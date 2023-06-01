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

#ifndef GFXRECON_AGS_API_CALL_ENCODERS_H
#define GFXRECON_AGS_API_CALL_ENCODERS_H

#include "custom_ags_wrappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodeStruct(ParameterEncoder* encoder, const AGSRect& value);

void EncodeStruct(ParameterEncoder* encoder, const AGSDisplayInfo& value);

void EncodeStruct(ParameterEncoder* encoder, const AGSDeviceInfo& value);

void EncodeStruct(ParameterEncoder* encoder, const AGSConfiguration& value);

void EncodeStruct(ParameterEncoder* encoder, const AGSGPUInfo& value);

void EncodeStruct(ParameterEncoder* encoder, const AGSDX12DeviceCreationParams& value);

void EncodeStruct(ParameterEncoder* encoder, const AGSDX12ExtensionParams& value);

void EncodeStruct(ParameterEncoder* encoder, const GUID& value);

void EncodeStruct(ParameterEncoder* encoder, const AGSDX12ReturnedParams& value);

void EncodeStruct(ParameterEncoder* encoder, const AGSDX12ReturnedParams::ExtensionsSupported& value);

void Encode_agsInitialize(
    AGSReturnCode result, int agsVersion, const AGSConfiguration* config, AGSContext** context, AGSGPUInfo* gpuInfo);

void Encode_agsDeInitialize(AGSReturnCode result, AGSContext* context);

void Encode_agsDriverExtensionsDX12_CreateDevice(AGSReturnCode                      result,
                                                 AGSContext*                        context,
                                                 const AGSDX12DeviceCreationParams* creationParams,
                                                 const AGSDX12ExtensionParams*      extensionParams,
                                                 AGSDX12ReturnedParams*             returnedParams);

void Encode_agsDriverExtensionsDX12_DestroyDevice(AGSReturnCode result,
                                                  AGSContext*   context,
                                                  ID3D12Device* device,
                                                  unsigned int* deviceReferences);

void Encode_agsCheckDriverVersion(AGSDriverVersionResult result,
                                  const char*            radeonSoftwareVersionReported,
                                  unsigned int           radeonSoftwareVersionRequired);

void Encode_agsGetVersionNumber(int result);

void Encode_agsSetDisplayMode(
    AGSReturnCode result, AGSContext* context, int deviceIndex, int displayIndex, const AGSDisplaySettings* settings);

void Encode_agsDriverExtensionsDX12_PushMarker(AGSReturnCode              result,
                                               AGSContext*                context,
                                               ID3D12GraphicsCommandList* commandList,
                                               const char*                data);

void Encode_agsDriverExtensionsDX12_PopMarker(AGSReturnCode              result,
                                              AGSContext*                context,
                                              ID3D12GraphicsCommandList* commandList);

void Encode_agsDriverExtensionsDX12_SetMarker(AGSReturnCode              result,
                                              AGSContext*                context,
                                              ID3D12GraphicsCommandList* commandList,
                                              const char*                data);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_AGS_API_CALL_ENCODERS_H
