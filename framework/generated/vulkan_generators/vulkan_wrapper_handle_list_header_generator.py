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


class VulkanWrapperHandleListHeaderGeneratorOptions(BaseGeneratorOptions):
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


# Generates declarations for functions for Vulkan object info table
class VulkanWrapperHandleListHeaderGenerator(BaseGenerator):

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
        add_code = ''
        list_code = ''

        for handle_name in sorted(self.handle_names):
            if handle_name in self.DUPLICATE_HANDLE_TYPES:
                continue
            handle_name = handle_name[2:]
            handle_wrapper = handle_name + 'Wrapper'
            handle_list = handle_wrapper + '_list_'
            add_code += '    void AddWrapperHandle({0}* wrapper) {{ {1}.emplace_back(wrapper); }}\n'.format(handle_wrapper, handle_list)
            list_code += '    std::vector<std::shared_ptr<{0}>> {1};\n'.format(handle_wrapper, handle_list)

        self.newline()
        code = 'class VulkanWrapperHandleList\n'
        code += '{\n'
        code += '  public:\n'
        code += '    static VulkanWrapperHandleList* Get() { return &instance_; }\n'
        code += '\n'
        code += add_code
        code += '\n'
        code += '  private:\n'
        code += '    VulkanWrapperHandleList(){}\n'
        code += '    static VulkanWrapperHandleList instance_;\n'
        code += '\n'
        code += list_code
        code += '};\n'
        write(code, file=self.outFile)
    # yapf: enable

    def write_include(self):
        write(
            '#include "encode/vulkan_handle_wrappers.h"\n',
            file=self.outFile
        )
        self.newline()
