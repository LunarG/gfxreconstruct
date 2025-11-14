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
3. [Client setup](#client-setup)
   1. [VSCode](#vscode)
   2. [CLI](#cli)

## Problem

Ordinary Android apps can be debugged easily through Android Studio. However, the GFXR capture layer is
a shared object file that is loaded by the, typically non-debug, application. This document illustrates a 
method by which the `lldb-server` binary included with the Android SDK can be used for debugging
a .so built in debug mode with any Android app.

## lldb-server setup

The first step is to locate and copy the lldb-server binary to a location on the Android device,
making sure to give it execute permissions as well.
```
adb root
adb push $(find $ANDROID_NDK_HOME -path "*/aarch64/lldb-server") /data/local/tmp
adb shell chmod +x /data/local/tmp/lldb-server
```

Then, run the following command to start the server listening on port 9999
```
adb shell /data/local/tmp/lldb-server platform --server --listen localhost:9999
```

lldb-server is now ready to accept connections from a client debugger.

## Client setup

On the client side, we need to launch `lldb` with options to do the following:
  1. Disable breaking on signals we don't care about (e.g. SIGSEGV)
  2. Load the capture layer's debug symbols
  3. Attach to the remote debugger on the phone

We document two methods for attaching a client debugger to lldb-server: VScode, and CLI

### VScode
To setup VScode to be the client debugger, you need to set up your
`launch.json` to be like the following:
```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Android",
            "type": "lldb",
            "request": "attach",
            "pid": "${input:android_pid}",
            "initCommands": [
                "platform select remote-android",
                "platform connect connect://<your-device-id here>:9999",
                "process handle -p true -s false -n false SIGSEGV",
                "process handle -p true -s false -n false SIGBUS",
                "process handle -p true -s false -n false SIGPWR",
                "process handle -p true -s false -n false SIGXCPU",
                "settings append target.exec-search-paths ${workspaceFolder}/android/layer/build/intermediates/cxx/Debug/<some numbers such as '3m4on72q'>/obj/<target device architecture e.g. arm64-v8a>/"
            ]
        }
    ],
    "inputs": [
        {
            "id": "android_pid",
            "type": "command",
            "command": "shellCommand.execute",
            "args": {
                "command": "adb shell pidof <apk name e.g. com.example.VkCube>"
            }
        }
    ]
}
```
When you go to Start Debugging, the `adb shell pidof` command will run, and present you with an
option whose content is the PID of the target process. Selecting this will begin the process of
automatically attaching to the remote debugger.

You can obtain your device's id with the `adb devices` command:
```
> adb devices
List of devices attached
44021FDJH00229  device
```

### CLI








## Wait for debugger

Yeah
