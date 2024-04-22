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
#include "project_version.h"
#include "util/logging.h"
#include "vulkan/vulkan_core.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReplayDumpResourcesJson::VulkanReplayDumpResourcesJson(){};

void VulkanReplayDumpResourcesJson::VulkanReplayDumpResourcesJsonOpen(const std::string& infile,
                                                                      const std::string& outdir,
                                                                      float              scale)
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

    int ret = gfxrecon::util::platform::FileOpen(&jsonFileHandle_, outfile.c_str(), "w");
    if (ret || jsonFileHandle_ == nullptr)
    {
#if defined(WIN32)
        GFXRECON_LOG_FATAL("Could not open dump resources outfile file %s", outfile.c_str());
#else
        GFXRECON_LOG_FATAL("Could not open dump resources outfile file %s (%s)", outfile.c_str(), strerror(ret));
#endif
        exit(1);
    }

    out_stream_ = std::unique_ptr<gfxrecon::util::FileNoLockOutputStream>(
        new gfxrecon::util::FileNoLockOutputStream(jsonFileHandle_, false));

    gfxrecon::util::JsonOptions json_options;
    json_options.root_dir     = "."; // This field is not used
    json_options.data_sub_dir = "."; // This field is not used
    json_options.format       = gfxrecon::util::JsonFormat::JSON;

    json_writer_ = std::unique_ptr<gfxrecon::decode::JsonWriter>(
        new gfxrecon::decode::JsonWriter(json_options, GFXRECON_PROJECT_VERSION_STRING, infile));

    json_writer_->GetHeaderJson()["vulkan-version"] =
        std::to_string(VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
        std::to_string(VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
        std::to_string(VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
    json_writer_->GetHeaderJson()["scale"] = scale;
    json_writer_->StartStream(out_stream_.get());
}

void VulkanReplayDumpResourcesJson::VulkanReplayDumpResourcesJsonBlockStart()
{
    json_data_ = &json_writer_->WriteBlockStart();
}

void VulkanReplayDumpResourcesJson::VulkanReplayDumpResourcesJsonBlockEnd()
{
    json_writer_->WriteBlockEnd();
}

void VulkanReplayDumpResourcesJson::VulkanReplayDumpResourcesJsonClose()
{
    if (jsonFileHandle_)
    {
        json_writer_->EndStream();
        gfxrecon::util::platform::FileClose(jsonFileHandle_);
        jsonFileHandle_ = NULL;
    }
}

VulkanReplayDumpResourcesJson::~VulkanReplayDumpResourcesJson()
{
    VulkanReplayDumpResourcesJsonClose();
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
