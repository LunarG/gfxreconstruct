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
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

// Fill writes synthetic values into an API structure by walking its Schema with FillAction. Test-only.
//
// FillAction leaves handles, extension chains, opaque and void pointers, unions and structures without Schema Fields at
// the caller's value: a null handle encodes as the null id with no capture wrapper registered, a chain's node types
// are known only from sType at run time, and a union's Schema lists Alternatives, not Fields.

#ifndef GFXRECON_TEST_SCHEMA_FILL_H
#define GFXRECON_TEST_SCHEMA_FILL_H

#include "generated/generated_vulkan_schema.h"
#include "generated/generated_vulkan_schema_api_struct_members.h"
#include "schema/field.h"
#include "schema/schema.h"
#include "util/defines.h"

#include <cstddef>
#include <memory>
#include <type_traits>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test)
GFXRECON_BEGIN_NAMESPACE(fill)

// Every scalar the filler writes, and every count it therefore produces. Small, so a nested run of runs stays small;
// not zero, so runs are not empty.
inline constexpr int kPattern = 2;

// Owns everything a filled structure points to, for the life of one test.
class FillContext
{
  public:
    template <typename T>
    T* Make(size_t count)
    {
        T* p = new T[count]();
        keep_.emplace_back(static_cast<void*>(p), [](void* q) { delete[] static_cast<T*>(q); });
        return p;
    }

    template <typename Char>
    const Char* MakeText()
    {
        Char* text = Make<Char>(3);
        text[0]    = static_cast<Char>('a');
        text[1]    = static_cast<Char>('b');
        text[2]    = static_cast<Char>(0);
        return text;
    }

  private:
    std::vector<std::shared_ptr<void>> keep_;
};

template <typename ApiElement, typename Storage>
void Fill(FillContext& context, Storage& storage);

template <typename T>
inline constexpr bool IsPatternable_v = std::is_arithmetic_v<T> || std::is_enum_v<T>;

class FillAction
{
  public:
    explicit FillAction(FillContext& context) : context_(context) {}

    template <typename Field, typename Storage>
    requires schema::ValueField<Field> && schema::FieldStoreFor<Storage, Field>
    void Apply(Field field, Storage& storage)
    {
        using Element = schema::ApiTypeOf_t<typename Field::api_element>;

        if constexpr (schema::StructApiElement<typename Field::api_element>)
        {
            if constexpr (schema::HasSchemaFields<typename Field::api_element> && schema::Addressable<Storage, Field>)
            {
                Fill<typename Field::api_element>(context_, schema::GetRef(storage, field));
            }
        }
        else if constexpr (schema::TextApiElement<typename Field::api_element>)
        {
            // A text typedef held by value, LPCWSTR: the API element is the pointer type the header spells.
            schema::Set(storage, field, context_.MakeText<std::remove_cv_t<std::remove_pointer_t<Element>>>());
        }
        else if constexpr (!schema::HandleApiElement<typename Field::api_element> && IsPatternable_v<Element>)
        {
            schema::Set(storage, field, static_cast<Element>(kPattern));
        }
    }

    template <typename Field, typename Storage>
    requires schema::PointerField<Field> && schema::FieldStoreFor<Storage, Field>
    void Apply(Field field, Storage& storage)
    {
        using Element = schema::ApiTypeOf_t<typename Field::api_element>;

        if constexpr (schema::TextApiElement<typename Field::api_element>)
        {
            schema::Set(storage, field, context_.MakeText<Element>());
        }
        else if constexpr (schema::OpaqueApiElement<typename Field::api_element> ||
                           schema::VoidApiElement<typename Field::api_element>)
        {
            // A pointer to an opaque object or to void: nothing to allocate, the address is the value and stays null.
        }
        else if constexpr (!std::is_void_v<Element>)
        {
            Element* one = context_.Make<Element>(1);
            FillElement<Field>(*one);
            schema::Set(storage, field, one);
        }
    }

    template <typename Field, typename Storage>
    requires schema::AnyCountedField<Field> && schema::FieldStoreFor<Storage, Field> &&
        schema::FieldWithLength<Storage, Field>
    void Apply(Field field, Storage& storage)
    {
        using Element      = schema::ApiTypeOf_t<typename Field::api_element>;
        const size_t count = static_cast<size_t>(schema::LengthOf_t<Field>::Get(storage));

        if constexpr (schema::PointerArrayField<Field>)
        {
            const Element** rows = context_.Make<const Element*>(count);
            for (size_t i = 0; i < count; ++i)
            {
                if constexpr (schema::TextApiElement<typename Field::api_element>)
                {
                    rows[i] = context_.MakeText<Element>();
                }
                else
                {
                    Element* one = context_.Make<Element>(1);
                    FillElement<Field>(*one);
                    rows[i] = one;
                }
            }
            schema::Set(storage, field, rows);
        }
        else if constexpr (schema::VoidApiElement<typename Field::api_element>)
        {
            // A counted run of bytes the API declares as void.
            uint8_t* bytes = context_.Make<uint8_t>(count);
            for (size_t i = 0; i < count; ++i)
            {
                bytes[i] = static_cast<uint8_t>(kPattern + i);
            }
            schema::Set(storage, field, bytes);
        }
        else
        {
            Element* run = context_.Make<Element>(count);
            for (size_t i = 0; i < count; ++i)
            {
                FillElement<Field>(run[i]);
            }
            schema::Set(storage, field, run);
        }
    }

    template <typename Field, typename Storage>
    requires schema::FixedArrayField<Field> && schema::Addressable<Storage, Field>
    void Apply(Field field, Storage& storage)
    {
        auto& array     = schema::GetRef(storage, field);
        using ArrayType = std::remove_cvref_t<decltype(array)>;

        if constexpr (schema::TextApiElement<typename Field::api_element>)
        {
            constexpr size_t extent = std::extent_v<ArrayType, 0>;
            using Char              = std::remove_extent_t<ArrayType>;
            if constexpr (extent > 1)
            {
                array[0] = static_cast<Char>('a');
            }
            if constexpr (extent > 2)
            {
                array[1] = static_cast<Char>('b');
            }
        }
        else if constexpr (std::rank_v<ArrayType> == 2)
        {
            for (auto& row : array)
            {
                for (auto& element : row)
                {
                    FillElement<Field>(element);
                }
            }
        }
        else
        {
            for (auto& element : array)
            {
                FillElement<Field>(element);
            }
        }
    }

    template <typename Field, typename Storage>
    requires schema::ExtensionChainField<Field> && schema::FieldStoreFor<Storage, Field>
    void Apply(Field, Storage&) {}

  private:
    template <typename Field, typename Element>
    void FillElement(Element& element)
    {
        if constexpr (schema::StructApiElement<typename Field::api_element>)
        {
            if constexpr (schema::HasSchemaFields<typename Field::api_element>)
            {
                Fill<typename Field::api_element>(context_, element);
            }
        }
        else if constexpr (!schema::HandleApiElement<typename Field::api_element> && IsPatternable_v<Element>)
        {
            element = static_cast<Element>(kPattern);
        }
    }

    FillContext& context_;
};

template <typename ApiElement, typename Storage>
void Fill(FillContext& context, Storage& storage)
{
    FillAction action(context);
    schema::WalkFields<ApiElement>(action, storage);
}

GFXRECON_END_NAMESPACE(fill)
GFXRECON_END_NAMESPACE(test)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TEST_SCHEMA_FILL_H
