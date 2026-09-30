/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_OPENXR_DECODER_BASE_H
#define GFXRECON_DECODE_OPENXR_DECODER_BASE_H

#if ENABLE_OPENXR_SUPPORT

#include "decode/api_decoder.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_openxr_consumer.h"
#include "util/defines.h"
#include "decoder_util.h"

#include "openxr/openxr.h"

#include <algorithm>
#include <vector>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class OpenXrDecoderBase : public ApiDecoder
{
  public:
    OpenXrDecoderBase() {}

    virtual ~OpenXrDecoderBase() override {}

    void AddConsumer(OpenXrConsumer* consumer) { consumers_.push_back(consumer); }

    void RemoveConsumer(OpenXrConsumer* consumer)
    {
        consumers_.erase(std::remove(consumers_.begin(), consumers_.end(), consumer));
    }

    virtual void WaitIdle() override;

    virtual bool IsComplete(uint64_t block_index) override
    {
        return decode::IsComplete<OpenXrConsumer*>(consumers_, block_index);
    }

    virtual bool SupportsApiCall(format::ApiCallId call_id) override
    {
        return (format::GetApiCallFamily(call_id) == format::ApiFamilyId::ApiFamily_OpenXR);
    }

    virtual bool SupportsMetaDataId(format::MetaDataId meta_data_id) override
    {
        // For backwards compatibility, an encoded API of ApiFamily_None indicates the OpenXr API.
        format::ApiFamilyId api = format::GetMetaDataApi(meta_data_id);
        return (api == format::ApiFamilyId::ApiFamily_None) || (api == format::ApiFamilyId::ApiFamily_OpenXR);
    }

    virtual void DispatchStateBeginMarker(uint64_t frame_number) override;

    virtual void DispatchStateEndMarker(uint64_t frame_number) override;

    virtual void DispatchFrameEndMarker(uint64_t frame_number) override;

    virtual void DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message) override;

    virtual void DispatchSetEnvironmentVariablesCommand(const format::SetEnvironmentVariablesCommand& header,
                                                        const char* env_string) override;

    virtual void SetCurrentBlockIndex(uint64_t block_index) override;

    virtual void DispatchViewRelativeLocation(format::ThreadId                    thread_id,
                                              const format::ViewRelativeLocation& location) override;

    // Unused stubs
    virtual void DecodeFunctionCall(format::ApiCallId  call_id,
                                    const ApiCallInfo& call_options,
                                    const uint8_t*     parameter_buffer,
                                    size_t             buffer_size) override
    {}

  protected:
    const std::vector<OpenXrConsumer*>& GetConsumers() const { return consumers_; }

    size_t Decode_xrEnumerateSwapchainImages(const ApiCallInfo& call_info,
                                             const uint8_t*     parameter_buffer,
                                             size_t             buffer_size);
    size_t Decode_xrPollEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

  private:
    std::vector<OpenXrConsumer*> consumers_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_DECODER_BASE_H
