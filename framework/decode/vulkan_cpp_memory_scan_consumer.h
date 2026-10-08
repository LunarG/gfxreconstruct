//
// Copyright (c) 2026 LunarG, Inc
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

#ifndef GFXRECON_DECODE_VULKAN_CPP_MEMORY_SCAN_CONSUMER_H
#define GFXRECON_DECODE_VULKAN_CPP_MEMORY_SCAN_CONSUMER_H

#include "format/format.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <map>
#include <queue>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Reads a capture file and notes which resource each memory allocation carries.
//
// The generated source has to know the size that a resource needs before it
// writes the allocation, but the capture file holds the bind call after the
// allocate call.  One read of the file therefore cannot answer the question.
// This consumer reads the file first and collects only the bind calls, and the
// answer goes to VulkanCppConsumerBase::SetMemoryResourceMap before the read
// that writes the source.
class VulkanCppMemoryScanConsumer : public VulkanConsumer
{
  public:
    using MemoryResourceMap = std::map<format::HandleId, std::queue<std::pair<format::HandleId, VkDeviceSize>>>;

    const MemoryResourceMap& GetMemoryResourceMap() const { return memory_resource_map_; }

    virtual void Process_vkBindImageMemory(const ApiCallInfo& call_info, args::BindImageMemory& args) override
    {
        Add(args.memory, args.image, args.memoryOffset);
    }

    virtual void Process_vkBindBufferMemory(const ApiCallInfo& call_info, args::BindBufferMemory& args) override
    {
        Add(args.memory, args.buffer, args.memoryOffset);
    }

    virtual void Process_vkBindImageMemory2(const ApiCallInfo& call_info, args::BindImageMemory2& args) override
    {
        AddImage2(args.bindInfoCount, args.pBindInfos.GetMetaStructPointer());
    }

    virtual void Process_vkBindImageMemory2KHR(const ApiCallInfo& call_info, args::BindImageMemory2KHR& args) override
    {
        AddImage2(args.bindInfoCount, args.pBindInfos.GetMetaStructPointer());
    }

    virtual void Process_vkBindBufferMemory2(const ApiCallInfo& call_info, args::BindBufferMemory2& args) override
    {
        AddBuffer2(args.bindInfoCount, args.pBindInfos.GetMetaStructPointer());
    }

    virtual void Process_vkBindBufferMemory2KHR(const ApiCallInfo& call_info, args::BindBufferMemory2KHR& args) override
    {
        AddBuffer2(args.bindInfoCount, args.pBindInfos.GetMetaStructPointer());
    }

  private:
    void Add(format::HandleId memory, format::HandleId resource, VkDeviceSize offset)
    {
        memory_resource_map_[memory].emplace(std::make_pair(resource, offset));
    }

    // The meta structure carries the handle identifiers.  The decoded structure
    // carries handle pointers, which mean nothing here.
    void AddImage2(uint32_t count, const Decoded_VkBindImageMemoryInfo* bind_infos)
    {
        if (bind_infos == nullptr)
        {
            return;
        }
        for (uint32_t index = 0; index < count; ++index)
        {
            const VkDeviceSize offset =
                (bind_infos[index].decoded_value != nullptr) ? bind_infos[index].decoded_value->memoryOffset : 0;
            Add(bind_infos[index].memory, bind_infos[index].image, offset);
        }
    }

    void AddBuffer2(uint32_t count, const Decoded_VkBindBufferMemoryInfo* bind_infos)
    {
        if (bind_infos == nullptr)
        {
            return;
        }
        for (uint32_t index = 0; index < count; ++index)
        {
            const VkDeviceSize offset =
                (bind_infos[index].decoded_value != nullptr) ? bind_infos[index].decoded_value->memoryOffset : 0;
            Add(bind_infos[index].memory, bind_infos[index].buffer, offset);
        }
    }

    MemoryResourceMap memory_resource_map_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_CPP_MEMORY_SCAN_CONSUMER_H
