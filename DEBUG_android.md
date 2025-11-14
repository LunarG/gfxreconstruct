<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->
<p align="left"><img src="https://vulkan.lunarg.com/img/NewLunarGLogoBlack.png" alt="LunarG" width=263 height=113 /></p>

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2018-2025 LunarG, Inc.

# GFXReconstruct API Capture and Replay - Android

***This document describes how to debug the GFXReconstruct capture layer
on Android using lldbserver.***

## Index

1. [Concept](#concept)

1. [Capturing API Calls](#capturing-api-calls)
    1. [Before Use](#before-use)
    2. [Enabling the Capture Layer](#enabling-the-capture-layer)
    3. [Capture Options](#capture-options)
    4. [Capture Files](#capture-files)
    6. [Capture Limitations](#capture-limitations)
    7. [Troubleshooting Capturing of Applications](#troubleshooting-capturing-of-applications)
2. [Replaying API Calls](#replaying-api-calls)
    1. [Launch Script](#launch-script)
    2. [Install APK Command](#install-apk-command)
    3. [Replay Command](#replay-command)
    4. [Touch Controls](#touch-controls)
    5. [Key Controls](#key-controls)
    6. [Limitations of Replay On Android](#limitations-of-replay-on-android)
    7. [Troubleshooting Replay of Applications](#troubleshooting-replay-of-applications)
    8. [Dumping resources](#dumping-resources)
3. [Android Detailed Examples](#android-detailed-examples)


## Concept

Ordinary Android apps can be debugged easily through Android Studio. However, the GFXR capture layer is
a shared object file that is loaded by the, often non-debug, application. This document illustrates a 
method by which the `lldb-server` binary included with the Android SDK can be used for debugging
a .so built in debug mode with any Android app.

bash```
adb root
adb push $(find $ANDROID_NDK_HOME -path "*/aarch64/lldb-server") /data/local/tmp
adb shell /data/local/tmp/lldb-server platform --server --listen localhost:9999
```









## Wait for debugger

Yeah