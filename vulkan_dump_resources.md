# Dumping resources

## Index

1. [Overview](#overview)
2. [Identifying commands](#identifying-commands)
3. [Which commands to specify](#which-commands-to-specify)
    1. [Transfer commands](#transfer-commands)
4. [Input json file](#input-json-file)
    1. [Structure](#structure)
    2. [Rules](#rules)
    3. [Examples](#examples)
    4. [Culling dumped descriptors](#culling-dumped-descriptors)
    5. [Dumping options](#dumping-options)
5. [Running](#running)
6. [Output](#output)
    1. [Json file output](#json-file-output)
    2. [Dumped files](#dumped-files)
7. [Appendix: legacy input json format](#appendix-legacy-input-json-format)

## Overview

GFXReconstruct can dump the resources used by selected commands while it replays a capture file:

* **Render targets**: the color and depth attachments of draw calls, both for render passes and for dynamic rendering.
* **Vertex and index buffers** bound for draw calls.
* **Compute and ray tracing outputs**: the images and buffers written by `vkCmdDispatch*` and `vkCmdTraceRays*`.
* **Descriptors**: the images and buffers that any shader stage reads as descriptor bindings.
* **Acceleration structures** and the input buffers used to build them.
* **Transfer targets**: the destination resources of copy, blit and build commands.

Images are written as `bmp` or `png` files, and everything else is written as binary files.

Dumping needs a live replay on a GPU and cannot be done offline. You choose what to dump in a json file
that lists the [block indices](#identifying-commands) of the commands you want, and pass it to the replayer (see
[Running](#running)). One run can dump any number of commands.

## Identifying commands

Every command in a capture file has a unique, increasing number called its **block index**. This includes both
the Vulkan calls the application made and the meta commands that GFXReconstruct inserts. You use this number to
tell the replayer which commands to dump.

The simplest way to find block indices is to convert the capture to json with one command per line:

```sh
gfxrecon-convert --format jsonl capture.gfxr
```

```json
{"index":301,"function":{"name":"vkBeginCommandBuffer","thread":2,"return":"VK_SUCCESS","args":{"commandBuffer":80, ... }}},
{"index":302,"function":{"name":"vkCmdBeginRenderPass","thread":2,"cmd_index":1,"args":{"commandBuffer":80, ... }}},
{"index":303,"function":{"name":"vkCmdBindPipeline","thread":2,"cmd_index":2,"args":{"commandBuffer":80, ... }}},
{"index":307,"function":{"name":"vkCmdDraw","thread":2,"cmd_index":6,"args":{"commandBuffer":80, ... }}},
```

The `index` key is the block index. Vulkan objects are identified in the same way, by an **object ID**. In the
example above, all four commands use the `VkCommandBuffer` with object ID `80`.

## Which commands to specify

**Commands that can be dumped:**

| Kind      | Commands |
|-----------|----------|
| Draw      | `vkCmdDraw`, `vkCmdDrawIndexed`, `vkCmdDrawIndirect`, `vkCmdDrawIndexedIndirect`, `vkCmdDrawIndirectCount[KHR]`, `vkCmdDrawIndexedIndirectCount[KHR]` |
| Dispatch  | `vkCmdDispatch`, `vkCmdDispatchIndirect` |
| TraceRays | `vkCmdTraceRaysKHR`, `vkCmdTraceRaysIndirectKHR` |
| Transfer  | See [Transfer commands](#transfer-commands) below |

The replayer also needs the commands around them, so it can find and re-run the right work:

| Context command | When it's needed | Where it goes |
|---|---|---|
| `vkQueueSubmit` / `vkQueueSubmit2` | Always | `QueueSubmits[].Index` |
| `vkBeginCommandBuffer` | Always, one per command buffer (primary or secondary) | `CommandBuffers[].Index` |
| Render pass range | Draw calls only | `RenderPasses`: `[begin, nextSubpass..., end]`, or `[beginRendering, endRendering]` for dynamic rendering |
| `vkCmdExecuteCommands` | Commands inside secondary command buffers | `ExecuteCommands[].Index`, with the secondaries nested below it |

### Transfer commands

The destination resources of these commands can be dumped:

| Command (the `2` and `2KHR` variants are also supported) | Dumped as |
|---|---|
| `vkCmdCopyBuffer` | One binary file per region of the destination buffer |
| `vkCmdCopyImageToBuffer` | One binary file per region of the destination buffer |
| `vkCmdCopyImage` | One image file per region of the destination image (binary if the format can't be converted) |
| `vkCmdCopyBufferToImage` | One image file per region of the destination image (binary if the format can't be converted) |
| `vkCmdBlitImage` | Destination image |
| `vkCmdBuildAccelerationStructuresKHR` | Acceleration structure (no `2` variants) |
| `vkCmdCopyAccelerationStructureKHR` | Acceleration structure (no `2` variants) |

**State-setup meta commands.** A trimmed capture starts with a state-setup block, which creates and initializes
every Vulkan object that existed before the captured range. The following meta commands from that block can also
be dumped:
`kInitBufferCommand`, `kInitImageCommand`, `kVulkanBuildAccelerationStructuresCommand` and
`kVulkanCopyAccelerationStructuresCommand`. They don't belong to any command buffer, so you request them with
the top-level `StateSetup` key instead of a command buffer's `Transfer` list (see the
[example](#transfer-commands-and-state-setup)).

## Input json file

The block indices along with other dump resources options are specified using a json file which is used as input during replay.

### Structure

The input json is a tree that follows how work is submitted. A queue submit contains command buffers. A command
buffer contains its render pass ranges, its lists of commands to dump, and the `vkCmdExecuteCommands` calls that
run secondaries. Each secondary is again a command buffer node.

```
QueueSubmits[] → CommandBuffers[] → RenderPasses, Draw, Dispatch, TraceRays, Transfer
                                  → ExecuteCommands[] → CommandBuffers[] → ...
```

**Top level**

| Key | Type | Required | Meaning |
|---|---|---|---|
| `SchemaVersion` | string `"<major>.<minor>"` | Yes | Format version. The current version is `"1.0"` |
| `DumpingOptions` | object | No | See [Dumping options](#dumping-options) |
| `QueueSubmits` | `[QueueSubmit]` | Yes, unless only `StateSetup` is given | |
| `StateSetup` | `{ "Transfer": [Command] }` | No | Meta commands in a trimmed capture's state-setup block |
| `Resources` | `[Resource]` | No | Not implemented yet |

**QueueSubmit**

| Key | Type | Required | Meaning |
|---|---|---|---|
| `Index` | index, or list of indices | Yes | `vkQueueSubmit[2]` block index. Give a list to dump the same command buffers from several submissions |
| `CommandBuffers` | `[CommandBuffer]` | Yes | |

**CommandBuffer** (a primary, or a secondary when it sits under `ExecuteCommands`)

| Key | Type | Required | Meaning |
|---|---|---|---|
| `Index` | index | Yes | `vkBeginCommandBuffer` block index |
| `RenderPasses` | `[[index...]]` | When `Draw` is given | One range per render pass or dynamic rendering instance |
| `Draw`, `Dispatch`, `TraceRays`, `Transfer` | `[Command]` | No | Commands to dump |
| `ExecuteCommands` | `[ExecuteCommands]` | No | |
| `Position` | | No | Which appearance of the command buffer to dump. Not implemented yet |
| `Resources` | `[Resource]` | No | Not implemented yet |

**ExecuteCommands**

| Key | Type | Required | Meaning |
|---|---|---|---|
| `Index` | index | Yes | `vkCmdExecuteCommands` block index |
| `CommandBuffers` | `[CommandBuffer]` | Yes | The secondaries to dump |

**Command**: either a plain block index, or an object:

| Key | Type | Required | Meaning |
|---|---|---|---|
| `Index` | index | Yes | Block index of the command |
| `Descriptors` | `[{Set, Binding, ArrayIndex, SubresourceRange}]` | No | See [Culling dumped descriptors](#culling-dumped-descriptors) |
| `DumpingOptions` | object | No | Per-command options. Not implemented yet |

### Rules

* Block indices are unsigned integers. The parser sorts lists, so write them in any order.
* No duplicates:
  * A block index may appear only once in a list, and in only one of the `Draw` / `Dispatch` / `TraceRays` /
    `Transfer` lists of a command buffer.
  * A command buffer may appear only once under each `QueueSubmit` or `ExecuteCommands`.
  * A `vkQueueSubmit` index may appear in only one `QueueSubmits` entry.
* A secondary that several `vkCmdExecuteCommands` calls (or several primaries) run in the same submission is listed
  under each of them, with the same request each time.
* A secondary recorded with `VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT` runs inside the primary's render
  pass, so that range goes in the **primary's** `RenderPasses`. A secondary that begins its own dynamic rendering
  lists that range in its **own** node.
* Unknown keys are errors.
* A file without `SchemaVersion` is rejected.
* A file with a top-level `BeginCommandBuffer` key is read as the [legacy format](#appendix-legacy-input-json-format).
  You can't mix the two formats.

> **Not implemented yet:** `Position`, `Resources` and per-command `DumpingOptions` are part of the format, but
> the replayer rejects them with an error, so a request is never silently dumped differently from how it was
> written. Without `Position`, the first appearance of a command buffer in the submission (or in the
> `vkCmdExecuteCommands` call) is dumped.

### Examples

#### Minimal request

Capture excerpt:

```json
{"index":301,"function":{"name":"vkBeginCommandBuffer", ... } },
{"index":302,"function":{"name":"vkCmdBeginRenderPass", ... } },
{"index":303,"function":{"name":"vkCmdBindPipeline", ... } },
{"index":304,"function":{"name":"vkCmdBindDescriptorSets", ... } },
{"index":305,"function":{"name":"vkCmdSetViewport", ... } },
{"index":306,"function":{"name":"vkCmdSetScissor", ... } },
{"index":307,"function":{"name":"vkCmdDraw", ... } },
...
{"index":312,"function":{"name":"vkCmdDraw", ... } },
{"index":313,"function":{"name":"vkCmdEndRenderPass", ... } },
{"index":314,"function":{"name":"vkEndCommandBuffer", ... } },
{"index":315,"function":{"name":"vkQueueSubmit", ... } },
```

This dumps the color attachments of all six `vkCmdDraw` calls:

```json
{
    "SchemaVersion": "1.0",
    "QueueSubmits": [
        {
            "Index": 315,
            "CommandBuffers": [
                {
                    "Index": 301,
                    "RenderPasses": [ [ 302, 313 ] ],
                    "Draw": [ 307, 308, 309, 310, 311, 312 ]
                }
            ]
        }
    ]
}
```

#### Primary with secondaries

The primary below contains a dispatch, a trace rays call, two transfer commands and a four-subpass render
pass. It runs five secondaries:

* Secondaries 1–3 are recorded with `RENDER_PASS_CONTINUE` and run inside subpasses of the primary's render pass.
* Secondary 4 runs outside any render pass.
* Secondary 5 begins its own dynamic rendering instance.

The primary is submitted twice.

```C
// secondary 1, RENDER_PASS_CONTINUE, inherits subpass 2
 100  vkBeginCommandBuffer
 101  vkCmdBind* ×4                       (101..104)
 105  vkCmdDrawIndexed
 106  vkEndCommandBuffer
// secondary 2, RENDER_PASS_CONTINUE, inherits subpass 3
 200  vkBeginCommandBuffer
 205  vkCmdDrawIndexed
 206  vkCmdDrawIndexed
 207  vkEndCommandBuffer
// secondary 3, RENDER_PASS_CONTINUE, inherits subpass 3
 300  vkBeginCommandBuffer
 305  vkCmdDrawIndexed
 306  vkCmdDrawIndexed
 307  vkEndCommandBuffer
// secondary 4, outside any render pass
 400  vkBeginCommandBuffer
 403  vkCmdDispatch
 404  vkEndCommandBuffer
// secondary 5, begins its own dynamic rendering instance
 500  vkBeginCommandBuffer
 501  vkCmdBeginRendering
 506  vkCmdDrawIndexed
 507  vkCmdEndRendering
 508  vkEndCommandBuffer
// primary
1000  vkBeginCommandBuffer
1001  vkCmdBindPipeline, BindDescriptorSets
1003  vkCmdDispatch
1004  vkCmdBuildAccelerationStructuresKHR
1005  vkCmdBindPipeline, BindDescriptorSets
1007  vkCmdTraceRaysKHR
1008  vkCmdCopyBuffer
1009  vkCmdBeginRenderPass                subpass 0
1014    vkCmdDrawIndexed
1015  vkCmdNextSubpass                    subpass 1
1020    vkCmdDrawIndexed
1021    vkCmdDrawIndexed
1022  vkCmdNextSubpass                    subpass 2
1023    vkCmdExecuteCommands([secondary1])
1024  vkCmdNextSubpass                    subpass 3
1029    vkCmdDrawIndexed
1030    vkCmdExecuteCommands([secondary2, secondary3])
1035    vkCmdDrawIndexed
1036  vkCmdEndRenderPass
1037  vkCmdExecuteCommands([secondary4])
1038  vkCmdExecuteCommands([secondary5])
1039  vkEndCommandBuffer
2000  vkQueueSubmit([primary])
2001  vkWaitForFences
2002  vkQueueSubmit([primary])
```

Input json, dumping the second submission:

```json
{
  "SchemaVersion": "1.0",
  "QueueSubmits": [ {
    "Index": 2002,
    "CommandBuffers": [ {
      "Index": 1000,
      "RenderPasses": [ [ 1009, 1015, 1022, 1024, 1036 ] ],
      "Draw":      [ 1014, 1020, 1021, 1029, 1035 ],
      "Dispatch":  [ 1003 ],
      "TraceRays": [ 1007 ],
      "Transfer":  [ 1004, 1008 ],
      "ExecuteCommands": [
        { "Index": 1023, "CommandBuffers": [ { "Index": 100, "Draw": [ 105 ] } ] },
        { "Index": 1030, "CommandBuffers": [ { "Index": 200, "Draw": [ 205, 206 ] },
                                             { "Index": 300, "Draw": [ 305, 306 ] } ] },
        { "Index": 1037, "CommandBuffers": [ { "Index": 400, "Dispatch": [ 403 ] } ] },
        { "Index": 1038, "CommandBuffers": [ { "Index": 500, "RenderPasses": [ [ 501, 507 ] ],
                                                             "Draw": [ 506 ] } ] }
      ]
    } ]
  } ]
}
```

Things to note:

* Secondaries 1–3 have no `RenderPasses`, because their draws run in the primary's render pass, which is already
  listed in the primary.
* Secondary 5 lists its own `[ 501, 507 ]` dynamic rendering range.
* `vkCmdBuildAccelerationStructuresKHR` (1004) and `vkCmdCopyBuffer` (1008) are dumped as a transfer commands.
* To dump both submissions, replace `"Index": 2002` with `"Index": [ 2000, 2002 ]`.

#### Transfer commands and state setup

[Transfer commands](#transfer-commands) go in a command buffer's `Transfer` list:

```json
{
    "SchemaVersion": "1.0",
    "QueueSubmits": [
        { "Index": 270, "CommandBuffers": [ { "Index": 250, "Transfer": [ 266, 267 ] } ] }
    ]
}
```

State-setup meta commands of a trimmed capture go in the top-level `StateSetup` key:

```json
{ "SchemaVersion": "1.0", "StateSetup": { "Transfer": [ 266, 267 ] } }
```

### Culling dumped descriptors

By default, all bound descriptors are dumped. To dump only some of them, write the command as an object and list
the descriptors by set, binding and array index:

```json
{
    "SchemaVersion": "1.0",
    "QueueSubmits": [
        {
            "Index": 2548,
            "CommandBuffers": [
                {
                    "Index": 2525,
                    "RenderPasses": [ [ 2526, 2538 ] ],
                    "Draw": [
                        {
                            "Index": 2533,
                            "Descriptors": [
                                { "Set": 0, "Binding": 1, "ArrayIndex": 0 },
                                { "Set": 0, "Binding": 0, "ArrayIndex": 0 }
                            ]
                        },
                        2537
                    ]
                }
            ]
        }
    ]
}
```

The command object looks the same in the legacy format.

For image descriptors, you can also limit which subresources are dumped:

```json
{
    "Set": 0, "Binding": 1, "ArrayIndex": 0,
    "SubresourceRange": {
        "AspectMask": "VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT",
        "BaseMipLevel": 2,   "LevelCount": 1,
        "BaseArrayLayer": 2, "LayerCount": 1,
        "BaseZIndex": 0,     "ZCount": 1
    }
}
```

| Field | Meaning | Special values |
|---|---|---|
| `AspectMask` | Aspects to dump, as in `VkImageSubresourceRange` | `VK_IMAGE_ASPECT_NONE`: all valid aspects of the image's format |
| `BaseMipLevel`, `LevelCount` | Mip range | `LevelCount`: `VK_REMAINING_MIP_LEVELS` |
| `BaseArrayLayer`, `LayerCount` | Array layer range | `LayerCount`: `VK_REMAINING_ARRAY_LAYERS` |
| `BaseZIndex`, `ZCount` | Depth slice range for 3D images | `ZCount`: `REMAINING_Z_INDICES` |

### Dumping options

Options go in the top-level `DumpingOptions` object (called `DumpResourcesOptions` in the legacy format). Option names are not case-sensitive. An unknown option or a value of the wrong type is an error in the
tree format, and only a warning in the legacy format.

| Option | Type | Default | Description |
|---|---|---|---|
| `Scale` | float > 0 | `1.0` | Scales dumped images. Values above 10 are capped at 10 |
| `ImageFormat` | `bmp` \| `png` | `bmp` | File format for dumped images |
| `OutputDir` | string | | Output directory. Overrides `--dump-resources-dir` |
| `DumpBeforeCommand` | bool | `false` | Also dump resources *before* each draw, dispatch and trace rays command, not only after |
| `DumpDepth` | bool | `false` | Dump the depth attachment of draw calls |
| `ColorAttachmentIndex` | int ≥ -1 | `-1` | Color attachment to dump for draw calls. `-1` dumps all of them |
| `DumpVertexIndexBuffer` | bool | `false` | Dump the vertex and index buffers of draw calls |
| `DumpAllDescriptors` | bool | `false` | Dump every descriptor referenced by the bound pipeline |
| `DumpAllImageSubresources` | bool | `false` | Dump every mip level and array layer of images |
| `DumpRawImages` | bool | `false` | Dump images unchanged, as raw binary files |
| `DumpSeparateAlpha` | bool | `false` | Write the alpha channel of images to a separate file |
| `DumpUnusedVertexBindings` | bool | `false` | Dump all bound vertex buffers, not only the ones the active pipeline uses |
| `JsonOutputPerCommand` | bool | `false` | Write one output json file per dumped command instead of one file for all commands |
| `BinaryFileCompressionType` | `none` \| `lz4` \| `zlib` \| `zstd` | `none` | Compression for binary files (`lz4` uses the block format) |
| `DumpBuildAccelerationStructuresInputBuffers` | bool | `false` | Dump the vertex, index, transform, AABB and instance buffers used by `vkCmdBuildAccelerationStructuresKHR` |

Example:

```json
{
  "SchemaVersion": "1.0",
  "DumpingOptions": {
      "Scale": 0.2,
      "ImageFormat": "png",
      "DumpAllDescriptors": true,
      "DumpAllImageSubresources": true,
      "DumpBuildAccelerationStructuresInputBuffers": true
  },
  "QueueSubmits": [
    { "Index": 466, "CommandBuffers": [ { "Index": 448, "TraceRays": [ 451 ] } ] }
  ]
}
```

## Running

Pass the input json to `gfxrecon-replay`, or to the Android app through `gfxrecon.py`:

| Parameter | Description |
|---|---|
| `--dump-resources <file>.json` | The [input json file](#input-json-file) |
| `--dump-resources-dir <dir>` | Output directory. The default is the current working directory (`/sdcard` on Android). The json `OutputDir` option overrides it |

All other settings are [dumping options](#dumping-options) in the input json.

## Output

### Json file output

Besides the dumped files, the replayer writes a json file that describes everything it dumped. The file is named
after the capture file, with `.gfxr` replaced by `_rd.json`. For example, `vulkanCapture.gfxr` gives
`vulkanCapture_rd.json`. If `JsonOutputPerCommand` is set, one file is written per command instead.

The file contains:

1. **`header`**: the capture file path, the GFXReconstruct and Vulkan versions, the
   [schema version](#rules) of the input json, and the options used.
2. **`drawCallCommands`**: for each draw call, the command parameters, the color and depth attachments, the
   vertex and index buffers (if requested), and the descriptors.
3. **`dispatchCommands`** and **`traceRaysCommands`**: for each command, the parameters, the output images and
   buffers, and the descriptors.
4. **`transferCommands`**: the dumped transfer commands and their destination resources.

Abbreviated example:

```json
[
{
  "header": {
    "vulkanVersion": "1.4.335",
    "gfxreconVersion": "1.0.5",
    "captureFile": "vulkanCapture.gfxr",
    "inputJsonSchemaVersion": "1.0",
    "DumpResourcesOptions": {
      "Scale": 1.0,
      "ImageFormat": "bmp",
      "DumpDepth": true,
      "DumpVertexIndexBuffer": true,
      "DumpAllDescriptors": true,
      ...
    }
  }
},
{
  "drawCallCommands": [
    {
      "drawIndex": 407,
      "beginCommandBufferIndex": 399,
      "queueSubmitIndex": 461,
      "parameters": {
        "drawCallType": "vkCmdDraw",
        "vertexCount": 24576,
        "instanceCount": 1,
        "firstVertex": 0,
        "firstInstance": 0
      },
      "colorAttachments": [
        {
          "imageId": 15,
          "format": "VK_FORMAT_B8G8R8A8_UNORM",
          "type": "VK_IMAGE_TYPE_2D",
          "aspect": "COLOR",
          "dimensions": [ 1280, 720, 1 ],
          "mipLevel": 0,
          "arrayLayer": 0,
          "file": "image_<hash>.bmp"
        }
      ],
      "depthAttachments": [ ... ],
      "vertexBuffers": [
        { "bufferId": 75, "vertexBufferBinding": 0, "file": "buffer_<hash>.bin" }
      ],
      "descriptors": {
        "vertex": [
          {
            "type": "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER",
            "set": 0, "binding": 2, "arrayIndex": 0,
            "descriptor": { "bufferId": 79, "file": "buffer_<hash>.bin" }
          }
        ],
        "fragment": [ ... ]
      }
    }
  ]
},
{
  "dispatchCommands": [
    {
      "dispatchIndex": 294,
      "beginCommandBufferIndex": 290,
      "queueSubmitIndex": 723,
      "parameters": {
        "dispatchType": "vkCmdDispatch",
        "groupCountX": 96, "groupCountY": 1, "groupCountZ": 1
      },
      "outputs": {
        "buffers": [
          {
            "type": "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER",
            "set": 0, "binding": 0, "arrayIndex": 0,
            "bufferId": 75,
            "file": "buffer_<hash>.bin"
          }
        ]
      },
      "descriptors": [ ... ]
    }
  ]
}
]
```

### Dumped files

* **Images** are written in the selected `ImageFormat`. An image is written as a raw `.bin` file instead if its
  format can't be converted to 32-bit RGBA, or if `DumpRawImages` is set.
* **Buffers** are always written as raw `.bin` files, compressed if `BinaryFileCompressionType` is set.
* **Acceleration structures** are written as `BLAS_<hash>.bin` / `TLAS_<hash>.bin`.

File names are built from a hash of what was dumped (the command, binding, subresource and so on), not from
readable indices. Use the `file` entries in the output json to find the file for a given resource.

## Appendix: legacy input json format

The format below came before the tree format. It is still accepted, and it is recognized by its top-level
`BeginCommandBuffer` key. Instead of a tree, a request is a set of **parallel arrays matched by position**: entry
`i` of `BeginCommandBuffer` goes with entry `i` of `QueueSubmit`, `Draw`, `RenderPass`, `Dispatch`, `TraceRays`,
`Transfer` and `ExecuteCommands`. The options object is named `DumpResourcesOptions`, and the file has no
`SchemaVersion`.

| Key | Dimensions | Meaning |
|---|---|---|
| `BeginCommandBuffer`, `QueueSubmit` | 1D | One entry per command buffer. Repeat the submit index if several command buffers share a submission |
| `Draw`, `Dispatch`, `TraceRays`, `Transfer` | 2D | `[command buffer][command]` |
| `RenderPass` | 3D | `[command buffer][render pass][begin, nextSubpass..., end]` |
| `ExecuteCommands` | 3D | `[command buffer][...][vkCmdExecuteCommands index, secondary's BeginCommandBuffer index]` |

The [minimal request](#minimal-request) written in the legacy format:

```json
{
    "BeginCommandBuffer": [ 301 ],
    "Draw": [ [ 307, 308, 309, 310, 311, 312 ] ],
    "RenderPass": [ [ [ 302, 313 ] ] ],
    "QueueSubmit": [ 315 ]
}
```

Two command buffers, one with two render passes (the first has two subpasses):

```json
{
    "BeginCommandBuffer": [ 10, 11 ],
    "Draw":        [ [ 13, 14, 16, 17, 20, 21, 22, 23 ], [ 27, 28, 29 ] ],
    "RenderPass":  [ [ [ 12, 15, 18 ], [ 19, 24 ] ],     [ [ 26, 30 ] ] ],
    "QueueSubmit": [ 50, 51 ]
}
```

A draw call in secondary `754`, run by `vkCmdExecuteCommands` `3949` from primary `736`. Each command buffer
gets its own entry, and the primary holds the render pass and the `ExecuteCommands` pair:

```json
{
    "BeginCommandBuffer": [ 754, 736 ],
    "Draw":            [ [ 761 ], [ ] ],
    "RenderPass":      [ [ [ ] ], [ [ 3948, 3950 ] ] ],
    "ExecuteCommands": [ [ [ ] ], [ [ 3949, 754 ] ] ],
    "QueueSubmit":     [ 3952, 3952 ]
}
```

Transfer commands work the same way, as `"Transfer": [ [ 266, 267 ] ]`. State-setup meta commands use the special
index `0` for both `BeginCommandBuffer` and `QueueSubmit`:

```json
{
    "BeginCommandBuffer": [ 0 ],
    "Transfer": [ [ 266, 267 ] ],
    "QueueSubmit": [ 0 ]
}
```
