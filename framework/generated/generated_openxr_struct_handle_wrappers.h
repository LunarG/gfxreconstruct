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

#include "openxr/openxr.h"
#include "openxr/openxr_loader_negotiation.h"
#include "openxr/openxr_platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void UnwrapOpenXrStructHandles(XrActionSpaceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerBaseHeader* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrViewLocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrActionSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrInteractionProfileSuggestedBinding* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSessionActionSetsAttachInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrActionStateGetInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrActiveActionSet* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrActionsSyncInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrBoundSourcesForActionEnumerateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrHapticActionInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSwapchainSubImage* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerProjectionView* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerProjection* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerQuad* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataSessionStateChanged* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataReferenceSpaceChangePending* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataInteractionProfileChanged* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerCubeKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerDepthInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerCylinderKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerEquirectKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrGraphicsBindingVulkanKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSwapchainImageVulkanKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataVisibilityMaskChangedKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrVulkanGraphicsDeviceGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerEquirect2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpatialAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpatialAnchorSpaceCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpatialGraphStaticNodeBindingCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrHandJointsLocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSecondaryViewConfigurationFrameEndInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrBodyJointsLocateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrInteractionProfileDpadBindingEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrInteractionProfileAnalogThresholdVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSceneBoundsMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrNewSceneComputeInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSceneComponentsLocateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpatialAnchorCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataSpatialAnchorCreateCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataSpaceSetStatusCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSwapchainStateFoveationFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrPassthroughLayerCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerPassthroughFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrGeometryInstanceCreateInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrGeometryInstanceTransformFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrPassthroughStyleFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrMarkerSpaceCreateInfoML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataLocalizationChangedML* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpatialAnchorPersistenceInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpaceQueryResultFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpaceQueryResultsFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpaceSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpaceEraseInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataSpaceSaveCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataSpaceEraseCompleteFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSwapchainImageFoveationVulkanFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpaceShareInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerSpaceWarpInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEyeGazesInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrVirtualKeyboardSpaceCreateInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrVirtualKeyboardLocationInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrVirtualKeyboardInputInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataVirtualKeyboardCommitTextMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataVirtualKeyboardBackspaceMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataVirtualKeyboardEnterMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataVirtualKeyboardShownMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataVirtualKeyboardHiddenMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpaceListSaveInfoFB* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrRecommendedLayerResolutionGetInfoMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrPassthroughColorMapLutMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrPassthroughColorMapInterpolatedLutMETA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrPassthroughMeshTransformInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrCompositionLayerPassthroughHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrFoveationApplyInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrSpatialAnchorCreateInfoHTC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrActiveActionSetPriorityEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrActiveActionSetPrioritiesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrPlaneDetectorBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrPlaneDetectorGetInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapOpenXrStructHandles(XrEventDataUserPresenceChangedEXT* value, HandleUnwrapMemory* unwrap_memory);

XrBaseInStructure* CopyNextStruct(const XrBaseInStructure* base, HandleUnwrapMemory* unwrap_memory);

const void* UnwrapNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory);

template <typename OpenXrParentWrapper, typename OpenXrCoParentWrapper, typename T>
void CreateWrappedOpenXrStructArrayHandles(typename OpenXrParentWrapper::HandleType parent, typename OpenXrCoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id);

template <typename T>
T* MakeUnwrapOpenXrStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));

    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);
    size_t         num_bytes = len * sizeof(T);

    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));
}

template <typename T>
T* UnwrapOpenXrStructPtrHandles(const T* value, HandleUnwrapMemory* unwrap_memory)
{
    T* unwrapped_struct = nullptr;

    if (value != nullptr)
    {
        unwrapped_struct = MakeUnwrapOpenXrStructs(value, 1, unwrap_memory);
        UnwrapOpenXrStructHandles(unwrapped_struct, unwrap_memory);
    }

    return unwrapped_struct;
}

template <typename OpenXrParentWrapper, typename OpenXrCoParentWrapper>
void CreateWrappedOpenXrStructHandles(typename OpenXrParentWrapper::HandleType parent, typename OpenXrCoParentWrapper::HandleType co_parent, XrSpaceQueryResultsFB* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedOpenXrStructArrayHandles<OpenXrParentWrapper, OpenXrCoParentWrapper, XrSpaceQueryResultFB>(parent, co_parent, value->results, value->resultCapacityInput, get_id);
    }
}

template <typename OpenXrParentWrapper, typename OpenXrCoParentWrapper>
void CreateWrappedOpenXrStructHandles(typename OpenXrParentWrapper::HandleType parent, typename OpenXrCoParentWrapper::HandleType co_parent, XrSpaceQueryResultFB* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedOpenXrHandle<OpenXrParentWrapper, OpenXrCoParentWrapper, openxr_wrappers::SpaceWrapper>(parent, co_parent, &value->space, get_id);
    }
}

template <typename OpenXrParentWrapper, typename OpenXrCoParentWrapper, typename T>
void CreateWrappedOpenXrStructArrayHandles(typename OpenXrParentWrapper::HandleType parent, typename OpenXrCoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            CreateWrappedOpenXrStructHandles<OpenXrParentWrapper, OpenXrCoParentWrapper>(parent, co_parent, &value[i], get_id);
        }
    }
}

template <typename T>
T* UnwrapOpenXrStructArrayHandles(T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((values != nullptr) && (len > 0))
    {
        auto unwrapped_structs = MakeUnwrapOpenXrStructs(values, len, unwrap_memory);

        for (size_t i = 0; i < len; ++i)
        {
            UnwrapOpenXrStructHandles(&unwrapped_structs[i], unwrap_memory);
        }

        return unwrapped_structs;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return values;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif //  GFXRECON_GENERATED_OPENXR_STRUCT_HANDLE_WRAPPERS_H
