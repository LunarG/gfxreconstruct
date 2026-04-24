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

#ifndef GFXRECON_CONVERT_FEATURE_H
#define GFXRECON_CONVERT_FEATURE_H

#include "util/strings.h"

#include "decode/file_processor.h"
#include "decode/json_writer.h"
#include "decode/marker_json_consumer.h"
#include "decode/metadata_json_consumer.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(convert)

class ConvertFeature
{
  public:
    virtual ~ConvertFeature() = default;

    // Simple "getter" style methods
    virtual std::string Label() = 0;

    // Method to register this feature's decoder elements with the containers
    // FileProcessor
    virtual void RegisterDecodeComponents(gfxrecon::decode::FileProcessor& file_processor) = 0;

    // Method to register/unregister this the json writer with the json consumer
    virtual void RegisterJsonWriter(gfxrecon::decode::JsonWriter* json_writer) = 0;
    virtual void UnregisterJsonWriter()                                        = 0;
};

GFXRECON_END_NAMESPACE(convert)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CONVERT_FEATURE_H
