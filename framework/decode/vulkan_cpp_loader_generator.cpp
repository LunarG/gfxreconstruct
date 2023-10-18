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

VulkanCppLoaderGenerator::VulkanCppLoaderGenerator() : m_vulkanMethods() {}

VulkanCppLoaderGenerator::~VulkanCppLoaderGenerator() {}

void VulkanCppLoaderGenerator::AddMethodName(const std::string method_name)
{
    m_vulkanMethods.insert(method_name);
}

void VulkanCppLoaderGenerator::WriteOutLoaderGenerator(const std::string& outDir, const GfxTocppPlatform& platform)
{
    FILE*       pfn_src_file; // loader.cpp
    FILE*       pfn_hdr_file; // loader.h
    std::string filenameSrc = util::filepath::Join(outDir, "loader.cpp");
    std::string filenameHdr = util::filepath::Join(outDir, "loader.h");
    int32_t     resultSrc   = util::platform::FileOpen(&pfn_src_file, filenameSrc.c_str(), "w");
    uint32_t    resultHdr   = util::platform::FileOpen(&pfn_hdr_file, filenameHdr.c_str(), "w");
    if (resultSrc == 0 && resultHdr == 0)
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
        for (const auto& vulkanMethod : m_vulkanMethods)
        {
            std::string loaderBody = "PFN_" + vulkanMethod + " loaded_" + vulkanMethod + ";\n";
            fprintf(pfn_src_file, "%s", loaderBody.c_str());
            fprintf(pfn_hdr_file, "extern %s", loaderBody.c_str());
        }
        WriteOutLoadFunctions(pfn_src_file);
        fprintf(pfn_hdr_file, "#endif // LOADER_H\n");
    }
}

void VulkanCppLoaderGenerator::WriteOutLoadFunctions(FILE* file)
{
    fprintf(file, "\nvoid loadFunctions(VkInstance instance) {\n");
    for (const auto& vulkanMethod : m_vulkanMethods)
    {
        fprintf(file,
                "  loaded_%s = reinterpret_cast<PFN_%s>(vkGetInstanceProcAddr(instance, \"%s\"));\n",
                vulkanMethod.c_str(),
                vulkanMethod.c_str(),
                vulkanMethod.c_str());
    }
    fprintf(file, "}\n");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
