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

// The structure Encode Action. The pilot begins with one field idiom: a value-shaped scalar is read from the
// API-declared structure and encoded using the wire type selected by the Field's logical kind.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H

#include "encode/parameter_encoder.h"
#include "schema/field.h"

// This operation reads native Vulkan structures. Keep the complete generated member-binding population beside the
// Action and private to the translation unit that owns the generic EncodeStruct instantiations.
#include "generated/generated_vulkan_schema_native_struct_members.h"

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class EncodeStructAction
{
  public:
    explicit EncodeStructAction(ParameterEncoder* encoder) : encoder_(encoder) {}

    template <typename Field, typename Storage>
    requires schema::ScalarField<Field> && schema::HasMember<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        encoder_->template Encode<typename Field::api_type::kind>(schema::Get(storage, field));
    }

  private:
    ParameterEncoder* encoder_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
