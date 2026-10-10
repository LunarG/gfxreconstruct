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

// The structure type of a native structure, read through its descriptor binding, and the cast a sieve makes once it
// has matched one.

#ifndef GFXRECON_BINDING_STRUCTURE_TYPE_H
#define GFXRECON_BINDING_STRUCTURE_TYPE_H

#include "binding/descriptor_for.h"
#include "schema/schema.h"
#include "util/defines.h"
#include "util/logging.h"
#include "util/type_traits_extras.h"

#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(binding)

// The structure type the native structure's descriptor carries.
template <HasSchemaStructureType Native>
constexpr auto StructureTypeOf()
{
    return DescriptorFor<Native>::type::structure_type;
}

// A pointer to a chained structure, as the native type its structure type names, constness carried over from the
// pointer. Checked in debug through the first member, which every chainable structure's type is.
template <HasSchemaStructureType Specific, typename Generic>
requires std::is_pointer_v<Generic> && std::negation_v<std::is_pointer<Specific>>
auto StructureTypeCast(Generic generic)
{
    using Result        = util::CopyPointerConst_t<Generic, Specific>;
    using StructureType = std::remove_cv_t<decltype(StructureTypeOf<Specific>())>;
    Result specific     = reinterpret_cast<Result>(generic);
    GFXRECON_ASSERT((specific == nullptr) ||
                    (*reinterpret_cast<const StructureType*>(specific) == StructureTypeOf<Specific>()));
    return specific;
}

// The same, keyed on the descriptor.
template <schema::HasStructureType Descriptor, typename Generic>
requires std::is_pointer_v<Generic>
auto StructureTypeCast(Generic generic)
{
    return StructureTypeCast<typename Descriptor::element_type>(generic);
}

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_STRUCTURE_TYPE_H
