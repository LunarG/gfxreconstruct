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
#include "generated/generated_dx12_convert_to_texts.h"
#include "decode/custom_dx12_struct_ascii_consumers.h"
#include "decode/dx12_enum_util.h"
#include "util/interception/injection.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

Dx12AsciiConsumerBase::Dx12AsciiConsumerBase() : m_file(nullptr), current_frame_number_(0) {}

Dx12AsciiConsumerBase::~Dx12AsciiConsumerBase()
{
    Destroy();
}

void Dx12AsciiConsumerBase::Initialize(const std::string& filename, FILE* file)
{
    m_filename = filename;
    m_file     = file;
}

void Dx12AsciiConsumerBase::Destroy()
{
    m_file = nullptr;
}

void Dx12AsciiConsumerBase::Process_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                                     HRESULT          original_result,
                                                                     D3D12_FEATURE    feature,
                                                                     const void*      capture_feature_data,
                                                                     void*            replay_feature_data,
                                                                     UINT             feature_data_size)
{
    const char*        indent = "    ";
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CheckFeatureSupport(\n" << indent << "/* ";

    oss << "return = " << enumutil::GetResultValueString(original_result);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << indent << ConverttoText(feature);
    oss << ",\n";

    if (WriteCheckNull(oss, replay_feature_data, indent, false))
    {
        switch (feature)
        {
            case D3D12_FEATURE_D3D12_OPTIONS:
            {
                Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_ARCHITECTURE:
            {
                Decoded_D3D12_FEATURE_DATA_ARCHITECTURE value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_ARCHITECTURE*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_FEATURE_LEVELS:
            {
                Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_FEATURE_LEVELS*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_FORMAT_SUPPORT:
            {
                Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_FORMAT_SUPPORT*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS:
            {
                Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS value;
                value.decoded_value =
                    reinterpret_cast<D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_FORMAT_INFO:
            {
                Decoded_D3D12_FEATURE_DATA_FORMAT_INFO value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_FORMAT_INFO*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT:
            {
                Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT value;
                value.decoded_value =
                    reinterpret_cast<D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_SHADER_MODEL:
            {
                Decoded_D3D12_FEATURE_DATA_SHADER_MODEL value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_SHADER_MODEL*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS1:
            {
                Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1 value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS1*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_SUPPORT:
            {
                Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT value;
                value.decoded_value =
                    reinterpret_cast<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_ROOT_SIGNATURE:
            {
                Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_ROOT_SIGNATURE*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_ARCHITECTURE1:
            {
                Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1 value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_ARCHITECTURE1*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS2:
            {
                Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2 value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS2*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_SHADER_CACHE:
            {
                Decoded_D3D12_FEATURE_DATA_SHADER_CACHE value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_SHADER_CACHE*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_COMMAND_QUEUE_PRIORITY:
            {
                Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS3:
            {
                Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3 value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS3*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_EXISTING_HEAPS:
            {
                Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_EXISTING_HEAPS*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS4:
            {
                Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4 value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS4*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_SERIALIZATION:
            {
                Decoded_D3D12_FEATURE_DATA_SERIALIZATION value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_SERIALIZATION*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_CROSS_NODE:
            {
                Decoded_D3D12_FEATURE_DATA_CROSS_NODE value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_CROSS_NODE*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS5:
            {
                Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5 value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS5*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS6:
            {
                Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6 value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS6*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_QUERY_META_COMMAND:
            {
                Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_QUERY_META_COMMAND*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_D3D12_OPTIONS7:
            {
                Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7 value;
                value.decoded_value = reinterpret_cast<D3D12_FEATURE_DATA_D3D12_OPTIONS7*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPE_COUNT:
            {
                Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT value;
                value.decoded_value =
                    reinterpret_cast<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            case D3D12_FEATURE_PROTECTED_RESOURCE_SESSION_TYPES:
            {
                Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES value;
                value.decoded_value =
                    reinterpret_cast<D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES*>(replay_feature_data);
                WriteStructString(oss, &value, indent);
            }
            break;
            default:
                break;
        }
    }
    oss << ",\n";

    oss << indent << feature_data_size;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}

void Dx12AsciiConsumerBase::Process_IDXGIFactory5_CheckFeatureSupport(format::HandleId object_id,
                                                                      HRESULT          original_result,
                                                                      DXGI_FEATURE     feature,
                                                                      const void*      capture_feature_data,
                                                                      void*            replay_feature_data,
                                                                      UINT             feature_data_size)
{
    const char*        indent = "    ";
    std::ostringstream oss;
    oss << "IDXGIFactory5_id" << object_id << "->";
    oss << "CheckFeatureSupport(\n" << indent << "/* ";

    oss << "return = " << enumutil::GetResultValueString(original_result);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << indent << ConverttoText(feature);
    oss << ",\n";

    if (WriteCheckNull(oss, replay_feature_data, indent, false))
    {
        switch (feature)
        {
            case DXGI_FEATURE_PRESENT_ALLOW_TEARING:
            {
                WriteBOOLString(oss, *reinterpret_cast<BOOL*>(replay_feature_data), indent);
            }
            break;
            default:
                break;
        }
    }
    oss << ",\n";

    oss << indent << feature_data_size;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}

void Dx12AsciiConsumerBase::OverridePresent(format::HandleId object_id,
                                            HRESULT          return_value,
                                            UINT             SyncInterval,
                                            UINT             Flags)
{
    DumpPresentWithFrameNumber(object_id, return_value, SyncInterval, Flags, nullptr);
}

void Dx12AsciiConsumerBase::OverridePresent1(format::HandleId                                       object_id,
                                             HRESULT                                                return_value,
                                             UINT                                                   SyncInterval,
                                             UINT                                                   PresentFlags,
                                             StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* pPresentParameters)
{
    DumpPresentWithFrameNumber(object_id, return_value, SyncInterval, PresentFlags, pPresentParameters);
}

// TODO(#311): add thread ID information for all API call ascii dump.

void Dx12AsciiConsumerBase::DumpPresentWithFrameNumber(
    format::HandleId                                       object_id,
    HRESULT                                                return_value,
    UINT                                                   SyncInterval,
    UINT                                                   PresentFlags,
    StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* pPresentParameters)
{
    current_frame_number_++;

    std::ostringstream oss;
    oss << "Frame number: " << current_frame_number_ << "\n";

    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "Present1(\n    /* ";

    oss << "return = ";
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << SyncInterval;
    oss << ",\n";

    oss << "    " << PresentFlags;

    if (pPresentParameters)
    {
        oss << ",\n";

        if (WriteCheckPointerDecoderNull(oss, pPresentParameters, "    ", false))
        {
            WriteStructString(oss, pPresentParameters->GetMetaStructPointer(), "    ", false, false);
        }
        oss << ");\n\n";
    }

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
