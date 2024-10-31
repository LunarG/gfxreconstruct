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


class VulkanStructDeepCopySTypeBodyGeneratorOptions(BaseGeneratorOptions):
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


class VulkanStructDeepCopySTypeBodyGenerator(BaseGenerator):
    """VulkanStructTrackersHeaderGenerator - subclass of BaseGenerator.
    Generates C++ function definitions to track (deepcopy) Vulkan structs
    at API capture for trimming.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Map of typename to VkStructureType for each struct that is not an alias and has a VkStructureType associated
        self.struct_type_enums = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "graphics/vulkan_struct_deep_copy.h"',
            file=self.outFile
        )
        write('#include "format/platform_types.h"', file=self.outFile)
        write('#include "cstring"', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(graphics)', file=self.outFile)
        self.newline()
        write('inline uint8_t* offset_ptr(uint8_t* ptr, uint32_t offset)', file=self.outFile)
        write('{', file=self.outFile)
        write('    return ptr != nullptr ? ptr + offset : nullptr;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('size_t vulkan_struct_deep_copy_stype(const void* pNext, uint8_t* out_data)', file=self.outFile)
        write('{', file=self.outFile)
        write('    uint64_t offset = 0;', file=self.outFile)
        write('    auto     base    = reinterpret_cast<const VkBaseInStructure*>(pNext);', file=self.outFile)
        write('    uint8_t* out_ptr = offset_ptr(out_data, offset);', file=self.outFile)
        write('    switch (base->sType)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('            GFXRECON_LOG_WARNING("vulkan_struct_deep_copy_stype: unknown struct-type: %d", base->sType);', file=self.outFile)
        write('            break;', file=self.outFile)

    def endFile(self):
        """Method override."""
        write('    }', file=self.outFile)
        write('    return offset;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(graphics)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def checkType(self, typeinfo, typename):
        if typename in ['VkBaseInStructure',
                        'VkBaseOutStructure',
                        'VkXlibSurfaceCreateInfoKHR',
                        'VkXcbSurfaceCreateInfoKHR',
                        'VkWaylandSurfaceCreateInfoKHR',
                        'VkAndroidSurfaceCreateInfoKHR',
                        'VkImportAndroidHardwareBufferInfoANDROID',
                        'VkMetalSurfaceCreateInfoEXT',
                        'VkDirectFBSurfaceCreateInfoEXT',
                        'VkScreenSurfaceCreateInfoQNX',
                        'VkPushDescriptorSetWithTemplateInfoKHR'
                        ]:
            return False
        return True
    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if alias:
            return

        # Only process struct types that specify a 'structextends' tag, which indicates the struct can be used in a pNext chain.
        # parent_structs = typeinfo.elem.get('structextends')
        # if parent_structs and self.checkType(typeinfo, typename):
        if self.checkType(typeinfo, typename):
            stype = self.make_structure_type_enum(typeinfo, typename)
            if stype:
                write('        case {}:'.format(stype), file=self.outFile)
                write('            offset += vulkan_struct_deep_copy(', file=self.outFile)
                write('                reinterpret_cast<const {0}*>(pNext), 1, out_ptr);'.format(typename), file=self.outFile)
                write('            break;', file=self.outFile)

