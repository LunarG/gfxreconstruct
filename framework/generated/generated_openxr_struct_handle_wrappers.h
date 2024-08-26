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

#ifndef  GFXRECON_GENERATED_OPENXR_STRUCT_HANDLE_WRAPPERS_H
#define  GFXRECON_GENERATED_OPENXR_STRUCT_HANDLE_WRAPPERS_H

#ifdef ENABLE_OPENXR_SUPPORT

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

void UnwrapStructHandles(XrSystemProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSessionCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerBaseHeader* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFrameEndInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrViewLocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInteractionProfileSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSessionActionSetsAttachInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInteractionProfileState* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionStateGetInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActiveActionSet* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActionsSyncInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrBoundSourcesForActionEnumerateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInputSourceLocalizedNameGetInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHapticActionInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainSubImage* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerProjectionView* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerProjection* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerQuad* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSessionStateChanged* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataReferenceSpaceChangePending* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataInteractionProfileChanged* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerCubeKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerDepthInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerCylinderKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerEquirectKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingOpenGLWin32KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingOpenGLXlibKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingOpenGLXcbKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingOpenGLWaylandKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingOpenGLESAndroidKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingVulkanKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageVulkanKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingD3D11KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingD3D12KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVisibilityMaskChangedKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerColorScaleBiasKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVulkanGraphicsDeviceGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerEquirect2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSessionCreateInfoOverlayEXTX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerImageLayoutFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerAlphaBlendFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGraphicsBindingEGLMNDX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialGraphStaticNodeBindingCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHandJointsLocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSecondaryViewConfigurationLayerInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSecondaryViewConfigurationFrameEndInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrControllerModelKeyStateMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrHolographicWindowAttachmentMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerSecureContentFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrBodyJointsLocateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInteractionProfileDpadBindingEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrInteractionProfileAnalogThresholdVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneBoundsMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrNewSceneComputeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSceneComponentsLocateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrViveTrackerPathsHTCX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataViveTrackerConnectedHTCX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpatialAnchorCreateCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceSetStatusCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainStateFoveationFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughLayerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerPassthroughFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGeometryInstanceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGeometryInstanceTransformFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughStyleFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorMapMonoToRgbaFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorMapMonoToMonoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughBrightnessContrastSaturationFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRenderModelPathInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRenderModelPropertiesFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRenderModelLoadInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFrameEndInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrGlobalDimmerFrameEndInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrMarkerSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataLocalizationChangedML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorPersistenceInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceQueryResultFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceQueryResultsFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceQueryResultsAvailableFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceQueryCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceEraseInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceEraseCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSwapchainImageFoveationVulkanFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceShareInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceShareCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerSpaceWarpInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSceneCaptureCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEyeGazesInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerSettingsFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerDepthTestFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrLocalDimmingFrameEndInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardSpaceCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardLocationInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrVirtualKeyboardInputInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVirtualKeyboardCommitTextMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVirtualKeyboardBackspaceMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVirtualKeyboardEnterMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVirtualKeyboardShownMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataVirtualKeyboardHiddenMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpaceListSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataSpaceListSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrRecommendedLayerResolutionGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorMapLutMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughColorMapInterpolatedLutMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPassthroughMeshTransformInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrCompositionLayerPassthroughHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrFoveationApplyInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrSpatialAnchorCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActiveActionSetPriorityEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrActiveActionSetPrioritiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPlaneDetectorBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrPlaneDetectorGetInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(XrEventDataUserPresenceChangedEXT* value, HandleUnwrapMemory* unwrap_memory);

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
        CreateWrappedAtom<ParentWrapper, openxr_wrappers::SystemIdWrapper>(parent, &value->systemId, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrSystemGraphicsProperties* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrSystemTrackingProperties* value, PFN_GetHandleId get_id)
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
        CreateWrappedAtom<ParentWrapper, openxr_wrappers::PathWrapper>(parent, &value->interactionProfile, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrControllerModelKeyStateMSFT* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedAtom<ParentWrapper, openxr_wrappers::ControllerModelKeyMSFTWrapper>(parent, &value->modelKey, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrViveTrackerPathsHTCX* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedAtom<ParentWrapper, openxr_wrappers::PathWrapper>(parent, &value->persistentPath, get_id);
        CreateWrappedAtom<ParentWrapper, openxr_wrappers::PathWrapper>(parent, &value->rolePath, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrRenderModelPathInfoFB* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedAtom<ParentWrapper, openxr_wrappers::PathWrapper>(parent, &value->path, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrRenderModelPropertiesFB* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedAtom<ParentWrapper, openxr_wrappers::RenderModelKeyFBWrapper>(parent, &value->modelKey, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrSpaceQueryResultsFB* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedStructArrayHandles<ParentWrapper, CoParentWrapper, XrSpaceQueryResultFB>(parent, co_parent, value->results, value->resultCapacityInput, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, XrSpaceQueryResultFB* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedHandle<ParentWrapper, CoParentWrapper, openxr_wrappers::SpaceWrapper>(parent, co_parent, &value->space, get_id);
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

#endif //  GFXRECON_GENERATED_OPENXR_STRUCT_HANDLE_WRAPPERS_H
