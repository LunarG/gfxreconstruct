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
#include "decode/vulkan_replay_dump_resources_options.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "format/format_util.h"
#include "util/file_path.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "util/file_path.h"
#include "util/logging.h"
#include <cstdint>
#include PROJECT_VERSION_HEADER_FILE
#include "generated/generated_vulkan_enum_to_string.h"
#include "vulkan_replay_dump_resources_json.h"
#include "util/platform.h"
#include "util/file_path.h"
#include "vulkan/vulkan_core.h"
#include <cstddef>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReplayDumpResourcesJson::VulkanReplayDumpResourcesJson(const VulkanReplayOptions& options) :
    file_(nullptr), current_entry(nullptr), first_block_(true), draw_calls_entry_index(0), dispatch_entry_index(0),
    trace_rays_entry_index(0)
{
    header_["vulkanVersion"] = std::to_string(VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                               std::to_string(VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                               std::to_string(VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
    header_["gfxreconVersion"] = GetProjectVersionString();
    header_["captureFile"]     = options.capture_filename;

    auto& dr_options            = header_[kVDROptions];
    dr_options[kVDROptionScale] = options.dump_resources_scale;
    dr_options[kVDROptionImageFormat] =
        options.dump_resources_dump_raw_images ? "bin" : ImageFormatToString(options.dump_resources_image_format);
    dr_options[kVDROptionOutputDir]                = options.dump_resources_output_dir;
    dr_options[kVDROptionColorAttachmentIndex]     = options.dump_resources_color_attachment_index;
    dr_options[kVDROptionBefore]                   = options.dump_resources_before;
    dr_options[kVDROptionDumpDepth]                = options.dump_resources_dump_depth;
    dr_options[kVDROptionDumpVertexIndexBuffer]    = options.dump_resources_dump_vertex_index_buffer;
    dr_options[kVDROptionDumpAllDescriptors]       = options.dump_all_descriptors;
    dr_options[kVDROptionDumpAllImageSubresources] = options.dump_resources_dump_all_image_subresources;
    dr_options[kVDROptionDumpRawImages]            = options.dump_resources_dump_raw_images;
    dr_options[kVDROptionDumpSeparateAlpha]        = options.dump_resources_dump_separate_alpha;
    dr_options[kVDROptionDumpUnusedVertexBindings] = options.dump_resources_dump_unused_vertex_bindings;
    dr_options[kVDROptionJsonOutputPerCommand]     = options.dump_resources_json_per_command;
    dr_options[kVDROptionDumpBuildAccelerationStructuresInputBuffers] =
        options.dump_resources_dump_build_AS_input_buffers;
    dr_options[kVDROptionBinaryFileCompressionType] =
        format::GetCompressionTypeName(options.dump_resources_binary_file_compression_type);
};

bool VulkanReplayDumpResourcesJson::InitializeFile(const std::string& filename)
{
    int ret = gfxrecon::util::platform::FileOpen(&file_, filename.c_str(), "w");
    if (ret || file_ == nullptr)
    {
#if defined(WIN32)
        GFXRECON_LOG_FATAL("Could not open dump resources output json file %s", filename.c_str());
#else
        GFXRECON_LOG_FATAL("Could not open dump resources output json file %s (%s)", filename.c_str(), strerror(ret));
#endif
        return false;
    }

    util::platform::FileWrite("[\n", 2, file_);

    BlockStart();
    json_data_["header"] = header_;
    BlockEnd();

    BlockStart();

    return true;
}

bool VulkanReplayDumpResourcesJson::Open(const std::string& infile, const std::string& outdir)
{
    std::filesystem::path path_outfile(outdir);
    std::filesystem::path path_infile(infile);
    std::string           outfile;

    path_outfile /= path_infile.filename();
    outfile = path_outfile.string();
    if (outfile.size() >= 5 && !outfile.compare(outfile.size() - 5, 5, ".gfxr"))
    {
        outfile = outfile.substr(0, outfile.size() - 5);
    }
    outfile = outfile + "_dr.json";

    if (!InitializeFile(outfile))
    {
        return false;
    }

    return true;
}

bool VulkanReplayDumpResourcesJson::Open(const std::string& filename)
{
    if (!InitializeFile(filename))
    {
        return false;
    }

    return true;
}

void VulkanReplayDumpResourcesJson::Close()
{
    if (file_ != nullptr)
    {
        util::platform::FileWrite("]", 1, file_);
        gfxrecon::util::platform::FileClose(file_);
        file_ = nullptr;
    }
    first_block_ = true;
}

nlohmann::ordered_json& VulkanReplayDumpResourcesJson::BlockStart()
{
    json_data_.clear();
    current_entry = nullptr;

    draw_calls_entry_index = 0;
    dispatch_entry_index   = 0;
    trace_rays_entry_index = 0;

    return json_data_;
}

void VulkanReplayDumpResourcesJson::BlockEnd()
{
    assert(file_ != nullptr);

    if (!first_block_)
    {
        util::platform::FileWrite(",\n", 2, file_);
    }

    first_block_ = false;

    const std::string block = json_data_.dump(util::kJsonIndentWidth);
    util::platform::FileWrite(block.c_str(), block.size(), file_);
}

nlohmann::ordered_json& VulkanReplayDumpResourcesJson::InsertSubEntry(const std::string& entry_name)
{
    current_entry = &json_data_[entry_name];
    return *current_entry;
}

nlohmann::ordered_json& VulkanReplayDumpResourcesJson::GetCurrentSubEntry()
{
    return current_entry != nullptr ? *current_entry : json_data_;
}

void VulkanReplayDumpResourcesJson::InsertImageSubresourceInfo(nlohmann::ordered_json&                    json_entry,
                                                               const DumpedImage::DumpedImageSubresource& subresource,
                                                               VkFormat                                   format,
                                                               bool separate_alpha,
                                                               bool dumped_raw)
{
    const std::string aspect_str_whole(util::ToString<VkImageAspectFlagBits>(subresource.aspect));
    const std::string aspect_str(aspect_str_whole.begin() + 16, aspect_str_whole.end() - 4);
    json_entry["aspect"] = aspect_str;

    json_entry["dimensions"][0] = subresource.extent.width;
    json_entry["dimensions"][1] = subresource.extent.height;
    json_entry["dimensions"][2] = subresource.extent.depth;

    json_entry["mipLevel"]   = subresource.level;
    json_entry["arrayLayer"] = subresource.layer;
    json_entry["file"]       = subresource.filename;

    if (separate_alpha && !dumped_raw && vkuFormatHasAlpha(format))
    {
        json_entry["fileAlpha"] = util::filepath::InsertFilenamePostfix(subresource.filename, "_alpha");
    }

    if (dumped_raw)
    {
        json_entry["size"] = subresource.size;

        if (subresource.compressed_size)
        {
            json_entry["compressedSize"] = subresource.compressed_size;
        }
    }
}

void VulkanReplayDumpResourcesJson::InsertBeforeImageSubresourceInfo(
    nlohmann::ordered_json&                    json_entry,
    const DumpedImage::DumpedImageSubresource& subresource,
    VkFormat                                   format,
    bool                                       separate_alpha,
    bool                                       dumped_raw)
{
    json_entry["beforeFile"] = subresource.filename;

    if (separate_alpha && !dumped_raw && vkuFormatHasAlpha(format))
    {
        json_entry["beforeFileAlpha"] = util::filepath::InsertFilenamePostfix(subresource.filename, "_alpha");
    }

    if (dumped_raw)
    {
        json_entry["beforeSize"] = subresource.size;

        if (subresource.compressed_size)
        {
            json_entry["compressedSizeBefore"] = subresource.compressed_size;
        }
    }
}

void VulkanReplayDumpResourcesJson::InsertBufferInfo(nlohmann::ordered_json& json_entry,
                                                     const DumpedBuffer&     dumped_buffer)
{
    const VulkanBufferInfo* buffer_info = dumped_buffer.buffer_info;

    if (buffer_info != nullptr)
    {
        json_entry["bufferId"] = buffer_info->capture_id;
    }

    json_entry["offset"] = dumped_buffer.offset;
    json_entry["size"]   = dumped_buffer.size;
    json_entry["file"]   = dumped_buffer.filename;

    if (dumped_buffer.compressed_size)
    {
        json_entry["compressedSize"] = dumped_buffer.compressed_size;
    }
}

void VulkanReplayDumpResourcesJson::InsertBeforeBufferInfo(nlohmann::ordered_json& json_entry,
                                                           const DumpedBuffer&     dumped_buffer)
{
    json_entry["beforeFile"] = dumped_buffer.filename;

    if (dumped_buffer.compressed_size)
    {
        json_entry["compressedSizeBefore"] = dumped_buffer.compressed_size;
    }
}

void VulkanReplayDumpResourcesJson::InsertASBuildRangeInfo(nlohmann::ordered_json&                         json_entry,
                                                           const VkAccelerationStructureBuildRangeInfoKHR& range)
{
    auto& range_entry              = json_entry["VkAccelerationStructureBuildRangeInfoKHR"];
    range_entry["primitiveCount"]  = range.primitiveCount;
    range_entry["primitiveOffset"] = range.primitiveOffset;
    range_entry["firstVertex"]     = range.firstVertex;
    range_entry["transformOffset"] = range.transformOffset;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
