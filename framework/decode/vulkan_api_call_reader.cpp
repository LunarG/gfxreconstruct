/*
** Copyright (c) 2026 Arm Limited <open-source-office@arm.com>
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

#include "decode/vulkan_api_call_reader.h"

#include "decode/file_processor.h"
#include "generated/generated_vulkan_native_call_consumer.h"
#include "generated/generated_vulkan_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

namespace
{
class ApiCallOnlyVulkanDecoder final : public VulkanDecoder
{
  public:
    ApiCallOnlyVulkanDecoder(VulkanNativeCallCallbacks* callbacks, VulkanNativeCallConsumerBase* native_consumer) :
        callbacks_(callbacks), native_consumer_(native_consumer)
    {}

    bool SupportsMetaDataId(format::MetaDataId meta_data_id) override
    {
        if ((callbacks_ == nullptr) || (native_consumer_ == nullptr))
        {
            return false;
        }

        const format::ApiFamilyId  api  = format::GetMetaDataApi(meta_data_id);
        const format::MetaDataType type = format::GetMetaDataType(meta_data_id);
        const bool                 supported_api =
            (api == format::ApiFamilyId::ApiFamily_None) || (api == format::ApiFamilyId::ApiFamily_Vulkan);
        const bool supported =
            supported_api &&
            (((type == format::MetaDataType::kFillMemoryCommand) && callbacks_->HasMemoryUpdateCallback()) ||
             ((type == format::MetaDataType::kSetDeviceMemoryPropertiesCommand) &&
              callbacks_->HasDeviceMemoryPropertiesCallback()) ||
             ((type == format::MetaDataType::kBeginResourceInitCommand) &&
              callbacks_->HasResourceInitializationBeginCallback()) ||
             ((type == format::MetaDataType::kInitBufferCommand) && callbacks_->HasBufferInitializationCallback()) ||
             ((type == format::MetaDataType::kInitImageCommand) && callbacks_->HasImageInitializationCallback()) ||
             ((type == format::MetaDataType::kEndResourceInitCommand) &&
              callbacks_->HasResourceInitializationEndCallback()) ||
             ((type == format::MetaDataType::kSetOpaqueAddressCommand) && callbacks_->HasOpaqueAddressCallback()) ||
             ((type == format::MetaDataType::kVulkanBuildAccelerationStructuresCommand) &&
              callbacks_->HasAccelerationStructuresBuildCallback()) ||
             ((type == format::MetaDataType::kVulkanCopyAccelerationStructuresCommand) &&
              callbacks_->HasAccelerationStructuresCopyCallback()) ||
             ((type == format::MetaDataType::kVulkanWriteAccelerationStructuresPropertiesCommand) &&
              callbacks_->HasAccelerationStructureWritePropertiesCallback()));
        if (!supported)
        {
            callbacks_->UnhandledMetaCommand({ current_block_index_, meta_data_id });
        }
        return supported;
    }

    void DecodeFunctionCall(format::ApiCallId  call_id,
                            const ApiCallInfo& call_info,
                            const uint8_t*     parameter_buffer,
                            size_t             buffer_size) override
    {
        if ((callbacks_ != nullptr) && (GetVulkanNativeCommandInfo(static_cast<uint32_t>(call_id)) == nullptr))
        {
            const char* name = GetVulkanApiCallName(static_cast<uint32_t>(call_id));
            callbacks_->UnsupportedCall(
                { { call_info.index, call_info.thread_id }, static_cast<uint32_t>(call_id), name, nullptr, 0 });
            return;
        }
        VulkanDecoder::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);
    }

    void DispatchStateBeginMarker(uint64_t) override {}

    void DispatchStateEndMarker(uint64_t) override
    {
        if (native_consumer_ != nullptr)
        {
            native_consumer_->FlushPendingOpaqueAddresses();
        }
    }

    void DispatchFrameEndMarker(uint64_t) override
    {
        if (native_consumer_ != nullptr)
        {
            native_consumer_->FlushPendingOpaqueAddresses();
        }
    }

    void DispatchFillMemoryCommand(
        format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override
    {
        native_consumer_->ProcessMemoryUpdate(current_block_index_, thread_id, memory_id, offset, size, data);
    }

    void DispatchSetDeviceMemoryPropertiesCommand(format::ThreadId                             thread_id,
                                                  format::HandleId                             physical_device_id,
                                                  const std::vector<format::DeviceMemoryType>& memory_types,
                                                  const std::vector<format::DeviceMemoryHeap>& memory_heaps) override
    {
        native_consumer_->ProcessDeviceMemoryProperties(
            current_block_index_, thread_id, physical_device_id, memory_types, memory_heaps);
    }

    void DispatchBeginResourceInitCommand(format::ThreadId thread_id,
                                          format::HandleId device_id,
                                          uint64_t         total_copy_size,
                                          uint64_t         max_copy_size) override
    {
        native_consumer_->ProcessResourceInitializationBegin(
            current_block_index_, thread_id, device_id, total_copy_size, max_copy_size);
    }

    void DispatchInitBufferCommand(format::ThreadId thread_id,
                                   format::HandleId device_id,
                                   format::HandleId buffer_id,
                                   uint64_t         data_size,
                                   const uint8_t*   data) override
    {
        native_consumer_->ProcessBufferInitialization(
            current_block_index_, thread_id, device_id, buffer_id, data_size, data);
    }

    void DispatchInitImageCommand(format::ThreadId             thread_id,
                                  format::HandleId             device_id,
                                  format::HandleId             image_id,
                                  uint64_t                     data_size,
                                  uint32_t                     aspect,
                                  uint32_t                     layout,
                                  const std::vector<uint64_t>& level_sizes,
                                  const uint8_t*               data) override
    {
        native_consumer_->ProcessImageInitialization(
            current_block_index_, thread_id, device_id, image_id, data_size, aspect, layout, level_sizes, data);
    }

    void DispatchEndResourceInitCommand(format::ThreadId thread_id, format::HandleId device_id) override
    {
        native_consumer_->ProcessResourceInitializationEnd(current_block_index_, thread_id, device_id);
    }

    void DispatchSetOpaqueAddressCommand(format::ThreadId thread_id,
                                         format::HandleId device_id,
                                         format::HandleId object_id,
                                         uint64_t         address) override
    {
        native_consumer_->ProcessOpaqueAddress(current_block_index_, thread_id, device_id, object_id, address);
    }

    void SetCurrentBlockIndex(uint64_t block_index) override
    {
        current_block_index_ = block_index;
        VulkanDecoder::SetCurrentBlockIndex(block_index);
    }

  private:
    VulkanNativeCallCallbacks*    callbacks_{ nullptr };
    VulkanNativeCallConsumerBase* native_consumer_{ nullptr };
    uint64_t                      current_block_index_{ 0 };
};
} // namespace

class VulkanApiCallReader::Impl
{
  public:
    explicit Impl(uint64_t block_limit) :
        native_consumer_(std::make_unique<VulkanNativeCallConsumer>(callbacks_)), consumer_(native_consumer_.get()),
        decoder_(&callbacks_, native_consumer_.get()), file_processor_(block_limit)
    {
        decoder_.AddConsumer(consumer_);
        file_processor_.AddDecoder(&decoder_);
    }

    Impl(VulkanConsumer& consumer, uint64_t block_limit) :
        consumer_(&consumer), decoder_(nullptr, nullptr), file_processor_(block_limit)
    {
        decoder_.AddConsumer(consumer_);
        file_processor_.AddDecoder(&decoder_);
    }

    ~Impl()
    {
        file_processor_.RemoveDecoder(&decoder_);
        decoder_.RemoveConsumer(consumer_);
    }

    VulkanNativeCallCallbacks                 callbacks_;
    std::unique_ptr<VulkanNativeCallConsumer> native_consumer_;
    VulkanConsumer*                           consumer_;
    ApiCallOnlyVulkanDecoder                  decoder_;
    FileProcessor                             file_processor_;
};

VulkanApiCallReader::VulkanApiCallReader(uint64_t block_limit) : impl_(std::make_unique<Impl>(block_limit)) {}

VulkanApiCallReader::VulkanApiCallReader(VulkanConsumer& consumer, uint64_t block_limit) :
    impl_(std::make_unique<Impl>(consumer, block_limit))
{}

VulkanApiCallReader::~VulkanApiCallReader() = default;

bool VulkanApiCallReader::Initialize(const std::string& filename)
{
    impl_->callbacks_.ClearError();
    return impl_->file_processor_.Initialize(filename);
}

bool VulkanApiCallReader::ProcessNextFrame()
{
    const bool more_frames = impl_->file_processor_.ProcessNextFrame();
    if (impl_->native_consumer_ != nullptr)
    {
        impl_->native_consumer_->FlushPendingOpaqueAddresses();
    }
    return more_frames && !impl_->callbacks_.HasFatalError();
}

bool VulkanApiCallReader::ProcessAllFrames()
{
    const bool processed = impl_->file_processor_.ProcessAllFrames();
    if (impl_->native_consumer_ != nullptr)
    {
        impl_->native_consumer_->FlushPendingOpaqueAddresses();
    }
    return processed && !impl_->callbacks_.HasFatalError();
}

BlockIOError VulkanApiCallReader::GetErrorState() const
{
    return impl_->file_processor_.GetErrorState();
}

bool VulkanApiCallReader::EntireFileWasProcessed() const
{
    return impl_->file_processor_.EntireFileWasProcessed();
}

uint64_t VulkanApiCallReader::GetCurrentFrameNumber() const
{
    return impl_->file_processor_.GetCurrentFrameNumber();
}

uint64_t VulkanApiCallReader::GetCurrentBlockIndex() const
{
    return impl_->file_processor_.GetCurrentBlockIndex();
}

const format::FileHeader& VulkanApiCallReader::GetFileHeader() const
{
    return impl_->file_processor_.GetFileHeader();
}

bool VulkanApiCallReader::RegisterCallback(const std::string& name, PFN_vkVoidFunction callback)
{
    if ((impl_->native_consumer_ == nullptr) || (GetVulkanNativeCommandInfo(name.c_str()) == nullptr))
    {
        return false;
    }
    impl_->callbacks_.Register({ name.c_str(), callback });
    return true;
}

size_t VulkanApiCallReader::RegisterCallbacks(const VulkanNativeCallbackEntry*                    entries,
                                              size_t                                              count,
                                              std::vector<VulkanNativeCallbackRegistrationError>* rejected_entries)
{
    size_t accepted = 0;
    for (size_t i = 0; i < count; ++i)
    {
        VulkanNativeCallbackRegistrationStatus status = VulkanNativeCallbackRegistrationStatus::kSuccess;
        const char*                            name   = (entries != nullptr) ? entries[i].name : nullptr;
        if (impl_->native_consumer_ == nullptr)
        {
            status = VulkanNativeCallbackRegistrationStatus::kExternalConsumer;
        }
        else if ((entries == nullptr) || (name == nullptr) || (name[0] == '\0'))
        {
            status = VulkanNativeCallbackRegistrationStatus::kInvalidEntry;
        }
        else if (GetVulkanNativeCommandInfo(name) == nullptr)
        {
            status = VulkanNativeCallbackRegistrationStatus::kUnsupportedCommand;
        }
        else
        {
            impl_->callbacks_.Register(entries[i]);
            ++accepted;
        }

        if ((status != VulkanNativeCallbackRegistrationStatus::kSuccess) && (rejected_entries != nullptr))
        {
            rejected_entries->push_back({ i, name != nullptr ? name : "", status });
        }
    }
    return accepted;
}

bool VulkanApiCallReader::GetSupportedCallbackInfo(const std::string& name, VulkanNativeCommandInfo* info) const
{
    const VulkanNativeCommandInfo* command = GetVulkanNativeCommandInfo(name.c_str());
    if ((command == nullptr) || (info == nullptr))
    {
        return false;
    }
    *info = *command;
    return true;
}

bool VulkanApiCallReader::SetMissingCallbackPolicy(VulkanNativeMissingCallbackPolicy policy)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetMissingCallbackPolicy(policy);
    return true;
}

VulkanNativeMissingCallbackPolicy VulkanApiCallReader::GetMissingCallbackPolicy() const
{
    return impl_->callbacks_.GetMissingCallbackPolicy();
}

bool VulkanApiCallReader::HasNativeCallError() const
{
    return impl_->callbacks_.GetLastError().code != VulkanNativeCallErrorCode::kNone;
}

const VulkanNativeCallError& VulkanApiCallReader::GetLastNativeCallError() const
{
    return impl_->callbacks_.GetLastError();
}

void VulkanApiCallReader::ClearNativeCallError()
{
    impl_->callbacks_.ClearError();
}

bool VulkanApiCallReader::SetPreCallHook(VulkanNativeCallCallbacks::CallHook hook, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetPreCallHook(hook, user_data);
    return true;
}

bool VulkanApiCallReader::SetPostCallHook(VulkanNativeCallCallbacks::CallHook hook, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetPostCallHook(hook, user_data);
    return true;
}

bool VulkanApiCallReader::SetMissingCallbackHook(VulkanNativeCallCallbacks::CallHook hook, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetMissingCallbackHook(hook, user_data);
    return true;
}

bool VulkanApiCallReader::SetMemoryUpdateCallback(VulkanNativeCallCallbacks::MemoryUpdateCallback callback,
                                                  void*                                           user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetMemoryUpdateCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetDeviceMemoryPropertiesCallback(
    VulkanNativeCallCallbacks::DeviceMemoryPropertiesCallback callback, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetDeviceMemoryPropertiesCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetResourceInitializationBeginCallback(
    VulkanNativeCallCallbacks::ResourceInitializationBeginCallback callback, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetResourceInitializationBeginCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetBufferInitializationCallback(
    VulkanNativeCallCallbacks::BufferInitializationCallback callback, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetBufferInitializationCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetImageInitializationCallback(
    VulkanNativeCallCallbacks::ImageInitializationCallback callback, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetImageInitializationCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetResourceInitializationEndCallback(
    VulkanNativeCallCallbacks::ResourceInitializationEndCallback callback, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetResourceInitializationEndCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetDeviceAddressFixupCallback(VulkanNativeCallCallbacks::DeviceAddressFixupCallback callback,
                                                        void*                                                 user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetDeviceAddressFixupCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetShaderGroupHandleFixupCallback(
    VulkanNativeCallCallbacks::ShaderGroupHandleFixupCallback callback, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetShaderGroupHandleFixupCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetUnhandledMetaCommandCallback(
    VulkanNativeCallCallbacks::UnhandledMetaCommandCallback callback, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetUnhandledMetaCommandCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetOpaqueAddressCallback(VulkanNativeCallCallbacks::OpaqueAddressCallback callback,
                                                   void*                                            user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetOpaqueAddressCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetAccelerationStructuresBuildCallback(
    VulkanNativeCallCallbacks::AccelerationStructuresBuildCallback callback, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetAccelerationStructuresBuildCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetAccelerationStructuresCopyCallback(
    VulkanNativeCallCallbacks::AccelerationStructuresCopyCallback callback, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetAccelerationStructuresCopyCallback(callback, user_data);
    return true;
}

bool VulkanApiCallReader::SetAccelerationStructureWritePropertiesCallback(
    VulkanNativeCallCallbacks::AccelerationStructureWritePropertiesCallback callback, void* user_data)
{
    if (impl_->native_consumer_ == nullptr)
    {
        return false;
    }
    impl_->callbacks_.SetAccelerationStructureWritePropertiesCallback(callback, user_data);
    return true;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
