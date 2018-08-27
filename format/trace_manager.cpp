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

std::mutex                            TraceManager::ThreadData::count_lock_;
uint32_t                              TraceManager::ThreadData::thread_count_ = 0;
std::map<uint64_t, uint32_t>          TraceManager::ThreadData::id_map_;
thread_local TraceManager::ThreadData TraceManager::thread_data_;

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
    thread_data_.call_id_ = call_id;
    return thread_data_.parameter_encoder_.get();
}

void TraceManager::EndApiCallTrace(ParameterEncoder* encoder)
{
    bool                         not_compressed      = true;
    CompressedFunctionCallHeader compressed_header   = {};
    FunctionCallHeader           uncompressed_header = {};
    size_t                       uncompressed_size   = thread_data_.parameter_buffer_->GetDataSize();
    size_t                       header_size         = 0;
    const void*                  header_pointer      = nullptr;
    size_t                       data_size           = 0;
    const void*                  data_pointer        = nullptr;

    if (nullptr != compressor_)
    {
        size_t packet_size = 0;
        size_t compressed_size =
            compressor_->Compress(uncompressed_size, thread_data_.parameter_buffer_->GetData(), &compressed_buffer_);
        if ((0 < compressed_size) && (compressed_size < uncompressed_size))
        {
            data_pointer   = reinterpret_cast<const void*>(compressed_buffer_.data());
            data_size      = compressed_size;
            header_pointer = reinterpret_cast<const void*>(&compressed_header);
            header_size    = sizeof(CompressedFunctionCallHeader);

            compressed_header.block_header.type = BlockType::kCompressedFunctionCallBlock;
            compressed_header.api_call_id       = thread_data_.call_id_;
            compressed_header.uncompressed_size = uncompressed_size;

            packet_size +=
                sizeof(compressed_header.api_call_id) + sizeof(compressed_header.uncompressed_size) + compressed_size;
            if (file_options_.record_thread_id)
            {
                packet_size += sizeof(thread_data_.thread_id_);
            }

            if (file_options_.record_begin_end_timestamp)
            {
                packet_size += sizeof(thread_data_.call_begin_time_) + sizeof(thread_data_.call_end_time_);
            }
            compressed_header.block_header.size = packet_size;
            not_compressed                      = false;
        }
    }

    if (not_compressed)
    {
        size_t packet_size = 0;
        data_pointer       = reinterpret_cast<const void*>(thread_data_.parameter_buffer_->GetData());
        data_size          = uncompressed_size;
        header_pointer     = reinterpret_cast<const void*>(&uncompressed_header);
        header_size        = sizeof(FunctionCallHeader);

        uncompressed_header.block_header.type = BlockType::kFunctionCallBlock;
        uncompressed_header.api_call_id       = thread_data_.call_id_;

        packet_size += sizeof(uncompressed_header.api_call_id) + data_size;
        if (file_options_.record_thread_id)
        {
            packet_size += sizeof(thread_data_.thread_id_);
        }

        if (file_options_.record_begin_end_timestamp)
        {
            packet_size += sizeof(thread_data_.call_begin_time_) + sizeof(thread_data_.call_end_time_);
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
            bytes_written_ += file_stream_->Write(&thread_data_.thread_id_, sizeof(thread_data_.thread_id_));
        }

        if (file_options_.record_begin_end_timestamp)
        {
            bytes_written_ +=
                file_stream_->Write(&thread_data_.call_begin_time_, sizeof(thread_data_.call_begin_time_));
            bytes_written_ += file_stream_->Write(&thread_data_.call_end_time_, sizeof(thread_data_.call_end_time_));
        }

        // Write parameter data.
        bytes_written_ += file_stream_->Write(data_pointer, data_size);
    }

    thread_data_.parameter_encoder_->Reset();
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
    message_cmd.meta_header.block_header.size = sizeof(message_cmd.meta_header.meta_data_type) +
                                                sizeof(message_cmd.message_size) + message_length;
    message_cmd.meta_header.meta_data_type    = kDisplayMessageCommand;
    message_cmd.message_size                  = message_length;

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

void TraceManager::WriteFillMemoryCmd(const void* memory, VkDeviceSize offset, VkDeviceSize size)
{
    FillMemoryCommandHeader fill_cmd;

    fill_cmd.meta_header.block_header.type = kMetaDataBlock;
    fill_cmd.meta_header.block_header.size = sizeof(fill_cmd.meta_header.meta_data_type) + sizeof(fill_cmd.memory_id) +
                                             sizeof(fill_cmd.memory_offset) + sizeof(fill_cmd.memory_size) + size;
    fill_cmd.meta_header.meta_data_type = kFillMemoryCommand;
    fill_cmd.memory_id                  = reinterpret_cast<uint64_t>(memory);
    fill_cmd.memory_offset              = offset;
    fill_cmd.memory_size                = size;

    {
        std::lock_guard<std::mutex> lock(file_lock_);

        bytes_written_ += file_stream_->Write(&fill_cmd, sizeof(fill_cmd));
        bytes_written_ += file_stream_->Write((static_cast<const uint8_t*>(memory) + offset), size);
    }
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

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
