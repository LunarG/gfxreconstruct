/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_CUSTOM_VULKAN_ARRAY_SIZE_2D_H
#define GFXRECON_ENCODE_CUSTOM_VULKAN_ARRAY_SIZE_2D_H

#include "format/platform_types.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

template <typename... T>
class ArraySize2D
{};

// Size of vkCmdBuildAccelerationStructuresKHR argument ppBuildRangeInfos
template <>
class ArraySize2D<VkCommandBuffer,
                  uint32_t,
                  const VkAccelerationStructureBuildGeometryInfoKHR*,
                  const VkAccelerationStructureBuildRangeInfoKHR* const*>
{
  public:
    ArraySize2D(VkCommandBuffer                                        commandBuffer,
                uint32_t                                               infoCount,
                const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
                const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) :
        size_(infoCount),
        infos_(pInfos){};
    size_t size() const { return size_; }
    size_t operator[](size_t i) const { return infos_[i].geometryCount; }

  private:
    const size_t                                       size_;
    const VkAccelerationStructureBuildGeometryInfoKHR* infos_;
};

// Size of vkCmdBuildAccelerationStructuresIndirectKHR argument ppMaxPrimitiveCounts
template <>
class ArraySize2D<VkCommandBuffer,
                  uint32_t,
                  const VkAccelerationStructureBuildGeometryInfoKHR*,
                  const VkDeviceAddress*,
                  const uint32_t*,
                  const uint32_t* const*>
{
  public:
    ArraySize2D(VkCommandBuffer                                    commandBuffer,
                uint32_t                                           infoCount,
                const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                const VkDeviceAddress*                             pIndirectDeviceAddresses,
                const uint32_t*                                    pIndirectStrides,
                const uint32_t* const*                             ppMaxPrimitiveCounts) :
        size_(infoCount),
        infos_(pInfos){};
    size_t size() const { return size_; }
    size_t operator[](size_t i) const { return infos_[i].geometryCount; }

  private:
    const size_t                                       size_;
    const VkAccelerationStructureBuildGeometryInfoKHR* infos_;
};

// Size of vkBuildAccelerationStructuresKHR argument ppBuildRangeInfos
template <>
class ArraySize2D<VkDevice,
                  VkDeferredOperationKHR,
                  uint32_t,
                  const VkAccelerationStructureBuildGeometryInfoKHR*,
                  const VkAccelerationStructureBuildRangeInfoKHR* const*>
{
  public:
    ArraySize2D(VkDevice                                               device,
                VkDeferredOperationKHR                                 deferredOperation,
                uint32_t                                               infoCount,
                const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
                const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) :
        size_(infoCount),
        infos_(pInfos){};
    size_t size() const { return size_; }
    size_t operator[](size_t i) const { return infos_[i].geometryCount; }

  private:
    const size_t                                       size_;
    const VkAccelerationStructureBuildGeometryInfoKHR* infos_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_VULKAN_ARRAY_SIZE_2D_H
