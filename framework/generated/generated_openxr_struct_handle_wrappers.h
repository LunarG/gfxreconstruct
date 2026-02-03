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

#ifndef  GFXRECON_GENERATED_OPENXR_STRUCT_HANDLE_WRAPPERS_H
#define  GFXRECON_GENERATED_OPENXR_STRUCT_HANDLE_WRAPPERS_H

#if ENABLE_OPENXR_SUPPORT

#include "encode/custom_openxr_struct_handle_wrappers.h"
#include "encode/openxr_handle_wrapper_util.h"
#include "format/platform_types.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(openxr_wrappers)

void UnwrapStructHandles(XrApiLayerProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrExtensionProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInstanceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInstanceProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataBuffer* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemGetInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSessionCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceVelocity* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrReferenceSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceLocation* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrViewConfigurationProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrViewConfigurationView* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageBaseHeader* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageAcquireInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageWaitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageReleaseInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSessionBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFrameWaitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFrameState* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFrameBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerBaseHeader* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFrameEndInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrViewLocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrViewState* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrView* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionSetCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInteractionProfileSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSessionActionSetsAttachInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInteractionProfileState* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionStateGetInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionStateBoolean* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionStateFloat* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionStateVector2f* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionStatePose* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActiveActionSet* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionsSyncInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrBoundSourcesForActionEnumerateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInputSourceLocalizedNameGetInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHapticActionInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainSubImage* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerProjectionView* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerProjection* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerQuad* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataBaseHeader* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataEventsLost* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataInstanceLossPending* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSessionStateChanged* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataReferenceSpaceChangePending* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataInteractionProfileChanged* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHapticVibration* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpacesLocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceLocations* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceVelocities* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerCubeKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInstanceCreateInfoAndroidKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerDepthInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVulkanSwapchainFormatListCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerCylinderKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerEquirectKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingOpenGLWin32KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingOpenGLXlibKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingOpenGLXcbKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingOpenGLWaylandKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageOpenGLKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsRequirementsOpenGLKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingOpenGLESAndroidKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageOpenGLESKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsRequirementsOpenGLESKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingVulkanKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageVulkanKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsRequirementsVulkanKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingD3D11KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageD3D11KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsRequirementsD3D11KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingD3D12KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageD3D12KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsRequirementsD3D12KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingMetalKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageMetalKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsRequirementsMetalKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVisibilityMaskKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVisibilityMaskChangedKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerColorScaleBiasKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrLoaderInitInfoAndroidKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVulkanGraphicsDeviceGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerEquirect2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrBindingModificationBaseHeaderKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrBindingModificationsKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataPerfSettingsEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrDebugUtilsLabelEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrDebugUtilsMessengerCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrDebugUtilsMessengerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemEyeGazeInteractionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEyeGazeSampleTimeEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSessionCreateInfoOverlayEXTX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataMainSessionVisibilityChangedEXTX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerImageLayoutFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerAlphaBlendFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrViewConfigurationDepthRangeEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingEGLMNDX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialGraphNodeSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialGraphStaticNodeBindingCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialGraphNodeBindingPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemHandTrackingPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandTrackerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandJointsLocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandJointLocationsEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandJointVelocitiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemHandTrackingMeshPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandMeshSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandMeshUpdateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandMeshMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandPoseTypeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSecondaryViewConfigurationSessionBeginInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSecondaryViewConfigurationStateMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSecondaryViewConfigurationFrameStateMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSecondaryViewConfigurationLayerInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSecondaryViewConfigurationFrameEndInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrControllerModelKeyStateMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrControllerModelNodePropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrControllerModelPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrControllerModelNodeStateMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrControllerModelStateMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrViewConfigurationViewFovEPIC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHolographicWindowAttachmentMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerReprojectionInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerReprojectionPlaneOverrideMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrAndroidSurfaceSwapchainCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainStateBaseHeaderFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerSecureContentFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemBodyTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrBodyTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrBodySkeletonFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrBodyJointsLocateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrBodyJointLocationsFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInteractionProfileDpadBindingEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInteractionProfileAnalogThresholdVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandJointsMotionRangeInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneObserverCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneBoundsMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrNewSceneComputeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVisualMeshComputeLodInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneComponentsMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneComponentsGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneComponentLocationsMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneComponentsLocateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneObjectsMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneComponentParentFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneObjectTypesFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrScenePlanesMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrScenePlaneAlignmentFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneMeshesMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneMeshBuffersGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneMeshBuffersMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneMeshVertexBufferMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneMeshIndicesUint32MSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneMeshIndicesUint16MSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSerializedSceneFragmentDataGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneDeserializeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataDisplayRefreshRateChangedFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrViveTrackerPathsHTCX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataViveTrackerConnectedHTCX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemFacialTrackingPropertiesHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFacialExpressionsHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFacialTrackerCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemColorSpacePropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandTrackingMeshFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandTrackingScaleFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandTrackingAimStateFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandTrackingCapsulesStateFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemSpatialEntityPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceComponentStatusSetInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceComponentStatusFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpatialAnchorCreateCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceSetStatusCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFoveationProfileCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainCreateInfoFoveationFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainStateFoveationFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFoveationLevelProfileCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemKeyboardTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrKeyboardSpaceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrKeyboardTrackingQueryFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrTriangleMeshCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemPassthroughPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemPassthroughProperties2FB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughLayerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerPassthroughFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGeometryInstanceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGeometryInstanceTransformFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughStyleFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorMapMonoToRgbaFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorMapMonoToMonoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughBrightnessContrastSaturationFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataPassthroughStateChangedFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRenderModelPathInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRenderModelPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRenderModelBufferFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRenderModelLoadInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemRenderModelPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRenderModelCapabilitiesRequestFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrViewLocateFoveatedRenderingVARJO* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFoveatedViewConfigurationViewVARJO* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemFoveatedRenderingPropertiesVARJO* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerDepthTestVARJO* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemMarkerTrackingPropertiesVARJO* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataMarkerTrackingUpdateVARJO* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMarkerSpaceCreateInfoVARJO* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFrameEndInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGlobalDimmerFrameEndInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCoordinateSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemMarkerUnderstandingPropertiesML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMarkerDetectorCreateInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMarkerDetectorArucoInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMarkerDetectorSizeInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMarkerDetectorAprilTagInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMarkerDetectorCustomProfileInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMarkerDetectorSnapshotInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMarkerDetectorStateML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMarkerSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrLocalizationMapML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataLocalizationChangedML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMapLocalizationRequestInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrLocalizationMapImportInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrLocalizationEnableEventsInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorPersistenceInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneMarkersMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneMarkerTypeFilterMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneMarkerQRCodesMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceQueryInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceStorageLocationFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceUuidFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceComponentFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceQueryResultFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceQueryResultsFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceQueryResultsAvailableFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceQueryCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceEraseInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceEraseCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageFoveationVulkanFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainStateAndroidSurfaceDimensionsFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainStateSamplerOpenGLESFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainStateSamplerVulkanFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceShareInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceShareCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerSpaceWarpInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemSpaceWarpPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHapticAmplitudeEnvelopeVibrationFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSemanticLabelsFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRoomLayoutFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrBoundary2DFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSemanticLabelsSupportInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrDigitalLensControlALMALENCE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSceneCaptureCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneCaptureRequestInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceContainerFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFoveationEyeTrackedProfileCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFoveationEyeTrackedStateMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemFoveationEyeTrackedPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemFaceTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFaceTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFaceExpressionInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFaceExpressionWeightsFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEyeTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEyeGazesInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemEyeTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEyeGazesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughKeyboardHandsIntensityFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerSettingsFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHapticPcmVibrationFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrDevicePcmSampleRateStateFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerDepthTestFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrLocalDimmingFrameEndInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughPreferencesMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemVirtualKeyboardPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardSpaceCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardLocationInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardModelVisibilitySetInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardAnimationStateMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardModelAnimationStatesMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardTextureDataMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardInputInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardTextContextChangeInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVirtualKeyboardCommitTextMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVirtualKeyboardBackspaceMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVirtualKeyboardEnterMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVirtualKeyboardShownMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVirtualKeyboardHiddenMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrExternalCameraOCULUS* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVulkanSwapchainCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPerformanceMetricsStateMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPerformanceMetricsCounterMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceListSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceListSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceUserCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemHeadsetIdPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRecommendedLayerResolutionMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRecommendedLayerResolutionGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorLutCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorLutUpdateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorMapLutMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorMapInterpolatedLutMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemPassthroughColorLutPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceTriangleMeshGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceTriangleMeshMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemFaceTrackingProperties2FB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFaceTrackerCreateInfo2FB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFaceExpressionInfo2FB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFaceExpressionWeights2FB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEnvironmentDepthProviderCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEnvironmentDepthSwapchainCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEnvironmentDepthSwapchainStateMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEnvironmentDepthImageAcquireInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEnvironmentDepthImageViewMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEnvironmentDepthImageMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEnvironmentDepthHandRemovalSetInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemEnvironmentDepthPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughMeshTransformInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerPassthroughHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFoveationApplyInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFoveationDynamicModeInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFoveationCustomModeInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemAnchorPropertiesHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActiveActionSetPriorityEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActiveActionSetPrioritiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemForceFeedbackCurlPropertiesMNDX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrForceFeedbackCurlApplyLocationsMNDX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandTrackingDataSourceInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandTrackingDataSourceStateEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemPlaneDetectionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPlaneDetectorCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPlaneDetectorBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPlaneDetectorGetInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPlaneDetectorLocationEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPlaneDetectorLocationsEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPlaneDetectorPolygonBufferEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFutureCancelInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFuturePollInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFutureCompletionEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFuturePollResultEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataUserPresenceChangedEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSystemUserPresencePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataHeadsetFitChangedML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataEyeCalibrationChangedML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrUserCalibrationEnableEventsInfoML* value, HandleUnwrapMemory* unwrap_memory);

XrBaseInStructure* CopyNextStruct(const XrBaseInStructure* base, HandleUnwrapMemory* unwrap_memory);

void* UnwrapNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory);

template <typename ParentWrapper, typename CoParentWrapper, typename T>
void CreateWrappedStructArrayHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id);

template <typename T>
T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));

    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);
    size_t         num_bytes = len * sizeof(T);

    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));
}

template <typename T>
T* UnwrapStructPtrHandles(const T* value, HandleUnwrapMemory* unwrap_memory)
{
    T* unwrapped_struct = nullptr;

    if (value != nullptr)
    {
        unwrapped_struct = MakeUnwrapStructs(value, 1, unwrap_memory);
        UnwrapStructHandles(unwrapped_struct, unwrap_memory);
    }

    return unwrapped_struct;
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrSystemProperties* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        openxr_wrappers::CreateWrappedAtom<ParentWrapper, openxr_wrappers::SystemIdWrapper>(parent, &value->systemId, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrSpaceLocation* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrInteractionProfileState* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        openxr_wrappers::CreateWrappedAtom<ParentWrapper, openxr_wrappers::PathWrapper>(parent, &value->interactionProfile, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrControllerModelKeyStateMSFT* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        openxr_wrappers::CreateWrappedAtom<ParentWrapper, openxr_wrappers::ControllerModelKeyMSFTWrapper>(parent, &value->modelKey, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrViveTrackerPathsHTCX* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        openxr_wrappers::CreateWrappedAtom<ParentWrapper, openxr_wrappers::PathWrapper>(parent, &value->persistentPath, get_id);
        openxr_wrappers::CreateWrappedAtom<ParentWrapper, openxr_wrappers::PathWrapper>(parent, &value->rolePath, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrRenderModelPathInfoFB* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        openxr_wrappers::CreateWrappedAtom<ParentWrapper, openxr_wrappers::PathWrapper>(parent, &value->path, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrRenderModelPropertiesFB* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        openxr_wrappers::CreateWrappedAtom<ParentWrapper, openxr_wrappers::RenderModelKeyFBWrapper>(parent, &value->modelKey, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrSpaceQueryResultsFB* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        openxr_wrappers::CreateWrappedStructArrayHandles<ParentWrapper, CoParentWrapper, XrSpaceQueryResultFB>(parent, co_parent, value->results, value->resultCapacityInput, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrSpaceQueryResultFB* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        openxr_wrappers::CreateWrappedHandle<ParentWrapper, CoParentWrapper, openxr_wrappers::SpaceWrapper>(parent, co_parent, &value->space, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper, typename T>
void CreateWrappedStructArrayHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value[i], get_id);
        }
    }
}

template <typename T>
T* UnwrapStructArrayHandles(T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((values != nullptr) && (len > 0))
    {
        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);

        for (size_t i = 0; i < len; ++i)
        {
            UnwrapStructHandles(&unwrapped_structs[i], unwrap_memory);
        }

        return unwrapped_structs;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return values;
}

template <typename T>
T* UnwrapStructPtrArrayHandles(T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((values != nullptr) && (len > 0))
    {
        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);

        for (size_t i = 0; i < len; ++i)
        {
            UnwrapStructHandles(unwrapped_structs[i], unwrap_memory);
        }

        return unwrapped_structs;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return values;
}

GFXRECON_END_NAMESPACE(openxr_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_GENERATED_OPENXR_STRUCT_HANDLE_WRAPPERS_H
