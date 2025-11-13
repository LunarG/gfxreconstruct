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
#include "generated/generated_vulkan_enum_to_string.h"
#include "util/buffer_writer.h"
#include "util/image_writer.h"
#include "util/logging.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <cstddef>
#include <unordered_set>
#include <vulkan/vulkan_core.h>

#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include <variant>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

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

bool DefaultVulkanDumpResourcesDelegate::DumpResource(const VulkanDelegateDumpResourceContext& delegate_context)
{
    const DumpedResourceBase* resource_info = delegate_context.dumped_resource;
    switch (resource_info->type)
    {
        case DumpResourceType::kRtv:
        case DumpResourceType::kDsv:
        case DumpResourceType::kImageDescriptor:
        case DumpResourceType::kDispatchTraceRaysImage:
        case DumpResourceType::kDispatchTraceRaysImageDescriptor:
            return DumpImageToFile(delegate_context);
            break;

        case DumpResourceType::kVertex:
        case DumpResourceType::kIndex:
        case DumpResourceType::kBufferDescriptor:
        case DumpResourceType::kDispatchTraceRaysBuffer:
        case DumpResourceType::kDispatchTraceRaysBufferDescriptor:
        case DumpResourceType::kInlineUniformBufferDescriptor:
        case DumpResourceType::kDispatchTraceRaysInlineUniformBufferDescriptor:
            return DumpBufferToFile(delegate_context);
            break;

        case DumpResourceType::kAccelerationStructure:
            return DumpAccelerationStructureToFile(delegate_context);
            break;

        default:
            break;
    }

    return false;
}

static bool DumpBufferToFile(DumpedBuffer&           dumped_buffer,
                             const std::string&      filename,
                             const DumpedRawData&    data,
                             const util::Compressor* compressor)
{
    const size_t bytes_written = util::bufferwriter::WriteBuffer(filename, data.data(), data.size(), compressor);

    if (!bytes_written)
    {
        GFXRECON_LOG_ERROR("Error writing file %s", filename.c_str());
        return false;
    }

    dumped_buffer.filename = filename;

    if (bytes_written && bytes_written != data.size())
    {
        GFXRECON_ASSERT(compressor != nullptr);
        dumped_buffer.compressed_size = bytes_written;
    }

    return bytes_written ? true : false;
}

bool DefaultVulkanDumpResourcesDelegate::DumpBufferToFile(const VulkanDelegateDumpResourceContext& delegate_context)
{
    DumpedResourceBase* dumped_resource = static_cast<DumpedResourceBase*>(delegate_context.dumped_resource);
    GFXRECON_ASSERT(dumped_resource != nullptr);

    DumpedBuffer*           dumped_buffer;
    BufferFilenameGenerator filename_generator;

    switch (dumped_resource->type)
    {
        case DumpResourceType::kVertex:
        case DumpResourceType::kIndex:
        {
            filename_generator = dumped_resource->type == DumpResourceType::kVertex
                                     ? &DefaultVulkanDumpResourcesDelegate::GenerateVertexBufferFilename
                                     : &DefaultVulkanDumpResourcesDelegate::GenerateIndexBufferFilename;

            GFXRECON_ASSERT(!delegate_context.before_command);
            DumpedVertexIndexBuffer* dumped_vertex_index_buffer =
                static_cast<DumpedVertexIndexBuffer*>(dumped_resource);
            dumped_buffer = &dumped_vertex_index_buffer->buffer;
        }
        break;

        case DumpResourceType::kBufferDescriptor:
        case DumpResourceType::kDispatchTraceRaysBuffer:
        case DumpResourceType::kDispatchTraceRaysBufferDescriptor:
        case DumpResourceType::kInlineUniformBufferDescriptor:
        case DumpResourceType::kDispatchTraceRaysInlineUniformBufferDescriptor:
        {
            if (dumped_resource->type == DumpResourceType::kBufferDescriptor)
            {
                filename_generator = &DefaultVulkanDumpResourcesDelegate::GenerateGraphicsBufferDescriptorFilename;
            }
            else if (dumped_resource->type == DumpResourceType::kDispatchTraceRaysBuffer)
            {
                filename_generator = &DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysBufferFilename;
            }
            else if (dumped_resource->type == DumpResourceType::kInlineUniformBufferDescriptor)
            {
                GFXRECON_ASSERT(!delegate_context.before_command);
                filename_generator =
                    &DefaultVulkanDumpResourcesDelegate::GenerateGraphicsInlineUniformBufferDescriptorFilename;
            }
            else if (dumped_resource->type == DumpResourceType::kDispatchTraceRaysInlineUniformBufferDescriptor)
            {
                GFXRECON_ASSERT(!delegate_context.before_command);
                filename_generator =
                    &DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysInlineUniformBufferDescriptorFilename;
            }
            else
            {
                GFXRECON_ASSERT((dumped_resource->type == DumpResourceType::kDispatchTraceRaysBufferDescriptor));
                filename_generator =
                    &DefaultVulkanDumpResourcesDelegate::GenerateDispatchTraceRaysBufferDescriptorFilename;
            }

            DumpedDescriptor* dumped_buffer_desc = static_cast<DumpedDescriptor*>(delegate_context.dumped_resource);
            GFXRECON_ASSERT(dumped_buffer_desc != nullptr);

            dumped_buffer = !delegate_context.before_command
                                ? std::get_if<DumpedBuffer>(&dumped_buffer_desc->dumped_resource)
                                : std::get_if<DumpedBuffer>(&dumped_buffer_desc->dumped_resource_before);
            GFXRECON_ASSERT(dumped_buffer != nullptr);
        }
        break;

        default:
            GFXRECON_LOG_ERROR("%s(): Unexpected resource type", __func__)
    }

    const VulkanDelegateBufferDumpedData& buffer_data =
        std::get<VulkanDelegateBufferDumpedData>(delegate_context.dumped_data);

    const std::string filename =
        std::invoke(filename_generator, *this, *dumped_resource, delegate_context.before_command);

    return gfxrecon::decode::DumpBufferToFile(*dumped_buffer, filename, buffer_data.data, delegate_context.compressor);
}

static constexpr util::imagewriter::DataFormats VkFormatToImageWriterDataFormat(VkFormat              format,
                                                                                VkImageAspectFlagBits aspect)
{
    if (aspect == VK_IMAGE_ASPECT_COLOR_BIT)
    {
        if (format == VK_FORMAT_R8G8B8_SRGB || format == VK_FORMAT_R8G8B8_UNORM)
        {
            return util::imagewriter::DataFormats::kFormat_RGB;
        }
        else if (format == VK_FORMAT_R8G8B8A8_SRGB || format == VK_FORMAT_R8G8B8A8_UNORM)
        {
            return util::imagewriter::DataFormats::kFormat_RGBA;
        }
        else if (format == VK_FORMAT_B8G8R8_SRGB || format == VK_FORMAT_B8G8R8_UNORM)
        {
            return util::imagewriter::DataFormats::kFormat_BGR;
        }
        else if (format == VK_FORMAT_B8G8R8A8_SRGB || format == VK_FORMAT_B8G8R8A8_UNORM)
        {
            return util::imagewriter::DataFormats::kFormat_BGRA;
        }
    }
    else if (aspect == VK_IMAGE_ASPECT_DEPTH_BIT)
    {
        if (format == VK_FORMAT_D32_SFLOAT || format == VK_FORMAT_D32_SFLOAT_S8_UINT)
        {
            return util::imagewriter::DataFormats::kFormat_D32_FLOAT;
        }
        else if (format == VK_FORMAT_D24_UNORM_S8_UINT || format == VK_FORMAT_X8_D24_UNORM_PACK32)
        {
            return util::imagewriter::DataFormats::kFormat_D24_UNORM;
        }
        else if (format == VK_FORMAT_D16_UNORM || format == VK_FORMAT_D16_UNORM_S8_UINT)
        {
            return util::imagewriter::DataFormats::kFormat_D16_UNORM;
        }
    }
    else if (aspect == VK_IMAGE_ASPECT_STENCIL_BIT)
    {
        if (format == VK_FORMAT_D32_SFLOAT_S8_UINT || format == VK_FORMAT_D16_UNORM_S8_UINT ||
            format == VK_FORMAT_D24_UNORM_S8_UINT)
        {
            return util::imagewriter::DataFormats::kFormat_S8_UINT;
        }
    }

    GFXRECON_LOG_WARNING("%s(): Unrecognized format - aspect combination (%s - %s)",
                         __func__,
                         util::ToString(format).c_str(),
                         util::ToString(aspect).c_str());
    return util::imagewriter::DataFormats::kFormat_UNSPECIFIED;
}

static const std::unordered_set<VkFormat> FormatsDumpedAsImages = {

    VK_FORMAT_R8G8B8_SRGB, VK_FORMAT_R8G8B8_UNORM,       VK_FORMAT_R8G8B8A8_SRGB,     VK_FORMAT_R8G8B8A8_UNORM,
    VK_FORMAT_B8G8R8_SRGB, VK_FORMAT_B8G8R8_UNORM,       VK_FORMAT_B8G8R8A8_SRGB,     VK_FORMAT_B8G8R8A8_UNORM,
    VK_FORMAT_D32_SFLOAT,  VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT, VK_FORMAT_X8_D24_UNORM_PACK32,
    VK_FORMAT_D16_UNORM
};

static constexpr DumpedImageFormat
GetDumpedImageFormat(const DumpedImage& dumped_image, bool dump_images_raw, util::ScreenshotFormat image_file_format)
{
    if (dump_images_raw)
    {
        return KFormatRaw;
    }

    if (!FormatsDumpedAsImages.count(dumped_image.dumped_format))
    {
        return KFormatRaw;
    }

    // Choose the requested preference for image file extension
    switch (image_file_format)
    {
        case util::ScreenshotFormat::kBmp:
            return kFormatBMP;

        case util::ScreenshotFormat::kPng:
            return KFormatPNG;

        default:
            GFXRECON_LOG_ERROR("Unexpected image file format");
    }

    return KFormatRaw;
}

bool DefaultVulkanDumpResourcesDelegate::DumpImageToFile(const VulkanDelegateDumpResourceContext& delegate_context)
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
            dumped_image = delegate_context.before_command ? &dumped_rt->dumped_image_before : &dumped_rt->dumped_image;
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
            dumped_image                  = delegate_context.before_command
                                                ? std::get_if<DumpedImage>(&dumped_desc->dumped_resource_before)
                                                : std::get_if<DumpedImage>(&dumped_desc->dumped_resource);
            GFXRECON_ASSERT(dumped_image != nullptr);
        }
        break;

        default:
            GFXRECON_LOG_ERROR("%s(): Unexpected resource type", __func__)
    }

    const VulkanImageInfo*  image_info  = dumped_image->image_info;
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(image_info->parent_id);
    GFXRECON_ASSERT(device_info != nullptr);

    const DumpedImageFormat output_image_format = GetDumpedImageFormat(
        *dumped_image, options_.dump_resources_dump_raw_images, options_.dump_resources_image_format);

    dumped_image->dumped_raw = (output_image_format == DumpedImageFormat::KFormatRaw);

    GFXRECON_ASSERT(!dumped_image->dumped_subresources.empty());

    const VulkanDelegateImageDumpedData& image_dumped_data =
        std::get<VulkanDelegateImageDumpedData>(delegate_context.dumped_data);

    for (size_t i = 0; i < dumped_image->dumped_subresources.size(); ++i)
    {
        auto& sub_res = dumped_image->dumped_subresources[i];

        const std::string filename = std::invoke(filename_generator,
                                                 *this,
                                                 *dumped_resource,
                                                 output_image_format,
                                                 sub_res.aspect,
                                                 sub_res.level,
                                                 sub_res.layer,
                                                 delegate_context.before_command);

        sub_res.filename = filename;

        if (output_image_format != KFormatRaw)
        {
            const util::imagewriter::DataFormats image_writer_format =
                VkFormatToImageWriterDataFormat(dumped_image->dumped_format, sub_res.aspect);
            assert(image_writer_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED);

            const uint32_t texel_size = vkuFormatElementSizeWithAspect(dumped_image->dumped_format, sub_res.aspect);
            const uint32_t stride     = texel_size * sub_res.scaled_extent.width;

            if (output_image_format == kFormatBMP)
            {
                if (options_.dump_resources_dump_separate_alpha)
                {
                    util::imagewriter::WriteBmpImageSeparateAlpha(
                        filename,
                        sub_res.scaled_extent.width,
                        sub_res.scaled_extent.height,
                        static_cast<const void*>(image_dumped_data.data[i].data()),
                        stride,
                        image_writer_format);
                }
                else
                {
                    util::imagewriter::WriteBmpImage(filename,
                                                     sub_res.scaled_extent.width,
                                                     sub_res.scaled_extent.height,
                                                     static_cast<const void*>(image_dumped_data.data[i].data()),
                                                     stride,
                                                     image_writer_format,
                                                     vkuFormatHasAlpha(image_info->format));
                }
            }
            else if (output_image_format == KFormatPNG)
            {
                if (options_.dump_resources_dump_separate_alpha)
                {
                    util::imagewriter::WritePngImageSeparateAlpha(
                        filename,
                        sub_res.scaled_extent.width,
                        sub_res.scaled_extent.height,
                        static_cast<const void*>(image_dumped_data.data[i].data()),
                        stride,
                        image_writer_format);
                }
                else
                {
                    util::imagewriter::WritePngImage(filename,
                                                     sub_res.scaled_extent.width,
                                                     sub_res.scaled_extent.height,
                                                     static_cast<const void*>(image_dumped_data.data[i].data()),
                                                     stride,
                                                     image_writer_format,
                                                     vkuFormatHasAlpha(image_info->format));
                }
            }
        }
        else
        {
            if (!options_.dump_resources_dump_raw_images)
            {
                GFXRECON_LOG_WARNING(
                    "%s format is not handled. Images with that format will be dump as a plain binary file.",
                    util::ToString<VkFormat>(image_info->format).c_str());
            }

            sub_res.size = image_dumped_data.data[i].size();
            const size_t bytes_written =
                util::bufferwriter::WriteBuffer(filename,
                                                static_cast<const void*>(image_dumped_data.data[i].data()),
                                                image_dumped_data.data[i].size(),
                                                delegate_context.compressor);

            if (!bytes_written)
            {
                GFXRECON_LOG_ERROR("Failed writing file %s", filename.c_str());
                return false;
            }

            if (delegate_context.compressor != nullptr)
            {
                sub_res.compressed_size = bytes_written;
            }
        }
    }

    return true;
}

bool DefaultVulkanDumpResourcesDelegate::DumpAccelerationStructureToFile(
    const VulkanDelegateDumpResourceContext& delegate_context)
{
    DumpedDescriptor* dumped_descriptor = static_cast<DumpedDescriptor*>(delegate_context.dumped_resource);
    DumpedTopLevelAccelerationStructure* dumped_tlas =
        std::get_if<DumpedTopLevelAccelerationStructure>(&dumped_descriptor->dumped_resource);
    GFXRECON_ASSERT(dumped_tlas != nullptr);

    const VulkanDelegateAccelerationStructureDumpedData& dumped_tlas_data =
        std::get<VulkanDelegateAccelerationStructureDumpedData>(delegate_context.dumped_data);

    // Dump input instance buffers
    GFXRECON_ASSERT(dumped_tlas_data.data.instance_data.size() == dumped_tlas->instance_data.size());
    for (size_t i = 0; i < dumped_tlas_data.data.instance_data.size(); ++i)
    {
        // Instance buffer
        if (dumped_tlas->instance_data[i].size && dumped_tlas->dump_build_input_buffers)
        {
            GFXRECON_ASSERT(dumped_tlas->as_info != nullptr);
            std::string filename = GenerateASDumpedBufferFilename(*dumped_descriptor,
                                                                  dumped_tlas->as_info->capture_id,
                                                                  AccelerationStructureDumpedBufferType::kInstance,
                                                                  dumped_descriptor->resource_type,
                                                                  static_cast<uint32_t>(i));
            gfxrecon::decode::DumpBufferToFile(dumped_tlas->instance_data[i],
                                               filename,
                                               dumped_tlas_data.data.instance_data[i].instance_buffer,
                                               delegate_context.compressor);
        }

        // Serialized AS data
        if (dumped_tlas->serialized_data.size)
        {
            std::string filename =
                GenerateASDumpedBufferFilename(*dumped_descriptor,
                                               dumped_tlas->as_info->capture_id,
                                               AccelerationStructureDumpedBufferType::kSerializedTlas,
                                               dumped_descriptor->resource_type);

            gfxrecon::decode::DumpBufferToFile(dumped_tlas->serialized_data,
                                               filename,
                                               dumped_tlas_data.data.serialized_data,
                                               delegate_context.compressor);
        }
    }

    // Traverse and dump referenced BLASes
    GFXRECON_ASSERT(dumped_tlas_data.data.blass_dumped_data.size() == dumped_tlas->blass.size());
    for (size_t i = 0; i < dumped_tlas_data.data.blass_dumped_data.size(); ++i)
    {
        auto&       blas      = dumped_tlas->blass[i];
        const auto& blas_data = dumped_tlas_data.data.blass_dumped_data[i];

        // Serialized AS data
        if (blas.serialized_data.size)
        {
            std::string filename =
                GenerateASDumpedBufferFilename(*dumped_descriptor,
                                               blas.blas_info->capture_id,
                                               AccelerationStructureDumpedBufferType::kSerializedBlas,
                                               dumped_descriptor->resource_type);
            gfxrecon::decode::DumpBufferToFile(
                blas.serialized_data, filename, blas_data.serialized_data, delegate_context.compressor);
        }

        if (!dumped_tlas->dump_build_input_buffers)
        {
            continue;
        }

        // Build input buffers
        for (size_t d = 0; d < dumped_tlas_data.data.blass_dumped_data[i].build_data.size(); ++d)
        {
            // Triangles
            if (const auto* triangles_data = std::get_if<BLASDumpedHostData::Triangles>(
                    &dumped_tlas_data.data.blass_dumped_data[i].build_data[d]))
            {
                auto* triangles = std::get_if<DumpedBottomLevelAccelerationStructure::DumpedBuildInputDataTriangles>(
                    &blas.input_data[d]);
                GFXRECON_ASSERT(triangles != nullptr);

                // Vertex buffer
                if (triangles->vertex_buffer.size)
                {
                    GFXRECON_ASSERT(blas.blas_info != nullptr);
                    std::string filename =
                        GenerateASDumpedBufferFilename(*dumped_descriptor,
                                                       blas.blas_info->capture_id,
                                                       AccelerationStructureDumpedBufferType::kVertex,
                                                       dumped_descriptor->resource_type,
                                                       static_cast<uint32_t>(d));
                    gfxrecon::decode::DumpBufferToFile(
                        triangles->vertex_buffer, filename, triangles_data->vertex_buffer, delegate_context.compressor);
                }

                // Index buffer
                if (triangles->index_type != VK_INDEX_TYPE_NONE_KHR && triangles->index_buffer.size)
                {
                    std::string filename = GenerateASDumpedBufferFilename(*dumped_descriptor,
                                                                          blas.blas_info->capture_id,
                                                                          AccelerationStructureDumpedBufferType::kIndex,
                                                                          dumped_descriptor->resource_type,
                                                                          static_cast<uint32_t>(d));
                    gfxrecon::decode::DumpBufferToFile(
                        triangles->index_buffer, filename, triangles_data->index_buffer, delegate_context.compressor);
                }

                // Transform buffer
                if (triangles->transform_buffer.size)
                {
                    std::string filename =
                        GenerateASDumpedBufferFilename(*dumped_descriptor,
                                                       blas.blas_info->capture_id,
                                                       AccelerationStructureDumpedBufferType::kTransform,
                                                       dumped_descriptor->resource_type,
                                                       static_cast<uint32_t>(d));
                    gfxrecon::decode::DumpBufferToFile(triangles->transform_buffer,
                                                       filename,
                                                       triangles_data->transform_buffer,
                                                       delegate_context.compressor);
                }
            }
            // AABBs
            else if (const auto* aabb_data = std::get_if<BLASDumpedHostData::AABBS>(
                         &dumped_tlas_data.data.blass_dumped_data[i].build_data[d]))
            {
                auto* aabb =
                    std::get_if<DumpedBottomLevelAccelerationStructure::DumpedBuildInputDataAABB>(&blas.input_data[d]);
                GFXRECON_ASSERT(aabb != nullptr);

                if (aabb->aabb_buffer.size)
                {
                    std::string filename = GenerateASDumpedBufferFilename(*dumped_descriptor,
                                                                          blas.blas_info->capture_id,
                                                                          AccelerationStructureDumpedBufferType::kAABB,
                                                                          dumped_descriptor->resource_type,
                                                                          static_cast<uint32_t>(d));
                    gfxrecon::decode::DumpBufferToFile(
                        aabb->aabb_buffer, filename, aabb_data->aabb_buffer, delegate_context.compressor);
                }
            }
        }
    }

    return true;
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
    const VulkanImageInfo*    image_info =
        !before_command ? rt_resource_info.dumped_image.image_info : rt_resource_info.dumped_image_before.image_info;
    std::string aspect_str     = ImageAspectToStr(aspect);
    std::string attachment_str = rt_resource_info.location != DEPTH_ATTACHMENT
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
                      << image_desc_info.bcb_index << "_rp_" << image_desc_info.render_pass << "_aspect_" << aspect_str;
    }
    else
    {
        std::string whole_format_name = util::ToString<VkFormat>(image_info->format);
        std::string format_name(whole_format_name.begin() + 10, whole_format_name.end());

        base_filename << "image_" << image_info->capture_id << "_qs_" << image_desc_info.qs_index << "_bcb_"
                      << image_desc_info.bcb_index << "_rp_" << image_desc_info.render_pass << "_" << format_name
                      << "_aspect_" << aspect_str;
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
             << dumped_desc.bcb_index << "_rp_" << dumped_desc.render_pass << "_set_" << dumped_desc.set << "_binding_"
             << dumped_desc.binding << "_ai_" << dumped_desc.array_index << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string DefaultVulkanDumpResourcesDelegate::GenerateGraphicsInlineUniformBufferDescriptorFilename(
    const DumpedResourceBase& dumped_resource, bool before_command) const
{
    GFXRECON_UNREFERENCED_PARAMETER(before_command);

    const DumpedDescriptor& buffer_desc_info = static_cast<const DumpedDescriptor&>(dumped_resource);

    std::stringstream filename;
    filename << capture_filename_ << "_"
             << "inlineUniformBlock_set_" << buffer_desc_info.set << "_binding_" << buffer_desc_info.binding << "_ai_"
             << buffer_desc_info.array_index << "_qs_" << buffer_desc_info.qs_index << "_bcb_"
             << buffer_desc_info.bcb_index << ".bin";

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

    size_t rt_json_entries = 0;
    for (const auto& rt : dumped_resources.dumped_render_targets)
    {
        const bool is_depth_attachment = rt.location == DEPTH_ATTACHMENT;
        auto&      rt_entries =
            !is_depth_attachment ? draw_call_entry["colorAttachments"] : draw_call_entry["depthAttachment"];
        auto& rt_entry = !is_depth_attachment ? rt_entries[rt_json_entries++] : rt_entries;

        const DumpedImage&     image      = rt.dumped_image;
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

        if (image.can_dump == ImageDumpResult::kCanDump)
        {
            for (size_t sr = 0; sr < image.dumped_subresources.size(); ++sr)
            {
                const DumpedImage::DumpedImageSubresource& dumped_image_sub_resource = image.dumped_subresources[sr];
                auto&                                      subresource_json_entry    = rt_entry["subresources"];
                dump_json_.InsertImageSubresourceInfo(subresource_json_entry[sr],
                                                      dumped_image_sub_resource,
                                                      image_info->format,
                                                      options_.dump_resources_dump_separate_alpha,
                                                      image.dumped_raw);

                if (options_.dump_resources_before)
                {
                    const DumpedImage::DumpedImageSubresource& dumped_image_before_sub_resource =
                        rt.dumped_image_before.dumped_subresources[sr];
                    dump_json_.InsertBeforeImageSubresourceInfo(subresource_json_entry[sr],
                                                                dumped_image_before_sub_resource,
                                                                image_info->format,
                                                                options_.dump_resources_dump_separate_alpha,
                                                                image.dumped_raw);
                }
            }
        }
        else
        {
            if (image.can_dump == ImageDumpResult::kCanNotResolve)
            {
                rt_entry["dumpFailure"] = "CouldNotResolve";
            }
            else if (image.can_dump == ImageDumpResult::kFormatNotSupported)
            {
                rt_entry["dumpFailure"] = "FormatNotSupported";
            }
        }
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

    if (options_.dump_resources_dump_vertex_index_buffer)
    {
        size_t vertex_buffer_entries = 0;
        for (const auto& vib : dumped_resources.dumped_vertex_index_buffers)
        {
            if (vib.index_type != VK_INDEX_TYPE_NONE_KHR)
            {
                auto& vertex_input_state_json_entry = draw_call_entry["vertexInputState"];
                auto& json_entry                    = vertex_input_state_json_entry["indexBuffer"];

                json_entry["indexType"] = util::ToString<VkIndexType>(vib.index_type);
                dump_json_.InsertBufferInfo(json_entry, vib.buffer);
            }
            else
            {
                auto& vertex_input_state_json_entry = draw_call_entry["vertexInputState"];
                auto& json_entry = vertex_input_state_json_entry["vertexBuffers"][vertex_buffer_entries++];

                json_entry["vertexBufferBinding"] = vib.binding;
                dump_json_.InsertBufferInfo(json_entry, vib.buffer);
            }
        }
    }

    if (options_.dump_resources_dump_immutable_resources)
    {
        GenerateDescriptorsJsonInfo(draw_call_entry, dumped_resources);
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
    filename << capture_filename_ << "_buffer_" << buffer_info->capture_id << "_set_" << buffer_desc_info.set
             << "_binding_" << buffer_desc_info.binding << "_ai_" << buffer_desc_info.array_index << "_qs_"
             << buffer_desc_info.qs_index << "_bcb_" << buffer_desc_info.bcb_index << ".bin";

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
             << buffer_desc_info.binding << "_ai_" << buffer_desc_info.array_index << "_qs_"
             << buffer_desc_info.qs_index << "_bcb_" << buffer_desc_info.bcb_index << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

void DefaultVulkanDumpResourcesDelegate::GenerateDescriptorsJsonInfo(nlohmann::ordered_json&    dispatch_json_entry,
                                                                     const DumpedResourcesInfo& dumped_resources)
{
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

                if (dumped_image->can_dump == ImageDumpResult::kCanDump)
                {
                    for (size_t sr = 0; sr < dumped_image->dumped_subresources.size(); ++sr)
                    {
                        const auto& dumped_image_sub_resource = dumped_image->dumped_subresources[sr];

                        auto& subresource_json_entry = entry["subresources"];
                        dump_json_.InsertImageSubresourceInfo(subresource_json_entry[sr],
                                                              dumped_image_sub_resource,
                                                              img_info->format,
                                                              options_.dump_resources_dump_separate_alpha,
                                                              dumped_image->dumped_raw);

                        const DumpedImage* dumped_image_before = std::get_if<DumpedImage>(&desc.dumped_resource_before);
                        if (options_.dump_resources_before && dumped_image_before != nullptr)
                        {
                            const DumpedImage::DumpedImageSubresource& dumped_image_before_sub_resource =
                                dumped_image_before->dumped_subresources[sr];

                            dump_json_.InsertBeforeImageSubresourceInfo(subresource_json_entry[sr],
                                                                        dumped_image_before_sub_resource,
                                                                        img_info->format,
                                                                        options_.dump_resources_dump_separate_alpha,
                                                                        dumped_image->dumped_raw);
                        }
                    }
                }
                else
                {
                    if (dumped_image->can_dump == ImageDumpResult::kCanNotResolve)
                    {
                        entry["dumpFailure"] = "CouldNotResolve";
                    }
                    else if (dumped_image->can_dump == ImageDumpResult::kFormatNotSupported)
                    {
                        entry["dumpFailure"] = "FormatNotSupported";
                    }
                }
            }
        }
        else if (const DumpedBuffer* dumped_buffer = std::get_if<DumpedBuffer>(&desc.dumped_resource))
        {
            for (const std::string& stage_name : shader_stages_names)
            {
                uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                auto&     entry             = dispatch_json_entry["descriptors"][stage_name][stage_entry_index++];
                entry["type"]               = util::ToString<VkDescriptorType>(desc.desc_type);
                entry["set"]                = desc.set;
                entry["binding"]            = desc.binding;
                entry["arrayIndex"]         = desc.array_index;

                dump_json_.InsertBufferInfo(entry, *dumped_buffer);

                const DumpedBuffer* dumped_buffer_before = std::get_if<DumpedBuffer>(&desc.dumped_resource_before);
                if (options_.dump_resources_before && dumped_buffer_before != nullptr)
                {
                    dump_json_.InsertBeforeBufferInfo(entry, *dumped_buffer_before);
                }
            }
        }
        else
        {
            const DumpedTopLevelAccelerationStructure* tlas =
                std::get_if<DumpedTopLevelAccelerationStructure>(&desc.dumped_resource);
            GFXRECON_ASSERT(tlas != nullptr);

            for (const std::string& stage_name : shader_stages_names)
            {
                uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                auto&     entry             = dispatch_json_entry["descriptors"][stage_name][stage_entry_index++];
                entry["type"]               = util::ToString<VkDescriptorType>(desc.desc_type);
                entry["set"]                = desc.set;
                entry["binding"]            = desc.binding;
                entry["arrayIndex"]         = desc.array_index;

                entry["TlasId"] = tlas->as_info->capture_id;

                if (tlas->instance_data.empty() && tlas->blass.empty())
                {
                    continue;
                }

                auto& tlas_content_entries = entry["TlasContent"];
                if (!tlas->instance_data.empty() && options_.dump_resources_dump_build_AS_input_buffers)
                {
                    auto& instances_entries = tlas_content_entries["InstanceBuffers"];
                    for (size_t inst_idx = 0; inst_idx < tlas->instance_data.size(); ++inst_idx)
                    {
                        instances_entries[inst_idx]["Stride"] = tlas->instance_buffer_stride;
                        dump_json_.InsertBufferInfo(instances_entries[inst_idx], tlas->instance_data[inst_idx]);
                    }
                }

                // TLAS serialized data
                if (tlas->serialized_data.size)
                {
                    auto& serialized_entry = tlas_content_entries["SerializedData"];
                    dump_json_.InsertBufferInfo(serialized_entry, tlas->serialized_data);
                }

                // Iterate BLASes
                if (!tlas->blass.empty())
                {
                    auto& blas_entries = tlas_content_entries["BLASes"];
                    for (size_t blas = 0; blas < tlas->blass.size(); ++blas)
                    {
                        auto& blas_entry = blas_entries[blas];

                        GFXRECON_ASSERT(tlas->blass[blas].blas_info != nullptr);
                        blas_entry["BlasId"]               = tlas->blass[blas].blas_info->capture_id;
                        blas_entry["CaptureDeviceAddress"] = tlas->blass[blas].blas_info->capture_address;
                        blas_entry["ReplayDeviceAddress"]  = tlas->blass[blas].blas_info->replay_address;

                        // BLAS serialized data
                        if (tlas->blass[blas].serialized_data.size)
                        {
                            auto& serialized_entry = blas_entry["SerializedData"];
                            dump_json_.InsertBufferInfo(serialized_entry, tlas->blass[blas].serialized_data);
                        }

                        auto& blas_inputs_entry = blas_entry["BuildInputs"];
                        if (tlas->blass[blas].input_data.empty())
                        {
                            continue;
                        }

                        std::string input_type_string;
                        if (std::get_if<DumpedBottomLevelAccelerationStructure::DumpedBuildInputDataTriangles>(
                                &tlas->blass[blas].input_data[0]))
                        {
                            input_type_string = "Triangles";
                        }
                        else
                        {
                            input_type_string = "AABBs";
                        }

                        auto& inputs_array_entries = blas_inputs_entry[input_type_string];
                        for (size_t blas_input = 0; blas_input < tlas->blass[blas].input_data.size(); ++blas_input)
                        {
                            if (const auto* triangles =
                                    std::get_if<DumpedBottomLevelAccelerationStructure::DumpedBuildInputDataTriangles>(
                                        &tlas->blass[blas].input_data[blas_input]))
                            {
                                dump_json_.InsertASBuildRangeInfo(inputs_array_entries[blas_input], triangles->range);

                                auto& vertex_buffer_entry        = inputs_array_entries[blas_input]["VertexBuffer"];
                                vertex_buffer_entry["Format"]    = util::ToString(triangles->vertex_format);
                                vertex_buffer_entry["MaxVertex"] = triangles->max_vertex;
                                vertex_buffer_entry["Stride"]    = triangles->vertex_buffer_stride;
                                dump_json_.InsertBufferInfo(vertex_buffer_entry, triangles->vertex_buffer);

                                if (triangles->index_type != VK_INDEX_TYPE_NONE_KHR)
                                {
                                    auto& index_buffer_entry        = inputs_array_entries[blas_input]["IndexBuffer"];
                                    index_buffer_entry["IndexType"] = util::ToString(triangles->index_type);
                                    dump_json_.InsertBufferInfo(index_buffer_entry, triangles->index_buffer);
                                }

                                if (triangles->transform_buffer.size)
                                {
                                    auto& transform_buffer_entry = inputs_array_entries[blas_input]["TransformBuffer"];
                                    dump_json_.InsertBufferInfo(transform_buffer_entry, triangles->transform_buffer);
                                }
                            }
                            else if (const auto* aabbs =
                                         std::get_if<DumpedBottomLevelAccelerationStructure::DumpedBuildInputDataAABB>(
                                             &tlas->blass[blas].input_data[blas_input]))
                            {
                                dump_json_.InsertASBuildRangeInfo(inputs_array_entries[blas_input], triangles->range);
                                auto& aabb_buffer_entry = inputs_array_entries[blas_input]["AABBBuffer"];
                                dump_json_.InsertBufferInfo(aabb_buffer_entry, aabbs->aabb_buffer);
                            }
                        }
                    }
                }
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

    GenerateDescriptorsJsonInfo(dispatch_json_entry, dumped_resources);

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

    GenerateDescriptorsJsonInfo(tr_entry, dumped_resources);

    if (options_.dump_resources_json_per_command)
    {
        dump_json_.BlockEnd();
        dump_json_.Close();
    }
}

std::string
DefaultVulkanDumpResourcesDelegate::GenerateASDumpedBufferFilename(const DumpedResourceBase&             resource_info,
                                                                   format::HandleId                      handle_id,
                                                                   AccelerationStructureDumpedBufferType type,
                                                                   DumpResourcesCommandType dumped_command_type,
                                                                   uint32_t                 buffer_index)
{
    std::stringstream filename;

    filename << capture_filename_ << "_";

    switch (dumped_command_type)
    {
        case DumpResourcesCommandType::kGraphics:
            filename << "DrawCall_";
            break;

        case DumpResourcesCommandType::kCompute:
            filename << "Dispatch_";
            break;

        case DumpResourcesCommandType::kRayTracing:
            filename << "TraceRays_";
            break;

        default:
            GFXRECON_LOG_ERROR(
                "%s: Unrecognized command type (%u)", __func__, static_cast<unsigned>(dumped_command_type));
            filename << "XXX_";
            break;
    }

    filename << resource_info.cmd_index;

    std::string buffer_type;
    switch (type)
    {
        case AccelerationStructureDumpedBufferType::kInstance:
            buffer_type = "_instance_buffer_";
            break;
        case AccelerationStructureDumpedBufferType::kVertex:
            buffer_type = "_vertex_buffer_";
            break;
        case AccelerationStructureDumpedBufferType::kIndex:
            buffer_type = "_index_buffer_";
            break;
        case AccelerationStructureDumpedBufferType::kAABB:
            buffer_type = "_AABB_buffer_";
            break;
        case AccelerationStructureDumpedBufferType::kTransform:
            buffer_type = "_transform_buffer_";
            break;
        case AccelerationStructureDumpedBufferType::kSerializedBlas:
        case AccelerationStructureDumpedBufferType::kSerializedTlas:
            buffer_type = "_serialized";
            break;
        default:
            GFXRECON_ASSERT(0);
    }

    if (type == AccelerationStructureDumpedBufferType::kVertex ||
        type == AccelerationStructureDumpedBufferType::kIndex || type == AccelerationStructureDumpedBufferType::kAABB ||
        type == AccelerationStructureDumpedBufferType::kTransform ||
        type == AccelerationStructureDumpedBufferType::kSerializedBlas)
    {
        filename << "_BLAS_";
    }
    else
    {
        filename << "_TLAS_";
    }

    filename << handle_id << buffer_type;

    if (type != AccelerationStructureDumpedBufferType::kSerializedBlas &&
        type != AccelerationStructureDumpedBufferType::kSerializedTlas)
    {
        GFXRECON_ASSERT(buffer_index != std::numeric_limits<uint32_t>::max())
        filename << buffer_index;
    }

    filename << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
