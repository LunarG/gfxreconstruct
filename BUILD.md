# Build Instructions

Instructions for building this repository on Linux, Windows, and Android


## Index

1. [Contributing](#contributing-to-the-repository)
1. [Repository Content](#repository-content)
1. [Repository Set-Up](#repository-set-up)
1. [Windows Build](#building-on-windows)
1. [Linux Build](#building-on-linux)
1. [Android Build](#building-on-android)


## Contributing to the Repository

If you intend to contribute, the preferred work flow is for you to develop
your contribution in a fork of this repository in your GitHub account and then
submit a pull request.
Please see the [CONTRIBUTING.md](CONTRIBUTING.md) file in this repository for
more details.


## Repository Content

This repository contains the source code necessary to build the LunarG
Brimstone layer and applications.
The folders contain the following content:

| Top Folder  | Sub-Folder | Description  |
|---|---|---|
| android  | | Android utilities and files necessary to build the content of this repo for Android. |
| cmake    | | CMake utility files for assisting in the build process. |
| external | | Additional source repositories pulled into this repository as sub-modules. |
| framework | | Top-level folder containing framework files for this repository.|
| | application | Application framework files for abstracting key information away from the main application code. |
| | decode | Various functionality to assist in decoding the content of an application.  This is typically used by replay consumers. |
| | encode | Various functionality to assist in the encoding of content for an application.  This is typically used by the Brimstone layer. |
| | format | Functionality used to define the various formats and containers for the basic bits of functionality. |
| | generated | Generated source files and generator scripts (in Python) used to assist in the encode and decode of supported APIs. |
| | util | General utility functionality to assist in platform portability. |
| layer | | Contains the code that produces the Brimstone Vulkan layer used to capture Vulkan commands. |
| tools | | Top-level folder containing the application tools for this repository. |
| | compress | A tool used to compress or uncompress Brimstone binary files. |
| | replay | A tool used to replay commands in a Brimstone binary file. |
| | toascii | A tool used to dump out the contents of the commands in a Brimstone binary file as ascii content. |


## Repository Set-Up

### Display Drivers

This repository does not contain a Vulkan-capable driver.
You will need to obtain and install a Vulkan driver from your graphics
hardware vendor or from some other suitable source if you intend to run
Vulkan applications.

### Download the Repository

To create your local git repository:

    git clone https://github.com/LunarG/brimstone.git

### Repository Dependencies

This repository has dependencies on the
[Volk](https://github.com/zeux/volk) and
[Vulkan-Headers](https://github.com/KhronosGroup/Vulkan-Headers)
repositories.
Both of these repositories are added to the project as Git Submodules.

Once the repository has been cloned, you must enter the brimstone
source directory you create and pull down the submodule information using
the following command:

```
git submodule update --init --recursive
```

Once this has been done, you should have the latest source.
However, occasionally the submodules will be updated and you will need to
update the submodules using the following command:

```
git submodule update --init --recursive
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

    cd brimstone
    mkdir build
    cmake -H. -Bbuild -A x64

The `-A` option is used to select either the "Win32" or "x64" architecture.

If a generator for a specific version of Visual Studio is required, you can
specify it for Visual Studio 2015, for example, with:

    64-bit: -G "Visual Studio 14 2015 Win64"
    32-bit: -G "Visual Studio 14 2015"

The above steps create a Windows solution file named
`brimstone.sln` in the build directory.

At this point, you can build the solution from the command line or open the
generated solution with Visual Studio.

#### Build the Solution From the Command Line

While still in the build directory:

    cmake --build .

to build the Debug configuration (the default), or:

    cmake --build . --config Release

to make a Release build.

#### Build the Solution With Visual Studio

Launch Visual Studio and open the "brimstone.sln" solution file
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

    sudo apt-get install git cmake build-essential libx11-xcb-dev \
        libxkbcommon-dev libwayland-dev libxrandr-dev

### Linux Build

The general approach is to run CMake to generate make files. Then either run
CMake with the `--build` option or `make` to build from the command line.


#### Use CMake to Create the Make Files

Change your current directory to the top of the cloned repository directory,
create a build directory and generate the make files.

    cd brimstone
    mkdir build
    cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug

Use `-DCMAKE_BUILD_TYPE` to specify a Debug or Release build.

#### Build the Project

You can just run `make` to begin the build.

To speed up the build on a multi-core machine, use the `-j` option for `make`
to specify the number of cores to use for the build. For example:

    make -j4

You can also use

    cmake --build .

If your build system supports ccache, you can enable that via CMake option `-DUSE_CCACHE=On`


## Building On Android

Install the required tools for Linux and Windows covered above, then add the
following.

**TBD** 
