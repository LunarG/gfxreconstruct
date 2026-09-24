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

// Android hardware buffer support.
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
void VulkanCppConsumerBase::ProcessCreateHardwareBufferCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    memory_id,
    uint64_t                                            buffer_id,
    uint32_t                                            format,
    uint32_t                                            width,
    uint32_t                                            height,
    uint32_t                                            stride,
    uint64_t                                            usage,
    uint32_t                                            layers,
    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    // Create an Android Hardware buffer using the code from "vulkan_replay_consumer_base" as a reference.
    if (platform_ == GfxToCppPlatform::PLATFORM_ANDROID)
    {
        FILE* file = GetFrameFile();

        VulkanCppAndroidBufferInfo buffer_info;
        buffer_info.name      = "and_hw_buffer_" + std::to_string(GetNextId());
        buffer_info.memory_id = memory_id;
        AddKnownVariables("AHardwareBuffer*", buffer_info.name);
        android_buffer_id_map_[buffer_id] = buffer_info;

        VulkanCppAndroidMemoryInfo memory_info;
        memory_info.name        = "and_hw_buf_mem_info_" + std::to_string(GetNextId());
        memory_info.buffer_name = buffer_info.name;
        AddKnownVariables("HardwareBufferMemoryInfo", memory_info.name);
        android_memory_id_map_[memory_id] = memory_info;

        std::string memory_name;
        if (memory_id_map_.find(memory_id) != memory_id_map_.end())
        {
            memory_name = memory_id_map_[memory_id];
        }

        fprintf(file, "\t{\n");
        fprintf(file, "\t\tAHardwareBuffer_Desc desc = {};\n");
        fprintf(file, "\t\tdesc.format               = %u;\n", format);
        fprintf(file, "\t\tdesc.height               = %u;\n", height);
        fprintf(file, "\t\tdesc.layers               = %u;\n", layers);
        fprintf(file, "\t\tdesc.usage                = %" PRIu64 ";\n", usage);
        fprintf(file, "\t\tdesc.width                = %u;\n", width);
        fprintf(file, "\n");
        fprintf(file, "\t\tint ahwbuf_res = AHardwareBuffer_allocate(&desc, &%s);\n", buffer_info.name.c_str());
        fprintf(file, "\t\tif (ahwbuf_res == 0 && %s != nullptr)\n", buffer_info.name.c_str());
        fprintf(file, "\t\t{\n");
        fprintf(file, "\t\t\tahwbuf_res = -1;\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\tstd::vector<HardwareBufferPlaneInfo> replay_plane_info;\n");
        fprintf(file, "\n");
        fprintf(
            file,
            "// The multi-plane functions are declared for API 26, but are only available to link with API 29.  So, "
            "this\n");
        fprintf(file, "// could be turned into a run-time check dependent on dlsym returning a valid pointer for\n");
        fprintf(file, "// AHardwareBuffer_lockPlanes.\n");
        fprintf(file, "#if __ANDROID_API__ >= 29\n");
        fprintf(file, "\t\t\tif (desc.usage & AHARDWAREBUFFER_USAGE_CPU_WRITE_MASK)\n");
        fprintf(file, "\t\t\t{\n");
        fprintf(file, "\t\t\t\tAHardwareBuffer_Planes ahb_planes;\n");
        fprintf(file, "\t\t\t\tahwbuf_res =\n");
        fprintf(file,
                "\t\t\t\t\tAHardwareBuffer_lockPlanes(buffer, AHARDWAREBUFFER_USAGE_CPU_WRITE_OFTEN, -1, "
                "nullptr, &ahb_planes);\n");
        fprintf(file, "\t\t\t\tif (ahwbuf_res == 0)\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\tvoid* data = ahb_planes.planes[0].data;\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\t\tfor (uint32_t i = 0; i < ahb_planes.planeCount; ++i)\n");
        fprintf(file, "\t\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\t\tHardwareBufferPlaneInfo ahb_plane_info;\n");
        fprintf(file, "\t\t\t\t\t\tahb_plane_info.offset =\n");
        fprintf(file,
                "\t\t\t\t\t\t\treinterpret_cast<uint8_t*>(ahb_planes.planes[i].data) - "
                "reinterpret_cast<uint8_t*>(data);\n");
        fprintf(file, "\t\t\t\t\t\tahb_plane_info.pixel_stride = ahb_planes.planes[i].pixelStride;\n");
        fprintf(file, "\t\t\t\t\t\tahb_plane_info.row_pitch    = ahb_planes.planes[i].rowStride;\n");
        fprintf(file, "\t\t\t\t\t\treplay_plane_info.emplace_back(std::move(ahb_plane_info));\n");
        fprintf(file, "\t\t\t\t\t}\n");
        fprintf(file, "\n");
        fprintf(file, "\t\t\t\t\t\tif (AHardwareBuffer_unlock(buffer, nullptr) != 0)\n");
        fprintf(file, "\t\t\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\t\t\tprintf(\"ERROR: AHardwareBuffer_unlock failed for AHardwareBuffer object\"\n");
        if (memory_name.length() > 0)
        {
            fprintf(
                file, "\t\t\t\t\t\t\t\"(Buffer %s, Memory %s)\");\n", buffer_info.name.c_str(), memory_name.c_str());
        }
        else
        {
            fprintf(file, "\t\t\t\t\t\t\t\"(Buffer %s)\");\n", buffer_info.name.c_str());
        }
        fprintf(file, "\t\t\t\t\t}\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\t\t\t\telse\n");
        fprintf(file, "\t\t\t\t{\n");
        fprintf(file, "\t\t\t\t\tprintf(\"WARNING: AHardwareBuffer_lockPlanes failed.\");\n");
        fprintf(file, "\t\t\t\t}\n");
        fprintf(file, "\t\t\t}\n");
        fprintf(file, "#endif\n");

        fprintf(file, "\n");
        fprintf(file, "\t\t\t%s.compatible_strides = true;\n", memory_info.name.c_str());
        fprintf(file, "\n");
        fprintf(file, "\t\t\t// Check for matching strides.\n");
        if (plane_info.empty())
        {
            fprintf(file, "\t\t\tuint32_t bpp = GetHardwareBufferFormatBpp(%u);\n", format);
            fprintf(file, "\n");
            fprintf(file, "\t\t\tAHardwareBuffer_describe(%s, &desc);\n", buffer_info.name.c_str());
            fprintf(file, "\t\t\tif (%u != desc.stride)\n", stride);
            fprintf(file, "\t\t\t{\n");
            fprintf(file, "\t\t\t\t%s.compatible_strides = false;\n", memory_info.name.c_str());
            fprintf(file, "\t\t\t}\n");
            fprintf(file, "\n");
            fprintf(file, "\t\t\t%s.plane_info.resize(1);\n", memory_info.name.c_str());
            fprintf(file, "\t\t\t%s.plane_info[0].capture_offset    = 0;\n", memory_info.name.c_str());
            fprintf(file, "\t\t\t%s.plane_info[0].replay_offset     = 0;\n", memory_info.name.c_str());
            fprintf(file, "\t\t\t%s.plane_info[0].capture_row_pitch = bpp * %u;\n", memory_info.name.c_str(), stride);
            fprintf(file, "\t\t\t%s.plane_info[0].replay_row_pitch  = bpp * desc.stride;\n", memory_info.name.c_str());
            fprintf(file, "\t\t\t%s.plane_info[0].height            = %u;\n", memory_info.name.c_str(), height);
        }
        else
        {
            fprintf(file,
                    "\t\t\t%s.plane_info.resize(%" PRIu64 ");\n",
                    memory_info.name.c_str(),
                    util::platform::SizeTtoUint64(plane_info.size()));
            fprintf(file, "\n");
            for (uint32_t i = 0; i < static_cast<uint32_t>(plane_info.size()); ++i)
            {
                fprintf(file,
                        "\t\t\t%s.plane_info[%u].capture_offset    = %" PRId64 ";\n",
                        memory_info.name.c_str(),
                        i,
                        plane_info[i].offset);
                fprintf(file,
                        "\t\t\t%s.plane_info[%u].replay_offset     = replay_plane_info[%u].offset;\n",
                        memory_info.name.c_str(),
                        i,
                        i);
                fprintf(file,
                        "\t\t\t%s.plane_info[%u].capture_row_pitch = %u;\n",
                        memory_info.name.c_str(),
                        i,
                        plane_info[i].row_pitch);
                fprintf(file,
                        "\t\t\t%s.plane_info[%u].replay_row_pitch  = replay_plane_info[%u].row_pitch;\n",
                        memory_info.name.c_str(),
                        i,
                        i);
                fprintf(file, "\t\t\t%s.plane_info[%u].height            = %u;\n", memory_info.name.c_str(), i, height);
                fprintf(file, "\n");
                fprintf(file, "\t\t\tif ((%" PRIu64 " != replay_plane_info[%u].offset) ||\n", plane_info[i].offset, i);
                fprintf(file, "\t\t\t\t(%u != replay_plane_info[%u].row_pitch))\n", plane_info[i].row_pitch, i);
                fprintf(file, "\t\t\t{\n");
                fprintf(file, "\t\t\t\t%s.compatible_strides = false;\n", memory_info.name.c_str());
                fprintf(file, "\t\t\t}\n");
            }
        }

        fprintf(file, "\t\t}\n");
        fprintf(file, "\t\telse\n");
        fprintf(file, "\t\t{\n");
        fprintf(file, "\t\t\tprintf(\"ERROR: AHardwareBuffer_allocate failed for AHardwareBuffer object \"\n");
        if (memory_name.length() > 0)
        {
            fprintf(file, "\t\t\t\t\t\"(Buffer %s, Memory %s)\");\n", buffer_info.name.c_str(), memory_name.c_str());
        }
        else
        {
            fprintf(file, "\t\t\t\t\t\"(Buffer %s)\");\n", buffer_info.name.c_str());
        }
        fprintf(file, "\t\t}\n");
        fprintf(file, "\t}\n");
    }
}

bool VulkanCppConsumerBase::SupportsAndroidHardwareBuffers()
{
    if (platform_ == GfxToCppPlatform::PLATFORM_ANDROID)
    {
        return true;
    }

    if (!warned_about_android_hardware_buffers_)
    {
        warned_about_android_hardware_buffers_ = true;
        GFXRECON_LOG_WARNING("The capture file uses Android hardware buffers.  The target platform does not have "
                             "them, so the generated source leaves that work out.  Use \"-t android\" to keep it.");
    }
    return false;
}

std::string VulkanCppConsumerBase::GetAndroidHwBufferName(uint64_t buffer)
{
    if (android_buffer_id_map_.find(buffer) != android_buffer_id_map_.end())
    {
        return android_buffer_id_map_[buffer].name;
    }
    return "VK_NULL_HANDLE";
}

void VulkanCppConsumerBase::Generate_vkGetAndroidHardwareBufferPropertiesANDROID(
    args::GetAndroidHardwareBufferPropertiesANDROID& args)
{
    if (!SupportsAndroidHardwareBuffers())
    {
        return;
    }

    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");

    std::string buffer_name;
    if (android_buffer_id_map_.find(args.buffer) == android_buffer_id_map_.end())
    {
        buffer_name = "buffer_" + std::to_string(this->GetNextId());
        fprintf(file, "\t\tvoid* %s;\n", buffer_name.c_str());
    }
    else
    {
        buffer_name = android_buffer_id_map_[args.buffer].name;
    }

    std::string       properties_name = "properties_" + std::to_string(this->GetNextId());
    std::stringstream stream_properties;
    properties_name = GenerateStruct_VkAndroidHardwareBufferPropertiesANDROID(
        stream_properties, args.pProperties.GetPointer(), args.pProperties.GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_properties.str().c_str());
    pfn_loader_.AddMethodName("vkGetAndroidHardwareBufferPropertiesANDROID");
    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetAndroidHardwareBufferPropertiesANDROID(%s, %s, &%s), %s);\n",
            this->GetHandle(args.device).c_str(),
            buffer_name.c_str(),
            properties_name.c_str(),
            util::ToString<VkResult>(args.result).c_str());

    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkGetMemoryAndroidHardwareBufferANDROID(
    args::GetMemoryAndroidHardwareBufferANDROID& args)
{
    if (!SupportsAndroidHardwareBuffers())
    {
        return;
    }

    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");

    std::stringstream stream_info;
    std::string       info_struct = GenerateStruct_VkMemoryGetAndroidHardwareBufferInfoANDROID(
        stream_info, args.pInfo.GetPointer(), args.pInfo.GetMetaStructPointer(), *this);
    fprintf(file, "%s", stream_info.str().c_str());

    format::HandleId memory_id = args.pInfo.GetMetaStructPointer()->memory;

    std::string buffer_name;
    std::string buffer_argument;
    if (args.pBuffer.IsNull())
    {
        buffer_name     = "";
        buffer_argument = "nullptr";
    }
    else
    {
        buffer_name     = "and_hw_buffer_" + std::to_string(GetNextId());
        buffer_argument = "&" + buffer_name;
    }

    VulkanCppAndroidBufferInfo buffer_info;
    buffer_info.name      = buffer_name;
    buffer_info.memory_id = memory_id;
    AddKnownVariables("AHardwareBuffer*", buffer_info.name);

    // TODO: Not sure if this is necessary
    VulkanCppAndroidMemoryInfo memory_info;
    memory_info.name                  = "";
    memory_info.buffer_name           = buffer_name;
    android_memory_id_map_[memory_id] = memory_info;

    pfn_loader_.AddMethodName("vkGetMemoryAndroidHardwareBufferANDROID");

    fprintf(file,
            "\t\tVK_CALL_CHECK(loaded_vkGetMemoryAndroidHardwareBufferANDROID(%s, &%s, %s), %s);\n",
            this->GetHandle(args.device).c_str(),
            info_struct.c_str(),
            buffer_argument.c_str(),
            util::ToString<VkResult>(args.result).c_str());

    android_buffer_id_map_[*args.pBuffer.GetPointer()] = buffer_info;

    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::ProcessDestroyHardwareBufferCommand(uint64_t buffer_id)
{
    if (android_buffer_id_map_.find(buffer_id) != android_buffer_id_map_.end())
    {
        auto& buffer_info = android_buffer_id_map_[buffer_id];
        FILE* file        = GetFrameFile();
        fprintf(file, "\t{\n");
        fprintf(file, "\t\tAHardwareBuffer_release(%s);\n", android_buffer_id_map_[buffer_id].name.c_str());
        android_memory_id_map_.erase(buffer_info.memory_id);
        android_buffer_id_map_.erase(buffer_id);
        fprintf(file, "\t}\n");
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
