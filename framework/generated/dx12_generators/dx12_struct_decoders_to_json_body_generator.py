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

import sys
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator
from reformat_code import format_cpp_code

class Dx12StructDecodersToJsonBodyGenerator(Dx12BaseGenerator):
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

    def beginFile(self, gen_opts):
        Dx12BaseGenerator.beginFile(self, gen_opts)
        ## @todo De-duplicate this list.
        '''self.STRUCT_BLACKLIST.append('DXGI_DISPLAY_COLOR_SPACE')
        self.STRUCT_BLACKLIST.append('D3D12_RAYTRACING_INSTANCE_DESC')
        self.STRUCT_BLACKLIST.append('D3D12_CPU_DESCRIPTOR_HANDLE')
        self.STRUCT_BLACKLIST.append('D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION')
        self.STRUCT_BLACKLIST.append('D3D12_GPU_DESCRIPTOR_HANDLE')
        self.STRUCT_BLACKLIST.append('_SECURITY_ATTRIBUTES')
        self.STRUCT_BLACKLIST.remove('D3D12_CPU_DESCRIPTOR_HANDLE')'''
        # We can generate the header for the decoder version but the body needs the manual implementation at the end of this file.
        self.STRUCT_BLACKLIST.append('GUID')

        code = format_cpp_code('''
            #include "generated_dx12_struct_decoders_to_json.h"
            #include "generated_dx12_enum_to_json.h"
            #include "decode/custom_dx12_struct_decoders.h"
            #include "decode/decode_json_util.h"
            #include "graphics/dx12_util.h"
            #include "util/json_util.h"

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)

            using util::JsonOptions;

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
                {{
                    case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
                    {{
                        FieldToJson(jdata["DescriptorTable"], meta_struct.DescriptorTable, options);
                        break;
                    }}
                    case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
                    {{
                        FieldToJson(jdata["Constants"], meta_struct.Constants, options);
                        break;
                    }}
                    case D3D12_ROOT_PARAMETER_TYPE_CBV:
                    case D3D12_ROOT_PARAMETER_TYPE_SRV:
                    case D3D12_ROOT_PARAMETER_TYPE_UAV:
                    {{
                        FieldToJson(jdata["Descriptor"], meta_struct.Descriptor, options);
                        break;
                    }}
                }}
                '''
            case "D3D12_SHADER_RESOURCE_VIEW_DESC":
                field_to_json = '''
                switch(decoded_value.ViewDimension)
                {{
                    case D3D12_SRV_DIMENSION_BUFFER:
                    {{
                        FieldToJson(jdata["Buffer"], meta_struct.Buffer, options);
                        break;
                    }}
                    case D3D12_SRV_DIMENSION_TEXTURE1D:
                    {{
                        FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                        break;
                    }}
                    case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
                    {{
                        FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                        break;
                    }}
                    case D3D12_SRV_DIMENSION_TEXTURE2D:
                    {{
                        FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                        break;
                    }}
                    case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
                    {{
                        FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                        break;
                    }}
                    case D3D12_SRV_DIMENSION_TEXTURE2DMS:
                    {{
                        FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                        break;
                    }}
                    case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
                    {{
                        FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                        break;
                    }}
                    case D3D12_SRV_DIMENSION_TEXTURE3D:
                    {{
                        FieldToJson(jdata["Texture3D"], meta_struct.Texture3D, options);
                        break;
                    }}
                    case D3D12_SRV_DIMENSION_TEXTURECUBE:
                    {{
                        FieldToJson(jdata["TextureCube"], meta_struct.TextureCube, options);
                        break;
                    }}
                    case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
                    {{
                        FieldToJson(jdata["TextureCubeArray"], meta_struct.TextureCubeArray, options);
                        break;
                    }}
                    case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
                    {{
                        FieldToJson(jdata["RaytracingAccelerationStructure"], meta_struct.RaytracingAccelerationStructure, options);
                        break;
                    }}
                }}
                '''
            case "D3D12_SAMPLER_DESC2":
                field_to_json = '''
                    if(decoded_value.Flags & D3D12_SAMPLER_FLAG_UINT_BORDER_COLOR)
                    {{
                        FieldToJson(jdata["UintBorderColor"], decoded_value.UintBorderColor, options);
                    }}
                    else
                    {{
                        FieldToJson(jdata["FloatBorderColor"], decoded_value.FloatBorderColor, options);
                    }}
                '''
            case "D3D12_UNORDERED_ACCESS_VIEW_DESC":
                field_to_json = '''
                    switch(decoded_value.ViewDimension)
                    {{
                        case D3D12_UAV_DIMENSION_UNKNOWN:
                        {{
                            FieldToJson(jdata["Warning"], "Zero-valued ViewDimension is meaningless. Is struct corrupted?", options);
                            break;
                        }}
                        case D3D12_UAV_DIMENSION_BUFFER:
                        {{
                            FieldToJson(jdata["Buffer"], meta_struct.Buffer, options);
                            break;
                        }}
                        case D3D12_UAV_DIMENSION_TEXTURE1D:
                        {{
                            FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                            break;
                        }}
                        case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
                        {{
                            FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                            break;
                        }}
                        case D3D12_UAV_DIMENSION_TEXTURE2D:
                        {{
                            FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                            break;
                        }}
                        case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
                        {{
                            FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                            break;
                        }}
                        case D3D12_UAV_DIMENSION_TEXTURE2DMS:
                        {{
                            FieldToJson(jdata["Texture2DMS"], "Field missing from Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC.", options);
                            break;
                        }}
                        case D3D12_UAV_DIMENSION_TEXTURE2DMSARRAY:
                        {{
                            FieldToJson(jdata["Texture2DMSArray"], "Field missing from Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC.", options);
                            break;
                        }}
                        case D3D12_UAV_DIMENSION_TEXTURE3D:
                        {{
                            FieldToJson(jdata["Texture3D"], meta_struct.Texture3D, options);
                            break;
                        }}
                        default:
                        {{
                            FieldToJson(jdata["Warning"], "ViewDimension with unknown value. Is struct corrupted?", options);
                            FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ViewDimension), options);
                            break;
                        }}
                    }}
                '''
            case "D3D12_RENDER_TARGET_VIEW_DESC":
                field_to_json = '''
                    switch(decoded_value.ViewDimension)
                    {{
                        case D3D12_RTV_DIMENSION_UNKNOWN:
                        {{
                            FieldToJson(jdata["Warning"], "Zero D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC. Uninitialised struct?", options);
                            break;
                        }}
                        case D3D12_RTV_DIMENSION_BUFFER:
                        {{
                            FieldToJson(jdata["Buffer"], meta_struct.Buffer, options);
                            break;
                        }}
                        case D3D12_RTV_DIMENSION_TEXTURE1D:
                        {{
                            FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                            break;
                        }}
                        case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
                        {{
                            FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                            break;
                        }}
                        case D3D12_RTV_DIMENSION_TEXTURE2D:
                        {{
                            FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                            break;
                        }}
                        case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
                        {{
                            FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                            break;
                        }}
                        case D3D12_RTV_DIMENSION_TEXTURE2DMS:
                        {{
                            FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                            break;
                        }}
                        case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
                        {{
                            FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                            break;
                        }}
                        case D3D12_RTV_DIMENSION_TEXTURE3D:
                        {{
                            FieldToJson(jdata["Texture3D"], meta_struct.Texture3D, options);
                            break;
                        }}
                        default:
                        {{
                            FieldToJson(jdata["Warning"], "Unknown D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC. Corrupt struct?", options);
                            FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ViewDimension), options);
                            break;
                        }}
                    }}
                '''
            case "D3D12_DEPTH_STENCIL_VIEW_DESC":
                field_to_json = '''
                    switch(decoded_value.ViewDimension)
                    {{
                        case D3D12_DSV_DIMENSION_UNKNOWN:
                        {{
                            FieldToJson(jdata["Warning"], "Zero D3D12_RTV_DIMENSION in D3D12_RENDER_TARGET_VIEW_DESC. Uninitialised struct?", options);
                            break;
                        }}
                        case D3D12_DSV_DIMENSION_TEXTURE1D:
                        {{
                            FieldToJson(jdata["Texture1D"], meta_struct.Texture1D, options);
                            break;
                        }}
                        case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
                        {{
                            FieldToJson(jdata["Texture1DArray"], meta_struct.Texture1DArray, options);
                            break;
                        }}
                        case D3D12_DSV_DIMENSION_TEXTURE2D:
                        {{
                            FieldToJson(jdata["Texture2D"], meta_struct.Texture2D, options);
                            break;
                        }}
                        case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
                        {{
                            FieldToJson(jdata["Texture2DArray"], meta_struct.Texture2DArray, options);
                            break;
                        }}
                        case D3D12_DSV_DIMENSION_TEXTURE2DMS:
                        {{
                            FieldToJson(jdata["Texture2DMS"], meta_struct.Texture2DMS, options);
                            break;
                        }}
                        case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
                        {{
                            FieldToJson(jdata["Texture2DMSArray"], meta_struct.Texture2DMSArray, options);
                            break;
                        }}
                        default:
                        {{
                            FieldToJson(jdata["Warning"], "Unknown D3D12_DSV_DIMENSION in D3D12_DEPTH_STENCIL_VIEW_DESC. Corrupt struct?", options);
                            FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ViewDimension), options);
                            break;
                        }}
                    }}
                '''
            case "D3D12_ROOT_PARAMETER1":
                field_to_json = '''
                switch (decoded_value.ParameterType)
                {{
                    case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
                    {{
                        FieldToJson(jdata["DescriptorTable"], meta_struct.DescriptorTable, options);
                        break;
                    }}
                    case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
                    {{
                        FieldToJson(jdata["Constants"], meta_struct.Constants, options);
                        break;
                    }}
                    case D3D12_ROOT_PARAMETER_TYPE_CBV:
                    case D3D12_ROOT_PARAMETER_TYPE_SRV:
                    case D3D12_ROOT_PARAMETER_TYPE_UAV:
                    {{
                        FieldToJson(jdata["Descriptor"], meta_struct.Descriptor, options);
                        break;
                    }}
                    default:
                    {{
                        FieldToJson(jdata["Warning"], "Unknown D3D12_ROOT_PARAMETER_TYPE in D3D12_ROOT_PARAMETER1. Uninitialised or corrupt struct?", options);
                        FieldToJson(jdata["Unknown value"], uint32_t(decoded_value.ParameterType), options);
                        break;
                    }}
                }}
            '''
            case "D3D12_VERSIONED_ROOT_SIGNATURE_DESC":
                field_to_json = '''
                switch (decoded_value.Version)
                {{
                    case D3D_ROOT_SIGNATURE_VERSION_1_0:
                    {{
                        FieldToJson(jdata["Desc_1_0"], meta_struct.Desc_1_0, options);
                        break;
                    }}
                    case D3D_ROOT_SIGNATURE_VERSION_1_1:
                    {{
                        FieldToJson(jdata["Desc_1_1"], meta_struct.Desc_1_1, options);
                        break;
                    }}
                    case D3D_ROOT_SIGNATURE_VERSION_1_2:
                    {{
                        /// @todo Uncomment this once the union member is added to the decoded struct: FieldToJson(jdata["Desc_1_2"], meta_struct.Desc_1_2, options);
                        GFXRECON_LOG_ERROR("Unknown D3D_ROOT_SIGNATURE_VERSION_1_2 in D3D12_VERSIONED_ROOT_SIGNATURE_DESC.");
                        break;
                    }}
                    default:
                    {{
                        FieldToJson(jdata["Warning"], "Unknown D3D_ROOT_SIGNATURE_VERSION in D3D12_VERSIONED_ROOT_SIGNATURE_DESC. Uninitialised or corrupt struct?", options);
                        break;
                    }}
                }}
            '''
            case "D3D12_INDIRECT_ARGUMENT_DESC":
                field_to_json = '''
                switch (decoded_value.Type)
                {{
                    case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW:
                    case D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED:
                    case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH:
                    {{
                        // No data to output for draws and dispatches, they are parameterless tags.
                        break;
                    }}
                    case D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW:
                    {{
                        auto& vb = jdata["VertexBuffer"];
                        FieldToJson(vb["Slot"], decoded_value.VertexBuffer.Slot, options);
                        break;
                    }}
                    case D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW:
                    {{
                        // No parameters to output.
                        FieldToJson(jdata["comment"], "There must be a D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED in the same sequence.", options);
                        break;
                    }}
                    case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT:
                    {{
                        auto& c = jdata["Constant"];
                        FieldToJson(c["RootParameterIndex"], decoded_value.Constant.RootParameterIndex, options);
                        FieldToJson(c["DestOffsetIn32BitValues"], decoded_value.Constant.DestOffsetIn32BitValues, options);
                        FieldToJson(c["Num32BitValuesToSet"], decoded_value.Constant.Num32BitValuesToSet, options);
                        break;
                    }}
                    case D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW:
                    {{
                        auto& cbv = jdata["ConstantBufferView"];
                        FieldToJson(cbv["RootParameterIndex"], decoded_value.ConstantBufferView.RootParameterIndex, options);
                        break;
                    }}
                    case D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW:
                    {{
                        auto& srv = jdata["ShaderResourceView"];
                        FieldToJson(srv["RootParameterIndex"], decoded_value.ShaderResourceView.RootParameterIndex, options);
                        break;
                    }}
                    case D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW:
                    {{
                        auto& uav = jdata["UnorderedAccessView"];
                        FieldToJson(uav["RootParameterIndex"], decoded_value.UnorderedAccessView.RootParameterIndex, options);
                        break;
                    }}
                    case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS:
                    case D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH_MESH:
                    {{
                        // No data to output for draws and dispatches, they are parameterless tags.
                        break;
                    }}
                    default:
                    {{
                        FieldToJson(jdata["Warning"], "Unknown D3D12_INDIRECT_ARGUMENT_TYPE in D3D12_INDIRECT_ARGUMENT_DESC. Uninitialised or corrupt struct?", options);
                        break;
                    }}
                }}
                '''
            case _:
                print(message)
        return format_cpp_code(field_to_json, 2)

    # yapf: disable
    def makeStructBody(self, name, values):
        body = ''
        union_index = 0
        # Iterate over private, protected, public properties (only public non-empty):
        for property_visibility, properties in values['properties'].items():
            for p in properties:
                value = self.get_value_info(p)
                type = p['type']

                if "anon-union" in type:
                    field_to_json = self.makeUnionFieldToJson(properties, name, union_index)
                    union_index += 1
                elif not (value.is_pointer or value.is_array or self.is_handle(value.base_type) or self.is_struct(value.base_type)):
                    if "BOOL" in type:
                        field_to_json = '        Bool32ToJson(jdata["{0}"], decoded_value.{0}, options); // Basic data plumbs to raw struct'
                    else:
                        field_to_json = '        FieldToJson(jdata["{0}"], decoded_value.{0}, options); // Basic data plumbs to raw struct'
                else:
                    if "BOOL" in type:
                        field_to_json = '        Bool32ToJson(jdata["{0}"], meta_struct.{0}, options); // Complex types and handles plumb to the decoded struct'
                        # This branch never taken so warn devs to check out the generated code if it ever is:
                        print("ALERT: First time generating code for non-simple Bool. Check the result and delete this alert:")
                        print(field_to_json)
                    else:
                        field_to_json = '        FieldToJson(jdata["{0}"], meta_struct.{0}, options); // Complex types and handles plumb to the decoded struct'

                # Append some type info to the generated comment to help working back from
                # generated to code to change required here:
                if value.is_pointer:
                    field_to_json += " [is_pointer]"
                if value.is_array:
                        field_to_json += " [is_array]"
                if self.is_handle(value.base_type):
                    ## @todo Never fires.
                    print("ALERT: Found handle: " + field_to_json)
                    field_to_json += " [is_handle]"
                elif self.is_struct(value.base_type):
                    field_to_json += " [is_struct]"
                elif self.is_enum(value.base_type):
                    field_to_json += " [is_enum]"
                elif "BOOL" in type:
                    field_to_json += " [is_bool]"

                field_to_json = field_to_json.format(value.name, value.array_length)
                body += field_to_json + '\n'
        return body
    # yapf: enable

    def endFile(self):
        """Method override."""
        custom_impls = format_cpp_code('''
            /// @defgroup custom_dx12_struct_decoders_to_json_body_generators Custom implementations
            /// for troublesome structs.
            /** @{*/
            /// @todo Put the custom implementations in the generator Python here rather than
            /// creating a whole new compilation unit for them.

            // Won't be generated as is a <winnt.h> struct.
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

            // The decoded struct has a custom implementation.
            void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC* data, const JsonOptions& options)
            {
                using namespace util;
                if (data && data->decoded_value)
                {
                    const D3D12_PIPELINE_STATE_STREAM_DESC& decoded_value = *data->decoded_value;
                    const Decoded_D3D12_PIPELINE_STATE_STREAM_DESC& meta_struct = *data;
                    FieldToJson(jdata["SizeInBytes"], decoded_value.SizeInBytes, options); // Basic data plumbs to raw struct.
                    /// @todo This needs custom handling:
                    FieldToJson(jdata["pPipelineStateSubobjectStream"], "ToDo: custom handler required.", options); // Any pointer or thing with a pointer or a handle plumbs to the Decoded type [is_pointer]
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
                    FieldToJson(jdata["Type"], decoded_value.Type, options); // Basic data plumbs to raw struct [is_enum]
                    /// @todo This needs custom handling:
                    FieldToJson(jdata["pDesc"], "ToDo: custom handler required.", options); // Any pointer or thing with a pointer or a handle plumbs to the Decoded type [is_pointer]
                }
            }



            //  ============================================================================================================================
            /// @todo Pull out the structs below which only fail due to having a union member and use the union injection mechanism instead.

            void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_BARRIER_GROUP* data, const JsonOptions& options)
            {
                using namespace util;
                if (data && data->decoded_value)
                {
                    const D3D12_BARRIER_GROUP& decoded_value = *data->decoded_value;
                    const Decoded_D3D12_BARRIER_GROUP& meta_struct = *data;
                    FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
                    FieldToJson(jdata["NumBarriers"], decoded_value.NumBarriers, options); //
                    /// @todo Implement this union: FieldToJson(jdata[""], decoded_value., options); //
                }
            }

            /// Manual raw struct functon to be used for Decoded_D3D12_CLEAR_VALUE conversion.
            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VALUE& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Depth"], obj.Depth, options);
                FieldToJson(jdata["Stencil"], obj.Stencil, options);
            }

            // D3D12_CLEAR_VALUE contains a union so we need to output depending on the format.
            void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_CLEAR_VALUE* data, const JsonOptions& options)
            {
                using namespace util;

                if (data && data->decoded_value)
                {
                    const D3D12_CLEAR_VALUE& decoded_value = *data->decoded_value;
                    const Decoded_D3D12_CLEAR_VALUE& meta_struct = *data;
                    FieldToJson(jdata["Format"], decoded_value.Format, options);
                    if(graphics::dx12::IsDepthStencilFormat(decoded_value.Format))
                    {
                        FieldToJson(jdata["DepthStencil"], decoded_value.DepthStencil, options);
                    }
                    else
                    {
                        FieldToJson(jdata["Color"], decoded_value.Color, options);
                    }
                }
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_RESOURCE_BARRIER* data, const JsonOptions& options)
            {
                using namespace util;
                if (data && data->decoded_value)
                {
                    const D3D12_RESOURCE_BARRIER& decoded_value = *data->decoded_value;
                    const Decoded_D3D12_RESOURCE_BARRIER& meta_struct = *data;
                    FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
                    FieldToJson(jdata["Flags"], decoded_value.Flags, options); // [is_enum]
                    /// @todo Implement this union: FieldToJson(jdata[""], decoded_value., options);
                }
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_D3D12_TEXTURE_COPY_LOCATION* data, const JsonOptions& options)
            {
                using namespace util;
                if (data && data->decoded_value)
                {
                    const D3D12_TEXTURE_COPY_LOCATION& decoded_value = *data->decoded_value;
                    const Decoded_D3D12_TEXTURE_COPY_LOCATION& meta_struct = *data;
                    ; ///< @todo Generate for pResource[None]: ID3D12Resource [is_pointer]
                    FieldToJson(jdata["Type"], decoded_value.Type, options); // [is_enum]
                    /// @todo Implement this union: FieldToJson(jdata[""], decoded_value., options); //
                }
            }

            /** @} */
        ''') + '\n'
        write(custom_impls, file=self.outFile)
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
