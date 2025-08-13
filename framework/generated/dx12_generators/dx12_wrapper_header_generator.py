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
from dx12_base_generator import Dx12BaseGenerator, write


# Generates function/class wrappers for DX12 capture.
class Dx12WrapperHeaderGenerator(Dx12BaseGenerator):
    # Default C++ code indentation size.
    INDENT_SIZE = 4

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

        # Unique set of names of all defined classes.
        self.class_names = []
        # Unique set of names of all class names specified as base classes.
        self.class_parent_names = []

    # Method override
    def beginFile(self, genOpts):
        Dx12BaseGenerator.beginFile(self, genOpts)

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

    # Method override
    def endFile(self):
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

    # Method override
    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            self.newline()
            write(self.dx12_prefix_strings.format(k), file=self.outFile)
            self.newline()

            for m in v.functions:
                if self.is_required_function_data(m) and (
                    not self.is_cmd_black_listed(m['name'])
                ):
                    self.write_function_decl(m)

            for class_name, class_value in v.classes.items():
                if self.is_required_class_data(class_value)\
                   and (class_value['name'] != 'IUnknown'):
                    self.write_class_decl(class_value)

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

    # Determine if the specified class should contain a map of object pointers to wrapper pointers.
    def is_map_class(self, name):
        map_classes = []
        final_class_names = self.get_final_class_names()

        for final_class_name in final_class_names:
            class_family_names = self.get_class_family_names(final_class_name)
            first_class = class_family_names[0]
            map_classes.append(first_class)

        return name in map_classes

    def write_include(self):
        code = ''
        code += '#include "encode/dx12_object_wrapper_info.h\"\n'
        code += '#include "encode/iunknown_wrapper.h\"\n'
        code += '#include "util/defines.h"\n'
        code += '\n'

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)

        code += '\n'
        code += '#include <mutex>\n'
        code += '#include <unordered_map>\n'

        write(code, file=self.outFile)

    def write_function_decl(self, function, indent=''):
        return_type = function['rtnType'].replace(' *', '*')
        expr = indent + '{} {}('.format(return_type, function['name'])
        if function['parameters']:
            expr += '\n'
            expr += self.make_param_decl_list(
                function['parameters'], self.increment_indent(indent)
            )
        expr += ');\n'
        write(expr, file=self.outFile)

    def write_class_decl(self, class_info, indent=''):
        name = class_info['name']
        inherits = class_info['inherits']
        methods = class_info['methods']['public']
        is_map_class = self.is_map_class(name)

        # Make the inheritance list
        inherit_expr = ''
        for entry in inherits:
            if inherit_expr:
                inherit_expr += ', '
            inherit_expr += '{} {}_Wrapper'.format(
                entry['access'], entry['decl_name']
            )

        # Begin class declaration
        expr = indent + 'class {}_Wrapper'.format(name)
        if inherit_expr:
            expr += ' : {}'.format(inherit_expr)
        expr += '\n'
        expr += indent + '{\n'
        expr += indent + '  public:\n'
        indent = self.increment_indent(indent)

        # Constructor
        expr += indent + '{name}_Wrapper(REFIID riid, IUnknown* object,'\
            ' DxWrapperResources* resources = nullptr,' \
            ' const std::function<void(IUnknown_Wrapper*)>& destructor' \
            ' = [](IUnknown_Wrapper* u){{' \
            ' delete reinterpret_cast<{name}_Wrapper*>(u); }});\n'.format(
                name=name
            )

        if is_map_class:
            # Add a destructor to remove the object from the map.
            expr += '\n'
            expr += indent + '~{}_Wrapper();\n'.format(name)

            # Add a function to retreive an existing wrapper for an object.
            expr += '\n'
            expr += indent + 'static {}_Wrapper* GetExistingWrapper'\
                '(IUnknown* object);\n'.format(name)

            # Object info "getters"
            expr += '\n'
            expr += indent + 'std::shared_ptr<const {}Info> GetObjectInfo() const'.format(
                name
            )
            expr += ' { return info_; }\n'
            expr += '\n'
            expr += indent + 'std::shared_ptr<{}Info> GetObjectInfo()'.format(
                name
            )
            expr += ' { return info_; }\n'

        # Public methods
        for method in methods:
            return_type = method['rtnType'].replace(' *', '*')
            expr += '\n'
            expr += indent + 'virtual {} {}('.format(
                return_type, method['name']
            )
            if method['parameters']:
                expr += '\n'
                expr += self.make_param_decl_list(
                    method['parameters'], self.increment_indent(indent)
                )
            expr += ');\n'

        # Pointer to wrapped object
        expr += '\n'

        if is_map_class:
            expr += indent[:-2] + 'private:\n'
            expr += indent + '// Map to prevent creation of more than one interface wrapper per object.\n'
            expr += indent + 'typedef std::unordered_map<IUnknown*, {}_Wrapper*> ObjectMap;\n'.format(
                name
            )
            expr += indent + 'static ObjectMap  object_map_;\n'
            expr += indent + 'static std::mutex object_map_lock_;\n'
            expr += '\n'
            expr += indent + 'std::shared_ptr<{}Info> info_;\n'.format(name)

        # End class declaration
        indent = self.decrement_indent(indent)
        expr += indent + '};\n'

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

    def increment_indent(self, indent):
        return indent + (' ' * self.INDENT_SIZE)

    def decrement_indent(self, indent):
        return indent[:-self.INDENT_SIZE]
