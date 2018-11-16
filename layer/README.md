# GFXReconstruct Vulkan Layer

The GFXReconstruct layer for Vulkan is available for capturing
Vulkan commands.


## Layer Details

The detailed name of the GFXReconstruct Vulkan layer is
`VK_LAYER_LUNARG_gfxreconstruct`.

This is the name that should be used to enable the layer from either
`vkCreateInstance` or setting it using the standard Vulkan Loader
`VK_INSTANCE_LAYERS` Environment Variable.


## Vulkan Layer Library Interface

The GFXReconstruct layer, as all Vulkan layer libraries, must conform to the
[layer library interface](https://github.com/KhronosGroup/Vulkan-Loader/blob/master/loader/LoaderAndLayerInterface.md#loader-and-layer-interface)
defined in the Vulkan Loader's
[LoaderAndLayerInterface.md](https://github.com/KhronosGroup/Vulkan-Loader/blob/master/loader/LoaderAndLayerInterface.md)
file found in the [Vulkan Loader GitHub](https://github.com/KhronosGroup/Vulkan-Loader).


## Usage

The usage of this layer depends upon the environment.
Currently, this layer is supported on Desktop (Linux/Windows) and
Android environments.
The details of how to use this layer are defined in the appropriate
document linked below:

[Desktop Usage](USAGE_desktop.md)

[Android Usage](USAGE_android.md)
