/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#ifndef  GFXRECON_GENERATED_OPENXR_ENUM_TO_JSON_H
#define  GFXRECON_GENERATED_OPENXR_ENUM_TO_JSON_H

#if ENABLE_OPENXR_SUPPORT

#include "format/platform_types.h"
#include "util/json_util.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

#include <nlohmann/json.hpp>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

enum class XrAndroidSurfaceSwapchainFlagsFB_t : XrAndroidSurfaceSwapchainFlagsFB { };
enum class XrCompositionLayerFlags_t : XrCompositionLayerFlags { };
enum class XrCompositionLayerImageLayoutFlagsFB_t : XrCompositionLayerImageLayoutFlagsFB { };
enum class XrCompositionLayerSecureContentFlagsFB_t : XrCompositionLayerSecureContentFlagsFB { };
enum class XrCompositionLayerSettingsFlagsFB_t : XrCompositionLayerSettingsFlagsFB { };
enum class XrCompositionLayerSpaceWarpInfoFlagsFB_t : XrCompositionLayerSpaceWarpInfoFlagsFB { };
enum class XrDebugUtilsMessageSeverityFlagsEXT_t : XrDebugUtilsMessageSeverityFlagsEXT { };
enum class XrDebugUtilsMessageTypeFlagsEXT_t : XrDebugUtilsMessageTypeFlagsEXT { };
enum class XrDigitalLensControlFlagsALMALENCE_t : XrDigitalLensControlFlagsALMALENCE { };
enum class XrEnvironmentDepthProviderCreateFlagsMETA_t : XrEnvironmentDepthProviderCreateFlagsMETA { };
enum class XrEnvironmentDepthSwapchainCreateFlagsMETA_t : XrEnvironmentDepthSwapchainCreateFlagsMETA { };
enum class XrExternalCameraStatusFlagsOCULUS_t : XrExternalCameraStatusFlagsOCULUS { };
enum class XrFoveationDynamicFlagsHTC_t : XrFoveationDynamicFlagsHTC { };
enum class XrFoveationEyeTrackedProfileCreateFlagsMETA_t : XrFoveationEyeTrackedProfileCreateFlagsMETA { };
enum class XrFoveationEyeTrackedStateFlagsMETA_t : XrFoveationEyeTrackedStateFlagsMETA { };
enum class XrFrameEndInfoFlagsML_t : XrFrameEndInfoFlagsML { };
enum class XrGlobalDimmerFrameEndInfoFlagsML_t : XrGlobalDimmerFrameEndInfoFlagsML { };
enum class XrHandTrackingAimFlagsFB_t : XrHandTrackingAimFlagsFB { };
enum class XrInputSourceLocalizedNameFlags_t : XrInputSourceLocalizedNameFlags { };
enum class XrInstanceCreateFlags_t : XrInstanceCreateFlags { };
enum class XrKeyboardTrackingFlagsFB_t : XrKeyboardTrackingFlagsFB { };
enum class XrKeyboardTrackingQueryFlagsFB_t : XrKeyboardTrackingQueryFlagsFB { };
enum class XrLocalizationMapErrorFlagsML_t : XrLocalizationMapErrorFlagsML { };
enum class XrOverlayMainSessionFlagsEXTX_t : XrOverlayMainSessionFlagsEXTX { };
enum class XrOverlaySessionCreateFlagsEXTX_t : XrOverlaySessionCreateFlagsEXTX { };
enum class XrPassthroughCapabilityFlagsFB_t : XrPassthroughCapabilityFlagsFB { };
enum class XrPassthroughFlagsFB_t : XrPassthroughFlagsFB { };
enum class XrPassthroughPreferenceFlagsMETA_t : XrPassthroughPreferenceFlagsMETA { };
enum class XrPassthroughStateChangedFlagsFB_t : XrPassthroughStateChangedFlagsFB { };
enum class XrPerformanceMetricsCounterFlagsMETA_t : XrPerformanceMetricsCounterFlagsMETA { };
enum class XrPlaneDetectionCapabilityFlagsEXT_t : XrPlaneDetectionCapabilityFlagsEXT { };
enum class XrPlaneDetectorFlagsEXT_t : XrPlaneDetectorFlagsEXT { };
enum class XrRenderModelFlagsFB_t : XrRenderModelFlagsFB { };
enum class XrSemanticLabelsSupportFlagsFB_t : XrSemanticLabelsSupportFlagsFB { };
enum class XrSessionCreateFlags_t : XrSessionCreateFlags { };
enum class XrSpaceLocationFlags_t : XrSpaceLocationFlags { };
enum class XrSpaceVelocityFlags_t : XrSpaceVelocityFlags { };
enum class XrSwapchainCreateFlags_t : XrSwapchainCreateFlags { };
enum class XrSwapchainCreateFoveationFlagsFB_t : XrSwapchainCreateFoveationFlagsFB { };
enum class XrSwapchainStateFoveationFlagsFB_t : XrSwapchainStateFoveationFlagsFB { };
enum class XrSwapchainUsageFlags_t : XrSwapchainUsageFlags { };
enum class XrTriangleMeshFlagsFB_t : XrTriangleMeshFlagsFB { };
enum class XrViewStateFlags_t : XrViewStateFlags { };
enum class XrVirtualKeyboardInputStateFlagsMETA_t : XrVirtualKeyboardInputStateFlagsMETA { };
enum class XrVulkanDeviceCreateFlagsKHR_t : XrVulkanDeviceCreateFlagsKHR { };
enum class XrVulkanInstanceCreateFlagsKHR_t : XrVulkanInstanceCreateFlagsKHR { };

void FieldToJson(nlohmann::ordered_json& jdata, const XrActionType& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrAndroidThreadTypeKHR& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrBlendFactorFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrBodyJointFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrBodyJointSetFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrColorSpaceFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrCompareOpFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrEnvironmentBlendMode& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrExternalCameraAttachedToDeviceOCULUS& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrEyeCalibrationStatusML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrEyeExpressionHTC& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrEyePositionFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrEyeVisibility& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceConfidence2FB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceConfidenceFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpression2FB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionSet2FB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionSetFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceTrackingDataSource2FB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFacialTrackingTypeHTC& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrForceFeedbackCurlLocationMNDX& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFormFactor& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationDynamicFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationLevelFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationLevelHTC& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationModeHTC& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFutureStateEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandForearmJointULTRALEAP& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandJointEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandJointSetEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandJointsMotionRangeEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandPoseTypeMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandTrackingDataSourceEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrHeadsetFitStatusML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrLipExpressionHTC& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrLoaderInterfaceStructs& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalDimmingModeMETA& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapConfidenceML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapStateML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapTypeML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerAprilTagDictML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerArucoDictML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorCameraML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorCornerRefineMethodML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorFpsML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorFullAnalysisIntervalML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorProfileML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorResolutionML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorStatusML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerTypeML& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrMeshComputeLodMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrObjectType& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughColorLutChannelsMETA& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughFormHTC& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughLayerPurposeFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsDomainEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsLevelEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsNotificationLevelEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsSubDomainEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerformanceMetricsCounterUnitMETA& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectionStateEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectorOrientationEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectorSemanticTypeEXT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrReferenceSpaceType& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrReprojectionModeMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrResult& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComponentTypeMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComputeConsistencyMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComputeFeatureMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComputeStateMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneMarkerQRCodeSymbolTypeMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneMarkerTypeMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneObjectTypeMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrScenePlaneAlignmentTypeMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSessionState& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceComponentTypeFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpacePersistenceModeFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceQueryActionFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceStorageLocationFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpatialGraphNodeTypeMSFT& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrStructureType& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrTrackingOptimizationSettingsDomainQCOM& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrTrackingOptimizationSettingsHintQCOM& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrViewConfigurationType& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrVirtualKeyboardInputSourceMETA& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrVirtualKeyboardLocationTypeMETA& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrVisibilityMaskTypeKHR& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrWindingOrderFB& value);
void FieldToJson(nlohmann::ordered_json& jdata, const XrAndroidSurfaceSwapchainFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrCompositionLayerFlags_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrCompositionLayerImageLayoutFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrCompositionLayerSecureContentFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrCompositionLayerSettingsFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrCompositionLayerSpaceWarpInfoFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrDebugUtilsMessageSeverityFlagsEXT_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrDebugUtilsMessageTypeFlagsEXT_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrDigitalLensControlFlagsALMALENCE_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrEnvironmentDepthProviderCreateFlagsMETA_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrEnvironmentDepthSwapchainCreateFlagsMETA_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrExternalCameraStatusFlagsOCULUS_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationDynamicFlagsHTC_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationEyeTrackedProfileCreateFlagsMETA_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationEyeTrackedStateFlagsMETA_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrFrameEndInfoFlagsML_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrGlobalDimmerFrameEndInfoFlagsML_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandTrackingAimFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrInputSourceLocalizedNameFlags_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrInstanceCreateFlags_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrKeyboardTrackingFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrKeyboardTrackingQueryFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapErrorFlagsML_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrOverlayMainSessionFlagsEXTX_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrOverlaySessionCreateFlagsEXTX_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughCapabilityFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughPreferenceFlagsMETA_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughStateChangedFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerformanceMetricsCounterFlagsMETA_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectionCapabilityFlagsEXT_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectorFlagsEXT_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrRenderModelFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSemanticLabelsSupportFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSessionCreateFlags_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceLocationFlags_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceVelocityFlags_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSwapchainCreateFlags_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSwapchainCreateFoveationFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSwapchainStateFoveationFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrSwapchainUsageFlags_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrTriangleMeshFlagsFB_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrViewStateFlags_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrVirtualKeyboardInputStateFlagsMETA_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrVulkanDeviceCreateFlagsKHR_t flags);
void FieldToJson(nlohmann::ordered_json& jdata, const XrVulkanInstanceCreateFlagsKHR_t flags);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_GENERATED_OPENXR_ENUM_TO_JSON_H
