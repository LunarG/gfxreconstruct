#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
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

import json, inspect
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator, Dx12GeneratorOptions
from dx12_ascii_consumer_header_generator import Dx12AsciiConsumerHeaderGenerator, Dx12AsciiConsumerHeaderGeneratorOptions

class Dx12AsciiBodyGeneratorOptions(Dx12AsciiConsumerHeaderGeneratorOptions):

    def __init__(
        self,
        constructor_args,
        # Path to JSON file listing Vulkan API calls to override on capture.
        ascii_overrides=None,
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
        Dx12AsciiConsumerHeaderGeneratorOptions.__init__(
            self, constructor_args, blacklists, platform_types, filename,
            directory, prefix_text, protect_file, protect_feature
        )
        self.ascii_overrides = ascii_overrides


class Dx12AsciiConsumerBodyGenerator(Dx12AsciiConsumerHeaderGenerator):

    ASCII_OVERRIDES = {}

    def beginFile(self, genOpts):
# The following functions/methods require custom handling so their declarations
#   are generated, but the definitions are hand written in 
        self.APICALL_BLACKLIST.append('D3D12CreateRootSignatureDeserializer')
        self.METHODCALL_BLACKLIST.append('ID3D12RootSignatureDeserializer_GetRootSignatureDesc')
        self.METHODCALL_BLACKLIST.append('ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc')
        self.METHODCALL_BLACKLIST.append('ID3D12Heap_GetDesc')
        self.METHODCALL_BLACKLIST.append('ID3D12Resource_GetDesc')
        self.METHODCALL_BLACKLIST.append('ID3D12DescriptorHeap_GetDesc')
        self.METHODCALL_BLACKLIST.append('ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart')
        self.METHODCALL_BLACKLIST.append('ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart')
        self.METHODCALL_BLACKLIST.append('ID3D12CommandQueue_GetDesc')
        self.METHODCALL_BLACKLIST.append('ID3D12Device_GetResourceAllocationInfo')
        self.METHODCALL_BLACKLIST.append('ID3D12Device_GetCustomHeapProperties')
        self.METHODCALL_BLACKLIST.append('ID3D12Device_GetAdapterLuid')
        self.METHODCALL_BLACKLIST.append('ID3D12ProtectedResourceSession_GetDesc')
        self.METHODCALL_BLACKLIST.append('ID3D12Device4_GetResourceAllocationInfo1')
        self.METHODCALL_BLACKLIST.append('ID3D12GraphicsCommandList_ResourceBarrier')
        self.METHODCALL_BLACKLIST.append('ID3D12InfoQueue_GetMessage')
        self.METHODCALL_BLACKLIST.append('ID3D12InfoQueue_GetStorageFilter')
        self.METHODCALL_BLACKLIST.append('ID3D12InfoQueue_GetRetrievalFilter')
        self.METHODCALL_BLACKLIST.append('ID3D12Device_CreateRootSignature')
        Dx12AsciiConsumerHeaderGenerator.beginFile(self, genOpts)
        if genOpts.ascii_overrides:
            overrides = json.loads(open(genOpts.ascii_overrides, 'r').read())
            self.ASCII_OVERRIDES = overrides

    def write_include(self):
        write('#include "generated_dx12_ascii_consumer.h"', file=self.outFile)
        write('#include "generated_dx12_enum_to_string.h"', file=self.outFile)
        write('#include "generated_dx12_struct_to_string.h"', file=self.outFile)
        write('#include "decode/custom_dx12_ascii_consumer.h"', file=self.outFile)
        write('#include "decode/dx12_enum_util.h"', file=self.outFile)
        write('#include "util/interception/injection.h"', file=self.outFile)
        write('#include "util/to_string.h"', file=self.outFile)
        self.newline()

    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)
        self.write_dx12_consumer_class('Ascii')

    def get_decoder_class_define(self, consumer_type):
        declaration = ''
        indent = ''
        function_class = 'Dx12{}Consumer::'.format(consumer_type)
        class_end = ''
        return (declaration, indent, function_class, class_end)

    def get_consumer_function_body(self, class_name, method_info, return_type):
        class_method_name = method_info['name']
        is_override = False
        if class_name in self.ASCII_OVERRIDES['classmethods']:
            is_override = class_method_name in self.ASCII_OVERRIDES['classmethods'][class_name]
        if is_override:
            code = '\n{\n    '
            code += self.ASCII_OVERRIDES['classmethods'][class_name][class_method_name] + '(\n'
            code += '        object_id,\n'
            code += '        return_value'
            for parameter in method_info['parameters']:
                code += ', /*TODO*/\n'
                code += '        ' + parameter['name']
            code += ');\n}\n'
        else:
            code = '\n'
            code += inspect.cleandoc('''
                {{
                    using namespace gfxrecon::util;
                    ToStringFlags to_string_flags = kToString_Default;
                    uint32_t tab_count = 0;
                    uint32_t tab_size = 4;
                    WriteApiCallToFileInfo writeApiCallToFileInfo{{}};
                    writeApiCallToFileInfo.pObjectTypeName = {0};
                    writeApiCallToFileInfo.handleId = {1};
                    writeApiCallToFileInfo.pFunctionName = "{2}";
                    std::string returnValue = {3};
                    writeApiCallToFileInfo.pReturnValue = !returnValue.empty() ? returnValue.c_str() : nullptr;
                    WriteApiCallToFile(
                        writeApiCallToFileInfo, to_string_flags, tab_count, tab_size,
                        [&](std::stringstream& str_strm)
                        {{
                '''.format(
                    '"' + class_name + '"' if class_name else 'nullptr',
                    'object_id' if class_name else '0', class_method_name,
                    'DX12ReturnValueToString(return_value, to_string_flags, tab_count, tab_size)' if not 'void' in return_type else 'std::string()'))
            code += '\n'
            code += self.make_consumer_func_body(class_name, method_info, return_type)
            code += inspect.cleandoc('''
                        }
                    );
                }
                ''')
        return code

    def make_consumer_func_body(self, class_name, method_info, return_type):
        code = ''

        # Handle function arguments
        for parameter in method_info['parameters']:
            value = self.get_value_info(parameter)

            # Start with a static_assert() so that if any values make it through the logic
            #   below without being handled the generated code will fail to compile
            to_string = 'static_assert(false, "Unhandled value in `dx12_ascii_consumer_body_generator.py`")'

            # There's some repeated code in this if/else block...It's easier (imo) to reason
            #   about each case when they're all listed explictly
            if value.is_pointer:
                if value.is_array:
                    if self.is_handle(value.base_type):
                        to_string = 'static_assert(false, "Unhandled dynamic array of handles in `dx12_ascii_consumer_body_generator.py`")'
                    elif self.is_struct(value.base_type):
                        to_string = 'PointerDecoderArrayToString({1}, {0}, to_string_flags, tab_count, tab_size)'
                    elif self.is_enum(value.base_type):
                        to_string = 'EnumPointerDecoderArrayToString({1}, {0}, to_string_flags, tab_count, tab_size)'
                    else:
                        to_string = 'PointerDecoderArrayToString({1}, {0}, to_string_flags, tab_count, tab_size)'
                else:
                    if self.is_handle(value.base_type):
                        to_string = 'static_assert(false, "Unhandled pointer to handle in `dx12_ascii_consumer_body_generator.py`")'
                    elif self.is_struct(value.base_type):
                        to_string = 'PointerDecoderToString({0}, to_string_flags, tab_count, tab_size)'
                    elif self.is_enum(value.base_type):
                        to_string = 'EnumPointerDecoderToString({0})'
                    elif self.get_category_type(value.base_type) == 'class' or value.base_type == 'void':
                        to_string = 'HandleIdToString({0})'
                    else:
                        to_string = 'PointerDecoderToString({0}, to_string_flags, tab_count, tab_size)'
            else:
                if value.is_array:
                    if self.is_handle(value.base_type):
                        to_string = 'static_assert(false, "Unhandled static array of handles in `dx12_ascii_consumer_body_generator.py`")'
                    elif self.is_struct(value.base_type):
                        to_string = 'static_assert(false, "Unhandled static array of structures in `dx12_ascii_consumer_body_generator.py`")'
                    elif self.is_enum(value.base_type):
                        to_string = 'static_assert(false, "Unhandled static array of enums in `dx12_ascii_consumer_body_generator.py`")'
                    else:
                        to_string = 'PointerDecoderArrayToString({1}, {0}, to_string_flags, tab_count, tab_size)'
                else:
                    if self.is_handle(value.base_type):
                        to_string = 'static_assert(false, "Unhandled handle in `dx12_ascii_consumer_body_generator.py`")'
                    elif self.is_struct(value.base_type):
                        to_string = 'ToString(*{0}.decoded_value, to_string_flags, tab_count, tab_size)'
                    elif self.is_enum(value.base_type):
                        to_string = '\'"\' + ToString({0}, to_string_flags, tab_count, tab_size) + \'"\''
                    else:
                        to_string = 'ToString({0}, to_string_flags, tab_count, tab_size)'

            first_field = 'true' if not code else 'false'
            value_name = ('[out]' if self.is_output(value) else '') + value.name
            array_length = value.array_length
            if array_length and type(array_length) == str and array_length[0] == '*':
                array_length = array_length.replace('* ', '')
            to_string = to_string.format(value.name, array_length)
            code += '            FieldToString(str_strm, {0}, "{1}", to_string_flags, tab_count, tab_size, {2});\n'.format(first_field, value_name, to_string)
        return code
