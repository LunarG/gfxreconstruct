<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->
<p align="left"><img src="https://vulkan.lunarg.com/img/NewLunarGLogoBlack.png" alt="LunarG" width=263 height=113 /></p>

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2018-2022 LunarG, Inc.

Copyright &copy; 2022 Advanced Micro Devices, Inc.

# GFXReconstruct API Capture and Replay - Vulkan

***This document describes the GFXReconstruct software for capturing and
replaying Vulkan API calls on Desktop systems (i.e. Windows, Linux, MacOS).***

If you are looking for capturing/replaying on a different platform, please refer
to one of these other documents:
 * [GfxReconstruct for Android](./USAGE_android.md)
 * [GfxReconstruct for Desktop D3D12](./USAGE_desktop_D3D12.md)


## Index

1. [Capturing API calls](#capturing-api-calls)
    1. [Enabling the Capture Layer](#enabling-the-capture-layer)
    2. [Capture Options](#capture-options)
    3. [Capture Files](#capture-files)
    4. [Capture Script](#capture-script)
2. [Replaying API Calls](#replaying-api-calls)
    1. [Command Line Arguments](#command-line-arguments)
    2. [Key Controls](#key-controls)
    3. [Virtual Swapchain](#virtual-swapchain)
    4. [Dumping resources](#dumping-resources)
3. [Other Capture File Processing Tools](#other-capture-file-processing-tools)
    1. [Capture File Info](#capture-file-info)
    2. [Capture File Compression](#capture-file-compression)
    3. [Shader Extraction](#shader-extraction)
    4. [Trimmed File Optimization](#trimmed-file-optimization)
    5. [JSON Lines Conversion](#json-lines-conversion)
    6. [Command Launcher](#command-launcher)
    7. [Options Common To All Tools](#common-options)

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

#### Understanding GFXReconstruct Layer Memory Capture

The Vulkan API allows Vulkan memory objects to be mapped by an application
for direct modification.
To successfully capture an application, the GFXReconstruct layer must be able to
detect if the application modifies the mapped memory in order to dump the changes
in the capture file so that they can be re-applied while replaying.
To achieve this GFXR utilizes four different modes:

##### 1. `assisted`
This mode expects the application to call `vkFlushMappedMemoryRanges`
after memory is modified; the memory ranges specified to the
`vkFlushMappedMemoryRanges` call will be written to the capture file
during the call.

##### 2. `unassisted`
This mode writes the full content of mapped memory to the capture file
on calls to `vkUnmapMemory` and `vkQueueSubmit`. It is very inefficient
for performance and it will bloat capture file sizes. May be unusable
with real-world applications that map large amounts of memory.

##### 3. `page_guard`
`page_guard` tracks modifications to individual memory pages, which are
written to the capture file on calls to `vkFlushMappedMemoryRanges`,
`vkUnmapMemory`, and `vkQueueSubmit`. This method requires allocating
shadow memory for all mapped memory. The way the changes are being tracked
varies depending on the operating system.
- On Windows `Vectored Exception Handling` mechanism is used on the shadow
memories that correspond to the mapped device memory regions.
- On Linux and Android the shadow memory regions are similarly trapped by
changing its access protection to `PROT_NONE`. Every access from the
application will generate a `SIGSEGV` which is handled by the appropriate
signal handler installed by the page guard manager.

Because a shadow memory is allocated and returned to the application instead
of the actual mapped memory returned by the driver, both reads and writes need
to be tracked.
- Writes need to be dumped to the capture file.
- Reads must trigger a memory copy from the actual mapped memory into the shadow
memory so that the application will read the correct/updated data each time.

`page_guard` is the most efficient, both performance and capture file size
wise, mechanism. However, as described in
[Conflicts With Crash Detection Libraries](#conflicts-with-crash-detection-libraries),
it has some limitation when capturing applications that install their own
signal handler for handling the `SIGSEGV` signal. This limitation exists
only on Linux and Android applications. To work around this
limitation there is the `userfaultfd` mechanism.

##### 4. `userfaultfd`
This mode utilizes the userfaultfd mechanism provided by the Linux kernel which
allows user space applications to detect and handle page faults.
Under the hood `userfaultfd` is the same mechanism as `page_guard` but instead of trapping
the shadow memory regions with the `PROT_NONE` + `SIGSEGV` trick, it
registers those memory regions for tracking to the userfaultfd mechanism.

Shadow memory regions are registered using the
`UFFDIO_REGISTER_MODE_WP | UFFDIO_REGISTER_MODE_MISSING` flags with the
userfaultfd mechanism and a handler thread is started and polls for faults
to trigger. The combination of those flags will trigger a fault in two cases:
- When an unallocated page is accessed with either a write or a read.
- When a page is written.

This imposes a limitation: When the shadow memory is freshly allocated all
pages will be unallocated, making tracking both reads and writes simple as
both will trigger a fault. However, after the first time the accesses are
tracked and dumped to the capture file, the reads cannot be tracked any longer
as the pages will be already allocated and won't trigger a fault.
To workaround this each time the memory is examined, the dirty regions are
being "reset". This involves unregistering those subregions from userfaultfd,
requesting new pages from the OS to be provided at the same virtual addresses
and then the subregions are registered again for tracking.
This has a performance penalty as in this case both reads and writes need
to be copied from the actual mapped memory into the shadow memory when
detected, while the `page_guard` method requires this only for reads.

Also there is another limitation. The way the new pages are requested each
time and the regions are unregistered and registered again, makes this
mechanism prone to race conditions when there are multiple threads. If a
thread is accessing a specific page within a region and at the same time
that region is being reset, then the access is not trapped and undefined
behavior occurs.

In order to work around this a list of the thread ids that access each
region is kept. When that specific region is being reset a signal is
sent to each thread which will force them to enter a signal handler that
GFXR registers for that signal. The signal handler essentially performs a
form of synchronization between the thread that is triggering the reset and
the rest of the threads that potentially are touching pages that are being
reset. The signal used one of the real time signals, the first in the range
[`SIGRTMIN`, `SIGRTMAX`] that has no handler already installed.

`userfaultfd` is less efficient performance wise than `page_guard` but
should be fast enough for real-world applications and games.

##### Disabling Debug Breaks Triggered by the GFXReconstruct Layer

When running an application in a debugger with the layer enabled, the
access violations triggered by the layer's memory tracking behavior may
cause the debugger to break. For example, on macOS using LLDB, these
debug breaks may be disabled with the following command:

```text
process handle SIGSEGV -n true -p true -s false
```

The equivalent command for GDB is:

```text
handle SIGSEGV nostop noprint
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

#### Supported Options

Options with the BOOL type accept the following values:

* A case-insensitive string value 'true' or a non-zero integer value indicate
  true.
* A case-insensitive string value 'false' or a zero integer value indicate
  false.

The capture layer will generate a warning message for unrecognized or invalid
option values.

| Option                                         | Environment Variable                                    | Type    | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| ---------------------------------------------- | ------------------------------------------------------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Capture File Name                              | GFXRECON_CAPTURE_FILE                                   | STRING  | Path to use when creating the capture file. Supports variable patterns for dynamic file paths, such as `${AppName}` (the application or executable name). Default is: `gfxrecon_capture.gfxr` |
| Capture Specific Frames                        | GFXRECON_CAPTURE_FRAMES                                 | STRING  | Specify one or more comma-separated frame ranges to capture.  Each range will be written to its own file.  A frame range can be specified as a single value, to specify a single frame to capture, or as two hyphenated values, to specify the first and last frame to capture.  Frame ranges should be specified in ascending order and cannot overlap. Note that frame numbering is 1-based (i.e. the first frame is frame 1). Example: `200,301-305` will create two capture files, one containing a single frame and one containing five frames.  Default is: Empty string (all frames are captured).                                                                                                                                                                                                                                                                                                                                                                   |
| Quit after capturing frame ranges              | GFXRECON_QUIT_AFTER_CAPTURE_FRAMES                      | BOOL    | Setting it to `true` will force the application to terminate once all frame ranges specified by `GFXRECON_CAPTURE_FRAMES` have been captured. Default is: `false`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| Hotkey Capture Trigger                         | GFXRECON_CAPTURE_TRIGGER                                | STRING  | Specify a hotkey (any one of F1-F12, TAB, CONTROL) that will be used to start/stop capture.  Example: `F3` will set the capture trigger to F3 hotkey. One capture file will be generated for each pair of start/stop hotkey presses. Default is: Empty string (hotkey capture trigger is disabled).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| Hotkey Capture Trigger Frames                  | GFXRECON_CAPTURE_TRIGGER_FRAMES                         | STRING  | Specify a limit on the number of frames to be captured via hotkey.  Example: `1` will capture exactly one frame when the trigger key is pressed. Default is: Empty string (no limit)                                                                                                                                                                                                                                                      |
| Use asset file                                 | GFXRECON_CAPTURE_USE_ASSET_FILE                         | BOOL    | When set to `true` assets (images, buffers and descriptors) will be stored separately into an asset file instead of the capture file.                                                                                                                                                                                                                                                       |
| Capture Specific GPU Queue Submits             | GFXRECON_CAPTURE_QUEUE_SUBMITS                          | STRING  | Specify one or more comma-separated GPU queue submit call ranges to capture.  Queue submit calls are `vkQueueSubmit` for Vulkan and `ID3D12CommandQueue::ExecuteCommandLists` for DX12. Queue submit ranges work as described above in `GFXRECON_CAPTURE_FRAMES` but on GPU queue submit calls instead of frames. The index is 0-based. Default is: Empty string (all queue submits are captured).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| Capture File Compression Type                  | GFXRECON_CAPTURE_COMPRESSION_TYPE                       | STRING  | Compression format to use with the capture file.  Valid values are: `LZ4`, `ZLIB`, `ZSTD`, and `NONE`. Default is: `LZ4`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| Capture File Timestamp                         | GFXRECON_CAPTURE_FILE_TIMESTAMP                         | BOOL    | Add a timestamp to the capture file as described by [Timestamps](#timestamps).  Default is: `true`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| Capture File Flush After Write                 | GFXRECON_CAPTURE_FILE_FLUSH                             | BOOL    | Flush output stream after each packet is written to the capture file.  Default is: `false`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| Capture Environment | GFXRECON_CAPTURE_ENVIRONMENT | STRING | Comma delimited list of environment variables to store in the capture file. These can optionally be restored during replay to their capture-time values with the `gfxrecon-replay-renamed.py` utility.
| Log Level                                      | GFXRECON_LOG_LEVEL                                      | STRING  | Specify the highest level message to log.  Options are: `debug`, `info`, `warning`, `error`, and `fatal`.  The specified level and all levels listed after it will be enabled for logging.  For example, choosing the `warning` level will also enable the `error` and `fatal` levels. Default is: `info`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| Log Output to Console                          | GFXRECON_LOG_OUTPUT_TO_CONSOLE                          | BOOL    | Log messages will be written to stdout. Default is: `true`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| Log File                                       | GFXRECON_LOG_FILE                                       | STRING  | When set, log messages will be written to a file at the specified path. Default is: Empty string (file logging disabled).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| Log Detailed                                   | GFXRECON_LOG_DETAILED                                   | BOOL    | Include name and line number from the file responsible for the log message. Default is: `false`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| Log Allow Indents                              | GFXRECON_LOG_ALLOW_INDENTS                              | BOOL    | Apply additional indentation formatting to log messages. Default is: `false`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| Log Break on Error                             | GFXRECON_LOG_BREAK_ON_ERROR                             | BOOL    | Trigger a debug break when logging an error. Default is: `false`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| Log File Create New                            | GFXRECON_LOG_FILE_CREATE_NEW                            | BOOL    | Specifies that log file initialization should overwrite an existing file when true, or append to an existing file when false. Default is: `true`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| Log File Flush After Write                     | GFXRECON_LOG_FILE_FLUSH_AFTER_WRITE                     | BOOL    | Flush the log file to disk after each write when true. Default is: `false`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| Log File Keep Open                             | GFXRECON_LOG_FILE_KEEP_OPEN                             | BOOL    | Keep the log file open between log messages when true, or close and reopen the log file for each message when false. Default is: `true`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| Log Output to Debug Console                    | GFXRECON_LOG_OUTPUT_TO_OS_DEBUG_STRING                  | BOOL    | Windows only option.  Log messages will be written to the Debug Console with `OutputDebugStringA`. Default is: `false`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| Memory Tracking Mode                           | GFXRECON_MEMORY_TRACKING_MODE                           | STRING  | Specifies the memory tracking mode to use for detecting modifications to mapped Vulkan memory objects. Available options are: `page_guard`, `userfaultfd`, `assisted`, and `unassisted`. See [Understanding GFXReconstruct Layer Memory Capture](#understanding-gfxreconstruct-layer-memory-capture) for more details. Default is `page_guard`.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| Page Guard Copy on Map                         | GFXRECON_PAGE_GUARD_COPY_ON_MAP                         | BOOL    | When the `page_guard` memory tracking mode is enabled, copies the content of the mapped memory to the shadow memory immediately after the memory is mapped. Default is: `true`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| Page Guard Separate Read Tracking              | GFXRECON_PAGE_GUARD_SEPARATE_READ                       | BOOL    | When the `page_guard` memory tracking mode is enabled, copies the content of pages accessed for read from mapped memory to shadow memory on each read. Can overwrite unprocessed shadow memory content when an application is reading from and writing to the same page. Default is: `true`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| Page Guard External Memory                     | GFXRECON_PAGE_GUARD_EXTERNAL_MEMORY                     | BOOL    | When the `page_guard` memory tracking mode is enabled, use the VK_EXT_external_memory_host extension to eliminate the need for shadow memory allocations. For each memory allocation from a host visible memory type, the capture layer will create an allocation from system memory, which it can monitor for write access, and provide that allocation to vkAllocateMemory as external memory. Only available on Windows. Default is `false`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| Page Guard Persistent Memory                   | GFXRECON_PAGE_GUARD_PERSISTENT_MEMORY                   | BOOL    | When the `page_guard` memory tracking mode is enabled, this option changes the way that the shadow memory used to detect modifications to mapped memory is allocated. The default behavior is to allocate and copy the mapped memory range on map and free the allocation on unmap. When this option is enabled, an allocation with a size equal to that of the object being mapped is made once on the first map and is not freed until the object is destroyed.  This option is intended to be used with applications that frequently map and unmap large memory ranges, to avoid frequent allocation and copy operations that can have a negative impact on performance.  This option is ignored when GFXRECON_PAGE_GUARD_EXTERNAL_MEMORY is enabled. Default is `false`                                                                                                                                                                                                 |
| Page Guard Align Buffer Sizes                  | GFXRECON_PAGE_GUARD_ALIGN_BUFFER_SIZES                  | BOOL    | When the `page_guard` memory tracking mode is enabled, this option overrides the Vulkan API calls that report buffer memory properties to report that buffer sizes and alignments must be a multiple of the system page size.  This option is intended to be used with applications that perform CPU writes and GPU writes/copies to different buffers that are bound to the same page of mapped memory, which may result in data being lost when copying pages from the `page_guard` shadow allocation to the real allocation.  This data loss can result in visible corruption during capture.  Forcing buffer sizes and alignments to a multiple of the system page size prevents multiple buffers from being bound to the same page, avoiding data loss from simultaneous CPU writes to the shadow allocation and GPU writes to the real allocation for different buffers bound to the same page.  This option is only available for the Vulkan API.  Default is `true` |
| Page Guard Unblock SIGSEGV                     | GFXRECON_PAGE_GUARD_UNBLOCK_SIGSEGV                     | BOOL    | When the `page_guard` memory tracking mode is enabled and in the case that SIGSEGV has been marked as blocked in thread's signal mask, setting this enviroment variable to `true` will forcibly re-enable the signal in the thread's signal mask. Default is `false`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| Page Guard Signal Handler Watcher              | GFXRECON_PAGE_GUARD_SIGNAL_HANDLER_WATCHER              | BOOL    | When the `page_guard` memory tracking mode is enabled, setting this enviroment variable to `true` will spawn a thread which will will periodically reinstall the `SIGSEGV` handler if it has been replaced by the application being traced. Default is `false`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| Page Guard Signal Handler Watcher Max Restores | GFXRECON_PAGE_GUARD_SIGNAL_HANDLER_WATCHER_MAX_RESTORES | INTEGER | Sets the number of times the watcher will attempt to restore the signal handler. Setting it to a negative will make the watcher thread run indefinitely. Default is `1`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| Force Command Serialization                    | GFXRECON_FORCE_COMMAND_SERIALIZATION                    | BOOL    | Sets exclusive locks(unique_lock) for every ApiCall. It can avoid external multi-thread to cause captured issue.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| Queue Zero Only                                | GFXRECON_QUEUE_ZERO_ONLY                                | BOOL    | Forces to using only QueueFamilyIndex: 0 and queueCount: 1 on capturing to avoid replay error for unavailble VkQueue.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| Allow Pipeline Compile Required                | GFXRECON_ALLOW_PIPELINE_COMPILE_REQUIRED                | BOOL    | The default behaviour forces VK_PIPELINE_COMPILE_REQUIRED to be returned from Create*Pipelines calls which have VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT set, and skips dispatching and recording the calls. This forces applications to fallback to recompiling pipelines without caching, the Vulkan calls for which will be captured. Enabling this option causes capture to record the application's calls and implementation's return values unmodified, but the resulting captures are fragile to changes in Vulkan implementations if they use pipeline caching.                                                                                                                                                                                                                                                                                                                                                                                     |
| Stop Recording Calls in Threads With Invalid Data | GFXRECON_SKIP_THREADS_WITH_INVALID_DATA | BOOL | When a thread is encountered which contains data that is unexpected, skip the data and mark the thread as skippable.  This is important especially in OpenXR where other API commands (such as Vulkan) may be generated inside of the OpenXR commands, but may still be referenced in some fashion outside of the OpenXR commands.  This results in issues during replay.  So, this option prevents those commands, and the threads containing those commands from being recorded to the capture file.  Default is `false` and it is only valid when OpenXR capture is enabled.                                               |

#### Memory Tracking Known Issues

### Capture Limitations

#### Conflicts With Crash Detection Libraries

As described in
[Understanding GFXReconstruct Layer Memory Capture](#understanding-gfxreconstruct-layer-memory-capture),
the capture layer, when it utilizing the `page_guard` mechanism, it uses a signal
handler to detect modifications to mapped memory.
Only one signal handler for that signal can be registered at a time, which can
lead to a potential conflict with crash detection libraries that will also
register a signal handler.

Conflict between the `page_guard` mechanism  and crash detection libraries depends on the
order with which each component registers its signal handler.
The capture layer will not register its signal handler until the first call to
`vkMapMemory`.
As long as the application initializes the crash detection library before
calling `vkMapMemory`, there should be no conflict.

The conflict occurs when the application initializes its Vulkan component and
its crash detection library concurrently.
Applications have been observed to initialize Vulkan and begin uploading
resources with one or more threads, while at the same time initializing a crash
detection library from another thread.
For this scenario, the crash detection library sets its signal handler after the
first call to `vkMapMemory`, while a resource upload thread is actively writing
to the mapped memory.
After the crash detection library sets its signal handler, it immediately
receives a SIGSEGV event generated by the concurrent write to mapped memory,
which it detects as a crash and terminates the application.

`userfaultfd` mechanism was introduced in order to work around such conflicts.

#### Memory Tracking Limitations

There is a limitation with the `page_guard` memory tracking method used by the
GFXReconstruct capture layer.
The logic behind that method is to apply a memory protection to the
guarded/shadowed regions so that accesses made by the user to trigger a
segmentation fault which is handled by GFXReconstruct.
If the access is made by a system call (like `fread()`) then there won't be a
segmentation fault generated and the function will fail.
As a result the mapped region will not be updated.

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

#### Layer Settings via VK_EXT_layer_settings

An alternative way to configure the GFXReconstruct Vulkan capture layer is via the Vulkan
`VK_EXT_layer_settings` extension, which allows settings to be passed directly through the
Vulkan API at instance creation time. This is especially useful in environments where
environment variables and settings files are not available or convenient (such as some
launchers or embedded systems).

GFXReconstruct supports reading capture options from `VkLayerSettingEXT` structures
provided in the `pNext` chain of `VkInstanceCreateInfo` when creating a Vulkan instance.
This allows you to specify settings programmatically, without relying on environment
variables or external files.

To use this feature, add a `VkLayerSettingsCreateInfoEXT` structure to the `pNext` chain
of your `VkInstanceCreateInfo`, and include settings for the
`VK_LAYER_LUNARG_gfxreconstruct` layer. For example, to set the capture file name:

```c
const char* capture_file_value[] = { "my_capture.gfxr" };

VkLayerSettingEXT capture_file_setting = {
    .pLayerName = "VK_LAYER_LUNARG_gfxreconstruct",
    .pSettingName = "capture_file",
    .type = VK_LAYER_SETTING_TYPE_STRING_EXT,
    .valueCount = 1,
    .pValues = capture_file_value,
};

VkLayerSettingsCreateInfoEXT layer_settings_info = {
    .sType = VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT,
    .pNext = NULL,
    .settingCount = 1,
    .pSettings = &capture_file_setting
};

VkInstanceCreateInfo instance_info = {
    .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    .pNext = &layer_settings_info,
    // ... other fields ...
};
```

Supported settings include:

- `capture_file` (string): Path to use when creating the capture file (same as `GFXRECON_CAPTURE_FILE`).

#### Selecting Settings for the page_guard Memory Tracking Mode

The default settings selected for the `page_guard` memory tracking mode are the settings that are most likely to work on a given platform, but may not provide the best performance for all cases.

For Windows, setting `GFXRECON_PAGE_GUARD_EXTERNAL_MEMORY` to `true` is recommended. If capture does not work with this setting, or a different operating system is being used, try the default settings.

If capture performs poorly with the the default settings, try setting `GFXRECON_PAGE_GUARD_PERSISTENT_MEMORY` to `true`.

If corruption is observed during capture, try setting `GFXRECON_PAGE_GUARD_ALIGN_BUFFER_SIZES` to `true`. If this does not help, try setting `GFXRECON_PAGE_GUARD_SEPARATE_READ` to `false`.

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

When capture file timestamps are enabled, a timestamp with an ISO 8601-based
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

### Trimmed Captures

Trimmed captures are created when GFXR is configured to start capturing at some later
time in execution.

To create a trimmed capture one of the trimming options can be used.
For example on desktop there is the `GFXRECON_CAPTURE_FRAMES` environment variable,
which specifies the frame ranges to capture, each range generating a separate
trimmed capture file. There's also the `GFXRECON_CAPTURE_TRIGGER` environment
variable. Each time the hot key is pressed a new trimmed capture is started/stopped.

An existing capture file can be trimmed by replaying the capture with the capture layer
enabled and a trimming frame range or trimming hot key enabled. (However, replay for
some content may be fast enough using the hot key may be difficult.) Here's an example
command-line that replays an existing capture with the capture layer enabled and
configured to capture only from frame 100 through frame 200 into a new capture file:

`gfxrecon-capture.py -f 100-200 gfxrecon-replay gfxrecon-example-capture.gfxr``

### Asset files

When doing a trimmed capture, `GFXRECON_CAPTURE_USE_ASSET_FILE` gives the option to
dump all assets (images, buffers and descriptors) separetly in a different capture
file called the asset file. When this option is enabled assets are tracked and
only those that are changed during a tracking period (outside of a trim range) are
dumped into the asset file. This first time a trim range is encountered (or the
hotkey is pressed) all assets will be dumped, but the next time this happens only
the assets that have been changed will be dumped. This should speed up the dumping
process.

### Capture Script

The `gfxrecon-capture-vulkan.py` tool is a convenience script that can be used to
start a capture and specify the capture options using a single command.

```text
usage: gfxrecon-capture-vulkan.py [-h]
                                  [-w dir]
                                  [-o captureFile]
                                  [-f captureFrames]
                                  [--no-file-timestamp]
                                  [--trigger {F1-F12,TAB,CTRL}]
                                  [--compression-type {LZ4,ZLIB,ZSTD,NONE}]
                                  [--file-flush]
                                  [--log-level {debug,info,warn,error,fatal}]
                                  [--log-timestamps]
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
  --log-timestamps      Output a timestamp in front of each log message.
  --log-file <logFile>  Write log messages to a file at the specified path.
                        Default is: Empty string (file logging disabled)
  --memory-tracking-mode {page_guard,assisted,unassisted}
                        Method to use to track changes to memory mapped objects:
                           page_guard: use guard pages to track changes (default)
                           assisted:   application will call vkFlushMappedMemoryRanges
                                       for memory to be written to the capture file
                           unassisted: all mapped memory will be written to the
                                       capture file during VkQueueSubmit and VkUnmapMemory
```

Most of the options for `gfxrecon-capture-vulkan.py` result in the script setting
the appropriate capture layer environment variable, then invoking the program to
be captured. Environment variables not set by `gfxrecon-capture-vulkan.py` can be
set manually before running `gfxrecon-capture-vulkan.py` and they will be detected by
the capture layer.

The `gfxrecon-capture-vulkan.py` tool is a Python3 script. In order to use it, a
Python3 interpreter must first be installed. Once Python3 is installed, you should
be able to invoke `gfxrecon-capture-vulkan.py` by simply typing:

```bash
gfxrecon-capture-vulkan.py -o vkcube.gfxr vkcube
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
gfxrecon-replay         [-h | --help] [--version] [--cpu-mask <binary-mask>] [--gpu <index>]
                        [--pause-frame <N>] [--paused] [--sync] [--screenshot-all]
                        [--screenshots <N1(-N2),...>] [--screenshot-format <format>]
                        [--screenshot-dir <dir>] [--screenshot-prefix <file-prefix>]
                        [--screenshot-scale SCALE] [--screenshot-size WIDTHxHEIGHT]
                        [--screenshot-interval <N>]
                        [--capture]
                        [--sfa | --skip-failed-allocations] [--replace-shaders <dir>]
                        [--opcd | --omit-pipeline-cache-data] [--wsi <platform>]
                        [--surface-index <N>] [--remove-unsupported] [--validate]
                        [-m <mode> | --memory-translation <mode>]
                        [--fwo <x,y> | --force-windowed-origin <x,y>]
                        [--swapchain MODE] [--use-captured-swapchain-indices]
                        [--mfr|--measurement-frame-range <start-frame>-<end-frame>]
                        [--measurement-file <file>] [--quit-after-measurement-range]
                        [--flush-measurement-range]
                        [--log-level <level>] [--log-file <file>] [--log-debugview]
                        [--debug-messenger-level <level>]
                        [--no-debug-popup] [--use-colorspace-fallback]
                        [--wait-before-present]
                        [--dump-resources <submit-index,command-index,draw-call-index>]
                        [--dump-resources <arg>]
                        [--dump-resources <filename>]
                        [--dump-resources <filename>.json]
                        [--dump-resources-before-draw] [--dump-resources-scale <scale>]
                        [--dump-resources-dir <dir>]
                        [--dump-resources-image-format <format>]
                        [--dump-resources-dump-depth-attachment]
                        [--dump-resources-dump-color-attachment-index <index>]
                        [--dump-resources-dump-vertex-index-buffers]
                        [--dump-resources-json-output-per-command]
                        [--dump-resources-dump-immutable-resources]
                        [--dump-resources-dump-all-image-subresources] <file>
                        [--pbi-all] [--pbis <index1,index2>]
                        [--pipeline-creation-jobs | --pcj <num_jobs>]


Required arguments:
  <file>                Path to the capture file to replay.

Optional arguments:
  -h                    Print usage information and exit (same as --help).
  --version             Print version information and exit.
  --log-level <level>   Specify highest level message to log. Options are:
                        debug, info, warning, error, and fatal. Default is info.
  --log-timestamps      Output a timestamp in front of each log message.
  --log-file <file>     Write log messages to a file at the specified path.
                        Default is: Empty string (file logging disabled).
  --log-debugview       Log messages with OutputDebugStringA. Windows only.
  --debug-messenger-level <level>
                        Specify highest debug messenger severity level. Options
                        are: debug, info, warning, and error. Default is
                        warning.
  --cpu-mask <binary-mask>
                        Set of CPU cores used by the replayer.
                        `binary-mask` is a succession of '0' and '1' read from left
                        to right that specifies used/unused cores.
                        For example '10010' activates the first and
                        fourth cores and deactivate all other cores.
                        If the option is not set, all cores can be used. If the option
                        is set only for some cores, the other cores are not used.
  --gpu <index>         Use the specified device for replay, where index
                        is the zero-based index to the array of physical devices
                        returned by vkEnumeratePhysicalDevices.  Replay may fail
                        if the specified device is not compatible with the
                        original capture devices.
  --gpu-group <index>   Use the specified device group for replay, where index
                        is the zero-based index to the array of physical device group
                        returned by vkEnumeratePhysicalDeviceGroups.  Replay may fail
                        if the specified device group is not compatible with the
                        original capture device group.
  --pause-frame <N>     Pause after replaying frame number N.
  --paused              Pause after replaying the first frame (same
                        as --pause-frame 1).
  --screenshot-all
                        Generate screenshots for all frames.  When this
                        option is specified, --screenshots is ignored.
  --screenshots <N1[-N2][,...]>
                        Generate screenshots for the specified frames.
                        Target frames are specified as a comma separated
                        list of frame ranges.  A frame range can be specified
                        as a single value, to specify a single frame, or as
                        two hyphenated values, to specify the first and last
                        frames to process.  Frame ranges should be specified in
                        ascending order and cannot overlap.  Note that frame
                        numbering is 1-based (i.e. the first frame is frame 1).
                        Example: 200,301-305 will generate six screenshots.
  --screenshot-interval <N>
                        Specifies the number of frames between two screenshots
                        within a screenshot range.
                        Example: If screenshot range is 10-15 and interval is 2,
                        screenshot will be generated for frames 10, 12 and 14.
                        Default is 1.
  --screenshot-format <format>
                        Image file format to use for screenshot generation.
                        Available formats are:
                            bmp         Bitmap file format.  This is the default format.
                            png         Portable Network Graphics file format.
  --screenshot-dir <dir>
                        Directory to write screenshots.  Default is the current
                        working directory.
  --screenshot-prefix <file-prefix>
                        Prefix to apply to the screenshot file name.  Default is
                        "screenshot", producing file names similar to
                        "screenshot_frame8049.bmp".
  --screenshot-scale SCALE
                        Specify a decimal factor which will determine screenshot
                        sizes. The factor will be multiplied with the swapchain
                        images dimension to determine the screenshot dimensions.
                        Default is 1.0.
  --screenshot-size WIDTHxHEIGHT
                        Specify desired screenshot dimensions. Leaving this
                        unspecified screenshots will use the swapchain images
                        dimensions. If --screenshot-scale is also specified then
                        this option is ignored.
  --capture             Capture the replaying GFXR file. Capture option behavior and
                        usage is the same as when capturing with the GFXR layer. The
                        capture functionality is included in the `gfxrecon-replay`
                        executable--no GFXR capture layer is added to the Vulkan layer
                        chain.
  --sfa                 Skip vkAllocateMemory, vkAllocateCommandBuffers, and
                        vkAllocateDescriptorSets calls that failed during
                        capture (same as --skip-failed-allocations).
  --replace-shaders <dir> Replace the shader code in each CreateShaderModule
                        with the contents of the file <dir>/sh<handle_id> if found, where
                        <handle_id> is the handle id of the CreateShaderModule call.
                        See gfxrecon-extract.
  --opcd                Omit pipeline cache data from calls to
                        vkCreatePipelineCache and skip calls to
                        vkGetPipelineCacheData (same as
                        --omit-pipeline-cache-data).
  --wsi <platform>      Force replay to use the specified wsi platform.
                        Available platforms are:
                        auto,display,headless,metal,wayland,win32,xcb,xlib
  --surface-index <N>   Restrict rendering to the Nth surface object created.
                        Used with captures that include multiple surfaces.  Default
                        is -1 (render to all surfaces).
  --sync                Synchronize after each queue submission with vkQueueWaitIdle.
  --remove-unsupported  Remove unsupported extensions and features from instance
                        and device creation parameters.
  --validate            Enables the Khronos Vulkan validation layer when replaying a
                        Vulkan capture or the Direct3D debug layer when replaying a
                        Direct3D 12 capture.
  -m <mode>             Enable memory translation for replay on GPUs with memory
                        types that are not compatible with the capture GPU's
                        memory types.  Available modes are:
                            none        No memory translation is performed.  This
                                        is the default behavior.
                            remap       Attempt to map capture memory types to
                                        compatible replay memory types, without
                                        altering memory allocation behavior.
                            realign     Adjust memory allocation sizes and
                                        resource binding offsets based on
                                        replay memory properties.
                            rebind      Change memory allocation behavior based
                                        on resource usage and replay memory
                                        properties.  Resources may be bound
                                        to different allocations with different
                                        offsets.  Uses VMA to manage allocations
                                        and suballocations.
  --fwo <x,y>           Force windowed mode if not already, and allow setting of a custom window location.
                        (Same as --force-windowed-origin)
  --no-debug-popup      Disable the 'Abort, Retry, Ignore' message box
                        displayed when abort() is called (Windows debug only).
  --swapchain MODE      Choose a swapchain mode to replay. Available modes are:
                            virtual     Virtual Swapchain of images which match
                                        the swapchain in effect at capture time and
                                        which are copied to the underlying swapchain of the
                                        implementation being replayed on. This is default.
                            captured    Use the swapchain indices stored in the
                                        capture directly on the swapchain setup for replay.
                            offscreen   Disable creating swapchains, surfaces
                                        and windows. To see rendering, add the --screenshots option.
  --vssb
                        Skip blit to real swapchain to gain performance during replay.
  --use-captured-swapchain-indices
                        Same as "--swapchain captured". Ignored if the "--swapchain" option is used.
  --measurement-frame-range <start_frame>-<end_frame>
              Custom framerange to measure FPS for.
              This range will include the start frame but not the end frame.
              The measurement frame range defaults to all frames except the loading
              frame but can be configured for any range. If the end frame is past the
              last frame in the trace it will be clamped to the frame after the last
              (so in that case the results would include the last frame).
  --measurement-file <file>
              Write measurements to a file at the specified path.
              Default is: '/sdcard/gfxrecon-measurements.json' on android and
              './gfxrecon-measurements.json' on desktop.
  --quit-after-measurement-range
              If this is specified the replayer will abort
              when it reaches the <end_frame> specified in
              the --measurement-frame-range argument.
  --flush-measurement-range
              If this is specified the replayer will flush
              and wait for all current GPU work to finish at the
              start and end of the measurement range.
  --flush-inside-measurement-range
              If this is specified the replayer will flush and wait
              for all current GPU work to finish at the end of each
              frame inside the measurement range.
  --use-colorspace-fallback
              Swap the swapchain color space if unsupported by replay device.
              Check if color space is not supported by replay device and
              fallback to VK_COLOR_SPACE_SRGB_NONLINEAR_KHR.
  --offscreen-swapchain-frame-boundary
              Should only be used with offscreen swapchain.
              Activates the extension VK_EXT_frame_boundary (always supported if
              trimming, checks for driver support otherwise) and inserts command
              buffer submission with VkFrameBoundaryEXT where vkQueuePresentKHR
              was called in the original capture.
              This allows preserving frames when capturing a replay that uses.
              offscreen swapchain.
  --sgfs <status>
              Specify behaviour to skip calls to vkWaitForFences and vkGetFenceStatus:
                status=0 : Don't skip
                status=1 : Skip unsuccessful calls
                status=2 : Allways skip
              If no skip frame range is specified (--sgfr), the status applies to all
              frames.
  --sgfr <frame-ranges>
              Frame ranges where --sgfs applies. The format is:
                <frame-start-1>-<frame-end-1>[,<frame-start-1>-<frame-end-1>]*
  --wait-before-present
              Force wait on completion of queue operations for all queues
              before calling Present. This is needed for accurate acquisition
              of instrumentation data on some platforms.
  --dump-resources <submit-index,command-index,draw-call-index>
              The capture file will be examined, and <submit-index,command-index,draw-call-index>
              will be converted to <arg> as used in --dump-resources <arg> below.
              The converted args will be used as the args for dump resources.
  --dump-resources <arg>
              <arg> is BeginCommandBuffer=<n>,Draw=<o>,BeginRenderPass=<p>,
              NextSubpass=<q>,EndRenderPass=<r>,Dispatch=<s>,TraceRays=<t>,
              QueueSubmit=<u>
              Dump gpu resources after the given vmCmdDraw*, vkCmdDispatch, or vkCmdTraceRaysKHR
              is replayed. The parameter for each is a block index from the capture file. The
              additional parameters are used to identify during which occurence of the
              vkCmdDraw/vkCmdDispatch/vkCmdTraceRaysKHR resources will be dumped.  NextSubPass can
              be repeated 0 or more times to indicate subpasses within a render pass.  Note that
              the minimal set of parameters must be one of:
                  BeginCmdBuffer, Draw, BeginRenderPass, EndRenderPass, and QueueSubmit
                  BeginCmdBuffer, Dispatch and QueueSubmit
                  BeginCmdBuffer, TraceRays and QueueSubmit
  --dump-resources <filename>
              Extract --dump-resources block indices args from the specified file, with each line in
              the file containing a comma or space separated list of the parameters to
              --dump-resources <arg>. The file can contain multiple lines specifying multiple dumps.
  --dump-resources <filename>.json
              Extract --dump-resources block indices args from the specified json file. The format for the
              json file is documented in detail in the gfxreconstruct documentation.
  --dump-resources-image-format <format>
              Image file format to use for image resource dumping.
              Available formats are:
                  bmp         Bitmap file format.  This is the default format.
                  png         Png file format.
  --dump-resources-before-draw
              In addition to dumping gpu resources after the CmdDraw, CmdDispatch and CmdTraceRays calls
              specified by the --dump-resources <arg>, also dump resources before those
              calls.
  --dump-resources-scale <scale>
              Scale images generated by dump resources by the given scale factor. The scale factor must
              be a floating point number greater than 0. Values greater than 10 are capped at 10. Default
              value is 1.0.
  --dump-resources-dir <dir>
              Directory to write dump resources output files. Default is the current working directory.
  --dump-resources-image-format <format>
              Image file format to use when dumping image resources. Available formats are: bmp, png
  --dump-resources-dump-depth-attachment
              Configures whether to dump the depth attachment when dumping draw calls. Default is disabled.
  --dump-resources-dump-color-attachment-index <index>
              Specify which color attachment to dump when dumping draw calls. It should be an unsigned zero
              based integer. Default is to dump all color attachments.
  --dump-resources-dump-vertex-index-buffers
              Enables dumping of vertex and index buffers while dumping draw call resources.
  --dump-resources-json-output-per-command
              Enables storing a json output file for each dumped command. Overrides default behavior which
              is generating one output json file that contains the information for all dumped commands.
  --dump-resources-dump-immutable-resources
              Enables dumping of resources that are used as inputs in the commands requested for dumping.
  --dump-resources-dump-all-image-subresources
              Enables dumping of all image sub resources (mip map levels and array layers).
  --dump-resources-dump-raw-images
              When enabled all image resources will be dumped verbatim as raw bin files.
  --dump-resources-dump-separate-alpha
              When enabled alpha channel of dumped images will be dumped in a separate file.
  --pbi-all
              Print all block information.
  --pbis <index1,index2>
              Print block information between block index1 and block index2.
  --pipeline-creation-jobs | --pcj <num_jobs>
              Specify the number of asynchronous pipeline-creation jobs as integer.
              If <num_jobs> is negative it will be added to the number of cpu-cores, e.g. -1 -> num_cores - 1.
              Default: 0 (do not use asynchronous operations)
  --save-pipeline-cache <cache-file>
                        If set, produces pipeline caches at replay time instead of using
                        the one saved at capture time and save those caches in <cache-file>.
  --load-pipeline-cache <cache-file>
                        If set, loads data created by the `--save-pipeline-cache`
                        option in <cache-file> and uses it to create the pipelines instead
                        of the pipeline caches saved at capture time.
  --add-new-pipeline-caches
                        If set, allows gfxreconstruct to create new vkPipelineCache objects
                        when it encounters a pipeline created without cache. This option can
                        be used in coordination with `--save-pipeline-cache` and
                        `--load-pipeline-cache`.
  --quit-after-frame
              Specify a frame after which replay will terminate.
```

### Key Controls

The `gfxrecon-replay` tool for Desktop supports the following key controls:

| Key(s)         | Action                                 |
| -------------- | -------------------------------------- |
| Space, p       | Toggle pause/play.                     |
| Right arrow, n | Advance to the next frame when paused. |

### Virtual Swapchain

During replay, swapchain indices for present can be different from captured indices. Causes for this can include the swapchain image count differing between capture and replay, and `vkAcquireNextImageKHR` returning a different `pImageIndex` at replay to the one that was captured. These issues can cause unexpected rendering or even crashes.

Virtual Swapchain insulates higher layers in the Vulkan stack from these problems by creating a set of images, exactly matching the swapchain configuration at capture time, which it exposes for them to render into.  Before a present, it copies the virtual image to a target swapchain image for display. Since this issue can happen in many situations, virtual swapchain is the default setup. If the user wants to bypass the feature and use the captured indices to present directly on the swapchain of the replay implementation, they should add the `--use-captured-swapchain-indices` option when invoking `gfxrecon-replay`.

### Debug mode VMA errors

gfxrec-replay with the -m rebind option uses the Vulkan Memory Allocator library for memory allocations. If gfxrecon-replay is compiled debuggable, VMA_ASSERT errors in VMA can be trapped for debugging by setting GFXRECON_LOG_BREAK_ON_ERROR to true.

### Fence skipping

There can be situations where one wants to alter Vulkan fences behavior without being able to modifying the application. For example, for GPU performance measurements, we might want to "pack frames" when replaying by removing fences that we know unnecessary. For these situations, the options `--skip-get-fence-status`(`--sgfs`) and `--skip-get-fence-ranges`(`--sgfr`) have been created.

There are three possible status that can be set using `--sgfs`:
- `0` - Don't skip: The default status, nothing particular happens.
- `1` - Skip unsuccessful: `vkWaitForFences`/`vkGetFenceStatus` is called only if the result at capture time was `VK_SUCCESS`. Else, the result obtained at capture time is directly returned.
- `2` - Skip all: `vkWaitForFences`/`vkGetFenceStatus` is never called and `VK_SUCCESS` is returned directly instead.

The `--sgfr` option specify at which frames these conditions apply. If `--sgfr` is not specified, they apply to all frames.

### Dumping resources

GFXReconstruct offers the capability to dump resources when replaying a capture file. Detailed documentation of that feature can be found in [vulkan_dump_resources.md](./vulkan_dump_resources.md)

## Other Capture File Processing Tools

### Capture File Info

The `gfxrecon-info` tool prints statistics for a GFXReconstruct capture file, including
information about the application,
the physical device , device memory allocation, and device pipelines.

```text
gfxrecon-info - Print statistics for a GFXReconstruct capture file.

Usage:
  gfxrecon-info [-h | --help] [--version] <file>

Required arguments:
  <file>      The GFXReconstruct capture file to be processed.

Optional arguments:
  -h          Print usage information and exit (same as --help).
  --version   Print version information and exit.
```

### Capture File Compression

The `gfxrecon-compress` tool compresses or decompresses GFXReconstruct
capture files. It can also be used to change the compression format used
in a capture file.

```text
gfxrecon-compress - A tool to compress/decompress GFXReconstruct capture files.

Usage:
  gfxrecon-compress [-h | --help] [--version] <input_file> <output_file> <compression_format>

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
  -h              Print usage information and exit (same as --help).
  --version       Print version information and exit.
```

### Shader Extraction

The `gfxrecon-extract` tool extracts all shaders in a GFXReconstruct capture
file. The extracted shaders are placed into a specified directory.

```text
gfxrecon-extract - Extract shaders from a GFXReconstruct capture file.

Usage:
  gfxrecon-extract [-h | --help] [--version] [--dir <dir>] <file>

Optional arguments:
  -h          Print usage information and exit (same as --help).
  --version   Print version information and exit.
  --dir <dir> Place extracted shaders into directory <dir>. Otherwise
              use <file>.shaders in working directory. Create directory
              if necessary. Each shader is placed in individual file
              named sh<handle_id> where handle_id is handle id of the
              CreateShaderModule call. See gfxrecon-replay --replace-shaders.
Required arguments:
  <file>      The GFXReconstruct capture file to be processed.
```

### Trimmed File Optimization

The `gfxrecon-optimize` tool removes unused buffer and image initialization
data from trimmed capture files.

For trimmed capture files, a snapshot of the Vulkan API state is written at
the start of the file. This state snapshot includes the data for all buffers
and images that were live at the time that capture started. Some of the buffer
and image objects captured in the state snapshot may go unreferenced by the
captured frames and their data can be removed from the capture file. The
`gfxrecon-optimize` tool will process a trimmed file to identify buffer and
image objects that were initialized in the state snapshot, but were not used
by any of the captured frames, and generate a new capture file that omits the
data for these unused buffer and image objects.

```text
gfxrecon-optimize - Remove unused resource initialization data from trimmed
                    GFXReconstruct capture files.

Usage:
  gfxrecon-optimize [-h | --help] [--version] <input-file> <output-file>

Required arguments:
  <input-file>          The trimmed GFXReconstruct capture file to be
                        processed.
  <output-file>         The name of the new GFXReconstruct capture file to be
                        created.

Optional arguments:
  -h                    Print usage information and exit (same as --help).
  --version             Print version information and exit.
```

### JSON Lines Conversion

The `gfxrecon-convert` tool converts a capture file into a series of JSON
documents, one per line following the
[JSON Lines standard](https://jsonlines.org/).
The JSON document on each line is designed to be parsed by tools such as simple
Python scripts as well as being useful for inspection by eye after pretty
printing, for example by piping through a command-line tool such as
[`jq`](https://stedolan.github.io/jq/).
For these post-processing use cases, `gfxrecon-convert` can be used to stream
from binary captures directly, without
having to save the intermediate JSON files to storage.
Because each JSON object is on its own line, line oriented tools such as
grep, sed, head, and split can be applied ahead of JSON-aware ones which
are heavier-weight to reduce their workload on large captures.

The file begins with a header object containing some metadata, followed by a
series of objects representing the sequence of Vulkan calls stored in the
capture. More details of the file format can be found in the tool's
[README](tools/convert/README.md).


```text
gfxrecon-convert - A tool to convert GFXReconstruct capture files to text.

Usage:
  gfxrecon-convert [-h | --help] [--version] <file>

Required arguments:
  <file>		Path to the GFXReconstruct capture file to be converted
                to text.

Optional arguments:
  -h			        Print usage information and exit (same as --help).
  --version		        Print version information and exit.
  --output file         'stdout' or a path to a file to write JSON output
                        to. Default is the input filepath with "gfxr" replaced
                        by "jsonl".
  --no-debug-popup      Disable the 'Abort, Retry, Ignore' message box
                        displayed when abort() is called (Windows debug only).
```

### Command Launcher

The `gfxrecon.py` tool is a utility that can be used to launch all of the
GFXReconstruct commands.

```text
usage: gfxrecon.py [-h] command ...

GFXReconstruct utility launcher.

positional arguments:
  command     Command to execute. Valid options are [capture, compress, convert,
              extract, info, optimize, replay]
  args        Command-specific argument list. Specify -h after command name for
              command help.

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

### Options Common To all Tools

If the environment variable `GFXRECON_NO_DEBUG_POPUP` has any non-zero
number or non-empty, non-numeric string value when running any of
of the file processing tools, the tool will attempt to disable the
'Abort, Retry, Ignore' message box displayed when `assert()` fails on
Windows in a Debug build.  This behavior is slightly different than
`--no-debug-popup` in that the message box is disabled before any other
variable initialization.  This is probably most useful in headless or
"Continuous Integration" builds when an on-screen message box that
can't be automatically dismissed may hang scripts or cause directories
to be locked.  (Note that "FALSE" and "no", as examples, are non-empty,
non-numeric string values and will be interpreted as enabling the option.)
