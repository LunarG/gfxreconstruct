<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->
<p align="left"><img src="https://vulkan.lunarg.com/img/NewLunarGLogoBlack.png" alt="LunarG" width=263 height=113 /></p>

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2024 LunarG, Inc.

# Meta Quest Walkthrough

## EXPERIMENTAL FEATURE!!!

Be aware the OpenXR support within GFXReconstruct is an experimental
feature, with restricted functionality and testing. See List of Known
Limitations below.

## Index

1. [Purpose](#purpose)
2. [Building IGL with the Capture Layer](#building-igl-with-the-capture-layer)
3. [Capturing the IGL Content](#capturing-the-igl-content)
4. [Replaying the IGL Content](#replaying-the-igl-content)
5. [Capturing the Replay Content](#capturing-the-replay-content)

## Purpose
This document shows several examples of how to use the GFXReconstruct
tools. These examples will help work through issues you may discover
while attempting to perform the same process on your own application.

**NOTE:** 
Many of these examples are given based on using a Windows system
as the build and/or host since the Meta Quest Developer Hub tools work
on Windows and not Linux.

## Building IGL with the Capture Layer
Let's look at adding the GFXReconstruct layer as a requirement of the
[Meta IGL](https://github.com/facebook/igl) project. These steps assume
that you have installed all the appropriate dependencies necessary to
build that project. Please refer to that repository to ensure these
dependencies have been met before continuing.

### 1. Pull down the GFXReconstruct source

If you haven't already, pull down the GFXReconstruct source from GitHub
so that it also updates any necessary submodules as part of the clone
operation:

```bash
git clone --recurse-submodules https://github.com/LunarG/gfxreconstruct.git
```

The full location of the `gfxreconstruct` folder generated from this
step is to be used in all cases below for `{gfxreconstruct_root}`.

### 2. Pull down the source for IGL

```bash
git clone --recurse-submodules https://github.com/facebook/igl.git
cd igl
```

Alternatively, if this is not the first time the tree is cloned,
simply enter the folder containing the source and update to the latest,
but also make sure that the submodules are re-initialized and updated
(because additional submodules may have been added).

```bash
cd igl
git pull
git submodule init
git submodule update --recursive
```

### 3. Edit the Gradle files to Find the GFXreconstruct Capture Layer

#### build.gradle

Edit the 'build\\android\\app-openxr-vulkan\\build.gradle' file to add
the capture layer as a dependency:

```text
@@ -82,4 +82,8 @@ android {
     buildFeatures {
         viewBinding true
     }
+
+    dependencies {
+        implementation project(':VkLayer_gfxreconstruct')
+    }
 }
```

#### settings.gradle

Edit the 'build\\android\\settings.gradle' file to include the project
location:

```text
@@ -23,3 +23,5 @@ rootProject.name = "IGL"
 include ':app'
 include ':app-openxr-vulkan'
 include ':app-openxr-gles'
+include ':VkLayer_gfxreconstruct'
+project(':VkLayer_gfxreconstruct').projectDir = file('{gfxreconstruct_root}\\android\\layer')
```

**NOTE**: Replace {gfxreconstruct_root} with the full path location of
the source you cloned from the GFXReconstruct repo in Step 1.


#### Add more permissions to AndroidManifest

Edit the file 

`shell/openxr/mobile/java/com/facebook/igl/shell/openxr/vulkan/AndroidManifest.xml`

to include `MANAGE_EXTERNAL_STORAGE` permission required by Android
10 and later:

```text
@@ -12,6 +12,7 @@

   <uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
   <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
+  <uses-permission android:name="android.permission.MANAGE_EXTERNAL_STORAGE"/>
   <uses-permission android:name="android.permission.INTERNET" />
   <uses-permission android:name="com.oculus.permission.HAND_TRACKING" />
```


#### Update the OpenXR-SDK Usage in IGL to the latest

Edit the `third-party/bootstrap-deps.json` file to use a new OpenXR-SDK
commit.

Update to at least sha1 of `be392bf6949adeeabad5082aa79d12aacbda781f`.


### 4. Build IGL using Android Studio

 1. Select "app-openxr-vulkan" target
 2. Click on the hamburger menu (top left), select the `Build` menu and then `Rebuild` under that


## Capturing the IGL Content

The example that follows uses the Meta IGL OpenXr Vulkan Sample built
above and assumes that you built the debug version.  The benefit of
building the application in this way is that it will automatically
incorporate the GFXReconstruct capture layer into the .APK file for the
built application.

**NOTE:** This assumes you have installed the Quest Development Hub with
its version of the Android tools (such as ADB)

### 1. Run Logcat

```bash
adb logcat -s IGL vulkan VulkanLoader VulkanLoaderAndroid OpenXR OpenXR-Loader gfxrecon
```

### 2. Enable GFXReconstruct

Using the ADB installed from the Meta Quest Developer Hub ("C:\Program
Files\Meta Quest Developer Hub\resources\bin\adb.exe" on some systems),
enable the GFXReconstruct layer only for the application using the
global settings:

```bash

adb shell "settings put global enable_gpu_debug_layers 1"
adb shell "settings put global gpu_debug_app com.facebook.igl.shell.openxr.vulkan"
adb shell "settings put global gpu_debug_layers 'VK_LAYER_LUNARG_gfxreconstruct'"
```

**NOTE:** You can also just log into `adb shell` and execute the commands
as they appear in the quotes if that is easier for you.

### 3. Set the Capture Options

Now, set the command to capture frames 1-500 so we can see what's
happening and write the file to the `/sdcard/Download` folder:

```bash
adb shell "setprop debug.gfxrecon.capture_file  '/sdcard/Download/openxr_capture.gfxr'"
adb shell "setprop debug.gfxrecon.capture_frames '1-500'"
```

#### Disable Timestamp on capture file

By default, in order to avoid conflicting capture file names, GFXR will
add a timestamp onto the end of the capture file, such as:

```bash
/sdcard/Download/openxr_capture_frames_1_through_500_20240812T132918.gfxr
```

If you find GFXR adding the timestamp on the end of the capture file to
be problematic, you can disable that with the following:

```bash
adb shell "setprop debug.gfxrecon.capture_file_timestamp 0"
```

#### Disable Re-Entrant Cases

By default, GFXReconstruct attempts to filter out what we call
"re-entrant" calls, it may still happen. A "re-entrant" call is when the
application calls the OpenXR runtime, which then creates some graphics API
commands (for example Vulkan commands) to perform some additional work
like composition. If the application is also capturing Vulkan commands
with GFXReconstruct these commands would show up, but shouldn't because
they are not part of what is intended to be recorded. To avoid this, we
disable recording any calls while an OpenXR command is in the process of
being recorded and executed. However, some calls may continue to occur
outside of these OpenXR calls. In some cases, the OpenXR runtime may
have a separate thread waiting on VkFences that were triggered during
an OpenXR call. These additional fences would be completely unknown to
GFXR because they would have been created and used initially outside of
its view. Therefore, we need to disable recording any Vulkan commands
that have content we don't recognize.

This is done by setting the following option:

```bash
adb shell "setprop debug.gfxrecon.skip_threads_with_invalid_data  '1'"
```

#### Additional Options

More capture options can be found in the
[USAGE_android.md](./USAGE_android.md) under the [Capture
Options](./USAGE_android.md#capture-options) section.

### 4. Install and Run the Application

  1. Open Android Studio 
  2. Connect the headset to your development
    machine using a USB plug
    a. Make sure the headset is detected by Android Studio
  3. Select the headset in the target 
  4. Make sure "app-openxr-vulkan"
    is selected 
  5. Press the "Play" triangle to run
    a. You may have to first select to enable commands from the host
    system on the headset

This shows that you can run the application on the target.

### 5. Run the Application

Repeat the steps from section 2. above.

This time, however, you should see a generated capture file after
exiting the application in the `/sdcard/Download` folder called
`openxr_capture_frames_1_to_500.gfxr` since you have selected to save
only some of the frames.

### 6. Verify the capture file

Check that the above file exists:

```bash
adb shell ls /sdcard/Download/openxr_capture*.gfxr
```

### 7. Disable the capture layer

Disable the capture layer globally and also restore the Vulkan usage of
the HWUI:

```bash
adb shell "setprop debug.vulkan.layers ''"
adb shell "settings put global gpu_debug_app ''"
adb shell "settings put global gpu_debug_layers ''"
```

## Replaying the IGL Content


### 1. Install the replay application

Now, we need to install the Replay application that we built as part of
the GFXReconstruct source.  Install the replay APK from the root of the
built source tree by using the `gfxrecon.py` script:

```bash
python3 android/scripts/gfxrecon.py install-apk android/tools/quest_replay/build/outputs/apk/debug/quest_replay-debug.apk
```

### 2. Force External Storage Permissions

Even though the Quest Replay application is built enabling external
storage access permissions in its Android Manifest file, it doesn't appear
to always work. Because of this, just force on the permission right
before attempting to run and access the files in the `/sdcard/downlaod`
directory:

```bash
adb shell appops set --uid com.lunarg.gfxreconstruct.replay MANAGE_EXTERNAL_STORAGE allow
```

### 3. Run the replay

First, disable the GFXReconstruct capture layers for Vulkan:

```bash
adb shell "setprop debug.vulkan.layers ''"
adb shell "settings put global gpu_debug_app ''"
adb shell "settings put global gpu_debug_layers ''"
```

Run the replay using the `gfxrecon.py` script:

```bash
python3 android/scripts/gfxrecon.py replay sdcard/Download/openxr_capture_frames_1_through_500_20240812T132918.gfxr
```

Replacing "openxr_capture_frames_1_through_500_20240812T132918.gfxr" with
the name of the most recent capture file discovered when performing step
[6. Verify the capture file](#6-verify-the-capture-file) above.


## Capturing the Replay Content

To capture a replay requires some additional changes.

### 1. Build this project enabling capture of the Quest replay app

By default, the replay does not include the necessary OpenXR
capture layer manifest files.
Because of this, you need to pass in the `EnableOpenXRCaptureOfReplay`
Gradle propery during build to properly define all the dependencies
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
the debug layer in section
[3. Enable GFXReconstruct](#3-enable-gfxreconstruct)
in the Capturing IGL Content section above.

One change is to make sure that we:
* Capture the correct application (here it is the replay application)
* Adjust the capture file to use a different name than
the one being replayed (or you will overwrite what you're reading)

```bash
adb shell settings put global gpu_debug_app com.lunarg.gfxreconstruct.replay
adb shell "setprop debug.gfxrecon.capture_file  '/sdcard/Download/replay_capture.gfxr'"
```

### 2. Install the Quest replay application

(Follow instructions in section [1. Install the replay
application](#1-install-the-replay-application)) in the Replay section
above if you have not already done so.

As well as modifying the permissions as noted in section [2. Force
External Storage Permissions](#2-force-external-storage-permissions)
in the Replay section above.

### 3. Run Logcat

```bash
adb logcat -s IGL vulkan VulkanLoader VulkanLoaderAndroid OpenXR OpenXR-Loader gfxrecon
```

### 4. Upload the Replay Capture

If the replay capture file is not already on the device, you will need
to push it up using:

```bash
adb push {capture_file_name} /sdcard/Download
```

### 5. Run the quest_replay Application

Run the replay using the `gfxrecon.py` script:

```bash
python3 android/scripts/gfxrecon.py replay /sdcard/Download/{capture_file_name}
```
