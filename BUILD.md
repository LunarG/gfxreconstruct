# Build Instructions

Instructions for building this repository on Linux, Windows, and Android


## Index

1. [Contributing](#contributing-to-the-repository)
2. [Repository Content](#repository-content)
3. [Repository Set-Up](#repository-set-up)
4. [Windows Build](#building-on-windows)
5. [Linux Build](#building-on-linux)
6. [Android Build](#android)


## Contributing to the Repository

If you intend to contribute, the preferred work flow is for you to develop
your contribution in a fork of this repository in your GitHub account and then
submit a pull request.
Please see the [CONTRIBUTING.md](CONTRIBUTING.md) file in this repository for
more details.


## Repository Content

This repository contains the source code necessary to build the LunarG
GFXReoncstruct layer and applications.
The folders contain the following content:

| Top Folder  | Sub-Folder | Description  |
|---|---|---|
| android  | | Android utilities and files necessary to build the content of this repo for Android. |
| cmake    | | CMake utility files for assisting in the build process. |
| external | | Additional source repositories pulled into this repository as sub-modules. |
| framework | | Top-level folder containing framework files for this repository.|
| | application | Application framework files for abstracting key information away from the main application code. |
| | decode | Various functionality to assist in decoding the content of an application.  This is typically used by replay consumers. |
| | encode | Various functionality to assist in the encoding of content for an application.  This is typically used by the GFXReoncstruct layer. |
| | format | Functionality used to define the various formats and containers for the basic bits of functionality. |
| | generated | Generated source files and generator scripts (in Python) used to assist in the encode and decode of supported APIs. |
| | util | General utility functionality to assist in platform portability. |
| layer | | Contains the code that produces the GFXReconstruct Vulkan layer used to capture Vulkan commands. |
| tools | | Top-level folder containing the application tools for this repository. |
| | compress | A tool used to compress or uncompress GFXReconstruct capture files. |
| | replay | A tool used to replay commands in a GFXReconstruct capture file. |
| | toascii | A tool used to dump out the contents of the commands in a GFXReconstruct capture file as ascii content. |


## Repository Set-Up

### Display Drivers

This repository does not contain a Vulkan-capable driver.
You will need to obtain and install a Vulkan driver from your graphics
hardware vendor or from some other suitable source if you intend to run
Vulkan applications.

### Download the Repository

To create your local git repository:

```
git clone https://github.com/LunarG/gfxreconstruct.git
```

### Repository Dependencies

This repository has dependencies on the
[Volk](https://github.com/zeux/volk) and
[Vulkan-Headers](https://github.com/KhronosGroup/Vulkan-Headers)
repositories.
Both of these repositories are added to the project as Git Submodules.

Once the repository has been cloned, you must enter the gfxreconstruct 
source directory you create and pull down the submodule information using
the following command:

```
git submodule update --init --recursive
```

Once this has been done, you should have the latest source.
However, occasionally the submodules will be updated and you will need to
update the submodules using the following command:

```
git submodule update --recursive
```


## Building On Windows

### Windows Development Environment Requirements

- Windows
  - Any Personal Computer version supported by Microsoft
- Microsoft [Visual Studio](https://www.visualstudio.com/)
  - Versions
    - [2015](https://www.visualstudio.com/vs/older-downloads/)
    - [2017](https://www.visualstudio.com/vs/downloads/)
  - The Community Edition of each of the above versions is sufficient, as
    well as any more capable edition.
- [CMake](http://www.cmake.org/download/) (Version 3.1 or better)
  - Use the installer option to add CMake to the system PATH
- Git Client Support
  - [Git for Windows](http://git-scm.com/download/win) is a popular solution
    for Windows
  - Some IDEs (e.g., [Visual Studio](https://www.visualstudio.com/),
    [GitHub Desktop](https://desktop.github.com/)) have integrated
    Git client support

### Windows Build - Microsoft Visual Studio

The general approach is to run CMake to generate the Visual Studio project
files.
Then either run CMake with the `--build` option to build from the command line
or use the Visual Studio IDE to open the generated solution and work with the
solution interactively.

#### Use `CMake` to Create the Visual Studio Project Files

Change your current directory to the top of the cloned repository directory,
create a build directory and generate the Visual Studio project files:

```
cd gfxreconstruct
mkdir build
cmake -H. -Bbuild -G "Visual Studio 15 Win64"
```

The above is for building 64-bit binaries using Visual Studio 2017. If you want to build 32-bit binaries or want to build using a different version of Visual Studio, you can use one of the following variations:

 * 64-bit for VS 2015: cmake -H. -Bbuild -G "Visual Studio 14 Win64"
 * 32-bit for VS 2017: cmake -H. -Bbuild -G "Visual Studio 15"
 * 32-bit for VS 2015: cmake -H. -Bbuild -G "Visual Studio 14"

The above steps create a Windows solution file named
`GFXReconstruct.sln` in the build directory.

At this point, you can build the solution from the command line or open the
generated solution with Visual Studio.

#### Build the Solution From the Command Line

While still in the build directory:

```
cmake --build .
```

to build the Debug configuration (the default), or:

```
cmake --build . --config Release
```

to make a Release build.

#### Build the Solution With Visual Studio

Launch Visual Studio and open the "GFXReconstruct.sln" solution file
in the build folder. You may select "Debug" or "Release" from the Solution
Configurations drop-down list. Start a build by selecting the Build->Build
Solution menu item.


## Building On Linux

### Linux Build Requirements

This repository has been built and tested on the two most recent Ubuntu LTS
versions. Currently, the oldest supported version is Ubuntu 14.04, meaning
that the minimum supported compiler versions are GCC 4.8.2 and Clang 3.4,
although earlier versions may work. It should be straightforward to adapt this
repository to other Linux distributions.

#### Required Package List

Building on Linux requires the installation of the following packages:

* A C++ compiler
* GIT
* CMake
* X11, XCB and Wayland development libraries

Additional recommended tools packages include:

* Python 3

##### Ubuntu

On Ubuntu, the required packages can be installed with the following
command:

```
sudo apt-get install git cmake build-essential libx11-xcb-dev \
        libxkbcommon-dev libwayland-dev libxrandr-dev
```

##### Fedora Core

On Fedora Core, the required packages can be installed with the following
command:

```
sudo dnf install git cmake libxcb-devel libxkbcommon-devel \
        libXrandr-devel wayland-devel
```


### Linux Build

The general approach is to run CMake to generate make files. Then either run
CMake with the `--build` option or `make` to build from the command line.


#### Use CMake to Create the Make Files

Change your current directory to the top of the cloned repository directory,
create a build directory and generate the make files.

```
cd gfxreconstruct
mkdir build
cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug
```

Use `-DCMAKE_BUILD_TYPE` to specify a Debug or Release build.

#### Build the Project

You can just run `make` to begin the build.

To speed up the build on a multi-core machine, use the `-j` option for `make`
to specify the number of cores to use for the build. For example:

```
make -j4
```

You can also use

```
cmake --build .
```

If your build system supports ccache, you can enable that via CMake option `-DUSE_CCACHE=On`


## Android

### Android Preparation

Install the required tools for Linux and Windows covered above, then add the
following:

 * The latest version of [Android Studio](https://developer.android.com/studio/) with additional items:
   * The [Android Platform tools](https://developer.android.com/studio/releases/platform-tools) for your specific platform
   * The [Android NDK](https://developer.android.com/ndk/guides/)
   * [Android SDK 23 (6.0 Marshmallow) or newer](https://guides.codepath.com/android/installing-android-sdk-tools)
 * Set the following `ANDROID_*` environment variables appropriately in your user environment if building outside of Android Studio:
   * `ANDROID_NDK_HOME`
   * `ANDROID_SDK_HOME`

### Android Build Process

In the following snippets you will see the following defines.  Replace them with the item described next to them in the table:


| Tag | Replace With  |
|---|---|
| `{gfxreconstruct_root}` | Substitute in the path to the GFXReconstruct source folder on your system |


**TODO:** Add something here about running gradlew from the command line to build


#### Building Stand-alone

1. Open Android Studio
2. Choose "Import Project" and browse to the `{gfxreconstruct_root}/android` folder and click "OK".
 * This option may appear in either the opening Dialog box, or if you choose `File -> New -> Import Project...`
 * Once imported, you should see at least 2 project modules:
   * layer  - The GFXReconstruct layer that is used to record capture files
   * replay - The GFXReconstruct capture file replay tool
3. Build the project

#### Building With Your Existing App

If you are building your app with Android Studio or with gradle, you can do the following to add the layer module as a dependency of your app.
Adding the layer as a dependency will make gradle build the layer when building your app and add the layer to your app's APK.
It will also merge the layer module's Manifest file with your app's Manifest file, automatically including the permissions that the layer requires (currently just access to storage).

1. In your app's settings.gradle file, add something like the following:

```
include ':VkLayer_gfxreconstruct'
project(':VkLayer_gfxreconstruct').projectDir = file('{gfxreconstruct_root}/android/layer')
```

2.  In your app's build.gradle file, add this:

```
    dependencies {
        implementation project(':VkLayer_gfxreconstruct')
    }
```

##### Possible Errors with Merging

If you get errors on the merging of the manifest files, you should open the
AndroidManifest.xml file associated with your source project and click the
"Merged Manifest" button at the bottom of the text editor.
This should show what errors have occurred.

One common error is when your app Min Android SDK version is different than
the GFXReconstruct layer's Min Android SDK version.
You can correct this by updating the Min Android SDK version in one
AndroidManifest.xml or the other.

