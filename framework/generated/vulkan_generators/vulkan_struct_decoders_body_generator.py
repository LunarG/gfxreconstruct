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


class VulkanStructDecodersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for Vulkan struct decoding"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platformTypes=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefixText='',
        protectFile=False,
        protectFeature=True,
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platformTypes,
            filename,
            directory,
            prefixText,
            protectFile,
            protectFeature,
            extraVulkanHeaders=extraVulkanHeaders
        )


# VulkanStructDecodersBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions for decoding Vulkan API structures.
class VulkanStructDecodersBodyGenerator(BaseGenerator):
    """Generate C++ functions for Vulkan struct decoding"""

    def __init__(
        self, errFile=sys.stderr, warnFile=sys.stderr, diagFile=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            processCmds=False,
            processStructs=True,
            featureBreak=True,
            errFile=errFile,
            warnFile=warnFile,
            diagFile=diagFile
        )

    # Method override
    # yapf: disable
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "generated/generated_vulkan_struct_decoders.h"', file=self.outFile)
        self.newline()
        write('#include "decode/custom_vulkan_struct_decoders.h"', file=self.outFile)
        write('#include "decode/decode_allocator.h"', file=self.outFile)
        self.newline()
        write('#include <cassert>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()
        write('size_t DecodePNextStruct(const uint8_t* buffer, size_t buffer_size, PNextNode** pNext);', file=self.outFile)
    # yapf: enable

    # Method override
    # yapf: disable
    def endFile(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
    # yapf: enable

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureStructMembers:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    # yapf: disable
    def generateFeature(self):
        first = True
        for struct in self.getFilteredStructNames():
            body = '' if first else '\n'
            body += 'size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_{}* wrapper)\n'.format(struct)
            body += '{\n'
            body += '    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));\n'
            body += '\n'
            body += '    size_t bytes_read = 0;\n'
            body += '    {}* value = wrapper->decoded_value;\n'.format(struct)
            body += '\n'
            body += self.makeDecodeStructBody(struct, self.featureStructMembers[struct])
            body += '\n'
            body += '    return bytes_read;\n'
            body += '}'

            write(body, file=self.outFile)
            first = False
    # yapf: enable

    #
    # Generate C++ code for the decoder method body.
    # yapf: disable
    def makeDecodeStructBody(self, name, values):
        body = ''

        for value in values:
            # pNext fields require special treatment and are not processed by type name
            if 'pNext' in value.name:
                body += '    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->{}));\n'.format(value.name)
                body += '    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;\n'
            else:
                body += self.makeDecodeInvocation(name, value)

        return body
    # yapf: enable

    #
    # Generate the struct member decoder function call invocation.
    # yapf: disable
    def makeDecodeInvocation(self, name, value):
        bufferArgs = '(buffer + bytes_read), (buffer_size - bytes_read)'

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
                # Pointer to an unknown object type, encoded as a 64-bit integer ID.
                body += '    bytes_read += ValueDecoder::DecodeAddress({}, &(wrapper->{}));\n'.format(bufferArgs, value.name)
                body += '    value->{} = nullptr;\n'.format(value.name)
            else:
                isStaticArray = True if (value.isArray and not value.isDynamic) else False
                accessOp = '.'

                if isStruct:
                    body += '    wrapper->{} = DecodeAllocator::Allocate<{}>();\n'.format(value.name, self.makeDecodedParamType(value))
                    accessOp = '->'

                if isStaticArray:
                    # The pointer decoder will write directly to the struct member's memory.
                    body += '    wrapper->{name}{}SetExternalMemory(value->{name}, {arraylen});\n'.format(accessOp, name=value.name, arraylen=value.arrayCapacity)

                if isStruct or isString or isHandle:
                    body += '    bytes_read += wrapper->{}{}Decode({});\n'.format(value.name, accessOp, bufferArgs)
                else:
                    body += '    bytes_read += wrapper->{}.Decode{}({});\n'.format(value.name, typeName, bufferArgs)

                if not isStaticArray:
                    if isHandle:
                        # Point the real struct's member pointer to the handle pointer decoder's handle memory.
                        body += '    value->{} = nullptr;\n'.format(value.name)
                    else:
                        # Point the real struct's member pointer to the pointer decoder's memory.
                        body += '    value->{name} = wrapper->{name}{}GetPointer();\n'.format(accessOp, name=value.name)
        else:
            if isStruct:
                body += '    wrapper->{} = DecodeAllocator::Allocate<{}>();\n'.format(value.name, self.makeDecodedParamType(value))
                body += '    wrapper->{name}->decoded_value = &(value->{name});\n'.format(name=value.name)
                body += '    bytes_read += DecodeStruct({}, wrapper->{});\n'.format(bufferArgs, value.name)
            elif isFuncp:
                body += '    bytes_read += ValueDecoder::DecodeAddress({}, &(wrapper->{}));\n'.format(bufferArgs, value.name)
                body += '    value->{} = nullptr;\n'.format(value.name)
            elif isHandle:
                body += '    bytes_read += ValueDecoder::DecodeHandleIdValue({}, &(wrapper->{}));\n'.format(bufferArgs, value.name)
                body += '    value->{} = VK_NULL_HANDLE;\n'.format(value.name)
            elif self.isGenericStructHandleValue(name, value.name):
                body += '    bytes_read += ValueDecoder::DecodeUInt64Value({}, &(wrapper->{}));\n'.format(bufferArgs, value.name)
                body += '    value->{} = 0;\n'.format(value.name)
            elif value.bitfieldWidth:
                # Bit fields need to be read into a tempoaray and then assigned to the struct member.
                tempParamName = 'temp_{}'.format(value.name)
                body += '    {} {};\n'.format(value.baseType, tempParamName)
                body += '    bytes_read += ValueDecoder::Decode{}Value({}, &{});\n'.format(typeName, bufferArgs, tempParamName)
                body += '    value->{} = {};\n'.format(value.name, tempParamName)
            else:
                body += '    bytes_read += ValueDecoder::Decode{}Value({}, &(value->{}));\n'.format(typeName, bufferArgs, value.name)

        return body
    # yapf: enable
