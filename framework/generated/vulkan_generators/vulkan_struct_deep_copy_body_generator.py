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

preamble = '''
#include "graphics/vulkan_struct_deep_copy.h"
#include "format/platform_types.h"
#include "cstring"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// do not use for structs containing pointers
template <typename T>
inline size_t shallow_copy(const T* structs, uint32_t count, uint8_t* out_data)
{
    if (structs == nullptr)
    {
        return 0;
    }
    uint32_t num_bytes = sizeof(T) * count;
    if (out_data != nullptr)
    {
        memcpy(out_data, structs, num_bytes);
    }
    return num_bytes;
}

inline uint8_t* offset_ptr(uint8_t* ptr, uint32_t offset)
{
    return ptr != nullptr ? ptr + offset : nullptr;
}

template <typename T>
size_t vulkan_struct_deep_copy(const T* structs, uint32_t count, uint8_t* out_data)
{
     return shallow_copy(structs, count, out_data);
}

template <>
size_t vulkan_struct_deep_copy(const char* str, uint32_t /*count*/, uint8_t* out_data)
{
    if (str != nullptr)
    {
        size_t len = strlen(str);
        if (out_data != nullptr)
        {
            strcpy(reinterpret_cast<char*>(out_data), str);
        }
        return len + 1;
    }
    return 0;
}

template <>
size_t vulkan_struct_deep_copy(const void* structs, uint32_t count, uint8_t* out_data)
{
    // copy binary blob pointed to
    if (out_data != nullptr)
    {
        memcpy(out_data, structs, count);
    }
    return count;
}

template <typename T, typename U>
void handle_pointer(const T&  base_struct,
                    const U&  pointer_member,
                    uint32_t  count,
                    uint32_t  out_index,
                    uint64_t& offset,
                    uint8_t*  out_data)
{
    static_assert(std::is_pointer_v<U>);
    
    if (pointer_member == nullptr || count == 0)
    {
        return;
    }

    // member-offset within struct in bytes
    uint32_t member_offset =
        reinterpret_cast<const uint8_t*>(&pointer_member) - reinterpret_cast<const uint8_t*>(&base_struct);

    // copy pointer-chain recursively
    uint32_t copy_size = vulkan_struct_deep_copy(pointer_member, count, offset_ptr(out_data, offset));

    // re-direct pointers to point at copy
    if (out_data != nullptr)
    {
        auto* out_ptr = reinterpret_cast<U*>(out_data + out_index * sizeof(T) + member_offset);
        *out_ptr      = reinterpret_cast<U>(offset_ptr(out_data, offset));
    }
    offset += copy_size;
}

template <typename T>
void handle_pnext(const T& base_struct, uint32_t out_index, uint64_t& offset, uint8_t* out_data)
{
    if (base_struct.pNext != nullptr)
    {
        uint8_t* out_address = offset_ptr(out_data, offset);
        offset += vulkan_struct_deep_copy_stype(base_struct.pNext, out_address);
        if (out_address != nullptr)
        {
            void** out_pNext = reinterpret_cast<void**>(out_data + out_index * sizeof(T) + offsetof(T, pNext));
            *out_pNext       = out_address;
        }
    }
}

template <typename T, typename U>
void handle_struct_member(
    const T& base_struct, const U& struct_member, uint32_t out_index, uint64_t& offset, uint8_t* out_data)
{
    uint32_t member_offset =
        reinterpret_cast<const uint8_t*>(&struct_member) - reinterpret_cast<const uint8_t*>(&base_struct);

    auto out_address = offset_ptr(out_data, offset);
    offset += vulkan_struct_deep_copy_stype(&struct_member, out_address);

    if (out_data != nullptr)
    {
        auto& out_struct_member = *reinterpret_cast<U*>(out_data + out_index * sizeof(T) + member_offset);
        out_struct_member       = *reinterpret_cast<U*>(out_address);
    }
}

template <typename T, typename U>
void handle_array_of_pointers(const T&  base_struct,
                              const U&  struct_pointer_array,
                              uint32_t  struct_pointer_array_count,
                              uint32_t  out_index,
                              uint64_t& offset,
                              uint8_t*  out_data)
{
    using pointer_type = std::decay_t<decltype(*struct_pointer_array)>;
    static_assert(std::is_pointer_v<U> && std::is_pointer_v<pointer_type>);

    if (struct_pointer_array == nullptr || struct_pointer_array_count == 0)
    {
        return;
    }
    uint32_t copy_size = struct_pointer_array_count * sizeof(pointer_type);

    // member-offset within struct in bytes
    uint32_t member_offset =
        reinterpret_cast<const uint8_t*>(&struct_pointer_array) - reinterpret_cast<const uint8_t*>(&base_struct);

    for (uint32_t i = 0; i < struct_pointer_array_count; ++i)
    {
        uint32_t out_offset = offset + copy_size;

        // copy pointers in array recursively
        copy_size += vulkan_struct_deep_copy(struct_pointer_array[i], 1, offset_ptr(out_data, out_offset));

        // re-direct pointers to point at copy
        if (out_data != nullptr)
        {
            auto* out_ptr = reinterpret_cast<pointer_type*>(out_data + offset + i * sizeof(pointer_type));
            *out_ptr      = reinterpret_cast<pointer_type>(offset_ptr(out_data, out_offset));
        }
    }
    // re-direct array-pointer to point at copy
    if (out_data != nullptr)
    {
        auto* out_ptr = reinterpret_cast<U*>(out_data + out_index * sizeof(T) + member_offset);
        *out_ptr      = reinterpret_cast<U>(offset_ptr(out_data, offset));
    }
    offset += copy_size;
}
'''
class VulkanStructDeepCopyBodyGeneratorOptions(BaseGeneratorOptions):
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


class VulkanStructDeepCopyBodyGenerator(BaseGenerator):
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
        write(preamble, file=self.outFile)
        self.newline()

    def endFile(self):
        """Method override."""
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

    def getPointerCountExpression(self, typename, pointer_value):
        if typename == "VkPipelineMultisampleStateCreateInfo" and pointer_value.name == "pSampleMask":
            return "(base_struct.rasterizationSamples + 31) / 32"
        elif typename == "VkMicromapVersionInfoEXT" and pointer_value.name == "pVersionData":
            return "2 * VK_UUID_SIZE"
        elif typename == "VkAccelerationStructureVersionInfoKHR" and pointer_value.name == "pVersionData":
            return "2 * VK_UUID_SIZE"
        elif pointer_value.array_length:
            return "base_struct.{}".format(pointer_value.array_length).split(",")[0].replace(" ", "")
        else:
            return "1"

    def isExternalObject(self, value):
        """ external objects are referenced as void* pointers to non-array values. """
        return (value.is_pointer and not value.is_array) and value.base_type in self.EXTERNAL_OBJECT_TYPES

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if alias or not self.checkType(typeinfo, typename):
            return

        has_pointer_members = False
        has_pNext = False

        for value in self.feature_struct_members[typename]:
            if value.name == 'pNext':
                has_pNext = True
            elif value.is_pointer and not self.isExternalObject(value):
                has_pointer_members = True

        if not (has_pointer_members or has_pNext):
            return

        write('template <>', file=self.outFile)
        write('size_t vulkan_struct_deep_copy(const {0}* structs, uint32_t count, uint8_t* out_data)'.format(typename), file=self.outFile)
        write('{', file=self.outFile)
        write('    using struct_type              = std::decay_t<decltype(*structs)>;', file=self.outFile)
        write('    constexpr uint32_t struct_size = sizeof(struct_type);', file=self.outFile)
        self.newline()
        write('    if (structs == nullptr || count == 0)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        return 0;', file=self.outFile)
        write('    }', file=self.outFile)
        write('    uint64_t offset = struct_size * count;', file=self.outFile)
        self.newline()
        write('    for (uint32_t i = 0; i < count; ++i)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        const auto& base_struct = structs[i];', file=self.outFile)
        write('        if (out_data != nullptr)', file=self.outFile)
        write('        {', file=self.outFile)
        write('            auto out_structures = reinterpret_cast<struct_type*>(out_data);', file=self.outFile)
        write('            out_structures[i]   = base_struct;', file=self.outFile)
        write('        }', file=self.outFile)

        for value in self.feature_struct_members[typename]:
            if value.name == 'pNext':
                write('        handle_pnext(base_struct, i, offset, out_data);', file=self.outFile)
            elif value.is_pointer and not self.isExternalObject(value):
                count_exp = self.getPointerCountExpression(typename, value)
                if value.pointer_count == 1:
                    write('        handle_pointer(base_struct, base_struct.{0}, {1}, i, offset, out_data);'.format(value.name, count_exp), file=self.outFile)
                elif value.pointer_count == 2:
                    write('        handle_array_of_pointers(base_struct, base_struct.{0}, {1}, i, offset, out_data);'.format(value.name, count_exp), file=self.outFile)
            elif value.base_type in ["VkPipelineShaderStageCreateInfo", "VkAccelerationStructureGeometryDataKHR"]:
                write('        handle_struct_member(base_struct, base_struct.{0}, i, offset, out_data);'.format(value.name), file=self.outFile)
        write('    }', file=self.outFile)
        write('    return offset;', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()

