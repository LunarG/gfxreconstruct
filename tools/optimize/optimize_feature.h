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

#ifndef GFXRECON_OPTIMIZE_FEATURE_H
#define GFXRECON_OPTIMIZE_FEATURE_H

#include "decode/file_processor.h"
#include "util/argument_parser.h"
#include "util/defines.h"
#include "util/feature_base.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(optimize)

class OptimizeFeature : public util::FeatureBase
{
  public:
    // Block-limit sentinels for the two-phase detection pass. Values match the
    // kDefaultBlockLimit / kNoBlockLimit constants on both VulkanDetectionConsumer and
    // Dx12DetectionConsumer, so main.cpp doesn't need to include those headers.
    static constexpr uint64_t kDefaultDetectionBlockLimit = 1000;
    static constexpr uint64_t kNoDetectionBlockLimit      = 0;

    // Registers this feature's detection decoder with the given FileProcessor.
    // Pass kDefaultDetectionBlockLimit for the initial quick scan; if nothing is
    // detected, call again with kNoDetectionBlockLimit for a full-file scan.
    virtual void RegisterDetectionDecoder(decode::FileProcessor& file_processor, uint64_t block_limit) = 0;

    // Returns true if this feature's API was present in the capture.
    virtual bool WasDetected() const = 0;

    // Returns true if this feature should run given the parsed CLI args.
    // Automatic mode: delegates to WasDetected().
    // Manual mode: returns true if the feature's own flags are explicitly set.
    virtual bool ShouldRun(const util::ArgumentParser& args) const = 0;

    // Runs the optimization, managing all internal passes. Returns true on success.
    virtual bool Optimize(const std::string&          input_filename,
                          const std::string&          output_filename,
                          const util::ArgumentParser& args) = 0;

    // Command-line options and arguments come from util::FeatureBase::GetOptionDescs(). The
    // functions in tools/tool_feature_options.h collect them, validate the values, and print
    // the synopsis fragments and the usage sections.
};

GFXRECON_END_NAMESPACE(optimize)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_OPTIMIZE_FEATURE_H
