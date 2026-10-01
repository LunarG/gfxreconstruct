/*
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

#ifndef GFXRECON_STAT_DECODER_BASE_H
#define GFXRECON_STAT_DECODER_BASE_H

#include "decode/api_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/stat_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/*
** This class implements the ApiDecoder interface
** Its main purpose is to decode non api application info
*/
class StatDecoderBase : public ApiDecoder
{
  public:
    StatDecoderBase() {}

    ~StatDecoderBase() {}

    virtual bool IsComplete(uint64_t block_index) override;

    virtual void WaitIdle() override{};

    void AddConsumer(StatConsumerBase* consumer) { consumers_.push_back(consumer); }

    virtual bool SupportsApiCall(format::ApiCallId id) override { return true; }

    virtual bool SupportsMetaDataId(format::MetaDataId meta_data_id) override { return true; }

    virtual void DecodeFunctionCall(format::ApiCallId  id,
                                    const ApiCallInfo& call_info,
                                    const uint8_t*     buffer,
                                    size_t             buffer_size) override
    {}

    virtual void DecodeMethodCall(format::ApiCallId  call_id,
                                  format::HandleId   object_id,
                                  const ApiCallInfo& call_options,
                                  const uint8_t*     parameter_buffer,
                                  size_t             buffer_size) override
    {}

    virtual void DispatchStateBeginMarker(uint64_t frame_number) override;

  private:
    std::vector<StatConsumerBase*> consumers_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_STAT_DECODER_BASE_H
