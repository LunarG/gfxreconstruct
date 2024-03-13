/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
** Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_CUSTOM_OPENXR_ENCODER_COMMANDS_H
#define GFXRECON_ENCODE_CUSTOM_OPENXR_ENCODER_COMMANDS_H

#include "encode/openxr_capture_manager.h"
#include "format/api_call_id.h"
#include "util/defines.h"

#if ENABLE_OPENXR_SUPPORT

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <format::ApiCallId Id>
struct CustomEncoderPreCall
{
    template <typename... Args>
    static void Dispatch(OpenXrCaptureManager*, Args...)
    {}
};

template <format::ApiCallId Id>
struct CustomEncoderPostCall
{
    template <typename... Args>
    static void Dispatch(OpenXrCaptureManager*, Args...)
    {}

    template <typename... Args>
    static void Dispatch(OpenXrCaptureManager*, XrResult, Args...)
    {}
};

// Dispatch custom command to initialize capture at instance creation.
template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateInstance>
{
    template <typename... Args>
    static void Dispatch(OpenXrCaptureManager*, XrResult result, Args...)
    {
        OpenXrCaptureManager::CheckXrCreateInstanceStatus(result);
    }
};

// Dispatch custom command to finalize capture at instance destruction.
template <>
struct CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyInstance>
{
    template <typename... Args>
    static void Dispatch(OpenXrCaptureManager*, Args...)
    {
        OpenXrCaptureManager::DestroyInstance();
    }
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif //  ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_ENCODE_CUSTOM_OPENXR_ENCODER_COMMANDS_H
