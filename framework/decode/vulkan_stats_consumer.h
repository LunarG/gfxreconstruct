/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_VULKAN_STAT_CONSUMER_H
#define GFXRECON_DECODE_VULKAN_STAT_CONSUMER_H

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/api_decoder.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <set>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanStatsConsumer : public gfxrecon::decode::VulkanConsumer
{
  public:
    uint32_t           GetTrimmedStartFrame() const { return trimmed_frame_; }
    const std::string& GetAppName() const { return app_name_; }
    uint32_t           GetAppVersion() const { return app_version_; }
    const std::string& GetEngineName() const { return engine_name_; }
    uint32_t           GetEngineVersion() const { return engine_version_; }
    uint32_t           GetApiVersion() const { return api_version_; }
    uint64_t           GetGraphicsPipelineCount() const { return graphics_pipelines_; }
    uint64_t           GetComputePipelineCount() const { return compute_pipelines_; }
    uint64_t           GetRayTracingPipelineCount() const { return raytracing_pipelines_; }
    uint64_t           GetDrawCount() const { return draw_count_; }
    uint64_t           GetDispatchCount() const { return dispatch_count_; }
    uint64_t           GetAllocationCount() const { return allocation_count_; }
    uint64_t           GetMinAllocationSize() const { return min_allocation_size_; }
    uint64_t           GetMaxAllocationSize() const { return max_allocation_size_; }

    const std::set<gfxrecon::format::HandleId>& GetInstantiatedDevices() const { return used_physical_devices_; }
    const VkPhysicalDeviceProperties*           GetDeviceProperties(gfxrecon::format::HandleId id) const
    {
        auto entry = physical_device_properties_.find(id);
        if (entry != physical_device_properties_.end())
        {
            return &entry->second;
        }

        return nullptr;
    }

    virtual void ProcessStateBeginMarker(uint64_t frame_number) override
    {
        // Theres should only be one of these in a capture file.
        trimmed_frame_ = static_cast<uint32_t>(frame_number);
    }

    virtual void Process_vkCreateInstance(
        const gfxrecon::decode::ApiCallInfo&                                                    call_info,
        VkResult                                                                                returnValue,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkInstanceCreateInfo>* pCreateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkInstance>*) override
    {
        if ((pCreateInfo != nullptr) && (returnValue >= 0) && !pCreateInfo->IsNull())
        {
            auto create_info = pCreateInfo->GetPointer();
            auto app_info    = create_info->pApplicationInfo;
            if (app_info != nullptr)
            {
                if (app_info->pApplicationName != nullptr)
                {
                    app_name_ = app_info->pApplicationName;
                }

                if (app_info->pEngineName != nullptr)
                {
                    engine_name_ = app_info->pEngineName;
                }

                app_version_    = app_info->applicationVersion;
                engine_version_ = app_info->engineVersion;
                api_version_    = app_info->apiVersion;
            }
        }
    }

    virtual void Process_vkGetPhysicalDeviceProperties(
        const gfxrecon::decode::ApiCallInfo&                                                          call_info,
        gfxrecon::format::HandleId                                                                    physicalDevice,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkPhysicalDeviceProperties>* pProperties)
        override
    {
        if ((pProperties != nullptr) && !pProperties->IsNull())
        {
            physical_device_properties_[physicalDevice] = *pProperties->GetPointer();
        }
    }

    virtual void Process_vkGetPhysicalDeviceProperties2(
        const gfxrecon::decode::ApiCallInfo&                                                           call_info,
        gfxrecon::format::HandleId                                                                     physicalDevice,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkPhysicalDeviceProperties2>* pProperties)
        override
    {
        if ((pProperties != nullptr) && !pProperties->IsNull())
        {
            auto properties2                            = pProperties->GetPointer();
            physical_device_properties_[physicalDevice] = properties2->properties;
        }
    }

    virtual void Process_vkGetPhysicalDeviceProperties2KHR(
        const gfxrecon::decode::ApiCallInfo&                                                           call_info,
        gfxrecon::format::HandleId                                                                     physicalDevice,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkPhysicalDeviceProperties2>* pProperties)
        override
    {
        if ((pProperties != nullptr) && !pProperties->IsNull())
        {
            auto properties2                            = pProperties->GetPointer();
            physical_device_properties_[physicalDevice] = properties2->properties;
        }
    }

    virtual void
    Process_vkCreateDevice(const gfxrecon::decode::ApiCallInfo& call_info,
                           VkResult                             returnValue,
                           gfxrecon::format::HandleId           physicalDevice,
                           gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkDeviceCreateInfo>*,
                           gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
                           gfxrecon::decode::HandlePointerDecoder<VkDevice>*) override
    {
        if (returnValue >= 0)
        {
            used_physical_devices_.insert(physicalDevice);
        }
    }

    virtual void Process_vkCreateGraphicsPipelines(
        const gfxrecon::decode::ApiCallInfo& call_info,
        VkResult                             returnValue,
        gfxrecon::format::HandleId,
        gfxrecon::format::HandleId,
        uint32_t createInfoCount,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkGraphicsPipelineCreateInfo>*,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkPipeline>*) override
    {
        if (returnValue >= 0)
        {
            graphics_pipelines_ += createInfoCount;
        }
    }

    virtual void Process_vkCreateComputePipelines(
        const gfxrecon::decode::ApiCallInfo& call_info,
        VkResult                             returnValue,
        gfxrecon::format::HandleId,
        gfxrecon::format::HandleId,
        uint32_t createInfoCount,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkComputePipelineCreateInfo>*,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkPipeline>*) override
    {
        if (returnValue >= 0)
        {
            compute_pipelines_ += createInfoCount;
        }
    }

    void Process_vkCreateRayTracingPipelinesKHR(const ApiCallInfo& call_info,
                                                VkResult           returnValue,
                                                format::HandleId,
                                                format::HandleId,
                                                format::HandleId,
                                                uint32_t createInfoCount,
                                                StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>*,
                                                StructPointerDecoder<Decoded_VkAllocationCallbacks>*,
                                                HandlePointerDecoder<VkPipeline>*) override
    {
        if (returnValue >= 0)
        {
            raytracing_pipelines_ += createInfoCount;
        }
    }

    virtual void Process_vkCmdDraw(const gfxrecon::decode::ApiCallInfo& call_info,
                                   gfxrecon::format::HandleId,
                                   uint32_t,
                                   uint32_t,
                                   uint32_t,
                                   uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndexed(const gfxrecon::decode::ApiCallInfo& call_info,
                                          gfxrecon::format::HandleId,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          int32_t,
                                          uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                           gfxrecon::format::HandleId,
                                           gfxrecon::format::HandleId,
                                           VkDeviceSize,
                                           uint32_t,
                                           uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndexedIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                                  gfxrecon::format::HandleId,
                                                  gfxrecon::format::HandleId,
                                                  VkDeviceSize,
                                                  uint32_t,
                                                  uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndirectCountKHR(const gfxrecon::decode::ApiCallInfo& call_info,
                                                   gfxrecon::format::HandleId,
                                                   gfxrecon::format::HandleId,
                                                   VkDeviceSize,
                                                   gfxrecon::format::HandleId,
                                                   VkDeviceSize,
                                                   uint32_t,
                                                   uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(const gfxrecon::decode::ApiCallInfo& call_info,
                                                          gfxrecon::format::HandleId,
                                                          gfxrecon::format::HandleId,
                                                          VkDeviceSize,
                                                          gfxrecon::format::HandleId,
                                                          VkDeviceSize,
                                                          uint32_t,
                                                          uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndirectByteCountEXT(const gfxrecon::decode::ApiCallInfo& call_info,
                                                       gfxrecon::format::HandleId,
                                                       uint32_t,
                                                       uint32_t,
                                                       gfxrecon::format::HandleId,
                                                       VkDeviceSize,
                                                       uint32_t,
                                                       uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndirectCountAMD(const gfxrecon::decode::ApiCallInfo& call_info,
                                                   gfxrecon::format::HandleId,
                                                   gfxrecon::format::HandleId,
                                                   VkDeviceSize,
                                                   gfxrecon::format::HandleId,
                                                   VkDeviceSize,
                                                   uint32_t,
                                                   uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(const gfxrecon::decode::ApiCallInfo& call_info,
                                                          gfxrecon::format::HandleId,
                                                          gfxrecon::format::HandleId,
                                                          VkDeviceSize,
                                                          gfxrecon::format::HandleId,
                                                          VkDeviceSize,
                                                          uint32_t,
                                                          uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawMeshTasksNV(const gfxrecon::decode::ApiCallInfo& call_info,
                                              gfxrecon::format::HandleId,
                                              uint32_t,
                                              uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(const gfxrecon::decode::ApiCallInfo& call_info,
                                                      gfxrecon::format::HandleId,
                                                      gfxrecon::format::HandleId,
                                                      VkDeviceSize,
                                                      uint32_t,
                                                      uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectCountNV(const gfxrecon::decode::ApiCallInfo& call_info,
                                                           gfxrecon::format::HandleId,
                                                           gfxrecon::format::HandleId,
                                                           VkDeviceSize,
                                                           gfxrecon::format::HandleId,
                                                           VkDeviceSize,
                                                           uint32_t,
                                                           uint32_t) override
    {
        ++draw_count_;
    }

    virtual void Process_vkCmdDispatch(const gfxrecon::decode::ApiCallInfo& call_info,
                                       gfxrecon::format::HandleId,
                                       uint32_t,
                                       uint32_t,
                                       uint32_t) override
    {
        ++dispatch_count_;
    }

    virtual void Process_vkCmdDispatchIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                               gfxrecon::format::HandleId,
                                               gfxrecon::format::HandleId,
                                               VkDeviceSize) override
    {
        ++dispatch_count_;
    }

    virtual void Process_vkCmdDispatchBase(const gfxrecon::decode::ApiCallInfo& call_info,
                                           gfxrecon::format::HandleId,
                                           uint32_t,
                                           uint32_t,
                                           uint32_t,
                                           uint32_t,
                                           uint32_t,
                                           uint32_t) override
    {
        ++dispatch_count_;
    }

    virtual void Process_vkCmdDispatchBaseKHR(const gfxrecon::decode::ApiCallInfo& call_info,
                                              gfxrecon::format::HandleId,
                                              uint32_t,
                                              uint32_t,
                                              uint32_t,
                                              uint32_t,
                                              uint32_t,
                                              uint32_t) override
    {
        ++dispatch_count_;
    }

    virtual void Process_vkAllocateMemory(
        const gfxrecon::decode::ApiCallInfo& call_info,
        VkResult                             returnValue,
        gfxrecon::format::HandleId,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkDeviceMemory>*) override
    {
        assert(pAllocateInfo != nullptr);

        if (returnValue >= 0)
        {
            ++allocation_count_;

            if (!pAllocateInfo->IsNull())
            {
                auto allocate_info = pAllocateInfo->GetPointer();

                if (allocate_info->allocationSize < min_allocation_size_)
                {
                    min_allocation_size_ = allocate_info->allocationSize;
                }

                if (allocate_info->allocationSize > max_allocation_size_)
                {
                    max_allocation_size_ = allocate_info->allocationSize;
                }
            }
        }
    }

  private:
    uint32_t trimmed_frame_{ 0 };

    // Application info.
    std::string app_name_;
    uint32_t    app_version_{ 0 };
    std::string engine_name_;
    uint32_t    engine_version_{ 0 };
    uint32_t    api_version_{ 0 };

    // Physical device info.
    std::set<gfxrecon::format::HandleId>                                       used_physical_devices_;
    std::unordered_map<gfxrecon::format::HandleId, VkPhysicalDeviceProperties> physical_device_properties_;

    // Total pipeline counts by type.
    uint64_t graphics_pipelines_{ 0 };
    uint64_t compute_pipelines_{ 0 };
    uint64_t raytracing_pipelines_{ 0 };

    // Total draw/dispatch counts.
    uint64_t draw_count_{ 0 };
    uint64_t dispatch_count_{ 0 };

    // Memory allocation info.
    uint64_t allocation_count_{ 0 };
    uint64_t min_allocation_size_{ std::numeric_limits<uint64_t>::max() };
    uint64_t max_allocation_size_{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_STAT_CONSUMER_H
