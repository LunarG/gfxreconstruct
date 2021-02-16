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

import sys
from dx12_api_call_encoders_header_generator\
    import Dx12ApiCallEncodersHeaderGenerator, write


class Dx12ApiCallEncodersBodyGenerator(Dx12ApiCallEncodersHeaderGenerator):
    """Generates C++ functions responsible for encoding Dx12 API call."""

    ERROR_MSG = 'ERROR: Missing parameter type:'

    def __init__(self, source_dict, dx12_prefix_strings,
                 err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout):
        Dx12ApiCallEncodersHeaderGenerator.__init__(
            self, source_dict, dx12_prefix_strings,
            err_file, warn_file, diag_file)
        self.check_blacklist = True

    def write_include(self):
        """Methond override."""
        code = ("#include \"generated/generated_dx12_api_call_encoders.h\"\n"
                "#include \"encode/custom_dx12_struct_encoders.h\"\n"
                "\n"
                "#include \"encode/custom_encoder_commands.h\"\n"
                "#include \"encode/parameter_encoder.h\"\n"
                "#include \"encode/struct_pointer_encoder.h\"\n"
                "#include \"encode/trace_manager.h\"\n"
                "#include \"format/api_call_id.h\"\n"
                "#include \"util/defines.h\"\n")
        write(code, file=self.outFile)

    def write_encode_object(self):
        """Methond override."""
        code = ("void EncodeDxObjectPtr(ParameterEncoder* encoder, void** object, bool omit_output_data)\n"  # noqa
                "{\n"
                "    format::HandleId  device_id = format::kNullHandleId;\n"
                "    format::HandleId* device_id_ptr = nullptr;\n"
                "    if ((object != nullptr) && (*object != nullptr))\n"
                "    {\n"
                "        //device_id = reinterpret_cast<const IUnknown_Wrapper*>(*object)->GetObjectId();\n"  # noqa
                "        device_id_ptr = &device_id;\n"
                "    }\n"
                "    // The final version of the encoder would use the address of object as the address that is encoded for the pointer value.\n"  # noqa
                "    encoder->EncodeHandleIdPtr(device_id_ptr, omit_output_data);\n"  # noqa
                "}\n"
                "\n"
                "void EncodeDxObjectPtrArray(ParameterEncoder* encoder, void*** value, size_t len, bool omit_data, bool omit_addr)\n"  # noqa
                "{\n"
                "    encoder->EncodeStructArrayPreamble(value, len, omit_data, omit_addr);\n"  # noqa
                "    if ((value != nullptr) && (len > 0) && !omit_data)\n"
                "    {\n"
                "        for (size_t i = 0; i < len; ++i)\n"
                "        {\n"
                "            EncodeDxObjectPtr(encoder, value[i]);\n"
                "        }\n"
                "    }\n"
                "}")
        write(code, file=self.outFile)

    def get_encode_struct(self, value, is_generating_struct):
        """Methond override."""
        write_parameter_value = ''
        if is_generating_struct:
            write_parameter_value = 'value.'

        if value.array_length and type(value.array_length) == str:
            return 'EncodeStructArray(encoder, {}{}, {}{});'.format(
                write_parameter_value, value.name, write_parameter_value,
                value.array_length)

        elif value.pointer_count == 1:
            if value.array_capacity == 0:
                return 'EncodeStructPtr(encoder, {}{});'.format(
                    write_parameter_value, value.name)
            else:
                print(self.ERROR_MSG, 'struct ptr array', value.name)

        elif value.pointer_count == 2:
            return 'EncodeStructPtr(encoder, *{}{});'.format(
                write_parameter_value, value.name)

        else:
            if value.array_capacity == 0:
                return 'EncodeStruct(encoder, {}{});'.format(
                    write_parameter_value, value.name)
            else:
                return 'EncodeStructArray(encoder, {}{}, {});'.format(
                    write_parameter_value, value.name, value.array_capacity)
        return ''

    def get_encode_value(self, value, function_name,
                         function_value, is_generating_struct):
        """Methond override."""
        write_parameter_value = ''
        if is_generating_struct:
            write_parameter_value = 'value.'

        write_function_value = ''
        if function_value:
            write_function_value = 'Value'

        if value.array_length and type(value.array_length) == str:
            return 'encoder->Encode{}Array({}{}, {}{});'.format(
                function_name, write_parameter_value, value.name,
                write_parameter_value, value.array_length)

        elif value.pointer_count == 1:
            if value.array_capacity == 0:
                return 'encoder->Encode{}Ptr({}{});'.format(
                    function_name, write_parameter_value, value.name)
            else:
                print(self.ERROR_MSG, 'ptr array', function_name, value.name)
        elif value.pointer_count == 2:
            return 'encoder->Encode{}PtrPtr({}{});'.format(
                    function_name, write_parameter_value, value.name)

        else:
            if value.array_capacity == 0:
                return 'encoder->Encode{}{}({}{});'.format(
                    function_name, write_function_value,
                    write_parameter_value, value.name)
            else:
                if value.array_dimension > 0:
                    return 'encoder->Encode{}Array(*{}{}, {});'.format(
                        function_name, write_parameter_value, value.name,
                        value.array_capacity)
                else:
                    return 'encoder->Encode{}Array({}{}, {});'.format(
                        function_name, write_parameter_value, value.name,
                        value.array_capacity)
        return ''

    def get_encode_parameter(self, parameter, is_generating_struct):
        """Methond override."""
        rtn = []
        struct_name = ''
        if 'parent' in parameter and 'name' in parameter['parent']:
            struct_name = parameter['parent']['name']

        value = self.get_value_info(parameter)

        if self.is_struct(value.base_type):
            rtn.append(self.get_encode_struct(value, is_generating_struct))

        elif self.is_class(value):
            if value.array_length and type(value.array_length) == str:
                if is_generating_struct:
                    if value.is_const:
                        rtn.append('EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<{}***>\n'  # noqa
                                   '            (&const_cast<{}*>(&value)->{})), value.{});'  # noqa
                                   .format(value.base_type, struct_name,
                                           value.name, value.array_length))
                    else:
                        rtn.append('EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(&const_cast<{}**>\n'  # noqa
                                   '            (&value)->{}), value.{});'
                                   .format(struct_name, value.name,
                                           value.array_length))
                else:
                    if value.is_const:
                        rtn.append('EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<{}***>(&{})), {});'  # noqa
                                   .format(value.base_type, value.name,
                                           value.array_length))
                    else:
                        rtn.append('EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(&{}), {});'  # noqa
                                   .format(value.name, value.array_length))

            else:
                if is_generating_struct:
                    if value.is_const:
                        rtn.append('EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(const_cast<{}**>\n'  # noqa
                                   '            (&const_cast<{}*>(&value)->{})));'  # noqa
                                   .format(value.base_type, struct_name,
                                           value.name))
                    else:
                        rtn.append('EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<{}*>\n'  # noqa
                                   '            (&value)->{}));'
                                   .format(struct_name, value.name))
                else:
                    if value.is_const:
                        rtn.append('EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(const_cast<{}**>(&{})));'  # noqa
                                   .format(value.base_type, value.name))
                    else:
                        rtn.append('EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&{}));'  # noqa
                                   .format(value.name))

        else:
            function_value = True
            encode_type = self.convert_function(value.base_type)

            if encode_type == 'String' or encode_type == 'WString':
                value.pointer_count = 0
                function_value = 0
                value.array_capacity = 0

            elif encode_type == 'Function':
                value.pointer_count = 1

            elif encode_type == value.base_type:
                if self.is_enum(value.base_type):
                    encode_type = 'Enum'

                else:
                    print(self.ERROR_MSG, value.base_type, value.name)

            if encode_type:
                rtn.append(
                    self.get_encode_value(
                        value,
                        encode_type,
                        function_value,
                        is_generating_struct))
        return rtn

    def get_encode_struct_body(self, properties):
        """Methond override."""
        body = '\n'\
               '{\n'
        for k, v in properties.items():
            for p in v:
                encodes = self.get_encode_parameter(p, True)
                for code in encodes:
                    body += '    {}\n'.format(code)

        body += '}'
        return body

    def get_encode_function_body(self, class_name, method_info):
        """Methond override."""
        body = '\n'\
               '{\n'
        if class_name:
            body += ('    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall{}_{}, wrapper_id);\n'  # noqa
                     .format(class_name, method_info['name']))
        else:
            body += ('    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_{});\n'  # noqa
                     .format(method_info['name']))

        body += '    if(encoder)\n'\
                '    {\n'

        for p in method_info['parameters']:
            encodes = self.get_encode_parameter(p, False)
            for code in encodes:
                body += '        {}\n'.format(code)

        rtn_type = method_info['rtnType']
        if rtn_type.find('void ') == -1 or rtn_type.find('void *') != -1:
            rtn_parameter = {}
            rtn_parameter['name'] = 'result'
            rtn_parameter['type'] = rtn_type

            encodes = self.get_encode_parameter(rtn_parameter, False)
            for code in encodes:
                body += '        {}\n'.format(code)

        if class_name:
            body += '        TraceManager::Get()->EndMethodCallTrace(encoder);\n'  # noqa
        else:
            body += '        TraceManager::Get()->EndApiCallTrace(encoder);\n'

        body += '    }\n}'
        return body
