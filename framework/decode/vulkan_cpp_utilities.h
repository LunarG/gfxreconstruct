//
// Copyright (c) 2021 Samsung
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

#ifndef GFXREC_VULKAN_CPP_UTILITIES_H
#define GFXREC_VULKAN_CPP_UTILITIES_H

#include <util/defines.h>
#include <vulkan/vulkan.h>

#include <string>
#include <vector>
#include <map>
#include <format/platform_types.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

const uint32_t MAX_FRAME_CAPACITY = 1000;

enum class GfxToCppPlatform
{
    PLATFORM_ANDROID,
    PLATFORM_MACOS,
    PLATFORM_WAYLAND,
    PLATFORM_WIN32,
    PLATFORM_XCB,
    PLATFORM_XLIB,
    PLATFORM_COUNT // MUST BE LAST
};

struct PlatformTargets
{
    gfxrecon::decode::GfxToCppPlatform platformEnum;
    char                               platformName[32];
    char                               wsiSurfaceExtName[32];
};

const PlatformTargets kValidTargetPlatforms[] = {
    { GfxToCppPlatform::PLATFORM_ANDROID, "android", VK_KHR_ANDROID_SURFACE_EXTENSION_NAME },
    { GfxToCppPlatform::PLATFORM_MACOS, "macos", VK_EXT_METAL_SURFACE_EXTENSION_NAME },
    { GfxToCppPlatform::PLATFORM_WAYLAND, "wayland", VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME },
    { GfxToCppPlatform::PLATFORM_WIN32, "win32", VK_KHR_WIN32_SURFACE_EXTENSION_NAME },
    { GfxToCppPlatform::PLATFORM_XCB, "xcb", VK_KHR_XCB_SURFACE_EXTENSION_NAME },
    { GfxToCppPlatform::PLATFORM_XLIB, "xlib", VK_KHR_XLIB_SURFACE_EXTENSION_NAME }
};

struct GfxToCppVariable
{
    std::string type;
    std::string name;
    uint32_t    count;

    std::string                     GenerateString() const;
    static std::vector<std::string> GenerateStringVec(const std::vector<GfxToCppVariable>& variables);
};

void PrintToFile(FILE* file, const std::string& format, const std::vector<std::string>& data);

enum DescriptorBaseType
{
    DESCRIPTOR_BASE_TYPE_NONE                   = 0,
    DESCRIPTOR_BASE_TYPE_SAMPLER                = 1,
    DESCRIPTOR_BASE_TYPE_IMAGE                  = 2,
    DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER = 3,
    DESCRIPTOR_BASE_TYPE_BUFFER                 = 4,
    DESCRIPTOR_BASE_TYPE_TEXEL                  = 5,
    DESCRIPTOR_BASE_TYPE_INLINE_UNIFORM_BLOCK   = 6,
    DESCRIPTOR_BASE_TYPE_ACCELERATION_STRUCTURE = 7,
};

std::string DescriptorCreateInfoTypeToString(VkDescriptorType descriptorType);

DescriptorBaseType GetDescriptorBaseType(VkDescriptorType descriptorType);

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif // GFXREC_VULKAN_CPP_UTILITIES_H
