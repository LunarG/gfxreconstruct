#!/usr/bin/python3 -i
#
# Copyright (c) 2021-2025 LunarG, Inc.
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
from khronos_base_generator import write


# Generates declarations for functions for Khronos state table
class KhronosStateTableHeaderGenerator():

    def add_wrapper_funcs_for_type(self, api_data, name):
        type_api_data = self.get_api_data_from_type(name)
        wrapper_prefix = type_api_data.wrapper_prefix
        type_prefix = type_api_data.type_prefix
        short_name = name[len(type_prefix):]
        handle_wrapper_func = type_api_data.camel_guard + short_name + 'Wrapper'
        handle_wrapper_type = wrapper_prefix + '::' + short_name + 'Wrapper'
        handle_map = type_prefix.lower() + '_' + short_name[0].lower() + short_name[1:] + '_map_'
        self.insert_code += '    bool InsertWrapper(format::HandleId id, {}* wrapper) {{ return InsertEntry(id, wrapper, {}); }}\n'.format(
            handle_wrapper_type, handle_map
        )
        self.remove_code += '    bool RemoveWrapper(const {}* wrapper) {{ return RemoveEntry(wrapper, {}); }}\n'.format(
            handle_wrapper_type, handle_map
        )
        self.visit_code += '    void VisitWrappers(std::function<void({}*)> visitor) const {{ for (auto entry : {}) {{ visitor(entry.second); }} }}\n'.format(
            handle_wrapper_type, handle_map
        )
        self.get_code += '    {0}* Get{1}(format::HandleId id) {{ return GetWrapper<{0}>(id, {2}); }}\n'.format(
            handle_wrapper_type, handle_wrapper_func, handle_map
        )
        self.const_get_code += '    const {0}* Get{1}(format::HandleId id) const {{ return GetWrapper<{0}>(id, {2}); }}\n'.format(
            handle_wrapper_type, handle_wrapper_func, handle_map
        )
        self.map_code += '    std::map<format::HandleId, {}*> {};\n'.format(
            handle_wrapper_type, handle_map
        )
        self.api_insert_code += '    bool InsertWrapper({}* wrapper) {{ return InsertEntry(wrapper->handle, wrapper, {}); }}\n'.format(
            handle_wrapper_type, handle_map
        )
        self.api_remove_code += '    bool RemoveWrapper(const {}* wrapper) {{\n'.format(
            handle_wrapper_type
        )
        self.api_remove_code += '         if (wrapper == nullptr) return false;\n'
        self.api_remove_code += '         return RemoveEntry(wrapper->handle, {});\n'.format(
            handle_map
        )
        self.api_remove_code += '    }\n'
        self.api_get_code += 'template<> inline {0}* {3}StateHandleTable::GetWrapper<{0}>({1} handle) {{ return {3}StateTableBase::GetWrapper(handle, {2}); }}\n'.format(
            handle_wrapper_type, name, handle_map, api_data.api_class_prefix
        )
        self.api_const_get_code += 'template<> inline const {0}* {3}StateHandleTable::GetWrapper<{0}>({1} handle) const {{ return {3}StateTableBase::GetWrapper(handle, {2}); }}\n'.format(
            handle_wrapper_type, name, handle_map, api_data.api_class_prefix
        )
        self.api_map_code += '    std::unordered_map<{}, {}*> {};\n'.format(
            name, handle_wrapper_type, handle_map
        )

    def generate_state_table_content(self):

        self.insert_code = ''
        self.remove_code = ''
        self.const_get_code = ''
        self.get_code = ''
        self.visit_code = ''
        self.map_code = ''

        self.api_insert_code = ''
        self.api_remove_code = ''
        self.api_const_get_code = ''
        self.api_get_code = ''
        self.api_map_code = ''

        api_data = self.get_api_data()

        for handle in sorted(self.handle_names):
            if handle in self.handle_aliases:
                continue
            self.add_wrapper_funcs_for_type(api_data, handle)
        for atom in sorted(self.atom_names):
            if atom in self.atom_aliases:
                continue
            self.add_wrapper_funcs_for_type(api_data, atom)
        for opaque in sorted(self.opaque_names):
            if atom in self.opaque_aliases:
                continue
            self.add_wrapper_funcs_for_type(api_data, opaque)

        self.newline()
        code = 'class {0}StateTable : {0}StateTableBase\n'.format(
            api_data.api_class_prefix
        )
        code += '{\n'
        code += '  public:\n'
        code += '    {}StateTable() {{}}\n'.format(api_data.api_class_prefix)
        code += '    ~{}StateTable() {{}}\n'.format(api_data.api_class_prefix)
        code += '\n'
        code += self.insert_code
        code += '\n'
        code += self.remove_code
        code += '\n'
        code += self.const_get_code
        code += '\n'
        code += self.get_code
        code += '\n'
        code += self.visit_code
        code += '\n'
        code += '  private:\n'
        code += self.map_code
        code += '};\n'
        code += '\n'
        code += 'class {0}StateHandleTable : {0}StateTableBase\n'.format(
            api_data.api_class_prefix
        )
        code += '{\n'
        code += '  public:\n'
        code += '    {}StateHandleTable() {{}}\n'.format(
            api_data.api_class_prefix
        )
        code += '    ~{}StateHandleTable() {{}}\n'.format(
            api_data.api_class_prefix
        )
        code += '\n'
        code += self.api_insert_code
        code += '\n'
        code += self.api_remove_code
        code += '\n'
        code += '    template<typename Wrapper> const Wrapper* GetWrapper(typename Wrapper::HandleType handle) const { return nullptr; }\n'
        code += '\n'
        code += '    template<typename Wrapper> Wrapper* GetWrapper(typename Wrapper::HandleType handle) { return nullptr; }\n'
        code += '\n'
        code += '  private:\n'
        code += self.api_map_code
        code += '};\n'
        code += '\n'
        code += self.api_const_get_code
        code += '\n'
        code += self.api_get_code
        write(code, file=self.outFile)
