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

import os
import re
import sys
import inspect
from base_generator import *
from base_generator_defines import bits_enum_to_flags_typedef


class OpenXrEnumToStringBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for OpenXR ToString() functions"""

    def __init__(
        self,
        # Path to JSON file listing apicalls and structs to ignore.
        blacklists=None,
        # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        platformTypes=None,
        filename=None,
        directory='.',
        prefixText='',
        protectFile=False,
        protectFeature=True,
        extraHeaders=[]
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
            extraHeaders=extraHeaders
        )


# OpenXrEnumToStringBodyGenerator - subclass of BaseGenerator.
# Generates C++ functions for stringifying OpenXR API enums.
class OpenXrEnumToStringBodyGenerator(BaseGenerator):
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
        body = inspect.cleandoc(
            '''
            #include "generated_openxr_enum_to_string.h"

            GFXRECON_BEGIN_NAMESPACE(gfxrecon)
            GFXRECON_BEGIN_NAMESPACE(util)
            '''
        )
        write(body, file=self.outFile)

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

    # Performs C++ code generation for the feature.
    def generate_feature(self):
        for enum in sorted(self.enum_names):
            if enum.startswith(
                'Vk'
            ) or enum in self.processedEnums or enum in self.enum_aliases:
                continue

            body = ''
            self.processedEnums.add(enum)

            if self.is64BitFlags(enum) or self.is_bittype(enum):
                # print(enum)
                # body = 'std::string {0}ToString(const {0}& value, ToStringFlags, uint32_t, uint32_t)\n'
                # Since every caller needs to know exactly what it is calling, we may as well
                # dispense with the parameters that are always ignored:
                body += f'\nstd::string {enum}ToString(const uint64_t& value)\n'
            elif not self.is_bittype(enum):
                body += f'\ntemplate <> std::string ToString<{enum}>(const {enum}& value, ToStringFlags, uint32_t, uint32_t)\n'

            if len(body) == 0:
                continue

            body += '{\n'
            if enum in self.enum_enumerants and len(
                self.enum_enumerants[enum]
            ):
                enumerants = self.enum_enumerants[enum]
                body += '    switch (value) {\n'
                for enumerant in enumerants:
                    body += f'    case {enumerant}: return "{enumerant}";\n'
                body += '    default: break;\n'
                body += '    }\n'
            body += f'    return "Unhandled {enum}";\n'
            body += '}\n'
            if self.is_bittype(enum):
                if self.is64BitFlags(enum):
                    flag_name = enum
                    flag_name = flag_name.replace('Bit', '')
                    if flag_name in self.flags_types:
                        body += f'\nstd::string {flag_name}ToString(XrFlags64 xrFlags)\n'
                        body += '{\n'
                        body += '    std::string   str;\n'
                        body += '    XrFlags64     index = 0U;\n'
                        body += '    while (xrFlags)\n'
                        body += '    {\n'
                        body += '        if (xrFlags & 1U)\n'
                        body += '        {\n'
                        body += '            if (!str.empty())\n'
                        body += '            {\n'
                        body += '                str += \'|\';\n'
                        body += '            }\n'
                        body += f'            str.append({enum}ToString(static_cast<uint64_t>(1U << index)));\n'
                        body += '        }\n'
                        body += '        ++index;\n'
                        body += '        xrFlags >>= 1U;\n'
                        body += '    }\n'
                        body += '    if (str.empty())\n'
                        body += '    {\n'
                        body += f'        str.append({enum}ToString(static_cast<uint64_t>(0U)));\n'
                        body += '    }\n'
                        body += '    return str;\n'
                        body += '}\n'
                else:
                    # Original version(these are never actually being called which is part of issue #620):
                    body += f'\ntemplate <> std::string ToString<{enum}>(XrFlags xrFlags, ToStringFlags, uint32_t, uint32_t)\n'
                    # Simpler, non-template version that matches the 64 bit version above. Changing
                    # to these signatures actually compiles fine, showing the originals were never
                    # called anywhere. Leaving this commented-out but ready for the PR that fixes
                    # issue #620 to use.
                    # body += '\nstd::string {1}ToString(XrFlags xrFlags)\n'
                    body += '{\n'
                    body += f'    return BitmaskToString<{enum}>(xrFlags);\n'
                    body += '}\n'

            write(body, file=self.outFile)
