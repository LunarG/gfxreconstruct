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

#ifndef  GFXRECON_GENERATED_OPENXR_DISPATCH_TABLE_H
#define  GFXRECON_GENERATED_OPENXR_DISPATCH_TABLE_H

#ifdef ENABLE_OPENXR_SUPPORT


#include "format/platform_types.h"
#include "util/defines.h"
#include "util/logging.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

GFXRECON_BEGIN_NAMESPACE(noop)
// clang-format off
static XRAPI_ATTR XrResult XRAPI_CALL xrGetInstanceProcAddr(XrInstance, const char*, PFN_xrVoidFunction*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetInstanceProcAddr was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyInstance(XrInstance) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyInstance was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetInstanceProperties(XrInstance, XrInstanceProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetInstanceProperties was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrPollEvent(XrInstance, XrEventDataBuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPollEvent was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrResultToString(XrInstance, XrResult, char[XR_MAX_RESULT_STRING_SIZE]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrResultToString was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrStructureTypeToString(XrInstance, XrStructureType, char[XR_MAX_STRUCTURE_NAME_SIZE]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrStructureTypeToString was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSystem(XrInstance, const XrSystemGetInfo*, XrSystemId*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSystem was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSystemProperties(XrInstance, XrSystemId, XrSystemProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSystemProperties was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateEnvironmentBlendModes(XrInstance, XrSystemId, XrViewConfigurationType, uint32_t, uint32_t*, XrEnvironmentBlendMode*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateEnvironmentBlendModes was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSession(XrInstance, const XrSessionCreateInfo*, XrSession*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSession was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroySession(XrSession) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySession was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateReferenceSpaces(XrSession, uint32_t, uint32_t*, XrReferenceSpaceType*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateReferenceSpaces was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateReferenceSpace(XrSession, const XrReferenceSpaceCreateInfo*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateReferenceSpace was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetReferenceSpaceBoundsRect(XrSession, XrReferenceSpaceType, XrExtent2Df*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetReferenceSpaceBoundsRect was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateActionSpace(XrSession, const XrActionSpaceCreateInfo*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateActionSpace was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrLocateSpace(XrSpace, XrSpace, XrTime, XrSpaceLocation*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLocateSpace was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpace(XrSpace) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySpace was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateViewConfigurations(XrInstance, XrSystemId, uint32_t, uint32_t*, XrViewConfigurationType*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateViewConfigurations was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetViewConfigurationProperties(XrInstance, XrSystemId, XrViewConfigurationType, XrViewConfigurationProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetViewConfigurationProperties was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateViewConfigurationViews(XrInstance, XrSystemId, XrViewConfigurationType, uint32_t, uint32_t*, XrViewConfigurationView*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateViewConfigurationViews was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSwapchainFormats(XrSession, uint32_t, uint32_t*, int64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateSwapchainFormats was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSwapchain(XrSession, const XrSwapchainCreateInfo*, XrSwapchain*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSwapchain was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroySwapchain(XrSwapchain) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySwapchain was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSwapchainImages(XrSwapchain, uint32_t, uint32_t*, XrSwapchainImageBaseHeader*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateSwapchainImages was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrAcquireSwapchainImage(XrSwapchain, const XrSwapchainImageAcquireInfo*, uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrAcquireSwapchainImage was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrWaitSwapchainImage(XrSwapchain, const XrSwapchainImageWaitInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrWaitSwapchainImage was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrReleaseSwapchainImage(XrSwapchain, const XrSwapchainImageReleaseInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrReleaseSwapchainImage was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrBeginSession(XrSession, const XrSessionBeginInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrBeginSession was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEndSession(XrSession) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEndSession was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrRequestExitSession(XrSession) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrRequestExitSession was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrWaitFrame(XrSession, const XrFrameWaitInfo*, XrFrameState*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrWaitFrame was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrBeginFrame(XrSession, const XrFrameBeginInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrBeginFrame was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEndFrame(XrSession, const XrFrameEndInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEndFrame was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrLocateViews(XrSession, const XrViewLocateInfo*, XrViewState*, uint32_t, uint32_t*, XrView*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLocateViews was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrStringToPath(XrInstance, const char*, XrPath*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrStringToPath was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrPathToString(XrInstance, XrPath, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPathToString was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateActionSet(XrInstance, const XrActionSetCreateInfo*, XrActionSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateActionSet was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyActionSet(XrActionSet) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyActionSet was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateAction(XrActionSet, const XrActionCreateInfo*, XrAction*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateAction was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyAction(XrAction) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyAction was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSuggestInteractionProfileBindings(XrInstance, const XrInteractionProfileSuggestedBinding*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSuggestInteractionProfileBindings was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrAttachSessionActionSets(XrSession, const XrSessionActionSetsAttachInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrAttachSessionActionSets was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetCurrentInteractionProfile(XrSession, XrPath, XrInteractionProfileState*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetCurrentInteractionProfile was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStateBoolean(XrSession, const XrActionStateGetInfo*, XrActionStateBoolean*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetActionStateBoolean was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStateFloat(XrSession, const XrActionStateGetInfo*, XrActionStateFloat*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetActionStateFloat was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStateVector2f(XrSession, const XrActionStateGetInfo*, XrActionStateVector2f*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetActionStateVector2f was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStatePose(XrSession, const XrActionStateGetInfo*, XrActionStatePose*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetActionStatePose was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSyncActions(XrSession, const XrActionsSyncInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSyncActions was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateBoundSourcesForAction(XrSession, const XrBoundSourcesForActionEnumerateInfo*, uint32_t, uint32_t*, XrPath*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateBoundSourcesForAction was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetInputSourceLocalizedName(XrSession, const XrInputSourceLocalizedNameGetInfo*, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetInputSourceLocalizedName was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrApplyHapticFeedback(XrSession, const XrHapticActionInfo*, const XrHapticBaseHeader*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrApplyHapticFeedback was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrStopHapticFeedback(XrSession, const XrHapticActionInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrStopHapticFeedback was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetAndroidApplicationThreadKHR(XrSession, XrAndroidThreadTypeKHR, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetAndroidApplicationThreadKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSwapchainAndroidSurfaceKHR(XrSession, const XrSwapchainCreateInfo*, XrSwapchain*, jobject*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSwapchainAndroidSurfaceKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetOpenGLGraphicsRequirementsKHR(XrInstance, XrSystemId, XrGraphicsRequirementsOpenGLKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetOpenGLGraphicsRequirementsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetOpenGLESGraphicsRequirementsKHR(XrInstance, XrSystemId, XrGraphicsRequirementsOpenGLESKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetOpenGLESGraphicsRequirementsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanInstanceExtensionsKHR(XrInstance, XrSystemId, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanInstanceExtensionsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanDeviceExtensionsKHR(XrInstance, XrSystemId, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanDeviceExtensionsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsDeviceKHR(XrInstance, XrSystemId, VkInstance, VkPhysicalDevice*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanGraphicsDeviceKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsRequirementsKHR(XrInstance, XrSystemId, XrGraphicsRequirementsVulkanKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanGraphicsRequirementsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetD3D11GraphicsRequirementsKHR(XrInstance, XrSystemId, XrGraphicsRequirementsD3D11KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetD3D11GraphicsRequirementsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetD3D12GraphicsRequirementsKHR(XrInstance, XrSystemId, XrGraphicsRequirementsD3D12KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetD3D12GraphicsRequirementsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVisibilityMaskKHR(XrSession, XrViewConfigurationType, uint32_t, XrVisibilityMaskTypeKHR, XrVisibilityMaskKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVisibilityMaskKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrConvertWin32PerformanceCounterToTimeKHR(XrInstance, const LARGE_INTEGER*, XrTime*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrConvertWin32PerformanceCounterToTimeKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrConvertTimeToWin32PerformanceCounterKHR(XrInstance, XrTime, LARGE_INTEGER*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrConvertTimeToWin32PerformanceCounterKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrConvertTimespecTimeToTimeKHR(XrInstance, const struct timespec*, XrTime*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrConvertTimespecTimeToTimeKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrConvertTimeToTimespecTimeKHR(XrInstance, XrTime, struct timespec*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrConvertTimeToTimespecTimeKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateVulkanInstanceKHR(XrInstance, const XrVulkanInstanceCreateInfoKHR*, VkInstance*, VkResult*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateVulkanInstanceKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateVulkanDeviceKHR(XrInstance, const XrVulkanDeviceCreateInfoKHR*, VkDevice*, VkResult*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateVulkanDeviceKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsDevice2KHR(XrInstance, const XrVulkanGraphicsDeviceGetInfoKHR*, VkPhysicalDevice*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanGraphicsDevice2KHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsRequirements2KHR(XrInstance, XrSystemId, XrGraphicsRequirementsVulkanKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanGraphicsRequirements2KHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrPerfSettingsSetPerformanceLevelEXT(XrSession, XrPerfSettingsDomainEXT, XrPerfSettingsLevelEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPerfSettingsSetPerformanceLevelEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrThermalGetTemperatureTrendEXT(XrSession, XrPerfSettingsDomainEXT, XrPerfSettingsNotificationLevelEXT*, float*, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrThermalGetTemperatureTrendEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetDebugUtilsObjectNameEXT(XrInstance, const XrDebugUtilsObjectNameInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetDebugUtilsObjectNameEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateDebugUtilsMessengerEXT(XrInstance, const XrDebugUtilsMessengerCreateInfoEXT*, XrDebugUtilsMessengerEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateDebugUtilsMessengerEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyDebugUtilsMessengerEXT(XrDebugUtilsMessengerEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyDebugUtilsMessengerEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult                                    XRAPI_CALL xrSubmitDebugUtilsMessageEXT(XrInstance, XrDebugUtilsMessageSeverityFlagsEXT, XrDebugUtilsMessageTypeFlagsEXT, const XrDebugUtilsMessengerCallbackDataEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSubmitDebugUtilsMessageEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSessionBeginDebugUtilsLabelRegionEXT(XrSession, const XrDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSessionBeginDebugUtilsLabelRegionEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSessionEndDebugUtilsLabelRegionEXT(XrSession) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSessionEndDebugUtilsLabelRegionEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSessionInsertDebugUtilsLabelEXT(XrSession, const XrDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSessionInsertDebugUtilsLabelEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorMSFT(XrSession, const XrSpatialAnchorCreateInfoMSFT*, XrSpatialAnchorMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorSpaceMSFT(XrSession, const XrSpatialAnchorSpaceCreateInfoMSFT*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorSpaceMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpatialAnchorMSFT(XrSpatialAnchorMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySpatialAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceActiveEXT(XrSession, XrPath, XrPath, XrBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetInputDeviceActiveEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceStateBoolEXT(XrSession, XrPath, XrPath, XrBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetInputDeviceStateBoolEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceStateFloatEXT(XrSession, XrPath, XrPath, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetInputDeviceStateFloatEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceStateVector2fEXT(XrSession, XrPath, XrPath, XrVector2f) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetInputDeviceStateVector2fEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceLocationEXT(XrSession, XrPath, XrPath, XrSpace, XrPosef) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetInputDeviceLocationEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialGraphNodeSpaceMSFT(XrSession, const XrSpatialGraphNodeSpaceCreateInfoMSFT*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialGraphNodeSpaceMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrTryCreateSpatialGraphStaticNodeBindingMSFT(XrSession, const XrSpatialGraphStaticNodeBindingCreateInfoMSFT*, XrSpatialGraphNodeBindingMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTryCreateSpatialGraphStaticNodeBindingMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpatialGraphNodeBindingMSFT(XrSpatialGraphNodeBindingMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySpatialGraphNodeBindingMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpatialGraphNodeBindingPropertiesMSFT(XrSpatialGraphNodeBindingMSFT, const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT*, XrSpatialGraphNodeBindingPropertiesMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpatialGraphNodeBindingPropertiesMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateHandTrackerEXT(XrSession, const XrHandTrackerCreateInfoEXT*, XrHandTrackerEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateHandTrackerEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyHandTrackerEXT(XrHandTrackerEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyHandTrackerEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrLocateHandJointsEXT(XrHandTrackerEXT, const XrHandJointsLocateInfoEXT*, XrHandJointLocationsEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLocateHandJointsEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateHandMeshSpaceMSFT(XrHandTrackerEXT, const XrHandMeshSpaceCreateInfoMSFT*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateHandMeshSpaceMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrUpdateHandMeshMSFT(XrHandTrackerEXT, const XrHandMeshUpdateInfoMSFT*, XrHandMeshMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrUpdateHandMeshMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetControllerModelKeyMSFT(XrSession, XrPath, XrControllerModelKeyStateMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetControllerModelKeyMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrLoadControllerModelMSFT(XrSession, XrControllerModelKeyMSFT, uint32_t, uint32_t*, uint8_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLoadControllerModelMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetControllerModelPropertiesMSFT(XrSession, XrControllerModelKeyMSFT, XrControllerModelPropertiesMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetControllerModelPropertiesMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetControllerModelStateMSFT(XrSession, XrControllerModelKeyMSFT, XrControllerModelStateMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetControllerModelStateMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorFromPerceptionAnchorMSFT(XrSession, IUnknown*, XrSpatialAnchorMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorFromPerceptionAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(XrSession, XrSpatialAnchorMSFT, IUnknown**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTryGetPerceptionAnchorFromSpatialAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateReprojectionModesMSFT(XrInstance, XrSystemId, XrViewConfigurationType, uint32_t, uint32_t*, XrReprojectionModeMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateReprojectionModesMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrUpdateSwapchainFB(XrSwapchain, const XrSwapchainStateBaseHeaderFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrUpdateSwapchainFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSwapchainStateFB(XrSwapchain, XrSwapchainStateBaseHeaderFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSwapchainStateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateBodyTrackerFB(XrSession, const XrBodyTrackerCreateInfoFB*, XrBodyTrackerFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateBodyTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyBodyTrackerFB(XrBodyTrackerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyBodyTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrLocateBodyJointsFB(XrBodyTrackerFB, const XrBodyJointsLocateInfoFB*, XrBodyJointLocationsFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLocateBodyJointsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetBodySkeletonFB(XrBodyTrackerFB, XrBodySkeletonFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetBodySkeletonFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSceneComputeFeaturesMSFT(XrInstance, XrSystemId, uint32_t, uint32_t*, XrSceneComputeFeatureMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateSceneComputeFeaturesMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSceneObserverMSFT(XrSession, const XrSceneObserverCreateInfoMSFT*, XrSceneObserverMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSceneObserverMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroySceneObserverMSFT(XrSceneObserverMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySceneObserverMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSceneMSFT(XrSceneObserverMSFT, const XrSceneCreateInfoMSFT*, XrSceneMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSceneMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroySceneMSFT(XrSceneMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySceneMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrComputeNewSceneMSFT(XrSceneObserverMSFT, const XrNewSceneComputeInfoMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrComputeNewSceneMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneComputeStateMSFT(XrSceneObserverMSFT, XrSceneComputeStateMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSceneComputeStateMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneComponentsMSFT(XrSceneMSFT, const XrSceneComponentsGetInfoMSFT*, XrSceneComponentsMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSceneComponentsMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrLocateSceneComponentsMSFT(XrSceneMSFT, const XrSceneComponentsLocateInfoMSFT*, XrSceneComponentLocationsMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLocateSceneComponentsMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneMeshBuffersMSFT(XrSceneMSFT, const XrSceneMeshBuffersGetInfoMSFT*, XrSceneMeshBuffersMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSceneMeshBuffersMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDeserializeSceneMSFT(XrSceneObserverMSFT, const XrSceneDeserializeInfoMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDeserializeSceneMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSerializedSceneFragmentDataMSFT(XrSceneMSFT, const XrSerializedSceneFragmentDataGetInfoMSFT*, uint32_t, uint32_t*, uint8_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSerializedSceneFragmentDataMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateDisplayRefreshRatesFB(XrSession, uint32_t, uint32_t*, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateDisplayRefreshRatesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetDisplayRefreshRateFB(XrSession, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetDisplayRefreshRateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrRequestDisplayRefreshRateFB(XrSession, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrRequestDisplayRefreshRateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateViveTrackerPathsHTCX(XrInstance, uint32_t, uint32_t*, XrViveTrackerPathsHTCX*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateViveTrackerPathsHTCX was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateFacialTrackerHTC(XrSession, const XrFacialTrackerCreateInfoHTC*, XrFacialTrackerHTC*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateFacialTrackerHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFacialTrackerHTC(XrFacialTrackerHTC) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyFacialTrackerHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetFacialExpressionsHTC(XrFacialTrackerHTC, XrFacialExpressionsHTC*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetFacialExpressionsHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateColorSpacesFB(XrSession, uint32_t, uint32_t*, XrColorSpaceFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateColorSpacesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetColorSpaceFB(XrSession, const XrColorSpaceFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetColorSpaceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetHandMeshFB(XrHandTrackerEXT, XrHandTrackingMeshFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetHandMeshFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorFB(XrSession, const XrSpatialAnchorCreateInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceUuidFB(XrSpace, XrUuidEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceUuidFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSpaceSupportedComponentsFB(XrSpace, uint32_t, uint32_t*, XrSpaceComponentTypeFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateSpaceSupportedComponentsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetSpaceComponentStatusFB(XrSpace, const XrSpaceComponentStatusSetInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetSpaceComponentStatusFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceComponentStatusFB(XrSpace, XrSpaceComponentTypeFB, XrSpaceComponentStatusFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceComponentStatusFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateFoveationProfileFB(XrSession, const XrFoveationProfileCreateInfoFB*, XrFoveationProfileFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateFoveationProfileFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFoveationProfileFB(XrFoveationProfileFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyFoveationProfileFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrQuerySystemTrackedKeyboardFB(XrSession, const XrKeyboardTrackingQueryFB*, XrKeyboardTrackingDescriptionFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrQuerySystemTrackedKeyboardFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateKeyboardSpaceFB(XrSession, const XrKeyboardSpaceCreateInfoFB*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateKeyboardSpaceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateTriangleMeshFB(XrSession, const XrTriangleMeshCreateInfoFB*, XrTriangleMeshFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateTriangleMeshFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyTriangleMeshFB(XrTriangleMeshFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyTriangleMeshFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshGetVertexBufferFB(XrTriangleMeshFB, XrVector3f**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshGetVertexBufferFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshGetIndexBufferFB(XrTriangleMeshFB, uint32_t**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshGetIndexBufferFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshBeginUpdateFB(XrTriangleMeshFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshBeginUpdateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshEndUpdateFB(XrTriangleMeshFB, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshEndUpdateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshBeginVertexBufferUpdateFB(XrTriangleMeshFB, uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshBeginVertexBufferUpdateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshEndVertexBufferUpdateFB(XrTriangleMeshFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshEndVertexBufferUpdateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughFB(XrSession, const XrPassthroughCreateInfoFB*, XrPassthroughFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreatePassthroughFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughFB(XrPassthroughFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyPassthroughFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughStartFB(XrPassthroughFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughStartFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughPauseFB(XrPassthroughFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughPauseFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughLayerFB(XrSession, const XrPassthroughLayerCreateInfoFB*, XrPassthroughLayerFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreatePassthroughLayerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughLayerFB(XrPassthroughLayerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyPassthroughLayerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerPauseFB(XrPassthroughLayerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughLayerPauseFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerResumeFB(XrPassthroughLayerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughLayerResumeFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerSetStyleFB(XrPassthroughLayerFB, const XrPassthroughStyleFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughLayerSetStyleFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateGeometryInstanceFB(XrSession, const XrGeometryInstanceCreateInfoFB*, XrGeometryInstanceFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateGeometryInstanceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyGeometryInstanceFB(XrGeometryInstanceFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyGeometryInstanceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGeometryInstanceSetTransformFB(XrGeometryInstanceFB, const XrGeometryInstanceTransformFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGeometryInstanceSetTransformFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateRenderModelPathsFB(XrSession, uint32_t, uint32_t*, XrRenderModelPathInfoFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateRenderModelPathsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetRenderModelPropertiesFB(XrSession, XrPath, XrRenderModelPropertiesFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetRenderModelPropertiesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrLoadRenderModelFB(XrSession, const XrRenderModelLoadInfoFB*, XrRenderModelBufferFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLoadRenderModelFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetEnvironmentDepthEstimationVARJO(XrSession, XrBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetEnvironmentDepthEstimationVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult  XRAPI_CALL xrSetMarkerTrackingVARJO(XrSession, XrBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetMarkerTrackingVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetMarkerTrackingTimeoutVARJO(XrSession, uint64_t, XrDuration) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetMarkerTrackingTimeoutVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetMarkerTrackingPredictionVARJO(XrSession, uint64_t, XrBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetMarkerTrackingPredictionVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerSizeVARJO(XrSession, uint64_t, XrExtent2Df*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerSizeVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateMarkerSpaceVARJO(XrSession, const XrMarkerSpaceCreateInfoVARJO*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateMarkerSpaceVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult  XRAPI_CALL xrSetViewOffsetVARJO(XrSession, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetViewOffsetVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpaceFromCoordinateFrameUIDML(XrSession, const XrCoordinateSpaceCreateInfoML *, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpaceFromCoordinateFrameUIDML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateMarkerDetectorML(XrSession, const XrMarkerDetectorCreateInfoML*, XrMarkerDetectorML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateMarkerDetectorML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyMarkerDetectorML(XrMarkerDetectorML) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyMarkerDetectorML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSnapshotMarkerDetectorML(XrMarkerDetectorML, XrMarkerDetectorSnapshotInfoML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSnapshotMarkerDetectorML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerDetectorStateML(XrMarkerDetectorML, XrMarkerDetectorStateML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerDetectorStateML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkersML(XrMarkerDetectorML, uint32_t, uint32_t*, XrMarkerML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkersML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerReprojectionErrorML(XrMarkerDetectorML, XrMarkerML, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerReprojectionErrorML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerLengthML(XrMarkerDetectorML, XrMarkerML, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerLengthML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerNumberML(XrMarkerDetectorML, XrMarkerML, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerNumberML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerStringML(XrMarkerDetectorML, XrMarkerML, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerStringML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateMarkerSpaceML(XrSession, const XrMarkerSpaceCreateInfoML*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateMarkerSpaceML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnableLocalizationEventsML(XrSession, const XrLocalizationEnableEventsInfoML *) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnableLocalizationEventsML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrQueryLocalizationMapsML(XrSession, const XrLocalizationMapQueryInfoBaseHeaderML*, uint32_t, uint32_t *, XrLocalizationMapML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrQueryLocalizationMapsML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrRequestMapLocalizationML(XrSession, const XrMapLocalizationRequestInfoML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrRequestMapLocalizationML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrImportLocalizationMapML(XrSession, const XrLocalizationMapImportInfoML*, XrUuidEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrImportLocalizationMapML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateExportedLocalizationMapML(XrSession, const XrUuidEXT*, XrExportedLocalizationMapML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateExportedLocalizationMapML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyExportedLocalizationMapML(XrExportedLocalizationMapML) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyExportedLocalizationMapML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetExportedLocalizationMapDataML(XrExportedLocalizationMapML, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetExportedLocalizationMapDataML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorStoreConnectionMSFT(XrSession, XrSpatialAnchorStoreConnectionMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorStoreConnectionMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpatialAnchorStoreConnectionMSFT(XrSpatialAnchorStoreConnectionMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySpatialAnchorStoreConnectionMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrPersistSpatialAnchorMSFT(XrSpatialAnchorStoreConnectionMSFT, const XrSpatialAnchorPersistenceInfoMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPersistSpatialAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumeratePersistedSpatialAnchorNamesMSFT(XrSpatialAnchorStoreConnectionMSFT, uint32_t, uint32_t*, XrSpatialAnchorPersistenceNameMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumeratePersistedSpatialAnchorNamesMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorFromPersistedNameMSFT(XrSession, const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT*, XrSpatialAnchorMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorFromPersistedNameMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrUnpersistSpatialAnchorMSFT(XrSpatialAnchorStoreConnectionMSFT, const XrSpatialAnchorPersistenceNameMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrUnpersistSpatialAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrClearSpatialAnchorStoreMSFT(XrSpatialAnchorStoreConnectionMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrClearSpatialAnchorStoreMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneMarkerRawDataMSFT(XrSceneMSFT, const XrUuidMSFT*, uint32_t, uint32_t*, uint8_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSceneMarkerRawDataMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneMarkerDecodedStringMSFT(XrSceneMSFT, const XrUuidMSFT*, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSceneMarkerDecodedStringMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrQuerySpacesFB(XrSession, const XrSpaceQueryInfoBaseHeaderFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrQuerySpacesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrRetrieveSpaceQueryResultsFB(XrSession, XrAsyncRequestIdFB, XrSpaceQueryResultsFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrRetrieveSpaceQueryResultsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSaveSpaceFB(XrSession, const XrSpaceSaveInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSaveSpaceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEraseSpaceFB(XrSession, const XrSpaceEraseInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEraseSpaceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetAudioOutputDeviceGuidOculus(XrInstance, wchar_t[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetAudioOutputDeviceGuidOculus was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetAudioInputDeviceGuidOculus(XrInstance, wchar_t[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetAudioInputDeviceGuidOculus was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrShareSpacesFB(XrSession, const XrSpaceShareInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrShareSpacesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceBoundingBox2DFB(XrSession, XrSpace, XrRect2Df*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceBoundingBox2DFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceBoundingBox3DFB(XrSession, XrSpace, XrRect3DfFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceBoundingBox3DFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceSemanticLabelsFB(XrSession, XrSpace, XrSemanticLabelsFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceSemanticLabelsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceBoundary2DFB(XrSession, XrSpace, XrBoundary2DFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceBoundary2DFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceRoomLayoutFB(XrSession, XrSpace, XrRoomLayoutFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceRoomLayoutFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetDigitalLensControlALMALENCE(XrSession, const XrDigitalLensControlALMALENCE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetDigitalLensControlALMALENCE was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrRequestSceneCaptureFB(XrSession, const XrSceneCaptureRequestInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrRequestSceneCaptureFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceContainerFB(XrSession, XrSpace, XrSpaceContainerFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceContainerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetFoveationEyeTrackedStateMETA(XrSession, XrFoveationEyeTrackedStateMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetFoveationEyeTrackedStateMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateFaceTrackerFB(XrSession, const XrFaceTrackerCreateInfoFB*, XrFaceTrackerFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateFaceTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFaceTrackerFB(XrFaceTrackerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyFaceTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetFaceExpressionWeightsFB(XrFaceTrackerFB, const XrFaceExpressionInfoFB*, XrFaceExpressionWeightsFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetFaceExpressionWeightsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateEyeTrackerFB(XrSession, const XrEyeTrackerCreateInfoFB*, XrEyeTrackerFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateEyeTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyEyeTrackerFB(XrEyeTrackerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyEyeTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetEyeGazesFB(XrEyeTrackerFB, const XrEyeGazesInfoFB*, XrEyeGazesFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetEyeGazesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerSetKeyboardHandsIntensityFB(XrPassthroughLayerFB, const XrPassthroughKeyboardHandsIntensityFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughLayerSetKeyboardHandsIntensityFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetDeviceSampleRateFB(XrSession, const XrHapticActionInfo*, XrDevicePcmSampleRateGetInfoFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetDeviceSampleRateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetPassthroughPreferencesMETA(XrSession, XrPassthroughPreferencesMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetPassthroughPreferencesMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateVirtualKeyboardMETA(XrSession, const XrVirtualKeyboardCreateInfoMETA*, XrVirtualKeyboardMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateVirtualKeyboardMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyVirtualKeyboardMETA(XrVirtualKeyboardMETA) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyVirtualKeyboardMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateVirtualKeyboardSpaceMETA(XrSession, XrVirtualKeyboardMETA, const XrVirtualKeyboardSpaceCreateInfoMETA*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateVirtualKeyboardSpaceMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSuggestVirtualKeyboardLocationMETA(XrVirtualKeyboardMETA, const XrVirtualKeyboardLocationInfoMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSuggestVirtualKeyboardLocationMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardScaleMETA(XrVirtualKeyboardMETA, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVirtualKeyboardScaleMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetVirtualKeyboardModelVisibilityMETA(XrVirtualKeyboardMETA, const XrVirtualKeyboardModelVisibilitySetInfoMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetVirtualKeyboardModelVisibilityMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardModelAnimationStatesMETA(XrVirtualKeyboardMETA, XrVirtualKeyboardModelAnimationStatesMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVirtualKeyboardModelAnimationStatesMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardDirtyTexturesMETA(XrVirtualKeyboardMETA, uint32_t, uint32_t*, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVirtualKeyboardDirtyTexturesMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardTextureDataMETA(XrVirtualKeyboardMETA, uint64_t, XrVirtualKeyboardTextureDataMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVirtualKeyboardTextureDataMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSendVirtualKeyboardInputMETA(XrVirtualKeyboardMETA, const XrVirtualKeyboardInputInfoMETA*, XrPosef*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSendVirtualKeyboardInputMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrChangeVirtualKeyboardTextContextMETA(XrVirtualKeyboardMETA, const XrVirtualKeyboardTextContextChangeInfoMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrChangeVirtualKeyboardTextContextMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateExternalCamerasOCULUS(XrSession, uint32_t, uint32_t*, XrExternalCameraOCULUS*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateExternalCamerasOCULUS was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnumeratePerformanceMetricsCounterPathsMETA(XrInstance, uint32_t, uint32_t*, XrPath*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumeratePerformanceMetricsCounterPathsMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetPerformanceMetricsStateMETA(XrSession, const XrPerformanceMetricsStateMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetPerformanceMetricsStateMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetPerformanceMetricsStateMETA(XrSession, XrPerformanceMetricsStateMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetPerformanceMetricsStateMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrQueryPerformanceMetricsCounterMETA(XrSession, XrPath, XrPerformanceMetricsCounterMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrQueryPerformanceMetricsCounterMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSaveSpaceListFB(XrSession, const XrSpaceListSaveInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSaveSpaceListFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpaceUserFB(XrSession, const XrSpaceUserCreateInfoFB*, XrSpaceUserFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpaceUserFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceUserIdFB(XrSpaceUserFB, XrSpaceUserIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceUserIdFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpaceUserFB(XrSpaceUserFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySpaceUserFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetRecommendedLayerResolutionMETA(XrSession, const XrRecommendedLayerResolutionGetInfoMETA*, XrRecommendedLayerResolutionMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetRecommendedLayerResolutionMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughColorLutMETA(XrPassthroughFB, const XrPassthroughColorLutCreateInfoMETA*, XrPassthroughColorLutMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreatePassthroughColorLutMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughColorLutMETA(XrPassthroughColorLutMETA) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyPassthroughColorLutMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrUpdatePassthroughColorLutMETA(XrPassthroughColorLutMETA, const XrPassthroughColorLutUpdateInfoMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrUpdatePassthroughColorLutMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceTriangleMeshMETA(XrSpace, const XrSpaceTriangleMeshGetInfoMETA*, XrSpaceTriangleMeshMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceTriangleMeshMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateFaceTracker2FB(XrSession, const XrFaceTrackerCreateInfo2FB*, XrFaceTracker2FB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateFaceTracker2FB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFaceTracker2FB(XrFaceTracker2FB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyFaceTracker2FB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetFaceExpressionWeights2FB(XrFaceTracker2FB, const XrFaceExpressionInfo2FB*, XrFaceExpressionWeights2FB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetFaceExpressionWeights2FB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrSetTrackingOptimizationSettingsHintQCOM(XrSession, XrTrackingOptimizationSettingsDomainQCOM, XrTrackingOptimizationSettingsHintQCOM) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetTrackingOptimizationSettingsHintQCOM was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughHTC(XrSession, const XrPassthroughCreateInfoHTC*, XrPassthroughHTC*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreatePassthroughHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughHTC(XrPassthroughHTC) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyPassthroughHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrApplyFoveationHTC(XrSession, const XrFoveationApplyInfoHTC*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrApplyFoveationHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorHTC(XrSession, const XrSpatialAnchorCreateInfoHTC*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetSpatialAnchorNameHTC(XrSpace, XrSpatialAnchorNameHTC*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpatialAnchorNameHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrApplyForceFeedbackCurlMNDX(XrHandTrackerEXT, const XrForceFeedbackCurlApplyLocationsMNDX*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrApplyForceFeedbackCurlMNDX was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrCreatePlaneDetectorEXT(XrSession, const XrPlaneDetectorCreateInfoEXT*, XrPlaneDetectorEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreatePlaneDetectorEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPlaneDetectorEXT(XrPlaneDetectorEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyPlaneDetectorEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrBeginPlaneDetectionEXT(XrPlaneDetectorEXT, const XrPlaneDetectorBeginInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrBeginPlaneDetectionEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetPlaneDetectionStateEXT(XrPlaneDetectorEXT, XrPlaneDetectionStateEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetPlaneDetectionStateEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetPlaneDetectionsEXT(XrPlaneDetectorEXT, const XrPlaneDetectorGetInfoEXT*, XrPlaneDetectorLocationsEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetPlaneDetectionsEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrGetPlanePolygonBufferEXT(XrPlaneDetectorEXT, uint64_t, uint32_t, XrPlaneDetectorPolygonBufferEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetPlanePolygonBufferEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL xrEnableUserCalibrationEventsML(XrInstance, const XrUserCalibrationEnableEventsInfoML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnableUserCalibrationEventsML was called, resulting in no-op behavior."); return XR_SUCCESS; }
// clang-format on
GFXRECON_END_NAMESPACE(noop)

struct OpenXrLayerTable
{
    PFN_xrCreateApiLayerInstance CreateApiLayerInstance{ nullptr };
};

struct OpenXrInstanceTable
{
    PFN_xrGetInstanceProcAddr GetInstanceProcAddr{ noop::xrGetInstanceProcAddr };
    PFN_xrDestroyInstance DestroyInstance{ noop::xrDestroyInstance };
    PFN_xrGetInstanceProperties GetInstanceProperties{ noop::xrGetInstanceProperties };
    PFN_xrPollEvent PollEvent{ noop::xrPollEvent };
    PFN_xrResultToString ResultToString{ noop::xrResultToString };
    PFN_xrStructureTypeToString StructureTypeToString{ noop::xrStructureTypeToString };
    PFN_xrGetSystem GetSystem{ noop::xrGetSystem };
    PFN_xrGetSystemProperties GetSystemProperties{ noop::xrGetSystemProperties };
    PFN_xrEnumerateEnvironmentBlendModes EnumerateEnvironmentBlendModes{ noop::xrEnumerateEnvironmentBlendModes };
    PFN_xrCreateSession CreateSession{ noop::xrCreateSession };
    PFN_xrDestroySession DestroySession{ noop::xrDestroySession };
    PFN_xrEnumerateReferenceSpaces EnumerateReferenceSpaces{ noop::xrEnumerateReferenceSpaces };
    PFN_xrCreateReferenceSpace CreateReferenceSpace{ noop::xrCreateReferenceSpace };
    PFN_xrGetReferenceSpaceBoundsRect GetReferenceSpaceBoundsRect{ noop::xrGetReferenceSpaceBoundsRect };
    PFN_xrCreateActionSpace CreateActionSpace{ noop::xrCreateActionSpace };
    PFN_xrLocateSpace LocateSpace{ noop::xrLocateSpace };
    PFN_xrDestroySpace DestroySpace{ noop::xrDestroySpace };
    PFN_xrEnumerateViewConfigurations EnumerateViewConfigurations{ noop::xrEnumerateViewConfigurations };
    PFN_xrGetViewConfigurationProperties GetViewConfigurationProperties{ noop::xrGetViewConfigurationProperties };
    PFN_xrEnumerateViewConfigurationViews EnumerateViewConfigurationViews{ noop::xrEnumerateViewConfigurationViews };
    PFN_xrEnumerateSwapchainFormats EnumerateSwapchainFormats{ noop::xrEnumerateSwapchainFormats };
    PFN_xrCreateSwapchain CreateSwapchain{ noop::xrCreateSwapchain };
    PFN_xrDestroySwapchain DestroySwapchain{ noop::xrDestroySwapchain };
    PFN_xrEnumerateSwapchainImages EnumerateSwapchainImages{ noop::xrEnumerateSwapchainImages };
    PFN_xrAcquireSwapchainImage AcquireSwapchainImage{ noop::xrAcquireSwapchainImage };
    PFN_xrWaitSwapchainImage WaitSwapchainImage{ noop::xrWaitSwapchainImage };
    PFN_xrReleaseSwapchainImage ReleaseSwapchainImage{ noop::xrReleaseSwapchainImage };
    PFN_xrBeginSession BeginSession{ noop::xrBeginSession };
    PFN_xrEndSession EndSession{ noop::xrEndSession };
    PFN_xrRequestExitSession RequestExitSession{ noop::xrRequestExitSession };
    PFN_xrWaitFrame WaitFrame{ noop::xrWaitFrame };
    PFN_xrBeginFrame BeginFrame{ noop::xrBeginFrame };
    PFN_xrEndFrame EndFrame{ noop::xrEndFrame };
    PFN_xrLocateViews LocateViews{ noop::xrLocateViews };
    PFN_xrStringToPath StringToPath{ noop::xrStringToPath };
    PFN_xrPathToString PathToString{ noop::xrPathToString };
    PFN_xrCreateActionSet CreateActionSet{ noop::xrCreateActionSet };
    PFN_xrDestroyActionSet DestroyActionSet{ noop::xrDestroyActionSet };
    PFN_xrCreateAction CreateAction{ noop::xrCreateAction };
    PFN_xrDestroyAction DestroyAction{ noop::xrDestroyAction };
    PFN_xrSuggestInteractionProfileBindings SuggestInteractionProfileBindings{ noop::xrSuggestInteractionProfileBindings };
    PFN_xrAttachSessionActionSets AttachSessionActionSets{ noop::xrAttachSessionActionSets };
    PFN_xrGetCurrentInteractionProfile GetCurrentInteractionProfile{ noop::xrGetCurrentInteractionProfile };
    PFN_xrGetActionStateBoolean GetActionStateBoolean{ noop::xrGetActionStateBoolean };
    PFN_xrGetActionStateFloat GetActionStateFloat{ noop::xrGetActionStateFloat };
    PFN_xrGetActionStateVector2f GetActionStateVector2f{ noop::xrGetActionStateVector2f };
    PFN_xrGetActionStatePose GetActionStatePose{ noop::xrGetActionStatePose };
    PFN_xrSyncActions SyncActions{ noop::xrSyncActions };
    PFN_xrEnumerateBoundSourcesForAction EnumerateBoundSourcesForAction{ noop::xrEnumerateBoundSourcesForAction };
    PFN_xrGetInputSourceLocalizedName GetInputSourceLocalizedName{ noop::xrGetInputSourceLocalizedName };
    PFN_xrApplyHapticFeedback ApplyHapticFeedback{ noop::xrApplyHapticFeedback };
    PFN_xrStopHapticFeedback StopHapticFeedback{ noop::xrStopHapticFeedback };
    PFN_xrSetAndroidApplicationThreadKHR SetAndroidApplicationThreadKHR{ noop::xrSetAndroidApplicationThreadKHR };
    PFN_xrCreateSwapchainAndroidSurfaceKHR CreateSwapchainAndroidSurfaceKHR{ noop::xrCreateSwapchainAndroidSurfaceKHR };
    PFN_xrGetOpenGLGraphicsRequirementsKHR GetOpenGLGraphicsRequirementsKHR{ noop::xrGetOpenGLGraphicsRequirementsKHR };
    PFN_xrGetOpenGLESGraphicsRequirementsKHR GetOpenGLESGraphicsRequirementsKHR{ noop::xrGetOpenGLESGraphicsRequirementsKHR };
    PFN_xrGetVulkanInstanceExtensionsKHR GetVulkanInstanceExtensionsKHR{ noop::xrGetVulkanInstanceExtensionsKHR };
    PFN_xrGetVulkanDeviceExtensionsKHR GetVulkanDeviceExtensionsKHR{ noop::xrGetVulkanDeviceExtensionsKHR };
    PFN_xrGetVulkanGraphicsDeviceKHR GetVulkanGraphicsDeviceKHR{ noop::xrGetVulkanGraphicsDeviceKHR };
    PFN_xrGetVulkanGraphicsRequirementsKHR GetVulkanGraphicsRequirementsKHR{ noop::xrGetVulkanGraphicsRequirementsKHR };
    PFN_xrGetD3D11GraphicsRequirementsKHR GetD3D11GraphicsRequirementsKHR{ noop::xrGetD3D11GraphicsRequirementsKHR };
    PFN_xrGetD3D12GraphicsRequirementsKHR GetD3D12GraphicsRequirementsKHR{ noop::xrGetD3D12GraphicsRequirementsKHR };
    PFN_xrGetVisibilityMaskKHR GetVisibilityMaskKHR{ noop::xrGetVisibilityMaskKHR };
    PFN_xrConvertWin32PerformanceCounterToTimeKHR ConvertWin32PerformanceCounterToTimeKHR{ noop::xrConvertWin32PerformanceCounterToTimeKHR };
    PFN_xrConvertTimeToWin32PerformanceCounterKHR ConvertTimeToWin32PerformanceCounterKHR{ noop::xrConvertTimeToWin32PerformanceCounterKHR };
    PFN_xrConvertTimespecTimeToTimeKHR ConvertTimespecTimeToTimeKHR{ noop::xrConvertTimespecTimeToTimeKHR };
    PFN_xrConvertTimeToTimespecTimeKHR ConvertTimeToTimespecTimeKHR{ noop::xrConvertTimeToTimespecTimeKHR };
    PFN_xrCreateVulkanInstanceKHR CreateVulkanInstanceKHR{ noop::xrCreateVulkanInstanceKHR };
    PFN_xrCreateVulkanDeviceKHR CreateVulkanDeviceKHR{ noop::xrCreateVulkanDeviceKHR };
    PFN_xrGetVulkanGraphicsDevice2KHR GetVulkanGraphicsDevice2KHR{ noop::xrGetVulkanGraphicsDevice2KHR };
    PFN_xrGetVulkanGraphicsRequirements2KHR GetVulkanGraphicsRequirements2KHR{ noop::xrGetVulkanGraphicsRequirements2KHR };
    PFN_xrPerfSettingsSetPerformanceLevelEXT PerfSettingsSetPerformanceLevelEXT{ noop::xrPerfSettingsSetPerformanceLevelEXT };
    PFN_xrThermalGetTemperatureTrendEXT ThermalGetTemperatureTrendEXT{ noop::xrThermalGetTemperatureTrendEXT };
    PFN_xrSetDebugUtilsObjectNameEXT SetDebugUtilsObjectNameEXT{ noop::xrSetDebugUtilsObjectNameEXT };
    PFN_xrCreateDebugUtilsMessengerEXT CreateDebugUtilsMessengerEXT{ noop::xrCreateDebugUtilsMessengerEXT };
    PFN_xrDestroyDebugUtilsMessengerEXT DestroyDebugUtilsMessengerEXT{ noop::xrDestroyDebugUtilsMessengerEXT };
    PFN_xrSubmitDebugUtilsMessageEXT SubmitDebugUtilsMessageEXT{ noop::xrSubmitDebugUtilsMessageEXT };
    PFN_xrSessionBeginDebugUtilsLabelRegionEXT SessionBeginDebugUtilsLabelRegionEXT{ noop::xrSessionBeginDebugUtilsLabelRegionEXT };
    PFN_xrSessionEndDebugUtilsLabelRegionEXT SessionEndDebugUtilsLabelRegionEXT{ noop::xrSessionEndDebugUtilsLabelRegionEXT };
    PFN_xrSessionInsertDebugUtilsLabelEXT SessionInsertDebugUtilsLabelEXT{ noop::xrSessionInsertDebugUtilsLabelEXT };
    PFN_xrCreateSpatialAnchorMSFT CreateSpatialAnchorMSFT{ noop::xrCreateSpatialAnchorMSFT };
    PFN_xrCreateSpatialAnchorSpaceMSFT CreateSpatialAnchorSpaceMSFT{ noop::xrCreateSpatialAnchorSpaceMSFT };
    PFN_xrDestroySpatialAnchorMSFT DestroySpatialAnchorMSFT{ noop::xrDestroySpatialAnchorMSFT };
    PFN_xrSetInputDeviceActiveEXT SetInputDeviceActiveEXT{ noop::xrSetInputDeviceActiveEXT };
    PFN_xrSetInputDeviceStateBoolEXT SetInputDeviceStateBoolEXT{ noop::xrSetInputDeviceStateBoolEXT };
    PFN_xrSetInputDeviceStateFloatEXT SetInputDeviceStateFloatEXT{ noop::xrSetInputDeviceStateFloatEXT };
    PFN_xrSetInputDeviceStateVector2fEXT SetInputDeviceStateVector2fEXT{ noop::xrSetInputDeviceStateVector2fEXT };
    PFN_xrSetInputDeviceLocationEXT SetInputDeviceLocationEXT{ noop::xrSetInputDeviceLocationEXT };
    PFN_xrCreateSpatialGraphNodeSpaceMSFT CreateSpatialGraphNodeSpaceMSFT{ noop::xrCreateSpatialGraphNodeSpaceMSFT };
    PFN_xrTryCreateSpatialGraphStaticNodeBindingMSFT TryCreateSpatialGraphStaticNodeBindingMSFT{ noop::xrTryCreateSpatialGraphStaticNodeBindingMSFT };
    PFN_xrDestroySpatialGraphNodeBindingMSFT DestroySpatialGraphNodeBindingMSFT{ noop::xrDestroySpatialGraphNodeBindingMSFT };
    PFN_xrGetSpatialGraphNodeBindingPropertiesMSFT GetSpatialGraphNodeBindingPropertiesMSFT{ noop::xrGetSpatialGraphNodeBindingPropertiesMSFT };
    PFN_xrCreateHandTrackerEXT CreateHandTrackerEXT{ noop::xrCreateHandTrackerEXT };
    PFN_xrDestroyHandTrackerEXT DestroyHandTrackerEXT{ noop::xrDestroyHandTrackerEXT };
    PFN_xrLocateHandJointsEXT LocateHandJointsEXT{ noop::xrLocateHandJointsEXT };
    PFN_xrCreateHandMeshSpaceMSFT CreateHandMeshSpaceMSFT{ noop::xrCreateHandMeshSpaceMSFT };
    PFN_xrUpdateHandMeshMSFT UpdateHandMeshMSFT{ noop::xrUpdateHandMeshMSFT };
    PFN_xrGetControllerModelKeyMSFT GetControllerModelKeyMSFT{ noop::xrGetControllerModelKeyMSFT };
    PFN_xrLoadControllerModelMSFT LoadControllerModelMSFT{ noop::xrLoadControllerModelMSFT };
    PFN_xrGetControllerModelPropertiesMSFT GetControllerModelPropertiesMSFT{ noop::xrGetControllerModelPropertiesMSFT };
    PFN_xrGetControllerModelStateMSFT GetControllerModelStateMSFT{ noop::xrGetControllerModelStateMSFT };
    PFN_xrCreateSpatialAnchorFromPerceptionAnchorMSFT CreateSpatialAnchorFromPerceptionAnchorMSFT{ noop::xrCreateSpatialAnchorFromPerceptionAnchorMSFT };
    PFN_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT TryGetPerceptionAnchorFromSpatialAnchorMSFT{ noop::xrTryGetPerceptionAnchorFromSpatialAnchorMSFT };
    PFN_xrEnumerateReprojectionModesMSFT EnumerateReprojectionModesMSFT{ noop::xrEnumerateReprojectionModesMSFT };
    PFN_xrUpdateSwapchainFB UpdateSwapchainFB{ noop::xrUpdateSwapchainFB };
    PFN_xrGetSwapchainStateFB GetSwapchainStateFB{ noop::xrGetSwapchainStateFB };
    PFN_xrCreateBodyTrackerFB CreateBodyTrackerFB{ noop::xrCreateBodyTrackerFB };
    PFN_xrDestroyBodyTrackerFB DestroyBodyTrackerFB{ noop::xrDestroyBodyTrackerFB };
    PFN_xrLocateBodyJointsFB LocateBodyJointsFB{ noop::xrLocateBodyJointsFB };
    PFN_xrGetBodySkeletonFB GetBodySkeletonFB{ noop::xrGetBodySkeletonFB };
    PFN_xrEnumerateSceneComputeFeaturesMSFT EnumerateSceneComputeFeaturesMSFT{ noop::xrEnumerateSceneComputeFeaturesMSFT };
    PFN_xrCreateSceneObserverMSFT CreateSceneObserverMSFT{ noop::xrCreateSceneObserverMSFT };
    PFN_xrDestroySceneObserverMSFT DestroySceneObserverMSFT{ noop::xrDestroySceneObserverMSFT };
    PFN_xrCreateSceneMSFT CreateSceneMSFT{ noop::xrCreateSceneMSFT };
    PFN_xrDestroySceneMSFT DestroySceneMSFT{ noop::xrDestroySceneMSFT };
    PFN_xrComputeNewSceneMSFT ComputeNewSceneMSFT{ noop::xrComputeNewSceneMSFT };
    PFN_xrGetSceneComputeStateMSFT GetSceneComputeStateMSFT{ noop::xrGetSceneComputeStateMSFT };
    PFN_xrGetSceneComponentsMSFT GetSceneComponentsMSFT{ noop::xrGetSceneComponentsMSFT };
    PFN_xrLocateSceneComponentsMSFT LocateSceneComponentsMSFT{ noop::xrLocateSceneComponentsMSFT };
    PFN_xrGetSceneMeshBuffersMSFT GetSceneMeshBuffersMSFT{ noop::xrGetSceneMeshBuffersMSFT };
    PFN_xrDeserializeSceneMSFT DeserializeSceneMSFT{ noop::xrDeserializeSceneMSFT };
    PFN_xrGetSerializedSceneFragmentDataMSFT GetSerializedSceneFragmentDataMSFT{ noop::xrGetSerializedSceneFragmentDataMSFT };
    PFN_xrEnumerateDisplayRefreshRatesFB EnumerateDisplayRefreshRatesFB{ noop::xrEnumerateDisplayRefreshRatesFB };
    PFN_xrGetDisplayRefreshRateFB GetDisplayRefreshRateFB{ noop::xrGetDisplayRefreshRateFB };
    PFN_xrRequestDisplayRefreshRateFB RequestDisplayRefreshRateFB{ noop::xrRequestDisplayRefreshRateFB };
    PFN_xrEnumerateViveTrackerPathsHTCX EnumerateViveTrackerPathsHTCX{ noop::xrEnumerateViveTrackerPathsHTCX };
    PFN_xrCreateFacialTrackerHTC CreateFacialTrackerHTC{ noop::xrCreateFacialTrackerHTC };
    PFN_xrDestroyFacialTrackerHTC DestroyFacialTrackerHTC{ noop::xrDestroyFacialTrackerHTC };
    PFN_xrGetFacialExpressionsHTC GetFacialExpressionsHTC{ noop::xrGetFacialExpressionsHTC };
    PFN_xrEnumerateColorSpacesFB EnumerateColorSpacesFB{ noop::xrEnumerateColorSpacesFB };
    PFN_xrSetColorSpaceFB SetColorSpaceFB{ noop::xrSetColorSpaceFB };
    PFN_xrGetHandMeshFB GetHandMeshFB{ noop::xrGetHandMeshFB };
    PFN_xrCreateSpatialAnchorFB CreateSpatialAnchorFB{ noop::xrCreateSpatialAnchorFB };
    PFN_xrGetSpaceUuidFB GetSpaceUuidFB{ noop::xrGetSpaceUuidFB };
    PFN_xrEnumerateSpaceSupportedComponentsFB EnumerateSpaceSupportedComponentsFB{ noop::xrEnumerateSpaceSupportedComponentsFB };
    PFN_xrSetSpaceComponentStatusFB SetSpaceComponentStatusFB{ noop::xrSetSpaceComponentStatusFB };
    PFN_xrGetSpaceComponentStatusFB GetSpaceComponentStatusFB{ noop::xrGetSpaceComponentStatusFB };
    PFN_xrCreateFoveationProfileFB CreateFoveationProfileFB{ noop::xrCreateFoveationProfileFB };
    PFN_xrDestroyFoveationProfileFB DestroyFoveationProfileFB{ noop::xrDestroyFoveationProfileFB };
    PFN_xrQuerySystemTrackedKeyboardFB QuerySystemTrackedKeyboardFB{ noop::xrQuerySystemTrackedKeyboardFB };
    PFN_xrCreateKeyboardSpaceFB CreateKeyboardSpaceFB{ noop::xrCreateKeyboardSpaceFB };
    PFN_xrCreateTriangleMeshFB CreateTriangleMeshFB{ noop::xrCreateTriangleMeshFB };
    PFN_xrDestroyTriangleMeshFB DestroyTriangleMeshFB{ noop::xrDestroyTriangleMeshFB };
    PFN_xrTriangleMeshGetVertexBufferFB TriangleMeshGetVertexBufferFB{ noop::xrTriangleMeshGetVertexBufferFB };
    PFN_xrTriangleMeshGetIndexBufferFB TriangleMeshGetIndexBufferFB{ noop::xrTriangleMeshGetIndexBufferFB };
    PFN_xrTriangleMeshBeginUpdateFB TriangleMeshBeginUpdateFB{ noop::xrTriangleMeshBeginUpdateFB };
    PFN_xrTriangleMeshEndUpdateFB TriangleMeshEndUpdateFB{ noop::xrTriangleMeshEndUpdateFB };
    PFN_xrTriangleMeshBeginVertexBufferUpdateFB TriangleMeshBeginVertexBufferUpdateFB{ noop::xrTriangleMeshBeginVertexBufferUpdateFB };
    PFN_xrTriangleMeshEndVertexBufferUpdateFB TriangleMeshEndVertexBufferUpdateFB{ noop::xrTriangleMeshEndVertexBufferUpdateFB };
    PFN_xrCreatePassthroughFB CreatePassthroughFB{ noop::xrCreatePassthroughFB };
    PFN_xrDestroyPassthroughFB DestroyPassthroughFB{ noop::xrDestroyPassthroughFB };
    PFN_xrPassthroughStartFB PassthroughStartFB{ noop::xrPassthroughStartFB };
    PFN_xrPassthroughPauseFB PassthroughPauseFB{ noop::xrPassthroughPauseFB };
    PFN_xrCreatePassthroughLayerFB CreatePassthroughLayerFB{ noop::xrCreatePassthroughLayerFB };
    PFN_xrDestroyPassthroughLayerFB DestroyPassthroughLayerFB{ noop::xrDestroyPassthroughLayerFB };
    PFN_xrPassthroughLayerPauseFB PassthroughLayerPauseFB{ noop::xrPassthroughLayerPauseFB };
    PFN_xrPassthroughLayerResumeFB PassthroughLayerResumeFB{ noop::xrPassthroughLayerResumeFB };
    PFN_xrPassthroughLayerSetStyleFB PassthroughLayerSetStyleFB{ noop::xrPassthroughLayerSetStyleFB };
    PFN_xrCreateGeometryInstanceFB CreateGeometryInstanceFB{ noop::xrCreateGeometryInstanceFB };
    PFN_xrDestroyGeometryInstanceFB DestroyGeometryInstanceFB{ noop::xrDestroyGeometryInstanceFB };
    PFN_xrGeometryInstanceSetTransformFB GeometryInstanceSetTransformFB{ noop::xrGeometryInstanceSetTransformFB };
    PFN_xrEnumerateRenderModelPathsFB EnumerateRenderModelPathsFB{ noop::xrEnumerateRenderModelPathsFB };
    PFN_xrGetRenderModelPropertiesFB GetRenderModelPropertiesFB{ noop::xrGetRenderModelPropertiesFB };
    PFN_xrLoadRenderModelFB LoadRenderModelFB{ noop::xrLoadRenderModelFB };
    PFN_xrSetEnvironmentDepthEstimationVARJO SetEnvironmentDepthEstimationVARJO{ noop::xrSetEnvironmentDepthEstimationVARJO };
    PFN_xrSetMarkerTrackingVARJO SetMarkerTrackingVARJO{ noop::xrSetMarkerTrackingVARJO };
    PFN_xrSetMarkerTrackingTimeoutVARJO SetMarkerTrackingTimeoutVARJO{ noop::xrSetMarkerTrackingTimeoutVARJO };
    PFN_xrSetMarkerTrackingPredictionVARJO SetMarkerTrackingPredictionVARJO{ noop::xrSetMarkerTrackingPredictionVARJO };
    PFN_xrGetMarkerSizeVARJO GetMarkerSizeVARJO{ noop::xrGetMarkerSizeVARJO };
    PFN_xrCreateMarkerSpaceVARJO CreateMarkerSpaceVARJO{ noop::xrCreateMarkerSpaceVARJO };
    PFN_xrSetViewOffsetVARJO SetViewOffsetVARJO{ noop::xrSetViewOffsetVARJO };
    PFN_xrCreateSpaceFromCoordinateFrameUIDML CreateSpaceFromCoordinateFrameUIDML{ noop::xrCreateSpaceFromCoordinateFrameUIDML };
    PFN_xrCreateMarkerDetectorML CreateMarkerDetectorML{ noop::xrCreateMarkerDetectorML };
    PFN_xrDestroyMarkerDetectorML DestroyMarkerDetectorML{ noop::xrDestroyMarkerDetectorML };
    PFN_xrSnapshotMarkerDetectorML SnapshotMarkerDetectorML{ noop::xrSnapshotMarkerDetectorML };
    PFN_xrGetMarkerDetectorStateML GetMarkerDetectorStateML{ noop::xrGetMarkerDetectorStateML };
    PFN_xrGetMarkersML GetMarkersML{ noop::xrGetMarkersML };
    PFN_xrGetMarkerReprojectionErrorML GetMarkerReprojectionErrorML{ noop::xrGetMarkerReprojectionErrorML };
    PFN_xrGetMarkerLengthML GetMarkerLengthML{ noop::xrGetMarkerLengthML };
    PFN_xrGetMarkerNumberML GetMarkerNumberML{ noop::xrGetMarkerNumberML };
    PFN_xrGetMarkerStringML GetMarkerStringML{ noop::xrGetMarkerStringML };
    PFN_xrCreateMarkerSpaceML CreateMarkerSpaceML{ noop::xrCreateMarkerSpaceML };
    PFN_xrEnableLocalizationEventsML EnableLocalizationEventsML{ noop::xrEnableLocalizationEventsML };
    PFN_xrQueryLocalizationMapsML QueryLocalizationMapsML{ noop::xrQueryLocalizationMapsML };
    PFN_xrRequestMapLocalizationML RequestMapLocalizationML{ noop::xrRequestMapLocalizationML };
    PFN_xrImportLocalizationMapML ImportLocalizationMapML{ noop::xrImportLocalizationMapML };
    PFN_xrCreateExportedLocalizationMapML CreateExportedLocalizationMapML{ noop::xrCreateExportedLocalizationMapML };
    PFN_xrDestroyExportedLocalizationMapML DestroyExportedLocalizationMapML{ noop::xrDestroyExportedLocalizationMapML };
    PFN_xrGetExportedLocalizationMapDataML GetExportedLocalizationMapDataML{ noop::xrGetExportedLocalizationMapDataML };
    PFN_xrCreateSpatialAnchorStoreConnectionMSFT CreateSpatialAnchorStoreConnectionMSFT{ noop::xrCreateSpatialAnchorStoreConnectionMSFT };
    PFN_xrDestroySpatialAnchorStoreConnectionMSFT DestroySpatialAnchorStoreConnectionMSFT{ noop::xrDestroySpatialAnchorStoreConnectionMSFT };
    PFN_xrPersistSpatialAnchorMSFT PersistSpatialAnchorMSFT{ noop::xrPersistSpatialAnchorMSFT };
    PFN_xrEnumeratePersistedSpatialAnchorNamesMSFT EnumeratePersistedSpatialAnchorNamesMSFT{ noop::xrEnumeratePersistedSpatialAnchorNamesMSFT };
    PFN_xrCreateSpatialAnchorFromPersistedNameMSFT CreateSpatialAnchorFromPersistedNameMSFT{ noop::xrCreateSpatialAnchorFromPersistedNameMSFT };
    PFN_xrUnpersistSpatialAnchorMSFT UnpersistSpatialAnchorMSFT{ noop::xrUnpersistSpatialAnchorMSFT };
    PFN_xrClearSpatialAnchorStoreMSFT ClearSpatialAnchorStoreMSFT{ noop::xrClearSpatialAnchorStoreMSFT };
    PFN_xrGetSceneMarkerRawDataMSFT GetSceneMarkerRawDataMSFT{ noop::xrGetSceneMarkerRawDataMSFT };
    PFN_xrGetSceneMarkerDecodedStringMSFT GetSceneMarkerDecodedStringMSFT{ noop::xrGetSceneMarkerDecodedStringMSFT };
    PFN_xrQuerySpacesFB QuerySpacesFB{ noop::xrQuerySpacesFB };
    PFN_xrRetrieveSpaceQueryResultsFB RetrieveSpaceQueryResultsFB{ noop::xrRetrieveSpaceQueryResultsFB };
    PFN_xrSaveSpaceFB SaveSpaceFB{ noop::xrSaveSpaceFB };
    PFN_xrEraseSpaceFB EraseSpaceFB{ noop::xrEraseSpaceFB };
    PFN_xrGetAudioOutputDeviceGuidOculus GetAudioOutputDeviceGuidOculus{ noop::xrGetAudioOutputDeviceGuidOculus };
    PFN_xrGetAudioInputDeviceGuidOculus GetAudioInputDeviceGuidOculus{ noop::xrGetAudioInputDeviceGuidOculus };
    PFN_xrShareSpacesFB ShareSpacesFB{ noop::xrShareSpacesFB };
    PFN_xrGetSpaceBoundingBox2DFB GetSpaceBoundingBox2DFB{ noop::xrGetSpaceBoundingBox2DFB };
    PFN_xrGetSpaceBoundingBox3DFB GetSpaceBoundingBox3DFB{ noop::xrGetSpaceBoundingBox3DFB };
    PFN_xrGetSpaceSemanticLabelsFB GetSpaceSemanticLabelsFB{ noop::xrGetSpaceSemanticLabelsFB };
    PFN_xrGetSpaceBoundary2DFB GetSpaceBoundary2DFB{ noop::xrGetSpaceBoundary2DFB };
    PFN_xrGetSpaceRoomLayoutFB GetSpaceRoomLayoutFB{ noop::xrGetSpaceRoomLayoutFB };
    PFN_xrSetDigitalLensControlALMALENCE SetDigitalLensControlALMALENCE{ noop::xrSetDigitalLensControlALMALENCE };
    PFN_xrRequestSceneCaptureFB RequestSceneCaptureFB{ noop::xrRequestSceneCaptureFB };
    PFN_xrGetSpaceContainerFB GetSpaceContainerFB{ noop::xrGetSpaceContainerFB };
    PFN_xrGetFoveationEyeTrackedStateMETA GetFoveationEyeTrackedStateMETA{ noop::xrGetFoveationEyeTrackedStateMETA };
    PFN_xrCreateFaceTrackerFB CreateFaceTrackerFB{ noop::xrCreateFaceTrackerFB };
    PFN_xrDestroyFaceTrackerFB DestroyFaceTrackerFB{ noop::xrDestroyFaceTrackerFB };
    PFN_xrGetFaceExpressionWeightsFB GetFaceExpressionWeightsFB{ noop::xrGetFaceExpressionWeightsFB };
    PFN_xrCreateEyeTrackerFB CreateEyeTrackerFB{ noop::xrCreateEyeTrackerFB };
    PFN_xrDestroyEyeTrackerFB DestroyEyeTrackerFB{ noop::xrDestroyEyeTrackerFB };
    PFN_xrGetEyeGazesFB GetEyeGazesFB{ noop::xrGetEyeGazesFB };
    PFN_xrPassthroughLayerSetKeyboardHandsIntensityFB PassthroughLayerSetKeyboardHandsIntensityFB{ noop::xrPassthroughLayerSetKeyboardHandsIntensityFB };
    PFN_xrGetDeviceSampleRateFB GetDeviceSampleRateFB{ noop::xrGetDeviceSampleRateFB };
    PFN_xrGetPassthroughPreferencesMETA GetPassthroughPreferencesMETA{ noop::xrGetPassthroughPreferencesMETA };
    PFN_xrCreateVirtualKeyboardMETA CreateVirtualKeyboardMETA{ noop::xrCreateVirtualKeyboardMETA };
    PFN_xrDestroyVirtualKeyboardMETA DestroyVirtualKeyboardMETA{ noop::xrDestroyVirtualKeyboardMETA };
    PFN_xrCreateVirtualKeyboardSpaceMETA CreateVirtualKeyboardSpaceMETA{ noop::xrCreateVirtualKeyboardSpaceMETA };
    PFN_xrSuggestVirtualKeyboardLocationMETA SuggestVirtualKeyboardLocationMETA{ noop::xrSuggestVirtualKeyboardLocationMETA };
    PFN_xrGetVirtualKeyboardScaleMETA GetVirtualKeyboardScaleMETA{ noop::xrGetVirtualKeyboardScaleMETA };
    PFN_xrSetVirtualKeyboardModelVisibilityMETA SetVirtualKeyboardModelVisibilityMETA{ noop::xrSetVirtualKeyboardModelVisibilityMETA };
    PFN_xrGetVirtualKeyboardModelAnimationStatesMETA GetVirtualKeyboardModelAnimationStatesMETA{ noop::xrGetVirtualKeyboardModelAnimationStatesMETA };
    PFN_xrGetVirtualKeyboardDirtyTexturesMETA GetVirtualKeyboardDirtyTexturesMETA{ noop::xrGetVirtualKeyboardDirtyTexturesMETA };
    PFN_xrGetVirtualKeyboardTextureDataMETA GetVirtualKeyboardTextureDataMETA{ noop::xrGetVirtualKeyboardTextureDataMETA };
    PFN_xrSendVirtualKeyboardInputMETA SendVirtualKeyboardInputMETA{ noop::xrSendVirtualKeyboardInputMETA };
    PFN_xrChangeVirtualKeyboardTextContextMETA ChangeVirtualKeyboardTextContextMETA{ noop::xrChangeVirtualKeyboardTextContextMETA };
    PFN_xrEnumerateExternalCamerasOCULUS EnumerateExternalCamerasOCULUS{ noop::xrEnumerateExternalCamerasOCULUS };
    PFN_xrEnumeratePerformanceMetricsCounterPathsMETA EnumeratePerformanceMetricsCounterPathsMETA{ noop::xrEnumeratePerformanceMetricsCounterPathsMETA };
    PFN_xrSetPerformanceMetricsStateMETA SetPerformanceMetricsStateMETA{ noop::xrSetPerformanceMetricsStateMETA };
    PFN_xrGetPerformanceMetricsStateMETA GetPerformanceMetricsStateMETA{ noop::xrGetPerformanceMetricsStateMETA };
    PFN_xrQueryPerformanceMetricsCounterMETA QueryPerformanceMetricsCounterMETA{ noop::xrQueryPerformanceMetricsCounterMETA };
    PFN_xrSaveSpaceListFB SaveSpaceListFB{ noop::xrSaveSpaceListFB };
    PFN_xrCreateSpaceUserFB CreateSpaceUserFB{ noop::xrCreateSpaceUserFB };
    PFN_xrGetSpaceUserIdFB GetSpaceUserIdFB{ noop::xrGetSpaceUserIdFB };
    PFN_xrDestroySpaceUserFB DestroySpaceUserFB{ noop::xrDestroySpaceUserFB };
    PFN_xrGetRecommendedLayerResolutionMETA GetRecommendedLayerResolutionMETA{ noop::xrGetRecommendedLayerResolutionMETA };
    PFN_xrCreatePassthroughColorLutMETA CreatePassthroughColorLutMETA{ noop::xrCreatePassthroughColorLutMETA };
    PFN_xrDestroyPassthroughColorLutMETA DestroyPassthroughColorLutMETA{ noop::xrDestroyPassthroughColorLutMETA };
    PFN_xrUpdatePassthroughColorLutMETA UpdatePassthroughColorLutMETA{ noop::xrUpdatePassthroughColorLutMETA };
    PFN_xrGetSpaceTriangleMeshMETA GetSpaceTriangleMeshMETA{ noop::xrGetSpaceTriangleMeshMETA };
    PFN_xrCreateFaceTracker2FB CreateFaceTracker2FB{ noop::xrCreateFaceTracker2FB };
    PFN_xrDestroyFaceTracker2FB DestroyFaceTracker2FB{ noop::xrDestroyFaceTracker2FB };
    PFN_xrGetFaceExpressionWeights2FB GetFaceExpressionWeights2FB{ noop::xrGetFaceExpressionWeights2FB };
    PFN_xrSetTrackingOptimizationSettingsHintQCOM SetTrackingOptimizationSettingsHintQCOM{ noop::xrSetTrackingOptimizationSettingsHintQCOM };
    PFN_xrCreatePassthroughHTC CreatePassthroughHTC{ noop::xrCreatePassthroughHTC };
    PFN_xrDestroyPassthroughHTC DestroyPassthroughHTC{ noop::xrDestroyPassthroughHTC };
    PFN_xrApplyFoveationHTC ApplyFoveationHTC{ noop::xrApplyFoveationHTC };
    PFN_xrCreateSpatialAnchorHTC CreateSpatialAnchorHTC{ noop::xrCreateSpatialAnchorHTC };
    PFN_xrGetSpatialAnchorNameHTC GetSpatialAnchorNameHTC{ noop::xrGetSpatialAnchorNameHTC };
    PFN_xrApplyForceFeedbackCurlMNDX ApplyForceFeedbackCurlMNDX{ noop::xrApplyForceFeedbackCurlMNDX };
    PFN_xrCreatePlaneDetectorEXT CreatePlaneDetectorEXT{ noop::xrCreatePlaneDetectorEXT };
    PFN_xrDestroyPlaneDetectorEXT DestroyPlaneDetectorEXT{ noop::xrDestroyPlaneDetectorEXT };
    PFN_xrBeginPlaneDetectionEXT BeginPlaneDetectionEXT{ noop::xrBeginPlaneDetectionEXT };
    PFN_xrGetPlaneDetectionStateEXT GetPlaneDetectionStateEXT{ noop::xrGetPlaneDetectionStateEXT };
    PFN_xrGetPlaneDetectionsEXT GetPlaneDetectionsEXT{ noop::xrGetPlaneDetectionsEXT };
    PFN_xrGetPlanePolygonBufferEXT GetPlanePolygonBufferEXT{ noop::xrGetPlanePolygonBufferEXT };
    PFN_xrEnableUserCalibrationEventsML EnableUserCalibrationEventsML{ noop::xrEnableUserCalibrationEventsML };
};

template <typename GetProcAddr, typename Handle, typename FuncP>
static void LoadOpenXrFunction(GetProcAddr gpa, Handle handle, const char* name, FuncP* funcp)
{
    XrResult result = gpa(handle, name, reinterpret_cast<PFN_xrVoidFunction*>(funcp));
    if (result != XR_SUCCESS)
    {
        (*funcp) = nullptr;
    }
}

static void LoadOpenXrInstanceTable(PFN_xrGetInstanceProcAddr gpa, XrInstance instance, OpenXrInstanceTable* table)
{
    assert(table != nullptr);

    table->GetInstanceProcAddr = gpa;
    LoadOpenXrFunction(gpa, instance, "xrDestroyInstance", &table->DestroyInstance);
    LoadOpenXrFunction(gpa, instance, "xrGetInstanceProperties", &table->GetInstanceProperties);
    LoadOpenXrFunction(gpa, instance, "xrPollEvent", &table->PollEvent);
    LoadOpenXrFunction(gpa, instance, "xrResultToString", &table->ResultToString);
    LoadOpenXrFunction(gpa, instance, "xrStructureTypeToString", &table->StructureTypeToString);
    LoadOpenXrFunction(gpa, instance, "xrGetSystem", &table->GetSystem);
    LoadOpenXrFunction(gpa, instance, "xrGetSystemProperties", &table->GetSystemProperties);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateEnvironmentBlendModes", &table->EnumerateEnvironmentBlendModes);
    LoadOpenXrFunction(gpa, instance, "xrCreateSession", &table->CreateSession);
    LoadOpenXrFunction(gpa, instance, "xrDestroySession", &table->DestroySession);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateReferenceSpaces", &table->EnumerateReferenceSpaces);
    LoadOpenXrFunction(gpa, instance, "xrCreateReferenceSpace", &table->CreateReferenceSpace);
    LoadOpenXrFunction(gpa, instance, "xrGetReferenceSpaceBoundsRect", &table->GetReferenceSpaceBoundsRect);
    LoadOpenXrFunction(gpa, instance, "xrCreateActionSpace", &table->CreateActionSpace);
    LoadOpenXrFunction(gpa, instance, "xrLocateSpace", &table->LocateSpace);
    LoadOpenXrFunction(gpa, instance, "xrDestroySpace", &table->DestroySpace);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateViewConfigurations", &table->EnumerateViewConfigurations);
    LoadOpenXrFunction(gpa, instance, "xrGetViewConfigurationProperties", &table->GetViewConfigurationProperties);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateViewConfigurationViews", &table->EnumerateViewConfigurationViews);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateSwapchainFormats", &table->EnumerateSwapchainFormats);
    LoadOpenXrFunction(gpa, instance, "xrCreateSwapchain", &table->CreateSwapchain);
    LoadOpenXrFunction(gpa, instance, "xrDestroySwapchain", &table->DestroySwapchain);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateSwapchainImages", &table->EnumerateSwapchainImages);
    LoadOpenXrFunction(gpa, instance, "xrAcquireSwapchainImage", &table->AcquireSwapchainImage);
    LoadOpenXrFunction(gpa, instance, "xrWaitSwapchainImage", &table->WaitSwapchainImage);
    LoadOpenXrFunction(gpa, instance, "xrReleaseSwapchainImage", &table->ReleaseSwapchainImage);
    LoadOpenXrFunction(gpa, instance, "xrBeginSession", &table->BeginSession);
    LoadOpenXrFunction(gpa, instance, "xrEndSession", &table->EndSession);
    LoadOpenXrFunction(gpa, instance, "xrRequestExitSession", &table->RequestExitSession);
    LoadOpenXrFunction(gpa, instance, "xrWaitFrame", &table->WaitFrame);
    LoadOpenXrFunction(gpa, instance, "xrBeginFrame", &table->BeginFrame);
    LoadOpenXrFunction(gpa, instance, "xrEndFrame", &table->EndFrame);
    LoadOpenXrFunction(gpa, instance, "xrLocateViews", &table->LocateViews);
    LoadOpenXrFunction(gpa, instance, "xrStringToPath", &table->StringToPath);
    LoadOpenXrFunction(gpa, instance, "xrPathToString", &table->PathToString);
    LoadOpenXrFunction(gpa, instance, "xrCreateActionSet", &table->CreateActionSet);
    LoadOpenXrFunction(gpa, instance, "xrDestroyActionSet", &table->DestroyActionSet);
    LoadOpenXrFunction(gpa, instance, "xrCreateAction", &table->CreateAction);
    LoadOpenXrFunction(gpa, instance, "xrDestroyAction", &table->DestroyAction);
    LoadOpenXrFunction(gpa, instance, "xrSuggestInteractionProfileBindings", &table->SuggestInteractionProfileBindings);
    LoadOpenXrFunction(gpa, instance, "xrAttachSessionActionSets", &table->AttachSessionActionSets);
    LoadOpenXrFunction(gpa, instance, "xrGetCurrentInteractionProfile", &table->GetCurrentInteractionProfile);
    LoadOpenXrFunction(gpa, instance, "xrGetActionStateBoolean", &table->GetActionStateBoolean);
    LoadOpenXrFunction(gpa, instance, "xrGetActionStateFloat", &table->GetActionStateFloat);
    LoadOpenXrFunction(gpa, instance, "xrGetActionStateVector2f", &table->GetActionStateVector2f);
    LoadOpenXrFunction(gpa, instance, "xrGetActionStatePose", &table->GetActionStatePose);
    LoadOpenXrFunction(gpa, instance, "xrSyncActions", &table->SyncActions);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateBoundSourcesForAction", &table->EnumerateBoundSourcesForAction);
    LoadOpenXrFunction(gpa, instance, "xrGetInputSourceLocalizedName", &table->GetInputSourceLocalizedName);
    LoadOpenXrFunction(gpa, instance, "xrApplyHapticFeedback", &table->ApplyHapticFeedback);
    LoadOpenXrFunction(gpa, instance, "xrStopHapticFeedback", &table->StopHapticFeedback);
    LoadOpenXrFunction(gpa, instance, "xrSetAndroidApplicationThreadKHR", &table->SetAndroidApplicationThreadKHR);
    LoadOpenXrFunction(gpa, instance, "xrCreateSwapchainAndroidSurfaceKHR", &table->CreateSwapchainAndroidSurfaceKHR);
    LoadOpenXrFunction(gpa, instance, "xrGetOpenGLGraphicsRequirementsKHR", &table->GetOpenGLGraphicsRequirementsKHR);
    LoadOpenXrFunction(gpa, instance, "xrGetOpenGLESGraphicsRequirementsKHR", &table->GetOpenGLESGraphicsRequirementsKHR);
    LoadOpenXrFunction(gpa, instance, "xrGetVulkanInstanceExtensionsKHR", &table->GetVulkanInstanceExtensionsKHR);
    LoadOpenXrFunction(gpa, instance, "xrGetVulkanDeviceExtensionsKHR", &table->GetVulkanDeviceExtensionsKHR);
    LoadOpenXrFunction(gpa, instance, "xrGetVulkanGraphicsDeviceKHR", &table->GetVulkanGraphicsDeviceKHR);
    LoadOpenXrFunction(gpa, instance, "xrGetVulkanGraphicsRequirementsKHR", &table->GetVulkanGraphicsRequirementsKHR);
    LoadOpenXrFunction(gpa, instance, "xrGetD3D11GraphicsRequirementsKHR", &table->GetD3D11GraphicsRequirementsKHR);
    LoadOpenXrFunction(gpa, instance, "xrGetD3D12GraphicsRequirementsKHR", &table->GetD3D12GraphicsRequirementsKHR);
    LoadOpenXrFunction(gpa, instance, "xrGetVisibilityMaskKHR", &table->GetVisibilityMaskKHR);
    LoadOpenXrFunction(gpa, instance, "xrConvertWin32PerformanceCounterToTimeKHR", &table->ConvertWin32PerformanceCounterToTimeKHR);
    LoadOpenXrFunction(gpa, instance, "xrConvertTimeToWin32PerformanceCounterKHR", &table->ConvertTimeToWin32PerformanceCounterKHR);
    LoadOpenXrFunction(gpa, instance, "xrConvertTimespecTimeToTimeKHR", &table->ConvertTimespecTimeToTimeKHR);
    LoadOpenXrFunction(gpa, instance, "xrConvertTimeToTimespecTimeKHR", &table->ConvertTimeToTimespecTimeKHR);
    LoadOpenXrFunction(gpa, instance, "xrCreateVulkanInstanceKHR", &table->CreateVulkanInstanceKHR);
    LoadOpenXrFunction(gpa, instance, "xrCreateVulkanDeviceKHR", &table->CreateVulkanDeviceKHR);
    LoadOpenXrFunction(gpa, instance, "xrGetVulkanGraphicsDevice2KHR", &table->GetVulkanGraphicsDevice2KHR);
    LoadOpenXrFunction(gpa, instance, "xrGetVulkanGraphicsRequirements2KHR", &table->GetVulkanGraphicsRequirements2KHR);
    LoadOpenXrFunction(gpa, instance, "xrPerfSettingsSetPerformanceLevelEXT", &table->PerfSettingsSetPerformanceLevelEXT);
    LoadOpenXrFunction(gpa, instance, "xrThermalGetTemperatureTrendEXT", &table->ThermalGetTemperatureTrendEXT);
    LoadOpenXrFunction(gpa, instance, "xrSetDebugUtilsObjectNameEXT", &table->SetDebugUtilsObjectNameEXT);
    LoadOpenXrFunction(gpa, instance, "xrCreateDebugUtilsMessengerEXT", &table->CreateDebugUtilsMessengerEXT);
    LoadOpenXrFunction(gpa, instance, "xrDestroyDebugUtilsMessengerEXT", &table->DestroyDebugUtilsMessengerEXT);
    LoadOpenXrFunction(gpa, instance, "xrSubmitDebugUtilsMessageEXT", &table->SubmitDebugUtilsMessageEXT);
    LoadOpenXrFunction(gpa, instance, "xrSessionBeginDebugUtilsLabelRegionEXT", &table->SessionBeginDebugUtilsLabelRegionEXT);
    LoadOpenXrFunction(gpa, instance, "xrSessionEndDebugUtilsLabelRegionEXT", &table->SessionEndDebugUtilsLabelRegionEXT);
    LoadOpenXrFunction(gpa, instance, "xrSessionInsertDebugUtilsLabelEXT", &table->SessionInsertDebugUtilsLabelEXT);
    LoadOpenXrFunction(gpa, instance, "xrCreateSpatialAnchorMSFT", &table->CreateSpatialAnchorMSFT);
    LoadOpenXrFunction(gpa, instance, "xrCreateSpatialAnchorSpaceMSFT", &table->CreateSpatialAnchorSpaceMSFT);
    LoadOpenXrFunction(gpa, instance, "xrDestroySpatialAnchorMSFT", &table->DestroySpatialAnchorMSFT);
    LoadOpenXrFunction(gpa, instance, "xrSetInputDeviceActiveEXT", &table->SetInputDeviceActiveEXT);
    LoadOpenXrFunction(gpa, instance, "xrSetInputDeviceStateBoolEXT", &table->SetInputDeviceStateBoolEXT);
    LoadOpenXrFunction(gpa, instance, "xrSetInputDeviceStateFloatEXT", &table->SetInputDeviceStateFloatEXT);
    LoadOpenXrFunction(gpa, instance, "xrSetInputDeviceStateVector2fEXT", &table->SetInputDeviceStateVector2fEXT);
    LoadOpenXrFunction(gpa, instance, "xrSetInputDeviceLocationEXT", &table->SetInputDeviceLocationEXT);
    LoadOpenXrFunction(gpa, instance, "xrCreateSpatialGraphNodeSpaceMSFT", &table->CreateSpatialGraphNodeSpaceMSFT);
    LoadOpenXrFunction(gpa, instance, "xrTryCreateSpatialGraphStaticNodeBindingMSFT", &table->TryCreateSpatialGraphStaticNodeBindingMSFT);
    LoadOpenXrFunction(gpa, instance, "xrDestroySpatialGraphNodeBindingMSFT", &table->DestroySpatialGraphNodeBindingMSFT);
    LoadOpenXrFunction(gpa, instance, "xrGetSpatialGraphNodeBindingPropertiesMSFT", &table->GetSpatialGraphNodeBindingPropertiesMSFT);
    LoadOpenXrFunction(gpa, instance, "xrCreateHandTrackerEXT", &table->CreateHandTrackerEXT);
    LoadOpenXrFunction(gpa, instance, "xrDestroyHandTrackerEXT", &table->DestroyHandTrackerEXT);
    LoadOpenXrFunction(gpa, instance, "xrLocateHandJointsEXT", &table->LocateHandJointsEXT);
    LoadOpenXrFunction(gpa, instance, "xrCreateHandMeshSpaceMSFT", &table->CreateHandMeshSpaceMSFT);
    LoadOpenXrFunction(gpa, instance, "xrUpdateHandMeshMSFT", &table->UpdateHandMeshMSFT);
    LoadOpenXrFunction(gpa, instance, "xrGetControllerModelKeyMSFT", &table->GetControllerModelKeyMSFT);
    LoadOpenXrFunction(gpa, instance, "xrLoadControllerModelMSFT", &table->LoadControllerModelMSFT);
    LoadOpenXrFunction(gpa, instance, "xrGetControllerModelPropertiesMSFT", &table->GetControllerModelPropertiesMSFT);
    LoadOpenXrFunction(gpa, instance, "xrGetControllerModelStateMSFT", &table->GetControllerModelStateMSFT);
    LoadOpenXrFunction(gpa, instance, "xrCreateSpatialAnchorFromPerceptionAnchorMSFT", &table->CreateSpatialAnchorFromPerceptionAnchorMSFT);
    LoadOpenXrFunction(gpa, instance, "xrTryGetPerceptionAnchorFromSpatialAnchorMSFT", &table->TryGetPerceptionAnchorFromSpatialAnchorMSFT);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateReprojectionModesMSFT", &table->EnumerateReprojectionModesMSFT);
    LoadOpenXrFunction(gpa, instance, "xrUpdateSwapchainFB", &table->UpdateSwapchainFB);
    LoadOpenXrFunction(gpa, instance, "xrGetSwapchainStateFB", &table->GetSwapchainStateFB);
    LoadOpenXrFunction(gpa, instance, "xrCreateBodyTrackerFB", &table->CreateBodyTrackerFB);
    LoadOpenXrFunction(gpa, instance, "xrDestroyBodyTrackerFB", &table->DestroyBodyTrackerFB);
    LoadOpenXrFunction(gpa, instance, "xrLocateBodyJointsFB", &table->LocateBodyJointsFB);
    LoadOpenXrFunction(gpa, instance, "xrGetBodySkeletonFB", &table->GetBodySkeletonFB);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateSceneComputeFeaturesMSFT", &table->EnumerateSceneComputeFeaturesMSFT);
    LoadOpenXrFunction(gpa, instance, "xrCreateSceneObserverMSFT", &table->CreateSceneObserverMSFT);
    LoadOpenXrFunction(gpa, instance, "xrDestroySceneObserverMSFT", &table->DestroySceneObserverMSFT);
    LoadOpenXrFunction(gpa, instance, "xrCreateSceneMSFT", &table->CreateSceneMSFT);
    LoadOpenXrFunction(gpa, instance, "xrDestroySceneMSFT", &table->DestroySceneMSFT);
    LoadOpenXrFunction(gpa, instance, "xrComputeNewSceneMSFT", &table->ComputeNewSceneMSFT);
    LoadOpenXrFunction(gpa, instance, "xrGetSceneComputeStateMSFT", &table->GetSceneComputeStateMSFT);
    LoadOpenXrFunction(gpa, instance, "xrGetSceneComponentsMSFT", &table->GetSceneComponentsMSFT);
    LoadOpenXrFunction(gpa, instance, "xrLocateSceneComponentsMSFT", &table->LocateSceneComponentsMSFT);
    LoadOpenXrFunction(gpa, instance, "xrGetSceneMeshBuffersMSFT", &table->GetSceneMeshBuffersMSFT);
    LoadOpenXrFunction(gpa, instance, "xrDeserializeSceneMSFT", &table->DeserializeSceneMSFT);
    LoadOpenXrFunction(gpa, instance, "xrGetSerializedSceneFragmentDataMSFT", &table->GetSerializedSceneFragmentDataMSFT);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateDisplayRefreshRatesFB", &table->EnumerateDisplayRefreshRatesFB);
    LoadOpenXrFunction(gpa, instance, "xrGetDisplayRefreshRateFB", &table->GetDisplayRefreshRateFB);
    LoadOpenXrFunction(gpa, instance, "xrRequestDisplayRefreshRateFB", &table->RequestDisplayRefreshRateFB);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateViveTrackerPathsHTCX", &table->EnumerateViveTrackerPathsHTCX);
    LoadOpenXrFunction(gpa, instance, "xrCreateFacialTrackerHTC", &table->CreateFacialTrackerHTC);
    LoadOpenXrFunction(gpa, instance, "xrDestroyFacialTrackerHTC", &table->DestroyFacialTrackerHTC);
    LoadOpenXrFunction(gpa, instance, "xrGetFacialExpressionsHTC", &table->GetFacialExpressionsHTC);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateColorSpacesFB", &table->EnumerateColorSpacesFB);
    LoadOpenXrFunction(gpa, instance, "xrSetColorSpaceFB", &table->SetColorSpaceFB);
    LoadOpenXrFunction(gpa, instance, "xrGetHandMeshFB", &table->GetHandMeshFB);
    LoadOpenXrFunction(gpa, instance, "xrCreateSpatialAnchorFB", &table->CreateSpatialAnchorFB);
    LoadOpenXrFunction(gpa, instance, "xrGetSpaceUuidFB", &table->GetSpaceUuidFB);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateSpaceSupportedComponentsFB", &table->EnumerateSpaceSupportedComponentsFB);
    LoadOpenXrFunction(gpa, instance, "xrSetSpaceComponentStatusFB", &table->SetSpaceComponentStatusFB);
    LoadOpenXrFunction(gpa, instance, "xrGetSpaceComponentStatusFB", &table->GetSpaceComponentStatusFB);
    LoadOpenXrFunction(gpa, instance, "xrCreateFoveationProfileFB", &table->CreateFoveationProfileFB);
    LoadOpenXrFunction(gpa, instance, "xrDestroyFoveationProfileFB", &table->DestroyFoveationProfileFB);
    LoadOpenXrFunction(gpa, instance, "xrQuerySystemTrackedKeyboardFB", &table->QuerySystemTrackedKeyboardFB);
    LoadOpenXrFunction(gpa, instance, "xrCreateKeyboardSpaceFB", &table->CreateKeyboardSpaceFB);
    LoadOpenXrFunction(gpa, instance, "xrCreateTriangleMeshFB", &table->CreateTriangleMeshFB);
    LoadOpenXrFunction(gpa, instance, "xrDestroyTriangleMeshFB", &table->DestroyTriangleMeshFB);
    LoadOpenXrFunction(gpa, instance, "xrTriangleMeshGetVertexBufferFB", &table->TriangleMeshGetVertexBufferFB);
    LoadOpenXrFunction(gpa, instance, "xrTriangleMeshGetIndexBufferFB", &table->TriangleMeshGetIndexBufferFB);
    LoadOpenXrFunction(gpa, instance, "xrTriangleMeshBeginUpdateFB", &table->TriangleMeshBeginUpdateFB);
    LoadOpenXrFunction(gpa, instance, "xrTriangleMeshEndUpdateFB", &table->TriangleMeshEndUpdateFB);
    LoadOpenXrFunction(gpa, instance, "xrTriangleMeshBeginVertexBufferUpdateFB", &table->TriangleMeshBeginVertexBufferUpdateFB);
    LoadOpenXrFunction(gpa, instance, "xrTriangleMeshEndVertexBufferUpdateFB", &table->TriangleMeshEndVertexBufferUpdateFB);
    LoadOpenXrFunction(gpa, instance, "xrCreatePassthroughFB", &table->CreatePassthroughFB);
    LoadOpenXrFunction(gpa, instance, "xrDestroyPassthroughFB", &table->DestroyPassthroughFB);
    LoadOpenXrFunction(gpa, instance, "xrPassthroughStartFB", &table->PassthroughStartFB);
    LoadOpenXrFunction(gpa, instance, "xrPassthroughPauseFB", &table->PassthroughPauseFB);
    LoadOpenXrFunction(gpa, instance, "xrCreatePassthroughLayerFB", &table->CreatePassthroughLayerFB);
    LoadOpenXrFunction(gpa, instance, "xrDestroyPassthroughLayerFB", &table->DestroyPassthroughLayerFB);
    LoadOpenXrFunction(gpa, instance, "xrPassthroughLayerPauseFB", &table->PassthroughLayerPauseFB);
    LoadOpenXrFunction(gpa, instance, "xrPassthroughLayerResumeFB", &table->PassthroughLayerResumeFB);
    LoadOpenXrFunction(gpa, instance, "xrPassthroughLayerSetStyleFB", &table->PassthroughLayerSetStyleFB);
    LoadOpenXrFunction(gpa, instance, "xrCreateGeometryInstanceFB", &table->CreateGeometryInstanceFB);
    LoadOpenXrFunction(gpa, instance, "xrDestroyGeometryInstanceFB", &table->DestroyGeometryInstanceFB);
    LoadOpenXrFunction(gpa, instance, "xrGeometryInstanceSetTransformFB", &table->GeometryInstanceSetTransformFB);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateRenderModelPathsFB", &table->EnumerateRenderModelPathsFB);
    LoadOpenXrFunction(gpa, instance, "xrGetRenderModelPropertiesFB", &table->GetRenderModelPropertiesFB);
    LoadOpenXrFunction(gpa, instance, "xrLoadRenderModelFB", &table->LoadRenderModelFB);
    LoadOpenXrFunction(gpa, instance, "xrSetEnvironmentDepthEstimationVARJO", &table->SetEnvironmentDepthEstimationVARJO);
    LoadOpenXrFunction(gpa, instance, "xrSetMarkerTrackingVARJO", &table->SetMarkerTrackingVARJO);
    LoadOpenXrFunction(gpa, instance, "xrSetMarkerTrackingTimeoutVARJO", &table->SetMarkerTrackingTimeoutVARJO);
    LoadOpenXrFunction(gpa, instance, "xrSetMarkerTrackingPredictionVARJO", &table->SetMarkerTrackingPredictionVARJO);
    LoadOpenXrFunction(gpa, instance, "xrGetMarkerSizeVARJO", &table->GetMarkerSizeVARJO);
    LoadOpenXrFunction(gpa, instance, "xrCreateMarkerSpaceVARJO", &table->CreateMarkerSpaceVARJO);
    LoadOpenXrFunction(gpa, instance, "xrSetViewOffsetVARJO", &table->SetViewOffsetVARJO);
    LoadOpenXrFunction(gpa, instance, "xrCreateSpaceFromCoordinateFrameUIDML", &table->CreateSpaceFromCoordinateFrameUIDML);
    LoadOpenXrFunction(gpa, instance, "xrCreateMarkerDetectorML", &table->CreateMarkerDetectorML);
    LoadOpenXrFunction(gpa, instance, "xrDestroyMarkerDetectorML", &table->DestroyMarkerDetectorML);
    LoadOpenXrFunction(gpa, instance, "xrSnapshotMarkerDetectorML", &table->SnapshotMarkerDetectorML);
    LoadOpenXrFunction(gpa, instance, "xrGetMarkerDetectorStateML", &table->GetMarkerDetectorStateML);
    LoadOpenXrFunction(gpa, instance, "xrGetMarkersML", &table->GetMarkersML);
    LoadOpenXrFunction(gpa, instance, "xrGetMarkerReprojectionErrorML", &table->GetMarkerReprojectionErrorML);
    LoadOpenXrFunction(gpa, instance, "xrGetMarkerLengthML", &table->GetMarkerLengthML);
    LoadOpenXrFunction(gpa, instance, "xrGetMarkerNumberML", &table->GetMarkerNumberML);
    LoadOpenXrFunction(gpa, instance, "xrGetMarkerStringML", &table->GetMarkerStringML);
    LoadOpenXrFunction(gpa, instance, "xrCreateMarkerSpaceML", &table->CreateMarkerSpaceML);
    LoadOpenXrFunction(gpa, instance, "xrEnableLocalizationEventsML", &table->EnableLocalizationEventsML);
    LoadOpenXrFunction(gpa, instance, "xrQueryLocalizationMapsML", &table->QueryLocalizationMapsML);
    LoadOpenXrFunction(gpa, instance, "xrRequestMapLocalizationML", &table->RequestMapLocalizationML);
    LoadOpenXrFunction(gpa, instance, "xrImportLocalizationMapML", &table->ImportLocalizationMapML);
    LoadOpenXrFunction(gpa, instance, "xrCreateExportedLocalizationMapML", &table->CreateExportedLocalizationMapML);
    LoadOpenXrFunction(gpa, instance, "xrDestroyExportedLocalizationMapML", &table->DestroyExportedLocalizationMapML);
    LoadOpenXrFunction(gpa, instance, "xrGetExportedLocalizationMapDataML", &table->GetExportedLocalizationMapDataML);
    LoadOpenXrFunction(gpa, instance, "xrCreateSpatialAnchorStoreConnectionMSFT", &table->CreateSpatialAnchorStoreConnectionMSFT);
    LoadOpenXrFunction(gpa, instance, "xrDestroySpatialAnchorStoreConnectionMSFT", &table->DestroySpatialAnchorStoreConnectionMSFT);
    LoadOpenXrFunction(gpa, instance, "xrPersistSpatialAnchorMSFT", &table->PersistSpatialAnchorMSFT);
    LoadOpenXrFunction(gpa, instance, "xrEnumeratePersistedSpatialAnchorNamesMSFT", &table->EnumeratePersistedSpatialAnchorNamesMSFT);
    LoadOpenXrFunction(gpa, instance, "xrCreateSpatialAnchorFromPersistedNameMSFT", &table->CreateSpatialAnchorFromPersistedNameMSFT);
    LoadOpenXrFunction(gpa, instance, "xrUnpersistSpatialAnchorMSFT", &table->UnpersistSpatialAnchorMSFT);
    LoadOpenXrFunction(gpa, instance, "xrClearSpatialAnchorStoreMSFT", &table->ClearSpatialAnchorStoreMSFT);
    LoadOpenXrFunction(gpa, instance, "xrGetSceneMarkerRawDataMSFT", &table->GetSceneMarkerRawDataMSFT);
    LoadOpenXrFunction(gpa, instance, "xrGetSceneMarkerDecodedStringMSFT", &table->GetSceneMarkerDecodedStringMSFT);
    LoadOpenXrFunction(gpa, instance, "xrQuerySpacesFB", &table->QuerySpacesFB);
    LoadOpenXrFunction(gpa, instance, "xrRetrieveSpaceQueryResultsFB", &table->RetrieveSpaceQueryResultsFB);
    LoadOpenXrFunction(gpa, instance, "xrSaveSpaceFB", &table->SaveSpaceFB);
    LoadOpenXrFunction(gpa, instance, "xrEraseSpaceFB", &table->EraseSpaceFB);
    LoadOpenXrFunction(gpa, instance, "xrGetAudioOutputDeviceGuidOculus", &table->GetAudioOutputDeviceGuidOculus);
    LoadOpenXrFunction(gpa, instance, "xrGetAudioInputDeviceGuidOculus", &table->GetAudioInputDeviceGuidOculus);
    LoadOpenXrFunction(gpa, instance, "xrShareSpacesFB", &table->ShareSpacesFB);
    LoadOpenXrFunction(gpa, instance, "xrGetSpaceBoundingBox2DFB", &table->GetSpaceBoundingBox2DFB);
    LoadOpenXrFunction(gpa, instance, "xrGetSpaceBoundingBox3DFB", &table->GetSpaceBoundingBox3DFB);
    LoadOpenXrFunction(gpa, instance, "xrGetSpaceSemanticLabelsFB", &table->GetSpaceSemanticLabelsFB);
    LoadOpenXrFunction(gpa, instance, "xrGetSpaceBoundary2DFB", &table->GetSpaceBoundary2DFB);
    LoadOpenXrFunction(gpa, instance, "xrGetSpaceRoomLayoutFB", &table->GetSpaceRoomLayoutFB);
    LoadOpenXrFunction(gpa, instance, "xrSetDigitalLensControlALMALENCE", &table->SetDigitalLensControlALMALENCE);
    LoadOpenXrFunction(gpa, instance, "xrRequestSceneCaptureFB", &table->RequestSceneCaptureFB);
    LoadOpenXrFunction(gpa, instance, "xrGetSpaceContainerFB", &table->GetSpaceContainerFB);
    LoadOpenXrFunction(gpa, instance, "xrGetFoveationEyeTrackedStateMETA", &table->GetFoveationEyeTrackedStateMETA);
    LoadOpenXrFunction(gpa, instance, "xrCreateFaceTrackerFB", &table->CreateFaceTrackerFB);
    LoadOpenXrFunction(gpa, instance, "xrDestroyFaceTrackerFB", &table->DestroyFaceTrackerFB);
    LoadOpenXrFunction(gpa, instance, "xrGetFaceExpressionWeightsFB", &table->GetFaceExpressionWeightsFB);
    LoadOpenXrFunction(gpa, instance, "xrCreateEyeTrackerFB", &table->CreateEyeTrackerFB);
    LoadOpenXrFunction(gpa, instance, "xrDestroyEyeTrackerFB", &table->DestroyEyeTrackerFB);
    LoadOpenXrFunction(gpa, instance, "xrGetEyeGazesFB", &table->GetEyeGazesFB);
    LoadOpenXrFunction(gpa, instance, "xrPassthroughLayerSetKeyboardHandsIntensityFB", &table->PassthroughLayerSetKeyboardHandsIntensityFB);
    LoadOpenXrFunction(gpa, instance, "xrGetDeviceSampleRateFB", &table->GetDeviceSampleRateFB);
    LoadOpenXrFunction(gpa, instance, "xrGetPassthroughPreferencesMETA", &table->GetPassthroughPreferencesMETA);
    LoadOpenXrFunction(gpa, instance, "xrCreateVirtualKeyboardMETA", &table->CreateVirtualKeyboardMETA);
    LoadOpenXrFunction(gpa, instance, "xrDestroyVirtualKeyboardMETA", &table->DestroyVirtualKeyboardMETA);
    LoadOpenXrFunction(gpa, instance, "xrCreateVirtualKeyboardSpaceMETA", &table->CreateVirtualKeyboardSpaceMETA);
    LoadOpenXrFunction(gpa, instance, "xrSuggestVirtualKeyboardLocationMETA", &table->SuggestVirtualKeyboardLocationMETA);
    LoadOpenXrFunction(gpa, instance, "xrGetVirtualKeyboardScaleMETA", &table->GetVirtualKeyboardScaleMETA);
    LoadOpenXrFunction(gpa, instance, "xrSetVirtualKeyboardModelVisibilityMETA", &table->SetVirtualKeyboardModelVisibilityMETA);
    LoadOpenXrFunction(gpa, instance, "xrGetVirtualKeyboardModelAnimationStatesMETA", &table->GetVirtualKeyboardModelAnimationStatesMETA);
    LoadOpenXrFunction(gpa, instance, "xrGetVirtualKeyboardDirtyTexturesMETA", &table->GetVirtualKeyboardDirtyTexturesMETA);
    LoadOpenXrFunction(gpa, instance, "xrGetVirtualKeyboardTextureDataMETA", &table->GetVirtualKeyboardTextureDataMETA);
    LoadOpenXrFunction(gpa, instance, "xrSendVirtualKeyboardInputMETA", &table->SendVirtualKeyboardInputMETA);
    LoadOpenXrFunction(gpa, instance, "xrChangeVirtualKeyboardTextContextMETA", &table->ChangeVirtualKeyboardTextContextMETA);
    LoadOpenXrFunction(gpa, instance, "xrEnumerateExternalCamerasOCULUS", &table->EnumerateExternalCamerasOCULUS);
    LoadOpenXrFunction(gpa, instance, "xrEnumeratePerformanceMetricsCounterPathsMETA", &table->EnumeratePerformanceMetricsCounterPathsMETA);
    LoadOpenXrFunction(gpa, instance, "xrSetPerformanceMetricsStateMETA", &table->SetPerformanceMetricsStateMETA);
    LoadOpenXrFunction(gpa, instance, "xrGetPerformanceMetricsStateMETA", &table->GetPerformanceMetricsStateMETA);
    LoadOpenXrFunction(gpa, instance, "xrQueryPerformanceMetricsCounterMETA", &table->QueryPerformanceMetricsCounterMETA);
    LoadOpenXrFunction(gpa, instance, "xrSaveSpaceListFB", &table->SaveSpaceListFB);
    LoadOpenXrFunction(gpa, instance, "xrCreateSpaceUserFB", &table->CreateSpaceUserFB);
    LoadOpenXrFunction(gpa, instance, "xrGetSpaceUserIdFB", &table->GetSpaceUserIdFB);
    LoadOpenXrFunction(gpa, instance, "xrDestroySpaceUserFB", &table->DestroySpaceUserFB);
    LoadOpenXrFunction(gpa, instance, "xrGetRecommendedLayerResolutionMETA", &table->GetRecommendedLayerResolutionMETA);
    LoadOpenXrFunction(gpa, instance, "xrCreatePassthroughColorLutMETA", &table->CreatePassthroughColorLutMETA);
    LoadOpenXrFunction(gpa, instance, "xrDestroyPassthroughColorLutMETA", &table->DestroyPassthroughColorLutMETA);
    LoadOpenXrFunction(gpa, instance, "xrUpdatePassthroughColorLutMETA", &table->UpdatePassthroughColorLutMETA);
    LoadOpenXrFunction(gpa, instance, "xrGetSpaceTriangleMeshMETA", &table->GetSpaceTriangleMeshMETA);
    LoadOpenXrFunction(gpa, instance, "xrCreateFaceTracker2FB", &table->CreateFaceTracker2FB);
    LoadOpenXrFunction(gpa, instance, "xrDestroyFaceTracker2FB", &table->DestroyFaceTracker2FB);
    LoadOpenXrFunction(gpa, instance, "xrGetFaceExpressionWeights2FB", &table->GetFaceExpressionWeights2FB);
    LoadOpenXrFunction(gpa, instance, "xrSetTrackingOptimizationSettingsHintQCOM", &table->SetTrackingOptimizationSettingsHintQCOM);
    LoadOpenXrFunction(gpa, instance, "xrCreatePassthroughHTC", &table->CreatePassthroughHTC);
    LoadOpenXrFunction(gpa, instance, "xrDestroyPassthroughHTC", &table->DestroyPassthroughHTC);
    LoadOpenXrFunction(gpa, instance, "xrApplyFoveationHTC", &table->ApplyFoveationHTC);
    LoadOpenXrFunction(gpa, instance, "xrCreateSpatialAnchorHTC", &table->CreateSpatialAnchorHTC);
    LoadOpenXrFunction(gpa, instance, "xrGetSpatialAnchorNameHTC", &table->GetSpatialAnchorNameHTC);
    LoadOpenXrFunction(gpa, instance, "xrApplyForceFeedbackCurlMNDX", &table->ApplyForceFeedbackCurlMNDX);
    LoadOpenXrFunction(gpa, instance, "xrCreatePlaneDetectorEXT", &table->CreatePlaneDetectorEXT);
    LoadOpenXrFunction(gpa, instance, "xrDestroyPlaneDetectorEXT", &table->DestroyPlaneDetectorEXT);
    LoadOpenXrFunction(gpa, instance, "xrBeginPlaneDetectionEXT", &table->BeginPlaneDetectionEXT);
    LoadOpenXrFunction(gpa, instance, "xrGetPlaneDetectionStateEXT", &table->GetPlaneDetectionStateEXT);
    LoadOpenXrFunction(gpa, instance, "xrGetPlaneDetectionsEXT", &table->GetPlaneDetectionsEXT);
    LoadOpenXrFunction(gpa, instance, "xrGetPlanePolygonBufferEXT", &table->GetPlanePolygonBufferEXT);
    LoadOpenXrFunction(gpa, instance, "xrEnableUserCalibrationEventsML", &table->EnableUserCalibrationEventsML);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_DISPATCH_TABLE_H
