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

// Queues, submits, fences, and query pools.
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
void VulkanCppConsumerBase::Generate_vkGetFenceStatus(args::GetFenceStatus& args)
{
    if (args.result == VK_SUCCESS)
    {
        fprintf(GetFrameFile(),
                "\twhile (vkGetFenceStatus(%s, %s) != VK_SUCCESS) { usleep(5000); }\n",
                this->GetHandle(args.device).c_str(),
                this->GetHandle(args.fence).c_str());
    }
    else
    {
        fprintf(GetFrameFile(),
                "\tVK_CALL_CHECK(vkGetFenceStatus(%s, %s), %s);\n",
                this->GetHandle(args.device).c_str(),
                this->GetHandle(args.fence).c_str(),
                util::ToString<VkResult>(args.result).c_str());
    }
}

void VulkanCppConsumerBase::Generate_vkGetQueryPoolResults(args::GetQueryPoolResults& args)
{
    FILE* file = GetFrameFile();

    // Try to re-use a temporary memory storage big enough to store this.
    std::string temp_memory_name;
    for (auto& temp_memory : frame_split_temp_memory_)
    {
        if (temp_memory.size >= args.dataSize)
        {
            temp_memory_name = temp_memory.name;
            break;
        }
    }
    if (temp_memory_name.size() == 0)
    {
        FrameTempMemory temp_memory;
        temp_memory.name = "pData_" + std::to_string(this->GetNextId());
        temp_memory.size = args.dataSize;
        frame_split_temp_memory_.push_back(temp_memory);
        temp_memory_name = temp_memory.name;

        fprintf(file,
                "\tuint8_t %s[%" PRIu64 "];\n",
                temp_memory_name.c_str(),
                util::platform::SizeTtoUint64(args.dataSize));
    }

    if (args.result == VK_SUCCESS)
    {
        fprintf(file,
                "\twhile (vkGetQueryPoolResults(%s, %s, %u, %u, %" PRIu64 "UL, %s, %" PRIu64
                "UL, %s) != VK_SUCCESS) { usleep(5000); }\n",
                GetHandle(args.device).c_str(),
                GetHandle(args.queryPool).c_str(),
                args.firstQuery,
                args.queryCount,
                util::platform::SizeTtoUint64(args.dataSize),
                temp_memory_name.c_str(),
                args.stride,
                util::ToString<VkQueryResultFlags>(args.flags).c_str());
    }
    else
    {
        fprintf(file,
                "\tVK_CALL_CHECK(vkGetQueryPoolResults(%s, %s, %u, %u, %" PRIu64 "UL, %s, %" PRIu64 "UL, %s), %s);\n",
                GetHandle(args.device).c_str(),
                GetHandle(args.queryPool).c_str(),
                args.firstQuery,
                args.queryCount,
                util::platform::SizeTtoUint64(args.dataSize),
                temp_memory_name.c_str(),
                args.stride,
                util::ToString<VkQueryResultFlags>(args.flags).c_str(),
                util::ToString<VkResult>(args.result).c_str());
    }
}

void VulkanCppConsumerBase::Intercept_vkDestroySemaphore(args::DestroySemaphore& args)
{
    if (args.semaphore != format::kNullHandleId)
    {
        imported_semaphores_.erase(
            std::remove(imported_semaphores_.begin(), imported_semaphores_.end(), args.semaphore),
            imported_semaphores_.end());
    }
}

void VulkanCppConsumerBase::Generate_vkWaitForFences(args::WaitForFences& args)
{
    FILE*       file = GetFrameFile();
    char        indent_tabs[16];
    std::string fences_array     = "NULL";
    std::string fences_var_names = toStringJoin(
        args.pFences.GetPointer(),
        args.pFences.GetPointer() + args.fenceCount,
        [&](const format::HandleId current) { return GetHandle(current); },
        ", ");
    if (args.fenceCount == 1)
    {
        fences_array   = "&" + fences_var_names;
        indent_tabs[0] = '\t';
        indent_tabs[1] = '\0';
    }
    else if (args.fenceCount > 1)
    {
        fprintf(file, "\t{\n");
        fences_array = "fences_array_" + std::to_string(GetNextId());
        fprintf(file, "\t\tVkFence %s[] = { %s };\n", fences_array.c_str(), fences_var_names.c_str());
        indent_tabs[0] = '\t';
        indent_tabs[1] = '\t';
        indent_tabs[2] = '\0';
    }
    if (args.result == VK_SUCCESS)
    {
        fprintf(file,
                "%swhile (vkWaitForFences(%s, %u, %s, %u, %" PRIu64 "UL) != VK_SUCCESS) { usleep(5000); };\n",
                indent_tabs,
                GetHandle(args.device).c_str(),
                args.fenceCount,
                fences_array.c_str(),
                args.waitAll,
                args.timeout);
    }
    else
    {
        fprintf(file,
                "%sVK_CALL_CHECK(vkWaitForFences(%s, %u, %s, %u, %" PRIu64 "UL), %s);\n",
                indent_tabs,
                GetHandle(args.device).c_str(),
                args.fenceCount,
                fences_array.c_str(),
                args.waitAll,
                args.timeout,
                util::ToString<VkResult>(args.result).c_str());
    }
    if (args.fenceCount > 1)
    {
        fprintf(file, "\t}\n");
    }
}

void VulkanCppConsumerBase::Generate_vkGetSemaphoreWin32HandleKHR(args::GetSemaphoreWin32HandleKHR& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t// vkGetSemaphoreWin32HandleKHR ignored\n");

    // No other work necessary because we're not actually sharing the semaphore during replay
}

void VulkanCppConsumerBase::Generate_vkImportSemaphoreWin32HandleKHR(args::ImportSemaphoreWin32HandleKHR& args)
{
    // Add the semaphore to the list of imported semaphores
    imported_semaphores_.push_back(args.pImportSemaphoreWin32HandleInfo.GetMetaStructPointer()->semaphore);

    // No other work necessary because we're not actually importing the semaphore during replay
}

void VulkanCppConsumerBase::Generate_vkGetSemaphoreFdKHR(args::GetSemaphoreFdKHR& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(args);
    FILE* file = GetFrameFile();
    fprintf(file, "\t// vkGetSemaphoreFdKHR ignored\n");

    // No other work necessary because we're not actually sharing the semaphore during replay
}

void VulkanCppConsumerBase::Generate_vkImportSemaphoreFdKHR(args::ImportSemaphoreFdKHR& args)
{
    // Add the semaphore to the list of imported semaphores
    imported_semaphores_.push_back(args.pImportSemaphoreFdInfo.GetMetaStructPointer()->semaphore);

    // No other work necessary because we're not actually importing the semaphore during replay
}

void VulkanCppConsumerBase::Generate_vkGetDeviceQueue(args::GetDeviceQueue& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    std::string pqueue_name = "pQueue_" + std::to_string(this->GetNextId(VK_OBJECT_TYPE_QUEUE));
    AddKnownVariables("VkQueue", pqueue_name, args.pQueue.GetPointer());
    this->AddHandles(pqueue_name, args.pQueue.GetPointer());
    fprintf(file,
            "\t\ttoCppGetDeviceQueue(%s, %u, %u, &%s);\n",
            this->GetHandle(args.device).c_str(),
            args.queueFamilyIndex,
            args.queueIndex,
            pqueue_name.c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkQueueSubmit(args::QueueSubmit& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // queue
    // submitCount
    // pSubmits
    std::stringstream stream_psubmits;
    std::string       psubmits_array = "NULL";
    PointerPairContainer<decltype(args.pSubmits.GetPointer()), decltype(args.pSubmits.GetMetaStructPointer())>
                psubmits_pair{ args.pSubmits.GetPointer(), args.pSubmits.GetMetaStructPointer(), args.submitCount };
    std::string psubmits_names = toStringJoin(
        psubmits_pair.begin(),
        psubmits_pair.end(),
        [&](auto pair) {
            {
                return GenerateStruct_VkSubmitInfo(stream_psubmits, pair.t1, pair.t2, imported_semaphores_, *this);
            }
        },
        ", ");
    if (stream_psubmits.str().length() > 0)
    {
        fprintf(file, "%s", stream_psubmits.str().c_str());
        if (args.submitCount == 1)
        {
            psubmits_array = "&" + psubmits_names;
        }
        else if (args.submitCount > 1)
        {
            psubmits_array = "submits_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkSubmitInfo %s[] = { %s };\n", psubmits_array.c_str(), psubmits_names.c_str());
        }
    }
    // fence
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkQueueSubmit(%s, %u, %s, %s), %s);\n",
            this->GetHandle(args.queue).c_str(),
            args.submitCount,
            psubmits_array.c_str(),
            this->GetHandle(args.fence).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkQueueSubmit2(args::QueueSubmit2& args, const char* extension)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // queue
    // submitCount
    // pSubmits
    std::stringstream stream_psubmits;
    std::string       psubmits_array = "NULL";
    PointerPairContainer<decltype(args.pSubmits.GetPointer()), decltype(args.pSubmits.GetMetaStructPointer())>
                psubmits_pair{ args.pSubmits.GetPointer(), args.pSubmits.GetMetaStructPointer(), args.submitCount };
    std::string psubmits_names = toStringJoin(
        psubmits_pair.begin(),
        psubmits_pair.end(),
        [&](auto pair) {
            {
                return GenerateStruct_VkSubmitInfo2(stream_psubmits, pair.t1, pair.t2, imported_semaphores_, *this);
            }
        },
        ", ");
    if (stream_psubmits.str().length() > 0)
    {
        fprintf(file, "%s", stream_psubmits.str().c_str());
        if (args.submitCount == 1)
        {
            psubmits_array = "&" + psubmits_names;
        }
        else if (args.submitCount > 1)
        {
            psubmits_array = "submits_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkSubmitInfo2 %s[] = { %s };\n", psubmits_array.c_str(), psubmits_names.c_str());
        }
    }
    // fence
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkQueueSubmit2%s(%s, %u, %s, %s), %s);\n",
            extension,
            this->GetHandle(args.queue).c_str(),
            args.submitCount,
            psubmits_array.c_str(),
            this->GetHandle(args.fence).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
}

void VulkanCppConsumerBase::Generate_vkQueueBindSparse(args::QueueBindSparse& args)
{
    FILE* file = GetFrameFile();
    fprintf(file, "\t{\n");
    // queue
    // bindInfoCount
    // pBindInfo
    std::stringstream stream_pbind_info;
    std::string       pbind_info_array = "NULL";
    PointerPairContainer<decltype(args.pBindInfo.GetPointer()), decltype(args.pBindInfo.GetMetaStructPointer())>
        pbind_info_pair{ args.pBindInfo.GetPointer(), args.pBindInfo.GetMetaStructPointer(), args.bindInfoCount };
    std::string pbind_info_names = toStringJoin(
        pbind_info_pair.begin(),
        pbind_info_pair.end(),
        [&](auto pair) {
            {
                return GenerateStruct_VkBindSparseInfo(
                    stream_pbind_info, pair.t1, pair.t2, imported_semaphores_, *this);
            }
        },
        ", ");
    if (stream_pbind_info.str().length() > 0)
    {
        fprintf(file, "%s", stream_pbind_info.str().c_str());
        if (args.bindInfoCount == 1)
        {
            pbind_info_array = "&" + pbind_info_names;
        }
        else if (args.bindInfoCount > 1)
        {
            pbind_info_array = "bind_info_" + std::to_string(this->GetNextId());
            fprintf(file, "\t\tVkBindSparseInfo %s[] = { %s };\n", pbind_info_array.c_str(), pbind_info_names.c_str());
        }
    }
    // fence
    fprintf(file,
            "\t\tVK_CALL_CHECK(vkQueueBindSparse(%s, %u, %s, %s), %s);\n",
            this->GetHandle(args.queue).c_str(),
            args.bindInfoCount,
            pbind_info_array.c_str(),
            this->GetHandle(args.fence).c_str(),
            util::ToString<VkResult>(args.result).c_str());
    fprintf(file, "\t}\n");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
