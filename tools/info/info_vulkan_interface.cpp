/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include "info_vulkan_interface.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

std::string InfoVulkanInterface::ApiCompiledHeaderVersionString()
{
    return std::format("  Vulkan Header Version  {}.{}.{}",
                       VK_API_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                       VK_API_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                       VK_API_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
}

void InfoVulkanInterface::UpdatePossibleCommandLineOptionsArgs(std::string& options, std::string& arguments)
{
    GFXRECON_UNREFERENCED_PARAMETER(options);
    GFXRECON_UNREFERENCED_PARAMETER(arguments);
}

void InfoVulkanInterface::UpdateCommandLineUsage(std::string& usage)
{
    GFXRECON_UNREFERENCED_PARAMETER(usage);
}

bool InfoVulkanInterface::CheckCommandLine(std::shared_ptr<gfxrecon::util::ArgumentParser> arg_parser)
{
    GFXRECON_UNREFERENCED_PARAMETER(arg_parser);
    return true;
}

void InfoVulkanInterface::RegisterApiDecodeComponents(gfxrecon::decode::FileProcessor& file_processor)
{
    vulkan_decoder_.AddConsumer(&vulkan_detection_consumer_);
    vulkan_decoder_.AddConsumer(&vulkan_stats_consumer_);
    file_processor.AddDecoder(&vulkan_decoder_);
}

void InfoVulkanInterface::OutputInfo()
{
    switch (info_output_level_)
    {
        case InfoApiInterface::InfoOutputLevel::kBasic:
            break;
        case InfoApiInterface::InfoOutputLevel::kVerbose:
            break;
        default:
            break;
    }
}

uint32_t InfoVulkanInterface::GetFrameStart()
{
    return vulkan_stats_consumer_.GetTrimmedStartFrame();
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)
