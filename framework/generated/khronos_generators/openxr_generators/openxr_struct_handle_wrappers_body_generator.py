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

import re, sys
from base_generator import BaseGenerator, BaseGeneratorOptions, write
from collections import OrderedDict


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
        extraHeaders=[]
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
            extraHeaders=extraHeaders
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
            process_cmds=True,
            process_structs=True,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        self.next_structs_with_handles = dict(
        )  # Map of OpenXR structure types to type value for structs that can be part of a next chain and contain handles.
        self.next_structs = dict(
        )  # Map of OpenXR structure types to type value for structs that can be part of a next chain and do not contain handles.

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
        write('GFXRECON_BEGIN_NAMESPACE(openxr_wrappers)', file=self.outFile)

    def endFile(self):
        """Method override."""

        # Check for output structures, which retrieve handles that need to be wrapped.
        for cmd in self.cmd_names:
            info = self.all_cmd_params[cmd]
            values = info[2]

            for value in values:
                if self.is_output_parameter(value) and self.is_struct(
                    value.base_type
                ) and (value.base_type in self.structs_with_handles
                       ) and (value.base_type not in self.output_structs):
                    self.output_structs.append(value.base_type)
                    for member in self.all_struct_members[value.base_type]:
                        if self.is_struct(
                            member.base_type
                        ) and (member.base_type not in self.output_structs):
                            self.output_structs.append(member.base_type)

        for struct in self.all_structs:
            if (
                (struct in self.structs_with_handles)
                or (struct in self.GENERIC_HANDLE_STRUCTS)
            ):
                body = '\n'
                body += 'void UnwrapStructHandles({}* value, HandleUnwrapMemory* unwrap_memory)\n'.format(
                    struct
                )
                body += '{\n'
                body += '    if (value != nullptr)\n'
                body += '    {\n'

                if struct in self.base_header_structs.keys():
                    body += '        switch (value->type)\n'
                    body += '        {\n'
                    body += '            default:\n'
                    body += '                // Handle as base-type below\n'
                    body += '                break;\n'

                    for child in self.base_header_structs[struct]:
                        switch_type = self.generate_structure_type(child)

                        body += f'            case {switch_type}:\n'
                        body += f'                UnwrapStructHandles(reinterpret_cast<{child}*>(value),\n'
                        body += f'                                 unwrap_memory);\n'
                        body += '                // Return here because we processed the appropriate data in\n'
                        body += '                // the correct structure type\n'
                        body += '                return;\n'
                    body += '        }\n'
                    body += '\n'

                body += self.make_struct_handle_unwrappings(
                    struct, self.structs_with_handles[struct]
                )
                body += '    }\n'
                body += '}'

                write(body, file=self.outFile)

        # Generate the next shallow copy code, for next structs that don't have handles, but need to be preserved in the overall copy for handle wrapping.
        self.newline()
        write(
            'XrBaseInStructure* CopyNextStruct(const XrBaseInStructure* base, HandleUnwrapMemory* unwrap_memory)',
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
            '        GFXRECON_LOG_WARNING("Failed to copy entire next chain when unwrapping handles due to unrecognized type %d", base->type);',
            file=self.outFile
        )
        write('        break;', file=self.outFile)
        for base_type in self.next_structs:
            write(
                '    case {}:'.format(self.next_structs[base_type]),
                file=self.outFile
            )
            prefix = self.get_prefix_from_type(base_type)
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

        # Generate the next handle wrapping code.
        self.newline()
        write(
            'void* UnwrapNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory)',
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
            '            XrBaseInStructure* copy = CopyNextStruct(base, unwrap_memory);',
            file=self.outFile
        )
        write('            if (copy != nullptr)', file=self.outFile)
        write('            {', file=self.outFile)
        write(
            '                copy->next = reinterpret_cast<const XrBaseInStructure*>(UnwrapNextStructHandles(base->next, unwrap_memory));',
            file=self.outFile
        )
        write('            }', file=self.outFile)
        write('            return copy;', file=self.outFile)
        write('        }', file=self.outFile)
        for base_type in self.next_structs_with_handles:
            write(
                '        case {}:'.format(
                    self.next_structs_with_handles[base_type]
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
        write('GFXRECON_END_NAMESPACE(openxr_wrappers)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if self.process_structs and not self.is_struct_black_listed(
            typename
        ) and not alias:
            has_handles = self.check_struct_member_handles(
                typename, self.structs_with_handles
            )

            # Track this struct if it can be present in a next chain.
            parent_structs = typeinfo.elem.get('structextends')
            if parent_structs:
                type = self.makeStructureTypeEnum(typeinfo, typename)
                if type:
                    if has_handles:
                        self.next_structs_with_handles[typename] = type

                    self.next_structs[typename] = type

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members or self.feature_cmd_params:
            return True
        return False

    def make_struct_handle_unwrappings(self, name, handle_members):
        """Generating expressions for unwrapping struct handles before an API call."""
        body = ''

        for member in handle_members:
            if 'next' in member.name:
                body += '        if (value->next != nullptr)\n'
                body += '        {\n'
                body += '            value->next = UnwrapNextStructHandles(value->next, unwrap_memory);\n'
                body += '        }\n'
            elif self.is_struct(member.base_type):
                # This is a struct that includes handles.
                if member.is_array:
                    if 'const' in member.full_type:
                        temp_type = member.full_type
                        full_type_non_const = re.sub(' const ', '', temp_type)
                        full_type_non_const = re.sub(
                            'const ', '', full_type_non_const
                        )
                        full_type_non_const = re.sub(
                            ' const', '', full_type_non_const
                        )
                        variable_name = f'const_cast<{full_type_non_const}>(value->{member.name})'
                    else:
                        variable_name = f'value->{member.name}'

                    length_exprs = member.array_length.split(',')
                    length_count = len(length_exprs)

                    if member.pointer_count > 1 and length_count < member.pointer_count:
                        unwrap_function = 'UnwrapStructPtrArrayHandles'
                    else:
                        unwrap_function = 'UnwrapStructArrayHandles'

                    body += f'        value->{member.name} = {unwrap_function}({variable_name}, value->{member.array_length}, unwrap_memory);\n'

                elif member.is_pointer:
                    body += '        value->{name} = UnwrapStructPtrHandles(value->{name}, unwrap_memory);\n'.format(
                        name=member.name
                    )
                else:
                    body += '        UnwrapStructHandles(&value->{}, unwrap_memory);\n'.format(
                        member.name
                    )
        return body
