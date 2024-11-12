#!/usr/bin/python3 -i
#
# Copyright (c) 2022-2024 LunarG, Inc.
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
#

from khronos_base_generator import write

class KhronosStructToJsonHeaderGenerator():
    """KhronosStructToJsonHeaderGenerator
    Generate C++ function declarations to serialize Khronos structures to JSON"""

    def should_decode_struct(self, struct):
        """Method indended to be overridden.
        Indicates that the provided struct is a struct we want to decode"""
        return True

    def write_header_contents(self):
        for struct in self.get_all_filtered_struct_names():
            if self.should_decode_struct(struct):
                body = "void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_{0}* data, const util::JsonOptions& options = util::JsonOptions());".format(struct)
                write(body, file=self.outFile)
        self.newline()

        var_name = self.get_extended_struct_var_name()
        prefix = self.get_extended_struct_func_prefix()
        if len(var_name) > 0 and len(prefix) > 0:
            write(f'/// Works out the type of the struct at the end of a {var_name} pointer and dispatches', file=self.outFile)
            write('/// recursively to the FieldToJson for that.', file=self.outFile)
            write(f'void FieldToJson(nlohmann::ordered_json& jdata, const {prefix}Node* data, const util::JsonOptions& options = util::JsonOptions());', file=self.outFile)
