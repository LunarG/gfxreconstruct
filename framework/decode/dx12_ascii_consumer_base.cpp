/*
** Copyright (c) 2021-2023 LunarG, Inc.
** Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
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

#include "decode/dx12_ascii_consumer_base.h"
#include "decode/custom_dx12_ascii_consumer.h"
#include "decode/dx12_enum_util.h"
#include "util/interception/injection.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

Dx12AsciiConsumerBase::Dx12AsciiConsumerBase() : file_(nullptr), current_frame_number_(0) {}

Dx12AsciiConsumerBase::~Dx12AsciiConsumerBase()
{
    Destroy();
}

void Dx12AsciiConsumerBase::Initialize(FILE* file, gfxrecon::util::ToStringFlags toStringFlags)
{
    assert(file);
    file_            = file;
    to_string_flags_ = toStringFlags;
    // Note the Vulkan Consumer will top and tail the file with
    // a JSON array if output is not JSONL.
}

void Dx12AsciiConsumerBase::Destroy()
{
    if (file_)
    {
        file_ = nullptr;
    }
}

void Dx12AsciiConsumerBase::Process_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                                     HRESULT          original_result,
                                                                     D3D12_FEATURE    feature,
                                                                     const void*      pCaptureFeatureSupportData,
                                                                     void*            pReplayFeatureSupportData,
                                                                     UINT             FeatureSupportDataSize)
{
    // clang-format off
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckFeatureSupport";
    auto returnValue = ToString(original_result, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            #if 0
            FieldToString(str_strm, true, "feature", to_string_flags_, tab_count, tab_size, ToString(feature, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "FeatureSupportDataSize", to_string_flags_, tab_count, tab_size, ToString(FeatureSupportDataSize, to_string_flags_, tab_count, tab_size));
            switch (feature)
            {
            case D3D12_FEATURE_D3D12_OPTIONS:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_ARCHITECTURE:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_ARCHITECTURE*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_ARCHITECTURE*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_FEATURE_LEVELS:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_FEATURE_LEVELS*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_FEATURE_LEVELS*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_FORMAT_SUPPORT:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_FORMAT_SUPPORT*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_FORMAT_SUPPORT*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_FORMAT_INFO:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_FORMAT_INFO*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_FORMAT_INFO*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_SHADER_MODEL:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_SHADER_MODEL*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_SHADER_MODEL*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS1:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS1*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS1*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_SUPPORT:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_ROOT_SIGNATURE:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_ROOT_SIGNATURE*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_ROOT_SIGNATURE*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_ARCHITECTURE1:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_ARCHITECTURE1*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_ARCHITECTURE1*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS2:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS2*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS2*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_SHADER_CACHE:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_SHADER_CACHE*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_SHADER_CACHE*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_COMMAND_QUEUE_PRIORITY:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS3:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS3*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS3*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_EXISTING_HEAPS:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_EXISTING_HEAPS*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_EXISTING_HEAPS*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS4:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS4*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS4*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_SERIALIZATION:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_SERIALIZATION*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_SERIALIZATION*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_CROSS_NODE:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_CROSS_NODE*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_CROSS_NODE*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS5:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS5*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS5*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS6:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS6*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS6*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_QUERY_META_COMMAND:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_QUERY_META_COMMAND*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_QUERY_META_COMMAND*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS7:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS7*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_D3D12_OPTIONS7*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPE_COUNT:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPES:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            default:
            {
            } break;
            }
            #endif
        }
    );
    // clang-format on
}

void Dx12AsciiConsumerBase::Process_IDXGIFactory5_CheckFeatureSupport(format::HandleId object_id,
                                                                      HRESULT          original_result,
                                                                      DXGI_FEATURE     feature,
                                                                      const void*      pCaptureFeatureSupportData,
                                                                      void*            pReplayFeatureSupportData,
                                                                      UINT             FeatureSupportDataSize)
{
    // clang-format off
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "IDXGIFactory5";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckFeatureSupport";
    auto returnValue = ToString(original_result, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            #if 0
            FieldToString(str_strm, true, "feature", to_string_flags_, tab_count, tab_size, ToString(feature, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "FeatureSupportDataSize", to_string_flags_, tab_count, tab_size, ToString(FeatureSupportDataSize, to_string_flags_, tab_count, tab_size));
            switch (feature)
            {
            case DXGI_FEATURE_PRESENT_ALLOW_TEARING:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const BOOL*>(pCaptureFeatureSupportData);
                const auto& replayFeatureSupportData = *reinterpret_cast<const BOOL*>(pReplayFeatureSupportData);
                FieldToString(str_strm, false, "pCaptureFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
                FieldToString(str_strm, false, "pReplayFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(replayFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            default:
            {
            } break;
            }
            #endif
        }
    );
    // clang-format on
}

void Dx12AsciiConsumerBase::Process_ID3D12Resource_WriteToSubresource(format::HandleId object_id,
                                                                      HRESULT          return_value,
                                                                      UINT             DstSubresource,
                                                                      StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
                                                                      void*                                    pSrcData,
                                                                      UINT SrcRowPitch,
                                                                      UINT SrcDepthPitch)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D12Resource";
    writeApiCallToFileInfo.handleId        = object_id;
    writeApiCallToFileInfo.pFunctionName   = "WriteToSubresource";
    std::string returnValue                = ToString(return_value);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm,
                      true,
                      "DstSubresource",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(DstSubresource, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "pDstBox",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pDstBox, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm, false, "pSrcData", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcData));
        FieldToString(str_strm,
                      false,
                      "SrcRowPitch",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(SrcRowPitch, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "SrcDepthPitch",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(SrcDepthPitch, to_string_flags_, tab_count, tab_size));
    });
}

void Dx12AsciiConsumerBase::Process_ID3D11Device_CheckFeatureSupport(const ApiCallInfo& call_info,
                                                                     format::HandleId   object_id,
                                                                     HRESULT            return_value,
                                                                     D3D11_FEATURE      feature,
                                                                     const void*        capture_feature_data,
                                                                     void*              replay_feature_data,
                                                                     UINT               feature_data_size)
{
    // TODO: When used with the replay consumer, this layer could report both the feature data from capture and replay,
    // but there needs to be a way to determine if replay_feature_data contains valid data. Normally, the consumer would
    // allocate the replay memory, making it nullptr when no other active consumer has allocated it, but for this API
    // call the memory is allocated by the decoder and replay_feature_data is never nullptr.
    GFXRECON_UNREFERENCED_PARAMETER(replay_feature_data);

    // clang-format off
    using namespace gfxrecon::util;
    uint32_t tab_count = 0;
    uint32_t tab_size = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D11Device";
    writeApiCallToFileInfo.handleId = object_id;
    writeApiCallToFileInfo.pFunctionName = "CheckFeatureSupport";
    auto returnValue = ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size,
        [&](std::stringstream& str_strm)
        {
            FieldToString(str_strm, true, "Feature", to_string_flags_, tab_count, tab_size, ToString(feature, to_string_flags_, tab_count, tab_size));
            FieldToString(str_strm, false, "FeatureSupportDataSize", to_string_flags_, tab_count, tab_size, ToString(feature_data_size, to_string_flags_, tab_count, tab_size));
            switch (feature)
            {
            case D3D11_FEATURE_THREADING:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_THREADING*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_DOUBLES:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_DOUBLES*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_FORMAT_SUPPORT:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_FORMAT_SUPPORT*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_FORMAT_SUPPORT2:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_FORMAT_SUPPORT2*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D10_X_HARDWARE_OPTIONS:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D11_OPTIONS:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D11_OPTIONS*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_ARCHITECTURE_INFO:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_ARCHITECTURE_INFO*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D9_OPTIONS:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D9_OPTIONS*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_SHADER_MIN_PRECISION_SUPPORT:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D9_SHADOW_SUPPORT:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D11_OPTIONS1:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D11_OPTIONS1*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D9_SIMPLE_INSTANCING_SUPPORT:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_MARKER_SUPPORT:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_MARKER_SUPPORT*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D9_OPTIONS1:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D9_OPTIONS1*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D11_OPTIONS2:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D11_OPTIONS2*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D11_OPTIONS3:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D11_OPTIONS3*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D11_OPTIONS4:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D11_OPTIONS4*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_SHADER_CACHE:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_SHADER_CACHE*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            case D3D11_FEATURE_D3D11_OPTIONS5:
            {
                const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_D3D11_OPTIONS5*>(capture_feature_data);
                FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            }
            break;
            // TODO: This requires code generated from the 10.0.22000.194 Windows SDK
            //case D3D11_FEATURE_DISPLAYABLE:
            //{
            //    const auto& captureFeatureSupportData = *reinterpret_cast<const D3D11_FEATURE_DATA_DISPLAYABLE*>(capture_feature_data);
            //    FieldToString(str_strm, false, "pFeatureSupportData", to_string_flags_, tab_count, tab_size, ToString(captureFeatureSupportData, to_string_flags_, tab_count, tab_size));
            //}
            //break;
            default:
            break;
            }
        }
    );
    // clang-format on
}

void Dx12AsciiConsumerBase::Process_ID3D11Device_CreateBuffer(
    const ApiCallInfo&                                    call_info,
    format::HandleId                                      object_id,
    HRESULT                                               return_value,
    StructPointerDecoder<Decoded_D3D11_BUFFER_DESC>*      pDesc,
    StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
    HandlePointerDecoder<ID3D11Buffer*>*                  ppBuffer)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D11Device";
    writeApiCallToFileInfo.handleId        = object_id;
    writeApiCallToFileInfo.pFunctionName   = "CreateBuffer";
    std::string returnValue                = ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm,
                      true,
                      "pDesc",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "pInitialData",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pInitialData, to_string_flags_, tab_count, tab_size));
        FieldToString(
            str_strm, false, "[out]ppBuffer", to_string_flags_, tab_count, tab_size, OutPtrDecoderToString(ppBuffer));
    });
}

void Dx12AsciiConsumerBase::Process_ID3D11Device_CreateTexture1D(
    const ApiCallInfo&                                    call_info,
    format::HandleId                                      object_id,
    HRESULT                                               return_value,
    StructPointerDecoder<Decoded_D3D11_TEXTURE1D_DESC>*   pDesc,
    StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
    HandlePointerDecoder<ID3D11Texture1D*>*               ppTexture1D)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D11Device";
    writeApiCallToFileInfo.handleId        = object_id;
    writeApiCallToFileInfo.pFunctionName   = "CreateTexture1D";
    std::string returnValue                = ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm,
                      true,
                      "pDesc",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "pInitialData",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pInitialData, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "[out]ppTexture1D",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      OutPtrDecoderToString(ppTexture1D));
    });
}

void Dx12AsciiConsumerBase::Process_ID3D11Device_CreateTexture2D(
    const ApiCallInfo&                                    call_info,
    format::HandleId                                      object_id,
    HRESULT                                               return_value,
    StructPointerDecoder<Decoded_D3D11_TEXTURE2D_DESC>*   pDesc,
    StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
    HandlePointerDecoder<ID3D11Texture2D*>*               ppTexture2D)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D11Device";
    writeApiCallToFileInfo.handleId        = object_id;
    writeApiCallToFileInfo.pFunctionName   = "CreateTexture2D";
    std::string returnValue                = ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm,
                      true,
                      "pDesc",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "pInitialData",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pInitialData, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "[out]ppTexture2D",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      OutPtrDecoderToString(ppTexture2D));
    });
}

void Dx12AsciiConsumerBase::Process_ID3D11Device_CreateTexture3D(
    const ApiCallInfo&                                    call_info,
    format::HandleId                                      object_id,
    HRESULT                                               return_value,
    StructPointerDecoder<Decoded_D3D11_TEXTURE3D_DESC>*   pDesc,
    StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
    HandlePointerDecoder<ID3D11Texture3D*>*               ppTexture3D)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D11Device";
    writeApiCallToFileInfo.handleId        = object_id;
    writeApiCallToFileInfo.pFunctionName   = "CreateTexture3D";
    std::string returnValue                = ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm,
                      true,
                      "pDesc",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "pInitialData",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pInitialData, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "[out]ppTexture3D",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      OutPtrDecoderToString(ppTexture3D));
    });
}

void Dx12AsciiConsumerBase::Process_ID3D11DeviceContext_UpdateSubresource(
    const ApiCallInfo&                       call_info,
    format::HandleId                         object_id,
    format::HandleId                         pDstResource,
    UINT                                     DstSubresource,
    StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
    PointerDecoder<uint8_t>*                 pSrcData,
    UINT                                     SrcRowPitch,
    UINT                                     SrcDepthPitch)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D11DeviceContext";
    writeApiCallToFileInfo.handleId        = object_id;
    writeApiCallToFileInfo.pFunctionName   = "UpdateSubresource";
    std::string returnValue                = std::string();
    writeApiCallToFileInfo.pReturnValue    = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(
            str_strm, true, "pDstResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstResource));
        FieldToString(str_strm,
                      false,
                      "DstSubresource",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(DstSubresource, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "pDstBox",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pDstBox, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm, false, "pSrcData", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcData));
        FieldToString(str_strm,
                      false,
                      "SrcRowPitch",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(SrcRowPitch, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "SrcDepthPitch",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(SrcDepthPitch, to_string_flags_, tab_count, tab_size));
    });
}

void Dx12AsciiConsumerBase::Process_ID3D11DeviceContext1_UpdateSubresource1(
    const ApiCallInfo&                       call_info,
    format::HandleId                         object_id,
    format::HandleId                         pDstResource,
    UINT                                     DstSubresource,
    StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
    PointerDecoder<uint8_t>*                 pSrcData,
    UINT                                     SrcRowPitch,
    UINT                                     SrcDepthPitch,
    UINT                                     CopyFlags)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D11DeviceContext1";
    writeApiCallToFileInfo.handleId        = object_id;
    writeApiCallToFileInfo.pFunctionName   = "UpdateSubresource1";
    std::string returnValue                = std::string();
    writeApiCallToFileInfo.pReturnValue    = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(
            str_strm, true, "pDstResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstResource));
        FieldToString(str_strm,
                      false,
                      "DstSubresource",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(DstSubresource, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "pDstBox",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pDstBox, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm, false, "pSrcData", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcData));
        FieldToString(str_strm,
                      false,
                      "SrcRowPitch",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(SrcRowPitch, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "SrcDepthPitch",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(SrcDepthPitch, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "CopyFlags",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(CopyFlags, to_string_flags_, tab_count, tab_size));
    });
}

void Dx12AsciiConsumerBase::Process_ID3D11Device3_CreateTexture2D1(
    const ApiCallInfo&                                    call_info,
    format::HandleId                                      object_id,
    HRESULT                                               return_value,
    StructPointerDecoder<Decoded_D3D11_TEXTURE2D_DESC1>*  pDesc,
    StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
    HandlePointerDecoder<ID3D11Texture2D1*>*              ppTexture2D)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D11Device3";
    writeApiCallToFileInfo.handleId        = object_id;
    writeApiCallToFileInfo.pFunctionName   = "CreateTexture2D1";
    std::string returnValue                = ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue    = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm,
                      true,
                      "pDesc",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "pInitialData",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pInitialData, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "[out]ppTexture2D",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      OutPtrDecoderToString(ppTexture2D));
    });
}

void Dx12AsciiConsumerBase::Process_ID3D11Device3_CreateTexture3D1(
    const ApiCallInfo&                                    call_info,
    format::HandleId                                      object_id,
    HRESULT                                               return_value,
    StructPointerDecoder<Decoded_D3D11_TEXTURE3D_DESC1>*  pDesc,
    StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
    HandlePointerDecoder<ID3D11Texture3D1*>*              ppTexture3D)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D11Device3";
    writeApiCallToFileInfo.handleId        = object_id;
    writeApiCallToFileInfo.pFunctionName   = "CreateTexture3D1";
    std::string returnValue                = ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue    = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm,
                      true,
                      "pDesc",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pDesc, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "pInitialData",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pInitialData, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "[out]ppTexture3D",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      OutPtrDecoderToString(ppTexture3D));
    });
}

void Dx12AsciiConsumerBase::Process_ID3D11Device3_WriteToSubresource(const ApiCallInfo& call_info,
                                                                     format::HandleId   object_id,
                                                                     format::HandleId   pDstResource,
                                                                     UINT               DstSubresource,
                                                                     StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                                     PointerDecoder<uint8_t>*                 pSrcData,
                                                                     UINT SrcRowPitch,
                                                                     UINT SrcDepthPitch)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteApiCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.pObjectTypeName = "ID3D11Device3";
    writeApiCallToFileInfo.handleId        = object_id;
    writeApiCallToFileInfo.pFunctionName   = "WriteToSubresource";
    std::string returnValue                = std::string();
    writeApiCallToFileInfo.pReturnValue    = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(
            str_strm, true, "pDstResource", to_string_flags_, tab_count, tab_size, HandleIdToString(pDstResource));
        FieldToString(str_strm,
                      false,
                      "DstSubresource",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(DstSubresource, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "pDstBox",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      StructPointerDecoderToString(pDstBox, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm, false, "pSrcData", to_string_flags_, tab_count, tab_size, HandleIdToString(pSrcData));
        FieldToString(str_strm,
                      false,
                      "SrcRowPitch",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(SrcRowPitch, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "SrcDepthPitch",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(SrcDepthPitch, to_string_flags_, tab_count, tab_size));
    });
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
