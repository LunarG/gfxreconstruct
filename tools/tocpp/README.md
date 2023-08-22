### Overview

The ToCpp tool converts the GFXReconstruct capture file into a cpp source with Vulkan API calls.

The tool can generate Vulkan source either for Android or desktop (xcb surface).

### Generate the source for Android

##### Prerequisites
- build the ToCpp tool

##### Conversion

```sh
# In the root of GFXReconstruct
./build/tools/tocpp/gfxrecon-tocpp -t android -o out_android --android-template external/Tocpp-Android-Template/ ./android_capture.gfxr
```

- `-t android` `(--target android)` indicates that we generate for Android.
- `-o out_android` `(--output out_android)` specify the directory where all the required files will be copied/generated.
- `--android-template external/Tocpp-Android-Template/` specify where is the android template.

At the end in the output directory (`out_android`) all files from the template directory (specified by `--android-template`), the generated `app/src/main/jni/VulkanMain.cpp` and the saved image data (`app/src/main/assets/*.bin`) can be found.

### Build the apk

##### Prerequisites
- [Gradle](https://gradle.org/install/)
- Android NDK
    * [NDK](https://developer.android.com/ndk/downloads/index.html)
    * SDK with the latest cmake package

**OR**

- [Android Studio 3.0](https://developer.android.com/studio/index.html) or higher

Create the apk:

```sh
# Inside the output directory (`out_android`)
gradle assembleDebug
```

### Install the apk

##### Prerequisites
- A device running Android 7.0 (API level 24) or higher
- The program `adb` if we want to install it outside of the Android Studio.

```sh
# Inside the output directory (`out_android`)
adb install ./app/build/outputs/apk/debug/app-debug.apk
```
### Generate the source for desktop (XCB)

```sh
# In the root of GFXReconstruct
./build/tools/tocpp/gfxrecon-tocpp -t xcb -o out_xcb_capture ./capture.gfxr
```

- `-t xcb` `(--target xcb)` indicates that we generate for XCB platform.
- `-o out_xcb_capture` `(--output out_xcb_capture)` specify the directory where all the required files will be generated.

At the end the output directory (`out_xcb_capture`) contains the generated `capture.cpp` and the saved image data (`*.bin`).

### Build the source for desktop (XCB)

```sh
# Inside the output directory (`out_xcb_capture`)
cmake -H. -Bbuild
make -C build  # recommended to specify the number of jobs with '-j <cpu_num>'. For example: make -C build -j ${nproc}
```

### Run the source for desktop (XCB)

```sh
# Inside the output directory (`out_xcb_capture`)
./build/vulkan_app
```
