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

import json
import sys
from base_generator import BaseGenerator, BaseGeneratorOptions, write
from base_replay_consumer_body_generator import BaseReplayConsumerBodyGenerator


class VulkanReplayConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file replay."""

    def __init__(
        self,
        replay_overrides=None,  # Path to JSON file listing Vulkan API calls to override on replay.
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
        self.replay_overrides = replay_overrides


class VulkanReplayConsumerBodyGenerator(
    BaseReplayConsumerBodyGenerator, BaseGenerator
):
    """VulkanReplayConsumerBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanReplayConsumer class responsible for
    replaying decoded Vulkan API call parameter data.
    Generate a C++ class for Vulkan capture file replay.
    """

    # Map of Vulkan function names to override function names.  Calls to Vulkan functions in the map
    # will be replaced by the override value.
    REPLAY_OVERRIDES = {}

    # Map of pool object types associating the pool type with the allocated type and the allocated type with the pool type.
    POOL_OBJECT_ASSOCIATIONS = {
        'VkCommandBuffer': 'VkCommandPool',
        'VkDescriptorSet': 'VkDescriptorPool',
        'VkCommandPool': 'VkCommandBuffer',
        'VkDescriptorPool': 'VkDescriptorSet'
    }

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structs_with_handles = dict()
        self.structs_with_handle_ptrs = []
        # Map of struct types to associated VkStructureType.
        self.stype_values = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        if gen_opts.replay_overrides:
            self.__load_replay_overrides(gen_opts.replay_overrides)

        write(
            '#include "generated/generated_vulkan_replay_consumer.h"',
            file=self.outFile
        )
        self.newline()
        write(
            '#include "decode/custom_vulkan_struct_handle_mappers.h"',
            file=self.outFile
        )
        write(
            '#include "decode/vulkan_handle_mapping_util.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_dispatch_table.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_struct_handle_mappers.h"',
            file=self.outFile
        )
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.check_struct_member_handles(
                typename, self.structs_with_handles,
                self.structs_with_handle_ptrs
            )

            stype = self.make_structure_type_enum(typeinfo, typename)
            if stype:
                self.stype_values[typename] = stype

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        BaseReplayConsumerBodyGenerator.generate_feature(self)

    def use_instance_table(self, typename):
        """Check for dispatchable handle types associated with the instance dispatch table."""
        if typename in ['VkInstance', 'VkPhysicalDevice']:
            return True
        return False

    def get_parent_id(self, value, values):
        """Get the ID of the parent object when creating a Vulkan handle.  VkInstance is does not have a parent object."""
        if value.base_type != "VkInstance":
            return values[0].name
        return 'format::kNullHandleId'

    def is_pool_allocation(self, name):
        """Determine if an API call is perfroming a pool allocation."""
        if name.startswith('vkAllocate') and (name != 'vkAllocateMemory'):
            return True
        return False

    def make_consumer_func_body(self, return_type, name, values):
        """Return VulkanReplayConsumer class member function definition."""
        body = ''
        is_override = name in self.REPLAY_OVERRIDES

        args, preexpr, postexpr = self.make_body_expressions(
            return_type, name, values, is_override
        )
        arglist = ', '.join(args)

        dispatchfunc = ''
        if name not in ['vkCreateInstance', 'vkCreateDevice']:
            dispatchfunc = 'GetInstanceTable' if self.use_instance_table(
                values[0].base_type
            ) else 'GetDeviceTable'
            if is_override:
                dispatchfunc += '({}->handle)->{}'.format(args[0], name[2:])
            else:
                dispatchfunc += '({})->{}'.format(args[0], name[2:])

        call_expr = ''
        if is_override:
            if name in ['vkCreateInstance', 'vkCreateDevice']:
                call_expr = '{}(returnValue, {})'.format(
                    self.REPLAY_OVERRIDES[name], arglist
                )
            elif return_type == 'VkResult':
                # Override functions receive the decoded return value in addition to parameters.
                call_expr = '{}({}, returnValue, {})'.format(
                    self.REPLAY_OVERRIDES[name], dispatchfunc, arglist
                )
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
        if return_type == 'VkResult':
            body += '    VkResult replay_result = {};\n'.format(call_expr)
            body += '    CheckResult("{}", returnValue, replay_result);\n'.format(
                name
            )
        else:
            body += '    {};\n'.format(call_expr)
        if postexpr:
            body += '\n'
            body += '\n'.join(
                ['    ' + val if val else val for val in postexpr]
            )
            body += '\n'

        cleanup_expr = self.make_remove_handle_expression(name, values)
        if cleanup_expr:
            body += '    {}\n'.format(cleanup_expr)

        return body

    def make_variable_length_array_post_expr(
        self, name, value, values, length_name
    ):
        """Generate expressions to store the result of the count query for an array containing a variable number of values."""
        handle_value = values[0]
        if self.is_handle(values[1].base_type):
            handle_value = values[1]

        index_id = 'k{}Array{}'.format(handle_value.base_type[2:], name[2:])
        handle_type = '{}Info'.format(handle_value.base_type[2:])
        info_func = '&VulkanObjectInfoTable::Get{}Info'.format(
            handle_value.base_type[2:]
        )

        return 'if ({}->IsNull()) {{ SetOutputArrayCount<{}>({}, {}, {}, {}); }}'.format(
            value.name, handle_type, handle_value.name, index_id, length_name,
            info_func
        )

    def make_variable_length_array_get_count_call(
        self, return_type, name, value, values
    ):
        """Generate expressions to call a function that retrieves the count of an array containing a variable number of values."""
        return_value = 'VK_SUCCESS'
        if (return_type == 'VkResult'):
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
        handle_type = '{}Info'.format(handle_value.base_type[2:])
        info_func = '&VulkanObjectInfoTable::Get{}Info'.format(
            handle_value.base_type[2:]
        )

        return 'GetOutputArrayCount<{}, {}>("{}", {}, {}, {}, {}, {}, {})'.format(
            value.base_type, handle_type, name, return_value,
            handle_value.name, index_id, value.name, array_name, info_func
        )

    def make_body_expressions(self, return_type, name, values, is_override):
        """"Generating expressions for mapping decoded parameters to arguments used in the API call.
        For array lengths that are stored in pointers, this will map the original parameter name
        to the temporary parameter name that was created to store the value to be provided to the Vulkan API call.
        """
        array_lengths = dict()
        is_variable_length = False

        args = []  # List of arguments to the API call.
        preexpr = [
        ]  # Variable declarations for handle mappings, temporary output allocations, and input pointers.
        postexpr = [
        ]  # Expressions to add new handles to the handle map and delete temporary allocations.

        for value in values:
            if value.is_pointer or value.is_array:
                full_type = value.full_type if not value.platform_full_type else value.platform_full_type
                is_input = self.is_input_pointer(value)
                is_extenal_object = False
                need_temp_value = True
                expr = ''

                if (
                    value.base_type in self.EXTERNAL_OBJECT_TYPES
                ) and not value.is_array:
                    # Currently, all arrays of external object types are 'void*' values that represent arrays of bytes, so we only have a
                    # pointer to an external object when the value is not an array.
                    is_extenal_object = True

                if (value.is_array and not value.is_dynamic):
                    # Use dynamic pointer syntax for static arrays.
                    full_type += '*'

                if is_override and not is_extenal_object:
                    # Overrides receive the PointerDecoder object instead of the actual Vulkan pointer, so the temporary value used to hold the pointer returned by
                    # PointerDecoder::GetPointer() is not needed for most cases.  Pointers to external (non-Vulkan) objects are subject to separate pre/post
                    # processing, so continue to use a temporary value that is passed to the override function instead of the PointerDecoder object.
                    need_temp_value = False

                # Determine name of variable specifying the length of an array.  An override may be required to
                # replace the original length value with a temporary pointer variable.
                length_name = value.array_length
                if length_name:
                    if length_name in array_lengths:
                        # Array lengths with pointer types are received by the consumer as PointerDecoder<T> objects, so
                        # an intermediate value of type T is created to hold the value that will be provided to the Vulkan
                        # API call.  The 'array_lengths' dictionary contains a mapping of the original parameter name to the
                        # intermediate value name.  For this case, we need to use the intermediate value for array allocations.
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
                    if is_extenal_object:
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
                    elif value.base_type == 'VkAllocationCallbacks':
                        if need_temp_value:
                            # The replay consumer needs to override the allocation callbacks used by the captured application.
                            expr += 'GetAllocationCallbacks({});'.format(
                                value.name
                            )
                    elif self.is_handle(value.base_type):
                        # We received an array of 64-bit integer IDs from the decoder.
                        expr += 'MapHandles<{type}Info>({}, {}, &VulkanObjectInfoTable::Get{type}Info);'.format(
                            value.name, length_name, type=value.base_type[2:]
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
                        elif self.is_handle(value.base_type):
                            # Add mappings for the newly created handles.
                            preexpr.append(
                                'if (!{paramname}->IsNull()) {{ {paramname}->SetHandleLength({}); }}'
                                .format(length_name, paramname=value.name)
                            )
                            if need_temp_value:
                                expr += '{}->GetHandlePointer();'.format(
                                    value.name
                                )
                                if self.is_pool_allocation(name):
                                    postexpr.append(
                                        'AddPoolHandles<{pooltype}Info, {basetype}Info>({}, handle_mapping::GetPoolId({}->GetMetaStructPointer()), {paramname}->GetPointer(), {paramname}->GetLength(), {}, {}, &VulkanObjectInfoTable::Get{pooltype}Info, &VulkanObjectInfoTable::Add{basetype}Info);'
                                        .format(
                                            self.get_parent_id(value, values),
                                            values[1].name,
                                            arg_name,
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type[2:],
                                            pooltype=self.
                                            POOL_OBJECT_ASSOCIATIONS[
                                                value.base_type][2:]
                                        )
                                    )
                                else:
                                    postexpr.append(
                                        'AddHandles<{basetype}Info>({}, {paramname}->GetPointer(), {paramname}->GetLength(), {}, {}, &VulkanObjectInfoTable::Add{basetype}Info);'
                                        .format(
                                            self.get_parent_id(value, values),
                                            arg_name,
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type[2:]
                                        )
                                    )
                            else:
                                preexpr.append(
                                    'std::vector<{}Info> handle_info({});'.
                                    format(value.base_type[2:], length_name)
                                )
                                expr = 'for (size_t i = 0; i < {}; ++i) {{ {}->SetConsumerData(i, &handle_info[i]); }}'.format(
                                    length_name, value.name
                                )
                                if self.is_pool_allocation(name):
                                    postexpr.append(
                                        'AddPoolHandles<{pooltype}Info, {basetype}Info>({}, handle_mapping::GetPoolId({}->GetMetaStructPointer()), {paramname}->GetPointer(), {paramname}->GetLength(), {paramname}->GetHandlePointer(), {}, std::move(handle_info), &VulkanObjectInfoTable::Get{pooltype}Info, &VulkanObjectInfoTable::Add{basetype}Info);'
                                        .format(
                                            self.get_parent_id(value, values),
                                            values[1].name,
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type[2:],
                                            pooltype=self.
                                            POOL_OBJECT_ASSOCIATIONS[
                                                value.base_type][2:]
                                        )
                                    )
                                else:
                                    postexpr.append(
                                        'AddHandles<{basetype}Info>({}, {paramname}->GetPointer(), {paramname}->GetLength(), {paramname}->GetHandlePointer(), {}, std::move(handle_info), &VulkanObjectInfoTable::Add{basetype}Info);'
                                        .format(
                                            self.get_parent_id(value, values),
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type[2:]
                                        )
                                    )

                        elif self.is_struct(value.base_type):
                            # Generate the expression to allocate the output array.
                            alloc_expr = ''
                            if value.base_type in self.stype_values:
                                # If this is a struct with sType and pNext fields, we need to initialize them.
                                # TODO: recreate pNext value read from the capture file.
                                alloc_expr += 'AllocateOutputData({}, {}{{ {}, nullptr }});'.format(
                                    length_name, value.base_type,
                                    self.stype_values[value.base_type]
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
                                            self.get_parent_id(value, values),
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
                                            self.get_parent_id(value, values),
                                            length_name,
                                            paramname=value.name,
                                            basetype=value.base_type
                                        )
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
                        if is_extenal_object:
                            # Map the object ID to the new object
                            if value.platform_full_type:
                                expr += '{paramname}->IsNull() ? nullptr : reinterpret_cast<{}>({paramname}->AllocateOutputData(1));'.format(
                                    full_type, paramname=value.name
                                )
                                if return_type != 'void':
                                    postexpr.append(
                                        'PostProcessExternalObject(replay_result, (*{}->GetPointer()), static_cast<void*>(*{}), format::ApiCallId::ApiCall_{name}, "{name}");'
                                        .format(value.name, arg_name, name=name)
                                    )
                                else:
                                    postexpr.append(
                                        'PostProcessExternalObject(VK_SUCCESS, (*{}->GetPointer()), static_cast<void*>(*{}), format::ApiCallId::ApiCall_{name}, "{name}");'
                                        .format(value.name, arg_name, name=name)
                                    )                                    
                            else:
                                expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1);'.format(
                                    paramname=value.name
                                )
                                if return_type != 'void':
                                    postexpr.append(
                                        'PostProcessExternalObject(replay_result, (*{paramname}->GetPointer()), *{paramname}->GetOutputPointer(), format::ApiCallId::ApiCall_{name}, "{name}");'
                                        .format(paramname=value.name, name=name)
                                    )
                                else:
                                    postexpr.append(
                                        'PostProcessExternalObject(VK_SUCCESS, (*{paramname}->GetPointer()), *{paramname}->GetOutputPointer(), format::ApiCallId::ApiCall_{name}, "{name}");'
                                        .format(paramname=value.name, name=name)
                                    )                                    
                        elif self.is_handle(value.base_type):
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
                                    'AddHandle<{basetype}Info>({}, {}->GetPointer(), {}, &VulkanObjectInfoTable::Add{basetype}Info);'
                                    .format(
                                        self.get_parent_id(value, values),
                                        value.name,
                                        arg_name,
                                        basetype=value.base_type[2:]
                                    )
                                )
                            else:
                                preexpr.append(
                                    '{}Info handle_info;'.format(
                                        value.base_type[2:]
                                    )
                                )
                                expr = '{}->SetConsumerData(0, &handle_info);'.format(
                                    value.name
                                )
                                postexpr.append(
                                    'AddHandle<{basetype}Info>({}, {paramname}->GetPointer(), {paramname}->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::Add{basetype}Info);'
                                    .format(
                                        self.get_parent_id(value, values),
                                        paramname=value.name,
                                        basetype=value.base_type[2:]
                                    )
                                )
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
                            elif self.is_struct(value.base_type):
                                # If this is a struct with sType and pNext fields, we need to initialize them.
                                if value.base_type in self.stype_values:
                                    # TODO: recreate pNext value read from the capture file; pNext is currently null.
                                    expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1, {{ {}, nullptr }});'.format(
                                        self.stype_values[value.base_type],
                                        paramname=value.name
                                    )
                                else:
                                    expr += '{paramname}->IsNull() ? nullptr : {paramname}->AllocateOutputData(1);'.format(
                                        paramname=value.name
                                    )

                                # If this is a struct with handles, we need to add replay mappings for the embedded handles.
                                if value.base_type in self.structs_with_handles:
                                    if need_temp_value:
                                        if value.base_type in self.structs_with_handle_ptrs:
                                            preexpr.append(
                                                'SetStructHandleLengths<Decoded_{}>({paramname}->GetMetaStructPointer(), {paramname}->GetLength());'
                                                .format(
                                                    value.base_type,
                                                    paramname=value.name
                                                )
                                            )
                                        postexpr.append(
                                            'AddStructHandles<Decoded_{basetype}>({}, {name}->GetMetaStructPointer(), {}, &GetObjectInfoTable());'
                                            .format(
                                                self.get_parent_id(
                                                    value, values
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
                                                    value, values
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
            elif self.is_handle(value.base_type):
                # Handles need to be mapped.
                arg_name = 'in_' + value.name
                args.append(arg_name)
                if is_override:
                    # We use auto in case the compiler can determine if the value should be const or non-const based on the override function signature.
                    expr = 'auto {} = GetObjectInfoTable().Get{}Info({});'.format(
                        arg_name, value.base_type[2:], value.name
                    )
                    preexpr.append(expr)
                else:
                    expr = '{} {} = '.format(value.full_type, arg_name)
                    expr += 'MapHandle<{type}Info>({}, &VulkanObjectInfoTable::Get{type}Info);'.format(
                        value.name, type=value.base_type[2:]
                    )
                    preexpr.append(expr)

                    # If surface was not created, need to automatically ignore for non-overrides queries
                    # Swapchain also need to check if a dummy swapchain was created instead
                    if value.name == "surface":
                        expr = 'if ({} == VK_NULL_HANDLE) {{ return; }}'.format(
                            arg_name
                        )
                        preexpr.append(expr)
                    elif value.name == "swapchain":
                        expr = 'if (GetObjectInfoTable().Get{}Info({})->surface == VK_NULL_HANDLE) {{ return; }}'.format(
                            value.base_type[2:], value.name
                        )
                        preexpr.append(expr)
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
            else:
                # Only need to append the parameter name to the args list; no other expressions are necessary.
                args.append(value.name)
        return args, preexpr, postexpr

    def make_remove_handle_expression(self, name, values):
        expr = None
        if name.startswith('vkDestroy') or (name == 'vkFreeMemory'):
            # For functions starting with 'vkDestroy' and vkFreeMemory, the handle being destroyed/freed is the second parameter, except for.
            # vkDestroyInstance and vkDestroyDevice, where there is no parent object and the handle being destroyed is the first parameter.
            value = values[0] if name in [
                'vkDestroyInstance', 'vkDestroyDevice'
            ] else values[1]
            if value.base_type not in self.POOL_OBJECT_ASSOCIATIONS:
                expr = 'RemoveHandle({}, &VulkanObjectInfoTable::Remove{basetype}Info);'.format(
                    value.name, basetype=value.base_type[2:]
                )
            else:
                # Pools require special case processing to cleanup objects allocated from them.
                expr = 'RemovePoolHandle<{basetype}Info>({}, &VulkanObjectInfoTable::Get{basetype}Info, &VulkanObjectInfoTable::Remove{basetype}Info, &VulkanObjectInfoTable::Remove{}Info);'.format(
                    value.name,
                    self.POOL_OBJECT_ASSOCIATIONS[value.base_type][2:],
                    basetype=value.base_type[2:]
                )
        elif name.startswith('vkFree'):
            # For pool based vkFreeCommandBuffers and vkFreeDescriptorSets, the pool handle is the second parameter, the array count is the third parameter and the array of handles to free is the fourth parameter.
            value = values[3]
            expr = 'RemovePoolHandles<{pooltype}Info, {basetype}Info>({}, {}, {}, &VulkanObjectInfoTable::Get{pooltype}Info, &VulkanObjectInfoTable::Remove{basetype}Info);'.format(
                values[1].name,
                value.name,
                values[2].name,
                basetype=value.base_type[2:],
                pooltype=self.POOL_OBJECT_ASSOCIATIONS[value.base_type][2:]
            )

        return expr

    def __load_replay_overrides(self, filename):
        overrides = json.loads(open(filename, 'r').read())
        self.REPLAY_OVERRIDES = overrides['functions']
