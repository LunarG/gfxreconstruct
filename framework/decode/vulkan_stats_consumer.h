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
#include "format/format.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

// vulkan_hash.hpp includes <ciso646>, which is deprecated on C++17 and
// is a warning on gcc 15, treated as error in our build.  So silence that
// deprecation for now.  TODO remove the dependency on deprecated header.
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcpp"
#endif

// avoid compilation issues with c++20 / 32bit
#define VULKAN_HPP_NO_SPACESHIP_OPERATOR
#include "vulkan/vulkan_hash.hpp"
#include "vulkan/vulkan_structs.hpp"

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

#include "util/platform.h"

#include "vulkan/vulkan.h"

#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct VulkanDeviceTracker
{
    VulkanDeviceTracker() {}
    VulkanDeviceTracker(const uint32_t ext_count, const char* const* exts) : enabled_extensions(exts, exts + ext_count)
    {}

    std::vector<std::string> enabled_extensions;

    // Total pipeline counts by type.
    uint64_t graphics_pipelines{ 0 };
    uint64_t compute_pipelines{ 0 };
    uint64_t raytracing_pipelines{ 0 };

    // Total draw/dispatch counts.
    uint64_t draw_count{ 0 };
    uint64_t dispatch_count{ 0 };

    // Memory allocation info.
    uint64_t allocation_count{ 0 };
    uint64_t min_allocation_size{ std::numeric_limits<uint64_t>::max() };
    uint64_t max_allocation_size{ 0 };
};

struct VulkanPhysicalDeviceTracker
{
    std::vector<VkDevice> devices;
};

struct VulkanInstanceAppInfo
{
    VulkanInstanceAppInfo() {}
    VulkanInstanceAppInfo(const VkApplicationInfo& app_info) :
        app_version(app_info.applicationVersion), engine_version(app_info.engineVersion),
        api_version(app_info.apiVersion)
    {
        if (app_info.pApplicationName)
        {
            app_name = app_info.pApplicationName;
        }
        if (app_info.pEngineName)
        {
            engine_name = app_info.pEngineName;
        }
    }
    std::string app_name;
    uint32_t    app_version{ 0 };
    std::string engine_name;
    uint32_t    engine_version{ 0 };
    uint32_t    api_version{ 0 };
};

struct VulkanInstanceTracker
{
    VulkanInstanceTracker() {}
    VulkanInstanceTracker(const VkApplicationInfo* ai,
                          const uint32_t           ext_count,
                          const char* const*       exts,
                          VkInstance               inst) :
        enabled_extensions(exts, exts + ext_count),
        instance_id(inst)
    {
        if (ai)
        {
            app_info = std::move(VulkanInstanceAppInfo(*ai));
        }
    }
    VulkanInstanceAppInfo            app_info;
    std::vector<std::string>         enabled_extensions;
    std::vector<VkPhysicalDevice>    physical_devices;
    bool                             uses_physical_device_groups{ false };
    std::vector<VkPhysicalDevice>    used_physical_devices;
    std::unordered_set<vk::Extent2D> resolutions;
    VkInstance                       instance_id;
};

class VulkanStatsConsumer : public gfxrecon::decode::VulkanConsumer
{
  public:
    // New stuff
    uint32_t   GetInstanceCount() const { return static_cast<uint32_t>(instance_info_.size()); }
    VkInstance GetLastCreatedInstance() const { return last_created_instance_; }
    const std::unordered_map<VkInstance, VulkanInstanceTracker>& GetInstanceInfo() const { return instance_info_; }
    const std::unordered_map<VkPhysicalDevice, VulkanPhysicalDeviceTracker>& GetPhysicalDeviceInfo() const
    {
        return physical_device_info_;
    }
    const std::unordered_map<VkDevice, VulkanDeviceTracker>& GetDeviceInfo() const { return device_info_; }

    // Old stuff
    uint32_t GetTrimmedStartFrame() const { return trimmed_frame_; }
    uint64_t GetTotalGraphicsPipelineCount() const { return total_graphics_pipelines_; }
    uint64_t GetTotalComputePipelineCount() const { return total_compute_pipelines_; }
    uint64_t GetTotalRayTracingPipelineCount() const { return total_raytracing_pipelines_; }
    uint64_t GetTotalDrawCount() const { return total_draw_count_; }
    uint64_t GetTotalDispatchCount() const { return total_dispatch_count_; }
    uint64_t GetTotalAllocationCount() const { return total_allocation_count_; }
    uint64_t GetTotalMinAllocationSize() const { return total_min_allocation_size_; }
    uint64_t GetTotalMaxAllocationSize() const { return total_max_allocation_size_; }

    using PhysicalDeviceProperties = std::unordered_map<gfxrecon::format::HandleId, VkPhysicalDeviceProperties>;
    const PhysicalDeviceProperties& GetPhysicalDeviceProperties() const { return physical_device_properties_; }

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
        const gfxrecon::decode::ApiCallInfo&                                                     call_info,
        VkResult                                                                                 returnValue,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkInstanceCreateInfo>*  pCreateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>* allocCb,
        gfxrecon::decode::HandlePointerDecoder<VkInstance>*                                      pInstance) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        GFXRECON_UNREFERENCED_PARAMETER(allocCb);
        if ((pCreateInfo != nullptr) && (returnValue >= 0) && !pCreateInfo->IsNull())
        {
            auto create_info = pCreateInfo->GetPointer();
            auto app_info    = create_info->pApplicationInfo;
            if (app_info != nullptr)
            {
                const VkInstance      inst = reinterpret_cast<const VkInstance>(*pInstance->GetPointer());
                VulkanInstanceTracker instance_tracker(
                    app_info, create_info->enabledExtensionCount, create_info->ppEnabledExtensionNames, inst);
                instance_info_[inst]   = std::move(instance_tracker);
                last_created_instance_ = inst;
            }
        }
    }

    virtual void Process_vkEnumeratePhysicalDevices(const ApiCallInfo&                      call_info,
                                                    VkResult                                returnValue,
                                                    format::HandleId                        instance,
                                                    PointerDecoder<uint32_t>*               pPhysicalDeviceCount,
                                                    HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        if (returnValue >= 0 && *pPhysicalDeviceCount->GetPointer() > 0 && pPhysicalDevices->GetPointer())
        {
            uint32_t   pd_count    = *pPhysicalDeviceCount->GetPointer();
            VkInstance actual_inst = reinterpret_cast<VkInstance>(instance);
            GFXRECON_ASSERT(instance_info_.find(actual_inst) != instance_info_.end());
            for (uint32_t pd = 0; pd < pd_count; ++pd)
            {
                VkPhysicalDevice phys_dev = reinterpret_cast<VkPhysicalDevice>(pPhysicalDevices->GetPointer()[pd]);
                if (std::find(instance_info_[actual_inst].physical_devices.begin(),
                              instance_info_[actual_inst].physical_devices.end(),
                              phys_dev) == instance_info_[actual_inst].physical_devices.end())
                {
                    instance_info_[actual_inst].physical_devices.push_back(phys_dev);
                    physical_device_to_instance_map_[phys_dev] = actual_inst;
                }
            }
        }
    }

    virtual void Process_vkEnumeratePhysicalDeviceGroups(
        const ApiCallInfo&                                             call_info,
        VkResult                                                       returnValue,
        format::HandleId                                               instance,
        PointerDecoder<uint32_t>*                                      pPhysicalDeviceGroupCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        if (returnValue >= 0 && *pPhysicalDeviceGroupCount->GetPointer() > 0 &&
            pPhysicalDeviceGroupProperties->GetPointer())
        {
            const Decoded_VkPhysicalDeviceGroupProperties* meta_info =
                pPhysicalDeviceGroupProperties->GetMetaStructPointer();
            size_t     physdev_group_count = pPhysicalDeviceGroupProperties->GetLength();
            VkInstance actual_inst         = reinterpret_cast<VkInstance>(instance);
            GFXRECON_ASSERT(instance_info_.find(actual_inst) != instance_info_.end());

            for (size_t pdg = 0; pdg < physdev_group_count; ++pdg)
            {
                size_t                  physical_device_count = meta_info[pdg].physicalDevices.GetLength();
                const format::HandleId* physical_devices      = meta_info[pdg].physicalDevices.GetPointer();
                for (size_t pd = 0; pd < physical_device_count; ++pd)
                {
                    VkPhysicalDevice phys_dev = reinterpret_cast<VkPhysicalDevice>(physical_devices[pd]);
                    if (std::find(instance_info_[actual_inst].physical_devices.begin(),
                                  instance_info_[actual_inst].physical_devices.end(),
                                  phys_dev) == instance_info_[actual_inst].physical_devices.end())
                    {
                        instance_info_[actual_inst].physical_devices.push_back(phys_dev);
                        physical_device_to_instance_map_[phys_dev] = actual_inst;

                        instance_info_[actual_inst].uses_physical_device_groups = true;
                    }
                }
            }
        }
    }

    virtual void Process_vkGetPhysicalDeviceProperties(
        const gfxrecon::decode::ApiCallInfo&                                                          call_info,
        gfxrecon::format::HandleId                                                                    physicalDevice,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkPhysicalDeviceProperties>* pProperties)
        override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
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
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
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
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        if ((pProperties != nullptr) && !pProperties->IsNull())
        {
            auto properties2                            = pProperties->GetPointer();
            physical_device_properties_[physicalDevice] = properties2->properties;
        }
    }

    virtual void Process_vkCreateDevice(
        const gfxrecon::decode::ApiCallInfo&                                                     call_info,
        VkResult                                                                                 returnValue,
        gfxrecon::format::HandleId                                                               physicalDevice,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkDeviceCreateInfo>*    pCreateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>* allocCb,
        gfxrecon::decode::HandlePointerDecoder<VkDevice>*                                        pDevice) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        GFXRECON_UNREFERENCED_PARAMETER(allocCb);
        if ((pCreateInfo != nullptr) && (returnValue >= 0) && !pCreateInfo->IsNull())
        {
            auto create_info = pCreateInfo->GetPointer();

            VkPhysicalDevice phys_dev = reinterpret_cast<VkPhysicalDevice>(physicalDevice);
            VkInstance       instance = physical_device_to_instance_map_[phys_dev];

            if (std::find(instance_info_[instance].used_physical_devices.begin(),
                          instance_info_[instance].used_physical_devices.end(),
                          phys_dev) == instance_info_[instance].used_physical_devices.end())
            {
                used_physical_devices_.insert(physicalDevice);
                instance_info_[instance].used_physical_devices.push_back(phys_dev);
            }

            const VkDevice device           = reinterpret_cast<const VkDevice>(*pDevice->GetPointer());
            device_to_instance_map_[device] = instance;

            if (physical_device_info_.find(phys_dev) == physical_device_info_.end())
            {
                physical_device_info_[phys_dev] = std::move(VulkanPhysicalDeviceTracker());
            }

            if (std::find(physical_device_info_[phys_dev].devices.begin(),
                          physical_device_info_[phys_dev].devices.end(),
                          device) == physical_device_info_[phys_dev].devices.end())
            {
                physical_device_info_[phys_dev].devices.push_back(device);
            }

            device_info_[device] = std::move(
                VulkanDeviceTracker(create_info->enabledExtensionCount, create_info->ppEnabledExtensionNames));
        }
    }

    virtual void Process_vkCreateGraphicsPipelines(
        const gfxrecon::decode::ApiCallInfo& call_info,
        VkResult                             returnValue,
        format::HandleId                     device,
        format::HandleId                     pipelineCache,
        uint32_t                             createInfoCount,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkGraphicsPipelineCreateInfo>*,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkPipeline>*) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        GFXRECON_UNREFERENCED_PARAMETER(pipelineCache);
        if (returnValue >= 0)
        {
            total_graphics_pipelines_ += createInfoCount;

            VkDevice dev = reinterpret_cast<VkDevice>(device);
            device_info_[dev].graphics_pipelines += createInfoCount;
        }
    }

    virtual void Process_vkCreateComputePipelines(
        const gfxrecon::decode::ApiCallInfo& call_info,
        VkResult                             returnValue,
        format::HandleId                     device,
        format::HandleId                     pipelineCache,
        uint32_t                             createInfoCount,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkComputePipelineCreateInfo>*,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkPipeline>*) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        GFXRECON_UNREFERENCED_PARAMETER(pipelineCache);
        if (returnValue >= 0)
        {
            total_compute_pipelines_ += createInfoCount;

            VkDevice dev = reinterpret_cast<VkDevice>(device);
            device_info_[dev].compute_pipelines += createInfoCount;
        }
    }

    void Process_vkCreateRayTracingPipelinesKHR(const ApiCallInfo& call_info,
                                                VkResult           returnValue,
                                                format::HandleId   device,
                                                format::HandleId   deferredOperation,
                                                format::HandleId   pipelineCache,
                                                uint32_t           createInfoCount,
                                                StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>*,
                                                StructPointerDecoder<Decoded_VkAllocationCallbacks>*,
                                                HandlePointerDecoder<VkPipeline>*) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        GFXRECON_UNREFERENCED_PARAMETER(deferredOperation);
        GFXRECON_UNREFERENCED_PARAMETER(pipelineCache);
        if (returnValue >= 0)
        {
            total_raytracing_pipelines_ += createInfoCount;

            VkDevice dev = reinterpret_cast<VkDevice>(device);
            device_info_[dev].raytracing_pipelines += createInfoCount;
        }
    }

    virtual void Process_vkCmdDraw(const gfxrecon::decode::ApiCallInfo& call_info,
                                   gfxrecon::format::HandleId,
                                   uint32_t,
                                   uint32_t,
                                   uint32_t,
                                   uint32_t) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDrawIndexed(const gfxrecon::decode::ApiCallInfo& call_info,
                                          gfxrecon::format::HandleId,
                                          uint32_t,
                                          uint32_t,
                                          uint32_t,
                                          int32_t,
                                          uint32_t) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDrawIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                           gfxrecon::format::HandleId,
                                           gfxrecon::format::HandleId,
                                           VkDeviceSize,
                                           uint32_t,
                                           uint32_t) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDrawIndexedIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                                  gfxrecon::format::HandleId,
                                                  gfxrecon::format::HandleId,
                                                  VkDeviceSize,
                                                  uint32_t,
                                                  uint32_t) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
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
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
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
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
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
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
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
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
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
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDrawMeshTasksNV(const gfxrecon::decode::ApiCallInfo& call_info,
                                              gfxrecon::format::HandleId,
                                              uint32_t,
                                              uint32_t) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(const gfxrecon::decode::ApiCallInfo& call_info,
                                                      gfxrecon::format::HandleId,
                                                      gfxrecon::format::HandleId,
                                                      VkDeviceSize,
                                                      uint32_t,
                                                      uint32_t) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
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
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDispatch(const gfxrecon::decode::ApiCallInfo& call_info,
                                       gfxrecon::format::HandleId,
                                       uint32_t,
                                       uint32_t,
                                       uint32_t) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_dispatch_count_;
    }

    virtual void Process_vkCmdDispatchIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                               gfxrecon::format::HandleId,
                                               gfxrecon::format::HandleId,
                                               VkDeviceSize) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_dispatch_count_;
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
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_dispatch_count_;
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
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        ++total_dispatch_count_;
    }

    virtual void ProcessSetDevicePropertiesCommand(format::HandleId   physical_device_id,
                                                   uint32_t           api_version,
                                                   uint32_t           driver_version,
                                                   uint32_t           vendor_id,
                                                   uint32_t           device_id,
                                                   uint32_t           device_type,
                                                   const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                   const std::string& device_name) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(physical_device_id);

        if (physical_device_properties_.find(physical_device_id) == physical_device_properties_.end())
        {
            physical_device_properties_.emplace(physical_device_id, VkPhysicalDeviceProperties());
            physical_device_properties_[physical_device_id].apiVersion    = api_version;
            physical_device_properties_[physical_device_id].driverVersion = driver_version;
            physical_device_properties_[physical_device_id].vendorID      = vendor_id;
            physical_device_properties_[physical_device_id].deviceID      = device_id;
            physical_device_properties_[physical_device_id].deviceType = static_cast<VkPhysicalDeviceType>(device_type);

            device_name.copy(physical_device_properties_[physical_device_id].deviceName,
                             VK_MAX_PHYSICAL_DEVICE_NAME_SIZE);

            util::platform::MemoryCopy(&physical_device_properties_[physical_device_id].pipelineCacheUUID[0],
                                       format::kUuidSize,
                                       pipeline_cache_uuid,
                                       format::kUuidSize);
        }
    }

    virtual void Process_vkAllocateMemory(
        const gfxrecon::decode::ApiCallInfo&                                                    call_info,
        VkResult                                                                                returnValue,
        gfxrecon::format::HandleId                                                              device,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*,
        gfxrecon::decode::HandlePointerDecoder<VkDeviceMemory>*) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        assert(pAllocateInfo != nullptr);

        if (returnValue >= 0)
        {
            VkDevice dev = reinterpret_cast<VkDevice>(device);

            total_allocation_count_++;
            device_info_[dev].allocation_count += 1;

            if (!pAllocateInfo->IsNull())
            {
                auto allocate_info = pAllocateInfo->GetPointer();

                if (allocate_info->allocationSize < total_min_allocation_size_)
                {
                    total_min_allocation_size_ = allocate_info->allocationSize;
                }

                if (allocate_info->allocationSize < device_info_[dev].min_allocation_size)
                {
                    device_info_[dev].min_allocation_size = allocate_info->allocationSize;
                }

                if (allocate_info->allocationSize > total_max_allocation_size_)
                {
                    total_max_allocation_size_ = allocate_info->allocationSize;
                }

                if (allocate_info->allocationSize > device_info_[dev].max_allocation_size)
                {
                    device_info_[dev].max_allocation_size = allocate_info->allocationSize;
                }
            }
        }
    }

    virtual void Process_vkCreateSwapchainKHR(
        const gfxrecon::decode::ApiCallInfo&                                                        call_info,
        VkResult                                                                                    returnValue,
        gfxrecon::format::HandleId                                                                  device,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>*    pAllocator,
        gfxrecon::decode::HandlePointerDecoder<VkSwapchainKHR>*                                     pSwapchain) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
        GFXRECON_UNREFERENCED_PARAMETER(pSwapchain);
        if (returnValue >= 0 && !pCreateInfo->IsNull())
        {
            const auto& extent   = pCreateInfo->GetPointer()->imageExtent;
            VkInstance  instance = device_to_instance_map_[reinterpret_cast<VkDevice>(device)];
            instance_info_[instance].resolutions.insert(extent);
        }
    }

    virtual void
    Process_vkCreateSharedSwapchainsKHR(const ApiCallInfo&                                      call_info,
                                        VkResult                                                returnValue,
                                        format::HandleId                                        device,
                                        uint32_t                                                swapchainCount,
                                        StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                        HandlePointerDecoder<VkSwapchainKHR>*                   pSwapchains) override
    {
        GFXRECON_UNREFERENCED_PARAMETER(call_info);
        GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
        GFXRECON_UNREFERENCED_PARAMETER(pSwapchains);
        if (returnValue >= 0 && !pCreateInfos->IsNull())
        {
            for (uint32_t i = 0; i < swapchainCount; ++i)
            {
                const auto& extent   = pCreateInfos->GetPointer()[i].imageExtent;
                VkInstance  instance = device_to_instance_map_[reinterpret_cast<VkDevice>(device)];
                instance_info_[instance].resolutions.insert(extent);
            }
        }
    }

  private:
    uint32_t trimmed_frame_{ 0 };

    // Physical device info.
    std::set<gfxrecon::format::HandleId>                                       used_physical_devices_;
    std::unordered_map<gfxrecon::format::HandleId, VkPhysicalDeviceProperties> physical_device_properties_;

    // Total pipeline counts by type.
    uint64_t total_graphics_pipelines_{ 0 };
    uint64_t total_compute_pipelines_{ 0 };
    uint64_t total_raytracing_pipelines_{ 0 };

    // Total draw/dispatch counts.
    uint64_t total_draw_count_{ 0 };
    uint64_t total_dispatch_count_{ 0 };

    // Total memory allocation info
    uint64_t total_allocation_count_{ 0 };
    uint64_t total_min_allocation_size_{ std::numeric_limits<uint64_t>::max() };
    uint64_t total_max_allocation_size_{ 0 };

    VkInstance                                                        last_created_instance_;
    std::unordered_map<VkInstance, VulkanInstanceTracker>             instance_info_;
    std::unordered_map<VkPhysicalDevice, VulkanPhysicalDeviceTracker> physical_device_info_;
    std::unordered_map<VkDevice, VulkanDeviceTracker>                 device_info_;
    std::unordered_map<VkPhysicalDevice, VkInstance>                  physical_device_to_instance_map_;
    std::unordered_map<VkDevice, VkInstance>                          device_to_instance_map_;
    std::unordered_map<VkDevice, VkPhysicalDevice>                    device_to_physical_device_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_STAT_CONSUMER_H
