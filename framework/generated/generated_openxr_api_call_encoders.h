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

#ifndef  GFXRECON_GENERATED_OPENXR_API_CALL_ENCODERS_H
#define  GFXRECON_GENERATED_OPENXR_API_CALL_ENCODERS_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "format/platform_types.h"
#include "util/defines.h"

// Define the platform defines so that we can have entrypoints for each
// possible entrypoint in our dispatch table.
#ifndef XR_USE_PLATFORM_WIN32
#define XR_USE_PLATFORM_WIN32
#endif
#ifndef XR_USE_PLATFORM_WAYLAND
#define XR_USE_PLATFORM_WAYLAND
#endif
#ifndef XR_USE_PLATFORM_XCB
#define XR_USE_PLATFORM_XCB
#endif
#ifndef XR_USE_PLATFORM_XLIB
#define XR_USE_PLATFORM_XLIB
#endif
#ifndef XR_USE_PLATFORM_ANDROID
#define XR_USE_PLATFORM_ANDROID
#endif
#ifndef XR_USE_PLATFORM_ML
#define XR_USE_PLATFORM_ML
#endif
#ifndef XR_USE_PLATFORM_EGL
#define XR_USE_PLATFORM_EGL
#endif
#ifndef XR_USE_GRAPHICS_API_VULKAN
#define XR_USE_GRAPHICS_API_VULKAN
#endif
#ifndef XR_USE_GRAPHICS_API_OPENGL
#define XR_USE_GRAPHICS_API_OPENGL
#endif
#ifndef XR_USE_GRAPHICS_API_OPENGL_ES
#define XR_USE_GRAPHICS_API_OPENGL_ES
#endif
#ifndef XR_USE_GRAPHICS_API_D3D11
#define XR_USE_GRAPHICS_API_D3D11
#endif
#ifndef XR_USE_GRAPHICS_API_D3D12
#define XR_USE_GRAPHICS_API_D3D12
#endif
#ifndef XR_USE_TIMESPEC
#define XR_USE_TIMESPEC
#endif

#include "openxr/openxr.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

XRAPI_ATTR XrResult XRAPI_CALL CreateInstance(
    const XrInstanceCreateInfo*                 createInfo,
    XrInstance*                                 instance);

XRAPI_ATTR XrResult XRAPI_CALL DestroyInstance(
    XrInstance                                  instance);

XRAPI_ATTR XrResult XRAPI_CALL GetInstanceProperties(
    XrInstance                                  instance,
    XrInstanceProperties*                       instanceProperties);

XRAPI_ATTR XrResult XRAPI_CALL PollEvent(
    XrInstance                                  instance,
    XrEventDataBuffer*                          eventData);

XRAPI_ATTR XrResult XRAPI_CALL ResultToString(
    XrInstance                                  instance,
    XrResult                                    value,
    char                                        buffer[XR_MAX_RESULT_STRING_SIZE]);

XRAPI_ATTR XrResult XRAPI_CALL StructureTypeToString(
    XrInstance                                  instance,
    XrStructureType                             value,
    char                                        buffer[XR_MAX_STRUCTURE_NAME_SIZE]);

XRAPI_ATTR XrResult XRAPI_CALL GetSystem(
    XrInstance                                  instance,
    const XrSystemGetInfo*                      getInfo,
    XrSystemId*                                 systemId);

XRAPI_ATTR XrResult XRAPI_CALL GetSystemProperties(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrSystemProperties*                         properties);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateEnvironmentBlendModes(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    environmentBlendModeCapacityInput,
    uint32_t*                                   environmentBlendModeCountOutput,
    XrEnvironmentBlendMode*                     environmentBlendModes);

XRAPI_ATTR XrResult XRAPI_CALL CreateSession(
    XrInstance                                  instance,
    const XrSessionCreateInfo*                  createInfo,
    XrSession*                                  session);

XRAPI_ATTR XrResult XRAPI_CALL DestroySession(
    XrSession                                   session);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateReferenceSpaces(
    XrSession                                   session,
    uint32_t                                    spaceCapacityInput,
    uint32_t*                                   spaceCountOutput,
    XrReferenceSpaceType*                       spaces);

XRAPI_ATTR XrResult XRAPI_CALL CreateReferenceSpace(
    XrSession                                   session,
    const XrReferenceSpaceCreateInfo*           createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL GetReferenceSpaceBoundsRect(
    XrSession                                   session,
    XrReferenceSpaceType                        referenceSpaceType,
    XrExtent2Df*                                bounds);

XRAPI_ATTR XrResult XRAPI_CALL CreateActionSpace(
    XrSession                                   session,
    const XrActionSpaceCreateInfo*              createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL LocateSpace(
    XrSpace                                     space,
    XrSpace                                     baseSpace,
    XrTime                                      time,
    XrSpaceLocation*                            location);

XRAPI_ATTR XrResult XRAPI_CALL DestroySpace(
    XrSpace                                     space);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateViewConfigurations(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    viewConfigurationTypeCapacityInput,
    uint32_t*                                   viewConfigurationTypeCountOutput,
    XrViewConfigurationType*                    viewConfigurationTypes);

XRAPI_ATTR XrResult XRAPI_CALL GetViewConfigurationProperties(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    XrViewConfigurationProperties*              configurationProperties);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateViewConfigurationViews(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewCapacityInput,
    uint32_t*                                   viewCountOutput,
    XrViewConfigurationView*                    views);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateSwapchainFormats(
    XrSession                                   session,
    uint32_t                                    formatCapacityInput,
    uint32_t*                                   formatCountOutput,
    int64_t*                                    formats);

XRAPI_ATTR XrResult XRAPI_CALL CreateSwapchain(
    XrSession                                   session,
    const XrSwapchainCreateInfo*                createInfo,
    XrSwapchain*                                swapchain);

XRAPI_ATTR XrResult XRAPI_CALL DestroySwapchain(
    XrSwapchain                                 swapchain);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateSwapchainImages(
    XrSwapchain                                 swapchain,
    uint32_t                                    imageCapacityInput,
    uint32_t*                                   imageCountOutput,
    XrSwapchainImageBaseHeader*                 images);

XRAPI_ATTR XrResult XRAPI_CALL AcquireSwapchainImage(
    XrSwapchain                                 swapchain,
    const XrSwapchainImageAcquireInfo*          acquireInfo,
    uint32_t*                                   index);

XRAPI_ATTR XrResult XRAPI_CALL WaitSwapchainImage(
    XrSwapchain                                 swapchain,
    const XrSwapchainImageWaitInfo*             waitInfo);

XRAPI_ATTR XrResult XRAPI_CALL ReleaseSwapchainImage(
    XrSwapchain                                 swapchain,
    const XrSwapchainImageReleaseInfo*          releaseInfo);

XRAPI_ATTR XrResult XRAPI_CALL BeginSession(
    XrSession                                   session,
    const XrSessionBeginInfo*                   beginInfo);

XRAPI_ATTR XrResult XRAPI_CALL EndSession(
    XrSession                                   session);

XRAPI_ATTR XrResult XRAPI_CALL RequestExitSession(
    XrSession                                   session);

XRAPI_ATTR XrResult XRAPI_CALL WaitFrame(
    XrSession                                   session,
    const XrFrameWaitInfo*                      frameWaitInfo,
    XrFrameState*                               frameState);

XRAPI_ATTR XrResult XRAPI_CALL BeginFrame(
    XrSession                                   session,
    const XrFrameBeginInfo*                     frameBeginInfo);

XRAPI_ATTR XrResult XRAPI_CALL EndFrame(
    XrSession                                   session,
    const XrFrameEndInfo*                       frameEndInfo);

XRAPI_ATTR XrResult XRAPI_CALL LocateViews(
    XrSession                                   session,
    const XrViewLocateInfo*                     viewLocateInfo,
    XrViewState*                                viewState,
    uint32_t                                    viewCapacityInput,
    uint32_t*                                   viewCountOutput,
    XrView*                                     views);

XRAPI_ATTR XrResult XRAPI_CALL StringToPath(
    XrInstance                                  instance,
    const char*                                 pathString,
    XrPath*                                     path);

XRAPI_ATTR XrResult XRAPI_CALL PathToString(
    XrInstance                                  instance,
    XrPath                                      path,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL CreateActionSet(
    XrInstance                                  instance,
    const XrActionSetCreateInfo*                createInfo,
    XrActionSet*                                actionSet);

XRAPI_ATTR XrResult XRAPI_CALL DestroyActionSet(
    XrActionSet                                 actionSet);

XRAPI_ATTR XrResult XRAPI_CALL CreateAction(
    XrActionSet                                 actionSet,
    const XrActionCreateInfo*                   createInfo,
    XrAction*                                   action);

XRAPI_ATTR XrResult XRAPI_CALL DestroyAction(
    XrAction                                    action);

XRAPI_ATTR XrResult XRAPI_CALL SuggestInteractionProfileBindings(
    XrInstance                                  instance,
    const XrInteractionProfileSuggestedBinding* suggestedBindings);

XRAPI_ATTR XrResult XRAPI_CALL AttachSessionActionSets(
    XrSession                                   session,
    const XrSessionActionSetsAttachInfo*        attachInfo);

XRAPI_ATTR XrResult XRAPI_CALL GetCurrentInteractionProfile(
    XrSession                                   session,
    XrPath                                      topLevelUserPath,
    XrInteractionProfileState*                  interactionProfile);

XRAPI_ATTR XrResult XRAPI_CALL GetActionStateBoolean(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStateBoolean*                       state);

XRAPI_ATTR XrResult XRAPI_CALL GetActionStateFloat(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStateFloat*                         state);

XRAPI_ATTR XrResult XRAPI_CALL GetActionStateVector2f(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStateVector2f*                      state);

XRAPI_ATTR XrResult XRAPI_CALL GetActionStatePose(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStatePose*                          state);

XRAPI_ATTR XrResult XRAPI_CALL SyncActions(
    XrSession                                   session,
    const XrActionsSyncInfo*                    syncInfo);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateBoundSourcesForAction(
    XrSession                                   session,
    const XrBoundSourcesForActionEnumerateInfo* enumerateInfo,
    uint32_t                                    sourceCapacityInput,
    uint32_t*                                   sourceCountOutput,
    XrPath*                                     sources);

XRAPI_ATTR XrResult XRAPI_CALL GetInputSourceLocalizedName(
    XrSession                                   session,
    const XrInputSourceLocalizedNameGetInfo*    getInfo,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL ApplyHapticFeedback(
    XrSession                                   session,
    const XrHapticActionInfo*                   hapticActionInfo,
    const XrHapticBaseHeader*                   hapticFeedback);

XRAPI_ATTR XrResult XRAPI_CALL StopHapticFeedback(
    XrSession                                   session,
    const XrHapticActionInfo*                   hapticActionInfo);


XRAPI_ATTR XrResult XRAPI_CALL SetAndroidApplicationThreadKHR(
    XrSession                                   session,
    XrAndroidThreadTypeKHR                      threadType,
    uint32_t                                    threadId);

XRAPI_ATTR XrResult XRAPI_CALL CreateSwapchainAndroidSurfaceKHR(
    XrSession                                   session,
    const XrSwapchainCreateInfo*                info,
    XrSwapchain*                                swapchain,
    jobject*                                    surface);

XRAPI_ATTR XrResult XRAPI_CALL GetOpenGLGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsOpenGLKHR*            graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL GetOpenGLESGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsOpenGLESKHR*          graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL GetVulkanInstanceExtensionsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL GetVulkanDeviceExtensionsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL GetVulkanGraphicsDeviceKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    VkInstance                                  vkInstance,
    VkPhysicalDevice*                           vkPhysicalDevice);

XRAPI_ATTR XrResult XRAPI_CALL GetVulkanGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsVulkanKHR*            graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL GetD3D11GraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsD3D11KHR*             graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL GetD3D12GraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsD3D12KHR*             graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL GetVisibilityMaskKHR(
    XrSession                                   session,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewIndex,
    XrVisibilityMaskTypeKHR                     visibilityMaskType,
    XrVisibilityMaskKHR*                        visibilityMask);

XRAPI_ATTR XrResult XRAPI_CALL ConvertWin32PerformanceCounterToTimeKHR(
    XrInstance                                  instance,
    const LARGE_INTEGER*                        performanceCounter,
    XrTime*                                     time);

XRAPI_ATTR XrResult XRAPI_CALL ConvertTimeToWin32PerformanceCounterKHR(
    XrInstance                                  instance,
    XrTime                                      time,
    LARGE_INTEGER*                              performanceCounter);

XRAPI_ATTR XrResult XRAPI_CALL ConvertTimespecTimeToTimeKHR(
    XrInstance                                  instance,
    const struct timespec*                      timespecTime,
    XrTime*                                     time);

XRAPI_ATTR XrResult XRAPI_CALL ConvertTimeToTimespecTimeKHR(
    XrInstance                                  instance,
    XrTime                                      time,
    struct timespec*                            timespecTime);

XRAPI_ATTR XrResult XRAPI_CALL InitializeLoaderKHR(
    const XrLoaderInitInfoBaseHeaderKHR*        loaderInitInfo);

XRAPI_ATTR XrResult XRAPI_CALL GetVulkanGraphicsRequirements2KHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsVulkanKHR*            graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL PerfSettingsSetPerformanceLevelEXT(
    XrSession                                   session,
    XrPerfSettingsDomainEXT                     domain,
    XrPerfSettingsLevelEXT                      level);

XRAPI_ATTR XrResult XRAPI_CALL ThermalGetTemperatureTrendEXT(
    XrSession                                   session,
    XrPerfSettingsDomainEXT                     domain,
    XrPerfSettingsNotificationLevelEXT*         notificationLevel,
    float*                                      tempHeadroom,
    float*                                      tempSlope);

XRAPI_ATTR XrResult XRAPI_CALL SetDebugUtilsObjectNameEXT(
    XrInstance                                  instance,
    const XrDebugUtilsObjectNameInfoEXT*        nameInfo);

XRAPI_ATTR XrResult XRAPI_CALL CreateDebugUtilsMessengerEXT(
    XrInstance                                  instance,
    const XrDebugUtilsMessengerCreateInfoEXT*   createInfo,
    XrDebugUtilsMessengerEXT*                   messenger);

XRAPI_ATTR XrResult XRAPI_CALL DestroyDebugUtilsMessengerEXT(
    XrDebugUtilsMessengerEXT                    messenger);

XRAPI_ATTR XrResult                                    XRAPI_CALL SubmitDebugUtilsMessageEXT(
    XrInstance                                  instance,
    XrDebugUtilsMessageSeverityFlagsEXT         messageSeverity,
    XrDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const XrDebugUtilsMessengerCallbackDataEXT* callbackData);

XRAPI_ATTR XrResult XRAPI_CALL SessionBeginDebugUtilsLabelRegionEXT(
    XrSession                                   session,
    const XrDebugUtilsLabelEXT*                 labelInfo);

XRAPI_ATTR XrResult XRAPI_CALL SessionEndDebugUtilsLabelRegionEXT(
    XrSession                                   session);

XRAPI_ATTR XrResult XRAPI_CALL SessionInsertDebugUtilsLabelEXT(
    XrSession                                   session,
    const XrDebugUtilsLabelEXT*                 labelInfo);

XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorMSFT(
    XrSession                                   session,
    const XrSpatialAnchorCreateInfoMSFT*        createInfo,
    XrSpatialAnchorMSFT*                        anchor);

XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorSpaceMSFT(
    XrSession                                   session,
    const XrSpatialAnchorSpaceCreateInfoMSFT*   createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL DestroySpatialAnchorMSFT(
    XrSpatialAnchorMSFT                         anchor);

XRAPI_ATTR XrResult XRAPI_CALL SetInputDeviceActiveEXT(
    XrSession                                   session,
    XrPath                                      interactionProfile,
    XrPath                                      topLevelPath,
    XrBool32                                    isActive);

XRAPI_ATTR XrResult XRAPI_CALL SetInputDeviceStateBoolEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    XrBool32                                    state);

XRAPI_ATTR XrResult XRAPI_CALL SetInputDeviceStateFloatEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    float                                       state);

XRAPI_ATTR XrResult XRAPI_CALL SetInputDeviceStateVector2fEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    XrVector2f                                  state);

XRAPI_ATTR XrResult XRAPI_CALL SetInputDeviceLocationEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    XrSpace                                     space,
    XrPosef                                     pose);

XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialGraphNodeSpaceMSFT(
    XrSession                                   session,
    const XrSpatialGraphNodeSpaceCreateInfoMSFT* createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL TryCreateSpatialGraphStaticNodeBindingMSFT(
    XrSession                                   session,
    const XrSpatialGraphStaticNodeBindingCreateInfoMSFT* createInfo,
    XrSpatialGraphNodeBindingMSFT*              nodeBinding);

XRAPI_ATTR XrResult XRAPI_CALL DestroySpatialGraphNodeBindingMSFT(
    XrSpatialGraphNodeBindingMSFT               nodeBinding);

XRAPI_ATTR XrResult XRAPI_CALL GetSpatialGraphNodeBindingPropertiesMSFT(
    XrSpatialGraphNodeBindingMSFT               nodeBinding,
    const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* getInfo,
    XrSpatialGraphNodeBindingPropertiesMSFT*    properties);

XRAPI_ATTR XrResult XRAPI_CALL CreateHandTrackerEXT(
    XrSession                                   session,
    const XrHandTrackerCreateInfoEXT*           createInfo,
    XrHandTrackerEXT*                           handTracker);

XRAPI_ATTR XrResult XRAPI_CALL DestroyHandTrackerEXT(
    XrHandTrackerEXT                            handTracker);

XRAPI_ATTR XrResult XRAPI_CALL LocateHandJointsEXT(
    XrHandTrackerEXT                            handTracker,
    const XrHandJointsLocateInfoEXT*            locateInfo,
    XrHandJointLocationsEXT*                    locations);

XRAPI_ATTR XrResult XRAPI_CALL CreateHandMeshSpaceMSFT(
    XrHandTrackerEXT                            handTracker,
    const XrHandMeshSpaceCreateInfoMSFT*        createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL UpdateHandMeshMSFT(
    XrHandTrackerEXT                            handTracker,
    const XrHandMeshUpdateInfoMSFT*             updateInfo,
    XrHandMeshMSFT*                             handMesh);

XRAPI_ATTR XrResult XRAPI_CALL GetControllerModelKeyMSFT(
    XrSession                                   session,
    XrPath                                      topLevelUserPath,
    XrControllerModelKeyStateMSFT*              controllerModelKeyState);

XRAPI_ATTR XrResult XRAPI_CALL LoadControllerModelMSFT(
    XrSession                                   session,
    XrControllerModelKeyMSFT                    modelKey,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    uint8_t*                                    buffer);

XRAPI_ATTR XrResult XRAPI_CALL GetControllerModelPropertiesMSFT(
    XrSession                                   session,
    XrControllerModelKeyMSFT                    modelKey,
    XrControllerModelPropertiesMSFT*            properties);

XRAPI_ATTR XrResult XRAPI_CALL GetControllerModelStateMSFT(
    XrSession                                   session,
    XrControllerModelKeyMSFT                    modelKey,
    XrControllerModelStateMSFT*                 state);

XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorFromPerceptionAnchorMSFT(
    XrSession                                   session,
    IUnknown*                                   perceptionAnchor,
    XrSpatialAnchorMSFT*                        anchor);

XRAPI_ATTR XrResult XRAPI_CALL TryGetPerceptionAnchorFromSpatialAnchorMSFT(
    XrSession                                   session,
    XrSpatialAnchorMSFT                         anchor,
    IUnknown**                                  perceptionAnchor);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateReprojectionModesMSFT(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    modeCapacityInput,
    uint32_t*                                   modeCountOutput,
    XrReprojectionModeMSFT*                     modes);

XRAPI_ATTR XrResult XRAPI_CALL UpdateSwapchainFB(
    XrSwapchain                                 swapchain,
    const XrSwapchainStateBaseHeaderFB*         state);

XRAPI_ATTR XrResult XRAPI_CALL GetSwapchainStateFB(
    XrSwapchain                                 swapchain,
    XrSwapchainStateBaseHeaderFB*               state);

XRAPI_ATTR XrResult XRAPI_CALL CreateBodyTrackerFB(
    XrSession                                   session,
    const XrBodyTrackerCreateInfoFB*            createInfo,
    XrBodyTrackerFB*                            bodyTracker);

XRAPI_ATTR XrResult XRAPI_CALL DestroyBodyTrackerFB(
    XrBodyTrackerFB                             bodyTracker);

XRAPI_ATTR XrResult XRAPI_CALL LocateBodyJointsFB(
    XrBodyTrackerFB                             bodyTracker,
    const XrBodyJointsLocateInfoFB*             locateInfo,
    XrBodyJointLocationsFB*                     locations);

XRAPI_ATTR XrResult XRAPI_CALL GetBodySkeletonFB(
    XrBodyTrackerFB                             bodyTracker,
    XrBodySkeletonFB*                           skeleton);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateSceneComputeFeaturesMSFT(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    featureCapacityInput,
    uint32_t*                                   featureCountOutput,
    XrSceneComputeFeatureMSFT*                  features);

XRAPI_ATTR XrResult XRAPI_CALL CreateSceneObserverMSFT(
    XrSession                                   session,
    const XrSceneObserverCreateInfoMSFT*        createInfo,
    XrSceneObserverMSFT*                        sceneObserver);

XRAPI_ATTR XrResult XRAPI_CALL DestroySceneObserverMSFT(
    XrSceneObserverMSFT                         sceneObserver);

XRAPI_ATTR XrResult XRAPI_CALL CreateSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrSceneCreateInfoMSFT*                createInfo,
    XrSceneMSFT*                                scene);

XRAPI_ATTR XrResult XRAPI_CALL DestroySceneMSFT(
    XrSceneMSFT                                 scene);

XRAPI_ATTR XrResult XRAPI_CALL ComputeNewSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrNewSceneComputeInfoMSFT*            computeInfo);

XRAPI_ATTR XrResult XRAPI_CALL GetSceneComputeStateMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    XrSceneComputeStateMSFT*                    state);

XRAPI_ATTR XrResult XRAPI_CALL GetSceneComponentsMSFT(
    XrSceneMSFT                                 scene,
    const XrSceneComponentsGetInfoMSFT*         getInfo,
    XrSceneComponentsMSFT*                      components);

XRAPI_ATTR XrResult XRAPI_CALL LocateSceneComponentsMSFT(
    XrSceneMSFT                                 scene,
    const XrSceneComponentsLocateInfoMSFT*      locateInfo,
    XrSceneComponentLocationsMSFT*              locations);

XRAPI_ATTR XrResult XRAPI_CALL GetSceneMeshBuffersMSFT(
    XrSceneMSFT                                 scene,
    const XrSceneMeshBuffersGetInfoMSFT*        getInfo,
    XrSceneMeshBuffersMSFT*                     buffers);

XRAPI_ATTR XrResult XRAPI_CALL DeserializeSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrSceneDeserializeInfoMSFT*           deserializeInfo);

XRAPI_ATTR XrResult XRAPI_CALL GetSerializedSceneFragmentDataMSFT(
    XrSceneMSFT                                 scene,
    const XrSerializedSceneFragmentDataGetInfoMSFT* getInfo,
    uint32_t                                    countInput,
    uint32_t*                                   readOutput,
    uint8_t*                                    buffer);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateDisplayRefreshRatesFB(
    XrSession                                   session,
    uint32_t                                    displayRefreshRateCapacityInput,
    uint32_t*                                   displayRefreshRateCountOutput,
    float*                                      displayRefreshRates);

XRAPI_ATTR XrResult XRAPI_CALL GetDisplayRefreshRateFB(
    XrSession                                   session,
    float*                                      displayRefreshRate);

XRAPI_ATTR XrResult XRAPI_CALL RequestDisplayRefreshRateFB(
    XrSession                                   session,
    float                                       displayRefreshRate);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateViveTrackerPathsHTCX(
    XrInstance                                  instance,
    uint32_t                                    pathCapacityInput,
    uint32_t*                                   pathCountOutput,
    XrViveTrackerPathsHTCX*                     paths);

XRAPI_ATTR XrResult XRAPI_CALL CreateFacialTrackerHTC(
    XrSession                                   session,
    const XrFacialTrackerCreateInfoHTC*         createInfo,
    XrFacialTrackerHTC*                         facialTracker);

XRAPI_ATTR XrResult XRAPI_CALL DestroyFacialTrackerHTC(
    XrFacialTrackerHTC                          facialTracker);

XRAPI_ATTR XrResult XRAPI_CALL GetFacialExpressionsHTC(
    XrFacialTrackerHTC                          facialTracker,
    XrFacialExpressionsHTC*                     facialExpressions);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateColorSpacesFB(
    XrSession                                   session,
    uint32_t                                    colorSpaceCapacityInput,
    uint32_t*                                   colorSpaceCountOutput,
    XrColorSpaceFB*                             colorSpaces);

XRAPI_ATTR XrResult XRAPI_CALL SetColorSpaceFB(
    XrSession                                   session,
    const XrColorSpaceFB                        colorSpace);

XRAPI_ATTR XrResult XRAPI_CALL GetHandMeshFB(
    XrHandTrackerEXT                            handTracker,
    XrHandTrackingMeshFB*                       mesh);

XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorFB(
    XrSession                                   session,
    const XrSpatialAnchorCreateInfoFB*          info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL GetSpaceUuidFB(
    XrSpace                                     space,
    XrUuidEXT*                                  uuid);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateSpaceSupportedComponentsFB(
    XrSpace                                     space,
    uint32_t                                    componentTypeCapacityInput,
    uint32_t*                                   componentTypeCountOutput,
    XrSpaceComponentTypeFB*                     componentTypes);

XRAPI_ATTR XrResult XRAPI_CALL SetSpaceComponentStatusFB(
    XrSpace                                     space,
    const XrSpaceComponentStatusSetInfoFB*      info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL GetSpaceComponentStatusFB(
    XrSpace                                     space,
    XrSpaceComponentTypeFB                      componentType,
    XrSpaceComponentStatusFB*                   status);

XRAPI_ATTR XrResult XRAPI_CALL CreateFoveationProfileFB(
    XrSession                                   session,
    const XrFoveationProfileCreateInfoFB*       createInfo,
    XrFoveationProfileFB*                       profile);

XRAPI_ATTR XrResult XRAPI_CALL DestroyFoveationProfileFB(
    XrFoveationProfileFB                        profile);

XRAPI_ATTR XrResult XRAPI_CALL QuerySystemTrackedKeyboardFB(
    XrSession                                   session,
    const XrKeyboardTrackingQueryFB*            queryInfo,
    XrKeyboardTrackingDescriptionFB*            keyboard);

XRAPI_ATTR XrResult XRAPI_CALL CreateKeyboardSpaceFB(
    XrSession                                   session,
    const XrKeyboardSpaceCreateInfoFB*          createInfo,
    XrSpace*                                    keyboardSpace);

XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshBeginUpdateFB(
    XrTriangleMeshFB                            mesh);

XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshEndUpdateFB(
    XrTriangleMeshFB                            mesh,
    uint32_t                                    vertexCount,
    uint32_t                                    triangleCount);

XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshBeginVertexBufferUpdateFB(
    XrTriangleMeshFB                            mesh,
    uint32_t*                                   outVertexCount);

XRAPI_ATTR XrResult XRAPI_CALL TriangleMeshEndVertexBufferUpdateFB(
    XrTriangleMeshFB                            mesh);

XRAPI_ATTR XrResult XRAPI_CALL CreatePassthroughFB(
    XrSession                                   session,
    const XrPassthroughCreateInfoFB*            createInfo,
    XrPassthroughFB*                            outPassthrough);

XRAPI_ATTR XrResult XRAPI_CALL DestroyPassthroughFB(
    XrPassthroughFB                             passthrough);

XRAPI_ATTR XrResult XRAPI_CALL PassthroughStartFB(
    XrPassthroughFB                             passthrough);

XRAPI_ATTR XrResult XRAPI_CALL PassthroughPauseFB(
    XrPassthroughFB                             passthrough);

XRAPI_ATTR XrResult XRAPI_CALL CreatePassthroughLayerFB(
    XrSession                                   session,
    const XrPassthroughLayerCreateInfoFB*       createInfo,
    XrPassthroughLayerFB*                       outLayer);

XRAPI_ATTR XrResult XRAPI_CALL DestroyPassthroughLayerFB(
    XrPassthroughLayerFB                        layer);

XRAPI_ATTR XrResult XRAPI_CALL PassthroughLayerPauseFB(
    XrPassthroughLayerFB                        layer);

XRAPI_ATTR XrResult XRAPI_CALL PassthroughLayerResumeFB(
    XrPassthroughLayerFB                        layer);

XRAPI_ATTR XrResult XRAPI_CALL PassthroughLayerSetStyleFB(
    XrPassthroughLayerFB                        layer,
    const XrPassthroughStyleFB*                 style);

XRAPI_ATTR XrResult XRAPI_CALL CreateGeometryInstanceFB(
    XrSession                                   session,
    const XrGeometryInstanceCreateInfoFB*       createInfo,
    XrGeometryInstanceFB*                       outGeometryInstance);

XRAPI_ATTR XrResult XRAPI_CALL DestroyGeometryInstanceFB(
    XrGeometryInstanceFB                        instance);

XRAPI_ATTR XrResult XRAPI_CALL GeometryInstanceSetTransformFB(
    XrGeometryInstanceFB                        instance,
    const XrGeometryInstanceTransformFB*        transformation);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateRenderModelPathsFB(
    XrSession                                   session,
    uint32_t                                    pathCapacityInput,
    uint32_t*                                   pathCountOutput,
    XrRenderModelPathInfoFB*                    paths);

XRAPI_ATTR XrResult XRAPI_CALL GetRenderModelPropertiesFB(
    XrSession                                   session,
    XrPath                                      path,
    XrRenderModelPropertiesFB*                  properties);

XRAPI_ATTR XrResult XRAPI_CALL LoadRenderModelFB(
    XrSession                                   session,
    const XrRenderModelLoadInfoFB*              info,
    XrRenderModelBufferFB*                      buffer);

XRAPI_ATTR XrResult XRAPI_CALL SetEnvironmentDepthEstimationVARJO(
    XrSession                                   session,
    XrBool32                                    enabled);

XRAPI_ATTR XrResult  XRAPI_CALL SetMarkerTrackingVARJO(
    XrSession                                   session,
    XrBool32                                    enabled);

XRAPI_ATTR XrResult XRAPI_CALL SetMarkerTrackingTimeoutVARJO(
    XrSession                                   session,
    uint64_t                                    markerId,
    XrDuration                                  timeout);

XRAPI_ATTR XrResult XRAPI_CALL SetMarkerTrackingPredictionVARJO(
    XrSession                                   session,
    uint64_t                                    markerId,
    XrBool32                                    enable);

XRAPI_ATTR XrResult XRAPI_CALL GetMarkerSizeVARJO(
    XrSession                                   session,
    uint64_t                                    markerId,
    XrExtent2Df*                                size);

XRAPI_ATTR XrResult XRAPI_CALL CreateMarkerSpaceVARJO(
    XrSession                                   session,
    const XrMarkerSpaceCreateInfoVARJO*         createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult  XRAPI_CALL SetViewOffsetVARJO(
    XrSession                                   session,
    float                                       offset);

XRAPI_ATTR XrResult XRAPI_CALL CreateSpaceFromCoordinateFrameUIDML(
    XrSession                                   session,
    const XrCoordinateSpaceCreateInfoML *       createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL CreateMarkerDetectorML(
    XrSession                                   session,
    const XrMarkerDetectorCreateInfoML*         createInfo,
    XrMarkerDetectorML*                         markerDetector);

XRAPI_ATTR XrResult XRAPI_CALL DestroyMarkerDetectorML(
    XrMarkerDetectorML                          markerDetector);

XRAPI_ATTR XrResult XRAPI_CALL SnapshotMarkerDetectorML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerDetectorSnapshotInfoML*             snapshotInfo);

XRAPI_ATTR XrResult XRAPI_CALL GetMarkerDetectorStateML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerDetectorStateML*                    state);

XRAPI_ATTR XrResult XRAPI_CALL GetMarkersML(
    XrMarkerDetectorML                          markerDetector,
    uint32_t                                    markerCapacityInput,
    uint32_t*                                   markerCountOutput,
    XrMarkerML*                                 markers);

XRAPI_ATTR XrResult XRAPI_CALL GetMarkerReprojectionErrorML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    float*                                      reprojectionErrorMeters);

XRAPI_ATTR XrResult XRAPI_CALL GetMarkerLengthML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    float*                                      meters);

XRAPI_ATTR XrResult XRAPI_CALL GetMarkerNumberML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    uint64_t*                                   number);

XRAPI_ATTR XrResult XRAPI_CALL GetMarkerStringML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL CreateMarkerSpaceML(
    XrSession                                   session,
    const XrMarkerSpaceCreateInfoML*            createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL EnableLocalizationEventsML(
    XrSession                                   session,
    const XrLocalizationEnableEventsInfoML *    info);

XRAPI_ATTR XrResult XRAPI_CALL QueryLocalizationMapsML(
    XrSession                                   session,
    const XrLocalizationMapQueryInfoBaseHeaderML* queryInfo,
    uint32_t                                    mapCapacityInput,
    uint32_t *                                  mapCountOutput,
    XrLocalizationMapML*                        maps);

XRAPI_ATTR XrResult XRAPI_CALL RequestMapLocalizationML(
    XrSession                                   session,
    const XrMapLocalizationRequestInfoML*       requestInfo);

XRAPI_ATTR XrResult XRAPI_CALL ImportLocalizationMapML(
    XrSession                                   session,
    const XrLocalizationMapImportInfoML*        importInfo,
    XrUuidEXT*                                  mapUuid);

XRAPI_ATTR XrResult XRAPI_CALL CreateExportedLocalizationMapML(
    XrSession                                   session,
    const XrUuidEXT*                            mapUuid,
    XrExportedLocalizationMapML*                map);

XRAPI_ATTR XrResult XRAPI_CALL DestroyExportedLocalizationMapML(
    XrExportedLocalizationMapML                 map);

XRAPI_ATTR XrResult XRAPI_CALL GetExportedLocalizationMapDataML(
    XrExportedLocalizationMapML                 map,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorStoreConnectionMSFT(
    XrSession                                   session,
    XrSpatialAnchorStoreConnectionMSFT*         spatialAnchorStore);

XRAPI_ATTR XrResult XRAPI_CALL DestroySpatialAnchorStoreConnectionMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore);

XRAPI_ATTR XrResult XRAPI_CALL PersistSpatialAnchorMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore,
    const XrSpatialAnchorPersistenceInfoMSFT*   spatialAnchorPersistenceInfo);

XRAPI_ATTR XrResult XRAPI_CALL EnumeratePersistedSpatialAnchorNamesMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore,
    uint32_t                                    spatialAnchorNameCapacityInput,
    uint32_t*                                   spatialAnchorNameCountOutput,
    XrSpatialAnchorPersistenceNameMSFT*         spatialAnchorNames);

XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorFromPersistedNameMSFT(
    XrSession                                   session,
    const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* spatialAnchorCreateInfo,
    XrSpatialAnchorMSFT*                        spatialAnchor);

XRAPI_ATTR XrResult XRAPI_CALL UnpersistSpatialAnchorMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore,
    const XrSpatialAnchorPersistenceNameMSFT*   spatialAnchorPersistenceName);

XRAPI_ATTR XrResult XRAPI_CALL ClearSpatialAnchorStoreMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore);

XRAPI_ATTR XrResult XRAPI_CALL GetSceneMarkerRawDataMSFT(
    XrSceneMSFT                                 scene,
    const XrUuidMSFT*                           markerId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    uint8_t*                                    buffer);

XRAPI_ATTR XrResult XRAPI_CALL GetSceneMarkerDecodedStringMSFT(
    XrSceneMSFT                                 scene,
    const XrUuidMSFT*                           markerId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL QuerySpacesFB(
    XrSession                                   session,
    const XrSpaceQueryInfoBaseHeaderFB*         info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL RetrieveSpaceQueryResultsFB(
    XrSession                                   session,
    XrAsyncRequestIdFB                          requestId,
    XrSpaceQueryResultsFB*                      results);

XRAPI_ATTR XrResult XRAPI_CALL SaveSpaceFB(
    XrSession                                   session,
    const XrSpaceSaveInfoFB*                    info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL EraseSpaceFB(
    XrSession                                   session,
    const XrSpaceEraseInfoFB*                   info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL GetAudioOutputDeviceGuidOculus(
    XrInstance                                  instance,
    wchar_t                                     buffer[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]);

XRAPI_ATTR XrResult XRAPI_CALL GetAudioInputDeviceGuidOculus(
    XrInstance                                  instance,
    wchar_t                                     buffer[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]);

XRAPI_ATTR XrResult XRAPI_CALL ShareSpacesFB(
    XrSession                                   session,
    const XrSpaceShareInfoFB*                   info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL GetSpaceBoundingBox2DFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrRect2Df*                                  boundingBox2DOutput);

XRAPI_ATTR XrResult XRAPI_CALL GetSpaceBoundingBox3DFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrRect3DfFB*                                boundingBox3DOutput);

XRAPI_ATTR XrResult XRAPI_CALL GetSpaceSemanticLabelsFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrSemanticLabelsFB*                         semanticLabelsOutput);

XRAPI_ATTR XrResult XRAPI_CALL GetSpaceBoundary2DFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrBoundary2DFB*                             boundary2DOutput);

XRAPI_ATTR XrResult XRAPI_CALL GetSpaceRoomLayoutFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrRoomLayoutFB*                             roomLayoutOutput);

XRAPI_ATTR XrResult XRAPI_CALL SetDigitalLensControlALMALENCE(
    XrSession                                   session,
    const XrDigitalLensControlALMALENCE*        digitalLensControl);

XRAPI_ATTR XrResult XRAPI_CALL RequestSceneCaptureFB(
    XrSession                                   session,
    const XrSceneCaptureRequestInfoFB*          info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL GetSpaceContainerFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrSpaceContainerFB*                         spaceContainerOutput);

XRAPI_ATTR XrResult XRAPI_CALL GetFoveationEyeTrackedStateMETA(
    XrSession                                   session,
    XrFoveationEyeTrackedStateMETA*             foveationState);

XRAPI_ATTR XrResult XRAPI_CALL CreateFaceTrackerFB(
    XrSession                                   session,
    const XrFaceTrackerCreateInfoFB*            createInfo,
    XrFaceTrackerFB*                            faceTracker);

XRAPI_ATTR XrResult XRAPI_CALL DestroyFaceTrackerFB(
    XrFaceTrackerFB                             faceTracker);

XRAPI_ATTR XrResult XRAPI_CALL GetFaceExpressionWeightsFB(
    XrFaceTrackerFB                             faceTracker,
    const XrFaceExpressionInfoFB*               expressionInfo,
    XrFaceExpressionWeightsFB*                  expressionWeights);

XRAPI_ATTR XrResult XRAPI_CALL CreateEyeTrackerFB(
    XrSession                                   session,
    const XrEyeTrackerCreateInfoFB*             createInfo,
    XrEyeTrackerFB*                             eyeTracker);

XRAPI_ATTR XrResult XRAPI_CALL DestroyEyeTrackerFB(
    XrEyeTrackerFB                              eyeTracker);

XRAPI_ATTR XrResult XRAPI_CALL GetEyeGazesFB(
    XrEyeTrackerFB                              eyeTracker,
    const XrEyeGazesInfoFB*                     gazeInfo,
    XrEyeGazesFB*                               eyeGazes);

XRAPI_ATTR XrResult XRAPI_CALL PassthroughLayerSetKeyboardHandsIntensityFB(
    XrPassthroughLayerFB                        layer,
    const XrPassthroughKeyboardHandsIntensityFB* intensity);

XRAPI_ATTR XrResult XRAPI_CALL GetDeviceSampleRateFB(
    XrSession                                   session,
    const XrHapticActionInfo*                   hapticActionInfo,
    XrDevicePcmSampleRateGetInfoFB*             deviceSampleRate);

XRAPI_ATTR XrResult XRAPI_CALL GetPassthroughPreferencesMETA(
    XrSession                                   session,
    XrPassthroughPreferencesMETA*               preferences);

XRAPI_ATTR XrResult XRAPI_CALL CreateVirtualKeyboardMETA(
    XrSession                                   session,
    const XrVirtualKeyboardCreateInfoMETA*      createInfo,
    XrVirtualKeyboardMETA*                      keyboard);

XRAPI_ATTR XrResult XRAPI_CALL DestroyVirtualKeyboardMETA(
    XrVirtualKeyboardMETA                       keyboard);

XRAPI_ATTR XrResult XRAPI_CALL CreateVirtualKeyboardSpaceMETA(
    XrSession                                   session,
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardSpaceCreateInfoMETA* createInfo,
    XrSpace*                                    keyboardSpace);

XRAPI_ATTR XrResult XRAPI_CALL SuggestVirtualKeyboardLocationMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardLocationInfoMETA*    locationInfo);

XRAPI_ATTR XrResult XRAPI_CALL GetVirtualKeyboardScaleMETA(
    XrVirtualKeyboardMETA                       keyboard,
    float*                                      scale);

XRAPI_ATTR XrResult XRAPI_CALL SetVirtualKeyboardModelVisibilityMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardModelVisibilitySetInfoMETA* modelVisibility);

XRAPI_ATTR XrResult XRAPI_CALL GetVirtualKeyboardModelAnimationStatesMETA(
    XrVirtualKeyboardMETA                       keyboard,
    XrVirtualKeyboardModelAnimationStatesMETA*  animationStates);

XRAPI_ATTR XrResult XRAPI_CALL GetVirtualKeyboardDirtyTexturesMETA(
    XrVirtualKeyboardMETA                       keyboard,
    uint32_t                                    textureIdCapacityInput,
    uint32_t*                                   textureIdCountOutput,
    uint64_t*                                   textureIds);

XRAPI_ATTR XrResult XRAPI_CALL GetVirtualKeyboardTextureDataMETA(
    XrVirtualKeyboardMETA                       keyboard,
    uint64_t                                    textureId,
    XrVirtualKeyboardTextureDataMETA*           textureData);

XRAPI_ATTR XrResult XRAPI_CALL SendVirtualKeyboardInputMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardInputInfoMETA*       info,
    XrPosef*                                    interactorRootPose);

XRAPI_ATTR XrResult XRAPI_CALL ChangeVirtualKeyboardTextContextMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardTextContextChangeInfoMETA* changeInfo);

XRAPI_ATTR XrResult XRAPI_CALL EnumerateExternalCamerasOCULUS(
    XrSession                                   session,
    uint32_t                                    cameraCapacityInput,
    uint32_t*                                   cameraCountOutput,
    XrExternalCameraOCULUS*                     cameras);

XRAPI_ATTR XrResult XRAPI_CALL EnumeratePerformanceMetricsCounterPathsMETA(
    XrInstance                                  instance,
    uint32_t                                    counterPathCapacityInput,
    uint32_t*                                   counterPathCountOutput,
    XrPath*                                     counterPaths);

XRAPI_ATTR XrResult XRAPI_CALL SetPerformanceMetricsStateMETA(
    XrSession                                   session,
    const XrPerformanceMetricsStateMETA*        state);

XRAPI_ATTR XrResult XRAPI_CALL GetPerformanceMetricsStateMETA(
    XrSession                                   session,
    XrPerformanceMetricsStateMETA*              state);

XRAPI_ATTR XrResult XRAPI_CALL QueryPerformanceMetricsCounterMETA(
    XrSession                                   session,
    XrPath                                      counterPath,
    XrPerformanceMetricsCounterMETA*            counter);

XRAPI_ATTR XrResult XRAPI_CALL SaveSpaceListFB(
    XrSession                                   session,
    const XrSpaceListSaveInfoFB*                info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL CreateSpaceUserFB(
    XrSession                                   session,
    const XrSpaceUserCreateInfoFB*              info,
    XrSpaceUserFB*                              user);

XRAPI_ATTR XrResult XRAPI_CALL GetSpaceUserIdFB(
    XrSpaceUserFB                               user,
    XrSpaceUserIdFB*                            userId);

XRAPI_ATTR XrResult XRAPI_CALL DestroySpaceUserFB(
    XrSpaceUserFB                               user);

XRAPI_ATTR XrResult XRAPI_CALL GetRecommendedLayerResolutionMETA(
    XrSession                                   session,
    const XrRecommendedLayerResolutionGetInfoMETA* info,
    XrRecommendedLayerResolutionMETA*           resolution);

XRAPI_ATTR XrResult XRAPI_CALL CreatePassthroughColorLutMETA(
    XrPassthroughFB                             passthrough,
    const XrPassthroughColorLutCreateInfoMETA*  createInfo,
    XrPassthroughColorLutMETA*                  colorLut);

XRAPI_ATTR XrResult XRAPI_CALL DestroyPassthroughColorLutMETA(
    XrPassthroughColorLutMETA                   colorLut);

XRAPI_ATTR XrResult XRAPI_CALL UpdatePassthroughColorLutMETA(
    XrPassthroughColorLutMETA                   colorLut,
    const XrPassthroughColorLutUpdateInfoMETA*  updateInfo);

XRAPI_ATTR XrResult XRAPI_CALL GetSpaceTriangleMeshMETA(
    XrSpace                                     space,
    const XrSpaceTriangleMeshGetInfoMETA*       getInfo,
    XrSpaceTriangleMeshMETA*                    triangleMeshOutput);

XRAPI_ATTR XrResult XRAPI_CALL CreateFaceTracker2FB(
    XrSession                                   session,
    const XrFaceTrackerCreateInfo2FB*           createInfo,
    XrFaceTracker2FB*                           faceTracker);

XRAPI_ATTR XrResult XRAPI_CALL DestroyFaceTracker2FB(
    XrFaceTracker2FB                            faceTracker);

XRAPI_ATTR XrResult XRAPI_CALL GetFaceExpressionWeights2FB(
    XrFaceTracker2FB                            faceTracker,
    const XrFaceExpressionInfo2FB*              expressionInfo,
    XrFaceExpressionWeights2FB*                 expressionWeights);

XRAPI_ATTR XrResult XRAPI_CALL SetTrackingOptimizationSettingsHintQCOM(
    XrSession                                   session,
    XrTrackingOptimizationSettingsDomainQCOM    domain,
    XrTrackingOptimizationSettingsHintQCOM      hint);

XRAPI_ATTR XrResult XRAPI_CALL CreatePassthroughHTC(
    XrSession                                   session,
    const XrPassthroughCreateInfoHTC*           createInfo,
    XrPassthroughHTC*                           passthrough);

XRAPI_ATTR XrResult XRAPI_CALL DestroyPassthroughHTC(
    XrPassthroughHTC                            passthrough);

XRAPI_ATTR XrResult XRAPI_CALL ApplyFoveationHTC(
    XrSession                                   session,
    const XrFoveationApplyInfoHTC*              applyInfo);

XRAPI_ATTR XrResult XRAPI_CALL CreateSpatialAnchorHTC(
    XrSession                                   session,
    const XrSpatialAnchorCreateInfoHTC*         createInfo,
    XrSpace*                                    anchor);

XRAPI_ATTR XrResult XRAPI_CALL GetSpatialAnchorNameHTC(
    XrSpace                                     anchor,
    XrSpatialAnchorNameHTC*                     name);

XRAPI_ATTR XrResult XRAPI_CALL ApplyForceFeedbackCurlMNDX(
    XrHandTrackerEXT                            handTracker,
    const XrForceFeedbackCurlApplyLocationsMNDX* locations);

XRAPI_ATTR XrResult XRAPI_CALL CreatePlaneDetectorEXT(
    XrSession                                   session,
    const XrPlaneDetectorCreateInfoEXT*         createInfo,
    XrPlaneDetectorEXT*                         planeDetector);

XRAPI_ATTR XrResult XRAPI_CALL DestroyPlaneDetectorEXT(
    XrPlaneDetectorEXT                          planeDetector);

XRAPI_ATTR XrResult XRAPI_CALL BeginPlaneDetectionEXT(
    XrPlaneDetectorEXT                          planeDetector,
    const XrPlaneDetectorBeginInfoEXT*          beginInfo);

XRAPI_ATTR XrResult XRAPI_CALL GetPlaneDetectionStateEXT(
    XrPlaneDetectorEXT                          planeDetector,
    XrPlaneDetectionStateEXT*                   state);

XRAPI_ATTR XrResult XRAPI_CALL GetPlaneDetectionsEXT(
    XrPlaneDetectorEXT                          planeDetector,
    const XrPlaneDetectorGetInfoEXT*            info,
    XrPlaneDetectorLocationsEXT*                locations);

XRAPI_ATTR XrResult XRAPI_CALL GetPlanePolygonBufferEXT(
    XrPlaneDetectorEXT                          planeDetector,
    uint64_t                                    planeId,
    uint32_t                                    polygonBufferIndex,
    XrPlaneDetectorPolygonBufferEXT*            polygonBuffer);

XRAPI_ATTR XrResult XRAPI_CALL EnableUserCalibrationEventsML(
    XrInstance                                  instance,
    const XrUserCalibrationEnableEventsInfoML*  enableInfo);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_API_CALL_ENCODERS_H
