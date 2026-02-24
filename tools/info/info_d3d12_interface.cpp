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

#include "info_d3d12_interface.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

const char kEnumGpuIndices[] = "--enum-gpu-indices";

void InfoD3d12Interface::UpdatePossibleCommandLineOptionsArgs(std::string& options, std::string& arguments)
{
    options += " ";
    options += kEnumGpuIndices;
}

void InfoD3d12Interface::UpdateCommandLineUsage(std::string& usage)
{
    usage += "\n// D3D12-specific\n";
    usage += std::format("  {}\tPrint GPU indices and exit\n", kEnumGpuIndices);
}

bool InfoD3d12Interface::CheckCommandLine(std::shared_ptr<gfxrecon::util::ArgumentParser> arg_parser)
{
    if (arg_parser->IsOptionSet(kEnumGpuIndices))
    {
        // Indicate we need an API-specific overrid, and set the output to only show the necessary info
        api_output_override_ = true;
        info_output_level_   = kD3d12EnumGpuDevices;
    }
}

void InfoD3d12Interface::RegisterApiDecodeComponents(gfxrecon::decode::FileProcessor& file_processor)
{
    dx12_decoder_.AddConsumer(&dx12_detection_consumer_);
    dx12_decoder_.AddConsumer(&dx12_consumer_);
    file_processor.AddDecoder(&dx12_decoder_);
}

void InfoD3d12Interface::OutputEnumGpuIndices()
{
    IDXGIFactory1* factory1 = nullptr;

    HRESULT result = CreateDXGIFactory1(IID_IDXGIFactory1, reinterpret_cast<void**>(&factory1));

    if (SUCCEEDED(result))
    {
        gfxrecon::graphics::dx12::ActiveAdapterMap adapters{};
        gfxrecon::graphics::dx12::TrackAdapters(result, reinterpret_cast<void**>(&factory1), adapters);

        WriteOutput("GPU index\tGPU name\tSubSys ID");
        for (size_t index = 0; index < adapters.size(); ++index)
        {
            for (auto adapter : adapters)
            {
                if (index == adapter.second.adapter_idx)
                {
                    std::string replay_adapter_str =
                        gfxrecon::util::WCharArrayToString(adapter.second.internal_desc.Description);

                    WriteOutput("%-9x\t%s\t%u",
                                adapter.second.adapter_idx,
                                replay_adapter_str.c_str(),
                                adapter.second.internal_desc.SubSysId);
                    break;
                }
            }
        }
        factory1->Release();
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to enumerate GPU indices");
    }
}

void InfoD3d12Interface::OutputInfo()
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
        case InfoApiInterface::InfoOutputLevel::kD3d12EnumGpuDevices:
            OutputEnumGpuIndices();
            break;
        case InfoApiInterface::InfoOutputLevel::kVerbose:
            break;
        default:
            break;
    }
}

uint32_t InfoD3d12Interface::GetFrameStart()
{
    return 0; // TODO
}

uint32_t GetBlankFrameCount()
{
    return dx12_consumer_.GetDummyFrameCount();
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT
