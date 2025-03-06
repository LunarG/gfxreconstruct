#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
# Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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
from openxr_base_generator import OpenXrBaseGenerator, OpenXrBaseGeneratorOptions, write
from khronos_api_call_encoders_generator import KhronosApiCallEncodersGenerator

class OpenXrApiCallEncodersBodyGeneratorOptions(OpenXrBaseGeneratorOptions):
    """Options for generating C++ functions for OpenXr API parameter encoding."""

    def __init__(
        self,
        capture_overrides=None,  # Path to JSON file listing OpenXr API calls to override on capture.
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        OpenXrBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )
        self.capture_overrides = capture_overrides

        begin_end = self.begin_end_file_data
        begin_end.specific_headers.extend((
            'encode/custom_openxr_encoder_commands.h',
            'encode/custom_openxr_struct_handle_wrappers.h',
            'encode/openxr_capture_manager.h',
            'encode/openxr_handle_wrappers.h',
            'encode/openxr_handle_wrapper_util.h',
            'encode/parameter_encoder.h',
            'encode/struct_pointer_encoder.h',
            '',
            'format/api_call_id.h',
            '',
            'generated/generated_openxr_api_call_encoders.h',
            'generated/generated_openxr_struct_handle_wrappers.h',
            'generated/generated_vulkan_struct_handle_wrappers.h',
            '',
            'util/defines.h',
        ))
        begin_end.namespaces.extend(('gfxrecon', 'encode'))


class OpenXrApiCallEncodersBodyGenerator(OpenXrBaseGenerator, KhronosApiCallEncodersGenerator):
    """OpenXrApiCallEncodersBodyGenerator - subclass of OpenXrBaseGenerator.
    Generates C++ functions responsible for encoding OpenXr API call
    parameter data.
    """

    # Map of OpenXr function names to override function names.  Calls to OpenXr functions in the map
    # will be replaced by the override value.
    CAPTURE_OVERRIDES = {}

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        OpenXrBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )
        KhronosApiCallEncodersGenerator.__init__(self)

    def beginFile(self, gen_opts):
        """Method override."""
        OpenXrBaseGenerator.beginFile(self, gen_opts)

        if gen_opts.capture_overrides:
            self.load_capture_overrides(gen_opts.capture_overrides)

    def endFile(self):
        """Method override."""
        self.write_api_call_encoders_contents(make_cmd_body=self.make_cmd_body)

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)

    def use_instance_table(self, name, typename):
        """Check for dispatchable handle types associated with the instance dispatch table."""
        if typename in ['VkInstance', 'VkPhysicalDevice']:
            return True
        return False

    def make_layer_dispatch_call(self, name, values, arg_list):
        """Generate the layer dispatch call invocation."""
        call_setup_expr = []
        object_name = values[0].name
        dispatchfunc = 'openxr_wrappers::GetInstanceTable'

        return [
            call_setup_expr, '{}({})->{}({})'.format(
                dispatchfunc, object_name, name[2:], arg_list
            )
        ]

    def make_cmd_body(self, return_type, name, values):
        """Command definition."""
        indent = ' ' * self.INDENT_SIZE
        is_override = name in self.CAPTURE_OVERRIDES
        encode_after = False
        omit_output_param = None
        has_outputs = self.has_outputs(return_type, values)
        arg_list = self.make_arg_list(values)

        body = ''

        if has_outputs or (return_type and return_type != 'void'):
            encode_after = True

        omit_output_param = None
        if has_outputs and (return_type and return_type != 'void'):
            omit_output_param = 'omit_output_data'
            body += f'{indent}bool {omit_output_param} = false;\n'
            body += '\n'

        top_indent = indent

        if name == "xrCreateApiLayerInstance":
            capture_manager = 'OpenXrCaptureManager::Get()'
            body += indent + 'auto api_call_lock = OpenXrCaptureManager::AcquireExclusiveApiCallLock();\n'
        else:
            capture_manager = 'manager'
            body += indent + 'OpenXrCaptureManager* manager = OpenXrCaptureManager::Get();\n'
            body += indent + 'GFXRECON_ASSERT(manager != nullptr);\n'
            if not is_override:
                # Allow customization that is unlocked and validly reentrant
                # For example if one needs to record calls into the output stream to add context or state
                # to allow replay time operations, or handle differences in state tracking between API's (e.g. wrapped handles)
                body += indent + 'CustomEncoderPreCall<format::ApiCallId::ApiCall_{}>::PreLockReentrant({}, {});\n'.format(
                    name, capture_manager, arg_list
                )

                # Declare for handles that need unwrapping.
                unwrapped_arg_list, unwrap_list = self.make_handle_unwrapping(
                    name, values
                )
                if unwrap_list:
                    body += indent + f'HandleUnwrapMemory* handle_unwrap_memory = nullptr;\n'
                    body += '\n'.join(
                        [
                            indent +
                            '{type} {wrap_name} = nullptr;\n'.format(**unwrap)
                            for unwrap in unwrap_list
                        ]
                    )

                body += indent + 'CommonCaptureManager::CaptureMode save_capture_mode;\n'
                top_indent = indent + ' ' * self.INDENT_SIZE
                body += indent + '{\n'

                lock_call = 'auto call_lock = manager->AcquireCallLock();\n'
                body += top_indent + lock_call

        body += '\n'

        body += top_indent + 'CustomEncoderPreCall<format::ApiCallId::ApiCall_{}>::Dispatch({}, {});\n'.format(
            name, capture_manager, arg_list
        )

        if not encode_after:
            body += '\n'
            body += self.make_parameter_encoding(
                name, values, return_type, top_indent, omit_output_param
            )

        # Some API calls have different Success criteria for outputting data
        emit_output_check = f'CustomCallResult<format::ApiCallId::ApiCall_{name}>::Succeeded ({capture_manager}, result)'

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
                body += f'{indent}{omit_output_param} = !{emit_output_check};\n'
        else:
            # Unwrap handles that need unwrapping
            if unwrap_list:
                body += '\n' + top_indent + f'handle_unwrap_memory = {capture_manager}->GetHandleUnwrapMemory();\n'
                body += '\n'.join(
                    [
                        top_indent
                        + '{wrap_name} = {call};\n'.format(**unwrap)
                        for unwrap in unwrap_list
                    ]
                )

            # Disable capture for reentrance
            body += top_indent + 'save_capture_mode = manager->GetCaptureMode();\n'
            body += top_indent + 'manager->SetCaptureMode(CommonCaptureManager::CaptureModeFlags::kModeDisabled);\n'

            # Unlock above (only !is_override)
            body += indent + '}\n\n'

            # Still holding a lock across a call here...
            if self.lock_for_destroy_handle_is_needed(name):
                body += indent + 'ScopedDestroyLock exclusive_scoped_lock;\n'

            # Construct the function call to dispatch to the next layer.
            (call_setup_expr, call_expr) = self.make_layer_dispatch_call(
                name, values, unwrapped_arg_list
            )
            if call_setup_expr:
                for e in call_setup_expr:
                    body += indent + e + '\n'
            if return_type and return_type != 'void':
                body += indent + '{} result = {};\n'.format(
                    return_type, call_expr
                )
            else:
                body += indent + '{};\n'.format(call_expr)

            # Need to relock, since lock was released before dispatch
            body += '\n' + indent + lock_call

            # Restore capture_mode
            body += indent + 'manager->SetCaptureMode(save_capture_mode);\n'

            # Wrap newly created handles.
            wrap_expr = self.make_handle_wrapping(values, indent)
            if wrap_expr:
                body += '\n'
                if return_type and return_type != 'void':
                    body += f'{indent}if ({emit_output_check})\n'
                    body += indent + '{\n'
                    body += '    ' + wrap_expr
                    body += indent + '}\n'
                    if has_outputs:
                        body += f'{indent}else\n'
                        body += f'{indent}{{\n'
                        body += f'{indent}    {omit_output_param} = true;\n'
                        body += f'{indent}}}\n'
                else:
                    body += wrap_expr
            elif has_outputs and (return_type and return_type != 'void'):
                body += f'{indent}{omit_output_param} = !{emit_output_check};\n'

        if encode_after:
            body += self.make_parameter_encoding(
                name, values, return_type, indent, omit_output_param
            )

        body += '\n'
        if return_type and return_type != 'void':
            body += '    CustomEncoderPostCall<format::ApiCallId::ApiCall_{}>::Dispatch({}, result, {});\n'.format(
                name, capture_manager, arg_list
            )
        else:
            body += '    CustomEncoderPostCall<format::ApiCallId::ApiCall_{}>::Dispatch({}, {});\n'.format(
                name, capture_manager, arg_list
            )

        cleanup_expr = self.make_handle_cleanup(name, values, indent)
        if cleanup_expr:
            body += '\n'
            body += cleanup_expr

        if return_type and return_type != 'void':
            body += '\n'
            body += '    return result;\n'

        return body

    def make_begin_api_call(self, name, values):
        capture_manager = 'manager'
        if name == 'xrCreateApiLayerInstance':
            capture_manager = 'OpenXrCaptureManager::Get()'

        if name.startswith('xrCreate') or name.startswith('xrDestroy'):
            return 'auto encoder = {}->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_{});\n'.format(
                capture_manager, name
            )
        else:
            return 'auto encoder = {}->BeginApiCallCapture(format::ApiCallId::ApiCall_{});\n'.format(
                capture_manager, name
            )

    def make_end_api_call(self, name, values, return_type):
        decl = 'manager->'
        if name == 'xrCreateApiLayerInstance':
            decl = 'OpenXrCaptureManager::Get()->'

        if name.startswith('xrCreate'):
            if name == 'xrCreateSwapchainAndroidSurfaceKHR' or 'Vulkan' in name:
                # The handle is the second last parameter.
                handle = values[-2]
                parent_handle = values[0] if self.is_handle(
                    values[0].base_type
                ) else None
            else:
                # The handle is the last parameter.
                handle = values[-1]
                parent_handle = values[0] if self.is_handle(
                    values[0].base_type
                ) else None

            handle_wrapper = self.get_handle_wrapper(handle.base_type)

            #  Search for the create info struct
            info_base_type = 'void'
            info_name = 'nullptr'
            for value in values:
                if ('CreateInfo' in value.base_type):
                    info_base_type = value.base_type
                    info_name = value.name
                    # Confirm array counts match
                    if value.is_array and (
                        handle.array_length != value.array_length
                    ):
                        print(
                            'WARNING: {} has separate array counts for create info structures ({}) and handles ({})'
                            .format(
                                name, value.array_length, handle.array_length
                            )
                        )

            return_value = 'XR_SUCCESS'
            if return_type == 'XrResult':
                return_value = 'result'

            if handle.is_array:
                length_name = self.make_array_length_expression(handle)

                if 'pAllocateInfo->' in length_name:
                    # This is a pool allocation call, which receives one allocate info structure that is shared by all object being allocated.
                    decl += 'EndPoolCreateApiCallCapture<{}, {}, {}>({}, {}, {}, {}, {})'.format(
                        parent_handle.base_type, handle_wrapper,
                        info_base_type, return_value, parent_handle.name,
                        length_name, handle.name, info_name
                    )
                else:
                    # This is a multi-object creation call (e.g. pipeline creation, or swapchain image retrieval), which receives
                    # separate create info structures for each object being created. Many multi-object creation calls receive a
                    # handle as their second parameter, which is of interest to the state tracker (e.g. the hPipelineCache handle
                    # from vkCreateGraphicsPipelines or the vkSwapchain handle from vkGetSwapchainImagesKHR). For api calls that do
                    # not receive a handle as the second parameter (e.g. vkEnumeratePhysicalDevices), the handle type is set to 'void*'.
                    if handle.base_type in self.struct_names:
                        # "handle" is actually a struct with embedded handles
                        unwrap_handle_def = 'nullptr'
                        member_handle_type, member_handle_name, member_array_length = self.get_struct_handle_member_info(
                            self.structs_with_handles[handle.base_type]
                        )
                        member_handle_wrapper = self.get_wrapper_prefix_from_type(
                            member_handle_type
                        )

                        if not member_array_length:
                            unwrap_handle_def = '[]({}* handle_struct)->{wrapper}r* {{ return openxr_wrappers::GetWrapper<{wrapper}>(handle_struct->{}); }}'.format(
                                handle.base_type,
                                member_handle_name,
                                wrapper=member_handle_wrapper
                            )

                        decl += 'EndStructGroupCreateApiCallCapture<{}, {}, {}>({}, {}, {}, {}, {})'.format(
                            parent_handle.base_type, member_handle_wrapper,
                            handle.base_type, return_value, parent_handle.name,
                            length_name, handle.name, unwrap_handle_def
                        )
                    elif self.is_handle(values[1].base_type):
                        second_handle = values[1]
                        decl += 'EndGroupCreateApiCallCapture<{}, {}, {}, {}>({}, {}, {}, {}, {}, {})'.format(
                            parent_handle.base_type, second_handle.base_type,
                            handle_wrapper, info_base_type, return_value,
                            parent_handle.name, second_handle.name,
                            length_name, handle.name, info_name
                        )
                    else:
                        decl += 'EndGroupCreateApiCallCapture<{}, void*, {}, {}>({}, {}, nullptr, {}, {}, {})'.format(
                            parent_handle.base_type, handle_wrapper,
                            info_base_type, return_value, parent_handle.name,
                            length_name, handle.name, info_name
                        )

            else:
                end_api_call = 'EndCreateApiCallCapture'
                if handle.base_type in self.atom_names:
                    end_api_call = 'EndCreateAtomApiCallCapture'

                if handle.base_type in self.struct_names:
                    # TODO: No cases in current OpenXr spec of handle inside non-array output structure
                    raise NotImplementedError
                elif parent_handle:
                    decl += '{}<{}, {}, {}>({}, {}, {}, {})'.format(
                        end_api_call, parent_handle.base_type, handle_wrapper,
                        info_base_type, return_value, parent_handle.name,
                        handle.name, info_name
                    )
                else:
                    # Instance creation does not have a parent handle; set the parent handle type to 'void*'.
                    decl += '{}<const void*, {}, {}>({}, nullptr, {}, {})'.format(
                        end_api_call, handle_wrapper, info_base_type,
                        return_value, handle.name, info_name
                    )

        elif name.startswith('xrDestroy'):
            handle = values[0]
            handle_wrapper = self.get_handle_wrapper(handle.base_type)

            if handle.is_array:
                decl += 'EndDestroyApiCallCapture<{}>({}, {})'.format(
                    handle_wrapper, handle.array_length, handle.name
                )
            else:
                decl += 'EndDestroyApiCallCapture<{}>({})'.format(
                    handle_wrapper, handle.name
                )
        else:
            decl += 'EndApiCallCapture()'

        decl += ';\n'
        return decl

    def make_handle_wrapping(self, values, indent):
        expr = ''
        for value in values:
            if self.is_output_parameter(value) and (
                self.is_handle_like(value.base_type) or self.struct_has_handles(value.base_type)
            ):
                parent_prefix = 'openxr_wrappers::'
                co_parent_prefix = 'openxr_wrappers::'
                temp_prefix = self.get_wrapper_prefix_from_type(
                    values[0].base_type
                )
                if temp_prefix != 'UNKNOWN_WRAPPERS':
                    parent_prefix = temp_prefix + '::'

                if values[1] is not None:
                    temp_prefix = self.get_wrapper_prefix_from_type(
                        values[1].base_type
                    )
                    if temp_prefix != 'UNKNOWN_WRAPPERS':
                        co_parent_prefix = temp_prefix + '::'

                # The XrInstance handle does not have parent, so the 'unused'
                # values will be provided to the wrapper creation function.
                parent_type = parent_prefix + 'NoParentWrapper'
                parent_value = parent_prefix + 'NoParentWrapper::kHandleValue'
                if self.is_handle_like(values[0].base_type):
                    parent_type = self.get_handle_wrapper(values[0].base_type)
                    parent_value = values[0].name

                # Some handles have two parent handles, such as swapchain images and display modes,
                # or command buffers and descriptor sets allocated from pools.
                co_parent_type = co_parent_prefix + 'NoParentWrapper'
                co_parent_value = co_parent_prefix + 'NoParentWrapper::kHandleValue'
                if self.is_handle_like(
                    values[1].base_type
                ) and not self.is_output_parameter(values[1]):
                    co_parent_type = self.get_handle_wrapper(
                        values[1].base_type
                    )
                    co_parent_value = values[1].name

                wrapper_prefix = self.get_wrapper_prefix_from_type(
                    value.base_type
                )

                if value.is_array:
                    length_name = value.array_length
                    for len in values:
                        if (len.name == length_name) and len.is_pointer:
                            length_name = '({name} != nullptr) ? (*{name}) : 0'.format(
                                name=length_name
                            )
                            break
                    if self.is_handle(value.base_type):

                        handle_wrapper = self.get_handle_wrapper(
                            value.base_type
                        )
                        expr += indent + '{}CreateWrappedHandles<{}, {}, {}>({}, {}, {}, {}, OpenXrCaptureManager::GetUniqueId);\n'.format(
                            parent_prefix, parent_type, co_parent_type,
                            handle_wrapper, parent_value, co_parent_value,
                            value.name, length_name
                        )
                    elif self.is_atom(value.base_type):

                        handle_wrapper = self.get_handle_wrapper(
                            value.base_type
                        )
                        expr += indent + '{}CreateWrappedAtoms<{}, {}>({}, {}, {}, OpenXrCaptureManager::GetUniqueId);\n'.format(
                            parent_prefix, parent_type, handle_wrapper,
                            parent_value, value.name, length_name
                        )
                    elif self.is_opaque(value.base_type):

                        handle_wrapper = self.get_handle_wrapper(
                            value.base_type
                        )
                        expr += indent + '{}CreateWrappedOpaques<{}, {}>({}, {}, {}, OpenXrCaptureManager::GetUniqueId);\n'.format(
                            parent_prefix, parent_type, handle_wrapper,
                            parent_value, value.name, length_name
                        )
                    elif self.is_struct(
                        value.base_type
                    ) and (value.base_type in self.structs_with_handles):
                        expr += indent + '{}CreateWrappedStructArrayHandles<{}, {}, {}>({}, {}, {}, {}, OpenXrCaptureManager::GetUniqueId);\n'.format(
                            parent_prefix, parent_type, co_parent_type,
                            value.base_type, parent_value, co_parent_value,
                            value.name, length_name
                        )
                else:
                    is_handle = self.is_handle(value.base_type)
                    is_atom = self.is_atom(value.base_type)
                    is_opaque = self.is_opaque(value.base_type)
                    if self.is_handle(value.base_type):
                        handle_wrapper = self.get_handle_wrapper(
                            value.base_type
                        )
                        expr += indent + '{}CreateWrappedHandle<{}, {}, {}>({}, {}, {}, OpenXrCaptureManager::GetUniqueId);\n'.format(
                            parent_prefix, parent_type, co_parent_type,
                            handle_wrapper, parent_value, co_parent_value,
                            value.name
                        )
                    elif self.is_atom(value.base_type):
                        handle_wrapper = self.get_handle_wrapper(
                            value.base_type
                        )
                        expr += indent + '{}CreateWrappedAtom<{}, {}>({}, {}, OpenXrCaptureManager::GetUniqueId);\n'.format(
                            parent_prefix, parent_type, handle_wrapper,
                            parent_value, value.name
                        )
                    elif self.is_opaque(value.base_type):
                        handle_wrapper = self.get_handle_wrapper(
                            value.base_type
                        )
                        expr += indent + '{}CreateWrappedOpaque<{}, {}>({}, {}, OpenXrCaptureManager::GetUniqueId);\n'.format(
                            parent_prefix, parent_type, handle_wrapper,
                            parent_value, value.name
                        )
                    elif self.is_struct(
                        value.base_type
                    ) and (value.base_type in self.structs_with_handles):
                        expr += indent + '{}CreateWrappedStructHandles<{}, {}>({}, {}, {}, OpenXrCaptureManager::GetUniqueId);\n'.format(
                            parent_prefix, parent_type, co_parent_type,
                            parent_value, co_parent_value, value.name
                        )
        return expr

    def make_handle_unwrapping(self, name, values):
        args = []
        unwraps = []
        need_unwrap_memory = False
        for value in values:
            arg_name = value.name
            if value.is_pointer or value.is_array:
                if self.is_input_pointer(value):
                    if (value.base_type in self.structs_with_handles
                        ) or (value.base_type in self.GENERIC_HANDLE_STRUCTS):
                        arg_name += '_unwrapped'
                        wrapper_prefix = self.get_wrapper_prefix_from_type(
                            value.base_type
                        ) + '::'
                        unwrap = {
                            'type': value.full_type,
                            'name': value.name,
                            'wrap_name': arg_name,
                            'prefix': wrapper_prefix
                        }
                        if value.is_array:
                            unwrap['length'] = value.array_length
                            unwrap[
                                'call'
                            ] = '{prefix}UnwrapStructArrayHandles({name}, {length}, handle_unwrap_memory)'.format(
                                **unwrap
                            )
                        else:
                            unwrap[
                                'call'
                            ] = '{prefix}UnwrapStructPtrHandles({name}, handle_unwrap_memory)'.format(
                                **unwrap
                            )
                        unwraps.append(unwrap)
            args.append(arg_name)
        return ', '.join(args), unwraps

    def lock_for_destroy_handle_is_needed(self, name):
        if name.startswith('xrDestroy'):
            return True
        else:
            return False

    def make_handle_cleanup(self, name, values, indent):
        expr = ''
        if name.startswith('xrDestroy'):
            handle = values[0]
            wrapper_prefix = self.get_wrapper_prefix_from_type(
                handle.base_type
            ) + '::'
            handle_prefix = self.get_handle_wrapper(handle.base_type)

            if handle.is_array:
                expr += indent + '{}DestroyWrappedHandles<{}>({}, {});\n'.format(
                    wrapper_prefix, handle_prefix, handle.name,
                    handle.array_length
                )
            else:
                expr += indent + '{}DestroyWrappedHandle<{}>({});\n'.format(
                    wrapper_prefix, handle_prefix, handle.name
                )
        return expr
