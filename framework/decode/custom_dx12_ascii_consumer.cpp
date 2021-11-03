/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "decode/custom_dx12_ascii_consumer.h"
#include "generated/generated_dx12_ascii_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void Dx12AsciiConsumer::Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
    format::HandleId object_id, StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12RootSignatureDeserializer";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRootSignatureDesc";
    auto returnValue = ToString(*return_value->GetPointer(), to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) { });
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
    format::HandleId object_id, StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12VersionedRootSignatureDeserializer";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetUnconvertedRootSignatureDesc";
    auto returnValue = ToString(*return_value->GetPointer(), to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) { });
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12Heap_GetDesc(format::HandleId object_id, Decoded_D3D12_HEAP_DESC return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Heap";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) { });
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12Resource_GetDesc(format::HandleId            object_id,
                                                       Decoded_D3D12_RESOURCE_DESC return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) { });
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetDesc(format::HandleId                   object_id,
                                                             Decoded_D3D12_DESCRIPTOR_HEAP_DESC return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DescriptorHeap";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) { });
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    format::HandleId object_id, Decoded_D3D12_CPU_DESCRIPTOR_HANDLE return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DescriptorHeap";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCPUDescriptorHandleForHeapStart";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) { });
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    format::HandleId object_id, Decoded_D3D12_GPU_DESCRIPTOR_HANDLE return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12DescriptorHeap";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCPUDescriptorHandleForHeapStart";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) { });
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetDesc(format::HandleId                 object_id,
                                                           Decoded_D3D12_COMMAND_QUEUE_DESC return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) { });
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetResourceAllocationInfo(
    format::HandleId                                   object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO             return_value,
    UINT                                               visibleMask,
    UINT                                               numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetResourceAllocationInfo";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
                FieldToString(str_strm, true, "visibleMask", to_string_flags, tab_count, tab_size, ToString(visibleMask, to_string_flags, tab_count, tab_size));
                FieldToString(str_strm, false, "numResourceDescs", to_string_flags, tab_count, tab_size, ToString(numResourceDescs, to_string_flags, tab_count, tab_size));
                FieldToString(str_strm, false, "pResourceDescs", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(numResourceDescs, pResourceDescs, to_string_flags, tab_count, tab_size));
        }
    );
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetCustomHeapProperties(format::HandleId              object_id,
                                                                     Decoded_D3D12_HEAP_PROPERTIES return_value,
                                                                     UINT                          nodeMask,
                                                                     D3D12_HEAP_TYPE               heapType)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetCustomHeapProperties";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "nodeMask", to_string_flags, tab_count, tab_size, ToString(nodeMask, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "heapType", to_string_flags, tab_count, tab_size, '"' + ToString(heapType, to_string_flags, tab_count, tab_size) + '"');
        }
    );
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetAdapterLuid(format::HandleId object_id, Decoded_LUID return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetAdapterLuid";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) { });
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
    format::HandleId object_id, Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12ProtectedResourceSession";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetDesc";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) { });
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12Device4_GetResourceAllocationInfo1(
    format::HandleId                                               object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO                         return_value,
    UINT                                                           visibleMask,
    UINT                                                           numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>*             pResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device4";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetResourceAllocationInfo1";
    auto returnValue = ToString(*return_value.decoded_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "visibleMask", to_string_flags, tab_count, tab_size, ToString(visibleMask, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "numResourceDescs", to_string_flags, tab_count, tab_size, ToString(numResourceDescs, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pResourceDescs", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(numResourceDescs, pResourceDescs, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pResourceAllocationInfo1", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(numResourceDescs, pResourceAllocationInfo1, to_string_flags, tab_count, tab_size));
        }
    );
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResourceBarrier(
    format::HandleId object_id, UINT NumBarriers, StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12GraphicsCommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "ResourceBarrier";
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "NumBarriers", to_string_flags, tab_count, tab_size, ToString(NumBarriers, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pBarriers", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(NumBarriers, pBarriers, to_string_flags, tab_count, tab_size));
        }
    );
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMessage(format::HandleId                             object_id,
                                                           HRESULT                                      return_value,
                                                           UINT64                                       MessageIndex,
                                                           StructPointerDecoder<Decoded_D3D12_MESSAGE>* pMessage,
                                                           PointerDecoder<SIZE_T>* pMessageByteLength)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetMessage";
    auto returnValue = ToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "MessageIndex", to_string_flags, tab_count, tab_size, ToString(MessageIndex, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]pMessage", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(pMessageByteLength, pMessage, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pMessageByteLength", to_string_flags, tab_count, tab_size, PointerDecoderToString(pMessageByteLength, to_string_flags, tab_count, tab_size));
        }
    );
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetStorageFilter(
    format::HandleId                                       object_id,
    HRESULT                                                return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
    PointerDecoder<SIZE_T>*                                pFilterByteLength)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetStorageFilter";
    auto returnValue = ToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pFilter", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(pFilterByteLength, pFilter, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pFilterByteLength", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFilterByteLength, to_string_flags, tab_count, tab_size));
        }
    );
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetRetrievalFilter(
    format::HandleId                                       object_id,
    HRESULT                                                return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
    PointerDecoder<SIZE_T>*                                pFilterByteLength)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12InfoQueue";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetRetrievalFilter";
    auto returnValue = ToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "[out]pFilter", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(pFilterByteLength, pFilter, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pFilterByteLength", to_string_flags, tab_count, tab_size, PointerDecoderToString(pFilterByteLength, to_string_flags, tab_count, tab_size));
        }
    );
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12Device_CreateRootSignature(format::HandleId             object_id,
                                                                 HRESULT                      return_value,
                                                                 UINT                         nodeMask,
                                                                 PointerDecoder<uint8_t>*     pBlobWithRootSignature,
                                                                 SIZE_T                       blobLengthInBytes,
                                                                 Decoded_GUID                 riid,
                                                                 HandlePointerDecoder<void*>* ppvRootSignature)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CreateRootSignature";
    auto returnValue = ToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "nodeMask", to_string_flags, tab_count, tab_size, ToString(nodeMask, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pBlobWithRootSignature", to_string_flags, tab_count, tab_size, HandleIdToString(pBlobWithRootSignature));
            FieldToString(str_strm, false, "blobLengthInBytes", to_string_flags, tab_count, tab_size, ToString(blobLengthInBytes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppvRootSignature", to_string_flags, tab_count, tab_size, HandleIdToString(ppvRootSignature));
        }
    );
    // clang-format on
}

void Dx12AsciiConsumer::Process_D3D12CreateRootSignatureDeserializer(
    HRESULT                      return_value,
    PointerDecoder<uint8_t>*     pSrcData,
    SIZE_T                       SrcDataSizeInBytes,
    Decoded_GUID                 pRootSignatureDeserializerInterface,
    HandlePointerDecoder<void*>* ppRootSignatureDeserializer)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pFunctionName = "D3D12CreateRootSignatureDeserializer";
    auto returnValue = ToString(return_value, to_string_flags, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "pSrcData", to_string_flags, tab_count, tab_size, PointerDecoderArrayToString(SrcDataSizeInBytes, pSrcData, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "SrcDataSizeInBytes", to_string_flags, tab_count, tab_size, ToString(SrcDataSizeInBytes, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "pRootSignatureDeserializerInterface", to_string_flags, tab_count, tab_size, ToString(*pRootSignatureDeserializerInterface.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppRootSignatureDeserializer", to_string_flags, tab_count, tab_size, HandleIdToString(ppRootSignatureDeserializer));
        }
    );
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12CommandList_GetType(format::HandleId        object_id,
                                                          D3D12_COMMAND_LIST_TYPE return_value)
{
    // clang-format off
    using namespace gfxrecon::util;
    ToStringFlags to_string_flags = kToString_Default;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12CommandList";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "GetType";
    std::string returnValue = '"' + DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size) + '"';
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
        }
    );
    // clang-format on
}

void Dx12AsciiConsumer::Process_ID3D12Device1_CreatePipelineLibrary(format::HandleId             object_id,
                                                                    HRESULT                      return_value,
                                                                    PointerDecoder<uint8_t>*     pLibraryBlob,
                                                                    SIZE_T                       BlobLength,
                                                                    Decoded_GUID                 riid,
                                                                    HandlePointerDecoder<void*>* ppPipelineLibrary)
{
    // clang-format off
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
            FieldToString(str_strm, true, "pLibraryBlob", to_string_flags, tab_count, tab_size, "\"" + PtrToString(pLibraryBlob->GetPointer()) + "\"");
            FieldToString(str_strm, false, "BlobLength", to_string_flags, tab_count, tab_size, ToString(BlobLength, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "riid", to_string_flags, tab_count, tab_size, ToString(*riid.decoded_value, to_string_flags, tab_count, tab_size));
            FieldToString(str_strm, false, "[out]ppPipelineLibrary", to_string_flags, tab_count, tab_size, HandleIdToString(ppPipelineLibrary));
        }
    );
    // clang-format on
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
