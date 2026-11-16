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

#if defined(D3D12_SUPPORT)

#include "optimize_dx12_feature.h"

#include "tool_settings.h"

#include "dx12_optimize_util.h"
#include "util/api_version_info.h"
#include "util/feature_module_registry.h"
#include "util/logging.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(optimize)

GFXR_UTIL_REGISTER_FEATURE_CREATOR(OptimizeFeature, OptimizeDx12Feature)

std::string OptimizeDx12Feature::CompiledHeaderVersionString() const
{
    return util::GetD3D12SdkVersionString();
}

// D3D12-specific CLI flag names, private to this translation unit.
constexpr char kD3d12PsoRemoval[]             = "--d3d12-pso-removal";
constexpr char kD3d12ResourceRemoval[]        = "--d3d12-resource-removal";
constexpr char kDx12OptimizeDxr[]             = "--dxr";
constexpr char kDx12OptimizeDxrExperimental[] = "--dxr-experimental";

void OptimizeDx12Feature::RegisterDetectionDecoder(decode::FileProcessor& file_processor, uint64_t block_limit)
{
    // Destroy decoder before consumer: decoder holds a raw pointer to consumer.
    detection_decoder_.reset();
    detection_consumer_ = std::make_unique<decode::Dx12DetectionConsumer>(block_limit);
    detection_decoder_  = std::make_unique<decode::Dx12Decoder>();
    detection_decoder_->AddConsumer(detection_consumer_.get());
    file_processor.AddDecoder(detection_decoder_.get());
}

bool OptimizeDx12Feature::WasDetected() const
{
    return detection_consumer_ != nullptr && detection_consumer_->WasD3D12APIDetected();
}

bool OptimizeDx12Feature::ShouldRun(const util::ArgumentParser& args) const
{
    bool manual_mode = args.IsOptionSet(kDx12OptimizeDxr) || args.IsOptionSet(kDx12OptimizeDxrExperimental) ||
                       args.IsOptionSet(kD3d12PsoRemoval) || args.IsOptionSet(kD3d12ResourceRemoval);
    return manual_mode || WasDetected();
}

std::vector<util::FeatureOptionDesc> OptimizeDx12Feature::GetOptionDescs() const
{
    return { { "", { "Remove creation of unreferenced PSOs." }, false, kD3d12PsoRemoval },
             { "",
               { "Remove initialization of unreferenced resources (experimental,", "off by default)." },
               false,
               kD3d12ResourceRemoval },
             { "", { "Optimize for DXR and ExecuteIndirect replay." }, false, kDx12OptimizeDxr },
             // The experimental form of --dxr has no description, so it stays out of the usage text.
             { "", {}, false, kDx12OptimizeDxrExperimental },
             { "<index>",
               { "Use the specified device for the optimizer replay, where index is",
                 "the zero-based index to the array of adapters that",
                 "IDXGIFactory1::EnumAdapters1 returns. The optimizer replay can fail",
                 "when the specified device is not compatible with the original",
                 "capture devices." },
               true,
               kOverrideGpuArgument } };
}

decode::Dx12OptimizationOptions OptimizeDx12Feature::BuildOptions(const util::ArgumentParser& args) const
{
    decode::Dx12OptimizationOptions options{};
    options.optimize_resource_values              = args.IsOptionSet(kDx12OptimizeDxr);
    options.optimize_resource_values_experimental = args.IsOptionSet(kDx12OptimizeDxrExperimental);
    options.remove_redundant_psos                 = args.IsOptionSet(kD3d12PsoRemoval);
    options.remove_redundant_resources            = args.IsOptionSet(kD3d12ResourceRemoval);

    if (options.optimize_resource_values_experimental)
    {
        GFXRECON_WRITE_CONSOLE("Running experimental DXR optimization. This mode is experimental, and should only "
                               "be used if --dxr did not produce a valid capture file.");
        options.optimize_resource_values = true;
    }

    const auto& gpu_override = args.GetArgumentValue(kOverrideGpuArgument);
    if (!gpu_override.empty())
    {
        options.override_gpu_index = std::stoi(gpu_override);
    }

    // Automatic mode: no flags explicitly set, enable all stable defaults.
    if (!options.optimize_resource_values && !options.remove_redundant_psos && !options.remove_redundant_resources)
    {
        options.optimize_resource_values = true;
        options.remove_redundant_psos    = true;
        // remove_redundant_resources is experimental and intentionally left false.
    }

    return options;
}

bool OptimizeDx12Feature::Optimize(const std::string&          input_filename,
                                   const std::string&          output_filename,
                                   const util::ArgumentParser& args)
{
    decode::Dx12OptimizationOptions options = BuildOptions(args);
    return Dx12OptimizeFile(input_filename, output_filename, options);
}

GFXRECON_END_NAMESPACE(optimize)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT
