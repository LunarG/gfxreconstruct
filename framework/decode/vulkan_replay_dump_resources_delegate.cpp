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
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "util/buffer_writer.h"

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

void DefaultVulkanDumpResourcesDelegate::DumpDrawCallInfo(const VulkanDumpDrawCallInfo&        draw_call_info,
                                                          const graphics::VulkanInstanceTable* instance_table)
{
    switch (draw_call_info.type)
    {
        case DumpResourceType::kDrawCallInfo:
            GenerateOutputJsonDrawCallInfo(draw_call_info, instance_table);
            break;
        case DumpResourceType::kDispatchInfo:
            GenerateOutputJsonDispatchInfo(draw_call_info, instance_table);
            break;
        case DumpResourceType::kTraceRaysIndex:
            GenerateOutputJsonTraceRaysIndex(draw_call_info, instance_table);
            break;
        default:
            break;
    }
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpResource(const VulkanDumpResourceInfo& resource_info)
{
    switch (resource_info.type)
    {
        case DumpResourceType::kRtv:
        case DumpResourceType::kDsv:
            return DumpRenderTargetImage(resource_info);
            break;
        case DumpResourceType::kImageDescriptor:
            return DumpImageDescriptor(resource_info);
            break;
        case DumpResourceType::kBufferDescriptor:
            return DumpBufferDescriptor(resource_info);
            break;
        case DumpResourceType::kInlineUniformBufferDescriptor:
            return DumpInlineUniformBufferDescriptor(resource_info);
            break;
        case DumpResourceType::kVertex:
            return DumpVertexBuffer(resource_info);
            break;
        case DumpResourceType::kIndex:
            return DumpIndexBuffer(resource_info);
            break;
        case DumpResourceType::kDispatchTraceRaysImage:
            return DumpeDispatchTraceRaysImage(resource_info);
            break;
        case DumpResourceType::kDispatchTraceRaysBuffer:
            return DumpeDispatchTraceRaysBuffer(resource_info);
            break;
        case DumpResourceType::kDispatchTraceRaysImageDescriptor:
            return DumpDispatchTraceRaysImageDescriptor(resource_info);
            break;
        case DumpResourceType::kDispatchTraceRaysBufferDescriptor:
            return DumpDispatchTraceRaysBufferDescriptor(resource_info);
            break;
        case DumpResourceType::kDispatchTraceRaysInlineUniformBufferDescriptor:
            return DumpDispatchTraceRaysInlineUniformBufferDescriptor(resource_info);
            break;
        default:
            break;
    }
    return VK_ERROR_UNKNOWN;
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpRenderTargetImage(const VulkanDumpResourceInfo& resource_info)
{
    const VulkanImageInfo* image_info = resource_info.image_info;

    std::vector<VkImageAspectFlagBits> aspects;
    GetFormatAspects(image_info->format, aspects);

    const size_t total_files = options_.dump_resources_dump_all_image_subresources
                                   ? (aspects.size() * image_info->layer_count * image_info->level_count)
                                   : aspects.size();

    std::vector<std::string> filenames(total_files);
    size_t                   f = 0;
    for (auto aspect : aspects)
    {
        for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
        {
            for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
            {
                filenames[f++] = GenerateRenderTargetImageFilename(resource_info, aspect, mip, layer);

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

    bool     scaling_supported;
    VkResult res = DumpImageToFile(image_info,
                                   resource_info.device_info,
                                   resource_info.device_table,
                                   resource_info.instance_table,
                                   *resource_info.object_info_table,
                                   filenames,
                                   options_.dump_resources_scale,
                                   scaling_supported,
                                   options_.dump_resources_image_format,
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

    // Keep track of images for which scaling failed
    for (size_t i = 0; i < filenames.size(); ++i)
    {
        if (!scaling_supported)
        {
            images_failed_scaling_.insert(filenames[i]);
        }
    }
    return res;
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateRenderTargetImageFilename(
    const VulkanDumpResourceInfo& resource_info, VkImageAspectFlagBits aspect, uint32_t mip_level, uint32_t layer) const
{
    const VulkanImageInfo* image_info     = resource_info.image_info;
    std::string            aspect_str     = ImageAspectToStr(aspect);
    std::string            attachment_str = resource_info.attachment_index != DEPTH_ATTACHMENT
                                                ? "_att_" + std::to_string(resource_info.attachment_index)
                                                : "_depth_att";

    std::stringstream filename;
    filename << capture_filename_ << "_";

    const DumpedImageFormat output_image_format = GetDumpedImageFormat(resource_info.device_info,
                                                                       resource_info.device_table,
                                                                       resource_info.instance_table,
                                                                       *resource_info.object_info_table,
                                                                       image_info->format,
                                                                       image_info->tiling,
                                                                       image_info->type,
                                                                       options_.dump_resources_image_format,
                                                                       options_.dump_resources_dump_raw_images);

    if (output_image_format != KFormatRaw)
    {
        if (options_.dump_resources_before)
        {
            filename << "draw_" << ((!resource_info.before_cmd) ? "after_" : "before_") << resource_info.cmd_index
                     << "_qs_" << resource_info.qs_index << "_bcb_" << resource_info.bcb_index << attachment_str
                     << "_aspect_" << aspect_str;
        }
        else
        {
            filename << "draw_" << resource_info.cmd_index << "_qs_" << resource_info.qs_index << "_bcb_"
                     << resource_info.bcb_index << attachment_str << "_aspect_" << aspect_str;
        }
    }
    else
    {
        if (options_.dump_resources_before)
        {
            filename << "draw_" << ((!resource_info.before_cmd) ? "after_" : "before_") << resource_info.cmd_index
                     << "_qs_" << resource_info.qs_index << "_bcb_" << resource_info.bcb_index << "_"
                     << resource_info.qs_index << "_" << resource_info.bcb_index << attachment_str << "_"
                     << util::ToString<VkFormat>(image_info->format) << "_aspect_" << aspect_str;
        }
        else
        {
            filename << "draw_" << resource_info.cmd_index << "_qs_" << resource_info.qs_index << "_bcb_"
                     << resource_info.bcb_index << attachment_str << "_" << util::ToString<VkFormat>(image_info->format)
                     << "_aspect_" << aspect_str;
        }
    }

    if (options_.dump_resources_dump_all_image_subresources)
    {
        std::stringstream subresource_sting;
        subresource_sting << "_mip_" << mip_level << "_layer_" << layer;
        subresource_sting << ImageFileExtension(output_image_format);

        std::filesystem::path filedirname(options_.dump_resources_output_dir);
        std::filesystem::path filebasename(filename.str() + subresource_sting.str());
        return (filedirname / filebasename).string();
    }
    else
    {
        filename << ImageFileExtension(output_image_format);

        std::filesystem::path filedirname(options_.dump_resources_output_dir);
        std::filesystem::path filebasename(filename.str());
        return (filedirname / filebasename).string();
    }
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpImageDescriptor(const VulkanDumpResourceInfo& resource_info)
{
    const VulkanImageInfo* image_info = resource_info.image_info;

    std::vector<VkImageAspectFlagBits> aspects;
    GetFormatAspects(image_info->format, aspects);

    const size_t total_files = options_.dump_resources_dump_all_image_subresources
                                   ? (aspects.size() * image_info->layer_count * image_info->level_count)
                                   : aspects.size();

    std::vector<std::string> filenames(total_files);

    size_t f = 0;
    for (auto aspect : aspects)
    {
        for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
        {
            for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
            {
                filenames[f++] = GenerateImageDescriptorFilename(resource_info, aspect, mip, layer);

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

    bool     scaling_supported;
    VkResult res = DumpImageToFile(image_info,
                                   resource_info.device_info,
                                   resource_info.device_table,
                                   resource_info.instance_table,
                                   *resource_info.object_info_table,
                                   filenames,
                                   options_.dump_resources_scale,
                                   scaling_supported,
                                   options_.dump_resources_image_format,
                                   options_.dump_resources_dump_all_image_subresources,
                                   options_.dump_resources_dump_raw_images,
                                   options_.dump_resources_dump_separate_alpha,
                                   image_info->intermediate_layout);
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

    // Keep track of images for which scaling failed
    for (size_t i = 0; i < filenames.size(); ++i)
    {
        if (!scaling_supported)
        {
            images_failed_scaling_.insert(filenames[i]);
        }
    }
    return res;
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateImageDescriptorFilename(
    const VulkanDumpResourceInfo& resource_info, VkImageAspectFlagBits aspect, uint32_t mip_level, uint32_t layer) const
{
    const VulkanImageInfo* image_info = resource_info.image_info;
    std::string            aspect_str = ImageAspectToStr(aspect);
    std::stringstream      base_filename;
    base_filename << capture_filename_ << "_";

    const DumpedImageFormat output_image_format = GetDumpedImageFormat(resource_info.device_info,
                                                                       resource_info.device_table,
                                                                       resource_info.instance_table,
                                                                       *resource_info.object_info_table,
                                                                       image_info->format,
                                                                       image_info->tiling,
                                                                       image_info->type,
                                                                       options_.dump_resources_image_format,
                                                                       options_.dump_resources_dump_raw_images);

    if (output_image_format != KFormatRaw)
    {
        base_filename << "image_" << image_info->capture_id << "_qs_" << resource_info.qs_index << "_bcb_"
                      << resource_info.bcb_index << "_rp_" << resource_info.rp << "_aspect_" << aspect_str;
    }
    else
    {
        std::string whole_format_name = util::ToString<VkFormat>(image_info->format);
        std::string format_name(whole_format_name.begin() + 10, whole_format_name.end());

        base_filename << "image_" << image_info->capture_id << "_qs_" << resource_info.qs_index << "_bcb_"
                      << resource_info.bcb_index << "_rp_" << resource_info.rp << "_" << format_name << "_aspect_"
                      << aspect_str;
    }

    if (options_.dump_resources_dump_all_image_subresources)
    {
        std::stringstream sub_resources_str;
        sub_resources_str << base_filename.str() << "_mip_" << mip_level << "_layer_" << layer;
        sub_resources_str << ImageFileExtension(output_image_format);

        std::filesystem::path filedirname(options_.dump_resources_output_dir);
        std::filesystem::path filebasename(sub_resources_str.str());
        return (filedirname / filebasename).string();
    }
    else
    {
        base_filename << ImageFileExtension(output_image_format);
        std::filesystem::path filedirname(options_.dump_resources_output_dir);
        std::filesystem::path filebasename(base_filename.str());
        return (filedirname / filebasename).string();
    }
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpBufferDescriptor(const VulkanDumpResourceInfo& resource_info)
{
    const std::string filename = GenerateBufferDescriptorFilename(resource_info);
    return util::bufferwriter::WriteBuffer(filename, resource_info.data.data(), resource_info.data.size())
               ? VK_SUCCESS
               : VK_ERROR_UNKNOWN;
}

std::string
DefaultVulkanDumpResourcesDelegate::GenerateBufferDescriptorFilename(const VulkanDumpResourceInfo& resource_info) const
{
    std::stringstream filename;

    filename << capture_filename_ << "_"
             << "buffer_" << resource_info.buffer_info->capture_id << "_qs_" << resource_info.qs_index << "_bcb_"
             << resource_info.bcb_index << "_rp_" << resource_info.rp << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult
DefaultVulkanDumpResourcesDelegate::DumpInlineUniformBufferDescriptor(const VulkanDumpResourceInfo& resource_info)
{
    std::string filename = GenerateInlineUniformBufferDescriptorFilename(resource_info);
    return util::bufferwriter::WriteBuffer(filename, resource_info.data.data(), resource_info.data.size())
               ? VK_SUCCESS
               : VK_ERROR_UNKNOWN;
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateInlineUniformBufferDescriptorFilename(
    const VulkanDumpResourceInfo& resource_info) const
{
    std::stringstream filename;
    filename << capture_filename_ << "_"
             << "inlineUniformBlock_set_" << resource_info.set << "_binding_" << resource_info.binding << "_qs_"
             << resource_info.qs_index << "_bcb_" << resource_info.bcb_index << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpVertexBuffer(const VulkanDumpResourceInfo& resource_info)
{
    std::string filename = GenerateVertexBufferFilename(resource_info);
    return util::bufferwriter::WriteBuffer(filename, resource_info.data.data(), resource_info.data.size())
               ? VK_SUCCESS
               : VK_ERROR_UNKNOWN;
}

std::string
DefaultVulkanDumpResourcesDelegate::GenerateVertexBufferFilename(const VulkanDumpResourceInfo& resource_info) const
{
    std::stringstream filename;
    filename << capture_filename_ << "_"
             << "vertexBuffers_"
             << "qs_" << resource_info.qs_index << "_bcb_" << resource_info.bcb_index << "_dc_"
             << resource_info.cmd_index << "_binding_" << resource_info.binding << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpIndexBuffer(const VulkanDumpResourceInfo& resource_info)
{
    std::string filename = GenerateIndexBufferFilename(resource_info);
    return util::bufferwriter::WriteBuffer(filename, resource_info.data.data(), resource_info.data.size())
               ? VK_SUCCESS
               : VK_ERROR_UNKNOWN;
}

std::string
DefaultVulkanDumpResourcesDelegate::GenerateIndexBufferFilename(const VulkanDumpResourceInfo& resource_info) const
{
    std::stringstream filename;
    filename << capture_filename_ << "_";
    std::string index_type_name = IndexTypeToStr(resource_info.index_type);
    filename << "indexBuffer_"
             << "qs_" << resource_info.qs_index << "_bcb_" << resource_info.bcb_index << "_dc_"
             << resource_info.cmd_index << index_type_name << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonDrawCallInfo(
    const VulkanDumpDrawCallInfo& draw_call_info, const graphics::VulkanInstanceTable* instance_table)
{
    if (options_.dump_resources_json_per_command)
    {
        std::stringstream filename;
        filename << capture_filename_ << "_";
        filename << "DrawCall_" << draw_call_info.cmd_index << "_qs_" << draw_call_info.qs_index << "_bcb_"
                 << draw_call_info.bcb_index << "_dr.json";
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

    draw_call_entry["drawIndex"]               = draw_call_info.cmd_index;
    draw_call_entry["beginCommandBufferIndex"] = draw_call_info.bcb_index;
    draw_call_entry["queueSubmitIndex"]        = draw_call_info.qs_index;

    // Write draw call params
    auto& dc_params_json_entry           = draw_call_entry["parameters"];
    dc_params_json_entry["drawCallType"] = DrawCallsDumpingContext::DrawCallTypeToStr(draw_call_info.dc_param->type);
    switch (draw_call_info.dc_param->type)
    {
        case DrawCallsDumpingContext::DrawCallType::kDraw:
        {
            const VkDrawIndirectCommand& dc_params = draw_call_info.dc_param->dc_params_union.draw;

            dc_params_json_entry["vertexCount"]   = dc_params.vertexCount;
            dc_params_json_entry["instanceCount"] = dc_params.instanceCount;
            dc_params_json_entry["firstVertex"]   = dc_params.firstVertex;
            dc_params_json_entry["firstInstance"] = dc_params.firstInstance;
        }
        break;

        case DrawCallsDumpingContext::DrawCallType::kDrawIndexed:
        {
            const VkDrawIndexedIndirectCommand& dc_params = draw_call_info.dc_param->dc_params_union.draw_indexed;

            dc_params_json_entry["indexCount"]    = dc_params.indexCount;
            dc_params_json_entry["instanceCount"] = dc_params.instanceCount;
            dc_params_json_entry["firstIndex"]    = dc_params.firstIndex;
            dc_params_json_entry["vertexOffset"]  = dc_params.vertexOffset;
            dc_params_json_entry["firstInstance"] = dc_params.firstInstance;
        }
        break;

        case DrawCallsDumpingContext::DrawCallType::kDrawIndirect:
        {
            const auto& dc_params = draw_call_info.dc_param->dc_params_union.draw_indirect;

            assert((dc_params.draw_count && dc_params.draw_params != nullptr) || !dc_params.draw_count);

            dc_params_json_entry["drawCount"] = dc_params.draw_count;
            auto& indirect_param_entries      = dc_params_json_entry["indirectParams"];
            for (uint32_t di = 0; di < dc_params.draw_count; ++di)
            {
                indirect_param_entries[di]["vertexCount"]   = dc_params.draw_params[di].vertexCount;
                indirect_param_entries[di]["instanceCount"] = dc_params.draw_params[di].instanceCount;
                indirect_param_entries[di]["firstVertex"]   = dc_params.draw_params[di].firstVertex;
                indirect_param_entries[di]["firstInstance"] = dc_params.draw_params[di].firstInstance;
            }
        }
        break;

        case DrawCallsDumpingContext::DrawCallType::kDrawIndexedIndirect:
        {
            const auto& dc_params = draw_call_info.dc_param->dc_params_union.draw_indirect;

            assert((dc_params.draw_count && dc_params.draw_indexed_params != nullptr) || !dc_params.draw_count);

            dc_params_json_entry["drawCount"] = dc_params.draw_count;
            auto& indirect_param_entries      = dc_params_json_entry["indirectParams"];
            for (uint32_t di = 0; di < dc_params.draw_count; ++di)
            {
                indirect_param_entries[di]["indexCount"]    = dc_params.draw_indexed_params[di].indexCount;
                indirect_param_entries[di]["instanceCount"] = dc_params.draw_indexed_params[di].instanceCount;
                indirect_param_entries[di]["firstIndex"]    = dc_params.draw_indexed_params[di].firstIndex;
                indirect_param_entries[di]["vertexOffset"]  = dc_params.draw_indexed_params[di].vertexOffset;
                indirect_param_entries[di]["firstInstance"] = dc_params.draw_indexed_params[di].firstInstance;
            }
        }
        break;

        case DrawCallsDumpingContext::DrawCallType::kDrawIndirectCount:
        case DrawCallsDumpingContext::DrawCallType::kDrawIndirectCountKHR:
        case DrawCallsDumpingContext::DrawCallType::kDrawIndirectCountAMD:
        {
            const auto& dc_params = draw_call_info.dc_param->dc_params_union.draw_indirect_count;

            dc_params_json_entry["maxDrawCount"]    = dc_params.max_draw_count;
            dc_params_json_entry["actualDrawCount"] = dc_params.actual_draw_count;

            auto& indirect_param_entries = dc_params_json_entry["indirectParams"];
            for (uint32_t di = 0; di < dc_params.actual_draw_count; ++di)
            {
                indirect_param_entries[di]["vertexCount"]   = dc_params.draw_params[di].vertexCount;
                indirect_param_entries[di]["instanceCount"] = dc_params.draw_params[di].instanceCount;
                indirect_param_entries[di]["firstVertex"]   = dc_params.draw_params[di].firstVertex;
                indirect_param_entries[di]["firstInstance"] = dc_params.draw_params[di].firstInstance;
            }
        }
        break;

        case DrawCallsDumpingContext::DrawCallType::kDrawIndexedIndirectCount:
        case DrawCallsDumpingContext::DrawCallType::kDrawIndexedIndirectCountKHR:
        case DrawCallsDumpingContext::DrawCallType::kDrawIndexedIndirectCountAMD:
        {
            const auto& dc_params = draw_call_info.dc_param->dc_params_union.draw_indirect_count;

            dc_params_json_entry["maxDrawCount"]    = dc_params.max_draw_count;
            dc_params_json_entry["actualDrawCount"] = dc_params.actual_draw_count;

            auto& indirect_param_entries = dc_params_json_entry["indirectParams"];
            for (uint32_t di = 0; di < dc_params.actual_draw_count; ++di)
            {
                indirect_param_entries[di]["indexCount"]    = dc_params.draw_indexed_params[di].indexCount;
                indirect_param_entries[di]["instanceCount"] = dc_params.draw_indexed_params[di].instanceCount;
                indirect_param_entries[di]["firstIndex"]    = dc_params.draw_indexed_params[di].firstIndex;
                indirect_param_entries[di]["vertexOffset"]  = dc_params.draw_indexed_params[di].vertexOffset;
                indirect_param_entries[di]["firstInstance"] = dc_params.draw_indexed_params[di].firstInstance;
            }
        }
        break;

        default:
            assert(0);
    }

    VulkanDumpResourceInfo res_info_base{};
    res_info_base = draw_call_info;

    // Write color attachment info
    if (draw_call_info.render_targets != nullptr && !draw_call_info.render_targets->color_att_imgs.empty())
    {
        auto& rt_entries = draw_call_entry["colorAttachments"];

        size_t f = 0;
        for (size_t i = 0; i < draw_call_info.render_targets->color_att_imgs.size(); ++i)
        {
            if (options_.dump_resources_color_attachment_index != kUnspecifiedColorAttachment &&
                static_cast<size_t>(options_.dump_resources_color_attachment_index) != i)
            {
                continue;
            }

            const VulkanImageInfo* image_info = draw_call_info.render_targets->color_att_imgs[i];
            assert(image_info != nullptr);

            if (!IsImageDumpable(instance_table, image_info))
            {
                continue;
            }

            std::vector<VkImageAspectFlagBits> aspects;
            GetFormatAspects(image_info->format, aspects);

            for (auto aspect : aspects)
            {
                for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
                {
                    for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
                    {
                        std::string filenameBefore;
                        if (options_.dump_resources_before)
                        {
                            VulkanDumpResourceInfo res_info_before = res_info_base;
                            res_info_before.type                   = DumpResourceType::kRtv;
                            res_info_before.image_info             = image_info;
                            res_info_before.attachment_index       = i;
                            res_info_before.before_cmd             = true;
                            filenameBefore = GenerateRenderTargetImageFilename(res_info_before, aspect, mip, layer);
                        }

                        VulkanDumpResourceInfo res_info_after = res_info_base;
                        res_info_after.type                   = DumpResourceType::kRtv;
                        res_info_after.image_info             = image_info;
                        res_info_after.attachment_index       = i;
                        res_info_after.before_cmd             = false;
                        std::string filenameAfter =
                            GenerateRenderTargetImageFilename(res_info_after, aspect, mip, layer);

                        const VkExtent3D extent = { std::max(1u, image_info->extent.width >> mip),
                                                    std::max(1u, image_info->extent.height >> mip),
                                                    image_info->extent.depth };

                        dump_json_.InsertImageInfo(rt_entries[f++],
                                                   image_info->format,
                                                   image_info->type,
                                                   image_info->capture_id,
                                                   extent,
                                                   filenameAfter,
                                                   aspect,
                                                   ImageFailedScaling(filenameAfter),
                                                   mip,
                                                   layer,
                                                   options_.dump_resources_dump_separate_alpha,
                                                   options_.dump_resources_before ? &filenameBefore : nullptr);

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
            }
        }
    }

    // Write depth attachment info
    if (options_.dump_resources_dump_depth && draw_call_info.render_targets != nullptr &&
        draw_call_info.render_targets->depth_att_img != nullptr &&
        IsImageDumpable(instance_table, draw_call_info.render_targets->depth_att_img))
    {
        auto& depth_entries = draw_call_entry["depthAttachments"];

        const VulkanImageInfo* image_info = draw_call_info.render_targets->depth_att_img;

        std::vector<VkImageAspectFlagBits> aspects;
        GetFormatAspects(image_info->format, aspects);

        size_t f = 0;
        for (auto aspect : aspects)
        {
            for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
            {
                for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
                {
                    std::string filenameBefore;
                    if (options_.dump_resources_before)
                    {
                        VulkanDumpResourceInfo res_info_before = res_info_base;
                        res_info_before.type                   = DumpResourceType::kDsv;
                        res_info_before.image_info             = image_info;
                        res_info_before.attachment_index       = DEPTH_ATTACHMENT;
                        res_info_before.before_cmd             = true;
                        filenameBefore = GenerateRenderTargetImageFilename(res_info_before, aspect, mip, layer);
                    }

                    VulkanDumpResourceInfo res_info_after = res_info_base;
                    res_info_after.type                   = DumpResourceType::kDsv;
                    res_info_after.image_info             = image_info;
                    res_info_after.attachment_index       = DEPTH_ATTACHMENT;
                    res_info_after.before_cmd             = false;
                    std::string filenameAfter = GenerateRenderTargetImageFilename(res_info_after, aspect, mip, layer);

                    const VkExtent3D extent = { std::max(1u, image_info->extent.width >> mip),
                                                std::max(1u, image_info->extent.height >> mip),
                                                image_info->extent.depth };

                    dump_json_.InsertImageInfo(depth_entries[f++],
                                               image_info->format,
                                               image_info->type,
                                               image_info->capture_id,
                                               extent,
                                               filenameAfter,
                                               aspect,
                                               ImageFailedScaling(filenameAfter),
                                               mip,
                                               layer,
                                               options_.dump_resources_dump_separate_alpha,
                                               options_.dump_resources_before ? &filenameBefore : nullptr);

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
        }
    }

    // Emit in json output the references to vertex and index buffers dumped files
    if (options_.dump_resources_dump_vertex_index_buffer)
    {
        // Emmit vertex bindings info
        if (!draw_call_info.dc_param->vertex_input_state.vertex_input_binding_map.empty())
        {
            auto& vertex_input_state_json_entry = draw_call_entry["vertexInputState"];

            auto&    bindings_json_entry = vertex_input_state_json_entry["bindings"];
            uint32_t i                   = 0;
            for (const auto& vb_binding : draw_call_info.dc_param->vertex_input_state.vertex_input_binding_map)
            {
                bindings_json_entry[i]["binding"]   = vb_binding.first;
                bindings_json_entry[i]["stride"]    = vb_binding.second.stride;
                bindings_json_entry[i]["inputRate"] = util::ToString<VkVertexInputRate>(vb_binding.second.inputRate);
                ++i;
            }
        }

        // Emmit vertex attributes info
        if (!draw_call_info.dc_param->vertex_input_state.vertex_input_attribute_map.empty())
        {
            auto&    vertex_input_state_json_entry = draw_call_entry["vertexInputState"];
            auto&    attributes_json_entry         = vertex_input_state_json_entry["attributes"];
            uint32_t i                             = 0;
            for (const auto& vb_attribute : draw_call_info.dc_param->vertex_input_state.vertex_input_attribute_map)
            {
                attributes_json_entry[i]["location"] = vb_attribute.first;
                attributes_json_entry[i]["binding"]  = vb_attribute.second.binding;
                attributes_json_entry[i]["format"]   = vb_attribute.second.format;
                attributes_json_entry[i]["offset"]   = vb_attribute.second.offset;
                ++i;
            }
        }

        // Emmit bound index buffer info
        if (DrawCallsDumpingContext::IsDrawCallIndexed(draw_call_info.dc_param->type))
        {
            if (draw_call_info.dc_param->json_output_info.index_buffer_info.dumped &&
                draw_call_info.dc_param->referenced_index_buffer.buffer_info != nullptr)
            {
                VulkanDumpResourceInfo res_info         = res_info_base;
                res_info.type                           = DumpResourceType::kIndex;
                res_info.index_type                     = draw_call_info.dc_param->referenced_index_buffer.index_type;
                const std::string index_buffer_filename = GenerateIndexBufferFilename(res_info);

                auto& vertex_input_state_json_entry = draw_call_entry["vertexInputState"];
                auto& json_entry                    = vertex_input_state_json_entry["indexBuffer"];

                json_entry["bufferId"] = draw_call_info.dc_param->referenced_index_buffer.buffer_info->capture_id;
                json_entry["file"]     = index_buffer_filename;
                json_entry["offset"]   = draw_call_info.dc_param->json_output_info.index_buffer_info.offset;
                json_entry["indexType"] =
                    util::ToString<VkIndexType>(draw_call_info.dc_param->referenced_index_buffer.index_type);
            }
        }

        // Emmit bound vertex buffers info
        if (!draw_call_info.dc_param->referenced_vertex_buffers.bound_vertex_buffer_per_binding.empty() &&
            !draw_call_info.dc_param->vertex_input_state.vertex_input_binding_map.empty())
        {
            uint32_t i = 0;
            for (const auto& vb_binding : draw_call_info.dc_param->vertex_input_state.vertex_input_binding_map)
            {
                const auto json_info_entry =
                    draw_call_info.dc_param->json_output_info.vertex_bindings_info.find(vb_binding.first);
                const bool buffer_dumped =
                    json_info_entry != draw_call_info.dc_param->json_output_info.vertex_bindings_info.end();
                if (buffer_dumped)
                {
                    auto& vertex_input_state_json_entry = draw_call_entry["vertexInputState"];
                    auto& json_entry                    = vertex_input_state_json_entry["vertexBuffers"];

                    const auto& vb_binding_buffer =
                        draw_call_info.dc_param->referenced_vertex_buffers.bound_vertex_buffer_per_binding.find(
                            vb_binding.first);
                    assert(vb_binding_buffer !=
                           draw_call_info.dc_param->referenced_vertex_buffers.bound_vertex_buffer_per_binding.end());
                    GFXRECON_ASSERT(vb_binding_buffer->second.buffer_info != nullptr)

                    VulkanDumpResourceInfo res_info = res_info_base;
                    res_info.type                   = DumpResourceType::kVertex;
                    res_info.binding                = vb_binding.first;
                    const std::string vb_filename   = GenerateVertexBufferFilename(res_info);

                    json_entry[i]["bufferId"]            = vb_binding_buffer->second.buffer_info->capture_id;
                    json_entry[i]["vertexBufferBinding"] = vb_binding.first;
                    json_entry[i]["file"]                = vb_filename;
                    json_entry[i]["offset"]              = json_info_entry->second.offset;
                    ++i;
                }
            }
        }
    }

    // Emit in json output the references to dumped immutable descriptors
    if (options_.dump_resources_dump_immutable_resources)
    {
        std::unordered_map<std::string, uint32_t> per_stage_json_entry_indices;
        for (const auto& desc_set : draw_call_info.dc_param->referenced_descriptors)
        {
            const uint32_t desc_set_index = desc_set.first;
            for (const auto& desc : desc_set.second)
            {
                const uint32_t desc_set_binding_index = desc.first;

                std::vector<std::string> shader_stages_names;
                ShaderStageFlagsToStageNames(desc.second.stage_flags, shader_stages_names);
                for (const std::string& stage_name : shader_stages_names)
                {
                    switch (desc.second.desc_type)
                    {
                        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                        {
                            for (const auto& img_desc : desc.second.image_info)
                            {
                                if (img_desc.second.image_view_info == nullptr)
                                {
                                    continue;
                                }

                                const VulkanImageInfo* image_info = draw_call_info.object_info_table->GetVkImageInfo(
                                    img_desc.second.image_view_info->image_id);
                                if (image_info == nullptr || !IsImageDumpable(instance_table, image_info))
                                {
                                    continue;
                                }

                                uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                                auto& desc_json_entry = draw_call_entry["descriptors"][stage_name][stage_entry_index++];
                                desc_json_entry["type"]       = util::ToString<VkDescriptorType>(desc.second.desc_type);
                                desc_json_entry["set"]        = desc_set_index;
                                desc_json_entry["binding"]    = desc_set_binding_index;
                                desc_json_entry["arrayIndex"] = img_desc.first;

                                std::vector<VkImageAspectFlagBits> aspects;
                                GetFormatAspects(image_info->format, aspects);

                                VulkanDumpResourceInfo res_info = res_info_base;
                                res_info.type                   = DumpResourceType::kImageDescriptor;
                                res_info.image_info             = image_info;

                                size_t f = 0;
                                for (auto aspect : aspects)
                                {
                                    for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
                                    {
                                        for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
                                        {
                                            std::string filename =
                                                GenerateImageDescriptorFilename(res_info, aspect, mip, layer);
                                            const VkExtent3D extent = { std::max(1u, image_info->extent.width >> mip),
                                                                        std::max(1u, image_info->extent.height >> mip),
                                                                        image_info->extent.depth };

                                            auto& image_descriptor_json_entry = desc_json_entry["descriptor"];
                                            dump_json_.InsertImageInfo(image_descriptor_json_entry[f++],
                                                                       image_info->format,
                                                                       image_info->type,
                                                                       image_info->capture_id,
                                                                       extent,
                                                                       filename,
                                                                       aspect,
                                                                       ImageFailedScaling(filename),
                                                                       mip,
                                                                       layer,
                                                                       options_.dump_resources_dump_separate_alpha);

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
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        {
                            for (const auto& buf_desc : desc.second.buffer_info)
                            {
                                const VulkanBufferInfo* buf_info = buf_desc.second.buffer_info;
                                if (buf_info != nullptr)
                                {
                                    uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                                    auto&     desc_json_entry =
                                        draw_call_entry["descriptors"][stage_name][stage_entry_index++];
                                    desc_json_entry["type"] = util::ToString<VkDescriptorType>(desc.second.desc_type);
                                    desc_json_entry["set"]  = desc_set_index;
                                    desc_json_entry["binding"]    = desc_set_binding_index;
                                    desc_json_entry["arrayIndex"] = buf_desc.first;

                                    VulkanDumpResourceInfo res_info = res_info_base;
                                    res_info.type                   = DumpResourceType::kBufferDescriptor;
                                    res_info.buffer_info            = buf_info;

                                    const std::string filename = GenerateBufferDescriptorFilename(res_info);
                                    auto&             buffer_descriptor_json_entry = desc_json_entry["descriptor"];
                                    dump_json_.InsertBufferInfo(buffer_descriptor_json_entry, buf_info, filename);
                                }
                            }
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                        {
                            uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                            auto&     desc_json_entry = draw_call_entry["descriptors"][stage_name][stage_entry_index++];
                            desc_json_entry["type"]   = util::ToString<VkDescriptorType>(desc.second.desc_type);
                            desc_json_entry["set"]    = desc_set_index;
                            desc_json_entry["binding"] = desc_set_binding_index;
                            desc_json_entry["size"]    = desc.second.inline_uniform_block.size();

                            VulkanDumpResourceInfo res_info = res_info_base;
                            res_info.type                   = DumpResourceType::kInlineUniformBufferDescriptor;
                            res_info.set                    = desc_set_index;
                            res_info.binding                = desc_set_binding_index;
                            desc_json_entry["file"]         = GenerateInlineUniformBufferDescriptorFilename(res_info);
                        }
                        break;

                        default:
                            break;
                    }
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

VkResult DefaultVulkanDumpResourcesDelegate::DumpeDispatchTraceRaysImage(const VulkanDumpResourceInfo& resource_info)
{
    const VulkanImageInfo* image_info = resource_info.image_info;

    std::vector<VkImageAspectFlagBits> aspects;
    GetFormatAspects(image_info->format, aspects);

    const size_t total_files = options_.dump_resources_dump_all_image_subresources
                                   ? (aspects.size() * image_info->layer_count * image_info->level_count)
                                   : aspects.size();

    std::vector<std::string> filenames(total_files);
    size_t                   f = 0;
    for (auto aspect : aspects)
    {
        for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
        {
            for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
            {
                filenames[f++] = GenerateDispatchTraceRaysImageFilename(resource_info, mip, layer, aspect);

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

    bool     scaling_supported;
    VkResult res = DumpImageToFile(image_info,
                                   resource_info.device_info,
                                   resource_info.device_table,
                                   resource_info.instance_table,
                                   *resource_info.object_info_table,
                                   filenames,
                                   options_.dump_resources_scale,
                                   scaling_supported,
                                   options_.dump_resources_image_format,
                                   false,
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

    // Keep track of images for which scaling failed
    for (size_t i = 0; i < filenames.size(); ++i)
    {
        if (!scaling_supported)
        {
            images_failed_scaling_.insert(filenames[i]);
        }
    }
    return res;
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysImageFilename(
    const VulkanDumpResourceInfo& resource_info, uint32_t mip_level, uint32_t layer, VkImageAspectFlagBits aspect) const
{
    const VulkanImageInfo*  image_info          = resource_info.image_info;
    const DumpedImageFormat output_image_format = GetDumpedImageFormat(resource_info.device_info,
                                                                       resource_info.device_table,
                                                                       resource_info.instance_table,
                                                                       *resource_info.object_info_table,
                                                                       image_info->format,
                                                                       image_info->tiling,
                                                                       image_info->type,
                                                                       options_.dump_resources_image_format,
                                                                       options_.dump_resources_dump_raw_images);

    const std::string aspect_str = ImageAspectToStr(aspect);

    std::stringstream filename;
    filename << capture_filename_ << '_';

    if (resource_info.before_cmd)
    {
        filename << (resource_info.is_dispatch ? "dispatch_" : "traceRays_") << resource_info.cmd_index << "_qs_"
                 << resource_info.qs_index << "_bcb_" << resource_info.bcb_index << "_before_"
                 << "set_" << resource_info.set << "_binding_" << resource_info.binding << "_index_"
                 << resource_info.array_index;
        if (output_image_format != KFormatRaw)
        {
            filename << "_" << util::ToString<VkFormat>(image_info->format).c_str();
        }
        filename << "_aspect_" << aspect_str;
    }
    else
    {
        filename << (resource_info.is_dispatch ? "dispatch_" : "traceRays_") << resource_info.cmd_index << "_qs_"
                 << resource_info.qs_index << "_bcb_" << resource_info.bcb_index << "_"
                 << (options_.dump_resources_before ? "after_" : "") << "set_" << resource_info.set << "_binding_"
                 << resource_info.binding << "_index_" << resource_info.array_index;
        if (output_image_format != KFormatRaw)
        {
            filename << "_" << util::ToString<VkFormat>(image_info->format).c_str();
        }
        filename << "_aspect_" << aspect_str;
    }

    if (options_.dump_resources_dump_all_image_subresources)
    {
        filename << "_mip_" << mip_level << "_layer_" << layer;
    }

    filename << ImageFileExtension(output_image_format);

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpeDispatchTraceRaysBuffer(const VulkanDumpResourceInfo& resource_info)
{
    std::string filename = GenerateDispatchTraceRaysBufferFilename(resource_info);
    return util::bufferwriter::WriteBuffer(filename, resource_info.data.data(), resource_info.data.size())
               ? VK_SUCCESS
               : VK_ERROR_UNKNOWN;
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysBufferFilename(
    const VulkanDumpResourceInfo& resource_info) const
{
    std::stringstream filename;

    filename << capture_filename_ << '_';

    if (resource_info.before_cmd)
    {
        filename << (resource_info.is_dispatch ? "dispatch_" : "traceRays_") << resource_info.cmd_index << "_qs_"
                 << resource_info.qs_index << "_bcb_" << resource_info.bcb_index << "_before_"
                 << "set_" << resource_info.set << "_binding_" << resource_info.binding << "_index_"
                 << resource_info.array_index << "_buffer.bin";
    }
    else
    {
        filename << (resource_info.is_dispatch ? "dispatch_" : "traceRays_") << resource_info.cmd_index << "_qs_"
                 << resource_info.qs_index << "_bcb_" << resource_info.bcb_index << "_"
                 << (options_.dump_resources_before ? "after_" : "") << "set_" << resource_info.set << "_binding_"
                 << resource_info.binding << "_index_" << resource_info.array_index << "_buffer.bin";
    }

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult
DefaultVulkanDumpResourcesDelegate::DumpDispatchTraceRaysImageDescriptor(const VulkanDumpResourceInfo& resource_info)
{
    const VulkanImageInfo* image_info = resource_info.image_info;

    std::vector<VkImageAspectFlagBits> aspects;
    GetFormatAspects(image_info->format, aspects);

    const size_t total_files = options_.dump_resources_dump_all_image_subresources
                                   ? (aspects.size() * image_info->layer_count * image_info->level_count)
                                   : aspects.size();

    std::vector<std::string> filenames(total_files);

    size_t f = 0;
    for (auto aspect : aspects)
    {
        for (uint32_t mip = 0; mip < image_info->level_count; ++mip)
        {
            for (uint32_t layer = 0; layer < image_info->layer_count; ++layer)
            {
                filenames[f++] = GenerateDispatchTraceRaysImageDescriptorFilename(resource_info, mip, layer, aspect);

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

    bool     scaling_supported;
    VkResult res = DumpImageToFile(image_info,
                                   resource_info.device_info,
                                   resource_info.device_table,
                                   resource_info.instance_table,
                                   *resource_info.object_info_table,
                                   filenames,
                                   options_.dump_resources_scale,
                                   scaling_supported,
                                   options_.dump_resources_image_format,
                                   options_.dump_resources_dump_all_image_subresources,
                                   options_.dump_resources_dump_raw_images,
                                   options_.dump_resources_dump_separate_alpha);
    if (res != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Dumping image failed (%s)", util::ToString<VkResult>(res).c_str())
        return res;
    }

    // Keep track of images for which scaling failed
    for (size_t i = 0; i < filenames.size(); ++i)
    {
        if (scaling_supported)
        {
            images_failed_scaling_.insert(filenames[i]);
        }
    }
    return res;
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysImageDescriptorFilename(
    const VulkanDumpResourceInfo& resource_info, uint32_t mip_level, uint32_t layer, VkImageAspectFlagBits aspect) const
{
    const VulkanImageInfo* image_info = resource_info.image_info;
    std::string            aspect_str = ImageAspectToStr(aspect);
    std::stringstream      base_filename;

    base_filename << capture_filename_ << '_';

    const DumpedImageFormat output_image_format = GetDumpedImageFormat(resource_info.device_info,
                                                                       resource_info.device_table,
                                                                       resource_info.instance_table,
                                                                       *resource_info.object_info_table,
                                                                       image_info->format,
                                                                       image_info->tiling,
                                                                       image_info->type,
                                                                       options_.dump_resources_image_format,
                                                                       options_.dump_resources_dump_raw_images);

    if (output_image_format != KFormatRaw)
    {
        base_filename << "image_" << image_info->capture_id << "_qs_" << resource_info.qs_index << "_bcb_"
                      << resource_info.bcb_index << "_aspect_" << aspect_str;
    }
    else
    {
        std::string format_name = FormatToStr(image_info->format);
        base_filename << "image_" << image_info->capture_id << "_qs_" << resource_info.qs_index << "_bcb_"
                      << resource_info.bcb_index << "_" << format_name << "_aspect_" << aspect_str;
    }

    if (options_.dump_resources_dump_all_image_subresources)
    {
        std::stringstream sub_resources_str;
        sub_resources_str << base_filename.str() << "_mip_" << mip_level << "_layer_" << layer;
        sub_resources_str << ImageFileExtension(output_image_format);
        std::filesystem::path filedirname(options_.dump_resources_output_dir);
        std::filesystem::path filebasename(sub_resources_str.str());
        return (filedirname / filebasename).string();
    }
    else
    {
        base_filename << ImageFileExtension(output_image_format);
        std::filesystem::path filedirname(options_.dump_resources_output_dir);
        std::filesystem::path filebasename(base_filename.str());
        return (filedirname / filebasename).string();
    }
}

VkResult
DefaultVulkanDumpResourcesDelegate::DumpDispatchTraceRaysBufferDescriptor(const VulkanDumpResourceInfo& resource_info)
{
    const std::string filename = GenerateDispatchTraceRaysBufferDescriptorFilename(resource_info);
    return util::bufferwriter::WriteBuffer(filename, resource_info.data.data(), resource_info.data.size())
               ? VK_SUCCESS
               : VK_ERROR_UNKNOWN;
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysBufferDescriptorFilename(
    const VulkanDumpResourceInfo& resource_info) const
{
    std::stringstream filename;

    filename << capture_filename_ << "_buffer_" << resource_info.buffer_info->capture_id << "_qs_"
             << resource_info.qs_index << "_bcb_" << resource_info.bcb_index << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

VkResult DefaultVulkanDumpResourcesDelegate::DumpDispatchTraceRaysInlineUniformBufferDescriptor(
    const VulkanDumpResourceInfo& resource_info)
{
    std::string filename = GenerateDispatchTraceRaysInlineUniformBufferDescriptorFilename(resource_info);
    return util::bufferwriter::WriteBuffer(filename, resource_info.data.data(), resource_info.data.size())
               ? VK_SUCCESS
               : VK_ERROR_UNKNOWN;
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysInlineUniformBufferDescriptorFilename(
    const VulkanDumpResourceInfo& resource_info) const
{
    std::stringstream filename;
    filename << capture_filename_ << '_' << "inlineUniformBlock_set_" << resource_info.set << "_binding_"
             << resource_info.binding << "_qs_" << resource_info.qs_index << "_bcb_" << resource_info.bcb_index
             << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonDispatchInfo(
    const VulkanDumpDrawCallInfo& draw_call_info, const graphics::VulkanInstanceTable* instance_table)
{
    if (draw_call_info.disp_param == nullptr)
    {
        return;
    }

    if (options_.dump_resources_json_per_command)
    {
        std::stringstream filename;
        filename << "Dispatch_" << draw_call_info.cmd_index << "_qs_" << draw_call_info.qs_index << "_bcb_"
                 << draw_call_info.bcb_index << "_dr.json";
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

    dispatch_json_entry["dispatchIndex"]           = draw_call_info.cmd_index;
    dispatch_json_entry["beginCommandBufferIndex"] = draw_call_info.bcb_index;
    dispatch_json_entry["queueSubmitIndex"]        = draw_call_info.qs_index;

    auto& params_json_entries = dispatch_json_entry["parameters"];
    params_json_entries["dispatchType"] =
        DispatchTraceRaysDumpingContext::DispatchTypeToStr(draw_call_info.disp_param->type);
    switch (draw_call_info.disp_param->type)
    {
        case DispatchTraceRaysDumpingContext::DispatchTypes::kDispatch:
        {
            const auto& ds_params = draw_call_info.disp_param->dispatch_params_union.dispatch;

            params_json_entries["groupCountX"] = ds_params.groupCountX;
            params_json_entries["groupCountY"] = ds_params.groupCountY;
            params_json_entries["groupCountZ"] = ds_params.groupCountZ;
        }
        break;

        case DispatchTraceRaysDumpingContext::DispatchTypes::kDispatchIndirect:
        {
            const auto& ds_params = draw_call_info.disp_param->dispatch_params_union.dispatch_indirect;

            assert(ds_params.dispatch_params != nullptr);
            params_json_entries["groupCountX"] = ds_params.dispatch_params->groupCountX;
            params_json_entries["groupCountY"] = ds_params.dispatch_params->groupCountY;
            params_json_entries["groupCountZ"] = ds_params.dispatch_params->groupCountZ;
        }
        break;

        case DispatchTraceRaysDumpingContext::DispatchTypes::kDispatchBase:
        {
            const auto& ds_params = draw_call_info.disp_param->dispatch_params_union.dispatch_base;

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

    auto& outputs_json_entries = dispatch_json_entry["outputs"];

    VulkanDumpResourceInfo res_info_base{};
    res_info_base = draw_call_info;

    if (options_.dump_resources_before)
    {
        const auto& mutable_resource_entry_before = draw_call_info.disp_param->mutable_resources_clones_before;
        if (!mutable_resource_entry_before.images.empty())
        {
            auto&    before_command_output_image_entries = outputs_json_entries["before"]["images"];
            uint32_t output_image_index                  = 0;

            for (const auto& image : mutable_resource_entry_before.images)
            {
                const uint32_t           desc_set    = image.desc_set;
                const uint32_t           binding     = image.desc_binding;
                const uint32_t           array_index = image.array_index;
                const VkShaderStageFlags stages      = image.stages;
                const VulkanImageInfo*   img_info    = image.original_image;
                assert(img_info != nullptr);

                auto& image_json_entry         = before_command_output_image_entries[output_image_index++];
                image_json_entry["type"]       = util::ToString<VkDescriptorType>(image.desc_type);
                image_json_entry["set"]        = desc_set;
                image_json_entry["binding"]    = binding;
                image_json_entry["arrayIndex"] = array_index;
                auto& image_json_entry_desc    = image_json_entry["images"];

                std::vector<VkImageAspectFlagBits> aspects;
                GetFormatAspects(img_info->format, aspects);

                size_t f = 0;
                for (auto aspect : aspects)
                {
                    for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                    {
                        for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                        {
                            VulkanDumpResourceInfo res_info = res_info_base;
                            res_info.type                   = DumpResourceType::kDispatchTraceRaysImage;
                            res_info.is_dispatch            = true;
                            res_info.before_cmd             = true;
                            res_info.image_info             = img_info;
                            res_info.set                    = desc_set;
                            res_info.binding                = binding;
                            res_info.array_index            = array_index;
                            res_info.stages                 = stages;

                            std::string filename = GenerateDispatchTraceRaysImageFilename(res_info, mip, layer, aspect);

                            const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                        std::max(1u, img_info->extent.height >> mip),
                                                        img_info->extent.depth };

                            dump_json_.InsertImageInfo(image_json_entry_desc[f++],
                                                       img_info->format,
                                                       img_info->type,
                                                       img_info->capture_id,
                                                       extent,
                                                       filename,
                                                       aspect,
                                                       ImageFailedScaling(filename),
                                                       mip,
                                                       layer,
                                                       options_.dump_resources_dump_separate_alpha);

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
        }

        if (!mutable_resource_entry_before.buffers.empty())
        {
            auto&    before_command_output_buffer_entries = outputs_json_entries["before"]["buffers"];
            uint32_t output_buffer_index                  = 0;

            for (const auto& buffer : mutable_resource_entry_before.buffers)
            {
                const uint32_t           desc_set    = buffer.desc_set;
                const uint32_t           binding     = buffer.desc_binding;
                const uint32_t           array_index = buffer.array_index;
                const VkShaderStageFlags stages      = buffer.stages;
                const VulkanBufferInfo*  buffer_info = buffer.original_buffer;
                assert(buffer_info != nullptr);

                VulkanDumpResourceInfo res_info = res_info_base;
                res_info.type                   = DumpResourceType::kDispatchTraceRaysBuffer;
                res_info.is_dispatch            = true;
                res_info.before_cmd             = true;
                res_info.set                    = desc_set;
                res_info.binding                = binding;
                res_info.array_index            = array_index;
                res_info.stages                 = stages;

                std::string filename = GenerateDispatchTraceRaysBufferFilename(res_info);

                auto& buffer_json_entry         = before_command_output_buffer_entries[output_buffer_index++];
                buffer_json_entry["type"]       = util::ToString<VkDescriptorType>(buffer.desc_type);
                buffer_json_entry["set"]        = desc_set;
                buffer_json_entry["binding"]    = binding;
                buffer_json_entry["arrayIndex"] = array_index;
                dump_json_.InsertBufferInfo(buffer_json_entry, buffer_info, filename);
            }
        }
    }

    const auto& mutable_resource_entry = draw_call_info.disp_param->mutable_resources_clones;
    if (!mutable_resource_entry.images.empty())
    {
        auto& outputs_json_entries_after =
            options_.dump_resources_before ? outputs_json_entries["after"] : outputs_json_entries;
        auto& image_outputs_json_entries = outputs_json_entries_after["images"];

        uint32_t mutable_images_count = 0;
        for (const auto& image : mutable_resource_entry.images)
        {
            const uint32_t           desc_set    = image.desc_set;
            const uint32_t           binding     = image.desc_binding;
            const uint32_t           array_index = image.array_index;
            const VkShaderStageFlags stages      = image.stages;
            const VulkanImageInfo*   img_info    = image.original_image;
            assert(img_info != nullptr);

            auto& image_json_entry         = image_outputs_json_entries[mutable_images_count++];
            image_json_entry["type"]       = util::ToString<VkDescriptorType>(image.desc_type);
            image_json_entry["set"]        = desc_set;
            image_json_entry["binding"]    = binding;
            image_json_entry["arrayIndex"] = array_index;
            auto& image_json_entry_desc    = image_json_entry["images"];

            std::vector<VkImageAspectFlagBits> aspects;
            GetFormatAspects(img_info->format, aspects);

            size_t f = 0;
            for (auto aspect : aspects)
            {
                for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                {
                    for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                    {
                        VulkanDumpResourceInfo res_info = res_info_base;
                        res_info.type                   = DumpResourceType::kDispatchTraceRaysImage;
                        res_info.is_dispatch            = true;
                        res_info.before_cmd             = false;
                        res_info.image_info             = img_info;
                        res_info.set                    = desc_set;
                        res_info.binding                = binding;
                        res_info.array_index            = array_index;
                        res_info.stages                 = stages;

                        std::string filename = GenerateDispatchTraceRaysImageFilename(res_info, mip, layer, aspect);

                        const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                    std::max(1u, img_info->extent.height >> mip),
                                                    img_info->extent.depth };

                        dump_json_.InsertImageInfo(image_json_entry_desc[f++],
                                                   img_info->format,
                                                   img_info->type,
                                                   img_info->capture_id,
                                                   extent,
                                                   filename,
                                                   aspect,
                                                   ImageFailedScaling(filename),
                                                   mip,
                                                   layer,
                                                   options_.dump_resources_dump_separate_alpha);

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
    }

    if (!mutable_resource_entry.buffers.empty())
    {
        auto& outputs_json_entries_after =
            options_.dump_resources_before ? outputs_json_entries["after"] : outputs_json_entries;
        auto& buffer_outputs_json_entries = outputs_json_entries_after["buffers"];

        uint32_t mutable_buffers_count = 0;
        for (const auto& buffer : mutable_resource_entry.buffers)
        {
            const uint32_t           desc_set    = buffer.desc_set;
            const uint32_t           binding     = buffer.desc_binding;
            const uint32_t           array_index = buffer.array_index;
            const VkShaderStageFlags stages      = buffer.stages;
            const VulkanBufferInfo*  buffer_info = buffer.original_buffer;
            assert(buffer_info != nullptr);

            VulkanDumpResourceInfo res_info = res_info_base;
            res_info.type                   = DumpResourceType::kDispatchTraceRaysBuffer;
            res_info.is_dispatch            = true;
            res_info.before_cmd             = false;
            res_info.set                    = desc_set;
            res_info.binding                = binding;
            res_info.array_index            = array_index;
            res_info.stages                 = stages;

            std::string filename = GenerateDispatchTraceRaysBufferFilename(res_info);

            auto& buffer_json_entry         = buffer_outputs_json_entries[mutable_buffers_count++];
            buffer_json_entry["type"]       = util::ToString<VkDescriptorType>(buffer.desc_type);
            buffer_json_entry["set"]        = desc_set;
            buffer_json_entry["binding"]    = binding;
            buffer_json_entry["arrayIndex"] = array_index;
            dump_json_.InsertBufferInfo(buffer_json_entry, buffer_info, filename);
        }
    }

    if (options_.dump_resources_dump_immutable_resources)
    {
        uint32_t descriptor_entries_count = 0;
        for (const auto& desc_set : draw_call_info.disp_param->referenced_descriptors)
        {
            const uint32_t desc_set_index = desc_set.first;
            for (const auto& desc_binding : desc_set.second)
            {
                const uint32_t desc_binding_index = desc_binding.first;
                switch (desc_binding.second.desc_type)
                {
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        for (const auto& img_desc : desc_binding.second.image_info)
                        {
                            if (img_desc.second.image_view_info == nullptr)
                            {
                                continue;
                            }

                            const VulkanImageInfo* img_info = draw_call_info.object_info_table->GetVkImageInfo(
                                img_desc.second.image_view_info->image_id);
                            if (img_info == nullptr)
                            {
                                continue;
                            }

                            auto& entry = dispatch_json_entry["descriptors"][descriptor_entries_count++];

                            entry["type"]       = util::ToString<VkDescriptorType>(desc_binding.second.desc_type);
                            entry["set"]        = desc_set_index;
                            entry["binding"]    = desc_binding_index;
                            entry["arrayIndex"] = img_desc.first;

                            std::vector<VkImageAspectFlagBits> aspects;
                            GetFormatAspects(img_info->format, aspects);

                            size_t f = 0;
                            for (auto aspect : aspects)
                            {
                                for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                                {
                                    for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                                    {
                                        VulkanDumpResourceInfo res_info = res_info_base;
                                        res_info.type       = DumpResourceType::kDispatchTraceRaysImageDescriptor;
                                        res_info.image_info = img_info;

                                        std::string filename = GenerateDispatchTraceRaysImageDescriptorFilename(
                                            res_info, mip, layer, aspect);

                                        auto&            image_descriptor_json_entry = entry["descriptor"];
                                        const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                                    std::max(1u, img_info->extent.height >> mip),
                                                                    img_info->extent.depth };

                                        dump_json_.InsertImageInfo(image_descriptor_json_entry[f++],
                                                                   img_info->format,
                                                                   img_info->type,
                                                                   img_info->capture_id,
                                                                   extent,
                                                                   filename,
                                                                   aspect,
                                                                   ImageFailedScaling(filename),
                                                                   mip,
                                                                   layer,
                                                                   options_.dump_resources_dump_separate_alpha);

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
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    {
                        for (const auto& buf_desc : desc_binding.second.buffer_info)
                        {
                            if (buf_desc.second.buffer_info != nullptr)
                            {
                                auto& entry = dispatch_json_entry["descriptors"][descriptor_entries_count++];

                                entry["type"]       = util::ToString<VkDescriptorType>(desc_binding.second.desc_type);
                                entry["set"]        = desc_set_index;
                                entry["binding"]    = desc_binding_index;
                                entry["arrayIndex"] = buf_desc.first;

                                auto& buffer_descriptor_json_entry = entry["descriptor"];

                                VulkanDumpResourceInfo res_info = res_info_base;
                                res_info.type                   = DumpResourceType::kDispatchTraceRaysBufferDescriptor;
                                res_info.buffer_info            = buf_desc.second.buffer_info;

                                const std::string filename =
                                    GenerateDispatchTraceRaysBufferDescriptorFilename(res_info);
                                dump_json_.InsertBufferInfo(
                                    buffer_descriptor_json_entry, buf_desc.second.buffer_info, filename);
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                        break;

                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        auto& entry = dispatch_json_entry["descriptors"][descriptor_entries_count++];

                        entry["type"]    = util::ToString<VkDescriptorType>(desc_binding.second.desc_type);
                        entry["set"]     = desc_set_index;
                        entry["binding"] = desc_binding_index;
                        entry["size"]    = desc_binding.second.inline_uniform_block.size();

                        VulkanDumpResourceInfo res_info = res_info_base;
                        res_info.type    = DumpResourceType::kDispatchTraceRaysInlineUniformBufferDescriptor;
                        res_info.set     = desc_set_index;
                        res_info.binding = desc_binding_index;

                        const std::string filename =
                            GenerateDispatchTraceRaysInlineUniformBufferDescriptorFilename(res_info);
                        entry["file"] = filename;
                    }
                    break;

                    default:
                        GFXRECON_LOG_WARNING_ONCE(
                            "%s(): Descriptor type (%s) not handled",
                            __func__,
                            util::ToString<VkDescriptorType>(desc_binding.second.desc_type).c_str());
                        break;
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

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonTraceRaysIndex(
    const VulkanDumpDrawCallInfo& draw_call_info, const graphics::VulkanInstanceTable* instance_table)
{
    if (draw_call_info.tr_param == nullptr)
    {
        return;
    }
    auto& current_block = dump_json_.GetCurrentSubEntry();

    auto& tr_json_entries =
        (!options_.dump_resources_json_per_command) ? current_block["traceRaysCommands"] : dump_json_.GetData();

    if (options_.dump_resources_json_per_command)
    {
        std::stringstream filename;
        filename << "TraceRays_" << draw_call_info.cmd_index << "_qs_" << draw_call_info.qs_index << "_bcb_"
                 << draw_call_info.bcb_index << "_dr.json";
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

    tr_entry["traceRaysIndex"]          = draw_call_info.cmd_index;
    tr_entry["beginCommandBufferIndex"] = draw_call_info.bcb_index;
    tr_entry["queueSubmitIndex"]        = draw_call_info.qs_index;

    auto& params_json_entries = tr_entry["parameters"];
    params_json_entries["traceRaysType"] =
        DispatchTraceRaysDumpingContext::TraceRaysTypeToStr(draw_call_info.tr_param->type);

    switch (draw_call_info.tr_param->type)
    {
        case DispatchTraceRaysDumpingContext::TraceRaysTypes::kTraceRays:
        {
            const auto& params = draw_call_info.tr_param->trace_rays_params_union.trace_rays;

            params_json_entries["width"]  = params.width;
            params_json_entries["height"] = params.height;
            params_json_entries["depth"]  = params.depth;
        }
        break;

        case DispatchTraceRaysDumpingContext::TraceRaysTypes::kTraceRaysIndirect:
        {
            const auto& params = draw_call_info.tr_param->trace_rays_params_union.trace_rays_indirect;

            params_json_entries["width"]  = params.trace_rays_params.width;
            params_json_entries["height"] = params.trace_rays_params.height;
            params_json_entries["depth"]  = params.trace_rays_params.depth;
        }
        break;

        case DispatchTraceRaysDumpingContext::TraceRaysTypes::kTraceRaysIndirect2:
        {
            const auto& params = draw_call_info.tr_param->trace_rays_params_union.trace_rays_indirect2;

            params_json_entries["width"]  = params.trace_rays_params.width;
            params_json_entries["height"] = params.trace_rays_params.height;
            params_json_entries["depth"]  = params.trace_rays_params.depth;
        }
        break;

        default:
            assert(0);
    }

    auto& outputs_json_entries = tr_entry["outputs"];

    VulkanDumpResourceInfo res_info_base{};
    res_info_base = draw_call_info;

    if (options_.dump_resources_before)
    {
        const auto& mutable_resource_entry_before = draw_call_info.tr_param->mutable_resources_clones_before;
        if (!mutable_resource_entry_before.images.empty())
        {
            auto&    before_command_output_image_entries = outputs_json_entries["before"]["images"];
            uint32_t output_image_index                  = 0;

            for (const auto& image : mutable_resource_entry_before.images)
            {
                const uint32_t           desc_set    = image.desc_set;
                const uint32_t           binding     = image.desc_binding;
                const uint32_t           array_index = image.array_index;
                const VkShaderStageFlags stages      = image.stages;
                const VulkanImageInfo*   img_info    = image.original_image;
                assert(img_info != nullptr);

                std::vector<VkImageAspectFlagBits> aspects;
                GetFormatAspects(img_info->format, aspects);

                auto& image_json_entry         = before_command_output_image_entries[output_image_index++];
                image_json_entry["type"]       = util::ToString<VkDescriptorType>(image.desc_type);
                image_json_entry["stages"]     = ShaderStageFlagsToString(stages);
                image_json_entry["set"]        = desc_set;
                image_json_entry["binding"]    = binding;
                image_json_entry["arrayIndex"] = array_index;
                auto& image_json_entry_desc    = image_json_entry["images"];

                size_t f = 0;
                for (auto aspect : aspects)
                {
                    for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                    {
                        for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                        {
                            VulkanDumpResourceInfo res_info = res_info_base;
                            res_info.type                   = DumpResourceType::kDispatchTraceRaysImage;
                            res_info.is_dispatch            = false;
                            res_info.before_cmd             = true;
                            res_info.image_info             = img_info;
                            res_info.set                    = desc_set;
                            res_info.binding                = binding;
                            res_info.array_index            = array_index;
                            res_info.stages                 = stages;

                            std::string filename = GenerateDispatchTraceRaysImageFilename(res_info, mip, layer, aspect);

                            const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                        std::max(1u, img_info->extent.height >> mip),
                                                        img_info->extent.depth };

                            dump_json_.InsertImageInfo(image_json_entry_desc[f++],
                                                       img_info->format,
                                                       img_info->type,
                                                       img_info->capture_id,
                                                       extent,
                                                       filename,
                                                       aspect,
                                                       ImageFailedScaling(filename),
                                                       mip,
                                                       layer,
                                                       options_.dump_resources_dump_separate_alpha);

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
        }

        if (!mutable_resource_entry_before.buffers.empty())
        {
            auto&    before_command_output_buffer_entries = outputs_json_entries["before"]["buffers"];
            uint32_t output_buffer_index                  = 0;

            for (const auto& buffer : mutable_resource_entry_before.buffers)
            {
                const uint32_t           desc_set    = buffer.desc_set;
                const uint32_t           binding     = buffer.desc_binding;
                const uint32_t           array_index = buffer.array_index;
                const VkShaderStageFlags stages      = buffer.stages;
                const VulkanBufferInfo*  buffer_info = buffer.original_buffer;
                assert(buffer_info != nullptr);

                VulkanDumpResourceInfo res_info = res_info_base;
                res_info.type                   = DumpResourceType::kDispatchTraceRaysBuffer;
                res_info.is_dispatch            = false;
                res_info.before_cmd             = true;
                res_info.set                    = desc_set;
                res_info.binding                = binding;
                res_info.array_index            = array_index;
                res_info.stages                 = stages;

                std::string filename = GenerateDispatchTraceRaysBufferFilename(res_info);

                auto& buffer_json_entry         = before_command_output_buffer_entries[output_buffer_index++];
                buffer_json_entry["type"]       = util::ToString<VkDescriptorType>(buffer.desc_type);
                buffer_json_entry["stages"]     = ShaderStageFlagsToString(stages);
                buffer_json_entry["set"]        = desc_set;
                buffer_json_entry["binding"]    = binding;
                buffer_json_entry["arrayIndex"] = array_index;
                dump_json_.InsertBufferInfo(buffer_json_entry, buffer_info, filename);
            }
        }
    }

    const auto& mutable_resource_entry = draw_call_info.tr_param->mutable_resources_clones;
    auto&       outputs_json_entries_after =
        options_.dump_resources_before ? outputs_json_entries["after"] : outputs_json_entries;

    if (!mutable_resource_entry.images.empty())
    {
        uint32_t mutable_images_count = 0;
        for (const auto& image : mutable_resource_entry.images)
        {
            const uint32_t           desc_set    = image.desc_set;
            const uint32_t           binding     = image.desc_binding;
            const uint32_t           array_index = image.array_index;
            const VkShaderStageFlags stages      = image.stages;
            const VulkanImageInfo*   img_info    = image.original_image;
            assert(img_info != nullptr);

            auto& image_json_entry         = outputs_json_entries_after["images"][mutable_images_count++];
            image_json_entry["type"]       = util::ToString<VkDescriptorType>(image.desc_type);
            image_json_entry["stages"]     = ShaderStageFlagsToString(stages);
            image_json_entry["set"]        = desc_set;
            image_json_entry["binding"]    = binding;
            image_json_entry["arrayIndex"] = array_index;
            auto& image_json_entry_desc    = image_json_entry["images"];

            std::vector<VkImageAspectFlagBits> aspects;
            GetFormatAspects(img_info->format, aspects);

            size_t f = 0;
            for (auto aspect : aspects)
            {
                for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                {
                    for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                    {
                        VulkanDumpResourceInfo res_info = res_info_base;
                        res_info.type                   = DumpResourceType::kDispatchTraceRaysImage;
                        res_info.is_dispatch            = false;
                        res_info.before_cmd             = false;
                        res_info.image_info             = img_info;
                        res_info.set                    = desc_set;
                        res_info.binding                = binding;
                        res_info.array_index            = array_index;
                        res_info.stages                 = stages;

                        std::string filename = GenerateDispatchTraceRaysImageFilename(res_info, mip, layer, aspect);

                        const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                    std::max(1u, img_info->extent.height >> mip),
                                                    img_info->extent.depth };

                        dump_json_.InsertImageInfo(image_json_entry_desc[f++],
                                                   img_info->format,
                                                   img_info->type,
                                                   img_info->capture_id,
                                                   extent,
                                                   filename,
                                                   aspect,
                                                   ImageFailedScaling(filename),
                                                   mip,
                                                   layer,
                                                   options_.dump_resources_dump_separate_alpha);

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
    }

    if (!mutable_resource_entry.buffers.empty())
    {
        uint32_t mutable_buffers_count = 0;
        for (const auto& buffer : mutable_resource_entry.buffers)
        {
            const uint32_t           desc_set    = buffer.desc_set;
            const uint32_t           binding     = buffer.desc_binding;
            const uint32_t           array_index = buffer.array_index;
            const VkShaderStageFlags stages      = buffer.stages;
            const VulkanBufferInfo*  buffer_info = buffer.original_buffer;
            assert(buffer_info != nullptr);

            VulkanDumpResourceInfo res_info = res_info_base;
            res_info.type                   = DumpResourceType::kDispatchTraceRaysBuffer;
            res_info.is_dispatch            = false;
            res_info.before_cmd             = false;
            res_info.set                    = desc_set;
            res_info.binding                = binding;
            res_info.array_index            = array_index;
            res_info.stages                 = stages;

            std::string filename = GenerateDispatchTraceRaysBufferFilename(res_info);

            auto& buffer_json_entry         = outputs_json_entries_after["buffers"][mutable_buffers_count++];
            buffer_json_entry["type"]       = util::ToString<VkDescriptorType>(buffer.desc_type);
            buffer_json_entry["stages"]     = ShaderStageFlagsToString(stages);
            buffer_json_entry["set"]        = desc_set;
            buffer_json_entry["binding"]    = binding;
            buffer_json_entry["arrayIndex"] = array_index;
            dump_json_.InsertBufferInfo(buffer_json_entry, buffer_info, filename);
        }
    }

    if (options_.dump_resources_dump_immutable_resources)
    {
        for (const auto& desc_set : draw_call_info.tr_param->referenced_descriptors)
        {
            const uint32_t                            desc_set_index = desc_set.first;
            std::unordered_map<std::string, uint32_t> per_stage_json_entry_indices;
            for (const auto& desc : desc_set.second)
            {
                const uint32_t           desc_binding_index = desc.first;
                const VkDescriptorType   desc_type          = desc.second.desc_type;
                std::vector<std::string> shader_stages_names;
                ShaderStageFlagsToStageNames(desc.second.stage_flags, shader_stages_names);

                for (const std::string& stage_name : shader_stages_names)
                {
                    switch (desc_type)
                    {
                        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                        {
                            for (const auto& img_desc : desc.second.image_info)
                            {
                                if (img_desc.second.image_view_info == nullptr)
                                {
                                    continue;
                                }

                                const VulkanImageInfo* img_info = draw_call_info.object_info_table->GetVkImageInfo(
                                    img_desc.second.image_view_info->image_id);
                                if (img_info == nullptr)
                                {
                                    continue;
                                }

                                uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                                auto&     entry             = tr_entry["descriptors"][stage_name][stage_entry_index++];

                                entry["type"]       = util::ToString<VkDescriptorType>(desc_type);
                                entry["set"]        = desc_set_index;
                                entry["binding"]    = desc_binding_index;
                                entry["arrayIndex"] = img_desc.first;

                                std::vector<VkImageAspectFlagBits> aspects;
                                GetFormatAspects(img_info->format, aspects);

                                size_t f = 0;
                                for (auto aspect : aspects)
                                {
                                    for (uint32_t mip = 0; mip < img_info->level_count; ++mip)
                                    {
                                        for (uint32_t layer = 0; layer < img_info->layer_count; ++layer)
                                        {
                                            VulkanDumpResourceInfo res_info = res_info_base;
                                            res_info.type       = DumpResourceType::kDispatchTraceRaysImageDescriptor;
                                            res_info.image_info = img_info;

                                            std::string filename = GenerateDispatchTraceRaysImageDescriptorFilename(
                                                res_info, mip, layer, aspect);

                                            const VkExtent3D extent = { std::max(1u, img_info->extent.width >> mip),
                                                                        std::max(1u, img_info->extent.height >> mip),
                                                                        img_info->extent.depth };

                                            auto& image_descriptor_json_entry = entry["descriptor"];

                                            dump_json_.InsertImageInfo(image_descriptor_json_entry[f++],
                                                                       img_info->format,
                                                                       img_info->type,
                                                                       img_info->capture_id,
                                                                       extent,
                                                                       filename,
                                                                       aspect,
                                                                       ImageFailedScaling(filename),
                                                                       mip,
                                                                       layer,
                                                                       options_.dump_resources_dump_separate_alpha);

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
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        {
                            for (const auto& buf_desc : desc.second.buffer_info)
                            {
                                if (buf_desc.second.buffer_info != nullptr)
                                {
                                    uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                                    auto&     entry = tr_entry["descriptors"][stage_name][stage_entry_index++];

                                    entry["type"]       = util::ToString<VkDescriptorType>(desc.second.desc_type);
                                    entry["set"]        = desc_set_index;
                                    entry["binding"]    = desc_binding_index;
                                    entry["arrayIndex"] = buf_desc.first;

                                    VulkanDumpResourceInfo res_info = res_info_base;
                                    res_info.type        = DumpResourceType::kDispatchTraceRaysBufferDescriptor;
                                    res_info.buffer_info = buf_desc.second.buffer_info;

                                    const std::string filename =
                                        GenerateDispatchTraceRaysBufferDescriptorFilename(res_info);
                                    auto& buffer_descriptor_json_entry = entry["descriptor"];
                                    dump_json_.InsertBufferInfo(
                                        buffer_descriptor_json_entry, buf_desc.second.buffer_info, filename);
                                }
                            }
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                        {
                            uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                            auto&     desc_json_entry   = tr_entry["descriptors"][stage_name][stage_entry_index++];

                            VulkanDumpResourceInfo res_info = res_info_base;
                            res_info.type    = DumpResourceType::kDispatchTraceRaysInlineUniformBufferDescriptor;
                            res_info.set     = desc_set_index;
                            res_info.binding = desc_binding_index;

                            const std::string filename =
                                GenerateDispatchTraceRaysInlineUniformBufferDescriptorFilename(res_info);

                            desc_json_entry["type"]    = util::ToString<VkDescriptorType>(desc.second.desc_type);
                            desc_json_entry["set"]     = desc_set_index;
                            desc_json_entry["binding"] = desc_binding_index;
                            desc_json_entry["size"]    = desc.second.inline_uniform_block.size();
                            desc_json_entry["file"]    = filename;
                        }
                        break;

                        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                        case VK_DESCRIPTOR_TYPE_SAMPLER:
                            break;

                        default:
                            GFXRECON_LOG_WARNING_ONCE("%s(): Descriptor type (%s) not handled",
                                                      __func__,
                                                      util::ToString<VkDescriptorType>(desc.second.desc_type).c_str());
                            break;
                    }
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

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
