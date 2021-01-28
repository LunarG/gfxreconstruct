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
from base_generator import write
from dx12_base_generator import Dx12BaseGenerator


# Generates functions to create wrappers for DX12 capture based on IID.
class Dx12WrapperCreatorsBodyGenerator(Dx12BaseGenerator):
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

        self.write_include()

        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.generate_all()

        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        Dx12BaseGenerator.endFile(self)

    # Method override
    def generate_feature(self):
        Dx12BaseGenerator.generate_feature(self)

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for k2, v2 in v.classes.items():
                if (v2['declaration_method'] == 'class')\
                   and (v2['name'] != 'IUnknown'):
                    # Track class names
                    class_name = v2['name']
                    if class_name not in self.class_names:
                        self.class_names.append(class_name)

                    # Track names of classes inherited from
                    for entry in v2['inherits']:
                        decl_name = entry['decl_name']
                        if decl_name not in self.class_parent_names:
                            self.class_parent_names.append(decl_name)

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
        if final_class_name[-1].isdigit():
            for i in range(len(final_class_name) - 1, -1, -1):
                if not final_class_name[i].isdigit():
                    base_name = final_class_name[:i + 1]
                    final_number = final_class_name[i + 1:]
                    break

        class_family_names = [base_name]
        if final_number:
            # Generate with class numbers in ascending order, from 1 to n.
            for i in range(1, int(final_number) + 1):
                class_family_names.append(base_name + str(i))

        return class_family_names

    def gen_create_func_name(self, class_family_names):
        # Create a function name and argument with the first class
        # name from the class family (the first name in the list is
        # the name without a version number).
        first_class = class_family_names[0]
        return 'Wrap{}'.format(first_class)

    def gen_iid_cond_exp(self, class_family_names, align_indent):
        expr = ''

        for name in class_family_names:
            if expr:
                expr += ' ||\n' + align_indent
            expr += 'IsEqualIID(riid, IID_{})'.format(name)

        return expr

    def gen_iid_if_else_expr(self, final_class_names, indent):
        expr = ''

        for name in final_class_names:
            class_family_names = self.get_class_family_names(name)
            cond_expr = 'else if (' if expr else 'if ('
            align_indent = indent + (' ' * len(cond_expr))

            first_class = class_family_names[0]
            arg_value = 'reinterpret_cast<{}**>(object)'.format(first_class)
            func_name = self.gen_create_func_name(class_family_names)

            expr += indent + cond_expr
            expr += self.gen_iid_cond_exp(class_family_names, align_indent)
            expr += ')\n'
            expr += indent + '{\n'
            expr += self.increment_indent(indent)
            expr += '{}(riid, {});\n'.format(func_name, arg_value)
            expr += indent + '}\n'

        return expr

    def gen_catch_all_create(self, final_class_names, indent):
        decl = indent
        decl += 'void WrapObject(REFIID riid, void** object)\n'
        decl += indent + '{\n'
        indent = self.increment_indent(indent)

        decl += indent + 'if ((object == nullptr) || (*object == nullptr))\n'
        decl += indent + '{\n'
        indent = self.increment_indent(indent)
        decl += indent + 'return;\n'
        indent = self.decrement_indent(indent)
        decl += indent + '}\n'
        decl += '\n'

        decl += self.gen_iid_if_else_expr(final_class_names, indent)

        indent = self.decrement_indent(indent)
        decl += indent + '}\n'

        return decl

    def gen_wrapper_create(self, final_class_name, indent):
        class_family_names = self.get_class_family_names(final_class_name)

        first_class = class_family_names[0]
        param_type = '{}**'.format(first_class)
        func_name = self.gen_create_func_name(class_family_names)

        decl = indent
        decl += 'void {}(REFIID riid, {} object)\n'.format(
            func_name, param_type
        )
        decl += indent + '{\n'
        indent = self.increment_indent(indent)

        decl += indent + 'assert((object != nullptr) &&'\
            ' (*object != nullptr));\n'
        decl += '\n'

        # Generate logic that attempts to promote the current class type to
        # the most recent supported version.  We start with the typename of
        # the most recent class and work toward the least recent version.
        class_family_names.reverse()
        for i, name in enumerate(class_family_names):
            if i > 0:
                decl += '\n'

            arg_value = 'static_cast<{}*>(*object)'.format(name)
            cast_value = 'reinterpret_cast<{}*>(wrapper)'.format(name)

            # If the current type is already the version being checked,
            # no conversion is needed.
            decl += indent + 'if (IsEqualIID(riid, IID_{}))\n'.format(name)
            decl += indent + '{\n'
            indent = self.increment_indent(indent)

            decl += indent + 'auto wrapper = new {}_Wrapper({});\n'.format(
                name, arg_value
            )
            decl += indent + '(*object) = {};\n'.format(cast_value)
            decl += indent + 'return;\n'

            indent = self.decrement_indent(indent)
            decl += indent + '}\n'

            # Attempt to promote the object with QueryInterface.
            decl += indent + 'else\n'
            decl += indent + '{\n'
            indent = self.increment_indent(indent)

            decl += indent + '{}* converted = nullptr;\n'.format(name)
            decl += indent +'auto result = (*object)->QueryInterface(' \
                'IID_PPV_ARGS(&converted));\n'
            decl += indent + 'if (SUCCEEDED(result))\n'
            decl += indent + '{\n'
            indent = self.increment_indent(indent)

            decl += indent + '(*object)->Release();\n'
            decl += indent + 'auto wrapper = new {}_Wrapper({});\n'.format(
                name, arg_value
            )
            decl += indent + '(*object) = {};\n'.format(cast_value)
            decl += indent + 'return;\n'

            indent = self.decrement_indent(indent)
            decl += indent + '}\n'

            indent = self.decrement_indent(indent)
            decl += indent + '}\n'

        decl += '\n'
        decl += indent + 'GFXRECON_LOG_FATAL("'\
            'Failed to wrap unsupported {} object type for capture"'\
            ');\n'.format(first_class)

        indent = self.decrement_indent(indent)
        decl += indent + '}\n'

        return decl

    def generate_all(self):
        indent = ''
        final_class_names = self.get_final_class_names()

        code = '\n'
        code += self.gen_catch_all_create(final_class_names, indent)
        write(code, file=self.outFile)

        for name in final_class_names:
            code = self.gen_wrapper_create(name, indent)
            write(code, file=self.outFile)

    def write_include(self):
        code = ''
        code += '#include "generated/generated_dx12_wrapper_creators.h"\n'
        code += '\n'
        code += '#include "encode/dx12_object_wrapper_util.h"\n'
        code += '#include "generated/generated_dx12_wrappers.h"\n'
        code += '#include "util/defines.h"\n'
        code += '#include "util/logging.h"\n'
        code += '\n'
        code += '#include <cassert>\n'

        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            code += '#include <{}>\n'.format(k)

        write(code, file=self.outFile)

    def increment_indent(self, indent):
        return indent + (' ' * self.INDENT_SIZE)

    def decrement_indent(self, indent):
        return indent[:-self.INDENT_SIZE]
