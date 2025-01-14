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

from openxr_base_generator import OpenXrBaseGenerator, OpenXrBaseGeneratorOptions, write
from khronos_struct_type_util_generator import KhronosStructTypeUtilGenerator
from reformat_code import format_cpp_code

OpenXrTypeUtilGeneratorOptions = OpenXrBaseGeneratorOptions

class OpenXrTypeUtilGenerator(OpenXrBaseGenerator, KhronosStructTypeUtilGenerator):
    """OpenXrTypeUtilGenerator - subclass of OpenXrBaseGenerator.
    Generates C++ utility header to do compile-time lookups between OpenXr
    structure types and their corresponding VkStructureType values
    """
    def __init__(self, **kwargs):
        OpenXrBaseGenerator.__init__(
            self,
            **kwargs
        )
        self.extra_struct_type_skips = [ 'XrLocalizationMapQueryInfoBaseHeaderML' ]

    def beginFile(self, gen_opts):
        KhronosStructTypeUtilGenerator.update_begin_end_file_data(gen_opts.begin_end_file_data)
        OpenXrBaseGenerator.beginFile(self, gen_opts)
        KhronosStructTypeUtilGenerator.write_struct_type_prefix(self, gen_opts)


    def skip_struct_type(self, struct):
        """ Maybe be overridden """
        return (KhronosStructTypeUtilGenerator.skip_struct_type(self, struct) or
                 struct in self.extra_struct_type_skips)

    def endFile(self):
        KhronosStructTypeUtilGenerator.write_struct_type_data(self)

        # Finish processing in superclass
        OpenXrBaseGenerator.endFile(self)
