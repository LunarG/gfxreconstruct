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

class StructEncodersGeneratorOptions(BaseGeneratorOptions):
    """Options for Vulkan API structure encoding C++ code generation"""
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

# StructEncodersGenerator - subclass of BaseGenerator.
# Generates C++ functions for encoding Vulkan API structures.
class StructEncodersGenerator(BaseGenerator):
    """Generate structure encoding C++ code"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self, errFile, warnFile, diagFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include <cmath>', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "format/parameter_encoder.h"', file=self.outFile)
        self.newline()
        write('BRIMSTONE_BEGIN_NAMESPACE(brimstone)', file=self.outFile)
        self.newline()
        write('size_t encode_pnext_struct(format::ParameterEncoder* encoder, const void* value);', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('BRIMSTONE_END_NAMESPACE(brimstone)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureStructMembers:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        first = True
        for struct in self.featureStructMembers:
            body = '' if first else '\n'
            body += 'size_t encode_struct(format::ParameterEncoder* encoder, const {}& value)\n'.format(struct)
            body += '{\n'
            body += '    size_t result = 0;\n'
            body += self.makeStructBody(self.featureStructMembers[struct], 'value.')
            body += '    return result;\n'
            body += '}\n'
            write(body, file=self.outFile)

            # TODO: The following can be templated in the hand written code.
            body = 'size_t encode_struct_ptr(format::ParameterEncoder* encoder, const {}* value)\n'.format(struct)
            body += '{\n'
            body += '    size_t result = encoder->EncodeStructPtrPreamble(value);\n'
            body += '    if (value != nullptr)\n'
            body += '    {\n'
            body += '        result += encode_struct(encoder, *value);\n'
            body += '    }\n'
            body += '    return result;\n'
            body += '}\n'
            write(body, file=self.outFile)

            body = 'size_t encode_struct_array(format::ParameterEncoder* encoder, const {}* value, size_t len)\n'.format(struct)
            body += '{\n'
            body += '    size_t result = encoder->EncodeStructArrayPreamble(value, len);\n'
            body += '    if ((value != nullptr) && (len > 0))\n'
            body += '    {\n'
            body += '        for(size_t i = 0; i < len; ++i)\n'
            body += '        {\n'
            body += '            result = encode_struct(encoder, value[i]);\n'
            body += '        }\n'
            body += '    }\n'
            body += '    return result;\n'
            body += '}'
            write(body, file=self.outFile)

            first = False

    #
    # Command definition
    def makeStructBody(self, values, prefix):
        # Build array of lines for function body
        body = ''

        for value in values:
            # pNext fields require special treatment and are not processed by typename
            if 'pNext' in value.name:
                body += '    result += encode_pnext_struct(encoder, {});\n'.format(prefix + value.name)
            else:
                methodCall = self.makeEncoderMethodCall(value, values, prefix)
                body += '    result += {};\n'.format(methodCall)

        return body
