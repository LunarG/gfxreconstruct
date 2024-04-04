#!/usr/bin/python3 -i
#
# Copyright (c) 2023 LunarG, Inc.
# Copyright (c) 2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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


class VulkanStructTrackersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating function definitions to track (deepcopy) Vulkan structs at API capture for trimming."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraVulkanHeaders=[]
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
            extraVulkanHeaders=extraVulkanHeaders
        )


class VulkanStructTrackersBodyGenerator(BaseGenerator):
    """VulkanStructTrackersHeaderGenerator - subclass of BaseGenerator.
    Generates C++ function definitions to track (deepcopy) Vulkan structs
    at API capture for trimming.
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

        # Map of typename to VkStructureType for each struct that is not an alias and has a VkStructureType associated
        self.struct_type_enums = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write('#include "generated/generated_vulkan_struct_trackers.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(vulkan_trackers)', file=self.outFile)
        self.newline()

    def endFile(self):
        """Method override."""

        self.newline()
        write('void* TrackStruct(const void* value, HandleUnwrapMemory* unwrap_memory)', file=self.outFile)
        write('{', file=self.outFile)
        write('    if (value == nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        return nullptr;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    VkStructureType valueType = reinterpret_cast<const VkBaseInStructure*>(value)->sType;', file=self.outFile)
        write('    switch (valueType)', file=self.outFile)
        write('    {', file=self.outFile)
        for typename, struct_type_enum in self.struct_type_enums.items():
            write('        case {}:'.format(struct_type_enum), file=self.outFile)
            write('            return TrackStruct(reinterpret_cast<const {}*>(value), unwrap_memory);'.format(typename), file=self.outFile)
        write('        default:', file=self.outFile)
        write('            GFXRECON_LOG_ERROR("Unknown structure type: %u", valueType);', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    return nullptr;', file=self.outFile)
        write('}', file=self.outFile)

        self.newline()
        write('GFXRECON_END_NAMESPACE(vulkan_trackers)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if alias:
            return
        
        if typename in ['VkBaseInStructure', 'VkBaseOutStructure']:
            return
        
        struct_type_enum = self.make_structure_type_enum(typeinfo, typename)
        if struct_type_enum is None:
            return

        self.struct_type_enums[typename] = struct_type_enum
        
        write('{0}* TrackStruct(const {0}* value, HandleUnwrapMemory* unwrap_memory)'.format(typename), file=self.outFile)
        write('{', file=self.outFile)
        write('    if (value == nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        return nullptr;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    {}* unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);'.format(typename), file=self.outFile)
        self.newline()

        for value in self.feature_struct_members[typename]:
            if value.is_array and value.is_dynamic:
                if value.array_dimension == 1:
                    member_expr = f'unwrapped_struct->{value.name}'
                    length_expr = self.make_array_length_expression(value, 'unwrapped_struct->')
                    if value.base_type == 'void':
                        call_expr = f'MakeUnwrapVulkanStructs<uint8_t>(reinterpret_cast<const uint8_t*>({member_expr}), {length_expr}, unwrap_memory)'
                    else:
                        call_expr = f'MakeUnwrapVulkanStructs({member_expr}, {length_expr}, unwrap_memory)'
                    write('    if ({})'.format(member_expr), file=self.outFile)
                    write('    {', file=self.outFile)
                    write('        {} = {};'.format(member_expr, call_expr), file=self.outFile)
                    write('    }', file=self.outFile)
                else:
                    print(f'VulkanStructTrackersBodyGenerator ignored: {typename}.{value.name}') # TODO

        for value in self.feature_struct_members[typename]:
            if value.name == 'pNext':
                self.newline()
                write('    unwrapped_struct->pNext = TrackStruct(unwrapped_struct->pNext, unwrap_memory);', file=self.outFile)
                break
        
        self.newline()
        write('    return unwrapped_struct;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()

