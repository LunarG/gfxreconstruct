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
from base_generator import write
from dx12_api_call_encoders_header_generator import Dx12ApiCallEncodersHeaderGenerator


class Dx12ApiCallEncodersBodyGenerator(Dx12ApiCallEncodersHeaderGenerator):
    """Generates C++ functions responsible for encoding Dx12 API call."""

    def __init__(
        self,
        source_dict,
        dx12_prefix_strings,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout
    ):
        Dx12ApiCallEncodersHeaderGenerator.__init__(
            self, source_dict, dx12_prefix_strings, err_file, warn_file,
            diag_file
        )
        self.check_blacklist = True
        self.structs_with_wrap_objects = []

        # Unique set of names of all defined classes.
        self.class_names = []
        # Unique set of names of all class names specified as base classes.
        self.class_parent_names = []

    def generate_feature(self):
        header_dict = self.source_dict['header_dict']
        self.structs_with_wrap_objects = self.collect_struct_with_objects(
            header_dict
        )
        for k, v in header_dict.items():
            for class_name, class_value in v.classes.items():
                if self.is_required_class_data(class_value)\
                   and (class_value['name'] != 'IUnknown'):
                    # Track class names
                    if class_name not in self.class_names:
                        self.class_names.append(class_name)

                    # Track names of classes inherited from
                    for entry in class_value['inherits']:
                        decl_name = entry['decl_name']
                        if decl_name not in self.class_parent_names:
                            self.class_parent_names.append(decl_name)

        Dx12ApiCallEncodersHeaderGenerator.generate_feature(self)

    def write_include(self):
        """Methond override."""
        code = (
            "#include \"generated/generated_dx12_api_call_encoders.h\"\n"
            "#include \"encode/custom_dx12_struct_encoders.h\"\n"
            "\n"
            "#include \"encode/d3d12_capture_manager.h\"\n"
            "#include \"encode/parameter_encoder.h\"\n"
            "#include \"encode/struct_pointer_encoder.h\"\n"
            "#include \"format/api_call_id.h\"\n"
            "#include \"util/defines.h\"\n"
        )
        write(code, file=self.outFile)

    def get_encode_struct(self, value, is_generating_struct, is_result):
        """Methond override."""
        write_parameter_value = ''
        if is_generating_struct:
            write_parameter_value = 'value.'

        omit_output_data = ''
        if is_result and self.is_output(value):
            omit_output_data = ', omit_output_data'

        if value.array_length and type(value.array_length) == str:
            return 'EncodeStructArray(encoder, {}{}, {}{}{});'.format(
                write_parameter_value, value.name, write_parameter_value,
                value.array_length, omit_output_data
            )

        elif value.pointer_count == 1:
            if value.array_capacity == 0:
                return 'EncodeStructPtr(encoder, {}{}{});'.format(
                    write_parameter_value, value.name, omit_output_data
                )

        elif value.pointer_count == 2:
            return 'EncodeStructPtr(encoder, *{}{}{});'.format(
                write_parameter_value, value.name, omit_output_data
            )

        else:
            if value.array_capacity == 0:
                return 'EncodeStruct(encoder, {}{});'.format(
                    write_parameter_value, value.name
                )
            else:
                return 'EncodeStructArray(encoder, {}{}, {}{});'.format(
                    write_parameter_value, value.name, value.array_capacity,
                    omit_output_data
                )
        return ''

    def get_encode_value(
        self, value, function_name, function_value, is_generating_struct,
        is_result
    ):
        """Methond override."""
        write_parameter_value = ''
        if is_generating_struct:
            write_parameter_value = 'value.'

        write_function_value = ''
        if function_value:
            write_function_value = 'Value'

        omit_output_data = ''
        if is_result and self.is_output(value):
            omit_output_data = ', omit_output_data'

        if value.array_length and type(value.array_length) == str:
            return 'encoder->Encode{}Array({}{}, {}{}{});'.format(
                function_name, write_parameter_value, value.name,
                write_parameter_value, value.array_length, omit_output_data
            )

        elif value.pointer_count == 1:
            if value.array_capacity == 0:
                if value.base_type == 'void':
                    omit_output_data = ''
                if not value.array_length:
                    return 'encoder->Encode{}Ptr({}{}{});'.format(
                        function_name, write_parameter_value, value.name,
                        omit_output_data
                    )
                else:
                    return 'encoder->Encode{}Array({}{}{});'.format(
                        function_name, write_parameter_value, value.name,
                        omit_output_data
                    )

        elif value.pointer_count == 2:
            return 'encoder->Encode{}PtrPtr({}{}{});'.format(
                function_name, write_parameter_value, value.name,
                omit_output_data
            )

        else:
            if value.array_capacity == 0:
                return 'encoder->Encode{}{}({}{});'.format(
                    function_name, write_function_value, write_parameter_value,
                    value.name
                )
            else:
                if value.array_dimension > 0:
                    return 'encoder->Encode{}Array(*{}{}, {}{});'.format(
                        function_name, write_parameter_value, value.name,
                        value.array_capacity, omit_output_data
                    )
                else:
                    return 'encoder->Encode{}Array({}{}, {}{});'.format(
                        function_name, write_parameter_value, value.name,
                        value.array_capacity, omit_output_data
                    )
        return ''

    def get_encode_parameter(self, value, is_generating_struct, is_result):
        rtn = ''
        omit_output_data = ''
        if is_result and self.is_output(value):
            omit_output_data = ', omit_output_data'

        if self.is_struct(value.base_type):
            rtn = self.get_encode_struct(
                value, is_generating_struct, is_result
            )

        elif self.is_class(value):
            if value.array_length and type(value.array_length) == str:
                if is_generating_struct:
                    pass
                else:
                    rtn = 'encoder->EncodeObjectArray({}, {}{});'.format(
                        value.name, value.array_length, omit_output_data
                    )
            else:
                if is_generating_struct:
                    if value.pointer_count == 2:
                        rtn = 'encoder->EncodeObjectPtr(value.{}{});'.format(
                            value.name, omit_output_data
                        )
                    else:
                        rtn = 'encoder->EncodeObjectValue(value.{});'.format(
                            value.name
                        )
                else:
                    if value.pointer_count == 2:
                        rtn = 'encoder->EncodeObjectPtr({}{});'.format(
                            value.name, omit_output_data
                        )
                    else:
                        rtn = 'encoder->EncodeObjectValue({});'.format(
                            value.name
                        )

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
                    encode_type = ''

            if encode_type:
                rtn = self.get_encode_value(
                    value, encode_type, function_value, is_generating_struct,
                    is_result
                )

        if not rtn:
            print(
                'ERROR: Missing parameter type:', value.full_type, value.name
            )
        return rtn

    def get_encode_struct_body(self, properties):
        """Methond override."""
        body = '\n'\
               '{\n'
        for k, v in properties.items():
            for p in v:
                value = self.get_value_info(p)
                encode = self.get_encode_parameter(value, True, False)
                body += '    {}\n'.format(encode)

        body += '}'
        return body

    def get_encode_function_body(self, class_name, method_info, is_result):
        """Methond override."""
        body = '\n'\
               '{\n'

        method_name = method_info['name']
        parameters = method_info['parameters']
        is_create_call = False
        is_descriptor_create_call = False
        is_command_list_call = False
        create_object_tuple = None

        # Check if last parameter is a created object.
        create_object_info, _ = self.get_object_creation_params(parameters)

        # TODO (GH #83): are there creation calls that need to be processed when len(create_object_info) > 1 ?
        if len(create_object_info) == 1 and create_object_info[0]:
            is_create_call = True
            create_object_tuple = create_object_info[0]

        # Check if last parameter is a descriptor.
        descriptor_creation_param_name = self.get_descriptor_creation_param(
            parameters
        )
        if descriptor_creation_param_name:
            is_descriptor_create_call = True

        # Check if call is a CommandList command.
        if 'GraphicsCommandList' in class_name:
            is_command_list_call = True

        # Build begin and end calls.
        api_or_method = ''
        begin_call_type = ''
        begin_call_args = ''
        end_call_type = ''
        end_call_args = ''
        class_method_name = method_info['name']

        if class_name:
            api_or_method = 'Method'
            begin_call_args = 'format::ApiCallId::ApiCall_{}_{}, wrapper->GetCaptureId()'.format(
                class_name, method_name
            )
            class_method_name = class_name + '_' + class_method_name

        else:
            api_or_method = 'Api'
            begin_call_args = 'format::ApiCallId::ApiCall_{}'.format(
                method_name
            )

        if is_create_call:
            begin_call_type = 'Tracked'
            end_call_type = 'Create'
            end_call_args = 'return_value, {}, {}'.format(
                create_object_tuple[0], create_object_tuple[1]
            )
            if class_name:
                # Check that the calling class is a wrapper type that contains object info. Some wrapper types (e.g., IDXGIObject_Wrapper)
                # do not contain object infos because they are base class interfaces for final types.
                # TODO (GH #83): Is it possible these intermediate object types also need to have wrapper infos?
                class_family_names = self.get_class_family_names(class_name)
                first_class = class_family_names[0]
                is_map_class = self.is_map_class(first_class)
                if is_map_class:
                    end_call_args += ', wrapper'
                else:
                    end_call_args += ', static_cast<void*>(nullptr)'
        elif is_descriptor_create_call:
            begin_call_type = 'Tracked'
            end_call_type = 'CreateDescriptor'
            end_call_args = '{}'.format(descriptor_creation_param_name)
            if class_name:
                end_call_args += ', wrapper'
        elif is_command_list_call:
            begin_call_type = 'Tracked'
            end_call_type = 'CommandList'
            end_call_args = '{}'.format('wrapper')

        begin_call = 'Begin{}{}CallCapture({})'.format(
            begin_call_type, api_or_method, begin_call_args
        )
        end_call = 'End{}{}CallCapture({})'.format(
            end_call_type, api_or_method, end_call_args
        )

        body += (
            '    auto encoder = D3D12CaptureManager::Get()->{};\n'.
            format(begin_call)
        )

        body += '    if(encoder)\n'\
                '    {\n'

        if is_result:
            body += '        bool omit_output_data = false;\n'\
                    '        if (return_value != S_OK)\n'\
                    '        {\n'\
                    '            omit_output_data = true;\n'\
                    '        }\n'

        for p in parameters:
            value = self.get_value_info(p)
            encode = self.get_encode_parameter(value, False, is_result)
            body += '        {}\n'.format(encode)

        rtn_type = method_info['rtnType']
        if rtn_type.find('void ') == -1 or rtn_type.find('void *') != -1:
            value = self.get_return_value_info(rtn_type, class_method_name)
            encode = self.get_encode_parameter(value, False, is_result)
            body += '        {}\n'.format(encode)

        body += ('        D3D12CaptureManager::Get()->{};\n'.format(end_call))

        body += '    }\n}'
        return body

    # Check the parameter list for a pointer to an object that is being
    # created or retrieved, which needs to be wrapped.
    def get_object_creation_params(self, param_info):
        refiid_value = None
        create_values = []
        create_wrap_struct = []

        # Check for pairs of parameters with REFIID and void** types or a
        # parameter with a non-const double pointer class type.
        for param in param_info:
            value = self.get_value_info(param)

            if (value.base_type != 'LARGE_INTEGER') and self.is_struct(
                value.base_type
            ) and (value.full_type.find('_Out_') != -1):
                if value.base_type in self.structs_with_wrap_objects:
                    create_wrap_struct.append(value)

            data = []
            if not refiid_value:
                if value.base_type == 'GUID':
                    refiid_value = value
                elif (
                    self.is_class(value)
                    and ((value.pointer_count == 2) and (not value.is_const))
                ):
                    cast_expr = 'reinterpret_cast<void**>({})'.format(
                        value.name
                    )
                    create_values.append(
                        [
                            'IID_' + value.base_type, cast_expr,
                            value.array_length
                        ]
                    )
            else:
                if (
                    (value.base_type == 'void') and (value.pointer_count == 2)
                    and (not value.is_const)
                ):
                    create_values.append(
                        [refiid_value.name, value.name, value.array_length]
                    )
                refiid_value = None

        return create_values, create_wrap_struct

    def get_descriptor_creation_param(self, param_info):
        if len(param_info) > 0:
            descriptor_creation_types = ['D3D12_CPU_DESCRIPTOR_HANDLE']
            value = self.get_value_info(param_info[-1])
            if (value.base_type
                in descriptor_creation_types) and (value.pointer_count == 0):
                return value.name
        return None

    # Get the names of the final classes in the DX class hierarchies.
    def get_final_class_names(self):
        final_class_names = []

        for name in self.class_names:
            if name not in self.class_parent_names:
                final_class_names.append(name)

        return final_class_names

    def get_class_family_names(self, final_class_name):
        base_name = final_class_name
        final_number = ''

        # Get the number from the end of the class name.  Start from the
        # back of the string and advance forward until a non-digit character
        # is encountered.
        if (not final_class_name
            in self.NOT_FAMILY_CLASSES) and (final_class_name[-1].isdigit()):
            for i in range(len(final_class_name) - 1, -1, -1):
                if not final_class_name[i].isdigit():
                    base_name = final_class_name[:i + 1]
                    final_number = final_class_name[i + 1:]
                    break

        class_family_names = [base_name]
        if final_number:
            # Generate with class numbers in ascending order, from 1 to n.
            for i in range(1, int(final_number) + 1):
                class_family_names.append(base_name + str(i))

        return class_family_names

    # Determine if the specified class should contain a map of object pointers to wrapper pointers.
    def is_map_class(self, name):
        map_classes = []
        final_class_names = self.get_final_class_names()

        for final_class_name in final_class_names:
            class_family_names = self.get_class_family_names(final_class_name)
            first_class = class_family_names[0]
            map_classes.append(first_class)

        return name in map_classes
