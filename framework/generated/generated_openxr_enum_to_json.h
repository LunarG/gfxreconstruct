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

#ifndef  GFXRECON_GENERATED_OPENXR_ENUM_TO_JSON_H
#define  GFXRECON_GENERATED_OPENXR_ENUM_TO_JSON_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "format/platform_types.h"
#include "util/json_util.h"

#include <nlohmann/json.hpp>

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
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"


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

void FieldToJson(nlohmann::ordered_json& jdata, const XrActionType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrAndroidThreadTypeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrBlendFactorFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrBodyJointFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrBodyJointSetFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrColorSpaceFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrCompareOpFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrEnvironmentBlendMode& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrExternalCameraAttachedToDeviceOCULUS& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrEyeCalibrationStatusML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrEyeExpressionHTC& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrEyePositionFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrEyeVisibility& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceConfidence2FB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceConfidenceFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpression2FB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionSet2FB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionSetFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceTrackingDataSource2FB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFacialTrackingTypeHTC& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrForceFeedbackCurlLocationMNDX& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFormFactor& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationDynamicFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationLevelFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationLevelHTC& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationModeHTC& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandForearmJointULTRALEAP& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandJointEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandJointSetEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandJointsMotionRangeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandPoseTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrHandTrackingDataSourceEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrHeadsetFitStatusML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrLipExpressionHTC& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrLoaderInterfaceStructs& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalDimmingModeMETA& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapConfidenceML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapStateML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapTypeML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerAprilTagDictML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerArucoDictML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorCameraML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorCornerRefineMethodML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorFpsML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorFullAnalysisIntervalML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorProfileML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorResolutionML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorStatusML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerTypeML& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrMeshComputeLodMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrObjectType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughColorLutChannelsMETA& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughFormHTC& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughLayerPurposeFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsDomainEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsLevelEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsNotificationLevelEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsSubDomainEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPerformanceMetricsCounterUnitMETA& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectionStateEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectorOrientationEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectorSemanticTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrReferenceSpaceType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrReprojectionModeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrResult& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComponentTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComputeConsistencyMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComputeFeatureMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComputeStateMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneMarkerQRCodeSymbolTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneMarkerTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneObjectTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrScenePlaneAlignmentTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSessionState& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceComponentTypeFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpacePersistenceModeFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceQueryActionFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceStorageLocationFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrSpatialGraphNodeTypeMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrStructureType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrTrackingOptimizationSettingsDomainQCOM& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrTrackingOptimizationSettingsHintQCOM& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrViewConfigurationType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrVirtualKeyboardInputSourceMETA& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrVirtualKeyboardLocationTypeMETA& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrVisibilityMaskTypeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const XrWindingOrderFB& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrAndroidSurfaceSwapchainFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrCompositionLayerFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrCompositionLayerImageLayoutFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrCompositionLayerSecureContentFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrCompositionLayerSettingsFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrCompositionLayerSpaceWarpInfoFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrDebugUtilsMessageSeverityFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrDebugUtilsMessageTypeFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrDigitalLensControlFlagsALMALENCE_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrExternalCameraStatusFlagsOCULUS_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrFoveationDynamicFlagsHTC_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrFoveationEyeTrackedProfileCreateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrFoveationEyeTrackedStateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrFrameEndInfoFlagsML_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrGlobalDimmerFrameEndInfoFlagsML_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrHandTrackingAimFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrInputSourceLocalizedNameFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrInstanceCreateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrKeyboardTrackingFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrKeyboardTrackingQueryFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrLocalizationMapErrorFlagsML_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrOverlayMainSessionFlagsEXTX_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrOverlaySessionCreateFlagsEXTX_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrPassthroughCapabilityFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrPassthroughFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrPassthroughPreferenceFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrPassthroughStateChangedFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrPerformanceMetricsCounterFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrPlaneDetectionCapabilityFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrPlaneDetectorFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrRenderModelFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrSemanticLabelsSupportFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrSessionCreateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrSpaceLocationFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrSpaceVelocityFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrSwapchainCreateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrSwapchainCreateFoveationFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrSwapchainStateFoveationFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrSwapchainUsageFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrTriangleMeshFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrViewStateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrVirtualKeyboardInputStateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrVulkanDeviceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(XrVulkanInstanceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const util::JsonOptions& options = util::JsonOptions());

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_ENUM_TO_JSON_H
