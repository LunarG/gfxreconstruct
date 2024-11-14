#!/usr/bin/python3 -i
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

import os, re, sys
from base_generator import *


class VulkanStateTableHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ function declarations for Vulkan API parameter encoding"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )


# Generates declarations for functions for Vulkan state table
class VulkanStateTableHeaderGenerator(BaseGenerator):

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    # Method override
    # yapf: disable
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        self.write_include()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
    # yapf: enable

    # Method override
    # yapf: disable
    def endFile(self):
        self.generate_all()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
    # yapf: enable

    def add_wrapper_funcs_for_type(self, name):
        wrapper_prefix = self.get_wrapper_prefix_from_type(name)
        type_prefix = self.get_api_struct_prefix_from_type(name)
        short_name = name[len(type_prefix):]
        handle_wrapper_func = short_name + 'Wrapper'
        handle_wrapper_type = wrapper_prefix + '::' + short_name + 'Wrapper'
        handle_map = short_name[0].lower() + short_name[1:] + '_map_'
        self.insert_code += '    bool InsertWrapper(format::HandleId id, {}* wrapper) {{ return InsertEntry(id, wrapper, {}); }}\n'.format(handle_wrapper_type, handle_map)
        self.remove_code += '    bool RemoveWrapper(const {}* wrapper) {{ return RemoveEntry(wrapper, {}); }}\n'.format(handle_wrapper_type, handle_map)
        self.visit_code += '    void VisitWrappers(std::function<void({}*)> visitor) const {{ for (auto entry : {}) {{ visitor(entry.second); }} }}\n'.format(handle_wrapper_type, handle_map)
        self.get_code += '    {0}* Get{1}(format::HandleId id) {{ return GetWrapper<{0}>(id, {2}); }}\n'.format(handle_wrapper_type, handle_wrapper_func, handle_map)
        self.const_get_code += '    const {0}* Get{1}(format::HandleId id) const {{ return GetWrapper<{0}>(id, {2}); }}\n'.format(handle_wrapper_type, handle_wrapper_func, handle_map)
        self.map_code += '    std::map<format::HandleId, {}*> {};\n'.format(handle_wrapper_type, handle_map)
        self.api_insert_code += '    bool InsertWrapper({}* wrapper) {{ return InsertEntry(wrapper->handle, wrapper, {}); }}\n'.format(handle_wrapper_type, handle_map)
        self.api_remove_code += '    bool RemoveWrapper(const {}* wrapper) {{\n'.format(handle_wrapper_type)
        self.api_remove_code += '         if (wrapper == nullptr) return false;\n'
        self.api_remove_code += '         return RemoveEntry(wrapper->handle, {});\n'.format(handle_map)
        self.api_remove_code += '    }\n'
        self.api_get_code += 'template<> inline {0}* VulkanStateHandleTable::GetWrapper<{0}>({1} handle) {{ return VulkanStateTableBase::GetWrapper(handle, {2}); }}\n'.format(handle_wrapper_type, name, handle_map)
        self.api_const_get_code += 'template<> inline const {0}* VulkanStateHandleTable::GetWrapper<{0}>({1} handle) const {{ return VulkanStateTableBase::GetWrapper(handle, {2}); }}\n'.format(handle_wrapper_type, name, handle_map)
        self.api_map_code += '    std::unordered_map<{}, {}*> {};\n'.format(name, handle_wrapper_type, handle_map)

    # yapf: disable
    def generate_all(self):
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

        for handle in sorted(self.handle_names):
            if handle in self.handle_aliases:
                continue
            self.add_wrapper_funcs_for_type(handle)
        for atom in sorted(self.atom_names):
            if atom in self.atom_aliases:
                continue
            self.add_wrapper_funcs_for_type(atom)
        for opaque in sorted(self.opaque_names):
            if atom in self.opaque_aliases:
                continue
            self.add_wrapper_funcs_for_type(opaque)

        self.newline()
        code = 'class VulkanStateTable : VulkanStateTableBase\n'
        code += '{\n'
        code += '  public:\n'
        code += '    VulkanStateTable() {}\n'
        code += '    ~VulkanStateTable() {}\n'
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
        code += 'class VulkanStateHandleTable : VulkanStateTableBase\n'
        code += '{\n'
        code += '  public:\n'
        code += '    VulkanStateHandleTable() {}\n'
        code += '    ~VulkanStateHandleTable() {}\n'
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
    # yapf: enable

    def write_include(self):
        write(
            '#include "encode/vulkan_state_table_base.h"\n', file=self.outFile
        )
        self.newline()
