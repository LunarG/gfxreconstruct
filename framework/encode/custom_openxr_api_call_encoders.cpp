/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#if ENABLE_OPENXR_SUPPORT

#include "encode/custom_openxr_api_call_encoders.h"
#include "encode/custom_openxr_encoder_commands.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/openxr_capture_manager.h"
#include "encode/openxr_handle_wrapper_util.h"
#include "encode/openxr_handle_wrappers.h"
#include "encode/vulkan_capture_manager.h"
#include "format/api_call_id.h"
#include "format/platform_types.h"
#include "generated/generated_openxr_struct_handle_wrappers.h"
#include "util/defines.h"
#include "generated/generated_vulkan_api_call_encoders.h"

#include "openxr/openxr.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

static void RequireVulkanCaptureEnabled()
{
    // If Vulkan Capture has not been enabled, various encode calls such as
    // encode::vkEnumeratePhysicalDevices and vulkan_wrappers::CreateWrappedHandle
    // will crash, as no VulkanCaptureManager exists to support them.
    //
    // API call encoders which make these calls must check that the needed
    // capture manager is present before making those calls.
    VulkanCaptureManager* vulkan_capture_manager = VulkanCaptureManager::Get();
    if (!vulkan_capture_manager)
    {
        GFXRECON_LOG_FATAL(
            "Capture configuration error. Attempting OpenXR capture without Vulkan graphics API capture enabled.");
    }
    GFXRECON_ASSERT(vulkan_capture_manager != nullptr);
}

XRAPI_ATTR XrResult XRAPI_CALL xrEndFrame(XrSession session, const XrFrameEndInfo* frameEndInfo)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEndFrame>::PreLockReentrant(manager, session, frameEndInfo);
    HandleUnwrapMemory*   handle_unwrap_memory   = nullptr;
    const XrFrameEndInfo* frameEndInfo_unwrapped = nullptr;

    CommonCaptureManager::CaptureMode save_capture_mode;
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrEndFrame>::Dispatch(manager, session, frameEndInfo);
        handle_unwrap_memory   = manager->GetHandleUnwrapMemory();
        frameEndInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(frameEndInfo, handle_unwrap_memory);

        save_capture_mode = manager->GetCaptureMode();
        manager->SetCaptureMode(CommonCaptureManager::CaptureModeFlags::kModeDisabled);
    }

    XrResult result = openxr_wrappers::GetInstanceTable(session)->EndFrame(session, frameEndInfo_unwrapped);

    auto call_lock = manager->AcquireCallLock();
    manager->SetCaptureMode(save_capture_mode);

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrEndFrame);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, frameEndInfo);
        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrEndFrame>::Dispatch(manager, result, session, frameEndInfo);

    // End the frame
    manager->EndFrame(call_lock);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrInitializeLoaderKHR(const XrLoaderInitInfoBaseHeaderKHR* loader_init_info)
{
    XrResult result = XR_ERROR_INITIALIZATION_FAILED;

    if (OpenXrCaptureManager::CreateInstance())
    {
        OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();

        auto api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrInitializeLoaderKHR>::Dispatch(manager, loader_init_info);

        auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrInitializeLoaderKHR);
        if (encoder)
        {
            switch (loader_init_info->type)
            {
                case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
                {
                    const XrLoaderInitInfoAndroidKHR* android_init_info =
                        reinterpret_cast<const XrLoaderInitInfoAndroidKHR*>(loader_init_info);
                    EncodeStructPtr(encoder, android_init_info);
                    break;
                }
                default:
                    GFXRECON_LOG_WARNING("Unknown XrLoaderInitInfoBaseHeaderKHR derived structure type %d",
                                         loader_init_info->type);
                    EncodeStructPtr(encoder, loader_init_info);
                    break;
            }

            // Just record the information and return a SUCCESS message
            result = XR_SUCCESS;

            encoder->EncodeEnumValue(result);
            manager->EndApiCallCapture();
        }

        CustomEncoderPostCall<format::ApiCallId::ApiCall_xrInitializeLoaderKHR>::Dispatch(
            manager, result, loader_init_info);
    }

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsDeviceKHR(XrInstance        instance,
                                                            XrSystemId        systemId,
                                                            VkInstance        vkInstance,
                                                            VkPhysicalDevice* vkPhysicalDevice)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);

    // GetVulkanGraphicsDevice requires a valid Vulkan Instance
    // Thus if capture isn't enabled by the beginning of this call, OpenXR capture will likely fail
    RequireVulkanCaptureEnabled(); // Will FATAL error and assert

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDeviceKHR>::PreLockReentrant(
        manager, instance, systemId, vkInstance, vkPhysicalDevice);
    CommonCaptureManager::CaptureMode save_capture_mode;
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDeviceKHR>::Dispatch(
            manager, instance, systemId, vkInstance, vkPhysicalDevice);
        save_capture_mode = manager->GetCaptureMode();
        manager->SetCaptureMode(CommonCaptureManager::CaptureModeFlags::kModeDisabled);
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetVulkanGraphicsDeviceKHR(
        instance, systemId, vkInstance, vkPhysicalDevice);

    auto call_lock = manager->AcquireCallLock();
    manager->SetCaptureMode(save_capture_mode);

    if (result >= 0)
    {
        // Only create a new handle if one doesn't already exist for this Vulkan physical device
        if (format::kNullHandleId ==
            vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(*vkPhysicalDevice))
        {
            auto instance_wrapper = openxr_wrappers::GetWrapper<openxr_wrappers::InstanceWrapper>(instance);
            vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::InstanceWrapper,
                                                 vulkan_wrappers::NoParentWrapper,
                                                 vulkan_wrappers::PhysicalDeviceWrapper>(
                vkInstance,
                vulkan_wrappers::NoParentWrapper::kHandleValue,
                vkPhysicalDevice,
                VulkanCaptureManager::GetUniqueId);
        }

        // Record the instance based on the physical device returned
        auto instance_wrapper = openxr_wrappers::GetWrapper<openxr_wrappers::InstanceWrapper>(instance);
        instance_wrapper->vkphysdev_vkinstance_map[*vkPhysicalDevice] = vkInstance;
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

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDeviceKHR>::Dispatch(
        manager, result, instance, systemId, vkInstance, vkPhysicalDevice);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateVulkanInstanceKHR(XrInstance                           instance,
                                                         const XrVulkanInstanceCreateInfoKHR* createInfo,
                                                         VkInstance*                          vulkanInstance,
                                                         VkResult*                            vulkanResult)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);

    // NOTE: RequireVulkanCaptureEnabled is called post dispatch.

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVulkanInstanceKHR>::PreLockReentrant(
        manager, instance, createInfo, vulkanInstance, vulkanResult);
    CommonCaptureManager::CaptureMode save_capture_mode;
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVulkanInstanceKHR>::Dispatch(
            manager, instance, createInfo, vulkanInstance, vulkanResult);
        save_capture_mode = manager->GetCaptureMode();
        manager->SetCaptureMode(CommonCaptureManager::CaptureModeFlags::kModeDisabled);
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->CreateVulkanInstanceKHR(
        instance, createInfo, vulkanInstance, vulkanResult);

    auto call_lock = manager->AcquireCallLock();
    manager->SetCaptureMode(save_capture_mode);

    if (result >= 0)
    {
        // We check for the requirement *after* the CreateVulkanInstance, as it is possible that Vulkan
        // Capture wasn't enabled before the down-chain call (unlikely, but possible)
        RequireVulkanCaptureEnabled(); // Will FATAL error and assert

        // Only create a new handle if one doesn't already exist for this Vulkan instance
        if (format::kNullHandleId == vulkan_wrappers::GetWrappedId<vulkan_wrappers::InstanceWrapper>(*vulkanInstance))
        {
            vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::NoParentWrapper,
                                                 vulkan_wrappers::NoParentWrapper,
                                                 vulkan_wrappers::InstanceWrapper>(
                vulkan_wrappers::NoParentWrapper::kHandleValue,
                vulkan_wrappers::NoParentWrapper::kHandleValue,
                vulkanInstance,
                VulkanCaptureManager::GetUniqueId);
        }

        // Record the instance based on the gipa returned
        auto instance_wrapper = openxr_wrappers::GetWrapper<openxr_wrappers::InstanceWrapper>(instance);
        instance_wrapper->vkgipa_vkinstance_map[createInfo->pfnGetInstanceProcAddr] = *vulkanInstance;
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
        manager->EndCreateApiCallCapture<XrInstance, vulkan_wrappers::InstanceWrapper, XrVulkanInstanceCreateInfoKHR>(
            result, instance, vulkanInstance, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateVulkanInstanceKHR>::Dispatch(
        manager, result, instance, createInfo, vulkanInstance, vulkanResult);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateVulkanDeviceKHR(XrInstance                         instance,
                                                       const XrVulkanDeviceCreateInfoKHR* createInfo,
                                                       VkDevice*                          vulkanDevice,
                                                       VkResult*                          vulkanResult)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);

    // CreateVulkanDevice requires a valid Vulkan Instance and physical device.
    // Thus if capture isn't enabled by the beginning of this call, OpenXR capture will likely fail
    RequireVulkanCaptureEnabled(); // Will FATAL error and assert

    HandleUnwrapMemory*                handle_unwrap_memory = nullptr;
    const XrVulkanDeviceCreateInfoKHR* createInfo_unwrapped = nullptr;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVulkanDeviceKHR>::PreLockReentrant(
        manager, instance, createInfo, vulkanDevice, vulkanResult);
    CommonCaptureManager::CaptureMode save_capture_mode;
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateVulkanDeviceKHR>::Dispatch(
            manager, instance, createInfo, vulkanDevice, vulkanResult);
        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        createInfo_unwrapped = openxr_wrappers::UnwrapStructPtrHandles(createInfo, handle_unwrap_memory);

        save_capture_mode = manager->GetCaptureMode();
        manager->SetCaptureMode(CommonCaptureManager::CaptureModeFlags::kModeDisabled);
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->CreateVulkanDeviceKHR(
        instance, createInfo_unwrapped, vulkanDevice, vulkanResult);

    auto call_lock = manager->AcquireCallLock();
    manager->SetCaptureMode(save_capture_mode);

    if (result >= 0)
    {
        // Record the instance based on the gipa returned
        auto       instance_wrapper = openxr_wrappers::GetWrapper<openxr_wrappers::InstanceWrapper>(instance);
        VkInstance vulkanInstance   = instance_wrapper->vkgipa_vkinstance_map[createInfo->pfnGetInstanceProcAddr];

        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::InstanceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::DeviceWrapper>(
            vulkanInstance,
            vulkan_wrappers::NoParentWrapper::kHandleValue,
            vulkanDevice,
            VulkanCaptureManager::GetUniqueId);
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
        manager->EndCreateApiCallCapture<XrInstance, vulkan_wrappers::DeviceWrapper, XrVulkanDeviceCreateInfoKHR>(
            result, instance, vulkanDevice, createInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateVulkanDeviceKHR>::Dispatch(
        manager, result, instance, createInfo, vulkanDevice, vulkanResult);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsDevice2KHR(XrInstance                              instance,
                                                             const XrVulkanGraphicsDeviceGetInfoKHR* getInfo,
                                                             VkPhysicalDevice* vulkanPhysicalDevice)
{
    bool omit_output_data = false;

    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);

    // GetVulkanGraphicsDevice requires a valid Vulkan Instance
    // Thus if capture isn't enabled by the beginning of this call, OpenXR capture will likely fail
    RequireVulkanCaptureEnabled(); // Will FATAL error and assert

    HandleUnwrapMemory*                     handle_unwrap_memory = nullptr;
    const XrVulkanGraphicsDeviceGetInfoKHR* getInfo_unwrapped    = nullptr;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDevice2KHR>::PreLockReentrant(
        manager, instance, getInfo, vulkanPhysicalDevice);
    CommonCaptureManager::CaptureMode save_capture_mode;
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDevice2KHR>::Dispatch(
            manager, instance, getInfo, vulkanPhysicalDevice);
        handle_unwrap_memory = manager->GetHandleUnwrapMemory();
        getInfo_unwrapped    = openxr_wrappers::UnwrapStructPtrHandles(getInfo, handle_unwrap_memory);

        save_capture_mode = manager->GetCaptureMode();
        manager->SetCaptureMode(CommonCaptureManager::CaptureModeFlags::kModeDisabled);
    }

    XrResult result = openxr_wrappers::GetInstanceTable(instance)->GetVulkanGraphicsDevice2KHR(
        instance, getInfo_unwrapped, vulkanPhysicalDevice);

    auto call_lock = manager->AcquireCallLock();
    manager->SetCaptureMode(save_capture_mode);

    if (result >= 0)
    {
        // Only create a new handle if one doesn't already exist for this Vulkan physical device
        if (format::kNullHandleId ==
            vulkan_wrappers::GetWrappedId<vulkan_wrappers::PhysicalDeviceWrapper>(*vulkanPhysicalDevice))
        {
            vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::InstanceWrapper,
                                                 vulkan_wrappers::NoParentWrapper,
                                                 vulkan_wrappers::PhysicalDeviceWrapper>(
                getInfo->vulkanInstance,
                vulkan_wrappers::NoParentWrapper::kHandleValue,
                vulkanPhysicalDevice,
                VulkanCaptureManager::GetUniqueId);
        }

        // Record the instance based on the physical device returned
        auto instance_wrapper = openxr_wrappers::GetWrapper<openxr_wrappers::InstanceWrapper>(instance);
        instance_wrapper->vkphysdev_vkinstance_map[*vulkanPhysicalDevice] = getInfo->vulkanInstance;
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

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDevice2KHR>::Dispatch(
        manager, result, instance, getInfo, vulkanPhysicalDevice);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrCreateTriangleMeshFB(XrSession                         session,
                                                      const XrTriangleMeshCreateInfoFB* createInfo,
                                                      XrTriangleMeshFB*                 outTriangleMesh)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateTriangleMeshFB>::PreLockReentrant(
        manager, session, createInfo, outTriangleMesh);
    CommonCaptureManager::CaptureMode save_capture_mode;
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateTriangleMeshFB>::Dispatch(
            manager, session, createInfo, outTriangleMesh);
        save_capture_mode = manager->GetCaptureMode();
        manager->SetCaptureMode(CommonCaptureManager::CaptureModeFlags::kModeDisabled);
    }

    XrResult result =
        openxr_wrappers::GetInstanceTable(session)->CreateTriangleMeshFB(session, createInfo, outTriangleMesh);

    auto call_lock = manager->AcquireCallLock();
    manager->SetCaptureMode(save_capture_mode);

    if (result >= 0)
    {
        openxr_wrappers::CreateWrappedHandle<openxr_wrappers::SessionWrapper,
                                             openxr_wrappers::NoParentWrapper,
                                             openxr_wrappers::TriangleMeshFBWrapper>(
            session,
            openxr_wrappers::NoParentWrapper::kHandleValue,
            outTriangleMesh,
            OpenXrCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrCreateTriangleMeshFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::SessionWrapper>(session);
        EncodeStructPtr(encoder, createInfo);
        encoder->EncodeOpenXrHandlePtr<openxr_wrappers::TriangleMeshFBWrapper>(outTriangleMesh, omit_output_data);
        encoder->EncodeEnumValue(result);
        manager->EndCreateApiCallCapture<XrSession, openxr_wrappers::TriangleMeshFBWrapper, XrTriangleMeshCreateInfoFB>(
            result, session, outTriangleMesh, createInfo);
        auto tri_mesh_fb_wrapper =
            openxr_wrappers::GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(*outTriangleMesh);
        memcpy(&tri_mesh_fb_wrapper->create_info, createInfo, sizeof(XrTriangleMeshCreateInfoFB));
        tri_mesh_fb_wrapper->create_info.next = nullptr;
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateTriangleMeshFB>::Dispatch(
        manager, result, session, createInfo, outTriangleMesh);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyTriangleMeshFB(XrTriangleMeshFB mesh)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyTriangleMeshFB>::PreLockReentrant(manager, mesh);
    CommonCaptureManager::CaptureMode save_capture_mode;
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyTriangleMeshFB>::Dispatch(manager, mesh);
        save_capture_mode = manager->GetCaptureMode();
        manager->SetCaptureMode(CommonCaptureManager::CaptureModeFlags::kModeDisabled);
    }

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult          result = openxr_wrappers::GetInstanceTable(mesh)->DestroyTriangleMeshFB(mesh);

    auto call_lock = manager->AcquireCallLock();
    manager->SetCaptureMode(save_capture_mode);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyTriangleMeshFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyTriangleMeshFB>::Dispatch(manager, result, mesh);

    openxr_wrappers::DestroyWrappedHandle<openxr_wrappers::TriangleMeshFBWrapper>(mesh);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshGetVertexBufferFB(XrTriangleMeshFB mesh, XrVector3f** outVertexBuffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshGetVertexBufferFB>::PreLockReentrant(
        manager, mesh, outVertexBuffer);
    CommonCaptureManager::CaptureMode save_capture_mode;
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshGetVertexBufferFB>::Dispatch(
            manager, mesh, outVertexBuffer);
        save_capture_mode = manager->GetCaptureMode();
        manager->SetCaptureMode(CommonCaptureManager::CaptureModeFlags::kModeDisabled);
    }

    XrResult result = openxr_wrappers::GetInstanceTable(mesh)->TriangleMeshGetVertexBufferFB(mesh, outVertexBuffer);

    auto call_lock = manager->AcquireCallLock();
    manager->SetCaptureMode(save_capture_mode);

    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTriangleMeshGetVertexBufferFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(mesh);

        auto tri_mesh_fb_wrapper = openxr_wrappers::GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
        EncodeStructArray<XrVector3f>(
            encoder, *outVertexBuffer, tri_mesh_fb_wrapper->create_info.vertexCount, omit_output_data);

        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrTriangleMeshGetVertexBufferFB>::Dispatch(
        manager, result, mesh, outVertexBuffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshGetIndexBufferFB(XrTriangleMeshFB mesh, uint32_t** outIndexBuffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshGetIndexBufferFB>::PreLockReentrant(
        manager, mesh, outIndexBuffer);
    CommonCaptureManager::CaptureMode save_capture_mode;
    {
        auto call_lock = manager->AcquireCallLock();

        CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshGetIndexBufferFB>::Dispatch(
            manager, mesh, outIndexBuffer);
        save_capture_mode = manager->GetCaptureMode();
        manager->SetCaptureMode(CommonCaptureManager::CaptureModeFlags::kModeDisabled);
    }

    XrResult result = openxr_wrappers::GetInstanceTable(mesh)->TriangleMeshGetIndexBufferFB(mesh, outIndexBuffer);

    auto call_lock = manager->AcquireCallLock();
    manager->SetCaptureMode(save_capture_mode);

    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTriangleMeshGetIndexBufferFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(mesh);

        auto tri_mesh_fb_wrapper = openxr_wrappers::GetWrapper<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
        encoder->EncodeUInt32Array(*outIndexBuffer, tri_mesh_fb_wrapper->create_info.triangleCount * 3);

        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrTriangleMeshGetIndexBufferFB>::Dispatch(
        manager, result, mesh, outIndexBuffer);

    return result;
}

static void ForceVulkanEnumeratePhysicalDevices(VkInstance vkInstance)
{
    if (vkInstance == VK_NULL_HANDLE)
        return;

    // Force gfxrecon Vulkan entrypoints to get the physical device information
    // NOTE: Must be called without the lock held
    //
    // NOTE: this adds a phantom call to the capture file, but on replay assures that the Vulkan side has the physical
    // device handle mapping it will need.  Xr can't create that handle mapping because it has a different *wrapped*
    // handle from the loader and cannot determine the mapping from the wrapped physical device it has to the
    // unwrapped physical devices
    //
    // NOTE: Despite the naming these are calls to encode::vkEnumeratePhysicalDevices not API/down-layer calls
    uint32_t device_count = 0;
    vkEnumeratePhysicalDevices(vkInstance, &device_count, nullptr);
    std::vector<VkPhysicalDevice> vk_devices(device_count);
    vkEnumeratePhysicalDevices(vkInstance, &device_count, vk_devices.data());
}

void CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDeviceKHR>::PreLockReentrant(
    OpenXrCaptureManager*, XrInstance, XrSystemId, VkInstance vkInstance, VkPhysicalDevice*)
{
    ForceVulkanEnumeratePhysicalDevices(vkInstance);
}

void CustomEncoderPreCall<format::ApiCallId::ApiCall_xrGetVulkanGraphicsDevice2KHR>::PreLockReentrant(
    OpenXrCaptureManager*, XrInstance, const XrVulkanGraphicsDeviceGetInfoKHR* getInfo, VkPhysicalDevice*)
{
    if (getInfo)
    {
        ForceVulkanEnumeratePhysicalDevices(getInfo->vulkanInstance);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
