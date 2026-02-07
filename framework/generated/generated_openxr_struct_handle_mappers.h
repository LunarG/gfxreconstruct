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

#if ENABLE_OPENXR_SUPPORT

#include "decode/common_consumer_base.h"
#include "decode/common_object_info_table.h"
#include "decode/openxr_next_node.h"
#include "format/platform_types.h"
#include "decode/custom_openxr_struct_handle_mappers.h"
#include "generated/generated_openxr_struct_decoders_forward.h"
#include "util/defines.h"

#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructHandles(Decoded_XrApiLayerProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrExtensionProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrApplicationInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInstanceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInstanceProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataBuffer* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemGetInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemGraphicsProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemTrackingProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSessionCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVector3f* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceVelocity* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrQuaternionf* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPosef* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrReferenceSpaceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrExtent2Df* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionSpaceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceLocation* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrViewConfigurationProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrViewConfigurationView* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageBaseHeader* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageAcquireInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageWaitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageReleaseInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSessionBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFrameWaitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFrameState* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFrameBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerBaseHeader* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFrameEndInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrViewLocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrViewState* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFovf* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrView* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionSetCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionSuggestedBinding* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInteractionProfileSuggestedBinding* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSessionActionSetsAttachInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInteractionProfileState* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionStateGetInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionStateBoolean* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionStateFloat* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVector2f* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionStateVector2f* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionStatePose* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActiveActionSet* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionsSyncInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBoundSourcesForActionEnumerateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInputSourceLocalizedNameGetInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHapticActionInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHapticBaseHeader* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrOffset2Di* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrExtent2Di* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRect2Di* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainSubImage* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerProjectionView* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerProjection* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerQuad* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataBaseHeader* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataEventsLost* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataInstanceLossPending* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSessionStateChanged* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataReferenceSpaceChangePending* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataInteractionProfileChanged* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHapticVibration* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrOffset2Df* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRect2Df* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVector4f* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrColor4f* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrApiLayerNextInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrApiLayerCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrNegotiateApiLayerRequest* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrColor3f* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrExtent3Df* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpheref* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBoxf* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFrustumf* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrUuid* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpacesLocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceLocationData* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceLocations* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceVelocityData* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceVelocities* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerCubeKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInstanceCreateInfoAndroidKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerDepthInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVulkanSwapchainFormatListCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerCylinderKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerEquirectKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLWin32KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLXlibKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLXcbKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLWaylandKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageOpenGLKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsRequirementsOpenGLKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLESAndroidKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageOpenGLESKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsRequirementsOpenGLESKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingVulkanKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageVulkanKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsRequirementsVulkanKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingD3D11KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageD3D11KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsRequirementsD3D11KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingD3D12KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageD3D12KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsRequirementsD3D12KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingMetalKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageMetalKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsRequirementsMetalKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVisibilityMaskKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVisibilityMaskChangedKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerColorScaleBiasKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrLoaderInitInfoBaseHeaderKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrLoaderInitInfoAndroidKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVulkanGraphicsDeviceGetInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerEquirect2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBindingModificationBaseHeaderKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBindingModificationsKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataPerfSettingsEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrDebugUtilsObjectNameInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrDebugUtilsLabelEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrDebugUtilsMessengerCallbackDataEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrDebugUtilsMessengerCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemEyeGazeInteractionPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEyeGazeSampleTimeEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSessionCreateInfoOverlayEXTX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataMainSessionVisibilityChangedEXTX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerImageLayoutFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerAlphaBlendFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrViewConfigurationDepthRangeEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingEGLMNDX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialGraphNodeBindingPropertiesMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemHandTrackingPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandTrackerCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandJointsLocateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandJointLocationEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandJointVelocityEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandJointLocationsEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandJointVelocitiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemHandTrackingMeshPropertiesMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandMeshSpaceCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandMeshUpdateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandMeshIndexBufferMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandMeshVertexMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandMeshVertexBufferMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandMeshMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandPoseTypeInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSecondaryViewConfigurationStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSecondaryViewConfigurationFrameStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrControllerModelKeyStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrControllerModelNodePropertiesMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrControllerModelPropertiesMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrControllerModelNodeStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrControllerModelStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrViewConfigurationViewFovEPIC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHolographicWindowAttachmentMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerReprojectionInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrAndroidSurfaceSwapchainCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainStateBaseHeaderFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerSecureContentFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBodyJointLocationFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemBodyTrackingPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBodyTrackerCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBodySkeletonJointFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBodySkeletonFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBodyJointsLocateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBodyJointLocationsFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInteractionProfileDpadBindingEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInteractionProfileAnalogThresholdVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandJointsMotionRangeInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrUuidMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneObserverCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneSphereBoundMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneOrientedBoxBoundMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneFrustumBoundMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneBoundsMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrNewSceneComputeInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVisualMeshComputeLodInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneComponentMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneComponentsMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneComponentsGetInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneComponentLocationMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneComponentLocationsMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneComponentsLocateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneObjectMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneObjectsMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneComponentParentFilterInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneObjectTypesFilterInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrScenePlaneMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrScenePlanesMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrScenePlaneAlignmentFilterInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMeshMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMeshesMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMeshBuffersGetInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMeshBuffersMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMeshVertexBufferMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMeshIndicesUint32MSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMeshIndicesUint16MSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSerializedSceneFragmentDataGetInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrDeserializeSceneFragmentMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneDeserializeInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataDisplayRefreshRateChangedFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrViveTrackerPathsHTCX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataViveTrackerConnectedHTCX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemFacialTrackingPropertiesHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFacialExpressionsHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFacialTrackerCreateInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemColorSpacePropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVector4sFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandTrackingMeshFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandTrackingScaleFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandTrackingAimStateFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandCapsuleFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandTrackingCapsulesStateFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemSpatialEntityPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceComponentStatusSetInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceComponentStatusFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpatialAnchorCreateCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceSetStatusCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFoveationProfileCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainCreateInfoFoveationFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainStateFoveationFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFoveationLevelProfileCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemKeyboardTrackingPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrKeyboardTrackingDescriptionFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrKeyboardSpaceCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrKeyboardTrackingQueryFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrTriangleMeshCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemPassthroughPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemPassthroughProperties2FB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughLayerCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerPassthroughFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGeometryInstanceCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGeometryInstanceTransformFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughStyleFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorMapMonoToRgbaFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorMapMonoToMonoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughBrightnessContrastSaturationFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataPassthroughStateChangedFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRenderModelPathInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRenderModelPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRenderModelBufferFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRenderModelLoadInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemRenderModelPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRenderModelCapabilitiesRequestFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrViewLocateFoveatedRenderingVARJO* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFoveatedViewConfigurationViewVARJO* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemFoveatedRenderingPropertiesVARJO* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerDepthTestVARJO* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemMarkerTrackingPropertiesVARJO* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataMarkerTrackingUpdateVARJO* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMarkerSpaceCreateInfoVARJO* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFrameEndInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGlobalDimmerFrameEndInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCoordinateSpaceCreateInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemMarkerUnderstandingPropertiesML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMarkerDetectorCreateInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMarkerDetectorArucoInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMarkerDetectorSizeInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMarkerDetectorAprilTagInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMarkerDetectorCustomProfileInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMarkerDetectorSnapshotInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMarkerDetectorStateML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMarkerSpaceCreateInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrLocalizationMapML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataLocalizationChangedML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrLocalizationMapQueryInfoBaseHeaderML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMapLocalizationRequestInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrLocalizationMapImportInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrLocalizationEnableEventsInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorPersistenceNameMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorPersistenceInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMarkerMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMarkersMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMarkerTypeFilterMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMarkerQRCodeMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneMarkerQRCodesMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceQueryInfoBaseHeaderFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceFilterInfoBaseHeaderFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceQueryInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceStorageLocationFilterInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceUuidFilterInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceComponentFilterInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceQueryResultFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceQueryResultsFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceQueryResultsAvailableFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceQueryCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceSaveInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceEraseInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceSaveCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceEraseCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageFoveationVulkanFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainStateSamplerOpenGLESFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainStateSamplerVulkanFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceShareInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceShareCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerSpaceWarpInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemSpaceWarpPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHapticAmplitudeEnvelopeVibrationFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrOffset3DfFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRect3DfFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSemanticLabelsFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRoomLayoutFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBoundary2DFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSemanticLabelsSupportInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrDigitalLensControlALMALENCE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSceneCaptureCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneCaptureRequestInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceContainerFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFoveationEyeTrackedStateMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemFoveationEyeTrackedPropertiesMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemFaceTrackingPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFaceTrackerCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFaceExpressionInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFaceExpressionStatusFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFaceExpressionWeightsFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEyeGazeFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEyeTrackerCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEyeGazesInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemEyeTrackingPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEyeGazesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughKeyboardHandsIntensityFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerSettingsFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHapticPcmVibrationFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrDevicePcmSampleRateStateFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerDepthTestFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrLocalDimmingFrameEndInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughPreferencesMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemVirtualKeyboardPropertiesMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardLocationInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardAnimationStateMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardModelAnimationStatesMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardTextureDataMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardInputInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardTextContextChangeInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardCommitTextMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardBackspaceMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardEnterMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardShownMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardHiddenMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrExternalCameraIntrinsicsOCULUS* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrExternalCameraExtrinsicsOCULUS* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrExternalCameraOCULUS* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVulkanSwapchainCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPerformanceMetricsStateMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPerformanceMetricsCounterMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceListSaveInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceListSaveCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceUserCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemHeadsetIdPropertiesMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRecommendedLayerResolutionMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRecommendedLayerResolutionGetInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorLutDataMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorLutCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorLutUpdateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorMapLutMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorMapInterpolatedLutMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemPassthroughColorLutPropertiesMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceTriangleMeshGetInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceTriangleMeshMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemFaceTrackingProperties2FB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFaceTrackerCreateInfo2FB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFaceExpressionInfo2FB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFaceExpressionWeights2FB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEnvironmentDepthProviderCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEnvironmentDepthSwapchainCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEnvironmentDepthSwapchainStateMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEnvironmentDepthImageAcquireInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEnvironmentDepthImageViewMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEnvironmentDepthImageMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEnvironmentDepthHandRemovalSetInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemEnvironmentDepthPropertiesMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughCreateInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughMeshTransformInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerPassthroughHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFoveationApplyInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFoveationConfigurationHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFoveationDynamicModeInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFoveationCustomModeInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemAnchorPropertiesHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorNameHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActiveActionSetPriorityEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActiveActionSetPrioritiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemForceFeedbackCurlPropertiesMNDX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrForceFeedbackCurlApplyLocationMNDX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrForceFeedbackCurlApplyLocationsMNDX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandTrackingDataSourceInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandTrackingDataSourceStateEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemPlaneDetectionPropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPlaneDetectorCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPlaneDetectorBeginInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPlaneDetectorGetInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPlaneDetectorLocationEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPlaneDetectorLocationsEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPlaneDetectorPolygonBufferEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFutureCancelInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFuturePollInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFutureCompletionBaseHeaderEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFutureCompletionEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFuturePollResultEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataUserPresenceChangedEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSystemUserPresencePropertiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataHeadsetFitChangedML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataEyeCalibrationChangedML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrUserCalibrationEnableEventsInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapNextStructHandles(OpenXrNextNode* value, const CommonObjectInfoTable& object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSystemProperties* id_wrapper, const XrSystemProperties* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSpaceLocation* id_wrapper, const XrSpaceLocation* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrInteractionProfileState* id_wrapper, const XrInteractionProfileState* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrControllerModelKeyStateMSFT* id_wrapper, const XrControllerModelKeyStateMSFT* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrViveTrackerPathsHTCX* id_wrapper, const XrViveTrackerPathsHTCX* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrRenderModelPathInfoFB* id_wrapper, const XrRenderModelPathInfoFB* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrRenderModelPropertiesFB* id_wrapper, const XrRenderModelPropertiesFB* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSpaceQueryResultsFB* id_wrapper, const XrSpaceQueryResultsFB* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSpaceQueryResultFB* id_wrapper, const XrSpaceQueryResultFB* handle_struct, CommonObjectInfoTable* object_info_table);

void PushRecaptureStructHandleIds(const Decoded_XrSystemProperties* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_XrSpaceLocation* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_XrInteractionProfileState* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_XrControllerModelKeyStateMSFT* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_XrViveTrackerPathsHTCX* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_XrRenderModelPathInfoFB* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_XrRenderModelPropertiesFB* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_XrSpaceQueryResultsFB* id_wrapper, CommonConsumerBase* consumer);

void PushRecaptureStructHandleIds(const Decoded_XrSpaceQueryResultFB* id_wrapper, CommonConsumerBase* consumer);

#include "decode/common_struct_handle_mappers.h"
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
