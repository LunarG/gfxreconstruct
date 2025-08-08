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

#include "decode/vulkan_replay_dump_resources_delegate.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_resources_util.h"
#include "util/buffer_writer.h"
#include "util/logging.h"
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

bool DefaultVulkanDumpResourcesDelegate::IsImageDumpable(const graphics::VulkanInstanceTable* instance_table,
                                                         const VulkanImageInfo*               image_info)
{
    GFXRECON_ASSERT(instance_table != nullptr);
    GFXRECON_ASSERT(image_info != nullptr);

    // Check for multisampled images that cannot be dumped
    if (image_info->sample_count == VK_SAMPLE_COUNT_1_BIT)
    {
        return true;
    }

    if (instance_table != nullptr)
    {
        VulkanDeviceInfo* device = object_info_table_.GetVkDeviceInfo(image_info->parent_id);
        if (device != nullptr)
        {
            VkFormatProperties format_properties{};
            instance_table->GetPhysicalDeviceFormatProperties(device->parent, image_info->format, &format_properties);
            if ((format_properties.optimalTilingFeatures & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT) !=
                VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT)
            {
                return false;
            }
        }
    }

    return true;
}

void DefaultVulkanDumpResourcesDelegate::DumpDrawCallInfo(const VulkanDelegateDumpDrawCallContext& draw_call_info)
{
    switch (draw_call_info.command_type)
    {
        case DumpResourcesCommandType::kGraphics:
            GenerateOutputJsonDrawCallInfo(draw_call_info);
            break;
        case DumpResourcesCommandType::kCompute:
            GenerateOutputJsonDispatchInfo(draw_call_info);
            break;
        case DumpResourcesCommandType::kRayTracing:
            GenerateOutputJsonTraceRaysIndex(draw_call_info);
            break;
        default:
            break;
    }
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpResource(const VulkanDelegateDumpResourceContext& delegate_context)
{
    const DumpedResourceBase* resource_info = delegate_context.dumped_resource;
    switch (resource_info->type)
    {
        case DumpResourceType::kRtv:
        case DumpResourceType::kDsv:
        case DumpResourceType::kImageDescriptor:
        case DumpResourceType::kDispatchTraceRaysImage:
        case DumpResourceType::kDispatchTraceRaysImageDescriptor:
            return DumpImage(delegate_context);
            break;

        case DumpResourceType::kVertex:
        case DumpResourceType::kIndex:
        case DumpResourceType::kBufferDescriptor:
        case DumpResourceType::kDispatchTraceRaysBuffer:
        case DumpResourceType::kDispatchTraceRaysBufferDescriptor:
            return DumpBuffer(delegate_context);
            break;

        case DumpResourceType::kInlineUniformBufferDescriptor:
        case DumpResourceType::kDispatchTraceRaysInlineUniformBufferDescriptor:
            return DumpInlineUniformBufferDescriptor(delegate_context);
            break;

        default:
            break;
    }
    return VK_ERROR_UNKNOWN;
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpBuffer(const VulkanDelegateDumpResourceContext& delegate_context)
{
    DumpedResourceBase* dumped_resource = static_cast<DumpedDescriptor*>(delegate_context.dumped_resource);
    GFXRECON_ASSERT(dumped_resource != nullptr);

    DumpedBuffer*           dumped_buffer;
    BufferFilenameGenerator filename_generator;

    switch (delegate_context.dumped_resource->type)
    {
        case DumpResourceType::kVertex:
        case DumpResourceType::kIndex:
        {
            filename_generator = delegate_context.dumped_resource->type == DumpResourceType::kVertex
                                     ? &DefaultVulkanDumpResourcesDelegate::GenerateVertexBufferFilename
                                     : &DefaultVulkanDumpResourcesDelegate::GenerateIndexBufferFilename;

            DumpedVertexIndexBuffer* dumped_vertex_index_buffer =
                static_cast<DumpedVertexIndexBuffer*>(delegate_context.dumped_resource);
            dumped_buffer = &dumped_vertex_index_buffer->buffer;
        }
        break;

        case DumpResourceType::kBufferDescriptor:
        case DumpResourceType::kDispatchTraceRaysBuffer:
        case DumpResourceType::kDispatchTraceRaysBufferDescriptor:
        {
            if (delegate_context.dumped_resource->type == DumpResourceType::kBufferDescriptor)
            {
                filename_generator = &DefaultVulkanDumpResourcesDelegate::GenerateGraphicsBufferDescriptorFilename;
            }
            else if (delegate_context.dumped_resource->type == DumpResourceType::kDispatchTraceRaysBuffer)
            {
                filename_generator = &DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysBufferFilename;
            }
            else
            {
                GFXRECON_ASSERT(
                    (delegate_context.dumped_resource->type == DumpResourceType::kDispatchTraceRaysBufferDescriptor));
                filename_generator =
                    &DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysBufferDescriptorFilename;
            }

            DumpedDescriptor* dumped_buffer_desc = static_cast<DumpedDescriptor*>(delegate_context.dumped_resource);
            GFXRECON_ASSERT(dumped_buffer_desc != nullptr);
            dumped_buffer = std::get_if<DumpedBuffer>(&dumped_buffer_desc->dumped_resource);
            GFXRECON_ASSERT(dumped_buffer != nullptr);
        }
        break;

        default:
            GFXRECON_LOG_ERROR("%s(): Unexpected resource type", __func__)
    }

    dumped_buffer->filename = std::invoke(filename_generator, *this, *dumped_resource, false);

    if (dumped_resource->before_command)
    {
        dumped_buffer->filename_before = std::invoke(filename_generator, *this, *dumped_resource, true);
    }

    const VulkanBufferInfo* buffer_info = dumped_buffer->buffer_info;
    GFXRECON_ASSERT(buffer_info != nullptr);
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(buffer_info->parent_id);
    GFXRECON_ASSERT(device_info != nullptr);

    VkResult res = DumpBufferToFile(*dumped_buffer,
                                    device_info,
                                    delegate_context.device_table,
                                    delegate_context.instance_table,
                                    object_info_table_,
                                    dumped_resource->before_command,
                                    delegate_context.compressor);

    return res;
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpImage(const VulkanDelegateDumpResourceContext& delegate_context)
{
    DumpedResourceBase* dumped_resource = delegate_context.dumped_resource;
    GFXRECON_ASSERT(dumped_resource != nullptr);

    DumpedImage*           dumped_image;
    ImageFilenameGenerator filename_generator;

    switch (dumped_resource->type)
    {
        case DumpResourceType::kRtv:
        case DumpResourceType::kDsv:
        {
            filename_generator            = &DefaultVulkanDumpResourcesDelegate::GenerateRenderTargetImageFilename;
            DumpedRenderTarget* dumped_rt = static_cast<DumpedRenderTarget*>(dumped_resource);
            dumped_image                  = &dumped_rt->image;
        }
        break;

        case DumpResourceType::kImageDescriptor:
        case DumpResourceType::kDispatchTraceRaysImage:
        case DumpResourceType::kDispatchTraceRaysImageDescriptor:
        {
            if (dumped_resource->type == DumpResourceType::kImageDescriptor)
            {
                filename_generator = &DefaultVulkanDumpResourcesDelegate::GenerateGraphicsImageDescriptorFilename;
            }
            else if (dumped_resource->type == DumpResourceType::kDispatchTraceRaysImage)
            {
                filename_generator = &DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysImageFilename;
            }
            else
            {
                filename_generator =
                    &DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysImageDescriptorFilename;
            }

            DumpedDescriptor* dumped_desc = static_cast<DumpedDescriptor*>(dumped_resource);
            dumped_image                  = std::get_if<DumpedImage>(&dumped_desc->dumped_resource);
            GFXRECON_ASSERT(dumped_image != nullptr);
        }
        break;

        default:
            GFXRECON_LOG_ERROR("%s(): Unexpected resource type", __func__)
    }

    const VulkanImageInfo*  image_info  = dumped_image->image_info;
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(image_info->parent_id);
    GFXRECON_ASSERT(device_info != nullptr);

    if (!IsImageDumpable(delegate_context.instance_table, image_info))
    {
        return VK_SUCCESS;
    }

    const DumpedImageFormat output_image_format = GetDumpedImageFormat(device_info,
                                                                       delegate_context.device_table,
                                                                       delegate_context.instance_table,
                                                                       object_info_table_,
                                                                       image_info->format,
                                                                       image_info->tiling,
                                                                       image_info->type,
                                                                       options_.dump_resources_image_format,
                                                                       options_.dump_resources_dump_raw_images);

    dumped_image->dumped_raw = output_image_format == DumpedImageFormat::KFormatRaw;

    std::vector<VkImageAspectFlagBits> aspects;
    GetFormatAspects(image_info->format, aspects);
    const size_t subresources_count = options_.dump_resources_dump_all_image_subresources
                                          ? (aspects.size() * image_info->layer_count * image_info->level_count)
                                          : aspects.size();

    dumped_image->dumped_subresources.resize(subresources_count);

    size_t sr = 0;
    for (auto aspect : aspects)
    {
        for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
        {
            for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
            {
                dumped_image->dumped_subresources[sr].aspect   = aspect;
                dumped_image->dumped_subresources[sr].level    = mip;
                dumped_image->dumped_subresources[sr].layer    = layer;
                dumped_image->dumped_subresources[sr].filename = std::invoke(
                    filename_generator, *this, *dumped_resource, output_image_format, aspect, mip, layer, false);

                if (dumped_resource->before_command)
                {
                    dumped_image->dumped_subresources[sr].filename_before = std::invoke(
                        filename_generator, *this, *dumped_resource, output_image_format, aspect, mip, layer, true);
                }

                ++sr;

                if (!options_.dump_resources_dump_all_image_subresources)
                {
                    break;
                }
            }

            if (!options_.dump_resources_dump_all_image_subresources)
            {
                break;
            }
        }

        if (!options_.dump_resources_dump_all_image_subresources)
        {
            break;
        }
    }

    VkResult res = DumpImageToFile(*dumped_image,
                                   device_info,
                                   delegate_context.device_table,
                                   delegate_context.instance_table,
                                   object_info_table_,
                                   options_.dump_resources_scale,
                                   options_.dump_resources_image_format,
                                   dumped_resource->before_command,
                                   delegate_context.compressor,
                                   options_.dump_resources_dump_all_image_subresources,
                                   options_.dump_resources_dump_raw_images,
                                   options_.dump_resources_dump_separate_alpha,
                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
    if (res != VK_SUCCESS)
    {
        if (res == VK_ERROR_FEATURE_NOT_PRESENT)
        {
            // Failures to dump images due to multisampling should be ok
            GFXRECON_LOG_WARNING("Image could not be resolved (%s)",
                                 util::ToString<VkFormat>(image_info->format).c_str())
            return VK_SUCCESS;
        }
        else
        {
            GFXRECON_LOG_ERROR("Dumping image failed (%s)", util::ToString<VkResult>(res).c_str())
        }
    }

    return res;
}

std::string
DefaultVulkanDumpResourcesDelegate::GenerateRenderTargetImageFilename(const DumpedResourceBase& dumped_resource,
                                                                      DumpedImageFormat         output_image_format,
                                                                      VkImageAspectFlagBits     aspect,
                                                                      uint32_t                  mip_level,
                                                                      uint32_t                  layer,
                                                                      bool                      before_command) const
{
    const DumpedRenderTarget& rt_resource_info = static_cast<const DumpedRenderTarget&>(dumped_resource);
    const VulkanImageInfo*    image_info       = rt_resource_info.image.image_info;
    std::string               aspect_str       = ImageAspectToStr(aspect);
    std::string               attachment_str   = rt_resource_info.location != DEPTH_ATTACHMENT
                                                     ? "_att_" + std::to_string(rt_resource_info.location)
                                                     : "_depth_att";

    std::stringstream filename;
    filename << capture_filename_ << "_";

    if (output_image_format != KFormatRaw)
    {
        if (options_.dump_resources_before)
        {
            filename << "draw_" << ((!before_command) ? "after_" : "before_") << rt_resource_info.cmd_index << "_qs_"
                     << rt_resource_info.qs_index << "_bcb_" << rt_resource_info.bcb_index << attachment_str
                     << "_aspect_" << aspect_str;
        }
        else
        {
            filename << "draw_" << rt_resource_info.cmd_index << "_qs_" << rt_resource_info.qs_index << "_bcb_"
                     << rt_resource_info.bcb_index << attachment_str << "_aspect_" << aspect_str;
        }
    }
    else
    {
        if (options_.dump_resources_before)
        {
            filename << "draw_" << ((!before_command) ? "after_" : "before_") << rt_resource_info.cmd_index << "_qs_"
                     << rt_resource_info.qs_index << "_bcb_" << rt_resource_info.bcb_index << "_"
                     << rt_resource_info.qs_index << "_" << rt_resource_info.bcb_index << attachment_str << "_"
                     << util::ToString<VkFormat>(image_info->format) << "_aspect_" << aspect_str;
        }
        else
        {
            filename << "draw_" << rt_resource_info.cmd_index << "_qs_" << rt_resource_info.qs_index << "_bcb_"
                     << rt_resource_info.bcb_index << attachment_str << "_"
                     << util::ToString<VkFormat>(image_info->format) << "_aspect_" << aspect_str;
        }
    }

    std::stringstream subresource_sting;
    subresource_sting << "_mip_" << mip_level << "_layer_" << layer;
    subresource_sting << ImageFileExtension(output_image_format);

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str() + subresource_sting.str());
    return (filedirname / filebasename).string();
}

std::string
DefaultVulkanDumpResourcesDelegate::GenerateGraphicsImageDescriptorFilename(const DumpedResourceBase& dumped_resource,
                                                                            DumpedImageFormat     output_image_format,
                                                                            VkImageAspectFlagBits aspect,
                                                                            uint32_t              mip_level,
                                                                            uint32_t              layer,
                                                                            bool                  before_command) const
{
    GFXRECON_UNREFERENCED_PARAMETER(before_command);

    const DumpedDescriptor& image_desc_info = static_cast<const DumpedDescriptor&>(dumped_resource);
    const DumpedImage*      dumped_image    = std::get_if<DumpedImage>(&image_desc_info.dumped_resource);
    GFXRECON_ASSERT(dumped_image != nullptr);

    const VulkanImageInfo* image_info = dumped_image->image_info;
    std::string            aspect_str = ImageAspectToStr(aspect);
    std::stringstream      base_filename;
    base_filename << capture_filename_ << "_";

    if (output_image_format != KFormatRaw)
    {
        base_filename << "image_" << image_info->capture_id << "_qs_" << image_desc_info.qs_index << "_bcb_"
                      << image_desc_info.bcb_index << "_dc_index_" << image_desc_info.cmd_index << "_rp_"
                      << image_desc_info.render_pass << "_aspect_" << aspect_str;
    }
    else
    {
        std::string whole_format_name = util::ToString<VkFormat>(image_info->format);
        std::string format_name(whole_format_name.begin() + 10, whole_format_name.end());

        base_filename << "image_" << image_info->capture_id << "_qs_" << image_desc_info.qs_index << "_bcb_"
                      << image_desc_info.bcb_index << "_dc_index_" << image_desc_info.cmd_index << "_rp_"
                      << image_desc_info.render_pass << "_" << format_name << "_aspect_" << aspect_str;
    }

    std::stringstream sub_resources_str;
    sub_resources_str << base_filename.str() << "_mip_" << mip_level << "_layer_" << layer;
    sub_resources_str << ImageFileExtension(output_image_format);

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(sub_resources_str.str());
    return (filedirname / filebasename).string();
}

std::string
DefaultVulkanDumpResourcesDelegate::GenerateGraphicsBufferDescriptorFilename(const DumpedResourceBase& dumped_resource,
                                                                             bool before_command) const
{
    GFXRECON_UNREFERENCED_PARAMETER(before_command);

    const DumpedDescriptor& dumped_desc = static_cast<const DumpedDescriptor&>(dumped_resource);

    const DumpedBuffer* dumped_buffer = std::get_if<DumpedBuffer>(&dumped_desc.dumped_resource);
    GFXRECON_ASSERT(dumped_buffer != nullptr);

    const VulkanBufferInfo* buffer_info = dumped_buffer->buffer_info;

    std::stringstream filename;

    filename << capture_filename_ << "_"
             << "buffer_" << buffer_info->capture_id << "_qs_" << dumped_desc.qs_index << "_bcb_"
             << dumped_desc.bcb_index << "_dc_index_" << dumped_desc.cmd_index << "_rp_" << dumped_desc.render_pass
             << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpInlineUniformBufferDescriptor(
    const VulkanDelegateDumpResourceContext& delegate_context)
{
    DumpedDescriptor* dumped_buffer_desc = static_cast<DumpedDescriptor*>(delegate_context.dumped_resource);
    GFXRECON_ASSERT(dumped_buffer_desc != nullptr);
    GFXRECON_ASSERT(!dumped_buffer_desc->before_command);

    GFXRECON_ASSERT(dumped_buffer_desc->resource_type != DumpResourcesCommandType::kNone);
    const bool        is_graphics = dumped_buffer_desc->resource_type == DumpResourcesCommandType::kGraphics;
    const std::string filename =
        is_graphics ? GenerateGraphicsInlineUniformBufferDescriptorFilename(*dumped_buffer_desc, false)
                    : GenerateDispatchTraceRaysInlineUniformBufferDescriptorFilename(*dumped_buffer_desc, false);

    DumpedBuffer* dumped_buffer = std::get_if<DumpedBuffer>(&dumped_buffer_desc->dumped_resource);
    GFXRECON_ASSERT(dumped_buffer != nullptr);

    dumped_buffer->filename = filename;

    const size_t bytes_written = util::bufferwriter::WriteBuffer(filename,
                                                                 dumped_buffer->inline_uniform_data.data(),
                                                                 dumped_buffer->inline_uniform_data.size(),
                                                                 delegate_context.compressor);

    if (bytes_written && bytes_written != dumped_buffer->size)
    {
        GFXRECON_ASSERT(delegate_context.compressor != nullptr);
        dumped_buffer->compressed_size = bytes_written;
    }

    return bytes_written ? VK_SUCCESS : VK_ERROR_UNKNOWN;
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateGraphicsInlineUniformBufferDescriptorFilename(
    const DumpedResourceBase& dumped_resource, bool before_command) const
{
    GFXRECON_UNREFERENCED_PARAMETER(before_command);

    const DumpedDescriptor& buffer_desc_info = static_cast<const DumpedDescriptor&>(dumped_resource);

    std::stringstream filename;
    filename << capture_filename_ << "_"
             << "inlineUniformBlock_set_" << buffer_desc_info.set << "_binding_" << buffer_desc_info.binding << "_qs_"
             << buffer_desc_info.qs_index << "_bcb_" << buffer_desc_info.bcb_index << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateVertexBufferFilename(const DumpedResourceBase& dumped_resource,
                                                                             bool before_command) const
{
    GFXRECON_UNREFERENCED_PARAMETER(before_command);

    const DumpedVertexIndexBuffer& vertex_buffer = static_cast<const DumpedVertexIndexBuffer&>(dumped_resource);

    std::stringstream filename;
    filename << capture_filename_ << "_"
             << "vertexBuffers_"
             << "qs_" << vertex_buffer.qs_index << "_bcb_" << vertex_buffer.bcb_index << "_dc_"
             << vertex_buffer.cmd_index << "_binding_" << vertex_buffer.binding << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateIndexBufferFilename(const DumpedResourceBase& dumped_resource,
                                                                            bool before_command) const
{
    GFXRECON_UNREFERENCED_PARAMETER(before_command);

    const DumpedVertexIndexBuffer& index_buffer = static_cast<const DumpedVertexIndexBuffer&>(dumped_resource);

    std::stringstream filename;
    filename << capture_filename_ << "_";
    std::string index_type_name = IndexTypeToStr(index_buffer.index_type);
    filename << "indexBuffer_"
             << "qs_" << dumped_resource.qs_index << "_bcb_" << dumped_resource.bcb_index << "_dc_"
             << dumped_resource.cmd_index << index_type_name << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonDrawCallInfo(
    const VulkanDelegateDumpDrawCallContext& draw_call_info)
{
    const DrawCallsDumpingContext::DrawCallParams* dc_params =
        std::get<const DrawCallsDumpingContext::DrawCallParams*>(draw_call_info.command_parameters);
    GFXRECON_ASSERT(dc_params != nullptr);

    const DumpedResourcesInfo& dumped_resources = dc_params->dumped_resources;

    if (options_.dump_resources_json_per_command)
    {
        std::stringstream filename;
        filename << capture_filename_ << "_";
        filename << "DrawCall_" << dumped_resources.cmd_index << "_qs_" << dumped_resources.qs_index << "_bcb_"
                 << dumped_resources.bcb_index << "_dr.json";

        std::filesystem::path filedirname(options_.dump_resources_output_dir);
        std::filesystem::path filebasename(filename.str());
        std::string           full_filename = (filedirname / filebasename).string();

        dump_json_.Open(full_filename);
        dump_json_.BlockStart();
    }

    auto& current_block = dump_json_.GetCurrentSubEntry();
    auto& drawcall_json_entries =
        !options_.dump_resources_json_per_command ? current_block["drawCallCommands"] : current_block;

    const uint32_t draw_call_json_entry = dump_json_.FetchAndAddDrawCallsEntryIndex();
    auto&          draw_call_entry =
        !options_.dump_resources_json_per_command ? drawcall_json_entries[draw_call_json_entry] : drawcall_json_entries;

    if (options_.using_dump_resources_target)
    {
        draw_call_entry["queueSubmitCallIndex"]   = options_.dump_resources_target.submit_index;
        draw_call_entry["commandBufferCallIndex"] = options_.dump_resources_target.command_index;
        draw_call_entry["drawCallIndex"]          = options_.dump_resources_target.draw_call_index;
    }

    draw_call_entry["drawIndex"]               = dumped_resources.cmd_index;
    draw_call_entry["beginCommandBufferIndex"] = dumped_resources.bcb_index;
    draw_call_entry["queueSubmitIndex"]        = dumped_resources.qs_index;

    // Write draw call params
    auto& dc_params_json_entry           = draw_call_entry["parameters"];
    dc_params_json_entry["drawCallType"] = DrawCallsDumpingContext::DrawCallTypeToStr(dc_params->type);
    switch (dc_params->type)
    {
        case DrawCallsDumpingContext::DrawCallType::kDraw:
        {
            const VkDrawIndirectCommand& draw_call_parameters = dc_params->dc_params_union.draw;

            dc_params_json_entry["vertexCount"]   = draw_call_parameters.vertexCount;
            dc_params_json_entry["instanceCount"] = draw_call_parameters.instanceCount;
            dc_params_json_entry["firstVertex"]   = draw_call_parameters.firstVertex;
            dc_params_json_entry["firstInstance"] = draw_call_parameters.firstInstance;
        }
        break;

        case DrawCallsDumpingContext::DrawCallType::kDrawIndexed:
        {
            const VkDrawIndexedIndirectCommand& draw_call_parameters = dc_params->dc_params_union.draw_indexed;

            dc_params_json_entry["indexCount"]    = draw_call_parameters.indexCount;
            dc_params_json_entry["instanceCount"] = draw_call_parameters.instanceCount;
            dc_params_json_entry["firstIndex"]    = draw_call_parameters.firstIndex;
            dc_params_json_entry["vertexOffset"]  = draw_call_parameters.vertexOffset;
            dc_params_json_entry["firstInstance"] = draw_call_parameters.firstInstance;
        }
        break;

        case DrawCallsDumpingContext::DrawCallType::kDrawIndirect:
        {
            const auto& draw_call_parameters = dc_params->dc_params_union.draw_indirect;

            assert((draw_call_parameters.draw_count && draw_call_parameters.draw_params != nullptr) ||
                   !draw_call_parameters.draw_count);

            dc_params_json_entry["drawCount"] = draw_call_parameters.draw_count;
            auto& indirect_param_entries      = dc_params_json_entry["indirectParams"];
            for (uint32_t di = 0; di < draw_call_parameters.draw_count; ++di)
            {
                indirect_param_entries[di]["vertexCount"]   = draw_call_parameters.draw_params[di].vertexCount;
                indirect_param_entries[di]["instanceCount"] = draw_call_parameters.draw_params[di].instanceCount;
                indirect_param_entries[di]["firstVertex"]   = draw_call_parameters.draw_params[di].firstVertex;
                indirect_param_entries[di]["firstInstance"] = draw_call_parameters.draw_params[di].firstInstance;
            }
        }
        break;

        case DrawCallsDumpingContext::DrawCallType::kDrawIndexedIndirect:
        {
            const auto& draw_call_parameters = dc_params->dc_params_union.draw_indirect;

            assert((draw_call_parameters.draw_count && draw_call_parameters.draw_indexed_params != nullptr) ||
                   !draw_call_parameters.draw_count);

            dc_params_json_entry["drawCount"] = draw_call_parameters.draw_count;
            auto& indirect_param_entries      = dc_params_json_entry["indirectParams"];
            for (uint32_t di = 0; di < draw_call_parameters.draw_count; ++di)
            {
                indirect_param_entries[di]["indexCount"] = draw_call_parameters.draw_indexed_params[di].indexCount;
                indirect_param_entries[di]["instanceCount"] =
                    draw_call_parameters.draw_indexed_params[di].instanceCount;
                indirect_param_entries[di]["firstIndex"]   = draw_call_parameters.draw_indexed_params[di].firstIndex;
                indirect_param_entries[di]["vertexOffset"] = draw_call_parameters.draw_indexed_params[di].vertexOffset;
                indirect_param_entries[di]["firstInstance"] =
                    draw_call_parameters.draw_indexed_params[di].firstInstance;
            }
        }
        break;

        case DrawCallsDumpingContext::DrawCallType::kDrawIndirectCount:
        case DrawCallsDumpingContext::DrawCallType::kDrawIndirectCountKHR:
        case DrawCallsDumpingContext::DrawCallType::kDrawIndirectCountAMD:
        {
            const auto& draw_call_parameters = dc_params->dc_params_union.draw_indirect_count;

            dc_params_json_entry["maxDrawCount"]    = draw_call_parameters.max_draw_count;
            dc_params_json_entry["actualDrawCount"] = draw_call_parameters.actual_draw_count;

            auto& indirect_param_entries = dc_params_json_entry["indirectParams"];
            for (uint32_t di = 0; di < draw_call_parameters.actual_draw_count; ++di)
            {
                indirect_param_entries[di]["vertexCount"]   = draw_call_parameters.draw_params[di].vertexCount;
                indirect_param_entries[di]["instanceCount"] = draw_call_parameters.draw_params[di].instanceCount;
                indirect_param_entries[di]["firstVertex"]   = draw_call_parameters.draw_params[di].firstVertex;
                indirect_param_entries[di]["firstInstance"] = draw_call_parameters.draw_params[di].firstInstance;
            }
        }
        break;

        case DrawCallsDumpingContext::DrawCallType::kDrawIndexedIndirectCount:
        case DrawCallsDumpingContext::DrawCallType::kDrawIndexedIndirectCountKHR:
        case DrawCallsDumpingContext::DrawCallType::kDrawIndexedIndirectCountAMD:
        {
            const auto& draw_call_parameters = dc_params->dc_params_union.draw_indirect_count;

            dc_params_json_entry["maxDrawCount"]    = draw_call_parameters.max_draw_count;
            dc_params_json_entry["actualDrawCount"] = draw_call_parameters.actual_draw_count;

            auto& indirect_param_entries = dc_params_json_entry["indirectParams"];
            for (uint32_t di = 0; di < draw_call_parameters.actual_draw_count; ++di)
            {
                indirect_param_entries[di]["indexCount"] = draw_call_parameters.draw_indexed_params[di].indexCount;
                indirect_param_entries[di]["instanceCount"] =
                    draw_call_parameters.draw_indexed_params[di].instanceCount;
                indirect_param_entries[di]["firstIndex"]   = draw_call_parameters.draw_indexed_params[di].firstIndex;
                indirect_param_entries[di]["vertexOffset"] = draw_call_parameters.draw_indexed_params[di].vertexOffset;
                indirect_param_entries[di]["firstInstance"] =
                    draw_call_parameters.draw_indexed_params[di].firstInstance;
            }
        }
        break;

        default:
            assert(0);
    }

    if (options_.dump_resources_dump_vertex_index_buffer)
    {
        // Emmit vertex bindings info
        if (!dc_params->vertex_input_state.vertex_input_binding_map.empty())
        {
            auto& vertex_input_state_json_entry = draw_call_entry["vertexInputState"];

            auto&    bindings_json_entry = vertex_input_state_json_entry["bindings"];
            uint32_t i                   = 0;
            for (const auto& [binding_index, vb_binding] : dc_params->vertex_input_state.vertex_input_binding_map)
            {
                bindings_json_entry[i]["binding"]   = binding_index;
                bindings_json_entry[i]["stride"]    = vb_binding.stride;
                bindings_json_entry[i]["inputRate"] = util::ToString<VkVertexInputRate>(vb_binding.inputRate);

                if (!options_.dump_resources_dump_unused_vertex_bindings &&
                    !dc_params->vertex_input_state.IsVertexBindingReferenced(binding_index))
                {
                    bindings_json_entry[i]["unused"] = true;
                }

                ++i;
            }
        }

        // Emmit vertex attributes info
        if (!dc_params->vertex_input_state.vertex_input_attribute_map.empty())
        {
            auto&    vertex_input_state_json_entry = draw_call_entry["vertexInputState"];
            auto&    attributes_json_entry         = vertex_input_state_json_entry["attributes"];
            uint32_t i                             = 0;
            for (const auto& vb_attribute : dc_params->vertex_input_state.vertex_input_attribute_map)
            {
                attributes_json_entry[i]["location"] = vb_attribute.first;
                attributes_json_entry[i]["binding"]  = vb_attribute.second.binding;
                attributes_json_entry[i]["format"]   = vb_attribute.second.format;
                attributes_json_entry[i]["offset"]   = vb_attribute.second.offset;
                ++i;
            }
        }
    }

    size_t rt_json_entries = 0;
    for (const auto& rt : dumped_resources.dumped_render_targets)
    {
        const bool is_depth_attachment = rt.location == DEPTH_ATTACHMENT;
        auto&      rt_entries =
            !is_depth_attachment ? draw_call_entry["colorAttachments"] : draw_call_entry["depthAttachment"];
        auto& rt_entry = !is_depth_attachment ? rt_entries[rt_json_entries++] : rt_entries;

        const DumpedImage&     image      = rt.image;
        const VulkanImageInfo* image_info = image.image_info;
        GFXRECON_ASSERT(image_info != nullptr);

        rt_entry["imageId"]   = image_info->capture_id;
        rt_entry["format"]    = util::ToString<VkFormat>(image_info->format);
        rt_entry["imageType"] = util::ToString<VkImageType>(image_info->type);
        rt_entry["levels"]    = image_info->level_count;
        rt_entry["layers"]    = image_info->layer_count;
        if (!is_depth_attachment)
        {
            rt_entry["location"] = rt.location;
        }

        if (image.scaling_failed)
        {
            rt_entry["scaleFailed"] = true;
        }

        std::vector<VkImageAspectFlagBits> aspects;
        GetFormatAspects(image_info->format, aspects);

        size_t subresource_entry = 0;
        for (auto aspect : aspects)
        {
            for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
            {
                for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
                {
                    const auto& dumped_image_sub_resource = image.dumped_subresources[subresource_entry];
                    auto&       subresource_json_entry    = rt_entry["subresources"];
                    dump_json_.InsertImageSubresourceInfo(subresource_json_entry[subresource_entry],
                                                          dumped_image_sub_resource,
                                                          image_info->format,
                                                          options_.dump_resources_dump_separate_alpha,
                                                          image.dumped_raw);
                    ++subresource_entry;

                    // Skip rest of layers
                    if (!options_.dump_resources_dump_all_image_subresources)
                    {
                        break;
                    }
                }

                // Skip rest of mip map levels
                if (!options_.dump_resources_dump_all_image_subresources)
                {
                    break;
                }
            }

            // Skip rest of aspects
            if (!options_.dump_resources_dump_all_image_subresources)
            {
                break;
            }
        }
    }

    if (options_.dump_resources_dump_vertex_index_buffer)
    {
        size_t vertex_buffer_entries = 0;
        for (const auto& vib : dumped_resources.dumped_vertex_index_buffers)
        {
            if (vib.index_type != VK_INDEX_TYPE_NONE_KHR)
            {
                auto& vertex_input_state_json_entry = draw_call_entry["vertexInputState"];
                auto& json_entry                    = vertex_input_state_json_entry["indexBuffer"];

                dump_json_.InsertBufferInfo(json_entry, vib.buffer);
                json_entry["indexType"] = util::ToString<VkIndexType>(vib.index_type);
            }
            else
            {
                auto& vertex_input_state_json_entry = draw_call_entry["vertexInputState"];
                auto& json_entry = vertex_input_state_json_entry["vertexBuffers"][vertex_buffer_entries++];

                dump_json_.InsertBufferInfo(json_entry, vib.buffer);
                json_entry["vertexBufferBinding"] = vib.binding;
            }
        }
    }

    if (options_.dump_resources_dump_immutable_resources)
    {
        std::unordered_map<std::string, uint32_t> per_stage_json_entry_indices;
        for (const auto& desc : dumped_resources.dumped_descriptors)
        {
            std::vector<std::string> shader_stages_names;
            ShaderStageFlagsToStageNames(desc.stages, shader_stages_names);

            if (const DumpedImage* image = std::get_if<DumpedImage>(&desc.dumped_resource))
            {
                for (const std::string& stage_name : shader_stages_names)
                {
                    const VulkanImageInfo* image_info = image->image_info;

                    uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                    auto&     desc_json_entry   = draw_call_entry["descriptors"][stage_name][stage_entry_index++];

                    desc_json_entry["type"]       = util::ToString<VkDescriptorType>(desc.desc_type);
                    desc_json_entry["set"]        = desc.set;
                    desc_json_entry["binding"]    = desc.binding;
                    desc_json_entry["arrayIndex"] = desc.array_index;
                    desc_json_entry["imageId"]    = image_info->capture_id;
                    desc_json_entry["format"]     = util::ToString<VkFormat>(image_info->format);
                    desc_json_entry["imageType"]  = util::ToString<VkImageType>(image_info->type);

                    if (image->scaling_failed)
                    {
                        desc_json_entry["scaleFailed"] = true;
                    }

                    std::vector<VkImageAspectFlagBits> aspects;
                    GetFormatAspects(image_info->format, aspects);

                    size_t subresource_entry = 0;
                    for (auto aspect : aspects)
                    {
                        for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
                        {
                            for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
                            {
                                const auto& dumped_image_sub_resource = image->dumped_subresources[subresource_entry];
                                auto&       subresource_json_entry    = desc_json_entry["subresources"];
                                dump_json_.InsertImageSubresourceInfo(subresource_json_entry[subresource_entry],
                                                                      dumped_image_sub_resource,
                                                                      image_info->format,
                                                                      options_.dump_resources_dump_separate_alpha,
                                                                      image->dumped_raw);
                                ++subresource_entry;

                                // Skip rest of layers
                                if (!options_.dump_resources_dump_all_image_subresources)
                                {
                                    break;
                                }
                            }

                            // Skip rest of mip map levels
                            if (!options_.dump_resources_dump_all_image_subresources)
                            {
                                break;
                            }
                        }

                        // Skip rest of aspects
                        if (!options_.dump_resources_dump_all_image_subresources)
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                GFXRECON_ASSERT(std::get_if<DumpedImage>(&desc.dumped_resource) == nullptr);

                const DumpedBuffer* buffer = std::get_if<DumpedBuffer>(&desc.dumped_resource);

                for (const std::string& stage_name : shader_stages_names)
                {
                    uint32_t& stage_entry_index   = per_stage_json_entry_indices[stage_name];
                    auto&     desc_json_entry     = draw_call_entry["descriptors"][stage_name][stage_entry_index++];
                    desc_json_entry["type"]       = util::ToString<VkDescriptorType>(desc.desc_type);
                    desc_json_entry["set"]        = desc.set;
                    desc_json_entry["binding"]    = desc.binding;
                    desc_json_entry["arrayIndex"] = desc.array_index;
                    dump_json_.InsertBufferInfo(desc_json_entry, *buffer);
                }
            }
        }
    }

    if (options_.dump_resources_json_per_command)
    {
        dump_json_.BlockEnd();
        dump_json_.Close();
    }
}

std::string
DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysImageFilename(const DumpedResourceBase& dumped_resource,
                                                                           DumpedImageFormat     output_image_format,
                                                                           VkImageAspectFlagBits aspect,
                                                                           uint32_t              mip_level,
                                                                           uint32_t              layer,
                                                                           bool                  before_command) const
{
    const DumpedDescriptor& dumped_image_desc = static_cast<const DumpedDescriptor&>(dumped_resource);
    const DumpedImage*      dumped_image      = std::get_if<DumpedImage>(&dumped_image_desc.dumped_resource);
    GFXRECON_ASSERT(dumped_image != nullptr);

    const VulkanImageInfo* image_info = dumped_image->image_info;
    GFXRECON_ASSERT(image_info != nullptr);

    GFXRECON_ASSERT(dumped_image_desc.resource_type == DumpResourcesCommandType::kCompute ||
                    dumped_image_desc.resource_type == DumpResourcesCommandType::kRayTracing);
    const bool is_dispatch = dumped_image_desc.resource_type == DumpResourcesCommandType::kCompute;

    const std::string aspect_str = ImageAspectToStr(aspect);

    std::stringstream filename;
    filename << capture_filename_ << '_';

    if (before_command)
    {
        filename << (is_dispatch ? "dispatch_" : "traceRays_") << dumped_image_desc.cmd_index << "_qs_"
                 << dumped_image_desc.qs_index << "_bcb_" << dumped_image_desc.bcb_index << "_before_"
                 << "set_" << dumped_image_desc.set << "_binding_" << dumped_image_desc.binding << "_index_"
                 << dumped_image_desc.array_index;
        if (output_image_format != KFormatRaw)
        {
            filename << "_" << util::ToString<VkFormat>(image_info->format).c_str();
        }
        filename << "_aspect_" << aspect_str;
    }
    else
    {
        filename << (is_dispatch ? "dispatch_" : "traceRays_") << dumped_image_desc.cmd_index << "_qs_"
                 << dumped_image_desc.qs_index << "_bcb_" << dumped_image_desc.bcb_index << "_"
                 << (options_.dump_resources_before ? "after_" : "") << "set_" << dumped_image_desc.set << "_binding_"
                 << dumped_image_desc.binding << "_index_" << dumped_image_desc.array_index;
        if (output_image_format != KFormatRaw)
        {
            filename << "_" << util::ToString<VkFormat>(image_info->format).c_str();
        }
        filename << "_aspect_" << aspect_str;
    }

    filename << "_mip_" << mip_level << "_layer_" << layer;

    filename << ImageFileExtension(output_image_format);

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string
DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysBufferFilename(const DumpedResourceBase& dumped_resource,
                                                                            bool before_command) const
{
    GFXRECON_UNREFERENCED_PARAMETER(before_command);

    const DumpedDescriptor& dumped_buffer_desc = static_cast<const DumpedDescriptor&>(dumped_resource);
    const DumpedBuffer*     dumped_buffer      = std::get_if<DumpedBuffer>(&dumped_buffer_desc.dumped_resource);
    GFXRECON_ASSERT(dumped_buffer != nullptr);

    GFXRECON_ASSERT(dumped_buffer_desc.resource_type == DumpResourcesCommandType::kCompute ||
                    dumped_buffer_desc.resource_type == DumpResourcesCommandType::kRayTracing);
    const bool is_dispatch = dumped_buffer_desc.resource_type == DumpResourcesCommandType::kCompute;

    std::stringstream filename;

    filename << capture_filename_ << '_';

    if (before_command)
    {
        filename << (is_dispatch ? "dispatch_" : "traceRays_") << dumped_buffer_desc.cmd_index << "_qs_"
                 << dumped_buffer_desc.qs_index << "_bcb_" << dumped_buffer_desc.bcb_index << "_before_"
                 << "set_" << dumped_buffer_desc.set << "_binding_" << dumped_buffer_desc.binding << "_index_"
                 << dumped_buffer_desc.array_index << "_buffer.bin";
    }
    else
    {
        filename << (is_dispatch ? "dispatch_" : "traceRays_") << dumped_buffer_desc.cmd_index << "_qs_"
                 << dumped_buffer_desc.qs_index << "_bcb_" << dumped_buffer_desc.bcb_index << "_"
                 << (options_.dump_resources_before ? "after_" : "") << "set_" << dumped_buffer_desc.set << "_binding_"
                 << dumped_buffer_desc.binding << "_index_" << dumped_buffer_desc.array_index << "_buffer.bin";
    }

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysImageDescriptorFilename(
    const DumpedResourceBase& dumped_resource,
    DumpedImageFormat         output_image_format,
    VkImageAspectFlagBits     aspect,
    uint32_t                  mip_level,
    uint32_t                  layer,
    bool                      before_command) const
{
    GFXRECON_UNREFERENCED_PARAMETER(before_command);

    const DumpedDescriptor& image_desc_info = static_cast<const DumpedDescriptor&>(dumped_resource);

    const DumpedImage* dumped_image = std::get_if<DumpedImage>(&image_desc_info.dumped_resource);
    GFXRECON_ASSERT(dumped_image != nullptr);

    const VulkanImageInfo* image_info = dumped_image->image_info;

    std::string       aspect_str = ImageAspectToStr(aspect);
    std::stringstream base_filename;

    base_filename << capture_filename_ << '_';

    if (output_image_format != KFormatRaw)
    {
        base_filename << "image_" << image_info->capture_id << "_qs_" << image_desc_info.qs_index << "_bcb_"
                      << image_desc_info.bcb_index << "_aspect_" << aspect_str;
    }
    else
    {
        std::string format_name = FormatToStr(image_info->format);
        base_filename << "image_" << image_info->capture_id << "_qs_" << image_desc_info.qs_index << "_bcb_"
                      << image_desc_info.bcb_index << "_" << format_name << "_aspect_" << aspect_str;
    }

    std::stringstream sub_resources_str;
    sub_resources_str << base_filename.str() << "_mip_" << mip_level << "_layer_" << layer;
    sub_resources_str << ImageFileExtension(output_image_format);
    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(sub_resources_str.str());
    return (filedirname / filebasename).string();
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysBufferDescriptorFilename(
    const DumpedResourceBase& dumped_resource, bool before_command) const
{
    GFXRECON_UNREFERENCED_PARAMETER(before_command);

    const DumpedDescriptor& buffer_desc_info = static_cast<const DumpedDescriptor&>(dumped_resource);
    const DumpedBuffer*     dumped_buffer    = std::get_if<DumpedBuffer>(&buffer_desc_info.dumped_resource);
    GFXRECON_ASSERT(dumped_buffer != nullptr);

    const VulkanBufferInfo* buffer_info = dumped_buffer->buffer_info;
    GFXRECON_ASSERT(buffer_info != nullptr);

    std::stringstream filename;
    filename << capture_filename_ << "_buffer_" << buffer_info->capture_id << "_qs_" << buffer_desc_info.qs_index
             << "_bcb_" << buffer_desc_info.bcb_index << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysInlineUniformBufferDescriptorFilename(
    const DumpedResourceBase& dumped_resource, bool before_command) const
{
    GFXRECON_UNREFERENCED_PARAMETER(before_command);

    const DumpedDescriptor& buffer_desc_info = static_cast<const DumpedDescriptor&>(dumped_resource);

    std::stringstream filename;
    filename << capture_filename_ << '_' << "inlineUniformBlock_set_" << buffer_desc_info.set << "_binding_"
             << buffer_desc_info.binding << "_qs_" << buffer_desc_info.qs_index << "_bcb_" << buffer_desc_info.bcb_index
             << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

void DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysDescriptorsJsonInfo(
    nlohmann::ordered_json& dispatch_json_entry, const DumpedResourcesInfo& dumped_resources, bool is_dispatch)
{
    GFXRECON_ASSERT(dumped_resources.dumped_render_targets.empty());
    GFXRECON_ASSERT(dumped_resources.dumped_vertex_index_buffers.empty());

    std::unordered_map<std::string, uint32_t> per_stage_json_entry_indices;
    for (const auto& desc : dumped_resources.dumped_descriptors)
    {
        const VkShaderStageFlags stages = desc.stages;
        std::vector<std::string> shader_stages_names;
        ShaderStageFlagsToStageNames(stages, shader_stages_names);

        if (const DumpedImage* dumped_image = std::get_if<DumpedImage>(&desc.dumped_resource))
        {
            const VulkanImageInfo* img_info = dumped_image->image_info;
            GFXRECON_ASSERT(img_info != nullptr);

            for (const std::string& stage_name : shader_stages_names)
            {
                uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                auto&     entry             = dispatch_json_entry["descriptors"][stage_name][stage_entry_index++];
                entry["type"]               = util::ToString<VkDescriptorType>(desc.desc_type);
                entry["set"]                = desc.set;
                entry["binding"]            = desc.binding;
                entry["arrayIndex"]         = desc.array_index;
                entry["imageId"]            = img_info->capture_id;
                entry["format"]             = util::ToString<VkFormat>(img_info->format);
                entry["imageType"]          = util::ToString<VkImageType>(img_info->type);

                if (dumped_image->scaling_failed)
                {
                    entry["scaleFailed"] = true;
                }

                std::vector<VkImageAspectFlagBits> aspects;
                GetFormatAspects(img_info->format, aspects);
                size_t subresource_entry = 0;
                for (auto aspect : aspects)
                {
                    for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                    {
                        for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                        {
                            const auto& dumped_image_sub_resource =
                                dumped_image->dumped_subresources[subresource_entry];
                            auto& subresource_json_entry = entry["subresources"];
                            dump_json_.InsertImageSubresourceInfo(subresource_json_entry[subresource_entry],
                                                                  dumped_image_sub_resource,
                                                                  img_info->format,
                                                                  options_.dump_resources_dump_separate_alpha,
                                                                  dumped_image->dumped_raw);
                            ++subresource_entry;

                            if (!options_.dump_resources_dump_all_image_subresources)
                            {
                                break;
                            }
                        }

                        if (!options_.dump_resources_dump_all_image_subresources)
                        {
                            break;
                        }
                    }

                    if (!options_.dump_resources_dump_all_image_subresources)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            const DumpedBuffer* dumped_buffer = std::get_if<DumpedBuffer>(&desc.dumped_resource);
            GFXRECON_ASSERT(dumped_buffer != nullptr);

            for (const std::string& stage_name : shader_stages_names)
            {
                uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                auto&     entry             = dispatch_json_entry["descriptors"][stage_name][stage_entry_index++];
                entry["type"]               = util::ToString<VkDescriptorType>(desc.desc_type);
                entry["set"]                = desc.set;
                entry["binding"]            = desc.binding;
                entry["arrayIndex"]         = desc.array_index;
                dump_json_.InsertBufferInfo(entry, *dumped_buffer);
            }
        }
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonDispatchInfo(
    const VulkanDelegateDumpDrawCallContext& draw_call_info)
{
    const DispatchTraceRaysDumpingContext::DispatchParams* disp_params =
        std::get<const DispatchTraceRaysDumpingContext::DispatchParams*>(draw_call_info.command_parameters);

    if (disp_params == nullptr)
    {
        return;
    }

    const DumpedResourcesInfo& dumped_resources = disp_params->dumped_resources;

    if (options_.dump_resources_json_per_command)
    {
        std::stringstream filename;
        filename << "Dispatch_" << dumped_resources.cmd_index << "_qs_" << dumped_resources.qs_index << "_bcb_"
                 << dumped_resources.bcb_index << "_dr.json";
        std::filesystem::path filedirname(options_.dump_resources_output_dir);
        std::filesystem::path filebasename(filename.str());
        std::string           full_filename = (filedirname / filebasename).string();

        dump_json_.Open(full_filename);
        dump_json_.BlockStart();
    }

    auto& current_block = dump_json_.GetCurrentSubEntry();
    auto& dispatch_json_entries =
        !options_.dump_resources_json_per_command ? current_block["dispatchCommands"] : dump_json_.GetData();

    const uint32_t dispatch_json_entry_index = dump_json_.FetchAndAddDispatchEntryIndex();
    auto&          dispatch_json_entry       = !options_.dump_resources_json_per_command
                                                   ? dispatch_json_entries[dispatch_json_entry_index]
                                                   : dump_json_.GetData();

    if (options_.using_dump_resources_target)
    {
        dispatch_json_entry["queueSubmitCallIndex"]   = options_.dump_resources_target.submit_index;
        dispatch_json_entry["commandBufferCallIndex"] = options_.dump_resources_target.command_index;
        dispatch_json_entry["drawCallIndex"]          = options_.dump_resources_target.draw_call_index;
    }

    dispatch_json_entry["dispatchIndex"]           = dumped_resources.cmd_index;
    dispatch_json_entry["beginCommandBufferIndex"] = dumped_resources.bcb_index;
    dispatch_json_entry["queueSubmitIndex"]        = dumped_resources.qs_index;

    auto& params_json_entries           = dispatch_json_entry["parameters"];
    params_json_entries["dispatchType"] = DispatchTraceRaysDumpingContext::DispatchTypeToStr(disp_params->type);
    switch (disp_params->type)
    {
        case DispatchTraceRaysDumpingContext::DispatchTypes::kDispatch:
        {
            const auto& ds_params = disp_params->dispatch_params_union.dispatch;

            params_json_entries["groupCountX"] = ds_params.groupCountX;
            params_json_entries["groupCountY"] = ds_params.groupCountY;
            params_json_entries["groupCountZ"] = ds_params.groupCountZ;
        }
        break;

        case DispatchTraceRaysDumpingContext::DispatchTypes::kDispatchIndirect:
        {
            const auto& ds_params = disp_params->dispatch_params_union.dispatch_indirect;

            params_json_entries["groupCountX"] = ds_params.fetched_dispatch_params.groupCountX;
            params_json_entries["groupCountY"] = ds_params.fetched_dispatch_params.groupCountY;
            params_json_entries["groupCountZ"] = ds_params.fetched_dispatch_params.groupCountZ;
        }
        break;

        case DispatchTraceRaysDumpingContext::DispatchTypes::kDispatchBase:
        {
            const auto& ds_params = disp_params->dispatch_params_union.dispatch_base;

            params_json_entries["baseGroupX"]  = ds_params.baseGroupX;
            params_json_entries["baseGroupY"]  = ds_params.baseGroupY;
            params_json_entries["baseGroupZ"]  = ds_params.baseGroupZ;
            params_json_entries["groupCountX"] = ds_params.groupCountX;
            params_json_entries["groupCountY"] = ds_params.groupCountY;
            params_json_entries["groupCountZ"] = ds_params.groupCountZ;
        }
        break;

        default:
            assert(0);
    }

    GenerateDispatchTraceRaysDescriptorsJsonInfo(dispatch_json_entry, dumped_resources, true);

    if (options_.dump_resources_json_per_command)
    {
        dump_json_.BlockEnd();
        dump_json_.Close();
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonTraceRaysIndex(
    const VulkanDelegateDumpDrawCallContext& draw_call_info)
{
    const DispatchTraceRaysDumpingContext::TraceRaysParams* tr_params =
        std::get<const DispatchTraceRaysDumpingContext::TraceRaysParams*>(draw_call_info.command_parameters);

    if (tr_params == nullptr)
    {
        return;
    }

    const DumpedResourcesInfo& dumped_resources = tr_params->dumped_resources;

    auto& current_block = dump_json_.GetCurrentSubEntry();

    auto& tr_json_entries =
        (!options_.dump_resources_json_per_command) ? current_block["traceRaysCommands"] : dump_json_.GetData();

    if (options_.dump_resources_json_per_command)
    {
        std::stringstream filename;
        filename << "TraceRays_" << dumped_resources.cmd_index << "_qs_" << dumped_resources.qs_index << "_bcb_"
                 << dumped_resources.bcb_index << "_dr.json";
        std::filesystem::path filedirname(options_.dump_resources_output_dir);
        std::filesystem::path filebasename(filename.str());
        std::string           full_filename = (filedirname / filebasename).string();

        dump_json_.Open(full_filename);
        dump_json_.BlockStart();
    }

    const uint32_t trace_rays_json_entry_index = dump_json_.FetchAndAddTraceRaysEntryIndex();
    auto&          tr_entry =
        !options_.dump_resources_json_per_command ? tr_json_entries[trace_rays_json_entry_index] : dump_json_.GetData();

    if (options_.using_dump_resources_target)
    {
        tr_entry["queueSubmitCallIndex"]   = options_.dump_resources_target.submit_index;
        tr_entry["commandBufferCallIndex"] = options_.dump_resources_target.command_index;
        tr_entry["drawCallIndex"]          = options_.dump_resources_target.draw_call_index;
    }

    tr_entry["traceRaysIndex"]          = dumped_resources.cmd_index;
    tr_entry["beginCommandBufferIndex"] = dumped_resources.bcb_index;
    tr_entry["queueSubmitIndex"]        = dumped_resources.qs_index;

    auto& params_json_entries            = tr_entry["parameters"];
    params_json_entries["traceRaysType"] = DispatchTraceRaysDumpingContext::TraceRaysTypeToStr(tr_params->type);

    switch (tr_params->type)
    {
        case DispatchTraceRaysDumpingContext::TraceRaysTypes::kTraceRays:
        {
            const auto& params = tr_params->trace_rays_params_union.trace_rays;

            params_json_entries["width"]  = params.width;
            params_json_entries["height"] = params.height;
            params_json_entries["depth"]  = params.depth;
        }
        break;

        case DispatchTraceRaysDumpingContext::TraceRaysTypes::kTraceRaysIndirect:
        {
            const auto& params = tr_params->trace_rays_params_union.trace_rays_indirect;

            params_json_entries["width"]  = params.trace_rays_params.width;
            params_json_entries["height"] = params.trace_rays_params.height;
            params_json_entries["depth"]  = params.trace_rays_params.depth;
        }
        break;

        case DispatchTraceRaysDumpingContext::TraceRaysTypes::kTraceRaysIndirect2:
        {
            const auto& params = tr_params->trace_rays_params_union.trace_rays_indirect2;

            params_json_entries["width"]  = params.trace_rays_params.width;
            params_json_entries["height"] = params.trace_rays_params.height;
            params_json_entries["depth"]  = params.trace_rays_params.depth;
        }
        break;

        default:
            assert(0);
    }

    GenerateDispatchTraceRaysDescriptorsJsonInfo(tr_entry, dumped_resources, false);

    if (options_.dump_resources_json_per_command)
    {
        dump_json_.BlockEnd();
        dump_json_.Close();
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
