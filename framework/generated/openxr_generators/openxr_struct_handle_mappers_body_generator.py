#!/usr/bin/python3 -i
#
# Copyright (c) 2019-2020 Valve Corporation
# Copyright (c) 2019-2024 LunarG, Inc.
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
from base_generator import BaseGenerator, BaseGeneratorOptions, write
from base_struct_handle_mappers_body_generator import BaseStructHandleMappersBodyGenerator


class OpenXrStructHandleMappersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating functions to map OpenXR struct member handles at file replay."""

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


class OpenXrStructHandleMappersBodyGenerator(
    BaseStructHandleMappersBodyGenerator, BaseGenerator
):
    """OpenXrStructHandleMappersBodyGenerator - subclass of BaseGenerator.
    Generates C++ functions responsible for mapping struct member handles
    when replaying decoded OpenXR API call parameter data.
    Generate C++ functions for OpenXR struct member handle mapping at file replay.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )
        BaseStructHandleMappersBodyGenerator.__init__(self)

        self.gen_struct_replay_info = []
        self.gen_cmd_replay_info = []

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_openxr_struct_handle_mappers.h"',
            file=self.outFile
        )
        write(
            '#include "decode/custom_openxr_struct_decoders.h"',
            file=self.outFile
        )
        write('#include "decode/handle_pointer_decoder.h"', file=self.outFile)
        write(
            '#include "decode/openxr_handle_mapping_util.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_openxr_struct_decoders.h"',
            file=self.outFile
        )
        write(
            '#include "generated/generated_openxr_struct_handle_mappers.h"',
            file=self.outFile
        )
        self.newline()
        write('#include <algorithm>', file=self.outFile)
        write('#include <cassert>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)

    def endFile(self):
        """Method override."""

        # Execute the deferred gen struct operations
        for (typeinfo, typename, alias) in self.gen_struct_replay_info:
            BaseGenerator.genStruct(self, typeinfo, typename, alias, True, False)
            self.local_gen_struct(typeinfo, typename, alias)

        for (cmdinfo, name, alias) in self.gen_cmd_replay_info:
            BaseGenerator.genCmd(self, cmdinfo, name, alias, True, False)
            self.local_gen_cmd(cmdinfo, name, alias)

        # Create the struct handle mappers for all features
        self.generate_struct_mappers(self.get_filtered_all_feature_struct_names())

        BaseStructHandleMappersBodyGenerator.endFile(self)
        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias, False, True)

        self.gen_struct_replay_info.append([typeinfo, typename, alias])
        #self.local_gen_struct(typeinfo, typename, alias)

    def local_gen_struct(self, typeinfo, typename, alias):
        if not alias:
            has_handles = self.check_struct_member_handles(
                typename, self.structs_with_handles
            )

            # Track this struct if it can be present in a next chain.
            parent_structs = typeinfo.elem.get('structextends')
            if parent_structs:
                type = self.make_structure_type_enum(typeinfo, typename)
                if type:
                    if has_handles:
                        self.pnext_structs_with_handles[typename] = type

                    self.pnext_structs[typename] = type

    def genCmd(self, cmdinfo, name, alias):
        """Method override."""
        BaseGenerator.genCmd(self, cmdinfo, name, alias, False, True)
        self.gen_cmd_replay_info.append([cmdinfo, name, alias])

    def local_gen_cmd(self, cmdinfo, name, alias):
        # Look for output structs that contain handles and add to list
        if not alias:
            for value_info in self.feature_cmd_params[name][2]:
                if self.is_output_parameter(value_info) and (
                    value_info.base_type in self.get_filtered_feature_struct_names()
                ) and (value_info.base_type in self.structs_with_handles) and (
                    value_info.base_type
                    not in self.output_structs_with_handles
                ):
                    self.output_structs_with_handles.append(
                        value_info.base_type
                    )

                    # Make sure to decode any struct with handles associated with this output
                    # structure as well
                    if value_info.base_type in self.structs_with_handles:
                        for member in self.structs_with_handles[
                            value_info.base_type]:
                            if self.is_struct(member.base_type):
                                self.output_structs_with_handles.append(
                                    member.base_type
                                )

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members:
            return True
        return False
