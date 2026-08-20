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
#include "decode/vulkan_temporary_objects.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_injected_calls.h"
#include "graphics/vulkan_util.h"
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

using BoundDescriptorSets = std::map<uint32_t, VulkanDescriptorSetInfo::VulkanDescriptorBindingsInfo>;

const char* ImageFileExtension(DumpedImageFormat image_format);

VkResult CreateVkImage(const CommonObjectInfoTable&               object_info_table,
                       const graphics::VulkanInjectedDeviceCalls& device_table,
                       const VkPhysicalDeviceMemoryProperties*    replay_device_phys_mem_props,
                       const VulkanImageInfo*                     image_info,
                       VkImage*                                   new_image,
                       VkDeviceMemory*                            new_image_memory);

uint32_t VkIndexTypeToBytes(VkIndexType type);

MinMaxVertexIndex FindMinMaxVertexIndices(const std::vector<uint8_t>& index_data,
                                          uint32_t                    index_count,
                                          uint32_t                    first_index,
                                          int32_t                     vertex_offset,
                                          VkIndexType                 type);

ImageDumpResult CanDumpImage(const graphics::VulkanInstanceTable*             instance_table,
                             VkPhysicalDevice                                 phys_dev,
                             const VulkanImageInfo*                           image_info,
                             const graphics::VulkanDevicePropertyFeatureInfo& physical_device_features_info);

// Fetch image from the GPU into host memory
VkResult DumpImage(DumpedImage&                               dumped_image,
                   VkImageLayout                              layout,
                   float                                      scale,
                   bool                                       dump_image_raw,
                   const ImageSubresourceRanges&              subresource_range,
                   DumpedImageHostData&                       data,
                   const VulkanDeviceInfo*                    device_info,
                   const graphics::VulkanInjectedDeviceCalls& device_table,
                   const graphics::VulkanInstanceTable*       instance_table,
                   const CommonObjectInfoTable&               object_info_table);

// Fetch a buffer from the GPU into host memory
VkResult DumpBuffer(const DumpedBuffer&                        buffer,
                    DumpedHostData&                            data,
                    const VulkanDeviceInfo*                    device_info,
                    const graphics::VulkanInjectedDeviceCalls& device_table,
                    const graphics::VulkanInstanceTable*       instance_table,
                    const CommonObjectInfoTable&               object_info_table);

// Fetch an acceleration structure from the GPU into host memory
VkResult DumpAccelerationStructure(DumpedAccelerationStructure&                      dumped_as,
                                   AccelerationStructureDumpedHostData&              dumped_as_data,
                                   AccelerationStructureDumpResourcesContext*        as_context,
                                   const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                                   const VulkanDeviceInfo*                           device_info,
                                   const graphics::VulkanInjectedDeviceCalls&        device_table,
                                   const CommonObjectInfoTable&                      object_info_table,
                                   const graphics::VulkanInstanceTable&              instance_table,
                                   const VulkanPerDeviceAddressTrackers&             address_trackers,
                                   bool                                              use_capture_addresses = false);

std::string ShaderStageToStr(VkShaderStageFlagBits shader_stage);

std::string ImageAspectToStr(VkImageAspectFlagBits aspect);

std::string FormatToStr(VkFormat format);

std::string IndexTypeToStr(VkIndexType type);

VkResult CreateVkBuffer(VkDeviceSize                               size,
                        const graphics::VulkanInjectedDeviceCalls& device_table,
                        VkDevice                                   parent_device,
                        const VkBaseInStructure*                   pNext,
                        const VkBaseInStructure*                   allocate_memory_info_pNext,
                        const VkPhysicalDeviceMemoryProperties*    replay_device_phys_mem_props,
                        VkBufferUsageFlags                         usage_flags,
                        VkBuffer*                                  new_buffer,
                        VkDeviceMemory*                            new_memory);

std::string ShaderStageFlagsToString(VkShaderStageFlags flags);

void ShaderStageFlagsToStageNames(VkShaderStageFlags flags, std::vector<std::string>& stage_names);

// Submit a single VkSubmitInfo2 to the queue using vkQueueSubmit2 when it is available. On devices that do not support
// synchronization2, the submit info is converted into a VkSubmitInfo and submitted via vkQueueSubmit. The
// dump-resources submissions are serialized with host fence waits, so the wait-stage masks lost during down-conversion
// do not affect correctness.
VkResult SubmitInfo2OnQueue(const graphics::VulkanInjectedDeviceCalls&        device_table,
                            const graphics::VulkanDeviceVersionExtensionInfo& device_version_extension_info,
                            VkQueue                                           queue,
                            const VkSubmitInfo2&                              submit_info_2,
                            VkFence                                           fence);

// Inject a CmdCopyBuffer(command_buffer, src, dst, regions.count(), regions.size()) into the provided command buffer
// followed by the appropriate pipeline barrier
void CopyBufferAndBarrier(VkCommandBuffer                            command_buffer,
                          const graphics::VulkanInjectedDeviceCalls& device_table,
                          VkBuffer                                   src,
                          VkBuffer                                   dst,
                          const std::vector<VkBufferCopy>&           regions,
                          VkAccessFlags src_access_mask = VK_ACCESS_TRANSFER_WRITE_BIT | VK_ACCESS_MEMORY_WRITE_BIT,
                          VkAccessFlags dst_access_mask = VK_ACCESS_TRANSFER_READ_BIT | VK_ACCESS_HOST_READ_BIT,
                          VkPipelineStageFlags src_stage_mask = VK_PIPELINE_STAGE_TRANSFER_BIT,
                          VkPipelineStageFlags dst_stage_mask = VK_PIPELINE_STAGE_TRANSFER_BIT |
                                                                VK_PIPELINE_STAGE_HOST_BIT);

bool ValidateImageSubresourceRange(const ImageSubresourceRanges& requested_subresource_range,
                                   ImageSubresourceRanges&       modified_subresource_range,
                                   const VulkanImageInfo*        image_info);

void CullDescriptors(const CommonObjectInfoTable&             object_info_table_,
                     const BoundDescriptorSets&               call_referenced_descriptors,
                     const DescriptorImageSubresourcesVector* requested_descriptors,
                     decode::Index                            call_index,
                     bool                                     dump_all_image_subresources,
                     DescriptorImageSubresourcesVector&       descriptors_to_dump);

class VulkanDumpResourcesDelegate;
class DefaultVulkanDumpResourcesDelegate;

enum class DumpResourcesCommandBufferLevel
{
    kUnknown = 0,
    kPrimary,
    kSecondary
};

struct SecondaryIdentifiers
{
    // vkCmdExecuteCommands block index
    Index execute_cmds_index{ UNDEFINED_INDEX };

    // Secondary's command buffer index inside pCommandBuffers
    Index execute_cmds_cmd_buf_index{ UNDEFINED_INDEX };
};

#define DEPTH_ATTACHMENT ~0

GFXRECON_END_NAMESPACE(gfxrecon) GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMMON_H */
