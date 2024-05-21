/*
** Copyright (c) 2018-2022 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
** Copyright (c) 2019-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_CAPTURE_MANAGER_H
#define GFXRECON_ENCODE_CAPTURE_MANAGER_H

#include "encode/capture_settings.h"
#include "encode/handle_unwrap_memory.h"
#include "encode/parameter_buffer.h"
#include "encode/parameter_encoder.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_output_stream.h"
#include "util/keyboard.h"

#include <atomic>
#include <cassert>
#include <mutex>
#include <optional>
#include <shared_mutex>
#include <string>
#include <unordered_map>
#include <vector>
#include "util/file_path.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class ApiCaptureManager;

// The CommonCaptureManager provides common functionality referenced API specific capture managers
class CommonCaptureManager
{
  public:
    typedef std::shared_mutex ApiCallMutexT;

    static format::HandleId GetUniqueId() { return ++unique_id_counter_; }

    using ApiSharedLockT    = std::shared_lock<ApiCallMutexT>;
    using ApiExclusiveLockT = std::unique_lock<ApiCallMutexT>;
    static auto AcquireSharedApiCallLock() { return std::move(ApiSharedLockT(api_call_mutex_)); }
    static auto AcquireExclusiveApiCallLock() { return std::move(ApiExclusiveLockT(api_call_mutex_)); }

    class ApiCallLock
    {
      public:
        enum class Type
        {
            kExclusive,
            kShared
        };

        ApiCallLock(Type type, ApiCallMutexT& mutex);

      private:
        std::optional<ApiExclusiveLockT> exclusive;
        std::optional<ApiSharedLockT>    shared;
    };
    // This method returns the composite with the apropos Lock initialized
    ApiCallLock AcquireCallLock() const;

    HandleUnwrapMemory* GetHandleUnwrapMemory()
    {
        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);
        thread_data->handle_unwrap_memory_.Reset();
        return &thread_data->handle_unwrap_memory_;
    }

    ParameterEncoder* BeginTrackedApiCallCapture(format::ApiCallId call_id)
    {
        if (capture_mode_ != kModeDisabled)
        {
            return InitApiCallCapture(call_id);
        }

        return nullptr;
    }

    ParameterEncoder* BeginApiCallCapture(format::ApiCallId call_id)
    {
        if ((capture_mode_ & kModeWrite) == kModeWrite)
        {
            return InitApiCallCapture(call_id);
        }

        return nullptr;
    }

    ParameterEncoder* BeginTrackedMethodCallCapture(format::ApiCallId call_id, format::HandleId object_id)
    {
        if (capture_mode_ != kModeDisabled)
        {
            return InitMethodCallCapture(call_id, object_id);
        }

        return nullptr;
    }

    ParameterEncoder* BeginMethodCallCapture(format::ApiCallId call_id, format::HandleId object_id)
    {
        if ((capture_mode_ & kModeWrite) == kModeWrite)
        {
            return InitMethodCallCapture(call_id, object_id);
        }

        return nullptr;
    }

    void EndApiCallCapture();

    void EndMethodCallCapture();

    void WriteFrameMarker(format::MarkerType marker_type);

    void EndFrame(format::ApiFamilyId api_family);

    // Pre/PostQueueSubmit to be called immediately before and after work is submitted to the GPU by vkQueueSubmit for
    // Vulkan or by ID3D12CommandQueue::ExecuteCommandLists for DX12.
    void PreQueueSubmit(format::ApiFamilyId api_family);
    void PostQueueSubmit(format::ApiFamilyId api_family);

    bool ShouldTriggerScreenshot();

    util::ScreenshotFormat GetScreenshotFormat() { return screenshot_format_; }

    void CheckContinueCaptureForWriteMode(format::ApiFamilyId api_family, uint32_t current_boundary_count);

    void CheckStartCaptureForTrackMode(format::ApiFamilyId api_family, uint32_t current_boundary_count);

    bool IsTrimHotkeyPressed();

    CaptureSettings::RuntimeTriggerState GetRuntimeTriggerState();

    bool RuntimeTriggerEnabled();

    bool RuntimeTriggerDisabled();

    void WriteDisplayMessageCmd(format::ApiFamilyId api_family, const char* message);

    void WriteExeFileInfo(format::ApiFamilyId api_family, const gfxrecon::util::filepath::FileInfo& info);

    void ForcedWriteAnnotation(const format::AnnotationType type, const char* label, const char* data);

    /// @brief Inject an Annotation block into the capture file.
    /// @param type Identifies the contents of data as plain, xml, or json text
    /// @param label The key or name of the annotation.
    /// @param data The value or payload text of the annotation.
    void WriteAnnotation(const format::AnnotationType type, const char* label, const char* data);

    bool GetIUnknownWrappingSetting() const { return iunknown_wrapping_; }
    auto GetForceCommandSerialization() const { return force_command_serialization_; }
    auto GetQueueZeroOnly() const { return queue_zero_only_; }
    auto GetAllowPipelineCompileRequired() const { return allow_pipeline_compile_required_; }

    bool     IsAnnotated() const { return rv_annotation_info_.rv_annotation; }
    uint16_t GetGPUVAMask() const { return rv_annotation_info_.gpuva_mask; }
    uint16_t GetDescriptorMask() const { return rv_annotation_info_.descriptor_mask; }
    uint64_t GetShaderIDMask() const { return rv_annotation_info_.shaderid_mask; }

    uint64_t GetBlockIndex()
    {
        auto thread_data = GetThreadData();
        return thread_data->block_index_ == 0 ? 0 : thread_data->block_index_ - 1;
    }

    static bool CreateInstance(ApiCaptureManager* api_instance_, const std::function<void()>& destroyer);
    template <typename Derived>
    static bool CreateInstance()
    {
        return CreateInstance(Derived::InitSingleton(), Derived::DestroySingleton);
    }

    CommonCaptureManager();

    enum CaptureModeFlags : uint32_t
    {
        kModeDisabled      = 0x0,
        kModeWrite         = 0x01,
        kModeTrack         = 0x02,
        kModeWriteAndTrack = (kModeWrite | kModeTrack)
    };

    enum PageGuardMemoryMode : uint32_t
    {
        kMemoryModeDisabled,
        kMemoryModeShadowInternal,   // Internally managed shadow memory allocations.
        kMemoryModeShadowPersistent, // Externally managed shadow memory allocations.
        kMemoryModeExternal          // Imported host memory without shadow allocations.
    };

    typedef uint32_t CaptureMode;

    class ThreadData
    {
      public:
        ThreadData();

        ~ThreadData() {}

        std::vector<uint8_t>& GetScratchBuffer() { return scratch_buffer_; }

      public:
        const format::ThreadId                   thread_id_;
        format::ApiCallId                        call_id_;
        format::HandleId                         object_id_;
        std::unique_ptr<encode::ParameterBuffer> parameter_buffer_;
        std::unique_ptr<ParameterEncoder>        parameter_encoder_;
        std::vector<uint8_t>                     compressed_buffer_;
        HandleUnwrapMemory                       handle_unwrap_memory_;
        uint64_t                                 block_index_;

      private:
        static format::ThreadId GetThreadId();

      private:
        static std::mutex                                     count_lock_;
        static format::ThreadId                               thread_count_;
        static std::unordered_map<uint64_t, format::ThreadId> id_map_;

      private:
        // Used for combining multiple buffers for a single file write.
        std::vector<uint8_t> scratch_buffer_;
    };

    ThreadData* GetThreadData();
    bool        IsCaptureModeTrack() const;
    bool        IsCaptureModeWrite() const;

    void DestroyInstance(ApiCaptureManager* singleton);

  protected:
    bool LockedCreateInstance(ApiCaptureManager* api_capture_singleton, const std::function<void()>& destroyer);

    virtual ~CommonCaptureManager();

    bool Initialize(format::ApiFamilyId                   api_family,
                    std::string                           base_filename,
                    const CaptureSettings::TraceSettings& trace_settings);

  public:
    bool                                GetForceFileFlush() const { return force_file_flush_; }
    CaptureSettings::MemoryTrackingMode GetMemoryTrackingMode() const { return memory_tracking_mode_; }
    bool                                GetPageGuardAlignBufferSizes() const { return page_guard_align_buffer_sizes_; }
    bool                                GetPageGuardTrackAhbMemory() const { return page_guard_track_ahb_memory_; }
    PageGuardMemoryMode                 GetPageGuardMemoryMode() const { return page_guard_memory_mode_; }
    const std::string&                  GetTrimKey() const { return trim_key_; }
    bool                                IsTrimEnabled() const { return trim_enabled_; }
    uint32_t                            GetCurrentFrame() const { return current_frame_; }
    CaptureMode                         GetCaptureMode() const { return capture_mode_; }
    bool                                GetDebugLayerSetting() const { return debug_layer_; }
    bool                                GetDebugDeviceLostSetting() const { return debug_device_lost_; }
    bool                                GetDisableDxrSetting() const { return disable_dxr_; }
    auto                                GetAccelStructPaddingSetting() const { return accel_struct_padding_; }

    util::Compressor*      GetCompressor() { return compressor_.get(); }
    std::mutex&            GetMappedMemoryLock() { return mapped_memory_lock_; }
    util::Keyboard&        GetKeyboard() { return keyboard_; }
    const std::string&     GetScreenshotPrefix() const { return screenshot_prefix_; }
    util::ScreenshotFormat GetScreenShotFormat() const { return screenshot_format_; }

    std::string CreateTrimFilename(const std::string& base_filename, const util::UintRange& trim_range);
    bool        CreateCaptureFile(format::ApiFamilyId api_family, const std::string& base_filename);
    void        WriteCaptureOptions(std::string& operation_annotation);
    void        ActivateTrimming();
    void        DeactivateTrimming();

    void WriteFileHeader();
    void BuildOptionList(const format::EnabledOptions&        enabled_options,
                         std::vector<format::FileOptionPair>* option_list);

    ParameterEncoder* InitApiCallCapture(format::ApiCallId call_id);

    ParameterEncoder* InitMethodCallCapture(format::ApiCallId call_id, format::HandleId object_id);

    void
    WriteResizeWindowCmd(format::ApiFamilyId api_family, format::HandleId surface_id, uint32_t width, uint32_t height);

    void WriteFillMemoryCmd(
        format::ApiFamilyId api_family, format::HandleId memory_id, uint64_t offset, uint64_t size, const void* data);

    void WriteCreateHeapAllocationCmd(format::ApiFamilyId api_family, uint64_t allocation_id, uint64_t allocation_size);

    void WriteToFile(const void* data, size_t size);

    template <size_t N>
    void CombineAndWriteToFile(const std::pair<const void*, size_t> (&buffers)[N])
    {
        static_assert(N != 1, "Use WriteToFile(void*, size) when writing a single buffer.");

        // Combine buffers for a single write.
        std::vector<uint8_t>& scratch_buffer = GetThreadData()->GetScratchBuffer();
        scratch_buffer.clear();
        for (size_t i = 0; i < N; ++i)
        {
            const uint8_t* const data = reinterpret_cast<const uint8_t*>(buffers[i].first);
            const size_t         size = buffers[i].second;
            scratch_buffer.insert(scratch_buffer.end(), data, data + size);
        }

        WriteToFile(scratch_buffer.data(), scratch_buffer.size());
    }

    void IncrementBlockIndex(uint64_t blocks)
    {
        block_index_ += blocks;
        GetThreadData()->block_index_ = block_index_;
    }

  protected:
    std::unique_ptr<util::Compressor> compressor_;
    std::mutex                        mapped_memory_lock_;
    util::Keyboard                    keyboard_;
    std::string                       screenshot_prefix_;
    util::ScreenshotFormat            screenshot_format_;
    std::atomic<uint64_t>             block_index_;

  private:
    static void AtExit();

  private:
    static std::mutex                               instance_lock_;
    static CommonCaptureManager*                    singleton_;
    static thread_local std::unique_ptr<ThreadData> thread_data_;
    static std::atomic<format::HandleId>            unique_id_counter_;
    static ApiCallMutexT                            api_call_mutex_;

    uint32_t instance_count_ = 0;
    struct ApiInstanceRecord
    {
        size_t                count;
        std::function<void()> destroyer;
    };
    using ApiCaptureManagerMap = std::unordered_map<ApiCaptureManager*, ApiInstanceRecord>;
    ApiCaptureManagerMap api_capture_managers_;

    CaptureSettings default_settings_; // Default settings from the initial api singleton
    CaptureSettings
        capture_settings_; // Settings from the settings file and environment at capture manager creation time.

    std::unique_ptr<util::FileOutputStream> file_stream_;
    format::EnabledOptions                  file_options_;
    std::string                             base_filename_;
    bool                                    timestamp_filename_;
    bool                                    force_file_flush_;
    CaptureSettings::MemoryTrackingMode     memory_tracking_mode_;
    bool                                    page_guard_align_buffer_sizes_;
    bool                                    page_guard_track_ahb_memory_;
    bool                                    page_guard_unblock_sigsegv_;
    bool                                    page_guard_signal_handler_watcher_;
    uint32_t                                page_guard_signal_handler_watcher_max_restores_;
    PageGuardMemoryMode                     page_guard_memory_mode_;
    bool                                    page_guard_separate_read_;
    bool                                    page_guard_copy_on_map_;
    bool                                    page_guard_external_memory_;
    bool                                    trim_enabled_;
    CaptureSettings::TrimBoundary           trim_boundary_;
    std::vector<util::UintRange>            trim_ranges_;
    std::string                             trim_key_;
    uint32_t                                trim_key_frames_;
    uint32_t                                trim_key_first_frame_;
    size_t                                  trim_current_range_;
    uint32_t                                current_frame_;
    uint32_t                                queue_submit_count_;
    CaptureMode                             capture_mode_;
    bool                                    previous_hotkey_state_;
    CaptureSettings::RuntimeTriggerState    previous_runtime_trigger_state_;
    bool                                    debug_layer_;
    bool                                    debug_device_lost_;
    bool                                    screenshots_enabled_;
    std::vector<uint32_t>                   screenshot_indices_;
    bool                                    disable_dxr_;
    uint32_t                                accel_struct_padding_;
    bool                                    iunknown_wrapping_;
    bool                                    force_command_serialization_;
    bool                                    queue_zero_only_;
    bool                                    allow_pipeline_compile_required_;
    bool                                    quit_after_frame_ranges_;

    struct
    {
        bool     rv_annotation{ false };
        uint16_t gpuva_mask{ RvAnnotationUtil::kGPUVAMask };
        uint16_t descriptor_mask{ RvAnnotationUtil::kDescriptorMask };
        uint64_t shaderid_mask{ RvAnnotationUtil::kShaderIDMask };
    } rv_annotation_info_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CAPTURE_MANAGER_H
