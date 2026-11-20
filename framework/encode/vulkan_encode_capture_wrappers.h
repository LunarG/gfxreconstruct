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

// CaptureWrapperOf maps a handle's API element to its capture wrapper. It is an encode-only trait, not a member of the
// API element: a wrapper type in generated_vulkan_schema_types.h would pull encode/vulkan_handle_wrappers.h into
// every includer.
//
// This header declares the template and nothing more. The specializations, one per handle, are in
// generated/generated_vulkan_capture_wrapper_of.h, which is the header encode code includes.
// NOTE: a translation unit that evaluates ApiElementWithCaptureWrapper before including that header gets false,
// silently, and the compiler is not required to diagnose the late specialization.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_CAPTURE_WRAPPERS_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_CAPTURE_WRAPPERS_H

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Declared, not defined: a handle API element with no specialization does not satisfy ApiElementWithCaptureWrapper.
template <typename ApiType>
struct CaptureWrapperOf;

template <typename ApiType>
concept ApiElementWithCaptureWrapper = requires
{
    typename CaptureWrapperOf<ApiType>::type;
};

template <ApiElementWithCaptureWrapper ApiType>
using CaptureWrapperOf_t = typename CaptureWrapperOf<ApiType>::type;

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_CAPTURE_WRAPPERS_H
