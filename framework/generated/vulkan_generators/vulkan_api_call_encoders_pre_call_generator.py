#!/usr/bin/python3 -i
#
# Copyright (c) 2023 Valve Corporation
# Copyright (c) 2023 LunarG, Inc.
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


class VulkanApiCallEncodersPreCallGeneratorOptions(BaseGeneratorOptions):
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


class VulkanApiCallEncodersPreCallGenerator(BaseGenerator):
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

        write('#ifndef GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_PRE_COMMANDS_H',file=self.outFile)
        write('#define GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_PRE_COMMANDS_H',file=self.outFile)
        self.newline()

        write('#include "encode/custom_vulkan_encoder_commands.h"',file=self.outFile)
        write('#include "encode/vulkan_capture_manager.h"',file=self.outFile)
        write('#include "generated/generated_vulkan_struct_handle_wrappers.h"', file=self.outFile)
        write('#include "format/api_call_id.h"', file=self.outFile)
        write('#include "util/defines.h"',file=self.outFile)

        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        self.newline()
        write('template <format::ApiCallId Id>',file=self.outFile)
        write('struct EncoderPreCall',file=self.outFile)
        write('{',file=self.outFile)
        write('    template <typename... Args>',file=self.outFile)
        write('    static void Dispatch(VulkanCaptureManager* manager, Args... args)',file=self.outFile)
        write('    {}',file=self.outFile)
        write('};',file=self.outFile)

    def endFile(self):
        """Method override."""
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)
        self.newline()
        write('#endif // GFXRECON_ENCODE_GENERATED_VULKAN_ENCODER_PRE_COMMANDS_H', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.check_struct_member_handles(
                typename, self.structs_with_handles
            )

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        first = True
        for cmd in self.get_filtered_cmd_names():
            info = self.feature_cmd_params[cmd]
            return_type = info[0]
            proto = info[1]
            values = info[2]

            cmddef = ''
            cmddef += self.make_cmd_body(return_type, cmd, proto, values)

            write(cmddef, file=self.outFile)
            first = False

    def make_cmd_body(self, return_type, name, proto, values):
        arg_list = self.make_arg_list(values)
        indent = ' ' * self.INDENT_SIZE
        is_create_instance = name == 'vkCreateInstance'

        body = 'template<>\n'
        body += 'struct EncoderPreCall<format::ApiCallId::ApiCall_{}>\n'.format(name)
        body += '{\n'
        body += self.make_dispatch_decl(proto, values)
        body += indent + '{\n'

        if not is_create_instance:
            body += indent + indent + 'assert(manager);\n\n'

        body += indent + indent + 'CustomEncoderPreCall<format::ApiCallId::ApiCall_{}>::Dispatch(manager, {});\n'.format(name, arg_list)

        if not is_create_instance:
            body += '\n'

            # Check for handles that need unwrapping.
            unwrap_expr, unwrapped_arg_list, need_unwrap_memory = self.make_handle_unwrapping(
                name, values, indent
            )

            if unwrap_expr:
                if need_unwrap_memory:
                    body += indent + indent + 'auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();\n'
                body += indent + unwrap_expr
                body += '\n'

            body += indent + indent + 'for (auto &plugin : manager->GetLoadedPlugins())\n'
            body += indent + indent + '{\n'
            body += indent + indent + '    plugin.func_table_pre.{}_PreCall(manager->GetBlockIndex(), {});\n'.format(name[2:], arg_list)
            body += indent + indent + '}\n'

        body += indent + '}\n'
        body += '};\n'

        return body

    def make_dispatch_decl(self, proto, values):
        param_decls = []
        indent = ' ' * self.INDENT_SIZE

        for value in values:
            value_name = value.name
            value_type = value.full_type if not value.platform_full_type else value.platform_full_type

            if value.is_array and not value.is_dynamic:
                value_name += '[{}]'.format(value.array_capacity)

            param_decl = self.make_aligned_param_decl(
                value_type, value_name, 2 * self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            param_decls.append(param_decl)

        if param_decls:
            return indent + 'static void Dispatch(VulkanCaptureManager* manager,\n{})\n'.format(',\n'.join(param_decls))

        return '{}()\n'.format(proto)

    def make_handle_unwrapping(self, name, values, indent):
        args = []
        expr = ''
        need_unwrap_memory = False
        for value in values:
            arg_name = value.name
            if value.is_pointer or value.is_array:
                if self.is_input_pointer(value):
                    if (value.base_type in self.structs_with_handles) or (
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
            args.append(arg_name)
        return expr, ', '.join(args), need_unwrap_memory
