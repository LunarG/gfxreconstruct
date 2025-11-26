/*
** Copyright (c) 2020-2021 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_DXGI_DISPATCH_TABLE_H
#define GFXRECON_ENCODE_DXGI_DISPATCH_TABLE_H

#include "util/defines.h"
#include "util/logging.h"

#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_3.h>
#include <dxgi1_6.h>
#include <windows.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

struct DxgiDispatchTable
{
    // Functions processed for capture.  These are the DXGI functions exported by dxgi.dll and documented on MSDN.
    // NOTE: There are no typedefs in the DXGI header files for these functions.
    decltype(CreateDXGIFactory)*                CreateDXGIFactory{ nullptr };
    decltype(CreateDXGIFactory1)*               CreateDXGIFactory1{ nullptr };
    decltype(CreateDXGIFactory2)*               CreateDXGIFactory2{ nullptr };
    decltype(DXGIDeclareAdapterRemovalSupport)* DXGIDeclareAdapterRemovalSupport{ nullptr };
    decltype(DXGIGetDebugInterface1)*           DXGIGetDebugInterface1{ nullptr };
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

typedef bool (*PFN_InitializeDxgiCapture)(gfxrecon::encode::DxgiDispatchTable*);
typedef void(WINAPI* PFN_ReleaseDxgiCapture)(gfxrecon::encode::DxgiDispatchTable*);

#endif // GFXRECON_ENCODE_DXGI_DISPATCH_TABLE_H
