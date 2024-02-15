/*
** Copyright (c) 2023 LunarG, Inc.
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

#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "graphics/vulkan_resources_util.h"
#include "util/image_writer.h"
#include "util/buffer_writer.h"
#include "vulkan_replay_dump_resources.h"

#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <sstream>
#if !defined(WIN32)
#include <dirent.h>
#endif

#define DELETE_STALE_DUMP_FILES

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

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

static util::imagewriter::DataFormats VkFormatToImageWriterDataFormat(VkFormat format)
{
    switch (format)
    {
        case VK_FORMAT_R8G8B8_UNORM:
            return util::imagewriter::DataFormats::kFormat_RGB;

        case VK_FORMAT_R8G8B8A8_UNORM:
            return util::imagewriter::DataFormats::kFormat_RGBA;

        case VK_FORMAT_B8G8R8_UNORM:
            return util::imagewriter::DataFormats::kFormat_BGR;

        case VK_FORMAT_R16G16B16A16_SFLOAT:
            return util::imagewriter::DataFormats::kFormat_R16G16B16A16_SFLOAT;

        case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
            return util::imagewriter::DataFormats::kFormat_B10G11R11_UFLOAT;

        case VK_FORMAT_B8G8R8A8_UNORM:
            return util::imagewriter::DataFormats::kFormat_BGRA;

        case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
            return util::imagewriter::DataFormats::kFormat_A2B10G10R10;

        case VK_FORMAT_D32_SFLOAT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return util::imagewriter::DataFormats::kFormat_D32_FLOAT;

        case VK_FORMAT_X8_D24_UNORM_PACK32:
            return util::imagewriter::DataFormats::kFormat_D24_UNORM;

        case VK_FORMAT_D16_UNORM:
            return util::imagewriter::DataFormats::kFormat_D16_UNORM;

        default:
            GFXRECON_LOG_WARNING("%s() failed to handle format %s. Will dump as a plain binary file.",
                                 __func__,
                                 util::ToString<VkFormat>(format).c_str());
            return util::imagewriter::DataFormats::kFormat_UNSPECIFIED;
    }
}

static uint32_t GetMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                                   uint32_t                                type_bits,
                                   VkMemoryPropertyFlags                   property_flags)
{
    uint32_t memory_type_index = std::numeric_limits<uint32_t>::max();

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        if ((type_bits & (1 << i)) &&
            ((memory_properties.memoryTypes[i].propertyFlags & property_flags) == property_flags))
        {
            memory_type_index = i;
            break;
        }
    }

    return memory_type_index;
}

VulkanReplayDumpResourcesBase::VulkanReplayDumpResourcesBase(const VulkanReplayOptions&   options,
                                                             const VulkanObjectInfoTable& object_info_table) :
    QueueSubmit_indices_(options.QueueSubmit_Indices),
    recording_(false), dump_resources_before_(options.dump_resources_before), object_info_table_(object_info_table)
{
    if (!options.Draw_Indices.size() && !options.Dispatch_Indices.size() && !options.TraceRays_Indices.size())
    {
        return;
    }

    for (size_t i = 0; i < options.BeginCommandBuffer_Indices.size(); ++i)
    {
        const uint64_t bcb_index = options.BeginCommandBuffer_Indices[i];

        if (i < options.Draw_Indices.size() && options.Draw_Indices[i].size())
        {
            draw_call_contexts.emplace(bcb_index,
                                       DrawCallsDumpingContext(options.Draw_Indices[i].size() ? options.Draw_Indices[i]
                                                                                              : std::vector<uint64_t>(),
                                                               options.RenderPass_Indices[i].size()
                                                                   ? options.RenderPass_Indices[i]
                                                                   : std::vector<std::vector<uint64_t>>(),
                                                               object_info_table,
                                                               options.dump_resources_before,
                                                               options.dump_resources_output_path,
                                                               options.dump_resources_image_format,
                                                               options.dump_resources_scale));
        }

        if ((i < options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size()) ||
            (i < options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size()))
        {
            dispatch_ray_contexts.emplace(bcb_index,
                                          DispatchTraceRaysDumpingContext(
                                              (options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size())
                                                  ? options.Dispatch_Indices[i]
                                                  : std::vector<uint64_t>(),
                                              (options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size())
                                                  ? options.TraceRays_Indices[i]
                                                  : std::vector<uint64_t>(),
                                              object_info_table_,
                                              options.dump_resources_before,
                                              options.dump_resources_output_path,
                                              options.dump_resources_image_format,
                                              options.dump_resources_scale));
        }
    }

#if defined(__ANDROID__) && defined(DELETE_STALE_DUMP_FILES)
    // On Android there is an issue with files which are manually deleted (for example from adb shell) then fopen with
    // "wb" might fail with the error that the file already exists. Deleting the file from code can workaround this
    DIR* dump_resource_dir = opendir(options.dump_resources_output_path.c_str());
    if (dump_resource_dir != nullptr)
    {
        struct dirent* dir;
        while ((dir = readdir(dump_resource_dir)) != nullptr)
        {
            const int len = strlen(dir->d_name);
            if (len > 3)
            {
                const char* file_extension = &dir->d_name[len - 3];

                if (!strcmp(file_extension, "bmp") || !strcmp(file_extension, "png") || !strcmp(file_extension, "bin"))
                {
                    std::string full_path = options.dump_resources_output_path + std::string(dir->d_name);
                    GFXRECON_LOG_INFO("Deleting file %s", full_path.c_str());
                    if (remove(full_path.c_str()))
                    {
                        GFXRECON_LOG_ERROR(" Failed to delete file %s (%s)", dir->d_name, strerror(errno));
                    }
                }
            }
        }
    }
#endif
}

VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer)
{
    auto begin_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (begin_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    auto context_entry = draw_call_contexts.find(begin_entry->second);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

const VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer) const
{
    auto begin_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (begin_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    const auto context_entry = draw_call_contexts.find(begin_entry->second);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    const DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(uint64_t bcb_id)
{
    auto context_entry = draw_call_contexts.find(bcb_id);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

const VulkanReplayDumpResourcesBase::DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(uint64_t bcb_id) const
{
    const auto context_entry = draw_call_contexts.find(bcb_id);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    const DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(uint64_t bcb_id)
{
    auto context_entry = dispatch_ray_contexts.find(bcb_id);
    if (context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    DispatchTraceRaysDumpingContext* context = &context_entry->second;
    return context;
}

const VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(uint64_t bcb_id) const
{
    const auto context_entry = dispatch_ray_contexts.find(bcb_id);
    if (context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    const DispatchTraceRaysDumpingContext* context = &context_entry->second;
    return context;
}

VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer)
{
    auto bcb_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (bcb_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    auto dr_context_entry = dispatch_ray_contexts.find(bcb_entry->second);
    if (dr_context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    DispatchTraceRaysDumpingContext* context = &dr_context_entry->second;
    return context;
}

const VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer) const
{
    const auto bcb_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (bcb_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    const auto dr_context_entry = dispatch_ray_contexts.find(bcb_entry->second);
    if (dr_context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    const DispatchTraceRaysDumpingContext* context = &dr_context_entry->second;
    return context;
}

VkResult VulkanReplayDumpResourcesBase::CloneCommandBuffer(uint64_t                   bcb_index,
                                                           const CommandBufferInfo*   original_command_buffer_info,
                                                           const encode::DeviceTable* device_table)
{
    assert(device_table);

    GFXRECON_WRITE_CONSOLE("%s(bcb_index: %" PRIu64 ", original_command_buffer_info: %" PRIu64 ")",
                           __func__,
                           bcb_index,
                           original_command_buffer_info->capture_id);

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(bcb_index);
    if (dc_context != nullptr)
    {
        VkResult res = dc_context->CloneCommandBuffer(original_command_buffer_info, device_table);
        if (res == VK_SUCCESS)
        {
            recording_ = true;

            assert(cmd_buf_begin_map_.find(original_command_buffer_info->handle) == cmd_buf_begin_map_.end());
            cmd_buf_begin_map_[original_command_buffer_info->handle] = bcb_index;
        }
        else
        {
            return res;
        }
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(bcb_index);
    if (dr_context != nullptr)
    {
        VkResult res = dr_context->CloneCommandBuffer(original_command_buffer_info, device_table);
        if (res == VK_SUCCESS)
        {
            recording_ = true;

            assert(cmd_buf_begin_map_.find(original_command_buffer_info->handle) == cmd_buf_begin_map_.end());
            cmd_buf_begin_map_[original_command_buffer_info->handle] = bcb_index;
        }
        else
        {
            return res;
        }
    }

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::FinalizeCommandBuffer()
{
    GFXRECON_WRITE_CONSOLE("  Finalizing command buffer %u (out of %zu) dc: %" PRIu64,
                           current_cb_index,
                           command_buffers.size(),
                           dc_indices[CmdBufToDCVectorIndex(current_cb_index)]);

    assert(current_cb_index < command_buffers.size());
    VkCommandBuffer current_clone = command_buffers[current_cb_index];
    assert(device_table != nullptr);

    assert(inside_renderpass);
    if (inside_renderpass)
    {
        device_table->CmdEndRenderPass(current_clone);
    }

    device_table->EndCommandBuffer(current_clone);

    // Increment index of command buffer that is going to be finalized next
    ++current_cb_index;
}

void VulkanReplayDumpResourcesBase::FinalizeDrawCallCommandBuffer(VkCommandBuffer original_command_buffer)
{
    DrawCallsDumpingContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
    assert(context);

    context->FinalizeCommandBuffer();

    UpdateRecordingStatus();
}

void VulkanReplayDumpResourcesBase::OverrideCmdDraw(const ApiCallInfo& call_info,
                                                    PFN_vkCmdDraw      func,
                                                    VkCommandBuffer    original_command_buffer,
                                                    uint32_t           vertexCount,
                                                    uint32_t           instanceCount,
                                                    uint32_t           firstVertex,
                                                    uint32_t           firstInstance)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexed(const ApiCallInfo&   call_info,
                                                           PFN_vkCmdDrawIndexed func,
                                                           VkCommandBuffer      original_command_buffer,
                                                           uint32_t             indexCount,
                                                           uint32_t             instanceCount,
                                                           uint32_t             firstIndex,
                                                           int32_t              vertexOffset,
                                                           uint32_t             firstInstance)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndirect(const ApiCallInfo&    call_info,
                                                            PFN_vkCmdDrawIndirect func,
                                                            VkCommandBuffer       original_command_buffer,
                                                            VkBuffer              buffer,
                                                            VkDeviceSize          offset,
                                                            uint32_t              drawCount,
                                                            uint32_t              stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, drawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, drawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexedIndirect(const ApiCallInfo&           call_info,
                                                                   PFN_vkCmdDrawIndexedIndirect func,
                                                                   VkCommandBuffer              original_command_buffer,
                                                                   VkBuffer                     buffer,
                                                                   VkDeviceSize                 offset,
                                                                   uint32_t                     drawCount,
                                                                   uint32_t                     stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, drawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, drawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndirectCount(const ApiCallInfo&         call_info,
                                                                 PFN_vkCmdDrawIndirectCount func,
                                                                 VkCommandBuffer            original_command_buffer,
                                                                 VkBuffer                   buffer,
                                                                 VkDeviceSize               offset,
                                                                 VkBuffer                   countBuffer,
                                                                 VkDeviceSize               countBufferOffset,
                                                                 uint32_t                   maxDrawCount,
                                                                 uint32_t                   stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexedIndirectCount(const ApiCallInfo&                call_info,
                                                                        PFN_vkCmdDrawIndexedIndirectCount func,
                                                                        VkCommandBuffer original_command_buffer,
                                                                        VkBuffer        buffer,
                                                                        VkDeviceSize    offset,
                                                                        VkBuffer        countBuffer,
                                                                        VkDeviceSize    countBufferOffset,
                                                                        uint32_t        maxDrawCount,
                                                                        uint32_t        stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndirectCountKHR(const ApiCallInfo&            call_info,
                                                                    PFN_vkCmdDrawIndirectCountKHR func,
                                                                    VkCommandBuffer original_command_buffer,
                                                                    VkBuffer        buffer,
                                                                    VkDeviceSize    offset,
                                                                    VkBuffer        countBuffer,
                                                                    VkDeviceSize    countBufferOffset,
                                                                    uint32_t        maxDrawCount,
                                                                    uint32_t        stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexedIndirectCountKHR(const ApiCallInfo& call_info,
                                                                           PFN_vkCmdDrawIndexedIndirectCountKHR func,
                                                                           VkCommandBuffer original_command_buffer,
                                                                           VkBuffer        buffer,
                                                                           VkDeviceSize    offset,
                                                                           VkBuffer        countBuffer,
                                                                           VkDeviceSize    countBufferOffset,
                                                                           uint32_t        maxDrawCount,
                                                                           uint32_t        stride)
{
    assert(IsRecording(original_command_buffer));

    if (dump_resources_before_ && ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    if (ShouldDumpDrawCall(original_command_buffer, call_info.index))
    {
        FinalizeDrawCallCommandBuffer(original_command_buffer);
    }
}

bool VulkanReplayDumpResourcesBase::ShouldDumpDrawCall(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DrawCallsDumpingContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (context != nullptr)
    {
        return context->ShouldDumpDrawCall(index);
    }
    else
    {
        return false;
    }
}

bool VulkanReplayDumpResourcesBase::ShouldDumpDispatch(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    if (context != nullptr)
    {
        return context->ShouldDumpDispatch(index);
    }
    else
    {
        return false;
    }
}

bool VulkanReplayDumpResourcesBase::ShouldDumpTraceRays(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    if (context != nullptr)
    {
        return context->ShouldDumpTraceRays(index);
    }
    else
    {
        return false;
    }
}

bool VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::ShouldDumpDrawCall(uint64_t index) const
{
    // Indices should be sorted
    if (!IsInsideRange(dc_indices, index))
    {
        return false;
    }

    for (size_t i = dump_resources_before ? current_cb_index / 2 : current_cb_index; i < dc_indices.size(); ++i)
    {
        if (index == dc_indices[i])
        {
            return true;
        }
        else if (index > dc_indices[i])
        {
            // Indices should be sorted
            return false;
        }
    }

    return false;
}

bool VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::ShouldHandleRenderPass(uint64_t index) const
{
    for (const auto& rp : RP_indices)
    {
        if (IsInsideRange(rp, index))
        {
            return true;
        }
    }

    return false;
}

VkResult VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::DumpDrawCallsAttachments(VkQueue  queue,
                                                                                          uint64_t bcb_index)
{
    BackUpMutableResources(queue);

    const size_t n_drawcalls = command_buffers.size();
    for (size_t cb = 0; cb < n_drawcalls; ++cb)
    {
        GFXRECON_WRITE_CONSOLE("Submitting CB/DC %u of %zu (idx: %" PRIu64 ") for BeginCommandBuffer: %" PRIu64,
                               cb,
                               n_drawcalls,
                               dc_indices[CmdBufToDCVectorIndex(cb)],
                               bcb_index);

        VkSubmitInfo submit_info;
        submit_info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submit_info.pNext                = nullptr;
        submit_info.waitSemaphoreCount   = 0;
        submit_info.pWaitSemaphores      = nullptr;
        submit_info.pWaitDstStageMask    = nullptr;
        submit_info.commandBufferCount   = 1;
        submit_info.pCommandBuffers      = &command_buffers[cb];
        submit_info.signalSemaphoreCount = 0;
        submit_info.pSignalSemaphores    = nullptr;

        RevertMutableResources(queue);

        const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
        assert(device_info);

        const VkFenceCreateInfo ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
        VkFence                 submission_fence;
        VkResult                res = device_table->CreateFence(device_info->handle, &ci, nullptr, &submission_fence);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("CreateFence failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

        res = device_table->QueueSubmit(queue, 1, &submit_info, submission_fence);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
            return res;
        }

        // Wait
        res = device_table->WaitForFences(device_info->handle, 1, &submission_fence, VK_TRUE, ~0UL);
        if (res != VK_SUCCESS)
        {
            device_table->DestroyFence(device_info->handle, submission_fence, nullptr);
            GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

        device_table->DestroyFence(device_info->handle, submission_fence, nullptr);

        // Dump resources
        DumpRenderTargetAttachments(cb);

        // Revert render attachments layouts
        // res = RevertRenderTargetImageLayouts(dc_context, queue, dc_indices[cb]);
        // assert(res == VK_SUCCESS);
        // if (res != VK_SUCCESS)
        // {
        //     return res;
        // }
    }

    return VK_SUCCESS;
}

#define DEPTH_ATTACHMENT ~0

std::string VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::GenerateImageFilename(VkFormat format,
                                                                                          uint64_t cmd_buf_index,
                                                                                          uint64_t dc_index,
                                                                                          int attachment_index) const
{
    util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(format);

    std::vector<VkImageAspectFlagBits> aspects;
    bool                               combined_depth_stencil;
    graphics::GetFormatAspects(format, &aspects, &combined_depth_stencil);

    std::string aspect_str_whole(util::ToString<VkImageAspectFlagBits>(aspects[0]));
    std::string aspect_str(aspect_str_whole.begin() + 16, aspect_str_whole.end() - 4);
    std::string attachment_str =
        attachment_index != DEPTH_ATTACHMENT ? "_att_" + std::to_string(attachment_index) : "_depth_att_";

    std::stringstream filename;
    if (VkFormatToImageWriterDataFormat(format) != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
    {
        if (dump_resources_before)
        {
            filename << dump_resource_path << "Draw_" << ((cmd_buf_index % 2) ? "after_" : "before_") << dc_index
                     << attachment_str << "_aspect_" << aspect_str << util::ScreenshotFormatToCStr(image_file_format);
        }
        else
        {
            filename << dump_resource_path << "Draw_" << dc_index << attachment_str << "_aspect_" << aspect_str
                     << util::ScreenshotFormatToCStr(image_file_format);
        }
    }
    else
    {
        if (dump_resources_before)
        {
            filename << dump_resource_path << "Draw_" << ((cmd_buf_index % 2) ? "after_" : "before_") << dc_index
                     << attachment_str << "_aspect_" << aspect_str << ".bin";
        }
        else
        {
            filename << dump_resource_path << "Draw_" << dc_index << attachment_str << "_aspect_" << aspect_str
                     << ".bin";
        }
    }

    return filename.str();
}

VkResult
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::DumpRenderTargetAttachments(uint64_t cmd_buf_index) const
{
    assert(device_table != nullptr);

    const size_t                dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_index)];
    const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
    const uint64_t              rp       = RP_index.first;
    const uint64_t              sp       = RP_index.second;

    if (!render_targets_[rp][sp].color_att_imgs.size() && render_targets_[rp][sp].depth_att_img == nullptr)
    {
        return VK_SUCCESS;
    }

    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(
        device_info->handle, *device_table, *phys_dev_info->replay_device_info->memory_properties);

    // Dump color attachments
    for (size_t i = 0; i < render_targets_[rp][sp].color_att_imgs.size(); ++i)
    {
        const ImageInfo* image_info = render_targets_[rp][sp].color_att_imgs[i];

        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;

        VkResult res = resource_util.ReadFromImageResourceStaging(
            image_info->handle,
            image_info->format,
            image_info->type,
            VkExtent3D{ render_area_[rp].extent.width, render_area_[rp].extent.height, 1 },
            image_info->level_count,
            image_info->layer_count,
            image_info->tiling,
            image_info->sample_count,
            // All ender targets should be transitioned by the
            // custom render passes into TRANSFER_SRC_OPTIMAL
            VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
            0,
            VK_IMAGE_ASPECT_COLOR_BIT,
            data,
            subresource_offsets,
            subresource_sizes,
            false,
            dump_resources_scale);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);
        const std::string              filename = GenerateImageFilename(image_info->format, cmd_buf_index, dc_index, i);
        if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            const uint32_t texel_size = vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_COLOR_BIT);
            const uint32_t stride     = texel_size * image_info->extent.width * dump_resources_scale;

            if (image_file_format == util::ScreenshotFormat::kBmp)
            {
                util::imagewriter::WriteBmpImage(filename,
                                                 image_info->extent.width * dump_resources_scale,
                                                 image_info->extent.height * dump_resources_scale,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
            else if (image_file_format == util::ScreenshotFormat::kPng)
            {
                util::imagewriter::WritePngImage(filename,
                                                 image_info->extent.width * dump_resources_scale,
                                                 image_info->extent.height * dump_resources_scale,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
        }
        else
        {
            util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
        }
    }

    // Dump depth attachment
    if (render_targets_[rp][sp].depth_att_img != nullptr)
    {
        const ImageInfo* image_info = render_targets_[rp][sp].depth_att_img;

        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;

        VkResult res = resource_util.ReadFromImageResourceStaging(
            image_info->handle,
            image_info->format,
            image_info->type,
            VkExtent3D{ render_area_[rp].extent.width, render_area_[rp].extent.height, 1 },
            image_info->level_count,
            image_info->layer_count,
            image_info->tiling,
            image_info->sample_count,
            // All ender targets should be transitioned by the
            // custom render passes into TRANSFER_SRC_OPTIMAL
            VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
            0,
            VK_IMAGE_ASPECT_DEPTH_BIT,
            data,
            subresource_offsets,
            subresource_sizes,
            false,
            dump_resources_scale);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);
        const std::string              filename =
            GenerateImageFilename(image_info->format, cmd_buf_index, dc_index, DEPTH_ATTACHMENT);
        if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            // This is a bit awkward
            const uint32_t texel_size =
                image_info->format != VK_FORMAT_X8_D24_UNORM_PACK32
                    ? vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_DEPTH_BIT)
                    : 4;
            const uint32_t stride = texel_size * image_info->extent.width * dump_resources_scale;

            if (image_file_format == util::ScreenshotFormat::kBmp)
            {
                util::imagewriter::WriteBmpImage(filename,
                                                 image_info->extent.width * dump_resources_scale,
                                                 image_info->extent.height * dump_resources_scale,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
            else
            {
                util::imagewriter::WritePngImage(filename,
                                                 image_info->extent.width * dump_resources_scale,
                                                 image_info->extent.height * dump_resources_scale,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
        }
        else
        {
            util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
        }
    }

    return VK_SUCCESS;
}

VkResult VulkanReplayDumpResourcesBase::QueueSubmit(std::vector<VkSubmitInfo>  modified_submit_infos,
                                                    const encode::DeviceTable& device_table,
                                                    VkQueue                    queue,
                                                    VkFence                    fence,
                                                    uint64_t                   index)
{
    bool     pre_submit = false;
    bool     submitted  = false;
    VkResult res;

    // First do a submission with all command buffer except the ones we are interested in
    std::vector<VkSubmitInfo>                 submit_infos_copy = modified_submit_infos;
    std::vector<std::vector<VkCommandBuffer>> modified_command_buffer_handles(submit_infos_copy.size());
    for (size_t s = 0; s < submit_infos_copy.size(); s++)
    {
        size_t     command_buffer_count   = submit_infos_copy[s].commandBufferCount;
        const auto command_buffer_handles = submit_infos_copy[s].pCommandBuffers;

        for (uint32_t o = 0; o < command_buffer_count; ++o)
        {
            auto bcb_entry = cmd_buf_begin_map_.find(command_buffer_handles[o]);
            if (bcb_entry != cmd_buf_begin_map_.end())
            {
                continue;
            }
            else
            {
                pre_submit = true;
                modified_command_buffer_handles[s].push_back(command_buffer_handles[o]);
            }
        }

        if (modified_command_buffer_handles[s].size())
        {
            submit_infos_copy[s].commandBufferCount = modified_command_buffer_handles[s].size();
            submit_infos_copy[s].pCommandBuffers    = modified_command_buffer_handles[s].data();
        }
        else
        {
            submit_infos_copy.erase(submit_infos_copy.begin() + s);
        }
    }

    if (pre_submit)
    {
        assert(submit_infos_copy.size());

        res = device_table.QueueSubmit(queue, submit_infos_copy.size(), submit_infos_copy.data(), VK_NULL_HANDLE);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
            goto error;
        }

        // Wait
        res = device_table.QueueWaitIdle(queue);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("QueueWaitIdle failed with %s", util::ToString<VkResult>(res).c_str());
            goto error;
        }
    }

    for (size_t s = 0; s < modified_submit_infos.size(); s++)
    {
        size_t     command_buffer_count   = modified_submit_infos[s].commandBufferCount;
        const auto command_buffer_handles = modified_submit_infos[s].pCommandBuffers;

        // Don't wait and don't signal any semaphores
        if (command_buffer_count)
        {
            modified_submit_infos[s].waitSemaphoreCount   = 0;
            modified_submit_infos[s].pWaitSemaphores      = nullptr;
            modified_submit_infos[s].pWaitDstStageMask    = nullptr;
            modified_submit_infos[s].signalSemaphoreCount = 0;
            modified_submit_infos[s].pSignalSemaphores    = nullptr;
        }

        for (uint32_t o = 0; o < command_buffer_count; ++o)
        {
            DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(command_buffer_handles[o]);
            if (dc_context != nullptr)
            {
                assert(cmd_buf_begin_map_.find(command_buffer_handles[o]) != cmd_buf_begin_map_.end());

                res = dc_context->DumpDrawCallsAttachments(queue, cmd_buf_begin_map_[command_buffer_handles[o]]);
                if (res == VK_SUCCESS)
                {
                    submitted = true;
                }
                else
                {
                    goto error;
                }
            }

            DispatchTraceRaysDumpingContext* dr_context =
                FindDispatchRaysCommandBufferContext(command_buffer_handles[o]);
            if (dr_context != nullptr)
            {
                assert(cmd_buf_begin_map_.find(command_buffer_handles[o]) != cmd_buf_begin_map_.end());
                res =
                    dr_context->DumpDispatchRaysMutableResources(queue, cmd_buf_begin_map_[command_buffer_handles[o]]);

                if (res == VK_SUCCESS)
                {
                    submitted = true;
                }
                else
                {
                    goto error;
                }
            }
        }
    }

    assert(res >= 0);

    // Looks like we didn't submit anything. Do the submission as it would have been done
    // without further modifications
    if (!submitted)
    {
        res = device_table.QueueSubmit(queue, modified_submit_infos.size(), modified_submit_infos.data(), fence);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        }
    }
    else
    {
        assert(index == QueueSubmit_indices_[0]);
        QueueSubmit_indices_.erase(QueueSubmit_indices_.begin());

        // Once all submissions are complete terminate process
        if (QueueSubmit_indices_.size() == 0)
        {
            exit(0);
        }
    }

error:
    if (res < 0)
    {
        GFXRECON_LOG_ERROR("Something went wrong. Terminating.")
        exit(0);
    }

    return res;
}

VkResult
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::CloneCommandBuffer(const CommandBufferInfo*   orig_cmd_buf_info,
                                                                           const encode::DeviceTable* dev_table)
{
    assert(orig_cmd_buf_info);
    assert(dev_table);

    const CommandPoolInfo* cb_pool_info = object_info_table.GetCommandPoolInfo(orig_cmd_buf_info->pool_id);

    const VkCommandBufferAllocateInfo ai{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                          nullptr,
                                          cb_pool_info->handle,
                                          VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                                          1 };

    const DeviceInfo* dev_info = object_info_table.GetDeviceInfo(orig_cmd_buf_info->parent_id);

    GFXRECON_WRITE_CONSOLE("Allocating %zu command buffers for draw call command buffer context:",
                           command_buffers.size())
    for (size_t i = 0; i < command_buffers.size(); ++i)
    {
        assert(command_buffers[i] == VK_NULL_HANDLE);
        VkResult res = dev_table->AllocateCommandBuffers(dev_info->handle, &ai, &command_buffers[i]);

        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }

        const VkCommandBufferBeginInfo bi{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
        dev_table->BeginCommandBuffer(command_buffers[i], &bi);
    }

    GFXRECON_WRITE_CONSOLE("Done")

    assert(original_command_buffer_info == nullptr);
    original_command_buffer_info = orig_cmd_buf_info;

    assert(device_table == nullptr);
    device_table = dev_table;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info->parent_id != format::kNullHandleId);
    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    assert(phys_dev_info->replay_device_info);
    assert(phys_dev_info->replay_device_info->memory_properties.get());
    replay_device_phys_mem_props = phys_dev_info->replay_device_info->memory_properties.get();

    // Allocate auxiliary command buffer
    VkResult res = device_table->AllocateCommandBuffers(dev_info->handle, &ai, &aux_command_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
        assert(0);
        return res;
    }

    const VkFenceCreateInfo ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
    res                        = device_table->CreateFence(dev_info->handle, &ci, nullptr, &aux_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateFence failed with %s", util::ToString<VkResult>(res).c_str());
        assert(0);
        return res;
    }

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::BindDescriptorSets(
    VkPipelineBindPoint                          pipeline_bind_point,
    VkPipelineLayout                             layout,
    uint32_t                                     first_set,
    const std::vector<const DescriptorSetInfo*>& descriptor_sets_infos,
    uint32_t                                     dynamicOffsetCount,
    const uint32_t*                              pDynamicOffsets)
{
    PipelineBindPoints bind_point = VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);

    for (size_t i = 0; i < descriptor_sets_infos.size(); ++i)
    {
        for (const auto& binding : descriptor_sets_infos[i]->descriptors)
        {
            switch (binding.second.desc_type)
            {
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                {
                    const ImageViewInfo* img_view_info =
                        object_info_table.GetImageViewInfo(binding.second.image_info.image_view_id);
                    assert(img_view_info);

                    const ImageInfo* img_info = object_info_table.GetImageInfo(img_view_info->image_id);
                    assert(img_info);

                    bound_descriptor_sets[bind_point][first_set + i].image_infos[binding.first] = img_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    const BufferInfo* buffer_info =
                        object_info_table.GetBufferInfo(binding.second.buffer_info.buffer_id);
                    assert(buffer_info);

                    bound_descriptor_sets[bind_point][first_set + i].buffer_infos[binding.first] = buffer_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    const BufferViewInfo* buffer_view_info =
                        object_info_table.GetBufferViewInfo(binding.second.texel_buffer_view);
                    assert(buffer_view_info);

                    const BufferInfo* buffer_info = object_info_table.GetBufferInfo(buffer_view_info->buffer_id);
                    assert(buffer_info);

                    bound_descriptor_sets[bind_point][first_set + i].buffer_infos[binding.first] = buffer_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    // These are read only resources
                    break;

                default:
                    GFXRECON_LOG_WARNING_ONCE("%s(): Descriptor type (%s) not handled",
                                              __func__,
                                              util::ToString<VkDescriptorType>(binding.second.desc_type).c_str());
                    break;
            }
        }
    }
}

VkResult
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::CloneRenderPass(const RenderPassInfo* original_render_pass)
{
    std::vector<VkAttachmentDescription> modified_attachemnts = original_render_pass->attachment_descs;

    // Fix storeOps and final layouts
    for (auto& att : modified_attachemnts)
    {
        att.storeOp     = VK_ATTACHMENT_STORE_OP_STORE;
        att.finalLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

        if (vkuFormatHasStencil(att.format))
        {
            att.stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE;
        }
    }

    // Create new render passes
    render_pass_clones.emplace_back(std::vector<VkRenderPass>());
    auto new_render_pass = render_pass_clones.end() - 1;
    new_render_pass->resize(original_render_pass->subpass_refs.size());

    // Do one quick pass over the subpass references in order to check if the render pass
    // uses color and/or depth attachments. This information might be necessary when
    // defining the dependencies of the custom render passes
    bool has_color = false, has_depth = false;
    for (uint32_t sub = 0; sub < original_render_pass->subpass_refs.size(); ++sub)
    {
        if (original_render_pass->subpass_refs[sub].color_att_refs.size())
        {
            has_color = true;
        }

        if (original_render_pass->subpass_refs[sub].has_depth)
        {
            has_depth = true;
        }
    }

    // Create new render passes. For each subpass in the original render pass a new render pass will be created.
    // Each new render pass will progressively contain an additional subpass until all subpasses of the original
    // renderpass are exhausted.
    // For example for a render pass with 3 subpasses, 3 new render passes will be created and will contain the
    // following subpasses:
    // Renderpass 0: Will contain 1 subpass.
    // Renderpass 1: Will contain 2 subpass.
    // Renderpass 2: Will contain 3 subpass.
    // Each draw call that is marked for dumping will be "assigned" the appropriate render pass depending on which
    // subpasses it was called from in the original render pass
    std::vector<VkSubpassDescription> subpass_descs;
    for (uint32_t sub = 0; sub < original_render_pass->subpass_refs.size(); ++sub)
    {
        bool                             has_external_dependencies_post = false;
        bool                             has_external_dependencies_pre  = false;
        std::vector<VkSubpassDependency> modified_dependencies;
        for (uint32_t d = 0; d < original_render_pass->dependencies.size(); ++d)
        {
            const VkSubpassDependency& original_dep = original_render_pass->dependencies[d];

            if ((original_dep.srcSubpass > sub || original_dep.dstSubpass > sub) &&
                (original_dep.srcSubpass != VK_SUBPASS_EXTERNAL && original_dep.dstSubpass != VK_SUBPASS_EXTERNAL))
            {
                GFXRECON_WRITE_CONSOLE("  RP %u skips dep %u (%u -> %u) as out of scope",
                                       sub,
                                       d,
                                       original_dep.srcSubpass,
                                       original_dep.dstSubpass);

                // Skip this dependency as out of scope
                continue;
            }

            auto new_dep = modified_dependencies.insert(modified_dependencies.end(), original_dep);
            if (new_dep->srcSubpass != VK_SUBPASS_EXTERNAL && new_dep->srcSubpass > sub)
            {
                new_dep->srcSubpass = sub;
            }
            else if (new_dep->dstSubpass != VK_SUBPASS_EXTERNAL && new_dep->dstSubpass > sub)
            {
                new_dep->dstSubpass = sub;
            }

            if (new_dep->srcSubpass == VK_SUBPASS_EXTERNAL)
            {
                // new_dep->srcStageMask |= VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
                // new_dep->srcAccessMask |= VK_ACCESS_TRANSFER_READ_BIT;

                has_external_dependencies_pre = true;
            }

            if (new_dep->dstSubpass == VK_SUBPASS_EXTERNAL)
            {
                new_dep->dstStageMask  = VK_PIPELINE_STAGE_TRANSFER_BIT;
                new_dep->dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

                has_external_dependencies_post = true;
            }

            GFXRECON_WRITE_CONSOLE("  RP %u gets a new dependency:", sub)
            GFXRECON_WRITE_CONSOLE("      srcSubpass: %u", new_dep->srcSubpass);
            GFXRECON_WRITE_CONSOLE("      dstSubpass: %u", new_dep->dstSubpass);
            GFXRECON_WRITE_CONSOLE("      srcStageMask: %s",
                                   util::VkPipelineStageFlags2ToString(new_dep->srcStageMask).c_str());
            GFXRECON_WRITE_CONSOLE("      dstStageMask: %s",
                                   util::VkPipelineStageFlags2ToString(new_dep->dstStageMask).c_str());
            GFXRECON_WRITE_CONSOLE("      srcAccessMask: %s",
                                   util::VkAccessFlags2ToString(new_dep->srcAccessMask).c_str());
            GFXRECON_WRITE_CONSOLE("      dstAccessMask: %s",
                                   util::VkAccessFlags2ToString(new_dep->dstAccessMask).c_str());
            GFXRECON_WRITE_CONSOLE("      dependencyFlags: %s",
                                   util::ToString<VkDependencyFlags>(new_dep->dependencyFlags).c_str());
        }

        if (!has_external_dependencies_post)
        {
            GFXRECON_WRITE_CONSOLE("  No post renderpass dependecy was detected")

            VkSubpassDependency post_dependency;
            post_dependency.srcSubpass    = sub;
            post_dependency.dstSubpass    = VK_SUBPASS_EXTERNAL;
            post_dependency.dstStageMask  = VK_PIPELINE_STAGE_TRANSFER_BIT;
            post_dependency.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

            if (has_color)
            {
                GFXRECON_WRITE_CONSOLE("    Injecting one for color")

                post_dependency.srcStageMask  = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
                post_dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

                modified_dependencies.push_back(post_dependency);
            }

            if (has_depth)
            {
                GFXRECON_WRITE_CONSOLE("    Injecting one for depth")

                post_dependency.srcStageMask =
                    VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT | VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT;
                post_dependency.srcAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;

                modified_dependencies.push_back(post_dependency);
            }
        }

        const RenderPassInfo::SubpassReferences& original_subp_ref = original_render_pass->subpass_refs[sub];
        auto new_subp_desc = subpass_descs.insert(subpass_descs.end(), VkSubpassDescription());

        new_subp_desc->flags                = original_subp_ref.flags;
        new_subp_desc->pipelineBindPoint    = original_subp_ref.pipeline_bind_point;
        new_subp_desc->inputAttachmentCount = original_subp_ref.input_att_refs.size();
        new_subp_desc->pInputAttachments =
            original_subp_ref.input_att_refs.size() ? original_subp_ref.input_att_refs.data() : nullptr;
        new_subp_desc->colorAttachmentCount = original_subp_ref.color_att_refs.size();
        new_subp_desc->pColorAttachments =
            original_subp_ref.color_att_refs.size() ? original_subp_ref.color_att_refs.data() : nullptr;
        new_subp_desc->pResolveAttachments =
            original_subp_ref.resolve_att_refs.size() ? original_subp_ref.resolve_att_refs.data() : nullptr;
        new_subp_desc->pDepthStencilAttachment =
            original_subp_ref.has_depth ? &original_subp_ref.depth_att_ref : nullptr;
        new_subp_desc->preserveAttachmentCount = original_subp_ref.preserve_att_refs.size();
        new_subp_desc->pPreserveAttachments =
            original_subp_ref.preserve_att_refs.size() ? original_subp_ref.preserve_att_refs.data() : nullptr;

        VkRenderPassCreateInfo ci;
        ci.sType           = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        ci.pNext           = nullptr;
        ci.flags           = VkRenderPassCreateFlags(0);
        ci.attachmentCount = modified_attachemnts.size();
        ci.pAttachments    = modified_attachemnts.size() ? modified_attachemnts.data() : nullptr;

        assert(subpass_descs.size() == sub + 1);
        ci.subpassCount = sub + 1;
        ci.pSubpasses   = subpass_descs.data();

        ci.dependencyCount = modified_dependencies.size();
        ci.pDependencies   = modified_dependencies.size() ? modified_dependencies.data() : nullptr;

        const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
        VkDevice          device      = device_info->handle;

        VkResult res = device_table->CreateRenderPass(device, &ci, nullptr, &new_render_pass->at(sub));
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("CreateRenderPass failed with %s", util::ToString<VkResult>(res).c_str());
            return res;
        }
    }

    return VK_SUCCESS;
}

VkResult
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::BeginRenderPass(const RenderPassInfo*  render_pass_info,
                                                                        uint32_t               clear_value_count,
                                                                        const VkClearValue*    p_clear_values,
                                                                        const FramebufferInfo* framebuffer_info,
                                                                        const VkRect2D&        render_area,
                                                                        VkSubpassContents      contents)
{
    assert(render_pass_info);
    assert(framebuffer_info);

    std::vector<const ImageInfo*> color_att_imgs;

    inside_renderpass  = true;
    current_subpass    = 0;
    active_renderpass  = render_pass_info;
    active_framebuffer = framebuffer_info;

    // Parse color attachments
    uint32_t i = 0;
    for (const auto& att_ref : active_renderpass->subpass_refs[current_subpass].color_att_refs)
    {
        const uint32_t att_idx = att_ref.attachment;

        const ImageViewInfo* img_view_info =
            object_info_table.GetImageViewInfo(framebuffer_info->attachment_image_view_ids[att_idx]);
        assert(img_view_info);

        const ImageInfo* img_info = object_info_table.GetImageInfo(img_view_info->image_id);
        assert(img_info);

        color_att_imgs.push_back(img_info);
    }

    const ImageInfo* depth_img_info;

    if (active_renderpass->subpass_refs[current_subpass].has_depth)
    {
        const uint32_t       depth_att_idx = active_renderpass->subpass_refs[current_subpass].depth_att_ref.attachment;
        const ImageViewInfo* depth_img_view_info =
            object_info_table.GetImageViewInfo(framebuffer_info->attachment_image_view_ids[depth_att_idx]);
        assert(depth_img_view_info);

        depth_img_info = object_info_table.GetImageInfo(depth_img_view_info->image_id);
        assert(depth_img_info);
    }
    else
    {
        depth_img_info = nullptr;
    }

    SetRenderTargets(std::move(color_att_imgs), depth_img_info, true);

    SetRenderArea(render_area);

    VkResult res = CloneRenderPass(render_pass_info);
    if (res != VK_SUCCESS)
    {
        return res;
    }

    // Add vkCmdBeginRenderPass into the cloned command buffers using the modified render pass
    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index;
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_idx)];

        // GetRenderPassIndex will tell us which render pass each cloned command buffer should use depending on the
        // assigned draw call index
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;
        const uint64_t              sp       = RP_index.second;

        if (dc_index < RP_indices[rp][0])
        {
            continue;
        }
        else if (dc_index > RP_indices[rp][RP_indices[rp].size() - 1] || rp > current_renderpass)
        {
            break;
        }

        VkRenderPassBeginInfo bi = { VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO, nullptr };

        bi.clearValueCount = clear_value_count;
        bi.pClearValues    = p_clear_values;
        bi.framebuffer     = framebuffer_info->handle;
        bi.renderArea      = render_area;

        GFXRECON_WRITE_CONSOLE(
            "  cmd_buf_idx: %zu with dc index: %" PRIu64 " gets render pass: (%u, %u)", cmd_buf_idx, dc_index, rp, sp);

        assert(rp < render_pass_clones.size());
        assert(sp < render_pass_clones[rp].size());
        bi.renderPass = render_pass_clones[rp][sp];

        device_table->CmdBeginRenderPass(*it, &bi, contents);
    }

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::NextSubpass(VkSubpassContents contents)
{
    assert(active_renderpass);
    assert(active_framebuffer);

    std::vector<const ImageInfo*>    color_att_imgs;
    std::vector<VkAttachmentStoreOp> color_att_storeOps;
    std::vector<VkImageLayout>       color_att_final_layouts;

    ++current_subpass;

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index;
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t              dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_idx)];
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;

        if (rp != current_renderpass)
        {
            continue;
        }

        GFXRECON_WRITE_CONSOLE("  cmd_buf_idx: %zu with dc index: %" PRIu64 " moves to subpass: (%u, %u)",
                               cmd_buf_idx,
                               dc_index,
                               rp,
                               current_subpass);

        device_table->CmdNextSubpass(*it, contents);
    }

    assert(current_subpass < active_renderpass->subpass_refs.size());

    // Parse color attachments
    for (const auto& att_ref : active_renderpass->subpass_refs[current_subpass].color_att_refs)
    {
        const uint32_t att_idx = att_ref.attachment;
        assert(att_idx < active_framebuffer->attachment_image_view_ids.size());

        const ImageViewInfo* img_view_info =
            object_info_table.GetImageViewInfo(active_framebuffer->attachment_image_view_ids[att_idx]);
        assert(img_view_info);

        const ImageInfo* img_info = object_info_table.GetImageInfo(img_view_info->image_id);
        assert(img_info);

        color_att_imgs.push_back(img_info);
        color_att_storeOps.push_back(active_renderpass->attachment_descs[att_idx].storeOp);
        color_att_final_layouts.push_back(active_renderpass->attachment_descs[att_idx].finalLayout);
    }

    const ImageInfo*    depth_img_info;
    VkAttachmentStoreOp depth_att_storeOp;
    VkImageLayout       depth_final_layout;

    if (active_renderpass->subpass_refs[current_subpass].has_depth)
    {
        const uint32_t depth_att_idx = active_renderpass->subpass_refs[current_subpass].depth_att_ref.attachment;
        assert(depth_att_idx < active_framebuffer->attachment_image_view_ids.size());

        const ImageViewInfo* depth_img_view_info =
            object_info_table.GetImageViewInfo(active_framebuffer->attachment_image_view_ids[depth_att_idx]);
        assert(depth_img_view_info);

        depth_img_info = object_info_table.GetImageInfo(depth_img_view_info->image_id);
        assert(depth_img_info);
        depth_att_storeOp  = active_renderpass->attachment_descs[depth_att_idx].storeOp;
        depth_final_layout = active_renderpass->attachment_descs[depth_att_idx].finalLayout;
    }
    else
    {
        depth_img_info    = nullptr;
        depth_att_storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    }

    SetRenderTargets(std::move(color_att_imgs), depth_img_info, false);
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::BindPipeline(VkPipelineBindPoint pipeline_bind_point,
                                                                          const PipelineInfo* pipeline)
{
    VulkanReplayDumpResourcesBase::PipelineBindPoints bind_point =
        VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);

    bound_pipelines[bind_point] = pipeline;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::EndRenderPass()
{
    assert(inside_renderpass);

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(first, last);
    size_t cmd_buf_idx = current_cb_index;
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it, ++cmd_buf_idx)
    {
        const uint64_t              dc_index = dc_indices[CmdBufToDCVectorIndex(cmd_buf_idx)];
        const RenderPassSubpassPair RP_index = GetRenderPassIndex(dc_index);
        const uint64_t              rp       = RP_index.first;
        const uint64_t              sp       = RP_index.second;

        if (dc_index < RP_indices[rp][0])
        {
            continue;
        }
        else if (dc_index > RP_indices[rp][RP_indices[rp].size() - 1] || rp > current_renderpass)
        {
            break;
        }

        GFXRECON_WRITE_CONSOLE(
            "  cmd_buf_idx: %zu with dc index: %" PRIu64 " ends render pass: (%u, %u)", cmd_buf_idx, dc_index, rp, sp);

        device_table->CmdEndRenderPass(*it);
    }

    ++current_renderpass;

    inside_renderpass = false;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::SetRenderTargets(
    const std::vector<const ImageInfo*>& color_att_imgs, const ImageInfo* depth_att_img, bool new_render_pass)
{
    if (new_render_pass)
    {
        render_targets_.emplace_back(std::vector<RenderTargets>());
    }

    auto render_targets = render_targets_.end() - 1;

    render_targets->emplace_back(RenderTargets());
    auto new_rts = render_targets->end() - 1;

    new_rts->color_att_imgs = color_att_imgs;
    new_rts->depth_att_img  = depth_att_img;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::SetRenderArea(const VkRect2D& render_area)
{
    render_area_.push_back(render_area);
}

bool VulkanReplayDumpResourcesBase::DumpingBeginCommandBufferIndex(uint64_t index) const
{
    const DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(index);

    if (dc_context == nullptr)
    {
        const DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(index);
        return dr_context != nullptr;
    }
    else
    {
        return true;
    }
}

bool VulkanReplayDumpResourcesBase::GetDrawCallActiveCommandBuffers(VkCommandBuffer original_command_buffer,
                                                                    cmd_buf_it&     first,
                                                                    cmd_buf_it&     last) const
{
    assert(IsRecording(original_command_buffer));

    const DrawCallsDumpingContext* stack = FindDrawCallCommandBufferContext(original_command_buffer);

    if (stack != nullptr)
    {
        stack->GetDrawCallActiveCommandBuffers(first, last);
        return true;
    }
    else
    {
        return false;
    }
}

VkCommandBuffer
VulkanReplayDumpResourcesBase::GetDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer) const
{
    assert(IsRecording(original_command_buffer));

    const DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);

    if (context != nullptr)
    {
        VkCommandBuffer dr_command_buffer = context->GetDispatchRaysCommandBuffer();
        assert(dr_command_buffer != VK_NULL_HANDLE);

        return dr_command_buffer;
    }
    else
    {
        return VK_NULL_HANDLE;
    }
}

bool VulkanReplayDumpResourcesBase::UpdateRecordingStatus()
{
    assert(recording_);

    for (const auto& entry : draw_call_contexts)
    {
        const DrawCallsDumpingContext& dc_context = entry.second;
        if (dc_context.IsRecording())
        {
            return true;
        }
    }

    for (const auto& entry : dispatch_ray_contexts)
    {
        const DispatchTraceRaysDumpingContext& dr_context = entry.second;
        if (dr_context.IsRecording())
        {
            return true;
        }
    }

    return (recording_ = false);
}

bool VulkanReplayDumpResourcesBase::ShouldDumpQueueSubmitIndex(uint64_t index) const
{
    // Indices should be sorted
    if (!IsInsideRange(QueueSubmit_indices_, index))
    {
        return false;
    }

    for (size_t i = 0; i < QueueSubmit_indices_.size(); ++i)
    {
        if (index == QueueSubmit_indices_[i])
        {
            return true;
        }
        else if (index > QueueSubmit_indices_[i])
        {
            return false;
        }
    }

    return false;
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRenderPass(
    const ApiCallInfo&                                   call_info,
    PFN_vkCmdBeginRenderPass                             func,
    VkCommandBuffer                                      original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                                    contents)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        const auto render_pass_info_meta = pRenderPassBegin->GetMetaStructPointer();
        auto       framebuffer_id        = render_pass_info_meta->framebuffer;
        auto       render_pass_id        = render_pass_info_meta->renderPass;

        const FramebufferInfo* framebuffer_info = object_info_table_.GetFramebufferInfo(framebuffer_id);
        assert(framebuffer_info);

        const RenderPassInfo* render_pass_info = object_info_table_.GetRenderPassInfo(render_pass_id);
        assert(render_pass_info);

        // Do not record vkCmdBeginRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::BeginRenderPass
        VkResult res = dc_context->BeginRenderPass(render_pass_info,
                                                   pRenderPassBegin->GetPointer()->clearValueCount,
                                                   pRenderPassBegin->GetPointer()->pClearValues,
                                                   framebuffer_info,
                                                   pRenderPassBegin->GetPointer()->renderArea,
                                                   contents);
        assert(res == VK_SUCCESS);
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pRenderPassBegin->GetPointer(), contents);
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pRenderPassBegin->GetPointer(), contents);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRenderPass2(
    const ApiCallInfo&                                   call_info,
    PFN_vkCmdBeginRenderPass2                            func,
    VkCommandBuffer                                      original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>*    pSubpassBeginInfo)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        const auto render_pass_info_meta = pRenderPassBegin->GetMetaStructPointer();
        auto       framebuffer_id        = render_pass_info_meta->framebuffer;
        auto       render_pass_id        = render_pass_info_meta->renderPass;

        const FramebufferInfo* framebuffer_info = object_info_table_.GetFramebufferInfo(framebuffer_id);
        assert(framebuffer_info);

        const RenderPassInfo* render_pass_info = object_info_table_.GetRenderPassInfo(render_pass_id);
        assert(render_pass_info);

        // Do not record vkCmdBeginRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::BeginRenderPass
        VkResult res = dc_context->BeginRenderPass(render_pass_info,
                                                   pRenderPassBegin->GetPointer()->clearValueCount,
                                                   pRenderPassBegin->GetPointer()->pClearValues,
                                                   framebuffer_info,
                                                   pRenderPassBegin->GetPointer()->renderArea,
                                                   pSubpassBeginInfo->GetPointer()->contents);

        assert(res == VK_SUCCESS);
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pRenderPassBegin->GetPointer(), pSubpassBeginInfo->GetPointer());
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pRenderPassBegin->GetPointer(), pSubpassBeginInfo->GetPointer());
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdNextSubpass(const ApiCallInfo&   call_info,
                                                           PFN_vkCmdNextSubpass func,
                                                           VkCommandBuffer      original_command_buffer,
                                                           VkSubpassContents    contents)
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    // Do not record NextSubpass commands in current DrawCall context command buffers.
    // It will be handled by DrawCallsDumpingContext::NextSubpass
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        dc_context->NextSubpass(contents);
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, contents);
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, contents);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdNextSubpass2(
    const ApiCallInfo&                                call_info,
    PFN_vkCmdNextSubpass2                             func,
    VkCommandBuffer                                   original_command_buffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>*   pSubpassEndInfo)
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        // Do not record NextSubpass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::NextSubpass
        dc_context->NextSubpass(pSubpassBeginInfo->GetPointer()->contents);
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pSubpassBeginInfo->GetPointer(), pSubpassEndInfo->GetPointer());
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pSubpassBeginInfo->GetPointer(), pSubpassEndInfo->GetPointer());
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRenderPass(const ApiCallInfo&     call_info,
                                                             PFN_vkCmdEndRenderPass func,
                                                             VkCommandBuffer        original_command_buffer)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        // Do not record EndRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::EndRenderPass
        dc_context->EndRenderPass();
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it);
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRenderPass2(
    const ApiCallInfo&                              call_info,
    PFN_vkCmdEndRenderPass2                         func,
    VkCommandBuffer                                 original_command_buffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        // Do not record EndRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::EndRenderPass
        dc_context->EndRenderPass();
    }
    else if (dc_context != nullptr)
    {
        VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pSubpassEndInfo->GetPointer());
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pSubpassEndInfo->GetPointer());
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindPipeline(const ApiCallInfo&    call_info,
                                                            PFN_vkCmdBindPipeline func,
                                                            VkCommandBuffer       original_command_buffer,
                                                            VkPipelineBindPoint   pipelineBindPoint,
                                                            const PipelineInfo*   pipeline)
{
    assert(pipeline);
    assert(IsRecording(original_command_buffer));

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, pipelineBindPoint, pipeline->handle);
        }

        DrawCallsDumpingContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
        assert(context);
        context->BindPipeline(pipelineBindPoint, pipeline);
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, pipelineBindPoint, pipeline->handle);

        DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
        assert(context);
        context->BindPipeline(pipelineBindPoint, pipeline);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindDescriptorSets(const ApiCallInfo&          call_info,
                                                                  PFN_vkCmdBindDescriptorSets func,
                                                                  VkCommandBuffer             original_command_buffer,
                                                                  VkPipelineBindPoint         pipeline_bind_point,
                                                                  VkPipelineLayout            layout,
                                                                  uint32_t                    first_set,
                                                                  uint32_t                    descriptor_sets_count,
                                                                  const format::HandleId*     descriptor_sets_ids,
                                                                  uint32_t                    dynamicOffsetCount,
                                                                  const uint32_t*             pDynamicOffsets)
{
    assert(IsRecording(original_command_buffer));
    assert(descriptor_sets_ids);

    PipelineBindPoints                    bind_point = VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);
    std::vector<VkDescriptorSet>          desc_set_handles(descriptor_sets_count, VK_NULL_HANDLE);
    std::vector<const DescriptorSetInfo*> desc_set_infos(descriptor_sets_count, nullptr);

    for (uint32_t i = 0; i < descriptor_sets_count; ++i)
    {
        const DescriptorSetInfo* desc_set_info = object_info_table_.GetDescriptorSetInfo(descriptor_sets_ids[i]);
        assert(desc_set_info);
        desc_set_infos[i]   = desc_set_info;
        desc_set_handles[i] = desc_set_info->handle;
    }

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context)
    {
        dc_context->BindDescriptorSets(
            pipeline_bind_point, layout, first_set, desc_set_infos, dynamicOffsetCount, pDynamicOffsets);
    }

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
    {
        func(*it,
             pipeline_bind_point,
             layout,
             first_set,
             descriptor_sets_count,
             desc_set_handles.data(),
             dynamicOffsetCount,
             pDynamicOffsets);
    }

    VkCommandBuffer dr_cmd_buf = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_cmd_buf != VK_NULL_HANDLE)
    {
        func(dr_cmd_buf,
             pipeline_bind_point,
             layout,
             first_set,
             descriptor_sets_count,
             desc_set_handles.data(),
             dynamicOffsetCount,
             pDynamicOffsets);
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dr_context)
    {
        dr_context->BindDescriptorSets(
            pipeline_bind_point, layout, first_set, desc_set_infos, dynamicOffsetCount, pDynamicOffsets);
    }
}

void VulkanReplayDumpResourcesBase::FinalizeDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer)
{
    DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    if (!context->IsRecording())
    {
        context->FinalizeCommandBuffer();
    }

    UpdateRecordingStatus();
}

void VulkanReplayDumpResourcesBase::OverrideCmdDispatch(const ApiCallInfo& call_info,
                                                        PFN_vkCmdDispatch  func,
                                                        VkCommandBuffer    original_command_buffer,
                                                        uint32_t           groupCountX,
                                                        uint32_t           groupCountY,
                                                        uint32_t           groupCountZ)
{
    assert(IsRecording(original_command_buffer));

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, groupCountX, groupCountY, groupCountZ);
        }
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dump_resources_before_ && dr_context != nullptr)
    {
        if (dr_context->ShouldDumpDispatch(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, true, true);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, groupCountX, groupCountY, groupCountZ);
    }

    if (dr_context != nullptr)
    {
        if (dr_context->ShouldDumpDispatch(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, false, true);
            FinalizeDispatchRaysCommandBuffer(original_command_buffer);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDispatchIndirect(const ApiCallInfo&        call_info,
                                                                PFN_vkCmdDispatchIndirect func,
                                                                VkCommandBuffer           original_command_buffer,
                                                                VkBuffer                  buffer,
                                                                VkDeviceSize              offset)
{
    assert(IsRecording(original_command_buffer));

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it, buffer, offset);
        }
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dump_resources_before_ && dr_context != nullptr)
    {
        if (dr_context->ShouldDumpDispatch(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, true, true);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, buffer, offset);
    }

    if (dr_context != nullptr)
    {
        if (dr_context->ShouldDumpDispatch(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, false, true);
            FinalizeDispatchRaysCommandBuffer(original_command_buffer);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdTraceRaysKHR(
    const ApiCallInfo&                                             call_info,
    PFN_vkCmdTraceRaysKHR                                          func,
    VkCommandBuffer                                                original_command_buffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                                       width,
    uint32_t                                                       height,
    uint32_t                                                       depth)
{
    assert(IsRecording(original_command_buffer));

    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable   = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable     = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable      = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    VulkanReplayDumpResourcesBase::cmd_buf_it first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (VulkanReplayDumpResourcesBase::cmd_buf_it it = first; it < last; ++it)
        {
            func(*it,
                 in_pRaygenShaderBindingTable,
                 in_pMissShaderBindingTable,
                 in_pHitShaderBindingTable,
                 in_pCallableShaderBindingTable,
                 width,
                 height,
                 depth);
        }
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dump_resources_before_ && dr_context != nullptr)
    {
        if (dr_context->ShouldDumpTraceRays(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, true, false);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer,
             in_pRaygenShaderBindingTable,
             in_pMissShaderBindingTable,
             in_pHitShaderBindingTable,
             in_pCallableShaderBindingTable,
             width,
             height,
             depth);
    }

    if (dr_context != nullptr)
    {
        if (dr_context->ShouldDumpTraceRays(call_info.index))
        {
            dr_context->CloneDispatchRaysResources(call_info.index, false, false);
            FinalizeDispatchRaysCommandBuffer(original_command_buffer);
        }
    }
}

VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::DrawCallsDumpingContext(
    const std::vector<uint64_t>&              dc_indices,
    const std::vector<std::vector<uint64_t>>& rp_indices,
    const VulkanObjectInfoTable&              object_info_table,
    bool                                      dump_resources_before,
    const std::string&                        dump_resource_path,
    util::ScreenshotFormat                    image_file_format,
    float                                     dump_resources_scale) :
    original_command_buffer_info(nullptr),
    current_cb_index(0), dc_indices(dc_indices), RP_indices(rp_indices), active_renderpass(nullptr),
    active_framebuffer(nullptr), bound_pipelines{ nullptr }, current_renderpass(0), current_subpass(0),
    dump_resources_before(dump_resources_before), aux_command_buffer(VK_NULL_HANDLE), aux_fence(VK_NULL_HANDLE),
    device_table(nullptr), object_info_table(object_info_table), replay_device_phys_mem_props(nullptr),
    dump_resource_path(dump_resource_path), image_file_format(image_file_format),
    dump_resources_scale(dump_resources_scale)
{
    must_backup_resources = (dc_indices.size() > 1);

    const size_t n_cmd_buffs = dump_resources_before ? 2 * dc_indices.size() : dc_indices.size();
    command_buffers.resize(n_cmd_buffs, VK_NULL_HANDLE);
}

VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::~DrawCallsDumpingContext()
{
    if (original_command_buffer_info)
    {
        if (aux_command_buffer != VK_NULL_HANDLE)
        {
            const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
            VkDevice          device      = device_info->handle;

            assert(device_table);

            const CommandPoolInfo* pool_info =
                object_info_table.GetCommandPoolInfo(original_command_buffer_info->pool_id);
            assert(pool_info);

            device_table->FreeCommandBuffers(device, pool_info->handle, 1, &aux_command_buffer);
            aux_command_buffer = VK_NULL_HANDLE;
        }

        DestroyMutableResourceBackups();
    }
}

static VkResult CloneImage(const VulkanObjectInfoTable&            object_info_table,
                           const encode::DeviceTable*              device_table,
                           const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                           const ImageInfo*                        image_info,
                           VkImage*                                new_image,
                           VkDeviceMemory*                         new_image_memory)
{
    VkImageCreateInfo ci;
    ci.sType                 = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    ci.pNext                 = nullptr;
    ci.flags                 = VkImageCreateFlags(0);
    ci.imageType             = image_info->type;
    ci.format                = image_info->format;
    ci.extent                = image_info->extent;
    ci.mipLevels             = image_info->level_count;
    ci.arrayLayers           = image_info->layer_count;
    ci.samples               = image_info->sample_count;
    ci.tiling                = image_info->tiling;
    ci.usage                 = image_info->usage | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    ci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    ci.queueFamilyIndexCount = image_info->queue_family_index;
    ci.pQueueFamilyIndices   = nullptr;
    ci.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(image_info->parent_id);
    VkDevice          device      = device_info->handle;

    assert(device_table);
    assert(new_image);
    VkResult res = device_table->CreateImage(device, &ci, nullptr, new_image);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateImage failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    VkMemoryRequirements mem_reqs       = {};
    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, nullptr };

    device_table->GetImageMemoryRequirements(device, *new_image, &mem_reqs);
    mem_alloc_info.allocationSize = mem_reqs.size;

    assert(replay_device_phys_mem_props);
    uint32_t index =
        GetMemoryTypeIndex(*replay_device_phys_mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_ERROR("%s failed to find an appropriate memory type", __func__)
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    mem_alloc_info.memoryTypeIndex = index;

    assert(new_image_memory);
    res = device_table->AllocateMemory(device, &mem_alloc_info, nullptr, new_image_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->BindImageMemory(device, *new_image, *new_image_memory, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("BindImageMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

VkResult CloneBuffer(const VulkanObjectInfoTable&            object_info_table,
                     const encode::DeviceTable*              device_table,
                     const VkPhysicalDeviceMemoryProperties* replay_device_phys_mem_props,
                     const BufferInfo*                       buffer_info,
                     VkBuffer*                               new_buffer,
                     VkDeviceMemory*                         new_buffer_memory)
{
    VkBufferCreateInfo ci;
    ci.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    ci.pNext                 = nullptr;
    ci.flags                 = VkBufferCreateFlags(0);
    ci.size                  = buffer_info->size;
    ci.usage                 = buffer_info->usage | VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    ci.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    ci.queueFamilyIndexCount = buffer_info->queue_family_index;
    ci.pQueueFamilyIndices   = nullptr;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(buffer_info->parent_id);
    VkDevice          device      = device_info->handle;

    assert(device_table);
    assert(new_buffer);

    VkResult res = device_table->CreateBuffer(device, &ci, nullptr, new_buffer);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateBuffer failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    VkMemoryRequirements mem_reqs       = {};
    VkMemoryAllocateInfo mem_alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, nullptr };

    device_table->GetBufferMemoryRequirements(device, *new_buffer, &mem_reqs);
    mem_alloc_info.allocationSize = mem_reqs.size;

    assert(replay_device_phys_mem_props);
    uint32_t index =
        GetMemoryTypeIndex(*replay_device_phys_mem_props, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_ERROR("%s failed to find an appropriate memory type", __func__)
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    mem_alloc_info.memoryTypeIndex = index;

    assert(new_buffer_memory);
    res = device_table->AllocateMemory(device, &mem_alloc_info, nullptr, new_buffer_memory);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->BindBufferMemory(device, *new_buffer, *new_buffer_memory, 0);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("BindBufferMemory failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::DestroyMutableResourceBackups()
{
    assert(original_command_buffer_info);

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    VkDevice          device      = device_info->handle;

    for (size_t i = 0; i < mutable_resource_backups.images.size(); ++i)
    {
        device_table->DestroyImage(device, mutable_resource_backups.images[i], nullptr);
    }

    for (size_t i = 0; i < mutable_resource_backups.image_memories.size(); ++i)
    {
        device_table->FreeMemory(device, mutable_resource_backups.image_memories[i], nullptr);
    }

    mutable_resource_backups.images.clear();
    mutable_resource_backups.image_memories.clear();
    mutable_resource_backups.original_images.clear();

    for (size_t i = 0; i < mutable_resource_backups.buffers.size(); ++i)
    {
        device_table->DestroyBuffer(device, mutable_resource_backups.buffers[i], nullptr);
    }

    for (size_t i = 0; i < mutable_resource_backups.buffer_memories.size(); ++i)
    {
        device_table->FreeMemory(device, mutable_resource_backups.buffer_memories[i], nullptr);
    }

    mutable_resource_backups.buffers.clear();
    mutable_resource_backups.buffer_memories.clear();
    mutable_resource_backups.original_buffers.clear();
}

VkResult VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::RevertMutableResources(VkQueue queue)
{
    return VK_SUCCESS;

    if (!must_backup_resources || (!mutable_resource_backups.images.size() && !mutable_resource_backups.buffers.size()))
    {
        return VK_SUCCESS;
    }

    assert(aux_command_buffer);

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    VkDevice          device      = device_info->handle;

    device_table->ResetCommandBuffer(aux_command_buffer, 0);

    const VkCommandBufferBeginInfo bi = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    device_table->BeginCommandBuffer(aux_command_buffer, &bi);

    VkImageMemoryBarrier img_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER, nullptr };
    img_barrier.subresourceRange.baseMipLevel   = 0;
    img_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
    img_barrier.subresourceRange.baseArrayLayer = 0;
    img_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;

    assert(mutable_resource_backups.images.size() == mutable_resource_backups.original_images.size());
    for (size_t i = 0; i < mutable_resource_backups.images.size(); ++i)
    {
        const VkImageAspectFlags aspect_mask =
            graphics::GetFormatAspectMask(mutable_resource_backups.original_images[i]->format);
        img_barrier.subresourceRange.aspectMask = aspect_mask;

        // Flush gpu caches and transition original image to appropriate layout
        img_barrier.srcAccessMask       = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        img_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.oldLayout           = VK_IMAGE_LAYOUT_GENERAL;
        img_barrier.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.srcQueueFamilyIndex = 0;
        img_barrier.dstQueueFamilyIndex = 0;
        img_barrier.image               = mutable_resource_backups.original_images[i]->handle;

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &img_barrier);

        // Transition back up image to appropriate layout
        img_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.image         = mutable_resource_backups.images[i];

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &img_barrier);

        // Copy
        VkImageCopy copy_region                   = {};
        copy_region.srcSubresource.aspectMask     = aspect_mask;
        copy_region.srcSubresource.baseArrayLayer = 0;
        copy_region.srcSubresource.layerCount     = mutable_resource_backups.original_images[i]->layer_count;
        copy_region.srcSubresource.mipLevel       = 0;
        copy_region.dstSubresource                = copy_region.srcSubresource;

        std::vector<VkImageCopy> copy_regions(mutable_resource_backups.original_images[i]->level_count);

        for (uint32_t j = 0; j < mutable_resource_backups.original_images[i]->level_count; ++j)
        {
            copy_region.extent.width  = std::max(1u, (mutable_resource_backups.original_images[i]->extent.width >> j));
            copy_region.extent.height = std::max(1u, (mutable_resource_backups.original_images[i]->extent.height >> j));
            copy_region.extent.depth  = std::max(1u, (mutable_resource_backups.original_images[i]->extent.depth >> j));

            copy_regions[j] = copy_region;
        }

        device_table->CmdCopyImage(aux_command_buffer,
                                   mutable_resource_backups.images[i],
                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                   mutable_resource_backups.original_images[i]->handle,
                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                   copy_regions.size(),
                                   copy_regions.data());
    }

    VkBufferMemoryBarrier buffer_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER, nullptr };
    VkBufferCopy          copy_region    = { 0, 0 };

    assert(mutable_resource_backups.buffers.size() == mutable_resource_backups.original_buffers.size());
    for (size_t i = 0; i < mutable_resource_backups.buffers.size(); ++i)
    {
        buffer_barrier.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        buffer_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        buffer_barrier.buffer        = mutable_resource_backups.original_buffers[i]->handle;

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         1,
                                         &buffer_barrier,
                                         0,
                                         nullptr);

        copy_region.size = mutable_resource_backups.original_buffers[i]->size;
        device_table->CmdCopyBuffer(aux_command_buffer,
                                    mutable_resource_backups.buffers[i],
                                    mutable_resource_backups.original_buffers[i]->handle,
                                    1,
                                    &copy_region);
    }

    device_table->EndCommandBuffer(aux_command_buffer);

    VkSubmitInfo si         = { VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr };
    si.waitSemaphoreCount   = 0;
    si.pWaitSemaphores      = nullptr;
    si.pWaitDstStageMask    = nullptr;
    si.signalSemaphoreCount = 0;
    si.pSignalSemaphores    = nullptr;
    si.commandBufferCount   = 1;
    si.pCommandBuffers      = &aux_command_buffer;

    VkResult res = device_table->ResetFences(device, 1, &aux_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("ResetFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->QueueSubmit(queue, 1, &si, aux_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR(
            "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->WaitForFences(device, 1, &aux_fence, VK_TRUE, std::numeric_limits<uint64_t>::max());
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

VkResult VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::BackUpMutableResources(VkQueue queue)
{
    if (!must_backup_resources || (!mutable_resource_backups.images.size() && !mutable_resource_backups.buffers.size()))
    {
        return VK_SUCCESS;
    }

    assert(aux_command_buffer);

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    VkDevice          device      = device_info->handle;

    device_table->ResetCommandBuffer(aux_command_buffer, 0);

    const VkCommandBufferBeginInfo bi = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    device_table->BeginCommandBuffer(aux_command_buffer, &bi);

    VkImageMemoryBarrier img_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER, nullptr };
    img_barrier.subresourceRange.baseMipLevel   = 0;
    img_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
    img_barrier.subresourceRange.baseArrayLayer = 0;
    img_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;

    assert(mutable_resource_backups.images.size() == mutable_resource_backups.original_images.size());
    for (size_t i = 0; i < mutable_resource_backups.images.size(); ++i)
    {
        const VkImageAspectFlags aspect_mask =
            graphics::GetFormatAspectMask(mutable_resource_backups.original_images[i]->format);
        img_barrier.subresourceRange.aspectMask = aspect_mask;

        // Flush gpu caches and transition original image to appropriate layout
        img_barrier.srcAccessMask       = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        img_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
        img_barrier.oldLayout           = VK_IMAGE_LAYOUT_GENERAL;
        img_barrier.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        img_barrier.srcQueueFamilyIndex = 0;
        img_barrier.dstQueueFamilyIndex = 0;
        img_barrier.image               = mutable_resource_backups.original_images[i]->handle;

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &img_barrier);

        // Transition back up image to appropriate layout
        img_barrier.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        img_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
        img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        img_barrier.image         = mutable_resource_backups.images[i];

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &img_barrier);

        // Copy
        VkImageCopy copy_region                   = {};
        copy_region.srcSubresource.aspectMask     = aspect_mask;
        copy_region.srcSubresource.baseArrayLayer = 0;
        copy_region.srcSubresource.layerCount     = mutable_resource_backups.original_images[i]->layer_count;
        copy_region.srcSubresource.mipLevel       = 0;
        copy_region.dstSubresource                = copy_region.srcSubresource;

        std::vector<VkImageCopy> copy_regions(mutable_resource_backups.original_images[i]->level_count);

        for (uint32_t j = 0; j < mutable_resource_backups.original_images[i]->level_count; ++j)
        {
            copy_region.extent.width  = std::max(1u, (mutable_resource_backups.original_images[i]->extent.width >> j));
            copy_region.extent.height = std::max(1u, (mutable_resource_backups.original_images[i]->extent.height >> j));
            copy_region.extent.depth  = std::max(1u, (mutable_resource_backups.original_images[i]->extent.depth >> j));

            copy_regions[j] = copy_region;
        }

        device_table->CmdCopyImage(aux_command_buffer,
                                   mutable_resource_backups.original_images[i]->handle,
                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                   mutable_resource_backups.images[i],
                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                   copy_regions.size(),
                                   copy_regions.data());
    }

    VkBufferMemoryBarrier buffer_barrier = { VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER, nullptr };
    VkBufferCopy          copy_region    = { 0, 0 };

    assert(mutable_resource_backups.buffers.size() == mutable_resource_backups.original_buffers.size());
    for (size_t i = 0; i < mutable_resource_backups.buffers.size(); ++i)
    {
        buffer_barrier.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        buffer_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        buffer_barrier.buffer        = mutable_resource_backups.original_buffers[i]->handle;

        device_table->CmdPipelineBarrier(aux_command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         1,
                                         &buffer_barrier,
                                         0,
                                         nullptr);

        copy_region.size = mutable_resource_backups.original_buffers[i]->size;
        device_table->CmdCopyBuffer(aux_command_buffer,
                                    mutable_resource_backups.original_buffers[i]->handle,
                                    mutable_resource_backups.buffers[i],
                                    1,
                                    &copy_region);
    }

    device_table->EndCommandBuffer(aux_command_buffer);

    VkSubmitInfo si         = { VK_STRUCTURE_TYPE_SUBMIT_INFO, nullptr };
    si.waitSemaphoreCount   = 0;
    si.pWaitSemaphores      = nullptr;
    si.pWaitDstStageMask    = nullptr;
    si.signalSemaphoreCount = 0;
    si.pSignalSemaphores    = nullptr;
    si.commandBufferCount   = 1;
    si.pCommandBuffers      = &aux_command_buffer;

    VkResult res = device_table->ResetFences(device, 1, &aux_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("ResetFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->QueueSubmit(queue, 1, &si, aux_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR(
            "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->WaitForFences(device, 1, &aux_fence, VK_TRUE, std::numeric_limits<uint64_t>::max());
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    return VK_SUCCESS;
}

VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::RenderPassSubpassPair
VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::GetRenderPassIndex(uint64_t dc_index) const
{
    assert(RP_indices.size());

    for (size_t rp = 0; rp < RP_indices.size(); ++rp)
    {
        const std::vector<uint64_t>& render_pass = RP_indices[rp];
        assert(render_pass.size());

        if (dc_index > render_pass[render_pass.size() - 1])
        {
            continue;
        }

        for (uint64_t sp = 0; sp < render_pass.size() - 1; ++sp)
        {
            if (dc_index > render_pass[sp] && dc_index < render_pass[sp + 1])
            {
                return RenderPassSubpassPair(rp, sp);
            }
        }
    }

    // If this is hit then probably there's something wrong with the draw call and/or render pass indices
    GFXRECON_LOG_ERROR(
        "It appears that there is an error with the provided Draw indices in combination with the render pass indices.")
    assert(0);

    return RenderPassSubpassPair(0, 0);
}

size_t VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::CmdBufToDCVectorIndex(size_t cmd_buf_index) const
{
    assert(cmd_buf_index < command_buffers.size());

    if (dump_resources_before)
    {
        assert(cmd_buf_index / 2 < dc_indices.size());

        return cmd_buf_index / 2;
    }
    else
    {
        assert(cmd_buf_index < dc_indices.size());

        return cmd_buf_index;
    }
}

uint32_t VulkanReplayDumpResourcesBase::DrawCallsDumpingContext::GetDrawCallActiveCommandBuffers(cmd_buf_it& first,
                                                                                                 cmd_buf_it& last) const
{
    assert(current_cb_index <= command_buffers.size());

    first = command_buffers.begin() + current_cb_index;
    last  = command_buffers.end();

    return current_cb_index;
}

bool VulkanReplayDumpResourcesBase::IsRecording(VkCommandBuffer original_command_buffer) const
{
    if (recording_)
    {
        const DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
        if (dc_context)
        {
            if (dc_context->IsRecording())
            {
                return true;
            }
        }

        const DispatchTraceRaysDumpingContext* dr_context =
            FindDispatchRaysCommandBufferContext(original_command_buffer);
        if (dr_context != nullptr)
        {
            if (dr_context->IsRecording())
            {
                return true;
            }
        }
    }

    return false;
}

VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::DispatchTraceRaysDumpingContext(
    const std::vector<uint64_t>& dispatch_indices,
    const std::vector<uint64_t>& trace_rays_indices,
    const VulkanObjectInfoTable& object_info_table,
    bool                         dump_resources_before,
    const std::string&           dump_resource_path,
    util::ScreenshotFormat       image_file_format,
    float                        dump_resources_scale) :
    original_command_buffer_info(nullptr),
    DR_command_buffer(VK_NULL_HANDLE), dispatch_indices(dispatch_indices),
    trace_rays_indices(trace_rays_indices), bound_pipelines{ nullptr }, dump_resources_before(dump_resources_before),
    dump_resource_path(dump_resource_path), image_file_format(image_file_format),
    dump_resources_scale(dump_resources_scale), device_table(nullptr), object_info_table(object_info_table),
    replay_device_phys_mem_props(nullptr), current_dispatch_index(0), current_trace_rays_index(0)
{}

VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::~DispatchTraceRaysDumpingContext()
{
    DestroyMutableResourcesClones();

    if (original_command_buffer_info)
    {
        if (DR_command_buffer != VK_NULL_HANDLE)
        {
            const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
            if (device_info)
            {
                VkDevice device = device_info->handle;

                assert(device_table);

                const CommandPoolInfo* pool_info =
                    object_info_table.GetCommandPoolInfo(original_command_buffer_info->pool_id);
                assert(pool_info);

                device_table->FreeCommandBuffers(device, pool_info->handle, 1, &DR_command_buffer);
                DR_command_buffer = VK_NULL_HANDLE;
            }
        }
    }
}

VkResult VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::CloneCommandBuffer(
    const CommandBufferInfo* orig_cmd_buf_info, const encode::DeviceTable* dev_table)
{
    assert(orig_cmd_buf_info);
    assert(dev_table);

    const CommandPoolInfo* cb_pool_info = object_info_table.GetCommandPoolInfo(orig_cmd_buf_info->pool_id);

    const VkCommandBufferAllocateInfo ai{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                                          nullptr,
                                          cb_pool_info->handle,
                                          VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                                          1 };

    const DeviceInfo* dev_info = object_info_table.GetDeviceInfo(orig_cmd_buf_info->parent_id);

    GFXRECON_WRITE_CONSOLE("Allocating a command buffer for Dispatch/TraceRays command buffer context:")

    VkResult res = dev_table->AllocateCommandBuffers(dev_info->handle, &ai, &DR_command_buffer);

    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateCommandBuffers failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    const VkCommandBufferBeginInfo bi{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    dev_table->BeginCommandBuffer(DR_command_buffer, &bi);

    GFXRECON_WRITE_CONSOLE("Done")

    assert(original_command_buffer_info == nullptr);
    original_command_buffer_info = orig_cmd_buf_info;

    assert(device_table == nullptr);
    device_table = dev_table;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info->parent_id != format::kNullHandleId);
    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    assert(phys_dev_info->replay_device_info);
    assert(phys_dev_info->replay_device_info->memory_properties.get());
    replay_device_phys_mem_props = phys_dev_info->replay_device_info->memory_properties.get();

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::BindPipeline(VkPipelineBindPoint bind_point,
                                                                                  const PipelineInfo* pipeline)
{
    PipelineBindPoints point = VkPipelineBindPointToPipelineBindPoint(bind_point);
    bound_pipelines[point]   = pipeline;
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::BindDescriptorSets(
    VkPipelineBindPoint                          pipeline_bind_point,
    VkPipelineLayout                             layout,
    uint32_t                                     first_set,
    const std::vector<const DescriptorSetInfo*>& descriptor_sets_infos,
    uint32_t                                     dynamicOffsetCount,
    const uint32_t*                              pDynamicOffsets)
{
    PipelineBindPoints bind_point = VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);

    for (size_t i = 0; i < descriptor_sets_infos.size(); ++i)
    {
        for (const auto& binding : descriptor_sets_infos[i]->descriptors)
        {
            switch (binding.second.desc_type)
            {
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                {
                    const ImageViewInfo* img_view_info =
                        object_info_table.GetImageViewInfo(binding.second.image_info.image_view_id);
                    assert(img_view_info);

                    const ImageInfo* img_info = object_info_table.GetImageInfo(img_view_info->image_id);
                    assert(img_info);

                    bound_descriptor_sets[bind_point][first_set + i].image_infos[binding.first] = img_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    const BufferInfo* buffer_info =
                        object_info_table.GetBufferInfo(binding.second.buffer_info.buffer_id);
                    assert(buffer_info);

                    bound_descriptor_sets[bind_point][first_set + i].buffer_infos[binding.first] = buffer_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    const BufferViewInfo* buffer_view_info =
                        object_info_table.GetBufferViewInfo(binding.second.texel_buffer_view);
                    assert(buffer_view_info);

                    const BufferInfo* buffer_info = object_info_table.GetBufferInfo(buffer_view_info->buffer_id);
                    assert(buffer_info);

                    bound_descriptor_sets[bind_point][first_set + i].buffer_infos[binding.first] = buffer_info;
                }
                break;

                case VK_DESCRIPTOR_TYPE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    // These are read only resources
                    break;

                default:
                    GFXRECON_LOG_WARNING_ONCE("%s(): Descriptor type (%s) not handled",
                                              __func__,
                                              util::ToString<VkDescriptorType>(binding.second.desc_type).c_str());
                    break;
            }
        }
    }
}

bool VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::ShouldDumpDispatch(uint64_t index) const
{
    // Indices should be sorted
    if (!IsInsideRange(dispatch_indices, index))
    {
        return false;
    }

    for (size_t i = dump_resources_before ? current_dispatch_index / 2 : current_dispatch_index;
         i < dispatch_indices.size();
         ++i)
    {
        if (index == dispatch_indices[i])
        {
            return true;
        }
        else if (index > dispatch_indices[i])
        {
            // Indices should be sorted
            return false;
        }
    }

    return false;
}

bool VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::ShouldDumpTraceRays(uint64_t index) const
{
    // Indices should be sorted
    if (!IsInsideRange(trace_rays_indices, index))
    {
        return false;
    }

    for (size_t i = dump_resources_before ? current_trace_rays_index / 2 : current_trace_rays_index;
         i < trace_rays_indices.size();
         ++i)
    {
        if (index == trace_rays_indices[i])
        {
            return true;
        }
        else if (index > trace_rays_indices[i])
        {
            // Indices should be sorted
            return false;
        }
    }

    return false;
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::CopyBufferResource(
    const BufferInfo* src_buffer_info, VkBuffer dst_buffer)
{
    assert(src_buffer_info);
    assert(dst_buffer != VK_NULL_HANDLE);
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::CopyImageResource(const ImageInfo* src_image_info,
                                                                                       VkImage          dst_image)
{
    assert(src_image_info != nullptr);
    assert(dst_image != VK_NULL_HANDLE);

    VkImageLayout old_layout;
    assert(original_command_buffer_info != nullptr);
    const auto img_layout_entry = original_command_buffer_info->image_layout_barriers.find(src_image_info->capture_id);
    if (img_layout_entry != original_command_buffer_info->image_layout_barriers.end())
    {
        old_layout = img_layout_entry->second;
    }
    else
    {
        old_layout = VK_IMAGE_LAYOUT_GENERAL;
    }

    // Make sure any potential writes are complete and transition image to TRANSFER_SRC_OPTIMAL layout
    VkImageMemoryBarrier img_barrier;
    img_barrier.sType               = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    img_barrier.pNext               = nullptr;
    img_barrier.srcAccessMask       = VK_ACCESS_MEMORY_WRITE_BIT;
    img_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_READ_BIT;
    img_barrier.oldLayout           = old_layout;
    img_barrier.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    img_barrier.srcQueueFamilyIndex = src_image_info->queue_family_index;
    img_barrier.dstQueueFamilyIndex = src_image_info->queue_family_index;
    img_barrier.image               = src_image_info->handle;
    img_barrier.subresourceRange    = {
        graphics::GetFormatAspectMask(src_image_info->format), 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS
    };

    assert(device_table != nullptr);
    device_table->CmdPipelineBarrier(DR_command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VkDependencyFlags(0),
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &img_barrier);

    // Transition destination image
    img_barrier.srcAccessMask = VK_ACCESS_NONE;
    img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    img_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
    img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    img_barrier.image         = dst_image;

    device_table->CmdPipelineBarrier(DR_command_buffer,
                                     VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VkDependencyFlags(0),
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &img_barrier);

    assert(src_image_info->level_count);
    assert(src_image_info->layer_count);

    std::vector<VkImageCopy> copies(src_image_info->level_count, VkImageCopy());
    VkImageCopy              copy;
    copy.srcSubresource.aspectMask     = graphics::GetFormatAspectMask(src_image_info->format);
    copy.srcSubresource.baseArrayLayer = 0;
    copy.srcSubresource.layerCount     = src_image_info->layer_count;
    copy.srcOffset.x                   = 0;
    copy.srcOffset.y                   = 0;
    copy.srcOffset.z                   = 0;

    copy.dstSubresource.aspectMask     = graphics::GetFormatAspectMask(src_image_info->format);
    copy.dstSubresource.baseArrayLayer = 0;
    copy.dstSubresource.layerCount     = src_image_info->layer_count;
    copy.dstOffset.x                   = 0;
    copy.dstOffset.y                   = 0;
    copy.dstOffset.z                   = 0;

    for (uint32_t i = 0; i < src_image_info->level_count; ++i)
    {
        copy.srcSubresource.mipLevel = i;
        copy.dstSubresource.mipLevel = i;
        copy.extent.width            = (src_image_info->extent.width << i);
        copy.extent.height           = (src_image_info->extent.height << i);
        copy.extent.depth            = (src_image_info->extent.depth << i);

        copies[i] = copy;
    }

    device_table->CmdCopyImage(DR_command_buffer,
                               src_image_info->handle,
                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                               dst_image,
                               VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                               copies.size(),
                               copies.data());

    // Wait for transfer and transition source image back to previous layout
    img_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
    img_barrier.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    img_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
    img_barrier.newLayout     = old_layout;
    img_barrier.image         = src_image_info->handle;

    device_table->CmdPipelineBarrier(DR_command_buffer,
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

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::CloneDispatchRaysResources(uint64_t index,
                                                                                                bool cloning_before_cmd,
                                                                                                bool is_dispatch)
{
    assert(IsRecording());
    assert(
        (is_dispatch &&
         index == dispatch_indices[(dump_resources_before ? (current_dispatch_index / 2) : current_dispatch_index)]) ||
        (!is_dispatch &&
         index ==
             trace_rays_indices[(dump_resources_before ? (current_trace_rays_index / 2) : current_trace_rays_index)]));

    // Scan for mutable resources in the bound pipeline
    const PipelineBindPoints bind_point = is_dispatch ? kBindPoint_compute : kBindPoint_ray_tracing;
    const PipelineInfo*      pipeline   = bound_pipelines[bind_point];
    assert(pipeline != nullptr);

    for (const auto& shader : pipeline->shaders)
    {
        for (const auto& desc_set : shader.second.used_descriptors_info)
        {
            const uint32_t set = desc_set.first;
            for (const auto& desc_binding : desc_set.second)
            {
                // Search for resources that are not marked as read only
                if (desc_binding.second.accessed && !desc_binding.second.readonly)
                {
                    const uint32_t binding = desc_binding.first;

                    switch (desc_binding.second.type)
                    {
                        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                        {
                            assert(bound_descriptor_sets[bind_point].find(set) !=
                                   bound_descriptor_sets[bind_point].end());

                            assert(bound_descriptor_sets[bind_point][set].image_infos.find(binding) !=
                                   bound_descriptor_sets[bind_point][set].image_infos.end());

                            const ImageInfo* img_info = bound_descriptor_sets[bind_point][set].image_infos[binding];
                            assert(img_info);

                            VkImage*        new_img_ptr        = nullptr;
                            VkDeviceMemory* new_img_memory_ptr = nullptr;

                            if (!cloning_before_cmd)
                            {
                                mutable_resources_clones.insert({ index, DumpableResourceBackup() });
                                mutable_resources_clones[index].original_images.push_back(img_info);
                                mutable_resources_clones[index].image_desc_set_binding_pair.push_back(
                                    std::make_pair(set, binding));

                                new_img_ptr = &*(mutable_resources_clones[index].images.insert(
                                    mutable_resources_clones[index].images.end(), VK_NULL_HANDLE));

                                new_img_memory_ptr = &*(mutable_resources_clones[index].image_memories.insert(
                                    mutable_resources_clones[index].image_memories.end(), VK_NULL_HANDLE));
                            }
                            else
                            {
                                mutable_resources_clones_before.insert({ index, DumpableResourceBackup() });
                                mutable_resources_clones_before[index].original_images.push_back(img_info);
                                mutable_resources_clones_before[index].image_desc_set_binding_pair.push_back(
                                    std::make_pair(set, binding));

                                new_img_ptr = &*(mutable_resources_clones_before[index].images.insert(
                                    mutable_resources_clones_before[index].images.end(), VK_NULL_HANDLE));

                                new_img_memory_ptr = &*(mutable_resources_clones_before[index].image_memories.insert(
                                    mutable_resources_clones_before[index].image_memories.end(), VK_NULL_HANDLE));
                            }

                            assert(new_img_ptr != nullptr);
                            assert(new_img_memory_ptr != nullptr);

                            CloneImage(object_info_table,
                                       device_table,
                                       replay_device_phys_mem_props,
                                       img_info,
                                       new_img_ptr,
                                       new_img_memory_ptr);

                            CopyImageResource(img_info, *new_img_ptr);
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                        {
                            assert(bound_descriptor_sets[bind_point].find(set) !=
                                   bound_descriptor_sets[bind_point].end());

                            assert(bound_descriptor_sets[bind_point][set].buffer_infos.find(binding) !=
                                   bound_descriptor_sets[bind_point][set].buffer_infos.end());

                            const BufferInfo* buf_info = bound_descriptor_sets[bind_point][set].buffer_infos[binding];
                            assert(buf_info);

                            VkBuffer*       new_buf_ptr        = nullptr;
                            VkDeviceMemory* new_buf_memory_ptr = nullptr;

                            if (!cloning_before_cmd)
                            {
                                mutable_resources_clones.insert({ index, DumpableResourceBackup() });
                                mutable_resources_clones[index].original_buffers.push_back(buf_info);
                                mutable_resources_clones[index].buffer_desc_set_binding_pair.push_back(
                                    std::make_pair(set, binding));

                                new_buf_ptr = &*(mutable_resources_clones[index].buffers.insert(
                                    mutable_resources_clones[index].buffers.end(), VK_NULL_HANDLE));

                                new_buf_memory_ptr = &*(mutable_resources_clones[index].buffer_memories.insert(
                                    mutable_resources_clones[index].buffer_memories.end(), VK_NULL_HANDLE));
                            }
                            else
                            {
                                mutable_resources_clones_before.insert({ index, DumpableResourceBackup() });
                                mutable_resources_clones_before[index].original_buffers.push_back(buf_info);
                                mutable_resources_clones_before[index].buffer_desc_set_binding_pair.push_back(
                                    std::make_pair(set, binding));

                                new_buf_ptr = &*(mutable_resources_clones_before[index].buffers.insert(
                                    mutable_resources_clones_before[index].buffers.end(), VK_NULL_HANDLE));

                                new_buf_memory_ptr = &*(mutable_resources_clones_before[index].buffer_memories.insert(
                                    mutable_resources_clones_before[index].buffer_memories.end(), VK_NULL_HANDLE));
                            }

                            assert(new_buf_ptr != nullptr);
                            assert(new_buf_memory_ptr != nullptr);

                            CloneBuffer(object_info_table,
                                        device_table,
                                        replay_device_phys_mem_props,
                                        buf_info,
                                        new_buf_ptr,
                                        new_buf_memory_ptr);

                            CopyBufferResource(buf_info, *new_buf_ptr);
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_SAMPLER:
                        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                            // These are read only resources
                            break;

                        default:
                            GFXRECON_LOG_WARNING_ONCE(
                                "%s(): Descriptor type (%s) not handled",
                                __func__,
                                util::ToString<VkDescriptorType>(desc_binding.second.type).c_str());
                            break;
                    }
                }
            }
        }
    }

    if (is_dispatch)
    {
        ++current_dispatch_index;
    }
    else
    {
        ++current_trace_rays_index;
    }
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::DestroyMutableResourcesClones()
{
    for (auto& dr_entry : mutable_resources_clones)
    {
        for (size_t i = 0; i < dr_entry.second.original_images.size(); ++i)
        {
            const DeviceInfo* device_info =
                object_info_table.GetDeviceInfo(dr_entry.second.original_images[i]->parent_id);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(device, dr_entry.second.image_memories[i], nullptr);
            device_table->DestroyImage(device, dr_entry.second.images[i], nullptr);
        }

        for (size_t i = 0; i < dr_entry.second.original_buffers.size(); ++i)
        {
            const DeviceInfo* device_info =
                object_info_table.GetDeviceInfo(dr_entry.second.original_buffers[i]->parent_id);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(device, dr_entry.second.buffer_memories[i], nullptr);
            device_table->DestroyBuffer(device, dr_entry.second.buffers[i], nullptr);
        }
    }

    for (auto& dr_entry : mutable_resources_clones_before)
    {
        for (size_t i = 0; i < dr_entry.second.original_images.size(); ++i)
        {
            const DeviceInfo* device_info =
                object_info_table.GetDeviceInfo(dr_entry.second.original_images[i]->parent_id);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(device, dr_entry.second.image_memories[i], nullptr);
            device_table->DestroyImage(device, dr_entry.second.images[i], nullptr);
        }

        for (size_t i = 0; i < dr_entry.second.original_buffers.size(); ++i)
        {
            const DeviceInfo* device_info =
                object_info_table.GetDeviceInfo(dr_entry.second.original_buffers[i]->parent_id);
            VkDevice device = device_info->handle;

            device_table->FreeMemory(device, dr_entry.second.buffer_memories[i], nullptr);
            device_table->DestroyBuffer(device, dr_entry.second.buffers[i], nullptr);
        }
    }
}

VkResult
VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::DumpDispatchRaysMutableResources(VkQueue  queue,
                                                                                                 uint64_t bcb_index)
{
    GFXRECON_WRITE_CONSOLE("Submitting Dispatc/TraceRays command buffer for BeginCommandBuffer: %" PRIu64, bcb_index);

    VkSubmitInfo submit_info;
    submit_info.sType                = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.pNext                = nullptr;
    submit_info.waitSemaphoreCount   = 0;
    submit_info.pWaitSemaphores      = nullptr;
    submit_info.pWaitDstStageMask    = nullptr;
    submit_info.commandBufferCount   = 1;
    submit_info.pCommandBuffers      = &DR_command_buffer;
    submit_info.signalSemaphoreCount = 0;
    submit_info.pSignalSemaphores    = nullptr;

    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const VkFenceCreateInfo ci = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
    VkFence                 submission_fence;
    VkResult                res = device_table->CreateFence(device_info->handle, &ci, nullptr, &submission_fence);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("CreateFence failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    res = device_table->QueueSubmit(queue, 1, &submit_info, submission_fence);
    assert(res == VK_SUCCESS);
    if (res != VK_SUCCESS)
    {
        device_table->DestroyFence(device_info->handle, submission_fence, nullptr);
        GFXRECON_LOG_ERROR(
            "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        return res;
    }

    // Wait
    res = device_table->WaitForFences(device_info->handle, 1, &submission_fence, VK_TRUE, ~0UL);
    assert(res == VK_SUCCESS);
    if (res != VK_SUCCESS)
    {
        device_table->DestroyFence(device_info->handle, submission_fence, nullptr);
        GFXRECON_LOG_ERROR("WaitForFences failed with %s", util::ToString<VkResult>(res).c_str());
        return res;
    }

    device_table->DestroyFence(device_info->handle, submission_fence, nullptr);

    for (auto index : dispatch_indices)
    {
        DumpMutableResources(index, true);
    }

    for (auto index : trace_rays_indices)
    {
        DumpMutableResources(index, false);
    }

    return VK_SUCCESS;
}

std::string VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::GenerateImageFilename(
    VkFormat format, bool is_dispatch, uint64_t index, uint32_t desc_set, uint32_t desc_binding, bool before_cmd) const
{
    util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(format);

    std::vector<VkImageAspectFlagBits> aspects;
    bool                               combined_depth_stencil;
    graphics::GetFormatAspects(format, &aspects, &combined_depth_stencil);

    std::string aspect_str_whole(util::ToString<VkImageAspectFlagBits>(aspects[0]));
    std::string aspect_str(aspect_str_whole.begin() + 16, aspect_str_whole.end() - 4);

    std::stringstream filename;
    if (before_cmd)
    {
        if (VkFormatToImageWriterDataFormat(format) != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            filename << dump_resource_path << (is_dispatch ? "Dispatch_" : "TraceRays_") << "before_" << index
                     << "_set_" << desc_set << "_binding_" << desc_binding << "_"
                     << util::ToString<VkFormat>(format).c_str() << "_aspect_" << aspect_str
                     << util::ScreenshotFormatToCStr(image_file_format);
        }
        else
        {
            filename << dump_resource_path << (is_dispatch ? "Dispatch_" : "TraceRays_") << "before_" << index
                     << "_set_" << desc_set << "_binding_" << desc_binding << "_aspect_" << aspect_str
                     << util::ToString<VkFormat>(format) << ".bin";
        }
    }
    else
    {
        if (VkFormatToImageWriterDataFormat(format) != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            filename << dump_resource_path << (is_dispatch ? "Dispatch_" : "TraceRays_")
                     << (dump_resources_before ? "after_" : "") << index << "_set_" << desc_set << "_binding_"
                     << desc_binding << "_" << util::ToString<VkFormat>(format).c_str() << "_aspect_" << aspect_str
                     << util::ScreenshotFormatToCStr(image_file_format);
        }
        else
        {
            filename << dump_resource_path << (is_dispatch ? "Dispatch_" : "TraceRays_")
                     << (dump_resources_before ? "after_" : "") << index << "_set_" << desc_set << "_binding_"
                     << desc_binding << "_aspect_" << aspect_str << util::ToString<VkFormat>(format).c_str() << ".bin";
        }
    }

    return filename.str();
}

std::string VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::GenerateBufferFilename(
    bool is_dispatch, uint64_t index, uint32_t desc_set, uint32_t desc_binding, bool before_cmd) const
{
    std::stringstream filename;

    if (before_cmd)
    {
        filename << dump_resource_path << (is_dispatch ? "Dispatch_" : "TraceRays_") << "before_" << index << "_set_"
                 << desc_set << "_binding_" << desc_binding << "_buffer.bin";
    }
    else
    {
        filename << dump_resource_path << (is_dispatch ? "Dispatch_" : "TraceRays_")
                 << (dump_resources_before ? "after_" : "") << index << "_set_" << desc_set << "_binding_"
                 << desc_binding << "_buffer.bin";
    }

    return filename.str();
}

VkResult VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::DumpMutableResources(uint64_t index,
                                                                                              bool     is_dispatch)
{
    if (!mutable_resources_clones.size())
    {
        assert(!mutable_resources_clones_before.size());
        return VK_SUCCESS;
    }

    assert(original_command_buffer_info);
    assert(original_command_buffer_info->parent_id != format::kNullHandleId);
    const DeviceInfo* device_info = object_info_table.GetDeviceInfo(original_command_buffer_info->parent_id);
    assert(device_info);

    const PhysicalDeviceInfo* phys_dev_info = object_info_table.GetPhysicalDeviceInfo(device_info->parent_id);
    assert(phys_dev_info);

    graphics::VulkanResourcesUtil resource_util(
        device_info->handle, *device_table, *phys_dev_info->replay_device_info->memory_properties);

    if (dump_resources_before)
    {
        assert(mutable_resources_clones_before.size());
        assert(mutable_resources_clones_before.find(index) != mutable_resources_clones_before.end());

        // Dump images
        for (size_t i = 0; i < mutable_resources_clones_before[index].original_images.size(); ++i)
        {
            const ImageInfo*      image_info = mutable_resources_clones_before[index].original_images[i];
            std::vector<uint8_t>  data;
            std::vector<uint64_t> subresource_offsets;
            std::vector<uint64_t> subresource_sizes;

            VkResult res = resource_util.ReadFromImageResourceStaging(mutable_resources_clones_before[index].images[i],
                                                                      image_info->format,
                                                                      image_info->type,
                                                                      image_info->extent,
                                                                      image_info->level_count,
                                                                      image_info->layer_count,
                                                                      image_info->tiling,
                                                                      image_info->sample_count,
                                                                      VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                                      0,
                                                                      VK_IMAGE_ASPECT_COLOR_BIT,
                                                                      data,
                                                                      subresource_offsets,
                                                                      subresource_sizes,
                                                                      false,
                                                                      dump_resources_scale);

            if (res != VK_SUCCESS)
            {
                return res;
            }

            uint32_t    desc_set = mutable_resources_clones_before[index].image_desc_set_binding_pair[i].first;
            uint32_t    binding  = mutable_resources_clones_before[index].image_desc_set_binding_pair[i].second;
            std::string filename =
                GenerateImageFilename(image_info->format, is_dispatch, index, desc_set, binding, true);
            util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);
            if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
            {

                const uint32_t texel_size =
                    vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_COLOR_BIT);
                const uint32_t stride = texel_size * image_info->extent.width * dump_resources_scale;

                if (image_file_format == util::ScreenshotFormat::kBmp)
                {
                    util::imagewriter::WriteBmpImage(filename,
                                                     image_info->extent.width * dump_resources_scale,
                                                     image_info->extent.height * dump_resources_scale,
                                                     subresource_sizes[0],
                                                     data.data(),
                                                     stride,
                                                     output_image_format);
                }
                else
                {
                    util::imagewriter::WritePngImage(filename,
                                                     image_info->extent.width * dump_resources_scale,
                                                     image_info->extent.height * dump_resources_scale,
                                                     subresource_sizes[0],
                                                     data.data(),
                                                     stride,
                                                     output_image_format);
                }
            }
            else
            {
                util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
            }
        }

        // Dump buffers
        for (size_t i = 0; i < mutable_resources_clones_before[index].original_buffers.size(); ++i)
        {
            const BufferInfo*    buffer_info = mutable_resources_clones_before[index].original_buffers[i];
            std::vector<uint8_t> data;

            VkResult res = resource_util.ReadFromBufferResource(mutable_resources_clones_before[index].buffers[i],
                                                                buffer_info->size,
                                                                buffer_info->queue_family_index,
                                                                data);

            if (res != VK_SUCCESS)
            {
                return res;
            }

            uint32_t    desc_set = mutable_resources_clones_before[index].buffer_desc_set_binding_pair[i].first;
            uint32_t    binding  = mutable_resources_clones_before[index].buffer_desc_set_binding_pair[i].second;
            std::string filename = GenerateBufferFilename(is_dispatch, index, desc_set, binding, true);

            util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
        }
    }

    assert(mutable_resources_clones.find(index) != mutable_resources_clones.end());

    for (size_t i = 0; i < mutable_resources_clones[index].original_images.size(); ++i)
    {
        const ImageInfo*      image_info = mutable_resources_clones[index].original_images[i];
        std::vector<uint8_t>  data;
        std::vector<uint64_t> subresource_offsets;
        std::vector<uint64_t> subresource_sizes;

        VkResult res = resource_util.ReadFromImageResourceStaging(mutable_resources_clones[index].images[i],
                                                                  image_info->format,
                                                                  image_info->type,
                                                                  image_info->extent,
                                                                  image_info->level_count,
                                                                  image_info->layer_count,
                                                                  image_info->tiling,
                                                                  image_info->sample_count,
                                                                  VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                                  0,
                                                                  VK_IMAGE_ASPECT_COLOR_BIT,
                                                                  data,
                                                                  subresource_offsets,
                                                                  subresource_sizes,
                                                                  false,
                                                                  dump_resources_scale);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        uint32_t    desc_set = mutable_resources_clones[index].image_desc_set_binding_pair[i].first;
        uint32_t    binding  = mutable_resources_clones[index].image_desc_set_binding_pair[i].second;
        std::string filename = GenerateImageFilename(image_info->format, is_dispatch, index, desc_set, binding, false);
        util::imagewriter::DataFormats output_image_format = VkFormatToImageWriterDataFormat(image_info->format);
        if (output_image_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED)
        {
            const uint32_t texel_size = vkuFormatElementSizeWithAspect(image_info->format, VK_IMAGE_ASPECT_COLOR_BIT);
            const uint32_t stride     = texel_size * image_info->extent.width * dump_resources_scale;

            if (image_file_format == util::ScreenshotFormat::kBmp)
            {
                util::imagewriter::WriteBmpImage(filename,
                                                 image_info->extent.width * dump_resources_scale,
                                                 image_info->extent.height * dump_resources_scale,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
            else
            {
                util::imagewriter::WritePngImage(filename,
                                                 image_info->extent.width * dump_resources_scale,
                                                 image_info->extent.height * dump_resources_scale,
                                                 subresource_sizes[0],
                                                 data.data(),
                                                 stride,
                                                 output_image_format);
            }
        }
        else
        {
            util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
        }
    }

    // Dump buffers
    for (size_t i = 0; i < mutable_resources_clones[index].original_buffers.size(); ++i)
    {
        const BufferInfo*    buffer_info = mutable_resources_clones[index].original_buffers[i];
        std::vector<uint8_t> data;

        VkResult res = resource_util.ReadFromBufferResource(
            mutable_resources_clones[index].buffers[i], buffer_info->size, buffer_info->queue_family_index, data);

        if (res != VK_SUCCESS)
        {
            return res;
        }

        uint32_t    desc_set = mutable_resources_clones[index].buffer_desc_set_binding_pair[i].first;
        uint32_t    binding  = mutable_resources_clones[index].buffer_desc_set_binding_pair[i].second;
        std::string filename = GenerateBufferFilename(is_dispatch, index, desc_set, binding, false);

        util::bufferwriter::WriteBuffer(filename, data.data(), data.size());
    }

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::FinalizeCommandBuffer()
{
    assert((dump_resources_before ? (current_dispatch_index / 2) : current_dispatch_index) == dispatch_indices.size() &&
           (dump_resources_before ? (current_trace_rays_index / 2) : current_trace_rays_index) ==
               trace_rays_indices.size());
    assert(DR_command_buffer != VK_NULL_HANDLE);

    GFXRECON_WRITE_CONSOLE("Finalizing Dispach/TraceRays command buffer")

    device_table->EndCommandBuffer(DR_command_buffer);
}

bool VulkanReplayDumpResourcesBase::DispatchTraceRaysDumpingContext::IsRecording() const
{
    if (!dump_resources_before)
    {
        return current_dispatch_index < dispatch_indices.size() || current_trace_rays_index < trace_rays_indices.size();
    }
    else
    {
        return ((current_dispatch_index / 2) < dispatch_indices.size()) ||
               ((current_trace_rays_index / 2) < trace_rays_indices.size());
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
