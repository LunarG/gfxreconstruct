/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_PLUGINS_CAPTURE_FUNC_TABLE_GENERAL_H
#define GFXRECON_PLUGINS_CAPTURE_FUNC_TABLE_GENERAL_H

#include "format/format.h"
#include "util/platform.h"
#include "plugins_entrypoints_general.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugins)
GFXRECON_BEGIN_NAMESPACE(capture)

typedef void (*PFN_AddStateInformation)(const StateInformation* obj);

GFXRECON_BEGIN_NAMESPACE(noop)

static void AddStateInformation(const StateInformation* obj) {}

GFXRECON_END_NAMESPACE(noop)

struct plugin_func_table_general
{
    PFN_AddStateInformation AddStateInformation{ noop::AddStateInformation };
};

template <typename FuncP>
static void LoadBaseFunction(util::platform::GetProcAddress_t gpa,
                             util::platform::LibraryHandle    handle,
                             const char*                      name,
                             FuncP*                           funcp)
{
    FuncP result = reinterpret_cast<FuncP>(gpa(handle, name));
    if (result)
    {
        *funcp = result;
    }
}

// clang-format off
static void LoadBaseFunctionTable(util::platform::GetProcAddress_t gpa, util::platform::LibraryHandle handle, plugin_func_table_general *table)
{
    assert(gpa);
    assert(handle);
    assert(table);

    LoadBaseFunction(gpa, handle, "AddStateInformation", &table->AddStateInformation);
}

GFXRECON_END_NAMESPACE(capture)
GFXRECON_END_NAMESPACE(plugins)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_PLUGINS_CAPTURE_FUNC_TABLE_GENERAL_H
