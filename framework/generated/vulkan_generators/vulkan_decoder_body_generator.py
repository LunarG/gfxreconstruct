#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2020 Valve Corporation
# Copyright (c) 2018-2020 LunarG, Inc.
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


class VulkanDecoderBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan API parameter decoding"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platformTypes=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefixText='',
        protectFile=False,
        protectFeature=True
    ):
        BaseGeneratorOptions.__init__(
            self, blacklists, platformTypes, filename, directory, prefixText,
            protectFile, protectFeature
        )


# VulkanDecoderBodyGenerator - subclass of BaseGenerator.
# Generates C++ member functions for the VulkanDecoder class responsible for decoding
# Vulkan API call parameter data.
class VulkanDecoderBodyGenerator(BaseGenerator):
    """Generate a C++ class for Vulkan API parameter decoding"""

    def __init__(
        self, errFile=sys.stderr, warnFile=sys.stderr, diagFile=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            processCmds=True,
            processStructs=False,
            featureBreak=True,
            errFile=errFile,
            warnFile=warnFile,
            diagFile=diagFile
        )

        # Names of all Vulkan commands processed by the generator.
        self.cmdNames = []

    # Method override
    # yapf: disable
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "decode/handle_pointer_decoder.h"', file=self.outFile)
        write('#include "decode/pnext_node.h"', file=self.outFile)
        write('#include "decode/pointer_decoder.h"', file=self.outFile)
        write('#include "decode/string_array_decoder.h"', file=self.outFile)
        write('#include "decode/string_decoder.h"', file=self.outFile)
        write('#include "decode/struct_pointer_decoder.h"', file=self.outFile)
        write('#include "decode/value_decoder.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_decoder.h"', file=self.outFile)
        write('#include "generated/generated_vulkan_struct_decoders_forward.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include <cstddef>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
    # yapf: enable

    # Method override
    # yapf: disable
    def endFile(self):
        self.newline()
        # Generate the VulkanDecoder::DecodeFunctionCall method for all of the commands processed by the generator.
        self.generateDecodeCases()
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
    # yapf: enable

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureCmdParams:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    # yapf: disable
    def generateFeature(self):
        first = True
        for cmd in self.getFilteredCmdNames():
            self.cmdNames.append(cmd)

            info = self.featureCmdParams[cmd]
            returnType = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += 'size_t VulkanDecoder::Decode_{}(const uint8_t* parameter_buffer, size_t buffer_size)\n'.format(cmd)
            cmddef += '{\n'
            cmddef += '    size_t bytes_read = 0;\n'
            cmddef += '\n'
            cmddef += self.makeCmdBody(returnType, cmd, values)
            cmddef += '\n'
            cmddef += '    return bytes_read;\n'
            cmddef += '}'

            write(cmddef, file=self.outFile)
            first = False
    # yapf: enable

    #
    # Generate C++ code for the decoder method body.
    # yapf: disable
    def makeCmdBody(self, returnType, name, values):
        body = ''
        argNames = []

        # Declarations for decoded types.
        for value in values:
            decodeType = self.makeDecodedParamType(value)
            body += '    {} {};\n'.format(decodeType, value.name)
            if 'Decoder' in decodeType:
                argNames.append('&{}'.format(value.name))
            else:
                argNames.append(value.name)

        if returnType and returnType != 'void':
            body += '    {} return_value;\n'.format(returnType)

        # Blank line after declarations.
        if values or returnType:
            body += '\n'

        # Decode() method calls for pointer decoder wrappers.
        for value in values:
            body += self.makeDecodeInvocation(value)
        if returnType and returnType != 'void':
            body += self.makeDecodeInvocation(ValueInfo('return_value', returnType, returnType))

        # Blank line after Decode() method invocations.
        if values or returnType:
            body += '\n'

        # Make the argument list for the API call
        arglist = ', '.join([argName for argName in argNames])
        if returnType and returnType != 'void':
            arglist = ', '.join(['return_value', arglist])

        body += '    for (auto consumer : GetConsumers())\n'
        body += '    {\n'
        body += '        consumer->Process_{}({});\n'.format(name, arglist)
        body += '    }\n'

        return body
    # yapf: enable

    #
    # Generate parameter decode function/method invocation.
    # yapf: disable
    def makeDecodeInvocation(self, value):
        bufferArgs = '(parameter_buffer + bytes_read), (buffer_size - bytes_read)'
        body = ''

        isStruct = False
        isString = False
        isFuncp = False
        isHandle = False

        typeName = self.makeInvocationTypeName(value.baseType)

        if self.isStruct(typeName):
            isStruct = True
        elif typeName in ['String', 'WString']:
            isString = True
        elif typeName == 'FunctionPtr':
            isFuncp = True
        elif typeName == 'Handle':
            isHandle = True

        # isPointer will be False for static arrays.
        if value.isPointer or value.isArray:
            if typeName in self.EXTERNAL_OBJECT_TYPES and not value.isArray:
                if value.pointerCount > 1:
                    # Pointer to a pointer to an unknown object type (void**), encoded as a pointer to a 64-bit integer ID.
                    body += '    bytes_read += {}.DecodeVoidPtr({});\n'.format(value.name, bufferArgs)
                else:
                    # Pointer to an unknown object type, encoded as a 64-bit integer ID.
                    body += '    bytes_read += ValueDecoder::DecodeAddress({}, &{});\n'.format(bufferArgs, value.name)
            else:
                if isStruct or isString or isHandle:
                    body += '    bytes_read += {}.Decode({});\n'.format(value.name, bufferArgs)
                else:
                    body += '    bytes_read += {}.Decode{}({});\n'.format(value.name, typeName, bufferArgs)
        else:
            if isStruct:
                body += '    bytes_read += DecodeStruct({}, &{});\n'.format(bufferArgs, value.name)
            elif isFuncp:
                body += '    bytes_read += ValueDecoder::DecodeAddress({}, &{});\n'.format(bufferArgs, value.name)
            elif isHandle:
                body += '    bytes_read += ValueDecoder::DecodeHandleIdValue({}, &{});\n'.format(bufferArgs, value.name)
            else:
                body += '    bytes_read += ValueDecoder::Decode{}Value({}, &{});\n'.format(typeName, bufferArgs, value.name)

        return body
    # yapf: enable

    #
    # Generate the VulkanDecoder::DecodeFunctionCall method.
    # yapf: disable
    def generateDecodeCases(self):
        write('void VulkanDecoder::DecodeFunctionCall(format::ApiCallId             call_id,', file=self.outFile)
        write('                                       const ApiCallInfo&            call_info,', file=self.outFile)
        write('                                       const uint8_t*                parameter_buffer,', file=self.outFile)
        write('                                       size_t                        buffer_size)', file=self.outFile)
        write('{', file=self.outFile)
        write('    switch(call_id)', file=self.outFile)
        write('    {', file=self.outFile)
        write('    default:', file=self.outFile)
        write('        VulkanDecoderBase::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);', file=self.outFile)
        write('        break;', file=self.outFile)

        for cmd in self.cmdNames:
            cmddef = '    case format::ApiCallId::ApiCall_{}:\n'.format(cmd)
            cmddef += '        Decode_{}(parameter_buffer, buffer_size);\n'.format(cmd)
            cmddef += '        break;'
            write(cmddef, file=self.outFile)

        write('    }', file=self.outFile)
        write('}\n', file=self.outFile)
    # yapf: enable
