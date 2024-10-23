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

#ifndef GFXRECON_CUSTOM_AGS_REPLAY_CONSUMER_H
#define GFXRECON_CUSTOM_AGS_REPLAY_CONSUMER_H

#include "custom_ags_consumer_base.h"
#include "dx12_replay_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct AgsDispatchTable_6_0_1
{
    AGS_INITIALIZE                         agsInitialize{ nullptr };
    AGS_DEINITIALIZE                       agsDeInitialize{ nullptr };
    AGS_CHECKDRIVERVERSION                 agsCheckDriverVersion{ nullptr };
    AGS_DRIVEREXTENSIONSDX12_CREATEDEVICE  agsDriverExtensionsDX12_CreateDevice{ nullptr };
    AGS_DRIVEREXTENSIONSDX12_DESTROYDEVICE agsDriverExtensionsDX12_DestroyDevice{ nullptr };
    AGS_GETVERSIONNUMBER                   agsGetVersionNumber{ nullptr };
    AGS_SETDISPLAYMODE                     agsSetDisplayMode{ nullptr };
    AGS_DRIVEREXTENSIONSDX12_PUSHMARKER    agsDriverExtensionsDX12_PushMarker{ nullptr };
    AGS_DRIVEREXTENSIONSDX12_POPMARKER     agsDriverExtensionsDX12_PopMarker{ nullptr };
    AGS_DRIVEREXTENSIONSDX12_SETMARKER     agsDriverExtensionsDX12_SetMarker{ nullptr };
};

class AgsReplayConsumer : public AgsConsumerBase
{
  public:
    AgsReplayConsumer() {}
    virtual ~AgsReplayConsumer() override {}

    virtual void Process_agsInitialize(const ApiCallInfo&      call_info,
                                       AGSReturnCode           return_value,
                                       int                     agsVersion,
                                       const AGSConfiguration* config,
                                       AGSContext* const       context,
                                       const AGSGPUInfo&       gpuInfo) override;

    virtual void Process_agsDriverExtensionsDX12_CreateDevice(
        const ApiCallInfo&                                    call_info,
        AGSReturnCode                                         return_value,
        AGSContext*                                           context,
        AGSDX12DeviceCreationParams*                          creationParams,
        const AGSDX12ExtensionParams*                         extensionParams,
        StructPointerDecoder<Decoded_AGS_DX12_RETURN_PARAMS>* pReturnParams) override;

    virtual void Process_agsDriverExtensionsDX12_DestroyDevice(const ApiCallInfo& call_info,
                                                               AGSReturnCode      return_value,
                                                               AGSContext*        context,
                                                               ID3D12Device*      device,
                                                               unsigned int*      deviceReferences) override;

    virtual void
    Process_agsDeInitialize(const ApiCallInfo& call_info, AGSReturnCode return_value, AGSContext* context) override;

    virtual void Process_agsCheckDriverVersion(const ApiCallInfo&     call_info,
                                               AGSDriverVersionResult return_value,
                                               const char*            radeonSoftwareVersionReported,
                                               unsigned int           radeonSoftwareVersionRequired) override;

    virtual void Process_agsGetVersionNumber(const ApiCallInfo& call_info, int return_value) override;

    virtual void Process_agsSetDisplayMode(const ApiCallInfo&        call_info,
                                           AGSReturnCode             return_value,
                                           AGSContext*               context,
                                           int                       deviceIndex,
                                           int                       displayIndex,
                                           const AGSDisplaySettings* settings) override;

    virtual void Process_agsDriverExtensionsDX12_PushMarker(const ApiCallInfo& call_info,
                                                            AGSReturnCode      return_value,
                                                            AGSContext*        context,
                                                            format::HandleId   object_id,
                                                            const char*        data) override;

    virtual void Process_agsDriverExtensionsDX12_PopMarker(const ApiCallInfo& call_info,
                                                           AGSReturnCode      return_value,
                                                           AGSContext*        context,
                                                           format::HandleId   object_id) override;

    virtual void Process_agsDriverExtensionsDX12_SetMarker(const ApiCallInfo& call_info,
                                                           AGSReturnCode      return_value,
                                                           AGSContext*        context,
                                                           format::HandleId   object_id,
                                                           const char*        data) override;

    void AddDx12Consumer(Dx12ReplayConsumerBase* dx12_replay_consumer) { dx12_replay_consumer_ = dx12_replay_consumer; }

  private:
    inline bool ValidateAgsInputs(AGSContext* context);
    inline bool ValidateContext(AGSContext* current);
    inline bool ValidateDx12Consumer();

    void CheckReplayResult(const char* call_name, AGSReturnCode capture_result, AGSReturnCode replay_result);
    void CheckReplayResult(const char*            call_name,
                           AGSDriverVersionResult capture_result,
                           AGSDriverVersionResult replay_result);

    std::map<AGSContext*, AGSContext*> context_map_; // Map of captured context to current context
    Dx12ReplayConsumerBase*            dx12_replay_consumer_{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CUSTOM_AGS_REPLAY_CONSUMER_H
