#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
# Copyright (c) 2023-2025 Qualcomm Technologies, Inc. and/or its subsidiaries.
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
import re
from dx12_base_generator import Dx12BaseGenerator, Dx12GeneratorOptions, write
from dx12_replay_consumer_header_generator import Dx12ReplayConsumerHeaderGenerator, Dx12ReplayConsumerHeaderGeneratorOptions
from dx12_base_replay_consumer_body_generator import Dx12BaseReplayConsumerBodyGenerator


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
    Dx12BaseReplayConsumerBodyGenerator, Dx12ReplayConsumerHeaderGenerator
):
    """Generates C++ functions responsible for consuming Dx12 API calls."""

    REPLAY_OVERRIDES = {}

    # API calls with variable length array semantics, with an inout pointer
    # to an array size that retrieves the expected size of the array when the
    # pointer to the array is null, but do not have the array pointer labeled
    # with the 'opt' SAL marking. For these functions, we assume that 'opt' was
    # accidentally omitted and that the function should be treated as if the
    # 'opt' were present.
    EXTRA_VARIABLE_LENGTH_ARRAYS = {
        'IDXGIObject_GetPrivateData': ['pData'],
        'ID3D12ShaderCacheSession_FindValue': ['pValue']
    }

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
        self.structs_with_handles = {
            **self.CUSTOM_STRUCT_HANDLE_MAP, 'D3D12_CPU_DESCRIPTOR_HANDLE':
            ['ptr']
        }
        self.structs_with_handle_ptrs = []
        self.structs_with_map_data = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        Dx12ReplayConsumerHeaderGenerator.beginFile(self, gen_opts)
        if gen_opts.replay_overrides:
            self.__load_replay_overrides(gen_opts.replay_overrides)

    def write_include(self):
        """Method override."""
        write(
            '#include "generated/generated_dx12_replay_consumer.h"',
            file=self.outFile
        )
        self.newline()
        write(
            '#include "decode/custom_dx12_struct_object_mappers.h"',
            file=self.outFile
        )
        write(
            '#include "decode/custom_dx12_replay_commands.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_dx12_struct_object_mappers.h"',
            file=self.outFile
        )
        self.newline()
        write(
            '#ifdef GFXRECON_AGS_SUPPORT',
            file=self.outFile
        )
        write(
            '#include "decode/ags_gpu_cmd_wrapper.h"',
            file=self.outFile
        )
        write(
            '#endif',
            file=self.outFile
        )
        self.newline()

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        Dx12BaseGenerator.genStruct(self, typeinfo, typename, alias)
        if not alias:
            for struct_name in self.get_filtered_struct_names():
                self.check_struct_member_handles(
                    struct_name, self.structs_with_handles,
                    self.structs_with_handle_ptrs, True,
                    self.structs_with_map_data, ['D3D12_GPU_VIRTUAL_ADDRESS']
                )

    def generate_feature(self):
        """Method override."""
        header_dict = self.source_dict['header_dict']
        self.structs_with_objects = self.collect_struct_with_objects(
            header_dict
        )
        Dx12BaseGenerator.generate_feature(self)
        Dx12BaseReplayConsumerBodyGenerator.generate_feature(self)
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

            cmddef += (
                "    auto replay_object = GetObjectInfo(object_id);\n"
                "    if ((replay_object != nullptr) &&"
                " (replay_object->object != nullptr))\n"
                "    {\n"
            )

            if 'ID3D12GraphicsCommandList' in class_name:
                    cmddef += ("#ifdef GFXRECON_AGS_SUPPORT\n".format(method)
                    )
                    cmddef += (
                        "        AgsGpuCmdWrapper ags_gpu_cmd_wrapper(&options_, static_cast<ID3D12GraphicsCommandList*>(replay_object->object), object_id, format::ApiCallId::ApiCall_{0}, GetCurrentBlockIndex());\n".format(method)
                    )
                    cmddef += ("#endif\n\n".format(method)
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
        """Method override."""
        code = ''
        arg_list = []
        add_object_list = []
        set_resource_dimension_layout_list = []
        struct_add_object_list = []
        pre_call_expr_list = []
        post_call_expr_list = []
        post_extenal_object_list = []

        is_override = name in self.REPLAY_OVERRIDES
        is_resource_creation_methods = False
        is_object = True if name.find('_') != -1 else False
        if is_object:
            class_name = name[:name.find('_')]
            method_name = name[name.find('_') + 1:]
            if class_name in self.REPLAY_OVERRIDES['classmethods']:
                is_override = method_name in self.REPLAY_OVERRIDES[
                    'classmethods'][class_name]
            if re.search("^Create.+Resource[0-9]*$", method_name) is not None:
                is_resource_creation_methods = True
        else:
            is_override = name in self.REPLAY_OVERRIDES['functions']

        code += (
            "    CustomReplayPreCall<format::ApiCallId::ApiCall_{}>::Dispatch(\n"
            "        this,\n"
            "        call_info,".format(name)
        )

        if is_object:
            code += "\n        replay_object,"

        for value in values:
            code += ('\n' + "        " + value.name + ",")

        code = code[:-1]
        code += ");\n"

        # Generate a dictionary of variable length array size parameter info to be used with
        # storing and retrieving the array sizes returned by API calls that return the expected
        # size of the array when the array parameter is null.
        variable_array_lengths = {}
        for value in values:
            if self.is_variable_length_array(name, value):
                base_length_name = value.array_length.replace('* ', '')
                variable_array_lengths[base_length_name] = {
                    'array_value': value,
                    'length_value': self.find_value(base_length_name, values)
                }

        for value in values:
            is_class = self.is_class(value)
            is_extenal_object = (
                value.base_type in self.EXTERNAL_OBJECT_TYPES
            ) and not value.is_array
            is_output = self.is_output(value)
            if value.full_type == '_Out_ void *' or value.full_type == '_Inout_ void *':
                is_output = False

            is_struct = self.is_struct(value.base_type)
            is_variable_length_array = self.is_variable_length_array(
                name, value
            )

            if is_output:
                if value.base_type in self.structs_with_objects:
                    struct_add_object_list.append(
                        'AddStructObjects({0}, {0}->GetPointer(), GetObjectInfoTable());\n'
                        .format(value.name)
                    )
                elif is_variable_length_array:
                    # This is an optional output array with an array size parameter that is
                    # also a pointer. This array parameter may adhere to a pattern that, when
                    # it is null, the API call will return the expected input array size in
                    # the value pointed to by the array size parameter. In this case, we can
                    # store the value returned here and use it to allocate an array of this
                    # stored size on the next call when the array pointer is not null.
                    if is_object:
                        post_call_expr_list.append(
                            self.make_variable_length_array_post_expr(
                                name, value
                            )
                        )
                    else:
                        print(
                            "ERROR: Variable length output array size tracking is not implemented for function calls."
                        )

            if is_class:
                if is_output:
                    handles = 1
                    if is_variable_length_array:
                        handles = value.array_length.replace(
                            ' ', ''
                        ) + '->GetOutputPointer()'
                        array_length = value.array_length.replace('* ', '')
                        # Ensure that the array's output data initialization expression is written to the
                        # file after the size parameter is initialized, storing the expression string now
                        # and appending it to the code string immediately before generating the API call,
                        # after all other parameters have been processed.
                        set_length_expr = '    if(!{}->IsNull() && !{}->IsNull())\n    {{\n        {}->SetHandleLength({});\n'.format(
                            value.name, array_length, value.name, handles
                        )

                        if is_override:
                            set_length_expr += '        for (size_t i = 0; i < {1}; ++i) {{ {0}->SetConsumerData(i, &object_info_{0}[i]); }}\n'.format(
                                value.name, handles
                            )
                            set_length_expr += '    }\n'
                        else:
                            set_length_expr += '    }\n'
                            set_length_expr += '    auto out_p_{0}    = {0}->GetPointer();\n'\
                                               '    auto out_hp_{0}   = {0}->GetHandlePointer();\n'.format(value.name)

                        # Add a null check to the expression stored in handles for its use here and in the
                        # AddObjects expression generated below.
                        handles = '!{}->IsNull() ? {} : 0'.format(array_length, handles)
                        if is_override:
                            set_length_expr = '    std::vector<DxObjectInfo> object_info_{}({});\n'.format(
                                value.name, handles
                            ) + set_length_expr
                        pre_call_expr_list.append(set_length_expr)
                    else:
                        if value.array_length:
                            if isinstance(value.array_length, str
                                          ) and value.array_length[0] == '*':
                                handles = value.array_length + '->GetPointer()'
                            else:
                                handles = value.array_length
                        if is_override:
                            if value.array_length:
                                code += '    std::vector<DxObjectInfo> object_info_{}({});\n'.format(
                                    value.name, handles
                                )
                            else:
                                code += '    DxObjectInfo object_info_{}{{}};\n'.format(
                                    value.name
                                )
                            code += '    if(!{0}->IsNull())\n    {{\n        {0}->SetHandleLength({1});\n'\
                                    .format(value.name, handles)
                            if value.array_length:
                                code += '        for (size_t i = 0; i < {1}; ++i) {{ {0}->SetConsumerData(i, &object_info_{0}[i]); }}\n'.format(
                                    value.name, handles
                                )
                            else:
                                code += '        {0}->SetConsumerData(0, &object_info_{0});\n'\
                                        .format(value.name)
                            code += '    }\n'
                        else:
                            code += '    if(!{0}->IsNull()) {0}->SetHandleLength({1});\n'\
                                        .format(value.name, handles)
                            code += '    auto out_p_{0}    = {0}->GetPointer();\n'\
                                    '    auto out_hp_{0}   = {0}->GetHandlePointer();\n'\
                                    .format(value.name)

                    if is_override:
                        arg_list.append(value.name)
                        if value.array_length:
                            add_object_list.append(
                                 'AddObjects({0}->GetPointer(), {0}->GetLength(), {0}->GetHandlePointer(), {1}'\
                                 'std::move(object_info_{0}), format::ApiCall_{2});\n'\
                                 .format(value.name, handles, name)
                            )
                        else:
                            add_object_list.append(
                                'AddObject({0}->GetPointer(), {0}->GetHandlePointer(), '\
                                'std::move(object_info_{0}), format::ApiCall_{1});\n'\
                                .format(value.name, name)
                            )
                    else:
                        arg_list.append('out_hp_{}'.format(value.name))
                        if value.array_length:
                            add_object_list.append(
                                'AddObjects(out_p_{0}, {0}->GetLength(), out_hp_{0}, {1}, format::ApiCall_{2});\n'
                                .format(value.name, handles, name)
                            )
                        else:
                            add_object_list.append(
                                'AddObject(out_p_{0}, out_hp_{0}, format::ApiCall_{1});\n'.format(
                                    value.name, name
                                )
                            )

                    set_resource_dimension_layout_list.append(
                        'SetResourceDesc({0}, pDesc);\n'.format(
                            value.name
                        )
                    )
                else:
                    if value.pointer_count == 2:
                        if is_override:
                            code += '    MapObjects<{1}>({0}, {2});\n'.format(
                                value.name, value.base_type, value.array_length
                            )
                            arg_list.append(value.name)
                        else:
                            code += '    auto in_{0} = MapObjects<{1}>({0}, {2});\n'.format(
                                value.name, value.base_type, value.array_length
                            )
                            arg_list.append('in_{}'.format(value.name))

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

            elif is_extenal_object:
                if is_output:
                    length = '1'
                    if value.array_length:
                        if value.array_length[0] == '*':
                            length = value.array_length + '->GetPointer()'
                        else:
                            length = value.array_length
                    code += '    if(!{}->IsNull())\n    {{\n        {}->AllocateOutputData({});\n    }}\n'.format(
                        value.name, value.name, length
                    )

                    if is_override:
                        arg_list.append(value.name)

                    else:
                        code += '    auto out_p_{0}    = {0}->GetPointer();\n'\
                            .format(value.name)

                        if value.platform_base_type:
                            code += '    auto out_op_{0}   = reinterpret_cast<{1}*>({0}->GetOutputPointer());\n'\
                                    .format(value.name, value.platform_base_type)
                        else:
                            code += '    auto out_op_{0}   = {0}->GetOutputPointer();\n'\
                                    .format(value.name)

                        arg_list.append('out_op_{}'.format(value.name))
                        post_extenal_object_list.append(
                            'PostProcessExternalObject(replay_result, reinterpret_cast<void**>(out_op_{0}), out_p_{0}, format::ApiCallId::ApiCall_{1}, "{1}");\n'
                            .format(value.name, name)
                        )

                else:
                    if is_override:
                        arg_list.append(value.name)
                    else:
                        if value.platform_base_type:
                            code += '    auto in_{0} = static_cast<{2}>(PreProcessExternalObject({0}, format::ApiCallId::ApiCall_{1}, "{1}"));\n'\
                                    .format(value.name, name, value.platform_base_type)
                        else:
                            code += '    auto in_{0} = PreProcessExternalObject({0}, format::ApiCallId::ApiCall_{1}, "{1}");\n'\
                                    .format(value.name, name)
                        arg_list.append('in_{}'.format(value.name))

            elif (value.base_type in self.structs_with_handles) or (
                value.base_type in self.GENERIC_HANDLE_STRUCTS
            ) or (value.base_type in self.structs_with_map_data):
                if value.is_pointer:
                    if value.is_array:
                        code += '    MapStructArrayObjects({0}->GetMetaStructPointer(), {0}->GetLength(), GetObjectInfoTable(), GetGpuVaTable());\n'.format(
                            value.name
                        )
                    else:
                        code += '    MapStructObjects({}->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());\n'.format(
                            value.name
                        )
                    if is_override:
                        arg_list.append(value.name)
                    else:
                        arg_list.append(value.name + '->GetPointer()')
                else:
                    if value.is_array:
                        code += '    MapStructArrayObjects(&{}, {}->GetLength(), GetObjectInfoTable(), GetGpuVaTable());\n'.format(
                            value.name
                        )
                    else:
                        code += '    MapStructObjects(&{}, GetObjectInfoTable(), GetGpuVaTable());\n'.format(
                            value.name
                        )
                    arg_list.append('*{}.decoded_value'.format(value.name))
            else:
                if is_output:
                    if is_variable_length_array:
                        length = value.array_length.replace('* ', '')
                        # Ensure that the array's output data initialization expression is written to the
                        # file after the size parameter is initialized, storing the expression string now
                        # and appending it to the code string immediately before generating the API call,
                        # after all other parameters have been processed.
                        pre_call_expr_list.append(
                            '    if(!{}->IsNull() && !{}->IsNull())\n    {{\n        {}->AllocateOutputData({}->GetOutputPointer());\n    }}\n'
                            .format(
                                value.name, length, value.name,
                                value.array_length.replace(' ', '')
                            )
                        )
                    elif value.name in variable_array_lengths:
                        code += '    if(!{}->IsNull())\n    {{\n        {}->AllocateOutputData(1, {});\n    }}\n'.format(
                            value.name, value.name,
                            self.make_variable_length_array_get_count_call(
                                return_type, name,
                                **variable_array_lengths[value.name]
                            )
                        )
                    else:
                        length = '1'
                        # The _result_bytebuffer_ annotation indicates that the parameter is a pointer to a
                        # pointer to a buffer allocated by the runtime/driver. For this case, only the single
                        # pointer to the output buffer needs to be allocated.
                        if value.array_length and (
                            not '_result_bytebuffer_' in value.full_type
                        ):
                            if isinstance(value.array_length, str
                                          ) and value.array_length[0] == '*':
                                length = '!{}->IsNull() ? {}->GetPointer() : 0'.format(
                                    value.array_length.replace('* ', ''),
                                    value.array_length.replace(' ', '')
                                )
                            else:
                                length = value.array_length
                        else:
                            for dict_name, not_array_list in self.NOT_ARRAY_DICT.items():
                                if value.name in not_array_list:
                                    length = '!{}ByteLength->IsNull() ? *{}ByteLength->GetPointer() : 1'.format(
                                        value.name, value.name)
                                    break
                        code += '    if(!{}->IsNull())\n    {{\n        {}->AllocateOutputData({});\n    }}\n'.format(
                            value.name, value.name, length
                        )
                else:
                    map_func = self.MAP_STRUCT_TYPE.get(value.base_type)
                    if map_func:
                        if value.is_array:
                            code += '    if ({0} && !{0}->IsNull())\n'\
                                    '    {{\n'\
                                    '        {2}({0}->GetPointer(), {1});\n'\
                                    '    }}\n'.format(
                                value.name, value.array_length, map_func[1]
                            )
                        else:
                            if value.is_pointer:
                                code += '    if ({0} && !{0}->IsNull())\n'\
                                        '    {{\n'\
                                        '        {1}(*{0}->GetPointer());\n'\
                                        '    }}\n'.format(
                                    value.name, map_func[0]
                                )
                            else:
                                if is_struct:
                                    code += '    {}(*{}.decoded_value);\n'.format(
                                        map_func[0], value.name
                                    )
                                else:
                                    code += '    {}({});\n'.format(
                                        map_func[0], value.name
                                    )

                if is_override:
                    arg_list.append(value.name)

                elif value.pointer_count > 0 or value.is_array:
                    if is_struct and value.pointer_count == 2 and value.is_const:
                        if is_output:
                            code += '    auto in_{0}    = {0}->GetOutputPointer();\n'\
                                .format(value.name)
                        else:
                            code += '    auto in_{0}    = {0}->GetPointer();\n'\
                                .format(value.name)
                        arg_list.append(
                            'const_cast<const {}**>(&in_{})'.format(
                                value.base_type, value.name
                            )
                        )
                    else:
                        if is_output:
                            arg_list.append(value.name + '->GetOutputPointer()')
                        else:
                            arg_list.append(value.name + '->GetPointer()')

                else:
                    if is_struct:
                        arg_list.append('*' + value.name + '.decoded_value')

                    elif self.is_callback(value.base_type):
                        code += '    auto in_{0} = reinterpret_cast<{2}>(GetReplayCallback({0}, format::ApiCallId::ApiCall_{1}, "{1}"));\n'\
                                .format(value.name, name, value.base_type)
                        arg_list.append('in_{}'.format(value.name))

                    else:
                        arg_list.append(value.name)

        for e in pre_call_expr_list:
            code += e

        indent_length = len(code)
        code += '    '
        if return_type != 'void':
            code += 'auto replay_result = '

        if is_object and not is_override:
            code += 'reinterpret_cast<{}*>(replay_object->object)->'.format(class_name)

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
                code += 'return_value'
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

        if is_object and not is_override and ('ID3D12GraphicsCommandList' in class_name):
            code += (
                "    if(options_.enable_dump_resources)\n"
                "    {{\n"
                "        GFXRECON_ASSERT(dump_resources_);\n"
                "        auto dump_command_sets = dump_resources_->GetCommandListsForDumpResources(replay_object, call_info.index, format::ApiCall_{}_{});\n"
                "        for (auto& command_set : dump_command_sets)\n"
                "        {{\n".format(class_name, method_name)
            )
            if class_name != 'ID3D12GraphicsCommandList':
                code += (
                    "            graphics::dx12::{0}ComPtr command_list{1};\n"
                    "            command_set.list->QueryInterface(IID_PPV_ARGS(&command_list{1}));\n".format(class_name, class_name[-1])
                )
                indent_length = len(code)
                code += "            command_list{}".format(class_name[-1])

            else:
                indent_length = len(code)
                code += "            command_set.list"
            code += "->{}(".format(method_name)

            first = True
            indent_length = len(code) - indent_length
            for arg in arg_list:
                if not first:
                    code += ',\n{}'.format(' ' * indent_length)
                first = False
                code += arg

            code += (
                ");\n"
                "        }\n"
                "    }\n"
            )

        for e in post_call_expr_list:
            code += '    {}'.format(e)

        if len(add_object_list) or len(struct_add_object_list):
            scope_indent = '    '
            if return_type == 'HRESULT':
                code += "    if (SUCCEEDED(replay_result))\n    {\n"
                scope_indent += '    '
            for e in add_object_list:
                code += scope_indent + '{}'.format(e)
            for e in struct_add_object_list:
                code += scope_indent + '{}'.format(e)
            if is_resource_creation_methods:
                for e in set_resource_dimension_layout_list:
                    code += '        {}'.format(e)
            if return_type == 'HRESULT':
                code += "    }\n"

        if return_type == 'HRESULT':
            code += (
                '    CheckReplayResult("{}", return_value, replay_result);\n'.
                format(name)
            )

        code += (
            "    CustomReplayPostCall<format::ApiCallId::ApiCall_{}>::Dispatch(\n"
            "        this,\n"
            "        call_info,".format(name)
        )

        if is_object:
            code += "\n        replay_object,"

        if return_type != 'void':
            code += (
                "\n        return_value,"
                "\n        replay_result,"
            )

        for value in values:
            code += ('\n' + "        " + value.name + ",")

        code = code[:-1]
        code +=");\n"

        for e in post_extenal_object_list:
            code += '    {}'.format(e)
        return code

    def find_value(self, name, values):
        for value in values:
            if value.name == name:
                return value

    def is_variable_length_array(self, name, value):
        return value.is_array and value.array_length and isinstance(
            value.array_length, str
        ) and value.array_length.startswith('*') and (
            ('_opt_' in value.full_type) or (
                (name in self.EXTRA_VARIABLE_LENGTH_ARRAYS) and
                (value.name in self.EXTRA_VARIABLE_LENGTH_ARRAYS[name])
            )
        )

    def get_variable_length_array_index_id(self, name):
        class_name = name[:name.find('_')][1:].replace('DXGI', 'Dxgi')
        method_name = name[name.find('_') + 1:]
        index_id = 'VariableLengthArrayIndices::k{}Array{}'.format(
            class_name, method_name
        )
        return index_id

    def make_variable_length_array_post_expr(self, name, value):
        """Generate expressions to store the result of the count query for an array containing a variable number of values."""
        index_id = self.get_variable_length_array_index_id(name)

        length_name = value.array_length
        base_length_name = length_name.replace('* ', '')
        return 'if ({}->IsNull() && !{}->IsNull()) {{ SetOutputArrayCount(object_id, {}, {}->GetOutputPointer()); }}\n'.format(
            value.name, base_length_name, index_id,
            length_name.replace(' ', '')
        )

    def make_variable_length_array_get_count_call(
        self, return_type, name, array_value, length_value
    ):
        """Generate expression to call a function that retrieves the count of an array containing a variable number of values."""
        return_value = 'S_OK'
        if (return_type == 'HRESULT'):
            return_value = 'return_value'

        index_id = self.get_variable_length_array_index_id(name)

        return 'GetOutputArrayCount("{}", {}, object_id, {}, {}, {})'.format(
            name.replace('_', '::'), return_value, index_id, length_value.name,
            array_value.name
        )

    def __load_replay_overrides(self, filename):
        overrides = json.loads(open(filename, 'r').read())
        self.REPLAY_OVERRIDES = overrides
