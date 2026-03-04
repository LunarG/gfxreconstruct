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

struct XrAndroidSurfaceSwapchainFlagsFB_t { };
struct XrCompositionLayerFlags_t { };
struct XrCompositionLayerImageLayoutFlagsFB_t { };
struct XrCompositionLayerSecureContentFlagsFB_t { };
struct XrCompositionLayerSettingsFlagsFB_t { };
struct XrCompositionLayerSpaceWarpInfoFlagsFB_t { };
struct XrDebugUtilsMessageSeverityFlagsEXT_t { };
struct XrDebugUtilsMessageTypeFlagsEXT_t { };
struct XrDigitalLensControlFlagsALMALENCE_t { };
struct XrEnvironmentDepthProviderCreateFlagsMETA_t { };
struct XrEnvironmentDepthSwapchainCreateFlagsMETA_t { };
struct XrExternalCameraStatusFlagsOCULUS_t { };
struct XrFoveationDynamicFlagsHTC_t { };
struct XrFoveationEyeTrackedProfileCreateFlagsMETA_t { };
struct XrFoveationEyeTrackedStateFlagsMETA_t { };
struct XrFrameEndInfoFlagsML_t { };
struct XrGlobalDimmerFrameEndInfoFlagsML_t { };
struct XrHandTrackingAimFlagsFB_t { };
struct XrInputSourceLocalizedNameFlags_t { };
struct XrInstanceCreateFlags_t { };
struct XrKeyboardTrackingFlagsFB_t { };
struct XrKeyboardTrackingQueryFlagsFB_t { };
struct XrLocalizationMapErrorFlagsML_t { };
struct XrOverlayMainSessionFlagsEXTX_t { };
struct XrOverlaySessionCreateFlagsEXTX_t { };
struct XrPassthroughCapabilityFlagsFB_t { };
struct XrPassthroughFlagsFB_t { };
struct XrPassthroughPreferenceFlagsMETA_t { };
struct XrPassthroughStateChangedFlagsFB_t { };
struct XrPerformanceMetricsCounterFlagsMETA_t { };
struct XrPlaneDetectionCapabilityFlagsEXT_t { };
struct XrPlaneDetectorFlagsEXT_t { };
struct XrRenderModelFlagsFB_t { };
struct XrSemanticLabelsSupportFlagsFB_t { };
struct XrSessionCreateFlags_t { };
struct XrSpaceLocationFlags_t { };
struct XrSpaceVelocityFlags_t { };
struct XrSwapchainCreateFlags_t { };
struct XrSwapchainCreateFoveationFlagsFB_t { };
struct XrSwapchainStateFoveationFlagsFB_t { };
struct XrSwapchainUsageFlags_t { };
struct XrTriangleMeshFlagsFB_t { };
struct XrViewStateFlags_t { };
struct XrVirtualKeyboardInputStateFlagsMETA_t { };
struct XrVulkanDeviceCreateFlagsKHR_t { };
struct XrVulkanInstanceCreateFlagsKHR_t { };

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
void FieldToJson(XrAndroidSurfaceSwapchainFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrCompositionLayerFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrCompositionLayerImageLayoutFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrCompositionLayerSecureContentFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrCompositionLayerSettingsFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrCompositionLayerSpaceWarpInfoFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrDebugUtilsMessageSeverityFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrDebugUtilsMessageTypeFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrDigitalLensControlFlagsALMALENCE_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrEnvironmentDepthProviderCreateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrEnvironmentDepthSwapchainCreateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrExternalCameraStatusFlagsOCULUS_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrFoveationDynamicFlagsHTC_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrFoveationEyeTrackedProfileCreateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrFoveationEyeTrackedStateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrFrameEndInfoFlagsML_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrGlobalDimmerFrameEndInfoFlagsML_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrHandTrackingAimFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrInputSourceLocalizedNameFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrInstanceCreateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrKeyboardTrackingFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrKeyboardTrackingQueryFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrLocalizationMapErrorFlagsML_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrOverlayMainSessionFlagsEXTX_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrOverlaySessionCreateFlagsEXTX_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrPassthroughCapabilityFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrPassthroughFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrPassthroughPreferenceFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrPassthroughStateChangedFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrPerformanceMetricsCounterFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrPlaneDetectionCapabilityFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrPlaneDetectorFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrRenderModelFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrSemanticLabelsSupportFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrSessionCreateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrSpaceLocationFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrSpaceVelocityFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrSwapchainCreateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrSwapchainCreateFoveationFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrSwapchainStateFoveationFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrSwapchainUsageFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrTriangleMeshFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrViewStateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrVirtualKeyboardInputStateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrVulkanDeviceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);
void FieldToJson(XrVulkanInstanceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const XrFlags64 flags);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_GENERATED_OPENXR_ENUM_TO_JSON_H
