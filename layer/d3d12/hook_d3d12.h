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

#ifndef GFXRECON_HOOK_D3D12_H
#define GFXRECON_HOOK_D3D12_H

#include "encode/d3d12_dispatch_table.h"

#include "util/interception/real_and_mine_hook.h"

#include <Windows.h>
#include <d3d12.h>

class Hook_D3D12;

// Helper struct that holds data required for hook management
struct D3d12HookInfo
{
    // GFXR DLL with capture implementation, which is only loaded when capture is enabled
    HMODULE capture_dll = nullptr;

    // System DLL providing the D3D12 API calls to wrap
    HMODULE d3d12_dll = nullptr;

    // Dispatch table pointing either at the GPU or capture layer
    gfxrecon::encode::D3D12DispatchTable dispatch_table = {};

    // Interceptor class in charge of hooking
    Hook_D3D12* interceptor = nullptr;
};

//-----------------------------------------------------------------------------
/// typedef function pointers
//-----------------------------------------------------------------------------
typedef HRESULT(WINAPI* PFN_D3D12CREATEDEVICE)(IUnknown*         pAdapter,
                                               D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                               const IID&        riid,
                                               void**            ppDevice);

typedef HRESULT(WINAPI* PFN_D3D12CREATEROOTSIGNATUREDESERIALIZER)(LPCVOID    pSrcData,
                                                                  SIZE_T     SrcDataSizeInBytes,
                                                                  const IID& pRootSignatureDeserializerInterface,
                                                                  void**     ppRootSignatureDeserializer);

typedef HRESULT(WINAPI* PFN_D3D12CREATEVERSIONEDROOTSIGNATUREDESERIALIZER)(
    LPCVOID    pSrcData,
    SIZE_T     SrcDataSizeInBytes,
    const IID& pRootSignatureDeserializerInterface,
    void**     ppRootSignatureDeserializer);

typedef HRESULT(WINAPI* PFN_D3D12ENABLEEXPERIMENTALFEATURES)(UINT       NumFeatures,
                                                             const IID* pIIDs,
                                                             void*      pConfigurationStructs,
                                                             UINT*      pConfigurationStructSizes);

typedef HRESULT(WINAPI* PFN_D3D12GETDEBUGINTERFACE)(const IID& riid, void** ppvDebug);

typedef HRESULT(WINAPI* PFN_D3D12SERIALIZEROOTSIGNATURE)(const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
                                                         D3D_ROOT_SIGNATURE_VERSION       Version,
                                                         ID3DBlob**                       ppBlob,
                                                         ID3DBlob**                       ppErrorBlob);

typedef HRESULT(WINAPI* PFN_D3D12GETINTERFACE)(REFCLSID rclsid, REFIID riid, void** ppvDebug);

typedef HRESULT(WINAPI* PFN_D3D12SERIALIZEVERSIONEDROOTSIGNATURE)(
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature, ID3DBlob** ppBlob, ID3DBlob** ppErrorBlob);

//-----------------------------------------------------------------------------
/// This class is responsible for hooking D3D12 module entry points. It contains
/// a "Mine" implementation for each hooked function.
//-----------------------------------------------------------------------------
class Hook_D3D12
{
  public:
    static Hook_D3D12* GetInterceptor();

    Hook_D3D12() {}
    virtual ~Hook_D3D12() {}

    static bool HookInterceptor(bool capture);
    static bool UnhookInterceptor();

    gfxrecon::util::interception::RealAndMineHook<PFN_D3D12CREATEDEVICE> hook_D3D12CreateDevice_;
    gfxrecon::util::interception::RealAndMineHook<PFN_D3D12CREATEROOTSIGNATUREDESERIALIZER>
        hook_D3D12CreateRootSignatureDeserializer_;
    gfxrecon::util::interception::RealAndMineHook<PFN_D3D12CREATEVERSIONEDROOTSIGNATUREDESERIALIZER>
        hook_D3D12CreateVersionedRootSignatureDeserializer_;
    gfxrecon::util::interception::RealAndMineHook<PFN_D3D12ENABLEEXPERIMENTALFEATURES>
                                                                              hook_D3D12EnableExperimentalFeatures_;
    gfxrecon::util::interception::RealAndMineHook<PFN_D3D12GETDEBUGINTERFACE> hook_D3D12GetDebugInterface_;
    gfxrecon::util::interception::RealAndMineHook<PFN_D3D12SERIALIZEROOTSIGNATURE> hook_D3D12SerializeRootSignature_;
    gfxrecon::util::interception::RealAndMineHook<PFN_D3D12SERIALIZEVERSIONEDROOTSIGNATURE>
                                                                         hook_D3D12SerializeVersionedRootSignature_;
    gfxrecon::util::interception::RealAndMineHook<PFN_D3D12GETINTERFACE> hook_D3D12GetInterface_;
};
#endif // GFXRECON_HOOK_D3D12_H
