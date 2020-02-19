/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

    virtual void DispatchStateBeginMarker(uint64_t frame_number) {}

    virtual void DispatchStateEndMarker(uint64_t frame_number) {}

    virtual void DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message) {}

    virtual void DispatchFillMemoryCommand(
        format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data)
    {}

    virtual void DispatchResizeWindowCommand(format::ThreadId thread_id,
                                             format::HandleId surface_id,
                                             uint32_t         width,
                                             uint32_t         height)
    {}

    virtual void DispatchCreateHardwareBufferCommand(format::ThreadId                                    thread_id,
                                                     format::HandleId                                    memory_id,
                                                     uint64_t                                            buffer_id,
                                                     uint32_t                                            format,
                                                     uint32_t                                            width,
                                                     uint32_t                                            height,
                                                     uint32_t                                            stride,
                                                     uint32_t                                            usage,
                                                     uint32_t                                            layers,
                                                     const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
    {}

    virtual void DispatchDestroyHardwareBufferCommand(format::ThreadId thread_id, uint64_t buffer_id) {}

    virtual void DispatchSetDeviceMemoryPropertiesCommand(format::ThreadId thread_id,
                                                          format::HandleId physical_device_id,
                                                          uint32_t         memory_type_count,
                                                          const std::vector<format::DeviceMemoryType>& memory_types,
                                                          uint32_t memory_heap_count,
                                                          const std::vector<format::DeviceMemoryHeap>& memory_heaps)
    {}

    virtual void DispatchSetSwapchainImageStateCommand(format::ThreadId thread_id,
                                                       format::HandleId device_id,
                                                       format::HandleId swapchain_id,
                                                       uint32_t         last_presented_image,
                                                       const std::vector<format::SwapchainImageStateInfo>& image_state)
    {}

    virtual void DispatchBeginResourceInitCommand(format::ThreadId thread_id,
                                                  format::HandleId device_id,
                                                  uint64_t         max_resource_size,
                                                  uint64_t         max_copy_size)
    {}

    virtual void DispatchEndResourceInitCommand(format::ThreadId thread_id, format::HandleId device_id) {}

    virtual void DispatchInitBufferCommand(format::ThreadId thread_id,
                                           format::HandleId device_id,
                                           format::HandleId buffer_id,
                                           uint64_t         data_size,
                                           const uint8_t*   data)
    {}

    virtual void DispatchInitImageCommand(format::ThreadId             thread_id,
                                          format::HandleId             device_id,
                                          format::HandleId             image_id,
                                          uint64_t                     data_size,
                                          uint32_t                     aspect,
                                          uint32_t                     layout,
                                          const std::vector<uint64_t>& level_sizes,
                                          const uint8_t*               data)
    {}
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_API_DECODE_DECODER_H
