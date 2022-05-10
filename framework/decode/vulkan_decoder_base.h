/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_DECODER_BASE_H
#define GFXRECON_DECODE_VULKAN_DECODER_BASE_H

#include "decode/api_decoder.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <algorithm>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanDecoderBase : public ApiDecoder
{
  public:
    VulkanDecoderBase() {}

    virtual ~VulkanDecoderBase() override {}

    void AddConsumer(VulkanConsumer* consumer) { consumers_.push_back(consumer); }

    void RemoveConsumer(VulkanConsumer* consumer)
    {
        consumers_.erase(std::remove(consumers_.begin(), consumers_.end(), consumer));
    }

    virtual void WaitIdle() override;

    virtual bool SupportsApiCall(format::ApiCallId call_id) override
    {
        return (format::GetApiCallFamily(call_id) == format::ApiFamilyId::ApiFamily_Vulkan);
    }

    virtual bool SupportsMetaDataId(format::MetaDataId meta_data_id) override
    {
        // For backwards compatibility, an encoded API of ApiFamily_None indicates the Vulkan API.
        format::ApiFamilyId api = format::GetMetaDataApi(meta_data_id);
        return (api == format::ApiFamilyId::ApiFamily_None) || (api == format::ApiFamilyId::ApiFamily_Vulkan);
    }

    virtual void DecodeFunctionCall(format::ApiCallId  call_id,
                                    const ApiCallInfo& call_options,
                                    const uint8_t*     parameter_buffer,
                                    size_t             buffer_size) override;

    virtual void DispatchStateBeginMarker(uint64_t frame_number) override;

    virtual void DispatchStateEndMarker(uint64_t frame_number) override;

    virtual void DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message) override;

    virtual void DispatchFillMemoryCommand(
        format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void DispatchResizeWindowCommand(format::ThreadId thread_id,
                                             format::HandleId surface_id,
                                             uint32_t         width,
                                             uint32_t         height) override;

    virtual void DispatchResizeWindowCommand2(format::ThreadId thread_id,
                                              format::HandleId surface_id,
                                              uint32_t         width,
                                              uint32_t         height,
                                              uint32_t         pre_transform) override;

    virtual void
    DispatchCreateHardwareBufferCommand(format::ThreadId                                    thread_id,
                                        format::HandleId                                    memory_id,
                                        uint64_t                                            buffer_id,
                                        uint32_t                                            format,
                                        uint32_t                                            width,
                                        uint32_t                                            height,
                                        uint32_t                                            stride,
                                        uint32_t                                            usage,
                                        uint32_t                                            layers,
                                        const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override;

    virtual void DispatchDestroyHardwareBufferCommand(format::ThreadId thread_id, uint64_t buffer_id) override;

    virtual void DispatchSetDevicePropertiesCommand(format::ThreadId   thread_id,
                                                    format::HandleId   physical_device_id,
                                                    uint32_t           api_version,
                                                    uint32_t           driver_version,
                                                    uint32_t           vendor_id,
                                                    uint32_t           device_id,
                                                    uint32_t           device_type,
                                                    const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                    const std::string& device_name) override;

    virtual void
    DispatchSetDeviceMemoryPropertiesCommand(format::ThreadId                             thread_id,
                                             format::HandleId                             physical_device_id,
                                             const std::vector<format::DeviceMemoryType>& memory_types,
                                             const std::vector<format::DeviceMemoryHeap>& memory_heaps) override;

    virtual void DispatchSetOpaqueAddressCommand(format::ThreadId thread_id,
                                                 format::HandleId device_id,
                                                 format::HandleId object_id,
                                                 uint64_t         address) override;

    virtual void DispatchSetRayTracingShaderGroupHandlesCommand(format::ThreadId thread_id,
                                                                format::HandleId device_id,
                                                                format::HandleId pipeline_id,
                                                                size_t           data_size,
                                                                const uint8_t*   data) override;

    virtual void
    DispatchSetSwapchainImageStateCommand(format::ThreadId                                    thread_id,
                                          format::HandleId                                    device_id,
                                          format::HandleId                                    swapchain_id,
                                          uint32_t                                            last_presented_image,
                                          const std::vector<format::SwapchainImageStateInfo>& image_state) override;

    virtual void DispatchBeginResourceInitCommand(format::ThreadId thread_id,
                                                  format::HandleId device_id,
                                                  uint64_t         max_resource_size,
                                                  uint64_t         max_copy_size) override;

    virtual void DispatchEndResourceInitCommand(format::ThreadId thread_id, format::HandleId device_id) override;

    virtual void DispatchInitBufferCommand(format::ThreadId thread_id,
                                           format::HandleId device_id,
                                           format::HandleId buffer_id,
                                           uint64_t         data_size,
                                           const uint8_t*   data) override;

    virtual void DispatchInitImageCommand(format::ThreadId             thread_id,
                                          format::HandleId             device_id,
                                          format::HandleId             image_id,
                                          uint64_t                     data_size,
                                          uint32_t                     aspect,
                                          uint32_t                     layout,
                                          const std::vector<uint64_t>& level_sizes,
                                          const uint8_t*               data) override;

  protected:
    const std::vector<VulkanConsumer*>& GetConsumers() const { return consumers_; }

  private:
    size_t Decode_vkUpdateDescriptorSetWithTemplate(const ApiCallInfo& call_info,
                                                    const uint8_t*     parameter_buffer,
                                                    size_t             buffer_size);

    size_t Decode_vkCmdPushDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                        const uint8_t*     parameter_buffer,
                                                        size_t             buffer_size);

    size_t Decode_vkUpdateDescriptorSetWithTemplateKHR(const ApiCallInfo& call_info,
                                                       const uint8_t*     parameter_buffer,
                                                       size_t             buffer_size);

  private:
    std::vector<VulkanConsumer*> consumers_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_DECODER_BASE_H
