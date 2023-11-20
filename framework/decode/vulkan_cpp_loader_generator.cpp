/*
** Copyright (c) 2021 Samsung
** Copyright (c) 2023 Google
** Copyright (c) 2023 LunarG, Inc
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

#include "decode/vulkan_cpp_loader_generator.h"

#include "util/file_path.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static const char* sLoaderHeader = R"(
#ifndef LOADER_H
#define LOADER_H

#include <vulkan/vulkan.h>
)";

static const char* sLoadFunction = R"(
void loadFunctions(VkInstance instance);
)";

VulkanCppLoaderGenerator::VulkanCppLoaderGenerator() : vulkan_methods_() {}

VulkanCppLoaderGenerator::~VulkanCppLoaderGenerator() {}

void VulkanCppLoaderGenerator::AddMethodName(const std::string method_name)
{
    vulkan_methods_.insert(method_name);
}

void VulkanCppLoaderGenerator::WriteOutLoaderGenerator(const std::string& outDir, const GfxTocppPlatform& platform)
{
    FILE*       pfn_src_file; // loader.cpp
    FILE*       pfn_hdr_file; // loader.h
    std::string filename_src = util::filepath::Join(outDir, "loader.cpp");
    std::string filename_hdr = util::filepath::Join(outDir, "loader.h");
    int32_t     result_src   = util::platform::FileOpen(&pfn_src_file, filename_src.c_str(), "w");
    uint32_t    result_hdr   = util::platform::FileOpen(&pfn_hdr_file, filename_hdr.c_str(), "w");
    if (result_src == 0 && result_hdr == 0)
    {
        fprintf(pfn_hdr_file, "%s\n", sLoaderHeader);
        switch (platform)
        {
            case GfxTocppPlatform::PLATFORM_ANDROID:
                fprintf(pfn_src_file, "#define VK_USE_PLATFORM_ANDROID_KHR\n");
                break;
            case GfxTocppPlatform::PLATFORM_MACOS:
                fprintf(pfn_src_file, "#define VK_USE_PLATFORM_METAL_EXT\n");
                break;
            case GfxTocppPlatform::PLATFORM_WAYLAND:
                fprintf(pfn_src_file, "#define VK_USE_PLATFORM_WAYLAND_KHR\n");
                break;
            case GfxTocppPlatform::PLATFORM_WIN32:
                fprintf(pfn_src_file, "#define VK_USE_PLATFORM_WIN32_KHR\n");
                break;
            case GfxTocppPlatform::PLATFORM_XCB:
                fprintf(pfn_src_file, "#define VK_USE_PLATFORM_XCB_KHR\n");
                break;
            case GfxTocppPlatform::PLATFORM_XLIB:
                fprintf(pfn_src_file, "#define VK_USE_PLATFORM_XLIB_KHR\n");
                break;
            default:
                break;
        }

        fprintf(pfn_src_file, "#include \"loader.h\"\n\n");
        fprintf(pfn_hdr_file, "%s", sLoadFunction);
        for (const auto& vulkan_method : vulkan_methods_)
        {
            std::string loader_body = "PFN_" + vulkan_method + " loaded_" + vulkan_method + ";\n";
            fprintf(pfn_src_file, "%s", loader_body.c_str());
            fprintf(pfn_hdr_file, "extern %s", loader_body.c_str());
        }
        WriteOutLoadFunctions(pfn_src_file);
        fprintf(pfn_hdr_file, "#endif // LOADER_H\n");
    }
}

void VulkanCppLoaderGenerator::WriteOutLoadFunctions(FILE* file)
{
    fprintf(file, "\nvoid loadFunctions(VkInstance instance) {\n");
    for (const auto& vulkan_method : vulkan_methods_)
    {
        fprintf(file,
                "  loaded_%s = reinterpret_cast<PFN_%s>(vkGetInstanceProcAddr(instance, \"%s\"));\n",
                vulkan_method.c_str(),
                vulkan_method.c_str(),
                vulkan_method.c_str());
    }
    fprintf(file, "}\n");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
