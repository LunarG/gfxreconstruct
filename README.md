# Project Goals

The primary goal for the GFXReconstruct project is to create an improved
version of LunarG's [vktrace](https://github.com/LunarG/VulkanTools)
software for capture and replay of Vulkan API calls. As development
progresses, existing vktrace functionality such as trimming and
client-server mode will be integrated with the GFXReconstruct codebase.
When GFXReconstruct reaches feature parity with vktrace, vktrace will
be deprecated in favor of GFXReconstruct.

The initial focus of this effort was to improve the code generation process
responsible for generating the Vulkan API call encoding and decoding code,
to address some code maintenance and Vulkan API version update issues present
with the existing vktrace software. It has also offered an opportunity to
explore potential performance and feature enhancements, such as compression
for capture files (currently available) and support for multi-threaded replay
(to be added in the future).

## Stability

The GFXReconstruct project is currently Beta quality software.  The primary
consideration for stability is the capture file format.  While this format
does not change regularly, it is not yet finalized and may change in ways
that are incompatible with the existing format as new features (eg.
multi-threaded replay and trimming) are implemented.  Once these features
are implemented and considered stable, the file format will be assigned a
1.0 version, at which point backward compatibility will be guaranteed across
GFXReconstruct versions.

# Project Components

The GFXReconstruct project provides tools for the capture and replay of Vulkan
API calls, allowing the graphics commands executed by a Vulkan application to
be recorded to a file that may later be replayed to reconstruct the
graphics-specific behavior of the captured application. The replay code has
been organized with a framework design to make it easy to create additional
tools for processing capture files. Although the software is currently
exclusive to the Vulkan API, it has been designed such that support for
additional graphics APIs is possible.

The GFXReconstruct components currently provided with this repository are:

* The `VK_LAYER_LUNARG_gfxreconstruct` Vulkan layer for capturing
   Vulkan application commands.
* The `gfxrecon-replay` tool to replay GFXReconstruct capture files.
* The `gfxrecon-info` tool to print information describing GFXReconstruct
  capture files.
* The `gfxrecon-compress` tool to compress/decompress GFXReconstruct
  capture files.
  * **NOTE:** The gfxrecon-compress tool requires LZ4, Zstandard, and/or
    zlib, which are currently optional build dependencies.
* The `gfxrecon-extract` tool to extract SPIR-V binaries from
  GFXReconstruct capture files.
* The `gfxrecon-toascii` tool to convert GFXReconstruct capture files to
  an ASCII listing of API calls.



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

* [Desktop Usage](USAGE_desktop.md)
* [Android Usage](USAGE_android.md)

## License

This work is licensed under the Apache License, Version 2.0; see
[LICENSE](LICENSE.txt) for more information.
