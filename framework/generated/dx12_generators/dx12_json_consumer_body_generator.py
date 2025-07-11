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
from dx12_base_generator import Dx12BaseGenerator, Dx12GeneratorOptions, write
from dx12_json_consumer_header_generator import Dx12JsonConsumerHeaderGenerator, Dx12JsonConsumerHeaderGeneratorOptions
from dx12_json_common_generator import Dx12JsonCommonGenerator
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


class Dx12JsonConsumerBodyGenerator(Dx12JsonConsumerHeaderGenerator, Dx12JsonCommonGenerator):

    JSON_OVERRIDES = {}

    ## @brief A set of tuples, each specifying an argument of a method or function which could be
    ## represented as a binary blob.
    ## The binary file will be named as follows: [<object_name>.]<[method|function]_name>.<argument_name>-<instance_counter>.bin
    BINARY_BLOBS = {
        # Methods:
        ('ID3D12Device', 'CreateRootSignature', 'pBlobWithRootSignature'),
        # Free Functions:
        (None, 'FunctionWithBlob', 'pBlobArgument'), # Example of registering a free function's argument as a binary blob.
    }

    def beginFile(self, genOpts):
        Dx12JsonConsumerHeaderGenerator.beginFile(self, genOpts)
        if genOpts.json_overrides:
            overrides = json.loads(open(genOpts.json_overrides, 'r').read())
            self.JSON_OVERRIDES = overrides

    def write_include(self):
        write(format_cpp_code('''
            #include "generated_dx12_json_consumer.h"
            #include "generated_dx12_enum_to_json.h"
            #include "generated_dx12_struct_decoders_to_json.h"
            #include "decode/dx12_enum_util.h"
            #include "decode/decode_json_util.h"
            #include "decode/json_writer.h"
            #include "util/to_string.h"
            #include "format/format_json.h"
        '''), file=self.outFile)
        self.newline()

    def generate_feature(self):
        write(format_cpp_code('''
            inline bool RepresentBinaryFile(const util::JsonOptions& json_options, nlohmann::ordered_json& jdata, std::string_view filename_base, const uint64_t instance_counter, const PointerDecoder<uint8_t>& data)
            {
                return util::RepresentBinaryFile(json_options, jdata, filename_base, instance_counter, data.GetLength(), data.GetPointer());
            }
        '''), file=self.outFile)
        self.newline()
        Dx12BaseGenerator.generate_feature(self)
        self.write_dx12_consumer_class('Json')

    def get_decoder_class_define(self, consumer_type):
        declaration = ''
        indent = ''
        function_class = 'Dx12{}Consumer::'.format(consumer_type)
        class_end = ''
        return (declaration, indent, function_class, class_end)

    def get_consumer_function_body(self, class_name, method_info, return_type, return_value):
        class_method_name = method_info['name']
        code = '''
            {
                using namespace gfxrecon::util;
        '''
        if(class_name == None or len(class_name) == 0):
            code += self.make_consumer_func_body(method_info, return_type, return_value)
        else:
            code += self.make_consumer_method_body(class_name, method_info, return_type, return_value)

        code += "\n}"
        code = "\n" + format_cpp_code(code)
        return code

    ## Generate a FieldToJson appropriate to the return type.
    ## @param func_type Either "function" or "method" for expected use.
    def make_return(self, func_type, return_value):
        if(None == return_value):
            return ""
        function_name = self.choose_field_to_json_name(return_value)
        ret_line = "{0}({1}[format::kNameReturn], return_value, options);\n"
        ## if return_type.startswith("HANDLE "):
        ## This is a Windows handle, probably to a waitable object so we output it as a JSON number:
        ## <https://learn.microsoft.com/en-us/windows/win32/sysinfo/handles-and-objects>
        ## <https://learn.microsoft.com/en-us/windows/win32/sync/wait-functions>
        ret_line = ret_line.format(function_name, func_type)
        return ret_line

    def make_consumer_func_body(self, method_info, return_type, return_value):
        # Deal with the function's returned value:
        if return_type != 'HRESULT WINAPI':
            print ("Warning - Unexpected return type:", return_type)
        ret_line = self.make_return("function", return_value)

        code = '''
            nlohmann::ordered_json& function = writer_->WriteApiCallStart(call_info, "{}");
            const JsonOptions& options = writer_->GetOptions();
        '''
        code += ret_line
        code += '''nlohmann::ordered_json& args = function[format::kNameArgs];
            {{
        '''
        # Generate a correct FieldToJson for each argument:
        for parameter in method_info['parameters']:
            value = self.get_value_info(parameter)
            code += "    " + self.make_field_to_json(None, method_info['name'], value, "options") + "\n"

        code += remove_leading_empty_lines('''
                }}
            writer_->WriteBlockEnd();
        ''')
        code = code.format(method_info['name'])
        return code

    def make_consumer_method_body(self, class_name, method_info, return_type, return_value):
        code = '''
            nlohmann::ordered_json& method = writer_->WriteApiCallStart(call_info, "{0}", object_id, "{1}");
            const JsonOptions& options = writer_->GetOptions();
        '''

        # Deal with the function's returned value:
        ret_line = self.make_return("method", return_value)
        code += ret_line

        # Deal with function argumentS:
        if len(method_info['parameters']) > 0:
            code += '''nlohmann::ordered_json& args = method[format::kNameArgs];
                {{
            '''
            # Generate a correct FieldToJson for each argument:
            for parameter in method_info['parameters']:
                value = self.get_value_info(parameter)
                code += "    " + self.make_field_to_json(class_name, method_info['name'], value, "options") + "\n"
            code += "}}\n"

        code += "writer_->WriteBlockEnd();"
        code = code.format(class_name, method_info['name'])
        return code

    ## @param value_info A ValueInfo object from base_generator.py.
    def make_field_to_json(self, class_name, function_name, value_info, options_name):
        # Handle arguments that are pointers to binary blobs:
        if (class_name, function_name, value_info.name) in self.BINARY_BLOBS:
            field_to_json  = '        static thread_local uint64_t {2}_counter{{{{ 0 }}}};\n'
            if class_name == None:
                # A function argument:
                field_to_json += '        const bool written = RepresentBinaryFile(options, args["{2}"], "{1}.{2}", {2}_counter, {2});\n'
            else:
                # A method argument:
                field_to_json += '        const bool written = RepresentBinaryFile(options, args["{2}"], "{0}.{1}.{2}", {2}_counter, *{2});\n'
            field_to_json += '        {2}_counter += written;\n'
            field_to_json = field_to_json.format(class_name, function_name, value_info.name)
            return field_to_json

        # Handle arguments that are not pointers to binary blobs:

        field_to_json_name = self.choose_field_to_json_name(value_info)
        src = value_info.name
        ## Special case for pointers to flag sets defined by enums:
        ## (easier than having pointer decoder versions of each flagset type's FieldToString)
        if value_info.is_pointer and field_to_json_name.startswith("FieldToJson_"):
            src = "*" + src + "->GetPointer()"
        field_to_json = '{0}({1}["{2}"], {3}, {4});'.format(field_to_json_name, "args", value_info.name, src, options_name)
        if "anon-union" in value_info.base_type:
            field_to_json += "// [anon-union] "
            print("ALERT: anon union " + value_info.name)

        return field_to_json