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

using util::Bool32ToJson;

/*
** This part is generated from d3d12.h in Windows SDK: 10.0.26100.0
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["pRootSignature"], pRootSignature);
        args["Version"] = Version;
        HandleToJson(args["ppBlob"], ppBlob);
        HandleToJson(args["ppErrorBlob"], ppErrorBlob);
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["pSrcData"], pSrcData);
        args["SrcDataSizeInBytes"] = SrcDataSizeInBytes;
        FieldToJson(args["pRootSignatureDeserializerInterface"], pRootSignatureDeserializerInterface);
        HandleToJson(args["ppRootSignatureDeserializer"], ppRootSignatureDeserializer);
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["pRootSignature"], pRootSignature);
        HandleToJson(args["ppBlob"], ppBlob);
        HandleToJson(args["ppErrorBlob"], ppErrorBlob);
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["pSrcData"], pSrcData);
        args["SrcDataSizeInBytes"] = SrcDataSizeInBytes;
        FieldToJson(args["pRootSignatureDeserializerInterface"], pRootSignatureDeserializerInterface);
        HandleToJson(args["ppRootSignatureDeserializer"], ppRootSignatureDeserializer);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        WStringDecoder* RootSignatureSubobjectName,
        Decoded_GUID pRootSignatureDeserializerInterface,
        PointerDecoder<uint64_t, void*>* ppRootSignatureDeserializer)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary");
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["pSrcData"], pSrcData);
        args["SrcDataSizeInBytes"] = SrcDataSizeInBytes;
        FieldToJson(args["RootSignatureSubobjectName"], RootSignatureSubobjectName);
        FieldToJson(args["pRootSignatureDeserializerInterface"], pRootSignatureDeserializerInterface);
        FieldToJson(args["ppRootSignatureDeserializer"], ppRootSignatureDeserializer);
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        HandleToJson(args["pAdapter"], pAdapter);
        args["MinimumFeatureLevel"] = MinimumFeatureLevel;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppDevice"], ppDevice);
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvDebug"], ppvDebug);
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        args["NumFeatures"] = NumFeatures;
        FieldToJson(args["pIIDs"], pIIDs);
        FieldToJson(args["pConfigurationStructs"], pConfigurationStructs);
        FieldToJson(args["pConfigurationStructSizes"], pConfigurationStructSizes);
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["rclsid"], rclsid);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvDebug"], ppvDebug);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["guid"], guid);
        FieldToJson(args["pDataSize"], pDataSize);
        FieldToJson(args["pData"], pData);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["guid"], guid);
        args["DataSize"] = DataSize;
        FieldToJson(args["pData"], pData);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["guid"], guid);
        HandleToJson(args["pData"], pData);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Name"], Name);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvDevice"], ppvDevice);
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
    FieldToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["convertToVersion"] = convertToVersion;
        FieldToJson(args["ppDesc"], ppDesc);
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
    FieldToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Heap_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_HEAP_DESC return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Heap", object_id, "GetDesc");
    FieldToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Subresource"] = Subresource;
        FieldToJson(args["pReadRange"], pReadRange);
        FieldToJson(args["ppData"], ppData);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Subresource"] = Subresource;
        FieldToJson(args["pWrittenRange"], pWrittenRange);
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
    FieldToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Resource_GetGPUVirtualAddress(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Resource", object_id, "GetGPUVirtualAddress");
    FieldToJsonAsHex(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["pDstData"] = pDstData;
        args["DstRowPitch"] = DstRowPitch;
        args["DstDepthPitch"] = DstDepthPitch;
        args["SrcSubresource"] = SrcSubresource;
        FieldToJson(args["pSrcBox"], pSrcBox);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeapProperties"], pHeapProperties);
        if (!pHeapFlags->IsNull())
        {
            args["pHeapFlags"] = D3D12_HEAP_FLAGS_t{ *pHeapFlags->GetPointer() };
        }
        else
        {
            FieldToJson(args["pHeapFlags"], nullptr);
        }
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
    HresultToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Fence_GetCompletedValue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Fence", object_id, "GetCompletedValue");
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Value"] = Value;
        args["hEvent"] = hEvent;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Value"] = Value;
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
    method[format::kNameReturn] = D3D12_FENCE_FLAGS_t{ return_value };
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["ppBlob"], ppBlob);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12PipelineState1_GetRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvRootSignature)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12PipelineState1", object_id, "GetRootSignature");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvRootSignature"], ppvRootSignature);
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
    FieldToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DescriptorHeap", object_id, "GetCPUDescriptorHandleForHeapStart");
    FieldToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DescriptorHeap", object_id, "GetGPUDescriptorHandleForHeapStart");
    FieldToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandList_GetType(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_COMMAND_LIST_TYPE return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandList", object_id, "GetType");
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_Close(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "Close");
    HresultToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pInitialState"], pInitialState);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pPipelineState"], pPipelineState);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["VertexCountPerInstance"] = VertexCountPerInstance;
        args["InstanceCount"] = InstanceCount;
        args["StartVertexLocation"] = StartVertexLocation;
        args["StartInstanceLocation"] = StartInstanceLocation;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["IndexCountPerInstance"] = IndexCountPerInstance;
        args["InstanceCount"] = InstanceCount;
        args["StartIndexLocation"] = StartIndexLocation;
        args["BaseVertexLocation"] = BaseVertexLocation;
        args["StartInstanceLocation"] = StartInstanceLocation;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["ThreadGroupCountX"] = ThreadGroupCountX;
        args["ThreadGroupCountY"] = ThreadGroupCountY;
        args["ThreadGroupCountZ"] = ThreadGroupCountZ;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDstBuffer"], pDstBuffer);
        args["DstOffset"] = DstOffset;
        HandleToJson(args["pSrcBuffer"], pSrcBuffer);
        args["SrcOffset"] = SrcOffset;
        args["NumBytes"] = NumBytes;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDst"], pDst);
        args["DstX"] = DstX;
        args["DstY"] = DstY;
        args["DstZ"] = DstZ;
        FieldToJson(args["pSrc"], pSrc);
        FieldToJson(args["pSrcBox"], pSrcBox);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDstResource"], pDstResource);
        HandleToJson(args["pSrcResource"], pSrcResource);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pTiledResource"], pTiledResource);
        FieldToJson(args["pTileRegionStartCoordinate"], pTileRegionStartCoordinate);
        FieldToJson(args["pTileRegionSize"], pTileRegionSize);
        HandleToJson(args["pBuffer"], pBuffer);
        args["BufferStartOffsetInBytes"] = BufferStartOffsetInBytes;
        args["Flags"] = D3D12_TILE_COPY_FLAGS_t{ Flags };
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDstResource"], pDstResource);
        args["DstSubresource"] = DstSubresource;
        HandleToJson(args["pSrcResource"], pSrcResource);
        args["SrcSubresource"] = SrcSubresource;
        args["Format"] = Format;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["PrimitiveTopology"] = PrimitiveTopology;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumViewports"] = NumViewports;
        FieldToJson(args["pViewports"], pViewports);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumRects"] = NumRects;
        FieldToJson(args["pRects"], pRects);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["BlendFactor"], BlendFactor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["StencilRef"] = StencilRef;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pPipelineState"], pPipelineState);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumBarriers"] = NumBarriers;
        FieldToJson(args["pBarriers"], pBarriers);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pCommandList"], pCommandList);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumDescriptorHeaps"] = NumDescriptorHeaps;
        HandleToJson(args["ppDescriptorHeaps"], ppDescriptorHeaps);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pRootSignature"], pRootSignature);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pRootSignature"], pRootSignature);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        FieldToJson(args["BaseDescriptor"], BaseDescriptor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        FieldToJson(args["BaseDescriptor"], BaseDescriptor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        args["SrcData"] = SrcData;
        args["DestOffsetIn32BitValues"] = DestOffsetIn32BitValues;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        args["SrcData"] = SrcData;
        args["DestOffsetIn32BitValues"] = DestOffsetIn32BitValues;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        args["Num32BitValuesToSet"] = Num32BitValuesToSet;
        FieldToJson(args["pSrcData"], pSrcData);
        args["DestOffsetIn32BitValues"] = DestOffsetIn32BitValues;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        args["Num32BitValuesToSet"] = Num32BitValuesToSet;
        FieldToJson(args["pSrcData"], pSrcData);
        args["DestOffsetIn32BitValues"] = DestOffsetIn32BitValues;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["RootParameterIndex"] = RootParameterIndex;
        FieldToJsonAsHex(args["BufferLocation"], BufferLocation);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pView"], pView);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["StartSlot"] = StartSlot;
        args["NumViews"] = NumViews;
        FieldToJson(args["pViews"], pViews);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["StartSlot"] = StartSlot;
        args["NumViews"] = NumViews;
        FieldToJson(args["pViews"], pViews);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumRenderTargetDescriptors"] = NumRenderTargetDescriptors;
        FieldToJson(args["pRenderTargetDescriptors"], pRenderTargetDescriptors);
        Bool32ToJson(args["RTsSingleHandleToDescriptorRange"], RTsSingleHandleToDescriptorRange);
        FieldToJson(args["pDepthStencilDescriptor"], pDepthStencilDescriptor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["DepthStencilView"], DepthStencilView);
        args["ClearFlags"] = D3D12_CLEAR_FLAGS_t{ ClearFlags };
        FieldToJson(args["Depth"], Depth);
        args["Stencil"] = Stencil;
        args["NumRects"] = NumRects;
        FieldToJson(args["pRects"], pRects);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["RenderTargetView"], RenderTargetView);
        FieldToJson(args["ColorRGBA"], ColorRGBA);
        args["NumRects"] = NumRects;
        FieldToJson(args["pRects"], pRects);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ViewGPUHandleInCurrentHeap"], ViewGPUHandleInCurrentHeap);
        FieldToJson(args["ViewCPUHandle"], ViewCPUHandle);
        HandleToJson(args["pResource"], pResource);
        FieldToJson(args["Values"], Values);
        args["NumRects"] = NumRects;
        FieldToJson(args["pRects"], pRects);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["ViewGPUHandleInCurrentHeap"], ViewGPUHandleInCurrentHeap);
        FieldToJson(args["ViewCPUHandle"], ViewCPUHandle);
        HandleToJson(args["pResource"], pResource);
        FieldToJson(args["Values"], Values);
        args["NumRects"] = NumRects;
        FieldToJson(args["pRects"], pRects);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        FieldToJson(args["pRegion"], pRegion);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pQueryHeap"], pQueryHeap);
        args["Type"] = Type;
        args["Index"] = Index;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pQueryHeap"], pQueryHeap);
        args["Type"] = Type;
        args["Index"] = Index;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pQueryHeap"], pQueryHeap);
        args["Type"] = Type;
        args["StartIndex"] = StartIndex;
        args["NumQueries"] = NumQueries;
        HandleToJson(args["pDestinationBuffer"], pDestinationBuffer);
        args["AlignedDestinationBufferOffset"] = AlignedDestinationBufferOffset;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pBuffer"], pBuffer);
        args["AlignedBufferOffset"] = AlignedBufferOffset;
        args["Operation"] = Operation;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Metadata"] = Metadata;
        FieldToJson(args["pData"], pData);
        args["Size"] = Size;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Metadata"] = Metadata;
        FieldToJson(args["pData"], pData);
        args["Size"] = Size;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList_EndEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList", object_id, "EndEvent");
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pCommandSignature"], pCommandSignature);
        args["MaxCommandCount"] = MaxCommandCount;
        HandleToJson(args["pArgumentBuffer"], pArgumentBuffer);
        args["ArgumentBufferOffset"] = ArgumentBufferOffset;
        HandleToJson(args["pCountBuffer"], pCountBuffer);
        args["CountBufferOffset"] = CountBufferOffset;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDstBuffer"], pDstBuffer);
        args["DstOffset"] = DstOffset;
        HandleToJson(args["pSrcBuffer"], pSrcBuffer);
        args["SrcOffset"] = SrcOffset;
        args["Dependencies"] = Dependencies;
        HandleToJson(args["ppDependentResources"], ppDependentResources);
        FieldToJson(args["pDependentSubresourceRanges"], pDependentSubresourceRanges);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDstBuffer"], pDstBuffer);
        args["DstOffset"] = DstOffset;
        HandleToJson(args["pSrcBuffer"], pSrcBuffer);
        args["SrcOffset"] = SrcOffset;
        args["Dependencies"] = Dependencies;
        HandleToJson(args["ppDependentResources"], ppDependentResources);
        FieldToJson(args["pDependentSubresourceRanges"], pDependentSubresourceRanges);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Min"], Min);
        FieldToJson(args["Max"], Max);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumSamplesPerPixel"] = NumSamplesPerPixel;
        args["NumPixels"] = NumPixels;
        FieldToJson(args["pSamplePositions"], pSamplePositions);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDstResource"], pDstResource);
        args["DstSubresource"] = DstSubresource;
        args["DstX"] = DstX;
        args["DstY"] = DstY;
        HandleToJson(args["pSrcResource"], pSrcResource);
        args["SrcSubresource"] = SrcSubresource;
        FieldToJson(args["pSrcRect"], pSrcRect);
        args["Format"] = Format;
        args["ResolveMode"] = ResolveMode;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["Mask"], Mask);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Count"] = Count;
        FieldToJson(args["pParams"], pParams);
        FieldToJson(args["pModes"], pModes);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        args["NumResourceRegions"] = NumResourceRegions;
        FieldToJson(args["pResourceRegionStartCoordinates"], pResourceRegionStartCoordinates);
        FieldToJson(args["pResourceRegionSizes"], pResourceRegionSizes);
        HandleToJson(args["pHeap"], pHeap);
        args["NumRanges"] = NumRanges;
        if (!pRangeFlags->IsNull())
        {
            args["pRangeFlags"] = D3D12_TILE_RANGE_FLAGS_t{ *pRangeFlags->GetPointer() };
        }
        else
        {
            FieldToJson(args["pRangeFlags"], nullptr);
        }
        FieldToJson(args["pHeapRangeStartOffsets"], pHeapRangeStartOffsets);
        FieldToJson(args["pRangeTileCounts"], pRangeTileCounts);
        args["Flags"] = D3D12_TILE_MAPPING_FLAGS_t{ Flags };
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDstResource"], pDstResource);
        FieldToJson(args["pDstRegionStartCoordinate"], pDstRegionStartCoordinate);
        HandleToJson(args["pSrcResource"], pSrcResource);
        FieldToJson(args["pSrcRegionStartCoordinate"], pSrcRegionStartCoordinate);
        FieldToJson(args["pRegionSize"], pRegionSize);
        args["Flags"] = D3D12_TILE_MAPPING_FLAGS_t{ Flags };
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumCommandLists"] = NumCommandLists;
        HandleToJson(args["ppCommandLists"], ppCommandLists);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Metadata"] = Metadata;
        FieldToJson(args["pData"], pData);
        args["Size"] = Size;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Metadata"] = Metadata;
        FieldToJson(args["pData"], pData);
        args["Size"] = Size;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue_EndEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue", object_id, "EndEvent");
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pFence"], pFence);
        args["Value"] = Value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pFence"], pFence);
        args["Value"] = Value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFrequency"], pFrequency);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pGpuTimestamp"], pGpuTimestamp);
        FieldToJson(args["pCpuTimestamp"], pCpuTimestamp);
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
    FieldToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue1_SetProcessPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_COMMAND_QUEUE_PROCESS_PRIORITY Priority)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue1", object_id, "SetProcessPriority");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Priority"] = Priority;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue1_GetProcessPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<D3D12_COMMAND_QUEUE_PROCESS_PRIORITY>* pOutValue)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue1", object_id, "GetProcessPriority");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutValue"], pOutValue);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue1_SetGlobalPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_COMMAND_QUEUE_GLOBAL_PRIORITY Priority)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue1", object_id, "SetGlobalPriority");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Priority"] = Priority;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12CommandQueue1_GetGlobalPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<D3D12_COMMAND_QUEUE_GLOBAL_PRIORITY>* pOutValue)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12CommandQueue1", object_id, "GetGlobalPriority");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutValue"], pOutValue);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device_GetNodeCount(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device", object_id, "GetNodeCount");
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppCommandQueue"], ppCommandQueue);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["type"] = type;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppCommandAllocator"], ppCommandAllocator);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppPipelineState"], ppPipelineState);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppPipelineState"], ppPipelineState);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["nodeMask"], nodeMask);
        args["type"] = type;
        HandleToJson(args["pCommandAllocator"], pCommandAllocator);
        HandleToJson(args["pInitialState"], pInitialState);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppCommandList"], ppCommandList);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDescriptorHeapDesc"], pDescriptorHeapDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvHeap"], ppvHeap);
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
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["DescriptorHeapType"] = DescriptorHeapType;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["nodeMask"], nodeMask);
        FieldToJson(args["pBlobWithRootSignature"], pBlobWithRootSignature);
        args["blobLengthInBytes"] = blobLengthInBytes;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvRootSignature"], ppvRootSignature);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["DestDescriptor"], DestDescriptor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["DestDescriptor"], DestDescriptor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        HandleToJson(args["pCounterResource"], pCounterResource);
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["DestDescriptor"], DestDescriptor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["DestDescriptor"], DestDescriptor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["DestDescriptor"], DestDescriptor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["DestDescriptor"], DestDescriptor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumDestDescriptorRanges"] = NumDestDescriptorRanges;
        FieldToJson(args["pDestDescriptorRangeStarts"], pDestDescriptorRangeStarts);
        FieldToJson(args["pDestDescriptorRangeSizes"], pDestDescriptorRangeSizes);
        args["NumSrcDescriptorRanges"] = NumSrcDescriptorRanges;
        FieldToJson(args["pSrcDescriptorRangeStarts"], pSrcDescriptorRangeStarts);
        FieldToJson(args["pSrcDescriptorRangeSizes"], pSrcDescriptorRangeSizes);
        args["DescriptorHeapsType"] = DescriptorHeapsType;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumDescriptors"] = NumDescriptors;
        FieldToJson(args["DestDescriptorRangeStart"], DestDescriptorRangeStart);
        FieldToJson(args["SrcDescriptorRangeStart"], SrcDescriptorRangeStart);
        args["DescriptorHeapsType"] = DescriptorHeapsType;
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
    FieldToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["visibleMask"], visibleMask);
        args["numResourceDescs"] = numResourceDescs;
        FieldToJson(args["pResourceDescs"], pResourceDescs);
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
    FieldToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["nodeMask"], nodeMask);
        args["heapType"] = heapType;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeapProperties"], pHeapProperties);
        args["HeapFlags"] = D3D12_HEAP_FLAGS_t{ HeapFlags };
        FieldToJson(args["pDesc"], pDesc);
        args["InitialResourceState"] = D3D12_RESOURCE_STATES_t{ InitialResourceState };
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue);
        FieldToJson(args["riidResource"], riidResource);
        HandleToJson(args["ppvResource"], ppvResource);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvHeap"], ppvHeap);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pHeap"], pHeap);
        args["HeapOffset"] = HeapOffset;
        FieldToJson(args["pDesc"], pDesc);
        args["InitialState"] = D3D12_RESOURCE_STATES_t{ InitialState };
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvResource"], ppvResource);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        args["InitialState"] = D3D12_RESOURCE_STATES_t{ InitialState };
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvResource"], ppvResource);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pObject"], pObject);
        FieldToJson(args["pAttributes"], pAttributes);
        args["Access"] = Access;
        FieldToJson(args["Name"], Name);
        FieldToJson(args["pHandle"], pHandle);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NTHandle"] = NTHandle;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvObj"], ppvObj);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Name"], Name);
        args["Access"] = Access;
        FieldToJson(args["pNTHandle"], pNTHandle);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumObjects"] = NumObjects;
        HandleToJson(args["ppObjects"], ppObjects);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumObjects"] = NumObjects;
        HandleToJson(args["ppObjects"], ppObjects);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["InitialValue"] = InitialValue;
        args["Flags"] = D3D12_FENCE_FLAGS_t{ Flags };
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppFence"], ppFence);
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
    HresultToJson(method[format::kNameReturn], return_value);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResourceDesc"], pResourceDesc);
        args["FirstSubresource"] = FirstSubresource;
        args["NumSubresources"] = NumSubresources;
        args["BaseOffset"] = BaseOffset;
        FieldToJson(args["pLayouts"], pLayouts);
        FieldToJson(args["pNumRows"], pNumRows);
        FieldToJson(args["pRowSizeInBytes"], pRowSizeInBytes);
        FieldToJson(args["pTotalBytes"], pTotalBytes);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvHeap"], ppvHeap);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        HandleToJson(args["pRootSignature"], pRootSignature);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvCommandSignature"], ppvCommandSignature);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pTiledResource"], pTiledResource);
        FieldToJson(args["pNumTilesForEntireResource"], pNumTilesForEntireResource);
        FieldToJson(args["pPackedMipDesc"], pPackedMipDesc);
        FieldToJson(args["pStandardTileShapeForNonPackedMips"], pStandardTileShapeForNonPackedMips);
        FieldToJson(args["pNumSubresourceTilings"], pNumSubresourceTilings);
        args["FirstSubresourceTilingToGet"] = FirstSubresourceTilingToGet;
        FieldToJson(args["pSubresourceTilingsForNonPackedMips"], pSubresourceTilingsForNonPackedMips);
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
    FieldToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pName"], pName);
        HandleToJson(args["pPipeline"], pPipeline);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pName"], pName);
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppPipelineState"], ppPipelineState);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pName"], pName);
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppPipelineState"], ppPipelineState);
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
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pData"], pData);
        args["DataSizeInBytes"] = DataSizeInBytes;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pName"], pName);
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppPipelineState"], ppPipelineState);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pLibraryBlob"], pLibraryBlob);
        args["BlobLength"] = BlobLength;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppPipelineLibrary"], ppPipelineLibrary);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["ppFences"], ppFences);
        FieldToJson(args["pFenceValues"], pFenceValues);
        args["NumFences"] = NumFences;
        args["Flags"] = D3D12_MULTIPLE_FENCE_WAIT_FLAGS_t{ Flags };
        args["hEvent"] = hEvent;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumObjects"] = NumObjects;
        HandleToJson(args["ppObjects"], ppObjects);
        FieldToJson(args["pPriorities"], pPriorities);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppPipelineState"], ppPipelineState);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["pAddress"] = pAddress;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvHeap"], ppvHeap);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["hFileMapping"] = hFileMapping;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvHeap"], ppvHeap);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Flags"] = D3D12_RESIDENCY_FLAGS_t{ Flags };
        args["NumObjects"] = NumObjects;
        HandleToJson(args["ppObjects"], ppObjects);
        HandleToJson(args["pFenceToSignal"], pFenceToSignal);
        args["FenceValueToSignal"] = FenceValueToSignal;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppFence"], ppFence);
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
    method[format::kNameReturn] = D3D12_PROTECTED_SESSION_STATUS_t{ return_value };
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ProtectedResourceSession", object_id, "GetDesc");
    FieldToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["nodeMask"], nodeMask);
        args["type"] = type;
        args["flags"] = D3D12_COMMAND_LIST_FLAGS_t{ flags };
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppCommandList"], ppCommandList);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppSession"], ppSession);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeapProperties"], pHeapProperties);
        args["HeapFlags"] = D3D12_HEAP_FLAGS_t{ HeapFlags };
        FieldToJson(args["pDesc"], pDesc);
        args["InitialResourceState"] = D3D12_RESOURCE_STATES_t{ InitialResourceState };
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue);
        HandleToJson(args["pProtectedSession"], pProtectedSession);
        FieldToJson(args["riidResource"], riidResource);
        HandleToJson(args["ppvResource"], ppvResource);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        HandleToJson(args["pProtectedSession"], pProtectedSession);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvHeap"], ppvHeap);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        args["InitialState"] = D3D12_RESOURCE_STATES_t{ InitialState };
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue);
        HandleToJson(args["pProtectedSession"], pProtectedSession);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvResource"], ppvResource);
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
    FieldToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["visibleMask"], visibleMask);
        args["numResourceDescs"] = numResourceDescs;
        FieldToJson(args["pResourceDescs"], pResourceDescs);
        FieldToJson(args["pResourceAllocationInfo1"], pResourceAllocationInfo1);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NewState"] = NewState;
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
    FieldToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppv"], ppv);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riidResource"], riidResource);
        HandleToJson(args["ppvResource"], ppvResource);
        FieldToJson(args["riidQueue"], riidQueue);
        HandleToJson(args["ppvQueue"], ppvQueue);
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
    HresultToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pObject"], pObject);
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
    FieldToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pExportName"], pExportName);
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
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pExportName"], pExportName);
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
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectProperties_SetPipelineStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 PipelineStackSizeInBytes)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectProperties", object_id, "SetPipelineStackSize");
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["PipelineStackSizeInBytes"] = PipelineStackSizeInBytes;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectProperties1_GetProgramIdentifier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_PROGRAM_IDENTIFIER return_value,
        WStringDecoder* pProgramName)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectProperties1", object_id, "GetProgramIdentifier");
    FieldToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pProgramName"], pProgramName);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectProperties2_GetGlobalRootSignatureForProgram(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pProgramName,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvRootSignature)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectProperties2", object_id, "GetGlobalRootSignatureForProgram");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pProgramName"], pProgramName);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvRootSignature"], ppvRootSignature);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectProperties2_GetGlobalRootSignatureForShader(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pExportName,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvRootSignature)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectProperties2", object_id, "GetGlobalRootSignatureForShader");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pExportName"], pExportName);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvRootSignature"], ppvRootSignature);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetNumWorkGraphs(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetNumWorkGraphs");
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetProgramName(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        WStringDecoder* return_value,
        UINT WorkGraphIndex)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetProgramName");
    FieldToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetWorkGraphIndex(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        WStringDecoder* pProgramName)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetWorkGraphIndex");
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pProgramName"], pProgramName);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetNumNodes(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        UINT WorkGraphIndex)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetNumNodes");
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetNodeID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_NODE_ID return_value,
        UINT WorkGraphIndex,
        UINT NodeIndex)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetNodeID");
    FieldToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
        args["NodeIndex"] = NodeIndex;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetNodeIndex(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        UINT WorkGraphIndex,
        Decoded_D3D12_NODE_ID NodeID)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetNodeIndex");
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
        FieldToJson(args["NodeID"], NodeID);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        UINT WorkGraphIndex,
        UINT NodeIndex)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetNodeLocalRootArgumentsTableIndex");
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
        args["NodeIndex"] = NodeIndex;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetNumEntrypoints(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        UINT WorkGraphIndex)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetNumEntrypoints");
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetEntrypointID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_NODE_ID return_value,
        UINT WorkGraphIndex,
        UINT EntrypointIndex)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetEntrypointID");
    FieldToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
        args["EntrypointIndex"] = EntrypointIndex;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetEntrypointIndex(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        UINT WorkGraphIndex,
        Decoded_D3D12_NODE_ID NodeID)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetEntrypointIndex");
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
        FieldToJson(args["NodeID"], NodeID);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        UINT WorkGraphIndex,
        UINT EntrypointIndex)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetEntrypointRecordSizeInBytes");
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
        args["EntrypointIndex"] = EntrypointIndex;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT WorkGraphIndex,
        StructPointerDecoder<Decoded_D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS>* pWorkGraphMemoryRequirements)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetWorkGraphMemoryRequirements");
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
        FieldToJson(args["pWorkGraphMemoryRequirements"], pWorkGraphMemoryRequirements);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12WorkGraphProperties_GetEntrypointRecordAlignmentInBytes(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        UINT WorkGraphIndex,
        UINT EntrypointIndex)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12WorkGraphProperties", object_id, "GetEntrypointRecordAlignmentInBytes");
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WorkGraphIndex"] = WorkGraphIndex;
        args["EntrypointIndex"] = EntrypointIndex;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pOwner"], pOwner);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvTracker"], ppvTracker);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device5_RemoveDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device5", object_id, "RemoveDevice");
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pNumMetaCommands"], pNumMetaCommands);
        FieldToJson(args["pDescs"], pDescs);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["CommandId"], CommandId);
        args["Stage"] = Stage;
        FieldToJson(args["pTotalStructureSizeInBytes"], pTotalStructureSizeInBytes);
        FieldToJson(args["pParameterCount"], pParameterCount);
        FieldToJson(args["pParameterDescs"], pParameterDescs);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["CommandId"], CommandId);
        FieldToJsonAsFixedWidthBinary(args["NodeMask"], NodeMask);
        FieldToJson(args["pCreationParametersData"], pCreationParametersData);
        args["CreationParametersDataSizeInBytes"] = CreationParametersDataSizeInBytes;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppMetaCommand"], ppMetaCommand);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppStateObject"], ppStateObject);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["pInfo"], pInfo);
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
    method[format::kNameReturn] = D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS_t{ return_value };
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["SerializedDataType"] = SerializedDataType;
        FieldToJson(args["pIdentifierToCheck"], pIdentifierToCheck);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Enablement"] = Enablement;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Enablement"] = Enablement;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Enablement"] = Enablement;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Enablement"] = Enablement;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["MarkersOnly"], MarkersOnly);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutput"], pOutput);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutput"], pOutput);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutput"], pOutput);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutput"], pOutput);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pOutput"], pOutput);
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
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Mode"] = Mode;
        args["MeasurementsAction"] = MeasurementsAction;
        args["hEventToSignalUponCompletion"] = hEventToSignalUponCompletion;
        Bool32ToJson(args["pbFurtherMeasurementsDesired"], pbFurtherMeasurementsDesired);
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
    FieldToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pAddition"], pAddition);
        HandleToJson(args["pStateObjectToGrowFrom"], pStateObjectToGrowFrom);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppNewStateObject"], ppNewStateObject);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppSession"], ppSession);
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
    FieldToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["visibleMask"], visibleMask);
        args["numResourceDescs"] = numResourceDescs;
        FieldToJson(args["pResourceDescs"], pResourceDescs);
        FieldToJson(args["pResourceAllocationInfo1"], pResourceAllocationInfo1);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeapProperties"], pHeapProperties);
        args["HeapFlags"] = D3D12_HEAP_FLAGS_t{ HeapFlags };
        FieldToJson(args["pDesc"], pDesc);
        args["InitialResourceState"] = D3D12_RESOURCE_STATES_t{ InitialResourceState };
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue);
        HandleToJson(args["pProtectedSession"], pProtectedSession);
        FieldToJson(args["riidResource"], riidResource);
        HandleToJson(args["ppvResource"], ppvResource);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pHeap"], pHeap);
        args["HeapOffset"] = HeapOffset;
        FieldToJson(args["pDesc"], pDesc);
        args["InitialState"] = D3D12_RESOURCE_STATES_t{ InitialState };
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvResource"], ppvResource);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pTargetedResource"], pTargetedResource);
        HandleToJson(args["pFeedbackResource"], pFeedbackResource);
        FieldToJson(args["DestDescriptor"], DestDescriptor);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pResourceDesc"], pResourceDesc);
        args["FirstSubresource"] = FirstSubresource;
        args["NumSubresources"] = NumSubresources;
        args["BaseOffset"] = BaseOffset;
        FieldToJson(args["pLayouts"], pLayouts);
        FieldToJson(args["pNumRows"], pNumRows);
        FieldToJson(args["pRowSizeInBytes"], pRowSizeInBytes);
        FieldToJson(args["pTotalBytes"], pTotalBytes);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppProtectedSession"], ppProtectedSession);
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
    FieldToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppProtectedSession"], ppProtectedSession);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pProtectedResourceSession"], pProtectedResourceSession);
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
    method[format::kNameReturn] = return_value;
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Stage"] = Stage;
        args["ParameterIndex"] = ParameterIndex;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumRenderTargets"] = NumRenderTargets;
        FieldToJson(args["pRenderTargets"], pRenderTargets);
        FieldToJson(args["pDepthStencil"], pDepthStencil);
        args["Flags"] = D3D12_RENDER_PASS_FLAGS_t{ Flags };
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList4_EndRenderPass(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList4", object_id, "EndRenderPass");
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pMetaCommand"], pMetaCommand);
        FieldToJson(args["pInitializationParametersData"], pInitializationParametersData);
        args["InitializationParametersDataSizeInBytes"] = InitializationParametersDataSizeInBytes;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pMetaCommand"], pMetaCommand);
        FieldToJson(args["pExecutionParametersData"], pExecutionParametersData);
        args["ExecutionParametersDataSizeInBytes"] = ExecutionParametersDataSizeInBytes;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        args["NumPostbuildInfoDescs"] = NumPostbuildInfoDescs;
        FieldToJson(args["pPostbuildInfoDescs"], pPostbuildInfoDescs);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        args["NumSourceAccelerationStructures"] = NumSourceAccelerationStructures;
        FieldToJsonAsHex(args["pSourceAccelerationStructureData"], pSourceAccelerationStructureData);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsHex(args["DestAccelerationStructureData"], DestAccelerationStructureData);
        FieldToJsonAsHex(args["SourceAccelerationStructureData"], SourceAccelerationStructureData);
        args["Mode"] = Mode;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pStateObject"], pStateObject);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pKey"], pKey);
        args["KeySize"] = KeySize;
        FieldToJson(args["pValue"], pValue);
        FieldToJson(args["pValueSize"], pValueSize);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pKey"], pKey);
        args["KeySize"] = KeySize;
        FieldToJson(args["pValue"], pValue);
        args["ValueSize"] = ValueSize;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ShaderCacheSession_SetDeleteOnDestroy(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ShaderCacheSession", object_id, "SetDeleteOnDestroy");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12ShaderCacheSession_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_SHADER_CACHE_SESSION_DESC return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12ShaderCacheSession", object_id, "GetDesc");
    FieldToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvSession"], ppvSession);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Kinds"] = D3D12_SHADER_CACHE_KIND_FLAGS_t{ Kinds };
        args["Control"] = D3D12_SHADER_CACHE_CONTROL_FLAGS_t{ Control };
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["CreatorID"], CreatorID);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppCommandQueue"], ppCommandQueue);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHeapProperties"], pHeapProperties);
        args["HeapFlags"] = D3D12_HEAP_FLAGS_t{ HeapFlags };
        FieldToJson(args["pDesc"], pDesc);
        args["InitialLayout"] = InitialLayout;
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue);
        HandleToJson(args["pProtectedSession"], pProtectedSession);
        args["NumCastableFormats"] = NumCastableFormats;
        FieldToJson(args["pCastableFormats"], pCastableFormats);
        FieldToJson(args["riidResource"], riidResource);
        HandleToJson(args["ppvResource"], ppvResource);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pHeap"], pHeap);
        args["HeapOffset"] = HeapOffset;
        FieldToJson(args["pDesc"], pDesc);
        args["InitialLayout"] = InitialLayout;
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue);
        args["NumCastableFormats"] = NumCastableFormats;
        FieldToJson(args["pCastableFormats"], pCastableFormats);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvResource"], ppvResource);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        args["InitialLayout"] = InitialLayout;
        FieldToJson(args["pOptimizedClearValue"], pOptimizedClearValue);
        HandleToJson(args["pProtectedSession"], pProtectedSession);
        args["NumCastableFormats"] = NumCastableFormats;
        FieldToJson(args["pCastableFormats"], pCastableFormats);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvResource"], ppvResource);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["DestDescriptor"], DestDescriptor);
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
    FieldToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["visibleMask"], visibleMask);
        args["numResourceDescs"] = numResourceDescs;
        FieldToJson(args["pResourceDescs"], pResourceDescs);
        FieldToJson(args["pNumCastableFormats"], pNumCastableFormats);
        FieldToJson(args["ppCastableFormats"], ppCastableFormats);
        FieldToJson(args["pResourceAllocationInfo1"], pResourceAllocationInfo1);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device13_OpenExistingHeapFromAddress1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t pAddress,
        SIZE_T size,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device13", object_id, "OpenExistingHeapFromAddress1");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["pAddress"] = pAddress;
        args["size"] = size;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvHeap"], ppvHeap);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Device14_CreateRootSignatureFromSubobjectInLibrary(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT nodeMask,
        PointerDecoder<uint8_t>* pLibraryBlob,
        SIZE_T blobLengthInBytes,
        WStringDecoder* subobjectName,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvRootSignature)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Device14", object_id, "CreateRootSignatureFromSubobjectInLibrary");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsFixedWidthBinary(args["nodeMask"], nodeMask);
        FieldToJson(args["pLibraryBlob"], pLibraryBlob);
        args["blobLengthInBytes"] = blobLengthInBytes;
        FieldToJson(args["subobjectName"], subobjectName);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvRootSignature"], ppvRootSignature);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectDatabase_SetApplicationDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_APPLICATION_DESC>* pApplicationDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectDatabase", object_id, "SetApplicationDesc");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pApplicationDesc"], pApplicationDesc);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectDatabase_GetApplicationDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t CallbackFunc,
        uint64_t pContext)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectDatabase", object_id, "GetApplicationDesc");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["CallbackFunc"] = CallbackFunc;
        args["pContext"] = pContext;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectDatabase_StorePipelineStateDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pKey,
        UINT KeySize,
        UINT Version,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectDatabase", object_id, "StorePipelineStateDesc");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pKey"], pKey);
        args["KeySize"] = KeySize;
        args["Version"] = Version;
        FieldToJson(args["pDesc"], pDesc);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectDatabase_FindPipelineStateDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pKey,
        UINT KeySize,
        uint64_t CallbackFunc,
        uint64_t pContext)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectDatabase", object_id, "FindPipelineStateDesc");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pKey"], pKey);
        args["KeySize"] = KeySize;
        args["CallbackFunc"] = CallbackFunc;
        args["pContext"] = pContext;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectDatabase_StoreStateObjectDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pKey,
        UINT KeySize,
        UINT Version,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
        PointerDecoder<uint8_t>* pStateObjectToGrowFromKey,
        UINT StateObjectToGrowFromKeySize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectDatabase", object_id, "StoreStateObjectDesc");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pKey"], pKey);
        args["KeySize"] = KeySize;
        args["Version"] = Version;
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["pStateObjectToGrowFromKey"], pStateObjectToGrowFromKey);
        args["StateObjectToGrowFromKeySize"] = StateObjectToGrowFromKeySize;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectDatabase_FindStateObjectDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pKey,
        UINT KeySize,
        uint64_t CallbackFunc,
        uint64_t pContext)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectDatabase", object_id, "FindStateObjectDesc");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pKey"], pKey);
        args["KeySize"] = KeySize;
        args["CallbackFunc"] = CallbackFunc;
        args["pContext"] = pContext;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectDatabase_FindObjectVersion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pKey,
        UINT KeySize,
        PointerDecoder<UINT>* pVersion)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectDatabase", object_id, "FindObjectVersion");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pKey"], pKey);
        args["KeySize"] = KeySize;
        FieldToJson(args["pVersion"], pVersion);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pObject"], pObject);
        FieldToJson(args["pHandle"], pHandle);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pFence"], pFence);
        args["FenceValue"] = FenceValue;
        FieldToJson(args["pFenceFd"], pFenceFd);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["bEnable"], bEnable);
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
    Bool32ToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Tools1_ReserveGPUVARangesAtCreate(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE>* pRanges,
        UINT uiNumRanges)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Tools1", object_id, "ReserveGPUVARangesAtCreate");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRanges"], pRanges);
        args["uiNumRanges"] = uiNumRanges;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Tools1_ClearReservedGPUVARangesList(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Tools1", object_id, "ClearReservedGPUVARangesList");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Tools2_SetApplicationSpecificDriverState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pAdapter,
        format::HandleId pBlob)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Tools2", object_id, "SetApplicationSpecificDriverState");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pAdapter"], pAdapter);
        HandleToJson(args["pBlob"], pBlob);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12PageableTools_GetAllocation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE>* pAllocation)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12PageableTools", object_id, "GetAllocation");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pAllocation"], pAllocation);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceTools_SetNextAllocationAddress(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS nextAllocationVirtualAddress)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceTools", object_id, "SetNextAllocationAddress");
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJsonAsHex(args["nextAllocationVirtualAddress"], nextAllocationVirtualAddress);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceTools1_GetApplicationSpecificDriverState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceTools1", object_id, "GetApplicationSpecificDriverState");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["ppBlob"], ppBlob);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceTools1_GetApplicationSpecificDriverBlobStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceTools1", object_id, "GetApplicationSpecificDriverBlobStatus");
    method[format::kNameReturn] = D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS_t{ return_value };
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["SDKVersion"] = SDKVersion;
        FieldToJson(args["SDKPath"], SDKPath);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["SDKVersion"] = SDKVersion;
        FieldToJson(args["SDKPath"], SDKPath);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvFactory"], ppvFactory);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12SDKConfiguration1_FreeUnusedSDKs(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12SDKConfiguration1", object_id, "FreeUnusedSDKs");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceFactory_InitializeFromGlobalState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceFactory", object_id, "InitializeFromGlobalState");
    HresultToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceFactory_ApplyToGlobalState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceFactory", object_id, "ApplyToGlobalState");
    HresultToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["flags"] = D3D12_DEVICE_FACTORY_FLAGS_t{ flags };
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
    method[format::kNameReturn] = D3D12_DEVICE_FACTORY_FLAGS_t{ return_value };
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["clsid"], clsid);
        FieldToJson(args["iid"], iid);
        HandleToJson(args["ppv"], ppv);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumFeatures"] = NumFeatures;
        FieldToJson(args["pIIDs"], pIIDs);
        FieldToJson(args["pConfigurationStructs"], pConfigurationStructs);
        FieldToJson(args["pConfigurationStructSizes"], pConfigurationStructSizes);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["adapter"], adapter);
        args["FeatureLevel"] = FeatureLevel;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvDevice"], ppvDevice);
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
    FieldToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pGuids"], pGuids);
        args["NumGuids"] = NumGuids;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        HandleToJson(args["ppResult"], ppResult);
        HandleToJson(args["ppError"], ppError);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pBlob"], pBlob);
        args["Size"] = Size;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvDeserializer"], ppvDeserializer);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pLibraryBlob,
        SIZE_T Size,
        WStringDecoder* RootSignatureSubobjectName,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDeserializer)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12DeviceConfiguration1", object_id, "CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pLibraryBlob"], pLibraryBlob);
        args["Size"] = Size;
        FieldToJson(args["RootSignatureSubobjectName"], RootSignatureSubobjectName);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvDeserializer"], ppvDeserializer);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12StateObjectDatabaseFactory_CreateStateObjectDatabaseFromFile(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pDatabaseFile,
        D3D12_STATE_OBJECT_DATABASE_FLAGS flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvStateObjectDatabase)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12StateObjectDatabaseFactory", object_id, "CreateStateObjectDatabaseFromFile");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDatabaseFile"], pDatabaseFile);
        args["flags"] = D3D12_STATE_OBJECT_DATABASE_FLAGS_t{ flags };
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvStateObjectDatabase"], ppvStateObjectDatabase);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["baseShadingRate"] = baseShadingRate;
        FieldToJson(args["combiners"], combiners);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["shadingRateImage"], shadingRateImage);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["ThreadGroupCountX"] = ThreadGroupCountX;
        args["ThreadGroupCountY"] = ThreadGroupCountY;
        args["ThreadGroupCountZ"] = ThreadGroupCountZ;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumBarrierGroups"] = NumBarrierGroups;
        FieldToJson(args["pBarrierGroups"], pBarrierGroups);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["FrontStencilRef"] = FrontStencilRef;
        args["BackStencilRef"] = BackStencilRef;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["DepthBias"], DepthBias);
        FieldToJson(args["DepthBiasClamp"], DepthBiasClamp);
        FieldToJson(args["SlopeScaledDepthBias"], SlopeScaledDepthBias);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["IBStripCutValue"] = IBStripCutValue;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList10_SetProgram(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_SET_PROGRAM_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList10", object_id, "SetProgram");
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GraphicsCommandList10_DispatchGraph(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_DISPATCH_GRAPH_DESC>* pDesc)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GraphicsCommandList10", object_id, "DispatchGraph");
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pD3D12Device"], pD3D12Device);
        FieldToJsonAsFixedWidthBinary(args["NodeMask"], NodeMask);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvDSRDevice"], ppvDSRDevice);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GBVDiagnostics_GetGBVEntireSubresourceStatesData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pResource,
        PointerDecoder<int>* pData,
        UINT DataSize)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GBVDiagnostics", object_id, "GetGBVEntireSubresourceStatesData");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        FieldToJson(args["pData"], pData);
        args["DataSize"] = DataSize;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GBVDiagnostics_GetGBVSubresourceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pResource,
        UINT Subresource,
        PointerDecoder<int>* pData)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GBVDiagnostics", object_id, "GetGBVSubresourceState");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        args["Subresource"] = Subresource;
        FieldToJson(args["pData"], pData);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GBVDiagnostics_GetGBVResourceUniformState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pResource,
        PointerDecoder<int>* pData)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GBVDiagnostics", object_id, "GetGBVResourceUniformState");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        FieldToJson(args["pData"], pData);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GBVDiagnostics_GetGBVResourceInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDesc,
        PointerDecoder<UINT32>* pResourceHash,
        PointerDecoder<UINT32>* pSubresourceStatesByteOffset)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GBVDiagnostics", object_id, "GetGBVResourceInfo");
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        FieldToJson(args["pResourceDesc"], pResourceDesc);
        FieldToJson(args["pResourceHash"], pResourceHash);
        FieldToJson(args["pSubresourceStatesByteOffset"], pSubresourceStatesByteOffset);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GBVDiagnostics_GBVReserved0(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GBVDiagnostics", object_id, "GBVReserved0");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12GBVDiagnostics_GBVReserved1(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12GBVDiagnostics", object_id, "GBVReserved1");
    writer_->WriteBlockEnd();
}

/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.26100.0
**
*/
void Dx12JsonConsumer::Process_ID3D10Blob_GetBufferPointer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        uint64_t return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D10Blob", object_id, "GetBufferPointer");
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D10Blob_GetBufferSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        SIZE_T return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D10Blob", object_id, "GetBufferSize");
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["callbackFn"] = callbackFn;
        args["pData"] = pData;
        FieldToJson(args["pCallbackID"], pCallbackID);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["callbackID"] = callbackID;
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from d3d12sdklayers.h in Windows SDK: 10.0.26100.0
**
*/
void Dx12JsonConsumer::Process_ID3D12Debug_EnableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug", object_id, "EnableDebugLayer");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug1_EnableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug1", object_id, "EnableDebugLayer");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug1_SetEnableGPUBasedValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug1", object_id, "SetEnableGPUBasedValidation");
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Flags"] = D3D12_GPU_BASED_VALIDATION_FLAGS_t{ Flags };
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Flags"] = D3D12_GPU_BASED_VALIDATION_FLAGS_t{ Flags };
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug4_DisableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug4", object_id, "DisableDebugLayer");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12Debug5_SetEnableAutoName(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12Debug5", object_id, "SetEnableAutoName");
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Enable"], Enable);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Type"] = Type;
        FieldToJson(args["pData"], pData);
        args["DataSize"] = DataSize;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Type"] = Type;
        FieldToJson(args["pData"], pData);
        args["DataSize"] = DataSize;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Flags"] = D3D12_RLDO_FLAGS_t{ Flags };
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Mask"] = Mask;
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
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Flags"] = D3D12_RLDO_FLAGS_t{ Flags };
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Type"] = Type;
        FieldToJson(args["pData"], pData);
        args["DataSize"] = DataSize;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Type"] = Type;
        FieldToJson(args["pData"], pData);
        args["DataSize"] = DataSize;
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
    Bool32ToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        args["Subresource"] = Subresource;
        args["State"] = State;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        args["Subresource"] = Subresource;
        args["Access"] = Access;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        args["Subresource"] = Subresource;
        args["Layout"] = Layout;
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
    Bool32ToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        args["Subresource"] = Subresource;
        args["State"] = State;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Type"] = Type;
        FieldToJson(args["pData"], pData);
        args["DataSize"] = DataSize;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Type"] = Type;
        FieldToJson(args["pData"], pData);
        args["DataSize"] = DataSize;
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
    Bool32ToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        args["Subresource"] = Subresource;
        args["State"] = State;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Mask"] = Mask;
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
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Type"] = Type;
        FieldToJson(args["pData"], pData);
        args["DataSize"] = DataSize;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Type"] = Type;
        FieldToJson(args["pData"], pData);
        args["DataSize"] = DataSize;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        args["Subresource"] = Subresource;
        args["Access"] = Access;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        args["Subresource"] = Subresource;
        args["Layout"] = Layout;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pResource"], pResource);
        args["Subresource"] = Subresource;
        args["window"] = window;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pFence"], pFence);
        args["FenceValue"] = FenceValue;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["guid"], guid);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["guid"], guid);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Subresource"] = Subresource;
        FieldToJson(args["pWrittenRange"], pWrittenRange);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["MessageCountLimit"] = MessageCountLimit;
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_ClearStoredMessages(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "ClearStoredMessages");
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["MessageIndex"] = MessageIndex;
        FieldToJson(args["pMessage"], pMessage);
        FieldToJson(args["pMessageByteLength"], pMessageByteLength);
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
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetNumMessagesDeniedByStorageFilter");
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetNumStoredMessages(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetNumStoredMessages");
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetNumStoredMessagesAllowedByRetrievalFilter");
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetNumMessagesDiscardedByMessageCountLimit");
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetMessageCountLimit");
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter);
        FieldToJson(args["pFilterByteLength"], pFilterByteLength);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_ClearStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "ClearStorageFilter");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PushEmptyStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PushEmptyStorageFilter");
    HresultToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PushCopyOfStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PushCopyOfStorageFilter");
    HresultToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PopStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PopStorageFilter");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetStorageFilterStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetStorageFilterStackSize");
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter);
        FieldToJson(args["pFilterByteLength"], pFilterByteLength);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_ClearRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "ClearRetrievalFilter");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PushEmptyRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PushEmptyRetrievalFilter");
    HresultToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PushCopyOfRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PushCopyOfRetrievalFilter");
    HresultToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFilter"], pFilter);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_PopRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "PopRetrievalFilter");
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_ID3D12InfoQueue_GetRetrievalFilterStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "ID3D12InfoQueue", object_id, "GetRetrievalFilterStackSize");
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Category"] = Category;
        args["Severity"] = Severity;
        args["ID"] = ID;
        FieldToJson(args["pDescription"], pDescription);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Severity"] = Severity;
        FieldToJson(args["pDescription"], pDescription);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Category"] = Category;
        Bool32ToJson(args["bEnable"], bEnable);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Severity"] = Severity;
        Bool32ToJson(args["bEnable"], bEnable);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["ID"] = ID;
        Bool32ToJson(args["bEnable"], bEnable);
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
    Bool32ToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Category"] = Category;
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
    Bool32ToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Severity"] = Severity;
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
    Bool32ToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["ID"] = ID;
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["bMute"], bMute);
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
    Bool32ToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["CallbackFunc"] = CallbackFunc;
        args["CallbackFilterFlags"] = D3D12_MESSAGE_CALLBACK_FLAGS_t{ CallbackFilterFlags };
        args["pContext"] = pContext;
        FieldToJson(args["pCallbackCookie"], pCallbackCookie);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["CallbackCookie"] = CallbackCookie;
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi.h in Windows SDK: 10.0.26100.0
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppFactory"], ppFactory);
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppFactory"], ppFactory);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Name"], Name);
        args["DataSize"] = DataSize;
        FieldToJson(args["pData"], pData);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Name"], Name);
        HandleToJson(args["pUnknown"], pUnknown);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["Name"], Name);
        FieldToJson(args["pDataSize"], pDataSize);
        FieldToJson(args["pData"], pData);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppParent"], ppParent);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppDevice"], ppDevice);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pSharedHandle"], pSharedHandle);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pUsage"], pUsage);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["EvictionPriority"] = EvictionPriority;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pEvictionPriority"], pEvictionPriority);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Key"] = Key;
        args["dwMilliseconds"] = dwMilliseconds;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Key"] = Key;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pLockedRect"], pLockedRect);
        args["MapFlags"] = MapFlags;
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
    HresultToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Discard"], Discard);
        FieldToJson(args["phdc"], phdc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDirtyRect"], pDirtyRect);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Output"] = Output;
        HandleToJson(args["ppOutput"], ppOutput);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["InterfaceName"], InterfaceName);
        FieldToJson(args["pUMDVersion"], pUMDVersion);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["EnumFormat"] = EnumFormat;
        args["Flags"] = Flags;
        FieldToJson(args["pNumModes"], pNumModes);
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pModeToMatch"], pModeToMatch);
        FieldToJson(args["pClosestMatch"], pClosestMatch);
        HandleToJson(args["pConcernedDevice"], pConcernedDevice);
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
    HresultToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDevice"], pDevice);
        Bool32ToJson(args["Exclusive"], Exclusive);
    }
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutput_ReleaseOwnership(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutput", object_id, "ReleaseOwnership");
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pGammaCaps"], pGammaCaps);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pArray"], pArray);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pArray"], pArray);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pScanoutSurface"], pScanoutSurface);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDestination"], pDestination);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pStats"], pStats);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["SyncInterval"] = SyncInterval;
        args["Flags"] = Flags;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Buffer"] = Buffer;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppSurface"], ppSurface);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["Fullscreen"], Fullscreen);
        HandleToJson(args["pTarget"], pTarget);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["pFullscreen"], pFullscreen);
        HandleToJson(args["ppTarget"], ppTarget);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["BufferCount"] = BufferCount;
        args["Width"] = Width;
        args["Height"] = Height;
        args["NewFormat"] = NewFormat;
        args["SwapChainFlags"] = SwapChainFlags;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pNewTargetParameters"], pNewTargetParameters);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["ppOutput"], ppOutput);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pStats"], pStats);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pLastPresentCount"], pLastPresentCount);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Adapter"] = Adapter;
        HandleToJson(args["ppAdapter"], ppAdapter);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WindowHandle"] = WindowHandle;
        args["Flags"] = Flags;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pWindowHandle"], pWindowHandle);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDevice"], pDevice);
        FieldToJson(args["pDesc"], pDesc);
        HandleToJson(args["ppSwapChain"], ppSwapChain);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Module"] = Module;
        HandleToJson(args["ppAdapter"], ppAdapter);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pAdapter"], pAdapter);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
        args["NumSurfaces"] = NumSurfaces;
        args["Usage"] = Usage;
        FieldToJson(args["pSharedResource"], pSharedResource);
        HandleToJson(args["ppSurface"], ppSurface);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["ppResources"], ppResources);
        FieldToJson(args["pResidencyStatus"], pResidencyStatus);
        args["NumResources"] = NumResources;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Priority"] = Priority;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pPriority"], pPriority);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Adapter"] = Adapter;
        HandleToJson(args["ppAdapter"], ppAdapter);
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
    Bool32ToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["MaxLatency"] = MaxLatency;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pMaxLatency"], pMaxLatency);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.26100.0
**
*/
void Dx12JsonConsumer::Process_IDXGIDisplayControl_IsStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDisplayControl", object_id, "IsStereoEnabled");
    Bool32ToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIDisplayControl_SetStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL enabled)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDisplayControl", object_id, "SetStereoEnabled");
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        Bool32ToJson(args["enabled"], enabled);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["TimeoutInMilliseconds"] = TimeoutInMilliseconds;
        FieldToJson(args["pFrameInfo"], pFrameInfo);
        HandleToJson(args["ppDesktopResource"], ppDesktopResource);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["DirtyRectsBufferSize"] = DirtyRectsBufferSize;
        FieldToJson(args["pDirtyRectsBuffer"], pDirtyRectsBuffer);
        FieldToJson(args["pDirtyRectsBufferSizeRequired"], pDirtyRectsBufferSizeRequired);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["MoveRectsBufferSize"] = MoveRectsBufferSize;
        FieldToJson(args["pMoveRectBuffer"], pMoveRectBuffer);
        FieldToJson(args["pMoveRectsBufferSizeRequired"], pMoveRectsBufferSizeRequired);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["PointerShapeBufferSize"] = PointerShapeBufferSize;
        FieldToJson(args["pPointerShapeBuffer"], pPointerShapeBuffer);
        FieldToJson(args["pPointerShapeBufferSizeRequired"], pPointerShapeBufferSizeRequired);
        FieldToJson(args["pPointerShapeInfo"], pPointerShapeInfo);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pLockedRect"], pLockedRect);
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
    HresultToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIOutputDuplication_ReleaseFrame(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIOutputDuplication", object_id, "ReleaseFrame");
    HresultToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppParentResource"], ppParentResource);
        FieldToJson(args["pSubresourceIndex"], pSubresourceIndex);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["index"] = index;
        HandleToJson(args["ppSurface"], ppSurface);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pAttributes"], pAttributes);
        args["dwAccess"] = dwAccess;
        FieldToJson(args["lpName"], lpName);
        FieldToJson(args["pHandle"], pHandle);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumResources"] = NumResources;
        HandleToJson(args["ppResources"], ppResources);
        args["Priority"] = Priority;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumResources"] = NumResources;
        HandleToJson(args["ppResources"], ppResources);
        Bool32ToJson(args["pDiscarded"], pDiscarded);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["hEvent"] = hEvent;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pHwnd"], pHwnd);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["refiid"], refiid);
        HandleToJson(args["ppUnk"], ppUnk);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["SyncInterval"] = SyncInterval;
        args["PresentFlags"] = PresentFlags;
        FieldToJson(args["pPresentParameters"], pPresentParameters);
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
    Bool32ToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["ppRestrictToOutput"], ppRestrictToOutput);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pColor"], pColor);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pColor"], pColor);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Rotation"] = Rotation;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRotation"], pRotation);
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
    Bool32ToJson(method[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDevice"], pDevice);
        args["hWnd"] = hWnd;
        FieldToJson(args["pDesc"], pDesc);
        FieldToJson(args["pFullscreenDesc"], pFullscreenDesc);
        HandleToJson(args["pRestrictToOutput"], pRestrictToOutput);
        HandleToJson(args["ppSwapChain"], ppSwapChain);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDevice"], pDevice);
        HandleToJson(args["pWindow"], pWindow);
        FieldToJson(args["pDesc"], pDesc);
        HandleToJson(args["pRestrictToOutput"], pRestrictToOutput);
        HandleToJson(args["ppSwapChain"], ppSwapChain);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["hResource"] = hResource;
        FieldToJson(args["pLuid"], pLuid);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WindowHandle"] = WindowHandle;
        args["wMsg"] = wMsg;
        FieldToJson(args["pdwCookie"], pdwCookie);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["hEvent"] = hEvent;
        FieldToJson(args["pdwCookie"], pdwCookie);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["dwCookie"] = dwCookie;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["WindowHandle"] = WindowHandle;
        args["wMsg"] = wMsg;
        FieldToJson(args["pdwCookie"], pdwCookie);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["hEvent"] = hEvent;
        FieldToJson(args["pdwCookie"], pdwCookie);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["dwCookie"] = dwCookie;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDevice"], pDevice);
        FieldToJson(args["pDesc"], pDesc);
        HandleToJson(args["pRestrictToOutput"], pRestrictToOutput);
        HandleToJson(args["ppSwapChain"], ppSwapChain);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["EnumFormat"] = EnumFormat;
        args["Flags"] = Flags;
        FieldToJson(args["pNumModes"], pNumModes);
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pModeToMatch"], pModeToMatch);
        FieldToJson(args["pClosestMatch"], pClosestMatch);
        HandleToJson(args["pConcernedDevice"], pConcernedDevice);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDestination"], pDestination);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDevice"], pDevice);
        HandleToJson(args["ppOutputDuplication"], ppOutputDuplication);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.26100.0
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        args["Flags"] = Flags;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppFactory"], ppFactory);
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
    HresultToJson(function[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = function[format::kNameArgs];
    {
        args["Flags"] = Flags;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["pDebug"], pDebug);
    }
    writer_->WriteBlockEnd();

}

void Dx12JsonConsumer::Process_IDXGIDevice3_Trim(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIDevice3", object_id, "Trim");
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Width"] = Width;
        args["Height"] = Height;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pWidth"], pWidth);
        FieldToJson(args["pHeight"], pHeight);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["MaxLatency"] = MaxLatency;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pMaxLatency"], pMaxLatency);
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
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pMatrix"], pMatrix);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pMatrix"], pMatrix);
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
    Bool32ToJson(method[format::kNameReturn], return_value);
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IDXGIFactory3_GetCreationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGIFactory3", object_id, "GetCreationFlags");
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["BufferToPresent"] = BufferToPresent;
        args["SyncInterval"] = SyncInterval;
        args["Flags"] = Flags;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRect"], pRect);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRect"], pRect);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Width"] = Width;
        args["Height"] = Height;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRect"], pRect);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pRect"], pRect);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pWidth"], pWidth);
        FieldToJson(args["pHeight"], pHeight);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["ColorSpace"] = DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS_t{ ColorSpace };
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
    method[format::kNameReturn] = DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS_t{ return_value };
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDevice"], pDevice);
        args["hSurface"] = hSurface;
        FieldToJson(args["pDesc"], pDesc);
        HandleToJson(args["pRestrictToOutput"], pRestrictToOutput);
        HandleToJson(args["ppSwapChain"], ppSwapChain);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDevice"], pDevice);
        args["hSurface"] = hSurface;
        FieldToJson(args["pDesc"], pDesc);
        HandleToJson(args["pYuvDecodeBuffers"], pYuvDecodeBuffers);
        HandleToJson(args["pRestrictToOutput"], pRestrictToOutput);
        HandleToJson(args["ppSwapChain"], ppSwapChain);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pStats"], pStats);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Duration"] = Duration;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["DesiredPresentDuration"] = DesiredPresentDuration;
        FieldToJson(args["pClosestSmallerPresentDuration"], pClosestSmallerPresentDuration);
        FieldToJson(args["pClosestLargerPresentDuration"], pClosestLargerPresentDuration);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["EnumFormat"] = EnumFormat;
        HandleToJson(args["pConcernedDevice"], pConcernedDevice);
        FieldToJson(args["pFlags"], pFlags);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.26100.0
**
*/
void Dx12JsonConsumer::Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IDXGISwapChain3", object_id, "GetCurrentBackBufferIndex");
    method[format::kNameReturn] = return_value;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["ColorSpace"] = ColorSpace;
        FieldToJson(args["pColorSpaceSupport"], pColorSpaceSupport);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["ColorSpace"] = ColorSpace;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["BufferCount"] = BufferCount;
        args["Width"] = Width;
        args["Height"] = Height;
        args["Format"] = Format;
        args["SwapChainFlags"] = SwapChainFlags;
        FieldToJsonAsFixedWidthBinary(args["pCreationNodeMask"], pCreationNodeMask);
        HandleToJson(args["ppPresentQueue"], ppPresentQueue);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Format"] = Format;
        args["ColorSpace"] = ColorSpace;
        HandleToJson(args["pConcernedDevice"], pConcernedDevice);
        FieldToJson(args["pFlags"], pFlags);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["AdapterLuid"], AdapterLuid);
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvAdapter"], ppvAdapter);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvAdapter"], ppvAdapter);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["hEvent"] = hEvent;
        FieldToJson(args["pdwCookie"], pdwCookie);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["dwCookie"] = dwCookie;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NodeIndex"] = NodeIndex;
        args["MemorySegmentGroup"] = MemorySegmentGroup;
        FieldToJson(args["pVideoMemoryInfo"], pVideoMemoryInfo);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NodeIndex"] = NodeIndex;
        args["MemorySegmentGroup"] = MemorySegmentGroup;
        args["Reservation"] = Reservation;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["hEvent"] = hEvent;
        FieldToJson(args["pdwCookie"], pdwCookie);
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
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["dwCookie"] = dwCookie;
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.26100.0
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        HandleToJson(args["pDevice"], pDevice);
        args["Flags"] = Flags;
        args["SupportedFormatsCount"] = SupportedFormatsCount;
        FieldToJson(args["pSupportedFormats"], pSupportedFormats);
        HandleToJson(args["ppOutputDuplication"], ppOutputDuplication);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Type"] = Type;
        args["Size"] = Size;
        FieldToJson(args["pMetaData"], pMetaData);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumResources"] = NumResources;
        HandleToJson(args["ppResources"], ppResources);
        args["Priority"] = Priority;
        args["Flags"] = Flags;
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["NumResources"] = NumResources;
        HandleToJson(args["ppResources"], ppResources);
        FieldToJson(args["pResults"], pResults);
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.26100.0
**
*/
void Dx12JsonConsumer::Process_DXGIDeclareAdapterRemovalSupport(
        const ApiCallInfo& call_info,
        HRESULT return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "DXGIDeclareAdapterRemovalSupport");
    HresultToJson(function[format::kNameReturn], return_value);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pDesc"], pDesc);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["pFlags"], pFlags);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["Adapter"] = Adapter;
        args["GpuPreference"] = GpuPreference;
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvAdapter"], ppvAdapter);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["hEvent"] = hEvent;
        FieldToJson(args["pdwCookie"], pdwCookie);
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        args["dwCookie"] = dwCookie;
    }
    writer_->WriteBlockEnd();
}

/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.26100.0
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
    HresultToJson(method[format::kNameReturn], return_value);
    nlohmann::ordered_json& args = method[format::kNameArgs];
    {
        FieldToJson(args["riid"], riid);
        HandleToJson(args["ppvObject"], ppvObject);
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
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}

void Dx12JsonConsumer::Process_IUnknown_Release(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        ULONG return_value)
{
    using namespace gfxrecon::util;

    nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "IUnknown", object_id, "Release");
    method[format::kNameReturn] = return_value;
    writer_->WriteBlockEnd();
}



GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
