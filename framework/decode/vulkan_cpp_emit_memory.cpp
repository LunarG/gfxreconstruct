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

// Memory allocation, binding, and requirements.
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
void VulkanCppConsumerBase::Generate_vkGetBufferMemoryRequirements(args::GetBufferMemoryRequirements& args)
{
    FILE* file = GetFrameFile();

    std::string memory_requirements_var_name =
        "pMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    AddKnownVariables("VkMemoryRequirements", memory_requirements_var_name);

    fprintf(file,
            "\tvkGetBufferMemoryRequirements(%s, %s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.buffer).c_str(),
            memory_requirements_var_name.c_str());

    resource_memory_req_map_[args.buffer] = memory_requirements_var_name;

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetImageMemoryRequirements(args::GetImageMemoryRequirements& args)
{
    FILE* file = GetFrameFile();

    std::string memory_requirements_var_name =
        "pMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    AddKnownVariables("VkMemoryRequirements", memory_requirements_var_name);

    fprintf(file,
            "\tvkGetImageMemoryRequirements(%s, %s, &%s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.image).c_str(),
            memory_requirements_var_name.c_str());

    resource_memory_req_map_[args.image] = memory_requirements_var_name;

    fprintf(file, "\n");
}

void VulkanCppConsumerBase::Generate_vkGetBufferMemoryRequirements2(args::GetBufferMemoryRequirements2& args,
                                                                    const char*                         extension)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // device
    // pInfo
    std::stringstream stream_info;
    std::string       info_struct_name = GenerateStruct_VkBufferMemoryRequirementsInfo2(
        stream_info, args.pInfo.GetPointer(), args.pInfo.GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_info.str().c_str());
    // pMemoryRequirements
    std::string       memory_requirements_var_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_memory_requirements;
    memory_requirements_var_name = GenerateStruct_VkMemoryRequirements2(stream_memory_requirements,
                                                                        args.pMemoryRequirements.GetPointer(),
                                                                        args.pMemoryRequirements.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_memory_requirements.str().c_str());
    AddKnownVariables("VkMemoryRequirements2", memory_requirements_var_name);

    std::string method_name = "vkGetBufferMemoryRequirements2";
    method_name += extension;
    pfn_loader_.AddMethodName(method_name);

    fprintf(file,
            "\t\tloaded_%s(%s, &%s, &%s);\n",
            method_name.c_str(),
            this->GetHandle(args.device).c_str(),
            info_struct_name.c_str(),
            memory_requirements_var_name.c_str());
    fprintf(file, "\t}\n");
    resource_memory_req_map_[args.pInfo.GetMetaStructPointer()->buffer] = memory_requirements_var_name;
}

void VulkanCppConsumerBase::Generate_vkGetBufferMemoryRequirements2KHR(args::GetBufferMemoryRequirements2KHR& args)
{
    return Generate_vkGetBufferMemoryRequirements2(reinterpret_cast<args::GetBufferMemoryRequirements2&>(args), "KHR");
}

void VulkanCppConsumerBase::Generate_vkGetImageMemoryRequirements2(args::GetImageMemoryRequirements2& args,
                                                                   const char*                        extension)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // device
    // pInfo
    std::stringstream stream_info;
    std::string       info_struct_name = GenerateStruct_VkImageMemoryRequirementsInfo2(
        stream_info, args.pInfo.GetPointer(), args.pInfo.GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_info.str().c_str());
    // pMemoryRequirements
    std::string       memory_requirements_var_name = "pMemoryRequirements_" + std::to_string(this->GetNextId());
    std::stringstream stream_memory_requirements;
    memory_requirements_var_name = GenerateStruct_VkMemoryRequirements2(stream_memory_requirements,
                                                                        args.pMemoryRequirements.GetPointer(),
                                                                        args.pMemoryRequirements.GetMetaStructPointer(),
                                                                        *this);
    fprintf(file, "%s", stream_memory_requirements.str().c_str());
    AddKnownVariables("VkMemoryRequirements2", memory_requirements_var_name);

    std::string method_name = "vkGetImageMemoryRequirements2";
    method_name += extension;
    pfn_loader_.AddMethodName(method_name);

    fprintf(file,
            "\t\tloaded_%s(%s, &%s, &%s);\n",
            method_name.c_str(),
            this->GetHandle(args.device).c_str(),
            info_struct_name.c_str(),
            memory_requirements_var_name.c_str());
    fprintf(file, "\t}\n");
    resource_memory_req_map_[args.pInfo.GetMetaStructPointer()->image] = memory_requirements_var_name;
}

void VulkanCppConsumerBase::Generate_vkGetImageMemoryRequirements2KHR(args::GetImageMemoryRequirements2KHR& args)
{
    return Generate_vkGetImageMemoryRequirements2(reinterpret_cast<args::GetImageMemoryRequirements2&>(args), "KHR");
}

void VulkanCppConsumerBase::Generate_vkGetImageSparseMemoryRequirements(args::GetImageSparseMemoryRequirements& args)
{
    FILE* file = GetFrameFile();

    std::string spare_memory_reqs_count_var_name =
        "pSparseMemoryRequirementCount_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    fprintf(file, "\tuint32_t %s;\n", spare_memory_reqs_count_var_name.c_str());

    std::string sparse_mem_reqs_var_name =
        "pSparseMemoryRequirements_" + std::to_string(VulkanCppConsumerBase::GetNextId());
    const uint32_t* in_pSparseMemoryRequirementCount = args.pSparseMemoryRequirementCount.GetPointer();

    AddKnownVariables("VkSparseImageMemoryRequirements", sparse_mem_reqs_var_name, *in_pSparseMemoryRequirementCount);
    fprintf(file,
            "\tvkGetImageSparseMemoryRequirements(%s, %s, &%s, %s);\n",
            this->GetHandle(args.device).c_str(),
            this->GetHandle(args.image).c_str(),
            spare_memory_reqs_count_var_name.c_str(),
            sparse_mem_reqs_var_name.c_str());

    resource_memory_req_map_[args.image] = sparse_mem_reqs_var_name;
}

void VulkanCppConsumerBase::Generate_vkMapMemory(args::MapMemory& args)
{
    std::string data_var_name = "ppData_" + std::to_string(GetNextId());
    AddKnownVariables("void*", data_var_name);

    fprintf(GetFrameFile(),
            "\tVK_CALL_CHECK(vkMapMemory(%s, %s, %" PRIu64 "UL, %" PRIu64 "UL, %s, &%s), %s);\n",
            handle_id_map_[args.device].c_str(),
            handle_id_map_[args.memory].c_str(),
            args.offset,
            args.size,
            util::ToString<VkMemoryMapFlags>(args.flags).c_str(),
            data_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());

    memory_id_map_[(uint64_t)args.memory] = data_var_name;
}

void VulkanCppConsumerBase::Generate_vkUnmapMemory(args::UnmapMemory& args)
{
    fprintf(GetFrameFile(),
            "\tvkUnmapMemory(%s, %s);\n",
            handle_id_map_[args.device].c_str(),
            handle_id_map_[args.memory].c_str());

    memory_id_map_[(uint64_t)args.memory] = "<<INVALID>>";
}

void VulkanCppConsumerBase::Generate_vkAllocateMemory(args::AllocateMemory& args)
{
    FILE* file = GetFrameFile();

    fprintf(file, "\t{\n");

    // Check to see if we need to worry about opaque memory here.
    VkDeviceInfo* dev_info = nullptr;
    if (device_info_map_.find(args.device) != device_info_map_.end())
    {
        dev_info                       = device_info_map_[args.device];
        format::HandleId memory_handle = *args.pMemory.GetPointer();

        // If we don't have this memory handle in the opaque address list, set it back to NULL since we
        // won't be using it here.
        if (dev_info->opaque_addresses.find(memory_handle) == dev_info->opaque_addresses.end())
        {
            dev_info = nullptr;
        }
        else
        {
            // Create a opaque memory struct for use in the pNext chain in case we need it.
            // and set all the appropriate variables that can be used to track if it is needed.
            // This way the various pNext structures can just use these variables to determine
            // the appropriate action.
            fprintf(file, "\t\tVkMemoryOpaqueCaptureAddressAllocateInfo address_info = {\n");
            fprintf(file, "\t\t\tVK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO,\n");
            fprintf(file, "\t\t};\n");
            fprintf(file, "\n");

            fprintf(file, "\t\tbool     can_use_opaque_address = false;\n");
            fprintf(file, "\t\tbool     uses_opaque_address    = false;\n");
            fprintf(file, "\t\tbool     imports_memory         = false;\n");
            fprintf(file, "\n");
            fprintf(file,
                    "\t\tif (g_device_info.find(%s) != g_device_info.end()){\n",
                    this->GetHandle(args.device).c_str());
            fprintf(
                file, "\t\t\tToCppDeviceInfo* dev_info = g_device_info[%s];\n", this->GetHandle(args.device).c_str());
            fprintf(file, "\t\t\tif (dev_info->features.features_dev_buf_addr.bufferDeviceAddressCaptureReplay ||\n");
            fprintf(file, "\t\t\t    dev_info->features.features_1_2.bufferDeviceAddressCaptureReplay) {\n");
            fprintf(file, "\t\t\t\tcan_use_opaque_address = true;\n");
            fprintf(file,
                    "\t\t\t\taddress_info.opaque_address = %" PRIu64 "ULL;\n",
                    dev_info->opaque_addresses[memory_handle]);
            fprintf(file, "\t\t\t}\n");
            fprintf(file, "\n");
        }
    }

    std::stringstream stream_alloc_info;
    std::string       alloc_info_struct_var_name =
        GenerateStruct_VkMemoryAllocateInfo(stream_alloc_info,
                                            *args.pMemory.GetPointer(),
                                            args.pAllocateInfo.GetPointer(),
                                            args.pAllocateInfo.GetMetaStructPointer(),
                                            *this);
    fprintf(file, "%s", stream_alloc_info.str().c_str());
    std::string memory_var_name = "pMemory_" + std::to_string(this->GetNextId());
    AddKnownVariables("VkDeviceMemory", memory_var_name, args.pMemory.GetPointer());
    if (args.result == VK_SUCCESS)
    {
        this->AddHandles(memory_var_name, args.pMemory.GetPointer());
    }

    // Now that the pNext items are done, perform any work that needs to be done last and update
    // the vkMemoryAllocationInfo pNext array to start with our custom one.
    if (dev_info != nullptr)
    {
        fprintf(file, "\t\tif (uses_opaque_address) {\n");
        fprintf(file, "\t\t\tif (imports_memory) {\n");
        fprintf(file,
                "\t\t\t\t// The Vulkan spec states: If the pNext chain includes a VkImportMemoryHostPointerInfoEXT\n");
        fprintf(file,
                "\t\t\t\t// structure, VkMemoryOpaqueCaptureAddressAllocateInfo::opaqueCaptureAddress must be zer\n");
        fprintf(file, "\t\t\t\taddress_info.opaque_address = 0;\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "\t\t\taddress_info.pNext = %s.pNext;\n", alloc_info_struct_var_name.c_str());
        fprintf(file, "\t\t\t%s.pNext = &address_info;\n", alloc_info_struct_var_name.c_str());
        fprintf(file, "\t\t}\n");
    }

    fprintf(file,
            "\t\tVK_CALL_CHECK(vkAllocateMemory(%s, &%s, %s, &%s), %s);\n",
            GetHandle(args.device).c_str(),
            alloc_info_struct_var_name.c_str(),
            "nullptr",
            memory_var_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkCreateBuffer(args::CreateBuffer& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");

    VkDeviceInfo*    dev_info      = nullptr;
    format::HandleId buffer_handle = *args.pBuffer.GetPointer();
    if (device_info_map_.find(args.device) != device_info_map_.end())
    {
        dev_info = device_info_map_[args.device];
        if (dev_info != nullptr)
        {
            // Determine if this buffer uses an opaque address, if so, we need to search through the
            // buffer usage and set additional flags as necessary and record the appropriate address.
            if (dev_info->opaque_addresses.find(buffer_handle) != dev_info->opaque_addresses.end())
            {
                // This is only used in certain cases, but it needs to be scoped locally to this function for it to be
                // valid
                fprintf(file, "\t\tVkBufferOpaqueCaptureAddressCreateInfo address_info = {\n");
                fprintf(file, "\t\t\tVK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO\n");
                fprintf(file, "\t\t};\n");
                fprintf(file, "\n");
            }
            else
            {
                // Nothing to do here.
                dev_info = nullptr;
            }
        }
    }

    std::stringstream stream_pcreate_info;
    std::string       pcreate_info_struct = GenerateStruct_VkBufferCreateInfo(
        stream_pcreate_info, args.pCreateInfo.GetPointer(), args.pCreateInfo.GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_pcreate_info.str().c_str());
    std::string pbuffer_name = "pBuffer_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_BUFFER));

    if (dev_info != nullptr)
    {
        fprintf(
            file, "\t\tif (g_device_info.find(%s) != g_device_info.end()){\n", this->GetHandle(args.device).c_str());
        fprintf(file, "\t\t\tToCppDeviceInfo* dev_info = g_device_info[%s];\n", this->GetHandle(args.device).c_str());
        fprintf(file, "\t\t\tif (dev_info->features.features_dev_buf_addr.bufferDeviceAddressCaptureReplay ||\n");
        fprintf(file, "\t\t\t    dev_info->features.features_1_2.bufferDeviceAddressCaptureReplay) {\n");
        fprintf(file, "\t\t\t\tbool                uses_address         = false;\n");
        fprintf(file, "\t\t\t\tVkBufferCreateFlags address_create_flags = 0;\n");
        fprintf(file, "\t\t\t\tVkBufferUsageFlags  address_usage_flags  = 0;\n");
        fprintf(file, "\n");
        fprintf(file,
                "\t\t\t\tif ((%s.usage & VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT) ==\n",
                pcreate_info_struct.c_str());
        fprintf(file, "\t\t\t\t    VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT)\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t    uses_address = true;\n");
        fprintf(file, "\t\t\t\t    address_create_flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file,
                "\t\t\t\tif ((%s.usage & VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR) ==\n",
                pcreate_info_struct.c_str());
        fprintf(file, "\t\t\t\t    VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR)\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t    uses_address = true;\n");
        fprintf(file, "\t\t\t\t    address_create_flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;\n");
        fprintf(file, "\t\t\t\t    address_usage_flags |= VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT;\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\n");

        fprintf(file, "\t\t\t\tif (uses_address)\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file,
                "\t\t\t\t\taddress_info.opaqueCaptureAddress = %" PRIu64 "LLU;\n",
                dev_info->opaque_addresses[buffer_handle]);
        fprintf(file, "\n");
        fprintf(file,
                "\t\t\t\t\t// The shallow copy of VkBufferCreateInfo references the same pNext list from the "
                "copy source.  We insert\n");
        fprintf(file,
                "\t\t\t\t\t// the buffer address extension struct at the start of the list to avoid modifying "
                "the original by appending\n");
        fprintf(file, "\t\t\t\t\t// to the end.\n");
        fprintf(file, "\t\t\t\t\taddress_info.pNext = %s.pNext;\n", pcreate_info_struct.c_str());
        fprintf(file, "\t\t\t\t\t%s.pNext = &address_info;\n", pcreate_info_struct.c_str());
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\t\t%s.flags |= address_create_flags;\n", pcreate_info_struct.c_str());
        fprintf(file, "\t\t\t\t\t%s.usage |= address_usage_flags;\n", pcreate_info_struct.c_str());
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "\t\t}\n");
    }

    AddKnownVariables("VkBuffer", pbuffer_name, args.pBuffer.GetPointer());
    if (args.result == VK_SUCCESS)
    {
        this->AddHandles(pbuffer_name, args.pBuffer.GetPointer());
    }
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkCreateBuffer(%s, &%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            pcreate_info_struct.c_str(),
            "nullptr",
            pbuffer_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Intercept_vkBindImageMemory(args::BindImageMemory& args)
{
    memory_resource_map_[args.memory].emplace(std::make_pair(args.image, args.memoryOffset));
}

void VulkanCppConsumerBase::Intercept_vkBindImageMemory2(args::BindImageMemory2& args, const char* extension)
{
    for (uint32_t index = 0; index < args.bindInfoCount; ++index)
    {
        const VkBindImageMemoryInfo* cur_image_memory = args.pBindInfos.GetPointer() + index;
        memory_resource_map_[(format::HandleId)cur_image_memory->memory].emplace(
            std::make_pair((format::HandleId)cur_image_memory->image, cur_image_memory->memoryOffset));
    }
}

void VulkanCppConsumerBase::Intercept_vkBindBufferMemory(args::BindBufferMemory& args)
{
    memory_resource_map_[args.memory].emplace(std::make_pair(args.buffer, args.memoryOffset));
}

void VulkanCppConsumerBase::Intercept_vkBindBufferMemory2(args::BindBufferMemory2& args)
{
    for (uint32_t index = 0; index < args.bindInfoCount; ++index)
    {
        const VkBindBufferMemoryInfo* cur_buffer_memory = args.pBindInfos.GetPointer() + index;
        memory_resource_map_[(format::HandleId)cur_buffer_memory->memory].emplace(
            std::make_pair((format::HandleId)cur_buffer_memory->buffer, cur_buffer_memory->memoryOffset));
    }
}

void VulkanCppConsumerBase::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                     uint64_t       offset,
                                                     uint64_t       size,
                                                     const uint8_t* data)
{
    const SavedFileInfo file_info = data_packer_.AddFileContents(data, size);

    auto entry = memory_id_map_.find(memory_id);
    if (entry != memory_id_map_.end())
    {
        GenerateLoadData(file_info.file_path, file_info.byte_offset, memory_id_map_[memory_id].c_str(), offset, size);
    }
    else if (android_memory_id_map_.find(memory_id) != android_memory_id_map_.end())
    {
        // Update the memory using the Android Hardware buffer path (using "vulkan_replay_consumer_base" as a reference)
        VulkanCppAndroidMemoryInfo android_memory_info = android_memory_id_map_[memory_id];
        std::string                android_hw_mem_name = android_memory_info.name;
        FILE*                      file                = GetFrameFile();
        fprintf(file, "#if defined(VK_USE_PLATFORM_ANDROID_KHR)\n");
        fprintf(file, "\t{\n");
        fprintf(file, "\t\tresult            = VK_SUCCESS;\n");
        fprintf(file, "\t\tvoid* buffer_data = nullptr;\n");
        fprintf(file, "\t\tint lock_result   = AHardwareBuffer_lock(\n");
        fprintf(file,
                "\t\t\t%s, AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN, -1, nullptr, &buffer_data);\n",
                android_memory_info.buffer_name.c_str());
        fprintf(file, "\t\tif (lock_result == 0)\n");
        fprintf(file, "\t\t{\n");
        fprintf(file, "\t\t\tassert(buffer_data != nullptr);\n");
        fprintf(file, "\t\t\tif (%s.plane_info.size() == 1)\n", android_hw_mem_name.c_str());
        fprintf(file, "\t\t\t{\n");
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, offset);
        fprintf(file, "\t\t\t\tsize_t   data_size         = static_cast<size_t>(%" PRIu64 ");\n", size);
        fprintf(file, "\t\t\t\tsize_t   data_offset       = static_cast<size_t>(%" PRIu64 ");\n", offset);
        fprintf(file,
                "\t\t\t\tsize_t   capture_row_pitch = %s.plane_info[0].capture_row_pitch;\n",
                android_hw_mem_name.c_str());
        fprintf(file,
                "\t\t\t\tsize_t   replay_row_pitch  = %s.plane_info[0].replay_row_pitch;\n",
                android_hw_mem_name.c_str());
        fprintf(file, "\t\t\t\tuint32_t height            = %s.plane_info[0].height;\n", android_hw_mem_name.c_str());
        fprintf(file, "\t\t\t\tCopyImageSubresourceMemory(\"%s\",\n", file_info.file_path.c_str());
        fprintf(file, "\t\t\t\t\t\t\t\t\t%" PRIu64 ",\n", file_info.byte_offset);
        fprintf(file, "\t\t\t\t\t\t\t\t\tstatic_cast<uint8_t*>(buffer_data),\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\tdata_offset,\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\tdata_size,\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\treplay_row_pitch,\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\tcapture_row_pitch,\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\theight,\n");
        fprintf(file, "\t\t\t\t\t\t\t\t\tappdata);\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "\t\t\telse\n");
        fprintf(file, "\t\t\t{\n");
        fprintf(file, "\t\t\t\t// TODO: multi-plane image format support when strides do not match.\n");
        fprintf(file,
                "\t\t\t\tprintf(\"ERROR: Ignoring fill memory command for AHardwareBuffer with multi-plane "
                "format and\"\n");
        fprintf(file, "\t\t\t\t\t\"mismatched capture/replay strides (Memory ID = %%\" PRIu64\n");
        fprintf(file, "\t\t\t\t\t\"): support not yet implemented\",\n");
        fprintf(file, "\t\t\t\t\t%" PRIu64 ");\n", memory_id);
        fprintf(file, "\t\t\t}\n");
        fprintf(file,
                "\t\t\tlock_result = AHardwareBuffer_unlock(%s, nullptr);\n",
                android_memory_info.buffer_name.c_str());
        fprintf(file, "\t\t\tif (lock_result != 0)\n");
        fprintf(file, "\t\t\t{\n");
        fprintf(file,
                "\t\t\t\tprintf(\"ERROR: AHardwareBuffer_unlock failed for AHardwareBuffer object (Memory ID = "
                "%%\" PRIu64 \")\",\n");
        fprintf(file, "\t\t\t\t\t\t%" PRIu64 ");\n", memory_id);
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "\t\t}\n");
        fprintf(file, "\t\telse\n");
        fprintf(file, "\t\t{\n");
        fprintf(file,
                "\t\t\tprintf(\"ERROR: AHardwareBuffer_lock failed for AHardwareBuffer object (Memory ID = %%\" "
                "PRIu64 \")\",\n");
        fprintf(file, "\t\t\t\t\t%" PRIu64 ");\n", memory_id);
        fprintf(file, "\t\t}\n");
        fprintf(file, "\t}\n");
        fprintf(file, "#endif\n");
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
