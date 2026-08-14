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

// Surface creation for each target platform.
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
void VulkanCppConsumerBase::Generate_vkCreateAndroidSurfaceKHR(args::CreateAndroidSurfaceKHR& args)
{
    GenerateSurfaceCreation(
        platform_, args.result, args.instance, (void*)&args.pCreateInfo, args.pSurface.GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateMetalSurfaceEXT(args::CreateMetalSurfaceEXT& args)
{
    GenerateSurfaceCreation(
        platform_, args.result, args.instance, (void*)&args.pCreateInfo, args.pSurface.GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateWaylandSurfaceKHR(args::CreateWaylandSurfaceKHR& args)
{
    GenerateSurfaceCreation(
        platform_, args.result, args.instance, (void*)&args.pCreateInfo, args.pSurface.GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateWin32SurfaceKHR(args::CreateWin32SurfaceKHR& args)
{
    GenerateSurfaceCreation(
        platform_, args.result, args.instance, (void*)&args.pCreateInfo, args.pSurface.GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateXcbSurfaceKHR(args::CreateXcbSurfaceKHR& args)
{
    GenerateSurfaceCreation(
        platform_, args.result, args.instance, (void*)&args.pCreateInfo, args.pSurface.GetPointer());
}

void VulkanCppConsumerBase::Generate_vkCreateXlibSurfaceKHR(args::CreateXlibSurfaceKHR& args)
{
    GenerateSurfaceCreation(
        platform_, args.result, args.instance, (void*)&args.pCreateInfo, args.pSurface.GetPointer());
}

void VulkanCppConsumerBase::GenerateSurfaceCreation(GfxToCppPlatform        platform,
                                                    VkResult                returnValue,
                                                    format::HandleId        instance,
                                                    void*                   pSurfaceCreateInfo,
                                                    const format::HandleId* pSurface)
{
    FILE* file = GetFrameFile();

    std::stringstream stream_create_info;
    std::string       surface_var_name            = "pSurface_" + std::to_string(GetNextId());
    std::string       create_info_struct_var_name = "";
    std::string       surface_create_func_call    = "";

    fprintf(file, "\t{\n");

    switch (platform_)
    {
        case GfxToCppPlatform::PLATFORM_ANDROID:
        {
            VkAndroidSurfaceCreateInfoKHR         android_struct_info  = {};
            Decoded_VkAndroidSurfaceCreateInfoKHR decoded_android_info = {};

            if (platform_ == platform)
            {
                android_struct_info =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            android_struct_info.sType   = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
            create_info_struct_var_name = GenerateStruct_VkAndroidSurfaceCreateInfoKHR(
                stream_create_info, &android_struct_info, &decoded_android_info, *this);
            surface_create_func_call = "vkCreateAndroidSurfaceKHR";
            break;
        }
        case GfxToCppPlatform::PLATFORM_WIN32:
        {
            VkWin32SurfaceCreateInfoKHR         win32_struct_info  = {};
            Decoded_VkWin32SurfaceCreateInfoKHR decoded_win32_info = {};

            if (platform_ == platform)
            {
                win32_struct_info =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            win32_struct_info.sType     = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
            create_info_struct_var_name = GenerateStruct_VkWin32SurfaceCreateInfoKHR(
                stream_create_info, &win32_struct_info, &decoded_win32_info, *this);
            surface_create_func_call = "vkCreateWin32SurfaceKHR";
            break;
        }
        case GfxToCppPlatform::PLATFORM_XCB:
        {
            VkXcbSurfaceCreateInfoKHR         xcb_struct_info  = {};
            Decoded_VkXcbSurfaceCreateInfoKHR decoded_xcb_info = {};

            if (platform_ == platform)
            {
                xcb_struct_info =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            xcb_struct_info.sType       = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
            create_info_struct_var_name = GenerateStruct_VkXcbSurfaceCreateInfoKHR(
                stream_create_info, &xcb_struct_info, &decoded_xcb_info, *this);
            surface_create_func_call = "vkCreateXcbSurfaceKHR";
            break;
        }
        case GfxToCppPlatform::PLATFORM_WAYLAND:
        {
            VkWaylandSurfaceCreateInfoKHR         wayland_struct_info  = {};
            Decoded_VkWaylandSurfaceCreateInfoKHR decoded_wayland_info = {};

            if (platform_ == platform)
            {
                wayland_struct_info =
                    *reinterpret_cast<StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>*>(pSurfaceCreateInfo)
                         ->GetPointer();
            }
            wayland_struct_info.sType   = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR;
            create_info_struct_var_name = GenerateStruct_VkWaylandSurfaceCreateInfoKHR(
                stream_create_info, &wayland_struct_info, &decoded_wayland_info, *this);
            surface_create_func_call = "vkCreateWaylandSurfaceKHR";
            break;
        }
        default:
            GFXRECON_LOG_FATAL("Failed to generate surface creation: Invalid platform (%d)", platform_);
            break;
    }
    fprintf(file, "\n%s", stream_create_info.str().c_str());
    AddKnownVariables("VkSurfaceKHR", surface_var_name, pSurface);
    AddHandles(surface_var_name, pSurface);
    pfn_loader_.AddMethodName(surface_create_func_call);
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_%s(%s, &%s, %s, &%s), %s);\n",
            surface_create_func_call.c_str(),
            GetHandle(instance).c_str(),
            create_info_struct_var_name.c_str(),
            "nullptr",
            surface_var_name.c_str(),
            util::ToString<VkResult>(returnValue).c_str());

    fprintf(file, "\t}\n");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
