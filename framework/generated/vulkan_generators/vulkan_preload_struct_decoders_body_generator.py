#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2020 LunarG, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notiPacketFVulkanStructDecce shall be included in
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
from base_struct_decoders_body_generator import BaseStructDecodersBodyGenerator


class VulkanPreloadStructDecodersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for Vulkan struct decoding."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraVulkanHeaders=[]
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
            extraVulkanHeaders=extraVulkanHeaders
        )


class VulkanPreloadStructDecodersBodyGenerator(
    BaseStructDecodersBodyGenerator, BaseGenerator
):
    """VulkanPreloadStructDecodersBodyGenerator - subclass of BaseGenerator.
    Generates C++ functions for decoding Vulkan API structures.
    Generate C++ functions for Vulkan struct decoding."""

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

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_vulkan_preload_struct_decoders.h"',
            file=self.outFile
        )
        self.newline()
        write(
            '#include "decode/custom_vulkan_struct_decoders.h"',
            file=self.outFile
        )
        write('#include "decode/decode_allocator.h"', file=self.outFile)
        self.newline()
        write('#include <cassert>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()
        write(
            'size_t PreloadDecodePNextStruct(const uint8_t* buffer, size_t buffer_size, PNextNode** pNext);',
            file=self.outFile
        )

    def endFile(self):
        """Method override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        first = True
        for struct in self.get_filtered_struct_names():
            body = '' if first else '\n'
            body += 'size_t PreloadDecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_{}* wrapper)\n'.format(
                struct
            )
            body += '{\n'
            body += '    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));\n'
            body += '\n'
            body += '    size_t bytes_read = 0;\n'
            body += '    {}* value = wrapper->decoded_value;\n'.format(struct)
            body += '\n'
            body += self.make_decode_struct_body(
                struct, self.feature_struct_members[struct]
            )
            body += '\n'
            body += '    return bytes_read;\n'
            body += '}'

            write(body, file=self.outFile)
            first = False

    def make_decode_struct_body(self, name, values):
        """Generate C++ code for the decoder method body."""
        body = ''

        for value in values:
            # pNext fields require special treatment and are not processed by type name
            if 'pNext' in value.name and value.base_type == 'void':
                body += '    bytes_read += PreloadDecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->{}));\n'.format(
                    value.name
                )
                body += '    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;\n'
            else:
                body += self.make_decode_invocation(
                    name, value
                )

        return body

    def make_decode_invocation(self, name, value):
        """Generate the struct member decoder function call invocation."""
        buffer_args = '(buffer + bytes_read), (buffer_size - bytes_read)'

        body = ''

        is_struct = False
        is_class = False
        is_string = False
        is_funcp = False
        is_handle = False
        is_enum = False

        type_name = self.make_invocation_type_name(value.base_type)

        if self.is_struct(type_name):
            is_struct = True
        elif self.is_class(value):
            is_class = True
        elif type_name in ['String', 'WString']:
            is_string = True
        elif type_name == 'FunctionPtr':
            is_funcp = True
        elif self.is_handle(value.base_type):
            is_handle = True
        elif type_name == 'Enum':
            is_enum = True

        # is_pointer will be False for static arrays.
        if value.is_pointer or value.is_array:
            if type_name in self.EXTERNAL_OBJECT_TYPES and not value.is_array:
                # Pointer to an unknown object type, encoded as a 64-bit integer ID.
                body += '    bytes_read += ValueDecoder::DecodeAddress({}, &(wrapper->{}));\n'.format(
                    buffer_args, value.name
                )
                body += '    value->{} = nullptr;\n'.format(value.name)
            else:
                is_static_array = True if (
                    value.is_array and not value.is_dynamic
                ) else False
                access_op = '.'

                if is_struct:
                    body += '    wrapper->{} = DecodeAllocator::Allocate<{}>();\n'.format(
                        value.name, self.make_decoded_param_type(value)
                    )
                    access_op = '->'

                if is_static_array:
                    array_dimension = ''
                    # dx12 treats 2d array as 1d array. EX: [8][2] -> [16], so dx12's 2d array needs *. 
                    # But vk keeps 2d array.
                    if self.is_dx12_class() and value.array_dimension and value.array_dimension > 0:
                        array_dimension = '*'
                    # The pointer decoder will write directly to the struct member's memory.
                    body += '    wrapper->{name}{}SetExternalMemory({}value->{name}, {arraylen});\n'.format(
                        access_op,
                        array_dimension,
                        name=value.name,
                        arraylen=value.array_capacity
                    )

                if is_struct or is_string or is_handle or (
                    is_class and value.pointer_count > 1
                ):
                    body += '    bytes_read += wrapper->{}{}PreloadDecode({});\n'.format(
                        value.name, access_op, buffer_args
                    )
                elif is_class and value.pointer_count == 1:
                    body += '    bytes_read += ValueDecoder::DecodeHandleIdValue({}, &(wrapper->{}));\n'.format(
                        buffer_args, value.name
                    )
                elif self.has_basetype(value.base_type):
                    base_type = self.get_basetype(value.base_type)
                    body += '    bytes_read += wrapper->{}.PreloadDecode{}({});\n'.format(
                        value.name, self.encode_types[base_type], buffer_args
                    )
                else:
                    body += '    bytes_read += wrapper->{}.PreloadDecode{}({});\n'.format(
                        value.name, type_name, buffer_args
                    )

                if not is_static_array:
                    if is_handle or is_class:
                        # Point the real struct's member pointer to the handle pointer decoder's handle memory.
                        body += '    value->{} = nullptr;\n'.format(value.name)
                    else:
                        # Point the real struct's member pointer to the pointer decoder's memory.
                        convert_const_cast_begin = ''
                        convert_const_cast_end = ''

                        if value.full_type.find('LPCWSTR *') != -1:
                            convert_const_cast_end = ')'
                            convert_const_cast_begin = 'const_cast<LPCWSTR*>('

                        elif value.full_type.find('LPCSTR *') != -1:
                            convert_const_cast_end = ')'
                            convert_const_cast_begin = 'const_cast<LPCSTR*>('

                        body += '    value->{name} = {}wrapper->{name}{}GetPointer(){};\n'.format(
                            convert_const_cast_begin,
                            access_op,
                            convert_const_cast_end,
                            name=value.name
                        )
        else:
            if is_struct:
                body += '    wrapper->{} = DecodeAllocator::Allocate<{}>();\n'.format(
                    value.name, self.make_decoded_param_type(value)
                )
                body += '    wrapper->{name}->decoded_value = &(value->{name});\n'.format(
                    name=value.name
                )
                body += '    bytes_read += PreloadDecodeStruct({}, wrapper->{});\n'.format(
                    buffer_args, value.name
                )
            elif is_funcp:
                body += '    bytes_read += ValueDecoder::DecodeAddress({}, &(wrapper->{}));\n'.format(
                    buffer_args, value.name
                )
                body += '    value->{} = nullptr;\n'.format(value.name)
            elif is_handle:
                body += '    bytes_read += ValueDecoder::DecodeHandleIdValue({}, &(wrapper->{}));\n'.format(
                    buffer_args, value.name
                )
                body += '    value->{} = VK_NULL_HANDLE;\n'.format(value.name)
            elif self.is_generic_struct_handle_value(name, value.name):
                body += '    bytes_read += ValueDecoder::DecodeUInt64Value({}, &(wrapper->{}));\n'.format(
                    buffer_args, value.name
                )
                body += '    value->{} = 0;\n'.format(value.name)
            elif value.bitfield_width:
                # Bit fields need to be read into a tempoaray and then assigned to the struct member.
                temp_param_name = 'temp_{}'.format(value.name)
                body += '    {} {};\n'.format(value.base_type, temp_param_name)
                body += '    bytes_read += ValueDecoder::Decode{}Value({}, &{});\n'.format(
                    type_name, buffer_args, temp_param_name
                )
                body += '    value->{} = {};\n'.format(
                    value.name, temp_param_name
                )
            elif is_enum:
                body += '    bytes_read += ValueDecoder::DecodeEnumValue({}, &(value->{}));\n'.format(
                    buffer_args, value.name
                )
            elif self.has_basetype(type_name):
                base_type = self.get_basetype(type_name)
                body += '    bytes_read += ValueDecoder::Decode{}Value({}, &(value->{}));\n'.format(
                    self.encode_types[base_type], buffer_args, value.name
                )
            elif 'Flags' in type_name:
                if 'Flags64' in type_name:
                    body += '    bytes_read += ValueDecoder::DecodeFlags64Value({}, &(value->{}));\n'.format(
                        buffer_args, value.name
                    )
                else:
                    body += '    bytes_read += ValueDecoder::DecodeFlagsValue({}, &(value->{}));\n'.format(
                        buffer_args, value.name
                    )
            else:
                body += '    bytes_read += ValueDecoder::Decode{}Value({}, &(value->{}));\n'.format(
                    type_name, buffer_args, value.name
                )

        return body
