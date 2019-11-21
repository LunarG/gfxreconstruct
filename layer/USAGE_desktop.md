# Using the GFXReconstruct Layer on the Desktop

## Enabling the GFXReconstruct Capture Layer
The path to the layer's `VK_LAYER_LUNARG_gfxreconstruct.json` file and
corresponding `VkLayer_gfxreconstruct` library must be added to
`VK_LAYER_PATH` environment variable for the Vulkan loader to find the layer.

After `VK_LAYER_PATH` has been updated, the layer may be enabled through
one of the following methods:
  * Adding the `VK_LAYER_LUNARG_gfxreconstruct` name string to the `VkInstanceCreateInfo::ppEnabledLayerNames` value when calling `vkCreateInstance`
  * Adding the `VK_LAYER_LUNARG_gfxreconstruct` name string to the list of layer names specified through the `VK_INSTANCE_LAYERS` environment variable.

### Setting VK_LAYER_PATH
The `VK_LAYER_PATH` environment variable should be used to tell the Vulkan
loader where to find the GFXReconstruct layer.

#### Windows
The following example demonstrates how to update the Windows `VK_LAYER_PATH`
environment variable for the GFXReconstruct capture layer. The example uses
the `C:\gfxreconstruct` path to represent the location of directory containing
the GFXReconstruct project source, and the `build` folder name to represent
the sub-directory specified to CMake as the location to place the build
binaries. The following command would be executed from the command prompt to
add the Debug build of the layer to `VK_LAYER_PATH`:
```
set VK_LAYER_PATH=C:\gfxreconstruct\build\layer\Debug;%VK_LAYER_PATH%
```

#### Linux
The following example demonstrates how to update the Windows `VK_LAYER_PATH`
environment variable for the GFXReconstruct capture layer. The example uses
the `/gfxreconstruct` path to represent the location of directory containing
the GFXReconstruct project source, and the `build` folder name to represent
the sub-directory specified to CMake as the location to place the build
binaries. The following command would be executed from the command line to
add the layer to `VK_LAYER_PATH`:
```
export VK_LAYER_PATH=/gfxreconstruct/build/layer:$VK_LAYER_PATH
```

### Enabling the layer with VK_INSTANCE_LAYERS
The `VK_INSTANCE_LAYERS` environment variable may be used to force the Vulkan
loader to load the GFXReconstruct layer.

#### Windows
The following command would be executed from the command prompt to set the
`VK_INSTANCE_LAYERS` environment variable:
```
set VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
```

#### Linux
The following command would be executed from the command line to set the
`VK_INSTANCE_LAYERS` environment variable:
```
export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
```

## Layer Options
The GFXReconstruct layer supports the following options, which may be enabled
with environment variables.  Each environment variable begins with the prefix
`GFXRECON_`.

#### Windows
The following example demonstrates how to set the layer's log level to
"warning" from the Windows command prompt:
```
set GFXRECON_LOG_LEVEL=warning
```

#### Linux
The following example demonstrates how to set the layer's log level to
"warning" from the Linux command line:
```
export GFXRECON_LOG_LEVEL=warning
```

### Supported Options
Options with the BOOL type accept the following values:
* A case-insensitive string value 'true' or a non-zero integer value indicate true.
* A case-insensitive string value 'false' or a zero integer value indicate false.

The capture layer will generate a warning message for unrecognized or invalid
option values.

Option | Environment Variable | Type | Description
------| ------------- |------|-------------
Capture File Name | GFXRECON_CAPTURE_FILE | STRING | Path to use when creating the capture file.  Default is: `gfxrecon_capture.gfxr`
Capture Specific Frames | GFXRECON_CAPTURE_FRAMES | STRING | Specify one or more comma-separated frame ranges to capture.  Each range will be written to its own file.  A frame range can be specified as a single value, to specify a single frame to capture, or as two hyphenated values, to specify the first and last frame to capture.  Frame ranges should be specified in ascending order and cannot overlap.  Example: `200,301-305` will create two capture files, one containing a single frame and one containing five frames.  Default is: Empty string (all frames are captured).
Capture File Compression Type | GFXRECON_CAPTURE_COMPRESSION_TYPE | STRING | Compression format to use with the capture file.  Valid values are: `LZ4`, `ZLIB`, and `NONE`. Default is: `LZ4`
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
Memory Tracking Mode | GFXRECON_MEMORY_TRACKING_MODE | STRING | Specifies the memory tracking mode to use for detecting modifications to mapped Vulkan memory objects. Available options are: `page_guard`, `assisted`, and `unassisted`. Default is `page_guard` <ul><li>`page_guard` tracks modifications to individual memory pages, which are written to the capture file on calls to `vkFlushMappedMemoryRanges`, `vkUnmapMemory`, and `vkQueueSubmit`. Tracking modifications requires allocating shadow memory for all mapped memory.</li><li>`assisted` expects the application to call `vkFlushMappedMemoryRanges` after memory is modified; the memory ranges specified to the `vkFlushMappedMemoryRanges` call will be written to the capture file during the call.</li><li>`unassisted` writes the full content of mapped memory to the capture file on calls to `vkUnmapMemory` and `vkQueueSubmit`. It is very inefficient and may be unusable with real world applications that map large amounts of memory.</li></ul>
Page Guard Copy on Map | GFXRECON_PAGE_GUARD_COPY_ON_MAP | BOOL | When the `page_guard` memory tracking mode is enabled, copies the content of the mapped memory to the shadow memory immediately after the memory is mapped. Default is: `true`
Page Guard Lazy Copy | GFXRECON_PAGE_GUARD_LAZY_COPY | BOOL | When the `page_guard` memory tracking mode is enabled, changes the copy on map behavior such that the copy is performed for individual memory pages on first access after map. Default is: `false`
Page Guard Separate Read Tracking | GFXRECON_PAGE_GUARD_SEPARATE_READ | BOOL | When the `page_guard` memory tracking mode is enabled, copies the content of pages accessed for read from mapped memory to shadow memory on each read. Can overwrite unprocessed shadow memory content when an application is reading from and writing to the same page. Default is: `true`
Page Guard External Memory | GFXRECON_PAGE_GUARD_EXTERNAL_MEMORY | BOOL | When the `page_guard` memory tracking mode is enabled, use the VK_EXT_external_memory_host extension to eliminate the need for shadow memory allocations. For each memory allocation from a host visible memory type, the capture layer will create an allocation from system memory, which it can monitor for write access, and provide that allocation to vkAllocateMemory as external memory. Only available on Windows. Default is `false`

## Capture Files
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

### Specifying Capture File Location
The capture file's save location can be specified by setting the
`GFXRECON_CAPTURE_FILE` environment variable, described above in
the [Layer Options](#layer-options) section.

### Timestamps
When capture file timestamps are enabled, a timestamp with an
[ISO 8601-based](https://en.wikipedia.org/wiki/ISO_8601)
format will be added to the name of every file created by the layer. The
timestamp is generated when the capture file is created by the layer's
`vkCreateInstance` function and is added to the base filename specified
through the `GFXRECON_CAPTURE_FILE` environment variable. Timestamps have
the form:
 ```
_yyyymmddThhmmss
```
where the lower-case letters stand for: Year, Month, Day, Hour, Minute, Second.
The `T` is a designator that separates the date and time components. Time is
reported for the local timezone and is specified with the 24-hour format.

The following example shows a timestamp that was added to a file that was
originally named `gfxrecon_capture.gfxr` and was created at 2:35 PM
on November 25, 2018:
  `gfxrecon_capture_20181125T143527.gfxr`
