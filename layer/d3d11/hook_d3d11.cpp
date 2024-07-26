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

#include "hook_d3d11.h"

#include "util/file_path.h"

// Static data required for hook management
static D3d11HookInfo hook_info_ = {};

HRESULT WINAPI Mine_D3D11CreateDevice(IDXGIAdapter*            pAdapter,
                                      D3D_DRIVER_TYPE          DriverType,
                                      HMODULE                  Software,
                                      UINT                     Flags,
                                      const D3D_FEATURE_LEVEL* pFeatureLevels,
                                      UINT                     FeatureLevels,
                                      UINT                     SDKVersion,
                                      ID3D11Device**           ppDevice,
                                      D3D_FEATURE_LEVEL*       pFeatureLevel,
                                      ID3D11DeviceContext**    ppImmediateContext)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D11CreateDevice(pAdapter,
                                                         DriverType,
                                                         Software,
                                                         Flags,
                                                         pFeatureLevels,
                                                         FeatureLevels,
                                                         SDKVersion,
                                                         ppDevice,
                                                         pFeatureLevel,
                                                         ppImmediateContext);

    return result;
}

HRESULT WINAPI Mine_D3D11CreateDeviceAndSwapChain(IDXGIAdapter*               pAdapter,
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
                                                  ID3D11DeviceContext**       ppImmediateContext)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D11CreateDeviceAndSwapChain(pAdapter,
                                                                     DriverType,
                                                                     Software,
                                                                     Flags,
                                                                     pFeatureLevels,
                                                                     FeatureLevels,
                                                                     SDKVersion,
                                                                     pSwapChainDesc,
                                                                     ppSwapChain,
                                                                     ppDevice,
                                                                     pFeatureLevel,
                                                                     ppImmediateContext);

    return result;
}

HRESULT WINAPI Mine_D3D11On12CreateDevice(IUnknown*                pDevice,
                                          UINT                     Flags,
                                          const D3D_FEATURE_LEVEL* pFeatureLevels,
                                          UINT                     FeatureLevels,
                                          IUnknown* const*         ppCommandQueues,
                                          UINT                     NumQueues,
                                          UINT                     NodeMask,
                                          ID3D11Device**           ppDevice,
                                          ID3D11DeviceContext**    ppImmediateContext,
                                          D3D_FEATURE_LEVEL*       pChosenFeatureLevel)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D11On12CreateDevice(pDevice,
                                                             Flags,
                                                             pFeatureLevels,
                                                             FeatureLevels,
                                                             ppCommandQueues,
                                                             NumQueues,
                                                             NodeMask,
                                                             ppDevice,
                                                             ppImmediateContext,
                                                             pChosenFeatureLevel);

    return result;
}

//----------------------------------------------------------------------------
/// Fill in a dispatch table with function addresses obtained from d3d11.dll
///
/// \param  d3d11_table Output dispatch table.
///
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool GetD3d11DispatchTable(gfxrecon::encode::D3D11DispatchTable& d3d11_table)
{
    std::string library_base_path = "";

    bool success = gfxrecon::util::filepath::GetWindowsSystemLibrariesPath(library_base_path);

    if (success == true)
    {
        std::string library_path = library_base_path + "\\d3d11.dll";

        hook_info_.d3d11_dll = LoadLibraryA(library_path.c_str());

        if (hook_info_.d3d11_dll != nullptr)
        {
            d3d11_table.D3D11CreateDevice =
                reinterpret_cast<PFN_D3D11_CREATE_DEVICE>(GetProcAddress(hook_info_.d3d11_dll, "D3D11CreateDevice"));

            d3d11_table.D3D11CreateDeviceAndSwapChain = reinterpret_cast<PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN>(
                GetProcAddress(hook_info_.d3d11_dll, "D3D11CreateDeviceAndSwapChain"));

            d3d11_table.D3D11On12CreateDevice = reinterpret_cast<PFN_D3D11ON12_CREATE_DEVICE>(
                GetProcAddress(hook_info_.d3d11_dll, "D3D11On12CreateDevice"));

            success = true;
        }
    }

    return success;
}

//----------------------------------------------------------------------------
/// Given a d3d11 dispatch table, perform hooking and write out the final
/// dispatch table that will be called by intercepted entry points.
///
/// \param  d3d11_table Incoming dispatch table with entry function addresses
///                     in d3d11.
///
/// \param  gpu_table Outgoing dispatch table with hooked entry points that
///                   will either go to the GPU or capture layer.
///
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool GetD3d11DispatchTableHooked(gfxrecon::encode::D3D11DispatchTable  d3d11_table,
                                 gfxrecon::encode::D3D11DispatchTable& gpu_table)
{
    bool success = false;

    Hook_D3D11* pInterceptor = Hook_D3D11::GetInterceptor();

    if (pInterceptor != nullptr)
    {
        bool attach_success = false;

        if (d3d11_table.D3D11CreateDevice != nullptr)
        {
            pInterceptor->hook_D3D11CreateDevice_.SetHooks(d3d11_table.D3D11CreateDevice, Mine_D3D11CreateDevice);
            attach_success = pInterceptor->hook_D3D11CreateDevice_.Attach();

            gpu_table.D3D11CreateDevice = pInterceptor->hook_D3D11CreateDevice_.real_hook_;
        }

        if (d3d11_table.D3D11CreateDeviceAndSwapChain != nullptr)
        {
            pInterceptor->hook_D3D11CreateDeviceAndSwapChain_.SetHooks(d3d11_table.D3D11CreateDeviceAndSwapChain,
                                                                       Mine_D3D11CreateDeviceAndSwapChain);
            attach_success = pInterceptor->hook_D3D11CreateDeviceAndSwapChain_.Attach();

            gpu_table.D3D11CreateDeviceAndSwapChain = pInterceptor->hook_D3D11CreateDeviceAndSwapChain_.real_hook_;
        }

        if (d3d11_table.D3D11On12CreateDevice != nullptr)
        {
            pInterceptor->hook_D3D11On12CreateDevice_.SetHooks(d3d11_table.D3D11On12CreateDevice,
                                                               Mine_D3D11On12CreateDevice);
            attach_success = pInterceptor->hook_D3D11On12CreateDevice_.Attach();

            gpu_table.D3D11On12CreateDevice = pInterceptor->hook_D3D11On12CreateDevice_.real_hook_;
        }

        success = true;
    }

    return success;
}

//-----------------------------------------------------------------------------
/// Get unique instance of Hook_D3D11
///
/// \return Pointer to instance of Hook_D3D11
//-----------------------------------------------------------------------------
Hook_D3D11* Hook_D3D11::GetInterceptor()
{
    if (hook_info_.interceptor == nullptr)
    {
        hook_info_.interceptor = new Hook_D3D11();
    }

    return hook_info_.interceptor;
}

//-----------------------------------------------------------------------------
/// Attach API entry points for hooking.
///
/// \param capture Whether capture is enabled
///
/// \return True if entry points were successfully hooked.
//-----------------------------------------------------------------------------
bool Hook_D3D11::HookInterceptor(bool capture)
{
    bool success = false;

    Hook_D3D11* pInterceptor = GetInterceptor();

    if (pInterceptor != nullptr)
    {
        gfxrecon::encode::D3D11DispatchTable dispatch_table_d3d11 = {};

        success = GetD3d11DispatchTable(dispatch_table_d3d11);

        if (success == true)
        {
            success = GetD3d11DispatchTableHooked(dispatch_table_d3d11, hook_info_.dispatch_table);

            if (success == true)
            {
                if (capture == true)
                {
                    if (hook_info_.capture_dll == nullptr)
                    {
                        hook_info_.capture_dll = gfxrecon::util::platform::OpenLibrary(GFXR_D3D12_CAPTURE_PATH);

                        if (hook_info_.capture_dll != nullptr)
                        {
                            auto init_func = reinterpret_cast<PFN_InitializeD3D11Capture>(
                                GetProcAddress(hook_info_.capture_dll, "InitializeD3D11Capture"));

                            if (init_func != nullptr)
                            {
                                init_func(&hook_info_.dispatch_table);
                            }
                        }
                    }
                }
            }
        }
    }

    return success;
}

//-----------------------------------------------------------------------------
/// Detach all hooked API entry points.
///
/// \return True if entry points were successfully detached.
//-----------------------------------------------------------------------------
bool Hook_D3D11::UnhookInterceptor()
{
    bool success = false;

    Hook_D3D11* pInterceptor = GetInterceptor();

    if (pInterceptor != nullptr)
    {
        pInterceptor->hook_D3D11CreateDevice_.Detach();
        pInterceptor->hook_D3D11CreateDeviceAndSwapChain_.Detach();
        pInterceptor->hook_D3D11On12CreateDevice_.Detach();

        success = true;
    }

    return success;
}
