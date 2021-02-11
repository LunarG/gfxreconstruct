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
    import DX12ApiCallEncodersHeaderGenerator, write


# Generates C++ functions responsible for encoding DX12 API call.
class DX12ApiCallEncodersBodyGenerator(DX12ApiCallEncodersHeaderGenerator):

    ERROR_MSG = 'ERROR: Missing parameter type:'

    def __init__(self, source_dict, dx12_prefix_strings,
                 errFile=sys.stderr, warnFile=sys.stderr, diagFile=sys.stdout):
        DX12ApiCallEncodersHeaderGenerator.__init__(
            self, source_dict, dx12_prefix_strings,
            errFile, warnFile, diagFile)
        self.check_blacklist = True

    # Method override
    def write_include(self):
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

    # Method override
    def write_encode_object(self):
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

    # Method override
    def get_encode_struct(self, value, is_generating_struct):
        write_parameter_value = ''
        if is_generating_struct:
            write_parameter_value = 'value.'

        if value.arrayLength and type(value.arrayLength) == str:
            return 'EncodeStructArray(encoder, {}{}, {}{});'.format(
                write_parameter_value, value.name, write_parameter_value,
                value.arrayLength)

        elif value.pointerCount == 1:
            if value.arrayCapacity == 0:
                return 'EncodeStructPtr(encoder, {}{});'.format(
                    write_parameter_value, value.name)
            else:
                print(self.ERROR_MSG, 'struct ptr array', value.name)

        elif value.pointerCount == 2:
            return 'EncodeStructPtr(encoder, *{}{});'.format(
                write_parameter_value, value.name)

        else:
            if value.arrayCapacity == 0:
                return 'EncodeStruct(encoder, {}{});'.format(
                    write_parameter_value, value.name)
            else:
                return 'EncodeStructArray(encoder, {}{}, {});'.format(
                    write_parameter_value, value.name, value.arrayCapacity)
        return ''

    # Method override
    def get_encode_value(self, value, function_name,
                         function_value, is_generating_struct):
        write_parameter_value = ''
        if is_generating_struct:
            write_parameter_value = 'value.'

        write_function_value = ''
        if function_value:
            write_function_value = 'Value'

        if value.arrayLength and type(value.arrayLength) == str:
            return 'encoder->Encode{}Array({}{}, {}{});'.format(
                function_name, write_parameter_value, value.name,
                write_parameter_value, value.arrayLength)

        elif value.pointerCount == 1:
            if value.arrayCapacity == 0:
                return 'encoder->Encode{}Ptr({}{});'.format(
                    function_name, write_parameter_value, value.name)
            else:
                print(self.ERROR_MSG, 'ptr array', function_name, value.name)
        elif value.pointerCount == 2:
            return 'encoder->Encode{}PtrPtr({}{});'.format(
                    function_name, write_parameter_value, value.name)

        else:
            if value.arrayCapacity == 0:
                return 'encoder->Encode{}{}({}{});'.format(
                    function_name, write_function_value,
                    write_parameter_value, value.name)
            else:
                if value.arrayDimension > 0:
                    return 'encoder->Encode{}Array(*{}{}, {});'.format(
                        function_name, write_parameter_value, value.name,
                        value.arrayCapacity)
                else:
                    return 'encoder->Encode{}Array({}{}, {});'.format(
                        function_name, write_parameter_value, value.name,
                        value.arrayCapacity)
        return ''

    # Method override
    def get_encode_parameter(self, parameter, is_generating_struct):
        rtn = []
        struct_name = ''
        if 'parent' in parameter and 'name' in parameter['parent']:
            struct_name = parameter['parent']['name']

        value = self.get_value_info(parameter)

        # This union is from winnt.h
        if value.baseType == 'LARGE_INTEGER':
            if value.pointerCount == 1:
                value.name = '&' + value.name + '->QuadPart'

        if value.unionMembers:
            rtn.append('// For Union, find the largest size in the member and encode it.')  # noqa
            rtn.append('size_t union_size_max = 0, union_size = 0;')

            for m in value.unionMembers:
                rtn.append('if (union_size = sizeof(value.{}) > union_size_max) union_size_max = union_size;'  # noqa
                           .format(m[0]))
            rtn.append('encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.{}), union_size_max);'  # noqa
                       .format(value.unionMembers[0][0]))

        elif self.isStruct(value.baseType):
            rtn.append(self.get_encode_struct(value, is_generating_struct))

        elif self.isClass(value):
            if value.arrayLength and type(value.arrayLength) == str:
                if is_generating_struct:
                    if value.isConst:
                        rtn.append('EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<{}***>\n'  # noqa
                                   '            (&const_cast<{}*>(&value)->{})), value.{});'  # noqa
                                   .format(value.baseType, struct_name,
                                           value.name, value.arrayLength))
                    else:
                        rtn.append('EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(&const_cast<{}**>\n'  # noqa
                                   '            (&value)->{}), value.{});'
                                   .format(struct_name, value.name,
                                           value.arrayLength))
                else:
                    if value.isConst:
                        rtn.append('EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<{}***>(&{})), {});'  # noqa
                                   .format(value.baseType, value.name,
                                           value.arrayLength))
                    else:
                        rtn.append('EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(&{}), {});'  # noqa
                                   .format(value.name, value.arrayLength))

            else:
                if is_generating_struct:
                    if value.isConst:
                        rtn.append('EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(const_cast<{}**>\n'  # noqa
                                   '            (&const_cast<{}*>(&value)->{})));'  # noqa
                                   .format(value.baseType, struct_name,
                                           value.name))
                    else:
                        rtn.append('EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<{}*>\n'  # noqa
                                   '            (&value)->{}));'
                                   .format(struct_name, value.name))
                else:
                    if value.isConst:
                        rtn.append('EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(const_cast<{}**>(&{})));'  # noqa
                                   .format(value.baseType, value.name))
                    else:
                        rtn.append('EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&{}));'  # noqa
                                   .format(value.name))

        else:
            function_value = True
            encode_type = self.convert_function(value.baseType)

            if encode_type == 'String' or encode_type == 'WString':
                value.pointerCount = 0
                function_value = 0
                value.arrayCapacity = 0

            elif encode_type == 'Function':
                value.pointerCount = 1

            elif encode_type == value.baseType:
                if self.isEnum(value.baseType):
                    encode_type = 'Enum'

                else:
                    print(self.ERROR_MSG, value.baseType, value.name)

            if encode_type:
                rtn.append(
                    self.get_encode_value(
                        value,
                        encode_type,
                        function_value,
                        is_generating_struct))
        return rtn

    # Method override
    def get_encode_struct_body(self, properties):
        body = '\n'\
               '{\n'
        for k, v in properties.items():
            for p in v:
                encodes = self.get_encode_parameter(p, True)
                for code in encodes:
                    body += '    {}\n'.format(code)

        body += '}'
        return body

    # Method override
    def get_encode_function_body(self, class_name, method_info):
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
