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

#ifndef GFXRECON_DECODE_CUSTOM_AGS_STRUCT_DECODERS_H
#define GFXRECON_DECODE_CUSTOM_AGS_STRUCT_DECODERS_H

#include "decode/pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "generated/generated_dx12_struct_decoders.h"

#include <amd_ags.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const int32_t kAdapterStringSize        = 256;
const int32_t kDriverSoftwareStringSize = 256;

struct Decoded_AGS_CONFIGURATION
{
    using struct_type = AGSConfiguration;

    AGSConfiguration* decoded_value{ nullptr };
};

struct Decoded_AGS_RECT
{
    using struct_type = AGSRect;

    AGSRect* decoded_value{ nullptr };
};

struct Decoded_AGS_DISPLAY_INFO
{
    using struct_type = AGSDisplayInfo;

    AGSDisplayInfo*   decoded_value{ nullptr };
    StringDecoder     name;
    StringDecoder     displayDeviceName;
    Decoded_AGS_RECT* currentResolution{ nullptr };
    Decoded_AGS_RECT* visibleResolution{ nullptr };
};

struct Decoded_AGS_DEVICE_INFO
{
    using struct_type = AGSDeviceInfo;

    AGSDeviceInfo*                                  decoded_value{ nullptr };
    StringDecoder                                   adapterString;
    StructPointerDecoder<Decoded_AGS_DISPLAY_INFO>* ppAgsDisplayInfo{ nullptr };
};

struct Decoded_AGS_GPU_INFO
{
    using struct_type = AGSGPUInfo;

    AGSGPUInfo*                                    decoded_value{ nullptr };
    StringDecoder                                  driverVersion;
    StringDecoder                                  radeonSoftwareVersion;
    StructPointerDecoder<Decoded_AGS_DEVICE_INFO>* ppAgsDeviceInfo{ nullptr };
};

struct Decoded_AGS_DX12_DEVICE_CREATION_PARAMS
{
    using struct_type = AGSDX12DeviceCreationParams;

    AGSDX12DeviceCreationParams* decoded_value{ nullptr };
    Decoded_GUID*                iid{ nullptr };
};

struct Decoded_AGS_DX12_EXTENSION_PARAMS
{
    using struct_type = AGSDX12ExtensionParams;

    AGSDX12ExtensionParams* decoded_value{ nullptr };
    WStringDecoder          pAppName;
    WStringDecoder          pEngineName;
};

struct Decoded_AGS_DX12_EXTENSIONS_SUPPORTED
{
    using struct_type = AGSDX12ReturnedParams::ExtensionsSupported;

    AGSDX12ReturnedParams::ExtensionsSupported* decoded_value{ nullptr };
};

struct Decoded_AGS_DX12_RETURN_PARAMS
{
    using struct_type = AGSDX12ReturnedParams;

    AGSDX12ReturnedParams*                 decoded_value{ nullptr };
    format::HandleId                       pDevice;
    Decoded_AGS_DX12_EXTENSIONS_SUPPORTED* extensionsSupported{ nullptr };
};

struct Decoded_AGS_DISPLAY_SETTINGS
{
    using struct_type = AGSDisplaySettings;

    AGSDisplaySettings* decoded_value{ nullptr };
};

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_RECT* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DISPLAY_INFO* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DEVICE_INFO* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DX12_DEVICE_CREATION_PARAMS* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DX12_EXTENSION_PARAMS* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DX12_EXTENSIONS_SUPPORTED* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DX12_RETURN_PARAMS* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_CONFIGURATION* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_GPU_INFO* wrapper);
size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_AGS_DISPLAY_SETTINGS* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_ASG_STRUCT_DECODERS_H
