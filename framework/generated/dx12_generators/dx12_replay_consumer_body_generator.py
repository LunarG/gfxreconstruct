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

from base_generator import write
from dx12_base_generator import Dx12BaseGenerator
from dx12_replay_consumer_header_generator import Dx12ReplayConsumerHeaderGenerator
from base_replay_consumer_body_generator import BaseReplayConsumerBodyGenerator


class Dx12ReplayConsumerBodyGenerator(
    BaseReplayConsumerBodyGenerator, Dx12ReplayConsumerHeaderGenerator
):
    """Generates C++ functions responsible for consuming Dx12 API calls."""

    def write_include(self):
        """Methond override."""
        write('#include "generated_dx12_replay_consumer.h"', file=self.outFile)

    def generate_feature(self):
        """Methond override."""
        Dx12BaseGenerator.generate_feature(self)
        BaseReplayConsumerBodyGenerator.generate_feature(self, 'Dx12')
        self.generate_dx12_method_feature()

    def generate_dx12_method_feature(self):
        first = True
        for method in self.get_filtered_method_names():
            info = self.feature_method_params[method]
            return_type = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.make_consumer_func_decl(
                return_type, 'Dx12ReplayConsumer::Process_' + method, values,
                True
            ) + '\n'
            cmddef += '{\n'

            class_name = method[:method.find('_')]
            cmddef += (
                "    auto replay_object = MapObject<{}>(object_id);\n"
                "    if (replay_object != nullptr)\n"
                "    {{\n".format(class_name)
            )

            body = self.make_consumer_func_body(return_type, method, values)
            code_list = body.split('\n')
            for code in code_list:
                if len(code) > 0:
                    cmddef += ('    ' + code + '\n')

            cmddef += '    }\n'\
                      '}'

            write(cmddef, file=self.outFile)
            first = False

    def make_consumer_func_body(self, return_type, name, values):
        """Methond override."""
        if name == 'IUnknown_AddRef':
            return '    replay_object->AddRef();\n'
        elif name == 'IUnknown_Release':
            return (
                "    auto replay_count = replay_object->Release();\n"
                "    if (replay_count == 0)\n"
                "    {\n"
                "        RemoveObject(object_id);\n"
                "        GFXRECON_LOG_INFO(\"Object with ID %\" PRIu64 \" has been destroyed\", object_id);\n"
                "    }\n"
            )

        code = ''
        for value in values:
            if self.is_tracking_data(value):
                array_length = None
                if value.is_array:
                    # TODO: There are currently no output array parameters,
                    # so just print a warning for now.
                    print(
                        'WARNING: Skipping code generation for unsupported output array parameter',
                        name, '::', value.name
                    )
                else:
                    array_length = 1
                code += '    if(!{0}->IsNull()) {0}->SetHandleLength({1});\n'\
                        '    auto _out_p_{0}    = {0}->GetPointer();\n'\
                        '    auto _out_hp_{0}   = {0}->GetHandlePointer();\n'\
                        .format(value.name, array_length)

        is_object = True if name.find('_') != -1 else False
        function_name = name if not is_object else name[name.find('_') + 1:]
        indent_length = len(code)
        code += '    '
        if return_type != 'void':
            code += 'auto replay_result = '

        if is_object:
            code += 'replay_object->'

        code += function_name + '('
        indent_length = len(code) - indent_length
        first = True
        for value in values:
            if not first:
                code += ',\n{}'.format(' ' * indent_length)
            first = False

            value_name = None
            if self.is_tracking_data(value):
                if value.full_type.find('void') != -1:
                    value_name = 'reinterpret_cast<void**>(_out_hp_{})'.format(
                        value.name
                    )
                else:
                    value_name = '_out_hp_{}'.format(value.name)
            else:
                if value.pointer_count > 0 or value.is_array:
                    if self.is_class(value):
                        if value.pointer_count == 2:
                            value_name = 'MapObject<{}*>(*{}->GetPointer())'.format(
                                value.base_type, value.name
                            )
                        elif value.pointer_count == 1:
                            value_name = 'MapObject<{}>(*{}->GetPointer())'.format(
                                value.base_type, value.name
                            )
                    elif self.is_struct(
                        value.base_type
                    ) and value.pointer_count == 2 and value.is_const:
                        value_name = (
                            'const_cast<const {}**>({}->GetPointer())'.format(
                                value.base_type, value.name
                            )
                        )
                    elif value.base_type == 'void':
                        if value.pointer_count == 1:
                            value_name = 'reinterpret_cast<void*>({})'.format(
                                value.name
                            )
                        elif value.pointer_count == 2:
                            value_name = value.name + '->GetOutputPointer()'
                    else:
                        value_name = value.name + '->GetPointer()'

                else:
                    if self.is_struct(value.base_type):
                        value_name = '*' + value.name + '.decoded_value'
                    elif self.is_handle(value.base_type):
                        value_name = 'MapHandle<{}>({})'.format(
                            value.base_type, value.name
                        )
                    elif value.base_type == 'PFN_DESTRUCTION_CALLBACK':
                        value_name = (
                            'reinterpret_cast<PFN_DESTRUCTION_CALLBACK>({})'.
                            format(value.name)
                        )

            if not value_name:
                value_name = value.name
            code += value_name
        code += ');\n'

        if return_type == 'HRESULT' and len(values):
            code += ("    if (SUCCEEDED(replay_result))\n" "    {\n")
            for value in values:
                if self.is_tracking_data(value):
                    if self.is_class(value):
                        code += (
                            '        AddObject(_out_p_{0}, _out_hp_{0});\n'.
                            format(value.name)
                        )
                    elif self.is_handle(value.base_type):
                        code += (
                            '        AddHandle(_out_p_{0}, _out_hp_{0});\n'.
                            format(value.name)
                        )
            code += "    }\n"
            code += (
                '    CheckReplayResult("{}", returnValue, replay_result);\n'.
                format(name)
            )
        return code

    def is_tracking_data(self, value):
        if value.full_type.find('_Out') != -1 and (
            self.is_class(value) or self.is_handle(value.base_type)
        ):
            return True
        return False
