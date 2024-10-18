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

#include "decode/custom_ags_struct_decoders.h"
#include "custom_ags_replay_consumer.h"
#include "util/logging.h"

#include <amd_ags.h>

const char kAGS601DllName[] = ".\\amd_ags_x64.dll";

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

inline bool AgsReplayConsumer::ValidateContext(AGSContext* current)
{
    if (context_map_.find(current) == context_map_.end())
    {
        GFXRECON_LOG_WARNING("Processing function in AgsReplayConsumer: not found input context %p.", current);
        return false;
    }

    return true;
}

inline bool AgsReplayConsumer::ValidateDx12Consumer()
{
    if (dx12_replay_consumer_ == nullptr)
    {
        GFXRECON_LOG_WARNING("AGS: dx12 consumer not set.");
        return false;
    }
    return true;
}

inline bool AgsReplayConsumer::ValidateAgsInputs(AGSContext* context)
{
    return ValidateContext(context) && ValidateDx12Consumer();
}

static std::string GetAgsResultValueString(AGSReturnCode result)
{
    switch (result)
    {
        case AGS_SUCCESS:
            return "AGS_SUCCESS";
        case AGS_FAILURE:
            return "AGS_FAILURE";
        case AGS_INVALID_ARGS:
            return "AGS_INVALID_ARGS";
        case AGS_OUT_OF_MEMORY:
            return "AGS_OUT_OF_MEMORY";
        case AGS_MISSING_D3D_DLL:
            return "AGS_MISSING_D3D_DLL";
        case AGS_LEGACY_DRIVER:
            return "AGS_LEGACY_DRIVER";
        case AGS_NO_AMD_DRIVER_INSTALLED:
            return "AGS_NO_AMD_DRIVER_INSTALLED";
        case AGS_EXTENSION_NOT_SUPPORTED:
            return "AGS_EXTENSION_NOT_SUPPORTED";
        case AGS_ADL_FAILURE:
            return "AGS_ADL_FAILURE";
        case AGS_DX_FAILURE:
            return "AGS_DX_FAILURE";
        case AGS_D3DDEVICE_NOT_CREATED:
            return "AGS_D3DDEVICE_NOT_CREATED";
        default:
            return std::to_string(result);
    }
}

static std::string GetAgsResultValueString(AGSDriverVersionResult result)
{
    switch (result)
    {
        case AGS_SOFTWAREVERSIONCHECK_OK:
            return "AGS_SOFTWAREVERSIONCHECK_OK";
        case AGS_SOFTWAREVERSIONCHECK_OLDER:
            return "AGS_SOFTWAREVERSIONCHECK_OLDER";
        case AGS_SOFTWAREVERSIONCHECK_UNDEFINED:
            return "AGS_SOFTWAREVERSIONCHECK_UNDEFINED";
        default:
            return std::to_string(result);
    }
}

void AgsReplayConsumer::CheckReplayResult(const char*   call_name,
                                          AGSReturnCode capture_result,
                                          AGSReturnCode replay_result)
{
    if (capture_result != replay_result)
    {
        GFXRECON_LOG_WARNING("%s returned %s, which does not match the value returned at capture %s.",
                             call_name,
                             GetAgsResultValueString(replay_result).c_str(),
                             GetAgsResultValueString(capture_result).c_str());
    }
}

void AgsReplayConsumer::CheckReplayResult(const char*            call_name,
                                          AGSDriverVersionResult capture_result,
                                          AGSDriverVersionResult replay_result)
{
    if (capture_result != replay_result)
    {
        GFXRECON_LOG_WARNING("%s returned %s, which does not match the value returned at capture %s.",
                             call_name,
                             GetAgsResultValueString(replay_result).c_str(),
                             GetAgsResultValueString(capture_result).c_str());
    }
}

void AgsReplayConsumer::Process_agsInitialize(const ApiCallInfo&      call_info,
                                              AGSReturnCode           return_value,
                                              int                     agsVersion,
                                              const AGSConfiguration* config,
                                              AGSContext* const       context,
                                              const AGSGPUInfo&       gpuInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    AGSGPUInfo gpu_info_replay{};

    if (config != nullptr && (config->allocCallback != nullptr || config->freeCallback != nullptr))
    {
        GFXRECON_LOG_WARNING_ONCE(
            "agsInitialize function was called with a non-null 'config' parameter during capture. "
            "Now for replay, the parameter is set to a nullptr value, because the callback pointers can't be "
            "translated.");
    }

    AGSConfiguration* forced_config   = nullptr;
    auto              current_version = AGS_CURRENT_VERSION;

    if (agsVersion != current_version)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The agsInitialize function was called with an AGS version that is different from the current version. "
            "The replay will be processed with the latest AGS version.");
    }

    AGSContext*   replay_context = nullptr;
    AGSReturnCode result         = agsInitialize(current_version, forced_config, &replay_context, &gpu_info_replay);
    if (result == AGS_SUCCESS)
    {
        context_map_[context] = replay_context;
    }

    CheckReplayResult("Process_agsInitialize", return_value, result);
}

void AgsReplayConsumer::Process_agsDriverExtensionsDX12_CreateDevice(
    const ApiCallInfo&                                    call_info,
    AGSReturnCode                                         return_value,
    AGSContext*                                           context,
    AGSDX12DeviceCreationParams*                          creationParams,
    const AGSDX12ExtensionParams*                         extensionParams,
    StructPointerDecoder<Decoded_AGS_DX12_RETURN_PARAMS>* pReturnParams)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (ValidateAgsInputs(context))
    {
        IDXGIAdapter* current_adapter = nullptr;

        current_adapter = dx12_replay_consumer_->MapObject<IDXGIAdapter>(
            reinterpret_cast<gfxrecon::format::HandleId>(creationParams->pAdapter));

        if (current_adapter == nullptr)
        {
            current_adapter = dx12_replay_consumer_->GetAdapter();
        }

        creationParams->pAdapter = current_adapter;

        AGSDX12ReturnedParams returned_parameters{};
        AGSContext*           replay_context = context_map_[context];

        AGSReturnCode result =
            agsDriverExtensionsDX12_CreateDevice(replay_context, creationParams, extensionParams, &returned_parameters);

        // mapping created objects.
        // also need to check if the supported feature flags are still the same.
        DxObjectInfo object_info{};
        object_info.capture_id = pReturnParams->GetMetaStructPointer()->pDevice;
        object_info.object     = returned_parameters.pDevice;
        object_info.extra_info = std::move(std::make_unique<D3D12DeviceInfo>());
        dx12_replay_consumer_->AddObject(&(object_info.capture_id),
                                         reinterpret_cast<void**>(&(object_info.object)),
                                         std::move(object_info),
                                         format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_2_0);

        returned_parameters.extensionsSupported.padding          = 0;
        pReturnParams->GetPointer()->extensionsSupported.padding = 0;
        if (memcmp(&(returned_parameters.extensionsSupported),
                   &(pReturnParams->GetPointer()->extensionsSupported),
                   sizeof(returned_parameters.extensionsSupported)) != 0)
        {
            GFXRECON_LOG_WARNING(
                "Process_agsDriverExtensionsDX12_CreateDevice: returned extensions support doesn't match "
                "the captured extensions support.");
        }

        CheckReplayResult("Process_agsDriverExtensionsDX12_CreateDevice", return_value, result);
    }
}

void AgsReplayConsumer::Process_agsDriverExtensionsDX12_DestroyDevice(const ApiCallInfo& call_info,
                                                                      AGSReturnCode      return_value,
                                                                      AGSContext*        context,
                                                                      ID3D12Device*      device,
                                                                      unsigned int*      deviceReferences)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (ValidateAgsInputs(context))
    {
        ID3D12Device*              current_device            = nullptr;
        unsigned int               current_device_references = 0;
        gfxrecon::format::HandleId captured_device           = reinterpret_cast<gfxrecon::format::HandleId>(device);
        AGSContext*                replay_context            = context_map_[context];

        current_device = dx12_replay_consumer_->MapObject<ID3D12Device>(captured_device);

        AGSReturnCode result =
            agsDriverExtensionsDX12_DestroyDevice(replay_context, current_device, &current_device_references);

        DxObjectInfo object_info{};
        object_info.capture_id = captured_device;
        object_info.object     = current_device;
        dx12_replay_consumer_->RemoveObject(&object_info);

        CheckReplayResult("Process_agsDriverExtensionsDX12_DestroyDevice", return_value, result);
    }
}

void AgsReplayConsumer::Process_agsDeInitialize(const ApiCallInfo& call_info,
                                                AGSReturnCode      return_value,
                                                AGSContext*        context)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (ValidateContext(context))
    {
        AGSContext*   replay_context = context_map_[context];
        AGSReturnCode result         = agsDeInitialize(replay_context);

        if (result == AGS_SUCCESS)
        {
            context_map_.erase(context);
        }

        CheckReplayResult("Process_agsDeInitialize", return_value, result);
    }
}

void AgsReplayConsumer::Process_agsCheckDriverVersion(const ApiCallInfo&     call_info,
                                                      AGSDriverVersionResult return_value,
                                                      const char*            radeonSoftwareVersionReported,
                                                      unsigned int           radeonSoftwareVersionRequired)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    AGSDriverVersionResult result = agsCheckDriverVersion(radeonSoftwareVersionReported, radeonSoftwareVersionRequired);

    CheckReplayResult("Process_agsCheckDriverVersion", return_value, result);
}

void AgsReplayConsumer::Process_agsGetVersionNumber(const ApiCallInfo& call_info, int return_value)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    int result = agsGetVersionNumber();

    if (return_value != result)
    {
        GFXRECON_LOG_WARNING("%s returned %d, which does not match the value returned at capture %d.",
                             "Process_agsGetVersionNumber",
                             result,
                             return_value);
    }
}

void AgsReplayConsumer::Process_agsSetDisplayMode(const ApiCallInfo&        call_info,
                                                  AGSReturnCode             return_value,
                                                  AGSContext*               context,
                                                  int                       deviceIndex,
                                                  int                       displayIndex,
                                                  const AGSDisplaySettings* settings)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (ValidateContext(context))
    {
        AGSContext*   replay_context = context_map_[context];
        AGSReturnCode result         = agsSetDisplayMode(replay_context, deviceIndex, displayIndex, settings);

        CheckReplayResult("Process_agsSetDisplayMode", return_value, result);
    }
}

void AgsReplayConsumer::Process_agsDriverExtensionsDX12_PushMarker(const ApiCallInfo& call_info,
                                                                   AGSReturnCode      return_value,
                                                                   AGSContext*        context,
                                                                   format::HandleId   object_id,
                                                                   const char*        data)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (ValidateContext(context))
    {
        ID3D12GraphicsCommandList* command_list   = nullptr;
        AGSContext*                replay_context = context_map_[context];
        command_list = dx12_replay_consumer_->MapObject<ID3D12GraphicsCommandList>(object_id);

        AGSReturnCode result = agsDriverExtensionsDX12_PushMarker(replay_context, command_list, data);

        CheckReplayResult("agsDriverExtensionsDX12_PushMarker", return_value, result);
    }
}

void AgsReplayConsumer::Process_agsDriverExtensionsDX12_PopMarker(const ApiCallInfo& call_info,
                                                                  AGSReturnCode      return_value,
                                                                  AGSContext*        context,
                                                                  format::HandleId   object_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (ValidateContext(context))
    {
        ID3D12GraphicsCommandList* command_list   = nullptr;
        AGSContext*                replay_context = context_map_[context];
        command_list = dx12_replay_consumer_->MapObject<ID3D12GraphicsCommandList>(object_id);

        AGSReturnCode result = agsDriverExtensionsDX12_PopMarker(replay_context, command_list);

        CheckReplayResult("agsDriverExtensionsDX12_PopMarker", return_value, result);
    }
}

void AgsReplayConsumer::Process_agsDriverExtensionsDX12_SetMarker(const ApiCallInfo& call_info,
                                                                  AGSReturnCode      return_value,
                                                                  AGSContext*        context,
                                                                  format::HandleId   object_id,
                                                                  const char*        data)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (ValidateContext(context))
    {
        ID3D12GraphicsCommandList* command_list   = nullptr;
        AGSContext*                replay_context = context_map_[context];
        command_list = dx12_replay_consumer_->MapObject<ID3D12GraphicsCommandList>(object_id);

        AGSReturnCode result = agsDriverExtensionsDX12_SetMarker(replay_context, command_list, data);

        CheckReplayResult("agsDriverExtensionsDX12_SetMarker", return_value, result);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
