# Third-Party Dependencies
This folder contains the third-party dependencies for the GFXReconstruct
project. Required dependencies are included as Git submodules, while
pre-compiled binaries for optional dependencies are provided for the
Windows and Android platforms.

## Required Dependencies
The following required dependencies are included here as submodules.  Refer
to the [BUILD.md](BUILD.md) documentation for information regarding
submodule initialization and update.

* Vulkan-Headers from https://github.com/KhronosGroup/Vulkan-Headers

## Optional Dependencies
Pre-compiled binaries for a limited set of platforms have been provided for
convenience.  The project's CMake configuration will automatically search
for the dependencies included within this folder by default, but the
configuration may be changed at CMake initialization to reference binaries
from any location.

### Version Information
The provided pre-compiled binaries were created from the following
software versions:

* LZ4 version 1.8.3 - https://github.com/lz4/lz4/releases/
* zlib version 1.2.11 from  http://zlib.net/

### Build Information
The provided pre-compiled binaries were created for the following
platforms:

* Windows x86 and x64 architectures created with Visual Studio 2017.
* Android armeabi-v7a and arm64-v8a architectures created with the clang compiler tool-chain targeting the android-24 platform.

Linux binaries for the optional dependencies are available for most Linux
distributions through the distribution's standard package manager.

## License Information
License information for the third-party dependencies contained within this
folder are listed in [LICENSE_ThirdParty.txt](../LICENSE_ThirdParty.txt)
