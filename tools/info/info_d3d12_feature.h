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

#ifndef GFXRECON_INFO_D3D12_FEATURE_H
#define GFXRECON_INFO_D3D12_FEATURE_H

#if defined(D3D12_SUPPORT)

#include "info_feature.h"

#include "decode/dx12_detection_consumer.h"
#include "decode/dx12_stats_consumer.h"
#include "generated/generated_dx12_decoder.h"
#include "graphics/dx12_util.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

class InfoD3d12Feature : public InfoFeature
{
  public:
    InfoD3d12Feature() : dx12_detection_consumer_(decode::Dx12DetectionConsumer::kNoBlockLimit) {}
    virtual ~InfoD3d12Feature() = default;

    // Simple "getter" style methods
    std::string Label() const override { return "D3D12"; }
    bool        WasDetected() override { return dx12_detection_consumer_.WasD3D12APIDetected(); }
    std::string CompiledHeaderVersionString() const override;
    uint32_t    GetBlankFrameCount() override;

    // Output methods
    std::string    GenerateText() override;
    nlohmann::json GenerateJson() override;

    // Method to register this feature's decoder elements with the containers
    // FileProcessor
    void RegisterDecodeComponents(decode::FileProcessor&      file_processor,
                                  const decode::InfoConsumer& info_consumer) override;

  private:
    std::string AdapterTypeToString(format::AdapterType type);
    std::string GetDriverInfoString();

    std::string GetDriverInfoText();
    std::string GetSwapchainInfoText();
    std::string GetRuntimeInfoText();
    std::string GetAdapterInfoText();
    std::string GetDxrEiInfoText();

    nlohmann::json GetRuntimeInfoJson();
    nlohmann::json GetAdapterInfoJson();
    nlohmann::json GetSwapchainInfoJson();
    nlohmann::json GetDxrEiInfoJson();

    bool                          output_enum_gpu_indices_{ false };
    decode::Dx12DetectionConsumer dx12_detection_consumer_;
    decode::Dx12StatsConsumer     dx12_consumer_;
    decode::Dx12Decoder           dx12_decoder_;
    decode::FileProcessor*        file_processor_{ nullptr };
    const decode::InfoConsumer*   info_consumer_{ nullptr };
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT

#endif // GFXRECON_INFO_D3D12_FEATURE_H
