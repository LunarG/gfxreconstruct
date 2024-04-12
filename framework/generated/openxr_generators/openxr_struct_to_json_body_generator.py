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
#

import sys
from base_generator import *
from reformat_code import format_cpp_code, indent_cpp_code, remove_leading_empty_lines, remove_trailing_newlines


class OpenXrStructToJsonBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for serializing OpenXR structures to JSON"""

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


# OpenXrStructToJsonBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions for serializing OpenXr API structures to JSON.
class OpenXrStructToJsonBodyGenerator(BaseGenerator):
    """Generate C++ functions for OpenXR FieldToJson(...) functions"""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=False,
            process_structs=True,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        self.pnext_extension_structs = dict()
        self.flagsType = dict()
        self.flagsTypeAlias = dict()
        self.flagEnumBitsType = dict()

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        body = format_cpp_code(
            '''
            #include "generated_openxr_struct_to_json.h"
            #include "generated_vulkan_struct_to_json.h"
            #include "generated_openxr_enum_to_json.h"
            #include "generated_vulkan_enum_to_json.h"
            #include "util/to_string.h"

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)
            using util::JsonOptions;
            using util::to_hex_variable_width;
            using util::uuid_to_string;
        '''
        )
        body += "\n"
        write(body, file=self.outFile)

    # Method override
    def endFile(self):
        body = '''
            void FieldToJson(nlohmann::ordered_json& jdata, const OpenXrNextNode* data, const JsonOptions& options)
            {
                if (data && data->GetPointer())
                {
                    const auto type = reinterpret_cast<const XrBaseInStructure*>(data->GetPointer())->type;
                    switch (type)
                    {'''
        body += self.make_next_body()
        body += '''
                        default:
                        {
                            GFXRECON_LOG_WARNING("Unknown next node type: %u.", (unsigned)type);
                        }
                    }
                }
            }

            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)
        '''
        body = remove_trailing_newlines(indent_cpp_code(body))
        write(body, file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        self.feature_break = False
        if self.feature_struct_members:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generate_feature(self):
        for struct in self.get_filtered_struct_names():
            body = '''
                void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_{0}* data, const JsonOptions& options)
                {{
                    if (data && data->decoded_value)
                    {{
                        const {0}& decoded_value = *data->decoded_value;
                        const Decoded_{0}& meta_struct = *data;

                '''.format(struct)
            body += self.makeStructBody(
                struct, self.feature_struct_members[struct]
            )
            body += remove_leading_empty_lines(
                '''
                    }
                }
                '''
            )
            body = remove_trailing_newlines(indent_cpp_code(body))
            write(body, file=self.outFile)

    #
    # Command definition
    def makeStructBody(self, name, values):
        body = ''
        has_next = False
        for value in values:
            type_name = self.make_decoded_param_type(value)
            flagsEnumType = value.base_type

            if value.name == 'next':
                # move pnext to be the last member
                has_next = True
                continue

            # Default to getting the data from the native OpenXr struct:
            to_json = 'FieldToJson(jdata["{0}"], decoded_value.{0}, options)'

            if value.base_type.startswith('PFN_') or 'userData' in value.name:
                to_json = 'FieldToJson(jdata["{0}"], to_hex_variable_width(meta_struct.{0}), options)'
            elif value.is_pointer:
                if 'String' in type_name:
                    to_json = 'FieldToJson(jdata["{0}"], &meta_struct.{0}, options)'
                elif self.is_handle(value.base_type):
                    to_json = 'HandleToJson(jdata["{0}"], &meta_struct.{0}, options)'
                elif 'XrBool32' == value.base_type:
                    to_json = 'Bool32ToJson(jdata["{0}"], &meta_struct.{0})'
                else:
                    to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
            else:
                if value.is_array:
                    if 'UUID' in value.array_length or 'LUID' in value.array_length:
                        to_json = 'FieldToJson(jdata["{0}"], uuid_to_string(sizeof(decoded_value.{0}), decoded_value.{0}), options)'
                    elif 'String' in type_name:
                        to_json = 'FieldToJson(jdata["{0}"], &meta_struct.{0}, options)'
                    elif self.is_handle(value.base_type):
                        to_json = 'HandleToJson(jdata["{0}"], &meta_struct.{0}, options)'
                    elif self.is_struct(value.base_type):
                        to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
                    elif 'XrBool32' == value.base_type:
                        # Currently unused:
                        to_json = 'Bool32ToJson(jdata["{0}"], &meta_struct.{0})'
                    elif not value.is_dynamic:
                        to_json = 'FieldToJson(jdata["{0}"], &meta_struct.{0}, options)'
                    else:
                        to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
                else:
                    if self.is_handle(value.base_type):
                        to_json = 'HandleToJson(jdata["{0}"], meta_struct.{0}, options)'
                    elif self.is_struct(value.base_type):
                        to_json = 'FieldToJson(jdata["{0}"], meta_struct.{0}, options)'
                    elif self.is_flags(value.base_type):
                        if value.base_type in self.flagsTypeAlias:
                            flagsEnumType = self.flagsTypeAlias[value.base_type
                                                                ]
                        to_json = 'FieldToJson({2}_t(),jdata["{0}"], decoded_value.{0}, options)'
                    elif self.is_enum(value.base_type):
                        to_json = 'FieldToJson(jdata["{0}"], decoded_value.{0}, options)'
                    elif 'XrBool32' == value.base_type:
                        to_json = 'jdata["{0}"] = static_cast<bool>(decoded_value.{0})'

            to_json = to_json.format(
                value.name, value.base_type, flagsEnumType
            )
            body += '        {0};\n'.format(to_json)
        # Save next as last member
        if has_next:
            body += '        FieldToJson(jdata["next"], meta_struct.next, options);\n'

        return body

    def genStruct(self, typeinfo, typename, alias):
        super().genStruct(typeinfo, typename, alias)

        if not alias:
            if typeinfo.elem.get('structextends'):
                pnext_extension_struct = self.make_structure_type_enum(
                    typeinfo, typename
                )
                if pnext_extension_struct:
                    self.pnext_extension_structs[typename
                                                 ] = pnext_extension_struct

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

    def make_next_body(self):
        body = ''
        for struct in self.pnext_extension_structs:
            body += '''
            case {1}:
            {{
               const auto* next = reinterpret_cast<const Decoded_{0}*>(data->GetMetaStructPointer());
               FieldToJson(jdata, next, options);
               break;
            }}
            '''.format(struct, self.pnext_extension_structs[struct])
        return body
