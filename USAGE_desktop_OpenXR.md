<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->
<p align="left"><img src="https://vulkan.lunarg.com/img/NewLunarGLogoBlack.png" alt="LunarG" width=263 height=113 /></p>

[![Creative Commons][1]][2]

[1]: https://i.creativecommons.org/l/by-nd/4.0/88x31.png "Creative Commons License"
[2]: https://creativecommons.org/licenses/by-nd/4.0/

Copyright &copy; 2018-2022 LunarG, Inc.

Copyright &copy; 2022 Advanced Micro Devices, Inc.

# GFXReconstruct API Capture and Replay - OpenXR

***This document describes the GFXReconstruct software for capturing and
replaying OpenXR on Desktop systems (i.e. Windows, Linux, MacOS).***

If you are looking for capturing/replaying on a different platform, please refer
to one of these other documents:

 * [Meta Quest Walkthrough](./HOWTO_meta_quest.md)
 * [GfxReconstruct for Android Vulkan](./USAGE_android.md)
 * [GfxReconstruct for Desktop Vulkan](./USAGE_desktop_Vulkan.md)
 * [GfxReconstruct for Desktop D3D12](./USAGE_desktop_D3D12.md)

## EXPERIMENTAL FEATURE!!!

Be aware the OpenXR support within GFXReconstruct is an experimental feature, with restricted functionality and testing. See List of Known Limitations below.


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

The GFXReconstruct capture layer is a OpenXR layer that intercepts OpenXR API
calls and logs them to a GFXReconstruct capture file. *Currently Vulkan capture must also be enabled concurrently when OpenXR Capture is enabled. See [GfxReconstruct for Desktop Vulkan](./USAGE_desktop_Vulkan.md) for details.*

### Enabling the Capture Layer

The path to the layer's `XrLayer_gfxreconstruct.json` file and
corresponding `VkLayer_gfxreconstruct` library must be added to
`XR_API_LAYER_PATH` environment variable for the OpenXR loader to find the layer. 

***Note that this must be the same path specified for the Vulkan Loader, as capture will not function correctly if different `VkLayer_gfxreconstruct` libraries are used for the two API's.***

After `XR_API_LAYER_PATH` has been updated, the layer may be enabled through
one of the following methods:

* Adding the `XR_APILAYER_LUNARG_gfxreconstruct` name string to the
  `XrInstanceCreateInfo::enabledApiLayerNames` value when calling
  `xrCreateInstance`
* Adding the `XR_APILAYER_LUNARG_gfxreconstruct` name string to the list of
  layer names specified through the `XR_ENABLE_API_LAYERS` environment variable

#### Setting XR_API_LAYER_PATH

The `XR_API_LAYER_PATH` environment variable can be used to tell the OpenXR
loader where to find the GFXReconstruct capture layer. (***Note: the following not yet supported in SDK, so you will need to manually set the `XR_API_LAYER_PATH`.***) ~~If you are using
GFXReconstruct from a Vulkan SDK installation or a Linux package install,
there is no need to set `XR_API_LAYER_PATH`- the installation process will have
set up the GFXReconstruct capture layer so that the Vulkan loader can find
and load it.~~

##### Setting XR_API_LAYER_PATH for Windows

If you are not using GFXReconstruct from a Vulkan SDK, use the
following as an example of how to update the Windows `XR_API_LAYER_PATH` and`VK_LAYER_PATH`
environment variable for the GFXReconstruct capture layer. The example uses
the `C:\gfxreconstruct` path to represent the location of directory containing
the GFXReconstruct project source, and the `build` folder name to represent
the sub-directory specified to CMake as the location to place the build
binaries. The following command would be executed from the command prompt to
add the Debug build of the layer to `VK_LAYER_PATH`:

```bat
set VK_LAYER_PATH=C:\gfxreconstruct\build\layer\Debug;%VK_LAYER_PATH%
set XR_LAYER_PATH=C:\gfxreconstruct\build\layer\Debug;%XR_LAYER_PATH%
```

##### Setting XR_API_LAYER_PATH for Linux (not supported)

~~If you are not using GFXReconstruct from the Vulkan SDK or a Linux package, use~~
~~the following as an example of how to update the Linux `XR_API_LAYER_PATH`~~
~~environment variable for the GFXReconstruct capture layer. The example uses~~
~~the `/gfxreconstruct` path to represent the location of directory containing~~
~~the GFXReconstruct project source, and the `build` folder name to represent~~
~~the sub-directory specified to CMake as the location to place the build~~
~~binaries. The following command would be executed from the command line to~~
~~add the layer to `XR_API_LAYER_PATH`:  export VK_LAYER_PATH=/gfxreconstruct/build/layer:$VK_LAYER_PATH~~

#### Enabling the capture with Environment Variables

The `XR_ENABLE_API_LAYERS`and `VK_INSTANCE_LAYERS` environment variables may be used so that the the
GFXReconstruct layer is loaded by the OpenXR and Vulkan loaders respectively.

##### Enabling the capture for Windows

The following command would be executed from the command prompt to set the
`XR_ENABLE_API_LAYERS` and `VK_INSTANCE_LAYERS` environment variables:

```bat
set XR_ENABLE_API_LAYERS=XR_APILAYER_LUNARG_gfxreconstruct
set VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
```

##### Enabling the layer for Linux (not supported)

~~The following command would be executed from the command line to set the
`VK_INSTANCE_LAYERS` environment variable: export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct~~

#### Understanding GFXReconstruct OpenXR Layer Capture and Replay

*TODO: Expand this section describing the differences between Vulkan and OpenXR capture and replay.*

* OpenXR realtime head, hand, controller capture will not match replay head, hand, controller data at replay. The latter being largely ignored.
* OpenXR state machine transitions and events will not match exactly between capture and replay.  Event data replay attempts to match events from capture, important for events reflecting runtime state such as `XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED`
* Replayed OpenXR frames are displayed at the the same head relative position as captured, and thus are insensitive to replay time head tracking. 

### Capture Options

The GFXReconstruct OpenXR layer supports several options, which may be enabled
through environment variables or a layer settings file. 

These match those described in [GfxReconstruct for Desktop Vulkan,](./USAGE_desktop_Vulkan.md) noting limitations described below.

## Replaying API Calls

The GFXReconstruct Replay tool, `gfxrecon-replay`, can be used to replay
files captured with or generated by other GFXReconstruct components. See  [GfxReconstruct for Desktop Vulkan](./USAGE_desktop_Vulkan.md) for full documentation, noting limitations described below.

### OpenXR Capture Known Limitations

The current implementation has been written to cover the OpenXR API entry points and usage based on a limited number of test applications (listed in issue below).  It is possible that meaningful omissions or errors in capture and/or replay may exist outside the usage tested.  The current set of known limitations is maintained in [GitHub/LunarG/gfxreconstruct issue 2145](https://github.com/LunarG/gfxreconstruct/issues/2145). 

## Status of Other Capture File Processing Tools

### Capture File Info

Appears to function with OpenXR captures.

### Capture File Compression

Has not been tested with OpenXR captures.

### Shader Extraction

Has not been tested with OpenXR.

### Trimmed File Optimization

OpenXR capture and replay do no support trimming options.

### JSON Lines Conversion

Has been tested and is believed to function correctly for all supported OpenXR commands and datatypes.

