<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->

<p align="left"><img src="https://vulkan.lunarg.com/img/NewLunarGLogoBlack.png" alt="LunarG" width=263 height=113 /></p>

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2022-2023 LunarG, Inc.

Copyright &copy; 2022-2023 Advanced Micro Devices, Inc. All rights reserved.

# GFXReconstruct API Capture and Replay - D3D12

***This document describes the GFXReconstruct software for capturing and
replaying D3D12 API calls on Windows Desktop systems.***

If you are looking for capturing/replaying on a different platform, please refer
to one of these other documents:
 * [GfxReconstruct for Android Vulkan](./USAGE_android.md)
 * [GfxReconstruct for Desktop Vulkan](./USAGE_desktop_Vulkan.md)


## Index

1. [Capturing API calls](#capturing-api-calls)
    1. [Enabling D3D12 Capture](#enabling-d3d12-capture)
    2. [Capture Options](#capture-options)
    3. [Capture Files](#capture-files)
2. [Replaying API Calls](#replaying-api-calls)
    1. [Command Line Arguments](#command-line-arguments)
    2. [Keyboard Controls](#keyboard-controls)
    3. [Capturing Replay (Recapture)](#capturing-replay-recapture)
3. [Other Capture File Processing Tools](#other-capture-file-processing-tools)
    1. [Capture File Info](#capture-file-info)
    2. [Capture File Compression](#capture-file-compression)
    3. [Capture File Optimizer](#capture-file-optimizer)
    4. [Renaming Scripts](#renaming-scripts)
4. [AMD GPU Services Support](#ags-support)
    1. [How to Capture AGS](#how-to-capture-ags)
    2. [How to Process AGS Capture Files](#how-to-process-ags-capture-files)




## Capturing API calls

The GFXRconstruct capture process leans on a DLL substitution mechanism to intercept D3D12 API calls. When an application loads the D3D12 or DXGI runtimes, it loads the GFXReconstruct capture libraries instead, which provides a means of API call interception. From that point on, GFXReconstruct is able record D3D12 API calls to a capture file and also forward them to the real runtimes.

### Enabling D3D12 Capture

First, these components must be identified:

- The path to the application executable
- The GFXReconstruct capture libraries:
  - `d3d12.dll`
  - `dxgi.dll`
  - `d3d12_capture.dll`

These capture libraries must be placed beside the application executable. For example, if we have the following application:

```bash
C:\AppPath\d3d12_app.exe
```

We must populate its folder as follows:

```bash
C:\AppPath\d3d12_app.exe
C:\AppPath\d3d12.dll
C:\AppPath\dxgi.dll
C:\AppPath\d3d12_capture.dll
```

It is important to remove these capture libraries once capture is complete. Otherwise, subsequent runs of the application will also be captured.

If there is a specialized need to have the GFXReconstruct capture libraries call into a custom D3D12/DXGI runtime, then the custom runtime must be named either `d3d12_ms.dll` or `dxgi_ms.dll`. It must also be placed beside the application executable.

### Capture Options

Capture-time settings may be changed by setting `GFXRECON_*` environment variables.

If no options are set, GFXReconstruct will apply default settings and always record from the first frame up until application termination.

The following example demonstrates how to use the Windows Command Prompt to set the log level to "warning" and then launch the application. Running these commands will produce a .gfxr capture file in the current working directory.

```bat
set GFXRECON_LOG_LEVEL=warning
C:\AppPath\d3d12_app.exe
```

Note that some applications are started using a launcher (i.e. gaming services/platforms). In this case, GFXReconstruct's capture options should also be set in a Windows Command Prompt, and the launcher needs to be started from that **same** prompt. Then any child applications that are started by that launcher will inherit GFXReconstruct's capture options which were set in the prompt.

##### Supported Options

Options with the BOOL type accept the following values:

* A case-insensitive string value 'true' or a non-zero integer value indicate true.
* A case-insensitive string value 'false' or a zero integer value indicate false.

The capture layer will generate a warning message for unrecognized or invalid option values.

Option | Environment Variable | Type | Description
------| ------------- |------|-------------
Capture File Name | GFXRECON_CAPTURE_FILE | STRING | Path to use when creating the capture file.  Default is: `gfxrecon_capture.gfxr`
Capture Specific Frames | GFXRECON_CAPTURE_FRAMES | STRING | Specify one or more comma-separated frame ranges to capture.  Each range will be written to its own file.  A frame range can be specified as a single value, to specify a single frame to capture, or as two hyphenated values, to specify the first and last frame to capture.  Frame ranges should be specified in ascending order and cannot overlap. Note that frame numbering is 1-based (i.e. the first frame is frame 1). Example: `200,301-305` will create two capture files, one containing a single frame and one containing five frames.  Default is: Empty string (all frames are captured).
Quit after capturing frame ranges | GFXRECON_QUIT_AFTER_CAPTURE_FRAMES | BOOL | Setting it to `true` will force the application to terminate once all frame ranges specified by `GFXRECON_CAPTURE_FRAMES` have been captured. Default is: `false`
Hotkey Capture Trigger | GFXRECON_CAPTURE_TRIGGER | STRING | Specify a hotkey (any one of F1-F12, TAB, CONTROL) that will be used to start/stop capture.  Example: `F3` will set the capture trigger to F3 hotkey. One capture file will be generated for each pair of start/stop hotkey presses. Default is: Empty string (hotkey capture trigger is disabled).
Hotkey Capture Trigger Frames | GFXRECON_CAPTURE_TRIGGER_FRAMES | STRING | Specify a limit on the number of frames to be captured via hotkey.  Example: `1` will capture exactly one frame when the trigger key is pressed. Default is: Empty string (no limit)
Capture Specific GPU Queue Submits | GFXRECON_CAPTURE_QUEUE_SUBMITS | STRING | Specify one or more comma-separated GPU queue submit call ranges to capture.  Queue submit calls are `vkQueueSubmit` for Vulkan and `ID3D12CommandQueue::ExecuteCommandLists` for DX12. Queue submit ranges work as described above in `GFXRECON_CAPTURE_FRAMES` but on GPU queue submit calls instead of frames.  Default is: Empty string (all queue submits are captured).
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
Memory Tracking Mode | GFXRECON_MEMORY_TRACKING_MODE | STRING | Specifies the memory tracking mode to use for detecting modifications to mapped memory objects. Available options are: `page_guard` and `unassisted`. Default is `page_guard`, which tracks modifications to individual memory pages. Tracking modifications requires allocating shadow memory for all mapped memory.`unassisted` writes the full content of mapped memory to the capture file. It is very inefficient and may be unusable with real-world applications that map large amounts of memory. 
Page Guard Copy on Map | GFXRECON_PAGE_GUARD_COPY_ON_MAP | BOOL | When the `page_guard` memory tracking mode is enabled, copies the content of the mapped memory to the shadow memory immediately after the memory is mapped. Default is: `true`
Page Guard Separate Read Tracking | GFXRECON_PAGE_GUARD_SEPARATE_READ | BOOL | When the `page_guard` memory tracking mode is enabled, copies the content of pages accessed for read from mapped memory to shadow memory on each read. Can overwrite unprocessed shadow memory content when an application is reading from and writing to the same page. Default is: `true`
Page Guard External Memory | GFXRECON_PAGE_GUARD_EXTERNAL_MEMORY | BOOL | When the `page_guard` memory tracking mode is enabled, use the WriteWatch mechanism to eliminate the need for shadow memory allocations. For each memory allocation from a host visible memory type, the capture layer will create an allocation from system memory, which it can monitor for write access. Only available on Windows. Default is `true` for D3D12. 
Page Guard Persistent Memory | GFXRECON_PAGE_GUARD_PERSISTENT_MEMORY | BOOL | When the `page_guard` memory tracking mode is enabled, this option changes the way that the shadow memory used to detect modifications to mapped memory is allocated. The default behavior is to allocate and copy the mapped memory range on map and free the allocation on unmap. When this option is enabled, an allocation with a size equal to that of the object being mapped is made once on the first map and is not freed until the object is destroyed.  This option is intended to be used with applications that frequently map and unmap large memory ranges, to avoid frequent allocation and copy operations that can have a negative impact on performance.  This option is ignored when GFXRECON_PAGE_GUARD_EXTERNAL_MEMORY is enabled. Default is `false`
Enable Debug Layer | GFXRECON_DEBUG_LAYER | BOOL | Direct3D 12 only option. Enable the Direct3D debug layer for Direct3D 12 application captures. Default is `false`
 Debug Device Lost                 | GFXRECON_DEBUG_DEVICE_LOST             | BOOL   | Direct3D 12 only option. Enables automatic injection of breadcrumbs into command buffers and page fault reporting.                  Used to debug device removed problems. 
 Disable DXR Support               | GFXRECON_DISABLE_DXR                   | BOOL   | Direct3D 12 only option. Override the result of `CheckFeatureSupport` to report the `RaytracingTier` as `D3D12_RAYTRACING_TIER_NOT_SUPPORTED`. Default is `false` 
Acceleration Struct Size Padding | GFXRECON_ACCEL_STRUCT_PADDING | UINT | Direct3D 12 only option. Increase the required acceleration structure size that is reported to the application by calls to `GetRaytracingAccelerationStructurePrebuildInfo`. This can enable replay in environments with increased acceleration structure size requirements. The value should be specified as a percent of size increase. For example, a value of `5` would increase the reported acceleration structure sizes by `5%`. Default is `0` 
Force Command Serialization | GFXRECON_FORCE_COMMAND_SERIALIZATION | BOOL | Sets exclusive locks(unique_lock) for every ApiCall. It can avoid external multi-thread to cause captured issue.
Enable Experimental RV Search | GFXRECON_RV_ANNOTATION_EXPERIMENTAL | BOOL | Direct3D 12 only option. Experimental feature to help enable replay of certain DXR/ExecuteIndirect workloads. RV annotation is a capture mode which attempts to detect when applications write Resource Values (RVs) to memory. Conceptually, RVs represent different types of GPU pointers that applications write as resource data. This capture mode writes GFXR-specific identifier values into unoccupied bits of application-facing RVs and then searches for the identifier values when the application performs a memory write. This allows GFXR to better track RV locations and eventually produce an RV-optimized capture file that may be replayed. Enabling this feature introduces performance overhead during capture, and may result in unstable capture and/or replay.
Use random RV annotation | GFXRECON_RV_ANNOTATION_RAND | BOOL | Option for GFXRECON_RV_ANNOTATION_EXPERIMENTAL. By default, the 2-byte identifier values are hard-coded. This option generates random identifier values used for annotating GPUVAs and GPU descriptors. Use this if capture-time crashes are observed.
Specify GPU VA RV annotation | GFXRECON_RV_ANNOTATION_GPUVA | STRING | Option for GFXRECON_RV_ANNOTATION_EXPERIMENTAL. By default, the 2-byte identifier values are hard-coded. This option forces a specific identifier value to be used for annotating GPUVAs. The value should be specified as a 2-byte hexadecimal string, e.g., "0xAB12" or "ab12".
Specify GPU descriptor handle RV annotation | GFXRECON_RV_ANNOTATION_DESCRIPTOR | STRING | Option for GFXRECON_RV_ANNOTATION_EXPERIMENTAL. By default, the 2-byte identifier values are hard-coded. This option forces a specific identifier value to be used for annotating GPU descriptors. The value should be specified as a 2-byte hexadecimal string, e.g., "0xAB12" or "ab12".


### Capture Files

When a capture is created depends on the type of capture is being taken. If taking a full capture (all frames) then the capture file gets created when an export in `dxgi.dll` or `d3d12.dll` is called. If taking a trimmed capture (subset of frames), the capture file gets created on the starting condition (trigger hotkey or frame number).

#### Specifying Capture File Location

The capture file's save location can be specified by setting the`GFXRECON_CAPTURE_FILE` environment variable, described above in the [Layer Options](#layer-options) section.

#### Timestamps

When capture file timestamps are enabled, a timestamp with an ISO 8601-based
format will be added to the name of every file created by the layer. The timestamp is generated when the capture file is created and is added to the base filename specified through the `GFXRECON_CAPTURE_FILE` environment variable. Timestamps have
the form:

```text
_yyyymmddThhmmss
```

where the lower-case letters stand for: Year, Month, Day, Hours, Minutes, Seconds.  The `T` is a designator that separates the date and time components. Time is reported for the local timezone and is specified with the 24-hour format.

The following example shows a timestamp that was added to a file that was originally named `gfxrecon_capture.gfxr` and was created at 2:35 PM on November 25, 2018:  `gfxrecon_capture_20181125T143527.gfxr`

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

## Replaying API Calls

The GFXReconstruct Replay tool, `gfxrecon-replay`, can be used to replay files captured with or generated by other GFXReconstruct components. 

GFXReconstruct leverages the Agility SDK runtime in order to replay. This means that GFXReconstruct's D3D12 support inherits the same Windows OS version requirements that are imposed by the Agility SDK. Please see the official Agility SDK documentation for the most up-to-date requirements.

A folder named `D3D12` that contains the required Agility SDK runtime must exist in the same folder as `gfxrecon-replay.exe`. When building GFXReconstruct, the `D3D12` folder will be created in the `gfxrecon-replay` output build folder. If `gfxrecon-replay.exe` is copied to another folder, the `D3D12` folder must be copied along with it.

### Command Line Arguments

The `gfxrecon-replay` tool accepts the following command line arguments:

```text
gfxrecon-replay.exe - A tool to replay GFXReconstruct capture files.

Usage:
  gfxrecon-replay.exe   [-h | --help] [--version] [--gpu <index>]
                        [--pause-frame <N>] [--paused] [--sync] [--screenshot-all]
                        [--screenshots <N1(-N2),...>] [--screenshot-format <format>]
                        [--screenshot-dir <dir>] [--screenshot-prefix <file-prefix>]
                        [--screenshot-scale SCALE] [--screenshot-size WIDTHxHEIGHT]
                        [--sfa | --skip-failed-allocations] [--replace-shaders <dir>]
                        [--opcd | --omit-pipeline-cache-data] [--wsi <platform>]
                        [--use-cached-psos] [--surface-index <N>]
                        [--remove-unsupported] [--validate]
                        [--onhb | --omit-null-hardware-buffers]
                        [-m <mode> | --memory-translation <mode>]
                        [--fw <width,height> | --force-windowed <width,height>]
                        [--log-level <level>] [--log-file <file>] [--log-debugview]
                        [--batching-memory-usage <pct>]
                        [--api <api>] <file>

Required arguments:
  <file>                Path to the capture file to replay.

Optional arguments:
  -h                    Print usage information and exit (same as --help).
  --version             Print version information and exit.
  --log-level <level>   Specify highest level message to log. Options are:
                        debug, info, warning, error, and fatal. Default is info.
  --log-file <file>     Write log messages to a file at the specified path.
                        Default is: Empty string (file logging disabled).
  --log-debugview       Log messages with OutputDebugStringA.
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
  --screenshot-format <format>
                        Image file format to use for screenshot generation.
                        Available formats are:
                            bmp         Bitmap file format.  This is the default format.
  --screenshot-dir <dir>
                        Directory to write screenshots.  Default is the current
                        working directory.
  --screenshot-prefix <file-prefix>
                        Prefix to apply to the screenshot file name.  Default is
                        "screenshot", producing file names similar to
                        "screenshot_frame_8049.bmp".
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
  --validate            Enables the Khronos Vulkan validation layer when replaying a
                        Vulkan capture or the Direct3D debug layer when replaying a
                        Direct3D 12 capture.
  --gpu <index>         Use the specified device for replay, where index
                        is the zero-based index to the array of physical devices
                        returned by vkEnumeratePhysicalDevices or IDXGIFactory1::EnumAdapters1.
                        Replay may fail if the specified device is not compatible with the
                        original capture devices.

Windows-only:
  --api <api>           Use the specified API for replay
                        Available values are:
                            vulkan      Replay with the Vulkan API enabled.
                            d3d12       Replay with the Direct3D API enabled.
                            all         Replay with both the Vulkan and Direct3D 12 APIs
                                        enabled. This is the default.

Vulkan-only:
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
                        Available platforms are: auto,win32,headless
  --surface-index <N>   Restrict rendering to the Nth surface object created.
                        Used with captures that include multiple surfaces.  Default
                        is -1 (render to all surfaces).
  --sync                Synchronize after each queue submission with vkQueueWaitIdle.
  --remove-unsupported  Remove unsupported extensions and features from instance
                        and device creation parameters.
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

D3D12-only:
  --use-cached-psos            Permit using cached PSOs when creating graphics or compute pipelines.
                               Using cached PSOs may reduce PSO creation time but may result in replay errors.
  --debug-device-lost          Enables automatic injection of breadcrumbs into command buffers
                               and page fault reporting.
                               Used to debug Direct3D 12 device removed problems.
  --fw <width,height>          Setup windowed and override resolution.
                               (Same as --force-windowed)
  --create-dummy-allocations   Enables creation of dummy heaps and resources
                               for replay validation.
  --dx12-override-object-names Generates unique names for all ID3D12Objects and
                               assigns each object the generated name.
                               This is intended to assist replay debugging.
  --batching-memory-usage <pct>
                               Limits the max amount of additional memory that can be used to batch
                               resource data uploads during trim state load. Batching resource data
                               uploads may reduce the number of GPU submissions required to load the
                               trim state. <pct> is applied to the total available physical system memory
                               and to the application's GPU memory budget. This only limits memory use
                               for batching and does not guarantee overall max memory usage.
                               Acceptable values range from 0 to 100 (default: 80). 0 means no batching,
                               100 means use all available system and GPU memory.
```



### Keyboard Controls

The `gfxrecon-replay` tool supports the following key controls:

Key(s) | Action
-------|-------
Space, p | Toggle pause/play.
Right arrow, n | Advance to the next frame when paused.



### Capturing Replay (Recapture)

`gfxrecon-replay` can be run with GFXReconstruct capture enabled. The process to capture the output of `gfxrecon-replay` is the same as capturing any other application as described in [Capturing API calls](#capturing-api-calls). This process is referred to as "recapture".

When recapturing DXR or EI enabled captures, those captures must first be optimized using [DXR Optimization](#dxr-optimization).



## Other Capture File Processing Tools

### Capture File Info

The `gfxrecon-info` tool prints statistics for a GFXReconstruct capture file. 

This includes:

- API-agnostic information about the capture file
- Executable name of the captured application
- Capture-time adapter/GPU information
- Capture-time driver information
- Swapchain dimensions (resolution)
- Whether it contains DXR workloads and has been optimized

```text
gfxrecon-info.exe - Print statistics for a GFXReconstruct capture file.

Usage:
  gfxrecon-info.exe [-h | --help] [--version] [--exe-info-only] <file>

Required arguments:
  <file>                The GFXReconstruct capture file to be processed.

Optional arguments:
  -h                    Print usage information and exit (same as --help).
  --version             Print version information and exit.
  --exe-info-only       Quickly exit after extracting captured application's executable name
```

### Capture File Compression

The `gfxrecon-compress` tool compresses or decompresses GFXReconstruct capture files. It can also be used to change the compression format used in a capture file.

```text
gfxrecon-compress.exe - A tool to compress/decompress GFXReconstruct capture files.

Usage:
  gfxrecon-compress.exe [-h | --help] [--version] <input_file> <output_file> <compression_format>

Required arguments:
  <input_file>          Path to the input file to process.
  <output_file>         Path to the output file to generate.
  <compression_format>  Compression format to apply to the output file.
                        Options are:
                          LZ4  - Use LZ4 compression.
                          ZLIB - Use zlib compression.
                          NONE - Remove compression.

Optional arguments:
  -h                    Print usage information and exit (same as --help).
  --version             Print version information and exit.
```

### Capture File Optimizer

The `gfxrecon-optimize` tool produces new capture files with improved replay performance.

Before attempting to optimize a capture file, please ensure it is able to replay first.

Like `gfxrecon-replay`, `gfxrecon-optimize` also requires the `D3D12` folder to exist beside it. As mentioned previously, this folder is where GFXReconstruct references the Agility SDK runtime.

There are two optimizations implemented for D3D12:

#### DXR Optimization

In order to replay DXR workloads, GFXReconstruct needs to ensure that GPUVAs are valid before submission time. This can be a challenge because GPUVAs recorded at capture-time cannot be reused verbatim at replay-time. Therefore GFXReconstruct replay needs to employ sophisticated GPUVA tracking mechanisms with the ultimate goal of patching resources with valid replay-time GPUVAs, before each submission. This is undesirable from a replay performance standpoint, but the optimizer tool can be used to remove this overhead. 

The first pass of this optimization replays the capture, to gather information about how the application filled in DXR buffers with which GPUVAs. The second pass of this optimization takes this information and creates a new GFXReconstruct capture with DXR resources populated with correct GPUVAs, without the need to patch them before submit time.

It is strongly recommended that this optimization is executed after capturing any application with a DXR workload. It needs to only be ran **once** per capture, and **must** be done so on a machine that can successfully replay the original capture. The resulting optimized capture can be then replayed using `gfxrecon-replay`

#### Redundant PSO Removal

Many applications create thousands of pipeline state objects (PSOs) during load time, which get set as GPU state at some point later in time. However, this does not mean a GFXReconstruct capture will be long enough to actually use all PSOs that were created. It is therefore redundant for GFXR to replay time-consuming creation of thousands of PSOs, which will never actually get referenced in the capture. 

The first pass of this optimization scans a capture, and gathers information about which PSOs were referenced or not. The second pass uses this information to construct a new capture file that excludes creation of PSOs which were never used to set GPU state. This results in huge time savings during replay load time for many applications.

It is strongly recommended that this optimization is executed after capturing any application. It needs to only be ran **once** per capture, and can be done so on **any** system. The resulting optimized capture can then be replayed using `gfxrecon-replay`

```text
gfxrecon-optimize.exe - Produce new captures with enhanced performance characteristics
                        For Vulkan, the optimizer will remove unused buffer and image initialization data (for trimmed captures)
                        For D3D12, the optimizer will improve DXR replay performance and remove unused PSOs (for all captures)

Usage:
  gfxrecon-optimize.exe [-h | --help] [--version] [--d3d12-pso-removal] [--dxr] [--gpu <index>] <input-file> <output-file>

Required arguments:
  <input-file>          The path to input GFXReconstruct capture file to be processed.
  <output-file>         The path to output GFXReconstruct capture file to be created.

Optional arguments:
  -h                    Print usage information and exit (same as --help).
  --version             Print version information and exit.
  --d3d12-pso-removal   D3D12-only: Remove creation of unreferenced PSOs.
  --dxr                 D3D12-only: Optimize for DXR replay.
  --gpu <index>         D3D12-only: Use the specified device for the optimizer replay, where index is the zero-based index to the array 
                        of physical devices returned by vkEnumeratePhysicalDevices or the optimizer replay may fail if the specified 
                        device is not compatible with the IDXGIFactory1::EnumAdapters1. The optimizer replay may fail if the specified 
                        device is not compatible with the original capture devices.

Note: running without optional arguments will instruct the optimizer to detect API and run all available optimizations.
```

### Renaming Scripts

In order to obtain application-matching playback, it is sometimes necessary to rename `gfxrecon-replay.exe` to match the captured application's executable name. This is because driver behavior can sometimes change depending on the executable name of the running application. Renaming is not always required, but it is an added measure towards functional replay. The two following utility scripts are bundled, which extract the application name from the capture file and make the renaming task automatic. Renaming can also be done manually, since the application executable name can be extracted using the `gfxrecon-info` tool.

#### gfxrecon-replay-renamed.py

This script can be used to replay capture files. It performs automatic renaming and execution of `gfxrecon-replay.exe`

```text
gfxrecon-replay-renamed.py - Helper script to perform automatic renaming of gfxrecon-replay.exe prior to playback.

Usage:
  gfxrecon-replay-renamed.py <file> [optional_replayer_args]

Required arguments:
  <file>                     Path to the capture file to replay.

Optional arguments:
  [optional_replayer_args]   All optional arguments exposed by gfxrecon-replay.exe
```

#### gfxrecon-optimize-renamed.py

This script can be used to optimize capture files. It performs automatic renaming and execution of `gfxrecon-optimize.exe`

The optimizer is a candidate for renaming since the DXR portion of it runs a replay of the capture.

```text
gfxrecon-optimize-renamed.py - Helper script to perform automatic renaming of gfxrecon-optimize.exe prior to optimization.

Usage:
  gfxrecon-optimize-renamed.py <input-file> <output-file> [--dxr] [--d3d12-pso-removal]

Required arguments:
  <input-file>          The path to input GFXReconstruct capture file to be processed.
  <output-file>         The path to output GFXReconstruct capture file to be created.

Optional arguments:
  --d3d12-pso-removal   D3D12-only: Remove creation of unreferenced PSOs.
  --dxr                 D3D12-only: Optimize for DXR replay.
  --gpu <index>         D3D12-only: Use the specified device for the optimizer replay, where index is the zero-based index to the array 
                        of physical devices returned by vkEnumeratePhysicalDevices or The optimizer replay may fail if the specified 
                        device is not compatible with the IDXGIFactory1::EnumAdapters1. The optimizer replay may fail if the specified 
                        device is not compatible with the original capture devices.

Note: running without optional arguments will instruct the optimizer to detect API and run all available optimizations.
```



## AMD GPU Services Support

Some applications adopt vendor-specific libraries to leverage GPU capabilities not exposed by graphics APIs. For example, the AMD GPU Services (AGS) library is commonly loaded by applications that have implemented features specific to AMD.

The GFXReconstruct capture process for AGS also leans on DLL substitution for interception. When an application loads amd_ags_x64.dll, it loads a proxy version provided by GFXReconstruct instead. From that point on, GFXReconstruct can record AGS function calls, process them, and call into the real AGS runtime.

This is supported for AGS version 6.0.1.


### How to Capture AGS

The process is the same as normal, with the addition that we must also perform some AGS DLL renaming. There are two versions of the AGS DLL:
- The official one, which comes bundled with the application (`amd_ags_x64.dll`)
- The proxy one, which comes bundled with GFXReconstruct (`amd_ags_x64_capture.dll`)

Steps:
1.	Identify the app executable.
2.	Identify the official AGS DLL that came bundled with the application, which usually lives beside its executable.
3.	Verify the AGS version that was shipped with the application. This can be done by inspecting its file properties. If the version is 6.0.1, then AGS calls made by this application can be captured.
4.	Rename the official AGS DLL to `amd_ags_x64_orig.dll`.
5.	Copy the GFXReconstruct capture libraries, plus the proxy AGS DLL, beside the application executable.
6.	Rename the proxy AGS DLL to `amd_ags_x64.dll`.
7.	At this point, the file structure should look like this:
```bash
    C:\AppPath\d3d12_app.exe
    C:\AppPath\d3d12.dll
    C:\AppPath\dxgi.dll
    C:\AppPath\d3d12_capture.dll
    C:\AppPath\amd_ags_x64.dll
    C:\AppPath\amd_ags_x64_orig.dll
```
8.	Resume standard full/trim capture procedures, and obtain a capture file.
9.	When finished, make sure to remove the GFXReconstruct capture libraries, and restore the official AGS DLL bundled with the application.

### How to Process AGS Files

Both gfxrecon-replay and gfxrecon-optimize are able to read and process capture files that contain with AGS calls. From a user point of view, their usage remains unchanged. The only additional requirement is that the official AGS DLL must live in the same directory as gfxrecon-replay and gfxrecon-optimize. This is because both tools need to find and reference the official AGS DLL in order to issue AGS calls.




