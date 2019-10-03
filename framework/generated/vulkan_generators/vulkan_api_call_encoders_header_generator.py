#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.
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

import os,re,sys
from base_generator import *

class VulkanApiCallEncodersHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ function declarations for Vulkan API parameter encoding"""
    def __init__(self,
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platformTypes = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename = None,
                 directory = '.',
                 prefixText = '',
                 protectFile = False,
                 protectFeature = True):
        BaseGeneratorOptions.__init__(self, blacklists, platformTypes,
                                      filename, directory, prefixText,
                                      protectFile, protectFeature)

# VulkanApiCallEncodersHeaderGenerator - subclass of BaseGenerator.
# Generates C++ functions responsible for encoding Vulkan API call parameter data.
class VulkanApiCallEncodersHeaderGenerator(BaseGenerator):
    """Generate C++ function declarations for Vulkan API parameter encoding"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=False, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureCmdParams:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        first = True
        for cmd in self.getFilteredCmdNames():
            info = self.featureCmdParams[cmd]
            returnType = info[0]
            proto = info[1]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.makeCmdDecl(proto, values)

            write(cmddef, file=self.outFile)
            first = False

    #
    # Generate function declaration for a command
    def makeCmdDecl(self, proto, values):
        paramDecls = []

        for value in values:
            valueName = value.name
            valueType = value.fullType if not value.platformFullType else value.platformFullType

            if value.isArray and not value.isDynamic:
                valueName += '[{}]'.format(value.arrayCapacity)

            paramDecl = self.makeAlignedParamDecl(valueType, valueName, self.INDENT_SIZE, self.genOpts.alignFuncParam)
            paramDecls.append(paramDecl)

        if paramDecls:
            return '{}(\n{});'.format(proto, ',\n'.join(paramDecls))

        return '{}();'.format(proto)

