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


# Base class for generating struct docoder body code.
class BaseStructDecodersBodyGenerator():

    #
    # Performs C++ code generation for the feature.
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

    #
    # Generate C++ code for the decoder method body.
    def makeDecodeStructBody(self, name, values):
        body = ''

        for value in values:
            # pNext fields require special treatment and are not processed by type name
            if 'pNext' in value.name and value.baseType == 'void':
                body += '    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->{}));\n'.format(value.name)
                body += '    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;\n'
            else:
                body += BaseStructDecodersBodyGenerator.makeDecodeInvocation(self, name, value)

        return body

    #
    # Generate the struct member decoder function call invocation.
    def makeDecodeInvocation(self, name, value):
        bufferArgs = '(buffer + bytes_read), (buffer_size - bytes_read)'

        body = ''

        isStruct = False
        isClass = False
        isString = False
        isFuncp = False
        isHandle = False
        isEnum = False
        isUnion = False  # union is only for dx12

        typeName = self.makeInvocationTypeName(value.baseType)

        if self.isStruct(typeName):
            isStruct = True
        elif self.isClass(typeName):
            isClass = True
        elif typeName in ['String', 'WString']:
            isString = True
        elif typeName == 'FunctionPtr':
            isFuncp = True
        elif typeName == 'Handle':
            isHandle = True
        elif typeName == 'Enum':
            isEnum = True
        elif typeName == 'Union':
            isUnion = True

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
                    arrayDimension = ''
                    if value.arrayDimension and value.arrayDimension > 0:
                        arrayDimension = '*'
                    # The pointer decoder will write directly to the struct member's memory.
                    body += '    wrapper->{name}{}SetExternalMemory({}value->{name}, {arraylen});\n'.format(accessOp, arrayDimension, name=value.name, arraylen=value.arrayCapacity)

                if isStruct or isString or isHandle or isClass:
                    body += '    bytes_read += wrapper->{}{}Decode({});\n'.format(value.name, accessOp, bufferArgs)
                else:
                    body += '    bytes_read += wrapper->{}.Decode{}({});\n'.format(value.name, typeName, bufferArgs)

                if not isStaticArray:
                    if isHandle or isClass:
                        # Point the real struct's member pointer to the handle pointer decoder's handle memory.
                        body += '    value->{} = nullptr;\n'.format(value.name)
                    else:
                        # Point the real struct's member pointer to the pointer decoder's memory.
                        convert_const_cast_begin = ''
                        convert_const_cast_end = ''

                        if value.fullType.find('LPCWSTR *') != -1:
                            convert_const_cast_end = ')'
                            convert_const_cast_begin = 'const_cast<LPCWSTR*>('

                        elif value.fullType.find('LPCSTR *') != -1:
                            convert_const_cast_end = ')'
                            convert_const_cast_begin = 'const_cast<LPCSTR*>('

                        body += '    value->{name} = {}wrapper->{name}{}GetPointer(){};\n'.format(convert_const_cast_begin, accessOp, convert_const_cast_end, name=value.name)
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
            elif isEnum:
                body += '    bytes_read += ValueDecoder::DecodeEnumValue({}, &(value->{}));\n'.format(bufferArgs, value.name)
            elif isUnion:
                body += '    // For Union, find the largest size in the member and encode it.\n'\
                        '    size_t union_size_max = 0, union_size = 0;\n'\

                for m in value.unionMembers:
                    body += '    if (union_size = sizeof(value->{}) > union_size_max) union_size_max = union_size;\n'.format(m[0])

                body += '    ValueDecoder::DecodeVoidArray({}, reinterpret_cast<void*>(&value->{}), union_size_max);\n'.format(bufferArgs, value.unionMembers[0][0])

            else:
                body += '    bytes_read += ValueDecoder::Decode{}Value({}, &(value->{}));\n'.format(typeName, bufferArgs, value.name)

        return body
