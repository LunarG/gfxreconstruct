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

#include "generated/generated_openxr_struct_handle_wrappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void UnwrapStructHandles(XrActionSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrCompositionLayerBaseHeader* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = UnwrapNextStructHandles(value->next, unwrap_memory);
        }
    }
}

void UnwrapStructHandles(XrFrameEndInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->layers = UnwrapStructArrayHandles(value->layers, value->layerCount, unwrap_memory);
    }
}

void UnwrapStructHandles(XrViewLocateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrActionSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrInteractionProfileSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->suggestedBindings = UnwrapStructArrayHandles(value->suggestedBindings, value->countSuggestedBindings, unwrap_memory);
    }
}

void UnwrapStructHandles(XrSessionActionSetsAttachInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrActionStateGetInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrActiveActionSet* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrActionsSyncInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->activeActionSets = UnwrapStructArrayHandles(value->activeActionSets, value->countActiveActionSets, unwrap_memory);
    }
}

void UnwrapStructHandles(XrBoundSourcesForActionEnumerateInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrHapticActionInfo* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSwapchainSubImage* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrCompositionLayerProjectionView* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
    }
}

void UnwrapStructHandles(XrCompositionLayerProjection* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->views = UnwrapStructArrayHandles(value->views, value->viewCount, unwrap_memory);
    }
}

void UnwrapStructHandles(XrCompositionLayerQuad* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
    }
}

void UnwrapStructHandles(XrEventDataSessionStateChanged* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataReferenceSpaceChangePending* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataInteractionProfileChanged* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrCompositionLayerCubeKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}
#ifdef XR_USE_PLATFORM_ANDROID
#endif /* XR_USE_PLATFORM_ANDROID */

void UnwrapStructHandles(XrCompositionLayerDepthInfoKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
    }
}
#ifdef XR_USE_GRAPHICS_API_VULKAN
#endif /* XR_USE_GRAPHICS_API_VULKAN */

void UnwrapStructHandles(XrCompositionLayerCylinderKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
    }
}

void UnwrapStructHandles(XrCompositionLayerEquirectKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
    }
}
#ifdef XR_USE_GRAPHICS_API_OPENGL
#endif /* XR_USE_GRAPHICS_API_OPENGL */
#ifdef XR_USE_GRAPHICS_API_OPENGL_ES
#endif /* XR_USE_GRAPHICS_API_OPENGL_ES */
#ifdef XR_USE_GRAPHICS_API_VULKAN
#endif /* XR_USE_GRAPHICS_API_VULKAN */
#ifdef XR_USE_GRAPHICS_API_D3D11
#endif /* XR_USE_GRAPHICS_API_D3D11 */
#ifdef XR_USE_GRAPHICS_API_D3D12
#endif /* XR_USE_GRAPHICS_API_D3D12 */

void UnwrapStructHandles(XrEventDataVisibilityMaskChangedKHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}
#ifdef XR_USE_PLATFORM_ANDROID
#endif /* XR_USE_PLATFORM_ANDROID */
#ifdef XR_USE_GRAPHICS_API_VULKAN
#endif /* XR_USE_GRAPHICS_API_VULKAN */

void UnwrapStructHandles(XrCompositionLayerEquirect2KHR* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->subImage, unwrap_memory);
    }
}

void UnwrapStructHandles(XrSpatialAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSpatialAnchorSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}
#ifdef XR_USE_PLATFORM_EGL
#endif /* XR_USE_PLATFORM_EGL */

void UnwrapStructHandles(XrSpatialGraphStaticNodeBindingCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrHandJointsLocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSecondaryViewConfigurationLayerInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->layers = UnwrapStructArrayHandles(value->layers, value->layerCount, unwrap_memory);
    }
}

void UnwrapStructHandles(XrSecondaryViewConfigurationFrameEndInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->viewConfigurationLayersInfo = UnwrapStructArrayHandles(value->viewConfigurationLayersInfo, value->viewConfigurationCount, unwrap_memory);
    }
}
#ifdef XR_USE_PLATFORM_WIN32
#endif /* XR_USE_PLATFORM_WIN32 */
#ifdef XR_USE_PLATFORM_ANDROID
#endif /* XR_USE_PLATFORM_ANDROID */

void UnwrapStructHandles(XrBodyJointsLocateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrInteractionProfileDpadBindingEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrInteractionProfileAnalogThresholdVALVE* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSceneBoundsMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrNewSceneComputeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->bounds, unwrap_memory);
    }
}

void UnwrapStructHandles(XrSceneComponentsLocateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSpatialAnchorCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataSpatialAnchorCreateCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataSpaceSetStatusCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSwapchainStateFoveationFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrPassthroughLayerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrCompositionLayerPassthroughFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrGeometryInstanceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrGeometryInstanceTransformFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrPassthroughStyleFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = UnwrapNextStructHandles(value->next, unwrap_memory);
        }
    }
}
#ifdef XR_USE_PLATFORM_ML
#endif /* XR_USE_PLATFORM_ML */

void UnwrapStructHandles(XrMarkerSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataLocalizationChangedML* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSpatialAnchorPersistenceInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSpaceQueryResultFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSpaceQueryResultsFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->results = UnwrapStructArrayHandles(value->results, value->resultCapacityInput, unwrap_memory);
    }
}

void UnwrapStructHandles(XrSpaceSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrSpaceEraseInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataSpaceSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataSpaceEraseCompleteFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}
#ifdef XR_USE_GRAPHICS_API_VULKAN
#endif /* XR_USE_GRAPHICS_API_VULKAN */
#ifdef XR_USE_PLATFORM_ANDROID
#endif /* XR_USE_PLATFORM_ANDROID */
#ifdef XR_USE_GRAPHICS_API_OPENGL_ES
#endif /* XR_USE_GRAPHICS_API_OPENGL_ES */
#ifdef XR_USE_GRAPHICS_API_VULKAN
#endif /* XR_USE_GRAPHICS_API_VULKAN */

void UnwrapStructHandles(XrSpaceShareInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrCompositionLayerSpaceWarpInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        UnwrapStructHandles(&value->motionVectorSubImage, unwrap_memory);
        UnwrapStructHandles(&value->depthSubImage, unwrap_memory);
    }
}

void UnwrapStructHandles(XrEyeGazesInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrVirtualKeyboardSpaceCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrVirtualKeyboardLocationInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrVirtualKeyboardInputInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataVirtualKeyboardCommitTextMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataVirtualKeyboardBackspaceMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataVirtualKeyboardEnterMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataVirtualKeyboardShownMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataVirtualKeyboardHiddenMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}
#ifdef XR_USE_GRAPHICS_API_VULKAN
#endif /* XR_USE_GRAPHICS_API_VULKAN */

void UnwrapStructHandles(XrSpaceListSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrRecommendedLayerResolutionGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->layer = UnwrapStructPtrHandles(value->layer, unwrap_memory);
    }
}

void UnwrapStructHandles(XrPassthroughColorMapLutMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrPassthroughColorMapInterpolatedLutMETA* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrPassthroughMeshTransformInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrCompositionLayerPassthroughHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        if (value->next != nullptr)
        {
            value->next = UnwrapNextStructHandles(value->next, unwrap_memory);
        }
    }
}

void UnwrapStructHandles(XrFoveationApplyInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->subImages = UnwrapStructArrayHandles(value->subImages, value->subImageCount, unwrap_memory);
    }
}

void UnwrapStructHandles(XrSpatialAnchorCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrActiveActionSetPriorityEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrActiveActionSetPrioritiesEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        value->actionSetPriorities = UnwrapStructArrayHandles(value->actionSetPriorities, value->actionSetPriorityCount, unwrap_memory);
    }
}

void UnwrapStructHandles(XrPlaneDetectorBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrPlaneDetectorGetInfoEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

void UnwrapStructHandles(XrEventDataUserPresenceChangedEXT* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
    }
}

XrBaseInStructure* CopyNextStruct(const XrBaseInStructure* base, HandleUnwrapMemory* unwrap_memory)
{
    assert(base != nullptr);

    XrBaseInStructure* copy = nullptr;
    switch (base->type)
    {
    default:
        GFXRECON_LOG_WARNING("Failed to copy entire next chain when unwrapping handles due to unrecognized type %d", base->type);
        break;
    case XR_TYPE_SPACE_VELOCITY:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceVelocity*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrInstanceCreateInfoAndroidKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerDepthInfoKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingOpenGLWin32KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingOpenGLXlibKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingOpenGLXcbKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingOpenGLWaylandKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingOpenGLESAndroidKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingVulkanKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingD3D11KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingD3D12KHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerColorScaleBiasKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_BINDING_MODIFICATIONS_KHR:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrBindingModificationsKHR*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrDebugUtilsMessengerCreateInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemEyeGazeInteractionPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrEyeGazeSampleTimeEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSessionCreateInfoOverlayEXTX*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerImageLayoutFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerAlphaBlendFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViewConfigurationDepthRangeEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGraphicsBindingEGLMNDX*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemHandTrackingPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandJointVelocitiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemHandTrackingMeshPropertiesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandPoseTypeInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSecondaryViewConfigurationSessionBeginInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSecondaryViewConfigurationFrameStateMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSecondaryViewConfigurationFrameEndInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSecondaryViewConfigurationSwapchainCreateInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViewConfigurationViewFovEPIC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHolographicWindowAttachmentMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerReprojectionInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerReprojectionPlaneOverrideMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrAndroidSurfaceSwapchainCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerSecureContentFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemBodyTrackingPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandJointsMotionRangeInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVisualMeshComputeLodInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_OBJECTS_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneObjectsMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneComponentParentFilterInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneObjectTypesFilterInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_PLANES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrScenePlanesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrScenePlaneAlignmentFilterInfoMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MESHES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMeshesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemFacialTrackingPropertiesHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemColorSpacePropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_SCALE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingScaleFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingAimStateFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingCapsulesStateFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemSpatialEntityPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainCreateInfoFoveationFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationLevelProfileCreateInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemKeyboardTrackingPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemPassthroughPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemPassthroughProperties2FB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerPassthroughFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorMapMonoToRgbaFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorMapMonoToMonoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughBrightnessContrastSaturationFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemRenderModelPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrRenderModelCapabilitiesRequestFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrViewLocateFoveatedRenderingVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveatedViewConfigurationViewVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemFoveatedRenderingPropertiesVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerDepthTestVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemMarkerTrackingPropertiesVARJO*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FRAME_END_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFrameEndInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrGlobalDimmerFrameEndInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemMarkerUnderstandingPropertiesML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorArucoInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorSizeInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorAprilTagInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrMarkerDetectorCustomProfileInfoML*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MARKERS_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMarkersMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMarkerTypeFilterMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSceneMarkerQRCodesMSFT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSpaceStorageLocationFilterInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSwapchainImageFoveationVulkanFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerSpaceWarpInfoFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemSpaceWarpPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationEyeTrackedProfileCreateInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemFoveationEyeTrackedPropertiesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemFaceTrackingPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemEyeTrackingPropertiesFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerSettingsFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrCompositionLayerDepthTestFB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrLocalDimmingFrameEndInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemVirtualKeyboardPropertiesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrVulkanSwapchainCreateInfoMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemHeadsetIdPropertiesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorMapLutMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughColorMapInterpolatedLutMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemPassthroughColorLutPropertiesMETA*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemFaceTrackingProperties2FB*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrPassthroughMeshTransformInfoHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationDynamicModeInfoHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrFoveationCustomModeInfoHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemAnchorPropertiesHTC*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrActiveActionSetPrioritiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemForceFeedbackCurlPropertiesMNDX*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingDataSourceInfoEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrHandTrackingDataSourceStateEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemPlaneDetectionPropertiesEXT*>(base), 1, unwrap_memory));
        break;
    case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const XrSystemUserPresencePropertiesEXT*>(base), 1, unwrap_memory));
        break;
    }

    return copy;
}

const void* UnwrapNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory)
{
    if (value != nullptr)
    {
        const XrBaseInStructure* base = reinterpret_cast<const XrBaseInStructure*>(value);

        switch (base->type)
        {
        default:
        {
            // This structure does not contain handles, but may point to a structure that does.
            XrBaseInStructure* copy = CopyNextStruct(base, unwrap_memory);
            if (copy != nullptr)
            {
                copy->next = reinterpret_cast<const XrBaseInStructure*>(UnwrapNextStructHandles(base->next, unwrap_memory));
            }
            return copy;
        }
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerDepthInfoKHR*>(base), unwrap_memory);
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrSecondaryViewConfigurationFrameEndInfoMSFT*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerPassthroughFB*>(base), unwrap_memory);
        case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrCompositionLayerSpaceWarpInfoFB*>(base), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrPassthroughColorMapLutMETA*>(base), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrPassthroughColorMapInterpolatedLutMETA*>(base), unwrap_memory);
        case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrPassthroughMeshTransformInfoHTC*>(base), unwrap_memory);
        case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            return UnwrapStructPtrHandles(reinterpret_cast<const XrActiveActionSetPrioritiesEXT*>(base), unwrap_memory);
        }
    }

    return nullptr;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
