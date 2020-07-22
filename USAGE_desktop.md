<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->
<p align="left"><img src="https://vulkan.lunarg.com/img/NewLunarGLogoBlack.png" alt="LunarG" width=263 height=113 /></p>

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2018-2020 LunarG, Inc.

# GFXReconstruct API Capture and Replay

## **Desktop Version**

This document describes the GFXReconstruct software for capturing and replaying
Vulkan API calls on Desktop systems.

## Index

1. [Capturing API calls](#capturing-api-calls)
    1. [Enabling the Capture Layer](#enabling-the-capture-layer)
    2. [Capture Options](#capture-options)
    3. [Capture Files](#capture-files)
    4. [Capture Script](#capture-script)
2. [Replaying API Calls](#replaying-api-calls)
    1. [Command Line Arguments](#command-line-arguments)
    2. [Keyboard Controls](#keyboard-controls)
3. [Other Capture File Processing Tools](#other-capture-file-processing-tools)
    1. [Capture File Compression](#capture-file-compression)
    2. [Shader Extraction](#shader-extraction)
    3. [Capture File Info](#capture-file-info)
    4. [Command Launcher](#command-launcher)

## Capturing API calls

The GFXReconstruct capture layer is a Vulkan layer that intercepts Vulkan API
calls and logs them to a GFXReconstruct capture file.

### Enabling the Capture Layer

The path to the layer's `VkLayer_gfxreconstruct.json` file and
corresponding `VkLayer_gfxreconstruct` library must be added to
`VK_LAYER_PATH` environment variable for the Vulkan loader to find the layer.

After `VK_LAYER_PATH` has been updated, the layer may be enabled through
one of the following methods:

* Adding the `VK_LAYER_LUNARG_gfxreconstruct` name string to the
  `VkInstanceCreateInfo::ppEnabledLayerNames` value when calling
  `vkCreateInstance`
* Adding the `VK_LAYER_LUNARG_gfxreconstruct` name string to the list of
  layer names specified through the `VK_INSTANCE_LAYERS` environment variable

#### Setting VK_LAYER_PATH

The `VK_LAYER_PATH` environment variable can be used to tell the Vulkan
loader where to find the GFXReconstruct capture layer. If you are using
GFXReconstruct from a Vulkan SDK installation or a Linux package install,
there is no need to set VK_LAYER_PATH - the installation process will have
set up the GFXReconstruct capture layer so that the Vulkan loader can find
and load it.

##### Setting VK_LAYER_PATH for Windows

If you are not using GFXReconstruct from a Vulkan SDK, use the
following as an example of how to update the Windows `VK_LAYER_PATH`
environment variable for the GFXReconstruct capture layer. The example uses
the `C:\gfxreconstruct` path to represent the location of directory containing
the GFXReconstruct project source, and the `build` folder name to represent
the sub-directory specified to CMake as the location to place the build
binaries. The following command would be executed from the command prompt to
add the Debug build of the layer to `VK_LAYER_PATH`:

```bat
set VK_LAYER_PATH=C:\gfxreconstruct\build\layer\Debug;%VK_LAYER_PATH%
```

##### Setting VK_LAYER_PATH for Linux

If you are not using GFXReconstruct from the Vulkan SDK or a Linux package, use
the following as an example of how to update the Linux `VK_LAYER_PATH`
environment variable for the GFXReconstruct capture layer. The example uses
the `/gfxreconstruct` path to represent the location of directory containing
the GFXReconstruct project source, and the `build` folder name to represent
the sub-directory specified to CMake as the location to place the build
binaries. The following command would be executed from the command line to
add the layer to `VK_LAYER_PATH`:

```bash
export VK_LAYER_PATH=/gfxreconstruct/build/layer:$VK_LAYER_PATH
```

#### Enabling the layer with VK_INSTANCE_LAYERS

The `VK_INSTANCE_LAYERS` environment variable may be used so that the the
GFXReconstruct layer is loaded by the Vulkan loader.

##### Enabling the layer for Windows

The following command would be executed from the command prompt to set the
`VK_INSTANCE_LAYERS` environment variable:

```bat
set VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
```

##### Enabling the layer for Linux

The following command would be executed from the command line to set the
`VK_INSTANCE_LAYERS` environment variable:

```bash
export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
```

### Capture Options

The GFXReconstruct layer supports several options, which may be enabled
through environment variables or a layer settings file.

#### Windows Options

The following example demonstrates how to set the layer's log level to
"warning" from the Windows command prompt:

```bat
set GFXRECON_LOG_LEVEL=warning
```

#### Linux Options

The following example demonstrates how to set the layer's log level to
"warning" from the Linux command line:

```bash
export GFXRECON_LOG_LEVEL=warning
```

##### Supported Options

Options with the BOOL type accept the following values:

* A case-insensitive string value 'true' or a non-zero integer value indicate
  true.
* A case-insensitive string value 'false' or a zero integer value indicate
  false.

The capture layer will generate a warning message for unrecognized or invalid
option values.

Option | Environment Variable | Type | Description
------| ------------- |------|-------------
Capture File Name | GFXRECON_CAPTURE_FILE | STRING | Path to use when creating the capture file.  Default is: `gfxrecon_capture.gfxr`
Capture Specific Frames | GFXRECON_CAPTURE_FRAMES | STRING | Specify one or more comma-separated frame ranges to capture.  Each range will be written to its own file.  A frame range can be specified as a single value, to specify a single frame to capture, or as two hyphenated values, to specify the first and last frame to capture.  Frame ranges should be specified in ascending order and cannot overlap. Note that frame numbering is 1-based (i.e. the first frame is frame 1). Example: `200,301-305` will create two capture files, one containing a single frame and one containing five frames.  Default is: Empty string (all frames are captured).
Hotkey Capture Trigger | GFXRECON_CAPTURE_TRIGGER | STRING | Specify a hotkey (any one of F1-F12, TAB, CONTROL) that will be used to start/stop capture.  Example: `F3` will set the capture trigger to F3 hotkey. One capture file will be generated for each pair of start/stop hotkey presses. Default is: Empty string (hotkey capture trigger is disabled).
Capture File Compression Type | GFXRECON_CAPTURE_COMPRESSION_TYPE | STRING | Compression format to use with the capture file.  Valid values are: `LZ4`, `ZLIB`, `ZSTD`, and `NONE`. Default is: `LZ4`
Capture File Timestamp | GFXRECON_CAPTURE_FILE_TIMESTAMP | BOOL | Add a timestamp to the capture file as described by [Timestamps](#timestamps).  Default is: `true`
Capture File Flush After Write | GFXRECON_CAPTURE_FILE_FLUSH | BOOL | Flush output stream after each packet is written to the capture file.  Default is: `false`
Log Level | GFXRECON_LOG_LEVEL | STRING | Specify the highest level message to log.  Options are: `debug`, `info`, `warning`, `error`, and `fatal`.  The specified level and all levels listed after it will be enabled for logging.  For example, choosing the `warning` level will also enable the `error` and `fatal` levels. Default is: `info`
Log Output to Console | GFXRECON_LOG_OUTPUT_TO_CONSOLE | BOOL | Log messages will be written to stdout. Default is: `true`
Log File | GFXRECON_LOG_FILE | STRING | When set, log messages will be written to a file at the specified path. Default is: Empty string (file logging disabled).
Log Detailed | GFXRECON_LOG_DETAILED | BOOL | Include name and line number from the file responsible for the log message. Default is: `false`
Log Allow Indents | GFXRECON_LOG_ALLOW_INDENTS | BOOL | Apply additional indentation formatting to log messages. Default is: `false`
Log Break on Error | GFXRECON_LOG_BREAK_ON_ERROR | BOOL | Trigger a debug break when logging an error. Default is: `false`
Log File Create New | GFXRECON_LOG_FILE_CREATE_NEW | BOOL | Specifies that log file initialization should overwrite an existing file when true, or append to an existing file when false. Default is: `true`
Log File Flush After Write | GFXRECON_LOG_FILE_FLUSH_AFTER_WRITE | BOOL | Flush the log file to disk after each write when true. Default is: `false`
Log File Keep Open | GFXRECON_LOG_FILE_KEEP_OPEN | BOOL | Keep the log file open between log messages when true, or close and reopen the log file for each message when false. Default is: `true`
Log Output to Debug Console | GFXRECON_LOG_OUTPUT_TO_OS_DEBUG_STRING | BOOL | Windows only option.  Log messages will be written to the Debug Console with `OutputDebugStringA`. Default is: `false`
Memory Tracking Mode | GFXRECON_MEMORY_TRACKING_MODE | STRING | Specifies the memory tracking mode to use for detecting modifications to mapped Vulkan memory objects. Available options are: `page_guard`, `assisted`, and `unassisted`. Default is `page_guard` <ul><li>`page_guard` tracks modifications to individual memory pages, which are written to the capture file on calls to `vkFlushMappedMemoryRanges`, `vkUnmapMemory`, and `vkQueueSubmit`. Tracking modifications requires allocating shadow memory for all mapped memory.</li><li>`assisted` expects the application to call `vkFlushMappedMemoryRanges` after memory is modified; the memory ranges specified to the `vkFlushMappedMemoryRanges` call will be written to the capture file during the call.</li><li>`unassisted` writes the full content of mapped memory to the capture file on calls to `vkUnmapMemory` and `vkQueueSubmit`. It is very inefficient and may be unusable with real-world applications that map large amounts of memory.</li></ul>
Page Guard Copy on Map | GFXRECON_PAGE_GUARD_COPY_ON_MAP | BOOL | When the `page_guard` memory tracking mode is enabled, copies the content of the mapped memory to the shadow memory immediately after the memory is mapped. Default is: `true`
Page Guard Separate Read Tracking | GFXRECON_PAGE_GUARD_SEPARATE_READ | BOOL | When the `page_guard` memory tracking mode is enabled, copies the content of pages accessed for read from mapped memory to shadow memory on each read. Can overwrite unprocessed shadow memory content when an application is reading from and writing to the same page. Default is: `true`
Page Guard External Memory | GFXRECON_PAGE_GUARD_EXTERNAL_MEMORY | BOOL | When the `page_guard` memory tracking mode is enabled, use the VK_EXT_external_memory_host extension to eliminate the need for shadow memory allocations. For each memory allocation from a host visible memory type, the capture layer will create an allocation from system memory, which it can monitor for write access, and provide that allocation to vkAllocateMemory as external memory. Only available on Windows. Default is `false`

#### Settings File

Capture options may also be specified through a layer settings file.  The layer
settings file will be loaded before the environment variables are processed,
allowing environment variables to override individual settings file entries.

The `VK_LAYER_SETTINGS_PATH` environment variable is used to enable a
settings file. The environment variable may be set as either the path to the
folder containing a file named `vk_layer_settings.txt` or the full path to a
file with a custom name. When set to a folder, the capture layer will try to
open a file in that folder named `vk_layer_settings.txt`.  When set to a file,
the capture layer will try to open a file with the specified name.

The settings file may be combined with settings files for other layers. The
capture layer will ignore entries that do not start with the
'lunarg_gfxreconstruct.' prefix.

A sample layer settings file, documenting each available setting, can be found
in the GFXReconstruct GitHub repository at `layer/vk_layer_settings.txt`. Most
binary distributions of the GFXReconstruct software will also include a sample
settings file.

### Capture Files

Capture files are created on the first call to `vkCreateInstance`, when the
Vulkan loader loads the capture layer, and are closed on `vkDestroyInstance`,
when the last active instance is destroyed and the layer is unloaded.

If multiple instances are active concurrently, only one capture file will be
created. If multiple instances are active consecutively (i.e. an instance is
created and destroyed before the next instance is created), the creation of
each instance will generate a new file. For applications that create multiple
instances consecutively, it will be necessary to enable capture file timestamps
to prevent each new instance from overwriting the file created by the previous
instance.

If the layer fails to open the capture file, it will make the call to
`vkCreateInstance` fail, returning `VK_ERROR_INITIALIZATION_FAILED`.

#### Specifying Capture File Location

The capture file's save location can be specified by setting the
`GFXRECON_CAPTURE_FILE` environment variable, described above in
the [Layer Options](#layer-options) section.

#### Timestamps

When capture file timestamps are enabled, a timestamp with an
[ISO 8601-based](https://en.wikipedia.org/wiki/ISO_8601)
format will be added to the name of every file created by the layer. The
timestamp is generated when the capture file is created by the layer's
`vkCreateInstance` function and is added to the base filename specified
through the `GFXRECON_CAPTURE_FILE` environment variable. Timestamps have
the form:

```text
_yyyymmddThhmmss
```

where the lower-case letters stand for: Year, Month, Day, Hours, Minutes,
Seconds.  The `T` is a designator that separates the date and time components.
Time is reported for the local timezone and is specified with the 24-hour
format.

The following example shows a timestamp that was added to a file that was
originally named `gfxrecon_capture.gfxr` and was created at 2:35 PM
on November 25, 2018:
  `gfxrecon_capture_20181125T143527.gfxr`

### Capture Script

The `gfxrecon-capture.py` tool is a convenience script that can be used to
start a capture and specify the capture options using a single command.

```text
usage: gfxrecon-capture.py [-h]
                           [-w dir]
                           [-o captureFile]
                           [-f captureFrames]
                           [--no-file-timestamp]
                           [--trigger {F1-F12,TAB,CTRL}]
                           [--compression-type {LZ4,ZLIB,ZSTD,NONE}]
                           [--file-flush]
                           [--log-level {debug,info,warn,error,fatal}]
                           [--log-file <file>]
                           [--memory-tracking-mode {page_guard,assisted,unassisted}]
                           <program> [<programArgs>]

Create a capture of a Vulkan program.

positional arguments:
  <program> [<program args>]
                        Program to capture, optionally followed by program
                        arguments

optional arguments:
  -h, --help            show this help message and exit
  -w <dir>, --working-dir <dir>
                        Set CWD to this directory before running the program
  -o <captureFile>, --capture-file <captureFile>
                        Name of the capture file, default is
                        gfxrecon_capture.gfxr
  -f <captureFrames>, --capture-frames <captureFrames>
                        List of frames to capture, default is all frames
  --no-file-timestamp   Do not add a timestamp to the capture file name
  --trigger {F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,TAB,CTRL}
                        Specify a hotkey to start/stop capture
  --compression-type {LZ4,ZLIB,ZSTD,NONE}
                        Specify the type of compression to use in the capture
                        file, default is LZ4
  --file-flush          Flush output stream after each packet is written to
                        capture file
  --log-level {debug,info,warn,error,fatal}
                        Specify highest level message to log, default is info
  --log-file logFile    Name of the log file (disable logging with empty
                        string), default is stdout/stderr
  --memory-tracking-mode {page_guard,assisted,unassisted}
                        Method to use to track changes to memory mapped objects:
                           page_guard: use guard pages to track changes (default)
                           assisted:   application will call vkFlushMappedMemoryRanges
                                       for memory to be written to the capture file
                           unassisted: all mapped memory will be written to the
                                       capture file during VkQueueSubmit and VkUnmapMemory
```

Most of the options for `gfxrecon-capture.py` result in the script setting the
appropriate capture layer environment variable, then invoking the program to
be captured. Environment variables not set by `gfxrecon-capture.py` can be set
manually before running `gfxrecon-capture.py` and they will be detected by the
capture layer.

The `gfxrecon-capture.py` tool is a Python3 script. In order to use it, a
Python3 interpreter must first be installed. Once Python3 is installed, you should
be able to invoke `gfxrecon-capture.py` by simply typing:

```bash
gfxrecon-capture.py -o vkcube.gfxr vkcube
```

On Windows, after installing Python3, be sure to associate the `.py` file extension with
the Python3 interpreter before you run the script.



## Replaying API Calls

The GFXReconstruct Replay tool, `gfxrecon-replay`, can be used to replay
files captured with or generated by other GFXReconstruct components.

### Command Line Arguments

The `gfxrecon-replay` tool for desktop accepts the following command line
arguments:

```text
gfxrecon-replay         [--version] [--gpu <index>] [--pause-frame <N>]
                        [--paused] [--sfa | --skip-failed-allocations]
                        [--replace-shaders <dir>]
                        [--opcd | --omit-pipeline-cache-data] [--wsi <platform>]
                        [-m <mode> | --memory-translation <mode>] <file>

Required arguments:
  <file>                Path to the capture file to replay.

Optional arguments:
  --version             Print version information and exit.
  --gpu <index>         Use the specified device for replay, where index
                        is the zero-based index to the array of physical devices
                        returned by vkEnumeratePhysicalDevices.  Replay may fail
                        if the specified device is not compatible with the
                        original capture devices.
  --pause-frame <N>     Pause after replaying frame number N.
  --paused              Pause after replaying the first frame (same
                        as --pause-frame 1).
  --sfa                 Skip vkAllocateMemory, vkAllocateCommandBuffers, and
                        vkAllocateDescriptorSets calls that failed during
                        capture (same as --skip-failed-allocations).
  --replace-shaders <dir> Replace the shader code in each CreateShaderModule
                        with the contents of the file <dir>/sh<handle_id> if
                        found, where <handle_id> is the handle id of the
                        vkCreateShaderModule call. Also see gfxrecon-extract.
  --opcd                Omit pipeline cache data from calls to
                        vkCreatePipelineCache (same as --omit-pipeline-cache-data).
  --wsi <platform>      Force replay to use the specified wsi platform.
                        Available platforms are: auto,win32,xcb,wayland
  -m <mode>             Enable memory translation for replay on GPUs with memory
                        types that are not compatible with the capture GPU's
                        memory types.  Available modes are:
                            none        No memory translation is performed.  This
                                        is the default behavior.
                            remap       Attempt to map capture memory types to
                                        compatible replay memory types, without
                                        altering memory allocation behavior.
                            realign     Adjust memory allocation sizes and
                                        resource binding offests based on
                                        replay memory properties.
                            rebind      Change memory allocation behavior based
                                        on resource usage and replay memory
                                        properties.  Resources may be bound
                                        to different allocations with different
                                        offsets.  Uses VMA to manage allocations
                                        and suballocations.
```

### Keyboard Controls

The `gfxrecon-replay` tool for Desktop supports the following key controls:

Key(s) | Action
-------|-------
Space, p | Toggle pause/play.
Right arrow, n | Advance to the next frame when paused.

## Other Capture File Processing Tools

### Capture File Compression

The `gfxrecon-compress` tool compresses or decompresses GFXReconstruct
capture files. It can also be used to change the compression format used
in a capture file.

```text
gfxrecon-compress - A tool to compress/decompress GFXReconstruct capture files.

Usage:
  gfxrecon-compress [--version] <input_file> <output_file> <compression_format>

Required arguments:
  <input_file>    Path to the input file to process.
  <output_file>   Path to the output file to generate.
  <compression_format>  Compression format to apply to the output file.
                        Options are:
                          LZ4  - Use LZ4 compression.
                          ZLIB - Use zlib compression.
                          ZSTD - Use Zstandard compression.
                          NONE - Remove compression.

Optional arguments:
  --version       Print version information and exit
```

### Shader Extraction

The `gfxrecon-extract` tool extracts all shaders in a GFXReconstruct capture
file. The extracted shaders are placed into a specified directory.

```text
gfxrecon-extract - Extract shaders from a GFXReconstruct capture file.

Usage:
  gfxrecon-extract [--dir <dir>] <file>

Optional arguments:
  --dir <dir> Place extracted shaders into directory <dir>. Otherwise
              use <file>.shaders in working directory. Create directory
              if necessary. Each shader is placed in individual file
              named sh<handle_id> where handle_id is handle id of the
              CreateShaderModule call. See gfxrecon-replay --replace-shaders.
Required arguments:
  <file>      The GFXReconstruct capture file to be processed.
```

### Capture File Info

The `gfxrecon-info` tool prints statistics for a GFXReconstruct capture file, including
information about the application,
the physical device , device memory allocation, and device pipelines.

```text
gfxrecon-info - Print statistics for a GFXReconstruct capture file.

Usage:
  gfxrecon-info [--version] <file>

Required arguments:
  <file>      The GFXReconstruct capture file to be processed.

Optional arguments:
  --version   Print version information and exit.
```

### Command Launcher

The `gfxrecon.py` tool is a utility that can be used to launch all of the
GFXReconstruct commands.

```text
usage: gfxrecon.py [-h] command ...

GFXReconstruct utility launcher.

positional arguments:
  command     Command to execute. Valid options are [capture, compress,
              extract, info, replay]
  args        Command-specific argument list. Specify -h after command name
              for command help.

optional arguments:
  -h, --help  show this help message and exit
```

The `gfxrecon.py` tool is a Python3 script. In order to use it, a
Python3 interpreter must first be installed. Once Python3 is installed, you should
be able to invoke `gfxrecon.py` by simply typing:

```bash
gfxrecon.py capture -o vkcube.gfxr vkcube
```

On Windows, after installing Python3, be sure to associate the `.py` file extension with
the Python3 interpreter before you run the script.
