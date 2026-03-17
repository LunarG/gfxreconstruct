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

#ifndef GFXRECON_INFO_API_GENERATOR_H
#define GFXRECON_INFO_API_GENERATOR_H

#include "decode/file_processor.h"
#include "format/format.h"
#include "util/argument_parser.h"
#include "util/defines.h"

#include <nlohmann/json.hpp>

#include <functional>
#include <iomanip>
#include <memory>
#include <sstream>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

class InfoApiGenerator
{
  public:
    virtual ~InfoApiGenerator() = default;

    // Simple "getter" style methods
    virtual format::ApiFamilyId ApiFamilyId() const = 0;
    virtual std::string         ApiLabel() const    = 0;
    virtual bool                ApiWasDetected()    = 0;
    virtual std::string         ApiCompiledHeaderVersionString() const { return ""; }
    virtual uint32_t            GetBlankFrameCount() { return 0; }
    virtual uint32_t            GetFrameStart() const { return 0; }
    virtual bool                ApiDesiresSingleLineFrameOutput() const { return false; }

    // A few "setter" style methods
    virtual void SetFrameMarkerUsage(bool found) { uses_frame_markers_ = found; }
    virtual void SetDriverInfoString(const std::string& driver_info) { driver_info_ = driver_info; }

    // API-specific command-line methods (default is do nothing and return true if required)
    virtual void UpdateValidCommandLineOptionsArgs(std::string& options, std::string& arguments)
    {
        GFXRECON_UNREFERENCED_PARAMETER(options);
        GFXRECON_UNREFERENCED_PARAMETER(arguments);
    }
    virtual std::string GetCommandLineUsage() { return ""; }
    virtual bool        CheckCommandLine(gfxrecon::util::ArgumentParser* arg_parser)
    {
        GFXRECON_UNREFERENCED_PARAMETER(arg_parser);
        return true;
    }

    // Method to register this API's decoder elements with the containers
    // FileProcessor
    virtual void RegisterApiDecodeComponents(gfxrecon::decode::FileProcessor& file_processor) = 0;

    // Indicates that this API generator requires an API-specific output
    bool RestrictingOutput() { return restricting_output_; }

    // Output methods
    virtual std::string    GenerateText() = 0;
    virtual nlohmann::json GenerateJson() = 0;

  protected:
    bool        uses_frame_markers_{ false };
    std::string driver_info_;
    bool        restricting_output_{ false };
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INFO_API_GENERATOR_H
