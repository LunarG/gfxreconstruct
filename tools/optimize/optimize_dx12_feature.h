/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_OPTIMIZE_DX12_FEATURE_H
#define GFXRECON_OPTIMIZE_DX12_FEATURE_H

#if defined(D3D12_SUPPORT)

#include "optimize_feature.h"

#include "decode/dx12_detection_consumer.h"
#include "decode/dx12_optimize_options.h"
#include "generated/generated_dx12_decoder.h"

#include <memory>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(optimize)

class OptimizeDx12Feature : public OptimizeFeature
{
  public:
    OptimizeDx12Feature()           = default;
    ~OptimizeDx12Feature() override = default;

    std::string Label() const override { return "D3D12"; }
    std::string CompiledHeaderVersionString() const override;

    void RegisterDetectionDecoder(decode::FileProcessor& file_processor, uint64_t block_limit) override;
    bool WasDetected() const override;
    bool ShouldRun(const util::ArgumentParser& args) const override;
    bool Optimize(const std::string&          input_filename,
                  const std::string&          output_filename,
                  const util::ArgumentParser& args) override;

    // Command-line options and arguments
    // -------------------------------------
    std::vector<util::FeatureOptionDesc> GetOptionDescs() const override;

  private:
    decode::Dx12OptimizationOptions BuildOptions(const util::ArgumentParser& args) const;

    std::unique_ptr<decode::Dx12DetectionConsumer> detection_consumer_;
    std::unique_ptr<decode::Dx12Decoder>           detection_decoder_;
};

GFXRECON_END_NAMESPACE(optimize)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT

#endif // GFXRECON_OPTIMIZE_DX12_FEATURE_H
