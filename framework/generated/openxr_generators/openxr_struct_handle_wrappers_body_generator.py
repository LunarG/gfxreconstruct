#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
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


class OpenXrStructHandleWrappersBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating functions to wrap OpenXR API struct member handles at API capture."""

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


class OpenXrStructHandleWrappersBodyGenerator(BaseGenerator):
    """OpenXrStructHandleWrappersBodyGenerator - subclass of BaseGenerator.
    Generates C++ functions responsible for wrapping struct member handles
    when recording OpenXR API call parameter data.
    Generate C++ functions for OpenXr struct member handle wrapping at API capture.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=False,
            process_structs=True,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Map of OpenXr structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structs_with_handles = dict()
        self.pnext_structs_with_handles = dict(
        )  # Map of OpenXR structure types to type value for structs that can be part of a pNext chain and contain handles.
        self.pnext_structs = dict(
        )  # Map of OpenXR structure types to type value for structs that can be part of a pNext chain and do not contain handles.

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_openxr_struct_handle_wrappers.h"',
            file=self.outFile
        )
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)

    def endFile(self):
        """Method override."""
        # Generate the pNext shallow copy code, for pNext structs that don't have handles, but need to be preserved in the overall copy for handle wrapping.
        self.newline()
        write(
            'XrBaseInStructure* CopyPNextStruct(const XrBaseInStructure* base, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    assert(base != nullptr);', file=self.outFile)
        self.newline()
        write('    XrBaseInStructure* copy = nullptr;', file=self.outFile)
        write('    switch (base->type)', file=self.outFile)
        write('    {', file=self.outFile)
        write('    default:', file=self.outFile)
        write(
            '        GFXRECON_LOG_WARNING("Failed to copy entire pNext chain when unwrapping handles due to unrecognized type %d", base->type);',
            file=self.outFile
        )
        write('        break;', file=self.outFile)
        for base_type in self.pnext_structs:
            write(
                '    case {}:'.format(self.pnext_structs[base_type]),
                file=self.outFile
            )
            write(
                '        copy = reinterpret_cast<XrBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const {}*>(base), 1, unwrap_memory));'
                .format(base_type),
                file=self.outFile
            )
            write('        break;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    return copy;', file=self.outFile)
        write('}', file=self.outFile)

        # Generate the pNext handle wrapping code.
        self.newline()
        write(
            'const void* UnwrapPNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    if (value != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        const XrBaseInStructure* base = reinterpret_cast<const XrBaseInStructure*>(value);',
            file=self.outFile
        )
        self.newline()
        write('        switch (base->type)', file=self.outFile)
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('        {', file=self.outFile)
        write(
            '            // This structure does not contain handles, but may point to a structure that does.',
            file=self.outFile
        )
        write(
            '            XrBaseInStructure* copy = CopyPNextStruct(base, unwrap_memory);',
            file=self.outFile
        )
        write('            if (copy != nullptr)', file=self.outFile)
        write('            {', file=self.outFile)
        write(
            '                copy->pNext = reinterpret_cast<const XrBaseInStructure*>(UnwrapPNextStructHandles(base->pNext, unwrap_memory));',
            file=self.outFile
        )
        write('            }', file=self.outFile)
        write('            return copy;', file=self.outFile)
        write('        }', file=self.outFile)
        for base_type in self.pnext_structs_with_handles:
            write(
                '        case {}:'.format(
                    self.pnext_structs_with_handles[base_type]
                ),
                file=self.outFile
            )
            write(
                '            return UnwrapStructPtrHandles(reinterpret_cast<const {}*>(base), unwrap_memory);'
                .format(base_type),
                file=self.outFile
            )
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    return nullptr;', file=self.outFile)
        write('}', file=self.outFile)

        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            has_handles = self.check_struct_member_handles(
                typename, self.structs_with_handles
            )

            # Track this struct if it can be present in a pNext chain.
            parent_structs = typeinfo.elem.get('structextends')
            if parent_structs:
                type = self.make_structure_type_enum(typeinfo, typename)
                if type:
                    if has_handles:
                        self.pnext_structs_with_handles[typename] = type

                    self.pnext_structs[typename] = type

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        for struct in self.get_filtered_struct_names():
            if (
                (struct in self.structs_with_handles)
                or (struct in self.GENERIC_HANDLE_STRUCTS)
            ):
                handle_members = dict()
                generic_handle_members = dict()

                if struct in self.structs_with_handles:
                    handle_members = self.structs_with_handles[struct]
                if struct in self.GENERIC_HANDLE_STRUCTS:
                    generic_handle_members = self.GENERIC_HANDLE_STRUCTS[struct
                                                                         ]

                body = '\n'
                body += 'void UnwrapStructHandles({}* value, HandleUnwrapMemory* unwrap_memory)\n'.format(
                    struct
                )
                body += '{\n'
                body += '    if (value != nullptr)\n'
                body += '    {\n'
                body += self.make_struct_handle_unwrappings(
                    struct, handle_members, generic_handle_members
                )
                body += '    }\n'
                body += '}'

                write(body, file=self.outFile)

    def make_struct_handle_unwrappings(
        self, name, handle_members, generic_handle_members
    ):
        """Generating expressions for unwrapping struct handles before an API call."""
        body = ''

        for member in handle_members:
            if 'pNext' in member.name:
                body += '        if (value->pNext != nullptr)\n'
                body += '        {\n'
                body += '            value->pNext = UnwrapPNextStructHandles(value->pNext, unwrap_memory);\n'
                body += '        }\n'
            elif self.is_struct(member.base_type):
                # This is a struct that includes handles.
                if member.is_array:
                    body += '        value->{name} = UnwrapStructArrayHandles(value->{name}, value->{}, unwrap_memory);\n'.format(
                        member.array_length, name=member.name
                    )
                elif member.is_pointer:
                    body += '        value->{name} = UnwrapStructPtrHandles(value->{name}, unwrap_memory);\n'.format(
                        name=member.name
                    )
                else:
                    body += '        UnwrapStructHandles(&value->{}, unwrap_memory);\n'.format(
                        member.name
                    )
        return body
