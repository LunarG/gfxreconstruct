/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2025 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_API_DECODE_DECODER_H
#define GFXRECON_API_DECODE_DECODER_H

#include "format/api_call_id.h"
#include "format/format.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct ApiCallInfo
{
    /// The block index of a function call. Stream processors like FileProcessor
    /// must set this before dispatching function calls to decoders.
    /// @note This is lightly used: only for a log output in replay and for JSON
    /// Convert.
    /// @see ApiDecoder::SetCurrentBlockIndex() which can pass the block index
    /// to decoders so it is available for any block type, not just API calls.
    uint64_t index{ 0 };

    /// Thread id of captured function call.
    format::ThreadId thread_id{ 0 };
};

class ApiDecoder
{
  public:
    virtual ~ApiDecoder() {}

    virtual void WaitIdle() = 0;

    virtual bool IsComplete(uint64_t block_index) = 0;

    virtual bool SupportsApiCall(format::ApiCallId id) = 0;

    virtual bool SupportsMetaDataId(format::MetaDataId meta_data_id) = 0;

    virtual void DecodeFunctionCall(format::ApiCallId  id,
                                    const ApiCallInfo& call_info,
                                    const uint8_t*     buffer,
                                    size_t             buffer_size) = 0;

    virtual void DecodeMethodCall(format::ApiCallId  call_id,
                                  format::HandleId   object_id,
                                  const ApiCallInfo& call_options,
                                  const uint8_t*     parameter_buffer,
                                  size_t             buffer_size)
    {}

    virtual void DispatchStateBeginMarker(uint64_t frame_number) = 0;

    virtual void DispatchStateEndMarker(uint64_t frame_number) = 0;

    virtual void DispatchFrameEndMarker(uint64_t frame_number) = 0;

    virtual void DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message) = 0;

    virtual void DispatchDriverInfo(format::ThreadId thread_id, format::DriverInfoBlock& info) = 0;

    virtual void DispatchExeFileInfo(format::ThreadId thread_id, format::ExeFileInfoBlock& info) = 0;

    virtual void DispatchFillMemoryCommand(
        format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) = 0;

    virtual void
    DispatchFillMemoryResourceValueCommand(const format::FillMemoryResourceValueCommandHeader& command_header,
                                           const uint8_t*                                      data) = 0;

    virtual void DispatchResizeWindowCommand(format::ThreadId thread_id,
                                             format::HandleId surface_id,
                                             uint32_t         width,
                                             uint32_t         height) = 0;

    virtual void DispatchResizeWindowCommand2(format::ThreadId thread_id,
                                              format::HandleId surface_id,
                                              uint32_t         width,
                                              uint32_t         height,
                                              uint32_t         pre_transform) = 0;

    virtual void
    DispatchCreateHardwareBufferCommand(format::ThreadId                                    thread_id,
                                        format::HandleId                                    device_id,
                                        format::HandleId                                    memory_id,
                                        uint64_t                                            buffer_id,
                                        uint32_t                                            format,
                                        uint32_t                                            width,
                                        uint32_t                                            height,
                                        uint32_t                                            stride,
                                        uint64_t                                            usage,
                                        uint32_t                                            layers,
                                        const std::vector<format::HardwareBufferPlaneInfo>& plane_info) = 0;

    virtual void DispatchDestroyHardwareBufferCommand(format::ThreadId thread_id, uint64_t buffer_id) = 0;

    virtual void DispatchCreateHeapAllocationCommand(format::ThreadId thread_id,
                                                     uint64_t         allocation_id,
                                                     uint64_t         allocation_size) = 0;

    virtual void DispatchSetDevicePropertiesCommand(format::ThreadId   thread_id,
                                                    format::HandleId   physical_device_id,
                                                    uint32_t           api_version,
                                                    uint32_t           driver_version,
                                                    uint32_t           vendor_id,
                                                    uint32_t           device_id,
                                                    uint32_t           device_type,
                                                    const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                    const std::string& device_name) = 0;

    virtual void
    DispatchSetDeviceMemoryPropertiesCommand(format::ThreadId                             thread_id,
                                             format::HandleId                             physical_device_id,
                                             const std::vector<format::DeviceMemoryType>& memory_types,
                                             const std::vector<format::DeviceMemoryHeap>& memory_heaps) = 0;

    virtual void DispatchSetOpaqueAddressCommand(format::ThreadId thread_id,
                                                 format::HandleId device_id,
                                                 format::HandleId object_id,
                                                 uint64_t         address) = 0;

    virtual void DispatchSetRayTracingShaderGroupHandlesCommand(format::ThreadId thread_id,
                                                                format::HandleId device_id,
                                                                format::HandleId buffer_id,
                                                                size_t           data_size,
                                                                const uint8_t*   data) = 0;

    virtual void
    DispatchSetSwapchainImageStateCommand(format::ThreadId                                    thread_id,
                                          format::HandleId                                    device_id,
                                          format::HandleId                                    swapchain_id,
                                          uint32_t                                            last_presented_image,
                                          const std::vector<format::SwapchainImageStateInfo>& image_state) = 0;

    virtual void DispatchBeginResourceInitCommand(format::ThreadId thread_id,
                                                  format::HandleId device_id,
                                                  uint64_t         max_resource_size,
                                                  uint64_t         max_copy_size) = 0;

    virtual void DispatchEndResourceInitCommand(format::ThreadId thread_id, format::HandleId device_id) = 0;

    virtual void DispatchInitBufferCommand(format::ThreadId thread_id,
                                           format::HandleId device_id,
                                           format::HandleId buffer_id,
                                           uint64_t         data_size,
                                           const uint8_t*   data) = 0;

    virtual void DispatchInitImageCommand(format::ThreadId             thread_id,
                                          format::HandleId             device_id,
                                          format::HandleId             image_id,
                                          uint64_t                     data_size,
                                          uint32_t                     aspect,
                                          uint32_t                     layout,
                                          const std::vector<uint64_t>& level_sizes,
                                          const uint8_t*               data) = 0;

    virtual void DispatchInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                                const uint8_t*                              data) = 0;

    virtual void DispatchInitDx12AccelerationStructureCommand(
        const format::InitDx12AccelerationStructureCommandHeader&       command_header,
        std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
        const uint8_t*                                                  build_inputs_data) = 0;

    virtual void DispatchGetDxgiAdapterInfo(const format::DxgiAdapterInfoCommandHeader& adapter_info_header){};

    virtual void DispatchGetDx12RuntimeInfo(const format::Dx12RuntimeInfoCommandHeader& runtime_info_header){};

    virtual void DispatchExecuteBlocksFromFile(format::ThreadId   thread_id,
                                               uint32_t           n_blocks,
                                               int64_t            offset,
                                               const std::string& filename){};

    virtual void SetCurrentBlockIndex(uint64_t block_index){};

    // Expects zero-based frame_number to match the way FileProcessor::current_frame_number_ works
    virtual void SetCurrentFrameNumber(uint64_t frame_number){};

    virtual void SetCurrentApiCallId(format::ApiCallId api_call_id){};

    virtual void DispatchSetTlasToBlasDependencyCommand(format::HandleId                     tlas,
                                                        const std::vector<format::HandleId>& blases){};

    virtual void DispatchSetEnvironmentVariablesCommand(format::SetEnvironmentVariablesCommand& header,
                                                        const char*                             env_string){};

    virtual void DispatchVulkanAccelerationStructuresBuildMetaCommand(const uint8_t* parameter_buffer,
                                                                      size_t         buffer_size){};

    virtual void DispatchVulkanAccelerationStructuresCopyMetaCommand(const uint8_t* parameter_buffer,
                                                                     size_t         buffer_size){};

    virtual void DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand(const uint8_t* parameter_buffer,
                                                                                size_t         buffer_size){};

    virtual void DispatchViewRelativeLocation(format::ThreadId thread_id, format::ViewRelativeLocation& location){};

    virtual void DispatchInitializeMetaCommand(format::InitializeMetaCommand& header,
                                               const uint8_t*                 initialization_parameters_data){};
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_API_DECODE_DECODER_H
