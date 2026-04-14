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

#ifndef GFXRECON_INFO_FEATURE_H
#define GFXRECON_INFO_FEATURE_H

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

class InfoFeature
{
  public:
    virtual ~InfoFeature() = default;

    // Simple "getter" style methods
    virtual std::string Label() const = 0;
    virtual bool        WasDetected() = 0;
    virtual std::string CompiledHeaderVersionString() const { return ""; }
    virtual uint32_t    GetBlankFrameCount() { return 0; }
    virtual uint32_t    GetFrameStart() const { return 0; }
    virtual bool        DesiresSingleLineFrameOutput() const { return false; }

    // A few "setter" style methods
    virtual void SetDriverInfoString(const std::string& driver_info) { driver_info_ = driver_info; }

    // API-specific command-line methods (default is do nothing and return true if required)
    virtual void UpdateValidCommandLineOptionsArgs(std::string& options, std::string& arguments)
    {
        GFXRECON_UNREFERENCED_PARAMETER(options);
        GFXRECON_UNREFERENCED_PARAMETER(arguments);
    }
    virtual std::string GetCommandLineUsage() { return ""; }
    virtual bool        CheckCommandLine(util::ArgumentParser* arg_parser)
    {
        GFXRECON_UNREFERENCED_PARAMETER(arg_parser);
        return true;
    }

    // Method to register this feature's decoder elements with the containers
    // FileProcessor
    void RegisterDecodeComponents(decode::FileProcessor* file_processor)
    {
        file_processor_ = file_processor;
        RegisterInternalDecodeComponents(file_processor);
    }

    // Indicates that this API generator requires an API-specific output
    bool RestrictingOutput() { return restricting_output_; }

    // Output methods
    virtual std::string    GenerateText() = 0;
    virtual nlohmann::json GenerateJson() = 0;

  protected:
    virtual void RegisterInternalDecodeComponents(decode::FileProcessor* file_processor) = 0;

    decode::FileProcessor* file_processor_{ nullptr };
    std::string            driver_info_;
    bool                   restricting_output_{ false };
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INFO_FEATURE_H
