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
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("GetRootSignatureDesc", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(str_strm,
    //                   true,
    //                   "return",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //     FieldToString(
    //         str_strm, false, "ID3D12RootSignatureDeserializer", to_string_flags, tab_count, tab_size, "nullptr");
    // });
}

void Dx12AsciiConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
    format::HandleId object_id, StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* return_value)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile(
    //     "GetUnconvertedRootSignatureDesc", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //         FieldToString(str_strm,
    //                       true,
    //                       "return",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //         FieldToString(str_strm,
    //                       false,
    //                       "ID3D12VersionedRootSignatureDeserializer",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       "nullptr");
    //     });
}

void Dx12AsciiConsumer::Process_ID3D12Heap_GetDesc(format::HandleId object_id, Decoded_D3D12_HEAP_DESC return_value)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(str_strm,
    //                   true,
    //                   "return",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //     FieldToString(str_strm, false, "ID3D12Heap", to_string_flags, tab_count, tab_size, "nullptr");
    // });
}

void Dx12AsciiConsumer::Process_ID3D12Resource_GetDesc(format::HandleId            object_id,
                                                       Decoded_D3D12_RESOURCE_DESC return_value)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(str_strm,
    //                   true,
    //                   "return",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //     FieldToString(str_strm, false, "ID3D12Resource", to_string_flags, tab_count, tab_size, "nullptr");
    // });
}

void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetDesc(format::HandleId                   object_id,
                                                             Decoded_D3D12_DESCRIPTOR_HEAP_DESC return_value)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(str_strm,
    //                   true,
    //                   "return",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //     FieldToString(str_strm, false, "ID3D12DescriptorHeap", to_string_flags, tab_count, tab_size, "nullptr");
    // });
}

void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    format::HandleId object_id, Decoded_D3D12_CPU_DESCRIPTOR_HANDLE return_value)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile(
    //     "GetCPUDescriptorHandleForHeapStart", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //         FieldToString(str_strm,
    //                       true,
    //                       "return",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //         FieldToString(str_strm, false, "ID3D12DescriptorHeap", to_string_flags, tab_count, tab_size, "nullptr");
    //     });
}

void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    format::HandleId object_id, Decoded_D3D12_GPU_DESCRIPTOR_HANDLE return_value)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile(
    //     "GetGPUDescriptorHandleForHeapStart", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //         FieldToString(str_strm,
    //                       true,
    //                       "return",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //         FieldToString(str_strm, false, "ID3D12DescriptorHeap", to_string_flags, tab_count, tab_size, "nullptr");
    //     });
}

void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetDesc(format::HandleId                 object_id,
                                                           Decoded_D3D12_COMMAND_QUEUE_DESC return_value)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(str_strm,
    //                   true,
    //                   "return",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //     FieldToString(str_strm, false, "ID3D12CommandQueue", to_string_flags, tab_count, tab_size, "nullptr");
    // });
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetResourceAllocationInfo(
    format::HandleId                                   object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO             return_value,
    UINT                                               visibleMask,
    UINT                                               numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile(
    //     "GetResourceAllocationInfo", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //         FieldToString(str_strm,
    //                       true,
    //                       "return",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //         FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
    //         FieldToString(str_strm,
    //                       false,
    //                       "visibleMask",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       "TODO 15 : ToString(visibleMask, to_string_flags, tab_count, tab_size)");
    //         FieldToString(str_strm,
    //                       false,
    //                       "numResourceDescs",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       "TODO 15 : ToString(numResourceDescs, to_string_flags, tab_count, tab_size)");
    //         FieldToString(str_strm,
    //                       false,
    //                       "pResourceDescs",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       "TODO 1 : PointerDecoderArrayToString(numResourceDescs, pResourceDescs, to_string_flags, "
    //                       "tab_count, tab_size)");
    //     });
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetCustomHeapProperties(format::HandleId              object_id,
                                                                     Decoded_D3D12_HEAP_PROPERTIES return_value,
                                                                     UINT                          nodeMask,
                                                                     D3D12_HEAP_TYPE               heapType)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile(
    //     "GetCustomHeapProperties", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //         FieldToString(str_strm,
    //                       true,
    //                       "return",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //         FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
    //         FieldToString(str_strm,
    //                       false,
    //                       "nodeMask",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       "TODO 15 : ToString(nodeMask, to_string_flags, tab_count, tab_size)");
    //         FieldToString(str_strm,
    //                       false,
    //                       "heapType",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       '"' + ToString(heapType, to_string_flags, tab_count, tab_size) + '"');
    //     });
}

void Dx12AsciiConsumer::Process_ID3D12Device_GetAdapterLuid(format::HandleId object_id, Decoded_LUID return_value)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("GetAdapterLuid", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(str_strm,
    //                   true,
    //                   "return",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //     FieldToString(str_strm, false, "ID3D12Device", to_string_flags, tab_count, tab_size, "nullptr");
    // });
}

void Dx12AsciiConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
    format::HandleId object_id, Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("GetDesc", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(str_strm,
    //                   true,
    //                   "return",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //     FieldToString(
    //         str_strm, false, "ID3D12ProtectedResourceSession", to_string_flags, tab_count, tab_size, "nullptr");
    // });
}

void Dx12AsciiConsumer::Process_ID3D12Device4_GetResourceAllocationInfo1(
    format::HandleId                                               object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO                         return_value,
    UINT                                                           visibleMask,
    UINT                                                           numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>*             pResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile(
    //     "GetResourceAllocationInfo1", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //         FieldToString(str_strm,
    //                       true,
    //                       "return",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       '"' + ToString(return_value, to_string_flags, tab_count, tab_size) + '"');
    //         FieldToString(str_strm, false, "ID3D12Device4", to_string_flags, tab_count, tab_size, "nullptr");
    //         FieldToString(str_strm,
    //                       false,
    //                       "visibleMask",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       "TODO 15 : ToString(visibleMask, to_string_flags, tab_count, tab_size)");
    //         FieldToString(str_strm,
    //                       false,
    //                       "numResourceDescs",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       "TODO 15 : ToString(numResourceDescs, to_string_flags, tab_count, tab_size)");
    //         FieldToString(str_strm,
    //                       false,
    //                       "pResourceDescs",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       "TODO 1 : PointerDecoderArrayToString(numResourceDescs, pResourceDescs, to_string_flags, "
    //                       "tab_count, tab_size)");
    //         FieldToString(str_strm,
    //                       false,
    //                       "[out]pResourceAllocationInfo1",
    //                       to_string_flags,
    //                       tab_count,
    //                       tab_size,
    //                       "TODO 1 : PointerDecoderArrayToString(numResourceDescs, pResourceAllocationInfo1, "
    //                       "to_string_flags, tab_count, tab_size)");
    //     });
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResourceBarrier(
    format::HandleId object_id, UINT NumBarriers, StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("ResourceBarrier", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(str_strm,
    //                   true,
    //                   "ID3D12GraphicsCommandList",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   HandleIdToString(object_id));
    //     FieldToString(str_strm,
    //                   false,
    //                   "NumBarriers",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   ToString(NumBarriers, to_string_flags, tab_count, tab_size));
    //     FieldToString(str_strm,
    //                   false,
    //                   "pBarriers",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   PointerDecoderArrayToString(NumBarriers, pBarriers, to_string_flags, tab_count, tab_size));
    // });
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMessage(format::HandleId                             object_id,
                                                           HRESULT                                      return_value,
                                                           UINT64                                       MessageIndex,
                                                           StructPointerDecoder<Decoded_D3D12_MESSAGE>* pMessage,
                                                           PointerDecoder<SIZE_T>* pMessageByteLength)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("GetMessage", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(
    //         str_strm, true, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, HandleIdToString(object_id));
    //     FieldToString(str_strm,
    //                   false,
    //                   "return",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size));
    //     FieldToString(str_strm,
    //                   false,
    //                   "MessageIndex",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   ToString(MessageIndex, to_string_flags, tab_count, tab_size));
    //     FieldToString(str_strm,
    //                   false,
    //                   "[out]pMessage",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   PointerDecoderArrayToString(pMessageByteLength, pMessage, to_string_flags, tab_count, tab_size));
    //     FieldToString(str_strm,
    //                   false,
    //                   "pMessageByteLength",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   "TODO 7 : PointerDecoderToString(pMessageByteLength, to_string_flags, tab_count, tab_size)");
    // });
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetStorageFilter(
    format::HandleId                                       object_id,
    HRESULT                                                return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
    PointerDecoder<SIZE_T>*                                pFilterByteLength)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("GetStorageFilter", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(
    //         str_strm, true, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, HandleIdToString(object_id));
    //     FieldToString(str_strm,
    //                   false,
    //                   "return",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size));
    //     FieldToString(str_strm,
    //                   false,
    //                   "[out]pFilter",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   PointerDecoderArrayToString(pFilterByteLength, pFilter, to_string_flags, tab_count, tab_size));
    //     FieldToString(str_strm,
    //                   false,
    //                   "pFilterByteLength",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   "TODO 7 : PointerDecoderToString(pFilterByteLength, to_string_flags, tab_count, tab_size)");
    // });
}

void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetRetrievalFilter(
    format::HandleId                                       object_id,
    HRESULT                                                return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
    PointerDecoder<SIZE_T>*                                pFilterByteLength)
{
    // using namespace gfxrecon::util;
    // ToStringFlags to_string_flags = kToString_Default;
    // uint32_t      tab_count       = 0;
    // uint32_t      tab_size        = 4;
    // WriteApiCallToFile("GetRetrievalFilter", to_string_flags, tab_count, tab_size, [&](std::stringstream& str_strm) {
    //     FieldToString(
    //         str_strm, true, "ID3D12InfoQueue", to_string_flags, tab_count, tab_size, HandleIdToString(object_id));
    //     FieldToString(str_strm,
    //                   false,
    //                   "return",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size));
    //     FieldToString(str_strm,
    //                   false,
    //                   "[out]pFilter",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   PointerDecoderArrayToString(pFilterByteLength, pFilter, to_string_flags, tab_count, tab_size));
    //     FieldToString(str_strm,
    //                   false,
    //                   "pFilterByteLength",
    //                   to_string_flags,
    //                   tab_count,
    //                   tab_size,
    //                   "TODO 7 : PointerDecoderToString(pFilterByteLength, to_string_flags, tab_count, tab_size)");
    // });
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
