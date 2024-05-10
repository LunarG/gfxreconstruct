/*
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_DX12_DETECTION_CONSUMER_H
#define GFXRECON_DECODE_DX12_DETECTION_CONSUMER_H

#include "decode/api_decoder.h"
#include "decode/struct_pointer_decoder.h"
#if defined(WIN32)
#include "generated/generated_dx12_decoder.h"
#endif
#include "decode/stat_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12DetectionConsumer : public Dx12Consumer
{
  public:
    static const uint64_t kDefaultBlockLimit = 1000;
    static const uint64_t kNoBlockLimit      = 0;

    Dx12DetectionConsumer(uint64_t block_limit = kDefaultBlockLimit) :
        block_limit_(block_limit), dx12_consumer_usage_(false)
    {}
    bool         WasD3D12APIDetected() { return dx12_consumer_usage_; }
    virtual void Process_D3D12CreateDevice(const gfxrecon::decode::ApiCallInfo&           call_info,
                                           HRESULT                                        return_value,
                                           gfxrecon::format::HandleId                     pAdapter,
                                           D3D_FEATURE_LEVEL                              MinimumFeatureLevel,
                                           gfxrecon::decode::Decoded_GUID                 riid,
                                           gfxrecon::decode::HandlePointerDecoder<void*>* ppDevice)
    {
        dx12_consumer_usage_ = true;
    }

    virtual bool IsComplete(uint64_t block_index) override
    {
        return ((block_limit_ != kNoBlockLimit) && (block_index > block_limit_)) || WasD3D12APIDetected();
    }

  private:
    const uint64_t block_limit_;
    bool           dx12_consumer_usage_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_DETECTION_CONSUMER_H
