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

from base_generator import *


# Base class for generating decoder body code.
class BaseDecoderBodyGenerator():

    #
    # Performs C++ code generation for the feature.
    # type is 'Vulkan' or 'DX12'
    def generate_feature(self, type):
        first = True
        for cmd in self.getFilteredCmdNames():
            self.cmdNames.append(cmd)

            info = self.featureCmdParams[cmd]
            returnType = info[0]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += 'size_t {}Decoder::Decode_{}(const uint8_t* parameter_buffer, size_t buffer_size)\n'.format(type, cmd)
            cmddef += '{\n'
            cmddef += '    size_t bytes_read = 0;\n'
            cmddef += '\n'
            cmddef += self.makeCmdBody(returnType, cmd, values)
            cmddef += '\n'
            cmddef += '    return bytes_read;\n'
            cmddef += '}'

            write(cmddef, file=self.outFile)
            first = False

    #
    # Generate C++ code for the decoder method body.
    def makeCmdBody(self, returnType, name, values, dx12_method = False):
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

        # Vulkan return is very simple. Value is only for DX12 Method.
        dx12_return_value = None
        dx12_return_decodeType = None
        if returnType and returnType != 'void':
            if dx12_method:
                dx12_return_value = self.get_return_value_info('return_value', returnType)
                dx12_return_decodeType = self.makeDecodedParamType(dx12_return_value)
                body += '    {} return_value;\n'.format(dx12_return_decodeType)
            else:
                body += '    {} return_value;\n'.format(returnType)

        # Blank line after declarations.
        if values or returnType:
            body += '\n'

        # Decode() method calls for pointer decoder wrappers.
        for value in values:
            body += BaseDecoderBodyGenerator.makeDecodeInvocation(self, value)
        if returnType and returnType != 'void':
            if dx12_method:
                body += BaseDecoderBodyGenerator.makeDecodeInvocation(self, dx12_return_value)
            else:
                body += BaseDecoderBodyGenerator.makeDecodeInvocation(self, ValueInfo('return_value', returnType, returnType))

        # Blank line after Decode() method invocations.
        if values or returnType:
            body += '\n'

        # Make the argument list for the API call
        arglist = ', '.join([argName for argName in argNames])
        if returnType and returnType != 'void':
            if dx12_method and dx12_return_decodeType.find('Decoder') != -1:
                arglist = ', '.join(['&return_value', arglist])
            else:
                arglist = ', '.join(['return_value', arglist])

        if dx12_method:
            arglist = 'object_id, ' + arglist

        if arglist[-2:] == ', ':
            arglist = arglist[:-2]

        body += '    for (auto consumer : GetConsumers())\n'
        body += '    {\n'
        body += '        consumer->Process_{}({});\n'.format(name, arglist)
        body += '    }\n'

        return body

    #
    # Generate parameter decode function/method invocation.
    def makeDecodeInvocation(self, value):
        bufferArgs = '(parameter_buffer + bytes_read), (buffer_size - bytes_read)'
        body = ''

        isStruct = False
        isClass = False
        isString = False
        isFuncp = False
        isHandle = False

        typeName = self.makeInvocationTypeName(value.baseType)

        if self.isStruct(typeName):
            isStruct = True
        elif self.isClass(value):
            isClass = True
        elif typeName in ['String', 'WString']:
            isString = True
        elif typeName == 'FunctionPtr':
            isFuncp = True
        elif typeName == 'Handle':
            isHandle = True

        # isPointer will be False for static arrays.
        if value.isPointer or value.isArray:
            if not isClass and typeName in self.EXTERNAL_OBJECT_TYPES and not value.isArray:
                if value.pointerCount > 1:
                    # Pointer to a pointer to an unknown object type (void**), encoded as a pointer to a 64-bit integer ID.
                    body += '    bytes_read += {}.DecodeVoidPtr({});\n'.format(value.name, bufferArgs)
                else:
                    # Pointer to an unknown object type, encoded as a 64-bit integer ID.
                    body += '    bytes_read += ValueDecoder::DecodeAddress({}, &{});\n'.format(bufferArgs, value.name)
            else:
                if isStruct or isString or isHandle or isClass:
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

    #
    # Generate the VulkanDecoder::DecodeFunctionCall method.
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
