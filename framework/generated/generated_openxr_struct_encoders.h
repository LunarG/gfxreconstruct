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

#ifndef  GFXRECON_GENERATED_OPENXR_STRUCT_ENCODERS_H
#define  GFXRECON_GENERATED_OPENXR_STRUCT_ENCODERS_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "encode/custom_openxr_struct_encoders.h"
#include "encode/parameter_encoder.h"
#include "format/platform_types.h"
#include "util/defines.h"

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

#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodeNextStruct(ParameterEncoder* encoder, const void* value);

void EncodeStruct(ParameterEncoder* encoder, const XrApiLayerProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const XrExtensionProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const XrApplicationInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrInstanceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrInstanceProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataBuffer& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemGetInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemGraphicsProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemTrackingProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSessionCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVector3f& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceVelocity& value);
void EncodeStruct(ParameterEncoder* encoder, const XrQuaternionf& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPosef& value);
void EncodeStruct(ParameterEncoder* encoder, const XrReferenceSpaceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrExtent2Df& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActionSpaceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceLocation& value);
void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationView& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageBaseHeader& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageAcquireInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageWaitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageReleaseInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSessionBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFrameWaitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFrameState& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFrameBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerBaseHeader& value);
void EncodeStruct(ParameterEncoder* encoder, const XrViewLocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrViewState& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFovf& value);
void EncodeStruct(ParameterEncoder* encoder, const XrView& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActionSetCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActionCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActionSuggestedBinding& value);
void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileSuggestedBinding& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSessionActionSetsAttachInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileState& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActionStateGetInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActionStateBoolean& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActionStateFloat& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVector2f& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActionStateVector2f& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActionStatePose& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActiveActionSet& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActionsSyncInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrBoundSourcesForActionEnumerateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrInputSourceLocalizedNameGetInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHapticActionInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHapticBaseHeader& value);
void EncodeStruct(ParameterEncoder* encoder, const XrOffset2Di& value);
void EncodeStruct(ParameterEncoder* encoder, const XrExtent2Di& value);
void EncodeStruct(ParameterEncoder* encoder, const XrRect2Di& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainSubImage& value);
void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerProjectionView& value);
void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerProjection& value);
void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerQuad& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataBaseHeader& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataEventsLost& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataInstanceLossPending& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSessionStateChanged& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataReferenceSpaceChangePending& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataInteractionProfileChanged& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHapticVibration& value);
void EncodeStruct(ParameterEncoder* encoder, const XrOffset2Df& value);
void EncodeStruct(ParameterEncoder* encoder, const XrRect2Df& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVector4f& value);
void EncodeStruct(ParameterEncoder* encoder, const XrColor4f& value);

void EncodeStruct(ParameterEncoder* encoder, const XrApiLayerNextInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrApiLayerCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const XrNegotiateApiLayerRequest& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerCubeKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrInstanceCreateInfoAndroidKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerDepthInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanSwapchainFormatListCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerCylinderKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerEquirectKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLWin32KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLXlibKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLXcbKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLWaylandKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageOpenGLKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsOpenGLKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingOpenGLESAndroidKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageOpenGLESKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsOpenGLESKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingVulkanKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageVulkanKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsVulkanKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingD3D11KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageD3D11KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsD3D11KHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingD3D12KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageD3D12KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsRequirementsD3D12KHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrVisibilityMaskKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVisibilityMaskChangedKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerColorScaleBiasKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrLoaderInitInfoBaseHeaderKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrLoaderInitInfoAndroidKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanGraphicsDeviceGetInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerEquirect2KHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrBindingModificationBaseHeaderKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataPerfSettingsEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsObjectNameInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsLabelEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsMessengerCallbackDataEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrDebugUtilsMessengerCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemEyeGazeInteractionPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazeSampleTimeEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSessionCreateInfoOverlayEXTX& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataMainSessionVisibilityChangedEXTX& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorCreateInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorSpaceCreateInfoMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerImageLayoutFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerAlphaBlendFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationDepthRangeEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrGraphicsBindingEGLMNDX& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphNodeSpaceCreateInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphStaticNodeBindingCreateInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpatialGraphNodeBindingPropertiesMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemHandTrackingPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackerCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandJointsLocateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandJointLocationEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandJointVelocityEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandJointLocationsEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandJointVelocitiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemHandTrackingMeshPropertiesMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshSpaceCreateInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshUpdateInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshIndexBufferMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshVertexMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshVertexBufferMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandMeshMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandPoseTypeInfoMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationSessionBeginInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationStateMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationFrameStateMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationFrameEndInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelKeyStateMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelNodePropertiesMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelPropertiesMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelNodeStateMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrControllerModelStateMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrViewConfigurationViewFovEPIC& value);

void EncodeStruct(ParameterEncoder* encoder, const XrHolographicWindowAttachmentMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerReprojectionInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerReprojectionPlaneOverrideMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrAndroidSurfaceSwapchainCreateInfoFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateBaseHeaderFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerSecureContentFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrBodyJointLocationFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemBodyTrackingPropertiesFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrBodyTrackerCreateInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrBodySkeletonJointFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrBodySkeletonFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrBodyJointsLocateInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrBodyJointLocationsFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileDpadBindingEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrInteractionProfileAnalogThresholdVALVE& value);

void EncodeStruct(ParameterEncoder* encoder, const XrHandJointsMotionRangeInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrUuidMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneObserverCreateInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneCreateInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneSphereBoundMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneOrientedBoxBoundMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneFrustumBoundMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneBoundsMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrNewSceneComputeInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVisualMeshComputeLodInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentsMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentsGetInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentLocationMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentLocationsMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentsLocateInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneObjectMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneObjectsMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneComponentParentFilterInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneObjectTypesFilterInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrScenePlaneMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrScenePlanesMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrScenePlaneAlignmentFilterInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshesMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshBuffersGetInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshBuffersMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshVertexBufferMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshIndicesUint32MSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMeshIndicesUint16MSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSerializedSceneFragmentDataGetInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrDeserializeSceneFragmentMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneDeserializeInfoMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataDisplayRefreshRateChangedFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrViveTrackerPathsHTCX& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataViveTrackerConnectedHTCX& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFacialTrackingPropertiesHTC& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFacialExpressionsHTC& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFacialTrackerCreateInfoHTC& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemColorSpacePropertiesFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrVector4sFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingMeshFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingScaleFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingAimStateFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrHandCapsuleFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingCapsulesStateFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemSpatialEntityPropertiesFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorCreateInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceComponentStatusSetInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceComponentStatusFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrUuidEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpatialAnchorCreateCompleteFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceSetStatusCompleteFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationProfileCreateInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainCreateInfoFoveationFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateFoveationFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationLevelProfileCreateInfoFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemKeyboardTrackingPropertiesFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrKeyboardTrackingDescriptionFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrKeyboardSpaceCreateInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrKeyboardTrackingQueryFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrTriangleMeshCreateInfoFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemPassthroughPropertiesFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemPassthroughProperties2FB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughCreateInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughLayerCreateInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerPassthroughFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrGeometryInstanceCreateInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrGeometryInstanceTransformFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughStyleFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapMonoToRgbaFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapMonoToMonoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughBrightnessContrastSaturationFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataPassthroughStateChangedFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelPathInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelPropertiesFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelBufferFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelLoadInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemRenderModelPropertiesFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrRenderModelCapabilitiesRequestFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrViewLocateFoveatedRenderingVARJO& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFoveatedViewConfigurationViewVARJO& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemFoveatedRenderingPropertiesVARJO& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerDepthTestVARJO& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemMarkerTrackingPropertiesVARJO& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataMarkerTrackingUpdateVARJO& value);
void EncodeStruct(ParameterEncoder* encoder, const XrMarkerSpaceCreateInfoVARJO& value);

void EncodeStruct(ParameterEncoder* encoder, const XrFrameEndInfoML& value);

void EncodeStruct(ParameterEncoder* encoder, const XrGlobalDimmerFrameEndInfoML& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCoordinateSpaceCreateInfoML& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemMarkerUnderstandingPropertiesML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorCreateInfoML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorArucoInfoML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorSizeInfoML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorAprilTagInfoML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorCustomProfileInfoML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorSnapshotInfoML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrMarkerDetectorStateML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrMarkerSpaceCreateInfoML& value);

void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationMapML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataLocalizationChangedML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationMapQueryInfoBaseHeaderML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrMapLocalizationRequestInfoML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationMapImportInfoML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrLocalizationEnableEventsInfoML& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorPersistenceNameMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorPersistenceInfoMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkersMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerTypeFilterMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerQRCodeMSFT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneMarkerQRCodesMSFT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryInfoBaseHeaderFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceFilterInfoBaseHeaderFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceStorageLocationFilterInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceUuidFilterInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceComponentFilterInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryResultFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceQueryResultsFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceQueryResultsAvailableFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceQueryCompleteFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceSaveInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceEraseInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceSaveCompleteFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceEraseCompleteFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainImageFoveationVulkanFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateAndroidSurfaceDimensionsFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateSamplerOpenGLESFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSwapchainStateSamplerVulkanFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceShareInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceShareCompleteFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerSpaceWarpInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemSpaceWarpPropertiesFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrHapticAmplitudeEnvelopeVibrationFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrExtent3DfFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrOffset3DfFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrRect3DfFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSemanticLabelsFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrRoomLayoutFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrBoundary2DFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSemanticLabelsSupportInfoFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrDigitalLensControlALMALENCE& value);

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSceneCaptureCompleteFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSceneCaptureRequestInfoFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceContainerFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationEyeTrackedProfileCreateInfoMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFoveationEyeTrackedStateMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemFoveationEyeTrackedPropertiesMETA& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFaceTrackingPropertiesFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFaceTrackerCreateInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionStatusFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionWeightsFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazeFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEyeTrackerCreateInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazesInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemEyeTrackingPropertiesFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEyeGazesFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughKeyboardHandsIntensityFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerSettingsFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrHapticPcmVibrationFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrDevicePcmSampleRateStateFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerDepthTestFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrLocalDimmingFrameEndInfoMETA& value);

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughPreferencesMETA& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemVirtualKeyboardPropertiesMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardCreateInfoMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardSpaceCreateInfoMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardLocationInfoMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardModelVisibilitySetInfoMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardAnimationStateMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardModelAnimationStatesMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardTextureDataMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardInputInfoMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrVirtualKeyboardTextContextChangeInfoMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardCommitTextMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardBackspaceMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardEnterMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardShownMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataVirtualKeyboardHiddenMETA& value);

void EncodeStruct(ParameterEncoder* encoder, const XrExternalCameraIntrinsicsOCULUS& value);
void EncodeStruct(ParameterEncoder* encoder, const XrExternalCameraExtrinsicsOCULUS& value);
void EncodeStruct(ParameterEncoder* encoder, const XrExternalCameraOCULUS& value);

void EncodeStruct(ParameterEncoder* encoder, const XrVulkanSwapchainCreateInfoMETA& value);

void EncodeStruct(ParameterEncoder* encoder, const XrPerformanceMetricsStateMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPerformanceMetricsCounterMETA& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceListSaveInfoFB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataSpaceListSaveCompleteFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceUserCreateInfoFB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemHeadsetIdPropertiesMETA& value);

void EncodeStruct(ParameterEncoder* encoder, const XrRecommendedLayerResolutionMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrRecommendedLayerResolutionGetInfoMETA& value);

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorLutDataMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorLutCreateInfoMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorLutUpdateInfoMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapLutMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorMapInterpolatedLutMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemPassthroughColorLutPropertiesMETA& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSpaceTriangleMeshGetInfoMETA& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpaceTriangleMeshMETA& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemFaceTrackingProperties2FB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFaceTrackerCreateInfo2FB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionInfo2FB& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFaceExpressionWeights2FB& value);

void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughCreateInfoHTC& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughColorHTC& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPassthroughMeshTransformInfoHTC& value);
void EncodeStruct(ParameterEncoder* encoder, const XrCompositionLayerPassthroughHTC& value);

void EncodeStruct(ParameterEncoder* encoder, const XrFoveationApplyInfoHTC& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFoveationConfigurationHTC& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFoveationDynamicModeInfoHTC& value);
void EncodeStruct(ParameterEncoder* encoder, const XrFoveationCustomModeInfoHTC& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemAnchorPropertiesHTC& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorNameHTC& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSpatialAnchorCreateInfoHTC& value);

void EncodeStruct(ParameterEncoder* encoder, const XrActiveActionSetPriorityEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrActiveActionSetPrioritiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemForceFeedbackCurlPropertiesMNDX& value);
void EncodeStruct(ParameterEncoder* encoder, const XrForceFeedbackCurlApplyLocationMNDX& value);
void EncodeStruct(ParameterEncoder* encoder, const XrForceFeedbackCurlApplyLocationsMNDX& value);

void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingDataSourceInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrHandTrackingDataSourceStateEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrSystemPlaneDetectionPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrExtent3DfEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorBeginInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorGetInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorLocationEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorLocationsEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrPlaneDetectorPolygonBufferEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataUserPresenceChangedEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const XrSystemUserPresencePropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const XrEventDataHeadsetFitChangedML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrEventDataEyeCalibrationChangedML& value);
void EncodeStruct(ParameterEncoder* encoder, const XrUserCalibrationEnableEventsInfoML& value);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_STRUCT_ENCODERS_H
