#!/usr/bin/python3 -i
#
# Copyright (c) 2021-2024 LunarG, Inc.
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


class OpenXrStateTableHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ function declarations for OpenXR API parameter encoding"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platformTypes=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefixText='',
        protectFile=False,
        protectFeature=True,
        extraOpenXrHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platformTypes,
            filename,
            directory,
            prefixText,
            protectFile,
            protectFeature,
            extraOpenXrHeaders=extraOpenXrHeaders
        )


# Generates declarations for functions for OpenXr state table
class OpenXrStateTableHeaderGenerator(BaseGenerator):

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=False,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        self.write_include()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    # Method override
    def endFile(self):
        self.generate_all()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def generate_all(self):
        insert_code = ''
        remove_code = ''
        const_get_code = ''
        get_code = ''
        visit_code = ''
        map_code = ''

        xr_insert_code = ''
        xr_remove_code = ''
        xr_const_get_code = ''
        xr_get_code = ''
        xr_map_code = ''

        for xr_handle_name in sorted(self.handle_names):
            if xr_handle_name in self.DUPLICATE_HANDLE_TYPES:
                continue
            handle_name = xr_handle_name[2:]
            wrapper_prefix = self.get_handle_wrapper_prefix(xr_handle_name)
            handle_prefix = self.get_handle_prefix(xr_handle_name)
            handle_wrapper_func = handle_prefix + handle_name + 'Wrapper'
            handle_wrapper_type = wrapper_prefix + '::' + handle_name + 'Wrapper'
            handle_map = handle_name[0].lower() + handle_name[1:] + '_map_'
            insert_code += '    bool InsertWrapper(format::HandleId id, {0}* wrapper) {{ return InsertEntry(id, wrapper, {1}); }}\n'.format(
                handle_wrapper_type, handle_map
            )
            remove_code += '    bool RemoveWrapper(const {0}* wrapper) {{ return RemoveEntry(wrapper, {1}); }}\n'.format(
                handle_wrapper_type, handle_map
            )
            visit_code += '    void VisitWrappers(std::function<void({0}*)> visitor) const {{ for (auto entry : {1}) {{ visitor(entry.second); }} }}\n'.format(
                handle_wrapper_type, handle_map
            )
            get_code += '    {0}* Get{1}(format::HandleId id) {{ return GetWrapper<{0}>(id, {2}); }}\n'.format(
                handle_wrapper_type, handle_wrapper_func, handle_map
            )
            const_get_code += '    const {0}* Get{1}(format::HandleId id) const {{ return GetWrapper<{0}>(id, {2}); }}\n'.format(
                handle_wrapper_type, handle_wrapper_func, handle_map
            )
            map_code += '    std::map<format::HandleId, {0}*> {1};\n'.format(
                handle_wrapper_type, handle_map
            )
            xr_insert_code += '    bool InsertWrapper({0}* wrapper) {{ return InsertEntry(wrapper->handle, wrapper, {1}); }}\n'.format(
                handle_wrapper_type, handle_map
            )
            xr_remove_code += '    bool RemoveWrapper(const {}* wrapper) {{\n'.format(
                handle_wrapper_type
            )
            xr_remove_code += '         if (wrapper == nullptr) return false;\n'
            xr_remove_code += '         return RemoveEntry(wrapper->handle, {});\n'.format(
                handle_map
            )
            xr_remove_code += '    }\n'
            xr_get_code += 'template<> inline {0}* OpenXrStateHandleTable::GetWrapper<{0}>({1} handle) {{ return OpenXrStateTableBase::GetWrapper(handle, {2}); }}\n'.format(
                handle_wrapper_type, xr_handle_name, handle_map
            )
            xr_const_get_code += 'template<> inline const {0}* OpenXrStateHandleTable::GetWrapper<{0}>({1} handle) const {{ return OpenXrStateTableBase::GetWrapper(handle, {2}); }}\n'.format(
                handle_wrapper_type, xr_handle_name, handle_map
            )
            xr_map_code += '    std::unordered_map<{0}, {1}*> {2};\n'.format(
                xr_handle_name, handle_wrapper_type, handle_map
            )

        self.newline()
        code = 'class OpenXrStateTable : OpenXrStateTableBase\n'
        code += '{\n'
        code += '  public:\n'
        code += '    OpenXrStateTable() {}\n'
        code += '    ~OpenXrStateTable() {}\n'
        code += '\n'
        code += insert_code
        code += '\n'
        code += remove_code
        code += '\n'
        code += const_get_code
        code += '\n'
        code += get_code
        code += '\n'
        code += visit_code
        code += '\n'
        code += '  private:\n'
        code += map_code
        code += '};\n'
        code += '\n'
        code += 'class OpenXrStateHandleTable : OpenXrStateTableBase\n'
        code += '{\n'
        code += '  public:\n'
        code += '    OpenXrStateHandleTable() {}\n'
        code += '    ~OpenXrStateHandleTable() {}\n'
        code += '\n'
        code += xr_insert_code
        code += '\n'
        code += xr_remove_code
        code += '\n'
        code += '    template<typename Wrapper> const Wrapper* GetWrapper(typename Wrapper::HandleType handle) const { return nullptr; }\n'
        code += '\n'
        code += '    template<typename Wrapper> Wrapper* GetWrapper(typename Wrapper::HandleType handle) { return nullptr; }\n'
        code += '\n'
        code += '  private:\n'
        code += xr_map_code
        code += '};\n'
        code += '\n'
        code += xr_const_get_code
        code += '\n'
        code += xr_get_code
        write(code, file=self.outFile)

    def write_include(self):
        write(
            '#include "encode/openxr_state_table_base.h"\n', file=self.outFile
        )
        self.newline()
