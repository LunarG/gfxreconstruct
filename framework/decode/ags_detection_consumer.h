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

#ifndef GFXRECON_DECODE_AGS_DETECTION_CONSUMER_H
#define GFXRECON_DECODE_AGS_DETECTION_CONSUMER_H

#include "decode/custom_ags_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class AgsDetectionConsumer : public AgsConsumerBase
{
  public:
    AgsDetectionConsumer() : created_ags_dx12_device_(false) {}
    bool         WasAgsDx12Detected() { return created_ags_dx12_device_; }
    virtual void Process_agsDriverExtensionsDX12_CreateDevice(
        const ApiCallInfo&                                    call_info,
        AGSReturnCode                                         return_value,
        AGSContext*                                           context,
        AGSDX12DeviceCreationParams*                          creationParams,
        const AGSDX12ExtensionParams*                         extensionParams,
        StructPointerDecoder<Decoded_AGS_DX12_RETURN_PARAMS>* pReturnParams) override
    {
        created_ags_dx12_device_ = true;
    }

    virtual void Process_agsInitialize(const ApiCallInfo&      call_info,
                                       AGSReturnCode           return_value,
                                       int                     agsVersion,
                                       const AGSConfiguration* config,
                                       AGSContext* const       context,
                                       const AGSGPUInfo&       gpuInfo) override
    {}

    virtual void Process_agsDriverExtensionsDX12_DestroyDevice(const ApiCallInfo& call_info,
                                                               AGSReturnCode      return_value,
                                                               AGSContext*        context,
                                                               ID3D12Device*      device,
                                                               unsigned int*      deviceReferences) override
    {}

    virtual void
    Process_agsDeInitialize(const ApiCallInfo& call_info, AGSReturnCode return_value, AGSContext* context) override
    {}

    virtual void Process_agsCheckDriverVersion(const ApiCallInfo&     call_info,
                                               AGSDriverVersionResult return_value,
                                               const char*            radeonSoftwareVersionReported,
                                               unsigned int           radeonSoftwareVersionRequired) override
    {}

    virtual void Process_agsGetVersionNumber(const ApiCallInfo& call_info, int return_value) override {}

    virtual void Process_agsSetDisplayMode(const ApiCallInfo&        call_info,
                                           AGSReturnCode             return_value,
                                           AGSContext*               context,
                                           int                       deviceIndex,
                                           int                       displayIndex,
                                           const AGSDisplaySettings* settings) override
    {}

    virtual void Process_agsDriverExtensionsDX12_PushMarker(const ApiCallInfo& call_info,
                                                            AGSReturnCode      return_value,
                                                            AGSContext*        context,
                                                            format::HandleId   object_id,
                                                            const char*        data) override
    {}

    virtual void Process_agsDriverExtensionsDX12_PopMarker(const ApiCallInfo& call_info,
                                                           AGSReturnCode      return_value,
                                                           AGSContext*        context,
                                                           format::HandleId   object_id) override
    {}

    virtual void Process_agsDriverExtensionsDX12_SetMarker(const ApiCallInfo& call_info,
                                                           AGSReturnCode      return_value,
                                                           AGSContext*        context,
                                                           format::HandleId   object_id,
                                                           const char*        data) override
    {}

  private:
    bool created_ags_dx12_device_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_AGS_DETECTION_CONSUMER_H
