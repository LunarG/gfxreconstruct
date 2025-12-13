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
#include "util/info_output.h"
#include "util/to_string.h"

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
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include <nlohmann/json.hpp>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanStatsConsumer : public gfxrecon::decode::VulkanConsumer, public gfxrecon::util::InfoOutputInterface
{

  private:
    struct VulkanDeviceTracker
    {
        VulkanDeviceTracker() {}
        VulkanDeviceTracker(const uint32_t ext_count, const char* const* exts)
        {
            enabled_extensions = std::move(std::vector<std::string>(exts, exts + ext_count));
        }
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
                              VkInstance               inst)
        {
            if (ai)
            {
                app_info = std::move(VulkanInstanceAppInfo(*ai));
            }
            enabled_extensions = std::move(std::vector<std::string>(exts, exts + ext_count));
            instance_id        = inst;
        }
        VulkanInstanceAppInfo            app_info;
        std::vector<std::string>         enabled_extensions;
        std::vector<VkPhysicalDevice>    physical_devices;
        bool                             uses_physical_device_groups{ false };
        std::vector<VkPhysicalDevice>    used_physical_devices;
        std::unordered_set<vk::Extent2D> resolutions;
        VkInstance                       instance_id;
    };

  public:
    static std::string MakeVersionString(uint32_t version)
    {
        return std::to_string(VK_API_VERSION_MAJOR(version)) + "." + std::to_string(VK_API_VERSION_MINOR(version)) +
               "." + std::to_string(VK_API_VERSION_PATCH(version));
    }
    static std::string GetCurrentHeaderVersionString() { return MakeVersionString(VK_HEADER_VERSION_COMPLETE); }

    uint32_t GetTrimmedStartFrame() const { return trimmed_frame_; }

    const VkPhysicalDeviceProperties* GetPhysicalDeviceProperties(gfxrecon::format::HandleId id) const
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

    virtual void Process_vkCreateDevice(
        const gfxrecon::decode::ApiCallInfo&                                                     call_info,
        VkResult                                                                                 returnValue,
        gfxrecon::format::HandleId                                                               physicalDevice,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkDeviceCreateInfo>*    pCreateInfo,
        gfxrecon::decode::StructPointerDecoder<gfxrecon::decode::Decoded_VkAllocationCallbacks>* allocCb,
        gfxrecon::decode::HandlePointerDecoder<VkDevice>*                                        pDevice) override
    {
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
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDrawIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                           gfxrecon::format::HandleId,
                                           gfxrecon::format::HandleId,
                                           VkDeviceSize,
                                           uint32_t,
                                           uint32_t) override
    {
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDrawIndexedIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                                  gfxrecon::format::HandleId,
                                                  gfxrecon::format::HandleId,
                                                  VkDeviceSize,
                                                  uint32_t,
                                                  uint32_t) override
    {
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
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDrawMeshTasksNV(const gfxrecon::decode::ApiCallInfo& call_info,
                                              gfxrecon::format::HandleId,
                                              uint32_t,
                                              uint32_t) override
    {
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(const gfxrecon::decode::ApiCallInfo& call_info,
                                                      gfxrecon::format::HandleId,
                                                      gfxrecon::format::HandleId,
                                                      VkDeviceSize,
                                                      uint32_t,
                                                      uint32_t) override
    {
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
        ++total_draw_count_;
    }

    virtual void Process_vkCmdDispatch(const gfxrecon::decode::ApiCallInfo& call_info,
                                       gfxrecon::format::HandleId,
                                       uint32_t,
                                       uint32_t,
                                       uint32_t) override
    {
        ++total_dispatch_count_;
    }

    virtual void Process_vkCmdDispatchIndirect(const gfxrecon::decode::ApiCallInfo& call_info,
                                               gfxrecon::format::HandleId,
                                               gfxrecon::format::HandleId,
                                               VkDeviceSize) override
    {
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
        if (!pCreateInfo->IsNull())
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
        if (!pCreateInfos->IsNull())
        {
            for (uint32_t i = 0; i < swapchainCount; ++i)
            {
                const auto& extent   = pCreateInfos->GetPointer()[i].imageExtent;
                VkInstance  instance = device_to_instance_map_[reinterpret_cast<VkDevice>(device)];
                instance_info_[instance].resolutions.insert(extent);
            }
        }
    }

    void PrintVulkanDeviceType(VkPhysicalDeviceType device_type, std::string& device_string) const
    {
        switch (device_type)
        {
            case VK_PHYSICAL_DEVICE_TYPE_OTHER:
                device_string = "VK_PHYSICAL_DEVICE_TYPE_OTHER";
                break;
            case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
                device_string = "VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU";
                break;
            case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
                device_string = "VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU";
                break;
            case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
                device_string = "VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU";
                break;
            case VK_PHYSICAL_DEVICE_TYPE_CPU:
                device_string = "VK_PHYSICAL_DEVICE_TYPE_CPU";
                break;
            default:
                device_string = " Unknown (";
                device_string += std::to_string(device_type);
                device_string += ")";
                break;
        }
    }

    void GenerateInstanceApplicationJsonData(nlohmann::json& json_base, const VulkanInstanceAppInfo& app_info) const
    {
        json_base["application"]["name"]    = app_info.app_name;
        json_base["application"]["version"] = app_info.app_version;
        json_base["engine"]["name"]         = app_info.engine_name;
        json_base["engine"]["version"]      = app_info.engine_version;
        json_base["api-version"]            = MakeVersionString(app_info.api_version);
    }

    void GenerateInstanceApplicationStrings(std::vector<std::string>&    out_strings,
                                            const VulkanInstanceAppInfo& app_info) const
    {
        out_strings.push_back("");
        out_strings.push_back("Vulkan application info:");
        out_strings.push_back("\tApplication name:    " + app_info.app_name);
        out_strings.push_back("\tApplication version: " + std::to_string(app_info.app_version));
        out_strings.push_back("\tEngine name:         " + app_info.engine_name);
        out_strings.push_back("\tEngine version:      " + std::to_string(app_info.engine_version));
        out_strings.push_back("\tTarget API version:  " + std::to_string(app_info.api_version) + " (" +
                              MakeVersionString(app_info.api_version) + ")");
    }

    void GenerateDeviceJsonData(nlohmann::json& dev_json_array, const std::vector<VkDevice>& devices) const
    {
        for (const auto& dev : devices)
        {
            nlohmann::json dev_json;
            const auto&    cur_info = device_info_.at(dev);

            if (cur_info.enabled_extensions.size() > 0)
            {
                dev_json["extensions"] = cur_info.enabled_extensions;
            }
            dev_json["memory-alloc"]["count"]             = cur_info.allocation_count;
            dev_json["memory-alloc"]["min-size"]          = cur_info.min_allocation_size;
            dev_json["memory-alloc"]["max-size"]          = cur_info.max_allocation_size;
            dev_json["pipeline-info"]["graphics-count"]   = cur_info.graphics_pipelines;
            dev_json["pipeline-info"]["compute-count"]    = cur_info.compute_pipelines;
            dev_json["pipeline-info"]["raytracing-count"] = cur_info.raytracing_pipelines;

            dev_json_array.push_back(dev_json);
        }
    }

    void GeneratePhysicalDeviceJsonData(nlohmann::json&                      pd_json_array,
                                        const std::vector<VkPhysicalDevice>& used_pds) const
    {
        for (const auto& pd : used_pds)
        {
            auto properties = GetPhysicalDeviceProperties(reinterpret_cast<gfxrecon::format::HandleId>(pd));
            if (properties != nullptr)
            {
                nlohmann::json pd_json;
                pd_json["device-name"] = properties->deviceName;
                std::string device_type_string;
                PrintVulkanDeviceType(properties->deviceType, device_type_string);
                pd_json["device-type"]    = device_type_string;
                pd_json["api-version"]    = MakeVersionString(properties->apiVersion);
                pd_json["device-id"]      = properties->deviceID;
                pd_json["vendor-id"]      = properties->vendorID;
                pd_json["driver-version"] = properties->driverVersion;

                std::string uuid_string = gfxrecon::util::uuid_to_string(VK_UUID_SIZE, properties->pipelineCacheUUID);
                pd_json["pipeline-cache-uuid"] = uuid_string;

                pd_json["vulkan-devices"] = nlohmann::json::array();
                GenerateDeviceJsonData(pd_json["vulkan-devices"], physical_device_info_.at(pd).devices);

                pd_json_array.push_back(pd_json);
            }
        }
    }

    void AddPhysicalDeviceStrings(std::vector<std::string>&         out_strings,
                                  const VkPhysicalDeviceProperties* properties) const
    {
        std::stringstream ss;
        ss << std::hex << std::setfill('0') << std::setw(8) << properties->deviceID;
        std::string device_id_str = ss.str();
        ss                        = std::stringstream();
        ss << std::hex << std::setfill('0') << std::setw(8) << properties->vendorID;
        std::string vendor_id_str = ss.str();
        ss                        = std::stringstream();
        ss << std::hex << std::setfill('0') << std::setw(8) << properties->driverVersion;
        std::string driver_version_str = ss.str();

        std::string device_type_string;
        PrintVulkanDeviceType(properties->deviceType, device_type_string);

        std::string uuid_string = gfxrecon::util::uuid_to_string(VK_UUID_SIZE, properties->pipelineCacheUUID);

        out_strings.push_back("\tDevice name:         " + std::string(properties->deviceName));
        out_strings.push_back("\tDevice type:         " + std::to_string(properties->deviceType) + " (" +
                              device_type_string + ")");
        out_strings.push_back("\tDevice ID:           0x" + device_id_str);
        out_strings.push_back("\tVendor ID:           0x" + vendor_id_str);
        out_strings.push_back("\tDriver version:      " + std::to_string(properties->driverVersion) + " (0x" +
                              driver_version_str + ")");
        out_strings.push_back("\tAPI version:         " + std::to_string(properties->apiVersion) + " (" +
                              MakeVersionString(properties->apiVersion) + ")");
        out_strings.push_back("\tPipeline cache UUID: 0x" + uuid_string);
    }

    void GeneratePhysicalDeviceStrings(std::vector<std::string>&            out_strings,
                                       const std::vector<VkPhysicalDevice>& used_pds) const
    {
        out_strings.push_back("");
        out_strings.push_back("Vulkan physical device info:");
        for (const auto& pd : used_pds)
        {
            auto properties = GetPhysicalDeviceProperties(reinterpret_cast<gfxrecon::format::HandleId>(pd));
            if (properties != nullptr)
            {
                AddPhysicalDeviceStrings(out_strings, properties);
            }
        }

        out_strings.push_back("");
        out_strings.push_back("Vulkan device memory allocation info:");
        out_strings.push_back("\tTotal allocations:   " + std::to_string(total_allocation_count_));

        if (total_allocation_count_ > 0)
        {
            out_strings.push_back("\tMin allocation size: " + std::to_string(total_min_allocation_size_));
            out_strings.push_back("\tMax allocation size: " + std::to_string(total_max_allocation_size_));
        }

        out_strings.push_back("");
        out_strings.push_back("Vulkan pipeline info:");
        out_strings.push_back("\tTotal graphics pipelines:   " + std::to_string(total_graphics_pipelines_));
        out_strings.push_back("\tTotal compute pipelines:    " + std::to_string(total_compute_pipelines_));
        out_strings.push_back("\tTotal raytracing pipelines: " + std::to_string(total_raytracing_pipelines_));
    }

    void GenerateInstanceJsonData(nlohmann::json& inst_json_array) const
    {
        for (const auto& [instance, value] : instance_info_)
        {
            nlohmann::json instance_json;

            // Write application data
            GenerateInstanceApplicationJsonData(instance_json["application-info"], value.app_info);
            instance_json["extensions"] = value.enabled_extensions;

            // Write resolution data
            instance_json["resolutions"] = nlohmann::json::array();
            for (const auto& resolution : value.resolutions)
            {
                instance_json["resolutions"].push_back(std::to_string(resolution.width) + "x" +
                                                       std::to_string(resolution.height));
            }

            instance_json["used-physical-device-groups"] = value.uses_physical_device_groups;
            instance_json["physical-devices"]            = nlohmann::json::array();
            GeneratePhysicalDeviceJsonData(instance_json["physical-devices"], value.used_physical_devices);

            inst_json_array.push_back(instance_json);
        }
    }

    void GenerateInstanceStrings(std::vector<std::string>& out_strings, const VulkanInstanceTracker& inst_tracker) const
    {
        // Write application data
        GenerateInstanceApplicationStrings(out_strings, inst_tracker.app_info);

        // Write resolution data
        std::string resolutions = "\tUsed resolutions:    ";
        for (const auto& resolution : inst_tracker.resolutions)
        {
            resolutions += std::to_string(resolution.width) + "x" + std::to_string(resolution.height) + " ";
        }
        out_strings.push_back(resolutions);

        // Write out physical device info
        GeneratePhysicalDeviceStrings(out_strings, inst_tracker.used_physical_devices);
    }

    std::pair<const std::string, const nlohmann::json*> GenerateJson() const override
    {
        nlohmann::json* vulkan_base = new nlohmann::json;

        (*vulkan_base)["instances"] = nlohmann::json::array();
        GenerateInstanceJsonData((*vulkan_base)["instances"]);

        return std::make_pair("vulkan", vulkan_base);
    }

    const std::vector<std::string> GenerateStrings() const override
    {
        std::vector<std::string> out_strings;

        // Find the best instance (use the last one if nothing else looks good)
        VkInstance best_instance = last_created_instance_;
        uint32_t   max_allocs    = 0;
        uint32_t   max_pipelines = 0;
        for (const auto& [key, value] : instance_info_)
        {
            uint32_t used_allocs    = 0;
            uint32_t used_pipelines = 0;
            for (const auto& pd : value.used_physical_devices)
            {
                for (const auto& dev : physical_device_info_.at(pd).devices)
                {
                    const auto& cur_info = device_info_.at(dev);
                    used_allocs += cur_info.allocation_count;
                    used_pipelines +=
                        cur_info.graphics_pipelines + cur_info.compute_pipelines + cur_info.raytracing_pipelines;
                }
            }
            if (used_allocs > max_allocs && used_pipelines > max_pipelines)
            {
                best_instance = value.instance_id;
                max_allocs    = used_allocs;
                max_pipelines = used_pipelines;
            }
        }

        // Only generate data for the "best" instance.
        GenerateInstanceStrings(out_strings, instance_info_.at(best_instance));

        // Print Physical device info
        out_strings.push_back("");
        out_strings.push_back("Physical device properties:");
        for (const auto& [key, value] : physical_device_properties_)
        {
            out_strings.push_back("  Device: " + std::to_string(key));
            AddPhysicalDeviceStrings(out_strings, &value);
        }

        return out_strings;
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
