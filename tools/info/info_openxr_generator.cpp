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

#include "info_openxr_generator.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

// Static boolean that runs a lambda to automatically create and register this class with the
// base class RegisterGenerator method.
static bool sRegisterThisGenerator = []() {
    InfoApiGenerator::RegisterGenerator([]() { return std::make_unique<InfoOpenXrGenerator>(); });
    return true;
}();

std::string InfoOpenXrGenerator::ApiCompiledHeaderVersionString() const
{
    return std::string("  OpenXR Header Version  ") + std::to_string(XR_VERSION_MAJOR(XR_CURRENT_API_VERSION)) + "." +
           std::to_string(XR_VERSION_MINOR(XR_CURRENT_API_VERSION)) + "." +
           std::to_string(XR_VERSION_PATCH(XR_CURRENT_API_VERSION));
}

void InfoOpenXrGenerator::RegisterApiDecodeComponents(decode::FileProcessor& file_processor)
{
    openxr_decoder_.AddConsumer(&openxr_detection_consumer_);
    openxr_decoder_.AddConsumer(&openxr_stats_consumer_);
    file_processor.AddDecoder(&openxr_decoder_);
}

std::string InfoOpenXrGenerator::GetVersionString(XrVersion api_version)
{
    uint32_t major = XR_VERSION_MAJOR(api_version);
    uint32_t minor = XR_VERSION_MINOR(api_version);
    uint32_t patch = XR_VERSION_PATCH(api_version);

    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

void InfoOpenXrGenerator::PrintInfo()
{
    auto instance_info = openxr_stats_consumer_.GetInstanceInfo();

    WriteOutput("");
    WriteOutput("OpenXR info:");

    WriteOutput(std::string("\tHeader Version:             ") + GetVersionString(XR_CURRENT_API_VERSION));

    WriteOutput(std::string("\tNumber of OpenXR Instances: ") + std::to_string(instance_info.size()));

    // For non-verbose standard output, just print first application/instance info
    WriteOutput("\nOpenXR application info:");
    WriteOutput(std::string("\tApplication name:    ") + instance_info[0].app_name);
    WriteOutput(std::string("\tApplication version: ") + std::to_string(instance_info[0].app_version));
    WriteOutput(std::string("\tEngine name:         ") + instance_info[0].engine_name);
    WriteOutput(std::string("\tEngine version:      ") + std::to_string(instance_info[0].engine_version));
    WriteOutput(std::string("\tTarget API version:  ") + std::to_string(instance_info[0].api_version) + " (" +
                GetVersionString(instance_info[0].api_version) + ")");
}

nlohmann::json InfoOpenXrGenerator::GenerateJson()
{
    auto instance_info = openxr_stats_consumer_.GetInstanceInfo();

    nlohmann::json openxr_stats;

    openxr_stats["header-version"] = GetVersionString(XR_CURRENT_API_VERSION);
    auto& instances_json = openxr_stats["instances"] = nlohmann::json::array();

    uint32_t       inst_index = 0;
    nlohmann::json instance_array;
    for (auto& it : instance_info)
    {
        nlohmann::json instance_json;

        auto& application_info                     = instance_json["application-info"];
        application_info["application"]["name"]    = it.second.app_name;
        application_info["application"]["version"] = it.second.app_version;
        application_info["engine"]["name"]         = it.second.engine_name;
        application_info["engine"]["version"]      = it.second.engine_version;
        application_info["api-version"]            = GetVersionString(it.second.api_version);

        instance_json["extensions"] = it.second.enabled_extensions;

        instances_json.push_back(instance_json);
    }

    return openxr_stats;
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
