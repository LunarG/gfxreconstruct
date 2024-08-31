/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_MARKER_JSON_CONSUMER_BASE_H
#define GFXRECON_DECODE_MARKER_JSON_CONSUMER_BASE_H

#include "util/defines.h"
#include "format/format_json.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// Template shim for turning markers into json using a JsonWriter pointed to by
// a protected pointer called writer_ in a base class.
template <class Base>
class MarkerJsonConsumer : public Base
{
  public:
    virtual void ProcessStateBeginMarker(uint64_t frame_number)
    {
        this->writer_->WriteMarker(format::kNameState, "BeginMarker", frame_number);
    }
    virtual void ProcessStateEndMarker(uint64_t frame_number)
    {
        this->writer_->WriteMarker(format::kNameState, "EndMarker", frame_number);
    }

    virtual void ProcessFrameBeginMarker(uint64_t frame_number)
    {
        this->writer_->WriteMarker(format::kNameFrame, "BeginMarker", frame_number);
    }

    virtual void ProcessFrameEndMarker(uint64_t frame_number)
    {
        this->writer_->WriteMarker(format::kNameFrame, "EndMarker", frame_number);
    }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_MARKER_JSON_CONSUMER_BASE_H
