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
** This part is generated from dxgi.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12AsciiConsumer::Process_CreateDXGIFactory(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "CreateDXGIFactory";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppFactory", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppFactory));
        }
    );
}

void Dx12AsciiConsumer::Process_CreateDXGIFactory1(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "CreateDXGIFactory1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppFactory", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppFactory));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIObject_SetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIObject";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPrivateData";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Name", to_string_flags_, tab_count, tab_size, ToString(*Name.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags_, tab_count, tab_size, ToString(DataSize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIObject_SetPrivateDataInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        format::HandleId pUnknown)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIObject";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPrivateDataInterface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Name", to_string_flags_, tab_count, tab_size, ToString(*Name.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pUnknown", to_string_flags_, tab_count, tab_size, HandleIdToString(pUnknown));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIObject_GetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIObject";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPrivateData";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Name", to_string_flags_, tab_count, tab_size, ToString(*Name.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDataSize", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pDataSize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(pDataSize, pData, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIObject_GetParent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParent)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIObject";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetParent";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppParent", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppParent));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDeviceSubObject_GetDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDeviceSubObject";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDevice";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppDevice", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource_GetSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pSharedHandle)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSharedHandle";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pSharedHandle", to_string_flags_, tab_count, tab_size, HandleIdToString(pSharedHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource_GetUsage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<DXGI_USAGE>* pUsage)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetUsage";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pUsage", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pUsage, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource_SetEvictionPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT EvictionPriority)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEvictionPriority";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "EvictionPriority", to_string_flags_, tab_count, tab_size, ToString(EvictionPriority, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource_GetEvictionPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pEvictionPriority)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetEvictionPriority";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pEvictionPriority", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pEvictionPriority, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIKeyedMutex_AcquireSync(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Key,
        DWORD dwMilliseconds)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIKeyedMutex";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AcquireSync";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Key", to_string_flags_, tab_count, tab_size, ToString(Key, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "dwMilliseconds", to_string_flags_, tab_count, tab_size, ToString(dwMilliseconds, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIKeyedMutex_ReleaseSync(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Key)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIKeyedMutex";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReleaseSync";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Key", to_string_flags_, tab_count, tab_size, ToString(Key, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface_Map(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect,
        UINT MapFlags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Map";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pLockedRect", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pLockedRect, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "MapFlags", to_string_flags_, tab_count, tab_size, ToString(MapFlags, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface_Unmap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Unmap";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface1_GetDC(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Discard,
        PointerDecoder<uint64_t, void*>* phdc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDC";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Discard", to_string_flags_, tab_count, tab_size, ToString(Discard, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]phdc", to_string_flags_, tab_count, tab_size, HandleIdToString(phdc));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface1_ReleaseDC(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRect)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReleaseDC";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDirtyRect", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDirtyRect, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter_EnumOutputs(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Output,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumOutputs";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Output", to_string_flags_, tab_count, tab_size, ToString(Output, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppOutput", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppOutput));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter_CheckInterfaceSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID InterfaceName,
        StructPointerDecoder<Decoded_LARGE_INTEGER>* pUMDVersion)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckInterfaceSupport";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "InterfaceName", to_string_flags_, tab_count, tab_size, ToString(*InterfaceName.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pUMDVersion", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pUMDVersion, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetDisplayModeList(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDisplayModeList";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "EnumFormat", to_string_flags_, tab_count, tab_size, Quote(ToString(EnumFormat)));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, ToString(Flags, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pNumModes", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pNumModes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(pNumModes, pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_FindClosestMatchingMode(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pClosestMatch,
        format::HandleId pConcernedDevice)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "FindClosestMatchingMode";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pModeToMatch", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pModeToMatch, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pClosestMatch", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pClosestMatch, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pConcernedDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pConcernedDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_WaitForVBlank(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "WaitForVBlank";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_TakeOwnership(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        BOOL Exclusive)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "TakeOwnership";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "Exclusive", to_string_flags_, tab_count, tab_size, ToString(Exclusive, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_ReleaseOwnership(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReleaseOwnership";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetGammaControlCapabilities(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES>* pGammaCaps)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetGammaControlCapabilities";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pGammaCaps", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pGammaCaps, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_SetGammaControl(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGammaControl";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pArray", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pArray, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetGammaControl(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetGammaControl";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pArray", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pArray, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_SetDisplaySurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pScanoutSurface)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDisplaySurface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pScanoutSurface", to_string_flags_, tab_count, tab_size, HandleIdToString(pScanoutSurface));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetDisplaySurfaceData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDestination)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDisplaySurfaceData";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDestination", to_string_flags_, tab_count, tab_size, HandleIdToString(pDestination));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput_GetFrameStatistics(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameStatistics";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pStats", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pStats, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_Present(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT SyncInterval,
        UINT Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Present";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "SyncInterval", to_string_flags_, tab_count, tab_size, ToString(SyncInterval, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, ToString(Flags, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetBuffer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Buffer,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSurface)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBuffer";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Buffer", to_string_flags_, tab_count, tab_size, ToString(Buffer, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSurface", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppSurface));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_SetFullscreenState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Fullscreen,
        format::HandleId pTarget)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetFullscreenState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Fullscreen", to_string_flags_, tab_count, tab_size, ToString(Fullscreen, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pTarget", to_string_flags_, tab_count, tab_size, HandleIdToString(pTarget));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetFullscreenState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<BOOL>* pFullscreen,
        HandlePointerDecoder<IDXGIOutput*>* ppTarget)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFullscreenState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pFullscreen", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pFullscreen, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppTarget", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppTarget));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_ResizeBuffers(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT NewFormat,
        UINT SwapChainFlags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResizeBuffers";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "BufferCount", to_string_flags_, tab_count, tab_size, ToString(BufferCount, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Width", to_string_flags_, tab_count, tab_size, ToString(Width, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Height", to_string_flags_, tab_count, tab_size, ToString(Height, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NewFormat", to_string_flags_, tab_count, tab_size, Quote(ToString(NewFormat)));
            FieldToString(str_strm, false, "SwapChainFlags", to_string_flags_, tab_count, tab_size, ToString(SwapChainFlags, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_ResizeTarget(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pNewTargetParameters)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResizeTarget";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pNewTargetParameters", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pNewTargetParameters, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetContainingOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetContainingOutput";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]ppOutput", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppOutput));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetFrameStatistics(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameStatistics";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pStats", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pStats, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_GetLastPresentCount(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pLastPresentCount)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetLastPresentCount";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pLastPresentCount", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pLastPresentCount, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory_EnumAdapters(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumAdapters";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Adapter", to_string_flags_, tab_count, tab_size, ToString(Adapter, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppAdapter", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory_MakeWindowAssociation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "MakeWindowAssociation";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "WindowHandle", to_string_flags_, tab_count, tab_size, HandleIdToString(WindowHandle));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, ToString(Flags, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory_GetWindowAssociation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pWindowHandle)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetWindowAssociation";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pWindowHandle", to_string_flags_, tab_count, tab_size, HandleIdToString(pWindowHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory_CreateSwapChain(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc,
        HandlePointerDecoder<IDXGISwapChain*>* ppSwapChain)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSwapChain";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory_CreateSoftwareAdapter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t Module,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSoftwareAdapter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Module", to_string_flags_, tab_count, tab_size, HandleIdToString(Module));
            FieldToString(str_strm, false, "[out]ppAdapter", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice_GetAdapter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIAdapter*>* pAdapter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetAdapter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pAdapter", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(pAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice_CreateSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc,
        UINT NumSurfaces,
        DXGI_USAGE Usage,
        StructPointerDecoder<Decoded_DXGI_SHARED_RESOURCE>* pSharedResource,
        HandlePointerDecoder<IDXGISurface*>* ppSurface)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSurface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumSurfaces", to_string_flags_, tab_count, tab_size, ToString(NumSurfaces, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Usage", to_string_flags_, tab_count, tab_size, ToString(Usage, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSharedResource", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pSharedResource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSurface", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumSurfaces, ppSurface, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice_QueryResourceResidency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IUnknown*>* ppResources,
        PointerDecoder<DXGI_RESIDENCY>* pResidencyStatus,
        UINT NumResources)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "QueryResourceResidency";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ppResources", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumResources, ppResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pResidencyStatus", to_string_flags_, tab_count, tab_size, EnumPointerDecoderArrayToString(NumResources, pResidencyStatus, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumResources", to_string_flags_, tab_count, tab_size, ToString(NumResources, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice_SetGPUThreadPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        INT Priority)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGPUThreadPriority";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Priority", to_string_flags_, tab_count, tab_size, ToString(Priority, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice_GetGPUThreadPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<INT>* pPriority)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetGPUThreadPriority";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pPriority", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pPriority, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory1_EnumAdapters1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter1*>* ppAdapter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumAdapters1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Adapter", to_string_flags_, tab_count, tab_size, ToString(Adapter, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppAdapter", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory1_IsCurrent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IsCurrent";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter1_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice1_SetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT MaxLatency)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMaximumFrameLatency";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "MaxLatency", to_string_flags_, tab_count, tab_size, ToString(MaxLatency, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice1_GetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pMaxLatency)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMaximumFrameLatency";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pMaxLatency", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pMaxLatency, to_string_flags_, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12AsciiConsumer::Process_IDXGIDisplayControl_IsStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDisplayControl";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IsStereoEnabled";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDisplayControl_SetStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL enabled)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDisplayControl";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetStereoEnabled";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "enabled", to_string_flags_, tab_count, tab_size, ToString(enabled, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_AcquireNextFrame(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT TimeoutInMilliseconds,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_FRAME_INFO>* pFrameInfo,
        HandlePointerDecoder<IDXGIResource*>* ppDesktopResource)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AcquireNextFrame";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "TimeoutInMilliseconds", to_string_flags_, tab_count, tab_size, ToString(TimeoutInMilliseconds, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pFrameInfo", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pFrameInfo, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppDesktopResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppDesktopResource));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFrameDirtyRects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT DirtyRectsBufferSize,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRectsBuffer,
        PointerDecoder<UINT>* pDirtyRectsBufferSizeRequired)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameDirtyRects";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DirtyRectsBufferSize", to_string_flags_, tab_count, tab_size, ToString(DirtyRectsBufferSize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDirtyRectsBuffer", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(DirtyRectsBufferSize/sizeof tagRECT, pDirtyRectsBuffer, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDirtyRectsBufferSizeRequired", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pDirtyRectsBufferSizeRequired, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFrameMoveRects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT MoveRectsBufferSize,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_MOVE_RECT>* pMoveRectBuffer,
        PointerDecoder<UINT>* pMoveRectsBufferSizeRequired)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameMoveRects";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "MoveRectsBufferSize", to_string_flags_, tab_count, tab_size, ToString(MoveRectsBufferSize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pMoveRectBuffer", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(MoveRectsBufferSize/sizeof DXGI_OUTDUPL_MOVE_RECT, pMoveRectBuffer, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pMoveRectsBufferSizeRequired", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pMoveRectsBufferSizeRequired, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFramePointerShape(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT PointerShapeBufferSize,
        PointerDecoder<uint8_t>* pPointerShapeBuffer,
        PointerDecoder<UINT>* pPointerShapeBufferSizeRequired,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO>* pPointerShapeInfo)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFramePointerShape";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "PointerShapeBufferSize", to_string_flags_, tab_count, tab_size, ToString(PointerShapeBufferSize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pPointerShapeBuffer", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(PointerShapeBufferSize, pPointerShapeBuffer, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pPointerShapeBufferSizeRequired", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pPointerShapeBufferSizeRequired, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pPointerShapeInfo", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pPointerShapeInfo, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_MapDesktopSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "MapDesktopSurface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pLockedRect", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pLockedRect, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_UnMapDesktopSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnMapDesktopSurface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_ReleaseFrame(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutputDuplication";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReleaseFrame";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISurface2_GetResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParentResource,
        PointerDecoder<UINT>* pSubresourceIndex)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISurface2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetResource";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppParentResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppParentResource));
            FieldToString(str_strm, false, "[out]pSubresourceIndex", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pSubresourceIndex, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource1_CreateSubresourceSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT index,
        HandlePointerDecoder<IDXGISurface2*>* ppSurface)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSubresourceSurface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "index", to_string_flags_, tab_count, tab_size, ToString(index, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSurface", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppSurface));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIResource1_CreateSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD dwAccess,
        WStringDecoder* lpName,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIResource1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSharedHandle";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pAttributes", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pAttributes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "dwAccess", to_string_flags_, tab_count, tab_size, ToString(dwAccess, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "lpName", to_string_flags_, tab_count, tab_size, StringDecoderToString(lpName));
            FieldToString(str_strm, false, "[out]pHandle", to_string_flags_, tab_count, tab_size, HandleIdToString(pHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice2_OfferResources(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OfferResources";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumResources", to_string_flags_, tab_count, tab_size, ToString(NumResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppResources", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumResources, ppResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Priority", to_string_flags_, tab_count, tab_size, Quote(ToString(Priority)));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice2_ReclaimResources(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<BOOL>* pDiscarded)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReclaimResources";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumResources", to_string_flags_, tab_count, tab_size, ToString(NumResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppResources", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumResources, ppResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDiscarded", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumResources, pDiscarded, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice2_EnqueueSetEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnqueueSetEvent";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags_, tab_count, tab_size, HandleIdToString(hEvent));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetFullscreenDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFullscreenDesc";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetHwnd(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pHwnd)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetHwnd";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pHwnd", to_string_flags_, tab_count, tab_size, HandleIdToString(pHwnd));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetCoreWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID refiid,
        HandlePointerDecoder<void*>* ppUnk)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCoreWindow";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "refiid", to_string_flags_, tab_count, tab_size, ToString(*refiid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppUnk", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppUnk));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_Present1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT SyncInterval,
        UINT PresentFlags,
        StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* pPresentParameters)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Present1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "SyncInterval", to_string_flags_, tab_count, tab_size, ToString(SyncInterval, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "PresentFlags", to_string_flags_, tab_count, tab_size, ToString(PresentFlags, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pPresentParameters", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pPresentParameters, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_IsTemporaryMonoSupported(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IsTemporaryMonoSupported";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetRestrictToOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIOutput*>* ppRestrictToOutput)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRestrictToOutput";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]ppRestrictToOutput", to_string_flags_, tab_count, tab_size, HandleIdToString(ppRestrictToOutput));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_SetBackgroundColor(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBackgroundColor";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pColor", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pColor, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetBackgroundColor(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBackgroundColor";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pColor", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pColor, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_SetRotation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_MODE_ROTATION Rotation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetRotation";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Rotation", to_string_flags_, tab_count, tab_size, Quote(ToString(Rotation)));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetRotation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<DXGI_MODE_ROTATION>* pRotation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRotation";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pRotation", to_string_flags_, tab_count, tab_size, EnumPointerDecoderToString(pRotation));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_IsWindowedStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IsWindowedStereoEnabled";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForHwnd(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSwapChainForHwnd";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "hWnd", to_string_flags_, tab_count, tab_size, HandleIdToString(hWnd));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pFullscreenDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pFullscreenDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRestrictToOutput", to_string_flags_, tab_count, tab_size, HandleIdToString(pRestrictToOutput));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForCoreWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        format::HandleId pWindow,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSwapChainForCoreWindow";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "pWindow", to_string_flags_, tab_count, tab_size, HandleIdToString(pWindow));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRestrictToOutput", to_string_flags_, tab_count, tab_size, HandleIdToString(pRestrictToOutput));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_GetSharedResourceAdapterLuid(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hResource,
        StructPointerDecoder<Decoded_LUID>* pLuid)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSharedResourceAdapterLuid";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hResource", to_string_flags_, tab_count, tab_size, HandleIdToString(hResource));
            FieldToString(str_strm, false, "[out]pLuid", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pLuid, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterStereoStatusWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterStereoStatusWindow";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "WindowHandle", to_string_flags_, tab_count, tab_size, HandleIdToString(WindowHandle));
            FieldToString(str_strm, false, "wMsg", to_string_flags_, tab_count, tab_size, ToString(wMsg, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterStereoStatusEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterStereoStatusEvent";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags_, tab_count, tab_size, HandleIdToString(hEvent));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_UnregisterStereoStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterStereoStatus";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "dwCookie", to_string_flags_, tab_count, tab_size, ToString(dwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterOcclusionStatusWindow";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "WindowHandle", to_string_flags_, tab_count, tab_size, HandleIdToString(WindowHandle));
            FieldToString(str_strm, false, "wMsg", to_string_flags_, tab_count, tab_size, ToString(wMsg, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterOcclusionStatusEvent";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags_, tab_count, tab_size, HandleIdToString(hEvent));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_UnregisterOcclusionStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterOcclusionStatus";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "dwCookie", to_string_flags_, tab_count, tab_size, ToString(dwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForComposition(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSwapChainForComposition";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRestrictToOutput", to_string_flags_, tab_count, tab_size, HandleIdToString(pRestrictToOutput));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter2_GetDesc2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc2";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput1_GetDisplayModeList1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDisplayModeList1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "EnumFormat", to_string_flags_, tab_count, tab_size, Quote(ToString(EnumFormat)));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, ToString(Flags, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pNumModes", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pNumModes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(pNumModes, pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput1_FindClosestMatchingMode1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pClosestMatch,
        format::HandleId pConcernedDevice)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "FindClosestMatchingMode1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pModeToMatch", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pModeToMatch, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pClosestMatch", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pClosestMatch, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pConcernedDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pConcernedDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput1_GetDisplaySurfaceData1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDestination)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDisplaySurfaceData1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDestination", to_string_flags_, tab_count, tab_size, HandleIdToString(pDestination));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput1_DuplicateOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DuplicateOutput";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "[out]ppOutputDuplication", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppOutputDuplication));
        }
    );
}

/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12AsciiConsumer::Process_CreateDXGIFactory2(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "CreateDXGIFactory2";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags_, tab_count, tab_size, ToString(Flags, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppFactory", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppFactory));
        }
    );
}

void Dx12AsciiConsumer::Process_DXGIGetDebugInterface1(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* pDebug)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "DXGIGetDebugInterface1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags_, tab_count, tab_size, ToString(Flags, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDebug", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(pDebug));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice3_Trim(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Trim";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetSourceSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Width,
        UINT Height)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetSourceSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Width", to_string_flags_, tab_count, tab_size, ToString(Width, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Height", to_string_flags_, tab_count, tab_size, ToString(Height, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetSourceSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSourceSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pWidth", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pWidth, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pHeight", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pHeight, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT MaxLatency)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMaximumFrameLatency";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "MaxLatency", to_string_flags_, tab_count, tab_size, ToString(MaxLatency, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pMaxLatency)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMaximumFrameLatency";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pMaxLatency", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pMaxLatency, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        uint64_t return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameLatencyWaitableObject";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetMatrixTransform(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMatrixTransform";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pMatrix", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pMatrix, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetMatrixTransform(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMatrixTransform";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pMatrix", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pMatrix, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput2_SupportsOverlays(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SupportsOverlays";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory3_GetCreationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCreationFlags";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_PresentBuffer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT BufferToPresent,
        UINT SyncInterval,
        UINT Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PresentBuffer";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "BufferToPresent", to_string_flags_, tab_count, tab_size, ToString(BufferToPresent, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "SyncInterval", to_string_flags_, tab_count, tab_size, ToString(SyncInterval, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, ToString(Flags, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetSourceRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetSourceRect";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRect", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pRect, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetTargetRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetTargetRect";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRect", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pRect, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetDestSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Width,
        UINT Height)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDestSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Width", to_string_flags_, tab_count, tab_size, ToString(Width, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Height", to_string_flags_, tab_count, tab_size, ToString(Height, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetSourceRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSourceRect";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pRect", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pRect, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetTargetRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetTargetRect";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pRect", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pRect, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetDestSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDestSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pWidth", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pWidth, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pHeight", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pHeight, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetColorSpace(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetColorSpace";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ColorSpace", to_string_flags_, tab_count, tab_size, Quote(ToString(ColorSpace)));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetColorSpace(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDecodeSwapChain";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetColorSpace";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        uint64_t hSurface,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactoryMedia";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSwapChainForCompositionSurfaceHandle";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "hSurface", to_string_flags_, tab_count, tab_size, HandleIdToString(hSurface));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRestrictToOutput", to_string_flags_, tab_count, tab_size, HandleIdToString(pRestrictToOutput));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactoryMedia";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateDecodeSwapChainForCompositionSurfaceHandle";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "hSurface", to_string_flags_, tab_count, tab_size, HandleIdToString(hSurface));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pYuvDecodeBuffers", to_string_flags_, tab_count, tab_size, HandleIdToString(pYuvDecodeBuffers));
            FieldToString(str_strm, false, "pRestrictToOutput", to_string_flags_, tab_count, tab_size, HandleIdToString(pRestrictToOutput));
            FieldToString(str_strm, false, "[out]ppSwapChain", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppSwapChain));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA>* pStats)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChainMedia";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFrameStatisticsMedia";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pStats", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pStats, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_SetPresentDuration(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Duration)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChainMedia";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPresentDuration";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Duration", to_string_flags_, tab_count, tab_size, ToString(Duration, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_CheckPresentDurationSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT DesiredPresentDuration,
        PointerDecoder<UINT>* pClosestSmallerPresentDuration,
        PointerDecoder<UINT>* pClosestLargerPresentDuration)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChainMedia";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckPresentDurationSupport";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DesiredPresentDuration", to_string_flags_, tab_count, tab_size, ToString(DesiredPresentDuration, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pClosestSmallerPresentDuration", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pClosestSmallerPresentDuration, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pClosestLargerPresentDuration", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pClosestLargerPresentDuration, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput3_CheckOverlaySupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        format::HandleId pConcernedDevice,
        PointerDecoder<UINT>* pFlags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckOverlaySupport";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "EnumFormat", to_string_flags_, tab_count, tab_size, Quote(ToString(EnumFormat)));
            FieldToString(str_strm, false, "pConcernedDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pConcernedDevice));
            FieldToString(str_strm, false, "[out]pFlags", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pFlags, to_string_flags_, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12AsciiConsumer::Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCurrentBackBufferIndex";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain3_CheckColorSpaceSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        PointerDecoder<UINT>* pColorSpaceSupport)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckColorSpaceSupport";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ColorSpace", to_string_flags_, tab_count, tab_size, Quote(ToString(ColorSpace)));
            FieldToString(str_strm, false, "[out]pColorSpaceSupport", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pColorSpaceSupport, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain3_SetColorSpace1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_COLOR_SPACE_TYPE ColorSpace)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetColorSpace1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ColorSpace", to_string_flags_, tab_count, tab_size, Quote(ToString(ColorSpace)));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain3_ResizeBuffers1(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResizeBuffers1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "BufferCount", to_string_flags_, tab_count, tab_size, ToString(BufferCount, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Width", to_string_flags_, tab_count, tab_size, ToString(Width, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Height", to_string_flags_, tab_count, tab_size, ToString(Height, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Format", to_string_flags_, tab_count, tab_size, Quote(ToString(Format)));
            FieldToString(str_strm, false, "SwapChainFlags", to_string_flags_, tab_count, tab_size, ToString(SwapChainFlags, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pCreationNodeMask", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(BufferCount, pCreationNodeMask, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppPresentQueue", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(BufferCount, ppPresentQueue, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput4_CheckOverlayColorSpaceSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT Format,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        format::HandleId pConcernedDevice,
        PointerDecoder<UINT>* pFlags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckOverlayColorSpaceSupport";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Format", to_string_flags_, tab_count, tab_size, Quote(ToString(Format)));
            FieldToString(str_strm, false, "ColorSpace", to_string_flags_, tab_count, tab_size, Quote(ToString(ColorSpace)));
            FieldToString(str_strm, false, "pConcernedDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pConcernedDevice));
            FieldToString(str_strm, false, "[out]pFlags", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pFlags, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory4_EnumAdapterByLuid(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_LUID AdapterLuid,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumAdapterByLuid";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "AdapterLuid", to_string_flags_, tab_count, tab_size, ToString(*AdapterLuid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvAdapter", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory4_EnumWarpAdapter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumWarpAdapter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvAdapter", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterHardwareContentProtectionTeardownStatusEvent";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags_, tab_count, tab_size, HandleIdToString(hEvent));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterHardwareContentProtectionTeardownStatus";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "dwCookie", to_string_flags_, tab_count, tab_size, ToString(dwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_QueryVideoMemoryInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        StructPointerDecoder<Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO>* pVideoMemoryInfo)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "QueryVideoMemoryInfo";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NodeIndex", to_string_flags_, tab_count, tab_size, ToString(NodeIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "MemorySegmentGroup", to_string_flags_, tab_count, tab_size, Quote(ToString(MemorySegmentGroup)));
            FieldToString(str_strm, false, "[out]pVideoMemoryInfo", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pVideoMemoryInfo, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_SetVideoMemoryReservation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        UINT64 Reservation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetVideoMemoryReservation";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NodeIndex", to_string_flags_, tab_count, tab_size, ToString(NodeIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "MemorySegmentGroup", to_string_flags_, tab_count, tab_size, Quote(ToString(MemorySegmentGroup)));
            FieldToString(str_strm, false, "Reservation", to_string_flags_, tab_count, tab_size, ToString(Reservation, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterVideoMemoryBudgetChangeNotificationEvent";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags_, tab_count, tab_size, HandleIdToString(hEvent));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterVideoMemoryBudgetChangeNotification";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "dwCookie", to_string_flags_, tab_count, tab_size, ToString(dwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12AsciiConsumer::Process_IDXGIOutput5_DuplicateOutput1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        UINT Flags,
        UINT SupportedFormatsCount,
        PointerDecoder<DXGI_FORMAT>* pSupportedFormats,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DuplicateOutput1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDevice", to_string_flags_, tab_count, tab_size, HandleIdToString(pDevice));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, ToString(Flags, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "SupportedFormatsCount", to_string_flags_, tab_count, tab_size, ToString(SupportedFormatsCount, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSupportedFormats", to_string_flags_, tab_count, tab_size, EnumPointerDecoderArrayToString(SupportedFormatsCount, pSupportedFormats, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppOutputDuplication", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppOutputDuplication));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain4_SetHDRMetaData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_HDR_METADATA_TYPE Type,
        UINT Size,
        PointerDecoder<uint8_t>* pMetaData)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGISwapChain4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetHDRMetaData";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "Size", to_string_flags_, tab_count, tab_size, ToString(Size, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pMetaData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(Size, pMetaData, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice4_OfferResources1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority,
        UINT Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OfferResources1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumResources", to_string_flags_, tab_count, tab_size, ToString(NumResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppResources", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumResources, ppResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Priority", to_string_flags_, tab_count, tab_size, Quote(ToString(Priority)));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, ToString(Flags, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIDevice4_ReclaimResources1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<DXGI_RECLAIM_RESOURCE_RESULTS>* pResults)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIDevice4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReclaimResources1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumResources", to_string_flags_, tab_count, tab_size, ToString(NumResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppResources", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumResources, ppResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pResults", to_string_flags_, tab_count, tab_size, EnumPointerDecoderArrayToString(NumResources, pResults, to_string_flags_, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12AsciiConsumer::Process_DXGIDeclareAdapterRemovalSupport(
        const ApiCallInfo& call_info,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "DXGIDeclareAdapterRemovalSupport";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIAdapter4_GetDesc3(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIAdapter4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc3";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput6_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIOutput6_CheckHardwareCompositionSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pFlags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIOutput6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckHardwareCompositionSupport";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pFlags", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pFlags, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory6_EnumAdapterByGpuPreference(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        DXGI_GPU_PREFERENCE GpuPreference,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumAdapterByGpuPreference";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Adapter", to_string_flags_, tab_count, tab_size, ToString(Adapter, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "GpuPreference", to_string_flags_, tab_count, tab_size, Quote(ToString(GpuPreference)));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvAdapter", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvAdapter));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory7_RegisterAdaptersChangedEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory7";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterAdaptersChangedEvent";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hEvent", to_string_flags_, tab_count, tab_size, HandleIdToString(hEvent));
            FieldToString(str_strm, false, "[out]pdwCookie", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pdwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory7";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterAdaptersChangedEvent";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "dwCookie", to_string_flags_, tab_count, tab_size, ToString(dwCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from d3d12.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12AsciiConsumer::Process_D3D12SerializeRootSignature(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* pRootSignature,
        D3D_ROOT_SIGNATURE_VERSION Version,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12SerializeRootSignature";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRootSignature", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pRootSignature, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Version", to_string_flags_, tab_count, tab_size, Quote(ToString(Version)));
            FieldToString(str_strm, false, "[out]ppBlob", to_string_flags_, tab_count, tab_size, HandleIdToString(ppBlob));
            FieldToString(str_strm, false, "[out]ppErrorBlob", to_string_flags_, tab_count, tab_size, HandleIdToString(ppErrorBlob));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12SerializeVersionedRootSignature(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pRootSignature,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12SerializeVersionedRootSignature";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRootSignature", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pRootSignature, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppBlob", to_string_flags_, tab_count, tab_size, HandleIdToString(ppBlob));
            FieldToString(str_strm, false, "[out]ppErrorBlob", to_string_flags_, tab_count, tab_size, HandleIdToString(ppErrorBlob));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12CreateVersionedRootSignatureDeserializer(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        Decoded_GUID pRootSignatureDeserializerInterface,
        HandlePointerDecoder<void*>* ppRootSignatureDeserializer)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12CreateVersionedRootSignatureDeserializer";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pSrcData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(SrcDataSizeInBytes, pSrcData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcDataSizeInBytes", to_string_flags_, tab_count, tab_size, ToString(SrcDataSizeInBytes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRootSignatureDeserializerInterface", to_string_flags_, tab_count, tab_size, ToString(*pRootSignatureDeserializerInterface.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppRootSignatureDeserializer", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppRootSignatureDeserializer));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12CreateDevice(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        format::HandleId pAdapter,
        D3D_FEATURE_LEVEL MinimumFeatureLevel,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12CreateDevice";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pAdapter", to_string_flags_, tab_count, tab_size, HandleIdToString(pAdapter));
            FieldToString(str_strm, false, "MinimumFeatureLevel", to_string_flags_, tab_count, tab_size, Quote(ToString(MinimumFeatureLevel)));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppDevice", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12GetDebugInterface(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDebug)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12GetDebugInterface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvDebug", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvDebug));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12EnableExperimentalFeatures(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        UINT NumFeatures,
        StructPointerDecoder<Decoded_GUID>* pIIDs,
        PointerDecoder<uint8_t>* pConfigurationStructs,
        PointerDecoder<UINT>* pConfigurationStructSizes)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12EnableExperimentalFeatures";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumFeatures", to_string_flags_, tab_count, tab_size, ToString(NumFeatures, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pIIDs", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumFeatures, pIIDs, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pConfigurationStructs", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumFeatures, pConfigurationStructs, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pConfigurationStructSizes", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumFeatures, pConfigurationStructSizes, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12GetInterface(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID rclsid,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDebug)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = nullptr;
    writeApiCallToFileInfo.handleId = 0;
    writeApiCallToFileInfo.pFunctionName = "D3D12GetInterface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "rclsid", to_string_flags_, tab_count, tab_size, ToString(*rclsid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvDebug", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvDebug));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Object_GetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Object";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPrivateData";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "guid", to_string_flags_, tab_count, tab_size, ToString(*guid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDataSize", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pDataSize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(pDataSize, pData, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Object_SetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Object";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPrivateData";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "guid", to_string_flags_, tab_count, tab_size, ToString(*guid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags_, tab_count, tab_size, ToString(DataSize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Object_SetPrivateDataInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        format::HandleId pData)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Object";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPrivateDataInterface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "guid", to_string_flags_, tab_count, tab_size, ToString(*guid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, HandleIdToString(pData));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Object_SetName(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* Name)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Object";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetName";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Name", to_string_flags_, tab_count, tab_size, StringDecoderToString(Name));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceChild_GetDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDevice)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceChild";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDevice";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvDevice", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D_ROOT_SIGNATURE_VERSION convertToVersion,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* ppDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12VersionedRootSignatureDeserializer";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRootSignatureDescAtVersion";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "convertToVersion", to_string_flags_, tab_count, tab_size, Quote(ToString(convertToVersion)));
            FieldToString(str_strm, false, "[out]ppDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(ppDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_Map(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pReadRange,
        PointerDecoder<uint64_t, void*>* ppData)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Map";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Subresource", to_string_flags_, tab_count, tab_size, ToString(Subresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pReadRange", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pReadRange, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppData", to_string_flags_, tab_count, tab_size, PointerDecoderToString<uint64_t, void*>(ppData));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_Unmap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pWrittenRange)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Unmap";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Subresource", to_string_flags_, tab_count, tab_size, ToString(Subresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pWrittenRange", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pWrittenRange, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_GetGPUVirtualAddress(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetGPUVirtualAddress";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_ReadFromSubresource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t pDstData,
        UINT DstRowPitch,
        UINT DstDepthPitch,
        UINT SrcSubresource,
        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReadFromSubresource";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pDstData", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstData));
            FieldToString(str_strm, false, "DstRowPitch", to_string_flags_, tab_count, tab_size, ToString(DstRowPitch, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DstDepthPitch", to_string_flags_, tab_count, tab_size, ToString(DstDepthPitch, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcSubresource", to_string_flags_, tab_count, tab_size, ToString(SrcSubresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcBox", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pSrcBox, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_GetHeapProperties(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        PointerDecoder<D3D12_HEAP_FLAGS>* pHeapFlags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetHeapProperties";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pHeapProperties", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pHeapProperties, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pHeapFlags", to_string_flags_, tab_count, tab_size, EnumPointerDecoderToString(pHeapFlags));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandAllocator_Reset(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandAllocator";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Reset";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Fence_GetCompletedValue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Fence";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCompletedValue";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Fence_SetEventOnCompletion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Value,
        uint64_t hEvent)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Fence";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEventOnCompletion";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Value", to_string_flags_, tab_count, tab_size, ToString(Value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "hEvent", to_string_flags_, tab_count, tab_size, HandleIdToString(hEvent));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Fence_Signal(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Fence";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Signal";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Value", to_string_flags_, tab_count, tab_size, ToString(Value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Fence1_GetCreationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_FENCE_FLAGS return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Fence1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCreationFlags";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineState_GetCachedBlob(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineState";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCachedBlob";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]ppBlob", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppBlob));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Close(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Close";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Reset(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pAllocator,
        format::HandleId pInitialState)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Reset";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pAllocator", to_string_flags_, tab_count, tab_size, HandleIdToString(pAllocator));
            FieldToString(str_strm, false, "pInitialState", to_string_flags_, tab_count, tab_size, HandleIdToString(pInitialState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pPipelineState)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearState";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pPipelineState", to_string_flags_, tab_count, tab_size, HandleIdToString(pPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DrawInstanced(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT VertexCountPerInstance,
        UINT InstanceCount,
        UINT StartVertexLocation,
        UINT StartInstanceLocation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DrawInstanced";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "VertexCountPerInstance", to_string_flags_, tab_count, tab_size, ToString(VertexCountPerInstance, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InstanceCount", to_string_flags_, tab_count, tab_size, ToString(InstanceCount, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "StartVertexLocation", to_string_flags_, tab_count, tab_size, ToString(StartVertexLocation, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "StartInstanceLocation", to_string_flags_, tab_count, tab_size, ToString(StartInstanceLocation, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT IndexCountPerInstance,
        UINT InstanceCount,
        UINT StartIndexLocation,
        INT BaseVertexLocation,
        UINT StartInstanceLocation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DrawIndexedInstanced";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "IndexCountPerInstance", to_string_flags_, tab_count, tab_size, ToString(IndexCountPerInstance, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InstanceCount", to_string_flags_, tab_count, tab_size, ToString(InstanceCount, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "StartIndexLocation", to_string_flags_, tab_count, tab_size, ToString(StartIndexLocation, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BaseVertexLocation", to_string_flags_, tab_count, tab_size, ToString(BaseVertexLocation, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "StartInstanceLocation", to_string_flags_, tab_count, tab_size, ToString(StartInstanceLocation, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Dispatch(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Dispatch";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ThreadGroupCountX", to_string_flags_, tab_count, tab_size, ToString(ThreadGroupCountX, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ThreadGroupCountY", to_string_flags_, tab_count, tab_size, ToString(ThreadGroupCountY, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ThreadGroupCountZ", to_string_flags_, tab_count, tab_size, ToString(ThreadGroupCountZ, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyBufferRegion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstBuffer,
        UINT64 DstOffset,
        format::HandleId pSrcBuffer,
        UINT64 SrcOffset,
        UINT64 NumBytes)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyBufferRegion";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstBuffer));
            FieldToString(str_strm, false, "DstOffset", to_string_flags_, tab_count, tab_size, ToString(DstOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcBuffer));
            FieldToString(str_strm, false, "SrcOffset", to_string_flags_, tab_count, tab_size, ToString(SrcOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumBytes", to_string_flags_, tab_count, tab_size, ToString(NumBytes, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyTextureRegion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pDst,
        UINT DstX,
        UINT DstY,
        UINT DstZ,
        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pSrc,
        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyTextureRegion";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDst", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDst, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DstX", to_string_flags_, tab_count, tab_size, ToString(DstX, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DstY", to_string_flags_, tab_count, tab_size, ToString(DstY, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DstZ", to_string_flags_, tab_count, tab_size, ToString(DstZ, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pSrc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcBox", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pSrcBox, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstResource,
        format::HandleId pSrcResource)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyResource";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstResource));
            FieldToString(str_strm, false, "pSrcResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyTiles(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pTiledResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pTileRegionStartCoordinate,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pTileRegionSize,
        format::HandleId pBuffer,
        UINT64 BufferStartOffsetInBytes,
        D3D12_TILE_COPY_FLAGS Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyTiles";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pTiledResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pTiledResource));
            FieldToString(str_strm, false, "pTileRegionStartCoordinate", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pTileRegionStartCoordinate, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pTileRegionSize", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pTileRegionSize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pBuffer));
            FieldToString(str_strm, false, "BufferStartOffsetInBytes", to_string_flags_, tab_count, tab_size, ToString(BufferStartOffsetInBytes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResolveSubresource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstResource,
        UINT DstSubresource,
        format::HandleId pSrcResource,
        UINT SrcSubresource,
        DXGI_FORMAT Format)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResolveSubresource";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstResource));
            FieldToString(str_strm, false, "DstSubresource", to_string_flags_, tab_count, tab_size, ToString(DstSubresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcResource));
            FieldToString(str_strm, false, "SrcSubresource", to_string_flags_, tab_count, tab_size, ToString(SrcSubresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Format", to_string_flags_, tab_count, tab_size, Quote(ToString(Format)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D_PRIMITIVE_TOPOLOGY PrimitiveTopology)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IASetPrimitiveTopology";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "PrimitiveTopology", to_string_flags_, tab_count, tab_size, Quote(ToString(PrimitiveTopology)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_RSSetViewports(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumViewports,
        StructPointerDecoder<Decoded_D3D12_VIEWPORT>* pViewports)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RSSetViewports";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumViewports", to_string_flags_, tab_count, tab_size, ToString(NumViewports, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pViewports", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumViewports, pViewports, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_RSSetScissorRects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RSSetScissorRects";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumRects", to_string_flags_, tab_count, tab_size, ToString(NumRects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRects", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumRects, pRects, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetBlendFactor(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        PointerDecoder<FLOAT> BlendFactor [4])
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OMSetBlendFactor";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "BlendFactor", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(4, BlendFactor, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetStencilRef(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT StencilRef)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OMSetStencilRef";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "StencilRef", to_string_flags_, tab_count, tab_size, ToString(StencilRef, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetPipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pPipelineState)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPipelineState";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pPipelineState", to_string_flags_, tab_count, tab_size, HandleIdToString(pPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ExecuteBundle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pCommandList)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ExecuteBundle";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pCommandList", to_string_flags_, tab_count, tab_size, HandleIdToString(pCommandList));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumDescriptorHeaps,
        HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDescriptorHeaps";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumDescriptorHeaps", to_string_flags_, tab_count, tab_size, ToString(NumDescriptorHeaps, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppDescriptorHeaps", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumDescriptorHeaps, ppDescriptorHeaps, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pRootSignature)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRootSignature";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRootSignature", to_string_flags_, tab_count, tab_size, HandleIdToString(pRootSignature));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pRootSignature)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRootSignature";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pRootSignature", to_string_flags_, tab_count, tab_size, HandleIdToString(pRootSignature));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRootDescriptorTable";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BaseDescriptor", to_string_flags_, tab_count, tab_size, ToString(*BaseDescriptor.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRootDescriptorTable";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BaseDescriptor", to_string_flags_, tab_count, tab_size, ToString(*BaseDescriptor.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRoot32BitConstant";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcData", to_string_flags_, tab_count, tab_size, ToString(SrcData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestOffsetIn32BitValues", to_string_flags_, tab_count, tab_size, ToString(DestOffsetIn32BitValues, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRoot32BitConstant";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcData", to_string_flags_, tab_count, tab_size, ToString(SrcData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestOffsetIn32BitValues", to_string_flags_, tab_count, tab_size, ToString(DestOffsetIn32BitValues, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRoot32BitConstants";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Num32BitValuesToSet", to_string_flags_, tab_count, tab_size, ToString(Num32BitValuesToSet, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(Num32BitValuesToSet * sizeof ( UINT ), pSrcData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestOffsetIn32BitValues", to_string_flags_, tab_count, tab_size, ToString(DestOffsetIn32BitValues, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRoot32BitConstants";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Num32BitValuesToSet", to_string_flags_, tab_count, tab_size, ToString(Num32BitValuesToSet, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(Num32BitValuesToSet * sizeof ( UINT ), pSrcData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestOffsetIn32BitValues", to_string_flags_, tab_count, tab_size, ToString(DestOffsetIn32BitValues, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRootConstantBufferView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags_, tab_count, tab_size, ToString(BufferLocation, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRootConstantBufferView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags_, tab_count, tab_size, ToString(BufferLocation, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRootShaderResourceView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags_, tab_count, tab_size, ToString(BufferLocation, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRootShaderResourceView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags_, tab_count, tab_size, ToString(BufferLocation, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetComputeRootUnorderedAccessView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags_, tab_count, tab_size, ToString(BufferLocation, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGraphicsRootUnorderedAccessView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RootParameterIndex", to_string_flags_, tab_count, tab_size, ToString(RootParameterIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BufferLocation", to_string_flags_, tab_count, tab_size, ToString(BufferLocation, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IASetIndexBuffer";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pView", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pView, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetVertexBuffers(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "IASetVertexBuffers";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "StartSlot", to_string_flags_, tab_count, tab_size, ToString(StartSlot, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumViews", to_string_flags_, tab_count, tab_size, ToString(NumViews, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pViews", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumViews, pViews, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SOSetTargets(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW>* pViews)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SOSetTargets";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "StartSlot", to_string_flags_, tab_count, tab_size, ToString(StartSlot, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumViews", to_string_flags_, tab_count, tab_size, ToString(NumViews, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pViews", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumViews, pViews, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumRenderTargetDescriptors,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
        BOOL RTsSingleHandleToDescriptorRange,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OMSetRenderTargets";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumRenderTargetDescriptors", to_string_flags_, tab_count, tab_size, ToString(NumRenderTargetDescriptors, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRenderTargetDescriptors", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString((NumRenderTargetDescriptors ? (RTsSingleHandleToDescriptorRange ? 1 : NumRenderTargetDescriptors) : 0), pRenderTargetDescriptors, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "RTsSingleHandleToDescriptorRange", to_string_flags_, tab_count, tab_size, ToString(RTsSingleHandleToDescriptorRange, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDepthStencilDescriptor", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDepthStencilDescriptor, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearDepthStencilView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
        D3D12_CLEAR_FLAGS ClearFlags,
        FLOAT Depth,
        UINT8 Stencil,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearDepthStencilView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DepthStencilView", to_string_flags_, tab_count, tab_size, ToString(*DepthStencilView.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ClearFlags", to_string_flags_, tab_count, tab_size, Quote(ToString(ClearFlags)));
            FieldToString(str_strm, false, "Depth", to_string_flags_, tab_count, tab_size, ToString(Depth, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Stencil", to_string_flags_, tab_count, tab_size, ToString(Stencil, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumRects", to_string_flags_, tab_count, tab_size, ToString(NumRects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRects", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumRects, pRects, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearRenderTargetView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
        PointerDecoder<FLOAT> ColorRGBA [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearRenderTargetView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "RenderTargetView", to_string_flags_, tab_count, tab_size, ToString(*RenderTargetView.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ColorRGBA", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(4, ColorRGBA, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumRects", to_string_flags_, tab_count, tab_size, ToString(NumRects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRects", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumRects, pRects, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        format::HandleId pResource,
        PointerDecoder<UINT> Values [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearUnorderedAccessViewUint";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ViewGPUHandleInCurrentHeap", to_string_flags_, tab_count, tab_size, ToString(*ViewGPUHandleInCurrentHeap.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ViewCPUHandle", to_string_flags_, tab_count, tab_size, ToString(*ViewCPUHandle.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Values", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(4, Values, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumRects", to_string_flags_, tab_count, tab_size, ToString(NumRects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRects", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumRects, pRects, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        format::HandleId pResource,
        PointerDecoder<FLOAT> Values [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearUnorderedAccessViewFloat";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ViewGPUHandleInCurrentHeap", to_string_flags_, tab_count, tab_size, ToString(*ViewGPUHandleInCurrentHeap.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ViewCPUHandle", to_string_flags_, tab_count, tab_size, ToString(*ViewCPUHandle.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Values", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(4, Values, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumRects", to_string_flags_, tab_count, tab_size, ToString(NumRects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRects", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumRects, pRects, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DiscardResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_DISCARD_REGION>* pRegion)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DiscardResource";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "pRegion", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pRegion, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_BeginQuery(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BeginQuery";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pQueryHeap", to_string_flags_, tab_count, tab_size, HandleIdToString(pQueryHeap));
            FieldToString(str_strm, false, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "Index", to_string_flags_, tab_count, tab_size, ToString(Index, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_EndQuery(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EndQuery";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pQueryHeap", to_string_flags_, tab_count, tab_size, HandleIdToString(pQueryHeap));
            FieldToString(str_strm, false, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "Index", to_string_flags_, tab_count, tab_size, ToString(Index, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResolveQueryData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT StartIndex,
        UINT NumQueries,
        format::HandleId pDestinationBuffer,
        UINT64 AlignedDestinationBufferOffset)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResolveQueryData";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pQueryHeap", to_string_flags_, tab_count, tab_size, HandleIdToString(pQueryHeap));
            FieldToString(str_strm, false, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "StartIndex", to_string_flags_, tab_count, tab_size, ToString(StartIndex, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumQueries", to_string_flags_, tab_count, tab_size, ToString(NumQueries, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDestinationBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pDestinationBuffer));
            FieldToString(str_strm, false, "AlignedDestinationBufferOffset", to_string_flags_, tab_count, tab_size, ToString(AlignedDestinationBufferOffset, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetPredication(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pBuffer,
        UINT64 AlignedBufferOffset,
        D3D12_PREDICATION_OP Operation)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPredication";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pBuffer));
            FieldToString(str_strm, false, "AlignedBufferOffset", to_string_flags_, tab_count, tab_size, ToString(AlignedBufferOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Operation", to_string_flags_, tab_count, tab_size, Quote(ToString(Operation)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetMarker(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMarker";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Metadata", to_string_flags_, tab_count, tab_size, ToString(Metadata, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(Size, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Size", to_string_flags_, tab_count, tab_size, ToString(Size, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_BeginEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BeginEvent";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Metadata", to_string_flags_, tab_count, tab_size, ToString(Metadata, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(Size, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Size", to_string_flags_, tab_count, tab_size, ToString(Size, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_EndEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EndEvent";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ExecuteIndirect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pCommandSignature,
        UINT MaxCommandCount,
        format::HandleId pArgumentBuffer,
        UINT64 ArgumentBufferOffset,
        format::HandleId pCountBuffer,
        UINT64 CountBufferOffset)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ExecuteIndirect";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pCommandSignature", to_string_flags_, tab_count, tab_size, HandleIdToString(pCommandSignature));
            FieldToString(str_strm, false, "MaxCommandCount", to_string_flags_, tab_count, tab_size, ToString(MaxCommandCount, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pArgumentBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pArgumentBuffer));
            FieldToString(str_strm, false, "ArgumentBufferOffset", to_string_flags_, tab_count, tab_size, ToString(ArgumentBufferOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pCountBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pCountBuffer));
            FieldToString(str_strm, false, "CountBufferOffset", to_string_flags_, tab_count, tab_size, ToString(CountBufferOffset, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AtomicCopyBufferUINT";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstBuffer));
            FieldToString(str_strm, false, "DstOffset", to_string_flags_, tab_count, tab_size, ToString(DstOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcBuffer));
            FieldToString(str_strm, false, "SrcOffset", to_string_flags_, tab_count, tab_size, ToString(SrcOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Dependencies", to_string_flags_, tab_count, tab_size, ToString(Dependencies, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppDependentResources", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(Dependencies, ppDependentResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDependentSubresourceRanges", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(Dependencies, pDependentSubresourceRanges, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AtomicCopyBufferUINT64";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstBuffer));
            FieldToString(str_strm, false, "DstOffset", to_string_flags_, tab_count, tab_size, ToString(DstOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcBuffer", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcBuffer));
            FieldToString(str_strm, false, "SrcOffset", to_string_flags_, tab_count, tab_size, ToString(SrcOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Dependencies", to_string_flags_, tab_count, tab_size, ToString(Dependencies, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppDependentResources", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(Dependencies, ppDependentResources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDependentSubresourceRanges", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(Dependencies, pDependentSubresourceRanges, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_OMSetDepthBounds(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        FLOAT Min,
        FLOAT Max)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OMSetDepthBounds";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Min", to_string_flags_, tab_count, tab_size, ToString(Min, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Max", to_string_flags_, tab_count, tab_size, ToString(Max, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_SetSamplePositions(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumSamplesPerPixel,
        UINT NumPixels,
        StructPointerDecoder<Decoded_D3D12_SAMPLE_POSITION>* pSamplePositions)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetSamplePositions";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumSamplesPerPixel", to_string_flags_, tab_count, tab_size, ToString(NumSamplesPerPixel, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumPixels", to_string_flags_, tab_count, tab_size, ToString(NumPixels, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSamplePositions", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumSamplesPerPixel * NumPixels, pSamplePositions, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResolveSubresourceRegion";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstResource));
            FieldToString(str_strm, false, "DstSubresource", to_string_flags_, tab_count, tab_size, ToString(DstSubresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DstX", to_string_flags_, tab_count, tab_size, ToString(DstX, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DstY", to_string_flags_, tab_count, tab_size, ToString(DstY, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcResource));
            FieldToString(str_strm, false, "SrcSubresource", to_string_flags_, tab_count, tab_size, ToString(SrcSubresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcRect", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pSrcRect, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Format", to_string_flags_, tab_count, tab_size, Quote(ToString(Format)));
            FieldToString(str_strm, false, "ResolveMode", to_string_flags_, tab_count, tab_size, Quote(ToString(ResolveMode)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_SetViewInstanceMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Mask)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetViewInstanceMask";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Mask", to_string_flags_, tab_count, tab_size, ToString(Mask, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList2_WriteBufferImmediate(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Count,
        StructPointerDecoder<Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>* pParams,
        PointerDecoder<D3D12_WRITEBUFFERIMMEDIATE_MODE>* pModes)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "WriteBufferImmediate";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Count", to_string_flags_, tab_count, tab_size, ToString(Count, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pParams", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(Count, pParams, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pModes", to_string_flags_, tab_count, tab_size, EnumPointerDecoderArrayToString(Count, pModes, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_UpdateTileMappings(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UpdateTileMappings";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "NumResourceRegions", to_string_flags_, tab_count, tab_size, ToString(NumResourceRegions, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pResourceRegionStartCoordinates", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumResourceRegions, pResourceRegionStartCoordinates, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pResourceRegionSizes", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumResourceRegions, pResourceRegionSizes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pHeap", to_string_flags_, tab_count, tab_size, HandleIdToString(pHeap));
            FieldToString(str_strm, false, "NumRanges", to_string_flags_, tab_count, tab_size, ToString(NumRanges, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRangeFlags", to_string_flags_, tab_count, tab_size, EnumPointerDecoderArrayToString(NumRanges, pRangeFlags, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pHeapRangeStartOffsets", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumRanges, pHeapRangeStartOffsets, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRangeTileCounts", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumRanges, pRangeTileCounts, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_CopyTileMappings(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pDstRegionStartCoordinate,
        format::HandleId pSrcResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pSrcRegionStartCoordinate,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pRegionSize,
        D3D12_TILE_MAPPING_FLAGS Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyTileMappings";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDstResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstResource));
            FieldToString(str_strm, false, "pDstRegionStartCoordinate", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDstRegionStartCoordinate, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcResource));
            FieldToString(str_strm, false, "pSrcRegionStartCoordinate", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pSrcRegionStartCoordinate, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRegionSize", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pRegionSize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_ExecuteCommandLists(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumCommandLists,
        HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ExecuteCommandLists";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumCommandLists", to_string_flags_, tab_count, tab_size, ToString(NumCommandLists, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppCommandLists", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumCommandLists, ppCommandLists, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_SetMarker(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMarker";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Metadata", to_string_flags_, tab_count, tab_size, ToString(Metadata, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(Size, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Size", to_string_flags_, tab_count, tab_size, ToString(Size, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_BeginEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BeginEvent";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Metadata", to_string_flags_, tab_count, tab_size, ToString(Metadata, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(Size, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Size", to_string_flags_, tab_count, tab_size, ToString(Size, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_EndEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EndEvent";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_Signal(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pFence,
        UINT64 Value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Signal";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFence", to_string_flags_, tab_count, tab_size, HandleIdToString(pFence));
            FieldToString(str_strm, false, "Value", to_string_flags_, tab_count, tab_size, ToString(Value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_Wait(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pFence,
        UINT64 Value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Wait";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFence", to_string_flags_, tab_count, tab_size, HandleIdToString(pFence));
            FieldToString(str_strm, false, "Value", to_string_flags_, tab_count, tab_size, ToString(Value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetTimestampFrequency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT64>* pFrequency)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetTimestampFrequency";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pFrequency", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pFrequency, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetClockCalibration(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT64>* pGpuTimestamp,
        PointerDecoder<UINT64>* pCpuTimestamp)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetClockCalibration";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pGpuTimestamp", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pGpuTimestamp, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pCpuTimestamp", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pCpuTimestamp, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetNodeCount(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNodeCount";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandQueue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandQueue)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandQueue";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppCommandQueue", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppCommandQueue));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandAllocator(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_COMMAND_LIST_TYPE type,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandAllocator)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandAllocator";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "type", to_string_flags_, tab_count, tab_size, Quote(ToString(type)));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppCommandAllocator", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppCommandAllocator));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateGraphicsPipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateGraphicsPipelineState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateComputePipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateComputePipelineState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandList(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandList";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "nodeMask", to_string_flags_, tab_count, tab_size, ToString(nodeMask, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "type", to_string_flags_, tab_count, tab_size, Quote(ToString(type)));
            FieldToString(str_strm, false, "pCommandAllocator", to_string_flags_, tab_count, tab_size, HandleIdToString(pCommandAllocator));
            FieldToString(str_strm, false, "pInitialState", to_string_flags_, tab_count, tab_size, HandleIdToString(pInitialState));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppCommandList", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppCommandList));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateDescriptorHeap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateDescriptorHeap";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDescriptorHeapDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDescriptorHeapDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetDescriptorHandleIncrementSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDescriptorHandleIncrementSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DescriptorHeapType", to_string_flags_, tab_count, tab_size, Quote(ToString(DescriptorHeapType)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateConstantBufferView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateConstantBufferView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags_, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateShaderResourceView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateShaderResourceView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags_, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        format::HandleId pCounterResource,
        StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateUnorderedAccessView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "pCounterResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pCounterResource));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags_, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateRenderTargetView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateRenderTargetView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags_, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateDepthStencilView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateDepthStencilView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags_, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateSampler(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSampler";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags_, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CopyDescriptors(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyDescriptors";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumDestDescriptorRanges", to_string_flags_, tab_count, tab_size, ToString(NumDestDescriptorRanges, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDestDescriptorRangeStarts", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumDestDescriptorRanges, pDestDescriptorRangeStarts, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDestDescriptorRangeSizes", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumDestDescriptorRanges, pDestDescriptorRangeSizes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumSrcDescriptorRanges", to_string_flags_, tab_count, tab_size, ToString(NumSrcDescriptorRanges, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcDescriptorRangeStarts", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumSrcDescriptorRanges, pSrcDescriptorRangeStarts, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSrcDescriptorRangeSizes", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumSrcDescriptorRanges, pSrcDescriptorRangeSizes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DescriptorHeapsType", to_string_flags_, tab_count, tab_size, Quote(ToString(DescriptorHeapsType)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CopyDescriptorsSimple(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumDescriptors,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyDescriptorsSimple";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumDescriptors", to_string_flags_, tab_count, tab_size, ToString(NumDescriptors, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptorRangeStart", to_string_flags_, tab_count, tab_size, ToString(*DestDescriptorRangeStart.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcDescriptorRangeStart", to_string_flags_, tab_count, tab_size, ToString(*SrcDescriptorRangeStart.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DescriptorHeapsType", to_string_flags_, tab_count, tab_size, Quote(ToString(DescriptorHeapsType)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommittedResource(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommittedResource";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeapProperties", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pHeapProperties, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "HeapFlags", to_string_flags_, tab_count, tab_size, Quote(ToString(HeapFlags)));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialResourceState", to_string_flags_, tab_count, tab_size, Quote(ToString(InitialResourceState)));
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOptimizedClearValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riidResource", to_string_flags_, tab_count, tab_size, ToString(*riidResource.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateHeap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateHeap";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreatePlacedResource(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreatePlacedResource";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeap", to_string_flags_, tab_count, tab_size, HandleIdToString(pHeap));
            FieldToString(str_strm, false, "HeapOffset", to_string_flags_, tab_count, tab_size, ToString(HeapOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialState", to_string_flags_, tab_count, tab_size, Quote(ToString(InitialState)));
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOptimizedClearValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateReservedResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateReservedResource";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialState", to_string_flags_, tab_count, tab_size, Quote(ToString(InitialState)));
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOptimizedClearValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pObject,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD Access,
        WStringDecoder* Name,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSharedHandle";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pObject", to_string_flags_, tab_count, tab_size, HandleIdToString(pObject));
            FieldToString(str_strm, false, "pAttributes", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pAttributes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Access", to_string_flags_, tab_count, tab_size, ToString(Access, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Name", to_string_flags_, tab_count, tab_size, StringDecoderToString(Name));
            FieldToString(str_strm, false, "[out]pHandle", to_string_flags_, tab_count, tab_size, HandleIdToString(pHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_OpenSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t NTHandle,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObj)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OpenSharedHandle";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NTHandle", to_string_flags_, tab_count, tab_size, HandleIdToString(NTHandle));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvObj", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvObj));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_OpenSharedHandleByName(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* Name,
        DWORD Access,
        PointerDecoder<uint64_t, void*>* pNTHandle)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OpenSharedHandleByName";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Name", to_string_flags_, tab_count, tab_size, StringDecoderToString(Name));
            FieldToString(str_strm, false, "Access", to_string_flags_, tab_count, tab_size, ToString(Access, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pNTHandle", to_string_flags_, tab_count, tab_size, HandleIdToString(pNTHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_MakeResident(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "MakeResident";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumObjects", to_string_flags_, tab_count, tab_size, ToString(NumObjects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppObjects", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumObjects, ppObjects, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_Evict(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Evict";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumObjects", to_string_flags_, tab_count, tab_size, ToString(NumObjects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppObjects", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumObjects, ppObjects, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateFence(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 InitialValue,
        D3D12_FENCE_FLAGS Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateFence";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "InitialValue", to_string_flags_, tab_count, tab_size, ToString(InitialValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppFence", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppFence));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetDeviceRemovedReason(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDeviceRemovedReason";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetCopyableFootprints(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCopyableFootprints";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResourceDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pResourceDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "FirstSubresource", to_string_flags_, tab_count, tab_size, ToString(FirstSubresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumSubresources", to_string_flags_, tab_count, tab_size, ToString(NumSubresources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BaseOffset", to_string_flags_, tab_count, tab_size, ToString(BaseOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pLayouts", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumSubresources, pLayouts, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pNumRows", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumSubresources, pNumRows, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pRowSizeInBytes", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumSubresources, pRowSizeInBytes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pTotalBytes", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pTotalBytes, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateQueryHeap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_QUERY_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateQueryHeap";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_SetStablePowerState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetStablePowerState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags_, tab_count, tab_size, ToString(Enable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC>* pDesc,
        format::HandleId pRootSignature,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvCommandSignature)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandSignature";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRootSignature", to_string_flags_, tab_count, tab_size, HandleIdToString(pRootSignature));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvCommandSignature", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvCommandSignature));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetResourceTiling(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetResourceTiling";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pTiledResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pTiledResource));
            FieldToString(str_strm, false, "[out]pNumTilesForEntireResource", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pNumTilesForEntireResource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pPackedMipDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pPackedMipDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pStandardTileShapeForNonPackedMips", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pStandardTileShapeForNonPackedMips, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pNumSubresourceTilings", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pNumSubresourceTilings, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "FirstSubresourceTilingToGet", to_string_flags_, tab_count, tab_size, ToString(FirstSubresourceTilingToGet, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pSubresourceTilingsForNonPackedMips", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(pNumSubresourceTilings, pSubresourceTilingsForNonPackedMips, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_StorePipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        format::HandleId pPipeline)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "StorePipeline";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pName", to_string_flags_, tab_count, tab_size, StringDecoderToString(pName));
            FieldToString(str_strm, false, "pPipeline", to_string_flags_, tab_count, tab_size, HandleIdToString(pPipeline));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_LoadGraphicsPipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "LoadGraphicsPipeline";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pName", to_string_flags_, tab_count, tab_size, StringDecoderToString(pName));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_LoadComputePipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "LoadComputePipeline";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pName", to_string_flags_, tab_count, tab_size, StringDecoderToString(pName));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_GetSerializedSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        SIZE_T return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSerializedSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_Serialize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pData,
        SIZE_T DataSizeInBytes)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Serialize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSizeInBytes, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSizeInBytes", to_string_flags_, tab_count, tab_size, ToString(DataSizeInBytes, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary1_LoadPipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12PipelineLibrary1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "LoadPipeline";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pName", to_string_flags_, tab_count, tab_size, StringDecoderToString(pName));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device1_SetEventOnMultipleFenceCompletion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<ID3D12Fence*>* ppFences,
        PointerDecoder<UINT64>* pFenceValues,
        UINT NumFences,
        D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
        uint64_t hEvent)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEventOnMultipleFenceCompletion";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ppFences", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumFences, ppFences, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pFenceValues", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumFences, pFenceValues, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumFences", to_string_flags_, tab_count, tab_size, ToString(NumFences, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
            FieldToString(str_strm, false, "hEvent", to_string_flags_, tab_count, tab_size, HandleIdToString(hEvent));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device1_SetResidencyPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        PointerDecoder<D3D12_RESIDENCY_PRIORITY>* pPriorities)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetResidencyPriority";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumObjects", to_string_flags_, tab_count, tab_size, ToString(NumObjects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppObjects", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumObjects, ppObjects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pPriorities", to_string_flags_, tab_count, tab_size, EnumPointerDecoderArrayToString(NumObjects, pPriorities, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device2_CreatePipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreatePipelineState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineState", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppPipelineState));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device3_OpenExistingHeapFromAddress(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t pAddress,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OpenExistingHeapFromAddress";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pAddress", to_string_flags_, tab_count, tab_size, HandleIdToString(pAddress));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device3_OpenExistingHeapFromFileMapping(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hFileMapping,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OpenExistingHeapFromFileMapping";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "hFileMapping", to_string_flags_, tab_count, tab_size, HandleIdToString(hFileMapping));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device3_EnqueueMakeResident(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RESIDENCY_FLAGS Flags,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        format::HandleId pFenceToSignal,
        UINT64 FenceValueToSignal)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnqueueMakeResident";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
            FieldToString(str_strm, false, "NumObjects", to_string_flags_, tab_count, tab_size, ToString(NumObjects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ppObjects", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumObjects, ppObjects, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pFenceToSignal", to_string_flags_, tab_count, tab_size, HandleIdToString(pFenceToSignal));
            FieldToString(str_strm, false, "FenceValueToSignal", to_string_flags_, tab_count, tab_size, ToString(FenceValueToSignal, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ProtectedSession_GetStatusFence(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ProtectedSession";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetStatusFence";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppFence", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppFence));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ProtectedSession_GetSessionStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_PROTECTED_SESSION_STATUS return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ProtectedSession";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSessionStatus";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_CreateCommandList1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        D3D12_COMMAND_LIST_FLAGS flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandList)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandList1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "nodeMask", to_string_flags_, tab_count, tab_size, ToString(nodeMask, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "type", to_string_flags_, tab_count, tab_size, Quote(ToString(type)));
            FieldToString(str_strm, false, "flags", to_string_flags_, tab_count, tab_size, Quote(ToString(flags)));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppCommandList", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppCommandList));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_CreateProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateProtectedResourceSession";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSession", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_CreateCommittedResource1(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommittedResource1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeapProperties", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pHeapProperties, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "HeapFlags", to_string_flags_, tab_count, tab_size, Quote(ToString(HeapFlags)));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialResourceState", to_string_flags_, tab_count, tab_size, Quote(ToString(InitialResourceState)));
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOptimizedClearValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pProtectedSession", to_string_flags_, tab_count, tab_size, HandleIdToString(pProtectedSession));
            FieldToString(str_strm, false, "riidResource", to_string_flags_, tab_count, tab_size, ToString(*riidResource.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_CreateHeap1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        format::HandleId pProtectedSession,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateHeap1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pProtectedSession", to_string_flags_, tab_count, tab_size, HandleIdToString(pProtectedSession));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvHeap", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvHeap));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_CreateReservedResource1(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateReservedResource1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialState", to_string_flags_, tab_count, tab_size, Quote(ToString(InitialState)));
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOptimizedClearValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pProtectedSession", to_string_flags_, tab_count, tab_size, HandleIdToString(pProtectedSession));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12LifetimeOwner_LifetimeStateUpdated(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_LIFETIME_STATE NewState)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12LifetimeOwner";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "LifetimeStateUpdated";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NewState", to_string_flags_, tab_count, tab_size, Quote(ToString(NewState)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetLUID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_LUID return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SwapChainAssistant";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetLUID";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetSwapChainObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppv)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SwapChainAssistant";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetSwapChainObject";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppv", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppv));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource,
        Decoded_GUID riidQueue,
        HandlePointerDecoder<void*>* ppvQueue)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SwapChainAssistant";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCurrentResourceAndCommandQueue";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riidResource", to_string_flags_, tab_count, tab_size, ToString(*riidResource.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
            FieldToString(str_strm, false, "riidQueue", to_string_flags_, tab_count, tab_size, ToString(*riidQueue.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvQueue", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvQueue));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_InsertImplicitSync(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SwapChainAssistant";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "InsertImplicitSync";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12LifetimeTracker_DestroyOwnedObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pObject)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12LifetimeTracker";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DestroyOwnedObject";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pObject", to_string_flags_, tab_count, tab_size, HandleIdToString(pObject));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetShaderIdentifier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        PointerDecoder<uint8_t>* return_value,
        WStringDecoder* pExportName)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12StateObjectProperties";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetShaderIdentifier";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pExportName", to_string_flags_, tab_count, tab_size, StringDecoderToString(pExportName));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetShaderStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value,
        WStringDecoder* pExportName)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12StateObjectProperties";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetShaderStackSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pExportName", to_string_flags_, tab_count, tab_size, StringDecoderToString(pExportName));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetPipelineStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12StateObjectProperties";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPipelineStackSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_SetPipelineStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 PipelineStackSizeInBytes)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12StateObjectProperties";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPipelineStackSize";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "PipelineStackSizeInBytes", to_string_flags_, tab_count, tab_size, ToString(PipelineStackSizeInBytes, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_CreateLifetimeTracker(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pOwner,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvTracker)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateLifetimeTracker";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pOwner", to_string_flags_, tab_count, tab_size, HandleIdToString(pOwner));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvTracker", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvTracker));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_RemoveDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RemoveDevice";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_EnumerateMetaCommands(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pNumMetaCommands,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_DESC>* pDescs)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumerateMetaCommands";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pNumMetaCommands", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pNumMetaCommands, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pDescs", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(pNumMetaCommands, pDescs, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_EnumerateMetaCommandParameters(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID CommandId,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        PointerDecoder<UINT>* pTotalStructureSizeInBytes,
        PointerDecoder<UINT>* pParameterCount,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_PARAMETER_DESC>* pParameterDescs)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnumerateMetaCommandParameters";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "CommandId", to_string_flags_, tab_count, tab_size, ToString(*CommandId.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Stage", to_string_flags_, tab_count, tab_size, Quote(ToString(Stage)));
            FieldToString(str_strm, false, "[out]pTotalStructureSizeInBytes", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pTotalStructureSizeInBytes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pParameterCount", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pParameterCount, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pParameterDescs", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(pParameterCount, pParameterDescs, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_CreateMetaCommand(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateMetaCommand";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "CommandId", to_string_flags_, tab_count, tab_size, ToString(*CommandId.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NodeMask", to_string_flags_, tab_count, tab_size, ToString(NodeMask, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pCreationParametersData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(CreationParametersDataSizeInBytes, pCreationParametersData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "CreationParametersDataSizeInBytes", to_string_flags_, tab_count, tab_size, ToString(CreationParametersDataSizeInBytes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppMetaCommand", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppMetaCommand));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_CreateStateObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppStateObject)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateStateObject";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppStateObject", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppStateObject));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>* pDesc,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>* pInfo)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRaytracingAccelerationStructurePrebuildInfo";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pInfo", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pInfo, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device5_CheckDriverMatchingIdentifier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS return_value,
        D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
        StructPointerDecoder<Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>* pIdentifierToCheck)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckDriverMatchingIdentifier";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "SerializedDataType", to_string_flags_, tab_count, tab_size, Quote(ToString(SerializedDataType)));
            FieldToString(str_strm, false, "pIdentifierToCheck", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pIdentifierToCheck, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedDataSettings";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetAutoBreadcrumbsEnablement";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enablement", to_string_flags_, tab_count, tab_size, Quote(ToString(Enablement)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedDataSettings";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPageFaultEnablement";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enablement", to_string_flags_, tab_count, tab_size, Quote(ToString(Enablement)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedDataSettings";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetWatsonDumpEnablement";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enablement", to_string_flags_, tab_count, tab_size, Quote(ToString(Enablement)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedDataSettings1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBreadcrumbContextEnablement";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enablement", to_string_flags_, tab_count, tab_size, Quote(ToString(Enablement)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL MarkersOnly)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedDataSettings2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UseMarkersOnlyAutoBreadcrumbs";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "MarkersOnly", to_string_flags_, tab_count, tab_size, ToString(MarkersOnly, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* pOutput)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedData";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetAutoBreadcrumbsOutput";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pOutput", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOutput, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>* pOutput)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedData";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPageFaultAllocationOutput";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pOutput", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOutput, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* pOutput)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedData1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetAutoBreadcrumbsOutput1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pOutput", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOutput, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* pOutput)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedData1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPageFaultAllocationOutput1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pOutput", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOutput, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2>* pOutput)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedData2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetPageFaultAllocationOutput2";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pOutput", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOutput, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData2_GetDeviceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_DEVICE_STATE return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceRemovedExtendedData2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDeviceState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device6_SetBackgroundProcessingMode(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_BACKGROUND_PROCESSING_MODE Mode,
        D3D12_MEASUREMENTS_ACTION MeasurementsAction,
        uint64_t hEventToSignalUponCompletion,
        PointerDecoder<BOOL>* pbFurtherMeasurementsDesired)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBackgroundProcessingMode";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Mode", to_string_flags_, tab_count, tab_size, Quote(ToString(Mode)));
            FieldToString(str_strm, false, "MeasurementsAction", to_string_flags_, tab_count, tab_size, Quote(ToString(MeasurementsAction)));
            FieldToString(str_strm, false, "hEventToSignalUponCompletion", to_string_flags_, tab_count, tab_size, HandleIdToString(hEventToSignalUponCompletion));
            FieldToString(str_strm, false, "[out]pbFurtherMeasurementsDesired", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pbFurtherMeasurementsDesired, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ProtectedResourceSession1_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ProtectedResourceSession1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device7_AddToStateObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pAddition,
        format::HandleId pStateObjectToGrowFrom,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppNewStateObject)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device7";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddToStateObject";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pAddition", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pAddition, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pStateObjectToGrowFrom", to_string_flags_, tab_count, tab_size, HandleIdToString(pStateObjectToGrowFrom));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppNewStateObject", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppNewStateObject));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device7_CreateProtectedResourceSession1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device7";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateProtectedResourceSession1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppSession", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device8_GetResourceAllocationInfo2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetResourceAllocationInfo2";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "visibleMask", to_string_flags_, tab_count, tab_size, ToString(visibleMask, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "numResourceDescs", to_string_flags_, tab_count, tab_size, ToString(numResourceDescs, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pResourceDescs", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(numResourceDescs, pResourceDescs, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pResourceAllocationInfo1", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(numResourceDescs, pResourceAllocationInfo1, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device8_CreateCommittedResource2(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommittedResource2";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeapProperties", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pHeapProperties, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "HeapFlags", to_string_flags_, tab_count, tab_size, Quote(ToString(HeapFlags)));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialResourceState", to_string_flags_, tab_count, tab_size, Quote(ToString(InitialResourceState)));
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOptimizedClearValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pProtectedSession", to_string_flags_, tab_count, tab_size, HandleIdToString(pProtectedSession));
            FieldToString(str_strm, false, "riidResource", to_string_flags_, tab_count, tab_size, ToString(*riidResource.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device8_CreatePlacedResource1(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreatePlacedResource1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeap", to_string_flags_, tab_count, tab_size, HandleIdToString(pHeap));
            FieldToString(str_strm, false, "HeapOffset", to_string_flags_, tab_count, tab_size, ToString(HeapOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialState", to_string_flags_, tab_count, tab_size, Quote(ToString(InitialState)));
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOptimizedClearValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pTargetedResource,
        format::HandleId pFeedbackResource,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSamplerFeedbackUnorderedAccessView";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pTargetedResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pTargetedResource));
            FieldToString(str_strm, false, "pFeedbackResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pFeedbackResource));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags_, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device8_GetCopyableFootprints1(
        const ApiCallInfo& call_info,
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
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCopyableFootprints1";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResourceDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pResourceDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "FirstSubresource", to_string_flags_, tab_count, tab_size, ToString(FirstSubresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumSubresources", to_string_flags_, tab_count, tab_size, ToString(NumSubresources, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BaseOffset", to_string_flags_, tab_count, tab_size, ToString(BaseOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pLayouts", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumSubresources, pLayouts, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pNumRows", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumSubresources, pNumRows, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pRowSizeInBytes", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumSubresources, pRowSizeInBytes, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pTotalBytes", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pTotalBytes, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource1_GetProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetProtectedResourceSession";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppProtectedSession", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppProtectedSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource2_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC1 return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc1";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Heap1_GetProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Heap1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetProtectedResourceSession";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppProtectedSession", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppProtectedSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pProtectedResourceSession)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetProtectedResourceSession";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pProtectedResourceSession", to_string_flags_, tab_count, tab_size, HandleIdToString(pProtectedResourceSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12MetaCommand_GetRequiredParameterResourceSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        UINT ParameterIndex)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12MetaCommand";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRequiredParameterResourceSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Stage", to_string_flags_, tab_count, tab_size, Quote(ToString(Stage)));
            FieldToString(str_strm, false, "ParameterIndex", to_string_flags_, tab_count, tab_size, ToString(ParameterIndex, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_BeginRenderPass(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BeginRenderPass";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumRenderTargets", to_string_flags_, tab_count, tab_size, ToString(NumRenderTargets, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pRenderTargets", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumRenderTargets, pRenderTargets, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDepthStencil", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDepthStencil, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_EndRenderPass(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EndRenderPass";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pMetaCommand,
        PointerDecoder<uint8_t>* pInitializationParametersData,
        SIZE_T InitializationParametersDataSizeInBytes)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "InitializeMetaCommand";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pMetaCommand", to_string_flags_, tab_count, tab_size, HandleIdToString(pMetaCommand));
            FieldToString(str_strm, false, "pInitializationParametersData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(InitializationParametersDataSizeInBytes, pInitializationParametersData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitializationParametersDataSizeInBytes", to_string_flags_, tab_count, tab_size, ToString(InitializationParametersDataSizeInBytes, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pMetaCommand,
        PointerDecoder<uint8_t>* pExecutionParametersData,
        SIZE_T ExecutionParametersDataSizeInBytes)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ExecuteMetaCommand";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pMetaCommand", to_string_flags_, tab_count, tab_size, HandleIdToString(pMetaCommand));
            FieldToString(str_strm, false, "pExecutionParametersData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(ExecutionParametersDataSizeInBytes, pExecutionParametersData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ExecutionParametersDataSizeInBytes", to_string_flags_, tab_count, tab_size, ToString(ExecutionParametersDataSizeInBytes, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* pDesc,
        UINT NumPostbuildInfoDescs,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pPostbuildInfoDescs)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BuildRaytracingAccelerationStructure";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumPostbuildInfoDescs", to_string_flags_, tab_count, tab_size, ToString(NumPostbuildInfoDescs, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pPostbuildInfoDescs", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumPostbuildInfoDescs, pPostbuildInfoDescs, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pDesc,
        UINT NumSourceAccelerationStructures,
        PointerDecoder<D3D12_GPU_VIRTUAL_ADDRESS>* pSourceAccelerationStructureData)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EmitRaytracingAccelerationStructurePostbuildInfo";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumSourceAccelerationStructures", to_string_flags_, tab_count, tab_size, ToString(NumSourceAccelerationStructures, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pSourceAccelerationStructureData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumSourceAccelerationStructures, pSourceAccelerationStructureData, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
        D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CopyRaytracingAccelerationStructure";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "DestAccelerationStructureData", to_string_flags_, tab_count, tab_size, ToString(DestAccelerationStructureData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "SourceAccelerationStructureData", to_string_flags_, tab_count, tab_size, ToString(SourceAccelerationStructureData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Mode", to_string_flags_, tab_count, tab_size, Quote(ToString(Mode)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_SetPipelineState1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pStateObject)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetPipelineState1";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pStateObject", to_string_flags_, tab_count, tab_size, HandleIdToString(pStateObject));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_DispatchRays(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* pDesc)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DispatchRays";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ShaderCacheSession_FindValue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pKey,
        UINT KeySize,
        PointerDecoder<uint8_t>* pValue,
        PointerDecoder<UINT>* pValueSize)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ShaderCacheSession";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "FindValue";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pKey", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(KeySize, pKey, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "KeySize", to_string_flags_, tab_count, tab_size, ToString(KeySize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pValue", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(pValueSize, pValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pValueSize", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pValueSize, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ShaderCacheSession_StoreValue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pKey,
        UINT KeySize,
        PointerDecoder<uint8_t>* pValue,
        UINT ValueSize)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ShaderCacheSession";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "StoreValue";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pKey", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(KeySize, pKey, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "KeySize", to_string_flags_, tab_count, tab_size, ToString(KeySize, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pValue", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(ValueSize, pValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ValueSize", to_string_flags_, tab_count, tab_size, ToString(ValueSize, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ShaderCacheSession_SetDeleteOnDestroy(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ShaderCacheSession";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDeleteOnDestroy";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ShaderCacheSession_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_SHADER_CACHE_SESSION_DESC return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ShaderCacheSession";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device9_CreateShaderCacheSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_SHADER_CACHE_SESSION_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvSession)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device9";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateShaderCacheSession";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvSession", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvSession));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device9_ShaderCacheControl(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_SHADER_CACHE_KIND_FLAGS Kinds,
        D3D12_SHADER_CACHE_CONTROL_FLAGS Control)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device9";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ShaderCacheControl";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Kinds", to_string_flags_, tab_count, tab_size, Quote(ToString(Kinds)));
            FieldToString(str_strm, false, "Control", to_string_flags_, tab_count, tab_size, Quote(ToString(Control)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device9_CreateCommandQueue1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
        Decoded_GUID CreatorID,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandQueue)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device9";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommandQueue1";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "CreatorID", to_string_flags_, tab_count, tab_size, ToString(*CreatorID.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppCommandQueue", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppCommandQueue));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device10_CreateCommittedResource3(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
        D3D12_BARRIER_LAYOUT InitialLayout,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        format::HandleId pProtectedSession,
        UINT32 NumCastableFormats,
        PointerDecoder<DXGI_FORMAT>* pCastableFormats,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device10";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateCommittedResource3";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeapProperties", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pHeapProperties, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "HeapFlags", to_string_flags_, tab_count, tab_size, Quote(ToString(HeapFlags)));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialLayout", to_string_flags_, tab_count, tab_size, Quote(ToString(InitialLayout)));
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOptimizedClearValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pProtectedSession", to_string_flags_, tab_count, tab_size, HandleIdToString(pProtectedSession));
            FieldToString(str_strm, false, "NumCastableFormats", to_string_flags_, tab_count, tab_size, ToString(NumCastableFormats, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pCastableFormats", to_string_flags_, tab_count, tab_size, EnumPointerDecoderArrayToString(NumCastableFormats, pCastableFormats, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riidResource", to_string_flags_, tab_count, tab_size, ToString(*riidResource.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device10_CreatePlacedResource2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pHeap,
        UINT64 HeapOffset,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
        D3D12_BARRIER_LAYOUT InitialLayout,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        UINT32 NumCastableFormats,
        PointerDecoder<DXGI_FORMAT>* pCastableFormats,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device10";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreatePlacedResource2";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pHeap", to_string_flags_, tab_count, tab_size, HandleIdToString(pHeap));
            FieldToString(str_strm, false, "HeapOffset", to_string_flags_, tab_count, tab_size, ToString(HeapOffset, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialLayout", to_string_flags_, tab_count, tab_size, Quote(ToString(InitialLayout)));
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOptimizedClearValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumCastableFormats", to_string_flags_, tab_count, tab_size, ToString(NumCastableFormats, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pCastableFormats", to_string_flags_, tab_count, tab_size, EnumPointerDecoderArrayToString(NumCastableFormats, pCastableFormats, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device10_CreateReservedResource2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_BARRIER_LAYOUT InitialLayout,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        format::HandleId pProtectedSession,
        UINT32 NumCastableFormats,
        PointerDecoder<DXGI_FORMAT>* pCastableFormats,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device10";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateReservedResource2";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "InitialLayout", to_string_flags_, tab_count, tab_size, Quote(ToString(InitialLayout)));
            FieldToString(str_strm, false, "pOptimizedClearValue", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pOptimizedClearValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pProtectedSession", to_string_flags_, tab_count, tab_size, HandleIdToString(pProtectedSession));
            FieldToString(str_strm, false, "NumCastableFormats", to_string_flags_, tab_count, tab_size, ToString(NumCastableFormats, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pCastableFormats", to_string_flags_, tab_count, tab_size, EnumPointerDecoderArrayToString(NumCastableFormats, pCastableFormats, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvResource", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvResource));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device11_CreateSampler2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC2>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device11";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateSampler2";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DestDescriptor", to_string_flags_, tab_count, tab_size, ToString(*DestDescriptor.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12VirtualizationGuestDevice_ShareWithHost(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pObject,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12VirtualizationGuestDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ShareWithHost";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pObject", to_string_flags_, tab_count, tab_size, HandleIdToString(pObject));
            FieldToString(str_strm, false, "[out]pHandle", to_string_flags_, tab_count, tab_size, HandleIdToString(pHandle));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12VirtualizationGuestDevice_CreateFenceFd(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pFence,
        UINT64 FenceValue,
        PointerDecoder<int>* pFenceFd)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12VirtualizationGuestDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateFenceFd";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFence", to_string_flags_, tab_count, tab_size, HandleIdToString(pFence));
            FieldToString(str_strm, false, "FenceValue", to_string_flags_, tab_count, tab_size, ToString(FenceValue, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pFenceFd", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pFenceFd, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Tools_EnableShaderInstrumentation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL bEnable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Tools";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnableShaderInstrumentation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "bEnable", to_string_flags_, tab_count, tab_size, ToString(bEnable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Tools_ShaderInstrumentationEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Tools";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ShaderInstrumentationEnabled";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SDKConfiguration_SetSDKVersion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT SDKVersion,
        StringDecoder* SDKPath)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SDKConfiguration";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetSDKVersion";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "SDKVersion", to_string_flags_, tab_count, tab_size, ToString(SDKVersion, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "SDKPath", to_string_flags_, tab_count, tab_size, StringDecoderToString(SDKPath));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SDKConfiguration1_CreateDeviceFactory(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT SDKVersion,
        StringDecoder* SDKPath,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvFactory)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SDKConfiguration1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateDeviceFactory";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "SDKVersion", to_string_flags_, tab_count, tab_size, ToString(SDKVersion, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "SDKPath", to_string_flags_, tab_count, tab_size, StringDecoderToString(SDKPath));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvFactory", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvFactory));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SDKConfiguration1_FreeUnusedSDKs(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SDKConfiguration1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "FreeUnusedSDKs";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceFactory_InitializeFromGlobalState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "InitializeFromGlobalState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceFactory_ApplyToGlobalState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ApplyToGlobalState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceFactory_SetFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEVICE_FACTORY_FLAGS flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetFlags";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "flags", to_string_flags_, tab_count, tab_size, Quote(ToString(flags)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceFactory_GetFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DEVICE_FACTORY_FLAGS return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFlags";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceFactory_GetConfigurationInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID clsid,
        Decoded_GUID iid,
        HandlePointerDecoder<void*>* ppv)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetConfigurationInterface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "clsid", to_string_flags_, tab_count, tab_size, ToString(*clsid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "iid", to_string_flags_, tab_count, tab_size, ToString(*iid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppv", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppv));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceFactory_EnableExperimentalFeatures(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumFeatures,
        StructPointerDecoder<Decoded_GUID>* pIIDs,
        PointerDecoder<uint8_t>* pConfigurationStructs,
        PointerDecoder<UINT>* pConfigurationStructSizes)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnableExperimentalFeatures";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumFeatures", to_string_flags_, tab_count, tab_size, ToString(NumFeatures, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pIIDs", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumFeatures, pIIDs, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pConfigurationStructs", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumFeatures, pConfigurationStructs, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pConfigurationStructSizes", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(NumFeatures, pConfigurationStructSizes, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceFactory_CreateDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId adapter,
        D3D_FEATURE_LEVEL FeatureLevel,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDevice)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceFactory";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateDevice";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "adapter", to_string_flags_, tab_count, tab_size, HandleIdToString(adapter));
            FieldToString(str_strm, false, "FeatureLevel", to_string_flags_, tab_count, tab_size, Quote(ToString(FeatureLevel)));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvDevice", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvDevice));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceConfiguration_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_DEVICE_CONFIGURATION_DESC return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceConfiguration";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    std::string returnValue = DX12ReturnValueToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_GUID>* pGuids,
        UINT NumGuids)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceConfiguration";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetEnabledExperimentalFeatures";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pGuids", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumGuids, pGuids, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "NumGuids", to_string_flags_, tab_count, tab_size, ToString(NumGuids, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceConfiguration_SerializeVersionedRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pDesc,
        HandlePointerDecoder<ID3D10Blob*>* ppResult,
        HandlePointerDecoder<ID3D10Blob*>* ppError)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceConfiguration";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SerializeVersionedRootSignature";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pDesc", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppResult", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppResult));
            FieldToString(str_strm, false, "[out]ppError", to_string_flags_, tab_count, tab_size, HandleIdToString(ppError));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pBlob,
        SIZE_T Size,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDeserializer)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DeviceConfiguration";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateVersionedRootSignatureDeserializer";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pBlob", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(Size, pBlob, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Size", to_string_flags_, tab_count, tab_size, ToString(Size, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvDeserializer", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvDeserializer));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRate(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_SHADING_RATE baseShadingRate,
        PointerDecoder<D3D12_SHADING_RATE_COMBINER>* combiners)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RSSetShadingRate";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "baseShadingRate", to_string_flags_, tab_count, tab_size, Quote(ToString(baseShadingRate)));
            FieldToString(str_strm, false, "combiners", to_string_flags_, tab_count, tab_size, EnumPointerDecoderArrayToString(D3D12_RS_SET_SHADING_RATE_COMBINER_COUNT, combiners, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId shadingRateImage)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RSSetShadingRateImage";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "shadingRateImage", to_string_flags_, tab_count, tab_size, HandleIdToString(shadingRateImage));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList6_DispatchMesh(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DispatchMesh";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ThreadGroupCountX", to_string_flags_, tab_count, tab_size, ToString(ThreadGroupCountX, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ThreadGroupCountY", to_string_flags_, tab_count, tab_size, ToString(ThreadGroupCountY, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "ThreadGroupCountZ", to_string_flags_, tab_count, tab_size, ToString(ThreadGroupCountZ, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList7_Barrier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT32 NumBarrierGroups,
        StructPointerDecoder<Decoded_D3D12_BARRIER_GROUP>* pBarrierGroups)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList7";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Barrier";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumBarrierGroups", to_string_flags_, tab_count, tab_size, ToString(NumBarrierGroups, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pBarrierGroups", to_string_flags_, tab_count, tab_size, StructPointerDecoderArrayToString(NumBarrierGroups, pBarrierGroups, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT FrontStencilRef,
        UINT BackStencilRef)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList8";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "OMSetFrontAndBackStencilRef";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "FrontStencilRef", to_string_flags_, tab_count, tab_size, ToString(FrontStencilRef, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "BackStencilRef", to_string_flags_, tab_count, tab_size, ToString(BackStencilRef, to_string_flags_, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12AsciiConsumer::Process_ID3D10Blob_GetBufferPointer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        uint64_t return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D10Blob";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBufferPointer";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D10Blob_GetBufferSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        SIZE_T return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D10Blob";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBufferSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3DDestructionNotifier_RegisterDestructionCallback(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t callbackFn,
        uint64_t pData,
        PointerDecoder<UINT>* pCallbackID)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3DDestructionNotifier";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterDestructionCallback";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "callbackFn", to_string_flags_, tab_count, tab_size, ToString(callbackFn, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, HandleIdToString(pData));
            FieldToString(str_strm, false, "[out]pCallbackID", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pCallbackID, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3DDestructionNotifier_UnregisterDestructionCallback(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT callbackID)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3DDestructionNotifier";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterDestructionCallback";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "callbackID", to_string_flags_, tab_count, tab_size, ToString(callbackID, to_string_flags_, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from d3d12sdklayers.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12AsciiConsumer::Process_ID3D12Debug_EnableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnableDebugLayer";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug1_EnableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EnableDebugLayer";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug1_SetEnableGPUBasedValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEnableGPUBasedValidation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags_, tab_count, tab_size, ToString(Enable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEnableSynchronizedCommandQueueValidation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags_, tab_count, tab_size, ToString(Enable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug2_SetGPUBasedValidationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGPUBasedValidationFlags";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug3_SetEnableGPUBasedValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEnableGPUBasedValidation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags_, tab_count, tab_size, ToString(Enable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEnableSynchronizedCommandQueueValidation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags_, tab_count, tab_size, ToString(Enable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug3_SetGPUBasedValidationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetGPUBasedValidationFlags";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug4_DisableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "DisableDebugLayer";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug5_SetEnableAutoName(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetEnableAutoName";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags_, tab_count, tab_size, ToString(Enable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Debug6_SetForceLegacyBarrierValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Debug6";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetForceLegacyBarrierValidation";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Enable", to_string_flags_, tab_count, tab_size, ToString(Enable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDebugParameter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags_, tab_count, tab_size, ToString(DataSize, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDebugParameter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "[out]pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags_, tab_count, tab_size, ToString(DataSize, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_ReportLiveDeviceObjects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RLDO_FLAGS Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReportLiveDeviceObjects";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice_SetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_FEATURE Mask)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetFeatureMask";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Mask", to_string_flags_, tab_count, tab_size, Quote(ToString(Mask)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice_GetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DEBUG_FEATURE return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFeatureMask";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice_ReportLiveDeviceObjects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RLDO_FLAGS Flags)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ReportLiveDeviceObjects";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Flags", to_string_flags_, tab_count, tab_size, Quote(ToString(Flags)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice2_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDebugParameter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags_, tab_count, tab_size, ToString(DataSize, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugDevice2_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugDevice2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDebugParameter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "[out]pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags_, tab_count, tab_size, ToString(DataSize, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandQueue_AssertResourceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AssertResourceState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags_, tab_count, tab_size, ToString(Subresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "State", to_string_flags_, tab_count, tab_size, ToString(State, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandQueue1_AssertResourceAccess(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        D3D12_BARRIER_ACCESS Access)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandQueue1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AssertResourceAccess";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags_, tab_count, tab_size, ToString(Subresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Access", to_string_flags_, tab_count, tab_size, Quote(ToString(Access)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandQueue1_AssertTextureLayout(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        D3D12_BARRIER_LAYOUT Layout)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandQueue1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AssertTextureLayout";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags_, tab_count, tab_size, ToString(Subresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Layout", to_string_flags_, tab_count, tab_size, Quote(ToString(Layout)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_AssertResourceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AssertResourceState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags_, tab_count, tab_size, ToString(Subresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "State", to_string_flags_, tab_count, tab_size, ToString(State, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDebugParameter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags_, tab_count, tab_size, ToString(DataSize, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDebugParameter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "[out]pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags_, tab_count, tab_size, ToString(DataSize, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_AssertResourceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AssertResourceState";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags_, tab_count, tab_size, ToString(Subresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "State", to_string_flags_, tab_count, tab_size, ToString(State, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_SetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_FEATURE Mask)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetFeatureMask";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Mask", to_string_flags_, tab_count, tab_size, Quote(ToString(Mask)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_GetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DEBUG_FEATURE return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetFeatureMask";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList2_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetDebugParameter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags_, tab_count, tab_size, ToString(DataSize, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList2_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList2";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDebugParameter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Type", to_string_flags_, tab_count, tab_size, Quote(ToString(Type)));
            FieldToString(str_strm, false, "[out]pData", to_string_flags_, tab_count, tab_size, PointerDecoderArrayToString(DataSize, pData, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "DataSize", to_string_flags_, tab_count, tab_size, ToString(DataSize, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList3_AssertResourceAccess(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        D3D12_BARRIER_ACCESS Access)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AssertResourceAccess";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags_, tab_count, tab_size, ToString(Subresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Access", to_string_flags_, tab_count, tab_size, Quote(ToString(Access)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DebugCommandList3_AssertTextureLayout(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        D3D12_BARRIER_LAYOUT Layout)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DebugCommandList3";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AssertTextureLayout";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags_, tab_count, tab_size, ToString(Subresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "Layout", to_string_flags_, tab_count, tab_size, Quote(ToString(Layout)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SharingContract_Present(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        uint64_t window)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SharingContract";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Present";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pResource));
            FieldToString(str_strm, false, "Subresource", to_string_flags_, tab_count, tab_size, ToString(Subresource, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "window", to_string_flags_, tab_count, tab_size, HandleIdToString(window));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SharingContract_SharedFenceSignal(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pFence,
        UINT64 FenceValue)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SharingContract";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SharedFenceSignal";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFence", to_string_flags_, tab_count, tab_size, HandleIdToString(pFence));
            FieldToString(str_strm, false, "FenceValue", to_string_flags_, tab_count, tab_size, ToString(FenceValue, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SharingContract_BeginCapturableWork(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_GUID guid)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SharingContract";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "BeginCapturableWork";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "guid", to_string_flags_, tab_count, tab_size, ToString(*guid.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12SharingContract_EndCapturableWork(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_GUID guid)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12SharingContract";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "EndCapturableWork";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "guid", to_string_flags_, tab_count, tab_size, ToString(*guid.decoded_value, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 MessageCountLimit)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMessageCountLimit";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "MessageCountLimit", to_string_flags_, tab_count, tab_size, ToString(MessageCountLimit, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearStoredMessages(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearStoredMessages";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNumMessagesAllowedByStorageFilter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNumMessagesDeniedByStorageFilter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumStoredMessages(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNumStoredMessages";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNumStoredMessagesAllowedByRetrievalFilter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetNumMessagesDiscardedByMessageCountLimit";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMessageCountLimit";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddStorageFilterEntries(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddStorageFilterEntries";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFilter", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pFilter, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearStorageFilter";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushEmptyStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushEmptyStorageFilter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushCopyOfStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushCopyOfStorageFilter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushStorageFilter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFilter", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pFilter, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PopStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PopStorageFilter";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetStorageFilterStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetStorageFilterStackSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddRetrievalFilterEntries(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddRetrievalFilterEntries";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFilter", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pFilter, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ClearRetrievalFilter";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushEmptyRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushEmptyRetrievalFilter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushCopyOfRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushCopyOfRetrievalFilter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PushRetrievalFilter";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pFilter", to_string_flags_, tab_count, tab_size, StructPointerDecoderToString(pFilter, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PopRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "PopRetrievalFilter";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetRetrievalFilterStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRetrievalFilterStackSize";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddMessage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_CATEGORY Category,
        D3D12_MESSAGE_SEVERITY Severity,
        D3D12_MESSAGE_ID ID,
        StringDecoder* pDescription)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddMessage";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Category", to_string_flags_, tab_count, tab_size, Quote(ToString(Category)));
            FieldToString(str_strm, false, "Severity", to_string_flags_, tab_count, tab_size, Quote(ToString(Severity)));
            FieldToString(str_strm, false, "ID", to_string_flags_, tab_count, tab_size, Quote(ToString(ID)));
            FieldToString(str_strm, false, "pDescription", to_string_flags_, tab_count, tab_size, StringDecoderToString(pDescription));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddApplicationMessage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_SEVERITY Severity,
        StringDecoder* pDescription)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddApplicationMessage";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Severity", to_string_flags_, tab_count, tab_size, Quote(ToString(Severity)));
            FieldToString(str_strm, false, "pDescription", to_string_flags_, tab_count, tab_size, StringDecoderToString(pDescription));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnCategory(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_CATEGORY Category,
        BOOL bEnable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBreakOnCategory";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Category", to_string_flags_, tab_count, tab_size, Quote(ToString(Category)));
            FieldToString(str_strm, false, "bEnable", to_string_flags_, tab_count, tab_size, ToString(bEnable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnSeverity(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_SEVERITY Severity,
        BOOL bEnable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBreakOnSeverity";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Severity", to_string_flags_, tab_count, tab_size, Quote(ToString(Severity)));
            FieldToString(str_strm, false, "bEnable", to_string_flags_, tab_count, tab_size, ToString(bEnable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_ID ID,
        BOOL bEnable)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetBreakOnID";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ID", to_string_flags_, tab_count, tab_size, Quote(ToString(ID)));
            FieldToString(str_strm, false, "bEnable", to_string_flags_, tab_count, tab_size, ToString(bEnable, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnCategory(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_CATEGORY Category)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBreakOnCategory";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Category", to_string_flags_, tab_count, tab_size, Quote(ToString(Category)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnSeverity(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_SEVERITY Severity)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBreakOnSeverity";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Severity", to_string_flags_, tab_count, tab_size, Quote(ToString(Severity)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_ID ID)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetBreakOnID";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "ID", to_string_flags_, tab_count, tab_size, Quote(ToString(ID)));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetMuteDebugOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL bMute)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "SetMuteDebugOutput";
    std::string returnValue = std::string();
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "bMute", to_string_flags_, tab_count, tab_size, ToString(bMute, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMuteDebugOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMuteDebugOutput";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue1_RegisterMessageCallback(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t CallbackFunc,
        D3D12_MESSAGE_CALLBACK_FLAGS CallbackFilterFlags,
        uint64_t pContext,
        PointerDecoder<DWORD>* pCallbackCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "RegisterMessageCallback";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "CallbackFunc", to_string_flags_, tab_count, tab_size, ToString(CallbackFunc, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "CallbackFilterFlags", to_string_flags_, tab_count, tab_size, Quote(ToString(CallbackFilterFlags)));
            FieldToString(str_strm, false, "pContext", to_string_flags_, tab_count, tab_size, HandleIdToString(pContext));
            FieldToString(str_strm, false, "pCallbackCookie", to_string_flags_, tab_count, tab_size, PointerDecoderToString(pCallbackCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue1_UnregisterMessageCallback(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DWORD CallbackCookie)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue1";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "UnregisterMessageCallback";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "CallbackCookie", to_string_flags_, tab_count, tab_size, ToString(CallbackCookie, to_string_flags_, tab_count, tab_size));
        }
    );
}

/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12AsciiConsumer::Process_IUnknown_QueryInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObject)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IUnknown";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "QueryInterface";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "riid", to_string_flags_, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvObject", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppvObject));
        }
    );
}

void Dx12AsciiConsumer::Process_IUnknown_AddRef(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        ULONG return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IUnknown";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "AddRef";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}

void Dx12AsciiConsumer::Process_IUnknown_Release(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        ULONG return_value)
{
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IUnknown";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "Release";
    std::string returnValue = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(
        writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
}



GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
