/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H

#include "encode/custom_vulkan_struct_handle_wrappers.h"
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

void UnwrapStructHandles(VkSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImageMemorySwapchainInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAcquireNextImageInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayModePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlanePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplaySurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

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

void UnwrapStructHandles(VkDeferredOperationInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineExecutableInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineLibraryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewHandleInfoNVX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkConditionalRenderingBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkShaderModuleValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryTrianglesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryAABBNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryDataNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindAccelerationStructureMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsPipelineShaderGroupsCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsStreamNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsLayoutTokenNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsLayoutCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureMemoryRequirementsInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureDeviceAddressInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkStridedBufferRegionKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyAccelerationStructureToMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMemoryToAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

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
