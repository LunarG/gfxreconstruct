<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->
<p align="left"><img src="https://vulkan.lunarg.com/img/NewLunarGLogoBlack.png" alt="LunarG" width=263 height=113 /></p>

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2024-2025 LunarG, Inc.

# Meta Quest Walkthrough

## EXPERIMENTAL FEATURE!!!

Be aware the OpenXR support within GFXReconstruct is an experimental
feature, with restricted functionality and testing. See List of Known
Limitations below.

## Index

1. [Purpose](#purpose)
2. [Building GFXReconstruct](#building-gfxreconstruct)
3. [Attaching GFXReconstruct to an Existing Application](#attaching-gfxreconstruct-to-an-existing-application)
4. [Replaying a Capture File](#replaying-a-capture-file)
6. [Capturing the Replay Content](#capturing-the-replay-content)
7. [OpenXR Capture Known Limitations](#openxr-capture-known-limitations)

## Purpose

This document shows several examples of how to use the GFXReconstruct
tools for the Meta Quest headsets, in particular the Meta Quest
Pro and Quest 3 models.

These examples assume that the developer is using a Windows system
as the build and/or host since the Meta Quest Developer Hub tools work
on Windows and not Linux.

**NOTE:** This assumes the application meets the following requirements
 * Uses Gradle (preferably 8.0+)
 * Builds against Android 10+

## Building GFXReconstruct

First, download a version of GFXReconstruct that supports OpenXR
using the [GFXReconstruct GitHub repo](https://github.com/LunarG/gfxreconstruct).

```bash
git clone --recurse-submodules https://github.com/LunarG/gfxreconstruct.git
```

The full location of the `gfxreconstruct` folder generated from this
step is to be used in all cases below for `{gfxreconstruct_root}`.

Next, follow the instructions in the [BUILD.md doc](./BUILD.md)
found in the top-level of the GFXReconstruct repo for building
for an [Android target](./BUILD.md#building-for-android).


## Attaching GFXReconstruct to an Existing Application

To attach GFXReconstruct to an existing application
will require modifying the Gradle files so that the
application can find and build with the capture layer:


### 1. App settings.gradle Changes

Include GFXReconstruct's layer as a known project:

```bash
include ':VkLayer_gfxreconstruct'
project(':VkLayer_gfxreconstruct').projectDir = file('{gfxreconstruct_root}\\android\\layer')
```

Replace `{gfxreconstruct_root}` with the location of your
GFXReconstruct source pulled down from Github above in
the [Building GFXReconstruct](#building-gfxreconstruct)
section.

**NOTE:** Even though the layer is listed as
"Vk"Layer_gfxreconstruct (as in Vulkan),
it also contains information for the OpenXR
API Layer as well.


### 2. App build.gradle Changes

Add GFXReconstruct's layer as a dependency:

```bash
dependencies {
    implementation project(':VkLayer_gfxreconstruct')
}
```

### 3. Adjust App AndroidManifest

Edit the application file to add both the
`WRITE_EXTERNAL_STORAGE` and `MANAGE_EXTERNAL_STORAGE`
permissions so that GFXReconstruct can write the
capture file to your system.

For example:

```bash
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
  xmlns:tools="http://schemas.android.com/tools"
...
  <uses-permission android:name="org.khronos.openxr.permission.OPENXR" />
  <uses-permission android:name="org.khronos.openxr.permission.OPENXR_SYSTEM" />
...
+  <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
+  <uses-permission android:name="android.permission.MANAGE_EXTERNAL_STORAGE"/>
...
```


### 4. Building Your App

Build it as normal, it should automatically include
the necessary library files and OpenXR Implicit
API Layer.

#### Note About Release Build of App

This step is not necessary for Debug builds of an
application.
However, for Release builds, there is some additional
settings required.
This is because on Android/Meta OS the Vulkan layer
is attached at run-time using Android/Meta OS system
settings.
If the application does not have the `debuggable`
flag set to `true` in the build.gradle file, the layer
will not correctly attach at run-time.

For example:

```bash
 release {
     signingConfig signingConfigs.release
-    debuggable false
+    debuggable true
...
     ndk {
-        debuggable  false
+        debuggable  true
...
     }
 }
```

### 5. Enable GFXReconstruct Vulkan Capture

Using the ADB installed from the Meta Quest Developer Hub ("C:\Program
Files\Meta Quest Developer Hub\resources\bin\adb.exe" on some systems),
enable the GFXReconstruct layer only for the application using the
global settings:

```bash
adb shell "settings put global enable_gpu_debug_layers 1"
adb shell "settings put global gpu_debug_app {Android applicationId}"
adb shell "settings put global gpu_debug_layers 'VK_LAYER_LUNARG_gfxreconstruct'"
```

Replace `{Android applicationId}` with the application's Id.
This Id typically can be found in the `build.gradle` file and
should look something similar to the following:

* com.facebook.igl.shell.openxr.vulkan
* net.beyondreality.openxr_provider.finger_painting3.openxr

**NOTE:** If you apply an `applicationIdSuffix`, you should append it to
the applicationId to get the full Identifier.

#### What do These Commands Do?

The first command setting `enable_gpu_debug_layers` to 1 tells
the OS that you will be using Debug Vulkan Layers that will be
attached to the application at runtime.

The second command settings `gpu_debug_app` tells the OS
which application you want the layer applied to.

The third command setting `gpu_debug_layers` identifies which Debug
Vulkan layers you want enabled.
In this case, GFXReconstruct's Vulkan layer name
`VK_LAYER_LUNARG_gfxreconstruct`.


### 6. Set the Capture Options

Now, set the command indicating where to record the contents
of the capture, in this case to the `/sdcard/Download` folder:

```bash
adb shell "setprop debug.gfxrecon.capture_file  '/sdcard/Download/openxr_capture.gfxr'"
```

This commands will result in the capture file being written
to the `/sdcard/Download` folder on the device with the
prefix of `openxr_capture` and the suffix of `.gfxr`.

#### Filename With Timestamp

By default, the filename provided above is modified to include
a timestamp after the main filename.
For example, with the above information, the expanded
filename with timestamp may look something like
`openxr_capture_20240812T132918.gfxr`.
In general, adding a timestamp to the filename is useful
since it creates a unique file per run allowing users
to capture multiple times without fear of overriding
the previous capture.
However, if you are using it in a script and it may be useful
to force a consistent filename by disabling the use of
the timestamp.

To disable adding a timestamp to the filename when capturing,
set the following Android property:

```bash
adb shell "setprop debug.gfxrecon.capture_file_timestamp 0"
```

**NOTE:** The rest of this document assumes this option
is enabled simply so we can simplify the naming of the
capture filename.


#### Limit to a Certain Number of Frames

You can adjust how many frames are captured (instead of
all frames until the app is completed) by defining
the `debug.gfxrecon.capture_frames` property.

For example, if you want to only capture the first
500 frames, you do the following:

```bash
adb shell "setprop debug.gfxrecon.capture_frames '1-500'"
```

**NOTE:** This will change the name of the capture file generated.
For example, above we set the capture file to
`/sdcard/Download/openxr_capture.gfxr`, but with frame limitations
enabled, it will now be named
`/sdcard/Download/openxr_capture_frames_1_through_500.gfxr`.
If timestamps are not disabled, the filename will look even
more complex, like
`/sdcard/Download/openxr_capture_frames_1_through_500_20240812T132918.gfxr`.

#### Disable Re-Entrant Cases

By default, GFXReconstruct capturing of OpenXR and Vulkan
content simultaneously attempts to filter out what we call
"re-entrant" calls.
A "re-entrant" call is when the application calls the OpenXR
runtime, which then creates some graphics API commands
(for example Vulkan commands) to perform some additional work
like composition.
If the application is also performing Vulkan commands,
which GFXReconstruct is capturing, then GFXReconstruct could
run into the situation of capturing unnecessary Vulkan commands
which will be re-generated by the OpenXR at replay time.
To avoid this, we disable recording any calls while an OpenXR
command is in the process of being recorded and executed.

However, some calls may continue to occur outside of these
OpenXR calls.
In some cases, the OpenXR runtime may have a separate thread
waiting on `VkFences` that were triggered during an OpenXR call.
These additional fences would be completely unknown to
GFXReconstruct because they would have been created and used
initially outside of its view.
Therefore, we need to disable recording any Vulkan commands
that have content we don't recognize.

This is done by setting the following option:

```bash
adb shell "setprop debug.gfxrecon.skip_threads_with_invalid_data  '1'"
```

#### Additional Options

More capture options can be found in the
[USAGE_android.md](./USAGE_android.md) under the [Capture
Options](./USAGE_android.md#capture-options) section.

### 7. Install and Run the Application

Install the application as normal and run it.

**NOTE:** There are several situations in Android that may
prevent updating an application that has already been installed
on the system previously.
In those situations, it is better to make sure any previous
installed versions are stopped and uninstalled before
attempting to install the newer version of the application.

Then run the application as normal to capture
the content.

If the application fails to launch, review the
`adb logcat` information for any fatal or error messages.
Here is a useful filter for logcat messages.

```bash
adb logcat -s DEBUG vulkan VulkanLoader VulkanLoaderAndroid OpenXR OpenXR-Loader gfxrecon
```

Once complete, if everything executed correctly, the capture
file should be present in the `/sdcard/Download` folder.

Check that it exists:

```bash
adb shell ls /sdcard/Download/openxr_capture*.gfxr
```

## Replaying a Capture File


### 1. Install the Quest Replay Application

Install the GFXReconstruct Quest Replay application
that is built as part of the Android build of
GFXReconstruct using the `gfxrecon.py` script:

For example, if installing the Debug build of
the Quest replay app:

```bash
cd {gfxreconstruct_root}
python3 android/scripts/gfxrecon.py install-apk android/tools/quest_replay/build/outputs/apk/debug/quest_replay-debug.apk
```

Replace `{gfxreconstruct_root}` with the location of your
GFXReconstruct source pulled down from Github above in
the [Building GFXReconstruct](#building-gfxreconstruct)
section.

### 2. Force External Storage Permissions

Even though the Quest Replay application is built enabling external
storage access permissions in its Android Manifest file,
it doesn't always appear to stick.
Because of this, it is best to just force on the permission right
before attempting to run and access the files in the `/sdcard/Download`
directory:

```bash
adb shell appops set --uid com.lunarg.gfxreconstruct.replay MANAGE_EXTERNAL_STORAGE allow
```

### 3. Run the replay

Run the replay using the `gfxrecon.py` script:

```bash
python3 android/scripts/gfxrecon.py replay sdcard/Download/{capture_file_name}
```

Replace `{capture_file_name}` with the name of a
valid capture file that was created.
The replay should run, perform the appropriate rendering,
and then close on completion.


## Capturing the Replay Content

At times, capturing the Quest replay itself may be of use but
does require some additional changes.

### 1. Build the Replay Enabling Capture

By default, the Quest replay application does not include the
necessary OpenXR capture layer manifest files.
Because of this, you need to pass in the `EnableOpenXRCaptureOfReplay`
Gradle property during build to properly define all the dependencies
for the capture layer.

This can be done in the following way:

```bash
gradlew assembleDebug -PEnableOpenXRCaptureOfReplay=true
```

Once rebuilt, the capture should be ready from the OpenXR side, however,
you still will need to enable the Vulkan settings to completely and
properly capture the necessary content.

### 2. Change the Debug app to the GFXRecon Quest replay app

If you haven't already done so, first follow the instructions to enable
the debug layer in the
[Enable GFXReconstruct Vulkan Capture](#5-enable-gfxreconstruct-vulkan-capture)
section above.

One change is to make sure that:
* The correct application name is used (here it is the Quest replay
  application)
* Adjust the capture file to use a different name than
  the one being replayed (or it will overwrite what is being read)

```bash
adb shell settings put global gpu_debug_app com.lunarg.gfxreconstruct.replay
adb shell "setprop debug.gfxrecon.capture_file  '/sdcard/Download/replay_capture.gfxr'"
```

### 2. Install the Updated Replay Tool

(Follow instructions in the 
[1. Install the Quest Replay Application](#1-install-the-quest-replay-application))section above (especially if the Quest replay application was
previously installed without re-capture enabled).

Repeat the permissions modification as noted in the
[2. Force External Storage Permissions](#2-force-external-storage-permissions)
section above.

### 3. Run Logcat

```bash
adb logcat -s DEBUG vulkan VulkanLoader VulkanLoaderAndroid OpenXR OpenXR-Loader gfxrecon
```

### 4. Upload the Replay Capture

If the capture file that will be used to replay is not already on
the device, push it to the device using ADB:

```bash
adb push {capture_file_name} /sdcard/Download
```

### 5. Run the Quest Replay Application

Run the replay using the `gfxrecon.py` script:

```bash
python3 android/scripts/gfxrecon.py replay /sdcard/Download/{capture_file_name}
```

## OpenXR Capture Known Limitations

The current implementation has been written to cover the OpenXR API
entrypoints and usage based on a limited number of test applications (listed in issue below).
It is possible that meaningful omissions or errors in capture and/or
replay may exist outside the usage tested.
The current set of known limitations is maintained in
[GitHub/LunarG/gfxreconstruct issue 2145](https://github.com/LunarG/gfxreconstruct/issues/2145). 

