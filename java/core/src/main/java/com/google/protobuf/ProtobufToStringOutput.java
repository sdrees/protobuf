package com.google.protobuf;

import java.util.Optional;

/**
 * ProtobufToStringOutput controls the output format of {@link Message#toString()}. Specifically,
 * for the Runnable object passed to `callWithDebugFormat` and `callWithTextFormat`,
 * Message.toString() will always output the specified format unless ProtobufToStringOutput is used
 * again to change the output format.
 */
public final class ProtobufToStringOutput {
  private enum OutputMode {
    DEBUG_FORMAT,
    TEXT_FORMAT
  }

  private static final ThreadLocal<OutputMode> outputMode =
      ThreadLocal.withInitial(() -> OutputMode.TEXT_FORMAT);

  // Many tests are bound to the traditional Message.toString() output format (the text format). To
  // accelerate the debug format adoption while avoiding breaking such tests, we introduce this
  // test-only flag to disable the debug format in tests for certain libraries in which the output
  // of Message.toString() is unlikely to be deserialized.
  private static final ThreadLocal<Boolean> disableDebugFormatForTests =
      ThreadLocal.withInitial(() -> false);

  private ProtobufToStringOutput() {}

  @CanIgnoreReturnValue
  private static OutputMode setOutputMode(OutputMode newMode) {
    OutputMode oldMode = outputMode.get();
    outputMode.set(newMode);
    return oldMode;
  }

  private static void callWithSpecificFormat(Runnable impl, OutputMode mode) {
    OutputMode oldMode = setOutputMode(mode);
    try {
      impl.run();
    } finally {
      OutputMode unused = setOutputMode(oldMode);
    }
  }

  public static void callWithDebugFormat(Runnable impl) {
    callWithSpecificFormat(impl, OutputMode.DEBUG_FORMAT);
  }

  public static void callWithTextFormat(Runnable impl) {
    callWithSpecificFormat(impl, OutputMode.TEXT_FORMAT);
  }

  public static boolean shouldOutputDebugFormat() {
    return outputMode.get() == OutputMode.DEBUG_FORMAT;
  }

  static void setDisableDebugFormatForTests(boolean disable) {
    disableDebugFormatForTests.set(disable);
  }
}
