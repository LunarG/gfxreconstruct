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


class VulkanObjectInfoTableBase2HeaderGeneratorOptions(BaseGeneratorOptions):
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
        extraVulkanHeaders=[]
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
            extraVulkanHeaders=extraVulkanHeaders
        )


# Generates declarations for functions for Vulkan object info table
class VulkanObjectInfoTableBase2HeaderGenerator(BaseGenerator):

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
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
    # yapf: enable

    # Method override
    # yapf: disable
    def endFile(self):
        self.generate_all()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
    # yapf: enable

    # yapf: disable
    def generate_all(self):
        add_code = ''
        remove_code = ''
        const_get_code = ''
        get_code = ''
        visit_code = ''
        map_code = ''

        for handle_name in sorted(self.handle_names):
            if handle_name in self.DUPLICATE_HANDLE_TYPES:
                continue
            short_handle_name = handle_name[2:]
            handle_info = short_handle_name + 'Info'
            function_info = handle_name + 'Info'
            handle_map = short_handle_name[0].lower() + short_handle_name[1:] + '_map_'
            add_code += '    void Add{0}(Vulkan{1}&& info) {{ AddObjectInfo(std::move(info), &{2}); }}\n'.format(function_info, handle_info, handle_map)
            remove_code += '    void Remove{0}(format::HandleId id) {{ {1}.erase(id); }}\n'.format(function_info, handle_map)
            const_get_code += '    const Vulkan{0}* Get{1}(format::HandleId id) const {{ return GetObjectInfo<Vulkan{0}>(id, &{2}); }}\n'.format(handle_info, function_info, handle_map)
            get_code += '    Vulkan{0}* Get{1}(format::HandleId id) {{ return GetObjectInfo<Vulkan{0}>(id, &{2}); }}\n'.format(handle_info, function_info, handle_map)
            visit_code += '    void Visit{0}(std::function<void(const Vulkan{1}*)> visitor) const {{  for (const auto& entry : {2}) {{ visitor(&entry.second); }}  }}\n'.format(function_info, handle_info, handle_map)
            map_code += '     std::unordered_map<format::HandleId, Vulkan{0}> {1};\n'.format(handle_info, handle_map)

        self.newline()
        code = 'class VulkanObjectInfoTableBase2 : VulkanObjectInfoTableBase\n'
        code += '{\n'
        code += '  public:\n'
        code += '    VulkanObjectInfoTableBase2() {}\n'
        code += '    ~VulkanObjectInfoTableBase2() {}\n'
        code += '\n'
        code += add_code
        code += '\n'
        code += remove_code
        code += '\n'
        code += const_get_code
        code += '\n'
        code += get_code
        code += '\n'
        code += visit_code
        code += '\n'
        code += '  protected:\n'
        code += map_code
        code += '};\n'
        write(code, file=self.outFile)
    # yapf: enable

    def write_include(self):
        write(
            '#include "decode/vulkan_object_info_table_base.h"\n',
            file=self.outFile
        )
        self.newline()
