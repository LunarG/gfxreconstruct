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

#ifndef GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_JSON_H
#define GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_JSON_H

#include "util/json_util.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayDumpResourcesJson
{
  public:
    VulkanReplayDumpResourcesJson(const VulkanReplayOptions& options);

    ~VulkanReplayDumpResourcesJson(){};

    bool Open(const std::string& infile, const std::string& outdir);

    bool Open(const std::string& filename);

    void Close();

    nlohmann::ordered_json& BlockStart();

    void BlockEnd();

    nlohmann::ordered_json& GetData() { return json_data_; }

    template <typename T>
    void InsertSingleEntry(const std::string& descriptor, const T& value)
    {
        json_data_[descriptor] = value;
    }

    nlohmann::ordered_json& InsertSubEntry(const std::string& entry_name);

    nlohmann::ordered_json& GetCurrentSubEntry();

    void InsertImageInfo(nlohmann::ordered_json&         json_entry,
                         const VulkanImageInfo*          image_info,
                         const std::vector<std::string>& filenames,
                         VkImageAspectFlagBits           aspect,
                         bool                            scale_failed = false,
                         uint32_t                        mip_level    = 0,
                         uint32_t                        array_layer  = 0,
                         const VkExtent3D*               extent       = nullptr);

    void InsertBufferInfo(nlohmann::ordered_json& json_entry,
                          const VulkanBufferInfo* buffer_info,
                          const std::string&      filename);

  private:
    bool InitializeFile(const std::string& filename);

    FILE*                   file_;
    nlohmann::ordered_json  header_;
    nlohmann::ordered_json  json_data_;
    nlohmann::ordered_json* current_entry;
    bool                    first_block_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_JSON_H */
