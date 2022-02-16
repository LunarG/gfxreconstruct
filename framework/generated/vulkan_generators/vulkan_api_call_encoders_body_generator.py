#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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
from base_generator import BaseGenerator, BaseGeneratorOptions, ValueInfo, json, write


class VulkanApiCallEncodersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for Vulkan API parameter encoding."""

    def __init__(
        self,
        capture_overrides=None,  # Path to JSON file listing Vulkan API calls to override on capture.
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
        self.capture_overrides = capture_overrides


class VulkanApiCallEncodersBodyGenerator(BaseGenerator):
    """VulkanApiCallEncodersBodyGenerator - subclass of BaseGenerator.
    Generates C++ functions responsible for encoding Vulkan API call
    parameter data.
    Generate C++ functions for Vulkan API parameter encoding.
    """

    # Map of Vulkan function names to override function names.  Calls to Vulkan functions in the map
    # will be replaced by the override value.
    CAPTURE_OVERRIDES = {}

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

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        if gen_opts.capture_overrides:
            self.__load_capture_overrides(gen_opts.capture_overrides)

        write(
            '#include "generated/generated_vulkan_api_call_encoders.h"',
            file=self.outFile
        )
        self.newline()
        write(
            '#include "encode/custom_vulkan_encoder_commands.h"',
            file=self.outFile
        )
        write(
            '#include "encode/custom_vulkan_array_size_2d.h"',
            file=self.outFile
        )
        write('#include "encode/parameter_encoder.h"', file=self.outFile)
        write('#include "encode/struct_pointer_encoder.h"', file=self.outFile)
        write('#include "encode/vulkan_capture_manager.h"', file=self.outFile)
        write(
            '#include "encode/vulkan_handle_wrapper_util.h"',
            file=self.outFile
        )
        write('#include "encode/vulkan_handle_wrappers.h"', file=self.outFile)
        write('#include "format/api_call_id.h"', file=self.outFile)
        write(
            '#include "generated/generated_vulkan_command_buffer_util.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_vulkan_struct_handle_wrappers.h"',
            file=self.outFile
        )
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.check_struct_member_handles(
                typename, self.structs_with_handles
            )

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        first = True
        for cmd in self.get_filtered_cmd_names():
            info = self.feature_cmd_params[cmd]
            return_type = info[0]
            proto = info[1]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.make_cmd_decl(proto, values)
            cmddef += '{\n'
            cmddef += self.make_cmd_body(return_type, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)
            first = False

    def make_cmd_decl(self, proto, values):
        """Generate function declaration for a command."""
        param_decls = []

        for value in values:
            value_name = value.name
            value_type = value.full_type if not value.platform_full_type else value.platform_full_type

            if value.is_array and not value.is_dynamic:
                value_name += '[{}]'.format(value.array_capacity)

            param_decl = self.make_aligned_param_decl(
                value_type, value_name, self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            param_decls.append(param_decl)

        if param_decls:
            return '{}(\n{})\n'.format(proto, ',\n'.join(param_decls))

        return '{}()\n'.format(proto)

    def use_instance_table(self, typename):
        """Check for dispatchable handle types associated with the instance dispatch table."""
        if typename in ['VkInstance', 'VkPhysicalDevice']:
            return True
        return False

    def make_layer_dispatch_call(self, name, values, arg_list):
        """Generate the layer dispatch call invocation."""
        dispatchfunc = 'GetInstanceTable' if self.use_instance_table(
            values[0].base_type
        ) else 'GetDeviceTable'
        return '{}({})->{}({})'.format(
            dispatchfunc, values[0].name, name[2:], arg_list
        )

    def make_cmd_body(self, return_type, name, values):
        """Command definition."""
        indent = ' ' * self.INDENT_SIZE
        is_override = name in self.CAPTURE_OVERRIDES
        encode_after = False
        omit_output_param = None
        has_outputs = self.has_outputs(return_type, values)
        arg_list = self.make_arg_list(values)

        body = ''

        body += indent + 'auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();\n'
        body += '\n'

        if has_outputs or (return_type and return_type != 'void'):
            encode_after = True

        if has_outputs and (return_type and return_type != 'void'):
            omit_output_param = 'omit_output_data'
            body += indent + 'bool omit_output_data = false;\n'
            body += '\n'

        body += indent + 'CustomEncoderPreCall<format::ApiCallId::ApiCall_{}>::Dispatch(VulkanCaptureManager::Get(), {});\n'.format(
            name, arg_list
        )

        if not encode_after:
            body += self.make_parameter_encoding(
                name, values, return_type, indent, omit_output_param
            )

        body += '\n'

        if is_override:
            # Capture overrides simply call the override function without handle unwrap/wrap
            # Construct the function call to dispatch to the next layer.
            call_expr = '{}({})'.format(
                self.CAPTURE_OVERRIDES[name], self.make_arg_list(values)
            )
            if return_type and return_type != 'void':
                body += indent + '{} result = {};\n'.format(
                    return_type, call_expr
                )
            else:
                body += indent + '{};\n'.format(call_expr)

            if has_outputs and (return_type and return_type != 'void'):
                body += indent + 'if (result < 0)\n'
                body += indent + '{\n'
                body += indent + '    omit_output_data = true;\n'
                body += indent + '}\n'
        else:
            # Check for handles that need unwrapping.
            unwrap_expr, unwrapped_arg_list, need_unwrap_memory = self.make_handle_unwrapping(
                name, values, indent
            )
            if unwrap_expr:
                if need_unwrap_memory:
                    body += indent + 'auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();\n'
                body += unwrap_expr
                body += '\n'

            # Construct the function call to dispatch to the next layer.
            call_expr = self.make_layer_dispatch_call(
                name, values, unwrapped_arg_list
            )
            if return_type and return_type != 'void':
                body += indent + '{} result = {};\n'.format(
                    return_type, call_expr
                )
            else:
                body += indent + '{};\n'.format(call_expr)

            # Wrap newly created handles.
            wrap_expr = self.make_handle_wrapping(values, indent)
            if wrap_expr:
                body += '\n'
                if return_type and return_type != 'void':
                    body += indent + 'if (result >= 0)\n'
                    body += indent + '{\n'
                    body += '    ' + wrap_expr
                    body += indent + '}\n'
                    if has_outputs:
                        body += indent + 'else\n'
                        body += indent + '{\n'
                        body += indent + '    omit_output_data = true;\n'
                        body += indent + '}\n'
                else:
                    body += wrap_expr
            elif has_outputs and (return_type and return_type != 'void'):
                body += indent + 'if (result < 0)\n'
                body += indent + '{\n'
                body += indent + '    omit_output_data = true;\n'
                body += indent + '}\n'

        if encode_after:
            body += self.make_parameter_encoding(
                name, values, return_type, indent, omit_output_param
            )

        body += '\n'
        if return_type and return_type != 'void':
            body += '    CustomEncoderPostCall<format::ApiCallId::ApiCall_{}>::Dispatch(VulkanCaptureManager::Get(), result, {});\n'.format(
                name, arg_list
            )
        else:
            body += '    CustomEncoderPostCall<format::ApiCallId::ApiCall_{}>::Dispatch(VulkanCaptureManager::Get(), {});\n'.format(
                name, arg_list
            )

        cleanup_expr = self.make_handle_cleanup(name, values, indent)
        if cleanup_expr:
            body += '\n'
            body += cleanup_expr

        if return_type and return_type != 'void':
            body += '\n'
            body += '    return result;\n'

        return body

    def make_parameter_encoding(
        self, name, values, return_type, indent, omit_output_param
    ):
        body = '\n'
        body += indent + self.make_begin_api_call(name, values)
        body += indent + 'if (encoder)\n'
        body += indent + '{\n'
        indent += ' ' * self.INDENT_SIZE

        for value in values:
            method_call = self.make_encoder_method_call(
                name, value, values, '', omit_output_param
            )
            body += indent + '{};\n'.format(method_call)

        if return_type and return_type != 'void':
            method_call = self.make_encoder_method_call(
                name, ValueInfo('result', return_type, return_type), [], ''
            )
            body += indent + '{};\n'.format(method_call)

        # Determine the appropriate end call: Create handle call, destroy handle call, or general call.
        body += indent + self.make_end_api_call(name, values, return_type)
        indent = indent[0:-self.INDENT_SIZE]
        body += indent + '}\n'
        return body

    def make_begin_api_call(self, name, values):
        if name.startswith('vkCreate') or name.startswith(
            'vkAllocate'
        ) or name.startswith('vkDestroy') or name.startswith(
            'vkFree'
        ) or self.retrieves_handles(values) or (
            values[0].base_type == 'VkCommandBuffer'
        ) or (name == 'vkReleasePerformanceConfigurationINTEL'):
            return 'auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_{});\n'.format(
                name
            )
        else:
            return 'auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_{});\n'.format(
                name
            )

    def get_struct_handle_member_info(self, members):
        member_handle_type = None
        member_handle_name = None
        member_array_length = None

        for member in members:
            if self.is_handle(member.base_type):
                member_handle_type = member.base_type
                member_handle_name = member.name
                if member.is_array:
                    member_array_length = member.array_length
                break
            elif self.is_struct(member.base_type):
                # This can't handle the case where 'member' is an array of structs
                member_handle_type, member_handle_name, member_array_length = self.get_struct_handle_member_info(
                    self.structs_with_handles[member.base_type]
                )
                member_handle_name = '{}.{}'.format(
                    member.name, member_handle_name
                )

        return member_handle_type, member_handle_name, member_array_length

    def make_end_api_call(self, name, values, return_type):
        decl = 'VulkanCaptureManager::Get()->'

        if name.startswith('vkCreate') or name.startswith(
            'vkAllocate'
        ) or self.retrieves_handles(values):
            # The handle is the last parameter.
            handle = values[-1]
            parent_handle = values[0] if self.is_handle(
                values[0].base_type
            ) else None

            #  Search for the create info struct
            info_base_type = 'void'
            info_name = 'nullptr'
            for value in values:
                if (
                    ('CreateInfo' in value.base_type)
                    or ('AllocateInfo' in value.base_type)
                ):
                    info_base_type = value.base_type
                    info_name = value.name
                    # Confirm array counts match
                    if value.is_array and (
                        handle.array_length != value.array_length
                    ):
                        print(
                            'WARNING: {} has separate array counts for create info structures ({}) and handles ({})'
                            .format(name, value.array_length, count)
                        )

            return_value = 'VK_SUCCESS'
            if return_type == 'VkResult':
                return_value = 'result'

            if handle.is_array:
                length_name = self.make_array_length_expression(handle)

                if 'pAllocateInfo->' in length_name:
                    # This is a pool allocation call, which receives one allocate info structure that is shared by all object being allocated.
                    decl += 'EndPoolCreateApiCallCapture<{}, {}Wrapper, {}>({}, {}, {}, {}, {})'.format(
                        parent_handle.base_type, handle.base_type[2:],
                        info_base_type, return_value, parent_handle.name,
                        length_name, handle.name, info_name
                    )
                else:
                    # This is a multi-object creation call (e.g. pipeline creation, or swapchain image retrieval), which receives
                    # separate create info structures for each object being created. Many multi-object creation calls receive a
                    # handle as their second parameter, which is of interest to the state tracker (e.g. the VkPipelineCache handle
                    # from vkCreateGraphicsPipelines or the vkSwapchain handle from vkGetSwapchainImagesKHR). For api calls that do
                    # not receive a handle as the second parameter (e.g. vkEnumeratePhysicalDevices), the handle type is set to 'void*'.
                    if handle.base_type in self.struct_names:
                        # "handle" is actually a struct with embedded handles
                        unwrap_handle_def = 'nullptr'
                        member_handle_type, member_handle_name, member_array_length = self.get_struct_handle_member_info(
                            self.structs_with_handles[handle.base_type]
                        )

                        if not member_array_length:
                            unwrap_handle_def = '[]({}* handle_struct)->{wrapper}Wrapper* {{ return reinterpret_cast<{wrapper}Wrapper*>(handle_struct->{}); }}'.format(
                                handle.base_type,
                                member_handle_name,
                                wrapper=member_handle_type[2:]
                            )

                        decl += 'EndStructGroupCreateApiCallCapture<{}, {}Wrapper, {}>({}, {}, {}, {}, {})'.format(
                            parent_handle.base_type, member_handle_type[2:],
                            handle.base_type, return_value, parent_handle.name,
                            length_name, handle.name, unwrap_handle_def
                        )
                    elif self.is_handle(values[1].base_type):
                        second_handle = values[1]
                        decl += 'EndGroupCreateApiCallCapture<{}, {}, {}Wrapper, {}>({}, {}, {}, {}, {}, {})'.format(
                            parent_handle.base_type, second_handle.base_type,
                            handle.base_type[2:], info_base_type, return_value,
                            parent_handle.name, second_handle.name,
                            length_name, handle.name, info_name
                        )
                    else:
                        decl += 'EndGroupCreateApiCallCapture<{}, void*, {}Wrapper, {}>({}, {}, nullptr, {}, {}, {})'.format(
                            parent_handle.base_type, handle.base_type[2:],
                            info_base_type, return_value, parent_handle.name,
                            length_name, handle.name, info_name
                        )

            else:
                if handle.base_type in self.struct_names:
                    # TODO: No cases in current Vulkan spec of handle inside non-array output structure
                    raise NotImplementedError
                elif parent_handle:
                    decl += 'EndCreateApiCallCapture<{}, {}Wrapper, {}>({}, {}, {}, {})'.format(
                        parent_handle.base_type, handle.base_type[2:],
                        info_base_type, return_value, parent_handle.name,
                        handle.name, info_name
                    )
                else:
                    # Instance creation does not have a parent handle; set the parent handle type to 'void*'.
                    decl += 'EndCreateApiCallCapture<const void*, {}Wrapper, {}>({}, nullptr, {}, {})'.format(
                        handle.base_type[2:], info_base_type, return_value,
                        handle.name, info_name
                    )

        elif name.startswith('vkDestroy') or name.startswith('vkFree') or (
            name == 'vkReleasePerformanceConfigurationINTEL'
        ):
            handle = None
            if name in ['vkDestroyInstance', 'vkDestroyDevice']:
                # Instance/device destroy calls are special case where the target handle is the first parameter
                handle = values[0]
            else:
                # The destroy target is the second parameter, except for pool based allocations where it is the last parameter.
                handle = values[1]
                if ("Pool" in handle.base_type) and name.startswith('vkFree'):
                    handle = values[3]

            if handle.is_array:
                decl += 'EndDestroyApiCallCapture<{}Wrapper>({}, {})'.format(
                    handle.base_type[2:], handle.array_length, handle.name
                )
            else:
                decl += 'EndDestroyApiCallCapture<{}Wrapper>({})'.format(
                    handle.base_type[2:], handle.name
                )

        elif values[0].base_type == 'VkCommandBuffer':
            get_handles_expr = self.make_get_command_handles_expr(
                name, values[1:]
            )
            if get_handles_expr:
                decl += 'EndCommandApiCallCapture({}, {})'.format(
                    values[0].name, get_handles_expr
                )
            else:
                decl += 'EndCommandApiCallCapture({})'.format(values[0].name)
        else:
            decl += 'EndApiCallCapture()'

        decl += ';\n'
        return decl

    def make_handle_wrapping(self, values, indent):
        expr = ''
        for value in values:
            if self.is_output_parameter(value) and (
                self.is_handle(value.base_type) or (
                    self.is_struct(value.base_type) and
                    (value.base_type in self.structs_with_handles)
                )
            ):
                # The VkInstance handle does not have parent, so the 'unused'
                # values will be provided to the wrapper creation function.
                parent_type = 'NoParentWrapper'
                parent_value = 'NoParentWrapper::kHandleValue'
                if self.is_handle(values[0].base_type):
                    parent_type = values[0].base_type[2:] + 'Wrapper'
                    parent_value = values[0].name

                # Some handles have two parent handles, such as swapchain images and display modes,
                # or command buffers and descriptor sets allocated from pools.
                co_parent_type = 'NoParentWrapper'
                co_parent_value = 'NoParentWrapper::kHandleValue'
                if self.is_handle(values[1].base_type):
                    co_parent_type = values[1].base_type[2:] + 'Wrapper'
                    co_parent_value = values[1].name
                elif values[1].base_type.endswith(
                    'AllocateInfo'
                ) and value.is_array and ('->' in value.array_length):
                    # An array of handles with length specified by an AllocateInfo structure (there is a -> in the length name) is a pool allocation.
                    # Extract the pool handle from the AllocateInfo structure, which is currently the first and only handle member.
                    members = self.structs_with_handles[values[1].base_type]
                    for member in members:
                        if self.is_handle(member.base_type):
                            co_parent_type = member.base_type[2:] + 'Wrapper'
                            co_parent_value = values[
                                1].name + '->' + member.name
                            break

                if value.is_array:
                    length_name = value.array_length
                    for len in values:
                        if (len.name == length_name) and len.is_pointer:
                            length_name = '({name} != nullptr) ? (*{name}) : 0'.format(
                                name=length_name
                            )
                            break
                    if self.is_handle(value.base_type):
                        expr += indent + 'CreateWrappedHandles<{}, {}, {}Wrapper>({}, {}, {}, {}, VulkanCaptureManager::GetUniqueId);\n'.format(
                            parent_type, co_parent_type, value.base_type[2:],
                            parent_value, co_parent_value, value.name,
                            length_name
                        )
                    elif self.is_struct(
                        value.base_type
                    ) and (value.base_type in self.structs_with_handles):
                        expr += indent + 'CreateWrappedStructArrayHandles<{}, {}, {}>({}, {}, {}, {}, VulkanCaptureManager::GetUniqueId);\n'.format(
                            parent_type, co_parent_type, value.base_type,
                            parent_value, co_parent_value, value.name,
                            length_name
                        )
                else:
                    if self.is_handle(value.base_type):
                        expr += indent + 'CreateWrappedHandle<{}, {}, {}Wrapper>({}, {}, {}, VulkanCaptureManager::GetUniqueId);\n'.format(
                            parent_type, co_parent_type, value.base_type[2:],
                            parent_value, co_parent_value, value.name
                        )
                    elif self.is_struct(
                        value.base_type
                    ) and (value.base_type in self.structs_with_handles):
                        expr += indent + 'CreateWrappedStructHandles<{}, {}>({}, {}, {}, VulkanCaptureManager::GetUniqueId);\n'.format(
                            parent_type, co_parent_type, parent_value,
                            co_parent_value, value.name
                        )
        return expr

    def make_handle_unwrapping(self, name, values, indent):
        args = []
        expr = ''
        need_unwrap_memory = False
        for value in values:
            arg_name = value.name
            if value.is_pointer or value.is_array:
                if self.is_input_pointer(value):
                    if self.is_handle(value.base_type):
                        need_unwrap_memory = True
                        arg_name += '_unwrapped'
                        array_length = value.array_length if value.is_array else 1  # At this time, all pointer unwrap cases are arrays
                        expr += indent + '{} {name}_unwrapped = UnwrapHandles<{}>({name}, {}, handle_unwrap_memory);\n'.format(
                            value.full_type,
                            value.base_type,
                            array_length,
                            name=value.name
                        )
                    elif (value.base_type in self.structs_with_handles) or (
                        value.base_type in self.GENERIC_HANDLE_STRUCTS
                    ):
                        need_unwrap_memory = True
                        arg_name += '_unwrapped'
                        if value.is_array:
                            expr += indent + '{} {name}_unwrapped = UnwrapStructArrayHandles({name}, {}, handle_unwrap_memory);\n'.format(
                                value.full_type,
                                value.array_length,
                                name=value.name
                            )
                        else:
                            expr += indent + '{} {name}_unwrapped = UnwrapStructPtrHandles({name}, handle_unwrap_memory);\n'.format(
                                value.full_type, name=value.name
                            )
            elif self.is_handle(value.base_type):
                arg_name += '_unwrapped'
                expr += indent + '{type} {name}_unwrapped = GetWrappedHandle<{type}>({name});\n'.format(
                    type=value.base_type, name=value.name
                )
            elif self.is_generic_cmd_handle_value(name, value.name):
                arg_name += '_unwrapped'
                expr += indent + '{type} {name}_unwrapped = GetWrappedHandle({name}, {type_value});\n'.format(
                    type=value.base_type,
                    name=value.name,
                    type_value=self.
                    get_generic_cmd_handle_type_value(name, value.name)
                )
            args.append(arg_name)
        return expr, ', '.join(args), need_unwrap_memory

    def make_handle_cleanup(self, name, values, indent):
        expr = ''
        if name.startswith('vkDestroy') or name.startswith('vkFree') or (
            name == 'vkReleasePerformanceConfigurationINTEL'
        ):
            handle = None
            if name in ['vkDestroyInstance', 'vkDestroyDevice']:
                # Instance/device destroy calls are special case where the target handle is the first parameter
                handle = values[0]
            else:
                # The destroy target is the second parameter, except for pool based allocations where it is the last parameter.
                handle = values[1]
                if ("Pool" in handle.base_type) and name.startswith('vkFree'):
                    handle = values[3]

            if handle.is_array:
                expr += indent + 'DestroyWrappedHandles<{}Wrapper>({}, {});\n'.format(
                    handle.base_type[2:], handle.name, handle.array_length
                )
            else:
                expr += indent + 'DestroyWrappedHandle<{}Wrapper>({});\n'.format(
                    handle.base_type[2:], handle.name
                )
        return expr

    def get_param_list_handles(self, values):
        """Create list of parameters that have handle types or are structs that contain handles."""
        handles = []
        for value in values:
            if self.is_handle(value.base_type):
                handles.append(value)
            elif self.is_struct(
                value.base_type
            ) and (value.base_type in self.structs_with_handles):
                handles.append(value)
        return handles

    def make_get_command_handles_expr(self, cmd, values):
        """Generate an expression for a get command buffer handles utility function."""
        handle_params = self.get_param_list_handles(values)
        if handle_params:
            args = []
            for value in handle_params:
                if value.array_length:
                    args.append(value.array_length)
                args.append(value.name)
            return 'Track{}Handles, {}'.format(
                cmd[2:], ', '.join(self.make_unique_list(args))
            )
        else:
            return None

    def retrieves_handles(self, values):
        """Determine if an API call indirectly creates handles by retrieving them(e.g. vkEnumeratePhysicalDevices, vkGetRandROutputDisplayEXT)"""
        for value in values:
            if self.is_output_parameter(value) and (
                self.is_handle(value.base_type) or
                (value.base_type in self.structs_with_handles)
            ):
                return True
        return False

    def has_outputs(self, return_value, parameter_values):
        for value in parameter_values:
            if self.is_output_parameter(value):
                return True
        return False

    def __load_capture_overrides(self, filename):
        overrides = json.loads(open(filename, 'r').read())
        self.CAPTURE_OVERRIDES = overrides['functions']
