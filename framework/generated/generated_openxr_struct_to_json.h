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

#ifndef  GFXRECON_GENERATED_OPENXR_STRUCT_TO_JSON_H
#define  GFXRECON_GENERATED_OPENXR_STRUCT_TO_JSON_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "decode/custom_openxr_struct_to_json.h"


#include "format/platform_types.h"

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerProperties* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtensionProperties* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApplicationInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceCreateInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceProperties* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataBuffer* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemGetInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemGraphicsProperties* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemTrackingProperties* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemProperties* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionCreateInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector3f* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceVelocity* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrQuaternionf* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPosef* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrReferenceSpaceCreateInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent2Df* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSpaceCreateInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceLocation* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationProperties* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationView* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainCreateInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageBaseHeader* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageAcquireInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageWaitInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageReleaseInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionBeginInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameWaitInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameState* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameBeginInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerBaseHeader* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewLocateInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewState* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFovf* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrView* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSetCreateInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionCreateInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionSuggestedBinding* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileSuggestedBinding* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionActionSetsAttachInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileState* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateGetInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateBoolean* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateFloat* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector2f* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStateVector2f* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionStatePose* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSet* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActionsSyncInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoundSourcesForActionEnumerateInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInputSourceLocalizedNameGetInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticActionInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticBaseHeader* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset2Di* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent2Di* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect2Di* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainSubImage* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerProjectionView* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerProjection* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerQuad* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataBaseHeader* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataEventsLost* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataInstanceLossPending* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSessionStateChanged* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataReferenceSpaceChangePending* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataInteractionProfileChanged* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticVibration* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset2Df* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect2Df* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector4f* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrColor4f* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerNextInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrApiLayerCreateInfo* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrNegotiateApiLayerRequest* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerCubeKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInstanceCreateInfoAndroidKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthInfoKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanSwapchainFormatListCreateInfoKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerCylinderKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerEquirectKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLWin32KHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLXlibKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLXcbKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLWaylandKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageOpenGLKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsOpenGLKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingOpenGLESAndroidKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageOpenGLESKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsOpenGLESKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingVulkanKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageVulkanKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsVulkanKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingD3D11KHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageD3D11KHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsD3D11KHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingD3D12KHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageD3D12KHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsRequirementsD3D12KHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVisibilityMaskKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVisibilityMaskChangedKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerColorScaleBiasKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLoaderInitInfoBaseHeaderKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLoaderInitInfoAndroidKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanGraphicsDeviceGetInfoKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerEquirect2KHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBindingModificationBaseHeaderKHR* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataPerfSettingsEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsObjectNameInfoEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsLabelEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsMessengerCallbackDataEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDebugUtilsMessengerCreateInfoEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEyeGazeInteractionPropertiesEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazeSampleTimeEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSessionCreateInfoOverlayEXTX* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataMainSessionVisibilityChangedEXTX* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerImageLayoutFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerAlphaBlendFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationDepthRangeEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGraphicsBindingEGLMNDX* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeSpaceCreateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeBindingPropertiesGetInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialGraphNodeBindingPropertiesMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHandTrackingPropertiesEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackerCreateInfoEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointsLocateInfoEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointLocationEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointVelocityEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointLocationsEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointVelocitiesEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHandTrackingMeshPropertiesMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshSpaceCreateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshUpdateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshIndexBufferMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshVertexMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshVertexBufferMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandMeshMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandPoseTypeInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationSessionBeginInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationStateMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationFrameStateMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelKeyStateMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelNodePropertiesMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelPropertiesMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelNodeStateMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrControllerModelStateMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewConfigurationViewFovEPIC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHolographicWindowAttachmentMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerReprojectionInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerReprojectionPlaneOverrideMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrAndroidSurfaceSwapchainCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateBaseHeaderFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSecureContentFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointLocationFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemBodyTrackingPropertiesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyTrackerCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodySkeletonJointFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodySkeletonFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointsLocateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBodyJointLocationsFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileDpadBindingEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrInteractionProfileAnalogThresholdVALVE* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandJointsMotionRangeInfoEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUuidMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObserverCreateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneCreateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneSphereBoundMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneOrientedBoxBoundMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneFrustumBoundMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneBoundsMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrNewSceneComputeInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVisualMeshComputeLodInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsGetInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentLocationMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentLocationsMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentsLocateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectsMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneComponentParentFilterInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneObjectTypesFilterInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlaneMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlanesMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrScenePlaneAlignmentFilterInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshesMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshBuffersGetInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshBuffersMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshVertexBufferMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshIndicesUint32MSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMeshIndicesUint16MSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSerializedSceneFragmentDataGetInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDeserializeSceneFragmentMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneDeserializeInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataDisplayRefreshRateChangedFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViveTrackerPathsHTCX* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataViveTrackerConnectedHTCX* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFacialTrackingPropertiesHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFacialExpressionsHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFacialTrackerCreateInfoHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemColorSpacePropertiesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVector4sFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingMeshFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingScaleFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingAimStateFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandCapsuleFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingCapsulesStateFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemSpatialEntityPropertiesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentStatusSetInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentStatusFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUuidEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpatialAnchorCreateCompleteFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceSetStatusCompleteFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationProfileCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainCreateInfoFoveationFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateFoveationFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationLevelProfileCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemKeyboardTrackingPropertiesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardTrackingDescriptionFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardSpaceCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrKeyboardTrackingQueryFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrTriangleMeshCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughPropertiesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughProperties2FB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughLayerCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerPassthroughFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGeometryInstanceCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGeometryInstanceTransformFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughStyleFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapMonoToRgbaFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapMonoToMonoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughBrightnessContrastSaturationFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataPassthroughStateChangedFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelPathInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelPropertiesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelBufferFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelLoadInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemRenderModelPropertiesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRenderModelCapabilitiesRequestFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrViewLocateFoveatedRenderingVARJO* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveatedViewConfigurationViewVARJO* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFoveatedRenderingPropertiesVARJO* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthTestVARJO* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemMarkerTrackingPropertiesVARJO* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataMarkerTrackingUpdateVARJO* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerSpaceCreateInfoVARJO* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFrameEndInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrGlobalDimmerFrameEndInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCoordinateSpaceCreateInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemMarkerUnderstandingPropertiesML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorCreateInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorArucoInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorSizeInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorAprilTagInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorCustomProfileInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorSnapshotInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerDetectorStateML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMarkerSpaceCreateInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataLocalizationChangedML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapQueryInfoBaseHeaderML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrMapLocalizationRequestInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationMapImportInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalizationEnableEventsInfoML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorPersistenceNameMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorPersistenceInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkersMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerTypeFilterMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerQRCodeMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneMarkerQRCodesMSFT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryInfoBaseHeaderFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceFilterInfoBaseHeaderFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceStorageLocationFilterInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceUuidFilterInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceComponentFilterInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryResultFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceQueryResultsFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceQueryResultsAvailableFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceQueryCompleteFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceSaveInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceEraseInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceSaveCompleteFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceEraseCompleteFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainImageFoveationVulkanFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateAndroidSurfaceDimensionsFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateSamplerOpenGLESFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSwapchainStateSamplerVulkanFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceShareInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceShareCompleteFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSpaceWarpInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemSpaceWarpPropertiesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticAmplitudeEnvelopeVibrationFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent3DfFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrOffset3DfFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRect3DfFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSemanticLabelsFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRoomLayoutFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrBoundary2DFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSemanticLabelsSupportInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDigitalLensControlALMALENCE* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSceneCaptureCompleteFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSceneCaptureRequestInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceContainerFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationEyeTrackedProfileCreateInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationEyeTrackedStateMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFoveationEyeTrackedPropertiesMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFaceTrackingPropertiesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceTrackerCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionStatusFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionWeightsFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazeFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeTrackerCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazesInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemEyeTrackingPropertiesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEyeGazesFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughKeyboardHandsIntensityFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerSettingsFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHapticPcmVibrationFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrDevicePcmSampleRateStateFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerDepthTestFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrLocalDimmingFrameEndInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughPreferencesMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemVirtualKeyboardPropertiesMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardCreateInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardLocationInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardModelVisibilitySetInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardAnimationStateMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardModelAnimationStatesMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardTextureDataMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardInputInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVirtualKeyboardTextContextChangeInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardCommitTextMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardBackspaceMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardEnterMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardShownMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataVirtualKeyboardHiddenMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraIntrinsicsOCULUS* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraExtrinsicsOCULUS* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExternalCameraOCULUS* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrVulkanSwapchainCreateInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPerformanceMetricsStateMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPerformanceMetricsCounterMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceListSaveInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataSpaceListSaveCompleteFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceUserCreateInfoFB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemHeadsetIdPropertiesMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRecommendedLayerResolutionMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrRecommendedLayerResolutionGetInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutDataMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutCreateInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorLutUpdateInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapLutMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorMapInterpolatedLutMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPassthroughColorLutPropertiesMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceTriangleMeshGetInfoMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpaceTriangleMeshMETA* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemFaceTrackingProperties2FB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceTrackerCreateInfo2FB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionInfo2FB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFaceExpressionWeights2FB* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughCreateInfoHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughColorHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPassthroughMeshTransformInfoHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrCompositionLayerPassthroughHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationApplyInfoHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationConfigurationHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationDynamicModeInfoHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrFoveationCustomModeInfoHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemAnchorPropertiesHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorNameHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSpatialAnchorCreateInfoHTC* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSetPriorityEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrActiveActionSetPrioritiesEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemForceFeedbackCurlPropertiesMNDX* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrForceFeedbackCurlApplyLocationMNDX* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrForceFeedbackCurlApplyLocationsMNDX* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingDataSourceInfoEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrHandTrackingDataSourceStateEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemPlaneDetectionPropertiesEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorCreateInfoEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrExtent3DfEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorBeginInfoEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorGetInfoEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorLocationEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorLocationsEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrPlaneDetectorPolygonBufferEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataUserPresenceChangedEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrSystemUserPresencePropertiesEXT* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataHeadsetFitChangedML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrEventDataEyeCalibrationChangedML* data, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_XrUserCalibrationEnableEventsInfoML* data, const util::JsonOptions& options = util::JsonOptions());

/// Works out the type of the struct at the end of a next pointer and dispatches
/// recursively to the FieldToJson for that.
void FieldToJson(nlohmann::ordered_json& jdata, const OpenXrNextNode* data, const util::JsonOptions& options = util::JsonOptions());

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_STRUCT_TO_JSON_H
