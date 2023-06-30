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

#ifndef GFXRECON_AGS_WRAPPERS_H
#define GFXRECON_AGS_WRAPPERS_H

#include "encode/d3d12_capture_manager.h"

#include <amd_ags.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

AMD_AGS_API AGSReturnCode agsInitialize(int                     agsVersion,
                                        const AGSConfiguration* config,
                                        AGSContext**            context,
                                        AGSGPUInfo*             gpuInfo);

AMD_AGS_API AGSReturnCode agsDeInitialize(AGSContext* context);

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_CreateDevice(AGSContext*                        context,
                                                               const AGSDX12DeviceCreationParams* creationParams,
                                                               const AGSDX12ExtensionParams*      extensionParams,
                                                               AGSDX12ReturnedParams*             returnedParams);

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_DestroyDevice(AGSContext*   context,
                                                                ID3D12Device* device,
                                                                unsigned int* deviceReferences);

AMD_AGS_API AGSDriverVersionResult agsCheckDriverVersion(const char*  radeonSoftwareVersionReported,
                                                         unsigned int radeonSoftwareVersionRequired);

AMD_AGS_API int agsGetVersionNumber();

AMD_AGS_API AGSReturnCode agsSetDisplayMode(AGSContext*               context,
                                            int                       deviceIndex,
                                            int                       displayIndex,
                                            const AGSDisplaySettings* settings);

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_PushMarker(AGSContext*                context,
                                                             ID3D12GraphicsCommandList* commandList,
                                                             const char*                data);

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_PopMarker(AGSContext*                context,
                                                            ID3D12GraphicsCommandList* commandList);

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_SetMarker(AGSContext*                context,
                                                            ID3D12GraphicsCommandList* commandList,
                                                            const char*                data);

AMD_AGS_API AGSReturnCode
agsDriverExtensionsDX12_CreateComputePipelineState(AGSContext*                              context,
                                                   unsigned int                             flags,
                                                   const D3D12_COMPUTE_PIPELINE_STATE_DESC* desc,
                                                   const IID&                               riid,
                                                   void**                                   pipelineState);

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_CreatePipelineState(AGSContext*                             context,
                                                                      unsigned int                            flags,
                                                                      const D3D12_PIPELINE_STATE_STREAM_DESC* desc,
                                                                      const IID&                              riid,
                                                                      void** pipelineState);

AMD_AGS_API void agsInitNotSupported();

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_AGS_WRAPPERS_H
