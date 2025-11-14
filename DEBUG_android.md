<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->
<p align="left"><img src="https://vulkan.lunarg.com/img/NewLunarGLogoBlack.png" alt="LunarG" width=263 height=113 /></p>

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2018-2025 LunarG, Inc.

# GFXReconstruct Capture layer debugging - Android

***This document describes how to debug the GFXReconstruct capture layer
on Android using lldbserver.***

## Index

1. [Problem](#problem)
2. [Setting up lldb-server](#lldb-server-setup)

## Problem

Ordinary Android apps can be debugged easily through Android Studio. However, the GFXR capture layer is
a shared object file that is loaded by the, often non-debug, application. This document illustrates a 
method by which the `lldb-server` binary included with the Android SDK can be used for debugging
a .so built in debug mode with any Android app.

## lldb-server setup

The first step is to locate and copy the lldb-server binary to a location on the Android device.
```
adb root
adb push $(find $ANDROID_NDK_HOME -path "*/aarch64/lldb-server") /data/local/tmp
adb shell chmod +x /data/local/tmp/lldb-server
adb shell /data/local/tmp/lldb-server platform --server --listen localhost:9999
```









## Wait for debugger

Yeah
