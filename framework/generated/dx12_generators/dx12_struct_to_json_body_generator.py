#!/usr/bin/env python3
#
# Copyright (c) 2021-2023 LunarG, Inc.
# Copyright (c) 2023 Valve Corporation
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

class Dx12StructToJsonBodyGenerator(Dx12BaseGenerator):
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
        #self.STRUCT_BLACKLIST.append('DXGI_DISPLAY_COLOR_SPACE')
        #self.STRUCT_BLACKLIST.append('D3D12_RAYTRACING_INSTANCE_DESC')
        #self.STRUCT_BLACKLIST.append('D3D12_CPU_DESCRIPTOR_HANDLE')
        #self.STRUCT_BLACKLIST.append('D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION')
        #self.STRUCT_BLACKLIST.append('D3D12_GPU_DESCRIPTOR_HANDLE')
        #self.STRUCT_BLACKLIST.append('_SECURITY_ATTRIBUTES')
        self.STRUCT_BLACKLIST.append('GUID')
        Dx12BaseGenerator.beginFile(self, gen_opts)

        code = '''
            #include "generated_dx12_struct_to_json.h"
            #include "generated_dx12_enum_to_json.h"
            #include "decode/custom_dx12_to_string.h"

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(util)
        '''
        write(format_cpp_code(code), file=self.outFile)
        self.newline()

    def generate_feature(self):
        struct_dict = self.source_dict['struct_dict']
        for k, v in struct_dict.items():
            if not self.is_struct_black_listed(k):
                body = '''
                    void FieldToJson(nlohmann::ordered_json& jdata, const {0}& obj, const JsonOptions& options)
                    {{
                    '''.format(k)
                body += self.makeStructBody(k, v)
                body += "}"
                body = format_cpp_code(body) + '\n'
                write(body, file=self.outFile)

    # yapf: disable
    def makeStructBody(self, name, values):
        body = ''
        for property_type, properties in values['properties'].items():
            for p in properties:
                value = self.get_value_info(p)

                # @todo BOOL type?  FieldToJson(jdata["RectsCoalesced"], obj.RectsCoalesced ???
                field_to_json = '    ; ///< @todo Generate for {0}[{1}]: ' + str(value.base_type) + '\n'
                if value.is_pointer:
                    if value.is_array:
                        pass
                else:
                    if value.is_array:
                        pass
                    else:
                        if self.is_handle(value.base_type):
                            pass
                        elif self.is_struct(value.base_type):
                            pass
                        elif self.is_enum(value.base_type):
                            field_to_json = '    FieldToJson(jdata["{0}"], ToString(obj.{0}), options); // enum\n'
                        else:
                            field_to_json = '    FieldToJson(jdata["{0}"], obj.{0}, options); // base case\n'

                # field_to_json = '    FieldToJson(jdata["{0}"], obj.{0}, options);\n'
                field_to_json = field_to_json.format(value.name, value.array_length)
                body += field_to_json
        return body
    # yapf: enable

    def endFile(self):
        """Method override."""
        code = format_cpp_code('''
            /// Put the custom implementations in the generator Python here rather than
            /// creating a whole new compilation unit for them.
            /// @note, not all of these may be needed for the convert tool if it uses the decoded struct
            /// equivalents so complete the ones with todos as needed on-demand.

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_CLEAR_VALUE& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RESOURCE_BARRIER& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
                FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_TEXTURE_COPY_LOCATION& obj, const JsonOptions& options)
            {
                ; ///< @todo Generate for pResource[None]: ID3D12Resource
                FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SHADER_RESOURCE_VIEW_DESC& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
                FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
                FieldToJson(jdata["Shader4ComponentMapping"], obj.Shader4ComponentMapping, options); // base case
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_SAMPLER_DESC2& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Filter"], ToString(obj.Filter), options); // enum
                FieldToJson(jdata["AddressU"], ToString(obj.AddressU), options); // enum
                FieldToJson(jdata["AddressV"], ToString(obj.AddressV), options); // enum
                FieldToJson(jdata["AddressW"], ToString(obj.AddressW), options); // enum
                FieldToJson(jdata["MipLODBias"], obj.MipLODBias, options); // base case
                FieldToJson(jdata["MaxAnisotropy"], obj.MaxAnisotropy, options); // base case
                FieldToJson(jdata["ComparisonFunc"], ToString(obj.ComparisonFunc), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                FieldToJson(jdata["MinLOD"], obj.MinLOD, options); // base case
                FieldToJson(jdata["MaxLOD"], obj.MaxLOD, options); // base case
                FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_UNORDERED_ACCESS_VIEW_DESC& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
                FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_TARGET_VIEW_DESC& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
                FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_DEPTH_STENCIL_VIEW_DESC& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Format"], ToString(obj.Format), options); // enum
                FieldToJson(jdata["ViewDimension"], ToString(obj.ViewDimension), options); // enum
                FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["ParameterType"], ToString(obj.ParameterType), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                FieldToJson(jdata["ShaderVisibility"], ToString(obj.ShaderVisibility), options); // enum
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_ROOT_PARAMETER1& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["ParameterType"], ToString(obj.ParameterType), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                FieldToJson(jdata["ShaderVisibility"], ToString(obj.ShaderVisibility), options); // enum
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Version"], ToString(obj.Version), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_INDIRECT_ARGUMENT_DESC& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RAYTRACING_GEOMETRY_DESC& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
                FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
                FieldToJson(jdata["Flags"], ToString(obj.Flags), options); // enum
                FieldToJson(jdata["NumDescs"], obj.NumDescs, options); // base case
                FieldToJson(jdata["DescsLayout"], ToString(obj.DescsLayout), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Version"], ToString(obj.Version), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_BEGINNING_ACCESS& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_RENDER_PASS_ENDING_ACCESS& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            void FieldToJson(nlohmann::ordered_json& jdata, const D3D12_BARRIER_GROUP& obj, const JsonOptions& options)
            {
                FieldToJson(jdata["Type"], ToString(obj.Type), options); // enum
                FieldToJson(jdata["NumBarriers"], obj.NumBarriers, options); // base case
                /// @todo FieldToJson(jdata[""], obj., options); // base case
                GFXRECON_LOG_ERROR("Partially implemented FieldToJson() called: \\"" __FUNCTION__ "\\"");
            }

            GFXRECON_END_NAMESPACE(util)
            GFXRECON_END_NAMESPACE(gfxrecon)
        ''')
        write(code, file=self.outFile)
        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)
