# EXPERIMENTAL BRANCH!!!

** WARNING!! **

This is an experimental branch working to add OpenXR support to GFXReconstruct.
The OpenXR capture API layer is not yet implemented and is still in progress.

Use this branch at your own risk!

** WARNING!! **

# Project Components

The GFXReconstruct project provides tools for the capture and replay of graphics 
API calls, allowing the graphics commands executed by an application
to be recorded to a file that may later be replayed to reconstruct the
graphics-specific behavior of the captured application. The replay code has
been organized with a framework design to make it easy to create additional
tools for processing capture files. 

The GFXReconstruct components currently provided with this repository are:

* The `VK_LAYER_LUNARG_gfxreconstruct` Vulkan layer for capturing
   Vulkan application commands.
* The D3D12 capture libraries for capturing D3D12 application commands.
* The `gfxrecon-replay` tool to replay GFXReconstruct capture files.
* The `gfxrecon-info` tool to print information describing GFXReconstruct
  capture files.
* The `gfxrecon-compress` tool to compress/decompress GFXReconstruct
  capture files.
  * **NOTE:** The gfxrecon-compress tool requires LZ4, Zstandard, and/or
    zlib, which are currently optional build dependencies.
* The `gfxrecon-extract` tool to extract SPIR-V binaries from
  GFXReconstruct capture files.
* The `gfxrecon-convert` tool to convert GFXReconstruct capture files to
  a [JSON Lines](https://jsonlines.org/) listing of API calls. (experimental
  for D3D12 captures)
* The `gfxrecon-optimize` tool to produce new capture files with 
  improved replay performance.



## Contributing

If you intend to contribute, the preferred work flow is for you to develop
your contribution in a fork of this repo in your GitHub account and then
submit a pull request.
Please see the [CONTRIBUTING](CONTRIBUTING.md) file in this repository for
more details

## Building

Instructions for building the contents of this repository can be found in
the [BUILD.md](BUILD.md) documentation.

## Usage

Instructions for using the GFXReconstruct capture and replay tools can be
found at the following locations:

* [Desktop Usage - Vulkan](USAGE_desktop_Vulkan.md)
* [Desktop Usage - D3D12](USAGE_desktop_D3D12.md)
* [Android Usage](USAGE_android.md)

## License

This work is licensed under the terms of the MIT License; see
[LICENSE](LICENSE.txt) for more information.

## Appropriate Use

GFXReconstruct is a suite of tools intended for the purpose of
improving application and platform quality by allowing the analysis
of capture and replay of graphics command streams.  Use cases
include, for example, regression testing, silicon and platform
bringup, and reporting bugs.  Using GFXReconstruct to extract assets
from an application or game for which you don’t have an appropriate
license may violate copyrights or software licenses.
