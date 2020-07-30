# Build Instructions

Instructions for building the GFXReconstruct project source code on Linux,
Windows, and Android platforms.

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2018-2020 LunarG, Inc.

## Index

1. [Introduction](#introduction)
2. [Repository Content](#repository-content)
3. [Repository Set-Up](#repository-set-up)
4. [Windows Build](#building-for-windows)
5. [Linux Build](#building-for-linux)
6. [Android Build](#android)

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
| | toascii | Tool to convert GFXR capture files to an ASCII listing of API calls. |

## Repository Set-Up

### Clone the Repository

Use the following Git command to create a local copy of the GFXReconstruct
repository:

```bash
git clone https://github.com/LunarG/gfxreconstruct.git
```

### Repository Dependencies

The GFXReconstruct project has both required and optional dependencies. See
the [External Dependencies README.md](external/README.md) for details regarding
individual dependencies.

Required dependencies are included with the GFXReconstruct repository as Git
submodules. After cloning the repository, execute the following command
from within the GFXReconstruct project folder to initialize the submodules:

```bash
git submodule update --init
```

Submodules will be updated periodically as the GFXReconstruct project is
updated to support new Vulkan API releases. To obtain submodule updates,
execute the following command from within the GFXReconstruct project folder:

```bash
git submodule update
```

Submodules will need to be updated when the repository status (e.g.
`git status`) shows the submodule folders as having been modified
after a repository update (e.g. `git pull`).

## Common build instructions

For desktop builds, there is a Python 3 build script, `scripts/build.py`, that can
be used to update Git submodule dependencies, configure, and build the GFXReconstruct
software.  The script works with both Windows and Linux, and requires Python 3.5 or
above.

By default, the script performs some optional build steps that are intended for
developer builds.  If the target build system has not been configured for
developer builds as described in [CONTRIBUTING.md](CONTRIBUTING.md), the script
can be run with the following options to disable the developer build steps:

```bash
python scripts/build.py --skip-check-code-style --skip-tests
```

Run the script with the `-h` option for additional usage information.

## Building for Windows

### Windows Development Environment Requirements

- Microsoft [Visual Studio](https://www.visualstudio.com/)
  - Supported Versions
    - [2019](https://www.visualstudio.com/vs/downloads/)
    - [2017](https://www.visualstudio.com/vs/older-downloads/)
    - [2015](https://www.visualstudio.com/vs/older-downloads/)
  - The Community Edition for each of the above versions is sufficient
- [CMake](http://www.cmake.org/download/) (Version 3.1 or better)
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
cmake -H. -Bbuild -G "Visual Studio 15 Win64"
```

The following commands can be used to generate project files for different
variations of the Visual Studio 2015 and 2017 WIN32 and x64 build
configurations:

- 64-bit for VS 2015: cmake -H. -Bbuild -G "Visual Studio 14 Win64"
- 32-bit for VS 2017: cmake -H. -Bbuild -G "Visual Studio 15"
- 32-bit for VS 2015: cmake -H. -Bbuild -G "Visual Studio 14"

Running any of the above commands will create a Windows solution file named
`GFXReconstruct.sln` in the build directory.

At this point, you can build the solution from the command line or open the
generated solution with Visual Studio.

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

- A C++ compiler with C++-14 support
- Git
- CMake
- X11 + XCB and/or Wayland development libraries

#### Ubuntu

For Ubuntu, the required packages can be installed with the following command:

```bash
sudo apt-get install git cmake build-essential libx11-xcb-dev libxcb-keysyms1-dev \
        libwayland-dev libxrandr-dev zlib1g-dev liblz4-dev libzstd-dev
```

#### Fedora

For Fedora, the required packages can be installed with the following
command:

```bash
sudo dnf install git cmake libxcb-devel libX11-devel xcb-util-keysyms-devel \
        libXrandr-devel wayland-devel zlib-devel lz4-devel libzstd-devel
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
cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug
```

The following commands can be used to generate makefiles for different
variations of Debug and Release 32-bit and 64-bit build configurations,
where `-DCMAKE_BUILD_TYPE` is used to specify `Debug` or `Release` build
profiles:

- 64-bit Release: cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Release
- 32-bit Debug: cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS=-m32 -DCMAKE_SHARED_LINKER_FLAGS=-m32
- 32-bit Release: cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS=-m32 -DCMAKE_SHARED_LINKER_FLAGS=-m32

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

## Install the project

Files can be installed to "/usr/local/" with `sudo make install`

For Linux, the default install directory `/usr/local` can be changed by setting CMake's CMAKE_INSTALL_PREFIX
variable. For example, to install to a "/tmp/gfxreconstruct" directory, run `cmake -DCMAKE_INSTALL_PREFIX=/tmp/gfxreconstruct .`
from gfxreconstruct's root source directory. Then install with `make install`.

## Android

### Android Development Requirements

- The latest version of [Android Studio](https://developer.android.com/studio/) with additional items:
  - The [Android Platform tools](https://developer.android.com/studio/releases/platform-tools) for your specific platform
  - The [Android NDK](https://developer.android.com/ndk/guides/)
  - [Android SDK 26 (8.0 Oreo) or newer](https://guides.codepath.com/android/installing-android-sdk-tools)
- Set the following `ANDROID_*` environment variables appropriately in your user environment if building outside of Android Studio:
  - `ANDROID_NDK_HOME`
  - `ANDROID_SDK_HOME`

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
