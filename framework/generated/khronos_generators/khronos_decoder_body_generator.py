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
from khronos_base_generator import ValueInfo, write
from copy import deepcopy


class KhronosDecoderBodyGenerator():
    """Khronos class for generating decoder body code."""

    def skip_generating_command(self, command):
        """ Method may be overridden. """
        return self.is_manually_generated_cmd_name(command)

    def generate_commands(self):
        platform_type = self.get_api_prefix()

        first = True
        for cmd in self.get_all_filtered_cmd_names():
            if self.is_manually_generated_cmd_name(cmd):
                continue

            info = self.all_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += 'size_t {}Decoder::Decode_{}(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)\n'.format(
                platform_type, cmd
            )
            cmddef += '{\n'
            cmddef += '    size_t bytes_read = 0;\n'
            cmddef += '\n'
            cmddef += self.make_cmd_body(return_type, cmd, values)
            cmddef += '\n'
            cmddef += '    return bytes_read;\n'
            cmddef += '}'

            write(cmddef, file=self.outFile)
            first = False

    def make_cmd_body(self, return_type, name, values):
        """Generate C++ code for the decoder method body."""
        preamble = ''
        main_body = ''
        epilogue = ''
        arg_names = []
        has_base_header_to_peak = False

        # Declarations for decoded types.
        for value in values:
            is_base_header_value = False
            # If the value is a base header type, we need to do some work to read the actual
            # structure that is used, and then pass the information down.
            if value.base_type in self.children_structs.keys():
                has_base_header_to_peak = True
                is_base_header_value    = True
                decode_type = self.make_decoded_param_type(value)
                main_body += '    {}* {};\n'.format(decode_type, value.name)
                main_body += '    {} {};\n'.format(decode_type, self.make_simple_var_name(value.base_type))
                for child in self.children_structs[value.base_type]:
                    new_value = deepcopy(value)
                    new_value.base_type = child
                    decode_type = self.make_decoded_param_type(new_value)
                    main_body += '    {} {};\n'.format(decode_type, self.make_simple_var_name(child))
            else:
                decode_type = self.make_decoded_param_type(value)
                main_body += '    {} {};\n'.format(decode_type, value.name)

            if decode_type == 'Decoded_{}'.format(value.base_type):
                main_body += '    {} value_{};\n'.format(
                    value.base_type, value.name
                )
                main_body += '    {0}.decoded_value = &value_{0};\n'.format(
                    value.name
                )

            # For base header values, we'll use the pointer variable which uses the default value.name
            # and not dereference it.
            if is_base_header_value:
                arg_names.append(value.name)
            elif 'Decoder' in decode_type:
                arg_names.append('&{}'.format(value.name))
            else:
                arg_names.append(value.name)

        if return_type and return_type != 'void':
            main_body += '    {} return_value;\n'.format(return_type)

        # Blank line after declarations.
        if values or return_type:
            main_body += '\n'

        if has_base_header_to_peak:
            main_body += '    bool     peak_is_null    = false;\n'
            main_body += '    bool     peak_is_struct  = false;\n'
            main_body += '    bool     peak_has_length = false;\n'
            main_body += '    size_t   peak_length{};\n'
            main_body += '    uint32_t peak_structure_type = 0;\n'

        # Decode() method calls for pointer decoder wrappers.
        for value in values:
            preamble, main_body, epilogue = KhronosDecoderBodyGenerator.make_decode_invocation(
                self, value, preamble, main_body, epilogue
            )
        if return_type and return_type != 'void':
            preamble, main_body, epilogue = KhronosDecoderBodyGenerator.make_decode_invocation(
                self, ValueInfo('return_value', return_type, return_type), preamble, main_body, epilogue
            )

        # Blank line after Decode() method invocations.
        if values or return_type:
            main_body += '\n'

        # Make the argument list for the API call
        arglist = ', '.join([arg_name for arg_name in arg_names])
        if return_type and return_type != 'void':
            arglist = ', '.join(['return_value', arglist])

        if arglist[-2:] == ', ':
            arglist = arglist[:-2]
        arglist = 'call_info, ' + arglist

        main_body += '    for (auto consumer : GetConsumers())\n'
        main_body += '    {\n'
        main_body += '        consumer->Process_{}({});\n'.format(name, arglist)
        main_body += '    }\n'

        if len(preamble) > 0:
            preamble += '\n'
        body = preamble + main_body + epilogue

        return body

    def make_decode_invocation(self, value, preamble, main_body, epilogue):
        """Generate parameter decode function/method invocation."""
        buffer_args = '(parameter_buffer + bytes_read), (buffer_size - bytes_read)'

        is_struct = False
        is_string = False
        is_funcp = False
        is_handle_like = False

        type_name = self.make_invocation_type_name(value.base_type)

        if self.is_struct(type_name):
            is_struct = True
        elif type_name in ['String', 'WString']:
            is_string = True
        elif type_name == 'FunctionPtr':
            is_funcp = True
        elif self.is_handle_like(value.base_type):
            is_handle_like = True

        # is_pointer will be False for static arrays.
        if value.is_pointer or value.is_array:
            if type_name in self.EXTERNAL_OBJECT_TYPES and not value.is_array:
                if value.pointer_count > 1:
                    # Pointer to a pointer to an unknown object type (void**), encoded as a pointer to a 64-bit integer ID.
                    main_body += '    bytes_read += {}.DecodeVoidPtr({});\n'.format(
                        value.name, buffer_args
                    )
                else:
                    # Pointer to an unknown object type, encoded as a 64-bit integer ID.
                    main_body += '    bytes_read += ValueDecoder::DecodeAddress({}, &{});\n'.format(
                        buffer_args, value.name
                    )
            else:
                if is_struct or is_string or is_handle_like:
                    if type_name in self.children_structs.keys():
                        base_type_name = self.make_simple_var_name(value.base_type)
                        main_body += '    if (PointerDecoderBase::PeekAttributesAndType((parameter_buffer + bytes_read),\n'
                        main_body += '                                                   (buffer_size - bytes_read),\n'
                        main_body += '                                                   peak_is_null,\n'
                        main_body += '                                                   peak_is_struct,\n'
                        main_body += '                                                   peak_has_length,\n'
                        main_body += '                                                   peak_length,\n'
                        main_body += '                                                   peak_structure_type))\n'
                        main_body += '     {\n'
                        main_body += '         XrStructureType xr_type = static_cast<XrStructureType>(peak_structure_type);\n'
                        main_body += '         switch (xr_type)\n'
                        main_body += '         {\n'
                        for child in self.children_structs[value.base_type]:
                            switch_type = self.struct_type_names[child]
                            main_body += f'             case {switch_type}:\n'
                            child_var = self.make_simple_var_name(child)
                            main_body += f'                 bytes_read += {child_var}.Decode({buffer_args});\n'
                            main_body += f'                 {value.name} = reinterpret_cast<StructPointerDecoder<Decoded_{value.base_type}>*>(&{child_var});\n'
                            main_body += '                 break;\n'

                        main_body += '             default:\n'
                        main_body += f'                 bytes_read += {base_type_name}.Decode({buffer_args});\n'
                        main_body += f'                 {value.name} = &{base_type_name};\n'
                        main_body += '                 break;\n'
                        main_body += '         }\n'
                        main_body += '     }\n'

                    elif is_string:
                        if value.array_length is not None:
                            main_body += f'    {value.base_type}* {value.name}_store = nullptr;\n'
                            main_body += f'    if ({value.array_length} > 0)\n'
                            main_body += '    {\n'
                            main_body += f'        {value.name}_store = new {value.base_type}[{value.array_length}];\n'
                            main_body += f'        {value.name}.SetExternalMemory({value.name}_store, {value.array_length});\n'
                            main_body += '    }\n'
                            epilogue += f'    if ({value.name}_store != nullptr)\n'
                            epilogue += '    {\n'
                            epilogue += f'        delete[] {value.name}_store;\n'
                            epilogue += '    }\n'
                        main_body += '    bytes_read += {}.Decode({});\n'.format(
                                value.name, buffer_args
                            )
                    else:
                        main_body += '    bytes_read += {}.Decode({});\n'.format(
                            value.name, buffer_args
                        )
                elif self.has_basetype(value.base_type):
                    base_type = self.get_basetype(value.base_type)
                    main_body += '    bytes_read += {}.Decode{}({});\n'.format(
                        value.name, self.encode_types[base_type], buffer_args
                    )
 
                else:
                    main_body += '    bytes_read += {}.Decode{}({});\n'.format(
                        value.name, type_name, buffer_args
                    )
        else:
            if is_struct:
                main_body += '    bytes_read += DecodeStruct({}, &{});\n'.format(
                    buffer_args, value.name
                )
            elif is_funcp:
                main_body += '    bytes_read += ValueDecoder::DecodeAddress({}, &{});\n'.format(
                    buffer_args, value.name
                )
            elif is_handle_like:
                main_body += '    bytes_read += ValueDecoder::DecodeHandleIdValue({}, &{});\n'.format(
                    buffer_args, value.name
                )
            elif self.has_basetype(type_name) :
                base_type = self.get_basetype(type_name)
                main_body += '    bytes_read += ValueDecoder::Decode{}Value({}, &{});\n'.format(
                    self.encode_types[base_type], buffer_args, value.name
                )
            else:
                main_body += '    bytes_read += ValueDecoder::Decode{}Value({}, &{});\n'.format(
                    type_name, buffer_args, value.name
                )

        return preamble, main_body, epilogue

    def generate_decode_cases(self):
        prefix = self.get_api_prefix()
        """Generate the (Platform)Decoder::DecodeFunctionCall method."""

        body = f'void {prefix}Decoder::DecodeFunctionCall(format::ApiCallId             call_id,\n'
        body += '                                       const ApiCallInfo&            call_info,\n'
        body += '                                       const uint8_t*                parameter_buffer,\n'
        body += '                                       size_t                        buffer_size)\n'
        body += '{\n'
        body += '    switch(call_id)\n'
        body += '    {\n'
        body += '    default:\n'
        body += f'        {prefix}DecoderBase::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);\n'
        body += '        break;\n'
        write(body, file=self.outFile)

        for cmd in self.get_all_filtered_cmd_names():
            cmddef = '    case format::ApiCallId::ApiCall_{}:\n'.format(cmd)
            cmddef += '        Decode_{}(call_info, parameter_buffer, buffer_size);\n'.format(
                cmd
            )
            cmddef += '        break;'
            write(cmddef, file=self.outFile)

        write('    }', file=self.outFile)
        write('}\n', file=self.outFile)
