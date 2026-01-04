/*
** Copyright (c) 2024-2025 LunarG, Inc.
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

#ifndef GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMMON_H
#define GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMMON_H

#include "decode/vulkan_device_address_tracker.h"
#include "decode/common_object_info_table.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_as.h"
#include "decode/vulkan_replay_dump_resources_delegate_dumped_resources.h"
#include "decode/vulkan_replay_options.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/logging.h"
#include "util/defines.h"
#include "util/options.h"

#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using CommandBufferIterator = std::vector<VkCommandBuffer>::const_iterator;

template <typename T>
static bool IsInsideRange(const std::vector<T>& vec, T value)
{
    if (!vec.size())
    {
        return false;
    }
    else
    {
        return (value >= *(vec.begin()) && value <= *(vec.end() - 1));
    }
}

enum DumpedImageFormat
{
    kFormatBMP,
    KFormatPNG,
    KFormatRaw
};

struct MinMaxVertexIndex
{
    uint32_t min = 0;
    uint32_t max = 0;
};

using BoundDescriptorSets = std::unordered_map<uint32_t, VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo>;

DumpedImageFormat GetDumpedImageFormat(const VulkanDeviceInfo*              device_info,
                                       const graphics::VulkanDeviceTable*   device_table,
                                       const graphics::VulkanInstanceTable* instance_table,
                                       const CommonObjectInfoTable&         object_info_table,
                                       VkFormat                             src_format,
                                       VkImageTiling                        src_image_tiling,
                                       VkImageType                          type,
                                       util::ScreenshotFormat               image_file_format,
                                       bool                                 dump_raw = false);

const char* ImageFileExtension(DumpedImageFormat image_format);

VkResult CreateVkImage(const CommonObjectInfoTable&            object_info_table,
                       const graphics::VulkanDeviceTable*      device_table,
                       const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                       const VulkanImageInfo*                  image_info,
                       VkImage*                                new_image,
                       VkDeviceMemory*                         new_image_memory);

uint32_t VkIndexTypeToBytes(VkIndexType type);

MinMaxVertexIndex FindMinMaxVertexIndices(const std::vector<uint8_t>& index_data,
                                          uint32_t                    index_count,
                                          uint32_t                    first_index,
                                          int32_t                     vertex_offset,
                                          VkIndexType                 type);

ImageDumpResult CanDumpImage(const graphics::VulkanInstanceTable* instance_table,
                             VkPhysicalDevice                     phys_dev,
                             const VulkanImageInfo*               image_info);

// Fetch image from the GPU into host memory
VkResult DumpImage(DumpedImage&                         dumped_image,
                   VkImageLayout                        layout,
                   float                                scale,
                   bool                                 dump_image_raw,
                   const VkImageSubresourceRange&       subresource_range,
                   DumpedImageHostData&                 data,
                   const VulkanDeviceInfo*              device_info,
                   const graphics::VulkanDeviceTable*   device_table,
                   const graphics::VulkanInstanceTable* instance_table,
                   const CommonObjectInfoTable&         object_info_table);

// Fetch a buffer from the GPU into host memory
VkResult DumpBuffer(const DumpedBuffer&                  buffer,
                    DumpedHostData&                      data,
                    const VulkanDeviceInfo*              device_info,
                    const graphics::VulkanDeviceTable*   device_table,
                    const graphics::VulkanInstanceTable* instance_table,
                    const CommonObjectInfoTable&         object_info_table);

// Fetch an acceleration structure from the GPU into host memory
VkResult DumpAccelerationStructure(DumpedAccelerationStructure&                      dumped_as,
                                   AccelerationStructureDumpedHostData&              dumped_as_data,
                                   AccelerationStructureDumpResourcesContext*        as_context,
                                   const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                                   const VulkanDeviceInfo*                           device_info,
                                   const graphics::VulkanDeviceTable&                device_table,
                                   const CommonObjectInfoTable&                      object_info_table,
                                   const graphics::VulkanInstanceTable&              instance_table,
                                   const VulkanPerDeviceAddressTrackers&             address_trackers);

std::string ShaderStageToStr(VkShaderStageFlagBits shader_stage);

std::string ImageAspectToStr(VkImageAspectFlagBits aspect);

std::string FormatToStr(VkFormat format);

std::string IndexTypeToStr(VkIndexType type);

VkResult CreateVkBuffer(VkDeviceSize                            size,
                        const graphics::VulkanDeviceTable&      device_table,
                        VkDevice                                parent_device,
                        const VkBaseInStructure*                pNext,
                        const VkBaseInStructure*                allocate_memory_info_pNext,
                        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                        VkBufferUsageFlags                      usage_flags,
                        VkBuffer*                               new_buffer,
                        VkDeviceMemory*                         new_memory);

std::string ShaderStageFlagsToString(VkShaderStageFlags flags);

void ShaderStageFlagsToStageNames(VkShaderStageFlags flags, std::vector<std::string>& stage_names);

std::vector<VkPipelineBindPoint> ShaderStageFlagsToPipelineBindPoints(VkShaderStageFlags flags);

uint32_t FindTransferQueueFamilyIndex(const VulkanDeviceInfo::EnabledQueueFamilyFlags& families);

uint32_t FindComputeQueueFamilyIndex(const VulkanDeviceInfo::EnabledQueueFamilyFlags& families);

using FindQueueFamilyIndex_fp = uint32_t(const VulkanDeviceInfo::EnabledQueueFamilyFlags&);

struct TemporaryCommandBuffer
{
    TemporaryCommandBuffer() = default;
    TemporaryCommandBuffer(const TemporaryCommandBuffer& other)
    {
        device_info    = other.device_info;
        device_table   = other.device_table;
        command_pool   = other.command_pool;
        command_buffer = other.command_buffer;
        queue          = other.queue;
    }

    const VulkanDeviceInfo*            device_info{ nullptr };
    const graphics::VulkanDeviceTable* device_table{ nullptr };

    VkCommandPool   command_pool   = VK_NULL_HANDLE;
    VkCommandBuffer command_buffer = VK_NULL_HANDLE;
    VkQueue         queue          = VK_NULL_HANDLE;
};

VkResult CreateAndBeginCommandBuffer(FindQueueFamilyIndex_fp*           queue_finder_fp,
                                     const VulkanDeviceInfo*            device_info,
                                     const graphics::VulkanDeviceTable& device_table,
                                     TemporaryCommandBuffer&            cmd_buf_objects);

VkResult SubmitAndDestroyCommandBuffer(const TemporaryCommandBuffer& cmd_buf_objects);

// Inject a CmdCopyBuffer(command_buffer, src, dst, regions.count(), regions.size()) into the provided command buffer
// followed by the appropriate pipeline barrier
void CopyBufferAndBarrier(VkCommandBuffer                    command_buffer,
                          const graphics::VulkanDeviceTable& device_table,
                          VkBuffer                           src,
                          VkBuffer                           dst,
                          const std::vector<VkBufferCopy>&   regions,
                          VkAccessFlags src_access_mask = VK_ACCESS_TRANSFER_WRITE_BIT | VK_ACCESS_MEMORY_WRITE_BIT,
                          VkAccessFlags dst_access_mask = VK_ACCESS_TRANSFER_READ_BIT | VK_ACCESS_HOST_READ_BIT,
                          VkPipelineStageFlags src_stage_mask = VK_PIPELINE_STAGE_TRANSFER_BIT,
                          VkPipelineStageFlags dst_stage_mask = VK_PIPELINE_STAGE_TRANSFER_BIT |
                                                                VK_PIPELINE_STAGE_HOST_BIT);

static constexpr VkImageSubresourceRange FilterImageSubresourceRange(const VkImageSubresourceRange& subresource_range,
                                                                     const VulkanImageInfo*         image_info)
{
    GFXRECON_ASSERT(image_info != nullptr);

    VkImageSubresourceRange modified_subresource_range;
    modified_subresource_range.aspectMask = subresource_range.aspectMask;

    // Handle base mip level and count
    if (subresource_range.baseMipLevel > image_info->level_count)
    {
        modified_subresource_range.baseMipLevel = 0;
    }
    else
    {
        modified_subresource_range.baseMipLevel = subresource_range.baseMipLevel;
    }

    if (subresource_range.levelCount == VK_REMAINING_MIP_LEVELS)
    {
        modified_subresource_range.levelCount = image_info->level_count - modified_subresource_range.baseMipLevel;
    }
    else
    {
        modified_subresource_range.levelCount = std::min(image_info->level_count, subresource_range.levelCount);
    }

    // Handle base array layer and count
    if (subresource_range.baseArrayLayer > image_info->layer_count)
    {
        modified_subresource_range.baseArrayLayer = 0;
    }
    else
    {
        modified_subresource_range.baseArrayLayer = subresource_range.baseArrayLayer;
    }

    if (subresource_range.layerCount == VK_REMAINING_ARRAY_LAYERS)
    {
        modified_subresource_range.layerCount = image_info->layer_count - modified_subresource_range.baseArrayLayer;
    }
    else
    {
        modified_subresource_range.layerCount = std::min(image_info->layer_count, subresource_range.layerCount);
    }

    return modified_subresource_range;
}

bool CullDescriptor(CommandImageSubresourceIterator cmd_subresources_entry,
                    uint32_t                        desc_set,
                    uint32_t                        binding,
                    uint32_t                        array_index,
                    VkImageSubresourceRange*        subresource_range = nullptr);

class VulkanDumpResourcesDelegate;
class DefaultVulkanDumpResourcesDelegate;

enum class DumpResourcesCommandBufferLevel
{
    kUnknown = 0,
    kPrimary,
    kSecondary
};

#define DEPTH_ATTACHMENT ~0

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMMON_H */
