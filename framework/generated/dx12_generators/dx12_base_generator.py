#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
# Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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
from base_generator import BaseGenerator, BaseGeneratorOptions, ValueInfo


class Dx12GeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ function declarations for Dx12 API."""

    def __init__(
        self,
        blacklists=None,
        platform_types=None,
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True
    ):
        BaseGeneratorOptions.__init__(
            self, blacklists, platform_types, filename, directory, prefix_text,
            protect_file, protect_feature
        )


class Dx12BaseGenerator(BaseGenerator):

    ARRAY_SIZE_LIST = [
        ['D3D12_AUTO_BREADCRUMB_NODE', 'pCommandHistory', 'BreadcrumbCount'],
        ['D3D12_AUTO_BREADCRUMB_NODE1', 'pCommandHistory', 'BreadcrumbCount'],
        [
            'D3D12_AUTO_BREADCRUMB_NODE1', 'pBreadcrumbContexts',
            'BreadcrumbContextsCount'
        ],
        [
            'D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES', 'pTypes',
            'Count'
        ],
        [
            'ID3D12GraphicsCommandList_OMSetRenderTargets',
            'pRenderTargetDescriptors',
            '(NumRenderTargetDescriptors ? (RTsSingleHandleToDescriptorRange ? 1 : NumRenderTargetDescriptors) : 0)'
        ]
    ]

    RETURN_ARRAY_SIZE_LIST = [
        [
            'ID3D12StateObjectProperties_GetShaderIdentifier',
            'D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES'
        ]
    ]

    NOT_ARRAY_DICT = {'D3D12_MESSAGE': ['pDescription']}

    # convert base type into the encode function name
    CONVERT_FUNCTION_LIST = [
        [['BYTE', 'byte', 'UINT8', 'unsigned char'], 'UInt8'],
        [['INT8'], 'Int8'],
        [['UINT16', 'unsigned short'], 'UInt16'],
        [['SHORT'], 'Int16'],
        [
            [
                'unsigned long', 'ULONG', 'DWORD', 'UINT', 'UINT32',
                'unsigned int', 'DXGI_USAGE'
            ], 'UInt32'
        ],
        [['HRESULT', 'LONG', 'BOOL', 'INT', 'int'], 'Int32'],
        [['UINT64', 'D3D12_GPU_VIRTUAL_ADDRESS'], 'UInt64'],
        [['LONG_PTR', 'SIZE_T'], 'SizeT'],
        [['FLOAT', 'float'], 'Float'],
        [['void'], 'Void'],
        [['char'], 'String'],
        [['wchar_t'], 'WString'],
        [['PFN_DESTRUCTION_CALLBACK'], 'Function'],
        [['D3D12MessageFunc'], 'Function'],
    ]

    BIT_FIELD_LIST = [
        ['D3D12_RAYTRACING_INSTANCE_DESC', 'InstanceID', ':24'],
        ['D3D12_RAYTRACING_INSTANCE_DESC', 'InstanceMask', ':8'],
        [
            'D3D12_RAYTRACING_INSTANCE_DESC',
            'InstanceContributionToHitGroupIndex', ':24'
        ],
        ['D3D12_RAYTRACING_INSTANCE_DESC', 'Flags', ':8'],
    ]

    # Dictionary for structs with members that contain objects that must be
    # unwrapped or mapped on replay, for cases such as
    # D3D12_PIPELINE_STATE_STREAM_DESC that contain an array of bytes with
    # embedded objects.
    CUSTOM_STRUCT_HANDLE_MAP = {
        'D3D12_PIPELINE_STATE_STREAM_DESC': ['pPipelineStateSubobjectStream'],
        'D3D12_STATE_SUBOBJECT': ['pDesc']
    }

    # Some functions annotate COM pointer parameters that have a void**
    # with the '_Out_' token instead of '_COM_Outptr_'.  This table
    # contains the COM pointer parameters that are not annotated as
    # COM pointers.
    COM_POINTER_PARAMS = {
        'D3D12CreateRootSignatureDeserializer':
        ['ppRootSignatureDeserializer'],
        'D3D12CreateVersionedRootSignatureDeserializer':
        ['ppRootSignatureDeserializer']
    }

    # Those classes inherit from IUnknow
    NOT_FAMILY_CLASSES = [
        'ID3D12Debug1', 'ID3D12Debug2', 'ID3D12DebugDevice1',
        'ID3D12DebugCommandList1'
    ]

    # ID3D23CommandList is top parent class for all ID3D12GraphicsCommandList[n]
    FAMILY_CLASSES_EXECPTION = {
        'ID3D12GraphicsCommandList':
        'ID3D12CommandList'
    }

    ADD_RV_ANNOTATION_METHODS = [
        'GetGPUVirtualAddress',
        'GetGPUDescriptorHandleForHeapStart',
        'GetShaderIdentifier',
    ]

    REMOVE_RV_ANNOTATION_TYPES = {
        'D3D12_GPU_VIRTUAL_ADDRESS':'',
        'D3D12_GPU_DESCRIPTOR_HANDLE':'',
        'D3D12_INDEX_BUFFER_VIEW':'',
        'D3D12_VERTEX_BUFFER_VIEW':'',
        'D3D12_STREAM_OUTPUT_BUFFER_VIEW':'',
        'D3D12_CONSTANT_BUFFER_VIEW_DESC':'',
        'D3D12_SHADER_RESOURCE_VIEW_DESC':'',
        'D3D12_WRITEBUFFERIMMEDIATE_PARAMETER':'',
        'D3D12_DISPATCH_RAYS_DESC':'',
        'D3D12_RAYTRACING_GEOMETRY_DESC':'',
        'D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC':'D3D12_RAYTRACING_GEOMETRY_DESC[]',
        'D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS':'D3D12_RAYTRACING_GEOMETRY_DESC[]',
        'D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC':'',
    }

    def __init__(
        self,
        source_dict,
        dx12_prefix_strings,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout,
        feature_break=True
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=feature_break,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )
        self.source_dict = source_dict
        self.dx12_prefix_strings = dx12_prefix_strings
        self.feature_method_params = dict()
        self.check_blacklist = False

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
            elif t == '_SECURITY_ATTRIBUTES' or (
                t[0] != '_' and t != 'STDMETHODCALLTYPE' and t != 'WINAPI'
                and t != 'IN' and t != 'OUT'
            ):
                if rtn:
                    rtn += ' '
                rtn += t
        return rtn

    def get_return_value_info(self, param_type, function_name):
        base_type = ''
        full_type = param_type
        const = False
        pointer = 0  # 1: *, 2: ** ...
        types1 = self.clean_type_define(param_type)
        types = types1.split(" ")

        for t in types:
            if t == 'const':
                const = True
            elif t == '*':
                pointer += 1
            elif t != 'struct':
                if base_type:
                    base_type += ' '
                base_type += t

        array_length = None
        array_capacity = 0
        array_dimension = 0
        for e in self.RETURN_ARRAY_SIZE_LIST:
            if e[0] == function_name:
                array_length = e[1]

        platform_base_type = None
        platform_full_type = None
        if base_type in self.PLATFORM_TYPES:
            type_info = self.PLATFORM_TYPES[base_type]
            platform_base_type = base_type
            platform_full_type = full_type
            base_type = type_info['baseType']
            full_type = full_type.replace(base_type, type_info['replaceWith'])
            replace_with = type_info['replaceWith']
            if 'const ' in replace_with:
                const = True
            pointer += replace_with.count('*')

        return ValueInfo(
            name='return_value',
            base_type=base_type,
            full_type=full_type,
            pointer_count=pointer,
            array_length=array_length,
            array_capacity=array_capacity,
            array_dimension=array_dimension,
            platform_base_type=platform_base_type,
            platform_full_type=platform_full_type,
            is_const=const
        )

    def get_value_info(self, param):
        struct_name = ''
        if ('parent' in param) and ('name' in param['parent']):
            struct_name = param['parent']['name']
            if (param['parent']['parent']
                ) and ('name' in param['parent']['parent']):
                struct_name = param['parent']['parent']['name'
                                                        ] + '_' + struct_name

        name = param['name']
        full_type = param['type']
        const = False
        pointer = 0  # 1: *, 2: ** ...
        types1 = self.clean_type_define(full_type)
        types = types1.split(" ")
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

        platform_base_type = None
        platform_full_type = None
        if base_type in self.PLATFORM_TYPES:
            type_info = self.PLATFORM_TYPES[base_type]
            platform_base_type = base_type
            platform_full_type = full_type
            base_type = type_info['baseType']
            full_type = full_type.replace(base_type, type_info['replaceWith'])
            replace_with = type_info['replaceWith']
            if 'const ' in replace_with:
                const = True
            pointer += replace_with.count('*')

        array_length = None
        array_capacity = 0
        array_dimension = 0
        if 'array_size' in param:
            array_capacity = int(param['array_size'])
            array_length = array_capacity
            if 'multi_dimensional_array' in param:
                array_dimension = int(param['multi_dimensional_array'])

        # Check if it is an array pointer, and get the size of parameter's name.
        if pointer > 0:
            for e in self.ARRAY_SIZE_LIST:
                if e[0] == struct_name and name == e[1]:
                    array_length = e[2]

            if not array_length:
                index_parentheses1 = full_type.find('(')
                if index_parentheses1 != -1:
                    index_parentheses2 = full_type[
                        index_parentheses1
                        + 1:].find(')') + index_parentheses1
                    index_parentheses11 = index_parentheses1
                    parentheses = 0

                    while True:
                        index_parentheses111 = full_type[index_parentheses11
                                                         + 1:index_parentheses2
                                                         ].find('(')
                        if index_parentheses111 == -1:
                            break
                        index_parentheses11 += index_parentheses111 + 1
                        parentheses += 1

                    while parentheses > -1:
                        index_parentheses22 = full_type[index_parentheses2
                                                        + 1:].find(')')
                        if index_parentheses22 == -1:
                            break
                        index_parentheses2 += index_parentheses22 + 1
                        parentheses -= 1

                    param = full_type[index_parentheses1
                                      + 2:index_parentheses2]
                    if param[0] != '_':
                        param_list = param.split(', ')
                        array_length = param_list[0]
                        if (
                            array_length.find('Size') != -1
                            and base_type.find('void') == -1
                        ):
                            array_length += ('/sizeof ' + base_type)
                        elif array_length[-1] == ' ':
                            array_length = array_length[:-1]

        if struct_name in self.NOT_ARRAY_DICT:
            not_array_list = self.NOT_ARRAY_DICT[struct_name]
            if name in not_array_list:
                array_length = None
                array_capacity = 0
                array_dimension = 0

        return ValueInfo(
            name=name,
            base_type=base_type,
            full_type=full_type,
            pointer_count=pointer,
            array_length=array_length,
            array_capacity=array_capacity,
            array_dimension=array_dimension,
            platform_base_type=platform_base_type,
            platform_full_type=platform_full_type,
            bitfield_width=self.get_bit_field(struct_name, name),
            is_const=const,
            is_com_outptr=self.is_com_outptr(struct_name, name, full_type)
        )

    def get_api_prefix(self):
        return 'Dx12'

    def get_prefix_from_type(self, type):
        return 'Dx12'

    def get_wrapper_prefix_from_type(self):
        return 'object_wrappers'

    def genType(self, typeinfo, name, alias):
        """Method override."""
        self.genStruct(None, None, None)
        self.genCmd(None, None, None)
        self.gen_method()

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for class_name, class_value in v.classes.items():
                if self.is_required_struct_data(class_name, class_value):
                    self.feature_struct_members[
                        class_name] = self.make_value_info(
                            class_value['properties']['public']
                        )

    def genCmd(self, cmdinfo, name, alias):
        """Method override."""
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for m in v.functions:
                if self.is_required_function_data(m):
                    name = m['name']
                    self.feature_cmd_params[name] = (
                        self.clean_type_define(m['rtnType']), '',
                        self.make_value_info(m['parameters'])
                    )

    def gen_method(self):
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for k, v in v.classes.items():
                if self.is_required_class_data(v):
                    for m in v['methods']['public']:
                        name = k + '_' + m['name']
                        self.feature_method_params[name] = (
                            self.clean_type_define(m['rtnType']), '',
                            self.make_value_info(m['parameters'])
                        )

    def get_filtered_method_names(self):
        return [
            key for key in self.feature_method_params
            if not self.is_method_black_listed(key)
        ]

    def make_value_info(self, params):
        """Method override."""
        values = []
        for p in params:
            values.append(self.get_value_info(p))
        return values

    def get_filtered_struct_names(self):
        """Method override."""
        if self.check_blacklist:
            return [
                key for key in self.source_dict['struct_dict']
                if not self.is_struct_black_listed(key)
            ]
        else:
            return self.source_dict['struct_dict'].keys()

    def get_category_type(self, type):
        if self.is_struct(type):
            return 'struct'
        elif self.is_class_type(type):
            return 'class'
        elif self.is_enum(type):
            return 'enum'
        elif self.is_union(type):
            return 'union'
        return 'base'

    def is_track_command_list(self, value):
        if self.has_class(value) or self.has_cpu_descriptor_handle(
            value
        ) or self.has_gpu_descriptor_handle(
            value
        ) or self.has_gpu_virtual_address(value):
            return True
        return False

    def has_cpu_descriptor_handle(self, value):
        if 'D3D12_CPU_DESCRIPTOR_HANDLE' in value.base_type:
            return True

        members = self.get_members(value.base_type, False)
        if members:
            for v in members:
                if self.has_cpu_descriptor_handle(v):
                    return True
        return False

    def has_gpu_descriptor_handle(self, value):
        if 'D3D12_GPU_DESCRIPTOR_HANDLE' in value.base_type:
            return True

        members = self.get_members(value.base_type, False)
        if members:
            for v in members:
                if self.has_gpu_descriptor_handle(v):
                    return True
        return False

    def has_gpu_virtual_address(self, value):
        if 'D3D12_GPU_VIRTUAL_ADDRESS' in value.base_type:
            return True

        members = self.get_members(value.base_type, False)
        if members:
            for v in members:
                if self.has_gpu_virtual_address(v):
                    return True
        return False

    def has_class(self, value):
        if self.is_class(value) or self.has_class_in_struct(
            value.base_type
        ) or (self.has_class_in_union(value)):
            return True
        return False

    def has_class_in_struct(self, type):
        struct_members = self.get_struct_members(type)
        if struct_members:
            for v in struct_members:
                if self.has_class(v):
                    return True
        return False

    def has_class_in_union(self, value):
        union_members = self.get_union_members(value.base_type)
        if union_members:
            for m in union_members:
                if self.has_class(m):
                    return True
        return False

    def get_function_arguments(self, info):
        values = list()
        for p in info['parameters']:
            values.append(self.get_value_info(p))
        return values

    def get_members(self, type, is_enum=True, is_union=True, is_struct=True):
        # D3D12's class has no members.
        if is_struct:
            members = self.get_struct_members(type)
            if members:
                return members
        if is_enum:
            members = self.get_enum_members(type)
            if members:
                return members
        if is_union:
            members = self.get_union_members(type)
            if members:
                return members
        return None

    def is_struct(self, type):
        """Method override."""
        # This type is from winnt.h. It isn't parsed. It's in custom classes.
        if type == 'LARGE_INTEGER':
            return True
        struct_dict = self.source_dict['struct_dict']
        return type in struct_dict

    def get_struct_members(self, type):
        struct_dict = self.source_dict['struct_dict']
        struct_info = struct_dict.get(type)
        if struct_info:
            members = list()
            for k, v in struct_info['properties'].items():
                for p in v:
                    members.append(self.get_value_info(p))
            return members
        return None

    def is_class_type(self, type):
        class_dict = self.source_dict['class_dict']
        return type in class_dict

    def is_class(self, value):
        """Method override. Use value, not type because it needs to check void** case."""
        if value.base_type == 'void' and value.pointer_count == 2 and value.is_com_outptr:
            return True

        class_dict = self.source_dict['class_dict']
        return value.base_type in class_dict

    def get_bit_field(self, struct_name, param_name):
        for m in self.BIT_FIELD_LIST:
            if m[0] == struct_name and m[1] == param_name:
                return m[2]
        return ''

    def is_enum(self, type):
        """Method override."""
        enum_dict = self.source_dict['enum_dict']
        return type in enum_dict

    def get_enum_members(self, type):
        enum_dict = self.source_dict['enum_dict']
        enum_info = enum_dict.get(type)
        if enum_info:
            members = list()
            for v in enum_info['values']:
                members.append([v['name'], v['value']])
            return members
        return None

    def is_union(self, type):
        if type[:12] == '<anon-union-':
            union_dict = self.source_dict['union_dict']
            return type in union_dict
        return False

    def get_union_members(self, type):
        if type[:12] == '<anon-union-':
            union_dict = self.source_dict['union_dict']
            union_info = union_dict.get(type)
            if union_info:
                members = list()
                for m in union_info['members']:
                    members.append(self.get_value_info(m))
                return members
        return None

    def convert_function(self, type):
        for e in self.CONVERT_FUNCTION_LIST:
            for k in e[0]:
                if type == k:
                    return e[1]
        return type

    def make_invocation_type_name(self, base_type):
        """Method override."""
        type = self.convert_function(base_type)
        type = BaseGenerator.make_invocation_type_name(self, type)
        if type == 'Function':
            type = 'FunctionPtr'
        else:
            union = self.is_union(type)
            if union:
                type = 'Union'
        return type

    def is_required_function_data(self, function_source_data):
        name = function_source_data['name']
        if (
            function_source_data['parent'] is None and name[:7] != 'DEFINE_'
            and name[:8] != 'DECLARE_' and name != 'InlineIsEqualGUID'
            and name != 'IsEqualGUID' and name[:8] != 'operator'
        ):
            return True
        return False

    def is_required_class_data(self, class_source_data):
        if class_source_data['declaration_method'] == 'class':
            return True
        return False

    def is_required_struct_data(self, struct_type, struct_source_data):
        if struct_source_data['declaration_method'] == 'struct' and (
            not self.check_blacklist
            or not struct_source_data['name'] in self.STRUCT_BLACKLIST
        ) and struct_type[-4:] != 'Vtbl' and struct_type.find(
            "::<anon-union-"
        ) == -1:
            return True
        return False

    def is_com_outptr(self, func_name, param_name, param_full_type):
        if 'COM_Outptr' in param_full_type:
            return True
        elif (
            func_name in self.COM_POINTER_PARAMS
            and param_name in self.COM_POINTER_PARAMS[func_name]
        ):
            return True
        return False

    def collect_struct_with_objects(self, header_dict):
        structs_with_objects = dict()

        for k, v in header_dict.items():
            for class_name, class_value in v.classes.items():
                if self.is_required_struct_data(class_name, class_value):
                    values = []
                    for prop_type, props in class_value['properties'].items():
                        for p in props:
                            value = self.get_value_info(p)

                            if (
                                self.is_struct(value.base_type) and
                                (value.full_type.find('_Out_') != -1) and
                                (value.base_type in structs_with_objects)
                            ) or (self.is_class(value)):
                                values.append(value)
                    if values:
                        structs_with_objects[class_name] = values

        return structs_with_objects

    def is_output(self, value):
        if (value.full_type.find('_Out') !=
            -1) or (value.full_type.find('_Inout') != -1):
            return True
        return False
