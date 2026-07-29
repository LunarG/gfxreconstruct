# Third-Party Dependencies
This folder contains the third-party dependencies for the GFXReconstruct
project. Required dependencies are included as Git submodules, the compression
libraries are built from pinned upstream sources at build time, and a small set
of pre-compiled binaries remains for dependencies that cannot be built from
source.

## Required Dependencies
The following required dependencies are included here as submodules.  Refer
to the [BUILD.md](BUILD.md) documentation for information regarding
submodule initialization and update.

* Vulkan-Headers from https://github.com/KhronosGroup/Vulkan-Headers

## Compression Libraries
LZ4, Zstandard, and zlib are fetched and built from source by CMake, so they
are not stored in this folder.  The upstream repository and the exact revision
used for each library are pinned in
[cmake/CompressionDependencies.cmake](../cmake/CompressionDependencies.cmake),
which is the single place to change when updating a library.  The versions
currently pinned are:

* LZ4 version 1.10.0 from https://github.com/lz4/lz4
* Zstandard version 1.5.7 from https://github.com/facebook/zstd
* zlib version 1.3.2 from https://github.com/madler/zlib

Fetching the sources requires network access when CMake is run.  Building
against libraries already installed on the system instead, which is what Linux
distribution packagers and air-gapped builds generally want, is described in
[BUILD.md](../BUILD.md).

On Android, zlib is provided by the NDK as a platform library and is used from
there rather than being built from source.

## Pre-Compiled Binaries
Pre-compiled binaries are provided for the following dependencies, which cannot
be produced by the CMake build:

* `win32`, `win64`, `win64-arm`: Detours, used for the D3D12 capture layer.
* `win32`: AMD AGS, retained for reference; the build fetches the AGS SDK
  directly (see [cmake/FindAGS.cmake](../cmake/FindAGS.cmake)).
* `win64-arm`: LZ4, Zstandard, and zlib built as ARM64X.  These are produced by
  building each library twice, once as ARM64 and once as ARM64EC, and splicing
  the results together with `link.exe /lib /machine:arm64x`.  CMake cannot
  express that, so Windows on ARM builds continue to link these binaries.
  [win64-arm/lib/README.txt](precompiled/win64-arm/lib/README.txt) documents how
  they were produced and must be followed when they are updated.

## License Information
License information for the third-party dependencies contained within this
folder are listed in [LICENSE_ThirdParty.txt](../LICENSE_ThirdParty.txt)
