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

// A handle's API type descriptor to its capture wrapper. The design places this fact on the descriptor as
// capture_wrapper_type; naming an encode-side wrapper from the public types header would pull the wrapper headers
// into every includer, so it is an encode-private trait keyed on the descriptor instead. Hand-written rows for the
// handle types the migrated structures use, while the list is hand-written; at inversion the mapping is generated,
// or the wrappers themselves become specializations keyed on the descriptor, and this header retires.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_CAPTURE_WRAPPERS_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_CAPTURE_WRAPPERS_H

#include "encode/vulkan_handle_wrappers.h"
#include "generated/generated_vulkan_schema_types.h"
#include "schema/field.h"
#include "util/defines.h"

#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Declared, not defined, so an absent row is an incomplete type and HasCaptureWrapper reads as unsatisfied.
template <typename ApiType>
struct CaptureWrapperFor;

template <typename ApiType>
using CaptureWrapperType = typename CaptureWrapperFor<ApiType>::type;

template <typename ApiType>
concept HasCaptureWrapper = requires
{
    typename CaptureWrapperFor<ApiType>::type;
};

// One row per mapped handle type. The static_assert holds the row to the descriptor: the wrapper named must wrap
// the handle type the descriptor describes.
#define GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(Handle, Wrapper)                                                    \
    template <>                                                                                                 \
    struct CaptureWrapperFor<schema::vulkan::api_types::Handle>                                                 \
    {                                                                                                           \
        using type = vulkan_wrappers::Wrapper;                                                                  \
        static_assert(std::is_same_v<type::HandleType, schema::ElementType<schema::vulkan::api_types::Handle>>, \
                      "The wrapper's handle type must be the descriptor's element type");                       \
    }

GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkBuffer, BufferWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkCommandBuffer, CommandBufferWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkDeviceMemory, DeviceMemoryWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkPhysicalDevice, PhysicalDeviceWrapper);
GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR(VkSemaphore, SemaphoreWrapper);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_CAPTURE_WRAPPERS_H
