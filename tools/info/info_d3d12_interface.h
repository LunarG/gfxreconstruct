/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_INFO_D3D12_INTERFACE_H
#define GFXRECON_INFO_D3D12_INTERFACE_H

#if defined(D3D12_SUPPORT)

#include "info_api_interface.h"

#include "decode/dx12_detection_consumer.h"
#include "decode/dx12_stats_consumer.h"
#include "generated/generated_dx12_decoder.h"
#include "graphics/dx12_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

class InfoD3d12Interface : public InfoApiInterface
{
  public:
    InfoD3d12Interface() : dx12_detection_consumer_(gfxrecon::decode::Dx12DetectionConsumer::kNoBlockLimit) {}
    virtual ~InfoD3d12Interface() = default;

    // Simple "getter" style methods
    format::ApiFamilyId ApiFamilyId() const override { return format::ApiFamilyId::ApiFamily_D3D12; }
    std::string         ApiLabel() const override { return "D3D12"; }
    bool                ApiWasDetected() override { return dx12_detection_consumer_.WasD3D12APIDetected(); }
    std::string         ApiCompiledHeaderVersionString() const override;
    uint32_t            GetBlankFrameCount() const override;

    // API-specific command-line methods (default is do nothing and return true if required)
    void UpdateValidCommandLineOptionsArgs(std::string& options, std::string& arguments) override;
    void OutputCommandLineUsage() override;
    bool CheckCommandLine(gfxrecon::util::ArgumentParser* arg_parser) override;

    // Method to register this API's decoder elements with the containers
    // FileProcessor
    void RegisterApiDecodeComponents(gfxrecon::decode::FileProcessor& file_processor) override;

    // Output methods%s
    void           PrintInfo() override;
    nlohmann::json GenerateJson() override;

  private:
    std::string AdapterTypeToString(gfxrecon::format::AdapterType type);
    std::string GetDriverInfoString();

    void PrintEnumGpuIndices();
    void PrintDriverInfoText();
    void PrintSwapchainInfoText();
    void PrintRuntimeInfoText();
    void PrintAdapterInfoText();
    void PrintDxrEiInfoText();

    nlohmann::json GetRuntimeInfoJson();
    nlohmann::json GetAdapterInfoJson();
    nlohmann::json GetSwapchainInfoJson();
    nlohmann::json GetDxrEiInfoJson();

    const InfoApiInterface::InfoOutputLevel kD3d12EnumGpuDevices = InfoApiInterface::InfoOutputLevel::kApiSpecific_1;

    gfxrecon::decode::Dx12DetectionConsumer dx12_detection_consumer_;
    gfxrecon::decode::Dx12StatsConsumer     dx12_consumer_;
    gfxrecon::decode::Dx12Decoder           dx12_decoder_;
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT

#endif // GFXRECON_INFO_D3D12_INTERFACE_H
