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

#if ENABLE_OPENXR_SUPPORT

#include "info_openxr_interface.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

std::string InfoOpenXrInterface::ApiCompiledHeaderVersionString()
{
    return std::format("  OpenXR Header Version  {}.{}.{}",
                       XR_VERSION_MAJOR(XR_CURRENT_API_VERSION),
                       XR_VERSION_MINOR(XR_CURRENT_API_VERSION),
                       XR_VERSION_PATCH(XR_CURRENT_API_VERSION));
}

void InfoOpenXrInterface::UpdatePossibleCommandLineOptionsArgs(std::string& options, std::string& arguments)
{
    GFXRECON_UNREFERENCED_PARAMETER(options);
    GFXRECON_UNREFERENCED_PARAMETER(arguments);
}

void InfoOpenXrInterface::UpdateCommandLineUsage(std::string& usage)
{
    GFXRECON_UNREFERENCED_PARAMETER(usage);
}

bool InfoOpenXrInterface::CheckCommandLine(std::shared_ptr<gfxrecon::util::ArgumentParser> arg_parser)
{
    GFXRECON_UNREFERENCED_PARAMETER(arg_parser);
    return true;
}

void InfoOpenXrInterface::RegisterApiDecodeComponents(gfxrecon::decode::FileProcessor& file_processor)
{
    openxr_decoder_.AddConsumer(&openxr_detection_consumer_);
    openxr_decoder_.AddConsumer(&openxr_stats_consumer_);
    file_processor.AddDecoder(&openxr_decoder_);
}

void InfoOpenXrInterface::OutputInfo()
{
    switch (info_output_level_)
    {
        case InfoApiInterface::InfoOutputLevel::kBasic:
            break;
        case InfoApiInterface::InfoOutputLevel::kExeInfo:
            break;
        case InfoApiInterface::InfoOutputLevel::EnvironmentInfo:
            break;
        case InfoApiInterface::InfoOutputLevel::FileInfo:
            break;
        case InfoApiInterface::InfoOutputLevel::kVerbose:
            break;
        default:
            break;
    }
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
