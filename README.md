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

## Experimental OpenXR Support

OpenXR support in GFXReconstruct is experimental and is recommended only for
developer use for evaluation!
Only a subset of features and a very small number of apps are supported.
See [USAGE_desktop_OpenXR](USAGE_desktop_OpenXR.md) and the
"Supported Capabilities" table below for more detail.

Because OpenXR support is considered a Proof-of-Concept, it is not enabled
in the SDK built version of GFXReconstruct.
If OpenXR support is desired, please pull the source down from the
GitHub repo and build manually.

## Contributing

If you intend to contribute, the preferred work flow is for you to develop
your contribution in a fork of this repo in your GitHub account and then
submit a pull request.
Please see the [CONTRIBUTING](CONTRIBUTING.md) file in this repository for
more details

## Supported Capabilities

| Capability     |   Windows  |  Linux  |  Mac  |   Android   |  Meta Quest |
| -------------- | :--------: | :-----: | :-------: | :-----: | :---------: |
| **Vulkan Support** ||||||
| Capture | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :construction:  |
| Replay  | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :construction:  |
| gfxrecon-compress | :white_check_mark: | :white_check_mark: | :white_check_mark: | :large_orange_diamond: | :large_orange_diamond: |
| gfxrecon-convert | :white_check_mark: | :white_check_mark: | :white_check_mark: | :large_orange_diamond: | :large_orange_diamond: |
| gfxrecon-info | :white_check_mark: | :white_check_mark: | :white_check_mark: | :large_orange_diamond: | :large_orange_diamond: |
| gfxrecon-optimize | :white_check_mark: | :white_check_mark: | :white_check_mark: | :large_orange_diamond: | :x: |
| gfxrecon-tocpp | :x: | :construction: | :x: | :construction:  | :x: |
| **D3D12 Support** ||||||
| Capture  | :white_check_mark: | :x: | :x: | :x: | :x: |
| Replay   | :white_check_mark: | :x: | :x: | :x: | :x: |
| gfxrecon-compress | :white_check_mark: | :x: | :x: | :x: | :x: |
| gfxrecon-convert | :white_check_mark: | :x: | :x: | :x: | :x: |
| gfxrecon-info | :white_check_mark: | :x: | :x: | :x: | :x: |
| gfxrecon-optimize | :white_check_mark: | :x: | :x: | :x: | :x: |
| **OpenXR (Vulkan Graphics API only)** ||||||
| Capture | :construction: | :construction: | :x: | :construction: | :construction:  |
| Replay  | :construction: | :construction: | :x: | :construction: | :construction:  |
| gfxrecon-compress | :construction: | :construction: | :x: | :large_orange_diamond: | :large_orange_diamond: |
| gfxrecon-convert | :construction: | :construction: | :x: | :large_orange_diamond: | :large_orange_diamond:  |
| gfxrecon-info | :construction: | :construction: | :x: | :large_orange_diamond: | :large_orange_diamond:  |
| gfxrecon-optimize | :x: | :x: | :x: | :x: | :x: |
| gfxrecon-tocpp | :x: | :x: | :x: | :x:  | :x: |

**Legend**
* :white_check_mark: : Supported
* :x: : Not Supported
* :large_orange_diamond: : Not supported on Android/Meta Quest, but Desktop tools support modifying the resulting captures
* :construction: : Early Preview / Alpha / Beta

### Cross-Platform Capture/Replay Support

The table above only represents replay on the same platform and driver
version on which the file was captured.

It is possible in some circumstances to replay on one operating system a
trace that was captured on another operating system.
However this is not currently supported unless specified.

For example, a Windows capture may replay on Linux, and vice versa,
if:
  * Certain settings are forced in the replay application
     * Overriding the windowing system used
     * Disabling unknown extensions
     * Rebinding memory
  * Compability libraries are enabled to expose operating system behavior
     * Such as Wine.


## Building

Instructions for building the contents of this repository can be found in
the [BUILD.md](BUILD.md) documentation.

## Usage

Instructions for using the GFXReconstruct capture and replay tools can be
found at the following locations:

* [Desktop Usage - Vulkan](USAGE_desktop_Vulkan.md)
* [Desktop Usage - D3D12](USAGE_desktop_D3D12.md)
* [Android Usage](USAGE_android.md)

## Testing

In addition to unit tests, there are several [test apps](TESTING_test_apps.md) included that can 
be used to verify GFXReconstruct output.  These test apps execute small graphics workloads which
result in small, known .gfxr outputs.

## License

This work is licensed under the terms of the MIT License; see
[LICENSE](LICENSE.txt) for more information.

## Appropriate Use

GFXReconstruct is a suite of tools intended for the purpose of
improving application and platform quality by allowing the analysis
of capture and replay of graphics command streams. Use cases
include, for example, regression testing, silicon and platform
bringup, and reporting bugs. Using GFXReconstruct to extract assets
from an application or game for which you don’t have an appropriate
license may violate copyrights or software licenses.
