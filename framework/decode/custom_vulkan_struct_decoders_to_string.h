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

#ifndef GFXRECON_CUSTOM_VULKAN_STRUCT_DECODERS_TO_STRING_H
#define GFXRECON_CUSTOM_VULKAN_STRUCT_DECODERS_TO_STRING_H

#include "custom_vulkan_to_string.h"
#include "custom_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "format/platform_types.h"
#include "util/defines.h"
#include "util/to_string.h"

#include "vulkan/vulkan.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::string PNextDecodedToString(const decode::PNextNode* pNext, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);

template <>
std::string ToString<decode::Decoded_SECURITY_ATTRIBUTES>(const decode::Decoded_SECURITY_ATTRIBUTES& obj,
                                          ToStringFlags              toStringFlags,
                                          uint32_t                   tabCount,
                                          uint32_t                   tabSize);


template <>
std::string ToString<decode::Decoded_VkAccelerationStructureGeometryKHR>(const decode::Decoded_VkAccelerationStructureGeometryKHR& obj,
                                                         ToStringFlags                             toStringFlags,
                                                         uint32_t                                  tabCount,
                                                         uint32_t                                  tabSize);

template <>
std::string ToString<decode::Decoded_VkAccelerationStructureMotionInstanceNV>(const decode::Decoded_VkAccelerationStructureMotionInstanceNV& obj,
                                                              ToStringFlags toStringFlags,
                                                              uint32_t      tabCount,
                                                              uint32_t      tabSize);

// Dispatch to the raw vulkan version as there are no pNexts or handles reachable through this.
template <>
inline std::string ToString<decode::Decoded_VkClearColorValue>(const decode::Decoded_VkClearColorValue& obj,
                                        ToStringFlags            toStringFlags,
                                        uint32_t                 tabCount,
                                        uint32_t                 tabSize)
{
    assert(obj.decoded_value);
    if(obj.decoded_value)
    {
        return ToString<VkClearColorValue>(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "";
}

// Dispatch to the raw vulkan version as there are no pNexts or handles reachable through this.
template <>
inline std::string ToString<decode::Decoded_VkClearValue>(const decode::Decoded_VkClearValue& obj, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    assert(obj.decoded_value);
    if(obj.decoded_value)
    {
        return ToString<VkClearValue>(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "";
}

template <>
std::string ToString<decode::Decoded_VkDescriptorImageInfo>(const decode::Decoded_VkDescriptorImageInfo& obj,
                                            ToStringFlags                toStringFlags,
                                            uint32_t                     tabCount,
                                            uint32_t                     tabSize);


template <>
inline std::string ToString<decode::Decoded_VkDeviceOrHostAddressConstKHR>(const decode::Decoded_VkDeviceOrHostAddressConstKHR& obj,
                                                    ToStringFlags                        toStringFlags,
                                                    uint32_t                             tabCount,
                                                    uint32_t                             tabSize)
{
    assert(obj.decoded_value);
    if(obj.decoded_value)
    {
        return ToString(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "";
}

template <> 
inline std::string ToString<decode::Decoded_VkDeviceOrHostAddressKHR>(const decode::Decoded_VkDeviceOrHostAddressKHR& obj,
                                               ToStringFlags                   toStringFlags,
                                               uint32_t                        tabCount,
                                               uint32_t                        tabSize)
{
    assert(obj.decoded_value);
    if(obj.decoded_value)
    {
        return ToString(*obj.decoded_value, toStringFlags, tabCount, tabSize);
    }
    return "";
}

template <>
std::string ToString<decode::Decoded_VkLayerProperties>(const decode::Decoded_VkLayerProperties& obj,
                                        ToStringFlags            toStringFlags,
                                        uint32_t                 tabCount,
                                        uint32_t                 tabSize);
template <>
std::string ToString<decode::Decoded_VkPerformanceValueINTEL>(const decode::Decoded_VkPerformanceValueINTEL& obj,
                                              ToStringFlags                  toStringFlags,
                                              uint32_t                       tabCount,
                                              uint32_t                       tabSize);

template <>
std::string ToString<decode::Decoded_VkWriteDescriptorSet>(const decode::Decoded_VkWriteDescriptorSet& obj,
                                           ToStringFlags               toStringFlags,
                                           uint32_t                    tabCount,
                                           uint32_t                    tabSize);

template <typename VkHandleType>
inline std::string VkHandleArrayToString(const decode::HandlePointerDecoder<VkHandleType>& pHandles,
                                         ToStringFlags       toStringFlags = kToString_Default,
                                         uint32_t            tabCount      = 0,
                                         uint32_t            tabSize       = 4)
{
    return ArrayToString(
        pHandles.GetLength(),
        pHandles.GetPointer(),
        toStringFlags,
        tabCount,
        tabSize,
        [&]() { return pHandles.GetPointer() != nullptr; },
        [&](uint32_t i) { return VkHandleToString(pHandles.GetPointer()[i]); });
}


GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CUSTOM_VULKAN_STRUCT_DECODERS_TO_STRING_H
