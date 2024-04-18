#!/usr/bin/python3 -i
#
# Copyright (c) 2022-2024 LunarG, Inc.
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
from base_generator import BaseGenerator, BaseGeneratorOptions, write
from reformat_code import format_cpp_code, indent_cpp_code, remove_trailing_newlines


class OpenXrExportJsonConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for OpenXR capture file to JSON file generation."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraOpenXrHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraOpenXrHeaders=extraOpenXrHeaders
        )


class OpenXrExportJsonConsumerBodyGenerator(BaseGenerator):
    """OpenXrExportJsonConsumerBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the OpenXrExportJsonConsumer class responsible for
    generating a textfile containing decoded OpenXR API call parameter data.
    Generate a C++ class for OpenXR capture file to JSON file generation.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=False,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        self.flagsType = dict()
        self.flagsTypeAlias = dict()
        self.flagEnumBitsType = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        includes = format_cpp_code(
            '''
            #include "util/defines.h"
            #include "generated/generated_openxr_json_consumer.h"
            #include "decode/custom_openxr_struct_to_json.h"
        '''
        )
        write(includes, file=self.outFile)
        self.includeOpenXrHeaders(gen_opts)
        namespace = remove_trailing_newlines(
            indent_cpp_code(
                '''
            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)

            using util::JsonOptions;
        '''
            )
        )
        write(namespace, file=self.outFile)

    def endFile(self):
        """Method override."""
        body = format_cpp_code(
            '''
            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)
        '''
        )
        write(body, file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        first = True

        for cmd in self.get_filtered_cmd_names():
            info = self.feature_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.make_consumer_func_decl(
                return_type, 'OpenXrExportJsonConsumer::Process_' + cmd, values
            ) + '\n'
            cmddef += format_cpp_code(
                '''
                {{
                    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "{0}");
                    const JsonOptions& json_options = GetJsonOptions();
                '''.format(cmd)
            )
            cmddef += '\n'
            cmddef += self.make_consumer_func_body(return_type, cmd, values)
            cmddef += format_cpp_code(
                '''
                    WriteBlockEnd();
                }
            ''', 1
            )
            write(cmddef, file=self.outFile)
            first = False

    def is_command_buffer_cmd(self, command):
        if 'vkCmd' in command:
            return True
        return False

    # yapf: disable
    def make_consumer_func_body(self, return_type, name, values):
        """Return OpenXrExportJsonConsumer class member function definition."""
        body = ''

        # Handle function return value
        if 'XrBool32' == return_type:
            # Output as JSON boolean type true/false without quotes:
            body += '            Bool32ToJson(jdata[NameReturn()], returnValue, json_options);\n'
        elif self.is_handle(return_type):
            body += '    HandleToJson(jdata[NameReturn()], returnValue, json_options);\n'
        # Enums, ints, etc. handled by default and static dispatch based on C++ type:
        elif not 'void' in return_type:
            body += '    FieldToJson(jdata[NameReturn()], returnValue, json_options);\n'

        if len(values) > 0:
            body += '    auto& args = jdata[NameArgs()];\n'
            # Handle function arguments
            for value in values:
                flagsEnumType = value.base_type

                # Default to letting the right function overload to be resolved based on argument types,
                # including enums, strings ints, floats etc.:
                # Note there are overloads for scalars and pointers/arrays.
                if not (value.is_pointer or value.is_array) and self.is_struct(value.base_type):
                    to_json = 'FieldToJson(args["{0}"], &{0}, json_options)'
                else:
                    to_json = 'FieldToJson(args["{0}"], {0}, json_options)'

                # Special cases:
                if 'VkBool32' == value.base_type:
                    to_json = 'Bool32ToJson(args["{0}"], {0}, json_options)'
                elif self.is_handle(value.base_type):
                    to_json = 'HandleToJson(args["{0}"], {0}, json_options)'
                elif self.is_flags(value.base_type):
                    if value.base_type in self.flagsTypeAlias:
                        flagsEnumType = self.flagsTypeAlias[value.base_type]
                    if not (value.is_pointer or value.is_array):
                        to_json = 'FieldToJson({2}_t(), args["{0}"], {0}, json_options)'
                    else:
                        # Default to outputting as the raw type but warn:
                        print("Missing conversion of pointers to", flagsEnumType, "in", name,  file=sys.stderr)

                to_json = to_json.format(value.name, value.base_type, flagsEnumType)
                body += '        {0};\n'.format(to_json)
        return body
    # yapf: enable

    def genType(self, typeinfo, name, alias):
        super().genType(typeinfo, name, alias)
        if self.is_flags(name):
            if alias is None:
                self.flagsType[name] = self.flags_types[name]
                bittype = typeinfo.elem.get('requires')
                if bittype is None:
                    bittype = typeinfo.elem.get('bitvalues')
                if bittype is not None:
                    self.flagEnumBitsType[bittype] = name
            else:
                self.flagsTypeAlias[name] = alias
