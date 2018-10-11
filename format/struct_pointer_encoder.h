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

#ifndef BRIMSTONE_STRUCT_POINTER_ENCODER_H
#define BRIMSTONE_STRUCT_POINTER_ENCODER_H

#include "format/custom_struct_encoders.h"
#include "format/parameter_encoder.h"
#include "format/platform_types.h"
#include "util/defines.h"

#include "generated/generated_struct_encoders.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

template <typename T>
void encode_struct_ptr(format::ParameterEncoder* encoder, const T* value)
{
    encoder->EncodeStructPtrPreamble(value);
    if (value != nullptr)
    {
        encode_struct(encoder, *value);
    }
}

template <typename T>
void encode_struct_array(format::ParameterEncoder* encoder, const T* value, size_t len)
{
    encoder->EncodeStructArrayPreamble(value, len);
    if ((value != nullptr) && (len > 0))
    {
        for (size_t i = 0; i < len; ++i)
        {
            encode_struct(encoder, value[i]);
        }
    }
}

BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_STRUCT_POINTER_ENCODER_H
