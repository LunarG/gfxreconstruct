/*
** Copyright (c) 2024 LunarG, Inc. All rights reserved.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_OPENXR_DETECTION_CONSUMER_H
#define GFXRECON_DECODE_OPENXR_DETECTION_CONSUMER_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "decode/openxr_consumer_base.h"
#include "util/defines.h"
#include "generated/generated_openxr_consumer.h"

#include "openxr/openxr.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr int kMaxOpenXrBlockLimit = 1000;

class OpenXrDetectionConsumer : public OpenXrConsumer
{
  public:
    OpenXrDetectionConsumer() {}
    bool         WasOpenXrAPIDetected() { return openxr_consumer_usage_; }
    virtual void Process_xrCreateSession(const ApiCallInfo&         call_info,
                                         XrResult                   returnValue,
                                         gfxrecon::format::HandleId instance,
                                         StructPointerDecoder<Decoded_XrSessionCreateInfo>*,
                                         HandlePointerDecoder<XrSession>*) override
    {
        openxr_consumer_usage_ = true;
    }
    virtual bool IsComplete(uint64_t block_index) override
    {
        return (block_index > kMaxOpenXrBlockLimit) || WasOpenXrAPIDetected();
    }

  private:
    static int const kMaxOpenXrBlockLimit = 1000;
    bool             openxr_consumer_usage_{ false };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_DETECTION_CONSUMER_H
