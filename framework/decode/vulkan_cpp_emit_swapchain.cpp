//
// Copyright (c) 2020 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2023 LunarG, Inc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Swapchain creation, image query, acquire, and present.
// This file holds part of VulkanCppConsumerBase.  See vulkan_cpp_consumer_base.h.

#include "decode/vulkan_cpp_consumer_base.h"
#include "decode/vulkan_cpp_template_strings.h"

#include PROJECT_VERSION_HEADER_FILE
#include "util/file_path.h"
#include "util/platform.h"
#include <util/hash.h>
#include "decode/vulkan_cpp_structs.h"
#include <generated/generated_vulkan_cpp_structs.h>
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "generated/generated_vulkan_enum_to_string.h"

#include <algorithm>
#include <cmath>
#include <iomanip>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
void VulkanCppConsumerBase::Generate_vkCreateSwapchainKHR(args::CreateSwapchainKHR& args)
{
    FILE* file = GetFrameFile();

    fprintf(file, "\t{\n");

    std::stringstream         stream_pcreate_info;
    VkSwapchainCreateInfoKHR* struct_info = args.pCreateInfo.GetPointer();
    if (platform_ == GfxToCppPlatform::PLATFORM_ANDROID)
    {
        struct_info->imageExtent.width  = GetProperWindowWidth(struct_info->imageExtent.width);
        struct_info->imageExtent.height = GetProperWindowHeight(struct_info->imageExtent.height);
    }
    std::string pcreate_info_struct = GenerateStruct_VkSwapchainCreateInfoKHR(
        stream_pcreate_info, struct_info, args.pCreateInfo.GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pswapchain_name = "pSwapchain_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_SWAPCHAIN_KHR));
    AddKnownVariables("VkSwapchainKHR", pswapchain_name, args.pSwapchain.GetPointer());
    if (args.result == VK_SUCCESS)
    {
        this->AddHandles(pswapchain_name, args.pSwapchain.GetPointer());
    }

    fprintf(file,
            "\t\tVK_CALL_CHECK(toCppCreateSwapchainKHR(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pswapchain_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkDestroySwapchainKHR(args::DestroySwapchainKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    fprintf(file,
            "\t\ttoCppDestroySwapchainKHR(%s, %s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.swapchain).c_str(),
            "nullptr");
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkGetSwapchainImagesKHR(args::GetSwapchainImagesKHR& args)
{
    FILE* file = GetFrameFile();

    uint32_t captured_swapchain_count = 0;
    if (args.pSwapchainImageCount.GetPointer() != nullptr)
    {
        captured_swapchain_count = *args.pSwapchainImageCount.GetPointer();
    }

    // An application normally calls this twice: once to get the image count, then
    // again to get the images.  A trimmed capture file can hold the second call
    // without the first, because the first call happened before the trim point.
    // So make sure that a count variable exists for either call.
    auto count_entry = swapchain_image_count_map_.find(args.swapchain);
    if (count_entry == swapchain_image_count_map_.end())
    {
        const std::string new_count_var_name = "pSwapchainImageCount_" + std::to_string(GetNextId());
        AddKnownVariables("uint32_t", new_count_var_name);
        count_entry = swapchain_image_count_map_.emplace(args.swapchain, new_count_var_name).first;

        if (args.pSwapchainImages.GetPointer() != nullptr)
        {
            // No count call came first, so start from the count in the capture file.
            fprintf(file, "\t%s = %u;\n", new_count_var_name.c_str(), captured_swapchain_count);
        }
    }
    const std::string& swapchain_image_count_var_name = count_entry->second;

    std::string swapchain_images_var_name = "NULL";
    if (args.pSwapchainImages.GetPointer() != NULL)
    {
        swapchain_images_var_name = "pSwapchainImages_" + std::to_string(GetNextId());
        fprintf(file,
                "\t%s = new VkImage[%s];\n",
                swapchain_images_var_name.c_str(),
                swapchain_image_count_var_name.c_str());
        AddKnownVariables("VkImage*", swapchain_images_var_name);
        if (args.result == VK_SUCCESS)
        {
            AddHandles(swapchain_images_var_name,
                       args.pSwapchainImages.GetPointer(),
                       GFXRECON_NARROWING_CAST(uint32_t, args.pSwapchainImages.GetLength()));
        }
    }

    pfn_loader_.AddMethodName("vkGetSwapchainImagesKHR");

    fprintf(file,
            "\tVK_CALL_CHECK(toCppGetSwapchainImagesKHR(%s, %s, %u, &%s, %s), %s);\n",
            GetHandle(args.device).c_str(),
            handle_id_map_[args.swapchain].c_str(),
            captured_swapchain_count,
            swapchain_image_count_var_name.c_str(),
            swapchain_images_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
}

void VulkanCppConsumerBase::Generate_vkGetPhysicalDeviceSurfaceFormatsKHR(
    args::GetPhysicalDeviceSurfaceFormatsKHR& args)
{
    FILE* file = GetFrameFile();

    std::string surface_formats_var_name = "NULL";
    if (args.pSurfaceFormats.GetPointer() == NULL)
    {
        const std::string surface_format_count_name = "pSurfaceFormatCount_" + std::to_string(GetNextId());
        fprintf(file, "\tuint32_t %s;\n", surface_format_count_name.c_str());
        surface_format_count_map_[args.surface] = surface_format_count_name;
    }
    else
    {
        surface_formats_var_name = "pSurfaceFormats_" + std::to_string(GetNextId());
        fprintf(file,
                "\tVkSurfaceFormatKHR %s[%s];\n",
                surface_formats_var_name.c_str(),
                surface_format_count_map_[args.surface].c_str());
        // TODO: connect these formats to their usages? How?
    }

    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfaceFormatsKHR");
    fprintf(file,
            "\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfaceFormatsKHR(%s, %s, &%s, %s), %s);\n",
            GetHandle(args.physicalDevice).c_str(),
            GetHandle(args.surface).c_str(),
            surface_format_count_map_[args.surface].c_str(),
            surface_formats_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetPhysicalDeviceSurfacePresentModesKHR(
    args::GetPhysicalDeviceSurfacePresentModesKHR& args)
{
    FILE* file = GetFrameFile();

    std::string present_modes_var_name = "NULL";
    if (args.pPresentModes.GetPointer() == NULL)
    {
        const std::string present_mode_count_var_name = "pPresentModeCount_" + std::to_string(GetNextId());
        fprintf(file, "\tuint32_t %s;\n", present_mode_count_var_name.c_str());
        surface_present_mode_count_map_[args.surface] = present_mode_count_var_name;
    }
    else
    {
        present_modes_var_name = "pPresentModes_" + std::to_string(GetNextId());
        fprintf(file,
                "\tVkPresentModeKHR %s[%s];\n",
                present_modes_var_name.c_str(),
                surface_present_mode_count_map_[args.surface].c_str());
        // TODO: connect these formats to their usages? How?
    }

    pfn_loader_.AddMethodName("vkGetPhysicalDeviceSurfacePresentModesKHR");
    fprintf(file,
            "\tVK_CALL_CHECK(loaded_vkGetPhysicalDeviceSurfacePresentModesKHR(%s, %s, &%s, %s), %s);\n",
            GetHandle(args.physicalDevice).c_str(),
            GetHandle(args.surface).c_str(),
            surface_present_mode_count_map_[args.surface].c_str(),
            present_modes_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkAcquireNextImageKHR(args::AcquireNextImageKHR& args)
{
    FILE*       file                 = GetFrameFile();
    std::string image_index_var_name = "pImageIndex_" + std::to_string(GetNextId());
    next_image_map_[args.swapchain].push(image_index_var_name);

    AddKnownVariables("uint32_t", image_index_var_name);

    pfn_loader_.AddMethodName("vkAcquireNextImageKHR");
    fprintf(file,
            "\tVK_CALL_CHECK(toCppAcquireNextImageKHR(static_cast<VkResult>(0x%08x), %s, %s, %" PRIu64
            "UL, %s, %s, %u, &%s), %s);\n",
            args.result,
            GetHandle(args.device).c_str(),
            GetHandle(args.swapchain).c_str(),
            args.timeout,
            GetHandle(args.semaphore).c_str(),
            GetHandle(args.fence).c_str(),
            (*args.pImageIndex.GetPointer()),
            image_index_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
}

void VulkanCppConsumerBase::Generate_vkAcquireNextImage2KHR(args::AcquireNextImage2KHR& args)
{
    FILE*             file = GetFrameFile();
    std::stringstream stream_acquire_info;
    std::string       acquire_info_var_name = GenerateStruct_VkAcquireNextImageInfoKHR(
        stream_acquire_info, args.pAcquireInfo.GetPointer(), args.pAcquireInfo.GetMetaStructPointer(), *this);
    fprintf(file, "\n%s", stream_acquire_info.str().c_str());
    std::string image_index_var_name = "pImageIndex_" + std::to_string(GetNextId());
    fprintf(file, "\tuint32_t %s;\n", image_index_var_name.c_str());
    pfn_loader_.AddMethodName("vkAcquireNextImage2KHR");

    if (args.result == VK_SUCCESS)
    {
        fprintf(file,
                "\twhile (loaded_vkAcquireNextImage2KHR(%s, &%s, &%s) != VK_SUCCESS) { usleep(5000); };\n",
                GetHandle(args.device).c_str(),
                acquire_info_var_name.c_str(),
                image_index_var_name.c_str());
    }
    else
    {
        fprintf(file,
                "\tVK_CALL_CHECK(loaded_vkAcquireNextImage2KHR(%s, &%s, &%s), %s);\n",
                GetHandle(args.device).c_str(),
                acquire_info_var_name.c_str(),
                image_index_var_name.c_str(),
                util::ToString<VkResult>(args.result).c_str());
    }
}

void VulkanCppConsumerBase::Generate_vkQueuePresentKHR(args::QueuePresentKHR& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::stringstream stream_present_info;
    std::string       present_info_struct = GenerateStruct_VkPresentInfoKHR(stream_present_info,
                                                                      args.pPresentInfo.GetPointer(),
                                                                      args.pPresentInfo.GetMetaStructPointer(),
                                                                      imported_semaphores_,
                                                                      *this);
    fprintf(file, "%s", stream_present_info.str().c_str());
    pfn_loader_.AddMethodName("vkQueuePresentKHR");
    fprintf(file,
            "\t\tVK_CALL_CHECK(toCppQueuePresentKHR(%s, &%s), %s);\n",
            this->GetHandle(args.queue).c_str(),
            present_info_struct.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
