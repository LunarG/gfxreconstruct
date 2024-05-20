/*
** Copyright (c) 2022-2024 LunarG, Inc.
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

#include "decode/openxr_json_consumer_base.h"
#include "decode/custom_openxr_struct_to_json.h"

#include "util/json_util.h"
#include "util/platform.h"
#include "util/file_path.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using namespace util::platform;
using util::JsonOptions;
using util::uuid_to_string;

OpenXrExportJsonConsumerBase::OpenXrExportJsonConsumerBase() {}

OpenXrExportJsonConsumerBase::~OpenXrExportJsonConsumerBase()
{
    Destroy();
}

void OpenXrExportJsonConsumerBase::Initialize(JsonWriter* writer, const std::string_view openxrVersion)
{
    GFXRECON_ASSERT(writer);
    writer_ = writer;

    writer->GetHeaderJson()["openxr-version"] = std::string(openxrVersion);
}

void OpenXrExportJsonConsumerBase::Destroy()
{
    if (writer_)
    {
        writer_->Destroy();
    }
}

std::string OpenXrExportJsonConsumerBase::GenerateFilename(const std::string& filename)
{
    return writer_->GenerateFilename(filename);
}

bool OpenXrExportJsonConsumerBase::WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data)
{
    return writer_->WriteBinaryFile(filename, data_size, data);
}

void OpenXrExportJsonConsumerBase::Process_xrEnumerateSwapchainImages(
    const ApiCallInfo&                                        call_info,
    XrResult                                                  returnValue,
    format::HandleId                                          swapchain,
    uint32_t                                                  imageCapacityInput,
    PointerDecoder<uint32_t>*                                 imageCountOutput,
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images)
{
    nlohmann::ordered_json& jdata        = WriteApiCallStart(call_info, "xrEnumerateSwapchainImages");
    const JsonOptions&      json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
    HandleToJson(args["swapchain"], swapchain, json_options);
    FieldToJson(args["imageCapacityInput"], imageCapacityInput, json_options);
    FieldToJson(args["imageCountOutput"], imageCountOutput, json_options);
    if (images != nullptr && images->GetPointer() != nullptr && images->GetLength() >= 1)
    {
        XrSwapchainImageBaseHeader* header = images->GetPointer();
        switch (header->type)
        {
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
            {
                FieldToJson(args["images"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageOpenGLKHR>*>(images),
                            json_options);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            {
                FieldToJson(args["images"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageVulkanKHR>*>(images),
                            json_options);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
            {
                FieldToJson(args["images"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageD3D11KHR>*>(images),
                            json_options);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
            {
                FieldToJson(args["images"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageD3D12KHR>*>(images),
                            json_options);
                break;
            }
            default:
            {
                FieldToJson(args["images"], images, json_options);
                break;
            }
        }
    }
    else
    {
        FieldToJson(args["images"], images, json_options);
    }
    WriteBlockEnd();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
