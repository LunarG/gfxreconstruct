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

#ifdef ENABLE_OPENXR_SUPPORT

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

void MapStructHandles(Decoded_XrSystemProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSessionCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionSpaceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerBaseHeader* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFrameEndInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrViewLocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionSuggestedBinding* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInteractionProfileSuggestedBinding* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSessionActionSetsAttachInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInteractionProfileState* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionStateGetInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActiveActionSet* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActionsSyncInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBoundSourcesForActionEnumerateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInputSourceLocalizedNameGetInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHapticActionInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainSubImage* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerProjectionView* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerProjection* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerQuad* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSessionStateChanged* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataReferenceSpaceChangePending* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataInteractionProfileChanged* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerCubeKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerDepthInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerCylinderKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerEquirectKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLWin32KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLXlibKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLXcbKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLWaylandKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingOpenGLESAndroidKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingVulkanKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageVulkanKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingD3D11KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingD3D12KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVisibilityMaskChangedKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerColorScaleBiasKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVulkanGraphicsDeviceGetInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerEquirect2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSessionCreateInfoOverlayEXTX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorSpaceCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerImageLayoutFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerAlphaBlendFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGraphicsBindingEGLMNDX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialGraphStaticNodeBindingCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHandJointsLocateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSecondaryViewConfigurationLayerInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSecondaryViewConfigurationFrameEndInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrControllerModelKeyStateMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrHolographicWindowAttachmentMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerSecureContentFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrBodyJointsLocateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInteractionProfileDpadBindingEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrInteractionProfileAnalogThresholdVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneBoundsMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrNewSceneComputeInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSceneComponentsLocateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrViveTrackerPathsHTCX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataViveTrackerConnectedHTCX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpatialAnchorCreateCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceSetStatusCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainStateFoveationFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughLayerCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerPassthroughFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGeometryInstanceCreateInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGeometryInstanceTransformFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughStyleFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorMapMonoToRgbaFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorMapMonoToMonoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughBrightnessContrastSaturationFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRenderModelPathInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRenderModelPropertiesFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRenderModelLoadInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFrameEndInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrGlobalDimmerFrameEndInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrMarkerSpaceCreateInfoML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataLocalizationChangedML* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorPersistenceInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceQueryResultFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceQueryResultsFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceQueryResultsAvailableFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceQueryCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceSaveInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceEraseInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceSaveCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceEraseCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSwapchainImageFoveationVulkanFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceShareInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceShareCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerSpaceWarpInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSceneCaptureCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEyeGazesInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerSettingsFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerDepthTestFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrLocalDimmingFrameEndInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardSpaceCreateInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardLocationInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrVirtualKeyboardInputInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardCommitTextMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardBackspaceMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardEnterMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardShownMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataVirtualKeyboardHiddenMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpaceListSaveInfoFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataSpaceListSaveCompleteFB* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrRecommendedLayerResolutionGetInfoMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorMapLutMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughColorMapInterpolatedLutMETA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPassthroughMeshTransformInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrCompositionLayerPassthroughHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrFoveationApplyInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrSpatialAnchorCreateInfoHTC* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActiveActionSetPriorityEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrActiveActionSetPrioritiesEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPlaneDetectorBeginInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrPlaneDetectorGetInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_XrEventDataUserPresenceChangedEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapNextStructHandles(const void* value, void* wrapper, const CommonObjectInfoTable& object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSystemProperties* id_wrapper, const XrSystemProperties* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrInteractionProfileState* id_wrapper, const XrInteractionProfileState* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrControllerModelKeyStateMSFT* id_wrapper, const XrControllerModelKeyStateMSFT* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrViveTrackerPathsHTCX* id_wrapper, const XrViveTrackerPathsHTCX* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrRenderModelPathInfoFB* id_wrapper, const XrRenderModelPathInfoFB* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrRenderModelPropertiesFB* id_wrapper, const XrRenderModelPropertiesFB* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSpaceQueryResultsFB* id_wrapper, const XrSpaceQueryResultsFB* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_XrSpaceQueryResultFB* id_wrapper, const XrSpaceQueryResultFB* handle_struct, CommonObjectInfoTable* object_info_table);

#include "decode/common_struct_handle_mappers.h"
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
