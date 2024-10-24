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
void AddChildObject<ImageInfo>(
    std::unordered_map<format::HandleId, std::unordered_map<VkImage, const ImageInfo*>>* objects, const ImageInfo* info)
{
    assert(objects != nullptr);

    if (!info->is_swapchain_image)
    {
        (*objects)[info->parent_id].insert(std::make_pair(info->handle, info));
    }
}

template <typename S, typename T>
void FreeChildObjects(VulkanObjectInfoTable* table,
                      const std::string&     parent_type_name,
                      const std::string&     object_type_name,
                      bool                   remove_entries,
                      bool                   report_leaks,
                      S* (VulkanObjectInfoTable::*GetParentInfoFunc)(format::HandleId),
                      void (VulkanObjectInfoTable::*VisitFunc)(std::function<void(const T*)>) const,
                      void (VulkanObjectInfoTable::*RemoveFunc)(format::HandleId),
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
void FreeParentObjects(VulkanObjectInfoTable* table,
                       bool                   remove_entries,
                       void (VulkanObjectInfoTable::*VisitFunc)(std::function<void(const T*)>) const,
                       void (VulkanObjectInfoTable::*RemoveFunc)(format::HandleId),
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
void ClearObjects(VulkanObjectInfoTable* table,
                  void (VulkanObjectInfoTable::*VisitFunc)(std::function<void(const T*)>) const,
                  void (VulkanObjectInfoTable::*RemoveFunc)(format::HandleId))
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

void FreeAllLiveObjects(VulkanObjectInfoTable*                                         table,
                        bool                                                           remove_entries,
                        bool                                                           report_leaks,
                        std::function<const encode::VulkanInstanceTable*(const void*)> get_instance_table,
                        std::function<const encode::VulkanDeviceTable*(const void*)>   get_device_table,
                        VulkanSwapchain*                                               swapchain)
{
    FreeChildObjects<DeviceInfo, EventInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkEvent),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitEventInfo,
        &VulkanObjectInfoTable::RemoveEventInfo,
        [&](const DeviceInfo* parent_info, const EventInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyEvent(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, FenceInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkFence),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitFenceInfo,
        &VulkanObjectInfoTable::RemoveFenceInfo,
        [&](const DeviceInfo* parent_info, const FenceInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyFence(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, SemaphoreInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkSemaphore),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitSemaphoreInfo,
        &VulkanObjectInfoTable::RemoveSemaphoreInfo,
        [&](const DeviceInfo* parent_info, const SemaphoreInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroySemaphore(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, QueryPoolInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkQueryPool),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitQueryPoolInfo,
        &VulkanObjectInfoTable::RemoveQueryPoolInfo,
        [&](const DeviceInfo* parent_info, const QueryPoolInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyQueryPool(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, RenderPassInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkRenderPass),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitRenderPassInfo,
        &VulkanObjectInfoTable::RemoveRenderPassInfo,
        [&](const DeviceInfo* parent_info, const RenderPassInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyRenderPass(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, SamplerInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkSampler),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitSamplerInfo,
        &VulkanObjectInfoTable::RemoveSamplerInfo,
        [&](const DeviceInfo* parent_info, const SamplerInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroySampler(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, SamplerYcbcrConversionInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkSamplerYcbcrConversion),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitSamplerYcbcrConversionInfo,
        &VulkanObjectInfoTable::RemoveSamplerYcbcrConversionInfo,
        [&](const DeviceInfo* parent_info, const SamplerYcbcrConversionInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroySamplerYcbcrConversion(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, FramebufferInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkFramebuffer),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitFramebufferInfo,
        &VulkanObjectInfoTable::RemoveFramebufferInfo,
        [&](const DeviceInfo* parent_info, const FramebufferInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyFramebuffer(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, ImageViewInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkImageView),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitImageViewInfo,
        &VulkanObjectInfoTable::RemoveImageViewInfo,
        [&](const DeviceInfo* parent_info, const ImageViewInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyImageView(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, ImageInfo>(table,
                                            GFXRECON_STR(VkDevice),
                                            GFXRECON_STR(VkImage),
                                            remove_entries,
                                            report_leaks,
                                            &VulkanObjectInfoTable::GetDeviceInfo,
                                            &VulkanObjectInfoTable::VisitImageInfo,
                                            &VulkanObjectInfoTable::RemoveImageInfo,
                                            [&](const DeviceInfo* parent_info, const ImageInfo* object_info) {
                                                assert((parent_info != nullptr) && (object_info != nullptr));

                                                auto allocator = parent_info->allocator.get();
                                                assert(allocator != nullptr);

                                                allocator->DestroyImage(
                                                    object_info->handle, nullptr, object_info->allocator_data);
                                            });

    FreeChildObjects<DeviceInfo, BufferViewInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkBufferView),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitBufferViewInfo,
        &VulkanObjectInfoTable::RemoveBufferViewInfo,
        [&](const DeviceInfo* parent_info, const BufferViewInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyBufferView(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, BufferInfo>(table,
                                             GFXRECON_STR(VkDevice),
                                             GFXRECON_STR(VkBuffer),
                                             remove_entries,
                                             report_leaks,
                                             &VulkanObjectInfoTable::GetDeviceInfo,
                                             &VulkanObjectInfoTable::VisitBufferInfo,
                                             &VulkanObjectInfoTable::RemoveBufferInfo,
                                             [&](const DeviceInfo* parent_info, const BufferInfo* object_info) {
                                                 assert((parent_info != nullptr) && (object_info != nullptr));

                                                 auto allocator = parent_info->allocator.get();
                                                 assert(allocator != nullptr);

                                                 allocator->DestroyBuffer(
                                                     object_info->handle, nullptr, object_info->allocator_data);
                                             });

    FreeChildObjects<DeviceInfo, DeviceMemoryInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkDeviceMemory),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitDeviceMemoryInfo,
        &VulkanObjectInfoTable::RemoveDeviceMemoryInfo,
        [&](const DeviceInfo* parent_info, const DeviceMemoryInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));

            auto allocator = parent_info->allocator.get();
            assert(allocator != nullptr);

            allocator->FreeMemory(object_info->handle, nullptr, object_info->allocator_data);
        });

    FreeChildObjects<DeviceInfo, PipelineCacheInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkPipelineCache),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitPipelineCacheInfo,
        &VulkanObjectInfoTable::RemovePipelineCacheInfo,
        [&](const DeviceInfo* parent_info, const PipelineCacheInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyPipelineCache(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, PipelineInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkPipeline),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitPipelineInfo,
        &VulkanObjectInfoTable::RemovePipelineInfo,
        [&](const DeviceInfo* parent_info, const PipelineInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)->DestroyPipeline(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, PipelineLayoutInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkPipelineLayout),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitPipelineLayoutInfo,
        &VulkanObjectInfoTable::RemovePipelineLayoutInfo,
        [&](const DeviceInfo* parent_info, const PipelineLayoutInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyPipelineLayout(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, ShaderModuleInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkShaderModule),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitShaderModuleInfo,
        &VulkanObjectInfoTable::RemoveShaderModuleInfo,
        [&](const DeviceInfo* parent_info, const ShaderModuleInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyShaderModule(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, DescriptorSetLayoutInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkDescriptorSetLayout),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitDescriptorSetLayoutInfo,
        &VulkanObjectInfoTable::RemoveDescriptorSetLayoutInfo,
        [&](const DeviceInfo* parent_info, const DescriptorSetLayoutInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyDescriptorSetLayout(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, DescriptorUpdateTemplateInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkDescriptorUpdateTemplate),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitDescriptorUpdateTemplateInfo,
        &VulkanObjectInfoTable::RemoveDescriptorUpdateTemplateInfo,
        [&](const DeviceInfo* parent_info, const DescriptorUpdateTemplateInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyDescriptorUpdateTemplate(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, CommandPoolInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkCommandPool),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitCommandPoolInfo,
        &VulkanObjectInfoTable::RemoveCommandPoolInfo,
        [&](const DeviceInfo* parent_info, const CommandPoolInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyCommandPool(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, IndirectCommandsLayoutNVInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkIndirectCommandsLayoutNV),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitIndirectCommandsLayoutNVInfo,
        &VulkanObjectInfoTable::RemoveIndirectCommandsLayoutNVInfo,
        [&](const DeviceInfo* parent_info, const IndirectCommandsLayoutNVInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyIndirectCommandsLayoutNV(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, ValidationCacheEXTInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkValidationCacheEXT),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitValidationCacheEXTInfo,
        &VulkanObjectInfoTable::RemoveValidationCacheEXTInfo,
        [&](const DeviceInfo* parent_info, const ValidationCacheEXTInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyValidationCacheEXT(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, AccelerationStructureKHRInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkAccelerationStructureKHR),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitAccelerationStructureKHRInfo,
        &VulkanObjectInfoTable::RemoveAccelerationStructureKHRInfo,
        [&](const DeviceInfo* parent_info, const AccelerationStructureKHRInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyAccelerationStructureKHR(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, AccelerationStructureNVInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkAccelerationStructureNV),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitAccelerationStructureNVInfo,
        &VulkanObjectInfoTable::RemoveAccelerationStructureNVInfo,
        [&](const DeviceInfo* parent_info, const AccelerationStructureNVInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyAccelerationStructureNV(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, PerformanceConfigurationINTELInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkPerformanceConfigurationINTEL),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitPerformanceConfigurationINTELInfo,
        &VulkanObjectInfoTable::RemovePerformanceConfigurationINTELInfo,
        [&](const DeviceInfo* parent_info, const PerformanceConfigurationINTELInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->ReleasePerformanceConfigurationINTEL(parent_info->handle, object_info->handle);
        });

    FreeChildObjects<DeviceInfo, DeferredOperationKHRInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkDeferredOperationKHR),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitDeferredOperationKHRInfo,
        &VulkanObjectInfoTable::RemoveDeferredOperationKHRInfo,
        [&](const DeviceInfo* parent_info, const DeferredOperationKHRInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyDeferredOperationKHR(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<DeviceInfo, PrivateDataSlotInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkPrivateDataSlotEXT),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitPrivateDataSlotInfo,
        &VulkanObjectInfoTable::RemovePrivateDataSlotInfo,
        [&](const DeviceInfo* parent_info, const PrivateDataSlotInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_device_table(parent_info->handle)
                ->DestroyPrivateDataSlot(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<InstanceInfo, DebugReportCallbackEXTInfo>(
        table,
        GFXRECON_STR(VkInstance),
        GFXRECON_STR(VkDebugReportCallbackEXT),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetInstanceInfo,
        &VulkanObjectInfoTable::VisitDebugReportCallbackEXTInfo,
        &VulkanObjectInfoTable::RemoveDebugReportCallbackEXTInfo,
        [&](const InstanceInfo* parent_info, const DebugReportCallbackEXTInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_instance_table(parent_info->handle)
                ->DestroyDebugReportCallbackEXT(parent_info->handle, object_info->handle, nullptr);
        });

    FreeChildObjects<InstanceInfo, DebugUtilsMessengerEXTInfo>(
        table,
        GFXRECON_STR(VkInstance),
        GFXRECON_STR(VkDebugUtilsMessengerEXT),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetInstanceInfo,
        &VulkanObjectInfoTable::VisitDebugUtilsMessengerEXTInfo,
        &VulkanObjectInfoTable::RemoveDebugUtilsMessengerEXTInfo,
        [&](const InstanceInfo* parent_info, const DebugUtilsMessengerEXTInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            get_instance_table(parent_info->handle)
                ->DestroyDebugUtilsMessengerEXT(parent_info->handle, object_info->handle, nullptr);
        });

    // VKDescriptorPool objects have a special destroy function to destroy any retired descriptor pool objects that ran
    // out of memory during replay.
    FreeChildObjects<DeviceInfo, DescriptorPoolInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkDescriptorPool),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitDescriptorPoolInfo,
        &VulkanObjectInfoTable::RemoveDescriptorPoolInfo,
        [&](const DeviceInfo* parent_info, const DescriptorPoolInfo* object_info) {
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
    FreeChildObjects<DeviceInfo, SwapchainKHRInfo>(
        table,
        GFXRECON_STR(VkDevice),
        GFXRECON_STR(VkSwapchainKHR),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetDeviceInfo,
        &VulkanObjectInfoTable::VisitSwapchainKHRInfo,
        &VulkanObjectInfoTable::RemoveSwapchainKHRInfo,
        [&](const DeviceInfo* parent_info, const SwapchainKHRInfo* object_info) {
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

                for (const ImageInfo& image_info : object_info->image_infos)
                {
                    allocator->DestroyImageDirect(image_info.handle, nullptr, image_info.allocator_data);
                    allocator->FreeMemoryDirect(image_info.memory, nullptr, image_info.memory_allocator_data);
                }
            }
        });

    // VkSurfaceKHR objects have a special destroy function to destroy the object through the Window object that
    // initially created it.
    FreeChildObjects<InstanceInfo, SurfaceKHRInfo>(
        table,
        GFXRECON_STR(VkInstance),
        GFXRECON_STR(VkSurfaceKHR),
        remove_entries,
        report_leaks,
        &VulkanObjectInfoTable::GetInstanceInfo,
        &VulkanObjectInfoTable::VisitSurfaceKHRInfo,
        &VulkanObjectInfoTable::RemoveSurfaceKHRInfo,
        [&](const InstanceInfo* parent_info, const SurfaceKHRInfo* object_info) {
            assert((parent_info != nullptr) && (object_info != nullptr));
            auto table = get_instance_table(parent_info->handle);
            swapchain->DestroySurface(table->DestroySurfaceKHR, parent_info, object_info, nullptr);
        });

    FreeParentObjects<DeviceInfo>(table,
                                  remove_entries,
                                  &VulkanObjectInfoTable::VisitDeviceInfo,
                                  &VulkanObjectInfoTable::RemoveDeviceInfo,
                                  [&](const DeviceInfo* object_info) {
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

        ClearObjects<PhysicalDeviceInfo>(
            table, &VulkanObjectInfoTable::VisitPhysicalDeviceInfo, &VulkanObjectInfoTable::RemovePhysicalDeviceInfo);
        ClearObjects<QueueInfo>(table, &VulkanObjectInfoTable::VisitQueueInfo, &VulkanObjectInfoTable::RemoveQueueInfo);
        ClearObjects<DisplayKHRInfo>(
            table, &VulkanObjectInfoTable::VisitDisplayKHRInfo, &VulkanObjectInfoTable::RemoveDisplayKHRInfo);
        ClearObjects<DisplayModeKHRInfo>(
            table, &VulkanObjectInfoTable::VisitDisplayModeKHRInfo, &VulkanObjectInfoTable::RemoveDisplayModeKHRInfo);
        ClearObjects<CommandBufferInfo>(
            table, &VulkanObjectInfoTable::VisitCommandBufferInfo, &VulkanObjectInfoTable::RemoveCommandBufferInfo);
        ClearObjects<DescriptorSetInfo>(
            table, &VulkanObjectInfoTable::VisitDescriptorSetInfo, &VulkanObjectInfoTable::RemoveDescriptorSetInfo);

        // Clear the remaining swap chain images.
        ClearObjects<ImageInfo>(table, &VulkanObjectInfoTable::VisitImageInfo, &VulkanObjectInfoTable::RemoveImageInfo);
    }
}

void FreeAllLiveInstances(VulkanObjectInfoTable*                                         table,
                          bool                                                           remove_entries,
                          bool                                                           report_leaks,
                          std::function<const encode::VulkanInstanceTable*(const void*)> get_instance_table,
                          std::function<const encode::VulkanDeviceTable*(const void*)>   get_device_table)
{
    FreeParentObjects<InstanceInfo>(table,
                                    remove_entries,
                                    &VulkanObjectInfoTable::VisitInstanceInfo,
                                    &VulkanObjectInfoTable::RemoveInstanceInfo,
                                    [&](const InstanceInfo* object_info) {
                                        assert(object_info != nullptr);
                                        auto table = get_instance_table(object_info->handle);
                                        table->DestroyInstance(object_info->handle, nullptr);
                                    });
}

GFXRECON_END_NAMESPACE(object_cleanup)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
