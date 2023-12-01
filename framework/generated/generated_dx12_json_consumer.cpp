/*
** Copyright (c) 2021-2023 LunarG, Inc.
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
** This file is generated from dx12_json_consumer_body_generator.py.
**
*/

#include "generated_dx12_json_consumer.h"
#include "generated_dx12_enum_to_json.h"
#include "generated_dx12_struct_decoders_to_json.h"
#include "decode/dx12_enum_util.h"
#include "decode/decode_json_util.h"
#include "decode/json_writer.h"
#include "util/to_string.h"
#include "format/format_json.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/*
** This part is generated from dxgi.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12JsonConsumer::Process_CreateDXGIFactory(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "CreateDXGIFactory");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppFactory"], ppFactory, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_CreateDXGIFactory1(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "CreateDXGIFactory1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppFactory"], ppFactory, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_IDXGIObject_SetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIObject", object_id, "SetPrivateData");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Name"], Name, options);
        FieldToJson(args["DataSize"], DataSize, options);
        FieldToJson(args["pData"], pData, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIObject_SetPrivateDataInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        format::HandleId pUnknown)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIObject", object_id, "SetPrivateDataInterface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Name"], Name, options);
        FieldToJson(args["pUnknown"], pUnknown, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIObject_GetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIObject", object_id, "GetPrivateData");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Name"], Name, options);
        FieldToJson(args["pDataSize"], pDataSize, options);
        FieldToJson(args["pData"], pData, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIObject_GetParent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParent)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIObject", object_id, "GetParent");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppParent"], ppParent, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDeviceSubObject_GetDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDeviceSubObject", object_id, "GetDevice");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppDevice"], ppDevice, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIResource_GetSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pSharedHandle)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIResource", object_id, "GetSharedHandle");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pSharedHandle"], pSharedHandle, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIResource_GetUsage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<DXGI_USAGE>* pUsage)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIResource", object_id, "GetUsage");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pUsage"], pUsage, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIResource_SetEvictionPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT EvictionPriority)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIResource", object_id, "SetEvictionPriority");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["EvictionPriority"], EvictionPriority, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIResource_GetEvictionPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pEvictionPriority)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIResource", object_id, "GetEvictionPriority");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pEvictionPriority"], pEvictionPriority, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIKeyedMutex_AcquireSync(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Key,
        DWORD dwMilliseconds)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIKeyedMutex", object_id, "AcquireSync");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Key"], Key, options);
        FieldToJson(args["dwMilliseconds"], dwMilliseconds, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIKeyedMutex_ReleaseSync(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Key)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIKeyedMutex", object_id, "ReleaseSync");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Key"], Key, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISurface_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISurface", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISurface_Map(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect,
        UINT MapFlags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISurface", object_id, "Map");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pLockedRect"], pLockedRect, options);
        FieldToJson(args["MapFlags"], MapFlags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISurface_Unmap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISurface", object_id, "Unmap");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISurface1_GetDC(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Discard,
        PointerDecoder<uint64_t, void*>* phdc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISurface1", object_id, "GetDC");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Discard"], Discard, options);
        FieldToJson(args["phdc"], phdc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISurface1_ReleaseDC(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRect)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISurface1", object_id, "ReleaseDC");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDirtyRect"], pDirtyRect, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter_EnumOutputs(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Output,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter", object_id, "EnumOutputs");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Output"], Output, options);
        FieldToJson(args["ppOutput"], ppOutput, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter_CheckInterfaceSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID InterfaceName,
        StructPointerDecoder<Decoded_LARGE_INTEGER>* pUMDVersion)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter", object_id, "CheckInterfaceSupport");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["InterfaceName"], InterfaceName, options);
        FieldToJson(args["pUMDVersion"], pUMDVersion, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_GetDisplayModeList(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "GetDisplayModeList");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["EnumFormat"], EnumFormat, options);
        FieldToJson(args["Flags"], Flags, options);
        FieldToJson(args["pNumModes"], pNumModes, options);
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_FindClosestMatchingMode(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pClosestMatch,
        format::HandleId pConcernedDevice)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "FindClosestMatchingMode");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pModeToMatch"], pModeToMatch, options);
        FieldToJson(args["pClosestMatch"], pClosestMatch, options);
        FieldToJson(args["pConcernedDevice"], pConcernedDevice, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_WaitForVBlank(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "WaitForVBlank");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_TakeOwnership(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        BOOL Exclusive)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "TakeOwnership");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDevice"], pDevice, options);
        Bool32ToJson(args["Exclusive"], Exclusive, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_ReleaseOwnership(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "ReleaseOwnership");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_GetGammaControlCapabilities(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES>* pGammaCaps)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "GetGammaControlCapabilities");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pGammaCaps"], pGammaCaps, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_SetGammaControl(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "SetGammaControl");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pArray"], pArray, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_GetGammaControl(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "GetGammaControl");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pArray"], pArray, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_SetDisplaySurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pScanoutSurface)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "SetDisplaySurface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pScanoutSurface"], pScanoutSurface, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_GetDisplaySurfaceData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDestination)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "GetDisplaySurfaceData");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDestination"], pDestination, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_GetFrameStatistics(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "GetFrameStatistics");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pStats"], pStats, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain_Present(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT SyncInterval,
        UINT Flags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain", object_id, "Present");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["SyncInterval"], SyncInterval, options);
        FieldToJson(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain_GetBuffer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Buffer,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSurface)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain", object_id, "GetBuffer");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Buffer"], Buffer, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppSurface"], ppSurface, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain_SetFullscreenState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Fullscreen,
        format::HandleId pTarget)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain", object_id, "SetFullscreenState");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Fullscreen"], Fullscreen, options);
        FieldToJson(args["pTarget"], pTarget, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain_GetFullscreenState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<BOOL>* pFullscreen,
        HandlePointerDecoder<IDXGIOutput*>* ppTarget)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain", object_id, "GetFullscreenState");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["pFullscreen"], pFullscreen, options);
        FieldToJson(args["ppTarget"], ppTarget, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain_ResizeBuffers(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain", object_id, "ResizeBuffers");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["BufferCount"], BufferCount, options);
        FieldToJson(args["Width"], Width, options);
        FieldToJson(args["Height"], Height, options);
        FieldToJson(args["NewFormat"], NewFormat, options);
        FieldToJson(args["SwapChainFlags"], SwapChainFlags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain_ResizeTarget(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pNewTargetParameters)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain", object_id, "ResizeTarget");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pNewTargetParameters"], pNewTargetParameters, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain_GetContainingOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain", object_id, "GetContainingOutput");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ppOutput"], ppOutput, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain_GetFrameStatistics(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain", object_id, "GetFrameStatistics");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pStats"], pStats, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain_GetLastPresentCount(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pLastPresentCount)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain", object_id, "GetLastPresentCount");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pLastPresentCount"], pLastPresentCount, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory_EnumAdapters(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory", object_id, "EnumAdapters");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Adapter"], Adapter, options);
        FieldToJson(args["ppAdapter"], ppAdapter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory_MakeWindowAssociation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT Flags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory", object_id, "MakeWindowAssociation");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["WindowHandle"], WindowHandle, options);
        FieldToJson(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory_GetWindowAssociation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pWindowHandle)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory", object_id, "GetWindowAssociation");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pWindowHandle"], pWindowHandle, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory_CreateSwapChain(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc,
        HandlePointerDecoder<IDXGISwapChain*>* ppSwapChain)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory", object_id, "CreateSwapChain");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDevice"], pDevice, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["ppSwapChain"], ppSwapChain, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory_CreateSoftwareAdapter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t Module,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory", object_id, "CreateSoftwareAdapter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Module"], Module, options);
        FieldToJson(args["ppAdapter"], ppAdapter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice_GetAdapter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIAdapter*>* pAdapter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice", object_id, "GetAdapter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pAdapter"], pAdapter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice_CreateSurface(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice", object_id, "CreateSurface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["NumSurfaces"], NumSurfaces, options);
        FieldToJson(args["Usage"], Usage, options);
        FieldToJson(args["pSharedResource"], pSharedResource, options);
        FieldToJson(args["ppSurface"], ppSurface, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice_QueryResourceResidency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IUnknown*>* ppResources,
        PointerDecoder<DXGI_RESIDENCY>* pResidencyStatus,
        UINT NumResources)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice", object_id, "QueryResourceResidency");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ppResources"], ppResources, options);
        FieldToJson(args["pResidencyStatus"], pResidencyStatus, options);
        FieldToJson(args["NumResources"], NumResources, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice_SetGPUThreadPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        INT Priority)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice", object_id, "SetGPUThreadPriority");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Priority"], Priority, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice_GetGPUThreadPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<INT>* pPriority)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice", object_id, "GetGPUThreadPriority");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pPriority"], pPriority, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory1_EnumAdapters1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter1*>* ppAdapter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory1", object_id, "EnumAdapters1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Adapter"], Adapter, options);
        FieldToJson(args["ppAdapter"], ppAdapter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory1_IsCurrent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory1", object_id, "IsCurrent");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter1_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter1", object_id, "GetDesc1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice1_SetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT MaxLatency)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice1", object_id, "SetMaximumFrameLatency");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["MaxLatency"], MaxLatency, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice1_GetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pMaxLatency)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice1", object_id, "GetMaximumFrameLatency");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pMaxLatency"], pMaxLatency, options);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12JsonConsumer::Process_IDXGIDisplayControl_IsStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDisplayControl", object_id, "IsStereoEnabled");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDisplayControl_SetStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL enabled)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDisplayControl", object_id, "SetStereoEnabled");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["enabled"], enabled, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutputDuplication_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutputDuplication", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutputDuplication_AcquireNextFrame(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT TimeoutInMilliseconds,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_FRAME_INFO>* pFrameInfo,
        HandlePointerDecoder<IDXGIResource*>* ppDesktopResource)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutputDuplication", object_id, "AcquireNextFrame");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["TimeoutInMilliseconds"], TimeoutInMilliseconds, options);
        FieldToJson(args["pFrameInfo"], pFrameInfo, options);
        FieldToJson(args["ppDesktopResource"], ppDesktopResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutputDuplication_GetFrameDirtyRects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT DirtyRectsBufferSize,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRectsBuffer,
        PointerDecoder<UINT>* pDirtyRectsBufferSizeRequired)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutputDuplication", object_id, "GetFrameDirtyRects");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["DirtyRectsBufferSize"], DirtyRectsBufferSize, options);
        FieldToJson(args["pDirtyRectsBuffer"], pDirtyRectsBuffer, options);
        FieldToJson(args["pDirtyRectsBufferSizeRequired"], pDirtyRectsBufferSizeRequired, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutputDuplication_GetFrameMoveRects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT MoveRectsBufferSize,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_MOVE_RECT>* pMoveRectBuffer,
        PointerDecoder<UINT>* pMoveRectsBufferSizeRequired)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutputDuplication", object_id, "GetFrameMoveRects");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["MoveRectsBufferSize"], MoveRectsBufferSize, options);
        FieldToJson(args["pMoveRectBuffer"], pMoveRectBuffer, options);
        FieldToJson(args["pMoveRectsBufferSizeRequired"], pMoveRectsBufferSizeRequired, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutputDuplication_GetFramePointerShape(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT PointerShapeBufferSize,
        PointerDecoder<uint8_t>* pPointerShapeBuffer,
        PointerDecoder<UINT>* pPointerShapeBufferSizeRequired,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO>* pPointerShapeInfo)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutputDuplication", object_id, "GetFramePointerShape");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["PointerShapeBufferSize"], PointerShapeBufferSize, options);
        FieldToJson(args["pPointerShapeBuffer"], pPointerShapeBuffer, options);
        FieldToJson(args["pPointerShapeBufferSizeRequired"], pPointerShapeBufferSizeRequired, options);
        FieldToJson(args["pPointerShapeInfo"], pPointerShapeInfo, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutputDuplication_MapDesktopSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutputDuplication", object_id, "MapDesktopSurface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pLockedRect"], pLockedRect, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutputDuplication_UnMapDesktopSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutputDuplication", object_id, "UnMapDesktopSurface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutputDuplication_ReleaseFrame(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutputDuplication", object_id, "ReleaseFrame");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISurface2_GetResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParentResource,
        PointerDecoder<UINT>* pSubresourceIndex)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISurface2", object_id, "GetResource");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppParentResource"], ppParentResource, options);
        FieldToJson(args["pSubresourceIndex"], pSubresourceIndex, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIResource1_CreateSubresourceSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT index,
        HandlePointerDecoder<IDXGISurface2*>* ppSurface)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIResource1", object_id, "CreateSubresourceSurface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["index"], index, options);
        FieldToJson(args["ppSurface"], ppSurface, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIResource1_CreateSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD dwAccess,
        WStringDecoder* lpName,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIResource1", object_id, "CreateSharedHandle");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pAttributes"], pAttributes, options);
        FieldToJson(args["dwAccess"], dwAccess, options);
        FieldToJson(args["lpName"], lpName, options);
        FieldToJson(args["pHandle"], pHandle, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice2_OfferResources(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice2", object_id, "OfferResources");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumResources"], NumResources, options);
        FieldToJson(args["ppResources"], ppResources, options);
        FieldToJson(args["Priority"], Priority, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice2_ReclaimResources(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<BOOL>* pDiscarded)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice2", object_id, "ReclaimResources");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumResources"], NumResources, options);
        FieldToJson(args["ppResources"], ppResources, options);
        Bool32ToJson(args["pDiscarded"], pDiscarded, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice2_EnqueueSetEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice2", object_id, "EnqueueSetEvent");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["hEvent"], hEvent, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "GetDesc1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_GetFullscreenDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "GetFullscreenDesc");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_GetHwnd(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pHwnd)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "GetHwnd");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHwnd"], pHwnd, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_GetCoreWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID refiid,
        HandlePointerDecoder<void*>* ppUnk)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "GetCoreWindow");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["refiid"], refiid, options);
        FieldToJson(args["ppUnk"], ppUnk, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_Present1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT SyncInterval,
        UINT PresentFlags,
        StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* pPresentParameters)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "Present1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["SyncInterval"], SyncInterval, options);
        FieldToJson(args["PresentFlags"], PresentFlags, options);
        FieldToJson(args["pPresentParameters"], pPresentParameters, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_IsTemporaryMonoSupported(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "IsTemporaryMonoSupported");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_GetRestrictToOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIOutput*>* ppRestrictToOutput)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "GetRestrictToOutput");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ppRestrictToOutput"], ppRestrictToOutput, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_SetBackgroundColor(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "SetBackgroundColor");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pColor"], pColor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_GetBackgroundColor(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "GetBackgroundColor");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pColor"], pColor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_SetRotation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_MODE_ROTATION Rotation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "SetRotation");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Rotation"], Rotation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain1_GetRotation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<DXGI_MODE_ROTATION>* pRotation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain1", object_id, "GetRotation");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRotation"], pRotation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_IsWindowedStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "IsWindowedStereoEnabled");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_CreateSwapChainForHwnd(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "CreateSwapChainForHwnd");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDevice"], pDevice, options);
        FieldToJson(args["hWnd"], hWnd, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["pFullscreenDesc"], pFullscreenDesc, options);
        FieldToJson(args["pRestrictToOutput"], pRestrictToOutput, options);
        FieldToJson(args["ppSwapChain"], ppSwapChain, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_CreateSwapChainForCoreWindow(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "CreateSwapChainForCoreWindow");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDevice"], pDevice, options);
        FieldToJson(args["pWindow"], pWindow, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["pRestrictToOutput"], pRestrictToOutput, options);
        FieldToJson(args["ppSwapChain"], ppSwapChain, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_GetSharedResourceAdapterLuid(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hResource,
        StructPointerDecoder<Decoded_LUID>* pLuid)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "GetSharedResourceAdapterLuid");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["hResource"], hResource, options);
        FieldToJson(args["pLuid"], pLuid, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_RegisterStereoStatusWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "RegisterStereoStatusWindow");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["WindowHandle"], WindowHandle, options);
        FieldToJson(args["wMsg"], wMsg, options);
        FieldToJson(args["pdwCookie"], pdwCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_RegisterStereoStatusEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "RegisterStereoStatusEvent");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["hEvent"], hEvent, options);
        FieldToJson(args["pdwCookie"], pdwCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_UnregisterStereoStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "UnregisterStereoStatus");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["dwCookie"], dwCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "RegisterOcclusionStatusWindow");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["WindowHandle"], WindowHandle, options);
        FieldToJson(args["wMsg"], wMsg, options);
        FieldToJson(args["pdwCookie"], pdwCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "RegisterOcclusionStatusEvent");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["hEvent"], hEvent, options);
        FieldToJson(args["pdwCookie"], pdwCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_UnregisterOcclusionStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "UnregisterOcclusionStatus");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["dwCookie"], dwCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory2_CreateSwapChainForComposition(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory2", object_id, "CreateSwapChainForComposition");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDevice"], pDevice, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["pRestrictToOutput"], pRestrictToOutput, options);
        FieldToJson(args["ppSwapChain"], ppSwapChain, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter2_GetDesc2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter2", object_id, "GetDesc2");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput1_GetDisplayModeList1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput1", object_id, "GetDisplayModeList1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["EnumFormat"], EnumFormat, options);
        FieldToJson(args["Flags"], Flags, options);
        FieldToJson(args["pNumModes"], pNumModes, options);
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput1_FindClosestMatchingMode1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pClosestMatch,
        format::HandleId pConcernedDevice)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput1", object_id, "FindClosestMatchingMode1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pModeToMatch"], pModeToMatch, options);
        FieldToJson(args["pClosestMatch"], pClosestMatch, options);
        FieldToJson(args["pConcernedDevice"], pConcernedDevice, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput1_GetDisplaySurfaceData1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDestination)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput1", object_id, "GetDisplaySurfaceData1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDestination"], pDestination, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput1_DuplicateOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput1", object_id, "DuplicateOutput");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDevice"], pDevice, options);
        FieldToJson(args["ppOutputDuplication"], ppOutputDuplication, options);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12JsonConsumer::Process_CreateDXGIFactory2(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "CreateDXGIFactory2");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["Flags"], Flags, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppFactory"], ppFactory, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_DXGIGetDebugInterface1(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* pDebug)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "DXGIGetDebugInterface1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["Flags"], Flags, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["pDebug"], pDebug, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_IDXGIDevice3_Trim(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice3", object_id, "Trim");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain2_SetSourceSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Width,
        UINT Height)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain2", object_id, "SetSourceSize");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Width"], Width, options);
        FieldToJson(args["Height"], Height, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain2_GetSourceSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain2", object_id, "GetSourceSize");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pWidth"], pWidth, options);
        FieldToJson(args["pHeight"], pHeight, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain2_SetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT MaxLatency)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain2", object_id, "SetMaximumFrameLatency");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["MaxLatency"], MaxLatency, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain2_GetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pMaxLatency)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain2", object_id, "GetMaximumFrameLatency");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pMaxLatency"], pMaxLatency, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        uint64_t return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain2", object_id, "GetFrameLatencyWaitableObject");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain2_SetMatrixTransform(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain2", object_id, "SetMatrixTransform");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pMatrix"], pMatrix, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain2_GetMatrixTransform(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain2", object_id, "GetMatrixTransform");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pMatrix"], pMatrix, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput2_SupportsOverlays(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput2", object_id, "SupportsOverlays");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory3_GetCreationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory3", object_id, "GetCreationFlags");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDecodeSwapChain_PresentBuffer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT BufferToPresent,
        UINT SyncInterval,
        UINT Flags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDecodeSwapChain", object_id, "PresentBuffer");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["BufferToPresent"], BufferToPresent, options);
        FieldToJson(args["SyncInterval"], SyncInterval, options);
        FieldToJson(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDecodeSwapChain_SetSourceRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDecodeSwapChain", object_id, "SetSourceRect");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRect"], pRect, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDecodeSwapChain_SetTargetRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDecodeSwapChain", object_id, "SetTargetRect");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRect"], pRect, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDecodeSwapChain_SetDestSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Width,
        UINT Height)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDecodeSwapChain", object_id, "SetDestSize");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Width"], Width, options);
        FieldToJson(args["Height"], Height, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDecodeSwapChain_GetSourceRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDecodeSwapChain", object_id, "GetSourceRect");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRect"], pRect, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDecodeSwapChain_GetTargetRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDecodeSwapChain", object_id, "GetTargetRect");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRect"], pRect, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDecodeSwapChain_GetDestSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDecodeSwapChain", object_id, "GetDestSize");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pWidth"], pWidth, options);
        FieldToJson(args["pHeight"], pHeight, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDecodeSwapChain_SetColorSpace(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDecodeSwapChain", object_id, "SetColorSpace");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson_DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS(args["ColorSpace"], ColorSpace, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDecodeSwapChain_GetColorSpace(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDecodeSwapChain", object_id, "GetColorSpace");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson_DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactoryMedia", object_id, "CreateSwapChainForCompositionSurfaceHandle");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDevice"], pDevice, options);
        FieldToJson(args["hSurface"], hSurface, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["pRestrictToOutput"], pRestrictToOutput, options);
        FieldToJson(args["ppSwapChain"], ppSwapChain, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactoryMedia", object_id, "CreateDecodeSwapChainForCompositionSurfaceHandle");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDevice"], pDevice, options);
        FieldToJson(args["hSurface"], hSurface, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["pYuvDecodeBuffers"], pYuvDecodeBuffers, options);
        FieldToJson(args["pRestrictToOutput"], pRestrictToOutput, options);
        FieldToJson(args["ppSwapChain"], ppSwapChain, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA>* pStats)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChainMedia", object_id, "GetFrameStatisticsMedia");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pStats"], pStats, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChainMedia_SetPresentDuration(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Duration)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChainMedia", object_id, "SetPresentDuration");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Duration"], Duration, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChainMedia_CheckPresentDurationSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT DesiredPresentDuration,
        PointerDecoder<UINT>* pClosestSmallerPresentDuration,
        PointerDecoder<UINT>* pClosestLargerPresentDuration)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChainMedia", object_id, "CheckPresentDurationSupport");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["DesiredPresentDuration"], DesiredPresentDuration, options);
        FieldToJson(args["pClosestSmallerPresentDuration"], pClosestSmallerPresentDuration, options);
        FieldToJson(args["pClosestLargerPresentDuration"], pClosestLargerPresentDuration, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput3_CheckOverlaySupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        format::HandleId pConcernedDevice,
        PointerDecoder<UINT>* pFlags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput3", object_id, "CheckOverlaySupport");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["EnumFormat"], EnumFormat, options);
        FieldToJson(args["pConcernedDevice"], pConcernedDevice, options);
        FieldToJson(args["pFlags"], pFlags, options);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12JsonConsumer::Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain3", object_id, "GetCurrentBackBufferIndex");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain3_CheckColorSpaceSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        PointerDecoder<UINT>* pColorSpaceSupport)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain3", object_id, "CheckColorSpaceSupport");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ColorSpace"], ColorSpace, options);
        FieldToJson(args["pColorSpaceSupport"], pColorSpaceSupport, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain3_SetColorSpace1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_COLOR_SPACE_TYPE ColorSpace)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain3", object_id, "SetColorSpace1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ColorSpace"], ColorSpace, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain3_ResizeBuffers1(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain3", object_id, "ResizeBuffers1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["BufferCount"], BufferCount, options);
        FieldToJson(args["Width"], Width, options);
        FieldToJson(args["Height"], Height, options);
        FieldToJson(args["Format"], Format, options);
        FieldToJson(args["SwapChainFlags"], SwapChainFlags, options);
        FieldToJsonAsFixedWidthBinary(args["pCreationNodeMask"], pCreationNodeMask, options);
        FieldToJson(args["ppPresentQueue"], ppPresentQueue, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput4_CheckOverlayColorSpaceSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT Format,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        format::HandleId pConcernedDevice,
        PointerDecoder<UINT>* pFlags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput4", object_id, "CheckOverlayColorSpaceSupport");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Format"], Format, options);
        FieldToJson(args["ColorSpace"], ColorSpace, options);
        FieldToJson(args["pConcernedDevice"], pConcernedDevice, options);
        FieldToJson(args["pFlags"], pFlags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory4_EnumAdapterByLuid(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_LUID AdapterLuid,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory4", object_id, "EnumAdapterByLuid");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["AdapterLuid"], AdapterLuid, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvAdapter"], ppvAdapter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory4_EnumWarpAdapter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory4", object_id, "EnumWarpAdapter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvAdapter"], ppvAdapter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter3", object_id, "RegisterHardwareContentProtectionTeardownStatusEvent");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["hEvent"], hEvent, options);
        FieldToJson(args["pdwCookie"], pdwCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter3", object_id, "UnregisterHardwareContentProtectionTeardownStatus");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["dwCookie"], dwCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter3_QueryVideoMemoryInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        StructPointerDecoder<Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO>* pVideoMemoryInfo)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter3", object_id, "QueryVideoMemoryInfo");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NodeIndex"], NodeIndex, options);
        FieldToJson(args["MemorySegmentGroup"], MemorySegmentGroup, options);
        FieldToJson(args["pVideoMemoryInfo"], pVideoMemoryInfo, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter3_SetVideoMemoryReservation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        UINT64 Reservation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter3", object_id, "SetVideoMemoryReservation");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NodeIndex"], NodeIndex, options);
        FieldToJson(args["MemorySegmentGroup"], MemorySegmentGroup, options);
        FieldToJson(args["Reservation"], Reservation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter3", object_id, "RegisterVideoMemoryBudgetChangeNotificationEvent");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["hEvent"], hEvent, options);
        FieldToJson(args["pdwCookie"], pdwCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter3", object_id, "UnregisterVideoMemoryBudgetChangeNotification");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["dwCookie"], dwCookie, options);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12JsonConsumer::Process_IDXGIOutput5_DuplicateOutput1(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput5", object_id, "DuplicateOutput1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDevice"], pDevice, options);
        FieldToJson(args["Flags"], Flags, options);
        FieldToJson(args["SupportedFormatsCount"], SupportedFormatsCount, options);
        FieldToJson(args["pSupportedFormats"], pSupportedFormats, options);
        FieldToJson(args["ppOutputDuplication"], ppOutputDuplication, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGISwapChain4_SetHDRMetaData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_HDR_METADATA_TYPE Type,
        UINT Size,
        PointerDecoder<uint8_t>* pMetaData)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain4", object_id, "SetHDRMetaData");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["Size"], Size, options);
        FieldToJson(args["pMetaData"], pMetaData, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice4_OfferResources1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority,
        UINT Flags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice4", object_id, "OfferResources1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumResources"], NumResources, options);
        FieldToJson(args["ppResources"], ppResources, options);
        FieldToJson(args["Priority"], Priority, options);
        FieldToJson(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDevice4_ReclaimResources1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<DXGI_RECLAIM_RESOURCE_RESULTS>* pResults)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice4", object_id, "ReclaimResources1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumResources"], NumResources, options);
        FieldToJson(args["ppResources"], ppResources, options);
        FieldToJson(args["pResults"], pResults, options);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12JsonConsumer::Process_DXGIDeclareAdapterRemovalSupport(
        const ApiCallInfo& call_info,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "DXGIDeclareAdapterRemovalSupport");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_IDXGIAdapter4_GetDesc3(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIAdapter4", object_id, "GetDesc3");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput6_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput6", object_id, "GetDesc1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput6_CheckHardwareCompositionSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pFlags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput6", object_id, "CheckHardwareCompositionSupport");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFlags"], pFlags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory6_EnumAdapterByGpuPreference(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        DXGI_GPU_PREFERENCE GpuPreference,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory6", object_id, "EnumAdapterByGpuPreference");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Adapter"], Adapter, options);
        FieldToJson(args["GpuPreference"], GpuPreference, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvAdapter"], ppvAdapter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory7_RegisterAdaptersChangedEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory7", object_id, "RegisterAdaptersChangedEvent");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["hEvent"], hEvent, options);
        FieldToJson(args["pdwCookie"], pdwCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DWORD dwCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory7", object_id, "UnregisterAdaptersChangedEvent");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["dwCookie"], dwCookie, options);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from d3d12.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12JsonConsumer::Process_D3D12SerializeRootSignature(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* pRootSignature,
        D3D_ROOT_SIGNATURE_VERSION Version,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "D3D12SerializeRootSignature");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["pRootSignature"], pRootSignature, options);
        FieldToJson(args["Version"], Version, options);
        FieldToJson(args["ppBlob"], ppBlob, options);
        FieldToJson(args["ppErrorBlob"], ppErrorBlob, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_D3D12CreateRootSignatureDeserializer(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        Decoded_GUID pRootSignatureDeserializerInterface,
        HandlePointerDecoder<void*>* ppRootSignatureDeserializer)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "D3D12CreateRootSignatureDeserializer");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["pSrcData"], pSrcData, options);
        FieldToJson(args["SrcDataSizeInBytes"], SrcDataSizeInBytes, options);
        FieldToJson(args["pRootSignatureDeserializerInterface"], pRootSignatureDeserializerInterface, options);
        FieldToJson(args["ppRootSignatureDeserializer"], ppRootSignatureDeserializer, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_D3D12SerializeVersionedRootSignature(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pRootSignature,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "D3D12SerializeVersionedRootSignature");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["pRootSignature"], pRootSignature, options);
        FieldToJson(args["ppBlob"], ppBlob, options);
        FieldToJson(args["ppErrorBlob"], ppErrorBlob, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_D3D12CreateVersionedRootSignatureDeserializer(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        Decoded_GUID pRootSignatureDeserializerInterface,
        HandlePointerDecoder<void*>* ppRootSignatureDeserializer)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "D3D12CreateVersionedRootSignatureDeserializer");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["pSrcData"], pSrcData, options);
        FieldToJson(args["SrcDataSizeInBytes"], SrcDataSizeInBytes, options);
        FieldToJson(args["pRootSignatureDeserializerInterface"], pRootSignatureDeserializerInterface, options);
        FieldToJson(args["ppRootSignatureDeserializer"], ppRootSignatureDeserializer, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_D3D12CreateDevice(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        format::HandleId pAdapter,
        D3D_FEATURE_LEVEL MinimumFeatureLevel,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "D3D12CreateDevice");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["pAdapter"], pAdapter, options);
        FieldToJson(args["MinimumFeatureLevel"], MinimumFeatureLevel, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppDevice"], ppDevice, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_D3D12GetDebugInterface(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDebug)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "D3D12GetDebugInterface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvDebug"], ppvDebug, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_D3D12EnableExperimentalFeatures(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        UINT NumFeatures,
        StructPointerDecoder<Decoded_GUID>* pIIDs,
        PointerDecoder<uint8_t>* pConfigurationStructs,
        PointerDecoder<UINT>* pConfigurationStructSizes)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "D3D12EnableExperimentalFeatures");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["NumFeatures"], NumFeatures, options);
        FieldToJson(args["pIIDs"], pIIDs, options);
        FieldToJson(args["pConfigurationStructs"], pConfigurationStructs, options);
        FieldToJson(args["pConfigurationStructSizes"], pConfigurationStructSizes, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_D3D12GetInterface(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID rclsid,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDebug)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "D3D12GetInterface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(function[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["rclsid"], rclsid, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvDebug"], ppvDebug, options);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_ID3D12Object_GetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Object", object_id, "GetPrivateData");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["guid"], guid, options);
        FieldToJson(args["pDataSize"], pDataSize, options);
        FieldToJson(args["pData"], pData, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Object_SetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Object", object_id, "SetPrivateData");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["guid"], guid, options);
        FieldToJson(args["DataSize"], DataSize, options);
        FieldToJson(args["pData"], pData, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Object_SetPrivateDataInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        format::HandleId pData)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Object", object_id, "SetPrivateDataInterface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["guid"], guid, options);
        FieldToJson(args["pData"], pData, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Object_SetName(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* Name)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Object", object_id, "SetName");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Name"], Name, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceChild_GetDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDevice)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceChild", object_id, "GetDevice");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvDevice"], ppvDevice, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12RootSignatureDeserializer", object_id, "GetRootSignatureDesc");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D_ROOT_SIGNATURE_VERSION convertToVersion,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* ppDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12VersionedRootSignatureDeserializer", object_id, "GetRootSignatureDescAtVersion");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["convertToVersion"], convertToVersion, options);
        FieldToJson(args["ppDesc"], ppDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12VersionedRootSignatureDeserializer", object_id, "GetUnconvertedRootSignatureDesc");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Heap_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_HEAP_DESC return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Heap", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Resource_Map(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pReadRange,
        PointerDecoder<uint64_t, void*>* ppData)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Resource", object_id, "Map");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["pReadRange"], pReadRange, options);
        FieldToJson(args["ppData"], ppData, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Resource_Unmap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pWrittenRange)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Resource", object_id, "Unmap");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["pWrittenRange"], pWrittenRange, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Resource_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Resource", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Resource_GetGPUVirtualAddress(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Resource", object_id, "GetGPUVirtualAddress");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJsonAsHex(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Resource_ReadFromSubresource(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Resource", object_id, "ReadFromSubresource");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDstData"], pDstData, options);
        FieldToJson(args["DstRowPitch"], DstRowPitch, options);
        FieldToJson(args["DstDepthPitch"], DstDepthPitch, options);
        FieldToJson(args["SrcSubresource"], SrcSubresource, options);
        FieldToJson(args["pSrcBox"], pSrcBox, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Resource_GetHeapProperties(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        PointerDecoder<D3D12_HEAP_FLAGS>* pHeapFlags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Resource", object_id, "GetHeapProperties");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeapProperties"], pHeapProperties, options);
        FieldToJson_D3D12_HEAP_FLAGS(args["pHeapFlags"], *pHeapFlags->GetPointer(), options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandAllocator_Reset(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandAllocator", object_id, "Reset");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Fence_GetCompletedValue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Fence", object_id, "GetCompletedValue");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Fence_SetEventOnCompletion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Value,
        uint64_t hEvent)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Fence", object_id, "SetEventOnCompletion");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Value"], Value, options);
        FieldToJson(args["hEvent"], hEvent, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Fence_Signal(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Fence", object_id, "Signal");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Value"], Value, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Fence1_GetCreationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_FENCE_FLAGS return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Fence1", object_id, "GetCreationFlags");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson_D3D12_FENCE_FLAGS(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12PipelineState_GetCachedBlob(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12PipelineState", object_id, "GetCachedBlob");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ppBlob"], ppBlob, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DescriptorHeap_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_DESCRIPTOR_HEAP_DESC return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DescriptorHeap", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DescriptorHeap", object_id, "GetCPUDescriptorHandleForHeapStart");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DescriptorHeap", object_id, "GetGPUDescriptorHandleForHeapStart");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandList_GetType(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_COMMAND_LIST_TYPE return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandList", object_id, "GetType");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_Close(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "Close");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_Reset(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pAllocator,
        format::HandleId pInitialState)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "Reset");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pAllocator"], pAllocator, options);
        FieldToJson(args["pInitialState"], pInitialState, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_ClearState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pPipelineState)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "ClearState");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pPipelineState"], pPipelineState, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_DrawInstanced(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT VertexCountPerInstance,
        UINT InstanceCount,
        UINT StartVertexLocation,
        UINT StartInstanceLocation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "DrawInstanced");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["VertexCountPerInstance"], VertexCountPerInstance, options);
        FieldToJson(args["InstanceCount"], InstanceCount, options);
        FieldToJson(args["StartVertexLocation"], StartVertexLocation, options);
        FieldToJson(args["StartInstanceLocation"], StartInstanceLocation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT IndexCountPerInstance,
        UINT InstanceCount,
        UINT StartIndexLocation,
        INT BaseVertexLocation,
        UINT StartInstanceLocation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "DrawIndexedInstanced");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["IndexCountPerInstance"], IndexCountPerInstance, options);
        FieldToJson(args["InstanceCount"], InstanceCount, options);
        FieldToJson(args["StartIndexLocation"], StartIndexLocation, options);
        FieldToJson(args["BaseVertexLocation"], BaseVertexLocation, options);
        FieldToJson(args["StartInstanceLocation"], StartInstanceLocation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_Dispatch(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "Dispatch");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ThreadGroupCountX"], ThreadGroupCountX, options);
        FieldToJson(args["ThreadGroupCountY"], ThreadGroupCountY, options);
        FieldToJson(args["ThreadGroupCountZ"], ThreadGroupCountZ, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_CopyBufferRegion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstBuffer,
        UINT64 DstOffset,
        format::HandleId pSrcBuffer,
        UINT64 SrcOffset,
        UINT64 NumBytes)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "CopyBufferRegion");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDstBuffer"], pDstBuffer, options);
        FieldToJson(args["DstOffset"], DstOffset, options);
        FieldToJson(args["pSrcBuffer"], pSrcBuffer, options);
        FieldToJson(args["SrcOffset"], SrcOffset, options);
        FieldToJson(args["NumBytes"], NumBytes, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_CopyTextureRegion(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "CopyTextureRegion");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDst"], pDst, options);
        FieldToJson(args["DstX"], DstX, options);
        FieldToJson(args["DstY"], DstY, options);
        FieldToJson(args["DstZ"], DstZ, options);
        FieldToJson(args["pSrc"], pSrc, options);
        FieldToJson(args["pSrcBox"], pSrcBox, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_CopyResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstResource,
        format::HandleId pSrcResource)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "CopyResource");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDstResource"], pDstResource, options);
        FieldToJson(args["pSrcResource"], pSrcResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_CopyTiles(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "CopyTiles");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pTiledResource"], pTiledResource, options);
        FieldToJson(args["pTileRegionStartCoordinate"], pTileRegionStartCoordinate, options);
        FieldToJson(args["pTileRegionSize"], pTileRegionSize, options);
        FieldToJson(args["pBuffer"], pBuffer, options);
        FieldToJson(args["BufferStartOffsetInBytes"], BufferStartOffsetInBytes, options);
        FieldToJson_D3D12_TILE_COPY_FLAGS(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_ResolveSubresource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstResource,
        UINT DstSubresource,
        format::HandleId pSrcResource,
        UINT SrcSubresource,
        DXGI_FORMAT Format)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "ResolveSubresource");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDstResource"], pDstResource, options);
        FieldToJson(args["DstSubresource"], DstSubresource, options);
        FieldToJson(args["pSrcResource"], pSrcResource, options);
        FieldToJson(args["SrcSubresource"], SrcSubresource, options);
        FieldToJson(args["Format"], Format, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D_PRIMITIVE_TOPOLOGY PrimitiveTopology)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "IASetPrimitiveTopology");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["PrimitiveTopology"], PrimitiveTopology, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_RSSetViewports(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumViewports,
        StructPointerDecoder<Decoded_D3D12_VIEWPORT>* pViewports)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "RSSetViewports");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumViewports"], NumViewports, options);
        FieldToJson(args["pViewports"], pViewports, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_RSSetScissorRects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "RSSetScissorRects");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumRects"], NumRects, options);
        FieldToJson(args["pRects"], pRects, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_OMSetBlendFactor(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        PointerDecoder<FLOAT> BlendFactor [4])
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "OMSetBlendFactor");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["BlendFactor"], BlendFactor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_OMSetStencilRef(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT StencilRef)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "OMSetStencilRef");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["StencilRef"], StencilRef, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetPipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pPipelineState)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetPipelineState");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pPipelineState"], pPipelineState, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_ResourceBarrier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumBarriers,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "ResourceBarrier");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumBarriers"], NumBarriers, options);
        FieldToJson(args["pBarriers"], pBarriers, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_ExecuteBundle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pCommandList)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "ExecuteBundle");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pCommandList"], pCommandList, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumDescriptorHeaps,
        HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetDescriptorHeaps");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumDescriptorHeaps"], NumDescriptorHeaps, options);
        FieldToJson(args["ppDescriptorHeaps"], ppDescriptorHeaps, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pRootSignature)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetComputeRootSignature");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRootSignature"], pRootSignature, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pRootSignature)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetGraphicsRootSignature");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRootSignature"], pRootSignature, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetComputeRootDescriptorTable");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJson(args["BaseDescriptor"], BaseDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetGraphicsRootDescriptorTable");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJson(args["BaseDescriptor"], BaseDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetComputeRoot32BitConstant");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJson(args["SrcData"], SrcData, options);
        FieldToJson(args["DestOffsetIn32BitValues"], DestOffsetIn32BitValues, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetGraphicsRoot32BitConstant");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJson(args["SrcData"], SrcData, options);
        FieldToJson(args["DestOffsetIn32BitValues"], DestOffsetIn32BitValues, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetComputeRoot32BitConstants");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJson(args["Num32BitValuesToSet"], Num32BitValuesToSet, options);
        FieldToJson(args["pSrcData"], pSrcData, options);
        FieldToJson(args["DestOffsetIn32BitValues"], DestOffsetIn32BitValues, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetGraphicsRoot32BitConstants");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJson(args["Num32BitValuesToSet"], Num32BitValuesToSet, options);
        FieldToJson(args["pSrcData"], pSrcData, options);
        FieldToJson(args["DestOffsetIn32BitValues"], DestOffsetIn32BitValues, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetComputeRootConstantBufferView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetGraphicsRootConstantBufferView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetComputeRootShaderResourceView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetGraphicsRootShaderResourceView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetComputeRootUnorderedAccessView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetGraphicsRootUnorderedAccessView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RootParameterIndex"], RootParameterIndex, options);
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "IASetIndexBuffer");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pView"], pView, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_IASetVertexBuffers(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "IASetVertexBuffers");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["StartSlot"], StartSlot, options);
        FieldToJson(args["NumViews"], NumViews, options);
        FieldToJson(args["pViews"], pViews, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SOSetTargets(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW>* pViews)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SOSetTargets");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["StartSlot"], StartSlot, options);
        FieldToJson(args["NumViews"], NumViews, options);
        FieldToJson(args["pViews"], pViews, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumRenderTargetDescriptors,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
        BOOL RTsSingleHandleToDescriptorRange,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "OMSetRenderTargets");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumRenderTargetDescriptors"], NumRenderTargetDescriptors, options);
        FieldToJson(args["pRenderTargetDescriptors"], pRenderTargetDescriptors, options);
        Bool32ToJson(args["RTsSingleHandleToDescriptorRange"], RTsSingleHandleToDescriptorRange, options);
        FieldToJson(args["pDepthStencilDescriptor"], pDepthStencilDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_ClearDepthStencilView(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "ClearDepthStencilView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["DepthStencilView"], DepthStencilView, options);
        FieldToJson_D3D12_CLEAR_FLAGS(args["ClearFlags"], ClearFlags, options);
        FieldToJson(args["Depth"], Depth, options);
        FieldToJson(args["Stencil"], Stencil, options);
        FieldToJson(args["NumRects"], NumRects, options);
        FieldToJson(args["pRects"], pRects, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_ClearRenderTargetView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
        PointerDecoder<FLOAT> ColorRGBA [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "ClearRenderTargetView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RenderTargetView"], RenderTargetView, options);
        FieldToJson(args["ColorRGBA"], ColorRGBA, options);
        FieldToJson(args["NumRects"], NumRects, options);
        FieldToJson(args["pRects"], pRects, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "ClearUnorderedAccessViewUint");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ViewGPUHandleInCurrentHeap"], ViewGPUHandleInCurrentHeap, options);
        FieldToJson(args["ViewCPUHandle"], ViewCPUHandle, options);
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["Values"], Values, options);
        FieldToJson(args["NumRects"], NumRects, options);
        FieldToJson(args["pRects"], pRects, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "ClearUnorderedAccessViewFloat");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ViewGPUHandleInCurrentHeap"], ViewGPUHandleInCurrentHeap, options);
        FieldToJson(args["ViewCPUHandle"], ViewCPUHandle, options);
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["Values"], Values, options);
        FieldToJson(args["NumRects"], NumRects, options);
        FieldToJson(args["pRects"], pRects, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_DiscardResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_DISCARD_REGION>* pRegion)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "DiscardResource");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["pRegion"], pRegion, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_BeginQuery(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "BeginQuery");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pQueryHeap"], pQueryHeap, options);
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["Index"], Index, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_EndQuery(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "EndQuery");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pQueryHeap"], pQueryHeap, options);
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["Index"], Index, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_ResolveQueryData(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "ResolveQueryData");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pQueryHeap"], pQueryHeap, options);
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["StartIndex"], StartIndex, options);
        FieldToJson(args["NumQueries"], NumQueries, options);
        FieldToJson(args["pDestinationBuffer"], pDestinationBuffer, options);
        FieldToJson(args["AlignedDestinationBufferOffset"], AlignedDestinationBufferOffset, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetPredication(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pBuffer,
        UINT64 AlignedBufferOffset,
        D3D12_PREDICATION_OP Operation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetPredication");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pBuffer"], pBuffer, options);
        FieldToJson(args["AlignedBufferOffset"], AlignedBufferOffset, options);
        FieldToJson(args["Operation"], Operation, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_SetMarker(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "SetMarker");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Metadata"], Metadata, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["Size"], Size, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_BeginEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "BeginEvent");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Metadata"], Metadata, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["Size"], Size, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_EndEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "EndEvent");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_ExecuteIndirect(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "ExecuteIndirect");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pCommandSignature"], pCommandSignature, options);
        FieldToJson(args["MaxCommandCount"], MaxCommandCount, options);
        FieldToJson(args["pArgumentBuffer"], pArgumentBuffer, options);
        FieldToJson(args["ArgumentBufferOffset"], ArgumentBufferOffset, options);
        FieldToJson(args["pCountBuffer"], pCountBuffer, options);
        FieldToJson(args["CountBufferOffset"], CountBufferOffset, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList1", object_id, "AtomicCopyBufferUINT");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDstBuffer"], pDstBuffer, options);
        FieldToJson(args["DstOffset"], DstOffset, options);
        FieldToJson(args["pSrcBuffer"], pSrcBuffer, options);
        FieldToJson(args["SrcOffset"], SrcOffset, options);
        FieldToJson(args["Dependencies"], Dependencies, options);
        FieldToJson(args["ppDependentResources"], ppDependentResources, options);
        FieldToJson(args["pDependentSubresourceRanges"], pDependentSubresourceRanges, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList1", object_id, "AtomicCopyBufferUINT64");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDstBuffer"], pDstBuffer, options);
        FieldToJson(args["DstOffset"], DstOffset, options);
        FieldToJson(args["pSrcBuffer"], pSrcBuffer, options);
        FieldToJson(args["SrcOffset"], SrcOffset, options);
        FieldToJson(args["Dependencies"], Dependencies, options);
        FieldToJson(args["ppDependentResources"], ppDependentResources, options);
        FieldToJson(args["pDependentSubresourceRanges"], pDependentSubresourceRanges, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList1_OMSetDepthBounds(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        FLOAT Min,
        FLOAT Max)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList1", object_id, "OMSetDepthBounds");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Min"], Min, options);
        FieldToJson(args["Max"], Max, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList1_SetSamplePositions(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumSamplesPerPixel,
        UINT NumPixels,
        StructPointerDecoder<Decoded_D3D12_SAMPLE_POSITION>* pSamplePositions)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList1", object_id, "SetSamplePositions");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumSamplesPerPixel"], NumSamplesPerPixel, options);
        FieldToJson(args["NumPixels"], NumPixels, options);
        FieldToJson(args["pSamplePositions"], pSamplePositions, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList1", object_id, "ResolveSubresourceRegion");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDstResource"], pDstResource, options);
        FieldToJson(args["DstSubresource"], DstSubresource, options);
        FieldToJson(args["DstX"], DstX, options);
        FieldToJson(args["DstY"], DstY, options);
        FieldToJson(args["pSrcResource"], pSrcResource, options);
        FieldToJson(args["SrcSubresource"], SrcSubresource, options);
        FieldToJson(args["pSrcRect"], pSrcRect, options);
        FieldToJson(args["Format"], Format, options);
        FieldToJson(args["ResolveMode"], ResolveMode, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList1_SetViewInstanceMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Mask)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList1", object_id, "SetViewInstanceMask");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["Mask"], Mask, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList2_WriteBufferImmediate(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Count,
        StructPointerDecoder<Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>* pParams,
        PointerDecoder<D3D12_WRITEBUFFERIMMEDIATE_MODE>* pModes)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList2", object_id, "WriteBufferImmediate");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Count"], Count, options);
        FieldToJson(args["pParams"], pParams, options);
        FieldToJson(args["pModes"], pModes, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_UpdateTileMappings(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "UpdateTileMappings");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["NumResourceRegions"], NumResourceRegions, options);
        FieldToJson(args["pResourceRegionStartCoordinates"], pResourceRegionStartCoordinates, options);
        FieldToJson(args["pResourceRegionSizes"], pResourceRegionSizes, options);
        FieldToJson(args["pHeap"], pHeap, options);
        FieldToJson(args["NumRanges"], NumRanges, options);
        FieldToJson_D3D12_TILE_RANGE_FLAGS(args["pRangeFlags"], *pRangeFlags->GetPointer(), options);
        FieldToJson(args["pHeapRangeStartOffsets"], pHeapRangeStartOffsets, options);
        FieldToJson(args["pRangeTileCounts"], pRangeTileCounts, options);
        FieldToJson_D3D12_TILE_MAPPING_FLAGS(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_CopyTileMappings(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "CopyTileMappings");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDstResource"], pDstResource, options);
        FieldToJson(args["pDstRegionStartCoordinate"], pDstRegionStartCoordinate, options);
        FieldToJson(args["pSrcResource"], pSrcResource, options);
        FieldToJson(args["pSrcRegionStartCoordinate"], pSrcRegionStartCoordinate, options);
        FieldToJson(args["pRegionSize"], pRegionSize, options);
        FieldToJson_D3D12_TILE_MAPPING_FLAGS(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_ExecuteCommandLists(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumCommandLists,
        HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "ExecuteCommandLists");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumCommandLists"], NumCommandLists, options);
        FieldToJson(args["ppCommandLists"], ppCommandLists, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_SetMarker(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "SetMarker");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Metadata"], Metadata, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["Size"], Size, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_BeginEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "BeginEvent");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Metadata"], Metadata, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["Size"], Size, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_EndEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "EndEvent");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_Signal(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pFence,
        UINT64 Value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "Signal");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFence"], pFence, options);
        FieldToJson(args["Value"], Value, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_Wait(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pFence,
        UINT64 Value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "Wait");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFence"], pFence, options);
        FieldToJson(args["Value"], Value, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_GetTimestampFrequency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT64>* pFrequency)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "GetTimestampFrequency");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFrequency"], pFrequency, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_GetClockCalibration(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT64>* pGpuTimestamp,
        PointerDecoder<UINT64>* pCpuTimestamp)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "GetClockCalibration");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pGpuTimestamp"], pGpuTimestamp, options);
        FieldToJson(args["pCpuTimestamp"], pCpuTimestamp, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_COMMAND_QUEUE_DESC return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_GetNodeCount(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "GetNodeCount");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateCommandQueue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandQueue)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateCommandQueue");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppCommandQueue"], ppCommandQueue, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateCommandAllocator(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_COMMAND_LIST_TYPE type,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandAllocator)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateCommandAllocator");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["type"], type, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppCommandAllocator"], ppCommandAllocator, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateGraphicsPipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateGraphicsPipelineState");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppPipelineState"], ppPipelineState, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateComputePipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateComputePipelineState");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppPipelineState"], ppPipelineState, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateCommandList(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateCommandList");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["nodeMask"], nodeMask, options);
        FieldToJson(args["type"], type, options);
        FieldToJson(args["pCommandAllocator"], pCommandAllocator, options);
        FieldToJson(args["pInitialState"], pInitialState, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppCommandList"], ppCommandList, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateDescriptorHeap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateDescriptorHeap");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDescriptorHeapDesc"], pDescriptorHeapDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvHeap"], ppvHeap, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_GetDescriptorHandleIncrementSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "GetDescriptorHandleIncrementSize");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["DescriptorHeapType"], DescriptorHeapType, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT nodeMask,
        PointerDecoder<uint8_t>* pBlobWithRootSignature,
        SIZE_T blobLengthInBytes,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvRootSignature)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateRootSignature");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["nodeMask"], nodeMask, options);
        FieldToJson(args["pBlobWithRootSignature"], pBlobWithRootSignature, options);
        FieldToJson(args["blobLengthInBytes"], blobLengthInBytes, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvRootSignature"], ppvRootSignature, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateConstantBufferView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateConstantBufferView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["DestDescriptor"], DestDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateShaderResourceView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateShaderResourceView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["DestDescriptor"], DestDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        format::HandleId pCounterResource,
        StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateUnorderedAccessView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["pCounterResource"], pCounterResource, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["DestDescriptor"], DestDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateRenderTargetView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateRenderTargetView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["DestDescriptor"], DestDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateDepthStencilView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateDepthStencilView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["DestDescriptor"], DestDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateSampler(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateSampler");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["DestDescriptor"], DestDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CopyDescriptors(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CopyDescriptors");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumDestDescriptorRanges"], NumDestDescriptorRanges, options);
        FieldToJson(args["pDestDescriptorRangeStarts"], pDestDescriptorRangeStarts, options);
        FieldToJson(args["pDestDescriptorRangeSizes"], pDestDescriptorRangeSizes, options);
        FieldToJson(args["NumSrcDescriptorRanges"], NumSrcDescriptorRanges, options);
        FieldToJson(args["pSrcDescriptorRangeStarts"], pSrcDescriptorRangeStarts, options);
        FieldToJson(args["pSrcDescriptorRangeSizes"], pSrcDescriptorRangeSizes, options);
        FieldToJson(args["DescriptorHeapsType"], DescriptorHeapsType, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CopyDescriptorsSimple(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumDescriptors,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CopyDescriptorsSimple");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumDescriptors"], NumDescriptors, options);
        FieldToJson(args["DestDescriptorRangeStart"], DestDescriptorRangeStart, options);
        FieldToJson(args["SrcDescriptorRangeStart"], SrcDescriptorRangeStart, options);
        FieldToJson(args["DescriptorHeapsType"], DescriptorHeapsType, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_GetResourceAllocationInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "GetResourceAllocationInfo");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["visibleMask"], visibleMask, options);
        FieldToJson(args["numResourceDescs"], numResourceDescs, options);
        FieldToJson(args["pResourceDescs"], pResourceDescs, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_GetCustomHeapProperties(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_HEAP_PROPERTIES return_value,
        UINT nodeMask,
        D3D12_HEAP_TYPE heapType)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "GetCustomHeapProperties");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["nodeMask"], nodeMask, options);
        FieldToJson(args["heapType"], heapType, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateCommittedResource(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateCommittedResource");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeapProperties"], pHeapProperties, options);
        FieldToJson_D3D12_HEAP_FLAGS(args["HeapFlags"], HeapFlags, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson_D3D12_RESOURCE_STATES(args["InitialResourceState"], InitialResourceState, options);
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue, options);
        FieldToJson(args["riidResource"], riidResource, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateHeap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateHeap");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvHeap"], ppvHeap, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreatePlacedResource(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreatePlacedResource");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeap"], pHeap, options);
        FieldToJson(args["HeapOffset"], HeapOffset, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson_D3D12_RESOURCE_STATES(args["InitialState"], InitialState, options);
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateReservedResource(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateReservedResource");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson_D3D12_RESOURCE_STATES(args["InitialState"], InitialState, options);
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateSharedHandle(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateSharedHandle");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pObject"], pObject, options);
        FieldToJson(args["pAttributes"], pAttributes, options);
        FieldToJson(args["Access"], Access, options);
        FieldToJson(args["Name"], Name, options);
        FieldToJson(args["pHandle"], pHandle, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_OpenSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t NTHandle,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObj)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "OpenSharedHandle");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NTHandle"], NTHandle, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvObj"], ppvObj, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_OpenSharedHandleByName(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* Name,
        DWORD Access,
        PointerDecoder<uint64_t, void*>* pNTHandle)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "OpenSharedHandleByName");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Name"], Name, options);
        FieldToJson(args["Access"], Access, options);
        FieldToJson(args["pNTHandle"], pNTHandle, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_MakeResident(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "MakeResident");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumObjects"], NumObjects, options);
        FieldToJson(args["ppObjects"], ppObjects, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_Evict(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "Evict");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumObjects"], NumObjects, options);
        FieldToJson(args["ppObjects"], ppObjects, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateFence(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 InitialValue,
        D3D12_FENCE_FLAGS Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateFence");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["InitialValue"], InitialValue, options);
        FieldToJson_D3D12_FENCE_FLAGS(args["Flags"], Flags, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppFence"], ppFence, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_GetDeviceRemovedReason(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "GetDeviceRemovedReason");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_GetCopyableFootprints(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "GetCopyableFootprints");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResourceDesc"], pResourceDesc, options);
        FieldToJson(args["FirstSubresource"], FirstSubresource, options);
        FieldToJson(args["NumSubresources"], NumSubresources, options);
        FieldToJson(args["BaseOffset"], BaseOffset, options);
        FieldToJson(args["pLayouts"], pLayouts, options);
        FieldToJson(args["pNumRows"], pNumRows, options);
        FieldToJson(args["pRowSizeInBytes"], pRowSizeInBytes, options);
        FieldToJson(args["pTotalBytes"], pTotalBytes, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateQueryHeap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_QUERY_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateQueryHeap");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvHeap"], ppvHeap, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_SetStablePowerState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Enable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "SetStablePowerState");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_CreateCommandSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC>* pDesc,
        format::HandleId pRootSignature,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvCommandSignature)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "CreateCommandSignature");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["pRootSignature"], pRootSignature, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvCommandSignature"], ppvCommandSignature, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_GetResourceTiling(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "GetResourceTiling");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pTiledResource"], pTiledResource, options);
        FieldToJson(args["pNumTilesForEntireResource"], pNumTilesForEntireResource, options);
        FieldToJson(args["pPackedMipDesc"], pPackedMipDesc, options);
        FieldToJson(args["pStandardTileShapeForNonPackedMips"], pStandardTileShapeForNonPackedMips, options);
        FieldToJson(args["pNumSubresourceTilings"], pNumSubresourceTilings, options);
        FieldToJson(args["FirstSubresourceTilingToGet"], FirstSubresourceTilingToGet, options);
        FieldToJson(args["pSubresourceTilingsForNonPackedMips"], pSubresourceTilingsForNonPackedMips, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_GetAdapterLuid(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_LUID return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "GetAdapterLuid");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12PipelineLibrary_StorePipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        format::HandleId pPipeline)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12PipelineLibrary", object_id, "StorePipeline");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pName"], pName, options);
        FieldToJson(args["pPipeline"], pPipeline, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12PipelineLibrary_LoadGraphicsPipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12PipelineLibrary", object_id, "LoadGraphicsPipeline");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pName"], pName, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppPipelineState"], ppPipelineState, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12PipelineLibrary_LoadComputePipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12PipelineLibrary", object_id, "LoadComputePipeline");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pName"], pName, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppPipelineState"], ppPipelineState, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12PipelineLibrary_GetSerializedSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        SIZE_T return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12PipelineLibrary", object_id, "GetSerializedSize");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12PipelineLibrary_Serialize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pData,
        SIZE_T DataSizeInBytes)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12PipelineLibrary", object_id, "Serialize");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["DataSizeInBytes"], DataSizeInBytes, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12PipelineLibrary1_LoadPipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12PipelineLibrary1", object_id, "LoadPipeline");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pName"], pName, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppPipelineState"], ppPipelineState, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device1_CreatePipelineLibrary(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pLibraryBlob,
        SIZE_T BlobLength,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineLibrary)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device1", object_id, "CreatePipelineLibrary");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pLibraryBlob"], pLibraryBlob, options);
        FieldToJson(args["BlobLength"], BlobLength, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppPipelineLibrary"], ppPipelineLibrary, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device1_SetEventOnMultipleFenceCompletion(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device1", object_id, "SetEventOnMultipleFenceCompletion");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ppFences"], ppFences, options);
        FieldToJson(args["pFenceValues"], pFenceValues, options);
        FieldToJson(args["NumFences"], NumFences, options);
        FieldToJson_D3D12_MULTIPLE_FENCE_WAIT_FLAGS(args["Flags"], Flags, options);
        FieldToJson(args["hEvent"], hEvent, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device1_SetResidencyPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        PointerDecoder<D3D12_RESIDENCY_PRIORITY>* pPriorities)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device1", object_id, "SetResidencyPriority");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumObjects"], NumObjects, options);
        FieldToJson(args["ppObjects"], ppObjects, options);
        FieldToJson(args["pPriorities"], pPriorities, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device2_CreatePipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device2", object_id, "CreatePipelineState");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppPipelineState"], ppPipelineState, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device3_OpenExistingHeapFromAddress(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t pAddress,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device3", object_id, "OpenExistingHeapFromAddress");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pAddress"], pAddress, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvHeap"], ppvHeap, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device3_OpenExistingHeapFromFileMapping(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hFileMapping,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device3", object_id, "OpenExistingHeapFromFileMapping");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["hFileMapping"], hFileMapping, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvHeap"], ppvHeap, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device3_EnqueueMakeResident(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device3", object_id, "EnqueueMakeResident");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson_D3D12_RESIDENCY_FLAGS(args["Flags"], Flags, options);
        FieldToJson(args["NumObjects"], NumObjects, options);
        FieldToJson(args["ppObjects"], ppObjects, options);
        FieldToJson(args["pFenceToSignal"], pFenceToSignal, options);
        FieldToJson(args["FenceValueToSignal"], FenceValueToSignal, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ProtectedSession_GetStatusFence(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ProtectedSession", object_id, "GetStatusFence");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppFence"], ppFence, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ProtectedSession_GetSessionStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_PROTECTED_SESSION_STATUS return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ProtectedSession", object_id, "GetSessionStatus");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson_D3D12_PROTECTED_SESSION_STATUS(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ProtectedResourceSession", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device4_CreateCommandList1(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device4", object_id, "CreateCommandList1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["nodeMask"], nodeMask, options);
        FieldToJson(args["type"], type, options);
        FieldToJson_D3D12_COMMAND_LIST_FLAGS(args["flags"], flags, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppCommandList"], ppCommandList, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device4_CreateProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device4", object_id, "CreateProtectedResourceSession");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppSession"], ppSession, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device4_CreateCommittedResource1(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device4", object_id, "CreateCommittedResource1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeapProperties"], pHeapProperties, options);
        FieldToJson_D3D12_HEAP_FLAGS(args["HeapFlags"], HeapFlags, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson_D3D12_RESOURCE_STATES(args["InitialResourceState"], InitialResourceState, options);
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue, options);
        FieldToJson(args["pProtectedSession"], pProtectedSession, options);
        FieldToJson(args["riidResource"], riidResource, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device4_CreateHeap1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        format::HandleId pProtectedSession,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device4", object_id, "CreateHeap1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["pProtectedSession"], pProtectedSession, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvHeap"], ppvHeap, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device4_CreateReservedResource1(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device4", object_id, "CreateReservedResource1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson_D3D12_RESOURCE_STATES(args["InitialState"], InitialState, options);
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue, options);
        FieldToJson(args["pProtectedSession"], pProtectedSession, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device4_GetResourceAllocationInfo1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device4", object_id, "GetResourceAllocationInfo1");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["visibleMask"], visibleMask, options);
        FieldToJson(args["numResourceDescs"], numResourceDescs, options);
        FieldToJson(args["pResourceDescs"], pResourceDescs, options);
        FieldToJson(args["pResourceAllocationInfo1"], pResourceAllocationInfo1, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12LifetimeOwner_LifetimeStateUpdated(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_LIFETIME_STATE NewState)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12LifetimeOwner", object_id, "LifetimeStateUpdated");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NewState"], NewState, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SwapChainAssistant_GetLUID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_LUID return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SwapChainAssistant", object_id, "GetLUID");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SwapChainAssistant_GetSwapChainObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppv)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SwapChainAssistant", object_id, "GetSwapChainObject");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppv"], ppv, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource,
        Decoded_GUID riidQueue,
        HandlePointerDecoder<void*>* ppvQueue)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SwapChainAssistant", object_id, "GetCurrentResourceAndCommandQueue");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riidResource"], riidResource, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
        FieldToJson(args["riidQueue"], riidQueue, options);
        FieldToJson(args["ppvQueue"], ppvQueue, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SwapChainAssistant_InsertImplicitSync(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SwapChainAssistant", object_id, "InsertImplicitSync");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12LifetimeTracker_DestroyOwnedObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pObject)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12LifetimeTracker", object_id, "DestroyOwnedObject");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pObject"], pObject, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectProperties_GetShaderIdentifier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        PointerDecoder<uint8_t>* return_value,
        WStringDecoder* pExportName)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectProperties", object_id, "GetShaderIdentifier");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pExportName"], pExportName, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectProperties_GetShaderStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value,
        WStringDecoder* pExportName)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectProperties", object_id, "GetShaderStackSize");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pExportName"], pExportName, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectProperties_GetPipelineStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectProperties", object_id, "GetPipelineStackSize");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectProperties_SetPipelineStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 PipelineStackSizeInBytes)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectProperties", object_id, "SetPipelineStackSize");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["PipelineStackSizeInBytes"], PipelineStackSizeInBytes, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device5_CreateLifetimeTracker(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pOwner,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvTracker)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device5", object_id, "CreateLifetimeTracker");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOwner"], pOwner, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvTracker"], ppvTracker, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device5_RemoveDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device5", object_id, "RemoveDevice");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device5_EnumerateMetaCommands(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pNumMetaCommands,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_DESC>* pDescs)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device5", object_id, "EnumerateMetaCommands");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pNumMetaCommands"], pNumMetaCommands, options);
        FieldToJson(args["pDescs"], pDescs, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device5_EnumerateMetaCommandParameters(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device5", object_id, "EnumerateMetaCommandParameters");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["CommandId"], CommandId, options);
        FieldToJson(args["Stage"], Stage, options);
        FieldToJson(args["pTotalStructureSizeInBytes"], pTotalStructureSizeInBytes, options);
        FieldToJson(args["pParameterCount"], pParameterCount, options);
        FieldToJson(args["pParameterDescs"], pParameterDescs, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device5_CreateMetaCommand(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device5", object_id, "CreateMetaCommand");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["CommandId"], CommandId, options);
        FieldToJsonAsFixedWidthBinary(args["NodeMask"], NodeMask, options);
        FieldToJson(args["pCreationParametersData"], pCreationParametersData, options);
        FieldToJson(args["CreationParametersDataSizeInBytes"], CreationParametersDataSizeInBytes, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppMetaCommand"], ppMetaCommand, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device5_CreateStateObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppStateObject)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device5", object_id, "CreateStateObject");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppStateObject"], ppStateObject, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>* pDesc,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>* pInfo)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device5", object_id, "GetRaytracingAccelerationStructurePrebuildInfo");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["pInfo"], pInfo, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device5_CheckDriverMatchingIdentifier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS return_value,
        D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
        StructPointerDecoder<Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>* pIdentifierToCheck)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device5", object_id, "CheckDriverMatchingIdentifier");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson_D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["SerializedDataType"], SerializedDataType, options);
        FieldToJson(args["pIdentifierToCheck"], pIdentifierToCheck, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedDataSettings", object_id, "SetAutoBreadcrumbsEnablement");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Enablement"], Enablement, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedDataSettings", object_id, "SetPageFaultEnablement");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Enablement"], Enablement, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedDataSettings", object_id, "SetWatsonDumpEnablement");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Enablement"], Enablement, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedDataSettings1", object_id, "SetBreadcrumbContextEnablement");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Enablement"], Enablement, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL MarkersOnly)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedDataSettings2", object_id, "UseMarkersOnlyAutoBreadcrumbs");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["MarkersOnly"], MarkersOnly, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* pOutput)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedData", object_id, "GetAutoBreadcrumbsOutput");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutput"], pOutput, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>* pOutput)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedData", object_id, "GetPageFaultAllocationOutput");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutput"], pOutput, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* pOutput)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedData1", object_id, "GetAutoBreadcrumbsOutput1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutput"], pOutput, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* pOutput)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedData1", object_id, "GetPageFaultAllocationOutput1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutput"], pOutput, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2>* pOutput)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedData2", object_id, "GetPageFaultAllocationOutput2");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutput"], pOutput, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceRemovedExtendedData2_GetDeviceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_DEVICE_STATE return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceRemovedExtendedData2", object_id, "GetDeviceState");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device6_SetBackgroundProcessingMode(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_BACKGROUND_PROCESSING_MODE Mode,
        D3D12_MEASUREMENTS_ACTION MeasurementsAction,
        uint64_t hEventToSignalUponCompletion,
        PointerDecoder<BOOL>* pbFurtherMeasurementsDesired)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device6", object_id, "SetBackgroundProcessingMode");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Mode"], Mode, options);
        FieldToJson(args["MeasurementsAction"], MeasurementsAction, options);
        FieldToJson(args["hEventToSignalUponCompletion"], hEventToSignalUponCompletion, options);
        Bool32ToJson(args["pbFurtherMeasurementsDesired"], pbFurtherMeasurementsDesired, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ProtectedResourceSession1_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ProtectedResourceSession1", object_id, "GetDesc1");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device7_AddToStateObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pAddition,
        format::HandleId pStateObjectToGrowFrom,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppNewStateObject)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device7", object_id, "AddToStateObject");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pAddition"], pAddition, options);
        FieldToJson(args["pStateObjectToGrowFrom"], pStateObjectToGrowFrom, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppNewStateObject"], ppNewStateObject, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device7_CreateProtectedResourceSession1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device7", object_id, "CreateProtectedResourceSession1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppSession"], ppSession, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device8_GetResourceAllocationInfo2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device8", object_id, "GetResourceAllocationInfo2");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["visibleMask"], visibleMask, options);
        FieldToJson(args["numResourceDescs"], numResourceDescs, options);
        FieldToJson(args["pResourceDescs"], pResourceDescs, options);
        FieldToJson(args["pResourceAllocationInfo1"], pResourceAllocationInfo1, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device8_CreateCommittedResource2(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device8", object_id, "CreateCommittedResource2");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeapProperties"], pHeapProperties, options);
        FieldToJson_D3D12_HEAP_FLAGS(args["HeapFlags"], HeapFlags, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson_D3D12_RESOURCE_STATES(args["InitialResourceState"], InitialResourceState, options);
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue, options);
        FieldToJson(args["pProtectedSession"], pProtectedSession, options);
        FieldToJson(args["riidResource"], riidResource, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device8_CreatePlacedResource1(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device8", object_id, "CreatePlacedResource1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeap"], pHeap, options);
        FieldToJson(args["HeapOffset"], HeapOffset, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson_D3D12_RESOURCE_STATES(args["InitialState"], InitialState, options);
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pTargetedResource,
        format::HandleId pFeedbackResource,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device8", object_id, "CreateSamplerFeedbackUnorderedAccessView");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pTargetedResource"], pTargetedResource, options);
        FieldToJson(args["pFeedbackResource"], pFeedbackResource, options);
        FieldToJson(args["DestDescriptor"], DestDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device8_GetCopyableFootprints1(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device8", object_id, "GetCopyableFootprints1");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResourceDesc"], pResourceDesc, options);
        FieldToJson(args["FirstSubresource"], FirstSubresource, options);
        FieldToJson(args["NumSubresources"], NumSubresources, options);
        FieldToJson(args["BaseOffset"], BaseOffset, options);
        FieldToJson(args["pLayouts"], pLayouts, options);
        FieldToJson(args["pNumRows"], pNumRows, options);
        FieldToJson(args["pRowSizeInBytes"], pRowSizeInBytes, options);
        FieldToJson(args["pTotalBytes"], pTotalBytes, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Resource1_GetProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Resource1", object_id, "GetProtectedResourceSession");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppProtectedSession"], ppProtectedSession, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Resource2_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC1 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Resource2", object_id, "GetDesc1");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Heap1_GetProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Heap1", object_id, "GetProtectedResourceSession");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppProtectedSession"], ppProtectedSession, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pProtectedResourceSession)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList3", object_id, "SetProtectedResourceSession");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pProtectedResourceSession"], pProtectedResourceSession, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12MetaCommand_GetRequiredParameterResourceSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        UINT ParameterIndex)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12MetaCommand", object_id, "GetRequiredParameterResourceSize");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Stage"], Stage, options);
        FieldToJson(args["ParameterIndex"], ParameterIndex, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList4_BeginRenderPass(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS Flags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList4", object_id, "BeginRenderPass");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumRenderTargets"], NumRenderTargets, options);
        FieldToJson(args["pRenderTargets"], pRenderTargets, options);
        FieldToJson(args["pDepthStencil"], pDepthStencil, options);
        FieldToJson_D3D12_RENDER_PASS_FLAGS(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList4_EndRenderPass(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList4", object_id, "EndRenderPass");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pMetaCommand,
        PointerDecoder<uint8_t>* pInitializationParametersData,
        SIZE_T InitializationParametersDataSizeInBytes)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList4", object_id, "InitializeMetaCommand");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pMetaCommand"], pMetaCommand, options);
        FieldToJson(args["pInitializationParametersData"], pInitializationParametersData, options);
        FieldToJson(args["InitializationParametersDataSizeInBytes"], InitializationParametersDataSizeInBytes, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pMetaCommand,
        PointerDecoder<uint8_t>* pExecutionParametersData,
        SIZE_T ExecutionParametersDataSizeInBytes)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList4", object_id, "ExecuteMetaCommand");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pMetaCommand"], pMetaCommand, options);
        FieldToJson(args["pExecutionParametersData"], pExecutionParametersData, options);
        FieldToJson(args["ExecutionParametersDataSizeInBytes"], ExecutionParametersDataSizeInBytes, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* pDesc,
        UINT NumPostbuildInfoDescs,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pPostbuildInfoDescs)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList4", object_id, "BuildRaytracingAccelerationStructure");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["NumPostbuildInfoDescs"], NumPostbuildInfoDescs, options);
        FieldToJson(args["pPostbuildInfoDescs"], pPostbuildInfoDescs, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pDesc,
        UINT NumSourceAccelerationStructures,
        PointerDecoder<D3D12_GPU_VIRTUAL_ADDRESS>* pSourceAccelerationStructureData)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList4", object_id, "EmitRaytracingAccelerationStructurePostbuildInfo");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["NumSourceAccelerationStructures"], NumSourceAccelerationStructures, options);
        FieldToJsonAsHex(args["pSourceAccelerationStructureData"], pSourceAccelerationStructureData, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
        D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList4", object_id, "CopyRaytracingAccelerationStructure");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsHex(args["DestAccelerationStructureData"], DestAccelerationStructureData, options);
        FieldToJsonAsHex(args["SourceAccelerationStructureData"], SourceAccelerationStructureData, options);
        FieldToJson(args["Mode"], Mode, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList4_SetPipelineState1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pStateObject)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList4", object_id, "SetPipelineState1");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pStateObject"], pStateObject, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList4_DispatchRays(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList4", object_id, "DispatchRays");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ShaderCacheSession_FindValue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pKey,
        UINT KeySize,
        PointerDecoder<uint8_t>* pValue,
        PointerDecoder<UINT>* pValueSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ShaderCacheSession", object_id, "FindValue");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pKey"], pKey, options);
        FieldToJson(args["KeySize"], KeySize, options);
        FieldToJson(args["pValue"], pValue, options);
        FieldToJson(args["pValueSize"], pValueSize, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ShaderCacheSession_StoreValue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pKey,
        UINT KeySize,
        PointerDecoder<uint8_t>* pValue,
        UINT ValueSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ShaderCacheSession", object_id, "StoreValue");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pKey"], pKey, options);
        FieldToJson(args["KeySize"], KeySize, options);
        FieldToJson(args["pValue"], pValue, options);
        FieldToJson(args["ValueSize"], ValueSize, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ShaderCacheSession_SetDeleteOnDestroy(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ShaderCacheSession", object_id, "SetDeleteOnDestroy");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ShaderCacheSession_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_SHADER_CACHE_SESSION_DESC return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ShaderCacheSession", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device9_CreateShaderCacheSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_SHADER_CACHE_SESSION_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvSession)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device9", object_id, "CreateShaderCacheSession");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvSession"], ppvSession, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device9_ShaderCacheControl(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_SHADER_CACHE_KIND_FLAGS Kinds,
        D3D12_SHADER_CACHE_CONTROL_FLAGS Control)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device9", object_id, "ShaderCacheControl");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson_D3D12_SHADER_CACHE_KIND_FLAGS(args["Kinds"], Kinds, options);
        FieldToJson_D3D12_SHADER_CACHE_CONTROL_FLAGS(args["Control"], Control, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device9_CreateCommandQueue1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
        Decoded_GUID CreatorID,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandQueue)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device9", object_id, "CreateCommandQueue1");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["CreatorID"], CreatorID, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppCommandQueue"], ppCommandQueue, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device10_CreateCommittedResource3(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device10", object_id, "CreateCommittedResource3");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeapProperties"], pHeapProperties, options);
        FieldToJson_D3D12_HEAP_FLAGS(args["HeapFlags"], HeapFlags, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["InitialLayout"], InitialLayout, options);
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue, options);
        FieldToJson(args["pProtectedSession"], pProtectedSession, options);
        FieldToJson(args["NumCastableFormats"], NumCastableFormats, options);
        FieldToJson(args["pCastableFormats"], pCastableFormats, options);
        FieldToJson(args["riidResource"], riidResource, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device10_CreatePlacedResource2(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device10", object_id, "CreatePlacedResource2");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeap"], pHeap, options);
        FieldToJson(args["HeapOffset"], HeapOffset, options);
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["InitialLayout"], InitialLayout, options);
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue, options);
        FieldToJson(args["NumCastableFormats"], NumCastableFormats, options);
        FieldToJson(args["pCastableFormats"], pCastableFormats, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device10_CreateReservedResource2(
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

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device10", object_id, "CreateReservedResource2");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["InitialLayout"], InitialLayout, options);
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue, options);
        FieldToJson(args["pProtectedSession"], pProtectedSession, options);
        FieldToJson(args["NumCastableFormats"], NumCastableFormats, options);
        FieldToJson(args["pCastableFormats"], pCastableFormats, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvResource"], ppvResource, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device11_CreateSampler2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC2>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device11", object_id, "CreateSampler2");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["DestDescriptor"], DestDescriptor, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device12_GetResourceAllocationInfo3(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDescs,
        PointerDecoder<UINT32>* pNumCastableFormats,
        PointerDecoder<DXGI_FORMAT*>* ppCastableFormats,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device12", object_id, "GetResourceAllocationInfo3");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["visibleMask"], visibleMask, options);
        FieldToJson(args["numResourceDescs"], numResourceDescs, options);
        FieldToJson(args["pResourceDescs"], pResourceDescs, options);
        FieldToJson(args["pNumCastableFormats"], pNumCastableFormats, options);
        FieldToJson(args["ppCastableFormats"], ppCastableFormats, options);
        FieldToJson(args["pResourceAllocationInfo1"], pResourceAllocationInfo1, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12VirtualizationGuestDevice_ShareWithHost(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pObject,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12VirtualizationGuestDevice", object_id, "ShareWithHost");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pObject"], pObject, options);
        FieldToJson(args["pHandle"], pHandle, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12VirtualizationGuestDevice_CreateFenceFd(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pFence,
        UINT64 FenceValue,
        PointerDecoder<int>* pFenceFd)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12VirtualizationGuestDevice", object_id, "CreateFenceFd");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFence"], pFence, options);
        FieldToJson(args["FenceValue"], FenceValue, options);
        FieldToJson(args["pFenceFd"], pFenceFd, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Tools_EnableShaderInstrumentation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL bEnable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Tools", object_id, "EnableShaderInstrumentation");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["bEnable"], bEnable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Tools_ShaderInstrumentationEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Tools", object_id, "ShaderInstrumentationEnabled");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SDKConfiguration_SetSDKVersion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT SDKVersion,
        StringDecoder* SDKPath)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SDKConfiguration", object_id, "SetSDKVersion");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["SDKVersion"], SDKVersion, options);
        FieldToJson(args["SDKPath"], SDKPath, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SDKConfiguration1_CreateDeviceFactory(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT SDKVersion,
        StringDecoder* SDKPath,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvFactory)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SDKConfiguration1", object_id, "CreateDeviceFactory");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["SDKVersion"], SDKVersion, options);
        FieldToJson(args["SDKPath"], SDKPath, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvFactory"], ppvFactory, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SDKConfiguration1_FreeUnusedSDKs(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SDKConfiguration1", object_id, "FreeUnusedSDKs");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceFactory_InitializeFromGlobalState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceFactory", object_id, "InitializeFromGlobalState");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceFactory_ApplyToGlobalState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceFactory", object_id, "ApplyToGlobalState");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceFactory_SetFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEVICE_FACTORY_FLAGS flags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceFactory", object_id, "SetFlags");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson_D3D12_DEVICE_FACTORY_FLAGS(args["flags"], flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceFactory_GetFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DEVICE_FACTORY_FLAGS return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceFactory", object_id, "GetFlags");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson_D3D12_DEVICE_FACTORY_FLAGS(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceFactory_GetConfigurationInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID clsid,
        Decoded_GUID iid,
        HandlePointerDecoder<void*>* ppv)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceFactory", object_id, "GetConfigurationInterface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["clsid"], clsid, options);
        FieldToJson(args["iid"], iid, options);
        FieldToJson(args["ppv"], ppv, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceFactory_EnableExperimentalFeatures(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumFeatures,
        StructPointerDecoder<Decoded_GUID>* pIIDs,
        PointerDecoder<uint8_t>* pConfigurationStructs,
        PointerDecoder<UINT>* pConfigurationStructSizes)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceFactory", object_id, "EnableExperimentalFeatures");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumFeatures"], NumFeatures, options);
        FieldToJson(args["pIIDs"], pIIDs, options);
        FieldToJson(args["pConfigurationStructs"], pConfigurationStructs, options);
        FieldToJson(args["pConfigurationStructSizes"], pConfigurationStructSizes, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceFactory_CreateDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId adapter,
        D3D_FEATURE_LEVEL FeatureLevel,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDevice)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceFactory", object_id, "CreateDevice");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["adapter"], adapter, options);
        FieldToJson(args["FeatureLevel"], FeatureLevel, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvDevice"], ppvDevice, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceConfiguration_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_DEVICE_CONFIGURATION_DESC return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceConfiguration", object_id, "GetDesc");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_GUID>* pGuids,
        UINT NumGuids)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceConfiguration", object_id, "GetEnabledExperimentalFeatures");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pGuids"], pGuids, options);
        FieldToJson(args["NumGuids"], NumGuids, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceConfiguration_SerializeVersionedRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pDesc,
        HandlePointerDecoder<ID3D10Blob*>* ppResult,
        HandlePointerDecoder<ID3D10Blob*>* ppError)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceConfiguration", object_id, "SerializeVersionedRootSignature");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc, options);
        FieldToJson(args["ppResult"], ppResult, options);
        FieldToJson(args["ppError"], ppError, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pBlob,
        SIZE_T Size,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDeserializer)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceConfiguration", object_id, "CreateVersionedRootSignatureDeserializer");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pBlob"], pBlob, options);
        FieldToJson(args["Size"], Size, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvDeserializer"], ppvDeserializer, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRate(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_SHADING_RATE baseShadingRate,
        PointerDecoder<D3D12_SHADING_RATE_COMBINER>* combiners)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList5", object_id, "RSSetShadingRate");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["baseShadingRate"], baseShadingRate, options);
        FieldToJson(args["combiners"], combiners, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId shadingRateImage)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList5", object_id, "RSSetShadingRateImage");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["shadingRateImage"], shadingRateImage, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList6_DispatchMesh(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList6", object_id, "DispatchMesh");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ThreadGroupCountX"], ThreadGroupCountX, options);
        FieldToJson(args["ThreadGroupCountY"], ThreadGroupCountY, options);
        FieldToJson(args["ThreadGroupCountZ"], ThreadGroupCountZ, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList7_Barrier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT32 NumBarrierGroups,
        StructPointerDecoder<Decoded_D3D12_BARRIER_GROUP>* pBarrierGroups)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList7", object_id, "Barrier");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["NumBarrierGroups"], NumBarrierGroups, options);
        FieldToJson(args["pBarrierGroups"], pBarrierGroups, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT FrontStencilRef,
        UINT BackStencilRef)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList8", object_id, "OMSetFrontAndBackStencilRef");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["FrontStencilRef"], FrontStencilRef, options);
        FieldToJson(args["BackStencilRef"], BackStencilRef, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList9_RSSetDepthBias(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        FLOAT DepthBias,
        FLOAT DepthBiasClamp,
        FLOAT SlopeScaledDepthBias)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList9", object_id, "RSSetDepthBias");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["DepthBias"], DepthBias, options);
        FieldToJson(args["DepthBiasClamp"], DepthBiasClamp, options);
        FieldToJson(args["SlopeScaledDepthBias"], SlopeScaledDepthBias, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_INDEX_BUFFER_STRIP_CUT_VALUE IBStripCutValue)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList9", object_id, "IASetIndexBufferStripCutValue");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["IBStripCutValue"], IBStripCutValue, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DSRDeviceFactory_CreateDSRDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pD3D12Device,
        UINT NodeMask,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDSRDevice)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DSRDeviceFactory", object_id, "CreateDSRDevice");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pD3D12Device"], pD3D12Device, options);
        FieldToJsonAsFixedWidthBinary(args["NodeMask"], NodeMask, options);
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvDSRDevice"], ppvDSRDevice, options);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12JsonConsumer::Process_ID3D10Blob_GetBufferPointer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        uint64_t return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D10Blob", object_id, "GetBufferPointer");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D10Blob_GetBufferSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        SIZE_T return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D10Blob", object_id, "GetBufferSize");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3DDestructionNotifier_RegisterDestructionCallback(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t callbackFn,
        uint64_t pData,
        PointerDecoder<UINT>* pCallbackID)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3DDestructionNotifier", object_id, "RegisterDestructionCallback");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["callbackFn"], callbackFn, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["pCallbackID"], pCallbackID, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3DDestructionNotifier_UnregisterDestructionCallback(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT callbackID)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3DDestructionNotifier", object_id, "UnregisterDestructionCallback");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["callbackID"], callbackID, options);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from d3d12sdklayers.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12JsonConsumer::Process_ID3D12Debug_EnableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug", object_id, "EnableDebugLayer");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug1_EnableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug1", object_id, "EnableDebugLayer");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug1_SetEnableGPUBasedValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug1", object_id, "SetEnableGPUBasedValidation");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug1", object_id, "SetEnableSynchronizedCommandQueueValidation");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug2_SetGPUBasedValidationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug2", object_id, "SetGPUBasedValidationFlags");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson_D3D12_GPU_BASED_VALIDATION_FLAGS(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug3_SetEnableGPUBasedValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug3", object_id, "SetEnableGPUBasedValidation");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug3", object_id, "SetEnableSynchronizedCommandQueueValidation");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug3_SetGPUBasedValidationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug3", object_id, "SetGPUBasedValidationFlags");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson_D3D12_GPU_BASED_VALIDATION_FLAGS(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug4_DisableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug4", object_id, "DisableDebugLayer");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug5_SetEnableAutoName(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug5", object_id, "SetEnableAutoName");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug6_SetForceLegacyBarrierValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug6", object_id, "SetForceLegacyBarrierValidation");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugDevice1_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugDevice1", object_id, "SetDebugParameter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["DataSize"], DataSize, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugDevice1_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugDevice1", object_id, "GetDebugParameter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["DataSize"], DataSize, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugDevice1_ReportLiveDeviceObjects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RLDO_FLAGS Flags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugDevice1", object_id, "ReportLiveDeviceObjects");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson_D3D12_RLDO_FLAGS(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugDevice_SetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_FEATURE Mask)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugDevice", object_id, "SetFeatureMask");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Mask"], Mask, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugDevice_GetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DEBUG_FEATURE return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugDevice", object_id, "GetFeatureMask");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugDevice_ReportLiveDeviceObjects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RLDO_FLAGS Flags)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugDevice", object_id, "ReportLiveDeviceObjects");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson_D3D12_RLDO_FLAGS(args["Flags"], Flags, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugDevice2_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugDevice2", object_id, "SetDebugParameter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["DataSize"], DataSize, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugDevice2_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugDevice2", object_id, "GetDebugParameter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["DataSize"], DataSize, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandQueue_AssertResourceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandQueue", object_id, "AssertResourceState");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["State"], State, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandQueue1_AssertResourceAccess(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        D3D12_BARRIER_ACCESS Access)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandQueue1", object_id, "AssertResourceAccess");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["Access"], Access, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandQueue1_AssertTextureLayout(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        D3D12_BARRIER_LAYOUT Layout)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandQueue1", object_id, "AssertTextureLayout");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["Layout"], Layout, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandList1_AssertResourceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandList1", object_id, "AssertResourceState");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["State"], State, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandList1_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandList1", object_id, "SetDebugParameter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["DataSize"], DataSize, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandList1_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandList1", object_id, "GetDebugParameter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["DataSize"], DataSize, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandList_AssertResourceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandList", object_id, "AssertResourceState");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["State"], State, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandList_SetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_FEATURE Mask)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandList", object_id, "SetFeatureMask");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Mask"], Mask, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandList_GetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DEBUG_FEATURE return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandList", object_id, "GetFeatureMask");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandList2_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandList2", object_id, "SetDebugParameter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["DataSize"], DataSize, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandList2_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandList2", object_id, "GetDebugParameter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Type"], Type, options);
        FieldToJson(args["pData"], pData, options);
        FieldToJson(args["DataSize"], DataSize, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandList3_AssertResourceAccess(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        D3D12_BARRIER_ACCESS Access)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandList3", object_id, "AssertResourceAccess");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["Access"], Access, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DebugCommandList3_AssertTextureLayout(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        D3D12_BARRIER_LAYOUT Layout)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DebugCommandList3", object_id, "AssertTextureLayout");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["Layout"], Layout, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SharingContract_Present(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        uint64_t window)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SharingContract", object_id, "Present");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResource"], pResource, options);
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["window"], window, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SharingContract_SharedFenceSignal(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pFence,
        UINT64 FenceValue)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SharingContract", object_id, "SharedFenceSignal");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFence"], pFence, options);
        FieldToJson(args["FenceValue"], FenceValue, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SharingContract_BeginCapturableWork(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_GUID guid)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SharingContract", object_id, "BeginCapturableWork");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["guid"], guid, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SharingContract_EndCapturableWork(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_GUID guid)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SharingContract", object_id, "EndCapturableWork");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["guid"], guid, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ManualWriteTrackingResource_TrackWrite(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pWrittenRange)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ManualWriteTrackingResource", object_id, "TrackWrite");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Subresource"], Subresource, options);
        FieldToJson(args["pWrittenRange"], pWrittenRange, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_SetMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 MessageCountLimit)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "SetMessageCountLimit");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["MessageCountLimit"], MessageCountLimit, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_ClearStoredMessages(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "ClearStoredMessages");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetMessage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 MessageIndex,
        StructPointerDecoder<Decoded_D3D12_MESSAGE>* pMessage,
        PointerDecoder<SIZE_T>* pMessageByteLength)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetMessage");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["MessageIndex"], MessageIndex, options);
        FieldToJson(args["pMessage"], pMessage, options);
        FieldToJson(args["pMessageByteLength"], pMessageByteLength, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetNumMessagesAllowedByStorageFilter");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetNumMessagesDeniedByStorageFilter");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetNumStoredMessages(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetNumStoredMessages");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetNumStoredMessagesAllowedByRetrievalFilter");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetNumMessagesDiscardedByMessageCountLimit");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetMessageCountLimit");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_AddStorageFilterEntries(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "AddStorageFilterEntries");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
        PointerDecoder<SIZE_T>* pFilterByteLength)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetStorageFilter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter, options);
        FieldToJson(args["pFilterByteLength"], pFilterByteLength, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_ClearStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "ClearStorageFilter");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PushEmptyStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PushEmptyStorageFilter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PushCopyOfStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PushCopyOfStorageFilter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PushStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PushStorageFilter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PopStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PopStorageFilter");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetStorageFilterStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetStorageFilterStackSize");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_AddRetrievalFilterEntries(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "AddRetrievalFilterEntries");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
        PointerDecoder<SIZE_T>* pFilterByteLength)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetRetrievalFilter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter, options);
        FieldToJson(args["pFilterByteLength"], pFilterByteLength, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_ClearRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "ClearRetrievalFilter");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PushEmptyRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PushEmptyRetrievalFilter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PushCopyOfRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PushCopyOfRetrievalFilter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PushRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PushRetrievalFilter");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PopRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PopRetrievalFilter");
    const JsonOptions& options = writer_->GetOptions();
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetRetrievalFilterStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetRetrievalFilterStackSize");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_AddMessage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_CATEGORY Category,
        D3D12_MESSAGE_SEVERITY Severity,
        D3D12_MESSAGE_ID ID,
        StringDecoder* pDescription)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "AddMessage");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Category"], Category, options);
        FieldToJson(args["Severity"], Severity, options);
        FieldToJson(args["ID"], ID, options);
        FieldToJson(args["pDescription"], pDescription, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_AddApplicationMessage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_SEVERITY Severity,
        StringDecoder* pDescription)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "AddApplicationMessage");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Severity"], Severity, options);
        FieldToJson(args["pDescription"], pDescription, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_SetBreakOnCategory(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_CATEGORY Category,
        BOOL bEnable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "SetBreakOnCategory");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Category"], Category, options);
        Bool32ToJson(args["bEnable"], bEnable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_SetBreakOnSeverity(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_SEVERITY Severity,
        BOOL bEnable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "SetBreakOnSeverity");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Severity"], Severity, options);
        Bool32ToJson(args["bEnable"], bEnable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_SetBreakOnID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_ID ID,
        BOOL bEnable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "SetBreakOnID");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ID"], ID, options);
        Bool32ToJson(args["bEnable"], bEnable, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetBreakOnCategory(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_CATEGORY Category)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetBreakOnCategory");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Category"], Category, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetBreakOnSeverity(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_SEVERITY Severity)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetBreakOnSeverity");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Severity"], Severity, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetBreakOnID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_ID ID)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetBreakOnID");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ID"], ID, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_SetMuteDebugOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL bMute)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "SetMuteDebugOutput");
    const JsonOptions& options = writer_->GetOptions();
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["bMute"], bMute, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetMuteDebugOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetMuteDebugOutput");
    const JsonOptions& options = writer_->GetOptions();
    Bool32ToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue1_RegisterMessageCallback(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t CallbackFunc,
        D3D12_MESSAGE_CALLBACK_FLAGS CallbackFilterFlags,
        uint64_t pContext,
        PointerDecoder<DWORD>* pCallbackCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue1", object_id, "RegisterMessageCallback");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["CallbackFunc"], CallbackFunc, options);
        FieldToJson_D3D12_MESSAGE_CALLBACK_FLAGS(args["CallbackFilterFlags"], CallbackFilterFlags, options);
        FieldToJson(args["pContext"], pContext, options);
        FieldToJson(args["pCallbackCookie"], pCallbackCookie, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue1_UnregisterMessageCallback(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DWORD CallbackCookie)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue1", object_id, "UnregisterMessageCallback");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["CallbackCookie"], CallbackCookie, options);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.20348.0
**
*/
void Dx12JsonConsumer::Process_IUnknown_QueryInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObject)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IUnknown", object_id, "QueryInterface");
    const JsonOptions& options = writer_->GetOptions();
    HresultToJson(method[format::kNameReturn], return_value, options);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid, options);
        FieldToJson(args["ppvObject"], ppvObject, options);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IUnknown_AddRef(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        ULONG return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IUnknown", object_id, "AddRef");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IUnknown_Release(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        ULONG return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IUnknown", object_id, "Release");
    const JsonOptions& options = writer_->GetOptions();
    FieldToJson(method[format::kNameReturn], return_value, options);
    writer_->WriteBlockEnd();
}



GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
