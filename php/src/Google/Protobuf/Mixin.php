<?php
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# NO CHECKED-IN PROTOBUF GENCODE
# source: google/protobuf/api.proto

namespace Google\Protobuf;

use Google\Protobuf\Internal\GPBType;
use Google\Protobuf\Internal\GPBUtil;
use Google\Protobuf\RepeatedField;

/**
 * Declares an API Interface to be included in this interface. The including
 * interface must redeclare all the methods from the included interface, but
 * documentation and options are inherited as follows:
 * - If after comment and whitespace stripping, the documentation
 *   string of the redeclared method is empty, it will be inherited
 *   from the original method.
 * - Each annotation belonging to the service config (http,
 *   visibility) which is not set in the redeclared method will be
 *   inherited.
 * - If an http annotation is inherited, the path pattern will be
 *   modified as follows. Any version prefix will be replaced by the
 *   version of the including interface plus the [root][] path if
 *   specified.
 * Example of a simple mixin:
 *     package google.acl.v1;
 *     service AccessControl {
 *       // Get the underlying ACL object.
 *       rpc GetAcl(GetAclRequest) returns (Acl) {
 *         option (google.api.http).get = "/v1/{resource=**}:getAcl";
 *       }
 *     }
 *     package google.storage.v2;
 *     service Storage {
 *       rpc GetAcl(GetAclRequest) returns (Acl);
 *       // Get a data record.
 *       rpc GetData(GetDataRequest) returns (Data) {
 *         option (google.api.http).get = "/v2/{resource=**}";
 *       }
 *     }
 * Example of a mixin configuration:
 *     apis:
 *     - name: google.storage.v2.Storage
 *       mixins:
 *       - name: google.acl.v1.AccessControl
 * The mixin construct implies that all methods in `AccessControl` are
 * also declared with same name and request/response types in
 * `Storage`. A documentation generator or annotation processor will
 * see the effective `Storage.GetAcl` method after inheriting
 * documentation and annotations as follows:
 *     service Storage {
 *       // Get the underlying ACL object.
 *       rpc GetAcl(GetAclRequest) returns (Acl) {
 *         option (google.api.http).get = "/v2/{resource=**}:getAcl";
 *       }
 *       ...
 *     }
 * Note how the version in the path pattern changed from `v1` to `v2`.
 * If the `root` field in the mixin is specified, it should be a
 * relative path under which inherited HTTP paths are placed. Example:
 *     apis:
 *     - name: google.storage.v2.Storage
 *       mixins:
 *       - name: google.acl.v1.AccessControl
 *         root: acls
 * This implies the following inherited HTTP annotation:
 *     service Storage {
 *       // Get the underlying ACL object.
 *       rpc GetAcl(GetAclRequest) returns (Acl) {
 *         option (google.api.http).get = "/v2/acls/{resource=**}:getAcl";
 *       }
 *       ...
 *     }
 *
 * Generated from protobuf message <code>google.protobuf.Mixin</code>
 */
class Mixin extends \Google\Protobuf\Internal\Message
{
    /**
     * The fully qualified name of the interface which is included.
     *
     * Generated from protobuf field <code>string name = 1;</code>
     */
    protected $name = '';
    /**
     * If non-empty specifies a path under which inherited HTTP paths
     * are rooted.
     *
     * Generated from protobuf field <code>string root = 2;</code>
     */
    protected $root = '';

    /**
     * Constructor.
     *
     * @param array $data {
     *     Optional. Data for populating the Message object.
     *
     *     @type string $name
     *           The fully qualified name of the interface which is included.
     *     @type string $root
     *           If non-empty specifies a path under which inherited HTTP paths
     *           are rooted.
     * }
     */
    public function __construct($data = NULL) {
        \GPBMetadata\Google\Protobuf\Api::initOnce();
        parent::__construct($data);
    }

    /**
     * The fully qualified name of the interface which is included.
     *
     * Generated from protobuf field <code>string name = 1;</code>
     * @return string
     */
    public function getName()
    {
        return $this->name;
    }

    /**
     * The fully qualified name of the interface which is included.
     *
     * Generated from protobuf field <code>string name = 1;</code>
     * @param string $var
     * @return $this
     */
    public function setName($var)
    {
        GPBUtil::checkString($var, True);
        $this->name = $var;

        return $this;
    }

    /**
     * If non-empty specifies a path under which inherited HTTP paths
     * are rooted.
     *
     * Generated from protobuf field <code>string root = 2;</code>
     * @return string
     */
    public function getRoot()
    {
        return $this->root;
    }

    /**
     * If non-empty specifies a path under which inherited HTTP paths
     * are rooted.
     *
     * Generated from protobuf field <code>string root = 2;</code>
     * @param string $var
     * @return $this
     */
    public function setRoot($var)
    {
        GPBUtil::checkString($var, True);
        $this->root = $var;

        return $this;
    }

}

