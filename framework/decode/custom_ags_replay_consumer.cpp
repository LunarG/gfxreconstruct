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
    if (current != captured_context_)
    {
        GFXRECON_LOG_WARNING("Processing function in AgsReplayConsumer: input context value %p doesn't match "
                             "initialization value %p.",
                             current,
                             captured_context_);
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

void AgsReplayConsumer::LoadAgsDll()
{
    if (ags_dll_ == nullptr)
    {
        ags_dll_ = util::platform::OpenLibrary(kAGS601DllName);
    }

    if (ags_dll_ != nullptr)
    {
        ags_dispatch_table_.agsInitialize =
            reinterpret_cast<decltype(agsInitialize)*>(GetProcAddress(ags_dll_, "agsInitialize"));

        ags_dispatch_table_.agsDriverExtensionsDX12_CreateDevice =
            reinterpret_cast<decltype(agsDriverExtensionsDX12_CreateDevice)*>(
                GetProcAddress(ags_dll_, "agsDriverExtensionsDX12_CreateDevice"));

        ags_dispatch_table_.agsDriverExtensionsDX12_DestroyDevice =
            reinterpret_cast<decltype(agsDriverExtensionsDX12_DestroyDevice)*>(
                GetProcAddress(ags_dll_, "agsDriverExtensionsDX12_DestroyDevice"));

        ags_dispatch_table_.agsDeInitialize =
            reinterpret_cast<decltype(agsDeInitialize)*>(GetProcAddress(ags_dll_, "agsDeInitialize"));

        ags_dispatch_table_.agsCheckDriverVersion =
            reinterpret_cast<decltype(agsCheckDriverVersion)*>(GetProcAddress(ags_dll_, "agsCheckDriverVersion"));

        ags_dispatch_table_.agsGetVersionNumber =
            reinterpret_cast<decltype(agsGetVersionNumber)*>(GetProcAddress(ags_dll_, "agsGetVersionNumber"));

        ags_dispatch_table_.agsSetDisplayMode =
            reinterpret_cast<decltype(agsSetDisplayMode)*>(GetProcAddress(ags_dll_, "agsSetDisplayMode"));

        ags_dispatch_table_.agsDriverExtensionsDX12_PushMarker =
            reinterpret_cast<decltype(agsDriverExtensionsDX12_PushMarker)*>(
                GetProcAddress(ags_dll_, "agsDriverExtensionsDX12_PushMarker"));

        ags_dispatch_table_.agsDriverExtensionsDX12_PopMarker =
            reinterpret_cast<decltype(agsDriverExtensionsDX12_PopMarker)*>(
                GetProcAddress(ags_dll_, "agsDriverExtensionsDX12_PopMarker"));

        ags_dispatch_table_.agsDriverExtensionsDX12_SetMarker =
            reinterpret_cast<decltype(agsDriverExtensionsDX12_SetMarker)*>(
                GetProcAddress(ags_dll_, "agsDriverExtensionsDX12_SetMarker"));

        if ((ags_dispatch_table_.agsInitialize != nullptr) &&
            (ags_dispatch_table_.agsDriverExtensionsDX12_CreateDevice != nullptr) &&
            (ags_dispatch_table_.agsDriverExtensionsDX12_DestroyDevice != nullptr) &&
            (ags_dispatch_table_.agsDeInitialize != nullptr) &&
            (ags_dispatch_table_.agsCheckDriverVersion != nullptr) &&
            (ags_dispatch_table_.agsGetVersionNumber != nullptr) &&
            (ags_dispatch_table_.agsSetDisplayMode != nullptr) &&
            (ags_dispatch_table_.agsDriverExtensionsDX12_PushMarker != nullptr) &&
            (ags_dispatch_table_.agsDriverExtensionsDX12_PopMarker != nullptr) &&
            (ags_dispatch_table_.agsDriverExtensionsDX12_SetMarker != nullptr))
        {
            ags_dll_loaded_ = true;
        }

        if (!ags_dll_loaded_)
        {
            GFXRECON_LOG_WARNING("AGS: failure loading ags dll.");
        }
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

    LoadAgsDll();

    if (ags_dll_loaded_)
    {
        captured_context_ = context;
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
                "The agsInitialize function was called with an AGS version that is different from the current version."
                "The replay will be processed with the latest AGS version.");
        }

        AGSReturnCode result =
            ags_dispatch_table_.agsInitialize(current_version, forced_config, &current_context_, &gpu_info_replay);

        CheckReplayResult("Process_agsInitialize", return_value, result);
    }
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

    if (ags_dll_loaded_ && ValidateAgsInputs(context))
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
        AGSReturnCode         result = ags_dispatch_table_.agsDriverExtensionsDX12_CreateDevice(
            current_context_, creationParams, extensionParams, &returned_parameters);

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

    if (ags_dll_loaded_ && ValidateAgsInputs(context))
    {
        ID3D12Device*              current_device            = nullptr;
        unsigned int               current_device_references = 0;
        gfxrecon::format::HandleId captured_device           = reinterpret_cast<gfxrecon::format::HandleId>(device);

        current_device = dx12_replay_consumer_->MapObject<ID3D12Device>(captured_device);

        AGSReturnCode result = ags_dispatch_table_.agsDriverExtensionsDX12_DestroyDevice(
            current_context_, current_device, &current_device_references);

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

    if (ags_dll_loaded_ && ValidateContext(context))
    {
        AGSReturnCode result = ags_dispatch_table_.agsDeInitialize(current_context_);

        CheckReplayResult("Process_agsDeInitialize", return_value, result);
    }
}

void AgsReplayConsumer::Process_agsCheckDriverVersion(const ApiCallInfo&     call_info,
                                                      AGSDriverVersionResult return_value,
                                                      const char*            radeonSoftwareVersionReported,
                                                      unsigned int           radeonSoftwareVersionRequired)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (ags_dll_loaded_)
    {
        AGSDriverVersionResult result =
            ags_dispatch_table_.agsCheckDriverVersion(radeonSoftwareVersionReported, radeonSoftwareVersionRequired);

        CheckReplayResult("Process_agsCheckDriverVersion", return_value, result);
    }
}

void AgsReplayConsumer::Process_agsGetVersionNumber(const ApiCallInfo& call_info, int return_value)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (ags_dll_loaded_)
    {
        int result = ags_dispatch_table_.agsGetVersionNumber();

        if (return_value != result)
        {
            GFXRECON_LOG_WARNING("%s returned %d, which does not match the value returned at capture %d.",
                                 "Process_agsGetVersionNumber",
                                 result,
                                 return_value);
        }
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

    if (ags_dll_loaded_ && ValidateContext(context))
    {
        AGSReturnCode result =
            ags_dispatch_table_.agsSetDisplayMode(current_context_, deviceIndex, displayIndex, settings);

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

    if (ags_dll_loaded_ && ValidateContext(context))
    {
        ID3D12GraphicsCommandList* command_list = nullptr;
        command_list = dx12_replay_consumer_->MapObject<ID3D12GraphicsCommandList>(object_id);

        AGSReturnCode result =
            ags_dispatch_table_.agsDriverExtensionsDX12_PushMarker(current_context_, command_list, data);

        CheckReplayResult("agsDriverExtensionsDX12_PushMarker", return_value, result);
    }
}

void AgsReplayConsumer::Process_agsDriverExtensionsDX12_PopMarker(const ApiCallInfo& call_info,
                                                                  AGSReturnCode      return_value,
                                                                  AGSContext*        context,
                                                                  format::HandleId   object_id)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (ags_dll_loaded_ && ValidateContext(context))
    {
        ID3D12GraphicsCommandList* command_list = nullptr;
        command_list = dx12_replay_consumer_->MapObject<ID3D12GraphicsCommandList>(object_id);

        AGSReturnCode result = ags_dispatch_table_.agsDriverExtensionsDX12_PopMarker(current_context_, command_list);

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

    if (ags_dll_loaded_ && ValidateContext(context))
    {
        ID3D12GraphicsCommandList* command_list = nullptr;
        command_list = dx12_replay_consumer_->MapObject<ID3D12GraphicsCommandList>(object_id);

        AGSReturnCode result =
            ags_dispatch_table_.agsDriverExtensionsDX12_SetMarker(current_context_, command_list, data);

        CheckReplayResult("agsDriverExtensionsDX12_SetMarker", return_value, result);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
