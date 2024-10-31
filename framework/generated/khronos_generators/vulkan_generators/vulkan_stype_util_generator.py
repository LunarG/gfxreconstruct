#!/usr/bin/python3
#
# Copyright (c) 2024 LunarG, Inc.
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

from base_generator import BaseGenerator, BaseGeneratorOptions, write
from reformat_code import format_cpp_code

VulkanSTypeUtilGeneratorOptions = BaseGeneratorOptions

class VulkanSTypeUtilGenerator(BaseGenerator):
    """VulkanSTypeUtilGenerator - subclass of BaseGenerator.
    Generates C++ utility header to do compile-time lookups between Vulkan
    structure types and their corresponding VkStructureType values
    """
    def __init__(self, **kwargs):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=False,
            **kwargs
        )
        # These are dummy structures that do not have their own VkStructureType values
        self.missing_stypes = ['VkBaseInStructure', 'VkBaseOutStructure']

    def beginFile(self, gen_opts):
        BaseGenerator.beginFile(self, gen_opts)
        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(util)', file=self.outFile)
        self.newline()
        write(format_cpp_code('''
            // Instantiating the primary template indicates that either the template was
            // called with an invalid Vulkan struct type or that the code generation is out
            // of date, both of which are errors
            template <typename T> VkStructureType GetSType() = delete;'''), file=self.outFile)
        self.newline()

    def genStruct(self, typeinfo, typename, alias):
        if not alias and typename not in self.missing_stypes:
            stype = self.make_structure_type_enum(typeinfo, typename)
            if stype:
                write(f'template <> constexpr VkStructureType GetSType<{typename}>(){{ return {stype}; }}', file=self.outFile)

    def endFile(self):
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)
