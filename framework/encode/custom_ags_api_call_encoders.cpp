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

#include "custom_ags_api_call_encoders.h"
#include "d3d12_capture_manager.h"
#include "struct_pointer_encoder.h"
#include "format/api_call_id.h"
#include "generated/generated_dx12_api_call_encoders.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodeStruct(ParameterEncoder* encoder, const AGSRect& value)
{
    encoder->EncodeInt32Value(value.offsetX);
    encoder->EncodeInt32Value(value.offsetY);
    encoder->EncodeInt32Value(value.width);
    encoder->EncodeInt32Value(value.height);
}

void EncodeStruct(ParameterEncoder* encoder, const AGSDisplayInfo& value)
{
    encoder->EncodeString(value.name);
    encoder->EncodeString(value.displayDeviceName);

    encoder->EncodeUInt32Value(value.isPrimaryDisplay);
    encoder->EncodeUInt32Value(value.HDR10);
    encoder->EncodeUInt32Value(value.dolbyVision);
    encoder->EncodeUInt32Value(value.freesync);
    encoder->EncodeUInt32Value(value.freesyncHDR);
    encoder->EncodeUInt32Value(value.eyefinityInGroup);
    encoder->EncodeUInt32Value(value.eyefinityPreferredDisplay);
    encoder->EncodeUInt32Value(value.eyefinityInPortraitMode);
    encoder->EncodeUInt32Value(value.reservedPadding);
    encoder->EncodeInt32Value(value.maxResolutionX);
    encoder->EncodeInt32Value(value.maxResolutionY);
    encoder->EncodeFloatValue(value.maxRefreshRate);
    EncodeStruct(encoder, value.currentResolution);
    EncodeStruct(encoder, value.visibleResolution);
    encoder->EncodeFloatValue(value.currentRefreshRate);
    encoder->EncodeInt32Value(value.eyefinityGridCoordX);
    encoder->EncodeInt32Value(value.eyefinityGridCoordY);
    encoder->EncodeDoubleValue(value.chromaticityRedX);
    encoder->EncodeDoubleValue(value.chromaticityRedY);
    encoder->EncodeDoubleValue(value.chromaticityGreenX);
    encoder->EncodeDoubleValue(value.chromaticityGreenY);
    encoder->EncodeDoubleValue(value.chromaticityBlueX);
    encoder->EncodeDoubleValue(value.chromaticityBlueY);
    encoder->EncodeDoubleValue(value.chromaticityWhitePointX);
    encoder->EncodeDoubleValue(value.chromaticityWhitePointY);
    encoder->EncodeDoubleValue(value.screenDiffuseReflectance);
    encoder->EncodeDoubleValue(value.screenSpecularReflectance);
    encoder->EncodeDoubleValue(value.minLuminance);
    encoder->EncodeDoubleValue(value.maxLuminance);
    encoder->EncodeDoubleValue(value.avgLuminance);
    encoder->EncodeInt32Value(value.logicalDisplayIndex);
    encoder->EncodeInt32Value(value.adlAdapterIndex);
    encoder->EncodeInt32Value(value.reserved);
}

void EncodeStruct(ParameterEncoder* encoder, const AGSDeviceInfo& value)
{
    encoder->EncodeString(value.adapterString);
    encoder->EncodeInt32Value(value.asicFamily);
    encoder->EncodeUInt32Value(value.isAPU);
    encoder->EncodeUInt32Value(value.isPrimaryDevice);
    encoder->EncodeUInt32Value(value.isExternal);
    encoder->EncodeUInt32Value(value.reservedPadding);
    encoder->EncodeInt32Value(value.vendorId);
    encoder->EncodeInt32Value(value.deviceId);
    encoder->EncodeInt32Value(value.revisionId);
    encoder->EncodeInt32Value(value.numCUs);
    encoder->EncodeInt32Value(value.numWGPs);
    encoder->EncodeInt32Value(value.numROPs);
    encoder->EncodeInt32Value(value.coreClock);
    encoder->EncodeInt32Value(value.memoryClock);
    encoder->EncodeInt32Value(value.memoryBandwidth);
    encoder->EncodeFloatValue(value.teraFlops);
    encoder->EncodeUInt64Value(value.localMemoryInBytes);
    encoder->EncodeUInt64Value(value.sharedMemoryInBytes);
    encoder->EncodeInt32Value(value.numDisplays);
    EncodeStructArray(encoder, value.displays, value.numDisplays);
    encoder->EncodeInt32Value(value.eyefinityEnabled);
    encoder->EncodeInt32Value(value.eyefinityGridWidth);
    encoder->EncodeInt32Value(value.eyefinityGridHeight);
    encoder->EncodeInt32Value(value.eyefinityResolutionX);
    encoder->EncodeInt32Value(value.eyefinityResolutionY);
    encoder->EncodeInt32Value(value.eyefinityBezelCompensated);
    encoder->EncodeInt32Value(value.adlAdapterIndex);
    encoder->EncodeInt32Value(value.reserved);
}

void EncodeStruct(ParameterEncoder* encoder, const AGSConfiguration& value)
{
    encoder->EncodeFunctionPtr(value.allocCallback);
    encoder->EncodeFunctionPtr(value.freeCallback);
}

void EncodeStruct(ParameterEncoder* encoder, const AGSGPUInfo& value)
{
    encoder->EncodeString(value.driverVersion);
    encoder->EncodeString(value.radeonSoftwareVersion);
    encoder->EncodeInt32Value(value.numDevices);
    EncodeStructArray(encoder, value.devices, value.numDevices);
}

void EncodeStruct(ParameterEncoder* encoder, const AGSDX12DeviceCreationParams& value)
{
    encoder->EncodeObjectValue(value.pAdapter);
    EncodeStruct(encoder, static_cast<GUID>(value.iid));
    encoder->EncodeEnumValue(value.FeatureLevel);
}

void EncodeStruct(ParameterEncoder* encoder, const AGSDX12ExtensionParams& value)
{
    encoder->EncodeWString(value.pAppName);
    encoder->EncodeWString(value.pEngineName);
    encoder->EncodeUInt32Value(value.appVersion);
    encoder->EncodeUInt32Value(value.engineVersion);
    encoder->EncodeUInt32Value(value.uavSlot);
}

void EncodeStruct(ParameterEncoder* encoder, const AGSDX12ReturnedParams& value)
{
    encoder->EncodeObjectValue(value.pDevice);
    EncodeStruct(encoder, value.extensionsSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const AGSDX12ReturnedParams::ExtensionsSupported& value)
{
    encoder->EncodeUInt32Value(value.intrinsics16);
    encoder->EncodeUInt32Value(value.intrinsics17);
    encoder->EncodeUInt32Value(value.userMarkers);
    encoder->EncodeUInt32Value(value.appRegistration);
    encoder->EncodeUInt32Value(value.UAVBindSlot);
    encoder->EncodeUInt32Value(value.intrinsics19);
    encoder->EncodeUInt32Value(value.baseVertex);
    encoder->EncodeUInt32Value(value.baseInstance);
    encoder->EncodeUInt32Value(value.getWaveSize);
    encoder->EncodeUInt32Value(value.floatConversion);
    encoder->EncodeUInt32Value(value.readLaneAt);
    encoder->EncodeUInt32Value(value.rayHitToken);
    encoder->EncodeUInt32Value(value.padding);
}

void EncodeStruct(ParameterEncoder* encoder, const AGSDisplaySettings& value)
{
    encoder->EncodeInt32Value(value.mode);
    encoder->EncodeDoubleValue(value.chromaticityRedX);
    encoder->EncodeDoubleValue(value.chromaticityRedY);
    encoder->EncodeDoubleValue(value.chromaticityGreenX);
    encoder->EncodeDoubleValue(value.chromaticityGreenY);
    encoder->EncodeDoubleValue(value.chromaticityBlueX);
    encoder->EncodeDoubleValue(value.chromaticityBlueY);
    encoder->EncodeDoubleValue(value.chromaticityWhitePointX);
    encoder->EncodeDoubleValue(value.chromaticityWhitePointY);
    encoder->EncodeDoubleValue(value.minLuminance);
    encoder->EncodeDoubleValue(value.maxLuminance);
    encoder->EncodeDoubleValue(value.maxContentLightLevel);
    encoder->EncodeDoubleValue(value.maxFrameAverageLightLevel);
    encoder->EncodeUInt32Value(value.disableLocalDimming);
    encoder->EncodeUInt32Value(value.reservedPadding);
}

void Encode_agsInitialize(
    AGSReturnCode result, int agsVersion, const AGSConfiguration* config, AGSContext** context, AGSGPUInfo* gpuInfo)
{
    auto encoder =
        D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_Ags_agsInitialize_6_0_1);
    if (encoder)
    {
        bool omit_output_data = false;
        if (result != AGSReturnCode::AGS_SUCCESS)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(agsVersion);
        EncodeStructPtr(encoder, config);
        encoder->EncodeVoidPtr(omit_output_data ? nullptr : *context);
        EncodeStructPtr(encoder, gpuInfo, omit_output_data);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndAgsApiCallCapture(result, reinterpret_cast<void*>(*context));
    }
}

void Encode_agsDeInitialize(AGSReturnCode result, AGSContext* context)
{
    auto encoder =
        D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_Ags_agsDeInitialize_6_0_1);
    if (encoder)
    {
        encoder->EncodeVoidPtr(context);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndAgsApiCallCapture(result, reinterpret_cast<void*>(context));
    }
}

void Encode_agsDriverExtensionsDX12_CreateDevice(AGSReturnCode                      result,
                                                 AGSContext*                        context,
                                                 const AGSDX12DeviceCreationParams* creationParams,
                                                 const AGSDX12ExtensionParams*      extensionParams,
                                                 AGSDX12ReturnedParams*             returnedParams)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(
        format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_0_1);
    if (encoder)
    {
        bool omit_output_data = false;
        if (result != AGSReturnCode::AGS_SUCCESS)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(context);
        EncodeStructPtr(encoder, creationParams);
        EncodeStructPtr(encoder, extensionParams);
        EncodeStructPtr(encoder, returnedParams, omit_output_data);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndAgsApiCallCapture(result, reinterpret_cast<void*>(returnedParams->pDevice));
    }
}

void Encode_agsDriverExtensionsDX12_DestroyDevice(AGSReturnCode result,
                                                  AGSContext*   context,
                                                  ID3D12Device* device,
                                                  unsigned int* deviceReferences)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(
        format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_DestroyDevice_6_0_1);
    if (encoder)
    {
        encoder->EncodeVoidPtr(context);
        encoder->EncodeObjectValue(device);
        encoder->EncodeUInt32Ptr(deviceReferences);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndApiCallCapture();
    }
}

void Encode_agsCheckDriverVersion(AGSDriverVersionResult result,
                                  const char*            radeonSoftwareVersionReported,
                                  unsigned int           radeonSoftwareVersionRequired)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(
        format::ApiCallId::ApiCall_Ags_agsCheckDriverVersion_6_0_1);
    if (encoder)
    {
        encoder->EncodeString(radeonSoftwareVersionReported);
        encoder->EncodeUInt32Value(radeonSoftwareVersionRequired);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndApiCallCapture();
    }
}

void Encode_agsGetVersionNumber(int result)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(
        format::ApiCallId::ApiCall_Ags_agsGetVersionNumber_6_0_1);
    if (encoder)
    {
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndApiCallCapture();
    }
}

void Encode_agsSetDisplayMode(
    AGSReturnCode result, AGSContext* context, int deviceIndex, int displayIndex, const AGSDisplaySettings* settings)
{
    auto encoder =
        D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_Ags_agsSetDisplayMode_6_0_1);
    if (encoder)
    {
        encoder->EncodeVoidPtr(context);
        encoder->EncodeInt32Value(deviceIndex);
        encoder->EncodeInt32Value(displayIndex);
        EncodeStruct(encoder, *settings);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndApiCallCapture();
    }
}

void Encode_agsDriverExtensionsDX12_PushMarker(AGSReturnCode              result,
                                               AGSContext*                context,
                                               ID3D12GraphicsCommandList* commandList,
                                               const char*                data)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(
        format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_PushMarker_6_0_1);
    if (encoder)
    {
        encoder->EncodeVoidPtr(context);
        encoder->EncodeObjectValue(commandList);
        encoder->EncodeString(data);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndAgsApiCallCapture(
            reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(commandList));
    }
}

void Encode_agsDriverExtensionsDX12_PopMarker(AGSReturnCode              result,
                                              AGSContext*                context,
                                              ID3D12GraphicsCommandList* commandList)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(
        format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_PopMarker_6_0_1);
    if (encoder)
    {
        encoder->EncodeVoidPtr(context);
        encoder->EncodeObjectValue(commandList);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndAgsApiCallCapture(
            reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(commandList));
    }
}

void Encode_agsDriverExtensionsDX12_SetMarker(AGSReturnCode              result,
                                              AGSContext*                context,
                                              ID3D12GraphicsCommandList* commandList,
                                              const char*                data)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(
        format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_SetMarker_6_0_1);
    if (encoder)
    {
        encoder->EncodeVoidPtr(context);
        encoder->EncodeObjectValue(commandList);
        encoder->EncodeString(data);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndAgsApiCallCapture(
            reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(commandList));
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
