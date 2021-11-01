/*
** Copyright (c) 2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
*/

/*
** This file is generated from dx12_ascii_consumer_body_generator.py.
**
*/

#include "generated_dx12_ascii_consumer.h"
#include "generated_dx12_enum_to_string.h"
#include "generated_dx12_struct_to_string.h"
#include "decode/custom_dx12_ascii_consumer.h"
#include "decode/dx12_enum_util.h"
#include "util/interception/injection.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/*
** This part is generated from dxgi.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_CreateDXGIFactory(
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "CreateDXGIFactory";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppFactory", to_string_flags, tab_count, tab_size, HandleIdToString(ppFactory));
        }
    );
}

void Dx12AsciiConsumer::Process_CreateDXGIFactory1(
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "CreateDXGIFactory1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppFactory", to_string_flags, tab_count, tab_size, HandleIdToString(ppFactory));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIObject_SetPrivateData(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIObject";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPrivateData";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Name", to_string_flags, tab_count, tab_size, ToString(*Name.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags, tab_count, tab_size, ToString(DataSize, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIObject_SetPrivateDataInterface(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        format::HandleId pUnknown)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIObject";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPrivateDataInterface";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Name", to_string_flags, tab_count, tab_size, ToString(*Name.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pUnknown", to_string_flags, tab_count, tab_size, HandleIdToString(pUnknown));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIObject_GetPrivateData(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIObject";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPrivateData";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Name", to_string_flags, tab_count, tab_size, ToString(*Name.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDataSize", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDataSize, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(pDataSize, pData, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIObject_GetParent(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParent)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIObject";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetParent";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppParent", to_string_flags, tab_count, tab_size, HandleIdToString(ppParent));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDeviceSubObject_GetDevice(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDeviceSubObject";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDevice";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppDevice", to_string_flags, tab_count, tab_size, HandleIdToString(ppDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource_GetSharedHandle(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pSharedHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSharedHandle";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pSharedHandle", to_string_flags, tab_count, tab_size, HandleIdToString(pSharedHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource_GetUsage(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<DXGI_USAGE>* pUsage)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetUsage";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pUsage", to_string_flags, tab_count, tab_size, PointerDecoderToString(pUsage, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource_SetEvictionPriority(
        format::HandleId object_id,
        HRESULT return_value,
        UINT EvictionPriority)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEvictionPriority";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "EvictionPriority", to_string_flags, tab_count, tab_size, ToString(EvictionPriority, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource_GetEvictionPriority(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pEvictionPriority)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetEvictionPriority";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pEvictionPriority", to_string_flags, tab_count, tab_size, PointerDecoderToString(pEvictionPriority, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIKeyedMutex_AcquireSync(
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Key,
        DWORD dwMilliseconds)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIKeyedMutex";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AcquireSync";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Key", to_string_flags, tab_count, tab_size, ToString(Key, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "dwMilliseconds", to_string_flags, tab_count, tab_size, ToString(dwMilliseconds, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIKeyedMutex_ReleaseSync(
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Key)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIKeyedMutex";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReleaseSync";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Key", to_string_flags, tab_count, tab_size, ToString(Key, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface_GetDesc(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface_Map(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect,
        UINT MapFlags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Map";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pLockedRect", to_string_flags, tab_count, tab_size, PointerDecoderToString(pLockedRect, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "MapFlags", to_string_flags, tab_count, tab_size, ToString(MapFlags, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface_Unmap(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Unmap";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface1_GetDC(
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Discard,
        PointerDecoder<uint64_t, void*>* phdc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDC";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Discard", to_string_flags, tab_count, tab_size, ToString(Discard, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]phdc", to_string_flags, tab_count, tab_size, HandleIdToString(phdc));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface1_ReleaseDC(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRect)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReleaseDC";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDirtyRect", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDirtyRect, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter_EnumOutputs(
        format::HandleId object_id,
        HRESULT return_value,
        UINT Output,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumOutputs";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Output", to_string_flags, tab_count, tab_size, ToString(Output, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppOutput", to_string_flags, tab_count, tab_size, HandleIdToString(ppOutput));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter_GetDesc(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter_CheckInterfaceSupport(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID InterfaceName,
        StructPointerDecoder<Decoded_LARGE_INTEGER>* pUMDVersion)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckInterfaceSupport";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "InterfaceName", to_string_flags, tab_count, tab_size, ToString(*InterfaceName.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pUMDVersion", to_string_flags, tab_count, tab_size, PointerDecoderToString(pUMDVersion, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetDesc(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetDisplayModeList(
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDisplayModeList";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "EnumFormat", to_string_flags, tab_count, tab_size, '"' + ToString(EnumFormat, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, ToString(Flags, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pNumModes", to_string_flags, tab_count, tab_size, PointerDecoderToString(pNumModes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(pNumModes, pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_FindClosestMatchingMode(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pClosestMatch,
        format::HandleId pConcernedDevice)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "FindClosestMatchingMode";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pModeToMatch", to_string_flags, tab_count, tab_size, PointerDecoderToString(pModeToMatch, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pClosestMatch", to_string_flags, tab_count, tab_size, PointerDecoderToString(pClosestMatch, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pConcernedDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pConcernedDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_WaitForVBlank(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "WaitForVBlank";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_TakeOwnership(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        BOOL Exclusive)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "TakeOwnership";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "Exclusive", to_string_flags, tab_count, tab_size, ToString(Exclusive, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_ReleaseOwnership(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReleaseOwnership";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetGammaControlCapabilities(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES>* pGammaCaps)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetGammaControlCapabilities";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pGammaCaps", to_string_flags, tab_count, tab_size, PointerDecoderToString(pGammaCaps, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_SetGammaControl(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGammaControl";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pArray", to_string_flags, tab_count, tab_size, PointerDecoderToString(pArray, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetGammaControl(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetGammaControl";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pArray", to_string_flags, tab_count, tab_size, PointerDecoderToString(pArray, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_SetDisplaySurface(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pScanoutSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDisplaySurface";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pScanoutSurface", to_string_flags, tab_count, tab_size, HandleIdToString(pScanoutSurface));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetDisplaySurfaceData(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDestination)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDisplaySurfaceData";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDestination", to_string_flags, tab_count, tab_size, HandleIdToString(pDestination));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetFrameStatistics(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameStatistics";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pStats", to_string_flags, tab_count, tab_size, PointerDecoderToString(pStats, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_Present(
        format::HandleId object_id,
        HRESULT return_value,
        UINT SyncInterval,
        UINT Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Present";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "SyncInterval", to_string_flags, tab_count, tab_size, ToString(SyncInterval, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, ToString(Flags, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetBuffer(
        format::HandleId object_id,
        HRESULT return_value,
        UINT Buffer,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBuffer";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Buffer", to_string_flags, tab_count, tab_size, ToString(Buffer, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSurface", to_string_flags, tab_count, tab_size, HandleIdToString(ppSurface));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_SetFullscreenState(
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Fullscreen,
        format::HandleId pTarget)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetFullscreenState";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Fullscreen", to_string_flags, tab_count, tab_size, ToString(Fullscreen, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pTarget", to_string_flags, tab_count, tab_size, HandleIdToString(pTarget));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetFullscreenState(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<BOOL>* pFullscreen,
        HandlePointerDecoder<IDXGIOutput*>* ppTarget)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFullscreenState";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pFullscreen", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFullscreen, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppTarget", to_string_flags, tab_count, tab_size, HandleIdToString(ppTarget));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetDesc(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_ResizeBuffers(
        format::HandleId object_id,
        HRESULT return_value,
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT NewFormat,
        UINT SwapChainFlags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResizeBuffers";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "BufferCount", to_string_flags, tab_count, tab_size, ToString(BufferCount, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Width", to_string_flags, tab_count, tab_size, ToString(Width, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Height", to_string_flags, tab_count, tab_size, ToString(Height, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NewFormat", to_string_flags, tab_count, tab_size, '"' + ToString(NewFormat, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "SwapChainFlags", to_string_flags, tab_count, tab_size, ToString(SwapChainFlags, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_ResizeTarget(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pNewTargetParameters)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResizeTarget";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pNewTargetParameters", to_string_flags, tab_count, tab_size, PointerDecoderToString(pNewTargetParameters, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetContainingOutput(
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetContainingOutput";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]ppOutput", to_string_flags, tab_count, tab_size, HandleIdToString(ppOutput));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetFrameStatistics(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameStatistics";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pStats", to_string_flags, tab_count, tab_size, PointerDecoderToString(pStats, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetLastPresentCount(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pLastPresentCount)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetLastPresentCount";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pLastPresentCount", to_string_flags, tab_count, tab_size, PointerDecoderToString(pLastPresentCount, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory_EnumAdapters(
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumAdapters";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Adapter", to_string_flags, tab_count, tab_size, ToString(Adapter, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppAdapter", to_string_flags, tab_count, tab_size, HandleIdToString(ppAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory_MakeWindowAssociation(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "MakeWindowAssociation";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "WindowHandle", to_string_flags, tab_count, tab_size, HandleIdToString(WindowHandle));
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, ToString(Flags, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory_GetWindowAssociation(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pWindowHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetWindowAssociation";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pWindowHandle", to_string_flags, tab_count, tab_size, HandleIdToString(pWindowHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory_CreateSwapChain(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc,
        HandlePointerDecoder<IDXGISwapChain*>* ppSwapChain)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSwapChain";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags, tab_count, tab_size, HandleIdToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory_CreateSoftwareAdapter(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t Module,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSoftwareAdapter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Module", to_string_flags, tab_count, tab_size, HandleIdToString(Module));
            FieldToString(str_strm, false, "[out]ppAdapter", to_string_flags, tab_count, tab_size, HandleIdToString(ppAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice_GetAdapter(
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIAdapter*>* pAdapter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetAdapter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pAdapter", to_string_flags, tab_count, tab_size, HandleIdToString(pAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice_CreateSurface(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc,
        UINT NumSurfaces,
        DXGI_USAGE Usage,
        StructPointerDecoder<Decoded_DXGI_SHARED_RESOURCE>* pSharedResource,
        HandlePointerDecoder<IDXGISurface*>* ppSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSurface";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumSurfaces", to_string_flags, tab_count, tab_size, ToString(NumSurfaces, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Usage", to_string_flags, tab_count, tab_size, ToString(Usage, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSharedResource", to_string_flags, tab_count, tab_size, PointerDecoderToString(pSharedResource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSurface", to_string_flags, tab_count, tab_size, HandleIdToString(ppSurface));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice_QueryResourceResidency(
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IUnknown*>* ppResources,
        PointerDecoder<DXGI_RESIDENCY>* pResidencyStatus,
        UINT NumResources)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "QueryResourceResidency";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ppResources", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumResources, ppResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pResidencyStatus", to_string_flags, tab_count, tab_size, EnumPointerDecoderArrayToString(NumResources, pResidencyStatus, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumResources", to_string_flags, tab_count, tab_size, ToString(NumResources, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice_SetGPUThreadPriority(
        format::HandleId object_id,
        HRESULT return_value,
        INT Priority)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGPUThreadPriority";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Priority", to_string_flags, tab_count, tab_size, ToString(Priority, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice_GetGPUThreadPriority(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<INT>* pPriority)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetGPUThreadPriority";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pPriority", to_string_flags, tab_count, tab_size, PointerDecoderToString(pPriority, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory1_EnumAdapters1(
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter1*>* ppAdapter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumAdapters1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Adapter", to_string_flags, tab_count, tab_size, ToString(Adapter, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppAdapter", to_string_flags, tab_count, tab_size, HandleIdToString(ppAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory1_IsCurrent(
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IsCurrent";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter1_GetDesc1(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice1_SetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT return_value,
        UINT MaxLatency)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMaximumFrameLatency";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "MaxLatency", to_string_flags, tab_count, tab_size, ToString(MaxLatency, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice1_GetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pMaxLatency)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMaximumFrameLatency";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pMaxLatency", to_string_flags, tab_count, tab_size, PointerDecoderToString(pMaxLatency, to_string_flags, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IDXGIDisplayControl_IsStereoEnabled(
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDisplayControl";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IsStereoEnabled";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDisplayControl_SetStereoEnabled(
        format::HandleId object_id,
        BOOL enabled)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDisplayControl";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetStereoEnabled";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "enabled", to_string_flags, tab_count, tab_size, ToString(enabled, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetDesc(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_AcquireNextFrame(
        format::HandleId object_id,
        HRESULT return_value,
        UINT TimeoutInMilliseconds,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_FRAME_INFO>* pFrameInfo,
        HandlePointerDecoder<IDXGIResource*>* ppDesktopResource)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AcquireNextFrame";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "TimeoutInMilliseconds", to_string_flags, tab_count, tab_size, ToString(TimeoutInMilliseconds, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pFrameInfo", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFrameInfo, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppDesktopResource", to_string_flags, tab_count, tab_size, HandleIdToString(ppDesktopResource));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFrameDirtyRects(
        format::HandleId object_id,
        HRESULT return_value,
        UINT DirtyRectsBufferSize,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRectsBuffer,
        PointerDecoder<UINT>* pDirtyRectsBufferSizeRequired)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameDirtyRects";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DirtyRectsBufferSize", to_string_flags, tab_count, tab_size, ToString(DirtyRectsBufferSize, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDirtyRectsBuffer", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DirtyRectsBufferSize/sizeof tagRECT, pDirtyRectsBuffer, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDirtyRectsBufferSizeRequired", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDirtyRectsBufferSizeRequired, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFrameMoveRects(
        format::HandleId object_id,
        HRESULT return_value,
        UINT MoveRectsBufferSize,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_MOVE_RECT>* pMoveRectBuffer,
        PointerDecoder<UINT>* pMoveRectsBufferSizeRequired)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameMoveRects";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "MoveRectsBufferSize", to_string_flags, tab_count, tab_size, ToString(MoveRectsBufferSize, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pMoveRectBuffer", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(MoveRectsBufferSize/sizeof DXGI_OUTDUPL_MOVE_RECT, pMoveRectBuffer, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pMoveRectsBufferSizeRequired", to_string_flags, tab_count, tab_size, PointerDecoderToString(pMoveRectsBufferSizeRequired, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFramePointerShape(
        format::HandleId object_id,
        HRESULT return_value,
        UINT PointerShapeBufferSize,
        PointerDecoder<uint8_t>* pPointerShapeBuffer,
        PointerDecoder<UINT>* pPointerShapeBufferSizeRequired,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO>* pPointerShapeInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFramePointerShape";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "PointerShapeBufferSize", to_string_flags, tab_count, tab_size, ToString(PointerShapeBufferSize, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pPointerShapeBuffer", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(PointerShapeBufferSize, pPointerShapeBuffer, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pPointerShapeBufferSizeRequired", to_string_flags, tab_count, tab_size, PointerDecoderToString(pPointerShapeBufferSizeRequired, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pPointerShapeInfo", to_string_flags, tab_count, tab_size, PointerDecoderToString(pPointerShapeInfo, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_MapDesktopSurface(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "MapDesktopSurface";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pLockedRect", to_string_flags, tab_count, tab_size, PointerDecoderToString(pLockedRect, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_UnMapDesktopSurface(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnMapDesktopSurface";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_ReleaseFrame(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReleaseFrame";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface2_GetResource(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParentResource,
        PointerDecoder<UINT>* pSubresourceIndex)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetResource";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppParentResource", to_string_flags, tab_count, tab_size, HandleIdToString(ppParentResource));
            FieldToString(str_strm, false, "[out]pSubresourceIndex", to_string_flags, tab_count, tab_size, PointerDecoderToString(pSubresourceIndex, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource1_CreateSubresourceSurface(
        format::HandleId object_id,
        HRESULT return_value,
        UINT index,
        HandlePointerDecoder<IDXGISurface2*>* ppSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSubresourceSurface";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "index", to_string_flags, tab_count, tab_size, ToString(index, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSurface", to_string_flags, tab_count, tab_size, HandleIdToString(ppSurface));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource1_CreateSharedHandle(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD dwAccess,
        WStringDecoder* lpName,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSharedHandle";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pAttributes", to_string_flags, tab_count, tab_size, PointerDecoderToString(pAttributes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "dwAccess", to_string_flags, tab_count, tab_size, ToString(dwAccess, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "lpName", to_string_flags, tab_count, tab_size, PointerDecoderToString(lpName, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pHandle", to_string_flags, tab_count, tab_size, HandleIdToString(pHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice2_OfferResources(
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OfferResources";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumResources", to_string_flags, tab_count, tab_size, ToString(NumResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppResources", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumResources, ppResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Priority", to_string_flags, tab_count, tab_size, '"' + ToString(Priority, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice2_ReclaimResources(
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<BOOL>* pDiscarded)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReclaimResources";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumResources", to_string_flags, tab_count, tab_size, ToString(NumResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppResources", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumResources, ppResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDiscarded", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumResources, pDiscarded, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice2_EnqueueSetEvent(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnqueueSetEvent";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags, tab_count, tab_size, HandleIdToString(hEvent));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetDesc1(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetFullscreenDesc(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFullscreenDesc";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetHwnd(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pHwnd)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetHwnd";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pHwnd", to_string_flags, tab_count, tab_size, HandleIdToString(pHwnd));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetCoreWindow(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID refiid,
        HandlePointerDecoder<void*>* ppUnk)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCoreWindow";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "refiid", to_string_flags, tab_count, tab_size, ToString(*refiid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppUnk", to_string_flags, tab_count, tab_size, HandleIdToString(ppUnk));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_Present1(
        format::HandleId object_id,
        HRESULT return_value,
        UINT SyncInterval,
        UINT PresentFlags,
        StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* pPresentParameters)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Present1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "SyncInterval", to_string_flags, tab_count, tab_size, ToString(SyncInterval, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "PresentFlags", to_string_flags, tab_count, tab_size, ToString(PresentFlags, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pPresentParameters", to_string_flags, tab_count, tab_size, PointerDecoderToString(pPresentParameters, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_IsTemporaryMonoSupported(
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IsTemporaryMonoSupported";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetRestrictToOutput(
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIOutput*>* ppRestrictToOutput)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRestrictToOutput";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]ppRestrictToOutput", to_string_flags, tab_count, tab_size, HandleIdToString(ppRestrictToOutput));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_SetBackgroundColor(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBackgroundColor";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pColor", to_string_flags, tab_count, tab_size, PointerDecoderToString(pColor, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetBackgroundColor(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBackgroundColor";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pColor", to_string_flags, tab_count, tab_size, PointerDecoderToString(pColor, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_SetRotation(
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_MODE_ROTATION Rotation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetRotation";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Rotation", to_string_flags, tab_count, tab_size, '"' + ToString(Rotation, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetRotation(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<DXGI_MODE_ROTATION>* pRotation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRotation";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pRotation", to_string_flags, tab_count, tab_size, EnumPointerDecoderToString(pRotation));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_IsWindowedStereoEnabled(
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IsWindowedStereoEnabled";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForHwnd(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        uint64_t hWnd,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pFullscreenDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSwapChainForHwnd";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "hWnd", to_string_flags, tab_count, tab_size, HandleIdToString(hWnd));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pFullscreenDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFullscreenDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRestrictToOutput", to_string_flags, tab_count, tab_size, HandleIdToString(pRestrictToOutput));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags, tab_count, tab_size, HandleIdToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForCoreWindow(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        format::HandleId pWindow,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSwapChainForCoreWindow";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "pWindow", to_string_flags, tab_count, tab_size, HandleIdToString(pWindow));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRestrictToOutput", to_string_flags, tab_count, tab_size, HandleIdToString(pRestrictToOutput));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags, tab_count, tab_size, HandleIdToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_GetSharedResourceAdapterLuid(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hResource,
        StructPointerDecoder<Decoded_LUID>* pLuid)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSharedResourceAdapterLuid";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hResource", to_string_flags, tab_count, tab_size, HandleIdToString(hResource));
            FieldToString(str_strm, false, "[out]pLuid", to_string_flags, tab_count, tab_size, PointerDecoderToString(pLuid, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterStereoStatusWindow(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterStereoStatusWindow";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "WindowHandle", to_string_flags, tab_count, tab_size, HandleIdToString(WindowHandle));
            FieldToString(str_strm, false, "wMsg", to_string_flags, tab_count, tab_size, ToString(wMsg, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterStereoStatusEvent(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterStereoStatusEvent";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags, tab_count, tab_size, HandleIdToString(hEvent));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_UnregisterStereoStatus(
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterStereoStatus";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "dwCookie", to_string_flags, tab_count, tab_size, ToString(dwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusWindow(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterOcclusionStatusWindow";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "WindowHandle", to_string_flags, tab_count, tab_size, HandleIdToString(WindowHandle));
            FieldToString(str_strm, false, "wMsg", to_string_flags, tab_count, tab_size, ToString(wMsg, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusEvent(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterOcclusionStatusEvent";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags, tab_count, tab_size, HandleIdToString(hEvent));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_UnregisterOcclusionStatus(
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterOcclusionStatus";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "dwCookie", to_string_flags, tab_count, tab_size, ToString(dwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForComposition(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSwapChainForComposition";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRestrictToOutput", to_string_flags, tab_count, tab_size, HandleIdToString(pRestrictToOutput));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags, tab_count, tab_size, HandleIdToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter2_GetDesc2(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc2";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput1_GetDisplayModeList1(
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDisplayModeList1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "EnumFormat", to_string_flags, tab_count, tab_size, '"' + ToString(EnumFormat, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, ToString(Flags, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pNumModes", to_string_flags, tab_count, tab_size, PointerDecoderToString(pNumModes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(pNumModes, pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput1_FindClosestMatchingMode1(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pClosestMatch,
        format::HandleId pConcernedDevice)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "FindClosestMatchingMode1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pModeToMatch", to_string_flags, tab_count, tab_size, PointerDecoderToString(pModeToMatch, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pClosestMatch", to_string_flags, tab_count, tab_size, PointerDecoderToString(pClosestMatch, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pConcernedDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pConcernedDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput1_GetDisplaySurfaceData1(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDestination)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDisplaySurfaceData1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDestination", to_string_flags, tab_count, tab_size, HandleIdToString(pDestination));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput1_DuplicateOutput(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DuplicateOutput";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "[out]ppOutputDuplication", to_string_flags, tab_count, tab_size, HandleIdToString(ppOutputDuplication));
        }
    );
}

/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_CreateDXGIFactory2(
        HRESULT return_value,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "CreateDXGIFactory2";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags, tab_count, tab_size, ToString(Flags, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppFactory", to_string_flags, tab_count, tab_size, HandleIdToString(ppFactory));
        }
    );
}

void Dx12AsciiConsumer::Process_DXGIGetDebugInterface1(
        HRESULT return_value,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* pDebug)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "DXGIGetDebugInterface1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags, tab_count, tab_size, ToString(Flags, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDebug", to_string_flags, tab_count, tab_size, HandleIdToString(pDebug));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice3_Trim(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Trim";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetSourceSize(
        format::HandleId object_id,
        HRESULT return_value,
        UINT Width,
        UINT Height)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetSourceSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Width", to_string_flags, tab_count, tab_size, ToString(Width, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Height", to_string_flags, tab_count, tab_size, ToString(Height, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetSourceSize(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSourceSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pWidth", to_string_flags, tab_count, tab_size, PointerDecoderToString(pWidth, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pHeight", to_string_flags, tab_count, tab_size, PointerDecoderToString(pHeight, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT return_value,
        UINT MaxLatency)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMaximumFrameLatency";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "MaxLatency", to_string_flags, tab_count, tab_size, ToString(MaxLatency, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pMaxLatency)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMaximumFrameLatency";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pMaxLatency", to_string_flags, tab_count, tab_size, PointerDecoderToString(pMaxLatency, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(
        format::HandleId object_id,
        uint64_t return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameLatencyWaitableObject";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetMatrixTransform(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMatrixTransform";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pMatrix", to_string_flags, tab_count, tab_size, PointerDecoderToString(pMatrix, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetMatrixTransform(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMatrixTransform";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pMatrix", to_string_flags, tab_count, tab_size, PointerDecoderToString(pMatrix, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput2_SupportsOverlays(
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SupportsOverlays";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory3_GetCreationFlags(
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCreationFlags";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_PresentBuffer(
        format::HandleId object_id,
        HRESULT return_value,
        UINT BufferToPresent,
        UINT SyncInterval,
        UINT Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PresentBuffer";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "BufferToPresent", to_string_flags, tab_count, tab_size, ToString(BufferToPresent, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "SyncInterval", to_string_flags, tab_count, tab_size, ToString(SyncInterval, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, ToString(Flags, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetSourceRect(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetSourceRect";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRect", to_string_flags, tab_count, tab_size, PointerDecoderToString(pRect, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetTargetRect(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetTargetRect";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRect", to_string_flags, tab_count, tab_size, PointerDecoderToString(pRect, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetDestSize(
        format::HandleId object_id,
        HRESULT return_value,
        UINT Width,
        UINT Height)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDestSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Width", to_string_flags, tab_count, tab_size, ToString(Width, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Height", to_string_flags, tab_count, tab_size, ToString(Height, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetSourceRect(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSourceRect";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pRect", to_string_flags, tab_count, tab_size, PointerDecoderToString(pRect, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetTargetRect(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetTargetRect";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pRect", to_string_flags, tab_count, tab_size, PointerDecoderToString(pRect, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetDestSize(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDestSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pWidth", to_string_flags, tab_count, tab_size, PointerDecoderToString(pWidth, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pHeight", to_string_flags, tab_count, tab_size, PointerDecoderToString(pHeight, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetColorSpace(
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetColorSpace";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ColorSpace", to_string_flags, tab_count, tab_size, '"' + ToString(ColorSpace, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetColorSpace(
        format::HandleId object_id,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetColorSpace";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        uint64_t hSurface,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactoryMedia";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSwapChainForCompositionSurfaceHandle";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "hSurface", to_string_flags, tab_count, tab_size, HandleIdToString(hSurface));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRestrictToOutput", to_string_flags, tab_count, tab_size, HandleIdToString(pRestrictToOutput));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags, tab_count, tab_size, HandleIdToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        uint64_t hSurface,
        StructPointerDecoder<Decoded_DXGI_DECODE_SWAP_CHAIN_DESC>* pDesc,
        format::HandleId pYuvDecodeBuffers,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGIDecodeSwapChain*>* ppSwapChain)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactoryMedia";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateDecodeSwapChainForCompositionSurfaceHandle";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "hSurface", to_string_flags, tab_count, tab_size, HandleIdToString(hSurface));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pYuvDecodeBuffers", to_string_flags, tab_count, tab_size, HandleIdToString(pYuvDecodeBuffers));
            FieldToString(str_strm, false, "pRestrictToOutput", to_string_flags, tab_count, tab_size, HandleIdToString(pRestrictToOutput));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags, tab_count, tab_size, HandleIdToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA>* pStats)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChainMedia";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameStatisticsMedia";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pStats", to_string_flags, tab_count, tab_size, PointerDecoderToString(pStats, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_SetPresentDuration(
        format::HandleId object_id,
        HRESULT return_value,
        UINT Duration)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChainMedia";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPresentDuration";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Duration", to_string_flags, tab_count, tab_size, ToString(Duration, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_CheckPresentDurationSupport(
        format::HandleId object_id,
        HRESULT return_value,
        UINT DesiredPresentDuration,
        PointerDecoder<UINT>* pClosestSmallerPresentDuration,
        PointerDecoder<UINT>* pClosestLargerPresentDuration)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChainMedia";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckPresentDurationSupport";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DesiredPresentDuration", to_string_flags, tab_count, tab_size, ToString(DesiredPresentDuration, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pClosestSmallerPresentDuration", to_string_flags, tab_count, tab_size, PointerDecoderToString(pClosestSmallerPresentDuration, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pClosestLargerPresentDuration", to_string_flags, tab_count, tab_size, PointerDecoderToString(pClosestLargerPresentDuration, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput3_CheckOverlaySupport(
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        format::HandleId pConcernedDevice,
        PointerDecoder<UINT>* pFlags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckOverlaySupport";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "EnumFormat", to_string_flags, tab_count, tab_size, '"' + ToString(EnumFormat, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pConcernedDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pConcernedDevice));
            FieldToString(str_strm, false, "[out]pFlags", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFlags, to_string_flags, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCurrentBackBufferIndex";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain3_CheckColorSpaceSupport(
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        PointerDecoder<UINT>* pColorSpaceSupport)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckColorSpaceSupport";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ColorSpace", to_string_flags, tab_count, tab_size, '"' + ToString(ColorSpace, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "[out]pColorSpaceSupport", to_string_flags, tab_count, tab_size, PointerDecoderToString(pColorSpaceSupport, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain3_SetColorSpace1(
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_COLOR_SPACE_TYPE ColorSpace)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetColorSpace1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ColorSpace", to_string_flags, tab_count, tab_size, '"' + ToString(ColorSpace, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain3_ResizeBuffers1(
        format::HandleId object_id,
        HRESULT return_value,
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT Format,
        UINT SwapChainFlags,
        PointerDecoder<UINT>* pCreationNodeMask,
        HandlePointerDecoder<IUnknown*>* ppPresentQueue)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResizeBuffers1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "BufferCount", to_string_flags, tab_count, tab_size, ToString(BufferCount, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Width", to_string_flags, tab_count, tab_size, ToString(Width, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Height", to_string_flags, tab_count, tab_size, ToString(Height, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Format", to_string_flags, tab_count, tab_size, '"' + ToString(Format, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "SwapChainFlags", to_string_flags, tab_count, tab_size, ToString(SwapChainFlags, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pCreationNodeMask", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(BufferCount, pCreationNodeMask, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppPresentQueue", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(BufferCount, ppPresentQueue, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput4_CheckOverlayColorSpaceSupport(
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT Format,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        format::HandleId pConcernedDevice,
        PointerDecoder<UINT>* pFlags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckOverlayColorSpaceSupport";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Format", to_string_flags, tab_count, tab_size, '"' + ToString(Format, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ColorSpace", to_string_flags, tab_count, tab_size, '"' + ToString(ColorSpace, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pConcernedDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pConcernedDevice));
            FieldToString(str_strm, false, "[out]pFlags", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFlags, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory4_EnumAdapterByLuid(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_LUID AdapterLuid,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumAdapterByLuid";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "AdapterLuid", to_string_flags, tab_count, tab_size, ToString(*AdapterLuid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvAdapter", to_string_flags, tab_count, tab_size, HandleIdToString(ppvAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory4_EnumWarpAdapter(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumWarpAdapter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvAdapter", to_string_flags, tab_count, tab_size, HandleIdToString(ppvAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterHardwareContentProtectionTeardownStatusEvent";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags, tab_count, tab_size, HandleIdToString(hEvent));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterHardwareContentProtectionTeardownStatus";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "dwCookie", to_string_flags, tab_count, tab_size, ToString(dwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_QueryVideoMemoryInfo(
        format::HandleId object_id,
        HRESULT return_value,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        StructPointerDecoder<Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO>* pVideoMemoryInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "QueryVideoMemoryInfo";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NodeIndex", to_string_flags, tab_count, tab_size, ToString(NodeIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "MemorySegmentGroup", to_string_flags, tab_count, tab_size, '"' + ToString(MemorySegmentGroup, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "[out]pVideoMemoryInfo", to_string_flags, tab_count, tab_size, PointerDecoderToString(pVideoMemoryInfo, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_SetVideoMemoryReservation(
        format::HandleId object_id,
        HRESULT return_value,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        UINT64 Reservation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetVideoMemoryReservation";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NodeIndex", to_string_flags, tab_count, tab_size, ToString(NodeIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "MemorySegmentGroup", to_string_flags, tab_count, tab_size, '"' + ToString(MemorySegmentGroup, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "Reservation", to_string_flags, tab_count, tab_size, ToString(Reservation, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterVideoMemoryBudgetChangeNotificationEvent";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags, tab_count, tab_size, HandleIdToString(hEvent));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterVideoMemoryBudgetChangeNotification";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "dwCookie", to_string_flags, tab_count, tab_size, ToString(dwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IDXGIOutput5_DuplicateOutput1(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        UINT Flags,
        UINT SupportedFormatsCount,
        PointerDecoder<DXGI_FORMAT>* pSupportedFormats,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DuplicateOutput1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, ToString(Flags, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "SupportedFormatsCount", to_string_flags, tab_count, tab_size, ToString(SupportedFormatsCount, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSupportedFormats", to_string_flags, tab_count, tab_size, EnumPointerDecoderArrayToString(SupportedFormatsCount, pSupportedFormats, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppOutputDuplication", to_string_flags, tab_count, tab_size, HandleIdToString(ppOutputDuplication));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain4_SetHDRMetaData(
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_HDR_METADATA_TYPE Type,
        UINT Size,
        PointerDecoder<uint8_t>* pMetaData)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetHDRMetaData";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "Size", to_string_flags, tab_count, tab_size, ToString(Size, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pMetaData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Size, pMetaData, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice4_OfferResources1(
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority,
        UINT Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OfferResources1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumResources", to_string_flags, tab_count, tab_size, ToString(NumResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppResources", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumResources, ppResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Priority", to_string_flags, tab_count, tab_size, '"' + ToString(Priority, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, ToString(Flags, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice4_ReclaimResources1(
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<DXGI_RECLAIM_RESOURCE_RESULTS>* pResults)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReclaimResources1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumResources", to_string_flags, tab_count, tab_size, ToString(NumResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppResources", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumResources, ppResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pResults", to_string_flags, tab_count, tab_size, EnumPointerDecoderArrayToString(NumResources, pResults, to_string_flags, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_DXGIDeclareAdapterRemovalSupport(
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "DXGIDeclareAdapterRemovalSupport";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter4_GetDesc3(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc3";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput6_GetDesc1(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput6_CheckHardwareCompositionSupport(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pFlags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckHardwareCompositionSupport";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pFlags", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFlags, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory6_EnumAdapterByGpuPreference(
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        DXGI_GPU_PREFERENCE GpuPreference,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumAdapterByGpuPreference";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Adapter", to_string_flags, tab_count, tab_size, ToString(Adapter, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "GpuPreference", to_string_flags, tab_count, tab_size, '"' + ToString(GpuPreference, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvAdapter", to_string_flags, tab_count, tab_size, HandleIdToString(ppvAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory7_RegisterAdaptersChangedEvent(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory7";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterAdaptersChangedEvent";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags, tab_count, tab_size, HandleIdToString(hEvent));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(
        format::HandleId object_id,
        HRESULT return_value,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory7";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterAdaptersChangedEvent";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "dwCookie", to_string_flags, tab_count, tab_size, ToString(dwCookie, to_string_flags, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from d3d12.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_D3D12SerializeRootSignature(
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* pRootSignature,
        D3D_ROOT_SIGNATURE_VERSION Version,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12SerializeRootSignature";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRootSignature", to_string_flags, tab_count, tab_size, PointerDecoderToString(pRootSignature, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Version", to_string_flags, tab_count, tab_size, '"' + ToString(Version, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "[out]ppBlob", to_string_flags, tab_count, tab_size, HandleIdToString(ppBlob));
            FieldToString(str_strm, false, "[out]ppErrorBlob", to_string_flags, tab_count, tab_size, HandleIdToString(ppErrorBlob));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12SerializeVersionedRootSignature(
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pRootSignature,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12SerializeVersionedRootSignature";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRootSignature", to_string_flags, tab_count, tab_size, PointerDecoderToString(pRootSignature, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppBlob", to_string_flags, tab_count, tab_size, HandleIdToString(ppBlob));
            FieldToString(str_strm, false, "[out]ppErrorBlob", to_string_flags, tab_count, tab_size, HandleIdToString(ppErrorBlob));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12CreateVersionedRootSignatureDeserializer(
        HRESULT return_value,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        Decoded_GUID pRootSignatureDeserializerInterface,
        HandlePointerDecoder<void*>* ppRootSignatureDeserializer)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12CreateVersionedRootSignatureDeserializer";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pSrcData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(SrcDataSizeInBytes, pSrcData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcDataSizeInBytes", to_string_flags, tab_count, tab_size, ToString(SrcDataSizeInBytes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRootSignatureDeserializerInterface", to_string_flags, tab_count, tab_size, ToString(*pRootSignatureDeserializerInterface.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppRootSignatureDeserializer", to_string_flags, tab_count, tab_size, HandleIdToString(ppRootSignatureDeserializer));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12CreateDevice(
        HRESULT return_value,
        format::HandleId pAdapter,
        D3D_FEATURE_LEVEL MinimumFeatureLevel,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12CreateDevice";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pAdapter", to_string_flags, tab_count, tab_size, HandleIdToString(pAdapter));
            FieldToString(str_strm, false, "MinimumFeatureLevel", to_string_flags, tab_count, tab_size, '"' + ToString(MinimumFeatureLevel, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppDevice", to_string_flags, tab_count, tab_size, HandleIdToString(ppDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12GetDebugInterface(
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDebug)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12GetDebugInterface";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvDebug", to_string_flags, tab_count, tab_size, HandleIdToString(ppvDebug));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12EnableExperimentalFeatures(
        HRESULT return_value,
        UINT NumFeatures,
        StructPointerDecoder<Decoded_GUID>* pIIDs,
        PointerDecoder<uint8_t>* pConfigurationStructs,
        PointerDecoder<UINT>* pConfigurationStructSizes)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12EnableExperimentalFeatures";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumFeatures", to_string_flags, tab_count, tab_size, ToString(NumFeatures, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pIIDs", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumFeatures, pIIDs, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pConfigurationStructs", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumFeatures, pConfigurationStructs, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pConfigurationStructSizes", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumFeatures, pConfigurationStructSizes, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Object_GetPrivateData(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Object";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPrivateData";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "guid", to_string_flags, tab_count, tab_size, ToString(*guid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDataSize", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDataSize, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(pDataSize, pData, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Object_SetPrivateData(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Object";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPrivateData";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "guid", to_string_flags, tab_count, tab_size, ToString(*guid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags, tab_count, tab_size, ToString(DataSize, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Object_SetPrivateDataInterface(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        format::HandleId pData)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Object";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPrivateDataInterface";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "guid", to_string_flags, tab_count, tab_size, ToString(*guid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, HandleIdToString(pData));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Object_SetName(
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* Name)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Object";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetName";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Name", to_string_flags, tab_count, tab_size, PointerDecoderToString(Name, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceChild_GetDevice(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDevice)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceChild";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDevice";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvDevice", to_string_flags, tab_count, tab_size, HandleIdToString(ppvDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
        format::HandleId object_id,
        HRESULT return_value,
        D3D_ROOT_SIGNATURE_VERSION convertToVersion,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* ppDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12VersionedRootSignatureDeserializer";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRootSignatureDescAtVersion";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "convertToVersion", to_string_flags, tab_count, tab_size, '"' + ToString(convertToVersion, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "[out]ppDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(ppDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_Map(
        format::HandleId object_id,
        HRESULT return_value,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pReadRange,
        PointerDecoder<uint64_t, void*>* ppData)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Map";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Subresource", to_string_flags, tab_count, tab_size, ToString(Subresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pReadRange", to_string_flags, tab_count, tab_size, PointerDecoderToString(pReadRange, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppData", to_string_flags, tab_count, tab_size, HandleIdToString(ppData));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_Unmap(
        format::HandleId object_id,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pWrittenRange)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Unmap";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Subresource", to_string_flags, tab_count, tab_size, ToString(Subresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pWrittenRange", to_string_flags, tab_count, tab_size, PointerDecoderToString(pWrittenRange, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_GetGPUVirtualAddress(
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetGPUVirtualAddress";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_WriteToSubresource(
        format::HandleId object_id,
        HRESULT return_value,
        UINT DstSubresource,
        StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
        uint64_t pSrcData,
        UINT SrcRowPitch,
        UINT SrcDepthPitch)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "WriteToSubresource";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DstSubresource", to_string_flags, tab_count, tab_size, ToString(DstSubresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDstBox", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDstBox, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcData", to_string_flags, tab_count, tab_size, HandleIdToString(pSrcData));
            FieldToString(str_strm, false, "SrcRowPitch", to_string_flags, tab_count, tab_size, ToString(SrcRowPitch, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcDepthPitch", to_string_flags, tab_count, tab_size, ToString(SrcDepthPitch, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_ReadFromSubresource(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t pDstData,
        UINT DstRowPitch,
        UINT DstDepthPitch,
        UINT SrcSubresource,
        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReadFromSubresource";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDstData", to_string_flags, tab_count, tab_size, HandleIdToString(pDstData));
            FieldToString(str_strm, false, "DstRowPitch", to_string_flags, tab_count, tab_size, ToString(DstRowPitch, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DstDepthPitch", to_string_flags, tab_count, tab_size, ToString(DstDepthPitch, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcSubresource", to_string_flags, tab_count, tab_size, ToString(SrcSubresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcBox", to_string_flags, tab_count, tab_size, PointerDecoderToString(pSrcBox, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_GetHeapProperties(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        PointerDecoder<D3D12_HEAP_FLAGS>* pHeapFlags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetHeapProperties";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pHeapProperties", to_string_flags, tab_count, tab_size, PointerDecoderToString(pHeapProperties, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pHeapFlags", to_string_flags, tab_count, tab_size, EnumPointerDecoderToString(pHeapFlags));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandAllocator_Reset(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandAllocator";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Reset";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Fence_GetCompletedValue(
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Fence";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCompletedValue";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Fence_SetEventOnCompletion(
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Value,
        uint64_t hEvent)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Fence";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEventOnCompletion";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Value", to_string_flags, tab_count, tab_size, ToString(Value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "hEvent", to_string_flags, tab_count, tab_size, HandleIdToString(hEvent));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Fence_Signal(
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Fence";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Signal";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Value", to_string_flags, tab_count, tab_size, ToString(Value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Fence1_GetCreationFlags(
        format::HandleId object_id,
        D3D12_FENCE_FLAGS return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Fence1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCreationFlags";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineState_GetCachedBlob(
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineState";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCachedBlob";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]ppBlob", to_string_flags, tab_count, tab_size, HandleIdToString(ppBlob));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Close(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Close";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Reset(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pAllocator,
        format::HandleId pInitialState)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Reset";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pAllocator", to_string_flags, tab_count, tab_size, HandleIdToString(pAllocator));
            FieldToString(str_strm, false, "pInitialState", to_string_flags, tab_count, tab_size, HandleIdToString(pInitialState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearState(
        format::HandleId object_id,
        format::HandleId pPipelineState)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearState";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pPipelineState", to_string_flags, tab_count, tab_size, HandleIdToString(pPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DrawInstanced(
        format::HandleId object_id,
        UINT VertexCountPerInstance,
        UINT InstanceCount,
        UINT StartVertexLocation,
        UINT StartInstanceLocation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DrawInstanced";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "VertexCountPerInstance", to_string_flags, tab_count, tab_size, ToString(VertexCountPerInstance, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "InstanceCount", to_string_flags, tab_count, tab_size, ToString(InstanceCount, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "StartVertexLocation", to_string_flags, tab_count, tab_size, ToString(StartVertexLocation, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "StartInstanceLocation", to_string_flags, tab_count, tab_size, ToString(StartInstanceLocation, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(
        format::HandleId object_id,
        UINT IndexCountPerInstance,
        UINT InstanceCount,
        UINT StartIndexLocation,
        INT BaseVertexLocation,
        UINT StartInstanceLocation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DrawIndexedInstanced";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "IndexCountPerInstance", to_string_flags, tab_count, tab_size, ToString(IndexCountPerInstance, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "InstanceCount", to_string_flags, tab_count, tab_size, ToString(InstanceCount, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "StartIndexLocation", to_string_flags, tab_count, tab_size, ToString(StartIndexLocation, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BaseVertexLocation", to_string_flags, tab_count, tab_size, ToString(BaseVertexLocation, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "StartInstanceLocation", to_string_flags, tab_count, tab_size, ToString(StartInstanceLocation, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Dispatch(
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Dispatch";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ThreadGroupCountX", to_string_flags, tab_count, tab_size, ToString(ThreadGroupCountX, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ThreadGroupCountY", to_string_flags, tab_count, tab_size, ToString(ThreadGroupCountY, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ThreadGroupCountZ", to_string_flags, tab_count, tab_size, ToString(ThreadGroupCountZ, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyBufferRegion(
        format::HandleId object_id,
        format::HandleId pDstBuffer,
        UINT64 DstOffset,
        format::HandleId pSrcBuffer,
        UINT64 SrcOffset,
        UINT64 NumBytes)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyBufferRegion";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pDstBuffer));
            FieldToString(str_strm, false, "DstOffset", to_string_flags, tab_count, tab_size, ToString(DstOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pSrcBuffer));
            FieldToString(str_strm, false, "SrcOffset", to_string_flags, tab_count, tab_size, ToString(SrcOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumBytes", to_string_flags, tab_count, tab_size, ToString(NumBytes, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyTextureRegion(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pDst,
        UINT DstX,
        UINT DstY,
        UINT DstZ,
        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pSrc,
        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyTextureRegion";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDst", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDst, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DstX", to_string_flags, tab_count, tab_size, ToString(DstX, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DstY", to_string_flags, tab_count, tab_size, ToString(DstY, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DstZ", to_string_flags, tab_count, tab_size, ToString(DstZ, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pSrc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcBox", to_string_flags, tab_count, tab_size, PointerDecoderToString(pSrcBox, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyResource(
        format::HandleId object_id,
        format::HandleId pDstResource,
        format::HandleId pSrcResource)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyResource";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstResource", to_string_flags, tab_count, tab_size, HandleIdToString(pDstResource));
            FieldToString(str_strm, false, "pSrcResource", to_string_flags, tab_count, tab_size, HandleIdToString(pSrcResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyTiles(
        format::HandleId object_id,
        format::HandleId pTiledResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pTileRegionStartCoordinate,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pTileRegionSize,
        format::HandleId pBuffer,
        UINT64 BufferStartOffsetInBytes,
        D3D12_TILE_COPY_FLAGS Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyTiles";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pTiledResource", to_string_flags, tab_count, tab_size, HandleIdToString(pTiledResource));
            FieldToString(str_strm, false, "pTileRegionStartCoordinate", to_string_flags, tab_count, tab_size, PointerDecoderToString(pTileRegionStartCoordinate, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pTileRegionSize", to_string_flags, tab_count, tab_size, PointerDecoderToString(pTileRegionSize, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pBuffer));
            FieldToString(str_strm, false, "BufferStartOffsetInBytes", to_string_flags, tab_count, tab_size, ToString(BufferStartOffsetInBytes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResolveSubresource(
        format::HandleId object_id,
        format::HandleId pDstResource,
        UINT DstSubresource,
        format::HandleId pSrcResource,
        UINT SrcSubresource,
        DXGI_FORMAT Format)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResolveSubresource";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstResource", to_string_flags, tab_count, tab_size, HandleIdToString(pDstResource));
            FieldToString(str_strm, false, "DstSubresource", to_string_flags, tab_count, tab_size, ToString(DstSubresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcResource", to_string_flags, tab_count, tab_size, HandleIdToString(pSrcResource));
            FieldToString(str_strm, false, "SrcSubresource", to_string_flags, tab_count, tab_size, ToString(SrcSubresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Format", to_string_flags, tab_count, tab_size, '"' + ToString(Format, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
        format::HandleId object_id,
        D3D_PRIMITIVE_TOPOLOGY PrimitiveTopology)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IASetPrimitiveTopology";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "PrimitiveTopology", to_string_flags, tab_count, tab_size, '"' + ToString(PrimitiveTopology, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_RSSetViewports(
        format::HandleId object_id,
        UINT NumViewports,
        StructPointerDecoder<Decoded_D3D12_VIEWPORT>* pViewports)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RSSetViewports";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumViewports", to_string_flags, tab_count, tab_size, ToString(NumViewports, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pViewports", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumViewports, pViewports, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_RSSetScissorRects(
        format::HandleId object_id,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RSSetScissorRects";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumRects", to_string_flags, tab_count, tab_size, ToString(NumRects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRects", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumRects, pRects, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetBlendFactor(
        format::HandleId object_id,
        PointerDecoder<FLOAT> BlendFactor [4])
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OMSetBlendFactor";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "BlendFactor", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(4, BlendFactor, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetStencilRef(
        format::HandleId object_id,
        UINT StencilRef)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OMSetStencilRef";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "StencilRef", to_string_flags, tab_count, tab_size, ToString(StencilRef, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetPipelineState(
        format::HandleId object_id,
        format::HandleId pPipelineState)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPipelineState";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pPipelineState", to_string_flags, tab_count, tab_size, HandleIdToString(pPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ExecuteBundle(
        format::HandleId object_id,
        format::HandleId pCommandList)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ExecuteBundle";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pCommandList", to_string_flags, tab_count, tab_size, HandleIdToString(pCommandList));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
        format::HandleId object_id,
        UINT NumDescriptorHeaps,
        HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDescriptorHeaps";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumDescriptorHeaps", to_string_flags, tab_count, tab_size, ToString(NumDescriptorHeaps, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppDescriptorHeaps", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumDescriptorHeaps, ppDescriptorHeaps, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
        format::HandleId object_id,
        format::HandleId pRootSignature)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRootSignature";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRootSignature", to_string_flags, tab_count, tab_size, HandleIdToString(pRootSignature));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
        format::HandleId object_id,
        format::HandleId pRootSignature)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRootSignature";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRootSignature", to_string_flags, tab_count, tab_size, HandleIdToString(pRootSignature));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRootDescriptorTable";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BaseDescriptor", to_string_flags, tab_count, tab_size, ToString(*BaseDescriptor.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRootDescriptorTable";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BaseDescriptor", to_string_flags, tab_count, tab_size, ToString(*BaseDescriptor.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRoot32BitConstant";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcData", to_string_flags, tab_count, tab_size, ToString(SrcData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestOffsetIn32BitValues", to_string_flags, tab_count, tab_size, ToString(DestOffsetIn32BitValues, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRoot32BitConstant";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcData", to_string_flags, tab_count, tab_size, ToString(SrcData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestOffsetIn32BitValues", to_string_flags, tab_count, tab_size, ToString(DestOffsetIn32BitValues, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRoot32BitConstants";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Num32BitValuesToSet", to_string_flags, tab_count, tab_size, ToString(Num32BitValuesToSet, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Num32BitValuesToSet * sizeof ( UINT ), pSrcData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestOffsetIn32BitValues", to_string_flags, tab_count, tab_size, ToString(DestOffsetIn32BitValues, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRoot32BitConstants";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Num32BitValuesToSet", to_string_flags, tab_count, tab_size, ToString(Num32BitValuesToSet, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Num32BitValuesToSet * sizeof ( UINT ), pSrcData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestOffsetIn32BitValues", to_string_flags, tab_count, tab_size, ToString(DestOffsetIn32BitValues, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRootConstantBufferView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags, tab_count, tab_size, ToString(BufferLocation, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRootConstantBufferView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags, tab_count, tab_size, ToString(BufferLocation, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRootShaderResourceView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags, tab_count, tab_size, ToString(BufferLocation, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRootShaderResourceView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags, tab_count, tab_size, ToString(BufferLocation, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRootUnorderedAccessView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags, tab_count, tab_size, ToString(BufferLocation, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRootUnorderedAccessView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags, tab_count, tab_size, ToString(BufferLocation, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IASetIndexBuffer";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pView", to_string_flags, tab_count, tab_size, PointerDecoderToString(pView, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetVertexBuffers(
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IASetVertexBuffers";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "StartSlot", to_string_flags, tab_count, tab_size, ToString(StartSlot, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumViews", to_string_flags, tab_count, tab_size, ToString(NumViews, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pViews", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumViews, pViews, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SOSetTargets(
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW>* pViews)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SOSetTargets";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "StartSlot", to_string_flags, tab_count, tab_size, ToString(StartSlot, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumViews", to_string_flags, tab_count, tab_size, ToString(NumViews, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pViews", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumViews, pViews, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
        format::HandleId object_id,
        UINT NumRenderTargetDescriptors,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
        BOOL RTsSingleHandleToDescriptorRange,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OMSetRenderTargets";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumRenderTargetDescriptors", to_string_flags, tab_count, tab_size, ToString(NumRenderTargetDescriptors, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRenderTargetDescriptors", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(RTsSingleHandleToDescriptorRange ? 1 : NumRenderTargetDescriptors, pRenderTargetDescriptors, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "RTsSingleHandleToDescriptorRange", to_string_flags, tab_count, tab_size, ToString(RTsSingleHandleToDescriptorRange, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDepthStencilDescriptor", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDepthStencilDescriptor, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearDepthStencilView(
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
        D3D12_CLEAR_FLAGS ClearFlags,
        FLOAT Depth,
        UINT8 Stencil,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearDepthStencilView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DepthStencilView", to_string_flags, tab_count, tab_size, ToString(*DepthStencilView.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ClearFlags", to_string_flags, tab_count, tab_size, '"' + ToString(ClearFlags, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "Depth", to_string_flags, tab_count, tab_size, ToString(Depth, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Stencil", to_string_flags, tab_count, tab_size, ToString(Stencil, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumRects", to_string_flags, tab_count, tab_size, ToString(NumRects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRects", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumRects, pRects, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearRenderTargetView(
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
        PointerDecoder<FLOAT> ColorRGBA [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearRenderTargetView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RenderTargetView", to_string_flags, tab_count, tab_size, ToString(*RenderTargetView.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ColorRGBA", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(4, ColorRGBA, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumRects", to_string_flags, tab_count, tab_size, ToString(NumRects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRects", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumRects, pRects, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        format::HandleId pResource,
        PointerDecoder<UINT> Values [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearUnorderedAccessViewUint";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ViewGPUHandleInCurrentHeap", to_string_flags, tab_count, tab_size, ToString(*ViewGPUHandleInCurrentHeap.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ViewCPUHandle", to_string_flags, tab_count, tab_size, ToString(*ViewCPUHandle.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Values", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(4, Values, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumRects", to_string_flags, tab_count, tab_size, ToString(NumRects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRects", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumRects, pRects, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        format::HandleId pResource,
        PointerDecoder<FLOAT> Values [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearUnorderedAccessViewFloat";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ViewGPUHandleInCurrentHeap", to_string_flags, tab_count, tab_size, ToString(*ViewGPUHandleInCurrentHeap.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ViewCPUHandle", to_string_flags, tab_count, tab_size, ToString(*ViewCPUHandle.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Values", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(4, Values, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumRects", to_string_flags, tab_count, tab_size, ToString(NumRects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRects", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumRects, pRects, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DiscardResource(
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_DISCARD_REGION>* pRegion)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DiscardResource";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "pRegion", to_string_flags, tab_count, tab_size, PointerDecoderToString(pRegion, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_BeginQuery(
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BeginQuery";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pQueryHeap", to_string_flags, tab_count, tab_size, HandleIdToString(pQueryHeap));
            FieldToString(str_strm, false, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "Index", to_string_flags, tab_count, tab_size, ToString(Index, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_EndQuery(
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EndQuery";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pQueryHeap", to_string_flags, tab_count, tab_size, HandleIdToString(pQueryHeap));
            FieldToString(str_strm, false, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "Index", to_string_flags, tab_count, tab_size, ToString(Index, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResolveQueryData(
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT StartIndex,
        UINT NumQueries,
        format::HandleId pDestinationBuffer,
        UINT64 AlignedDestinationBufferOffset)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResolveQueryData";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pQueryHeap", to_string_flags, tab_count, tab_size, HandleIdToString(pQueryHeap));
            FieldToString(str_strm, false, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "StartIndex", to_string_flags, tab_count, tab_size, ToString(StartIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumQueries", to_string_flags, tab_count, tab_size, ToString(NumQueries, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDestinationBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pDestinationBuffer));
            FieldToString(str_strm, false, "AlignedDestinationBufferOffset", to_string_flags, tab_count, tab_size, ToString(AlignedDestinationBufferOffset, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetPredication(
        format::HandleId object_id,
        format::HandleId pBuffer,
        UINT64 AlignedBufferOffset,
        D3D12_PREDICATION_OP Operation)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPredication";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pBuffer));
            FieldToString(str_strm, false, "AlignedBufferOffset", to_string_flags, tab_count, tab_size, ToString(AlignedBufferOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Operation", to_string_flags, tab_count, tab_size, '"' + ToString(Operation, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetMarker(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMarker";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Metadata", to_string_flags, tab_count, tab_size, ToString(Metadata, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Size, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Size", to_string_flags, tab_count, tab_size, ToString(Size, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_BeginEvent(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BeginEvent";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Metadata", to_string_flags, tab_count, tab_size, ToString(Metadata, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Size, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Size", to_string_flags, tab_count, tab_size, ToString(Size, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_EndEvent(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EndEvent";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ExecuteIndirect(
        format::HandleId object_id,
        format::HandleId pCommandSignature,
        UINT MaxCommandCount,
        format::HandleId pArgumentBuffer,
        UINT64 ArgumentBufferOffset,
        format::HandleId pCountBuffer,
        UINT64 CountBufferOffset)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ExecuteIndirect";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pCommandSignature", to_string_flags, tab_count, tab_size, HandleIdToString(pCommandSignature));
            FieldToString(str_strm, false, "MaxCommandCount", to_string_flags, tab_count, tab_size, ToString(MaxCommandCount, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pArgumentBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pArgumentBuffer));
            FieldToString(str_strm, false, "ArgumentBufferOffset", to_string_flags, tab_count, tab_size, ToString(ArgumentBufferOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pCountBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pCountBuffer));
            FieldToString(str_strm, false, "CountBufferOffset", to_string_flags, tab_count, tab_size, ToString(CountBufferOffset, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
        format::HandleId object_id,
        format::HandleId pDstBuffer,
        UINT64 DstOffset,
        format::HandleId pSrcBuffer,
        UINT64 SrcOffset,
        UINT Dependencies,
        HandlePointerDecoder<ID3D12Resource*>* ppDependentResources,
        StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64>* pDependentSubresourceRanges)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AtomicCopyBufferUINT";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pDstBuffer));
            FieldToString(str_strm, false, "DstOffset", to_string_flags, tab_count, tab_size, ToString(DstOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pSrcBuffer));
            FieldToString(str_strm, false, "SrcOffset", to_string_flags, tab_count, tab_size, ToString(SrcOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Dependencies", to_string_flags, tab_count, tab_size, ToString(Dependencies, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppDependentResources", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Dependencies, ppDependentResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDependentSubresourceRanges", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Dependencies, pDependentSubresourceRanges, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
        format::HandleId object_id,
        format::HandleId pDstBuffer,
        UINT64 DstOffset,
        format::HandleId pSrcBuffer,
        UINT64 SrcOffset,
        UINT Dependencies,
        HandlePointerDecoder<ID3D12Resource*>* ppDependentResources,
        StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64>* pDependentSubresourceRanges)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AtomicCopyBufferUINT64";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pDstBuffer));
            FieldToString(str_strm, false, "DstOffset", to_string_flags, tab_count, tab_size, ToString(DstOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcBuffer", to_string_flags, tab_count, tab_size, HandleIdToString(pSrcBuffer));
            FieldToString(str_strm, false, "SrcOffset", to_string_flags, tab_count, tab_size, ToString(SrcOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Dependencies", to_string_flags, tab_count, tab_size, ToString(Dependencies, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppDependentResources", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Dependencies, ppDependentResources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDependentSubresourceRanges", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Dependencies, pDependentSubresourceRanges, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_OMSetDepthBounds(
        format::HandleId object_id,
        FLOAT Min,
        FLOAT Max)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OMSetDepthBounds";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Min", to_string_flags, tab_count, tab_size, ToString(Min, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Max", to_string_flags, tab_count, tab_size, ToString(Max, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_SetSamplePositions(
        format::HandleId object_id,
        UINT NumSamplesPerPixel,
        UINT NumPixels,
        StructPointerDecoder<Decoded_D3D12_SAMPLE_POSITION>* pSamplePositions)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetSamplePositions";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumSamplesPerPixel", to_string_flags, tab_count, tab_size, ToString(NumSamplesPerPixel, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumPixels", to_string_flags, tab_count, tab_size, ToString(NumPixels, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSamplePositions", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumSamplesPerPixel * NumPixels, pSamplePositions, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(
        format::HandleId object_id,
        format::HandleId pDstResource,
        UINT DstSubresource,
        UINT DstX,
        UINT DstY,
        format::HandleId pSrcResource,
        UINT SrcSubresource,
        StructPointerDecoder<Decoded_tagRECT>* pSrcRect,
        DXGI_FORMAT Format,
        D3D12_RESOLVE_MODE ResolveMode)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResolveSubresourceRegion";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstResource", to_string_flags, tab_count, tab_size, HandleIdToString(pDstResource));
            FieldToString(str_strm, false, "DstSubresource", to_string_flags, tab_count, tab_size, ToString(DstSubresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DstX", to_string_flags, tab_count, tab_size, ToString(DstX, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DstY", to_string_flags, tab_count, tab_size, ToString(DstY, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcResource", to_string_flags, tab_count, tab_size, HandleIdToString(pSrcResource));
            FieldToString(str_strm, false, "SrcSubresource", to_string_flags, tab_count, tab_size, ToString(SrcSubresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcRect", to_string_flags, tab_count, tab_size, PointerDecoderToString(pSrcRect, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Format", to_string_flags, tab_count, tab_size, '"' + ToString(Format, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ResolveMode", to_string_flags, tab_count, tab_size, '"' + ToString(ResolveMode, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_SetViewInstanceMask(
        format::HandleId object_id,
        UINT Mask)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetViewInstanceMask";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Mask", to_string_flags, tab_count, tab_size, ToString(Mask, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList2_WriteBufferImmediate(
        format::HandleId object_id,
        UINT Count,
        StructPointerDecoder<Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>* pParams,
        PointerDecoder<D3D12_WRITEBUFFERIMMEDIATE_MODE>* pModes)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "WriteBufferImmediate";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Count", to_string_flags, tab_count, tab_size, ToString(Count, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pParams", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Count, pParams, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pModes", to_string_flags, tab_count, tab_size, EnumPointerDecoderArrayToString(Count, pModes, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_UpdateTileMappings(
        format::HandleId object_id,
        format::HandleId pResource,
        UINT NumResourceRegions,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pResourceRegionStartCoordinates,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pResourceRegionSizes,
        format::HandleId pHeap,
        UINT NumRanges,
        PointerDecoder<D3D12_TILE_RANGE_FLAGS>* pRangeFlags,
        PointerDecoder<UINT>* pHeapRangeStartOffsets,
        PointerDecoder<UINT>* pRangeTileCounts,
        D3D12_TILE_MAPPING_FLAGS Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UpdateTileMappings";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "NumResourceRegions", to_string_flags, tab_count, tab_size, ToString(NumResourceRegions, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pResourceRegionStartCoordinates", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumResourceRegions, pResourceRegionStartCoordinates, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pResourceRegionSizes", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumResourceRegions, pResourceRegionSizes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pHeap", to_string_flags, tab_count, tab_size, HandleIdToString(pHeap));
            FieldToString(str_strm, false, "NumRanges", to_string_flags, tab_count, tab_size, ToString(NumRanges, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRangeFlags", to_string_flags, tab_count, tab_size, EnumPointerDecoderArrayToString(NumRanges, pRangeFlags, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pHeapRangeStartOffsets", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumRanges, pHeapRangeStartOffsets, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRangeTileCounts", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumRanges, pRangeTileCounts, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_CopyTileMappings(
        format::HandleId object_id,
        format::HandleId pDstResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pDstRegionStartCoordinate,
        format::HandleId pSrcResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pSrcRegionStartCoordinate,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pRegionSize,
        D3D12_TILE_MAPPING_FLAGS Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyTileMappings";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstResource", to_string_flags, tab_count, tab_size, HandleIdToString(pDstResource));
            FieldToString(str_strm, false, "pDstRegionStartCoordinate", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDstRegionStartCoordinate, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcResource", to_string_flags, tab_count, tab_size, HandleIdToString(pSrcResource));
            FieldToString(str_strm, false, "pSrcRegionStartCoordinate", to_string_flags, tab_count, tab_size, PointerDecoderToString(pSrcRegionStartCoordinate, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRegionSize", to_string_flags, tab_count, tab_size, PointerDecoderToString(pRegionSize, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_ExecuteCommandLists(
        format::HandleId object_id,
        UINT NumCommandLists,
        HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ExecuteCommandLists";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumCommandLists", to_string_flags, tab_count, tab_size, ToString(NumCommandLists, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppCommandLists", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumCommandLists, ppCommandLists, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_SetMarker(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMarker";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Metadata", to_string_flags, tab_count, tab_size, ToString(Metadata, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Size, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Size", to_string_flags, tab_count, tab_size, ToString(Size, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_BeginEvent(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BeginEvent";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Metadata", to_string_flags, tab_count, tab_size, ToString(Metadata, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(Size, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Size", to_string_flags, tab_count, tab_size, ToString(Size, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_EndEvent(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EndEvent";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_Signal(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pFence,
        UINT64 Value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Signal";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFence", to_string_flags, tab_count, tab_size, HandleIdToString(pFence));
            FieldToString(str_strm, false, "Value", to_string_flags, tab_count, tab_size, ToString(Value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_Wait(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pFence,
        UINT64 Value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Wait";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFence", to_string_flags, tab_count, tab_size, HandleIdToString(pFence));
            FieldToString(str_strm, false, "Value", to_string_flags, tab_count, tab_size, ToString(Value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetTimestampFrequency(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT64>* pFrequency)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetTimestampFrequency";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pFrequency", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFrequency, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetClockCalibration(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT64>* pGpuTimestamp,
        PointerDecoder<UINT64>* pCpuTimestamp)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetClockCalibration";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pGpuTimestamp", to_string_flags, tab_count, tab_size, PointerDecoderToString(pGpuTimestamp, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pCpuTimestamp", to_string_flags, tab_count, tab_size, PointerDecoderToString(pCpuTimestamp, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetNodeCount(
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNodeCount";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandQueue(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandQueue)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandQueue";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppCommandQueue", to_string_flags, tab_count, tab_size, HandleIdToString(ppCommandQueue));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandAllocator(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_COMMAND_LIST_TYPE type,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandAllocator";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "type", to_string_flags, tab_count, tab_size, '"' + ToString(type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppCommandAllocator", to_string_flags, tab_count, tab_size, HandleIdToString(ppCommandAllocator));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateGraphicsPipelineState(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateGraphicsPipelineState";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags, tab_count, tab_size, HandleIdToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateComputePipelineState(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateComputePipelineState";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags, tab_count, tab_size, HandleIdToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandList(
        format::HandleId object_id,
        HRESULT return_value,
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        format::HandleId pCommandAllocator,
        format::HandleId pInitialState,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandList)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandList";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "nodeMask", to_string_flags, tab_count, tab_size, ToString(nodeMask, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "type", to_string_flags, tab_count, tab_size, '"' + ToString(type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pCommandAllocator", to_string_flags, tab_count, tab_size, HandleIdToString(pCommandAllocator));
            FieldToString(str_strm, false, "pInitialState", to_string_flags, tab_count, tab_size, HandleIdToString(pInitialState));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppCommandList", to_string_flags, tab_count, tab_size, HandleIdToString(ppCommandList));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateDescriptorHeap(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateDescriptorHeap";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDescriptorHeapDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDescriptorHeapDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags, tab_count, tab_size, HandleIdToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetDescriptorHandleIncrementSize(
        format::HandleId object_id,
        UINT return_value,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDescriptorHandleIncrementSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DescriptorHeapType", to_string_flags, tab_count, tab_size, '"' + ToString(DescriptorHeapType, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateConstantBufferView(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateConstantBufferView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateShaderResourceView(
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateShaderResourceView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateUnorderedAccessView(
        format::HandleId object_id,
        format::HandleId pResource,
        format::HandleId pCounterResource,
        StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateUnorderedAccessView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "pCounterResource", to_string_flags, tab_count, tab_size, HandleIdToString(pCounterResource));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateRenderTargetView(
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateRenderTargetView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateDepthStencilView(
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateDepthStencilView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateSampler(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSampler";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CopyDescriptors(
        format::HandleId object_id,
        UINT NumDestDescriptorRanges,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDestDescriptorRangeStarts,
        PointerDecoder<UINT>* pDestDescriptorRangeSizes,
        UINT NumSrcDescriptorRanges,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pSrcDescriptorRangeStarts,
        PointerDecoder<UINT>* pSrcDescriptorRangeSizes,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyDescriptors";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumDestDescriptorRanges", to_string_flags, tab_count, tab_size, ToString(NumDestDescriptorRanges, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDestDescriptorRangeStarts", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumDestDescriptorRanges, pDestDescriptorRangeStarts, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDestDescriptorRangeSizes", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumDestDescriptorRanges, pDestDescriptorRangeSizes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumSrcDescriptorRanges", to_string_flags, tab_count, tab_size, ToString(NumSrcDescriptorRanges, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcDescriptorRangeStarts", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumSrcDescriptorRanges, pSrcDescriptorRangeStarts, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcDescriptorRangeSizes", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumSrcDescriptorRanges, pSrcDescriptorRangeSizes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DescriptorHeapsType", to_string_flags, tab_count, tab_size, '"' + ToString(DescriptorHeapsType, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CopyDescriptorsSimple(
        format::HandleId object_id,
        UINT NumDescriptors,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyDescriptorsSimple";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumDescriptors", to_string_flags, tab_count, tab_size, ToString(NumDescriptors, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptorRangeStart", to_string_flags, tab_count, tab_size, ToString(*DestDescriptorRangeStart.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcDescriptorRangeStart", to_string_flags, tab_count, tab_size, ToString(*SrcDescriptorRangeStart.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DescriptorHeapsType", to_string_flags, tab_count, tab_size, '"' + ToString(DescriptorHeapsType, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommittedResource(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommittedResource";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeapProperties", to_string_flags, tab_count, tab_size, PointerDecoderToString(pHeapProperties, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "HeapFlags", to_string_flags, tab_count, tab_size, '"' + ToString(HeapFlags, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialResourceState", to_string_flags, tab_count, tab_size, '"' + ToString(InitialResourceState, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOptimizedClearValue, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riidResource", to_string_flags, tab_count, tab_size, ToString(*riidResource.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags, tab_count, tab_size, HandleIdToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateHeap(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateHeap";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags, tab_count, tab_size, HandleIdToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreatePlacedResource(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pHeap,
        UINT64 HeapOffset,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreatePlacedResource";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeap", to_string_flags, tab_count, tab_size, HandleIdToString(pHeap));
            FieldToString(str_strm, false, "HeapOffset", to_string_flags, tab_count, tab_size, ToString(HeapOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialState", to_string_flags, tab_count, tab_size, '"' + ToString(InitialState, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOptimizedClearValue, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags, tab_count, tab_size, HandleIdToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateReservedResource(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateReservedResource";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialState", to_string_flags, tab_count, tab_size, '"' + ToString(InitialState, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOptimizedClearValue, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags, tab_count, tab_size, HandleIdToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateSharedHandle(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pObject,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD Access,
        WStringDecoder* Name,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSharedHandle";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pObject", to_string_flags, tab_count, tab_size, HandleIdToString(pObject));
            FieldToString(str_strm, false, "pAttributes", to_string_flags, tab_count, tab_size, PointerDecoderToString(pAttributes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Access", to_string_flags, tab_count, tab_size, ToString(Access, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Name", to_string_flags, tab_count, tab_size, PointerDecoderToString(Name, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pHandle", to_string_flags, tab_count, tab_size, HandleIdToString(pHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_OpenSharedHandle(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t NTHandle,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObj)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OpenSharedHandle";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NTHandle", to_string_flags, tab_count, tab_size, HandleIdToString(NTHandle));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvObj", to_string_flags, tab_count, tab_size, HandleIdToString(ppvObj));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_OpenSharedHandleByName(
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* Name,
        DWORD Access,
        PointerDecoder<uint64_t, void*>* pNTHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OpenSharedHandleByName";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Name", to_string_flags, tab_count, tab_size, PointerDecoderToString(Name, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Access", to_string_flags, tab_count, tab_size, ToString(Access, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pNTHandle", to_string_flags, tab_count, tab_size, HandleIdToString(pNTHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_MakeResident(
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "MakeResident";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumObjects", to_string_flags, tab_count, tab_size, ToString(NumObjects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppObjects", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumObjects, ppObjects, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_Evict(
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Evict";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumObjects", to_string_flags, tab_count, tab_size, ToString(NumObjects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppObjects", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumObjects, ppObjects, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateFence(
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 InitialValue,
        D3D12_FENCE_FLAGS Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateFence";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "InitialValue", to_string_flags, tab_count, tab_size, ToString(InitialValue, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppFence", to_string_flags, tab_count, tab_size, HandleIdToString(ppFence));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetDeviceRemovedReason(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDeviceRemovedReason";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetCopyableFootprints(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDesc,
        UINT FirstSubresource,
        UINT NumSubresources,
        UINT64 BaseOffset,
        StructPointerDecoder<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT>* pLayouts,
        PointerDecoder<UINT>* pNumRows,
        PointerDecoder<UINT64>* pRowSizeInBytes,
        PointerDecoder<UINT64>* pTotalBytes)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCopyableFootprints";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResourceDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pResourceDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "FirstSubresource", to_string_flags, tab_count, tab_size, ToString(FirstSubresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumSubresources", to_string_flags, tab_count, tab_size, ToString(NumSubresources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BaseOffset", to_string_flags, tab_count, tab_size, ToString(BaseOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pLayouts", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumSubresources, pLayouts, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pNumRows", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumSubresources, pNumRows, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pRowSizeInBytes", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumSubresources, pRowSizeInBytes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pTotalBytes", to_string_flags, tab_count, tab_size, PointerDecoderToString(pTotalBytes, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateQueryHeap(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_QUERY_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateQueryHeap";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags, tab_count, tab_size, HandleIdToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_SetStablePowerState(
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetStablePowerState";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags, tab_count, tab_size, ToString(Enable, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandSignature(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC>* pDesc,
        format::HandleId pRootSignature,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvCommandSignature)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandSignature";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRootSignature", to_string_flags, tab_count, tab_size, HandleIdToString(pRootSignature));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvCommandSignature", to_string_flags, tab_count, tab_size, HandleIdToString(ppvCommandSignature));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetResourceTiling(
        format::HandleId object_id,
        format::HandleId pTiledResource,
        PointerDecoder<UINT>* pNumTilesForEntireResource,
        StructPointerDecoder<Decoded_D3D12_PACKED_MIP_INFO>* pPackedMipDesc,
        StructPointerDecoder<Decoded_D3D12_TILE_SHAPE>* pStandardTileShapeForNonPackedMips,
        PointerDecoder<UINT>* pNumSubresourceTilings,
        UINT FirstSubresourceTilingToGet,
        StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_TILING>* pSubresourceTilingsForNonPackedMips)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetResourceTiling";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pTiledResource", to_string_flags, tab_count, tab_size, HandleIdToString(pTiledResource));
            FieldToString(str_strm, false, "[out]pNumTilesForEntireResource", to_string_flags, tab_count, tab_size, PointerDecoderToString(pNumTilesForEntireResource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pPackedMipDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pPackedMipDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pStandardTileShapeForNonPackedMips", to_string_flags, tab_count, tab_size, PointerDecoderToString(pStandardTileShapeForNonPackedMips, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pNumSubresourceTilings", to_string_flags, tab_count, tab_size, PointerDecoderToString(pNumSubresourceTilings, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "FirstSubresourceTilingToGet", to_string_flags, tab_count, tab_size, ToString(FirstSubresourceTilingToGet, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pSubresourceTilingsForNonPackedMips", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(pNumSubresourceTilings, pSubresourceTilingsForNonPackedMips, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_StorePipeline(
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        format::HandleId pPipeline)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "StorePipeline";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pName", to_string_flags, tab_count, tab_size, PointerDecoderToString(pName, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pPipeline", to_string_flags, tab_count, tab_size, HandleIdToString(pPipeline));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_LoadGraphicsPipeline(
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "LoadGraphicsPipeline";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pName", to_string_flags, tab_count, tab_size, PointerDecoderToString(pName, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags, tab_count, tab_size, HandleIdToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_LoadComputePipeline(
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "LoadComputePipeline";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pName", to_string_flags, tab_count, tab_size, PointerDecoderToString(pName, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags, tab_count, tab_size, HandleIdToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_GetSerializedSize(
        format::HandleId object_id,
        SIZE_T return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSerializedSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_Serialize(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pData,
        SIZE_T DataSizeInBytes)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Serialize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSizeInBytes, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSizeInBytes", to_string_flags, tab_count, tab_size, ToString(DataSizeInBytes, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary1_LoadPipeline(
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "LoadPipeline";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pName", to_string_flags, tab_count, tab_size, PointerDecoderToString(pName, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags, tab_count, tab_size, HandleIdToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device1_CreatePipelineLibrary(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pLibraryBlob,
        SIZE_T BlobLength,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineLibrary)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreatePipelineLibrary";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pLibraryBlob", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(BlobLength, pLibraryBlob, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BlobLength", to_string_flags, tab_count, tab_size, ToString(BlobLength, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineLibrary", to_string_flags, tab_count, tab_size, HandleIdToString(ppPipelineLibrary));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device1_SetEventOnMultipleFenceCompletion(
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<ID3D12Fence*>* ppFences,
        PointerDecoder<UINT64>* pFenceValues,
        UINT NumFences,
        D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
        uint64_t hEvent)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEventOnMultipleFenceCompletion";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ppFences", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumFences, ppFences, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pFenceValues", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumFences, pFenceValues, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumFences", to_string_flags, tab_count, tab_size, ToString(NumFences, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "hEvent", to_string_flags, tab_count, tab_size, HandleIdToString(hEvent));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device1_SetResidencyPriority(
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        PointerDecoder<D3D12_RESIDENCY_PRIORITY>* pPriorities)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetResidencyPriority";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumObjects", to_string_flags, tab_count, tab_size, ToString(NumObjects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppObjects", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumObjects, ppObjects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pPriorities", to_string_flags, tab_count, tab_size, EnumPointerDecoderArrayToString(NumObjects, pPriorities, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device2_CreatePipelineState(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreatePipelineState";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags, tab_count, tab_size, HandleIdToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device3_OpenExistingHeapFromAddress(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t pAddress,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OpenExistingHeapFromAddress";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pAddress", to_string_flags, tab_count, tab_size, HandleIdToString(pAddress));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags, tab_count, tab_size, HandleIdToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device3_OpenExistingHeapFromFileMapping(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hFileMapping,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OpenExistingHeapFromFileMapping";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hFileMapping", to_string_flags, tab_count, tab_size, HandleIdToString(hFileMapping));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags, tab_count, tab_size, HandleIdToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device3_EnqueueMakeResident(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RESIDENCY_FLAGS Flags,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        format::HandleId pFenceToSignal,
        UINT64 FenceValueToSignal)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnqueueMakeResident";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "NumObjects", to_string_flags, tab_count, tab_size, ToString(NumObjects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ppObjects", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumObjects, ppObjects, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pFenceToSignal", to_string_flags, tab_count, tab_size, HandleIdToString(pFenceToSignal));
            FieldToString(str_strm, false, "FenceValueToSignal", to_string_flags, tab_count, tab_size, ToString(FenceValueToSignal, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ProtectedSession_GetStatusFence(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ProtectedSession";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetStatusFence";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppFence", to_string_flags, tab_count, tab_size, HandleIdToString(ppFence));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ProtectedSession_GetSessionStatus(
        format::HandleId object_id,
        D3D12_PROTECTED_SESSION_STATUS return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ProtectedSession";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSessionStatus";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_CreateCommandList1(
        format::HandleId object_id,
        HRESULT return_value,
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        D3D12_COMMAND_LIST_FLAGS flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandList)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandList1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "nodeMask", to_string_flags, tab_count, tab_size, ToString(nodeMask, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "type", to_string_flags, tab_count, tab_size, '"' + ToString(type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "flags", to_string_flags, tab_count, tab_size, '"' + ToString(flags, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppCommandList", to_string_flags, tab_count, tab_size, HandleIdToString(ppCommandList));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_CreateProtectedResourceSession(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateProtectedResourceSession";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSession", to_string_flags, tab_count, tab_size, HandleIdToString(ppSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_CreateCommittedResource1(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        format::HandleId pProtectedSession,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommittedResource1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeapProperties", to_string_flags, tab_count, tab_size, PointerDecoderToString(pHeapProperties, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "HeapFlags", to_string_flags, tab_count, tab_size, '"' + ToString(HeapFlags, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialResourceState", to_string_flags, tab_count, tab_size, '"' + ToString(InitialResourceState, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOptimizedClearValue, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pProtectedSession", to_string_flags, tab_count, tab_size, HandleIdToString(pProtectedSession));
            FieldToString(str_strm, false, "riidResource", to_string_flags, tab_count, tab_size, ToString(*riidResource.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags, tab_count, tab_size, HandleIdToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_CreateHeap1(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        format::HandleId pProtectedSession,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateHeap1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pProtectedSession", to_string_flags, tab_count, tab_size, HandleIdToString(pProtectedSession));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags, tab_count, tab_size, HandleIdToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_CreateReservedResource1(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        format::HandleId pProtectedSession,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateReservedResource1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialState", to_string_flags, tab_count, tab_size, '"' + ToString(InitialState, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOptimizedClearValue, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pProtectedSession", to_string_flags, tab_count, tab_size, HandleIdToString(pProtectedSession));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags, tab_count, tab_size, HandleIdToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12LifetimeOwner_LifetimeStateUpdated(
        format::HandleId object_id,
        D3D12_LIFETIME_STATE NewState)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12LifetimeOwner";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "LifetimeStateUpdated";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NewState", to_string_flags, tab_count, tab_size, '"' + ToString(NewState, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetLUID(
        format::HandleId object_id,
        Decoded_LUID return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SwapChainAssistant";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetLUID";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetSwapChainObject(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppv)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SwapChainAssistant";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSwapChainObject";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppv", to_string_flags, tab_count, tab_size, HandleIdToString(ppv));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource,
        Decoded_GUID riidQueue,
        HandlePointerDecoder<void*>* ppvQueue)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SwapChainAssistant";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCurrentResourceAndCommandQueue";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riidResource", to_string_flags, tab_count, tab_size, ToString(*riidResource.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags, tab_count, tab_size, HandleIdToString(ppvResource));
            FieldToString(str_strm, false, "riidQueue", to_string_flags, tab_count, tab_size, ToString(*riidQueue.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvQueue", to_string_flags, tab_count, tab_size, HandleIdToString(ppvQueue));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_InsertImplicitSync(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SwapChainAssistant";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "InsertImplicitSync";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12LifetimeTracker_DestroyOwnedObject(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pObject)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12LifetimeTracker";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DestroyOwnedObject";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pObject", to_string_flags, tab_count, tab_size, HandleIdToString(pObject));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetShaderIdentifier(
        format::HandleId object_id,
        PointerDecoder<uint8_t>* return_value,
        WStringDecoder* pExportName)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12StateObjectProperties";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetShaderIdentifier";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pExportName", to_string_flags, tab_count, tab_size, PointerDecoderToString(pExportName, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetShaderStackSize(
        format::HandleId object_id,
        UINT64 return_value,
        WStringDecoder* pExportName)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12StateObjectProperties";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetShaderStackSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pExportName", to_string_flags, tab_count, tab_size, PointerDecoderToString(pExportName, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetPipelineStackSize(
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12StateObjectProperties";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPipelineStackSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_SetPipelineStackSize(
        format::HandleId object_id,
        UINT64 PipelineStackSizeInBytes)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12StateObjectProperties";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPipelineStackSize";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "PipelineStackSizeInBytes", to_string_flags, tab_count, tab_size, ToString(PipelineStackSizeInBytes, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_CreateLifetimeTracker(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pOwner,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvTracker)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateLifetimeTracker";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pOwner", to_string_flags, tab_count, tab_size, HandleIdToString(pOwner));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvTracker", to_string_flags, tab_count, tab_size, HandleIdToString(ppvTracker));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_RemoveDevice(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RemoveDevice";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_EnumerateMetaCommands(
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pNumMetaCommands,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_DESC>* pDescs)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumerateMetaCommands";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pNumMetaCommands", to_string_flags, tab_count, tab_size, PointerDecoderToString(pNumMetaCommands, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDescs", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(pNumMetaCommands, pDescs, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_EnumerateMetaCommandParameters(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID CommandId,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        PointerDecoder<UINT>* pTotalStructureSizeInBytes,
        PointerDecoder<UINT>* pParameterCount,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_PARAMETER_DESC>* pParameterDescs)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumerateMetaCommandParameters";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "CommandId", to_string_flags, tab_count, tab_size, ToString(*CommandId.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Stage", to_string_flags, tab_count, tab_size, '"' + ToString(Stage, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "[out]pTotalStructureSizeInBytes", to_string_flags, tab_count, tab_size, PointerDecoderToString(pTotalStructureSizeInBytes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pParameterCount", to_string_flags, tab_count, tab_size, PointerDecoderToString(pParameterCount, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pParameterDescs", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(pParameterCount, pParameterDescs, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_CreateMetaCommand(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID CommandId,
        UINT NodeMask,
        PointerDecoder<uint8_t>* pCreationParametersData,
        SIZE_T CreationParametersDataSizeInBytes,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppMetaCommand)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateMetaCommand";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "CommandId", to_string_flags, tab_count, tab_size, ToString(*CommandId.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NodeMask", to_string_flags, tab_count, tab_size, ToString(NodeMask, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pCreationParametersData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(CreationParametersDataSizeInBytes, pCreationParametersData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "CreationParametersDataSizeInBytes", to_string_flags, tab_count, tab_size, ToString(CreationParametersDataSizeInBytes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppMetaCommand", to_string_flags, tab_count, tab_size, HandleIdToString(ppMetaCommand));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_CreateStateObject(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppStateObject)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateStateObject";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppStateObject", to_string_flags, tab_count, tab_size, HandleIdToString(ppStateObject));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>* pDesc,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRaytracingAccelerationStructurePrebuildInfo";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pInfo", to_string_flags, tab_count, tab_size, PointerDecoderToString(pInfo, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_CheckDriverMatchingIdentifier(
        format::HandleId object_id,
        D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS return_value,
        D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
        StructPointerDecoder<Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>* pIdentifierToCheck)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckDriverMatchingIdentifier";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "SerializedDataType", to_string_flags, tab_count, tab_size, '"' + ToString(SerializedDataType, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pIdentifierToCheck", to_string_flags, tab_count, tab_size, PointerDecoderToString(pIdentifierToCheck, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedDataSettings";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetAutoBreadcrumbsEnablement";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enablement", to_string_flags, tab_count, tab_size, '"' + ToString(Enablement, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedDataSettings";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPageFaultEnablement";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enablement", to_string_flags, tab_count, tab_size, '"' + ToString(Enablement, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedDataSettings";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetWatsonDumpEnablement";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enablement", to_string_flags, tab_count, tab_size, '"' + ToString(Enablement, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedDataSettings1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBreadcrumbContextEnablement";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enablement", to_string_flags, tab_count, tab_size, '"' + ToString(Enablement, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* pOutput)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedData";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetAutoBreadcrumbsOutput";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pOutput", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOutput, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>* pOutput)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedData";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPageFaultAllocationOutput";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pOutput", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOutput, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* pOutput)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedData1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetAutoBreadcrumbsOutput1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pOutput", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOutput, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* pOutput)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedData1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPageFaultAllocationOutput1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pOutput", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOutput, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device6_SetBackgroundProcessingMode(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_BACKGROUND_PROCESSING_MODE Mode,
        D3D12_MEASUREMENTS_ACTION MeasurementsAction,
        uint64_t hEventToSignalUponCompletion,
        PointerDecoder<BOOL>* pbFurtherMeasurementsDesired)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBackgroundProcessingMode";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Mode", to_string_flags, tab_count, tab_size, '"' + ToString(Mode, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "MeasurementsAction", to_string_flags, tab_count, tab_size, '"' + ToString(MeasurementsAction, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "hEventToSignalUponCompletion", to_string_flags, tab_count, tab_size, HandleIdToString(hEventToSignalUponCompletion));
            FieldToString(str_strm, false, "[out]pbFurtherMeasurementsDesired", to_string_flags, tab_count, tab_size, PointerDecoderToString(pbFurtherMeasurementsDesired, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ProtectedResourceSession1_GetDesc1(
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ProtectedResourceSession1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device7_AddToStateObject(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pAddition,
        format::HandleId pStateObjectToGrowFrom,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppNewStateObject)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device7";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddToStateObject";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pAddition", to_string_flags, tab_count, tab_size, PointerDecoderToString(pAddition, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pStateObjectToGrowFrom", to_string_flags, tab_count, tab_size, HandleIdToString(pStateObjectToGrowFrom));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppNewStateObject", to_string_flags, tab_count, tab_size, HandleIdToString(ppNewStateObject));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device7_CreateProtectedResourceSession1(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device7";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateProtectedResourceSession1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSession", to_string_flags, tab_count, tab_size, HandleIdToString(ppSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device8_GetResourceAllocationInfo2(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetResourceAllocationInfo2";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "visibleMask", to_string_flags, tab_count, tab_size, ToString(visibleMask, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "numResourceDescs", to_string_flags, tab_count, tab_size, ToString(numResourceDescs, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pResourceDescs", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(numResourceDescs, pResourceDescs, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pResourceAllocationInfo1", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(numResourceDescs, pResourceAllocationInfo1, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device8_CreateCommittedResource2(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        format::HandleId pProtectedSession,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommittedResource2";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeapProperties", to_string_flags, tab_count, tab_size, PointerDecoderToString(pHeapProperties, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "HeapFlags", to_string_flags, tab_count, tab_size, '"' + ToString(HeapFlags, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialResourceState", to_string_flags, tab_count, tab_size, '"' + ToString(InitialResourceState, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOptimizedClearValue, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pProtectedSession", to_string_flags, tab_count, tab_size, HandleIdToString(pProtectedSession));
            FieldToString(str_strm, false, "riidResource", to_string_flags, tab_count, tab_size, ToString(*riidResource.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags, tab_count, tab_size, HandleIdToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device8_CreatePlacedResource1(
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pHeap,
        UINT64 HeapOffset,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreatePlacedResource1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeap", to_string_flags, tab_count, tab_size, HandleIdToString(pHeap));
            FieldToString(str_strm, false, "HeapOffset", to_string_flags, tab_count, tab_size, ToString(HeapOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialState", to_string_flags, tab_count, tab_size, '"' + ToString(InitialState, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags, tab_count, tab_size, PointerDecoderToString(pOptimizedClearValue, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags, tab_count, tab_size, HandleIdToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
        format::HandleId object_id,
        format::HandleId pTargetedResource,
        format::HandleId pFeedbackResource,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSamplerFeedbackUnorderedAccessView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pTargetedResource", to_string_flags, tab_count, tab_size, HandleIdToString(pTargetedResource));
            FieldToString(str_strm, false, "pFeedbackResource", to_string_flags, tab_count, tab_size, HandleIdToString(pFeedbackResource));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device8_GetCopyableFootprints1(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDesc,
        UINT FirstSubresource,
        UINT NumSubresources,
        UINT64 BaseOffset,
        StructPointerDecoder<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT>* pLayouts,
        PointerDecoder<UINT>* pNumRows,
        PointerDecoder<UINT64>* pRowSizeInBytes,
        PointerDecoder<UINT64>* pTotalBytes)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCopyableFootprints1";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResourceDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pResourceDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "FirstSubresource", to_string_flags, tab_count, tab_size, ToString(FirstSubresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumSubresources", to_string_flags, tab_count, tab_size, ToString(NumSubresources, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "BaseOffset", to_string_flags, tab_count, tab_size, ToString(BaseOffset, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pLayouts", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumSubresources, pLayouts, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pNumRows", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumSubresources, pNumRows, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pRowSizeInBytes", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumSubresources, pRowSizeInBytes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pTotalBytes", to_string_flags, tab_count, tab_size, PointerDecoderToString(pTotalBytes, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource1_GetProtectedResourceSession(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetProtectedResourceSession";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppProtectedSession", to_string_flags, tab_count, tab_size, HandleIdToString(ppProtectedSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource2_GetDesc1(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC1 return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Heap1_GetProtectedResourceSession(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Heap1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetProtectedResourceSession";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppProtectedSession", to_string_flags, tab_count, tab_size, HandleIdToString(ppProtectedSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
        format::HandleId object_id,
        format::HandleId pProtectedResourceSession)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetProtectedResourceSession";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pProtectedResourceSession", to_string_flags, tab_count, tab_size, HandleIdToString(pProtectedResourceSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12MetaCommand_GetRequiredParameterResourceSize(
        format::HandleId object_id,
        UINT64 return_value,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        UINT ParameterIndex)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12MetaCommand";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRequiredParameterResourceSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Stage", to_string_flags, tab_count, tab_size, '"' + ToString(Stage, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ParameterIndex", to_string_flags, tab_count, tab_size, ToString(ParameterIndex, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_BeginRenderPass(
        format::HandleId object_id,
        UINT NumRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BeginRenderPass";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumRenderTargets", to_string_flags, tab_count, tab_size, ToString(NumRenderTargets, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRenderTargets", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumRenderTargets, pRenderTargets, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pDepthStencil", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDepthStencil, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_EndRenderPass(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EndRenderPass";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(
        format::HandleId object_id,
        format::HandleId pMetaCommand,
        PointerDecoder<uint8_t>* pInitializationParametersData,
        SIZE_T InitializationParametersDataSizeInBytes)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "InitializeMetaCommand";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pMetaCommand", to_string_flags, tab_count, tab_size, HandleIdToString(pMetaCommand));
            FieldToString(str_strm, false, "pInitializationParametersData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(InitializationParametersDataSizeInBytes, pInitializationParametersData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "InitializationParametersDataSizeInBytes", to_string_flags, tab_count, tab_size, ToString(InitializationParametersDataSizeInBytes, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
        format::HandleId object_id,
        format::HandleId pMetaCommand,
        PointerDecoder<uint8_t>* pExecutionParametersData,
        SIZE_T ExecutionParametersDataSizeInBytes)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ExecuteMetaCommand";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pMetaCommand", to_string_flags, tab_count, tab_size, HandleIdToString(pMetaCommand));
            FieldToString(str_strm, false, "pExecutionParametersData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(ExecutionParametersDataSizeInBytes, pExecutionParametersData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ExecutionParametersDataSizeInBytes", to_string_flags, tab_count, tab_size, ToString(ExecutionParametersDataSizeInBytes, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* pDesc,
        UINT NumPostbuildInfoDescs,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pPostbuildInfoDescs)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BuildRaytracingAccelerationStructure";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumPostbuildInfoDescs", to_string_flags, tab_count, tab_size, ToString(NumPostbuildInfoDescs, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pPostbuildInfoDescs", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumPostbuildInfoDescs, pPostbuildInfoDescs, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pDesc,
        UINT NumSourceAccelerationStructures,
        PointerDecoder<D3D12_GPU_VIRTUAL_ADDRESS>* pSourceAccelerationStructureData)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EmitRaytracingAccelerationStructurePostbuildInfo";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "NumSourceAccelerationStructures", to_string_flags, tab_count, tab_size, ToString(NumSourceAccelerationStructures, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pSourceAccelerationStructureData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumSourceAccelerationStructures, pSourceAccelerationStructureData, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
        D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyRaytracingAccelerationStructure";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DestAccelerationStructureData", to_string_flags, tab_count, tab_size, ToString(DestAccelerationStructureData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "SourceAccelerationStructureData", to_string_flags, tab_count, tab_size, ToString(SourceAccelerationStructureData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "Mode", to_string_flags, tab_count, tab_size, '"' + ToString(Mode, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_SetPipelineState1(
        format::HandleId object_id,
        format::HandleId pStateObject)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPipelineState1";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pStateObject", to_string_flags, tab_count, tab_size, HandleIdToString(pStateObject));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_DispatchRays(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DispatchRays";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDesc, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Tools_EnableShaderInstrumentation(
        format::HandleId object_id,
        BOOL bEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Tools";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnableShaderInstrumentation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "bEnable", to_string_flags, tab_count, tab_size, ToString(bEnable, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Tools_ShaderInstrumentationEnabled(
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Tools";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ShaderInstrumentationEnabled";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRate(
        format::HandleId object_id,
        D3D12_SHADING_RATE baseShadingRate,
        PointerDecoder<D3D12_SHADING_RATE_COMBINER>* combiners)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RSSetShadingRate";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "baseShadingRate", to_string_flags, tab_count, tab_size, '"' + ToString(baseShadingRate, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "combiners", to_string_flags, tab_count, tab_size, EnumPointerDecoderArrayToString(D3D12_RS_SET_SHADING_RATE_COMBINER_COUNT, combiners, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
        format::HandleId object_id,
        format::HandleId shadingRateImage)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RSSetShadingRateImage";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "shadingRateImage", to_string_flags, tab_count, tab_size, HandleIdToString(shadingRateImage));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList6_DispatchMesh(
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DispatchMesh";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ThreadGroupCountX", to_string_flags, tab_count, tab_size, ToString(ThreadGroupCountX, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ThreadGroupCountY", to_string_flags, tab_count, tab_size, ToString(ThreadGroupCountY, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "ThreadGroupCountZ", to_string_flags, tab_count, tab_size, ToString(ThreadGroupCountZ, to_string_flags, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_ID3D10Blob_GetBufferPointer(
        format::HandleId object_id,
        uint64_t return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D10Blob";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBufferPointer";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D10Blob_GetBufferSize(
        format::HandleId object_id,
        SIZE_T return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D10Blob";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBufferSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3DDestructionNotifier_RegisterDestructionCallback(
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t callbackFn,
        uint64_t pData,
        PointerDecoder<UINT>* pCallbackID)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3DDestructionNotifier";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterDestructionCallback";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "callbackFn", to_string_flags, tab_count, tab_size, ToString(callbackFn, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, HandleIdToString(pData));
            FieldToString(str_strm, false, "[out]pCallbackID", to_string_flags, tab_count, tab_size, PointerDecoderToString(pCallbackID, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3DDestructionNotifier_UnregisterDestructionCallback(
        format::HandleId object_id,
        HRESULT return_value,
        UINT callbackID)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3DDestructionNotifier";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterDestructionCallback";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "callbackID", to_string_flags, tab_count, tab_size, ToString(callbackID, to_string_flags, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from d3d12sdklayers.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_ID3D12Debug_EnableDebugLayer(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnableDebugLayer";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug1_EnableDebugLayer(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnableDebugLayer";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug1_SetEnableGPUBasedValidation(
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEnableGPUBasedValidation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags, tab_count, tab_size, ToString(Enable, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEnableSynchronizedCommandQueueValidation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags, tab_count, tab_size, ToString(Enable, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug2_SetGPUBasedValidationFlags(
        format::HandleId object_id,
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGPUBasedValidationFlags";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug3_SetEnableGPUBasedValidation(
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEnableGPUBasedValidation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags, tab_count, tab_size, ToString(Enable, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEnableSynchronizedCommandQueueValidation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags, tab_count, tab_size, ToString(Enable, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug3_SetGPUBasedValidationFlags(
        format::HandleId object_id,
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGPUBasedValidationFlags";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_SetDebugParameter(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDebugParameter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags, tab_count, tab_size, ToString(DataSize, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_GetDebugParameter(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDebugParameter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "[out]pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags, tab_count, tab_size, ToString(DataSize, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_ReportLiveDeviceObjects(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RLDO_FLAGS Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReportLiveDeviceObjects";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice_SetFeatureMask(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_FEATURE Mask)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetFeatureMask";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Mask", to_string_flags, tab_count, tab_size, '"' + ToString(Mask, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice_GetFeatureMask(
        format::HandleId object_id,
        D3D12_DEBUG_FEATURE return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFeatureMask";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice_ReportLiveDeviceObjects(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RLDO_FLAGS Flags)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReportLiveDeviceObjects";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags, tab_count, tab_size, '"' + ToString(Flags, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice2_SetDebugParameter(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDebugParameter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags, tab_count, tab_size, ToString(DataSize, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice2_GetDebugParameter(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDebugParameter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "[out]pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags, tab_count, tab_size, ToString(DataSize, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandQueue_AssertResourceState(
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AssertResourceState";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags, tab_count, tab_size, ToString(Subresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "State", to_string_flags, tab_count, tab_size, ToString(State, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_AssertResourceState(
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AssertResourceState";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags, tab_count, tab_size, ToString(Subresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "State", to_string_flags, tab_count, tab_size, ToString(State, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_SetDebugParameter(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDebugParameter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags, tab_count, tab_size, ToString(DataSize, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_GetDebugParameter(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDebugParameter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "[out]pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags, tab_count, tab_size, ToString(DataSize, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_AssertResourceState(
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AssertResourceState";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags, tab_count, tab_size, ToString(Subresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "State", to_string_flags, tab_count, tab_size, ToString(State, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_SetFeatureMask(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_FEATURE Mask)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetFeatureMask";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Mask", to_string_flags, tab_count, tab_size, '"' + ToString(Mask, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_GetFeatureMask(
        format::HandleId object_id,
        D3D12_DEBUG_FEATURE return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFeatureMask";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList2_SetDebugParameter(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDebugParameter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags, tab_count, tab_size, ToString(DataSize, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList2_GetDebugParameter(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDebugParameter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags, tab_count, tab_size, '"' + ToString(Type, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "[out]pData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags, tab_count, tab_size, ToString(DataSize, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SharingContract_Present(
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        uint64_t window)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SharingContract";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Present";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags, tab_count, tab_size, ToString(Subresource, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "window", to_string_flags, tab_count, tab_size, HandleIdToString(window));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SharingContract_SharedFenceSignal(
        format::HandleId object_id,
        format::HandleId pFence,
        UINT64 FenceValue)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SharingContract";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SharedFenceSignal";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFence", to_string_flags, tab_count, tab_size, HandleIdToString(pFence));
            FieldToString(str_strm, false, "FenceValue", to_string_flags, tab_count, tab_size, ToString(FenceValue, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SharingContract_BeginCapturableWork(
        format::HandleId object_id,
        Decoded_GUID guid)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SharingContract";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BeginCapturableWork";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "guid", to_string_flags, tab_count, tab_size, ToString(*guid.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SharingContract_EndCapturableWork(
        format::HandleId object_id,
        Decoded_GUID guid)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SharingContract";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EndCapturableWork";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "guid", to_string_flags, tab_count, tab_size, ToString(*guid.decoded_value, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetMessageCountLimit(
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 MessageCountLimit)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMessageCountLimit";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "MessageCountLimit", to_string_flags, tab_count, tab_size, ToString(MessageCountLimit, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearStoredMessages(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearStoredMessages";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNumMessagesAllowedByStorageFilter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNumMessagesDeniedByStorageFilter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumStoredMessages(
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNumStoredMessages";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNumStoredMessagesAllowedByRetrievalFilter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNumMessagesDiscardedByMessageCountLimit";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMessageCountLimit(
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMessageCountLimit";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddStorageFilterEntries(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddStorageFilterEntries";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFilter", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFilter, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearStorageFilter(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearStorageFilter";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushEmptyStorageFilter(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushEmptyStorageFilter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushCopyOfStorageFilter(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushCopyOfStorageFilter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushStorageFilter(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushStorageFilter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFilter", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFilter, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PopStorageFilter(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PopStorageFilter";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetStorageFilterStackSize(
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetStorageFilterStackSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddRetrievalFilterEntries(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddRetrievalFilterEntries";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFilter", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFilter, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearRetrievalFilter(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearRetrievalFilter";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushEmptyRetrievalFilter(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushEmptyRetrievalFilter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushCopyOfRetrievalFilter(
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushCopyOfRetrievalFilter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushRetrievalFilter(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushRetrievalFilter";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFilter", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFilter, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PopRetrievalFilter(
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PopRetrievalFilter";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetRetrievalFilterStackSize(
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRetrievalFilterStackSize";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddMessage(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_CATEGORY Category,
        D3D12_MESSAGE_SEVERITY Severity,
        D3D12_MESSAGE_ID ID,
        StringDecoder* pDescription)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddMessage";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Category", to_string_flags, tab_count, tab_size, '"' + ToString(Category, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "Severity", to_string_flags, tab_count, tab_size, '"' + ToString(Severity, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID", to_string_flags, tab_count, tab_size, '"' + ToString(ID, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pDescription", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDescription, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddApplicationMessage(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_SEVERITY Severity,
        StringDecoder* pDescription)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddApplicationMessage";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Severity", to_string_flags, tab_count, tab_size, '"' + ToString(Severity, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "pDescription", to_string_flags, tab_count, tab_size, PointerDecoderToString(pDescription, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnCategory(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_CATEGORY Category,
        BOOL bEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBreakOnCategory";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Category", to_string_flags, tab_count, tab_size, '"' + ToString(Category, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "bEnable", to_string_flags, tab_count, tab_size, ToString(bEnable, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnSeverity(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_SEVERITY Severity,
        BOOL bEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBreakOnSeverity";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Severity", to_string_flags, tab_count, tab_size, '"' + ToString(Severity, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "bEnable", to_string_flags, tab_count, tab_size, ToString(bEnable, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnID(
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_ID ID,
        BOOL bEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBreakOnID";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ID", to_string_flags, tab_count, tab_size, '"' + ToString(ID, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "bEnable", to_string_flags, tab_count, tab_size, ToString(bEnable, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnCategory(
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_CATEGORY Category)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBreakOnCategory";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Category", to_string_flags, tab_count, tab_size, '"' + ToString(Category, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnSeverity(
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_SEVERITY Severity)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBreakOnSeverity";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Severity", to_string_flags, tab_count, tab_size, '"' + ToString(Severity, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnID(
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_ID ID)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBreakOnID";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ID", to_string_flags, tab_count, tab_size, '"' + ToString(ID, to_string_flags, tab_count, tab_size) + '"');
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetMuteDebugOutput(
        format::HandleId object_id,
        BOOL bMute)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMuteDebugOutput";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "bMute", to_string_flags, tab_count, tab_size, ToString(bMute, to_string_flags, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMuteDebugOutput(
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMuteDebugOutput";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IUnknown_QueryInterface(
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObject)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IUnknown";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "QueryInterface";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvObject", to_string_flags, tab_count, tab_size, HandleIdToString(ppvObject));
        }
    );
}

void Dx12AsciiConsumer::Process_IUnknown_AddRef(
        format::HandleId object_id,
        ULONG return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IUnknown";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddRef";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IUnknown_Release(
        format::HandleId object_id,
        ULONG return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IUnknown";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Release";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}



GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
