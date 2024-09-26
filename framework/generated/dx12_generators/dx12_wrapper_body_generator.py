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
import json
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator, Dx12GeneratorOptions


class Dx12WrapperBodyGeneratorOptions(Dx12GeneratorOptions):
    """Options for generating C++ functions for Dx12 capture."""

    def __init__(
        self,
        capture_overrides=None,  # Path to JSON file listing Vulkan API calls to override on capture.
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True
    ):
        Dx12GeneratorOptions.__init__(
            self, blacklists, platform_types, filename, directory, prefix_text,
            protect_file, protect_feature
        )
        self.capture_overrides = capture_overrides


# Generates function/class wrappers for DX12 capture.
class Dx12WrapperBodyGenerator(Dx12BaseGenerator):
    # Default C++ code indentation size.
    INDENT_SIZE = 4

    # Map of Dx12 function names to override function names.  Calls to Dx12 functions in the map
    # will be replaced by the override value.
    CAPTURE_OVERRIDES = {}

    # Functions that can activate trimming from a pre call command.
    PRECALL_TRIM_TRIGGERS = {
        'ID3D12CommandQueue': ['ExecuteCommandLists'],
    }

    # Functions that can activate trimming from a post call command.
    POSTCALL_TRIM_TRIGGERS = {
        'ID3D12CommandQueue': ['ExecuteCommandLists'],
        'IDXGISwapChain': ['Present'],
        'IDXGISwapChain1': ['Present1']
    }

    def __init__(
        self,
        source_dict,
        dx12_prefix_strings,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout
    ):
        Dx12BaseGenerator.__init__(
            self, source_dict, dx12_prefix_strings, err_file, warn_file,
            diag_file
        )

        # A list of structures with object members that need to be unwrapped.
        self.structs_with_objects = {
            **self.CUSTOM_STRUCT_HANDLE_MAP, 'D3D12_CPU_DESCRIPTOR_HANDLE':
            ['ptr']
        }
        # Unique set of names of all defined classes.
        self.class_names = []
        # Unique set of names of all class names specified as base classes.
        self.class_parent_names = []

    # Method override
    def beginFile(self, genOpts):
        Dx12BaseGenerator.beginFile(self, genOpts)

        if genOpts.capture_overrides:
            self.__load_capture_overrides(genOpts.capture_overrides)

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for class_name, class_value in v.classes.items():
                if self.is_required_class_data(class_value)\
                   and (class_value['name'] != 'IUnknown'):
                    # Track class names
                    if class_name not in self.class_names:
                        self.class_names.append(class_name)

                    # Track names of classes inherited from
                    for entry in class_value['inherits']:
                        decl_name = entry['decl_name']
                        if decl_name not in self.class_parent_names:
                            self.class_parent_names.append(decl_name)

        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

        self.newline()
        self.write_map_defs()

    # Method override
    def endFile(self):
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

    # Method override
    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)

        # Find structs with COM object members, which will need to be
        # unwrapped.
        struct_dict = self.source_dict['struct_dict']
        for s in struct_dict:
            self.check_struct_member_handles(
                s, self.structs_with_objects, None, True
            )

        header_dict = self.source_dict['header_dict']
        self.structs_with_wrap_objects = self.collect_struct_with_objects(
            header_dict
        )
        for k, v in header_dict.items():
            self.newline()
            write(self.dx12_prefix_strings.format(k), file=self.outFile)
            self.newline()

            for m in v.functions:
                if self.is_required_function_data(m):
                    self.write_function_def(m)

            for class_name, class_value in v.classes.items():
                if self.is_required_class_data(class_value)\
                   and (class_value['name'] != 'IUnknown'):
                    self.write_class_member_def(class_value)

    # Get the names of the final classes in the DX class hierarchies.
    def get_final_class_names(self):
        final_class_names = []

        for name in self.class_names:
            if name not in self.class_parent_names:
                final_class_names.append(name)

        return final_class_names

    def get_class_family_names(self, final_class_name):
        base_name = final_class_name
        final_number = ''

        # Get the number from the end of the class name.  Start from the
        # back of the string and advance forward until a non-digit character
        # is encountered.
        if (not final_class_name
            in self.NOT_FAMILY_CLASSES) and (final_class_name[-1].isdigit()):
            for i in range(len(final_class_name) - 1, -1, -1):
                if not final_class_name[i].isdigit():
                    base_name = final_class_name[:i + 1]
                    final_number = final_class_name[i + 1:]
                    break

        class_family_names = []
        if base_name in self.FAMILY_CLASSES_EXECPTION:
            class_family_names.append(self.FAMILY_CLASSES_EXECPTION[base_name])
        class_family_names.append(base_name)
        if final_number:
            # Generate with class numbers in ascending order, from 1 to n.
            for i in range(1, int(final_number) + 1):
                class_family_names.append(base_name + str(i))

        return class_family_names

    # Write the defintitions for the static class unordered_map members.
    def write_map_defs(self):
        final_class_names = self.get_final_class_names()

        for final_class_name in final_class_names:
            class_family_names = self.get_class_family_names(final_class_name)
            first_class = class_family_names[0]
            decl = '{name}_Wrapper::ObjectMap {name}_Wrapper::object_map_;\n'.format(
                name=first_class
            )
            decl += 'std::mutex {name}_Wrapper::object_map_lock_;'.format(
                name=first_class
            )
            write(decl, file=self.outFile)

    # Determine if a value is an object or a struct/union with an object.
    def is_struct_object_member(self, member):
        if self.is_class(member) or (
            self.is_struct(member.base_type) and
            (member.name in self.structs_with_objects)
        ):
            return True
        elif self.is_union(member.base_type):
            # Check the anonymous union for objects.  This step
            # should not ignore blacklisted struct types.  It
            # needs to process all struct types to build an
            # accurate list of structs that contain objects.
            union_members = self.get_union_members(member.base_type)
            for union_info in union_members:
                if self.is_struct(union_info.base_type):
                    umembers = self.feature_struct_members[union_info.base_type
                                                           ]
                    for umember in umembers:
                        if self.is_struct_object_member(umember):
                            return True
                elif union_info.base_type in self.source_dict['class_dict']:
                    return True
        return False

    # Determine if the specified class should contain a map of object pointers to wrapper pointers.
    def is_map_class(self, name):
        map_classes = []
        final_class_names = self.get_final_class_names()

        for final_class_name in final_class_names:
            class_family_names = self.get_class_family_names(final_class_name)
            first_class = class_family_names[0]
            map_classes.append(first_class)

        return name in map_classes

    # Check the parameter list for a pointer to an object that is being
    # created or retrieved, which needs to be wrapped.
    def get_object_creation_params(self, param_info):
        refiid_value = None
        create_values = []
        create_wrap_struct = []

        # Check for pairs of parameters with REFIID and void** types or a
        # parameter with a non-const double pointer class type.
        for param in param_info:
            value = self.get_value_info(param)

            if (value.base_type != 'LARGE_INTEGER') and self.is_struct(
                value.base_type
            ) and (value.full_type.find('_Out_') != -1):
                if value.base_type in self.structs_with_wrap_objects:
                    create_wrap_struct.append(value)

            data = []
            if not refiid_value:
                if ((value.base_type == 'GUID') and (value.name != "rclsid") and (value.name != "CreatorID") and (value.name != "clsid")):
                    refiid_value = value
                elif (
                    self.is_class(value)
                    and ((value.pointer_count == 2) and (not value.is_const))
                ):
                    cast_expr = 'reinterpret_cast<void**>({})'.format(
                        value.name
                    )
                    create_values.append(
                        [
                            'IID_' + value.base_type, cast_expr,
                            value.array_length
                        ]
                    )
            else:
                if (
                    (value.base_type == 'void') and (value.pointer_count == 2)
                    and (not value.is_const)
                ):
                    create_values.append(
                        [refiid_value.name, value.name, value.array_length]
                    )
                refiid_value = None

        return create_values, create_wrap_struct

    # Check for input parameters that need to be unwrapped.
    def get_wrapped_object_params(self, param_info):
        wrapped_values = {}

        # Check for input parameters with a class type.
        for param in param_info:
            value = self.get_value_info(param)
            if self.is_class(value) and (
                (value.pointer_count == 1) or
                ((value.pointer_count == 2) and value.is_const)
            ):
                wrapped_values[value.name] = value

        return wrapped_values

    def gen_wrap_object(self, return_type, param_info, indent):
        expr = ''
        params_wrap_obejct, params_wrap_struct = self.get_object_creation_params(
            param_info
        )

        if params_wrap_obejct or params_wrap_struct:
            expr += '\n'
            if return_type == 'HRESULT':
                expr += indent + 'if (SUCCEEDED(result))\n'
                expr += indent + '{\n'
                indent = self.increment_indent(indent)

            for tuple in params_wrap_obejct:
                if not tuple[2]:
                    expr += indent + 'WrapObject({}, {}, nullptr);\n'.format(
                        tuple[0], tuple[1]
                    )
                else:
                    array_length = tuple[2]
                    if array_length.startswith('* '):
                        array_length = '({} != nullptr) ? {} : 0'.format(
                            array_length[2:], array_length.replace(' ', '')
                        )
                    expr += indent + 'WrapObjectArray({}, {}, {}, nullptr);\n'.format(
                        tuple[0], tuple[1], array_length
                    )

            for value in params_wrap_struct:
                if value.pointer_count == 2:
                    expr += indent + 'WrapStruct(*{});\n'.format(value.name)
                else:
                    expr += indent + 'WrapStruct({});\n'.format(value.name)

            if return_type == 'HRESULT':
                indent = self.decrement_indent(indent)
                expr += indent + '}\n'

        return expr

    def gen_function_pre_call(self, name, wrapped_args, indent):
        expr = indent + 'CustomWrapperPreCall<format::ApiCallId::ApiCall_{}>::Dispatch(\n'.format(
            name
        )

        indent = self.increment_indent(indent)
        expr += indent + 'manager'
        if wrapped_args:
            expr += ',\n'
            expr += wrapped_args
        expr += ');\n'

        return expr

    def gen_function_post_call(self, return_type, name, wrapped_args, indent):
        expr = indent + 'CustomWrapperPostCall<format::ApiCallId::ApiCall_{}>::Dispatch(\n'.format(
            name
        )

        indent = self.increment_indent(indent)
        expr += indent + 'manager'
        if return_type != 'void':
            expr += ',\n'
            expr += indent + 'result'
        if wrapped_args:
            expr += ',\n'
            expr += wrapped_args
        expr += ');\n'

        return expr

    def gen_method_pre_call(
        self, class_name, method_name, wrapped_args, indent
    ):
        expr = indent + 'CustomWrapperPreCall<format::ApiCallId::ApiCall_{}_{}>::Dispatch(\n'.format(
            class_name, method_name
        )

        indent = self.increment_indent(indent)
        expr += indent + 'manager,\n'

        if (class_name in self.PRECALL_TRIM_TRIGGERS) and (method_name in self.PRECALL_TRIM_TRIGGERS[class_name]):
            expr += indent + 'shared_api_call_lock,\n'

        expr += indent + 'this'
        if wrapped_args:
            expr += ',\n'
            expr += wrapped_args
        expr += ');\n'

        return expr

    def gen_remove_rv_annotation_call(
        self, class_name, method_name, method_parameters, indent
    ):
        expr = ''
        for param in method_parameters:
            param_name = param['name']
            param_info = self.get_value_info(param)
            param_type = param_info.base_type
            param_ptr_length = param_info.array_length
            if (param_type in self.REMOVE_RV_ANNOTATION_TYPES):
                if (param_info.is_pointer):
                    if (param_ptr_length):
                        expr += indent + 'std::unique_ptr<' + param_type + '[]> ' + param_name + '_unannotated = nullptr;\n'
                        expr += indent + 'if((manager->IsAnnotated() == true) && (' + param_ptr_length + ' != 0) && (' + param_name + ' != nullptr))\n'
                        expr += indent + '{\n'
                        indent = self.increment_indent(indent)
                        expr += indent + param_name + '_unannotated = RvAnnotationUtil::RemoveStructArrayRvAnnotations(' + param_name + ', ' + param_ptr_length + ');\n'
                        expr += indent + param_name + ' = ' + param_name + '_unannotated.get();\n'
                        indent = self.decrement_indent(indent)
                        expr += indent + '}\n\n'
                    else:
                        dependency_type = self.REMOVE_RV_ANNOTATION_TYPES[
                            param_type]
                        expr += indent + 'std::unique_ptr<' + param_type + '> ' + param_name + '_unannotated = nullptr;\n'
                        if (dependency_type):
                            expr += indent + 'std::unique_ptr<' + dependency_type + '> ' + param_name + '_dependency = nullptr;\n'
                        expr += indent + 'if((manager->IsAnnotated() == true) && (' + param_name + ' != nullptr))\n'
                        expr += indent + '{\n'
                        indent = self.increment_indent(indent)
                        expr += indent + param_name + '_unannotated = RvAnnotationUtil::RemoveStructRvAnnotations(' + param_name
                        if (dependency_type):
                            expr += ', ' + param_name + '_dependency'
                        expr += ');\n'
                        expr += indent + param_name + ' = ' + param_name + '_unannotated.get();\n'
                        indent = self.decrement_indent(indent)
                        expr += indent + '}\n\n'
                else:
                    expr += indent
                    expr += 'RvAnnotationUtil::RemoveRvAnnotation(' + param_name + ');\n\n'

        return expr

    def gen_add_rv_annotation_call(self, method_name, return_name, indent):
        expr = ''
        if (method_name in self.ADD_RV_ANNOTATION_METHODS):
            expr += '\n'
            expr += indent + 'RvAnnotationUtil::AddRvAnnotation(&' + return_name + ');\n'
        return expr

    def gen_method_post_call(
        self, return_type, class_name, method_name, wrapped_args, indent
    ):
        expr = indent + 'CustomWrapperPostCall<format::ApiCallId::ApiCall_{}_{}>::Dispatch(\n'.format(
            class_name, method_name
        )

        indent = self.increment_indent(indent)
        expr += indent + 'manager,\n'

        if (class_name in self.POSTCALL_TRIM_TRIGGERS) and (method_name in self.POSTCALL_TRIM_TRIGGERS[class_name]):
            expr += indent + 'shared_api_call_lock,\n'

        expr += indent + 'this'
        if return_type != 'void':
            expr += ',\n'
            expr += indent + 'result'
        if wrapped_args:
            expr += ',\n'
            expr += wrapped_args
        expr += ');\n'

        return expr

    def write_function_def(self, function, indent=''):
        return_type = function['rtnType'].replace(' *', '*')
        name = function['name']
        table = 'manager->GetD3D12DispatchTable()' if 'D3D12' in name\
           else 'manager->GetDxgiDispatchTable()'
        parameters = function['parameters']

        expr = indent + '{} {}('.format(return_type, name)
        if parameters:
            expr += '\n'
            expr += self.make_param_decl_list(
                parameters, self.increment_indent(indent)
            )
        expr += ')\n'
        expr += indent + '{\n'

        # Remove calling convention macros from return type.
        return_type = self.process_return_type(return_type)

        # Begin function body
        indent = self.increment_indent(indent)

        if return_type != 'void':
            expr += indent + return_type + ' result{};\n'
            expr += '\n'

        expr += indent + 'auto manager = D3D12CaptureManager::Get();\n'
        expr += indent + 'auto call_scope = manager->IncrementCallScope();\n'
        expr += '\n'

        # Generate API call with input object unwrapping and output object wrapping
        expr += indent + 'if (call_scope == 1)\n'
        expr += indent + '{\n'
        indent = self.increment_indent(indent)

        expr += indent + 'auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();\n'
        expr += indent + 'std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;\n'
        expr += indent + 'std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;\n'
        expr += indent + 'if (force_command_serialization)\n'
        expr += indent + '{\n'
        expr += indent + '    exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();\n'
        expr += indent + '}\n'
        expr += indent + 'else\n'
        expr += indent + '{\n'
        expr += indent + '    shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();\n'
        expr += indent + '}\n'
        expr += '\n'

        wrapped_args = ''
        unwrapped_args = ''
        need_unwrap_memory = False
        if parameters:
            wrapped_args, unused = self.make_arg_list(
                parameters, False, self.increment_indent(indent)
            )
            unwrapped_args, need_unwrap_memory = self.make_arg_list(
                parameters, True, self.increment_indent(indent)
            )

        # Add custom pre call action.
        expr += self.gen_function_pre_call(name, wrapped_args, indent)
        expr += '\n'

        if need_unwrap_memory:
            expr += indent + 'auto unwrap_memory = '\
                'manager->GetHandleUnwrapMemory();\n'
            expr += '\n'

        expr += indent
        if return_type != 'void':
            expr += 'result = '

        if name in self.CAPTURE_OVERRIDES['functions']:
            expr += '{}('.format(self.CAPTURE_OVERRIDES['functions'][name])
        else:
            expr += '{}.{}('.format(table, name)

        if unwrapped_args:
            expr += '\n'
            expr += unwrapped_args
        expr += ');\n'

        expr += self.gen_wrap_object(return_type, parameters, indent)

        expr += '\n'
        expr += indent + 'Encode_{}('.format(name)
        encode_args = ''
        if wrapped_args or (return_type != 'void'):
            expr += '\n'
            if return_type != 'void':
                encode_args += self.increment_indent(indent) + 'result'
            if wrapped_args:
                if encode_args:
                    encode_args += ',\n'
                encode_args += wrapped_args
        expr += encode_args + ');\n'

        # Add custom post call action.
        expr += '\n'
        expr += self.gen_function_post_call(
            return_type, name, wrapped_args, indent
        )

        indent = self.decrement_indent(indent)
        expr += indent + '}\n'

        # Generate API call without object wrapping/unwrapping
        expr += indent + 'else\n'
        expr += indent + '{\n'
        indent = self.increment_indent(indent)

        expr += indent
        if return_type != 'void':
            expr += 'result = '
        expr += '{}.{}('.format(table, name)
        if wrapped_args:
            expr += '\n'
            expr += wrapped_args
        expr += ');\n'

        indent = self.decrement_indent(indent)
        expr += indent + '}\n'

        # End method body
        expr += '\n'
        expr += indent + 'manager->DecrementCallScope();\n'

        if return_type != 'void':
            expr += '\n'
            expr += indent + 'return result;\n'

        indent = self.decrement_indent(indent)
        expr += indent + '}\n'

        write(expr, file=self.outFile)

    def write_common_class_methods(self, class_name, class_info, indent):
        is_map_class = self.is_map_class(class_name)
        inherits = class_info['inherits']
        expr = ''

        # Constructor
        initlist_expr = ''
        for entry in inherits:
            if initlist_expr:
                initlist_expr += ', '
            initlist_expr += '{}_Wrapper(riid, object, resources,'\
                ' destructor)'.format(entry['decl_name'])
        expr += indent + '{name}_Wrapper::{name}_Wrapper(REFIID riid,'\
            ' IUnknown* object, DxWrapperResources* resources,' \
            ' const std::function<void(IUnknown_Wrapper*)>& destructor)'\
            ' : {}\n'.format(
                initlist_expr, name=class_name
            )
        expr += indent + '{\n'
        if is_map_class:
            indent = self.increment_indent(indent)
            expr += indent + 'info_ = std::make_shared<{}Info>();\n'.format(
                class_name
            )
            expr += indent + 'info_->SetWrapper(this);\n'
            expr += indent + 'AddWrapperMapEntry(object, this, object_map_,'\
                ' object_map_lock_);\n'
            indent = self.decrement_indent(indent)
        expr += indent + '}\n'

        if is_map_class:
            # Add a destructor to remove the object from the map.
            expr += '\n'
            expr += indent + '{name}_Wrapper::~{name}_Wrapper()\n'.format(
                name=class_name
            )
            expr += indent + '{\n'
            indent = self.increment_indent(indent)
            expr += indent + 'CustomWrapperDestroyCall(this);\n'
            expr += indent + 'RemoveWrapperMapEntry(GetWrappedObjectAs<{}>(),'\
                ' object_map_, object_map_lock_);\n'.format(class_name)
            expr += indent + 'D3D12CaptureManager::Get()->ProcessWrapperDestroy(this);\n'
            expr += indent + 'info_->SetWrapper(nullptr);\n'
            indent = self.decrement_indent(indent)
            expr += indent + '}\n'

            # Add a function to retreive an existing wrapper for an object.
            expr += '\n'
            expr += indent + '{name}_Wrapper* {name}_Wrapper::'\
                'GetExistingWrapper(IUnknown* object)\n'.format(name=class_name)
            expr += indent + '{\n'
            indent = self.increment_indent(indent)
            expr += indent + 'return FindMapEntry<{}_Wrapper>(object,'\
                ' object_map_, object_map_lock_);\n'.format(class_name)
            indent = self.decrement_indent(indent)
            expr += indent + '}\n'

        write(expr, file=self.outFile)

    def write_class_member_def(self, class_info, indent=''):
        class_name = class_info['name']
        methods = class_info['methods']['public']
        wrapper = class_name + '_Wrapper'

        self.write_common_class_methods(class_name, class_info, indent)

        for method in methods:
            return_type = method['rtnType'].replace(' *', '*')
            method_name = method['name']
            parameters = method['parameters']
            expr = indent + '{} {}::{}('.format(
                return_type, wrapper, method_name
            )
            if parameters:
                expr += '\n'
                expr += self.make_param_decl_list(
                    method['parameters'], self.increment_indent(indent)
                )
            expr += ')\n'
            expr += indent + '{\n'

            # Remove calling convention macros from return type.
            return_type = self.process_return_type(return_type)

            # Begin method body
            indent = self.increment_indent(indent)

            if return_type != 'void':
                expr += indent + return_type + ' result{};\n'
                expr += '\n'

            expr += indent + 'auto manager = D3D12CaptureManager::Get();\n'
            expr += indent + 'auto call_scope = manager->IncrementCallScope();\n'
            expr += '\n'

            # Generate API call with input object unwrapping and output object wrapping
            expr += indent + 'if (call_scope == 1)\n'
            expr += indent + '{\n'
            indent = self.increment_indent(indent)

            expr += indent + 'auto force_command_serialization = D3D12CaptureManager::Get()->GetForceCommandSerialization();\n'
            expr += indent + 'std::shared_lock<CommonCaptureManager::ApiCallMutexT> shared_api_call_lock;\n'
            expr += indent + 'std::unique_lock<CommonCaptureManager::ApiCallMutexT> exclusive_api_call_lock;\n'
            expr += indent + 'if (force_command_serialization)\n'
            expr += indent + '{\n'
            expr += indent + '    exclusive_api_call_lock = D3D12CaptureManager::AcquireExclusiveApiCallLock();\n'
            expr += indent + '}\n'
            expr += indent + 'else\n'
            expr += indent + '{\n'
            expr += indent + '    shared_api_call_lock = D3D12CaptureManager::AcquireSharedApiCallLock();\n'
            expr += indent + '}\n'

            expr += '\n'

            # Add pre process to annotation
            expr += self.gen_remove_rv_annotation_call(
                class_name, method_name, parameters, indent
            )

            wrapped_args = ''
            unwrapped_args = ''
            trim_draw_calls_wrapped_args = ''
            trim_draw_calls_unwrapped_args = ''
            need_unwrap_memory = False
            if parameters:
                wrapped_args, unused = self.make_arg_list(
                    parameters, False, self.increment_indent(indent)
                )
                unwrapped_args, need_unwrap_memory = self.make_arg_list(
                    parameters, True, self.increment_indent(indent)
                )
                trim_draw_calls_wrapped_args, unused = self.make_arg_list(
                    parameters, False, self.increment_indent(self.increment_indent(self.increment_indent(indent)))
                )
                trim_draw_calls_unwrapped_args, need_unwrap_memory = self.make_arg_list(
                    parameters, True, self.increment_indent(self.increment_indent(self.increment_indent(indent)))
                )

            # Add custom pre call action.
            expr += self.gen_method_pre_call(
                class_name, method_name, wrapped_args, indent
            )
            expr += '\n'

            if need_unwrap_memory:
                expr += indent + 'auto unwrap_memory = '\
                    'manager->GetHandleUnwrapMemory();\n'
                expr += '\n'

            expr += indent
            if return_type != 'void':
                expr += 'result = '

            is_override = False
            if (class_name in self.CAPTURE_OVERRIDES['classmethods']) and (
                method_name
                in self.CAPTURE_OVERRIDES['classmethods'][class_name]
            ):
                is_override = True
                expr += '{}('.format(
                    self.CAPTURE_OVERRIDES['classmethods'][class_name]
                    [method_name]
                )
                if unwrapped_args:
                    unwrapped_args = self.increment_indent(
                        indent
                    ) + 'this,\n' + wrapped_args
                else:
                    unwrapped_args = self.increment_indent(indent) + 'this\n'
            else:
                expr += 'GetWrappedObjectAs<{}>()->{}('.format(
                    class_name, method_name
                )

            if unwrapped_args:
                expr += '\n'
                expr += unwrapped_args
            expr += ');\n'

            expr += self.gen_wrap_object(return_type, parameters, indent)

            expr += '\n'

            expr += indent + 'Encode_{}_{}(\n'.format(class_name, method_name)
            encode_args = self.increment_indent(indent) + 'this'
            if wrapped_args or (return_type != 'void'):
                if return_type != 'void':
                    encode_args += ',\n'
                    encode_args += self.increment_indent(indent) + 'result'
                if wrapped_args:
                    encode_args += ',\n'
                    encode_args += wrapped_args
            expr += encode_args + ');\n'

            if is_override is False and 'ID3D12GraphicsCommandList' in class_name:
                indent1 = self.increment_indent(indent)
                indent2 = self.increment_indent(indent1)
                indent3 = self.increment_indent(indent2)
                indent4 = self.increment_indent(indent3)
                expr += '\n'
                expr += indent + 'if(manager->GetTrimBoundary() == CaptureSettings::TrimBoundary::kDrawCalls)\n'
                expr += indent + '{\n'
                expr += indent1 + 'manager->DecrementCallScope();\n'
                expr += indent1 + 'auto trim_draw_calls_command_sets = manager->GetCommandListsForTrimDrawCalls(this, format::ApiCall_{}_{});\n'.format(class_name, method_name)
                expr += indent1 + 'for(auto& command_set : trim_draw_calls_command_sets)\n'
                expr += indent1 + '{\n'

                if class_name != 'ID3D12GraphicsCommandList':
                    expr += indent2 + 'graphics::dx12::{}ComPtr command_list = nullptr;\n'.format(class_name)
                    expr += indent2 + 'command_set.list->QueryInterface(IID_PPV_ARGS(&command_list));\n'
                    expr += indent2 + 'auto* wrapper = reinterpret_cast<{}_Wrapper*>(command_list.GetInterfacePtr());\n'.format(class_name)
                else:
                    expr += indent2 + 'auto* wrapper = reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(command_set.list.GetInterfacePtr());\n'

                if return_type != 'void':
                    expr += indent2 + 'HRESULT result_trim_draw_calls = wrapper'
                else:
                    expr += indent2 + 'wrapper'

                expr += "->{}(".format(method_name)                
                if trim_draw_calls_wrapped_args:
                    expr += "\n"
                    expr += trim_draw_calls_wrapped_args
                expr += ");\n"

                if return_type != 'void':               
                    expr += indent2 + 'if (result != result_trim_draw_calls)\n'
                    expr += indent2 + '{\n'
                    expr += indent3 + 'GFXRECON_LOG_WARNING("Splitting commandlists of {}::{} get different results: %s and %s",\n'.format(class_name, method_name)
                    expr += indent4 + 'decode::enumutil::GetResultValueString(result).c_str(),\n'
                    expr += indent4 + 'decode::enumutil::GetResultValueString(result_trim_draw_calls).c_str());\n'
                    expr += indent2 + '}\n'

                expr += indent1 + '}\n'
                expr += indent1 + 'manager->IncrementCallScope();\n'
                expr += indent + '}\n'

            # Add custom post call action.
            expr += '\n'
            expr += self.gen_method_post_call(
                return_type, class_name, method_name, wrapped_args, indent
            )

            # Add post process to annotation
            expr += self.gen_add_rv_annotation_call(
                method_name, 'result', indent
            )

            indent = self.decrement_indent(indent)
            expr += indent + '}\n'

            # Generate API call without object wrapping/unwrapping
            expr += indent + 'else\n'
            expr += indent + '{\n'
            indent = self.increment_indent(indent)

            expr += indent
            if return_type != 'void':
                expr += 'result = '
            expr += 'GetWrappedObjectAs<{}>()->{}('.format(
                class_name, method_name
            )
            if wrapped_args:
                expr += '\n'
                expr += wrapped_args
            expr += ');\n'

            indent = self.decrement_indent(indent)
            expr += indent + '}\n'

            # End method body
            expr += '\n'
            expr += indent + 'manager->DecrementCallScope();\n'

            if return_type != 'void':
                expr += '\n'
                expr += indent + 'return result;\n'

            indent = self.decrement_indent(indent)
            expr += indent + '}\n'

            write(expr, file=self.outFile)

    def make_param_decl_list(self, param_info, indent='    '):
        space_index = 0
        parameters = ''
        for p in param_info:
            if parameters:
                parameters += ',\n'
            parameters += indent
            parameters += self.clean_type_define(p['type'])
            parameters += ' '
            parameters += p['name']

            if 'array_size' in p:
                array_length = p['array_size']
                parameters += ' '

                if 'multi_dimensional_array' in p:
                    p['multi_dimensional_array']

                    if 'multi_dimensional_array_size' in p:
                        multi_dimensional_array_size = \
                            p['multi_dimensional_array_size']

                        array_sizes = multi_dimensional_array_size.split("x")
                        for size in array_sizes:
                            parameters += '['
                            parameters += size
                            parameters += ']'
                else:
                    parameters += '['
                    parameters += array_length
                    parameters += ']'

            while True:
                space_index = parameters.find(' ', space_index) + 1

                if (space_index != 0) and (
                    parameters[space_index] == '*'
                    or parameters[space_index - 2] == '('
                    or parameters[space_index] == '('
                    or parameters[space_index] == ')'
                ):
                    parameters = parameters[:space_index
                                            - 1] + parameters[space_index:]
                elif space_index == 0:
                    break
        return parameters

    def make_arg_list(self, param_info, unwrap_objects, indent='    '):
        space_index = 0
        args = ''
        need_unwrap_memory = False
        wrappers = self.get_wrapped_object_params(param_info)

        for p in param_info:
            name = p['name']
            if unwrap_objects:
                value = self.get_value_info(p)
                if name in wrappers:
                    if value.array_length:
                        need_unwrap_memory = True

                        name = 'UnwrapObjects<{}>'\
                            '({}, {}, unwrap_memory)'.format(
                                wrappers[name].base_type, name, value.array_length)
                    else:
                        name = 'encode::GetWrappedObject<{}>({})'\
                            .format(wrappers[name].base_type, name)
                else:
                    if value.base_type in self.structs_with_objects:
                        need_unwrap_memory = True

                        if value.is_pointer:
                            if value.array_length:
                                name = 'UnwrapStructArrayObjects({}, {}'.format(
                                    name, value.array_length
                                )
                            else:
                                name = 'UnwrapStructPtrObjects({}'.format(name)
                        else:
                            if value.array_length:
                                name = 'UnwrapStructArrayObjects({}, {}'.format(
                                    name, value.array_length
                                )
                            else:
                                name = '*UnwrapStructPtrObjects(&{}'.format(
                                    name
                                )

                        name += ', unwrap_memory)'

            if args:
                args += ',\n'
            args += indent
            args += name

        return args, need_unwrap_memory

    def process_return_type(self, rt):
        return rt.replace('STDMETHODCALLTYPE', '').replace('WINAPI',
                                                           '').strip()

    def write_include(self):
        code = ''

        code += '#include "generated/generated_dx12_struct_wrappers.h"\n'
        code += '#include "generated/generated_dx12_wrappers.h"\n'
        code += '\n'
        code += '#include "encode/custom_dx12_api_call_encoders.h"\n'
        code += '#include "encode/custom_dx12_struct_unwrappers.h"\n'
        code += '#include "encode/custom_dx12_wrapper_commands.h"\n'
        code += '#include "encode/d3d12_capture_manager.h"\n'
        code += '#include "encode/d3d12_dispatch_table.h"\n'
        code += '#include "encode/dx12_object_wrapper_util.h"\n'
        code += '#include "encode/dxgi_dispatch_table.h"\n'
        code += '#include "encode/dx12_rv_annotation_util.h"\n'
        code += '#include "decode/dx12_enum_util.h"\n'
        code += '#include "generated/generated_dx12_api_call_encoders.h"\n'
        code += '#include "generated/generated_dx12_struct_unwrappers.h"\n'
        code += '#include "generated/generated_dx12_wrapper_creators.h"\n'
        code += '#include "util/defines.h"\n'
        code += '\n'

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)

        write(code, file=self.outFile)

    def increment_indent(self, indent):
        return indent + (' ' * self.INDENT_SIZE)

    def decrement_indent(self, indent):
        return indent[:-self.INDENT_SIZE]

    def __load_capture_overrides(self, filename):
        self.CAPTURE_OVERRIDES = json.loads(open(filename, 'r').read())
