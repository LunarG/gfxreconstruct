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

    def get_parent_id(self, api_data, value, values):
        """Get the ID of the parent object when creating a handle.  The instance type is does not have a parent object."""
        if value.base_type != api_data.instance_type:
            return values[0].name
        return 'format::kNullHandleId'

    def use_instance_table(self, api_data, name, typename):
        """
        Check for dispatchable handle types associated with the instance dispatch table.
        May be overridden.
        """
        if not api_data.has_device or self.is_instance_type(typename):
            return True
        return False

    def is_pool_allocation(self, command):
        """Method may be overriden. """
        return False

    def get_pool_allocation_type(self, value):
        """Method may be overriden. """
        return None

    def check_skip_offscreen(self, values, name):
        """Method may be overriden. """
        return ''

    def check_skip_extended_struct_handling(self, struct, struct_type):
        """Method may be overriden. """
        return False

    def generate_custom_extended_struct_handling(self, struct, struct_type):
        """ Method may be overriden.
            None implies no customization
        """

        return None

    def handle_instance_device_items(self):
        """Method may be overriden. """
        return '', []

    def is_custom_return_type(self, api_data, typename):
        """Method may be overriden. """
        return typename == api_data.return_type_enum

    def handle_custom_return_type(self, name, dispatch_func, arg_list):
        """Method may be overriden. """
        return '{}({}, call_info.index, returnValue, {})'.format(
            self.REPLAY_OVERRIDES[name], dispatch_func, arg_list
        )

    def is_custom_dump_resource_type(self, is_dump_resources, is_override, name, value):
        """Method may be overriden. """
        return False

    def handle_custom_dump_resource_type(self, is_dump_resources, is_override, name, value):
        """Method may be overriden. """
        return ''

    def make_consumer_func_body(self, api_data, return_type, name, values):
        """
        Method override.
        Return ReplayConsumer class member function definition.
        """
        body = ''
        is_override = name in self.REPLAY_OVERRIDES
        is_dump_resources = self.is_dump_resources_api_call(name)

        is_skip_offscreen = True

        # function 'can' use asynchronous control-flow
        is_async = name in self.REPLAY_ASYNC_OVERRIDES

        for key in self.NOT_SKIP_FUNCTIONS_OFFSCREEN:
            if key in name:
                is_skip_offscreen = False
                break

        if is_skip_offscreen:
            body += self.check_skip_offscreen(values, name)

        args, preexpr, postexpr, push_handleid_expr = self.make_body_expression(
            api_data, return_type, name, values, is_override
        )
        arglist = ', '.join(args)

        dispatchfunc = ''
        if not self.is_core_type(name):
            object_name = args[0]
            object_name_is_handle = False
            if self.use_instance_table(name, values[0].base_type):
                dispatchfunc = 'GetInstanceTable'
                if api_data.has_device and values[0].base_type == api_data.device_type:
                    object_name, device_items = self.handle_instance_device_items()
                    preexpr.extend(device_items)
                    object_name_is_handle = True
            else:
                dispatchfunc = 'GetDeviceTable'

            if is_override and not object_name_is_handle:
                dispatchfunc += '({}->handle)->{}'.format(object_name, name[2:])
            else:
                dispatchfunc += '({})->{}'.format(object_name, name[2:])

        call_expr = ''
        if is_override:
            if self.is_core_create_command(name, True):
                call_expr = '{}(returnValue, {})'.format(
                    self.REPLAY_OVERRIDES[name], arglist
                )
            elif self.is_custom_return_type(api_data, return_type):
                call_expr = self.handle_custom_return_type(name, dispatchfunc, arglist)
            else:
                call_expr = '{}({}, {})'.format(
                    self.REPLAY_OVERRIDES[name], dispatchfunc, arglist
                )
        else:
            call_expr = '{}({})'.format(dispatchfunc, arglist)

        if preexpr:
            body += '\n'.join(
                ['    ' + val if val else val for val in preexpr]
            )
            body += '\n'
            body += '\n'
        if return_type == api_data.return_type_enum:
            if is_async:
                body += '    if (UseAsyncOperations())\n'
                body += '    {\n'
                body += '        auto task = {}({}, returnValue, call_info, {});\n'.format(self.REPLAY_ASYNC_OVERRIDES[name], dispatchfunc, arglist)
                body += '        if(task)\n'
                body += '        {\n'
                body += '           {}\n'.format(postexpr[0])
                body += '           return;\n'
                body += '        }\n'
                body += '    }\n'
                postexpr = postexpr[1:]  # drop async post-expression, don't repeat later

            body += push_handleid_expr[0]
            body += '    {} replay_result = {};\n'.format(api_data.return_type_enum, call_expr)
            body += '    CheckResult("{}", returnValue, replay_result, call_info);\n'.format(name)
        else:
            body += push_handleid_expr[0]
            body += '    {};\n'.format(call_expr)
        body += push_handleid_expr[1]

        # Dump resources code generation
        if is_dump_resources:
            is_dr_override = name in self.DUMP_RESOURCES_OVERRIDES

            dump_resource_arglist = ''
            if is_override:
                for val in values:
                    if val.is_pointer and self.is_struct(val.base_type):
                        if is_dr_override:
                            dump_resource_arglist += val.name
                        else:
                            dump_resource_arglist += val.name + '->GetPointer()'
                    elif self.is_handle(val.base_type):
                        if val.is_pointer:
                            if is_dr_override and val.base_type != "VkCommandBuffer":
                                dump_resource_arglist += val.name
                            else:
                                dump_resource_arglist += val.name + '->GetHandlePointer()'
                        elif self.is_custom_dump_resource_type(is_dump_resources, is_override, name, val):
                            dump_resource_arglist += self.handle_custom_dump_resource_type(is_dump_resources, is_override, name, val)
                        else:
                            dump_resource_arglist += 'in_' + val.name + '->handle'
                    else:
                        if val.is_pointer and val.base_type in ["void", "uint32_t"]:
                            # avoids passing a PointerDecoder* here (which is wrong but compiles fine, yikes)
                            # -> dump-resource API expects raw void*
                            dump_resource_arglist += val.name + '->GetPointer()'
                        else:
                            dump_resource_arglist += val.name
                    dump_resource_arglist += ', '
                dump_resource_arglist = dump_resource_arglist[:-2]
            else:
                if is_dr_override:
                    for val in values:
                        if val.is_pointer and not self.is_handle(val.base_type):
                            if self.is_struct(val.base_type):
                                dump_resource_arglist += val.name
                            else:
                                dump_resource_arglist += 'in_' + val.name
                        elif self.is_custom_dump_resource_type(is_dump_resources, is_override, name, val):
                            dump_resource_arglist += self.handle_custom_dump_resource_type(is_dump_resources, is_override, name, val)
                        elif self.is_handle(val.base_type) and not val.is_pointer:
                            dump_resource_arglist += 'GetObjectInfoTable().Get' + val.base_type + "Info(" + val.name + ")"
                        else:
                            dump_resource_arglist += val.name
                        dump_resource_arglist += ', '
                    dump_resource_arglist = dump_resource_arglist[:-2]
                else:
                    dump_resource_arglist = arglist

            body += '\n'
            body += '    if (options_.dumping_resources)\n'
            body += '    {\n'
            if return_type == api_data.return_type_enum:
                body += '        resource_dumper_->Process_{}(call_info, {}, returnValue, {});\n'.format(name, dispatchfunc, dump_resource_arglist)
            else:
                body += '        resource_dumper_->Process_{}(call_info, {}, {});\n'.format(name, dispatchfunc, dump_resource_arglist)

            body += '    }\n'

        if postexpr:
            body += '\n'
            body += '\n'.join(
                ['    ' + val if val else val for val in postexpr]
            )
            body += '\n'

        body += self.generate_custom_call(name, return_type, values)

        cleanup_expr = self.generate_remove_handle_expression(name, values)
        if cleanup_expr:
            body += '    {}\n'.format(cleanup_expr)

        return body

    def generate_replay_consumer_content(self, api_data):
        """Performs C++ code generation for the replay consumer."""
        platform_type = api_data.api_class_prefix

        if not self.is_resource_dump_class():
            self.newline()
            write('template <typename T>', file=self.outFile)
            write('void InitializeOutputStruct{}(StructPointerDecoder<T> *decoder);'.format(api_data.extended_struct_func_prefix), file=self.outFile)

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
            cmddef += self.make_consumer_func_body(api_data, return_type, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)

    def generate_extended_struct_handling(self, api_data):
        var_name = 'in_' + api_data.extended_struct_variable.lower()

        self.newline()
        write(
            'void InitializeOutputStruct{}Impl(const {}* {}, {}* output_struct)'
            .format(
                api_data.extended_struct_func_prefix, api_data.base_in_struct,
                var_name, api_data.base_out_struct
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

            if self.check_skip_extended_struct_handling(struct, struct_type):
                continue

            custom_extended = self.generate_custom_extended_struct_handling(struct, struct_type)
            if custom_extended:
                write(custom_extended, file=self.outFile)
                continue

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

    def generate_extended_struct_initialize_template(self, api_data):
        var_name = 'in_' + api_data.extended_struct_variable.lower()

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

    def determine_handle_to_remove_value(self, command, values):
        """Method may be overridden."""
        if self.is_core_destroy_command(command):
            return values[0]
        else:
            return values[1]

    def generate_remove_handle_expression(self, command, values):
        """ Method may be overridden. """
        if self.needs_remove_handle_expression(command):
            value = self.determine_handle_to_remove_value(command, values)
            return 'RemoveHandle({}, &CommonObjectInfoTable::Remove{basetype}Info);'.format(
                value.name, basetype=value.base_type
            )

    def generate_custom_call(self, name, return_type, values):
        """ Method may be overridden. """
        return ''

    def make_variable_length_array_post_expr(
        self, name, value, values, length_name
    ):
        """
        Generate expressions to store the result of the count query for an array containing
        a variable number of values.
        """
        handle_value = values[0]
        api_data = self.get_api_data()
        if self.is_handle_like(values[1].base_type):
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
        if self.is_handle_like(values[1].base_type):
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

    def is_allocation_callback_type(self, struct):
        """ Method may be overridden. """
        return False

    def is_special_case_value(self, value, is_override):
        """ Method may be overridden. """
        return False

    def handle_special_case_pointer_array(self, value, is_override):
        """ Method may be overridden. """
        return ''

    def needs_pipeline_customization(self, name):
        """ Method may be overridden. """
        return False

    def handle_pipeline_customization(self, length_name):
        """ Method may be overridden. """
        return ''

    def process_other_khronos_api_handles(self, value, values):
        """ Method may be overridden. """
        return ''

    def treat_as_struct(self, value):
        """ Method may be overridden. """
        return False

    def make_body_expression(self, api_data, return_type, name, values, is_override):
        """"
        Generating expressions for mapping decoded parameters to arguments used in the API call.
        For array lengths that are stored in pointers, this will map the original parameter name
        to the temporary parameter name that was created to store the value to be provided to the
        Khronos API call.
        """
        array_lengths = dict()
        is_variable_length = False

        args = []  # List of arguments to the API call.
        preexpr = [
        ]  # Variable declarations for handle mappings, temporary output allocations, and input pointers.
        postexpr = [
        ]  # Expressions to add new handles to the handle map and delete temporary allocations.
        push_handleid_expr = ["", ""]

        for value in values:
            need_initialize_output_pnext_struct = ''
            info_type = ''
            pool_info_type = ''
            pool_alloc_type = ''
            if self.is_handle_like(value.base_type):
                info_type = '{}{}Info'.format(
                    self.get_api_prefix_from_type(value.base_type), value.base_type[2:]
                )
                if api_data.has_pool_allocations and self.is_pool_allocation(name):
                    pool_alloc_type = self.get_pool_allocation_type(values[-1])
                    pool_info_type = '{}{}Info'.format(
                        api_data.api_class_prefix, pool_alloc_type[2:]
                    )

            if value.is_pointer or value.is_array:
                full_type = value.full_type if not value.platform_full_type else value.platform_full_type
                is_input = self.is_input_pointer(value)
                is_external_object = False
                need_temp_value = True
                expr = ''

                if (
                    value.base_type in self.EXTERNAL_OBJECT_TYPES
                ) and not value.is_array:
                    # Currently, all arrays of external object types are 'void*' values that represent arrays
                    # of bytes, so we only have a pointer to an external object when the value is not an array.
                    is_external_object = True

                if (value.is_array and not value.is_dynamic):
                    # Use dynamic pointer syntax for static arrays.
                    full_type += '*'

                if is_override and not is_external_object:
                    # Overrides receive the PointerDecoder object instead of the actual Khronos pointer, so
                    # the temporary value used to hold the pointer returned by PointerDecoder::GetPointer()
                    # is not needed for most cases.
                    # Pointers to external (non-Khronos) objects are subject to separate pre/post
                    # processing, so continue to use a temporary value that is passed to the override function
                    # instead of the PointerDecoder object.
                    need_temp_value = False

                # Determine name of variable specifying the length of an array.  An override may be required to
                # replace the original length value with a temporary pointer variable.
                length_name = value.array_length
                if length_name:
                    if length_name in array_lengths:
                        # Array lengths with pointer types are received by the consumer as PointerDecoder<T> objects,
                        # so an intermediate value of type T is created to hold the value that will be provided to
                        # the Khronos API call.
                        # The 'array_lengths' dictionary contains a mapping of the original parameter name to the
                        # intermediate value name.  For this case, we need to use the intermediate value for array
                        # allocations.
                        length_name = array_lengths[length_name]
                        is_variable_length = True
                    elif '->' in length_name:
                        # Some counts are members of an allocate info struct.  Similar to the above PointerDecoder<T> case,
                        # Pointers to structures are received in a StructPointerDecoder<T> object and an intermediate value is
                        # created to store the pointer encapsulated by the object.  This case also requires using the intermediate
                        # value to access the array length.  Prepending 'in_' to the 'arraylen' value is currently sufficient to
                        # handle this case.
                        if need_temp_value:
                            length_name = 'in_' + length_name
                        else:
                            length_name = length_name.replace(
                                '->', '->GetPointer()->'
                            )

                if not need_temp_value:
                    args.append(value.name)
                else:
                    # Generate temporary variable to reference a pointer value that is encapsulated within a PointerDecoder object.
                    if is_input:
                        arg_name = 'in_' + value.name
                    else:
                        arg_name = 'out_' + value.name

                    args.append(arg_name)

                    # Assign PointerDecoder pointer to temporary variable.
                    expr = '{} {} = '.format(full_type, arg_name)

                if is_input:
                    # Assign avalue to the temporary variable based on type.  Some array variables require temporary allocations.
                    if is_external_object:
                        # If this was an array with the 'void*' type, it was encoded as an array of bytes.
                        # If not (this case), it is a pointer to an unknown object type that was encoded as a uint64_t ID value.
                        # If possible, we will map the ID to an object previously created during replay.  Otherwise, we will
                        # need to report a warning that we may have a case that replay cannot handle.
                        if value.platform_full_type:
                            expr += 'static_cast<{}>(PreProcessExternalObject({}, format::ApiCallId::ApiCall_{name}, "{name}"));'.format(
                                value.platform_full_type,
                                value.name,
                                name=name
                            )
                        else:
                            expr += 'PreProcessExternalObject({}, format::ApiCallId::ApiCall_{name}, "{name}");'.format(
                                value.name, name=name
                            )
                    elif self.is_allocation_callback_type(value.base_type):
                        if need_temp_value:
                            # The replay consumer needs to override the allocation callbacks used by the captured application.
                            expr += 'GetAllocationCallbacks({});'.format(
                                value.name
                            )
                    elif self.is_handle_like(value.base_type):
                        # We received an array of 64-bit integer IDs from the decoder.
                        expr += 'MapHandles<{info_type}>({}, {}, &CommonObjectInfoTable::Get{base_type}Info);'.format(
                            value.name,
                            length_name,
                            info_type=info_type,
                            base_type=value.base_type
                        )
                    else:
                        if need_temp_value:
                            expr += '{}->GetPointer();'.format(value.name)

                        if (value.base_type in self.structs_with_handles) or (
                            value.base_type in self.GENERIC_HANDLE_STRUCTS
                        ):
                            preexpr.append(expr)
                            if value.is_array:
                                expr = 'MapStructArrayHandles({name}->GetMetaStructPointer(), {name}->GetLength(), GetObjectInfoTable());'.format(
                                    name=value.name
                                )
                            elif self.is_special_case_value(value, is_override):
                                preexpr_special = self.handle_special_case_pointer_array(
                                    value, is_override
                                )
                                preexpr.extend(preexpr_special)
                                expr = ''

                            else:
                                expr = 'MapStructHandles({}->GetMetaStructPointer(), GetObjectInfoTable());'.format(
                                    value.name
                                )
                else:
                    # Initialize output pointer.
                    if value.is_array:
                        if is_variable_length:
                            # Store the result of an array size query.
                            postexpr.append(
                                self.make_variable_length_array_post_expr(
                                    name, value, values, length_name
                                )
                            )

                        if value.base_type in self.EXTERNAL_OBJECT_TYPES:
                            # This is effectively an array with type void*, which was encoded as an array of bytes.
                            if need_temp_value:
                                expr += '{name}->IsNull() ? nullptr : {name}->AllocateOutputData({});'.format(
                                    length_name, name=value.name
                                )
                            else:
                                expr = 'if (!{name}->IsNull()) {{ {name}->AllocateOutputData({}); }}'.format(
                                    length_name, name=value.name
                                )
                        elif self.is_handle_like(value.base_type):
                            push_handleid_expr[0] = "    PushRecaptureHandleIds({}->GetPointer(), {}->GetLength());\n".format(value.name, value.name)
                            push_handleid_expr[1] = "    ClearRecaptureHandleIds();\n"
                            # Add mappings for the newly created handles.
                            preexpr.append(
                                'if (!{paramname}->IsNull()) {{ {paramname}->SetHandleLength({}); }}'
                                .format(length_name, paramname=value.name)
                            )
                            if self.needs_pipeline_customization(name):
                                preexpr.append(
                                    self.
                                    handle_pipeline_customization(length_name)
                                )
                            if need_temp_value:
                                expr += '{}->GetHandlePointer();'.format(
                                    value.name
                                )
                                if api_data.has_pool_allocations and self.is_pool_allocation(name):
                                    postexpr.append(
                                        'AddPoolHandles<{pool_info_type}, {info_type}>({}, handle_mapping::GetPoolId({}->GetMetaStructPointer()), {paramname}->GetPointer(), {paramname}->GetLength(), {}, {}, &CommonObjectInfoTable::Get{poolbasetype}Info, &CommonObjectInfoTable::Add{basetype}Info);'
                                        .format(
                                            self.get_parent_id(api_data, value, values),
                                            values[1].name,
                                            arg_name,
                                            length_name,
                                            paramname=value.name,
                                            info_type=info_type,
                                            basetype=value.base_type,
                                            pool_info_type=pool_info_type,
                                            poolbasetype=pool_alloc_type
                                        )
                                    )
                                else:
                                    postexpr.append(
                                        'AddHandles<{}>({}, {paramname}->GetPointer(), {paramname}->GetLength(), {}, {}, &CommonObjectInfoTable::Add{basetype}Info);'
                                        .format(
                                            info_type,
                                            self.get_parent_id(api_data, value, values),
                                            arg_name,
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type
                                        )
                                    )
                            else:
                                preexpr.append(
                                    'std::vector<{}> handle_info({});'.format(
                                        info_type, length_name
                                    )
                                )
                                expr = 'for (size_t i = 0; i < {}; ++i) {{ {}->SetConsumerData(i, &handle_info[i]); }}'.format(
                                    length_name, value.name
                                )
                                if api_data.has_pool_allocations and self.is_pool_allocation(name):
                                    postexpr.append(
                                        'AddPoolHandles<{}, {}>({}, handle_mapping::GetPoolId({}->GetMetaStructPointer()), {paramname}->GetPointer(), {paramname}->GetLength(), {paramname}->GetHandlePointer(), {}, std::move(handle_info), &CommonObjectInfoTable::Get{poolbasetype}Info, &CommonObjectInfoTable::Add{basetype}Info);'
                                        .format(
                                            pool_info_type,
                                            info_type,
                                            self.get_parent_id(api_data, value, values),
                                            values[1].name,
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type,
                                            poolbasetype=pool_alloc_type
                                        )
                                    )
                                else:
                                    # additionally add an asynchronous flavour to postexpr, so both are available later
                                    if name in self.REPLAY_ASYNC_OVERRIDES:
                                        postexpr.append(
                                            'AddHandlesAsync<{}>({}, {paramname}->GetPointer(), {paramname}->GetLength(), std::move(handle_info), &CommonObjectInfoTable::Add{basetype}Info, std::move(task));'
                                            .format(
                                                info_type,
                                                self.get_parent_id(
                                                    api_data, value, values
                                                ),
                                                arg_name,
                                                length_name,
                                                paramname=value.name,
                                                basetype=value.base_type
                                            )
                                        )
                                    postexpr.append(
                                        'AddHandles<{}>({}, {paramname}->GetPointer(), {paramname}->GetLength(), {paramname}->GetHandlePointer(), {}, std::move(handle_info), &CommonObjectInfoTable::Add{basetype}Info);'
                                        .format(
                                            info_type,
                                            self.get_parent_id(api_data, value, values),
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type
                                        )
                                    )

                        elif self.is_struct(value.base_type):
                            # Generate the expression to allocate the output array.
                            alloc_expr = ''
                            if value.base_type in self.struct_type_names:
                                # If this is a struct with sType and pNext fields, we need to initialize them.
                                # TODO: recreate pNext value read from the capture file.
                                alloc_expr += 'AllocateOutputData({}, {}{{ {}, nullptr }});'.format(
                                    length_name, value.base_type,
                                    self.struct_type_names[value.base_type]
                                )
                            else:
                                alloc_expr += 'AllocateOutputData({});'.format(
                                    length_name
                                )

                            if need_temp_value:
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->{}'.format(
                                    alloc_expr, paramname=value.name
                                )
                                # If this is a struct with handles, we need to add replay mappings for the embedded handles.
                                if value.base_type in self.structs_with_handles:
                                    push_handleid_expr[0] = "    PushRecaptureStructArrayHandleIds({paramname}->GetMetaStructPointer(), {paramname}->GetLength(), this);\n".format(paramname=value.name)
                                    push_handleid_expr[1] = "    ClearRecaptureHandleIds();\n"
                                    if value.base_type in self.structs_with_handle_ptrs:
                                        preexpr.append(
                                            'SetStructArrayHandleLengths<Decoded_{}>({paramname}->GetMetaStructPointer(), {paramname}->GetLength());'
                                            .format(
                                                value.base_type,
                                                paramname=value.name
                                            )
                                        )
                                    postexpr.append(
                                        'AddStructArrayHandles<Decoded_{basetype}>({}, {paramname}->GetMetaStructPointer(), {paramname}->GetLength(), {}, {}, &GetObjectInfoTable());'
                                        .format(
                                            self.get_parent_id(api_data, value, values),
                                            arg_name,
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type
                                        )
                                    )
                            else:
                                expr += 'if (!{paramname}->IsNull()) {{ {paramname}->{} }}'.format(
                                    alloc_expr, paramname=value.name
                                )
                                # If this is a struct with handles, we need to add replay mappings for the embedded handles.
                                if value.base_type in self.structs_with_handles:
                                    push_handleid_expr[0] = "    PushRecaptureStructArrayHandleIds({paramname}->GetMetaStructPointer(), {paramname}->GetLength(), this);\n".format(paramname=value.name)
                                    push_handleid_expr[1] = "    ClearRecaptureHandleIds();\n"
                                    if value.base_type in self.structs_with_handle_ptrs:
                                        preexpr.append(
                                            'SetStructArrayHandleLengths<Decoded_{}>({paramname}->GetMetaStructPointer(), {paramname}->GetLength());'
                                            .format(
                                                value.base_type,
                                                paramname=value.name
                                            )
                                        )
                                    postexpr.append(
                                        'AddStructArrayHandles<Decoded_{basetype}>({}, {paramname}->GetMetaStructPointer(), {paramname}->GetLength(), {paramname}->GetOutputPointer(), {}, &GetObjectInfoTable());'
                                        .format(
                                            self.get_parent_id(api_data, value, values),
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type
                                        )
                                    )
                        elif value.base_type in ['char', 'wchar_t']:
                            # TODO: Does this need to be re-allocated?  The decoder should read in the proper size. But needs verification.
                            expr += '{paramname}->GetPointer();'.format(
                                length_name, paramname=value.name
                            )

                        else:
                            if need_temp_value:
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData({});'.format(
                                    length_name, paramname=value.name
                                )
                            else:
                                expr = 'if ({paramname}->IsNull()) {{ {paramname}->AllocateOutputData({}); }}'.format(
                                    length_name, paramname=value.name
                                )
                    else:
                        if is_external_object:
                            # Map the object ID to the new object
                            if value.platform_full_type:
                                expr += '{paramname}->IsNull() ? nullptr : reinterpret_cast<{}>({paramname}->AllocateOutputData(1));'.format(
                                    full_type, paramname=value.name
                                )
                                if return_type != 'void':
                                    postexpr.append(
                                        'PostProcessExternalObject(replay_result, (*{}->GetPointer()), static_cast<void*>(*{}), format::ApiCallId::ApiCall_{name}, "{name}");'
                                        .format(
                                            value.name, arg_name, name=name
                                        )
                                    )
                                else:
                                    postexpr.append(
                                        'PostProcessExternalObject({}, (*{}->GetPointer()), static_cast<void*>(*{}), format::ApiCallId::ApiCall_{name}, "{name}");'
                                        .format(
                                            api_data.return_type_success_value,
                                            value.name,
                                            arg_name,
                                            name=name
                                        )
                                    )
                            else:
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1);'.format(
                                    paramname=value.name
                                )
                                if return_type != 'void':
                                    postexpr.append(
                                        'PostProcessExternalObject(replay_result, (*{paramname}->GetPointer()), *{paramname}->GetOutputPointer(), format::ApiCallId::ApiCall_{name}, "{name}");'
                                        .format(
                                            paramname=value.name, name=name
                                        )
                                    )
                                else:
                                    postexpr.append(
                                        'PostProcessExternalObject({}, (*{paramname}->GetPointer()), *{paramname}->GetOutputPointer(), format::ApiCallId::ApiCall_{name}, "{name}");'
                                        .format(
                                            api_data.return_type_success_value,
                                            paramname=value.name,
                                            name=name
                                        )
                                    )
                        elif self.is_handle_like(value.base_type):
                            push_handleid_expr[0] = "    PushRecaptureHandleId({}->GetPointer());\n".format(value.name)
                            push_handleid_expr[1] = "    ClearRecaptureHandleIds();\n"
                            # Add mapping for the newly created handle
                            preexpr.append(
                                'if (!{paramname}->IsNull()) {{ {paramname}->SetHandleLength(1); }}'
                                .format(paramname=value.name)
                            )
                            if need_temp_value:
                                expr += '{}->GetHandlePointer();'.format(
                                    value.name
                                )
                                postexpr.append(
                                    'AddHandle<{}>({}, {}->GetPointer(), {}, &CommonObjectInfoTable::Add{}Info);'
                                    .format(
                                        info_type,
                                        self.get_parent_id(api_data, value, values),
                                        value.name, arg_name, value.base_type
                                    )
                                )
                            else:
                                preexpr.append(
                                    '{} handle_info;'.format(info_type)
                                )
                                expr = '{}->SetConsumerData(0, &handle_info);'.format(
                                    value.name
                                )
                                postexpr.append(
                                    'AddHandle<{}>({}, {paramname}->GetPointer(), {paramname}->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::Add{basetype}Info);'
                                    .format(
                                        info_type,
                                        self.get_parent_id(api_data, value, values),
                                        paramname=value.name,
                                        basetype=value.base_type
                                    )
                                )

                            # If this is a handle, but from another Khronos API, we may have to some additional work
                            other_api_handle_text = self.process_other_khronos_api_handles(
                                value, values
                            )
                            if len(other_api_handle_text) > 0:
                                postexpr.append(other_api_handle_text)
                        else:
                            if self.is_array_len(value.name, values):
                                # If this is an array length, it is an in/out parameter and we need to assign the input value.
                                array_len_expr = self.make_variable_length_array_get_count_call(
                                    return_type, name, value, values
                                )
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1, {});'.format(
                                    array_len_expr, paramname=value.name
                                )
                                # Need to store the name of the intermediate value for use with allocating the array associated with this length.
                                if need_temp_value:
                                    array_lengths[value.name
                                                  ] = '*{}'.format(arg_name)
                                else:
                                    array_lengths[
                                        value.name
                                    ] = '*{}->GetOutputPointer()'.format(
                                        value.name
                                    )
                            elif self.is_struct(value.base_type) or self.treat_as_struct(value):
                                # If this is a struct with sType and pNext fields, we need to initialize them.
                                if value.base_type in self.struct_type_names:
                                    expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1, {{ {}, nullptr }});'.format(
                                        self.struct_type_names[value.base_type],
                                        paramname=value.name
                                    )
                                    need_initialize_output_pnext_struct = value.name
                                else:
                                    expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1);'.format(
                                        paramname=value.name
                                    )

                                # If this is a struct with handles, we need to add replay mappings for the embedded handles.
                                if value.base_type in self.structs_with_handles:
                                    push_handleid_expr[0] = "    PushRecaptureStructHandleIds({}->GetMetaStructPointer(), this);\n".format(value.name)
                                    push_handleid_expr[1] = "    ClearRecaptureHandleIds();\n"
                                    if need_temp_value:
                                        if value.base_type in self.structs_with_handle_ptrs:
                                            preexpr.append(
                                                'SetStructArrayHandleLengths<Decoded_{}>({paramname}->GetMetaStructPointer(), {paramname}->GetLength());'
                                                .format(
                                                    value.base_type,
                                                    paramname=value.name
                                                )
                                            )
                                        postexpr.append(
                                            'AddStructHandles({}, {name}->GetMetaStructPointer(), {}, &GetObjectInfoTable());'
                                            .format(
                                                self.get_parent_id(
                                                    api_data, value, values
                                                ),
                                                arg_name,
                                                name=value.name,
                                                basetype=value.base_type
                                            )
                                        )
                                    else:
                                        if value.base_type in self.structs_with_handle_ptrs:
                                            preexpr.append(
                                                'SetStructHandleLengths<Decoded_{}>({paramname}->GetMetaStructPointer(), {paramname}->GetLength());'
                                                .format(
                                                    value.base_type,
                                                    paramname=value.name
                                                )
                                            )
                                        postexpr.append(
                                            'AddStructHandles<Decoded_{basetype}>({}, {name}->GetMetaStructPointer(), {name}->GetOutputPointer(), &GetObjectInfoTable());'
                                            .format(
                                                self.get_parent_id(
                                                    api_data, value, values
                                                ),
                                                name=value.name,
                                                basetype=value.base_type
                                            )
                                        )
                            else:
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1, static_cast<{}>(0));'.format(
                                    value.base_type, paramname=value.name
                                )
                if expr:
                    preexpr.append(expr)
            elif self.is_handle_like(value.base_type):
                # Handles need to be mapped.
                arg_name = 'in_' + value.name
                args.append(arg_name)
                if is_override:
                    # We use auto in case the compiler can determine if the value should be const or non-const based on the override function signature.
                    expr = 'auto {} = GetObjectInfoTable().Get{}Info({});'.format(
                        arg_name, value.base_type, value.name
                    )
                    preexpr.append(expr)

                    if self.is_special_case_value(value, True):
                        preexpr_special = self.handle_special_case_pointer_array(
                            value, is_override
                        )
                        preexpr.extend(preexpr_special)
                else:
                    expr = '{} {} = '.format(value.full_type, arg_name)
                    expr += 'MapHandle<{}>({}, &CommonObjectInfoTable::Get{}Info);'.format(
                        info_type, value.name, value.base_type
                    )
                    preexpr.append(expr)

                    if self.is_special_case_value(value, False):
                        preexpr_special = self.handle_special_case_pointer_array(
                            value, is_override
                        )
                        preexpr.extend(preexpr_special)
            elif self.is_generic_cmd_handle_value(name, value.name):
                # Handles need to be mapped.
                arg_name = 'in_' + value.name
                args.append(arg_name)
                expr = '{} {} = '.format(value.full_type, arg_name)
                expr += 'MapHandle({}, {});'.format(
                    value.name,
                    self.get_generic_cmd_handle_type_value(name, value.name)
                )
                preexpr.append(expr)
            elif self.is_function_ptr(value.base_type):
                # Function pointers are encoded as a 64-bit address value.
                # TODO: Check for cases that need to be handled.
                print(
                    "WARNING: Generating replay code for a function {} with a {} parameter that is undefined."
                    .format(name, value.base_type)
                )
            elif self.is_struct(value.base_type):
                expr = ''
                if not value.is_pointer:
                    expr += '*'
                expr += f'{value.name}.decoded_value'
                args.append(expr)

            else:
                # Only need to append the parameter name to the args list; no other expressions are necessary.
                args.append(value.name)

            if len(need_initialize_output_pnext_struct) > 0:
                preexpr.append(
                    'InitializeOutputStruct{}({});'.
                    format(api_data.extended_struct_func_prefix, need_initialize_output_pnext_struct)
                )
        return args, preexpr, postexpr, push_handleid_expr
