/*
** Copyright (c) 2024 LunarG, Inc.
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
    header_["gfxreconVersion"] = GFXRECON_PROJECT_VERSION_STRING;
    header_["captureFile"]     = options.capture_filename;

    auto& dr_options                                    = header_["dumpResourcesOptions"];
    dr_options["scale"]                                 = options.dump_resources_scale;
    dr_options["dumpResourcesOutputDir"]                = options.dump_resources_output_dir;
    dr_options["dumpResourcesColorAttachmentIndex"]     = options.dump_resources_color_attachment_index;
    dr_options["dumpResourcesBefore"]                   = options.dump_resources_before;
    dr_options["dumpResourcesDumpDepth"]                = options.dump_resources_dump_depth;
    dr_options["dumpResourcesDumpVertexIndexBuffer"]    = options.dump_resources_dump_vertex_index_buffer;
    dr_options["dumpResourcesDumpImmutableResources"]   = options.dump_resources_dump_immutable_resources;
    dr_options["dumpResourcesDumpAllImageSubresources"] = options.dump_resources_dump_all_image_subresources;
    dr_options["dumpResourcesDumpRawImages"]            = options.dump_resources_dump_raw_images;
    dr_options["dumpResourcesDumpSeparateAlpha"]        = options.dump_resources_dump_separate_alpha;
    dr_options["dumpResourcesDumpUnusedVertexBindings"] = options.dump_resources_dump_unused_vertex_bindings;
    dr_options["dumpResourcesBinaryFileCompressionType"] =
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

void VulkanReplayDumpResourcesJson::InsertImageSubresourceInfo(nlohmann::ordered_json&      json_entry,
                                                               VkFormat                     image_format,
                                                               VkImageType                  image_type,
                                                               format::HandleId             image_id,
                                                               const VkExtent3D&            extent,
                                                               const std::string&           filename,
                                                               VkImageAspectFlagBits        aspect,
                                                               uint32_t                     layer_count,
                                                               uint32_t                     mip_level,
                                                               uint32_t                     array_layer,
                                                               const std::vector<uint64_t>* subresource_sizes,
                                                               bool                         separate_alpha,
                                                               const std::string*           filename_before)
{
    const std::string aspect_str_whole(util::ToString<VkImageAspectFlagBits>(aspect));
    const std::string aspect_str(aspect_str_whole.begin() + 16, aspect_str_whole.end() - 4);
    json_entry["aspect"] = aspect_str;

    json_entry["dimensions"][0] = extent.width;
    json_entry["dimensions"][1] = extent.height;
    json_entry["dimensions"][2] = extent.depth;

    json_entry["mipLevel"]   = mip_level;
    json_entry["arrayLayer"] = array_layer;

    const bool raw_image = !util::filepath::GetFilenameExtension(filename).compare(".bin");

    if (separate_alpha && !raw_image && vkuFormatHasAlpha(image_format))
    {
        if (filename_before != nullptr)
        {
            json_entry["beforeFile"]      = *filename_before;
            json_entry["beforeFileAlpha"] = util::filepath::InsertFilenamePostfix(*filename_before, "_alpha");
            json_entry["afterFile"]       = filename;
            json_entry["afterFileAlpha"]  = util::filepath::InsertFilenamePostfix(filename, "_alpha");
            ;
        }
        else
        {
            json_entry["file"]      = filename;
            json_entry["fileAlpha"] = util::filepath::InsertFilenamePostfix(filename, "_alpha");
        }
    }
    else
    {
        if (filename_before != nullptr)
        {
            json_entry["beforeFile"] = *filename_before;
            json_entry["afterFile"]  = filename;
        }
        else
        {
            json_entry["file"] = filename;
        }
    }

    if (subresource_sizes != nullptr)
    {
        const std::string file_extension      = util::filepath::GetFilenameExtension(filename);
        const bool        is_image_dumped_raw = !file_extension.compare(".bin");

        if (is_image_dumped_raw)
        {
            const uint32_t sub_res_idx = mip_level * layer_count + array_layer;
            GFXRECON_ASSERT(sub_res_idx < subresource_sizes->size());

            const uint64_t subresource_size = (*subresource_sizes)[sub_res_idx];
            json_entry["size"]              = subresource_size;
        }
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
