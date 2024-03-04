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

#ifndef  GFXRECON_GENERATED_OPENXR_LAYER_FUNC_TABLE_H
#define  GFXRECON_GENERATED_OPENXR_LAYER_FUNC_TABLE_H

#include "encode/custom_openxr_api_call_encoders.h"
#include "generated/generated_openxr_api_call_encoders.h"
#include "layer/trace_layer.h"
#include "util/defines.h"

#include <openxr/openxr.h>

#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

const std::unordered_map<std::string, PFN_xrVoidFunction> openxr_func_table = {
    { "xrGetInstanceProcAddr",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::GetInstanceProcAddr) },
    { "xrEnumerateApiLayerProperties",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateApiLayerProperties) },
    { "xrEnumerateInstanceExtensionProperties",                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateInstanceExtensionProperties) },
    { "xrCreateInstance",                                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::CreateInstance) },
    { "xrDestroyInstance",                                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyInstance) },
    { "xrGetInstanceProperties",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::GetInstanceProperties) },
    { "xrPollEvent",                                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::PollEvent) },
    { "xrResultToString",                                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::ResultToString) },
    { "xrStructureTypeToString",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::StructureTypeToString) },
    { "xrGetSystem",                                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::GetSystem) },
    { "xrGetSystemProperties",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::GetSystemProperties) },
    { "xrEnumerateEnvironmentBlendModes",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateEnvironmentBlendModes) },
    { "xrCreateSession",                                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSession) },
    { "xrDestroySession",                                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::DestroySession) },
    { "xrEnumerateReferenceSpaces",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateReferenceSpaces) },
    { "xrCreateReferenceSpace",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::CreateReferenceSpace) },
    { "xrGetReferenceSpaceBoundsRect",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::GetReferenceSpaceBoundsRect) },
    { "xrCreateActionSpace",                                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::CreateActionSpace) },
    { "xrLocateSpace",                                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::LocateSpace) },
    { "xrDestroySpace",                                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::DestroySpace) },
    { "xrEnumerateViewConfigurations",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateViewConfigurations) },
    { "xrGetViewConfigurationProperties",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::GetViewConfigurationProperties) },
    { "xrEnumerateViewConfigurationViews",                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateViewConfigurationViews) },
    { "xrEnumerateSwapchainFormats",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateSwapchainFormats) },
    { "xrCreateSwapchain",                                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSwapchain) },
    { "xrDestroySwapchain",                                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::DestroySwapchain) },
    { "xrEnumerateSwapchainImages",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateSwapchainImages) },
    { "xrAcquireSwapchainImage",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::AcquireSwapchainImage) },
    { "xrWaitSwapchainImage",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::WaitSwapchainImage) },
    { "xrReleaseSwapchainImage",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::ReleaseSwapchainImage) },
    { "xrBeginSession",                                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::BeginSession) },
    { "xrEndSession",                                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::EndSession) },
    { "xrRequestExitSession",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::RequestExitSession) },
    { "xrWaitFrame",                                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::WaitFrame) },
    { "xrBeginFrame",                                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::BeginFrame) },
    { "xrEndFrame",                                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::EndFrame) },
    { "xrLocateViews",                                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::LocateViews) },
    { "xrStringToPath",                                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::StringToPath) },
    { "xrPathToString",                                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::PathToString) },
    { "xrCreateActionSet",                                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::CreateActionSet) },
    { "xrDestroyActionSet",                                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyActionSet) },
    { "xrCreateAction",                                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::CreateAction) },
    { "xrDestroyAction",                                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyAction) },
    { "xrSuggestInteractionProfileBindings",                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::SuggestInteractionProfileBindings) },
    { "xrAttachSessionActionSets",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::AttachSessionActionSets) },
    { "xrGetCurrentInteractionProfile",                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::GetCurrentInteractionProfile) },
    { "xrGetActionStateBoolean",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::GetActionStateBoolean) },
    { "xrGetActionStateFloat",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::GetActionStateFloat) },
    { "xrGetActionStateVector2f",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::GetActionStateVector2f) },
    { "xrGetActionStatePose",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::GetActionStatePose) },
    { "xrSyncActions",                                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::SyncActions) },
    { "xrEnumerateBoundSourcesForAction",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateBoundSourcesForAction) },
    { "xrGetInputSourceLocalizedName",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::GetInputSourceLocalizedName) },
    { "xrApplyHapticFeedback",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::ApplyHapticFeedback) },
    { "xrStopHapticFeedback",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::StopHapticFeedback) },
    { "xrCreateApiLayerInstance",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::CreateApiLayerInstance) },
    { "xrNegotiateLoaderRuntimeInterface",                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::NegotiateLoaderRuntimeInterface) },
    { "xrNegotiateLoaderApiLayerInterface",                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::NegotiateLoaderApiLayerInterface) },
#ifdef XR_USE_PLATFORM_ANDROID
    { "xrSetAndroidApplicationThreadKHR",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::SetAndroidApplicationThreadKHR) },
#endif /* XR_USE_PLATFORM_ANDROID */
#ifdef XR_USE_PLATFORM_ANDROID
    { "xrCreateSwapchainAndroidSurfaceKHR",                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSwapchainAndroidSurfaceKHR) },
#endif /* XR_USE_PLATFORM_ANDROID */
#ifdef XR_USE_GRAPHICS_API_OPENGL
    { "xrGetOpenGLGraphicsRequirementsKHR",                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::GetOpenGLGraphicsRequirementsKHR) },
#endif /* XR_USE_GRAPHICS_API_OPENGL */
#ifdef XR_USE_GRAPHICS_API_OPENGL_ES
    { "xrGetOpenGLESGraphicsRequirementsKHR",                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::GetOpenGLESGraphicsRequirementsKHR) },
#endif /* XR_USE_GRAPHICS_API_OPENGL_ES */
#ifdef XR_USE_GRAPHICS_API_VULKAN
    { "xrGetVulkanInstanceExtensionsKHR",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::GetVulkanInstanceExtensionsKHR) },
    { "xrGetVulkanDeviceExtensionsKHR",                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::GetVulkanDeviceExtensionsKHR) },
    { "xrGetVulkanGraphicsDeviceKHR",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::GetVulkanGraphicsDeviceKHR) },
    { "xrGetVulkanGraphicsRequirementsKHR",                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::GetVulkanGraphicsRequirementsKHR) },
#endif /* XR_USE_GRAPHICS_API_VULKAN */
#ifdef XR_USE_GRAPHICS_API_D3D11
    { "xrGetD3D11GraphicsRequirementsKHR",                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::GetD3D11GraphicsRequirementsKHR) },
#endif /* XR_USE_GRAPHICS_API_D3D11 */
#ifdef XR_USE_GRAPHICS_API_D3D12
    { "xrGetD3D12GraphicsRequirementsKHR",                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::GetD3D12GraphicsRequirementsKHR) },
#endif /* XR_USE_GRAPHICS_API_D3D12 */
    { "xrGetVisibilityMaskKHR",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::GetVisibilityMaskKHR) },
#ifdef XR_USE_PLATFORM_WIN32
    { "xrConvertWin32PerformanceCounterToTimeKHR",                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::ConvertWin32PerformanceCounterToTimeKHR) },
    { "xrConvertTimeToWin32PerformanceCounterKHR",                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::ConvertTimeToWin32PerformanceCounterKHR) },
#endif /* XR_USE_PLATFORM_WIN32 */
#ifdef XR_USE_TIMESPEC
    { "xrConvertTimespecTimeToTimeKHR",                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::ConvertTimespecTimeToTimeKHR) },
    { "xrConvertTimeToTimespecTimeKHR",                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::ConvertTimeToTimespecTimeKHR) },
#endif /* XR_USE_TIMESPEC */
    { "xrInitializeLoaderKHR",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::InitializeLoaderKHR) },
#ifdef XR_USE_GRAPHICS_API_VULKAN
    { "xrCreateVulkanInstanceKHR",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::CreateVulkanInstanceKHR) },
    { "xrCreateVulkanDeviceKHR",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::CreateVulkanDeviceKHR) },
    { "xrGetVulkanGraphicsDevice2KHR",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::GetVulkanGraphicsDevice2KHR) },
    { "xrGetVulkanGraphicsRequirements2KHR",                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::GetVulkanGraphicsRequirements2KHR) },
#endif /* XR_USE_GRAPHICS_API_VULKAN */
    { "xrPerfSettingsSetPerformanceLevelEXT",                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::PerfSettingsSetPerformanceLevelEXT) },
    { "xrThermalGetTemperatureTrendEXT",                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::ThermalGetTemperatureTrendEXT) },
    { "xrSetDebugUtilsObjectNameEXT",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::SetDebugUtilsObjectNameEXT) },
    { "xrCreateDebugUtilsMessengerEXT",                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::CreateDebugUtilsMessengerEXT) },
    { "xrDestroyDebugUtilsMessengerEXT",                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyDebugUtilsMessengerEXT) },
    { "xrSubmitDebugUtilsMessageEXT",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::SubmitDebugUtilsMessageEXT) },
    { "xrSessionBeginDebugUtilsLabelRegionEXT",                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::SessionBeginDebugUtilsLabelRegionEXT) },
    { "xrSessionEndDebugUtilsLabelRegionEXT",                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::SessionEndDebugUtilsLabelRegionEXT) },
    { "xrSessionInsertDebugUtilsLabelEXT",                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::SessionInsertDebugUtilsLabelEXT) },
    { "xrCreateSpatialAnchorMSFT",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSpatialAnchorMSFT) },
    { "xrCreateSpatialAnchorSpaceMSFT",                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSpatialAnchorSpaceMSFT) },
    { "xrDestroySpatialAnchorMSFT",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::DestroySpatialAnchorMSFT) },
    { "xrSetInputDeviceActiveEXT",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::SetInputDeviceActiveEXT) },
    { "xrSetInputDeviceStateBoolEXT",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::SetInputDeviceStateBoolEXT) },
    { "xrSetInputDeviceStateFloatEXT",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::SetInputDeviceStateFloatEXT) },
    { "xrSetInputDeviceStateVector2fEXT",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::SetInputDeviceStateVector2fEXT) },
    { "xrSetInputDeviceLocationEXT",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::SetInputDeviceLocationEXT) },
    { "xrCreateSpatialGraphNodeSpaceMSFT",                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSpatialGraphNodeSpaceMSFT) },
    { "xrTryCreateSpatialGraphStaticNodeBindingMSFT",                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::TryCreateSpatialGraphStaticNodeBindingMSFT) },
    { "xrDestroySpatialGraphNodeBindingMSFT",                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::DestroySpatialGraphNodeBindingMSFT) },
    { "xrGetSpatialGraphNodeBindingPropertiesMSFT",                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpatialGraphNodeBindingPropertiesMSFT) },
    { "xrCreateHandTrackerEXT",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::CreateHandTrackerEXT) },
    { "xrDestroyHandTrackerEXT",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyHandTrackerEXT) },
    { "xrLocateHandJointsEXT",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::LocateHandJointsEXT) },
    { "xrCreateHandMeshSpaceMSFT",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::CreateHandMeshSpaceMSFT) },
    { "xrUpdateHandMeshMSFT",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::UpdateHandMeshMSFT) },
    { "xrGetControllerModelKeyMSFT",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::GetControllerModelKeyMSFT) },
    { "xrLoadControllerModelMSFT",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::LoadControllerModelMSFT) },
    { "xrGetControllerModelPropertiesMSFT",                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::GetControllerModelPropertiesMSFT) },
    { "xrGetControllerModelStateMSFT",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::GetControllerModelStateMSFT) },
#ifdef XR_USE_PLATFORM_WIN32
    { "xrCreateSpatialAnchorFromPerceptionAnchorMSFT",                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSpatialAnchorFromPerceptionAnchorMSFT) },
    { "xrTryGetPerceptionAnchorFromSpatialAnchorMSFT",                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::TryGetPerceptionAnchorFromSpatialAnchorMSFT) },
#endif /* XR_USE_PLATFORM_WIN32 */
    { "xrEnumerateReprojectionModesMSFT",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateReprojectionModesMSFT) },
    { "xrUpdateSwapchainFB",                                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::UpdateSwapchainFB) },
    { "xrGetSwapchainStateFB",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::GetSwapchainStateFB) },
    { "xrCreateBodyTrackerFB",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::CreateBodyTrackerFB) },
    { "xrDestroyBodyTrackerFB",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyBodyTrackerFB) },
    { "xrLocateBodyJointsFB",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::LocateBodyJointsFB) },
    { "xrGetBodySkeletonFB",                                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::GetBodySkeletonFB) },
    { "xrEnumerateSceneComputeFeaturesMSFT",                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateSceneComputeFeaturesMSFT) },
    { "xrCreateSceneObserverMSFT",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSceneObserverMSFT) },
    { "xrDestroySceneObserverMSFT",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::DestroySceneObserverMSFT) },
    { "xrCreateSceneMSFT",                                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSceneMSFT) },
    { "xrDestroySceneMSFT",                                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::DestroySceneMSFT) },
    { "xrComputeNewSceneMSFT",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::ComputeNewSceneMSFT) },
    { "xrGetSceneComputeStateMSFT",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::GetSceneComputeStateMSFT) },
    { "xrGetSceneComponentsMSFT",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::GetSceneComponentsMSFT) },
    { "xrLocateSceneComponentsMSFT",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::LocateSceneComponentsMSFT) },
    { "xrGetSceneMeshBuffersMSFT",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::GetSceneMeshBuffersMSFT) },
    { "xrDeserializeSceneMSFT",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::DeserializeSceneMSFT) },
    { "xrGetSerializedSceneFragmentDataMSFT",                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::GetSerializedSceneFragmentDataMSFT) },
    { "xrEnumerateDisplayRefreshRatesFB",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateDisplayRefreshRatesFB) },
    { "xrGetDisplayRefreshRateFB",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::GetDisplayRefreshRateFB) },
    { "xrRequestDisplayRefreshRateFB",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::RequestDisplayRefreshRateFB) },
    { "xrEnumerateViveTrackerPathsHTCX",                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateViveTrackerPathsHTCX) },
    { "xrCreateFacialTrackerHTC",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::CreateFacialTrackerHTC) },
    { "xrDestroyFacialTrackerHTC",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyFacialTrackerHTC) },
    { "xrGetFacialExpressionsHTC",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::GetFacialExpressionsHTC) },
    { "xrEnumerateColorSpacesFB",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateColorSpacesFB) },
    { "xrSetColorSpaceFB",                                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::SetColorSpaceFB) },
    { "xrGetHandMeshFB",                                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::GetHandMeshFB) },
    { "xrCreateSpatialAnchorFB",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSpatialAnchorFB) },
    { "xrGetSpaceUuidFB",                                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpaceUuidFB) },
    { "xrEnumerateSpaceSupportedComponentsFB",                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateSpaceSupportedComponentsFB) },
    { "xrSetSpaceComponentStatusFB",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::SetSpaceComponentStatusFB) },
    { "xrGetSpaceComponentStatusFB",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpaceComponentStatusFB) },
    { "xrCreateFoveationProfileFB",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::CreateFoveationProfileFB) },
    { "xrDestroyFoveationProfileFB",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyFoveationProfileFB) },
    { "xrQuerySystemTrackedKeyboardFB",                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::QuerySystemTrackedKeyboardFB) },
    { "xrCreateKeyboardSpaceFB",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::CreateKeyboardSpaceFB) },
    { "xrCreateTriangleMeshFB",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::CreateTriangleMeshFB) },
    { "xrDestroyTriangleMeshFB",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyTriangleMeshFB) },
    { "xrTriangleMeshGetVertexBufferFB",                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::TriangleMeshGetVertexBufferFB) },
    { "xrTriangleMeshGetIndexBufferFB",                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::TriangleMeshGetIndexBufferFB) },
    { "xrTriangleMeshBeginUpdateFB",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::TriangleMeshBeginUpdateFB) },
    { "xrTriangleMeshEndUpdateFB",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::TriangleMeshEndUpdateFB) },
    { "xrTriangleMeshBeginVertexBufferUpdateFB",                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::TriangleMeshBeginVertexBufferUpdateFB) },
    { "xrTriangleMeshEndVertexBufferUpdateFB",                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::TriangleMeshEndVertexBufferUpdateFB) },
    { "xrCreatePassthroughFB",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::CreatePassthroughFB) },
    { "xrDestroyPassthroughFB",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyPassthroughFB) },
    { "xrPassthroughStartFB",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::PassthroughStartFB) },
    { "xrPassthroughPauseFB",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::PassthroughPauseFB) },
    { "xrCreatePassthroughLayerFB",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::CreatePassthroughLayerFB) },
    { "xrDestroyPassthroughLayerFB",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyPassthroughLayerFB) },
    { "xrPassthroughLayerPauseFB",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::PassthroughLayerPauseFB) },
    { "xrPassthroughLayerResumeFB",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::PassthroughLayerResumeFB) },
    { "xrPassthroughLayerSetStyleFB",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::PassthroughLayerSetStyleFB) },
    { "xrCreateGeometryInstanceFB",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::CreateGeometryInstanceFB) },
    { "xrDestroyGeometryInstanceFB",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyGeometryInstanceFB) },
    { "xrGeometryInstanceSetTransformFB",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::GeometryInstanceSetTransformFB) },
    { "xrEnumerateRenderModelPathsFB",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateRenderModelPathsFB) },
    { "xrGetRenderModelPropertiesFB",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::GetRenderModelPropertiesFB) },
    { "xrLoadRenderModelFB",                                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::LoadRenderModelFB) },
    { "xrSetEnvironmentDepthEstimationVARJO",                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::SetEnvironmentDepthEstimationVARJO) },
    { "xrSetMarkerTrackingVARJO",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::SetMarkerTrackingVARJO) },
    { "xrSetMarkerTrackingTimeoutVARJO",                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::SetMarkerTrackingTimeoutVARJO) },
    { "xrSetMarkerTrackingPredictionVARJO",                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::SetMarkerTrackingPredictionVARJO) },
    { "xrGetMarkerSizeVARJO",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::GetMarkerSizeVARJO) },
    { "xrCreateMarkerSpaceVARJO",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::CreateMarkerSpaceVARJO) },
    { "xrSetViewOffsetVARJO",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::SetViewOffsetVARJO) },
#ifdef XR_USE_PLATFORM_ML
    { "xrCreateSpaceFromCoordinateFrameUIDML",                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSpaceFromCoordinateFrameUIDML) },
#endif /* XR_USE_PLATFORM_ML */
    { "xrCreateMarkerDetectorML",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::CreateMarkerDetectorML) },
    { "xrDestroyMarkerDetectorML",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyMarkerDetectorML) },
    { "xrSnapshotMarkerDetectorML",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::SnapshotMarkerDetectorML) },
    { "xrGetMarkerDetectorStateML",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::GetMarkerDetectorStateML) },
    { "xrGetMarkersML",                                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::GetMarkersML) },
    { "xrGetMarkerReprojectionErrorML",                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::GetMarkerReprojectionErrorML) },
    { "xrGetMarkerLengthML",                                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::GetMarkerLengthML) },
    { "xrGetMarkerNumberML",                                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::GetMarkerNumberML) },
    { "xrGetMarkerStringML",                                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::GetMarkerStringML) },
    { "xrCreateMarkerSpaceML",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::CreateMarkerSpaceML) },
    { "xrEnableLocalizationEventsML",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::EnableLocalizationEventsML) },
    { "xrQueryLocalizationMapsML",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::QueryLocalizationMapsML) },
    { "xrRequestMapLocalizationML",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::RequestMapLocalizationML) },
    { "xrImportLocalizationMapML",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::ImportLocalizationMapML) },
    { "xrCreateExportedLocalizationMapML",                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::CreateExportedLocalizationMapML) },
    { "xrDestroyExportedLocalizationMapML",                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyExportedLocalizationMapML) },
    { "xrGetExportedLocalizationMapDataML",                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::GetExportedLocalizationMapDataML) },
    { "xrCreateSpatialAnchorStoreConnectionMSFT",                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSpatialAnchorStoreConnectionMSFT) },
    { "xrDestroySpatialAnchorStoreConnectionMSFT",                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::DestroySpatialAnchorStoreConnectionMSFT) },
    { "xrPersistSpatialAnchorMSFT",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::PersistSpatialAnchorMSFT) },
    { "xrEnumeratePersistedSpatialAnchorNamesMSFT",                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::EnumeratePersistedSpatialAnchorNamesMSFT) },
    { "xrCreateSpatialAnchorFromPersistedNameMSFT",                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSpatialAnchorFromPersistedNameMSFT) },
    { "xrUnpersistSpatialAnchorMSFT",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::UnpersistSpatialAnchorMSFT) },
    { "xrClearSpatialAnchorStoreMSFT",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::ClearSpatialAnchorStoreMSFT) },
    { "xrGetSceneMarkerRawDataMSFT",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::GetSceneMarkerRawDataMSFT) },
    { "xrGetSceneMarkerDecodedStringMSFT",                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::GetSceneMarkerDecodedStringMSFT) },
    { "xrQuerySpacesFB",                                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::QuerySpacesFB) },
    { "xrRetrieveSpaceQueryResultsFB",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::RetrieveSpaceQueryResultsFB) },
    { "xrSaveSpaceFB",                                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::SaveSpaceFB) },
    { "xrEraseSpaceFB",                                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::EraseSpaceFB) },
#ifdef XR_USE_PLATFORM_WIN32
    { "xrGetAudioOutputDeviceGuidOculus",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::GetAudioOutputDeviceGuidOculus) },
    { "xrGetAudioInputDeviceGuidOculus",                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::GetAudioInputDeviceGuidOculus) },
#endif /* XR_USE_PLATFORM_WIN32 */
    { "xrShareSpacesFB",                                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::ShareSpacesFB) },
    { "xrGetSpaceBoundingBox2DFB",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpaceBoundingBox2DFB) },
    { "xrGetSpaceBoundingBox3DFB",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpaceBoundingBox3DFB) },
    { "xrGetSpaceSemanticLabelsFB",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpaceSemanticLabelsFB) },
    { "xrGetSpaceBoundary2DFB",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpaceBoundary2DFB) },
    { "xrGetSpaceRoomLayoutFB",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpaceRoomLayoutFB) },
    { "xrSetDigitalLensControlALMALENCE",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::SetDigitalLensControlALMALENCE) },
    { "xrRequestSceneCaptureFB",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::RequestSceneCaptureFB) },
    { "xrGetSpaceContainerFB",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpaceContainerFB) },
    { "xrGetFoveationEyeTrackedStateMETA",                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::GetFoveationEyeTrackedStateMETA) },
    { "xrCreateFaceTrackerFB",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::CreateFaceTrackerFB) },
    { "xrDestroyFaceTrackerFB",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyFaceTrackerFB) },
    { "xrGetFaceExpressionWeightsFB",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::GetFaceExpressionWeightsFB) },
    { "xrCreateEyeTrackerFB",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::CreateEyeTrackerFB) },
    { "xrDestroyEyeTrackerFB",                                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyEyeTrackerFB) },
    { "xrGetEyeGazesFB",                                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::GetEyeGazesFB) },
    { "xrPassthroughLayerSetKeyboardHandsIntensityFB",                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::PassthroughLayerSetKeyboardHandsIntensityFB) },
    { "xrGetDeviceSampleRateFB",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::GetDeviceSampleRateFB) },
    { "xrGetPassthroughPreferencesMETA",                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::GetPassthroughPreferencesMETA) },
    { "xrCreateVirtualKeyboardMETA",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::CreateVirtualKeyboardMETA) },
    { "xrDestroyVirtualKeyboardMETA",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyVirtualKeyboardMETA) },
    { "xrCreateVirtualKeyboardSpaceMETA",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::CreateVirtualKeyboardSpaceMETA) },
    { "xrSuggestVirtualKeyboardLocationMETA",                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::SuggestVirtualKeyboardLocationMETA) },
    { "xrGetVirtualKeyboardScaleMETA",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::GetVirtualKeyboardScaleMETA) },
    { "xrSetVirtualKeyboardModelVisibilityMETA",                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::SetVirtualKeyboardModelVisibilityMETA) },
    { "xrGetVirtualKeyboardModelAnimationStatesMETA",                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::GetVirtualKeyboardModelAnimationStatesMETA) },
    { "xrGetVirtualKeyboardDirtyTexturesMETA",                                                               reinterpret_cast<PFN_xrVoidFunction>(encode::GetVirtualKeyboardDirtyTexturesMETA) },
    { "xrGetVirtualKeyboardTextureDataMETA",                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::GetVirtualKeyboardTextureDataMETA) },
    { "xrSendVirtualKeyboardInputMETA",                                                                      reinterpret_cast<PFN_xrVoidFunction>(encode::SendVirtualKeyboardInputMETA) },
    { "xrChangeVirtualKeyboardTextContextMETA",                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::ChangeVirtualKeyboardTextContextMETA) },
    { "xrEnumerateExternalCamerasOCULUS",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::EnumerateExternalCamerasOCULUS) },
    { "xrEnumeratePerformanceMetricsCounterPathsMETA",                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::EnumeratePerformanceMetricsCounterPathsMETA) },
    { "xrSetPerformanceMetricsStateMETA",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::SetPerformanceMetricsStateMETA) },
    { "xrGetPerformanceMetricsStateMETA",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::GetPerformanceMetricsStateMETA) },
    { "xrQueryPerformanceMetricsCounterMETA",                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::QueryPerformanceMetricsCounterMETA) },
    { "xrSaveSpaceListFB",                                                                                   reinterpret_cast<PFN_xrVoidFunction>(encode::SaveSpaceListFB) },
    { "xrCreateSpaceUserFB",                                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSpaceUserFB) },
    { "xrGetSpaceUserIdFB",                                                                                  reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpaceUserIdFB) },
    { "xrDestroySpaceUserFB",                                                                                reinterpret_cast<PFN_xrVoidFunction>(encode::DestroySpaceUserFB) },
    { "xrGetRecommendedLayerResolutionMETA",                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::GetRecommendedLayerResolutionMETA) },
    { "xrCreatePassthroughColorLutMETA",                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::CreatePassthroughColorLutMETA) },
    { "xrDestroyPassthroughColorLutMETA",                                                                    reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyPassthroughColorLutMETA) },
    { "xrUpdatePassthroughColorLutMETA",                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::UpdatePassthroughColorLutMETA) },
    { "xrGetSpaceTriangleMeshMETA",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpaceTriangleMeshMETA) },
    { "xrCreateFaceTracker2FB",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::CreateFaceTracker2FB) },
    { "xrDestroyFaceTracker2FB",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyFaceTracker2FB) },
    { "xrGetFaceExpressionWeights2FB",                                                                       reinterpret_cast<PFN_xrVoidFunction>(encode::GetFaceExpressionWeights2FB) },
    { "xrSetTrackingOptimizationSettingsHintQCOM",                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::SetTrackingOptimizationSettingsHintQCOM) },
    { "xrCreatePassthroughHTC",                                                                              reinterpret_cast<PFN_xrVoidFunction>(encode::CreatePassthroughHTC) },
    { "xrDestroyPassthroughHTC",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyPassthroughHTC) },
    { "xrApplyFoveationHTC",                                                                                 reinterpret_cast<PFN_xrVoidFunction>(encode::ApplyFoveationHTC) },
    { "xrCreateSpatialAnchorHTC",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::CreateSpatialAnchorHTC) },
    { "xrGetSpatialAnchorNameHTC",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::GetSpatialAnchorNameHTC) },
    { "xrApplyForceFeedbackCurlMNDX",                                                                        reinterpret_cast<PFN_xrVoidFunction>(encode::ApplyForceFeedbackCurlMNDX) },
    { "xrCreatePlaneDetectorEXT",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::CreatePlaneDetectorEXT) },
    { "xrDestroyPlaneDetectorEXT",                                                                           reinterpret_cast<PFN_xrVoidFunction>(encode::DestroyPlaneDetectorEXT) },
    { "xrBeginPlaneDetectionEXT",                                                                            reinterpret_cast<PFN_xrVoidFunction>(encode::BeginPlaneDetectionEXT) },
    { "xrGetPlaneDetectionStateEXT",                                                                         reinterpret_cast<PFN_xrVoidFunction>(encode::GetPlaneDetectionStateEXT) },
    { "xrGetPlaneDetectionsEXT",                                                                             reinterpret_cast<PFN_xrVoidFunction>(encode::GetPlaneDetectionsEXT) },
    { "xrGetPlanePolygonBufferEXT",                                                                          reinterpret_cast<PFN_xrVoidFunction>(encode::GetPlanePolygonBufferEXT) },
    { "xrEnableUserCalibrationEventsML",                                                                     reinterpret_cast<PFN_xrVoidFunction>(encode::EnableUserCalibrationEventsML) },
};

GFXRECON_END_NAMESPACE(gfxrecon)

#endif //  GFXRECON_GENERATED_OPENXR_LAYER_FUNC_TABLE_H
