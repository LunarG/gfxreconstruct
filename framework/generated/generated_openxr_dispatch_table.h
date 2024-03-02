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

#include "format/platform_types.h"
#include "util/defines.h"
#include "util/logging.h"

#include <openxr/openxr.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

#ifdef XR_USE_PLATFORM_ANDROID
#endif /* XR_USE_PLATFORM_ANDROID */
#ifdef XR_USE_PLATFORM_ANDROID
#endif /* XR_USE_PLATFORM_ANDROID */
#ifdef XR_USE_GRAPHICS_API_OPENGL
#endif /* XR_USE_GRAPHICS_API_OPENGL */
#ifdef XR_USE_GRAPHICS_API_OPENGL_ES
#endif /* XR_USE_GRAPHICS_API_OPENGL_ES */
#ifdef XR_USE_GRAPHICS_API_VULKAN
#endif /* XR_USE_GRAPHICS_API_VULKAN */
#ifdef XR_USE_GRAPHICS_API_D3D11
#endif /* XR_USE_GRAPHICS_API_D3D11 */
#ifdef XR_USE_GRAPHICS_API_D3D12
#endif /* XR_USE_GRAPHICS_API_D3D12 */
#ifdef XR_USE_PLATFORM_WIN32
#endif /* XR_USE_PLATFORM_WIN32 */
#ifdef XR_USE_TIMESPEC
#endif /* XR_USE_TIMESPEC */
#ifdef XR_USE_GRAPHICS_API_VULKAN
#endif /* XR_USE_GRAPHICS_API_VULKAN */
#ifdef XR_USE_PLATFORM_WIN32
#endif /* XR_USE_PLATFORM_WIN32 */
#ifdef XR_USE_PLATFORM_ML
#endif /* XR_USE_PLATFORM_ML */
#ifdef XR_USE_PLATFORM_WIN32
#endif /* XR_USE_PLATFORM_WIN32 */

typedef const void* DispatchKey;

// Retrieve a dispatch key from a dispatchable handle
static DispatchKey GetDispatchKey(const void* handle)
{
    const DispatchKey* dispatch_key = reinterpret_cast<const DispatchKey*>(handle);
    return (*dispatch_key);
}

GFXRECON_BEGIN_NAMESPACE(noop)
// clang-format off
static XRAPI_ATTR XrResult XRAPI_CALL GetInstanceProcAddr(XrInstance, const char*, PFN_xrVoidFunction*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetInstanceProcAddr was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyInstance(XrInstance) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyInstance was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetInstanceProperties(XrInstance, XrInstanceProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetInstanceProperties was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL PollEvent(XrInstance, XrEventDataBuffer*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPollEvent was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ResultToString(XrInstance, XrResult, char[XR_MAX_RESULT_STRING_SIZE]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrResultToString was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL StructureTypeToString(XrInstance, XrStructureType, char[XR_MAX_STRUCTURE_NAME_SIZE]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrStructureTypeToString was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSystem(XrInstance, const XrSystemGetInfo*, XrSystemId*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSystem was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSystemProperties(XrInstance, XrSystemId, XrSystemProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSystemProperties was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateEnvironmentBlendModes(XrInstance, XrSystemId, XrViewConfigurationType, uint32_t, uint32_t*, XrEnvironmentBlendMode*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateEnvironmentBlendModes was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSession(XrInstance, const XrSessionCreateInfo*, XrSession*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSession was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroySession(XrSession) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySession was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateReferenceSpaces(XrSession, uint32_t, uint32_t*, XrReferenceSpaceType*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateReferenceSpaces was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateReferenceSpace(XrSession, const XrReferenceSpaceCreateInfo*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateReferenceSpace was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetReferenceSpaceBoundsRect(XrSession, XrReferenceSpaceType, XrExtent2Df*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetReferenceSpaceBoundsRect was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateActionSpace(XrSession, const XrActionSpaceCreateInfo*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateActionSpace was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL LocateSpace(XrSpace, XrSpace, XrTime, XrSpaceLocation*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLocateSpace was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroySpace(XrSpace) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySpace was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateViewConfigurations(XrInstance, XrSystemId, uint32_t, uint32_t*, XrViewConfigurationType*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateViewConfigurations was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetViewConfigurationProperties(XrInstance, XrSystemId, XrViewConfigurationType, XrViewConfigurationProperties*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetViewConfigurationProperties was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateViewConfigurationViews(XrInstance, XrSystemId, XrViewConfigurationType, uint32_t, uint32_t*, XrViewConfigurationView*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateViewConfigurationViews was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateSwapchainFormats(XrSession, uint32_t, uint32_t*, int64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateSwapchainFormats was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSwapchain(XrSession, const XrSwapchainCreateInfo*, XrSwapchain*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSwapchain was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroySwapchain(XrSwapchain) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySwapchain was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateSwapchainImages(XrSwapchain, uint32_t, uint32_t*, XrSwapchainImageBaseHeader*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateSwapchainImages was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL AcquireSwapchainImage(XrSwapchain, const XrSwapchainImageAcquireInfo*, uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrAcquireSwapchainImage was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL WaitSwapchainImage(XrSwapchain, const XrSwapchainImageWaitInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrWaitSwapchainImage was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ReleaseSwapchainImage(XrSwapchain, const XrSwapchainImageReleaseInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrReleaseSwapchainImage was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL BeginSession(XrSession, const XrSessionBeginInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrBeginSession was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EndSession(XrSession) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEndSession was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL RequestExitSession(XrSession) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrRequestExitSession was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL WaitFrame(XrSession, const XrFrameWaitInfo*, XrFrameState*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrWaitFrame was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL BeginFrame(XrSession, const XrFrameBeginInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrBeginFrame was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EndFrame(XrSession, const XrFrameEndInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEndFrame was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL LocateViews(XrSession, const XrViewLocateInfo*, XrViewState*, uint32_t, uint32_t*, XrView*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLocateViews was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL StringToPath(XrInstance, const char*, XrPath*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrStringToPath was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL PathToString(XrInstance, XrPath, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPathToString was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateActionSet(XrInstance, const XrActionSetCreateInfo*, XrActionSet*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateActionSet was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyActionSet(XrActionSet) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyActionSet was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateAction(XrActionSet, const XrActionCreateInfo*, XrAction*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateAction was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyAction(XrAction) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyAction was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SuggestInteractionProfileBindings(XrInstance, const XrInteractionProfileSuggestedBinding*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSuggestInteractionProfileBindings was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL AttachSessionActionSets(XrSession, const XrSessionActionSetsAttachInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrAttachSessionActionSets was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetCurrentInteractionProfile(XrSession, XrPath, XrInteractionProfileState*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetCurrentInteractionProfile was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetActionStateBoolean(XrSession, const XrActionStateGetInfo*, XrActionStateBoolean*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetActionStateBoolean was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetActionStateFloat(XrSession, const XrActionStateGetInfo*, XrActionStateFloat*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetActionStateFloat was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetActionStateVector2f(XrSession, const XrActionStateGetInfo*, XrActionStateVector2f*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetActionStateVector2f was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetActionStatePose(XrSession, const XrActionStateGetInfo*, XrActionStatePose*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetActionStatePose was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SyncActions(XrSession, const XrActionsSyncInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSyncActions was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateBoundSourcesForAction(XrSession, const XrBoundSourcesForActionEnumerateInfo*, uint32_t, uint32_t*, XrPath*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateBoundSourcesForAction was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetInputSourceLocalizedName(XrSession, const XrInputSourceLocalizedNameGetInfo*, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetInputSourceLocalizedName was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ApplyHapticFeedback(XrSession, const XrHapticActionInfo*, const XrHapticBaseHeader*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrApplyHapticFeedback was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL StopHapticFeedback(XrSession, const XrHapticActionInfo*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrStopHapticFeedback was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetAndroidApplicationThreadKHR(XrSession, XrAndroidThreadTypeKHR, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetAndroidApplicationThreadKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSwapchainAndroidSurfaceKHR(XrSession, const XrSwapchainCreateInfo*, XrSwapchain*, jobject*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSwapchainAndroidSurfaceKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetOpenGLGraphicsRequirementsKHR(XrInstance, XrSystemId, XrGraphicsRequirementsOpenGLKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetOpenGLGraphicsRequirementsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetOpenGLESGraphicsRequirementsKHR(XrInstance, XrSystemId, XrGraphicsRequirementsOpenGLESKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetOpenGLESGraphicsRequirementsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVulkanInstanceExtensionsKHR(XrInstance, XrSystemId, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanInstanceExtensionsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVulkanDeviceExtensionsKHR(XrInstance, XrSystemId, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanDeviceExtensionsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVulkanGraphicsDeviceKHR(XrInstance, XrSystemId, VkInstance, VkPhysicalDevice*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanGraphicsDeviceKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVulkanGraphicsRequirementsKHR(XrInstance, XrSystemId, XrGraphicsRequirementsVulkanKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanGraphicsRequirementsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetD3D11GraphicsRequirementsKHR(XrInstance, XrSystemId, XrGraphicsRequirementsD3D11KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetD3D11GraphicsRequirementsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetD3D12GraphicsRequirementsKHR(XrInstance, XrSystemId, XrGraphicsRequirementsD3D12KHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetD3D12GraphicsRequirementsKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVisibilityMaskKHR(XrSession, XrViewConfigurationType, uint32_t, XrVisibilityMaskTypeKHR, XrVisibilityMaskKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVisibilityMaskKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ConvertWin32PerformanceCounterToTimeKHR(XrInstance, const LARGE_INTEGER*, XrTime*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrConvertWin32PerformanceCounterToTimeKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ConvertTimeToWin32PerformanceCounterKHR(XrInstance, XrTime, LARGE_INTEGER*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrConvertTimeToWin32PerformanceCounterKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ConvertTimespecTimeToTimeKHR(XrInstance, const struct timespec*, XrTime*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrConvertTimespecTimeToTimeKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ConvertTimeToTimespecTimeKHR(XrInstance, XrTime, struct timespec*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrConvertTimeToTimespecTimeKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateVulkanInstanceKHR(XrInstance, const XrVulkanInstanceCreateInfoKHR*, VkInstance*, VkResult*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateVulkanInstanceKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateVulkanDeviceKHR(XrInstance, const XrVulkanDeviceCreateInfoKHR*, VkDevice*, VkResult*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateVulkanDeviceKHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVulkanGraphicsDevice2KHR(XrInstance, const XrVulkanGraphicsDeviceGetInfoKHR*, VkPhysicalDevice*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanGraphicsDevice2KHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVulkanGraphicsRequirements2KHR(XrInstance, XrSystemId, XrGraphicsRequirementsVulkanKHR*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVulkanGraphicsRequirements2KHR was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL PerfSettingsSetPerformanceLevelEXT(XrSession, XrPerfSettingsDomainEXT, XrPerfSettingsLevelEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPerfSettingsSetPerformanceLevelEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ThermalGetTemperatureTrendEXT(XrSession, XrPerfSettingsDomainEXT, XrPerfSettingsNotificationLevelEXT*, float*, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrThermalGetTemperatureTrendEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetDebugUtilsObjectNameEXT(XrInstance, const XrDebugUtilsObjectNameInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetDebugUtilsObjectNameEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateDebugUtilsMessengerEXT(XrInstance, const XrDebugUtilsMessengerCreateInfoEXT*, XrDebugUtilsMessengerEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateDebugUtilsMessengerEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyDebugUtilsMessengerEXT(XrDebugUtilsMessengerEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyDebugUtilsMessengerEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult                                    XRAPI_CALL SubmitDebugUtilsMessageEXT(XrInstance, XrDebugUtilsMessageSeverityFlagsEXT, XrDebugUtilsMessageTypeFlagsEXT, const XrDebugUtilsMessengerCallbackDataEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSubmitDebugUtilsMessageEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SessionBeginDebugUtilsLabelRegionEXT(XrSession, const XrDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSessionBeginDebugUtilsLabelRegionEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SessionEndDebugUtilsLabelRegionEXT(XrSession) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSessionEndDebugUtilsLabelRegionEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SessionInsertDebugUtilsLabelEXT(XrSession, const XrDebugUtilsLabelEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSessionInsertDebugUtilsLabelEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorMSFT(XrSession, const XrSpatialAnchorCreateInfoMSFT*, XrSpatialAnchorMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorSpaceMSFT(XrSession, const XrSpatialAnchorSpaceCreateInfoMSFT*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorSpaceMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroySpatialAnchorMSFT(XrSpatialAnchorMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySpatialAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetInputDeviceActiveEXT(XrSession, XrPath, XrPath, XrBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetInputDeviceActiveEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetInputDeviceStateBoolEXT(XrSession, XrPath, XrPath, XrBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetInputDeviceStateBoolEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetInputDeviceStateFloatEXT(XrSession, XrPath, XrPath, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetInputDeviceStateFloatEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetInputDeviceStateVector2fEXT(XrSession, XrPath, XrPath, XrVector2f) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetInputDeviceStateVector2fEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetInputDeviceLocationEXT(XrSession, XrPath, XrPath, XrSpace, XrPosef) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetInputDeviceLocationEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialGraphNodeSpaceMSFT(XrSession, const XrSpatialGraphNodeSpaceCreateInfoMSFT*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialGraphNodeSpaceMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL TryCreateSpatialGraphStaticNodeBindingMSFT(XrSession, const XrSpatialGraphStaticNodeBindingCreateInfoMSFT*, XrSpatialGraphNodeBindingMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTryCreateSpatialGraphStaticNodeBindingMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroySpatialGraphNodeBindingMSFT(XrSpatialGraphNodeBindingMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySpatialGraphNodeBindingMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpatialGraphNodeBindingPropertiesMSFT(XrSpatialGraphNodeBindingMSFT, const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT*, XrSpatialGraphNodeBindingPropertiesMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpatialGraphNodeBindingPropertiesMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateHandTrackerEXT(XrSession, const XrHandTrackerCreateInfoEXT*, XrHandTrackerEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateHandTrackerEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyHandTrackerEXT(XrHandTrackerEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyHandTrackerEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL LocateHandJointsEXT(XrHandTrackerEXT, const XrHandJointsLocateInfoEXT*, XrHandJointLocationsEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLocateHandJointsEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateHandMeshSpaceMSFT(XrHandTrackerEXT, const XrHandMeshSpaceCreateInfoMSFT*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateHandMeshSpaceMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL UpdateHandMeshMSFT(XrHandTrackerEXT, const XrHandMeshUpdateInfoMSFT*, XrHandMeshMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrUpdateHandMeshMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetControllerModelKeyMSFT(XrSession, XrPath, XrControllerModelKeyStateMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetControllerModelKeyMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL LoadControllerModelMSFT(XrSession, XrControllerModelKeyMSFT, uint32_t, uint32_t*, uint8_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLoadControllerModelMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetControllerModelPropertiesMSFT(XrSession, XrControllerModelKeyMSFT, XrControllerModelPropertiesMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetControllerModelPropertiesMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetControllerModelStateMSFT(XrSession, XrControllerModelKeyMSFT, XrControllerModelStateMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetControllerModelStateMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorFromPerceptionAnchorMSFT(XrSession, IUnknown*, XrSpatialAnchorMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorFromPerceptionAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL TryGetPerceptionAnchorFromSpatialAnchorMSFT(XrSession, XrSpatialAnchorMSFT, IUnknown**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTryGetPerceptionAnchorFromSpatialAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateReprojectionModesMSFT(XrInstance, XrSystemId, XrViewConfigurationType, uint32_t, uint32_t*, XrReprojectionModeMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateReprojectionModesMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL UpdateSwapchainFB(XrSwapchain, const XrSwapchainStateBaseHeaderFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrUpdateSwapchainFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSwapchainStateFB(XrSwapchain, XrSwapchainStateBaseHeaderFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSwapchainStateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateBodyTrackerFB(XrSession, const XrBodyTrackerCreateInfoFB*, XrBodyTrackerFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateBodyTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyBodyTrackerFB(XrBodyTrackerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyBodyTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL LocateBodyJointsFB(XrBodyTrackerFB, const XrBodyJointsLocateInfoFB*, XrBodyJointLocationsFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLocateBodyJointsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetBodySkeletonFB(XrBodyTrackerFB, XrBodySkeletonFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetBodySkeletonFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateSceneComputeFeaturesMSFT(XrInstance, XrSystemId, uint32_t, uint32_t*, XrSceneComputeFeatureMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateSceneComputeFeaturesMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSceneObserverMSFT(XrSession, const XrSceneObserverCreateInfoMSFT*, XrSceneObserverMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSceneObserverMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroySceneObserverMSFT(XrSceneObserverMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySceneObserverMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSceneMSFT(XrSceneObserverMSFT, const XrSceneCreateInfoMSFT*, XrSceneMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSceneMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroySceneMSFT(XrSceneMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySceneMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ComputeNewSceneMSFT(XrSceneObserverMSFT, const XrNewSceneComputeInfoMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrComputeNewSceneMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSceneComputeStateMSFT(XrSceneObserverMSFT, XrSceneComputeStateMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSceneComputeStateMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSceneComponentsMSFT(XrSceneMSFT, const XrSceneComponentsGetInfoMSFT*, XrSceneComponentsMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSceneComponentsMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL LocateSceneComponentsMSFT(XrSceneMSFT, const XrSceneComponentsLocateInfoMSFT*, XrSceneComponentLocationsMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLocateSceneComponentsMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSceneMeshBuffersMSFT(XrSceneMSFT, const XrSceneMeshBuffersGetInfoMSFT*, XrSceneMeshBuffersMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSceneMeshBuffersMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DeserializeSceneMSFT(XrSceneObserverMSFT, const XrSceneDeserializeInfoMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDeserializeSceneMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSerializedSceneFragmentDataMSFT(XrSceneMSFT, const XrSerializedSceneFragmentDataGetInfoMSFT*, uint32_t, uint32_t*, uint8_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSerializedSceneFragmentDataMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateDisplayRefreshRatesFB(XrSession, uint32_t, uint32_t*, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateDisplayRefreshRatesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetDisplayRefreshRateFB(XrSession, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetDisplayRefreshRateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL RequestDisplayRefreshRateFB(XrSession, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrRequestDisplayRefreshRateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateViveTrackerPathsHTCX(XrInstance, uint32_t, uint32_t*, XrViveTrackerPathsHTCX*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateViveTrackerPathsHTCX was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateFacialTrackerHTC(XrSession, const XrFacialTrackerCreateInfoHTC*, XrFacialTrackerHTC*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateFacialTrackerHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyFacialTrackerHTC(XrFacialTrackerHTC) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyFacialTrackerHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetFacialExpressionsHTC(XrFacialTrackerHTC, XrFacialExpressionsHTC*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetFacialExpressionsHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateColorSpacesFB(XrSession, uint32_t, uint32_t*, XrColorSpaceFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateColorSpacesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetColorSpaceFB(XrSession, const XrColorSpaceFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetColorSpaceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetHandMeshFB(XrHandTrackerEXT, XrHandTrackingMeshFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetHandMeshFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorFB(XrSession, const XrSpatialAnchorCreateInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpaceUuidFB(XrSpace, XrUuidEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceUuidFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateSpaceSupportedComponentsFB(XrSpace, uint32_t, uint32_t*, XrSpaceComponentTypeFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateSpaceSupportedComponentsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetSpaceComponentStatusFB(XrSpace, const XrSpaceComponentStatusSetInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetSpaceComponentStatusFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpaceComponentStatusFB(XrSpace, XrSpaceComponentTypeFB, XrSpaceComponentStatusFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceComponentStatusFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateFoveationProfileFB(XrSession, const XrFoveationProfileCreateInfoFB*, XrFoveationProfileFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateFoveationProfileFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyFoveationProfileFB(XrFoveationProfileFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyFoveationProfileFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL QuerySystemTrackedKeyboardFB(XrSession, const XrKeyboardTrackingQueryFB*, XrKeyboardTrackingDescriptionFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrQuerySystemTrackedKeyboardFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateKeyboardSpaceFB(XrSession, const XrKeyboardSpaceCreateInfoFB*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateKeyboardSpaceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateTriangleMeshFB(XrSession, const XrTriangleMeshCreateInfoFB*, XrTriangleMeshFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateTriangleMeshFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyTriangleMeshFB(XrTriangleMeshFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyTriangleMeshFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshGetVertexBufferFB(XrTriangleMeshFB, XrVector3f**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshGetVertexBufferFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshGetIndexBufferFB(XrTriangleMeshFB, uint32_t**) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshGetIndexBufferFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshBeginUpdateFB(XrTriangleMeshFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshBeginUpdateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshEndUpdateFB(XrTriangleMeshFB, uint32_t, uint32_t) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshEndUpdateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshBeginVertexBufferUpdateFB(XrTriangleMeshFB, uint32_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshBeginVertexBufferUpdateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshEndVertexBufferUpdateFB(XrTriangleMeshFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrTriangleMeshEndVertexBufferUpdateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreatePassthroughFB(XrSession, const XrPassthroughCreateInfoFB*, XrPassthroughFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreatePassthroughFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyPassthroughFB(XrPassthroughFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyPassthroughFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL PassthroughStartFB(XrPassthroughFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughStartFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL PassthroughPauseFB(XrPassthroughFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughPauseFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreatePassthroughLayerFB(XrSession, const XrPassthroughLayerCreateInfoFB*, XrPassthroughLayerFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreatePassthroughLayerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyPassthroughLayerFB(XrPassthroughLayerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyPassthroughLayerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL PassthroughLayerPauseFB(XrPassthroughLayerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughLayerPauseFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL PassthroughLayerResumeFB(XrPassthroughLayerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughLayerResumeFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL PassthroughLayerSetStyleFB(XrPassthroughLayerFB, const XrPassthroughStyleFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughLayerSetStyleFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateGeometryInstanceFB(XrSession, const XrGeometryInstanceCreateInfoFB*, XrGeometryInstanceFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateGeometryInstanceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyGeometryInstanceFB(XrGeometryInstanceFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyGeometryInstanceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GeometryInstanceSetTransformFB(XrGeometryInstanceFB, const XrGeometryInstanceTransformFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGeometryInstanceSetTransformFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateRenderModelPathsFB(XrSession, uint32_t, uint32_t*, XrRenderModelPathInfoFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateRenderModelPathsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetRenderModelPropertiesFB(XrSession, XrPath, XrRenderModelPropertiesFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetRenderModelPropertiesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL LoadRenderModelFB(XrSession, const XrRenderModelLoadInfoFB*, XrRenderModelBufferFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrLoadRenderModelFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetEnvironmentDepthEstimationVARJO(XrSession, XrBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetEnvironmentDepthEstimationVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult  XRAPI_CALL SetMarkerTrackingVARJO(XrSession, XrBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetMarkerTrackingVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetMarkerTrackingTimeoutVARJO(XrSession, uint64_t, XrDuration) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetMarkerTrackingTimeoutVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetMarkerTrackingPredictionVARJO(XrSession, uint64_t, XrBool32) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetMarkerTrackingPredictionVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetMarkerSizeVARJO(XrSession, uint64_t, XrExtent2Df*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerSizeVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateMarkerSpaceVARJO(XrSession, const XrMarkerSpaceCreateInfoVARJO*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateMarkerSpaceVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult  XRAPI_CALL SetViewOffsetVARJO(XrSession, float) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetViewOffsetVARJO was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSpaceFromCoordinateFrameUIDML(XrSession, const XrCoordinateSpaceCreateInfoML *, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpaceFromCoordinateFrameUIDML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateMarkerDetectorML(XrSession, const XrMarkerDetectorCreateInfoML*, XrMarkerDetectorML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateMarkerDetectorML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyMarkerDetectorML(XrMarkerDetectorML) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyMarkerDetectorML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SnapshotMarkerDetectorML(XrMarkerDetectorML, XrMarkerDetectorSnapshotInfoML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSnapshotMarkerDetectorML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetMarkerDetectorStateML(XrMarkerDetectorML, XrMarkerDetectorStateML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerDetectorStateML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetMarkersML(XrMarkerDetectorML, uint32_t, uint32_t*, XrMarkerML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkersML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetMarkerReprojectionErrorML(XrMarkerDetectorML, XrMarkerML, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerReprojectionErrorML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetMarkerLengthML(XrMarkerDetectorML, XrMarkerML, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerLengthML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetMarkerNumberML(XrMarkerDetectorML, XrMarkerML, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerNumberML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetMarkerStringML(XrMarkerDetectorML, XrMarkerML, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetMarkerStringML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateMarkerSpaceML(XrSession, const XrMarkerSpaceCreateInfoML*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateMarkerSpaceML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnableLocalizationEventsML(XrSession, const XrLocalizationEnableEventsInfoML *) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnableLocalizationEventsML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL QueryLocalizationMapsML(XrSession, const XrLocalizationMapQueryInfoBaseHeaderML*, uint32_t, uint32_t *, XrLocalizationMapML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrQueryLocalizationMapsML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL RequestMapLocalizationML(XrSession, const XrMapLocalizationRequestInfoML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrRequestMapLocalizationML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ImportLocalizationMapML(XrSession, const XrLocalizationMapImportInfoML*, XrUuidEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrImportLocalizationMapML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateExportedLocalizationMapML(XrSession, const XrUuidEXT*, XrExportedLocalizationMapML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateExportedLocalizationMapML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyExportedLocalizationMapML(XrExportedLocalizationMapML) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyExportedLocalizationMapML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetExportedLocalizationMapDataML(XrExportedLocalizationMapML, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetExportedLocalizationMapDataML was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorStoreConnectionMSFT(XrSession, XrSpatialAnchorStoreConnectionMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorStoreConnectionMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroySpatialAnchorStoreConnectionMSFT(XrSpatialAnchorStoreConnectionMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySpatialAnchorStoreConnectionMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL PersistSpatialAnchorMSFT(XrSpatialAnchorStoreConnectionMSFT, const XrSpatialAnchorPersistenceInfoMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPersistSpatialAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumeratePersistedSpatialAnchorNamesMSFT(XrSpatialAnchorStoreConnectionMSFT, uint32_t, uint32_t*, XrSpatialAnchorPersistenceNameMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumeratePersistedSpatialAnchorNamesMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorFromPersistedNameMSFT(XrSession, const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT*, XrSpatialAnchorMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorFromPersistedNameMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL UnpersistSpatialAnchorMSFT(XrSpatialAnchorStoreConnectionMSFT, const XrSpatialAnchorPersistenceNameMSFT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrUnpersistSpatialAnchorMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ClearSpatialAnchorStoreMSFT(XrSpatialAnchorStoreConnectionMSFT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrClearSpatialAnchorStoreMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSceneMarkerRawDataMSFT(XrSceneMSFT, const XrUuidMSFT*, uint32_t, uint32_t*, uint8_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSceneMarkerRawDataMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSceneMarkerDecodedStringMSFT(XrSceneMSFT, const XrUuidMSFT*, uint32_t, uint32_t*, char*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSceneMarkerDecodedStringMSFT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL QuerySpacesFB(XrSession, const XrSpaceQueryInfoBaseHeaderFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrQuerySpacesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL RetrieveSpaceQueryResultsFB(XrSession, XrAsyncRequestIdFB, XrSpaceQueryResultsFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrRetrieveSpaceQueryResultsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SaveSpaceFB(XrSession, const XrSpaceSaveInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSaveSpaceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EraseSpaceFB(XrSession, const XrSpaceEraseInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEraseSpaceFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetAudioOutputDeviceGuidOculus(XrInstance, wchar_t[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetAudioOutputDeviceGuidOculus was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetAudioInputDeviceGuidOculus(XrInstance, wchar_t[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetAudioInputDeviceGuidOculus was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ShareSpacesFB(XrSession, const XrSpaceShareInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrShareSpacesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpaceBoundingBox2DFB(XrSession, XrSpace, XrRect2Df*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceBoundingBox2DFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpaceBoundingBox3DFB(XrSession, XrSpace, XrRect3DfFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceBoundingBox3DFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpaceSemanticLabelsFB(XrSession, XrSpace, XrSemanticLabelsFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceSemanticLabelsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpaceBoundary2DFB(XrSession, XrSpace, XrBoundary2DFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceBoundary2DFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpaceRoomLayoutFB(XrSession, XrSpace, XrRoomLayoutFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceRoomLayoutFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetDigitalLensControlALMALENCE(XrSession, const XrDigitalLensControlALMALENCE*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetDigitalLensControlALMALENCE was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL RequestSceneCaptureFB(XrSession, const XrSceneCaptureRequestInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrRequestSceneCaptureFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpaceContainerFB(XrSession, XrSpace, XrSpaceContainerFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceContainerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetFoveationEyeTrackedStateMETA(XrSession, XrFoveationEyeTrackedStateMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetFoveationEyeTrackedStateMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateFaceTrackerFB(XrSession, const XrFaceTrackerCreateInfoFB*, XrFaceTrackerFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateFaceTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyFaceTrackerFB(XrFaceTrackerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyFaceTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetFaceExpressionWeightsFB(XrFaceTrackerFB, const XrFaceExpressionInfoFB*, XrFaceExpressionWeightsFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetFaceExpressionWeightsFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateEyeTrackerFB(XrSession, const XrEyeTrackerCreateInfoFB*, XrEyeTrackerFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateEyeTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyEyeTrackerFB(XrEyeTrackerFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyEyeTrackerFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetEyeGazesFB(XrEyeTrackerFB, const XrEyeGazesInfoFB*, XrEyeGazesFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetEyeGazesFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL PassthroughLayerSetKeyboardHandsIntensityFB(XrPassthroughLayerFB, const XrPassthroughKeyboardHandsIntensityFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrPassthroughLayerSetKeyboardHandsIntensityFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetDeviceSampleRateFB(XrSession, const XrHapticActionInfo*, XrDevicePcmSampleRateGetInfoFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetDeviceSampleRateFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetPassthroughPreferencesMETA(XrSession, XrPassthroughPreferencesMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetPassthroughPreferencesMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateVirtualKeyboardMETA(XrSession, const XrVirtualKeyboardCreateInfoMETA*, XrVirtualKeyboardMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateVirtualKeyboardMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyVirtualKeyboardMETA(XrVirtualKeyboardMETA) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyVirtualKeyboardMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateVirtualKeyboardSpaceMETA(XrSession, XrVirtualKeyboardMETA, const XrVirtualKeyboardSpaceCreateInfoMETA*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateVirtualKeyboardSpaceMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SuggestVirtualKeyboardLocationMETA(XrVirtualKeyboardMETA, const XrVirtualKeyboardLocationInfoMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSuggestVirtualKeyboardLocationMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVirtualKeyboardScaleMETA(XrVirtualKeyboardMETA, float*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVirtualKeyboardScaleMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetVirtualKeyboardModelVisibilityMETA(XrVirtualKeyboardMETA, const XrVirtualKeyboardModelVisibilitySetInfoMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetVirtualKeyboardModelVisibilityMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVirtualKeyboardModelAnimationStatesMETA(XrVirtualKeyboardMETA, XrVirtualKeyboardModelAnimationStatesMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVirtualKeyboardModelAnimationStatesMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVirtualKeyboardDirtyTexturesMETA(XrVirtualKeyboardMETA, uint32_t, uint32_t*, uint64_t*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVirtualKeyboardDirtyTexturesMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetVirtualKeyboardTextureDataMETA(XrVirtualKeyboardMETA, uint64_t, XrVirtualKeyboardTextureDataMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetVirtualKeyboardTextureDataMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SendVirtualKeyboardInputMETA(XrVirtualKeyboardMETA, const XrVirtualKeyboardInputInfoMETA*, XrPosef*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSendVirtualKeyboardInputMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ChangeVirtualKeyboardTextContextMETA(XrVirtualKeyboardMETA, const XrVirtualKeyboardTextContextChangeInfoMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrChangeVirtualKeyboardTextContextMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumerateExternalCamerasOCULUS(XrSession, uint32_t, uint32_t*, XrExternalCameraOCULUS*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumerateExternalCamerasOCULUS was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnumeratePerformanceMetricsCounterPathsMETA(XrInstance, uint32_t, uint32_t*, XrPath*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnumeratePerformanceMetricsCounterPathsMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetPerformanceMetricsStateMETA(XrSession, const XrPerformanceMetricsStateMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetPerformanceMetricsStateMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetPerformanceMetricsStateMETA(XrSession, XrPerformanceMetricsStateMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetPerformanceMetricsStateMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL QueryPerformanceMetricsCounterMETA(XrSession, XrPath, XrPerformanceMetricsCounterMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrQueryPerformanceMetricsCounterMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SaveSpaceListFB(XrSession, const XrSpaceListSaveInfoFB*, XrAsyncRequestIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSaveSpaceListFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSpaceUserFB(XrSession, const XrSpaceUserCreateInfoFB*, XrSpaceUserFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpaceUserFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpaceUserIdFB(XrSpaceUserFB, XrSpaceUserIdFB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceUserIdFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroySpaceUserFB(XrSpaceUserFB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroySpaceUserFB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetRecommendedLayerResolutionMETA(XrSession, const XrRecommendedLayerResolutionGetInfoMETA*, XrRecommendedLayerResolutionMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetRecommendedLayerResolutionMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreatePassthroughColorLutMETA(XrPassthroughFB, const XrPassthroughColorLutCreateInfoMETA*, XrPassthroughColorLutMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreatePassthroughColorLutMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyPassthroughColorLutMETA(XrPassthroughColorLutMETA) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyPassthroughColorLutMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL UpdatePassthroughColorLutMETA(XrPassthroughColorLutMETA, const XrPassthroughColorLutUpdateInfoMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrUpdatePassthroughColorLutMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpaceTriangleMeshMETA(XrSpace, const XrSpaceTriangleMeshGetInfoMETA*, XrSpaceTriangleMeshMETA*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpaceTriangleMeshMETA was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateFaceTracker2FB(XrSession, const XrFaceTrackerCreateInfo2FB*, XrFaceTracker2FB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateFaceTracker2FB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyFaceTracker2FB(XrFaceTracker2FB) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyFaceTracker2FB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetFaceExpressionWeights2FB(XrFaceTracker2FB, const XrFaceExpressionInfo2FB*, XrFaceExpressionWeights2FB*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetFaceExpressionWeights2FB was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL SetTrackingOptimizationSettingsHintQCOM(XrSession, XrTrackingOptimizationSettingsDomainQCOM, XrTrackingOptimizationSettingsHintQCOM) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrSetTrackingOptimizationSettingsHintQCOM was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreatePassthroughHTC(XrSession, const XrPassthroughCreateInfoHTC*, XrPassthroughHTC*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreatePassthroughHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyPassthroughHTC(XrPassthroughHTC) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyPassthroughHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ApplyFoveationHTC(XrSession, const XrFoveationApplyInfoHTC*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrApplyFoveationHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorHTC(XrSession, const XrSpatialAnchorCreateInfoHTC*, XrSpace*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreateSpatialAnchorHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetSpatialAnchorNameHTC(XrSpace, XrSpatialAnchorNameHTC*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetSpatialAnchorNameHTC was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL ApplyForceFeedbackCurlMNDX(XrHandTrackerEXT, const XrForceFeedbackCurlApplyLocationsMNDX*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrApplyForceFeedbackCurlMNDX was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL CreatePlaneDetectorEXT(XrSession, const XrPlaneDetectorCreateInfoEXT*, XrPlaneDetectorEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrCreatePlaneDetectorEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL DestroyPlaneDetectorEXT(XrPlaneDetectorEXT) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrDestroyPlaneDetectorEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL BeginPlaneDetectionEXT(XrPlaneDetectorEXT, const XrPlaneDetectorBeginInfoEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrBeginPlaneDetectionEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetPlaneDetectionStateEXT(XrPlaneDetectorEXT, XrPlaneDetectionStateEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetPlaneDetectionStateEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetPlaneDetectionsEXT(XrPlaneDetectorEXT, const XrPlaneDetectorGetInfoEXT*, XrPlaneDetectorLocationsEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetPlaneDetectionsEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL GetPlanePolygonBufferEXT(XrPlaneDetectorEXT, uint64_t, uint32_t, XrPlaneDetectorPolygonBufferEXT*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrGetPlanePolygonBufferEXT was called, resulting in no-op behavior."); return XR_SUCCESS; }
static XRAPI_ATTR XrResult XRAPI_CALL EnableUserCalibrationEventsML(XrInstance, const XrUserCalibrationEnableEventsInfoML*) { GFXRECON_LOG_WARNING_ONCE("Unsupported function xrEnableUserCalibrationEventsML was called, resulting in no-op behavior."); return XR_SUCCESS; }
// clang-format on
GFXRECON_END_NAMESPACE(noop)

struct LayerTable
{
    PFN_xrCreateInstance CreateInstance{ nullptr };
};

struct InstanceTable
{
    PFN_xrGetInstanceProcAddr GetInstanceProcAddr{ noop::GetInstanceProcAddr };
    PFN_xrDestroyInstance DestroyInstance{ noop::DestroyInstance };
    PFN_xrGetInstanceProperties GetInstanceProperties{ noop::GetInstanceProperties };
    PFN_xrPollEvent PollEvent{ noop::PollEvent };
    PFN_xrResultToString ResultToString{ noop::ResultToString };
    PFN_xrStructureTypeToString StructureTypeToString{ noop::StructureTypeToString };
    PFN_xrGetSystem GetSystem{ noop::GetSystem };
    PFN_xrGetSystemProperties GetSystemProperties{ noop::GetSystemProperties };
    PFN_xrEnumerateEnvironmentBlendModes EnumerateEnvironmentBlendModes{ noop::EnumerateEnvironmentBlendModes };
    PFN_xrCreateSession CreateSession{ noop::CreateSession };
    PFN_xrDestroySession DestroySession{ noop::DestroySession };
    PFN_xrEnumerateReferenceSpaces EnumerateReferenceSpaces{ noop::EnumerateReferenceSpaces };
    PFN_xrCreateReferenceSpace CreateReferenceSpace{ noop::CreateReferenceSpace };
    PFN_xrGetReferenceSpaceBoundsRect GetReferenceSpaceBoundsRect{ noop::GetReferenceSpaceBoundsRect };
    PFN_xrCreateActionSpace CreateActionSpace{ noop::CreateActionSpace };
    PFN_xrLocateSpace LocateSpace{ noop::LocateSpace };
    PFN_xrDestroySpace DestroySpace{ noop::DestroySpace };
    PFN_xrEnumerateViewConfigurations EnumerateViewConfigurations{ noop::EnumerateViewConfigurations };
    PFN_xrGetViewConfigurationProperties GetViewConfigurationProperties{ noop::GetViewConfigurationProperties };
    PFN_xrEnumerateViewConfigurationViews EnumerateViewConfigurationViews{ noop::EnumerateViewConfigurationViews };
    PFN_xrEnumerateSwapchainFormats EnumerateSwapchainFormats{ noop::EnumerateSwapchainFormats };
    PFN_xrCreateSwapchain CreateSwapchain{ noop::CreateSwapchain };
    PFN_xrDestroySwapchain DestroySwapchain{ noop::DestroySwapchain };
    PFN_xrEnumerateSwapchainImages EnumerateSwapchainImages{ noop::EnumerateSwapchainImages };
    PFN_xrAcquireSwapchainImage AcquireSwapchainImage{ noop::AcquireSwapchainImage };
    PFN_xrWaitSwapchainImage WaitSwapchainImage{ noop::WaitSwapchainImage };
    PFN_xrReleaseSwapchainImage ReleaseSwapchainImage{ noop::ReleaseSwapchainImage };
    PFN_xrBeginSession BeginSession{ noop::BeginSession };
    PFN_xrEndSession EndSession{ noop::EndSession };
    PFN_xrRequestExitSession RequestExitSession{ noop::RequestExitSession };
    PFN_xrWaitFrame WaitFrame{ noop::WaitFrame };
    PFN_xrBeginFrame BeginFrame{ noop::BeginFrame };
    PFN_xrEndFrame EndFrame{ noop::EndFrame };
    PFN_xrLocateViews LocateViews{ noop::LocateViews };
    PFN_xrStringToPath StringToPath{ noop::StringToPath };
    PFN_xrPathToString PathToString{ noop::PathToString };
    PFN_xrCreateActionSet CreateActionSet{ noop::CreateActionSet };
    PFN_xrDestroyActionSet DestroyActionSet{ noop::DestroyActionSet };
    PFN_xrCreateAction CreateAction{ noop::CreateAction };
    PFN_xrDestroyAction DestroyAction{ noop::DestroyAction };
    PFN_xrSuggestInteractionProfileBindings SuggestInteractionProfileBindings{ noop::SuggestInteractionProfileBindings };
    PFN_xrAttachSessionActionSets AttachSessionActionSets{ noop::AttachSessionActionSets };
    PFN_xrGetCurrentInteractionProfile GetCurrentInteractionProfile{ noop::GetCurrentInteractionProfile };
    PFN_xrGetActionStateBoolean GetActionStateBoolean{ noop::GetActionStateBoolean };
    PFN_xrGetActionStateFloat GetActionStateFloat{ noop::GetActionStateFloat };
    PFN_xrGetActionStateVector2f GetActionStateVector2f{ noop::GetActionStateVector2f };
    PFN_xrGetActionStatePose GetActionStatePose{ noop::GetActionStatePose };
    PFN_xrSyncActions SyncActions{ noop::SyncActions };
    PFN_xrEnumerateBoundSourcesForAction EnumerateBoundSourcesForAction{ noop::EnumerateBoundSourcesForAction };
    PFN_xrGetInputSourceLocalizedName GetInputSourceLocalizedName{ noop::GetInputSourceLocalizedName };
    PFN_xrApplyHapticFeedback ApplyHapticFeedback{ noop::ApplyHapticFeedback };
    PFN_xrStopHapticFeedback StopHapticFeedback{ noop::StopHapticFeedback };
    PFN_xrSetAndroidApplicationThreadKHR SetAndroidApplicationThreadKHR{ noop::SetAndroidApplicationThreadKHR };
    PFN_xrCreateSwapchainAndroidSurfaceKHR CreateSwapchainAndroidSurfaceKHR{ noop::CreateSwapchainAndroidSurfaceKHR };
    PFN_xrGetOpenGLGraphicsRequirementsKHR GetOpenGLGraphicsRequirementsKHR{ noop::GetOpenGLGraphicsRequirementsKHR };
    PFN_xrGetOpenGLESGraphicsRequirementsKHR GetOpenGLESGraphicsRequirementsKHR{ noop::GetOpenGLESGraphicsRequirementsKHR };
    PFN_xrGetVulkanInstanceExtensionsKHR GetVulkanInstanceExtensionsKHR{ noop::GetVulkanInstanceExtensionsKHR };
    PFN_xrGetVulkanDeviceExtensionsKHR GetVulkanDeviceExtensionsKHR{ noop::GetVulkanDeviceExtensionsKHR };
    PFN_xrGetVulkanGraphicsDeviceKHR GetVulkanGraphicsDeviceKHR{ noop::GetVulkanGraphicsDeviceKHR };
    PFN_xrGetVulkanGraphicsRequirementsKHR GetVulkanGraphicsRequirementsKHR{ noop::GetVulkanGraphicsRequirementsKHR };
    PFN_xrGetD3D11GraphicsRequirementsKHR GetD3D11GraphicsRequirementsKHR{ noop::GetD3D11GraphicsRequirementsKHR };
    PFN_xrGetD3D12GraphicsRequirementsKHR GetD3D12GraphicsRequirementsKHR{ noop::GetD3D12GraphicsRequirementsKHR };
    PFN_xrGetVisibilityMaskKHR GetVisibilityMaskKHR{ noop::GetVisibilityMaskKHR };
    PFN_xrConvertWin32PerformanceCounterToTimeKHR ConvertWin32PerformanceCounterToTimeKHR{ noop::ConvertWin32PerformanceCounterToTimeKHR };
    PFN_xrConvertTimeToWin32PerformanceCounterKHR ConvertTimeToWin32PerformanceCounterKHR{ noop::ConvertTimeToWin32PerformanceCounterKHR };
    PFN_xrConvertTimespecTimeToTimeKHR ConvertTimespecTimeToTimeKHR{ noop::ConvertTimespecTimeToTimeKHR };
    PFN_xrConvertTimeToTimespecTimeKHR ConvertTimeToTimespecTimeKHR{ noop::ConvertTimeToTimespecTimeKHR };
    PFN_xrCreateVulkanInstanceKHR CreateVulkanInstanceKHR{ noop::CreateVulkanInstanceKHR };
    PFN_xrCreateVulkanDeviceKHR CreateVulkanDeviceKHR{ noop::CreateVulkanDeviceKHR };
    PFN_xrGetVulkanGraphicsDevice2KHR GetVulkanGraphicsDevice2KHR{ noop::GetVulkanGraphicsDevice2KHR };
    PFN_xrGetVulkanGraphicsRequirements2KHR GetVulkanGraphicsRequirements2KHR{ noop::GetVulkanGraphicsRequirements2KHR };
    PFN_xrPerfSettingsSetPerformanceLevelEXT PerfSettingsSetPerformanceLevelEXT{ noop::PerfSettingsSetPerformanceLevelEXT };
    PFN_xrThermalGetTemperatureTrendEXT ThermalGetTemperatureTrendEXT{ noop::ThermalGetTemperatureTrendEXT };
    PFN_xrSetDebugUtilsObjectNameEXT SetDebugUtilsObjectNameEXT{ noop::SetDebugUtilsObjectNameEXT };
    PFN_xrCreateDebugUtilsMessengerEXT CreateDebugUtilsMessengerEXT{ noop::CreateDebugUtilsMessengerEXT };
    PFN_xrDestroyDebugUtilsMessengerEXT DestroyDebugUtilsMessengerEXT{ noop::DestroyDebugUtilsMessengerEXT };
    PFN_xrSubmitDebugUtilsMessageEXT SubmitDebugUtilsMessageEXT{ noop::SubmitDebugUtilsMessageEXT };
    PFN_xrSessionBeginDebugUtilsLabelRegionEXT SessionBeginDebugUtilsLabelRegionEXT{ noop::SessionBeginDebugUtilsLabelRegionEXT };
    PFN_xrSessionEndDebugUtilsLabelRegionEXT SessionEndDebugUtilsLabelRegionEXT{ noop::SessionEndDebugUtilsLabelRegionEXT };
    PFN_xrSessionInsertDebugUtilsLabelEXT SessionInsertDebugUtilsLabelEXT{ noop::SessionInsertDebugUtilsLabelEXT };
    PFN_xrCreateSpatialAnchorMSFT CreateSpatialAnchorMSFT{ noop::CreateSpatialAnchorMSFT };
    PFN_xrCreateSpatialAnchorSpaceMSFT CreateSpatialAnchorSpaceMSFT{ noop::CreateSpatialAnchorSpaceMSFT };
    PFN_xrDestroySpatialAnchorMSFT DestroySpatialAnchorMSFT{ noop::DestroySpatialAnchorMSFT };
    PFN_xrSetInputDeviceActiveEXT SetInputDeviceActiveEXT{ noop::SetInputDeviceActiveEXT };
    PFN_xrSetInputDeviceStateBoolEXT SetInputDeviceStateBoolEXT{ noop::SetInputDeviceStateBoolEXT };
    PFN_xrSetInputDeviceStateFloatEXT SetInputDeviceStateFloatEXT{ noop::SetInputDeviceStateFloatEXT };
    PFN_xrSetInputDeviceStateVector2fEXT SetInputDeviceStateVector2fEXT{ noop::SetInputDeviceStateVector2fEXT };
    PFN_xrSetInputDeviceLocationEXT SetInputDeviceLocationEXT{ noop::SetInputDeviceLocationEXT };
    PFN_xrCreateSpatialGraphNodeSpaceMSFT CreateSpatialGraphNodeSpaceMSFT{ noop::CreateSpatialGraphNodeSpaceMSFT };
    PFN_xrTryCreateSpatialGraphStaticNodeBindingMSFT TryCreateSpatialGraphStaticNodeBindingMSFT{ noop::TryCreateSpatialGraphStaticNodeBindingMSFT };
    PFN_xrDestroySpatialGraphNodeBindingMSFT DestroySpatialGraphNodeBindingMSFT{ noop::DestroySpatialGraphNodeBindingMSFT };
    PFN_xrGetSpatialGraphNodeBindingPropertiesMSFT GetSpatialGraphNodeBindingPropertiesMSFT{ noop::GetSpatialGraphNodeBindingPropertiesMSFT };
    PFN_xrCreateHandTrackerEXT CreateHandTrackerEXT{ noop::CreateHandTrackerEXT };
    PFN_xrDestroyHandTrackerEXT DestroyHandTrackerEXT{ noop::DestroyHandTrackerEXT };
    PFN_xrLocateHandJointsEXT LocateHandJointsEXT{ noop::LocateHandJointsEXT };
    PFN_xrCreateHandMeshSpaceMSFT CreateHandMeshSpaceMSFT{ noop::CreateHandMeshSpaceMSFT };
    PFN_xrUpdateHandMeshMSFT UpdateHandMeshMSFT{ noop::UpdateHandMeshMSFT };
    PFN_xrGetControllerModelKeyMSFT GetControllerModelKeyMSFT{ noop::GetControllerModelKeyMSFT };
    PFN_xrLoadControllerModelMSFT LoadControllerModelMSFT{ noop::LoadControllerModelMSFT };
    PFN_xrGetControllerModelPropertiesMSFT GetControllerModelPropertiesMSFT{ noop::GetControllerModelPropertiesMSFT };
    PFN_xrGetControllerModelStateMSFT GetControllerModelStateMSFT{ noop::GetControllerModelStateMSFT };
    PFN_xrCreateSpatialAnchorFromPerceptionAnchorMSFT CreateSpatialAnchorFromPerceptionAnchorMSFT{ noop::CreateSpatialAnchorFromPerceptionAnchorMSFT };
    PFN_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT TryGetPerceptionAnchorFromSpatialAnchorMSFT{ noop::TryGetPerceptionAnchorFromSpatialAnchorMSFT };
    PFN_xrEnumerateReprojectionModesMSFT EnumerateReprojectionModesMSFT{ noop::EnumerateReprojectionModesMSFT };
    PFN_xrUpdateSwapchainFB UpdateSwapchainFB{ noop::UpdateSwapchainFB };
    PFN_xrGetSwapchainStateFB GetSwapchainStateFB{ noop::GetSwapchainStateFB };
    PFN_xrCreateBodyTrackerFB CreateBodyTrackerFB{ noop::CreateBodyTrackerFB };
    PFN_xrDestroyBodyTrackerFB DestroyBodyTrackerFB{ noop::DestroyBodyTrackerFB };
    PFN_xrLocateBodyJointsFB LocateBodyJointsFB{ noop::LocateBodyJointsFB };
    PFN_xrGetBodySkeletonFB GetBodySkeletonFB{ noop::GetBodySkeletonFB };
    PFN_xrEnumerateSceneComputeFeaturesMSFT EnumerateSceneComputeFeaturesMSFT{ noop::EnumerateSceneComputeFeaturesMSFT };
    PFN_xrCreateSceneObserverMSFT CreateSceneObserverMSFT{ noop::CreateSceneObserverMSFT };
    PFN_xrDestroySceneObserverMSFT DestroySceneObserverMSFT{ noop::DestroySceneObserverMSFT };
    PFN_xrCreateSceneMSFT CreateSceneMSFT{ noop::CreateSceneMSFT };
    PFN_xrDestroySceneMSFT DestroySceneMSFT{ noop::DestroySceneMSFT };
    PFN_xrComputeNewSceneMSFT ComputeNewSceneMSFT{ noop::ComputeNewSceneMSFT };
    PFN_xrGetSceneComputeStateMSFT GetSceneComputeStateMSFT{ noop::GetSceneComputeStateMSFT };
    PFN_xrGetSceneComponentsMSFT GetSceneComponentsMSFT{ noop::GetSceneComponentsMSFT };
    PFN_xrLocateSceneComponentsMSFT LocateSceneComponentsMSFT{ noop::LocateSceneComponentsMSFT };
    PFN_xrGetSceneMeshBuffersMSFT GetSceneMeshBuffersMSFT{ noop::GetSceneMeshBuffersMSFT };
    PFN_xrDeserializeSceneMSFT DeserializeSceneMSFT{ noop::DeserializeSceneMSFT };
    PFN_xrGetSerializedSceneFragmentDataMSFT GetSerializedSceneFragmentDataMSFT{ noop::GetSerializedSceneFragmentDataMSFT };
    PFN_xrEnumerateDisplayRefreshRatesFB EnumerateDisplayRefreshRatesFB{ noop::EnumerateDisplayRefreshRatesFB };
    PFN_xrGetDisplayRefreshRateFB GetDisplayRefreshRateFB{ noop::GetDisplayRefreshRateFB };
    PFN_xrRequestDisplayRefreshRateFB RequestDisplayRefreshRateFB{ noop::RequestDisplayRefreshRateFB };
    PFN_xrEnumerateViveTrackerPathsHTCX EnumerateViveTrackerPathsHTCX{ noop::EnumerateViveTrackerPathsHTCX };
    PFN_xrCreateFacialTrackerHTC CreateFacialTrackerHTC{ noop::CreateFacialTrackerHTC };
    PFN_xrDestroyFacialTrackerHTC DestroyFacialTrackerHTC{ noop::DestroyFacialTrackerHTC };
    PFN_xrGetFacialExpressionsHTC GetFacialExpressionsHTC{ noop::GetFacialExpressionsHTC };
    PFN_xrEnumerateColorSpacesFB EnumerateColorSpacesFB{ noop::EnumerateColorSpacesFB };
    PFN_xrSetColorSpaceFB SetColorSpaceFB{ noop::SetColorSpaceFB };
    PFN_xrGetHandMeshFB GetHandMeshFB{ noop::GetHandMeshFB };
    PFN_xrCreateSpatialAnchorFB CreateSpatialAnchorFB{ noop::CreateSpatialAnchorFB };
    PFN_xrGetSpaceUuidFB GetSpaceUuidFB{ noop::GetSpaceUuidFB };
    PFN_xrEnumerateSpaceSupportedComponentsFB EnumerateSpaceSupportedComponentsFB{ noop::EnumerateSpaceSupportedComponentsFB };
    PFN_xrSetSpaceComponentStatusFB SetSpaceComponentStatusFB{ noop::SetSpaceComponentStatusFB };
    PFN_xrGetSpaceComponentStatusFB GetSpaceComponentStatusFB{ noop::GetSpaceComponentStatusFB };
    PFN_xrCreateFoveationProfileFB CreateFoveationProfileFB{ noop::CreateFoveationProfileFB };
    PFN_xrDestroyFoveationProfileFB DestroyFoveationProfileFB{ noop::DestroyFoveationProfileFB };
    PFN_xrQuerySystemTrackedKeyboardFB QuerySystemTrackedKeyboardFB{ noop::QuerySystemTrackedKeyboardFB };
    PFN_xrCreateKeyboardSpaceFB CreateKeyboardSpaceFB{ noop::CreateKeyboardSpaceFB };
    PFN_xrCreateTriangleMeshFB CreateTriangleMeshFB{ noop::CreateTriangleMeshFB };
    PFN_xrDestroyTriangleMeshFB DestroyTriangleMeshFB{ noop::DestroyTriangleMeshFB };
    PFN_xrTriangleMeshGetVertexBufferFB TriangleMeshGetVertexBufferFB{ noop::TriangleMeshGetVertexBufferFB };
    PFN_xrTriangleMeshGetIndexBufferFB TriangleMeshGetIndexBufferFB{ noop::TriangleMeshGetIndexBufferFB };
    PFN_xrTriangleMeshBeginUpdateFB TriangleMeshBeginUpdateFB{ noop::TriangleMeshBeginUpdateFB };
    PFN_xrTriangleMeshEndUpdateFB TriangleMeshEndUpdateFB{ noop::TriangleMeshEndUpdateFB };
    PFN_xrTriangleMeshBeginVertexBufferUpdateFB TriangleMeshBeginVertexBufferUpdateFB{ noop::TriangleMeshBeginVertexBufferUpdateFB };
    PFN_xrTriangleMeshEndVertexBufferUpdateFB TriangleMeshEndVertexBufferUpdateFB{ noop::TriangleMeshEndVertexBufferUpdateFB };
    PFN_xrCreatePassthroughFB CreatePassthroughFB{ noop::CreatePassthroughFB };
    PFN_xrDestroyPassthroughFB DestroyPassthroughFB{ noop::DestroyPassthroughFB };
    PFN_xrPassthroughStartFB PassthroughStartFB{ noop::PassthroughStartFB };
    PFN_xrPassthroughPauseFB PassthroughPauseFB{ noop::PassthroughPauseFB };
    PFN_xrCreatePassthroughLayerFB CreatePassthroughLayerFB{ noop::CreatePassthroughLayerFB };
    PFN_xrDestroyPassthroughLayerFB DestroyPassthroughLayerFB{ noop::DestroyPassthroughLayerFB };
    PFN_xrPassthroughLayerPauseFB PassthroughLayerPauseFB{ noop::PassthroughLayerPauseFB };
    PFN_xrPassthroughLayerResumeFB PassthroughLayerResumeFB{ noop::PassthroughLayerResumeFB };
    PFN_xrPassthroughLayerSetStyleFB PassthroughLayerSetStyleFB{ noop::PassthroughLayerSetStyleFB };
    PFN_xrCreateGeometryInstanceFB CreateGeometryInstanceFB{ noop::CreateGeometryInstanceFB };
    PFN_xrDestroyGeometryInstanceFB DestroyGeometryInstanceFB{ noop::DestroyGeometryInstanceFB };
    PFN_xrGeometryInstanceSetTransformFB GeometryInstanceSetTransformFB{ noop::GeometryInstanceSetTransformFB };
    PFN_xrEnumerateRenderModelPathsFB EnumerateRenderModelPathsFB{ noop::EnumerateRenderModelPathsFB };
    PFN_xrGetRenderModelPropertiesFB GetRenderModelPropertiesFB{ noop::GetRenderModelPropertiesFB };
    PFN_xrLoadRenderModelFB LoadRenderModelFB{ noop::LoadRenderModelFB };
    PFN_xrSetEnvironmentDepthEstimationVARJO SetEnvironmentDepthEstimationVARJO{ noop::SetEnvironmentDepthEstimationVARJO };
    PFN_xrSetMarkerTrackingVARJO SetMarkerTrackingVARJO{ noop::SetMarkerTrackingVARJO };
    PFN_xrSetMarkerTrackingTimeoutVARJO SetMarkerTrackingTimeoutVARJO{ noop::SetMarkerTrackingTimeoutVARJO };
    PFN_xrSetMarkerTrackingPredictionVARJO SetMarkerTrackingPredictionVARJO{ noop::SetMarkerTrackingPredictionVARJO };
    PFN_xrGetMarkerSizeVARJO GetMarkerSizeVARJO{ noop::GetMarkerSizeVARJO };
    PFN_xrCreateMarkerSpaceVARJO CreateMarkerSpaceVARJO{ noop::CreateMarkerSpaceVARJO };
    PFN_xrSetViewOffsetVARJO SetViewOffsetVARJO{ noop::SetViewOffsetVARJO };
    PFN_xrCreateSpaceFromCoordinateFrameUIDML CreateSpaceFromCoordinateFrameUIDML{ noop::CreateSpaceFromCoordinateFrameUIDML };
    PFN_xrCreateMarkerDetectorML CreateMarkerDetectorML{ noop::CreateMarkerDetectorML };
    PFN_xrDestroyMarkerDetectorML DestroyMarkerDetectorML{ noop::DestroyMarkerDetectorML };
    PFN_xrSnapshotMarkerDetectorML SnapshotMarkerDetectorML{ noop::SnapshotMarkerDetectorML };
    PFN_xrGetMarkerDetectorStateML GetMarkerDetectorStateML{ noop::GetMarkerDetectorStateML };
    PFN_xrGetMarkersML GetMarkersML{ noop::GetMarkersML };
    PFN_xrGetMarkerReprojectionErrorML GetMarkerReprojectionErrorML{ noop::GetMarkerReprojectionErrorML };
    PFN_xrGetMarkerLengthML GetMarkerLengthML{ noop::GetMarkerLengthML };
    PFN_xrGetMarkerNumberML GetMarkerNumberML{ noop::GetMarkerNumberML };
    PFN_xrGetMarkerStringML GetMarkerStringML{ noop::GetMarkerStringML };
    PFN_xrCreateMarkerSpaceML CreateMarkerSpaceML{ noop::CreateMarkerSpaceML };
    PFN_xrEnableLocalizationEventsML EnableLocalizationEventsML{ noop::EnableLocalizationEventsML };
    PFN_xrQueryLocalizationMapsML QueryLocalizationMapsML{ noop::QueryLocalizationMapsML };
    PFN_xrRequestMapLocalizationML RequestMapLocalizationML{ noop::RequestMapLocalizationML };
    PFN_xrImportLocalizationMapML ImportLocalizationMapML{ noop::ImportLocalizationMapML };
    PFN_xrCreateExportedLocalizationMapML CreateExportedLocalizationMapML{ noop::CreateExportedLocalizationMapML };
    PFN_xrDestroyExportedLocalizationMapML DestroyExportedLocalizationMapML{ noop::DestroyExportedLocalizationMapML };
    PFN_xrGetExportedLocalizationMapDataML GetExportedLocalizationMapDataML{ noop::GetExportedLocalizationMapDataML };
    PFN_xrCreateSpatialAnchorStoreConnectionMSFT CreateSpatialAnchorStoreConnectionMSFT{ noop::CreateSpatialAnchorStoreConnectionMSFT };
    PFN_xrDestroySpatialAnchorStoreConnectionMSFT DestroySpatialAnchorStoreConnectionMSFT{ noop::DestroySpatialAnchorStoreConnectionMSFT };
    PFN_xrPersistSpatialAnchorMSFT PersistSpatialAnchorMSFT{ noop::PersistSpatialAnchorMSFT };
    PFN_xrEnumeratePersistedSpatialAnchorNamesMSFT EnumeratePersistedSpatialAnchorNamesMSFT{ noop::EnumeratePersistedSpatialAnchorNamesMSFT };
    PFN_xrCreateSpatialAnchorFromPersistedNameMSFT CreateSpatialAnchorFromPersistedNameMSFT{ noop::CreateSpatialAnchorFromPersistedNameMSFT };
    PFN_xrUnpersistSpatialAnchorMSFT UnpersistSpatialAnchorMSFT{ noop::UnpersistSpatialAnchorMSFT };
    PFN_xrClearSpatialAnchorStoreMSFT ClearSpatialAnchorStoreMSFT{ noop::ClearSpatialAnchorStoreMSFT };
    PFN_xrGetSceneMarkerRawDataMSFT GetSceneMarkerRawDataMSFT{ noop::GetSceneMarkerRawDataMSFT };
    PFN_xrGetSceneMarkerDecodedStringMSFT GetSceneMarkerDecodedStringMSFT{ noop::GetSceneMarkerDecodedStringMSFT };
    PFN_xrQuerySpacesFB QuerySpacesFB{ noop::QuerySpacesFB };
    PFN_xrRetrieveSpaceQueryResultsFB RetrieveSpaceQueryResultsFB{ noop::RetrieveSpaceQueryResultsFB };
    PFN_xrSaveSpaceFB SaveSpaceFB{ noop::SaveSpaceFB };
    PFN_xrEraseSpaceFB EraseSpaceFB{ noop::EraseSpaceFB };
    PFN_xrGetAudioOutputDeviceGuidOculus GetAudioOutputDeviceGuidOculus{ noop::GetAudioOutputDeviceGuidOculus };
    PFN_xrGetAudioInputDeviceGuidOculus GetAudioInputDeviceGuidOculus{ noop::GetAudioInputDeviceGuidOculus };
    PFN_xrShareSpacesFB ShareSpacesFB{ noop::ShareSpacesFB };
    PFN_xrGetSpaceBoundingBox2DFB GetSpaceBoundingBox2DFB{ noop::GetSpaceBoundingBox2DFB };
    PFN_xrGetSpaceBoundingBox3DFB GetSpaceBoundingBox3DFB{ noop::GetSpaceBoundingBox3DFB };
    PFN_xrGetSpaceSemanticLabelsFB GetSpaceSemanticLabelsFB{ noop::GetSpaceSemanticLabelsFB };
    PFN_xrGetSpaceBoundary2DFB GetSpaceBoundary2DFB{ noop::GetSpaceBoundary2DFB };
    PFN_xrGetSpaceRoomLayoutFB GetSpaceRoomLayoutFB{ noop::GetSpaceRoomLayoutFB };
    PFN_xrSetDigitalLensControlALMALENCE SetDigitalLensControlALMALENCE{ noop::SetDigitalLensControlALMALENCE };
    PFN_xrRequestSceneCaptureFB RequestSceneCaptureFB{ noop::RequestSceneCaptureFB };
    PFN_xrGetSpaceContainerFB GetSpaceContainerFB{ noop::GetSpaceContainerFB };
    PFN_xrGetFoveationEyeTrackedStateMETA GetFoveationEyeTrackedStateMETA{ noop::GetFoveationEyeTrackedStateMETA };
    PFN_xrCreateFaceTrackerFB CreateFaceTrackerFB{ noop::CreateFaceTrackerFB };
    PFN_xrDestroyFaceTrackerFB DestroyFaceTrackerFB{ noop::DestroyFaceTrackerFB };
    PFN_xrGetFaceExpressionWeightsFB GetFaceExpressionWeightsFB{ noop::GetFaceExpressionWeightsFB };
    PFN_xrCreateEyeTrackerFB CreateEyeTrackerFB{ noop::CreateEyeTrackerFB };
    PFN_xrDestroyEyeTrackerFB DestroyEyeTrackerFB{ noop::DestroyEyeTrackerFB };
    PFN_xrGetEyeGazesFB GetEyeGazesFB{ noop::GetEyeGazesFB };
    PFN_xrPassthroughLayerSetKeyboardHandsIntensityFB PassthroughLayerSetKeyboardHandsIntensityFB{ noop::PassthroughLayerSetKeyboardHandsIntensityFB };
    PFN_xrGetDeviceSampleRateFB GetDeviceSampleRateFB{ noop::GetDeviceSampleRateFB };
    PFN_xrGetPassthroughPreferencesMETA GetPassthroughPreferencesMETA{ noop::GetPassthroughPreferencesMETA };
    PFN_xrCreateVirtualKeyboardMETA CreateVirtualKeyboardMETA{ noop::CreateVirtualKeyboardMETA };
    PFN_xrDestroyVirtualKeyboardMETA DestroyVirtualKeyboardMETA{ noop::DestroyVirtualKeyboardMETA };
    PFN_xrCreateVirtualKeyboardSpaceMETA CreateVirtualKeyboardSpaceMETA{ noop::CreateVirtualKeyboardSpaceMETA };
    PFN_xrSuggestVirtualKeyboardLocationMETA SuggestVirtualKeyboardLocationMETA{ noop::SuggestVirtualKeyboardLocationMETA };
    PFN_xrGetVirtualKeyboardScaleMETA GetVirtualKeyboardScaleMETA{ noop::GetVirtualKeyboardScaleMETA };
    PFN_xrSetVirtualKeyboardModelVisibilityMETA SetVirtualKeyboardModelVisibilityMETA{ noop::SetVirtualKeyboardModelVisibilityMETA };
    PFN_xrGetVirtualKeyboardModelAnimationStatesMETA GetVirtualKeyboardModelAnimationStatesMETA{ noop::GetVirtualKeyboardModelAnimationStatesMETA };
    PFN_xrGetVirtualKeyboardDirtyTexturesMETA GetVirtualKeyboardDirtyTexturesMETA{ noop::GetVirtualKeyboardDirtyTexturesMETA };
    PFN_xrGetVirtualKeyboardTextureDataMETA GetVirtualKeyboardTextureDataMETA{ noop::GetVirtualKeyboardTextureDataMETA };
    PFN_xrSendVirtualKeyboardInputMETA SendVirtualKeyboardInputMETA{ noop::SendVirtualKeyboardInputMETA };
    PFN_xrChangeVirtualKeyboardTextContextMETA ChangeVirtualKeyboardTextContextMETA{ noop::ChangeVirtualKeyboardTextContextMETA };
    PFN_xrEnumerateExternalCamerasOCULUS EnumerateExternalCamerasOCULUS{ noop::EnumerateExternalCamerasOCULUS };
    PFN_xrEnumeratePerformanceMetricsCounterPathsMETA EnumeratePerformanceMetricsCounterPathsMETA{ noop::EnumeratePerformanceMetricsCounterPathsMETA };
    PFN_xrSetPerformanceMetricsStateMETA SetPerformanceMetricsStateMETA{ noop::SetPerformanceMetricsStateMETA };
    PFN_xrGetPerformanceMetricsStateMETA GetPerformanceMetricsStateMETA{ noop::GetPerformanceMetricsStateMETA };
    PFN_xrQueryPerformanceMetricsCounterMETA QueryPerformanceMetricsCounterMETA{ noop::QueryPerformanceMetricsCounterMETA };
    PFN_xrSaveSpaceListFB SaveSpaceListFB{ noop::SaveSpaceListFB };
    PFN_xrCreateSpaceUserFB CreateSpaceUserFB{ noop::CreateSpaceUserFB };
    PFN_xrGetSpaceUserIdFB GetSpaceUserIdFB{ noop::GetSpaceUserIdFB };
    PFN_xrDestroySpaceUserFB DestroySpaceUserFB{ noop::DestroySpaceUserFB };
    PFN_xrGetRecommendedLayerResolutionMETA GetRecommendedLayerResolutionMETA{ noop::GetRecommendedLayerResolutionMETA };
    PFN_xrCreatePassthroughColorLutMETA CreatePassthroughColorLutMETA{ noop::CreatePassthroughColorLutMETA };
    PFN_xrDestroyPassthroughColorLutMETA DestroyPassthroughColorLutMETA{ noop::DestroyPassthroughColorLutMETA };
    PFN_xrUpdatePassthroughColorLutMETA UpdatePassthroughColorLutMETA{ noop::UpdatePassthroughColorLutMETA };
    PFN_xrGetSpaceTriangleMeshMETA GetSpaceTriangleMeshMETA{ noop::GetSpaceTriangleMeshMETA };
    PFN_xrCreateFaceTracker2FB CreateFaceTracker2FB{ noop::CreateFaceTracker2FB };
    PFN_xrDestroyFaceTracker2FB DestroyFaceTracker2FB{ noop::DestroyFaceTracker2FB };
    PFN_xrGetFaceExpressionWeights2FB GetFaceExpressionWeights2FB{ noop::GetFaceExpressionWeights2FB };
    PFN_xrSetTrackingOptimizationSettingsHintQCOM SetTrackingOptimizationSettingsHintQCOM{ noop::SetTrackingOptimizationSettingsHintQCOM };
    PFN_xrCreatePassthroughHTC CreatePassthroughHTC{ noop::CreatePassthroughHTC };
    PFN_xrDestroyPassthroughHTC DestroyPassthroughHTC{ noop::DestroyPassthroughHTC };
    PFN_xrApplyFoveationHTC ApplyFoveationHTC{ noop::ApplyFoveationHTC };
    PFN_xrCreateSpatialAnchorHTC CreateSpatialAnchorHTC{ noop::CreateSpatialAnchorHTC };
    PFN_xrGetSpatialAnchorNameHTC GetSpatialAnchorNameHTC{ noop::GetSpatialAnchorNameHTC };
    PFN_xrApplyForceFeedbackCurlMNDX ApplyForceFeedbackCurlMNDX{ noop::ApplyForceFeedbackCurlMNDX };
    PFN_xrCreatePlaneDetectorEXT CreatePlaneDetectorEXT{ noop::CreatePlaneDetectorEXT };
    PFN_xrDestroyPlaneDetectorEXT DestroyPlaneDetectorEXT{ noop::DestroyPlaneDetectorEXT };
    PFN_xrBeginPlaneDetectionEXT BeginPlaneDetectionEXT{ noop::BeginPlaneDetectionEXT };
    PFN_xrGetPlaneDetectionStateEXT GetPlaneDetectionStateEXT{ noop::GetPlaneDetectionStateEXT };
    PFN_xrGetPlaneDetectionsEXT GetPlaneDetectionsEXT{ noop::GetPlaneDetectionsEXT };
    PFN_xrGetPlanePolygonBufferEXT GetPlanePolygonBufferEXT{ noop::GetPlanePolygonBufferEXT };
    PFN_xrEnableUserCalibrationEventsML EnableUserCalibrationEventsML{ noop::EnableUserCalibrationEventsML };
};

template <typename GetProcAddr, typename Handle, typename FuncP>
static void LoadFunction(GetProcAddr gpa, Handle handle, const char* name, FuncP* funcp)
{
    FuncP result = reinterpret_cast<FuncP>(gpa(handle, name));
    if (result != nullptr)
    {
        (*funcp) = result;
    }
}

static void LoadInstanceTable(PFN_xrGetInstanceProcAddr gpa, XrInstance instance, InstanceTable* table)
{
    assert(table != nullptr);

    table->GetInstanceProcAddr = gpa;
    LoadFunction(gpa, instance, "xrDestroyInstance", &table->DestroyInstance);
    LoadFunction(gpa, instance, "xrGetInstanceProperties", &table->GetInstanceProperties);
    LoadFunction(gpa, instance, "xrPollEvent", &table->PollEvent);
    LoadFunction(gpa, instance, "xrResultToString", &table->ResultToString);
    LoadFunction(gpa, instance, "xrStructureTypeToString", &table->StructureTypeToString);
    LoadFunction(gpa, instance, "xrGetSystem", &table->GetSystem);
    LoadFunction(gpa, instance, "xrGetSystemProperties", &table->GetSystemProperties);
    LoadFunction(gpa, instance, "xrEnumerateEnvironmentBlendModes", &table->EnumerateEnvironmentBlendModes);
    LoadFunction(gpa, instance, "xrCreateSession", &table->CreateSession);
    LoadFunction(gpa, instance, "xrDestroySession", &table->DestroySession);
    LoadFunction(gpa, instance, "xrEnumerateReferenceSpaces", &table->EnumerateReferenceSpaces);
    LoadFunction(gpa, instance, "xrCreateReferenceSpace", &table->CreateReferenceSpace);
    LoadFunction(gpa, instance, "xrGetReferenceSpaceBoundsRect", &table->GetReferenceSpaceBoundsRect);
    LoadFunction(gpa, instance, "xrCreateActionSpace", &table->CreateActionSpace);
    LoadFunction(gpa, instance, "xrLocateSpace", &table->LocateSpace);
    LoadFunction(gpa, instance, "xrDestroySpace", &table->DestroySpace);
    LoadFunction(gpa, instance, "xrEnumerateViewConfigurations", &table->EnumerateViewConfigurations);
    LoadFunction(gpa, instance, "xrGetViewConfigurationProperties", &table->GetViewConfigurationProperties);
    LoadFunction(gpa, instance, "xrEnumerateViewConfigurationViews", &table->EnumerateViewConfigurationViews);
    LoadFunction(gpa, instance, "xrEnumerateSwapchainFormats", &table->EnumerateSwapchainFormats);
    LoadFunction(gpa, instance, "xrCreateSwapchain", &table->CreateSwapchain);
    LoadFunction(gpa, instance, "xrDestroySwapchain", &table->DestroySwapchain);
    LoadFunction(gpa, instance, "xrEnumerateSwapchainImages", &table->EnumerateSwapchainImages);
    LoadFunction(gpa, instance, "xrAcquireSwapchainImage", &table->AcquireSwapchainImage);
    LoadFunction(gpa, instance, "xrWaitSwapchainImage", &table->WaitSwapchainImage);
    LoadFunction(gpa, instance, "xrReleaseSwapchainImage", &table->ReleaseSwapchainImage);
    LoadFunction(gpa, instance, "xrBeginSession", &table->BeginSession);
    LoadFunction(gpa, instance, "xrEndSession", &table->EndSession);
    LoadFunction(gpa, instance, "xrRequestExitSession", &table->RequestExitSession);
    LoadFunction(gpa, instance, "xrWaitFrame", &table->WaitFrame);
    LoadFunction(gpa, instance, "xrBeginFrame", &table->BeginFrame);
    LoadFunction(gpa, instance, "xrEndFrame", &table->EndFrame);
    LoadFunction(gpa, instance, "xrLocateViews", &table->LocateViews);
    LoadFunction(gpa, instance, "xrStringToPath", &table->StringToPath);
    LoadFunction(gpa, instance, "xrPathToString", &table->PathToString);
    LoadFunction(gpa, instance, "xrCreateActionSet", &table->CreateActionSet);
    LoadFunction(gpa, instance, "xrDestroyActionSet", &table->DestroyActionSet);
    LoadFunction(gpa, instance, "xrCreateAction", &table->CreateAction);
    LoadFunction(gpa, instance, "xrDestroyAction", &table->DestroyAction);
    LoadFunction(gpa, instance, "xrSuggestInteractionProfileBindings", &table->SuggestInteractionProfileBindings);
    LoadFunction(gpa, instance, "xrAttachSessionActionSets", &table->AttachSessionActionSets);
    LoadFunction(gpa, instance, "xrGetCurrentInteractionProfile", &table->GetCurrentInteractionProfile);
    LoadFunction(gpa, instance, "xrGetActionStateBoolean", &table->GetActionStateBoolean);
    LoadFunction(gpa, instance, "xrGetActionStateFloat", &table->GetActionStateFloat);
    LoadFunction(gpa, instance, "xrGetActionStateVector2f", &table->GetActionStateVector2f);
    LoadFunction(gpa, instance, "xrGetActionStatePose", &table->GetActionStatePose);
    LoadFunction(gpa, instance, "xrSyncActions", &table->SyncActions);
    LoadFunction(gpa, instance, "xrEnumerateBoundSourcesForAction", &table->EnumerateBoundSourcesForAction);
    LoadFunction(gpa, instance, "xrGetInputSourceLocalizedName", &table->GetInputSourceLocalizedName);
    LoadFunction(gpa, instance, "xrApplyHapticFeedback", &table->ApplyHapticFeedback);
    LoadFunction(gpa, instance, "xrStopHapticFeedback", &table->StopHapticFeedback);
    LoadFunction(gpa, instance, "xrSetAndroidApplicationThreadKHR", &table->SetAndroidApplicationThreadKHR);
    LoadFunction(gpa, instance, "xrCreateSwapchainAndroidSurfaceKHR", &table->CreateSwapchainAndroidSurfaceKHR);
    LoadFunction(gpa, instance, "xrGetOpenGLGraphicsRequirementsKHR", &table->GetOpenGLGraphicsRequirementsKHR);
    LoadFunction(gpa, instance, "xrGetOpenGLESGraphicsRequirementsKHR", &table->GetOpenGLESGraphicsRequirementsKHR);
    LoadFunction(gpa, instance, "xrGetVulkanInstanceExtensionsKHR", &table->GetVulkanInstanceExtensionsKHR);
    LoadFunction(gpa, instance, "xrGetVulkanDeviceExtensionsKHR", &table->GetVulkanDeviceExtensionsKHR);
    LoadFunction(gpa, instance, "xrGetVulkanGraphicsDeviceKHR", &table->GetVulkanGraphicsDeviceKHR);
    LoadFunction(gpa, instance, "xrGetVulkanGraphicsRequirementsKHR", &table->GetVulkanGraphicsRequirementsKHR);
    LoadFunction(gpa, instance, "xrGetD3D11GraphicsRequirementsKHR", &table->GetD3D11GraphicsRequirementsKHR);
    LoadFunction(gpa, instance, "xrGetD3D12GraphicsRequirementsKHR", &table->GetD3D12GraphicsRequirementsKHR);
    LoadFunction(gpa, instance, "xrGetVisibilityMaskKHR", &table->GetVisibilityMaskKHR);
    LoadFunction(gpa, instance, "xrConvertWin32PerformanceCounterToTimeKHR", &table->ConvertWin32PerformanceCounterToTimeKHR);
    LoadFunction(gpa, instance, "xrConvertTimeToWin32PerformanceCounterKHR", &table->ConvertTimeToWin32PerformanceCounterKHR);
    LoadFunction(gpa, instance, "xrConvertTimespecTimeToTimeKHR", &table->ConvertTimespecTimeToTimeKHR);
    LoadFunction(gpa, instance, "xrConvertTimeToTimespecTimeKHR", &table->ConvertTimeToTimespecTimeKHR);
    LoadFunction(gpa, instance, "xrCreateVulkanInstanceKHR", &table->CreateVulkanInstanceKHR);
    LoadFunction(gpa, instance, "xrCreateVulkanDeviceKHR", &table->CreateVulkanDeviceKHR);
    LoadFunction(gpa, instance, "xrGetVulkanGraphicsDevice2KHR", &table->GetVulkanGraphicsDevice2KHR);
    LoadFunction(gpa, instance, "xrGetVulkanGraphicsRequirements2KHR", &table->GetVulkanGraphicsRequirements2KHR);
    LoadFunction(gpa, instance, "xrPerfSettingsSetPerformanceLevelEXT", &table->PerfSettingsSetPerformanceLevelEXT);
    LoadFunction(gpa, instance, "xrThermalGetTemperatureTrendEXT", &table->ThermalGetTemperatureTrendEXT);
    LoadFunction(gpa, instance, "xrSetDebugUtilsObjectNameEXT", &table->SetDebugUtilsObjectNameEXT);
    LoadFunction(gpa, instance, "xrCreateDebugUtilsMessengerEXT", &table->CreateDebugUtilsMessengerEXT);
    LoadFunction(gpa, instance, "xrDestroyDebugUtilsMessengerEXT", &table->DestroyDebugUtilsMessengerEXT);
    LoadFunction(gpa, instance, "xrSubmitDebugUtilsMessageEXT", &table->SubmitDebugUtilsMessageEXT);
    LoadFunction(gpa, instance, "xrSessionBeginDebugUtilsLabelRegionEXT", &table->SessionBeginDebugUtilsLabelRegionEXT);
    LoadFunction(gpa, instance, "xrSessionEndDebugUtilsLabelRegionEXT", &table->SessionEndDebugUtilsLabelRegionEXT);
    LoadFunction(gpa, instance, "xrSessionInsertDebugUtilsLabelEXT", &table->SessionInsertDebugUtilsLabelEXT);
    LoadFunction(gpa, instance, "xrCreateSpatialAnchorMSFT", &table->CreateSpatialAnchorMSFT);
    LoadFunction(gpa, instance, "xrCreateSpatialAnchorSpaceMSFT", &table->CreateSpatialAnchorSpaceMSFT);
    LoadFunction(gpa, instance, "xrDestroySpatialAnchorMSFT", &table->DestroySpatialAnchorMSFT);
    LoadFunction(gpa, instance, "xrSetInputDeviceActiveEXT", &table->SetInputDeviceActiveEXT);
    LoadFunction(gpa, instance, "xrSetInputDeviceStateBoolEXT", &table->SetInputDeviceStateBoolEXT);
    LoadFunction(gpa, instance, "xrSetInputDeviceStateFloatEXT", &table->SetInputDeviceStateFloatEXT);
    LoadFunction(gpa, instance, "xrSetInputDeviceStateVector2fEXT", &table->SetInputDeviceStateVector2fEXT);
    LoadFunction(gpa, instance, "xrSetInputDeviceLocationEXT", &table->SetInputDeviceLocationEXT);
    LoadFunction(gpa, instance, "xrCreateSpatialGraphNodeSpaceMSFT", &table->CreateSpatialGraphNodeSpaceMSFT);
    LoadFunction(gpa, instance, "xrTryCreateSpatialGraphStaticNodeBindingMSFT", &table->TryCreateSpatialGraphStaticNodeBindingMSFT);
    LoadFunction(gpa, instance, "xrDestroySpatialGraphNodeBindingMSFT", &table->DestroySpatialGraphNodeBindingMSFT);
    LoadFunction(gpa, instance, "xrGetSpatialGraphNodeBindingPropertiesMSFT", &table->GetSpatialGraphNodeBindingPropertiesMSFT);
    LoadFunction(gpa, instance, "xrCreateHandTrackerEXT", &table->CreateHandTrackerEXT);
    LoadFunction(gpa, instance, "xrDestroyHandTrackerEXT", &table->DestroyHandTrackerEXT);
    LoadFunction(gpa, instance, "xrLocateHandJointsEXT", &table->LocateHandJointsEXT);
    LoadFunction(gpa, instance, "xrCreateHandMeshSpaceMSFT", &table->CreateHandMeshSpaceMSFT);
    LoadFunction(gpa, instance, "xrUpdateHandMeshMSFT", &table->UpdateHandMeshMSFT);
    LoadFunction(gpa, instance, "xrGetControllerModelKeyMSFT", &table->GetControllerModelKeyMSFT);
    LoadFunction(gpa, instance, "xrLoadControllerModelMSFT", &table->LoadControllerModelMSFT);
    LoadFunction(gpa, instance, "xrGetControllerModelPropertiesMSFT", &table->GetControllerModelPropertiesMSFT);
    LoadFunction(gpa, instance, "xrGetControllerModelStateMSFT", &table->GetControllerModelStateMSFT);
    LoadFunction(gpa, instance, "xrCreateSpatialAnchorFromPerceptionAnchorMSFT", &table->CreateSpatialAnchorFromPerceptionAnchorMSFT);
    LoadFunction(gpa, instance, "xrTryGetPerceptionAnchorFromSpatialAnchorMSFT", &table->TryGetPerceptionAnchorFromSpatialAnchorMSFT);
    LoadFunction(gpa, instance, "xrEnumerateReprojectionModesMSFT", &table->EnumerateReprojectionModesMSFT);
    LoadFunction(gpa, instance, "xrUpdateSwapchainFB", &table->UpdateSwapchainFB);
    LoadFunction(gpa, instance, "xrGetSwapchainStateFB", &table->GetSwapchainStateFB);
    LoadFunction(gpa, instance, "xrCreateBodyTrackerFB", &table->CreateBodyTrackerFB);
    LoadFunction(gpa, instance, "xrDestroyBodyTrackerFB", &table->DestroyBodyTrackerFB);
    LoadFunction(gpa, instance, "xrLocateBodyJointsFB", &table->LocateBodyJointsFB);
    LoadFunction(gpa, instance, "xrGetBodySkeletonFB", &table->GetBodySkeletonFB);
    LoadFunction(gpa, instance, "xrEnumerateSceneComputeFeaturesMSFT", &table->EnumerateSceneComputeFeaturesMSFT);
    LoadFunction(gpa, instance, "xrCreateSceneObserverMSFT", &table->CreateSceneObserverMSFT);
    LoadFunction(gpa, instance, "xrDestroySceneObserverMSFT", &table->DestroySceneObserverMSFT);
    LoadFunction(gpa, instance, "xrCreateSceneMSFT", &table->CreateSceneMSFT);
    LoadFunction(gpa, instance, "xrDestroySceneMSFT", &table->DestroySceneMSFT);
    LoadFunction(gpa, instance, "xrComputeNewSceneMSFT", &table->ComputeNewSceneMSFT);
    LoadFunction(gpa, instance, "xrGetSceneComputeStateMSFT", &table->GetSceneComputeStateMSFT);
    LoadFunction(gpa, instance, "xrGetSceneComponentsMSFT", &table->GetSceneComponentsMSFT);
    LoadFunction(gpa, instance, "xrLocateSceneComponentsMSFT", &table->LocateSceneComponentsMSFT);
    LoadFunction(gpa, instance, "xrGetSceneMeshBuffersMSFT", &table->GetSceneMeshBuffersMSFT);
    LoadFunction(gpa, instance, "xrDeserializeSceneMSFT", &table->DeserializeSceneMSFT);
    LoadFunction(gpa, instance, "xrGetSerializedSceneFragmentDataMSFT", &table->GetSerializedSceneFragmentDataMSFT);
    LoadFunction(gpa, instance, "xrEnumerateDisplayRefreshRatesFB", &table->EnumerateDisplayRefreshRatesFB);
    LoadFunction(gpa, instance, "xrGetDisplayRefreshRateFB", &table->GetDisplayRefreshRateFB);
    LoadFunction(gpa, instance, "xrRequestDisplayRefreshRateFB", &table->RequestDisplayRefreshRateFB);
    LoadFunction(gpa, instance, "xrEnumerateViveTrackerPathsHTCX", &table->EnumerateViveTrackerPathsHTCX);
    LoadFunction(gpa, instance, "xrCreateFacialTrackerHTC", &table->CreateFacialTrackerHTC);
    LoadFunction(gpa, instance, "xrDestroyFacialTrackerHTC", &table->DestroyFacialTrackerHTC);
    LoadFunction(gpa, instance, "xrGetFacialExpressionsHTC", &table->GetFacialExpressionsHTC);
    LoadFunction(gpa, instance, "xrEnumerateColorSpacesFB", &table->EnumerateColorSpacesFB);
    LoadFunction(gpa, instance, "xrSetColorSpaceFB", &table->SetColorSpaceFB);
    LoadFunction(gpa, instance, "xrGetHandMeshFB", &table->GetHandMeshFB);
    LoadFunction(gpa, instance, "xrCreateSpatialAnchorFB", &table->CreateSpatialAnchorFB);
    LoadFunction(gpa, instance, "xrGetSpaceUuidFB", &table->GetSpaceUuidFB);
    LoadFunction(gpa, instance, "xrEnumerateSpaceSupportedComponentsFB", &table->EnumerateSpaceSupportedComponentsFB);
    LoadFunction(gpa, instance, "xrSetSpaceComponentStatusFB", &table->SetSpaceComponentStatusFB);
    LoadFunction(gpa, instance, "xrGetSpaceComponentStatusFB", &table->GetSpaceComponentStatusFB);
    LoadFunction(gpa, instance, "xrCreateFoveationProfileFB", &table->CreateFoveationProfileFB);
    LoadFunction(gpa, instance, "xrDestroyFoveationProfileFB", &table->DestroyFoveationProfileFB);
    LoadFunction(gpa, instance, "xrQuerySystemTrackedKeyboardFB", &table->QuerySystemTrackedKeyboardFB);
    LoadFunction(gpa, instance, "xrCreateKeyboardSpaceFB", &table->CreateKeyboardSpaceFB);
    LoadFunction(gpa, instance, "xrCreateTriangleMeshFB", &table->CreateTriangleMeshFB);
    LoadFunction(gpa, instance, "xrDestroyTriangleMeshFB", &table->DestroyTriangleMeshFB);
    LoadFunction(gpa, instance, "xrTriangleMeshGetVertexBufferFB", &table->TriangleMeshGetVertexBufferFB);
    LoadFunction(gpa, instance, "xrTriangleMeshGetIndexBufferFB", &table->TriangleMeshGetIndexBufferFB);
    LoadFunction(gpa, instance, "xrTriangleMeshBeginUpdateFB", &table->TriangleMeshBeginUpdateFB);
    LoadFunction(gpa, instance, "xrTriangleMeshEndUpdateFB", &table->TriangleMeshEndUpdateFB);
    LoadFunction(gpa, instance, "xrTriangleMeshBeginVertexBufferUpdateFB", &table->TriangleMeshBeginVertexBufferUpdateFB);
    LoadFunction(gpa, instance, "xrTriangleMeshEndVertexBufferUpdateFB", &table->TriangleMeshEndVertexBufferUpdateFB);
    LoadFunction(gpa, instance, "xrCreatePassthroughFB", &table->CreatePassthroughFB);
    LoadFunction(gpa, instance, "xrDestroyPassthroughFB", &table->DestroyPassthroughFB);
    LoadFunction(gpa, instance, "xrPassthroughStartFB", &table->PassthroughStartFB);
    LoadFunction(gpa, instance, "xrPassthroughPauseFB", &table->PassthroughPauseFB);
    LoadFunction(gpa, instance, "xrCreatePassthroughLayerFB", &table->CreatePassthroughLayerFB);
    LoadFunction(gpa, instance, "xrDestroyPassthroughLayerFB", &table->DestroyPassthroughLayerFB);
    LoadFunction(gpa, instance, "xrPassthroughLayerPauseFB", &table->PassthroughLayerPauseFB);
    LoadFunction(gpa, instance, "xrPassthroughLayerResumeFB", &table->PassthroughLayerResumeFB);
    LoadFunction(gpa, instance, "xrPassthroughLayerSetStyleFB", &table->PassthroughLayerSetStyleFB);
    LoadFunction(gpa, instance, "xrCreateGeometryInstanceFB", &table->CreateGeometryInstanceFB);
    LoadFunction(gpa, instance, "xrDestroyGeometryInstanceFB", &table->DestroyGeometryInstanceFB);
    LoadFunction(gpa, instance, "xrGeometryInstanceSetTransformFB", &table->GeometryInstanceSetTransformFB);
    LoadFunction(gpa, instance, "xrEnumerateRenderModelPathsFB", &table->EnumerateRenderModelPathsFB);
    LoadFunction(gpa, instance, "xrGetRenderModelPropertiesFB", &table->GetRenderModelPropertiesFB);
    LoadFunction(gpa, instance, "xrLoadRenderModelFB", &table->LoadRenderModelFB);
    LoadFunction(gpa, instance, "xrSetEnvironmentDepthEstimationVARJO", &table->SetEnvironmentDepthEstimationVARJO);
    LoadFunction(gpa, instance, "xrSetMarkerTrackingVARJO", &table->SetMarkerTrackingVARJO);
    LoadFunction(gpa, instance, "xrSetMarkerTrackingTimeoutVARJO", &table->SetMarkerTrackingTimeoutVARJO);
    LoadFunction(gpa, instance, "xrSetMarkerTrackingPredictionVARJO", &table->SetMarkerTrackingPredictionVARJO);
    LoadFunction(gpa, instance, "xrGetMarkerSizeVARJO", &table->GetMarkerSizeVARJO);
    LoadFunction(gpa, instance, "xrCreateMarkerSpaceVARJO", &table->CreateMarkerSpaceVARJO);
    LoadFunction(gpa, instance, "xrSetViewOffsetVARJO", &table->SetViewOffsetVARJO);
    LoadFunction(gpa, instance, "xrCreateSpaceFromCoordinateFrameUIDML", &table->CreateSpaceFromCoordinateFrameUIDML);
    LoadFunction(gpa, instance, "xrCreateMarkerDetectorML", &table->CreateMarkerDetectorML);
    LoadFunction(gpa, instance, "xrDestroyMarkerDetectorML", &table->DestroyMarkerDetectorML);
    LoadFunction(gpa, instance, "xrSnapshotMarkerDetectorML", &table->SnapshotMarkerDetectorML);
    LoadFunction(gpa, instance, "xrGetMarkerDetectorStateML", &table->GetMarkerDetectorStateML);
    LoadFunction(gpa, instance, "xrGetMarkersML", &table->GetMarkersML);
    LoadFunction(gpa, instance, "xrGetMarkerReprojectionErrorML", &table->GetMarkerReprojectionErrorML);
    LoadFunction(gpa, instance, "xrGetMarkerLengthML", &table->GetMarkerLengthML);
    LoadFunction(gpa, instance, "xrGetMarkerNumberML", &table->GetMarkerNumberML);
    LoadFunction(gpa, instance, "xrGetMarkerStringML", &table->GetMarkerStringML);
    LoadFunction(gpa, instance, "xrCreateMarkerSpaceML", &table->CreateMarkerSpaceML);
    LoadFunction(gpa, instance, "xrEnableLocalizationEventsML", &table->EnableLocalizationEventsML);
    LoadFunction(gpa, instance, "xrQueryLocalizationMapsML", &table->QueryLocalizationMapsML);
    LoadFunction(gpa, instance, "xrRequestMapLocalizationML", &table->RequestMapLocalizationML);
    LoadFunction(gpa, instance, "xrImportLocalizationMapML", &table->ImportLocalizationMapML);
    LoadFunction(gpa, instance, "xrCreateExportedLocalizationMapML", &table->CreateExportedLocalizationMapML);
    LoadFunction(gpa, instance, "xrDestroyExportedLocalizationMapML", &table->DestroyExportedLocalizationMapML);
    LoadFunction(gpa, instance, "xrGetExportedLocalizationMapDataML", &table->GetExportedLocalizationMapDataML);
    LoadFunction(gpa, instance, "xrCreateSpatialAnchorStoreConnectionMSFT", &table->CreateSpatialAnchorStoreConnectionMSFT);
    LoadFunction(gpa, instance, "xrDestroySpatialAnchorStoreConnectionMSFT", &table->DestroySpatialAnchorStoreConnectionMSFT);
    LoadFunction(gpa, instance, "xrPersistSpatialAnchorMSFT", &table->PersistSpatialAnchorMSFT);
    LoadFunction(gpa, instance, "xrEnumeratePersistedSpatialAnchorNamesMSFT", &table->EnumeratePersistedSpatialAnchorNamesMSFT);
    LoadFunction(gpa, instance, "xrCreateSpatialAnchorFromPersistedNameMSFT", &table->CreateSpatialAnchorFromPersistedNameMSFT);
    LoadFunction(gpa, instance, "xrUnpersistSpatialAnchorMSFT", &table->UnpersistSpatialAnchorMSFT);
    LoadFunction(gpa, instance, "xrClearSpatialAnchorStoreMSFT", &table->ClearSpatialAnchorStoreMSFT);
    LoadFunction(gpa, instance, "xrGetSceneMarkerRawDataMSFT", &table->GetSceneMarkerRawDataMSFT);
    LoadFunction(gpa, instance, "xrGetSceneMarkerDecodedStringMSFT", &table->GetSceneMarkerDecodedStringMSFT);
    LoadFunction(gpa, instance, "xrQuerySpacesFB", &table->QuerySpacesFB);
    LoadFunction(gpa, instance, "xrRetrieveSpaceQueryResultsFB", &table->RetrieveSpaceQueryResultsFB);
    LoadFunction(gpa, instance, "xrSaveSpaceFB", &table->SaveSpaceFB);
    LoadFunction(gpa, instance, "xrEraseSpaceFB", &table->EraseSpaceFB);
    LoadFunction(gpa, instance, "xrGetAudioOutputDeviceGuidOculus", &table->GetAudioOutputDeviceGuidOculus);
    LoadFunction(gpa, instance, "xrGetAudioInputDeviceGuidOculus", &table->GetAudioInputDeviceGuidOculus);
    LoadFunction(gpa, instance, "xrShareSpacesFB", &table->ShareSpacesFB);
    LoadFunction(gpa, instance, "xrGetSpaceBoundingBox2DFB", &table->GetSpaceBoundingBox2DFB);
    LoadFunction(gpa, instance, "xrGetSpaceBoundingBox3DFB", &table->GetSpaceBoundingBox3DFB);
    LoadFunction(gpa, instance, "xrGetSpaceSemanticLabelsFB", &table->GetSpaceSemanticLabelsFB);
    LoadFunction(gpa, instance, "xrGetSpaceBoundary2DFB", &table->GetSpaceBoundary2DFB);
    LoadFunction(gpa, instance, "xrGetSpaceRoomLayoutFB", &table->GetSpaceRoomLayoutFB);
    LoadFunction(gpa, instance, "xrSetDigitalLensControlALMALENCE", &table->SetDigitalLensControlALMALENCE);
    LoadFunction(gpa, instance, "xrRequestSceneCaptureFB", &table->RequestSceneCaptureFB);
    LoadFunction(gpa, instance, "xrGetSpaceContainerFB", &table->GetSpaceContainerFB);
    LoadFunction(gpa, instance, "xrGetFoveationEyeTrackedStateMETA", &table->GetFoveationEyeTrackedStateMETA);
    LoadFunction(gpa, instance, "xrCreateFaceTrackerFB", &table->CreateFaceTrackerFB);
    LoadFunction(gpa, instance, "xrDestroyFaceTrackerFB", &table->DestroyFaceTrackerFB);
    LoadFunction(gpa, instance, "xrGetFaceExpressionWeightsFB", &table->GetFaceExpressionWeightsFB);
    LoadFunction(gpa, instance, "xrCreateEyeTrackerFB", &table->CreateEyeTrackerFB);
    LoadFunction(gpa, instance, "xrDestroyEyeTrackerFB", &table->DestroyEyeTrackerFB);
    LoadFunction(gpa, instance, "xrGetEyeGazesFB", &table->GetEyeGazesFB);
    LoadFunction(gpa, instance, "xrPassthroughLayerSetKeyboardHandsIntensityFB", &table->PassthroughLayerSetKeyboardHandsIntensityFB);
    LoadFunction(gpa, instance, "xrGetDeviceSampleRateFB", &table->GetDeviceSampleRateFB);
    LoadFunction(gpa, instance, "xrGetPassthroughPreferencesMETA", &table->GetPassthroughPreferencesMETA);
    LoadFunction(gpa, instance, "xrCreateVirtualKeyboardMETA", &table->CreateVirtualKeyboardMETA);
    LoadFunction(gpa, instance, "xrDestroyVirtualKeyboardMETA", &table->DestroyVirtualKeyboardMETA);
    LoadFunction(gpa, instance, "xrCreateVirtualKeyboardSpaceMETA", &table->CreateVirtualKeyboardSpaceMETA);
    LoadFunction(gpa, instance, "xrSuggestVirtualKeyboardLocationMETA", &table->SuggestVirtualKeyboardLocationMETA);
    LoadFunction(gpa, instance, "xrGetVirtualKeyboardScaleMETA", &table->GetVirtualKeyboardScaleMETA);
    LoadFunction(gpa, instance, "xrSetVirtualKeyboardModelVisibilityMETA", &table->SetVirtualKeyboardModelVisibilityMETA);
    LoadFunction(gpa, instance, "xrGetVirtualKeyboardModelAnimationStatesMETA", &table->GetVirtualKeyboardModelAnimationStatesMETA);
    LoadFunction(gpa, instance, "xrGetVirtualKeyboardDirtyTexturesMETA", &table->GetVirtualKeyboardDirtyTexturesMETA);
    LoadFunction(gpa, instance, "xrGetVirtualKeyboardTextureDataMETA", &table->GetVirtualKeyboardTextureDataMETA);
    LoadFunction(gpa, instance, "xrSendVirtualKeyboardInputMETA", &table->SendVirtualKeyboardInputMETA);
    LoadFunction(gpa, instance, "xrChangeVirtualKeyboardTextContextMETA", &table->ChangeVirtualKeyboardTextContextMETA);
    LoadFunction(gpa, instance, "xrEnumerateExternalCamerasOCULUS", &table->EnumerateExternalCamerasOCULUS);
    LoadFunction(gpa, instance, "xrEnumeratePerformanceMetricsCounterPathsMETA", &table->EnumeratePerformanceMetricsCounterPathsMETA);
    LoadFunction(gpa, instance, "xrSetPerformanceMetricsStateMETA", &table->SetPerformanceMetricsStateMETA);
    LoadFunction(gpa, instance, "xrGetPerformanceMetricsStateMETA", &table->GetPerformanceMetricsStateMETA);
    LoadFunction(gpa, instance, "xrQueryPerformanceMetricsCounterMETA", &table->QueryPerformanceMetricsCounterMETA);
    LoadFunction(gpa, instance, "xrSaveSpaceListFB", &table->SaveSpaceListFB);
    LoadFunction(gpa, instance, "xrCreateSpaceUserFB", &table->CreateSpaceUserFB);
    LoadFunction(gpa, instance, "xrGetSpaceUserIdFB", &table->GetSpaceUserIdFB);
    LoadFunction(gpa, instance, "xrDestroySpaceUserFB", &table->DestroySpaceUserFB);
    LoadFunction(gpa, instance, "xrGetRecommendedLayerResolutionMETA", &table->GetRecommendedLayerResolutionMETA);
    LoadFunction(gpa, instance, "xrCreatePassthroughColorLutMETA", &table->CreatePassthroughColorLutMETA);
    LoadFunction(gpa, instance, "xrDestroyPassthroughColorLutMETA", &table->DestroyPassthroughColorLutMETA);
    LoadFunction(gpa, instance, "xrUpdatePassthroughColorLutMETA", &table->UpdatePassthroughColorLutMETA);
    LoadFunction(gpa, instance, "xrGetSpaceTriangleMeshMETA", &table->GetSpaceTriangleMeshMETA);
    LoadFunction(gpa, instance, "xrCreateFaceTracker2FB", &table->CreateFaceTracker2FB);
    LoadFunction(gpa, instance, "xrDestroyFaceTracker2FB", &table->DestroyFaceTracker2FB);
    LoadFunction(gpa, instance, "xrGetFaceExpressionWeights2FB", &table->GetFaceExpressionWeights2FB);
    LoadFunction(gpa, instance, "xrSetTrackingOptimizationSettingsHintQCOM", &table->SetTrackingOptimizationSettingsHintQCOM);
    LoadFunction(gpa, instance, "xrCreatePassthroughHTC", &table->CreatePassthroughHTC);
    LoadFunction(gpa, instance, "xrDestroyPassthroughHTC", &table->DestroyPassthroughHTC);
    LoadFunction(gpa, instance, "xrApplyFoveationHTC", &table->ApplyFoveationHTC);
    LoadFunction(gpa, instance, "xrCreateSpatialAnchorHTC", &table->CreateSpatialAnchorHTC);
    LoadFunction(gpa, instance, "xrGetSpatialAnchorNameHTC", &table->GetSpatialAnchorNameHTC);
    LoadFunction(gpa, instance, "xrApplyForceFeedbackCurlMNDX", &table->ApplyForceFeedbackCurlMNDX);
    LoadFunction(gpa, instance, "xrCreatePlaneDetectorEXT", &table->CreatePlaneDetectorEXT);
    LoadFunction(gpa, instance, "xrDestroyPlaneDetectorEXT", &table->DestroyPlaneDetectorEXT);
    LoadFunction(gpa, instance, "xrBeginPlaneDetectionEXT", &table->BeginPlaneDetectionEXT);
    LoadFunction(gpa, instance, "xrGetPlaneDetectionStateEXT", &table->GetPlaneDetectionStateEXT);
    LoadFunction(gpa, instance, "xrGetPlaneDetectionsEXT", &table->GetPlaneDetectionsEXT);
    LoadFunction(gpa, instance, "xrGetPlanePolygonBufferEXT", &table->GetPlanePolygonBufferEXT);
    LoadFunction(gpa, instance, "xrEnableUserCalibrationEventsML", &table->EnableUserCalibrationEventsML);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif //  GFXRECON_GENERATED_OPENXR_DISPATCH_TABLE_H
