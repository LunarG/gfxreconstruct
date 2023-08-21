#!/usr/bin/python3 -i
#
# Copyright (c) 2020 Samsung
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

import os
import re
import sys

from base_generator import *
from vulkan_cpp_consumer_body_generator import CPP_CONSUMER_ADD_EXTENSION_PAT, CPP_CONSUMER_REMOVE_EXTENSION_PAT, \
    CPP_CONSUMER_VULKAN_VERSION_PAT, CPP_APICALL_BLACKLIST


# Adds the following new option:
#  is_override - Specify whether the member function declarations are
#               virtual function overrides or pure virtual functions.
class VulkanCppConsumerHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ class declarations for Vulkan parameter processing"""
    def __init__(self,
                 class_name,
                 base_class_header,
                 is_override,
                 constructorArgs = '',
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platform_types = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename = None,
                 directory = '.',
                 prefix_text = '',
                 protect_file = False,
                 protect_feature = True,
                 versions = CPP_CONSUMER_VULKAN_VERSION_PAT,
                 add_extensions = CPP_CONSUMER_ADD_EXTENSION_PAT,
                 remove_extensions = CPP_CONSUMER_REMOVE_EXTENSION_PAT):
        BaseGeneratorOptions.__init__(self, blacklists=blacklists, platform_types=platform_types,
                                      filename=filename, directory=directory, prefix_text=prefix_text,
                                      protect_file=protect_file, protect_feature=protect_feature,
                                      versions=versions, default_extensions="dis",
                                      add_extensions=add_extensions,
                                      remove_extensions=remove_extensions)
        self.class_name = class_name
        self.base_class_header = base_class_header
        self.is_override = is_override
        self.constructorArgs = constructorArgs


# VulkanCppConsumerHeaderGenerator - subclass of BaseGenerator.
# Generates C++ member declarations for the VulkanConsumer class responsible for processing
# Vulkan API call parameter data.
class VulkanCppConsumerHeaderGenerator(BaseGenerator):
    """Generate C++ class declarations for Vulkan parameter processing"""

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

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        self.APICALL_BLACKLIST += CPP_APICALL_BLACKLIST

        write('#include "decode/{}"'.format(genOpts.base_class_header), file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()
        write('class {class_name} : public {class_name}Base'.format(class_name=genOpts.class_name), file=self.outFile)
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        if genOpts.constructorArgs:
            argList = ', '.join([arg.split(' ')[-1] for arg in genOpts.constructorArgs.split(',')])
            write('    {class_name}({}) : {class_name}Base({}) {{ }}\n'.format(genOpts.constructorArgs, argList, class_name=genOpts.class_name), file=self.outFile)
        else:
            write('    {}() {{ }}\n'.format(genOpts.class_name), file=self.outFile)
        write('    virtual ~{}() override {{ }}'.format(genOpts.class_name), file=self.outFile)

    # Method override
    def endFile(self):
        write('};', file=self.outFile)
        self.newline()
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        if self.feature_cmd_params or self.struct_names:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generate_feature(self):
        first = True
        for cmd in self.get_filtered_cmd_names():
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
