#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2024 LunarG, Inc.
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

from khronos_base_generator import write


class KhronosReplayConsumerBodyGenerator():
    """Base class for generating replay cousumers body code."""

    def generate_replay_consumer_content(self):
        """Performs C++ code generation for the replay consumer."""
        platform_type = self.get_api_prefix()

        for cmd in self.get_all_filtered_cmd_names():

            if self.is_resource_dump_class(
            ) and self.is_dump_resources_api_call(cmd) == False:
                continue

            info = self.all_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            cmddef = '\n'
            if self.is_resource_dump_class():
                cmddef += self.make_dump_resources_func_decl(
                    return_type,
                    '{}ReplayDumpResources::Process_'.format(platform_type)
                    + cmd, values, cmd in self.DUMP_RESOURCES_OVERRIDES
                ) + '\n'
            else:
                cmddef += self.make_consumer_func_decl(
                    return_type,
                    '{}ReplayConsumer::Process_'.format(platform_type) + cmd,
                    values
                ) + '\n'
            cmddef += '{\n'
            cmddef += self.make_consumer_func_body(return_type, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)

    def generate_extended_struct_handling(self):
        api_data = self.get_api_data()
        var_name = 'in_' + api_data.extended_struct_variable.lower()

        self.newline()
        write(
            'static void InitializeOutputStruct{}Impl(const {}* in_pnext, {}* output_struct)'
            .format(
                api_data.extended_struct_func_prefix, api_data.base_in_struct,
                api_data.base_out_struct
            ),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    while({})'.format(var_name), file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        switch({}->{})'.format(
                var_name, api_data.struct_type_variable
            ),
            file=self.outFile
        )
        write('        {', file=self.outFile)
        for struct in self.struct_type_names:
            struct_type = self.struct_type_names[struct]
            write(
                '            case {}:'.format(struct_type), file=self.outFile
            )
            write('            {', file=self.outFile)
            write(
                '                output_struct->{} = reinterpret_cast<{}*>(DecodeAllocator::Allocate<{}>());'
                .format(
                    api_data.extended_struct_variable,
                    api_data.base_out_struct, struct
                ),
                file=self.outFile
            )
            write('                break;', file=self.outFile)
            write('            }', file=self.outFile)
        write('            default:', file=self.outFile)
        write('                break;', file=self.outFile)
        write('        }', file=self.outFile)
        write(
            '        output_struct = output_struct->{};'.format(
                api_data.extended_struct_variable
            ),
            file=self.outFile
        )
        write(
            '        output_struct->{0} = {1}->{0};'.format(
                api_data.struct_type_variable, var_name
            ),
            file=self.outFile
        )
        write(
            '        {0} = {0}->{1};'.format(
                var_name, api_data.extended_struct_variable
            ),
            file=self.outFile
        )
        write('    }', file=self.outFile)
        write('}', file=self.outFile)

        self.newline()
        write('template <typename T>', file=self.outFile)
        write(
            'void InitializeOutputStruct{}(StructPointerDecoder<T> *decoder)'.
            format(api_data.extended_struct_func_prefix),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    if(decoder->IsNull()) return;', file=self.outFile)
        write(
            '    size_t len = decoder->GetOutputLength();', file=self.outFile
        )
        write('    auto input = decoder->GetPointer();', file=self.outFile)
        write(
            '    auto output = decoder->GetOutputPointer();',
            file=self.outFile
        )
        write('    for( size_t i = 0 ; i < len; ++i )', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        const auto* {} = reinterpret_cast<const {}*>(input[i].{});'
            .format(
                var_name, api_data.base_in_struct,
                api_data.extended_struct_variable
            ),
            file=self.outFile
        )
        write(
            '        if( {} == nullptr ) continue;'.format(var_name),
            file=self.outFile
        )
        write(
            '        auto* output_struct = reinterpret_cast<{}*>(&output[i]);'.
            format(api_data.base_out_struct),
            file=self.outFile
        )
        write(
            '        InitializeOutputStruct{}Impl({}, output_struct);'.format(
                api_data.extended_struct_func_prefix, var_name
            ),
            file=self.outFile
        )
        write('    }', file=self.outFile)
        write('}', file=self.outFile)

    def needs_remove_handle_expression(self, command):
        """ Method may be overridden. """
        api_data = self.get_api_data()
        if (
            command.startswith(api_data.command_prefix)
            and command[len(api_data.command_prefix):].startswith('Destroy')
        ):
            return True
        return False

    def determine_remove_value(self, command, values):
        """ Method may be overridden. """
        return values[0]

    def generate_remove_handle_expression(self, command, values):
        """ Method may be overridden. """
        if self.needs_remove_handle_expression(command):
            value = self.determine_remove_value(command, values)
            return 'RemoveHandle({}, &CommonObjectInfoTable::Remove{basetype}Info);'.format(
                value.name, basetype=value.base_type
            )

    def make_variable_length_array_post_expr(
        self, name, value, values, length_name
    ):
        """
        Generate expressions to store the result of the count query for an array containing
        a variable number of values.
        """
        handle_value = values[0]
        api_data = self.get_api_data()
        if self.is_handle(values[1].base_type):
            handle_value = values[1]

        index_id = 'k{}Array{}'.format(handle_value.base_type[2:], name[2:])
        handle_type = '{}{}Info'.format(
            api_data.api_class_prefix, handle_value.base_type[2:]
        )
        info_func = '&CommonObjectInfoTable::Get{}Info'.format(
            handle_value.base_type
        )

        return 'if ({}->IsNull()) {{ SetOutputArrayCount<{}>({}, {}, {}, {}); }}'.format(
            value.name, handle_type, handle_value.name, index_id, length_name,
            info_func
        )

    def make_variable_length_array_get_count_call(
        self, return_type, name, value, values
    ):
        """
        Generate expressions to call a function that retrieves the count of an array
        containing a variable number of values.
        """
        api_data = self.get_api_data()
        return_value = api_data.return_type_success_value
        if (return_type == api_data.return_type_enum):
            return_value = 'returnValue'

        handle_value = values[0]
        if self.is_handle(values[1].base_type):
            handle_value = values[1]

        array_name = None
        for v in values:
            if v.array_length == value.name:
                array_name = v.name

        if not array_name:
            print(
                "WARNING: Could not determine the name of the array parameter associate with function {} count parameter {}."
                .format(name, value.name)
            )

        index_id = 'k{}Array{}'.format(handle_value.base_type[2:], name[2:])
        handle_type = '{}{}Info'.format(
            api_data.api_class_prefix, handle_value.base_type[2:]
        )
        info_func = '&CommonObjectInfoTable::Get{}Info'.format(
            handle_value.base_type
        )

        return 'GetOutputArrayCount<{}, {}>("{}", {}, {}, {}, {}, {}, {})'.format(
            value.base_type, handle_type, name, return_value,
            handle_value.name, index_id, value.name, array_name, info_func
        )
