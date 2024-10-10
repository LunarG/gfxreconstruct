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
#include "custom_ags_wrappers.h"
#include "custom_dx12_wrapper_commands.h"
#include "generated/generated_dx12_struct_unwrappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

AMD_AGS_API AGSReturnCode agsInitialize(int                     agsVersion,
                                        const AGSConfiguration* config,
                                        AGSContext**            context,
                                        AGSGPUInfo*             gpuInfo)
{
    AGSReturnCode result = AGSReturnCode::AGS_SUCCESS;

    auto manager = D3D12CaptureManager::Get();
    manager->SetAgsVersion(agsVersion);
    if (((agsVersion >> 22) & 0x3FF) < AMD_AGS_VERSION_MAJOR)
    {
        GFXRECON_LOG_ERROR("The AGS version is not supported.");
    }
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();
        std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
        std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
        if (force_command_serialization)
        {
            exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();
        }
        else
        {
            shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();
        }

        CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsInitialize_6_0_1>::Dispatch(
            manager, agsVersion, config, context, gpuInfo);

        result = manager->GetAgsDispatchTable().agsInitialize(agsVersion, config, context, gpuInfo);

        Encode_agsInitialize(result, agsVersion, config, context, gpuInfo);

        CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsInitialize_6_0_1>::Dispatch(
            manager, result, agsVersion, config, context, gpuInfo);
    }
    else
    {
        result = manager->GetAgsDispatchTable().agsInitialize(agsVersion, config, context, gpuInfo);
    }

    manager->DecrementCallScope();

    return result;
}

AMD_AGS_API AGSReturnCode agsDeInitialize(AGSContext* context)
{
    AGSReturnCode result = AGSReturnCode::AGS_SUCCESS;

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();
        std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
        std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
        if (force_command_serialization)
        {
            exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();
        }
        else
        {
            shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();
        }

        CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsDeInitialize_6_0_1>::Dispatch(manager, context);

        result = manager->GetAgsDispatchTable().agsDeInitialize(context);

        Encode_agsDeInitialize(result, context);

        CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsDeInitialize_6_0_1>::Dispatch(manager, result, context);
    }
    else
    {
        result = manager->GetAgsDispatchTable().agsDeInitialize(context);
    }

    manager->DecrementCallScope();

    return result;
}

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_CreateDevice(AGSContext*                        context,
                                                               const AGSDX12DeviceCreationParams* creationParams,
                                                               const AGSDX12ExtensionParams*      extensionParams,
                                                               AGSDX12ReturnedParams*             returnedParams)
{
    AGSReturnCode result = AGSReturnCode::AGS_SUCCESS;

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();
        std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
        std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
        if (force_command_serialization)
        {
            exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();
        }
        else
        {
            shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();
        }
        auto ags_version = manager->GetAgsVersion();
        int  ags_major   = (ags_version >> 22) & 0x3FF;
        int  ags_minor   = (ags_version >> 12) & 0x3FF;
        if (ags_version == AGS_CURRENT_VERSION)
        {
            CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_2_0>::Dispatch(
                manager, context, creationParams, extensionParams, returnedParams);

            result = manager->GetAgsDispatchTable().agsDriverExtensionsDX12_CreateDevice(
                context, creationParams, extensionParams, returnedParams);

            if (SUCCEEDED(result))
            {
                WrapObject(creationParams->iid, reinterpret_cast<void**>(&(returnedParams->pDevice)), nullptr);
            }

            Encode_agsDriverExtensionsDX12_CreateDevice(
                result,
                context,
                creationParams,
                extensionParams,
                returnedParams,
                format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_2_0);

            CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_2_0>::Dispatch(
                manager, result, context, creationParams, extensionParams, returnedParams);
        }
        else if (ags_major == AMD_AGS_VERSION_MAJOR && ags_minor < 2)
        {
            CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_0_1>::Dispatch(
                manager, context, creationParams, extensionParams, returnedParams);

            result = manager->GetAgsDispatchTable().agsDriverExtensionsDX12_CreateDevice(
                context, creationParams, extensionParams, returnedParams);

            if (SUCCEEDED(result))
            {
                WrapObject(creationParams->iid, reinterpret_cast<void**>(&(returnedParams->pDevice)), nullptr);
            }

            Encode_agsDriverExtensionsDX12_CreateDevice(
                result,
                context,
                creationParams,
                extensionParams,
                returnedParams,
                format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_0_1);

            CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_CreateDevice_6_0_1>::Dispatch(
                manager, result, context, creationParams, extensionParams, returnedParams);
        }
    }
    else
    {
        result = manager->GetAgsDispatchTable().agsDriverExtensionsDX12_CreateDevice(
            context, creationParams, extensionParams, returnedParams);
    }

    manager->DecrementCallScope();

    return result;
}

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_DestroyDevice(AGSContext*   context,
                                                                ID3D12Device* device,
                                                                unsigned int* deviceReferences)
{
    AGSReturnCode result = AGSReturnCode::AGS_SUCCESS;

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();
        std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
        std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
        if (force_command_serialization)
        {
            exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();
        }
        else
        {
            shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();
        }

        CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_DestroyDevice_6_0_1>::Dispatch(
            manager, context, device, deviceReferences);

        ID3D12Device* object = encode::GetWrappedObject<ID3D12Device>(device);

        result =
            manager->GetAgsDispatchTable().agsDriverExtensionsDX12_DestroyDevice(context, object, deviceReferences);

        Encode_agsDriverExtensionsDX12_DestroyDevice(result, context, device, deviceReferences);

        CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_DestroyDevice_6_0_1>::Dispatch(
            manager, result, context, device, deviceReferences);
    }
    else
    {
        result =
            manager->GetAgsDispatchTable().agsDriverExtensionsDX12_DestroyDevice(context, device, deviceReferences);
    }

    manager->DecrementCallScope();

    return result;
}

AMD_AGS_API AGSDriverVersionResult agsCheckDriverVersion(const char*  radeonSoftwareVersionReported,
                                                         unsigned int radeonSoftwareVersionRequired)
{
    AGSDriverVersionResult result = AGSDriverVersionResult::AGS_SOFTWAREVERSIONCHECK_UNDEFINED;

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();
        std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
        std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
        if (force_command_serialization)
        {
            exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();
        }
        else
        {
            shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();
        }

        CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsCheckDriverVersion_6_0_1>::Dispatch(
            manager, radeonSoftwareVersionReported, radeonSoftwareVersionRequired);

        result = manager->GetAgsDispatchTable().agsCheckDriverVersion(radeonSoftwareVersionReported,
                                                                      radeonSoftwareVersionRequired);

        Encode_agsCheckDriverVersion(result, radeonSoftwareVersionReported, radeonSoftwareVersionRequired);

        CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsCheckDriverVersion_6_0_1>::Dispatch(
            manager, result, radeonSoftwareVersionReported, radeonSoftwareVersionRequired);
    }
    else
    {
        result = manager->GetAgsDispatchTable().agsCheckDriverVersion(radeonSoftwareVersionReported,
                                                                      radeonSoftwareVersionRequired);
    }

    manager->DecrementCallScope();

    return result;
}

AMD_AGS_API int agsGetVersionNumber()
{
    int result = 0;

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();
        std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
        std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
        if (force_command_serialization)
        {
            exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();
        }
        else
        {
            shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();
        }

        CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsGetVersionNumber_6_0_1>::Dispatch(manager);

        result = manager->GetAgsDispatchTable().agsGetVersionNumber();

        Encode_agsGetVersionNumber(result);

        CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsGetVersionNumber_6_0_1>::Dispatch(manager, result);
    }
    else
    {
        result = manager->GetAgsDispatchTable().agsGetVersionNumber();
    }

    manager->DecrementCallScope();

    return result;
}

AMD_AGS_API AGSReturnCode agsSetDisplayMode(AGSContext*               context,
                                            int                       deviceIndex,
                                            int                       displayIndex,
                                            const AGSDisplaySettings* settings)
{
    AGSReturnCode result = AGSReturnCode::AGS_SUCCESS;

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();
        std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
        std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
        if (force_command_serialization)
        {
            exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();
        }
        else
        {
            shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();
        }

        CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsSetDisplayMode_6_0_1>::Dispatch(
            manager, context, deviceIndex, displayIndex, settings);

        result = manager->GetAgsDispatchTable().agsSetDisplayMode(context, deviceIndex, displayIndex, settings);

        Encode_agsSetDisplayMode(result, context, deviceIndex, displayIndex, settings);

        CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsSetDisplayMode_6_0_1>::Dispatch(
            manager, result, context, deviceIndex, displayIndex, settings);
    }
    else
    {
        result = manager->GetAgsDispatchTable().agsSetDisplayMode(context, deviceIndex, displayIndex, settings);
    }

    manager->DecrementCallScope();

    return result;
}

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_PushMarker(AGSContext*                context,
                                                             ID3D12GraphicsCommandList* commandList,
                                                             const char*                data)
{
    AGSReturnCode result = AGSReturnCode::AGS_SUCCESS;

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();
        std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
        std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
        if (force_command_serialization)
        {
            exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();
        }
        else
        {
            shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();
        }

        CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_PushMarker_6_0_1>::Dispatch(
            manager, context, commandList, data);

        ID3D12GraphicsCommandList* object = encode::GetWrappedObject<ID3D12GraphicsCommandList>(commandList);

        result = manager->GetAgsDispatchTable().agsDriverExtensionsDX12_PushMarker(context, commandList, data);

        Encode_agsDriverExtensionsDX12_PushMarker(result, context, commandList, data);

        CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_PushMarker_6_0_1>::Dispatch(
            manager, result, context, commandList, data);
    }
    else
    {
        result = manager->GetAgsDispatchTable().agsDriverExtensionsDX12_PushMarker(context, commandList, data);
    }

    manager->DecrementCallScope();

    return result;
}

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_PopMarker(AGSContext* context, ID3D12GraphicsCommandList* commandList)
{
    AGSReturnCode result = AGSReturnCode::AGS_SUCCESS;

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();
        std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
        std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
        if (force_command_serialization)
        {
            exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();
        }
        else
        {
            shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();
        }

        CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_PopMarker_6_0_1>::Dispatch(
            manager, context, commandList);

        ID3D12GraphicsCommandList* object = encode::GetWrappedObject<ID3D12GraphicsCommandList>(commandList);

        result = manager->GetAgsDispatchTable().agsDriverExtensionsDX12_PopMarker(context, commandList);

        Encode_agsDriverExtensionsDX12_PopMarker(result, context, commandList);

        CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_PopMarker_6_0_1>::Dispatch(
            manager, result, context, commandList);
    }
    else
    {
        result = manager->GetAgsDispatchTable().agsDriverExtensionsDX12_PopMarker(context, commandList);
    }

    manager->DecrementCallScope();

    return result;
}

AMD_AGS_API AGSReturnCode agsDriverExtensionsDX12_SetMarker(AGSContext*                context,
                                                            ID3D12GraphicsCommandList* commandList,
                                                            const char*                data)
{
    AGSReturnCode result = AGSReturnCode::AGS_SUCCESS;

    auto manager    = D3D12CaptureManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();
        std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
        std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
        if (force_command_serialization)
        {
            exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();
        }
        else
        {
            shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();
        }

        CustomWrapperPreCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_SetMarker_6_0_1>::Dispatch(
            manager, context, commandList, data);

        ID3D12GraphicsCommandList* object = encode::GetWrappedObject<ID3D12GraphicsCommandList>(commandList);

        result = manager->GetAgsDispatchTable().agsDriverExtensionsDX12_SetMarker(context, object, data);

        Encode_agsDriverExtensionsDX12_SetMarker(result, context, commandList, data);

        CustomWrapperPostCall<format::ApiCallId::ApiCall_Ags_agsDriverExtensionsDX12_SetMarker_6_0_1>::Dispatch(
            manager, result, context, commandList, data);
    }
    else
    {
        result = manager->GetAgsDispatchTable().agsDriverExtensionsDX12_SetMarker(context, commandList, data);
    }

    manager->DecrementCallScope();

    return result;
}

AMD_AGS_API void agsInitNotSupported()
{
    GFXRECON_LOG_ERROR_ONCE("AGS version mismatch for GFXR capture: GFXR doesn't support this version of "
                            "amd_ags_x64.dll. Please remove the capture DLL and rename the original DLL back.");
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
