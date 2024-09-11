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

#ifndef GFXRECON_LAYER_CUSTOM_FUNC_TABLE_H
#define GFXRECON_LAYER_CUSTOM_FUNC_TABLE_H

#include "encode/custom_exported_layer_funcs.h"
#include "util/defines.h"

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

// clang-format off
const std::unordered_map<std::string, PFN_vkVoidFunction> custom_func_table = {
    { "GetBlockIndexGFXR", reinterpret_cast<PFN_vkVoidFunction>(encode::GetBlockIndexGFXR) },
    { "DumpAssetsGFXR", reinterpret_cast<PFN_vkVoidFunction>(encode::DumpAssetsGFXR) },
    { "SetUniqueIdOffsetGFXR", reinterpret_cast<PFN_vkVoidFunction>(encode::SetUniqueIdOffsetGFXR) },
    { "LoadAssetFileOffsetsGFXR", reinterpret_cast<PFN_vkVoidFunction>(encode::LoadAssetFileOffsetsGFXR) },
    { "OverrideIdForNextVulkanObjectGFXR", reinterpret_cast<PFN_vkVoidFunction>(encode::OverrideIdForNextVulkanObjectGFXR) },
    { "OverrideFrameNumberGFXR", reinterpret_cast<PFN_vkVoidFunction>(encode::OverrideFrameNumberGFXR) },
};
// clang-format on

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_LAYER_CUSTOM_FUNC_TABLE_H
