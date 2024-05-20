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

#ifndef  GFXRECON_GENERATED_OPENXR_JSON_CONSUMER_H
#define  GFXRECON_GENERATED_OPENXR_JSON_CONSUMER_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "decode/openxr_json_consumer_base.h"
#include "generated/generated_openxr_struct_decoders.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class OpenXrExportJsonConsumer : public OpenXrExportJsonConsumerBase
{
  public:
    OpenXrExportJsonConsumer() { }

    virtual ~OpenXrExportJsonConsumer() override { }

    virtual void Process_xrDestroyInstance(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance) override;

    virtual void Process_xrGetInstanceProperties(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrInstanceProperties>* instanceProperties) override;

    virtual void Process_xrPollEvent(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrEventDataBuffer>* eventData) override;

    virtual void Process_xrResultToString(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrResult                                    value,
        StringDecoder*                              buffer) override;

    virtual void Process_xrStructureTypeToString(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrStructureType                             value,
        StringDecoder*                              buffer) override;

    virtual void Process_xrGetSystem(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrSystemGetInfo>* getInfo,
        HandlePointerDecoder<XrSystemId>*           systemId) override;

    virtual void Process_xrGetSystemProperties(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrSystemProperties>* properties) override;

    virtual void Process_xrEnumerateEnvironmentBlendModes(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        XrViewConfigurationType                     viewConfigurationType,
        uint32_t                                    environmentBlendModeCapacityInput,
        PointerDecoder<uint32_t>*                   environmentBlendModeCountOutput,
        PointerDecoder<XrEnvironmentBlendMode>*     environmentBlendModes) override;

    virtual void Process_xrCreateSession(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrSessionCreateInfo>* createInfo,
        HandlePointerDecoder<XrSession>*            session) override;

    virtual void Process_xrDestroySession(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session) override;

    virtual void Process_xrEnumerateReferenceSpaces(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    spaceCapacityInput,
        PointerDecoder<uint32_t>*                   spaceCountOutput,
        PointerDecoder<XrReferenceSpaceType>*       spaces) override;

    virtual void Process_xrCreateReferenceSpace(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrReferenceSpaceCreateInfo>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) override;

    virtual void Process_xrGetReferenceSpaceBoundsRect(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrReferenceSpaceType                        referenceSpaceType,
        StructPointerDecoder<Decoded_XrExtent2Df>*  bounds) override;

    virtual void Process_xrCreateActionSpace(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionSpaceCreateInfo>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) override;

    virtual void Process_xrLocateSpace(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        format::HandleId                            baseSpace,
        XrTime                                      time,
        StructPointerDecoder<Decoded_XrSpaceLocation>* location) override;

    virtual void Process_xrDestroySpace(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space) override;

    virtual void Process_xrEnumerateViewConfigurations(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        uint32_t                                    viewConfigurationTypeCapacityInput,
        PointerDecoder<uint32_t>*                   viewConfigurationTypeCountOutput,
        PointerDecoder<XrViewConfigurationType>*    viewConfigurationTypes) override;

    virtual void Process_xrGetViewConfigurationProperties(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        XrViewConfigurationType                     viewConfigurationType,
        StructPointerDecoder<Decoded_XrViewConfigurationProperties>* configurationProperties) override;

    virtual void Process_xrEnumerateViewConfigurationViews(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        XrViewConfigurationType                     viewConfigurationType,
        uint32_t                                    viewCapacityInput,
        PointerDecoder<uint32_t>*                   viewCountOutput,
        StructPointerDecoder<Decoded_XrViewConfigurationView>* views) override;

    virtual void Process_xrEnumerateSwapchainFormats(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    formatCapacityInput,
        PointerDecoder<uint32_t>*                   formatCountOutput,
        PointerDecoder<int64_t>*                    formats) override;

    virtual void Process_xrCreateSwapchain(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* createInfo,
        HandlePointerDecoder<XrSwapchain>*          swapchain) override;

    virtual void Process_xrDestroySwapchain(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain) override;

    virtual void Process_xrAcquireSwapchainImage(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_XrSwapchainImageAcquireInfo>* acquireInfo,
        PointerDecoder<uint32_t>*                   index) override;

    virtual void Process_xrWaitSwapchainImage(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_XrSwapchainImageWaitInfo>* waitInfo) override;

    virtual void Process_xrReleaseSwapchainImage(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_XrSwapchainImageReleaseInfo>* releaseInfo) override;

    virtual void Process_xrBeginSession(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSessionBeginInfo>* beginInfo) override;

    virtual void Process_xrEndSession(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session) override;

    virtual void Process_xrRequestExitSession(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session) override;

    virtual void Process_xrWaitFrame(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFrameWaitInfo>* frameWaitInfo,
        StructPointerDecoder<Decoded_XrFrameState>* frameState) override;

    virtual void Process_xrBeginFrame(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFrameBeginInfo>* frameBeginInfo) override;

    virtual void Process_xrEndFrame(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFrameEndInfo>* frameEndInfo) override;

    virtual void Process_xrLocateViews(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrViewLocateInfo>* viewLocateInfo,
        StructPointerDecoder<Decoded_XrViewState>*  viewState,
        uint32_t                                    viewCapacityInput,
        PointerDecoder<uint32_t>*                   viewCountOutput,
        StructPointerDecoder<Decoded_XrView>*       views) override;

    virtual void Process_xrStringToPath(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StringDecoder*                              pathString,
        HandlePointerDecoder<XrPath>*               path) override;

    virtual void Process_xrPathToString(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrPath                                      path,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) override;

    virtual void Process_xrCreateActionSet(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrActionSetCreateInfo>* createInfo,
        HandlePointerDecoder<XrActionSet>*          actionSet) override;

    virtual void Process_xrDestroyActionSet(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            actionSet) override;

    virtual void Process_xrCreateAction(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            actionSet,
        StructPointerDecoder<Decoded_XrActionCreateInfo>* createInfo,
        HandlePointerDecoder<XrAction>*             action) override;

    virtual void Process_xrDestroyAction(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            action) override;

    virtual void Process_xrSuggestInteractionProfileBindings(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrInteractionProfileSuggestedBinding>* suggestedBindings) override;

    virtual void Process_xrAttachSessionActionSets(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSessionActionSetsAttachInfo>* attachInfo) override;

    virtual void Process_xrGetCurrentInteractionProfile(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelUserPath,
        StructPointerDecoder<Decoded_XrInteractionProfileState>* interactionProfile) override;

    virtual void Process_xrGetActionStateBoolean(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
        StructPointerDecoder<Decoded_XrActionStateBoolean>* state) override;

    virtual void Process_xrGetActionStateFloat(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
        StructPointerDecoder<Decoded_XrActionStateFloat>* state) override;

    virtual void Process_xrGetActionStateVector2f(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
        StructPointerDecoder<Decoded_XrActionStateVector2f>* state) override;

    virtual void Process_xrGetActionStatePose(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionStateGetInfo>* getInfo,
        StructPointerDecoder<Decoded_XrActionStatePose>* state) override;

    virtual void Process_xrSyncActions(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrActionsSyncInfo>* syncInfo) override;

    virtual void Process_xrEnumerateBoundSourcesForAction(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrBoundSourcesForActionEnumerateInfo>* enumerateInfo,
        uint32_t                                    sourceCapacityInput,
        PointerDecoder<uint32_t>*                   sourceCountOutput,
        HandlePointerDecoder<XrPath>*               sources) override;

    virtual void Process_xrGetInputSourceLocalizedName(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrInputSourceLocalizedNameGetInfo>* getInfo,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) override;

    virtual void Process_xrApplyHapticFeedback(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo,
        StructPointerDecoder<Decoded_XrHapticBaseHeader>* hapticFeedback) override;

    virtual void Process_xrStopHapticFeedback(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo) override;

    virtual void Process_xrCreateApiLayerInstance(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        StructPointerDecoder<Decoded_XrInstanceCreateInfo>* info,
        StructPointerDecoder<Decoded_XrApiLayerCreateInfo>* layerInfo,
        HandlePointerDecoder<XrInstance>*           instance) override;

    virtual void Process_xrSetAndroidApplicationThreadKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrAndroidThreadTypeKHR                      threadType,
        uint32_t                                    threadId) override;

    virtual void Process_xrCreateSwapchainAndroidSurfaceKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSwapchainCreateInfo>* info,
        HandlePointerDecoder<XrSwapchain>*          swapchain,
        uint64_t                                    surface) override;

    virtual void Process_xrGetOpenGLGraphicsRequirementsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLKHR>* graphicsRequirements) override;

    virtual void Process_xrGetOpenGLESGraphicsRequirementsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsOpenGLESKHR>* graphicsRequirements) override;

    virtual void Process_xrGetVulkanInstanceExtensionsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) override;

    virtual void Process_xrGetVulkanDeviceExtensionsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) override;

    virtual void Process_xrGetVulkanGraphicsDeviceKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        format::HandleId                            vkInstance,
        HandlePointerDecoder<VkPhysicalDevice>*     vkPhysicalDevice) override;

    virtual void Process_xrGetVulkanGraphicsRequirementsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements) override;

    virtual void Process_xrGetD3D11GraphicsRequirementsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D11KHR>* graphicsRequirements) override;

    virtual void Process_xrGetD3D12GraphicsRequirementsKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsD3D12KHR>* graphicsRequirements) override;

    virtual void Process_xrGetVisibilityMaskKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrViewConfigurationType                     viewConfigurationType,
        uint32_t                                    viewIndex,
        XrVisibilityMaskTypeKHR                     visibilityMaskType,
        StructPointerDecoder<Decoded_XrVisibilityMaskKHR>* visibilityMask) override;

    virtual void Process_xrConvertWin32PerformanceCounterToTimeKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<LARGE_INTEGER>*              performanceCounter,
        PointerDecoder<XrTime>*                     time) override;

    virtual void Process_xrConvertTimeToWin32PerformanceCounterKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrTime                                      time,
        PointerDecoder<LARGE_INTEGER>*              performanceCounter) override;

    virtual void Process_xrConvertTimespecTimeToTimeKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_timespec>*     timespecTime,
        PointerDecoder<XrTime>*                     time) override;

    virtual void Process_xrConvertTimeToTimespecTimeKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrTime                                      time,
        StructPointerDecoder<Decoded_timespec>*     timespecTime) override;


    virtual void Process_xrCreateVulkanInstanceKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrVulkanInstanceCreateInfoKHR>* createInfo,
        HandlePointerDecoder<VkInstance>*           vulkanInstance,
        PointerDecoder<VkResult>*                   vulkanResult) override;

    virtual void Process_xrCreateVulkanDeviceKHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrVulkanDeviceCreateInfoKHR>* createInfo,
        HandlePointerDecoder<VkDevice>*             vulkanDevice,
        PointerDecoder<VkResult>*                   vulkanResult) override;

    virtual void Process_xrGetVulkanGraphicsDevice2KHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrVulkanGraphicsDeviceGetInfoKHR>* getInfo,
        HandlePointerDecoder<VkPhysicalDevice>*     vulkanPhysicalDevice) override;

    virtual void Process_xrGetVulkanGraphicsRequirements2KHR(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        StructPointerDecoder<Decoded_XrGraphicsRequirementsVulkanKHR>* graphicsRequirements) override;

    virtual void Process_xrPerfSettingsSetPerformanceLevelEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPerfSettingsDomainEXT                     domain,
        XrPerfSettingsLevelEXT                      level) override;

    virtual void Process_xrThermalGetTemperatureTrendEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPerfSettingsDomainEXT                     domain,
        PointerDecoder<XrPerfSettingsNotificationLevelEXT>* notificationLevel,
        PointerDecoder<float>*                      tempHeadroom,
        PointerDecoder<float>*                      tempSlope) override;

    virtual void Process_xrSetDebugUtilsObjectNameEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrDebugUtilsObjectNameInfoEXT>* nameInfo) override;

    virtual void Process_xrCreateDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrDebugUtilsMessengerCreateInfoEXT>* createInfo,
        HandlePointerDecoder<XrDebugUtilsMessengerEXT>* messenger) override;

    virtual void Process_xrDestroyDebugUtilsMessengerEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            messenger) override;

    virtual void Process_xrSubmitDebugUtilsMessageEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrDebugUtilsMessageSeverityFlagsEXT         messageSeverity,
        XrDebugUtilsMessageTypeFlagsEXT             messageTypes,
        StructPointerDecoder<Decoded_XrDebugUtilsMessengerCallbackDataEXT>* callbackData) override;

    virtual void Process_xrSessionBeginDebugUtilsLabelRegionEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* labelInfo) override;

    virtual void Process_xrSessionEndDebugUtilsLabelRegionEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session) override;

    virtual void Process_xrSessionInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrDebugUtilsLabelEXT>* labelInfo) override;

    virtual void Process_xrCreateSpatialAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpatialAnchorMSFT>*  anchor) override;

    virtual void Process_xrCreateSpatialAnchorSpaceMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialAnchorSpaceCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) override;

    virtual void Process_xrDestroySpatialAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            anchor) override;

    virtual void Process_xrSetInputDeviceActiveEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      interactionProfile,
        XrPath                                      topLevelPath,
        XrBool32                                    isActive) override;

    virtual void Process_xrSetInputDeviceStateBoolEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelPath,
        XrPath                                      inputSourcePath,
        XrBool32                                    state) override;

    virtual void Process_xrSetInputDeviceStateFloatEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelPath,
        XrPath                                      inputSourcePath,
        float                                       state) override;

    virtual void Process_xrSetInputDeviceStateVector2fEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelPath,
        XrPath                                      inputSourcePath,
        Decoded_XrVector2f                          state) override;

    virtual void Process_xrSetInputDeviceLocationEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelPath,
        XrPath                                      inputSourcePath,
        format::HandleId                            space,
        Decoded_XrPosef                             pose) override;

    virtual void Process_xrCreateSpatialGraphNodeSpaceMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) override;

    virtual void Process_xrTryCreateSpatialGraphStaticNodeBindingMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpatialGraphNodeBindingMSFT>* nodeBinding) override;

    virtual void Process_xrDestroySpatialGraphNodeBindingMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            nodeBinding) override;

    virtual void Process_xrGetSpatialGraphNodeBindingPropertiesMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            nodeBinding,
        StructPointerDecoder<Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT>* getInfo,
        StructPointerDecoder<Decoded_XrSpatialGraphNodeBindingPropertiesMSFT>* properties) override;

    virtual void Process_xrCreateHandTrackerEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrHandTrackerCreateInfoEXT>* createInfo,
        HandlePointerDecoder<XrHandTrackerEXT>*     handTracker) override;

    virtual void Process_xrDestroyHandTrackerEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker) override;

    virtual void Process_xrLocateHandJointsEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker,
        StructPointerDecoder<Decoded_XrHandJointsLocateInfoEXT>* locateInfo,
        StructPointerDecoder<Decoded_XrHandJointLocationsEXT>* locations) override;

    virtual void Process_xrCreateHandMeshSpaceMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker,
        StructPointerDecoder<Decoded_XrHandMeshSpaceCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) override;

    virtual void Process_xrUpdateHandMeshMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker,
        StructPointerDecoder<Decoded_XrHandMeshUpdateInfoMSFT>* updateInfo,
        StructPointerDecoder<Decoded_XrHandMeshMSFT>* handMesh) override;

    virtual void Process_xrGetControllerModelKeyMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      topLevelUserPath,
        StructPointerDecoder<Decoded_XrControllerModelKeyStateMSFT>* controllerModelKeyState) override;

    virtual void Process_xrLoadControllerModelMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrControllerModelKeyMSFT                    modelKey,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        PointerDecoder<uint8_t>*                    buffer) override;

    virtual void Process_xrGetControllerModelPropertiesMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrControllerModelKeyMSFT                    modelKey,
        StructPointerDecoder<Decoded_XrControllerModelPropertiesMSFT>* properties) override;

    virtual void Process_xrGetControllerModelStateMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrControllerModelKeyMSFT                    modelKey,
        StructPointerDecoder<Decoded_XrControllerModelStateMSFT>* state) override;

    virtual void Process_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint64_t                                    perceptionAnchor,
        HandlePointerDecoder<XrSpatialAnchorMSFT>*  anchor) override;

    virtual void Process_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            anchor,
        PointerDecoder<uint64_t, void*>*            perceptionAnchor) override;

    virtual void Process_xrEnumerateReprojectionModesMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        XrViewConfigurationType                     viewConfigurationType,
        uint32_t                                    modeCapacityInput,
        PointerDecoder<uint32_t>*                   modeCountOutput,
        PointerDecoder<XrReprojectionModeMSFT>*     modes) override;

    virtual void Process_xrUpdateSwapchainFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state) override;

    virtual void Process_xrGetSwapchainStateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_XrSwapchainStateBaseHeaderFB>* state) override;

    virtual void Process_xrCreateBodyTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrBodyTrackerCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrBodyTrackerFB>*      bodyTracker) override;

    virtual void Process_xrDestroyBodyTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            bodyTracker) override;

    virtual void Process_xrLocateBodyJointsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            bodyTracker,
        StructPointerDecoder<Decoded_XrBodyJointsLocateInfoFB>* locateInfo,
        StructPointerDecoder<Decoded_XrBodyJointLocationsFB>* locations) override;

    virtual void Process_xrGetBodySkeletonFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            bodyTracker,
        StructPointerDecoder<Decoded_XrBodySkeletonFB>* skeleton) override;

    virtual void Process_xrEnumerateSceneComputeFeaturesMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        XrSystemId                                  systemId,
        uint32_t                                    featureCapacityInput,
        PointerDecoder<uint32_t>*                   featureCountOutput,
        PointerDecoder<XrSceneComputeFeatureMSFT>*  features) override;

    virtual void Process_xrCreateSceneObserverMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSceneObserverCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSceneObserverMSFT>*  sceneObserver) override;

    virtual void Process_xrDestroySceneObserverMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            sceneObserver) override;

    virtual void Process_xrCreateSceneMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            sceneObserver,
        StructPointerDecoder<Decoded_XrSceneCreateInfoMSFT>* createInfo,
        HandlePointerDecoder<XrSceneMSFT>*          scene) override;

    virtual void Process_xrDestroySceneMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene) override;

    virtual void Process_xrComputeNewSceneMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            sceneObserver,
        StructPointerDecoder<Decoded_XrNewSceneComputeInfoMSFT>* computeInfo) override;

    virtual void Process_xrGetSceneComputeStateMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            sceneObserver,
        PointerDecoder<XrSceneComputeStateMSFT>*    state) override;

    virtual void Process_xrGetSceneComponentsMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrSceneComponentsGetInfoMSFT>* getInfo,
        StructPointerDecoder<Decoded_XrSceneComponentsMSFT>* components) override;

    virtual void Process_xrLocateSceneComponentsMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrSceneComponentsLocateInfoMSFT>* locateInfo,
        StructPointerDecoder<Decoded_XrSceneComponentLocationsMSFT>* locations) override;

    virtual void Process_xrGetSceneMeshBuffersMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrSceneMeshBuffersGetInfoMSFT>* getInfo,
        StructPointerDecoder<Decoded_XrSceneMeshBuffersMSFT>* buffers) override;

    virtual void Process_xrDeserializeSceneMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            sceneObserver,
        StructPointerDecoder<Decoded_XrSceneDeserializeInfoMSFT>* deserializeInfo) override;

    virtual void Process_xrGetSerializedSceneFragmentDataMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrSerializedSceneFragmentDataGetInfoMSFT>* getInfo,
        uint32_t                                    countInput,
        PointerDecoder<uint32_t>*                   readOutput,
        PointerDecoder<uint8_t>*                    buffer) override;

    virtual void Process_xrEnumerateDisplayRefreshRatesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    displayRefreshRateCapacityInput,
        PointerDecoder<uint32_t>*                   displayRefreshRateCountOutput,
        PointerDecoder<float>*                      displayRefreshRates) override;

    virtual void Process_xrGetDisplayRefreshRateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        PointerDecoder<float>*                      displayRefreshRate) override;

    virtual void Process_xrRequestDisplayRefreshRateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        float                                       displayRefreshRate) override;

    virtual void Process_xrEnumerateViveTrackerPathsHTCX(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        uint32_t                                    pathCapacityInput,
        PointerDecoder<uint32_t>*                   pathCountOutput,
        StructPointerDecoder<Decoded_XrViveTrackerPathsHTCX>* paths) override;

    virtual void Process_xrCreateFacialTrackerHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFacialTrackerCreateInfoHTC>* createInfo,
        HandlePointerDecoder<XrFacialTrackerHTC>*   facialTracker) override;

    virtual void Process_xrDestroyFacialTrackerHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            facialTracker) override;

    virtual void Process_xrGetFacialExpressionsHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            facialTracker,
        StructPointerDecoder<Decoded_XrFacialExpressionsHTC>* facialExpressions) override;

    virtual void Process_xrEnumerateColorSpacesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    colorSpaceCapacityInput,
        PointerDecoder<uint32_t>*                   colorSpaceCountOutput,
        PointerDecoder<XrColorSpaceFB>*             colorSpaces) override;

    virtual void Process_xrSetColorSpaceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrColorSpaceFB                              colorSpace) override;

    virtual void Process_xrGetHandMeshFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker,
        StructPointerDecoder<Decoded_XrHandTrackingMeshFB>* mesh) override;

    virtual void Process_xrCreateSpatialAnchorFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoFB>* info,
        HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId) override;

    virtual void Process_xrGetSpaceUuidFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrUuidEXT>*    uuid) override;

    virtual void Process_xrEnumerateSpaceSupportedComponentsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        uint32_t                                    componentTypeCapacityInput,
        PointerDecoder<uint32_t>*                   componentTypeCountOutput,
        PointerDecoder<XrSpaceComponentTypeFB>*     componentTypes) override;

    virtual void Process_xrSetSpaceComponentStatusFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrSpaceComponentStatusSetInfoFB>* info,
        HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId) override;

    virtual void Process_xrGetSpaceComponentStatusFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        XrSpaceComponentTypeFB                      componentType,
        StructPointerDecoder<Decoded_XrSpaceComponentStatusFB>* status) override;

    virtual void Process_xrCreateFoveationProfileFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFoveationProfileCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrFoveationProfileFB>* profile) override;

    virtual void Process_xrDestroyFoveationProfileFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            profile) override;

    virtual void Process_xrQuerySystemTrackedKeyboardFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrKeyboardTrackingQueryFB>* queryInfo,
        StructPointerDecoder<Decoded_XrKeyboardTrackingDescriptionFB>* keyboard) override;

    virtual void Process_xrCreateKeyboardSpaceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrKeyboardSpaceCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrSpace>*              keyboardSpace) override;

    virtual void Process_xrTriangleMeshBeginUpdateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            mesh) override;

    virtual void Process_xrTriangleMeshEndUpdateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            mesh,
        uint32_t                                    vertexCount,
        uint32_t                                    triangleCount) override;

    virtual void Process_xrTriangleMeshBeginVertexBufferUpdateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            mesh,
        PointerDecoder<uint32_t>*                   outVertexCount) override;

    virtual void Process_xrTriangleMeshEndVertexBufferUpdateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            mesh) override;

    virtual void Process_xrCreatePassthroughFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPassthroughCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrPassthroughFB>*      outPassthrough) override;

    virtual void Process_xrDestroyPassthroughFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            passthrough) override;

    virtual void Process_xrPassthroughStartFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            passthrough) override;

    virtual void Process_xrPassthroughPauseFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            passthrough) override;

    virtual void Process_xrCreatePassthroughLayerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPassthroughLayerCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrPassthroughLayerFB>* outLayer) override;

    virtual void Process_xrDestroyPassthroughLayerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            layer) override;

    virtual void Process_xrPassthroughLayerPauseFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            layer) override;

    virtual void Process_xrPassthroughLayerResumeFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            layer) override;

    virtual void Process_xrPassthroughLayerSetStyleFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            layer,
        StructPointerDecoder<Decoded_XrPassthroughStyleFB>* style) override;

    virtual void Process_xrCreateGeometryInstanceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrGeometryInstanceCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrGeometryInstanceFB>* outGeometryInstance) override;

    virtual void Process_xrDestroyGeometryInstanceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance) override;

    virtual void Process_xrGeometryInstanceSetTransformFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrGeometryInstanceTransformFB>* transformation) override;

    virtual void Process_xrEnumerateRenderModelPathsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    pathCapacityInput,
        PointerDecoder<uint32_t>*                   pathCountOutput,
        StructPointerDecoder<Decoded_XrRenderModelPathInfoFB>* paths) override;

    virtual void Process_xrGetRenderModelPropertiesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      path,
        StructPointerDecoder<Decoded_XrRenderModelPropertiesFB>* properties) override;

    virtual void Process_xrLoadRenderModelFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrRenderModelLoadInfoFB>* info,
        StructPointerDecoder<Decoded_XrRenderModelBufferFB>* buffer) override;

    virtual void Process_xrSetEnvironmentDepthEstimationVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrBool32                                    enabled) override;

    virtual void Process_xrSetMarkerTrackingVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrBool32                                    enabled) override;

    virtual void Process_xrSetMarkerTrackingTimeoutVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint64_t                                    markerId,
        XrDuration                                  timeout) override;

    virtual void Process_xrSetMarkerTrackingPredictionVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint64_t                                    markerId,
        XrBool32                                    enable) override;

    virtual void Process_xrGetMarkerSizeVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint64_t                                    markerId,
        StructPointerDecoder<Decoded_XrExtent2Df>*  size) override;

    virtual void Process_xrCreateMarkerSpaceVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoVARJO>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) override;

    virtual void Process_xrSetViewOffsetVARJO(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        float                                       offset) override;

    virtual void Process_xrCreateSpaceFromCoordinateFrameUIDML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrCoordinateSpaceCreateInfoML>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) override;

    virtual void Process_xrCreateMarkerDetectorML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrMarkerDetectorCreateInfoML>* createInfo,
        HandlePointerDecoder<XrMarkerDetectorML>*   markerDetector) override;

    virtual void Process_xrDestroyMarkerDetectorML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector) override;

    virtual void Process_xrSnapshotMarkerDetectorML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        StructPointerDecoder<Decoded_XrMarkerDetectorSnapshotInfoML>* snapshotInfo) override;

    virtual void Process_xrGetMarkerDetectorStateML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        StructPointerDecoder<Decoded_XrMarkerDetectorStateML>* state) override;

    virtual void Process_xrGetMarkersML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        uint32_t                                    markerCapacityInput,
        PointerDecoder<uint32_t>*                   markerCountOutput,
        HandlePointerDecoder<XrMarkerML>*           markers) override;

    virtual void Process_xrGetMarkerReprojectionErrorML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        XrMarkerML                                  marker,
        PointerDecoder<float>*                      reprojectionErrorMeters) override;

    virtual void Process_xrGetMarkerLengthML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        XrMarkerML                                  marker,
        PointerDecoder<float>*                      meters) override;

    virtual void Process_xrGetMarkerNumberML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        XrMarkerML                                  marker,
        PointerDecoder<uint64_t>*                   number) override;

    virtual void Process_xrGetMarkerStringML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            markerDetector,
        XrMarkerML                                  marker,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) override;

    virtual void Process_xrCreateMarkerSpaceML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrMarkerSpaceCreateInfoML>* createInfo,
        HandlePointerDecoder<XrSpace>*              space) override;

    virtual void Process_xrEnableLocalizationEventsML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrLocalizationEnableEventsInfoML>* info) override;

    virtual void Process_xrQueryLocalizationMapsML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrLocalizationMapQueryInfoBaseHeaderML>* queryInfo,
        uint32_t                                    mapCapacityInput,
        PointerDecoder<uint32_t>*                   mapCountOutput,
        StructPointerDecoder<Decoded_XrLocalizationMapML>* maps) override;

    virtual void Process_xrRequestMapLocalizationML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrMapLocalizationRequestInfoML>* requestInfo) override;

    virtual void Process_xrImportLocalizationMapML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrLocalizationMapImportInfoML>* importInfo,
        StructPointerDecoder<Decoded_XrUuidEXT>*    mapUuid) override;

    virtual void Process_xrCreateExportedLocalizationMapML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrUuidEXT>*    mapUuid,
        HandlePointerDecoder<XrExportedLocalizationMapML>* map) override;

    virtual void Process_xrDestroyExportedLocalizationMapML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            map) override;

    virtual void Process_xrGetExportedLocalizationMapDataML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            map,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) override;

    virtual void Process_xrCreateSpatialAnchorStoreConnectionMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        HandlePointerDecoder<XrSpatialAnchorStoreConnectionMSFT>* spatialAnchorStore) override;

    virtual void Process_xrDestroySpatialAnchorStoreConnectionMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            spatialAnchorStore) override;

    virtual void Process_xrPersistSpatialAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            spatialAnchorStore,
        StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceInfoMSFT>* spatialAnchorPersistenceInfo) override;

    virtual void Process_xrEnumeratePersistedSpatialAnchorNamesMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            spatialAnchorStore,
        uint32_t                                    spatialAnchorNameCapacityInput,
        PointerDecoder<uint32_t>*                   spatialAnchorNameCountOutput,
        StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT>* spatialAnchorNames) override;

    virtual void Process_xrCreateSpatialAnchorFromPersistedNameMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT>* spatialAnchorCreateInfo,
        HandlePointerDecoder<XrSpatialAnchorMSFT>*  spatialAnchor) override;

    virtual void Process_xrUnpersistSpatialAnchorMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            spatialAnchorStore,
        StructPointerDecoder<Decoded_XrSpatialAnchorPersistenceNameMSFT>* spatialAnchorPersistenceName) override;

    virtual void Process_xrClearSpatialAnchorStoreMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            spatialAnchorStore) override;

    virtual void Process_xrGetSceneMarkerRawDataMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrUuidMSFT>*   markerId,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        PointerDecoder<uint8_t>*                    buffer) override;

    virtual void Process_xrGetSceneMarkerDecodedStringMSFT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            scene,
        StructPointerDecoder<Decoded_XrUuidMSFT>*   markerId,
        uint32_t                                    bufferCapacityInput,
        PointerDecoder<uint32_t>*                   bufferCountOutput,
        StringDecoder*                              buffer) override;

    virtual void Process_xrQuerySpacesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceQueryInfoBaseHeaderFB>* info,
        HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId) override;

    virtual void Process_xrRetrieveSpaceQueryResultsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrAsyncRequestIdFB                          requestId,
        StructPointerDecoder<Decoded_XrSpaceQueryResultsFB>* results) override;

    virtual void Process_xrSaveSpaceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceSaveInfoFB>* info,
        HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId) override;

    virtual void Process_xrEraseSpaceFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceEraseInfoFB>* info,
        HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId) override;

    virtual void Process_xrGetAudioOutputDeviceGuidOculus(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        WStringDecoder*                             buffer) override;

    virtual void Process_xrGetAudioInputDeviceGuidOculus(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        WStringDecoder*                             buffer) override;

    virtual void Process_xrShareSpacesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceShareInfoFB>* info,
        HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId) override;

    virtual void Process_xrGetSpaceBoundingBox2DFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrRect2Df>*    boundingBox2DOutput) override;

    virtual void Process_xrGetSpaceBoundingBox3DFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrRect3DfFB>*  boundingBox3DOutput) override;

    virtual void Process_xrGetSpaceSemanticLabelsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrSemanticLabelsFB>* semanticLabelsOutput) override;

    virtual void Process_xrGetSpaceBoundary2DFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrBoundary2DFB>* boundary2DOutput) override;

    virtual void Process_xrGetSpaceRoomLayoutFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrRoomLayoutFB>* roomLayoutOutput) override;

    virtual void Process_xrSetDigitalLensControlALMALENCE(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrDigitalLensControlALMALENCE>* digitalLensControl) override;

    virtual void Process_xrRequestSceneCaptureFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSceneCaptureRequestInfoFB>* info,
        HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId) override;

    virtual void Process_xrGetSpaceContainerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrSpaceContainerFB>* spaceContainerOutput) override;

    virtual void Process_xrGetFoveationEyeTrackedStateMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFoveationEyeTrackedStateMETA>* foveationState) override;

    virtual void Process_xrCreateFaceTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFaceTrackerCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrFaceTrackerFB>*      faceTracker) override;

    virtual void Process_xrDestroyFaceTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            faceTracker) override;

    virtual void Process_xrGetFaceExpressionWeightsFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            faceTracker,
        StructPointerDecoder<Decoded_XrFaceExpressionInfoFB>* expressionInfo,
        StructPointerDecoder<Decoded_XrFaceExpressionWeightsFB>* expressionWeights) override;

    virtual void Process_xrCreateEyeTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrEyeTrackerCreateInfoFB>* createInfo,
        HandlePointerDecoder<XrEyeTrackerFB>*       eyeTracker) override;

    virtual void Process_xrDestroyEyeTrackerFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            eyeTracker) override;

    virtual void Process_xrGetEyeGazesFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            eyeTracker,
        StructPointerDecoder<Decoded_XrEyeGazesInfoFB>* gazeInfo,
        StructPointerDecoder<Decoded_XrEyeGazesFB>* eyeGazes) override;

    virtual void Process_xrPassthroughLayerSetKeyboardHandsIntensityFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            layer,
        StructPointerDecoder<Decoded_XrPassthroughKeyboardHandsIntensityFB>* intensity) override;

    virtual void Process_xrGetDeviceSampleRateFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrHapticActionInfo>* hapticActionInfo,
        StructPointerDecoder<Decoded_XrDevicePcmSampleRateGetInfoFB>* deviceSampleRate) override;

    virtual void Process_xrGetPassthroughPreferencesMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPassthroughPreferencesMETA>* preferences) override;

    virtual void Process_xrCreateVirtualKeyboardMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrVirtualKeyboardCreateInfoMETA>* createInfo,
        HandlePointerDecoder<XrVirtualKeyboardMETA>* keyboard) override;

    virtual void Process_xrDestroyVirtualKeyboardMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard) override;

    virtual void Process_xrCreateVirtualKeyboardSpaceMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardSpaceCreateInfoMETA>* createInfo,
        HandlePointerDecoder<XrSpace>*              keyboardSpace) override;

    virtual void Process_xrSuggestVirtualKeyboardLocationMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardLocationInfoMETA>* locationInfo) override;

    virtual void Process_xrGetVirtualKeyboardScaleMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        PointerDecoder<float>*                      scale) override;

    virtual void Process_xrSetVirtualKeyboardModelVisibilityMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA>* modelVisibility) override;

    virtual void Process_xrGetVirtualKeyboardModelAnimationStatesMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardModelAnimationStatesMETA>* animationStates) override;

    virtual void Process_xrGetVirtualKeyboardDirtyTexturesMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        uint32_t                                    textureIdCapacityInput,
        PointerDecoder<uint32_t>*                   textureIdCountOutput,
        PointerDecoder<uint64_t>*                   textureIds) override;

    virtual void Process_xrGetVirtualKeyboardTextureDataMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        uint64_t                                    textureId,
        StructPointerDecoder<Decoded_XrVirtualKeyboardTextureDataMETA>* textureData) override;

    virtual void Process_xrSendVirtualKeyboardInputMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardInputInfoMETA>* info,
        StructPointerDecoder<Decoded_XrPosef>*      interactorRootPose) override;

    virtual void Process_xrChangeVirtualKeyboardTextContextMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            keyboard,
        StructPointerDecoder<Decoded_XrVirtualKeyboardTextContextChangeInfoMETA>* changeInfo) override;

    virtual void Process_xrEnumerateExternalCamerasOCULUS(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        uint32_t                                    cameraCapacityInput,
        PointerDecoder<uint32_t>*                   cameraCountOutput,
        StructPointerDecoder<Decoded_XrExternalCameraOCULUS>* cameras) override;

    virtual void Process_xrEnumeratePerformanceMetricsCounterPathsMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        uint32_t                                    counterPathCapacityInput,
        PointerDecoder<uint32_t>*                   counterPathCountOutput,
        HandlePointerDecoder<XrPath>*               counterPaths) override;

    virtual void Process_xrSetPerformanceMetricsStateMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA>* state) override;

    virtual void Process_xrGetPerformanceMetricsStateMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPerformanceMetricsStateMETA>* state) override;

    virtual void Process_xrQueryPerformanceMetricsCounterMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrPath                                      counterPath,
        StructPointerDecoder<Decoded_XrPerformanceMetricsCounterMETA>* counter) override;

    virtual void Process_xrSaveSpaceListFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceListSaveInfoFB>* info,
        HandlePointerDecoder<XrAsyncRequestIdFB>*   requestId) override;

    virtual void Process_xrCreateSpaceUserFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpaceUserCreateInfoFB>* info,
        HandlePointerDecoder<XrSpaceUserFB>*        user) override;

    virtual void Process_xrGetSpaceUserIdFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            user,
        PointerDecoder<XrSpaceUserIdFB>*            userId) override;

    virtual void Process_xrDestroySpaceUserFB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            user) override;

    virtual void Process_xrGetRecommendedLayerResolutionMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrRecommendedLayerResolutionGetInfoMETA>* info,
        StructPointerDecoder<Decoded_XrRecommendedLayerResolutionMETA>* resolution) override;

    virtual void Process_xrCreatePassthroughColorLutMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            passthrough,
        StructPointerDecoder<Decoded_XrPassthroughColorLutCreateInfoMETA>* createInfo,
        HandlePointerDecoder<XrPassthroughColorLutMETA>* colorLut) override;

    virtual void Process_xrDestroyPassthroughColorLutMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            colorLut) override;

    virtual void Process_xrUpdatePassthroughColorLutMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            colorLut,
        StructPointerDecoder<Decoded_XrPassthroughColorLutUpdateInfoMETA>* updateInfo) override;

    virtual void Process_xrGetSpaceTriangleMeshMETA(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            space,
        StructPointerDecoder<Decoded_XrSpaceTriangleMeshGetInfoMETA>* getInfo,
        StructPointerDecoder<Decoded_XrSpaceTriangleMeshMETA>* triangleMeshOutput) override;

    virtual void Process_xrCreateFaceTracker2FB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFaceTrackerCreateInfo2FB>* createInfo,
        HandlePointerDecoder<XrFaceTracker2FB>*     faceTracker) override;

    virtual void Process_xrDestroyFaceTracker2FB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            faceTracker) override;

    virtual void Process_xrGetFaceExpressionWeights2FB(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            faceTracker,
        StructPointerDecoder<Decoded_XrFaceExpressionInfo2FB>* expressionInfo,
        StructPointerDecoder<Decoded_XrFaceExpressionWeights2FB>* expressionWeights) override;

    virtual void Process_xrSetTrackingOptimizationSettingsHintQCOM(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        XrTrackingOptimizationSettingsDomainQCOM    domain,
        XrTrackingOptimizationSettingsHintQCOM      hint) override;

    virtual void Process_xrCreatePassthroughHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPassthroughCreateInfoHTC>* createInfo,
        HandlePointerDecoder<XrPassthroughHTC>*     passthrough) override;

    virtual void Process_xrDestroyPassthroughHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            passthrough) override;

    virtual void Process_xrApplyFoveationHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrFoveationApplyInfoHTC>* applyInfo) override;

    virtual void Process_xrCreateSpatialAnchorHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrSpatialAnchorCreateInfoHTC>* createInfo,
        HandlePointerDecoder<XrSpace>*              anchor) override;

    virtual void Process_xrGetSpatialAnchorNameHTC(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            anchor,
        StructPointerDecoder<Decoded_XrSpatialAnchorNameHTC>* name) override;

    virtual void Process_xrApplyForceFeedbackCurlMNDX(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            handTracker,
        StructPointerDecoder<Decoded_XrForceFeedbackCurlApplyLocationsMNDX>* locations) override;

    virtual void Process_xrCreatePlaneDetectorEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_XrPlaneDetectorCreateInfoEXT>* createInfo,
        HandlePointerDecoder<XrPlaneDetectorEXT>*   planeDetector) override;

    virtual void Process_xrDestroyPlaneDetectorEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            planeDetector) override;

    virtual void Process_xrBeginPlaneDetectionEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            planeDetector,
        StructPointerDecoder<Decoded_XrPlaneDetectorBeginInfoEXT>* beginInfo) override;

    virtual void Process_xrGetPlaneDetectionStateEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            planeDetector,
        PointerDecoder<XrPlaneDetectionStateEXT>*   state) override;

    virtual void Process_xrGetPlaneDetectionsEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            planeDetector,
        StructPointerDecoder<Decoded_XrPlaneDetectorGetInfoEXT>* info,
        StructPointerDecoder<Decoded_XrPlaneDetectorLocationsEXT>* locations) override;

    virtual void Process_xrGetPlanePolygonBufferEXT(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            planeDetector,
        uint64_t                                    planeId,
        uint32_t                                    polygonBufferIndex,
        StructPointerDecoder<Decoded_XrPlaneDetectorPolygonBufferEXT>* polygonBuffer) override;

    virtual void Process_xrEnableUserCalibrationEventsML(
        const ApiCallInfo&                          call_info,
        XrResult                                    returnValue,
        format::HandleId                            instance,
        StructPointerDecoder<Decoded_XrUserCalibrationEnableEventsInfoML>* enableInfo) override;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_JSON_CONSUMER_H
