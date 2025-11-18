/*
** Copyright (c) 2021 Samsung
** Copyright (c) 2023 Google
** Copyright (c) 2023 LunarG, Inc.
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
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <iostream>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
std::string GenerateExtension(std::ostream& out, const void* struct_info, void* meta_info, VulkanCppConsumerBase& consumer) {
    std::string next_var_name = "NULL";
    if (struct_info != nullptr && meta_info != nullptr) {
        const VkBaseInStructure* base_struct = reinterpret_cast<const VkBaseInStructure*>(struct_info);
        PNextNode* pnext_meta_data = reinterpret_cast<PNextNode*>(meta_info);
        switch (base_struct->sType) {
            case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkPipelineLayoutCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineLayoutCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineLayoutCreateInfo(out,
                                           casted_struct,
                                           decoded_struct,
                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkShaderModuleCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkShaderModuleCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkShaderModuleCreateInfo(out,
                                         casted_struct,
                                         decoded_struct,
                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO: {
                auto casted_struct = reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkBindBufferMemoryDeviceGroupInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkBindBufferMemoryDeviceGroupInfo(out,
                                                  casted_struct,
                                                  decoded_struct,
                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO: {
                auto casted_struct = reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkBindImageMemoryDeviceGroupInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkBindImageMemoryDeviceGroupInfo(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO: {
                auto casted_struct = reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkBindImagePlaneMemoryInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkBindImagePlaneMemoryInfo(out,
                                           casted_struct,
                                           decoded_struct,
                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO: {
                auto casted_struct = reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceGroupBindSparseInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceGroupBindSparseInfo(out,
                                            casted_struct,
                                            decoded_struct,
                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO: {
                auto casted_struct = reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceGroupCommandBufferBeginInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceGroupCommandBufferBeginInfo(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceGroupDeviceCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceGroupDeviceCreateInfo(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: {
                auto casted_struct = reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceGroupRenderPassBeginInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceGroupRenderPassBeginInfo(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO: {
                auto casted_struct = reinterpret_cast<const VkDeviceGroupSubmitInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceGroupSubmitInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceGroupSubmitInfo(out,
                                        casted_struct,
                                        decoded_struct,
                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkExportFenceCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExportFenceCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExportFenceCreateInfo(out,
                                        casted_struct,
                                        decoded_struct,
                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkExportMemoryAllocateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExportMemoryAllocateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExportMemoryAllocateInfo(out,
                                           casted_struct,
                                           decoded_struct,
                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkExportSemaphoreCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExportSemaphoreCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExportSemaphoreCreateInfo(out,
                                            casted_struct,
                                            decoded_struct,
                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkExternalImageFormatProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExternalImageFormatProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExternalImageFormatProperties(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExternalMemoryBufferCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExternalMemoryBufferCreateInfo(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExternalMemoryImageCreateInfo(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO: {
                auto casted_struct = reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImagePlaneMemoryRequirementsInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImagePlaneMemoryRequirementsInfo(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkImageViewUsageCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageViewUsageCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageViewUsageCreateInfo(out,
                                           casted_struct,
                                           decoded_struct,
                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO: {
                auto casted_struct = reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMemoryAllocateFlagsInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMemoryAllocateFlagsInfo(out,
                                          casted_struct,
                                          decoded_struct,
                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMemoryDedicatedAllocateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMemoryDedicatedAllocateInfo(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS: {
                auto casted_struct = reinterpret_cast<const VkMemoryDedicatedRequirements*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMemoryDedicatedRequirements*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMemoryDedicatedRequirements(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevice16BitStorageFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevice16BitStorageFeatures(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExternalImageFormatInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExternalImageFormatInfo(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFeatures2*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFeatures2*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFeatures2(out,
                                          casted_struct,
                                          decoded_struct,
                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceIDProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceIDProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceIDProperties(out,
                                             casted_struct,
                                             decoded_struct,
                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance3Properties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance3Properties(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMultiviewFeatures(out,
                                                  casted_struct,
                                                  decoded_struct,
                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMultiviewProperties(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePointClippingProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePointClippingProperties(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceProtectedMemoryFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceProtectedMemoryFeatures(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceProtectedMemoryProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceProtectedMemoryProperties(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSamplerYcbcrConversionFeatures(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderDrawParametersFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderDrawParametersFeatures(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSubgroupProperties(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVariablePointersFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVariablePointersFeatures(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineTessellationDomainOriginStateCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineTessellationDomainOriginStateCreateInfo(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO: {
                auto casted_struct = reinterpret_cast<const VkProtectedSubmitInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkProtectedSubmitInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkProtectedSubmitInfo(out,
                                      casted_struct,
                                      decoded_struct,
                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassInputAttachmentAspectCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassInputAttachmentAspectCreateInfo(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassMultiviewCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassMultiviewCreateInfo(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSamplerYcbcrConversionImageFormatProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSamplerYcbcrConversionImageFormatProperties(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO: {
                auto casted_struct = reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSamplerYcbcrConversionInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSamplerYcbcrConversionInfo(out,
                                             casted_struct,
                                             decoded_struct,
                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT: {
                auto casted_struct = reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAttachmentDescriptionStencilLayout*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAttachmentDescriptionStencilLayout(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT: {
                auto casted_struct = reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAttachmentReferenceStencilLayout*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAttachmentReferenceStencilLayout(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkBufferOpaqueCaptureAddressCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkBufferOpaqueCaptureAddressCreateInfo(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDescriptorSetLayoutBindingFlagsCreateInfo(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDescriptorSetVariableDescriptorCountAllocateInfo(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT: {
                auto casted_struct = reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDescriptorSetVariableDescriptorCountLayoutSupport(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkFramebufferAttachmentsCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkFramebufferAttachmentsCreateInfo(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkImageFormatListCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageFormatListCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageFormatListCreateInfo(out,
                                            casted_struct,
                                            decoded_struct,
                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkImageStencilUsageCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageStencilUsageCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageStencilUsageCreateInfo(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMemoryOpaqueCaptureAddressAllocateInfo(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevice8BitStorageFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevice8BitStorageFeatures(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceBufferDeviceAddressFeatures(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDepthStencilResolveProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDepthStencilResolveProperties(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorIndexingFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDescriptorIndexingFeatures(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorIndexingProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDescriptorIndexingProperties(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDriverProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDriverProperties(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFloatControlsProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFloatControlsProperties(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceHostQueryResetFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceHostQueryResetFeatures(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImagelessFramebufferFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImagelessFramebufferFeatures(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSamplerFilterMinmaxProperties(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceScalarBlockLayoutFeatures(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicInt64Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderAtomicInt64Features(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloat16Int8Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderFloat16Int8Features(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTimelineSemaphoreFeatures(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTimelineSemaphoreProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTimelineSemaphoreProperties(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVulkan11Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVulkan11Features(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVulkan11Properties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVulkan11Properties(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVulkan12Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVulkan12Features(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVulkan12Properties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVulkan12Properties(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVulkanMemoryModelFeatures(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO: {
                auto casted_struct = reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassAttachmentBeginInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassAttachmentBeginInfo(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSamplerReductionModeCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSamplerReductionModeCreateInfo(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSemaphoreTypeCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSemaphoreTypeCreateInfo(out,
                                          casted_struct,
                                          decoded_struct,
                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE: {
                auto casted_struct = reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSubpassDescriptionDepthStencilResolve*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSubpassDescriptionDepthStencilResolve(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO: {
                auto casted_struct = reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkTimelineSemaphoreSubmitInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkTimelineSemaphoreSubmitInfo(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO: {
                auto casted_struct = reinterpret_cast<const VkCommandBufferInheritanceRenderingInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkCommandBufferInheritanceRenderingInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkCommandBufferInheritanceRenderingInfo(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDescriptorPoolInlineUniformBlockCreateInfo(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDevicePrivateDataCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDevicePrivateDataCreateInfo(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3: {
                auto casted_struct = reinterpret_cast<const VkFormatProperties3*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkFormatProperties3*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkFormatProperties3(out,
                                    casted_struct,
                                    decoded_struct,
                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2: {
                auto casted_struct = reinterpret_cast<const VkMemoryBarrier2*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMemoryBarrier2*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMemoryBarrier2(out,
                                 casted_struct,
                                 decoded_struct,
                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDynamicRenderingFeatures(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageRobustnessFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageRobustnessFeatures(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceInlineUniformBlockFeatures(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceInlineUniformBlockProperties(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance4Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance4Features(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance4Properties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance4Properties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance4Properties(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePipelineCreationCacheControlFeatures(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePrivateDataFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePrivateDataFeatures(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderIntegerDotProductFeatures(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderIntegerDotProductProperties(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderTerminateInvocationFeatures(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSubgroupSizeControlFeatures(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupSizeControlProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSubgroupSizeControlProperties(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSynchronization2Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSynchronization2Features(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTexelBufferAlignmentProperties(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTextureCompressionASTCHDRFeatures(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVulkan13Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVulkan13Features(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVulkan13Properties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVulkan13Properties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVulkan13Properties(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineCreationFeedbackCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineCreationFeedbackCreateInfo(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkPipelineRenderingCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineRenderingCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineRenderingCreateInfo(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK: {
                auto casted_struct = reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkWriteDescriptorSetInlineUniformBlock*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkWriteDescriptorSetInlineUniformBlock(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS: {
                auto casted_struct = reinterpret_cast<const VkBindMemoryStatus*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkBindMemoryStatus*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkBindMemoryStatus(out,
                                   casted_struct,
                                   decoded_struct,
                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkBufferUsageFlags2CreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkBufferUsageFlags2CreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkBufferUsageFlags2CreateInfo(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceQueueGlobalPriorityCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceQueueGlobalPriorityCreateInfo(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY: {
                auto casted_struct = reinterpret_cast<const VkHostImageCopyDevicePerformanceQuery*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkHostImageCopyDevicePerformanceQuery*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkHostImageCopyDevicePerformanceQuery(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDynamicRenderingLocalReadFeatures(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceGlobalPriorityQueryFeatures(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceHostImageCopyFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceHostImageCopyFeatures(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceHostImageCopyProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceHostImageCopyProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceHostImageCopyProperties(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceIndexTypeUint8Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceIndexTypeUint8Features(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceLineRasterizationFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceLineRasterizationFeatures(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceLineRasterizationProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceLineRasterizationProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceLineRasterizationProperties(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance5Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance5Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance5Features(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance5Properties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance5Properties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance5Properties(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance6Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance6Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance6Features(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance6Properties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance6Properties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance6Properties(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePipelineProtectedAccessFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePipelineProtectedAccessFeatures(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePipelineRobustnessFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePipelineRobustnessFeatures(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePipelineRobustnessProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePipelineRobustnessProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePipelineRobustnessProperties(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePushDescriptorProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePushDescriptorProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePushDescriptorProperties(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderExpectAssumeFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderExpectAssumeFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderExpectAssumeFeatures(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderFloatControls2Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloatControls2Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderFloatControls2Features(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderSubgroupRotateFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupRotateFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderSubgroupRotateFeatures(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeatures*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorFeatures(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorProperties(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVulkan14Features*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVulkan14Features*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVulkan14Features(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVulkan14Properties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVulkan14Properties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVulkan14Properties(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkPipelineCreateFlags2CreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineCreateFlags2CreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineCreateFlags2CreateInfo(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineRasterizationLineStateCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineRasterizationLineStateCreateInfo(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkPipelineRobustnessCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineRobustnessCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineRobustnessCreateInfo(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO: {
                auto casted_struct = reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineVertexInputDivisorStateCreateInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineVertexInputDivisorStateCreateInfo(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES: {
                auto casted_struct = reinterpret_cast<const VkQueueFamilyGlobalPriorityProperties*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkQueueFamilyGlobalPriorityProperties*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkQueueFamilyGlobalPriorityProperties(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO: {
                auto casted_struct = reinterpret_cast<const VkRenderingAttachmentLocationInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderingAttachmentLocationInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderingAttachmentLocationInfo(out,
                                                  casted_struct,
                                                  decoded_struct,
                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO: {
                auto casted_struct = reinterpret_cast<const VkRenderingInputAttachmentIndexInfo*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderingInputAttachmentIndexInfo*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderingInputAttachmentIndexInfo(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE: {
                auto casted_struct = reinterpret_cast<const VkSubresourceHostMemcpySize*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSubresourceHostMemcpySize*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSubresourceHostMemcpySize(out,
                                            casted_struct,
                                            decoded_struct,
                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkBindImageMemorySwapchainInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkBindImageMemorySwapchainInfoKHR(out,
                                                  casted_struct,
                                                  decoded_struct,
                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceGroupPresentInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceGroupPresentInfoKHR(out,
                                            casted_struct,
                                            decoded_struct,
                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceGroupSwapchainCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceGroupSwapchainCreateInfoKHR(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageSwapchainCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageSwapchainCreateInfoKHR(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkDisplayPresentInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDisplayPresentInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDisplayPresentInfoKHR(out,
                                        casted_struct,
                                        decoded_struct,
                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkQueueFamilyQueryResultStatusPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkQueueFamilyQueryResultStatusPropertiesKHR(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkQueueFamilyVideoPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkQueueFamilyVideoPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkQueueFamilyVideoPropertiesKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoProfileInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoProfileInfoKHR(out,
                                      casted_struct,
                                      decoded_struct,
                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoProfileListInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoProfileListInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoProfileListInfoKHR(out,
                                          casted_struct,
                                          decoded_struct,
                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeCapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeCapabilitiesKHR(out,
                                             casted_struct,
                                             decoded_struct,
                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeUsageInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeUsageInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeUsageInfoKHR(out,
                                          casted_struct,
                                          decoded_struct,
                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264CapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264CapabilitiesKHR(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264DpbSlotInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264DpbSlotInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264DpbSlotInfoKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264GopRemainingFrameInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264GopRemainingFrameInfoKHR(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264PictureInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264PictureInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264PictureInfoKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264ProfileInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264ProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264ProfileInfoKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264QualityLevelPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264QualityLevelPropertiesKHR(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264RateControlInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264RateControlInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264RateControlInfoKHR(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264RateControlLayerInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264RateControlLayerInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264RateControlLayerInfoKHR(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264SessionCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264SessionCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264SessionCreateInfoKHR(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264SessionParametersAddInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264SessionParametersAddInfoKHR(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264SessionParametersCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264SessionParametersCreateInfoKHR(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264SessionParametersFeedbackInfoKHR(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264SessionParametersGetInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264SessionParametersGetInfoKHR(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeH264CapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeH264CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeH264CapabilitiesKHR(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeH264DpbSlotInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeH264DpbSlotInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeH264DpbSlotInfoKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeH264PictureInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeH264PictureInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeH264PictureInfoKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeH264ProfileInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeH264ProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeH264ProfileInfoKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeH264SessionParametersAddInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeH264SessionParametersAddInfoKHR(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeH264SessionParametersCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeH264SessionParametersCreateInfoKHR(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExportMemoryWin32HandleInfoKHR(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImportMemoryWin32HandleInfoKHR(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkImportMemoryFdInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImportMemoryFdInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImportMemoryFdInfoKHR(out,
                                        casted_struct,
                                        decoded_struct,
                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkWin32KeyedMutexAcquireReleaseInfoKHR(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkD3D12FenceSubmitInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkD3D12FenceSubmitInfoKHR(out,
                                          casted_struct,
                                          decoded_struct,
                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExportSemaphoreWin32HandleInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExportSemaphoreWin32HandleInfoKHR(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR: {
                auto casted_struct = reinterpret_cast<const VkPresentRegionsKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPresentRegionsKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPresentRegionsKHR(out,
                                    casted_struct,
                                    decoded_struct,
                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSharedPresentSurfaceCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSharedPresentSurfaceCapabilitiesKHR(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExportFenceWin32HandleInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExportFenceWin32HandleInfoKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPerformanceQuerySubmitInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPerformanceQuerySubmitInfoKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePerformanceQueryFeaturesKHR(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePerformanceQueryPropertiesKHR(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkQueryPoolPerformanceCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkQueryPoolPerformanceCreateInfoKHR(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderBfloat16FeaturesKHR(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePortabilitySubsetFeaturesKHR(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePortabilitySubsetPropertiesKHR(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderClockFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderClockFeaturesKHR(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkFragmentShadingRateAttachmentInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkFragmentShadingRateAttachmentInfoKHR(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineFragmentShadingRateStateCreateInfoKHR(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderingFragmentShadingRateAttachmentInfoKHR(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderQuadControlFeaturesKHR(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSurfaceProtectedCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSurfaceProtectedCapabilitiesKHR(out,
                                                  casted_struct,
                                                  decoded_struct,
                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePresentWaitFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePresentWaitFeaturesKHR(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(out,
                                                                        casted_struct,
                                                                        decoded_struct,
                                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineLibraryCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineLibraryCreateInfoKHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePresentIdFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePresentIdFeaturesKHR(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_ID_KHR: {
                auto casted_struct = reinterpret_cast<const VkPresentIdKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPresentIdKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPresentIdKHR(out,
                               casted_struct,
                               decoded_struct,
                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeCapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeCapabilitiesKHR(out,
                                             casted_struct,
                                             decoded_struct,
                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeQualityLevelInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeQualityLevelInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeQualityLevelInfoKHR(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeRateControlInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeRateControlInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeRateControlInfoKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeUsageInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeUsageInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeUsageInfoKHR(out,
                                          casted_struct,
                                          decoded_struct,
                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(out,
                                                                            casted_struct,
                                                                            decoded_struct,
                                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(out,
                                                                         casted_struct,
                                                                         decoded_struct,
                                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePresentId2FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePresentId2FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePresentId2FeaturesKHR(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR: {
                auto casted_struct = reinterpret_cast<const VkPresentId2KHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPresentId2KHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPresentId2KHR(out,
                                casted_struct,
                                decoded_struct,
                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR: {
                auto casted_struct = reinterpret_cast<const VkSurfaceCapabilitiesPresentId2KHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSurfaceCapabilitiesPresentId2KHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSurfaceCapabilitiesPresentId2KHR(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePresentWait2FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePresentWait2FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePresentWait2FeaturesKHR(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR: {
                auto casted_struct = reinterpret_cast<const VkSurfaceCapabilitiesPresentWait2KHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSurfaceCapabilitiesPresentWait2KHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSurfaceCapabilitiesPresentWait2KHR(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR: {
                auto casted_struct = reinterpret_cast<const VkDevicePipelineBinaryInternalCacheControlKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDevicePipelineBinaryInternalCacheControlKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDevicePipelineBinaryInternalCacheControlKHR(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePipelineBinaryFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePipelineBinaryFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePipelineBinaryFeaturesKHR(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePipelineBinaryPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePipelineBinaryPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePipelineBinaryPropertiesKHR(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkPipelineBinaryInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineBinaryInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineBinaryInfoKHR(out,
                                        casted_struct,
                                        decoded_struct,
                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR: {
                auto casted_struct = reinterpret_cast<const VkSurfacePresentModeCompatibilityKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSurfacePresentModeCompatibilityKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSurfacePresentModeCompatibilityKHR(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR: {
                auto casted_struct = reinterpret_cast<const VkSurfacePresentModeKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSurfacePresentModeKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSurfacePresentModeKHR(out,
                                        casted_struct,
                                        decoded_struct,
                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkSurfacePresentScalingCapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSurfacePresentScalingCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSurfacePresentScalingCapabilitiesKHR(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkSwapchainPresentFenceInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSwapchainPresentFenceInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSwapchainPresentFenceInfoKHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkSwapchainPresentModeInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSwapchainPresentModeInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSwapchainPresentModeInfoKHR(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkSwapchainPresentModesCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSwapchainPresentModesCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSwapchainPresentModesCreateInfoKHR(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkSwapchainPresentScalingCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSwapchainPresentScalingCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSwapchainPresentScalingCreateInfoKHR(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeMatrixPropertiesKHR(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeAV1CapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeAV1CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeAV1CapabilitiesKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeAV1DpbSlotInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeAV1DpbSlotInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeAV1DpbSlotInfoKHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeAV1PictureInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeAV1PictureInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeAV1PictureInfoKHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeAV1ProfileInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeAV1ProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeAV1ProfileInfoKHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeAV1SessionParametersCreateInfoKHR(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1CapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1CapabilitiesKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1DpbSlotInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1DpbSlotInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1DpbSlotInfoKHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1GopRemainingFrameInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1GopRemainingFrameInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1GopRemainingFrameInfoKHR(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1PictureInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1PictureInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1PictureInfoKHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1ProfileInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1ProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1ProfileInfoKHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1QualityLevelPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1QualityLevelPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1QualityLevelPropertiesKHR(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1RateControlInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1RateControlInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1RateControlInfoKHR(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1RateControlLayerInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1RateControlLayerInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1RateControlLayerInfoKHR(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1SessionCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1SessionCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1SessionCreateInfoKHR(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1SessionParametersCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1SessionParametersCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1SessionParametersCreateInfoKHR(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeVP9CapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeVP9CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeVP9CapabilitiesKHR(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeVP9PictureInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeVP9PictureInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeVP9PictureInfoKHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoDecodeVP9ProfileInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoDecodeVP9ProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoDecodeVP9ProfileInfoKHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoInlineQueryInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoInlineQueryInfoKHR(out,
                                          casted_struct,
                                          decoded_struct,
                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkAttachmentFeedbackLoopInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAttachmentFeedbackLoopInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAttachmentFeedbackLoopInfoEXT(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeIntraRefreshCapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeIntraRefreshCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeIntraRefreshCapabilitiesKHR(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeIntraRefreshInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeIntraRefreshInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeIntraRefreshInfoKHR(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeSessionIntraRefreshCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeSessionIntraRefreshCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeSessionIntraRefreshCreateInfoKHR(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoReferenceIntraRefreshInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoReferenceIntraRefreshInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoReferenceIntraRefreshInfoKHR(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH264QuantizationMapCapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH264QuantizationMapCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH264QuantizationMapCapabilitiesKHR(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeH265QuantizationMapCapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeH265QuantizationMapCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeH265QuantizationMapCapabilitiesKHR(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeQuantizationMapCapabilitiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeQuantizationMapCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeQuantizationMapCapabilitiesKHR(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeQuantizationMapInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeQuantizationMapInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeQuantizationMapInfoKHR(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR(out,
                                                                           casted_struct,
                                                                           decoded_struct,
                                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoFormatAV1QuantizationMapPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoFormatAV1QuantizationMapPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoFormatAV1QuantizationMapPropertiesKHR(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoFormatH265QuantizationMapPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoFormatH265QuantizationMapPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoFormatH265QuantizationMapPropertiesKHR(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkVideoFormatQuantizationMapPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoFormatQuantizationMapPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoFormatQuantizationMapPropertiesKHR(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(out,
                                                                            casted_struct,
                                                                            decoded_struct,
                                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceLayeredApiPropertiesListKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceLayeredApiPropertiesListKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceLayeredApiPropertiesListKHR(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance7FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance7FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance7FeaturesKHR(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance7PropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance7PropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance7PropertiesKHR(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR: {
                auto casted_struct = reinterpret_cast<const VkMemoryBarrierAccessFlags3KHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMemoryBarrierAccessFlags3KHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMemoryBarrierAccessFlags3KHR(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance8FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance8FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance8FeaturesKHR(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderFmaFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderFmaFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderFmaFeaturesKHR(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance9FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance9FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance9FeaturesKHR(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance9PropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance9PropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance9PropertiesKHR(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkQueueFamilyOwnershipTransferPropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkQueueFamilyOwnershipTransferPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkQueueFamilyOwnershipTransferPropertiesKHR(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRobustness2FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRobustness2FeaturesKHR(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRobustness2PropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRobustness2PropertiesKHR(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance10FeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance10FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance10FeaturesKHR(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMaintenance10PropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance10PropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance10PropertiesKHR(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkRenderingAttachmentFlagsInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderingAttachmentFlagsInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderingAttachmentFlagsInfoKHR(out,
                                                  casted_struct,
                                                  decoded_struct,
                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR: {
                auto casted_struct = reinterpret_cast<const VkResolveImageModeInfoKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkResolveImageModeInfoKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkResolveImageModeInfoKHR(out,
                                          casted_struct,
                                          decoded_struct,
                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDebugReportCallbackCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDebugReportCallbackCreateInfoEXT(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD: {
                auto casted_struct = reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineRasterizationStateRasterizationOrderAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineRasterizationStateRasterizationOrderAMD(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDedicatedAllocationBufferCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDedicatedAllocationBufferCreateInfoNV(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDedicatedAllocationImageCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDedicatedAllocationImageCreateInfoNV(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDedicatedAllocationMemoryAllocateInfoNV(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTransformFeedbackFeaturesEXT(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTransformFeedbackPropertiesEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineRasterizationStateStreamCreateInfoEXT(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD: {
                auto casted_struct = reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkTextureLODGatherFormatPropertiesAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkTextureLODGatherFormatPropertiesAMD(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCornerSampledImageFeaturesNV(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExportMemoryAllocateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExportMemoryAllocateInfoNV(out,
                                             casted_struct,
                                             decoded_struct,
                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExternalMemoryImageCreateInfoNV(out,
                                                  casted_struct,
                                                  decoded_struct,
                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExportMemoryWin32HandleInfoNV(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImportMemoryWin32HandleInfoNV(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkWin32KeyedMutexAcquireReleaseInfoNV(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT: {
                auto casted_struct = reinterpret_cast<const VkValidationFlagsEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkValidationFlagsEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkValidationFlagsEXT(out,
                                     casted_struct,
                                     decoded_struct,
                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT: {
                auto casted_struct = reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageViewASTCDecodeModeEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageViewASTCDecodeModeEXT(out,
                                             casted_struct,
                                             decoded_struct,
                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceASTCDecodeFeaturesEXT(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkCommandBufferInheritanceConditionalRenderingInfoEXT(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceConditionalRenderingFeaturesEXT(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineViewportWScalingStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineViewportWScalingStateCreateInfoNV(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSwapchainCounterCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSwapchainCounterCreateInfoEXT(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE: {
                auto casted_struct = reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPresentTimesInfoGOOGLE*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPresentTimesInfoGOOGLE(out,
                                         casted_struct,
                                         decoded_struct,
                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX: {
                auto casted_struct = reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMultiviewPerViewAttributesInfoNVX*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMultiviewPerViewAttributesInfoNVX(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(out,
                                                                        casted_struct,
                                                                        decoded_struct,
                                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineViewportSwizzleStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineViewportSwizzleStateCreateInfoNV(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDiscardRectanglePropertiesEXT(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineDiscardRectangleStateCreateInfoEXT(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineRasterizationConservativeStateCreateInfoEXT(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDepthClipEnableFeaturesEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineRasterizationDepthClipStateCreateInfoEXT(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDebugUtilsMessengerCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDebugUtilsMessengerCreateInfoEXT(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDebugUtilsObjectNameInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDebugUtilsObjectNameInfoEXT(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID: {
                auto casted_struct = reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAndroidHardwareBufferFormatProperties2ANDROID(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID: {
                auto casted_struct = reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAndroidHardwareBufferFormatPropertiesANDROID(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID: {
                auto casted_struct = reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAndroidHardwareBufferUsageANDROID*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAndroidHardwareBufferUsageANDROID(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID: {
                auto casted_struct = reinterpret_cast<const VkExternalFormatANDROID*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExternalFormatANDROID*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExternalFormatANDROID(out,
                                        casted_struct,
                                        decoded_struct,
                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID: {
                auto casted_struct = reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImportAndroidHardwareBufferInfoANDROID(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD: {
                auto casted_struct = reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAttachmentSampleCountInfoAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAttachmentSampleCountInfoAMD(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSampleLocationsPropertiesEXT(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineSampleLocationsStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineSampleLocationsStateCreateInfoEXT(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassSampleLocationsBeginInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassSampleLocationsBeginInfoEXT(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkSampleLocationsInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSampleLocationsInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSampleLocationsInfoEXT(out,
                                         casted_struct,
                                         decoded_struct,
                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineColorBlendAdvancedStateCreateInfoEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineCoverageToColorStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineCoverageToColorStateCreateInfoNV(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineCoverageModulationStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineCoverageModulationStateCreateInfoNV(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT: {
                auto casted_struct = reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDrmFormatModifierPropertiesList2EXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDrmFormatModifierPropertiesList2EXT(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT: {
                auto casted_struct = reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDrmFormatModifierPropertiesListEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDrmFormatModifierPropertiesListEXT(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageDrmFormatModifierExplicitCreateInfoEXT(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageDrmFormatModifierListCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageDrmFormatModifierListCreateInfoEXT(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkShaderModuleValidationCacheCreateInfoEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShadingRateImageFeaturesNV(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShadingRateImagePropertiesNV(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineViewportShadingRateImageStateCreateInfoNV(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingPropertiesNV(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV: {
                auto casted_struct = reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkWriteDescriptorSetAccelerationStructureNV(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkFilterCubicImageViewImageFormatPropertiesEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageViewImageFormatInfoEXT(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImportMemoryHostPointerInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImportMemoryHostPointerInfoEXT(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD: {
                auto casted_struct = reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineCompilerControlCreateInfoAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineCompilerControlCreateInfoAMD(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderCorePropertiesAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderCorePropertiesAMD(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD: {
                auto casted_struct = reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceMemoryOverallocationCreateInfoAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceMemoryOverallocationCreateInfoAMD(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP: {
                auto casted_struct = reinterpret_cast<const VkPresentFrameTokenGGP*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPresentFrameTokenGGP*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPresentFrameTokenGGP(out,
                                       casted_struct,
                                       decoded_struct,
                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMeshShaderFeaturesNV(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMeshShaderPropertiesNV(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderImageFootprintFeaturesNV(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExclusiveScissorFeaturesNV(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineViewportExclusiveScissorStateCreateInfoNV(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV: {
                auto casted_struct = reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkQueueFamilyCheckpointProperties2NV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkQueueFamilyCheckpointProperties2NV(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkQueueFamilyCheckpointPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkQueueFamilyCheckpointPropertiesNV(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL: {
                auto casted_struct = reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkQueryPoolPerformanceQueryCreateInfoINTEL(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePCIBusInfoPropertiesEXT(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD: {
                auto casted_struct = reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDisplayNativeHdrSurfaceCapabilitiesAMD(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD: {
                auto casted_struct = reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSwapchainDisplayNativeHdrCreateInfoAMD(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassFragmentDensityMapCreateInfoEXT(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderingFragmentDensityMapAttachmentInfoEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreProperties2AMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderCoreProperties2AMD(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCoherentMemoryFeaturesAMD(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMemoryBudgetPropertiesEXT(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMemoryPriorityAllocateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMemoryPriorityAllocateInfoEXT(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMemoryPriorityFeaturesEXT(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(out,
                                                                           casted_struct,
                                                                           decoded_struct,
                                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkBufferDeviceAddressCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkBufferDeviceAddressCreateInfoEXT(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkValidationFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkValidationFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkValidationFeaturesEXT(out,
                                        casted_struct,
                                        decoded_struct,
                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeMatrixFeaturesNV(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeMatrixPropertiesNV(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCoverageReductionModeFeaturesNV(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineCoverageReductionStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineCoverageReductionStateCreateInfoNV(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceProvokingVertexFeaturesEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceProvokingVertexPropertiesEXT(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT(out,
                                                                         casted_struct,
                                                                         decoded_struct,
                                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT: {
                auto casted_struct = reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSurfaceCapabilitiesFullScreenExclusiveEXT(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSurfaceFullScreenExclusiveInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSurfaceFullScreenExclusiveInfoEXT(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSurfaceFullScreenExclusiveWin32InfoEXT(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkMemoryMapPlacedInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMemoryMapPlacedInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMemoryMapPlacedInfoEXT(out,
                                         casted_struct,
                                         decoded_struct,
                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkGraphicsPipelineShaderGroupsCreateInfoNV(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkCommandBufferInheritanceViewportScissorInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkCommandBufferInheritanceViewportScissorInfoNV(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassTransformBeginInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassTransformBeginInfoQCOM(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkDepthBiasRepresentationInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDepthBiasRepresentationInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDepthBiasRepresentationInfoEXT(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDepthBiasControlFeaturesEXT(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceDeviceMemoryReportCreateInfoEXT(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCustomBorderColorFeaturesEXT(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCustomBorderColorPropertiesEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSamplerCustomBorderColorCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSamplerCustomBorderColorCreateInfoEXT(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePresentBarrierFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePresentBarrierFeaturesNV(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV: {
                auto casted_struct = reinterpret_cast<const VkSurfaceCapabilitiesPresentBarrierNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSurfaceCapabilitiesPresentBarrierNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSurfaceCapabilitiesPresentBarrierNV(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkSwapchainPresentBarrierCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSwapchainPresentBarrierCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSwapchainPresentBarrierCreateInfoNV(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceDiagnosticsConfigCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceDiagnosticsConfigCreateInfoNV(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTileShadingFeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTileShadingFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTileShadingFeaturesQCOM(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTileShadingPropertiesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTileShadingPropertiesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTileShadingPropertiesQCOM(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkRenderPassTileShadingCreateInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassTileShadingCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassTileShadingCreateInfoQCOM(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV: {
                auto casted_struct = reinterpret_cast<const VkQueryLowLatencySupportNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkQueryLowLatencySupportNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkQueryLowLatencySupportNV(out,
                                           casted_struct,
                                           decoded_struct,
                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkGraphicsPipelineLibraryCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkGraphicsPipelineLibraryCreateInfoEXT(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(out,
                                                                           casted_struct,
                                                                           decoded_struct,
                                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineFragmentShadingRateEnumStateCreateInfoNV(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV: {
                auto casted_struct = reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAccelerationStructureGeometryMotionTrianglesDataNV(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAccelerationStructureMotionInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAccelerationStructureMotionInfoNV(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkCopyCommandTransformInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkCopyCommandTransformInfoQCOM(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT: {
                auto casted_struct = reinterpret_cast<const VkImageCompressionControlEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageCompressionControlEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageCompressionControlEXT(out,
                                             casted_struct,
                                             decoded_struct,
                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkImageCompressionPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageCompressionPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageCompressionPropertiesEXT(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageCompressionControlFeaturesEXT(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(out,
                                                                        casted_struct,
                                                                        decoded_struct,
                                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevice4444FormatsFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevice4444FormatsFeaturesEXT(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFaultFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFaultFeaturesEXT(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(out,
                                                                              casted_struct,
                                                                              decoded_struct,
                                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkMutableDescriptorTypeCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMutableDescriptorTypeCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMutableDescriptorTypeCreateInfoEXT(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDrmPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDrmPropertiesEXT(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT: {
                auto casted_struct = reinterpret_cast<const VkDeviceAddressBindingCallbackDataEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceAddressBindingCallbackDataEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceAddressBindingCallbackDataEXT(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceAddressBindingReportFeaturesEXT(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDepthClipControlFeaturesEXT(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineViewportDepthClipControlCreateInfoEXT(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(out,
                                                                        casted_struct,
                                                                        decoded_struct,
                                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA: {
                auto casted_struct = reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImportMemoryZirconHandleInfoFUCHSIA*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImportMemoryZirconHandleInfoFUCHSIA(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT: {
                auto casted_struct = reinterpret_cast<const VkFrameBoundaryEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkFrameBoundaryEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkFrameBoundaryEXT(out,
                                   casted_struct,
                                   decoded_struct,
                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFrameBoundaryFeaturesEXT(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkMultisampledRenderToSingleSampledInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMultisampledRenderToSingleSampledInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMultisampledRenderToSingleSampledInfoEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(out,
                                                                             casted_struct,
                                                                             decoded_struct,
                                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT: {
                auto casted_struct = reinterpret_cast<const VkSubpassResolvePerformanceQueryEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSubpassResolvePerformanceQueryEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSubpassResolvePerformanceQueryEXT(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceColorWriteEnableFeaturesEXT(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineColorWriteCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineColorWriteCreateInfoEXT(out,
                                                  casted_struct,
                                                  decoded_struct,
                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeProfileRgbConversionInfoVALVE*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeProfileRgbConversionInfoVALVE*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeProfileRgbConversionInfoVALVE(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeRgbConversionCapabilitiesVALVE*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeRgbConversionCapabilitiesVALVE*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeRgbConversionCapabilitiesVALVE(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE: {
                auto casted_struct = reinterpret_cast<const VkVideoEncodeSessionRgbConversionCreateInfoVALVE*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkVideoEncodeSessionRgbConversionCreateInfoVALVE*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkVideoEncodeSessionRgbConversionCreateInfoVALVE(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageViewMinLodCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageViewMinLodCreateInfoEXT(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageViewMinLodFeaturesEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMultiDrawFeaturesEXT(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMultiDrawPropertiesEXT(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderTileImageFeaturesEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderTileImagePropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderTileImagePropertiesEXT(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT: {
                auto casted_struct = reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAccelerationStructureTrianglesOpacityMicromapEXT(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceOpacityMicromapFeaturesEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceOpacityMicromapPropertiesEXT(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV: {
                auto casted_struct = reinterpret_cast<const VkAccelerationStructureTrianglesDisplacementMicromapNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAccelerationStructureTrianglesDisplacementMicromapNV(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDisplacementMicromapFeaturesNV(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDisplacementMicromapPropertiesNV(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSamplerBorderColorComponentMappingCreateInfoEXT(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderCorePropertiesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderCorePropertiesARM(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM: {
                auto casted_struct = reinterpret_cast<const VkDeviceQueueShaderCoreControlCreateInfoARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDeviceQueueShaderCoreControlCreateInfoARM(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSchedulingControlsFeaturesARM(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSchedulingControlsPropertiesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSchedulingControlsPropertiesARM(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkImageViewSlicedCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageViewSlicedCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageViewSlicedCreateInfoEXT(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRenderPassStripedFeaturesARM(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRenderPassStripedPropertiesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRenderPassStripedPropertiesARM(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM: {
                auto casted_struct = reinterpret_cast<const VkRenderPassStripeBeginInfoARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassStripeBeginInfoARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassStripeBeginInfoARM(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM: {
                auto casted_struct = reinterpret_cast<const VkRenderPassStripeSubmitInfoARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassStripeSubmitInfoARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassStripeSubmitInfoARM(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkRenderPassFragmentDensityMapOffsetEndInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassFragmentDensityMapOffsetEndInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassFragmentDensityMapOffsetEndInfoEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkComputePipelineIndirectBufferInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkComputePipelineIndirectBufferInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkComputePipelineIndirectBufferInfoNV(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(out,
                                                                         casted_struct,
                                                                         decoded_struct,
                                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV: {
                auto casted_struct = reinterpret_cast<const VkAccelerationStructureGeometryLinearSweptSpheresDataNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAccelerationStructureGeometryLinearSweptSpheresDataNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAccelerationStructureGeometryLinearSweptSpheresDataNV(out,
                                                                        casted_struct,
                                                                        decoded_struct,
                                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV: {
                auto casted_struct = reinterpret_cast<const VkAccelerationStructureGeometrySpheresDataNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAccelerationStructureGeometrySpheresDataNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAccelerationStructureGeometrySpheresDataNV(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(out,
                                                                            casted_struct,
                                                                            decoded_struct,
                                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkImageViewSampleWeightCreateInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageViewSampleWeightCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageViewSampleWeightCreateInfoQCOM(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageProcessingFeaturesQCOM(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageProcessingPropertiesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageProcessingPropertiesQCOM(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceNestedCommandBufferPropertiesEXT(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT: {
                auto casted_struct = reinterpret_cast<const VkExternalMemoryAcquireUnmodifiedEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkExternalMemoryAcquireUnmodifiedEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkExternalMemoryAcquireUnmodifiedEXT(out,
                                                     casted_struct,
                                                     decoded_struct,
                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT: {
                auto casted_struct = reinterpret_cast<const VkRenderPassCreationControlEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassCreationControlEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassCreationControlEXT(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassCreationFeedbackCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassCreationFeedbackCreateInfoEXT(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassSubpassFeedbackCreateInfoEXT(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG: {
                auto casted_struct = reinterpret_cast<const VkDirectDriverLoadingListLUNARG*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDirectDriverLoadingListLUNARG*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDirectDriverLoadingListLUNARG(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineShaderStageModuleIdentifierCreateInfoEXT(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkOpticalFlowImageFormatInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkOpticalFlowImageFormatInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkOpticalFlowImageFormatInfoNV(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkOpticalFlowSessionCreatePrivateDataInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkOpticalFlowSessionCreatePrivateDataInfoNV(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceOpticalFlowFeaturesNV(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceOpticalFlowPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceOpticalFlowPropertiesNV(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceLegacyDitheringFeaturesEXT(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID: {
                auto casted_struct = reinterpret_cast<const VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAndroidHardwareBufferFormatResolvePropertiesANDROID(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceAntiLagFeaturesAMD*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceAntiLagFeaturesAMD*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceAntiLagFeaturesAMD(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderObjectFeaturesEXT(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderObjectPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderObjectPropertiesEXT(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTilePropertiesFeaturesQCOM(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC: {
                auto casted_struct = reinterpret_cast<const VkAmigoProfilingSubmitInfoSEC*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkAmigoProfilingSubmitInfoSEC*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkAmigoProfilingSubmitInfoSEC(out,
                                              casted_struct,
                                              decoded_struct,
                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceAmigoProfilingFeaturesSEC(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV(out,
                                                                        casted_struct,
                                                                        decoded_struct,
                                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCooperativeVectorFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeVectorFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeVectorFeaturesNV(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCooperativeVectorPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeVectorPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeVectorPropertiesNV(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkLayerSettingsCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkLayerSettingsCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkLayerSettingsCreateInfoEXT(out,
                                             casted_struct,
                                             decoded_struct,
                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(out,
                                                                             casted_struct,
                                                                             decoded_struct,
                                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV: {
                auto casted_struct = reinterpret_cast<const VkLatencySubmissionPresentIdNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkLatencySubmissionPresentIdNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkLatencySubmissionPresentIdNV(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV: {
                auto casted_struct = reinterpret_cast<const VkLatencySurfaceCapabilitiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkLatencySurfaceCapabilitiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkLatencySurfaceCapabilitiesNV(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkSwapchainLatencyCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSwapchainLatencyCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSwapchainLatencyCreateInfoNV(out,
                                               casted_struct,
                                               decoded_struct,
                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(out,
                                                                        casted_struct,
                                                                        decoded_struct,
                                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePerStageDescriptorSetFeaturesNV(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageProcessing2FeaturesQCOM(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageProcessing2PropertiesQCOM(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkSamplerBlockMatchWindowCreateInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSamplerBlockMatchWindowCreateInfoQCOM(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkBlitImageCubicWeightsInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkBlitImageCubicWeightsInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkBlitImageCubicWeightsInfoQCOM(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCubicWeightsFeaturesQCOM(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkSamplerCubicWeightsCreateInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSamplerCubicWeightsCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSamplerCubicWeightsCreateInfoQCOM(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCubicClampFeaturesQCOM(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(out,
                                                                              casted_struct,
                                                                              decoded_struct,
                                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceLayeredDriverPropertiesMSFT(out,
                                                            casted_struct,
                                                            decoded_struct,
                                                            consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkTileMemoryBindInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkTileMemoryBindInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkTileMemoryBindInfoQCOM(out,
                                         casted_struct,
                                         decoded_struct,
                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM: {
                auto casted_struct = reinterpret_cast<const VkTileMemoryRequirementsQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkTileMemoryRequirementsQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkTileMemoryRequirementsQCOM(out,
                                             casted_struct,
                                             decoded_struct,
                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM: {
                auto casted_struct = reinterpret_cast<const VkTileMemorySizeInfoQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkTileMemorySizeInfoQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkTileMemorySizeInfoQCOM(out,
                                         casted_struct,
                                         decoded_struct,
                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMemoryDecompressionFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMemoryDecompressionFeaturesEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMemoryDecompressionPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMemoryDecompressionPropertiesEXT(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkDisplayModeStereoPropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDisplayModeStereoPropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDisplayModeStereoPropertiesNV(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV: {
                auto casted_struct = reinterpret_cast<const VkDisplaySurfaceStereoCreateInfoNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkDisplaySurfaceStereoCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkDisplaySurfaceStereoCreateInfoNV(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRawAccessChainsFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRawAccessChainsFeaturesNV(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderFloat8FeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloat8FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderFloat8FeaturesEXT(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingValidationFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingValidationFeaturesNV(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV: {
                auto casted_struct = reinterpret_cast<const VkPartitionedAccelerationStructureFlagsNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPartitionedAccelerationStructureFlagsNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPartitionedAccelerationStructureFlagsNV(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(out,
                                                                           casted_struct,
                                                                           decoded_struct,
                                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV(out,
                                                                             casted_struct,
                                                                             decoded_struct,
                                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV: {
                auto casted_struct = reinterpret_cast<const VkWriteDescriptorSetPartitionedAccelerationStructureNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkWriteDescriptorSetPartitionedAccelerationStructureNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkWriteDescriptorSetPartitionedAccelerationStructureNV(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkGeneratedCommandsPipelineInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkGeneratedCommandsPipelineInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkGeneratedCommandsPipelineInfoEXT(out,
                                                   casted_struct,
                                                   decoded_struct,
                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkGeneratedCommandsShaderInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkGeneratedCommandsShaderInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkGeneratedCommandsShaderInfoEXT(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA: {
                auto casted_struct = reinterpret_cast<const VkImageAlignmentControlCreateInfoMESA*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImageAlignmentControlCreateInfoMESA*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImageAlignmentControlCreateInfoMESA(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(out,
                                                                  casted_struct,
                                                                  decoded_struct,
                                                                  consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlPropertiesMESA*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceImageAlignmentControlPropertiesMESA*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceImageAlignmentControlPropertiesMESA(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT(out,
                                                                         casted_struct,
                                                                         decoded_struct,
                                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDepthClampControlFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDepthClampControlFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDepthClampControlFeaturesEXT(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkPipelineViewportDepthClampControlCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineViewportDepthClampControlCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineViewportDepthClampControlCreateInfoEXT(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI: {
                auto casted_struct = reinterpret_cast<const VkHdrVividDynamicMetadataHUAWEI*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkHdrVividDynamicMetadataHUAWEI*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkHdrVividDynamicMetadataHUAWEI(out,
                                                casted_struct,
                                                decoded_struct,
                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceHdrVividFeaturesHUAWEI(out,
                                                       casted_struct,
                                                       decoded_struct,
                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2PropertiesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrix2PropertiesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeMatrix2PropertiesNV(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkImportMemoryMetalHandleInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkImportMemoryMetalHandleInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkImportMemoryMetalHandleInfoEXT(out,
                                                 casted_struct,
                                                 decoded_struct,
                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM(out,
                                                                         casted_struct,
                                                                         decoded_struct,
                                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM: {
                auto casted_struct = reinterpret_cast<const VkRenderPassPerformanceCountersByRegionBeginInfoARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkRenderPassPerformanceCountersByRegionBeginInfoARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkRenderPassPerformanceCountersByRegionBeginInfoARM(out,
                                                                    casted_struct,
                                                                    decoded_struct,
                                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(out,
                                                                     casted_struct,
                                                                     decoded_struct,
                                                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFormatPackFeaturesARM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFormatPackFeaturesARM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFormatPackFeaturesARM(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE(out,
                                                                       casted_struct,
                                                                       decoded_struct,
                                                                       consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE(out,
                                                                         casted_struct,
                                                                         decoded_struct,
                                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE: {
                auto casted_struct = reinterpret_cast<const VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePresentMeteringFeaturesNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePresentMeteringFeaturesNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePresentMeteringFeaturesNV(out,
                                                          casted_struct,
                                                          decoded_struct,
                                                          consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV: {
                auto casted_struct = reinterpret_cast<const VkSetPresentConfigNV*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkSetPresentConfigNV*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkSetPresentConfigNV(out,
                                     casted_struct,
                                     decoded_struct,
                                     consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT(out,
                                                                      casted_struct,
                                                                      decoded_struct,
                                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShader64BitIndexingFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShader64BitIndexingFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShader64BitIndexingFeaturesEXT(out,
                                                               casted_struct,
                                                               decoded_struct,
                                                               consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT: {
                auto casted_struct = reinterpret_cast<const VkCustomResolveCreateInfoEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkCustomResolveCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkCustomResolveCreateInfoEXT(out,
                                             casted_struct,
                                             decoded_struct,
                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceCustomResolveFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceCustomResolveFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceCustomResolveFeaturesEXT(out,
                                                         casted_struct,
                                                         decoded_struct,
                                                         consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceDataGraphModelFeaturesQCOM*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceDataGraphModelFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceDataGraphModelFeaturesQCOM(out,
                                                           casted_struct,
                                                           decoded_struct,
                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC(out,
                                                                        casted_struct,
                                                                        decoded_struct,
                                                                        consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT(out,
                                                                           casted_struct,
                                                                           decoded_struct,
                                                                           consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceAccelerationStructureFeaturesKHR(out,
                                                                 casted_struct,
                                                                 decoded_struct,
                                                                 consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceAccelerationStructurePropertiesKHR(out,
                                                                   casted_struct,
                                                                   decoded_struct,
                                                                   consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR: {
                auto casted_struct = reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkWriteDescriptorSetAccelerationStructureKHR(out,
                                                             casted_struct,
                                                             decoded_struct,
                                                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(out,
                                                              casted_struct,
                                                              decoded_struct,
                                                              consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingPipelinePropertiesKHR(out,
                                                                casted_struct,
                                                                decoded_struct,
                                                                consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceRayQueryFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceRayQueryFeaturesKHR(out,
                                                    casted_struct,
                                                    decoded_struct,
                                                    consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMeshShaderFeaturesEXT(out,
                                                      casted_struct,
                                                      decoded_struct,
                                                      consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT: {
                auto casted_struct = reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesEXT*>(struct_info);
                auto decoded_struct = reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer());
                next_var_name = "&" +  GenerateStruct_VkPhysicalDeviceMeshShaderPropertiesEXT(out,
                                                        casted_struct,
                                                        decoded_struct,
                                                        consumer);

                break;
            }
            default: {
                next_var_name = "NULL";
                break;
            }
        }
    }
    return next_var_name;
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
