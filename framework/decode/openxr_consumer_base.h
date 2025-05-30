/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_OPENXR_CONSUMER_BASE_H
#define GFXRECON_DECODE_OPENXR_CONSUMER_BASE_H

#if ENABLE_OPENXR_SUPPORT

#include "decode/common_consumer_base.h"
#include "decode/api_decoder.h"
#include "decode/custom_openxr_struct_decoders.h"
#include "decode/openxr_enum_util.h"
#include "format/platform_types.h"
#include "util/defines.h"

#include "openxr/openxr.h"

#include <numeric>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class OpenXrConsumerBase : public CommonConsumerBase
{
  public:
    OpenXrConsumerBase() {}

    virtual ~OpenXrConsumerBase() {}

    virtual void
    Process_xrInitializeLoaderKHR(const ApiCallInfo&                                           call_info,
                                  XrResult                                                     returnValue,
                                  StructPointerDecoder<Decoded_XrLoaderInitInfoBaseHeaderKHR>* loaderInitInfo)
    {}

    virtual void Process_xrCreateApiLayerInstance(const ApiCallInfo&                                  call_info,
                                                  XrResult                                            returnValue,
                                                  StructPointerDecoder<Decoded_XrInstanceCreateInfo>* info,
                                                  StructPointerDecoder<Decoded_XrApiLayerCreateInfo>* layerInfo,
                                                  HandlePointerDecoder<XrInstance>*                   instance)
    {}
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_CONSUMER_BASE_H
