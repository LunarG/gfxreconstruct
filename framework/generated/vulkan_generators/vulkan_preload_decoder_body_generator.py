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

import sys
from base_generator import BaseGenerator, BaseGeneratorOptions, ValueInfo, write
from base_decoder_body_generator import BaseDecoderBodyGenerator


class VulkanPreloadDecoderBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan API parameter decoding."""

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


class VulkanPreloadDecoderBodyGenerator(BaseDecoderBodyGenerator, BaseGenerator):
    """VulkanPreloadDecoderBodyGenerator - subclass of BaseGenerator.
    Generates C++ member functions for the VulkanPreloadDecoder class responsible for decoding
    Vulkan API call parameter data.
    Generate a C++ class for Vulkan API parameter decoding.
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

        # Names of all Vulkan commands processed by the generator.
        self.cmd_names = []

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write('#include "decode/handle_pointer_decoder.h"', file=self.outFile)
        write('#include "decode/pointer_decoder.h"', file=self.outFile)
        write('#include "decode/string_array_decoder.h"', file=self.outFile)
        write('#include "decode/string_decoder.h"', file=self.outFile)
        write('#include "decode/struct_pointer_decoder.h"', file=self.outFile)
        write('#include "decode/value_decoder.h"', file=self.outFile)
        write('#include "decode/vulkan_pnext_node.h"', file=self.outFile)
        write(
            '#include "generated/generated_vulkan_decoder.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_struct_decoders_forward.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_struct_packet.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_preload_decoder.h"',
            file=self.outFile
        )
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('#include <cstddef>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        self.newline()
        # Generate the VulkanDecoder::DecodeFunctionCall method for all of the commands processed by the generator.
        self.generate_decode_cases()
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        platform_type = self.get_api_prefix()

        first = True
        for cmd in self.get_filtered_cmd_names():
            self.cmd_names.append(cmd)

            info = self.feature_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += 'size_t {}PreloadDecoder::Decode_{}(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)\n'.format(
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

        # Vulkan return is very simple.
        if return_type and return_type != 'void':
            body += '    {} return_value;\n'.format(return_type)

        # Blank line after declarations.
        if values or return_type:
            body += '\n'

        for value in values:
            body += self.make_decode_invocation(
                value
            )
        if return_type and return_type != 'void':
            body += self.make_decode_invocation(
                ValueInfo('return_value', return_type, return_type)
            )

        # Blank line after Decode() method invocations.
        if values or return_type:
            body += '\n'

        # Make the argument list for the API call
        arglist = ', '.join([arg_name for arg_name in arg_names])
        if return_type and return_type != 'void':
            arglist = ', '.join(['return_value', arglist])


        if arglist[-2:] == ', ':
            arglist = arglist[:-2]
        arglist = 'call_info, ' + arglist

        # Create a packet
        body += '    Packet_{}* packet = PreloadDecodeAllocator::Allocate<Packet_{}>();\n'.format(name, name)
        body += '    packet->packet_id = gfxrecon::format::PacketCall_{};\n'.format(name)
        body += '    packet->call_info = call_info;\n'
        for value in values:
            body += '    packet->{} = {};\n'.format(value.name, value.name)
        if return_type and return_type != 'void':
            body += '    packet->return_value = return_value;\n'

        # Save the packet to the container
        body += '\n'
        body += '    AddPacket(reinterpret_cast<void*>(packet));\n'

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
                    body += '    bytes_read += {}.PreloadDecode({});\n'.format(
                        value.name, buffer_args
                    )
                elif is_class and value.pointer_count == 1:
                    body += '    bytes_read += ValueDecoder::DecodeHandleIdValue({}, &{});\n'.format(
                        buffer_args, value.name
                    )
                elif self.has_basetype(value.base_type):
                    base_type = self.get_basetype(value.base_type)
                    body += '    bytes_read += {}.PreloadDecode{}({});\n'.format(
                        value.name, self.encode_types[base_type], buffer_args
                    )
                else:
                    body += '    bytes_read += {}.PreloadDecode{}({});\n'.format(
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
        prefix = self.get_api_prefix()
        """Generate the (Platform)Decoder::DecodeFunctionCall method."""

        body = f'void {prefix}PreloadDecoder::DecodeFunctionCall(format::ApiCallId             call_id,\n'
        body += '                                       const ApiCallInfo&            call_info,\n'
        body += '                                       const uint8_t*                parameter_buffer,\n'
        body += '                                       size_t                        buffer_size)\n'
        body += '{\n'
        body += '    switch(call_id)\n'
        body += '    {\n'
        body += '    default:\n'
        body += f'        {prefix}PreloadDecoderBase::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);\n'
        body += '        break;\n'
        write(body, file=self.outFile)

        for cmd in self.cmd_names:
            cmddef = '    case format::ApiCallId::ApiCall_{}:\n'.format(cmd)
            cmddef += '        Decode_{}(call_info, parameter_buffer, buffer_size);\n'.format(
                cmd
            )
            cmddef += '        break;'
            write(cmddef, file=self.outFile)

        write('    }', file=self.outFile)
        write('}\n', file=self.outFile)