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

#ifndef  GFXRECON_GENERATED_OPENXR_DECODER_H
#define  GFXRECON_GENERATED_OPENXR_DECODER_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "decode/openxr_decoder_base.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class OpenXrDecoder : public OpenXrDecoderBase
{
  public:
    OpenXrDecoder() { }

    virtual ~OpenXrDecoder() override { }

    virtual void DecodeFunctionCall(format::ApiCallId             call_id,
                                    const ApiCallInfo&            call_info,
                                    const uint8_t*                parameter_buffer,
                                    size_t                        buffer_size) override;

  private:
    size_t Decode_xrDestroyInstance(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetInstanceProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrPollEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrResultToString(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrStructureTypeToString(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSystem(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSystemProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateEnvironmentBlendModes(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSession(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroySession(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateReferenceSpaces(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateReferenceSpace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetReferenceSpaceBoundsRect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateActionSpace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrLocateSpace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroySpace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateViewConfigurations(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetViewConfigurationProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateViewConfigurationViews(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateSwapchainFormats(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSwapchain(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroySwapchain(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrAcquireSwapchainImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrWaitSwapchainImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrReleaseSwapchainImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrBeginSession(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEndSession(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrRequestExitSession(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrWaitFrame(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrBeginFrame(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEndFrame(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrLocateViews(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrStringToPath(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrPathToString(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateActionSet(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyActionSet(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateAction(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyAction(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSuggestInteractionProfileBindings(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrAttachSessionActionSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetCurrentInteractionProfile(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetActionStateBoolean(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetActionStateFloat(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetActionStateVector2f(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetActionStatePose(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSyncActions(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateBoundSourcesForAction(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetInputSourceLocalizedName(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrApplyHapticFeedback(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrStopHapticFeedback(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateApiLayerInstance(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetAndroidApplicationThreadKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSwapchainAndroidSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetOpenGLGraphicsRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetOpenGLESGraphicsRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVulkanInstanceExtensionsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVulkanDeviceExtensionsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVulkanGraphicsDeviceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVulkanGraphicsRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetD3D11GraphicsRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetD3D12GraphicsRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVisibilityMaskKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrConvertWin32PerformanceCounterToTimeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrConvertTimeToWin32PerformanceCounterKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrConvertTimespecTimeToTimeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrConvertTimeToTimespecTimeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrInitializeLoaderKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateVulkanInstanceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateVulkanDeviceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVulkanGraphicsDevice2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVulkanGraphicsRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrPerfSettingsSetPerformanceLevelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrThermalGetTemperatureTrendEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetDebugUtilsObjectNameEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateDebugUtilsMessengerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyDebugUtilsMessengerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSubmitDebugUtilsMessageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSessionBeginDebugUtilsLabelRegionEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSessionEndDebugUtilsLabelRegionEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSessionInsertDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSpatialAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSpatialAnchorSpaceMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroySpatialAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetInputDeviceActiveEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetInputDeviceStateBoolEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetInputDeviceStateFloatEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetInputDeviceStateVector2fEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetInputDeviceLocationEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSpatialGraphNodeSpaceMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrTryCreateSpatialGraphStaticNodeBindingMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroySpatialGraphNodeBindingMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpatialGraphNodeBindingPropertiesMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateHandTrackerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyHandTrackerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrLocateHandJointsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateHandMeshSpaceMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrUpdateHandMeshMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetControllerModelKeyMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrLoadControllerModelMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetControllerModelPropertiesMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetControllerModelStateMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateReprojectionModesMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrUpdateSwapchainFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSwapchainStateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateBodyTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyBodyTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrLocateBodyJointsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetBodySkeletonFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateSceneComputeFeaturesMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSceneObserverMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroySceneObserverMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSceneMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroySceneMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrComputeNewSceneMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSceneComputeStateMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSceneComponentsMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrLocateSceneComponentsMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSceneMeshBuffersMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDeserializeSceneMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSerializedSceneFragmentDataMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateDisplayRefreshRatesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetDisplayRefreshRateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrRequestDisplayRefreshRateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateViveTrackerPathsHTCX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateFacialTrackerHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyFacialTrackerHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetFacialExpressionsHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateColorSpacesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetColorSpaceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetHandMeshFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSpatialAnchorFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpaceUuidFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateSpaceSupportedComponentsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetSpaceComponentStatusFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpaceComponentStatusFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateFoveationProfileFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyFoveationProfileFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrQuerySystemTrackedKeyboardFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateKeyboardSpaceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrTriangleMeshBeginUpdateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrTriangleMeshEndUpdateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrTriangleMeshBeginVertexBufferUpdateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrTriangleMeshEndVertexBufferUpdateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreatePassthroughFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyPassthroughFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrPassthroughStartFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrPassthroughPauseFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreatePassthroughLayerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyPassthroughLayerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrPassthroughLayerPauseFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrPassthroughLayerResumeFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrPassthroughLayerSetStyleFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateGeometryInstanceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyGeometryInstanceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGeometryInstanceSetTransformFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateRenderModelPathsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetRenderModelPropertiesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrLoadRenderModelFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetEnvironmentDepthEstimationVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetMarkerTrackingVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetMarkerTrackingTimeoutVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetMarkerTrackingPredictionVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetMarkerSizeVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateMarkerSpaceVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetViewOffsetVARJO(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSpaceFromCoordinateFrameUIDML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateMarkerDetectorML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyMarkerDetectorML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSnapshotMarkerDetectorML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetMarkerDetectorStateML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetMarkersML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetMarkerReprojectionErrorML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetMarkerLengthML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetMarkerNumberML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetMarkerStringML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateMarkerSpaceML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnableLocalizationEventsML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrQueryLocalizationMapsML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrRequestMapLocalizationML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrImportLocalizationMapML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateExportedLocalizationMapML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyExportedLocalizationMapML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetExportedLocalizationMapDataML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSpatialAnchorStoreConnectionMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroySpatialAnchorStoreConnectionMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrPersistSpatialAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumeratePersistedSpatialAnchorNamesMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSpatialAnchorFromPersistedNameMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrUnpersistSpatialAnchorMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrClearSpatialAnchorStoreMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSceneMarkerRawDataMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSceneMarkerDecodedStringMSFT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrQuerySpacesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrRetrieveSpaceQueryResultsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSaveSpaceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEraseSpaceFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetAudioOutputDeviceGuidOculus(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetAudioInputDeviceGuidOculus(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrShareSpacesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpaceBoundingBox2DFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpaceBoundingBox3DFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpaceSemanticLabelsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpaceBoundary2DFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpaceRoomLayoutFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetDigitalLensControlALMALENCE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrRequestSceneCaptureFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpaceContainerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetFoveationEyeTrackedStateMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateFaceTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyFaceTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetFaceExpressionWeightsFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateEyeTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyEyeTrackerFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetEyeGazesFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrPassthroughLayerSetKeyboardHandsIntensityFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetDeviceSampleRateFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetPassthroughPreferencesMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateVirtualKeyboardMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyVirtualKeyboardMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateVirtualKeyboardSpaceMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSuggestVirtualKeyboardLocationMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVirtualKeyboardScaleMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetVirtualKeyboardModelVisibilityMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVirtualKeyboardModelAnimationStatesMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVirtualKeyboardDirtyTexturesMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetVirtualKeyboardTextureDataMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSendVirtualKeyboardInputMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrChangeVirtualKeyboardTextContextMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumerateExternalCamerasOCULUS(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnumeratePerformanceMetricsCounterPathsMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetPerformanceMetricsStateMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetPerformanceMetricsStateMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrQueryPerformanceMetricsCounterMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSaveSpaceListFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSpaceUserFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpaceUserIdFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroySpaceUserFB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetRecommendedLayerResolutionMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreatePassthroughColorLutMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyPassthroughColorLutMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrUpdatePassthroughColorLutMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpaceTriangleMeshMETA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateFaceTracker2FB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyFaceTracker2FB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetFaceExpressionWeights2FB(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrSetTrackingOptimizationSettingsHintQCOM(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreatePassthroughHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyPassthroughHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrApplyFoveationHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreateSpatialAnchorHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetSpatialAnchorNameHTC(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrApplyForceFeedbackCurlMNDX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrCreatePlaneDetectorEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrDestroyPlaneDetectorEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrBeginPlaneDetectionEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetPlaneDetectionStateEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetPlaneDetectionsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrGetPlanePolygonBufferEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_xrEnableUserCalibrationEventsML(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_DECODER_H
