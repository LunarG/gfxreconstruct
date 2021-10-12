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
#include "generated_dx12_convert_to_texts.h"
#include "decode/custom_dx12_struct_ascii_consumers.h"
#include "decode/dx12_enum_util.h"
#include "util/interception/injection.h"

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
    WriteApiCallToFile("CreateDXGIFactory", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppFactory", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppFactory, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateDXGIFactory1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppFactory", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppFactory, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetPrivateData", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIObject", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Name", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(Name, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSize, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSize, pData, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetPrivateDataInterface", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIObject", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Name", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(Name, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pUnknown", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pUnknown, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetPrivateData", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIObject", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Name", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(Name, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDataSize", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDataSize, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(* pDataSize, pData, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetParent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIObject", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppParent", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppParent, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDevice", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDeviceSubObject", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppDevice, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetSharedHandle", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIResource", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pSharedHandle", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pSharedHandle, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetUsage", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIResource", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pUsage", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pUsage, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetEvictionPriority", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIResource", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "EvictionPriority", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(EvictionPriority, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetEvictionPriority", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIResource", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pEvictionPriority", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pEvictionPriority, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("AcquireSync", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIKeyedMutex", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Key", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Key, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "dwMilliseconds", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(dwMilliseconds, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ReleaseSync", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIKeyedMutex", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Key", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Key, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISurface", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("Map", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISurface", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pLockedRect", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pLockedRect, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "MapFlags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(MapFlags, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("Unmap", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISurface", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetDC", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISurface1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Discard", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Discard, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]phdc", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(phdc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ReleaseDC", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISurface1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDirtyRect", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDirtyRect, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnumOutputs", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIAdapter", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Output", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Output, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppOutput", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppOutput, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIAdapter", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CheckInterfaceSupport", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIAdapter", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "InterfaceName", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(InterfaceName, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pUMDVersion", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pUMDVersion, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDisplayModeList", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "EnumFormat", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(EnumFormat, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Flags, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pNumModes", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pNumModes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(* pNumModes, pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("FindClosestMatchingMode", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pModeToMatch", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pModeToMatch, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pClosestMatch", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pClosestMatch, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pConcernedDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pConcernedDevice, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("WaitForVBlank", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("TakeOwnership", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Exclusive", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Exclusive, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ReleaseOwnership", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetGammaControlCapabilities", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pGammaCaps", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pGammaCaps, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGammaControl", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pArray", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pArray, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetGammaControl", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pArray", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pArray, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetDisplaySurface", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pScanoutSurface", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pScanoutSurface, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDisplaySurfaceData", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDestination", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDestination, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetFrameStatistics", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pStats", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pStats, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_IDXGISwapChain_Present(
        format::HandleId object_id,
        HRESULT return_value,
        UINT SyncInterval,
        UINT Flags)
{
    OverridePresent(
        object_id,
        return_value,
        SyncInterval,
        Flags);
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
    WriteApiCallToFile("GetBuffer", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Buffer", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Buffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSurface", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSurface, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetFullscreenState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Fullscreen", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Fullscreen, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pTarget", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pTarget, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetFullscreenState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pFullscreen", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFullscreen, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppTarget", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppTarget, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ResizeBuffers", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "BufferCount", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BufferCount, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Width, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Height, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NewFormat", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(NewFormat, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "SwapChainFlags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SwapChainFlags, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ResizeTarget", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pNewTargetParameters", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pNewTargetParameters, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetContainingOutput", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]ppOutput", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppOutput, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetFrameStatistics", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pStats", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pStats, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetLastPresentCount", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pLastPresentCount", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pLastPresentCount, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnumAdapters", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Adapter", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Adapter, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppAdapter", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppAdapter, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("MakeWindowAssociation", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "WindowHandle", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(WindowHandle, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Flags, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetWindowAssociation", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pWindowHandle", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pWindowHandle, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateSwapChain", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSwapChain", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSwapChain, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateSoftwareAdapter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Module", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(Module, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppAdapter", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppAdapter, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetAdapter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pAdapter", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pAdapter, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateSurface", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumSurfaces", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumSurfaces, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Usage", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Usage, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSharedResource", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pSharedResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSurface", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSurface, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("QueryResourceResidency", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ppResources", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumResources, ppResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pResidencyStatus", toStringFlags, tabCount, tabSize, "TODO 2 : EnumPointerDecoderArrayToString(NumResources, pResidencyStatus, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumResources", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumResources, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGPUThreadPriority", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Priority", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Priority, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetGPUThreadPriority", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pPriority", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pPriority, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnumAdapters1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Adapter", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Adapter, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppAdapter", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppAdapter, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("IsCurrent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory1", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetDesc1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIAdapter1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetMaximumFrameLatency", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "MaxLatency", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(MaxLatency, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetMaximumFrameLatency", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pMaxLatency", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pMaxLatency, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("IsStereoEnabled", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDisplayControl", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("SetStereoEnabled", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "IDXGIDisplayControl", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "enabled", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(enabled, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "IDXGIOutputDuplication", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("AcquireNextFrame", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutputDuplication", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "TimeoutInMilliseconds", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(TimeoutInMilliseconds, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pFrameInfo", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pFrameInfo, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppDesktopResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppDesktopResource, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetFrameDirtyRects", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutputDuplication", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "DirtyRectsBufferSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DirtyRectsBufferSize, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pDirtyRectsBuffer", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(DirtyRectsBufferSize/sizeof tagRECT, pDirtyRectsBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pDirtyRectsBufferSizeRequired", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDirtyRectsBufferSizeRequired, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetFrameMoveRects", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutputDuplication", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "MoveRectsBufferSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(MoveRectsBufferSize, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pMoveRectBuffer", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(MoveRectsBufferSize/sizeof DXGI_OUTDUPL_MOVE_RECT, pMoveRectBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pMoveRectsBufferSizeRequired", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pMoveRectsBufferSizeRequired, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetFramePointerShape", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutputDuplication", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "PointerShapeBufferSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(PointerShapeBufferSize, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pPointerShapeBuffer", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(PointerShapeBufferSize, pPointerShapeBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pPointerShapeBufferSizeRequired", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pPointerShapeBufferSizeRequired, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pPointerShapeInfo", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pPointerShapeInfo, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("MapDesktopSurface", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutputDuplication", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pLockedRect", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pLockedRect, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("UnMapDesktopSurface", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutputDuplication", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("ReleaseFrame", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutputDuplication", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetResource", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISurface2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppParentResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppParentResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pSubresourceIndex", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pSubresourceIndex, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateSubresourceSurface", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIResource1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "index", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(index, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSurface", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSurface, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateSharedHandle", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIResource1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pAttributes", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pAttributes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "dwAccess", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(dwAccess, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "lpName", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(lpName, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pHandle", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pHandle, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("OfferResources", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumResources", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppResources", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumResources, ppResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Priority", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Priority, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("ReclaimResources", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumResources", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppResources", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumResources, ppResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pDiscarded", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumResources, pDiscarded, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnqueueSetEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "hEvent", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hEvent, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDesc1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetFullscreenDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetHwnd", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pHwnd", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pHwnd, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetCoreWindow", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "refiid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(refiid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppUnk", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppUnk, toStringFlags, tabCount, tabSize)");
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
    OverridePresent1(
        object_id,
        return_value,
        SyncInterval,
        PresentFlags,
        pPresentParameters);
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_IsTemporaryMonoSupported(
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("IsTemporaryMonoSupported", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain1", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetRestrictToOutput", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]ppRestrictToOutput", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppRestrictToOutput, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetBackgroundColor", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pColor", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pColor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetBackgroundColor", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pColor", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pColor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetRotation", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Rotation", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Rotation, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("GetRotation", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pRotation", toStringFlags, tabCount, tabSize, "TODO 6 : EnumPointerDecoderToString(pRotation)");
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
    WriteApiCallToFile("IsWindowedStereoEnabled", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("CreateSwapChainForHwnd", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "hWnd", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hWnd, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pFullscreenDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pFullscreenDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRestrictToOutput", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pRestrictToOutput, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSwapChain", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSwapChain, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateSwapChainForCoreWindow", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pWindow", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pWindow, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRestrictToOutput", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pRestrictToOutput, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSwapChain", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSwapChain, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetSharedResourceAdapterLuid", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "hResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pLuid", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pLuid, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("RegisterStereoStatusWindow", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "WindowHandle", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(WindowHandle, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "wMsg", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(wMsg, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pdwCookie", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pdwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("RegisterStereoStatusEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "hEvent", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hEvent, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pdwCookie", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pdwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("UnregisterStereoStatus", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "dwCookie", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(dwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("RegisterOcclusionStatusWindow", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "WindowHandle", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(WindowHandle, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "wMsg", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(wMsg, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pdwCookie", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pdwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("RegisterOcclusionStatusEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "hEvent", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hEvent, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pdwCookie", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pdwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("UnregisterOcclusionStatus", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "dwCookie", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(dwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateSwapChainForComposition", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRestrictToOutput", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pRestrictToOutput, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSwapChain", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSwapChain, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDesc2", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIAdapter2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDisplayModeList1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "EnumFormat", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(EnumFormat, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Flags, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pNumModes", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pNumModes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(* pNumModes, pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("FindClosestMatchingMode1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pModeToMatch", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pModeToMatch, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pClosestMatch", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pClosestMatch, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pConcernedDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pConcernedDevice, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDisplaySurfaceData1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDestination", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDestination, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("DuplicateOutput", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppOutputDuplication", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppOutputDuplication, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateDXGIFactory2", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Flags, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppFactory", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppFactory, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("DXGIGetDebugInterface1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Flags, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pDebug", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDebug, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("Trim", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "IDXGIDevice3", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("SetSourceSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Width, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Height, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetSourceSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pWidth", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pWidth, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pHeight", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pHeight, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetMaximumFrameLatency", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "MaxLatency", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(MaxLatency, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetMaximumFrameLatency", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pMaxLatency", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pMaxLatency, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetFrameLatencyWaitableObject", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain2", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("SetMatrixTransform", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pMatrix", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pMatrix, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetMatrixTransform", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pMatrix", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pMatrix, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SupportsOverlays", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput2", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetCreationFlags", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory3", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("PresentBuffer", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDecodeSwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "BufferToPresent", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BufferToPresent, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SyncInterval", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SyncInterval, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Flags, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetSourceRect", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDecodeSwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pRect", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pRect, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetTargetRect", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDecodeSwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pRect", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pRect, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetDestSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDecodeSwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Width, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Height, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetSourceRect", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDecodeSwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pRect", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pRect, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetTargetRect", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDecodeSwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pRect", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pRect, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDestSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDecodeSwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pWidth", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pWidth, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pHeight", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pHeight, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetColorSpace", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDecodeSwapChain", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ColorSpace", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(ColorSpace, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("GetColorSpace", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDecodeSwapChain", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("CreateSwapChainForCompositionSurfaceHandle", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactoryMedia", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "hSurface", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hSurface, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRestrictToOutput", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pRestrictToOutput, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSwapChain", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSwapChain, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateDecodeSwapChainForCompositionSurfaceHandle", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactoryMedia", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "hSurface", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hSurface, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pYuvDecodeBuffers", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pYuvDecodeBuffers, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRestrictToOutput", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pRestrictToOutput, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSwapChain", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSwapChain, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetFrameStatisticsMedia", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChainMedia", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pStats", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pStats, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetPresentDuration", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChainMedia", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Duration", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Duration, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CheckPresentDurationSupport", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChainMedia", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "DesiredPresentDuration", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DesiredPresentDuration, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pClosestSmallerPresentDuration", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pClosestSmallerPresentDuration, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pClosestLargerPresentDuration", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pClosestLargerPresentDuration, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CheckOverlaySupport", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "EnumFormat", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(EnumFormat, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pConcernedDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pConcernedDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pFlags", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFlags, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetCurrentBackBufferIndex", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain3", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("CheckColorSpaceSupport", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ColorSpace", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(ColorSpace, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "[out]pColorSpaceSupport", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pColorSpaceSupport, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetColorSpace1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ColorSpace", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(ColorSpace, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("ResizeBuffers1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "BufferCount", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BufferCount, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Width", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Width, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Height", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Height, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Format, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "SwapChainFlags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SwapChainFlags, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pCreationNodeMask", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(BufferCount, pCreationNodeMask, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppPresentQueue", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(BufferCount, ppPresentQueue, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CheckOverlayColorSpaceSupport", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Format, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "ColorSpace", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(ColorSpace, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pConcernedDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pConcernedDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pFlags", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFlags, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnumAdapterByLuid", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "AdapterLuid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(AdapterLuid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvAdapter", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvAdapter, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnumWarpAdapter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvAdapter", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvAdapter, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("RegisterHardwareContentProtectionTeardownStatusEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIAdapter3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "hEvent", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hEvent, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pdwCookie", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pdwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("UnregisterHardwareContentProtectionTeardownStatus", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "IDXGIAdapter3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "dwCookie", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(dwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("QueryVideoMemoryInfo", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIAdapter3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NodeIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NodeIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "MemorySegmentGroup", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(MemorySegmentGroup, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "[out]pVideoMemoryInfo", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pVideoMemoryInfo, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetVideoMemoryReservation", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIAdapter3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NodeIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NodeIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "MemorySegmentGroup", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(MemorySegmentGroup, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "Reservation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Reservation, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("RegisterVideoMemoryBudgetChangeNotificationEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIAdapter3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "hEvent", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hEvent, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pdwCookie", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pdwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("UnregisterVideoMemoryBudgetChangeNotification", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "IDXGIAdapter3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "dwCookie", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(dwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("DuplicateOutput1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput5", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDevice, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Flags, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SupportedFormatsCount", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SupportedFormatsCount, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSupportedFormats", toStringFlags, tabCount, tabSize, "TODO 2 : EnumPointerDecoderArrayToString(SupportedFormatsCount, pSupportedFormats, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppOutputDuplication", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppOutputDuplication, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetHDRMetaData", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGISwapChain4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "Size", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Size, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pMetaData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(Size, pMetaData, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("OfferResources1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumResources", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppResources", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumResources, ppResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Priority", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Priority, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Flags, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ReclaimResources1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIDevice4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumResources", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppResources", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumResources, ppResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pResults", toStringFlags, tabCount, tabSize, "TODO 2 : EnumPointerDecoderArrayToString(NumResources, pResults, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("DXGIDeclareAdapterRemovalSupport", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
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
    WriteApiCallToFile("GetDesc3", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIAdapter4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDesc1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput6", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CheckHardwareCompositionSupport", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIOutput6", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pFlags", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFlags, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnumAdapterByGpuPreference", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory6", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Adapter", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Adapter, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "GpuPreference", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(GpuPreference, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvAdapter", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvAdapter, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("RegisterAdaptersChangedEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory7", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "hEvent", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hEvent, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pdwCookie", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pdwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("UnregisterAdaptersChangedEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IDXGIFactory7", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "dwCookie", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(dwCookie, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("D3D12SerializeRootSignature", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "pRootSignature", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pRootSignature, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Version", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Version, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "[out]ppBlob", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppBlob, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppErrorBlob", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppErrorBlob, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_D3D12CreateRootSignatureDeserializer(
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
    WriteApiCallToFile("D3D12CreateRootSignatureDeserializer", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "pSrcData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(SrcDataSizeInBytes, pSrcData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcDataSizeInBytes", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcDataSizeInBytes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRootSignatureDeserializerInterface", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(pRootSignatureDeserializerInterface, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppRootSignatureDeserializer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppRootSignatureDeserializer, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("D3D12SerializeVersionedRootSignature", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "pRootSignature", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pRootSignature, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppBlob", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppBlob, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppErrorBlob", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppErrorBlob, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("D3D12CreateVersionedRootSignatureDeserializer", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "pSrcData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(SrcDataSizeInBytes, pSrcData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcDataSizeInBytes", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcDataSizeInBytes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRootSignatureDeserializerInterface", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(pRootSignatureDeserializerInterface, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppRootSignatureDeserializer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppRootSignatureDeserializer, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("D3D12CreateDevice", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "pAdapter", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pAdapter, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "MinimumFeatureLevel", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(MinimumFeatureLevel, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppDevice, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("D3D12GetDebugInterface", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvDebug", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvDebug, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("D3D12EnableExperimentalFeatures", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(strStrm, false, "NumFeatures", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumFeatures, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pIIDs", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumFeatures, pIIDs, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pConfigurationStructs", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumFeatures, pConfigurationStructs, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pConfigurationStructSizes", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumFeatures, pConfigurationStructSizes, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetPrivateData", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Object", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "guid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(guid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDataSize", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDataSize, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(* pDataSize, pData, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetPrivateData", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Object", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "guid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(guid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSize, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSize, pData, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetPrivateDataInterface", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Object", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "guid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(guid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pData, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetName", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Object", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Name", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(Name, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDevice", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DeviceChild", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvDevice", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvDevice, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetRootSignatureDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12RootSignatureDeserializer", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetRootSignatureDescAtVersion", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12VersionedRootSignatureDeserializer", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "convertToVersion", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(convertToVersion, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "[out]ppDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(ppDesc, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetUnconvertedRootSignatureDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12VersionedRootSignatureDeserializer", to_string_flags, tab_count, tab_size, "nullptr");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Heap_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_HEAP_DESC return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Heap", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("Map", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Resource", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Subresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pReadRange", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pReadRange, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppData", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppData, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("Unmap", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Resource", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Subresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pWrittenRange", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pWrittenRange, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Resource_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Resource", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetGPUVirtualAddress", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Resource", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("WriteToSubresource", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Resource", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "DstSubresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstSubresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDstBox", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDstBox, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcData", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pSrcData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcRowPitch", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcRowPitch, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcDepthPitch", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcDepthPitch, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ReadFromSubresource", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Resource", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pDstData", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDstData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstRowPitch", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstRowPitch, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstDepthPitch", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstDepthPitch, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcSubresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcSubresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcBox", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pSrcBox, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetHeapProperties", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Resource", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pHeapProperties", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pHeapProperties, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pHeapFlags", toStringFlags, tabCount, tabSize, "TODO 6 : EnumPointerDecoderToString(pHeapFlags)");
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
    WriteApiCallToFile("Reset", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12CommandAllocator", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetCompletedValue", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Fence", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("SetEventOnCompletion", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Fence", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Value", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Value, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "hEvent", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hEvent, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("Signal", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Fence", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Value", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Value, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetCreationFlags", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Fence1", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetCachedBlob", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12PipelineState", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]ppBlob", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppBlob, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_DESCRIPTOR_HEAP_DESC return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DescriptorHeap", to_string_flags, tab_count, tab_size, "nullptr");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetCPUDescriptorHandleForHeapStart", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DescriptorHeap", to_string_flags, tab_count, tab_size, "nullptr");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetGPUDescriptorHandleForHeapStart", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DescriptorHeap", to_string_flags, tab_count, tab_size, "nullptr");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandList_GetType(
        format::HandleId object_id,
        D3D12_COMMAND_LIST_TYPE return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetType", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12CommandList", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("Close", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("Reset", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pInitialState", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pInitialState, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ClearState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pPipelineState", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pPipelineState, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("DrawInstanced", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "VertexCountPerInstance", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(VertexCountPerInstance, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "InstanceCount", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(InstanceCount, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "StartVertexLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(StartVertexLocation, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "StartInstanceLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(StartInstanceLocation, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("DrawIndexedInstanced", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "IndexCountPerInstance", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(IndexCountPerInstance, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "InstanceCount", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(InstanceCount, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "StartIndexLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(StartIndexLocation, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BaseVertexLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BaseVertexLocation, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "StartInstanceLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(StartInstanceLocation, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("Dispatch", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ThreadGroupCountX", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(ThreadGroupCountX, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ThreadGroupCountY", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(ThreadGroupCountY, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ThreadGroupCountZ", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(ThreadGroupCountZ, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CopyBufferRegion", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDstBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDstBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pSrcBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumBytes", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumBytes, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CopyTextureRegion", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDst", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDst, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstX", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstX, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstY", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstY, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstZ", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstZ, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pSrc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcBox", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pSrcBox, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CopyResource", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDstResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDstResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pSrcResource, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CopyTiles", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pTiledResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pTiledResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pTileRegionStartCoordinate", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pTileRegionStartCoordinate, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pTileRegionSize", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pTileRegionSize, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BufferStartOffsetInBytes", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BufferStartOffsetInBytes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("ResolveSubresource", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDstResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDstResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstSubresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstSubresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pSrcResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcSubresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcSubresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Format, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("IASetPrimitiveTopology", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "PrimitiveTopology", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(PrimitiveTopology, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("RSSetViewports", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumViewports", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumViewports, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pViewports", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumViewports, pViewports, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("RSSetScissorRects", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumRects", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumRects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRects", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumRects, pRects, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("OMSetBlendFactor", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "BlendFactor", toStringFlags, tabCount, tabSize, "TODO 11 : PointerDecoderArrayToString(4, BlendFactor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("OMSetStencilRef", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "StencilRef", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(StencilRef, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetPipelineState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pPipelineState", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pPipelineState, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResourceBarrier(
        format::HandleId object_id,
        UINT NumBarriers,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("ResourceBarrier", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumBarriers", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumBarriers, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pBarriers", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumBarriers, pBarriers, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ExecuteBundle", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pCommandList", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pCommandList, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetDescriptorHeaps", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumDescriptorHeaps", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumDescriptorHeaps, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppDescriptorHeaps", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumDescriptorHeaps, ppDescriptorHeaps, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetComputeRootSignature", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pRootSignature", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pRootSignature, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGraphicsRootSignature", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pRootSignature", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pRootSignature, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetComputeRootDescriptorTable", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BaseDescriptor", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(BaseDescriptor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGraphicsRootDescriptorTable", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BaseDescriptor", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(BaseDescriptor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetComputeRoot32BitConstant", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcData", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestOffsetIn32BitValues", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DestOffsetIn32BitValues, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGraphicsRoot32BitConstant", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcData", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestOffsetIn32BitValues", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DestOffsetIn32BitValues, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetComputeRoot32BitConstants", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Num32BitValuesToSet", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Num32BitValuesToSet, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(Num32BitValuesToSet * sizeof ( UINT ), pSrcData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestOffsetIn32BitValues", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DestOffsetIn32BitValues, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGraphicsRoot32BitConstants", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Num32BitValuesToSet", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Num32BitValuesToSet, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(Num32BitValuesToSet * sizeof ( UINT ), pSrcData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestOffsetIn32BitValues", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DestOffsetIn32BitValues, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetComputeRootConstantBufferView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BufferLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BufferLocation, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGraphicsRootConstantBufferView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BufferLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BufferLocation, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetComputeRootShaderResourceView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BufferLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BufferLocation, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGraphicsRootShaderResourceView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BufferLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BufferLocation, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetComputeRootUnorderedAccessView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BufferLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BufferLocation, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGraphicsRootUnorderedAccessView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RootParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RootParameterIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BufferLocation", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BufferLocation, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("IASetIndexBuffer", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pView", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pView, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("IASetVertexBuffers", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "StartSlot", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(StartSlot, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumViews", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumViews, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pViews", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumViews, pViews, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SOSetTargets", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "StartSlot", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(StartSlot, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumViews", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumViews, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pViews", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumViews, pViews, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("OMSetRenderTargets", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumRenderTargetDescriptors", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumRenderTargetDescriptors, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRenderTargetDescriptors", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(RTsSingleHandleToDescriptorRange ? 1 : NumRenderTargetDescriptors, pRenderTargetDescriptors, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "RTsSingleHandleToDescriptorRange", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(RTsSingleHandleToDescriptorRange, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDepthStencilDescriptor", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDepthStencilDescriptor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ClearDepthStencilView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "DepthStencilView", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(DepthStencilView, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ClearFlags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(ClearFlags, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "Depth", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Depth, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Stencil", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Stencil, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumRects", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumRects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRects", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumRects, pRects, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ClearRenderTargetView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "RenderTargetView", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(RenderTargetView, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ColorRGBA", toStringFlags, tabCount, tabSize, "TODO 11 : PointerDecoderArrayToString(4, ColorRGBA, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumRects", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumRects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRects", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumRects, pRects, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ClearUnorderedAccessViewUint", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ViewGPUHandleInCurrentHeap", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(ViewGPUHandleInCurrentHeap, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ViewCPUHandle", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(ViewCPUHandle, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Values", toStringFlags, tabCount, tabSize, "TODO 11 : PointerDecoderArrayToString(4, Values, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumRects", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumRects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRects", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumRects, pRects, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ClearUnorderedAccessViewFloat", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ViewGPUHandleInCurrentHeap", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(ViewGPUHandleInCurrentHeap, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ViewCPUHandle", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(ViewCPUHandle, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Values", toStringFlags, tabCount, tabSize, "TODO 11 : PointerDecoderArrayToString(4, Values, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumRects", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumRects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRects", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumRects, pRects, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("DiscardResource", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRegion", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pRegion, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("BeginQuery", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pQueryHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pQueryHeap, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "Index", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Index, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EndQuery", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pQueryHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pQueryHeap, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "Index", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Index, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ResolveQueryData", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pQueryHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pQueryHeap, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "StartIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(StartIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumQueries", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumQueries, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDestinationBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDestinationBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "AlignedDestinationBufferOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(AlignedDestinationBufferOffset, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetPredication", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "AlignedBufferOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(AlignedBufferOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Operation", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Operation, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetMarker", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Metadata", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Metadata, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(Size, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Size", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Size, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("BeginEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Metadata", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Metadata, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(Size, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Size", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Size, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EndEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("ExecuteIndirect", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pCommandSignature", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pCommandSignature, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "MaxCommandCount", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(MaxCommandCount, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pArgumentBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pArgumentBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ArgumentBufferOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(ArgumentBufferOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pCountBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pCountBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "CountBufferOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(CountBufferOffset, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("AtomicCopyBufferUINT", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDstBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDstBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pSrcBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Dependencies", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Dependencies, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppDependentResources", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(Dependencies, ppDependentResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDependentSubresourceRanges", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(Dependencies, pDependentSubresourceRanges, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("AtomicCopyBufferUINT64", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDstBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDstBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcBuffer", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pSrcBuffer, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Dependencies", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Dependencies, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppDependentResources", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(Dependencies, ppDependentResources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDependentSubresourceRanges", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(Dependencies, pDependentSubresourceRanges, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("OMSetDepthBounds", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Min", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Min, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Max", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Max, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetSamplePositions", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumSamplesPerPixel", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumSamplesPerPixel, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumPixels", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumPixels, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSamplePositions", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumSamplesPerPixel * NumPixels, pSamplePositions, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ResolveSubresourceRegion", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDstResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDstResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstSubresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstSubresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstX", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstX, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DstY", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DstY, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pSrcResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcSubresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SrcSubresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcRect", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pSrcRect, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Format", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Format, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "ResolveMode", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(ResolveMode, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetViewInstanceMask", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Mask", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Mask, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("WriteBufferImmediate", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Count", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Count, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pParams", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(Count, pParams, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pModes", toStringFlags, tabCount, tabSize, "TODO 2 : EnumPointerDecoderArrayToString(Count, pModes, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("UpdateTileMappings", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumResourceRegions", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumResourceRegions, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pResourceRegionStartCoordinates", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumResourceRegions, pResourceRegionStartCoordinates, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pResourceRegionSizes", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumResourceRegions, pResourceRegionSizes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pHeap, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumRanges", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumRanges, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRangeFlags", toStringFlags, tabCount, tabSize, "TODO 2 : EnumPointerDecoderArrayToString(NumRanges, pRangeFlags, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pHeapRangeStartOffsets", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumRanges, pHeapRangeStartOffsets, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRangeTileCounts", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumRanges, pRangeTileCounts, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("CopyTileMappings", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDstResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDstResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDstRegionStartCoordinate", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDstRegionStartCoordinate, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pSrcResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcRegionStartCoordinate", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pSrcRegionStartCoordinate, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRegionSize", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pRegionSize, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("ExecuteCommandLists", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumCommandLists", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumCommandLists, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppCommandLists", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumCommandLists, ppCommandLists, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetMarker", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Metadata", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Metadata, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(Size, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Size", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Size, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("BeginEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Metadata", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Metadata, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(Size, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Size", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Size, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EndEvent", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("Signal", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pFence", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFence, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Value", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Value, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("Wait", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pFence", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFence, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Value", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Value, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetTimestampFrequency", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pFrequency", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFrequency, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetClockCalibration", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pGpuTimestamp", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pGpuTimestamp, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pCpuTimestamp", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pCpuTimestamp, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_COMMAND_QUEUE_DESC return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetNodeCount", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("CreateCommandQueue", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppCommandQueue", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppCommandQueue, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateCommandAllocator", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppCommandAllocator", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppCommandAllocator, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateGraphicsPipelineState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppPipelineState", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppPipelineState, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateComputePipelineState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppPipelineState", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppPipelineState, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateCommandList", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "nodeMask", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(nodeMask, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pCommandAllocator", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pCommandAllocator, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pInitialState", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pInitialState, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppCommandList", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppCommandList, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateDescriptorHeap", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDescriptorHeapDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDescriptorHeapDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvHeap, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDescriptorHandleIncrementSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "DescriptorHeapType", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(DescriptorHeapType, toStringFlags, tabCount, tabSize) + '"'");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateRootSignature(
        format::HandleId object_id,
        HRESULT return_value,
        UINT nodeMask,
        PointerDecoder<uint8_t>* pBlobWithRootSignature,
        SIZE_T blobLengthInBytes,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvRootSignature)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("CreateRootSignature", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "nodeMask", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(nodeMask, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pBlobWithRootSignature", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(blobLengthInBytes, pBlobWithRootSignature, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "blobLengthInBytes", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(blobLengthInBytes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvRootSignature", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvRootSignature, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateConstantBufferView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestDescriptor", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(DestDescriptor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateShaderResourceView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestDescriptor", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(DestDescriptor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateUnorderedAccessView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pCounterResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pCounterResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestDescriptor", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(DestDescriptor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateRenderTargetView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestDescriptor", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(DestDescriptor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateDepthStencilView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestDescriptor", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(DestDescriptor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateSampler", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestDescriptor", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(DestDescriptor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CopyDescriptors", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumDestDescriptorRanges", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumDestDescriptorRanges, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDestDescriptorRangeStarts", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumDestDescriptorRanges, pDestDescriptorRangeStarts, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDestDescriptorRangeSizes", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumDestDescriptorRanges, pDestDescriptorRangeSizes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumSrcDescriptorRanges", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumSrcDescriptorRanges, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcDescriptorRangeStarts", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumSrcDescriptorRanges, pSrcDescriptorRangeStarts, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSrcDescriptorRangeSizes", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumSrcDescriptorRanges, pSrcDescriptorRangeSizes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DescriptorHeapsType", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(DescriptorHeapsType, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("CopyDescriptorsSimple", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumDescriptors", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumDescriptors, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestDescriptorRangeStart", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(DestDescriptorRangeStart, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SrcDescriptorRangeStart", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(SrcDescriptorRangeStart, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DescriptorHeapsType", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(DescriptorHeapsType, toStringFlags, tabCount, tabSize) + '"'");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetResourceAllocationInfo(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetResourceAllocationInfo", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "visibleMask", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(visibleMask, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "numResourceDescs", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(numResourceDescs, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pResourceDescs", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(numResourceDescs, pResourceDescs, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetCustomHeapProperties(
        format::HandleId object_id,
        Decoded_D3D12_HEAP_PROPERTIES return_value,
        UINT nodeMask,
        D3D12_HEAP_TYPE heapType)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetCustomHeapProperties", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "nodeMask", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(nodeMask, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "heapType", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(heapType, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("CreateCommittedResource", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pHeapProperties", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pHeapProperties, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "HeapFlags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(HeapFlags, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "InitialResourceState", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(InitialResourceState, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pOptimizedClearValue", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOptimizedClearValue, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riidResource", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riidResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvResource, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateHeap", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvHeap, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreatePlacedResource", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pHeap, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "HeapOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(HeapOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "InitialState", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(InitialState, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pOptimizedClearValue", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOptimizedClearValue, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvResource, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateReservedResource", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "InitialState", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(InitialState, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pOptimizedClearValue", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOptimizedClearValue, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvResource, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateSharedHandle", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pObject", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pObject, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pAttributes", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pAttributes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Access", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Access, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Name", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(Name, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pHandle", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pHandle, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("OpenSharedHandle", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NTHandle", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(NTHandle, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvObj", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvObj, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("OpenSharedHandleByName", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Name", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(Name, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Access", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Access, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pNTHandle", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pNTHandle, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("MakeResident", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumObjects", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumObjects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppObjects", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumObjects, ppObjects, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("Evict", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumObjects", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumObjects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppObjects", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumObjects, ppObjects, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateFence", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "InitialValue", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(InitialValue, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppFence", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppFence, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDeviceRemovedReason", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetCopyableFootprints", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResourceDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pResourceDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "FirstSubresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(FirstSubresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumSubresources", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumSubresources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BaseOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BaseOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pLayouts", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumSubresources, pLayouts, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pNumRows", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumSubresources, pNumRows, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pRowSizeInBytes", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumSubresources, pRowSizeInBytes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pTotalBytes", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pTotalBytes, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateQueryHeap", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvHeap, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetStablePowerState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Enable", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Enable, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateCommandSignature", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRootSignature", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pRootSignature, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvCommandSignature", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvCommandSignature, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetResourceTiling", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pTiledResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pTiledResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pNumTilesForEntireResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pNumTilesForEntireResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pPackedMipDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pPackedMipDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pStandardTileShapeForNonPackedMips", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pStandardTileShapeForNonPackedMips, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pNumSubresourceTilings", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pNumSubresourceTilings, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "FirstSubresourceTilingToGet", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(FirstSubresourceTilingToGet, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pSubresourceTilingsForNonPackedMips", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(* pNumSubresourceTilings, pSubresourceTilingsForNonPackedMips, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetAdapterLuid(
        format::HandleId object_id,
        Decoded_LUID return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetAdapterLuid", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("StorePipeline", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12PipelineLibrary", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pName", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pName, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pPipeline", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pPipeline, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("LoadGraphicsPipeline", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12PipelineLibrary", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pName", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pName, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppPipelineState", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppPipelineState, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("LoadComputePipeline", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12PipelineLibrary", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pName", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pName, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppPipelineState", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppPipelineState, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetSerializedSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12PipelineLibrary", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("Serialize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12PipelineLibrary", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSizeInBytes, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSizeInBytes", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSizeInBytes, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("LoadPipeline", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12PipelineLibrary1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pName", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pName, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppPipelineState", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppPipelineState, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreatePipelineLibrary", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pLibraryBlob", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(BlobLength, pLibraryBlob, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BlobLength", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BlobLength, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppPipelineLibrary", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppPipelineLibrary, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetEventOnMultipleFenceCompletion", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ppFences", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumFences, ppFences, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pFenceValues", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumFences, pFenceValues, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumFences", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumFences, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "hEvent", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hEvent, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetResidencyPriority", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumObjects", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumObjects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppObjects", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumObjects, ppObjects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pPriorities", toStringFlags, tabCount, tabSize, "TODO 2 : EnumPointerDecoderArrayToString(NumObjects, pPriorities, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreatePipelineState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppPipelineState", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppPipelineState, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("OpenExistingHeapFromAddress", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pAddress", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pAddress, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvHeap, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("OpenExistingHeapFromFileMapping", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "hFileMapping", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hFileMapping, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvHeap, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnqueueMakeResident", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "NumObjects", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumObjects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ppObjects", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumObjects, ppObjects, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pFenceToSignal", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFenceToSignal, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "FenceValueToSignal", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(FenceValueToSignal, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetStatusFence", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12ProtectedSession", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppFence", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppFence, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetSessionStatus", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12ProtectedSession", to_string_flags, tab_count, tab_size, "nullptr");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12ProtectedResourceSession", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("CreateCommandList1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "nodeMask", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(nodeMask, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(flags, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppCommandList", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppCommandList, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateProtectedResourceSession", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSession", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSession, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateCommittedResource1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pHeapProperties", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pHeapProperties, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "HeapFlags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(HeapFlags, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "InitialResourceState", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(InitialResourceState, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pOptimizedClearValue", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOptimizedClearValue, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pProtectedSession", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pProtectedSession, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riidResource", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riidResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvResource, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateHeap1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pProtectedSession", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pProtectedSession, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvHeap, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateReservedResource1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "InitialState", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(InitialState, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pOptimizedClearValue", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOptimizedClearValue, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pProtectedSession", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pProtectedSession, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvResource, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12Device4_GetResourceAllocationInfo1(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetResourceAllocationInfo1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "visibleMask", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(visibleMask, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "numResourceDescs", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(numResourceDescs, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pResourceDescs", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(numResourceDescs, pResourceDescs, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pResourceAllocationInfo1", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(numResourceDescs, pResourceAllocationInfo1, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("LifetimeStateUpdated", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12LifetimeOwner", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NewState", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(NewState, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("GetLUID", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12SwapChainAssistant", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetSwapChainObject", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12SwapChainAssistant", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppv", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppv, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetCurrentResourceAndCommandQueue", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12SwapChainAssistant", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riidResource", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riidResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riidQueue", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riidQueue, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvQueue", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvQueue, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("InsertImplicitSync", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12SwapChainAssistant", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("DestroyOwnedObject", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12LifetimeTracker", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pObject", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pObject, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetShaderIdentifier", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12StateObjectProperties", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pExportName", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pExportName, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetShaderStackSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12StateObjectProperties", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pExportName", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pExportName, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetPipelineStackSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12StateObjectProperties", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("SetPipelineStackSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12StateObjectProperties", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "PipelineStackSizeInBytes", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(PipelineStackSizeInBytes, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateLifetimeTracker", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device5", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pOwner", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pOwner, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvTracker", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvTracker, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("RemoveDevice", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device5", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("EnumerateMetaCommands", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device5", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pNumMetaCommands", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pNumMetaCommands, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pDescs", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(* pNumMetaCommands, pDescs, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnumerateMetaCommandParameters", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device5", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "CommandId", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(CommandId, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Stage", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Stage, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "[out]pTotalStructureSizeInBytes", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pTotalStructureSizeInBytes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pParameterCount", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pParameterCount, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pParameterDescs", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(* pParameterCount, pParameterDescs, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateMetaCommand", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device5", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "CommandId", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(CommandId, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NodeMask", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NodeMask, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pCreationParametersData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(CreationParametersDataSizeInBytes, pCreationParametersData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "CreationParametersDataSizeInBytes", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(CreationParametersDataSizeInBytes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppMetaCommand", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppMetaCommand, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateStateObject", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device5", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppStateObject", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppStateObject, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetRaytracingAccelerationStructurePrebuildInfo", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device5", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pInfo", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CheckDriverMatchingIdentifier", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device5", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "SerializedDataType", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(SerializedDataType, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pIdentifierToCheck", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pIdentifierToCheck, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetAutoBreadcrumbsEnablement", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12DeviceRemovedExtendedDataSettings", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Enablement", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Enablement, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetPageFaultEnablement", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12DeviceRemovedExtendedDataSettings", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Enablement", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Enablement, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetWatsonDumpEnablement", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12DeviceRemovedExtendedDataSettings", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Enablement", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Enablement, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetBreadcrumbContextEnablement", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12DeviceRemovedExtendedDataSettings1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Enablement", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Enablement, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("GetAutoBreadcrumbsOutput", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DeviceRemovedExtendedData", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pOutput", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOutput, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetPageFaultAllocationOutput", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DeviceRemovedExtendedData", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pOutput", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOutput, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetAutoBreadcrumbsOutput1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DeviceRemovedExtendedData1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pOutput", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOutput, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetPageFaultAllocationOutput1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DeviceRemovedExtendedData1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pOutput", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOutput, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetBackgroundProcessingMode", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device6", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Mode", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Mode, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "MeasurementsAction", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(MeasurementsAction, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "hEventToSignalUponCompletion", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(hEventToSignalUponCompletion, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pbFurtherMeasurementsDesired", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pbFurtherMeasurementsDesired, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDesc1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12ProtectedResourceSession1", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("AddToStateObject", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device7", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pAddition", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pAddition, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pStateObjectToGrowFrom", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pStateObjectToGrowFrom, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppNewStateObject", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppNewStateObject, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateProtectedResourceSession1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device7", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppSession", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppSession, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetResourceAllocationInfo2", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device8", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "visibleMask", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(visibleMask, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "numResourceDescs", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(numResourceDescs, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pResourceDescs", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(numResourceDescs, pResourceDescs, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pResourceAllocationInfo1", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(numResourceDescs, pResourceAllocationInfo1, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateCommittedResource2", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device8", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pHeapProperties", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pHeapProperties, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "HeapFlags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(HeapFlags, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "InitialResourceState", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(InitialResourceState, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pOptimizedClearValue", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOptimizedClearValue, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pProtectedSession", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pProtectedSession, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riidResource", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riidResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvResource, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreatePlacedResource1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Device8", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pHeap", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pHeap, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "HeapOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(HeapOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "InitialState", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(InitialState, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pOptimizedClearValue", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pOptimizedClearValue, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvResource, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CreateSamplerFeedbackUnorderedAccessView", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device8", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pTargetedResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pTargetedResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pFeedbackResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFeedbackResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DestDescriptor", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(DestDescriptor, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetCopyableFootprints1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Device8", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResourceDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pResourceDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "FirstSubresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(FirstSubresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumSubresources", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumSubresources, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "BaseOffset", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(BaseOffset, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pLayouts", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumSubresources, pLayouts, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pNumRows", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumSubresources, pNumRows, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pRowSizeInBytes", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumSubresources, pRowSizeInBytes, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pTotalBytes", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pTotalBytes, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetProtectedResourceSession", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Resource1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppProtectedSession", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppProtectedSession, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDesc1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Resource2", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetProtectedResourceSession", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Heap1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppProtectedSession", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppProtectedSession, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetProtectedResourceSession", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pProtectedResourceSession", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pProtectedResourceSession, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetRequiredParameterResourceSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12MetaCommand", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Stage", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Stage, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "ParameterIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(ParameterIndex, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("BeginRenderPass", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "NumRenderTargets", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumRenderTargets, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pRenderTargets", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumRenderTargets, pRenderTargets, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pDepthStencil", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDepthStencil, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("EndRenderPass", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList4", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("InitializeMetaCommand", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pMetaCommand", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pMetaCommand, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pInitializationParametersData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(InitializationParametersDataSizeInBytes, pInitializationParametersData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "InitializationParametersDataSizeInBytes", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(InitializationParametersDataSizeInBytes, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ExecuteMetaCommand", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pMetaCommand", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pMetaCommand, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pExecutionParametersData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(ExecutionParametersDataSizeInBytes, pExecutionParametersData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ExecutionParametersDataSizeInBytes", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(ExecutionParametersDataSizeInBytes, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("BuildRaytracingAccelerationStructure", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumPostbuildInfoDescs", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumPostbuildInfoDescs, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pPostbuildInfoDescs", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(NumPostbuildInfoDescs, pPostbuildInfoDescs, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EmitRaytracingAccelerationStructurePostbuildInfo", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "NumSourceAccelerationStructures", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(NumSourceAccelerationStructures, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pSourceAccelerationStructureData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(NumSourceAccelerationStructures, pSourceAccelerationStructureData, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("CopyRaytracingAccelerationStructure", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "DestAccelerationStructureData", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DestAccelerationStructureData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "SourceAccelerationStructureData", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(SourceAccelerationStructureData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Mode", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Mode, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetPipelineState1", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pStateObject", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pStateObject, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("DispatchRays", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList4", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pDesc", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pDesc, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnableShaderInstrumentation", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Tools", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "bEnable", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(bEnable, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ShaderInstrumentationEnabled", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12Tools", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("RSSetShadingRate", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList5", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "baseShadingRate", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(baseShadingRate, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "combiners", toStringFlags, tabCount, tabSize, "TODO 2 : EnumPointerDecoderArrayToString(D3D12_RS_SET_SHADING_RATE_COMBINER_COUNT, combiners, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("RSSetShadingRateImage", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList5", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "shadingRateImage", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(shadingRateImage, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("DispatchMesh", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12GraphicsCommandList6", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ThreadGroupCountX", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(ThreadGroupCountX, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ThreadGroupCountY", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(ThreadGroupCountY, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "ThreadGroupCountZ", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(ThreadGroupCountZ, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetBufferPointer", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D10Blob", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetBufferSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D10Blob", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("RegisterDestructionCallback", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3DDestructionNotifier", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "callbackFn", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(callbackFn, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pCallbackID", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pCallbackID, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("UnregisterDestructionCallback", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3DDestructionNotifier", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "callbackID", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(callbackID, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EnableDebugLayer", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Debug", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("EnableDebugLayer", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Debug1", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("SetEnableGPUBasedValidation", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Debug1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Enable", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Enable, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetEnableSynchronizedCommandQueueValidation", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Debug1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Enable", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Enable, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGPUBasedValidationFlags", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Debug2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetEnableGPUBasedValidation", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Debug3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Enable", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Enable, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetEnableSynchronizedCommandQueueValidation", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Debug3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Enable", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Enable, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetGPUBasedValidationFlags", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12Debug3", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetDebugParameter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugDevice1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSize, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSize, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDebugParameter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugDevice1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSize, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSize, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ReportLiveDeviceObjects", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugDevice1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetFeatureMask", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugDevice", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Mask", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Mask, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("GetFeatureMask", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugDevice", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("ReportLiveDeviceObjects", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugDevice", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Flags", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Flags, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetDebugParameter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugDevice2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSize, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSize, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDebugParameter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugDevice2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSize, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSize, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("AssertResourceState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugCommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Subresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "State", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(State, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("AssertResourceState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugCommandList1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Subresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "State", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(State, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetDebugParameter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugCommandList1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSize, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSize, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDebugParameter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugCommandList1", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSize, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSize, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("AssertResourceState", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Subresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "State", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(State, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetFeatureMask", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugCommandList", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Mask", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Mask, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("GetFeatureMask", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugCommandList", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("SetDebugParameter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugCommandList2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSize, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSize, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetDebugParameter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12DebugCommandList2", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Type", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Type, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, "TODO 3 : PointerDecoderArrayToString(DataSize, pData, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "DataSize", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(DataSize, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("Present", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12SharingContract", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pResource", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pResource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "Subresource", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(Subresource, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "window", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(window, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SharedFenceSignal", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12SharingContract", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pFence", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFence, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "FenceValue", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(FenceValue, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("BeginCapturableWork", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12SharingContract", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "guid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(guid, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("EndCapturableWork", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12SharingContract", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "guid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(guid, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetMessageCountLimit", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "MessageCountLimit", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(MessageCountLimit, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ClearStoredMessages", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMessage(
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 MessageIndex,
        StructPointerDecoder<Decoded_D3D12_MESSAGE>* pMessage,
        PointerDecoder<SIZE_T>* pMessageByteLength)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetMessage", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "MessageIndex", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(MessageIndex, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]pMessage", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(* pMessageByteLength, pMessage, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pMessageByteLength", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pMessageByteLength, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetNumMessagesAllowedByStorageFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetNumMessagesDeniedByStorageFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetNumStoredMessages", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetNumStoredMessagesAllowedByRetrievalFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetNumMessagesDiscardedByMessageCountLimit", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetMessageCountLimit", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("AddStorageFilterEntries", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pFilter", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pFilter, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetStorageFilter(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
        PointerDecoder<SIZE_T>* pFilterByteLength)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetStorageFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pFilter", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(* pFilterByteLength, pFilter, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pFilterByteLength", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFilterByteLength, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ClearStorageFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("PushEmptyStorageFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("PushCopyOfStorageFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("PushStorageFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pFilter", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pFilter, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("PopStorageFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetStorageFilterStackSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("AddRetrievalFilterEntries", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pFilter", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pFilter, toStringFlags, tabCount, tabSize)");
        }
    );
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetRetrievalFilter(
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
        PointerDecoder<SIZE_T>* pFilterByteLength)
{
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFile("GetRetrievalFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "[out]pFilter", toStringFlags, tabCount, tabSize, "TODO 1 : PointerDecoderArrayToString(* pFilterByteLength, pFilter, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "pFilterByteLength", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pFilterByteLength, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("ClearRetrievalFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("PushEmptyRetrievalFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("PushCopyOfRetrievalFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("PushRetrievalFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "pFilter", toStringFlags, tabCount, tabSize, "TODO 5 : PointerDecoderToString(pFilter, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("PopRetrievalFilter", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("GetRetrievalFilterStackSize", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("AddMessage", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Category", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Category, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "Severity", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Severity, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "ID", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(ID, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pDescription", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDescription, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("AddApplicationMessage", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Severity", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Severity, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "pDescription", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(pDescription, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetBreakOnCategory", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Category", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Category, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "bEnable", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(bEnable, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetBreakOnSeverity", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Severity", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Severity, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "bEnable", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(bEnable, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("SetBreakOnID", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ID", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(ID, toStringFlags, tabCount, tabSize) + '"'");
            FieldToString(strStrm, false, "bEnable", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(bEnable, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetBreakOnCategory", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Category", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Category, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("GetBreakOnSeverity", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "Severity", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(Severity, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("GetBreakOnID", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "ID", toStringFlags, tabCount, tabSize, "TODO 14 : '"' + ToString(ID, toStringFlags, tabCount, tabSize) + '"'");
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
    WriteApiCallToFile("SetMuteDebugOutput", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "bMute", toStringFlags, tabCount, tabSize, "TODO 15 : ToString(bMute, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("GetMuteDebugOutput", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("QueryInterface", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IUnknown", to_string_flags, tab_count, tab_size, "nullptr");
            FieldToString(strStrm, false, "riid", toStringFlags, tabCount, tabSize, "TODO 13 : ToString(riid, toStringFlags, tabCount, tabSize)");
            FieldToString(strStrm, false, "[out]ppvObject", toStringFlags, tabCount, tabSize, "TODO 7 : PointerDecoderToString(ppvObject, toStringFlags, tabCount, tabSize)");
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
    WriteApiCallToFile("AddRef", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IUnknown", to_string_flags, tab_count, tab_size, "nullptr");
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
    WriteApiCallToFile("Release", to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "return", to_string_flags, tab_count, tab_size, '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
            FieldToString(str_strm, false, "IUnknown", to_string_flags, tab_count, tab_size, "nullptr");
        }
    );
}



GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
