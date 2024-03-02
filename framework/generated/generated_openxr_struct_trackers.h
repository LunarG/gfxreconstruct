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

#include "encode/handle_unwrap_memory.h"
#include "format/platform_types.h"
#include "util/defines.h"

#include <openxr/openxr.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename T>
T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));

    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);
    size_t         num_bytes = len * sizeof(T);

    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));
}

XrApiLayerProperties* TrackStruct(const XrApiLayerProperties* value, HandleUnwrapMemory* unwrap_memory);
XrExtensionProperties* TrackStruct(const XrExtensionProperties* value, HandleUnwrapMemory* unwrap_memory);
XrInstanceCreateInfo* TrackStruct(const XrInstanceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);
XrInstanceProperties* TrackStruct(const XrInstanceProperties* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataBuffer* TrackStruct(const XrEventDataBuffer* value, HandleUnwrapMemory* unwrap_memory);
XrSystemGetInfo* TrackStruct(const XrSystemGetInfo* value, HandleUnwrapMemory* unwrap_memory);
XrSystemProperties* TrackStruct(const XrSystemProperties* value, HandleUnwrapMemory* unwrap_memory);
XrSessionCreateInfo* TrackStruct(const XrSessionCreateInfo* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceVelocity* TrackStruct(const XrSpaceVelocity* value, HandleUnwrapMemory* unwrap_memory);
XrReferenceSpaceCreateInfo* TrackStruct(const XrReferenceSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);
XrActionSpaceCreateInfo* TrackStruct(const XrActionSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceLocation* TrackStruct(const XrSpaceLocation* value, HandleUnwrapMemory* unwrap_memory);
XrViewConfigurationProperties* TrackStruct(const XrViewConfigurationProperties* value, HandleUnwrapMemory* unwrap_memory);
XrViewConfigurationView* TrackStruct(const XrViewConfigurationView* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainCreateInfo* TrackStruct(const XrSwapchainCreateInfo* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainImageBaseHeader* TrackStruct(const XrSwapchainImageBaseHeader* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainImageAcquireInfo* TrackStruct(const XrSwapchainImageAcquireInfo* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainImageWaitInfo* TrackStruct(const XrSwapchainImageWaitInfo* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainImageReleaseInfo* TrackStruct(const XrSwapchainImageReleaseInfo* value, HandleUnwrapMemory* unwrap_memory);
XrSessionBeginInfo* TrackStruct(const XrSessionBeginInfo* value, HandleUnwrapMemory* unwrap_memory);
XrFrameWaitInfo* TrackStruct(const XrFrameWaitInfo* value, HandleUnwrapMemory* unwrap_memory);
XrFrameState* TrackStruct(const XrFrameState* value, HandleUnwrapMemory* unwrap_memory);
XrFrameBeginInfo* TrackStruct(const XrFrameBeginInfo* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerBaseHeader* TrackStruct(const XrCompositionLayerBaseHeader* value, HandleUnwrapMemory* unwrap_memory);
XrFrameEndInfo* TrackStruct(const XrFrameEndInfo* value, HandleUnwrapMemory* unwrap_memory);
XrViewLocateInfo* TrackStruct(const XrViewLocateInfo* value, HandleUnwrapMemory* unwrap_memory);
XrViewState* TrackStruct(const XrViewState* value, HandleUnwrapMemory* unwrap_memory);
XrView* TrackStruct(const XrView* value, HandleUnwrapMemory* unwrap_memory);
XrActionSetCreateInfo* TrackStruct(const XrActionSetCreateInfo* value, HandleUnwrapMemory* unwrap_memory);
XrActionCreateInfo* TrackStruct(const XrActionCreateInfo* value, HandleUnwrapMemory* unwrap_memory);
XrInteractionProfileSuggestedBinding* TrackStruct(const XrInteractionProfileSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory);
XrSessionActionSetsAttachInfo* TrackStruct(const XrSessionActionSetsAttachInfo* value, HandleUnwrapMemory* unwrap_memory);
XrInteractionProfileState* TrackStruct(const XrInteractionProfileState* value, HandleUnwrapMemory* unwrap_memory);
XrActionStateGetInfo* TrackStruct(const XrActionStateGetInfo* value, HandleUnwrapMemory* unwrap_memory);
XrActionStateBoolean* TrackStruct(const XrActionStateBoolean* value, HandleUnwrapMemory* unwrap_memory);
XrActionStateFloat* TrackStruct(const XrActionStateFloat* value, HandleUnwrapMemory* unwrap_memory);
XrActionStateVector2f* TrackStruct(const XrActionStateVector2f* value, HandleUnwrapMemory* unwrap_memory);
XrActionStatePose* TrackStruct(const XrActionStatePose* value, HandleUnwrapMemory* unwrap_memory);
XrActionsSyncInfo* TrackStruct(const XrActionsSyncInfo* value, HandleUnwrapMemory* unwrap_memory);
XrBoundSourcesForActionEnumerateInfo* TrackStruct(const XrBoundSourcesForActionEnumerateInfo* value, HandleUnwrapMemory* unwrap_memory);
XrInputSourceLocalizedNameGetInfo* TrackStruct(const XrInputSourceLocalizedNameGetInfo* value, HandleUnwrapMemory* unwrap_memory);
XrHapticActionInfo* TrackStruct(const XrHapticActionInfo* value, HandleUnwrapMemory* unwrap_memory);
XrHapticBaseHeader* TrackStruct(const XrHapticBaseHeader* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerProjectionView* TrackStruct(const XrCompositionLayerProjectionView* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerProjection* TrackStruct(const XrCompositionLayerProjection* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerQuad* TrackStruct(const XrCompositionLayerQuad* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataBaseHeader* TrackStruct(const XrEventDataBaseHeader* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataEventsLost* TrackStruct(const XrEventDataEventsLost* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataInstanceLossPending* TrackStruct(const XrEventDataInstanceLossPending* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataSessionStateChanged* TrackStruct(const XrEventDataSessionStateChanged* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataReferenceSpaceChangePending* TrackStruct(const XrEventDataReferenceSpaceChangePending* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataInteractionProfileChanged* TrackStruct(const XrEventDataInteractionProfileChanged* value, HandleUnwrapMemory* unwrap_memory);
XrHapticVibration* TrackStruct(const XrHapticVibration* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerCubeKHR* TrackStruct(const XrCompositionLayerCubeKHR* value, HandleUnwrapMemory* unwrap_memory);
XrInstanceCreateInfoAndroidKHR* TrackStruct(const XrInstanceCreateInfoAndroidKHR* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerDepthInfoKHR* TrackStruct(const XrCompositionLayerDepthInfoKHR* value, HandleUnwrapMemory* unwrap_memory);
XrVulkanSwapchainFormatListCreateInfoKHR* TrackStruct(const XrVulkanSwapchainFormatListCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerCylinderKHR* TrackStruct(const XrCompositionLayerCylinderKHR* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerEquirectKHR* TrackStruct(const XrCompositionLayerEquirectKHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsBindingOpenGLWin32KHR* TrackStruct(const XrGraphicsBindingOpenGLWin32KHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsBindingOpenGLXlibKHR* TrackStruct(const XrGraphicsBindingOpenGLXlibKHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsBindingOpenGLXcbKHR* TrackStruct(const XrGraphicsBindingOpenGLXcbKHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsBindingOpenGLWaylandKHR* TrackStruct(const XrGraphicsBindingOpenGLWaylandKHR* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainImageOpenGLKHR* TrackStruct(const XrSwapchainImageOpenGLKHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsRequirementsOpenGLKHR* TrackStruct(const XrGraphicsRequirementsOpenGLKHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsBindingOpenGLESAndroidKHR* TrackStruct(const XrGraphicsBindingOpenGLESAndroidKHR* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainImageOpenGLESKHR* TrackStruct(const XrSwapchainImageOpenGLESKHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsRequirementsOpenGLESKHR* TrackStruct(const XrGraphicsRequirementsOpenGLESKHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsBindingVulkanKHR* TrackStruct(const XrGraphicsBindingVulkanKHR* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainImageVulkanKHR* TrackStruct(const XrSwapchainImageVulkanKHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsRequirementsVulkanKHR* TrackStruct(const XrGraphicsRequirementsVulkanKHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsBindingD3D11KHR* TrackStruct(const XrGraphicsBindingD3D11KHR* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainImageD3D11KHR* TrackStruct(const XrSwapchainImageD3D11KHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsRequirementsD3D11KHR* TrackStruct(const XrGraphicsRequirementsD3D11KHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsBindingD3D12KHR* TrackStruct(const XrGraphicsBindingD3D12KHR* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainImageD3D12KHR* TrackStruct(const XrSwapchainImageD3D12KHR* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsRequirementsD3D12KHR* TrackStruct(const XrGraphicsRequirementsD3D12KHR* value, HandleUnwrapMemory* unwrap_memory);
XrVisibilityMaskKHR* TrackStruct(const XrVisibilityMaskKHR* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataVisibilityMaskChangedKHR* TrackStruct(const XrEventDataVisibilityMaskChangedKHR* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerColorScaleBiasKHR* TrackStruct(const XrCompositionLayerColorScaleBiasKHR* value, HandleUnwrapMemory* unwrap_memory);
XrLoaderInitInfoBaseHeaderKHR* TrackStruct(const XrLoaderInitInfoBaseHeaderKHR* value, HandleUnwrapMemory* unwrap_memory);
XrLoaderInitInfoAndroidKHR* TrackStruct(const XrLoaderInitInfoAndroidKHR* value, HandleUnwrapMemory* unwrap_memory);
XrVulkanInstanceCreateInfoKHR* TrackStruct(const XrVulkanInstanceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);
XrVulkanDeviceCreateInfoKHR* TrackStruct(const XrVulkanDeviceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);
XrVulkanGraphicsDeviceGetInfoKHR* TrackStruct(const XrVulkanGraphicsDeviceGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerEquirect2KHR* TrackStruct(const XrCompositionLayerEquirect2KHR* value, HandleUnwrapMemory* unwrap_memory);
XrBindingModificationBaseHeaderKHR* TrackStruct(const XrBindingModificationBaseHeaderKHR* value, HandleUnwrapMemory* unwrap_memory);
XrBindingModificationsKHR* TrackStruct(const XrBindingModificationsKHR* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataPerfSettingsEXT* TrackStruct(const XrEventDataPerfSettingsEXT* value, HandleUnwrapMemory* unwrap_memory);
XrDebugUtilsObjectNameInfoEXT* TrackStruct(const XrDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory);
XrDebugUtilsLabelEXT* TrackStruct(const XrDebugUtilsLabelEXT* value, HandleUnwrapMemory* unwrap_memory);
XrDebugUtilsMessengerCallbackDataEXT* TrackStruct(const XrDebugUtilsMessengerCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory);
XrDebugUtilsMessengerCreateInfoEXT* TrackStruct(const XrDebugUtilsMessengerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);
XrSystemEyeGazeInteractionPropertiesEXT* TrackStruct(const XrSystemEyeGazeInteractionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);
XrEyeGazeSampleTimeEXT* TrackStruct(const XrEyeGazeSampleTimeEXT* value, HandleUnwrapMemory* unwrap_memory);
XrSessionCreateInfoOverlayEXTX* TrackStruct(const XrSessionCreateInfoOverlayEXTX* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataMainSessionVisibilityChangedEXTX* TrackStruct(const XrEventDataMainSessionVisibilityChangedEXTX* value, HandleUnwrapMemory* unwrap_memory);
XrSpatialAnchorCreateInfoMSFT* TrackStruct(const XrSpatialAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSpatialAnchorSpaceCreateInfoMSFT* TrackStruct(const XrSpatialAnchorSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerImageLayoutFB* TrackStruct(const XrCompositionLayerImageLayoutFB* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerAlphaBlendFB* TrackStruct(const XrCompositionLayerAlphaBlendFB* value, HandleUnwrapMemory* unwrap_memory);
XrViewConfigurationDepthRangeEXT* TrackStruct(const XrViewConfigurationDepthRangeEXT* value, HandleUnwrapMemory* unwrap_memory);
XrGraphicsBindingEGLMNDX* TrackStruct(const XrGraphicsBindingEGLMNDX* value, HandleUnwrapMemory* unwrap_memory);
XrSpatialGraphNodeSpaceCreateInfoMSFT* TrackStruct(const XrSpatialGraphNodeSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSpatialGraphStaticNodeBindingCreateInfoMSFT* TrackStruct(const XrSpatialGraphStaticNodeBindingCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* TrackStruct(const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSpatialGraphNodeBindingPropertiesMSFT* TrackStruct(const XrSpatialGraphNodeBindingPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSystemHandTrackingPropertiesEXT* TrackStruct(const XrSystemHandTrackingPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);
XrHandTrackerCreateInfoEXT* TrackStruct(const XrHandTrackerCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);
XrHandJointsLocateInfoEXT* TrackStruct(const XrHandJointsLocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);
XrHandJointLocationsEXT* TrackStruct(const XrHandJointLocationsEXT* value, HandleUnwrapMemory* unwrap_memory);
XrHandJointVelocitiesEXT* TrackStruct(const XrHandJointVelocitiesEXT* value, HandleUnwrapMemory* unwrap_memory);
XrSystemHandTrackingMeshPropertiesMSFT* TrackStruct(const XrSystemHandTrackingMeshPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrHandMeshSpaceCreateInfoMSFT* TrackStruct(const XrHandMeshSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrHandMeshUpdateInfoMSFT* TrackStruct(const XrHandMeshUpdateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrHandMeshMSFT* TrackStruct(const XrHandMeshMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrHandPoseTypeInfoMSFT* TrackStruct(const XrHandPoseTypeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSecondaryViewConfigurationSessionBeginInfoMSFT* TrackStruct(const XrSecondaryViewConfigurationSessionBeginInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSecondaryViewConfigurationStateMSFT* TrackStruct(const XrSecondaryViewConfigurationStateMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSecondaryViewConfigurationFrameStateMSFT* TrackStruct(const XrSecondaryViewConfigurationFrameStateMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSecondaryViewConfigurationLayerInfoMSFT* TrackStruct(const XrSecondaryViewConfigurationLayerInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSecondaryViewConfigurationFrameEndInfoMSFT* TrackStruct(const XrSecondaryViewConfigurationFrameEndInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* TrackStruct(const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrControllerModelKeyStateMSFT* TrackStruct(const XrControllerModelKeyStateMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrControllerModelNodePropertiesMSFT* TrackStruct(const XrControllerModelNodePropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrControllerModelPropertiesMSFT* TrackStruct(const XrControllerModelPropertiesMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrControllerModelNodeStateMSFT* TrackStruct(const XrControllerModelNodeStateMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrControllerModelStateMSFT* TrackStruct(const XrControllerModelStateMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrViewConfigurationViewFovEPIC* TrackStruct(const XrViewConfigurationViewFovEPIC* value, HandleUnwrapMemory* unwrap_memory);
XrHolographicWindowAttachmentMSFT* TrackStruct(const XrHolographicWindowAttachmentMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerReprojectionInfoMSFT* TrackStruct(const XrCompositionLayerReprojectionInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerReprojectionPlaneOverrideMSFT* TrackStruct(const XrCompositionLayerReprojectionPlaneOverrideMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrAndroidSurfaceSwapchainCreateInfoFB* TrackStruct(const XrAndroidSurfaceSwapchainCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainStateBaseHeaderFB* TrackStruct(const XrSwapchainStateBaseHeaderFB* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerSecureContentFB* TrackStruct(const XrCompositionLayerSecureContentFB* value, HandleUnwrapMemory* unwrap_memory);
XrSystemBodyTrackingPropertiesFB* TrackStruct(const XrSystemBodyTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);
XrBodyTrackerCreateInfoFB* TrackStruct(const XrBodyTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrBodySkeletonFB* TrackStruct(const XrBodySkeletonFB* value, HandleUnwrapMemory* unwrap_memory);
XrBodyJointsLocateInfoFB* TrackStruct(const XrBodyJointsLocateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrBodyJointLocationsFB* TrackStruct(const XrBodyJointLocationsFB* value, HandleUnwrapMemory* unwrap_memory);
XrInteractionProfileDpadBindingEXT* TrackStruct(const XrInteractionProfileDpadBindingEXT* value, HandleUnwrapMemory* unwrap_memory);
XrInteractionProfileAnalogThresholdVALVE* TrackStruct(const XrInteractionProfileAnalogThresholdVALVE* value, HandleUnwrapMemory* unwrap_memory);
XrHandJointsMotionRangeInfoEXT* TrackStruct(const XrHandJointsMotionRangeInfoEXT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneObserverCreateInfoMSFT* TrackStruct(const XrSceneObserverCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneCreateInfoMSFT* TrackStruct(const XrSceneCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrNewSceneComputeInfoMSFT* TrackStruct(const XrNewSceneComputeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrVisualMeshComputeLodInfoMSFT* TrackStruct(const XrVisualMeshComputeLodInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneComponentsMSFT* TrackStruct(const XrSceneComponentsMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneComponentsGetInfoMSFT* TrackStruct(const XrSceneComponentsGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneComponentLocationsMSFT* TrackStruct(const XrSceneComponentLocationsMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneComponentsLocateInfoMSFT* TrackStruct(const XrSceneComponentsLocateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneObjectsMSFT* TrackStruct(const XrSceneObjectsMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneComponentParentFilterInfoMSFT* TrackStruct(const XrSceneComponentParentFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneObjectTypesFilterInfoMSFT* TrackStruct(const XrSceneObjectTypesFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrScenePlanesMSFT* TrackStruct(const XrScenePlanesMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrScenePlaneAlignmentFilterInfoMSFT* TrackStruct(const XrScenePlaneAlignmentFilterInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneMeshesMSFT* TrackStruct(const XrSceneMeshesMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneMeshBuffersGetInfoMSFT* TrackStruct(const XrSceneMeshBuffersGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneMeshBuffersMSFT* TrackStruct(const XrSceneMeshBuffersMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneMeshVertexBufferMSFT* TrackStruct(const XrSceneMeshVertexBufferMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneMeshIndicesUint32MSFT* TrackStruct(const XrSceneMeshIndicesUint32MSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneMeshIndicesUint16MSFT* TrackStruct(const XrSceneMeshIndicesUint16MSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSerializedSceneFragmentDataGetInfoMSFT* TrackStruct(const XrSerializedSceneFragmentDataGetInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneDeserializeInfoMSFT* TrackStruct(const XrSceneDeserializeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataDisplayRefreshRateChangedFB* TrackStruct(const XrEventDataDisplayRefreshRateChangedFB* value, HandleUnwrapMemory* unwrap_memory);
XrViveTrackerPathsHTCX* TrackStruct(const XrViveTrackerPathsHTCX* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataViveTrackerConnectedHTCX* TrackStruct(const XrEventDataViveTrackerConnectedHTCX* value, HandleUnwrapMemory* unwrap_memory);
XrSystemFacialTrackingPropertiesHTC* TrackStruct(const XrSystemFacialTrackingPropertiesHTC* value, HandleUnwrapMemory* unwrap_memory);
XrFacialExpressionsHTC* TrackStruct(const XrFacialExpressionsHTC* value, HandleUnwrapMemory* unwrap_memory);
XrFacialTrackerCreateInfoHTC* TrackStruct(const XrFacialTrackerCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory);
XrSystemColorSpacePropertiesFB* TrackStruct(const XrSystemColorSpacePropertiesFB* value, HandleUnwrapMemory* unwrap_memory);
XrHandTrackingMeshFB* TrackStruct(const XrHandTrackingMeshFB* value, HandleUnwrapMemory* unwrap_memory);
XrHandTrackingScaleFB* TrackStruct(const XrHandTrackingScaleFB* value, HandleUnwrapMemory* unwrap_memory);
XrHandTrackingAimStateFB* TrackStruct(const XrHandTrackingAimStateFB* value, HandleUnwrapMemory* unwrap_memory);
XrHandTrackingCapsulesStateFB* TrackStruct(const XrHandTrackingCapsulesStateFB* value, HandleUnwrapMemory* unwrap_memory);
XrSystemSpatialEntityPropertiesFB* TrackStruct(const XrSystemSpatialEntityPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpatialAnchorCreateInfoFB* TrackStruct(const XrSpatialAnchorCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceComponentStatusSetInfoFB* TrackStruct(const XrSpaceComponentStatusSetInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceComponentStatusFB* TrackStruct(const XrSpaceComponentStatusFB* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataSpatialAnchorCreateCompleteFB* TrackStruct(const XrEventDataSpatialAnchorCreateCompleteFB* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataSpaceSetStatusCompleteFB* TrackStruct(const XrEventDataSpaceSetStatusCompleteFB* value, HandleUnwrapMemory* unwrap_memory);
XrFoveationProfileCreateInfoFB* TrackStruct(const XrFoveationProfileCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainCreateInfoFoveationFB* TrackStruct(const XrSwapchainCreateInfoFoveationFB* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainStateFoveationFB* TrackStruct(const XrSwapchainStateFoveationFB* value, HandleUnwrapMemory* unwrap_memory);
XrFoveationLevelProfileCreateInfoFB* TrackStruct(const XrFoveationLevelProfileCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSystemKeyboardTrackingPropertiesFB* TrackStruct(const XrSystemKeyboardTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);
XrKeyboardSpaceCreateInfoFB* TrackStruct(const XrKeyboardSpaceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrKeyboardTrackingQueryFB* TrackStruct(const XrKeyboardTrackingQueryFB* value, HandleUnwrapMemory* unwrap_memory);
XrTriangleMeshCreateInfoFB* TrackStruct(const XrTriangleMeshCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSystemPassthroughPropertiesFB* TrackStruct(const XrSystemPassthroughPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);
XrSystemPassthroughProperties2FB* TrackStruct(const XrSystemPassthroughProperties2FB* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughCreateInfoFB* TrackStruct(const XrPassthroughCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughLayerCreateInfoFB* TrackStruct(const XrPassthroughLayerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerPassthroughFB* TrackStruct(const XrCompositionLayerPassthroughFB* value, HandleUnwrapMemory* unwrap_memory);
XrGeometryInstanceCreateInfoFB* TrackStruct(const XrGeometryInstanceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrGeometryInstanceTransformFB* TrackStruct(const XrGeometryInstanceTransformFB* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughStyleFB* TrackStruct(const XrPassthroughStyleFB* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughColorMapMonoToRgbaFB* TrackStruct(const XrPassthroughColorMapMonoToRgbaFB* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughColorMapMonoToMonoFB* TrackStruct(const XrPassthroughColorMapMonoToMonoFB* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughBrightnessContrastSaturationFB* TrackStruct(const XrPassthroughBrightnessContrastSaturationFB* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataPassthroughStateChangedFB* TrackStruct(const XrEventDataPassthroughStateChangedFB* value, HandleUnwrapMemory* unwrap_memory);
XrRenderModelPathInfoFB* TrackStruct(const XrRenderModelPathInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrRenderModelPropertiesFB* TrackStruct(const XrRenderModelPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);
XrRenderModelBufferFB* TrackStruct(const XrRenderModelBufferFB* value, HandleUnwrapMemory* unwrap_memory);
XrRenderModelLoadInfoFB* TrackStruct(const XrRenderModelLoadInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSystemRenderModelPropertiesFB* TrackStruct(const XrSystemRenderModelPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);
XrRenderModelCapabilitiesRequestFB* TrackStruct(const XrRenderModelCapabilitiesRequestFB* value, HandleUnwrapMemory* unwrap_memory);
XrViewLocateFoveatedRenderingVARJO* TrackStruct(const XrViewLocateFoveatedRenderingVARJO* value, HandleUnwrapMemory* unwrap_memory);
XrFoveatedViewConfigurationViewVARJO* TrackStruct(const XrFoveatedViewConfigurationViewVARJO* value, HandleUnwrapMemory* unwrap_memory);
XrSystemFoveatedRenderingPropertiesVARJO* TrackStruct(const XrSystemFoveatedRenderingPropertiesVARJO* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerDepthTestVARJO* TrackStruct(const XrCompositionLayerDepthTestVARJO* value, HandleUnwrapMemory* unwrap_memory);
XrSystemMarkerTrackingPropertiesVARJO* TrackStruct(const XrSystemMarkerTrackingPropertiesVARJO* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataMarkerTrackingUpdateVARJO* TrackStruct(const XrEventDataMarkerTrackingUpdateVARJO* value, HandleUnwrapMemory* unwrap_memory);
XrMarkerSpaceCreateInfoVARJO* TrackStruct(const XrMarkerSpaceCreateInfoVARJO* value, HandleUnwrapMemory* unwrap_memory);
XrFrameEndInfoML* TrackStruct(const XrFrameEndInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrGlobalDimmerFrameEndInfoML* TrackStruct(const XrGlobalDimmerFrameEndInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrCoordinateSpaceCreateInfoML* TrackStruct(const XrCoordinateSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrSystemMarkerUnderstandingPropertiesML* TrackStruct(const XrSystemMarkerUnderstandingPropertiesML* value, HandleUnwrapMemory* unwrap_memory);
XrMarkerDetectorCreateInfoML* TrackStruct(const XrMarkerDetectorCreateInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrMarkerDetectorArucoInfoML* TrackStruct(const XrMarkerDetectorArucoInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrMarkerDetectorSizeInfoML* TrackStruct(const XrMarkerDetectorSizeInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrMarkerDetectorAprilTagInfoML* TrackStruct(const XrMarkerDetectorAprilTagInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrMarkerDetectorCustomProfileInfoML* TrackStruct(const XrMarkerDetectorCustomProfileInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrMarkerDetectorSnapshotInfoML* TrackStruct(const XrMarkerDetectorSnapshotInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrMarkerDetectorStateML* TrackStruct(const XrMarkerDetectorStateML* value, HandleUnwrapMemory* unwrap_memory);
XrMarkerSpaceCreateInfoML* TrackStruct(const XrMarkerSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrLocalizationMapML* TrackStruct(const XrLocalizationMapML* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataLocalizationChangedML* TrackStruct(const XrEventDataLocalizationChangedML* value, HandleUnwrapMemory* unwrap_memory);
XrLocalizationMapQueryInfoBaseHeaderML* TrackStruct(const XrLocalizationMapQueryInfoBaseHeaderML* value, HandleUnwrapMemory* unwrap_memory);
XrMapLocalizationRequestInfoML* TrackStruct(const XrMapLocalizationRequestInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrLocalizationMapImportInfoML* TrackStruct(const XrLocalizationMapImportInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrLocalizationEnableEventsInfoML* TrackStruct(const XrLocalizationEnableEventsInfoML* value, HandleUnwrapMemory* unwrap_memory);
XrSpatialAnchorPersistenceInfoMSFT* TrackStruct(const XrSpatialAnchorPersistenceInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* TrackStruct(const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneMarkersMSFT* TrackStruct(const XrSceneMarkersMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneMarkerTypeFilterMSFT* TrackStruct(const XrSceneMarkerTypeFilterMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSceneMarkerQRCodesMSFT* TrackStruct(const XrSceneMarkerQRCodesMSFT* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceQueryInfoBaseHeaderFB* TrackStruct(const XrSpaceQueryInfoBaseHeaderFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceFilterInfoBaseHeaderFB* TrackStruct(const XrSpaceFilterInfoBaseHeaderFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceQueryInfoFB* TrackStruct(const XrSpaceQueryInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceStorageLocationFilterInfoFB* TrackStruct(const XrSpaceStorageLocationFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceUuidFilterInfoFB* TrackStruct(const XrSpaceUuidFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceComponentFilterInfoFB* TrackStruct(const XrSpaceComponentFilterInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceQueryResultsFB* TrackStruct(const XrSpaceQueryResultsFB* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataSpaceQueryResultsAvailableFB* TrackStruct(const XrEventDataSpaceQueryResultsAvailableFB* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataSpaceQueryCompleteFB* TrackStruct(const XrEventDataSpaceQueryCompleteFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceSaveInfoFB* TrackStruct(const XrSpaceSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceEraseInfoFB* TrackStruct(const XrSpaceEraseInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataSpaceSaveCompleteFB* TrackStruct(const XrEventDataSpaceSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataSpaceEraseCompleteFB* TrackStruct(const XrEventDataSpaceEraseCompleteFB* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainImageFoveationVulkanFB* TrackStruct(const XrSwapchainImageFoveationVulkanFB* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainStateAndroidSurfaceDimensionsFB* TrackStruct(const XrSwapchainStateAndroidSurfaceDimensionsFB* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainStateSamplerOpenGLESFB* TrackStruct(const XrSwapchainStateSamplerOpenGLESFB* value, HandleUnwrapMemory* unwrap_memory);
XrSwapchainStateSamplerVulkanFB* TrackStruct(const XrSwapchainStateSamplerVulkanFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceShareInfoFB* TrackStruct(const XrSpaceShareInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataSpaceShareCompleteFB* TrackStruct(const XrEventDataSpaceShareCompleteFB* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerSpaceWarpInfoFB* TrackStruct(const XrCompositionLayerSpaceWarpInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSystemSpaceWarpPropertiesFB* TrackStruct(const XrSystemSpaceWarpPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);
XrHapticAmplitudeEnvelopeVibrationFB* TrackStruct(const XrHapticAmplitudeEnvelopeVibrationFB* value, HandleUnwrapMemory* unwrap_memory);
XrSemanticLabelsFB* TrackStruct(const XrSemanticLabelsFB* value, HandleUnwrapMemory* unwrap_memory);
XrRoomLayoutFB* TrackStruct(const XrRoomLayoutFB* value, HandleUnwrapMemory* unwrap_memory);
XrBoundary2DFB* TrackStruct(const XrBoundary2DFB* value, HandleUnwrapMemory* unwrap_memory);
XrSemanticLabelsSupportInfoFB* TrackStruct(const XrSemanticLabelsSupportInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrDigitalLensControlALMALENCE* TrackStruct(const XrDigitalLensControlALMALENCE* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataSceneCaptureCompleteFB* TrackStruct(const XrEventDataSceneCaptureCompleteFB* value, HandleUnwrapMemory* unwrap_memory);
XrSceneCaptureRequestInfoFB* TrackStruct(const XrSceneCaptureRequestInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceContainerFB* TrackStruct(const XrSpaceContainerFB* value, HandleUnwrapMemory* unwrap_memory);
XrFoveationEyeTrackedProfileCreateInfoMETA* TrackStruct(const XrFoveationEyeTrackedProfileCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrFoveationEyeTrackedStateMETA* TrackStruct(const XrFoveationEyeTrackedStateMETA* value, HandleUnwrapMemory* unwrap_memory);
XrSystemFoveationEyeTrackedPropertiesMETA* TrackStruct(const XrSystemFoveationEyeTrackedPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory);
XrSystemFaceTrackingPropertiesFB* TrackStruct(const XrSystemFaceTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);
XrFaceTrackerCreateInfoFB* TrackStruct(const XrFaceTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrFaceExpressionInfoFB* TrackStruct(const XrFaceExpressionInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrFaceExpressionWeightsFB* TrackStruct(const XrFaceExpressionWeightsFB* value, HandleUnwrapMemory* unwrap_memory);
XrEyeTrackerCreateInfoFB* TrackStruct(const XrEyeTrackerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrEyeGazesInfoFB* TrackStruct(const XrEyeGazesInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSystemEyeTrackingPropertiesFB* TrackStruct(const XrSystemEyeTrackingPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);
XrEyeGazesFB* TrackStruct(const XrEyeGazesFB* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughKeyboardHandsIntensityFB* TrackStruct(const XrPassthroughKeyboardHandsIntensityFB* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerSettingsFB* TrackStruct(const XrCompositionLayerSettingsFB* value, HandleUnwrapMemory* unwrap_memory);
XrHapticPcmVibrationFB* TrackStruct(const XrHapticPcmVibrationFB* value, HandleUnwrapMemory* unwrap_memory);
XrDevicePcmSampleRateStateFB* TrackStruct(const XrDevicePcmSampleRateStateFB* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerDepthTestFB* TrackStruct(const XrCompositionLayerDepthTestFB* value, HandleUnwrapMemory* unwrap_memory);
XrLocalDimmingFrameEndInfoMETA* TrackStruct(const XrLocalDimmingFrameEndInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughPreferencesMETA* TrackStruct(const XrPassthroughPreferencesMETA* value, HandleUnwrapMemory* unwrap_memory);
XrSystemVirtualKeyboardPropertiesMETA* TrackStruct(const XrSystemVirtualKeyboardPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory);
XrVirtualKeyboardCreateInfoMETA* TrackStruct(const XrVirtualKeyboardCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrVirtualKeyboardSpaceCreateInfoMETA* TrackStruct(const XrVirtualKeyboardSpaceCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrVirtualKeyboardLocationInfoMETA* TrackStruct(const XrVirtualKeyboardLocationInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrVirtualKeyboardModelVisibilitySetInfoMETA* TrackStruct(const XrVirtualKeyboardModelVisibilitySetInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrVirtualKeyboardAnimationStateMETA* TrackStruct(const XrVirtualKeyboardAnimationStateMETA* value, HandleUnwrapMemory* unwrap_memory);
XrVirtualKeyboardModelAnimationStatesMETA* TrackStruct(const XrVirtualKeyboardModelAnimationStatesMETA* value, HandleUnwrapMemory* unwrap_memory);
XrVirtualKeyboardTextureDataMETA* TrackStruct(const XrVirtualKeyboardTextureDataMETA* value, HandleUnwrapMemory* unwrap_memory);
XrVirtualKeyboardInputInfoMETA* TrackStruct(const XrVirtualKeyboardInputInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrVirtualKeyboardTextContextChangeInfoMETA* TrackStruct(const XrVirtualKeyboardTextContextChangeInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataVirtualKeyboardCommitTextMETA* TrackStruct(const XrEventDataVirtualKeyboardCommitTextMETA* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataVirtualKeyboardBackspaceMETA* TrackStruct(const XrEventDataVirtualKeyboardBackspaceMETA* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataVirtualKeyboardEnterMETA* TrackStruct(const XrEventDataVirtualKeyboardEnterMETA* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataVirtualKeyboardShownMETA* TrackStruct(const XrEventDataVirtualKeyboardShownMETA* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataVirtualKeyboardHiddenMETA* TrackStruct(const XrEventDataVirtualKeyboardHiddenMETA* value, HandleUnwrapMemory* unwrap_memory);
XrExternalCameraOCULUS* TrackStruct(const XrExternalCameraOCULUS* value, HandleUnwrapMemory* unwrap_memory);
XrVulkanSwapchainCreateInfoMETA* TrackStruct(const XrVulkanSwapchainCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrPerformanceMetricsStateMETA* TrackStruct(const XrPerformanceMetricsStateMETA* value, HandleUnwrapMemory* unwrap_memory);
XrPerformanceMetricsCounterMETA* TrackStruct(const XrPerformanceMetricsCounterMETA* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceListSaveInfoFB* TrackStruct(const XrSpaceListSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataSpaceListSaveCompleteFB* TrackStruct(const XrEventDataSpaceListSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceUserCreateInfoFB* TrackStruct(const XrSpaceUserCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);
XrSystemHeadsetIdPropertiesMETA* TrackStruct(const XrSystemHeadsetIdPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory);
XrRecommendedLayerResolutionMETA* TrackStruct(const XrRecommendedLayerResolutionMETA* value, HandleUnwrapMemory* unwrap_memory);
XrRecommendedLayerResolutionGetInfoMETA* TrackStruct(const XrRecommendedLayerResolutionGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughColorLutCreateInfoMETA* TrackStruct(const XrPassthroughColorLutCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughColorLutUpdateInfoMETA* TrackStruct(const XrPassthroughColorLutUpdateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughColorMapLutMETA* TrackStruct(const XrPassthroughColorMapLutMETA* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughColorMapInterpolatedLutMETA* TrackStruct(const XrPassthroughColorMapInterpolatedLutMETA* value, HandleUnwrapMemory* unwrap_memory);
XrSystemPassthroughColorLutPropertiesMETA* TrackStruct(const XrSystemPassthroughColorLutPropertiesMETA* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceTriangleMeshGetInfoMETA* TrackStruct(const XrSpaceTriangleMeshGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory);
XrSpaceTriangleMeshMETA* TrackStruct(const XrSpaceTriangleMeshMETA* value, HandleUnwrapMemory* unwrap_memory);
XrSystemFaceTrackingProperties2FB* TrackStruct(const XrSystemFaceTrackingProperties2FB* value, HandleUnwrapMemory* unwrap_memory);
XrFaceTrackerCreateInfo2FB* TrackStruct(const XrFaceTrackerCreateInfo2FB* value, HandleUnwrapMemory* unwrap_memory);
XrFaceExpressionInfo2FB* TrackStruct(const XrFaceExpressionInfo2FB* value, HandleUnwrapMemory* unwrap_memory);
XrFaceExpressionWeights2FB* TrackStruct(const XrFaceExpressionWeights2FB* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughCreateInfoHTC* TrackStruct(const XrPassthroughCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughColorHTC* TrackStruct(const XrPassthroughColorHTC* value, HandleUnwrapMemory* unwrap_memory);
XrPassthroughMeshTransformInfoHTC* TrackStruct(const XrPassthroughMeshTransformInfoHTC* value, HandleUnwrapMemory* unwrap_memory);
XrCompositionLayerPassthroughHTC* TrackStruct(const XrCompositionLayerPassthroughHTC* value, HandleUnwrapMemory* unwrap_memory);
XrFoveationApplyInfoHTC* TrackStruct(const XrFoveationApplyInfoHTC* value, HandleUnwrapMemory* unwrap_memory);
XrFoveationDynamicModeInfoHTC* TrackStruct(const XrFoveationDynamicModeInfoHTC* value, HandleUnwrapMemory* unwrap_memory);
XrFoveationCustomModeInfoHTC* TrackStruct(const XrFoveationCustomModeInfoHTC* value, HandleUnwrapMemory* unwrap_memory);
XrSystemAnchorPropertiesHTC* TrackStruct(const XrSystemAnchorPropertiesHTC* value, HandleUnwrapMemory* unwrap_memory);
XrSpatialAnchorCreateInfoHTC* TrackStruct(const XrSpatialAnchorCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory);
XrActiveActionSetPrioritiesEXT* TrackStruct(const XrActiveActionSetPrioritiesEXT* value, HandleUnwrapMemory* unwrap_memory);
XrSystemForceFeedbackCurlPropertiesMNDX* TrackStruct(const XrSystemForceFeedbackCurlPropertiesMNDX* value, HandleUnwrapMemory* unwrap_memory);
XrForceFeedbackCurlApplyLocationsMNDX* TrackStruct(const XrForceFeedbackCurlApplyLocationsMNDX* value, HandleUnwrapMemory* unwrap_memory);
XrHandTrackingDataSourceInfoEXT* TrackStruct(const XrHandTrackingDataSourceInfoEXT* value, HandleUnwrapMemory* unwrap_memory);
XrHandTrackingDataSourceStateEXT* TrackStruct(const XrHandTrackingDataSourceStateEXT* value, HandleUnwrapMemory* unwrap_memory);
XrSystemPlaneDetectionPropertiesEXT* TrackStruct(const XrSystemPlaneDetectionPropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);
XrPlaneDetectorCreateInfoEXT* TrackStruct(const XrPlaneDetectorCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);
XrPlaneDetectorBeginInfoEXT* TrackStruct(const XrPlaneDetectorBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);
XrPlaneDetectorGetInfoEXT* TrackStruct(const XrPlaneDetectorGetInfoEXT* value, HandleUnwrapMemory* unwrap_memory);
XrPlaneDetectorLocationEXT* TrackStruct(const XrPlaneDetectorLocationEXT* value, HandleUnwrapMemory* unwrap_memory);
XrPlaneDetectorLocationsEXT* TrackStruct(const XrPlaneDetectorLocationsEXT* value, HandleUnwrapMemory* unwrap_memory);
XrPlaneDetectorPolygonBufferEXT* TrackStruct(const XrPlaneDetectorPolygonBufferEXT* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataUserPresenceChangedEXT* TrackStruct(const XrEventDataUserPresenceChangedEXT* value, HandleUnwrapMemory* unwrap_memory);
XrSystemUserPresencePropertiesEXT* TrackStruct(const XrSystemUserPresencePropertiesEXT* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataHeadsetFitChangedML* TrackStruct(const XrEventDataHeadsetFitChangedML* value, HandleUnwrapMemory* unwrap_memory);
XrEventDataEyeCalibrationChangedML* TrackStruct(const XrEventDataEyeCalibrationChangedML* value, HandleUnwrapMemory* unwrap_memory);
XrUserCalibrationEnableEventsInfoML* TrackStruct(const XrUserCalibrationEnableEventsInfoML* value, HandleUnwrapMemory* unwrap_memory);

void* TrackStruct(const void* value, HandleUnwrapMemory* unwrap_memory);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
