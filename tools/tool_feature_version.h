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

// Shared "--version" handling for tools that have a Feature module (replay, convert, extract,
// optimize, info): walks whatever Vulkan/D3D12/OpenXR Features are registered with
// FeatureModuleRegistry<FeatureBaseT> and prints each one's compiled-header version string, so
// every Feature-based tool reports the same set of API versions without any per-tool or
// per-API branching. Tools without a Feature module (compress, tocpp, file_version_patch) keep
// using the plain CheckOptionPrintVersion() from tool_command_line.h.

#ifndef GFXRECON_TOOL_FEATURE_VERSION_H
#define GFXRECON_TOOL_FEATURE_VERSION_H

#include "tool_command_line.h"

#include "util/feature_module_registry.h"

template <typename FeatureBaseT>
inline void PrintFeatureVersions()
{
    for (const auto& creator :
         gfxrecon::util::FeatureModuleRegistry<FeatureBaseT>::GetSingleton().GetRegisteredFeatureCreators())
    {
        auto              feature        = creator();
        const std::string version_string = feature->CompiledHeaderVersionString();
        if (!version_string.empty())
        {
            GFXRECON_WRITE_CONSOLE("  %s", version_string.c_str());
        }
    }
}

template <typename FeatureBaseT>
inline bool CheckOptionPrintFeatureVersions(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kVersionOption))
    {
        PrintVersionHeader(exe_name);
        PrintFeatureVersions<FeatureBaseT>();
        return true;
    }

    return false;
}

#endif // GFXRECON_TOOL_FEATURE_VERSION_H
