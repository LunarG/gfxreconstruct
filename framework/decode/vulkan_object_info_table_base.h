/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_OBJECT_MAPPER_BASE_H
#define GFXRECON_DECODE_VULKAN_OBJECT_MAPPER_BASE_H

#include "decode/vulkan_object_info.h"
#include "format/format.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <functional>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanObjectInfoTableBase
{
  protected:
    template <typename T>
    void AddVkObjectInfo(T&& info, std::unordered_map<format::HandleId, T>* map)
    {
        assert(map != nullptr);

        if ((info.capture_id != 0) && (info.handle != VK_NULL_HANDLE))
        {
            auto result = map->emplace(info.capture_id, std::forward<T>(info));

            if (!result.second)
            {
                // There are two expected cases where a capture ID would already be in the map. The first case is for
                // handles that are retrieved, such as VkPhysicalDevice, which can be processed more than once. For
                // this case we a have a duplicate info structure with the same ID and handle value, and do not need
                // to update the map entry. The existing entry may even contain additional info that would be lost if
                // replaced with this newly created, default initialized, info structure. The second case is for
                // temporary objects created during the trimmed file state setup. IDs may be reused when creating these
                // temporary objects, creating a case where we have a new handle that is not a duplicate of the existing
                // map entry. In this case, the map entry needs to be updated with the new object's info.
                auto iter = result.first;
                if (iter->second.handle != info.handle)
                {
                    iter->second = std::forward<T>(info);
                }
            }
        }
    }

    // Specialization template for SurfaceKHRInfo.
    //
    // Currently there is a workaround applied for Android apps that create more than 1 surface. For those apps there is
    // a command line option (--surface-index) with which the user can choose which of the surface to use, while the
    // rest simply will not be created at all. For those surfaces that are not created we still need the SurfaceKHRInfo
    // to be inserted in the map in order to be able to tell the difference whether the surface was not created because
    // of the said workaround or the user is passing a VK_NULL_HANDLE as a surface on purpose
    // (VK_GOOGLE_surfaceless_query).
    //
    // Once support for multiple Android surfaces is implemented and the workaround is
    // removed, this function should also be removed.
    //
    // Note: the "dummy" template parameter is here for the sole purpose of working around a gcc issue which does
    // not allow full specialization in non-namespace scope (https://gcc.gnu.org/bugzilla/show_bug.cgi?id=85282)
    template <typename dummy>
    void AddVkObjectInfo(VulkanSurfaceKHRInfo&& info, std::unordered_map<format::HandleId, VulkanSurfaceKHRInfo>* map)
    {
        assert(map != nullptr);

        if (info.capture_id != 0)
        {
            auto result = map->emplace(info.capture_id, std::forward<VulkanSurfaceKHRInfo>(info));

            if (!result.second)
            {
                // There are two expected cases where a capture ID would already be in the map. The first case is for
                // handles that are retrieved, such as VkPhysicalDevice, which can be processed more than once. For
                // this case we a have a duplicate info structure with the same ID and handle value, and do not need
                // to update the map entry. The existing entry may even contain additional info that would be lost if
                // replaced with this newly created, default initialized, info structure. The second case is for
                // temporary objects created during the trimmed file state setup. IDs may be reused when creating these
                // temporary objects, creating a case where we have a new handle that is not a duplicate of the existing
                // map entry. In this case, the map entry needs to be updated with the new object's info.
                auto iter = result.first;
                if (iter->second.handle != info.handle)
                {
                    iter->second = std::forward<VulkanSurfaceKHRInfo>(info);
                }
            }
        }
    }

    template <typename T>
    const T* GetVkObjectInfo(format::HandleId id, const std::unordered_map<format::HandleId, T>* map) const
    {
        assert(map != nullptr);

        const T* object_info = nullptr;

        if (id != 0)
        {
            const auto entry = map->find(id);

            if (entry != map->end())
            {
                object_info = &entry->second;
            }
        }

        return object_info;
    }

    template <typename T>
    T* GetVkObjectInfo(format::HandleId id, std::unordered_map<format::HandleId, T>* map)
    {
        assert(map != nullptr);

        T* object_info = nullptr;

        if (id != 0)
        {
            auto entry = map->find(id);

            if (entry != map->end())
            {
                object_info = &entry->second;
            }
        }

        return object_info;
    }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_OBJECT_MAPPER_BASE_H
