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

void XrActionTypeToJson(nlohmann::ordered_json& jdata, const XrActionType& value, const util::JsonOptions& options = util::JsonOptions());
void XrAndroidThreadTypeKHRToJson(nlohmann::ordered_json& jdata, const XrAndroidThreadTypeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void XrBlendFactorFBToJson(nlohmann::ordered_json& jdata, const XrBlendFactorFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrBodyJointFBToJson(nlohmann::ordered_json& jdata, const XrBodyJointFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrBodyJointSetFBToJson(nlohmann::ordered_json& jdata, const XrBodyJointSetFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrColorSpaceFBToJson(nlohmann::ordered_json& jdata, const XrColorSpaceFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrCompareOpFBToJson(nlohmann::ordered_json& jdata, const XrCompareOpFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrEnvironmentBlendModeToJson(nlohmann::ordered_json& jdata, const XrEnvironmentBlendMode& value, const util::JsonOptions& options = util::JsonOptions());
void XrExternalCameraAttachedToDeviceOCULUSToJson(nlohmann::ordered_json& jdata, const XrExternalCameraAttachedToDeviceOCULUS& value, const util::JsonOptions& options = util::JsonOptions());
void XrEyeCalibrationStatusMLToJson(nlohmann::ordered_json& jdata, const XrEyeCalibrationStatusML& value, const util::JsonOptions& options = util::JsonOptions());
void XrEyeExpressionHTCToJson(nlohmann::ordered_json& jdata, const XrEyeExpressionHTC& value, const util::JsonOptions& options = util::JsonOptions());
void XrEyePositionFBToJson(nlohmann::ordered_json& jdata, const XrEyePositionFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrEyeVisibilityToJson(nlohmann::ordered_json& jdata, const XrEyeVisibility& value, const util::JsonOptions& options = util::JsonOptions());
void XrFaceConfidence2FBToJson(nlohmann::ordered_json& jdata, const XrFaceConfidence2FB& value, const util::JsonOptions& options = util::JsonOptions());
void XrFaceConfidenceFBToJson(nlohmann::ordered_json& jdata, const XrFaceConfidenceFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrFaceExpression2FBToJson(nlohmann::ordered_json& jdata, const XrFaceExpression2FB& value, const util::JsonOptions& options = util::JsonOptions());
void XrFaceExpressionFBToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrFaceExpressionSet2FBToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionSet2FB& value, const util::JsonOptions& options = util::JsonOptions());
void XrFaceExpressionSetFBToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionSetFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrFaceTrackingDataSource2FBToJson(nlohmann::ordered_json& jdata, const XrFaceTrackingDataSource2FB& value, const util::JsonOptions& options = util::JsonOptions());
void XrFacialTrackingTypeHTCToJson(nlohmann::ordered_json& jdata, const XrFacialTrackingTypeHTC& value, const util::JsonOptions& options = util::JsonOptions());
void XrForceFeedbackCurlLocationMNDXToJson(nlohmann::ordered_json& jdata, const XrForceFeedbackCurlLocationMNDX& value, const util::JsonOptions& options = util::JsonOptions());
void XrFormFactorToJson(nlohmann::ordered_json& jdata, const XrFormFactor& value, const util::JsonOptions& options = util::JsonOptions());
void XrFoveationDynamicFBToJson(nlohmann::ordered_json& jdata, const XrFoveationDynamicFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrFoveationLevelFBToJson(nlohmann::ordered_json& jdata, const XrFoveationLevelFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrFoveationLevelHTCToJson(nlohmann::ordered_json& jdata, const XrFoveationLevelHTC& value, const util::JsonOptions& options = util::JsonOptions());
void XrFoveationModeHTCToJson(nlohmann::ordered_json& jdata, const XrFoveationModeHTC& value, const util::JsonOptions& options = util::JsonOptions());
void XrFutureStateEXTToJson(nlohmann::ordered_json& jdata, const XrFutureStateEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrHandEXTToJson(nlohmann::ordered_json& jdata, const XrHandEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrHandForearmJointULTRALEAPToJson(nlohmann::ordered_json& jdata, const XrHandForearmJointULTRALEAP& value, const util::JsonOptions& options = util::JsonOptions());
void XrHandJointEXTToJson(nlohmann::ordered_json& jdata, const XrHandJointEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrHandJointSetEXTToJson(nlohmann::ordered_json& jdata, const XrHandJointSetEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrHandJointsMotionRangeEXTToJson(nlohmann::ordered_json& jdata, const XrHandJointsMotionRangeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrHandPoseTypeMSFTToJson(nlohmann::ordered_json& jdata, const XrHandPoseTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrHandTrackingDataSourceEXTToJson(nlohmann::ordered_json& jdata, const XrHandTrackingDataSourceEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrHeadsetFitStatusMLToJson(nlohmann::ordered_json& jdata, const XrHeadsetFitStatusML& value, const util::JsonOptions& options = util::JsonOptions());
void XrLipExpressionHTCToJson(nlohmann::ordered_json& jdata, const XrLipExpressionHTC& value, const util::JsonOptions& options = util::JsonOptions());
void XrLoaderInterfaceStructsToJson(nlohmann::ordered_json& jdata, const XrLoaderInterfaceStructs& value, const util::JsonOptions& options = util::JsonOptions());
void XrLocalDimmingModeMETAToJson(nlohmann::ordered_json& jdata, const XrLocalDimmingModeMETA& value, const util::JsonOptions& options = util::JsonOptions());
void XrLocalizationMapConfidenceMLToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapConfidenceML& value, const util::JsonOptions& options = util::JsonOptions());
void XrLocalizationMapStateMLToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapStateML& value, const util::JsonOptions& options = util::JsonOptions());
void XrLocalizationMapTypeMLToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapTypeML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMarkerAprilTagDictMLToJson(nlohmann::ordered_json& jdata, const XrMarkerAprilTagDictML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMarkerArucoDictMLToJson(nlohmann::ordered_json& jdata, const XrMarkerArucoDictML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMarkerDetectorCameraMLToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorCameraML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMarkerDetectorCornerRefineMethodMLToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorCornerRefineMethodML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMarkerDetectorFpsMLToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorFpsML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMarkerDetectorFullAnalysisIntervalMLToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorFullAnalysisIntervalML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMarkerDetectorProfileMLToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorProfileML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMarkerDetectorResolutionMLToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorResolutionML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMarkerDetectorStatusMLToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorStatusML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMarkerTypeMLToJson(nlohmann::ordered_json& jdata, const XrMarkerTypeML& value, const util::JsonOptions& options = util::JsonOptions());
void XrMeshComputeLodMSFTToJson(nlohmann::ordered_json& jdata, const XrMeshComputeLodMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrObjectTypeToJson(nlohmann::ordered_json& jdata, const XrObjectType& value, const util::JsonOptions& options = util::JsonOptions());
void XrPassthroughColorLutChannelsMETAToJson(nlohmann::ordered_json& jdata, const XrPassthroughColorLutChannelsMETA& value, const util::JsonOptions& options = util::JsonOptions());
void XrPassthroughFormHTCToJson(nlohmann::ordered_json& jdata, const XrPassthroughFormHTC& value, const util::JsonOptions& options = util::JsonOptions());
void XrPassthroughLayerPurposeFBToJson(nlohmann::ordered_json& jdata, const XrPassthroughLayerPurposeFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrPerfSettingsDomainEXTToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsDomainEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrPerfSettingsLevelEXTToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsLevelEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrPerfSettingsNotificationLevelEXTToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsNotificationLevelEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrPerfSettingsSubDomainEXTToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsSubDomainEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrPerformanceMetricsCounterUnitMETAToJson(nlohmann::ordered_json& jdata, const XrPerformanceMetricsCounterUnitMETA& value, const util::JsonOptions& options = util::JsonOptions());
void XrPlaneDetectionStateEXTToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectionStateEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrPlaneDetectorOrientationEXTToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectorOrientationEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrPlaneDetectorSemanticTypeEXTToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectorSemanticTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void XrReferenceSpaceTypeToJson(nlohmann::ordered_json& jdata, const XrReferenceSpaceType& value, const util::JsonOptions& options = util::JsonOptions());
void XrReprojectionModeMSFTToJson(nlohmann::ordered_json& jdata, const XrReprojectionModeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrResultToJson(nlohmann::ordered_json& jdata, const XrResult& value, const util::JsonOptions& options = util::JsonOptions());
void XrSceneComponentTypeMSFTToJson(nlohmann::ordered_json& jdata, const XrSceneComponentTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrSceneComputeConsistencyMSFTToJson(nlohmann::ordered_json& jdata, const XrSceneComputeConsistencyMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrSceneComputeFeatureMSFTToJson(nlohmann::ordered_json& jdata, const XrSceneComputeFeatureMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrSceneComputeStateMSFTToJson(nlohmann::ordered_json& jdata, const XrSceneComputeStateMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrSceneMarkerQRCodeSymbolTypeMSFTToJson(nlohmann::ordered_json& jdata, const XrSceneMarkerQRCodeSymbolTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrSceneMarkerTypeMSFTToJson(nlohmann::ordered_json& jdata, const XrSceneMarkerTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrSceneObjectTypeMSFTToJson(nlohmann::ordered_json& jdata, const XrSceneObjectTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrScenePlaneAlignmentTypeMSFTToJson(nlohmann::ordered_json& jdata, const XrScenePlaneAlignmentTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrSessionStateToJson(nlohmann::ordered_json& jdata, const XrSessionState& value, const util::JsonOptions& options = util::JsonOptions());
void XrSpaceComponentTypeFBToJson(nlohmann::ordered_json& jdata, const XrSpaceComponentTypeFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrSpacePersistenceModeFBToJson(nlohmann::ordered_json& jdata, const XrSpacePersistenceModeFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrSpaceQueryActionFBToJson(nlohmann::ordered_json& jdata, const XrSpaceQueryActionFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrSpaceStorageLocationFBToJson(nlohmann::ordered_json& jdata, const XrSpaceStorageLocationFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrSpatialGraphNodeTypeMSFTToJson(nlohmann::ordered_json& jdata, const XrSpatialGraphNodeTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void XrStructureTypeToJson(nlohmann::ordered_json& jdata, const XrStructureType& value, const util::JsonOptions& options = util::JsonOptions());
void XrTrackingOptimizationSettingsDomainQCOMToJson(nlohmann::ordered_json& jdata, const XrTrackingOptimizationSettingsDomainQCOM& value, const util::JsonOptions& options = util::JsonOptions());
void XrTrackingOptimizationSettingsHintQCOMToJson(nlohmann::ordered_json& jdata, const XrTrackingOptimizationSettingsHintQCOM& value, const util::JsonOptions& options = util::JsonOptions());
void XrViewConfigurationTypeToJson(nlohmann::ordered_json& jdata, const XrViewConfigurationType& value, const util::JsonOptions& options = util::JsonOptions());
void XrVirtualKeyboardInputSourceMETAToJson(nlohmann::ordered_json& jdata, const XrVirtualKeyboardInputSourceMETA& value, const util::JsonOptions& options = util::JsonOptions());
void XrVirtualKeyboardLocationTypeMETAToJson(nlohmann::ordered_json& jdata, const XrVirtualKeyboardLocationTypeMETA& value, const util::JsonOptions& options = util::JsonOptions());
void XrVisibilityMaskTypeKHRToJson(nlohmann::ordered_json& jdata, const XrVisibilityMaskTypeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void XrWindingOrderFBToJson(nlohmann::ordered_json& jdata, const XrWindingOrderFB& value, const util::JsonOptions& options = util::JsonOptions());
void XrAndroidSurfaceSwapchainFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrCompositionLayerFlagsToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrCompositionLayerImageLayoutFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrCompositionLayerSecureContentFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrCompositionLayerSettingsFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrCompositionLayerSpaceWarpInfoFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrDebugUtilsMessageSeverityFlagsEXTToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrDebugUtilsMessageTypeFlagsEXTToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrDigitalLensControlFlagsALMALENCEToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrEnvironmentDepthProviderCreateFlagsMETAToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrEnvironmentDepthSwapchainCreateFlagsMETAToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrExternalCameraStatusFlagsOCULUSToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrFoveationDynamicFlagsHTCToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrFoveationEyeTrackedProfileCreateFlagsMETAToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrFoveationEyeTrackedStateFlagsMETAToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrFrameEndInfoFlagsMLToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrGlobalDimmerFrameEndInfoFlagsMLToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrHandTrackingAimFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrInputSourceLocalizedNameFlagsToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrInstanceCreateFlagsToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrKeyboardTrackingFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrKeyboardTrackingQueryFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrLocalizationMapErrorFlagsMLToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrOverlayMainSessionFlagsEXTXToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrOverlaySessionCreateFlagsEXTXToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrPassthroughCapabilityFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrPassthroughFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrPassthroughPreferenceFlagsMETAToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrPassthroughStateChangedFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrPerformanceMetricsCounterFlagsMETAToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrPlaneDetectionCapabilityFlagsEXTToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrPlaneDetectorFlagsEXTToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrRenderModelFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrSemanticLabelsSupportFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrSessionCreateFlagsToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrSpaceLocationFlagsToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrSpaceVelocityFlagsToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrSwapchainCreateFlagsToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrSwapchainCreateFoveationFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrSwapchainStateFoveationFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrSwapchainUsageFlagsToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrTriangleMeshFlagsFBToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrViewStateFlagsToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrVirtualKeyboardInputStateFlagsMETAToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrVulkanDeviceCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void XrVulkanInstanceCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_GENERATED_OPENXR_ENUM_TO_JSON_H
