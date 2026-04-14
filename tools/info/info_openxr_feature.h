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

#ifndef GFXRECON_INFO_OPENXR_FEATURE_H
#define GFXRECON_INFO_OPENXR_FEATURE_H

#if ENABLE_OPENXR_SUPPORT

#include "info_feature.h"

#include "decode/openxr_detection_consumer.h"
#include "decode/openxr_stats_consumer.h"
#include "generated/generated_openxr_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

class InfoOpenXrFeature : public InfoFeature
{
  public:
    InfoOpenXrFeature() : openxr_detection_consumer_() {}
    virtual ~InfoOpenXrFeature() = default;

    // Simple "getter" style methods
    std::string Label() const override { return "OpenXR"; }
    bool        WasDetected() override { return openxr_detection_consumer_.WasOpenXrAPIDetected(); }
    std::string CompiledHeaderVersionString() const override;

    // Output methods
    std::string    GenerateText() override;
    nlohmann::json GenerateJson() override;

  protected:
    // Method to register this feature's decoder elements with the containers
    // FileProcessor
    void RegisterInternalDecodeComponents(decode::FileProcessor* file_processor) override;

  private:
    std::string GetVersionString(XrVersion api_version);

    decode::OpenXrDetectionConsumer openxr_detection_consumer_;
    decode::OpenXrStatsConsumer     openxr_stats_consumer_;
    decode::OpenXrDecoder           openxr_decoder_;
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_INFO_OPENXR_FEATURE_H
