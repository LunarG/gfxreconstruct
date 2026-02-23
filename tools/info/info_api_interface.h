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

#ifndef GFXRECON_INFO_API_INTERFACE_H
#define GFXRECON_INFO_API_INTERFACE_H

#include "decode/file_processor.h"
#include "format/format.h"
#include "util/argument_parser.h"
#include "util/defines.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

enum class FrameMarkerTypes : std::uint32_t
{
    kImplicit = 0,
    kExplicit,
};

class InfoApiInterface
{
  public:
    enum class InfoOutputLevel : std::uint32_t
    {
        kBasic = 0,
        kExeInfo,
        kApplicationInfo,
        EnvironmentInfo,
        FileInfo,

        // API-specific reserved section
        kApiSpecific_1 = 250,
        kApiSpecific_2,
        kApiSpecific_3,
        kApiSpecific_4,
        kApiSpecific_5,

        kVerbose = 9999
    };

    virtual ~InfoApiInterface() = default;

    // Simple "getter" style methods
    virtual format::ApiFamilyId ApiFamilyId()            = 0;
    virtual std::string         ApiLabel()               = 0;
    virtual std::string         ApiHeaderVersionString() = 0;
    virtual bool                ApiWasDetected()         = 0;

    // This indicates that the API has output that should be executed WITHOUT any
    // other API outputing.  This is usually the case where the user asked to
    // get some API-specific info only.
    bool ApiOutputOverrideDetected() { return api_output_override_; }

    // API-specific command-line methods (default is do nothing and return true if required)
    virtual void UpdatePossibleCommandLineOptionsArgs(std::string& options, std::string& arguments) {}
    virtual void UpdateCommandLineUsage(std::string& usage) {}
    virtual bool CheckCommandLine(std::shared_ptr<gfxrecon::util::ArgumentParser> arg_parser) { return true; }

    // Method to register this API's decoder elements with the containers
    // FileProcessor
    virtual void RegisterApiDecodeComponents(gfxrecon::decode::FileProcessor& file_processor) = 0;

    // Output methods
    void         SetOutputLevel(InfoOutputLevel output_level) { info_output_level_ = output_level; }
    virtual void OutputInfo() = 0;

    // Frame-specific methods
    virtual void             GetFrameStart()       = 0;
    virtual FrameMarkerTypes GetFrameMarkerType()  = 0;
    virtual uint32_t         GetActualFrameCount() = 0;
    virtual uint32_t         GetBlankFrameCount()  = 0;
    uint32_t                 GetTotalFrameCount() { return GetActualFrameCount() + GetBlankFrameCount(); }

  protected:
    bool            api_output_override_{ false };
    InfoOutputLevel info_output_level_{ InfoOutputLevel::kBasic };
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INFO_API_INTERFACE_H
