/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_HOOK_D3D11_H
#define GFXRECON_HOOK_D3D11_H

#include "encode/d3d11_dispatch_table.h"

#include "util/interception/real_and_mine_hook.h"

#include <Windows.h>
#include <d3d11.h>

class Hook_D3D11;

// Helper struct that holds data required for hook management
struct D3d11HookInfo
{
    // GFXR DLL with capture implementation, which is only loaded when capture is enabled
    HMODULE capture_dll = nullptr;

    // System DLL providing the D3D11 API calls to wrap
    HMODULE d3d11_dll = nullptr;

    // Dispatch table pointing either at the GPU or capture layer
    gfxrecon::encode::D3D11DispatchTable dispatch_table = {};

    // Interceptor class in charge of hooking
    Hook_D3D11* interceptor = nullptr;
};

//-----------------------------------------------------------------------------
/// typedef function pointers
//-----------------------------------------------------------------------------
typedef HRESULT(WINAPI* PFN_D3D11_CREATE_DEVICE)(IDXGIAdapter*            pAdapter,
                                                 D3D_DRIVER_TYPE          DriverType,
                                                 HMODULE                  Software,
                                                 UINT                     Flags,
                                                 const D3D_FEATURE_LEVEL* pFeatureLevels,
                                                 UINT                     FeatureLevels,
                                                 UINT                     SDKVersion,
                                                 ID3D11Device**           ppDevice,
                                                 D3D_FEATURE_LEVEL*       pFeatureLevel,
                                                 ID3D11DeviceContext**    ppImmediateContext);

typedef HRESULT(WINAPI* PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN)(IDXGIAdapter*               pAdapter,
                                                                D3D_DRIVER_TYPE             DriverType,
                                                                HMODULE                     Software,
                                                                UINT                        Flags,
                                                                const D3D_FEATURE_LEVEL*    pFeatureLevels,
                                                                UINT                        FeatureLevels,
                                                                UINT                        SDKVersion,
                                                                const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
                                                                IDXGISwapChain**            ppSwapChain,
                                                                ID3D11Device**              ppDevice,
                                                                D3D_FEATURE_LEVEL*          pFeatureLevel,
                                                                ID3D11DeviceContext**       ppImmediateContext);

//-----------------------------------------------------------------------------
/// This class is responsible for hooking D3D11 module entry points. It contains
/// a "Mine" implementation for each hooked function.
//-----------------------------------------------------------------------------
class Hook_D3D11
{
  public:
    static Hook_D3D11* GetInterceptor();

    Hook_D3D11() {}
    virtual ~Hook_D3D11() {}

    static bool HookInterceptor(bool capture);
    static bool UnhookInterceptor();

    gfxrecon::util::interception::RealAndMineHook<PFN_D3D11_CREATE_DEVICE> hook_D3D11CreateDevice_;
    gfxrecon::util::interception::RealAndMineHook<PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN>
        hook_D3D11CreateDeviceAndSwapChain_;
};

#endif // GFXRECON_HOOK_D3D11_H
