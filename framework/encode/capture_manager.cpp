/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
** Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
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

#include "project_version.h"

#include "encode/capture_manager.h"

#include "format/format_util.h"
#include "util/compressor.h"
#include "util/file_path.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/platform.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// One based frame count.
const uint32_t kFirstFrame = 1;

std::mutex                                     CaptureManager::ThreadData::count_lock_;
format::ThreadId                               CaptureManager::ThreadData::thread_count_ = 0;
std::unordered_map<uint64_t, format::ThreadId> CaptureManager::ThreadData::id_map_;

uint32_t                                                 CaptureManager::instance_count_ = 0;
std::mutex                                               CaptureManager::instance_lock_;
thread_local std::unique_ptr<CaptureManager::ThreadData> CaptureManager::thread_data_;

std::atomic<format::HandleId> CaptureManager::unique_id_counter_{ format::kNullHandleId };

CaptureManager::ThreadData::ThreadData() :
    thread_id_(GetThreadId()), object_id_(format::kNullHandleId), call_id_(format::ApiCallId::ApiCall_Unknown)
{
    parameter_buffer_  = std::make_unique<util::MemoryOutputStream>();
    parameter_encoder_ = std::make_unique<ParameterEncoder>(parameter_buffer_.get());
}

format::ThreadId CaptureManager::ThreadData::GetThreadId()
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

CaptureManager::CaptureManager(format::ApiFamilyId api_family) :
    api_family_(api_family), force_file_flush_(false), timestamp_filename_(true),
    memory_tracking_mode_(CaptureSettings::MemoryTrackingMode::kPageGuard), page_guard_align_buffer_sizes_(false),
    page_guard_track_ahb_memory_(false), page_guard_memory_mode_(kMemoryModeShadowInternal), trim_enabled_(false),
    trim_current_range_(0), current_frame_(kFirstFrame), capture_mode_(kModeWrite), previous_hotkey_state_(false),
    debug_layer_(false)
{}

CaptureManager::~CaptureManager()
{
    if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
    {
        util::PageGuardManager::Destroy();
    }
}

bool CaptureManager::CreateInstance(std::function<CaptureManager*()> GetInstanceFunc,
                                    std::function<void()>            NewInstanceFunc)
{
    bool                        success = true;
    std::lock_guard<std::mutex> instance_lock(instance_lock_);

    if (instance_count_ == 0)
    {
        assert(GetInstanceFunc() == nullptr);

        // Default initialize logging to report issues while loading settings.
        const util::Log::Severity defaultLogLevel = util::Log::Severity::kInfoSeverity;
        util::Log::Init(defaultLogLevel);

        CaptureSettings settings = {};
        CaptureSettings::LoadSettings(&settings);

        // Reinitialize logging with values retrieved from settings.
        const util::Log::Settings& log_settings = settings.GetLogSettings();
        util::Log::Release();
        util::Log::Init(log_settings);

        CaptureSettings::TraceSettings trace_settings = settings.GetTraceSettings();
        std::string                    base_filename  = trace_settings.capture_file;

        instance_count_ = 1;
        NewInstanceFunc();
        assert(GetInstanceFunc() != nullptr);
        success = GetInstanceFunc()->Initialize(base_filename, trace_settings);
        if (!success)
        {
            GFXRECON_LOG_FATAL("Failed to initialize CaptureManager");
        }
    }
    else
    {
        assert(GetInstanceFunc() != nullptr);
        ++instance_count_;
    }

    GFXRECON_LOG_DEBUG("CaptureManager::CreateInstance(): Current instance count is %u", instance_count_);

    return success;
}

void CaptureManager::DestroyInstance(std::function<const CaptureManager*()> GetInstanceFunc,
                                     std::function<void()>                  DeleteInstanceFunc)
{
    std::lock_guard<std::mutex> instance_lock(instance_lock_);

    if (GetInstanceFunc() != nullptr)
    {
        assert(instance_count_ > 0);

        --instance_count_;

        if (instance_count_ == 0)
        {
            DeleteInstanceFunc();
            assert(GetInstanceFunc() == nullptr);

            util::Log::Release();
        }

        GFXRECON_LOG_DEBUG("CaptureManager::DestroyInstance(): Current instance count is %u", instance_count_);
    }
}

bool CaptureManager::Initialize(std::string base_filename, const CaptureSettings::TraceSettings& trace_settings)
{
    bool success = true;

    base_filename_        = base_filename;
    file_options_         = trace_settings.capture_file_options;
    timestamp_filename_   = trace_settings.time_stamp_file;
    memory_tracking_mode_ = trace_settings.memory_tracking_mode;
    force_file_flush_     = trace_settings.force_flush;
    debug_layer_          = trace_settings.debug_layer;

    if (memory_tracking_mode_ == CaptureSettings::kPageGuard)
    {
        page_guard_align_buffer_sizes_ = trace_settings.page_guard_align_buffer_sizes;
        page_guard_track_ahb_memory_   = trace_settings.page_guard_track_ahb_memory;

        bool use_external_memory = trace_settings.page_guard_external_memory;

#if !defined(WIN32)
        if (use_external_memory)
        {
            use_external_memory = false;
            GFXRECON_LOG_WARNING("Ignoring page guard external memory option on unsupported platform (Only Windows is "
                                 "currently supported)")
        }
#endif

        // External memory takes precedence over shadow memory modes.
        if (use_external_memory)
        {
            page_guard_memory_mode_ = kMemoryModeExternal;
        }
        else if (trace_settings.page_guard_persistent_memory)
        {
            page_guard_memory_mode_ = kMemoryModeShadowPersistent;
        }
        else
        {
            page_guard_memory_mode_ = kMemoryModeShadowInternal;
        }
    }
    else
    {
        page_guard_align_buffer_sizes_ = false;
        page_guard_track_ahb_memory_   = false;
        page_guard_memory_mode_        = kMemoryModeDisabled;
    }

    if (trace_settings.trim_ranges.empty() && trace_settings.trim_key.empty())
    {
        // Use default kModeWrite capture mode.
        success = CreateCaptureFile(base_filename_);
    }
    else
    {
        // Override default kModeWrite capture mode.
        trim_enabled_ = true;
        trim_ranges_  = trace_settings.trim_ranges;

        // Determine if trim starts at the first frame
        if (!trace_settings.trim_ranges.empty())
        {
            if (trim_ranges_[0].first == current_frame_)
            {
                // When capturing from the first frame, state tracking only needs to be enabled if there is more than
                // one capture range.
                if (trim_ranges_.size() > 1)
                {
                    capture_mode_ = kModeWriteAndTrack;
                }

                success = CreateCaptureFile(CreateTrimFilename(base_filename_, trim_ranges_[0]));
            }
            else
            {
                capture_mode_ = kModeTrack;
            }
        }
        // Check if trim is enabled by hot-key trigger at the first frame
        else if (!trace_settings.trim_key.empty())
        {
            trim_key_ = trace_settings.trim_key;

            // Enable state tracking when hotkey pressed
            if (IsTrimHotkeyPressed())
            {
                capture_mode_ = kModeWriteAndTrack;

                success = CreateCaptureFile(util::filepath::InsertFilenamePostfix(base_filename_, "_trim_trigger"));
            }
            else
            {
                capture_mode_ = kModeTrack;
            }
        }
        else
        {
            capture_mode_ = kModeTrack;
        }
    }

    if (success)
    {
        compressor_ = std::unique_ptr<util::Compressor>(format::CreateCompressor(file_options_.compression_type));
        if ((compressor_ == nullptr) && (file_options_.compression_type != format::CompressionType::kNone))
        {
            success = false;
        }
    }

    if (success)
    {
        if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            util::PageGuardManager::Create(trace_settings.page_guard_copy_on_map,
                                           trace_settings.page_guard_separate_read,
                                           util::PageGuardManager::kDefaultEnableReadWriteSamePage);
        }

        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            CreateStateTracker();
        }
    }
    else
    {
        capture_mode_ = kModeDisabled;
    }

    return success;
}

ParameterEncoder* CaptureManager::InitApiCallCapture(format::ApiCallId call_id)
{
    auto thread_data      = GetThreadData();
    thread_data->call_id_ = call_id;
    return thread_data->parameter_encoder_.get();
}

ParameterEncoder* CaptureManager::InitMethodCallCapture(format::ApiCallId call_id, format::HandleId object_id)
{
    auto thread_data        = GetThreadData();
    thread_data->call_id_   = call_id;
    thread_data->object_id_ = object_id;
    return thread_data->parameter_encoder_.get();
}

void CaptureManager::EndApiCallCapture(ParameterEncoder* encoder)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        assert(encoder != nullptr);

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

        if (compressor_ != nullptr)
        {
            size_t packet_size = 0;
            size_t compressed_size =
                compressor_->Compress(uncompressed_size, parameter_buffer->GetData(), &thread_data->compressed_buffer_);

            if ((compressed_size > 0) && (compressed_size < uncompressed_size))
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
            file_stream_->Write(header_pointer, header_size);

            // Write parameter data.
            file_stream_->Write(data_pointer, data_size);

            if (force_file_flush_)
            {
                file_stream_->Flush();
            }
        }

        encoder->Reset();
    }
    else if (encoder != nullptr)
    {
        encoder->Reset();
    }
}

void CaptureManager::EndMethodCallCapture(ParameterEncoder* encoder)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        assert(encoder != nullptr);

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        auto parameter_buffer = thread_data->parameter_buffer_.get();
        assert((parameter_buffer != nullptr) && (thread_data->parameter_encoder_ != nullptr) &&
               (thread_data->parameter_encoder_.get() == encoder));

        bool                               not_compressed      = true;
        format::CompressedMethodCallHeader compressed_header   = {};
        format::MethodCallHeader           uncompressed_header = {};
        size_t                             uncompressed_size   = parameter_buffer->GetDataSize();
        size_t                             header_size         = 0;
        const void*                        header_pointer      = nullptr;
        size_t                             data_size           = 0;
        const void*                        data_pointer        = nullptr;

        if (compressor_ != nullptr)
        {
            size_t packet_size = 0;
            size_t compressed_size =
                compressor_->Compress(uncompressed_size, parameter_buffer->GetData(), &thread_data->compressed_buffer_);

            if ((compressed_size > 0) && (compressed_size < uncompressed_size))
            {
                data_pointer   = reinterpret_cast<const void*>(thread_data->compressed_buffer_.data());
                data_size      = compressed_size;
                header_pointer = reinterpret_cast<const void*>(&compressed_header);
                header_size    = sizeof(format::CompressedMethodCallHeader);

                compressed_header.block_header.type = format::BlockType::kCompressedMethodCallBlock;
                compressed_header.api_call_id       = thread_data->call_id_;
                compressed_header.object_id         = thread_data->object_id_;
                compressed_header.thread_id         = thread_data->thread_id_;
                compressed_header.uncompressed_size = uncompressed_size;

                packet_size += sizeof(compressed_header.api_call_id) + sizeof(compressed_header.object_id) +
                               sizeof(compressed_header.uncompressed_size) + sizeof(compressed_header.thread_id) +
                               compressed_size;

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
            header_size        = sizeof(format::MethodCallHeader);

            uncompressed_header.block_header.type = format::BlockType::kMethodCallBlock;
            uncompressed_header.api_call_id       = thread_data->call_id_;
            uncompressed_header.object_id         = thread_data->object_id_;
            uncompressed_header.thread_id         = thread_data->thread_id_;

            packet_size += sizeof(uncompressed_header.api_call_id) + sizeof(compressed_header.object_id) +
                           sizeof(uncompressed_header.thread_id) + data_size;

            uncompressed_header.block_header.size = packet_size;
        }

        {
            std::lock_guard<std::mutex> lock(file_lock_);

            // Write appropriate function call block header.
            file_stream_->Write(header_pointer, header_size);

            // Write parameter data.
            file_stream_->Write(data_pointer, data_size);

            if (force_file_flush_)
            {
                file_stream_->Flush();
            }
        }

        encoder->Reset();
    }
    else if (encoder != nullptr)
    {
        encoder->Reset();
    }
}

bool CaptureManager::IsTrimHotkeyPressed()
{
    // Return true when GetKeyState() transitions from false to true
    bool hotkey_state      = keyboard_.GetKeyState(trim_key_);
    bool hotkey_pressed    = hotkey_state && !previous_hotkey_state_;
    previous_hotkey_state_ = hotkey_state;
    return hotkey_pressed;
}

void CaptureManager::CheckContinueCaptureForWriteMode()
{
    if (!trim_ranges_.empty())
    {
        --trim_ranges_[trim_current_range_].total;
        if (trim_ranges_[trim_current_range_].total == 0)
        {
            // Stop recording and close file.
            capture_mode_ &= ~kModeWrite;
            file_stream_ = nullptr;
            GFXRECON_LOG_INFO("Finished recording graphics API capture");

            // Advance to next range
            ++trim_current_range_;
            if (trim_current_range_ >= trim_ranges_.size())
            {
                // No more frames to capture. Capture can be disabled and resources can be released.
                trim_enabled_ = false;
                capture_mode_ = kModeDisabled;
                DestroyStateTracker();
                compressor_ = nullptr;
            }
            else if (trim_ranges_[trim_current_range_].first == current_frame_)
            {
                // Trimming was configured to capture two consecutive frames, so we need to start a new capture
                // file for the current frame.
                const CaptureSettings::TrimRange& trim_range = trim_ranges_[trim_current_range_];
                bool success = CreateCaptureFile(CreateTrimFilename(base_filename_, trim_range));
                if (success)
                {
                    ActivateTrimming();
                }
                else
                {
                    GFXRECON_LOG_FATAL("Failed to initialize capture for trim range; capture has been disabled");
                    trim_enabled_ = false;
                    capture_mode_ = kModeDisabled;
                }
            }
        }
    }
    else if (IsTrimHotkeyPressed())
    {
        // Stop recording and close file.
        capture_mode_ &= ~kModeWrite;
        file_stream_ = nullptr;
        GFXRECON_LOG_INFO("Finished recording graphics API capture");
    }
}

void CaptureManager::CheckStartCaptureForTrackMode()
{
    if (!trim_ranges_.empty())
    {
        if (trim_ranges_[trim_current_range_].first == current_frame_)
        {
            const CaptureSettings::TrimRange& trim_range = trim_ranges_[trim_current_range_];
            bool success = CreateCaptureFile(CreateTrimFilename(base_filename_, trim_range));
            if (success)
            {
                ActivateTrimming();
            }
            else
            {
                GFXRECON_LOG_FATAL("Failed to initialize capture for trim range; capture has been disabled");
                trim_enabled_ = false;
                capture_mode_ = kModeDisabled;
            }
        }
    }
    else if (IsTrimHotkeyPressed())
    {
        bool success = CreateCaptureFile(util::filepath::InsertFilenamePostfix(base_filename_, "_trim_trigger"));
        if (success)
        {
            ActivateTrimming();
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to initialize capture for hotkey trim trigger; capture has been disabled");
            trim_enabled_ = false;
            capture_mode_ = kModeDisabled;
        }
    }
}

void CaptureManager::EndFrame()
{
    if (trim_enabled_)
    {
        ++current_frame_;

        if ((capture_mode_ & kModeWrite) == kModeWrite)
        {
            // Currently capturing a frame range.
            // Check for end of range or hotkey trigger to stop capture.
            CheckContinueCaptureForWriteMode();
        }
        else if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            // Capture is not active.
            // Check for start of capture frame range or hotkey trigger to start capture
            CheckStartCaptureForTrackMode();
        }
    }
}

std::string CaptureManager::CreateTrimFilename(const std::string&                base_filename,
                                               const CaptureSettings::TrimRange& trim_range)
{
    assert(trim_range.total > 0);

    std::string range_string = "_";

    if (trim_range.total == 1)
    {
        range_string += "frame_";
        range_string += std::to_string(trim_range.first);
    }
    else
    {
        range_string += "frames_";
        range_string += std::to_string(trim_range.first);
        range_string += "_through_";
        range_string += std::to_string((trim_range.first + trim_range.total) - 1);
    }

    return util::filepath::InsertFilenamePostfix(base_filename, range_string);
}

bool CaptureManager::CreateCaptureFile(const std::string& base_filename)
{
    bool        success          = true;
    std::string capture_filename = base_filename;

    if (timestamp_filename_)
    {
        capture_filename = util::filepath::GenerateTimestampedFilename(capture_filename);
    }

    file_stream_ = std::make_unique<util::FileOutputStream>(capture_filename);

    if (file_stream_->IsValid())
    {
        GFXRECON_LOG_INFO("Recording graphics API capture to %s", capture_filename.c_str());
        WriteFileHeader();
    }
    else
    {
        file_stream_ = nullptr;
        success      = false;
    }

    return success;
}

void CaptureManager::ActivateTrimming()
{
    std::lock_guard<std::mutex> lock(file_lock_);

    capture_mode_ |= kModeWrite;

    auto thread_data = GetThreadData();
    assert(thread_data != nullptr);

    WriteTrackedState(thread_data->thread_id_);
}

void CaptureManager::WriteFileHeader()
{
    std::vector<format::FileOptionPair> option_list;

    BuildOptionList(file_options_, &option_list);

    format::FileHeader file_header;
    file_header.fourcc        = GFXRECON_FOURCC;
    file_header.major_version = 0;
    file_header.minor_version = 0;
    file_header.num_options   = static_cast<uint32_t>(option_list.size());

    file_stream_->Write(&file_header, sizeof(file_header));
    file_stream_->Write(option_list.data(), option_list.size() * sizeof(format::FileOptionPair));

    if (force_file_flush_)
    {
        file_stream_->Flush();
    }
}

void CaptureManager::BuildOptionList(const format::EnabledOptions&        enabled_options,
                                     std::vector<format::FileOptionPair>* option_list)
{
    assert(option_list != nullptr);

    option_list->push_back({ format::FileOption::kCompressionType, enabled_options.compression_type });
}

void CaptureManager::WriteDisplayMessageCmd(const char* message)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        size_t                              message_length = util::platform::StringLength(message);
        format::DisplayMessageCommandHeader message_cmd;

        message_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        message_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(message_cmd) + message_length;
        message_cmd.meta_header.meta_data_id =
            format::MakeMetaDataId(api_family_, format::MetaDataType::kDisplayMessageCommand);
        message_cmd.thread_id = GetThreadData()->thread_id_;

        {
            std::lock_guard<std::mutex> lock(file_lock_);

            file_stream_->Write(&message_cmd, sizeof(message_cmd));
            file_stream_->Write(message, message_length);

            if (force_file_flush_)
            {
                file_stream_->Flush();
            }
        }
    }
}

void CaptureManager::WriteResizeWindowCmd(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        format::ResizeWindowCommand resize_cmd;
        resize_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        resize_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(resize_cmd);
        resize_cmd.meta_header.meta_data_id =
            format::MakeMetaDataId(api_family_, format::MetaDataType::kResizeWindowCommand);
        resize_cmd.thread_id = GetThreadData()->thread_id_;

        resize_cmd.surface_id = surface_id;
        resize_cmd.width      = width;
        resize_cmd.height     = height;

        {
            std::lock_guard<std::mutex> lock(file_lock_);
            file_stream_->Write(&resize_cmd, sizeof(resize_cmd));

            if (force_file_flush_)
            {
                file_stream_->Flush();
            }
        }
    }
}

void CaptureManager::WriteFillMemoryCmd(format::HandleId memory_id, uint64_t offset, uint64_t size, const void* data)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

        format::FillMemoryCommandHeader fill_cmd;
        const uint8_t*                  write_address = (static_cast<const uint8_t*>(data) + offset);
        size_t                          write_size    = static_cast<size_t>(size);

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        fill_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        fill_cmd.meta_header.meta_data_id =
            format::MakeMetaDataId(api_family_, format::MetaDataType::kFillMemoryCommand);
        fill_cmd.thread_id     = thread_data->thread_id_;
        fill_cmd.memory_id     = memory_id;
        fill_cmd.memory_offset = offset;
        fill_cmd.memory_size   = size;

        if (compressor_ != nullptr)
        {
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
        fill_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(fill_cmd) + write_size;

        {
            std::lock_guard<std::mutex> lock(file_lock_);

            file_stream_->Write(&fill_cmd, sizeof(fill_cmd));
            file_stream_->Write(write_address, write_size);

            if (force_file_flush_)
            {
                file_stream_->Flush();
            }
        }
    }
}

void CaptureManager::WriteCreateHeapAllocationCmd(uint64_t allocation_id, uint64_t allocation_size)
{
    if ((GetCaptureMode() & kModeWrite) == kModeWrite)
    {
        format::CreateHeapAllocationCommand allocation_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        allocation_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        allocation_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(allocation_cmd);
        allocation_cmd.meta_header.meta_data_id =
            format::MakeMetaDataId(api_family_, format::MetaDataType::kCreateHeapAllocationCommand);
        allocation_cmd.thread_id       = thread_data->thread_id_;
        allocation_cmd.allocation_id   = allocation_id;
        allocation_cmd.allocation_size = allocation_size;

        {
            std::lock_guard<std::mutex> lock(file_lock_);

            file_stream_->Write(&allocation_cmd, sizeof(allocation_cmd));

            if (GetForceFileFlush())
            {
                file_stream_->Flush();
            }
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
