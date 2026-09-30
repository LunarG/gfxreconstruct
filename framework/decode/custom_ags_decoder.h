/*
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_CUSTOM_AGS_DECODER_H
#define GFXRECON_CUSTOM_AGS_DECODER_H

#include "api_decoder.h"
#include "custom_ags_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class AgsDecoder : public ApiDecoder
{
  public:
    AgsDecoder() {}
    virtual ~AgsDecoder() override {}

    virtual void WaitIdle() override {}

    virtual bool IsComplete(uint64_t block_index) override;

    void AddConsumer(AgsConsumerBase* consumer) { consumers_.push_back(consumer); }

    virtual bool SupportsApiCall(format::ApiCallId call_id) override;

    virtual bool SupportsMetaDataId(format::MetaDataId meta_data_id) override { return false; }

    virtual void SetCurrentBlockIndex(uint64_t block_index) override {}

    virtual void DecodeFunctionCall(format::ApiCallId  call_id,
                                    const ApiCallInfo& call_options,
                                    const uint8_t*     parameter_buffer,
                                    size_t             buffer_size) override;

    virtual void DecodeMethodCall(format::ApiCallId  call_id,
                                  format::HandleId   object_id,
                                  const ApiCallInfo& call_options,
                                  const uint8_t*     parameter_buffer,
                                  size_t             buffer_size) override
    {}

  protected:
    const std::vector<AgsConsumerBase*>& GetConsumers() const { return consumers_; }

  private:
    size_t Decode_agsInitialize(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_agsDeInitialize(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_agsDriverExtensionsDX12_CreateDevice_620(const ApiCallInfo& call_info,
                                                           const uint8_t*     parameter_buffer,
                                                           size_t             buffer_size);
    size_t Decode_agsDriverExtensionsDX12_CreateDevice_601(const ApiCallInfo& call_info,
                                                           const uint8_t*     parameter_buffer,
                                                           size_t             buffer_size);
    size_t Decode_agsDriverExtensionsDX12_DestroyDevice(const ApiCallInfo& call_info,
                                                        const uint8_t*     parameter_buffer,
                                                        size_t             buffer_size);
    size_t
    Decode_agsCheckDriverVersion(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t
    Decode_agsGetVersionNumber(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_agsSetDisplayMode(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_agsDriverExtensionsDX12_PushMarker(const ApiCallInfo& call_info,
                                                     const uint8_t*     parameter_buffer,
                                                     size_t             buffer_size);
    size_t Decode_agsDriverExtensionsDX12_PopMarker(const ApiCallInfo& call_info,
                                                    const uint8_t*     parameter_buffer,
                                                    size_t             buffer_size);
    size_t Decode_agsDriverExtensionsDX12_SetMarker(const ApiCallInfo& call_info,
                                                    const uint8_t*     parameter_buffer,
                                                    size_t             buffer_size);

    std::vector<AgsConsumerBase*> consumers_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
