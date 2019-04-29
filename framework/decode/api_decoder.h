/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_API_DECODE_DECODER_H
#define GFXRECON_API_DECODE_DECODER_H

#include "format/api_call_id.h"
#include "format/format.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct ApiCallInfo
{
    format::ThreadId thread_id{ 0 };
    uint64_t         timestamp{ 0 };
};

class ApiDecoder
{
  public:
    virtual ~ApiDecoder() {}

    virtual bool SupportsApiCall(format::ApiCallId id) = 0;

    virtual void DecodeFunctionCall(format::ApiCallId  id,
                                    const ApiCallInfo& call_info,
                                    const uint8_t*     buffer,
                                    size_t             buffer_size) = 0;

    virtual void DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message) {}

    virtual void DispatchFillMemoryCommand(
        format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data)
    {}

    virtual void DispatchResizeWindowCommand(format::ThreadId thread_id,
                                             format::HandleId surface_id,
                                             uint32_t         width,
                                             uint32_t         height)
    {}
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_API_DECODE_DECODER_H
