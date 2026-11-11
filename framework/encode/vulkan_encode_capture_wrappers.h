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

// CaptureWrapperOf maps a handle's API element to its capture wrapper, vulkan_wrappers::<Stem>Wrapper, where Stem is
// the handle name without its Vk prefix. The inventory visitor below emits one specialization per handle. It is an
// encode-only trait, not a member of the API element: naming the wrappers in generated_vulkan_schema_types.h would
// pull encode/vulkan_handle_wrappers.h into every includer.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_CAPTURE_WRAPPERS_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_CAPTURE_WRAPPERS_H

#include "encode/vulkan_handle_wrappers.h"
#include "generated/generated_vulkan_schema_types.h"
#include "schema/field.h"
#include "util/defines.h"

#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Declared, not defined: for a handle API element without a specialization, ApiElementWithCaptureWrapper is false, and
// no EncoderAdapter handle overload accepts its Field.
template <typename ApiType>
struct CaptureWrapperOf;

template <typename ApiType>
concept ApiElementWithCaptureWrapper = requires
{
    typename CaptureWrapperOf<ApiType>::type;
};

template <ApiElementWithCaptureWrapper ApiType>
using CaptureWrapperOf_t = typename CaptureWrapperOf<ApiType>::type;

#define GFXRECON_VULKAN_CAPTURE_WRAPPER_OF(Handle, Wrapper)                                                        \
    template <>                                                                                                    \
    struct CaptureWrapperOf<schema::vulkan::api_elements::Handle>                                                  \
    {                                                                                                              \
        using type = vulkan_wrappers::Wrapper;                                                                     \
        static_assert(std::is_same_v<type::HandleType, schema::ApiTypeOf_t<schema::vulkan::api_elements::Handle>>, \
                      "The wrapper's handle type must be the API element's element_type");                         \
    }

#define GFXRECON_INVENTORY_VISIT_HANDLE(Name, Stem) GFXRECON_VULKAN_CAPTURE_WRAPPER_OF(Name, Stem##Wrapper);
#include "generated/generated_vulkan_inventory.h"

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_CAPTURE_WRAPPERS_H
