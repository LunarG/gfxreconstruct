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
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions, write
from khronos_struct_handle_wrappers_body_generator import KhronosStructHandleWrappersBodyGenerator


class VulkanStructHandleWrappersBodyGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating functions to wrap Vulkan struct member handles at API capture."""

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


class VulkanStructHandleWrappersBodyGenerator(VulkanBaseGenerator, KhronosStructHandleWrappersBodyGenerator):
    """VulkanStructHandleWrappersBodyGenerator - subclass of VulkanBaseGenerator.
    Generates C++ functions responsible for wrapping struct member handles
    when recording Vulkan API call parameter data.
    Generate C++ functions for Vulkan struct member handle wrapping at API capture.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def beginFile(self, gen_opts):
        """Method override."""
        VulkanBaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_vulkan_struct_handle_wrappers.h"',
            file=self.outFile
        )
        self.newline()
        write('#include "vulkan/vk_layer.h"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(vulkan_wrappers)', file=self.outFile)

    def endFile(self):
        """Method override."""
        KhronosStructHandleWrappersBodyGenerator.write_struct_handle_wrapper_content(self)

        self.newline()
        write('GFXRECON_END_NAMESPACE(vulkan_wrappers)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        VulkanBaseGenerator.endFile(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.feature_struct_members:
            return True
        return False

    def write_special_case_struct_handling(self):
        """Method override."""
        write(
            '    case VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO:',
            file=self.outFile
        )
        write(
            '        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLayerInstanceCreateInfo*>(base), 1, unwrap_memory));',
            file=self.outFile
        )
        write('        break;', file=self.outFile)
        write(
            '    case VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO:',
            file=self.outFile
        )
        write(
            '        copy = reinterpret_cast<VkBaseInStructure*>(MakeUnwrapStructs(reinterpret_cast<const VkLayerDeviceCreateInfo*>(base), 1, unwrap_memory));',
            file=self.outFile
        )
        write('        break;', file=self.outFile)

    def has_special_case_handle_unwrapping(self, name):
        """Method override."""
        if (name == 'VkGeneratedCommandsMemoryRequirementsInfoEXT'):
            return True
        return False

    def get_special_case_handle_wrapping(self, name):
        """Method override."""
        # Workaround for spec missing const in VkGeneratedCommandsMemoryRequirementsInfoEXT::pNext, should be removed next header update
        if (name == 'VkGeneratedCommandsMemoryRequirementsInfoEXT'):
            return '            value->pNext = const_cast<void*>(UnwrapPNextStructHandles(value->pNext, unwrap_memory));\n'
        return ''
