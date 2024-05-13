/*
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "custom_ags_decoder.h"
#include "custom_ags_struct_decoders.h"
#include "string_decoder.h"
#include "value_decoder.h"

#include <amd_ags.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

bool AgsDecoder::IsComplete(uint64_t block_index)
{
    return false;
}

bool AgsDecoder::SupportsApiCall(format::ApiCallId call_id)
{
    auto family_id = format::GetApiCallFamily(call_id);
    return (family_id == format::ApiFamilyId::ApiFamily_AGS);
}

void AgsDecoder::DecodeFunctionCall(format::ApiCallId  call_id,
                                    const ApiCallInfo& call_info,
                                    const uint8_t*     parameter_buffer,
                                    size_t             buffer_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    switch (call_id)
    {
        case format::ApiCallId::ApiCall_Ags_agsInitialize_6_0_1:
            Decode_agsInitialize(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_Ags_agsDeInitialize_6_0_1:
            Decode_agsDeInitialize(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_0_1:
            Decode_agsDriverExtensionsDX12_CreateDevice_601(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_2_0:
            Decode_agsDriverExtensionsDX12_CreateDevice_620(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_DestroyDevice_6_0_1:
            Decode_agsDriverExtensionsDX12_DestroyDevice(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_Ags_agsCheckDriverVersion_6_0_1:
            Decode_agsCheckDriverVersion(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_Ags_agsGetVersionNumber_6_0_1:
            Decode_agsGetVersionNumber(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_Ags_agsSetDisplayMode_6_0_1:
            Decode_agsSetDisplayMode(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_PushMarker_6_0_1:
            Decode_agsDriverExtensionsDX12_PushMarker(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_PopMarker_6_0_1:
            Decode_agsDriverExtensionsDX12_PopMarker(call_info, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_SetMarker_6_0_1:
            Decode_agsDriverExtensionsDX12_SetMarker(call_info, parameter_buffer, buffer_size);
            break;
        default:
            break;
    }
}

size_t
AgsDecoder::Decode_agsInitialize(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    int           agsVersion = 0;
    AGSContext*   context    = nullptr;
    AGSReturnCode result     = AGSReturnCode::AGS_SUCCESS;

    bytes_read +=
        ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &agsVersion);

    StructPointerDecoder<Decoded_AGS_CONFIGURATION> pConfiguration;

    bytes_read += pConfiguration.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVoidPtr(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<uint64_t*>(&context));

    StructPointerDecoder<Decoded_AGS_GPU_INFO> pGPUInfo;
    bytes_read += pGPUInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&result));

    AGSConfiguration* ags_config = nullptr;
    if (!pConfiguration.IsNull())
    {
        ags_config = pConfiguration.GetMetaStructPointer()->decoded_value;
    }
    for (auto consumer : GetConsumers())
    {
        consumer->Process_agsInitialize(
            call_info, result, agsVersion, ags_config, context, *(pGPUInfo.GetMetaStructPointer()->decoded_value));
    }

    return bytes_read;
}

size_t
AgsDecoder::Decode_agsDeInitialize(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    AGSContext*   context = nullptr;
    AGSReturnCode result  = AGS_SUCCESS;
    bytes_read += ValueDecoder::DecodeVoidPtr(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<uint64_t*>(&context));
    bytes_read += ValueDecoder::DecodeInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&result));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_agsDeInitialize(call_info, result, context);
    }

    return bytes_read;
}

size_t AgsDecoder::Decode_agsDriverExtensionsDX12_CreateDevice_620(const ApiCallInfo& call_info,
                                                                   const uint8_t*     parameter_buffer,
                                                                   size_t             buffer_size)
{
    size_t bytes_read = 0;

    AGSContext*   context = nullptr;
    AGSReturnCode result  = AGS_SUCCESS;

    bytes_read += ValueDecoder::DecodeVoidPtr(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<uint64_t*>(&context));

    StructPointerDecoder<Decoded_AGS_DX12_DEVICE_CREATION_PARAMS> pCreationParams;
    bytes_read += pCreationParams.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    StructPointerDecoder<Decoded_AGS_DX12_EXTENSION_PARAMS> pExtensionParams;
    bytes_read += pExtensionParams.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    StructPointerDecoder<Decoded_AGS_DX12_RETURN_PARAMS> pReturnParams;
    bytes_read += pReturnParams.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    bytes_read += ValueDecoder::DecodeInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&result));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_agsDriverExtensionsDX12_CreateDevice(
            call_info, result, context, pCreationParams.GetPointer(), pExtensionParams.GetPointer(), &pReturnParams);
    }

    return bytes_read;
}

size_t AgsDecoder::Decode_agsDriverExtensionsDX12_CreateDevice_601(const ApiCallInfo& call_info,
                                                                   const uint8_t*     parameter_buffer,
                                                                   size_t             buffer_size)
{
    GFXRECON_LOG_WARNING("The current capture was made with AGS 6.0.1 but will be replayed with AGS 6.2.0. If replay "
                         "encounters error, a new capture may be needed.");
    return Decode_agsDriverExtensionsDX12_CreateDevice_620(call_info, parameter_buffer, buffer_size);
}

size_t AgsDecoder::Decode_agsDriverExtensionsDX12_DestroyDevice(const ApiCallInfo& call_info,
                                                                const uint8_t*     parameter_buffer,
                                                                size_t             buffer_size)
{
    size_t bytes_read = 0;

    AGSContext*          context          = nullptr;
    format::HandleId     pDevice          = 0;
    unsigned int         deviceReferences = 0;
    PointerDecoder<UINT> pDeviceReferences;
    AGSReturnCode        result = AGS_SUCCESS;

    bytes_read += ValueDecoder::DecodeVoidPtr(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<uint64_t*>(&context));
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDevice);
    bytes_read += pDeviceReferences.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&result));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_agsDriverExtensionsDX12_DestroyDevice(
            call_info, result, context, reinterpret_cast<ID3D12Device*>(pDevice), pDeviceReferences.GetPointer());
    }

    return bytes_read;
}

size_t AgsDecoder::Decode_agsCheckDriverVersion(const ApiCallInfo& call_info,
                                                const uint8_t*     parameter_buffer,
                                                size_t             buffer_size)
{
    size_t bytes_read = 0;

    AGSDriverVersionResult result = AGSDriverVersionResult::AGS_SOFTWAREVERSIONCHECK_UNDEFINED;
    StringDecoder          radeonSoftwareVersionReported;
    char*        pRadeonSoftwareVersionReported = DecodeAllocator::Allocate<char>(kDriverSoftwareStringSize, true);
    unsigned int radeonSoftwareVersionRequired  = 0;
    radeonSoftwareVersionReported.SetExternalMemory(pRadeonSoftwareVersionReported, kDriverSoftwareStringSize);
    bytes_read += radeonSoftwareVersionReported.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read),
                                                  (buffer_size - bytes_read),
                                                  reinterpret_cast<uint32_t*>(&radeonSoftwareVersionRequired));
    bytes_read += ValueDecoder::DecodeInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&result));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_agsCheckDriverVersion(
            call_info, result, pRadeonSoftwareVersionReported, radeonSoftwareVersionRequired);
    }

    return bytes_read;
}

size_t AgsDecoder::Decode_agsGetVersionNumber(const ApiCallInfo& call_info,
                                              const uint8_t*     parameter_buffer,
                                              size_t             buffer_size)
{
    size_t bytes_read = 0;

    int result = 0;
    bytes_read += ValueDecoder::DecodeInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&result));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_agsGetVersionNumber(call_info, result);
    }

    return bytes_read;
}

size_t
AgsDecoder::Decode_agsSetDisplayMode(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    AGSContext*   context      = nullptr;
    int           deviceIndex  = 0;
    int           displayIndex = 0;
    AGSReturnCode result       = AGS_SUCCESS;

    bytes_read += ValueDecoder::DecodeVoidPtr(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<uint64_t*>(&context));
    bytes_read +=
        ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceIndex);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &displayIndex);

    Decoded_AGS_DISPLAY_SETTINGS settings;
    settings.decoded_value = DecodeAllocator::Allocate<AGSDisplaySettings>();
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &settings);

    bytes_read += ValueDecoder::DecodeInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&result));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_agsSetDisplayMode(
            call_info, result, context, deviceIndex, displayIndex, settings.decoded_value);
    }

    return bytes_read;
}

size_t AgsDecoder::Decode_agsDriverExtensionsDX12_PushMarker(const ApiCallInfo& call_info,
                                                             const uint8_t*     parameter_buffer,
                                                             size_t             buffer_size)
{
    size_t bytes_read = 0;

    AGSContext*      context      = nullptr;
    format::HandleId pCommandList = 0;
    StringDecoder    markerDataDecoder;
    char*            pMarkerData = DecodeAllocator::Allocate<char>(kDriverSoftwareStringSize, true);
    markerDataDecoder.SetExternalMemory(pMarkerData, kDriverSoftwareStringSize);
    AGSReturnCode result = AGS_SUCCESS;

    bytes_read += ValueDecoder::DecodeVoidPtr(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<uint64_t*>(&context));
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCommandList);
    bytes_read += markerDataDecoder.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    bytes_read += ValueDecoder::DecodeInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&result));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_agsDriverExtensionsDX12_PushMarker(call_info, result, context, pCommandList, pMarkerData);
    }

    return bytes_read;
}

size_t AgsDecoder::Decode_agsDriverExtensionsDX12_PopMarker(const ApiCallInfo& call_info,
                                                            const uint8_t*     parameter_buffer,
                                                            size_t             buffer_size)
{
    size_t bytes_read = 0;

    AGSContext*      context      = nullptr;
    format::HandleId pCommandList = 0;
    AGSReturnCode    result       = AGS_SUCCESS;

    bytes_read += ValueDecoder::DecodeVoidPtr(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<uint64_t*>(&context));
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCommandList);

    bytes_read += ValueDecoder::DecodeInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&result));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_agsDriverExtensionsDX12_PopMarker(call_info, result, context, pCommandList);
    }

    return bytes_read;
}

size_t AgsDecoder::Decode_agsDriverExtensionsDX12_SetMarker(const ApiCallInfo& call_info,
                                                            const uint8_t*     parameter_buffer,
                                                            size_t             buffer_size)
{
    size_t bytes_read = 0;

    AGSContext*      context      = nullptr;
    format::HandleId pCommandList = 0;
    StringDecoder    markerDataDecoder;
    char*            pMarkerData = DecodeAllocator::Allocate<char>(kDriverSoftwareStringSize, true);
    markerDataDecoder.SetExternalMemory(pMarkerData, kDriverSoftwareStringSize);
    AGSReturnCode result = AGS_SUCCESS;

    bytes_read += ValueDecoder::DecodeVoidPtr(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<uint64_t*>(&context));
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCommandList);
    bytes_read += markerDataDecoder.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    bytes_read += ValueDecoder::DecodeInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&result));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_agsDriverExtensionsDX12_SetMarker(call_info, result, context, pCommandList, pMarkerData);
    }

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
