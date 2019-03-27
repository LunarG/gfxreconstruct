/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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

#include "encode/trace_manager.h"

#include "encode/vulkan_state_writer.h"
#include "format/format_util.h"
#include "util/compressor.h"
#include "util/file_path.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/platform.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Default log level to use prior to loading settings.
const util::Log::Severity kDefaultLogLevel = util::Log::Severity::kInfoSeverity;

// One based frame count.
const uint32_t kFirstFrame = 1;

std::mutex                                     TraceManager::ThreadData::count_lock_;
format::ThreadId                               TraceManager::ThreadData::thread_count_ = 0;
std::unordered_map<uint64_t, format::ThreadId> TraceManager::ThreadData::id_map_;

TraceManager*                                          TraceManager::instance_       = nullptr;
uint32_t                                               TraceManager::instance_count_ = 0;
std::mutex                                             TraceManager::instance_lock_;
thread_local std::unique_ptr<TraceManager::ThreadData> TraceManager::thread_data_;
LayerTable                                             TraceManager::layer_table_;

TraceManager::ThreadData::ThreadData() : thread_id_(GetThreadId()), call_id_(format::ApiCallId::ApiCall_Unknown)
{
    parameter_buffer_  = std::make_unique<util::MemoryOutputStream>();
    parameter_encoder_ = std::make_unique<ParameterEncoder>(parameter_buffer_.get());
}

format::ThreadId TraceManager::ThreadData::GetThreadId()
{
    format::ThreadId id  = 0;
    uint64_t         tid = util::platform::GetCurrentThreadId();

    // Using a uint64_t sequence number associated with the thread ID.
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

TraceManager::TraceManager() :
    force_file_flush_(false), bytes_written_(0), timestamp_filename_(true),
    memory_tracking_mode_(CaptureSettings::MemoryTrackingMode::kPageGuard), trim_enabled_(false),
    trim_current_range_(0), current_frame_(kFirstFrame), capture_mode_(kModeWrite)
{}

TraceManager::~TraceManager()
{
    if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
    {
        util::PageGuardManager::Destroy();
    }
}

void TraceManager::SetLayerFuncs(PFN_vkCreateInstance create_instance, PFN_vkCreateDevice create_device)
{
    assert((create_instance != nullptr) && (create_device != nullptr));
    layer_table_.CreateInstance = create_instance;
    layer_table_.CreateDevice   = create_device;
}

bool TraceManager::CreateInstance()
{
    bool                        success = true;
    std::lock_guard<std::mutex> instance_lock(instance_lock_);

    if (instance_count_ == 0)
    {
        assert(instance_ == nullptr);

        // Default initialize logging to report issues while loading settings.
        util::Log::Init(kDefaultLogLevel);

        CaptureSettings settings = {};
        CaptureSettings::LoadSettings(&settings);

        // Reinitialize logging with values retrieved from settings.
        const util::Log::Settings& log_settings = settings.GetLogSettings();
        util::Log::Release();
        util::Log::Init(log_settings);

        CaptureSettings::TraceSettings trace_settings = settings.GetTraceSettings();
        std::string                    base_filename  = trace_settings.capture_file;

        instance_ = new TraceManager();
        success   = instance_->Initialize(base_filename, trace_settings);
        if (success)
        {
            instance_count_ = 1;
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to initialize TraceManager");
        }
    }
    else
    {
        assert(instance_ != nullptr);
        ++instance_count_;
    }

    GFXRECON_LOG_DEBUG("vkCreateInstance(): Current instance count is %u", instance_count_);

    return success;
}

void TraceManager::CheckCreateInstanceStatus(VkResult result)
{
    if (result != VK_SUCCESS)
    {
        DestroyInstance();
    }
}

void TraceManager::DestroyInstance()
{
    std::lock_guard<std::mutex> instance_lock(instance_lock_);

    if (instance_ != nullptr)
    {
        assert(instance_count_ > 0);

        --instance_count_;

        if (instance_count_ == 0)
        {
            delete instance_;
            instance_ = nullptr;

            util::Log::Release();
        }

        GFXRECON_LOG_DEBUG("vkDestroyInstance(): Current instance count is %u", instance_count_);
    }
}

void TraceManager::AddInstanceTable(VkInstance instance, PFN_vkGetInstanceProcAddr gpa)
{
    InstanceTable& table = instance_tables_[GetDispatchKey(instance)];
    LoadInstanceTable(gpa, instance, &table);
}

void TraceManager::AddDeviceTable(VkDevice device, PFN_vkGetDeviceProcAddr gpa)
{
    DeviceTable& table = device_tables_[GetDispatchKey(device)];
    LoadDeviceTable(gpa, device, &table);
}

const encode::InstanceTable* TraceManager::GetInstanceTable(const void* handle) const
{
    auto table = instance_tables_.find(GetDispatchKey(handle));
    assert(table != instance_tables_.end());
    return (table != instance_tables_.end()) ? &table->second : nullptr;
}

const encode::DeviceTable* TraceManager::GetDeviceTable(const void* handle) const
{
    auto table = device_tables_.find(GetDispatchKey(handle));
    assert(table != device_tables_.end());
    return (table != device_tables_.end()) ? &table->second : nullptr;
}

bool TraceManager::Initialize(std::string base_filename, const CaptureSettings::TraceSettings& trace_settings)
{
    bool success = true;

    base_filename_        = base_filename;
    file_options_         = trace_settings.capture_file_options;
    timestamp_filename_   = trace_settings.time_stamp_file;
    memory_tracking_mode_ = trace_settings.memory_tracking_mode;
    force_file_flush_     = trace_settings.force_flush;

    if (!trace_settings.trim_ranges.empty())
    {
        trim_enabled_ = true;
        trim_ranges_  = trace_settings.trim_ranges;

        // Determine if trim starts at the first frame.
        if (trim_ranges_[0].first == current_frame_)
        {
            // When capturing from the first frame, state tracking only needs to be enabled if there is more than one
            // capture range.
            if (trim_ranges_.size() == 1)
            {
                capture_mode_ = kModeWrite;
            }
            else
            {
                capture_mode_ = kModeWriteAndTrack;
            }
        }
        else
        {
            capture_mode_ = kModeTrack;
        }
    }

    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        success = CreateCaptureFile();
    }

    if (success)
    {
        compressor_ = std::unique_ptr<util::Compressor>(format::CreateCompressor(file_options_.compression_type));
        if ((nullptr == compressor_) && (format::CompressionType::kNone != file_options_.compression_type))
        {
            success = false;
        }
    }

    if (success)
    {
        if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            util::PageGuardManager::Create(true, false, true, true, true, true);
        }

        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            state_tracker_ = std::make_unique<VulkanStateTracker>();
        }
    }
    else
    {
        capture_mode_ = kModeDisabled;
    }

    return success;
}

ParameterEncoder* TraceManager::InitApiCallTrace(format::ApiCallId call_id)
{
    auto thread_data      = GetThreadData();
    thread_data->call_id_ = call_id;
    return thread_data->parameter_encoder_.get();
}

void TraceManager::EndApiCallTrace(ParameterEncoder* encoder)
{
    assert(encoder != nullptr);

    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        auto parameter_buffer = thread_data->parameter_buffer_.get();
        assert((parameter_buffer != nullptr) && (thread_data->parameter_encoder_ != nullptr) &&
               (thread_data->parameter_encoder_.get() == encoder));

        bool                                 not_compressed      = true;
        format::CompressedFunctionCallHeader compressed_header   = {};
        format::FunctionCallHeader           uncompressed_header = {};
        size_t                               uncompressed_size   = parameter_buffer->GetDataSize();
        size_t                               header_size         = 0;
        const void*                          header_pointer      = nullptr;
        size_t                               data_size           = 0;
        const void*                          data_pointer        = nullptr;

        if (nullptr != compressor_)
        {
            size_t packet_size = 0;
            size_t compressed_size =
                compressor_->Compress(uncompressed_size, parameter_buffer->GetData(), &thread_data->compressed_buffer_);

            if ((0 < compressed_size) && (compressed_size < uncompressed_size))
            {
                data_pointer   = reinterpret_cast<const void*>(thread_data->compressed_buffer_.data());
                data_size      = compressed_size;
                header_pointer = reinterpret_cast<const void*>(&compressed_header);
                header_size    = sizeof(format::CompressedFunctionCallHeader);

                compressed_header.block_header.type = format::BlockType::kCompressedFunctionCallBlock;
                compressed_header.api_call_id       = thread_data->call_id_;
                compressed_header.thread_id         = thread_data->thread_id_;
                compressed_header.uncompressed_size = uncompressed_size;

                packet_size += sizeof(compressed_header.api_call_id) + sizeof(compressed_header.uncompressed_size) +
                               sizeof(compressed_header.thread_id) + compressed_size;

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
            header_size        = sizeof(format::FunctionCallHeader);

            uncompressed_header.block_header.type = format::BlockType::kFunctionCallBlock;
            uncompressed_header.api_call_id       = thread_data->call_id_;
            uncompressed_header.thread_id         = thread_data->thread_id_;

            packet_size += sizeof(uncompressed_header.api_call_id) + sizeof(uncompressed_header.thread_id) + data_size;

            uncompressed_header.block_header.size = packet_size;
        }

        {
            std::lock_guard<std::mutex> lock(file_lock_);

            // Write appropriate function call block header.
            bytes_written_ += file_stream_->Write(header_pointer, header_size);

            // Write parameter data.
            bytes_written_ += file_stream_->Write(data_pointer, data_size);
        }

        if (force_file_flush_)
        {
            file_stream_->Flush();
        }

        encoder->Reset();
    }
    else if (encoder != nullptr)
    {
        encoder->Reset();
    }
}

void TraceManager::EndFrame()
{
    if (trim_enabled_)
    {
        ++current_frame_;

        if ((capture_mode_ & kModeWrite) != kModeWrite)
        {
            // Capture is not active. Check for start of capture frame range.
            if (trim_ranges_[trim_current_range_].first == current_frame_)
            {
                bool success = CreateCaptureFile();
                if (success)
                {
                    capture_mode_ |= kModeWrite;

                    auto thread_data = GetThreadData();
                    assert(thread_data != nullptr);

                    VulkanStateWriter state_writer(file_stream_.get(), compressor_.get(), thread_data->thread_id_);
                    state_tracker_->WriteState(&state_writer);
                }
                else
                {
                    GFXRECON_LOG_FATAL("Failed to initialize capture for trim range; capture has been disabled");
                    capture_mode_ = kModeDisabled;
                }
            }
        }
        else
        {
            // Currently capture a frame range. Check for end of range.
            --trim_ranges_[trim_current_range_].total;
            if (trim_ranges_[trim_current_range_].total == 0)
            {
                // Stop recording and close file.
                capture_mode_ &= ~kModeWrite;
                file_stream_ = nullptr;

                // Advance to next range
                ++trim_current_range_;
                if (trim_current_range_ >= trim_ranges_.size())
                {
                    // No more frames to capture. Capture can be disabled and resources can be released.
                    trim_enabled_  = false;
                    capture_mode_  = kModeDisabled;
                    state_tracker_ = nullptr;
                    compressor_    = nullptr;
                }
            }
        }
    }
}

bool TraceManager::CreateCaptureFile()
{
    bool        success  = true;
    std::string filename = base_filename_;

    if (timestamp_filename_)
    {
        filename = util::filepath::GenerateTimestampedFilename(filename);
    }

    file_stream_ = std::make_unique<util::FileOutputStream>(filename);

    if (file_stream_->IsValid())
    {
        GFXRECON_LOG_INFO("Recording graphics API capture to %s", filename.c_str());
        WriteFileHeader();
    }
    else
    {
        file_stream_ = nullptr;
        success      = false;
    }

    return success;
}

void TraceManager::WriteFileHeader()
{
    std::vector<format::FileOptionPair> option_list;

    BuildOptionList(file_options_, &option_list);

    format::FileHeader file_header;
    file_header.fourcc        = GFXRECON_FOURCC;
    file_header.major_version = 0;
    file_header.minor_version = 0;
    file_header.num_options   = static_cast<uint32_t>(option_list.size());

    bytes_written_ += file_stream_->Write(&file_header, sizeof(file_header));
    bytes_written_ += file_stream_->Write(option_list.data(), option_list.size() * sizeof(format::FileOptionPair));
}

void TraceManager::BuildOptionList(const format::EnabledOptions&        enabled_options,
                                   std::vector<format::FileOptionPair>* option_list)
{
    assert(option_list != nullptr);

    option_list->push_back({ format::FileOption::kCompressionType, enabled_options.compression_type });
}

void TraceManager::WriteDisplayMessageCmd(const char* message)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        size_t                              message_length = util::platform::StringLength(message);
        format::DisplayMessageCommandHeader message_cmd;

        message_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        message_cmd.meta_header.block_header.size =
            sizeof(message_cmd.meta_header.meta_data_type) + sizeof(message_cmd.thread_id) + message_length;
        message_cmd.meta_header.meta_data_type = format::MetaDataType::kDisplayMessageCommand;
        message_cmd.thread_id                  = GetThreadData()->thread_id_;

        {
            std::lock_guard<std::mutex> lock(file_lock_);

            bytes_written_ += file_stream_->Write(&message_cmd, sizeof(message_cmd));
            bytes_written_ += file_stream_->Write(message, message_length);
        }
    }
}

void TraceManager::WriteResizeWindowCmd(VkSurfaceKHR surface, uint32_t width, uint32_t height)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        format::ResizeWindowCommand resize_cmd;
        resize_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        resize_cmd.meta_header.block_header.size = sizeof(resize_cmd.meta_header.meta_data_type) +
                                                   sizeof(resize_cmd.thread_id) + sizeof(resize_cmd.surface_id) +
                                                   sizeof(resize_cmd.width) + sizeof(resize_cmd.height);
        resize_cmd.meta_header.meta_data_type = format::MetaDataType::kResizeWindowCommand;
        resize_cmd.thread_id                  = GetThreadData()->thread_id_;

        resize_cmd.surface_id = format::ToHandleId(surface);
        resize_cmd.width      = width;
        resize_cmd.height     = height;

        {
            std::lock_guard<std::mutex> lock(file_lock_);
            bytes_written_ += file_stream_->Write(&resize_cmd, sizeof(resize_cmd));
        }
    }
}

void TraceManager::WriteFillMemoryCmd(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, const void* data)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

        format::FillMemoryCommandHeader fill_cmd;
        const uint8_t*                  write_address = (static_cast<const uint8_t*>(data) + offset);
        size_t                          write_size    = static_cast<size_t>(size);

        fill_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        fill_cmd.meta_header.meta_data_type    = format::MetaDataType::kFillMemoryCommand;
        fill_cmd.thread_id                     = GetThreadData()->thread_id_;
        fill_cmd.memory_id                     = format::ToHandleId(memory);
        fill_cmd.memory_offset                 = offset;
        fill_cmd.memory_size                   = size;

        if (compressor_ != nullptr)
        {
            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            size_t compressed_size = compressor_->Compress(write_size, write_address, &thread_data->compressed_buffer_);

            if ((compressed_size > 0) && (compressed_size < write_size))
            {
                // We don't have a special header for compressed fill commands because the header always includes
                // the uncompressed size, so we just change the type to indicate the data is compressed.
                fill_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                write_address = thread_data->compressed_buffer_.data();
                write_size    = compressed_size;
            }
        }

        // Calculate size of packet with compressed or uncompressed data size.
        fill_cmd.meta_header.block_header.size =
            sizeof(fill_cmd.meta_header.meta_data_type) + sizeof(fill_cmd.thread_id) + sizeof(fill_cmd.memory_id) +
            sizeof(fill_cmd.memory_offset) + sizeof(fill_cmd.memory_size) + write_size;

        {
            std::lock_guard<std::mutex> lock(file_lock_);

            bytes_written_ += file_stream_->Write(&fill_cmd, sizeof(fill_cmd));
            bytes_written_ += file_stream_->Write(write_address, write_size);
        }
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

            // Sort the descriptor update template info by type, so it can be written to the capture file
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
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSwapchain);

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
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

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
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    if ((result == VK_SUCCESS) && (ppData != nullptr))
    {
        std::lock_guard<std::mutex> lock(memory_tracker_lock_);
        MemoryTracker::EntryInfo*   info      = nullptr;
        bool                        first_map = memory_tracker_.MapEntry(memory, offset, size, (*ppData), &info);

        if ((info != nullptr) && (info->mapped_size > 0) &&
            (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard))
        {
            if (first_map)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, info->mapped_size);

                util::PageGuardManager* manager = util::PageGuardManager::Get();

                assert(manager != nullptr);

                info->tracked_memory = manager->AddMemory(
                    format::ToHandleId(memory), (*ppData), static_cast<size_t>(info->mapped_size), false);
            }
            else
            {
                // The application has mapped the same VkDeviceMemory object more than once and the pageguard manager is
                // already tracking it, so we will return the pointer obtained from the pageguard manager on the first
                // map call.
                GFXRECON_LOG_WARNING("VkDeviceMemory object with handle = %" PRIx64 " has been mapped more than once",
                                     memory);
            }

            // Return the pointer provided by the pageguard manager, which may be a pointer to shadow memory, not the
            // mapped memory.
            (*ppData) = info->tracked_memory;
        }
    }
}

void TraceManager::PreProcess_vkFlushMappedMemoryRanges(VkDevice                   device,
                                                        uint32_t                   memoryRangeCount,
                                                        const VkMappedMemoryRange* pMemoryRanges)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if (pMemoryRanges != nullptr)
    {
        if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            // TODO: Determine if this can be deferred to vkQueueSubmit for memory types with the HOST_COHERENT
            // property.
            VkDeviceMemory          current_memory = VK_NULL_HANDLE;
            util::PageGuardManager* manager        = util::PageGuardManager::Get();
            assert(manager != nullptr);

            std::lock_guard<std::mutex> lock(memory_tracker_lock_);

            for (uint32_t i = 0; i < memoryRangeCount; ++i)
            {
                if (current_memory != pMemoryRanges[i].memory)
                {
                    current_memory = pMemoryRanges[i].memory;
                    auto info      = memory_tracker_.GetEntryInfo(current_memory);

                    if ((info != nullptr) && (info->mapped_memory != nullptr))
                    {
                        manager->ProcessMemoryEntry(
                            format::ToHandleId(current_memory),
                            [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                                WriteFillMemoryCmd(
                                    format::FromHandleId<VkDeviceMemory>(memory_id), offset, size, start_address);
                            });
                    }
                }
            }
        }
        else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kAssisted)
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

                if ((info != nullptr) && (info->mapped_memory != nullptr))
                {
                    assert(pMemoryRanges[i].offset >= info->mapped_offset);

                    // The mapped pointer already includes the mapped offset.  Because the memory range
                    // offset is realtive to the start of the memory object, we need to adjust it to be
                    // realitve to the start of the mapped pointer.
                    VkDeviceSize relative_offset = pMemoryRanges[i].offset - info->mapped_offset;
                    VkDeviceSize size            = pMemoryRanges[i].size;
                    if (size == VK_WHOLE_SIZE)
                    {
                        size = info->allocation_size - pMemoryRanges[i].offset;
                    }

                    WriteFillMemoryCmd(pMemoryRanges[i].memory, relative_offset, size, info->mapped_memory);
                }
            }
        }
    }
}

void TraceManager::PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    std::lock_guard<std::mutex> lock(memory_tracker_lock_);

    if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        auto info = memory_tracker_.GetEntryInfo(memory);

        if ((info != nullptr) && (info->mapped_memory != nullptr))
        {
            manager->ProcessMemoryEntry(
                format::ToHandleId(memory),
                [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                    WriteFillMemoryCmd(format::FromHandleId<VkDeviceMemory>(memory_id), offset, size, start_address);
                });

            manager->RemoveMemory(format::ToHandleId(memory));
        }
    }
    else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kUnassisted)
    {
        // Write the entire mapped region.
        auto info = memory_tracker_.GetEntryInfo(memory);
        if ((info != nullptr) && (info->mapped_memory != nullptr))
        {
            // We set offset to 0, because the pointer returned by vkMapMemory already includes the offset.
            WriteFillMemoryCmd(memory, 0, info->mapped_size, info->mapped_memory);
        }
    }

    memory_tracker_.UnmapEntry(memory);
}

void TraceManager::PreProcess_vkFreeMemory(VkDevice                     device,
                                           VkDeviceMemory               memory,
                                           const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    std::lock_guard<std::mutex> lock(memory_tracker_lock_);

    bool is_mapped = false;
    memory_tracker_.RemoveEntry(memory, &is_mapped);

    if ((memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard) && is_mapped)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        manager->RemoveMemory(format::ToHandleId(memory));
    }
}

void TraceManager::PreProcess_vkQueueSubmit(VkQueue             queue,
                                            uint32_t            submitCount,
                                            const VkSubmitInfo* pSubmits,
                                            VkFence             fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_UNREFERENCED_PARAMETER(submitCount);
    GFXRECON_UNREFERENCED_PARAMETER(pSubmits);
    GFXRECON_UNREFERENCED_PARAMETER(fence);

    if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
    {
        std::lock_guard<std::mutex> lock(memory_tracker_lock_);

        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        manager->ProcessMemoryEntries([this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
            WriteFillMemoryCmd(format::FromHandleId<VkDeviceMemory>(memory_id), offset, size, start_address);
        });
    }
    else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kUnassisted)
    {
        std::lock_guard<std::mutex> lock(memory_tracker_lock_);

        memory_tracker_.VisitEntries([this](VkDeviceMemory memory, const MemoryTracker::EntryInfo& entry) {
            // If the memory is mapped, write the entire mapped region.
            if (entry.mapped_memory != nullptr)
            {
                // We set offset to 0, because the pointer returned by vkMapMemory already includes the offset.
                WriteFillMemoryCmd(memory, 0, entry.mapped_size, entry.mapped_memory);
            }
        });
    }
}

void TraceManager::PreProcess_vkCreateDescriptorUpdateTemplate(VkResult                                    result,
                                                               VkDevice                                    device,
                                                               const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                               const VkAllocationCallbacks*                pAllocator,
                                                               VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

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
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if ((result == VK_SUCCESS) && (pCreateInfo != nullptr) && (pDescriptorUpdateTemplate != nullptr))
    {
        AddDescriptorUpdateTemplate((*pDescriptorUpdateTemplate), pCreateInfo);
    }
}

void TraceManager::PreProcess_vkDestroyDescriptorUpdateTemplate(VkDevice                     device,
                                                                VkDescriptorUpdateTemplate   descriptorUpdateTemplate,
                                                                const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    RemoveDescriptorUpdateTemplate(descriptorUpdateTemplate);
}

void TraceManager::PreProcess_vkDestroyDescriptorUpdateTemplateKHR(VkDevice                   device,
                                                                   VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                   const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    RemoveDescriptorUpdateTemplate(descriptorUpdateTemplate);
}

#if defined(__ANDROID__)
void TraceManager::PreProcess_GetPhysicalDeviceSurfacePresentModesKHR(VkResult          result,
                                                                      VkPhysicalDevice  physicalDevice,
                                                                      VkSurfaceKHR      surface,
                                                                      uint32_t*         pPresentModeCount,
                                                                      VkPresentModeKHR* pPresentModes)
{
    GFXRECON_UNREFERENCED_PARAMETER(physicalDevice);
    GFXRECON_UNREFERENCED_PARAMETER(surface);

    if ((result == VK_SUCCESS) && (pPresentModeCount != nullptr) && ((*pPresentModeCount) > 0) &&
        (pPresentModes != nullptr))
    {
        for (uint32_t i = 0; i < (*pPresentModeCount); ++i)
        {
            pPresentModes[i] = VK_PRESENT_MODE_FIFO_KHR;
        }
    }
}
#endif

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
