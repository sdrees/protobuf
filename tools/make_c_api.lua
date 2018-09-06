--[[

  Code to generate a C API in:
    foo.proto -> foo.upb.h
                 foo.upb.c

  This code is evolving very quickly and so there are lots of little things
  that aren't perfect right now.  As it settles a little more, the code
  quality should improve.

--]]

local upb = require "upb"
local dump_cinit = require "dump_cinit"
local export = {}

local typemap = {
  [upb.TYPE_BOOL]     = "bool",
  [upb.TYPE_FLOAT]    = "float",
  [upb.TYPE_INT32]    = "int32_t",
  [upb.TYPE_UINT32]   = "uint32_t",
  [upb.TYPE_DOUBLE]   = "double",
  [upb.TYPE_INT64]    = "int64_t",
  [upb.TYPE_UINT64]   = "uint64_t",
  [upb.TYPE_STRING]   = "upb_stringview",
  [upb.TYPE_BYTES]    = "upb_stringview",
}

function strip_proto(filename)
  return string.gsub(filename, '%.proto$','')
end

local function join(...)
  return table.concat({...}, ".")
end

local function to_cident(...)
  return string.gsub(join(...), "[%./]", "_")
end

local function to_preproc(...)
  return string.upper(to_cident(...))
end

-- Strips away last path element, ie:
--   foo.Bar.Baz -> foo.Bar
local function remove_name(name)
  local package_end = 0
  for i=1,string.len(name) do
    if string.byte(name, i) == string.byte(".", 1) then
      package_end = i - 1
    end
  end
  return string.sub(name, 1, package_end)
end

local function enum_value_symbol(enumdef, name)
  return to_cident(remove_name(enumdef:full_name())) .. "_" .. name
end

local function dump_enum_vals(enumdef, append)
  local enum_vals = {}

  for k, v in enumdef:values() do
    enum_vals[#enum_vals + 1] = {k, v}
  end

  table.sort(enum_vals, function(a, b) return a[2] < b[2] end)

  -- protobuf convention is that enum values are scoped at the level of the
  -- enum itself, to follow C++.  Ie, if you have the enum:
  -- message Foo {
  --   enum E {
  --     VAL1 = 1;
  --     VAL2 = 2;
  --   }
  -- }
  --
  -- The name of VAL1 is Foo.VAL1, not Foo.E.VAL1.
  --
  -- This seems a bit sketchy, but people often name their enum values
  -- accordingly, ie:
  --
  -- enum Foo {
  --   FOO_VAL1 = 1;
  --   FOO_VAL2 = 2;
  -- }
  --
  -- So if we don't respect this also, we end up with constants that look like:
  --
  --   GOOGLE_PROTOBUF_FIELDDESCRIPTORPROTO_TYPE_TYPE_DOUBLE = 1
  --
  -- (notice the duplicated "TYPE").
  local cident = to_cident(remove_name(enumdef:full_name()))
  for i, pair in ipairs(enum_vals) do
    k, v = pair[1], pair[2]
    append('  %s = %d', enum_value_symbol(enumdef, k), v)
    if i == #enum_vals then
      append('\n')
    else
      append(',\n')
    end
  end
end

local function field_default(field)
  if field:type() == upb.TYPE_MESSAGE then
    return "NULL"
  elseif field:type() == upb.TYPE_STRING or
         field:type() == upb.TYPE_BYTES then
    local default = field:default() or ""
    return string.format('upb_stringview_make("%s", strlen("%s"))', field:default(), field:default())
  elseif field:type() == upb.TYPE_ENUM then
    return enum_value_symbol(field:subdef(), field:default())
  else
    return field:default();
  end
end

local function ctype(field, const)
  if const then
    const = "const "
  else
    const = ""
  end

  if field:label() == upb.LABEL_REPEATED then
    return const .. "upb_array*"
  elseif field:type() == upb.TYPE_MESSAGE then
    if field:containing_type():file() == field:subdef():file() then
      return const .. to_cident(field:subdef():full_name()) .. "*"
    else
      return const .. "struct " .. to_cident(field:subdef():full_name()) .. "*"
    end
  elseif field:type() == upb.TYPE_ENUM then
    return to_cident(field:subdef():full_name())
  else
    return typemap[field:type()] or "void*"
  end
end

local function emit_file_warning(filedef, append)
  append('/* This file was generated by upbc (the upb compiler) from the input\n')
  append(' * file:\n')
  append(' *\n')
  append(' *     %s\n', filedef:name())
  append(' *\n')
  append(' * Do not edit -- your changes will be discarded when the file is\n')
  append(' * regenerated. */\n\n')
end

local function field_layout_rank(field)
  -- Order:
  --   1, 2, 3. primitive fields (8, 4, 1 byte)
  --   4. string fields
  --   5. submessage fields
  --   6. repeated fields
  --
  -- This has the following nice properties:
  --
  --  1. padding alignment is (nearly) minimized.
  --  2. fields that might have defaults (1-4) are segregated
  --     from fields that are always zero-initialized (5-7).
  --
  -- We skip oneof fields, because they are emitted in a separate pass.
  local rank
  if field:containing_oneof() then
    rank = 100  -- These go last (actually we skip them).
  elseif field:label() == upb.LABEL_REPEATED then
    rank = 6
  elseif field:type() == upb.TYPE_MESSAGE then
    rank = 5
  elseif field:type() == upb.TYPE_STRING or field:type() == upb.TYPE_BYTES then
    rank = 4
  elseif field:type() == upb.TYPE_BOOL then
    rank = 3
  elseif field:type() == upb.TYPE_FLOAT or
         field:type() == upb.TYPE_INT32 or
         field:type() == upb.TYPE_UINT32 then
    rank = 2
  else
    rank = 1
  end

  -- Break ties with field number.
  return (rank * 2^29) + field:number()
end

local function sizeof(field)
  if field:label() == upb.LABEL_REPEATED or
     field:type() == upb.TYPE_MESSAGE then
    return {4, 8}
  elseif field:type() == upb.TYPE_STRING or field:type() == upb.TYPE_BYTES then
    -- upb_stringview
    return {8, 16}
  elseif field:type() == upb.TYPE_BOOL then
    return {1, 1}
  elseif field:type() == upb.TYPE_FLOAT or
         field:type() == upb.TYPE_INT32 or
         field:type() == upb.TYPE_UINT32 then
    return {4, 4}
  else
    return {8, 8}
  end
end

local function sizemax(size, max)
  max[1] = math.max(max[1], size[1])
  max[2] = math.max(max[2], size[2])
end

local function alignup(val, align)
  val[1] = math.ceil(val[1] / align[1]) * align[1]
  val[2] = math.ceil(val[2] / align[2]) * align[2]
end

local function copysize(size)
  return {size[1], size[2]}
end

local function place(offset, size, max)
  alignup(offset, size)
  local ret = copysize(offset)

  -- add size
  offset[1] = offset[1] + size[1]
  offset[2] = offset[2] + size[2]

  -- track max size
  sizemax(size, max)

  return ret
end

local function get_field_layout_order(msg)
  local field_order = {}

  -- Sort fields by rank.
  for field in msg:fields() do
    table.insert(field_order, field)
  end
  table.sort(field_order, function(a, b)
    return field_layout_rank(a) < field_layout_rank(b)
  end)

  return field_order
end

local function get_oneof_layout_order(msg)
  local oneof_order = {}

  -- Sort oneofs by name.
  for oneof in msg:oneofs() do
    table.insert(oneof_order, oneof)
  end
  table.sort(oneof_order, function(a, b)
    return a:name() < b:name()
  end)

  return oneof_order
end

local function has_hasbit(field)
  if field:containing_type():file():syntax() == upb.SYNTAX_PROTO2 then
    return field:label() ~= upb.LABEL_REPEATED and not field:containing_oneof()
  else
    return false
  end
end

local function get_message_layout(msg)
  local hasbit_count = 0
  local hasbit_indexes = {}
  local field_order = get_field_layout_order(msg)
  local maxsize = {0, 0}

  -- Count hasbits.
  for _, field in ipairs(field_order) do
    if has_hasbit(field) then
      hasbit_indexes[field] = hasbit_count
      hasbit_count = hasbit_count + 1
    end
  end

  -- Place hasbits at the beginning.
  local offset = math.ceil(hasbit_count / 8)
  offset = {offset, offset}  -- 32, 64 bit
  local offsets = {}

  -- Place non-oneof fields.
  for _, field in ipairs(field_order) do
    if not field:containing_oneof() then
      offsets[field] = place(offset, sizeof(field), maxsize)
    end
  end

  -- Place oneof fields.
  for oneof in msg:oneofs() do
    local oneof_maxsize = {0, 0}
    -- Calculate max size.
    for field in oneof:fields() do
      local size = sizeof(field)
      sizemax(size, oneof_maxsize)
    end

    -- Place discriminator enum and data.
    local data = place(offset, oneof_maxsize, maxsize)
    local case = place(offset, {4, 4}, maxsize)
    offsets[oneof] = {data, case}
  end

  -- Align overall size up to max size.
  alignup(offset, maxsize)
  local size = copysize(offset)

  -- Place oneof defaults.
  for oneof in msg:oneofs() do
    for field in oneof:fields() do
      offsets[field] = place(offset, sizeof(field), maxsize)
    end
  end

  return hasbit_indexes, offsets, size
end

function get_sizeinit(size)
  return string.format("UPB_SIZE(%s, %s)", size[1], size[2])
end

local function write_h_file(filedef, append)
  emit_file_warning(filedef, append)
  local basename_preproc = to_preproc(filedef:name())
  append('#ifndef %s_UPB_H_\n', basename_preproc)
  append('#define %s_UPB_H_\n\n', basename_preproc)

  append('#include "upb/msg.h"\n\n')
  append('#include "upb/decode.h"\n')
  append('#include "upb/encode.h"\n')
  append('#include "upb/port_def.inc"\n')

  append('UPB_BEGIN_EXTERN_C\n\n')

  -- Forward-declare types defined in this file.
  for msg in filedef:defs(upb.DEF_MSG) do
    local msgname = to_cident(msg:full_name())
    append('typedef struct %s { int a; } %s;\n', msgname, msgname)
  end

  -- Forward-declare types not in this file, but used as submessages.
  for msg in filedef:defs(upb.DEF_MSG) do
    for field in msg:fields() do
      if field:type() == upb.TYPE_MESSAGE and
          field:subdef():file() ~= filedef then
        -- Forward declaration for message type declared in another file.
        append('struct %s;\n', to_cident(field:subdef():full_name()))
      end
    end
  end

  append('\n')
  append("/* Enums */\n\n")

  for _, def in ipairs(sorted_defs(filedef:defs(upb.DEF_ENUM))) do
    local cident = to_cident(def:full_name())
    append('typedef enum {\n')
    dump_enum_vals(def, append)
    append('} %s;\n\n', cident)
  end

  for msg in filedef:defs(upb.DEF_MSG) do
    local hasbit_indexes, offsets, size = get_message_layout(msg)

    append("/* %s */\n\n", msg:full_name())

    local msgname = to_cident(msg:full_name())
    append('extern const upb_msglayout %s_msginit;\n', msgname)
    append('UPB_INLINE %s *%s_new(upb_arena *arena) {\n', msgname, msgname)
    append('  return upb_msg_new(&%s_msginit, arena);\n', msgname)
    append('}\n')
    append('UPB_INLINE %s *%s_parsenew(upb_stringview buf, upb_arena *arena) {\n',
           msgname, msgname)
    append('  %s *ret = %s_new(arena);\n', msgname, msgname)
    append('  return (ret && upb_decode(buf, ret, &%s_msginit)) ? ret : NULL;\n', msgname)
    append('}\n')
    append('UPB_INLINE char *%s_serialize(const %s *msg, upb_arena *arena, size_t *len) {\n',
           msgname, msgname)
    append('  return upb_encode(msg, &%s_msginit, arena, len);\n', msgname)
    append('}\n')
    append('\n')

    for oneof in msg:oneofs() do
      local fullname = to_cident(oneof:containing_type():full_name() .. "." .. oneof:name())
      local offset = offsets[oneof]
      append('typedef enum {\n')
      for field in oneof:fields() do
        append('  %s = %d,\n', fullname .. "_" .. field:name(), field:number())
      end
      append('  %s_NOT_SET = 0,\n', fullname)
      append('} %s_oneofcases;\n', fullname)
      append('UPB_INLINE %s_oneofcases %s_%s_case(const %s* msg) { ' ..
             'return UPB_FIELD_AT(msg, int, %s); }\n',
             fullname, msgname, oneof:name(), msgname, get_sizeinit(offset[2]))
      append('\n')
    end

    for field in msg:fields() do
      append('UPB_INLINE %s %s_%s(const %s *msg) {',
             ctype(field, true), msgname, field:name(), msgname)
      if field:containing_oneof() then
        local offset = offsets[field:containing_oneof()]
        append(' return UPB_READ_ONEOF(msg, %s, %s, %s, %s, %s); }\n',
               ctype(field, true), get_sizeinit(offset[1]),
               get_sizeinit(offset[2]), field:number(), field_default(field))
      else
        append(' return UPB_FIELD_AT(msg, %s, %s); }\n',
               ctype(field, true), get_sizeinit(offsets[field]))
      end
    end

    append('\n')

    for field in msg:fields() do
      append('UPB_INLINE void %s_set_%s(%s *msg, %s value) { ',
              msgname, field:name(), msgname, ctype(field))
      if field:containing_oneof() then
        local offset = offsets[field:containing_oneof()]
        append('UPB_WRITE_ONEOF(msg, %s, %s, value, %s, %s); }\n',
               ctype(field), get_sizeinit(offset[1]), get_sizeinit(offset[2]),
               field:number())
      else
        append('UPB_FIELD_AT(msg, %s, %s) = value; }\n',
               ctype(field), get_sizeinit(offsets[field]))
      end
    end

    append('\n\n')
  end

  append('UPB_END_EXTERN_C\n')

  append('\n')
  append('#include "upb/port_undef.inc"\n');
  append('\n')

  append('#endif  /* %s_UPB_H_ */\n', basename_preproc)
end

local function write_c_file(filedef, hfilename, append)
  emit_file_warning(filedef, append)

  append('#include <stddef.h>\n')
  append('#include "upb/msg.h"\n')
  append('#include "%s"\n', hfilename)

  for dep in filedef:dependencies() do
    local outbase = strip_proto(dep:name())
    append('#include "%s.upb.h"\n', outbase)
  end

  append('\n')
  append('#include "upb/port_def.inc"\n')
  append('\n')

  for msg in filedef:defs(upb.DEF_MSG) do
    local msgname = to_cident(msg:full_name())

    local fields_array_ref = "NULL"
    local submsgs_array_ref = "NULL"
    local oneofs_array_ref = "NULL"
    local field_count = 0
    local submsg_count = 0
    local submsg_set = {}
    local submsg_indexes = {}
    local hasbit_indexes, offsets, size = get_message_layout(msg)
    local oneofs_layout_order = get_oneof_layout_order(msg)
    local oneof_count = 0
    local oneof_indexes = {}

    -- Another sorted array in field number order.
    local fields_number_order = {}

    for field in msg:fields() do
      field_count = field_count + 1
      table.insert(fields_number_order, field)
      if field:type() == upb.TYPE_MESSAGE then
        submsg_count = submsg_count + 1
        submsg_set[field:subdef()] = true
      end
    end

    table.sort(fields_number_order, function(a, b)
      return a:number() < b:number()
    end)

    for _, oneof in ipairs(oneofs_layout_order) do
      oneof_indexes[oneof] = oneof_count
      oneof_count = oneof_count + 1
    end

    if oneof_count > 0 then
      local oneofs_array_name = msgname .. "_oneofs"
      oneofs_array_ref = "&" .. oneofs_array_name .. "[0]"
      append('static const upb_msglayout_oneof %s[%s] = {\n',
             oneofs_array_name, oneof_count)
      for _, oneof in ipairs(oneofs_layout_order) do
        local offset = offsets[oneof]
        append('  {%s, %s},\n', get_sizeinit(offset[1]), get_sizeinit(offset[2]))
      end
      append('};\n\n')
    end

    if submsg_count > 0 then
      -- TODO(haberman): could save a little bit of space by only generating a
      -- "submsgs" array for every strongly-connected component.
      local submsgs_array_name = msgname .. "_submsgs"
      submsgs_array_ref = "&" .. submsgs_array_name .. "[0]"
      append('static const upb_msglayout *const %s[%s] = {\n',
             submsgs_array_name, submsg_count)

      -- Create a deterministically-sorted array of submessage entries.
      local submsg_array = {}
      for k, v in pairs(submsg_set) do
        table.insert(submsg_array, k)
      end
      table.sort(submsg_array, function(a, b)
        return a:full_name() < b:full_name()
      end)

      for i, submsg in ipairs(submsg_array) do
        append('  &%s_msginit,\n', to_cident(submsg:full_name()))
        submsg_indexes[submsg] = i - 1
      end

      append('};\n\n')
    end

    if field_count > 0 then
      local fields_array_name = msgname .. "__fields"
      fields_array_ref = "&" .. fields_array_name .. "[0]"
      append('static const upb_msglayout_field %s[%s] = {\n',
             fields_array_name, field_count)
      for _, field in ipairs(fields_number_order) do
        local submsg_index = "UPB_NO_SUBMSG"
        local oneof_index = "UPB_NOT_IN_ONEOF"
        if field:type() == upb.TYPE_MESSAGE then
          submsg_index = submsg_indexes[field:subdef()]
        end
        if field:containing_oneof() then
          oneof_index = oneof_indexes[field:containing_oneof()]
        end
        append('  {%s, %s, %s, %s, %s, %s, %s},\n',
               field:number(),
               get_sizeinit(offsets[field]),
               hasbit_indexes[field] or "UPB_NO_HASBIT",
               oneof_index,
               submsg_index,
               field:descriptor_type(),
               field:label())
      end
      append('};\n\n')
    end

    append('const upb_msglayout %s_msginit = {\n', msgname)
    append('  %s,\n', submsgs_array_ref)
    append('  %s,\n', fields_array_ref)
    append('  %s,\n', oneofs_array_ref)
    append('  NULL, /* TODO. default_msg */\n')
    append('  %s, %s, %s, %s, %s\n',
           get_sizeinit(size), field_count,
           oneof_count,
           'false', -- TODO: extendable
          msg:file():syntax() == upb.SYNTAX_PROTO2
          )

    append('};\n\n')
  end

  append('#include "upb/port_undef.inc"\n')
  append('\n')
end

function export.write_gencode(filedef, hfilename, append_h, append_c)
  write_h_file(filedef, append_h)
  write_c_file(filedef, hfilename, append_c)
end

return export
