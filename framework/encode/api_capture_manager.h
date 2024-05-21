/*
** Copyright (c) 2018-2022 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_API_CAPTURE_MANAGER_H
#define GFXRECON_ENCODE_API_CAPTURE_MANAGER_H

#include "encode/capture_manager.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class ApiCaptureManager
{
  public:
    ApiCaptureManager(format::ApiFamilyId api_family) : api_family_(api_family) {}
    void SetCommonManager(CommonCaptureManager* common_manager) { common_manager_ = common_manager; }

    // Forwarded Statics
    static format::HandleId GetUniqueId() { return CommonCaptureManager::GetUniqueId(); }
    static auto AcquireSharedApiCallLock() { return std::move(CommonCaptureManager::AcquireSharedApiCallLock()); }

    static auto AcquireExclusiveApiCallLock() { return std::move(CommonCaptureManager::AcquireExclusiveApiCallLock()); }

    // Virtual interface
    virtual void CreateStateTracker()                                                               = 0;
    virtual void DestroyStateTracker()                                                              = 0;
    virtual void WriteTrackedState(util::FileOutputStream* file_stream, format::ThreadId thread_id) = 0;
    virtual CaptureSettings::TraceSettings GetDefaultTraceSettings();

    format::ApiFamilyId GetApiFamily() const { return api_family_; }
    bool                IsCaptureModeTrack() const { return common_manager_->IsCaptureModeTrack(); }
    bool                IsCaptureModeWrite() const { return common_manager_->IsCaptureModeWrite(); }

    bool IsPageGuardMemoryModeDisabled() const
    {
        return GetPageGuardMemoryMode() == CommonCaptureManager::kMemoryModeDisabled;
    }
    bool IsPageGuardMemoryModeShadowInternal() const
    {
        return GetPageGuardMemoryMode() == CommonCaptureManager::kMemoryModeShadowInternal;
    }
    bool IsPageGuardMemoryModeShadowPersistent() const
    {
        return GetPageGuardMemoryMode() == CommonCaptureManager::kMemoryModeShadowPersistent;
    }
    bool IsPageGuardMemoryModeExternal() const
    {
        return GetPageGuardMemoryMode() == CommonCaptureManager::kMemoryModeExternal;
    }

    typedef uint32_t CaptureMode;

    // Forwarded Common Methods
    auto AcquireCallLock() { return common_manager_->AcquireCallLock(); }

    HandleUnwrapMemory* GetHandleUnwrapMemory() { return common_manager_->GetHandleUnwrapMemory(); }
    ParameterEncoder*   BeginTrackedApiCallCapture(format::ApiCallId call_id)
    {
        return common_manager_->BeginTrackedApiCallCapture(call_id);
    }
    ParameterEncoder* BeginApiCallCapture(format::ApiCallId call_id)
    {
        return common_manager_->BeginApiCallCapture(call_id);
    }
    ParameterEncoder* BeginTrackedMethodCallCapture(format::ApiCallId call_id, format::HandleId object_id)
    {
        return common_manager_->BeginTrackedMethodCallCapture(call_id, object_id);
    }
    ParameterEncoder* BeginMethodCallCapture(format::ApiCallId call_id, format::HandleId object_id)
    {
        return common_manager_->BeginMethodCallCapture(call_id, object_id);
    }
    void EndApiCallCapture() { common_manager_->EndApiCallCapture(); }

    void EndMethodCallCapture() { common_manager_->EndMethodCallCapture(); }

    void WriteFrameMarker(format::MarkerType marker_type) { common_manager_->WriteFrameMarker(marker_type); }

    void EndFrame() { common_manager_->EndFrame(api_family_); }

    // Pre/PostQueueSubmit to be called immediately before and after work is submitted to the GPU by vkQueueSubmit for
    // Vulkan or by ID3D12CommandQueue::ExecuteCommandLists for DX12.
    void PreQueueSubmit() { common_manager_->PreQueueSubmit(api_family_); }
    void PostQueueSubmit() { common_manager_->PostQueueSubmit(api_family_); }

    bool ShouldTriggerScreenshot() { return common_manager_->ShouldTriggerScreenshot(); }

    void CheckContinueCaptureForWriteMode(uint32_t current_boundary_count)
    {
        common_manager_->CheckContinueCaptureForWriteMode(api_family_, current_boundary_count);
    }

    void CheckStartCaptureForTrackMode(uint32_t current_boundary_count)
    {
        common_manager_->CheckStartCaptureForTrackMode(api_family_, current_boundary_count);
    }

    bool IsTrimHotkeyPressed() { return common_manager_->IsTrimHotkeyPressed(); }

    CaptureSettings::RuntimeTriggerState GetRuntimeTriggerState() { return common_manager_->GetRuntimeTriggerState(); }

    bool RuntimeTriggerEnabled() { return common_manager_->RuntimeTriggerEnabled(); }

    bool RuntimeTriggerDisabled() { return common_manager_->RuntimeTriggerDisabled(); }

    void WriteDisplayMessageCmd(const char* message) { common_manager_->WriteDisplayMessageCmd(api_family_, message); }

    void WriteExeFileInfo(const gfxrecon::util::filepath::FileInfo& info)
    {
        common_manager_->WriteExeFileInfo(api_family_, info);
    }

    void ForcedWriteAnnotation(const format::AnnotationType type, const char* label, const char* data)
    {
        common_manager_->ForcedWriteAnnotation(type, label, data);
    }

    /// @brief Inject an Annotation block into the capture file.
    /// @param type Identifies the contents of data as plain, xml, or json text
    /// @param label The key or name of the annotation.
    /// @param data The value or payload text of the annotation.
    void WriteAnnotation(const format::AnnotationType type, const char* label, const char* data)
    {
        common_manager_->WriteAnnotation(type, label, data);
    }

    bool GetIUnknownWrappingSetting() const { return common_manager_->GetIUnknownWrappingSetting(); }
    auto GetForceCommandSerialization() const { return common_manager_->GetForceCommandSerialization(); }
    auto GetQueueZeroOnly() const { return common_manager_->GetQueueZeroOnly(); }
    auto GetAllowPipelineCompileRequired() const { return common_manager_->GetAllowPipelineCompileRequired(); }

    bool     IsAnnotated() const { return common_manager_->IsAnnotated(); }
    uint16_t GetGPUVAMask() const { return common_manager_->GetGPUVAMask(); }
    uint16_t GetDescriptorMask() const { return common_manager_->GetDescriptorMask(); }
    uint64_t GetShaderIDMask() const { return common_manager_->GetShaderIDMask(); }
    uint64_t GetBlockIndex() const { return common_manager_->GetBlockIndex(); }

    bool                                GetForceFileFlush() const { return common_manager_->GetForceFileFlush(); }
    CaptureSettings::MemoryTrackingMode GetMemoryTrackingMode() const
    {
        return common_manager_->GetMemoryTrackingMode();
    }
    bool GetPageGuardAlignBufferSizes() const { return common_manager_->GetPageGuardAlignBufferSizes(); }
    bool GetPageGuardTrackAhbMemory() const { return common_manager_->GetPageGuardTrackAhbMemory(); }
    CommonCaptureManager::PageGuardMemoryMode GetPageGuardMemoryMode() const
    {
        return common_manager_->GetPageGuardMemoryMode();
    }
    const std::string&                GetTrimKey() const { return common_manager_->GetTrimKey(); }
    bool                              IsTrimEnabled() const { return common_manager_->IsTrimEnabled(); }
    uint32_t                          GetCurrentFrame() const { return common_manager_->GetCurrentFrame(); }
    CommonCaptureManager::CaptureMode GetCaptureMode() const { return common_manager_->GetCaptureMode(); }
    bool                              GetDebugLayerSetting() const { return common_manager_->GetDebugLayerSetting(); }
    bool GetDebugDeviceLostSetting() const { return common_manager_->GetDebugDeviceLostSetting(); }
    bool GetDisableDxrSetting() const { return common_manager_->GetDisableDxrSetting(); }
    auto GetAccelStructPaddingSetting() const { return common_manager_->GetAccelStructPaddingSetting(); }

    void WriteResizeWindowCmd(format::HandleId surface_id, uint32_t width, uint32_t height)
    {
        common_manager_->WriteResizeWindowCmd(api_family_, surface_id, width, height);
    }
    void WriteFillMemoryCmd(format::HandleId memory_id, uint64_t offset, uint64_t size, const void* data)
    {
        common_manager_->WriteFillMemoryCmd(api_family_, memory_id, offset, size, data);
    }
    void WriteCreateHeapAllocationCmd(uint64_t allocation_id, uint64_t allocation_size)
    {
        common_manager_->WriteCreateHeapAllocationCmd(api_family_, allocation_id, allocation_size);
    }
    void WriteToFile(const void* data, size_t size) { common_manager_->WriteToFile(data, size); }

    template <size_t N>
    void CombineAndWriteToFile(const std::pair<const void*, size_t> (&buffers)[N])
    {
        common_manager_->CombineAndWriteToFile<N>(buffers);
    }

    CommonCaptureManager::ThreadData* GetThreadData() { return common_manager_->GetThreadData(); }
    util::Compressor*                 GetCompressor() { return common_manager_->GetCompressor(); }
    std::mutex&                       GetMappedMemoryLock() { return common_manager_->GetMappedMemoryLock(); }
    util::Keyboard&                   GetKeyboard() { return common_manager_->GetKeyboard(); }
    const std::string&                GetScreenshotPrefix() const { return common_manager_->GetScreenshotPrefix(); }
    util::ScreenshotFormat            GetScreenshotFormat() { return common_manager_->GetScreenshotFormat(); }

  protected:
    const format::ApiFamilyId api_family_;
    CommonCaptureManager*     common_manager_ = nullptr;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_API_CAPTURE_MANAGER_H
