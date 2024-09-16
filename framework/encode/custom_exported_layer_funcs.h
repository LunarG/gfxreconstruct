/*
** Copyright (c) 2024 Valve Corporation
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_LAYER_CUSTOM_EXPORTED_FUNCS_H
#define GFXRECON_LAYER_CUSTOM_EXPORTED_FUNCS_H

#include "format/format.h"
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// clang-format off
using GetBlockIndexGFXR_ptr          = void(*)(void);
using DumpAssetsGFXR_ptr             = void(*)(void);
using SetUniqueIdOffsetGFXRPtr       = void(*)(format::HandleId);
using LoadAssetFileOffsetsGFXRPtr    = void(*)(const format::AssetFileOffsets&);
using OverrideCaptureObjectIdFuncPtr = void(*)(format::HandleId, VkObjectType);
using OverrideFrameNumberGFXRPtr     = void(*)(format::FrameNumber);
using NotifyFrameStateSetupGFXRPtr   = void(*)(uint32_t);
// clang-format on

VKAPI_ATTR uint64_t VKAPI_CALL GetBlockIndexGFXR();
VKAPI_ATTR void VKAPI_CALL     DumpAssetsGFXR();
VKAPI_ATTR void VKAPI_CALL     SetUniqueIdOffsetGFXR(format::HandleId offset);
VKAPI_ATTR void VKAPI_CALL     LoadAssetFileOffsetsGFXR(const format::AssetFileOffsets& offsets);
VKAPI_ATTR void VKAPI_CALL     OverrideIdForNextVulkanObjectGFXR(format::HandleId id, VkObjectType type);
VKAPI_ATTR void VKAPI_CALL     OverrideFrameNumberGFXR(format::FrameNumber frame);
VKAPI_ATTR void VKAPI_CALL     NotifyFrameStateSetupGFXR(uint32_t is_in_frame_state_setup);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_LAYER_CUSTOM_EXPORTED_FUNCS_H
