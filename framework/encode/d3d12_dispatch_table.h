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

#ifndef GFXRECON_ENCODE_D3D12_DISPATCH_TABLE_H
#define GFXRECON_ENCODE_D3D12_DISPATCH_TABLE_H

#include "util/defines.h"
#include "util/logging.h"

#include <d3d12.h>
#include <windows.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

struct D3D12DispatchTable
{
    // Functions processed for capture.  These are the D3D12 functions exported by d3d12.dll and documented on MSDN.
    PFN_D3D12_CREATE_DEVICE                                D3D12CreateDevice{ nullptr };
    PFN_D3D12_CREATE_ROOT_SIGNATURE_DESERIALIZER           D3D12CreateRootSignatureDeserializer{ nullptr };
    PFN_D3D12_CREATE_VERSIONED_ROOT_SIGNATURE_DESERIALIZER D3D12CreateVersionedRootSignatureDeserializer{ nullptr };
    PFN_D3D12_GET_DEBUG_INTERFACE                          D3D12GetDebugInterface{ nullptr };
    PFN_D3D12_SERIALIZE_ROOT_SIGNATURE                     D3D12SerializeRootSignature{ nullptr };
    PFN_D3D12_SERIALIZE_VERSIONED_ROOT_SIGNATURE           D3D12SerializeVersionedRootSignature{ nullptr };
    PFN_D3D12_GET_INTERFACE                                D3D12GetInterface{ nullptr };
    PFN_D3D12_CREATE_VERSIONED_ROOT_SIGNATURE_DESERIALIZER_FROM_SUBOBJECT_IN_LIBRARY
    D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary{ nullptr };
    // NOTE: There is no typedef in d3d12.h for D3D12EnableExperimentalFeatures.
    decltype(D3D12EnableExperimentalFeatures)* D3D12EnableExperimentalFeatures{ nullptr };
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

typedef bool (*PFN_InitializeD3D12Capture)(gfxrecon::encode::D3D12DispatchTable*);
typedef void (*PFN_ReleaseD3D12Capture)(gfxrecon::encode::D3D12DispatchTable*);

#endif // GFXRECON_ENCODE_D3D12_DISPATCH_TABLE_H
