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

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_delegate.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "format/format.h"
#include "graphics/vulkan_resources_util.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "decode/vulkan_replay_dump_resources_transfer.h"
#include "util/logging.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "util/platform.h"
#include "util/to_string.h"

#include <cstdint>
#include <tuple>
#include <utility>
#include <vector>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

TransferDumpingContext::TransferDumpingContext(
    const CommandIndices*                             transfer_indices,
    CommonObjectInfoTable&                            object_info_table,
    const graphics::InstanceDispatchTablesMap&        instance_tables,
    const graphics::DeviceDispatchTablesMap&          device_tables,
    const VulkanReplayOptions&                        options,
    VulkanDumpResourcesDelegate&                      delegate,
    const VulkanPerDeviceAddressTrackers&             address_trackers,
    const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
    const util::Compressor*                           compressor) :
    object_info_table_(object_info_table),
    instance_tables_(instance_tables), device_tables_(device_tables), options_(options), delegate_(delegate),
    address_trackers_(address_trackers), acceleration_structures_context_(acceleration_structures_context),
    compressor_(compressor), device_table_(nullptr), device_info_(nullptr)
{
    if (transfer_indices != nullptr)
    {
        transfer_indices_ = *transfer_indices;
    }
}

bool TransferDumpingContext::MustDumpTransfer(uint64_t index) const
{
    return std::find(transfer_indices_.begin(), transfer_indices_.end(), index) != transfer_indices_.end();
}

void TransferDumpingContext::GetDispatchTables(format::HandleId device_id)
{
    device_info_ = object_info_table_.GetVkDeviceInfo(device_id);
    GFXRECON_ASSERT(device_info_ != nullptr);

    auto dev_table = device_tables_.find(graphics::GetVulkanDispatchKey(device_info_->handle));
    GFXRECON_ASSERT(dev_table != device_tables_.end());
    device_table_ = &dev_table->second;

    const VulkanPhysicalDeviceInfo* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info_->parent_id);
    GFXRECON_ASSERT(phys_dev_info);

    auto inst_table = instance_tables_.find(graphics::GetVulkanDispatchKey(phys_dev_info->handle));
    GFXRECON_ASSERT(inst_table != instance_tables_.end());
    instance_table_ = &inst_table->second;

    GFXRECON_ASSERT(phys_dev_info->replay_device_info);
    GFXRECON_ASSERT(phys_dev_info->replay_device_info->memory_properties);
    replay_device_phys_mem_props_ = &phys_dev_info->replay_device_info->memory_properties.value();
}

VkResult TransferDumpingContext::HandleInitBufferCommand(
    uint64_t cmd_index, format::HandleId device_id, format::HandleId buffer_id, uint64_t data_size, const uint8_t* data)
{
    GFXRECON_UNREFERENCED_PARAMETER(device_id);

    if (MustDumpTransfer(cmd_index))
    {
        auto [new_entry, success] = transfer_params_.emplace(
            std::piecewise_construct,
            std::forward_as_tuple(cmd_index),
            std::forward_as_tuple(
                buffer_id, data, data_size, *device_table_, device_info_, TransferCommandTypes::kCmdInitBuffer));
        GFXRECON_ASSERT(success);
    }

    return VK_SUCCESS;
}

VkResult TransferDumpingContext::HandleInitImageCommand(VkCommandBuffer              command_buffer,
                                                        uint64_t                     cmd_index,
                                                        format::HandleId             device_id,
                                                        format::HandleId             image_id,
                                                        uint64_t                     data_size,
                                                        VkImageAspectFlagBits        aspect,
                                                        VkImageLayout                layout,
                                                        const std::vector<uint64_t>& level_sizes,
                                                        const uint8_t*               data)
{
    if (MustDumpTransfer(cmd_index))
    {
        GetDispatchTables(device_id);

        // Images with multiple aspects have each aspect dumped separately in a different kInitImageCommand.
        // In these cases, and if multiple kInitImageCommand commands that correspond to different aspects of the same
        // image are requested for dumping, we will attempt to gather all aspects into a single DumpedImage.
        TransferParams::InitImageMetaCommand* init_image_params = nullptr;
        bool                                  insert_new_entry  = true;

        GFXRECON_ASSERT(cmd_index);
        auto entry = transfer_params_.find(cmd_index - 1);
        if (entry != transfer_params_.end())
        {
            init_image_params = static_cast<TransferParams::InitImageMetaCommand*>(entry->second.params.get());
            if (init_image_params != nullptr && init_image_params->dst_image == image_id)
            {
                insert_new_entry = false;
            }
        }

        const auto* img_info = object_info_table_.GetVkImageInfo(image_id);
        const auto* dev_info = object_info_table_.GetVkDeviceInfo(device_id);

        TemporaryCommandBuffer temp_command_buffer;
        VkCommandBuffer        cmd_buf;
        if (command_buffer == VK_NULL_HANDLE)
        {
            VkResult res = CreateAndBeginCommandBuffer(
                &FindComputeQueueFamilyIndex, dev_info, *device_table_, temp_command_buffer);
            if (res != VK_SUCCESS)
            {
                return res;
            }
            cmd_buf = temp_command_buffer.command_buffer;
        }
        else
        {
            cmd_buf = command_buffer;
        }

        if (insert_new_entry)
        {
            auto [new_entry, success] = transfer_params_.emplace(
                std::piecewise_construct,
                std::forward_as_tuple(cmd_index),
                std::forward_as_tuple(
                    image_id, aspect, img_info, *device_table_, device_info_, TransferCommandTypes::kCmdInitImage));
            GFXRECON_ASSERT(success);

            init_image_params = static_cast<TransferParams::InitImageMetaCommand*>(new_entry->second.params.get());

            // Create an image with the same properties
            const auto* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info_->parent_id);
            const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props =
                &phys_dev_info->replay_device_info->memory_properties.value();
            VkResult res = CloneImage(object_info_table_,
                                      device_table_,
                                      replay_device_phys_mem_props,
                                      img_info,
                                      &init_image_params->copied_image.image,
                                      &init_image_params->copied_image.memory);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("%s() CloneImage failed (%s)", __func__, util::ToString(res).c_str());
                return res;
            }

            init_image_params->copied_image.image_info.handle              = init_image_params->copied_image.image;
            init_image_params->copied_image.image_info.intermediate_layout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
            init_image_params->copied_image.image_info.current_layout      = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        }
        GFXRECON_ASSERT(init_image_params != nullptr);

        // Transition new image/aspect into VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL
        VkImageMemoryBarrier img_barrier = {
            VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
            nullptr,
            VK_ACCESS_NONE,
            VK_ACCESS_TRANSFER_WRITE_BIT,
            VK_IMAGE_LAYOUT_UNDEFINED,
            VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
            VK_QUEUE_FAMILY_IGNORED,
            VK_QUEUE_FAMILY_IGNORED,
            init_image_params->copied_image.image,
            { static_cast<VkImageAspectFlags>(aspect), 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS }
        };
        device_table_->CmdPipelineBarrier(cmd_buf,
                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);

        // Flush source image and transition into VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL
        img_barrier.srcAccessMask = VK_ACCESS_MEMORY_WRITE_BIT;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout     = layout;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.image         = img_info->handle;

        device_table_->CmdPipelineBarrier(cmd_buf,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT | VK_PIPELINE_STAGE_HOST_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);

        // Copy source image
        std::vector<VkImageCopy> copy_regions(img_info->level_count);
        for (uint32_t m = 0; m < img_info->level_count; ++m)
        {
            copy_regions[m].srcSubresource = { static_cast<VkImageAspectFlags>(aspect), m, 0, img_info->layer_count };
            copy_regions[m].srcOffset      = { 0, 0, 0 };
            copy_regions[m].dstSubresource = { static_cast<VkImageAspectFlags>(aspect), m, 0, img_info->layer_count };
            copy_regions[m].dstOffset      = { 0, 0, 0 };
            copy_regions[m].extent         = ScaleToMipLevel(img_info->extent, m);
        }

        device_table_->CmdCopyImage(cmd_buf,
                                    img_info->handle,
                                    VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                    init_image_params->copied_image.image,
                                    VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                    img_info->level_count,
                                    copy_regions.data());

        // Flush copy
        img_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.image         = init_image_params->copied_image.image;

        device_table_->CmdPipelineBarrier(cmd_buf,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);

        // Transition source image into original layout
        if (layout != VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL)
        {
            img_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
            img_barrier.dstAccessMask = VK_ACCESS_NONE;
            img_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
            img_barrier.newLayout     = layout;
            img_barrier.image         = img_info->handle;

            device_table_->CmdPipelineBarrier(cmd_buf,
                                              VK_PIPELINE_STAGE_TRANSFER_BIT,
                                              VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                              VkDependencyFlags(0),
                                              0,
                                              nullptr,
                                              0,
                                              nullptr,
                                              1,
                                              &img_barrier);
        }

        if (command_buffer == VK_NULL_HANDLE)
        {
            SubmitAndDestroyCommandBuffer(temp_command_buffer);
        }
    }

    return VK_SUCCESS;
}

VkResult TransferDumpingContext::HandleCmdCopyBuffer(const ApiCallInfo&      call_info,
                                                     VkCommandBuffer         commandBuffer,
                                                     const VulkanBufferInfo* srcBuffer,
                                                     const VulkanBufferInfo* dstBuffer,
                                                     uint32_t                regionCount,
                                                     const VkBufferCopy*     pRegions,
                                                     bool                    before_command)
{
    if (MustDumpTransfer(call_info.index))
    {
        GetDispatchTables(srcBuffer->parent_id);

        // If we also are dumping resources before the command, we insert only one entry in transfer_params_ and store
        // the allocated resources for both before and after in the same entry.
        const bool insert_new_entry =
            (options_.dump_resources_before && before_command) || !options_.dump_resources_before;
        TransferParams::CopyBuffer* copy_buffer_params;
        if (insert_new_entry)
        {
            auto [new_entry, success] =
                transfer_params_.emplace(std::piecewise_construct,
                                         std::forward_as_tuple(call_info.index),
                                         std::forward_as_tuple(srcBuffer->capture_id,
                                                               dstBuffer->capture_id,
                                                               *device_table_,
                                                               device_info_,
                                                               before_command,
                                                               TransferCommandTypes::kCmdCopyBuffer));
            GFXRECON_ASSERT(success);
            copy_buffer_params = static_cast<TransferParams::CopyBuffer*>(
                before_command ? new_entry->second.before_params.get() : new_entry->second.params.get());
        }
        else
        {
            GFXRECON_ASSERT(options_.dump_resources_before && !before_command);

            auto params_entry = transfer_params_.find(call_info.index);
            GFXRECON_ASSERT(params_entry != transfer_params_.end());
            copy_buffer_params = static_cast<TransferParams::CopyBuffer*>(params_entry->second.params.get());
        }
        GFXRECON_ASSERT(copy_buffer_params != nullptr);

        for (uint32_t i = 0; i < regionCount; ++i)
        {
            auto& new_region = copy_buffer_params->regions.emplace_back(pRegions[i]);

            // Create a new vulkan buffer for each region
            VkResult res = CreateVkBuffer(pRegions[i].size,
                                          *device_table_,
                                          device_info_->handle,
                                          nullptr,
                                          nullptr,
                                          replay_device_phys_mem_props_,
                                          VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                          &new_region.vk_objects.buffer,
                                          &new_region.vk_objects.memory);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("%s(): CreateVkBuffer failed for command %" PRIu64 " with %s",
                                   __func__,
                                   call_info.index,
                                   util::ToString<VkResult>(res).c_str());
                return res;
            }

            new_region.vk_objects.size = pRegions[i].size;

            // Flush original copy/buffer
            VkBufferMemoryBarrier buf_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
                                                  nullptr,
                                                  VK_ACCESS_TRANSFER_WRITE_BIT | VK_ACCESS_MEMORY_WRITE_BIT,
                                                  VK_ACCESS_TRANSFER_READ_BIT,
                                                  VK_QUEUE_FAMILY_IGNORED,
                                                  VK_QUEUE_FAMILY_IGNORED,
                                                  dstBuffer->handle,
                                                  pRegions[i].dstOffset,
                                                  pRegions[i].size };
            device_table_->CmdPipelineBarrier(commandBuffer,
                                              VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                              VK_PIPELINE_STAGE_TRANSFER_BIT,
                                              0,
                                              0,
                                              nullptr,
                                              1,
                                              &buf_barrier,
                                              0,
                                              nullptr);

            // Inject copy command
            const VkBufferCopy region = { pRegions[i].srcOffset, 0, pRegions[i].size };
            device_table_->CmdCopyBuffer(commandBuffer, dstBuffer->handle, new_region.vk_objects.buffer, 1, &region);

            // Flush copy
            buf_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
            buf_barrier.buffer        = new_region.vk_objects.buffer;
            device_table_->CmdPipelineBarrier(commandBuffer,
                                              VK_PIPELINE_STAGE_TRANSFER_BIT,
                                              VK_PIPELINE_STAGE_TRANSFER_BIT,
                                              0,
                                              0,
                                              nullptr,
                                              1,
                                              &buf_barrier,
                                              0,
                                              nullptr);
        }
    }

    return VK_SUCCESS;
}

VkResult TransferDumpingContext::HandleCmdCopyBuffer2(const ApiCallInfo&                               call_info,
                                                      VkCommandBuffer                                  commandBuffer,
                                                      StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo,
                                                      bool                                             before_command)
{
    const auto*               p_copy_info = pCopyBufferInfo->GetPointer();
    std::vector<VkBufferCopy> regions(p_copy_info->regionCount);
    for (uint32_t i = 0; i < p_copy_info->regionCount; ++i)
    {
        regions[i].srcOffset = p_copy_info->pRegions[i].srcOffset;
        regions[i].dstOffset = p_copy_info->pRegions[i].dstOffset;
        regions[i].size      = p_copy_info->pRegions[i].size;
    }

    const auto* p_copy_info_meta = pCopyBufferInfo->GetMetaStructPointer();
    const auto* src_buffer_info  = object_info_table_.GetVkBufferInfo(p_copy_info_meta->srcBuffer);
    const auto* dst_buffer_info  = object_info_table_.GetVkBufferInfo(p_copy_info_meta->dstBuffer);
    return HandleCmdCopyBuffer(call_info,
                               commandBuffer,
                               src_buffer_info,
                               dst_buffer_info,
                               p_copy_info->regionCount,
                               regions.data(),
                               before_command);
}

VkResult TransferDumpingContext::HandleCmdCopyBufferToImage(const ApiCallInfo&       call_info,
                                                            VkCommandBuffer          commandBuffer,
                                                            const VulkanBufferInfo*  srcBuffer,
                                                            const VulkanImageInfo*   dstImage,
                                                            VkImageLayout            dstImageLayout,
                                                            uint32_t                 regionCount,
                                                            const VkBufferImageCopy* pRegions,
                                                            bool                     before_command)
{
    if (MustDumpTransfer(call_info.index))
    {
        GetDispatchTables(dstImage->parent_id);
        const VkDevice device = device_info_->handle;

        // If we also are dumping resources before the command, we insert only one entry in transfer_params_ and store
        // the allocated resources for both before and after in the same entry.
        const bool insert_new_entry =
            (options_.dump_resources_before && before_command) || !options_.dump_resources_before;
        TransferParams::CopyBufferToImage* copy_buffer_to_image_params;
        if (insert_new_entry)
        {
            auto [new_entry, success] =
                transfer_params_.emplace(std::piecewise_construct,
                                         std::forward_as_tuple(call_info.index),
                                         std::forward_as_tuple(srcBuffer->capture_id,
                                                               dstImageLayout,
                                                               dstImage,
                                                               *device_table_,
                                                               device_info_,
                                                               before_command,
                                                               TransferCommandTypes::kCmdCopyBufferToImage));
            GFXRECON_ASSERT(success);
            copy_buffer_to_image_params = static_cast<TransferParams::CopyBufferToImage*>(
                before_command ? new_entry->second.before_params.get() : new_entry->second.params.get());
        }
        else
        {
            GFXRECON_ASSERT(options_.dump_resources_before && !before_command);

            auto params_entry = transfer_params_.find(call_info.index);
            GFXRECON_ASSERT(params_entry != transfer_params_.end());
            copy_buffer_to_image_params =
                static_cast<TransferParams::CopyBufferToImage*>(params_entry->second.params.get());
        }
        GFXRECON_ASSERT(copy_buffer_to_image_params != nullptr);

        // Create an image with the same parameters as the dstImage
        const auto* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info_->parent_id);
        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props =
            &phys_dev_info->replay_device_info->memory_properties.value();
        VkResult res = CloneImage(object_info_table_,
                                  device_table_,
                                  replay_device_phys_mem_props,
                                  dstImage,
                                  &copy_buffer_to_image_params->copied_image.image,
                                  &copy_buffer_to_image_params->copied_image.memory);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("%s() CloneImage failed (%s)", __func__, util::ToString(res).c_str());
            return res;
        }

        // Update copy of VulkanImageInfo
        copy_buffer_to_image_params->copied_image.image_info.handle = copy_buffer_to_image_params->copied_image.image;
        copy_buffer_to_image_params->copied_image.image_info.capture_id          = format::kNullHandleId;
        copy_buffer_to_image_params->copied_image.image_info.intermediate_layout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        copy_buffer_to_image_params->copied_image.image_info.current_layout      = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

        // Flush any pending writes to destination image
        VkImageMemoryBarrier img_barrier = {
            VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
            nullptr,
            VK_ACCESS_MEMORY_WRITE_BIT | VK_ACCESS_TRANSFER_WRITE_BIT,
            VK_ACCESS_TRANSFER_READ_BIT,
            dstImageLayout,
            VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
            VK_QUEUE_FAMILY_IGNORED,
            VK_QUEUE_FAMILY_IGNORED,
            dstImage->handle,
            { graphics::GetFormatAspects(dstImage->format), 0, dstImage->level_count, 0, dstImage->layer_count }
        };
        device_table_->CmdPipelineBarrier(commandBuffer,
                                          VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);

        // Transition new image's layout
        img_barrier.srcAccessMask = VK_ACCESS_NONE;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.image         = copy_buffer_to_image_params->copied_image.image;
        device_table_->CmdPipelineBarrier(commandBuffer,
                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);

        for (uint32_t i = 0; i < regionCount; ++i)
        {
            auto& new_region = copy_buffer_to_image_params->regions.emplace_back(pRegions[i]);

            // Copy each of the destination image's regions into the new image with CmdCopyImage
            const VkImageCopy region = { pRegions[i].imageSubresource,
                                         { 0, 0, 0 },
                                         pRegions[i].imageSubresource,
                                         { 0, 0, 0 },
                                         ScaleToMipLevel(dstImage->extent, pRegions[i].imageSubresource.mipLevel) };
            device_table_->CmdCopyImage(commandBuffer,
                                        dstImage->handle,
                                        dstImageLayout,
                                        copy_buffer_to_image_params->copied_image.image,
                                        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                        1,
                                        &region);
        }

        // Flush copies
        img_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.image         = copy_buffer_to_image_params->copied_image.image;
        device_table_->CmdPipelineBarrier(commandBuffer,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);
    }

    return VK_SUCCESS;
}

VkResult TransferDumpingContext::HandleCmdCopyBufferToImage2(
    const ApiCallInfo&                                      call_info,
    VkCommandBuffer                                         commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo,
    bool                                                    before_command)
{
    const auto* info_meta       = pCopyBufferToImageInfo->GetMetaStructPointer();
    const auto* src_buffer_info = object_info_table_.GetVkBufferInfo(info_meta->srcBuffer);
    const auto* dst_img_info    = object_info_table_.GetVkImageInfo(info_meta->dstImage);

    const auto*                    pInfo = info_meta->decoded_value;
    std::vector<VkBufferImageCopy> buffer_image_copy(pInfo->regionCount);
    for (uint32_t i = 0; i < pInfo->regionCount; ++i)
    {
        buffer_image_copy[i].bufferOffset      = pInfo->pRegions[i].bufferOffset;
        buffer_image_copy[i].bufferRowLength   = pInfo->pRegions[i].bufferRowLength;
        buffer_image_copy[i].bufferImageHeight = pInfo->pRegions[i].bufferImageHeight;
        buffer_image_copy[i].imageSubresource  = pInfo->pRegions[i].imageSubresource;
        buffer_image_copy[i].imageOffset       = pInfo->pRegions[i].imageOffset;
        buffer_image_copy[i].imageExtent       = pInfo->pRegions[i].imageExtent;
    }

    return HandleCmdCopyBufferToImage(call_info,
                                      commandBuffer,
                                      src_buffer_info,
                                      dst_img_info,
                                      pInfo->dstImageLayout,
                                      pInfo->regionCount,
                                      buffer_image_copy.data(),
                                      before_command);
}

VkResult TransferDumpingContext::HandleCmdCopyImage(const ApiCallInfo&     call_info,
                                                    VkCommandBuffer        commandBuffer,
                                                    const VulkanImageInfo* srcImage,
                                                    VkImageLayout          srcImageLayout,
                                                    const VulkanImageInfo* dstImage,
                                                    VkImageLayout          dstImageLayout,
                                                    uint32_t               regionCount,
                                                    const VkImageCopy*     pRegions,
                                                    bool                   before_command)
{
    if (MustDumpTransfer(call_info.index))
    {
        GetDispatchTables(srcImage->parent_id);
        const VkDevice device = device_info_->handle;

        // If we also are dumping resources before the command, we insert only one entry in transfer_params_ and store
        // the allocated resources for both before and after in the same entry.
        const bool insert_new_entry =
            (options_.dump_resources_before && before_command) || !options_.dump_resources_before;
        TransferParams::CopyImage* copy_image_params;
        if (insert_new_entry)
        {
            auto [new_entry, success] =
                transfer_params_.emplace(std::piecewise_construct,
                                         std::forward_as_tuple(call_info.index),
                                         std::forward_as_tuple(srcImage->capture_id,
                                                               srcImageLayout,
                                                               dstImageLayout,
                                                               dstImage,
                                                               *device_table_,
                                                               device_info_,
                                                               before_command,
                                                               TransferCommandTypes::kCmdCopyImage));
            GFXRECON_ASSERT(success);
            copy_image_params = static_cast<TransferParams::CopyImage*>(
                before_command ? new_entry->second.before_params.get() : new_entry->second.params.get());
        }
        else
        {
            GFXRECON_ASSERT(options_.dump_resources_before && !before_command);

            auto params_entry = transfer_params_.find(call_info.index);
            GFXRECON_ASSERT(params_entry != transfer_params_.end());
            copy_image_params = static_cast<TransferParams::CopyImage*>(params_entry->second.params.get());
        }
        GFXRECON_ASSERT(copy_image_params != nullptr);

        // Create an image with the same parameters as the dstImage
        const auto* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info_->parent_id);
        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props =
            &phys_dev_info->replay_device_info->memory_properties.value();
        VkResult res = CloneImage(object_info_table_,
                                  device_table_,
                                  replay_device_phys_mem_props,
                                  dstImage,
                                  &copy_image_params->copied_image.image,
                                  &copy_image_params->copied_image.memory);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("%s() CloneImage failed (%s)", __func__, util::ToString(res).c_str());
            return res;
        }

        // Update copy of VulkanImageInfo
        copy_image_params->copied_image.image_info.handle              = copy_image_params->copied_image.image;
        copy_image_params->copied_image.image_info.capture_id          = format::kNullHandleId;
        copy_image_params->copied_image.image_info.intermediate_layout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        copy_image_params->copied_image.image_info.current_layout      = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

        // Flush any pending writes to destination image
        VkImageMemoryBarrier img_barrier = {
            VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
            nullptr,
            VK_ACCESS_MEMORY_WRITE_BIT | VK_ACCESS_TRANSFER_WRITE_BIT,
            VK_ACCESS_TRANSFER_READ_BIT,
            dstImageLayout,
            VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
            VK_QUEUE_FAMILY_IGNORED,
            VK_QUEUE_FAMILY_IGNORED,
            dstImage->handle,
            { graphics::GetFormatAspects(dstImage->format), 0, dstImage->level_count, 0, dstImage->layer_count }
        };
        device_table_->CmdPipelineBarrier(commandBuffer,
                                          VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);

        // Transition new image's layout
        img_barrier.srcAccessMask = VK_ACCESS_NONE;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.image         = copy_image_params->copied_image.image;
        device_table_->CmdPipelineBarrier(commandBuffer,
                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);

        for (uint32_t i = 0; i < regionCount; ++i)
        {
            auto& new_region = copy_image_params->regions.emplace_back(pRegions[i]);

            // Copy regions into new image
            const VkImageCopy copy_region = { pRegions[i].dstSubresource,
                                              { 0, 0, 0 },
                                              pRegions[i].dstSubresource,
                                              { 0, 0, 0 },
                                              ScaleToMipLevel(dstImage->extent, pRegions[i].dstSubresource.mipLevel) };
            device_table_->CmdCopyImage(commandBuffer,
                                        dstImage->handle,
                                        VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                        copy_image_params->copied_image.image,
                                        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                        1,
                                        &copy_region);
        }

        // Barrier for injected copies
        img_barrier.srcAccessMask    = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.dstAccessMask    = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout        = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.newLayout        = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.image            = copy_image_params->copied_image.image;
        img_barrier.subresourceRange = { graphics::GetFormatAspects(copy_image_params->copied_image.image_info.format),
                                         0,
                                         VK_REMAINING_MIP_LEVELS,
                                         0,
                                         VK_REMAINING_ARRAY_LAYERS };

        device_table_->CmdPipelineBarrier(commandBuffer,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);
    }

    return VK_SUCCESS;
}

VkResult TransferDumpingContext::HandleCmdCopyImage2(const ApiCallInfo&                              call_info,
                                                     VkCommandBuffer                                 commandBuffer,
                                                     StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo,
                                                     bool                                            before_command)
{
    const auto*              p_info = pCopyImageInfo->GetPointer();
    std::vector<VkImageCopy> regions(p_info->regionCount);
    for (uint32_t i = 0; i < p_info->regionCount; ++i)
    {
        regions[i].srcSubresource = p_info->pRegions[i].srcSubresource;
        regions[i].srcOffset      = p_info->pRegions[i].srcOffset;
        regions[i].dstSubresource = p_info->pRegions[i].dstSubresource;
        regions[i].dstOffset      = p_info->pRegions[i].dstOffset;
        regions[i].extent         = p_info->pRegions[i].extent;
    }

    const auto* p_info_meta    = pCopyImageInfo->GetMetaStructPointer();
    const auto* src_image_info = object_info_table_.GetVkImageInfo(p_info_meta->srcImage);
    const auto* dst_image_info = object_info_table_.GetVkImageInfo(p_info_meta->dstImage);

    return HandleCmdCopyImage(call_info,
                              commandBuffer,
                              src_image_info,
                              p_info->srcImageLayout,
                              dst_image_info,
                              p_info->dstImageLayout,
                              p_info->regionCount,
                              regions.data(),
                              before_command);
}

VkResult TransferDumpingContext::HandleCmdCopyImageToBuffer(const ApiCallInfo&       call_info,
                                                            VkCommandBuffer          commandBuffer,
                                                            const VulkanImageInfo*   srcImage,
                                                            VkImageLayout            srcImageLayout,
                                                            const VulkanBufferInfo*  dstBuffer,
                                                            uint32_t                 regionCount,
                                                            const VkBufferImageCopy* pRegions,
                                                            bool                     before_command)
{
    if (MustDumpTransfer(call_info.index))
    {
        GetDispatchTables(dstBuffer->parent_id);

        // If we also are dumping resources before the command, we insert only one entry in transfer_params_ and store
        // the allocated resources for both before and after in the same entry.
        const bool insert_new_entry =
            (options_.dump_resources_before && before_command) || !options_.dump_resources_before;
        TransferParams::CopyImageToBuffer* copy_image_to_buffer_params;
        if (insert_new_entry)
        {
            auto [new_entry, success] =
                transfer_params_.emplace(std::piecewise_construct,
                                         std::forward_as_tuple(call_info.index),
                                         std::forward_as_tuple(srcImage->capture_id,
                                                               srcImageLayout,
                                                               dstBuffer->capture_id,
                                                               *device_table_,
                                                               device_info_,
                                                               before_command,
                                                               TransferCommandTypes::kCmdCopyImageToBuffer));
            GFXRECON_ASSERT(success);
            copy_image_to_buffer_params = static_cast<TransferParams::CopyImageToBuffer*>(
                before_command ? new_entry->second.before_params.get() : new_entry->second.params.get());
        }
        else
        {
            GFXRECON_ASSERT(options_.dump_resources_before && !before_command);

            auto params_entry = transfer_params_.find(call_info.index);
            GFXRECON_ASSERT(params_entry != transfer_params_.end());
            copy_image_to_buffer_params =
                static_cast<TransferParams::CopyImageToBuffer*>(params_entry->second.params.get());
        }
        GFXRECON_ASSERT(copy_image_to_buffer_params != nullptr);

        for (uint32_t i = 0; i < regionCount; ++i)
        {
            auto& new_region = copy_image_to_buffer_params->regions.emplace_back(pRegions[i]);

            const VKU_FORMAT_INFO img_format_info = vkuGetFormatInfo(srcImage->format);

            // Calculations are based on §22.3. Copying Data Between Buffers and Images
            const uint32_t row_extent = std::ceil(std::max(pRegions[i].bufferRowLength, pRegions[i].imageExtent.width) /
                                                  img_format_info.block_extent.width) *
                                        img_format_info.block_size;

            const uint32_t slice_extent =
                std::ceil(std::max(pRegions[i].bufferImageHeight, pRegions[i].imageExtent.height) /
                          img_format_info.block_extent.height) *
                row_extent;

            const uint32_t layer_extent =
                std::ceil(pRegions[i].imageExtent.depth / img_format_info.block_extent.depth) * slice_extent;

            const uint32_t region_buffer_size = layer_extent * pRegions[i].imageSubresource.layerCount;
            GFXRECON_ASSERT(static_cast<VkDeviceSize>(region_buffer_size) <= dstBuffer->size - pRegions[i].bufferOffset)
            new_region.vk_objects.size = region_buffer_size;

            // Create a new vulkan buffer for each region
            VkResult res = CreateVkBuffer(region_buffer_size,
                                          *device_table_,
                                          device_info_->handle,
                                          nullptr,
                                          nullptr,
                                          replay_device_phys_mem_props_,
                                          VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                                          &new_region.vk_objects.buffer,
                                          &new_region.vk_objects.memory);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("%s(): CreateVkBuffer failed for command %" PRIu64 " with %s",
                                   __func__,
                                   call_info.index,
                                   util::ToString<VkResult>(res).c_str());
                return res;
            }

            // Flush any pending writes to command's destination buffer
            VkBufferMemoryBarrier buff_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
                                                   nullptr,
                                                   VK_ACCESS_MEMORY_WRITE_BIT | VK_ACCESS_TRANSFER_WRITE_BIT,
                                                   VK_ACCESS_TRANSFER_READ_BIT,
                                                   VK_QUEUE_FAMILY_IGNORED,
                                                   VK_QUEUE_FAMILY_IGNORED,
                                                   dstBuffer->handle,
                                                   pRegions[i].bufferOffset,
                                                   region_buffer_size };
            device_table_->CmdPipelineBarrier(commandBuffer,
                                              VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                              VK_PIPELINE_STAGE_TRANSFER_BIT,
                                              VkDependencyFlags(0),
                                              0,
                                              nullptr,
                                              1,
                                              &buff_barrier,
                                              0,
                                              nullptr);

            // Copy regions with CmdCopyBuffer
            const VkBufferCopy buffer_copy_region = { pRegions[i].bufferOffset, 0, region_buffer_size };
            device_table_->CmdCopyBuffer(
                commandBuffer, dstBuffer->handle, new_region.vk_objects.buffer, 1, &buffer_copy_region);

            buff_barrier.buffer        = new_region.vk_objects.buffer;
            buff_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
            buff_barrier.offset        = 0;
            device_table_->CmdPipelineBarrier(commandBuffer,
                                              VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                              VK_PIPELINE_STAGE_TRANSFER_BIT,
                                              VkDependencyFlags(0),
                                              0,
                                              nullptr,
                                              1,
                                              &buff_barrier,
                                              0,
                                              nullptr);
        }
    }

    return VK_SUCCESS;
}

VkResult TransferDumpingContext::HandleCmdCopyImageToBuffer2(
    const ApiCallInfo&                                      call_info,
    VkCommandBuffer                                         commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo,
    bool                                                    before_command)
{
    const auto* info_meta       = pCopyImageToBufferInfo->GetMetaStructPointer();
    const auto* src_img_info    = object_info_table_.GetVkImageInfo(info_meta->srcImage);
    const auto* dst_buffer_info = object_info_table_.GetVkBufferInfo(info_meta->dstBuffer);

    const auto*                    info = info_meta->decoded_value;
    std::vector<VkBufferImageCopy> regions(info->regionCount);
    for (uint32_t i = 0; i < info->regionCount; ++i)
    {
        regions[i].bufferImageHeight = info->pRegions[i].bufferImageHeight;
        regions[i].bufferRowLength   = info->pRegions[i].bufferRowLength;
        regions[i].bufferOffset      = info->pRegions[i].bufferOffset;

        regions[i].imageOffset      = info->pRegions[i].imageOffset;
        regions[i].imageExtent      = info->pRegions[i].imageExtent;
        regions[i].imageSubresource = info->pRegions[i].imageSubresource;
    }

    return HandleCmdCopyImageToBuffer(call_info,
                                      commandBuffer,
                                      src_img_info,
                                      info->srcImageLayout,
                                      dst_buffer_info,
                                      info->regionCount,
                                      regions.data(),
                                      before_command);
}

VkResult TransferDumpingContext::HandleCmdBlitImage(const ApiCallInfo&     call_info,
                                                    VkCommandBuffer        commandBuffer,
                                                    const VulkanImageInfo* srcImage,
                                                    VkImageLayout          srcImageLayout,
                                                    const VulkanImageInfo* dstImage,
                                                    VkImageLayout          dstImageLayout,
                                                    uint32_t               regionCount,
                                                    const VkImageBlit*     pRegions,
                                                    VkFilter               filter,
                                                    bool                   before_command)
{
    if (MustDumpTransfer(call_info.index))
    {
        GetDispatchTables(dstImage->parent_id);

        // If we also are dumping resources before the command, we insert only one entry in transfer_params_ and store
        // the allocated resources for both before and after in the same entry.
        const bool insert_new_entry =
            (options_.dump_resources_before && before_command) || !options_.dump_resources_before;
        TransferParams::BlitImage* blit_image_params;
        if (insert_new_entry)
        {
            auto [new_entry, success] =
                transfer_params_.emplace(std::piecewise_construct,
                                         std::forward_as_tuple(call_info.index),
                                         std::forward_as_tuple(srcImage->capture_id,
                                                               srcImageLayout,
                                                               dstImageLayout,
                                                               dstImage,
                                                               filter,
                                                               *device_table_,
                                                               device_info_,
                                                               before_command,
                                                               TransferCommandTypes::kCmdBlitImage));
            GFXRECON_ASSERT(success);
            blit_image_params = static_cast<TransferParams::BlitImage*>(
                before_command ? new_entry->second.before_params.get() : new_entry->second.params.get());
        }
        else
        {
            GFXRECON_ASSERT(options_.dump_resources_before && !before_command);

            auto params_entry = transfer_params_.find(call_info.index);
            GFXRECON_ASSERT(params_entry != transfer_params_.end());
            blit_image_params = static_cast<TransferParams::BlitImage*>(params_entry->second.params.get());
        }
        GFXRECON_ASSERT(blit_image_params != nullptr);

        // Create an image with the same parameters as the dstImage
        const auto* phys_dev_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info_->parent_id);
        const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props =
            &phys_dev_info->replay_device_info->memory_properties.value();
        VkResult res = CloneImage(object_info_table_,
                                  device_table_,
                                  replay_device_phys_mem_props,
                                  dstImage,
                                  &blit_image_params->copied_image.image,
                                  &blit_image_params->copied_image.memory);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("%s() CloneImage failed (%s)", __func__, util::ToString(res).c_str());
            return res;
        }

        // Update copy of VulkanImageInfo
        blit_image_params->copied_image.image_info.handle              = blit_image_params->copied_image.image;
        blit_image_params->copied_image.image_info.capture_id          = format::kNullHandleId;
        blit_image_params->copied_image.image_info.intermediate_layout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        blit_image_params->copied_image.image_info.current_layout      = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

        // Flush any pending writes to destination image
        VkImageMemoryBarrier img_barrier = {
            VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
            nullptr,
            VK_ACCESS_MEMORY_WRITE_BIT | VK_ACCESS_TRANSFER_WRITE_BIT,
            VK_ACCESS_TRANSFER_READ_BIT,
            dstImageLayout,
            VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
            VK_QUEUE_FAMILY_IGNORED,
            VK_QUEUE_FAMILY_IGNORED,
            dstImage->handle,
            { graphics::GetFormatAspects(dstImage->format), 0, dstImage->level_count, 0, dstImage->layer_count }
        };
        device_table_->CmdPipelineBarrier(commandBuffer,
                                          VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);

        // Transition new image's layout
        img_barrier.srcAccessMask = VK_ACCESS_NONE;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.image         = blit_image_params->copied_image.image;
        device_table_->CmdPipelineBarrier(commandBuffer,
                                          VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);

        for (uint32_t i = 0; i < regionCount; ++i)
        {
            auto& new_region = blit_image_params->regions.emplace_back(pRegions[i]);

            const VkImageCopy copy_region = { pRegions[i].dstSubresource,
                                              { 0, 0, 0 },
                                              pRegions[i].dstSubresource,
                                              { 0, 0, 0 },
                                              ScaleToMipLevel(dstImage->extent, pRegions[i].dstSubresource.mipLevel) };

            device_table_->CmdCopyImage(commandBuffer,
                                        srcImage->handle,
                                        srcImageLayout,
                                        blit_image_params->copied_image.image,
                                        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                        1,
                                        &copy_region);
        }

        // Flush injected copies
        img_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        device_table_->CmdPipelineBarrier(commandBuffer,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          VkDependencyFlags(0),
                                          0,
                                          nullptr,
                                          0,
                                          nullptr,
                                          1,
                                          &img_barrier);
    }

    return VK_SUCCESS;
}

VkResult TransferDumpingContext::HandleCmdBlitImage2(const ApiCallInfo&                              call_info,
                                                     VkCommandBuffer                                 commandBuffer,
                                                     StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo,
                                                     bool                                            before_command)
{
    const auto blit_image_info_meta = pBlitImageInfo->GetMetaStructPointer();
    const auto blit_image_info      = pBlitImageInfo->GetPointer();

    std::vector<VkImageBlit> blit_regions(blit_image_info->regionCount);
    for (uint32_t i = 0; i < blit_image_info->regionCount; ++i)
    {
        blit_regions[i].srcOffsets[0]  = blit_image_info->pRegions[i].srcOffsets[0];
        blit_regions[i].srcOffsets[1]  = blit_image_info->pRegions[i].srcOffsets[1];
        blit_regions[i].srcSubresource = blit_image_info->pRegions[i].srcSubresource;

        blit_regions[i].dstOffsets[0]  = blit_image_info->pRegions[i].dstOffsets[0];
        blit_regions[i].dstOffsets[1]  = blit_image_info->pRegions[i].dstOffsets[1];
        blit_regions[i].dstSubresource = blit_image_info->pRegions[i].dstSubresource;
    }

    return HandleCmdBlitImage(call_info,
                              commandBuffer,
                              object_info_table_.GetVkImageInfo(blit_image_info_meta->srcImage),
                              blit_image_info->srcImageLayout,
                              object_info_table_.GetVkImageInfo(blit_image_info_meta->dstImage),
                              blit_image_info->dstImageLayout,
                              blit_image_info->regionCount,
                              blit_regions.data(),
                              blit_image_info->filter,
                              before_command);
}

VkResult TransferDumpingContext::HandleCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                                                         call_info,
    VkCommandBuffer                                                            commandBuffer,
    uint32_t                                                                   infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   ppBuildRangeInfos,
    bool                                                                       before_command)
{
    if (MustDumpTransfer(call_info.index))
    {
        const auto*                                            p_infos_meta  = pInfos->GetMetaStructPointer();
        const VkAccelerationStructureBuildGeometryInfoKHR*     p_infos       = pInfos->GetPointer();
        const VkAccelerationStructureBuildRangeInfoKHR* const* p_range_infos = ppBuildRangeInfos->GetPointer();

        // Need to grab a device_info, device_table pair
        const auto* dst_as =
            object_info_table_.GetVkAccelerationStructureKHRInfo(p_infos_meta[0].dstAccelerationStructure);
        GetDispatchTables(dst_as->parent_id);

        // If we also are dumping resources before the command, we insert only one entry in transfer_params_ and store
        // the allocated resources for both before and after in the same entry.
        const bool insert_new_entry =
            (options_.dump_resources_before && before_command) || !options_.dump_resources_before;
        TransferParams::BuildAccelerationStructure* build_params;
        if (insert_new_entry)
        {
            auto [new_entry, success] =
                transfer_params_.emplace(std::piecewise_construct,
                                         std::forward_as_tuple(call_info.index),
                                         std::forward_as_tuple(*device_table_,
                                                               device_info_,
                                                               before_command,
                                                               TransferCommandTypes::kCmdBuildAccelerationStructures));
            GFXRECON_ASSERT(success);
            build_params = static_cast<TransferParams::BuildAccelerationStructure*>(
                before_command ? new_entry->second.before_params.get() : new_entry->second.params.get());
        }
        else
        {
            GFXRECON_ASSERT(options_.dump_resources_before && !before_command);

            auto params_entry = transfer_params_.find(call_info.index);
            GFXRECON_ASSERT(params_entry != transfer_params_.end());
            build_params = static_cast<TransferParams::BuildAccelerationStructure*>(params_entry->second.params.get());
        }
        GFXRECON_ASSERT(build_params != nullptr);

        for (uint32_t i = 0; i < infoCount; ++i)
        {
            const auto* dst_as =
                object_info_table_.GetVkAccelerationStructureKHRInfo(p_infos_meta[i].dstAccelerationStructure);
            const auto* src_as =
                object_info_table_.GetVkAccelerationStructureKHRInfo(p_infos_meta[i].srcAccelerationStructure);

            VkResult               res;
            TemporaryCommandBuffer temp_command_buffer;

            // NULL command buffer means that this is coming from the state setup section
            if (commandBuffer == VK_NULL_HANDLE)
            {
                res = CreateAndBeginCommandBuffer(&FindComputeQueueFamilyIndex,
                                                  object_info_table_.GetVkDeviceInfo(dst_as->parent_id),
                                                  *device_table_,
                                                  temp_command_buffer);
                if (res != VK_SUCCESS)
                {
                    return res;
                }
            }

            const VkCommandBuffer command_buffer =
                commandBuffer != VK_NULL_HANDLE ? commandBuffer : temp_command_buffer.command_buffer;

            GFXRECON_ASSERT(device_table_ != nullptr);
            auto& new_build_info = build_params->build_infos.emplace_back(
                src_as, dst_as, p_infos[i].mode, *device_table_, object_info_table_, address_trackers_);

            if (!before_command)
            {
                // Clone build input buffers
                res = new_build_info.vk_objects.as_context.CloneBuildAccelerationStructuresInputBuffers(
                    command_buffer,
                    &p_infos_meta[i],
                    p_range_infos[i],
                    options_.dump_resources_dump_build_AS_input_buffers);
                if (res != VK_SUCCESS)
                {
                    return res;
                }
            }
            else
            {
                // If before_command is true then we need to copy the build input buffers before they are replaced.
                auto dst_as_context_entry = acceleration_structures_context_.find(dst_as);
                if (dst_as_context_entry != acceleration_structures_context_.end())
                {
                    const auto& dst_as_context = *dst_as_context_entry->second;
                    res = new_build_info.vk_objects.as_context.CloneBuildAccelerationStructuresInputBuffers(
                        command_buffer, dst_as_context, options_.dump_resources_dump_build_AS_input_buffers);
                    if (res != VK_SUCCESS)
                    {
                        return res;
                    }
                }
            }

            // Clone the dst acceleration structure
            res = CreateVkBuffer(dst_as->size,
                                 *device_table_,
                                 device_info_->handle,
                                 nullptr,
                                 nullptr,
                                 replay_device_phys_mem_props_,
                                 VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR |
                                     VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT |
                                     VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                                 &new_build_info.vk_objects.buffer,
                                 &new_build_info.vk_objects.memory);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR(
                    "%s(): CreateVkBuffer failed with %s", __func__, util::ToString<VkResult>(res).c_str());
                return res;
            }

            // Create acceleration structure
            const VkAccelerationStructureCreateInfoKHR as_ci = {
                VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR,
                nullptr,
                VkAccelerationStructureCreateFlagBitsKHR(0),
                new_build_info.vk_objects.buffer,
                0,
                dst_as->size,
                dst_as->type,
                0
            };
            res = device_table_->CreateAccelerationStructureKHR(
                device_info_->handle, &as_ci, nullptr, &new_build_info.vk_objects.as);
            if (res != VK_SUCCESS)
            {
                GFXRECON_LOG_ERROR("%s(): CreateAccelerationStructureKHR failed with %s",
                                   __func__,
                                   util::ToString<VkResult>(res).c_str());
                return res;
            }

            // Update local VulkanAccelerationStructureKHRInfo
            new_build_info.vk_objects.as_info.handle = new_build_info.vk_objects.as;
            new_build_info.vk_objects.as_info.buffer = new_build_info.vk_objects.buffer;

            // Wait for original build to complete / flush any pending writes to destination
            VkBufferMemoryBarrier dst_buf_mem_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
                                                          nullptr,
                                                          VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR |
                                                              VK_ACCESS_MEMORY_WRITE_BIT | VK_ACCESS_TRANSFER_WRITE_BIT,
                                                          VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR |
                                                              VK_ACCESS_TRANSFER_READ_BIT,
                                                          VK_QUEUE_FAMILY_IGNORED,
                                                          VK_QUEUE_FAMILY_IGNORED,
                                                          dst_as->buffer,
                                                          0,
                                                          VK_WHOLE_SIZE };
            device_table_->CmdPipelineBarrier(command_buffer,
                                              VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
                                              VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR |
                                                  VK_PIPELINE_STAGE_TRANSFER_BIT,
                                              0,
                                              0,
                                              nullptr,
                                              1,
                                              &dst_buf_mem_barrier,
                                              0,
                                              nullptr);

            // Flush temporary build
            dst_buf_mem_barrier.dstAccessMask = VK_ACCESS_MEMORY_WRITE_BIT;
            dst_buf_mem_barrier.buffer        = new_build_info.vk_objects.buffer;
            device_table_->CmdPipelineBarrier(command_buffer,
                                              VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
                                              VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR |
                                                  VK_PIPELINE_STAGE_TRANSFER_BIT,
                                              0,
                                              0,
                                              nullptr,
                                              1,
                                              &dst_buf_mem_barrier,
                                              0,
                                              nullptr);

            // Inject vkCmdCopyBuffer to Copy destination's backing buffer
            const VkBufferCopy copy_buffer_info = { 0, 0, dst_as->size };
            device_table_->CmdCopyBuffer(
                command_buffer, dst_as->buffer, new_build_info.vk_objects.buffer, 1, &copy_buffer_info);

            // Flush copy
            const VkBufferMemoryBarrier buf_mem_barrier = {
                VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
                nullptr,
                VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR | VK_ACCESS_TRANSFER_WRITE_BIT,
                VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR | VK_ACCESS_TRANSFER_READ_BIT,
                VK_QUEUE_FAMILY_IGNORED,
                VK_QUEUE_FAMILY_IGNORED,
                new_build_info.vk_objects.buffer,
                0,
                VK_WHOLE_SIZE
            };
            device_table_->CmdPipelineBarrier(
                command_buffer,
                VK_PIPELINE_STAGE_TRANSFER_BIT | VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
                VK_PIPELINE_STAGE_TRANSFER_BIT | VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
                0,
                0,
                nullptr,
                1,
                &buf_mem_barrier,
                0,
                nullptr);

            if (commandBuffer == VK_NULL_HANDLE)
            {
                SubmitAndDestroyCommandBuffer(temp_command_buffer);
            }
        }
    }

    return VK_SUCCESS;
}

VkResult TransferDumpingContext::HandleCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                                                call_info,
    VkCommandBuffer                                                   commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo,
    bool                                                              before_command)
{
    if (MustDumpTransfer(call_info.index))
    {
        const auto* p_info_meta = pInfo->GetMetaStructPointer();
        const auto* src_as      = object_info_table_.GetVkAccelerationStructureKHRInfo(p_info_meta->src);
        const auto* dst_as      = object_info_table_.GetVkAccelerationStructureKHRInfo(p_info_meta->dst);

        GetDispatchTables(dst_as->parent_id);

        // If we also are dumping resources before the command, we insert only one entry in transfer_params_ and store
        // the allocated resources for both before and after in the same entry.
        const bool insert_new_entry =
            (options_.dump_resources_before && before_command) || !options_.dump_resources_before;
        TransferParams::CopyAccelerationStructure* copy_as_params;
        if (insert_new_entry)
        {
            auto [new_entry, success] =
                transfer_params_.emplace(std::piecewise_construct,
                                         std::forward_as_tuple(call_info.index),
                                         std::forward_as_tuple(src_as->capture_id,
                                                               dst_as,
                                                               p_info_meta->decoded_value->mode,
                                                               *device_table_,
                                                               device_info_,
                                                               object_info_table_,
                                                               address_trackers_,
                                                               before_command,
                                                               TransferCommandTypes::kCmdCopyAccelerationStructure));
            GFXRECON_ASSERT(success);
            copy_as_params = static_cast<TransferParams::CopyAccelerationStructure*>(
                before_command ? new_entry->second.before_params.get() : new_entry->second.params.get());
        }
        else
        {
            GFXRECON_ASSERT(options_.dump_resources_before && !before_command);

            auto params_entry = transfer_params_.find(call_info.index);
            GFXRECON_ASSERT(params_entry != transfer_params_.end());
            copy_as_params = static_cast<TransferParams::CopyAccelerationStructure*>(params_entry->second.params.get());
        }
        GFXRECON_ASSERT(copy_as_params != nullptr);

        auto dst_as_context_entry = acceleration_structures_context_.find(dst_as);
        if (dst_as_context_entry != acceleration_structures_context_.end())
        {
            const auto& dst_as_context = *dst_as_context_entry->second;
            VkResult    res = copy_as_params->vk_objects.as_context.CloneBuildAccelerationStructuresInputBuffers(
                commandBuffer, dst_as_context, options_.dump_resources_dump_build_AS_input_buffers);
            if (res != VK_SUCCESS)
            {
                return res;
            }
        }

        // Clone destination acceleration structure
        // Clone the dst acceleration structure
        VkResult res = CreateVkBuffer(dst_as->size,
                                      *device_table_,
                                      device_info_->handle,
                                      nullptr,
                                      nullptr,
                                      replay_device_phys_mem_props_,
                                      VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR |
                                          VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT,
                                      &copy_as_params->vk_objects.buffer,
                                      &copy_as_params->vk_objects.memory);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("%s(): CreateVkBuffer failed with %s", __func__, util::ToString<VkResult>(res).c_str());
            return res;
        }

        // Create acceleration structure
        const VkAccelerationStructureCreateInfoKHR as_ci = { VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR,
                                                             nullptr,
                                                             VkAccelerationStructureCreateFlagBitsKHR(0),
                                                             copy_as_params->vk_objects.buffer,
                                                             0,
                                                             dst_as->size,
                                                             dst_as->type,
                                                             0 };
        res                                              = device_table_->CreateAccelerationStructureKHR(
            device_info_->handle, &as_ci, nullptr, &copy_as_params->vk_objects.as);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "%s(): CreateAccelerationStructureKHR failed with %s", __func__, util::ToString<VkResult>(res).c_str());
            return res;
        }

        // Update local VulkanAccelerationStructureKHRInfo
        copy_as_params->vk_objects.as_info.handle = copy_as_params->vk_objects.as;
        copy_as_params->vk_objects.as_info.buffer = copy_as_params->vk_objects.buffer;

        // Wait for original build to complete / flush any pending writes to destination
        const VkBufferMemoryBarrier dst_buf_mem_barrier = {
            VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            nullptr,
            VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR | VK_ACCESS_MEMORY_WRITE_BIT | VK_ACCESS_TRANSFER_WRITE_BIT,
            VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR | VK_ACCESS_TRANSFER_READ_BIT,
            VK_QUEUE_FAMILY_IGNORED,
            VK_QUEUE_FAMILY_IGNORED,
            dst_as->buffer,
            0,
            VK_WHOLE_SIZE
        };
        device_table_->CmdPipelineBarrier(commandBuffer,
                                          VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
                                          VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR |
                                              VK_PIPELINE_STAGE_TRANSFER_BIT,
                                          0,
                                          0,
                                          nullptr,
                                          1,
                                          &dst_buf_mem_barrier,
                                          0,
                                          nullptr);

        // Inject vkCmdCopyBuffer to Copy destination's backing buffer
        const VkBufferCopy copy_buffer_info = { 0, 0, dst_as->size };
        device_table_->CmdCopyBuffer(
            commandBuffer, dst_as->buffer, copy_as_params->vk_objects.buffer, 1, &copy_buffer_info);

        // Flush copy
        const VkBufferMemoryBarrier buf_mem_barrier = {
            VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            nullptr,
            VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR | VK_ACCESS_TRANSFER_WRITE_BIT,
            VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR | VK_ACCESS_TRANSFER_READ_BIT,
            VK_QUEUE_FAMILY_IGNORED,
            VK_QUEUE_FAMILY_IGNORED,
            copy_as_params->vk_objects.buffer,
            0,
            VK_WHOLE_SIZE
        };
        device_table_->CmdPipelineBarrier(
            commandBuffer,
            VK_PIPELINE_STAGE_TRANSFER_BIT | VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
            VK_PIPELINE_STAGE_TRANSFER_BIT | VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR,
            0,
            0,
            nullptr,
            1,
            &buf_mem_barrier,
            0,
            nullptr);
    }

    return VK_SUCCESS;
}

VkResult TransferDumpingContext::DumpTransferCommands(uint64_t qs_index)
{
    if (!qs_index)
    {
        delegate_.DumpStart();
    }

    for (auto& [cmd_index, cmd] : transfer_params_)
    {
        VulkanDelegateDumpResourceContext res_info(instance_table_, device_table_, compressor_);
        res_info.dumped_data = VulkanDelegateTransferCommandDumpedData();
        auto& host_data      = std::get<VulkanDelegateTransferCommandDumpedData>(res_info.dumped_data);

        TransferParams::TransferParamsBase* base_transfer_cmd = cmd.params.get();
        base_transfer_cmd->dumped_resources.cmd_index         = cmd_index;
        base_transfer_cmd->dumped_resources.qs_index          = qs_index;

        switch (base_transfer_cmd->type)
        {
            case kCmdInitBuffer:
            {
                auto* init_buffer             = static_cast<TransferParams::InitBufferMetaCommand*>(base_transfer_cmd);
                auto& new_dumped_transfer_cmd = init_buffer->dumped_resources.dumped_transfer_command =
                    std::make_unique<DumpedTransferCommand>(DumpResourceType::kInitBufferMetaCommand,
                                                            cmd_index,
                                                            qs_index,
                                                            init_buffer->dst_buffer,
                                                            init_buffer->data.size());
                auto& new_dumped_init_buffer =
                    std::get<DumpedInitBufferMetaCommand>(new_dumped_transfer_cmd->dumped_resource);

                res_info.dumped_resource = new_dumped_transfer_cmd.get();
                host_data.dumped_data    = VulkanDelegateBufferDumpedData();

                auto& dumped_host_data = std::get<VulkanDelegateBufferDumpedData>(host_data.dumped_data);
                dumped_host_data.data  = init_buffer->data;
                delegate_.DumpResource(res_info);
            }
            break;

            case kCmdInitImage:
            {
                auto* init_image              = static_cast<TransferParams::InitImageMetaCommand*>(base_transfer_cmd);
                auto& new_dumped_transfer_cmd = init_image->dumped_resources.dumped_transfer_command =
                    std::make_unique<DumpedTransferCommand>(DumpResourceType::kInitImageMetaCommand,
                                                            cmd_index,
                                                            qs_index,
                                                            init_image->dst_image,
                                                            &init_image->copied_image.image_info);

                res_info.dumped_resource = new_dumped_transfer_cmd.get();
                host_data.dumped_data    = VulkanDelegateImageDumpedData();

                // Images initialized in the state setup block should be dumpable, otherwise it wouldn't have been
                // possible to be dumped in the capture file in the first place.
                GFXRECON_ASSERT(CanDumpImage(instance_table_,
                                             device_info_->parent,
                                             &init_image->copied_image.image_info) == ImageDumpResult::kCanDump);

                auto& new_dumped_init_image =
                    std::get<DumpedInitImageMetaCommand>(new_dumped_transfer_cmd->dumped_resource);
                auto& dumped_image_host_data = std::get<VulkanDelegateImageDumpedData>(host_data.dumped_data);

                const VkImageSubresourceRange subresource_range = { static_cast<VkImageAspectFlags>(init_image->aspect),
                                                                    0,
                                                                    VK_REMAINING_MIP_LEVELS,
                                                                    0,
                                                                    VK_REMAINING_ARRAY_LAYERS };

                VkResult res = DumpImage(new_dumped_init_image.dumped_image,
                                         VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                         options_.dump_resources_scale,
                                         options_.dump_resources_dump_raw_images,
                                         subresource_range,
                                         dumped_image_host_data.data,
                                         device_info_,
                                         device_table_,
                                         instance_table_,
                                         object_info_table_);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Error dumping image of transfer command (%s)", util::ToString(res).c_str());
                    return res;
                }

                delegate_.DumpResource(res_info);
            }
            break;

            case kCmdCopyBuffer:
            {
                auto* copy_buffer             = static_cast<TransferParams::CopyBuffer*>(base_transfer_cmd);
                auto& new_dumped_transfer_cmd = copy_buffer->dumped_resources.dumped_transfer_command =
                    std::make_unique<DumpedTransferCommand>(DumpResourceType::kCopyBuffer,
                                                            cmd_index,
                                                            qs_index,
                                                            copy_buffer->src_buffer,
                                                            copy_buffer->dst_buffer,
                                                            copy_buffer->has_before_command);
                auto& new_dumped_copy_buffer = std::get<DumpedCopyBuffer>(new_dumped_transfer_cmd->dumped_resource);

                res_info.dumped_resource = new_dumped_transfer_cmd.get();
                host_data.dumped_data    = VulkanDelegateDumpedCopyBufferRegions();

                auto& dumped_regions_host_data = std::get<VulkanDelegateDumpedCopyBufferRegions>(host_data.dumped_data);
                for (const auto& region : copy_buffer->regions)
                {
                    auto& new_dumped_region = new_dumped_copy_buffer.regions.emplace_back(
                        region.region, region.vk_objects.buffer, region.vk_objects.size);

                    auto& host_dumped_region = dumped_regions_host_data.regions_data.emplace_back();

                    VkResult res = DumpBuffer(new_dumped_region.dumped_buffer,
                                              host_dumped_region,
                                              device_info_,
                                              device_table_,
                                              instance_table_,
                                              object_info_table_);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Error dumping buffer of transfer command (%s)",
                                           util::ToString(res).c_str());
                        return res;
                    }
                }

                delegate_.DumpResource(res_info);

                if (copy_buffer->has_before_command)
                {
                    dumped_regions_host_data.regions_data.clear();

                    const auto* copy_buffer_before = static_cast<TransferParams::CopyBuffer*>(cmd.before_params.get());
                    GFXRECON_ASSERT(copy_buffer_before != nullptr);

                    auto* new_dumped_copy_buffer_before =
                        std::get_if<DumpedCopyBuffer>(&new_dumped_transfer_cmd->dumped_resource_before);
                    for (const auto& region : copy_buffer_before->regions)
                    {
                        auto& new_dumped_region_before = new_dumped_copy_buffer_before->regions.emplace_back(
                            region.region, region.vk_objects.buffer, region.region.size);

                        auto& host_dumped_region_before = dumped_regions_host_data.regions_data.emplace_back();

                        VkResult res = DumpBuffer(new_dumped_region_before.dumped_buffer,
                                                  host_dumped_region_before,
                                                  device_info_,
                                                  device_table_,
                                                  instance_table_,
                                                  object_info_table_);
                        if (res != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Error dumping buffer of transfer command (%s)",
                                               util::ToString(res).c_str());
                            return res;
                        }
                    }

                    res_info.before_command = true;
                    delegate_.DumpResource(res_info);
                }
            }
            break;

            case kCmdCopyBufferToImage:
            {
                auto* copy_buffer_to_image = static_cast<TransferParams::CopyBufferToImage*>(base_transfer_cmd);
                const ImageDumpResult can_dump_image =
                    CanDumpImage(instance_table_, device_info_->parent, &copy_buffer_to_image->copied_image.image_info);

                auto& new_dumped_transfer_cmd = copy_buffer_to_image->dumped_resources.dumped_transfer_command =
                    std::make_unique<DumpedTransferCommand>(DumpResourceType::kCopyBufferToImage,
                                                            cmd_index,
                                                            qs_index,
                                                            copy_buffer_to_image->src_buffer,
                                                            copy_buffer_to_image->dst_image,
                                                            copy_buffer_to_image->dst_image_layout,
                                                            copy_buffer_to_image->has_before_command);

                res_info.dumped_resource = new_dumped_transfer_cmd.get();
                host_data.dumped_data    = VulkanDelegateDumpedCopyImageRegions();

                auto& new_dumped_copy_buffer_to_image =
                    std::get<DumpedCopyBufferToImage>(new_dumped_transfer_cmd->dumped_resource);
                auto& dumped_regions_host_data = std::get<VulkanDelegateDumpedCopyImageRegions>(host_data.dumped_data);
                for (const auto& region : copy_buffer_to_image->regions)
                {
                    auto& new_dumped_image_region = new_dumped_copy_buffer_to_image.regions.emplace_back(
                        region.region, &copy_buffer_to_image->copied_image.image_info, can_dump_image);

                    if (can_dump_image != ImageDumpResult::kCanDump)
                    {
                        continue;
                    }

                    auto& new_copy_buffer_to_image_image_region_host_data =
                        dumped_regions_host_data.regions_data.emplace_back();

                    const VkImageSubresourceRange subresource_range = { region.region.imageSubresource.aspectMask,
                                                                        region.region.imageSubresource.mipLevel,
                                                                        1,
                                                                        region.region.imageSubresource.baseArrayLayer,
                                                                        region.region.imageSubresource.layerCount };

                    // Dump region's subresources
                    VkResult res = DumpImage(new_dumped_image_region.dumped_image,
                                             new_dumped_image_region.dumped_image.image_info->intermediate_layout,
                                             options_.dump_resources_scale,
                                             options_.dump_resources_dump_raw_images,
                                             subresource_range,
                                             new_copy_buffer_to_image_image_region_host_data,
                                             device_info_,
                                             device_table_,
                                             instance_table_,
                                             object_info_table_);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Error dumping image of transfer command (%s)", util::ToString(res).c_str());
                        return res;
                    }
                }

                if (can_dump_image == ImageDumpResult::kCanDump)
                {
                    delegate_.DumpResource(res_info);
                }

                if (copy_buffer_to_image->has_before_command)
                {
                    dumped_regions_host_data.regions_data.clear();

                    const auto* copy_buffer_to_image_before =
                        static_cast<TransferParams::CopyBufferToImage*>(cmd.before_params.get());
                    GFXRECON_ASSERT(copy_buffer_to_image_before != nullptr);

                    auto& new_dumped_copy_buffer_to_image_before =
                        std::get<DumpedCopyBufferToImage>(new_dumped_transfer_cmd->dumped_resource_before);
                    for (const auto& region : copy_buffer_to_image_before->regions)
                    {
                        auto& new_dumped_image_region_before =
                            new_dumped_copy_buffer_to_image_before.regions.emplace_back(
                                region.region, &copy_buffer_to_image_before->copied_image.image_info, can_dump_image);

                        if (can_dump_image != ImageDumpResult::kCanDump)
                        {
                            continue;
                        }

                        auto& new_copy_buffer_to_image_image_region_host_data =
                            dumped_regions_host_data.regions_data.emplace_back();

                        const VkImageSubresourceRange subresource_range = {
                            region.region.imageSubresource.aspectMask,
                            region.region.imageSubresource.mipLevel,
                            1,
                            region.region.imageSubresource.baseArrayLayer,
                            region.region.imageSubresource.layerCount
                        };

                        // Dump region's subresources
                        VkResult res =
                            DumpImage(new_dumped_image_region_before.dumped_image,
                                      new_dumped_image_region_before.dumped_image.image_info->intermediate_layout,
                                      options_.dump_resources_scale,
                                      options_.dump_resources_dump_raw_images,
                                      subresource_range,
                                      new_copy_buffer_to_image_image_region_host_data,
                                      device_info_,
                                      device_table_,
                                      instance_table_,
                                      object_info_table_);
                        if (res != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Error dumping image of transfer command (%s)",
                                               util::ToString(res).c_str());
                            return res;
                        }
                    }

                    if (can_dump_image == ImageDumpResult::kCanDump)
                    {
                        res_info.before_command = true;
                        delegate_.DumpResource(res_info);
                    }
                }
            }
            break;

            case kCmdCopyImage:
            {
                auto* copy_image              = static_cast<TransferParams::CopyImage*>(base_transfer_cmd);
                auto& new_dumped_transfer_cmd = copy_image->dumped_resources.dumped_transfer_command =
                    std::make_unique<DumpedTransferCommand>(DumpResourceType::kCopyImage,
                                                            cmd_index,
                                                            qs_index,
                                                            copy_image->src_image,
                                                            copy_image->src_image_layout,
                                                            copy_image->dst_image,
                                                            copy_image->dst_image_layout,
                                                            copy_image->has_before_command);

                res_info.dumped_resource = new_dumped_transfer_cmd.get();
                host_data.dumped_data    = VulkanDelegateDumpedCopyImageRegions();

                const ImageDumpResult can_dump_image =
                    CanDumpImage(instance_table_, device_info_->parent, &copy_image->copied_image.image_info);

                auto& new_dumped_copy_image    = std::get<DumpedCopyImage>(new_dumped_transfer_cmd->dumped_resource);
                auto& dumped_regions_host_data = std::get<VulkanDelegateDumpedCopyImageRegions>(host_data.dumped_data);
                for (const auto& region : copy_image->regions)
                {
                    auto& new_dumped_image_region = new_dumped_copy_image.regions.emplace_back(
                        region.region, &copy_image->copied_image.image_info, can_dump_image);

                    if (can_dump_image != ImageDumpResult::kCanDump)
                    {
                        continue;
                    }

                    auto& new_copy_image_region_host_data = dumped_regions_host_data.regions_data.emplace_back();

                    const VkImageSubresourceRange subresource_range = { region.region.dstSubresource.aspectMask,
                                                                        region.region.dstSubresource.mipLevel,
                                                                        1,
                                                                        region.region.dstSubresource.baseArrayLayer,
                                                                        region.region.dstSubresource.layerCount };

                    // Dump region's subresources
                    VkResult res = DumpImage(new_dumped_image_region.dumped_image,
                                             new_dumped_image_region.dumped_image.image_info->intermediate_layout,
                                             options_.dump_resources_scale,
                                             options_.dump_resources_dump_raw_images,
                                             subresource_range,
                                             new_copy_image_region_host_data,
                                             device_info_,
                                             device_table_,
                                             instance_table_,
                                             object_info_table_);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Error dumping image of transfer command (%s)", util::ToString(res).c_str());
                        return res;
                    }
                }

                if (can_dump_image == ImageDumpResult::kCanDump)
                {
                    delegate_.DumpResource(res_info);
                }

                if (copy_image->has_before_command)
                {
                    dumped_regions_host_data.regions_data.clear();

                    const auto* copy_image_before = static_cast<TransferParams::CopyImage*>(cmd.before_params.get());
                    GFXRECON_ASSERT(copy_image_before != nullptr);

                    auto* new_dumped_copy_image_before =
                        std::get_if<DumpedCopyImage>(&new_dumped_transfer_cmd->dumped_resource_before);
                    GFXRECON_ASSERT(new_dumped_copy_image_before != nullptr);

                    for (const auto& region : copy_image_before->regions)
                    {
                        auto& new_dumped_image_region_before = new_dumped_copy_image_before->regions.emplace_back(
                            region.region, &copy_image_before->copied_image.image_info, can_dump_image);

                        if (can_dump_image != ImageDumpResult::kCanDump)
                        {
                            continue;
                        }

                        auto& new_copy_image_region_host_data = dumped_regions_host_data.regions_data.emplace_back();

                        const VkImageSubresourceRange subresource_range = { region.region.dstSubresource.aspectMask,
                                                                            region.region.dstSubresource.mipLevel,
                                                                            1,
                                                                            region.region.dstSubresource.baseArrayLayer,
                                                                            region.region.dstSubresource.layerCount };

                        // Dump region's subresources
                        VkResult res =
                            DumpImage(new_dumped_image_region_before.dumped_image,
                                      new_dumped_image_region_before.dumped_image.image_info->intermediate_layout,
                                      1.0f,
                                      options_.dump_resources_dump_raw_images,
                                      subresource_range,
                                      new_copy_image_region_host_data,
                                      device_info_,
                                      device_table_,
                                      instance_table_,
                                      object_info_table_);
                        if (res != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Error dumping image of transfer command (%s)",
                                               util::ToString(res).c_str());
                            return res;
                        }
                    }

                    if (can_dump_image == ImageDumpResult::kCanDump)
                    {
                        res_info.before_command = true;
                        delegate_.DumpResource(res_info);
                    }
                }
            }
            break;

            case kCmdCopyImageToBuffer:
            {
                auto* copy_image_to_buffer    = static_cast<TransferParams::CopyImageToBuffer*>(base_transfer_cmd);
                auto& new_dumped_transfer_cmd = copy_image_to_buffer->dumped_resources.dumped_transfer_command =
                    std::make_unique<DumpedTransferCommand>(DumpResourceType::kCopyImageToBuffer,
                                                            cmd_index,
                                                            qs_index,
                                                            copy_image_to_buffer->src_image,
                                                            copy_image_to_buffer->src_image_layout,
                                                            copy_image_to_buffer->dst_buffer,
                                                            copy_image_to_buffer->has_before_command);
                auto& new_dumped_copy_image_to_buffer =
                    std::get<DumpedCopyImageToBuffer>(new_dumped_transfer_cmd->dumped_resource);

                res_info.dumped_resource = new_dumped_transfer_cmd.get();
                host_data.dumped_data    = VulkanDelegateDumpedCopyBufferRegions();

                auto& dumped_regions_host_data = std::get<VulkanDelegateDumpedCopyBufferRegions>(host_data.dumped_data);
                for (const auto& region : copy_image_to_buffer->regions)
                {
                    auto& new_dumped_region = new_dumped_copy_image_to_buffer.regions.emplace_back(
                        region.region, region.vk_objects.buffer, region.vk_objects.size);
                    auto&    host_dumped_region = dumped_regions_host_data.regions_data.emplace_back();
                    VkResult res                = DumpBuffer(new_dumped_region.dumped_buffer,
                                              host_dumped_region,
                                              device_info_,
                                              device_table_,
                                              instance_table_,
                                              object_info_table_);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Error dumping buffer of transfer command (%s)",
                                           util::ToString(res).c_str());
                        return res;
                    }
                }

                delegate_.DumpResource(res_info);

                if (copy_image_to_buffer->has_before_command)
                {
                    dumped_regions_host_data.regions_data.clear();

                    const auto* copy_image_to_buffer_before =
                        static_cast<TransferParams::CopyImageToBuffer*>(cmd.before_params.get());
                    GFXRECON_ASSERT(copy_image_to_buffer_before != nullptr);

                    auto* new_dumped_copy_image_to_buffer_before =
                        std::get_if<DumpedCopyImageToBuffer>(&new_dumped_transfer_cmd->dumped_resource_before);
                    for (const auto& region : copy_image_to_buffer_before->regions)
                    {
                        auto& new_dumped_region_before = new_dumped_copy_image_to_buffer_before->regions.emplace_back(
                            region.region, region.vk_objects.buffer, region.vk_objects.size);

                        auto& host_dumped_region_before = dumped_regions_host_data.regions_data.emplace_back();

                        VkResult res = DumpBuffer(new_dumped_region_before.dumped_buffer,
                                                  host_dumped_region_before,
                                                  device_info_,
                                                  device_table_,
                                                  instance_table_,
                                                  object_info_table_);
                        if (res != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Error dumping buffer of transfer command (%s)",
                                               util::ToString(res).c_str());
                            return res;
                        }
                    }

                    res_info.before_command = true;
                    delegate_.DumpResource(res_info);
                }
            }
            break;

            case kCmdBlitImage:
            {
                auto*                 blit_image = static_cast<TransferParams::BlitImage*>(base_transfer_cmd);
                const ImageDumpResult can_dump_image =
                    CanDumpImage(instance_table_, device_info_->parent, &blit_image->copied_image.image_info);

                auto& new_dumped_transfer_cmd = blit_image->dumped_resources.dumped_transfer_command =
                    std::make_unique<DumpedTransferCommand>(DumpResourceType::kBlitImage,
                                                            cmd_index,
                                                            qs_index,
                                                            blit_image->src_image,
                                                            blit_image->src_image_layout,
                                                            blit_image->dst_image,
                                                            blit_image->dst_image_layout,
                                                            blit_image->filter,
                                                            blit_image->has_before_command);

                res_info.dumped_resource = new_dumped_transfer_cmd.get();
                host_data.dumped_data    = VulkanDelegateDumpedCopyImageRegions();

                auto& new_dumped_blit_image    = std::get<DumpedBlitImage>(new_dumped_transfer_cmd->dumped_resource);
                auto& dumped_regions_host_data = std::get<VulkanDelegateDumpedCopyImageRegions>(host_data.dumped_data);
                for (const auto& region : blit_image->regions)
                {
                    auto& new_dumped_image_region = new_dumped_blit_image.regions.emplace_back(
                        region.region, &blit_image->copied_image.image_info, can_dump_image);

                    if (can_dump_image != ImageDumpResult::kCanDump)
                    {
                        continue;
                    }

                    auto& new_blit_image_region_host_data = dumped_regions_host_data.regions_data.emplace_back();

                    const VkImageSubresourceRange subresource_range = { region.region.dstSubresource.aspectMask,
                                                                        region.region.dstSubresource.mipLevel,
                                                                        1,
                                                                        region.region.dstSubresource.baseArrayLayer,
                                                                        region.region.dstSubresource.layerCount };

                    // Dump region's subresources
                    VkResult res = DumpImage(new_dumped_image_region.dumped_image,
                                             new_dumped_image_region.dumped_image.image_info->intermediate_layout,
                                             options_.dump_resources_scale,
                                             options_.dump_resources_dump_raw_images,
                                             subresource_range,
                                             new_blit_image_region_host_data,
                                             device_info_,
                                             device_table_,
                                             instance_table_,
                                             object_info_table_);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Error dumping image of transfer command (%s)", util::ToString(res).c_str());
                        return res;
                    }
                }

                if (can_dump_image == ImageDumpResult::kCanDump)
                {
                    delegate_.DumpResource(res_info);
                }

                if (blit_image->has_before_command)
                {
                    dumped_regions_host_data.regions_data.clear();

                    const auto* blit_image_before = static_cast<TransferParams::BlitImage*>(cmd.before_params.get());
                    GFXRECON_ASSERT(blit_image_before != nullptr);

                    auto* new_dumped_blit_image_before =
                        std::get_if<DumpedBlitImage>(&new_dumped_transfer_cmd->dumped_resource_before);
                    GFXRECON_ASSERT(new_dumped_blit_image_before != nullptr);

                    for (const auto& region : blit_image_before->regions)
                    {
                        auto& new_dumped_image_region_before = new_dumped_blit_image_before->regions.emplace_back(
                            region.region, &blit_image_before->copied_image.image_info, can_dump_image);

                        if (can_dump_image != ImageDumpResult::kCanDump)
                        {
                            continue;
                        }

                        auto& new_copy_image_region_host_data = dumped_regions_host_data.regions_data.emplace_back();

                        const VkImageSubresourceRange subresource_range = { region.region.dstSubresource.aspectMask,
                                                                            region.region.dstSubresource.mipLevel,
                                                                            1,
                                                                            region.region.dstSubresource.baseArrayLayer,
                                                                            region.region.dstSubresource.layerCount };

                        // Dump region's subresources
                        VkResult res =
                            DumpImage(new_dumped_image_region_before.dumped_image,
                                      new_dumped_image_region_before.dumped_image.image_info->intermediate_layout,
                                      1.0f,
                                      options_.dump_resources_dump_raw_images,
                                      subresource_range,
                                      new_copy_image_region_host_data,
                                      device_info_,
                                      device_table_,
                                      instance_table_,
                                      object_info_table_);
                        if (res != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Error dumping image of transfer command (%s)",
                                               util::ToString(res).c_str());
                            return res;
                        }
                    }

                    if (can_dump_image == ImageDumpResult::kCanDump)
                    {
                        res_info.before_command = true;
                        delegate_.DumpResource(res_info);
                    }
                }
            }
            break;

            case kCmdBuildAccelerationStructures:
            {
                auto* build_as = static_cast<TransferParams::BuildAccelerationStructure*>(base_transfer_cmd);
                auto& new_dumped_transfer_cmd = build_as->dumped_resources.dumped_transfer_command =
                    std::make_unique<DumpedTransferCommand>(DumpResourceType::kBuildAccelerationStructure,
                                                            cmd_index,
                                                            qs_index,
                                                            build_as->has_before_command);
                auto& new_dumped_build_as =
                    std::get<DumpedBuildAccelerationStructure>(new_dumped_transfer_cmd->dumped_resource);

                res_info.dumped_resource = new_dumped_transfer_cmd.get();
                host_data.dumped_data    = VulkanDelegateDumpedBuildAccelerationStructures();

                auto& host_dumped_build_infos =
                    std::get<VulkanDelegateDumpedBuildAccelerationStructures>(host_data.dumped_data);

                for (auto& build_info : build_as->build_infos)
                {
                    auto& new_dumped_build_info = new_dumped_build_as.dumped_build_infos.emplace_back(
                        build_info.src_as,
                        build_info.dst_as,
                        build_info.mode,
                        &build_info.vk_objects.as_info,
                        options_.dump_resources_dump_build_AS_input_buffers);
                    auto& new_host_data_build_info = host_dumped_build_infos.data.emplace_back();

                    VkResult res = DumpAccelerationStructure(new_dumped_build_info.dumped_as,
                                                             new_host_data_build_info,
                                                             &build_info.vk_objects.as_context,
                                                             acceleration_structures_context_,
                                                             device_info_,
                                                             *device_table_,
                                                             object_info_table_,
                                                             *instance_table_,
                                                             address_trackers_);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Error dumping build acceleration structure command (%s)",
                                           util::ToString(res).c_str());
                        return res;
                    }
                }

                delegate_.DumpResource(res_info);

                if (build_as->has_before_command)
                {
                    host_dumped_build_infos.data.clear();

                    auto* build_as_before =
                        static_cast<TransferParams::BuildAccelerationStructure*>(cmd.before_params.get());

                    auto* new_dumped_build_as_before =
                        std::get_if<DumpedBuildAccelerationStructure>(&new_dumped_transfer_cmd->dumped_resource_before);
                    GFXRECON_ASSERT(new_dumped_build_as_before != nullptr);

                    for (auto& build_info : build_as_before->build_infos)
                    {
                        auto& new_dumped_build_info = new_dumped_build_as_before->dumped_build_infos.emplace_back(
                            build_info.src_as,
                            build_info.dst_as,
                            build_info.mode,
                            &build_info.vk_objects.as_info,
                            options_.dump_resources_dump_build_AS_input_buffers);
                        auto& new_host_data_build_info = host_dumped_build_infos.data.emplace_back();

                        VkResult res = DumpAccelerationStructure(new_dumped_build_info.dumped_as,
                                                                 new_host_data_build_info,
                                                                 &build_info.vk_objects.as_context,
                                                                 acceleration_structures_context_,
                                                                 device_info_,
                                                                 *device_table_,
                                                                 object_info_table_,
                                                                 *instance_table_,
                                                                 address_trackers_);
                        if (res != VK_SUCCESS)
                        {
                            GFXRECON_LOG_ERROR("Error dumping build acceleration structure command (%s)",
                                               util::ToString(res).c_str());
                            return res;
                        }
                    }

                    res_info.before_command = true;
                    delegate_.DumpResource(res_info);
                }
            }
            break;

            case kCmdCopyAccelerationStructure:
            {
                auto* copy_as = static_cast<TransferParams::CopyAccelerationStructure*>(base_transfer_cmd);
                auto& new_dumped_transfer_cmd = copy_as->dumped_resources.dumped_transfer_command =
                    std::make_unique<DumpedTransferCommand>(DumpResourceType::kCopyAccelerationStructure,
                                                            cmd_index,
                                                            qs_index,
                                                            copy_as->src_as,
                                                            copy_as->dst_as,
                                                            copy_as->mode,
                                                            &copy_as->vk_objects.as_info,
                                                            options_.dump_resources_dump_build_AS_input_buffers,
                                                            copy_as->has_before_command);
                auto& new_dumped_copy_as =
                    std::get<DumpedCopyAccelerationStructure>(new_dumped_transfer_cmd->dumped_resource);

                res_info.dumped_resource = new_dumped_transfer_cmd.get();
                host_data.dumped_data    = VulkanDelegateDumpedCopyAccelerationStructure();

                auto& host_dumped_copy_info =
                    std::get<VulkanDelegateDumpedCopyAccelerationStructure>(host_data.dumped_data);

                VkResult res = DumpAccelerationStructure(new_dumped_copy_as.dumped_copy_info.dumped_as,
                                                         host_dumped_copy_info.data,
                                                         &copy_as->vk_objects.as_context,
                                                         acceleration_structures_context_,
                                                         device_info_,
                                                         *device_table_,
                                                         object_info_table_,
                                                         *instance_table_,
                                                         address_trackers_);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Error dumping build acceleration structure command (%s)",
                                       util::ToString(res).c_str());
                    return res;
                }

                delegate_.DumpResource(res_info);

                if (copy_as->has_before_command)
                {
                    host_dumped_copy_info.data.clear();
                    auto* copy_as_before =
                        static_cast<TransferParams::CopyAccelerationStructure*>(cmd.before_params.get());
                    auto& new_dumped_copy_as_before =
                        std::get<DumpedCopyAccelerationStructure>(new_dumped_transfer_cmd->dumped_resource_before);

                    VkResult res = DumpAccelerationStructure(new_dumped_copy_as_before.dumped_copy_info.dumped_as,
                                                             host_dumped_copy_info.data,
                                                             &copy_as_before->vk_objects.as_context,
                                                             acceleration_structures_context_,
                                                             device_info_,
                                                             *device_table_,
                                                             object_info_table_,
                                                             *instance_table_,
                                                             address_trackers_);
                    if (res != VK_SUCCESS)
                    {
                        GFXRECON_LOG_ERROR("Error dumping build acceleration structure command (%s)",
                                           util::ToString(res).c_str());
                        return res;
                    }

                    res_info.before_command = true;
                    delegate_.DumpResource(res_info);
                }
            }
            break;

            default:
                GFXRECON_LOG_ERROR("%s() Unhandled dump resources type", __func__)
                GFXRECON_ASSERT(0);
        }

        const VulkanDelegateDumpDrawCallContext transfer_info{
            DumpResourcesPipelineStage::kTransfer, instance_table_, device_table_, &cmd
        };

        delegate_.DumpDrawCallInfo(transfer_info);
    }

    if (!qs_index)
    {
        delegate_.DumpEnd();
    }

    Release();

    return VK_SUCCESS;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
