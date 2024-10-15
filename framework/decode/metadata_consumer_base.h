/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_DECODE_METADATA_CONSUMER_BASE_H
#define GFXRECON_DECODE_METADATA_CONSUMER_BASE_H

#include "util/defines.h"
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// @brief Base class defining the virtual functions that consumers need to
/// implement to handle metacommands.
class MetadataConsumerBase
{
  public:
    virtual void Process_ExeFileInfo(util::filepath::FileInfo& info_record) {}
    virtual void ProcessDisplayMessageCommand(const std::string& message) {}
    virtual void ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) {}
    virtual void
    ProcessFillMemoryResourceValueCommand(const format::FillMemoryResourceValueCommandHeader& command_header,
                                          const uint8_t*                                      data)
    {}
    virtual void ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height) {}
    virtual void
    ProcessResizeWindowCommand2(format::HandleId surface_id, uint32_t width, uint32_t height, uint32_t pre_transform)
    {}
    virtual void ProcessCreateHardwareBufferCommand(format::HandleId                                    device_id,
                                                    format::HandleId                                    queue_id,
                                                    format::HandleId                                    memory_id,
                                                    uint64_t                                            buffer_id,
                                                    uint32_t                                            format,
                                                    uint32_t                                            width,
                                                    uint32_t                                            height,
                                                    uint32_t                                            stride,
                                                    uint64_t                                            usage,
                                                    uint32_t                                            layers,
                                                    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
    {}
    virtual void ProcessDestroyHardwareBufferCommand(uint64_t buffer_id) {}
    virtual void ProcessCreateHeapAllocationCommand(uint64_t allocation_id, uint64_t allocation_size) {}
    virtual void ProcessSetDevicePropertiesCommand(format::HandleId   physical_device_id,
                                                   uint32_t           api_version,
                                                   uint32_t           driver_version,
                                                   uint32_t           vendor_id,
                                                   uint32_t           device_id,
                                                   uint32_t           device_type,
                                                   const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                   const std::string& device_name)
    {}
    virtual void ProcessSetDeviceMemoryPropertiesCommand(format::HandleId physical_device_id,
                                                         const std::vector<format::DeviceMemoryType>& memory_types,
                                                         const std::vector<format::DeviceMemoryHeap>& memory_heaps)
    {}
    virtual void
    ProcessSetOpaqueAddressCommand(format::HandleId device_id, format::HandleId object_id, uint64_t address)
    {}
    virtual void ProcessSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                               format::HandleId pipeline_id,
                                                               size_t           data_size,
                                                               const uint8_t*   data)
    {}
    virtual void ProcessSetSwapchainImageStateCommand(format::HandleId device_id,
                                                      format::HandleId swapchain_id,
                                                      uint32_t         last_presented_image,
                                                      const std::vector<format::SwapchainImageStateInfo>& image_state)
    {}
    virtual void
    ProcessBeginResourceInitCommand(format::HandleId device_id, uint64_t max_resource_size, uint64_t max_copy_size)
    {}
    virtual void ProcessEndResourceInitCommand(format::HandleId device_id) {}
    virtual void ProcessInitBufferCommand(format::HandleId device_id,
                                          format::HandleId buffer_id,
                                          uint64_t         data_size,
                                          const uint8_t*   data)
    {}
    virtual void ProcessInitImageCommand(format::HandleId             device_id,
                                         format::HandleId             image_id,
                                         uint64_t                     data_size,
                                         uint32_t                     aspect,
                                         uint32_t                     layout,
                                         const std::vector<uint64_t>& level_sizes,
                                         const uint8_t*               data)
    {}
    virtual void ProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                               const uint8_t*                              data)
    {}
    virtual void ProcessExecuteBlocksFromFile(uint32_t           n_blocks,
                                              int64_t            offset,
                                              const std::string& filename)
    {}

    virtual void SetCurrentBlockIndex(uint64_t block_index) {}

    virtual void ProcessBuildVulkanAccelerationStructuresMetaCommand(
        format::HandleId                                                           device_id,
        uint32_t                                                                   info_count,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* geometry_infos,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   range_infos,
        std::vector<std::vector<VkAccelerationStructureInstanceKHR>>&              instance_buffers_data)
    {}

    virtual void ProcessCopyVulkanAccelerationStructuresMetaCommand(
        format::HandleId device_id, StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* copy_infos)
    {}

    virtual void ProcessVulkanAccelerationStructuresWritePropertiesMetaCommand(
        format::HandleId device_id, VkQueryType query_type, format::HandleId acceleration_structure_id)
    {}

  protected:
    uint64_t block_index_ = 0;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_METADATA_CONSUMER_BASE_H
