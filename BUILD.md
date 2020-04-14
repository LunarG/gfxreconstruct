# Build Instructions
Instructions for building the GFXReconstruct project source code on Linux,
Windows, and Android platforms.

## Index
1. [Contributing](#contributing-to-the-repository)
2. [Repository Content](#repository-content)
3. [Repository Set-Up](#repository-set-up)
4. [Windows Build](#building-on-windows)
5. [Linux Build](#building-on-linux)
6. [Android Build](#android)

## Contributing to the Repository
The preferred work flow for external contributions is to develop the
contribution in a fork of the GFXReconstruct repository and to submit a pull
request for the completed contribution.

Please see [CONTRIBUTING.md](CONTRIBUTING.md) for more details.

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
| | replay | Tool to replay GFXR capture files. |
| | toascii | Tool to convert GFXR capture files to an ASCII listing of API calls. |

## Repository Set-Up
### Download the Repository
Use the following Git command to create a local copy of the GFXReconstruct
repository:
```
git clone https://github.com/LunarG/gfxreconstruct.git
```

### Repository Dependencies
The GFXReconstruct project has both required and optional dependencies. See
the [External Dependencies README.md](external/README.md) for details regarding
individual dependencies.

Required dependencies are included with the GFXReconstruct repository as Git
submodules. After cloning the repository, execute the following command
from within the GFXReconstruct project folder to initialize the submodules:
```
git submodule update --init
```

Submodules will be updated periodically as the GFXReconstruct project is
updated to support new Vulkan API releases. To obtain submodule updates,
execute the following command from within the GFXReconstruct project folder:
```
git submodule update
```

Submodules will need to be updated when the repository status (e.g.
`git status`) shows the submodule folders as having been modified
after a repository update (e.g. `git pull`).

## Common build instructions
- There is a Python-3 build.py script at the repo root that can be used to update
  all dependencies, and build the project on both Windows and Linux.
  Run the script with the -h option to get help on how to run the build using
  the script.  
  The script requires Python 3.5 and above.
- There is an optional pre-build step for every target to run clang-format
  to apply the GFXReconstruct code style on the code.  
  This requires clang-format to be installed on the system.
  Use the `-DAPPLY_CPP_CODE_STYLE=ON` option to enable this pre-build step.
  Use the --code-style option if building with the build script.
  Code style is not applied to generated files.
- It is recommended to run static analysis on the code before submission.
  Use the -DRUN_STATIC_ANALYSIS=ON to run a post-build static analysis using
  clang-tidy.
  Use the --static-analysis option if building with the build script.

## Building for Windows
### Windows Development Environment Requirements
- Microsoft [Visual Studio](https://www.visualstudio.com/)
  - Versions
    - [2015](https://www.visualstudio.com/vs/older-downloads/)
    - [2017](https://www.visualstudio.com/vs/downloads/)
  - The Community Edition for each of the above versions is sufficient.
- [CMake](http://www.cmake.org/download/) (Version 3.1 or better)
  - Use the installer option to add CMake to the system PATH
- Git Client Support
  - [Git for Windows](http://git-scm.com/download/win) is a popular solution
    for Windows
  - Some IDEs (e.g., [Visual Studio](https://www.visualstudio.com/),
    [GitHub Desktop](https://desktop.github.com/)) have integrated
    Git client support
- Clang-format and Clang-tidy can be installed by installing the Windows Clang
  package from http://llvm.org/builds/

### Windows Build - Microsoft Visual Studio
The general approach is to run CMake to generate the Visual Studio project
files.
Then either run CMake with the `--build` option to build from the command line
or use the Visual Studio IDE to open the generated solution and work with the
solution interactively.

#### Use `CMake` to Create the Visual Studio Project Files
Change your current directory to the top level directory for the cloned
GFXReconstruct repository, create a build folder, and generate the Visual
Studio project files.

The following example demonstrates the generation of project files for the
Visual Studio 2017 x64 build configuration:
```
cd gfxreconstruct
mkdir build
cmake -H. -Bbuild -G "Visual Studio 15 Win64"
```

The following commands can be used to generate project files for different
variations of the Visual Studio 2015 and 2017 WIN32 and x64 build
configurations:
 * 64-bit for VS 2015: cmake -H. -Bbuild -G "Visual Studio 14 Win64"
 * 32-bit for VS 2017: cmake -H. -Bbuild -G "Visual Studio 15"
 * 32-bit for VS 2015: cmake -H. -Bbuild -G "Visual Studio 14"

The above steps create a Windows solution file named
`GFXReconstruct.sln` in the build directory.

At this point, you can build the solution from the command line or open the
generated solution with Visual Studio.

#### Build the Solution From the Command Line
To build the Debug configuration, run the following command from the build
directory:
```
cmake --build .
```

To build the Release configuration, run the following command from the build
directory:
```
cmake --build . --config Release
```

#### Build the Solution With Visual Studio
Launch Visual Studio and open the `GFXReconstruct.sln` solution file
from the build folder. You may select "Debug" or "Release" from the Solution
Configurations drop-down list. Start a build by selecting the Build->Build
Solution menu item.

## Building for Linux
#### Required Package List
Building on Linux requires the installation of the following packages:
* A C++ compiler with C++-14 support
* Git
* CMake
* X11 + XCB and/or Wayland development libraries
* clang-format package

The following optional packages are also recommended:
* clang-tidy package

##### Ubuntu
On Ubuntu, the required packages can be installed with the following
command:
```
sudo apt-get install git cmake build-essential libx11-xcb-dev libxcb-keysyms1-dev \
        libwayland-dev libxrandr-dev liblz4-dev libzstd-dev clang-format clang-tidy
```

##### Fedora Core
On Fedora Core, the required packages can be installed with the following
command:
```
sudo dnf install git cmake libxcb-devel libX11-devel xcb-util-keysyms-devel \
        libXrandr-devel wayland-devel lz4-devel libzstd-devel clang clang-tools-extra
```

### Linux Build
The general approach is to run CMake to generate make files. Then either run
CMake with the `--build` option or `make` to build from the command line.

#### Use CMake to Create the Make Files
Change your current directory to the top level directory for the cloned
GFXReconstruct repository, create a build folder, and generate the make
files.
```
cd gfxreconstruct
mkdir build
cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug
```

Use `-DCMAKE_BUILD_TYPE` to specify a `Debug` or `Release` build profile.

#### Build the Project
Run either the `make` or `cmake --build .` command from the build directory
to build the GFXReconstruct project source.

For faster builds on multi-core systems with `make`, use `make -j` to
specify the number of cores to use for the build. For example:
```
make -j4
```

For build systems that support ccache, enable it with the CMake
`-DUSE_CCACHE=On` option.

## Android
### Android Develpment Requirements
 * The latest version of [Android Studio](https://developer.android.com/studio/) with additional items:
   * The [Android Platform tools](https://developer.android.com/studio/releases/platform-tools) for your specific platform
   * The [Android NDK](https://developer.android.com/ndk/guides/)
   * [Android SDK 26 (8.0 Oreo) or newer](https://guides.codepath.com/android/installing-android-sdk-tools)
 * Set the following `ANDROID_*` environment variables appropriately in your user environment if building outside of Android Studio:
   * `ANDROID_NDK_HOME`
   * `ANDROID_SDK_HOME`

### Android Build
#### Building with Gradle
Run the following command from the `gfxreconstruct/android` folder to perform a
debug build with Gradle:

On Windows:
```
gradlew assembleDebug
```

On Linux:
```
./gradlew assembleDebug
```

To perform a release build, replace the `assembleDebug` task name with `assembleRelease`.

#### Building with Android Studio
1. Open Android Studio
2. Choose `Import Project`, browse to the `gfxreconstruct/android` folder, and click `OK`.
  * This option is available through either the opening Dialog box or the `File -> New -> Import Project...` menu item
  * If import succeeds, the following two project modules will be displayed by the Project browser:
    * layer  - The GFXReconstruct capture layer for recording Vulkan API data
    * replay - The GFXReconstruct tool to replay GFXR capture files
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
```
include ':VkLayer_gfxreconstruct'
project(':VkLayer_gfxreconstruct').projectDir = file('{gfxreconstruct_root}/android/layer')
```

Next, add the following lines to the application's `build.gradle` file:
```
    dependencies {
        implementation project(':VkLayer_gfxreconstruct')
    }
```
