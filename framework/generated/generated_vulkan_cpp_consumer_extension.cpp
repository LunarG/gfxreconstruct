/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "generated/generated_vulkan_cpp_consumer.h"
#include "generated/generated_vulkan_cpp_structs.h"
#include "decode/vulkan_cpp_structs.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"

#include <iostream>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

std::string GenerateExtension(std::ostream& out, const void* structInfo, void* metaInfo, VulkanCppConsumerBase& consumer) {
    std::string pNextName = "NULL";
    if (structInfo != nullptr && metaInfo != nullptr) {
        const VkBaseInStructure* baseStruct = reinterpret_cast<const VkBaseInStructure*>(structInfo);
        switch (baseStruct->sType) {
            case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkSwapchainCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSwapchainCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkSwapchainCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkPresentInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPresentInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPresentInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageSwapchainCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkImageSwapchainCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkBindImageMemorySwapchainInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkBindImageMemorySwapchainInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkAcquireNextImageInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAcquireNextImageInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkAcquireNextImageInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkDeviceGroupPresentCapabilitiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceGroupPresentCapabilitiesKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkDeviceGroupPresentCapabilitiesKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceGroupPresentInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkDeviceGroupPresentInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceGroupSwapchainCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkDeviceGroupSwapchainCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkXcbSurfaceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkXcbSurfaceCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkXcbSurfaceCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkWaylandSurfaceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkWaylandSurfaceCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkWaylandSurfaceCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkAndroidSurfaceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAndroidSurfaceCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkAndroidSurfaceCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO: {
                auto castedStruct = reinterpret_cast<const VkRenderPassMultiviewCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderPassMultiviewCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkRenderPassMultiviewCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMultiviewFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewFeaturesKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMultiviewFeaturesKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMultiviewPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPropertiesKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMultiviewPropertiesKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFeatures2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFeatures2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFeatures2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceProperties2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceProperties2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceProperties2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2: {
                auto castedStruct = reinterpret_cast<const VkFormatProperties2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkFormatProperties2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkFormatProperties2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2: {
                auto castedStruct = reinterpret_cast<const VkImageFormatProperties2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageFormatProperties2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkImageFormatProperties2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageFormatInfo2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageFormatInfo2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2: {
                auto castedStruct = reinterpret_cast<const VkQueueFamilyProperties2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkQueueFamilyProperties2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkQueueFamilyProperties2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMemoryProperties2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMemoryProperties2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMemoryProperties2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2: {
                auto castedStruct = reinterpret_cast<const VkSparseImageFormatProperties2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSparseImageFormatProperties2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkSparseImageFormatProperties2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceSparseImageFormatInfo2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO: {
                auto castedStruct = reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDescriptorUpdateTemplateCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkDescriptorUpdateTemplateCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2: {
                auto castedStruct = reinterpret_cast<const VkRenderPassCreateInfo2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderPassCreateInfo2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkRenderPassCreateInfo2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2: {
                auto castedStruct = reinterpret_cast<const VkAttachmentDescription2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAttachmentDescription2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkAttachmentDescription2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2: {
                auto castedStruct = reinterpret_cast<const VkAttachmentReference2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAttachmentReference2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkAttachmentReference2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2: {
                auto castedStruct = reinterpret_cast<const VkSubpassDescription2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSubpassDescription2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkSubpassDescription2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2: {
                auto castedStruct = reinterpret_cast<const VkSubpassDependency2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSubpassDependency2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkSubpassDependency2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO: {
                auto castedStruct = reinterpret_cast<const VkSubpassBeginInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSubpassBeginInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkSubpassBeginInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_END_INFO: {
                auto castedStruct = reinterpret_cast<const VkSubpassEndInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSubpassEndInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkSubpassEndInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePointClippingPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePointClippingPropertiesKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePointClippingPropertiesKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO: {
                auto castedStruct = reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderPassInputAttachmentAspectCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkRenderPassInputAttachmentAspectCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO: {
                auto castedStruct = reinterpret_cast<const VkImageViewUsageCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageViewUsageCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkImageViewUsageCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO: {
                auto castedStruct = reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineTessellationDomainOriginStateCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPipelineTessellationDomainOriginStateCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2: {
                auto castedStruct = reinterpret_cast<const VkBufferMemoryRequirementsInfo2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkBufferMemoryRequirementsInfo2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkBufferMemoryRequirementsInfo2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2: {
                auto castedStruct = reinterpret_cast<const VkImageMemoryRequirementsInfo2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageMemoryRequirementsInfo2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkImageMemoryRequirementsInfo2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2: {
                auto castedStruct = reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageSparseMemoryRequirementsInfo2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkImageSparseMemoryRequirementsInfo2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2: {
                auto castedStruct = reinterpret_cast<const VkMemoryRequirements2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryRequirements2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkMemoryRequirements2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2: {
                auto castedStruct = reinterpret_cast<const VkSparseImageMemoryRequirements2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSparseImageMemoryRequirements2KHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkSparseImageMemoryRequirements2KHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO: {
                auto castedStruct = reinterpret_cast<const VkImageFormatListCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageFormatListCreateInfoKHR*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkImageFormatListCreateInfoKHR(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceInlineUniformBlockFeaturesEXT(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceInlineUniformBlockPropertiesEXT(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK: {
                auto castedStruct = reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlockEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkWriteDescriptorSetInlineUniformBlockEXT*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkWriteDescriptorSetInlineUniformBlockEXT(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO: {
                auto castedStruct = reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkDescriptorPoolInlineUniformBlockCreateInfoEXT(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMemoryBudgetPropertiesEXT(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO: {
                auto castedStruct = reinterpret_cast<const VkImageStencilUsageCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageStencilUsageCreateInfoEXT*>(metaInfo);
                pNextName = "&" +  GenerateStruct_VkImageStencilUsageCreateInfoEXT(out,
                            castedStruct,
                            castedMetaInfo,
                            consumer);

                break;
            }
            default: {
                pNextName = "NULL";
                break;
            }
        }
    }
    return pNextName;
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
