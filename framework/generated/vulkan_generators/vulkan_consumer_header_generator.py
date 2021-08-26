#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.
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

import os, re, sys
from base_generator import *


# Adds the following new option:
#  isOverride - Specify whether the member function declarations are
#               virtual function overrides or pure virtual functions.
class VulkanConsumerHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ class declarations for Vulkan parameter processing"""
    def __init__(
            self,
            className,
            baseClassHeader,
            isOverride,
            constructorArgs='',
            blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
            platformTypes=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
            filename=None,
            directory='.',
            prefixText='',
            protectFile=False,
            protectFeature=True,
            extraVulkanHeaders=[]):
        BaseGeneratorOptions.__init__(self,
                                      blacklists,
                                      platformTypes,
                                      filename,
                                      directory,
                                      prefixText,
                                      protectFile,
                                      protectFeature,
                                      extraVulkanHeaders=extraVulkanHeaders)
        self.className = className
        self.baseClassHeader = baseClassHeader
        self.isOverride = isOverride
        self.constructorArgs = constructorArgs


# VulkanConsumerHeaderGenerator - subclass of BaseGenerator.
# Generates C++ member declarations for the VulkanConsumer class responsible for processing
# Vulkan API call parameter data.
class VulkanConsumerHeaderGenerator(BaseGenerator):
    """Generate C++ class declarations for Vulkan parameter processing"""
    def __init__(self,
                 errFile=sys.stderr,
                 warnFile=sys.stderr,
                 diagFile=sys.stdout):
        BaseGenerator.__init__(self,
                               processCmds=True,
                               processStructs=False,
                               featureBreak=True,
                               errFile=errFile,
                               warnFile=warnFile,
                               diagFile=diagFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "decode/{}"'.format(genOpts.baseClassHeader),
              file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(genOpts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()
        write('class {className} : public {className}Base'.format(
            className=genOpts.className),
              file=self.outFile)
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        if genOpts.constructorArgs:
            argList = ', '.join([
                arg.split(' ')[-1]
                for arg in genOpts.constructorArgs.split(',')
            ])
            write('    {className}({}) : {className}Base({}) {{ }}\n'.format(
                genOpts.constructorArgs, argList, className=genOpts.className),
                  file=self.outFile)
        else:
            write('    {}() {{ }}\n'.format(genOpts.className),
                  file=self.outFile)
        write('    virtual ~{}() override {{ }}'.format(genOpts.className),
              file=self.outFile)

    # Method override
    def endFile(self):
        write('};', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
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
            values = info[2]

            decl = self.makeConsumerFuncDecl(returnType, 'Process_' + cmd,
                                             values)

            cmddef = '' if first else '\n'
            if self.genOpts.isOverride:
                cmddef += self.indent('virtual ' + decl + ' override;',
                                      self.INDENT_SIZE)
            else:
                cmddef += self.indent('virtual ' + decl + ' {}',
                                      self.INDENT_SIZE)

            write(cmddef, file=self.outFile)
            first = False
