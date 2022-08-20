/*
** Copyright (c) 2021 LunarG, Inc.
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
    file_ = file;
    if (to_string_flags_ & gfxrecon::util::kToString_Formatted)
    {
        fprintf(file_, "{\n\"apiCalls\":[");
    }
}

void Dx12AsciiConsumerBase::Destroy()
{
    if (file_)
    {
        if (to_string_flags_ & gfxrecon::util::kToString_Formatted)
        {
            fprintf(file_, "\n]\n}\n");
        }
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
    std::string returnValue             = DX12ReturnValueToString(return_value, to_string_flags_, tab_count, tab_size);
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
