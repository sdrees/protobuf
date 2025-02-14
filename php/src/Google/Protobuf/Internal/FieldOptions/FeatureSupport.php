<?php
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# NO CHECKED-IN PROTOBUF GENCODE
# source: google/protobuf/descriptor.proto

namespace Google\Protobuf\Internal\FieldOptions;

use Google\Protobuf\Internal\GPBType;
use Google\Protobuf\Internal\GPBWire;
use Google\Protobuf\Internal\InputStream;
use Google\Protobuf\Internal\GPBUtil;
use Google\Protobuf\RepeatedField;

/**
 * Information about the support window of a feature.
 *
 * Generated from protobuf message <code>google.protobuf.FieldOptions.FeatureSupport</code>
 */
class FeatureSupport extends \Google\Protobuf\Internal\Message
{
    /**
     * The edition that this feature was first available in.  In editions
     * earlier than this one, the default assigned to EDITION_LEGACY will be
     * used, and proto files will not be able to override it.
     *
     * Generated from protobuf field <code>optional .google.protobuf.Edition edition_introduced = 1;</code>
     */
    protected $edition_introduced = null;
    /**
     * The edition this feature becomes deprecated in.  Using this after this
     * edition may trigger warnings.
     *
     * Generated from protobuf field <code>optional .google.protobuf.Edition edition_deprecated = 2;</code>
     */
    protected $edition_deprecated = null;
    /**
     * The deprecation warning text if this feature is used after the edition it
     * was marked deprecated in.
     *
     * Generated from protobuf field <code>optional string deprecation_warning = 3;</code>
     */
    protected $deprecation_warning = null;
    /**
     * The edition this feature is no longer available in.  In editions after
     * this one, the last default assigned will be used, and proto files will
     * not be able to override it.
     *
     * Generated from protobuf field <code>optional .google.protobuf.Edition edition_removed = 4;</code>
     */
    protected $edition_removed = null;

    /**
     * Constructor.
     *
     * @param array $data {
     *     Optional. Data for populating the Message object.
     *
     *     @type int $edition_introduced
     *           The edition that this feature was first available in.  In editions
     *           earlier than this one, the default assigned to EDITION_LEGACY will be
     *           used, and proto files will not be able to override it.
     *     @type int $edition_deprecated
     *           The edition this feature becomes deprecated in.  Using this after this
     *           edition may trigger warnings.
     *     @type string $deprecation_warning
     *           The deprecation warning text if this feature is used after the edition it
     *           was marked deprecated in.
     *     @type int $edition_removed
     *           The edition this feature is no longer available in.  In editions after
     *           this one, the last default assigned will be used, and proto files will
     *           not be able to override it.
     * }
     */
    public function __construct($data = NULL) {
        \GPBMetadata\Google\Protobuf\Internal\Descriptor::initOnce();
        parent::__construct($data);
    }

    /**
     * The edition that this feature was first available in.  In editions
     * earlier than this one, the default assigned to EDITION_LEGACY will be
     * used, and proto files will not be able to override it.
     *
     * Generated from protobuf field <code>optional .google.protobuf.Edition edition_introduced = 1;</code>
     * @return int
     */
    public function getEditionIntroduced()
    {
        return isset($this->edition_introduced) ? $this->edition_introduced : 0;
    }

    public function hasEditionIntroduced()
    {
        return isset($this->edition_introduced);
    }

    public function clearEditionIntroduced()
    {
        unset($this->edition_introduced);
    }

    /**
     * The edition that this feature was first available in.  In editions
     * earlier than this one, the default assigned to EDITION_LEGACY will be
     * used, and proto files will not be able to override it.
     *
     * Generated from protobuf field <code>optional .google.protobuf.Edition edition_introduced = 1;</code>
     * @param int $var
     * @return $this
     */
    public function setEditionIntroduced($var)
    {
        GPBUtil::checkEnum($var, \Google\Protobuf\Internal\Edition::class);
        $this->edition_introduced = $var;

        return $this;
    }

    /**
     * The edition this feature becomes deprecated in.  Using this after this
     * edition may trigger warnings.
     *
     * Generated from protobuf field <code>optional .google.protobuf.Edition edition_deprecated = 2;</code>
     * @return int
     */
    public function getEditionDeprecated()
    {
        return isset($this->edition_deprecated) ? $this->edition_deprecated : 0;
    }

    public function hasEditionDeprecated()
    {
        return isset($this->edition_deprecated);
    }

    public function clearEditionDeprecated()
    {
        unset($this->edition_deprecated);
    }

    /**
     * The edition this feature becomes deprecated in.  Using this after this
     * edition may trigger warnings.
     *
     * Generated from protobuf field <code>optional .google.protobuf.Edition edition_deprecated = 2;</code>
     * @param int $var
     * @return $this
     */
    public function setEditionDeprecated($var)
    {
        GPBUtil::checkEnum($var, \Google\Protobuf\Internal\Edition::class);
        $this->edition_deprecated = $var;

        return $this;
    }

    /**
     * The deprecation warning text if this feature is used after the edition it
     * was marked deprecated in.
     *
     * Generated from protobuf field <code>optional string deprecation_warning = 3;</code>
     * @return string
     */
    public function getDeprecationWarning()
    {
        return isset($this->deprecation_warning) ? $this->deprecation_warning : '';
    }

    public function hasDeprecationWarning()
    {
        return isset($this->deprecation_warning);
    }

    public function clearDeprecationWarning()
    {
        unset($this->deprecation_warning);
    }

    /**
     * The deprecation warning text if this feature is used after the edition it
     * was marked deprecated in.
     *
     * Generated from protobuf field <code>optional string deprecation_warning = 3;</code>
     * @param string $var
     * @return $this
     */
    public function setDeprecationWarning($var)
    {
        GPBUtil::checkString($var, True);
        $this->deprecation_warning = $var;

        return $this;
    }

    /**
     * The edition this feature is no longer available in.  In editions after
     * this one, the last default assigned will be used, and proto files will
     * not be able to override it.
     *
     * Generated from protobuf field <code>optional .google.protobuf.Edition edition_removed = 4;</code>
     * @return int
     */
    public function getEditionRemoved()
    {
        return isset($this->edition_removed) ? $this->edition_removed : 0;
    }

    public function hasEditionRemoved()
    {
        return isset($this->edition_removed);
    }

    public function clearEditionRemoved()
    {
        unset($this->edition_removed);
    }

    /**
     * The edition this feature is no longer available in.  In editions after
     * this one, the last default assigned will be used, and proto files will
     * not be able to override it.
     *
     * Generated from protobuf field <code>optional .google.protobuf.Edition edition_removed = 4;</code>
     * @param int $var
     * @return $this
     */
    public function setEditionRemoved($var)
    {
        GPBUtil::checkEnum($var, \Google\Protobuf\Internal\Edition::class);
        $this->edition_removed = $var;

        return $this;
    }

}

