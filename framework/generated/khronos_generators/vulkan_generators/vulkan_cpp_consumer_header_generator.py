#!/usr/bin/python3 -i
#
# Copyright (c) 2020 Samsung
# Copyright (c) 2023 Google
# Copyright (c) 2024 LunarG
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import sys
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write

# Copyright text prefixing all headers (list of strings).
CPP_PREFIX_STRING = [
    '/*',
    '** Copyright (c) 2020 Samsung',
    '** Copyright (c) 2023 Google',
    '** Copyright (c) 2024 LunarG, Inc.',
    '**',
    '** Permission is hereby granted, free of charge, to any person obtaining a',
    '** copy of this software and associated documentation files (the "Software"),',
    '** to deal in the Software without restriction, including without limitation',
    '** the rights to use, copy, modify, merge, publish, distribute, sublicense,',
    '** and/or sell copies of the Software, and to permit persons to whom the',
    '** Software is furnished to do so, subject to the following conditions:',
    '**',
    '** The above copyright notice and this permission notice shall be included in',
    '** all copies or substantial portions of the Software.', '**',
    '** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR',
    '** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,',
    '** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE',
    '** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER',
    '** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING',
    '** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER',
    '** DEALINGS IN THE SOFTWARE.',
    '*/',
    '',
    '/*',
    '** This file is generated from the Khronos Vulkan XML API Registry.',
    '**',
    '*/',
    ''
]

class VulkanCppConsumerHeaderGeneratorOptions(VulkanBaseGeneratorOptions):
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
        prefix_text=CPP_PREFIX_STRING,
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        VulkanBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            CPP_PREFIX_STRING,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )
        self.class_name = class_name
        self.base_class_header = base_class_header
        self.is_override = is_override
        self.constructor_args = constructor_args

        self.begin_end_file_data.specific_headers.extend((
            'decode/{}'.format(self.base_class_header),
            'util/defines.h'
        ))

        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode',))

class VulkanCppConsumerHeaderGenerator(VulkanBaseGenerator):
    """VulkanCppConsumerHeaderGenerator - subclass of VulkanBaseGenerator.
    Generates C++ member declarations for the VulkanConsumer class responsible for processing
    Vulkan API call parameter data.
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

        # TODO: Don't currently support Nvidia raytracing entrypoints
        self.APICALL_BLACKLIST = [
            'vkCmdBuildAccelerationStructureNV',
            'vkCmdTraceRaysNV',
            'vkCreateAccelerationStructureNV'
        ]

    def beginFile(self, gen_opts):
        """Method override."""
        VulkanBaseGenerator.beginFile(self, gen_opts)

        self.newline()
        write(
            'class {class_name} : public {class_name}Base'.format(
                class_name=gen_opts.class_name
            ),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        if gen_opts.constructor_args:
            arg_list = ', '.join(
                [
                    arg.split(' ')[-1]
                    for arg in gen_opts.constructor_args.split(',')
                ]
            )
            write(
                '    {class_name}({}) : {class_name}Base({}) {{ }}\n'.format(
                    gen_opts.constructor_args,
                    arg_list,
                    class_name=gen_opts.class_name
                ),
                file=self.outFile
            )
        else:
            write(
                '    {}() {{ }}\n'.format(gen_opts.class_name),
                file=self.outFile
            )
        write(
            '    virtual ~{}() override {{ }}'.format(gen_opts.class_name),
            file=self.outFile
        )

    def endFile(self):
        """Method override."""
        write('};', file=self.outFile)

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        if self.feature_cmd_params or self.struct_names:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        first = True
        cmdnames = self.get_filtered_cmd_names()
        cmdnames.sort()

        for cmd in cmdnames:
            info = self.feature_cmd_params[cmd]
            returnType = info[0]
            values = info[2]

            decl = self.make_consumer_func_decl(returnType, 'Process_' + cmd, values)

            cmddef = '' if first else '\n'
            if self.genOpts.is_override:
                cmddef += self.indent('virtual ' + decl + ' override;', self.INDENT_SIZE)
            else:
                cmddef += self.indent('virtual ' + decl + ' {}', self.INDENT_SIZE)

            write(cmddef, file=self.outFile)
            first = False
