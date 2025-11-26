/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_OPENXR_STAT_CONSUMER_H
#define GFXRECON_DECODE_OPENXR_STAT_CONSUMER_H

#if ENABLE_OPENXR_SUPPORT

#include "decode/custom_openxr_struct_decoders.h"
#include "decode/api_decoder.h"
#include "generated/generated_openxr_struct_decoders.h"
#include "generated/generated_openxr_consumer.h"
#include "util/defines.h"
#include "util/info_output.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"

#include <set>
#include <unordered_map>

#include <nlohmann/json.hpp>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class OpenXrStatsConsumer : public gfxrecon::decode::OpenXrConsumer, public gfxrecon::util::InfoOutputInterface
{
  private:
    std::string MakeVersionString(XrVersion version) const
    {
        return std::to_string(XR_VERSION_MAJOR(version)) + "." + std::to_string(XR_VERSION_MINOR(version)) + "." +
               std::to_string(XR_VERSION_PATCH(version));
    }

    struct OpenXrInstanceTracker
    {
        OpenXrInstanceTracker() {}
        OpenXrInstanceTracker(const XrApplicationInfo& app_info, const uint32_t ext_count, const char* const* exts) :
            app_name(app_info.applicationName), app_version(app_info.applicationVersion),
            engine_name(app_info.engineName), engine_version(app_info.engineVersion), api_version(app_info.apiVersion)
        {
            enabled_extensions = std::move(std::vector<std::string>(exts, exts + ext_count));
        }
        std::string              app_name;
        uint32_t                 app_version{ 0 };
        std::string              engine_name;
        uint32_t                 engine_version{ 0 };
        XrVersion                api_version{ 0 };
        std::vector<std::string> enabled_extensions;
    };

  public:
    virtual void ProcessStateBeginMarker(uint64_t frame_number) override {}

    virtual void Process_xrCreateApiLayerInstance(
        const gfxrecon::decode::ApiCallInfo&                                                    call_info,
        XrResult                                                                                returnValue,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_XrInstanceCreateInfo>* info,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_XrApiLayerCreateInfo>* apiLayerInfo,
        gfxrecon::decode::HandlePointerDecoder<XrInstance>*                                     pInstance) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(apiLayerInfo);
        if ((info != nullptr) && (returnValue >= 0) && !info->IsNull())
        {
            auto                  create_info = info->GetPointer();
            OpenXrInstanceTracker instance_tracker(
                create_info->applicationInfo, create_info->enabledExtensionCount, create_info->enabledExtensionNames);

            const gfxrecon::format::HandleId inst = *pInstance->GetPointer();
            last_created_instance_                = inst;
            instance_info_[inst]                  = std::move(instance_tracker);
        }
    }

    void GenerateInstanceJsonData(nlohmann::json& inst_json_array) const
    {
        for (const auto& [instance, value] : instance_info_)
        {
            nlohmann::json instance_json;

            // Write application data
            instance_json["application-info"]["application"]["name"]    = value.app_name;
            instance_json["application-info"]["application"]["version"] = value.app_version;
            instance_json["application-info"]["engine"]["name"]         = value.engine_name;
            instance_json["application-info"]["engine"]["version"]      = value.engine_version;
            instance_json["application-info"]["api-version"]            = MakeVersionString(value.api_version);
            instance_json["extensions"]                                 = value.enabled_extensions;

            inst_json_array.push_back(instance_json);
        }
    }

    void GenerateInstanceStrings(std::vector<std::string>& out_strings, const OpenXrInstanceTracker& inst_tracker) const
    {
        // Write application data
        out_strings.push_back("");
        out_strings.push_back("OpenXr application info:");
        out_strings.push_back("\tApplication name:    " + inst_tracker.app_name);
        out_strings.push_back("\tApplication version: " + std::to_string(inst_tracker.app_version));
        out_strings.push_back("\tEngine name:         " + inst_tracker.engine_name);
        out_strings.push_back("\tEngine version:      " + std::to_string(inst_tracker.engine_version));
        out_strings.push_back("\tTarget API version:  " + std::to_string(inst_tracker.api_version) + " (" +
                              MakeVersionString(inst_tracker.api_version) + ")");
    }

    std::pair<const std::string, const nlohmann::json*> GenerateJson() const override
    {
        nlohmann::json* openxr_base = new nlohmann::json;

        (*openxr_base)["openxr"]["header-version"] = MakeVersionString(static_cast<XrVersion>(XR_CURRENT_API_VERSION));

        (*openxr_base)["instances"] = nlohmann::json::array();
        GenerateInstanceJsonData((*openxr_base)["instances"]);

        return std::make_pair("openxr", openxr_base);
    }

    const std::vector<std::string> GenerateStrings() const override
    {
        std::vector<std::string> out_strings;
        out_strings.push_back("");
        out_strings.push_back("OpenXR info:");
        out_strings.push_back("\tHeader Version:             " +
                              MakeVersionString(static_cast<XrVersion>(XR_CURRENT_API_VERSION)));
        if (instance_info_.size())
        {
            out_strings.push_back("\tNumber of OpenXR Instances: " + std::to_string(instance_info_.size()));

            // Only generate data for the last instance.
            GenerateInstanceStrings(out_strings, instance_info_.at(last_created_instance_));
        }
        return out_strings;
    }

  private:
    gfxrecon::format::HandleId                                            last_created_instance_{ 0 };
    std::unordered_map<gfxrecon::format::HandleId, OpenXrInstanceTracker> instance_info_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_STAT_CONSUMER_H
