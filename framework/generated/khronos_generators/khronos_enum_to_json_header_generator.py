#!/usr/bin/python3 -i
#
# Copyright (c) 2022-2023 LunarG, Inc.
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

import sys
from khronos_base_generator import write


# KhronosEnumToJsonHeaderGenerator
# Generates C++ functions for stringifying Khronos API enums.
class KhronosEnumToJsonHeaderGenerator():
    """Generate C++ functions to serialize Khronos enumaration to JSON"""

    def skip_generating_enum_to_json_for_type(self, type):
        """ Method may be overridden"""
        return False

    def make_decls(self):
        # Set of enums that have been processed since we'll encounter enums that are
        #   referenced by extensions multiple times.  This list is prepopulated with
        #   enums that should be skipped.
        processedEnums = set()

        for enum in sorted(self.enum_names):
            if enum in processedEnums or self.skip_generating_enum_to_json_for_type(
                enum
            ):
                continue
            processedEnums.add(enum)
            if not enum in self.enumAliases:
                body = 'void {0}ToJson(nlohmann::ordered_json& jdata, const {0}& value, const util::JsonOptions& options = util::JsonOptions());'
                write(body.format(enum), file=self.outFile)

        for flag in sorted(self.flags_types):
            if flag in self.flags_type_aliases or self.skip_generating_enum_to_json_for_type(flag):
                continue
            body = 'void {0}ToJson(nlohmann::ordered_json& jdata, const {1} flags, const util::JsonOptions& options = util::JsonOptions());'
            write(body.format(flag, self.flags_types[flag]), file=self.outFile)
