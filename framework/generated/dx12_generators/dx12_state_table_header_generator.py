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
from base_generator_defines import write
from dx12_base_generator import Dx12BaseGenerator


# Generates declarations for functions for DX12 state table
class Dx12StateTableHeaderGenerator(Dx12BaseGenerator):
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

    def generate_all(self):
        indent = ''
        self.newline()
        final_class_names = self.get_final_class_names()
        self.insert_wrapper_code = ''
        self.remove_wrapper_code = ''
        self.visit_wrappers_code = ''
        self.get_wrapper_code = ''
        self.map_code = ''

        for final_class_name in final_class_names:
            class_family_names = self.get_class_family_names(final_class_name)
            name_wrapper = class_family_names[0] + '_Wrapper'

            self.insert_wrapper_code += '    bool InsertWrapper(format::HandleId id, {0}* wrapper) {{ return InsertEntry(id, wrapper, {0}_map_); }}\n'.format(
                name_wrapper
            )
            self.remove_wrapper_code += '    bool RemoveWrapper(const {0}* wrapper) {{ return RemoveEntry(wrapper, {0}_map_); }}\n'.format(
                name_wrapper
            )
            self.visit_wrappers_code += '    void VisitWrappers(std::function<void({0}*)> visitor) const {{ for (auto entry : {0}_map_) {{ visitor(entry.second); }} }}\n'.format(
                name_wrapper
            )
            self.get_wrapper_code += '    {0}* Get{0}(format::HandleId id) {{ return GetWrapper<{0}>(id, {0}_map_); }}\n'.format(
                name_wrapper
            )
            self.get_wrapper_code += '    const {0}* Get{0}(format::HandleId id) const {{ return GetWrapper<{0}>(id, {0}_map_); }}\n\n'.format(
                name_wrapper
            )
            self.map_code += '    std::map<format::HandleId, {0}*> {0}_map_;\n'.format(
                name_wrapper
            )

        code = 'class Dx12StateTable : public Dx12StateTableBase\n'
        code += '{\n'
        code += '  public:\n'
        code += '    Dx12StateTable() {}\n'
        code += '    ~Dx12StateTable() {}\n'
        code += '\n'
        code += self.insert_wrapper_code
        code += '\n'
        code += self.remove_wrapper_code
        code += '\n'
        code += self.visit_wrappers_code
        code += '\n'
        code += '    //\n'
        code += '    // Helper functions for state initialization.\n'
        code += '    //\n'
        code += '\n'
        code += self.get_wrapper_code
        code += '\n'
        code += '  private:\n'
        code += self.map_code
        code += '};\n'
        write(code, file=self.outFile)

    def write_include(self):
        write('#include "encode/dx12_state_table_base.h"\n', file=self.outFile)
