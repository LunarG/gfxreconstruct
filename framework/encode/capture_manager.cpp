/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
** Copyright (c) 2019-2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "format/format_util.h"
#include "util/compressor.h"
#include "util/file_path.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/platform.h"

#include <cassert>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// One based frame count.
const uint32_t kFirstFrame           = 1;
const size_t   kFileStreamBufferSize = 256 * 1024;

std::mutex                                     CaptureManager::ThreadData::count_lock_;
format::ThreadId                               CaptureManager::ThreadData::thread_count_ = 0;
std::unordered_map<uint64_t, format::ThreadId> CaptureManager::ThreadData::id_map_;

uint32_t                                                 CaptureManager::instance_count_ = 0;
std::mutex                                               CaptureManager::instance_lock_;
thread_local std::unique_ptr<CaptureManager::ThreadData> CaptureManager::thread_data_;
util::SharedMutex                                        CaptureManager::state_mutex_;

std::atomic<format::HandleId> CaptureManager::unique_id_counter_{ format::kNullHandleId };

CaptureManager::ThreadData::ThreadData() :
    thread_id_(GetThreadId()), object_id_(format::kNullHandleId), call_id_(format::ApiCallId::ApiCall_Unknown)
{
    parameter_buffer_  = std::make_unique<encode::ParameterBuffer>();
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
    page_guard_track_ahb_memory_(false), page_guard_unblock_sigsegv(false),
    page_guard_memory_mode_(kMemoryModeShadowInternal), trim_enabled_(false), trim_current_range_(0),
    current_frame_(kFirstFrame), capture_mode_(kModeWrite), previous_hotkey_state_(false), debug_layer_(false),
    debug_device_lost_(false), screenshot_prefix_(""), screenshots_enabled_(false), global_frame_count_(0)
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

        // Create new instance of capture manager.
        instance_count_ = 1;
        NewInstanceFunc();

        assert(GetInstanceFunc() != nullptr);

        // Initialize logging to report only errors (to stderr).
        util::Log::Settings stderr_only_log_settings;
        stderr_only_log_settings.min_severity            = util::Log::kErrorSeverity;
        stderr_only_log_settings.output_errors_to_stderr = true;
        util::Log::Init(stderr_only_log_settings);

        // Get capture settings which can be different per capture manager.
        CaptureSettings settings(GetInstanceFunc()->GetDefaultTraceSettings());

        // Load log settings.
        CaptureSettings::LoadLogSettings(&settings);

        // Reinitialize logging with values retrieved from settings.
        util::Log::Release();
        util::Log::Init(settings.GetLogSettings());

        // Load all settings with final logging settings active.
        CaptureSettings::LoadSettings(&settings);

        GFXRECON_LOG_INFO("Initializing GFXReconstruct capture layer");
        GFXRECON_LOG_INFO("  GFXReconstruct Version %s", GFXRECON_PROJECT_VERSION_STRING);

        CaptureSettings::TraceSettings trace_settings = settings.GetTraceSettings();
        std::string                    base_filename  = trace_settings.capture_file;

        // Initialize capture manager with default settings.
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

std::vector<uint32_t> CalcScreenshotIndices(std::vector<util::FrameRange> ranges)
{
    // Take a range of frames and convert it to a flat list of indices
    std::vector<uint32_t> indices;

    for (uint32_t i = 0; i < ranges.size(); ++i)
    {
        util::FrameRange& range = ranges[i];

        uint32_t diff = range.last - range.first + 1;

        for (uint32_t j = 0; j < diff; ++j)
        {
            uint32_t screenshot_index = range.first + j;

            indices.push_back(screenshot_index);
        }
    }

    // Sort and reverse index list once, so that we may refer to only last element as we Present()
    std::sort(indices.begin(), indices.end());
    std::reverse(indices.begin(), indices.end());

    return indices;
}

std::string PrepScreenshotPrefix(const std::string& dir)
{
    std::string out = dir;

    if (!out.empty())
    {
        if (out.back() != util::filepath::kPathSep)
        {
            out += util::filepath::kPathSep;
        }
    }

    out += "screenshot";

    return out;
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
    debug_device_lost_    = trace_settings.debug_device_lost;
    screenshots_enabled_  = !trace_settings.screenshot_ranges.empty();
    screenshot_indices_   = CalcScreenshotIndices(trace_settings.screenshot_ranges);
    screenshot_prefix_    = PrepScreenshotPrefix(trace_settings.screenshot_dir);

    if (memory_tracking_mode_ == CaptureSettings::kPageGuard)
    {
        page_guard_align_buffer_sizes_ = trace_settings.page_guard_align_buffer_sizes;
        page_guard_track_ahb_memory_   = trace_settings.page_guard_track_ahb_memory;
        page_guard_unblock_sigsegv     = trace_settings.page_guard_unblock_sigsegv;

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
            trim_key_frames_ = trace_settings.trim_key_frames;

            // Enable state tracking when hotkey pressed
            if (IsTrimHotkeyPressed())
            {
                capture_mode_ = kModeWriteAndTrack;
                trim_key_first_frame_ = current_frame_;

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
                                           util::PageGuardManager::kDefaultEnableReadWriteSamePage,
                                           trace_settings.page_guard_unblock_sigsegv);
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

    // Reset the parameter buffer and reserve space for an uncompressed FunctionCallHeader.
    thread_data->parameter_buffer_->ResetWithHeader(sizeof(format::FunctionCallHeader));

    return thread_data->parameter_encoder_.get();
}

ParameterEncoder* CaptureManager::InitMethodCallCapture(format::ApiCallId call_id, format::HandleId object_id)
{
    auto thread_data        = GetThreadData();
    thread_data->call_id_   = call_id;
    thread_data->object_id_ = object_id;

    // Reset the parameter buffer and reserve space for an uncompressed MethodCallHeader.
    thread_data->parameter_buffer_->ResetWithHeader(sizeof(format::MethodCallHeader));

    return thread_data->parameter_encoder_.get();
}

void CaptureManager::EndApiCallCapture()
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        auto parameter_buffer = thread_data->parameter_buffer_.get();
        assert((parameter_buffer != nullptr) && (thread_data->parameter_encoder_ != nullptr));

        bool   not_compressed    = true;
        size_t uncompressed_size = parameter_buffer->GetDataSize();

        if (compressor_ != nullptr)
        {
            size_t header_size     = sizeof(format::CompressedFunctionCallHeader);
            size_t compressed_size = compressor_->Compress(
                uncompressed_size, parameter_buffer->GetData(), &thread_data->compressed_buffer_, header_size);

            if ((compressed_size > 0) && (compressed_size < uncompressed_size))
            {
                auto compressed_header =
                    reinterpret_cast<format::CompressedFunctionCallHeader*>(thread_data->compressed_buffer_.data());
                compressed_header->block_header.type = format::BlockType::kCompressedFunctionCallBlock;
                compressed_header->api_call_id       = thread_data->call_id_;
                compressed_header->thread_id         = thread_data->thread_id_;
                compressed_header->uncompressed_size = uncompressed_size;
                compressed_header->block_header.size = sizeof(compressed_header->api_call_id) +
                                                       sizeof(compressed_header->thread_id) +
                                                       sizeof(compressed_header->uncompressed_size) + compressed_size;

                WriteToFile(thread_data->compressed_buffer_.data(), header_size + compressed_size);

                not_compressed = false;
            }
        }

        if (not_compressed)
        {
            uint8_t* header_data = parameter_buffer->GetHeaderData();
            assert((header_data != nullptr) &&
                   (parameter_buffer->GetHeaderDataSize() == sizeof(format::FunctionCallHeader)));

            auto uncompressed_header               = reinterpret_cast<format::FunctionCallHeader*>(header_data);
            uncompressed_header->block_header.type = format::BlockType::kFunctionCallBlock;
            uncompressed_header->api_call_id       = thread_data->call_id_;
            uncompressed_header->thread_id         = thread_data->thread_id_;
            uncompressed_header->block_header.size =
                sizeof(uncompressed_header->api_call_id) + sizeof(uncompressed_header->thread_id) + uncompressed_size;

            WriteToFile(parameter_buffer->GetHeaderData(),
                        parameter_buffer->GetHeaderDataSize() + parameter_buffer->GetDataSize());
        }
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
            DeactivateTrimming();
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
    else if (IsTrimHotkeyPressed() ||
             ((trim_key_frames_ > 0) && (current_frame_ >= (trim_key_first_frame_ + trim_key_frames_))))
    {
        // Stop recording and close file.
        DeactivateTrimming();
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

            trim_key_first_frame_ = current_frame_;
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

bool CaptureManager::ShouldTriggerScreenshot()
{
    bool triger_screenshot = false;

    if (screenshots_enabled_)
    {
        // Get next frame to screenshot from the back
        uint32_t target_frame = screenshot_indices_.back();

        // If this is a frame of interest, take a screenshot
        if (target_frame == global_frame_count_)
        {
            triger_screenshot = true;

            // Took screenshot, so remove it from the list
            screenshot_indices_.pop_back();
        }

        // If no more frames left, disable screenshots
        if (screenshot_indices_.empty())
        {
            screenshots_enabled_ = false;
        }
    }

    return triger_screenshot;
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

    global_frame_count_++;
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

    file_stream_ = std::make_unique<util::FileOutputStream>(capture_filename, kFileStreamBufferSize);

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
    capture_mode_ |= kModeWrite;

    auto thread_data = GetThreadData();
    assert(thread_data != nullptr);

    WriteTrackedState(file_stream_.get(), thread_data->thread_id_);
}

void CaptureManager::DeactivateTrimming()
{
    capture_mode_ &= ~kModeWrite;
    file_stream_ = nullptr;
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

    CombineAndWriteToFile({ { &file_header, sizeof(file_header) },
                            { option_list.data(), option_list.size() * sizeof(format::FileOptionPair) } });
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

        CombineAndWriteToFile({ { &message_cmd, sizeof(message_cmd) }, { message, message_length } });
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

        WriteToFile(&resize_cmd, sizeof(resize_cmd));
    }
}

void CaptureManager::WriteFillMemoryCmd(format::HandleId memory_id, uint64_t offset, uint64_t size, const void* data)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

        format::FillMemoryCommandHeader fill_cmd;
        size_t                          header_size       = sizeof(format::FillMemoryCommandHeader);
        const uint8_t*                  uncompressed_data = (static_cast<const uint8_t*>(data) + offset);
        size_t                          uncompressed_size = static_cast<size_t>(size);

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        fill_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        fill_cmd.meta_header.meta_data_id =
            format::MakeMetaDataId(api_family_, format::MetaDataType::kFillMemoryCommand);
        fill_cmd.thread_id     = thread_data->thread_id_;
        fill_cmd.memory_id     = memory_id;
        fill_cmd.memory_offset = offset;
        fill_cmd.memory_size   = size;

        bool not_compressed = true;

        if (compressor_ != nullptr)
        {
            size_t compressed_size = compressor_->Compress(
                uncompressed_size, uncompressed_data, &thread_data->compressed_buffer_, header_size);

            if ((compressed_size > 0) && (compressed_size < uncompressed_size))
            {
                not_compressed = false;

                // We don't have a special header for compressed fill commands because the header always includes
                // the uncompressed size, so we just change the type to indicate the data is compressed.
                fill_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                // Calculate size of packet with uncompressed data size.
                fill_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(fill_cmd) + compressed_size;

                // Copy header to beginning of compressed_buffer_
                util::platform::MemoryCopy(thread_data->compressed_buffer_.data(), header_size, &fill_cmd, header_size);

                WriteToFile(thread_data->compressed_buffer_.data(), header_size + compressed_size);
            }
        }

        if (not_compressed)
        {
            // Calculate size of packet with compressed data size.
            fill_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(fill_cmd) + uncompressed_size;

            CombineAndWriteToFile({ { &fill_cmd, header_size }, { uncompressed_data, uncompressed_size } });
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

        WriteToFile(&allocation_cmd, sizeof(allocation_cmd));
    }
}

void CaptureManager::WriteToFile(const void* data, size_t size)
{
    file_stream_->Write(data, size);
    if (force_file_flush_)
    {
        file_stream_->Flush();
    }
}

CaptureSettings::TraceSettings CaptureManager::GetDefaultTraceSettings()
{
    // Return default trace settings.
    return CaptureSettings::TraceSettings();
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
