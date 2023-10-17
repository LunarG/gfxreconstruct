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

std::string GenerateExtension(std::ostream& out, const void* structInfo, void* metaInfo, VulkanCppConsumerBase& consumer) {
    std::string pNextName = "NULL";
    if (structInfo != nullptr && metaInfo != nullptr) {
        const VkBaseInStructure* baseStruct = reinterpret_cast<const VkBaseInStructure*>(structInfo);
        PNextNode* metaInfoPNext = reinterpret_cast<PNextNode*>(metaInfo);
        switch (baseStruct->sType) {
            case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkAcquireNextImageInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAcquireNextImageInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAcquireNextImageInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkBindImageMemorySwapchainInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkBindImageMemorySwapchainInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkDeviceGroupPresentCapabilitiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceGroupPresentCapabilitiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceGroupPresentCapabilitiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceGroupPresentInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceGroupPresentInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceGroupSwapchainCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceGroupSwapchainCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageSwapchainCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageSwapchainCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkPresentInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPresentInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPresentInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkSwapchainCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSwapchainCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSwapchainCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkDisplayModeCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplayModeCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplayModeCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplaySurfaceCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplaySurfaceCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkDisplayPresentInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplayPresentInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplayPresentInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkXlibSurfaceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkXlibSurfaceCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkXlibSurfaceCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkXcbSurfaceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkXcbSurfaceCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkXcbSurfaceCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkWaylandSurfaceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkWaylandSurfaceCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkWaylandSurfaceCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkAndroidSurfaceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAndroidSurfaceCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAndroidSurfaceCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkWin32SurfaceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkWin32SurfaceCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkWin32SurfaceCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkBindVideoSessionMemoryInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkBindVideoSessionMemoryInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkBindVideoSessionMemoryInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceVideoFormatInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceVideoFormatInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceVideoFormatInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkQueueFamilyQueryResultStatusPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkQueueFamilyQueryResultStatusPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkQueueFamilyVideoPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkQueueFamilyVideoPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkQueueFamilyVideoPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoBeginCodingInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoBeginCodingInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoBeginCodingInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoCapabilitiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoCapabilitiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoCapabilitiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoCodingControlInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoCodingControlInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoCodingControlInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoEndCodingInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEndCodingInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEndCodingInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoFormatPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoFormatPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoFormatPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoPictureResourceInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoPictureResourceInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoPictureResourceInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoProfileInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoProfileInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoProfileInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoProfileListInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoProfileListInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoProfileListInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoReferenceSlotInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoReferenceSlotInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoReferenceSlotInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoSessionCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoSessionCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoSessionCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoSessionMemoryRequirementsKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoSessionMemoryRequirementsKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoSessionMemoryRequirementsKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoSessionParametersCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoSessionParametersCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoSessionParametersCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoSessionParametersUpdateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoSessionParametersUpdateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoSessionParametersUpdateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeCapabilitiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeCapabilitiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeCapabilitiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeUsageInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeUsageInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeUsageInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH264CapabilitiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH264CapabilitiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH264CapabilitiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH264DpbSlotInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH264DpbSlotInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH264DpbSlotInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH264PictureInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH264PictureInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH264PictureInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH264ProfileInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH264ProfileInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH264ProfileInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH264SessionParametersAddInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH264SessionParametersAddInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH264SessionParametersCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH264SessionParametersCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD: {
                auto castedStruct = reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAttachmentSampleCountInfoAMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAttachmentSampleCountInfoAMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX: {
                auto castedStruct = reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMultiviewPerViewAttributesInfoNVX*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMultiviewPerViewAttributesInfoNVX(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRenderingFragmentDensityMapAttachmentInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRenderingFragmentShadingRateAttachmentInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkExportMemoryWin32HandleInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportMemoryWin32HandleInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkMemoryGetWin32HandleInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryGetWin32HandleInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryGetWin32HandleInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkMemoryWin32HandlePropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryWin32HandlePropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryWin32HandlePropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkImportMemoryFdInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportMemoryFdInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportMemoryFdInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkMemoryFdPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryFdPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryFdPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkMemoryGetFdInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryGetFdInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryGetFdInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkWin32KeyedMutexAcquireReleaseInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkD3D12FenceSubmitInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkD3D12FenceSubmitInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkExportSemaphoreWin32HandleInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkExportSemaphoreWin32HandleInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkImportSemaphoreWin32HandleInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportSemaphoreWin32HandleInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportSemaphoreWin32HandleInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkSemaphoreGetWin32HandleInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSemaphoreGetWin32HandleInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSemaphoreGetWin32HandleInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkImportSemaphoreFdInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportSemaphoreFdInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportSemaphoreFdInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkSemaphoreGetFdInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSemaphoreGetFdInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSemaphoreGetFdInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePushDescriptorPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR: {
                auto castedStruct = reinterpret_cast<const VkPresentRegionsKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPresentRegionsKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPresentRegionsKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSharedPresentSurfaceCapabilitiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSharedPresentSurfaceCapabilitiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkExportFenceWin32HandleInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkExportFenceWin32HandleInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkFenceGetWin32HandleInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkFenceGetWin32HandleInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkFenceGetWin32HandleInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkImportFenceWin32HandleInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportFenceWin32HandleInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportFenceWin32HandleInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkFenceGetFdInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkFenceGetFdInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkFenceGetFdInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkImportFenceFdInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportFenceFdInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportFenceFdInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkAcquireProfilingLockInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAcquireProfilingLockInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAcquireProfilingLockInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR: {
                auto castedStruct = reinterpret_cast<const VkPerformanceCounterDescriptionKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPerformanceCounterDescriptionKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPerformanceCounterDescriptionKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR: {
                auto castedStruct = reinterpret_cast<const VkPerformanceCounterKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPerformanceCounterKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPerformanceCounterKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPerformanceQuerySubmitInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPerformanceQuerySubmitInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePerformanceQueryFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePerformanceQueryPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkQueryPoolPerformanceCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkQueryPoolPerformanceCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceSurfaceInfo2KHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR: {
                auto castedStruct = reinterpret_cast<const VkSurfaceCapabilities2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfaceCapabilities2KHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfaceCapabilities2KHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR: {
                auto castedStruct = reinterpret_cast<const VkSurfaceFormat2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfaceFormat2KHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfaceFormat2KHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR: {
                auto castedStruct = reinterpret_cast<const VkDisplayModeProperties2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplayModeProperties2KHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplayModeProperties2KHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR: {
                auto castedStruct = reinterpret_cast<const VkDisplayPlaneCapabilities2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplayPlaneCapabilities2KHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplayPlaneCapabilities2KHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR: {
                auto castedStruct = reinterpret_cast<const VkDisplayPlaneInfo2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplayPlaneInfo2KHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplayPlaneInfo2KHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR: {
                auto castedStruct = reinterpret_cast<const VkDisplayPlaneProperties2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplayPlaneProperties2KHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplayPlaneProperties2KHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR: {
                auto castedStruct = reinterpret_cast<const VkDisplayProperties2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplayProperties2KHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplayProperties2KHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePortabilitySubsetFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePortabilitySubsetPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderClockFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderClockFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH265CapabilitiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH265CapabilitiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH265CapabilitiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH265DpbSlotInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH265DpbSlotInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH265DpbSlotInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH265PictureInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH265PictureInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH265PictureInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH265ProfileInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH265ProfileInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH265ProfileInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH265SessionParametersAddInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH265SessionParametersAddInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH265SessionParametersAddInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoDecodeH265SessionParametersCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoDecodeH265SessionParametersCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoDecodeH265SessionParametersCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceQueueGlobalPriorityCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkQueueFamilyGlobalPriorityPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkQueueFamilyGlobalPriorityPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkFragmentShadingRateAttachmentInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkFragmentShadingRateAttachmentInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShadingRateKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineFragmentShadingRateStateCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfaceProtectedCapabilitiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfaceProtectedCapabilitiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePresentWaitFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePresentWaitFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkPipelineExecutableInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineExecutableInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineExecutableInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR: {
                auto castedStruct = reinterpret_cast<const VkPipelineExecutableInternalRepresentationKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineExecutableInternalRepresentationKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineExecutableInternalRepresentationKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPipelineExecutablePropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineExecutablePropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineExecutablePropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR: {
                auto castedStruct = reinterpret_cast<const VkPipelineExecutableStatisticKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineExecutableStatisticKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineExecutableStatisticKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkPipelineInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkMemoryMapInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryMapInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryMapInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkMemoryUnmapInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryUnmapInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryUnmapInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineLibraryCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineLibraryCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePresentIdFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePresentIdFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_ID_KHR: {
                auto castedStruct = reinterpret_cast<const VkPresentIdKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPresentIdKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPresentIdKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeCapabilitiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeCapabilitiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeCapabilitiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeQualityLevelInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeQualityLevelInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeQualityLevelInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeQualityLevelPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeQualityLevelPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeQualityLevelPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeRateControlInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeRateControlInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeRateControlInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeRateControlLayerInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeRateControlLayerInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeRateControlLayerInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeSessionParametersFeedbackInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeSessionParametersFeedbackInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeSessionParametersGetInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeSessionParametersGetInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeSessionParametersGetInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeUsageInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeUsageInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeUsageInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV: {
                auto castedStruct = reinterpret_cast<const VkCheckpointData2NV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCheckpointData2NV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCheckpointData2NV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV: {
                auto castedStruct = reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkQueueFamilyCheckpointProperties2NV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkQueueFamilyCheckpointProperties2NV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkBufferUsageFlags2CreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkBufferUsageFlags2CreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkBufferUsageFlags2CreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkDeviceImageSubresourceInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceImageSubresourceInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceImageSubresourceInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR: {
                auto castedStruct = reinterpret_cast<const VkImageSubresource2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageSubresource2KHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageSubresource2KHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMaintenance5FeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance5FeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance5FeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMaintenance5PropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance5PropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMaintenance5PropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkPipelineCreateFlags2CreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineCreateFlags2CreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineCreateFlags2CreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkRenderingAreaInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderingAreaInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRenderingAreaInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR: {
                auto castedStruct = reinterpret_cast<const VkSubresourceLayout2KHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSubresourceLayout2KHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSubresourceLayout2KHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkCooperativeMatrixPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCooperativeMatrixPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCooperativeMatrixPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeMatrixPropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDebugReportCallbackCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDebugReportCallbackCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD: {
                auto castedStruct = reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineRasterizationStateRasterizationOrderAMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineRasterizationStateRasterizationOrderAMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDebugMarkerMarkerInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDebugMarkerMarkerInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDebugMarkerObjectNameInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDebugMarkerObjectNameInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDebugMarkerObjectNameInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDebugMarkerObjectTagInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDebugMarkerObjectTagInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDebugMarkerObjectTagInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDedicatedAllocationBufferCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDedicatedAllocationBufferCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDedicatedAllocationImageCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDedicatedAllocationImageCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDedicatedAllocationMemoryAllocateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceTransformFeedbackFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceTransformFeedbackPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineRasterizationStateStreamCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX: {
                auto castedStruct = reinterpret_cast<const VkImageViewAddressPropertiesNVX*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageViewAddressPropertiesNVX*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageViewAddressPropertiesNVX(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX: {
                auto castedStruct = reinterpret_cast<const VkImageViewHandleInfoNVX*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageViewHandleInfoNVX*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageViewHandleInfoNVX(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264CapabilitiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264CapabilitiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264CapabilitiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264DpbSlotInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264DpbSlotInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264DpbSlotInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264GopRemainingFrameInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264GopRemainingFrameInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264GopRemainingFrameInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264NaluSliceInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264NaluSliceInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264NaluSliceInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264PictureInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264PictureInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264PictureInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264ProfileInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264ProfileInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264ProfileInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264QualityLevelPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264QualityLevelPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264QualityLevelPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264RateControlInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264RateControlInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264RateControlInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264RateControlLayerInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264RateControlLayerInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264RateControlLayerInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264SessionCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264SessionCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264SessionCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264SessionParametersAddInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersAddInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264SessionParametersAddInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264SessionParametersCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264SessionParametersCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264SessionParametersFeedbackInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264SessionParametersFeedbackInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH264SessionParametersGetInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersGetInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH264SessionParametersGetInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265CapabilitiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265CapabilitiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265CapabilitiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265DpbSlotInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265DpbSlotInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265DpbSlotInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265GopRemainingFrameInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265GopRemainingFrameInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265GopRemainingFrameInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265NaluSliceSegmentInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265NaluSliceSegmentInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265NaluSliceSegmentInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265PictureInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265PictureInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265PictureInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265ProfileInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265ProfileInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265ProfileInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265QualityLevelPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265QualityLevelPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265QualityLevelPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265RateControlInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265RateControlInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265RateControlInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265RateControlLayerInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265RateControlLayerInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265RateControlLayerInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265SessionCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265SessionCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265SessionCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265SessionParametersAddInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265SessionParametersAddInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265SessionParametersAddInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265SessionParametersCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265SessionParametersCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265SessionParametersCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265SessionParametersFeedbackInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265SessionParametersFeedbackInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265SessionParametersFeedbackInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkVideoEncodeH265SessionParametersGetInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVideoEncodeH265SessionParametersGetInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVideoEncodeH265SessionParametersGetInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD: {
                auto castedStruct = reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkTextureLODGatherFormatPropertiesAMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkTextureLODGatherFormatPropertiesAMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP: {
                auto castedStruct = reinterpret_cast<const VkStreamDescriptorSurfaceCreateInfoGGP*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkStreamDescriptorSurfaceCreateInfoGGP(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCornerSampledImageFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkExportMemoryAllocateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkExportMemoryAllocateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkExternalMemoryImageCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkExportMemoryWin32HandleInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportMemoryWin32HandleInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkWin32KeyedMutexAcquireReleaseInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT: {
                auto castedStruct = reinterpret_cast<const VkValidationFlagsEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkValidationFlagsEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkValidationFlagsEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN: {
                auto castedStruct = reinterpret_cast<const VkViSurfaceCreateInfoNN*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkViSurfaceCreateInfoNN*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkViSurfaceCreateInfoNN(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT: {
                auto castedStruct = reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageViewASTCDecodeModeEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageViewASTCDecodeModeEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceASTCDecodeFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePipelineRobustnessFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePipelineRobustnessPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePipelineRobustnessPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePipelineRobustnessPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineRobustnessCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineRobustnessCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineRobustnessCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCommandBufferInheritanceConditionalRenderingInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkConditionalRenderingBeginInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkConditionalRenderingBeginInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkConditionalRenderingBeginInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceConditionalRenderingFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineViewportWScalingStateCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineViewportWScalingStateCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT: {
                auto castedStruct = reinterpret_cast<const VkSurfaceCapabilities2EXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfaceCapabilities2EXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfaceCapabilities2EXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDeviceEventInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceEventInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceEventInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDisplayEventInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplayEventInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplayEventInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDisplayPowerInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplayPowerInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplayPowerInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSwapchainCounterCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSwapchainCounterCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE: {
                auto castedStruct = reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPresentTimesInfoGOOGLE*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPresentTimesInfoGOOGLE(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineViewportSwizzleStateCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineViewportSwizzleStateCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDiscardRectanglePropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineDiscardRectangleStateCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineRasterizationConservativeStateCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDepthClipEnableFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineRasterizationDepthClipStateCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_HDR_METADATA_EXT: {
                auto castedStruct = reinterpret_cast<const VkHdrMetadataEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkHdrMetadataEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkHdrMetadataEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK: {
                auto castedStruct = reinterpret_cast<const VkIOSSurfaceCreateInfoMVK*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkIOSSurfaceCreateInfoMVK*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkIOSSurfaceCreateInfoMVK(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK: {
                auto castedStruct = reinterpret_cast<const VkMacOSSurfaceCreateInfoMVK*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMacOSSurfaceCreateInfoMVK*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMacOSSurfaceCreateInfoMVK(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT: {
                auto castedStruct = reinterpret_cast<const VkDebugUtilsLabelEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDebugUtilsLabelEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDebugUtilsLabelEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT: {
                auto castedStruct = reinterpret_cast<const VkDebugUtilsMessengerCallbackDataEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDebugUtilsMessengerCallbackDataEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDebugUtilsMessengerCallbackDataEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDebugUtilsMessengerCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDebugUtilsMessengerCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDebugUtilsObjectNameInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDebugUtilsObjectNameInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDebugUtilsObjectTagInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDebugUtilsObjectTagInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDebugUtilsObjectTagInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID: {
                auto castedStruct = reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAndroidHardwareBufferFormatProperties2ANDROID(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID: {
                auto castedStruct = reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAndroidHardwareBufferFormatPropertiesANDROID(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID: {
                auto castedStruct = reinterpret_cast<const VkAndroidHardwareBufferPropertiesANDROID*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAndroidHardwareBufferPropertiesANDROID*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAndroidHardwareBufferPropertiesANDROID(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID: {
                auto castedStruct = reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAndroidHardwareBufferUsageANDROID*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAndroidHardwareBufferUsageANDROID(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID: {
                auto castedStruct = reinterpret_cast<const VkExternalFormatANDROID*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkExternalFormatANDROID*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkExternalFormatANDROID(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID: {
                auto castedStruct = reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportAndroidHardwareBufferInfoANDROID(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID: {
                auto castedStruct = reinterpret_cast<const VkMemoryGetAndroidHardwareBufferInfoANDROID*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryGetAndroidHardwareBufferInfoANDROID(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkMultisamplePropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMultisamplePropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMultisamplePropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceSampleLocationsPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineSampleLocationsStateCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineSampleLocationsStateCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderPassSampleLocationsBeginInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRenderPassSampleLocationsBeginInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkSampleLocationsInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSampleLocationsInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSampleLocationsInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineColorBlendAdvancedStateCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineCoverageToColorStateCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineCoverageToColorStateCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineCoverageModulationStateCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineCoverageModulationStateCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT: {
                auto castedStruct = reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDrmFormatModifierPropertiesList2EXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDrmFormatModifierPropertiesList2EXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT: {
                auto castedStruct = reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDrmFormatModifierPropertiesListEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDrmFormatModifierPropertiesListEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageDrmFormatModifierExplicitCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageDrmFormatModifierListCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageDrmFormatModifierListCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkImageDrmFormatModifierPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageDrmFormatModifierPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageDrmFormatModifierPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkShaderModuleValidationCacheCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkValidationCacheCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkValidationCacheCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkValidationCacheCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShadingRateImageFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShadingRateImagePropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineViewportShadingRateImageStateCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureMemoryRequirementsInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureMemoryRequirementsInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkBindAccelerationStructureMemoryInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkBindAccelerationStructureMemoryInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkBindAccelerationStructureMemoryInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV: {
                auto castedStruct = reinterpret_cast<const VkGeometryAABBNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkGeometryAABBNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkGeometryAABBNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GEOMETRY_NV: {
                auto castedStruct = reinterpret_cast<const VkGeometryNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkGeometryNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkGeometryNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV: {
                auto castedStruct = reinterpret_cast<const VkGeometryTrianglesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkGeometryTrianglesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkGeometryTrianglesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkRayTracingPipelineCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRayTracingPipelineCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRayTracingPipelineCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkRayTracingShaderGroupCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRayTracingShaderGroupCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRayTracingShaderGroupCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV: {
                auto castedStruct = reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkWriteDescriptorSetAccelerationStructureNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkFilterCubicImageViewImageFormatPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageViewImageFormatInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportMemoryHostPointerInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportMemoryHostPointerInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkMemoryHostPointerPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryHostPointerPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryHostPointerPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD: {
                auto castedStruct = reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineCompilerControlCreateInfoAMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineCompilerControlCreateInfoAMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkCalibratedTimestampInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCalibratedTimestampInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCalibratedTimestampInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderCorePropertiesAMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderCorePropertiesAMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD: {
                auto castedStruct = reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceMemoryOverallocationCreateInfoAMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceMemoryOverallocationCreateInfoAMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineVertexInputDivisorStateCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP: {
                auto castedStruct = reinterpret_cast<const VkPresentFrameTokenGGP*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPresentFrameTokenGGP*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPresentFrameTokenGGP(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMeshShaderFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMeshShaderPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderImageFootprintFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExclusiveScissorFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineViewportExclusiveScissorStateCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV: {
                auto castedStruct = reinterpret_cast<const VkCheckpointDataNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCheckpointDataNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCheckpointDataNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkQueueFamilyCheckpointPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkQueueFamilyCheckpointPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL: {
                auto castedStruct = reinterpret_cast<const VkInitializePerformanceApiInfoINTEL*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkInitializePerformanceApiInfoINTEL*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkInitializePerformanceApiInfoINTEL(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL: {
                auto castedStruct = reinterpret_cast<const VkPerformanceConfigurationAcquireInfoINTEL*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPerformanceConfigurationAcquireInfoINTEL*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPerformanceConfigurationAcquireInfoINTEL(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL: {
                auto castedStruct = reinterpret_cast<const VkPerformanceMarkerInfoINTEL*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPerformanceMarkerInfoINTEL*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPerformanceMarkerInfoINTEL(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL: {
                auto castedStruct = reinterpret_cast<const VkPerformanceOverrideInfoINTEL*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPerformanceOverrideInfoINTEL*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPerformanceOverrideInfoINTEL(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL: {
                auto castedStruct = reinterpret_cast<const VkPerformanceStreamMarkerInfoINTEL*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPerformanceStreamMarkerInfoINTEL*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPerformanceStreamMarkerInfoINTEL(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL: {
                auto castedStruct = reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkQueryPoolPerformanceQueryCreateInfoINTEL(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePCIBusInfoPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD: {
                auto castedStruct = reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDisplayNativeHdrSurfaceCapabilitiesAMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD: {
                auto castedStruct = reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSwapchainDisplayNativeHdrCreateInfoAMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA: {
                auto castedStruct = reinterpret_cast<const VkImagePipeSurfaceCreateInfoFUCHSIA*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImagePipeSurfaceCreateInfoFUCHSIA(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkMetalSurfaceCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMetalSurfaceCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMetalSurfaceCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRenderPassFragmentDensityMapCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreProperties2AMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderCoreProperties2AMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCoherentMemoryFeaturesAMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMemoryBudgetPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryPriorityAllocateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryPriorityAllocateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMemoryPriorityFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkBufferDeviceAddressCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkBufferDeviceAddressCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkValidationFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkValidationFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkValidationFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkCooperativeMatrixPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCooperativeMatrixPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCooperativeMatrixPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeMatrixFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCooperativeMatrixPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV: {
                auto castedStruct = reinterpret_cast<const VkFramebufferMixedSamplesCombinationNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkFramebufferMixedSamplesCombinationNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkFramebufferMixedSamplesCombinationNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCoverageReductionModeFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineCoverageReductionStateCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineCoverageReductionStateCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceProvokingVertexFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceProvokingVertexPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT: {
                auto castedStruct = reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfaceCapabilitiesFullScreenExclusiveEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfaceFullScreenExclusiveInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfaceFullScreenExclusiveInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfaceFullScreenExclusiveWin32InfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkHeadlessSurfaceCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkHeadlessSurfaceCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkHeadlessSurfaceCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceLineRasterizationFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceLineRasterizationFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceLineRasterizationPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceLineRasterizationPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceLineRasterizationPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineRasterizationLineStateCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineRasterizationLineStateCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceIndexTypeUint8FeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkCopyImageToImageInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCopyImageToImageInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCopyImageToImageInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkCopyImageToMemoryInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCopyImageToMemoryInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCopyImageToMemoryInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkCopyMemoryToImageInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCopyMemoryToImageInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCopyMemoryToImageInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT: {
                auto castedStruct = reinterpret_cast<const VkHostImageCopyDevicePerformanceQueryEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkHostImageCopyDevicePerformanceQueryEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkHostImageCopyDevicePerformanceQueryEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkHostImageLayoutTransitionInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkHostImageLayoutTransitionInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkHostImageLayoutTransitionInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT: {
                auto castedStruct = reinterpret_cast<const VkImageToMemoryCopyEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageToMemoryCopyEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageToMemoryCopyEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT: {
                auto castedStruct = reinterpret_cast<const VkMemoryToImageCopyEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryToImageCopyEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryToImageCopyEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceHostImageCopyFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceHostImageCopyFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceHostImageCopyPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceHostImageCopyPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceHostImageCopyPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT: {
                auto castedStruct = reinterpret_cast<const VkSubresourceHostMemcpySizeEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSubresourceHostMemcpySizeEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSubresourceHostMemcpySizeEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT: {
                auto castedStruct = reinterpret_cast<const VkSurfacePresentModeCompatibilityEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfacePresentModeCompatibilityEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfacePresentModeCompatibilityEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT: {
                auto castedStruct = reinterpret_cast<const VkSurfacePresentModeEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfacePresentModeEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfacePresentModeEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkSurfacePresentScalingCapabilitiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfacePresentScalingCapabilitiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfacePresentScalingCapabilitiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkReleaseSwapchainImagesInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkReleaseSwapchainImagesInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkReleaseSwapchainImagesInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkSwapchainPresentFenceInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSwapchainPresentFenceInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSwapchainPresentFenceInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkSwapchainPresentModeInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSwapchainPresentModeInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSwapchainPresentModeInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkSwapchainPresentModesCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSwapchainPresentModesCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSwapchainPresentModesCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkSwapchainPresentScalingCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSwapchainPresentScalingCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSwapchainPresentScalingCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkGeneratedCommandsInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkGeneratedCommandsInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkGeneratedCommandsInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkGeneratedCommandsMemoryRequirementsInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkGraphicsPipelineShaderGroupsCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkGraphicsShaderGroupCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkGraphicsShaderGroupCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkGraphicsShaderGroupCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkIndirectCommandsLayoutCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkIndirectCommandsLayoutCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV: {
                auto castedStruct = reinterpret_cast<const VkIndirectCommandsLayoutTokenNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkIndirectCommandsLayoutTokenNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkIndirectCommandsLayoutTokenNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCommandBufferInheritanceViewportScissorInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCommandBufferInheritanceViewportScissorInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM: {
                auto castedStruct = reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM: {
                auto castedStruct = reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderPassTransformBeginInfoQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRenderPassTransformBeginInfoQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDepthBiasInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDepthBiasInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDepthBiasInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDepthBiasRepresentationInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDepthBiasRepresentationInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDepthBiasRepresentationInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDepthBiasControlFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceDeviceMemoryReportCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT: {
                auto castedStruct = reinterpret_cast<const VkDeviceMemoryReportCallbackDataEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceMemoryReportCallbackDataEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceMemoryReportCallbackDataEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRobustness2FeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRobustness2FeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRobustness2PropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRobustness2PropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCustomBorderColorFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCustomBorderColorPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSamplerCustomBorderColorCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSamplerCustomBorderColorCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePresentBarrierFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePresentBarrierFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV: {
                auto castedStruct = reinterpret_cast<const VkSurfaceCapabilitiesPresentBarrierNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSurfaceCapabilitiesPresentBarrierNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSurfaceCapabilitiesPresentBarrierNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkSwapchainPresentBarrierCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSwapchainPresentBarrierCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSwapchainPresentBarrierCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceDiagnosticsConfigCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceDiagnosticsConfigCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV: {
                auto castedStruct = reinterpret_cast<const VkQueryLowLatencySupportNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkQueryLowLatencySupportNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkQueryLowLatencySupportNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkGraphicsPipelineLibraryCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkGraphicsPipelineLibraryCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineFragmentShadingRateEnumStateCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureGeometryMotionTrianglesDataNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureMotionInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureMotionInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM: {
                auto castedStruct = reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCopyCommandTransformInfoQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCopyCommandTransformInfoQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT: {
                auto castedStruct = reinterpret_cast<const VkImageCompressionControlEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageCompressionControlEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageCompressionControlEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkImageCompressionPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageCompressionPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageCompressionPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageCompressionControlFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevice4444FormatsFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevice4444FormatsFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT: {
                auto castedStruct = reinterpret_cast<const VkDeviceFaultCountsEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceFaultCountsEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceFaultCountsEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDeviceFaultInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceFaultInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceFaultInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFaultFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFaultFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkDirectFBSurfaceCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDirectFBSurfaceCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDirectFBSurfaceCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkMutableDescriptorTypeCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMutableDescriptorTypeCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMutableDescriptorTypeCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT: {
                auto castedStruct = reinterpret_cast<const VkVertexInputAttributeDescription2EXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVertexInputAttributeDescription2EXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVertexInputAttributeDescription2EXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT: {
                auto castedStruct = reinterpret_cast<const VkVertexInputBindingDescription2EXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkVertexInputBindingDescription2EXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkVertexInputBindingDescription2EXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDrmPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDrmPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT: {
                auto castedStruct = reinterpret_cast<const VkDeviceAddressBindingCallbackDataEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDeviceAddressBindingCallbackDataEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDeviceAddressBindingCallbackDataEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceAddressBindingReportFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDepthClipControlFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineViewportDepthClipControlCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA: {
                auto castedStruct = reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportMemoryZirconHandleInfoFUCHSIA*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportMemoryZirconHandleInfoFUCHSIA(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA: {
                auto castedStruct = reinterpret_cast<const VkMemoryGetZirconHandleInfoFUCHSIA*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryGetZirconHandleInfoFUCHSIA(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA: {
                auto castedStruct = reinterpret_cast<const VkMemoryZirconHandlePropertiesFUCHSIA*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryZirconHandlePropertiesFUCHSIA(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA: {
                auto castedStruct = reinterpret_cast<const VkImportSemaphoreZirconHandleInfoFUCHSIA*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImportSemaphoreZirconHandleInfoFUCHSIA(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA: {
                auto castedStruct = reinterpret_cast<const VkSemaphoreGetZirconHandleInfoFUCHSIA*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSemaphoreGetZirconHandleInfoFUCHSIA(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkMemoryGetRemoteAddressInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMemoryGetRemoteAddressInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMemoryGetRemoteAddressInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT: {
                auto castedStruct = reinterpret_cast<const VkFrameBoundaryEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkFrameBoundaryEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkFrameBoundaryEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFrameBoundaryFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkMultisampledRenderToSingleSampledInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMultisampledRenderToSingleSampledInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMultisampledRenderToSingleSampledInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT: {
                auto castedStruct = reinterpret_cast<const VkSubpassResolvePerformanceQueryEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSubpassResolvePerformanceQueryEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSubpassResolvePerformanceQueryEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX: {
                auto castedStruct = reinterpret_cast<const VkScreenSurfaceCreateInfoQNX*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkScreenSurfaceCreateInfoQNX*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkScreenSurfaceCreateInfoQNX(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceColorWriteEnableFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineColorWriteCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineColorWriteCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageViewMinLodCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageViewMinLodCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageViewMinLodFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMultiDrawFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMultiDrawPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderTileImageFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderTileImagePropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderTileImagePropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureTrianglesOpacityMicromapEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkCopyMemoryToMicromapInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCopyMemoryToMicromapInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCopyMemoryToMicromapInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkCopyMicromapInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCopyMicromapInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCopyMicromapInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkCopyMicromapToMemoryInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCopyMicromapToMemoryInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCopyMicromapToMemoryInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkMicromapBuildInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMicromapBuildInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMicromapBuildInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkMicromapBuildSizesInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMicromapBuildSizesInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMicromapBuildSizesInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkMicromapCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMicromapCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMicromapCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkMicromapVersionInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMicromapVersionInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMicromapVersionInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceOpacityMicromapFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceOpacityMicromapPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureTrianglesDisplacementMicromapNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureTrianglesDisplacementMicromapNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDisplacementMicromapFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDisplacementMicromapPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSamplerBorderColorComponentMappingCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesARM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderCorePropertiesARM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderCorePropertiesARM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkImageViewSlicedCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageViewSlicedCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageViewSlicedCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE: {
                auto castedStruct = reinterpret_cast<const VkDescriptorSetBindingReferenceVALVE*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDescriptorSetBindingReferenceVALVE*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDescriptorSetBindingReferenceVALVE(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE: {
                auto castedStruct = reinterpret_cast<const VkDescriptorSetLayoutHostMappingInfoVALVE*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDescriptorSetLayoutHostMappingInfoVALVE(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM: {
                auto castedStruct = reinterpret_cast<const VkSubpassFragmentDensityMapOffsetEndInfoQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSubpassFragmentDensityMapOffsetEndInfoQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkComputePipelineIndirectBufferInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkComputePipelineIndirectBufferInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkComputePipelineIndirectBufferInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkPipelineIndirectDeviceAddressInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineIndirectDeviceAddressInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineIndirectDeviceAddressInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM: {
                auto castedStruct = reinterpret_cast<const VkImageViewSampleWeightCreateInfoQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkImageViewSampleWeightCreateInfoQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkImageViewSampleWeightCreateInfoQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageProcessingFeaturesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageProcessingPropertiesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageProcessingPropertiesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceNestedCommandBufferPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT: {
                auto castedStruct = reinterpret_cast<const VkExternalMemoryAcquireUnmodifiedEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkExternalMemoryAcquireUnmodifiedEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkExternalMemoryAcquireUnmodifiedEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT: {
                auto castedStruct = reinterpret_cast<const VkRenderPassCreationControlEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderPassCreationControlEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRenderPassCreationControlEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderPassCreationFeedbackCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRenderPassCreationFeedbackCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRenderPassSubpassFeedbackCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG: {
                auto castedStruct = reinterpret_cast<const VkDirectDriverLoadingInfoLUNARG*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDirectDriverLoadingInfoLUNARG*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDirectDriverLoadingInfoLUNARG(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG: {
                auto castedStruct = reinterpret_cast<const VkDirectDriverLoadingListLUNARG*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkDirectDriverLoadingListLUNARG*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkDirectDriverLoadingListLUNARG(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPipelineShaderStageModuleIdentifierCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT: {
                auto castedStruct = reinterpret_cast<const VkShaderModuleIdentifierEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkShaderModuleIdentifierEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkShaderModuleIdentifierEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkOpticalFlowExecuteInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkOpticalFlowExecuteInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkOpticalFlowExecuteInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkOpticalFlowImageFormatInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkOpticalFlowImageFormatInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkOpticalFlowImageFormatInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkOpticalFlowImageFormatPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkOpticalFlowImageFormatPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkOpticalFlowImageFormatPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkOpticalFlowSessionCreateInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkOpticalFlowSessionCreateInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkOpticalFlowSessionCreateInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV: {
                auto castedStruct = reinterpret_cast<const VkOpticalFlowSessionCreatePrivateDataInfoNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkOpticalFlowSessionCreatePrivateDataInfoNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceOpticalFlowFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceOpticalFlowPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceOpticalFlowPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceLegacyDitheringFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID: {
                auto castedStruct = reinterpret_cast<const VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAndroidHardwareBufferFormatResolvePropertiesANDROID(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderObjectFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderObjectPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderObjectPropertiesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT: {
                auto castedStruct = reinterpret_cast<const VkShaderCreateInfoEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkShaderCreateInfoEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkShaderCreateInfoEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceTilePropertiesFeaturesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkTilePropertiesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkTilePropertiesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkTilePropertiesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC: {
                auto castedStruct = reinterpret_cast<const VkAmigoProfilingSubmitInfoSEC*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAmigoProfilingSubmitInfoSEC*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAmigoProfilingSubmitInfoSEC(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceAmigoProfilingFeaturesSEC(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM: {
                auto castedStruct = reinterpret_cast<const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageProcessing2FeaturesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceImageProcessing2PropertiesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM: {
                auto castedStruct = reinterpret_cast<const VkSamplerBlockMatchWindowCreateInfoQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSamplerBlockMatchWindowCreateInfoQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM: {
                auto castedStruct = reinterpret_cast<const VkBlitImageCubicWeightsInfoQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkBlitImageCubicWeightsInfoQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkBlitImageCubicWeightsInfoQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCubicWeightsFeaturesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM: {
                auto castedStruct = reinterpret_cast<const VkSamplerCubicWeightsCreateInfoQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSamplerCubicWeightsCreateInfoQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSamplerCubicWeightsCreateInfoQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM: {
                auto castedStruct = reinterpret_cast<const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceCubicClampFeaturesQCOM(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceLayeredDriverPropertiesMSFT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureBuildGeometryInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureBuildGeometryInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureBuildSizesInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureBuildSizesInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureBuildSizesInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureDeviceAddressInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureDeviceAddressInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureDeviceAddressInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureGeometryAabbsDataKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureGeometryAabbsDataKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureGeometryAabbsDataKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureGeometryInstancesDataKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureGeometryInstancesDataKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureGeometryInstancesDataKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureGeometryTrianglesDataKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureGeometryTrianglesDataKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureGeometryTrianglesDataKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkAccelerationStructureVersionInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkAccelerationStructureVersionInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkAccelerationStructureVersionInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkCopyAccelerationStructureInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCopyAccelerationStructureInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCopyAccelerationStructureInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkCopyAccelerationStructureToMemoryInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCopyAccelerationStructureToMemoryInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkCopyMemoryToAccelerationStructureInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkCopyMemoryToAccelerationStructureInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceAccelerationStructureFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceAccelerationStructurePropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR: {
                auto castedStruct = reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkWriteDescriptorSetAccelerationStructureKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRayTracingPipelinePropertiesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkRayTracingPipelineCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRayTracingPipelineCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRayTracingPipelineCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkRayTracingPipelineInterfaceCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRayTracingPipelineInterfaceCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR: {
                auto castedStruct = reinterpret_cast<const VkRayTracingShaderGroupCreateInfoKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkRayTracingShaderGroupCreateInfoKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkRayTracingShaderGroupCreateInfoKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceRayQueryFeaturesKHR*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceRayQueryFeaturesKHR(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMeshShaderFeaturesEXT(out,
                             castedStruct,
                             castedMetaInfo,
                             consumer);

                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT: {
                auto castedStruct = reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesEXT*>(structInfo);
                auto castedMetaInfo = reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT*>(metaInfoPNext->GetMetaStructPointer());
                pNextName = "&" +  GenerateStruct_VkPhysicalDeviceMeshShaderPropertiesEXT(out,
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
