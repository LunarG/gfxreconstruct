#!/usr/bin/python3 -i
#
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

# Adds the following new option:
#  isOverride - Specify whether the member function declarations are
#               virtual function overrides or pure virtual functions.
class ApiCallConsumerDeclarationsGeneratorOptions(BaseGeneratorOptions):
    """Options for Vulkan API parameter processing C++ code generation"""
    def __init__(self,
                 isOverride,
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
        self.isOverride = isOverride

# ApiCallDecoderDeclarationsGenerator - subclass of BaseGenerator.
# Generates C++ member declarations for the VulkanConsumer class responsible for processing
# Vulkan API call parameter data.
class ApiCallConsumerDeclarationsGenerator(BaseGenerator):
    """Generate API parameter processing C++ member declarations"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True, processStructs=False, featureBreak=True,
                               errFile=errFile, warnFile=warnFile, diagFile=diagFile)

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
        for cmd in self.featureCmdParams:
            info = self.featureCmdParams[cmd]
            returnType = info[0]
            values = info[2]

            decl = self.makeConsumerFuncDecl(returnType, 'Process_' + cmd, values)

            cmddef = '' if first else '\n'
            if self.genOpts.isOverride:
                cmddef += self.indent('virtual ' + decl + ' override;', self.INDENT_SIZE)
            else:
                cmddef += self.indent('virtual ' + decl + ' = 0;', self.INDENT_SIZE)

            write(cmddef, file=self.outFile)
            first = False
