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

Option | Environment Variable | Type | Description
------| ------------- |------|-------------
Capture Compression Type | GFXRECON_CAPTURE_COMPRESSION_TYPE | STRING | Define a specific compression type to use when capturing content.  Valid values are: "LZ4", "ZLIB", and "NONE".
Capture File | GFXRECON_CAPTURE_FILE | STRING | This option allows you to override the default path and name of the capture file.
Capture File Timestamp | GFXRECON_CAPTURE_FILE_TIMESTAMP | BOOL | This option lets you indicate if you want the capture file name to include the timestamp at creation time. This is important if your application could generate more than one and would normally clobber the original file's contents.
Log Allow Indents | GFXRECON_LOG_ALLOW_INDENTS | BOOL | This is an option to allow indent formatting in the strings to attempt to make things easier to read. Although indenting is used in very limited circumstances currently.
Log Break On Error | GFXRECON_LOG_BREAK_ON_ERROR | BOOL | This option triggers a debug break whenever an error is logged.
Log Detailed | GFXRECON_LOG_DETAILED | BOOL | Enable detailed logging messages (includes file name and location where triggered from).
Errors To Stderr | GFXRECON_LOG_ERRORS_TO_STDERR | BOOL | This option allows you to force all error messages that would be normally logged to also output to stderr.
Log File | GFXRECON_LOG_FILE | STRING | This option allows you to define the path and name of a log file that will be generated with log messages.
Log File Create New | GFXRECON_LOG_FILE_CREATE_NEW | BOOL | This option indicates that you want to either create a new file every time the layer is triggered, or append to the old log file.
Log File Flush After Write | GFXRECON_LOG_FILE_FLUSH_AFTER_WRITE | BOOL | This option allows you to force a flush after every log file write to make sure you don't lose messages in a buffer.
Log File Keep Open | GFXRECON_LOG_FILE_KEEP_OPEN | BOOL | This option forces the log file to remain open after it's created to allow for faster recording of log messages.
Log Level | GFXRECON_LOG_LEVEL | STRING | This option allows you to choose what log level you desire to trigger.  Available options include: "debug", "info", "warning", "error", and "fatal".  Any level selected will include all levels listed after it.  For example, choosing "warning" will also log out "error" and "fatal" messages.
Log Output To Console | GFXRECON_LOG_OUTPUT_TO_CONSOLE | BOOL | This option allows log messages to be written out to stdout (or whatever debug console is available on the target platform).
Log Output To OS Debug String | GFXRECON_LOG_OUTPUT_TO_OS_DEBUG_STRING | BOOL | This option allows log messages to be written out to the OS-specific logging mechanism.  Currently only works for Windows, but allows debug messages to re-direct from the console to `OutputDebugStringA`.
Memory Tracking Mode | GFXRECON_MEMORY_TRACKING_MODE | STRING | This option allows the user to determine what memory tracking mode the layer uses when handling memory.  Available options are: "page_guard", "assisted" and "unassisted".  <ul><li>"page_guard" is used to determine which regions of memory to write on an `vkUnmapMemory` or `vkQueueSubmit` call.</li><li>"assisted" assumes the application will always flush after writing to mapped memory, so will only write on a flush.</li><li>"unassisted" assumes the application does not flush, so writes all mapped data on an `vkUnmapMemory` or `vkQueueSubmit` call.</li></ul>

## Defining the Output Location

By default, the layer will generate a file called `gfxrecon_capture.gfxr` in
the current working directory.
However, you may define the environment variable `GFXRECON_CAPTURE_FILE` on
desktop to indicate the location and name of the resulting capture file
as defined above in [GFXRecon Debug Options](#gfxrecon-debug-options).

## Using

Simply run the Vulkan application as normal after defining the above items.

