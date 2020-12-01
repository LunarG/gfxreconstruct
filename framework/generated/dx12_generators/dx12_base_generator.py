#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
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

import sys
from base_generator\
    import BaseGenerator, BaseGeneratorOptions, ValueInfo, write


class DX12GeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ function declarations for DX12 API"""

    def __init__(self, blacklists=None, platformTypes=None, filename=None,
                 directory='.', prefixText='', protectFile=False,
                 protectFeature=True):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platformTypes,
            filename,
            directory,
            prefixText,
            protectFile,
            protectFeature)


class DX12BaseGenerator(BaseGenerator):

    PTR_ARRAY_SIZE_LIST = [
        ['D3D12_PIPELINE_STATE_STREAM_DESC',
            'pPipelineStateSubobjectStream', 'SizeInBytes'],
        ['D3D12_AUTO_BREADCRUMB_NODE',
            'pCommandHistory', 'BreadcrumbCount'],
        ['D3D12_AUTO_BREADCRUMB_NODE1',
            'pCommandHistory', 'BreadcrumbCount'],
        ['D3D12_AUTO_BREADCRUMB_NODE1',
            'pBreadcrumbContexts', 'BreadcrumbContextsCount'],
        ['D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES',
            'pTypes', 'Count'],
    ]

    # convert struct, class, or union type into the parsed type or convert
    # some define into plain type. The third value is pointer level.
    # If the new type is not a pointer, the value is 0. * is 1. ** is 2.
    # The Fourth value is if it's const.
    CONVERT_DEFINE_LIST = [
        [['D3D12_RECT', 'RECT'], 'tagRECT', 0, False],
        [['POINT'], 'tagPOINT', 0, False],
        [['REFIID', 'REFGUID', 'IID'], 'GUID', 0, False],
        [['DXGI_RGBA'], 'D3DCOLORVALUE', 0, False],
        [['ID3DBlob'], 'ID3D10Blob', 0, False],
        [['SECURITY_ATTRIBUTES'], '_SECURITY_ATTRIBUTES', 0, False],
        [['D3D12_PRIMITIVE_TOPOLOGY'], 'D3D_PRIMITIVE_TOPOLOGY', 0, False],
        [['LPCVOID'], 'void', 1, True],
        [['LPVOID'], 'void', 1, False],
    ]

    # override
    handleNames = ['HANDLE', 'HMONITOR', 'HWND', 'HMODULE', 'HDC']

    def __init__(self, source_dict, dx12_prefix_strings,
                 errFile=sys.stderr, warnFile=sys.stderr, diagFile=sys.stdout):
        BaseGenerator.__init__(
            self,
            processCmds=True,
            processStructs=True,
            featureBreak=True,
            errFile=errFile,
            warnFile=warnFile,
            diagFile=diagFile)
        self.source_dict = source_dict
        self.dx12_prefix_strings = dx12_prefix_strings
        self.function_declaration_set = set()

    def clean_type_define(self, type):
        rtn = ''
        types = type.split(" ")
        skip = 0

        for t in types:
            if t[0] == '(':
                skip += 1
                continue
            elif t[0] == ')':
                skip -= 1
                continue
            elif skip:
                continue
            elif t == '_SECURITY_ATTRIBUTES'\
                    or (t[0] != '_' and t != 'STDMETHODCALLTYPE'
                        and t != 'WINAPI' and t != 'IN' and t != 'OUT'):
                if rtn:
                    rtn += ' '
                rtn += t
        return rtn

    def get_value_info(self, param):
        struct_name = ''
        if 'parent' in param and 'name' in param['parent']:
            struct_name = param['parent']['name']

        name = param['name']
        full_type = param['type']
        const = False
        pointer = 0  # 1: *, 2: ** ...
        type1 = self.clean_type_define(full_type)
        types = type1.split(" ")
        base_type = ''

        for t in types:
            if t == 'const':
                const = True
            elif t == '*':
                pointer += 1
            elif t != 'struct':
                if base_type:
                    base_type += ' '
                base_type += t

        # Check if it is a array pointer, and get the size of parameter's name.
        array_length_value = ''
        if full_type[:12] == '_Field_size_':
            index_parentheses1 = full_type.find('(')
            index_parentheses2 = full_type.find(')')
            array_length_value = full_type[index_parentheses1 +
                                           2:index_parentheses2 - 1]

        elif full_type.find('( BufferCount )') != -1:
            array_length_value = 'BufferCount'

        elif full_type.find('( Dependencies )') != -1:
            array_length_value = 'Dependencies'

        else:
            index_parentheses1 = full_type.find('( Num')
            if index_parentheses1 != -1:
                index_parentheses2 = full_type[index_parentheses1 +
                                               1:
                                               ].find(')') + index_parentheses1
                index_parentheses11 = index_parentheses1
                parentheses = 0

                while True:
                    index_parentheses111 = full_type[index_parentheses11 +
                                                     1:index_parentheses2
                                                     ].find('(')
                    if index_parentheses111 == -1:
                        break
                    index_parentheses11 += index_parentheses111 + 1
                    parentheses += 1

                while parentheses > -1:
                    index_parentheses22 = full_type[index_parentheses2 + 1:
                                                    ].find(')')
                    if index_parentheses22 == -1:
                        break
                    index_parentheses2 += index_parentheses22 + 1
                    parentheses -= 1

                array_length_value = full_type[index_parentheses1 +
                                               2:index_parentheses2]

            else:
                for e in self.PTR_ARRAY_SIZE_LIST:
                    if e[0] == struct_name and name == e[1]:
                        array_length_value = e[2]

        for e in self.CONVERT_DEFINE_LIST:
            for k in e[0]:
                if base_type == k:
                    if e[3]:
                        const = True
                    base_type = e[1]
                    pointer += e[2]

        array_length = 0
        array_dimension = 0
        if 'array_size' in param:
            array_length = param['array_size']
            if 'multi_dimensional_array' in param:
                array_dimension = param['multi_dimensional_array']

        return ValueInfo(
            name=name,
            baseType=base_type,
            fullType=full_type,
            pointerCount=pointer,
            arrayLength=array_length,
            arrayLengthValue=array_length_value,
            arrayCapacity=array_length,
            arrayDimension=array_dimension,
            isConst=const)

    # Method override
    def genType(self):
        self.genStruct()

    # Method override
    def genStruct(self):
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for k2, v2 in v.classes.items():
                if v2['declaration_method'] == 'struct' and k2[-4:] != 'Vtbl'\
                   and k2.find("::<anon-union-") == -1:
                    self.featureStructMembers[k2] = self.makeValueInfo(
                        v2['properties'])

    # Method override
    def makeValueInfo(self, params):
        values = []
        for k, v in params.items():
            for p in v:
                values.append(self.get_value_info(p))
        return values

    # Method override
    def getFilteredStructNames(self):
        return self.source_dict['struct_list']

    # Method override
    def isStruct(self, type):
        struct_list = self.source_dict['struct_list']
        if type in struct_list:
            return True
        return False

    def isClass(self, type):
        class_list = self.source_dict['class_list']
        if type in class_list:
            return True
        return False

    # Method override
    def isEnum(self, type):
        enum_set = self.source_dict['enum_set']
        if type in enum_set:
            return True
        return False

    def get_union(self, type):
        if type[:12] == '<anon-union-':
            union_dict = self.source_dict['union_dict']
            return union_dict.get(type)
        return None
