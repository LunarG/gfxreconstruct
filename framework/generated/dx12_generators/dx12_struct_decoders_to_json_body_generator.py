#!/usr/bin/env python3
#
# Copyright (c) 2023 Valve Corporation
# Copyright (c) 2021-2023 LunarG, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.

## @file Generation of functions to convert decoded D3D12 structs to JSON.
## As well as the wholey generated functions, there are two levels of custom
## function support embedded inside this file.
## 1. Embedding manual code for a union member of a struct into an otherwise
##    generated function via makeUnionFieldToJson().
## 2. Wholey custom functions for more complicated struct such as those with
##    custom decoded struct classes to deal with mechanisms of type erasure
##    in the API such as void pointers pointing into opaque memory blocks
##    tagged with a type enum. These custom functions are embedded here and
##    output by endFile() to be included in the generated file for simplicity
##    and to avoid compiling a whole separate .cpp file draggig in the same
##    headers just for a few functions.
## If the generated ouput for a struct is ever observed to be incorrect, the
## procedure for generating a custom function is as follows:
## 1. Add cases to makeUnionFieldToJson() if it is only union members
##    that are causing the issue. 
## If the issue is not just union members with determining type fields in the
## same struct:
## 2. Copy the generated function into the custom function section below.
## 3. Add the struct name to json_blocklists.json (the prototype in the
##    header will still be generated).
## 4. Edit the custom function to fix the issue.
##
## @todo Add a mechanism to generate the boilerplate for custom functions
##       for structs with custom bodies to avoid the copy-paste. It should be
##       possible to generate up to and including the line
##       `const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& meta_struct = *data;`
##       and then have a custom function body for just the FieldToJson calls.
##

import sys
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator
from dx12_json_common_generator import Dx12JsonCommonGenerator
from reformat_code import format_cpp_code

class Dx12StructDecodersToJsonBodyGenerator(Dx12JsonCommonGenerator):
    """Generates C++ functions responsible for converting structs to JSON."""

    def __init__(
        self,
        source_dict,
        dx12_prefix_strings,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout
    ):
        Dx12BaseGenerator.__init__(
            self, source_dict, dx12_prefix_strings, err_file, warn_file,
            diag_file
        )

        ## @brief A set of tuples, each specifying a field of a struct which could be represented as a
        ## binary blob.
        ## If a field is present in this set, the generated code will output the field as a binary file*
        ## so add any field names here that you want to be output as a binary file.
        ## * If the JsonOptions::dump_binaries flag is set.
        ## The binary file will be named as follows: <struct_name>.<field_name>-<instance_counter>.bin
        self.binary_blobs = {
            ('D3D12_SHADER_BYTECODE', 'pShaderBytecode')
        }

    def beginFile(self, gen_opts):
        Dx12BaseGenerator.beginFile(self, gen_opts)
        code = format_cpp_code('''
            #if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

            #include "generated_dx12_struct_decoders_to_json.h"
            #include "generated_dx12_enum_to_json.h"
            #include "decode/custom_dx12_struct_decoders.h"
            #include "decode/decode_json_util.h"
            #include "graphics/dx12_util.h"
            #include "util/json_util.h"
            #include "format/format_json.h"

            /// @file Implementations of functions for converting decoded D3D12 structs to JSON.

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)

            using util::JsonOptions;

            // TODO Move all these manual functions out of the generator and into a .cpp file.

            /// @defgroup ManualD3D12StructFieldToJsons Manual functions to convert raw structs.
            /** @{ */
            static void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& data, const JsonOptions& options)
            {
                using namespace util;
                FieldToJson(jdata["AdditionalWidth"],  data.AdditionalWidth,  options);
                FieldToJson(jdata["AdditionalHeight"], data.AdditionalHeight, options);
            }

            static void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& data, const JsonOptions& options)
            {
                using namespace util;
                FieldToJson(jdata["AdditionalWidth"], data.AdditionalWidth, options);
                FieldToJson(jdata["AdditionalHeight"], data.AdditionalHeight, options);
            }

            /// Manual raw struct functon to be used for Decoded_D3D12_CLEAR_VALUE conversion.
            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VALUE& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Depth"], obj.Depth, options);
                FieldToJson(jdata["Stencil"], obj.Stencil, options);
            }
            /** @} */

            inline bool RepresentBinaryFile(const util::JsonOptions& json_options, nlohmann::ordered_json& jdata, std::string_view filename_base, const uint64_t instance_counter, const PointerDecoder<uint8_t>& data)
            {
                return RepresentBinaryFile(json_options, jdata, filename_base, instance_counter, data.GetLength(), data.GetPointer());
            }
        ''')
        write(code, file=self.outFile)
        self.newline()

    def generate_feature(self):
        struct_dict = self.source_dict['struct_dict']
        for k, v in struct_dict.items():
            if not self.is_struct_black_listed(k):
                body = format_cpp_code('''
                    void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_{0}* data, const JsonOptions& options)
                    {{
                        using namespace util;
                        if (data && data->decoded_value)
                        {{
                            const {0}& decoded_value = *data->decoded_value;
                            const Decoded_{0}& meta_struct = *data;
                    '''.format(k))
                body += '\n'
                body += self.makeStructBody(k, v)
                body += format_cpp_code('''
                    }
                }
                ''', 2)
                body += '\n'
                write(body, file=self.outFile)

    # yapf: disable
    def makeStructBody(self, name, values):
        body = ''
        union_index = 0
        # Iterate over private, protected, public properties (only public non-empty):
        items = values['properties'].items()
        for item in items:
            properties = item[1] # item[0] is the access level which is always 'public' so we ignore it
            for p in properties:
                value_info = self.get_value_info(p)

                field_to_json = ''

                if "anon-union" in value_info.base_type:
                    field_to_json = self.makeUnionFieldToJson(properties, name, union_index)
                    union_index += 1
                elif (name, value_info.name) in self.binary_blobs:
                    field_to_json  = '        static thread_local uint64_t {0}_{1}_counter{{ 0 }};\n'
                    field_to_json += '        const bool written = RepresentBinaryFile(options, jdata["{1}"], "{0}.{1}", {0}_{1}_counter, meta_struct.{1});\n'
                    field_to_json += '        {0}_{1}_counter += written;\n'
                    field_to_json = field_to_json.format(name, value_info.name)
                else:
                    function_name = self.choose_field_to_json_name(value_info)
                    if not (value_info.is_pointer or value_info.is_array or self.is_handle(value_info.base_type) or self.is_struct(value_info.base_type)):
                        # Basic data plumbs to raw struct:
                        field_to_json = '        {0}(jdata["{1}"], decoded_value.{1}, options);'
                    else:
                        # Complex types, pointers and handles plumb to the decoded struct:
                        field_to_json = '        {0}(jdata["{1}"], meta_struct.{1}, options);'
                    field_to_json = field_to_json.format(function_name, value_info.name, value_info.array_length)
                body += field_to_json
                body += '\n'
        return body
    # yapf: enable

    # Helper for structs with anonymous unions as members.
    # Instead of making the whole struct's FieldToJson custom, this helper can
    # provide a custom FieldToJson for the anon union to be injected into an
    # otherwise generated FieldtoJson implementation.
    def makeUnionFieldToJson(self, properties, struct_name, union_index):
        message = "ALERT: Union member {0} of {1} needs special handling.".format(union_index, struct_name)
        field_to_json = '        ; ///< @todo ' + message

        match struct_name:
            case "D3D12_ROOT_PARAMETER":
                field_to_json = '''
                switch(decoded_value.ParameterType)
                {
                    case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
                    {
                        FieldToJson(jdata["DescriptorTable"], meta_struct.DescriptorTable, options);
                        break;
                    }
                    case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
                    {
                        FieldToJson(jdata["Constants"], meta_struct.Constants, options);
                        break;
                    }
                    case D3D12_ROOT_PARAMETER_TYPE_CBV:
                    case D3D12_ROOT_PARAMETER_TYPE_SRV:
                    case D3D12_ROOT_PARAMETER_TYPE_UAV:
                    {
                        FieldToJson(jdata["Descriptor"], meta_struct.Descriptor, options);
                        break;
                    }
                }
                '''
            case "D3D12_SHADER_RESOURCE_VIEW_DESC":
                field_to_json = '''
                switch(decoded_value.ViewDimension)
                {
                    case D3D12_SRV_DIMENSION_BUFFER:
                    {
                        FieldToJson(jdata["Buffer"], meta_struct.Buffer, options);
                        break;
                    }
                    case D3D12_SRV_DIMENSION_TEXTURE1D:
                    {
                        FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                        break;
                    }
                    case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
                    {
                        FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                        break;
                    }
                    case D3D12_SRV_DIMENSION_TEXTURE2D:
                    {
                        FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                        break;
                    }
                    case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
                    {
                        FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                        break;
                    }
                    case D3D12_SRV_DIMENSION_TEXTURE2DMS:
                    {
                        FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                        break;
                    }
                    case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
                    {
                        FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                        break;
                    }
                    case D3D12_SRV_DIMENSION_TEXTURE3D:
                    {
                        FieldToJson(jdata["Texture3D"], meta_struct.Texture3D, options);
                        break;
                    }
                    case D3D12_SRV_DIMENSION_TEXTURECUBE:
                    {
                        FieldToJson(jdata["TextureCube"], meta_struct.TextureCube, options);
                        break;
                    }
                    case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
                    {
                        FieldToJson(jdata["TextureCubeArray"], meta_struct.TextureCubeArray, options);
                        break;
                    }
                    case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
                    {
                        FieldToJson(jdata["RaytracingAccelerationStructure"], meta_struct.RaytracingAccelerationStructure, options);
                        break;
                    }
                }
                '''
            case "D3D12_SAMPLER_DESC2":
                field_to_json = '''
                    if(decoded_value.Flags & D3D12_SAMPLER_FLAG_UINT_BORDER_COLOR)
                    {
                        FieldToJson(jdata["UintBorderColor"], decoded_value.UintBorderColor, options);
                    }
                    else
                    {
                        FieldToJson(jdata["FloatBorderColor"], decoded_value.FloatBorderColor, options);
                    }
                '''
            case "D3D12_UNORDERED_ACCESS_VIEW_DESC":
                field_to_json = '''
                    switch(decoded_value.ViewDimension)
                    {
                        case D3D12_UAV_DIMENSION_UNKNOWN:
                        {
                            FieldToJson(jdata[format::kNameWarning], "Zero-valued ViewDimension is meaningless. Is struct corrupted?", options);
                            break;
                        }
                        case D3D12_UAV_DIMENSION_BUFFER:
                        {
                            FieldToJson(jdata["Buffer"], meta_struct.Buffer, options);
                            break;
                        }
                        case D3D12_UAV_DIMENSION_TEXTURE1D:
                        {
                            FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                            break;
                        }
                        case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
                        {
                            FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                            break;
                        }
                        case D3D12_UAV_DIMENSION_TEXTURE2D:
                        {
                            FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                            break;
                        }
                        case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
                        {
                            FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                            break;
                        }
                        case D3D12_UAV_DIMENSION_TEXTURE2DMS:
                        {
                            FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                            break;
                        }
                        case D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY:
                        {
                            FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                            break;
                        }
                        case D3D12_UAV_DIMENSION_TEXTURE3D:
                        {
                            FieldToJson(jdata["Texture3D"], meta_struct.Texture3D, options);
                            break;
                        }
                        default:
                        {
                            FieldToJson(jdata[format::kNameWarning], "ViewDimension with unknown value. Is struct corrupted?", options);
                            FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ViewDimension), options);
                            break;
                        }
                    }
                '''
            case "D3D12_RENDER_TARGET_VIEW_DESC":
                field_to_json = '''
                    switch(decoded_value.ViewDimension)
                    {
                        case D3D12_RTV_DIMENSION_UNKNOWN:
                        {
                            FieldToJson(jdata[format::kNameWarning], "Zero D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC.", options);
                            break;
                        }
                        case D3D12_RTV_DIMENSION_BUFFER:
                        {
                            FieldToJson(jdata["Buffer"], meta_struct.Buffer, options);
                            break;
                        }
                        case D3D12_RTV_DIMENSION_TEXTURE1D:
                        {
                            FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                            break;
                        }
                        case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
                        {
                            FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                            break;
                        }
                        case D3D12_RTV_DIMENSION_TEXTURE2D:
                        {
                            FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                            break;
                        }
                        case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
                        {
                            FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                            break;
                        }
                        case D3D12_RTV_DIMENSION_TEXTURE2DMS:
                        {
                            FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                            break;
                        }
                        case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
                        {
                            FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                            break;
                        }
                        case D3D12_RTV_DIMENSION_TEXTURE3D:
                        {
                            FieldToJson(jdata["Texture3D"], meta_struct.Texture3D, options);
                            break;
                        }
                        default:
                        {
                            FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC. Corrupt struct?", options);
                            FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ViewDimension), options);
                            break;
                        }
                    }
                '''
            case "D3D12_DEPTH_STENCIL_VIEW_DESC":
                field_to_json = '''
                    switch(decoded_value.ViewDimension)
                    {
                        case D3D12_DSV_DIMENSION_UNKNOWN:
                        {
                            FieldToJson(jdata[format::kNameWarning], "Zero D3D12_DSV_DIMENSION in D3D12_DEPTH_STENCIL_VIEW_DESC.", options);
                            break;
                        }
                        case D3D12_DSV_DIMENSION_TEXTURE1D:
                        {
                            FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                            break;
                        }
                        case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
                        {
                            FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                            break;
                        }
                        case D3D12_DSV_DIMENSION_TEXTURE2D:
                        {
                            FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                            break;
                        }
                        case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
                        {
                            FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                            break;
                        }
                        case D3D12_DSV_DIMENSION_TEXTURE2DMS:
                        {
                            FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                            break;
                        }
                        case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
                        {
                            FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                            break;
                        }
                        default:
                        {
                            FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DSV_DIMENSION in D3D12_DEPTH_STENCIL_VIEW_DESC. Corrupt struct?", options);
                            FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ViewDimension), options);
                            break;
                        }
                    }
                '''
            case "D3D12_ROOT_PARAMETER1":
                field_to_json = '''
                switch (decoded_value.ParameterType)
                {
                    case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
                    {
                        FieldToJson(jdata["DescriptorTable"], meta_struct.DescriptorTable, options);
                        break;
                    }
                    case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
                    {
                        FieldToJson(jdata["Constants"], meta_struct.Constants, options);
                        break;
                    }
                    case D3D12_ROOT_PARAMETER_TYPE_CBV:
                    case D3D12_ROOT_PARAMETER_TYPE_SRV:
                    case D3D12_ROOT_PARAMETER_TYPE_UAV:
                    {
                        FieldToJson(jdata["Descriptor"], meta_struct.Descriptor, options);
                        break;
                    }
                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_ROOT_PARAMETER_TYPE in D3D12_ROOT_PARAMETER1.", options);
                        FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ParameterType), options);
                        break;
                    }
                }
            '''
            case "D3D12_VERSIONED_ROOT_SIGNATURE_DESC":
                field_to_json = '''
                switch (decoded_value.Version)
                {
                    case D3D_ROOT_SIGNATURE_VERSION_1_0:
                    {
                        FieldToJson(jdata["Desc_1_0"], meta_struct.Desc_1_0, options);
                        break;
                    }
                    case D3D_ROOT_SIGNATURE_VERSION_1_1:
                    {
                        FieldToJson(jdata["Desc_1_1"], meta_struct.Desc_1_1, options);
                        break;
                    }
                    case D3D_ROOT_SIGNATURE_VERSION_1_2:
                    {
                        FieldToJson(jdata["Desc_1_2"], meta_struct.Desc_1_2, options);
                        GFXRECON_LOG_ERROR("Unknown D3D_ROOT_SIGNATURE_VERSION_1_2 in D3D12_VERSIONED_ROOT_SIGNATURE_DESC.");
                        break;
                    }
                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D_ROOT_SIGNATURE_VERSION in D3D12_VERSIONED_ROOT_SIGNATURE_DESC.", options);
                        break;
                    }
                }
            '''
            case "D3D12_INDIRECT_ARGUMENT_DESC":
                field_to_json = '''
                switch (decoded_value.Type)
                {
                    case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW:
                    case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED:
                    case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH:
                    {
                        // No data to output for draws and dispatches, they are parameterless tags.
                        break;
                    }
                    case D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW:
                    {
                        auto& vb = jdata["VertexBuffer"];
                        FieldToJson(vb["Slot"], decoded_value.VertexBuffer.Slot, options);
                        break;
                    }
                    case D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW:
                    {
                        // No parameters to output.
                        FieldToJson(jdata["comment"], "There must be a D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED in the same sequence.", options);
                        break;
                    }
                    case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT:
                    {
                        auto& c = jdata["Constant"];
                        FieldToJson(c["RootParameterIndex"], decoded_value.Constant.RootParameterIndex, options);
                        FieldToJson(c["DestOffsetIn32BitValues"], decoded_value.Constant.DestOffsetIn32BitValues, options);
                        FieldToJson(c["Num32BitValuesToSet"], decoded_value.Constant.Num32BitValuesToSet, options);
                        break;
                    }
                    case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW:
                    {
                        auto& cbv = jdata["ConstantBufferView"];
                        FieldToJson(cbv["RootParameterIndex"], decoded_value.ConstantBufferView.RootParameterIndex, options);
                        break;
                    }
                    case D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW:
                    {
                        auto& srv = jdata["ShaderResourceView"];
                        FieldToJson(srv["RootParameterIndex"], decoded_value.ShaderResourceView.RootParameterIndex, options);
                        break;
                    }
                    case D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW:
                    {
                        auto& uav = jdata["UnorderedAccessView"];
                        FieldToJson(uav["RootParameterIndex"], decoded_value.UnorderedAccessView.RootParameterIndex, options);
                        break;
                    }
                    case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS:
                    case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_MESH:
                    {
                        // No data to output for draws and dispatches, they are parameterless tags.
                        break;
                    }
                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_INDIRECT_ARGUMENT_TYPE in D3D12_INDIRECT_ARGUMENT_DESC.", options);
                        break;
                    }
                }
                '''
            case "D3D12_RAYTRACING_GEOMETRY_DESC":
                field_to_json = '''
                switch(decoded_value.Type)
                {
                    case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
                    {
                        FieldToJson(jdata["Triangles"], meta_struct.Triangles, options);
                        break;
                    }
                    case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
                    {
                        FieldToJson(jdata["AABBs"], meta_struct.AABBs, options);
                        break;
                    }
                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RAYTRACING_GEOMETRY_TYPE in D3D12_RAYTRACING_GEOMETRY_DESC.", options);
                        break;
                    }
                }
                '''
            case "D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS":
                field_to_json = '''
                switch(decoded_value.Type)
                {
                    case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
                    {
                        FieldToJsonAsHex(jdata["InstanceDescs"], decoded_value.InstanceDescs, options);
                        break;
                    }
                    case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
                    {
                        switch(decoded_value.DescsLayout)
                        {
                            case D3D12_ELEMENTS_LAYOUT_ARRAY:
                            {
                                FieldToJson(jdata["pGeometryDescs"], meta_struct.pGeometryDescs, options);
                                break;
                            }
                            case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:
                            {
                                FieldToJson(jdata["ppGeometryDescs"], meta_struct.ppGeometryDescs, options);
                                break;
                            }
                        }
                        break;
                    }
                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE in D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS.", options);
                        break;
                    }
                }
                '''
            case "D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA":
                field_to_json = '''
                switch(decoded_value.Version)
                {
                    case D3D12_DRED_VERSION_1_0:
                    {
                        FieldToJson(jdata["Dred_1_0"], meta_struct.Dred_1_0, options);
                        break;
                    }
                    case D3D12_DRED_VERSION_1_1:
                    {
                        FieldToJson(jdata["Dred_1_1"], meta_struct.Dred_1_1, options);
                        break;
                    }
                    case D3D12_DRED_VERSION_1_2:
                    {
                        FieldToJson(jdata["Dred_1_2"], meta_struct.Dred_1_2, options);
                        break;
                    }
                    case D3D12_DRED_VERSION_1_3:
                    {
                        FieldToJson(jdata["Dred_1_3"], meta_struct.Dred_1_3, options);
                        FieldToJson(jdata[format::kNameWarning], "Dred_1_3 is not supported by GFXR at this time. Please file an issue quoting this text if this is a blocker for you.", options);
                        break;
                    }
                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_DRED_VERSION in D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA.", options);
                        break;
                    }
                }
                '''
            case "D3D12_RENDER_PASS_BEGINNING_ACCESS":
                field_to_json = '''
                switch(decoded_value.Type)
                {
                    case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR:
                    {
                        FieldToJson(jdata["Clear"], meta_struct.Clear, options);
                        break;
                    }
                    case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER:
                    if(decoded_value.PreserveLocal.AdditionalWidth != 0U || decoded_value.PreserveLocal.AdditionalHeight != 0U)
                    {
                        FieldToJson(jdata[format::kNameWarning], "Additional width and height should be zero (see DirectX Specs).", options);
                    }
                    case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_SRV:
                    case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE_LOCAL_UAV:
                    {
                        FieldToJson(jdata["PreserveLocal"], decoded_value.PreserveLocal, options);
                        break;
                    }
                    case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_DISCARD:
                    case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE:
                    case D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_NO_ACCESS:
                    // No parameters to these cases.
                    break;

                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE in D3D12_RENDER_PASS_BEGINNING_ACCESS.", options);
                        break;
                    }
                }
                '''
            case "D3D12_RENDER_PASS_ENDING_ACCESS":
                field_to_json = '''
                switch(decoded_value.Type)
                {
                    case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_DISCARD:
                    case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE:
                    case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_NO_ACCESS:
                    // No parameters to these cases.
                    break;

                    case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE:
                    {
                        FieldToJson(jdata["Resolve"], meta_struct.Resolve, options);
                        break;
                    }
                    case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_RENDER:
                    case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_SRV:
                    case D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE_LOCAL_UAV:
                    {
                        FieldToJson(jdata["PreserveLocal"], decoded_value.PreserveLocal, options);
                        break;
                    }

                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RENDER_PASS_ENDING_ACCESS_TYPE in D3D12_RENDER_PASS_ENDING_ACCESS.", options);
                        break;
                    }
                }
                '''
            case "D3D12_BARRIER_GROUP":
                field_to_json = '''
                switch(decoded_value.Type)
                {
                    case D3D12_BARRIER_TYPE_GLOBAL:
                    {
                        FieldToJson(jdata["pGlobalBarriers"], meta_struct.global_barriers, options);
                        break;
                    }
                    case D3D12_BARRIER_TYPE_TEXTURE:
                    {
                        FieldToJson(jdata["pTextureBarriers"], meta_struct.texture_barriers, options);
                        break;
                    }
                    case D3D12_BARRIER_TYPE_BUFFER:
                    {
                        FieldToJson(jdata["pBufferBarriers"], meta_struct.buffer_barriers, options);
                        break;
                    }
                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_BARRIER_TYPE in D3D12_BARRIER_GROUP.", options);
                        break;
                    }
                }
                '''
            case "D3D12_CLEAR_VALUE":
                field_to_json = '''
                if(graphics::dx12::IsDepthStencilFormat(decoded_value.Format))
                {
                    FieldToJson(jdata["DepthStencil"], decoded_value.DepthStencil, options);
                }
                else
                {
                    FieldToJson(jdata["Color"], decoded_value.Color, options);
                }
                '''
            case "D3D12_RESOURCE_BARRIER":
                field_to_json = '''
                switch(decoded_value.Type)
                {
                    case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
                    {
                        FieldToJson(jdata["Transition"], meta_struct.Transition, options);
                        break;
                    }
                    case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
                    {
                        FieldToJson(jdata["Aliasing"], meta_struct.Aliasing, options);
                        break;
                    }
                    case D3D12_RESOURCE_BARRIER_TYPE_UAV:
                    {
                        FieldToJson(jdata["UAV"], meta_struct.UAV, options);
                        break;
                    }
                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_RESOURCE_BARRIER_TYPE in D3D12_RESOURCE_BARRIER.", options);
                        break;
                    }
                }
                '''
            case "D3D12_TEXTURE_COPY_LOCATION":
                field_to_json = '''
                switch(decoded_value.Type)
                {
                    case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:
                    {
                        FieldToJson(jdata["SubresourceIndex"], decoded_value.SubresourceIndex, options);
                        break;
                    }
                    case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:
                    {
                        FieldToJson(jdata["PlacedFootprint"], meta_struct.PlacedFootprint, options);
                        break;
                    }
                    default:
                    {
                        FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_TEXTURE_COPY_TYPE in D3D12_TEXTURE_COPY_LOCATION.", options);
                        break;
                    }
                }
                '''
            case _:
                print(message)
        return format_cpp_code(field_to_json, 2)

    def endFile(self):
        """Method override."""
        custom_impls = format_cpp_code('''
            // TODO Move all these manual functions out of the generator and into a .cpp file.

            /// @defgroup custom_dx12_struct_decoders_to_json_bodies Custom implementations for
            /// troublesome structs.
            /// We put the custom implementations in the generator Python rather than
            /// creating a whole new compilation unit for them.
            /** @{*/

            // Decoded_LARGE_INTEGER won't be generated as it is a <winnt.h> struct rather than D3D12.
            void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_LARGE_INTEGER* data, const JsonOptions& options)
            {
                using namespace util;
                if (data && data->decoded_value)
                {
                    const LARGE_INTEGER& decoded_value = *data->decoded_value;
                    FieldToJson(jdata, decoded_value.QuadPart, options);
                }
            }

            // Generated version tries to read the struct members rather than doing the "fake enum" thing.
            void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_GUID* data, const JsonOptions& options)
            {
                using namespace util;
                if (data && data->decoded_value)
                {
                    const GUID& decoded_value = *data->decoded_value;
                    FieldToJson(jdata, decoded_value, options);
                }
            }

            /// Dump all the fields of the custom struct, even though not all need be populated.
            /// @note D3D12 doesn't define names for these: the underlying struct is just a void pointer
            /// and a byte count with the structure defined in documentation. See:
            /// <https://learn.microsoft.com/en-us/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc>
            /// See also: framework\decode\custom_dx12_struct_decoders.cpp
            void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* data, const JsonOptions& options)
            {
                using namespace util;
                if (data && data->decoded_value)
                {
                    const D3D12_PIPELINE_STATE_STREAM_DESC& decoded_value = *data->decoded_value;
                    const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC& meta_struct = *data;
                    FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct.
                    //FieldToJson(jdata["root_signature_ptr"], meta_struct.root_signature_ptr, options);
                    FieldToJson(jdata[format::kNameWarning], "D3D12_PIPELINE_STATE_STREAM_DESC.root_signature_ptr is not supported.", options);
                    FieldToJson(jdata["root_signature_ptr"], "@todo Get this field to convert cleanly.", options);
                    FieldToJson(jdata["vs_bytecode"], meta_struct.vs_bytecode, options);
                    FieldToJson(jdata["ps_bytecode"], meta_struct.ps_bytecode, options);
                    FieldToJson(jdata["ds_bytecode"], meta_struct.ds_bytecode, options);
                    FieldToJson(jdata["hs_bytecode"], meta_struct.hs_bytecode, options);
                    FieldToJson(jdata["gs_bytecode"], meta_struct.gs_bytecode, options);
                    FieldToJson(jdata["cs_bytecode"], meta_struct.cs_bytecode, options);
                    FieldToJson(jdata["as_bytecode"], meta_struct.as_bytecode, options);
                    FieldToJson(jdata["ms_bytecode"], meta_struct.ms_bytecode, options);
                    FieldToJson(jdata["stream_output"], meta_struct.stream_output, options);
                    FieldToJson(jdata["blend"], meta_struct.blend, options);
                    FieldToJson(jdata["rasterizer"], meta_struct.rasterizer, options);
                    FieldToJson(jdata["depth_stencil"], meta_struct.depth_stencil, options);
                    FieldToJson(jdata["input_layout"], meta_struct.input_layout, options);
                    FieldToJson(jdata["render_target_formats"], meta_struct.render_target_formats, options);
                    FieldToJson(jdata["sample_desc"], meta_struct.sample_desc, options);
                    FieldToJson(jdata["cached_pso"], meta_struct.cached_pso, options);
                    FieldToJson(jdata["depth_stencil1"], meta_struct.depth_stencil1, options);
                    FieldToJson(jdata["view_instancing"], meta_struct.view_instancing, options);
                }
            }

            // The decoded struct has a custom implementation.
            void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_STATE_SUBOBJECT* data, const JsonOptions& options)
            {
                using namespace util;
                if (data && data->decoded_value)
                {
                    const D3D12_STATE_SUBOBJECT& decoded_value = *data->decoded_value;
                    const Decoded_D3D12_STATE_SUBOBJECT& meta_struct = *data;
                    FieldToJson(jdata["Type"], decoded_value.Type, options);
                    switch(decoded_value.Type)
                    {
                        case D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:
                        FieldToJson(jdata["state_object_config"], meta_struct.state_object_config, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:
                        FieldToJson(jdata["global_root_signature"], meta_struct.global_root_signature, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:
                        FieldToJson(jdata["local_root_signature"], meta_struct.local_root_signature, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:
                        FieldToJson(jdata["node_mask"], meta_struct.node_mask, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:
                        FieldToJson(jdata["dxil_library_desc"], meta_struct.dxil_library_desc, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:
                        FieldToJson(jdata["existing_collection_desc"], meta_struct.existing_collection_desc, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
                        FieldToJson(jdata["subobject_to_exports_association"], meta_struct.subobject_to_exports_association, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:
                        FieldToJson(jdata["dxil_subobject_to_exports_association"], meta_struct.dxil_subobject_to_exports_association, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:
                        FieldToJson(jdata["raytracing_shader_config"], meta_struct.raytracing_shader_config, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:
                        FieldToJson(jdata["raytracing_pipeline_config"], meta_struct.raytracing_pipeline_config, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:
                        FieldToJson(jdata["hit_group_desc"], meta_struct.hit_group_desc, options);
                        break;
                        case D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG1:
                        FieldToJson(jdata["raytracing_pipeline_config1"], meta_struct.raytracing_pipeline_config1, options);
                        break;
                        default:
                        {
                            FieldToJson(jdata[format::kNameWarning], "Unknown D3D12_STATE_SUBOBJECT_TYPE in D3D12_STATE_SUBOBJECT.", options);
                            break;
                        }
                    }
                }
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE* data, const JsonOptions& options)
            {
                using namespace util;
                if (data && data->decoded_value)
                {
                    const D3D12_CPU_DESCRIPTOR_HANDLE& decoded_value = *data->decoded_value;
                    const Decoded_D3D12_CPU_DESCRIPTOR_HANDLE& meta_struct = *data;
                    // FieldToJson(jdata[format::kNameInfo], "heap_id and index were copied out of ptr by a custom encoder at capture time, and ptr was never stored in the capture file.", options);
                    FieldToJson(jdata["heap_id"], meta_struct.heap_id, options);
                    FieldToJson(jdata["index"], meta_struct.index, options);
                }
            }

            /** @} */
        ''') + '\n'
        write(custom_impls, file=self.outFile)
        self.newline()
        code = format_cpp_code('''
            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)

            #endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
        ''')
        write(code, file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
