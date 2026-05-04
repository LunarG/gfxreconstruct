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

#include "decode/info_consumer.h"
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

    // Method to register this feature's decoder elements with the containers
    // FileProcessor
    virtual void RegisterDecodeComponents(decode::FileProcessor&      file_processor,
                                          const decode::InfoConsumer& info_consumer) = 0;

    // Output methods
    virtual std::string    GenerateText() = 0;
    virtual nlohmann::json GenerateJson() = 0;
};

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INFO_FEATURE_H
