#!/usr/bin/python3 -i
#
# Copyright (c) 2019 Valve Corporation
# Copyright (c) 2019 LunarG, Inc.
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


class VulkanStructHandleWrappersHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating function prototypes to wrap Vulkan struct member handles at API capture."""

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


class VulkanStructHandleWrappersHeaderGenerator(BaseGenerator):
    """VulkanStructHandleWrappersHeaderGenerator - subclass of BaseGenerator.
    Generates C++ function prototypes for wrapping struct member handles
    when recording Vulkan API call parameter data.
    Generate C++ functions for Vulkan struct member handle wrapping at API capture.
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

        # Map of Vulkan structs containing handles to a list values for handle members or struct members
        # that contain handles (eg. VkGraphicsPipelineCreateInfo contains a VkPipelineShaderStageCreateInfo
        # member that contains handles).
        self.structs_with_handles = dict()
        self.output_structs = [
        ]  # Output structures that retrieve handles, which need to be wrapped.

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "encode/custom_vulkan_struct_handle_wrappers.h"',
            file=self.outFile
        )
        write('#include "encode/handle_unwrap_memory.h"', file=self.outFile)
        write(
            '#include "encode/vulkan_handle_wrapper_util.h"',
            file=self.outFile
        )
        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(vulkan_wrappers)', file=self.outFile)

    def endFile(self):
        """Method override."""
        self.newline()
        write(
            'VkBaseInStructure* CopyPNextStruct(const VkBaseInStructure* base, HandleUnwrapMemory* unwrap_memory);',
            file=self.outFile
        )
        self.newline()
        write(
            'const void* UnwrapPNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory);',
            file=self.outFile
        )
        self.newline()
        self.generate_create_wrapper_funcs()
        write(
            'template <typename ParentWrapper, typename CoParentWrapper, typename T>',
            file=self.outFile
        )
        write(
            'void CreateWrappedStructArrayHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    if (value != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write(
            '            CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value[i], get_id);',
            file=self.outFile
        )
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write(
            'T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write(
            '    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));',
            file=self.outFile
        )
        self.newline()
        write(
            '    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);',
            file=self.outFile
        )
        write(
            '    size_t         num_bytes = len * sizeof(T);',
            file=self.outFile
        )
        self.newline()
        write(
            '    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));',
            file=self.outFile
        )
        write('}', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write(
            'const T* UnwrapStructPtrHandles(const T* value, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    T* unwrapped_struct = nullptr;', file=self.outFile)
        self.newline()
        write('    if (value != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        unwrapped_struct = MakeUnwrapStructs(value, 1, unwrap_memory);',
            file=self.outFile
        )
        write(
            '        UnwrapStructHandles(unwrapped_struct, unwrap_memory);',
            file=self.outFile
        )
        write('    }', file=self.outFile)
        self.newline()
        write('    return unwrapped_struct;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('template <typename T>', file=self.outFile)
        write(
            'const T* UnwrapStructArrayHandles(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    if ((values != nullptr) && (len > 0))', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);',
            file=self.outFile
        )
        self.newline()
        write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
        write('        {', file=self.outFile)
        write(
            '            UnwrapStructHandles(&unwrapped_structs[i], unwrap_memory);',
            file=self.outFile
        )
        write('        }', file=self.outFile)
        self.newline()
        write('        return unwrapped_structs;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write(
            '    // Leave the original memory in place when the pointer is not null, but size is zero.',
            file=self.outFile
        )
        write('    return values;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(vulkan_wrappers)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.check_struct_member_handles(
                typename, self.structs_with_handles
            )

    def need_feature_generation(self):
        """Method override. Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members or self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        # Check for output structures, which retrieve handles that need to be wrapped.
        for cmd in self.feature_cmd_params:
            info = self.feature_cmd_params[cmd]
            values = info[2]

            for value in values:
                if self.is_output_parameter(value) and self.is_struct(
                    value.base_type
                ) and (value.base_type in self.structs_with_handles
                       ) and (value.base_type not in self.output_structs):
                    self.output_structs.append(value.base_type)

        # Generate unwrap and rewrap code for input structures.
        for struct in self.get_filtered_struct_names():
            if (
                (struct in self.structs_with_handles)
                or (struct in self.GENERIC_HANDLE_STRUCTS)
            ):
                body = '\n'
                body += 'void UnwrapStructHandles({}* value, HandleUnwrapMemory* unwrap_memory);'.format(
                    struct
                )
                write(body, file=self.outFile)

    def generate_create_wrapper_funcs(self):
        """Generates functions that wrap struct handle members."""
        for struct in self.output_structs:
            body = 'template <typename ParentWrapper, typename CoParentWrapper>\n'
            body += 'void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, {}* value, PFN_GetHandleId get_id)\n'.format(
                struct
            )
            body += '{\n'
            body += '    if (value != nullptr)\n'
            body += '    {\n'

            wrapper_prefix = self.get_wrapper_prefix_from_type()

            members = self.structs_with_handles[struct]
            for member in members:
                if self.is_struct(member.base_type):
                    if member.is_array:
                        body += '        vulkan_wrappers::CreateWrappedStructArrayHandles<ParentWrapper, CoParentWrapper, {}>(parent, co_parent, value->{}, value->{}, get_id);\n'.format(
                            member.base_type, member.name, member.array_length
                        )
                    elif member.is_pointer:
                        body += '        vulkan_wrappers::CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, value->{}, get_id);\n'.format(
                            member.name
                        )
                    else:
                        body += '        vulkan_wrappers::CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->{}, get_id);\n'.format(
                            member.name
                        )
                else:
                    if member.is_array:
                        body += '        vulkan_wrappers::CreateWrappedHandles<ParentWrapper, CoParentWrapper, {}::{}Wrapper>(parent, co_parent, value->{}, value->{}, get_id);\n'.format(
                            wrapper_prefix, member.base_type[2:], member.name, member.array_length
                        )
                    elif member.is_pointer:
                        body += '        vulkan_wrappers::CreateWrappedHandle<ParentWrapper, CoParentWrapper, {}::{}Wrapper>(parent, co_parent, value->{}, get_id);\n'.format(
                            wrapper_prefix, member.base_type[2:], member.name
                        )
                    else:
                        body += '        vulkan_wrappers::CreateWrappedHandle<ParentWrapper, CoParentWrapper, {}::{}Wrapper>(parent, co_parent, &value->{}, get_id);\n'.format(
                            wrapper_prefix, member.base_type[2:], member.name
                        )

            body += '    }\n'
            body += '}\n'
            write(body, file=self.outFile)
