/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef BRIMSTONE_FORMAT_TRACE_MANAGER_H
#define BRIMSTONE_FORMAT_TRACE_MANAGER_H

#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "util/file_output_stream.h"
#include "util/memory_output_stream.h"
#include "util/compressor.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "format/memory_tracker.h"
#include "format/parameter_encoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

class TraceManager
{
public:
    enum MemoryTrackingMode
    {
        // Assume the application does not flush, so write all mapped data on unmap and queue submit.
        kUnassisted = 0,
        // Assume the application will always flush after writing to mapped memory, so only write on flush.
        kAssisted = 1,
        // Use pageguard to determine which regions of memory to wrtie on unmap and queue submit.  This
        // mode shadows uncached memory.
        kPageGuard = 2
    };

public:
    TraceManager() : memory_tracking_mode_(MemoryTrackingMode::kUnassisted) { }

    ~TraceManager() { }

    bool Initialize(std::string filename, EnabledOptions file_options);

    void Destroy();

    ParameterEncoder* BeginApiCallTrace(ApiCallId call_id);

    void EndApiCallTrace(ParameterEncoder* encoder);

    void WriteDisplayMessageCmd(const char* message);

    void PreProcess_vkCreateSwapchain(VkDevice                        device,
                                      const VkSwapchainCreateInfoKHR* pCreateInfo,
                                      const VkAllocationCallbacks*    pAllocator,
                                      VkSwapchainKHR*                 pSwapchain);

    void PostProcess_vkAllocateMemory(VkResult                     result,
                                      VkDevice                     device,
                                      const VkMemoryAllocateInfo*  pAllocateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkDeviceMemory*              pMemory);

    void PostProcess_vkMapMemory(VkResult         result,
                                 VkDevice         device,
                                 VkDeviceMemory   memory,
                                 VkDeviceSize     offset,
                                 VkDeviceSize     size,
                                 VkMemoryMapFlags flags,
                                 void**           ppData);

    void PreProcess_vkFlushMappedMemoryRanges(VkDevice                   device,
                                              uint32_t                   memoryRangeCount,
                                              const VkMappedMemoryRange* pMemoryRanges);

    void PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory);

    void PreProcess_vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator);

    void PreProcess_vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);

  private:
    class ThreadData
    {
    public:
        ThreadData();

        ~ThreadData() { }

    public:
        const uint32_t                                      thread_id_;
        ApiCallId                                           call_id_;
        uint32_t                                            call_begin_time_;
        uint32_t                                            call_end_time_;
        std::unique_ptr<util::MemoryOutputStream>           parameter_buffer_;
        std::unique_ptr<ParameterEncoder>                   parameter_encoder_;

    private:
        static uint32_t GetThreadId();

    private:
        static std::mutex                                   count_lock_;
        static uint32_t                                     thread_count_;
        static std::map<uint64_t, uint32_t>                 id_map_;
    };

private:
    void WriteFileHeader();
    void BuildOptionList(const EnabledOptions& enabled_options, std::vector<FileOptionPair>* option_list);

    void WriteResizeWindowCmd(VkSurfaceKHR surface, uint32_t width, uint32_t height);
    void WriteFillMemoryCmd(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, const void* data);

private:
    static thread_local ThreadData                          thread_data_;
    EnabledOptions                                          file_options_;
    std::unique_ptr<util::FileOutputStream>                 file_stream_;
    std::string                                             filename_;
    std::mutex                                              file_lock_;
    uint64_t                                                bytes_written_;
    std::vector<uint8_t>                                    compressed_buffer_;
    util::Compressor*                                       compressor_;
    MemoryTrackingMode                                      memory_tracking_mode_;
    MemoryTracker                                           memory_tracker_;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_TRACE_MANAGER_H
