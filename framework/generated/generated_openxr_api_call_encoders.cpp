/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos OpenXR XML API Registry.
**
*/

#ifdef ENABLE_OPENXR_SUPPORT

#include "generated/generated_openxr_api_call_encoders.h"

#include "encode/custom_openxr_encoder_commands.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/openxr_capture_manager.h"
#include "encode/openxr_handle_wrapper_util.h"
#include "encode/openxr_handle_wrappers.h"
#include "format/api_call_id.h"
#include "generated/generated_openxr_struct_handle_wrappers.h"
#include "util/defines.h"

#include "openxr/openxr.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyInstance(
    XrInstance                                  instance)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyInstance>::Dispatch(manager, instance);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(instance)->DestroyInstance(instance);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyInstance);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::InstanceWrapper>(instance);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyInstance>::Dispatch(manager, result, instance);

    DestroyWrappedOpenXrHandle<openxr_wrappers::InstanceWrapper>(instance);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetInstanceProperties(
    XrInstance                                  instance,
    XrInstanceProperties*                       instanceProperties)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetInstanceProperties>::Dispatch(manager, instance, instanceProperties);

    XrResult result = GetOpenXrInstanceTable(instance)->GetInstanceProperties(instance, instanceProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetInstanceProperties);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, instanceProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetInstanceProperties>::Dispatch(manager, result, instance, instanceProperties);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrPollEvent(
    XrInstance                                  instance,
    XrEventDataBuffer*                          eventData)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPollEvent>::Dispatch(manager, instance, eventData);

    XrResult result = GetOpenXrInstanceTable(instance)->PollEvent(instance, eventData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPollEvent);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, eventData, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPollEvent>::Dispatch(manager, result, instance, eventData);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrResultToString(
    XrInstance                                  instance,
    XrResult                                    value,
    char                                        buffer[XR_MAX_RESULT_STRING_SIZE])
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrResultToString>::Dispatch(manager, instance, value, buffer);

    XrResult result = GetOpenXrInstanceTable(instance)->ResultToString(instance, value, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrResultToString);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeEnumValue(value);
        encoder->EncodeString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrResultToString>::Dispatch(manager, result, instance, value, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrStructureTypeToString(
    XrInstance                                  instance,
    XrStructureType                             value,
    char                                        buffer[XR_MAX_STRUCTURE_NAME_SIZE])
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStructureTypeToString>::Dispatch(manager, instance, value, buffer);

    XrResult result = GetOpenXrInstanceTable(instance)->StructureTypeToString(instance, value, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrStructureTypeToString);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeEnumValue(value);
        encoder->EncodeString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrStructureTypeToString>::Dispatch(manager, result, instance, value, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSystem(
    XrInstance                                  instance,
    const XrSystemGetInfo*                      getInfo,
    XrSystemId*                                 systemId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSystem>::Dispatch(manager, instance, getInfo, systemId);

    XrResult result = GetOpenXrInstanceTable(instance)->GetSystem(instance, getInfo, systemId);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSystem);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, getInfo);
        encoder->EncodeOpenXrAtomPtr<openxr_wrappers::SystemIdWrapper>(systemId, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSystem>::Dispatch(manager, result, instance, getInfo, systemId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSystemProperties(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrSystemProperties*                         properties)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSystemProperties>::Dispatch(manager, instance, systemId, properties);

    XrResult result = GetOpenXrInstanceTable(instance)->GetSystemProperties(instance, systemId, properties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSystemProperties);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        EncodeStructPtr(encoder, properties, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSystemProperties>::Dispatch(manager, result, instance, systemId, properties);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateEnvironmentBlendModes(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    environmentBlendModeCapacityInput,
    uint32_t*                                   environmentBlendModeCountOutput,
    XrEnvironmentBlendMode*                     environmentBlendModes)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateEnvironmentBlendModes>::Dispatch(manager, instance, systemId, viewConfigurationType, environmentBlendModeCapacityInput, environmentBlendModeCountOutput, environmentBlendModes);

    XrResult result = GetOpenXrInstanceTable(instance)->EnumerateEnvironmentBlendModes(instance, systemId, viewConfigurationType, environmentBlendModeCapacityInput, environmentBlendModeCountOutput, environmentBlendModes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateEnvironmentBlendModes);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        encoder->EncodeEnumValue(viewConfigurationType);
        encoder->EncodeUInt32Value(environmentBlendModeCapacityInput);
        encoder->EncodeUInt32Ptr(environmentBlendModeCountOutput, omit_output_data);
        encoder->EncodeEnumArray(environmentBlendModes, environmentBlendModeCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateEnvironmentBlendModes>::Dispatch(manager, result, instance, systemId, viewConfigurationType, environmentBlendModeCapacityInput, environmentBlendModeCountOutput, environmentBlendModes);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSession(
    XrInstance                                  instance,
    const XrSessionCreateInfo*                  createInfo,
    XrSession*                                  session)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSession>::Dispatch(manager, instance, createInfo, session);

    XrResult result = GetOpenXrInstanceTable(instance)->CreateSession(instance, createInfo, session);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::InstanceWrapper, OpenXrNoParentWrapper, openxr_wrappers::SessionWrapper>(instance, OpenXrNoParentWrapper::kHandleValue, session, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSession);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SessionWrapper>(session, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrInstance, openxr_wrappers::SessionWrapper, XrSessionCreateInfo>(result, instance, session, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSession>::Dispatch(manager, result, instance, createInfo, session);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySession(
    XrSession                                   session)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySession>::Dispatch(manager, session);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(session)->DestroySession(session);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySession);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SessionWrapper>(session);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySession>::Dispatch(manager, result, session);

    DestroyWrappedOpenXrHandle<openxr_wrappers::SessionWrapper>(session);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateReferenceSpaces(
    XrSession                                   session,
    uint32_t                                    spaceCapacityInput,
    uint32_t*                                   spaceCountOutput,
    XrReferenceSpaceType*                       spaces)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateReferenceSpaces>::Dispatch(manager, session, spaceCapacityInput, spaceCountOutput, spaces);

    XrResult result = GetOpenXrInstanceTable(session)->EnumerateReferenceSpaces(session, spaceCapacityInput, spaceCountOutput, spaces);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateReferenceSpaces);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt32Value(spaceCapacityInput);
        encoder->EncodeUInt32Ptr(spaceCountOutput, omit_output_data);
        encoder->EncodeEnumArray(spaces, spaceCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateReferenceSpaces>::Dispatch(manager, result, session, spaceCapacityInput, spaceCountOutput, spaces);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateReferenceSpace(
    XrSession                                   session,
    const XrReferenceSpaceCreateInfo*           createInfo,
    XrSpace*                                    space)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateReferenceSpace>::Dispatch(manager, session, createInfo, space);

    XrResult result = GetOpenXrInstanceTable(session)->CreateReferenceSpace(session, createInfo, space);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceWrapper>(session, OpenXrNoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateReferenceSpace);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(space, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceWrapper, XrReferenceSpaceCreateInfo>(result, session, space, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateReferenceSpace>::Dispatch(manager, result, session, createInfo, space);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetReferenceSpaceBoundsRect(
    XrSession                                   session,
    XrReferenceSpaceType                        referenceSpaceType,
    XrExtent2Df*                                bounds)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetReferenceSpaceBoundsRect>::Dispatch(manager, session, referenceSpaceType, bounds);

    XrResult result = GetOpenXrInstanceTable(session)->GetReferenceSpaceBoundsRect(session, referenceSpaceType, bounds);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetReferenceSpaceBoundsRect);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(referenceSpaceType);
        EncodeStructPtr(encoder, bounds, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetReferenceSpaceBoundsRect>::Dispatch(manager, result, session, referenceSpaceType, bounds);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateActionSpace(
    XrSession                                   session,
    const XrActionSpaceCreateInfo*              createInfo,
    XrSpace*                                    space)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateActionSpace>::Dispatch(manager, session, createInfo, space);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrActionSpaceCreateInfo* createInfo_unwrapped = UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->CreateActionSpace(session, createInfo_unwrapped, space);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceWrapper>(session, OpenXrNoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateActionSpace);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(space, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceWrapper, XrActionSpaceCreateInfo>(result, session, space, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateActionSpace>::Dispatch(manager, result, session, createInfo, space);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrLocateSpace(
    XrSpace                                     space,
    XrSpace                                     baseSpace,
    XrTime                                      time,
    XrSpaceLocation*                            location)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateSpace>::Dispatch(manager, space, baseSpace, time, location);

    XrResult result = GetOpenXrInstanceTable(space)->LocateSpace(space, baseSpace, time, location);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrLocateSpace);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(baseSpace);
        encoder->EncodeInt64Value(time);
        EncodeStructPtr(encoder, location, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrLocateSpace>::Dispatch(manager, result, space, baseSpace, time, location);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpace(
    XrSpace                                     space)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpace>::Dispatch(manager, space);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(space)->DestroySpace(space);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySpace);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SpaceWrapper>(space);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySpace>::Dispatch(manager, result, space);

    DestroyWrappedOpenXrHandle<openxr_wrappers::SpaceWrapper>(space);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateViewConfigurations(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    viewConfigurationTypeCapacityInput,
    uint32_t*                                   viewConfigurationTypeCountOutput,
    XrViewConfigurationType*                    viewConfigurationTypes)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateViewConfigurations>::Dispatch(manager, instance, systemId, viewConfigurationTypeCapacityInput, viewConfigurationTypeCountOutput, viewConfigurationTypes);

    XrResult result = GetOpenXrInstanceTable(instance)->EnumerateViewConfigurations(instance, systemId, viewConfigurationTypeCapacityInput, viewConfigurationTypeCountOutput, viewConfigurationTypes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateViewConfigurations);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        encoder->EncodeUInt32Value(viewConfigurationTypeCapacityInput);
        encoder->EncodeUInt32Ptr(viewConfigurationTypeCountOutput, omit_output_data);
        encoder->EncodeEnumArray(viewConfigurationTypes, viewConfigurationTypeCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateViewConfigurations>::Dispatch(manager, result, instance, systemId, viewConfigurationTypeCapacityInput, viewConfigurationTypeCountOutput, viewConfigurationTypes);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetViewConfigurationProperties(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    XrViewConfigurationProperties*              configurationProperties)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetViewConfigurationProperties>::Dispatch(manager, instance, systemId, viewConfigurationType, configurationProperties);

    XrResult result = GetOpenXrInstanceTable(instance)->GetViewConfigurationProperties(instance, systemId, viewConfigurationType, configurationProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetViewConfigurationProperties);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        encoder->EncodeEnumValue(viewConfigurationType);
        EncodeStructPtr(encoder, configurationProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetViewConfigurationProperties>::Dispatch(manager, result, instance, systemId, viewConfigurationType, configurationProperties);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateViewConfigurationViews(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewCapacityInput,
    uint32_t*                                   viewCountOutput,
    XrViewConfigurationView*                    views)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateViewConfigurationViews>::Dispatch(manager, instance, systemId, viewConfigurationType, viewCapacityInput, viewCountOutput, views);

    XrResult result = GetOpenXrInstanceTable(instance)->EnumerateViewConfigurationViews(instance, systemId, viewConfigurationType, viewCapacityInput, viewCountOutput, views);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateViewConfigurationViews);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        encoder->EncodeEnumValue(viewConfigurationType);
        encoder->EncodeUInt32Value(viewCapacityInput);
        encoder->EncodeUInt32Ptr(viewCountOutput, omit_output_data);
        EncodeStructArray(encoder, views, viewCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateViewConfigurationViews>::Dispatch(manager, result, instance, systemId, viewConfigurationType, viewCapacityInput, viewCountOutput, views);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSwapchainFormats(
    XrSession                                   session,
    uint32_t                                    formatCapacityInput,
    uint32_t*                                   formatCountOutput,
    int64_t*                                    formats)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSwapchainFormats>::Dispatch(manager, session, formatCapacityInput, formatCountOutput, formats);

    XrResult result = GetOpenXrInstanceTable(session)->EnumerateSwapchainFormats(session, formatCapacityInput, formatCountOutput, formats);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateSwapchainFormats);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt32Value(formatCapacityInput);
        encoder->EncodeUInt32Ptr(formatCountOutput, omit_output_data);
        encoder->EncodeInt64Array(formats, formatCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateSwapchainFormats>::Dispatch(manager, result, session, formatCapacityInput, formatCountOutput, formats);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSwapchain(
    XrSession                                   session,
    const XrSwapchainCreateInfo*                createInfo,
    XrSwapchain*                                swapchain)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSwapchain>::Dispatch(manager, session, createInfo, swapchain);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSwapchain(session, createInfo, swapchain);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SwapchainWrapper>(session, OpenXrNoParentWrapper::kHandleValue, swapchain, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSwapchain);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SwapchainWrapper>(swapchain, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SwapchainWrapper, XrSwapchainCreateInfo>(result, session, swapchain, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSwapchain>::Dispatch(manager, result, session, createInfo, swapchain);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySwapchain(
    XrSwapchain                                 swapchain)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySwapchain>::Dispatch(manager, swapchain);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(swapchain)->DestroySwapchain(swapchain);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySwapchain);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(swapchain);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SwapchainWrapper>(swapchain);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySwapchain>::Dispatch(manager, result, swapchain);

    DestroyWrappedOpenXrHandle<openxr_wrappers::SwapchainWrapper>(swapchain);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSwapchainImages(
    XrSwapchain                                 swapchain,
    uint32_t                                    imageCapacityInput,
    uint32_t*                                   imageCountOutput,
    XrSwapchainImageBaseHeader*                 images)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSwapchainImages>::Dispatch(manager, swapchain, imageCapacityInput, imageCountOutput, images);

    XrResult result = GetOpenXrInstanceTable(swapchain)->EnumerateSwapchainImages(swapchain, imageCapacityInput, imageCountOutput, images);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateSwapchainImages);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(swapchain);
        encoder->EncodeUInt32Value(imageCapacityInput);
        encoder->EncodeUInt32Ptr(imageCountOutput, omit_output_data);
        EncodeStructArray(encoder, images, imageCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateSwapchainImages>::Dispatch(manager, result, swapchain, imageCapacityInput, imageCountOutput, images);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrAcquireSwapchainImage(
    XrSwapchain                                 swapchain,
    const XrSwapchainImageAcquireInfo*          acquireInfo,
    uint32_t*                                   index)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrAcquireSwapchainImage>::Dispatch(manager, swapchain, acquireInfo, index);

    XrResult result = GetOpenXrInstanceTable(swapchain)->AcquireSwapchainImage(swapchain, acquireInfo, index);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrAcquireSwapchainImage);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(swapchain);
        EncodeStructPtr(encoder, acquireInfo);
        encoder->EncodeUInt32Ptr(index, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrAcquireSwapchainImage>::Dispatch(manager, result, swapchain, acquireInfo, index);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrWaitSwapchainImage(
    XrSwapchain                                 swapchain,
    const XrSwapchainImageWaitInfo*             waitInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrWaitSwapchainImage>::Dispatch(manager, swapchain, waitInfo);

    XrResult result = GetOpenXrInstanceTable(swapchain)->WaitSwapchainImage(swapchain, waitInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrWaitSwapchainImage);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(swapchain);
        EncodeStructPtr(encoder, waitInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrWaitSwapchainImage>::Dispatch(manager, result, swapchain, waitInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrReleaseSwapchainImage(
    XrSwapchain                                 swapchain,
    const XrSwapchainImageReleaseInfo*          releaseInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrReleaseSwapchainImage>::Dispatch(manager, swapchain, releaseInfo);

    XrResult result = GetOpenXrInstanceTable(swapchain)->ReleaseSwapchainImage(swapchain, releaseInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrReleaseSwapchainImage);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(swapchain);
        EncodeStructPtr(encoder, releaseInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrReleaseSwapchainImage>::Dispatch(manager, result, swapchain, releaseInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrBeginSession(
    XrSession                                   session,
    const XrSessionBeginInfo*                   beginInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrBeginSession>::Dispatch(manager, session, beginInfo);

    XrResult result = GetOpenXrInstanceTable(session)->BeginSession(session, beginInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrBeginSession);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, beginInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrBeginSession>::Dispatch(manager, result, session, beginInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEndSession(
    XrSession                                   session)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEndSession>::Dispatch(manager, session);

    XrResult result = GetOpenXrInstanceTable(session)->EndSession(session);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEndSession);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEndSession>::Dispatch(manager, result, session);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrRequestExitSession(
    XrSession                                   session)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestExitSession>::Dispatch(manager, session);

    XrResult result = GetOpenXrInstanceTable(session)->RequestExitSession(session);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrRequestExitSession);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrRequestExitSession>::Dispatch(manager, result, session);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrWaitFrame(
    XrSession                                   session,
    const XrFrameWaitInfo*                      frameWaitInfo,
    XrFrameState*                               frameState)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrWaitFrame>::Dispatch(manager, session, frameWaitInfo, frameState);

    XrResult result = GetOpenXrInstanceTable(session)->WaitFrame(session, frameWaitInfo, frameState);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrWaitFrame);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, frameWaitInfo);
        EncodeStructPtr(encoder, frameState, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrWaitFrame>::Dispatch(manager, result, session, frameWaitInfo, frameState);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrBeginFrame(
    XrSession                                   session,
    const XrFrameBeginInfo*                     frameBeginInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrBeginFrame>::Dispatch(manager, session, frameBeginInfo);

    XrResult result = GetOpenXrInstanceTable(session)->BeginFrame(session, frameBeginInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrBeginFrame);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, frameBeginInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrBeginFrame>::Dispatch(manager, result, session, frameBeginInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEndFrame(
    XrSession                                   session,
    const XrFrameEndInfo*                       frameEndInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEndFrame>::Dispatch(manager, session, frameEndInfo);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrFrameEndInfo* frameEndInfo_unwrapped = UnwrapStructPtrHandles(frameEndInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->EndFrame(session, frameEndInfo_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEndFrame);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, frameEndInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEndFrame>::Dispatch(manager, result, session, frameEndInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrLocateViews(
    XrSession                                   session,
    const XrViewLocateInfo*                     viewLocateInfo,
    XrViewState*                                viewState,
    uint32_t                                    viewCapacityInput,
    uint32_t*                                   viewCountOutput,
    XrView*                                     views)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateViews>::Dispatch(manager, session, viewLocateInfo, viewState, viewCapacityInput, viewCountOutput, views);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrViewLocateInfo* viewLocateInfo_unwrapped = UnwrapStructPtrHandles(viewLocateInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->LocateViews(session, viewLocateInfo_unwrapped, viewState, viewCapacityInput, viewCountOutput, views);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrLocateViews);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, viewLocateInfo);
        EncodeStructPtr(encoder, viewState, omit_output_data);
        encoder->EncodeUInt32Value(viewCapacityInput);
        encoder->EncodeUInt32Ptr(viewCountOutput, omit_output_data);
        EncodeStructArray(encoder, views, viewCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrLocateViews>::Dispatch(manager, result, session, viewLocateInfo, viewState, viewCapacityInput, viewCountOutput, views);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrStringToPath(
    XrInstance                                  instance,
    const char*                                 pathString,
    XrPath*                                     path)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStringToPath>::Dispatch(manager, instance, pathString, path);

    XrResult result = GetOpenXrInstanceTable(instance)->StringToPath(instance, pathString, path);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrStringToPath);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeString(pathString);
        encoder->EncodeOpenXrAtomPtr<openxr_wrappers::PathWrapper>(path, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrStringToPath>::Dispatch(manager, result, instance, pathString, path);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrPathToString(
    XrInstance                                  instance,
    XrPath                                      path,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPathToString>::Dispatch(manager, instance, path, bufferCapacityInput, bufferCountOutput, buffer);

    XrResult result = GetOpenXrInstanceTable(instance)->PathToString(instance, path, bufferCapacityInput, bufferCountOutput, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPathToString);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(path);
        encoder->EncodeUInt32Value(bufferCapacityInput);
        encoder->EncodeUInt32Ptr(bufferCountOutput, omit_output_data);
        encoder->EncodeString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPathToString>::Dispatch(manager, result, instance, path, bufferCapacityInput, bufferCountOutput, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateActionSet(
    XrInstance                                  instance,
    const XrActionSetCreateInfo*                createInfo,
    XrActionSet*                                actionSet)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateActionSet>::Dispatch(manager, instance, createInfo, actionSet);

    XrResult result = GetOpenXrInstanceTable(instance)->CreateActionSet(instance, createInfo, actionSet);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::InstanceWrapper, OpenXrNoParentWrapper, openxr_wrappers::ActionSetWrapper>(instance, OpenXrNoParentWrapper::kHandleValue, actionSet, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateActionSet);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::ActionSetWrapper>(actionSet, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrInstance, openxr_wrappers::ActionSetWrapper, XrActionSetCreateInfo>(result, instance, actionSet, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateActionSet>::Dispatch(manager, result, instance, createInfo, actionSet);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyActionSet(
    XrActionSet                                 actionSet)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyActionSet>::Dispatch(manager, actionSet);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(actionSet)->DestroyActionSet(actionSet);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyActionSet);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionSetWrapper>(actionSet);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::ActionSetWrapper>(actionSet);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyActionSet>::Dispatch(manager, result, actionSet);

    DestroyWrappedOpenXrHandle<openxr_wrappers::ActionSetWrapper>(actionSet);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateAction(
    XrActionSet                                 actionSet,
    const XrActionCreateInfo*                   createInfo,
    XrAction*                                   action)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateAction>::Dispatch(manager, actionSet, createInfo, action);

    XrResult result = GetOpenXrInstanceTable(actionSet)->CreateAction(actionSet, createInfo, action);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::ActionSetWrapper, OpenXrNoParentWrapper, openxr_wrappers::ActionWrapper>(actionSet, OpenXrNoParentWrapper::kHandleValue, action, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateAction);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionSetWrapper>(actionSet);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::ActionWrapper>(action, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrActionSet, openxr_wrappers::ActionWrapper, XrActionCreateInfo>(result, actionSet, action, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateAction>::Dispatch(manager, result, actionSet, createInfo, action);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyAction(
    XrAction                                    action)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyAction>::Dispatch(manager, action);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(action)->DestroyAction(action);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyAction);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(action);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::ActionWrapper>(action);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyAction>::Dispatch(manager, result, action);

    DestroyWrappedOpenXrHandle<openxr_wrappers::ActionWrapper>(action);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSuggestInteractionProfileBindings(
    XrInstance                                  instance,
    const XrInteractionProfileSuggestedBinding* suggestedBindings)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSuggestInteractionProfileBindings>::Dispatch(manager, instance, suggestedBindings);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrInteractionProfileSuggestedBinding* suggestedBindings_unwrapped = UnwrapStructPtrHandles(suggestedBindings, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(instance)->SuggestInteractionProfileBindings(instance, suggestedBindings_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSuggestInteractionProfileBindings);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, suggestedBindings);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSuggestInteractionProfileBindings>::Dispatch(manager, result, instance, suggestedBindings);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrAttachSessionActionSets(
    XrSession                                   session,
    const XrSessionActionSetsAttachInfo*        attachInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrAttachSessionActionSets>::Dispatch(manager, session, attachInfo);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSessionActionSetsAttachInfo* attachInfo_unwrapped = UnwrapStructPtrHandles(attachInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->AttachSessionActionSets(session, attachInfo_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrAttachSessionActionSets);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, attachInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrAttachSessionActionSets>::Dispatch(manager, result, session, attachInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetCurrentInteractionProfile(
    XrSession                                   session,
    XrPath                                      topLevelUserPath,
    XrInteractionProfileState*                  interactionProfile)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetCurrentInteractionProfile>::Dispatch(manager, session, topLevelUserPath, interactionProfile);

    XrResult result = GetOpenXrInstanceTable(session)->GetCurrentInteractionProfile(session, topLevelUserPath, interactionProfile);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetCurrentInteractionProfile);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(topLevelUserPath);
        EncodeStructPtr(encoder, interactionProfile, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetCurrentInteractionProfile>::Dispatch(manager, result, session, topLevelUserPath, interactionProfile);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStateBoolean(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStateBoolean*                       state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStateBoolean>::Dispatch(manager, session, getInfo, state);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrActionStateGetInfo* getInfo_unwrapped = UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->GetActionStateBoolean(session, getInfo_unwrapped, state);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetActionStateBoolean);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, getInfo);
        EncodeStructPtr(encoder, state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetActionStateBoolean>::Dispatch(manager, result, session, getInfo, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStateFloat(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStateFloat*                         state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStateFloat>::Dispatch(manager, session, getInfo, state);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrActionStateGetInfo* getInfo_unwrapped = UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->GetActionStateFloat(session, getInfo_unwrapped, state);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetActionStateFloat);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, getInfo);
        EncodeStructPtr(encoder, state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetActionStateFloat>::Dispatch(manager, result, session, getInfo, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStateVector2f(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStateVector2f*                      state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStateVector2f>::Dispatch(manager, session, getInfo, state);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrActionStateGetInfo* getInfo_unwrapped = UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->GetActionStateVector2f(session, getInfo_unwrapped, state);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetActionStateVector2f);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, getInfo);
        EncodeStructPtr(encoder, state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetActionStateVector2f>::Dispatch(manager, result, session, getInfo, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStatePose(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStatePose*                          state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStatePose>::Dispatch(manager, session, getInfo, state);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrActionStateGetInfo* getInfo_unwrapped = UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->GetActionStatePose(session, getInfo_unwrapped, state);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetActionStatePose);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, getInfo);
        EncodeStructPtr(encoder, state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetActionStatePose>::Dispatch(manager, result, session, getInfo, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSyncActions(
    XrSession                                   session,
    const XrActionsSyncInfo*                    syncInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSyncActions>::Dispatch(manager, session, syncInfo);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrActionsSyncInfo* syncInfo_unwrapped = UnwrapStructPtrHandles(syncInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->SyncActions(session, syncInfo_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSyncActions);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, syncInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSyncActions>::Dispatch(manager, result, session, syncInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateBoundSourcesForAction(
    XrSession                                   session,
    const XrBoundSourcesForActionEnumerateInfo* enumerateInfo,
    uint32_t                                    sourceCapacityInput,
    uint32_t*                                   sourceCountOutput,
    XrPath*                                     sources)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateBoundSourcesForAction>::Dispatch(manager, session, enumerateInfo, sourceCapacityInput, sourceCountOutput, sources);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrBoundSourcesForActionEnumerateInfo* enumerateInfo_unwrapped = UnwrapStructPtrHandles(enumerateInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->EnumerateBoundSourcesForAction(session, enumerateInfo_unwrapped, sourceCapacityInput, sourceCountOutput, sources);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateBoundSourcesForAction);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, enumerateInfo);
        encoder->EncodeUInt32Value(sourceCapacityInput);
        encoder->EncodeUInt32Ptr(sourceCountOutput, omit_output_data);
        encoder->EncodeOpenXrAtomArray<openxr_wrappers::PathWrapper>(sources, sourceCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateBoundSourcesForAction>::Dispatch(manager, result, session, enumerateInfo, sourceCapacityInput, sourceCountOutput, sources);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetInputSourceLocalizedName(
    XrSession                                   session,
    const XrInputSourceLocalizedNameGetInfo*    getInfo,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetInputSourceLocalizedName>::Dispatch(manager, session, getInfo, bufferCapacityInput, bufferCountOutput, buffer);

    XrResult result = GetOpenXrInstanceTable(session)->GetInputSourceLocalizedName(session, getInfo, bufferCapacityInput, bufferCountOutput, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetInputSourceLocalizedName);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, getInfo);
        encoder->EncodeUInt32Value(bufferCapacityInput);
        encoder->EncodeUInt32Ptr(bufferCountOutput, omit_output_data);
        encoder->EncodeString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetInputSourceLocalizedName>::Dispatch(manager, result, session, getInfo, bufferCapacityInput, bufferCountOutput, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrApplyHapticFeedback(
    XrSession                                   session,
    const XrHapticActionInfo*                   hapticActionInfo,
    const XrHapticBaseHeader*                   hapticFeedback)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrApplyHapticFeedback>::Dispatch(manager, session, hapticActionInfo, hapticFeedback);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrHapticActionInfo* hapticActionInfo_unwrapped = UnwrapStructPtrHandles(hapticActionInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->ApplyHapticFeedback(session, hapticActionInfo_unwrapped, hapticFeedback);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrApplyHapticFeedback);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, hapticActionInfo);
        EncodeStructPtr(encoder, hapticFeedback);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrApplyHapticFeedback>::Dispatch(manager, result, session, hapticActionInfo, hapticFeedback);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrStopHapticFeedback(
    XrSession                                   session,
    const XrHapticActionInfo*                   hapticActionInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStopHapticFeedback>::Dispatch(manager, session, hapticActionInfo);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrHapticActionInfo* hapticActionInfo_unwrapped = UnwrapStructPtrHandles(hapticActionInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->StopHapticFeedback(session, hapticActionInfo_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrStopHapticFeedback);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, hapticActionInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrStopHapticFeedback>::Dispatch(manager, result, session, hapticActionInfo);

    return result;
}


XRAPI_ATTR XrResult XRAPI_CALL xrSetAndroidApplicationThreadKHR(
    XrSession                                   session,
    XrAndroidThreadTypeKHR                      threadType,
    uint32_t                                    threadId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetAndroidApplicationThreadKHR>::Dispatch(manager, session, threadType, threadId);

    XrResult result = GetOpenXrInstanceTable(session)->SetAndroidApplicationThreadKHR(session, threadType, threadId);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetAndroidApplicationThreadKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(threadType);
        encoder->EncodeUInt32Value(threadId);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetAndroidApplicationThreadKHR>::Dispatch(manager, result, session, threadType, threadId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSwapchainAndroidSurfaceKHR(
    XrSession                                   session,
    const XrSwapchainCreateInfo*                info,
    XrSwapchain*                                swapchain,
    jobject*                                    surface)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR>::Dispatch(manager, session, info, swapchain, surface);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSwapchainAndroidSurfaceKHR(session, info, swapchain, surface);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SwapchainWrapper>(session, OpenXrNoParentWrapper::kHandleValue, swapchain, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SwapchainWrapper>(swapchain, omit_output_data);
        encoder->EncodeVoidPtr(surface);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SwapchainWrapper, XrSwapchainCreateInfo>(result, session, swapchain, info);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR>::Dispatch(manager, result, session, info, swapchain, surface);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetOpenGLGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsOpenGLKHR*            graphicsRequirements)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetOpenGLGraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);

    XrResult result = GetOpenXrInstanceTable(instance)->GetOpenGLGraphicsRequirementsKHR(instance, systemId, graphicsRequirements);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetOpenGLGraphicsRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        EncodeStructPtr(encoder, graphicsRequirements, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetOpenGLGraphicsRequirementsKHR>::Dispatch(manager, result, instance, systemId, graphicsRequirements);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetOpenGLESGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsOpenGLESKHR*          graphicsRequirements)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetOpenGLESGraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);

    XrResult result = GetOpenXrInstanceTable(instance)->GetOpenGLESGraphicsRequirementsKHR(instance, systemId, graphicsRequirements);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetOpenGLESGraphicsRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        EncodeStructPtr(encoder, graphicsRequirements, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetOpenGLESGraphicsRequirementsKHR>::Dispatch(manager, result, instance, systemId, graphicsRequirements);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanInstanceExtensionsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanInstanceExtensionsKHR>::Dispatch(manager, instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);

    XrResult result = GetOpenXrInstanceTable(instance)->GetVulkanInstanceExtensionsKHR(instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVulkanInstanceExtensionsKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        encoder->EncodeUInt32Value(bufferCapacityInput);
        encoder->EncodeUInt32Ptr(bufferCountOutput, omit_output_data);
        encoder->EncodeString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVulkanInstanceExtensionsKHR>::Dispatch(manager, result, instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanDeviceExtensionsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanDeviceExtensionsKHR>::Dispatch(manager, instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);

    XrResult result = GetOpenXrInstanceTable(instance)->GetVulkanDeviceExtensionsKHR(instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVulkanDeviceExtensionsKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        encoder->EncodeUInt32Value(bufferCapacityInput);
        encoder->EncodeUInt32Ptr(bufferCountOutput, omit_output_data);
        encoder->EncodeString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVulkanDeviceExtensionsKHR>::Dispatch(manager, result, instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsDeviceKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    VkInstance                                  vkInstance,
    VkPhysicalDevice*                           vkPhysicalDevice)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDeviceKHR>::Dispatch(manager, instance, systemId, vkInstance, vkPhysicalDevice);

    XrResult result = GetOpenXrInstanceTable(instance)->GetVulkanGraphicsDeviceKHR(instance, systemId, vkInstance, vkPhysicalDevice);

    if (result >= 0)
    {
        CreateWrappedVulkanHandle<openxr_wrappers::InstanceWrapper, OpenXrNoParentWrapper, vulkan_wrappers::PhysicalDeviceWrapper>(instance, OpenXrNoParentWrapper::kHandleValue, vkPhysicalDevice, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVulkanGraphicsDeviceKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::InstanceWrapper>(vkInstance);
        encoder->EncodeVulkanHandlePtr<vulkan_wrappers::PhysicalDeviceWrapper>(vkPhysicalDevice, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDeviceKHR>::Dispatch(manager, result, instance, systemId, vkInstance, vkPhysicalDevice);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsVulkanKHR*            graphicsRequirements)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);

    XrResult result = GetOpenXrInstanceTable(instance)->GetVulkanGraphicsRequirementsKHR(instance, systemId, graphicsRequirements);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        EncodeStructPtr(encoder, graphicsRequirements, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirementsKHR>::Dispatch(manager, result, instance, systemId, graphicsRequirements);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetD3D11GraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsD3D11KHR*             graphicsRequirements)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetD3D11GraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);

    XrResult result = GetOpenXrInstanceTable(instance)->GetD3D11GraphicsRequirementsKHR(instance, systemId, graphicsRequirements);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetD3D11GraphicsRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        EncodeStructPtr(encoder, graphicsRequirements, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetD3D11GraphicsRequirementsKHR>::Dispatch(manager, result, instance, systemId, graphicsRequirements);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetD3D12GraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsD3D12KHR*             graphicsRequirements)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetD3D12GraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);

    XrResult result = GetOpenXrInstanceTable(instance)->GetD3D12GraphicsRequirementsKHR(instance, systemId, graphicsRequirements);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetD3D12GraphicsRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        EncodeStructPtr(encoder, graphicsRequirements, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetD3D12GraphicsRequirementsKHR>::Dispatch(manager, result, instance, systemId, graphicsRequirements);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVisibilityMaskKHR(
    XrSession                                   session,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewIndex,
    XrVisibilityMaskTypeKHR                     visibilityMaskType,
    XrVisibilityMaskKHR*                        visibilityMask)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVisibilityMaskKHR>::Dispatch(manager, session, viewConfigurationType, viewIndex, visibilityMaskType, visibilityMask);

    XrResult result = GetOpenXrInstanceTable(session)->GetVisibilityMaskKHR(session, viewConfigurationType, viewIndex, visibilityMaskType, visibilityMask);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVisibilityMaskKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(viewConfigurationType);
        encoder->EncodeUInt32Value(viewIndex);
        encoder->EncodeEnumValue(visibilityMaskType);
        EncodeStructPtr(encoder, visibilityMask, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVisibilityMaskKHR>::Dispatch(manager, result, session, viewConfigurationType, viewIndex, visibilityMaskType, visibilityMask);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrConvertWin32PerformanceCounterToTimeKHR(
    XrInstance                                  instance,
    const LARGE_INTEGER*                        performanceCounter,
    XrTime*                                     time)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR>::Dispatch(manager, instance, performanceCounter, time);

    XrResult result = GetOpenXrInstanceTable(instance)->ConvertWin32PerformanceCounterToTimeKHR(instance, performanceCounter, time);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeInt64Ptr(performanceCounter);
        encoder->EncodeInt64Ptr(time, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR>::Dispatch(manager, result, instance, performanceCounter, time);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrConvertTimeToWin32PerformanceCounterKHR(
    XrInstance                                  instance,
    XrTime                                      time,
    LARGE_INTEGER*                              performanceCounter)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR>::Dispatch(manager, instance, time, performanceCounter);

    XrResult result = GetOpenXrInstanceTable(instance)->ConvertTimeToWin32PerformanceCounterKHR(instance, time, performanceCounter);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeInt64Value(time);
        encoder->EncodeInt64Ptr(performanceCounter, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR>::Dispatch(manager, result, instance, time, performanceCounter);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrConvertTimespecTimeToTimeKHR(
    XrInstance                                  instance,
    const struct timespec*                      timespecTime,
    XrTime*                                     time)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertTimespecTimeToTimeKHR>::Dispatch(manager, instance, timespecTime, time);

    XrResult result = GetOpenXrInstanceTable(instance)->ConvertTimespecTimeToTimeKHR(instance, timespecTime, time);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrConvertTimespecTimeToTimeKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, timespecTime);
        encoder->EncodeInt64Ptr(time, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrConvertTimespecTimeToTimeKHR>::Dispatch(manager, result, instance, timespecTime, time);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrConvertTimeToTimespecTimeKHR(
    XrInstance                                  instance,
    XrTime                                      time,
    struct timespec*                            timespecTime)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR>::Dispatch(manager, instance, time, timespecTime);

    XrResult result = GetOpenXrInstanceTable(instance)->ConvertTimeToTimespecTimeKHR(instance, time, timespecTime);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeInt64Value(time);
        EncodeStructPtr(encoder, timespecTime, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR>::Dispatch(manager, result, instance, time, timespecTime);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrInitializeLoaderKHR(
    const XrLoaderInitInfoBaseHeaderKHR*        loaderInitInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrInitializeLoaderKHR>::Dispatch(manager, loaderInitInfo);

    XrResult result = OpenXrCaptureManager::OverrideInitializeLoaderKHR(loaderInitInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrInitializeLoaderKHR);
    if (encoder)
    {
        EncodeStructPtr(encoder, loaderInitInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrInitializeLoaderKHR>::Dispatch(manager, result, loaderInitInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateVulkanInstanceKHR(
    XrInstance                                  instance,
    const XrVulkanInstanceCreateInfoKHR*        createInfo,
    VkInstance*                                 vulkanInstance,
    VkResult*                                   vulkanResult)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVulkanInstanceKHR>::Dispatch(manager, instance, createInfo, vulkanInstance, vulkanResult);

    XrResult result = GetOpenXrInstanceTable(instance)->CreateVulkanInstanceKHR(instance, createInfo, vulkanInstance, vulkanResult);

    if (result >= 0)
    {
        CreateWrappedVulkanHandle<openxr_wrappers::InstanceWrapper, OpenXrNoParentWrapper, vulkan_wrappers::InstanceWrapper>(instance, OpenXrNoParentWrapper::kHandleValue, vulkanInstance, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateVulkanInstanceKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeVulkanHandlePtr<vulkan_wrappers::InstanceWrapper>(vulkanInstance, omit_output_data);
        encoder->EncodeEnumPtr(vulkanResult, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrInstance, vulkan_wrappers::InstanceWrapper, XrVulkanInstanceCreateInfoKHR>(result, instance, vulkanInstance, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateVulkanInstanceKHR>::Dispatch(manager, result, instance, createInfo, vulkanInstance, vulkanResult);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateVulkanDeviceKHR(
    XrInstance                                  instance,
    const XrVulkanDeviceCreateInfoKHR*          createInfo,
    VkDevice*                                   vulkanDevice,
    VkResult*                                   vulkanResult)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVulkanDeviceKHR>::Dispatch(manager, instance, createInfo, vulkanDevice, vulkanResult);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrVulkanDeviceCreateInfoKHR* createInfo_unwrapped = UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(instance)->CreateVulkanDeviceKHR(instance, createInfo_unwrapped, vulkanDevice, vulkanResult);

    if (result >= 0)
    {
        CreateWrappedVulkanHandle<openxr_wrappers::InstanceWrapper, OpenXrNoParentWrapper, vulkan_wrappers::DeviceWrapper>(instance, OpenXrNoParentWrapper::kHandleValue, vulkanDevice, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateVulkanDeviceKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeVulkanHandlePtr<vulkan_wrappers::DeviceWrapper>(vulkanDevice, omit_output_data);
        encoder->EncodeEnumPtr(vulkanResult, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrInstance, vulkan_wrappers::DeviceWrapper, XrVulkanDeviceCreateInfoKHR>(result, instance, vulkanDevice, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateVulkanDeviceKHR>::Dispatch(manager, result, instance, createInfo, vulkanDevice, vulkanResult);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsDevice2KHR(
    XrInstance                                  instance,
    const XrVulkanGraphicsDeviceGetInfoKHR*     getInfo,
    VkPhysicalDevice*                           vulkanPhysicalDevice)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDevice2KHR>::Dispatch(manager, instance, getInfo, vulkanPhysicalDevice);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrVulkanGraphicsDeviceGetInfoKHR* getInfo_unwrapped = UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(instance)->GetVulkanGraphicsDevice2KHR(instance, getInfo_unwrapped, vulkanPhysicalDevice);

    if (result >= 0)
    {
        CreateWrappedVulkanHandle<openxr_wrappers::InstanceWrapper, OpenXrNoParentWrapper, vulkan_wrappers::PhysicalDeviceWrapper>(instance, OpenXrNoParentWrapper::kHandleValue, vulkanPhysicalDevice, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVulkanGraphicsDevice2KHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, getInfo);
        encoder->EncodeVulkanHandlePtr<vulkan_wrappers::PhysicalDeviceWrapper>(vulkanPhysicalDevice, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDevice2KHR>::Dispatch(manager, result, instance, getInfo, vulkanPhysicalDevice);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsRequirements2KHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsVulkanKHR*            graphicsRequirements)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirements2KHR>::Dispatch(manager, instance, systemId, graphicsRequirements);

    XrResult result = GetOpenXrInstanceTable(instance)->GetVulkanGraphicsRequirements2KHR(instance, systemId, graphicsRequirements);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        EncodeStructPtr(encoder, graphicsRequirements, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirements2KHR>::Dispatch(manager, result, instance, systemId, graphicsRequirements);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrPerfSettingsSetPerformanceLevelEXT(
    XrSession                                   session,
    XrPerfSettingsDomainEXT                     domain,
    XrPerfSettingsLevelEXT                      level)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPerfSettingsSetPerformanceLevelEXT>::Dispatch(manager, session, domain, level);

    XrResult result = GetOpenXrInstanceTable(session)->PerfSettingsSetPerformanceLevelEXT(session, domain, level);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPerfSettingsSetPerformanceLevelEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(domain);
        encoder->EncodeEnumValue(level);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPerfSettingsSetPerformanceLevelEXT>::Dispatch(manager, result, session, domain, level);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrThermalGetTemperatureTrendEXT(
    XrSession                                   session,
    XrPerfSettingsDomainEXT                     domain,
    XrPerfSettingsNotificationLevelEXT*         notificationLevel,
    float*                                      tempHeadroom,
    float*                                      tempSlope)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrThermalGetTemperatureTrendEXT>::Dispatch(manager, session, domain, notificationLevel, tempHeadroom, tempSlope);

    XrResult result = GetOpenXrInstanceTable(session)->ThermalGetTemperatureTrendEXT(session, domain, notificationLevel, tempHeadroom, tempSlope);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrThermalGetTemperatureTrendEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(domain);
        encoder->EncodeEnumPtr(notificationLevel, omit_output_data);
        encoder->EncodeFloatPtr(tempHeadroom, omit_output_data);
        encoder->EncodeFloatPtr(tempSlope, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrThermalGetTemperatureTrendEXT>::Dispatch(manager, result, session, domain, notificationLevel, tempHeadroom, tempSlope);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetDebugUtilsObjectNameEXT(
    XrInstance                                  instance,
    const XrDebugUtilsObjectNameInfoEXT*        nameInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetDebugUtilsObjectNameEXT>::Dispatch(manager, instance, nameInfo);

    XrResult result = GetOpenXrInstanceTable(instance)->SetDebugUtilsObjectNameEXT(instance, nameInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetDebugUtilsObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, nameInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetDebugUtilsObjectNameEXT>::Dispatch(manager, result, instance, nameInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateDebugUtilsMessengerEXT(
    XrInstance                                  instance,
    const XrDebugUtilsMessengerCreateInfoEXT*   createInfo,
    XrDebugUtilsMessengerEXT*                   messenger)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateDebugUtilsMessengerEXT>::Dispatch(manager, instance, createInfo, messenger);

    XrResult result = GetOpenXrInstanceTable(instance)->CreateDebugUtilsMessengerEXT(instance, createInfo, messenger);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::InstanceWrapper, OpenXrNoParentWrapper, openxr_wrappers::DebugUtilsMessengerEXTWrapper>(instance, OpenXrNoParentWrapper::kHandleValue, messenger, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(messenger, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrInstance, openxr_wrappers::DebugUtilsMessengerEXTWrapper, XrDebugUtilsMessengerCreateInfoEXT>(result, instance, messenger, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateDebugUtilsMessengerEXT>::Dispatch(manager, result, instance, createInfo, messenger);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyDebugUtilsMessengerEXT(
    XrDebugUtilsMessengerEXT                    messenger)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyDebugUtilsMessengerEXT>::Dispatch(manager, messenger);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(messenger)->DestroyDebugUtilsMessengerEXT(messenger);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(messenger);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(messenger);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyDebugUtilsMessengerEXT>::Dispatch(manager, result, messenger);

    DestroyWrappedOpenXrHandle<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(messenger);

    return result;
}

XRAPI_ATTR XrResult                                    XRAPI_CALL xrSubmitDebugUtilsMessageEXT(
    XrInstance                                  instance,
    XrDebugUtilsMessageSeverityFlagsEXT         messageSeverity,
    XrDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const XrDebugUtilsMessengerCallbackDataEXT* callbackData)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSubmitDebugUtilsMessageEXT>::Dispatch(manager, instance, messageSeverity, messageTypes, callbackData);

    XrResult result = GetOpenXrInstanceTable(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, callbackData);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSubmitDebugUtilsMessageEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeFlags64Value(messageSeverity);
        encoder->EncodeFlags64Value(messageTypes);
        EncodeStructPtr(encoder, callbackData);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSubmitDebugUtilsMessageEXT>::Dispatch(manager, result, instance, messageSeverity, messageTypes, callbackData);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSessionBeginDebugUtilsLabelRegionEXT(
    XrSession                                   session,
    const XrDebugUtilsLabelEXT*                 labelInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSessionBeginDebugUtilsLabelRegionEXT>::Dispatch(manager, session, labelInfo);

    XrResult result = GetOpenXrInstanceTable(session)->SessionBeginDebugUtilsLabelRegionEXT(session, labelInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSessionBeginDebugUtilsLabelRegionEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, labelInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSessionBeginDebugUtilsLabelRegionEXT>::Dispatch(manager, result, session, labelInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSessionEndDebugUtilsLabelRegionEXT(
    XrSession                                   session)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSessionEndDebugUtilsLabelRegionEXT>::Dispatch(manager, session);

    XrResult result = GetOpenXrInstanceTable(session)->SessionEndDebugUtilsLabelRegionEXT(session);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSessionEndDebugUtilsLabelRegionEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSessionEndDebugUtilsLabelRegionEXT>::Dispatch(manager, result, session);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSessionInsertDebugUtilsLabelEXT(
    XrSession                                   session,
    const XrDebugUtilsLabelEXT*                 labelInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSessionInsertDebugUtilsLabelEXT>::Dispatch(manager, session, labelInfo);

    XrResult result = GetOpenXrInstanceTable(session)->SessionInsertDebugUtilsLabelEXT(session, labelInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSessionInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, labelInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSessionInsertDebugUtilsLabelEXT>::Dispatch(manager, result, session, labelInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorMSFT(
    XrSession                                   session,
    const XrSpatialAnchorCreateInfoMSFT*        createInfo,
    XrSpatialAnchorMSFT*                        anchor)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorMSFT>::Dispatch(manager, session, createInfo, anchor);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpatialAnchorCreateInfoMSFT* createInfo_unwrapped = UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSpatialAnchorMSFT(session, createInfo_unwrapped, anchor);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpatialAnchorMSFTWrapper>(session, OpenXrNoParentWrapper::kHandleValue, anchor, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpatialAnchorMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpatialAnchorMSFTWrapper>(anchor, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpatialAnchorMSFTWrapper, XrSpatialAnchorCreateInfoMSFT>(result, session, anchor, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorMSFT>::Dispatch(manager, result, session, createInfo, anchor);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorSpaceMSFT(
    XrSession                                   session,
    const XrSpatialAnchorSpaceCreateInfoMSFT*   createInfo,
    XrSpace*                                    space)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorSpaceMSFT>::Dispatch(manager, session, createInfo, space);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpatialAnchorSpaceCreateInfoMSFT* createInfo_unwrapped = UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSpatialAnchorSpaceMSFT(session, createInfo_unwrapped, space);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceWrapper>(session, OpenXrNoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpatialAnchorSpaceMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(space, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceWrapper, XrSpatialAnchorSpaceCreateInfoMSFT>(result, session, space, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorSpaceMSFT>::Dispatch(manager, result, session, createInfo, space);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpatialAnchorMSFT(
    XrSpatialAnchorMSFT                         anchor)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpatialAnchorMSFT>::Dispatch(manager, anchor);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(anchor)->DestroySpatialAnchorMSFT(anchor);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySpatialAnchorMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorMSFTWrapper>(anchor);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SpatialAnchorMSFTWrapper>(anchor);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySpatialAnchorMSFT>::Dispatch(manager, result, anchor);

    DestroyWrappedOpenXrHandle<openxr_wrappers::SpatialAnchorMSFTWrapper>(anchor);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceActiveEXT(
    XrSession                                   session,
    XrPath                                      interactionProfile,
    XrPath                                      topLevelPath,
    XrBool32                                    isActive)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceActiveEXT>::Dispatch(manager, session, interactionProfile, topLevelPath, isActive);

    XrResult result = GetOpenXrInstanceTable(session)->SetInputDeviceActiveEXT(session, interactionProfile, topLevelPath, isActive);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetInputDeviceActiveEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(interactionProfile);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(topLevelPath);
        encoder->EncodeUInt32Value(isActive);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetInputDeviceActiveEXT>::Dispatch(manager, result, session, interactionProfile, topLevelPath, isActive);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceStateBoolEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    XrBool32                                    state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateBoolEXT>::Dispatch(manager, session, topLevelPath, inputSourcePath, state);

    XrResult result = GetOpenXrInstanceTable(session)->SetInputDeviceStateBoolEXT(session, topLevelPath, inputSourcePath, state);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetInputDeviceStateBoolEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(topLevelPath);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(inputSourcePath);
        encoder->EncodeUInt32Value(state);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateBoolEXT>::Dispatch(manager, result, session, topLevelPath, inputSourcePath, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceStateFloatEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    float                                       state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateFloatEXT>::Dispatch(manager, session, topLevelPath, inputSourcePath, state);

    XrResult result = GetOpenXrInstanceTable(session)->SetInputDeviceStateFloatEXT(session, topLevelPath, inputSourcePath, state);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetInputDeviceStateFloatEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(topLevelPath);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(inputSourcePath);
        encoder->EncodeFloatValue(state);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateFloatEXT>::Dispatch(manager, result, session, topLevelPath, inputSourcePath, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceStateVector2fEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    XrVector2f                                  state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateVector2fEXT>::Dispatch(manager, session, topLevelPath, inputSourcePath, state);

    XrResult result = GetOpenXrInstanceTable(session)->SetInputDeviceStateVector2fEXT(session, topLevelPath, inputSourcePath, state);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetInputDeviceStateVector2fEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(topLevelPath);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(inputSourcePath);
        EncodeStruct(encoder, state);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateVector2fEXT>::Dispatch(manager, result, session, topLevelPath, inputSourcePath, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceLocationEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    XrSpace                                     space,
    XrPosef                                     pose)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceLocationEXT>::Dispatch(manager, session, topLevelPath, inputSourcePath, space, pose);

    XrResult result = GetOpenXrInstanceTable(session)->SetInputDeviceLocationEXT(session, topLevelPath, inputSourcePath, space, pose);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetInputDeviceLocationEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(topLevelPath);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(inputSourcePath);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        EncodeStruct(encoder, pose);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetInputDeviceLocationEXT>::Dispatch(manager, result, session, topLevelPath, inputSourcePath, space, pose);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialGraphNodeSpaceMSFT(
    XrSession                                   session,
    const XrSpatialGraphNodeSpaceCreateInfoMSFT* createInfo,
    XrSpace*                                    space)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialGraphNodeSpaceMSFT>::Dispatch(manager, session, createInfo, space);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSpatialGraphNodeSpaceMSFT(session, createInfo, space);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceWrapper>(session, OpenXrNoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpatialGraphNodeSpaceMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(space, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceWrapper, XrSpatialGraphNodeSpaceCreateInfoMSFT>(result, session, space, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSpatialGraphNodeSpaceMSFT>::Dispatch(manager, result, session, createInfo, space);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrTryCreateSpatialGraphStaticNodeBindingMSFT(
    XrSession                                   session,
    const XrSpatialGraphStaticNodeBindingCreateInfoMSFT* createInfo,
    XrSpatialGraphNodeBindingMSFT*              nodeBinding)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT>::Dispatch(manager, session, createInfo, nodeBinding);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpatialGraphStaticNodeBindingCreateInfoMSFT* createInfo_unwrapped = UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->TryCreateSpatialGraphStaticNodeBindingMSFT(session, createInfo_unwrapped, nodeBinding);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(session, OpenXrNoParentWrapper::kHandleValue, nodeBinding, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(nodeBinding, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT>::Dispatch(manager, result, session, createInfo, nodeBinding);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpatialGraphNodeBindingMSFT(
    XrSpatialGraphNodeBindingMSFT               nodeBinding)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpatialGraphNodeBindingMSFT>::Dispatch(manager, nodeBinding);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(nodeBinding)->DestroySpatialGraphNodeBindingMSFT(nodeBinding);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySpatialGraphNodeBindingMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(nodeBinding);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(nodeBinding);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySpatialGraphNodeBindingMSFT>::Dispatch(manager, result, nodeBinding);

    DestroyWrappedOpenXrHandle<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(nodeBinding);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpatialGraphNodeBindingPropertiesMSFT(
    XrSpatialGraphNodeBindingMSFT               nodeBinding,
    const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* getInfo,
    XrSpatialGraphNodeBindingPropertiesMSFT*    properties)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT>::Dispatch(manager, nodeBinding, getInfo, properties);

    XrResult result = GetOpenXrInstanceTable(nodeBinding)->GetSpatialGraphNodeBindingPropertiesMSFT(nodeBinding, getInfo, properties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(nodeBinding);
        EncodeStructPtr(encoder, getInfo);
        EncodeStructPtr(encoder, properties, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT>::Dispatch(manager, result, nodeBinding, getInfo, properties);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateHandTrackerEXT(
    XrSession                                   session,
    const XrHandTrackerCreateInfoEXT*           createInfo,
    XrHandTrackerEXT*                           handTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateHandTrackerEXT>::Dispatch(manager, session, createInfo, handTracker);

    XrResult result = GetOpenXrInstanceTable(session)->CreateHandTrackerEXT(session, createInfo, handTracker);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::HandTrackerEXTWrapper>(session, OpenXrNoParentWrapper::kHandleValue, handTracker, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateHandTrackerEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::HandTrackerEXTWrapper>(handTracker, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::HandTrackerEXTWrapper, XrHandTrackerCreateInfoEXT>(result, session, handTracker, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateHandTrackerEXT>::Dispatch(manager, result, session, createInfo, handTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyHandTrackerEXT(
    XrHandTrackerEXT                            handTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyHandTrackerEXT>::Dispatch(manager, handTracker);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(handTracker)->DestroyHandTrackerEXT(handTracker);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyHandTrackerEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyHandTrackerEXT>::Dispatch(manager, result, handTracker);

    DestroyWrappedOpenXrHandle<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrLocateHandJointsEXT(
    XrHandTrackerEXT                            handTracker,
    const XrHandJointsLocateInfoEXT*            locateInfo,
    XrHandJointLocationsEXT*                    locations)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateHandJointsEXT>::Dispatch(manager, handTracker, locateInfo, locations);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrHandJointsLocateInfoEXT* locateInfo_unwrapped = UnwrapStructPtrHandles(locateInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(handTracker)->LocateHandJointsEXT(handTracker, locateInfo_unwrapped, locations);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrLocateHandJointsEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);
        EncodeStructPtr(encoder, locateInfo);
        EncodeStructPtr(encoder, locations, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrLocateHandJointsEXT>::Dispatch(manager, result, handTracker, locateInfo, locations);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateHandMeshSpaceMSFT(
    XrHandTrackerEXT                            handTracker,
    const XrHandMeshSpaceCreateInfoMSFT*        createInfo,
    XrSpace*                                    space)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateHandMeshSpaceMSFT>::Dispatch(manager, handTracker, createInfo, space);

    XrResult result = GetOpenXrInstanceTable(handTracker)->CreateHandMeshSpaceMSFT(handTracker, createInfo, space);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::HandTrackerEXTWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceWrapper>(handTracker, OpenXrNoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateHandMeshSpaceMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(space, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrHandTrackerEXT, openxr_wrappers::SpaceWrapper, XrHandMeshSpaceCreateInfoMSFT>(result, handTracker, space, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateHandMeshSpaceMSFT>::Dispatch(manager, result, handTracker, createInfo, space);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrUpdateHandMeshMSFT(
    XrHandTrackerEXT                            handTracker,
    const XrHandMeshUpdateInfoMSFT*             updateInfo,
    XrHandMeshMSFT*                             handMesh)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUpdateHandMeshMSFT>::Dispatch(manager, handTracker, updateInfo, handMesh);

    XrResult result = GetOpenXrInstanceTable(handTracker)->UpdateHandMeshMSFT(handTracker, updateInfo, handMesh);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrUpdateHandMeshMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);
        EncodeStructPtr(encoder, updateInfo);
        EncodeStructPtr(encoder, handMesh, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrUpdateHandMeshMSFT>::Dispatch(manager, result, handTracker, updateInfo, handMesh);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetControllerModelKeyMSFT(
    XrSession                                   session,
    XrPath                                      topLevelUserPath,
    XrControllerModelKeyStateMSFT*              controllerModelKeyState)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetControllerModelKeyMSFT>::Dispatch(manager, session, topLevelUserPath, controllerModelKeyState);

    XrResult result = GetOpenXrInstanceTable(session)->GetControllerModelKeyMSFT(session, topLevelUserPath, controllerModelKeyState);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetControllerModelKeyMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(topLevelUserPath);
        EncodeStructPtr(encoder, controllerModelKeyState, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetControllerModelKeyMSFT>::Dispatch(manager, result, session, topLevelUserPath, controllerModelKeyState);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrLoadControllerModelMSFT(
    XrSession                                   session,
    XrControllerModelKeyMSFT                    modelKey,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    uint8_t*                                    buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLoadControllerModelMSFT>::Dispatch(manager, session, modelKey, bufferCapacityInput, bufferCountOutput, buffer);

    XrResult result = GetOpenXrInstanceTable(session)->LoadControllerModelMSFT(session, modelKey, bufferCapacityInput, bufferCountOutput, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrLoadControllerModelMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::ControllerModelKeyMSFTWrapper>(modelKey);
        encoder->EncodeUInt32Value(bufferCapacityInput);
        encoder->EncodeUInt32Ptr(bufferCountOutput, omit_output_data);
        encoder->EncodeUInt8Array(buffer, bufferCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrLoadControllerModelMSFT>::Dispatch(manager, result, session, modelKey, bufferCapacityInput, bufferCountOutput, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetControllerModelPropertiesMSFT(
    XrSession                                   session,
    XrControllerModelKeyMSFT                    modelKey,
    XrControllerModelPropertiesMSFT*            properties)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetControllerModelPropertiesMSFT>::Dispatch(manager, session, modelKey, properties);

    XrResult result = GetOpenXrInstanceTable(session)->GetControllerModelPropertiesMSFT(session, modelKey, properties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetControllerModelPropertiesMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::ControllerModelKeyMSFTWrapper>(modelKey);
        EncodeStructPtr(encoder, properties, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetControllerModelPropertiesMSFT>::Dispatch(manager, result, session, modelKey, properties);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetControllerModelStateMSFT(
    XrSession                                   session,
    XrControllerModelKeyMSFT                    modelKey,
    XrControllerModelStateMSFT*                 state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetControllerModelStateMSFT>::Dispatch(manager, session, modelKey, state);

    XrResult result = GetOpenXrInstanceTable(session)->GetControllerModelStateMSFT(session, modelKey, state);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetControllerModelStateMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::ControllerModelKeyMSFTWrapper>(modelKey);
        EncodeStructPtr(encoder, state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetControllerModelStateMSFT>::Dispatch(manager, result, session, modelKey, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorFromPerceptionAnchorMSFT(
    XrSession                                   session,
    IUnknown*                                   perceptionAnchor,
    XrSpatialAnchorMSFT*                        anchor)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT>::Dispatch(manager, session, perceptionAnchor, anchor);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSpatialAnchorFromPerceptionAnchorMSFT(session, perceptionAnchor, anchor);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpatialAnchorMSFTWrapper>(session, OpenXrNoParentWrapper::kHandleValue, anchor, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeIUnknownPtr(perceptionAnchor, omit_output_data);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpatialAnchorMSFTWrapper>(anchor, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpatialAnchorMSFTWrapper, void>(result, session, anchor, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT>::Dispatch(manager, result, session, perceptionAnchor, anchor);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(
    XrSession                                   session,
    XrSpatialAnchorMSFT                         anchor,
    IUnknown**                                  perceptionAnchor)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT>::Dispatch(manager, session, anchor, perceptionAnchor);

    XrResult result = GetOpenXrInstanceTable(session)->TryGetPerceptionAnchorFromSpatialAnchorMSFT(session, anchor, perceptionAnchor);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorMSFTWrapper>(anchor);
        encoder->EncodeIUnknownPtrPtr(perceptionAnchor, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT>::Dispatch(manager, result, session, anchor, perceptionAnchor);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateReprojectionModesMSFT(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    modeCapacityInput,
    uint32_t*                                   modeCountOutput,
    XrReprojectionModeMSFT*                     modes)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateReprojectionModesMSFT>::Dispatch(manager, instance, systemId, viewConfigurationType, modeCapacityInput, modeCountOutput, modes);

    XrResult result = GetOpenXrInstanceTable(instance)->EnumerateReprojectionModesMSFT(instance, systemId, viewConfigurationType, modeCapacityInput, modeCountOutput, modes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateReprojectionModesMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        encoder->EncodeEnumValue(viewConfigurationType);
        encoder->EncodeUInt32Value(modeCapacityInput);
        encoder->EncodeUInt32Ptr(modeCountOutput, omit_output_data);
        encoder->EncodeEnumArray(modes, modeCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateReprojectionModesMSFT>::Dispatch(manager, result, instance, systemId, viewConfigurationType, modeCapacityInput, modeCountOutput, modes);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrUpdateSwapchainFB(
    XrSwapchain                                 swapchain,
    const XrSwapchainStateBaseHeaderFB*         state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUpdateSwapchainFB>::Dispatch(manager, swapchain, state);

    XrResult result = GetOpenXrInstanceTable(swapchain)->UpdateSwapchainFB(swapchain, state);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrUpdateSwapchainFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(swapchain);
        EncodeStructPtr(encoder, state);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrUpdateSwapchainFB>::Dispatch(manager, result, swapchain, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSwapchainStateFB(
    XrSwapchain                                 swapchain,
    XrSwapchainStateBaseHeaderFB*               state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSwapchainStateFB>::Dispatch(manager, swapchain, state);

    XrResult result = GetOpenXrInstanceTable(swapchain)->GetSwapchainStateFB(swapchain, state);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSwapchainStateFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(swapchain);
        EncodeStructPtr(encoder, state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSwapchainStateFB>::Dispatch(manager, result, swapchain, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateBodyTrackerFB(
    XrSession                                   session,
    const XrBodyTrackerCreateInfoFB*            createInfo,
    XrBodyTrackerFB*                            bodyTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateBodyTrackerFB>::Dispatch(manager, session, createInfo, bodyTracker);

    XrResult result = GetOpenXrInstanceTable(session)->CreateBodyTrackerFB(session, createInfo, bodyTracker);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::BodyTrackerFBWrapper>(session, OpenXrNoParentWrapper::kHandleValue, bodyTracker, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateBodyTrackerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::BodyTrackerFBWrapper>(bodyTracker, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::BodyTrackerFBWrapper, XrBodyTrackerCreateInfoFB>(result, session, bodyTracker, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateBodyTrackerFB>::Dispatch(manager, result, session, createInfo, bodyTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyBodyTrackerFB(
    XrBodyTrackerFB                             bodyTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyBodyTrackerFB>::Dispatch(manager, bodyTracker);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(bodyTracker)->DestroyBodyTrackerFB(bodyTracker);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyBodyTrackerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::BodyTrackerFBWrapper>(bodyTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::BodyTrackerFBWrapper>(bodyTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyBodyTrackerFB>::Dispatch(manager, result, bodyTracker);

    DestroyWrappedOpenXrHandle<openxr_wrappers::BodyTrackerFBWrapper>(bodyTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrLocateBodyJointsFB(
    XrBodyTrackerFB                             bodyTracker,
    const XrBodyJointsLocateInfoFB*             locateInfo,
    XrBodyJointLocationsFB*                     locations)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateBodyJointsFB>::Dispatch(manager, bodyTracker, locateInfo, locations);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrBodyJointsLocateInfoFB* locateInfo_unwrapped = UnwrapStructPtrHandles(locateInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(bodyTracker)->LocateBodyJointsFB(bodyTracker, locateInfo_unwrapped, locations);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrLocateBodyJointsFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::BodyTrackerFBWrapper>(bodyTracker);
        EncodeStructPtr(encoder, locateInfo);
        EncodeStructPtr(encoder, locations, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrLocateBodyJointsFB>::Dispatch(manager, result, bodyTracker, locateInfo, locations);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetBodySkeletonFB(
    XrBodyTrackerFB                             bodyTracker,
    XrBodySkeletonFB*                           skeleton)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetBodySkeletonFB>::Dispatch(manager, bodyTracker, skeleton);

    XrResult result = GetOpenXrInstanceTable(bodyTracker)->GetBodySkeletonFB(bodyTracker, skeleton);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetBodySkeletonFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::BodyTrackerFBWrapper>(bodyTracker);
        EncodeStructPtr(encoder, skeleton, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetBodySkeletonFB>::Dispatch(manager, result, bodyTracker, skeleton);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSceneComputeFeaturesMSFT(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    featureCapacityInput,
    uint32_t*                                   featureCountOutput,
    XrSceneComputeFeatureMSFT*                  features)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSceneComputeFeaturesMSFT>::Dispatch(manager, instance, systemId, featureCapacityInput, featureCountOutput, features);

    XrResult result = GetOpenXrInstanceTable(instance)->EnumerateSceneComputeFeaturesMSFT(instance, systemId, featureCapacityInput, featureCountOutput, features);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateSceneComputeFeaturesMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        encoder->EncodeUInt32Value(featureCapacityInput);
        encoder->EncodeUInt32Ptr(featureCountOutput, omit_output_data);
        encoder->EncodeEnumArray(features, featureCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateSceneComputeFeaturesMSFT>::Dispatch(manager, result, instance, systemId, featureCapacityInput, featureCountOutput, features);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSceneObserverMSFT(
    XrSession                                   session,
    const XrSceneObserverCreateInfoMSFT*        createInfo,
    XrSceneObserverMSFT*                        sceneObserver)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSceneObserverMSFT>::Dispatch(manager, session, createInfo, sceneObserver);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSceneObserverMSFT(session, createInfo, sceneObserver);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SceneObserverMSFTWrapper>(session, OpenXrNoParentWrapper::kHandleValue, sceneObserver, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSceneObserverMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SceneObserverMSFTWrapper, XrSceneObserverCreateInfoMSFT>(result, session, sceneObserver, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSceneObserverMSFT>::Dispatch(manager, result, session, createInfo, sceneObserver);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySceneObserverMSFT(
    XrSceneObserverMSFT                         sceneObserver)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySceneObserverMSFT>::Dispatch(manager, sceneObserver);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(sceneObserver)->DestroySceneObserverMSFT(sceneObserver);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySceneObserverMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySceneObserverMSFT>::Dispatch(manager, result, sceneObserver);

    DestroyWrappedOpenXrHandle<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrSceneCreateInfoMSFT*                createInfo,
    XrSceneMSFT*                                scene)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSceneMSFT>::Dispatch(manager, sceneObserver, createInfo, scene);

    XrResult result = GetOpenXrInstanceTable(sceneObserver)->CreateSceneMSFT(sceneObserver, createInfo, scene);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SceneObserverMSFTWrapper, OpenXrNoParentWrapper, openxr_wrappers::SceneMSFTWrapper>(sceneObserver, OpenXrNoParentWrapper::kHandleValue, scene, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSceneMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SceneMSFTWrapper>(scene, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSceneObserverMSFT, openxr_wrappers::SceneMSFTWrapper, XrSceneCreateInfoMSFT>(result, sceneObserver, scene, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSceneMSFT>::Dispatch(manager, result, sceneObserver, createInfo, scene);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySceneMSFT(
    XrSceneMSFT                                 scene)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySceneMSFT>::Dispatch(manager, scene);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(scene)->DestroySceneMSFT(scene);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySceneMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneMSFTWrapper>(scene);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SceneMSFTWrapper>(scene);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySceneMSFT>::Dispatch(manager, result, scene);

    DestroyWrappedOpenXrHandle<openxr_wrappers::SceneMSFTWrapper>(scene);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrComputeNewSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrNewSceneComputeInfoMSFT*            computeInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrComputeNewSceneMSFT>::Dispatch(manager, sceneObserver, computeInfo);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrNewSceneComputeInfoMSFT* computeInfo_unwrapped = UnwrapStructPtrHandles(computeInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(sceneObserver)->ComputeNewSceneMSFT(sceneObserver, computeInfo_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrComputeNewSceneMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver);
        EncodeStructPtr(encoder, computeInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrComputeNewSceneMSFT>::Dispatch(manager, result, sceneObserver, computeInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneComputeStateMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    XrSceneComputeStateMSFT*                    state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneComputeStateMSFT>::Dispatch(manager, sceneObserver, state);

    XrResult result = GetOpenXrInstanceTable(sceneObserver)->GetSceneComputeStateMSFT(sceneObserver, state);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSceneComputeStateMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver);
        encoder->EncodeEnumPtr(state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSceneComputeStateMSFT>::Dispatch(manager, result, sceneObserver, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneComponentsMSFT(
    XrSceneMSFT                                 scene,
    const XrSceneComponentsGetInfoMSFT*         getInfo,
    XrSceneComponentsMSFT*                      components)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneComponentsMSFT>::Dispatch(manager, scene, getInfo, components);

    XrResult result = GetOpenXrInstanceTable(scene)->GetSceneComponentsMSFT(scene, getInfo, components);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSceneComponentsMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneMSFTWrapper>(scene);
        EncodeStructPtr(encoder, getInfo);
        EncodeStructPtr(encoder, components, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSceneComponentsMSFT>::Dispatch(manager, result, scene, getInfo, components);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrLocateSceneComponentsMSFT(
    XrSceneMSFT                                 scene,
    const XrSceneComponentsLocateInfoMSFT*      locateInfo,
    XrSceneComponentLocationsMSFT*              locations)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateSceneComponentsMSFT>::Dispatch(manager, scene, locateInfo, locations);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSceneComponentsLocateInfoMSFT* locateInfo_unwrapped = UnwrapStructPtrHandles(locateInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(scene)->LocateSceneComponentsMSFT(scene, locateInfo_unwrapped, locations);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrLocateSceneComponentsMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneMSFTWrapper>(scene);
        EncodeStructPtr(encoder, locateInfo);
        EncodeStructPtr(encoder, locations, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrLocateSceneComponentsMSFT>::Dispatch(manager, result, scene, locateInfo, locations);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneMeshBuffersMSFT(
    XrSceneMSFT                                 scene,
    const XrSceneMeshBuffersGetInfoMSFT*        getInfo,
    XrSceneMeshBuffersMSFT*                     buffers)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneMeshBuffersMSFT>::Dispatch(manager, scene, getInfo, buffers);

    XrResult result = GetOpenXrInstanceTable(scene)->GetSceneMeshBuffersMSFT(scene, getInfo, buffers);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSceneMeshBuffersMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneMSFTWrapper>(scene);
        EncodeStructPtr(encoder, getInfo);
        EncodeStructPtr(encoder, buffers, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSceneMeshBuffersMSFT>::Dispatch(manager, result, scene, getInfo, buffers);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDeserializeSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrSceneDeserializeInfoMSFT*           deserializeInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDeserializeSceneMSFT>::Dispatch(manager, sceneObserver, deserializeInfo);

    XrResult result = GetOpenXrInstanceTable(sceneObserver)->DeserializeSceneMSFT(sceneObserver, deserializeInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrDeserializeSceneMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver);
        EncodeStructPtr(encoder, deserializeInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDeserializeSceneMSFT>::Dispatch(manager, result, sceneObserver, deserializeInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSerializedSceneFragmentDataMSFT(
    XrSceneMSFT                                 scene,
    const XrSerializedSceneFragmentDataGetInfoMSFT* getInfo,
    uint32_t                                    countInput,
    uint32_t*                                   readOutput,
    uint8_t*                                    buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSerializedSceneFragmentDataMSFT>::Dispatch(manager, scene, getInfo, countInput, readOutput, buffer);

    XrResult result = GetOpenXrInstanceTable(scene)->GetSerializedSceneFragmentDataMSFT(scene, getInfo, countInput, readOutput, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSerializedSceneFragmentDataMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneMSFTWrapper>(scene);
        EncodeStructPtr(encoder, getInfo);
        encoder->EncodeUInt32Value(countInput);
        encoder->EncodeUInt32Ptr(readOutput, omit_output_data);
        encoder->EncodeUInt8Array(buffer, countInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSerializedSceneFragmentDataMSFT>::Dispatch(manager, result, scene, getInfo, countInput, readOutput, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateDisplayRefreshRatesFB(
    XrSession                                   session,
    uint32_t                                    displayRefreshRateCapacityInput,
    uint32_t*                                   displayRefreshRateCountOutput,
    float*                                      displayRefreshRates)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateDisplayRefreshRatesFB>::Dispatch(manager, session, displayRefreshRateCapacityInput, displayRefreshRateCountOutput, displayRefreshRates);

    XrResult result = GetOpenXrInstanceTable(session)->EnumerateDisplayRefreshRatesFB(session, displayRefreshRateCapacityInput, displayRefreshRateCountOutput, displayRefreshRates);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateDisplayRefreshRatesFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt32Value(displayRefreshRateCapacityInput);
        encoder->EncodeUInt32Ptr(displayRefreshRateCountOutput, omit_output_data);
        encoder->EncodeFloatArray(displayRefreshRates, displayRefreshRateCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateDisplayRefreshRatesFB>::Dispatch(manager, result, session, displayRefreshRateCapacityInput, displayRefreshRateCountOutput, displayRefreshRates);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetDisplayRefreshRateFB(
    XrSession                                   session,
    float*                                      displayRefreshRate)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetDisplayRefreshRateFB>::Dispatch(manager, session, displayRefreshRate);

    XrResult result = GetOpenXrInstanceTable(session)->GetDisplayRefreshRateFB(session, displayRefreshRate);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetDisplayRefreshRateFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeFloatPtr(displayRefreshRate, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetDisplayRefreshRateFB>::Dispatch(manager, result, session, displayRefreshRate);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrRequestDisplayRefreshRateFB(
    XrSession                                   session,
    float                                       displayRefreshRate)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestDisplayRefreshRateFB>::Dispatch(manager, session, displayRefreshRate);

    XrResult result = GetOpenXrInstanceTable(session)->RequestDisplayRefreshRateFB(session, displayRefreshRate);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrRequestDisplayRefreshRateFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeFloatValue(displayRefreshRate);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrRequestDisplayRefreshRateFB>::Dispatch(manager, result, session, displayRefreshRate);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateViveTrackerPathsHTCX(
    XrInstance                                  instance,
    uint32_t                                    pathCapacityInput,
    uint32_t*                                   pathCountOutput,
    XrViveTrackerPathsHTCX*                     paths)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateViveTrackerPathsHTCX>::Dispatch(manager, instance, pathCapacityInput, pathCountOutput, paths);

    XrResult result = GetOpenXrInstanceTable(instance)->EnumerateViveTrackerPathsHTCX(instance, pathCapacityInput, pathCountOutput, paths);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateViveTrackerPathsHTCX);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeUInt32Value(pathCapacityInput);
        encoder->EncodeUInt32Ptr(pathCountOutput, omit_output_data);
        EncodeStructArray(encoder, paths, pathCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateViveTrackerPathsHTCX>::Dispatch(manager, result, instance, pathCapacityInput, pathCountOutput, paths);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateFacialTrackerHTC(
    XrSession                                   session,
    const XrFacialTrackerCreateInfoHTC*         createInfo,
    XrFacialTrackerHTC*                         facialTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFacialTrackerHTC>::Dispatch(manager, session, createInfo, facialTracker);

    XrResult result = GetOpenXrInstanceTable(session)->CreateFacialTrackerHTC(session, createInfo, facialTracker);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::FacialTrackerHTCWrapper>(session, OpenXrNoParentWrapper::kHandleValue, facialTracker, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateFacialTrackerHTC);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::FacialTrackerHTCWrapper>(facialTracker, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::FacialTrackerHTCWrapper, XrFacialTrackerCreateInfoHTC>(result, session, facialTracker, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateFacialTrackerHTC>::Dispatch(manager, result, session, createInfo, facialTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFacialTrackerHTC(
    XrFacialTrackerHTC                          facialTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFacialTrackerHTC>::Dispatch(manager, facialTracker);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(facialTracker)->DestroyFacialTrackerHTC(facialTracker);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyFacialTrackerHTC);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FacialTrackerHTCWrapper>(facialTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::FacialTrackerHTCWrapper>(facialTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyFacialTrackerHTC>::Dispatch(manager, result, facialTracker);

    DestroyWrappedOpenXrHandle<openxr_wrappers::FacialTrackerHTCWrapper>(facialTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetFacialExpressionsHTC(
    XrFacialTrackerHTC                          facialTracker,
    XrFacialExpressionsHTC*                     facialExpressions)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFacialExpressionsHTC>::Dispatch(manager, facialTracker, facialExpressions);

    XrResult result = GetOpenXrInstanceTable(facialTracker)->GetFacialExpressionsHTC(facialTracker, facialExpressions);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetFacialExpressionsHTC);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FacialTrackerHTCWrapper>(facialTracker);
        EncodeStructPtr(encoder, facialExpressions, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetFacialExpressionsHTC>::Dispatch(manager, result, facialTracker, facialExpressions);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateColorSpacesFB(
    XrSession                                   session,
    uint32_t                                    colorSpaceCapacityInput,
    uint32_t*                                   colorSpaceCountOutput,
    XrColorSpaceFB*                             colorSpaces)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateColorSpacesFB>::Dispatch(manager, session, colorSpaceCapacityInput, colorSpaceCountOutput, colorSpaces);

    XrResult result = GetOpenXrInstanceTable(session)->EnumerateColorSpacesFB(session, colorSpaceCapacityInput, colorSpaceCountOutput, colorSpaces);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateColorSpacesFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt32Value(colorSpaceCapacityInput);
        encoder->EncodeUInt32Ptr(colorSpaceCountOutput, omit_output_data);
        encoder->EncodeEnumArray(colorSpaces, colorSpaceCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateColorSpacesFB>::Dispatch(manager, result, session, colorSpaceCapacityInput, colorSpaceCountOutput, colorSpaces);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetColorSpaceFB(
    XrSession                                   session,
    const XrColorSpaceFB                        colorSpace)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetColorSpaceFB>::Dispatch(manager, session, colorSpace);

    XrResult result = GetOpenXrInstanceTable(session)->SetColorSpaceFB(session, colorSpace);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetColorSpaceFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(colorSpace);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetColorSpaceFB>::Dispatch(manager, result, session, colorSpace);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetHandMeshFB(
    XrHandTrackerEXT                            handTracker,
    XrHandTrackingMeshFB*                       mesh)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetHandMeshFB>::Dispatch(manager, handTracker, mesh);

    XrResult result = GetOpenXrInstanceTable(handTracker)->GetHandMeshFB(handTracker, mesh);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetHandMeshFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);
        EncodeStructPtr(encoder, mesh, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetHandMeshFB>::Dispatch(manager, result, handTracker, mesh);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorFB(
    XrSession                                   session,
    const XrSpatialAnchorCreateInfoFB*          info,
    XrAsyncRequestIdFB*                         requestId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFB>::Dispatch(manager, session, info, requestId);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpatialAnchorCreateInfoFB* info_unwrapped = UnwrapStructPtrHandles(info, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSpatialAnchorFB(session, info_unwrapped, requestId);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpatialAnchorFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        encoder->EncodeOpenXrAtomPtr<openxr_wrappers::AsyncRequestIdFBWrapper>(requestId, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateAtomApiCallCapture<XrSession, openxr_wrappers::AsyncRequestIdFBWrapper, XrSpatialAnchorCreateInfoFB>(result, session, requestId, info);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFB>::Dispatch(manager, result, session, info, requestId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceUuidFB(
    XrSpace                                     space,
    XrUuidEXT*                                  uuid)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceUuidFB>::Dispatch(manager, space, uuid);

    XrResult result = GetOpenXrInstanceTable(space)->GetSpaceUuidFB(space, uuid);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpaceUuidFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        EncodeStructPtr(encoder, uuid, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpaceUuidFB>::Dispatch(manager, result, space, uuid);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSpaceSupportedComponentsFB(
    XrSpace                                     space,
    uint32_t                                    componentTypeCapacityInput,
    uint32_t*                                   componentTypeCountOutput,
    XrSpaceComponentTypeFB*                     componentTypes)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSpaceSupportedComponentsFB>::Dispatch(manager, space, componentTypeCapacityInput, componentTypeCountOutput, componentTypes);

    XrResult result = GetOpenXrInstanceTable(space)->EnumerateSpaceSupportedComponentsFB(space, componentTypeCapacityInput, componentTypeCountOutput, componentTypes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateSpaceSupportedComponentsFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        encoder->EncodeUInt32Value(componentTypeCapacityInput);
        encoder->EncodeUInt32Ptr(componentTypeCountOutput, omit_output_data);
        encoder->EncodeEnumArray(componentTypes, componentTypeCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateSpaceSupportedComponentsFB>::Dispatch(manager, result, space, componentTypeCapacityInput, componentTypeCountOutput, componentTypes);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetSpaceComponentStatusFB(
    XrSpace                                     space,
    const XrSpaceComponentStatusSetInfoFB*      info,
    XrAsyncRequestIdFB*                         requestId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetSpaceComponentStatusFB>::Dispatch(manager, space, info, requestId);

    XrResult result = GetOpenXrInstanceTable(space)->SetSpaceComponentStatusFB(space, info, requestId);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetSpaceComponentStatusFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        EncodeStructPtr(encoder, info);
        encoder->EncodeOpenXrAtomPtr<openxr_wrappers::AsyncRequestIdFBWrapper>(requestId, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetSpaceComponentStatusFB>::Dispatch(manager, result, space, info, requestId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceComponentStatusFB(
    XrSpace                                     space,
    XrSpaceComponentTypeFB                      componentType,
    XrSpaceComponentStatusFB*                   status)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceComponentStatusFB>::Dispatch(manager, space, componentType, status);

    XrResult result = GetOpenXrInstanceTable(space)->GetSpaceComponentStatusFB(space, componentType, status);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpaceComponentStatusFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        encoder->EncodeEnumValue(componentType);
        EncodeStructPtr(encoder, status, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpaceComponentStatusFB>::Dispatch(manager, result, space, componentType, status);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateFoveationProfileFB(
    XrSession                                   session,
    const XrFoveationProfileCreateInfoFB*       createInfo,
    XrFoveationProfileFB*                       profile)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFoveationProfileFB>::Dispatch(manager, session, createInfo, profile);

    XrResult result = GetOpenXrInstanceTable(session)->CreateFoveationProfileFB(session, createInfo, profile);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::FoveationProfileFBWrapper>(session, OpenXrNoParentWrapper::kHandleValue, profile, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateFoveationProfileFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::FoveationProfileFBWrapper>(profile, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::FoveationProfileFBWrapper, XrFoveationProfileCreateInfoFB>(result, session, profile, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateFoveationProfileFB>::Dispatch(manager, result, session, createInfo, profile);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFoveationProfileFB(
    XrFoveationProfileFB                        profile)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFoveationProfileFB>::Dispatch(manager, profile);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(profile)->DestroyFoveationProfileFB(profile);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyFoveationProfileFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FoveationProfileFBWrapper>(profile);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::FoveationProfileFBWrapper>(profile);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyFoveationProfileFB>::Dispatch(manager, result, profile);

    DestroyWrappedOpenXrHandle<openxr_wrappers::FoveationProfileFBWrapper>(profile);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrQuerySystemTrackedKeyboardFB(
    XrSession                                   session,
    const XrKeyboardTrackingQueryFB*            queryInfo,
    XrKeyboardTrackingDescriptionFB*            keyboard)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQuerySystemTrackedKeyboardFB>::Dispatch(manager, session, queryInfo, keyboard);

    XrResult result = GetOpenXrInstanceTable(session)->QuerySystemTrackedKeyboardFB(session, queryInfo, keyboard);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrQuerySystemTrackedKeyboardFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, queryInfo);
        EncodeStructPtr(encoder, keyboard, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrQuerySystemTrackedKeyboardFB>::Dispatch(manager, result, session, queryInfo, keyboard);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateKeyboardSpaceFB(
    XrSession                                   session,
    const XrKeyboardSpaceCreateInfoFB*          createInfo,
    XrSpace*                                    keyboardSpace)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateKeyboardSpaceFB>::Dispatch(manager, session, createInfo, keyboardSpace);

    XrResult result = GetOpenXrInstanceTable(session)->CreateKeyboardSpaceFB(session, createInfo, keyboardSpace);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceWrapper>(session, OpenXrNoParentWrapper::kHandleValue, keyboardSpace, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateKeyboardSpaceFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(keyboardSpace, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceWrapper, XrKeyboardSpaceCreateInfoFB>(result, session, keyboardSpace, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateKeyboardSpaceFB>::Dispatch(manager, result, session, createInfo, keyboardSpace);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshBeginUpdateFB(
    XrTriangleMeshFB                            mesh)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshBeginUpdateFB>::Dispatch(manager, mesh);

    XrResult result = GetOpenXrInstanceTable(mesh)->TriangleMeshBeginUpdateFB(mesh);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTriangleMeshBeginUpdateFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrTriangleMeshBeginUpdateFB>::Dispatch(manager, result, mesh);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshEndUpdateFB(
    XrTriangleMeshFB                            mesh,
    uint32_t                                    vertexCount,
    uint32_t                                    triangleCount)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshEndUpdateFB>::Dispatch(manager, mesh, vertexCount, triangleCount);

    XrResult result = GetOpenXrInstanceTable(mesh)->TriangleMeshEndUpdateFB(mesh, vertexCount, triangleCount);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTriangleMeshEndUpdateFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
        encoder->EncodeUInt32Value(vertexCount);
        encoder->EncodeUInt32Value(triangleCount);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrTriangleMeshEndUpdateFB>::Dispatch(manager, result, mesh, vertexCount, triangleCount);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshBeginVertexBufferUpdateFB(
    XrTriangleMeshFB                            mesh,
    uint32_t*                                   outVertexCount)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB>::Dispatch(manager, mesh, outVertexCount);

    XrResult result = GetOpenXrInstanceTable(mesh)->TriangleMeshBeginVertexBufferUpdateFB(mesh, outVertexCount);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
        encoder->EncodeUInt32Ptr(outVertexCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB>::Dispatch(manager, result, mesh, outVertexCount);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshEndVertexBufferUpdateFB(
    XrTriangleMeshFB                            mesh)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshEndVertexBufferUpdateFB>::Dispatch(manager, mesh);

    XrResult result = GetOpenXrInstanceTable(mesh)->TriangleMeshEndVertexBufferUpdateFB(mesh);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTriangleMeshEndVertexBufferUpdateFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrTriangleMeshEndVertexBufferUpdateFB>::Dispatch(manager, result, mesh);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughFB(
    XrSession                                   session,
    const XrPassthroughCreateInfoFB*            createInfo,
    XrPassthroughFB*                            outPassthrough)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughFB>::Dispatch(manager, session, createInfo, outPassthrough);

    XrResult result = GetOpenXrInstanceTable(session)->CreatePassthroughFB(session, createInfo, outPassthrough);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::PassthroughFBWrapper>(session, OpenXrNoParentWrapper::kHandleValue, outPassthrough, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreatePassthroughFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::PassthroughFBWrapper>(outPassthrough, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::PassthroughFBWrapper, XrPassthroughCreateInfoFB>(result, session, outPassthrough, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreatePassthroughFB>::Dispatch(manager, result, session, createInfo, outPassthrough);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughFB(
    XrPassthroughFB                             passthrough)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughFB>::Dispatch(manager, passthrough);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(passthrough)->DestroyPassthroughFB(passthrough);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyPassthroughFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughFBWrapper>(passthrough);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::PassthroughFBWrapper>(passthrough);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyPassthroughFB>::Dispatch(manager, result, passthrough);

    DestroyWrappedOpenXrHandle<openxr_wrappers::PassthroughFBWrapper>(passthrough);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughStartFB(
    XrPassthroughFB                             passthrough)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughStartFB>::Dispatch(manager, passthrough);

    XrResult result = GetOpenXrInstanceTable(passthrough)->PassthroughStartFB(passthrough);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPassthroughStartFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughFBWrapper>(passthrough);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPassthroughStartFB>::Dispatch(manager, result, passthrough);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughPauseFB(
    XrPassthroughFB                             passthrough)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughPauseFB>::Dispatch(manager, passthrough);

    XrResult result = GetOpenXrInstanceTable(passthrough)->PassthroughPauseFB(passthrough);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPassthroughPauseFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughFBWrapper>(passthrough);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPassthroughPauseFB>::Dispatch(manager, result, passthrough);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughLayerFB(
    XrSession                                   session,
    const XrPassthroughLayerCreateInfoFB*       createInfo,
    XrPassthroughLayerFB*                       outLayer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughLayerFB>::Dispatch(manager, session, createInfo, outLayer);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrPassthroughLayerCreateInfoFB* createInfo_unwrapped = UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->CreatePassthroughLayerFB(session, createInfo_unwrapped, outLayer);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::PassthroughLayerFBWrapper>(session, OpenXrNoParentWrapper::kHandleValue, outLayer, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreatePassthroughLayerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::PassthroughLayerFBWrapper>(outLayer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::PassthroughLayerFBWrapper, XrPassthroughLayerCreateInfoFB>(result, session, outLayer, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreatePassthroughLayerFB>::Dispatch(manager, result, session, createInfo, outLayer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughLayerFB(
    XrPassthroughLayerFB                        layer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughLayerFB>::Dispatch(manager, layer);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(layer)->DestroyPassthroughLayerFB(layer);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyPassthroughLayerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughLayerFBWrapper>(layer);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::PassthroughLayerFBWrapper>(layer);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyPassthroughLayerFB>::Dispatch(manager, result, layer);

    DestroyWrappedOpenXrHandle<openxr_wrappers::PassthroughLayerFBWrapper>(layer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerPauseFB(
    XrPassthroughLayerFB                        layer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerPauseFB>::Dispatch(manager, layer);

    XrResult result = GetOpenXrInstanceTable(layer)->PassthroughLayerPauseFB(layer);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPassthroughLayerPauseFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughLayerFBWrapper>(layer);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPassthroughLayerPauseFB>::Dispatch(manager, result, layer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerResumeFB(
    XrPassthroughLayerFB                        layer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerResumeFB>::Dispatch(manager, layer);

    XrResult result = GetOpenXrInstanceTable(layer)->PassthroughLayerResumeFB(layer);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPassthroughLayerResumeFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughLayerFBWrapper>(layer);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPassthroughLayerResumeFB>::Dispatch(manager, result, layer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerSetStyleFB(
    XrPassthroughLayerFB                        layer,
    const XrPassthroughStyleFB*                 style)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerSetStyleFB>::Dispatch(manager, layer, style);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrPassthroughStyleFB* style_unwrapped = UnwrapStructPtrHandles(style, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(layer)->PassthroughLayerSetStyleFB(layer, style_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPassthroughLayerSetStyleFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughLayerFBWrapper>(layer);
        EncodeStructPtr(encoder, style);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPassthroughLayerSetStyleFB>::Dispatch(manager, result, layer, style);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateGeometryInstanceFB(
    XrSession                                   session,
    const XrGeometryInstanceCreateInfoFB*       createInfo,
    XrGeometryInstanceFB*                       outGeometryInstance)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateGeometryInstanceFB>::Dispatch(manager, session, createInfo, outGeometryInstance);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrGeometryInstanceCreateInfoFB* createInfo_unwrapped = UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->CreateGeometryInstanceFB(session, createInfo_unwrapped, outGeometryInstance);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::GeometryInstanceFBWrapper>(session, OpenXrNoParentWrapper::kHandleValue, outGeometryInstance, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateGeometryInstanceFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::GeometryInstanceFBWrapper>(outGeometryInstance, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::GeometryInstanceFBWrapper, XrGeometryInstanceCreateInfoFB>(result, session, outGeometryInstance, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateGeometryInstanceFB>::Dispatch(manager, result, session, createInfo, outGeometryInstance);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyGeometryInstanceFB(
    XrGeometryInstanceFB                        instance)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyGeometryInstanceFB>::Dispatch(manager, instance);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(instance)->DestroyGeometryInstanceFB(instance);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyGeometryInstanceFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::GeometryInstanceFBWrapper>(instance);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::GeometryInstanceFBWrapper>(instance);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyGeometryInstanceFB>::Dispatch(manager, result, instance);

    DestroyWrappedOpenXrHandle<openxr_wrappers::GeometryInstanceFBWrapper>(instance);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGeometryInstanceSetTransformFB(
    XrGeometryInstanceFB                        instance,
    const XrGeometryInstanceTransformFB*        transformation)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGeometryInstanceSetTransformFB>::Dispatch(manager, instance, transformation);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrGeometryInstanceTransformFB* transformation_unwrapped = UnwrapStructPtrHandles(transformation, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(instance)->GeometryInstanceSetTransformFB(instance, transformation_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGeometryInstanceSetTransformFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::GeometryInstanceFBWrapper>(instance);
        EncodeStructPtr(encoder, transformation);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGeometryInstanceSetTransformFB>::Dispatch(manager, result, instance, transformation);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateRenderModelPathsFB(
    XrSession                                   session,
    uint32_t                                    pathCapacityInput,
    uint32_t*                                   pathCountOutput,
    XrRenderModelPathInfoFB*                    paths)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateRenderModelPathsFB>::Dispatch(manager, session, pathCapacityInput, pathCountOutput, paths);

    XrResult result = GetOpenXrInstanceTable(session)->EnumerateRenderModelPathsFB(session, pathCapacityInput, pathCountOutput, paths);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateRenderModelPathsFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt32Value(pathCapacityInput);
        encoder->EncodeUInt32Ptr(pathCountOutput, omit_output_data);
        EncodeStructArray(encoder, paths, pathCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateRenderModelPathsFB>::Dispatch(manager, result, session, pathCapacityInput, pathCountOutput, paths);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetRenderModelPropertiesFB(
    XrSession                                   session,
    XrPath                                      path,
    XrRenderModelPropertiesFB*                  properties)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetRenderModelPropertiesFB>::Dispatch(manager, session, path, properties);

    XrResult result = GetOpenXrInstanceTable(session)->GetRenderModelPropertiesFB(session, path, properties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetRenderModelPropertiesFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(path);
        EncodeStructPtr(encoder, properties, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetRenderModelPropertiesFB>::Dispatch(manager, result, session, path, properties);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrLoadRenderModelFB(
    XrSession                                   session,
    const XrRenderModelLoadInfoFB*              info,
    XrRenderModelBufferFB*                      buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLoadRenderModelFB>::Dispatch(manager, session, info, buffer);

    XrResult result = GetOpenXrInstanceTable(session)->LoadRenderModelFB(session, info, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrLoadRenderModelFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        EncodeStructPtr(encoder, buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrLoadRenderModelFB>::Dispatch(manager, result, session, info, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetEnvironmentDepthEstimationVARJO(
    XrSession                                   session,
    XrBool32                                    enabled)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetEnvironmentDepthEstimationVARJO>::Dispatch(manager, session, enabled);

    XrResult result = GetOpenXrInstanceTable(session)->SetEnvironmentDepthEstimationVARJO(session, enabled);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetEnvironmentDepthEstimationVARJO);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt32Value(enabled);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetEnvironmentDepthEstimationVARJO>::Dispatch(manager, result, session, enabled);

    return result;
}

XRAPI_ATTR XrResult  XRAPI_CALL xrSetMarkerTrackingVARJO(
    XrSession                                   session,
    XrBool32                                    enabled)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingVARJO>::Dispatch(manager, session, enabled);

    XrResult result = GetOpenXrInstanceTable(session)->SetMarkerTrackingVARJO(session, enabled);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetMarkerTrackingVARJO);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt32Value(enabled);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingVARJO>::Dispatch(manager, result, session, enabled);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetMarkerTrackingTimeoutVARJO(
    XrSession                                   session,
    uint64_t                                    markerId,
    XrDuration                                  timeout)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingTimeoutVARJO>::Dispatch(manager, session, markerId, timeout);

    XrResult result = GetOpenXrInstanceTable(session)->SetMarkerTrackingTimeoutVARJO(session, markerId, timeout);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetMarkerTrackingTimeoutVARJO);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt64Value(markerId);
        encoder->EncodeInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingTimeoutVARJO>::Dispatch(manager, result, session, markerId, timeout);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetMarkerTrackingPredictionVARJO(
    XrSession                                   session,
    uint64_t                                    markerId,
    XrBool32                                    enable)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingPredictionVARJO>::Dispatch(manager, session, markerId, enable);

    XrResult result = GetOpenXrInstanceTable(session)->SetMarkerTrackingPredictionVARJO(session, markerId, enable);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetMarkerTrackingPredictionVARJO);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt64Value(markerId);
        encoder->EncodeUInt32Value(enable);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingPredictionVARJO>::Dispatch(manager, result, session, markerId, enable);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerSizeVARJO(
    XrSession                                   session,
    uint64_t                                    markerId,
    XrExtent2Df*                                size)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerSizeVARJO>::Dispatch(manager, session, markerId, size);

    XrResult result = GetOpenXrInstanceTable(session)->GetMarkerSizeVARJO(session, markerId, size);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetMarkerSizeVARJO);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt64Value(markerId);
        EncodeStructPtr(encoder, size, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetMarkerSizeVARJO>::Dispatch(manager, result, session, markerId, size);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateMarkerSpaceVARJO(
    XrSession                                   session,
    const XrMarkerSpaceCreateInfoVARJO*         createInfo,
    XrSpace*                                    space)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateMarkerSpaceVARJO>::Dispatch(manager, session, createInfo, space);

    XrResult result = GetOpenXrInstanceTable(session)->CreateMarkerSpaceVARJO(session, createInfo, space);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceWrapper>(session, OpenXrNoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateMarkerSpaceVARJO);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(space, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceWrapper, XrMarkerSpaceCreateInfoVARJO>(result, session, space, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateMarkerSpaceVARJO>::Dispatch(manager, result, session, createInfo, space);

    return result;
}

XRAPI_ATTR XrResult  XRAPI_CALL xrSetViewOffsetVARJO(
    XrSession                                   session,
    float                                       offset)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetViewOffsetVARJO>::Dispatch(manager, session, offset);

    XrResult result = GetOpenXrInstanceTable(session)->SetViewOffsetVARJO(session, offset);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetViewOffsetVARJO);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeFloatValue(offset);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetViewOffsetVARJO>::Dispatch(manager, result, session, offset);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpaceFromCoordinateFrameUIDML(
    XrSession                                   session,
    const XrCoordinateSpaceCreateInfoML *       createInfo,
    XrSpace*                                    space)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpaceFromCoordinateFrameUIDML>::Dispatch(manager, session, createInfo, space);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSpaceFromCoordinateFrameUIDML(session, createInfo, space);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceWrapper>(session, OpenXrNoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpaceFromCoordinateFrameUIDML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(space, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceWrapper, XrCoordinateSpaceCreateInfoML>(result, session, space, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSpaceFromCoordinateFrameUIDML>::Dispatch(manager, result, session, createInfo, space);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateMarkerDetectorML(
    XrSession                                   session,
    const XrMarkerDetectorCreateInfoML*         createInfo,
    XrMarkerDetectorML*                         markerDetector)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateMarkerDetectorML>::Dispatch(manager, session, createInfo, markerDetector);

    XrResult result = GetOpenXrInstanceTable(session)->CreateMarkerDetectorML(session, createInfo, markerDetector);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::MarkerDetectorMLWrapper>(session, OpenXrNoParentWrapper::kHandleValue, markerDetector, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateMarkerDetectorML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::MarkerDetectorMLWrapper, XrMarkerDetectorCreateInfoML>(result, session, markerDetector, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateMarkerDetectorML>::Dispatch(manager, result, session, createInfo, markerDetector);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyMarkerDetectorML(
    XrMarkerDetectorML                          markerDetector)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyMarkerDetectorML>::Dispatch(manager, markerDetector);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(markerDetector)->DestroyMarkerDetectorML(markerDetector);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyMarkerDetectorML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyMarkerDetectorML>::Dispatch(manager, result, markerDetector);

    DestroyWrappedOpenXrHandle<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSnapshotMarkerDetectorML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerDetectorSnapshotInfoML*             snapshotInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSnapshotMarkerDetectorML>::Dispatch(manager, markerDetector, snapshotInfo);

    XrResult result = GetOpenXrInstanceTable(markerDetector)->SnapshotMarkerDetectorML(markerDetector, snapshotInfo);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSnapshotMarkerDetectorML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
        EncodeStructPtr(encoder, snapshotInfo, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSnapshotMarkerDetectorML>::Dispatch(manager, result, markerDetector, snapshotInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerDetectorStateML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerDetectorStateML*                    state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerDetectorStateML>::Dispatch(manager, markerDetector, state);

    XrResult result = GetOpenXrInstanceTable(markerDetector)->GetMarkerDetectorStateML(markerDetector, state);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetMarkerDetectorStateML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
        EncodeStructPtr(encoder, state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetMarkerDetectorStateML>::Dispatch(manager, result, markerDetector, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkersML(
    XrMarkerDetectorML                          markerDetector,
    uint32_t                                    markerCapacityInput,
    uint32_t*                                   markerCountOutput,
    XrMarkerML*                                 markers)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkersML>::Dispatch(manager, markerDetector, markerCapacityInput, markerCountOutput, markers);

    XrResult result = GetOpenXrInstanceTable(markerDetector)->GetMarkersML(markerDetector, markerCapacityInput, markerCountOutput, markers);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetMarkersML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
        encoder->EncodeUInt32Value(markerCapacityInput);
        encoder->EncodeUInt32Ptr(markerCountOutput, omit_output_data);
        encoder->EncodeOpenXrAtomArray<openxr_wrappers::MarkerMLWrapper>(markers, markerCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetMarkersML>::Dispatch(manager, result, markerDetector, markerCapacityInput, markerCountOutput, markers);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerReprojectionErrorML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    float*                                      reprojectionErrorMeters)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerReprojectionErrorML>::Dispatch(manager, markerDetector, marker, reprojectionErrorMeters);

    XrResult result = GetOpenXrInstanceTable(markerDetector)->GetMarkerReprojectionErrorML(markerDetector, marker, reprojectionErrorMeters);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetMarkerReprojectionErrorML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::MarkerMLWrapper>(marker);
        encoder->EncodeFloatPtr(reprojectionErrorMeters, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetMarkerReprojectionErrorML>::Dispatch(manager, result, markerDetector, marker, reprojectionErrorMeters);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerLengthML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    float*                                      meters)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerLengthML>::Dispatch(manager, markerDetector, marker, meters);

    XrResult result = GetOpenXrInstanceTable(markerDetector)->GetMarkerLengthML(markerDetector, marker, meters);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetMarkerLengthML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::MarkerMLWrapper>(marker);
        encoder->EncodeFloatPtr(meters, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetMarkerLengthML>::Dispatch(manager, result, markerDetector, marker, meters);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerNumberML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    uint64_t*                                   number)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerNumberML>::Dispatch(manager, markerDetector, marker, number);

    XrResult result = GetOpenXrInstanceTable(markerDetector)->GetMarkerNumberML(markerDetector, marker, number);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetMarkerNumberML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::MarkerMLWrapper>(marker);
        encoder->EncodeUInt64Ptr(number, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetMarkerNumberML>::Dispatch(manager, result, markerDetector, marker, number);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerStringML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerStringML>::Dispatch(manager, markerDetector, marker, bufferCapacityInput, bufferCountOutput, buffer);

    XrResult result = GetOpenXrInstanceTable(markerDetector)->GetMarkerStringML(markerDetector, marker, bufferCapacityInput, bufferCountOutput, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetMarkerStringML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::MarkerMLWrapper>(marker);
        encoder->EncodeUInt32Value(bufferCapacityInput);
        encoder->EncodeUInt32Ptr(bufferCountOutput, omit_output_data);
        encoder->EncodeString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetMarkerStringML>::Dispatch(manager, result, markerDetector, marker, bufferCapacityInput, bufferCountOutput, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateMarkerSpaceML(
    XrSession                                   session,
    const XrMarkerSpaceCreateInfoML*            createInfo,
    XrSpace*                                    space)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateMarkerSpaceML>::Dispatch(manager, session, createInfo, space);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrMarkerSpaceCreateInfoML* createInfo_unwrapped = UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->CreateMarkerSpaceML(session, createInfo_unwrapped, space);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceWrapper>(session, OpenXrNoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateMarkerSpaceML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(space, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceWrapper, XrMarkerSpaceCreateInfoML>(result, session, space, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateMarkerSpaceML>::Dispatch(manager, result, session, createInfo, space);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnableLocalizationEventsML(
    XrSession                                   session,
    const XrLocalizationEnableEventsInfoML *    info)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnableLocalizationEventsML>::Dispatch(manager, session, info);

    XrResult result = GetOpenXrInstanceTable(session)->EnableLocalizationEventsML(session, info);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnableLocalizationEventsML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnableLocalizationEventsML>::Dispatch(manager, result, session, info);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrQueryLocalizationMapsML(
    XrSession                                   session,
    const XrLocalizationMapQueryInfoBaseHeaderML* queryInfo,
    uint32_t                                    mapCapacityInput,
    uint32_t *                                  mapCountOutput,
    XrLocalizationMapML*                        maps)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQueryLocalizationMapsML>::Dispatch(manager, session, queryInfo, mapCapacityInput, mapCountOutput, maps);

    XrResult result = GetOpenXrInstanceTable(session)->QueryLocalizationMapsML(session, queryInfo, mapCapacityInput, mapCountOutput, maps);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrQueryLocalizationMapsML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, queryInfo);
        encoder->EncodeUInt32Value(mapCapacityInput);
        encoder->EncodeUInt32Ptr(mapCountOutput, omit_output_data);
        EncodeStructArray(encoder, maps, mapCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrQueryLocalizationMapsML>::Dispatch(manager, result, session, queryInfo, mapCapacityInput, mapCountOutput, maps);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrRequestMapLocalizationML(
    XrSession                                   session,
    const XrMapLocalizationRequestInfoML*       requestInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestMapLocalizationML>::Dispatch(manager, session, requestInfo);

    XrResult result = GetOpenXrInstanceTable(session)->RequestMapLocalizationML(session, requestInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrRequestMapLocalizationML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, requestInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrRequestMapLocalizationML>::Dispatch(manager, result, session, requestInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrImportLocalizationMapML(
    XrSession                                   session,
    const XrLocalizationMapImportInfoML*        importInfo,
    XrUuidEXT*                                  mapUuid)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrImportLocalizationMapML>::Dispatch(manager, session, importInfo, mapUuid);

    XrResult result = GetOpenXrInstanceTable(session)->ImportLocalizationMapML(session, importInfo, mapUuid);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrImportLocalizationMapML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, importInfo);
        EncodeStructPtr(encoder, mapUuid, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrImportLocalizationMapML>::Dispatch(manager, result, session, importInfo, mapUuid);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateExportedLocalizationMapML(
    XrSession                                   session,
    const XrUuidEXT*                            mapUuid,
    XrExportedLocalizationMapML*                map)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateExportedLocalizationMapML>::Dispatch(manager, session, mapUuid, map);

    XrResult result = GetOpenXrInstanceTable(session)->CreateExportedLocalizationMapML(session, mapUuid, map);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::ExportedLocalizationMapMLWrapper>(session, OpenXrNoParentWrapper::kHandleValue, map, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateExportedLocalizationMapML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, mapUuid);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::ExportedLocalizationMapMLWrapper>(map, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::ExportedLocalizationMapMLWrapper, void>(result, session, map, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateExportedLocalizationMapML>::Dispatch(manager, result, session, mapUuid, map);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyExportedLocalizationMapML(
    XrExportedLocalizationMapML                 map)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyExportedLocalizationMapML>::Dispatch(manager, map);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(map)->DestroyExportedLocalizationMapML(map);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyExportedLocalizationMapML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::ExportedLocalizationMapMLWrapper>(map);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::ExportedLocalizationMapMLWrapper>(map);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyExportedLocalizationMapML>::Dispatch(manager, result, map);

    DestroyWrappedOpenXrHandle<openxr_wrappers::ExportedLocalizationMapMLWrapper>(map);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetExportedLocalizationMapDataML(
    XrExportedLocalizationMapML                 map,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetExportedLocalizationMapDataML>::Dispatch(manager, map, bufferCapacityInput, bufferCountOutput, buffer);

    XrResult result = GetOpenXrInstanceTable(map)->GetExportedLocalizationMapDataML(map, bufferCapacityInput, bufferCountOutput, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetExportedLocalizationMapDataML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::ExportedLocalizationMapMLWrapper>(map);
        encoder->EncodeUInt32Value(bufferCapacityInput);
        encoder->EncodeUInt32Ptr(bufferCountOutput, omit_output_data);
        encoder->EncodeString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetExportedLocalizationMapDataML>::Dispatch(manager, result, map, bufferCapacityInput, bufferCountOutput, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorStoreConnectionMSFT(
    XrSession                                   session,
    XrSpatialAnchorStoreConnectionMSFT*         spatialAnchorStore)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT>::Dispatch(manager, session, spatialAnchorStore);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSpatialAnchorStoreConnectionMSFT(session, spatialAnchorStore);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(session, OpenXrNoParentWrapper::kHandleValue, spatialAnchorStore, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper, void>(result, session, spatialAnchorStore, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT>::Dispatch(manager, result, session, spatialAnchorStore);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpatialAnchorStoreConnectionMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT>::Dispatch(manager, spatialAnchorStore);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(spatialAnchorStore)->DestroySpatialAnchorStoreConnectionMSFT(spatialAnchorStore);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT>::Dispatch(manager, result, spatialAnchorStore);

    DestroyWrappedOpenXrHandle<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrPersistSpatialAnchorMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore,
    const XrSpatialAnchorPersistenceInfoMSFT*   spatialAnchorPersistenceInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPersistSpatialAnchorMSFT>::Dispatch(manager, spatialAnchorStore, spatialAnchorPersistenceInfo);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpatialAnchorPersistenceInfoMSFT* spatialAnchorPersistenceInfo_unwrapped = UnwrapStructPtrHandles(spatialAnchorPersistenceInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(spatialAnchorStore)->PersistSpatialAnchorMSFT(spatialAnchorStore, spatialAnchorPersistenceInfo_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPersistSpatialAnchorMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore);
        EncodeStructPtr(encoder, spatialAnchorPersistenceInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPersistSpatialAnchorMSFT>::Dispatch(manager, result, spatialAnchorStore, spatialAnchorPersistenceInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumeratePersistedSpatialAnchorNamesMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore,
    uint32_t                                    spatialAnchorNameCapacityInput,
    uint32_t*                                   spatialAnchorNameCountOutput,
    XrSpatialAnchorPersistenceNameMSFT*         spatialAnchorNames)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT>::Dispatch(manager, spatialAnchorStore, spatialAnchorNameCapacityInput, spatialAnchorNameCountOutput, spatialAnchorNames);

    XrResult result = GetOpenXrInstanceTable(spatialAnchorStore)->EnumeratePersistedSpatialAnchorNamesMSFT(spatialAnchorStore, spatialAnchorNameCapacityInput, spatialAnchorNameCountOutput, spatialAnchorNames);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore);
        encoder->EncodeUInt32Value(spatialAnchorNameCapacityInput);
        encoder->EncodeUInt32Ptr(spatialAnchorNameCountOutput, omit_output_data);
        EncodeStructArray(encoder, spatialAnchorNames, spatialAnchorNameCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT>::Dispatch(manager, result, spatialAnchorStore, spatialAnchorNameCapacityInput, spatialAnchorNameCountOutput, spatialAnchorNames);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorFromPersistedNameMSFT(
    XrSession                                   session,
    const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* spatialAnchorCreateInfo,
    XrSpatialAnchorMSFT*                        spatialAnchor)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT>::Dispatch(manager, session, spatialAnchorCreateInfo, spatialAnchor);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* spatialAnchorCreateInfo_unwrapped = UnwrapStructPtrHandles(spatialAnchorCreateInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSpatialAnchorFromPersistedNameMSFT(session, spatialAnchorCreateInfo_unwrapped, spatialAnchor);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpatialAnchorMSFTWrapper>(session, OpenXrNoParentWrapper::kHandleValue, spatialAnchor, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, spatialAnchorCreateInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpatialAnchorMSFTWrapper>(spatialAnchor, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpatialAnchorMSFTWrapper, XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT>(result, session, spatialAnchor, spatialAnchorCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT>::Dispatch(manager, result, session, spatialAnchorCreateInfo, spatialAnchor);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrUnpersistSpatialAnchorMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore,
    const XrSpatialAnchorPersistenceNameMSFT*   spatialAnchorPersistenceName)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUnpersistSpatialAnchorMSFT>::Dispatch(manager, spatialAnchorStore, spatialAnchorPersistenceName);

    XrResult result = GetOpenXrInstanceTable(spatialAnchorStore)->UnpersistSpatialAnchorMSFT(spatialAnchorStore, spatialAnchorPersistenceName);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrUnpersistSpatialAnchorMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore);
        EncodeStructPtr(encoder, spatialAnchorPersistenceName);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrUnpersistSpatialAnchorMSFT>::Dispatch(manager, result, spatialAnchorStore, spatialAnchorPersistenceName);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrClearSpatialAnchorStoreMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrClearSpatialAnchorStoreMSFT>::Dispatch(manager, spatialAnchorStore);

    XrResult result = GetOpenXrInstanceTable(spatialAnchorStore)->ClearSpatialAnchorStoreMSFT(spatialAnchorStore);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrClearSpatialAnchorStoreMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrClearSpatialAnchorStoreMSFT>::Dispatch(manager, result, spatialAnchorStore);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneMarkerRawDataMSFT(
    XrSceneMSFT                                 scene,
    const XrUuidMSFT*                           markerId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    uint8_t*                                    buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneMarkerRawDataMSFT>::Dispatch(manager, scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);

    XrResult result = GetOpenXrInstanceTable(scene)->GetSceneMarkerRawDataMSFT(scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSceneMarkerRawDataMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneMSFTWrapper>(scene);
        EncodeStructPtr(encoder, markerId);
        encoder->EncodeUInt32Value(bufferCapacityInput);
        encoder->EncodeUInt32Ptr(bufferCountOutput, omit_output_data);
        encoder->EncodeUInt8Array(buffer, bufferCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSceneMarkerRawDataMSFT>::Dispatch(manager, result, scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneMarkerDecodedStringMSFT(
    XrSceneMSFT                                 scene,
    const XrUuidMSFT*                           markerId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneMarkerDecodedStringMSFT>::Dispatch(manager, scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);

    XrResult result = GetOpenXrInstanceTable(scene)->GetSceneMarkerDecodedStringMSFT(scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSceneMarkerDecodedStringMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneMSFTWrapper>(scene);
        EncodeStructPtr(encoder, markerId);
        encoder->EncodeUInt32Value(bufferCapacityInput);
        encoder->EncodeUInt32Ptr(bufferCountOutput, omit_output_data);
        encoder->EncodeString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSceneMarkerDecodedStringMSFT>::Dispatch(manager, result, scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrQuerySpacesFB(
    XrSession                                   session,
    const XrSpaceQueryInfoBaseHeaderFB*         info,
    XrAsyncRequestIdFB*                         requestId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQuerySpacesFB>::Dispatch(manager, session, info, requestId);

    XrResult result = GetOpenXrInstanceTable(session)->QuerySpacesFB(session, info, requestId);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrQuerySpacesFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        encoder->EncodeOpenXrAtomPtr<openxr_wrappers::AsyncRequestIdFBWrapper>(requestId, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrQuerySpacesFB>::Dispatch(manager, result, session, info, requestId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrRetrieveSpaceQueryResultsFB(
    XrSession                                   session,
    XrAsyncRequestIdFB                          requestId,
    XrSpaceQueryResultsFB*                      results)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRetrieveSpaceQueryResultsFB>::Dispatch(manager, session, requestId, results);

    XrResult result = GetOpenXrInstanceTable(session)->RetrieveSpaceQueryResultsFB(session, requestId, results);

    if (result >= 0)
    {
        CreateWrappedStructHandles<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper>(session, OpenXrNoParentWrapper::kHandleValue, results, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrRetrieveSpaceQueryResultsFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::AsyncRequestIdFBWrapper>(requestId);
        EncodeStructPtr(encoder, results, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrRetrieveSpaceQueryResultsFB>::Dispatch(manager, result, session, requestId, results);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSaveSpaceFB(
    XrSession                                   session,
    const XrSpaceSaveInfoFB*                    info,
    XrAsyncRequestIdFB*                         requestId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSaveSpaceFB>::Dispatch(manager, session, info, requestId);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpaceSaveInfoFB* info_unwrapped = UnwrapStructPtrHandles(info, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->SaveSpaceFB(session, info_unwrapped, requestId);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSaveSpaceFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        encoder->EncodeOpenXrAtomPtr<openxr_wrappers::AsyncRequestIdFBWrapper>(requestId, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSaveSpaceFB>::Dispatch(manager, result, session, info, requestId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEraseSpaceFB(
    XrSession                                   session,
    const XrSpaceEraseInfoFB*                   info,
    XrAsyncRequestIdFB*                         requestId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEraseSpaceFB>::Dispatch(manager, session, info, requestId);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpaceEraseInfoFB* info_unwrapped = UnwrapStructPtrHandles(info, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->EraseSpaceFB(session, info_unwrapped, requestId);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEraseSpaceFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        encoder->EncodeOpenXrAtomPtr<openxr_wrappers::AsyncRequestIdFBWrapper>(requestId, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEraseSpaceFB>::Dispatch(manager, result, session, info, requestId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetAudioOutputDeviceGuidOculus(
    XrInstance                                  instance,
    wchar_t                                     buffer[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS])
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetAudioOutputDeviceGuidOculus>::Dispatch(manager, instance, buffer);

    XrResult result = GetOpenXrInstanceTable(instance)->GetAudioOutputDeviceGuidOculus(instance, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetAudioOutputDeviceGuidOculus);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeWString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetAudioOutputDeviceGuidOculus>::Dispatch(manager, result, instance, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetAudioInputDeviceGuidOculus(
    XrInstance                                  instance,
    wchar_t                                     buffer[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS])
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetAudioInputDeviceGuidOculus>::Dispatch(manager, instance, buffer);

    XrResult result = GetOpenXrInstanceTable(instance)->GetAudioInputDeviceGuidOculus(instance, buffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetAudioInputDeviceGuidOculus);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeWString(buffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetAudioInputDeviceGuidOculus>::Dispatch(manager, result, instance, buffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrShareSpacesFB(
    XrSession                                   session,
    const XrSpaceShareInfoFB*                   info,
    XrAsyncRequestIdFB*                         requestId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrShareSpacesFB>::Dispatch(manager, session, info, requestId);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpaceShareInfoFB* info_unwrapped = UnwrapStructPtrHandles(info, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->ShareSpacesFB(session, info_unwrapped, requestId);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrShareSpacesFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        encoder->EncodeOpenXrAtomPtr<openxr_wrappers::AsyncRequestIdFBWrapper>(requestId, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrShareSpacesFB>::Dispatch(manager, result, session, info, requestId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceBoundingBox2DFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrRect2Df*                                  boundingBox2DOutput)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox2DFB>::Dispatch(manager, session, space, boundingBox2DOutput);

    XrResult result = GetOpenXrInstanceTable(session)->GetSpaceBoundingBox2DFB(session, space, boundingBox2DOutput);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpaceBoundingBox2DFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        EncodeStructPtr(encoder, boundingBox2DOutput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox2DFB>::Dispatch(manager, result, session, space, boundingBox2DOutput);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceBoundingBox3DFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrRect3DfFB*                                boundingBox3DOutput)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox3DFB>::Dispatch(manager, session, space, boundingBox3DOutput);

    XrResult result = GetOpenXrInstanceTable(session)->GetSpaceBoundingBox3DFB(session, space, boundingBox3DOutput);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpaceBoundingBox3DFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        EncodeStructPtr(encoder, boundingBox3DOutput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox3DFB>::Dispatch(manager, result, session, space, boundingBox3DOutput);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceSemanticLabelsFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrSemanticLabelsFB*                         semanticLabelsOutput)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceSemanticLabelsFB>::Dispatch(manager, session, space, semanticLabelsOutput);

    XrResult result = GetOpenXrInstanceTable(session)->GetSpaceSemanticLabelsFB(session, space, semanticLabelsOutput);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpaceSemanticLabelsFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        EncodeStructPtr(encoder, semanticLabelsOutput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpaceSemanticLabelsFB>::Dispatch(manager, result, session, space, semanticLabelsOutput);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceBoundary2DFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrBoundary2DFB*                             boundary2DOutput)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceBoundary2DFB>::Dispatch(manager, session, space, boundary2DOutput);

    XrResult result = GetOpenXrInstanceTable(session)->GetSpaceBoundary2DFB(session, space, boundary2DOutput);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpaceBoundary2DFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        EncodeStructPtr(encoder, boundary2DOutput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpaceBoundary2DFB>::Dispatch(manager, result, session, space, boundary2DOutput);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceRoomLayoutFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrRoomLayoutFB*                             roomLayoutOutput)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceRoomLayoutFB>::Dispatch(manager, session, space, roomLayoutOutput);

    XrResult result = GetOpenXrInstanceTable(session)->GetSpaceRoomLayoutFB(session, space, roomLayoutOutput);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpaceRoomLayoutFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        EncodeStructPtr(encoder, roomLayoutOutput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpaceRoomLayoutFB>::Dispatch(manager, result, session, space, roomLayoutOutput);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetDigitalLensControlALMALENCE(
    XrSession                                   session,
    const XrDigitalLensControlALMALENCE*        digitalLensControl)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetDigitalLensControlALMALENCE>::Dispatch(manager, session, digitalLensControl);

    XrResult result = GetOpenXrInstanceTable(session)->SetDigitalLensControlALMALENCE(session, digitalLensControl);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetDigitalLensControlALMALENCE);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, digitalLensControl);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetDigitalLensControlALMALENCE>::Dispatch(manager, result, session, digitalLensControl);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrRequestSceneCaptureFB(
    XrSession                                   session,
    const XrSceneCaptureRequestInfoFB*          info,
    XrAsyncRequestIdFB*                         requestId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestSceneCaptureFB>::Dispatch(manager, session, info, requestId);

    XrResult result = GetOpenXrInstanceTable(session)->RequestSceneCaptureFB(session, info, requestId);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrRequestSceneCaptureFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        encoder->EncodeOpenXrAtomPtr<openxr_wrappers::AsyncRequestIdFBWrapper>(requestId, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrRequestSceneCaptureFB>::Dispatch(manager, result, session, info, requestId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceContainerFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrSpaceContainerFB*                         spaceContainerOutput)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceContainerFB>::Dispatch(manager, session, space, spaceContainerOutput);

    XrResult result = GetOpenXrInstanceTable(session)->GetSpaceContainerFB(session, space, spaceContainerOutput);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpaceContainerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        EncodeStructPtr(encoder, spaceContainerOutput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpaceContainerFB>::Dispatch(manager, result, session, space, spaceContainerOutput);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetFoveationEyeTrackedStateMETA(
    XrSession                                   session,
    XrFoveationEyeTrackedStateMETA*             foveationState)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFoveationEyeTrackedStateMETA>::Dispatch(manager, session, foveationState);

    XrResult result = GetOpenXrInstanceTable(session)->GetFoveationEyeTrackedStateMETA(session, foveationState);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetFoveationEyeTrackedStateMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, foveationState, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetFoveationEyeTrackedStateMETA>::Dispatch(manager, result, session, foveationState);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateFaceTrackerFB(
    XrSession                                   session,
    const XrFaceTrackerCreateInfoFB*            createInfo,
    XrFaceTrackerFB*                            faceTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFaceTrackerFB>::Dispatch(manager, session, createInfo, faceTracker);

    XrResult result = GetOpenXrInstanceTable(session)->CreateFaceTrackerFB(session, createInfo, faceTracker);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::FaceTrackerFBWrapper>(session, OpenXrNoParentWrapper::kHandleValue, faceTracker, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateFaceTrackerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::FaceTrackerFBWrapper>(faceTracker, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::FaceTrackerFBWrapper, XrFaceTrackerCreateInfoFB>(result, session, faceTracker, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateFaceTrackerFB>::Dispatch(manager, result, session, createInfo, faceTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFaceTrackerFB(
    XrFaceTrackerFB                             faceTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFaceTrackerFB>::Dispatch(manager, faceTracker);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(faceTracker)->DestroyFaceTrackerFB(faceTracker);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyFaceTrackerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FaceTrackerFBWrapper>(faceTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::FaceTrackerFBWrapper>(faceTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyFaceTrackerFB>::Dispatch(manager, result, faceTracker);

    DestroyWrappedOpenXrHandle<openxr_wrappers::FaceTrackerFBWrapper>(faceTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetFaceExpressionWeightsFB(
    XrFaceTrackerFB                             faceTracker,
    const XrFaceExpressionInfoFB*               expressionInfo,
    XrFaceExpressionWeightsFB*                  expressionWeights)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFaceExpressionWeightsFB>::Dispatch(manager, faceTracker, expressionInfo, expressionWeights);

    XrResult result = GetOpenXrInstanceTable(faceTracker)->GetFaceExpressionWeightsFB(faceTracker, expressionInfo, expressionWeights);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetFaceExpressionWeightsFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FaceTrackerFBWrapper>(faceTracker);
        EncodeStructPtr(encoder, expressionInfo);
        EncodeStructPtr(encoder, expressionWeights, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetFaceExpressionWeightsFB>::Dispatch(manager, result, faceTracker, expressionInfo, expressionWeights);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateEyeTrackerFB(
    XrSession                                   session,
    const XrEyeTrackerCreateInfoFB*             createInfo,
    XrEyeTrackerFB*                             eyeTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateEyeTrackerFB>::Dispatch(manager, session, createInfo, eyeTracker);

    XrResult result = GetOpenXrInstanceTable(session)->CreateEyeTrackerFB(session, createInfo, eyeTracker);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::EyeTrackerFBWrapper>(session, OpenXrNoParentWrapper::kHandleValue, eyeTracker, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateEyeTrackerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::EyeTrackerFBWrapper>(eyeTracker, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::EyeTrackerFBWrapper, XrEyeTrackerCreateInfoFB>(result, session, eyeTracker, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateEyeTrackerFB>::Dispatch(manager, result, session, createInfo, eyeTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyEyeTrackerFB(
    XrEyeTrackerFB                              eyeTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyEyeTrackerFB>::Dispatch(manager, eyeTracker);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(eyeTracker)->DestroyEyeTrackerFB(eyeTracker);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyEyeTrackerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EyeTrackerFBWrapper>(eyeTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::EyeTrackerFBWrapper>(eyeTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyEyeTrackerFB>::Dispatch(manager, result, eyeTracker);

    DestroyWrappedOpenXrHandle<openxr_wrappers::EyeTrackerFBWrapper>(eyeTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetEyeGazesFB(
    XrEyeTrackerFB                              eyeTracker,
    const XrEyeGazesInfoFB*                     gazeInfo,
    XrEyeGazesFB*                               eyeGazes)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetEyeGazesFB>::Dispatch(manager, eyeTracker, gazeInfo, eyeGazes);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrEyeGazesInfoFB* gazeInfo_unwrapped = UnwrapStructPtrHandles(gazeInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(eyeTracker)->GetEyeGazesFB(eyeTracker, gazeInfo_unwrapped, eyeGazes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetEyeGazesFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EyeTrackerFBWrapper>(eyeTracker);
        EncodeStructPtr(encoder, gazeInfo);
        EncodeStructPtr(encoder, eyeGazes, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetEyeGazesFB>::Dispatch(manager, result, eyeTracker, gazeInfo, eyeGazes);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerSetKeyboardHandsIntensityFB(
    XrPassthroughLayerFB                        layer,
    const XrPassthroughKeyboardHandsIntensityFB* intensity)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerSetKeyboardHandsIntensityFB>::Dispatch(manager, layer, intensity);

    XrResult result = GetOpenXrInstanceTable(layer)->PassthroughLayerSetKeyboardHandsIntensityFB(layer, intensity);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPassthroughLayerSetKeyboardHandsIntensityFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughLayerFBWrapper>(layer);
        EncodeStructPtr(encoder, intensity);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPassthroughLayerSetKeyboardHandsIntensityFB>::Dispatch(manager, result, layer, intensity);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetDeviceSampleRateFB(
    XrSession                                   session,
    const XrHapticActionInfo*                   hapticActionInfo,
    XrDevicePcmSampleRateGetInfoFB*             deviceSampleRate)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetDeviceSampleRateFB>::Dispatch(manager, session, hapticActionInfo, deviceSampleRate);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrHapticActionInfo* hapticActionInfo_unwrapped = UnwrapStructPtrHandles(hapticActionInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->GetDeviceSampleRateFB(session, hapticActionInfo_unwrapped, deviceSampleRate);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetDeviceSampleRateFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, hapticActionInfo);
        EncodeStructPtr(encoder, deviceSampleRate, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetDeviceSampleRateFB>::Dispatch(manager, result, session, hapticActionInfo, deviceSampleRate);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetPassthroughPreferencesMETA(
    XrSession                                   session,
    XrPassthroughPreferencesMETA*               preferences)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPassthroughPreferencesMETA>::Dispatch(manager, session, preferences);

    XrResult result = GetOpenXrInstanceTable(session)->GetPassthroughPreferencesMETA(session, preferences);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetPassthroughPreferencesMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, preferences, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetPassthroughPreferencesMETA>::Dispatch(manager, result, session, preferences);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateVirtualKeyboardMETA(
    XrSession                                   session,
    const XrVirtualKeyboardCreateInfoMETA*      createInfo,
    XrVirtualKeyboardMETA*                      keyboard)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardMETA>::Dispatch(manager, session, createInfo, keyboard);

    XrResult result = GetOpenXrInstanceTable(session)->CreateVirtualKeyboardMETA(session, createInfo, keyboard);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::VirtualKeyboardMETAWrapper>(session, OpenXrNoParentWrapper::kHandleValue, keyboard, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateVirtualKeyboardMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::VirtualKeyboardMETAWrapper, XrVirtualKeyboardCreateInfoMETA>(result, session, keyboard, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardMETA>::Dispatch(manager, result, session, createInfo, keyboard);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyVirtualKeyboardMETA(
    XrVirtualKeyboardMETA                       keyboard)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyVirtualKeyboardMETA>::Dispatch(manager, keyboard);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(keyboard)->DestroyVirtualKeyboardMETA(keyboard);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyVirtualKeyboardMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyVirtualKeyboardMETA>::Dispatch(manager, result, keyboard);

    DestroyWrappedOpenXrHandle<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateVirtualKeyboardSpaceMETA(
    XrSession                                   session,
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardSpaceCreateInfoMETA* createInfo,
    XrSpace*                                    keyboardSpace)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardSpaceMETA>::Dispatch(manager, session, keyboard, createInfo, keyboardSpace);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrVirtualKeyboardSpaceCreateInfoMETA* createInfo_unwrapped = UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->CreateVirtualKeyboardSpaceMETA(session, keyboard, createInfo_unwrapped, keyboardSpace);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::VirtualKeyboardMETAWrapper, openxr_wrappers::SpaceWrapper>(session, keyboard, keyboardSpace, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateVirtualKeyboardSpaceMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(keyboardSpace, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceWrapper, XrVirtualKeyboardSpaceCreateInfoMETA>(result, session, keyboardSpace, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardSpaceMETA>::Dispatch(manager, result, session, keyboard, createInfo, keyboardSpace);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSuggestVirtualKeyboardLocationMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardLocationInfoMETA*    locationInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSuggestVirtualKeyboardLocationMETA>::Dispatch(manager, keyboard, locationInfo);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrVirtualKeyboardLocationInfoMETA* locationInfo_unwrapped = UnwrapStructPtrHandles(locationInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(keyboard)->SuggestVirtualKeyboardLocationMETA(keyboard, locationInfo_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSuggestVirtualKeyboardLocationMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        EncodeStructPtr(encoder, locationInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSuggestVirtualKeyboardLocationMETA>::Dispatch(manager, result, keyboard, locationInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardScaleMETA(
    XrVirtualKeyboardMETA                       keyboard,
    float*                                      scale)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardScaleMETA>::Dispatch(manager, keyboard, scale);

    XrResult result = GetOpenXrInstanceTable(keyboard)->GetVirtualKeyboardScaleMETA(keyboard, scale);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVirtualKeyboardScaleMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        encoder->EncodeFloatPtr(scale, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardScaleMETA>::Dispatch(manager, result, keyboard, scale);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetVirtualKeyboardModelVisibilityMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardModelVisibilitySetInfoMETA* modelVisibility)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetVirtualKeyboardModelVisibilityMETA>::Dispatch(manager, keyboard, modelVisibility);

    XrResult result = GetOpenXrInstanceTable(keyboard)->SetVirtualKeyboardModelVisibilityMETA(keyboard, modelVisibility);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetVirtualKeyboardModelVisibilityMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        EncodeStructPtr(encoder, modelVisibility);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetVirtualKeyboardModelVisibilityMETA>::Dispatch(manager, result, keyboard, modelVisibility);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardModelAnimationStatesMETA(
    XrVirtualKeyboardMETA                       keyboard,
    XrVirtualKeyboardModelAnimationStatesMETA*  animationStates)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA>::Dispatch(manager, keyboard, animationStates);

    XrResult result = GetOpenXrInstanceTable(keyboard)->GetVirtualKeyboardModelAnimationStatesMETA(keyboard, animationStates);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        EncodeStructPtr(encoder, animationStates, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA>::Dispatch(manager, result, keyboard, animationStates);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardDirtyTexturesMETA(
    XrVirtualKeyboardMETA                       keyboard,
    uint32_t                                    textureIdCapacityInput,
    uint32_t*                                   textureIdCountOutput,
    uint64_t*                                   textureIds)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA>::Dispatch(manager, keyboard, textureIdCapacityInput, textureIdCountOutput, textureIds);

    XrResult result = GetOpenXrInstanceTable(keyboard)->GetVirtualKeyboardDirtyTexturesMETA(keyboard, textureIdCapacityInput, textureIdCountOutput, textureIds);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        encoder->EncodeUInt32Value(textureIdCapacityInput);
        encoder->EncodeUInt32Ptr(textureIdCountOutput, omit_output_data);
        encoder->EncodeUInt64Array(textureIds, textureIdCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA>::Dispatch(manager, result, keyboard, textureIdCapacityInput, textureIdCountOutput, textureIds);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardTextureDataMETA(
    XrVirtualKeyboardMETA                       keyboard,
    uint64_t                                    textureId,
    XrVirtualKeyboardTextureDataMETA*           textureData)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardTextureDataMETA>::Dispatch(manager, keyboard, textureId, textureData);

    XrResult result = GetOpenXrInstanceTable(keyboard)->GetVirtualKeyboardTextureDataMETA(keyboard, textureId, textureData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetVirtualKeyboardTextureDataMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        encoder->EncodeUInt64Value(textureId);
        EncodeStructPtr(encoder, textureData, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardTextureDataMETA>::Dispatch(manager, result, keyboard, textureId, textureData);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSendVirtualKeyboardInputMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardInputInfoMETA*       info,
    XrPosef*                                    interactorRootPose)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSendVirtualKeyboardInputMETA>::Dispatch(manager, keyboard, info, interactorRootPose);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrVirtualKeyboardInputInfoMETA* info_unwrapped = UnwrapStructPtrHandles(info, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(keyboard)->SendVirtualKeyboardInputMETA(keyboard, info_unwrapped, interactorRootPose);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSendVirtualKeyboardInputMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        EncodeStructPtr(encoder, info);
        EncodeStructPtr(encoder, interactorRootPose, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSendVirtualKeyboardInputMETA>::Dispatch(manager, result, keyboard, info, interactorRootPose);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrChangeVirtualKeyboardTextContextMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardTextContextChangeInfoMETA* changeInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrChangeVirtualKeyboardTextContextMETA>::Dispatch(manager, keyboard, changeInfo);

    XrResult result = GetOpenXrInstanceTable(keyboard)->ChangeVirtualKeyboardTextContextMETA(keyboard, changeInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrChangeVirtualKeyboardTextContextMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        EncodeStructPtr(encoder, changeInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrChangeVirtualKeyboardTextContextMETA>::Dispatch(manager, result, keyboard, changeInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateExternalCamerasOCULUS(
    XrSession                                   session,
    uint32_t                                    cameraCapacityInput,
    uint32_t*                                   cameraCountOutput,
    XrExternalCameraOCULUS*                     cameras)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateExternalCamerasOCULUS>::Dispatch(manager, session, cameraCapacityInput, cameraCountOutput, cameras);

    XrResult result = GetOpenXrInstanceTable(session)->EnumerateExternalCamerasOCULUS(session, cameraCapacityInput, cameraCountOutput, cameras);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateExternalCamerasOCULUS);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeUInt32Value(cameraCapacityInput);
        encoder->EncodeUInt32Ptr(cameraCountOutput, omit_output_data);
        EncodeStructArray(encoder, cameras, cameraCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateExternalCamerasOCULUS>::Dispatch(manager, result, session, cameraCapacityInput, cameraCountOutput, cameras);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumeratePerformanceMetricsCounterPathsMETA(
    XrInstance                                  instance,
    uint32_t                                    counterPathCapacityInput,
    uint32_t*                                   counterPathCountOutput,
    XrPath*                                     counterPaths)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA>::Dispatch(manager, instance, counterPathCapacityInput, counterPathCountOutput, counterPaths);

    XrResult result = GetOpenXrInstanceTable(instance)->EnumeratePerformanceMetricsCounterPathsMETA(instance, counterPathCapacityInput, counterPathCountOutput, counterPaths);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeUInt32Value(counterPathCapacityInput);
        encoder->EncodeUInt32Ptr(counterPathCountOutput, omit_output_data);
        encoder->EncodeOpenXrAtomArray<openxr_wrappers::PathWrapper>(counterPaths, counterPathCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA>::Dispatch(manager, result, instance, counterPathCapacityInput, counterPathCountOutput, counterPaths);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetPerformanceMetricsStateMETA(
    XrSession                                   session,
    const XrPerformanceMetricsStateMETA*        state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetPerformanceMetricsStateMETA>::Dispatch(manager, session, state);

    XrResult result = GetOpenXrInstanceTable(session)->SetPerformanceMetricsStateMETA(session, state);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetPerformanceMetricsStateMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, state);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetPerformanceMetricsStateMETA>::Dispatch(manager, result, session, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetPerformanceMetricsStateMETA(
    XrSession                                   session,
    XrPerformanceMetricsStateMETA*              state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPerformanceMetricsStateMETA>::Dispatch(manager, session, state);

    XrResult result = GetOpenXrInstanceTable(session)->GetPerformanceMetricsStateMETA(session, state);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetPerformanceMetricsStateMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetPerformanceMetricsStateMETA>::Dispatch(manager, result, session, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrQueryPerformanceMetricsCounterMETA(
    XrSession                                   session,
    XrPath                                      counterPath,
    XrPerformanceMetricsCounterMETA*            counter)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQueryPerformanceMetricsCounterMETA>::Dispatch(manager, session, counterPath, counter);

    XrResult result = GetOpenXrInstanceTable(session)->QueryPerformanceMetricsCounterMETA(session, counterPath, counter);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrQueryPerformanceMetricsCounterMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::PathWrapper>(counterPath);
        EncodeStructPtr(encoder, counter, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrQueryPerformanceMetricsCounterMETA>::Dispatch(manager, result, session, counterPath, counter);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSaveSpaceListFB(
    XrSession                                   session,
    const XrSpaceListSaveInfoFB*                info,
    XrAsyncRequestIdFB*                         requestId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSaveSpaceListFB>::Dispatch(manager, session, info, requestId);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpaceListSaveInfoFB* info_unwrapped = UnwrapStructPtrHandles(info, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->SaveSpaceListFB(session, info_unwrapped, requestId);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSaveSpaceListFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        encoder->EncodeOpenXrAtomPtr<openxr_wrappers::AsyncRequestIdFBWrapper>(requestId, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSaveSpaceListFB>::Dispatch(manager, result, session, info, requestId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpaceUserFB(
    XrSession                                   session,
    const XrSpaceUserCreateInfoFB*              info,
    XrSpaceUserFB*                              user)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpaceUserFB>::Dispatch(manager, session, info, user);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSpaceUserFB(session, info, user);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceUserFBWrapper>(session, OpenXrNoParentWrapper::kHandleValue, user, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpaceUserFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceUserFBWrapper>(user, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceUserFBWrapper, XrSpaceUserCreateInfoFB>(result, session, user, info);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSpaceUserFB>::Dispatch(manager, result, session, info, user);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceUserIdFB(
    XrSpaceUserFB                               user,
    XrSpaceUserIdFB*                            userId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceUserIdFB>::Dispatch(manager, user, userId);

    XrResult result = GetOpenXrInstanceTable(user)->GetSpaceUserIdFB(user, userId);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpaceUserIdFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceUserFBWrapper>(user);
        encoder->EncodeUInt64Ptr(userId, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpaceUserIdFB>::Dispatch(manager, result, user, userId);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpaceUserFB(
    XrSpaceUserFB                               user)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpaceUserFB>::Dispatch(manager, user);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(user)->DestroySpaceUserFB(user);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySpaceUserFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceUserFBWrapper>(user);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SpaceUserFBWrapper>(user);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySpaceUserFB>::Dispatch(manager, result, user);

    DestroyWrappedOpenXrHandle<openxr_wrappers::SpaceUserFBWrapper>(user);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetRecommendedLayerResolutionMETA(
    XrSession                                   session,
    const XrRecommendedLayerResolutionGetInfoMETA* info,
    XrRecommendedLayerResolutionMETA*           resolution)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetRecommendedLayerResolutionMETA>::Dispatch(manager, session, info, resolution);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrRecommendedLayerResolutionGetInfoMETA* info_unwrapped = UnwrapStructPtrHandles(info, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->GetRecommendedLayerResolutionMETA(session, info_unwrapped, resolution);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetRecommendedLayerResolutionMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, info);
        EncodeStructPtr(encoder, resolution, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetRecommendedLayerResolutionMETA>::Dispatch(manager, result, session, info, resolution);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughColorLutMETA(
    XrPassthroughFB                             passthrough,
    const XrPassthroughColorLutCreateInfoMETA*  createInfo,
    XrPassthroughColorLutMETA*                  colorLut)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughColorLutMETA>::Dispatch(manager, passthrough, createInfo, colorLut);

    XrResult result = GetOpenXrInstanceTable(passthrough)->CreatePassthroughColorLutMETA(passthrough, createInfo, colorLut);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::PassthroughFBWrapper, OpenXrNoParentWrapper, openxr_wrappers::PassthroughColorLutMETAWrapper>(passthrough, OpenXrNoParentWrapper::kHandleValue, colorLut, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreatePassthroughColorLutMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughFBWrapper>(passthrough);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::PassthroughColorLutMETAWrapper>(colorLut, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrPassthroughFB, openxr_wrappers::PassthroughColorLutMETAWrapper, XrPassthroughColorLutCreateInfoMETA>(result, passthrough, colorLut, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreatePassthroughColorLutMETA>::Dispatch(manager, result, passthrough, createInfo, colorLut);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughColorLutMETA(
    XrPassthroughColorLutMETA                   colorLut)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughColorLutMETA>::Dispatch(manager, colorLut);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(colorLut)->DestroyPassthroughColorLutMETA(colorLut);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyPassthroughColorLutMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughColorLutMETAWrapper>(colorLut);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::PassthroughColorLutMETAWrapper>(colorLut);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyPassthroughColorLutMETA>::Dispatch(manager, result, colorLut);

    DestroyWrappedOpenXrHandle<openxr_wrappers::PassthroughColorLutMETAWrapper>(colorLut);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrUpdatePassthroughColorLutMETA(
    XrPassthroughColorLutMETA                   colorLut,
    const XrPassthroughColorLutUpdateInfoMETA*  updateInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUpdatePassthroughColorLutMETA>::Dispatch(manager, colorLut, updateInfo);

    XrResult result = GetOpenXrInstanceTable(colorLut)->UpdatePassthroughColorLutMETA(colorLut, updateInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrUpdatePassthroughColorLutMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughColorLutMETAWrapper>(colorLut);
        EncodeStructPtr(encoder, updateInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrUpdatePassthroughColorLutMETA>::Dispatch(manager, result, colorLut, updateInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceTriangleMeshMETA(
    XrSpace                                     space,
    const XrSpaceTriangleMeshGetInfoMETA*       getInfo,
    XrSpaceTriangleMeshMETA*                    triangleMeshOutput)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceTriangleMeshMETA>::Dispatch(manager, space, getInfo, triangleMeshOutput);

    XrResult result = GetOpenXrInstanceTable(space)->GetSpaceTriangleMeshMETA(space, getInfo, triangleMeshOutput);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpaceTriangleMeshMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        EncodeStructPtr(encoder, getInfo);
        EncodeStructPtr(encoder, triangleMeshOutput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpaceTriangleMeshMETA>::Dispatch(manager, result, space, getInfo, triangleMeshOutput);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateFaceTracker2FB(
    XrSession                                   session,
    const XrFaceTrackerCreateInfo2FB*           createInfo,
    XrFaceTracker2FB*                           faceTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFaceTracker2FB>::Dispatch(manager, session, createInfo, faceTracker);

    XrResult result = GetOpenXrInstanceTable(session)->CreateFaceTracker2FB(session, createInfo, faceTracker);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::FaceTracker2FBWrapper>(session, OpenXrNoParentWrapper::kHandleValue, faceTracker, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateFaceTracker2FB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::FaceTracker2FBWrapper>(faceTracker, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::FaceTracker2FBWrapper, XrFaceTrackerCreateInfo2FB>(result, session, faceTracker, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateFaceTracker2FB>::Dispatch(manager, result, session, createInfo, faceTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFaceTracker2FB(
    XrFaceTracker2FB                            faceTracker)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFaceTracker2FB>::Dispatch(manager, faceTracker);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(faceTracker)->DestroyFaceTracker2FB(faceTracker);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyFaceTracker2FB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FaceTracker2FBWrapper>(faceTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::FaceTracker2FBWrapper>(faceTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyFaceTracker2FB>::Dispatch(manager, result, faceTracker);

    DestroyWrappedOpenXrHandle<openxr_wrappers::FaceTracker2FBWrapper>(faceTracker);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetFaceExpressionWeights2FB(
    XrFaceTracker2FB                            faceTracker,
    const XrFaceExpressionInfo2FB*              expressionInfo,
    XrFaceExpressionWeights2FB*                 expressionWeights)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFaceExpressionWeights2FB>::Dispatch(manager, faceTracker, expressionInfo, expressionWeights);

    XrResult result = GetOpenXrInstanceTable(faceTracker)->GetFaceExpressionWeights2FB(faceTracker, expressionInfo, expressionWeights);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetFaceExpressionWeights2FB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FaceTracker2FBWrapper>(faceTracker);
        EncodeStructPtr(encoder, expressionInfo);
        EncodeStructPtr(encoder, expressionWeights, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetFaceExpressionWeights2FB>::Dispatch(manager, result, faceTracker, expressionInfo, expressionWeights);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrSetTrackingOptimizationSettingsHintQCOM(
    XrSession                                   session,
    XrTrackingOptimizationSettingsDomainQCOM    domain,
    XrTrackingOptimizationSettingsHintQCOM      hint)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetTrackingOptimizationSettingsHintQCOM>::Dispatch(manager, session, domain, hint);

    XrResult result = GetOpenXrInstanceTable(session)->SetTrackingOptimizationSettingsHintQCOM(session, domain, hint);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetTrackingOptimizationSettingsHintQCOM);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(domain);
        encoder->EncodeEnumValue(hint);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetTrackingOptimizationSettingsHintQCOM>::Dispatch(manager, result, session, domain, hint);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughHTC(
    XrSession                                   session,
    const XrPassthroughCreateInfoHTC*           createInfo,
    XrPassthroughHTC*                           passthrough)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughHTC>::Dispatch(manager, session, createInfo, passthrough);

    XrResult result = GetOpenXrInstanceTable(session)->CreatePassthroughHTC(session, createInfo, passthrough);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::PassthroughHTCWrapper>(session, OpenXrNoParentWrapper::kHandleValue, passthrough, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreatePassthroughHTC);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::PassthroughHTCWrapper>(passthrough, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::PassthroughHTCWrapper, XrPassthroughCreateInfoHTC>(result, session, passthrough, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreatePassthroughHTC>::Dispatch(manager, result, session, createInfo, passthrough);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughHTC(
    XrPassthroughHTC                            passthrough)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughHTC>::Dispatch(manager, passthrough);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(passthrough)->DestroyPassthroughHTC(passthrough);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyPassthroughHTC);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughHTCWrapper>(passthrough);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::PassthroughHTCWrapper>(passthrough);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyPassthroughHTC>::Dispatch(manager, result, passthrough);

    DestroyWrappedOpenXrHandle<openxr_wrappers::PassthroughHTCWrapper>(passthrough);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrApplyFoveationHTC(
    XrSession                                   session,
    const XrFoveationApplyInfoHTC*              applyInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrApplyFoveationHTC>::Dispatch(manager, session, applyInfo);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrFoveationApplyInfoHTC* applyInfo_unwrapped = UnwrapStructPtrHandles(applyInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->ApplyFoveationHTC(session, applyInfo_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrApplyFoveationHTC);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, applyInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrApplyFoveationHTC>::Dispatch(manager, result, session, applyInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorHTC(
    XrSession                                   session,
    const XrSpatialAnchorCreateInfoHTC*         createInfo,
    XrSpace*                                    anchor)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorHTC>::Dispatch(manager, session, createInfo, anchor);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrSpatialAnchorCreateInfoHTC* createInfo_unwrapped = UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(session)->CreateSpatialAnchorHTC(session, createInfo_unwrapped, anchor);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::SpaceWrapper>(session, OpenXrNoParentWrapper::kHandleValue, anchor, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpatialAnchorHTC);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::SpaceWrapper>(anchor, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::SpaceWrapper, XrSpatialAnchorCreateInfoHTC>(result, session, anchor, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorHTC>::Dispatch(manager, result, session, createInfo, anchor);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpatialAnchorNameHTC(
    XrSpace                                     anchor,
    XrSpatialAnchorNameHTC*                     name)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpatialAnchorNameHTC>::Dispatch(manager, anchor, name);

    XrResult result = GetOpenXrInstanceTable(anchor)->GetSpatialAnchorNameHTC(anchor, name);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetSpatialAnchorNameHTC);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(anchor);
        EncodeStructPtr(encoder, name, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetSpatialAnchorNameHTC>::Dispatch(manager, result, anchor, name);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrApplyForceFeedbackCurlMNDX(
    XrHandTrackerEXT                            handTracker,
    const XrForceFeedbackCurlApplyLocationsMNDX* locations)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrApplyForceFeedbackCurlMNDX>::Dispatch(manager, handTracker, locations);

    XrResult result = GetOpenXrInstanceTable(handTracker)->ApplyForceFeedbackCurlMNDX(handTracker, locations);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrApplyForceFeedbackCurlMNDX);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);
        EncodeStructPtr(encoder, locations);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrApplyForceFeedbackCurlMNDX>::Dispatch(manager, result, handTracker, locations);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreatePlaneDetectorEXT(
    XrSession                                   session,
    const XrPlaneDetectorCreateInfoEXT*         createInfo,
    XrPlaneDetectorEXT*                         planeDetector)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePlaneDetectorEXT>::Dispatch(manager, session, createInfo, planeDetector);

    XrResult result = GetOpenXrInstanceTable(session)->CreatePlaneDetectorEXT(session, createInfo, planeDetector);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper, OpenXrNoParentWrapper, openxr_wrappers::PlaneDetectorEXTWrapper>(session, OpenXrNoParentWrapper::kHandleValue, planeDetector, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreatePlaneDetectorEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::PlaneDetectorEXTWrapper, XrPlaneDetectorCreateInfoEXT>(result, session, planeDetector, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreatePlaneDetectorEXT>::Dispatch(manager, result, session, createInfo, planeDetector);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPlaneDetectorEXT(
    XrPlaneDetectorEXT                          planeDetector)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPlaneDetectorEXT>::Dispatch(manager, planeDetector);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = GetOpenXrInstanceTable(planeDetector)->DestroyPlaneDetectorEXT(planeDetector);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyPlaneDetectorEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyPlaneDetectorEXT>::Dispatch(manager, result, planeDetector);

    DestroyWrappedOpenXrHandle<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrBeginPlaneDetectionEXT(
    XrPlaneDetectorEXT                          planeDetector,
    const XrPlaneDetectorBeginInfoEXT*          beginInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrBeginPlaneDetectionEXT>::Dispatch(manager, planeDetector, beginInfo);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrPlaneDetectorBeginInfoEXT* beginInfo_unwrapped = UnwrapStructPtrHandles(beginInfo, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(planeDetector)->BeginPlaneDetectionEXT(planeDetector, beginInfo_unwrapped);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrBeginPlaneDetectionEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector);
        EncodeStructPtr(encoder, beginInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrBeginPlaneDetectionEXT>::Dispatch(manager, result, planeDetector, beginInfo);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetPlaneDetectionStateEXT(
    XrPlaneDetectorEXT                          planeDetector,
    XrPlaneDetectionStateEXT*                   state)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPlaneDetectionStateEXT>::Dispatch(manager, planeDetector, state);

    XrResult result = GetOpenXrInstanceTable(planeDetector)->GetPlaneDetectionStateEXT(planeDetector, state);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetPlaneDetectionStateEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector);
        encoder->EncodeEnumPtr(state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetPlaneDetectionStateEXT>::Dispatch(manager, result, planeDetector, state);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetPlaneDetectionsEXT(
    XrPlaneDetectorEXT                          planeDetector,
    const XrPlaneDetectorGetInfoEXT*            info,
    XrPlaneDetectorLocationsEXT*                locations)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPlaneDetectionsEXT>::Dispatch(manager, planeDetector, info, locations);

    auto handle_unwrap_memory = manager->GetHandleUnwrapMemory();
    const XrPlaneDetectorGetInfoEXT* info_unwrapped = UnwrapStructPtrHandles(info, handle_unwrap_memory);

    XrResult result = GetOpenXrInstanceTable(planeDetector)->GetPlaneDetectionsEXT(planeDetector, info_unwrapped, locations);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetPlaneDetectionsEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector);
        EncodeStructPtr(encoder, info);
        EncodeStructPtr(encoder, locations, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetPlaneDetectionsEXT>::Dispatch(manager, result, planeDetector, info, locations);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetPlanePolygonBufferEXT(
    XrPlaneDetectorEXT                          planeDetector,
    uint64_t                                    planeId,
    uint32_t                                    polygonBufferIndex,
    XrPlaneDetectorPolygonBufferEXT*            polygonBuffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPlanePolygonBufferEXT>::Dispatch(manager, planeDetector, planeId, polygonBufferIndex, polygonBuffer);

    XrResult result = GetOpenXrInstanceTable(planeDetector)->GetPlanePolygonBufferEXT(planeDetector, planeId, polygonBufferIndex, polygonBuffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetPlanePolygonBufferEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector);
        encoder->EncodeUInt64Value(planeId);
        encoder->EncodeUInt32Value(polygonBufferIndex);
        EncodeStructPtr(encoder, polygonBuffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetPlanePolygonBufferEXT>::Dispatch(manager, result, planeDetector, planeId, polygonBufferIndex, polygonBuffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrEnableUserCalibrationEventsML(
    XrInstance                                  instance,
    const XrUserCalibrationEnableEventsInfoML*  enableInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnableUserCalibrationEventsML>::Dispatch(manager, instance, enableInfo);

    XrResult result = GetOpenXrInstanceTable(instance)->EnableUserCalibrationEventsML(instance, enableInfo);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnableUserCalibrationEventsML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, enableInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnableUserCalibrationEventsML>::Dispatch(manager, result, instance, enableInfo);

    return result;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
