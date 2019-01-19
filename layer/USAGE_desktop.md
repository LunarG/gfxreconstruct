# Using the Vulkan GFXReconstruct Layer on Desktop

## Enabling

You must add the location of the generated
`VK_LAYER_LUNARG_gfxreconstruct.json` file and corresponding
`VkLayer_gfxreconstruct` library to your
`VK_LAYER_PATH` in order for the Vulkan loader to be able
to find the layer.
Then, you must also enable the layer in one of two ways:
  * Directly in your application using the
layer's name during `vkCreateInstance`
  * Indirectly by using the
`VK_INSTANCE_LAYERS` environment variable.

### Setting the VK_LAYER_PATH

#### Windows

If your source was located in: `C:\my_folder\gfxreconstruct`
and your build folder was `build64`,
then you would add it to the layer path in the following way:

```
set VK_LAYER_PATH=C:\my_folder\gfxreconstruct\build64\layer\Debug;%VK_LAYER_PATH%
```

#### Linux

If your source was located in: `/my_folder/gfxreconstruct`
and your build folder was `build`,
then you would add it to the layer path in the following way:

```
export VK_LAYER_PATH=/my_folder/gfxreconstruct/build/layer;$VK_LAYER_PATH
```

### Forcing the layer with VK_INSTANCE_LAYERS

To force the layer to be enabled for Vulkan applications, you can
set the `VK_INSTANCE_LAYERS` environment variable in the following way:

#### Windows

```
set VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
```

#### Linux

```
export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
```

<br></br>

## GFXRecon Debug Options

THe GFXReconstruct has multiple options that can be adjusted by using
environment variables.
Just as above, you use "set" or "export" (depending upon your platform) to
define an environment variable.
Each environment variable **must** begin with the prefix `GFXRECON_`.

For example, to set the log_level to "warning", you would call:

#### Windows

```
set GFXRECON_LOG_LEVEL=warning
```

#### Linux

```
export GFXRECON_LOG_LEVEL=warning
```

<br></br>

[//]: # (BEGIN-CODE-GEN - DO NOT REMOVE THIS COMMENT, THE FOLLOWING CODE IS AUTO-GENERATED)
Option | Environment Variable | Type | Description
------ | ------------- | ------ | -------------
Capture Compression Type | GFXRECON_CAPTURE_COMPRESSION_TYPE | string | Define a specific compression type to use when capturing content.Valid values are: "lz4", "lz77", "none".<ul><li>"lz4" - LZ4 lossless compression</li><li>"lz77" - LZ77 lossless compression</li><li>"none" - No compression</li></ul>
Capture File | GFXRECON_CAPTURE_FILE | file/path | Overrides the default path and name of the capture file.
Capture File Timestamp | GFXRECON_CAPTURE_FILE_TIMESTAMP | bool | Indicate if you want the capture file name to include the timestamp at creation time. This is important if your application could generate more than one and would normally clobber the original file's contents.
Capture Force Flush | GFXRECON_CAPTURE_FORCE_FLUSH | bool | Indicate if you want to flush the contents of the capture file at the end of each generated API Call packet.
Log Allow Indents | GFXRECON_LOG_ALLOW_INDENTS | bool | Apply iindent formatting in the strings to attempt to make things easier to read. Although indenting is used in very limited circumstances currently.
Log Break On Error | GFXRECON_LOG_BREAK_ON_ERROR | bool | Force the layer to break if it encounters an error so you can debug it easily.
Log Detailed | GFXRECON_LOG_DETAILED | bool | Enable detailed logging messages (includes file name and location where triggered from).
Log Errors To Stderr | GFXRECON_LOG_ERRORS_TO_STDERR | bool | Redirect errors to stderr instead of stdout when writing to the console.
Log File | GFXRECON_LOG_FILE | file/path | Output all log information to a file in the given location. Can be empty resulting in no log file.  Does not affect console output.
Log File Create New | GFXRECON_LOG_FILE_CREATE_NEW | bool | Allow the layer to create a new log file every time it starts, or to append to the existing file.
Log File Flush After Write | GFXRECON_LOG_FILE_FLUSH_AFTER_WRITE | bool | Flush the log file after every write.
Log File Keep Open | GFXRECON_LOG_FILE_KEEP_OPEN | bool | Keep the log file open between writes, otherwise open and close it every message.
Log Level | GFXRECON_LOG_LEVEL | string | This option allows you to choose what log level you desire to trigger.Valid values are: "command", "debug", "info", "warning", "error", "fatal".<ul><li>"command" - Output log messages of all severities including command enter/exit messages</li><li>"debug" - Output log messages of Debug severity or higher</li><li>"info" - Output log messages of Info severity or higher</li><li>"warning" - Output log messages of Warning severity or higher</li><li>"error" - Output log messages of Error severity or higher</li><li>"fatal" - Output only fatal error log messages</li></ul>
Log Output To Console | GFXRECON_LOG_OUTPUT_TO_CONSOLE | bool | Output log messages to the console using stdout (or a platform appropriate version of console output).
Log Output To Os Debug String | GFXRECON_LOG_OUTPUT_TO_OS_DEBUG_STRING | bool | Output log messages to an OS-specific logging mechanism. Currently only works for Windows, but allows debug messages to re-direct from the console to `OutputDebugStringA`.
Memory Tracking Mode | GFXRECON_MEMORY_TRACKING_MODE | string | Define the memory tracking mode the layer uses when handling memory.Valid values are: "unassisted", "assisted", "page_guard".<ul><li>"unassisted" - Assumes the application does not flush, so writes all mapped data on an `vkUnmapMemory` or `vkQueueSubmit` call.</li><li>"assisted" - Assumes the application will always flush after writing to mapped memory, so will only write on a flush.</li><li>"page_guard" - Determine which regions of memory to write on an `vkUnmapMemory` or `vkQueueSubmit` call and shadows uncached memory so as to properly provide all memory it can.</li></ul>
[//]: # (END-CODE-GEN - DO NOT REMOVE THIS COMMENT, THE PRECEDING CODE IS AUTO-GENERATED)

<br></br>

## Defining the Output Location

By default, the layer will generate a file called `gfxrecon_capture.gfxr` in
the current working directory.
However, you may define the environment variable `GFXRECON_CAPTURE_FILE` on
desktop to indicate the location and name of the resulting capture file
as defined above in [GFXRecon Debug Options](#gfxrecon-debug-options).


<br></br>

## Using

Simply run the Vulkan application as normal after defining the above items.

