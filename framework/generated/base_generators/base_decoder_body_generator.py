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

from base_generator import ValueInfo, write


class BaseDecoderBodyGenerator():
    """Base class for generating decoder body code."""

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        platform_type = 'Vulkan'
        if self.is_dx12_class():
            platform_type = 'Dx12'

        first = True
        for cmd in self.get_filtered_cmd_names():
            self.cmd_names.append(cmd)

            info = self.feature_cmd_params[cmd]
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

    def make_cmd_body(self, return_type, name, values, dx12_method=False):
        """Generate C++ code for the decoder method body."""
        body = ''
        arg_names = []

        # Declarations for decoded types.
        for value in values:
            decode_type = self.make_decoded_param_type(value)
            body += '    {} {};\n'.format(decode_type, value.name)

            if decode_type == 'Decoded_{}'.format(value.base_type):
                body += '    {} value_{};\n'.format(
                    value.base_type, value.name
                )
                body += '    {0}.decoded_value = &value_{0};\n'.format(
                    value.name
                )

            if 'Decoder' in decode_type:
                arg_names.append('&{}'.format(value.name))
            else:
                arg_names.append(value.name)

        # Vulkan return is very simple. Value is only for Dx12 Method.
        dx12_return_value = None
        dx12_return_decode_type = None
        if return_type and return_type != 'void':
            if dx12_method:
                dx12_return_value = self.get_return_value_info(
                    return_type, name
                )
                dx12_return_decode_type = self.make_decoded_param_type(
                    dx12_return_value
                )
                body += '    {} return_value;\n'.format(
                    dx12_return_decode_type
                )

                if dx12_return_decode_type == 'Decoded_{}'.format(return_type):
                    body += '    {} value_returned;\n'.format(return_type)
                    body += '    return_value.decoded_value = &value_returned;\n'

            else:
                body += '    {} return_value;\n'.format(return_type)

        # Blank line after declarations.
        if values or return_type:
            body += '\n'

        # Decode() method calls for pointer decoder wrappers.
        for value in values:
            body += BaseDecoderBodyGenerator.make_decode_invocation(
                self, value
            )
        if return_type and return_type != 'void':
            if dx12_method:
                body += BaseDecoderBodyGenerator.make_decode_invocation(
                    self, dx12_return_value
                )
            else:
                body += BaseDecoderBodyGenerator.make_decode_invocation(
                    self, ValueInfo('return_value', return_type, return_type)
                )

        # Blank line after Decode() method invocations.
        if values or return_type:
            body += '\n'

        # Make the argument list for the API call
        arglist = ', '.join([arg_name for arg_name in arg_names])
        if return_type and return_type != 'void':
            if dx12_method and dx12_return_decode_type.find('Decoder') != -1:
                arglist = ', '.join(['&return_value', arglist])
            else:
                arglist = ', '.join(['return_value', arglist])

        if dx12_method:
            arglist = 'object_id, ' + arglist

        if arglist[-2:] == ', ':
            arglist = arglist[:-2]
        arglist = 'call_info, ' + arglist

        body += '    for (auto consumer : GetConsumers())\n'
        body += '    {\n'
        body += '        consumer->Process_{}({});\n'.format(name, arglist)
        body += '    }\n'

        return body

    def make_decode_invocation(self, value):
        """Generate parameter decode function/method invocation."""
        buffer_args = '(parameter_buffer + bytes_read), (buffer_size - bytes_read)'
        body = ''

        is_struct = False
        is_class = False
        is_string = False
        is_funcp = False
        is_handle = False
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

        # is_pointer will be False for static arrays.
        if value.is_pointer or value.is_array:
            if not is_class and type_name in self.EXTERNAL_OBJECT_TYPES and not value.is_array:
                if value.pointer_count > 1:
                    # Pointer to a pointer to an unknown object type (void**), encoded as a pointer to a 64-bit integer ID.
                    body += '    bytes_read += {}.DecodeVoidPtr({});\n'.format(
                        value.name, buffer_args
                    )
                else:
                    # Pointer to an unknown object type, encoded as a 64-bit integer ID.
                    body += '    bytes_read += ValueDecoder::DecodeAddress({}, &{});\n'.format(
                        buffer_args, value.name
                    )
            else:
                if is_struct or is_string or is_handle or (
                    is_class and value.pointer_count > 1
                ):
                    body += '    bytes_read += {}.Decode({});\n'.format(
                        value.name, buffer_args
                    )
                elif is_class and value.pointer_count == 1:
                    body += '    bytes_read += ValueDecoder::DecodeHandleIdValue({}, &{});\n'.format(
                        buffer_args, value.name
                    )
                elif self.has_basetype(value.base_type):
                    base_type = self.get_basetype(value.base_type)
                    body += '    bytes_read += {}.Decode{}({});\n'.format(
                        value.name, self.encode_types[base_type], buffer_args
                    )
                else:
                    body += '    bytes_read += {}.Decode{}({});\n'.format(
                        value.name, type_name, buffer_args
                    )
        else:
            if is_struct:
                body += '    bytes_read += DecodeStruct({}, &{});\n'.format(
                    buffer_args, value.name
                )
            elif is_funcp:
                body += '    bytes_read += ValueDecoder::DecodeAddress({}, &{});\n'.format(
                    buffer_args, value.name
                )
            elif is_handle:
                body += '    bytes_read += ValueDecoder::DecodeHandleIdValue({}, &{});\n'.format(
                    buffer_args, value.name
                )
            elif self.has_basetype(type_name) :
                base_type = self.get_basetype(type_name)
                body += '    bytes_read += ValueDecoder::Decode{}Value({}, &{});\n'.format(
                    self.encode_types[base_type], buffer_args, value.name
                )
            else:
                body += '    bytes_read += ValueDecoder::Decode{}Value({}, &{});\n'.format(
                    type_name, buffer_args, value.name
                )

        return body

    def generate_decode_cases(self):
        """Generate the VulkanDecoder::DecodeFunctionCall method."""
        write(
            'void VulkanDecoder::DecodeFunctionCall(format::ApiCallId             call_id,',
            file=self.outFile
        )
        write(
            '                                       const ApiCallInfo&            call_info,',
            file=self.outFile
        )
        write(
            '                                       const uint8_t*                parameter_buffer,',
            file=self.outFile
        )
        write(
            '                                       size_t                        buffer_size)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    switch(call_id)', file=self.outFile)
        write('    {', file=self.outFile)
        write('    default:', file=self.outFile)
        write(
            '        VulkanDecoderBase::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);',
            file=self.outFile
        )
        write('        break;', file=self.outFile)

        for cmd in self.cmd_names:
            cmddef = '    case format::ApiCallId::ApiCall_{}:\n'.format(cmd)
            cmddef += '        Decode_{}(call_info, parameter_buffer, buffer_size);\n'.format(
                cmd
            )
            cmddef += '        break;'
            write(cmddef, file=self.outFile)

        write('    }', file=self.outFile)
        write('}\n', file=self.outFile)
