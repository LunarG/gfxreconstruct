/*
** Copyright (c) 2024 Valve Corporation
** Copyright (c) 2024 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_MARKING_LAYER_H
#define GFXRECON_UTIL_MARKING_LAYER_H

#include "vulkan/vulkan.h"
#include "util/defines.h"
#include "format/format.h"

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_object_info_table.h"

#include <string>
#include <set>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

typedef void MarkInjectedCallback(void*);
struct MarkInjectedCallbacks
{
    void*                 user_data;
    MarkInjectedCallback* begin_injected = nullptr;
    MarkInjectedCallback* end_injected   = nullptr;
};

class MarkingLayersUtil
{
  public:
    static MarkingLayersUtil& instance()
    {
        static MarkingLayersUtil instance;
        return instance;
    }

    template <typename T>
    void BeginInjected(const decode::VulkanObjectInfo<T>* info, const std::string& file = "", int line = 0)
    {
        if constexpr (is_debug_)
        {
            if (!scope_closed_)
            {
                GFXRECON_LOG_FATAL("Marking was not closed, previous begin call at %s, %s", file_.c_str(), line_);
                GFXRECON_ASSERT(false);
            }
            file_         = file;
            line_         = line;
            scope_closed_ = false;
        }

        callbacks_it_t entries = Callbacks(info);
        if (entries == callbacks_.end())
        {
            return;
        }

        for (const MarkInjectedCallbacks& callback : entries->second)
        {
            callback.begin_injected(callback.user_data);
        }
    }

    template <typename T>
    void EndInjected(const decode::VulkanObjectInfo<T>* info)
    {
        if constexpr (is_debug_)
        {
            scope_closed_ = true;
        }

        MarkingLayersUtil::callbacks_it_t entries = Callbacks(info);
        if (entries == callbacks_.end())
        {
            return;
        }

        for (const MarkInjectedCallbacks& callback : entries->second)
        {
            callback.end_injected(callback.user_data);
        }
    }

    void AddCallbacks(format::HandleId physical_device_id, const VkPhysicalDeviceToolProperties& tool_properties)
    {
        // Do not add callbacks for the layers that were not enabled by the respective argument
        if (layer_names_.count(tool_properties.layer) == 0)
        {
            return;
        }
        GFXRECON_LOG_DEBUG(
            "Adding a %s layer callbacks from physical device %" PRIu64, tool_properties.layer, physical_device_id);
        callbacks_[physical_device_id].emplace_back(*reinterpret_cast<MarkInjectedCallbacks*>(tool_properties.pNext));
    }

    void SetInfoTable(const decode::VulkanObjectInfoTable* object_info_table)
    {
        object_info_table_ = object_info_table;
    }

    void AddLayerName(std::string_view name) { layer_names_.insert(name); }

  private:
    using callbacks_it_t = std::unordered_map<format::HandleId, std::vector<MarkInjectedCallbacks>>::iterator;

  private:
    MarkingLayersUtil() = default;

    callbacks_it_t Callbacks(format::HandleId physical_device_id) { return callbacks_.find(physical_device_id); }

    template <typename T>
    callbacks_it_t Callbacks(const decode::VulkanObjectInfo<T>* info)
    {
        const decode::DeviceInfo* device_info = object_info_table_->GetDeviceInfo(info->parent_id);
        return Callbacks(device_info->parent_id);
    }
    MarkingLayersUtil::callbacks_it_t Callbacks(const decode::VulkanObjectInfo<VkDevice>* info)
    {
        return Callbacks(info->parent_id);
    }

    MarkingLayersUtil::callbacks_it_t Callbacks(const decode::VulkanObjectInfo<VkPhysicalDevice>* info)
    {
        return Callbacks(info->capture_id);
    }

  private:
    std::set<std::string_view>                                               layer_names_;
    std::unordered_map<format::HandleId, std::vector<MarkInjectedCallbacks>> callbacks_;
    const decode::VulkanObjectInfoTable*                                     object_info_table_{ nullptr };

    bool        scope_closed_{ true };
    std::string file_;
    int         line_;

#ifdef NDEBUG
    static const bool is_debug_ = false;
#else
    static const bool is_debug_ = true;
#endif
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif