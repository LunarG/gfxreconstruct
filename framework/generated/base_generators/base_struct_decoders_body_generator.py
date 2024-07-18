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

import re
import sys
from base_generator import write
from copy import deepcopy


class BaseStructDecodersBodyGenerator():
    """Base class for generating struct docoder body code."""

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        first = True
        for struct in self.get_filtered_struct_names():
            body = '' if first else '\n'
            body += 'size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_{}* wrapper)\n'.format(
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
        preamble = ''
        main_body = ''
        epilogue = ''

        for value in values:
            # pNext fields require special treatment and are not processed by type name
            if 'pNext' in value.name and value.base_type == 'void':
                main_body += '    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->{}));\n'.format(
                    value.name
                )
                main_body += '    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;\n'
            elif 'next' == value.name and value.base_type == 'void':
                main_body += '    bytes_read += DecodeNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->{}));\n'.format(
                    value.name
                )
                main_body += '    value->next = wrapper->next ? wrapper->next->GetPointer() : nullptr;\n'
            else:
                preamble, main_body, epilogue = BaseStructDecodersBodyGenerator.make_decode_invocation(
                    self, name, value, preamble, main_body, epilogue
                )

        if len(preamble) > 0:
            preamble += '\n'
        body = preamble + main_body + epilogue
        return body

    def make_decode_invocation(self, name, value, preamble, main_body, epilogue):
        """Generate the struct member decoder function call invocation."""
        buffer_args = '(buffer + bytes_read), (buffer_size - bytes_read)'

        is_struct = False
        is_class = False
        is_string = False
        is_funcp = False
        is_handle = False
        is_enum = False
        is_atom = False

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
        elif self.is_atom(value.base_type):
            is_atom = True
        elif type_name == 'Enum':
            is_enum = True

        # is_pointer will be False for static arrays.
        if value.is_pointer or value.is_array:
            if type_name in self.EXTERNAL_OBJECT_TYPES and not value.is_array:
                # Pointer to an unknown object type, encoded as a 64-bit integer ID.
                main_body += '    bytes_read += ValueDecoder::DecodeAddress({}, &(wrapper->{}));\n'.format(
                    buffer_args, value.name
                )
                main_body += '    value->{} = nullptr;\n'.format(value.name)
            else:
                is_static_array = True if (
                    value.is_array and not value.is_dynamic
                ) else False
                access_op = '.'

                if value.base_type in self.base_header_structs.keys():
                    if value.pointer_count == 1:
                        main_body += f'    switch (wrapper->{value.name}->GetPointer()->type)\n'
                        main_body += '    {\n'
                        main_body += '        default:\n'
                        main_body += '            wrapper->{} = DecodeAllocator::Allocate<{}>();\n'.format(
                            value.name, self.make_decoded_param_type(value)
                        )

                        if is_static_array:
                            array_dimension = ''
                            # The pointer decoder will write directly to the struct member's memory.
                            main_body += '            wrapper->{name}->SetExternalMemory({}value->{name}, {arraylen});\n'.format(
                                array_dimension,
                                name=value.name,
                                arraylen=value.array_capacity
                            )
                        main_body += '            bytes_read += wrapper->{}->Decode({});\n'.format(
                            value.name, buffer_args
                        )
                        main_body += '            break;\n'
                        for child in self.base_header_structs[value.base_type]:
                            type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', child)
                            type = type.upper()
                            switch_type = re.sub('XR_', 'XR_TYPE_', type)
                            if 'OPEN_GLESFB' in switch_type:
                                type = switch_type
                                switch_type = re.sub('OPEN_GLESFB', 'OPENGL_ES_FB', type)

                            new_value = deepcopy(value)
                            new_value.base_type = child
                            decode_type = self.make_decoded_param_type(new_value)
                            var_name = value.name + '_' + child.lower()
                            preamble += f'    {decode_type}* {var_name};\n'

                            main_body += f'        case {switch_type}:\n'
                            main_body += '            {} = DecodeAllocator::Allocate<{}>();\n'.format(
                                var_name, decode_type
                            )
                            main_body += '            bytes_read += {}->Decode({});\n'.format(
                                var_name, buffer_args
                            )
                            main_body += '            wrapper->{} = std::move(reinterpret_cast<StructPointerDecoder<Decoded_{}>*>({}));\n'.format(
                                value.name, value.base_type, var_name
                            )
                            main_body += '            break;\n'
                        main_body += '    }\n'
                    else:
                        # TODO: Doesn't currently support arrays of pointers
                        main_body += '    wrapper->{} = DecodeAllocator::Allocate<{}>();\n'.format(
                            value.name, self.make_decoded_param_type(value)
                        )
                else:
                    if is_struct:
                        main_body += '    wrapper->{} = DecodeAllocator::Allocate<{}>();\n'.format(
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
                        main_body += '    wrapper->{name}{}SetExternalMemory({}value->{name}, {arraylen});\n'.format(
                            access_op,
                            array_dimension,
                            name=value.name,
                            arraylen=value.array_capacity
                        )

                    if is_struct or is_string or is_handle or is_atom or (
                        is_class and value.pointer_count > 1
                    ):
                        main_body += '    bytes_read += wrapper->{}{}Decode({});\n'.format(
                            value.name, access_op, buffer_args
                        )
                    elif is_class and value.pointer_count == 1:
                        main_body += '    bytes_read += ValueDecoder::DecodeHandleIdValue({}, &(wrapper->{}));\n'.format(
                            buffer_args, value.name
                        )
                    elif self.has_basetype(value.base_type):
                        base_type = self.get_basetype(value.base_type)
                        main_body += '    bytes_read += wrapper->{}.Decode{}({});\n'.format(
                            value.name, self.encode_types[base_type], buffer_args
                        )
                    else:
                        main_body += '    bytes_read += wrapper->{}.Decode{}({});\n'.format(
                            value.name, type_name, buffer_args
                        )

                    if not is_static_array:
                        if is_handle or is_atom or is_class:
                            # Point the real struct's member pointer to the handle pointer decoder's handle memory.
                            main_body += '    value->{} = nullptr;\n'.format(value.name)
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

                            main_body += '    value->{name} = {}wrapper->{name}{}GetPointer(){};\n'.format(
                                convert_const_cast_begin,
                                access_op,
                                convert_const_cast_end,
                                name=value.name
                            )
        else:
            if is_struct:
                if value.base_type in self.base_header_structs.keys():
                    main_body += f'        switch ({value.name}->GetPointer()->type)\n'
                    main_body += '        {\n'
                    main_body += '            default:\n'
                    main_body += '                wrapper->{} = DecodeAllocator::Allocate<{}>();\n'.format(
                        value.name, self.make_decoded_param_type(value)
                    )
                    main_body += '                wrapper->{name}->decoded_value = &(value->{name});\n'.format(
                        name=value.name
                    )
                    main_body += '                bytes_read += DecodeStruct({}, wrapper->{});\n'.format(
                        buffer_args, value.name
                    )
                    main_body += '                break;\n'
                    for child in self.base_header_structs[value.base_type]:
                        type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', child)
                        type = type.upper()
                        switch_type = re.sub('XR_', 'XR_TYPE_', type)
                        if 'OPEN_GLESFB' in switch_type:
                            type = switch_type
                            switch_type = re.sub('OPEN_GLESFB', 'OPENGL_ES_FB', type)

                        new_value = deepcopy(value)
                        new_value.base_type = child
                        decode_type = self.make_decoded_param_type(new_value)
                        var_name = value.name + '_' + child.lower()
                        preamble += f'    {decode_type}* {var_name};\n'

                        main_body += f'            case {switch_type}:\n'

                        main_body += '            {} = DecodeAllocator::Allocate<{}>();\n'.format(
                            var_name, decode_type
                        )
                        main_body += '            bytes_read += {}->Decode({});\n'.format(
                            var_name, buffer_args
                        )
                        main_body += '            wrapper->{} = std::move(reinterpret_cast<StructPointerDecoder<Decoded_{}>*>({}));\n'.format(
                            value.name, value.base_type, var_name
                        )
                        main_body += '            break;\n'
                    main_body += '        }\n'
                else:
                    main_body += '    wrapper->{} = DecodeAllocator::Allocate<{}>();\n'.format(
                        value.name, self.make_decoded_param_type(value)
                    )
                    main_body += '    wrapper->{name}->decoded_value = &(value->{name});\n'.format(
                        name=value.name
                    )
                    main_body += '    bytes_read += DecodeStruct({}, wrapper->{});\n'.format(
                        buffer_args, value.name
                    )
            elif is_funcp:
                main_body += '    bytes_read += ValueDecoder::DecodeAddress({}, &(wrapper->{}));\n'.format(
                    buffer_args, value.name
                )
                main_body += '    value->{} = nullptr;\n'.format(value.name)
            elif is_handle or is_atom:
                main_body += '    bytes_read += ValueDecoder::DecodeHandleIdValue({}, &(wrapper->{}));\n'.format(
                    buffer_args, value.name
                )
                default_type = self.get_default_handle_atom_value(value.base_type)
                main_body += '    value->{} = {};\n'.format(value.name, default_type)
            elif self.is_generic_struct_handle_value(name, value.name):
                main_body += '    bytes_read += ValueDecoder::DecodeUInt64Value({}, &(wrapper->{}));\n'.format(
                    buffer_args, value.name
                )
                main_body += '    value->{} = 0;\n'.format(value.name)
            elif value.bitfield_width:
                # Bit fields need to be read into a tempoaray and then assigned to the struct member.
                temp_param_name = 'temp_{}'.format(value.name)
                main_body += '    {} {};\n'.format(value.base_type, temp_param_name)
                main_body += '    bytes_read += ValueDecoder::Decode{}Value({}, &{});\n'.format(
                    type_name, buffer_args, temp_param_name
                )
                main_body += '    value->{} = {};\n'.format(
                    value.name, temp_param_name
                )
            elif is_enum:
                main_body += '    bytes_read += ValueDecoder::DecodeEnumValue({}, &(value->{}));\n'.format(
                    buffer_args, value.name
                )
            elif self.has_basetype(type_name):
                base_type = self.get_basetype(type_name)
                main_body += '    bytes_read += ValueDecoder::Decode{}Value({}, &(value->{}));\n'.format(
                    self.encode_types[base_type], buffer_args, value.name
                )
            elif 'Flags' in type_name:
                if 'Flags64' in type_name:
                    main_body += '    bytes_read += ValueDecoder::DecodeFlags64Value({}, &(value->{}));\n'.format(
                        buffer_args, value.name
                    )
                else:
                    main_body += '    bytes_read += ValueDecoder::DecodeFlagsValue({}, &(value->{}));\n'.format(
                        buffer_args, value.name
                    )
            else:
                main_body += '    bytes_read += ValueDecoder::Decode{}Value({}, &(value->{}));\n'.format(
                    type_name, buffer_args, value.name
                )

        return preamble, main_body, epilogue
