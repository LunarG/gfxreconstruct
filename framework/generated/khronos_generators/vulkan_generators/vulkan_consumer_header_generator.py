#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
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

import sys
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write
from khronos_consumer_header_generator import KhronosConsumerHeaderGenerator


class VulkanConsumerHeaderGeneratorOptions(VulkanBaseGeneratorOptions):
    """Adds the following new option:
    is_override - Specify whether the member function declarations are
                  virtual function overrides or pure virtual functions.
    Options for generating C++ class declarations for Vulkan parameter processing.
    """

    def __init__(
        self,
        class_name,
        base_class_header,
        is_override,
        constructor_args='',
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        generate_process_overloads=False,
        extra_headers=[]
    ):
        VulkanBaseGeneratorOptions.__init__(
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
        self.class_name = class_name
        self.base_class_header = base_class_header
        self.is_override = is_override
        self.constructor_args = constructor_args
        self.generate_process_overloads = generate_process_overloads

        self.begin_end_file_data.specific_headers.extend((
            'decode/{}'.format(self.base_class_header),
            'util/defines.h',
            'generated/generated_vulkan_decoder_args.h',
            'decode/vulkan_decoder_args.h',
        ))

        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))


class VulkanConsumerHeaderGenerator(VulkanBaseGenerator, KhronosConsumerHeaderGenerator):
    """VulkanConsumerHeaderGenerator - subclass of VulkanBaseGenerator.
    Generates C++ member declarations for the VulkanConsumer class responsible for processing
    Vulkan API call parameter data.
    Generate C++ class declarations for Vulkan parameter processing.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def write_class_contents(self):
        """Method may be overridden."""
        KhronosConsumerHeaderGenerator.write_class_contents(self)

        if self.genOpts.generate_process_overloads:
            self.write_process_overloads()

    def write_process_overloads(self):
        """Write process overloads for all Vulkan commands. E.g.:
        void Process(const ApiCallInfo& call_info, args::CmdDraw& args) { Process_vkCmdDraw(call_info, args); }
        """
        for cmd in self.get_all_filtered_cmd_names():
            if self.skip_generating_command(cmd):
                continue

            decl = self.make_process_overload_func_decl(cmd)
            cmddef = self.indent(f'\n{decl} {{\n', self.INDENT_SIZE)
            cmddef += self.indent(f'Process_{cmd}(call_info, args);', self.INDENT_SIZE * 2)
            cmddef += self.indent('\n}', self.INDENT_SIZE)

            write(cmddef, file=self.outFile)

    def make_process_overload_func_decl(self, cmd_name):
        """return the process overload function declaration for the given command name."""
        param_decls = []
        param_decls.append(self.make_call_info_param_decl())
        param_decls.append(self.make_process_overload_param_decl(cmd_name))
        return 'void Process(\n{})'.format(',\n'.join(param_decls))

    def make_process_overload_param_decl(self, name):
        """return the parameter declaration for the process overload function."""
        args_struct_name = self.make_args_struct_name(name, namespace='args::')
        param_decl = self.make_aligned_param_decl(
            f'{args_struct_name}&', 'args', self.INDENT_SIZE,
            self.genOpts.align_func_param
        )
        return param_decl

    def endFile(self):
        """Method override."""
        KhronosConsumerHeaderGenerator.output_header_contents(
            self, self.genOpts.class_name, self.genOpts.constructor_args)

        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)
