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

#include "info_d3d12_generator.h"

#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

// Static boolean that runs a lambda to automatically create and register this class with the
// base class RegisterGenerator method.
static bool sRegisterThisGenerator = []() {
    InfoApiGenerator::RegisterGenerator([]() { return std::make_unique<InfoD3d12Generator>(); });
    return true;
}();

const char kEnumGpuIndices[] = "--enum-gpu-indices";

std::string InfoD3d12Generator::ApiCompiledHeaderVersionString() const
{
#if defined(D3D12SDKVersion)
    return std::string("  D3D12 SDK Version      ") + D3D12SDKVersion;
#else
    return "";
#endif
}

void InfoD3d12Generator::UpdateValidCommandLineOptionsArgs(std::string& options, std::string& arguments)
{
    options += " ";
    options += kEnumGpuIndices;
}

void InfoD3d12Generator::OutputCommandLineUsage()
{
    WriteOutput("\n// D3D12-specific\n");
    WriteOutput(std::string("  ") + kEnumGpuIndices + "\tPrint GPU indices and exit\n");
}

bool InfoD3d12Generator::CheckCommandLine(util::ArgumentParser* arg_parser)
{
    if (arg_parser->IsOptionSet(kEnumGpuIndices))
    {
        output_flags_ = InfoApiGenerator::OutputSelectionFlags::kApiSpecific_1;
    }
    return true;
}

void InfoD3d12Generator::RegisterApiDecodeComponents(decode::FileProcessor& file_processor)
{
    dx12_decoder_.AddConsumer(&dx12_detection_consumer_);
    dx12_decoder_.AddConsumer(&dx12_consumer_);
    file_processor.AddDecoder(&dx12_decoder_);
}

void InfoD3d12Generator::PrintEnumGpuIndices()
{
    IDXGIFactory1* factory1 = nullptr;

    HRESULT result = CreateDXGIFactory1(IID_PPV_ARGS(&factory1));

    if (SUCCEEDED(result))
    {
        gfxrecon::graphics::dx12::ActiveAdapterMap adapters{};
        gfxrecon::graphics::dx12::TrackAdapters(
            result, reinterpret_cast<void**>(&factory1.GetInterfacePtr()), adapters);

        WriteOutput("GPU index\tGPU name\tSubSys ID");
        for (size_t index = 0; index < adapters.size(); ++index)
        {
            for (auto adapter : adapters)
            {
                if (index == adapter.second.adapter_idx)
                {
                    std::string replay_adapter_str = util::WCharArrayToString(adapter.second.internal_desc.Description);

                    WriteOutput(util::to_hex_fixed_width<uint32_t>(adapter.second.adapter_idx, false, false) + "\t" +
                                replay_adapter_str + "\t" + std::to_string(adapter.second.internal_desc.SubSysId));
                    break;
                }
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to enumerate GPU indices");
    }
}

std::string InfoD3d12Generator::GetDriverInfoString()
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

void InfoD3d12Generator::PrintDriverInfoText()
{
    WriteOutput("");
    WriteOutput("Driver info:");
    if (driver_info_.length())
    {
        WriteOutput(std::string("\t") + driver_info_);
    }
    else
    {
        WriteOutput("\tDriver info not available.");
        WriteOutput("");
    }
}

std::string InfoD3d12Generator::AdapterTypeToString(format::AdapterType type)
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

void InfoD3d12Generator::PrintRuntimeInfoText()
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

    WriteOutput("D3D12 runtime info:");
    WriteOutput(std::string("\tVersion: ") + runtime_ver);
    WriteOutput(std::string("\tSource: ") + runtime_src);
    WriteOutput("");
}

nlohmann::json InfoD3d12Generator::GetRuntimeInfoJson()
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

void InfoD3d12Generator::PrintAdapterInfoText()
{
    WriteOutput("D3D12 adapter info:");

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

            WriteOutput(std::string("\tDescription: ") + util::WCharArrayToString(adapter.Description) + " " +
                        adapter_workload_pct);
            WriteOutput(std::string("\tVendor ID: ") + util::to_hex_fixed_width<uint32_t>(adapter.VendorId));
            WriteOutput(std::string("\tDevice ID: ") + util::to_hex_fixed_width<uint32_t>(adapter.DeviceId));
            WriteOutput(std::string("\tSubsys ID: ") + util::to_hex_fixed_width<uint32_t>(adapter.SubSysId));
            WriteOutput(std::string("\tRevision: ") + std::to_string(adapter.Revision));
            WriteOutput(std::string("\tDedicated Video Memory: ") + std::to_string(adapter.DedicatedVideoMemory));
            WriteOutput(std::string("\tDedicated System Memory: ") + std::to_string(adapter.DedicatedSystemMemory));
            WriteOutput(std::string("\tShared System Memory: ") + std::to_string(adapter.SharedSystemMemory));
            WriteOutput(std::string("\tLUID LowPart: ") + util::to_hex_fixed_width<uint32_t>(adapter.LuidLowPart));
            WriteOutput(std::string("\tLUID HighPart: ") + util::to_hex_fixed_width<int32_t>(adapter.LuidHighPart));
            WriteOutput(std::string("\tAdapter type: ") + adapter_type);
            WriteOutput("");
        }
    }
    else
    {
        WriteOutput("\tAdapter info not available.");
        WriteOutput("");
    }
}

nlohmann::json InfoD3d12Generator::GetAdapterInfoJson()
{
    const auto&    adapters      = dx12_consumer_.GetAdapters();
    nlohmann::json adapters_json = nlohmann::json::array();

    if (!adapters.empty())
    {
        std::unordered_map<int64_t, std::string> adapter_workload;
        dx12_consumer_.CalcAdapterWorkload(adapter_workload, adapters);

        for (const auto& adapter : adapters)
        {
            const int64_t luid = (adapter.LuidHighPart << 31) | adapter.LuidLowPart;

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

void InfoD3d12Generator::PrintSwapchainInfoText()
{
    WriteOutput("D3D12 swapchain info:");

    if (dx12_consumer_.FoundSwapchainInfo())
    {
        WriteOutput(std::string("\tDimensions: ") + dx12_consumer_.GetSwapchainDimensionsString());
    }
    else
    {
        WriteOutput("\tDimensions not available.");
    }

    WriteOutput("");
}

nlohmann::json InfoD3d12Generator::GetSwapchainInfoJson()
{
    auto [width, height] = dx12_consumer_.GetSwapchainDimensions();
    return { "dimensions", { { "width", width }, { "height", height } } };
}

void InfoD3d12Generator::PrintDxrEiInfoText()
{
    if (dx12_consumer_.ContainsEiWorkload())
    {
        WriteOutput("D3D12 EI workload: yes");
    }
    else
    {
        WriteOutput("D3D12 EI workload: no");
    }

    WriteOutput("");

    if (dx12_consumer_.ContainsDxrWorkload())
    {
        WriteOutput("D3D12 DXR workload: yes");
    }
    else
    {
        WriteOutput("D3D12 DXR workload: no");
    }

    if (dx12_consumer_.ContainsEiWorkload() || dx12_consumer_.ContainsDxrWorkload())
    {
        WriteOutput("");

        if (dx12_consumer_.ContainsOptFillMem())
        {
            WriteOutput("D3D12 DXR/EI optimized: yes");
        }
        else
        {
            WriteOutput("D3D12 DXR/EI optimized: no");
        }
    }
}

nlohmann::json InfoD3d12Generator::GetDxrEiInfoJson()
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

void InfoD3d12Generator::PrintInfo()
{
    if (output_flags_ & InfoApiGenerator::OutputSelectionFlags::kApiSpecific_1)
    {
        PrintEnumGpuIndices();
    }

    // Output everything else, unless we're only supposed to output the
    // enum gpu indicies only.
    if (output_flags_ != InfoApiGenerator::OutputSelectionFlags::kApiSpecific_1)
    {
        if (dx12_consumer_.GetDXGITestPresentCount() > 0 && uses_frame_markers_ == false)
        {
            WriteOutput(std::string("\tTest present count: ") +
                        std::to_string(dx12_consumer_.GetDXGITestPresentCount()));
        }

        PrintDriverInfoText();
        PrintRuntimeInfoText();
        PrintAdapterInfoText();
        PrintSwapchainInfoText();
        PrintDxrEiInfoText();
    }
}

nlohmann::json InfoD3d12Generator::GenerateJson()
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

uint32_t InfoD3d12Generator::GetBlankFrameCount() const
{
    return dx12_consumer_.GetDummyFrameCount();
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT
