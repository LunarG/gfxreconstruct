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

#include "decode/json_writer.h"
#include "util/file_output_stream.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReplayDumpResourcesJson
{
  public:
    VulkanReplayDumpResourcesJson();

    void VulkanReplayDumpResourcesJsonOpen(const std::string& infile, const std::string& outdir);

    void VulkanReplayDumpResourcesJsonBlockStart();

    void VulkanReplayDumpResourcesJsonBlockEnd();

    void VulkanReplayDumpResourcesJsonData(const std::string descriptor, const std::string value);

    void VulkanReplayDumpResourcesJsonData(const std::string descriptor, const uint64_t value);

    void VulkanReplayDumpResourcesJsonClose();

    ~VulkanReplayDumpResourcesJson();

  private:
    FILE*                                                   jsonFileHandle_{ NULL };
    std::unique_ptr<gfxrecon::util::FileNoLockOutputStream> out_stream_;
    std::unique_ptr<gfxrecon::decode::JsonWriter>           json_writer_;
    std::unique_ptr<nlohmann::ordered_json>                 dump_;
    nlohmann::ordered_json*                                 json_data_{ NULL };
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_JSON_H */
