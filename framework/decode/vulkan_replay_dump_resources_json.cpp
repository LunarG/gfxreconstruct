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

#include "vulkan_replay_dump_resources_json.h"
#include "util/platform.h"
#include "vulkan/vulkan_core.h"
#include <cstddef>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReplayDumpResourcesJson::VulkanReplayDumpResourcesJson(float scale)
{
    header_["vulkan-version"] = std::to_string(VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                std::to_string(VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                std::to_string(VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
    header_["scale"] = scale;
};

VulkanReplayDumpResourcesJson::~VulkanReplayDumpResourcesJson()
{
    Close();
}

bool VulkanReplayDumpResourcesJson::Open(const std::string& infile, const std::string& outdir, float scale)
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
    outfile = outfile + "_rd.json";

    int ret = gfxrecon::util::platform::FileOpen(&file_, outfile.c_str(), "w");
    if (ret || file_ == nullptr)
    {
#if defined(WIN32)
        GFXRECON_LOG_FATAL("Could not open dump resources outfile file %s", outfile.c_str());
#else
        GFXRECON_LOG_FATAL("Could not open dump resources outfile file %s (%s)", outfile.c_str(), strerror(ret));
#endif
        return false;
    }

    util::platform::FileWrite("[\n", 2, 1, file_);

    BlockStart();
    json_data_["header"] = header_;
    BlockEnd();

    return true;
}

void VulkanReplayDumpResourcesJson::Close()
{
    if (file_)
    {
        util::platform::FileWrite("]", 1, 1, file_);
        gfxrecon::util::platform::FileClose(file_);
        file_ = NULL;
    }
}

nlohmann::ordered_json& VulkanReplayDumpResourcesJson::BlockStart()
{
    json_data_.clear();
    return json_data_;
}

void VulkanReplayDumpResourcesJson::BlockEnd()
{
    static bool first_ = true;

    if (!first_)
    {
        util::platform::FileWrite(",\n", 2, 1, file_);
    }

    first_ = false;

    const std::string block = json_data_.dump(util::kJsonIndentWidth);
    util::platform::FileWrite(block.c_str(), block.size(), 1, file_);
}

nlohmann::ordered_json& VulkanReplayDumpResourcesJson::InsertSubEntry(const std::string& entry_name)
{
    nlohmann::ordered_json& sub_entry = json_data_[entry_name];
    return sub_entry;
}

void VulkanReplayDumpResourcesJson::InsertImageInfo(nlohmann::ordered_json& json_entry,
                                                    const ImageInfo*        image_info,
                                                    const std::string&      filename,
                                                    VkImageAspectFlagBits   aspect,
                                                    uint32_t                mip_level,
                                                    uint32_t                array_layer,
                                                    const VkExtent3D*       extent)
{
    assert(image_info != nullptr);

    json_entry["image_id"] = image_info->capture_id;
    json_entry["format"] = util::ToString<VkFormat>(image_info->format);
    json_entry["type"]   = util::ToString<VkImageType>(image_info->type);

    const std::string aspect_str_whole(util::ToString<VkImageAspectFlagBits>(aspect));
    const std::string aspect_str(aspect_str_whole.begin() + 16, aspect_str_whole.end() - 4);
    json_entry["aspect"] = aspect_str;

    json_entry["dimensions"][0] = extent != nullptr ? extent->width : image_info->extent.width;
    json_entry["dimensions"][1] = extent != nullptr ? extent->height : image_info->extent.height;
    json_entry["dimensions"][2] = extent != nullptr ? extent->depth : image_info->extent.depth;

    json_entry["mip_level"]   = mip_level;
    json_entry["array_layer"] = array_layer;

    json_entry["file"] = filename;
}

void VulkanReplayDumpResourcesJson::InsertBufferInfo(nlohmann::ordered_json& json_entry,
                                                     const BufferInfo*       buffer_info,
                                                     const std::string&      filename,
                                                     size_t                  size)
{
    assert(buffer_info != nullptr);

    json_entry["buffer_id"] = buffer_info->capture_id;
    json_entry["size"]   = size ? size : buffer_info->size;
    json_entry["file"]   = filename;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
