<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->
<p align="left"><img src="https://vulkan.lunarg.com/img/NewLunarGLogoBlack.png" alt="LunarG" width=263 height=113 /></p>

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2024 LunarG, Inc.

# Meta Quest Walkthrough

## Index

1. [Purpose](#purpose)
2. [Building IGL with the Capture Layer](#building-igl-with-the-capture-layer)
3. [Capturing Vulkan Samples](#capturing-vulkan-samples)

## Purpose

This document shows several examples of how to use the GFXReconstruct tools.
These examples will help work through issues you may discover while attempting
to perform the same process on your own application.

**NOTE:**
Many of these examples are given based on using a Windows system as the build
and/or host since the Meta Quest Developer Hub tools work on Windows and not
Linux.

## Building IGL with the Vulkan Capture Layer

Let's look at adding the GFXReconstruct layer as a requirement of the
[Meta IGL](https://github.com/facebook/igl) project.
These steps assume that you have installed all the appropriate dependencies
necessary to build that project.
Please refer to that repository to ensure these dependencies have been
met before continuing.

### 1. Pull down the GFXReconstruct source

If you haven't already, pull down the GFXReconstruct source from GitHub so that
it also updates any necessary submodules as part of the clone operation:

```bash
git clone --recurse-submodules https://github.com/LunarG/gfxreconstruct.git
```

The full location of the `gfxreconstruct` folder generated from this step
is to be used in all cases below for `{gfxreconstruct_root}`.

### 2. Pull down the source for IGL

```bash
git clone --recurse-submodules https://github.com/facebook/igl.git
cd igl
```

Alternatively, if this is not the first time the tree is cloned, simply enter
the folder containing the source and update to the latest, but also make sure
that the submodules are re-inited and updated (because additional submodules may
have been added).

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

Edit the 'build\\android\\settings.gradle' file to include
the project location:

```text
@@ -23,3 +23,5 @@ rootProject.name = "IGL"
 include ':app'
 include ':app-openxr-vulkan'
 include ':app-openxr-gles'
+include ':VkLayer_gfxreconstruct'
+project(':VkLayer_gfxreconstruct').projectDir = file('{gfxreconstruct_root}\\android\\layer')
```

**NOTE**: Replace {gfxreconstruct_root} with the full path location of the
source you cloned from the GFXReconstruct repo in Step 1.


#### Add more permissions to AndroidManifest

Edit the
'shell\\openxr\\mobile\\java\\com\\facebook\\igl\\shell\\openxr\\vulkan\\AndroidManifest.xml'
file to include `MANAGE_EXTERNAL_STORAGE` permission required by Android 10 and later:

```text
@@ -12,6 +12,7 @@

   <uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
   <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
+  <uses-permission android:name="android.permission.MANAGE_EXTERNAL_STORAGE"/>
   <uses-permission android:name="android.permission.INTERNET" />
   <uses-permission android:name="com.oculus.permission.HAND_TRACKING" />
```


#### Update the OpenXR-SDK Usage in IGL to the latest

Edit the `third-party/bootstrap-deps.json` file to use a new OpenXR-SDK commit.

Update to at least sha1 of "be392bf6949adeeabad5082aa79d12aacbda781f".


#### Copy the GFXReconstruct OpenXR API Layer Manifest File

OpenXR finds the API Layer in the APK if the Manifest file is found under the assets folder.

There are a few changes required to do so:

1) Build GFXReconstruct manually for Android or Linux with OpenXR enabled to get the OpenXR
   Manifest file.

   The file will appear at:  `<build_folder>/layer/XrLayer_gfxreconstruct.json`

2) Modify the manifest file to work as an implicit layer by adding a field at the end of the
   "api_layer" section:

```
   "disable_environment" : "GFXRECON_DISABLE"
```

   **NOTE** You will need to add a comma after the previous field to be valid JSON

3) Create the directory location for containing the manifest file

    Under `shell/resources/images` create the following folder tree:
    `openxr/1/api_layers/implicit.d`

4) Copying the file into the appropriate location

### 4. Build IGL using Android Studio

 1. Select "app-openxr-vulkan" target
 2. Click on the hamburger menu (top left), select the `Build` menu and then `Rebuild` under that


## Capturing the Vulkan IGL Content

The example that follows uses the Meta IGL OpenXr Vulkan Sample built above and assumes
that you built the debug version.
The benefit of building the application in this way is that it will
automatically incorporate the GFXReconstruct capture layer into the .APK file
for the built application.

**NOTE:** This assumes you have installed the Quest Development Hub with its version
of the Android tools (such as ADB)

### 1. Run Logcat

```bash
adb logcat -s IGL vulkan VulkanLoader VulkanLoaderAndroid OpenXR OpenXR-Loader gfxrecon
```

### 2. Install and Run the Application

 1. Open Android Studio
 2. Connect the headset to your development machine using a USB plug
    a. Make sure the headset is detected by Android Stduio
 3. Select the headset in the target
 4. Make sure "app-openxr-vulkan" is selected
 5. Press the "Play" triangle to run
    a. You may have to first select to enable commands from the host system on the headset

This shows that you can run the application on the target.

### 3. Enable GFXReconstruct

Using the ADB installed from the Meta Quest Developer Hub
("C:\Program Files\Meta Quest Developer Hub\resources\bin\adb.exe" on some systems),
enable the GFXReconstruct layer only for the application using the global
settings:

```bash
adb shell

(logs into device)

settings put global enable_gpu_debug_layers 1
settings put global gpu_debug_app com.facebook.igl.shell.openxr.vulkan
settings put global gpu_debug_layers "VK_LAYER_LUNARG_gfxreconstruct"
```

### 4. Set the Capture Options

Now, set the command to capture frames 1-100 so we can see what's happening
and write the file to the `/sdcard/Download` folder:

```bash
adb shell

(logs into device)

setprop debug.gfxrecon.capture_file  '/sdcard/Download/samples_capture.gfxr'
setprop debug.gfxrecon.capture_frames '1-100'
```

More capture options can be found in the [USAGE_android.md](./USAGE_android.md)
under the [Capture Options](./USAGE_android.md#capture-options) section.

### 5. Re-Run the Application

Repeat the steps from section 2. above.

This time, however, you should see a generated capture file after exiting the
application in the `/sdcard/Download` folder called
`samples_capture_frames_1_to_100.gfxr` since you have selected to save
only some of the frames.
