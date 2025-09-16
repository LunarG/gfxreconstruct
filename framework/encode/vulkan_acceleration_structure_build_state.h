/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_ACCELERATION_STRUCTURE_BUILD_STATE_H
#define GFXRECON_ENCODE_VULKAN_ACCELERATION_STRUCTURE_BUILD_STATE_H

#include "util/defines.h"
#include "format/format.h"
#include "vulkan/vulkan.h"
#include "vulkan/vulkan_core.h"
#include <optional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

namespace vulkan_wrappers
{
struct DeviceWrapper;
}

struct AccelerationStructureInputBuffer
{
    // Required data to correctly create a buffer
    VkBuffer                        handle{ VK_NULL_HANDLE };
    format::HandleId                handle_id{ format::kNullHandleId };
    vulkan_wrappers::DeviceWrapper* bind_device{ nullptr };
    uint32_t                        queue_family_index{ 0 };
    VkDeviceSize                    created_size{ 0 };
    VkBufferUsageFlags              usage{ 0 };

    bool destroyed{ false };

    VkDeviceAddress capture_address{ 0 };
    VkDeviceAddress actual_address{ 0 };

    std::vector<uint8_t> bytes;

    VkMemoryRequirements memory_requirements{};
    format::HandleId     bind_memory{};
    VkDeviceMemory       bind_memory_handle{ VK_NULL_HANDLE };
};

struct AccelerationStructureKHRBuildCommandData
{
    VkAccelerationStructureBuildGeometryInfoKHR                            geometry_info;
    std::unique_ptr<uint8_t[]>                                             geometry_info_memory;
    std::vector<VkAccelerationStructureBuildRangeInfoKHR>                  build_range_infos;
    std::unordered_map<format::HandleId, AccelerationStructureInputBuffer> input_buffers;
};

struct AccelerationStructureCopyCommandData
{
    format::HandleId                   device;
    VkCopyAccelerationStructureInfoKHR info;
};

struct AccelerationStructureWritePropertiesCommandData
{
    format::HandleId device;
    VkQueryType      query_type;
};

struct AccelerationStructureBuildState
{
    VkAccelerationStructureTypeKHR type;

    std::optional<AccelerationStructureKHRBuildCommandData>        latest_build_command{ std::nullopt };
    std::optional<AccelerationStructureCopyCommandData>            latest_copy_command{ std::nullopt };
    std::optional<AccelerationStructureWritePropertiesCommandData> latest_write_properties_command{ std::nullopt };
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif // GFXRECON_ENCODE_VULKAN_ACCELERATION_STRUCTURE_BUILD_STATE_H
