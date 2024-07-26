/*
** Copyright (c) 2020-2021 LunarG, Inc.
** Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

#ifndef GFXRECON_ENCODE_D3D11_DISPATCH_TABLE_H
#define GFXRECON_ENCODE_D3D11_DISPATCH_TABLE_H

#include "util/defines.h"
#include "util/logging.h"

#include <d3d11.h>
#include <windows.h>

// d3d11on12.h will include the d3d12.h from the Windows SDK directory, not the d3d12.h from the Agility SDK that is
// included in the GFXReconstruct source tree. To prevent a conflict between the Windows SDK and Agility SDK
// versions, include d3d12.h from the Agility SDK before including the d3d11on12.h header.
#include <d3d12.h>
#include <d3d11on12.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

struct D3D11DispatchTable
{
    // Functions processed for capture.  These are the D3D11 functions exported by d3d11.dll and documented on MSDN.
    PFN_D3D11_CREATE_DEVICE                D3D11CreateDevice{ nullptr };
    PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN D3D11CreateDeviceAndSwapChain{ nullptr };
    PFN_D3D11ON12_CREATE_DEVICE            D3D11On12CreateDevice{ nullptr };
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

typedef bool (*PFN_InitializeD3D11Capture)(gfxrecon::encode::D3D11DispatchTable*);
typedef void (*PFN_ReleaseD3D11Capture)(gfxrecon::encode::D3D11DispatchTable*);

#endif // GFXRECON_ENCODE_D3D11_DISPATCH_TABLE_H
