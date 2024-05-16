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

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyInstance(
    XrInstance                                  instance);

XRAPI_ATTR XrResult XRAPI_CALL xrGetInstanceProperties(
    XrInstance                                  instance,
    XrInstanceProperties*                       instanceProperties);

XRAPI_ATTR XrResult XRAPI_CALL xrPollEvent(
    XrInstance                                  instance,
    XrEventDataBuffer*                          eventData);

XRAPI_ATTR XrResult XRAPI_CALL xrResultToString(
    XrInstance                                  instance,
    XrResult                                    value,
    char                                        buffer[XR_MAX_RESULT_STRING_SIZE]);

XRAPI_ATTR XrResult XRAPI_CALL xrStructureTypeToString(
    XrInstance                                  instance,
    XrStructureType                             value,
    char                                        buffer[XR_MAX_STRUCTURE_NAME_SIZE]);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSystem(
    XrInstance                                  instance,
    const XrSystemGetInfo*                      getInfo,
    XrSystemId*                                 systemId);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSystemProperties(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrSystemProperties*                         properties);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateEnvironmentBlendModes(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    environmentBlendModeCapacityInput,
    uint32_t*                                   environmentBlendModeCountOutput,
    XrEnvironmentBlendMode*                     environmentBlendModes);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSession(
    XrInstance                                  instance,
    const XrSessionCreateInfo*                  createInfo,
    XrSession*                                  session);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySession(
    XrSession                                   session);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateReferenceSpaces(
    XrSession                                   session,
    uint32_t                                    spaceCapacityInput,
    uint32_t*                                   spaceCountOutput,
    XrReferenceSpaceType*                       spaces);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateReferenceSpace(
    XrSession                                   session,
    const XrReferenceSpaceCreateInfo*           createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL xrGetReferenceSpaceBoundsRect(
    XrSession                                   session,
    XrReferenceSpaceType                        referenceSpaceType,
    XrExtent2Df*                                bounds);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateActionSpace(
    XrSession                                   session,
    const XrActionSpaceCreateInfo*              createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL xrLocateSpace(
    XrSpace                                     space,
    XrSpace                                     baseSpace,
    XrTime                                      time,
    XrSpaceLocation*                            location);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpace(
    XrSpace                                     space);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateViewConfigurations(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    viewConfigurationTypeCapacityInput,
    uint32_t*                                   viewConfigurationTypeCountOutput,
    XrViewConfigurationType*                    viewConfigurationTypes);

XRAPI_ATTR XrResult XRAPI_CALL xrGetViewConfigurationProperties(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    XrViewConfigurationProperties*              configurationProperties);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateViewConfigurationViews(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewCapacityInput,
    uint32_t*                                   viewCountOutput,
    XrViewConfigurationView*                    views);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSwapchainFormats(
    XrSession                                   session,
    uint32_t                                    formatCapacityInput,
    uint32_t*                                   formatCountOutput,
    int64_t*                                    formats);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSwapchain(
    XrSession                                   session,
    const XrSwapchainCreateInfo*                createInfo,
    XrSwapchain*                                swapchain);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySwapchain(
    XrSwapchain                                 swapchain);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSwapchainImages(
    XrSwapchain                                 swapchain,
    uint32_t                                    imageCapacityInput,
    uint32_t*                                   imageCountOutput,
    XrSwapchainImageBaseHeader*                 images);

XRAPI_ATTR XrResult XRAPI_CALL xrAcquireSwapchainImage(
    XrSwapchain                                 swapchain,
    const XrSwapchainImageAcquireInfo*          acquireInfo,
    uint32_t*                                   index);

XRAPI_ATTR XrResult XRAPI_CALL xrWaitSwapchainImage(
    XrSwapchain                                 swapchain,
    const XrSwapchainImageWaitInfo*             waitInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrReleaseSwapchainImage(
    XrSwapchain                                 swapchain,
    const XrSwapchainImageReleaseInfo*          releaseInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrBeginSession(
    XrSession                                   session,
    const XrSessionBeginInfo*                   beginInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrEndSession(
    XrSession                                   session);

XRAPI_ATTR XrResult XRAPI_CALL xrRequestExitSession(
    XrSession                                   session);

XRAPI_ATTR XrResult XRAPI_CALL xrWaitFrame(
    XrSession                                   session,
    const XrFrameWaitInfo*                      frameWaitInfo,
    XrFrameState*                               frameState);

XRAPI_ATTR XrResult XRAPI_CALL xrBeginFrame(
    XrSession                                   session,
    const XrFrameBeginInfo*                     frameBeginInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrLocateViews(
    XrSession                                   session,
    const XrViewLocateInfo*                     viewLocateInfo,
    XrViewState*                                viewState,
    uint32_t                                    viewCapacityInput,
    uint32_t*                                   viewCountOutput,
    XrView*                                     views);

XRAPI_ATTR XrResult XRAPI_CALL xrStringToPath(
    XrInstance                                  instance,
    const char*                                 pathString,
    XrPath*                                     path);

XRAPI_ATTR XrResult XRAPI_CALL xrPathToString(
    XrInstance                                  instance,
    XrPath                                      path,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateActionSet(
    XrInstance                                  instance,
    const XrActionSetCreateInfo*                createInfo,
    XrActionSet*                                actionSet);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyActionSet(
    XrActionSet                                 actionSet);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateAction(
    XrActionSet                                 actionSet,
    const XrActionCreateInfo*                   createInfo,
    XrAction*                                   action);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyAction(
    XrAction                                    action);

XRAPI_ATTR XrResult XRAPI_CALL xrSuggestInteractionProfileBindings(
    XrInstance                                  instance,
    const XrInteractionProfileSuggestedBinding* suggestedBindings);

XRAPI_ATTR XrResult XRAPI_CALL xrAttachSessionActionSets(
    XrSession                                   session,
    const XrSessionActionSetsAttachInfo*        attachInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrGetCurrentInteractionProfile(
    XrSession                                   session,
    XrPath                                      topLevelUserPath,
    XrInteractionProfileState*                  interactionProfile);

XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStateBoolean(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStateBoolean*                       state);

XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStateFloat(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStateFloat*                         state);

XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStateVector2f(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStateVector2f*                      state);

XRAPI_ATTR XrResult XRAPI_CALL xrGetActionStatePose(
    XrSession                                   session,
    const XrActionStateGetInfo*                 getInfo,
    XrActionStatePose*                          state);

XRAPI_ATTR XrResult XRAPI_CALL xrSyncActions(
    XrSession                                   session,
    const XrActionsSyncInfo*                    syncInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateBoundSourcesForAction(
    XrSession                                   session,
    const XrBoundSourcesForActionEnumerateInfo* enumerateInfo,
    uint32_t                                    sourceCapacityInput,
    uint32_t*                                   sourceCountOutput,
    XrPath*                                     sources);

XRAPI_ATTR XrResult XRAPI_CALL xrGetInputSourceLocalizedName(
    XrSession                                   session,
    const XrInputSourceLocalizedNameGetInfo*    getInfo,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrApplyHapticFeedback(
    XrSession                                   session,
    const XrHapticActionInfo*                   hapticActionInfo,
    const XrHapticBaseHeader*                   hapticFeedback);

XRAPI_ATTR XrResult XRAPI_CALL xrStopHapticFeedback(
    XrSession                                   session,
    const XrHapticActionInfo*                   hapticActionInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateApiLayerInstance(
    const XrInstanceCreateInfo*                 info,
    const XrApiLayerCreateInfo*                 layerInfo,
    XrInstance*                                 instance);

XRAPI_ATTR XrResult XRAPI_CALL xrSetAndroidApplicationThreadKHR(
    XrSession                                   session,
    XrAndroidThreadTypeKHR                      threadType,
    uint32_t                                    threadId);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSwapchainAndroidSurfaceKHR(
    XrSession                                   session,
    const XrSwapchainCreateInfo*                info,
    XrSwapchain*                                swapchain,
    jobject*                                    surface);

XRAPI_ATTR XrResult XRAPI_CALL xrGetOpenGLGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsOpenGLKHR*            graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL xrGetOpenGLESGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsOpenGLESKHR*          graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanInstanceExtensionsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanDeviceExtensionsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsDeviceKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    VkInstance                                  vkInstance,
    VkPhysicalDevice*                           vkPhysicalDevice);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsVulkanKHR*            graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL xrGetD3D11GraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsD3D11KHR*             graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL xrGetD3D12GraphicsRequirementsKHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsD3D12KHR*             graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVisibilityMaskKHR(
    XrSession                                   session,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    viewIndex,
    XrVisibilityMaskTypeKHR                     visibilityMaskType,
    XrVisibilityMaskKHR*                        visibilityMask);

XRAPI_ATTR XrResult XRAPI_CALL xrConvertWin32PerformanceCounterToTimeKHR(
    XrInstance                                  instance,
    const LARGE_INTEGER*                        performanceCounter,
    XrTime*                                     time);

XRAPI_ATTR XrResult XRAPI_CALL xrConvertTimeToWin32PerformanceCounterKHR(
    XrInstance                                  instance,
    XrTime                                      time,
    LARGE_INTEGER*                              performanceCounter);

XRAPI_ATTR XrResult XRAPI_CALL xrConvertTimespecTimeToTimeKHR(
    XrInstance                                  instance,
    const struct timespec*                      timespecTime,
    XrTime*                                     time);

XRAPI_ATTR XrResult XRAPI_CALL xrConvertTimeToTimespecTimeKHR(
    XrInstance                                  instance,
    XrTime                                      time,
    struct timespec*                            timespecTime);


XRAPI_ATTR XrResult XRAPI_CALL xrCreateVulkanInstanceKHR(
    XrInstance                                  instance,
    const XrVulkanInstanceCreateInfoKHR*        createInfo,
    VkInstance*                                 vulkanInstance,
    VkResult*                                   vulkanResult);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateVulkanDeviceKHR(
    XrInstance                                  instance,
    const XrVulkanDeviceCreateInfoKHR*          createInfo,
    VkDevice*                                   vulkanDevice,
    VkResult*                                   vulkanResult);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsDevice2KHR(
    XrInstance                                  instance,
    const XrVulkanGraphicsDeviceGetInfoKHR*     getInfo,
    VkPhysicalDevice*                           vulkanPhysicalDevice);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVulkanGraphicsRequirements2KHR(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrGraphicsRequirementsVulkanKHR*            graphicsRequirements);

XRAPI_ATTR XrResult XRAPI_CALL xrPerfSettingsSetPerformanceLevelEXT(
    XrSession                                   session,
    XrPerfSettingsDomainEXT                     domain,
    XrPerfSettingsLevelEXT                      level);

XRAPI_ATTR XrResult XRAPI_CALL xrThermalGetTemperatureTrendEXT(
    XrSession                                   session,
    XrPerfSettingsDomainEXT                     domain,
    XrPerfSettingsNotificationLevelEXT*         notificationLevel,
    float*                                      tempHeadroom,
    float*                                      tempSlope);

XRAPI_ATTR XrResult XRAPI_CALL xrSetDebugUtilsObjectNameEXT(
    XrInstance                                  instance,
    const XrDebugUtilsObjectNameInfoEXT*        nameInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateDebugUtilsMessengerEXT(
    XrInstance                                  instance,
    const XrDebugUtilsMessengerCreateInfoEXT*   createInfo,
    XrDebugUtilsMessengerEXT*                   messenger);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyDebugUtilsMessengerEXT(
    XrDebugUtilsMessengerEXT                    messenger);

XRAPI_ATTR XrResult                                    XRAPI_CALL xrSubmitDebugUtilsMessageEXT(
    XrInstance                                  instance,
    XrDebugUtilsMessageSeverityFlagsEXT         messageSeverity,
    XrDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const XrDebugUtilsMessengerCallbackDataEXT* callbackData);

XRAPI_ATTR XrResult XRAPI_CALL xrSessionBeginDebugUtilsLabelRegionEXT(
    XrSession                                   session,
    const XrDebugUtilsLabelEXT*                 labelInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrSessionEndDebugUtilsLabelRegionEXT(
    XrSession                                   session);

XRAPI_ATTR XrResult XRAPI_CALL xrSessionInsertDebugUtilsLabelEXT(
    XrSession                                   session,
    const XrDebugUtilsLabelEXT*                 labelInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorMSFT(
    XrSession                                   session,
    const XrSpatialAnchorCreateInfoMSFT*        createInfo,
    XrSpatialAnchorMSFT*                        anchor);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorSpaceMSFT(
    XrSession                                   session,
    const XrSpatialAnchorSpaceCreateInfoMSFT*   createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpatialAnchorMSFT(
    XrSpatialAnchorMSFT                         anchor);

XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceActiveEXT(
    XrSession                                   session,
    XrPath                                      interactionProfile,
    XrPath                                      topLevelPath,
    XrBool32                                    isActive);

XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceStateBoolEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    XrBool32                                    state);

XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceStateFloatEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    float                                       state);

XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceStateVector2fEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    XrVector2f                                  state);

XRAPI_ATTR XrResult XRAPI_CALL xrSetInputDeviceLocationEXT(
    XrSession                                   session,
    XrPath                                      topLevelPath,
    XrPath                                      inputSourcePath,
    XrSpace                                     space,
    XrPosef                                     pose);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialGraphNodeSpaceMSFT(
    XrSession                                   session,
    const XrSpatialGraphNodeSpaceCreateInfoMSFT* createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL xrTryCreateSpatialGraphStaticNodeBindingMSFT(
    XrSession                                   session,
    const XrSpatialGraphStaticNodeBindingCreateInfoMSFT* createInfo,
    XrSpatialGraphNodeBindingMSFT*              nodeBinding);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpatialGraphNodeBindingMSFT(
    XrSpatialGraphNodeBindingMSFT               nodeBinding);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpatialGraphNodeBindingPropertiesMSFT(
    XrSpatialGraphNodeBindingMSFT               nodeBinding,
    const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* getInfo,
    XrSpatialGraphNodeBindingPropertiesMSFT*    properties);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateHandTrackerEXT(
    XrSession                                   session,
    const XrHandTrackerCreateInfoEXT*           createInfo,
    XrHandTrackerEXT*                           handTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyHandTrackerEXT(
    XrHandTrackerEXT                            handTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrLocateHandJointsEXT(
    XrHandTrackerEXT                            handTracker,
    const XrHandJointsLocateInfoEXT*            locateInfo,
    XrHandJointLocationsEXT*                    locations);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateHandMeshSpaceMSFT(
    XrHandTrackerEXT                            handTracker,
    const XrHandMeshSpaceCreateInfoMSFT*        createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL xrUpdateHandMeshMSFT(
    XrHandTrackerEXT                            handTracker,
    const XrHandMeshUpdateInfoMSFT*             updateInfo,
    XrHandMeshMSFT*                             handMesh);

XRAPI_ATTR XrResult XRAPI_CALL xrGetControllerModelKeyMSFT(
    XrSession                                   session,
    XrPath                                      topLevelUserPath,
    XrControllerModelKeyStateMSFT*              controllerModelKeyState);

XRAPI_ATTR XrResult XRAPI_CALL xrLoadControllerModelMSFT(
    XrSession                                   session,
    XrControllerModelKeyMSFT                    modelKey,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    uint8_t*                                    buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrGetControllerModelPropertiesMSFT(
    XrSession                                   session,
    XrControllerModelKeyMSFT                    modelKey,
    XrControllerModelPropertiesMSFT*            properties);

XRAPI_ATTR XrResult XRAPI_CALL xrGetControllerModelStateMSFT(
    XrSession                                   session,
    XrControllerModelKeyMSFT                    modelKey,
    XrControllerModelStateMSFT*                 state);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorFromPerceptionAnchorMSFT(
    XrSession                                   session,
    IUnknown*                                   perceptionAnchor,
    XrSpatialAnchorMSFT*                        anchor);

XRAPI_ATTR XrResult XRAPI_CALL xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(
    XrSession                                   session,
    XrSpatialAnchorMSFT                         anchor,
    IUnknown**                                  perceptionAnchor);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateReprojectionModesMSFT(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    XrViewConfigurationType                     viewConfigurationType,
    uint32_t                                    modeCapacityInput,
    uint32_t*                                   modeCountOutput,
    XrReprojectionModeMSFT*                     modes);

XRAPI_ATTR XrResult XRAPI_CALL xrUpdateSwapchainFB(
    XrSwapchain                                 swapchain,
    const XrSwapchainStateBaseHeaderFB*         state);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSwapchainStateFB(
    XrSwapchain                                 swapchain,
    XrSwapchainStateBaseHeaderFB*               state);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateBodyTrackerFB(
    XrSession                                   session,
    const XrBodyTrackerCreateInfoFB*            createInfo,
    XrBodyTrackerFB*                            bodyTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyBodyTrackerFB(
    XrBodyTrackerFB                             bodyTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrLocateBodyJointsFB(
    XrBodyTrackerFB                             bodyTracker,
    const XrBodyJointsLocateInfoFB*             locateInfo,
    XrBodyJointLocationsFB*                     locations);

XRAPI_ATTR XrResult XRAPI_CALL xrGetBodySkeletonFB(
    XrBodyTrackerFB                             bodyTracker,
    XrBodySkeletonFB*                           skeleton);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSceneComputeFeaturesMSFT(
    XrInstance                                  instance,
    XrSystemId                                  systemId,
    uint32_t                                    featureCapacityInput,
    uint32_t*                                   featureCountOutput,
    XrSceneComputeFeatureMSFT*                  features);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSceneObserverMSFT(
    XrSession                                   session,
    const XrSceneObserverCreateInfoMSFT*        createInfo,
    XrSceneObserverMSFT*                        sceneObserver);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySceneObserverMSFT(
    XrSceneObserverMSFT                         sceneObserver);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrSceneCreateInfoMSFT*                createInfo,
    XrSceneMSFT*                                scene);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySceneMSFT(
    XrSceneMSFT                                 scene);

XRAPI_ATTR XrResult XRAPI_CALL xrComputeNewSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrNewSceneComputeInfoMSFT*            computeInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneComputeStateMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    XrSceneComputeStateMSFT*                    state);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneComponentsMSFT(
    XrSceneMSFT                                 scene,
    const XrSceneComponentsGetInfoMSFT*         getInfo,
    XrSceneComponentsMSFT*                      components);

XRAPI_ATTR XrResult XRAPI_CALL xrLocateSceneComponentsMSFT(
    XrSceneMSFT                                 scene,
    const XrSceneComponentsLocateInfoMSFT*      locateInfo,
    XrSceneComponentLocationsMSFT*              locations);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneMeshBuffersMSFT(
    XrSceneMSFT                                 scene,
    const XrSceneMeshBuffersGetInfoMSFT*        getInfo,
    XrSceneMeshBuffersMSFT*                     buffers);

XRAPI_ATTR XrResult XRAPI_CALL xrDeserializeSceneMSFT(
    XrSceneObserverMSFT                         sceneObserver,
    const XrSceneDeserializeInfoMSFT*           deserializeInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSerializedSceneFragmentDataMSFT(
    XrSceneMSFT                                 scene,
    const XrSerializedSceneFragmentDataGetInfoMSFT* getInfo,
    uint32_t                                    countInput,
    uint32_t*                                   readOutput,
    uint8_t*                                    buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateDisplayRefreshRatesFB(
    XrSession                                   session,
    uint32_t                                    displayRefreshRateCapacityInput,
    uint32_t*                                   displayRefreshRateCountOutput,
    float*                                      displayRefreshRates);

XRAPI_ATTR XrResult XRAPI_CALL xrGetDisplayRefreshRateFB(
    XrSession                                   session,
    float*                                      displayRefreshRate);

XRAPI_ATTR XrResult XRAPI_CALL xrRequestDisplayRefreshRateFB(
    XrSession                                   session,
    float                                       displayRefreshRate);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateViveTrackerPathsHTCX(
    XrInstance                                  instance,
    uint32_t                                    pathCapacityInput,
    uint32_t*                                   pathCountOutput,
    XrViveTrackerPathsHTCX*                     paths);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateFacialTrackerHTC(
    XrSession                                   session,
    const XrFacialTrackerCreateInfoHTC*         createInfo,
    XrFacialTrackerHTC*                         facialTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFacialTrackerHTC(
    XrFacialTrackerHTC                          facialTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrGetFacialExpressionsHTC(
    XrFacialTrackerHTC                          facialTracker,
    XrFacialExpressionsHTC*                     facialExpressions);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateColorSpacesFB(
    XrSession                                   session,
    uint32_t                                    colorSpaceCapacityInput,
    uint32_t*                                   colorSpaceCountOutput,
    XrColorSpaceFB*                             colorSpaces);

XRAPI_ATTR XrResult XRAPI_CALL xrSetColorSpaceFB(
    XrSession                                   session,
    const XrColorSpaceFB                        colorSpace);

XRAPI_ATTR XrResult XRAPI_CALL xrGetHandMeshFB(
    XrHandTrackerEXT                            handTracker,
    XrHandTrackingMeshFB*                       mesh);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorFB(
    XrSession                                   session,
    const XrSpatialAnchorCreateInfoFB*          info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceUuidFB(
    XrSpace                                     space,
    XrUuidEXT*                                  uuid);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateSpaceSupportedComponentsFB(
    XrSpace                                     space,
    uint32_t                                    componentTypeCapacityInput,
    uint32_t*                                   componentTypeCountOutput,
    XrSpaceComponentTypeFB*                     componentTypes);

XRAPI_ATTR XrResult XRAPI_CALL xrSetSpaceComponentStatusFB(
    XrSpace                                     space,
    const XrSpaceComponentStatusSetInfoFB*      info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceComponentStatusFB(
    XrSpace                                     space,
    XrSpaceComponentTypeFB                      componentType,
    XrSpaceComponentStatusFB*                   status);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateFoveationProfileFB(
    XrSession                                   session,
    const XrFoveationProfileCreateInfoFB*       createInfo,
    XrFoveationProfileFB*                       profile);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFoveationProfileFB(
    XrFoveationProfileFB                        profile);

XRAPI_ATTR XrResult XRAPI_CALL xrQuerySystemTrackedKeyboardFB(
    XrSession                                   session,
    const XrKeyboardTrackingQueryFB*            queryInfo,
    XrKeyboardTrackingDescriptionFB*            keyboard);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateKeyboardSpaceFB(
    XrSession                                   session,
    const XrKeyboardSpaceCreateInfoFB*          createInfo,
    XrSpace*                                    keyboardSpace);

XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshBeginUpdateFB(
    XrTriangleMeshFB                            mesh);

XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshEndUpdateFB(
    XrTriangleMeshFB                            mesh,
    uint32_t                                    vertexCount,
    uint32_t                                    triangleCount);

XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshBeginVertexBufferUpdateFB(
    XrTriangleMeshFB                            mesh,
    uint32_t*                                   outVertexCount);

XRAPI_ATTR XrResult XRAPI_CALL xrTriangleMeshEndVertexBufferUpdateFB(
    XrTriangleMeshFB                            mesh);

XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughFB(
    XrSession                                   session,
    const XrPassthroughCreateInfoFB*            createInfo,
    XrPassthroughFB*                            outPassthrough);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughFB(
    XrPassthroughFB                             passthrough);

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughStartFB(
    XrPassthroughFB                             passthrough);

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughPauseFB(
    XrPassthroughFB                             passthrough);

XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughLayerFB(
    XrSession                                   session,
    const XrPassthroughLayerCreateInfoFB*       createInfo,
    XrPassthroughLayerFB*                       outLayer);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughLayerFB(
    XrPassthroughLayerFB                        layer);

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerPauseFB(
    XrPassthroughLayerFB                        layer);

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerResumeFB(
    XrPassthroughLayerFB                        layer);

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerSetStyleFB(
    XrPassthroughLayerFB                        layer,
    const XrPassthroughStyleFB*                 style);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateGeometryInstanceFB(
    XrSession                                   session,
    const XrGeometryInstanceCreateInfoFB*       createInfo,
    XrGeometryInstanceFB*                       outGeometryInstance);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyGeometryInstanceFB(
    XrGeometryInstanceFB                        instance);

XRAPI_ATTR XrResult XRAPI_CALL xrGeometryInstanceSetTransformFB(
    XrGeometryInstanceFB                        instance,
    const XrGeometryInstanceTransformFB*        transformation);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateRenderModelPathsFB(
    XrSession                                   session,
    uint32_t                                    pathCapacityInput,
    uint32_t*                                   pathCountOutput,
    XrRenderModelPathInfoFB*                    paths);

XRAPI_ATTR XrResult XRAPI_CALL xrGetRenderModelPropertiesFB(
    XrSession                                   session,
    XrPath                                      path,
    XrRenderModelPropertiesFB*                  properties);

XRAPI_ATTR XrResult XRAPI_CALL xrLoadRenderModelFB(
    XrSession                                   session,
    const XrRenderModelLoadInfoFB*              info,
    XrRenderModelBufferFB*                      buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrSetEnvironmentDepthEstimationVARJO(
    XrSession                                   session,
    XrBool32                                    enabled);

XRAPI_ATTR XrResult  XRAPI_CALL xrSetMarkerTrackingVARJO(
    XrSession                                   session,
    XrBool32                                    enabled);

XRAPI_ATTR XrResult XRAPI_CALL xrSetMarkerTrackingTimeoutVARJO(
    XrSession                                   session,
    uint64_t                                    markerId,
    XrDuration                                  timeout);

XRAPI_ATTR XrResult XRAPI_CALL xrSetMarkerTrackingPredictionVARJO(
    XrSession                                   session,
    uint64_t                                    markerId,
    XrBool32                                    enable);

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerSizeVARJO(
    XrSession                                   session,
    uint64_t                                    markerId,
    XrExtent2Df*                                size);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateMarkerSpaceVARJO(
    XrSession                                   session,
    const XrMarkerSpaceCreateInfoVARJO*         createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult  XRAPI_CALL xrSetViewOffsetVARJO(
    XrSession                                   session,
    float                                       offset);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpaceFromCoordinateFrameUIDML(
    XrSession                                   session,
    const XrCoordinateSpaceCreateInfoML *       createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateMarkerDetectorML(
    XrSession                                   session,
    const XrMarkerDetectorCreateInfoML*         createInfo,
    XrMarkerDetectorML*                         markerDetector);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyMarkerDetectorML(
    XrMarkerDetectorML                          markerDetector);

XRAPI_ATTR XrResult XRAPI_CALL xrSnapshotMarkerDetectorML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerDetectorSnapshotInfoML*             snapshotInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerDetectorStateML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerDetectorStateML*                    state);

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkersML(
    XrMarkerDetectorML                          markerDetector,
    uint32_t                                    markerCapacityInput,
    uint32_t*                                   markerCountOutput,
    XrMarkerML*                                 markers);

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerReprojectionErrorML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    float*                                      reprojectionErrorMeters);

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerLengthML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    float*                                      meters);

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerNumberML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    uint64_t*                                   number);

XRAPI_ATTR XrResult XRAPI_CALL xrGetMarkerStringML(
    XrMarkerDetectorML                          markerDetector,
    XrMarkerML                                  marker,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateMarkerSpaceML(
    XrSession                                   session,
    const XrMarkerSpaceCreateInfoML*            createInfo,
    XrSpace*                                    space);

XRAPI_ATTR XrResult XRAPI_CALL xrEnableLocalizationEventsML(
    XrSession                                   session,
    const XrLocalizationEnableEventsInfoML *    info);

XRAPI_ATTR XrResult XRAPI_CALL xrQueryLocalizationMapsML(
    XrSession                                   session,
    const XrLocalizationMapQueryInfoBaseHeaderML* queryInfo,
    uint32_t                                    mapCapacityInput,
    uint32_t *                                  mapCountOutput,
    XrLocalizationMapML*                        maps);

XRAPI_ATTR XrResult XRAPI_CALL xrRequestMapLocalizationML(
    XrSession                                   session,
    const XrMapLocalizationRequestInfoML*       requestInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrImportLocalizationMapML(
    XrSession                                   session,
    const XrLocalizationMapImportInfoML*        importInfo,
    XrUuidEXT*                                  mapUuid);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateExportedLocalizationMapML(
    XrSession                                   session,
    const XrUuidEXT*                            mapUuid,
    XrExportedLocalizationMapML*                map);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyExportedLocalizationMapML(
    XrExportedLocalizationMapML                 map);

XRAPI_ATTR XrResult XRAPI_CALL xrGetExportedLocalizationMapDataML(
    XrExportedLocalizationMapML                 map,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorStoreConnectionMSFT(
    XrSession                                   session,
    XrSpatialAnchorStoreConnectionMSFT*         spatialAnchorStore);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpatialAnchorStoreConnectionMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore);

XRAPI_ATTR XrResult XRAPI_CALL xrPersistSpatialAnchorMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore,
    const XrSpatialAnchorPersistenceInfoMSFT*   spatialAnchorPersistenceInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumeratePersistedSpatialAnchorNamesMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore,
    uint32_t                                    spatialAnchorNameCapacityInput,
    uint32_t*                                   spatialAnchorNameCountOutput,
    XrSpatialAnchorPersistenceNameMSFT*         spatialAnchorNames);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorFromPersistedNameMSFT(
    XrSession                                   session,
    const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* spatialAnchorCreateInfo,
    XrSpatialAnchorMSFT*                        spatialAnchor);

XRAPI_ATTR XrResult XRAPI_CALL xrUnpersistSpatialAnchorMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore,
    const XrSpatialAnchorPersistenceNameMSFT*   spatialAnchorPersistenceName);

XRAPI_ATTR XrResult XRAPI_CALL xrClearSpatialAnchorStoreMSFT(
    XrSpatialAnchorStoreConnectionMSFT          spatialAnchorStore);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneMarkerRawDataMSFT(
    XrSceneMSFT                                 scene,
    const XrUuidMSFT*                           markerId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    uint8_t*                                    buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSceneMarkerDecodedStringMSFT(
    XrSceneMSFT                                 scene,
    const XrUuidMSFT*                           markerId,
    uint32_t                                    bufferCapacityInput,
    uint32_t*                                   bufferCountOutput,
    char*                                       buffer);

XRAPI_ATTR XrResult XRAPI_CALL xrQuerySpacesFB(
    XrSession                                   session,
    const XrSpaceQueryInfoBaseHeaderFB*         info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL xrRetrieveSpaceQueryResultsFB(
    XrSession                                   session,
    XrAsyncRequestIdFB                          requestId,
    XrSpaceQueryResultsFB*                      results);

XRAPI_ATTR XrResult XRAPI_CALL xrSaveSpaceFB(
    XrSession                                   session,
    const XrSpaceSaveInfoFB*                    info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL xrEraseSpaceFB(
    XrSession                                   session,
    const XrSpaceEraseInfoFB*                   info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL xrGetAudioOutputDeviceGuidOculus(
    XrInstance                                  instance,
    wchar_t                                     buffer[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]);

XRAPI_ATTR XrResult XRAPI_CALL xrGetAudioInputDeviceGuidOculus(
    XrInstance                                  instance,
    wchar_t                                     buffer[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]);

XRAPI_ATTR XrResult XRAPI_CALL xrShareSpacesFB(
    XrSession                                   session,
    const XrSpaceShareInfoFB*                   info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceBoundingBox2DFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrRect2Df*                                  boundingBox2DOutput);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceBoundingBox3DFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrRect3DfFB*                                boundingBox3DOutput);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceSemanticLabelsFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrSemanticLabelsFB*                         semanticLabelsOutput);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceBoundary2DFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrBoundary2DFB*                             boundary2DOutput);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceRoomLayoutFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrRoomLayoutFB*                             roomLayoutOutput);

XRAPI_ATTR XrResult XRAPI_CALL xrSetDigitalLensControlALMALENCE(
    XrSession                                   session,
    const XrDigitalLensControlALMALENCE*        digitalLensControl);

XRAPI_ATTR XrResult XRAPI_CALL xrRequestSceneCaptureFB(
    XrSession                                   session,
    const XrSceneCaptureRequestInfoFB*          info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceContainerFB(
    XrSession                                   session,
    XrSpace                                     space,
    XrSpaceContainerFB*                         spaceContainerOutput);

XRAPI_ATTR XrResult XRAPI_CALL xrGetFoveationEyeTrackedStateMETA(
    XrSession                                   session,
    XrFoveationEyeTrackedStateMETA*             foveationState);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateFaceTrackerFB(
    XrSession                                   session,
    const XrFaceTrackerCreateInfoFB*            createInfo,
    XrFaceTrackerFB*                            faceTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFaceTrackerFB(
    XrFaceTrackerFB                             faceTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrGetFaceExpressionWeightsFB(
    XrFaceTrackerFB                             faceTracker,
    const XrFaceExpressionInfoFB*               expressionInfo,
    XrFaceExpressionWeightsFB*                  expressionWeights);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateEyeTrackerFB(
    XrSession                                   session,
    const XrEyeTrackerCreateInfoFB*             createInfo,
    XrEyeTrackerFB*                             eyeTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyEyeTrackerFB(
    XrEyeTrackerFB                              eyeTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrGetEyeGazesFB(
    XrEyeTrackerFB                              eyeTracker,
    const XrEyeGazesInfoFB*                     gazeInfo,
    XrEyeGazesFB*                               eyeGazes);

XRAPI_ATTR XrResult XRAPI_CALL xrPassthroughLayerSetKeyboardHandsIntensityFB(
    XrPassthroughLayerFB                        layer,
    const XrPassthroughKeyboardHandsIntensityFB* intensity);

XRAPI_ATTR XrResult XRAPI_CALL xrGetDeviceSampleRateFB(
    XrSession                                   session,
    const XrHapticActionInfo*                   hapticActionInfo,
    XrDevicePcmSampleRateGetInfoFB*             deviceSampleRate);

XRAPI_ATTR XrResult XRAPI_CALL xrGetPassthroughPreferencesMETA(
    XrSession                                   session,
    XrPassthroughPreferencesMETA*               preferences);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateVirtualKeyboardMETA(
    XrSession                                   session,
    const XrVirtualKeyboardCreateInfoMETA*      createInfo,
    XrVirtualKeyboardMETA*                      keyboard);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyVirtualKeyboardMETA(
    XrVirtualKeyboardMETA                       keyboard);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateVirtualKeyboardSpaceMETA(
    XrSession                                   session,
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardSpaceCreateInfoMETA* createInfo,
    XrSpace*                                    keyboardSpace);

XRAPI_ATTR XrResult XRAPI_CALL xrSuggestVirtualKeyboardLocationMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardLocationInfoMETA*    locationInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardScaleMETA(
    XrVirtualKeyboardMETA                       keyboard,
    float*                                      scale);

XRAPI_ATTR XrResult XRAPI_CALL xrSetVirtualKeyboardModelVisibilityMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardModelVisibilitySetInfoMETA* modelVisibility);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardModelAnimationStatesMETA(
    XrVirtualKeyboardMETA                       keyboard,
    XrVirtualKeyboardModelAnimationStatesMETA*  animationStates);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardDirtyTexturesMETA(
    XrVirtualKeyboardMETA                       keyboard,
    uint32_t                                    textureIdCapacityInput,
    uint32_t*                                   textureIdCountOutput,
    uint64_t*                                   textureIds);

XRAPI_ATTR XrResult XRAPI_CALL xrGetVirtualKeyboardTextureDataMETA(
    XrVirtualKeyboardMETA                       keyboard,
    uint64_t                                    textureId,
    XrVirtualKeyboardTextureDataMETA*           textureData);

XRAPI_ATTR XrResult XRAPI_CALL xrSendVirtualKeyboardInputMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardInputInfoMETA*       info,
    XrPosef*                                    interactorRootPose);

XRAPI_ATTR XrResult XRAPI_CALL xrChangeVirtualKeyboardTextContextMETA(
    XrVirtualKeyboardMETA                       keyboard,
    const XrVirtualKeyboardTextContextChangeInfoMETA* changeInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumerateExternalCamerasOCULUS(
    XrSession                                   session,
    uint32_t                                    cameraCapacityInput,
    uint32_t*                                   cameraCountOutput,
    XrExternalCameraOCULUS*                     cameras);

XRAPI_ATTR XrResult XRAPI_CALL xrEnumeratePerformanceMetricsCounterPathsMETA(
    XrInstance                                  instance,
    uint32_t                                    counterPathCapacityInput,
    uint32_t*                                   counterPathCountOutput,
    XrPath*                                     counterPaths);

XRAPI_ATTR XrResult XRAPI_CALL xrSetPerformanceMetricsStateMETA(
    XrSession                                   session,
    const XrPerformanceMetricsStateMETA*        state);

XRAPI_ATTR XrResult XRAPI_CALL xrGetPerformanceMetricsStateMETA(
    XrSession                                   session,
    XrPerformanceMetricsStateMETA*              state);

XRAPI_ATTR XrResult XRAPI_CALL xrQueryPerformanceMetricsCounterMETA(
    XrSession                                   session,
    XrPath                                      counterPath,
    XrPerformanceMetricsCounterMETA*            counter);

XRAPI_ATTR XrResult XRAPI_CALL xrSaveSpaceListFB(
    XrSession                                   session,
    const XrSpaceListSaveInfoFB*                info,
    XrAsyncRequestIdFB*                         requestId);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpaceUserFB(
    XrSession                                   session,
    const XrSpaceUserCreateInfoFB*              info,
    XrSpaceUserFB*                              user);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceUserIdFB(
    XrSpaceUserFB                               user,
    XrSpaceUserIdFB*                            userId);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroySpaceUserFB(
    XrSpaceUserFB                               user);

XRAPI_ATTR XrResult XRAPI_CALL xrGetRecommendedLayerResolutionMETA(
    XrSession                                   session,
    const XrRecommendedLayerResolutionGetInfoMETA* info,
    XrRecommendedLayerResolutionMETA*           resolution);

XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughColorLutMETA(
    XrPassthroughFB                             passthrough,
    const XrPassthroughColorLutCreateInfoMETA*  createInfo,
    XrPassthroughColorLutMETA*                  colorLut);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughColorLutMETA(
    XrPassthroughColorLutMETA                   colorLut);

XRAPI_ATTR XrResult XRAPI_CALL xrUpdatePassthroughColorLutMETA(
    XrPassthroughColorLutMETA                   colorLut,
    const XrPassthroughColorLutUpdateInfoMETA*  updateInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpaceTriangleMeshMETA(
    XrSpace                                     space,
    const XrSpaceTriangleMeshGetInfoMETA*       getInfo,
    XrSpaceTriangleMeshMETA*                    triangleMeshOutput);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateFaceTracker2FB(
    XrSession                                   session,
    const XrFaceTrackerCreateInfo2FB*           createInfo,
    XrFaceTracker2FB*                           faceTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyFaceTracker2FB(
    XrFaceTracker2FB                            faceTracker);

XRAPI_ATTR XrResult XRAPI_CALL xrGetFaceExpressionWeights2FB(
    XrFaceTracker2FB                            faceTracker,
    const XrFaceExpressionInfo2FB*              expressionInfo,
    XrFaceExpressionWeights2FB*                 expressionWeights);

XRAPI_ATTR XrResult XRAPI_CALL xrSetTrackingOptimizationSettingsHintQCOM(
    XrSession                                   session,
    XrTrackingOptimizationSettingsDomainQCOM    domain,
    XrTrackingOptimizationSettingsHintQCOM      hint);

XRAPI_ATTR XrResult XRAPI_CALL xrCreatePassthroughHTC(
    XrSession                                   session,
    const XrPassthroughCreateInfoHTC*           createInfo,
    XrPassthroughHTC*                           passthrough);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPassthroughHTC(
    XrPassthroughHTC                            passthrough);

XRAPI_ATTR XrResult XRAPI_CALL xrApplyFoveationHTC(
    XrSession                                   session,
    const XrFoveationApplyInfoHTC*              applyInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrCreateSpatialAnchorHTC(
    XrSession                                   session,
    const XrSpatialAnchorCreateInfoHTC*         createInfo,
    XrSpace*                                    anchor);

XRAPI_ATTR XrResult XRAPI_CALL xrGetSpatialAnchorNameHTC(
    XrSpace                                     anchor,
    XrSpatialAnchorNameHTC*                     name);

XRAPI_ATTR XrResult XRAPI_CALL xrApplyForceFeedbackCurlMNDX(
    XrHandTrackerEXT                            handTracker,
    const XrForceFeedbackCurlApplyLocationsMNDX* locations);

XRAPI_ATTR XrResult XRAPI_CALL xrCreatePlaneDetectorEXT(
    XrSession                                   session,
    const XrPlaneDetectorCreateInfoEXT*         createInfo,
    XrPlaneDetectorEXT*                         planeDetector);

XRAPI_ATTR XrResult XRAPI_CALL xrDestroyPlaneDetectorEXT(
    XrPlaneDetectorEXT                          planeDetector);

XRAPI_ATTR XrResult XRAPI_CALL xrBeginPlaneDetectionEXT(
    XrPlaneDetectorEXT                          planeDetector,
    const XrPlaneDetectorBeginInfoEXT*          beginInfo);

XRAPI_ATTR XrResult XRAPI_CALL xrGetPlaneDetectionStateEXT(
    XrPlaneDetectorEXT                          planeDetector,
    XrPlaneDetectionStateEXT*                   state);

XRAPI_ATTR XrResult XRAPI_CALL xrGetPlaneDetectionsEXT(
    XrPlaneDetectorEXT                          planeDetector,
    const XrPlaneDetectorGetInfoEXT*            info,
    XrPlaneDetectorLocationsEXT*                locations);

XRAPI_ATTR XrResult XRAPI_CALL xrGetPlanePolygonBufferEXT(
    XrPlaneDetectorEXT                          planeDetector,
    uint64_t                                    planeId,
    uint32_t                                    polygonBufferIndex,
    XrPlaneDetectorPolygonBufferEXT*            polygonBuffer);

XRAPI_ATTR XrResult XRAPI_CALL xrEnableUserCalibrationEventsML(
    XrInstance                                  instance,
    const XrUserCalibrationEnableEventsInfoML*  enableInfo);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_API_CALL_ENCODERS_H
