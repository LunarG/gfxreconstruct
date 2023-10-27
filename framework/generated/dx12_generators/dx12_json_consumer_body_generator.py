#!/usr/bin/env python3
#
# Copyright (c) 2021, 2023 LunarG, Inc.
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

import json
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator, Dx12GeneratorOptions
from dx12_json_consumer_header_generator import Dx12JsonConsumerHeaderGenerator, Dx12JsonConsumerHeaderGeneratorOptions
from reformat_code import format_cpp_code, remove_leading_empty_lines


class Dx12JsonBodyGeneratorOptions(Dx12JsonConsumerHeaderGeneratorOptions):

    def __init__(
        self,
        constructor_args,
        # Path to JSON file listing Vulkan API calls to override on capture.
        json_overrides=None,
        # Path to JSON file listing apicalls and structs to ignore.
        blacklists=None,
        # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        platform_types=None,
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True
    ):
        Dx12JsonConsumerHeaderGeneratorOptions.__init__(
            self, constructor_args, blacklists, platform_types, filename,
            directory, prefix_text, protect_file, protect_feature
        )
        self.json_overrides = json_overrides


class Dx12JsonConsumerBodyGenerator(Dx12JsonConsumerHeaderGenerator):

    JSON_OVERRIDES = {}

    def beginFile(self, genOpts):
        # The following functions/methods may require custom handling
        # @todo Turn Evaluate each of these, turn them back on in a blocklists.json and write the code to deal with them.
        # -- self.APICALL_BLACKLIST.append('D3D12CreateRootSignatureDeserializer')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12RootSignatureDeserializer_GetRootSignatureDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Heap_GetDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Resource_GetDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12DescriptorHeap_GetDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12CommandQueue_GetDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device_GetResourceAllocationInfo')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device_GetCustomHeapProperties')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device_GetAdapterLuid')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12ProtectedResourceSession_GetDesc')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device4_GetResourceAllocationInfo1')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12GraphicsCommandList_ResourceBarrier')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12InfoQueue_GetMessage')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12InfoQueue_GetStorageFilter')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12InfoQueue_GetRetrievalFilter')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device_CreateRootSignature')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12CommandList_GetType')
        # -- self.METHODCALL_BLACKLIST.append('ID3D12Device1_CreatePipelineLibrary')
        Dx12JsonConsumerHeaderGenerator.beginFile(self, genOpts)
        if genOpts.json_overrides:
            overrides = json.loads(open(genOpts.json_overrides, 'r').read())
            self.JSON_OVERRIDES = overrides

    def write_include(self):
        write(format_cpp_code('''
            /// @todo Optimise this include list. Pos, only include most specific [util|decode]/x_json_util.h variant since we have the convention that they include each other.
            #include "generated_dx12_json_consumer.h"
            #include "generated_dx12_enum_to_json.h"
            #include "generated_dx12_struct_decoders_to_json.h"
            #include "decode/dx12_enum_util.h"
            #include "decode/dx12_decode_json_util.h"
            #include "decode/decode_json_util.h"
            #include "decode/json_writer.h"
            #include "util/to_string.h"
            #include "format/format_json.h"
        '''), file=self.outFile)
        self.newline()

    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)
        self.write_dx12_consumer_class('Json')

    def get_decoder_class_define(self, consumer_type):
        declaration = ''
        indent = ''
        function_class = 'Dx12{}Consumer::'.format(consumer_type)
        class_end = ''
        return (declaration, indent, function_class, class_end)

    def get_consumer_function_body(self, class_name, method_info, return_type):
        class_method_name = method_info['name']
        code = '''
            {
                using namespace gfxrecon::util;
        '''
        if(class_name == None or len(class_name) == 0):
            code += self.make_consumer_func_body(method_info, return_type)
        else:
            code += self.make_consumer_method_body(class_name, method_info, return_type)

        code += "\n}"
        code = "\n" + format_cpp_code(code)
        return code

    def make_consumer_func_body(self, method_info, return_type):
        if return_type != 'HRESULT WINAPI':
            print ("Warning - Unexpected return type:", return_type)
        code = '''
            nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "{}");
            const JsonOptions& options = writer_->GetOptions();

            FieldToJson(function[format::kNameReturn], return_value, options);
            nlohmann::ordered_json& args = function[format::kNameArgs];
            {{
        '''
        # Generate a correct FieldToJson for each argument:
        for parameter in method_info['parameters']:
            value = self.get_value_info(parameter)
            code += "    " + self.make_field_to_json("args", value, "options") + "\n"

        code += remove_leading_empty_lines('''
                }}
            writer_->WriteBlockEnd();
        ''')
        code = code.format(method_info['name'])
        return code

    def make_consumer_method_body(self, class_name, method_info, return_type):
        code = '''
            nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "{0}", object_id, "{1}");
            const JsonOptions& options = writer_->GetOptions();
        '''
        if not "void" in return_type:
            #if method_info.returns_pointer:
            #    code += "FieldToJson(method[format::kNameReturn], return_value, options);"
            #else:
            code += "FieldToJson(method[format::kNameReturn], return_value, options);\n"
        else:
            code += "// Nothing returned from method.\n"
        if len(method_info['parameters']) > 0:
            code += '''nlohmann::ordered_json& args = method[format::kNameArgs];
                {{
            '''
            # Generate a correct FieldToJson for each argument:
            for parameter in method_info['parameters']:
                value = self.get_value_info(parameter)
                code += "    " + self.make_field_to_json("args", value, "options") + "\n"
            code += "}}\n"

        code += "writer_->WriteBlockEnd();"
        code = code.format(class_name, method_info['name'])
        return code

    ## @todo Move this to a common base class shared with Dx12StructDecodersToJsonBodyGenerator
    ## if the types used for arguments and struct properties are compatible.
    def make_field_to_json(self, parent_name, value, options_name):
        field_to_json = '/// @todo FieldToJson({0}["{1}"], {1}, {2})'.format(parent_name, value.name, options_name)
        if value.is_pointer:
            if value.is_array:
                pass
            else:
                field_to_json = self.make_pointer_field_to_json(parent_name, value, options_name)
        else:
            if value.is_array:
                pass
            else:
                if self.is_handle(value.base_type):
                    field_to_json = 'static_assert(false, "Unhandled handle.")'
                else:
                    field_to_json = 'FieldToJson({0}["{1}"], {1}, {2});'.format(parent_name, value.name, options_name)

        return field_to_json

    # Generate a FieldToJson for a pointer to a non-array.
    def make_pointer_field_to_json(self, parent_name, value, options_name):
        # Pointer to POD, struct, enum, string all have same signature:
        ## @todo BOOL?
        field_to_json = 'FieldToJson({0}["{1}"], {1}, {2});'.format(parent_name, value.name, options_name)
        return field_to_json
