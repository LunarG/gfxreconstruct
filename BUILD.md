# Build Instructions

Instructions for building the GFXReconstruct project source code on Linux,
Windows, and Android platforms.

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2018-2023 LunarG, Inc.

## Index

1. [Introduction](#introduction)
2. [Repository Content](#repository-content)
3. [Repository Set-Up](#repository-set-up)
4. [Windows Build](#building-for-windows)
5. [Linux Build](#building-for-linux)
6. [Android Build](#building-for-android)

## Introduction

The following documentation provides end user build instructions for
the GFXReconstruct software.  Developers interested in contributing to the
project should also see [CONTRIBUTING.md](CONTRIBUTING.md) for additional
setup instructions.

## Repository Content

The GFXReconstruct repository contains the source code for a Vulkan API
capture layer and associated tools for processing captured files. It is
organized with the following file structure:

| Top Folder  | Sub-Folder | Description  |
|---|---|---|
| android  | | Android build files and script for deploying and launching the replay tool. |
| cmake    | | CMake utility files to assist with the build process. |
| external | | Third party components provided as either Git sub-modules or pre-compiled binaries. |
| framework | | Framework library components used to create the capture layer and associated tools.|
| | application | Library providing components to manage replay execution and adapt to different windowing systems. |
| | decode | Library providing components to decode and process GFXR capture file content. |
| | encode | Library providing components to encode and write GFXR capture file content. |
| | format | Library providing utilities and type definitions for the GFXR capture file format. |
| | generated | Python code generators for the Vulkan XML Registry, along with the generated C++ source code to be used for encoding and decoding Vulkan API-related data. |
| | util | Library providing utility functions. |
| layer | | GFXReconstruct capture layer for recording Vulkan API data. |
| tools | | Tools for processing capture files. |
| | compress | Tool to compress or decompress GFXR capture files. |
| | extract | Tool to extract SPIR-V binaries from GFXR capture files. |
| | info | Tool to print information describing GFXR capture files. |
| | replay | Tool to replay GFXR capture files. |
| | convert | Tool to convert GFXR capture files to a JSON Lines listing of API calls. |

## Repository Set-Up

### Clone the Repository

Use the following Git command to create a local copy of the GFXReconstruct
repository:

```bash
git clone --recursive  https://github.com/LunarG/gfxreconstruct.git
```

### Repository Dependencies

The GFXReconstruct project has both required and optional dependencies. See
the [External Dependencies README.md](external/README.md) for details regarding
individual dependencies.

Required dependencies are included with the GFXReconstruct repository as Git
submodules.

If you clone the repository without the `--recursive` option, execute the
following command from within th GFXReconstruct project folder to initialize
the submodules:

```bash
git submodule update --init --recursive
```

Submodules will be updated periodically as the GFXReconstruct project is
updated to support new Vulkan API releases. To obtain submodule updates,
execute the following command from within the GFXReconstruct project folder:

```bash
git submodule update --recursive 
```

Submodules will need to be updated when the repository status (e.g.
`git status`) shows the submodule folders as having been modified
after a repository update (e.g. `git pull`).

## Common build instructions

For desktop builds, there is a Python 3 build script, `scripts/build.py`, that can
be used to update Git submodule dependencies, configure, and build the GFXReconstruct
software.  The script works with both Windows and Linux, and requires Python 3.5 or
above.

A 64 bit ARM Windows build can be achieved on an ARM64 Windows host system with the
following command:

```bat
python scripts/build.py -a arm64
```

By default, the script performs some optional build steps that are intended for
developer builds.  If the target build system has not been configured for
developer builds as described in [CONTRIBUTING.md](CONTRIBUTING.md), the script
can be run with the following options to disable the developer build steps:

```bash
python scripts/build.py --skip-check-code-style --skip-tests
```

The above invocation will run on a single core.
To speed up the build with parallel processes,
the standard CMake environment variable
[`CMAKE_BUILD_PARALLEL_LEVEL`](https://cmake.org/cmake/help/latest/envvar/CMAKE_BUILD_PARALLEL_LEVEL.html)
may be used.
For example, to use eight processes from within Bash:

```bash
CMAKE_BUILD_PARALLEL_LEVEL=8 python scripts/build.py --skip-check-code-style --skip-tests
```

By default, the script builds support for capturing and replaying
Direct3D 12.  To omit Direct3D 12 components, specify
`--skip-d3d12-support`.  For example:

```bash
python scripts/build.py --skip-d3d12-support
```

Run the script with the `-h` option for additional usage information.

### Enabling OpenXR Support During a Build

To enable OpenXR Support in GFXReconstruct enable the CMake option during build
generation time by setting the CMake variable `GFXRECON_ENABLE_OPENXR` to `ON`
in the following way:

```bash
cmake . -Bbuild -G ... -DGFXRECON_ENABLE_OPENXR=ON
```

**NOTE:**  OpenXR support is not fully implemented and should only be used at
your own risk.

## Building for Windows

### Windows Development Environment Requirements

- Microsoft [Visual Studio](https://www.visualstudio.com/)
  - Supported Versions
    - [2022](https://www.visualstudio.com/vs/downloads/)
    - [2019](https://www.visualstudio.com/vs/older-downloads/)
    - [2017](https://www.visualstudio.com/vs/older-downloads/)
  - The Community Edition for each of the above versions is sufficient
- [CMake](http://www.cmake.org/download/) (Version 3.16.3 or newer)
  - The build instructions assume that CMake has been added to the system PATH
- Git Client Support
  - [Git for Windows](http://git-scm.com/download/win) is a popular solution
    for Windows
  - Some IDEs (e.g., [Visual Studio](https://www.visualstudio.com/),
    [GitHub Desktop](https://desktop.github.com/)) have integrated
    Git client support

### Windows Build - Microsoft Visual Studio

The general approach is to first run CMake to generate the Visual Studio project
files.  Then either run CMake with the `--build` option to build from the command
line or use the Visual Studio IDE to open the generated solution and work with the
solution interactively.

#### Generate Visual Studio Project Files with `CMake`

Change your current directory to the top level directory for the cloned
GFXReconstruct repository, create a build folder, and generate the Visual
Studio project files.

The following example demonstrates the generation of project files for the
Visual Studio 2017 x64 build configuration:

```bat
cd gfxreconstruct
mkdir build
cmake . -Bbuild -G "Visual Studio 15 Win64"
```

The following commands can be used to generate project files for different
variations of the Visual Studio 2017 WIN32 and x64 build configurations:

- 64-bit for VS 2017: `cmake . -Bbuild -G "Visual Studio 15 Win64"`
- 32-bit for VS 2017: `cmake . -Bbuild -G "Visual Studio 15"`

Running any of the above commands will create a Windows solution file named
`GFXReconstruct.sln` in the build directory.

Visual Studio configuration will include support for capturing and replaying Direct3D 12 by default.  To omit Direct3D 12 components, specify `-DD3D12_SUPPORT=OFF` to cmake.

At this point, you can build the solution from the command line or open the
generated solution with Visual Studio.

**Note: The D3D12 build uses Windows 10 SDK 10.0.20348.0. Other Windows SDK versions may not be compatible. If you need to specify a Windows SDK, please use `-DCMAKE_SYSTEM_VERSION=10.0.20348.0`. If Python code generation is required, the shell used to run it should set the environment variable `WindowsSDKVersion=10.0.20348.0`.**

When generating a native build on an ARM64 Windows host the Visual Studio
Installer can be used to install the required Windows SDK version, `10.0.20348.0`.
Once the correct Windows SDK is installed, from a newly opened developer command
prompt for Visual Studio 2022, the following CMake invocation will generate a Visual
Studio solution and projects.

```bat
cmake . -Bbuild -G "Visual Studio 17 2022" -A ARM64 -DCMAKE_SYSTEM_VERSION=10.0.20348.0
```

#### Build the Solution From the Command Line

To build the Debug configuration, run the following command from the build
directory:

```bat
cmake --build .
```

To build the Release configuration, run the following command from the build
directory:

```bat
cmake --build . --config Release
```

#### Build the Solution With Visual Studio

Launch **Visual Studio** and open the `GFXReconstruct.sln` solution file
from the build folder. You may select "Debug" or "Release" from the Solution
Configurations drop-down list. Start a build by selecting the Build->Build
Solution menu item.

## Building for Linux

### Required Package List

Building on Linux requires the installation of the following packages:

- A C++ compiler with C++-17 support
- Git
- CMake
- X11 + XCB and/or Wayland development libraries

#### Ubuntu

GFXReconstruct is built and tested for SDK development using Ubuntu 20.04 and 22.04.  Older Ubuntu releases are unsupported.

For Ubuntu, the required packages can be installed with the following command:

```bash
sudo apt-get install git cmake build-essential libx11-xcb-dev libxcb-keysyms1-dev \
        libxcb-glx0-dev libwayland-dev libxrandr-dev zlib1g-dev liblz4-dev libzstd-dev
```

For 32-bit builds (DXVK might require 32-bit):
```bash
sudo apt-get install g++-multilib libx11-xcb-dev:i386 libxcb-keysyms1-dev:i386 \
        libxcb-glx0-dev:i386 libwayland-dev:i386 libxrandr-dev:i386 zlib1g-dev:i386 \
        liblz4-dev:i386 libzstd-dev:i386
```

For arm64 builds (cross compilation):

```bash
sudo apt-get install g++-aarch64-linux-gnu
```

#### Fedora

For Fedora, the required packages can be installed with the following
command:

```bash
sudo dnf install git cmake libxcb-devel libX11-devel xcb-util-keysyms-devel \
        libXrandr-devel wayland-devel zlib-devel lz4-devel libzstd-devel g++
```

For arm64 builds (cross compilation):

```bash
sudo dnf install g++-aarch64-linux-gnu
```


### Linux Build

The general approach is to run CMake to generate makefiles. Then either run
CMake with the `--build` option or `make` to build from the command line.

#### Use CMake to Create the Makefiles

Change your current directory to the top level directory for the cloned
GFXReconstruct repository, create a build folder, and generate the make
files.

The following example demonstrates makefile generation for a 64-bit Debug build:

```bash
cd gfxreconstruct
mkdir build
cmake . -Bbuild -DCMAKE_BUILD_TYPE=Debug
```

The following commands can be used to generate makefiles for different
variations of Debug and Release, as well as different architectures.
`-DCMAKE_BUILD_TYPE` is used to specify `Debug` or `Release` build
profiles and the `-DCMAKE_TOOLCHAIN_FILE` with a matching toolcain file
can be changed to compile for different architectures:

- 64-bit x64 Release (default): cmake . -Bbuild -DCMAKE_BUILD_TYPE=Release
- 32-bit x86 Debug: cmake . -Bbuild -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain/linux_x86_32.cmake
- 32-bit x86 Release: cmake . -Bbuild -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain/linux_x86_32.cmake
- 32-bit arm Release: cmake . -Bbuild -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain/linux_arm.cmake
- 64-bit arm Release: cmake . -Bbuild -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain/linux_arm64.cmake

For 32-bit builds, the 32-bit versions of the required packages specified above
must be installed.

#### Build the Project

Run either the `make` or `cmake --build .` command from the build directory
to build the GFXReconstruct project source.

For faster builds on multi-core systems with `make`, use `make -jN` to
specify the number of jobs that are allowed to run at the same time with
the build.  For example:

```bash
make -j4
```

For build systems that support ccache, it can be enabled with the CMake
`-DUSE_CCACHE=On` option.

#### Install the project

Files can be installed to "/usr/local/" with `sudo make install`

For Linux, the default install directory `/usr/local` can be changed by setting CMake's CMAKE_INSTALL_PREFIX
variable. For example, to install to a "/tmp/gfxreconstruct" directory, run `cmake -DCMAKE_INSTALL_PREFIX=/tmp/gfxreconstruct .`
from gfxreconstruct's root source directory. Then install with `make install`.


## Building for MacOS


### Required Package List

Building on MacOS requires the installation of the following packages:

- Command Line Tools (CLT) for Xcode: 
  - from `xcode-select --install` 
  - or https://developer.apple.com/download/all/) 
  - or [Xcode](https://itunes.apple.com/us/app/xcode/id497799835)
- Git
- CMake
  - install e.g. via https://brew.sh/

### MacOS Build
The approach is identical to a linux-build with one addition.

#### Explicit CPU-Architecture
Building for specific cpu-architectures can be accomplished by using the cmake-variable `CMAKE_OSX_ARCHITECTURES` 
with values `x86_64` (Intel) or `arm64` (Apple Silicon).
The default behavior is to build only for the architecture present in the build-machine.
A universal build, containing code for both architectures, can be done like this:

```bash
cd gfxreconstruct
mkdir build
cmake . -Bbuild -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64"
cd build
make -j4
```

## Building for Android

### Android Development Requirements

- The latest version of [Android Studio](https://developer.android.com/studio/) with additional items:
  - The [Android Platform tools](https://developer.android.com/studio/releases/platform-tools) for your specific platform
  - [Android SDK 33 (13 Tiramisu) or newer](https://guides.codepath.com/android/installing-android-sdk-tools)
  - [Android NDK 21.3.6528147 (r21d)](https://developer.android.com/ndk/guides/)
- [Java JDK 1.11](https://jdk.java.net/11)

#### Additional Linux Command-Linux Prerequisites

Additional requirements for building from the Linux command-line:
- Define `ANDROID_HOME`to be the path to the SDK installed on your system by Android Studio.
  - Refer to Android Studio to find out where the files are installed
    - **NOTE:** For older Android Stud io's you may also have to set `ANDROID_SDK_ROOT` to the same value
  - For example:

```bash
        export ANDROID_HOME=$HOME/Android/Sdk`
```

- Define JAVA_HOME to the path to the directory of the JDK.
  - For example:

```bash
      export JAVA_HOME=/usr/lib/jvm/java-11-openjdk-11.0.18.0.10-1.fc37.x86_64
```

- Make the `gradlew` script executable
  - `chmod +x android/gradlew`

### Android Build

#### Building with Gradle

Run the following command from the `gfxreconstruct/android` folder to perform a
debug build with Gradle:

On Windows:

```bat
gradlew assembleDebug
```

On Linux:

```bash
./gradlew assembleDebug
```

To perform a release build, replace the `assembleDebug` task name with `assembleRelease`.

#### Building with Android Studio

1. Open Android Studio
2. Choose `Import Project`, browse to the `gfxreconstruct/android` folder, and click `OK`.
    - This option is available through either the opening Dialog box or the `File -> New -> Import Project...` menu item
    - If import succeeds, the following two project modules will be displayed by the Project browser:
    - layer  - The GFXReconstruct capture layer for recording Vulkan API data
    - replay - The GFXReconstruct tool to replay GFXR capture files
3. Build the project by selecting the `Build -> Make Project` menu item or pressing `Ctrl+F9`

#### Adding the Layer to Existing Projects

The GFXReconstruct layer project may be added as a dependency of an existing
Android application project. After the layer has been added as an application
dependency, it will be built when the application is built and automatically
included with the application's APK. A manifest file provided by the
GFXReconstruct layer project will also be merged with the application's
Manifest file, adding `uses-permission` elements for the permissions required
by the layer (e.g. `WRITE_EXTERNAL_STORAGE`).

To add the GFXReconstruct project as an application dependency, first add the
following lines to the application's `settings.gradle` file, replacing the
`{gfxreconstruct_root}` value with the actual path to the top level
GFXReconstruct project folder:

```text
include ':VkLayer_gfxreconstruct'
project(':VkLayer_gfxreconstruct').projectDir = file('{gfxreconstruct_root}/android/layer')
```

Next, add the following lines to the application's `build.gradle` file:

```text
    dependencies {
        implementation project(':VkLayer_gfxreconstruct')
    }
```

**NOTE:** Make sure it is the app version of `build.gradle` (usually found in an
app folder).
This may not necessarily be the top `build.gradle` in the tree.

#### Adding the Vulkan Validation Layer to `gfxrecon-replay`

1. Download the latest Android Vulkan Validation Layer binaries from the [GitHub release page](https://github.com/KhronosGroup/Vulkan-ValidationLayers/releases)
2. Extract the prebuilt layer binaries and include them in the `gfxrecon-replay` APK by adding them to the following directories:
```text
gfxreconstruct/android/tools/replay/src/main/jniLibs/
    arm64-v8a/
        libVkLayer_khronos_validation.so
    armeabi-v7a/
        libVkLayer_khronos_validation.so
    x86/
        libVkLayer_khronos_validation.so
    x86-64/
        libVkLayer_khronos_validation.so
```
3. Rebuild and deploy `gfxrecon-replay`

The [Android Vulkan Validation Guide](https://developer.android.com/ndk/guides/graphics/validation-layer) has further instructions for advanced validation layer usage on Android


#### Android Detailed Examples

For more information and detailed examples on building and using GFXReconstruct
on Android can be found in the [HOWTO_android.md](./HOWTO_android.md) document.
