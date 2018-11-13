# Brimstone Components

This project provides the Brimstone components which include
the necessary tools to capture and replay commands from various
APIs.
The current list of supported APIs are:
 * Vulkan
 
There are several items that are found and built within this repository:

 * A Vulkan Layer for capturing Vulkan commands
 * A brimstone replay tool which can replay brimstone binary capture files.
 * A brimstone compress tool which can change the compression of brimstone binary capture files.
   * The compress tool can both compress and decompress these files
 * A brimstone ascii dumper tool to output the contents of the commands in a brimstone binary capture file.


## Contributing

If you intend to contribute, the preferred work flow is for you to develop your contribution
in a fork of this repo in your GitHub account and then submit a pull request.
Please see the [CONTRIBUTING](CONTRIBUTING.md) file in this repository for more details


## How to Build and Run

[BUILD.md](BUILD.md)
includes directions for building all the components.


## License
This work is released as open source under a Apache-style license from Khronos including a Khronos copyright.

See COPYRIGHT.txt for a full list of licenses used in this repository.

## Acknowledgements
While this project has been developed primarily by LunarG, Inc., 
Valve Corporation, has provided the funding behind this project's development
