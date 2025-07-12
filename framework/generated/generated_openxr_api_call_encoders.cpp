/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#if ENABLE_OPENXR_SUPPORT

#include "encode/custom_openxr_encoder_commands.h"
#include "encode/custom_openxr_struct_handle_wrappers.h"
#include "encode/openxr_capture_manager.h"
#include "encode/openxr_handle_wrappers.h"
#include "encode/openxr_handle_wrapper_util.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"

#include "format/api_call_id.h"

#include "generated/generated_openxr_api_call_encoders.h"
#include "generated/generated_openxr_struct_handle_wrappers.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"

#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyInstance(
    XrInstance                                  instance)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyInstance>::PreLockReentrant(manager, instance);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyInstance);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyInstance>::Dispatch(manager, instance);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(instance)->DestroyInstance(instance);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyInstance);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::InstanceWrapper>(instance);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyInstance>::Dispatch(manager, result, instance);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::InstanceWrapper>(instance);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetInstanceProperties(
    XrInstance                                  instance,
    XrInstanceProperties*                       instanceProperties)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetInstanceProperties>::PreLockReentrant(manager, instance, instanceProperties);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetInstanceProperties);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetInstanceProperties>::Dispatch(manager, instance, instanceProperties);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetInstanceProperties(instance, instanceProperties);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetInstanceProperties>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPollEvent>::PreLockReentrant(manager, instance, eventData);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPollEvent);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPollEvent>::Dispatch(manager, instance, eventData);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->PollEvent(instance, eventData);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrPollEvent>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrResultToString>::PreLockReentrant(manager, instance, value, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrResultToString);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrResultToString>::Dispatch(manager, instance, value, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->ResultToString(instance, value, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrResultToString>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStructureTypeToString>::PreLockReentrant(manager, instance, value, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrStructureTypeToString);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStructureTypeToString>::Dispatch(manager, instance, value, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->StructureTypeToString(instance, value, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrStructureTypeToString>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSystem>::PreLockReentrant(manager, instance, getInfo, systemId);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSystem);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSystem>::Dispatch(manager, instance, getInfo, systemId);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetSystem(instance, getInfo, systemId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrGetSystem>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtom<openxr_wrappers::InstanceWrapper, openxr_wrappers::SystemIdWrapper>(instance, systemId, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSystemProperties>::PreLockReentrant(manager, instance, systemId, properties);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSystemProperties);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSystemProperties>::Dispatch(manager, instance, systemId, properties);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetSystemProperties(instance, systemId, properties);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrGetSystemProperties>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedStructHandles<openxr_wrappers::InstanceWrapper, openxr_wrappers::SystemIdWrapper>(instance, systemId, properties, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateEnvironmentBlendModes>::PreLockReentrant(manager, instance, systemId, viewConfigurationType, environmentBlendModeCapacityInput, environmentBlendModeCountOutput, environmentBlendModes);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateEnvironmentBlendModes);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateEnvironmentBlendModes>::Dispatch(manager, instance, systemId, viewConfigurationType, environmentBlendModeCapacityInput, environmentBlendModeCountOutput, environmentBlendModes);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->EnumerateEnvironmentBlendModes(instance, systemId, viewConfigurationType, environmentBlendModeCapacityInput, environmentBlendModeCountOutput, environmentBlendModes);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateEnvironmentBlendModes>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSession>::PreLockReentrant(manager, instance, createInfo, session);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSessionCreateInfo* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSession);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSession>::Dispatch(manager, instance, createInfo, session);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->CreateSession(instance, createInfo_unwrapped, session);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSession>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::InstanceWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SessionWrapper>(instance, openxr_wrappers::NoParentWrapper::kHandleValue, session, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySession>::PreLockReentrant(manager, session);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroySession);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySession>::Dispatch(manager, session);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(session)->DestroySession(session);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySession);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SessionWrapper>(session);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySession>::Dispatch(manager, result, session);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::SessionWrapper>(session);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateReferenceSpaces(
    XrSession                                   session,
    uint32_t                                    spaceCapacityInput,
    uint32_t*                                   spaceCountOutput,
    XrReferenceSpaceType*                       spaces)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateReferenceSpaces>::PreLockReentrant(manager, session, spaceCapacityInput, spaceCountOutput, spaces);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateReferenceSpaces);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateReferenceSpaces>::Dispatch(manager, session, spaceCapacityInput, spaceCountOutput, spaces);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EnumerateReferenceSpaces(session, spaceCapacityInput, spaceCountOutput, spaces);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateReferenceSpaces>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateReferenceSpace>::PreLockReentrant(manager, session, createInfo, space);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateReferenceSpace);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateReferenceSpace>::Dispatch(manager, session, createInfo, space);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateReferenceSpace(session, createInfo, space);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateReferenceSpace>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetReferenceSpaceBoundsRect>::PreLockReentrant(manager, session, referenceSpaceType, bounds);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetReferenceSpaceBoundsRect);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetReferenceSpaceBoundsRect>::Dispatch(manager, session, referenceSpaceType, bounds);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetReferenceSpaceBoundsRect(session, referenceSpaceType, bounds);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetReferenceSpaceBoundsRect>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateActionSpace>::PreLockReentrant(manager, session, createInfo, space);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrActionSpaceCreateInfo* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateActionSpace);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateActionSpace>::Dispatch(manager, session, createInfo, space);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateActionSpace(session, createInfo_unwrapped, space);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateActionSpace>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateSpace>::PreLockReentrant(manager, space, baseSpace, time, location);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrLocateSpace);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateSpace>::Dispatch(manager, space, baseSpace, time, location);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(space)->LocateSpace(space, baseSpace, time, location);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrLocateSpace>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrLocateSpace);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(baseSpace);
        encoder->EncodeXrTimeValue(time);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpace>::PreLockReentrant(manager, space);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroySpace);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpace>::Dispatch(manager, space);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(space)->DestroySpace(space);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySpace);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceWrapper>(space);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SpaceWrapper>(space);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySpace>::Dispatch(manager, result, space);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::SpaceWrapper>(space);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateViewConfigurations(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    viewConfigurationTypeCapacityInput,
    uint32_t*                                   viewConfigurationTypeCountOutput,
    XrViewConfigurationType*                    viewConfigurationTypes)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateViewConfigurations>::PreLockReentrant(manager, instance, systemId, viewConfigurationTypeCapacityInput, viewConfigurationTypeCountOutput, viewConfigurationTypes);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateViewConfigurations);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateViewConfigurations>::Dispatch(manager, instance, systemId, viewConfigurationTypeCapacityInput, viewConfigurationTypeCountOutput, viewConfigurationTypes);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->EnumerateViewConfigurations(instance, systemId, viewConfigurationTypeCapacityInput, viewConfigurationTypeCountOutput, viewConfigurationTypes);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateViewConfigurations>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetViewConfigurationProperties>::PreLockReentrant(manager, instance, systemId, viewConfigurationType, configurationProperties);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetViewConfigurationProperties);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetViewConfigurationProperties>::Dispatch(manager, instance, systemId, viewConfigurationType, configurationProperties);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetViewConfigurationProperties(instance, systemId, viewConfigurationType, configurationProperties);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetViewConfigurationProperties>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateViewConfigurationViews>::PreLockReentrant(manager, instance, systemId, viewConfigurationType, viewCapacityInput, viewCountOutput, views);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateViewConfigurationViews);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateViewConfigurationViews>::Dispatch(manager, instance, systemId, viewConfigurationType, viewCapacityInput, viewCountOutput, views);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->EnumerateViewConfigurationViews(instance, systemId, viewConfigurationType, viewCapacityInput, viewCountOutput, views);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateViewConfigurationViews>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSwapchainFormats>::PreLockReentrant(manager, session, formatCapacityInput, formatCountOutput, formats);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateSwapchainFormats);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSwapchainFormats>::Dispatch(manager, session, formatCapacityInput, formatCountOutput, formats);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EnumerateSwapchainFormats(session, formatCapacityInput, formatCountOutput, formats);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateSwapchainFormats>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSwapchain>::PreLockReentrant(manager, session, createInfo, swapchain);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSwapchain);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSwapchain>::Dispatch(manager, session, createInfo, swapchain);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSwapchain(session, createInfo, swapchain);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSwapchain>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SwapchainWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, swapchain, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySwapchain>::PreLockReentrant(manager, swapchain);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroySwapchain);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySwapchain>::Dispatch(manager, swapchain);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(swapchain)->DestroySwapchain(swapchain);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySwapchain);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SwapchainWrapper>(swapchain);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SwapchainWrapper>(swapchain);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySwapchain>::Dispatch(manager, result, swapchain);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::SwapchainWrapper>(swapchain);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSwapchainImages(
    XrSwapchain                                 swapchain,
    uint32_t                                    imageCapacityInput,
    uint32_t*                                   imageCountOutput,
    XrSwapchainImageBaseHeader*                 images)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSwapchainImages>::PreLockReentrant(manager, swapchain, imageCapacityInput, imageCountOutput, images);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateSwapchainImages);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSwapchainImages>::Dispatch(manager, swapchain, imageCapacityInput, imageCountOutput, images);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(swapchain)->EnumerateSwapchainImages(swapchain, imageCapacityInput, imageCountOutput, images);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateSwapchainImages>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrAcquireSwapchainImage>::PreLockReentrant(manager, swapchain, acquireInfo, index);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrAcquireSwapchainImage);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrAcquireSwapchainImage>::Dispatch(manager, swapchain, acquireInfo, index);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(swapchain)->AcquireSwapchainImage(swapchain, acquireInfo, index);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrAcquireSwapchainImage>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrWaitSwapchainImage>::PreLockReentrant(manager, swapchain, waitInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrWaitSwapchainImage);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrWaitSwapchainImage>::Dispatch(manager, swapchain, waitInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(swapchain)->WaitSwapchainImage(swapchain, waitInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrReleaseSwapchainImage>::PreLockReentrant(manager, swapchain, releaseInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrReleaseSwapchainImage);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrReleaseSwapchainImage>::Dispatch(manager, swapchain, releaseInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(swapchain)->ReleaseSwapchainImage(swapchain, releaseInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrBeginSession>::PreLockReentrant(manager, session, beginInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrBeginSession);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrBeginSession>::Dispatch(manager, session, beginInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->BeginSession(session, beginInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEndSession>::PreLockReentrant(manager, session);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEndSession);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEndSession>::Dispatch(manager, session);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EndSession(session);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestExitSession>::PreLockReentrant(manager, session);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrRequestExitSession);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestExitSession>::Dispatch(manager, session);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->RequestExitSession(session);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrWaitFrame>::PreLockReentrant(manager, session, frameWaitInfo, frameState);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrWaitFrame);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrWaitFrame>::Dispatch(manager, session, frameWaitInfo, frameState);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->WaitFrame(session, frameWaitInfo, frameState);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrWaitFrame>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrBeginFrame>::PreLockReentrant(manager, session, frameBeginInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrBeginFrame);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrBeginFrame>::Dispatch(manager, session, frameBeginInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->BeginFrame(session, frameBeginInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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

XRAPI_ATTR XrResult XRAPI_CALL xrLocateViews(
    XrSession                                   session,
    const XrViewLocateInfo*                     viewLocateInfo,
    XrViewState*                                viewState,
    uint32_t                                    viewCapacityInput,
    uint32_t*                                   viewCountOutput,
    XrView*                                     views)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateViews>::PreLockReentrant(manager, session, viewLocateInfo, viewState, viewCapacityInput, viewCountOutput, views);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrViewLocateInfo* viewLocateInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrLocateViews);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateViews>::Dispatch(manager, session, viewLocateInfo, viewState, viewCapacityInput, viewCountOutput, views);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        viewLocateInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(viewLocateInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->LocateViews(session, viewLocateInfo_unwrapped, viewState, viewCapacityInput, viewCountOutput, views);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrLocateViews>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStringToPath>::PreLockReentrant(manager, instance, pathString, path);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrStringToPath);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStringToPath>::Dispatch(manager, instance, pathString, path);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->StringToPath(instance, pathString, path);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrStringToPath>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtom<openxr_wrappers::InstanceWrapper, openxr_wrappers::PathWrapper>(instance, path, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPathToString>::PreLockReentrant(manager, instance, path, bufferCapacityInput, bufferCountOutput, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPathToString);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPathToString>::Dispatch(manager, instance, path, bufferCapacityInput, bufferCountOutput, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->PathToString(instance, path, bufferCapacityInput, bufferCountOutput, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrPathToString>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateActionSet>::PreLockReentrant(manager, instance, createInfo, actionSet);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateActionSet);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateActionSet>::Dispatch(manager, instance, createInfo, actionSet);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->CreateActionSet(instance, createInfo, actionSet);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateActionSet>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::InstanceWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::ActionSetWrapper>(instance, openxr_wrappers::NoParentWrapper::kHandleValue, actionSet, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyActionSet>::PreLockReentrant(manager, actionSet);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyActionSet);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyActionSet>::Dispatch(manager, actionSet);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(actionSet)->DestroyActionSet(actionSet);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyActionSet);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionSetWrapper>(actionSet);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::ActionSetWrapper>(actionSet);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyActionSet>::Dispatch(manager, result, actionSet);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::ActionSetWrapper>(actionSet);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateAction(
    XrActionSet                                 actionSet,
    const XrActionCreateInfo*                   createInfo,
    XrAction*                                   action)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateAction>::PreLockReentrant(manager, actionSet, createInfo, action);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrActionCreateInfo* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateAction);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateAction>::Dispatch(manager, actionSet, createInfo, action);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(actionSet)->CreateAction(actionSet, createInfo_unwrapped, action);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateAction>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::ActionSetWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::ActionWrapper>(actionSet, openxr_wrappers::NoParentWrapper::kHandleValue, action, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyAction>::PreLockReentrant(manager, action);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyAction);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyAction>::Dispatch(manager, action);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(action)->DestroyAction(action);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyAction);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::ActionWrapper>(action);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::ActionWrapper>(action);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyAction>::Dispatch(manager, result, action);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::ActionWrapper>(action);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrSuggestInteractionProfileBindings(
    XrInstance                                  instance,
    const XrInteractionProfileSuggestedBinding* suggestedBindings)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSuggestInteractionProfileBindings>::PreLockReentrant(manager, instance, suggestedBindings);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrInteractionProfileSuggestedBinding* suggestedBindings_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSuggestInteractionProfileBindings);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSuggestInteractionProfileBindings>::Dispatch(manager, instance, suggestedBindings);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        suggestedBindings_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(suggestedBindings, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->SuggestInteractionProfileBindings(instance, suggestedBindings_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrAttachSessionActionSets>::PreLockReentrant(manager, session, attachInfo);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSessionActionSetsAttachInfo* attachInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrAttachSessionActionSets);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrAttachSessionActionSets>::Dispatch(manager, session, attachInfo);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        attachInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(attachInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->AttachSessionActionSets(session, attachInfo_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetCurrentInteractionProfile>::PreLockReentrant(manager, session, topLevelUserPath, interactionProfile);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetCurrentInteractionProfile);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetCurrentInteractionProfile>::Dispatch(manager, session, topLevelUserPath, interactionProfile);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetCurrentInteractionProfile(session, topLevelUserPath, interactionProfile);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrGetCurrentInteractionProfile>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedStructHandles<openxr_wrappers::SessionWrapper, openxr_wrappers::PathWrapper>(session, topLevelUserPath, interactionProfile, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStateBoolean>::PreLockReentrant(manager, session, getInfo, state);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrActionStateGetInfo* getInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetActionStateBoolean);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStateBoolean>::Dispatch(manager, session, getInfo, state);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        getInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetActionStateBoolean(session, getInfo_unwrapped, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetActionStateBoolean>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStateFloat>::PreLockReentrant(manager, session, getInfo, state);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrActionStateGetInfo* getInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetActionStateFloat);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStateFloat>::Dispatch(manager, session, getInfo, state);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        getInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetActionStateFloat(session, getInfo_unwrapped, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetActionStateFloat>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStateVector2f>::PreLockReentrant(manager, session, getInfo, state);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrActionStateGetInfo* getInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetActionStateVector2f);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStateVector2f>::Dispatch(manager, session, getInfo, state);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        getInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetActionStateVector2f(session, getInfo_unwrapped, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetActionStateVector2f>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStatePose>::PreLockReentrant(manager, session, getInfo, state);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrActionStateGetInfo* getInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetActionStatePose);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetActionStatePose>::Dispatch(manager, session, getInfo, state);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        getInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetActionStatePose(session, getInfo_unwrapped, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetActionStatePose>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSyncActions>::PreLockReentrant(manager, session, syncInfo);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrActionsSyncInfo* syncInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSyncActions);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSyncActions>::Dispatch(manager, session, syncInfo);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        syncInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(syncInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SyncActions(session, syncInfo_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateBoundSourcesForAction>::PreLockReentrant(manager, session, enumerateInfo, sourceCapacityInput, sourceCountOutput, sources);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrBoundSourcesForActionEnumerateInfo* enumerateInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateBoundSourcesForAction);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateBoundSourcesForAction>::Dispatch(manager, session, enumerateInfo, sourceCapacityInput, sourceCountOutput, sources);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        enumerateInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(enumerateInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EnumerateBoundSourcesForAction(session, enumerateInfo_unwrapped, sourceCapacityInput, sourceCountOutput, sources);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateBoundSourcesForAction>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtoms<openxr_wrappers::SessionWrapper, openxr_wrappers::PathWrapper>(session, sources, sourceCapacityInput, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetInputSourceLocalizedName>::PreLockReentrant(manager, session, getInfo, bufferCapacityInput, bufferCountOutput, buffer);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrInputSourceLocalizedNameGetInfo* getInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetInputSourceLocalizedName);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetInputSourceLocalizedName>::Dispatch(manager, session, getInfo, bufferCapacityInput, bufferCountOutput, buffer);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        getInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetInputSourceLocalizedName(session, getInfo_unwrapped, bufferCapacityInput, bufferCountOutput, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetInputSourceLocalizedName>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrApplyHapticFeedback>::PreLockReentrant(manager, session, hapticActionInfo, hapticFeedback);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrHapticActionInfo* hapticActionInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrApplyHapticFeedback);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrApplyHapticFeedback>::Dispatch(manager, session, hapticActionInfo, hapticFeedback);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        hapticActionInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(hapticActionInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->ApplyHapticFeedback(session, hapticActionInfo_unwrapped, hapticFeedback);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStopHapticFeedback>::PreLockReentrant(manager, session, hapticActionInfo);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrHapticActionInfo* hapticActionInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrStopHapticFeedback);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStopHapticFeedback>::Dispatch(manager, session, hapticActionInfo);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        hapticActionInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(hapticActionInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->StopHapticFeedback(session, hapticActionInfo_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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

XRAPI_ATTR XrResult XRAPI_CALL xrCreateApiLayerInstance(
    const XrInstanceCreateInfo*                 info,
    const XrApiLayerCreateInfo*                 layerInfo,
    XrInstance*                                 instance)
{
    bool omit_output_data = false;

    auto api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateApiLayerInstance>::Dispatch(OpenXrCaptureManager::Get(), info, layerInfo, instance);
    XrResult result = OpenXrCaptureManager::OverrideCreateApiLayerInstance(info, layerInfo, instance);
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrCreateApiLayerInstance>::Succeeded (OpenXrCaptureManager::Get(), result);

    auto encoder = OpenXrCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateApiLayerInstance);
    if (encoder)
    {
        EncodeStructPtr(encoder, info);
        EncodeStructPtr(encoder, layerInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::InstanceWrapper>(instance, omit_output_data);
        encoder->EncodeEnumValue(result);
        OpenXrCaptureManager::Get()->EndCreateApiCallCapture<const void*, openxr_wrappers::InstanceWrapper, XrApiLayerCreateInfo>(result, nullptr, instance, layerInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateApiLayerInstance>::Dispatch(OpenXrCaptureManager::Get(), result, info, layerInfo, instance);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrLocateSpaces(
    XrSession                                   session,
    const XrSpacesLocateInfo*                   locateInfo,
    XrSpaceLocations*                           spaceLocations)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateSpaces>::PreLockReentrant(manager, session, locateInfo, spaceLocations);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpacesLocateInfo* locateInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrLocateSpaces);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateSpaces>::Dispatch(manager, session, locateInfo, spaceLocations);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        locateInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(locateInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->LocateSpaces(session, locateInfo_unwrapped, spaceLocations);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrLocateSpaces>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrLocateSpaces);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, locateInfo);
        EncodeStructPtr(encoder, spaceLocations, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrLocateSpaces>::Dispatch(manager, result, session, locateInfo, spaceLocations);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrSetAndroidApplicationThreadKHR(
    XrSession                                   session,
    XrAndroidThreadTypeKHR                      threadType,
    uint32_t                                    threadId)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetAndroidApplicationThreadKHR>::PreLockReentrant(manager, session, threadType, threadId);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetAndroidApplicationThreadKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetAndroidApplicationThreadKHR>::Dispatch(manager, session, threadType, threadId);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetAndroidApplicationThreadKHR(session, threadType, threadId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR>::PreLockReentrant(manager, session, info, swapchain, surface);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR>::Dispatch(manager, session, info, swapchain, surface);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSwapchainAndroidSurfaceKHR(session, info, swapchain, surface);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSwapchainAndroidSurfaceKHR>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SwapchainWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, swapchain, OpenXrCaptureManager::GetUniqueId);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetOpenGLGraphicsRequirementsKHR>::PreLockReentrant(manager, instance, systemId, graphicsRequirements);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetOpenGLGraphicsRequirementsKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetOpenGLGraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetOpenGLGraphicsRequirementsKHR(instance, systemId, graphicsRequirements);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetOpenGLGraphicsRequirementsKHR>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetOpenGLESGraphicsRequirementsKHR>::PreLockReentrant(manager, instance, systemId, graphicsRequirements);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetOpenGLESGraphicsRequirementsKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetOpenGLESGraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetOpenGLESGraphicsRequirementsKHR(instance, systemId, graphicsRequirements);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetOpenGLESGraphicsRequirementsKHR>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanInstanceExtensionsKHR>::PreLockReentrant(manager, instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetVulkanInstanceExtensionsKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanInstanceExtensionsKHR>::Dispatch(manager, instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetVulkanInstanceExtensionsKHR(instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetVulkanInstanceExtensionsKHR>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanDeviceExtensionsKHR>::PreLockReentrant(manager, instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetVulkanDeviceExtensionsKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanDeviceExtensionsKHR>::Dispatch(manager, instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetVulkanDeviceExtensionsKHR(instance, systemId, bufferCapacityInput, bufferCountOutput, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetVulkanDeviceExtensionsKHR>::Succeeded (manager, result);

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

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsVulkanKHR*            graphicsRequirements)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirementsKHR>::PreLockReentrant(manager, instance, systemId, graphicsRequirements);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirementsKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetVulkanGraphicsRequirementsKHR(instance, systemId, graphicsRequirements);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirementsKHR>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetD3D11GraphicsRequirementsKHR>::PreLockReentrant(manager, instance, systemId, graphicsRequirements);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetD3D11GraphicsRequirementsKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetD3D11GraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetD3D11GraphicsRequirementsKHR(instance, systemId, graphicsRequirements);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetD3D11GraphicsRequirementsKHR>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetD3D12GraphicsRequirementsKHR>::PreLockReentrant(manager, instance, systemId, graphicsRequirements);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetD3D12GraphicsRequirementsKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetD3D12GraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetD3D12GraphicsRequirementsKHR(instance, systemId, graphicsRequirements);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetD3D12GraphicsRequirementsKHR>::Succeeded (manager, result);

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

XRAPI_ATTR XrResult XRAPI_CALL xrGetMetalGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsMetalKHR*             graphicsRequirements)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMetalGraphicsRequirementsKHR>::PreLockReentrant(manager, instance, systemId, graphicsRequirements);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetMetalGraphicsRequirementsKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMetalGraphicsRequirementsKHR>::Dispatch(manager, instance, systemId, graphicsRequirements);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetMetalGraphicsRequirementsKHR(instance, systemId, graphicsRequirements);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetMetalGraphicsRequirementsKHR>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetMetalGraphicsRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeOpenXrAtomValue<openxr_wrappers::SystemIdWrapper>(systemId);
        EncodeStructPtr(encoder, graphicsRequirements, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetMetalGraphicsRequirementsKHR>::Dispatch(manager, result, instance, systemId, graphicsRequirements);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVisibilityMaskKHR(
    XrSession                                   session,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewIndex,
    XrVisibilityMaskTypeKHR                     visibilityMaskType,
    XrVisibilityMaskKHR*                        visibilityMask)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVisibilityMaskKHR>::PreLockReentrant(manager, session, viewConfigurationType, viewIndex, visibilityMaskType, visibilityMask);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetVisibilityMaskKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVisibilityMaskKHR>::Dispatch(manager, session, viewConfigurationType, viewIndex, visibilityMaskType, visibilityMask);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetVisibilityMaskKHR(session, viewConfigurationType, viewIndex, visibilityMaskType, visibilityMask);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetVisibilityMaskKHR>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR>::PreLockReentrant(manager, instance, performanceCounter, time);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR>::Dispatch(manager, instance, performanceCounter, time);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->ConvertWin32PerformanceCounterToTimeKHR(instance, performanceCounter, time);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrConvertWin32PerformanceCounterToTimeKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeLARGE_INTEGERPtr(performanceCounter);
        encoder->EncodeXrTimePtr(time, omit_output_data);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR>::PreLockReentrant(manager, instance, time, performanceCounter);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR>::Dispatch(manager, instance, time, performanceCounter);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->ConvertTimeToWin32PerformanceCounterKHR(instance, time, performanceCounter);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrConvertTimeToWin32PerformanceCounterKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeXrTimeValue(time);
        encoder->EncodeLARGE_INTEGERPtr(performanceCounter, omit_output_data);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertTimespecTimeToTimeKHR>::PreLockReentrant(manager, instance, timespecTime, time);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrConvertTimespecTimeToTimeKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertTimespecTimeToTimeKHR>::Dispatch(manager, instance, timespecTime, time);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->ConvertTimespecTimeToTimeKHR(instance, timespecTime, time);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrConvertTimespecTimeToTimeKHR>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrConvertTimespecTimeToTimeKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, timespecTime);
        encoder->EncodeXrTimePtr(time, omit_output_data);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR>::PreLockReentrant(manager, instance, time, timespecTime);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR>::Dispatch(manager, instance, time, timespecTime);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->ConvertTimeToTimespecTimeKHR(instance, time, timespecTime);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        encoder->EncodeXrTimeValue(time);
        EncodeStructPtr(encoder, timespecTime, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrConvertTimeToTimespecTimeKHR>::Dispatch(manager, result, instance, time, timespecTime);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsRequirements2KHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsVulkanKHR*            graphicsRequirements)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirements2KHR>::PreLockReentrant(manager, instance, systemId, graphicsRequirements);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirements2KHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirements2KHR>::Dispatch(manager, instance, systemId, graphicsRequirements);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetVulkanGraphicsRequirements2KHR(instance, systemId, graphicsRequirements);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetVulkanGraphicsRequirements2KHR>::Succeeded (manager, result);

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

XRAPI_ATTR XrResult XRAPI_CALL xrLocateSpacesKHR(
    XrSession                                   session,
    const XrSpacesLocateInfo*                   locateInfo,
    XrSpaceLocations*                           spaceLocations)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateSpacesKHR>::PreLockReentrant(manager, session, locateInfo, spaceLocations);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpacesLocateInfo* locateInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrLocateSpacesKHR);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateSpacesKHR>::Dispatch(manager, session, locateInfo, spaceLocations);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        locateInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(locateInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->LocateSpacesKHR(session, locateInfo_unwrapped, spaceLocations);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrLocateSpacesKHR>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrLocateSpacesKHR);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, locateInfo);
        EncodeStructPtr(encoder, spaceLocations, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrLocateSpacesKHR>::Dispatch(manager, result, session, locateInfo, spaceLocations);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrPerfSettingsSetPerformanceLevelEXT(
    XrSession                                   session,
    XrPerfSettingsDomainEXT                     domain,
    XrPerfSettingsLevelEXT                      level)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPerfSettingsSetPerformanceLevelEXT>::PreLockReentrant(manager, session, domain, level);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPerfSettingsSetPerformanceLevelEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPerfSettingsSetPerformanceLevelEXT>::Dispatch(manager, session, domain, level);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->PerfSettingsSetPerformanceLevelEXT(session, domain, level);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrThermalGetTemperatureTrendEXT>::PreLockReentrant(manager, session, domain, notificationLevel, tempHeadroom, tempSlope);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrThermalGetTemperatureTrendEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrThermalGetTemperatureTrendEXT>::Dispatch(manager, session, domain, notificationLevel, tempHeadroom, tempSlope);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->ThermalGetTemperatureTrendEXT(session, domain, notificationLevel, tempHeadroom, tempSlope);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrThermalGetTemperatureTrendEXT>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetDebugUtilsObjectNameEXT>::PreLockReentrant(manager, instance, nameInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetDebugUtilsObjectNameEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetDebugUtilsObjectNameEXT>::Dispatch(manager, instance, nameInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->SetDebugUtilsObjectNameEXT(instance, nameInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateDebugUtilsMessengerEXT>::PreLockReentrant(manager, instance, createInfo, messenger);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateDebugUtilsMessengerEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateDebugUtilsMessengerEXT>::Dispatch(manager, instance, createInfo, messenger);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->CreateDebugUtilsMessengerEXT(instance, createInfo, messenger);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateDebugUtilsMessengerEXT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::InstanceWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::DebugUtilsMessengerEXTWrapper>(instance, openxr_wrappers::NoParentWrapper::kHandleValue, messenger, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyDebugUtilsMessengerEXT>::PreLockReentrant(manager, messenger);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyDebugUtilsMessengerEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyDebugUtilsMessengerEXT>::Dispatch(manager, messenger);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(messenger)->DestroyDebugUtilsMessengerEXT(messenger);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(messenger);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(messenger);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyDebugUtilsMessengerEXT>::Dispatch(manager, result, messenger);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::DebugUtilsMessengerEXTWrapper>(messenger);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSubmitDebugUtilsMessageEXT>::PreLockReentrant(manager, instance, messageSeverity, messageTypes, callbackData);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSubmitDebugUtilsMessageEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSubmitDebugUtilsMessageEXT>::Dispatch(manager, instance, messageSeverity, messageTypes, callbackData);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, callbackData);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSessionBeginDebugUtilsLabelRegionEXT>::PreLockReentrant(manager, session, labelInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSessionBeginDebugUtilsLabelRegionEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSessionBeginDebugUtilsLabelRegionEXT>::Dispatch(manager, session, labelInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SessionBeginDebugUtilsLabelRegionEXT(session, labelInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSessionEndDebugUtilsLabelRegionEXT>::PreLockReentrant(manager, session);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSessionEndDebugUtilsLabelRegionEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSessionEndDebugUtilsLabelRegionEXT>::Dispatch(manager, session);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SessionEndDebugUtilsLabelRegionEXT(session);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSessionInsertDebugUtilsLabelEXT>::PreLockReentrant(manager, session, labelInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSessionInsertDebugUtilsLabelEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSessionInsertDebugUtilsLabelEXT>::Dispatch(manager, session, labelInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SessionInsertDebugUtilsLabelEXT(session, labelInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorMSFT>::PreLockReentrant(manager, session, createInfo, anchor);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpatialAnchorCreateInfoMSFT* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSpatialAnchorMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorMSFT>::Dispatch(manager, session, createInfo, anchor);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSpatialAnchorMSFT(session, createInfo_unwrapped, anchor);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSpatialAnchorMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpatialAnchorMSFTWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, anchor, OpenXrCaptureManager::GetUniqueId);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorSpaceMSFT>::PreLockReentrant(manager, session, createInfo, space);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpatialAnchorSpaceCreateInfoMSFT* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSpatialAnchorSpaceMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorSpaceMSFT>::Dispatch(manager, session, createInfo, space);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSpatialAnchorSpaceMSFT(session, createInfo_unwrapped, space);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSpatialAnchorSpaceMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpatialAnchorMSFT>::PreLockReentrant(manager, anchor);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroySpatialAnchorMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpatialAnchorMSFT>::Dispatch(manager, anchor);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(anchor)->DestroySpatialAnchorMSFT(anchor);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySpatialAnchorMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorMSFTWrapper>(anchor);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SpatialAnchorMSFTWrapper>(anchor);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySpatialAnchorMSFT>::Dispatch(manager, result, anchor);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::SpatialAnchorMSFTWrapper>(anchor);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceActiveEXT>::PreLockReentrant(manager, session, interactionProfile, topLevelPath, isActive);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetInputDeviceActiveEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceActiveEXT>::Dispatch(manager, session, interactionProfile, topLevelPath, isActive);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetInputDeviceActiveEXT(session, interactionProfile, topLevelPath, isActive);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateBoolEXT>::PreLockReentrant(manager, session, topLevelPath, inputSourcePath, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetInputDeviceStateBoolEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateBoolEXT>::Dispatch(manager, session, topLevelPath, inputSourcePath, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetInputDeviceStateBoolEXT(session, topLevelPath, inputSourcePath, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateFloatEXT>::PreLockReentrant(manager, session, topLevelPath, inputSourcePath, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetInputDeviceStateFloatEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateFloatEXT>::Dispatch(manager, session, topLevelPath, inputSourcePath, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetInputDeviceStateFloatEXT(session, topLevelPath, inputSourcePath, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateVector2fEXT>::PreLockReentrant(manager, session, topLevelPath, inputSourcePath, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetInputDeviceStateVector2fEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceStateVector2fEXT>::Dispatch(manager, session, topLevelPath, inputSourcePath, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetInputDeviceStateVector2fEXT(session, topLevelPath, inputSourcePath, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceLocationEXT>::PreLockReentrant(manager, session, topLevelPath, inputSourcePath, space, pose);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetInputDeviceLocationEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetInputDeviceLocationEXT>::Dispatch(manager, session, topLevelPath, inputSourcePath, space, pose);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetInputDeviceLocationEXT(session, topLevelPath, inputSourcePath, space, pose);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialGraphNodeSpaceMSFT>::PreLockReentrant(manager, session, createInfo, space);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSpatialGraphNodeSpaceMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialGraphNodeSpaceMSFT>::Dispatch(manager, session, createInfo, space);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSpatialGraphNodeSpaceMSFT(session, createInfo, space);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSpatialGraphNodeSpaceMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT>::PreLockReentrant(manager, session, createInfo, nodeBinding);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpatialGraphStaticNodeBindingCreateInfoMSFT* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT>::Dispatch(manager, session, createInfo, nodeBinding);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->TryCreateSpatialGraphStaticNodeBindingMSFT(session, createInfo_unwrapped, nodeBinding);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrTryCreateSpatialGraphStaticNodeBindingMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, nodeBinding, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpatialGraphNodeBindingMSFT>::PreLockReentrant(manager, nodeBinding);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroySpatialGraphNodeBindingMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpatialGraphNodeBindingMSFT>::Dispatch(manager, nodeBinding);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(nodeBinding)->DestroySpatialGraphNodeBindingMSFT(nodeBinding);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySpatialGraphNodeBindingMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(nodeBinding);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(nodeBinding);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySpatialGraphNodeBindingMSFT>::Dispatch(manager, result, nodeBinding);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::SpatialGraphNodeBindingMSFTWrapper>(nodeBinding);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpatialGraphNodeBindingPropertiesMSFT(
    XrSpatialGraphNodeBindingMSFT               nodeBinding,
    const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* getInfo,
    XrSpatialGraphNodeBindingPropertiesMSFT*    properties)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT>::PreLockReentrant(manager, nodeBinding, getInfo, properties);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT>::Dispatch(manager, nodeBinding, getInfo, properties);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(nodeBinding)->GetSpatialGraphNodeBindingPropertiesMSFT(nodeBinding, getInfo, properties);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpatialGraphNodeBindingPropertiesMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateHandTrackerEXT>::PreLockReentrant(manager, session, createInfo, handTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateHandTrackerEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateHandTrackerEXT>::Dispatch(manager, session, createInfo, handTracker);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateHandTrackerEXT(session, createInfo, handTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateHandTrackerEXT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::HandTrackerEXTWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, handTracker, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyHandTrackerEXT>::PreLockReentrant(manager, handTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyHandTrackerEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyHandTrackerEXT>::Dispatch(manager, handTracker);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(handTracker)->DestroyHandTrackerEXT(handTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyHandTrackerEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyHandTrackerEXT>::Dispatch(manager, result, handTracker);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::HandTrackerEXTWrapper>(handTracker);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrLocateHandJointsEXT(
    XrHandTrackerEXT                            handTracker,
    const XrHandJointsLocateInfoEXT*            locateInfo,
    XrHandJointLocationsEXT*                    locations)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateHandJointsEXT>::PreLockReentrant(manager, handTracker, locateInfo, locations);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrHandJointsLocateInfoEXT* locateInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrLocateHandJointsEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateHandJointsEXT>::Dispatch(manager, handTracker, locateInfo, locations);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        locateInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(locateInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(handTracker)->LocateHandJointsEXT(handTracker, locateInfo_unwrapped, locations);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrLocateHandJointsEXT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateHandMeshSpaceMSFT>::PreLockReentrant(manager, handTracker, createInfo, space);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateHandMeshSpaceMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateHandMeshSpaceMSFT>::Dispatch(manager, handTracker, createInfo, space);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(handTracker)->CreateHandMeshSpaceMSFT(handTracker, createInfo, space);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateHandMeshSpaceMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::HandTrackerEXTWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceWrapper>(handTracker, openxr_wrappers::NoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUpdateHandMeshMSFT>::PreLockReentrant(manager, handTracker, updateInfo, handMesh);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrUpdateHandMeshMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUpdateHandMeshMSFT>::Dispatch(manager, handTracker, updateInfo, handMesh);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(handTracker)->UpdateHandMeshMSFT(handTracker, updateInfo, handMesh);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrUpdateHandMeshMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetControllerModelKeyMSFT>::PreLockReentrant(manager, session, topLevelUserPath, controllerModelKeyState);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetControllerModelKeyMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetControllerModelKeyMSFT>::Dispatch(manager, session, topLevelUserPath, controllerModelKeyState);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetControllerModelKeyMSFT(session, topLevelUserPath, controllerModelKeyState);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrGetControllerModelKeyMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedStructHandles<openxr_wrappers::SessionWrapper, openxr_wrappers::PathWrapper>(session, topLevelUserPath, controllerModelKeyState, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLoadControllerModelMSFT>::PreLockReentrant(manager, session, modelKey, bufferCapacityInput, bufferCountOutput, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrLoadControllerModelMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLoadControllerModelMSFT>::Dispatch(manager, session, modelKey, bufferCapacityInput, bufferCountOutput, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->LoadControllerModelMSFT(session, modelKey, bufferCapacityInput, bufferCountOutput, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrLoadControllerModelMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetControllerModelPropertiesMSFT>::PreLockReentrant(manager, session, modelKey, properties);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetControllerModelPropertiesMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetControllerModelPropertiesMSFT>::Dispatch(manager, session, modelKey, properties);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetControllerModelPropertiesMSFT(session, modelKey, properties);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetControllerModelPropertiesMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetControllerModelStateMSFT>::PreLockReentrant(manager, session, modelKey, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetControllerModelStateMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetControllerModelStateMSFT>::Dispatch(manager, session, modelKey, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetControllerModelStateMSFT(session, modelKey, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetControllerModelStateMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT>::PreLockReentrant(manager, session, perceptionAnchor, anchor);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT>::Dispatch(manager, session, perceptionAnchor, anchor);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSpatialAnchorFromPerceptionAnchorMSFT(session, perceptionAnchor, anchor);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpatialAnchorMSFTWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, anchor, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPerceptionAnchorMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeVoidPtr(perceptionAnchor);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT>::PreLockReentrant(manager, session, anchor, perceptionAnchor);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT>::Dispatch(manager, session, anchor, perceptionAnchor);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->TryGetPerceptionAnchorFromSpatialAnchorMSFT(session, anchor, perceptionAnchor);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorMSFTWrapper>(anchor);
        encoder->EncodeVoidPtrPtr(perceptionAnchor, omit_output_data);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateReprojectionModesMSFT>::PreLockReentrant(manager, instance, systemId, viewConfigurationType, modeCapacityInput, modeCountOutput, modes);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateReprojectionModesMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateReprojectionModesMSFT>::Dispatch(manager, instance, systemId, viewConfigurationType, modeCapacityInput, modeCountOutput, modes);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->EnumerateReprojectionModesMSFT(instance, systemId, viewConfigurationType, modeCapacityInput, modeCountOutput, modes);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateReprojectionModesMSFT>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUpdateSwapchainFB>::PreLockReentrant(manager, swapchain, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrUpdateSwapchainFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUpdateSwapchainFB>::Dispatch(manager, swapchain, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(swapchain)->UpdateSwapchainFB(swapchain, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSwapchainStateFB>::PreLockReentrant(manager, swapchain, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSwapchainStateFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSwapchainStateFB>::Dispatch(manager, swapchain, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(swapchain)->GetSwapchainStateFB(swapchain, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSwapchainStateFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateBodyTrackerFB>::PreLockReentrant(manager, session, createInfo, bodyTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateBodyTrackerFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateBodyTrackerFB>::Dispatch(manager, session, createInfo, bodyTracker);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateBodyTrackerFB(session, createInfo, bodyTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateBodyTrackerFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::BodyTrackerFBWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, bodyTracker, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyBodyTrackerFB>::PreLockReentrant(manager, bodyTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyBodyTrackerFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyBodyTrackerFB>::Dispatch(manager, bodyTracker);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(bodyTracker)->DestroyBodyTrackerFB(bodyTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyBodyTrackerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::BodyTrackerFBWrapper>(bodyTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::BodyTrackerFBWrapper>(bodyTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyBodyTrackerFB>::Dispatch(manager, result, bodyTracker);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::BodyTrackerFBWrapper>(bodyTracker);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrLocateBodyJointsFB(
    XrBodyTrackerFB                             bodyTracker,
    const XrBodyJointsLocateInfoFB*             locateInfo,
    XrBodyJointLocationsFB*                     locations)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateBodyJointsFB>::PreLockReentrant(manager, bodyTracker, locateInfo, locations);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrBodyJointsLocateInfoFB* locateInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrLocateBodyJointsFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateBodyJointsFB>::Dispatch(manager, bodyTracker, locateInfo, locations);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        locateInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(locateInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(bodyTracker)->LocateBodyJointsFB(bodyTracker, locateInfo_unwrapped, locations);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrLocateBodyJointsFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetBodySkeletonFB>::PreLockReentrant(manager, bodyTracker, skeleton);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetBodySkeletonFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetBodySkeletonFB>::Dispatch(manager, bodyTracker, skeleton);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(bodyTracker)->GetBodySkeletonFB(bodyTracker, skeleton);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetBodySkeletonFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSceneComputeFeaturesMSFT>::PreLockReentrant(manager, instance, systemId, featureCapacityInput, featureCountOutput, features);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateSceneComputeFeaturesMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSceneComputeFeaturesMSFT>::Dispatch(manager, instance, systemId, featureCapacityInput, featureCountOutput, features);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->EnumerateSceneComputeFeaturesMSFT(instance, systemId, featureCapacityInput, featureCountOutput, features);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateSceneComputeFeaturesMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSceneObserverMSFT>::PreLockReentrant(manager, session, createInfo, sceneObserver);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSceneObserverMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSceneObserverMSFT>::Dispatch(manager, session, createInfo, sceneObserver);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSceneObserverMSFT(session, createInfo, sceneObserver);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSceneObserverMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SceneObserverMSFTWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, sceneObserver, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySceneObserverMSFT>::PreLockReentrant(manager, sceneObserver);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroySceneObserverMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySceneObserverMSFT>::Dispatch(manager, sceneObserver);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(sceneObserver)->DestroySceneObserverMSFT(sceneObserver);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySceneObserverMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySceneObserverMSFT>::Dispatch(manager, result, sceneObserver);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::SceneObserverMSFTWrapper>(sceneObserver);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrSceneCreateInfoMSFT*                createInfo,
    XrSceneMSFT*                                scene)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSceneMSFT>::PreLockReentrant(manager, sceneObserver, createInfo, scene);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSceneMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSceneMSFT>::Dispatch(manager, sceneObserver, createInfo, scene);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(sceneObserver)->CreateSceneMSFT(sceneObserver, createInfo, scene);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSceneMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SceneObserverMSFTWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SceneMSFTWrapper>(sceneObserver, openxr_wrappers::NoParentWrapper::kHandleValue, scene, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySceneMSFT>::PreLockReentrant(manager, scene);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroySceneMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySceneMSFT>::Dispatch(manager, scene);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(scene)->DestroySceneMSFT(scene);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySceneMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SceneMSFTWrapper>(scene);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SceneMSFTWrapper>(scene);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySceneMSFT>::Dispatch(manager, result, scene);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::SceneMSFTWrapper>(scene);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrComputeNewSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrNewSceneComputeInfoMSFT*            computeInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrComputeNewSceneMSFT>::PreLockReentrant(manager, sceneObserver, computeInfo);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrNewSceneComputeInfoMSFT* computeInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrComputeNewSceneMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrComputeNewSceneMSFT>::Dispatch(manager, sceneObserver, computeInfo);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        computeInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(computeInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(sceneObserver)->ComputeNewSceneMSFT(sceneObserver, computeInfo_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneComputeStateMSFT>::PreLockReentrant(manager, sceneObserver, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSceneComputeStateMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneComputeStateMSFT>::Dispatch(manager, sceneObserver, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(sceneObserver)->GetSceneComputeStateMSFT(sceneObserver, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSceneComputeStateMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneComponentsMSFT>::PreLockReentrant(manager, scene, getInfo, components);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSceneComponentsMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneComponentsMSFT>::Dispatch(manager, scene, getInfo, components);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(scene)->GetSceneComponentsMSFT(scene, getInfo, components);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSceneComponentsMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateSceneComponentsMSFT>::PreLockReentrant(manager, scene, locateInfo, locations);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSceneComponentsLocateInfoMSFT* locateInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrLocateSceneComponentsMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLocateSceneComponentsMSFT>::Dispatch(manager, scene, locateInfo, locations);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        locateInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(locateInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(scene)->LocateSceneComponentsMSFT(scene, locateInfo_unwrapped, locations);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrLocateSceneComponentsMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneMeshBuffersMSFT>::PreLockReentrant(manager, scene, getInfo, buffers);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSceneMeshBuffersMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneMeshBuffersMSFT>::Dispatch(manager, scene, getInfo, buffers);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(scene)->GetSceneMeshBuffersMSFT(scene, getInfo, buffers);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSceneMeshBuffersMSFT>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDeserializeSceneMSFT>::PreLockReentrant(manager, sceneObserver, deserializeInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDeserializeSceneMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDeserializeSceneMSFT>::Dispatch(manager, sceneObserver, deserializeInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(sceneObserver)->DeserializeSceneMSFT(sceneObserver, deserializeInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSerializedSceneFragmentDataMSFT>::PreLockReentrant(manager, scene, getInfo, countInput, readOutput, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSerializedSceneFragmentDataMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSerializedSceneFragmentDataMSFT>::Dispatch(manager, scene, getInfo, countInput, readOutput, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(scene)->GetSerializedSceneFragmentDataMSFT(scene, getInfo, countInput, readOutput, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSerializedSceneFragmentDataMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateDisplayRefreshRatesFB>::PreLockReentrant(manager, session, displayRefreshRateCapacityInput, displayRefreshRateCountOutput, displayRefreshRates);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateDisplayRefreshRatesFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateDisplayRefreshRatesFB>::Dispatch(manager, session, displayRefreshRateCapacityInput, displayRefreshRateCountOutput, displayRefreshRates);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EnumerateDisplayRefreshRatesFB(session, displayRefreshRateCapacityInput, displayRefreshRateCountOutput, displayRefreshRates);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateDisplayRefreshRatesFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetDisplayRefreshRateFB>::PreLockReentrant(manager, session, displayRefreshRate);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetDisplayRefreshRateFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetDisplayRefreshRateFB>::Dispatch(manager, session, displayRefreshRate);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetDisplayRefreshRateFB(session, displayRefreshRate);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetDisplayRefreshRateFB>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestDisplayRefreshRateFB>::PreLockReentrant(manager, session, displayRefreshRate);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrRequestDisplayRefreshRateFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestDisplayRefreshRateFB>::Dispatch(manager, session, displayRefreshRate);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->RequestDisplayRefreshRateFB(session, displayRefreshRate);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateViveTrackerPathsHTCX>::PreLockReentrant(manager, instance, pathCapacityInput, pathCountOutput, paths);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateViveTrackerPathsHTCX);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateViveTrackerPathsHTCX>::Dispatch(manager, instance, pathCapacityInput, pathCountOutput, paths);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->EnumerateViveTrackerPathsHTCX(instance, pathCapacityInput, pathCountOutput, paths);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateViveTrackerPathsHTCX>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedStructArrayHandles<openxr_wrappers::InstanceWrapper, openxr_wrappers::NoParentWrapper, XrViveTrackerPathsHTCX>(instance, openxr_wrappers::NoParentWrapper::kHandleValue, paths, pathCapacityInput, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFacialTrackerHTC>::PreLockReentrant(manager, session, createInfo, facialTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateFacialTrackerHTC);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFacialTrackerHTC>::Dispatch(manager, session, createInfo, facialTracker);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateFacialTrackerHTC(session, createInfo, facialTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateFacialTrackerHTC>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::FacialTrackerHTCWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, facialTracker, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFacialTrackerHTC>::PreLockReentrant(manager, facialTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyFacialTrackerHTC);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFacialTrackerHTC>::Dispatch(manager, facialTracker);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(facialTracker)->DestroyFacialTrackerHTC(facialTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyFacialTrackerHTC);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FacialTrackerHTCWrapper>(facialTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::FacialTrackerHTCWrapper>(facialTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyFacialTrackerHTC>::Dispatch(manager, result, facialTracker);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::FacialTrackerHTCWrapper>(facialTracker);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetFacialExpressionsHTC(
    XrFacialTrackerHTC                          facialTracker,
    XrFacialExpressionsHTC*                     facialExpressions)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFacialExpressionsHTC>::PreLockReentrant(manager, facialTracker, facialExpressions);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetFacialExpressionsHTC);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFacialExpressionsHTC>::Dispatch(manager, facialTracker, facialExpressions);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(facialTracker)->GetFacialExpressionsHTC(facialTracker, facialExpressions);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetFacialExpressionsHTC>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateColorSpacesFB>::PreLockReentrant(manager, session, colorSpaceCapacityInput, colorSpaceCountOutput, colorSpaces);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateColorSpacesFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateColorSpacesFB>::Dispatch(manager, session, colorSpaceCapacityInput, colorSpaceCountOutput, colorSpaces);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EnumerateColorSpacesFB(session, colorSpaceCapacityInput, colorSpaceCountOutput, colorSpaces);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateColorSpacesFB>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetColorSpaceFB>::PreLockReentrant(manager, session, colorSpace);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetColorSpaceFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetColorSpaceFB>::Dispatch(manager, session, colorSpace);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetColorSpaceFB(session, colorSpace);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetHandMeshFB>::PreLockReentrant(manager, handTracker, mesh);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetHandMeshFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetHandMeshFB>::Dispatch(manager, handTracker, mesh);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(handTracker)->GetHandMeshFB(handTracker, mesh);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetHandMeshFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFB>::PreLockReentrant(manager, session, info, requestId);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpatialAnchorCreateInfoFB* info_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSpatialAnchorFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFB>::Dispatch(manager, session, info, requestId);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        info_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(info, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSpatialAnchorFB(session, info_unwrapped, requestId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtom<openxr_wrappers::SessionWrapper, openxr_wrappers::AsyncRequestIdFBWrapper>(session, requestId, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceUuidFB>::PreLockReentrant(manager, space, uuid);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpaceUuidFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceUuidFB>::Dispatch(manager, space, uuid);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(space)->GetSpaceUuidFB(space, uuid);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpaceUuidFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSpaceSupportedComponentsFB>::PreLockReentrant(manager, space, componentTypeCapacityInput, componentTypeCountOutput, componentTypes);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateSpaceSupportedComponentsFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateSpaceSupportedComponentsFB>::Dispatch(manager, space, componentTypeCapacityInput, componentTypeCountOutput, componentTypes);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(space)->EnumerateSpaceSupportedComponentsFB(space, componentTypeCapacityInput, componentTypeCountOutput, componentTypes);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateSpaceSupportedComponentsFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetSpaceComponentStatusFB>::PreLockReentrant(manager, space, info, requestId);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetSpaceComponentStatusFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetSpaceComponentStatusFB>::Dispatch(manager, space, info, requestId);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(space)->SetSpaceComponentStatusFB(space, info, requestId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrSetSpaceComponentStatusFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtom<openxr_wrappers::SpaceWrapper, openxr_wrappers::AsyncRequestIdFBWrapper>(space, requestId, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceComponentStatusFB>::PreLockReentrant(manager, space, componentType, status);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpaceComponentStatusFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceComponentStatusFB>::Dispatch(manager, space, componentType, status);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(space)->GetSpaceComponentStatusFB(space, componentType, status);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpaceComponentStatusFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFoveationProfileFB>::PreLockReentrant(manager, session, createInfo, profile);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateFoveationProfileFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFoveationProfileFB>::Dispatch(manager, session, createInfo, profile);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateFoveationProfileFB(session, createInfo, profile);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateFoveationProfileFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::FoveationProfileFBWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, profile, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFoveationProfileFB>::PreLockReentrant(manager, profile);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyFoveationProfileFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFoveationProfileFB>::Dispatch(manager, profile);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(profile)->DestroyFoveationProfileFB(profile);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyFoveationProfileFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FoveationProfileFBWrapper>(profile);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::FoveationProfileFBWrapper>(profile);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyFoveationProfileFB>::Dispatch(manager, result, profile);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::FoveationProfileFBWrapper>(profile);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrQuerySystemTrackedKeyboardFB(
    XrSession                                   session,
    const XrKeyboardTrackingQueryFB*            queryInfo,
    XrKeyboardTrackingDescriptionFB*            keyboard)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQuerySystemTrackedKeyboardFB>::PreLockReentrant(manager, session, queryInfo, keyboard);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrQuerySystemTrackedKeyboardFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQuerySystemTrackedKeyboardFB>::Dispatch(manager, session, queryInfo, keyboard);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->QuerySystemTrackedKeyboardFB(session, queryInfo, keyboard);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrQuerySystemTrackedKeyboardFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateKeyboardSpaceFB>::PreLockReentrant(manager, session, createInfo, keyboardSpace);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateKeyboardSpaceFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateKeyboardSpaceFB>::Dispatch(manager, session, createInfo, keyboardSpace);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateKeyboardSpaceFB(session, createInfo, keyboardSpace);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateKeyboardSpaceFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, keyboardSpace, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshBeginUpdateFB>::PreLockReentrant(manager, mesh);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrTriangleMeshBeginUpdateFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshBeginUpdateFB>::Dispatch(manager, mesh);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(mesh)->TriangleMeshBeginUpdateFB(mesh);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshEndUpdateFB>::PreLockReentrant(manager, mesh, vertexCount, triangleCount);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrTriangleMeshEndUpdateFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshEndUpdateFB>::Dispatch(manager, mesh, vertexCount, triangleCount);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(mesh)->TriangleMeshEndUpdateFB(mesh, vertexCount, triangleCount);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB>::PreLockReentrant(manager, mesh, outVertexCount);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB>::Dispatch(manager, mesh, outVertexCount);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(mesh)->TriangleMeshBeginVertexBufferUpdateFB(mesh, outVertexCount);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrTriangleMeshBeginVertexBufferUpdateFB>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshEndVertexBufferUpdateFB>::PreLockReentrant(manager, mesh);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrTriangleMeshEndVertexBufferUpdateFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshEndVertexBufferUpdateFB>::Dispatch(manager, mesh);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(mesh)->TriangleMeshEndVertexBufferUpdateFB(mesh);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughFB>::PreLockReentrant(manager, session, createInfo, outPassthrough);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreatePassthroughFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughFB>::Dispatch(manager, session, createInfo, outPassthrough);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreatePassthroughFB(session, createInfo, outPassthrough);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreatePassthroughFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::PassthroughFBWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, outPassthrough, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughFB>::PreLockReentrant(manager, passthrough);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyPassthroughFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughFB>::Dispatch(manager, passthrough);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(passthrough)->DestroyPassthroughFB(passthrough);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyPassthroughFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughFBWrapper>(passthrough);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::PassthroughFBWrapper>(passthrough);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyPassthroughFB>::Dispatch(manager, result, passthrough);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::PassthroughFBWrapper>(passthrough);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughStartFB(
    XrPassthroughFB                             passthrough)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughStartFB>::PreLockReentrant(manager, passthrough);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPassthroughStartFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughStartFB>::Dispatch(manager, passthrough);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(passthrough)->PassthroughStartFB(passthrough);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughPauseFB>::PreLockReentrant(manager, passthrough);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPassthroughPauseFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughPauseFB>::Dispatch(manager, passthrough);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(passthrough)->PassthroughPauseFB(passthrough);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughLayerFB>::PreLockReentrant(manager, session, createInfo, outLayer);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrPassthroughLayerCreateInfoFB* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreatePassthroughLayerFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughLayerFB>::Dispatch(manager, session, createInfo, outLayer);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreatePassthroughLayerFB(session, createInfo_unwrapped, outLayer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreatePassthroughLayerFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::PassthroughLayerFBWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, outLayer, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughLayerFB>::PreLockReentrant(manager, layer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyPassthroughLayerFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughLayerFB>::Dispatch(manager, layer);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(layer)->DestroyPassthroughLayerFB(layer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyPassthroughLayerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughLayerFBWrapper>(layer);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::PassthroughLayerFBWrapper>(layer);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyPassthroughLayerFB>::Dispatch(manager, result, layer);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::PassthroughLayerFBWrapper>(layer);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerPauseFB(
    XrPassthroughLayerFB                        layer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerPauseFB>::PreLockReentrant(manager, layer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPassthroughLayerPauseFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerPauseFB>::Dispatch(manager, layer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(layer)->PassthroughLayerPauseFB(layer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerResumeFB>::PreLockReentrant(manager, layer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPassthroughLayerResumeFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerResumeFB>::Dispatch(manager, layer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(layer)->PassthroughLayerResumeFB(layer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerSetStyleFB>::PreLockReentrant(manager, layer, style);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrPassthroughStyleFB* style_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPassthroughLayerSetStyleFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerSetStyleFB>::Dispatch(manager, layer, style);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        style_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(style, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(layer)->PassthroughLayerSetStyleFB(layer, style_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateGeometryInstanceFB>::PreLockReentrant(manager, session, createInfo, outGeometryInstance);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrGeometryInstanceCreateInfoFB* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateGeometryInstanceFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateGeometryInstanceFB>::Dispatch(manager, session, createInfo, outGeometryInstance);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateGeometryInstanceFB(session, createInfo_unwrapped, outGeometryInstance);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateGeometryInstanceFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::GeometryInstanceFBWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, outGeometryInstance, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyGeometryInstanceFB>::PreLockReentrant(manager, instance);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyGeometryInstanceFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyGeometryInstanceFB>::Dispatch(manager, instance);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(instance)->DestroyGeometryInstanceFB(instance);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyGeometryInstanceFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::GeometryInstanceFBWrapper>(instance);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::GeometryInstanceFBWrapper>(instance);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyGeometryInstanceFB>::Dispatch(manager, result, instance);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::GeometryInstanceFBWrapper>(instance);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGeometryInstanceSetTransformFB(
    XrGeometryInstanceFB                        instance,
    const XrGeometryInstanceTransformFB*        transformation)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGeometryInstanceSetTransformFB>::PreLockReentrant(manager, instance, transformation);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrGeometryInstanceTransformFB* transformation_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGeometryInstanceSetTransformFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGeometryInstanceSetTransformFB>::Dispatch(manager, instance, transformation);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        transformation_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(transformation, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GeometryInstanceSetTransformFB(instance, transformation_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateRenderModelPathsFB>::PreLockReentrant(manager, session, pathCapacityInput, pathCountOutput, paths);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateRenderModelPathsFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateRenderModelPathsFB>::Dispatch(manager, session, pathCapacityInput, pathCountOutput, paths);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EnumerateRenderModelPathsFB(session, pathCapacityInput, pathCountOutput, paths);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateRenderModelPathsFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedStructArrayHandles<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, XrRenderModelPathInfoFB>(session, openxr_wrappers::NoParentWrapper::kHandleValue, paths, pathCapacityInput, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetRenderModelPropertiesFB>::PreLockReentrant(manager, session, path, properties);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetRenderModelPropertiesFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetRenderModelPropertiesFB>::Dispatch(manager, session, path, properties);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetRenderModelPropertiesFB(session, path, properties);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrGetRenderModelPropertiesFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedStructHandles<openxr_wrappers::SessionWrapper, openxr_wrappers::PathWrapper>(session, path, properties, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLoadRenderModelFB>::PreLockReentrant(manager, session, info, buffer);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrRenderModelLoadInfoFB* info_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrLoadRenderModelFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrLoadRenderModelFB>::Dispatch(manager, session, info, buffer);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        info_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(info, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->LoadRenderModelFB(session, info_unwrapped, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrLoadRenderModelFB>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetEnvironmentDepthEstimationVARJO>::PreLockReentrant(manager, session, enabled);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetEnvironmentDepthEstimationVARJO);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetEnvironmentDepthEstimationVARJO>::Dispatch(manager, session, enabled);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetEnvironmentDepthEstimationVARJO(session, enabled);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingVARJO>::PreLockReentrant(manager, session, enabled);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetMarkerTrackingVARJO);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingVARJO>::Dispatch(manager, session, enabled);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetMarkerTrackingVARJO(session, enabled);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingTimeoutVARJO>::PreLockReentrant(manager, session, markerId, timeout);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetMarkerTrackingTimeoutVARJO);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingTimeoutVARJO>::Dispatch(manager, session, markerId, timeout);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetMarkerTrackingTimeoutVARJO(session, markerId, timeout);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingPredictionVARJO>::PreLockReentrant(manager, session, markerId, enable);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetMarkerTrackingPredictionVARJO);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetMarkerTrackingPredictionVARJO>::Dispatch(manager, session, markerId, enable);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetMarkerTrackingPredictionVARJO(session, markerId, enable);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerSizeVARJO>::PreLockReentrant(manager, session, markerId, size);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetMarkerSizeVARJO);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerSizeVARJO>::Dispatch(manager, session, markerId, size);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetMarkerSizeVARJO(session, markerId, size);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetMarkerSizeVARJO>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateMarkerSpaceVARJO>::PreLockReentrant(manager, session, createInfo, space);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateMarkerSpaceVARJO);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateMarkerSpaceVARJO>::Dispatch(manager, session, createInfo, space);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateMarkerSpaceVARJO(session, createInfo, space);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateMarkerSpaceVARJO>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetViewOffsetVARJO>::PreLockReentrant(manager, session, offset);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetViewOffsetVARJO);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetViewOffsetVARJO>::Dispatch(manager, session, offset);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetViewOffsetVARJO(session, offset);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpaceFromCoordinateFrameUIDML>::PreLockReentrant(manager, session, createInfo, space);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSpaceFromCoordinateFrameUIDML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpaceFromCoordinateFrameUIDML>::Dispatch(manager, session, createInfo, space);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSpaceFromCoordinateFrameUIDML(session, createInfo, space);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSpaceFromCoordinateFrameUIDML>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateMarkerDetectorML>::PreLockReentrant(manager, session, createInfo, markerDetector);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateMarkerDetectorML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateMarkerDetectorML>::Dispatch(manager, session, createInfo, markerDetector);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateMarkerDetectorML(session, createInfo, markerDetector);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateMarkerDetectorML>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::MarkerDetectorMLWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, markerDetector, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyMarkerDetectorML>::PreLockReentrant(manager, markerDetector);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyMarkerDetectorML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyMarkerDetectorML>::Dispatch(manager, markerDetector);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(markerDetector)->DestroyMarkerDetectorML(markerDetector);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyMarkerDetectorML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyMarkerDetectorML>::Dispatch(manager, result, markerDetector);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::MarkerDetectorMLWrapper>(markerDetector);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrSnapshotMarkerDetectorML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerDetectorSnapshotInfoML*             snapshotInfo)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSnapshotMarkerDetectorML>::PreLockReentrant(manager, markerDetector, snapshotInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSnapshotMarkerDetectorML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSnapshotMarkerDetectorML>::Dispatch(manager, markerDetector, snapshotInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(markerDetector)->SnapshotMarkerDetectorML(markerDetector, snapshotInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrSnapshotMarkerDetectorML>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerDetectorStateML>::PreLockReentrant(manager, markerDetector, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetMarkerDetectorStateML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerDetectorStateML>::Dispatch(manager, markerDetector, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(markerDetector)->GetMarkerDetectorStateML(markerDetector, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetMarkerDetectorStateML>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkersML>::PreLockReentrant(manager, markerDetector, markerCapacityInput, markerCountOutput, markers);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetMarkersML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkersML>::Dispatch(manager, markerDetector, markerCapacityInput, markerCountOutput, markers);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(markerDetector)->GetMarkersML(markerDetector, markerCapacityInput, markerCountOutput, markers);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrGetMarkersML>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtoms<openxr_wrappers::MarkerDetectorMLWrapper, openxr_wrappers::MarkerMLWrapper>(markerDetector, markers, markerCapacityInput, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerReprojectionErrorML>::PreLockReentrant(manager, markerDetector, marker, reprojectionErrorMeters);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetMarkerReprojectionErrorML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerReprojectionErrorML>::Dispatch(manager, markerDetector, marker, reprojectionErrorMeters);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(markerDetector)->GetMarkerReprojectionErrorML(markerDetector, marker, reprojectionErrorMeters);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetMarkerReprojectionErrorML>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerLengthML>::PreLockReentrant(manager, markerDetector, marker, meters);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetMarkerLengthML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerLengthML>::Dispatch(manager, markerDetector, marker, meters);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(markerDetector)->GetMarkerLengthML(markerDetector, marker, meters);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetMarkerLengthML>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerNumberML>::PreLockReentrant(manager, markerDetector, marker, number);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetMarkerNumberML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerNumberML>::Dispatch(manager, markerDetector, marker, number);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(markerDetector)->GetMarkerNumberML(markerDetector, marker, number);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetMarkerNumberML>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerStringML>::PreLockReentrant(manager, markerDetector, marker, bufferCapacityInput, bufferCountOutput, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetMarkerStringML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetMarkerStringML>::Dispatch(manager, markerDetector, marker, bufferCapacityInput, bufferCountOutput, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(markerDetector)->GetMarkerStringML(markerDetector, marker, bufferCapacityInput, bufferCountOutput, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetMarkerStringML>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateMarkerSpaceML>::PreLockReentrant(manager, session, createInfo, space);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrMarkerSpaceCreateInfoML* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateMarkerSpaceML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateMarkerSpaceML>::Dispatch(manager, session, createInfo, space);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateMarkerSpaceML(session, createInfo_unwrapped, space);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateMarkerSpaceML>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, space, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnableLocalizationEventsML>::PreLockReentrant(manager, session, info);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnableLocalizationEventsML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnableLocalizationEventsML>::Dispatch(manager, session, info);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EnableLocalizationEventsML(session, info);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQueryLocalizationMapsML>::PreLockReentrant(manager, session, queryInfo, mapCapacityInput, mapCountOutput, maps);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrQueryLocalizationMapsML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQueryLocalizationMapsML>::Dispatch(manager, session, queryInfo, mapCapacityInput, mapCountOutput, maps);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->QueryLocalizationMapsML(session, queryInfo, mapCapacityInput, mapCountOutput, maps);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrQueryLocalizationMapsML>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestMapLocalizationML>::PreLockReentrant(manager, session, requestInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrRequestMapLocalizationML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestMapLocalizationML>::Dispatch(manager, session, requestInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->RequestMapLocalizationML(session, requestInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrImportLocalizationMapML>::PreLockReentrant(manager, session, importInfo, mapUuid);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrImportLocalizationMapML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrImportLocalizationMapML>::Dispatch(manager, session, importInfo, mapUuid);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->ImportLocalizationMapML(session, importInfo, mapUuid);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrImportLocalizationMapML>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateExportedLocalizationMapML>::PreLockReentrant(manager, session, mapUuid, map);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateExportedLocalizationMapML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateExportedLocalizationMapML>::Dispatch(manager, session, mapUuid, map);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateExportedLocalizationMapML(session, mapUuid, map);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateExportedLocalizationMapML>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::ExportedLocalizationMapMLWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, map, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyExportedLocalizationMapML>::PreLockReentrant(manager, map);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyExportedLocalizationMapML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyExportedLocalizationMapML>::Dispatch(manager, map);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(map)->DestroyExportedLocalizationMapML(map);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyExportedLocalizationMapML);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::ExportedLocalizationMapMLWrapper>(map);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::ExportedLocalizationMapMLWrapper>(map);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyExportedLocalizationMapML>::Dispatch(manager, result, map);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::ExportedLocalizationMapMLWrapper>(map);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetExportedLocalizationMapDataML(
    XrExportedLocalizationMapML                 map,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetExportedLocalizationMapDataML>::PreLockReentrant(manager, map, bufferCapacityInput, bufferCountOutput, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetExportedLocalizationMapDataML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetExportedLocalizationMapDataML>::Dispatch(manager, map, bufferCapacityInput, bufferCountOutput, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(map)->GetExportedLocalizationMapDataML(map, bufferCapacityInput, bufferCountOutput, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetExportedLocalizationMapDataML>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT>::PreLockReentrant(manager, session, spatialAnchorStore);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT>::Dispatch(manager, session, spatialAnchorStore);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSpatialAnchorStoreConnectionMSFT(session, spatialAnchorStore);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSpatialAnchorStoreConnectionMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, spatialAnchorStore, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT>::PreLockReentrant(manager, spatialAnchorStore);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT>::Dispatch(manager, spatialAnchorStore);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(spatialAnchorStore)->DestroySpatialAnchorStoreConnectionMSFT(spatialAnchorStore);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySpatialAnchorStoreConnectionMSFT>::Dispatch(manager, result, spatialAnchorStore);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::SpatialAnchorStoreConnectionMSFTWrapper>(spatialAnchorStore);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrPersistSpatialAnchorMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore,
    const XrSpatialAnchorPersistenceInfoMSFT*   spatialAnchorPersistenceInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPersistSpatialAnchorMSFT>::PreLockReentrant(manager, spatialAnchorStore, spatialAnchorPersistenceInfo);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpatialAnchorPersistenceInfoMSFT* spatialAnchorPersistenceInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPersistSpatialAnchorMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPersistSpatialAnchorMSFT>::Dispatch(manager, spatialAnchorStore, spatialAnchorPersistenceInfo);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        spatialAnchorPersistenceInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(spatialAnchorPersistenceInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(spatialAnchorStore)->PersistSpatialAnchorMSFT(spatialAnchorStore, spatialAnchorPersistenceInfo_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT>::PreLockReentrant(manager, spatialAnchorStore, spatialAnchorNameCapacityInput, spatialAnchorNameCountOutput, spatialAnchorNames);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT>::Dispatch(manager, spatialAnchorStore, spatialAnchorNameCapacityInput, spatialAnchorNameCountOutput, spatialAnchorNames);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(spatialAnchorStore)->EnumeratePersistedSpatialAnchorNamesMSFT(spatialAnchorStore, spatialAnchorNameCapacityInput, spatialAnchorNameCountOutput, spatialAnchorNames);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumeratePersistedSpatialAnchorNamesMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT>::PreLockReentrant(manager, session, spatialAnchorCreateInfo, spatialAnchor);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* spatialAnchorCreateInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT>::Dispatch(manager, session, spatialAnchorCreateInfo, spatialAnchor);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        spatialAnchorCreateInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(spatialAnchorCreateInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSpatialAnchorFromPersistedNameMSFT(session, spatialAnchorCreateInfo_unwrapped, spatialAnchor);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSpatialAnchorFromPersistedNameMSFT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpatialAnchorMSFTWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, spatialAnchor, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUnpersistSpatialAnchorMSFT>::PreLockReentrant(manager, spatialAnchorStore, spatialAnchorPersistenceName);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrUnpersistSpatialAnchorMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUnpersistSpatialAnchorMSFT>::Dispatch(manager, spatialAnchorStore, spatialAnchorPersistenceName);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(spatialAnchorStore)->UnpersistSpatialAnchorMSFT(spatialAnchorStore, spatialAnchorPersistenceName);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrClearSpatialAnchorStoreMSFT>::PreLockReentrant(manager, spatialAnchorStore);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrClearSpatialAnchorStoreMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrClearSpatialAnchorStoreMSFT>::Dispatch(manager, spatialAnchorStore);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(spatialAnchorStore)->ClearSpatialAnchorStoreMSFT(spatialAnchorStore);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneMarkerRawDataMSFT>::PreLockReentrant(manager, scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSceneMarkerRawDataMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneMarkerRawDataMSFT>::Dispatch(manager, scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(scene)->GetSceneMarkerRawDataMSFT(scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSceneMarkerRawDataMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneMarkerDecodedStringMSFT>::PreLockReentrant(manager, scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSceneMarkerDecodedStringMSFT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSceneMarkerDecodedStringMSFT>::Dispatch(manager, scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(scene)->GetSceneMarkerDecodedStringMSFT(scene, markerId, bufferCapacityInput, bufferCountOutput, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSceneMarkerDecodedStringMSFT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQuerySpacesFB>::PreLockReentrant(manager, session, info, requestId);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrQuerySpacesFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQuerySpacesFB>::Dispatch(manager, session, info, requestId);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->QuerySpacesFB(session, info, requestId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrQuerySpacesFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtom<openxr_wrappers::SessionWrapper, openxr_wrappers::AsyncRequestIdFBWrapper>(session, requestId, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRetrieveSpaceQueryResultsFB>::PreLockReentrant(manager, session, requestId, results);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrRetrieveSpaceQueryResultsFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRetrieveSpaceQueryResultsFB>::Dispatch(manager, session, requestId, results);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->RetrieveSpaceQueryResultsFB(session, requestId, results);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrRetrieveSpaceQueryResultsFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedStructHandles<openxr_wrappers::SessionWrapper, openxr_wrappers::AsyncRequestIdFBWrapper>(session, requestId, results, OpenXrCaptureManager::GetUniqueId);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSaveSpaceFB>::PreLockReentrant(manager, session, info, requestId);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpaceSaveInfoFB* info_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSaveSpaceFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSaveSpaceFB>::Dispatch(manager, session, info, requestId);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        info_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(info, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SaveSpaceFB(session, info_unwrapped, requestId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrSaveSpaceFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtom<openxr_wrappers::SessionWrapper, openxr_wrappers::AsyncRequestIdFBWrapper>(session, requestId, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEraseSpaceFB>::PreLockReentrant(manager, session, info, requestId);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpaceEraseInfoFB* info_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEraseSpaceFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEraseSpaceFB>::Dispatch(manager, session, info, requestId);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        info_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(info, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EraseSpaceFB(session, info_unwrapped, requestId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrEraseSpaceFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtom<openxr_wrappers::SessionWrapper, openxr_wrappers::AsyncRequestIdFBWrapper>(session, requestId, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetAudioOutputDeviceGuidOculus>::PreLockReentrant(manager, instance, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetAudioOutputDeviceGuidOculus);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetAudioOutputDeviceGuidOculus>::Dispatch(manager, instance, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetAudioOutputDeviceGuidOculus(instance, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetAudioOutputDeviceGuidOculus>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetAudioInputDeviceGuidOculus>::PreLockReentrant(manager, instance, buffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetAudioInputDeviceGuidOculus);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetAudioInputDeviceGuidOculus>::Dispatch(manager, instance, buffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetAudioInputDeviceGuidOculus(instance, buffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetAudioInputDeviceGuidOculus>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrShareSpacesFB>::PreLockReentrant(manager, session, info, requestId);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpaceShareInfoFB* info_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrShareSpacesFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrShareSpacesFB>::Dispatch(manager, session, info, requestId);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        info_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(info, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->ShareSpacesFB(session, info_unwrapped, requestId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrShareSpacesFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtom<openxr_wrappers::SessionWrapper, openxr_wrappers::AsyncRequestIdFBWrapper>(session, requestId, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox2DFB>::PreLockReentrant(manager, session, space, boundingBox2DOutput);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpaceBoundingBox2DFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox2DFB>::Dispatch(manager, session, space, boundingBox2DOutput);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetSpaceBoundingBox2DFB(session, space, boundingBox2DOutput);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox2DFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox3DFB>::PreLockReentrant(manager, session, space, boundingBox3DOutput);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpaceBoundingBox3DFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox3DFB>::Dispatch(manager, session, space, boundingBox3DOutput);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetSpaceBoundingBox3DFB(session, space, boundingBox3DOutput);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpaceBoundingBox3DFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceSemanticLabelsFB>::PreLockReentrant(manager, session, space, semanticLabelsOutput);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpaceSemanticLabelsFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceSemanticLabelsFB>::Dispatch(manager, session, space, semanticLabelsOutput);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetSpaceSemanticLabelsFB(session, space, semanticLabelsOutput);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpaceSemanticLabelsFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceBoundary2DFB>::PreLockReentrant(manager, session, space, boundary2DOutput);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpaceBoundary2DFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceBoundary2DFB>::Dispatch(manager, session, space, boundary2DOutput);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetSpaceBoundary2DFB(session, space, boundary2DOutput);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpaceBoundary2DFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceRoomLayoutFB>::PreLockReentrant(manager, session, space, roomLayoutOutput);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpaceRoomLayoutFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceRoomLayoutFB>::Dispatch(manager, session, space, roomLayoutOutput);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetSpaceRoomLayoutFB(session, space, roomLayoutOutput);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpaceRoomLayoutFB>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetDigitalLensControlALMALENCE>::PreLockReentrant(manager, session, digitalLensControl);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetDigitalLensControlALMALENCE);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetDigitalLensControlALMALENCE>::Dispatch(manager, session, digitalLensControl);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetDigitalLensControlALMALENCE(session, digitalLensControl);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestSceneCaptureFB>::PreLockReentrant(manager, session, info, requestId);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrRequestSceneCaptureFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrRequestSceneCaptureFB>::Dispatch(manager, session, info, requestId);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->RequestSceneCaptureFB(session, info, requestId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrRequestSceneCaptureFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtom<openxr_wrappers::SessionWrapper, openxr_wrappers::AsyncRequestIdFBWrapper>(session, requestId, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceContainerFB>::PreLockReentrant(manager, session, space, spaceContainerOutput);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpaceContainerFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceContainerFB>::Dispatch(manager, session, space, spaceContainerOutput);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetSpaceContainerFB(session, space, spaceContainerOutput);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpaceContainerFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFoveationEyeTrackedStateMETA>::PreLockReentrant(manager, session, foveationState);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetFoveationEyeTrackedStateMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFoveationEyeTrackedStateMETA>::Dispatch(manager, session, foveationState);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetFoveationEyeTrackedStateMETA(session, foveationState);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetFoveationEyeTrackedStateMETA>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFaceTrackerFB>::PreLockReentrant(manager, session, createInfo, faceTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateFaceTrackerFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFaceTrackerFB>::Dispatch(manager, session, createInfo, faceTracker);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateFaceTrackerFB(session, createInfo, faceTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateFaceTrackerFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::FaceTrackerFBWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, faceTracker, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFaceTrackerFB>::PreLockReentrant(manager, faceTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyFaceTrackerFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFaceTrackerFB>::Dispatch(manager, faceTracker);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(faceTracker)->DestroyFaceTrackerFB(faceTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyFaceTrackerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FaceTrackerFBWrapper>(faceTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::FaceTrackerFBWrapper>(faceTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyFaceTrackerFB>::Dispatch(manager, result, faceTracker);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::FaceTrackerFBWrapper>(faceTracker);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetFaceExpressionWeightsFB(
    XrFaceTrackerFB                             faceTracker,
    const XrFaceExpressionInfoFB*               expressionInfo,
    XrFaceExpressionWeightsFB*                  expressionWeights)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFaceExpressionWeightsFB>::PreLockReentrant(manager, faceTracker, expressionInfo, expressionWeights);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetFaceExpressionWeightsFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFaceExpressionWeightsFB>::Dispatch(manager, faceTracker, expressionInfo, expressionWeights);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(faceTracker)->GetFaceExpressionWeightsFB(faceTracker, expressionInfo, expressionWeights);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetFaceExpressionWeightsFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateEyeTrackerFB>::PreLockReentrant(manager, session, createInfo, eyeTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateEyeTrackerFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateEyeTrackerFB>::Dispatch(manager, session, createInfo, eyeTracker);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateEyeTrackerFB(session, createInfo, eyeTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateEyeTrackerFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::EyeTrackerFBWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, eyeTracker, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyEyeTrackerFB>::PreLockReentrant(manager, eyeTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyEyeTrackerFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyEyeTrackerFB>::Dispatch(manager, eyeTracker);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(eyeTracker)->DestroyEyeTrackerFB(eyeTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyEyeTrackerFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EyeTrackerFBWrapper>(eyeTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::EyeTrackerFBWrapper>(eyeTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyEyeTrackerFB>::Dispatch(manager, result, eyeTracker);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::EyeTrackerFBWrapper>(eyeTracker);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetEyeGazesFB(
    XrEyeTrackerFB                              eyeTracker,
    const XrEyeGazesInfoFB*                     gazeInfo,
    XrEyeGazesFB*                               eyeGazes)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetEyeGazesFB>::PreLockReentrant(manager, eyeTracker, gazeInfo, eyeGazes);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrEyeGazesInfoFB* gazeInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetEyeGazesFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetEyeGazesFB>::Dispatch(manager, eyeTracker, gazeInfo, eyeGazes);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        gazeInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(gazeInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(eyeTracker)->GetEyeGazesFB(eyeTracker, gazeInfo_unwrapped, eyeGazes);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetEyeGazesFB>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerSetKeyboardHandsIntensityFB>::PreLockReentrant(manager, layer, intensity);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPassthroughLayerSetKeyboardHandsIntensityFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPassthroughLayerSetKeyboardHandsIntensityFB>::Dispatch(manager, layer, intensity);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(layer)->PassthroughLayerSetKeyboardHandsIntensityFB(layer, intensity);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetDeviceSampleRateFB>::PreLockReentrant(manager, session, hapticActionInfo, deviceSampleRate);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrHapticActionInfo* hapticActionInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetDeviceSampleRateFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetDeviceSampleRateFB>::Dispatch(manager, session, hapticActionInfo, deviceSampleRate);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        hapticActionInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(hapticActionInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetDeviceSampleRateFB(session, hapticActionInfo_unwrapped, deviceSampleRate);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetDeviceSampleRateFB>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPassthroughPreferencesMETA>::PreLockReentrant(manager, session, preferences);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetPassthroughPreferencesMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPassthroughPreferencesMETA>::Dispatch(manager, session, preferences);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetPassthroughPreferencesMETA(session, preferences);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetPassthroughPreferencesMETA>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardMETA>::PreLockReentrant(manager, session, createInfo, keyboard);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateVirtualKeyboardMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardMETA>::Dispatch(manager, session, createInfo, keyboard);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateVirtualKeyboardMETA(session, createInfo, keyboard);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardMETA>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::VirtualKeyboardMETAWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, keyboard, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyVirtualKeyboardMETA>::PreLockReentrant(manager, keyboard);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyVirtualKeyboardMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyVirtualKeyboardMETA>::Dispatch(manager, keyboard);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(keyboard)->DestroyVirtualKeyboardMETA(keyboard);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyVirtualKeyboardMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyVirtualKeyboardMETA>::Dispatch(manager, result, keyboard);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::VirtualKeyboardMETAWrapper>(keyboard);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateVirtualKeyboardSpaceMETA(
    XrSession                                   session,
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardSpaceCreateInfoMETA* createInfo,
    XrSpace*                                    keyboardSpace)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardSpaceMETA>::PreLockReentrant(manager, session, keyboard, createInfo, keyboardSpace);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrVirtualKeyboardSpaceCreateInfoMETA* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateVirtualKeyboardSpaceMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardSpaceMETA>::Dispatch(manager, session, keyboard, createInfo, keyboardSpace);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateVirtualKeyboardSpaceMETA(session, keyboard, createInfo_unwrapped, keyboardSpace);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateVirtualKeyboardSpaceMETA>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::VirtualKeyboardMETAWrapper, openxr_wrappers::SpaceWrapper>(session, keyboard, keyboardSpace, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSuggestVirtualKeyboardLocationMETA>::PreLockReentrant(manager, keyboard, locationInfo);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrVirtualKeyboardLocationInfoMETA* locationInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSuggestVirtualKeyboardLocationMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSuggestVirtualKeyboardLocationMETA>::Dispatch(manager, keyboard, locationInfo);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        locationInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(locationInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(keyboard)->SuggestVirtualKeyboardLocationMETA(keyboard, locationInfo_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardScaleMETA>::PreLockReentrant(manager, keyboard, scale);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetVirtualKeyboardScaleMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardScaleMETA>::Dispatch(manager, keyboard, scale);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(keyboard)->GetVirtualKeyboardScaleMETA(keyboard, scale);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetVirtualKeyboardScaleMETA>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetVirtualKeyboardModelVisibilityMETA>::PreLockReentrant(manager, keyboard, modelVisibility);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetVirtualKeyboardModelVisibilityMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetVirtualKeyboardModelVisibilityMETA>::Dispatch(manager, keyboard, modelVisibility);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(keyboard)->SetVirtualKeyboardModelVisibilityMETA(keyboard, modelVisibility);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA>::PreLockReentrant(manager, keyboard, animationStates);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA>::Dispatch(manager, keyboard, animationStates);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(keyboard)->GetVirtualKeyboardModelAnimationStatesMETA(keyboard, animationStates);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetVirtualKeyboardModelAnimationStatesMETA>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA>::PreLockReentrant(manager, keyboard, textureIdCapacityInput, textureIdCountOutput, textureIds);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA>::Dispatch(manager, keyboard, textureIdCapacityInput, textureIdCountOutput, textureIds);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(keyboard)->GetVirtualKeyboardDirtyTexturesMETA(keyboard, textureIdCapacityInput, textureIdCountOutput, textureIds);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetVirtualKeyboardDirtyTexturesMETA>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardTextureDataMETA>::PreLockReentrant(manager, keyboard, textureId, textureData);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetVirtualKeyboardTextureDataMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVirtualKeyboardTextureDataMETA>::Dispatch(manager, keyboard, textureId, textureData);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(keyboard)->GetVirtualKeyboardTextureDataMETA(keyboard, textureId, textureData);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetVirtualKeyboardTextureDataMETA>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSendVirtualKeyboardInputMETA>::PreLockReentrant(manager, keyboard, info, interactorRootPose);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrVirtualKeyboardInputInfoMETA* info_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSendVirtualKeyboardInputMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSendVirtualKeyboardInputMETA>::Dispatch(manager, keyboard, info, interactorRootPose);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        info_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(info, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(keyboard)->SendVirtualKeyboardInputMETA(keyboard, info_unwrapped, interactorRootPose);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrSendVirtualKeyboardInputMETA>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrChangeVirtualKeyboardTextContextMETA>::PreLockReentrant(manager, keyboard, changeInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrChangeVirtualKeyboardTextContextMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrChangeVirtualKeyboardTextContextMETA>::Dispatch(manager, keyboard, changeInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(keyboard)->ChangeVirtualKeyboardTextContextMETA(keyboard, changeInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateExternalCamerasOCULUS>::PreLockReentrant(manager, session, cameraCapacityInput, cameraCountOutput, cameras);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateExternalCamerasOCULUS);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateExternalCamerasOCULUS>::Dispatch(manager, session, cameraCapacityInput, cameraCountOutput, cameras);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EnumerateExternalCamerasOCULUS(session, cameraCapacityInput, cameraCountOutput, cameras);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateExternalCamerasOCULUS>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA>::PreLockReentrant(manager, instance, counterPathCapacityInput, counterPathCountOutput, counterPaths);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA>::Dispatch(manager, instance, counterPathCapacityInput, counterPathCountOutput, counterPaths);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->EnumeratePerformanceMetricsCounterPathsMETA(instance, counterPathCapacityInput, counterPathCountOutput, counterPaths);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrEnumeratePerformanceMetricsCounterPathsMETA>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtoms<openxr_wrappers::InstanceWrapper, openxr_wrappers::PathWrapper>(instance, counterPaths, counterPathCapacityInput, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetPerformanceMetricsStateMETA>::PreLockReentrant(manager, session, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetPerformanceMetricsStateMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetPerformanceMetricsStateMETA>::Dispatch(manager, session, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetPerformanceMetricsStateMETA(session, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPerformanceMetricsStateMETA>::PreLockReentrant(manager, session, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetPerformanceMetricsStateMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPerformanceMetricsStateMETA>::Dispatch(manager, session, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetPerformanceMetricsStateMETA(session, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetPerformanceMetricsStateMETA>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQueryPerformanceMetricsCounterMETA>::PreLockReentrant(manager, session, counterPath, counter);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrQueryPerformanceMetricsCounterMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrQueryPerformanceMetricsCounterMETA>::Dispatch(manager, session, counterPath, counter);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->QueryPerformanceMetricsCounterMETA(session, counterPath, counter);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrQueryPerformanceMetricsCounterMETA>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSaveSpaceListFB>::PreLockReentrant(manager, session, info, requestId);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpaceListSaveInfoFB* info_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSaveSpaceListFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSaveSpaceListFB>::Dispatch(manager, session, info, requestId);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        info_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(info, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SaveSpaceListFB(session, info_unwrapped, requestId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrSaveSpaceListFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedAtom<openxr_wrappers::SessionWrapper, openxr_wrappers::AsyncRequestIdFBWrapper>(session, requestId, OpenXrCaptureManager::GetUniqueId);
    }
    else
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpaceUserFB>::PreLockReentrant(manager, session, info, user);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSpaceUserFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpaceUserFB>::Dispatch(manager, session, info, user);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSpaceUserFB(session, info, user);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSpaceUserFB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceUserFBWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, user, OpenXrCaptureManager::GetUniqueId);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceUserIdFB>::PreLockReentrant(manager, user, userId);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpaceUserIdFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceUserIdFB>::Dispatch(manager, user, userId);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(user)->GetSpaceUserIdFB(user, userId);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpaceUserIdFB>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpaceUserFB>::PreLockReentrant(manager, user);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroySpaceUserFB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroySpaceUserFB>::Dispatch(manager, user);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(user)->DestroySpaceUserFB(user);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroySpaceUserFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SpaceUserFBWrapper>(user);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::SpaceUserFBWrapper>(user);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroySpaceUserFB>::Dispatch(manager, result, user);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::SpaceUserFBWrapper>(user);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetRecommendedLayerResolutionMETA(
    XrSession                                   session,
    const XrRecommendedLayerResolutionGetInfoMETA* info,
    XrRecommendedLayerResolutionMETA*           resolution)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetRecommendedLayerResolutionMETA>::PreLockReentrant(manager, session, info, resolution);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrRecommendedLayerResolutionGetInfoMETA* info_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetRecommendedLayerResolutionMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetRecommendedLayerResolutionMETA>::Dispatch(manager, session, info, resolution);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        info_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(info, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->GetRecommendedLayerResolutionMETA(session, info_unwrapped, resolution);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetRecommendedLayerResolutionMETA>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughColorLutMETA>::PreLockReentrant(manager, passthrough, createInfo, colorLut);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreatePassthroughColorLutMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughColorLutMETA>::Dispatch(manager, passthrough, createInfo, colorLut);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(passthrough)->CreatePassthroughColorLutMETA(passthrough, createInfo, colorLut);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreatePassthroughColorLutMETA>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::PassthroughFBWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::PassthroughColorLutMETAWrapper>(passthrough, openxr_wrappers::NoParentWrapper::kHandleValue, colorLut, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughColorLutMETA>::PreLockReentrant(manager, colorLut);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyPassthroughColorLutMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughColorLutMETA>::Dispatch(manager, colorLut);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(colorLut)->DestroyPassthroughColorLutMETA(colorLut);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyPassthroughColorLutMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughColorLutMETAWrapper>(colorLut);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::PassthroughColorLutMETAWrapper>(colorLut);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyPassthroughColorLutMETA>::Dispatch(manager, result, colorLut);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::PassthroughColorLutMETAWrapper>(colorLut);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrUpdatePassthroughColorLutMETA(
    XrPassthroughColorLutMETA                   colorLut,
    const XrPassthroughColorLutUpdateInfoMETA*  updateInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUpdatePassthroughColorLutMETA>::PreLockReentrant(manager, colorLut, updateInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrUpdatePassthroughColorLutMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrUpdatePassthroughColorLutMETA>::Dispatch(manager, colorLut, updateInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(colorLut)->UpdatePassthroughColorLutMETA(colorLut, updateInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceTriangleMeshMETA>::PreLockReentrant(manager, space, getInfo, triangleMeshOutput);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpaceTriangleMeshMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpaceTriangleMeshMETA>::Dispatch(manager, space, getInfo, triangleMeshOutput);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(space)->GetSpaceTriangleMeshMETA(space, getInfo, triangleMeshOutput);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpaceTriangleMeshMETA>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFaceTracker2FB>::PreLockReentrant(manager, session, createInfo, faceTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateFaceTracker2FB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateFaceTracker2FB>::Dispatch(manager, session, createInfo, faceTracker);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateFaceTracker2FB(session, createInfo, faceTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateFaceTracker2FB>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::FaceTracker2FBWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, faceTracker, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFaceTracker2FB>::PreLockReentrant(manager, faceTracker);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyFaceTracker2FB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyFaceTracker2FB>::Dispatch(manager, faceTracker);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(faceTracker)->DestroyFaceTracker2FB(faceTracker);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyFaceTracker2FB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::FaceTracker2FBWrapper>(faceTracker);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::FaceTracker2FBWrapper>(faceTracker);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyFaceTracker2FB>::Dispatch(manager, result, faceTracker);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::FaceTracker2FBWrapper>(faceTracker);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetFaceExpressionWeights2FB(
    XrFaceTracker2FB                            faceTracker,
    const XrFaceExpressionInfo2FB*              expressionInfo,
    XrFaceExpressionWeights2FB*                 expressionWeights)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFaceExpressionWeights2FB>::PreLockReentrant(manager, faceTracker, expressionInfo, expressionWeights);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetFaceExpressionWeights2FB);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetFaceExpressionWeights2FB>::Dispatch(manager, faceTracker, expressionInfo, expressionWeights);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(faceTracker)->GetFaceExpressionWeights2FB(faceTracker, expressionInfo, expressionWeights);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetFaceExpressionWeights2FB>::Succeeded (manager, result);

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

XRAPI_ATTR XrResult XRAPI_CALL xrCreateEnvironmentDepthProviderMETA(
    XrSession                                   session,
    const XrEnvironmentDepthProviderCreateInfoMETA* createInfo,
    XrEnvironmentDepthProviderMETA*             environmentDepthProvider)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateEnvironmentDepthProviderMETA>::PreLockReentrant(manager, session, createInfo, environmentDepthProvider);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateEnvironmentDepthProviderMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateEnvironmentDepthProviderMETA>::Dispatch(manager, session, createInfo, environmentDepthProvider);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateEnvironmentDepthProviderMETA(session, createInfo, environmentDepthProvider);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateEnvironmentDepthProviderMETA>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::EnvironmentDepthProviderMETAWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, environmentDepthProvider, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateEnvironmentDepthProviderMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::EnvironmentDepthProviderMETAWrapper>(environmentDepthProvider, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::EnvironmentDepthProviderMETAWrapper, XrEnvironmentDepthProviderCreateInfoMETA>(result, session, environmentDepthProvider, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateEnvironmentDepthProviderMETA>::Dispatch(manager, result, session, createInfo, environmentDepthProvider);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyEnvironmentDepthProviderMETA(
    XrEnvironmentDepthProviderMETA              environmentDepthProvider)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthProviderMETA>::PreLockReentrant(manager, environmentDepthProvider);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthProviderMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthProviderMETA>::Dispatch(manager, environmentDepthProvider);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(environmentDepthProvider)->DestroyEnvironmentDepthProviderMETA(environmentDepthProvider);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthProviderMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EnvironmentDepthProviderMETAWrapper>(environmentDepthProvider);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::EnvironmentDepthProviderMETAWrapper>(environmentDepthProvider);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthProviderMETA>::Dispatch(manager, result, environmentDepthProvider);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::EnvironmentDepthProviderMETAWrapper>(environmentDepthProvider);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrStartEnvironmentDepthProviderMETA(
    XrEnvironmentDepthProviderMETA              environmentDepthProvider)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStartEnvironmentDepthProviderMETA>::PreLockReentrant(manager, environmentDepthProvider);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrStartEnvironmentDepthProviderMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStartEnvironmentDepthProviderMETA>::Dispatch(manager, environmentDepthProvider);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(environmentDepthProvider)->StartEnvironmentDepthProviderMETA(environmentDepthProvider);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrStartEnvironmentDepthProviderMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EnvironmentDepthProviderMETAWrapper>(environmentDepthProvider);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrStartEnvironmentDepthProviderMETA>::Dispatch(manager, result, environmentDepthProvider);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrStopEnvironmentDepthProviderMETA(
    XrEnvironmentDepthProviderMETA              environmentDepthProvider)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStopEnvironmentDepthProviderMETA>::PreLockReentrant(manager, environmentDepthProvider);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrStopEnvironmentDepthProviderMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrStopEnvironmentDepthProviderMETA>::Dispatch(manager, environmentDepthProvider);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(environmentDepthProvider)->StopEnvironmentDepthProviderMETA(environmentDepthProvider);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrStopEnvironmentDepthProviderMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EnvironmentDepthProviderMETAWrapper>(environmentDepthProvider);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrStopEnvironmentDepthProviderMETA>::Dispatch(manager, result, environmentDepthProvider);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateEnvironmentDepthSwapchainMETA(
    XrEnvironmentDepthProviderMETA              environmentDepthProvider,
    const XrEnvironmentDepthSwapchainCreateInfoMETA* createInfo,
    XrEnvironmentDepthSwapchainMETA*            swapchain)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateEnvironmentDepthSwapchainMETA>::PreLockReentrant(manager, environmentDepthProvider, createInfo, swapchain);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateEnvironmentDepthSwapchainMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateEnvironmentDepthSwapchainMETA>::Dispatch(manager, environmentDepthProvider, createInfo, swapchain);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(environmentDepthProvider)->CreateEnvironmentDepthSwapchainMETA(environmentDepthProvider, createInfo, swapchain);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateEnvironmentDepthSwapchainMETA>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::EnvironmentDepthProviderMETAWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::EnvironmentDepthSwapchainMETAWrapper>(environmentDepthProvider, openxr_wrappers::NoParentWrapper::kHandleValue, swapchain, OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateEnvironmentDepthSwapchainMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EnvironmentDepthProviderMETAWrapper>(environmentDepthProvider);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::EnvironmentDepthSwapchainMETAWrapper>(swapchain, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrEnvironmentDepthProviderMETA, openxr_wrappers::EnvironmentDepthSwapchainMETAWrapper, XrEnvironmentDepthSwapchainCreateInfoMETA>(result, environmentDepthProvider, swapchain, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateEnvironmentDepthSwapchainMETA>::Dispatch(manager, result, environmentDepthProvider, createInfo, swapchain);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyEnvironmentDepthSwapchainMETA(
    XrEnvironmentDepthSwapchainMETA             swapchain)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthSwapchainMETA>::PreLockReentrant(manager, swapchain);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthSwapchainMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthSwapchainMETA>::Dispatch(manager, swapchain);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(swapchain)->DestroyEnvironmentDepthSwapchainMETA(swapchain);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthSwapchainMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EnvironmentDepthSwapchainMETAWrapper>(swapchain);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::EnvironmentDepthSwapchainMETAWrapper>(swapchain);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyEnvironmentDepthSwapchainMETA>::Dispatch(manager, result, swapchain);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::EnvironmentDepthSwapchainMETAWrapper>(swapchain);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateEnvironmentDepthSwapchainImagesMETA(
    XrEnvironmentDepthSwapchainMETA             swapchain,
    uint32_t                                    imageCapacityInput,
    uint32_t*                                   imageCountOutput,
    XrSwapchainImageBaseHeader*                 images)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateEnvironmentDepthSwapchainImagesMETA>::PreLockReentrant(manager, swapchain, imageCapacityInput, imageCountOutput, images);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnumerateEnvironmentDepthSwapchainImagesMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnumerateEnvironmentDepthSwapchainImagesMETA>::Dispatch(manager, swapchain, imageCapacityInput, imageCountOutput, images);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(swapchain)->EnumerateEnvironmentDepthSwapchainImagesMETA(swapchain, imageCapacityInput, imageCountOutput, images);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrEnumerateEnvironmentDepthSwapchainImagesMETA>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEnumerateEnvironmentDepthSwapchainImagesMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EnvironmentDepthSwapchainMETAWrapper>(swapchain);
        encoder->EncodeUInt32Value(imageCapacityInput);
        encoder->EncodeUInt32Ptr(imageCountOutput, omit_output_data);
        EncodeStructArray(encoder, images, imageCapacityInput, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEnumerateEnvironmentDepthSwapchainImagesMETA>::Dispatch(manager, result, swapchain, imageCapacityInput, imageCountOutput, images);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrGetEnvironmentDepthSwapchainStateMETA(
    XrEnvironmentDepthSwapchainMETA             swapchain,
    XrEnvironmentDepthSwapchainStateMETA*       state)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetEnvironmentDepthSwapchainStateMETA>::PreLockReentrant(manager, swapchain, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetEnvironmentDepthSwapchainStateMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetEnvironmentDepthSwapchainStateMETA>::Dispatch(manager, swapchain, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(swapchain)->GetEnvironmentDepthSwapchainStateMETA(swapchain, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetEnvironmentDepthSwapchainStateMETA>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrGetEnvironmentDepthSwapchainStateMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EnvironmentDepthSwapchainMETAWrapper>(swapchain);
        EncodeStructPtr(encoder, state, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetEnvironmentDepthSwapchainStateMETA>::Dispatch(manager, result, swapchain, state);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrAcquireEnvironmentDepthImageMETA(
    XrEnvironmentDepthProviderMETA              environmentDepthProvider,
    const XrEnvironmentDepthImageAcquireInfoMETA* acquireInfo,
    XrEnvironmentDepthImageMETA*                environmentDepthImage)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrAcquireEnvironmentDepthImageMETA>::PreLockReentrant(manager, environmentDepthProvider, acquireInfo, environmentDepthImage);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrEnvironmentDepthImageAcquireInfoMETA* acquireInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrAcquireEnvironmentDepthImageMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrAcquireEnvironmentDepthImageMETA>::Dispatch(manager, environmentDepthProvider, acquireInfo, environmentDepthImage);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        acquireInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(acquireInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(environmentDepthProvider)->AcquireEnvironmentDepthImageMETA(environmentDepthProvider, acquireInfo_unwrapped, environmentDepthImage);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrAcquireEnvironmentDepthImageMETA>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrAcquireEnvironmentDepthImageMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EnvironmentDepthProviderMETAWrapper>(environmentDepthProvider);
        EncodeStructPtr(encoder, acquireInfo);
        EncodeStructPtr(encoder, environmentDepthImage, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrAcquireEnvironmentDepthImageMETA>::Dispatch(manager, result, environmentDepthProvider, acquireInfo, environmentDepthImage);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrSetEnvironmentDepthHandRemovalMETA(
    XrEnvironmentDepthProviderMETA              environmentDepthProvider,
    const XrEnvironmentDepthHandRemovalSetInfoMETA* setInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetEnvironmentDepthHandRemovalMETA>::PreLockReentrant(manager, environmentDepthProvider, setInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetEnvironmentDepthHandRemovalMETA);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetEnvironmentDepthHandRemovalMETA>::Dispatch(manager, environmentDepthProvider, setInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(environmentDepthProvider)->SetEnvironmentDepthHandRemovalMETA(environmentDepthProvider, setInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrSetEnvironmentDepthHandRemovalMETA);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::EnvironmentDepthProviderMETAWrapper>(environmentDepthProvider);
        EncodeStructPtr(encoder, setInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrSetEnvironmentDepthHandRemovalMETA>::Dispatch(manager, result, environmentDepthProvider, setInfo);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrSetTrackingOptimizationSettingsHintQCOM(
    XrSession                                   session,
    XrTrackingOptimizationSettingsDomainQCOM    domain,
    XrTrackingOptimizationSettingsHintQCOM      hint)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetTrackingOptimizationSettingsHintQCOM>::PreLockReentrant(manager, session, domain, hint);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrSetTrackingOptimizationSettingsHintQCOM);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrSetTrackingOptimizationSettingsHintQCOM>::Dispatch(manager, session, domain, hint);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->SetTrackingOptimizationSettingsHintQCOM(session, domain, hint);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughHTC>::PreLockReentrant(manager, session, createInfo, passthrough);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreatePassthroughHTC);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePassthroughHTC>::Dispatch(manager, session, createInfo, passthrough);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreatePassthroughHTC(session, createInfo, passthrough);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreatePassthroughHTC>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::PassthroughHTCWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, passthrough, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughHTC>::PreLockReentrant(manager, passthrough);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyPassthroughHTC);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPassthroughHTC>::Dispatch(manager, passthrough);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(passthrough)->DestroyPassthroughHTC(passthrough);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyPassthroughHTC);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PassthroughHTCWrapper>(passthrough);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::PassthroughHTCWrapper>(passthrough);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyPassthroughHTC>::Dispatch(manager, result, passthrough);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::PassthroughHTCWrapper>(passthrough);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrApplyFoveationHTC(
    XrSession                                   session,
    const XrFoveationApplyInfoHTC*              applyInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrApplyFoveationHTC>::PreLockReentrant(manager, session, applyInfo);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrFoveationApplyInfoHTC* applyInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrApplyFoveationHTC);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrApplyFoveationHTC>::Dispatch(manager, session, applyInfo);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        applyInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(applyInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->ApplyFoveationHTC(session, applyInfo_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorHTC>::PreLockReentrant(manager, session, createInfo, anchor);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrSpatialAnchorCreateInfoHTC* createInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreateSpatialAnchorHTC);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateSpatialAnchorHTC>::Dispatch(manager, session, createInfo, anchor);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreateSpatialAnchorHTC(session, createInfo_unwrapped, anchor);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreateSpatialAnchorHTC>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::SpaceWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, anchor, OpenXrCaptureManager::GetUniqueId);
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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpatialAnchorNameHTC>::PreLockReentrant(manager, anchor, name);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetSpatialAnchorNameHTC);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetSpatialAnchorNameHTC>::Dispatch(manager, anchor, name);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(anchor)->GetSpatialAnchorNameHTC(anchor, name);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetSpatialAnchorNameHTC>::Succeeded (manager, result);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrApplyForceFeedbackCurlMNDX>::PreLockReentrant(manager, handTracker, locations);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrApplyForceFeedbackCurlMNDX);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrApplyForceFeedbackCurlMNDX>::Dispatch(manager, handTracker, locations);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(handTracker)->ApplyForceFeedbackCurlMNDX(handTracker, locations);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePlaneDetectorEXT>::PreLockReentrant(manager, session, createInfo, planeDetector);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCreatePlaneDetectorEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreatePlaneDetectorEXT>::Dispatch(manager, session, createInfo, planeDetector);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->CreatePlaneDetectorEXT(session, createInfo, planeDetector);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    if (CustomCallResult<format::ApiCallId::ApiCall_xrCreatePlaneDetectorEXT>::Succeeded (manager, result))
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper, openxr_wrappers::NoParentWrapper, openxr_wrappers::PlaneDetectorEXTWrapper>(session, openxr_wrappers::NoParentWrapper::kHandleValue, planeDetector, OpenXrCaptureManager::GetUniqueId);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPlaneDetectorEXT>::PreLockReentrant(manager, planeDetector);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrDestroyPlaneDetectorEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyPlaneDetectorEXT>::Dispatch(manager, planeDetector);
        reentry_control.PreDispatch();
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult result = openxr_wrappers::GetInstanceTable(planeDetector)->DestroyPlaneDetectorEXT(planeDetector);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyPlaneDetectorEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyPlaneDetectorEXT>::Dispatch(manager, result, planeDetector);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::PlaneDetectorEXTWrapper>(planeDetector);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrBeginPlaneDetectionEXT(
    XrPlaneDetectorEXT                          planeDetector,
    const XrPlaneDetectorBeginInfoEXT*          beginInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrBeginPlaneDetectionEXT>::PreLockReentrant(manager, planeDetector, beginInfo);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrPlaneDetectorBeginInfoEXT* beginInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrBeginPlaneDetectionEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrBeginPlaneDetectionEXT>::Dispatch(manager, planeDetector, beginInfo);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        beginInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(beginInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(planeDetector)->BeginPlaneDetectionEXT(planeDetector, beginInfo_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPlaneDetectionStateEXT>::PreLockReentrant(manager, planeDetector, state);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetPlaneDetectionStateEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPlaneDetectionStateEXT>::Dispatch(manager, planeDetector, state);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(planeDetector)->GetPlaneDetectionStateEXT(planeDetector, state);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetPlaneDetectionStateEXT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPlaneDetectionsEXT>::PreLockReentrant(manager, planeDetector, info, locations);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrPlaneDetectorGetInfoEXT* info_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetPlaneDetectionsEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPlaneDetectionsEXT>::Dispatch(manager, planeDetector, info, locations);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        info_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(info, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(planeDetector)->GetPlaneDetectionsEXT(planeDetector, info_unwrapped, locations);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetPlaneDetectionsEXT>::Succeeded (manager, result);

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
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPlanePolygonBufferEXT>::PreLockReentrant(manager, planeDetector, planeId, polygonBufferIndex, polygonBuffer);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrGetPlanePolygonBufferEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetPlanePolygonBufferEXT>::Dispatch(manager, planeDetector, planeId, polygonBufferIndex, polygonBuffer);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(planeDetector)->GetPlanePolygonBufferEXT(planeDetector, planeId, polygonBufferIndex, polygonBuffer);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrGetPlanePolygonBufferEXT>::Succeeded (manager, result);

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

XRAPI_ATTR XrResult XRAPI_CALL xrPollFutureEXT(
    XrInstance                                  instance,
    const XrFuturePollInfoEXT*                  pollInfo,
    XrFuturePollResultEXT*                      pollResult)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPollFutureEXT>::PreLockReentrant(manager, instance, pollInfo, pollResult);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrFuturePollInfoEXT* pollInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrPollFutureEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrPollFutureEXT>::Dispatch(manager, instance, pollInfo, pollResult);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        pollInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(pollInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->PollFutureEXT(instance, pollInfo_unwrapped, pollResult);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();
    omit_output_data = !CustomCallResult<format::ApiCallId::ApiCall_xrPollFutureEXT>::Succeeded (manager, result);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrPollFutureEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, pollInfo);
        EncodeStructPtr(encoder, pollResult, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrPollFutureEXT>::Dispatch(manager, result, instance, pollInfo, pollResult);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrCancelFutureEXT(
    XrInstance                                  instance,
    const XrFutureCancelInfoEXT*                cancelInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCancelFutureEXT>::PreLockReentrant(manager, instance, cancelInfo);
    HandleUnwrapMemory* handle_unwrap_memory = nullptr;
    const XrFutureCancelInfoEXT* cancelInfo_unwrapped = nullptr;
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrCancelFutureEXT);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCancelFutureEXT>::Dispatch(manager, instance, cancelInfo);

        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        cancelInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(cancelInfo, handle_unwrap_memory);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->CancelFutureEXT(instance, cancelInfo_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrCancelFutureEXT);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::InstanceWrapper>(instance);
        EncodeStructPtr(encoder, cancelInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCancelFutureEXT>::Dispatch(manager, result, instance, cancelInfo);

    return result;

}

XRAPI_ATTR XrResult XRAPI_CALL xrEnableUserCalibrationEventsML(
    XrInstance                                  instance,
    const XrUserCalibrationEnableEventsInfoML*  enableInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnableUserCalibrationEventsML>::PreLockReentrant(manager, instance, enableInfo);
    OpenXrCaptureManager::ReentryState reentry_control = manager->MakeReentryState(format::ApiCallId::ApiCall_xrEnableUserCalibrationEventsML);
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEnableUserCalibrationEventsML>::Dispatch(manager, instance, enableInfo);
        reentry_control.PreDispatch();
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->EnableUserCalibrationEventsML(instance, enableInfo);

    auto call_lock = manager->AcquireCallLock();
    reentry_control.PostDispatch();

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
