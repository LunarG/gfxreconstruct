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

#ifndef  GFXRECON_GENERATED_OPENXR_CONSUMER_H
#define  GFXRECON_GENERATED_OPENXR_CONSUMER_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "decode/openxr_consumer_base.h"
#include "generated/generated_openxr_struct_decoders.h"
#include "util/defines.h"


#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class OpenXrConsumer : public OpenXrConsumerBase
{
  public:
    OpenXrConsumer() { }

    virtual ~OpenXrConsumer() override { }

    virtual void Process_xrDestroyInstance(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance) {}

    virtual void Process_xrGetInstanceProperties(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrInstanceProperties>* instanceProperties) {}

    virtual void Process_xrPollEvent(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrEventDataBuffer>* eventData) {}

    virtual void Process_xrResultToString(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrResult                                    value,
        StringDecoder*                              buffer) {}

    virtual void Process_xrStructureTypeToString(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrStructureType                             value,
        StringDecoder*                              buffer) {}

    virtual void Process_xrGetSystem(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrSystemGetInfo>* getInfo,
        PointerDecoder<XrSystemId>*                 systemId) {}

    virtual void Process_xrGetSystemProperties(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrSystemProperties>* properties) {}

    virtual void Process_xrEnumerateEnvironmentBlendModes(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        XrViewConfigurationType                     viewConfigurationType,
        uint32_t                                    environmentBlendModeCapacityInput,
        PointerDecoder<uint32_t>*                   environmentBlendModeCountOutput,
        PointerDecoder<XrEnvironmentBlendMode>*     environmentBlendModes) {}

    virtual void Process_xrCreateSession(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrSessionCreateInfo>* createInfo,
        HandlePointerDecoder<XrSession>*            session) {}

    virtual void Process_xrDestroySession(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session) {}

    virtual void Process_xrEnumerateReferenceSpaces(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    spaceCapacityInput,
        PointerDecoder<uint32_t>*                   spaceCountOutput,
        PointerDecoder<XrReferenceSpaceType>*       spaces) {}

    virtual void Process_xrCreateReferenceSpace(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrReferenceSpaceCreateInfo>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) {}

    virtual void Process_xrGetReferenceSpaceBoundsRect(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrReferenceSpaceType                        referenceSpaceType,
        StructPointerDecoder<Decoded_XrExtent2Df>*  bounds) {}

    virtual void Process_xrCreateActionSpace(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionSpaceCreateInfo>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) {}

    virtual void Process_xrLocateSpace(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        format::HandleId                            baseSpace,
        XrTime                                      time,
        StructPointerDecoder<Decoded_XrSpaceLocation>* location) {}

    virtual void Process_xrDestroySpace(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space) {}

    virtual void Process_xrEnumerateViewConfigurations(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        uint32_t                                    viewConfigurationTypeCapacityInput,
        PointerDecoder<uint32_t>*                   viewConfigurationTypeCountOutput,
        PointerDecoder<XrViewConfigurationType>*    viewConfigurationTypes) {}

    virtual void Process_xrGetViewConfigurationProperties(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        XrViewConfigurationType                     viewConfigurationType,
        StructPointerDecoder<Decoded_XrViewConfigurationProperties>* configurationProperties) {}

    virtual void Process_xrEnumerateViewConfigurationViews(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        XrViewConfigurationType                     viewConfigurationType,
        uint32_t                                    viewCapacityInput,
        PointerDecoder<uint32_t>*                   viewCountOutput,
        StructPointerDecoder<Decoded_XrViewConfigurationView>* views) {}

    virtual void Process_xrEnumerateSwapchainFormats(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    formatCapacityInput,
        PointerDecoder<uint32_t>*                   formatCountOutput,
        PointerDecoder<int64_t>*                    formats) {}

    virtual void Process_xrCreateSwapchain(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* createInfo,
        HandlePointerDecoder<XrSwapchain>*          swapchain) {}

    virtual void Process_xrDestroySwapchain(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain) {}

    virtual void Process_xrEnumerateSwapchainImages(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        uint32_t                                    imageCapacityInput,
        PointerDecoder<uint32_t>*                   imageCountOutput,
        StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images) {}

    virtual void Process_xrAcquireSwapchainImage(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_XrSwapchainImageAcquireInfo>* acquireInfo,
        PointerDecoder<uint32_t>*                   index) {}

    virtual void Process_xrWaitSwapchainImage(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_XrSwapchainImageWaitInfo>* waitInfo) {}

    virtual void Process_xrReleaseSwapchainImage(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo) {}

    virtual void Process_xrBeginSession(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSessionBeginInfo>* beginInfo) {}

    virtual void Process_xrEndSession(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session) {}

    virtual void Process_xrRequestExitSession(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session) {}

    virtual void Process_xrWaitFrame(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFrameWaitInfo>* frameWaitInfo,
        StructPointerDecoder<Decoded_XrFrameState>* frameState) {}

    virtual void Process_xrBeginFrame(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFrameBeginInfo>* frameBeginInfo) {}

    virtual void Process_xrEndFrame(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFrameEndInfo>* frameEndInfo) {}

    virtual void Process_xrLocateViews(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrViewLocateInfo>* viewLocateInfo,
        StructPointerDecoder<Decoded_XrViewState>*  viewState,
        uint32_t                                    viewCapacityInput,
        PointerDecoder<uint32_t>*                   viewCountOutput,
        StructPointerDecoder<Decoded_XrView>*       views) {}

    virtual void Process_xrStringToPath(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StringDecoder*                              pathString,
        PointerDecoder<XrPath>*                     path) {}

    virtual void Process_xrPathToString(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrPath                                      path,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) {}

    virtual void Process_xrCreateActionSet(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrActionSetCreateInfo>* createInfo,
        HandlePointerDecoder<XrActionSet>*          actionSet) {}

    virtual void Process_xrDestroyActionSet(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            actionSet) {}

    virtual void Process_xrCreateAction(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            actionSet,
        StructPointerDecoder<Decoded_XrActionCreateInfo>* createInfo,
        HandlePointerDecoder<XrAction>*             action) {}

    virtual void Process_xrDestroyAction(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            action) {}

    virtual void Process_xrSuggestInteractionProfileBindings(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrInteractionProfileSuggestedBinding>* suggestedBindings) {}

    virtual void Process_xrAttachSessionActionSets(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSessionActionSetsAttachInfo>* attachInfo) {}

    virtual void Process_xrGetCurrentInteractionProfile(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelUserPath,
        StructPointerDecoder<Decoded_XrInteractionProfileState>* interactionProfile) {}

    virtual void Process_xrGetActionStateBoolean(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
        StructPointerDecoder<Decoded_XrActionStateBoolean>* state) {}

    virtual void Process_xrGetActionStateFloat(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
        StructPointerDecoder<Decoded_XrActionStateFloat>* state) {}

    virtual void Process_xrGetActionStateVector2f(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
        StructPointerDecoder<Decoded_XrActionStateVector2f>* state) {}

    virtual void Process_xrGetActionStatePose(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
        StructPointerDecoder<Decoded_XrActionStatePose>* state) {}

    virtual void Process_xrSyncActions(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionsSyncInfo>* syncInfo) {}

    virtual void Process_xrEnumerateBoundSourcesForAction(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrBoundSourcesForActionEnumerateInfo>* enumerateInfo,
        uint32_t                                    sourceCapacityInput,
        PointerDecoder<uint32_t>*                   sourceCountOutput,
        PointerDecoder<XrPath>*                     sources) {}

    virtual void Process_xrGetInputSourceLocalizedName(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrInputSourceLocalizedNameGetInfo>* getInfo,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) {}

    virtual void Process_xrApplyHapticFeedback(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo,
        StructPointerDecoder<Decoded_XrHapticBaseHeader>* hapticFeedback) {}

    virtual void Process_xrStopHapticFeedback(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo) {}

    virtual void Process_xrCreateApiLayerInstance(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        StructPointerDecoder<Decoded_XrInstanceCreateInfo>* info,
        StructPointerDecoder<Decoded_XrApiLayerCreateInfo>* layerInfo,
        HandlePointerDecoder<XrInstance>*           instance) {}

    virtual void Process_xrSetAndroidApplicationThreadKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrAndroidThreadTypeKHR                      threadType,
        uint32_t                                    threadId) {}

    virtual void Process_xrCreateSwapchainAndroidSurfaceKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* info,
        HandlePointerDecoder<XrSwapchain>*          swapchain,
        uint64_t                                    surface) {}

    virtual void Process_xrGetOpenGLGraphicsRequirementsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLKHR>* graphicsRequirements) {}

    virtual void Process_xrGetOpenGLESGraphicsRequirementsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLESKHR>* graphicsRequirements) {}

    virtual void Process_xrGetVulkanInstanceExtensionsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) {}

    virtual void Process_xrGetVulkanDeviceExtensionsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) {}

    virtual void Process_xrGetVulkanGraphicsDeviceKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        format::HandleId                            vkInstance,
        HandlePointerDecoder<VkPhysicalDevice>*     vkPhysicalDevice) {}

    virtual void Process_xrGetVulkanGraphicsRequirementsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements) {}

    virtual void Process_xrGetD3D11GraphicsRequirementsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D11KHR>* graphicsRequirements) {}

    virtual void Process_xrGetD3D12GraphicsRequirementsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D12KHR>* graphicsRequirements) {}

    virtual void Process_xrGetVisibilityMaskKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrViewConfigurationType                     viewConfigurationType,
        uint32_t                                    viewIndex,
        XrVisibilityMaskTypeKHR                     visibilityMaskType,
        StructPointerDecoder<Decoded_XrVisibilityMaskKHR>* visibilityMask) {}

    virtual void Process_xrConvertWin32PerformanceCounterToTimeKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<LARGE_INTEGER>*              performanceCounter,
        PointerDecoder<XrTime>*                     time) {}

    virtual void Process_xrConvertTimeToWin32PerformanceCounterKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrTime                                      time,
        PointerDecoder<LARGE_INTEGER>*              performanceCounter) {}

    virtual void Process_xrConvertTimespecTimeToTimeKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_timespec>*     timespecTime,
        PointerDecoder<XrTime>*                     time) {}

    virtual void Process_xrConvertTimeToTimespecTimeKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrTime                                      time,
        StructPointerDecoder<Decoded_timespec>*     timespecTime) {}


    virtual void Process_xrCreateVulkanInstanceKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrVulkanInstanceCreateInfoKHR>* createInfo,
        HandlePointerDecoder<VkInstance>*           vulkanInstance,
        PointerDecoder<VkResult>*                   vulkanResult) {}

    virtual void Process_xrCreateVulkanDeviceKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrVulkanDeviceCreateInfoKHR>* createInfo,
        HandlePointerDecoder<VkDevice>*             vulkanDevice,
        PointerDecoder<VkResult>*                   vulkanResult) {}

    virtual void Process_xrGetVulkanGraphicsDevice2KHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrVulkanGraphicsDeviceGetInfoKHR>* getInfo,
        HandlePointerDecoder<VkPhysicalDevice>*     vulkanPhysicalDevice) {}

    virtual void Process_xrGetVulkanGraphicsRequirements2KHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements) {}

    virtual void Process_xrPerfSettingsSetPerformanceLevelEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPerfSettingsDomainEXT                     domain,
        XrPerfSettingsLevelEXT                      level) {}

    virtual void Process_xrThermalGetTemperatureTrendEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPerfSettingsDomainEXT                     domain,
        PointerDecoder<XrPerfSettingsNotificationLevelEXT>* notificationLevel,
        PointerDecoder<float>*                      tempHeadroom,
        PointerDecoder<float>*                      tempSlope) {}

    virtual void Process_xrSetDebugUtilsObjectNameEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrDebugUtilsObjectNameInfoEXT>* nameInfo) {}

    virtual void Process_xrCreateDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrDebugUtilsMessengerCreateInfoEXT>* createInfo,
        HandlePointerDecoder<XrDebugUtilsMessengerEXT>* messenger) {}

    virtual void Process_xrDestroyDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            messenger) {}

    virtual void Process_xrSubmitDebugUtilsMessageEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrDebugUtilsMessageSeverityFlagsEXT         messageSeverity,
        XrDebugUtilsMessageTypeFlagsEXT             messageTypes,
        StructPointerDecoder<Decoded_XrDebugUtilsMessengerCallbackDataEXT>* callbackData) {}

    virtual void Process_xrSessionBeginDebugUtilsLabelRegionEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* labelInfo) {}

    virtual void Process_xrSessionEndDebugUtilsLabelRegionEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session) {}

    virtual void Process_xrSessionInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* labelInfo) {}

    virtual void Process_xrCreateSpatialAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpatialAnchorMSFT>*  anchor) {}

    virtual void Process_xrCreateSpatialAnchorSpaceMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialAnchorSpaceCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) {}

    virtual void Process_xrDestroySpatialAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            anchor) {}

    virtual void Process_xrSetInputDeviceActiveEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      interactionProfile,
        XrPath                                      topLevelPath,
        XrBool32                                    isActive) {}

    virtual void Process_xrSetInputDeviceStateBoolEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelPath,
        XrPath                                      inputSourcePath,
        XrBool32                                    state) {}

    virtual void Process_xrSetInputDeviceStateFloatEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelPath,
        XrPath                                      inputSourcePath,
        float                                       state) {}

    virtual void Process_xrSetInputDeviceStateVector2fEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelPath,
        XrPath                                      inputSourcePath,
        Decoded_XrVector2f                          state) {}

    virtual void Process_xrSetInputDeviceLocationEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelPath,
        XrPath                                      inputSourcePath,
        format::HandleId                            space,
        Decoded_XrPosef                             pose) {}

    virtual void Process_xrCreateSpatialGraphNodeSpaceMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) {}

    virtual void Process_xrTryCreateSpatialGraphStaticNodeBindingMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpatialGraphNodeBindingMSFT>* nodeBinding) {}

    virtual void Process_xrDestroySpatialGraphNodeBindingMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            nodeBinding) {}

    virtual void Process_xrGetSpatialGraphNodeBindingPropertiesMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            nodeBinding,
        StructPointerDecoder<Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT>* getInfo,
        StructPointerDecoder<Decoded_XrSpatialGraphNodeBindingPropertiesMSFT>* properties) {}

    virtual void Process_xrCreateHandTrackerEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrHandTrackerCreateInfoEXT>* createInfo,
        HandlePointerDecoder<XrHandTrackerEXT>*     handTracker) {}

    virtual void Process_xrDestroyHandTrackerEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker) {}

    virtual void Process_xrLocateHandJointsEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker,
        StructPointerDecoder<Decoded_XrHandJointsLocateInfoEXT>* locateInfo,
        StructPointerDecoder<Decoded_XrHandJointLocationsEXT>* locations) {}

    virtual void Process_xrCreateHandMeshSpaceMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker,
        StructPointerDecoder<Decoded_XrHandMeshSpaceCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) {}

    virtual void Process_xrUpdateHandMeshMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker,
        StructPointerDecoder<Decoded_XrHandMeshUpdateInfoMSFT>* updateInfo,
        StructPointerDecoder<Decoded_XrHandMeshMSFT>* handMesh) {}

    virtual void Process_xrGetControllerModelKeyMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelUserPath,
        StructPointerDecoder<Decoded_XrControllerModelKeyStateMSFT>* controllerModelKeyState) {}

    virtual void Process_xrLoadControllerModelMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrControllerModelKeyMSFT                    modelKey,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        PointerDecoder<uint8_t>*                    buffer) {}

    virtual void Process_xrGetControllerModelPropertiesMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrControllerModelKeyMSFT                    modelKey,
        StructPointerDecoder<Decoded_XrControllerModelPropertiesMSFT>* properties) {}

    virtual void Process_xrGetControllerModelStateMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrControllerModelKeyMSFT                    modelKey,
        StructPointerDecoder<Decoded_XrControllerModelStateMSFT>* state) {}

    virtual void Process_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint64_t                                    perceptionAnchor,
        HandlePointerDecoder<XrSpatialAnchorMSFT>*  anchor) {}

    virtual void Process_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            anchor,
        PointerDecoder<uint64_t, void*>*            perceptionAnchor) {}

    virtual void Process_xrEnumerateReprojectionModesMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        XrViewConfigurationType                     viewConfigurationType,
        uint32_t                                    modeCapacityInput,
        PointerDecoder<uint32_t>*                   modeCountOutput,
        PointerDecoder<XrReprojectionModeMSFT>*     modes) {}

    virtual void Process_xrUpdateSwapchainFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state) {}

    virtual void Process_xrGetSwapchainStateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state) {}

    virtual void Process_xrCreateBodyTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrBodyTrackerCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrBodyTrackerFB>*      bodyTracker) {}

    virtual void Process_xrDestroyBodyTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            bodyTracker) {}

    virtual void Process_xrLocateBodyJointsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            bodyTracker,
        StructPointerDecoder<Decoded_XrBodyJointsLocateInfoFB>* locateInfo,
        StructPointerDecoder<Decoded_XrBodyJointLocationsFB>* locations) {}

    virtual void Process_xrGetBodySkeletonFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            bodyTracker,
        StructPointerDecoder<Decoded_XrBodySkeletonFB>* skeleton) {}

    virtual void Process_xrEnumerateSceneComputeFeaturesMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        uint32_t                                    featureCapacityInput,
        PointerDecoder<uint32_t>*                   featureCountOutput,
        PointerDecoder<XrSceneComputeFeatureMSFT>*  features) {}

    virtual void Process_xrCreateSceneObserverMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSceneObserverCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSceneObserverMSFT>*  sceneObserver) {}

    virtual void Process_xrDestroySceneObserverMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            sceneObserver) {}

    virtual void Process_xrCreateSceneMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            sceneObserver,
        StructPointerDecoder<Decoded_XrSceneCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSceneMSFT>*          scene) {}

    virtual void Process_xrDestroySceneMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene) {}

    virtual void Process_xrComputeNewSceneMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            sceneObserver,
        StructPointerDecoder<Decoded_XrNewSceneComputeInfoMSFT>* computeInfo) {}

    virtual void Process_xrGetSceneComputeStateMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            sceneObserver,
        PointerDecoder<XrSceneComputeStateMSFT>*    state) {}

    virtual void Process_xrGetSceneComponentsMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrSceneComponentsGetInfoMSFT>* getInfo,
        StructPointerDecoder<Decoded_XrSceneComponentsMSFT>* components) {}

    virtual void Process_xrLocateSceneComponentsMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrSceneComponentsLocateInfoMSFT>* locateInfo,
        StructPointerDecoder<Decoded_XrSceneComponentLocationsMSFT>* locations) {}

    virtual void Process_xrGetSceneMeshBuffersMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrSceneMeshBuffersGetInfoMSFT>* getInfo,
        StructPointerDecoder<Decoded_XrSceneMeshBuffersMSFT>* buffers) {}

    virtual void Process_xrDeserializeSceneMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            sceneObserver,
        StructPointerDecoder<Decoded_XrSceneDeserializeInfoMSFT>* deserializeInfo) {}

    virtual void Process_xrGetSerializedSceneFragmentDataMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrSerializedSceneFragmentDataGetInfoMSFT>* getInfo,
        uint32_t                                    countInput,
        PointerDecoder<uint32_t>*                   readOutput,
        PointerDecoder<uint8_t>*                    buffer) {}

    virtual void Process_xrEnumerateDisplayRefreshRatesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    displayRefreshRateCapacityInput,
        PointerDecoder<uint32_t>*                   displayRefreshRateCountOutput,
        PointerDecoder<float>*                      displayRefreshRates) {}

    virtual void Process_xrGetDisplayRefreshRateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        PointerDecoder<float>*                      displayRefreshRate) {}

    virtual void Process_xrRequestDisplayRefreshRateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        float                                       displayRefreshRate) {}

    virtual void Process_xrEnumerateViveTrackerPathsHTCX(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        uint32_t                                    pathCapacityInput,
        PointerDecoder<uint32_t>*                   pathCountOutput,
        StructPointerDecoder<Decoded_XrViveTrackerPathsHTCX>* paths) {}

    virtual void Process_xrCreateFacialTrackerHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFacialTrackerCreateInfoHTC>* createInfo,
        HandlePointerDecoder<XrFacialTrackerHTC>*   facialTracker) {}

    virtual void Process_xrDestroyFacialTrackerHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            facialTracker) {}

    virtual void Process_xrGetFacialExpressionsHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            facialTracker,
        StructPointerDecoder<Decoded_XrFacialExpressionsHTC>* facialExpressions) {}

    virtual void Process_xrEnumerateColorSpacesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    colorSpaceCapacityInput,
        PointerDecoder<uint32_t>*                   colorSpaceCountOutput,
        PointerDecoder<XrColorSpaceFB>*             colorSpaces) {}

    virtual void Process_xrSetColorSpaceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrColorSpaceFB                              colorSpace) {}

    virtual void Process_xrGetHandMeshFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker,
        StructPointerDecoder<Decoded_XrHandTrackingMeshFB>* mesh) {}

    virtual void Process_xrCreateSpatialAnchorFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoFB>* info,
        PointerDecoder<XrAsyncRequestIdFB>*         requestId) {}

    virtual void Process_xrGetSpaceUuidFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrUuidEXT>*    uuid) {}

    virtual void Process_xrEnumerateSpaceSupportedComponentsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        uint32_t                                    componentTypeCapacityInput,
        PointerDecoder<uint32_t>*                   componentTypeCountOutput,
        PointerDecoder<XrSpaceComponentTypeFB>*     componentTypes) {}

    virtual void Process_xrSetSpaceComponentStatusFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrSpaceComponentStatusSetInfoFB>* info,
        PointerDecoder<XrAsyncRequestIdFB>*         requestId) {}

    virtual void Process_xrGetSpaceComponentStatusFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        XrSpaceComponentTypeFB                      componentType,
        StructPointerDecoder<Decoded_XrSpaceComponentStatusFB>* status) {}

    virtual void Process_xrCreateFoveationProfileFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFoveationProfileCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrFoveationProfileFB>* profile) {}

    virtual void Process_xrDestroyFoveationProfileFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            profile) {}

    virtual void Process_xrQuerySystemTrackedKeyboardFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrKeyboardTrackingQueryFB>* queryInfo,
        StructPointerDecoder<Decoded_XrKeyboardTrackingDescriptionFB>* keyboard) {}

    virtual void Process_xrCreateKeyboardSpaceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrKeyboardSpaceCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrSpace>*              keyboardSpace) {}

    virtual void Process_xrTriangleMeshBeginUpdateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            mesh) {}

    virtual void Process_xrTriangleMeshEndUpdateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            mesh,
        uint32_t                                    vertexCount,
        uint32_t                                    triangleCount) {}

    virtual void Process_xrTriangleMeshBeginVertexBufferUpdateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            mesh,
        PointerDecoder<uint32_t>*                   outVertexCount) {}

    virtual void Process_xrTriangleMeshEndVertexBufferUpdateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            mesh) {}

    virtual void Process_xrCreatePassthroughFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPassthroughCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrPassthroughFB>*      outPassthrough) {}

    virtual void Process_xrDestroyPassthroughFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            passthrough) {}

    virtual void Process_xrPassthroughStartFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            passthrough) {}

    virtual void Process_xrPassthroughPauseFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            passthrough) {}

    virtual void Process_xrCreatePassthroughLayerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPassthroughLayerCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrPassthroughLayerFB>* outLayer) {}

    virtual void Process_xrDestroyPassthroughLayerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            layer) {}

    virtual void Process_xrPassthroughLayerPauseFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            layer) {}

    virtual void Process_xrPassthroughLayerResumeFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            layer) {}

    virtual void Process_xrPassthroughLayerSetStyleFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            layer,
        StructPointerDecoder<Decoded_XrPassthroughStyleFB>* style) {}

    virtual void Process_xrCreateGeometryInstanceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrGeometryInstanceCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrGeometryInstanceFB>* outGeometryInstance) {}

    virtual void Process_xrDestroyGeometryInstanceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance) {}

    virtual void Process_xrGeometryInstanceSetTransformFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrGeometryInstanceTransformFB>* transformation) {}

    virtual void Process_xrEnumerateRenderModelPathsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    pathCapacityInput,
        PointerDecoder<uint32_t>*                   pathCountOutput,
        StructPointerDecoder<Decoded_XrRenderModelPathInfoFB>* paths) {}

    virtual void Process_xrGetRenderModelPropertiesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      path,
        StructPointerDecoder<Decoded_XrRenderModelPropertiesFB>* properties) {}

    virtual void Process_xrLoadRenderModelFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrRenderModelLoadInfoFB>* info,
        StructPointerDecoder<Decoded_XrRenderModelBufferFB>* buffer) {}

    virtual void Process_xrSetEnvironmentDepthEstimationVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrBool32                                    enabled) {}

    virtual void Process_xrSetMarkerTrackingVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrBool32                                    enabled) {}

    virtual void Process_xrSetMarkerTrackingTimeoutVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint64_t                                    markerId,
        XrDuration                                  timeout) {}

    virtual void Process_xrSetMarkerTrackingPredictionVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint64_t                                    markerId,
        XrBool32                                    enable) {}

    virtual void Process_xrGetMarkerSizeVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint64_t                                    markerId,
        StructPointerDecoder<Decoded_XrExtent2Df>*  size) {}

    virtual void Process_xrCreateMarkerSpaceVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoVARJO>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) {}

    virtual void Process_xrSetViewOffsetVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        float                                       offset) {}

    virtual void Process_xrCreateSpaceFromCoordinateFrameUIDML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrCoordinateSpaceCreateInfoML>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) {}

    virtual void Process_xrCreateMarkerDetectorML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrMarkerDetectorCreateInfoML>* createInfo,
        HandlePointerDecoder<XrMarkerDetectorML>*   markerDetector) {}

    virtual void Process_xrDestroyMarkerDetectorML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector) {}

    virtual void Process_xrSnapshotMarkerDetectorML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        StructPointerDecoder<Decoded_XrMarkerDetectorSnapshotInfoML>* snapshotInfo) {}

    virtual void Process_xrGetMarkerDetectorStateML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        StructPointerDecoder<Decoded_XrMarkerDetectorStateML>* state) {}

    virtual void Process_xrGetMarkersML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        uint32_t                                    markerCapacityInput,
        PointerDecoder<uint32_t>*                   markerCountOutput,
        PointerDecoder<XrMarkerML>*                 markers) {}

    virtual void Process_xrGetMarkerReprojectionErrorML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        XrMarkerML                                  marker,
        PointerDecoder<float>*                      reprojectionErrorMeters) {}

    virtual void Process_xrGetMarkerLengthML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        XrMarkerML                                  marker,
        PointerDecoder<float>*                      meters) {}

    virtual void Process_xrGetMarkerNumberML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        XrMarkerML                                  marker,
        PointerDecoder<uint64_t>*                   number) {}

    virtual void Process_xrGetMarkerStringML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        XrMarkerML                                  marker,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) {}

    virtual void Process_xrCreateMarkerSpaceML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoML>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) {}

    virtual void Process_xrEnableLocalizationEventsML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrLocalizationEnableEventsInfoML>* info) {}

    virtual void Process_xrQueryLocalizationMapsML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrLocalizationMapQueryInfoBaseHeaderML>* queryInfo,
        uint32_t                                    mapCapacityInput,
        PointerDecoder<uint32_t>*                   mapCountOutput,
        StructPointerDecoder<Decoded_XrLocalizationMapML>* maps) {}

    virtual void Process_xrRequestMapLocalizationML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrMapLocalizationRequestInfoML>* requestInfo) {}

    virtual void Process_xrImportLocalizationMapML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrLocalizationMapImportInfoML>* importInfo,
        StructPointerDecoder<Decoded_XrUuidEXT>*    mapUuid) {}

    virtual void Process_xrCreateExportedLocalizationMapML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrUuidEXT>*    mapUuid,
        HandlePointerDecoder<XrExportedLocalizationMapML>* map) {}

    virtual void Process_xrDestroyExportedLocalizationMapML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            map) {}

    virtual void Process_xrGetExportedLocalizationMapDataML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            map,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) {}

    virtual void Process_xrCreateSpatialAnchorStoreConnectionMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        HandlePointerDecoder<XrSpatialAnchorStoreConnectionMSFT>* spatialAnchorStore) {}

    virtual void Process_xrDestroySpatialAnchorStoreConnectionMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            spatialAnchorStore) {}

    virtual void Process_xrPersistSpatialAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            spatialAnchorStore,
        StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceInfoMSFT>* spatialAnchorPersistenceInfo) {}

    virtual void Process_xrEnumeratePersistedSpatialAnchorNamesMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            spatialAnchorStore,
        uint32_t                                    spatialAnchorNameCapacityInput,
        PointerDecoder<uint32_t>*                   spatialAnchorNameCountOutput,
        StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT>* spatialAnchorNames) {}

    virtual void Process_xrCreateSpatialAnchorFromPersistedNameMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT>* spatialAnchorCreateInfo,
        HandlePointerDecoder<XrSpatialAnchorMSFT>*  spatialAnchor) {}

    virtual void Process_xrUnpersistSpatialAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            spatialAnchorStore,
        StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT>* spatialAnchorPersistenceName) {}

    virtual void Process_xrClearSpatialAnchorStoreMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            spatialAnchorStore) {}

    virtual void Process_xrGetSceneMarkerRawDataMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrUuidMSFT>*   markerId,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        PointerDecoder<uint8_t>*                    buffer) {}

    virtual void Process_xrGetSceneMarkerDecodedStringMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrUuidMSFT>*   markerId,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) {}

    virtual void Process_xrQuerySpacesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceQueryInfoBaseHeaderFB>* info,
        PointerDecoder<XrAsyncRequestIdFB>*         requestId) {}

    virtual void Process_xrRetrieveSpaceQueryResultsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrAsyncRequestIdFB                          requestId,
        StructPointerDecoder<Decoded_XrSpaceQueryResultsFB>* results) {}

    virtual void Process_xrSaveSpaceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceSaveInfoFB>* info,
        PointerDecoder<XrAsyncRequestIdFB>*         requestId) {}

    virtual void Process_xrEraseSpaceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceEraseInfoFB>* info,
        PointerDecoder<XrAsyncRequestIdFB>*         requestId) {}

    virtual void Process_xrGetAudioOutputDeviceGuidOculus(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        WStringDecoder*                             buffer) {}

    virtual void Process_xrGetAudioInputDeviceGuidOculus(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        WStringDecoder*                             buffer) {}

    virtual void Process_xrShareSpacesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceShareInfoFB>* info,
        PointerDecoder<XrAsyncRequestIdFB>*         requestId) {}

    virtual void Process_xrGetSpaceBoundingBox2DFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrRect2Df>*    boundingBox2DOutput) {}

    virtual void Process_xrGetSpaceBoundingBox3DFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrRect3DfFB>*  boundingBox3DOutput) {}

    virtual void Process_xrGetSpaceSemanticLabelsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrSemanticLabelsFB>* semanticLabelsOutput) {}

    virtual void Process_xrGetSpaceBoundary2DFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrBoundary2DFB>* boundary2DOutput) {}

    virtual void Process_xrGetSpaceRoomLayoutFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrRoomLayoutFB>* roomLayoutOutput) {}

    virtual void Process_xrSetDigitalLensControlALMALENCE(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrDigitalLensControlALMALENCE>* digitalLensControl) {}

    virtual void Process_xrRequestSceneCaptureFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSceneCaptureRequestInfoFB>* info,
        PointerDecoder<XrAsyncRequestIdFB>*         requestId) {}

    virtual void Process_xrGetSpaceContainerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrSpaceContainerFB>* spaceContainerOutput) {}

    virtual void Process_xrGetFoveationEyeTrackedStateMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFoveationEyeTrackedStateMETA>* foveationState) {}

    virtual void Process_xrCreateFaceTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFaceTrackerCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrFaceTrackerFB>*      faceTracker) {}

    virtual void Process_xrDestroyFaceTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            faceTracker) {}

    virtual void Process_xrGetFaceExpressionWeightsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            faceTracker,
        StructPointerDecoder<Decoded_XrFaceExpressionInfoFB>* expressionInfo,
        StructPointerDecoder<Decoded_XrFaceExpressionWeightsFB>* expressionWeights) {}

    virtual void Process_xrCreateEyeTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrEyeTrackerCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrEyeTrackerFB>*       eyeTracker) {}

    virtual void Process_xrDestroyEyeTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            eyeTracker) {}

    virtual void Process_xrGetEyeGazesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            eyeTracker,
        StructPointerDecoder<Decoded_XrEyeGazesInfoFB>* gazeInfo,
        StructPointerDecoder<Decoded_XrEyeGazesFB>* eyeGazes) {}

    virtual void Process_xrPassthroughLayerSetKeyboardHandsIntensityFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            layer,
        StructPointerDecoder<Decoded_XrPassthroughKeyboardHandsIntensityFB>* intensity) {}

    virtual void Process_xrGetDeviceSampleRateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo,
        StructPointerDecoder<Decoded_XrDevicePcmSampleRateGetInfoFB>* deviceSampleRate) {}

    virtual void Process_xrGetPassthroughPreferencesMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPassthroughPreferencesMETA>* preferences) {}

    virtual void Process_xrCreateVirtualKeyboardMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrVirtualKeyboardCreateInfoMETA>* createInfo,
        HandlePointerDecoder<XrVirtualKeyboardMETA>* keyboard) {}

    virtual void Process_xrDestroyVirtualKeyboardMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard) {}

    virtual void Process_xrCreateVirtualKeyboardSpaceMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardSpaceCreateInfoMETA>* createInfo,
        HandlePointerDecoder<XrSpace>*              keyboardSpace) {}

    virtual void Process_xrSuggestVirtualKeyboardLocationMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardLocationInfoMETA>* locationInfo) {}

    virtual void Process_xrGetVirtualKeyboardScaleMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        PointerDecoder<float>*                      scale) {}

    virtual void Process_xrSetVirtualKeyboardModelVisibilityMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA>* modelVisibility) {}

    virtual void Process_xrGetVirtualKeyboardModelAnimationStatesMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardModelAnimationStatesMETA>* animationStates) {}

    virtual void Process_xrGetVirtualKeyboardDirtyTexturesMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        uint32_t                                    textureIdCapacityInput,
        PointerDecoder<uint32_t>*                   textureIdCountOutput,
        PointerDecoder<uint64_t>*                   textureIds) {}

    virtual void Process_xrGetVirtualKeyboardTextureDataMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        uint64_t                                    textureId,
        StructPointerDecoder<Decoded_XrVirtualKeyboardTextureDataMETA>* textureData) {}

    virtual void Process_xrSendVirtualKeyboardInputMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardInputInfoMETA>* info,
        StructPointerDecoder<Decoded_XrPosef>*      interactorRootPose) {}

    virtual void Process_xrChangeVirtualKeyboardTextContextMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardTextContextChangeInfoMETA>* changeInfo) {}

    virtual void Process_xrEnumerateExternalCamerasOCULUS(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    cameraCapacityInput,
        PointerDecoder<uint32_t>*                   cameraCountOutput,
        StructPointerDecoder<Decoded_XrExternalCameraOCULUS>* cameras) {}

    virtual void Process_xrEnumeratePerformanceMetricsCounterPathsMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        uint32_t                                    counterPathCapacityInput,
        PointerDecoder<uint32_t>*                   counterPathCountOutput,
        PointerDecoder<XrPath>*                     counterPaths) {}

    virtual void Process_xrSetPerformanceMetricsStateMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA>* state) {}

    virtual void Process_xrGetPerformanceMetricsStateMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA>* state) {}

    virtual void Process_xrQueryPerformanceMetricsCounterMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      counterPath,
        StructPointerDecoder<Decoded_XrPerformanceMetricsCounterMETA>* counter) {}

    virtual void Process_xrSaveSpaceListFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceListSaveInfoFB>* info,
        PointerDecoder<XrAsyncRequestIdFB>*         requestId) {}

    virtual void Process_xrCreateSpaceUserFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceUserCreateInfoFB>* info,
        HandlePointerDecoder<XrSpaceUserFB>*        user) {}

    virtual void Process_xrGetSpaceUserIdFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            user,
        PointerDecoder<XrSpaceUserIdFB>*            userId) {}

    virtual void Process_xrDestroySpaceUserFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            user) {}

    virtual void Process_xrGetRecommendedLayerResolutionMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrRecommendedLayerResolutionGetInfoMETA>* info,
        StructPointerDecoder<Decoded_XrRecommendedLayerResolutionMETA>* resolution) {}

    virtual void Process_xrCreatePassthroughColorLutMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            passthrough,
        StructPointerDecoder<Decoded_XrPassthroughColorLutCreateInfoMETA>* createInfo,
        HandlePointerDecoder<XrPassthroughColorLutMETA>* colorLut) {}

    virtual void Process_xrDestroyPassthroughColorLutMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            colorLut) {}

    virtual void Process_xrUpdatePassthroughColorLutMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            colorLut,
        StructPointerDecoder<Decoded_XrPassthroughColorLutUpdateInfoMETA>* updateInfo) {}

    virtual void Process_xrGetSpaceTriangleMeshMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrSpaceTriangleMeshGetInfoMETA>* getInfo,
        StructPointerDecoder<Decoded_XrSpaceTriangleMeshMETA>* triangleMeshOutput) {}

    virtual void Process_xrCreateFaceTracker2FB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFaceTrackerCreateInfo2FB>* createInfo,
        HandlePointerDecoder<XrFaceTracker2FB>*     faceTracker) {}

    virtual void Process_xrDestroyFaceTracker2FB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            faceTracker) {}

    virtual void Process_xrGetFaceExpressionWeights2FB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            faceTracker,
        StructPointerDecoder<Decoded_XrFaceExpressionInfo2FB>* expressionInfo,
        StructPointerDecoder<Decoded_XrFaceExpressionWeights2FB>* expressionWeights) {}

    virtual void Process_xrSetTrackingOptimizationSettingsHintQCOM(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrTrackingOptimizationSettingsDomainQCOM    domain,
        XrTrackingOptimizationSettingsHintQCOM      hint) {}

    virtual void Process_xrCreatePassthroughHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPassthroughCreateInfoHTC>* createInfo,
        HandlePointerDecoder<XrPassthroughHTC>*     passthrough) {}

    virtual void Process_xrDestroyPassthroughHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            passthrough) {}

    virtual void Process_xrApplyFoveationHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFoveationApplyInfoHTC>* applyInfo) {}

    virtual void Process_xrCreateSpatialAnchorHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoHTC>* createInfo,
        HandlePointerDecoder<XrSpace>*              anchor) {}

    virtual void Process_xrGetSpatialAnchorNameHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            anchor,
        StructPointerDecoder<Decoded_XrSpatialAnchorNameHTC>* name) {}

    virtual void Process_xrApplyForceFeedbackCurlMNDX(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker,
        StructPointerDecoder<Decoded_XrForceFeedbackCurlApplyLocationsMNDX>* locations) {}

    virtual void Process_xrCreatePlaneDetectorEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPlaneDetectorCreateInfoEXT>* createInfo,
        HandlePointerDecoder<XrPlaneDetectorEXT>*   planeDetector) {}

    virtual void Process_xrDestroyPlaneDetectorEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            planeDetector) {}

    virtual void Process_xrBeginPlaneDetectionEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            planeDetector,
        StructPointerDecoder<Decoded_XrPlaneDetectorBeginInfoEXT>* beginInfo) {}

    virtual void Process_xrGetPlaneDetectionStateEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            planeDetector,
        PointerDecoder<XrPlaneDetectionStateEXT>*   state) {}

    virtual void Process_xrGetPlaneDetectionsEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            planeDetector,
        StructPointerDecoder<Decoded_XrPlaneDetectorGetInfoEXT>* info,
        StructPointerDecoder<Decoded_XrPlaneDetectorLocationsEXT>* locations) {}

    virtual void Process_xrGetPlanePolygonBufferEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            planeDetector,
        uint64_t                                    planeId,
        uint32_t                                    polygonBufferIndex,
        StructPointerDecoder<Decoded_XrPlaneDetectorPolygonBufferEXT>* polygonBuffer) {}

    virtual void Process_xrEnableUserCalibrationEventsML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrUserCalibrationEnableEventsInfoML>* enableInfo) {}
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_CONSUMER_H
