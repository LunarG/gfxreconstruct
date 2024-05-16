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

import sys
from base_generator import *
from reformat_code import format_cpp_code


class OpenXrEnumToJsonHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating C++ functions for OpenXR ToString() functions"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
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
            platform_types,
            filename,
            directory,
            prefixText,
            protectFile,
            protectFeature,
            extraOpenXrHeaders=extraOpenXrHeaders
        )


# OpenXrEnumToStringHeaderGenerator - subclass of BaseGenerator.
# Generates C++ functions for stringifying OpenXr API enums.
class OpenXrEnumToJsonHeaderGenerator(BaseGenerator):
    """Generate C++ functions to serialize OpenXR enumaration to JSON"""

    SKIP_ENUM = []

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
        #   enums that should be skipped.
        self.processedEnums = set()

        self.enumType = dict()
        self.flagsType = dict()
        self.flagBitsType = dict()

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        includes = format_cpp_code(
            '''
            #include "format/platform_types.h"
            #include "util/json_util.h"

            #include <nlohmann/json.hpp>

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
        self.newline()
        self.make_decls()

        self.newline()
        body = format_cpp_code(
            '''
            GFXRECON_END_NAMESPACE(decode)
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

    def genGroup(self, groupinfo, group_name, alias):
        BaseGenerator.genGroup(self, groupinfo, group_name, alias)
        type_elem = groupinfo.elem
        if type_elem.get('bitwidth') == '64':
            self.enumType[group_name] = 'XrFlags64'
        else:
            self.enumType[group_name] = 'XrFlags'

    def genType(self, typeinfo, name, alias):
        super().genType(typeinfo, name, alias)
        if self.is_flags(name) and alias is None:
            self.flagsType[name] = self.flags_types[name]
            bittype = typeinfo.elem.get('requires')
            if bittype is None:
                bittype = typeinfo.elem.get('bitvalues')
            if bittype is not None:
                self.flagBitsType[bittype] = name

    def make_decls(self):
        for flag in sorted(self.flagsType):
            body = 'struct {0}_t {{ }};'
            write(body.format(flag), file=self.outFile)

        for enum in sorted(self.enum_names):
            if enum.startswith('Vk') or 'Bits' in enum:
                continue
            if not enum in self.enumAliases:
                if enum in self.enumType and self.enumType[enum] == 'XrFlags64':
                    body = 'struct {0}_t {{ }};'
                    write(body.format(enum), file=self.outFile)

        self.newline()
        for enum in sorted(self.enum_names):
            if enum.startswith('Vk') or 'Bits' in enum:
                continue
            if not enum in self.processedEnums and not enum in self.SKIP_ENUM:
                self.processedEnums.add(enum)
                if not enum in self.enumAliases:
                    if enum in self.enumType and self.enumType[
                        enum] == 'XrFlags64':
                        body = 'void FieldToJson({0}_t, nlohmann::ordered_json& jdata, const {0}& value, const util::JsonOptions& options = util::JsonOptions());'
                    else:
                        body = 'void FieldToJson(nlohmann::ordered_json& jdata, const {0}& value, const util::JsonOptions& options = util::JsonOptions());'
                    write(body.format(enum), file=self.outFile)

        for flag in sorted(self.flagsType):
            body = 'void FieldToJson({0}_t, nlohmann::ordered_json& jdata, const {1} flags, const util::JsonOptions& options = util::JsonOptions());'
            write(body.format(flag, self.flagsType[flag]), file=self.outFile)
