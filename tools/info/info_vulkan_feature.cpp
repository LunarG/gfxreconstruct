/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include "info_vulkan_feature.h"

#include "util/feature_module_registry.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

// Register this class as a feature in a module registry
GFXR_UTIL_REGISTER_FEATURE_CREATOR(InfoFeature, InfoVulkanFeature)

std::string InfoVulkanFeature::CompiledHeaderVersionString() const
{
    return std::string("  Vulkan Header Version  ") + std::to_string(VK_API_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) +
           "." + std::to_string(VK_API_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
           std::to_string(VK_API_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
}

void InfoVulkanFeature::RegisterDecodeComponents(decode::FileProcessor&      file_processor,
                                                 const decode::InfoConsumer& info_consumer)
{
    vulkan_decoder_.AddConsumer(&vulkan_detection_consumer_);
    vulkan_decoder_.AddConsumer(&vulkan_stats_consumer_);
    file_processor.AddDecoder(&vulkan_decoder_);
}

std::string InfoVulkanFeature::GetVersionString(uint32_t api_version)
{
    uint32_t major = VK_API_VERSION_MAJOR(api_version);
    uint32_t minor = VK_API_VERSION_MINOR(api_version);
    uint32_t patch = VK_API_VERSION_PATCH(api_version);

    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

std::string InfoVulkanFeature::GenerateText()
{
    std::string return_val = "\nVulkan application info:\n";

    auto instance_info = vulkan_stats_consumer_.GetInstanceInfo();
    auto pd_info       = vulkan_stats_consumer_.GetPhysicalDeviceInfo();
    auto dev_info      = vulkan_stats_consumer_.GetDeviceInfo();

    // Find the best instance (use the last one if nothing else looks good)
    VkInstance best_instance = vulkan_stats_consumer_.GetLastCreatedInstance();
    uint32_t   max_allocs    = 0;
    uint32_t   max_pipelines = 0;
    for (auto& it : instance_info)
    {
        uint32_t used_allocs    = 0;
        uint32_t used_pipelines = 0;
        for (auto pd : it.second.used_physical_devices)
        {
            for (auto dev : pd_info[pd].devices)
            {
                used_allocs += dev_info[dev].allocation_count;
                used_pipelines += dev_info[dev].graphics_pipelines + dev_info[dev].compute_pipelines +
                                  dev_info[dev].raytracing_pipelines;
            }
        }
        if (used_allocs > max_allocs && used_pipelines > max_pipelines)
        {
            best_instance = it.second.instance_id;
            max_allocs    = used_allocs;
            max_pipelines = used_pipelines;
        }
    }

    auto& best_instance_info = instance_info[best_instance];
    return_val += "\tApplication name:    " + best_instance_info.app_info.app_name + "\n";
    return_val += "\tApplication version: " + std::to_string(best_instance_info.app_info.app_version) + "\n";
    return_val += "\tEngine name:         " + best_instance_info.app_info.engine_name + "\n";
    return_val += "\tEngine version:      " + std::to_string(best_instance_info.app_info.engine_version) + "\n";
    return_val += "\tTarget API version:  " + std::to_string(best_instance_info.app_info.api_version) + " " +
                  GetVersionString(best_instance_info.app_info.api_version) + "\n";
    return_val += "\tUsed resolutions:    ";
    for (const auto& resolution : best_instance_info.resolutions)
    {
        return_val += std::to_string(resolution.width) + "x" + std::to_string(resolution.height) + " ";
    }
    return_val += "\n\nVulkan physical device info:\n";
    for (auto pd : best_instance_info.used_physical_devices)
    {
        auto properties = vulkan_stats_consumer_.GetDeviceProperties(reinterpret_cast<format::HandleId>(pd));
        if (properties != nullptr)
        {
            return_val += "\tDevice name:         " + std::string(properties->deviceName) + "\n";
            return_val += "\tDevice ID:           " + util::to_hex_fixed_width<uint32_t>(properties->deviceID) + "\n";
            return_val += "\tVendor ID:           " + util::to_hex_fixed_width<uint32_t>(properties->vendorID) + "\n";
            return_val += "\tDriver version:      " + std::to_string(properties->driverVersion) + " (" +
                          util::to_hex_fixed_width<uint32_t>(properties->driverVersion) + ")\n";
            return_val += "\tAPI version:         " + std::to_string(properties->apiVersion) + " (" +
                          GetVersionString(properties->apiVersion) + ")\n";
        }
    }

    // For Verbose, we right out each devices alloc info.
    return_val += "\nVulkan device memory allocation info:\n";
    return_val += "\tTotal allocations:   " + std::to_string(vulkan_stats_consumer_.GetTotalAllocationCount()) + "\n";
    if (vulkan_stats_consumer_.GetTotalAllocationCount() > 0)
    {
        return_val +=
            "\tMin allocation size: " + std::to_string(vulkan_stats_consumer_.GetTotalMinAllocationSize()) + "\n";
        return_val +=
            "\tMax allocation size: " + std::to_string(vulkan_stats_consumer_.GetTotalMaxAllocationSize()) + "\n";
    }

    return_val += "\nVulkan pipeline info:\n";
    return_val +=
        "\tTotal graphics pipelines:   " + std::to_string(vulkan_stats_consumer_.GetTotalGraphicsPipelineCount()) +
        "\n";
    return_val +=
        "\tTotal compute pipelines:    " + std::to_string(vulkan_stats_consumer_.GetTotalComputePipelineCount()) + "\n";
    return_val +=
        "\tTotal raytracing pipelines: " + std::to_string(vulkan_stats_consumer_.GetTotalRayTracingPipelineCount()) +
        "\n";

    // TODO: This is the number of recorded draw calls, which will not reflect the number of draw calls
    // executed when recorded once to a command buffer that is submitted/replayed more than once.
    // return_val += "\nDraw/dispatch call info:\n";
    // return_val += "\tTotal draw calls: " + std::to_string(stats_consumer.GetTotalDrawCount()) + "\n";
    // return_val += "\tTotal dispatch calls: " + std::to_string(stats_consumer.GetTotalDispatchCount()) + "\n";

    // Print Physical device info
    const decode::VulkanStatsConsumer::PhysicalDeviceProperties& physical_device_properties =
        vulkan_stats_consumer_.GetPhysicalDeviceProperties();

    return_val += "\nPhysical device properties:\n";
    for (const auto& props : physical_device_properties)
    {
        return_val += "  Device: " + std::to_string(props.first) + "\n";
        return_val += "\tAPI version:         " + util::to_hex_fixed_width<uint64_t>(props.second.apiVersion) + " (" +
                      GetVersionString(props.second.apiVersion) + ")" + "\n";
        return_val += "\tDriver version:      " + util::to_hex_fixed_width<uint32_t>(props.second.driverVersion) + "\n";
        return_val += "\tVendor ID:           " + util::to_hex_fixed_width<uint32_t>(props.second.vendorID) + "\n";
        return_val += "\tDevice ID:           " + util::to_hex_fixed_width<uint32_t>(props.second.deviceID) + "\n";
        return_val += "\tDevice name:         " + std::string(props.second.deviceName) + "\n";
    }

    return return_val;
}

std::string InfoVulkanFeature::GetDeviceTypeString(VkPhysicalDeviceType device_type)
{
    switch (device_type)
    {
        case VK_PHYSICAL_DEVICE_TYPE_OTHER:
            return "VK_PHYSICAL_DEVICE_TYPE_OTHER";
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
            return "VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU";
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            return "VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU";
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
            return "VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU";
        case VK_PHYSICAL_DEVICE_TYPE_CPU:
            return "VK_PHYSICAL_DEVICE_TYPE_CPU";
        default:
            return std::string("Unknown (") + std::to_string(device_type) + ")";
    }
}

nlohmann::json InfoVulkanFeature::GetDeviceMemoryStatsJson(uint64_t alloc_count,
                                                           uint64_t min_alloc,
                                                           uint64_t max_alloc,
                                                           uint64_t gfx_pipelines,
                                                           uint64_t comp_pipelines,
                                                           uint64_t rt_pipelines)
{
    return {
        { "memory-alloc",
          {
              { "count", alloc_count },
              { "min-size", min_alloc },
              { "max-size", max_alloc },
          } },
        { "pipeline-info",
          {
              { "graphics-count", gfx_pipelines },
              { "compute-count", comp_pipelines },
              { "raytracing-count", rt_pipelines },
          } },
    };
}

nlohmann::json InfoVulkanFeature::GenerateJson()
{
    nlohmann::json vulkan_stats;

    auto instance_info = vulkan_stats_consumer_.GetInstanceInfo();
    auto pd_info       = vulkan_stats_consumer_.GetPhysicalDeviceInfo();
    auto dev_info      = vulkan_stats_consumer_.GetDeviceInfo();

    vulkan_stats["header-version"] = std::to_string(VK_API_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                     std::to_string(VK_API_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                     std::to_string(VK_API_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
    auto& instances_json = vulkan_stats["instances"] = nlohmann::json::array();

    for (auto& it : instance_info)
    {
        nlohmann::json instance_json;

        auto& application_info                     = instance_json["application-info"];
        application_info["application"]["name"]    = it.second.app_info.app_name;
        application_info["application"]["version"] = it.second.app_info.app_version;
        application_info["engine"]["name"]         = it.second.app_info.engine_name;
        application_info["engine"]["version"]      = it.second.app_info.engine_version;
        application_info["api-version"]            = GetVersionString(it.second.app_info.api_version);

        instance_json["extensions"] = it.second.enabled_extensions;

        auto& resolutions = application_info["resolutions"] = nlohmann::json::array();
        for (const auto& resolution : it.second.resolutions)
        {
            resolutions.push_back({ { "width", resolution.width }, { "height", resolution.height } });
        }

        auto& physical_devices = instance_json["physical-devices"] = nlohmann::json::array();
        for (auto pd : it.second.used_physical_devices)
        {
            nlohmann::json pd_json;
            const auto& properties = vulkan_stats_consumer_.GetDeviceProperties(reinterpret_cast<format::HandleId>(pd));
            if (properties != nullptr)
            {
                pd_json["name"]           = properties->deviceName;
                pd_json["type"]           = GetDeviceTypeString(properties->deviceType);
                pd_json["api-version"]    = GetVersionString(properties->apiVersion);
                pd_json["id"]             = properties->deviceID;
                pd_json["vendor"]         = properties->vendorID;
                pd_json["driver-version"] = properties->driverVersion;
                std::string uuid_string   = util::uuid_to_string(VK_UUID_SIZE, properties->pipelineCacheUUID);
                pd_json["uuid"]           = uuid_string;

                auto& vulkan_devices = pd_json["vulkan-devices"] = nlohmann::json::array();

                for (auto dev : pd_info[pd].devices)
                {
                    nlohmann::json dev_json;

                    dev_json["extensions"] = dev_info[dev].enabled_extensions;

                    // For Verbose, we write out each devices alloc info.
                    dev_json["memory"] = GetDeviceMemoryStatsJson(dev_info[dev].allocation_count,
                                                                  dev_info[dev].min_allocation_size,
                                                                  dev_info[dev].max_allocation_size,
                                                                  dev_info[dev].graphics_pipelines,
                                                                  dev_info[dev].compute_pipelines,
                                                                  dev_info[dev].raytracing_pipelines);

                    vulkan_devices.push_back(dev_json);
                }

                physical_devices.push_back(pd_json);
            }
        }

        instances_json.push_back(instance_json);
    }
    return vulkan_stats;
}

uint32_t InfoVulkanFeature::GetFrameStart() const
{
    return vulkan_stats_consumer_.GetTrimmedStartFrame();
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)
