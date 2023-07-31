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

import json, inspect
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator, Dx12GeneratorOptions
from dx12_json_consumer_header_generator import Dx12JsonConsumerHeaderGenerator, Dx12JsonConsumerHeaderGeneratorOptions

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
        # The following functions/methods require custom handling
        # @todo Turn these back on and write the code to deal with them.
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
        write('#include "generated_dx12_json_consumer.h"', file=self.outFile)
        write('#include "generated_dx12_enum_to_string.h"', file=self.outFile)
        write('#include "generated_dx12_struct_to_string.h"', file=self.outFile)
        write('#include "decode/dx12_enum_util.h"', file=self.outFile)
        #write('#include "util/interception/injection.h"', file=self.outFile)
        write('#include "util/to_string.h"', file=self.outFile)
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
        code = '\n'
        code += inspect.cleandoc('''
            {{
                using namespace gfxrecon::util;
            '''.format(
                '"' + class_name + '"' if class_name else 'nullptr',
                'object_id' if class_name else '0', class_method_name,
                'std::string()' if not 'void' in return_type else 'std::string()'))
        code += '\n'
        code += self.make_consumer_func_body(class_name, method_info, return_type)
        code += inspect.cleandoc('''
            }
        ''')
        return code

    def make_consumer_func_body(self, class_name, method_info, return_type):
        code = ''
        return code
