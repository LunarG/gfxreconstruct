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

#include <cassert>

#include "util/platform.h"
#include "format/trace_manager.h"
#include "util/compressor.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

std::mutex                                             TraceManager::ThreadData::count_lock_;
uint32_t                                               TraceManager::ThreadData::thread_count_ = 0;
std::unordered_map<uint64_t, uint32_t>                 TraceManager::ThreadData::id_map_;
thread_local std::unique_ptr<TraceManager::ThreadData> TraceManager::thread_data_;

TraceManager::ThreadData::ThreadData() :
    thread_id_(GetThreadId()), call_id_(ApiCallId_Unknown), call_begin_time_(0), call_end_time_(0)
{
    parameter_buffer_  = std::make_unique<util::MemoryOutputStream>();
    parameter_encoder_ = std::make_unique<ParameterEncoder>(parameter_buffer_.get());
}

uint32_t TraceManager::ThreadData::GetThreadId()
{
    uint32_t id  = 0;
    uint64_t tid = util::platform::GetCurrentThreadId();

    // Using a uint32_t sequence number associated with the thread ID.
    std::lock_guard<std::mutex> lock(count_lock_);
    auto                        entry = id_map_.find(tid);
    if (entry != id_map_.end())
    {
        id = entry->second;
    }
    else
    {
        id = ++thread_count_;
        id_map_.insert(std::make_pair(tid, id));
    }

    return id;
}

bool TraceManager::Initialize(std::string filename, EnabledOptions file_options)
{
    bool success = false;

    file_options_ = file_options;
    filename_     = filename;
    file_stream_  = std::make_unique<util::FileOutputStream>(filename_);

    // TODO: Perform options related setup (enable compression, etc).

    compressor_ = util::Compressor::CreateCompressor(file_options.compression_type);
    if ((nullptr == compressor_) && (util::kNone != file_options.compression_type))
    {
        return false;
    }

    if (file_stream_->IsValid())
    {
        bytes_written_ = 0;
        WriteFileHeader();
        success = true;
    }

    return success;
}

void TraceManager::Destroy()
{
    // Perform any finalization required for trace file.
    if (nullptr != compressor_)
    {
        delete compressor_;
        compressor_ = nullptr;
    }
}

ParameterEncoder* TraceManager::BeginApiCallTrace(ApiCallId call_id)
{
    auto thread_data      = GetThreadData();
    thread_data->call_id_ = call_id;
    return thread_data->parameter_encoder_.get();
}

void TraceManager::EndApiCallTrace(ParameterEncoder* encoder)
{
    auto thread_data = GetThreadData();
    assert(thread_data != nullptr);

    auto parameter_buffer  = thread_data->parameter_buffer_.get();
    auto parameter_encoder = thread_data->parameter_encoder_.get();
    assert((parameter_buffer != nullptr) && (parameter_encoder != nullptr));

    bool                         not_compressed      = true;
    CompressedFunctionCallHeader compressed_header   = {};
    FunctionCallHeader           uncompressed_header = {};
    size_t                       uncompressed_size   = parameter_buffer->GetDataSize();
    size_t                       header_size         = 0;
    const void*                  header_pointer      = nullptr;
    size_t                       data_size           = 0;
    const void*                  data_pointer        = nullptr;

    if (nullptr != compressor_)
    {
        size_t packet_size = 0;
        size_t compressed_size =
            compressor_->Compress(uncompressed_size, parameter_buffer->GetData(), &compressed_buffer_);
        if ((0 < compressed_size) && (compressed_size < uncompressed_size))
        {
            data_pointer   = reinterpret_cast<const void*>(compressed_buffer_.data());
            data_size      = compressed_size;
            header_pointer = reinterpret_cast<const void*>(&compressed_header);
            header_size    = sizeof(CompressedFunctionCallHeader);

            compressed_header.block_header.type = BlockType::kCompressedFunctionCallBlock;
            compressed_header.api_call_id       = thread_data->call_id_;
            compressed_header.uncompressed_size = uncompressed_size;

            packet_size +=
                sizeof(compressed_header.api_call_id) + sizeof(compressed_header.uncompressed_size) + compressed_size;
            if (file_options_.record_thread_id)
            {
                packet_size += sizeof(thread_data->thread_id_);
            }

            if (file_options_.record_begin_end_timestamp)
            {
                packet_size += sizeof(thread_data->call_begin_time_) + sizeof(thread_data->call_end_time_);
            }
            compressed_header.block_header.size = packet_size;
            not_compressed                      = false;
        }
    }

    if (not_compressed)
    {
        size_t packet_size = 0;
        data_pointer       = reinterpret_cast<const void*>(parameter_buffer->GetData());
        data_size          = uncompressed_size;
        header_pointer     = reinterpret_cast<const void*>(&uncompressed_header);
        header_size        = sizeof(FunctionCallHeader);

        uncompressed_header.block_header.type = BlockType::kFunctionCallBlock;
        uncompressed_header.api_call_id       = thread_data->call_id_;

        packet_size += sizeof(uncompressed_header.api_call_id) + data_size;
        if (file_options_.record_thread_id)
        {
            packet_size += sizeof(thread_data->thread_id_);
        }

        if (file_options_.record_begin_end_timestamp)
        {
            packet_size += sizeof(thread_data->call_begin_time_) + sizeof(thread_data->call_end_time_);
        }
        uncompressed_header.block_header.size = packet_size;
    }

    {
        std::lock_guard<std::mutex> lock(file_lock_);

        // Write appropriate function call block header.
        bytes_written_ += file_stream_->Write(header_pointer, header_size);

        // Add optional call items.
        if (file_options_.record_thread_id)
        {
            bytes_written_ += file_stream_->Write(&thread_data->thread_id_, sizeof(thread_data->thread_id_));
        }

        if (file_options_.record_begin_end_timestamp)
        {
            bytes_written_ +=
                file_stream_->Write(&thread_data->call_begin_time_, sizeof(thread_data->call_begin_time_));
            bytes_written_ += file_stream_->Write(&thread_data->call_end_time_, sizeof(thread_data->call_end_time_));
        }

        // Write parameter data.
        bytes_written_ += file_stream_->Write(data_pointer, data_size);
    }

    parameter_encoder->Reset();
}

void TraceManager::WriteFileHeader()
{
    std::vector<FileOptionPair> option_list;

    BuildOptionList(file_options_, &option_list);

    FileHeader file_header;
    file_header.fourcc        = BRIMSTONE_FOURCC;
    file_header.major_version = 1;
    file_header.minor_version = 0;
    file_header.num_options   = static_cast<uint32_t>(option_list.size());

    bytes_written_ += file_stream_->Write(&file_header, sizeof(file_header));
    bytes_written_ += file_stream_->Write(option_list.data(), option_list.size() * sizeof(FileOptionPair));
}

void TraceManager::BuildOptionList(const EnabledOptions& enabled_options, std::vector<FileOptionPair>* option_list)
{
    assert(option_list != nullptr);

    option_list->push_back({ FileOption::kCompressionType, enabled_options.compression_type });
    option_list->push_back({ FileOption::kHaveThreadId, enabled_options.record_thread_id ? 1u : 0u });
    option_list->push_back(
        { FileOption::kHaveBeginEndTimestamp, enabled_options.record_begin_end_timestamp ? 1u : 0u });
    option_list->push_back({ FileOption::kOmitTextures, enabled_options.omit_textures ? 1u : 0u });
    option_list->push_back({ FileOption::kOmitBuffers, enabled_options.omit_buffers ? 1u : 0u });
}

void TraceManager::WriteDisplayMessageCmd(const char* message)
{
    size_t                      message_length = util::platform::StringLength(message);
    DisplayMessageCommandHeader message_cmd;

    message_cmd.meta_header.block_header.type = kMetaDataBlock;
    message_cmd.meta_header.block_header.size =
        sizeof(message_cmd.meta_header.meta_data_type) + sizeof(message_cmd.message_size) + message_length;
    message_cmd.meta_header.meta_data_type = kDisplayMessageCommand;
    message_cmd.message_size               = message_length;

    {
        std::lock_guard<std::mutex> lock(file_lock_);

        bytes_written_ += file_stream_->Write(&message_cmd, sizeof(message_cmd));
        bytes_written_ += file_stream_->Write(message, message_length);
    }
}

void TraceManager::WriteResizeWindowCmd(VkSurfaceKHR surface, uint32_t width, uint32_t height)
{
    ResizeWindowCommand resize_cmd;
    resize_cmd.meta_header.block_header.type = kMetaDataBlock;
    resize_cmd.meta_header.block_header.size = sizeof(resize_cmd.meta_header.meta_data_type) +
                                               sizeof(resize_cmd.surface_id) + sizeof(resize_cmd.width) +
                                               sizeof(resize_cmd.height);
    resize_cmd.meta_header.meta_data_type = kResizeWindowCommand;

    resize_cmd.surface_id = reinterpret_cast<HandleId>(surface);
    resize_cmd.width      = width;
    resize_cmd.height     = height;

    {
        std::lock_guard<std::mutex> lock(file_lock_);
        bytes_written_ += file_stream_->Write(&resize_cmd, sizeof(resize_cmd));
    }
}

void TraceManager::WriteFillMemoryCmd(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, const void* data)
{

    bool                              not_compressed      = true;
    CompressedFillMemoryCommandHeader compressed_header   = {};
    FillMemoryCommandHeader           uncompressed_header = {};
    size_t                            header_size         = 0;
    const void*                       header_pointer      = nullptr;
    size_t                            data_size           = 0;
    const uint8_t*                    data_pointer        = nullptr;

    if (nullptr != compressor_)
    {
        size_t compressed_size =
            compressor_->Compress(size, (static_cast<const uint8_t*>(data) + offset), &compressed_buffer_);
        if ((0 < compressed_size) && (compressed_size < size))
        {
            compressed_header.meta_header.block_header.type = kCompressedMetaDataBlock;
            compressed_header.meta_header.block_header.size =
                sizeof(compressed_header.meta_header.meta_data_type) + sizeof(compressed_header.memory_id) +
                sizeof(compressed_header.memory_offset) + sizeof(compressed_header.memory_size) + compressed_size;
            compressed_header.meta_header.meta_data_type    = kFillMemoryCommand;
            compressed_header.meta_header.uncompressed_size = size;
            compressed_header.memory_id                     = reinterpret_cast<uint64_t>(memory);
            compressed_header.memory_offset                 = offset;
            compressed_header.memory_size                   = size;
            header_size                                     = sizeof(CompressedFillMemoryCommandHeader);
            header_pointer                                  = reinterpret_cast<const void*>(&compressed_header);
            data_size                                       = compressed_size;
            data_pointer                                    = compressed_buffer_.data();
            not_compressed                                  = false;
        }
    }

    if (not_compressed)
    {
        uncompressed_header.meta_header.block_header.type = kMetaDataBlock;
        uncompressed_header.meta_header.block_header.size =
            sizeof(uncompressed_header.meta_header.meta_data_type) + sizeof(uncompressed_header.memory_id) +
            sizeof(uncompressed_header.memory_offset) + sizeof(uncompressed_header.memory_size) + size;
        uncompressed_header.meta_header.meta_data_type = kFillMemoryCommand;
        uncompressed_header.memory_id                  = reinterpret_cast<uint64_t>(memory);
        uncompressed_header.memory_offset              = offset;
        uncompressed_header.memory_size                = size;
        header_size                                    = sizeof(FillMemoryCommandHeader);
        header_pointer                                 = reinterpret_cast<const void*>(&uncompressed_header);
        data_size                                      = size;
        data_pointer                                   = (static_cast<const uint8_t*>(data) + offset);
    }

    {
        std::lock_guard<std::mutex> lock(file_lock_);

        bytes_written_ += file_stream_->Write(header_pointer, header_size);
        bytes_written_ += file_stream_->Write(data_pointer, data_size);
    }
}

void TraceManager::AddDescriptorUpdateTemplate(VkDescriptorUpdateTemplate                  update_template,
                                               const VkDescriptorUpdateTemplateCreateInfo* create_info)
{
    // A NULL check should have been performed by the caller.
    assert((create_info != nullptr));

    if (create_info->descriptorUpdateEntryCount > 0)
    {
        UpdateTemplateInfo info;

        for (size_t i = 0; i < create_info->descriptorUpdateEntryCount; ++i)
        {
            const VkDescriptorUpdateTemplateEntry* entry = &create_info->pDescriptorUpdateEntries[i];
            VkDescriptorType                       type  = entry->descriptorType;

            // Sort the descriptor update template info by type, so it can be written to the trace file
            // as tightly packed arrays of structures.  One array will be written for each descriptor info
            // structure/textel buffer view.
            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                info.image_info_count += entry->descriptorCount;
                info.image_info.emplace_back(entry->descriptorCount, entry->offset, entry->stride);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                info.buffer_info_count += entry->descriptorCount;
                info.buffer_info.emplace_back(entry->descriptorCount, entry->offset, entry->stride);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                info.texel_buffer_view_count += entry->descriptorCount;
                info.texel_buffer_view.emplace_back(entry->descriptorCount, entry->offset, entry->stride);
            }
            else
            {
                assert(false);
            }
        }

        {
            std::lock_guard<std::mutex> lock(update_template_map_lock_);
            update_template_map_.emplace(std::make_pair(update_template, info));
        }
    }
}

void TraceManager::RemoveDescriptorUpdateTemplate(VkDescriptorUpdateTemplate update_template)
{
    std::lock_guard<std::mutex> lock(update_template_map_lock_);
    update_template_map_.erase(update_template);
}

bool TraceManager::GetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate update_template,
                                                   const UpdateTemplateInfo** info) const
{
    assert(info != nullptr);

    bool found = false;

    // We assume that the application will not destroy an update template while it is in use, and that we only need
    // to lock on find for protection from data strcuture changes due to adds and removes of other update templates.
    auto entry = update_template_map_.find(update_template);
    if (entry != update_template_map_.end())
    {
        found   = true;
        (*info) = &(entry->second);
    }

    return found;
}

void TraceManager::PreProcess_vkCreateSwapchain(VkDevice                        device,
                                                const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                const VkAllocationCallbacks*    pAllocator,
                                                VkSwapchainKHR*                 pSwapchain)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(pAllocator);
    BRIMSTONE_UNREFERENCED_PARAMETER(pSwapchain);

    assert(pCreateInfo != nullptr);

    if (pCreateInfo)
    {
        WriteResizeWindowCmd(pCreateInfo->surface, pCreateInfo->imageExtent.width, pCreateInfo->imageExtent.height);
    }
}

void TraceManager::PostProcess_vkAllocateMemory(VkResult                     result,
                                                VkDevice                     device,
                                                const VkMemoryAllocateInfo*  pAllocateInfo,
                                                const VkAllocationCallbacks* pAllocator,
                                                VkDeviceMemory*              pMemory)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(pAllocator);

    if ((result == VK_SUCCESS) && (pAllocateInfo != nullptr) && (pMemory != nullptr))
    {
        std::lock_guard<std::mutex> lock(memory_tracker_lock_);
        // TODO: Get property flags for type index (for pageguard).
        // TODO: Key memory tracker by VkDevice + VkDeviceMemory for multi-device support.
        memory_tracker_.AddEntry((*pMemory), 0, pAllocateInfo->allocationSize);
    }
}

void TraceManager::PostProcess_vkMapMemory(VkResult         result,
                                           VkDevice         device,
                                           VkDeviceMemory   memory,
                                           VkDeviceSize     offset,
                                           VkDeviceSize     size,
                                           VkMemoryMapFlags flags,
                                           void**           ppData)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(flags);

    if ((result == VK_SUCCESS) && (ppData != nullptr))
    {
        std::lock_guard<std::mutex> lock(memory_tracker_lock_);
        memory_tracker_.MapEntry(memory, offset, size, (*ppData));
    }
}

void TraceManager::PreProcess_vkFlushMappedMemoryRanges(VkDevice                   device,
                                                        uint32_t                   memoryRangeCount,
                                                        const VkMappedMemoryRange* pMemoryRanges)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);

    if ((memory_tracking_mode_ == MemoryTrackingMode::kAssisted) && (pMemoryRanges != nullptr))
    {
        VkDeviceMemory                  current_memory = VK_NULL_HANDLE;
        const MemoryTracker::EntryInfo* info           = nullptr;

        std::lock_guard<std::mutex> lock(memory_tracker_lock_);

        for (uint32_t i = 0; i < memoryRangeCount; ++i)
        {
            if (current_memory != pMemoryRanges[i].memory)
            {
                current_memory = pMemoryRanges[i].memory;
                info           = memory_tracker_.GetEntryInfo(current_memory);
            }

            if ((info != nullptr) && (info->data != nullptr))
            {
                VkDeviceSize size = pMemoryRanges[i].size;
                if (size == VK_WHOLE_SIZE)
                {
                    size = info->allocation_size - (pMemoryRanges[i].offset - info->mapped_offset);
                }

                WriteFillMemoryCmd(pMemoryRanges[i].memory, pMemoryRanges[i].offset, size, info->data);
            }
        }
    }
}

void TraceManager::PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);

    std::lock_guard<std::mutex> lock(memory_tracker_lock_);

    if (memory_tracking_mode_ == MemoryTrackingMode::kUnassisted)
    {
        auto info = memory_tracker_.GetEntryInfo(memory);
        if ((info != nullptr) && (info->data != nullptr))
        {
            WriteFillMemoryCmd(memory,
                               info->mapped_offset,
                               (info->mapped_size == VK_WHOLE_SIZE) ? info->allocation_size : info->mapped_size,
                               info->data);
        }
    }

    memory_tracker_.UnmapEntry(memory);
}

void TraceManager::PreProcess_vkFreeMemory(VkDevice                     device,
                                           VkDeviceMemory               memory,
                                           const VkAllocationCallbacks* pAllocator)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(pAllocator);

    std::lock_guard<std::mutex> lock(memory_tracker_lock_);
    memory_tracker_.RemoveEntry(memory);
}

void TraceManager::PreProcess_vkQueueSubmit(VkQueue             queue,
                                            uint32_t            submitCount,
                                            const VkSubmitInfo* pSubmits,
                                            VkFence             fence)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(queue);
    BRIMSTONE_UNREFERENCED_PARAMETER(submitCount);
    BRIMSTONE_UNREFERENCED_PARAMETER(pSubmits);
    BRIMSTONE_UNREFERENCED_PARAMETER(fence);

    if (memory_tracking_mode_ == MemoryTrackingMode::kUnassisted)
    {
        std::lock_guard<std::mutex> lock(memory_tracker_lock_);

        memory_tracker_.VisitEntries([this](VkDeviceMemory memory, const MemoryTracker::EntryInfo& entry) {
            WriteFillMemoryCmd(memory,
                               entry.mapped_offset,
                               (entry.mapped_size == VK_WHOLE_SIZE) ? entry.allocation_size : entry.mapped_size,
                               entry.data);
        });
    }
}

void TraceManager::PreProcess_vkCreateDescriptorUpdateTemplate(VkResult                                    result,
                                                               VkDevice                                    device,
                                                               const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                               const VkAllocationCallbacks*                pAllocator,
                                                               VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(pAllocator);

    if ((result == VK_SUCCESS) && (pCreateInfo != nullptr) && (pDescriptorUpdateTemplate != nullptr))
    {
        AddDescriptorUpdateTemplate((*pDescriptorUpdateTemplate), pCreateInfo);
    }
}

void TraceManager::PreProcess_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    result,
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(pAllocator);

    if ((result == VK_SUCCESS) && (pCreateInfo != nullptr) && (pDescriptorUpdateTemplate != nullptr))
    {
        AddDescriptorUpdateTemplate((*pDescriptorUpdateTemplate), pCreateInfo);
    }
}

void TraceManager::PreProcess_vkDestroyDescriptorUpdateTemplate(VkDevice                     device,
                                                                VkDescriptorUpdateTemplate   descriptorUpdateTemplate,
                                                                const VkAllocationCallbacks* pAllocator)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(pAllocator);

    RemoveDescriptorUpdateTemplate(descriptorUpdateTemplate);
}

void TraceManager::PreProcess_vkDestroyDescriptorUpdateTemplateKHR(VkDevice                   device,
                                                                   VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                   const VkAllocationCallbacks* pAllocator)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(device);
    BRIMSTONE_UNREFERENCED_PARAMETER(pAllocator);

    RemoveDescriptorUpdateTemplate(descriptorUpdateTemplate);
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
