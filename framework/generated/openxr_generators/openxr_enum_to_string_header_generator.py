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

import os, re, sys, inspect
from base_generator import *


class OpenXrEnumToStringHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for OpenXR ToString() functions"""

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


# OpenXrEnumToStringHeaderGenerator - subclass of BaseGenerator.
# Generates C++ functions for stringifying OpenXR API enums.
class OpenXrEnumToStringHeaderGenerator(BaseGenerator):
    """Generate C++ functions for OpenXR ToString() functions"""

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

        # Set of enums that have been processed since we'll encounter enums that are
        #   referenced by extensions multiple times.  This list is prepopulated with
        #   enums that should be skipped.  For now this is an empty set
        #self.processedEnums = { }
        self.processedEnums = set()

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        includes = inspect.cleandoc(
            '''
            #include "format/platform_types.h"
            #include "util/to_string.h"
            '''
        )
        write(includes, file=self.outFile)
        self.newline()
        self.includeOpenXrHeaders(genOpts)
        self.newline()
        namespace = inspect.cleandoc(
            '''
            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(util)
            '''
        )
        write(namespace, file=self.outFile)

    # Method override
    def endFile(self):
        body = inspect.cleandoc(
            '''
            GFXRECON_END_NAMESPACE(util)
            GFXRECON_END_NAMESPACE(gfxrecon)
            '''
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
        for enum in sorted(self.enum_names):
            if not enum in self.processedEnums:
                if enum.startswith('Vk'):
                    continue
                self.processedEnums.add(enum)
                if not enum in self.enumAliases:
                    body = ''
                    if self.is_flags_enum_64bit(enum):
                        body = 'std::string {0}ToString(const uint64_t& value);'
                        body += '\nstd::string {1}ToString(XrFlags64 vkFlags);'
                    elif 'Bits' not in enum:
                        body = 'template <> std::string ToString<{0}>(const {0}& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);'
                    if len(body) > 0:
                        write(
                            body.format(enum, BitsEnumToFlagsTypedef(enum)),
                            file=self.outFile
                        )
