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

#ifndef  GFXRECON_GENERATED_OPENXR_STRUCT_DECODERS_FORWARD_H
#define  GFXRECON_GENERATED_OPENXR_STRUCT_DECODERS_FORWARD_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
















































































































struct Decoded_XrApiLayerProperties;
struct Decoded_XrExtensionProperties;
struct Decoded_XrApplicationInfo;
struct Decoded_XrInstanceCreateInfo;
struct Decoded_XrInstanceProperties;
struct Decoded_XrEventDataBuffer;
struct Decoded_XrSystemGetInfo;
struct Decoded_XrSystemGraphicsProperties;
struct Decoded_XrSystemTrackingProperties;
struct Decoded_XrSystemProperties;
struct Decoded_XrSessionCreateInfo;
struct Decoded_XrVector3f;
struct Decoded_XrSpaceVelocity;
struct Decoded_XrQuaternionf;
struct Decoded_XrPosef;
struct Decoded_XrReferenceSpaceCreateInfo;
struct Decoded_XrExtent2Df;
struct Decoded_XrActionSpaceCreateInfo;
struct Decoded_XrSpaceLocation;
struct Decoded_XrViewConfigurationProperties;
struct Decoded_XrViewConfigurationView;
struct Decoded_XrSwapchainCreateInfo;
struct Decoded_XrSwapchainImageBaseHeader;
struct Decoded_XrSwapchainImageAcquireInfo;
struct Decoded_XrSwapchainImageWaitInfo;
struct Decoded_XrSwapchainImageReleaseInfo;
struct Decoded_XrSessionBeginInfo;
struct Decoded_XrFrameWaitInfo;
struct Decoded_XrFrameState;
struct Decoded_XrFrameBeginInfo;
struct Decoded_XrCompositionLayerBaseHeader;
struct Decoded_XrFrameEndInfo;
struct Decoded_XrViewLocateInfo;
struct Decoded_XrViewState;
struct Decoded_XrFovf;
struct Decoded_XrView;
struct Decoded_XrActionSetCreateInfo;
struct Decoded_XrActionCreateInfo;
struct Decoded_XrActionSuggestedBinding;
struct Decoded_XrInteractionProfileSuggestedBinding;
struct Decoded_XrSessionActionSetsAttachInfo;
struct Decoded_XrInteractionProfileState;
struct Decoded_XrActionStateGetInfo;
struct Decoded_XrActionStateBoolean;
struct Decoded_XrActionStateFloat;
struct Decoded_XrVector2f;
struct Decoded_XrActionStateVector2f;
struct Decoded_XrActionStatePose;
struct Decoded_XrActiveActionSet;
struct Decoded_XrActionsSyncInfo;
struct Decoded_XrBoundSourcesForActionEnumerateInfo;
struct Decoded_XrInputSourceLocalizedNameGetInfo;
struct Decoded_XrHapticActionInfo;
struct Decoded_XrHapticBaseHeader;
struct Decoded_XrOffset2Di;
struct Decoded_XrExtent2Di;
struct Decoded_XrRect2Di;
struct Decoded_XrSwapchainSubImage;
struct Decoded_XrCompositionLayerProjectionView;
struct Decoded_XrCompositionLayerProjection;
struct Decoded_XrCompositionLayerQuad;
struct Decoded_XrEventDataBaseHeader;
struct Decoded_XrEventDataEventsLost;
struct Decoded_XrEventDataInstanceLossPending;
struct Decoded_XrEventDataSessionStateChanged;
struct Decoded_XrEventDataReferenceSpaceChangePending;
struct Decoded_XrEventDataInteractionProfileChanged;
struct Decoded_XrHapticVibration;
struct Decoded_XrOffset2Df;
struct Decoded_XrRect2Df;
struct Decoded_XrVector4f;
struct Decoded_XrColor4f;
struct Decoded_XrApiLayerNextInfo;
struct Decoded_XrApiLayerCreateInfo;
struct Decoded_XrNegotiateApiLayerRequest;
struct Decoded_XrCompositionLayerCubeKHR;
struct Decoded_XrInstanceCreateInfoAndroidKHR;
struct Decoded_XrCompositionLayerDepthInfoKHR;
struct Decoded_XrVulkanSwapchainFormatListCreateInfoKHR;
struct Decoded_XrCompositionLayerCylinderKHR;
struct Decoded_XrCompositionLayerEquirectKHR;
struct Decoded_XrGraphicsBindingOpenGLWin32KHR;
struct Decoded_XrGraphicsBindingOpenGLXlibKHR;
struct Decoded_XrGraphicsBindingOpenGLXcbKHR;
struct Decoded_XrGraphicsBindingOpenGLWaylandKHR;
struct Decoded_XrSwapchainImageOpenGLKHR;
struct Decoded_XrGraphicsRequirementsOpenGLKHR;
struct Decoded_XrGraphicsBindingOpenGLESAndroidKHR;
struct Decoded_XrSwapchainImageOpenGLESKHR;
struct Decoded_XrGraphicsRequirementsOpenGLESKHR;
struct Decoded_XrGraphicsBindingVulkanKHR;
struct Decoded_XrSwapchainImageVulkanKHR;
struct Decoded_XrGraphicsRequirementsVulkanKHR;
struct Decoded_XrGraphicsBindingD3D11KHR;
struct Decoded_XrSwapchainImageD3D11KHR;
struct Decoded_XrGraphicsRequirementsD3D11KHR;
struct Decoded_XrGraphicsBindingD3D12KHR;
struct Decoded_XrSwapchainImageD3D12KHR;
struct Decoded_XrGraphicsRequirementsD3D12KHR;
struct Decoded_XrVisibilityMaskKHR;
struct Decoded_XrEventDataVisibilityMaskChangedKHR;
struct Decoded_XrCompositionLayerColorScaleBiasKHR;
struct Decoded_XrLoaderInitInfoBaseHeaderKHR;
struct Decoded_XrLoaderInitInfoAndroidKHR;
struct Decoded_XrVulkanGraphicsDeviceGetInfoKHR;
struct Decoded_XrCompositionLayerEquirect2KHR;
struct Decoded_XrBindingModificationBaseHeaderKHR;
struct Decoded_XrBindingModificationsKHR;
struct Decoded_XrEventDataPerfSettingsEXT;
struct Decoded_XrDebugUtilsObjectNameInfoEXT;
struct Decoded_XrDebugUtilsLabelEXT;
struct Decoded_XrDebugUtilsMessengerCallbackDataEXT;
struct Decoded_XrDebugUtilsMessengerCreateInfoEXT;
struct Decoded_XrSystemEyeGazeInteractionPropertiesEXT;
struct Decoded_XrEyeGazeSampleTimeEXT;
struct Decoded_XrSessionCreateInfoOverlayEXTX;
struct Decoded_XrEventDataMainSessionVisibilityChangedEXTX;
struct Decoded_XrSpatialAnchorCreateInfoMSFT;
struct Decoded_XrSpatialAnchorSpaceCreateInfoMSFT;
struct Decoded_XrCompositionLayerImageLayoutFB;
struct Decoded_XrCompositionLayerAlphaBlendFB;
struct Decoded_XrViewConfigurationDepthRangeEXT;
struct Decoded_XrGraphicsBindingEGLMNDX;
struct Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT;
struct Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT;
struct Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT;
struct Decoded_XrSpatialGraphNodeBindingPropertiesMSFT;
struct Decoded_XrSystemHandTrackingPropertiesEXT;
struct Decoded_XrHandTrackerCreateInfoEXT;
struct Decoded_XrHandJointsLocateInfoEXT;
struct Decoded_XrHandJointLocationEXT;
struct Decoded_XrHandJointVelocityEXT;
struct Decoded_XrHandJointLocationsEXT;
struct Decoded_XrHandJointVelocitiesEXT;
struct Decoded_XrSystemHandTrackingMeshPropertiesMSFT;
struct Decoded_XrHandMeshSpaceCreateInfoMSFT;
struct Decoded_XrHandMeshUpdateInfoMSFT;
struct Decoded_XrHandMeshIndexBufferMSFT;
struct Decoded_XrHandMeshVertexMSFT;
struct Decoded_XrHandMeshVertexBufferMSFT;
struct Decoded_XrHandMeshMSFT;
struct Decoded_XrHandPoseTypeInfoMSFT;
struct Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT;
struct Decoded_XrSecondaryViewConfigurationStateMSFT;
struct Decoded_XrSecondaryViewConfigurationFrameStateMSFT;
struct Decoded_XrSecondaryViewConfigurationLayerInfoMSFT;
struct Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT;
struct Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT;
struct Decoded_XrControllerModelKeyStateMSFT;
struct Decoded_XrControllerModelNodePropertiesMSFT;
struct Decoded_XrControllerModelPropertiesMSFT;
struct Decoded_XrControllerModelNodeStateMSFT;
struct Decoded_XrControllerModelStateMSFT;
struct Decoded_XrViewConfigurationViewFovEPIC;
struct Decoded_XrHolographicWindowAttachmentMSFT;
struct Decoded_XrCompositionLayerReprojectionInfoMSFT;
struct Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT;
struct Decoded_XrAndroidSurfaceSwapchainCreateInfoFB;
struct Decoded_XrSwapchainStateBaseHeaderFB;
struct Decoded_XrCompositionLayerSecureContentFB;
struct Decoded_XrBodyJointLocationFB;
struct Decoded_XrSystemBodyTrackingPropertiesFB;
struct Decoded_XrBodyTrackerCreateInfoFB;
struct Decoded_XrBodySkeletonJointFB;
struct Decoded_XrBodySkeletonFB;
struct Decoded_XrBodyJointsLocateInfoFB;
struct Decoded_XrBodyJointLocationsFB;
struct Decoded_XrInteractionProfileDpadBindingEXT;
struct Decoded_XrInteractionProfileAnalogThresholdVALVE;
struct Decoded_XrHandJointsMotionRangeInfoEXT;
struct Decoded_XrUuidMSFT;
struct Decoded_XrSceneObserverCreateInfoMSFT;
struct Decoded_XrSceneCreateInfoMSFT;
struct Decoded_XrSceneSphereBoundMSFT;
struct Decoded_XrSceneOrientedBoxBoundMSFT;
struct Decoded_XrSceneFrustumBoundMSFT;
struct Decoded_XrSceneBoundsMSFT;
struct Decoded_XrNewSceneComputeInfoMSFT;
struct Decoded_XrVisualMeshComputeLodInfoMSFT;
struct Decoded_XrSceneComponentMSFT;
struct Decoded_XrSceneComponentsMSFT;
struct Decoded_XrSceneComponentsGetInfoMSFT;
struct Decoded_XrSceneComponentLocationMSFT;
struct Decoded_XrSceneComponentLocationsMSFT;
struct Decoded_XrSceneComponentsLocateInfoMSFT;
struct Decoded_XrSceneObjectMSFT;
struct Decoded_XrSceneObjectsMSFT;
struct Decoded_XrSceneComponentParentFilterInfoMSFT;
struct Decoded_XrSceneObjectTypesFilterInfoMSFT;
struct Decoded_XrScenePlaneMSFT;
struct Decoded_XrScenePlanesMSFT;
struct Decoded_XrScenePlaneAlignmentFilterInfoMSFT;
struct Decoded_XrSceneMeshMSFT;
struct Decoded_XrSceneMeshesMSFT;
struct Decoded_XrSceneMeshBuffersGetInfoMSFT;
struct Decoded_XrSceneMeshBuffersMSFT;
struct Decoded_XrSceneMeshVertexBufferMSFT;
struct Decoded_XrSceneMeshIndicesUint32MSFT;
struct Decoded_XrSceneMeshIndicesUint16MSFT;
struct Decoded_XrSerializedSceneFragmentDataGetInfoMSFT;
struct Decoded_XrDeserializeSceneFragmentMSFT;
struct Decoded_XrSceneDeserializeInfoMSFT;
struct Decoded_XrEventDataDisplayRefreshRateChangedFB;
struct Decoded_XrViveTrackerPathsHTCX;
struct Decoded_XrEventDataViveTrackerConnectedHTCX;
struct Decoded_XrSystemFacialTrackingPropertiesHTC;
struct Decoded_XrFacialExpressionsHTC;
struct Decoded_XrFacialTrackerCreateInfoHTC;
struct Decoded_XrSystemColorSpacePropertiesFB;
struct Decoded_XrVector4sFB;
struct Decoded_XrHandTrackingMeshFB;
struct Decoded_XrHandTrackingScaleFB;
struct Decoded_XrHandTrackingAimStateFB;
struct Decoded_XrHandCapsuleFB;
struct Decoded_XrHandTrackingCapsulesStateFB;
struct Decoded_XrSystemSpatialEntityPropertiesFB;
struct Decoded_XrSpatialAnchorCreateInfoFB;
struct Decoded_XrSpaceComponentStatusSetInfoFB;
struct Decoded_XrSpaceComponentStatusFB;
struct Decoded_XrUuidEXT;
struct Decoded_XrEventDataSpatialAnchorCreateCompleteFB;
struct Decoded_XrEventDataSpaceSetStatusCompleteFB;
struct Decoded_XrFoveationProfileCreateInfoFB;
struct Decoded_XrSwapchainCreateInfoFoveationFB;
struct Decoded_XrSwapchainStateFoveationFB;
struct Decoded_XrFoveationLevelProfileCreateInfoFB;
struct Decoded_XrSystemKeyboardTrackingPropertiesFB;
struct Decoded_XrKeyboardTrackingDescriptionFB;
struct Decoded_XrKeyboardSpaceCreateInfoFB;
struct Decoded_XrKeyboardTrackingQueryFB;
struct Decoded_XrTriangleMeshCreateInfoFB;
struct Decoded_XrSystemPassthroughPropertiesFB;
struct Decoded_XrSystemPassthroughProperties2FB;
struct Decoded_XrPassthroughCreateInfoFB;
struct Decoded_XrPassthroughLayerCreateInfoFB;
struct Decoded_XrCompositionLayerPassthroughFB;
struct Decoded_XrGeometryInstanceCreateInfoFB;
struct Decoded_XrGeometryInstanceTransformFB;
struct Decoded_XrPassthroughStyleFB;
struct Decoded_XrPassthroughColorMapMonoToRgbaFB;
struct Decoded_XrPassthroughColorMapMonoToMonoFB;
struct Decoded_XrPassthroughBrightnessContrastSaturationFB;
struct Decoded_XrEventDataPassthroughStateChangedFB;
struct Decoded_XrRenderModelPathInfoFB;
struct Decoded_XrRenderModelPropertiesFB;
struct Decoded_XrRenderModelBufferFB;
struct Decoded_XrRenderModelLoadInfoFB;
struct Decoded_XrSystemRenderModelPropertiesFB;
struct Decoded_XrRenderModelCapabilitiesRequestFB;
struct Decoded_XrViewLocateFoveatedRenderingVARJO;
struct Decoded_XrFoveatedViewConfigurationViewVARJO;
struct Decoded_XrSystemFoveatedRenderingPropertiesVARJO;
struct Decoded_XrCompositionLayerDepthTestVARJO;
struct Decoded_XrSystemMarkerTrackingPropertiesVARJO;
struct Decoded_XrEventDataMarkerTrackingUpdateVARJO;
struct Decoded_XrMarkerSpaceCreateInfoVARJO;
struct Decoded_XrFrameEndInfoML;
struct Decoded_XrGlobalDimmerFrameEndInfoML;
struct Decoded_XrCoordinateSpaceCreateInfoML;
struct Decoded_XrSystemMarkerUnderstandingPropertiesML;
struct Decoded_XrMarkerDetectorCreateInfoML;
struct Decoded_XrMarkerDetectorArucoInfoML;
struct Decoded_XrMarkerDetectorSizeInfoML;
struct Decoded_XrMarkerDetectorAprilTagInfoML;
struct Decoded_XrMarkerDetectorCustomProfileInfoML;
struct Decoded_XrMarkerDetectorSnapshotInfoML;
struct Decoded_XrMarkerDetectorStateML;
struct Decoded_XrMarkerSpaceCreateInfoML;
struct Decoded_XrLocalizationMapML;
struct Decoded_XrEventDataLocalizationChangedML;
struct Decoded_XrLocalizationMapQueryInfoBaseHeaderML;
struct Decoded_XrMapLocalizationRequestInfoML;
struct Decoded_XrLocalizationMapImportInfoML;
struct Decoded_XrLocalizationEnableEventsInfoML;
struct Decoded_XrSpatialAnchorPersistenceNameMSFT;
struct Decoded_XrSpatialAnchorPersistenceInfoMSFT;
struct Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT;
struct Decoded_XrSceneMarkerMSFT;
struct Decoded_XrSceneMarkersMSFT;
struct Decoded_XrSceneMarkerTypeFilterMSFT;
struct Decoded_XrSceneMarkerQRCodeMSFT;
struct Decoded_XrSceneMarkerQRCodesMSFT;
struct Decoded_XrSpaceQueryInfoBaseHeaderFB;
struct Decoded_XrSpaceFilterInfoBaseHeaderFB;
struct Decoded_XrSpaceQueryInfoFB;
struct Decoded_XrSpaceStorageLocationFilterInfoFB;
struct Decoded_XrSpaceUuidFilterInfoFB;
struct Decoded_XrSpaceComponentFilterInfoFB;
struct Decoded_XrSpaceQueryResultFB;
struct Decoded_XrSpaceQueryResultsFB;
struct Decoded_XrEventDataSpaceQueryResultsAvailableFB;
struct Decoded_XrEventDataSpaceQueryCompleteFB;
struct Decoded_XrSpaceSaveInfoFB;
struct Decoded_XrSpaceEraseInfoFB;
struct Decoded_XrEventDataSpaceSaveCompleteFB;
struct Decoded_XrEventDataSpaceEraseCompleteFB;
struct Decoded_XrSwapchainImageFoveationVulkanFB;
struct Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB;
struct Decoded_XrSwapchainStateSamplerOpenGLESFB;
struct Decoded_XrSwapchainStateSamplerVulkanFB;
struct Decoded_XrSpaceShareInfoFB;
struct Decoded_XrEventDataSpaceShareCompleteFB;
struct Decoded_XrCompositionLayerSpaceWarpInfoFB;
struct Decoded_XrSystemSpaceWarpPropertiesFB;
struct Decoded_XrHapticAmplitudeEnvelopeVibrationFB;
struct Decoded_XrExtent3DfFB;
struct Decoded_XrOffset3DfFB;
struct Decoded_XrRect3DfFB;
struct Decoded_XrSemanticLabelsFB;
struct Decoded_XrRoomLayoutFB;
struct Decoded_XrBoundary2DFB;
struct Decoded_XrSemanticLabelsSupportInfoFB;
struct Decoded_XrDigitalLensControlALMALENCE;
struct Decoded_XrEventDataSceneCaptureCompleteFB;
struct Decoded_XrSceneCaptureRequestInfoFB;
struct Decoded_XrSpaceContainerFB;
struct Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA;
struct Decoded_XrFoveationEyeTrackedStateMETA;
struct Decoded_XrSystemFoveationEyeTrackedPropertiesMETA;
struct Decoded_XrSystemFaceTrackingPropertiesFB;
struct Decoded_XrFaceTrackerCreateInfoFB;
struct Decoded_XrFaceExpressionInfoFB;
struct Decoded_XrFaceExpressionStatusFB;
struct Decoded_XrFaceExpressionWeightsFB;
struct Decoded_XrEyeGazeFB;
struct Decoded_XrEyeTrackerCreateInfoFB;
struct Decoded_XrEyeGazesInfoFB;
struct Decoded_XrSystemEyeTrackingPropertiesFB;
struct Decoded_XrEyeGazesFB;
struct Decoded_XrPassthroughKeyboardHandsIntensityFB;
struct Decoded_XrCompositionLayerSettingsFB;
struct Decoded_XrHapticPcmVibrationFB;
struct Decoded_XrDevicePcmSampleRateStateFB;
struct Decoded_XrCompositionLayerDepthTestFB;
struct Decoded_XrLocalDimmingFrameEndInfoMETA;
struct Decoded_XrPassthroughPreferencesMETA;
struct Decoded_XrSystemVirtualKeyboardPropertiesMETA;
struct Decoded_XrVirtualKeyboardCreateInfoMETA;
struct Decoded_XrVirtualKeyboardSpaceCreateInfoMETA;
struct Decoded_XrVirtualKeyboardLocationInfoMETA;
struct Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA;
struct Decoded_XrVirtualKeyboardAnimationStateMETA;
struct Decoded_XrVirtualKeyboardModelAnimationStatesMETA;
struct Decoded_XrVirtualKeyboardTextureDataMETA;
struct Decoded_XrVirtualKeyboardInputInfoMETA;
struct Decoded_XrVirtualKeyboardTextContextChangeInfoMETA;
struct Decoded_XrEventDataVirtualKeyboardCommitTextMETA;
struct Decoded_XrEventDataVirtualKeyboardBackspaceMETA;
struct Decoded_XrEventDataVirtualKeyboardEnterMETA;
struct Decoded_XrEventDataVirtualKeyboardShownMETA;
struct Decoded_XrEventDataVirtualKeyboardHiddenMETA;
struct Decoded_XrExternalCameraIntrinsicsOCULUS;
struct Decoded_XrExternalCameraExtrinsicsOCULUS;
struct Decoded_XrExternalCameraOCULUS;
struct Decoded_XrVulkanSwapchainCreateInfoMETA;
struct Decoded_XrPerformanceMetricsStateMETA;
struct Decoded_XrPerformanceMetricsCounterMETA;
struct Decoded_XrSpaceListSaveInfoFB;
struct Decoded_XrEventDataSpaceListSaveCompleteFB;
struct Decoded_XrSpaceUserCreateInfoFB;
struct Decoded_XrSystemHeadsetIdPropertiesMETA;
struct Decoded_XrRecommendedLayerResolutionMETA;
struct Decoded_XrRecommendedLayerResolutionGetInfoMETA;
struct Decoded_XrPassthroughColorLutDataMETA;
struct Decoded_XrPassthroughColorLutCreateInfoMETA;
struct Decoded_XrPassthroughColorLutUpdateInfoMETA;
struct Decoded_XrPassthroughColorMapLutMETA;
struct Decoded_XrPassthroughColorMapInterpolatedLutMETA;
struct Decoded_XrSystemPassthroughColorLutPropertiesMETA;
struct Decoded_XrSpaceTriangleMeshGetInfoMETA;
struct Decoded_XrSpaceTriangleMeshMETA;
struct Decoded_XrSystemFaceTrackingProperties2FB;
struct Decoded_XrFaceTrackerCreateInfo2FB;
struct Decoded_XrFaceExpressionInfo2FB;
struct Decoded_XrFaceExpressionWeights2FB;
struct Decoded_XrPassthroughCreateInfoHTC;
struct Decoded_XrPassthroughColorHTC;
struct Decoded_XrPassthroughMeshTransformInfoHTC;
struct Decoded_XrCompositionLayerPassthroughHTC;
struct Decoded_XrFoveationApplyInfoHTC;
struct Decoded_XrFoveationConfigurationHTC;
struct Decoded_XrFoveationDynamicModeInfoHTC;
struct Decoded_XrFoveationCustomModeInfoHTC;
struct Decoded_XrSystemAnchorPropertiesHTC;
struct Decoded_XrSpatialAnchorNameHTC;
struct Decoded_XrSpatialAnchorCreateInfoHTC;
struct Decoded_XrActiveActionSetPriorityEXT;
struct Decoded_XrActiveActionSetPrioritiesEXT;
struct Decoded_XrSystemForceFeedbackCurlPropertiesMNDX;
struct Decoded_XrForceFeedbackCurlApplyLocationMNDX;
struct Decoded_XrForceFeedbackCurlApplyLocationsMNDX;
struct Decoded_XrHandTrackingDataSourceInfoEXT;
struct Decoded_XrHandTrackingDataSourceStateEXT;
struct Decoded_XrSystemPlaneDetectionPropertiesEXT;
struct Decoded_XrPlaneDetectorCreateInfoEXT;
struct Decoded_XrExtent3DfEXT;
struct Decoded_XrPlaneDetectorBeginInfoEXT;
struct Decoded_XrPlaneDetectorGetInfoEXT;
struct Decoded_XrPlaneDetectorLocationEXT;
struct Decoded_XrPlaneDetectorLocationsEXT;
struct Decoded_XrPlaneDetectorPolygonBufferEXT;
struct Decoded_XrEventDataUserPresenceChangedEXT;
struct Decoded_XrSystemUserPresencePropertiesEXT;
struct Decoded_XrEventDataHeadsetFitChangedML;
struct Decoded_XrEventDataEyeCalibrationChangedML;
struct Decoded_XrUserCalibrationEnableEventsInfoML;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrApiLayerProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrExtensionProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrApplicationInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrInstanceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrInstanceProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataBuffer* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemGetInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemGraphicsProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemTrackingProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSessionCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVector3f* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceVelocity* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrQuaternionf* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPosef* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrReferenceSpaceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrExtent2Df* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActionSpaceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceLocation* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrViewConfigurationProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrViewConfigurationView* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainImageBaseHeader* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainImageAcquireInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainImageWaitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainImageReleaseInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSessionBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFrameWaitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFrameState* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFrameBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerBaseHeader* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFrameEndInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrViewLocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrViewState* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFovf* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrView* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActionSetCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActionCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActionSuggestedBinding* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrInteractionProfileSuggestedBinding* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSessionActionSetsAttachInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrInteractionProfileState* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActionStateGetInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActionStateBoolean* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActionStateFloat* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVector2f* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActionStateVector2f* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActionStatePose* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActiveActionSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActionsSyncInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrBoundSourcesForActionEnumerateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrInputSourceLocalizedNameGetInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHapticActionInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHapticBaseHeader* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrOffset2Di* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrExtent2Di* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRect2Di* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainSubImage* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerProjectionView* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerProjection* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerQuad* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataBaseHeader* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataEventsLost* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataInstanceLossPending* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataSessionStateChanged* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataReferenceSpaceChangePending* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataInteractionProfileChanged* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHapticVibration* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrOffset2Df* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRect2Df* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVector4f* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrColor4f* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrApiLayerNextInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrApiLayerCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrNegotiateApiLayerRequest* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerCubeKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrInstanceCreateInfoAndroidKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerDepthInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVulkanSwapchainFormatListCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerCylinderKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerEquirectKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsBindingOpenGLWin32KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsBindingOpenGLXlibKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsBindingOpenGLXcbKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsBindingOpenGLWaylandKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainImageOpenGLKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsRequirementsOpenGLKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsBindingOpenGLESAndroidKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainImageOpenGLESKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsRequirementsOpenGLESKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsBindingVulkanKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainImageVulkanKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsRequirementsVulkanKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsBindingD3D11KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainImageD3D11KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsRequirementsD3D11KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsBindingD3D12KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainImageD3D12KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsRequirementsD3D12KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVisibilityMaskKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataVisibilityMaskChangedKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerColorScaleBiasKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrLoaderInitInfoBaseHeaderKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrLoaderInitInfoAndroidKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVulkanGraphicsDeviceGetInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerEquirect2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrBindingModificationBaseHeaderKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrBindingModificationsKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataPerfSettingsEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrDebugUtilsObjectNameInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrDebugUtilsLabelEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrDebugUtilsMessengerCallbackDataEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrDebugUtilsMessengerCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemEyeGazeInteractionPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEyeGazeSampleTimeEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSessionCreateInfoOverlayEXTX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataMainSessionVisibilityChangedEXTX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialAnchorCreateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerImageLayoutFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerAlphaBlendFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrViewConfigurationDepthRangeEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGraphicsBindingEGLMNDX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialGraphNodeBindingPropertiesMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemHandTrackingPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandTrackerCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandJointsLocateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandJointLocationEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandJointVelocityEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandJointLocationsEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandJointVelocitiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemHandTrackingMeshPropertiesMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandMeshSpaceCreateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandMeshUpdateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandMeshIndexBufferMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandMeshVertexMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandMeshVertexBufferMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandMeshMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandPoseTypeInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationStateMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationFrameStateMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrControllerModelKeyStateMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrControllerModelNodePropertiesMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrControllerModelPropertiesMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrControllerModelNodeStateMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrControllerModelStateMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrViewConfigurationViewFovEPIC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHolographicWindowAttachmentMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerReprojectionInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrAndroidSurfaceSwapchainCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainStateBaseHeaderFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerSecureContentFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrBodyJointLocationFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemBodyTrackingPropertiesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrBodyTrackerCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrBodySkeletonJointFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrBodySkeletonFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrBodyJointsLocateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrBodyJointLocationsFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrInteractionProfileDpadBindingEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrInteractionProfileAnalogThresholdVALVE* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandJointsMotionRangeInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrUuidMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneObserverCreateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneCreateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneSphereBoundMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneOrientedBoxBoundMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneFrustumBoundMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneBoundsMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrNewSceneComputeInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVisualMeshComputeLodInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneComponentMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneComponentsMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneComponentsGetInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneComponentLocationMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneComponentLocationsMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneComponentsLocateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneObjectMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneObjectsMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneComponentParentFilterInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneObjectTypesFilterInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrScenePlaneMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrScenePlanesMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrScenePlaneAlignmentFilterInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMeshMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMeshesMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMeshBuffersGetInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMeshBuffersMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMeshVertexBufferMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMeshIndicesUint32MSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMeshIndicesUint16MSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSerializedSceneFragmentDataGetInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrDeserializeSceneFragmentMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneDeserializeInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataDisplayRefreshRateChangedFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrViveTrackerPathsHTCX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataViveTrackerConnectedHTCX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemFacialTrackingPropertiesHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFacialExpressionsHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFacialTrackerCreateInfoHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemColorSpacePropertiesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVector4sFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandTrackingMeshFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandTrackingScaleFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandTrackingAimStateFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandCapsuleFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandTrackingCapsulesStateFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemSpatialEntityPropertiesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialAnchorCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceComponentStatusSetInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceComponentStatusFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrUuidEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataSpatialAnchorCreateCompleteFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataSpaceSetStatusCompleteFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFoveationProfileCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainCreateInfoFoveationFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainStateFoveationFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFoveationLevelProfileCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemKeyboardTrackingPropertiesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrKeyboardTrackingDescriptionFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrKeyboardSpaceCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrKeyboardTrackingQueryFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrTriangleMeshCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemPassthroughPropertiesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemPassthroughProperties2FB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughLayerCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerPassthroughFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGeometryInstanceCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGeometryInstanceTransformFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughStyleFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughColorMapMonoToRgbaFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughColorMapMonoToMonoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughBrightnessContrastSaturationFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataPassthroughStateChangedFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRenderModelPathInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRenderModelPropertiesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRenderModelBufferFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRenderModelLoadInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemRenderModelPropertiesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRenderModelCapabilitiesRequestFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrViewLocateFoveatedRenderingVARJO* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFoveatedViewConfigurationViewVARJO* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemFoveatedRenderingPropertiesVARJO* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerDepthTestVARJO* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemMarkerTrackingPropertiesVARJO* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataMarkerTrackingUpdateVARJO* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrMarkerSpaceCreateInfoVARJO* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFrameEndInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrGlobalDimmerFrameEndInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCoordinateSpaceCreateInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemMarkerUnderstandingPropertiesML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrMarkerDetectorCreateInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrMarkerDetectorArucoInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrMarkerDetectorSizeInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrMarkerDetectorAprilTagInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrMarkerDetectorCustomProfileInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrMarkerDetectorSnapshotInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrMarkerDetectorStateML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrMarkerSpaceCreateInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrLocalizationMapML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataLocalizationChangedML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrLocalizationMapQueryInfoBaseHeaderML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrMapLocalizationRequestInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrLocalizationMapImportInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrLocalizationEnableEventsInfoML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialAnchorPersistenceNameMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialAnchorPersistenceInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMarkerMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMarkersMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMarkerTypeFilterMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMarkerQRCodeMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneMarkerQRCodesMSFT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceQueryInfoBaseHeaderFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceFilterInfoBaseHeaderFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceQueryInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceStorageLocationFilterInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceUuidFilterInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceComponentFilterInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceQueryResultFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceQueryResultsFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataSpaceQueryResultsAvailableFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataSpaceQueryCompleteFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceSaveInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceEraseInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataSpaceSaveCompleteFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataSpaceEraseCompleteFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainImageFoveationVulkanFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainStateSamplerOpenGLESFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSwapchainStateSamplerVulkanFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceShareInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataSpaceShareCompleteFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerSpaceWarpInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemSpaceWarpPropertiesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHapticAmplitudeEnvelopeVibrationFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrExtent3DfFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrOffset3DfFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRect3DfFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSemanticLabelsFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRoomLayoutFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrBoundary2DFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSemanticLabelsSupportInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrDigitalLensControlALMALENCE* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataSceneCaptureCompleteFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSceneCaptureRequestInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceContainerFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFoveationEyeTrackedStateMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemFoveationEyeTrackedPropertiesMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemFaceTrackingPropertiesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFaceTrackerCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFaceExpressionInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFaceExpressionStatusFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFaceExpressionWeightsFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEyeGazeFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEyeTrackerCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEyeGazesInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemEyeTrackingPropertiesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEyeGazesFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughKeyboardHandsIntensityFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerSettingsFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHapticPcmVibrationFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrDevicePcmSampleRateStateFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerDepthTestFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrLocalDimmingFrameEndInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughPreferencesMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemVirtualKeyboardPropertiesMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVirtualKeyboardCreateInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVirtualKeyboardLocationInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVirtualKeyboardAnimationStateMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVirtualKeyboardModelAnimationStatesMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVirtualKeyboardTextureDataMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVirtualKeyboardInputInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVirtualKeyboardTextContextChangeInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataVirtualKeyboardCommitTextMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataVirtualKeyboardBackspaceMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataVirtualKeyboardEnterMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataVirtualKeyboardShownMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataVirtualKeyboardHiddenMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrExternalCameraIntrinsicsOCULUS* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrExternalCameraExtrinsicsOCULUS* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrExternalCameraOCULUS* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrVulkanSwapchainCreateInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPerformanceMetricsStateMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPerformanceMetricsCounterMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceListSaveInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataSpaceListSaveCompleteFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceUserCreateInfoFB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemHeadsetIdPropertiesMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRecommendedLayerResolutionMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrRecommendedLayerResolutionGetInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughColorLutDataMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughColorLutCreateInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughColorLutUpdateInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughColorMapLutMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughColorMapInterpolatedLutMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemPassthroughColorLutPropertiesMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceTriangleMeshGetInfoMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpaceTriangleMeshMETA* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemFaceTrackingProperties2FB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFaceTrackerCreateInfo2FB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFaceExpressionInfo2FB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFaceExpressionWeights2FB* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughCreateInfoHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughColorHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPassthroughMeshTransformInfoHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrCompositionLayerPassthroughHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFoveationApplyInfoHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFoveationConfigurationHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFoveationDynamicModeInfoHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrFoveationCustomModeInfoHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemAnchorPropertiesHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialAnchorNameHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSpatialAnchorCreateInfoHTC* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActiveActionSetPriorityEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrActiveActionSetPrioritiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemForceFeedbackCurlPropertiesMNDX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrForceFeedbackCurlApplyLocationMNDX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrForceFeedbackCurlApplyLocationsMNDX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandTrackingDataSourceInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrHandTrackingDataSourceStateEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemPlaneDetectionPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPlaneDetectorCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrExtent3DfEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPlaneDetectorBeginInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPlaneDetectorGetInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPlaneDetectorLocationEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPlaneDetectorLocationsEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrPlaneDetectorPolygonBufferEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataUserPresenceChangedEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrSystemUserPresencePropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataHeadsetFitChangedML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrEventDataEyeCalibrationChangedML* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_XrUserCalibrationEnableEventsInfoML* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_STRUCT_DECODERS_FORWARD_H
