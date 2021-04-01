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

import json
import sys
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator, Dx12GeneratorOptions
from dx12_replay_consumer_header_generator import Dx12ReplayConsumerHeaderGenerator, Dx12ReplayConsumerHeaderGeneratorOptions
from base_replay_consumer_body_generator import BaseReplayConsumerBodyGenerator


class Dx12ReplayConsumerBodyGeneratorOptions(
    Dx12ReplayConsumerHeaderGeneratorOptions
):
    """Options for generating a C++ class for Dx12 capture file replay."""

    def __init__(
        self,
        constructor_args,
        replay_overrides=None,  # Path to JSON file listing Vulkan API calls to override on replay.
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True
    ):
        Dx12ReplayConsumerHeaderGeneratorOptions.__init__(
            self, constructor_args, blacklists, platform_types, filename,
            directory, prefix_text, protect_file, protect_feature
        )
        self.replay_overrides = replay_overrides


class Dx12ReplayConsumerBodyGenerator(
    BaseReplayConsumerBodyGenerator, Dx12ReplayConsumerHeaderGenerator
):
    """Generates C++ functions responsible for consuming Dx12 API calls."""

    REPLAY_OVERRIDES = {}

    def __init__(
        self,
        source_dict,
        dx12_prefix_strings,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout
    ):
        Dx12ReplayConsumerHeaderGenerator.__init__(
            self, source_dict, dx12_prefix_strings, err_file, warn_file,
            diag_file
        )
        self.structs_with_handles = dict()
        self.structs_with_handle_ptrs = []

    def beginFile(self, gen_opts):
        """Method override."""
        Dx12ReplayConsumerHeaderGenerator.beginFile(self, gen_opts)
        if gen_opts.replay_overrides:
            self.__load_replay_overrides(gen_opts.replay_overrides)

    def write_include(self):
        """Methond override."""
        write('#include "generated_dx12_replay_consumer.h"', file=self.outFile)
        write(
            '#include "generated_dx12_struct_object_mappers.h"',
            file=self.outFile
        )

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        Dx12BaseGenerator.genStruct(self, typeinfo, typename, alias)
        if not alias:
            for struct_name in self.get_filtered_struct_names():
                self.check_struct_member_handles(
                    struct_name, self.structs_with_handles,
                    self.structs_with_handle_ptrs
                )

    def generate_feature(self):
        """Methond override."""
        Dx12BaseGenerator.generate_feature(self)
        BaseReplayConsumerBodyGenerator.generate_feature(self)
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
            method_name = method[method.find('_') + 1:]
            is_override = False
            if class_name in self.REPLAY_OVERRIDES['classmethods']:
                is_override = method_name in self.REPLAY_OVERRIDES[
                    'classmethods'][class_name]

            if is_override:
                cmddef += (
                    "    auto replay_object = GetObjectInfo(object_id);\n"
                    "    if ((replay_object != nullptr) &&"
                    " (replay_object->object != nullptr))\n"
                )
            else:
                cmddef += (
                    "    auto replay_object = MapObject<{}>(object_id);\n"
                    "    if (replay_object != nullptr)\n".format(class_name)
                )
            cmddef += "    {\n"

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
        code = ''
        arg_list = []
        add_object_list = []
        post_extenal_object_list = []

        is_override = name in self.REPLAY_OVERRIDES
        is_object = True if name.find('_') != -1 else False
        if is_object:
            class_name = name[:name.find('_')]
            method_name = name[name.find('_') + 1:]
            if class_name in self.REPLAY_OVERRIDES['classmethods']:
                is_override = method_name in self.REPLAY_OVERRIDES[
                    'classmethods'][class_name]
        else:
            is_override = name in self.REPLAY_OVERRIDES['functions']

        for value in values:
            is_class = self.is_class(value)
            is_extenal_object = (
                value.base_type in self.EXTERNAL_OBJECT_TYPES
            ) and not value.is_array
            is_output = self.is_output(value)
            is_struct = self.is_struct(value.base_type)

            if is_class:
                if is_output:
                    handle_length = 1
                    if value.array_length:
                        print(
                            'ERROR: It does not deal with array output objects, {}.'
                            .format(value.name)
                        )

                    code += '    if(!{0}->IsNull()) {0}->SetHandleLength({1});\n'\
                            .format(value.name, handle_length)
                    if is_override:
                        code += '    DxObjectInfo object_info{{}};\n'\
                                '    {0}->SetConsumerData(0, &object_info);\n'\
                                .format(value.name)
                    else:
                        code += '    auto out_p_{0}    = {0}->GetPointer();\n'\
                                '    auto out_hp_{0}   = {0}->GetHandlePointer();\n'\
                                .format(value.name)

                    if is_override:
                        arg_list.append(value.name)
                    else:
                        arg_list.append('out_hp_{}'.format(value.name))

                    if is_override:
                        add_object_list.append(
                            'AddObject({0}->GetPointer(), {0}->GetHandlePointer(), '\
                            'object_info.extra_info_type, object_info.extra_info);\n'\
                            .format(value.name)
                        )
                    else:
                        add_object_list.append(
                            'AddObject(out_p_{0}, out_hp_{0});\n'.format(
                                value.name
                            )
                        )

                else:
                    if value.pointer_count == 2:
                        code += '    auto in_{0} = MapObjects<{1}>({0}->GetPointer(), {2});\n'.format(
                            value.name, value.base_type, value.array_length
                        )
                        arg_list.append('in_{}.data()'.format(value.name))

                    elif value.pointer_count == 1:
                        if is_override:
                            code += '    auto in_{0} = GetObjectInfo({0});\n'.format(
                                value.name
                            )
                        else:
                            code += '    auto in_{0} = MapObject<{1}>({0});\n'.format(
                                value.name, value.base_type
                            )
                        arg_list.append('in_{}'.format(value.name))

            elif is_extenal_object and not is_override:
                if is_output:
                    code += '    auto out_p_{0}    = {0}->GetPointer();\n'\
                            .format(value.name)

                    length = '1'
                    if value.array_length:
                        if value.array_length[0] is '*':
                            length = value.array_length + '->GetPointer()'
                        else:
                            length = value.array_length
                    code += '    {}->AllocateOutputData({});\n'.format(value.name, length)

                    if value.platform_base_type:
                        code += '    auto out_op_{0}   = reinterpret_cast<{1}*>({0}->GetOutputPointer());\n'\
                                .format(value.name, value.platform_base_type)
                    else:
                        code += '    auto out_op_{0}   = {0}->GetOutputPointer();\n'\
                                .format(value.name)

                    if is_override:
                        arg_list.append(value.name)
                    else:
                        arg_list.append('out_op_{}'.format(value.name))

                    post_extenal_object_list.append(
                        'PostProcessExternalObject(replay_result, out_op_{0}, out_p_{0}, format::ApiCallId::ApiCall_{1}, "{1}");\n'
                        .format(value.name, name)
                    )
                else:
                    if value.platform_base_type:
                        code += '    auto in_{0} = static_cast<{2}>(PreProcessExternalObject({0}, format::ApiCallId::ApiCall_{1}, "{1}"));\n'\
                                .format(value.name, name, value.platform_base_type)
                    else:
                        code += '    auto in_{0} = PreProcessExternalObject({0}, format::ApiCallId::ApiCall_{1}, "{1}");\n'\
                                .format(value.name, name)
                    arg_list.append('in_{}'.format(value.name))

            elif (value.base_type in self.structs_with_handles
                  ) or (value.base_type in self.GENERIC_HANDLE_STRUCTS):
                if value.is_array:
                    print(
                        'ERROR: It does not deal with array objects, {}, in struct(MapStructArrayObjects).'
                        .format(value.name)
                    )
                else:
                    code += '    MapStructObjects({}->GetMetaStructPointer(), GetObjectInfoTable());\n'.format(
                        value.name
                    )
                    arg_list.append(value.name + '->GetPointer()')

            else:
                if is_override:
                    arg_list.append(value.name)

                elif value.pointer_count > 0 or value.is_array:
                    if is_struct and value.pointer_count == 2 and value.is_const:
                        arg_list.append(
                            'const_cast<const {}**>({}->GetPointer())'.format(
                                value.base_type, value.name
                            )
                        )
                    else:
                        arg_list.append(value.name + '->GetPointer()')

                else:
                    if is_struct:
                        arg_list.append('*' + value.name + '.decoded_value')

                    elif value.base_type == 'PFN_DESTRUCTION_CALLBACK':
                        arg_list.append(
                            'reinterpret_cast<PFN_DESTRUCTION_CALLBACK>({})'.
                            format(value.name)
                        )

                    else:
                        arg_list.append(value.name)

        indent_length = len(code)
        code += '    '
        if return_type != 'void':
            code += 'auto replay_result = '

        if is_object and not is_override:
            code += 'replay_object->'

        first = True
        if is_override:
            if is_object:
                code += self.REPLAY_OVERRIDES['classmethods'][class_name][
                    method_name] + '('
            else:
                code += self.REPLAY_OVERRIDES['functions'][name] + '('

            indent_length = len(code) - indent_length
            if is_object:
                code += 'replay_object'
                first = False

            if return_type != 'void':
                if not first:
                    code += ',\n{}'.format(' ' * indent_length)
                code += 'returnValue'
                first = False
        else:
            function_name = name if not is_object else name[name.find('_')
                                                            + 1:]
            code += function_name + '('
            indent_length = len(code) - indent_length

        for arg in arg_list:
            if not first:
                code += ',\n{}'.format(' ' * indent_length)
            first = False
            code += arg

        code += ');\n'

        if return_type == 'HRESULT':
            if len(add_object_list):
                code += ("    if (SUCCEEDED(replay_result))\n" "    {\n")
                for e in add_object_list:
                    code += '        {}'.format(e)
                code += "    }\n"

            code += (
                '    CheckReplayResult("{}", returnValue, replay_result);\n'.
                format(name)
            )

        for e in post_extenal_object_list:
            code += '    {}'.format(e)
        return code

    def is_output(self, value):
        if value.full_type.find('_Out') != -1:
            return True
        return False

    def __load_replay_overrides(self, filename):
        overrides = json.loads(open(filename, 'r').read())
        self.REPLAY_OVERRIDES = overrides
