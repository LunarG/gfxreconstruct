/*
** Copyright (c) 2021-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "hook_d3d12.h"

#include "util/file_path.h"
#include "util/interception/interception_util.h"

// Static data required for hook management
static D3d12HookInfo hook_info_ = {};

HRESULT WINAPI Mine_D3D12CreateDevice(IUnknown*         pAdapter,
                                      D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                      const IID&        riid,
                                      void**            ppDevice)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D12CreateDevice(pAdapter, MinimumFeatureLevel, riid, ppDevice);

    return result;
}

HRESULT WINAPI Mine_D3D12CreateRootSignatureDeserializer(LPCVOID    pSrcData,
                                                         SIZE_T     SrcDataSizeInBytes,
                                                         const IID& pRootSignatureDeserializerInterface,
                                                         void**     ppRootSignatureDeserializer)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D12CreateRootSignatureDeserializer(
        pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);

    return result;
}

HRESULT WINAPI Mine_D3D12CreateVersionedRootSignatureDeserializer(LPCVOID    pSrcData,
                                                                  SIZE_T     SrcDataSizeInBytes,
                                                                  const IID& pRootSignatureDeserializerInterface,
                                                                  void**     ppRootSignatureDeserializer)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D12CreateVersionedRootSignatureDeserializer(
        pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);

    return result;
}

HRESULT WINAPI Mine_D3D12EnableExperimentalFeatures(UINT       NumFeatures,
                                                    const IID* pIIDs,
                                                    void*      pConfigurationStructs,
                                                    UINT*      pConfigurationStructSizes)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D12EnableExperimentalFeatures(
        NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes);

    return result;
}

HRESULT WINAPI Mine_D3D12GetDebugInterface(const IID& riid, void** ppvDebug)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D12GetDebugInterface(riid, ppvDebug);

    return result;
}

HRESULT WINAPI Mine_D3D12SerializeRootSignature(const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
                                                D3D_ROOT_SIGNATURE_VERSION       Version,
                                                ID3DBlob**                       ppBlob,
                                                ID3DBlob**                       ppErrorBlob)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D12SerializeRootSignature(pRootSignature, Version, ppBlob, ppErrorBlob);

    return result;
}

HRESULT WINAPI Mine_D3D12SerializeVersionedRootSignature(const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
                                                         ID3DBlob**                                 ppBlob,
                                                         ID3DBlob**                                 ppErrorBlob)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D12SerializeVersionedRootSignature(pRootSignature, ppBlob, ppErrorBlob);

    return result;
}

HRESULT WINAPI Mine_D3D12GetInterface(REFCLSID rclsid, REFIID riid, void** ppvDebug)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.D3D12GetInterface(rclsid, riid, ppvDebug);

    return result;
}
//----------------------------------------------------------------------------
/// Fill in a dispatch table with function addresses obtained from d3d12.dll
///
/// \param  d3d12_table Output dispatch table.
///
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool GetD3d12DispatchTable(gfxrecon::encode::D3D12DispatchTable& d3d12_table)
{
    std::string library_base_path = "";

    bool success = gfxrecon::util::filepath::GetWindowsSystemLibrariesPath(library_base_path);

    if (success == true)
    {
        std::string library_path = library_base_path + "\\d3d12.dll";

        hook_info_.d3d12_dll = LoadLibraryA(library_path.c_str());

        if (hook_info_.d3d12_dll != nullptr)
        {
            d3d12_table.D3D12CreateDevice =
                reinterpret_cast<PFN_D3D12_CREATE_DEVICE>(GetProcAddress(hook_info_.d3d12_dll, "D3D12CreateDevice"));

            d3d12_table.D3D12CreateRootSignatureDeserializer =
                reinterpret_cast<PFN_D3D12_CREATE_ROOT_SIGNATURE_DESERIALIZER>(
                    GetProcAddress(hook_info_.d3d12_dll, "D3D12CreateRootSignatureDeserializer"));

            d3d12_table.D3D12CreateVersionedRootSignatureDeserializer =
                reinterpret_cast<PFN_D3D12_CREATE_VERSIONED_ROOT_SIGNATURE_DESERIALIZER>(
                    GetProcAddress(hook_info_.d3d12_dll, "D3D12CreateVersionedRootSignatureDeserializer"));

            d3d12_table.D3D12GetDebugInterface = reinterpret_cast<PFN_D3D12_GET_DEBUG_INTERFACE>(
                GetProcAddress(hook_info_.d3d12_dll, "D3D12GetDebugInterface"));

            d3d12_table.D3D12SerializeRootSignature = reinterpret_cast<PFN_D3D12_SERIALIZE_ROOT_SIGNATURE>(
                GetProcAddress(hook_info_.d3d12_dll, "D3D12SerializeRootSignature"));

            d3d12_table.D3D12SerializeVersionedRootSignature =
                reinterpret_cast<PFN_D3D12_SERIALIZE_VERSIONED_ROOT_SIGNATURE>(
                    GetProcAddress(hook_info_.d3d12_dll, "D3D12SerializeVersionedRootSignature"));

            d3d12_table.D3D12GetInterface =
                reinterpret_cast<PFN_D3D12_GET_INTERFACE>(GetProcAddress(hook_info_.d3d12_dll, "D3D12GetInterface"));

            d3d12_table.D3D12EnableExperimentalFeatures = reinterpret_cast<decltype(D3D12EnableExperimentalFeatures)*>(
                GetProcAddress(hook_info_.d3d12_dll, "D3D12EnableExperimentalFeatures"));

            success = true;
        }
    }

    return success;
}

//----------------------------------------------------------------------------
/// Given a d3d12 dispatch table, perform hooking and write out the final
/// dispatch table that will be called by intercepted entry points.
///
/// \param  d3d12_table Incoming dispatch table with entry function addresses
///                     in d3d12.
///
/// \param  gpu_table Outgoing dispatch table with hooked entry points that
///                   will either go to the GPU or capture layer.
///
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool GetD3d12DispatchTableHooked(gfxrecon::encode::D3D12DispatchTable  d3d12_table,
                                 gfxrecon::encode::D3D12DispatchTable& gpu_table)
{
    bool success = false;

    Hook_D3D12* pInterceptor = Hook_D3D12::GetInterceptor();

    if (pInterceptor != nullptr)
    {
        bool attach_success = false;

        if (d3d12_table.D3D12CreateDevice != nullptr)
        {
            pInterceptor->hook_D3D12CreateDevice_.SetHooks(d3d12_table.D3D12CreateDevice, Mine_D3D12CreateDevice);
            attach_success = pInterceptor->hook_D3D12CreateDevice_.Attach();

            gpu_table.D3D12CreateDevice = pInterceptor->hook_D3D12CreateDevice_.real_hook_;
        }

        if (d3d12_table.D3D12CreateRootSignatureDeserializer != nullptr)
        {
            pInterceptor->hook_D3D12CreateRootSignatureDeserializer_.SetHooks(
                d3d12_table.D3D12CreateRootSignatureDeserializer, Mine_D3D12CreateRootSignatureDeserializer);
            attach_success = pInterceptor->hook_D3D12CreateRootSignatureDeserializer_.Attach();

            gpu_table.D3D12CreateRootSignatureDeserializer =
                pInterceptor->hook_D3D12CreateRootSignatureDeserializer_.real_hook_;
        }

        if (d3d12_table.D3D12CreateVersionedRootSignatureDeserializer != nullptr)
        {
            pInterceptor->hook_D3D12CreateVersionedRootSignatureDeserializer_.SetHooks(
                d3d12_table.D3D12CreateVersionedRootSignatureDeserializer,
                Mine_D3D12CreateVersionedRootSignatureDeserializer);
            attach_success = pInterceptor->hook_D3D12CreateVersionedRootSignatureDeserializer_.Attach();

            gpu_table.D3D12CreateVersionedRootSignatureDeserializer =
                pInterceptor->hook_D3D12CreateVersionedRootSignatureDeserializer_.real_hook_;
        }

        if (d3d12_table.D3D12EnableExperimentalFeatures != nullptr)
        {
            pInterceptor->hook_D3D12EnableExperimentalFeatures_.SetHooks(d3d12_table.D3D12EnableExperimentalFeatures,
                                                                         Mine_D3D12EnableExperimentalFeatures);
            attach_success = pInterceptor->hook_D3D12EnableExperimentalFeatures_.Attach();

            gpu_table.D3D12EnableExperimentalFeatures = pInterceptor->hook_D3D12EnableExperimentalFeatures_.real_hook_;
        }

        if (d3d12_table.D3D12GetDebugInterface != nullptr)
        {
            pInterceptor->hook_D3D12GetDebugInterface_.SetHooks(d3d12_table.D3D12GetDebugInterface,
                                                                Mine_D3D12GetDebugInterface);
            attach_success = pInterceptor->hook_D3D12GetDebugInterface_.Attach();

            gpu_table.D3D12GetDebugInterface = pInterceptor->hook_D3D12GetDebugInterface_.real_hook_;
        }

        if (d3d12_table.D3D12SerializeRootSignature != nullptr)
        {
            pInterceptor->hook_D3D12SerializeRootSignature_.SetHooks(d3d12_table.D3D12SerializeRootSignature,
                                                                     Mine_D3D12SerializeRootSignature);
            attach_success = pInterceptor->hook_D3D12SerializeRootSignature_.Attach();

            gpu_table.D3D12SerializeRootSignature = pInterceptor->hook_D3D12SerializeRootSignature_.real_hook_;
        }

        if (d3d12_table.D3D12SerializeVersionedRootSignature != nullptr)
        {
            pInterceptor->hook_D3D12SerializeVersionedRootSignature_.SetHooks(
                d3d12_table.D3D12SerializeVersionedRootSignature, Mine_D3D12SerializeVersionedRootSignature);
            attach_success = pInterceptor->hook_D3D12SerializeVersionedRootSignature_.Attach();

            gpu_table.D3D12SerializeVersionedRootSignature =
                pInterceptor->hook_D3D12SerializeVersionedRootSignature_.real_hook_;
        }

        if (d3d12_table.D3D12GetInterface != nullptr)
        {
            pInterceptor->hook_D3D12GetInterface_.SetHooks(d3d12_table.D3D12GetInterface, Mine_D3D12GetInterface);
            attach_success = pInterceptor->hook_D3D12GetInterface_.Attach();

            gpu_table.D3D12GetInterface = pInterceptor->hook_D3D12GetInterface_.real_hook_;
        }

        success = true;
    }

    return success;
}

//-----------------------------------------------------------------------------
/// Get unique instance of Hook_D3D12
///
/// \return Pointer to instance of Hook_D3D12
//-----------------------------------------------------------------------------
Hook_D3D12* Hook_D3D12::GetInterceptor()
{
    if (hook_info_.interceptor == nullptr)
    {
        hook_info_.interceptor = new Hook_D3D12();
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
bool Hook_D3D12::HookInterceptor(bool capture)
{
    bool success = false;

    Hook_D3D12* pInterceptor = GetInterceptor();

    if (pInterceptor != nullptr)
    {
        gfxrecon::encode::D3D12DispatchTable dispatch_table_d3d12 = {};

        success = GetD3d12DispatchTable(dispatch_table_d3d12);

        if (success == true)
        {
            success = GetD3d12DispatchTableHooked(dispatch_table_d3d12, hook_info_.dispatch_table);

            if (success == true)
            {
                if (capture == true)
                {
                    if (hook_info_.capture_dll == nullptr)
                    {
                        const std::string gfxr_d3d12_capture_path = gfxrecon::util::interception::CaptureLibPath();

                        hook_info_.capture_dll = gfxrecon::util::platform::OpenLibrary(gfxr_d3d12_capture_path.c_str());

                        if (hook_info_.capture_dll != nullptr)
                        {
                            auto init_func = reinterpret_cast<PFN_InitializeD3D12Capture>(
                                GetProcAddress(hook_info_.capture_dll, "InitializeD3D12Capture"));

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
bool Hook_D3D12::UnhookInterceptor()
{
    bool success = false;

    Hook_D3D12* pInterceptor = GetInterceptor();

    if (pInterceptor != nullptr)
    {
        pInterceptor->hook_D3D12CreateDevice_.Detach();
        pInterceptor->hook_D3D12CreateRootSignatureDeserializer_.Detach();
        pInterceptor->hook_D3D12CreateVersionedRootSignatureDeserializer_.Detach();
        pInterceptor->hook_D3D12EnableExperimentalFeatures_.Detach();
        pInterceptor->hook_D3D12GetDebugInterface_.Detach();
        pInterceptor->hook_D3D12SerializeRootSignature_.Detach();
        pInterceptor->hook_D3D12SerializeVersionedRootSignature_.Detach();

        success = true;
    }

    return success;
}
