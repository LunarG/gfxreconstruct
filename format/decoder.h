/*
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

#ifndef BRIMSTONE_DECODER_H
#define BRIMSTONE_DECODER_H

#include <string>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/api_call_id.h"
#include "format/format.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class Decoder
{
  public:
    virtual ~Decoder() {}

    virtual bool SupportsApiCall(ApiCallId id) = 0;

    virtual void
    DecodeFunctionCall(ApiCallId id, const ApiCallOptions& call_options, const uint8_t* buffer, size_t buffer_size) = 0;

    virtual void DispatchDisplayMessageCommand(const std::string& message) {}

    virtual void DispatchFillMemoryCommand(uint64_t pointer_id, uint64_t offset, uint64_t size, const uint8_t* data) {}

    virtual void DispatchResizeWindowCommand(HandleId surface_id, uint32_t width, uint32_t height) {}
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_DECODER_H
