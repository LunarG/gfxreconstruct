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

#ifndef GFXRECON_INFO_OPENXR_INTERFACE_H
#define GFXRECON_INFO_OPENXR_INTERFACE_H

#if ENABLE_OPENXR_SUPPORT

#include "info_api_interface.h"

#include "decode/openxr_detection_consumer.h"
#include "decode/openxr_stats_consumer.h"
#include "generated/generated_openxr_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

class InfoOpenXrInterface : public InfoApiInterface
{
  public:
    InfoOpenXrInterface() : openxr_detection_consumer_() {}
    virtual ~InfoOpenXrInterface() = default;

    // Simple "getter" style methods
    format::ApiFamilyId ApiFamilyId() const override { return format::ApiFamilyId::ApiFamily_OpenXR; }
    std::string         ApiLabel() const override { return "OpenXR"; }
    bool                ApiWasDetected() override { return openxr_detection_consumer_.WasOpenXrAPIDetected(); }
    std::string         ApiCompiledHeaderVersionString() const override;

    // Method to register this API's decoder elements with the containers
    // FileProcessor
    void RegisterApiDecodeComponents(gfxrecon::decode::FileProcessor& file_processor) override;

    // Output methods
    void           PrintInfo() override;
    nlohmann::json GenerateJson() override;

  private:
    std::string GetVersionString(XrVersion api_version);

    gfxrecon::decode::OpenXrDetectionConsumer openxr_detection_consumer_;
    gfxrecon::decode::OpenXrStatsConsumer     openxr_stats_consumer_;
    gfxrecon::decode::OpenXrDecoder           openxr_decoder_;
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_INFO_OPENXR_INTERFACE_H
