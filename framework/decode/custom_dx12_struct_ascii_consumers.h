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

#ifndef GFXRECON_DECODE_CUSTOM_DX12_STRUCT_ASCII_CONSUMERS_H
#define GFXRECON_DECODE_CUSTOM_DX12_STRUCT_ASCII_CONSUMERS_H

#include "generated/generated_dx12_ascii_consumer.h"
#include "generated/generated_dx12_convert_to_texts.h"
#include "util/interception/injection.h"

#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void WriteBOOLString(std::ostringstream& oss, const BOOL value, const char* indent, const bool output = false);

void WriteStructString(std::ostringstream&                             oss,
                       const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* value,
                       const char*                                     indent,
                       const bool                                      prefix = false,
                       const bool                                      output = false);

void WriteStructString(std::ostringstream&              oss,
                       const Decoded_D3D12_CLEAR_VALUE* value,
                       const char*                      indent,
                       const bool                       prefix = false,
                       const bool                       output = false);

void WriteStructString(std::ostringstream&                   oss,
                       const Decoded_D3D12_RESOURCE_BARRIER* value,
                       const char*                           indent,
                       const bool                            prefix = false,
                       const bool                            output = false);

void WriteStructString(std::ostringstream&                        oss,
                       const Decoded_D3D12_TEXTURE_COPY_LOCATION* value,
                       const char*                                indent,
                       const bool                                 prefix = false,
                       const bool                                 output = false);

void WriteStructString(std::ostringstream&                            oss,
                       const Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* value,
                       const char*                                    indent,
                       const bool                                     prefix = false,
                       const bool                                     output = false);

void WriteStructString(std::ostringstream&                             oss,
                       const Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* value,
                       const char*                                     indent,
                       const bool                                      prefix = false,
                       const bool                                      output = false);

void WriteStructString(std::ostringstream&                          oss,
                       const Decoded_D3D12_RENDER_TARGET_VIEW_DESC* value,
                       const char*                                  indent,
                       const bool                                   prefix = false,
                       const bool                                   output = false);

void WriteStructString(std::ostringstream&                          oss,
                       const Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* value,
                       const char*                                  indent,
                       const bool                                   prefix = false,
                       const bool                                   output = false);

void WriteStructString(std::ostringstream&                 oss,
                       const Decoded_D3D12_ROOT_PARAMETER* value,
                       const char*                         indent,
                       const bool                          prefix = false,
                       const bool                          output = false);

void WriteStructString(std::ostringstream&                  oss,
                       const Decoded_D3D12_ROOT_PARAMETER1* value,
                       const char*                          indent,
                       const bool                           prefix = false,
                       const bool                           output = false);

void WriteStructString(std::ostringstream&                                oss,
                       const Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* value,
                       const char*                                        indent,
                       const bool                                         prefix = false,
                       const bool                                         output = false);

void WriteStructString(std::ostringstream&                        oss,
                       const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* value,
                       const char*                                indent,
                       const bool                                 prefix = false,
                       const bool                                 output = false);

void WriteStructString(std::ostringstream&                         oss,
                       const Decoded_D3D12_INDIRECT_ARGUMENT_DESC* value,
                       const char*                                 indent,
                       const bool                                  prefix = false,
                       const bool                                  output = false);

void WriteStructString(std::ostringstream&                  oss,
                       const Decoded_D3D12_STATE_SUBOBJECT* value,
                       const char*                          indent,
                       const bool                           prefix = false,
                       const bool                           output = false);

void WriteStructString(std::ostringstream&                                   oss,
                       const Decoded_D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION* value,
                       const char*                                           indent,
                       const bool                                            prefix = false,
                       const bool                                            output = false);

void WriteStructString(std::ostringstream&                    oss,
                       const Decoded_D3D12_STATE_OBJECT_DESC* value,
                       const char*                            indent,
                       const bool                             prefix = false,
                       const bool                             output = false);

void WriteStructString(std::ostringstream&                           oss,
                       const Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* value,
                       const char*                                   indent,
                       const bool                                    prefix = false,
                       const bool                                    output = false);

void WriteStructString(std::ostringstream&                                                 oss,
                       const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* value,
                       const char*                                                         indent,
                       const bool                                                          prefix = false,
                       const bool                                                          output = false);

void WriteStructString(std::ostringstream&                                         oss,
                       const Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* value,
                       const char*                                                 indent,
                       const bool                                                  prefix = false,
                       const bool                                                  output = false);

void WriteStructString(std::ostringstream&                               oss,
                       const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* value,
                       const char*                                       indent,
                       const bool                                        prefix = false,
                       const bool                                        output = false);

void WriteStructString(std::ostringstream&                            oss,
                       const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* value,
                       const char*                                    indent,
                       const bool                                     prefix = false,
                       const bool                                     output = false);

template <typename T>
static void WriteArrayStructsString(std::ostringstream&            oss,
                                    const StructPointerDecoder<T>* values,
                                    const char*                    indent,
                                    const bool                     output = false)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent << output_string << "[";
    const auto size = values->GetLength();

    for (size_t i = 0; i < size; ++i)
    {
        bool prefix = false;
        if (i == 0)
        {
            prefix = true;
        }
        const auto* decoded_value = values->GetMetaStructPointer();
        WriteStructString(oss, &decoded_value[i], indent2.c_str(), prefix);
        if (i < (size - 1))
        {
            oss << ",\n";
        }
    }
    oss << "]";
}

template <typename T>
static void WriteArrayStructsString(std::ostringstream&       oss,
                                    StructPointerDecoder<T*>* values,
                                    const char*               indent,
                                    const bool                output = false)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent << output_string << "[";
    const auto size = values->GetLength();

    for (size_t i = 0; i < size; ++i)
    {
        bool prefix = false;
        if (i == 0)
        {
            prefix = true;
        }
        auto decoded_value = values->GetMetaStructPointer();
        WriteStructString(oss, decoded_value[i], indent2.c_str(), prefix);
        if (i < (size - 1))
        {
            oss << ",\n";
        }
    }
    oss << "]";
}

template <typename T>
static void
WriteArrayValuesString(std::ostringstream& oss, const T* values, const char* indent, const bool output = false)
{
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent << output_string << "[";
    const auto  size        = values->GetLength();
    const auto* array_value = values->GetPointer();

    for (size_t i = 0; i < size; ++i)
    {
        std::string indent_array = indent;
        indent_array.append("    ");
        if (i == 0)
        {
            indent_array = "   ";
        }
        oss << indent_array << array_value[i];
        if (i < (size - 1))
        {
            oss << ",\n";
        }
    }
    oss << "]";
}

static void WriteArrayWStringsString(std::ostringstream&        oss,
                                     const WStringArrayDecoder* values,
                                     const char*                indent,
                                     const bool                 output = false)
{
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent << output_string << "[";
    const auto  size        = values->GetLength();
    const auto* array_value = values->GetPointer();

    for (size_t i = 0; i < size; ++i)
    {
        std::string indent_array = indent;
        indent_array.append("    ");
        if (i == 0)
        {
            indent_array = "   ";
        }
        oss << indent_array << "\"" << util::interception::WideStringToString(array_value[i]) << "\"";
        if (i < (size - 1))
        {
            oss << ",\n";
        }
    }
    oss << "]";
}

static void WriteArrayBOOLsString(std::ostringstream&         oss,
                                  const PointerDecoder<BOOL>* values,
                                  const char*                 indent,
                                  const bool                  output = false)
{
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent << output_string << "[";
    const auto  size        = values->GetLength();
    const auto* array_value = values->GetPointer();

    for (size_t i = 0; i < size; ++i)
    {
        std::string indent_array = indent;
        indent_array.append("    ");
        if (i == 0)
        {
            indent_array = "   ";
        }
        WriteBOOLString(oss, array_value[i], indent_array.c_str());
        if (i < (size - 1))
        {
            oss << ",\n";
        }
    }
    oss << "]";
}

template <typename T>
static void
WriteArrayConvertsString(std::ostringstream& oss, const T* values, const char* indent, const bool output = false)
{
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent << output_string << "[";
    const auto  size        = values->GetLength();
    const auto* array_value = values->GetPointer();

    for (size_t i = 0; i < size; ++i)
    {
        std::string indent_array = indent;
        indent_array.append("    ");
        if (i == 0)
        {
            indent_array = "   ";
        }
        oss << indent_array << ConverttoText(array_value[i]);
        if (i < (size - 1))
        {
            oss << ",\n";
        }
    }
    oss << "]";
}

template <typename T>
static void WriteArrayClassesString(std::ostringstream&             oss,
                                    const HandlePointerDecoder<T*>* values,
                                    const char*                     class_name,
                                    const char*                     indent,
                                    const bool                      output = false)
{
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent << output_string << "[";
    const auto  size        = values->GetLength();
    const auto* array_id    = values->GetPointer();
    const auto* array_value = values->GetHandlePointer();

    for (size_t i = 0; i < size; ++i)
    {
        std::string indent_array = indent;
        indent_array.append("    ");
        if (i == 0)
        {
            indent_array = "   ";
        }
        WriteHandleId(oss, array_id[i], indent_array.c_str(), class_name);
        if (i < (size - 1))
        {
            oss << ",\n";
        }
    }
    oss << "]";
}

template <typename T>
static bool
WriteCheckStructDecoderNull(std::ostringstream& oss, const T* value, const char* indent, const bool output = false)
{
    if (value == nullptr || !value->decoded_value)
    {
        std::string output_string = "";
        if (output)
        {
            output_string = "&";
        }
        oss << indent << output_string << "nullptr";
        return false;
    }
    return true;
}

template <typename T>
static bool
WriteCheckPointerDecoderNull(std::ostringstream& oss, const T* value, const char* indent, const bool output = false)
{
    if (value == nullptr || value->IsNull())
    {
        std::string output_string = "";
        if (output)
        {
            output_string = "&";
        }
        oss << indent << output_string << "nullptr";
        return false;
    }
    return true;
}

template <typename T>
static bool WriteCheckNull(std::ostringstream& oss, const T* value, const char* indent, const bool output = false)
{
    if (value == nullptr)
    {
        std::string output_string = "";
        if (output)
        {
            output_string = "&";
        }
        oss << indent << output_string << "nullptr";
        return false;
    }
    return true;
}

static bool WriteHandleId(
    std::ostringstream& oss, format::HandleId value, const char* indent, const char* type_name, const bool output = false)
{
    std::string output_string = "";
    if (output)
    {
        output_string = "&";
    }

    if (value == format::kNullHandleId)
    {
        oss << indent << output_string << "nullptr";
        return false;
    }

    oss << indent << output_string << type_name << "_id" << value;
    return true;
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_CUSTOM_DX12_STRUCT_ASCII_CONSUMERS_H
