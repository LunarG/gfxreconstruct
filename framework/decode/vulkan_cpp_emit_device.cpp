//
// Copyright (c) 2020 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2023 LunarG, Inc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Instance, physical device, and device creation.
// This file holds part of VulkanCppConsumerBase.  See vulkan_cpp_consumer_base.h.

#include "decode/vulkan_cpp_consumer_base.h"
#include "decode/vulkan_cpp_template_strings.h"

#include PROJECT_VERSION_HEADER_FILE
#include "util/file_path.h"
#include "util/platform.h"
#include <util/hash.h>
#include "decode/vulkan_cpp_structs.h"
#include <generated/generated_vulkan_cpp_structs.h>
#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "generated/generated_vulkan_enum_to_string.h"

#include <algorithm>
#include <cmath>
#include <iomanip>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
void VulkanCppConsumerBase::Generate_vkEnumeratePhysicalDevices(args::EnumeratePhysicalDevices& args)
{
    FILE* file = GetFrameFile();

    if (args.pPhysicalDevices.GetPointer() != nullptr)
    {
        fprintf(file, "\t{\n");
        uint32_t          recorded_count = *(args.pPhysicalDeviceCount.GetPointer());
        const std::string physical_device_names =
            "physicalDevices_" + std::to_string(GetNextId(VK_OBJECT_TYPE_PHYSICAL_DEVICE));

        AddKnownVariables(
            "VkPhysicalDevice", physical_device_names, args.pPhysicalDevices.GetPointer(), recorded_count);
        fprintf(file, "\t\tuint32_t deviceCount = %d;\n", recorded_count);
        fprintf(file,
                "\t\tvkEnumeratePhysicalDevices(%s, &deviceCount, %s);\n",
                handle_id_map_[args.instance].c_str(),
                physical_device_names.c_str());

        AddHandles(physical_device_names, args.pPhysicalDevices.GetPointer(), recorded_count);

        enumerated_physical_devices_.assign(args.pPhysicalDevices.GetPointer(),
                                            args.pPhysicalDevices.GetPointer() + recorded_count);

        fprintf(file, "\t\tSelectPhysicalDevices(%s, deviceCount);\n", physical_device_names.c_str());
        fprintf(file, "\t}\n");
    }
}

void VulkanCppConsumerBase::Generate_vkGetPhysicalDeviceQueueFamilyProperties(
    args::GetPhysicalDeviceQueueFamilyProperties& args)
{
    FILE* file = GetFrameFile();

    std::string queue_family_props_var_name = "NULL";
    if (args.pQueueFamilyProperties.GetPointer() == NULL)
    {
        const std::string queue_family_props_count_var_name =
            "pQueueFamilyPropertyCount_" + std::to_string(GetNextId());
        fprintf(file, "\tuint32_t %s;\n", queue_family_props_count_var_name.c_str());
        queue_family_count_map_[args.physicalDevice] = queue_family_props_count_var_name;
    }
    else
    {
        queue_family_props_var_name = "pQueueFamilyProperties_" + std::to_string(GetNextId());
        fprintf(file,
                "\tVkQueueFamilyProperties %s[%s];\n",
                queue_family_props_var_name.c_str(),
                queue_family_count_map_[args.physicalDevice].c_str());
        // TODO: connect these formats to their usages? How?
    }

    fprintf(file,
            "\tvkGetPhysicalDeviceQueueFamilyProperties(%s, &%s, %s);\n",
            GetHandle(args.physicalDevice).c_str(),
            queue_family_count_map_[args.physicalDevice].c_str(),
            queue_family_props_var_name.c_str());

    fprintf(file, "\n");
}

static std::vector<std::string> FilterLayers(const char* const* layerArray, const uint32_t layerArrayLength)
{
    std::vector<std::string> enabled_layers;
    if (layerArrayLength == 0)
    {
        return enabled_layers;
    }

    const std::vector<std::string> layer_black_list = {
        GFXRECON_PROJECT_VULKAN_LAYER_NAME,
        "VK_LAYER_LUNARG_device_simulation",
    };

    for (uint32_t idx = 0; idx < layerArrayLength; ++idx)
    {
        bool isBlacklisted = std::any_of(layer_black_list.begin(),
                                         layer_black_list.end(),
                                         [&](const std::string& name) { return name == layerArray[idx]; });
        if (!isBlacklisted)
        {
            enabled_layers.emplace_back(layerArray[idx]);
        }
    }

    return enabled_layers;
}

static std::vector<std::string> ReplaceExtensions(const char* const*                        extensionArray,
                                                  const uint32_t                            extensionArrayLength,
                                                  const std::map<std::string, std::string>& remapInfo)
{
    std::vector<std::string> enabled_extensions;
    enabled_extensions.reserve(extensionArrayLength);

    for (uint32_t idx = 0; idx < extensionArrayLength; ++idx)
    {
        std::string extension_name(extensionArray[idx]);

        const auto& it = remapInfo.find(extension_name);
        if (it != remapInfo.end())
        {
            extension_name = it->second;
        }
        enabled_extensions.emplace_back(extension_name);
    }

    return enabled_extensions;
}

static void BuildInstanceCreateInfo(std::ostream&                       out,
                                    const VkInstanceCreateInfo*         struct_info,
                                    const Decoded_VkInstanceCreateInfo* metaInfo,
                                    const std::string&                  var_name,
                                    VulkanCppConsumerBase&              consumer)
{
    // Collect enabled layer names except the GFXReconstruct's own layer.
    const std::vector<std::string> layerNames =
        FilterLayers(struct_info->ppEnabledLayerNames, struct_info->enabledLayerCount);

    std::string next_name                = GenerateExtension(out, struct_info->pNext, metaInfo->pNext, consumer);
    std::string app_info_struct_var_name = "NULL";
    if (struct_info->pApplicationInfo != NULL)
    {
        app_info_struct_var_name =
            "&" + GenerateStruct_VkApplicationInfo(
                      out, struct_info->pApplicationInfo, metaInfo->pApplicationInfo->GetMetaStructPointer(), consumer);
    }

    // Print out enabled layers if there is any
    std::string enabled_layers_value = "NULL";
    if (layerNames.size() > 0)
    {
        enabled_layers_value = "ppEnabledLayerNames_" + std::to_string(consumer.GetNextId());
        out << "\t\tconst char* " << enabled_layers_value
            << "[] = " << VulkanCppConsumerBase::EscapeStringArray(layerNames) << ";" << std::endl;
    }

    std::vector<std::string> extension_names;
    std::string              enabled_extensions_names = "NULL";
    if (struct_info->enabledExtensionCount > 0)
    {
        GfxToCppPlatform cur_platform       = consumer.GetPlatform();
        std::string      cur_extension_name = kTargetPlatforms.at(cur_platform).wsiSurfaceExtName;

        // Point every surface extension that the tool retargets at the extension
        // for this platform.  kTargetPlatforms is not the right list, because it
        // holds only the platforms that the tool can generate for.  A capture can
        // use a surface that is not a target, such as Xlib, and that surface still
        // needs rewriting.
        std::map<std::string, std::string> replace_map;
        for (const std::string& surface_extension : kRetargetedSurfaceExtensionNames)
        {
            replace_map[surface_extension] = cur_extension_name;
        }

        extension_names =
            ReplaceExtensions(struct_info->ppEnabledExtensionNames, struct_info->enabledExtensionCount, replace_map);

        enabled_extensions_names = "ppEnabledExtensionNames_" + std::to_string(consumer.GetNextId());
        out << "\t\tconst char* " << enabled_extensions_names
            << "[] = " << VulkanCppConsumerBase::EscapeStringArray(extension_names) << ";" << std::endl;
    }

    out << "\t\tVkInstanceCreateInfo " << var_name << " = {" << std::endl;
    out << "\t\t" << util::ToString<VkStructureType>(struct_info->sType) << ", // sType" << std::endl;
    out << "\t\t" << next_name << ", // pNext" << std::endl;
    out << "\t\t" << util::ToString<VkInstanceCreateFlags>(struct_info->flags) << ", // flags" << std::endl;
    out << "\t\t" << app_info_struct_var_name << ", // pApplicationInfo" << std::endl;
    out << "\t\t" << layerNames.size() << ", // enabledLayerCount" << std::endl;
    out << "\t\t" << enabled_layers_value << ", // ppEnabledLayerNames" << std::endl;
    out << "\t\t" << extension_names.size() << ", // enabledExtensionCount" << std::endl;
    out << "\t\t" << enabled_extensions_names << " // ppEnabledExtensionNames" << std::endl;
    out << "\t\t};" << std::endl;

    std::string vkInstanceCreateInfoVar = "VkInstanceCreateInfo " + var_name + ";\n";
}

void VulkanCppConsumerBase::Generate_vkCreateInstance(args::CreateInstance& args)
{
    FILE* file = GetFrameFile();

    std::string       create_info_struct_var_name = "pCreateInfo_" + std::to_string(GetNextId());
    std::stringstream stream_instance_create_info;
    BuildInstanceCreateInfo(stream_instance_create_info,
                            args.pCreateInfo.GetPointer(),
                            args.pCreateInfo.GetMetaStructPointer(),
                            create_info_struct_var_name,
                            *this);

    std::string instance_var_name = "instance_" + std::to_string(GetNextId(VK_OBJECT_TYPE_INSTANCE));
    AddKnownVariables("VkInstance", instance_var_name);

    fprintf(file, "\t{\n");
    fprintf(file, "%s", stream_instance_create_info.str().c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateInstance(&%s, %s, &%s), %s);\n",
            create_info_struct_var_name.c_str(),
            "nullptr",
            instance_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());

    fprintf(file, "\t\tloadFunctions(%s);\n", instance_var_name.c_str());
    fprintf(file, "\t}\n");

    if (args.result == VK_SUCCESS)
    {
        AddHandles(instance_var_name, args.pInstance.GetPointer());
    }
}

void VulkanCppConsumerBase::Generate_vkCreateDevice(args::CreateDevice& args)
{
    FILE* file = GetFrameFile();

    VkDeviceInfo* new_dev_info                   = new VkDeviceInfo();
    new_dev_info->parent                         = args.physicalDevice;
    device_info_map_[*args.pDevice.GetPointer()] = new_dev_info;

    // Remember which slot in the enumeration this device came from, and which
    // extensions it needed.  The generated source chooses a device with these.
    RecordDeviceSelectionData(args.physicalDevice, args.pCreateInfo.GetPointer());

    fprintf(file, "\t{\n");
    fprintf(file, "\t\tQueryPhysicalDeviceMemoryProperties(%s);\n", this->GetHandle(args.physicalDevice).c_str());
    // physicalDevice
    // pCreateInfo
    std::stringstream stream_pcreate_info;
    std::string       pcreate_info_struct = GenerateStruct_VkDeviceCreateInfo(
        stream_pcreate_info, args.pCreateInfo.GetPointer(), args.pCreateInfo.GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    // pAllocator
    // pDevice
    std::string pdevice_name = "pDevice_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_DEVICE));
    AddKnownVariables("VkDevice", pdevice_name, args.pDevice.GetPointer());
    if (args.result == VK_SUCCESS)
    {
        this->AddHandles(pdevice_name, args.pDevice.GetPointer());
    }
    // Take out the extensions that this device does not have, or vkCreateDevice
    // stops the program.
    fprintf(file,
            "\t\tFilterDeviceExtensions(%s, &%s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pcreate_info_struct.c_str());
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateDevice(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pdevice_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());

    fprintf(file, "\n");
    fprintf(file,
            "\t\tif (!toCppInitDeviceInfo(%s, %s, &%s)) {\n",
            this->GetHandle(args.physicalDevice).c_str(),
            pdevice_name.c_str(),
            pcreate_info_struct.c_str());
    fprintf(
        file,
        "\t\t\tprintf(\"ERROR: Failed to generate device info for device %s created from physical device %s\\n\");\n",
        pdevice_name.c_str(),
        this->GetHandle(args.physicalDevice).c_str());
    fprintf(file, "\t\t}\n");

    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkDestroyDevice(args::DestroyDevice& args)
{
    FILE* file = GetFrameFile();

    if (device_info_map_.find(args.device) != device_info_map_.end())
    {
        VkDeviceInfo* dev_info = device_info_map_[args.device];
        delete dev_info;
        device_info_map_.erase(args.device);
    }

    fprintf(file, "\t{\n");
    fprintf(file, "\t\ttoCppDestroyDeviceInfo(%s);\n", this->GetHandle(args.device).c_str());
    fprintf(file, "\n");
    fprintf(file, "\t\tvkDestroyDevice(%s, %s);\n", this->GetHandle(args.device).c_str(), "nullptr");
    fprintf(file, "\t}\n");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
