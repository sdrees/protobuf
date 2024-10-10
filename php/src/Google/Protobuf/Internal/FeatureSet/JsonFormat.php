<?php
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# NO CHECKED-IN PROTOBUF GENCODE
# source: google/protobuf/descriptor.proto

namespace Google\Protobuf\Internal\FeatureSet;

use UnexpectedValueException;

/**
 * Protobuf type <code>google.protobuf.FeatureSet.JsonFormat</code>
 */
class JsonFormat
{
    /**
     * Generated from protobuf enum <code>JSON_FORMAT_UNKNOWN = 0;</code>
     */
    const JSON_FORMAT_UNKNOWN = 0;
    /**
     * Generated from protobuf enum <code>ALLOW = 1;</code>
     */
    const ALLOW = 1;
    /**
     * Generated from protobuf enum <code>LEGACY_BEST_EFFORT = 2;</code>
     */
    const LEGACY_BEST_EFFORT = 2;

    private static $valueToName = [
        self::JSON_FORMAT_UNKNOWN => 'JSON_FORMAT_UNKNOWN',
        self::ALLOW => 'ALLOW',
        self::LEGACY_BEST_EFFORT => 'LEGACY_BEST_EFFORT',
    ];

    public static function name($value)
    {
        if (!isset(self::$valueToName[$value])) {
            throw new UnexpectedValueException(sprintf(
                    'Enum %s has no name defined for value %s', __CLASS__, $value));
        }
        return self::$valueToName[$value];
    }


    public static function value($name)
    {
        $const = __CLASS__ . '::' . strtoupper($name);
        if (!defined($const)) {
            throw new UnexpectedValueException(sprintf(
                    'Enum %s has no value defined for name %s', __CLASS__, $name));
        }
        return constant($const);
    }
}

