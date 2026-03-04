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

#ifndef  GFXRECON_GENERATED_OPENXR_STRUCT_TO_JSON_H
#define  GFXRECON_GENERATED_OPENXR_STRUCT_TO_JSON_H

#if ENABLE_OPENXR_SUPPORT

#include "decode/custom_openxr_struct_to_json.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerProperties* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtensionProperties* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApplicationInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceCreateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceProperties* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataBuffer* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemGetInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemGraphicsProperties* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemTrackingProperties* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemProperties* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionCreateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector3f* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocity* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrQuaternionf* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPosef* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrReferenceSpaceCreateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent2Df* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSpaceCreateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocation* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationProperties* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationView* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainCreateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageBaseHeader* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageAcquireInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageWaitInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageReleaseInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionBeginInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameWaitInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameState* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameBeginInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerBaseHeader* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameEndInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewLocateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewState* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFovf* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrView* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSetCreateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionCreateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSuggestedBinding* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileSuggestedBinding* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionActionSetsAttachInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileState* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateGetInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateBoolean* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateFloat* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector2f* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateVector2f* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStatePose* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSet* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionsSyncInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoundSourcesForActionEnumerateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInputSourceLocalizedNameGetInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticActionInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticBaseHeader* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset2Di* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent2Di* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect2Di* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainSubImage* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerProjectionView* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerProjection* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerQuad* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataBaseHeader* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataEventsLost* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataInstanceLossPending* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSessionStateChanged* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataReferenceSpaceChangePending* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataInteractionProfileChanged* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticVibration* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset2Df* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect2Df* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector4f* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrColor4f* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerNextInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerCreateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrNegotiateApiLayerRequest* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrColor3f* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent3Df* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpheref* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoxf* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrustumf* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUuid* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpacesLocateInfo* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocationData* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocations* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocityData* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocities* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerCubeKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceCreateInfoAndroidKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthInfoKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanSwapchainFormatListCreateInfoKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerCylinderKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerEquirectKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLWin32KHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLXlibKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLXcbKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLWaylandKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageOpenGLKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsOpenGLKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLESAndroidKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageOpenGLESKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsOpenGLESKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingVulkanKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageVulkanKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsVulkanKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingD3D11KHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageD3D11KHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsD3D11KHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingD3D12KHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageD3D12KHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsD3D12KHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingMetalKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageMetalKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsMetalKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVisibilityMaskKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVisibilityMaskChangedKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerColorScaleBiasKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLoaderInitInfoBaseHeaderKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLoaderInitInfoAndroidKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanGraphicsDeviceGetInfoKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerEquirect2KHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBindingModificationBaseHeaderKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBindingModificationsKHR* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataPerfSettingsEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsObjectNameInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsLabelEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsMessengerCallbackDataEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsMessengerCreateInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEyeGazeInteractionPropertiesEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazeSampleTimeEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionCreateInfoOverlayEXTX* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataMainSessionVisibilityChangedEXTX* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerImageLayoutFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerAlphaBlendFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationDepthRangeEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingEGLMNDX* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeBindingPropertiesMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHandTrackingPropertiesEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackerCreateInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointsLocateInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointLocationEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointVelocityEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointLocationsEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointVelocitiesEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHandTrackingMeshPropertiesMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshSpaceCreateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshUpdateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshIndexBufferMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshVertexMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshVertexBufferMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandPoseTypeInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationStateMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationFrameStateMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelKeyStateMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelNodePropertiesMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelPropertiesMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelNodeStateMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelStateMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationViewFovEPIC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHolographicWindowAttachmentMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerReprojectionInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrAndroidSurfaceSwapchainCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateBaseHeaderFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSecureContentFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointLocationFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemBodyTrackingPropertiesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyTrackerCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodySkeletonJointFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodySkeletonFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointsLocateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointLocationsFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileDpadBindingEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileAnalogThresholdVALVE* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointsMotionRangeInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUuidMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObserverCreateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneCreateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneSphereBoundMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneOrientedBoxBoundMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneFrustumBoundMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneBoundsMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrNewSceneComputeInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVisualMeshComputeLodInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsGetInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentLocationMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentLocationsMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsLocateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectsMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentParentFilterInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectTypesFilterInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlaneMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlanesMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlaneAlignmentFilterInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshesMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshBuffersGetInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshBuffersMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshVertexBufferMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshIndicesUint32MSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshIndicesUint16MSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSerializedSceneFragmentDataGetInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDeserializeSceneFragmentMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneDeserializeInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataDisplayRefreshRateChangedFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViveTrackerPathsHTCX* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataViveTrackerConnectedHTCX* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFacialTrackingPropertiesHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFacialExpressionsHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFacialTrackerCreateInfoHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemColorSpacePropertiesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector4sFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingMeshFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingScaleFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingAimStateFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandCapsuleFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingCapsulesStateFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemSpatialEntityPropertiesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentStatusSetInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentStatusFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpatialAnchorCreateCompleteFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceSetStatusCompleteFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationProfileCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainCreateInfoFoveationFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateFoveationFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationLevelProfileCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemKeyboardTrackingPropertiesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardTrackingDescriptionFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardSpaceCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardTrackingQueryFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrTriangleMeshCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughPropertiesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughProperties2FB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughLayerCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerPassthroughFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGeometryInstanceCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGeometryInstanceTransformFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughStyleFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapMonoToRgbaFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapMonoToMonoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughBrightnessContrastSaturationFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataPassthroughStateChangedFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelPathInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelPropertiesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelBufferFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelLoadInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemRenderModelPropertiesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelCapabilitiesRequestFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewLocateFoveatedRenderingVARJO* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveatedViewConfigurationViewVARJO* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFoveatedRenderingPropertiesVARJO* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthTestVARJO* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemMarkerTrackingPropertiesVARJO* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataMarkerTrackingUpdateVARJO* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerSpaceCreateInfoVARJO* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameEndInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGlobalDimmerFrameEndInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCoordinateSpaceCreateInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemMarkerUnderstandingPropertiesML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorCreateInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorArucoInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorSizeInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorAprilTagInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorCustomProfileInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorSnapshotInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorStateML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerSpaceCreateInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataLocalizationChangedML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapQueryInfoBaseHeaderML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMapLocalizationRequestInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapImportInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationEnableEventsInfoML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorPersistenceNameMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorPersistenceInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkersMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerTypeFilterMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerQRCodeMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerQRCodesMSFT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryInfoBaseHeaderFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceFilterInfoBaseHeaderFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceStorageLocationFilterInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceUuidFilterInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentFilterInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryResultFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryResultsFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceQueryResultsAvailableFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceQueryCompleteFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceSaveInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceEraseInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceSaveCompleteFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceEraseCompleteFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageFoveationVulkanFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateSamplerOpenGLESFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateSamplerVulkanFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceShareInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceShareCompleteFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSpaceWarpInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemSpaceWarpPropertiesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticAmplitudeEnvelopeVibrationFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset3DfFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect3DfFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSemanticLabelsFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRoomLayoutFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoundary2DFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSemanticLabelsSupportInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDigitalLensControlALMALENCE* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSceneCaptureCompleteFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneCaptureRequestInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceContainerFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationEyeTrackedStateMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFoveationEyeTrackedPropertiesMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFaceTrackingPropertiesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceTrackerCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionStatusFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionWeightsFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazeFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeTrackerCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazesInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEyeTrackingPropertiesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazesFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughKeyboardHandsIntensityFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSettingsFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticPcmVibrationFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDevicePcmSampleRateStateFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthTestFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalDimmingFrameEndInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughPreferencesMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemVirtualKeyboardPropertiesMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardCreateInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardLocationInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardAnimationStateMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardModelAnimationStatesMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardTextureDataMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardInputInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardTextContextChangeInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardCommitTextMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardBackspaceMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardEnterMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardShownMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardHiddenMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraIntrinsicsOCULUS* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraExtrinsicsOCULUS* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraOCULUS* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanSwapchainCreateInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPerformanceMetricsStateMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPerformanceMetricsCounterMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceListSaveInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceListSaveCompleteFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceUserCreateInfoFB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHeadsetIdPropertiesMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRecommendedLayerResolutionMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRecommendedLayerResolutionGetInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutDataMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutCreateInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutUpdateInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapLutMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapInterpolatedLutMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughColorLutPropertiesMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceTriangleMeshGetInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceTriangleMeshMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFaceTrackingProperties2FB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceTrackerCreateInfo2FB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionInfo2FB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionWeights2FB* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthProviderCreateInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthSwapchainStateMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthImageAcquireInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthImageViewMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthImageMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEnvironmentDepthPropertiesMETA* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughCreateInfoHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughMeshTransformInfoHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerPassthroughHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationApplyInfoHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationConfigurationHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationDynamicModeInfoHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationCustomModeInfoHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemAnchorPropertiesHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorNameHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoHTC* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSetPriorityEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSetPrioritiesEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemForceFeedbackCurlPropertiesMNDX* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrForceFeedbackCurlApplyLocationMNDX* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrForceFeedbackCurlApplyLocationsMNDX* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingDataSourceInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingDataSourceStateEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPlaneDetectionPropertiesEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorCreateInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorBeginInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorGetInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorLocationEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorLocationsEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorPolygonBufferEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFutureCancelInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFuturePollInfoEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFutureCompletionBaseHeaderEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFutureCompletionEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFuturePollResultEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataUserPresenceChangedEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemUserPresencePropertiesEXT* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataHeadsetFitChangedML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataEyeCalibrationChangedML* data);
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUserCalibrationEnableEventsInfoML* data);


template <typename T>
void ParentChildFieldToJson(nlohmann::ordered_json& jdata, const T* data)
{
    // First read in the type to know which child we need to handle
    XrStructureType struct_type;
    FieldToJson(jdata["type"], struct_type);

    switch (struct_type)
    {
        default:
        {
            GFXRECON_LOG_WARNING("ParentChildFieldToJson: unrecognized child structure type %d", struct_type);
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrCompositionLayerProjection*>(data));
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_QUAD:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrCompositionLayerQuad*>(data));
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrCompositionLayerCubeKHR*>(data));
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrCompositionLayerCylinderKHR*>(data));
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrCompositionLayerEquirectKHR*>(data));
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrCompositionLayerEquirect2KHR*>(data));
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrCompositionLayerPassthroughFB*>(data));
            break;
        }
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrCompositionLayerPassthroughHTC*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_EVENTS_LOST:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataEventsLost*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataInstanceLossPending*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataSessionStateChanged*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataReferenceSpaceChangePending*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataInteractionProfileChanged*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataVisibilityMaskChangedKHR*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataPerfSettingsEXT*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataMainSessionVisibilityChangedEXTX*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataDisplayRefreshRateChangedFB*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataViveTrackerConnectedHTCX*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataSpatialAnchorCreateCompleteFB*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataSpaceSetStatusCompleteFB*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataMarkerTrackingUpdateVARJO*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataLocalizationChangedML*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataSpaceQueryResultsAvailableFB*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataSpaceQueryCompleteFB*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataSpaceSaveCompleteFB*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataSpaceEraseCompleteFB*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataSpaceShareCompleteFB*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataSpaceListSaveCompleteFB*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataHeadsetFitChangedML*>(data));
            break;
        }
        case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrEventDataEyeCalibrationChangedML*>(data));
            break;
        }
        case XR_TYPE_HAPTIC_VIBRATION:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrHapticVibration*>(data));
            break;
        }
        case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrHapticAmplitudeEnvelopeVibrationFB*>(data));
            break;
        }
        case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrHapticPcmVibrationFB*>(data));
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSwapchainImageOpenGLKHR*>(data));
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSwapchainImageOpenGLESKHR*>(data));
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSwapchainImageVulkanKHR*>(data));
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSwapchainImageD3D11KHR*>(data));
            break;
        }
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSwapchainImageD3D12KHR*>(data));
            break;
        }
        case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrLoaderInitInfoAndroidKHR*>(data));
            break;
        }
        case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrInteractionProfileDpadBindingEXT*>(data));
            break;
        }
        case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrInteractionProfileAnalogThresholdVALVE*>(data));
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSwapchainStateFoveationFB*>(data));
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB*>(data));
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSwapchainStateSamplerOpenGLESFB*>(data));
            break;
        }
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSwapchainStateSamplerVulkanFB*>(data));
            break;
        }
        case XR_TYPE_SPACE_QUERY_INFO_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSpaceQueryInfoFB*>(data));
            break;
        }
        case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSpaceUuidFilterInfoFB*>(data));
            break;
        }
        case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrSpaceComponentFilterInfoFB*>(data));
            break;
        }
        case XR_TYPE_FUTURE_COMPLETION_EXT:
        {
            FieldToJson(jdata, reinterpret_cast<const Decoded_XrFutureCompletionEXT*>(data));
            break;
        }
    }
}

/// Works out the type of the struct at the end of a next pointer and dispatches
/// recursively to the FieldToJson for that.
void FieldToJson(nlohmann::ordered_json& jdata, const OpenXrNextNode* data);
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_GENERATED_OPENXR_STRUCT_TO_JSON_H
