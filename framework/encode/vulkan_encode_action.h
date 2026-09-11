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

// The structure Encode Action: one Apply overload set, applied to a schema's Fields by schema::WalkFields over the
// API's own structure. Each overload reads a member and encodes it with the wire type its Field's logical kind
// selects; the Action names kinds and never widths.

#ifndef GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
#define GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H

#include "encode/parameter_encoder.h"
#include "schema/field.h"

// This operation reads native Vulkan structures. Keep the complete generated member-binding population beside the
// Action and private to the translation unit that owns the generic EncodeStruct instantiations.
#include "generated/generated_vulkan_schema_native_struct_members.h"

#include "util/defines.h"

#include <cstddef>
#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class EncodeStructAction
{
  public:
    explicit EncodeStructAction(ParameterEncoder* encoder) : encoder_(encoder) {}

    // A value-shaped scalar. Read through Get, which serves an ordinary member and a bitfield alike, so one overload
    // covers both.
    template <typename Field, typename Storage>
    requires schema::ScalarField<Field> && schema::HasMember<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        encoder_->template Encode<typename Field::api_type::kind>(schema::Get(storage, field));
    }

    // A fixed-extent array of scalars, of one or two dimensions. Every named fixed-array entry point, the 2DMatrix
    // family included, is one EncodeArray over a flat pointer and a length, so a matrix is a run of the extent
    // product and the two ranks share a body. The extents come from the API member's declared type, as they do on
    // the decode side, so the schema needs no extent for this.
    template <typename Field, typename Storage>
    requires schema::ScalarKindField<Field> && schema::StaticArrayField<Field> && schema::Addressable<Storage, Field>
    void Apply(Field field, const Storage& storage)
    {
        const auto& array_ref = schema::GetRef(storage, field);
        using ArrayType       = std::remove_cvref_t<decltype(array_ref)>;

        static_assert(std::is_array_v<ArrayType>,
                      "A StaticArray field must be declared as an array in the API type it belongs to");
        static_assert(std::rank_v<ArrayType> <= 2, "The encoder writes fixed arrays of one and two dimensions only");

        constexpr size_t count =
            std::extent_v<ArrayType, 0> * (std::rank_v<ArrayType> == 2 ? std::extent_v<ArrayType, 1> : 1);

        if constexpr (std::rank_v<ArrayType> == 2)
        {
            encoder_->template EncodeArray<typename Field::api_type::kind>(&array_ref[0][0], count);
        }
        else
        {
            encoder_->template EncodeArray<typename Field::api_type::kind>(&array_ref[0], count);
        }
    }

  private:
    ParameterEncoder* encoder_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_ENCODE_ACTION_H
