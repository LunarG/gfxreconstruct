/*
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include "custom_ags_struct_decoders.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_RECT* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;

    bytes_read += ValueDecoder::DecodeInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->offsetX);
    bytes_read += ValueDecoder::DecodeInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->offsetY);
    bytes_read += ValueDecoder::DecodeInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->width);
    bytes_read += ValueDecoder::DecodeInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->height);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DISPLAY_INFO* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t          bytes_read = 0;
    AGSDisplayInfo* value      = wrapper->decoded_value;

    wrapper->name.SetExternalMemory(value->name, sizeof(AGSDisplayInfo::name));
    wrapper->displayDeviceName.SetExternalMemory(value->displayDeviceName, sizeof(AGSDisplayInfo::displayDeviceName));
    bytes_read += wrapper->name.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += wrapper->displayDeviceName.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    uint32_t bit_value = 0;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->isPrimaryDisplay = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->HDR10 = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->dolbyVision = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->freesync = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->freesyncHDR = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->eyefinityInGroup = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->eyefinityPreferredDisplay = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->eyefinityInPortraitMode = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->reservedPadding = bit_value;

    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->maxResolutionX);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->maxResolutionY);
    bytes_read +=
        ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &value->maxRefreshRate);

    wrapper->currentResolution                = DecodeAllocator::Allocate<Decoded_AGS_RECT>();
    wrapper->currentResolution->decoded_value = &(value->currentResolution);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->currentResolution);

    wrapper->visibleResolution                = DecodeAllocator::Allocate<Decoded_AGS_RECT>();
    wrapper->visibleResolution->decoded_value = &(value->visibleResolution);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->visibleResolution);

    bytes_read +=
        ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &value->currentRefreshRate);

    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->eyefinityGridCoordX);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->eyefinityGridCoordY);

    bytes_read +=
        ValueDecoder::DecodeDoubleValue((buffer + bytes_read), (buffer_size - bytes_read), &value->chromaticityRedX);
    bytes_read +=
        ValueDecoder::DecodeDoubleValue((buffer + bytes_read), (buffer_size - bytes_read), &value->chromaticityRedY);
    bytes_read +=
        ValueDecoder::DecodeDoubleValue((buffer + bytes_read), (buffer_size - bytes_read), &value->chromaticityGreenX);
    bytes_read +=
        ValueDecoder::DecodeDoubleValue((buffer + bytes_read), (buffer_size - bytes_read), &value->chromaticityGreenY);
    bytes_read +=
        ValueDecoder::DecodeDoubleValue((buffer + bytes_read), (buffer_size - bytes_read), &value->chromaticityBlueX);
    bytes_read +=
        ValueDecoder::DecodeDoubleValue((buffer + bytes_read), (buffer_size - bytes_read), &value->chromaticityBlueY);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &value->chromaticityWhitePointX);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &value->chromaticityWhitePointY);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &value->screenDiffuseReflectance);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &value->screenSpecularReflectance);
    bytes_read +=
        ValueDecoder::DecodeDoubleValue((buffer + bytes_read), (buffer_size - bytes_read), &value->minLuminance);
    bytes_read +=
        ValueDecoder::DecodeDoubleValue((buffer + bytes_read), (buffer_size - bytes_read), &value->maxLuminance);
    bytes_read +=
        ValueDecoder::DecodeDoubleValue((buffer + bytes_read), (buffer_size - bytes_read), &value->avgLuminance);

    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->logicalDisplayIndex);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->adlAdapterIndex);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->reserved);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DEVICE_INFO* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t         bytes_read = 0;
    AGSDeviceInfo* value      = wrapper->decoded_value;

    value->adapterString = DecodeAllocator::Allocate<char>(kAdapterStringSize, true);
    wrapper->adapterString.SetExternalMemory(const_cast<char*>(value->adapterString), kAdapterStringSize);
    bytes_read += wrapper->adapterString.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &value->asicFamily);

    uint32_t bit_value = 0;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->isAPU = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->isPrimaryDevice = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->isExternal = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->reservedPadding = bit_value;

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->vendorId);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->deviceId);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->revisionId);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->numCUs);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->numWGPs);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->numROPs);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->coreClock);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->memoryClock);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->memoryBandwidth);

    bytes_read += ValueDecoder::DecodeFloatValue((buffer + bytes_read), (buffer_size - bytes_read), &value->teraFlops);
    bytes_read +=
        ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &value->localMemoryInBytes);
    bytes_read +=
        ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &value->sharedMemoryInBytes);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->numDisplays);

    // displays: it can be multiple
    wrapper->ppAgsDisplayInfo = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_AGS_DISPLAY_INFO>>();
    bytes_read += wrapper->ppAgsDisplayInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->displays = wrapper->ppAgsDisplayInfo->GetPointer();

    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->eyefinityEnabled);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->eyefinityGridWidth);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->eyefinityGridHeight);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->eyefinityResolutionX);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->eyefinityResolutionY);
    bytes_read += ValueDecoder::DecodeInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &value->eyefinityBezelCompensated);
    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->adlAdapterIndex);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->reserved);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DX12_DEVICE_CREATION_PARAMS* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                       bytes_read = 0;
    AGSDX12DeviceCreationParams* value      = wrapper->decoded_value;

    gfxrecon::format::HandleId adapter_id = 0;
    bytes_read += ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &adapter_id);
    value->pAdapter = reinterpret_cast<IDXGIAdapter*>(adapter_id);

    wrapper->iid                = DecodeAllocator::Allocate<Decoded_GUID>();
    wrapper->iid->decoded_value = &(value->iid);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->iid);
    value->iid = *(wrapper->iid->decoded_value);
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &value->FeatureLevel);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DX12_EXTENSION_PARAMS* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                  bytes_read = 0;
    AGSDX12ExtensionParams* value      = wrapper->decoded_value;

    value->pAppName = DecodeAllocator::Allocate<wchar_t>(kAdapterStringSize, true);
    wrapper->pAppName.SetExternalMemory(const_cast<wchar_t*>(value->pAppName), kAdapterStringSize);
    bytes_read += wrapper->pAppName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pEngineName = DecodeAllocator::Allocate<wchar_t>(kAdapterStringSize, true);
    wrapper->pEngineName.SetExternalMemory(const_cast<wchar_t*>(value->pEngineName), kAdapterStringSize);
    bytes_read += wrapper->pEngineName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->appVersion);
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->engineVersion);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->uavSlot);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DX12_EXTENSIONS_SUPPORTED* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                                      bytes_read = 0;
    AGSDX12ReturnedParams::ExtensionsSupported* value      = wrapper->decoded_value;

    uint32_t bit_value = 0;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->intrinsics16 = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->intrinsics17 = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->userMarkers = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->appRegistration = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->UAVBindSlot = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->intrinsics19 = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->baseVertex = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->baseInstance = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->getWaveSize = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->floatConversion = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->readLaneAt = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->rayHitToken = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    value->shaderClock = (bit_value & 0x1);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DX12_RETURN_PARAMS* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                 bytes_read = 0;
    AGSDX12ReturnedParams* value      = wrapper->decoded_value;

    gfxrecon::format::HandleId device_id = 0;
    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &device_id);
    wrapper->pDevice                            = device_id;
    wrapper->extensionsSupported                = DecodeAllocator::Allocate<Decoded_AGS_DX12_EXTENSIONS_SUPPORTED>();
    wrapper->extensionsSupported->decoded_value = &(value->extensionsSupported);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->extensionsSupported);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_CONFIGURATION* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t   bytes_read = 0;
    uint64_t alloc      = 0;
    uint64_t free       = 0;

    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &alloc);
    bytes_read += ValueDecoder::DecodeAddress((buffer + bytes_read), (buffer_size - bytes_read), &free);

    if (alloc == 0 && free == 0)
    {
        wrapper->decoded_value = nullptr;
    }
    else
    {
        wrapper->decoded_value->allocCallback = reinterpret_cast<AGS_ALLOC_CALLBACK>(alloc);
        wrapper->decoded_value->freeCallback  = reinterpret_cast<AGS_FREE_CALLBACK>(free);
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_GPU_INFO* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t      bytes_read = 0;
    AGSGPUInfo* value      = wrapper->decoded_value;

    value->driverVersion = DecodeAllocator::Allocate<char>(kDriverSoftwareStringSize, true);
    wrapper->driverVersion.SetExternalMemory(const_cast<char*>(value->driverVersion), kDriverSoftwareStringSize);
    bytes_read += wrapper->driverVersion.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->radeonSoftwareVersion = DecodeAllocator::Allocate<char>(kDriverSoftwareStringSize, true);
    wrapper->radeonSoftwareVersion.SetExternalMemory(const_cast<char*>(value->radeonSoftwareVersion),
                                                     kDriverSoftwareStringSize);
    bytes_read += wrapper->radeonSoftwareVersion.Decode((buffer + bytes_read), (buffer_size - bytes_read));

    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->numDevices);

    wrapper->ppAgsDeviceInfo = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_AGS_DEVICE_INFO>>();
    bytes_read += wrapper->ppAgsDeviceInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->devices = wrapper->ppAgsDeviceInfo->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DISPLAY_SETTINGS* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;

    bytes_read += ValueDecoder::DecodeInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<int32_t*>(&wrapper->decoded_value->mode));

    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->chromaticityRedX);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->chromaticityRedY);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->chromaticityGreenX);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->chromaticityGreenY);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->chromaticityBlueX);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->chromaticityBlueY);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->chromaticityWhitePointX);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->chromaticityWhitePointY);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->minLuminance);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->maxLuminance);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->maxContentLightLevel);
    bytes_read += ValueDecoder::DecodeDoubleValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_value->maxFrameAverageLightLevel);

    uint32_t bit_value = 0;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    wrapper->decoded_value->disableLocalDimming = bit_value;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &bit_value);
    wrapper->decoded_value->reservedPadding = bit_value;

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
