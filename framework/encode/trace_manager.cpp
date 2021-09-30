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

#include "encode/trace_manager.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_state_writer.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "graphics/vulkan_device_util.h"
#include "util/compressor.h"
#include "util/file_path.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/platform.h"

#include <cassert>
#include <unordered_set>

#if defined(__linux__) && !defined(__ANDROID__)
#if defined(VK_USE_PLATFORM_XCB_KHR)
#include <xcb/xcb_keysyms.h>
#endif
#endif

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/hardware_buffer.h>
#endif
#include <encode/deferred_operation.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// One based frame count.
const uint32_t kFirstFrame           = 1;
const size_t   kFileStreamBufferSize = 256 * 1024;

std::mutex                                     TraceManager::ThreadData::count_lock_;
format::ThreadId                               TraceManager::ThreadData::thread_count_ = 0;
std::unordered_map<uint64_t, format::ThreadId> TraceManager::ThreadData::id_map_;

TraceManager*                                          TraceManager::instance_       = nullptr;
uint32_t                                               TraceManager::instance_count_ = 0;
std::mutex                                             TraceManager::instance_lock_;
thread_local std::unique_ptr<TraceManager::ThreadData> TraceManager::thread_data_;
LayerTable                                             TraceManager::layer_table_;
util::SharedMutex                                      TraceManager::state_mutex_;

std::atomic<format::HandleId> TraceManager::unique_id_counter_{ format::kNullHandleId };

TraceManager::ThreadData::ThreadData() : thread_id_(GetThreadId()), call_id_(format::ApiCallId::ApiCall_Unknown)
{
    parameter_buffer_  = std::make_unique<encode::ParameterBuffer>();
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
    force_file_flush_(false), timestamp_filename_(true),
    memory_tracking_mode_(CaptureSettings::MemoryTrackingMode::kPageGuard), page_guard_align_buffer_sizes_(false),
    page_guard_track_ahb_memory_(false), page_guard_memory_mode_(kMemoryModeShadowInternal), trim_enabled_(false),
    trim_current_range_(0), current_frame_(kFirstFrame), capture_mode_(kModeWrite), previous_hotkey_state_(false)
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

        // Initialize logging to report only errors (to stderr).
        util::Log::Settings stderr_only_log_settings;
        stderr_only_log_settings.min_severity            = util::Log::kErrorSeverity;
        stderr_only_log_settings.output_errors_to_stderr = true;
        util::Log::Init(stderr_only_log_settings);

        // Load log settings.
        CaptureSettings settings = {};
        CaptureSettings::LoadLogSettings(&settings);

        // Reinitialize logging with values retrieved from settings.
        util::Log::Release();
        util::Log::Init(settings.GetLogSettings());

        // Load all settings with final logging settings active.
        CaptureSettings::LoadSettings(&settings);

        GFXRECON_LOG_INFO("Initializing GFXReconstruct capture layer");
        GFXRECON_LOG_INFO("  GFXReconstruct Version %s", GFXRECON_PROJECT_VERSION_STRING);
        GFXRECON_LOG_INFO("  Vulkan Header Version %u.%u.%u",
                          VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                          VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                          VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));

        CaptureSettings::TraceSettings trace_settings = settings.GetTraceSettings();
        std::string                    base_filename  = trace_settings.capture_file;

        instance_count_ = 1;
        instance_       = new TraceManager();
        success         = instance_->Initialize(base_filename, trace_settings);
        if (!success)
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

void TraceManager::InitInstance(VkInstance* instance, PFN_vkGetInstanceProcAddr gpa)
{
    assert(instance != nullptr);

    CreateWrappedHandle<NoParentWrapper, NoParentWrapper, InstanceWrapper>(
        NoParentWrapper::kHandleValue, NoParentWrapper::kHandleValue, instance, GetUniqueId);

    auto wrapper = reinterpret_cast<InstanceWrapper*>(*instance);
    LoadInstanceTable(gpa, wrapper->handle, &wrapper->layer_table);
}

void TraceManager::InitDevice(VkDevice* device, PFN_vkGetDeviceProcAddr gpa)
{
    assert((device != nullptr) && ((*device) != VK_NULL_HANDLE));

    CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DeviceWrapper>(
        VK_NULL_HANDLE, NoParentWrapper::kHandleValue, device, GetUniqueId);

    auto wrapper = reinterpret_cast<DeviceWrapper*>(*device);
    LoadDeviceTable(gpa, wrapper->handle, &wrapper->layer_table);
}

bool TraceManager::Initialize(const std::string base_filename, const CaptureSettings::TraceSettings& trace_settings)
{
    bool success = true;

    base_filename_        = base_filename;
    file_options_         = trace_settings.capture_file_options;
    timestamp_filename_   = trace_settings.time_stamp_file;
    memory_tracking_mode_ = trace_settings.memory_tracking_mode;
    force_file_flush_     = trace_settings.force_flush;

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
            trim_ranges_ = trace_settings.trim_ranges;
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
        if ((nullptr == compressor_) && (format::CompressionType::kNone != file_options_.compression_type))
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

    // Reset the parameter buffer and reserve space for an uncompressed FunctionCallHeader.
    thread_data->parameter_buffer_->ResetWithHeader(sizeof(format::FunctionCallHeader));

    return thread_data->parameter_encoder_.get();
}

void TraceManager::EndApiCallTrace()
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        auto parameter_buffer = thread_data->parameter_buffer_.get();
        assert((parameter_buffer != nullptr) && (thread_data->parameter_encoder_ != nullptr));

        bool   not_compressed    = true;
        size_t uncompressed_size = parameter_buffer->GetDataSize();

        if (nullptr != compressor_)
        {
            size_t header_size     = sizeof(format::CompressedFunctionCallHeader);
            size_t compressed_size = compressor_->Compress(
                uncompressed_size, parameter_buffer->GetData(), &thread_data->compressed_buffer_, header_size);

            if ((0 < compressed_size) && (compressed_size < uncompressed_size))
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

bool TraceManager::IsTrimHotkeyPressed()
{
    // Return true when GetKeyState() transitions from false to true
    bool hotkey_state      = keyboard_.GetKeyState(trim_key_);
    bool hotkey_pressed    = hotkey_state && !previous_hotkey_state_;
    previous_hotkey_state_ = hotkey_state;
    return hotkey_pressed;
}

void TraceManager::CheckContinueCaptureForWriteMode()
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
                trim_enabled_  = false;
                capture_mode_  = kModeDisabled;
                state_tracker_ = nullptr;
                compressor_    = nullptr;
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
        DeactivateTrimming();
        GFXRECON_LOG_INFO("Finished recording graphics API capture");
    }
}

void TraceManager::CheckStartCaptureForTrackMode()
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

void TraceManager::EndFrame()
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

std::string TraceManager::CreateTrimFilename(const std::string&                base_filename,
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

bool TraceManager::CreateCaptureFile(const std::string& base_filename)
{
    auto state_lock = AcquireUniqueStateLock();

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

void TraceManager::ActivateTrimming()
{
    auto state_lock = AcquireUniqueStateLock();

    capture_mode_ |= kModeWrite;

    auto thread_data = GetThreadData();
    assert(thread_data != nullptr);

    VulkanStateWriter state_writer(file_stream_.get(), compressor_.get(), thread_data->thread_id_);
    state_tracker_->WriteState(&state_writer, current_frame_);
}

void TraceManager::DeactivateTrimming()
{
    auto state_lock = AcquireUniqueStateLock();

    capture_mode_ &= ~kModeWrite;
    file_stream_ = nullptr;
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

    CombineAndWriteToFile({ { &file_header, sizeof(file_header) },
                            { option_list.data(), option_list.size() * sizeof(format::FileOptionPair) } });
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
        message_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(message_cmd) + message_length;
        message_cmd.meta_header.meta_data_type    = format::MetaDataType::kDisplayMessageCommand;
        message_cmd.thread_id                     = GetThreadData()->thread_id_;

        CombineAndWriteToFile({ { &message_cmd, sizeof(message_cmd) }, { message, message_length } });
    }
}

void TraceManager::WriteResizeWindowCmd(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        format::ResizeWindowCommand resize_cmd;
        resize_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        resize_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(resize_cmd);
        resize_cmd.meta_header.meta_data_type    = format::MetaDataType::kResizeWindowCommand;
        resize_cmd.thread_id                     = GetThreadData()->thread_id_;

        resize_cmd.surface_id = surface_id;
        resize_cmd.width      = width;
        resize_cmd.height     = height;

        WriteToFile(&resize_cmd, sizeof(resize_cmd));
    }
}

void TraceManager::WriteResizeWindowCmd2(format::HandleId              surface_id,
                                         uint32_t                      width,
                                         uint32_t                      height,
                                         VkSurfaceTransformFlagBitsKHR pre_transform)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        format::ResizeWindowCommand2 resize_cmd2;
        resize_cmd2.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        resize_cmd2.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(resize_cmd2);
        resize_cmd2.meta_header.meta_data_type    = format::MetaDataType::kResizeWindowCommand2;
        resize_cmd2.thread_id                     = GetThreadData()->thread_id_;

        resize_cmd2.surface_id = surface_id;
        resize_cmd2.width      = width;
        resize_cmd2.height     = height;

        switch (pre_transform)
        {
            default:
            case VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR:
            case VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform0;
                break;
            case VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform90;
                break;
            case VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform180;
                break;
            case VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform270;
                break;
        }

        WriteToFile(&resize_cmd2, sizeof(resize_cmd2));
    }
}

void TraceManager::WriteFillMemoryCmd(format::HandleId memory_id,
                                      VkDeviceSize     offset,
                                      VkDeviceSize     size,
                                      const void*      data)
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
        fill_cmd.meta_header.meta_data_type    = format::MetaDataType::kFillMemoryCommand;
        fill_cmd.thread_id                     = thread_data->thread_id_;
        fill_cmd.memory_id                     = memory_id;
        fill_cmd.memory_offset                 = offset;
        fill_cmd.memory_size                   = size;

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

void TraceManager::WriteCreateHardwareBufferCmd(format::HandleId                                    memory_id,
                                                AHardwareBuffer*                                    buffer,
                                                const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        assert(buffer != nullptr);

        format::CreateHardwareBufferCommandHeader create_buffer_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        create_buffer_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        create_buffer_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(create_buffer_cmd);
        create_buffer_cmd.meta_header.meta_data_type    = format::MetaDataType::kCreateHardwareBufferCommand;
        create_buffer_cmd.thread_id                     = thread_data->thread_id_;
        create_buffer_cmd.memory_id                     = memory_id;
        create_buffer_cmd.buffer_id                     = reinterpret_cast<uint64_t>(buffer);

        // Get AHB description data.
        AHardwareBuffer_Desc ahb_desc = {};
        AHardwareBuffer_describe(buffer, &ahb_desc);

        create_buffer_cmd.format = ahb_desc.format;
        create_buffer_cmd.width  = ahb_desc.width;
        create_buffer_cmd.height = ahb_desc.height;
        create_buffer_cmd.stride = ahb_desc.stride;
        create_buffer_cmd.usage  = ahb_desc.usage;
        create_buffer_cmd.layers = ahb_desc.layers;

        size_t planes_size = 0;

        if (plane_info.empty())
        {
            create_buffer_cmd.planes = 0;
        }
        else
        {
            create_buffer_cmd.planes = static_cast<uint32_t>(plane_info.size());
            // Update size of packet with size of plane info.
            planes_size = sizeof(plane_info[0]) * plane_info.size();
            create_buffer_cmd.meta_header.block_header.size += planes_size;
        }

        {
            if (planes_size > 0)
            {
                CombineAndWriteToFile(
                    { { &create_buffer_cmd, sizeof(create_buffer_cmd) }, { plane_info.data(), planes_size } });
            }
            else
            {
                WriteToFile(&create_buffer_cmd, sizeof(create_buffer_cmd));
            }
        }
#else
        GFXRECON_UNREFERENCED_PARAMETER(memory_id);
        GFXRECON_UNREFERENCED_PARAMETER(buffer);
        GFXRECON_UNREFERENCED_PARAMETER(plane_info);

        GFXRECON_LOG_ERROR("Skipping create AHardwareBuffer command write for unsupported platform");
#endif
    }
}

void TraceManager::WriteDestroyHardwareBufferCmd(AHardwareBuffer* buffer)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        assert(buffer != nullptr);

        format::DestroyHardwareBufferCommand destroy_buffer_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        destroy_buffer_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        destroy_buffer_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(destroy_buffer_cmd);
        destroy_buffer_cmd.meta_header.meta_data_type    = format::MetaDataType::kDestroyHardwareBufferCommand;
        destroy_buffer_cmd.thread_id                     = thread_data->thread_id_;
        destroy_buffer_cmd.buffer_id                     = reinterpret_cast<uint64_t>(buffer);

        WriteToFile(&destroy_buffer_cmd, sizeof(destroy_buffer_cmd));
#else
        GFXRECON_LOG_ERROR("Skipping destroy AHardwareBuffer command write for unsupported platform");
#endif
    }
}

void TraceManager::WriteSetDevicePropertiesCommand(format::HandleId                  physical_device_id,
                                                   const VkPhysicalDeviceProperties& properties)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        format::SetDevicePropertiesCommand properties_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        uint32_t device_name_len = static_cast<uint32_t>(util::platform::StringLength(properties.deviceName));

        properties_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        properties_cmd.meta_header.block_header.size =
            format::GetMetaDataBlockBaseSize(properties_cmd) + device_name_len;
        properties_cmd.meta_header.meta_data_type = format::MetaDataType::kSetDevicePropertiesCommand;
        properties_cmd.thread_id                  = thread_data->thread_id_;
        properties_cmd.physical_device_id         = physical_device_id;
        properties_cmd.api_version                = properties.apiVersion;
        properties_cmd.driver_version             = properties.driverVersion;
        properties_cmd.vendor_id                  = properties.vendorID;
        properties_cmd.device_id                  = properties.deviceID;
        properties_cmd.device_type                = properties.deviceType;
        util::platform::MemoryCopy(
            properties_cmd.pipeline_cache_uuid, format::kUuidSize, properties.pipelineCacheUUID, VK_UUID_SIZE);
        properties_cmd.device_name_len = device_name_len;

        CombineAndWriteToFile(
            { { &properties_cmd, sizeof(properties_cmd) }, { properties.deviceName, properties_cmd.device_name_len } });
    }
}

void TraceManager::WriteSetDeviceMemoryPropertiesCommand(format::HandleId                        physical_device_id,
                                                         const VkPhysicalDeviceMemoryProperties& memory_properties)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        format::SetDeviceMemoryPropertiesCommand memory_properties_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        memory_properties_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        memory_properties_cmd.meta_header.block_header.size =
            format::GetMetaDataBlockBaseSize(memory_properties_cmd) +
            (sizeof(format::DeviceMemoryType) * memory_properties.memoryTypeCount) +
            (sizeof(format::DeviceMemoryHeap) * memory_properties.memoryHeapCount);
        memory_properties_cmd.meta_header.meta_data_type = format::MetaDataType::kSetDeviceMemoryPropertiesCommand;
        memory_properties_cmd.thread_id                  = thread_data->thread_id_;
        memory_properties_cmd.physical_device_id         = physical_device_id;
        memory_properties_cmd.memory_type_count          = memory_properties.memoryTypeCount;
        memory_properties_cmd.memory_heap_count          = memory_properties.memoryHeapCount;

        // Since the number of file writes below is dynamic, CombineAndWriteToFile is not suitable. Instead, manually
        // populate thread_data's scratch_buffer_ then write to file.
        auto& scratch_buffer = thread_data->GetScratchBuffer();
        scratch_buffer.clear();
        scratch_buffer.insert(scratch_buffer.end(),
                              reinterpret_cast<uint8_t*>(&memory_properties_cmd),
                              reinterpret_cast<uint8_t*>(&memory_properties_cmd) + sizeof(memory_properties_cmd));

        format::DeviceMemoryType type;
        for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
        {
            type.property_flags = memory_properties.memoryTypes[i].propertyFlags;
            type.heap_index     = memory_properties.memoryTypes[i].heapIndex;

            scratch_buffer.insert(scratch_buffer.end(),
                                  reinterpret_cast<uint8_t*>(&type),
                                  reinterpret_cast<uint8_t*>(&type) + sizeof(type));
        }

        format::DeviceMemoryHeap heap;
        for (uint32_t i = 0; i < memory_properties.memoryHeapCount; ++i)
        {
            heap.size  = memory_properties.memoryHeaps[i].size;
            heap.flags = memory_properties.memoryHeaps[i].flags;

            scratch_buffer.insert(scratch_buffer.end(),
                                  reinterpret_cast<uint8_t*>(&heap),
                                  reinterpret_cast<uint8_t*>(&heap) + sizeof(heap));
        }

        WriteToFile(scratch_buffer.data(), scratch_buffer.size());
    }
}

void TraceManager::WriteSetOpaqueAddressCommand(format::HandleId device_id,
                                                format::HandleId object_id,
                                                uint64_t         address)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        format::SetOpaqueAddressCommand opaque_address_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        opaque_address_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        opaque_address_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(opaque_address_cmd);
        opaque_address_cmd.meta_header.meta_data_type    = format::MetaDataType::kSetOpaqueAddressCommand;
        opaque_address_cmd.thread_id                     = thread_data->thread_id_;
        opaque_address_cmd.device_id                     = device_id;
        opaque_address_cmd.object_id                     = object_id;
        opaque_address_cmd.address                       = address;

        WriteToFile(&opaque_address_cmd, sizeof(opaque_address_cmd));
    }
}

void TraceManager::WriteSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                               format::HandleId pipeline_id,
                                                               size_t           data_size,
                                                               const void*      data)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        format::SetRayTracingShaderGroupHandlesCommandHeader set_handles_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        set_handles_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        set_handles_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(set_handles_cmd) + data_size;
        set_handles_cmd.meta_header.meta_data_type    = format::MetaDataType::kSetRayTracingShaderGroupHandlesCommand;
        set_handles_cmd.thread_id                     = thread_data->thread_id_;
        set_handles_cmd.device_id                     = device_id;
        set_handles_cmd.pipeline_id                   = pipeline_id;
        set_handles_cmd.data_size                     = data_size;

        CombineAndWriteToFile({ { &set_handles_cmd, sizeof(set_handles_cmd) }, { data, data_size } });
    }
}

void TraceManager::SetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate                  update_template,
                                                   const VkDescriptorUpdateTemplateCreateInfo* create_info)
{
    // A NULL check should have been performed by the caller.
    assert((create_info != nullptr));

    if (create_info->descriptorUpdateEntryCount > 0)
    {
        DescriptorUpdateTemplateWrapper* wrapper = reinterpret_cast<DescriptorUpdateTemplateWrapper*>(update_template);
        UpdateTemplateInfo*              info    = &wrapper->info;

        for (size_t i = 0; i < create_info->descriptorUpdateEntryCount; ++i)
        {
            const VkDescriptorUpdateTemplateEntry* entry      = &create_info->pDescriptorUpdateEntries[i];
            VkDescriptorType                       type       = entry->descriptorType;
            size_t                                 entry_size = 0;

            // Sort the descriptor update template info by type, so it can be written to the capture file
            // as tightly packed arrays of structures.  One array will be written for each descriptor info
            // structure/textel buffer view.
            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                UpdateTemplateEntryInfo image_info;
                image_info.binding       = entry->dstBinding;
                image_info.array_element = entry->dstArrayElement;
                image_info.count         = entry->descriptorCount;
                image_info.offset        = entry->offset;
                image_info.stride        = entry->stride;
                image_info.type          = type;

                info->image_info_count += entry->descriptorCount;
                info->image_info.emplace_back(image_info);

                entry_size = sizeof(VkDescriptorImageInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                UpdateTemplateEntryInfo buffer_info;
                buffer_info.binding       = entry->dstBinding;
                buffer_info.array_element = entry->dstArrayElement;
                buffer_info.count         = entry->descriptorCount;
                buffer_info.offset        = entry->offset;
                buffer_info.stride        = entry->stride;
                buffer_info.type          = type;

                info->buffer_info_count += entry->descriptorCount;
                info->buffer_info.emplace_back(buffer_info);

                entry_size = sizeof(VkDescriptorBufferInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                UpdateTemplateEntryInfo texel_buffer_view_info;
                texel_buffer_view_info.binding       = entry->dstBinding;
                texel_buffer_view_info.array_element = entry->dstArrayElement;
                texel_buffer_view_info.count         = entry->descriptorCount;
                texel_buffer_view_info.offset        = entry->offset;
                texel_buffer_view_info.stride        = entry->stride;
                texel_buffer_view_info.type          = type;

                info->texel_buffer_view_count += entry->descriptorCount;
                info->texel_buffer_view.emplace_back(texel_buffer_view_info);

                entry_size = sizeof(VkBufferView);
            }
            else if (type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                UpdateTemplateEntryInfo accel_struct_info;
                accel_struct_info.binding       = entry->dstBinding;
                accel_struct_info.array_element = entry->dstArrayElement;
                accel_struct_info.count         = entry->descriptorCount;
                accel_struct_info.offset        = entry->offset;
                accel_struct_info.stride        = entry->stride;
                accel_struct_info.type          = type;

                info->acceleration_structure_khr_count += entry->descriptorCount;
                info->acceleration_structure_khr.emplace_back(accel_struct_info);

                entry_size = sizeof(VkAccelerationStructureKHR);
            }
            else
            {
                GFXRECON_LOG_ERROR("Unrecognized/unsupported descriptor type in descriptor update template.");
                assert(false);
            }

            if (entry->descriptorCount > 0)
            {
                size_t max_size = ((entry->descriptorCount - 1) * entry->stride) + entry->offset + entry_size;
                if (max_size > info->max_size)
                {
                    info->max_size = max_size;
                }
            }
        }
    }
}

bool TraceManager::GetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate update_template,
                                                   const UpdateTemplateInfo** info) const
{
    assert(info != nullptr);

    bool found = false;

    if (update_template != VK_NULL_HANDLE)
    {
        DescriptorUpdateTemplateWrapper* wrapper = reinterpret_cast<DescriptorUpdateTemplateWrapper*>(update_template);

        (*info) = &wrapper->info;
        found   = true;
    }

    return found;
}

void TraceManager::TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet            set,
                                                        VkDescriptorUpdateTemplate update_template,
                                                        const void*                data)
{
    const UpdateTemplateInfo* info = nullptr;
    if (GetDescriptorUpdateTemplateInfo(update_template, &info))
    {
        assert(state_tracker_ != nullptr);
        state_tracker_->TrackUpdateDescriptorSetWithTemplate(set, info, data);
    }
}

VkResult TraceManager::OverrideCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator,
                                              VkInstance*                  pInstance)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (CreateInstance())
    {
        if (instance_->page_guard_memory_mode_ == kMemoryModeExternal)
        {
            assert(pCreateInfo != nullptr);

            VkInstanceCreateInfo create_info_copy = (*pCreateInfo);

            // TODO: Only enable KHR_get_physical_device_properties_2 for 1.0 API version.
            size_t                   extension_count = create_info_copy.enabledExtensionCount;
            const char* const*       extensions      = create_info_copy.ppEnabledExtensionNames;
            std::vector<const char*> modified_extensions;

            bool has_dev_prop2 = false;

            for (size_t i = 0; i < extension_count; ++i)
            {
                auto entry = extensions[i];

                modified_extensions.push_back(entry);

                if (util::platform::StringCompare(entry, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) == 0)
                {
                    has_dev_prop2 = true;
                }
            }

            if (!has_dev_prop2)
            {
                modified_extensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
            }

            create_info_copy.enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
            create_info_copy.ppEnabledExtensionNames = modified_extensions.data();

            result = layer_table_.CreateInstance(&create_info_copy, pAllocator, pInstance);
        }
        else
        {
            result = layer_table_.CreateInstance(pCreateInfo, pAllocator, pInstance);
        }
    }

    if ((result == VK_SUCCESS) && (pCreateInfo->pApplicationInfo != nullptr))
    {
        auto api_version              = pCreateInfo->pApplicationInfo->apiVersion;
        auto instance_wrapper         = reinterpret_cast<InstanceWrapper*>(*pInstance);
        instance_wrapper->api_version = api_version;

        // Warn when enabled API version is newer than the supported API version.
        if (api_version > VK_HEADER_VERSION_COMPLETE)
        {
            GFXRECON_LOG_WARNING(
                "The application has specified that it uses Vulkan API version %u.%u.%u, which is newer than the "
                "version supported by GFXReconstruct.  Use of unsupported Vulkan features may cause capture or replay "
                "to fail.",
                VK_VERSION_MAJOR(api_version),
                VK_VERSION_MINOR(api_version),
                VK_VERSION_PATCH(api_version));
        }
    }

    return result;
}

VkResult TraceManager::OverrideCreateDevice(VkPhysicalDevice             physicalDevice,
                                            const VkDeviceCreateInfo*    pCreateInfo,
                                            const VkAllocationCallbacks* pAllocator,
                                            VkDevice*                    pDevice)
{
    auto                handle_unwrap_memory     = TraceManager::Get()->GetHandleUnwrapMemory();
    VkPhysicalDevice    physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDeviceCreateInfo* pCreateInfo_unwrapped =
        const_cast<VkDeviceCreateInfo*>(UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory));

    assert(pCreateInfo_unwrapped != nullptr);

    const InstanceTable* instance_table          = GetInstanceTable(physicalDevice);
    auto                 physical_device_wrapper = reinterpret_cast<PhysicalDeviceWrapper*>(physicalDevice);

    graphics::VulkanDeviceUtil                device_util;
    graphics::VulkanDevicePropertyFeatureInfo property_feature_info = device_util.EnableRequiredPhysicalDeviceFeatures(
        physical_device_wrapper->instance_api_version, instance_table, physicalDevice_unwrapped, pCreateInfo_unwrapped);

    // TODO: Only enable KHR_external_memory_capabilities for 1.0 API version.
    size_t                   extension_count = pCreateInfo_unwrapped->enabledExtensionCount;
    const char* const*       extensions      = pCreateInfo_unwrapped->ppEnabledExtensionNames;
    std::vector<const char*> modified_extensions;

    bool has_ext_mem_caps = false;
    bool has_ext_mem      = false;
    bool has_ext_mem_host = false;

    for (size_t i = 0; i < extension_count; ++i)
    {
        auto entry = pCreateInfo_unwrapped->ppEnabledExtensionNames[i];

        modified_extensions.push_back(entry);

        if (page_guard_memory_mode_ == kMemoryModeExternal)
        {
            if (util::platform::StringCompare(entry, VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME) == 0)
            {
                has_ext_mem_caps = true;
            }
            else if (util::platform::StringCompare(entry, VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME) == 0)
            {
                has_ext_mem = true;
            }
            else if (util::platform::StringCompare(entry, VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME) == 0)
            {
                has_ext_mem_host = true;
            }
        }
    }

    if (page_guard_memory_mode_ == kMemoryModeExternal)
    {
        if (!has_ext_mem_caps)
        {
            modified_extensions.push_back(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME);
        }

        if (!has_ext_mem)
        {
            modified_extensions.push_back(VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME);
        }

        if (!has_ext_mem_host)
        {
            modified_extensions.push_back(VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME);
        }
    }

    pCreateInfo_unwrapped->enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
    pCreateInfo_unwrapped->ppEnabledExtensionNames = modified_extensions.data();

    VkResult result = layer_table_.CreateDevice(physicalDevice_unwrapped, pCreateInfo_unwrapped, pAllocator, pDevice);

    if (result == VK_SUCCESS)
    {
        assert((pDevice != nullptr) && (*pDevice != VK_NULL_HANDLE));

        auto wrapper = reinterpret_cast<DeviceWrapper*>(*pDevice);

        // Track state of physical device properties and features at device creation
        wrapper->property_feature_info = property_feature_info;

        if ((capture_mode_ & kModeTrack) != kModeTrack)
        {
            // The state tracker will set this value when it is enabled. When state tracking is disabled it is set here
            // to ensure it is available.
            wrapper->physical_device = physical_device_wrapper;
        }
    }

    // Restore modified property/feature create info values to the original application values
    device_util.RestoreModifiedPhysicalDeviceFeatures();

    return result;
}

VkResult TraceManager::OverrideCreateBuffer(VkDevice                     device,
                                            const VkBufferCreateInfo*    pCreateInfo,
                                            const VkAllocationCallbacks* pAllocator,
                                            VkBuffer*                    pBuffer)
{
    VkResult result           = VK_SUCCESS;
    auto     device_wrapper   = reinterpret_cast<DeviceWrapper*>(device);
    VkDevice device_unwrapped = device_wrapper->handle;
    auto     device_table     = GetDeviceTable(device);

    bool                uses_address         = false;
    VkBufferCreateFlags address_create_flags = 0;
    VkBufferUsageFlags  address_usage_flags  = 0;
    if (device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        if ((pCreateInfo->usage & VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT) ==
            VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT)
        {
            uses_address = true;
            address_create_flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
        }
        if ((pCreateInfo->usage & VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR) ==
            VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR)
        {
            uses_address = true;
            address_create_flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
            address_usage_flags |= VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT;
        }
    }

    // NOTE: VkBufferCreateInfo does not currently support pNext structures with handles, so does not have a handle
    // unwrapping function.  If a pNext struct with handles is added in the future, it will be necessary to unwrap
    // pCreateInfo before calling CreateBuffer.  The unwrapping process will create a mutable copy of the original
    // pCreateInfo, with unwrapped handles, which can be modified directly and would not require the
    // 'modified_create_info' copy performed below.
    if (uses_address && (((pCreateInfo->flags & address_create_flags) != address_create_flags) ||
                         ((pCreateInfo->usage & address_usage_flags) != address_usage_flags)))
    {
        // If the buffer has shader device address usage, but the device address capture replay flag was not set, it
        // needs to be set here.  We create copy from an override to prevent the modified pCreateInfo from being
        // written to the capture file.
        VkBufferCreateInfo modified_create_info = (*pCreateInfo);
        modified_create_info.flags |= address_create_flags;
        modified_create_info.usage |= address_usage_flags;

        result = device_table->CreateBuffer(device_unwrapped, &modified_create_info, pAllocator, pBuffer);
    }
    else
    {
        result = device_table->CreateBuffer(device_unwrapped, pCreateInfo, pAllocator, pBuffer);
    }

    if ((result == VK_SUCCESS) && (pBuffer != nullptr))
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, BufferWrapper>(
            device, NoParentWrapper::kHandleValue, pBuffer, TraceManager::GetUniqueId);

        if (uses_address)
        {
            // If the buffer has a device address, write the 'set buffer address' command before writing the API call to
            // create the buffer.  The address will need to be passed to vkCreateBuffer through the pCreateInfo pNext
            // list.
            auto                      buffer_wrapper = reinterpret_cast<BufferWrapper*>(*pBuffer);
            VkBufferDeviceAddressInfo info           = { VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO };
            info.pNext                               = nullptr;
            info.buffer                              = buffer_wrapper->handle;
            uint64_t address                         = 0;

            if (device_wrapper->physical_device->instance_api_version >= VK_MAKE_VERSION(1, 2, 0))
            {
                address = device_table->GetBufferOpaqueCaptureAddress(device_unwrapped, &info);
            }
            else
            {
                address = device_table->GetBufferOpaqueCaptureAddressKHR(device_unwrapped, &info);
            }

            WriteSetOpaqueAddressCommand(device_wrapper->handle_id, buffer_wrapper->handle_id, address);

            if ((capture_mode_ & kModeTrack) == kModeTrack)
            {
                state_tracker_->TrackBufferDeviceAddress(device, *pBuffer, address);
            }
        }
    }

    return result;
}

VkResult TraceManager::OverrideCreateAccelerationStructureKHR(VkDevice                                    device,
                                                              const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
                                                              const VkAllocationCallbacks*                pAllocator,
                                                              VkAccelerationStructureKHR* pAccelerationStructureKHR)
{
    auto                                        handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    auto                                        device_wrapper       = reinterpret_cast<DeviceWrapper*>(device);
    VkDevice                                    device_unwrapped     = device_wrapper->handle;
    const DeviceTable*                          device_table         = GetDeviceTable(device);
    const VkAccelerationStructureCreateInfoKHR* pCreateInfo_unwrapped =
        UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result;
    if (device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        // Add flag to allow for opaque address capture
        VkAccelerationStructureCreateInfoKHR modified_create_info = (*pCreateInfo_unwrapped);
        modified_create_info.createFlags |= VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR;
        result = device_table->CreateAccelerationStructureKHR(
            device_unwrapped, &modified_create_info, pAllocator, pAccelerationStructureKHR);
    }
    else
    {
        result = device_table->CreateAccelerationStructureKHR(
            device_unwrapped, pCreateInfo_unwrapped, pAllocator, pAccelerationStructureKHR);
    }

    if ((result == VK_SUCCESS) && (pAccelerationStructureKHR != nullptr))
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, AccelerationStructureKHRWrapper>(
            device, NoParentWrapper::kHandleValue, pAccelerationStructureKHR, TraceManager::GetUniqueId);

        if (device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
        {
            AccelerationStructureKHRWrapper* accel_struct_wrapper =
                reinterpret_cast<AccelerationStructureKHRWrapper*>(*pAccelerationStructureKHR);

            VkAccelerationStructureDeviceAddressInfoKHR address_info{
                VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR, nullptr, accel_struct_wrapper->handle
            };

            // save address to use as pCreateInfo->deviceAddress during replay
            VkDeviceAddress address =
                device_table->GetAccelerationStructureDeviceAddressKHR(device_unwrapped, &address_info);

            WriteSetOpaqueAddressCommand(device_wrapper->handle_id, accel_struct_wrapper->handle_id, address);

            if ((capture_mode_ & kModeTrack) == kModeTrack)
            {
                state_tracker_->TrackAccelerationStructureKHRDeviceAddress(device, *pAccelerationStructureKHR, address);
            }
        }
    }

    return result;
}

VkResult TraceManager::OverrideAllocateMemory(VkDevice                     device,
                                              const VkMemoryAllocateInfo*  pAllocateInfo,
                                              const VkAllocationCallbacks* pAllocator,
                                              VkDeviceMemory*              pMemory)
{
    VkResult                         result          = VK_SUCCESS;
    void*                            external_memory = nullptr;
    VkImportMemoryHostPointerInfoEXT import_info;

    auto                  device_wrapper       = reinterpret_cast<DeviceWrapper*>(device);
    VkDevice              device_unwrapped     = device_wrapper->handle;
    auto                  handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkMemoryAllocateInfo* pAllocateInfo_unwrapped =
        const_cast<VkMemoryAllocateInfo*>(UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory));

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    const VkImportAndroidHardwareBufferInfoANDROID* import_ahb_info =
        FindAllocateMemoryExtensions(pAllocateInfo_unwrapped);
#endif

    bool                   uses_address         = false;
    VkMemoryAllocateFlags* modified_alloc_flags = nullptr;
    VkMemoryAllocateFlags  incoming_alloc_flags;
    if (device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        VkBaseOutStructure* current_struct = reinterpret_cast<VkBaseOutStructure*>(pAllocateInfo_unwrapped)->pNext;
        while (current_struct != nullptr)
        {
            if (current_struct->sType == VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO)
            {
                auto alloc_flags_info = reinterpret_cast<VkMemoryAllocateFlagsInfo*>(current_struct);
                if ((alloc_flags_info->flags & VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT) ==
                    VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT)
                {
                    uses_address         = true;
                    incoming_alloc_flags = alloc_flags_info->flags;
                    alloc_flags_info->flags |= VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
                    modified_alloc_flags = &(alloc_flags_info->flags);
                }
                break;
            }
            current_struct = current_struct->pNext;
        }
    }

    if (page_guard_memory_mode_ == kMemoryModeExternal)
    {
        VkMemoryPropertyFlags properties = GetMemoryProperties(device_wrapper, pAllocateInfo->memoryTypeIndex);

        if ((properties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
        {
            // Use the external memory extension to provide a memory allocation that can be watched directly by the page
            // guard implementation.
            assert(pAllocateInfo_unwrapped != nullptr);

            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pAllocateInfo_unwrapped->allocationSize);

            // TODO: This should be aligned to minImportedHostPointerAlignment, but there is a currently a loader bug
            // that prevents the layer from querying for that value when a 1.0 application does not explicitly enable
            // physical_device_properties2.  For now we align to system page size.
            size_t external_memory_size =
                manager->GetAlignedSize(static_cast<size_t>(pAllocateInfo_unwrapped->allocationSize));
            external_memory = manager->AllocateMemory(external_memory_size, true);

            if (external_memory != nullptr)
            {
                pAllocateInfo_unwrapped->allocationSize = external_memory_size;

                import_info.sType        = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT;
                import_info.pNext        = nullptr;
                import_info.handleType   = VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT;
                import_info.pHostPointer = external_memory;

                // TODO: Check pNext chain for use of incompatible extension types.
                VkBaseOutStructure* end = reinterpret_cast<VkBaseOutStructure*>(pAllocateInfo_unwrapped);
                while (end->pNext != nullptr)
                {
                    end = end->pNext;
                }

                end->pNext = reinterpret_cast<VkBaseOutStructure*>(&import_info);
            }
        }
    }

    result = GetDeviceTable(device)->AllocateMemory(device_unwrapped, pAllocateInfo_unwrapped, pAllocator, pMemory);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DeviceMemoryWrapper>(
            device, NoParentWrapper::kHandleValue, pMemory, TraceManager::GetUniqueId);

        assert(pMemory != nullptr);
        auto memory_wrapper = reinterpret_cast<DeviceMemoryWrapper*>(*pMemory);

        if (uses_address)
        {
            // Restore modified allocation flags
            assert(modified_alloc_flags != nullptr);
            *modified_alloc_flags = incoming_alloc_flags;

            VkDeviceMemoryOpaqueCaptureAddressInfo info{ VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO,
                                                         nullptr,
                                                         memory_wrapper->handle };

            uint64_t address = 0;
            if (device_wrapper->physical_device->instance_api_version >= VK_MAKE_VERSION(1, 2, 0))
            {
                address = GetDeviceTable(device)->GetDeviceMemoryOpaqueCaptureAddress(device_unwrapped, &info);
            }
            else
            {
                address = GetDeviceTable(device)->GetDeviceMemoryOpaqueCaptureAddressKHR(device_unwrapped, &info);
            }

            WriteSetOpaqueAddressCommand(device_wrapper->handle_id, memory_wrapper->handle_id, address);

            if ((capture_mode_ & kModeTrack) == kModeTrack)
            {
                state_tracker_->TrackDeviceMemoryDeviceAddress(device, *pMemory, address);
            }
        }

        memory_wrapper->external_allocation = external_memory;

        if ((capture_mode_ & kModeTrack) != kModeTrack)
        {
            // The state tracker will set this value when it is enabled. When state tracking is disabled it is set
            // here to ensure it is available for mapped memory tracking.
            memory_wrapper->allocation_size = pAllocateInfo->allocationSize;
        }

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        if ((import_ahb_info != nullptr) && (import_ahb_info->buffer != nullptr))
        {
            ProcessImportAndroidHardwareBuffer(device, *pMemory, import_ahb_info->buffer);
        }
#endif
    }
    else if (external_memory != nullptr)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        size_t external_memory_size = manager->GetAlignedSize(static_cast<size_t>(pAllocateInfo->allocationSize));
        manager->FreeMemory(external_memory, external_memory_size);
    }

    return result;
}

VkResult TraceManager::OverrideGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice                   physicalDevice,
                                                                  uint32_t*                          pToolCount,
                                                                  VkPhysicalDeviceToolPropertiesEXT* pToolProperties)
{
    auto original_pToolProperties = pToolProperties;
    if (pToolProperties != nullptr)
    {
        pToolProperties->sType    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT;
        pToolProperties->pNext    = nullptr;
        pToolProperties->purposes = VK_TOOL_PURPOSE_TRACING_BIT_EXT;

        util::platform::StringCopy(pToolProperties->name,
                                   VK_MAX_EXTENSION_NAME_SIZE,
                                   GFXRECON_PROJECT_NAME,
                                   util::platform::StringLength(GFXRECON_PROJECT_NAME));

        util::platform::StringCopy(pToolProperties->version,
                                   VK_MAX_EXTENSION_NAME_SIZE,
                                   GFXRECON_PROJECT_VERSION_STRING,
                                   util::platform::StringLength(GFXRECON_PROJECT_VERSION_STRING));

        util::platform::StringCopy(pToolProperties->description,
                                   VK_MAX_DESCRIPTION_SIZE,
                                   GFXRECON_PROJECT_DESCRIPTION,
                                   util::platform::StringLength(GFXRECON_PROJECT_DESCRIPTION));

        util::platform::StringCopy(pToolProperties->layer,
                                   VK_MAX_EXTENSION_NAME_SIZE,
                                   GFXRECON_PROJECT_LAYER_NAME,
                                   util::platform::StringLength(GFXRECON_PROJECT_LAYER_NAME));

        if (pToolCount != nullptr)
        {
            pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
            --(*pToolCount);
        }
    }

    auto physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)
                          ->GetPhysicalDeviceToolPropertiesEXT(physicalDevice_unwrapped, pToolCount, pToolProperties);

    if (original_pToolProperties != nullptr)
    {
        pToolProperties = original_pToolProperties;
    }

    if (pToolCount != nullptr)
    {
        ++(*pToolCount);
    }

    return result;
}

VkResult TraceManager::OverrideCreateRayTracingPipelinesKHR(VkDevice                                 device,
                                                            VkDeferredOperationKHR                   deferredOperation,
                                                            VkPipelineCache                          pipelineCache,
                                                            uint32_t                                 createInfoCount,
                                                            const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                                            const VkAllocationCallbacks*             pAllocator,
                                                            VkPipeline*                              pPipelines)
{
    std::unique_ptr<DeferredOperationCreateRayTracingPipelines>&& deferred_operation_instance =
        std::make_unique<DeferredOperationCreateRayTracingPipelines>(
            device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    auto                   device_wrapper              = reinterpret_cast<DeviceWrapper*>(device);
    VkDevice               device_unwrapped            = device_wrapper->handle;
    const DeviceTable*     device_table                = GetDeviceTable(device);
    HandleUnwrapMemory&    handle_unwrap_memory        = deferred_operation_instance->GetHandleUnwrapMemory();
    VkDeferredOperationKHR deferredOperation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(deferredOperation);
    VkPipelineCache        pipelineCache_unwrapped     = GetWrappedHandle<VkPipelineCache>(pipelineCache);
    const VkRayTracingPipelineCreateInfoKHR*& pCreateInfos_unwrapped =
        deferred_operation_instance->GetCreateInfosUnwrapped();

    pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, &handle_unwrap_memory);

    VkResult result;
    if (device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
    {
        std::unique_ptr<VkRayTracingPipelineCreateInfoKHR[]>& modified_create_infos =
            deferred_operation_instance->GetModifiedCreateInfos();
        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            modified_create_infos[i] = pCreateInfos_unwrapped[i];
            modified_create_infos[i].flags |= VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR;
        }
        result = device_table->CreateRayTracingPipelinesKHR(device_unwrapped,
                                                            deferredOperation_unwrapped,
                                                            pipelineCache_unwrapped,
                                                            createInfoCount,
                                                            modified_create_infos.get(),
                                                            pAllocator,
                                                            pPipelines);
    }
    else
    {
        result = device_table->CreateRayTracingPipelinesKHR(device_unwrapped,
                                                            deferredOperation_unwrapped,
                                                            pipelineCache_unwrapped,
                                                            createInfoCount,
                                                            pCreateInfos_unwrapped,
                                                            pAllocator,
                                                            pPipelines);
    }

    if ((result == VK_SUCCESS) && (pPipelines != nullptr))
    {
        CreateWrappedHandles<DeviceWrapper, DeferredOperationKHRWrapper, PipelineWrapper>(
            device, deferredOperation, pPipelines, createInfoCount, TraceManager::GetUniqueId);

        if (device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
        {
            for (uint32_t i = 0; i < createInfoCount; ++i)
            {
                PipelineWrapper* pipeline_wrapper = reinterpret_cast<PipelineWrapper*>(pPipelines[i]);

                uint32_t data_size = device_wrapper->property_feature_info.property_shaderGroupHandleCaptureReplaySize *
                                     pCreateInfos[i].groupCount;
                std::vector<uint8_t> data(data_size);

                device_table->GetRayTracingCaptureReplayShaderGroupHandlesKHR(
                    device_unwrapped, pipeline_wrapper->handle, 0, pCreateInfos[i].groupCount, data_size, data.data());

                WriteSetRayTracingShaderGroupHandlesCommand(
                    device_wrapper->handle_id, pipeline_wrapper->handle_id, data_size, data.data());

                if ((capture_mode_ & kModeTrack) == kModeTrack)
                {
                    state_tracker_->TrackRayTracingShaderGroupHandles(device, pPipelines[i], data_size, data.data());
                }
            }
        }
    }
    if (deferredOperation != VK_NULL_HANDLE)
    {
        DeferredOperationManager::Get()->add(deferredOperation, std::move(deferred_operation_instance));
    }
    return result;
}

void TraceManager::ProcessEnumeratePhysicalDevices(VkResult          result,
                                                   VkInstance        instance,
                                                   uint32_t          count,
                                                   VkPhysicalDevice* devices)
{
    assert(devices != nullptr);

    auto instance_wrapper = reinterpret_cast<InstanceWrapper*>(instance);
    assert(instance_wrapper != nullptr);

    // Write meta-data describing physical device properties on first call to vkEnumeratePhysicalDevices or
    // vkEnumeratePhysicalDeviceGroups.
    if (!instance_wrapper->have_device_properties)
    {
        // Only filter duplicate checks when we have a complete list of physical devices.
        if (result != VK_INCOMPLETE)
        {
            instance_wrapper->have_device_properties = true;
        }

        for (uint32_t i = 0; i < count; ++i)
        {
            VkPhysicalDevice physical_device = devices[i];

            if (physical_device != VK_NULL_HANDLE)
            {
                const InstanceTable* instance_table = GetInstanceTable(physical_device);
                assert(instance_table != nullptr);

                auto             physical_device_wrapper = reinterpret_cast<PhysicalDeviceWrapper*>(physical_device);
                format::HandleId physical_device_id      = physical_device_wrapper->handle_id;
                VkPhysicalDevice physical_device_handle  = physical_device_wrapper->handle;
                uint32_t         count                   = 0;

                VkPhysicalDeviceProperties       properties;
                VkPhysicalDeviceMemoryProperties memory_properties;

                instance_table->GetPhysicalDeviceProperties(physical_device_handle, &properties);
                instance_table->GetPhysicalDeviceMemoryProperties(physical_device_handle, &memory_properties);

                if ((capture_mode_ & kModeTrack) == kModeTrack)
                {
                    // Let the state tracker process the memory properties.
                    assert(state_tracker_ != nullptr);
                    state_tracker_->TrackPhysicalDeviceMemoryProperties(physical_device, &memory_properties);
                }
                else
                {
                    // When not tracking state, set the memory types directly.
                    physical_device_wrapper->memory_properties = std::move(memory_properties);
                }

                physical_device_wrapper->instance_api_version = instance_wrapper->api_version;

                WriteSetDevicePropertiesCommand(physical_device_id, properties);
                WriteSetDeviceMemoryPropertiesCommand(physical_device_id, physical_device_wrapper->memory_properties);
            }
        }
    }
}

VkMemoryPropertyFlags TraceManager::GetMemoryProperties(DeviceWrapper* device_wrapper, uint32_t memory_type_index)
{
    PhysicalDeviceWrapper*                  physical_device_wrapper = device_wrapper->physical_device;
    const VkPhysicalDeviceMemoryProperties* memory_properties       = &physical_device_wrapper->memory_properties;

    assert(memory_type_index < memory_properties->memoryTypeCount);

    return memory_properties->memoryTypes[memory_type_index].propertyFlags;
}

const VkImportAndroidHardwareBufferInfoANDROID*
TraceManager::FindAllocateMemoryExtensions(const VkMemoryAllocateInfo* allocate_info)
{
    const VkImportAndroidHardwareBufferInfoANDROID* import_ahb_info = nullptr;

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    assert(allocate_info != nullptr);

    const VkBaseInStructure* pnext = reinterpret_cast<const VkBaseInStructure*>(allocate_info->pNext);
    while (pnext != nullptr)
    {
        if (pnext->sType == VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID)
        {
            import_ahb_info = reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(pnext);
            break;
        }

        pnext = pnext->pNext;
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(allocate_info);
#endif

    return import_ahb_info;
}

void TraceManager::ProcessImportAndroidHardwareBuffer(VkDevice         device,
                                                      VkDeviceMemory   memory,
                                                      AHardwareBuffer* hardware_buffer)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    auto memory_wrapper = reinterpret_cast<DeviceMemoryWrapper*>(memory);
    assert((memory_wrapper != nullptr) && (hardware_buffer != nullptr));

    auto entry = hardware_buffers_.find(hardware_buffer);
    if (entry != hardware_buffers_.end())
    {
        ++entry->second.reference_count;
        memory_wrapper->hardware_buffer = hardware_buffer;
    }
    else
    {
        // If this is the first device memory object to reference the hardware buffer, write a buffer creation
        // command to the capture file and setup memory tracking.
        void* data   = nullptr;
        int   result = -1;

        std::vector<format::HardwareBufferPlaneInfo> plane_info;

        // The multi-plane functions are declared for API 26, but are only available to link with API 29.  So, this
        // could be turned into a run-time check dependent on dlsym returning a valid pointer for
        // AHardwareBuffer_lockPlanes.
#if __ANDROID_API__ >= 29
        AHardwareBuffer_Planes ahb_planes;
        result =
            AHardwareBuffer_lockPlanes(hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, nullptr, &ahb_planes);
        if (result == 0)
        {
            data = ahb_planes.planes[0].data;

            for (uint32_t i = 0; i < ahb_planes.planeCount; ++i)
            {
                format::HardwareBufferPlaneInfo ahb_plane_info;
                ahb_plane_info.offset =
                    reinterpret_cast<uint8_t*>(ahb_planes.planes[i].data) - reinterpret_cast<uint8_t*>(data);
                ahb_plane_info.pixel_stride = ahb_planes.planes[i].pixelStride;
                ahb_plane_info.row_pitch    = ahb_planes.planes[i].rowStride;
                plane_info.emplace_back(std::move(ahb_plane_info));
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("AHardwareBuffer_lockPlanes failed: AHardwareBuffer_lock will be used instead");
        }
#endif

        if (result != 0)
        {
            result = AHardwareBuffer_lock(hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, nullptr, &data);
        }

        if (result == 0)
        {
            assert(data != nullptr);

            // Only store buffer IDs and reference count if a creation command is written to the capture file.
            format::HandleId memory_id = GetUniqueId();

            HardwareBufferInfo& ahb_info = hardware_buffers_[hardware_buffer];
            ahb_info.memory_id           = memory_id;
            ahb_info.reference_count     = 1;

            memory_wrapper->hardware_buffer           = hardware_buffer;
            memory_wrapper->hardware_buffer_memory_id = memory_id;

            WriteCreateHardwareBufferCmd(memory_id, hardware_buffer, plane_info);
            WriteFillMemoryCmd(memory_id, 0, memory_wrapper->allocation_size, data);

            if ((memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard) &&
                page_guard_track_ahb_memory_)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, memory_wrapper->allocation_size);

                util::PageGuardManager* manager = util::PageGuardManager::Get();
                assert(manager != nullptr);

                manager->AddTrackedMemory(
                    memory_id,
                    data,
                    0,
                    static_cast<size_t>(memory_wrapper->allocation_size),
                    util::PageGuardManager::kNullShadowHandle,
                    false,  // No shadow memory for the imported AHB memory; Track directly with mprotect().
                    false); // Write watch is not supported for this case.
            }

            result = AHardwareBuffer_unlock(hardware_buffer, nullptr);
            if (result != 0)
            {
                GFXRECON_LOG_ERROR("AHardwareBuffer_unlock failed");
            }
        }
        else
        {
            GFXRECON_LOG_ERROR(
                "AHardwareBuffer_lock failed: hardware buffer data will be omitted from the capture file");
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(memory);
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void TraceManager::ReleaseAndroidHardwareBuffer(AHardwareBuffer* hardware_buffer)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    assert(hardware_buffer != nullptr);

    auto entry = hardware_buffers_.find(hardware_buffer);
    if ((entry != hardware_buffers_.end()) && (--entry->second.reference_count == 0))
    {
        if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            manager->RemoveTrackedMemory(entry->second.memory_id);
        }

        // There are no more references to the buffer, so we can submit a destroy buffer command.
        WriteDestroyHardwareBufferCmd(entry->first);
        hardware_buffers_.erase(entry);
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void TraceManager::PostProcess_vkEnumeratePhysicalDevices(VkResult          result,
                                                          VkInstance        instance,
                                                          uint32_t*         pPhysicalDeviceCount,
                                                          VkPhysicalDevice* pPhysicalDevices)
{
    if ((result >= 0) && (pPhysicalDeviceCount != nullptr) && (pPhysicalDevices != nullptr))
    {
        ProcessEnumeratePhysicalDevices(result, instance, *pPhysicalDeviceCount, pPhysicalDevices);
    }
}

void TraceManager::PostProcess_vkEnumeratePhysicalDeviceGroups(
    VkResult                         result,
    VkInstance                       instance,
    uint32_t*                        pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties)
{
    if ((result >= 0) && (pPhysicalDeviceGroupCount != nullptr) && (pPhysicalDeviceGroupProperties != nullptr))
    {
        std::unordered_set<VkPhysicalDevice> unique_handles;
        uint32_t                             count = *pPhysicalDeviceGroupCount;

        // Build a list of retrieved physical device handles, filtering duplicates.
        for (uint32_t i = 0; i < count; ++i)
        {
            for (uint32_t j = 0; j < pPhysicalDeviceGroupProperties[i].physicalDeviceCount; ++j)
            {
                unique_handles.insert(pPhysicalDeviceGroupProperties[i].physicalDevices[j]);
            }
        }

        std::vector<VkPhysicalDevice> devices(unique_handles.begin(), unique_handles.end());

        ProcessEnumeratePhysicalDevices(result, instance, static_cast<uint32_t>(devices.size()), devices.data());
    }
}

void TraceManager::PreProcess_vkCreateXlibSurfaceKHR(VkInstance                        instance,
                                                     const VkXlibSurfaceCreateInfoKHR* pCreateInfo,
                                                     const VkAllocationCallbacks*      pAllocator,
                                                     VkSurfaceKHR*                     pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);

#if defined(VK_USE_PLATFORM_XLIB_KHR)
    assert(pCreateInfo != nullptr);
    if (pCreateInfo && !trim_key_.empty())
    {
        if (!keyboard_.Initialize(pCreateInfo->dpy))
        {
            GFXRECON_LOG_ERROR("Failed to initialize Xlib keyboard capture trigger");
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    if (!trim_key_.empty())
    {
        GFXRECON_LOG_WARNING("Xlib keyboard capture trigger is not enabled on this system");
    }
#endif
}

void TraceManager::PreProcess_vkCreateXcbSurfaceKHR(VkInstance                       instance,
                                                    const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                                    const VkAllocationCallbacks*     pAllocator,
                                                    VkSurfaceKHR*                    pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);

#if defined(VK_USE_PLATFORM_XCB_KHR)
    assert(pCreateInfo != nullptr);
    if (pCreateInfo && !trim_key_.empty())
    {
        if (!keyboard_.Initialize(pCreateInfo->connection))
        {
            GFXRECON_LOG_ERROR("Failed to initialize XCB keyboard capture trigger");
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    if (!trim_key_.empty())
    {
        GFXRECON_LOG_WARNING("Xcb keyboard capture trigger is not enabled on this system");
    }
#endif
}

void TraceManager::PreProcess_vkCreateWaylandSurfaceKHR(VkInstance                           instance,
                                                        const VkWaylandSurfaceCreateInfoKHR* pCreateInfo,
                                                        const VkAllocationCallbacks*         pAllocator,
                                                        VkSurfaceKHR*                        pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);
    if (!trim_key_.empty())
    {
        GFXRECON_LOG_WARNING("Wayland keyboard capture trigger is not implemented");
    }
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
        WriteResizeWindowCmd2(GetWrappedId(pCreateInfo->surface),
                              pCreateInfo->imageExtent.width,
                              pCreateInfo->imageExtent.height,
                              pCreateInfo->preTransform);
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
    if ((result == VK_SUCCESS) && (ppData != nullptr))
    {
        auto wrapper = reinterpret_cast<DeviceMemoryWrapper*>(memory);
        assert(wrapper != nullptr);

        if (wrapper->mapped_data == nullptr)
        {
            if ((capture_mode_ & kModeTrack) == kModeTrack)
            {
                assert(state_tracker_ != nullptr);
                state_tracker_->TrackMappedMemory(device, memory, (*ppData), offset, size, flags);
            }
            else
            {
                // Perform subset of the state tracking performed by VulkanStateTracker::TrackMappedMemory, only storing
                // values needed for non-tracking capture.
                wrapper->mapped_data   = (*ppData);
                wrapper->mapped_offset = offset;
                wrapper->mapped_size   = size;
            }

            if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
                // Hardware buffer memory is tracked separately, so VkDeviceMemory mappings should be ignored to avoid
                // duplicate memory tracking entries.
                && (wrapper->hardware_buffer == nullptr)
#endif
            )
            {
                if (size == VK_WHOLE_SIZE)
                {
                    assert(offset <= wrapper->allocation_size);
                    size = wrapper->allocation_size - offset;
                }

                if (size > 0)
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, offset);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    bool use_shadow_memory = true;
                    bool use_write_watch   = false;

                    if (page_guard_memory_mode_ == kMemoryModeExternal)
                    {
                        use_shadow_memory = false;
                        use_write_watch   = true;
                    }
                    else if ((page_guard_memory_mode_ == kMemoryModeShadowPersistent) &&
                             (wrapper->shadow_allocation == util::PageGuardManager::kNullShadowHandle))
                    {
                        wrapper->shadow_allocation = manager->AllocatePersistentShadowMemory(static_cast<size_t>(size));
                    }

                    // Return the pointer provided by the pageguard manager, which may be a pointer to shadow memory,
                    // not the mapped memory.
                    (*ppData) = manager->AddTrackedMemory(wrapper->handle_id,
                                                          (*ppData),
                                                          static_cast<size_t>(offset),
                                                          static_cast<size_t>(size),
                                                          wrapper->shadow_allocation,
                                                          use_shadow_memory,
                                                          use_write_watch);
                }
            }
            else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kUnassisted)
            {
                // Need to keep track of mapped memory objects so memory content can be written at queue submit.
                std::lock_guard<std::mutex> lock(mapped_memory_lock_);
                mapped_memory_.insert(wrapper);
            }
        }
        else
        {
            // The application has mapped the same VkDeviceMemory object more than once and the pageguard
            // manager is already tracking it, so we will return the pointer obtained from the pageguard manager
            // on the first map call.
            GFXRECON_LOG_WARNING("VkDeviceMemory object with handle = %" PRIx64 " has been mapped more than once",
                                 memory);

            if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
            {
                assert((wrapper->mapped_offset == offset) && (wrapper->mapped_size == size));

                // Return the shadow memory that was allocated for the previous map operation.
                util::PageGuardManager* manager = util::PageGuardManager::Get();
                assert(manager != nullptr);

                if (!manager->GetTrackedMemory(wrapper->handle_id, ppData))
                {
                    GFXRECON_LOG_ERROR("Modifications to the VkDeviceMemory object that has been mapped more than once "
                                       "are not being track by PageGuardManager");
                }
            }
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
            const DeviceMemoryWrapper* current_memory_wrapper = nullptr;
            util::PageGuardManager*    manager                = util::PageGuardManager::Get();
            assert(manager != nullptr);

            for (uint32_t i = 0; i < memoryRangeCount; ++i)
            {
                auto next_memory_wrapper = reinterpret_cast<const DeviceMemoryWrapper*>(pMemoryRanges[i].memory);

                // Currently processing all dirty pages for the mapped memory, so filter multiple ranges from the same
                // object.
                if (next_memory_wrapper != current_memory_wrapper)
                {
                    current_memory_wrapper = next_memory_wrapper;

                    if ((current_memory_wrapper != nullptr) && (current_memory_wrapper->mapped_data != nullptr))
                    {
                        manager->ProcessMemoryEntry(
                            current_memory_wrapper->handle_id,
                            [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                                WriteFillMemoryCmd(memory_id, offset, size, start_address);
                            });
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING("vkFlushMappedMemoryRanges called for memory that is not mapped");
                    }
                }
            }
        }
        else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kAssisted)
        {
            const DeviceMemoryWrapper* current_memory_wrapper = nullptr;

            for (uint32_t i = 0; i < memoryRangeCount; ++i)
            {
                current_memory_wrapper = reinterpret_cast<const DeviceMemoryWrapper*>(pMemoryRanges[i].memory);

                if ((current_memory_wrapper != nullptr) && (current_memory_wrapper->mapped_data != nullptr))
                {
                    assert(pMemoryRanges[i].offset >= current_memory_wrapper->mapped_offset);

                    // The mapped pointer already includes the mapped offset.  Because the memory range
                    // offset is relative to the start of the memory object, we need to adjust it to be
                    // relative to the start of the mapped pointer.
                    VkDeviceSize relative_offset = pMemoryRanges[i].offset - current_memory_wrapper->mapped_offset;
                    VkDeviceSize size            = pMemoryRanges[i].size;
                    if (size == VK_WHOLE_SIZE)
                    {
                        assert(pMemoryRanges[i].offset <= current_memory_wrapper->allocation_size);
                        size = current_memory_wrapper->allocation_size - pMemoryRanges[i].offset;
                    }

                    WriteFillMemoryCmd(
                        current_memory_wrapper->handle_id, relative_offset, size, current_memory_wrapper->mapped_data);
                }
            }
        }
    }
}

void TraceManager::PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
    auto wrapper = reinterpret_cast<DeviceMemoryWrapper*>(memory);
    assert(wrapper != nullptr);

    if (wrapper->mapped_data != nullptr)
    {
        if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            manager->ProcessMemoryEntry(wrapper->handle_id,
                                        [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                                            WriteFillMemoryCmd(memory_id, offset, size, start_address);
                                        });

            manager->RemoveTrackedMemory(wrapper->handle_id);
        }
        else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kUnassisted)
        {
            VkDeviceSize size = wrapper->mapped_size;
            if (size == VK_WHOLE_SIZE)
            {
                assert(wrapper->mapped_offset <= wrapper->allocation_size);
                size = wrapper->allocation_size - wrapper->mapped_offset;
            }

            // Write the entire mapped region.
            // We set offset to 0, because the pointer returned by vkMapMemory already includes the offset.
            WriteFillMemoryCmd(wrapper->handle_id, 0, size, wrapper->mapped_data);

            {
                std::lock_guard<std::mutex> lock(mapped_memory_lock_);
                mapped_memory_.erase(wrapper);
            }
        }

        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackMappedMemory(device, memory, nullptr, 0, 0, 0);
        }
        else
        {
            // Perform subset of the state tracking performed by VulkanStateTracker::TrackMappedMemory, only storing
            // values needed for non-tracking capture.
            wrapper->mapped_data   = nullptr;
            wrapper->mapped_offset = 0;
            wrapper->mapped_size   = 0;
        }
    }
    else
    {
        GFXRECON_LOG_WARNING(
            "Attempting to unmap VkDeviceMemory object with handle = %" PRIx64 " that has not been mapped", memory);
    }
}

void TraceManager::PreProcess_vkFreeMemory(VkDevice                     device,
                                           VkDeviceMemory               memory,
                                           const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if (memory != VK_NULL_HANDLE)
    {
        auto wrapper = reinterpret_cast<DeviceMemoryWrapper*>(memory);

        if (wrapper->mapped_data != nullptr)
        {
            if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
            {
                util::PageGuardManager* manager = util::PageGuardManager::Get();
                assert(manager != nullptr);

                // Remove memory tracking.
                manager->RemoveTrackedMemory(wrapper->handle_id);
            }
            else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kUnassisted)
            {
                std::lock_guard<std::mutex> lock(mapped_memory_lock_);
                mapped_memory_.erase(wrapper);
            }
        }
    }
}

void TraceManager::PostProcess_vkFreeMemory(VkDevice                     device,
                                            VkDeviceMemory               memory,
                                            const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if (memory != VK_NULL_HANDLE)
    {
        // Destroy external resources.
        auto wrapper = reinterpret_cast<DeviceMemoryWrapper*>(memory);

        if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            if ((page_guard_memory_mode_ == kMemoryModeExternal) && (wrapper->external_allocation != nullptr))
            {
                size_t external_memory_size = manager->GetAlignedSize(static_cast<size_t>(wrapper->allocation_size));
                manager->FreeMemory(wrapper->external_allocation, external_memory_size);
            }
            else if ((page_guard_memory_mode_ == kMemoryModeShadowPersistent) &&
                     (wrapper->shadow_allocation != util::PageGuardManager::kNullShadowHandle))
            {
                manager->FreePersistentShadowMemory(wrapper->shadow_allocation);
            }
        }

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        if (wrapper->hardware_buffer != nullptr)
        {
            ReleaseAndroidHardwareBuffer(wrapper->hardware_buffer);
        }
#endif
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
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        manager->ProcessMemoryEntries([this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
            WriteFillMemoryCmd(memory_id, offset, size, start_address);
        });
    }
    else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kUnassisted)
    {
        std::lock_guard<std::mutex> lock(mapped_memory_lock_);

        for (auto wrapper : mapped_memory_)
        {
            VkDeviceSize size = wrapper->mapped_size;
            if (size == VK_WHOLE_SIZE)
            {
                assert(wrapper->mapped_offset <= wrapper->allocation_size);
                size = wrapper->allocation_size - wrapper->mapped_offset;
            }

            // If the memory is mapped, write the entire mapped region.
            // We set offset to 0, because the pointer returned by vkMapMemory already includes the offset.
            WriteFillMemoryCmd(wrapper->handle_id, 0, size, wrapper->mapped_data);
        }
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
        SetDescriptorUpdateTemplateInfo((*pDescriptorUpdateTemplate), pCreateInfo);
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
        SetDescriptorUpdateTemplateInfo((*pDescriptorUpdateTemplate), pCreateInfo);
    }
}

void TraceManager::PreProcess_vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
    auto device_wrapper = reinterpret_cast<DeviceWrapper*>(device);
    if (!device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        GFXRECON_LOG_ERROR_ONCE(
            "The application is using vkGetBufferDeviceAddress, which requires the bufferDeviceAddressCaptureReplay "
            "feature for accurate capture and replay. The capture device does not support this feature, so replay of "
            "the captured file may fail.");
    }
}

void TraceManager::PreProcess_vkGetAccelerationStructureDeviceAddressKHR(
    VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo)
{
    auto device_wrapper = reinterpret_cast<DeviceWrapper*>(device);
    if (!device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The application is using vkGetAccelerationStructureDeviceAddressKHR, which may require the "
            "accelerationStructureCaptureReplay feature for accurate capture and replay. The capture device does not "
            "support this feature, so replay of the captured file may fail.");
    }
}

void TraceManager::PreProcess_vkGetRayTracingShaderGroupHandlesKHR(
    VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData)
{
    auto device_wrapper = reinterpret_cast<DeviceWrapper*>(device);
    if (!device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The application is using vkGetRayTracingShaderGroupHandlesKHR, which may require the "
            "rayTracingPipelineShaderGroupHandleCaptureReplay feature for accurate capture and replay. The capture "
            "device does not support this feature, so replay of the captured file may fail.");
    }
}

#if defined(__ANDROID__)
void TraceManager::OverrideGetPhysicalDeviceSurfacePresentModesKHR(uint32_t*         pPresentModeCount,
                                                                   VkPresentModeKHR* pPresentModes)
{
    assert((pPresentModeCount != nullptr) && (pPresentModes != nullptr));

    for (uint32_t i = 0; i < (*pPresentModeCount); ++i)
    {
        pPresentModes[i] = VK_PRESENT_MODE_FIFO_KHR;
    }
}
#endif

void TraceManager::WriteToFile(const void* data, size_t size)
{
    file_stream_->Write(data, size);
    if (force_file_flush_)
    {
        file_stream_->Flush();
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
