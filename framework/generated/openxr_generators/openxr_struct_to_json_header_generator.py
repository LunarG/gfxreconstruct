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

import sys
from base_generator import *
from reformat_code import format_cpp_code, indent_cpp_code, remove_trailing_newlines


class OpenXrStructToJsonHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for to_json functions"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraOpenXrHeaders=[]
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
            extraOpenXrHeaders=extraOpenXrHeaders
        )


# OpenXrStructToJsonHeaderGenerator - subclass of BaseGenerator.
# Generates C++ functions for stringifying OpenXr API structures.
class OpenXrStructToJsonHeaderGenerator(BaseGenerator):
    """Generate C++ functions to serialize OpenXR structures to JSON"""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=False,
            process_structs=True,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        includes = format_cpp_code(
            '''
            #include "decode/custom_openxr_struct_to_json.h"
            '''
        )
        write(includes, file=self.outFile)
        self.newline()
        self.includeOpenXrHeaders(genOpts)
        self.newline()
        write("", file=self.outFile)
        namespace = format_cpp_code(
            '''
            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(decode)
            '''
        )
        write(namespace, file=self.outFile)

    # Method override
    def endFile(self):
        body = remove_trailing_newlines(
            indent_cpp_code(
                '''
            /// Works out the type of the struct at the end of a next pointer and dispatches
            /// recursively to the FieldToJson for that.
            void FieldToJson(nlohmann::ordered_json& jdata, const OpenXrNextNode* data, const util::JsonOptions& options = util::JsonOptions());

            GFXRECON_END_NAMESPACE(decode)
            GFXRECON_END_NAMESPACE(gfxrecon)
        '''
            )
        )
        write(body, file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        self.feature_break = False
        if self.feature_struct_members:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generate_feature(self):
        for struct in self.get_filtered_struct_names():
            body = "void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_{0}* data, const util::JsonOptions& options = util::JsonOptions());".format(
                struct
            )
            write(body, file=self.outFile)
