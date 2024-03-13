/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_STRUCT_POINTER_ENCODER_H
#define GFXRECON_ENCODE_STRUCT_POINTER_ENCODER_H

#include "encode/custom_openxr_struct_encoders.h"
#include "encode/custom_vulkan_struct_encoders.h"
#include "encode/parameter_encoder.h"
#include "format/platform_types.h"
#include "generated/generated_openxr_struct_encoders.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename T>
void EncodeStructPtr(ParameterEncoder* encoder, const T* value, bool omit_data = false, bool omit_addr = false)
{
    encoder->EncodeStructPtrPreamble(value, omit_data, omit_addr);

    if ((value != nullptr) && !omit_data)
    {
        EncodeStruct(encoder, *value);
    }
}

template <typename T>
void EncodeStructArray(
    ParameterEncoder* encoder, const T* value, size_t len, bool omit_data = false, bool omit_addr = false)
{
    encoder->EncodeStructArrayPreamble(value, len, omit_data, omit_addr);

    if ((value != nullptr) && (len > 0) && !omit_data)
    {
        for (size_t i = 0; i < len; ++i)
        {
            EncodeStruct(encoder, value[i]);
        }
    }
}

template <typename T>
void EncodeStructArray2D(ParameterEncoder* encoder,
                         const T* const*   value,
                         size_t            m,
                         size_t            n,
                         bool              omit_data = false,
                         bool              omit_addr = false)
{
    encoder->EncodeStructArray2DPreamble(value, m, omit_data, omit_addr);

    if ((value != nullptr) && (m > 0) && !omit_data)
    {
        for (size_t i = 0; i < m; ++i)
        {
            encoder->EncodeStructArrayPreamble(value[i], n, omit_data, omit_addr);
            for (size_t j = 0; j < n; ++j)
            {
                EncodeStruct(encoder, value[i][j]);
            }
        }
    }
}

template <typename T, typename SizeT>
typename std::enable_if<!std::is_integral<SizeT>::value>::type EncodeStructArray2D(ParameterEncoder* encoder,
                                                                                   const T* const*   value,
                                                                                   const SizeT&      size_2d,
                                                                                   bool              omit_data = false,
                                                                                   bool              omit_addr = false)
{
    const size_t outer_len = size_2d.size();
    encoder->EncodeStructArray2DPreamble(value, outer_len, omit_data, omit_addr);

    if ((value != nullptr) && (outer_len > 0))
    {
        for (size_t i = 0; i < outer_len; ++i)
        {
            const size_t inner_len = size_2d[i];
            encoder->EncodeStructArrayPreamble(value[i], inner_len, omit_data, omit_addr);
            for (size_t j = 0; j < inner_len; ++j)
            {
                EncodeStruct(encoder, value[i][j]);
            }
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_STRUCT_POINTER_ENCODER_H
