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

// A binding joins a schema entity to a C++ type that exists without the schema. This one maps an API's native
// structure to its API type descriptor, the inverse of the descriptor's element_type, which C++ cannot invert by
// lookup. The primary template is API-agnostic; each API's rows are generated, keyed on its native types, which
// never collide across APIs.

#ifndef GFXRECON_SCHEMA_BINDING_DESCRIPTOR_FOR_H
#define GFXRECON_SCHEMA_BINDING_DESCRIPTOR_FOR_H

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)
GFXRECON_BEGIN_NAMESPACE(binding)

template <typename Native>
struct DescriptorFor;

template <typename Native>
concept HasDescriptor = requires
{
    typename DescriptorFor<Native>::type;
};

// One row: Native is the API's structure, Descriptor its API type descriptor.
#define GFXRECON_SCHEMA_DESCRIPTOR_FOR(Native, Descriptor) \
    template <>                                            \
    struct DescriptorFor<Native>                           \
    {                                                      \
        using type = Descriptor;                           \
    }

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_BINDING_DESCRIPTOR_FOR_H
