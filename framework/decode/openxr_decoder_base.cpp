/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#if ENABLE_OPENXR_SUPPORT

#include "decode/openxr_decoder_base.h"

#include "decode/descriptor_update_template_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/value_decoder.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void OpenXrDecoderBase::WaitIdle()
{
    for (auto consumer : consumers_)
    {
        consumer->WaitDevicesIdle();
    }
}

void OpenXrDecoderBase::DispatchStateBeginMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessStateBeginMarker(frame_number);
    }
}

void OpenXrDecoderBase::DispatchStateEndMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessStateEndMarker(frame_number);
    }
}

void OpenXrDecoderBase::DispatchFrameEndMarker(uint64_t frame_number)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFrameEndMarker(frame_number);
    }
}

void OpenXrDecoderBase::DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message)
{
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);

    for (auto consumer : consumers_)
    {
        consumer->ProcessDisplayMessageCommand(message);
    }
}

void OpenXrDecoderBase::SetCurrentBlockIndex(uint64_t block_index)
{
    for (auto consumer : consumers_)
    {
        consumer->SetCurrentBlockIndex(block_index);
    }
}

size_t OpenXrDecoderBase::Decode_xrEnumerateSwapchainImages(const ApiCallInfo& call_info,
                                                            const uint8_t*     parameter_buffer,
                                                            size_t             buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                                          swapchain;
    uint32_t                                                  imageCapacityInput;
    PointerDecoder<uint32_t>                                  imageCountOutput;
    StructPointerDecoder<Decoded_XrSwapchainImageOpenGLKHR>   opengl_images;
    StructPointerDecoder<Decoded_XrSwapchainImageVulkanKHR>   vulkan_images;
    StructPointerDecoder<Decoded_XrSwapchainImageD3D11KHR>    d3d11_images;
    StructPointerDecoder<Decoded_XrSwapchainImageD3D12KHR>    d3d12_images;
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>  base_images;
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* image_ptr;
    XrResult                                                  return_value;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageCapacityInput);
    bytes_read += imageCountOutput.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    bool     is_null    = false;
    bool     is_struct  = false;
    bool     has_length = false;
    size_t   length{};
    uint32_t structure_type = 0;
    if (PointerDecoderBase::PeekAttributesAndType((parameter_buffer + bytes_read),
                                                  (buffer_size - bytes_read),
                                                  is_null,
                                                  is_struct,
                                                  has_length,
                                                  length,
                                                  structure_type))
    {
        XrStructureType xr_type = static_cast<XrStructureType>(structure_type);
        switch (xr_type)
        {
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
            {
                assert(!is_null && is_struct && has_length);
                bytes_read += opengl_images.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                image_ptr = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>*>(&opengl_images);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            {
                assert(!is_null && is_struct && has_length);
                bytes_read += vulkan_images.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                image_ptr = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>*>(&vulkan_images);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
            {
                assert(!is_null && is_struct && has_length);
                bytes_read += d3d11_images.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                image_ptr = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>*>(&d3d11_images);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
            {
                assert(!is_null && is_struct && has_length);
                bytes_read += d3d12_images.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                image_ptr = reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>*>(&d3d12_images);
                break;
            }
            default:
            {
                bytes_read += base_images.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
                image_ptr = &base_images;
                break;
            }
        }
    }
    bytes_read +=
        ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_xrEnumerateSwapchainImages(
            call_info, return_value, swapchain, imageCapacityInput, &imageCountOutput, image_ptr);
    }

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
