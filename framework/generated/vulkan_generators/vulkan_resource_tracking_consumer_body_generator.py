#!/usr/bin/env python3

# Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at:
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

'''
GFX reconstruct resource tracking consumer body generator
'''

import os
import re
import sys
from base_generator import *


class VulkanResourceTrackingConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """
    Options for generating a C++ class for Vulkan capture file
    to perform resource tracking
    """

    def __init__(self,
                 resourceTrackingOverrides=None,
                 blacklists=None,
                 platformTypes=None,
                 filename=None,
                 directory='.',
                 prefixText='',
                 protectFile=False,
                 protectFeature=True):
        """
        Init path to JSON file listing Vulkan API calls to override
        on memory data tracking, api calls and structs to ignore,
        and platform defined types if any.
        """
        BaseGeneratorOptions.__init__(self, blacklists, platformTypes,
                                      filename, directory, prefixText,
                                      protectFile, protectFeature)
        self.resource_tracking_overrides = resourceTrackingOverrides


class VulkanResourceTrackingConsumerBodyGenerator(BaseGenerator):
    """
    Generate a C++ class for Vulkan memory resources tracking
    VulkanResourceTrackingConsumerBodyGenerator - subclass of BaseGenerator.
    Generates C++ member definitions for the VulkanResourceTrackingConsumer
    class responsible for generating a memory map during first pass of replay.
    """
    RESOURCE_TRACKING_OVERRIDES = {}

    def __init__(self,
                 errFile=sys.stderr,
                 warnFile=sys.stderr,
                 diagFile=sys.stdout):
        """
        Init output for error, warning and diagnose files
        """
        BaseGenerator.__init__(self,
                               processCmds=True,
                               processStructs=False,
                               featureBreak=True,
                               errFile=errFile,
                               warnFile=warnFile,
                               diagFile=diagFile)

    def beginFile(self, generator_options):
        """
        Write the beginning of the file, it is a method override for
        the base generator class. It grabs the generator options and
        write the beginning of the file (namespace and includes headers)
        """
        BaseGenerator.beginFile(self, generator_options)

        if generator_options.resource_tracking_overrides:
            self.load_resource_tracking_overrides(
                generator_options.resource_tracking_overrides)

        write('#include \
"generated/generated_vulkan_resource_tracking_consumer.h"',
              file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def endFile(self):
        """
        Write end of file, it is a method override for the base generator.
        It writes end namespace and finish processing in superclass
        """
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        BaseGenerator.endFile(self)

    def needFeatureGeneration(self):
        """
        This is method ovverides for base generator class.
        It indicates that the current feature has C++ code to generate.
        """
        if self.featureCmdParams:
            return True
        return False

    def generateFeature(self):
        """
        This is method ovverides for base generator class.
        It performs C++ code generation for the feature
        command definition.
        """
        first = True
        for command in self.getFilteredCmdNames():
            info = self.featureCmdParams[command]
            return_type = info[0]
            values = info[2]

            command_definition = '' if first else '\n'
            command_definition += self.makeConsumerFuncDecl(
                return_type, 'VulkanResourceTrackingConsumer::Process_'
                + command, values) + '\n'
            command_definition += '{\n'
            command_definition += self.generate_consumer_function_body(
                return_type, command, values)
            command_definition += '}'

            write(command_definition, file=self.outFile)
            first = False

    def generate_body_expressions(self, name, values, is_override):
        """
        Generating expressions for mapping decoded parameters to arguments
        used in the API call
        """
        args = []       # List of arguments to the API call.

        for value in values:
            if value.isPointer or value.isArray:
                full_type = value.fullType if not value.platformFullType \
                    else value.platformFullType

                if (value.isArray and not value.isDynamic):
                    # Use dynamic pointer syntax for static arrays.
                    full_type += '*'

                args.append(value.name)
            else:
                # Only need to append the parameter name to the args list;
                # no other expressions are necessary.
                args.append(value.name)
        return args

    def generate_consumer_function_body(self, return_type, name, values):
        """
        Return VulkanResourceTrackingConsumer class member function definition.
        """
        is_override = name in self.RESOURCE_TRACKING_OVERRIDES

        args = self.generate_body_expressions(name, values, is_override)
        arglist = ', '.join(args)

        body = ''
        call_expressions = ''
        if is_override:
            call_expressions = '{}({})'.format(
                self.RESOURCE_TRACKING_OVERRIDES[name], arglist)
            body += '    {};\n'.format(call_expressions)
        else:
            body = '    //printf("%s\\n", "' + name + '");\n'
        return body

    def load_resource_tracking_overrides(self, filename):
        overrides = json.loads(open(filename, 'r').read())
        self.RESOURCE_TRACKING_OVERRIDES = overrides['functions']
