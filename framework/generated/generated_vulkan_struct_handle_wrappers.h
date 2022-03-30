/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H

#include "encode/custom_vulkan_struct_handle_wrappers.h"
#include "encode/handle_unwrap_memory.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "format/platform_types.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void UnwrapStructHandles(VkBufferMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMappedMemoryRange* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseMemoryBind* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseBufferMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageOpaqueMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageMemoryBind* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkShaderModuleCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineShaderStageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkComputePipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsPipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyDescriptorSet* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorBufferInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetLayoutBinding* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFramebufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferInheritanceInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindBufferMemoryInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImageMemoryInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryDedicatedAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceGroupProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageSparseMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerYcbcrConversionInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorUpdateTemplateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassAttachmentBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreWaitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreSignalInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferDeviceAddressInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceMemoryOpaqueCaptureAddressInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDependencyInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubmitInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyBufferInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyBufferToImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyImageToBufferInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBlitImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkResolveImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingAttachmentInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceBufferMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceImageMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImageMemorySwapchainInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAcquireNextImageInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayModePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlanePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplaySurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingFragmentDensityMapAttachmentInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportSemaphoreFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFenceGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportFenceFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFenceGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSurfaceInfo2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlaneProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayModeProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlaneInfo2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineExecutableInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineLibraryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugMarkerObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugMarkerObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewHandleInfoNVX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkConditionalRenderingBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugUtilsObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkShaderModuleValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryTrianglesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryAABBNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryDataNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindAccelerationStructureMemoryInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsPipelineShaderGroupsCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsStreamNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsLayoutTokenNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsLayoutCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportSemaphoreZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetRemoteAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetBindingReferenceVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureBuildGeometryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureDeviceAddressInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyAccelerationStructureToMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMemoryToAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

VkBaseInStructure* CopyPNextStruct(const VkBaseInStructure* base, HandleUnwrapMemory* unwrap_memory);

const void* UnwrapPNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory);

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkPhysicalDeviceGroupProperties* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedHandles<ParentWrapper, CoParentWrapper, PhysicalDeviceWrapper>(parent, co_parent, value->physicalDevices, value->physicalDeviceCount, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayPropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedHandle<ParentWrapper, CoParentWrapper, DisplayKHRWrapper>(parent, co_parent, &value->display, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayPlanePropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedHandle<ParentWrapper, CoParentWrapper, DisplayKHRWrapper>(parent, co_parent, &value->currentDisplay, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayModePropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedHandle<ParentWrapper, CoParentWrapper, DisplayModeKHRWrapper>(parent, co_parent, &value->displayMode, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->displayProperties, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayPlaneProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->displayPlaneProperties, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayModeProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->displayModeProperties, get_id);
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
T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));

    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);
    size_t         num_bytes = len * sizeof(T);

    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));
}

template <typename T>
const T* UnwrapStructPtrHandles(const T* value, HandleUnwrapMemory* unwrap_memory)
{
    T* unwrapped_struct = nullptr;

    if (value != nullptr)
    {
        unwrapped_struct = MakeUnwrapStructs(value, 1, unwrap_memory);
        UnwrapStructHandles(unwrapped_struct, unwrap_memory);
    }

    return unwrapped_struct;
}

template <typename T>
const T* UnwrapStructArrayHandles(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
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

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
