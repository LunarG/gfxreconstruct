/*
** Copyright (c) 2020-2023 LunarG, Inc.
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

#include "decode/vulkan_object_cleanup_util.h"

#include "decode/vulkan_resource_allocator.h"
#include "format/format.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(object_cleanup)

template <typename T>
void AddChildObject(std::unordered_map<format::HandleId, std::unordered_map<typename T::HandleType, const T*>>* objects,
                    const T*                                                                                    info)
{
    assert(objects != nullptr);
    (*objects)[info->parent_id].insert(std::make_pair(info->handle, info));
}

// ImageInfo specialization to filter swapchain images from the list of VkImage objects to destroy.
template <>
void AddChildObject<VulkanImageInfo>(
    std::unordered_map<format::HandleId, std::unordered_map<VkImage, const VulkanImageInfo*>>* objects,
    const VulkanImageInfo*                                                                     info)
{
    assert(objects != nullptr);

    if (!info->is_swapchain_image)
    {
        (*objects)[info->parent_id].insert(std::make_pair(info->handle, info));
    }
}

template <typename S, typename T>
void FreeChildObjects(CommonObjectInfoTable* table,
                      const std::string&     parent_type_name,
                      const std::string&     object_type_name,
                      bool                   remove_entries,
                      bool                   report_leaks,
                      S* (CommonObjectInfoTable::*GetParentInfoFunc)(format::HandleId),
                      void (CommonObjectInfoTable::*VisitFunc)(std::function<void(const T*)>) const,
                      void (CommonObjectInfoTable::*RemoveFunc)(format::HandleId),
                      std::function<void(const S*, const T*)> destroy_func)
{
    assert(table != nullptr);

    // Visit all table entries and sort them by parent ID.  Using unordered_map to filter duplicate handles.
    std::unordered_map<format::HandleId, std::unordered_map<typename T::HandleType, const T*>> objects;

    (table->*VisitFunc)([&](const T* info) { AddChildObject(&objects, info); });

    for (const auto& entry : objects)
    {
        auto parent_info = (table->*GetParentInfoFunc)(entry.first);

        if (parent_info != nullptr)
        {
            // Free resources.
            for (const auto& object_info : entry.second)
            {
                if (object_info.second != nullptr)
                {
                    destroy_func(parent_info, object_info.second);
                    if (remove_entries)
                    {
                        (table->*RemoveFunc)(object_info.second->capture_id);
                    }
                }
            }
        }
        else if (report_leaks)
        {
            GFXRECON_LOG_WARNING("Leaked %" PRIuPTR " %s objects allocated from %s ID %" PRIu64 " on exit",
                                 entry.second.size(),
                                 object_type_name.c_str(),
                                 parent_type_name.c_str(),
                                 entry.first);
        }
    }
}

template <typename T>
void FreeParentObjects(CommonObjectInfoTable* table,
                       bool                   remove_entries,
                       void (CommonObjectInfoTable::*VisitFunc)(std::function<void(const T*)>) const,
                       void (CommonObjectInfoTable::*RemoveFunc)(format::HandleId),
                       std::function<void(const T*)> destroy_func)
{
    assert(table != nullptr);

    std::unordered_map<typename T::HandleType, const T*> objects;

    (table->*VisitFunc)([&](const T* info) { objects.insert(std::make_pair(info->handle, info)); });

    for (const auto& entry : objects)
    {
        if (entry.second != nullptr)
        {
            destroy_func(entry.second);
            if (remove_entries)
            {
                (table->*RemoveFunc)(entry.second->capture_id);
            }
        }
    }
}

template <typename T>
void ClearObjects(CommonObjectInfoTable* table,
                  void (CommonObjectInfoTable::*VisitFunc)(std::function<void(const T*)>) const,
                  void (CommonObjectInfoTable::*RemoveFunc)(format::HandleId))
{
    assert(table != nullptr);

    std::vector<const T*> objects;

    (table->*VisitFunc)([&](const T* info) { objects.push_back(info); });

    for (const auto entry : objects)
    {
        if (entry != nullptr)
        {
            (table->*RemoveFunc)(entry->capture_id);
        }
    }
}

void FreeAllLiveObjects(CommonObjectInfoTable*                                         table,
                        bool                                                           remove_entries,
                        bool                                                           report_leaks,
                        std::function<const encode::VulkanInstanceTable*(const void*)> get_instance_table,
                        std::function<const encode::VulkanDeviceTable*(const void*)>   get_device_table,
                        VulkanSwapchain*                                               swapchain)
{
    FreeChildObjects<VulkanDeviceInfo, VulkanEventInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkEvent),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkEventInfo,
        &CommonObjectInfoTable::RemoveVkEventInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanEventInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyEvent(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanFenceInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkFence),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkFenceInfo,
        &CommonObjectInfoTable::RemoveVkFenceInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanFenceInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyFence(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanSemaphoreInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkSemaphore),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkSemaphoreInfo,
        &CommonObjectInfoTable::RemoveVkSemaphoreInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanSemaphoreInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroySemaphore(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanQueryPoolInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkQueryPool),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkQueryPoolInfo,
        &CommonObjectInfoTable::RemoveVkQueryPoolInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanQueryPoolInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyQueryPool(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanRenderPassInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkRenderPass),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkRenderPassInfo,
        &CommonObjectInfoTable::RemoveVkRenderPassInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanRenderPassInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyRenderPass(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanSamplerInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkSampler),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkSamplerInfo,
        &CommonObjectInfoTable::RemoveVkSamplerInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanSamplerInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroySampler(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanSamplerYcbcrConversionInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkSamplerYcbcrConversion),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkSamplerYcbcrConversionInfo,
        &CommonObjectInfoTable::RemoveVkSamplerYcbcrConversionInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanSamplerYcbcrConversionInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroySamplerYcbcrConversion(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanFramebufferInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkFramebuffer),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkFramebufferInfo,
        &CommonObjectInfoTable::RemoveVkFramebufferInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanFramebufferInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyFramebuffer(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanImageViewInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkImageView),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkImageViewInfo,
        &CommonObjectInfoTable::RemoveVkImageViewInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanImageViewInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyImageView(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanImageInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkImage),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkImageInfo,
        &CommonObjectInfoTable::RemoveVkImageInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanImageInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));

            auto allocator = parent_info->allocator.get();
            assert(allocator != nullptr);

            allocator->DestroyImage(object_info->handle, nullptr, object_info->allocator_data);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanBufferViewInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkBufferView),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkBufferViewInfo,
        &CommonObjectInfoTable::RemoveVkBufferViewInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanBufferViewInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyBufferView(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanBufferInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkBuffer),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkBufferInfo,
        &CommonObjectInfoTable::RemoveVkBufferInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanBufferInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));

            auto allocator = parent_info->allocator.get();
            assert(allocator != nullptr);

            allocator->DestroyBuffer(object_info->handle, nullptr, object_info->allocator_data);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanDeviceMemoryInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkDeviceMemory),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkDeviceMemoryInfo,
        &CommonObjectInfoTable::RemoveVkDeviceMemoryInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanDeviceMemoryInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));

            auto allocator = parent_info->allocator.get();
            assert(allocator != nullptr);

            allocator->FreeMemory(object_info->handle, nullptr, object_info->allocator_data);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanPipelineCacheInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkPipelineCache),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkPipelineCacheInfo,
        &CommonObjectInfoTable::RemoveVkPipelineCacheInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanPipelineCacheInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyPipelineCache(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanPipelineInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkPipeline),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkPipelineInfo,
        &CommonObjectInfoTable::RemoveVkPipelineInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanPipelineInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyPipeline(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanPipelineLayoutInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkPipelineLayout),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkPipelineLayoutInfo,
        &CommonObjectInfoTable::RemoveVkPipelineLayoutInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanPipelineLayoutInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyPipelineLayout(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanShaderModuleInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkShaderModule),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkShaderModuleInfo,
        &CommonObjectInfoTable::RemoveVkShaderModuleInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanShaderModuleInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyShaderModule(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanDescriptorSetLayoutInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkDescriptorSetLayout),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkDescriptorSetLayoutInfo,
        &CommonObjectInfoTable::RemoveVkDescriptorSetLayoutInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanDescriptorSetLayoutInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyDescriptorSetLayout(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanDescriptorUpdateTemplateInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkDescriptorUpdateTemplate),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkDescriptorUpdateTemplateInfo,
        &CommonObjectInfoTable::RemoveVkDescriptorUpdateTemplateInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanDescriptorUpdateTemplateInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyDescriptorUpdateTemplate(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanCommandPoolInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkCommandPool),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkCommandPoolInfo,
        &CommonObjectInfoTable::RemoveVkCommandPoolInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanCommandPoolInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyCommandPool(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanIndirectCommandsLayoutNVInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkIndirectCommandsLayoutNV),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkIndirectCommandsLayoutNVInfo,
        &CommonObjectInfoTable::RemoveVkIndirectCommandsLayoutNVInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanIndirectCommandsLayoutNVInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyIndirectCommandsLayoutNV(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanValidationCacheEXTInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkValidationCacheEXT),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkValidationCacheEXTInfo,
        &CommonObjectInfoTable::RemoveVkValidationCacheEXTInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanValidationCacheEXTInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyValidationCacheEXT(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanAccelerationStructureKHRInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkAccelerationStructureKHR),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkAccelerationStructureKHRInfo,
        &CommonObjectInfoTable::RemoveVkAccelerationStructureKHRInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanAccelerationStructureKHRInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyAccelerationStructureKHR(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanAccelerationStructureNVInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkAccelerationStructureNV),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkAccelerationStructureNVInfo,
        &CommonObjectInfoTable::RemoveVkAccelerationStructureNVInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanAccelerationStructureNVInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyAccelerationStructureNV(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanPerformanceConfigurationINTELInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkPerformanceConfigurationINTEL),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkPerformanceConfigurationINTELInfo,
        &CommonObjectInfoTable::RemoveVkPerformanceConfigurationINTELInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanPerformanceConfigurationINTELInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->ReleasePerformanceConfigurationINTEL(parent_info->handle, object_info->handle);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanDeferredOperationKHRInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkDeferredOperationKHR),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkDeferredOperationKHRInfo,
        &CommonObjectInfoTable::RemoveVkDeferredOperationKHRInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanDeferredOperationKHRInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyDeferredOperationKHR(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanDeviceInfo, VulkanPrivateDataSlotInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkPrivateDataSlotEXT),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkPrivateDataSlotInfo,
        &CommonObjectInfoTable::RemoveVkPrivateDataSlotInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanPrivateDataSlotInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyPrivateDataSlot(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanInstanceInfo, VulkanDebugReportCallbackEXTInfo>(
        table,
        GFXRECON_STR(VkInstance),
        GFXRECON_STR(VkDebugReportCallbackEXT),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkInstanceInfo,
        &CommonObjectInfoTable::VisitVkDebugReportCallbackEXTInfo,
        &CommonObjectInfoTable::RemoveVkDebugReportCallbackEXTInfo,
        [&](const VulkanInstanceInfo* parent_info, const VulkanDebugReportCallbackEXTInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_instance_table(parent_info->handle)
                ->DestroyDebugReportCallbackEXT(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<VulkanInstanceInfo, VulkanDebugUtilsMessengerEXTInfo>(
        table,
        GFXRECON_STR(VkInstance),
        GFXRECON_STR(VkDebugUtilsMessengerEXT),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkInstanceInfo,
        &CommonObjectInfoTable::VisitVkDebugUtilsMessengerEXTInfo,
        &CommonObjectInfoTable::RemoveVkDebugUtilsMessengerEXTInfo,
        [&](const VulkanInstanceInfo* parent_info, const VulkanDebugUtilsMessengerEXTInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_instance_table(parent_info->handle)
                ->DestroyDebugUtilsMessengerEXT(parent_info->handle, object_info->handle, nullptr);
        });

    // VKDescriptorPool objects have a special destroy function to destroy any retired descriptor pool objects that ran
    // out of memory during replay.
    FreeChildObjects<VulkanDeviceInfo, VulkanDescriptorPoolInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkDescriptorPool),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkDescriptorPoolInfo,
        &CommonObjectInfoTable::RemoveVkDescriptorPoolInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanDescriptorPoolInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));

            for (auto retired_pool : object_info->retired_pools)
            {
                get_device_table(parent_info->handle)
                    ->DestroyDescriptorPool(parent_info->handle, retired_pool, nullptr);
            }

            get_device_table(parent_info->handle)
                ->DestroyDescriptorPool(parent_info->handle, object_info->handle, nullptr);
        });

    // VkSwapchainKHR objects have a special destroy function to ignore the object when it has a null surface handle.
    // A valid swapchain object was not created in this case.
    FreeChildObjects<VulkanDeviceInfo, VulkanSwapchainKHRInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkSwapchainKHR),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkDeviceInfo,
        &CommonObjectInfoTable::VisitVkSwapchainKHRInfo,
        &CommonObjectInfoTable::RemoveVkSwapchainKHRInfo,
        [&](const VulkanDeviceInfo* parent_info, const VulkanSwapchainKHRInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            if (object_info->surface != VK_NULL_HANDLE)
            {
                swapchain->DestroySwapchainKHR(
                    get_device_table(parent_info->handle)->DestroySwapchainKHR, parent_info, object_info, nullptr);
            }
            else
            {
                // Destroy placeholder images that were created in place of a valid swapchain.
                auto allocator = parent_info->allocator.get();
                assert(allocator != nullptr);

                for (const VulkanImageInfo& image_info : object_info->image_infos)
                {
                    allocator->DestroyImageDirect(image_info.handle, nullptr, image_info.allocator_data);
                    allocator->FreeMemoryDirect(image_info.memory, nullptr, image_info.memory_allocator_data);
                }
            }
        });

    // VkSurfaceKHR objects have a special destroy function to destroy the object through the Window object that
    // initially created it.
    FreeChildObjects<VulkanInstanceInfo, VulkanSurfaceKHRInfo>(
        table,
        GFXRECON_STR(VkInstance),
        GFXRECON_STR(VkSurfaceKHR),
        remove_entries,
        report_leaks,
        &CommonObjectInfoTable::GetVkInstanceInfo,
        &CommonObjectInfoTable::VisitVkSurfaceKHRInfo,
        &CommonObjectInfoTable::RemoveVkSurfaceKHRInfo,
        [&](const VulkanInstanceInfo* parent_info, const VulkanSurfaceKHRInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            auto table = get_instance_table(parent_info->handle);
            swapchain->DestroySurface(table->DestroySurfaceKHR, parent_info, object_info, nullptr);
        });

    FreeParentObjects<VulkanDeviceInfo>(table,
                                        remove_entries,
                                        &CommonObjectInfoTable::VisitVkDeviceInfo,
                                        &CommonObjectInfoTable::RemoveVkDeviceInfo,
                                        [&](const VulkanDeviceInfo* object_info) {
                                            assert(object_info != nullptr);
                                            object_info->allocator->Destroy();
                                            auto table = get_device_table(object_info->handle);
                                            table->DestroyDevice(object_info->handle, nullptr);
                                        });

    // Remove the objects that are not destroyed from the table.
    if (remove_entries)
    {
        // The following object types are not processed because they are retrieved handles without destroy functions.
        //   VkPhysicalDevice
        //   VkQueue
        //   VkDisplayKHR
        //   VkDisplayModeKHR
        //
        // The following object types are not processed because they are implicitly freed when their pool/parent is
        // destroyed.
        //   VkCommandBuffer
        //   VkDescriptorSet
        //   VkImage objects that were retrieved from a VkSwapchainKHR object

        ClearObjects<VulkanPhysicalDeviceInfo>(table,
                                               &CommonObjectInfoTable::VisitVkPhysicalDeviceInfo,
                                               &CommonObjectInfoTable::RemoveVkPhysicalDeviceInfo);
        ClearObjects<VulkanQueueInfo>(
            table, &CommonObjectInfoTable::VisitVkQueueInfo, &CommonObjectInfoTable::RemoveVkQueueInfo);
        ClearObjects<VulkanDisplayKHRInfo>(
            table, &CommonObjectInfoTable::VisitVkDisplayKHRInfo, &CommonObjectInfoTable::RemoveVkDisplayKHRInfo);
        ClearObjects<VulkanDisplayModeKHRInfo>(table,
                                               &CommonObjectInfoTable::VisitVkDisplayModeKHRInfo,
                                               &CommonObjectInfoTable::RemoveVkDisplayModeKHRInfo);
        ClearObjects<VulkanCommandBufferInfo>(
            table, &CommonObjectInfoTable::VisitVkCommandBufferInfo, &CommonObjectInfoTable::RemoveVkCommandBufferInfo);
        ClearObjects<VulkanDescriptorSetInfo>(
            table, &CommonObjectInfoTable::VisitVkDescriptorSetInfo, &CommonObjectInfoTable::RemoveVkDescriptorSetInfo);

        // Clear the remaining swap chain images.
        ClearObjects<VulkanImageInfo>(
            table, &CommonObjectInfoTable::VisitVkImageInfo, &CommonObjectInfoTable::RemoveVkImageInfo);
    }
}

void FreeAllLiveInstances(CommonObjectInfoTable*                                         table,
                          bool                                                           remove_entries,
                          bool                                                           report_leaks,
                          std::function<const encode::VulkanInstanceTable*(const void*)> get_instance_table,
                          std::function<const encode::VulkanDeviceTable*(const void*)>   get_device_table)
{
    FreeParentObjects<VulkanInstanceInfo>(table,
                                          remove_entries,
                                          &CommonObjectInfoTable::VisitVkInstanceInfo,
                                          &CommonObjectInfoTable::RemoveVkInstanceInfo,
                                          [&](const VulkanInstanceInfo* object_info) {
                                              assert(object_info != nullptr);
                                              auto table = get_instance_table(object_info->handle);
                                              table->DestroyInstance(object_info->handle, nullptr);
                                          });
}

GFXRECON_END_NAMESPACE(object_cleanup)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
