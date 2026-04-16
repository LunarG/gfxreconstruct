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

#if defined(D3D12_SUPPORT)

#include "info_d3d12_feature.h"

#include "util/feature_module_registry.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

// Register this class as a feature in a module registry
GFXR_UTIL_REGISTER_FEATURE_CREATOR(InfoFeature, InfoD3d12Feature)

const char kEnumGpuIndices[] = "--enum-gpu-indices";

std::string InfoD3d12Feature::CompiledHeaderVersionString() const
{
#if defined(D3D12SDKVersion)
    return std::string("  D3D12 SDK Version      ") + D3D12SDKVersion;
#else
    return "";
#endif
}

void InfoD3d12Feature::UpdateValidCommandLineOptionsArgs(std::string& options, std::string& arguments)
{
    options += " ";
    options += kEnumGpuIndices;
}

std::string InfoD3d12Feature::GetCommandLineUsage()
{
    std::string return_val = "\n// D3D12-specific\n  ";
    return_val += kEnumGpuIndices;
    return_val += "\tPrint GPU indices and exit\n";
    return return_val;
}

bool InfoD3d12Feature::CheckCommandLine(util::ArgumentParser* arg_parser)
{
    if (arg_parser->IsOptionSet(kEnumGpuIndices))
    {
        // This API Generator is requiring a restricted output that is specific to
        // this generator.
        restricting_output_      = true;
        output_enum_gpu_indices_ = true;
    }
    return true;
}

void InfoD3d12Feature::RegisterDecodeComponents(decode::FileProcessor& file_processor)
{
    dx12_decoder_.AddConsumer(&dx12_detection_consumer_);
    dx12_decoder_.AddConsumer(&dx12_consumer_);
    file_processor.AddDecoder(&dx12_decoder_);
}

std::string InfoD3d12Feature::GetEnumGpuIndicesText()
{
    gfxrecon::graphics::dx12::IDXGIFactory1ComPtr factory1   = nullptr;
    std::string                                   return_val = "";

    HRESULT result = CreateDXGIFactory1(IID_PPV_ARGS(&factory1));

    if (SUCCEEDED(result))
    {
        gfxrecon::graphics::dx12::ActiveAdapterMap adapters{};
        gfxrecon::graphics::dx12::TrackAdapters(
            result, reinterpret_cast<void**>(&factory1.GetInterfacePtr()), adapters);

        return_val = "GPU index\tGPU name\tSubSys ID\n";
        for (size_t index = 0; index < adapters.size(); ++index)
        {
            for (auto adapter : adapters)
            {
                if (index == adapter.second.adapter_idx)
                {
                    std::string replay_adapter_str =
                        gfxrecon::util::WCharArrayToString(adapter.second.internal_desc.Description);

                    return_val += util::to_hex_fixed_width<uint32_t>(adapter.second.adapter_idx, false, false) + "\t" +
                                  replay_adapter_str + "\t" + std::to_string(adapter.second.internal_desc.SubSysId) +
                                  "\n";
                    break;
                }
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to enumerate GPU indices");
    }
    return return_val;
}

std::string InfoD3d12Feature::GetDriverInfoString()
{
    if (!driver_info_.empty())
    {
        return driver_info_;
    }
    else
    {
        return "Not available";
    }
}

std::string InfoD3d12Feature::GetDriverInfoText()
{
    std::string return_val = "\nDriver info:\n";
    if (driver_info_.length())
    {
        return_val += "\t" + driver_info_ + "\n";
    }
    else
    {
        return_val += "\tDriver info not available.\n\n";
    }
    return return_val;
}

std::string InfoD3d12Feature::AdapterTypeToString(format::AdapterType type)
{
    switch (type)
    {
        case format::AdapterType::kUnknownAdapter:
            return "Unknown type (DXGI 1.0)";
        case format::AdapterType::kSoftwareAdapter:
            return "Software";
        case format::AdapterType::kHardwareAdapter:
            return "Hardware";
        default:
            return "Unknown";
    }
}

std::string InfoD3d12Feature::GetRuntimeInfoText()
{
    format::Dx12RuntimeInfo runtime_info = dx12_consumer_.GetDx12RuntimeInfo();

    std::string runtime_src = "N/A";
    std::string runtime_ver = "N/A";

    if (util::platform::StringLength(runtime_info.src) > 0)
    {
        runtime_src = runtime_info.src;
        runtime_ver = std::to_string(runtime_info.version[0]) + "." + std::to_string(runtime_info.version[1]) + "." +
                      std::to_string(runtime_info.version[2]) + "." + std::to_string(runtime_info.version[3]);
    }

    std::string return_val = "D3D12 runtime info:\n";
    return_val += "\tVersion: " + runtime_ver + "\n";
    return_val += "\tSource: " + runtime_src + "\n\n";
    return return_val;
}

nlohmann::json InfoD3d12Feature::GetRuntimeInfoJson()
{
    format::Dx12RuntimeInfo runtime_info = dx12_consumer_.GetDx12RuntimeInfo();

    std::string runtime_src = "N/A";
    std::string runtime_ver = "N/A";

    if (util::platform::StringLength(runtime_info.src) > 0)
    {
        runtime_src = runtime_info.src;
        runtime_ver = std::to_string(runtime_info.version[0]) + "." + std::to_string(runtime_info.version[1]) + "." +
                      std::to_string(runtime_info.version[2]) + "." + std::to_string(runtime_info.version[3]);
    }

    return {
        { "version", runtime_ver },
        { "source", runtime_src },
    };
}

std::string InfoD3d12Feature::GetAdapterInfoText()
{
    std::string return_val = "D3D12 adapter info:\n";

    const auto& adapters = dx12_consumer_.GetAdapters();

    if (adapters.empty() == false)
    {
        std::unordered_map<int64_t, std::string> adapter_workload;
        dx12_consumer_.CalcAdapterWorkload(adapter_workload, adapters);

        for (const auto& adapter : adapters)
        {
            const int64_t luid = pack_luid(adapter);

            std::string adapter_workload_pct = "";

            if (adapter_workload.count(luid) > 0)
            {
                if (adapter_workload[luid] != "")
                {
                    adapter_workload_pct = "(" + adapter_workload[luid] + "% of GPU submissions)";
                }
            }
            else if (adapter_workload.size() > 0)
            {
                adapter_workload_pct = "(0% of GPU submissions)";
            }

            std::string adapter_type = AdapterTypeToString(graphics::dx12::ExtractAdapterType(adapter.extra_info));

            return_val +=
                "\tDescription: " + util::WCharArrayToString(adapter.Description) + " " + adapter_workload_pct + "\n";
            return_val += "\tVendor ID: " + util::to_hex_fixed_width<uint32_t>(adapter.VendorId) + "\n";
            return_val += "\tDevice ID: " + util::to_hex_fixed_width<uint32_t>(adapter.DeviceId) + "\n";
            return_val += "\tSubsys ID: " + util::to_hex_fixed_width<uint32_t>(adapter.SubSysId) + "\n";
            return_val += "\tRevision: " + std::to_string(adapter.Revision) + "\n";
            return_val += "\tDedicated Video Memory: " + std::to_string(adapter.DedicatedVideoMemory) + "\n";
            return_val += "\tDedicated System Memory: " + std::to_string(adapter.DedicatedSystemMemory) + "\n";
            return_val += "\tShared System Memory: " + std::to_string(adapter.SharedSystemMemory) + "\n";
            return_val += "\tLUID LowPart: " + util::to_hex_fixed_width<uint32_t>(adapter.LuidLowPart) + "\n";
            return_val += "\tLUID HighPart: " + util::to_hex_fixed_width<int32_t>(adapter.LuidHighPart) + "\n";
            return_val += "\tAdapter type: " + adapter_type + "\n\n";
        }
    }
    else
    {
        return_val += "\tAdapter info not available.\n\n";
    }
    return return_val;
}

nlohmann::json InfoD3d12Feature::GetAdapterInfoJson()
{
    const auto&    adapters      = dx12_consumer_.GetAdapters();
    nlohmann::json adapters_json = nlohmann::json::array();

    if (!adapters.empty())
    {
        std::unordered_map<int64_t, std::string> adapter_workload;
        dx12_consumer_.CalcAdapterWorkload(adapter_workload, adapters);

        for (const auto& adapter : adapters)
        {
            const int64_t luid = (static_cast<uint64_t>(adapter.LuidHighPart) << 32) | adapter.LuidLowPart;

            std::string adapter_workload_pct = "";

            if (adapter_workload.count(luid) > 0)
            {
                if (adapter_workload[luid] != "")
                {
                    adapter_workload_pct = "(" + adapter_workload[luid] + "% of GPU submissions)";
                }
            }
            else if (adapter_workload.size() > 0)
            {
                adapter_workload_pct = "(0% of GPU submissions)";
            }

            std::string adapter_type = AdapterTypeToString(graphics::dx12::ExtractAdapterType(adapter.extra_info));

            nlohmann::json json_adapter;
            json_adapter["description"]["details"]          = util::WCharArrayToString(adapter.Description);
            json_adapter["description"]["workload-percent"] = adapter_workload_pct;
            json_adapter["vendor-id"]                       = adapter.VendorId;
            json_adapter["device-id"]                       = adapter.DeviceId;
            json_adapter["subsys-id"]                       = adapter.SubSysId;
            json_adapter["revision"]                        = adapter.Revision;
            auto& memory                                    = json_adapter["memory"];
            memory["dedicated"]["video"]                    = adapter.DedicatedVideoMemory;
            memory["dedicated"]["system"]                   = adapter.DedicatedSystemMemory;
            memory["shared"]                                = adapter.SharedSystemMemory;
            memory["luid"]["low"]                           = adapter.LuidLowPart;
            memory["luid"]["high"]                          = adapter.LuidHighPart;
            json_adapter["adapter-type"]                    = adapter_type;
            adapters_json.push_back(json_adapter);
        }
    }

    return adapters_json;
}

std::string InfoD3d12Feature::GetSwapchainInfoText()
{
    std::string return_val = "D3D12 swapchain info:\n";

    if (dx12_consumer_.FoundSwapchainInfo())
    {
        return_val += "\tDimensions: " + dx12_consumer_.GetSwapchainDimensionsString() + "\n\n";
    }
    else
    {
        return_val += "\tDimensions not available.\n\n";
    }

    return return_val;
}

nlohmann::json InfoD3d12Feature::GetSwapchainInfoJson()
{
    auto [width, height] = dx12_consumer_.GetSwapchainDimensions();
    return { "dimensions", { { "width", width }, { "height", height } } };
}

std::string InfoD3d12Feature::GetDxrEiInfoText()
{
    std::string return_val = "D3D12 EI workload: ";
    return_val += std::string(dx12_consumer_.ContainsEiWorkload() ? "yes" : "no") + "\n";
    return_val += "D3D12 DXR workload: " + std::string(dx12_consumer_.ContainsDxrWorkload() ? "yes" : "no") + "\n";

    if (dx12_consumer_.ContainsEiWorkload() || dx12_consumer_.ContainsDxrWorkload())
    {
        return_val +=
            "D3D12 DXR/EI optimized: " + std::string(dx12_consumer_.ContainsOptFillMem() ? "yes" : "no") + "\n";
    }
    return_val += "\n";
    return return_val;
}

nlohmann::json InfoD3d12Feature::GetDxrEiInfoJson()
{
    return {
        { "ei-workload", dx12_consumer_.ContainsEiWorkload() ? "yes" : "no" },
        { "dxr-workload", dx12_consumer_.ContainsDxrWorkload() ? "yes" : "no" },
        { "dxr/ei-optimized",
          ((dx12_consumer_.ContainsEiWorkload() || dx12_consumer_.ContainsDxrWorkload()) &&
           dx12_consumer_.ContainsOptFillMem())
              ? "yes"
              : "no" },
    };
}

std::string InfoD3d12Feature::GenerateText()
{
    std::string return_val = "";

    if (restricting_output_ && output_enum_gpu_indices_)
    {
        return_val = GetEnumGpuIndicesText();
    }
    else
    {
        if (dx12_consumer_.GetDXGITestPresentCount() > 0 && uses_frame_markers_ == false)
        {
            return_val += "\tTest present count: " + std::to_string(dx12_consumer_.GetDXGITestPresentCount()) + "\n";
        }

        return_val += GetDriverInfoText();
        return_val += GetRuntimeInfoText();
        return_val += GetAdapterInfoText();
        return_val += GetSwapchainInfoText();
        return_val += GetDxrEiInfoText();
    }
    return return_val;
}

nlohmann::json InfoD3d12Feature::GenerateJson()
{
    nlohmann::json d3d12_json;

    if (dx12_consumer_.GetDXGITestPresentCount() > 0 && uses_frame_markers_ == false)
    {
        d3d12_json["total-present-count"] = dx12_consumer_.GetDXGITestPresentCount();
    }

    d3d12_json["driver"]   = GetDriverInfoString();
    d3d12_json["runtime"]  = GetRuntimeInfoJson();
    d3d12_json["adapters"] = GetAdapterInfoJson();
    if (dx12_consumer_.FoundSwapchainInfo())
    {
        d3d12_json["swapchain"] = GetSwapchainInfoJson();
    }
    d3d12_json["dxr-ei"] = GetDxrEiInfoJson();

    return d3d12_json;
}

uint32_t InfoD3d12Feature::GetBlankFrameCount()
{
    return dx12_consumer_.GetDummyFrameCount();
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT
