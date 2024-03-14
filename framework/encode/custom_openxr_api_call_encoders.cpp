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
#include "format/api_call_id.h"
#include "generated/generated_openxr_struct_handle_wrappers.h"
#include "util/defines.h"

#include "openxr/openxr.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

XRAPI_ATTR XrResult XRAPI_CALL CreateVulkanInstanceKHR(XrInstance                           instance,
                                                       const XrVulkanInstanceCreateInfoKHR* createInfo,
                                                       VkInstance*                          vulkanInstance,
                                                       VkResult*                            vulkanResult)
{
    // TODO : Brainpain
    return XR_SUCCESS;
}

XRAPI_ATTR XrResult XRAPI_CALL CreateVulkanDeviceKHR(XrInstance                         instance,
                                                     const XrVulkanDeviceCreateInfoKHR* createInfo,
                                                     VkDevice*                          vulkanDevice,
                                                     VkResult*                          vulkanResult)
{
    // TODO : Brainpain
    return XR_SUCCESS;
}

XRAPI_ATTR XrResult XRAPI_CALL GetVulkanGraphicsDevice2KHR(XrInstance                              instance,
                                                           const XrVulkanGraphicsDeviceGetInfoKHR* getInfo,
                                                           VkPhysicalDevice*                       vulkanPhysicalDevice)
{
    // TODO : Brainpain
    return XR_SUCCESS;
}

XRAPI_ATTR XrResult XRAPI_CALL CreateTriangleMeshFB(XrSession                         session,
                                                    const XrTriangleMeshCreateInfoFB* createInfo,
                                                    XrTriangleMeshFB*                 outTriangleMesh)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
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

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrCreateTriangleMeshFB>::Dispatch(
        manager, session, createInfo, outTriangleMesh);

    XrResult result = GetOpenXrInstanceTable(session)->CreateTriangleMeshFB(session, createInfo, outTriangleMesh);

    if (result >= 0)
    {
        CreateWrappedOpenXrHandle<openxr_wrappers::SessionWrapper,
                                  OpenXrNoParentWrapper,
                                  openxr_wrappers::TriangleMeshFBWrapper>(
            session, OpenXrNoParentWrapper::kHandleValue, outTriangleMesh, OpenXrCaptureManager::GetUniqueId);
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
        auto tri_mesh_fb_wrapper = GetOpenXrWrapper<openxr_wrappers::TriangleMeshFBWrapper>(*outTriangleMesh);
        memcpy(&tri_mesh_fb_wrapper->create_info, createInfo, sizeof(XrTriangleMeshCreateInfoFB));
        tri_mesh_fb_wrapper->create_info.next = nullptr;
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrCreateTriangleMeshFB>::Dispatch(
        manager, result, session, createInfo, outTriangleMesh);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL DestroyTriangleMeshFB(XrTriangleMeshFB mesh)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
    std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;
    if (force_command_serialization)
    {
        exclusive_api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();
    }
    else
    {
        shared_api_call_lock = OpenXrCaptureManager::AcquireSharedApiCallLock();
    }

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrDestroyTriangleMeshFB>::Dispatch(manager, mesh);

    ScopedDestroyLock exclusive_scoped_lock;
    XrResult          result = GetOpenXrInstanceTable(mesh)->DestroyTriangleMeshFB(mesh);

    auto encoder = manager->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_xrDestroyTriangleMeshFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
        encoder->EncodeEnumValue(result);
        manager->EndDestroyApiCallCapture<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrDestroyTriangleMeshFB>::Dispatch(manager, result, mesh);

    DestroyWrappedOpenXrHandle<openxr_wrappers::TriangleMeshFBWrapper>(mesh);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshGetVertexBufferFB(XrTriangleMeshFB mesh, XrVector3f** outVertexBuffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
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

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshGetVertexBufferFB>::Dispatch(
        manager, mesh, outVertexBuffer);

    XrResult result = GetOpenXrInstanceTable(mesh)->TriangleMeshGetVertexBufferFB(mesh, outVertexBuffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTriangleMeshGetVertexBufferFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(mesh);

        auto tri_mesh_fb_wrapper = GetOpenXrWrapper<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
        EncodeStructArray<XrVector3f>(
            encoder, *outVertexBuffer, tri_mesh_fb_wrapper->create_info.vertexCount, omit_output_data);

        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrTriangleMeshGetVertexBufferFB>::Dispatch(
        manager, result, mesh, outVertexBuffer);

    return result;
}

XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshGetIndexBufferFB(XrTriangleMeshFB mesh, uint32_t** outIndexBuffer)
{
    OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();
    GFXRECON_ASSERT(manager != nullptr);
    auto force_command_serialization = manager->GetForceCommandSerialization();
    std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;
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

    CustomEncoderPreCall<format::ApiCallId::ApiCall_xrTriangleMeshGetIndexBufferFB>::Dispatch(
        manager, mesh, outIndexBuffer);

    XrResult result = GetOpenXrInstanceTable(mesh)->TriangleMeshGetIndexBufferFB(mesh, outIndexBuffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = manager->BeginApiCallCapture(format::ApiCallId::ApiCall_xrTriangleMeshGetIndexBufferFB);
    if (encoder)
    {
        encoder->EncodeOpenXrHandleValue<openxr_wrappers::TriangleMeshFBWrapper>(mesh);

        auto tri_mesh_fb_wrapper = GetOpenXrWrapper<openxr_wrappers::TriangleMeshFBWrapper>(mesh);
        encoder->EncodeUInt32Array(*outIndexBuffer, tri_mesh_fb_wrapper->create_info.triangleCount * 3);

        encoder->EncodeEnumValue(result);
        manager->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_xrTriangleMeshGetIndexBufferFB>::Dispatch(
        manager, result, mesh, outIndexBuffer);

    return result;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
