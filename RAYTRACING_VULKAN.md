# Replay
## Problem
Acceleration structures have specific memory requirements for the buffers they use.
Also, commands operating on acceleration structures will refer to buffers by device addresses rather than handles.
These requirements and addresses are typically queried by the captured app and used as parameters later on.
Commands containing such parameters can fail to replay on different platforms due to differences in required sizes and alignments.
Current solution for handling device addresses using DEVICE_ADDRESS_CAPTURE_REPLAY does not guarantee portability.

## Proposed solution

[VulkanAccelerationStructureBuilder::CmdBuildAccelerationStructures](https://github.com/bartosz-muszarski-arm/gfxreconstruct/blob/7b19997f14602ad8944868c1a13aac5aeb94b5f0/framework/decode/vulkan_acceleration_structure_builder.cpp#L598)

```mermaid
sequenceDiagram
   replay ->> acceleration_structure_builder: CmdBuildAccelerationStructures
   acceleration_structure_builder ->> vulkan: GetAccelerationStructureSizeInfo
   vulkan -->> acceleration_structure_builder: VkAccelerationStructureBuildSizesInfoKHR
   acceleration_structure_builder ->> vulkan: CreateBuffer (accelerationStructureSize)
   acceleration_structure_builder ->> vulkan: CreateAccelerationStructure
   acceleration_structure_builder ->> vulkan: CreateBuffer (buildScratchSize)
```

### Device address
Device addresses can be replaced at runtime with correct values in expected calls.
The proposal is based on mapping the captured device address to a buffer and retrieving the device address of that buffer at runtime.
Addresses with offsets can be handled as well by searching based on known buffer addresses and sizes, then applying the same offset to found address.
Buffers containing device addresses can be written to at any time, so for device operations - AS build commands specifically - the address replacement is delayed until the command buffer containing such commands is queued for execution.

### Buffer sizes
Use similar approach to rebind allocator.
Once AS build command is queued for execution:

1. Query for correct buffer sizes

2. Create new acceleration structure and necessary buffers with correct sizes using rebind allocator

3. Replace parameters in the build command with the addresses of new buffers and the destination AS 

Any reference to the acceleration structures built originally - handles and device addresses -  needs to be replaced.

#### Known issues
It's not always possible to replace addresses properly. Device addresses can be set with MapMemory/FillMemoryCommand and used in shaders.
WIP: scan buffers used in shaders for known device addresses at capture time, insert metacommand signaling the replay to update device address at found location at runtime.

# Trimming

## Problem
Currently acceleration structures are saved to memory by state tracker and restored on replay.
This approach does not guarantee portability, as the deserialized acceleration structure may be incompatible with the replay device.

## Proposed solution
Acceleration structures can be recreated using the most recent build/copy/update commands.
Since these commands require handling on the replay side anyway to account for different sizes and alignment, this would be better handled by separate metacommands:
```
kVulkanBuildAccelerationStructuresCommand = 28,
kVulkanCopyAccelerationStructuresCommand  = 29
```

These metacommands contain data necessary to build/copy acceleration structures and are consumed by Acceleration structure builder on replay:
```
void VulkanAccelerationStructureBuilder::ProcessBuildVulkanAccelerationStructuresMetaCommand(
   uint32_t                                                      info_count,
   VkAccelerationStructureBuildGeometryInfoKHR*                  geometry_infos,
   VkAccelerationStructureBuildRangeInfoKHR**                    range_infos,
   std::vector<std::vector<VkAccelerationStructureInstanceKHR>>& instance_buffers_data)

void VulkanAccelerationStructureBuilder::ProcessCopyVulkanAccelerationStructuresMetaCommand(
   uint32_t info_count, VkCopyAccelerationStructureInfoKHR* copy_infos)

```
### Known issues
#### Portable/original trimming switch
Additional capture option is introduced:
experimental_raytracing_fastforwarding
Allowing to switch between the original trimming strategy and the proposed approach.

#### Capturing internal calls
As the functionalities required for portable replay use vulkan api as well, they're captured while trimming.
A redundant set of calls will be traced and consumed in the replayer, creating performance and memory overhead.
```
TODO: expose an api from the replayer to the capture layer signaling internal handling.
```

