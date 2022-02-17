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
        platformTypes=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefixText='',
        protectFile=False,
        protectFeature=True,
        extraVulkanHeaders=[]
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
            extraVulkanHeaders=extraVulkanHeaders
        )


# Generates declarations for functions for Vulkan state table
class VulkanStateTableHeaderGenerator(BaseGenerator):

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

    # yapf: disable
    def generate_all(self):
        insert_code = ''
        remove_code = ''
        const_get_code = ''
        get_code = ''
        visit_code = ''
        map_code = ''

        for handle_name in sorted(self.handle_names):
            if handle_name in self.DUPLICATE_HANDLE_TYPES:
                continue
            handle_name = handle_name[2:]
            handle_wrapper = handle_name + 'Wrapper'
            handle_map = handle_name[0].lower() + handle_name[1:] + '_map_'
            insert_code += '    bool InsertWrapper(format::HandleId id, {0}* wrapper) {{ return InsertEntry(id, wrapper, {1}); }}\n'.format(handle_wrapper, handle_map)
            remove_code += '    bool RemoveWrapper(const {0}* wrapper) {{ return RemoveEntry(wrapper, {1}); }}\n'.format(handle_wrapper, handle_map)
            visit_code += '    void VisitWrappers(std::function<void({0}*)> visitor) const {{ for (auto entry : {1}) {{ visitor(entry.second); }} }}\n'.format(handle_wrapper, handle_map)
            get_code += '    {0}* Get{0}(format::HandleId id) {{ return GetWrapper<{0}>(id, {1}); }}\n'.format(handle_wrapper, handle_map)
            const_get_code += '    const {0}* Get{0}(format::HandleId id) const {{ return GetWrapper<{0}>(id, {1}); }}\n'.format(handle_wrapper, handle_map)
            map_code += '    std::map<format::HandleId, {0}*> {1};\n'.format(handle_wrapper, handle_map)

        self.newline()
        code = 'class VulkanStateTable : VulkanStateTableBase\n'
        code += '{\n'
        code += '  public:\n'
        code += '    VulkanStateTable() {}\n'
        code += '    ~VulkanStateTable() {}\n'
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
        write(code, file=self.outFile)
    # yapf: enable

    def write_include(self):
        write(
            '#include "encode/vulkan_state_table_base.h"\n', file=self.outFile
        )
        self.newline()
