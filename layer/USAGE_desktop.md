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

## Defining the Output Location

By default, the layer will generate a file called `gfxrecon_capture.gfxr` in
the current working directory.
However, you may define the environment variable `GFXRECON_CAPTURE_FILE` on
desktop to indicate the location and name of the resulting capture file.
This can be simply a filename, or an entire path.
If this variable is not set, then 


#### Windows

```
set GFXRECON_CAPTURE_FILE=dota2_capture.gfxr
```

#### Linux

```
export GFXRECON_CAPTURE_FILE=/home/vulkan_developer/artifact_capture.gfxr
```


## Using

Simply run the Vulkan application as normal after defining the above items.

