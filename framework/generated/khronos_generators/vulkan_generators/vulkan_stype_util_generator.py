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

from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write
from khronos_struct_type_util_generator import KhronosStructTypeUtilGenerator
from reformat_code import format_cpp_code

VulkanSTypeUtilGeneratorOptions = VulkanBaseGeneratorOptions

class VulkanSTypeUtilGenerator(VulkanBaseGenerator, KhronosStructTypeUtilGenerator):
    """VulkanSTypeUtilGenerator - subclass of VulkanBaseGenerator.
    Generates C++ utility header to do compile-time lookups between Vulkan
    structure types and their corresponding VkStructureType values
    """
    def __init__(self, **kwargs):
        VulkanBaseGenerator.__init__(
            self,
            **kwargs
        )

    def beginFile(self, gen_opts):
        VulkanBaseGenerator.beginFile(self, gen_opts)
        KhronosStructTypeUtilGenerator.write_struct_type_prefix(self, gen_opts)

    def endFile(self):
        KhronosStructTypeUtilGenerator.write_struct_type_data(self)

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)
