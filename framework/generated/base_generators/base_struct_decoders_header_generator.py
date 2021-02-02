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

from base_generator import *


# Base class for generating struct decoder header code.
class BaseStructDecodersHeaderGenerator():

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        first = True
        for struct in self.getFilteredStructNames():
            body = '' if first else '\n'
            body += 'struct Decoded_{}\n'.format(struct)
            body += '{\n'
            body += '    using struct_type = {};\n'.format(struct)
            body += '\n'
            body += '    {}* decoded_value{{ nullptr }};\n'.format(struct)

            decls = self.makeMemberDeclarations(struct, self.featureStructMembers[struct])
            if decls:
                body += '\n'
                body += decls

            body += '};'

            write(body, file=self.outFile)
            first = False

        # Write typedefs for any aliases
        for struct in self.featureStructAliases:
            body = '' if first else '\n'
            body += 'typedef Decoded_{} Decoded_{};'.format(self.featureStructAliases[struct], struct)
            write(body, file=self.outFile)
            first = False

    #
    # Determines if a Vulkan struct member needs an associated member delcaration in the decoded struct wrapper.
    def needsMemberDeclaration(self, name, value):
        if value.isPointer or value.isArray:
            return True
        elif self.isFunctionPtr(value.baseType):
            return True
        elif self.isHandle(value.baseType):
            return True
        elif self.isStruct(value.baseType):
            return True
        elif self.isGenericStructHandleValue(name, value.name):
            return True
        return False

    #
    # Determines if the struct member requires default initalization and determines the value to use.
    def getDefaultInitValue(self, type):
        if type == 'format::HandleId':
            # These types represent values recorded for Vulkan handles.
            return 'format::kNullHandleId'
        elif type == 'uint64_t':
            # These types represent values recorded for function pointers and void pointers to non-Vulkan objects.
            return '0'
        return None

    #
    # Generate the struct member declarations for the decoded struct wrapper.
    def makeMemberDeclarations(self, name, values):
        body = ''

        for value in values:
            if value.name == 'pNext' and value.baseType == 'void':
                # We have a special type to store the pNext chain
                body += '    PNextNode* pNext{ nullptr };\n'
            elif self.needsMemberDeclaration(name, value):
                typeName = self.makeDecodedParamType(value)
                if self.isStruct(value.baseType):
                    typeName = '{}*'.format(typeName)

                defaultValue = self.getDefaultInitValue(typeName)
                if defaultValue:
                    body += '    {} {}{{ {} }};\n'.format(typeName, value.name, defaultValue)
                else:
                    if self.isStruct(value.baseType):
                        body += '    {} {}{{ nullptr }};\n'.format(typeName, value.name)
                    else:
                        body += '    {} {};\n'.format(typeName, value.name)

        return body
