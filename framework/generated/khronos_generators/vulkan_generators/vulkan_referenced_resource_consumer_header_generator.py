#!/usr/bin/python3 -i
#
# Copyright (c) 2020 LunarG, Inc.
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
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write


class VulkanReferencedResourceHeaderGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating the header to a C++ class for detecting unreferenced resource handles in a capture file."""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        VulkanBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )

        self.begin_end_file_data.specific_headers.extend((
            'decode/vulkan_referenced_resource_consumer_base.h',
            'util/defines.h',
        ))
        self.begin_end_file_data.namespaces.extend(('gfxrecon', 'decode'))


class VulkanReferencedResourceHeaderGenerator(VulkanBaseGenerator):
    """VulkanReferencedResourceHeaderGenerator - subclass of VulkanBaseGenerator.
    Generates C++ member definitions for the VulkanReferencedResource class responsible for
    determining which resource handles are used or unused in a capture file.
    Generate the header to a C++ class for detecting unreferenced resource handles in a capture file.
    """

    # All resource and resource associated handle types to be processed.
    RESOURCE_HANDLE_TYPES = [
        'VkBuffer', 'VkImage', 'VkBufferView', 'VkImageView', 'VkFramebuffer',
        'VkDescriptorSet', 'VkCommandBuffer', 'VkAccelerationStructureKHR'
    ]

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )
        self.restrict_handles = True  # Determines if the 'is_handle' override limits the handle test to only the values conained by RESOURCE_HANDLE_TYPES.

    def beginFile(self, gen_opts):
        """Method override."""
        VulkanBaseGenerator.beginFile(self, gen_opts)

        class_name = 'VulkanReferencedResourceConsumer'


        self.newline()
        write(
            'class {name} : public {name}Base'.format(name=class_name),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        write('    {}() {{ }}\n'.format(class_name), file=self.outFile)
        write(
            '    virtual ~{}() override {{ }}'.format(class_name),
            file=self.outFile
        )

    def endFile(self):
        """Method override."""
        for cmd, info in self.all_cmd_params.items():
            if self.is_cmd_black_listed(cmd):
                continue

            return_type = info[0]
            params = info[2]
            if params and params[0].base_type == 'VkCommandBuffer':
                # Check for parameters with resource handle types.
                handles = self.get_param_list_handles(params[1:])

                if (handles):
                    # Generate a function to build a list of handle types and values.
                    cmddef = '\n'

                    # Temporarily remove resource only matching restriction from is_handle() when generating the function signature.
                    self.restrict_handles = False
                    decl = self.make_consumer_func_decl(
                        return_type, 'Process_' + cmd, params
                    )
                    cmddef += self.indent(
                        'virtual ' + decl + ' override;', self.INDENT_SIZE
                    )
                    self.restrict_handles = True

                    write(cmddef, file=self.outFile)

        write('};', file=self.outFile)
        self.newline()

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_cmd_params:
            return True
        return False

    def is_handle(self, base_type):
        """Override method to check for handle type, only matching resource handle types."""
        if self.restrict_handles:
            if base_type in self.RESOURCE_HANDLE_TYPES:
                return True
            return False
        else:
            return VulkanBaseGenerator.is_handle(self, base_type)
