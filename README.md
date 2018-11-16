# GFXReconstruct Components

This project contains the GFXReconstruct components which include
the necessary tools to capture and replay commands from various
APIs.

The current list of supported APIs are:
 * Vulkan
 
There are several items that can be found and built within this repository:

 * The `VK_LAYER_LUNARG_gfxreconstruct` Vulkan Layer that is used to capture
   Vulkan application commands
 * The `gfxrecon-replay` tool which can replay GFXReconstruct capture files.
 * The `gfxrecon-compress` tool which can change the compression of
   GFXReconstruct capture files.
   * **NOTE:** The gfxrecon-compress tool can both compress and decompress
     these files but requires either LZ4 or LZ11 to be installed.
 * The `gfxrecon-toascii` tool to output the contents of the commands in a
   GFXReconstruct capture file.


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

Information for using the various components of the GFXReconstruct project
can be found in the following places:

* [Using the Vulkan Layer](layer/README.md)
* [Using the GFXReconstruct Replay tool](tools/replay/README.md)


## License

This work is released as open source under a Apache-style license from
Khronos including a Khronos copyright.

See COPYRIGHT.txt for a full list of licenses used in this repository.


## Acknowledgements
While this project has been developed primarily by LunarG, Inc., 
Valve Corporation, has provided the funding behind this project's development
