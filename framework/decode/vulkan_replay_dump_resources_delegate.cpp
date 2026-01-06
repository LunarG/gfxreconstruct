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
#include "generated/generated_vulkan_enum_to_string.h"
#include "util/buffer_writer.h"
#include "util/image_writer.h"
#include "util/logging.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <cstddef>
#include <cstdint>
#include <unordered_set>
#include <variant>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void DefaultVulkanDumpResourcesDelegate::DumpDrawCallInfo(const VulkanDelegateDumpDrawCallContext& draw_call_info)
{
    switch (draw_call_info.command_type)
    {
        case DumpResourcesPipelineStage::kGraphics:
            GenerateOutputJsonDrawCallInfo(draw_call_info);
            break;
        case DumpResourcesPipelineStage::kCompute:
            GenerateOutputJsonDispatchInfo(draw_call_info);
            break;
        case DumpResourcesPipelineStage::kRayTracing:
            GenerateOutputJsonTraceRaysIndex(draw_call_info);
            break;
        case DumpResourcesPipelineStage::kTransfer:
            GenerateOutputJsonTransferInfo(draw_call_info);
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

        case DumpResourceType::kInitBufferMetaCommand:
        case DumpResourceType::kInitImageMetaCommand:
        case DumpResourceType::kCopyBuffer:
        case DumpResourceType::kCopyBufferToImage:
        case DumpResourceType::kCopyImage:
        case DumpResourceType::kCopyImageToBuffer:
        case DumpResourceType::kBlitImage:
        case DumpResourceType::kBuildAccelerationStructure:
        case DumpResourceType::kCopyAccelerationStructure:
            return DumpTransferCommandToFile(delegate_context);
            break;

        default:
            GFXRECON_LOG_ERROR("%s(): Unexpected resources type (%d)", __func__, static_cast<int>(resource_info->type));
            GFXRECON_ASSERT(0);
            break;
    }

    return false;
}

static bool DumpBufferToFile(DumpedBuffer&           dumped_buffer,
                             const std::string&      filename,
                             const DumpedHostData&   data,
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
    DumpedResourceBase* dumped_resource = delegate_context.dumped_resource;
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

bool DefaultVulkanDumpResourcesDelegate::DumpImageToFile(DumpedResourceBase*        dumped_resource,
                                                         DumpedImage&               dumped_image,
                                                         const DumpedImageHostData& image_dumped_data,
                                                         ImageFilenameGenerator     filename_generator,
                                                         bool                       before_command,
                                                         const util::Compressor*    compressor)
{
    const VulkanImageInfo* image_info = dumped_image.image_info;

    const DumpedImageFormat output_image_format = GetDumpedImageFormat(
        dumped_image, options_.dump_resources_dump_raw_images, options_.dump_resources_image_format);

    dumped_image.dumped_raw = (output_image_format == DumpedImageFormat::KFormatRaw);

    GFXRECON_ASSERT(!dumped_image.dumped_subresources.empty());

    for (size_t i = 0; i < dumped_image.dumped_subresources.size(); ++i)
    {
        auto& sub_res = dumped_image.dumped_subresources[i];

        const std::string filename = std::invoke(filename_generator,
                                                 *this,
                                                 *dumped_resource,
                                                 output_image_format,
                                                 sub_res.aspect,
                                                 sub_res.level,
                                                 sub_res.layer,
                                                 before_command);

        sub_res.filename = filename;

        if (output_image_format != KFormatRaw)
        {
            const util::imagewriter::DataFormats image_writer_format =
                VkFormatToImageWriterDataFormat(dumped_image.dumped_format, sub_res.aspect);
            assert(image_writer_format != util::imagewriter::DataFormats::kFormat_UNSPECIFIED);

            const uint32_t texel_size = vkuFormatElementSizeWithAspect(dumped_image.dumped_format, sub_res.aspect);
            const uint32_t stride     = texel_size * sub_res.scaled_extent.width;

            if (output_image_format == kFormatBMP)
            {
                if (options_.dump_resources_dump_separate_alpha)
                {
                    util::imagewriter::WriteBmpImageSeparateAlpha(filename,
                                                                  sub_res.scaled_extent.width,
                                                                  sub_res.scaled_extent.height,
                                                                  static_cast<const void*>(image_dumped_data[i].data()),
                                                                  stride,
                                                                  image_writer_format);
                }
                else
                {
                    util::imagewriter::WriteBmpImage(filename,
                                                     sub_res.scaled_extent.width,
                                                     sub_res.scaled_extent.height,
                                                     static_cast<const void*>(image_dumped_data[i].data()),
                                                     stride,
                                                     image_writer_format,
                                                     vkuFormatHasAlpha(image_info->format));
                }
            }
            else if (output_image_format == KFormatPNG)
            {
                if (options_.dump_resources_dump_separate_alpha)
                {
                    util::imagewriter::WritePngImageSeparateAlpha(filename,
                                                                  sub_res.scaled_extent.width,
                                                                  sub_res.scaled_extent.height,
                                                                  static_cast<const void*>(image_dumped_data[i].data()),
                                                                  stride,
                                                                  image_writer_format);
                }
                else
                {
                    util::imagewriter::WritePngImage(filename,
                                                     sub_res.scaled_extent.width,
                                                     sub_res.scaled_extent.height,
                                                     static_cast<const void*>(image_dumped_data[i].data()),
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

            sub_res.size = image_dumped_data[i].size();
            const size_t bytes_written =
                util::bufferwriter::WriteBuffer(filename,
                                                static_cast<const void*>(image_dumped_data[i].data()),
                                                image_dumped_data[i].size(),
                                                compressor);

            if (!bytes_written)
            {
                GFXRECON_LOG_ERROR("Failed writing file %s", filename.c_str());
                return false;
            }

            if (compressor != nullptr)
            {
                sub_res.compressed_size = bytes_written;
            }
        }
    }

    return true;
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

    const VulkanDelegateImageDumpedData& image_dumped_data =
        std::get<VulkanDelegateImageDumpedData>(delegate_context.dumped_data);

    return DumpImageToFile(dumped_resource,
                           *dumped_image,
                           image_dumped_data.data,
                           filename_generator,
                           delegate_context.before_command,
                           delegate_context.compressor);
}

bool DefaultVulkanDumpResourcesDelegate::DumpTLASToFile(const DumpedResourceBase&                  dumped_resource,
                                                        DumpedAccelerationStructure&               dumped_as,
                                                        const AccelerationStructureDumpedHostData& dumped_as_data,
                                                        bool                                       before_command,
                                                        const util::Compressor*                    compressor)
{
    GFXRECON_ASSERT(dumped_as.as_info != nullptr);
    GFXRECON_ASSERT(dumped_as.as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR);

    // Dump serialized version
    if (dumped_as.serialized_buffer.size)
    {
        std::string filename = GenerateASDumpedBufferFilename(dumped_resource,
                                                              dumped_as.as_info->capture_id,
                                                              AccelerationStructureDumpedBufferType::kSerializedTlas,
                                                              dumped_resource.ppl_stage,
                                                              before_command);

        gfxrecon::decode::DumpBufferToFile(
            dumped_as.serialized_buffer, filename, dumped_as_data.serialized_data, compressor);
    }

    // Dump instance buffers
    for (size_t i = 0; i < dumped_as_data.build_data.size(); ++i)
    {
        GFXRECON_ASSERT(std::get_if<AccelerationStructureDumpedHostData::TrianglesBuffers>(
                            &dumped_as_data.build_data[i]) == nullptr);
        GFXRECON_ASSERT(std::get_if<AccelerationStructureDumpedHostData::AABBBuffer>(&dumped_as_data.build_data[i]) ==
                        nullptr);

        const auto* instance_buffer_host_data =
            std::get_if<AccelerationStructureDumpedHostData::InstanceBuffer>(&dumped_as_data.build_data[i]);
        GFXRECON_ASSERT(instance_buffer_host_data != nullptr);

        auto* instance_buffer =
            std::get_if<DumpedAccelerationStructure::DumpedBuildInputInstanceBuffer>(&dumped_as.input_buffers[i]);
        if (instance_buffer->instance_buffer.size)
        {
            std::string filename = GenerateASDumpedBufferFilename(dumped_resource,
                                                                  dumped_as.as_info->capture_id,
                                                                  AccelerationStructureDumpedBufferType::kInstance,
                                                                  dumped_resource.ppl_stage,
                                                                  before_command,
                                                                  static_cast<uint32_t>(i));
            gfxrecon::decode::DumpBufferToFile(
                instance_buffer->instance_buffer, filename, instance_buffer_host_data->instance_buffer, compressor);
        }
    }

    // Dump referenced BLASes
    for (size_t i = 0; i < dumped_as.BLASes.size(); ++i)
    {
        if (!DumpBLASToFile(
                dumped_resource, dumped_as.BLASes[i], dumped_as_data.blass_dumped_data[i], before_command, compressor))
        {
            return false;
        }
    }

    if (!dumped_as.dump_build_input_buffers)
    {
        return true;
    }

    // Dump instance buffers
    for (size_t i = 0; i < dumped_as_data.build_data.size(); ++i)
    {
        GFXRECON_ASSERT(std::get_if<AccelerationStructureDumpedHostData::TrianglesBuffers>(
                            &dumped_as_data.build_data[i]) == nullptr);
        GFXRECON_ASSERT(std::get_if<AccelerationStructureDumpedHostData::AABBBuffer>(&dumped_as_data.build_data[i]) ==
                        nullptr);
    }

    return true;
}

bool DefaultVulkanDumpResourcesDelegate::DumpBLASToFile(const DumpedResourceBase&                  dumped_resource,
                                                        DumpedAccelerationStructure&               dumped_as,
                                                        const AccelerationStructureDumpedHostData& dumped_as_data,
                                                        bool                                       before_command,
                                                        const util::Compressor*                    compressor)
{
    GFXRECON_ASSERT(dumped_as.as_info != nullptr);
    GFXRECON_ASSERT(dumped_as.as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR);

    // Dump serialized version
    if (dumped_as.serialized_buffer.size)
    {
        std::string filename = GenerateASDumpedBufferFilename(dumped_resource,
                                                              dumped_as.as_info->capture_id,
                                                              AccelerationStructureDumpedBufferType::kSerializedBlas,
                                                              dumped_resource.ppl_stage,
                                                              before_command);

        gfxrecon::decode::DumpBufferToFile(
            dumped_as.serialized_buffer, filename, dumped_as_data.serialized_data, compressor);
    }

    if (!dumped_as.dump_build_input_buffers)
    {
        return true;
    }

    // Build input buffers
    for (size_t i = 0; i < dumped_as_data.build_data.size(); ++i)
    {
        GFXRECON_ASSERT(
            std::get_if<AccelerationStructureDumpedHostData::InstanceBuffer>(&dumped_as_data.build_data[i]) == nullptr);

        // Triangles
        if (const auto* triangles_data =
                std::get_if<AccelerationStructureDumpedHostData::TrianglesBuffers>(&dumped_as_data.build_data[i]))
        {
            auto* triangles =
                std::get_if<DumpedAccelerationStructure::DumpedBuildInputTriangleBuffer>(&dumped_as.input_buffers[i]);
            GFXRECON_ASSERT(triangles != nullptr);

            // Vertex buffer
            if (triangles->vertex_buffer.size)
            {
                std::string filename = GenerateASDumpedBufferFilename(dumped_resource,
                                                                      dumped_as.as_info->capture_id,
                                                                      AccelerationStructureDumpedBufferType::kVertex,
                                                                      dumped_resource.ppl_stage,
                                                                      before_command,
                                                                      static_cast<uint32_t>(i));
                gfxrecon::decode::DumpBufferToFile(
                    triangles->vertex_buffer, filename, triangles_data->vertex_buffer, compressor);
            }

            // Index buffer
            if (triangles->index_type != VK_INDEX_TYPE_NONE_KHR && triangles->index_buffer.size)
            {
                std::string filename = GenerateASDumpedBufferFilename(dumped_resource,
                                                                      dumped_as.as_info->capture_id,
                                                                      AccelerationStructureDumpedBufferType::kIndex,
                                                                      dumped_resource.ppl_stage,
                                                                      before_command,
                                                                      static_cast<uint32_t>(i));
                gfxrecon::decode::DumpBufferToFile(
                    triangles->index_buffer, filename, triangles_data->index_buffer, compressor);
            }

            // Transform buffer
            if (triangles->transform_buffer.size)
            {
                std::string filename = GenerateASDumpedBufferFilename(dumped_resource,
                                                                      dumped_as.as_info->capture_id,
                                                                      AccelerationStructureDumpedBufferType::kTransform,
                                                                      dumped_resource.ppl_stage,
                                                                      before_command,
                                                                      static_cast<uint32_t>(i));
                gfxrecon::decode::DumpBufferToFile(
                    triangles->transform_buffer, filename, triangles_data->transform_buffer, compressor);
            }
        }
        // AABBs
        else if (const auto* aabb_data =
                     std::get_if<AccelerationStructureDumpedHostData::AABBBuffer>(&dumped_as_data.build_data[i]))
        {
            auto* aabb =
                std::get_if<DumpedAccelerationStructure::DumpedBuildInputAABBBuffer>(&dumped_as.input_buffers[i]);
            GFXRECON_ASSERT(aabb != nullptr);

            if (aabb->aabb_buffer.size)
            {
                std::string filename = GenerateASDumpedBufferFilename(dumped_resource,
                                                                      dumped_as.as_info->capture_id,
                                                                      AccelerationStructureDumpedBufferType::kAABB,
                                                                      dumped_resource.ppl_stage,
                                                                      before_command,
                                                                      static_cast<uint32_t>(i));
                gfxrecon::decode::DumpBufferToFile(aabb->aabb_buffer, filename, aabb_data->aabb_buffer, compressor);
            }
        }
    }

    return true;
}

bool DefaultVulkanDumpResourcesDelegate::DumpAccelerationStructureToFile(
    const VulkanDelegateDumpResourceContext& delegate_context)
{
    DumpedResourceBase* dumped_resource = delegate_context.dumped_resource;
    GFXRECON_ASSERT(dumped_resource != nullptr);

    DumpedDescriptor* dumped_descriptor = static_cast<DumpedDescriptor*>(dumped_resource);
    GFXRECON_ASSERT(dumped_descriptor != nullptr);
    DumpedAccelerationStructure* dumped_as =
        std::get_if<DumpedAccelerationStructure>(&dumped_descriptor->dumped_resource);

    GFXRECON_ASSERT(dumped_as != nullptr);

    const VulkanDelegateAccelerationStructureDumpedData& dumped_as_host_data =
        std::get<VulkanDelegateAccelerationStructureDumpedData>(delegate_context.dumped_data);

    GFXRECON_ASSERT(dumped_as_host_data.data.build_data.size() == dumped_as->input_buffers.size());
    GFXRECON_ASSERT(dumped_as->as_info != nullptr);
    if (dumped_as->as_info != nullptr && dumped_as->as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR)
    {
        return DumpTLASToFile(*dumped_resource,
                              *dumped_as,
                              dumped_as_host_data.data,
                              delegate_context.before_command,
                              delegate_context.compressor);
    }
    else if (dumped_as->as_info != nullptr &&
             dumped_as->as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR)
    {
        return DumpBLASToFile(*dumped_resource,
                              *dumped_as,
                              dumped_as_host_data.data,
                              delegate_context.before_command,
                              delegate_context.compressor);
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

    std::stringstream filename;

    filename << capture_filename_ << "_"
             << "buffer_" << dumped_buffer->buffer_info.capture_id << "_qs_" << dumped_desc.qs_index << "_bcb_"
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

std::string DefaultVulkanDumpResourcesDelegate::GenerateTransferToBufferRegionFilename(
    const DumpedResourceBase& dumped_resource, bool before_command, uint32_t region_index) const
{
    const auto& dumped_cmd = static_cast<const DumpedTransferCommand&>(dumped_resource);

    std::stringstream filename;
    filename << capture_filename_ << "_";

    switch (dumped_resource.type)
    {
        case DumpResourceType::kInitBufferMetaCommand:
            filename << "initBuffer_";
            break;

        case DumpResourceType::kCopyBuffer:
            filename << "copyBuffer_";
            break;
        case DumpResourceType::kCopyImageToBuffer:
            filename << "copyImageToBuffer_";
            break;
        default:
            GFXRECON_LOG_ERROR(
                "%s(): Unexpected resource type (%u)", __func__, static_cast<uint32_t>(dumped_resource.type))
    }

    if (options_.dump_resources_before)
    {
        if (before_command)
        {
            filename << "before_";
        }
        else
        {
            filename << "after_";
        }
    }

    filename << "cmd_" << dumped_cmd.cmd_index;
    if (region_index != NO_INDEX)
    {
        filename << "_region_index_" << region_index;
    }

    filename << "_qs_" << dumped_cmd.qs_index << ".bin";

    std::filesystem::path filedirname(options_.dump_resources_output_dir);
    std::filesystem::path filebasename(filename.str());
    return (filedirname / filebasename).string();
}

std::string
DefaultVulkanDumpResourcesDelegate::GenerateTransferToImageRegionFilename(const DumpedResourceBase& dumped_resource,
                                                                          DumpedImageFormat         output_image_format,
                                                                          VkImageAspectFlagBits     aspect,
                                                                          uint32_t                  mip_level,
                                                                          uint32_t                  layer,
                                                                          bool before_command) const
{
    std::stringstream filename;
    filename << capture_filename_ << "_";

    switch (dumped_resource.type)
    {
        case DumpResourceType::kInitImageMetaCommand:
            filename << "initImage_";
            break;

        case DumpResourceType::kCopyImage:
            filename << "copyImage_";
            break;

        case DumpResourceType::kCopyBufferToImage:
            filename << "copyBufferToImage_";
            break;

        case DumpResourceType::kBlitImage:
            filename << "blitImage_";
            break;

        default:
            GFXRECON_LOG_ERROR(
                "%s(): Unexpected resource type (%u)", __func__, static_cast<uint32_t>(dumped_resource.type))
    }

    if (options_.dump_resources_before)
    {
        if (before_command)
        {
            filename << "before_";
        }
        else
        {
            filename << "after_";
        }
    }

    const std::string aspect_str = ImageAspectToStr(aspect);
    const auto&       dumped_cmd = static_cast<const DumpedTransferCommand&>(dumped_resource);

    filename << "cmd_" << dumped_cmd.cmd_index << "_qs_" << dumped_cmd.qs_index << "_aspect_" << aspect_str << "_level_"
             << mip_level << "_layer_" << layer;

    filename << ImageFileExtension(output_image_format);

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

    if (options_.dump_all_descriptors)
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

    GFXRECON_ASSERT(dumped_image_desc.ppl_stage == DumpResourcesPipelineStage::kCompute ||
                    dumped_image_desc.ppl_stage == DumpResourcesPipelineStage::kRayTracing);
    const bool is_dispatch = dumped_image_desc.ppl_stage == DumpResourcesPipelineStage::kCompute;

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

    GFXRECON_ASSERT(dumped_buffer_desc.ppl_stage == DumpResourcesPipelineStage::kCompute ||
                    dumped_buffer_desc.ppl_stage == DumpResourcesPipelineStage::kRayTracing);
    const bool is_dispatch = dumped_buffer_desc.ppl_stage == DumpResourcesPipelineStage::kCompute;

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

    std::stringstream filename;
    filename << capture_filename_ << "_buffer_" << dumped_buffer->buffer_info.capture_id << "_set_"
             << buffer_desc_info.set << "_binding_" << buffer_desc_info.binding << "_ai_"
             << buffer_desc_info.array_index << "_qs_" << buffer_desc_info.qs_index << "_bcb_"
             << buffer_desc_info.bcb_index << ".bin";

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

void DefaultVulkanDumpResourcesDelegate::GenerateBLASJsonInfo(nlohmann::ordered_json&            blas_json_entry,
                                                              const DumpedAccelerationStructure& dumped_as)
{
    GFXRECON_ASSERT(dumped_as.as_info != nullptr);
    GFXRECON_ASSERT(dumped_as.as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR);

    GFXRECON_ASSERT(dumped_as.as_info != nullptr);
    blas_json_entry["BlasId"]               = dumped_as.as_info->capture_id;
    blas_json_entry["CaptureDeviceAddress"] = dumped_as.as_info->capture_address;
    blas_json_entry["ReplayDeviceAddress"]  = dumped_as.as_info->replay_address;

    // BLAS serialized data
    if (dumped_as.serialized_buffer.size)
    {
        auto& serialized_entry = blas_json_entry["SerializedData"];
        dump_json_.InsertBufferInfo(serialized_entry, dumped_as.serialized_buffer);
    }

    auto& blas_inputs_entry = blas_json_entry["BuildInputs"];
    if (dumped_as.input_buffers.empty())
    {
        return;
    }

    std::string input_type_string;
    if (std::get_if<DumpedAccelerationStructure::DumpedBuildInputTriangleBuffer>(&dumped_as.input_buffers[0]))
    {
        input_type_string = "Triangles";
    }
    else
    {
        input_type_string = "AABBs";
    }

    auto& inputs_array_entries = blas_inputs_entry[input_type_string];
    for (size_t blas_input = 0; blas_input < dumped_as.input_buffers.size(); ++blas_input)
    {
        if (const auto* triangles = std::get_if<DumpedAccelerationStructure::DumpedBuildInputTriangleBuffer>(
                &dumped_as.input_buffers[blas_input]))
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
        else if (const auto* aabbs = std::get_if<DumpedAccelerationStructure::DumpedBuildInputAABBBuffer>(
                     &dumped_as.input_buffers[blas_input]))
        {
            dump_json_.InsertASBuildRangeInfo(inputs_array_entries[blas_input], triangles->range);
            auto& aabb_buffer_entry = inputs_array_entries[blas_input]["AABBBuffer"];
            dump_json_.InsertBufferInfo(aabb_buffer_entry, aabbs->aabb_buffer);
        }
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateTLASJsonInfo(nlohmann::ordered_json&            tlas_json_entry,
                                                              const DumpedAccelerationStructure& dumped_as)
{
    GFXRECON_ASSERT(dumped_as.as_info != nullptr);
    GFXRECON_ASSERT(dumped_as.as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR);

    if (!dumped_as.input_buffers.empty() && options_.dump_resources_dump_build_AS_input_buffers)
    {
        auto& instances_entries = tlas_json_entry["InstanceBuffers"];
        for (size_t inst_idx = 0; inst_idx < dumped_as.input_buffers.size(); ++inst_idx)
        {
            GFXRECON_ASSERT(std::get_if<DumpedAccelerationStructure::DumpedBuildInputTriangleBuffer>(
                                &dumped_as.input_buffers[inst_idx]) == nullptr);
            GFXRECON_ASSERT(std::get_if<DumpedAccelerationStructure::DumpedBuildInputAABBBuffer>(
                                &dumped_as.input_buffers[inst_idx]) == nullptr);
            const auto* instance_buffer = std::get_if<DumpedAccelerationStructure::DumpedBuildInputInstanceBuffer>(
                &dumped_as.input_buffers[inst_idx]);
            GFXRECON_ASSERT(instance_buffer != nullptr);

            instances_entries[inst_idx]["Stride"] = dumped_as.instance_buffer_stride;
            dump_json_.InsertBufferInfo(instances_entries[inst_idx], instance_buffer->instance_buffer);
        }
    }

    // TLAS serialized data
    if (dumped_as.serialized_buffer.size)
    {
        auto& serialized_entry = tlas_json_entry["SerializedData"];
        dump_json_.InsertBufferInfo(serialized_entry, dumped_as.serialized_buffer);
    }

    // Iterate BLASes
    if (!dumped_as.BLASes.empty())
    {
        auto& blas_entries = tlas_json_entry["BLASes"];
        for (size_t blas = 0; blas < dumped_as.BLASes.size(); ++blas)
        {
            auto& blas_entry = blas_entries[blas];
            GenerateBLASJsonInfo(blas_entry, dumped_as.BLASes[blas]);
        }
    }
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
            const DumpedAccelerationStructure* tlas = std::get_if<DumpedAccelerationStructure>(&desc.dumped_resource);
            GFXRECON_ASSERT(tlas != nullptr);
            GFXRECON_ASSERT(tlas->as_info != nullptr);
            GFXRECON_ASSERT(tlas->as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR);

            for (const std::string& stage_name : shader_stages_names)
            {
                uint32_t& stage_entry_index = per_stage_json_entry_indices[stage_name];
                auto&     entry             = dispatch_json_entry["descriptors"][stage_name][stage_entry_index++];
                entry["type"]               = util::ToString<VkDescriptorType>(desc.desc_type);
                entry["set"]                = desc.set;
                entry["binding"]            = desc.binding;
                entry["arrayIndex"]         = desc.array_index;
                entry["TlasId"]             = tlas->as_info->capture_id;

                if (tlas->input_buffers.empty() && tlas->BLASes.empty())
                {
                    continue;
                }

                auto& tlas_content_entries = entry["TlasContent"];
                GenerateTLASJsonInfo(tlas_content_entries, *tlas);
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
                                                                   DumpResourcesPipelineStage dumped_command_type,
                                                                   bool                       before_command,
                                                                   uint32_t                   buffer_index)
{
    std::stringstream filename;

    filename << capture_filename_ << "_";

    switch (dumped_command_type)
    {
        case DumpResourcesPipelineStage::kGraphics:
            filename << "DrawCall_";
            break;

        case DumpResourcesPipelineStage::kCompute:
            filename << "Dispatch_";
            break;

        case DumpResourcesPipelineStage::kRayTracing:
            filename << "TraceRays_";
            break;

        case DumpResourcesPipelineStage::kTransfer:
            filename << "Transfer_";
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

    if (options_.dump_resources_before)
    {
        if (before_command)
        {
            filename << "before_";
        }
        else
        {
            filename << "after_";
        }
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

bool DefaultVulkanDumpResourcesDelegate::DumpTransferCommandToFile(
    const VulkanDelegateDumpResourceContext& delegate_context)
{
    const auto* dumped_transfer_host_data =
        std::get_if<VulkanDelegateTransferCommandDumpedData>(&delegate_context.dumped_data);
    GFXRECON_ASSERT(dumped_transfer_host_data != nullptr);

    auto* dumped_transfer_command = static_cast<DumpedTransferCommand*>(delegate_context.dumped_resource);
    GFXRECON_ASSERT(dumped_transfer_command != nullptr);

    if (const auto* init_buffer_host_data =
            std::get_if<VulkanDelegateBufferDumpedData>(&dumped_transfer_host_data->dumped_data))
    {
        const DumpedResourceBase* resource_info = delegate_context.dumped_resource;
        GFXRECON_ASSERT(resource_info->type == DumpResourceType::kInitBufferMetaCommand);

        auto* dumped_init_buffer = std::get_if<DumpedInitBufferMetaCommand>(&dumped_transfer_command->dumped_resource);
        GFXRECON_ASSERT(dumped_init_buffer != nullptr);
        const std::string filename =
            GenerateTransferToBufferRegionFilename(*delegate_context.dumped_resource, false, NO_INDEX);
        gfxrecon::decode::DumpBufferToFile(
            dumped_init_buffer->dumped_buffer, filename, init_buffer_host_data->data, delegate_context.compressor);
    }
    else if (const auto* init_image_host_data =
                 std::get_if<VulkanDelegateImageDumpedData>(&dumped_transfer_host_data->dumped_data))
    {
        const DumpedResourceBase* resource_info = delegate_context.dumped_resource;
        GFXRECON_ASSERT(resource_info->type == DumpResourceType::kInitImageMetaCommand);

        auto* dumped_init_image = std::get_if<DumpedInitImageMetaCommand>(&dumped_transfer_command->dumped_resource);
        GFXRECON_ASSERT(dumped_init_image != nullptr);

        DumpImageToFile(delegate_context.dumped_resource,
                        dumped_init_image->dumped_image,
                        init_image_host_data->data,
                        &DefaultVulkanDumpResourcesDelegate::GenerateTransferToImageRegionFilename,
                        delegate_context.before_command,
                        delegate_context.compressor);
    }
    else if (const auto* buffer_copy_host_data =
                 std::get_if<VulkanDelegateDumpedCopyBufferRegions>(&dumped_transfer_host_data->dumped_data))
    {
        const DumpedResourceBase* resource_info = delegate_context.dumped_resource;
        if (resource_info->type == DumpResourceType::kCopyBuffer)
        {
            auto* dumped_copy_buffer = std::get_if<DumpedCopyBuffer>(
                delegate_context.before_command ? &dumped_transfer_command->dumped_resource_before
                                                : &dumped_transfer_command->dumped_resource);
            GFXRECON_ASSERT(dumped_copy_buffer != nullptr);

            GFXRECON_ASSERT(buffer_copy_host_data->regions_data.size() == dumped_copy_buffer->regions.size());
            for (size_t i = 0; i < buffer_copy_host_data->regions_data.size(); ++i)
            {
                const auto&       region_host_data = buffer_copy_host_data->regions_data[i];
                const std::string filename         = GenerateTransferToBufferRegionFilename(
                    *delegate_context.dumped_resource, delegate_context.before_command, i);
                gfxrecon::decode::DumpBufferToFile(dumped_copy_buffer->regions[i].dumped_buffer,
                                                   filename,
                                                   region_host_data,
                                                   delegate_context.compressor);
            }
        }
        else
        {
            GFXRECON_ASSERT(resource_info->type == DumpResourceType::kCopyImageToBuffer)

            auto* dumped_copy_image_to_buffer = std::get_if<DumpedCopyImageToBuffer>(
                delegate_context.before_command ? &dumped_transfer_command->dumped_resource_before
                                                : &dumped_transfer_command->dumped_resource);
            GFXRECON_ASSERT(dumped_copy_image_to_buffer != nullptr);

            GFXRECON_ASSERT(buffer_copy_host_data->regions_data.size() == dumped_copy_image_to_buffer->regions.size());
            for (size_t i = 0; i < buffer_copy_host_data->regions_data.size(); ++i)
            {
                const auto&       region_host_data = buffer_copy_host_data->regions_data[i];
                const std::string filename         = GenerateTransferToBufferRegionFilename(
                    *delegate_context.dumped_resource, delegate_context.before_command, i);
                gfxrecon::decode::DumpBufferToFile(dumped_copy_image_to_buffer->regions[i].dumped_buffer,
                                                   filename,
                                                   region_host_data,
                                                   delegate_context.compressor);
            }
        }
    }
    else if (const auto* image_copy_host_data =
                 std::get_if<VulkanDelegateDumpedCopyImageRegions>(&dumped_transfer_host_data->dumped_data))
    {
        const DumpedResourceBase* resource_info = delegate_context.dumped_resource;
        if (resource_info->type == DumpResourceType::kCopyBufferToImage)
        {
            auto* dumped_copy_buffer_to_image = std::get_if<DumpedCopyBufferToImage>(
                delegate_context.before_command ? &dumped_transfer_command->dumped_resource_before
                                                : &dumped_transfer_command->dumped_resource);
            GFXRECON_ASSERT(dumped_copy_buffer_to_image != nullptr);

            GFXRECON_ASSERT(image_copy_host_data->regions_data.size() == dumped_copy_buffer_to_image->regions.size());
            for (size_t i = 0; i < image_copy_host_data->regions_data.size(); ++i)
            {
                DumpImageToFile(delegate_context.dumped_resource,
                                dumped_copy_buffer_to_image->regions[i].dumped_image,
                                image_copy_host_data->regions_data[i],
                                &DefaultVulkanDumpResourcesDelegate::GenerateTransferToImageRegionFilename,
                                delegate_context.before_command,
                                delegate_context.compressor);
            }
        }
        else if (resource_info->type == DumpResourceType::kCopyImage)
        {
            auto* dumped_copy_image = std::get_if<DumpedCopyImage>(
                delegate_context.before_command ? &dumped_transfer_command->dumped_resource_before
                                                : &dumped_transfer_command->dumped_resource);
            GFXRECON_ASSERT(dumped_copy_image != nullptr);

            GFXRECON_ASSERT(image_copy_host_data->regions_data.size() == dumped_copy_image->regions.size());
            for (size_t i = 0; i < image_copy_host_data->regions_data.size(); ++i)
            {
                DumpImageToFile(delegate_context.dumped_resource,
                                dumped_copy_image->regions[i].dumped_image,
                                image_copy_host_data->regions_data[i],
                                &DefaultVulkanDumpResourcesDelegate::GenerateTransferToImageRegionFilename,
                                delegate_context.before_command,
                                delegate_context.compressor);
            }
        }
        else if (resource_info->type == DumpResourceType::kBlitImage)
        {
            auto* dumped_blit_image = std::get_if<DumpedBlitImage>(
                delegate_context.before_command ? &dumped_transfer_command->dumped_resource_before
                                                : &dumped_transfer_command->dumped_resource);
            GFXRECON_ASSERT(dumped_blit_image != nullptr);

            GFXRECON_ASSERT(image_copy_host_data->regions_data.size() == dumped_blit_image->regions.size());
            for (size_t i = 0; i < image_copy_host_data->regions_data.size(); ++i)
            {
                DumpImageToFile(delegate_context.dumped_resource,
                                dumped_blit_image->regions[i].dumped_image,
                                image_copy_host_data->regions_data[i],
                                &DefaultVulkanDumpResourcesDelegate::GenerateTransferToImageRegionFilename,
                                delegate_context.before_command,
                                delegate_context.compressor);
            }
        }
    }
    else if (const auto* build_as_host_data =
                 std::get_if<VulkanDelegateDumpedBuildAccelerationStructures>(&dumped_transfer_host_data->dumped_data))
    {
        auto* dump_build_as = std::get_if<DumpedBuildAccelerationStructure>(
            delegate_context.before_command ? &dumped_transfer_command->dumped_resource_before
                                            : &dumped_transfer_command->dumped_resource);
        GFXRECON_ASSERT(dump_build_as != nullptr);

        GFXRECON_ASSERT(dump_build_as->dumped_build_infos.size() == build_as_host_data->data.size());
        for (size_t i = 0; i < dump_build_as->dumped_build_infos.size(); ++i)
        {
            if (dump_build_as->dumped_build_infos[i].dumped_as.as_info->type ==
                VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR)
            {
                return DumpTLASToFile(*dumped_transfer_command,
                                      dump_build_as->dumped_build_infos[i].dumped_as,
                                      build_as_host_data->data[i],
                                      delegate_context.before_command,
                                      delegate_context.compressor);
            }
            else
            {
                return DumpBLASToFile(*dumped_transfer_command,
                                      dump_build_as->dumped_build_infos[i].dumped_as,
                                      build_as_host_data->data[i],
                                      delegate_context.before_command,
                                      delegate_context.compressor);
            }
        }
    }
    else if (const auto* copy_as_host_data =
                 std::get_if<VulkanDelegateDumpedCopyAccelerationStructure>(&dumped_transfer_host_data->dumped_data))
    {
        auto* dump_copy_as = std::get_if<DumpedCopyAccelerationStructure>(
            delegate_context.before_command ? &dumped_transfer_command->dumped_resource_before
                                            : &dumped_transfer_command->dumped_resource);
        GFXRECON_ASSERT(dump_copy_as != nullptr);

        if (dump_copy_as->dumped_copy_info.dumped_as.as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR)
        {
            return DumpTLASToFile(*dumped_transfer_command,
                                  dump_copy_as->dumped_copy_info.dumped_as,
                                  copy_as_host_data->data,
                                  delegate_context.before_command,
                                  delegate_context.compressor);
        }
        else
        {
            return DumpBLASToFile(*dumped_transfer_command,
                                  dump_copy_as->dumped_copy_info.dumped_as,
                                  copy_as_host_data->data,
                                  delegate_context.before_command,
                                  delegate_context.compressor);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("%s(): Unexpected transfer command type", __func__);
        GFXRECON_ASSERT(0);
    }

    return true;
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonInitBufferCommand(const DumpedTransferCommand& cmd,
                                                                             nlohmann::ordered_json&      json_entry)
{
    GFXRECON_ASSERT(cmd.type == DumpResourceType::kInitBufferMetaCommand);

    const auto* init_buffer = std::get_if<DumpedInitBufferMetaCommand>(&cmd.dumped_resource);
    GFXRECON_ASSERT(init_buffer != nullptr);

    json_entry["buffer"] = init_buffer->buffer;
    dump_json_.InsertBufferInfo(json_entry, init_buffer->dumped_buffer);
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonInitImageCommand(const DumpedTransferCommand& cmd,
                                                                            nlohmann::ordered_json&      json_entry)
{
    GFXRECON_ASSERT(cmd.type == DumpResourceType::kInitImageMetaCommand);

    const auto* init_image = std::get_if<DumpedInitImageMetaCommand>(&cmd.dumped_resource);
    GFXRECON_ASSERT(init_image != nullptr);

    json_entry["image"] = init_image->image;

    for (size_t sr = 0; sr < init_image->dumped_image.dumped_subresources.size(); ++sr)
    {
        const DumpedImage::DumpedImageSubresource& dumped_image_sub_resource =
            init_image->dumped_image.dumped_subresources[sr];
        auto& subresource_json_entry = json_entry["subresources"];
        dump_json_.InsertImageSubresourceInfo(subresource_json_entry[sr],
                                              dumped_image_sub_resource,
                                              init_image->dumped_image.image_info->format,
                                              options_.dump_resources_dump_separate_alpha,
                                              init_image->dumped_image.dumped_raw);
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonCopyBufferCommand(const DumpedTransferCommand& cmd,
                                                                             nlohmann::ordered_json&      json_entry)
{
    GFXRECON_ASSERT(cmd.type == DumpResourceType::kCopyBuffer);

    const auto* copy_buffer = std::get_if<DumpedCopyBuffer>(&cmd.dumped_resource);
    GFXRECON_ASSERT(copy_buffer != nullptr);

    json_entry["srcBuffer"] = copy_buffer->src_buffer;
    json_entry["dstBuffer"] = copy_buffer->dst_buffer;

    auto& regions_entries = json_entry["regions"];

    for (size_t i = 0; i < copy_buffer->regions.size(); ++i)
    {
        const auto& region              = copy_buffer->regions[i];
        regions_entries[i]["srcOffset"] = region.region.srcOffset;
        regions_entries[i]["dstOffset"] = region.region.dstOffset;
        regions_entries[i]["size"]      = region.region.size;
        dump_json_.InsertBufferInfo(regions_entries[i], region.dumped_buffer);

        if (cmd.has_before)
        {
            const auto* copy_buffer_before = std::get_if<DumpedCopyBuffer>(&cmd.dumped_resource_before);
            GFXRECON_ASSERT(copy_buffer_before != nullptr);
            dump_json_.InsertBeforeBufferInfo(regions_entries[i], copy_buffer_before->regions[i].dumped_buffer);
        }
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonCopyBufferToImageCommand(const DumpedTransferCommand& cmd,
                                                                                    nlohmann::ordered_json& json_entry)
{
    GFXRECON_ASSERT(cmd.type == DumpResourceType::kCopyBufferToImage);

    const auto* copy_buffer_to_image = std::get_if<DumpedCopyBufferToImage>(&cmd.dumped_resource);
    GFXRECON_ASSERT(copy_buffer_to_image != nullptr);

    json_entry["srcBuffer"]      = copy_buffer_to_image->src_buffer;
    json_entry["dstImage"]       = copy_buffer_to_image->dst_image;
    json_entry["dstImageLayout"] = util::ToString<VkImageLayout>(copy_buffer_to_image->dst_image_layout);

    auto& regions_entries = json_entry["regions"];
    for (size_t i = 0; i < copy_buffer_to_image->regions.size(); ++i)
    {
        const auto& region = copy_buffer_to_image->regions[i];

        auto& region_entry                = regions_entries[i];
        region_entry["bufferOffset"]      = region.region.bufferOffset;
        region_entry["bufferRowLength"]   = region.region.bufferRowLength;
        region_entry["bufferImageHeight"] = region.region.bufferImageHeight;
        auto& img_subresource             = region_entry["imageSubresource"];
        img_subresource["aspectMask"] =
            util::ToString(static_cast<VkImageAspectFlagBits>(region.region.imageSubresource.aspectMask));
        img_subresource["mipLevel"]       = region.region.imageSubresource.mipLevel;
        img_subresource["baseArrayLayer"] = region.region.imageSubresource.baseArrayLayer;
        img_subresource["layerCount"]     = region.region.imageSubresource.layerCount;

        auto& img_offset = region_entry["imageOffset"];
        img_offset["x"]  = region.region.imageOffset.x;
        img_offset["y"]  = region.region.imageOffset.y;
        img_offset["z"]  = region.region.imageOffset.z;

        auto& img_extent = region_entry["imageOffset"];
        img_offset["x"]  = region.region.imageOffset.x;
        img_offset["y"]  = region.region.imageOffset.y;
        img_offset["z"]  = region.region.imageOffset.z;

        auto& extent     = region_entry["imageExtent"];
        extent["width"]  = region.region.imageExtent.width;
        extent["height"] = region.region.imageExtent.height;
        extent["depth"]  = region.region.imageExtent.depth;

        auto& subresource_json_entry = region_entry["subresources"];
        for (size_t sr = 0; sr < region.dumped_image.dumped_subresources.size(); ++sr)
        {
            const auto& dumped_image_sub_resource = region.dumped_image.dumped_subresources[sr];
            dump_json_.InsertImageSubresourceInfo(subresource_json_entry[sr],
                                                  dumped_image_sub_resource,
                                                  region.dumped_image.image_info->format,
                                                  options_.dump_resources_dump_separate_alpha,
                                                  region.dumped_image.dumped_raw);

            if (cmd.has_before)
            {
                const auto* copy_image_before = std::get_if<DumpedCopyBufferToImage>(&cmd.dumped_resource_before);
                GFXRECON_ASSERT(copy_image_before != nullptr);
                const auto& region_before                    = copy_image_before->regions[i];
                const auto& dumped_image_sub_resource_before = region_before.dumped_image.dumped_subresources[sr];
                dump_json_.InsertBeforeImageSubresourceInfo(subresource_json_entry[sr],
                                                            dumped_image_sub_resource_before,
                                                            region_before.dumped_image.image_info->format,
                                                            options_.dump_resources_dump_separate_alpha,
                                                            region_before.dumped_image.dumped_raw);
            }
        }
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonCopyImageCommand(const DumpedTransferCommand& cmd,
                                                                            nlohmann::ordered_json&      json_entry)
{
    GFXRECON_ASSERT(cmd.type == DumpResourceType::kCopyImage);

    const auto* copy_image = std::get_if<DumpedCopyImage>(&cmd.dumped_resource);
    GFXRECON_ASSERT(copy_image != nullptr);

    json_entry["srcImage"]       = copy_image->src_image;
    json_entry["srcImageLayout"] = util::ToString<VkImageLayout>(copy_image->src_image_layout);
    json_entry["dstImage"]       = copy_image->dst_image;
    json_entry["dstImageLayout"] = util::ToString<VkImageLayout>(copy_image->dst_image_layout);

    auto& regions_entries = json_entry["regions"];
    for (size_t i = 0; i < copy_image->regions.size(); ++i)
    {
        const auto& region          = copy_image->regions[i];
        auto&       region_entry    = regions_entries[i];
        auto&       src_subresource = region_entry["srcSubresource"];
        src_subresource["aspectMask"] =
            util::ToString(static_cast<VkImageAspectFlagBits>(region.region.srcSubresource.aspectMask));
        src_subresource["mipLevel"]       = region.region.srcSubresource.mipLevel;
        src_subresource["baseArrayLayer"] = region.region.srcSubresource.baseArrayLayer;
        src_subresource["layerCount"]     = region.region.srcSubresource.layerCount;

        auto& srcOffset = region_entry["srcOffset"];
        srcOffset["x"]  = region.region.srcOffset.x;
        srcOffset["y"]  = region.region.srcOffset.y;
        srcOffset["z"]  = region.region.srcOffset.z;

        auto& dst_subresource = region_entry["dstSubresource"];
        dst_subresource["aspectMask"] =
            util::ToString(static_cast<VkImageAspectFlagBits>(region.region.dstSubresource.aspectMask));
        dst_subresource["mipLevel"]       = region.region.dstSubresource.mipLevel;
        dst_subresource["baseArrayLayer"] = region.region.dstSubresource.baseArrayLayer;
        dst_subresource["layerCount"]     = region.region.dstSubresource.layerCount;

        auto& dstOffset = region_entry["dstOffset"];
        dstOffset["x"]  = region.region.dstOffset.x;
        dstOffset["y"]  = region.region.dstOffset.y;
        dstOffset["z"]  = region.region.dstOffset.z;

        auto& extent     = region_entry["extent"];
        extent["width"]  = region.region.extent.width;
        extent["height"] = region.region.extent.height;
        extent["depth"]  = region.region.extent.depth;

        auto& subresource_json_entry = region_entry["subresources"];
        for (size_t sr = 0; sr < region.dumped_image.dumped_subresources.size(); ++sr)
        {
            const auto& dumped_image_sub_resource = region.dumped_image.dumped_subresources[sr];
            dump_json_.InsertImageSubresourceInfo(subresource_json_entry[sr],
                                                  dumped_image_sub_resource,
                                                  region.dumped_image.image_info->format,
                                                  options_.dump_resources_dump_separate_alpha,
                                                  region.dumped_image.dumped_raw);

            if (cmd.has_before)
            {
                const auto* copy_image_before = std::get_if<DumpedCopyImage>(&cmd.dumped_resource_before);
                GFXRECON_ASSERT(copy_image_before != nullptr);
                const auto& region_before                    = copy_image_before->regions[i];
                const auto& dumped_image_sub_resource_before = region_before.dumped_image.dumped_subresources[sr];
                dump_json_.InsertBeforeImageSubresourceInfo(subresource_json_entry[sr],
                                                            dumped_image_sub_resource_before,
                                                            region_before.dumped_image.image_info->format,
                                                            options_.dump_resources_dump_separate_alpha,
                                                            region_before.dumped_image.dumped_raw);
            }
        }
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonCopyImageToBufferCommand(const DumpedTransferCommand& cmd,
                                                                                    nlohmann::ordered_json& json_entry)
{
    GFXRECON_ASSERT(cmd.type == DumpResourceType::kCopyImageToBuffer);

    const auto* copy_image_to_buffer = std::get_if<DumpedCopyImageToBuffer>(&cmd.dumped_resource);
    GFXRECON_ASSERT(copy_image_to_buffer != nullptr);

    json_entry["srcImage"]       = copy_image_to_buffer->src_image;
    json_entry["srcImageLayout"] = util::ToString<VkImageLayout>(copy_image_to_buffer->src_image_layout);
    json_entry["dstBuffer"]      = copy_image_to_buffer->dst_buffer;

    auto& regions_entries = json_entry["regions"];
    for (size_t i = 0; i < copy_image_to_buffer->regions.size(); ++i)
    {
        const auto& region       = copy_image_to_buffer->regions[i];
        auto&       region_entry = regions_entries[i];

        region_entry["bufferOffset"]      = region.region.bufferOffset;
        region_entry["bufferRowLength"]   = region.region.bufferRowLength;
        region_entry["bufferImageHeight"] = region.region.bufferImageHeight;

        auto& img_subresource_entry             = region_entry["imageSubresource"];
        img_subresource_entry["aspectMask"]     = region.region.imageSubresource.aspectMask;
        img_subresource_entry["mipLevel"]       = region.region.imageSubresource.mipLevel;
        img_subresource_entry["baseArrayLayer"] = region.region.imageSubresource.baseArrayLayer;
        img_subresource_entry["layerCount"]     = region.region.imageSubresource.layerCount;

        auto& image_offset = region_entry["imageOffset"];
        image_offset["x"]  = region.region.imageOffset.x;
        image_offset["y"]  = region.region.imageOffset.y;
        image_offset["z"]  = region.region.imageOffset.z;

        auto& image_extent     = region_entry["imageExtent"];
        image_extent["width"]  = region.region.imageExtent.width;
        image_extent["height"] = region.region.imageExtent.height;
        image_extent["depth"]  = region.region.imageExtent.depth;

        dump_json_.InsertBufferInfo(region_entry, region.dumped_buffer);

        if (cmd.has_before)
        {
            const auto* copy_buffer_before = std::get_if<DumpedCopyImageToBuffer>(&cmd.dumped_resource_before);
            GFXRECON_ASSERT(copy_buffer_before != nullptr);
            dump_json_.InsertBeforeBufferInfo(region_entry, copy_buffer_before->regions[i].dumped_buffer);
        }
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonBlitImageCommand(const DumpedTransferCommand& cmd,
                                                                            nlohmann::ordered_json&      json_entry)
{
    GFXRECON_ASSERT(cmd.type == DumpResourceType::kBlitImage);

    const auto* blit_image = std::get_if<DumpedBlitImage>(&cmd.dumped_resource);
    GFXRECON_ASSERT(blit_image != nullptr);

    json_entry["srcImage"]       = blit_image->src_image;
    json_entry["srcImageLayout"] = util::ToString<VkImageLayout>(blit_image->src_image_layout);
    json_entry["dstImage"]       = blit_image->dst_image;
    json_entry["dstImageLayout"] = util::ToString<VkImageLayout>(blit_image->dst_image_layout);
    json_entry["filter"]         = util::ToString<VkFilter>(blit_image->filter);

    auto& regions_entries = json_entry["regions"];
    for (size_t i = 0; i < blit_image->regions.size(); ++i)
    {
        const auto& region          = blit_image->regions[i];
        auto&       region_entry    = regions_entries[i];
        auto&       src_subresource = region_entry["srcSubresource"];
        src_subresource["aspectMask"] =
            util::ToString(static_cast<VkImageAspectFlagBits>(region.region.srcSubresource.aspectMask));
        src_subresource["mipLevel"]       = region.region.srcSubresource.mipLevel;
        src_subresource["baseArrayLayer"] = region.region.srcSubresource.baseArrayLayer;
        src_subresource["layerCount"]     = region.region.srcSubresource.layerCount;

        auto& srcOffsets    = region_entry["srcOffset"];
        srcOffsets["[0].x"] = region.region.srcOffsets[0].x;
        srcOffsets["[0].y"] = region.region.srcOffsets[0].y;
        srcOffsets["[0].z"] = region.region.srcOffsets[0].z;
        srcOffsets["[1].x"] = region.region.srcOffsets[1].x;
        srcOffsets["[1].y"] = region.region.srcOffsets[1].y;
        srcOffsets["[1].z"] = region.region.srcOffsets[1].z;

        auto& dst_subresource = region_entry["dstSubresource"];
        dst_subresource["aspectMask"] =
            util::ToString(static_cast<VkImageAspectFlagBits>(region.region.dstSubresource.aspectMask));
        dst_subresource["mipLevel"]       = region.region.dstSubresource.mipLevel;
        dst_subresource["baseArrayLayer"] = region.region.dstSubresource.baseArrayLayer;
        dst_subresource["layerCount"]     = region.region.dstSubresource.layerCount;

        auto& dstOffsets    = region_entry["dstOffset"];
        dstOffsets["[0].x"] = region.region.dstOffsets[0].x;
        dstOffsets["[0].y"] = region.region.dstOffsets[0].y;
        dstOffsets["[0].z"] = region.region.dstOffsets[0].z;
        dstOffsets["[1].x"] = region.region.dstOffsets[1].x;
        dstOffsets["[1].y"] = region.region.dstOffsets[1].y;
        dstOffsets["[1].z"] = region.region.dstOffsets[1].z;

        auto& subresource_json_entry = region_entry["subresources"];
        for (size_t sr = 0; sr < region.dumped_image.dumped_subresources.size(); ++sr)
        {
            const auto& dumped_image_sub_resource = region.dumped_image.dumped_subresources[sr];
            dump_json_.InsertImageSubresourceInfo(subresource_json_entry[sr],
                                                  dumped_image_sub_resource,
                                                  region.dumped_image.image_info->format,
                                                  options_.dump_resources_dump_separate_alpha,
                                                  region.dumped_image.dumped_raw);

            if (cmd.has_before)
            {
                const auto* copy_image_before = std::get_if<DumpedCopyImage>(&cmd.dumped_resource_before);
                GFXRECON_ASSERT(copy_image_before != nullptr);
                const auto& region_before                    = copy_image_before->regions[i];
                const auto& dumped_image_sub_resource_before = region_before.dumped_image.dumped_subresources[sr];
                dump_json_.InsertBeforeImageSubresourceInfo(subresource_json_entry[sr],
                                                            dumped_image_sub_resource_before,
                                                            region_before.dumped_image.image_info->format,
                                                            options_.dump_resources_dump_separate_alpha,
                                                            region_before.dumped_image.dumped_raw);
            }
        }
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonBuildAccelerationStructuresCommand(
    const DumpedTransferCommand& cmd, nlohmann::ordered_json& json_entry)
{
    GFXRECON_ASSERT(cmd.type == DumpResourceType::kBuildAccelerationStructure);

    const auto* dumped_build_as = std::get_if<DumpedBuildAccelerationStructure>(&cmd.dumped_resource);
    GFXRECON_ASSERT(dumped_build_as != nullptr);

    auto& builds_entries = json_entry["builds"];
    for (size_t i = 0; i < dumped_build_as->dumped_build_infos.size(); ++i)
    {
        const auto& build_info                        = dumped_build_as->dumped_build_infos[i];
        builds_entries[i]["srcAccelerationStructure"] = build_info.src_as;
        builds_entries[i]["dstAccelerationStructure"] = build_info.dst_as;
        builds_entries[i]["mode"] = util::ToString(static_cast<VkBuildAccelerationStructureModeKHR>(build_info.mode));
        builds_entries[i]["dstAccelerationStructureType"] =
            util::ToString<VkAccelerationStructureTypeKHR>(build_info.dumped_as.as_info->type);

        auto& as_content_entries = builds_entries[i]["asContent"];
        if (build_info.dumped_as.as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR)
        {
            GenerateTLASJsonInfo(as_content_entries, build_info.dumped_as);
        }
        else if (build_info.dumped_as.as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR)
        {
            GenerateBLASJsonInfo(as_content_entries, build_info.dumped_as);
        }
        else
        {
            GFXRECON_LOG_ERROR(
                "%s() Unhandled AS type %d", __func__, static_cast<int>(build_info.dumped_as.as_info->type));
            GFXRECON_ASSERT(0);
        }
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonCopyAccelerationStructureCommand(
    const DumpedTransferCommand& cmd, nlohmann::ordered_json& json_entry)
{
    GFXRECON_ASSERT(cmd.type == DumpResourceType::kCopyAccelerationStructure);

    const auto* dumped_copy_as = std::get_if<DumpedCopyAccelerationStructure>(&cmd.dumped_resource);
    GFXRECON_ASSERT(dumped_copy_as != nullptr);

    auto& copy_info_entries  = json_entry["copyInfo"];
    copy_info_entries["src"] = dumped_copy_as->dumped_copy_info.src_as;
    copy_info_entries["dst"] = dumped_copy_as->dumped_copy_info.dst_as;
    copy_info_entries["mode"] =
        util::ToString(static_cast<VkCopyAccelerationStructureModeKHR>(dumped_copy_as->dumped_copy_info.mode));

    auto& as_content_entries = copy_info_entries["asContent"];
    if (dumped_copy_as->dumped_copy_info.dumped_as.as_info->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR)
    {
        GenerateTLASJsonInfo(as_content_entries, dumped_copy_as->dumped_copy_info.dumped_as);
    }
    else if (dumped_copy_as->dumped_copy_info.dumped_as.as_info->type ==
             VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR)
    {
        GenerateBLASJsonInfo(as_content_entries, dumped_copy_as->dumped_copy_info.dumped_as);
    }
    else
    {
        GFXRECON_LOG_ERROR("%s() Unhandled AS type %d",
                           __func__,
                           static_cast<int>(dumped_copy_as->dumped_copy_info.dumped_as.as_info->type));
        GFXRECON_ASSERT(0);
    }
}

void DefaultVulkanDumpResourcesDelegate::GenerateOutputJsonTransferInfo(
    const VulkanDelegateDumpDrawCallContext& draw_call_info)
{
    const TransferDumpingContext::TransferParams* transfer_cmd_params =
        std::get<const TransferDumpingContext::TransferParams*>(draw_call_info.command_parameters);
    GFXRECON_ASSERT(transfer_cmd_params != nullptr);

    const DumpedResourcesInfo& dumped_resources = transfer_cmd_params->params->dumped_resources;
    if (options_.dump_resources_json_per_command)
    {
        std::stringstream filename;
        filename << capture_filename_ << "_";
        filename << "transfer_" << dumped_resources.cmd_index << "_qs_" << dumped_resources.qs_index << "_cmd_"
                 << dumped_resources.cmd_index << "_dr.json";

        std::filesystem::path filedirname(options_.dump_resources_output_dir);
        std::filesystem::path filebasename(filename.str());
        std::string           full_filename = (filedirname / filebasename).string();

        dump_json_.Open(full_filename);
        dump_json_.BlockStart();
    }

    auto& current_block = dump_json_.GetCurrentSubEntry();
    auto& transfer_json_entries =
        !options_.dump_resources_json_per_command ? current_block["transferCommands"] : current_block;

    const uint32_t transfer_json_entry = dump_json_.FetchAndAddTransferEntryIndex();
    auto&          transfer_entry =
        !options_.dump_resources_json_per_command ? transfer_json_entries[transfer_json_entry] : transfer_json_entries;

    transfer_entry["cmdType"]  = TransferDumpingContext::TransferCommandTypeToStr(transfer_cmd_params->params->type);
    transfer_entry["cmdIndex"] = dumped_resources.cmd_index;
    transfer_entry["beginCommandBufferIndex"] = dumped_resources.bcb_index;
    transfer_entry["queueSubmitIndex"]        = dumped_resources.qs_index;

    auto& transf_params_json_entry = transfer_entry["parameters"];

    GFXRECON_ASSERT(dumped_resources.dumped_transfer_command);
    auto& cmd = dumped_resources.dumped_transfer_command;
    switch (transfer_cmd_params->params->type)
    {
        case TransferDumpingContext::TransferCommandTypes::kCmdInitBuffer:
            GenerateOutputJsonInitBufferCommand(*cmd, transf_params_json_entry);
            break;

        case TransferDumpingContext::TransferCommandTypes::kCmdInitImage:
            GenerateOutputJsonInitImageCommand(*cmd, transf_params_json_entry);
            break;

        case TransferDumpingContext::TransferCommandTypes::kCmdCopyBuffer:
            GenerateOutputJsonCopyBufferCommand(*cmd, transf_params_json_entry);
            break;

        case TransferDumpingContext::TransferCommandTypes::kCmdCopyBufferToImage:
            GenerateOutputJsonCopyBufferToImageCommand(*cmd, transf_params_json_entry);
            break;

        case TransferDumpingContext::TransferCommandTypes::kCmdCopyImage:
            GenerateOutputJsonCopyImageCommand(*cmd, transf_params_json_entry);
            break;

        case TransferDumpingContext::TransferCommandTypes::kCmdCopyImageToBuffer:
            GenerateOutputJsonCopyImageToBufferCommand(*cmd, transf_params_json_entry);
            break;

        case TransferDumpingContext::TransferCommandTypes::kCmdBlitImage:
            GenerateOutputJsonBlitImageCommand(*cmd, transf_params_json_entry);
            break;

        case TransferDumpingContext::TransferCommandTypes::kCmdBuildAccelerationStructures:
            GenerateOutputJsonBuildAccelerationStructuresCommand(*cmd, transf_params_json_entry);
            break;

        case TransferDumpingContext::TransferCommandTypes::kCmdCopyAccelerationStructure:
            GenerateOutputJsonCopyAccelerationStructureCommand(*cmd, transf_params_json_entry);
            break;

        default:
            GFXRECON_LOG_WARNING("%s(): Transfer command type %d not handled",
                                 __func__,
                                 static_cast<int>(transfer_cmd_params->params->type));
            GFXRECON_ASSERT(0);
    }

    if (options_.dump_resources_json_per_command)
    {
        dump_json_.BlockEnd();
        dump_json_.Close();
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
