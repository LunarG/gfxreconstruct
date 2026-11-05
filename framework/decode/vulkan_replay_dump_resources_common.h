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

#include "decode/vulkan_replay_device_context.h"
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
#include "util/compressor.h"
#include "util/logging.h"
#include "util/defines.h"
#include "util/options.h"

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using CommandBufferIterator = std::vector<VkCommandBuffer>::const_iterator;

// Reports dump-resources progress on the active remote channel; the status frame can't advance during a submit's
// dumps. Replay thread only.
class DumpResourcesProgress
{
  public:
    // Set the total and reset progress; emits nothing.
    static void Begin(uint64_t total);

    // Emit the start message (0 of total) the first time it's called after Begin(); later calls are no-ops.
    static void Announce();

    // Advance the completed count by one and report it.
    static void Advance();

  private:
    static uint64_t total_;
    static uint64_t completed_;
    static bool     announced_;
};

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

ImageDumpResult CanDumpImage(const graphics::VulkanInstanceTable*              instance_table,
                             VkPhysicalDevice                                  phys_dev,
                             const VulkanImageInfo*                            image_info,
                             const graphics::VulkanDevicePropertyFeatureInfo&  physical_device_features_info,
                             const graphics::VulkanDeviceVersionExtensionInfo& device_version_extension_info);

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
                                   const VulkanPerDeviceContexts&                    device_contexts,
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

// Defined in vulkan_replay_dump_resources_windows.h
class DumpingContextWindows;
struct WindowSlot;

// Base class of the dumping contexts.
//
// Each dumping context is assigned its corresponding DumpingContextWindows. The base also holds what every such context
// needs: the (BeginCommandBuffer, QueueSubmit) pair it was created for, the original command buffer, the dispatch
// tables of its device and what the resources are dumped with.
//
// A dumping context owns the slots of the commands it knows: while the command buffer is recorded
// it tracks the state it needs, records its target commands into the clone taking work and tells the windows where a
// window ends. When the command buffer is submitted the windows run and call the owner of each slot back, through the
// virtual functions declared here, to dump it.
class DumpingContextBase
{
  public:
    // windows is the execution of the command buffer this context dumps commands from.
    DumpingContextBase(std::shared_ptr<DumpingContextWindows>            windows,
                       Index                                             bcb_index,
                       Index                                             qs_index,
                       CommonObjectInfoTable&                            object_info_table,
                       const VulkanReplayOptions&                        options,
                       VulkanDumpResourcesDelegate&                      delegate,
                       const util::Compressor*                           compressor,
                       const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                       const VulkanPerDeviceContexts&                    device_contexts);

    virtual ~DumpingContextBase() = default;

    // Stores the original command buffer and the dispatch tables of its device. Contexts with more to set up
    // override it and call this one first.
    virtual VkResult BeginCommandBuffer(const VulkanCommandBufferInfo*             orig_cmd_buf_info,
                                        const graphics::VulkanInjectedDeviceCalls& dev_table,
                                        const graphics::VulkanInstanceTable*       inst_table);

    VkCommandBuffer GetOriginalCommandBuffer() const
    {
        return original_command_buffer_info_ != nullptr ? original_command_buffer_info_->handle : VK_NULL_HANDLE;
    }

    // Dumps the resources of the slot's command. Called right after the window with index window_index has
    // executed: the one that ends with the command or, with --dump-resources-before, first the one that ends right
    // before it (even index) and then the one that holds the command (odd index).
    virtual VkResult DumpSlot(const WindowSlot& slot,
                              size_t            window_index,
                              VkQueue           queue,
                              Index             submit_info_index,
                              Index             submit_info_cmd_buf_index) = 0;

    // Forgets what was dumped during a queue submission, in case the command buffer is submitted again
    virtual void ResetDumpedResources() = 0;

    // Called on the owner of a primary from vkCmdExecuteCommands, before the slots of the secondary are taken
    // over: hands the state a secondary can inherit from the primary down to the secondary's owner of the same kind.
    virtual void PrepareSecondary(DumpingContextBase& secondary_owner) = 0;

    // Called on the owner of a primary once per slot of an executed secondary, in the secondary's slot order: shares
    // the secondary owner's parameters of the slot's command with this owner, records under which window of the
    // primary and which vkCmdExecuteCommands this execution of the command runs, and finalizes the primary's
    // window (two windows with --dump-resources-before).
    virtual void ExecuteSecondarySlot(DumpingContextBase& secondary_owner,
                                      const WindowSlot&   secondary_slot,
                                      Index               execute_cmd_index,
                                      Index               command_buffer_execute_index) = 0;

  protected:
    // The execution of the command buffer: the clones this context records into and whose slots it owns
    std::shared_ptr<DumpingContextWindows> windows_;

    const VulkanCommandBufferInfo* original_command_buffer_info_;
    Index                          bcb_index_;
    Index                          qs_index_;

    VulkanDumpResourcesDelegate& delegate_;
    const VulkanReplayOptions&   options_;
    const util::Compressor*      compressor_;

    graphics::VulkanInjectedDeviceCalls     device_table_;
    const graphics::VulkanInstanceTable*    instance_table_;
    CommonObjectInfoTable&                  object_info_table_;
    const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props_;

    const DumpResourcesAccelerationStructuresContext& acceleration_structures_context_;

    const VulkanPerDeviceContexts& device_contexts_;
};

GFXRECON_END_NAMESPACE(gfxrecon) GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_COMMON_H */
