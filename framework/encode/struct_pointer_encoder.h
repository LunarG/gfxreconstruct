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

#ifndef GFXRECON_ENCODE_STRUCT_POINTER_ENCODER_H
#define GFXRECON_ENCODE_STRUCT_POINTER_ENCODER_H

#include "encode/custom_vulkan_struct_encoders.h"
#include "encode/parameter_encoder.h"
#include "format/platform_types.h"
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

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_STRUCT_POINTER_ENCODER_H
