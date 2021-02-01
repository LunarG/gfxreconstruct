/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

static Hook_D3D12* d3d12_hook_ = nullptr;

typedef int (*pFuncPtr)(void);

HRESULT WINAPI Mine_D3D12CreateDevice(IUnknown*         pAdapter,
                                      D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                      const IID&        riid,
                                      void**            ppDevice)
{
    HRESULT result = S_FALSE;

    result =
        Hook_D3D12::GetInterceptor()->hook_D3D12CreateDevice_.real_hook_(pAdapter, MinimumFeatureLevel, riid, ppDevice);

    return result;
}

HRESULT WINAPI Mine_D3D12CreateRootSignatureDeserializer(LPCVOID    pSrcData,
                                                         SIZE_T     SrcDataSizeInBytes,
                                                         const IID& pRootSignatureDeserializerInterface,
                                                         void**     ppRootSignatureDeserializer)
{
    HRESULT result = S_FALSE;

    result = Hook_D3D12::GetInterceptor()->hook_D3D12CreateRootSignatureDeserializer_.real_hook_(
        pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);

    return result;
}

HRESULT WINAPI Mine_D3D12CreateVersionedRootSignatureDeserializer(LPCVOID    pSrcData,
                                                                  SIZE_T     SrcDataSizeInBytes,
                                                                  const IID& pRootSignatureDeserializerInterface,
                                                                  void**     ppRootSignatureDeserializer)
{
    HRESULT result = S_FALSE;

    result = Hook_D3D12::GetInterceptor()->hook_D3D12CreateVersionedRootSignatureDeserializer_.real_hook_(
        pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);

    return result;
}

HRESULT WINAPI Mine_D3D12EnableExperimentalFeatures(UINT       NumFeatures,
                                                    const IID* pIIDs,
                                                    void*      pConfigurationStructs,
                                                    UINT*      pConfigurationStructSizes)
{
    HRESULT result = S_FALSE;

    result = Hook_D3D12::GetInterceptor()->hook_D3D12EnableExperimentalFeatures_.real_hook_(
        NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes);

    return result;
}

HRESULT WINAPI Mine_D3D12GetDebugInterface(const IID& riid, void** ppvDebug)
{
    HRESULT result = S_FALSE;

    result = Hook_D3D12::GetInterceptor()->hook_D3D12GetDebugInterface_.real_hook_(riid, ppvDebug);

    return result;
}

HRESULT WINAPI Mine_D3D12SerializeRootSignature(const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
                                                D3D_ROOT_SIGNATURE_VERSION       Version,
                                                ID3DBlob**                       ppBlob,
                                                ID3DBlob**                       ppErrorBlob)
{
    HRESULT result = S_FALSE;

    result = Hook_D3D12::GetInterceptor()->hook_D3D12SerializeRootSignature_.real_hook_(
        pRootSignature, Version, ppBlob, ppErrorBlob);

    return result;
}

HRESULT WINAPI Mine_D3D12SerializeVersionedRootSignature(const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
                                                         ID3DBlob**                                 ppBlob,
                                                         ID3DBlob**                                 ppErrorBlob)
{
    HRESULT result = S_FALSE;

    result = Hook_D3D12::GetInterceptor()->hook_D3D12SerializeVersionedRootSignature_.real_hook_(
        pRootSignature, ppBlob, ppErrorBlob);

    return result;
}

HRESULT WINAPI D3D12CreateDevice(IUnknown*         pAdapter,
                                 D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                 const IID&        riid,
                                 void**            ppDevice)
{
    return Mine_D3D12CreateDevice(pAdapter, MinimumFeatureLevel, riid, ppDevice);
}

HRESULT WINAPI D3D12CreateRootSignatureDeserializer(LPCVOID    pSrcData,
                                                    SIZE_T     SrcDataSizeInBytes,
                                                    const IID& pRootSignatureDeserializerInterface,
                                                    void**     ppRootSignatureDeserializer)
{
    return Mine_D3D12CreateRootSignatureDeserializer(
        pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
}

HRESULT WINAPI D3D12CreateVersionedRootSignatureDeserializer(LPCVOID    pSrcData,
                                                             SIZE_T     SrcDataSizeInBytes,
                                                             const IID& pRootSignatureDeserializerInterface,
                                                             void**     ppRootSignatureDeserializer)
{
    return Mine_D3D12CreateVersionedRootSignatureDeserializer(
        pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
}

HRESULT WINAPI D3D12EnableExperimentalFeatures(UINT       NumFeatures,
                                               const IID* pIIDs,
                                               void*      pConfigurationStructs,
                                               UINT*      pConfigurationStructSizes)
{
    return Mine_D3D12EnableExperimentalFeatures(NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes);
}

HRESULT WINAPI D3D12GetDebugInterface(const IID& riid, void** ppvDebug)
{
    return Mine_D3D12GetDebugInterface(riid, ppvDebug);
}

HRESULT WINAPI D3D12SerializeRootSignature(const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
                                           D3D_ROOT_SIGNATURE_VERSION       Version,
                                           ID3DBlob**                       ppBlob,
                                           ID3DBlob**                       ppErrorBlob)
{
    return Mine_D3D12SerializeRootSignature(pRootSignature, Version, ppBlob, ppErrorBlob);
}

HRESULT WINAPI D3D12SerializeVersionedRootSignature(const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
                                                    ID3DBlob**                                 ppBlob,
                                                    ID3DBlob**                                 ppErrorBlob)
{
    return Mine_D3D12SerializeVersionedRootSignature(pRootSignature, ppBlob, ppErrorBlob);
}

//-----------------------------------------------------------------------------
/// Get unique instance of Hook_D3D12
//-----------------------------------------------------------------------------
Hook_D3D12* Hook_D3D12::GetInterceptor()
{
    if (d3d12_hook_ == nullptr)
    {
        d3d12_hook_ = new Hook_D3D12();
    }

    return d3d12_hook_;
}

//-----------------------------------------------------------------------------
/// Attach API entry points for hooking.
/// \return True if entry points were successfully hooked.
//-----------------------------------------------------------------------------
bool Hook_D3D12::HookInterceptor()
{
    bool success = false;

    HMODULE module_handle = ::LoadLibraryA("d3d12.dll");

    if (module_handle != nullptr)
    {
        Hook_D3D12* pInterceptor = GetInterceptor();

        if (pInterceptor != nullptr)
        {
            bool attach_success = false;

            pFuncPtr D3D12CreateDevice_funcPtr = (pFuncPtr)(::GetProcAddress(module_handle, "D3D12CreateDevice"));
            if (D3D12CreateDevice_funcPtr != nullptr)
            {
                pInterceptor->hook_D3D12CreateDevice_.SetHooks((PFN_D3D12CREATEDEVICE)D3D12CreateDevice_funcPtr,
                                                               Mine_D3D12CreateDevice);
                attach_success = pInterceptor->hook_D3D12CreateDevice_.Attach();
            }

            pFuncPtr D3D12CreateRootSignatureDeserializer_funcPtr =
                (pFuncPtr)(::GetProcAddress(module_handle, "D3D12CreateRootSignatureDeserializer"));
            if (D3D12CreateRootSignatureDeserializer_funcPtr != nullptr)
            {
                pInterceptor->hook_D3D12CreateRootSignatureDeserializer_.SetHooks(
                    (PFN_D3D12CREATEROOTSIGNATUREDESERIALIZER)D3D12CreateRootSignatureDeserializer_funcPtr,
                    Mine_D3D12CreateRootSignatureDeserializer);
                attach_success = pInterceptor->hook_D3D12CreateRootSignatureDeserializer_.Attach();
            }

            pFuncPtr D3D12CreateVersionedRootSignatureDeserializer_funcPtr =
                (pFuncPtr)(::GetProcAddress(module_handle, "D3D12CreateVersionedRootSignatureDeserializer"));
            if (D3D12CreateVersionedRootSignatureDeserializer_funcPtr != nullptr)
            {
                pInterceptor->hook_D3D12CreateVersionedRootSignatureDeserializer_.SetHooks(
                    (PFN_D3D12CREATEVERSIONEDROOTSIGNATUREDESERIALIZER)
                        D3D12CreateVersionedRootSignatureDeserializer_funcPtr,
                    Mine_D3D12CreateVersionedRootSignatureDeserializer);
                attach_success = pInterceptor->hook_D3D12CreateVersionedRootSignatureDeserializer_.Attach();
            }

            pFuncPtr D3D12EnableExperimentalFeatures_funcPtr =
                (pFuncPtr)(::GetProcAddress(module_handle, "D3D12EnableExperimentalFeatures"));
            if (D3D12EnableExperimentalFeatures_funcPtr != nullptr)
            {
                pInterceptor->hook_D3D12EnableExperimentalFeatures_.SetHooks(
                    (PFN_D3D12ENABLEEXPERIMENTALFEATURES)D3D12EnableExperimentalFeatures_funcPtr,
                    Mine_D3D12EnableExperimentalFeatures);
                attach_success = pInterceptor->hook_D3D12EnableExperimentalFeatures_.Attach();
            }

            pFuncPtr D3D12GetDebugInterface_funcPtr =
                (pFuncPtr)(::GetProcAddress(module_handle, "D3D12GetDebugInterface"));
            if (D3D12GetDebugInterface_funcPtr != nullptr)
            {
                pInterceptor->hook_D3D12GetDebugInterface_.SetHooks(
                    (PFN_D3D12GETDEBUGINTERFACE)D3D12GetDebugInterface_funcPtr, Mine_D3D12GetDebugInterface);
                attach_success = pInterceptor->hook_D3D12GetDebugInterface_.Attach();
            }

            pFuncPtr D3D12SerializeRootSignature_funcPtr =
                (pFuncPtr)(::GetProcAddress(module_handle, "D3D12SerializeRootSignature"));
            if (D3D12SerializeRootSignature_funcPtr != nullptr)
            {
                pInterceptor->hook_D3D12SerializeRootSignature_.SetHooks(
                    (PFN_D3D12SERIALIZEROOTSIGNATURE)D3D12SerializeRootSignature_funcPtr,
                    Mine_D3D12SerializeRootSignature);
                attach_success = pInterceptor->hook_D3D12SerializeRootSignature_.Attach();
            }

            pFuncPtr D3D12SerializeVersionedRootSignature_funcPtr =
                (pFuncPtr)(::GetProcAddress(module_handle, "D3D12SerializeVersionedRootSignature"));
            if (D3D12SerializeVersionedRootSignature_funcPtr != nullptr)
            {
                pInterceptor->hook_D3D12SerializeVersionedRootSignature_.SetHooks(
                    (PFN_D3D12SERIALIZEVERSIONEDROOTSIGNATURE)D3D12SerializeVersionedRootSignature_funcPtr,
                    Mine_D3D12SerializeVersionedRootSignature);
                attach_success = pInterceptor->hook_D3D12SerializeVersionedRootSignature_.Attach();
            }

            success = true;
        }
    }

    return success;
}

//-----------------------------------------------------------------------------
/// Detach all hooked API entry points.
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
