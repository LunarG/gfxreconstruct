/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_CUSTOM_VULKAN_TO_STRING_H
#define GFXRECON_CUSTOM_VULKAN_TO_STRING_H

#include "format/platform_types.h"
#include "util/defines.h"
#include "util/to_string.h"

#include "vulkan/vulkan.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::string PNextToString(const void* pNext, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);

template <>
std::string ToString<SECURITY_ATTRIBUTES>(const SECURITY_ATTRIBUTES& obj,
                                          ToStringFlags              toStringFlags,
                                          uint32_t                   tabCount,
                                          uint32_t                   tabSize);

template <>
std::string ToString<VkAccelerationStructureGeometryKHR>(const VkAccelerationStructureGeometryKHR& obj,
                                                         ToStringFlags                             toStringFlags,
                                                         uint32_t                                  tabCount,
                                                         uint32_t                                  tabSize);

template <>
std::string ToString<VkAccelerationStructureMotionInstanceNV>(const VkAccelerationStructureMotionInstanceNV& obj,
                                                              ToStringFlags toStringFlags,
                                                              uint32_t      tabCount,
                                                              uint32_t      tabSize);

template <>
std::string ToString<VkClearColorValue>(const VkClearColorValue& obj,
                                        ToStringFlags            toStringFlags,
                                        uint32_t                 tabCount,
                                        uint32_t                 tabSize);

template <>
std::string
ToString<VkClearValue>(const VkClearValue& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);

template <>
std::string ToString<VkDescriptorImageInfo>(const VkDescriptorImageInfo& obj,
                                            ToStringFlags                toStringFlags,
                                            uint32_t                     tabCount,
                                            uint32_t                     tabSize);

template <>
std::string ToString<VkDeviceOrHostAddressConstKHR>(const VkDeviceOrHostAddressConstKHR& obj,
                                                    ToStringFlags                        toStringFlags,
                                                    uint32_t                             tabCount,
                                                    uint32_t                             tabSize);

template <>
std::string ToString<VkDeviceOrHostAddressKHR>(const VkDeviceOrHostAddressKHR& obj,
                                               ToStringFlags                   toStringFlags,
                                               uint32_t                        tabCount,
                                               uint32_t                        tabSize);

template <>
std::string ToString<VkLayerProperties>(const VkLayerProperties& obj,
                                        ToStringFlags            toStringFlags,
                                        uint32_t                 tabCount,
                                        uint32_t                 tabSize);

template <>
std::string ToString<VkPerformanceCounterResultKHR>(const VkPerformanceCounterResultKHR& obj,
                                                    ToStringFlags                        toStringFlags,
                                                    uint32_t                             tabCount,
                                                    uint32_t                             tabSize);

template <>
std::string ToString<VkPerformanceValueINTEL>(const VkPerformanceValueINTEL& obj,
                                              ToStringFlags                  toStringFlags,
                                              uint32_t                       tabCount,
                                              uint32_t                       tabSize);

template <>
std::string ToString<VkWriteDescriptorSet>(const VkWriteDescriptorSet& obj,
                                           ToStringFlags               toStringFlags,
                                           uint32_t                    tabCount,
                                           uint32_t                    tabSize);

template <typename VkHandleType>
inline std::string VkHandleToString(VkHandleType vkHandle)
{
    return vkHandle ? PtrToString(vkHandle) : "VK_NULL_HANDLE";
}

template <typename VkHandleType>
inline std::string VkHandleArrayToString(uint32_t            count,
                                         const VkHandleType* pVkHandles,
                                         ToStringFlags       toStringFlags = kToString_Default,
                                         uint32_t            tabCount      = 0,
                                         uint32_t            tabSize       = 4)
{
    return ArrayToString(
        count,
        pVkHandles,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pVkHandles != nullptr; },
        [&](uint32_t i) { return VkHandleToString(pVkHandles[i]); });
}

template <typename VkEnumType>
inline std::string VkEnumArrayToString(uint32_t          count,
                                       const VkEnumType* pVkEnums,
                                       ToStringFlags     toStringFlags = kToString_Default,
                                       uint32_t          tabCount      = 0,
                                       uint32_t          tabSize       = 4)
{
    return ArrayToString(
        count,
        pVkEnums,
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pVkEnums != nullptr; },
        [&](uint32_t i) { return "\"" + ToString(pVkEnums[i]) + "\""; });
}

template <typename VkBitmaskType>
inline std::string BitmaskToString(VkFlags vkFlags)
{
    std::string str;
    VkFlags     index = 0;
    while (vkFlags)
    {
        if (vkFlags & 1)
        {
            if (!str.empty())
            {
                str.append("|");
            }
            str.append(ToString(static_cast<VkBitmaskType>(1 << index)));
        }
        ++index;
        vkFlags >>= 1;
    }
    if (str.empty())
    {
        str.append(ToString(static_cast<VkBitmaskType>(0)));
    }
    return str;
}

inline std::string UIDToString(uint32_t uidSize, const uint8_t* pUid)
{
    std::stringstream strStrm;
    if (uidSize && pUid)
    {
        for (uint32_t i = 0; i < uidSize; ++i)
        {
            if (i)
            {
                strStrm << '-';
            }
            strStrm << std::to_string(pUid[i]);
        }
    }
    return strStrm.str();
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CUSTOM_VULKAN_TO_STRING_H
