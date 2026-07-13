/*
** Copyright (c) 2020-2026 LunarG, Inc.
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

#ifndef GFXRECON_OPTIMIZE_VULKAN_FEATURE_H
#define GFXRECON_OPTIMIZE_VULKAN_FEATURE_H

#include "optimize_feature.h"

#include "decode/vulkan_detection_consumer.h"
#include "format/format.h"
#include "generated/generated_vulkan_decoder.h"

#include <memory>
#include <string>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(optimize)

class OptimizeVulkanFeature : public OptimizeFeature
{
  public:
    OptimizeVulkanFeature()           = default;
    ~OptimizeVulkanFeature() override = default;

    std::string Label() const override { return "Vulkan"; }
    std::string CompiledHeaderVersionString() const override;

    void RegisterDetectionDecoder(decode::FileProcessor& file_processor, uint64_t block_limit) override;
    bool WasDetected() const override;
    bool ShouldRun(const util::ArgumentParser& args) const override;
    bool Optimize(const std::string&          input_filename,
                  const std::string&          output_filename,
                  const util::ArgumentParser& args) override;

  private:
    // Pass 1: collect handles that were never referenced in a command buffer submission.
    bool GetUnreferencedResources(const std::string&                    input_filename,
                                  std::unordered_set<format::HandleId>& unreferenced_ids);

    // Passes 2-3: determine unreferenced block indices, then write the filtered output file.
    bool FilterUnreferencedResources(const std::string&                          input_filename,
                                     const std::string&                          output_filename,
                                     const std::unordered_set<format::HandleId>& unreferenced_ids);

    std::unique_ptr<decode::VulkanDetectionConsumer> detection_consumer_;
    std::unique_ptr<decode::VulkanDecoder>           detection_decoder_;
};

GFXRECON_END_NAMESPACE(optimize)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_OPTIMIZE_VULKAN_FEATURE_H
