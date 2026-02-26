/*
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_AGS_DISPATCH_TABLE_H
#define GFXRECON_ENCODE_AGS_DISPATCH_TABLE_H

#include "util/defines.h"
#include "util/logging.h"

#include <windows.h>

#if GFXRECON_AGS_SUPPORT
#include <amd_ags.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

#if GFXRECON_AGS_SUPPORT
typedef AMD_AGS_API void (*AGS_INIT_NOT_SUPPORTED)();
#endif

struct AgsDispatchTable
{
#if GFXRECON_AGS_SUPPORT
    // Functions processed for capture.  These are the AGS functions exported by amd_ags_x64.dll.
    AGS_INITIALIZE                         agsInitialize{ nullptr };
    AGS_DEINITIALIZE                       agsDeInitialize{ nullptr };
    AGS_CHECKDRIVERVERSION                 agsCheckDriverVersion{ nullptr };
    AGS_DRIVEREXTENSIONSDX12_CREATEDEVICE  agsDriverExtensionsDX12_CreateDevice{ nullptr };
    AGS_DRIVEREXTENSIONSDX12_DESTROYDEVICE agsDriverExtensionsDX12_DestroyDevice{ nullptr };
    AGS_GETVERSIONNUMBER                   agsGetVersionNumber{ nullptr };
    AGS_SETDISPLAYMODE                     agsSetDisplayMode{ nullptr };
    AGS_DRIVEREXTENSIONSDX12_PUSHMARKER    agsDriverExtensionsDX12_PushMarker{ nullptr };
    AGS_DRIVEREXTENSIONSDX12_POPMARKER     agsDriverExtensionsDX12_PopMarker{ nullptr };
    AGS_DRIVEREXTENSIONSDX12_SETMARKER     agsDriverExtensionsDX12_SetMarker{ nullptr };
    AGS_INIT_NOT_SUPPORTED agsInitNotSupported{ nullptr }; // In case, old version dll is used by the application
#endif
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

typedef bool (*PFN_InitializeAgsCapture)(gfxrecon::encode::AgsDispatchTable*);
typedef void(WINAPI* PFN_ReleaseAgsCapture)(gfxrecon::encode::AgsDispatchTable*);

#endif // GFXRECON_ENCODE_AGS_DISPATCH_TABLE_H
