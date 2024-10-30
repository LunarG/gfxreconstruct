#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2021 Valve Corporation
# Copyright (c) 2018-2024 LunarG, Inc.
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
#
# The content of this file was derived from the Khronos Registry cgenerator.py
# and related Python files found in the KhronosGroup/Vulkan-Headers GitHub repository.
#
# Copyright (c) 2013-2016 The Khronos Group Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# The content of this file was derived from the Khronos Registry cgenerator.py
# and related Python files found in the KhronosGroup/Vulkan-Headers GitHub repository.

import os,re,sys,json
from collections import OrderedDict
from khronos_base_generator import (KhronosBaseGeneratorOptions, KhronosBaseGenerator, BitsEnumToFlagsTypedef, make_re_string, remove_suffix, ValueInfo, write)
from generator import (OutputGenerator, noneStr, regSortFeatures)
from vkconventions import VulkanConventions


# Descriptive names for various regexp patterns used to select versions and extensions.
# From Khronos genvk.py
_default_extensions = 'vulkan'
_extensions = _features = []
_emit_extensions = []

# Exclude extensions from code generation.
# Note this doesn't totally eliminate them. ToString and ToJson functions for enums
# will always be generated but functions and structs can be screened out by editing
# the blocklists files such as the vulkan default "vulkan_generators/blacklists.json".
# Note, this doesn't hide them from the  application, but lets them bypass our
# layer during capture, meaning we will not call any of their functions at
# replay.
# To screen an extension out from the list reported to the application it should
# be added to the list kUnsupportedDeviceExtensions in trace_layer.cpp.
_remove_extensions = [
    "VK_AMDX_shader_enqueue",
    ## @todo <https://github.com/LunarG/gfxreconstruct/issues/917>
    "VK_EXT_descriptor_buffer",
    "VK_EXT_metal_objects",
    "VK_EXT_pipeline_properties",
    "VK_FUCHSIA_buffer_collection",
    "VK_HUAWEI_subpass_shading", # Limited tile shader
    "VK_NVX_binary_import",
    "VK_NV_copy_memory_indirect",
    "VK_NV_memory_decompression",
    "VK_QNX_external_memory_screen_buffer",
    "VK_NV_cuda_kernel_launch",
]

# Turn lists of names/patterns into matching regular expressions.
# From Khronos genvk.py
_add_extensions_pat = make_re_string(_extensions)
_remove_extensions_pat = make_re_string(_remove_extensions)
_emit_extensions_pat = make_re_string(_emit_extensions, '.*')
_features_pat = make_re_string(_features, '.*')


class BaseGeneratorOptions(KhronosBaseGeneratorOptions):
    """BaseGeneratorOptions - subclass of KhronosGeneratorOptions.
    Options for Vulkan API parameter encoding and decoding C++ code generation.

    Adds options used by FrameworkGenerator objects during C++ language
    code generation.

    Additional members
      blacklists - Path to JSON file listing apicalls and structs to ignore.
      platform_types - Path to JSON file listing platform (WIN32, X11, etc.)
        specific types that are defined outside of the Vulkan header.

    Additional members (from Khronos Registry COptionsGenerator)
      prefix_text - list of strings to prefix generated header with
        (usually a copyright statement + calling convention macros).
      protect_file - True if multiple inclusion protection should be
        generated (based on the filename) around the entire header.
      apicall - string to use for the function declaration prefix,
        such as APICALL on Windows.
      apientry - string to use for the calling convention macro,
        in typedefs, such as APIENTRY.
      apientryp - string to use for the calling convention macro
        in function pointer typedefs, such as APIENTRYP.
      indent_func_proto - True if prototype declarations should put each
        parameter on a separate line
      indent_func_pointer - True if typedefed function pointers should put each
        parameter on a separate line
      align_func_param - if nonzero and parameters are being put on a
        separate line, align parameter names at the specified column
    """

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        # Khronos CGeneratorOptions
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        conventions=VulkanConventions(),
        apicall='VKAPI_ATTR ',
        apientry='VKAPI_CALL ',
        apientryp='VKAPI_PTR *',
        indent_func_proto=True,
        align_func_param=48,
        sort_procedure=regSortFeatures,
        apiname='vulkan',
        profile=None,
        versions=_features_pat,
        emit_versions=_features_pat,
        default_extensions=_default_extensions,
        add_extensions=_add_extensions_pat,
        remove_extensions=_remove_extensions_pat,
        emit_extensions=_emit_extensions_pat,
        extraVulkanHeaders=[]
    ):
        KhronosBaseGeneratorOptions.__init__(
            self,
            blacklists=blacklists,
            platform_types=platform_types,
            filename=filename,
            directory=directory,
            prefix_text=prefix_text,
            protect_file=protect_file,
            protect_feature=protect_feature,
            conventions=conventions,
            apicall=apicall,
            apientry=apientry,
            apientryp=apientryp,
            indent_func_proto=True,
            align_func_param=align_func_param,
            sort_procedure=sort_procedure,
            apiname=apiname,
            profile=profile,
            versions=versions,
            emit_versions=emit_versions,
            default_extensions=_default_extensions,
            add_extensions=add_extensions,
            remove_extensions=remove_extensions,
            emit_extensions=emit_extensions,
            extraVulkanHeaders=extraVulkanHeaders
        )


class BaseGenerator(KhronosBaseGenerator):
    """BaseGenerator - subclass of KhronosBaseGenerator.
    Base class providing common operations used to generate C++-language code for framework
      components that encode and decode Vulkan API parameters.
    Base class for Vulkan API parameter encoding and decoding generators.
    """

    def __init__(
        self,
        process_cmds=False,
        process_structs=False,
        feature_break=True,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout
    ):
        KhronosBaseGenerator.__init__(
            self,
            process_cmds=process_cmds,
            process_structs=process_structs,
            feature_break=feature_break,
            err_file = err_file,
            warn_file = warn_file,
            diag_file = diag_file)

        self.SUPPORTED_SUBSETS= [ "vulkan"]

        # These structures should be ignored for handle mapping/unwrapping. They require special implementations.
        self.STRUCT_MAPPERS_BLACKLIST = ['VkAccelerationStructureBuildGeometryInfoKHR']

        self.GENERIC_HANDLE_APICALLS = {
            'vkDebugReportMessageEXT': {
                'object': 'objectType'
            },
            'vkSetPrivateDataEXT': {
                'objectHandle': 'objectType'
            },
            'vkGetPrivateDataEXT': {
                'objectHandle': 'objectType'
            },
            'vkSetPrivateData': {
                'objectHandle': 'objectType'
            },
            'vkGetPrivateData': {
                'objectHandle': 'objectType'
            }
        }

        self.GENERIC_HANDLE_STRUCTS = {
            'VkDebugMarkerObjectNameInfoEXT': {
                'object': 'objectType'
            },
            'VkDebugMarkerObjectTagInfoEXT': {
                'object': 'objectType'
            },
            'VkDebugUtilsObjectNameInfoEXT': {
                'objectHandle': 'objectType'
            },
            'VkDebugUtilsObjectTagInfoEXT': {
                'objectHandle': 'objectType'
            }
        }

        self.REPLACE_TYPE = {
            "VkRemoteAddressNV": {
                "baseType": "void",
                "replaceWith": "void*"
            }
        }

        self.MAP_STRUCT_TYPE = {
            'D3D12_GPU_DESCRIPTOR_HANDLE': [
                'MapGpuDescriptorHandle', 'MapGpuDescriptorHandles',
                'descriptor_map'
            ],
            'D3D12_GPU_VIRTUAL_ADDRESS':
            ['MapGpuVirtualAddress', 'MapGpuVirtualAddresses', 'gpu_va_map']
        }

        self.DUPLICATE_HANDLE_TYPES = [
            'VkDescriptorUpdateTemplateKHR', 'VkSamplerYcbcrConversionKHR', 'VkPrivateDataSlotEXT'
        ]

        self.VIDEO_TREE = None

        self.generate_video = False

    def beginFile(self, gen_opts):
        """Method override."""
        KhronosBaseGenerator.beginFile(self, gen_opts)

    def includeVulkanHeaders(self, gen_opts):
        """Write Vulkan header include statements
        """
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        write('#include "vk_video/vulkan_video_codec_h264std.h"', file=self.outFile)
        write('#include "vk_video/vulkan_video_codec_h264std_decode.h"', file=self.outFile)
        write('#include "vk_video/vulkan_video_codec_h264std_encode.h"', file=self.outFile)
        write('#include "vk_video/vulkan_video_codec_h265std.h"', file=self.outFile)
        write('#include "vk_video/vulkan_video_codec_h265std_decode.h"', file=self.outFile)
        write('#include "vk_video/vulkan_video_codec_h265std_encode.h"', file=self.outFile)
        write('#include "vk_video/vulkan_video_codecs_common.h"', file=self.outFile)

        KhronosBaseGenerator.include_extra_headers(self, gen_opts)

    def endFile(self):
        """Method override. Generate code for the feature."""
        KhronosBaseGenerator.endFile(self)

    def beginFeature(self, interface, emit):
        """Method override. Start processing in superclass."""
        KhronosBaseGenerator.beginFeature(self, interface, emit)

        if not self.generate_video:
            self.gen_video_type()
            self.generate_video = True

    def endFeature(self):
        """Method override. Generate code for the feature."""
        KhronosBaseGenerator.endFeature(self)

    def gen_video_type(self):
        if not self.VIDEO_TREE:
            return

        if self.process_structs:
            types = self.VIDEO_TREE.find('types')
            for element in types.iter('type'):
                name = element.get('name')
                category = element.get('category')
                if name and category and (category == 'struct' or category == 'union'):
                    self.struct_names.add(name)
                    if category == 'struct':
                        self.feature_struct_members[name] = self.make_value_info(
                            element.findall('member')
                        )

        for element in self.VIDEO_TREE.iter('enums'):
            group_name = element.get('name')
            self.enum_names.add(group_name)
            enumerants = dict()
            for elem in element.findall('enum'):
                name = elem.get('name')
                value = elem.get('value')
                if value:
                    enumerants[name] = value
            self.enumEnumerants[group_name] = enumerants

    def get_default_handle_atom_value(self, base_type):
        return 'VK_NULL_HANDLE'

    def check_struct_pnext_handles(self, typename):
        """Determines if the specified struct type can reference pNext extension structs that contain handles."""
        found_handles = False
        found_handle_ptrs = False
        valid_extension_structs = self.registry.validextensionstructs.get(
            typename
        )
        if valid_extension_structs:
            # Need to search the XML tree for pNext structures that have not been processed yet.
            for struct_name in valid_extension_structs:
                # Check for cached results from a previous check for this struct
                if struct_name in self.extension_structs_with_handles:
                    if self.extension_structs_with_handles[struct_name]:
                        found_handles = True
                    if self.extension_structs_with_handle_ptrs[struct_name]:
                        found_handle_ptrs = True
                else:
                    # If a pre-existing result was not found, check the XML registry for the struct
                    has_handles = False
                    hasHandlePtrs = False
                    type_info = self.registry.lookupElementInfo(
                        struct_name, self.registry.typedict
                    )
                    if type_info:
                        member_infos = [
                            member for member in
                            type_info.elem.findall('.//member/type')
                        ]
                        if member_infos:
                            for member_info in member_infos:
                                found = self.registry.tree.find(
                                    "types/type/[name='" + member_info.text
                                    + "'][@category='handle']"
                                )
                                if found:
                                    has_handles = True
                                    self.extension_structs_with_handles[
                                        struct_name] = True
                                    if member_info.tail and (
                                        '*' in member_info.tail
                                    ):
                                        self.extension_structs_with_handle_ptrs[
                                            struct_name] = True
                                        hasHandlePtrs = True
                                    else:
                                        self.extension_structs_with_handle_ptrs[
                                            struct_name] = False

                    if has_handles:
                        found_handles = True
                        if hasHandlePtrs:
                            found_handle_ptrs = True
                    else:
                        self.extension_structs_with_handles[struct_name
                                                            ] = False
                        self.extension_structs_with_handle_ptrs[struct_name
                                                                ] = False

        return found_handles, found_handle_ptrs

    def check_struct_member_handles(
        self,
        typename,
        structs_with_handles,
        structs_with_handle_ptrs=None,
        ignore_output=False,
        structs_with_map_data=None,
        extra_types=None
    ):
        """Determines if the specified struct type contains members that have a handle type or are structs that contain handles.
        Structs with member handles are added to a dictionary, where the key is the structure type and the value is a list of the handle members.
        An optional list of structure types that contain handle members with pointer types may also be generated.
        """
        handles = []
        has_handle_pointer = False
        map_data = []
        for value in self.feature_struct_members[typename]:
            if self.is_handle(value.base_type) or (
                extra_types and value.base_type in extra_types
            ):
                # The member is a handle.
                handles.append(value)
                if (
                    (structs_with_handle_ptrs is not None)
                    and (value.is_pointer or value.is_array)
                ):
                    has_handle_pointer = True
            elif self.is_struct(value.base_type) and (
                (value.base_type in structs_with_handles) and
                ((not ignore_output) or (not '_Out_' in value.full_type))
            ):
                # The member is a struct that contains a handle.
                handles.append(value)
                if (
                    (structs_with_handle_ptrs is not None)
                    and (value.name in structs_with_handle_ptrs)
                ):
                    has_handle_pointer = True
            elif self.is_union(value.base_type):
                # Check the anonymous union for objects.
                union_members = self.get_union_members(value.base_type)
                for union_info in union_members:
                    if self.is_struct(
                        union_info.base_type
                    ) and (union_info.base_type in structs_with_handles):
                        handles.append(value)
                        has_handle_pointer = True
                    elif union_info.base_type in self.source_dict['class_dict'
                                                                  ]:
                        handles.append(value)
                        has_handle_pointer = True
                    elif union_info.base_type in self.MAP_STRUCT_TYPE:
                        if (structs_with_map_data is not None):
                            map_data.append(value)
            elif ('pNext' in value.name):
                # The pNext chain may include a struct with handles.
                has_pnext_handles, has_pnext_handle_ptrs = self.check_struct_pnext_handles(
                    typename
                )
                if has_pnext_handles:
                    handles.append(value)
                    if (
                        structs_with_handle_ptrs is not None
                    ) and has_pnext_handle_ptrs:
                        has_handle_pointer = True

            if (structs_with_map_data is not None) and (
                (value.base_type in self.MAP_STRUCT_TYPE) or
                (value.base_type in structs_with_map_data)
            ):
                map_data.append(value)

        if map_data:
            structs_with_map_data[typename] = map_data

        if handles:
            # Process the list of struct members a second time to check for
            # members with the same type as the struct.  The current struct
            # type has not been added to the table of structs with handles
            # yet, so we must check the struct members a second time, looking
            # for members with the struct type, now that we know the current
            # struct type contains members that are handles/objects.  Any
            # struct members that have the same type as the struct must be
            # added to the handle member list.
            for value in self.feature_struct_members[typename]:
                if (value.base_type == typename) and (
                    (not ignore_output) or (not '_Out_' in value.full_type)
                ):
                    handles.append(value)

            structs_with_handles[typename] = handles
            if (structs_with_handle_ptrs is not None) and has_handle_pointer:
                structs_with_handle_ptrs.append(typename)
            return True
        return False

    def make_decoded_param_type(self, value):
        """Create a type to use for a decoded parameter, using the decoder wrapper types for pointers."""
        type_name = value.base_type

        # is_pointer will be False for static arrays.
        if value.is_pointer or value.is_array:
            count = value.pointer_count

            if self.is_struct(type_name):
                if count > 1:
                    type_name = 'StructPointerDecoder<Decoded_{}*>'.format(
                        type_name
                    )
                else:
                    type_name = 'StructPointerDecoder<Decoded_{}>'.format(
                        type_name
                    )
            elif type_name == 'wchar_t':
                if count > 1:
                    type_name = 'WStringArrayDecoder'
                else:
                    type_name = 'WStringDecoder'
            elif type_name == 'char':
                if count > 1:
                    type_name = 'StringArrayDecoder'
                else:
                    type_name = 'StringDecoder'
            elif type_name == 'void':
                if value.is_array:
                    # If this was an array (void*) it was encoded as an array of bytes.
                    type_name = 'PointerDecoder<uint8_t>'
                elif count > 1:
                    # If this was a pointer to a pointer to an unknown object (void**), it was encoded as a pointer to a 64-bit address value.
                    # So, we specify uint64_t as the decode type and void* as the type to be used for Vulkan API call output parameters.
                    type_name = 'PointerDecoder<uint64_t, void*>'
                else:
                    # If this was a pointer to an unknown object (void*), it was encoded as a 64-bit address value.
                    type_name = 'uint64_t'
            elif self.is_handle(type_name):
                type_name = 'HandlePointerDecoder<{}>'.format(type_name)
            else:
                if count > 1:
                    type_name = 'PointerDecoder<{}*>'.format(type_name)
                else:
                    type_name = 'PointerDecoder<{}>'.format(type_name)
        elif self.is_function_ptr(type_name):
            # Function pointers are encoded as a 64-bit address value.
            type_name = 'uint64_t'
        elif self.is_struct(type_name):
            type_name = 'Decoded_{}'.format(type_name)
        elif self.is_handle(type_name):
            type_name = 'format::HandleId'
        else:
            type_name = '{}'.format(type_name)

        return type_name

    def make_consumer_func_decl(
        self, return_type, name, values, dx12_method=False
    ):
        """make_consumer_decl - return VulkanConsumer class member function declaration.
        Generate VulkanConsumer class member function declaration.
        """
        param_decls = []
        param_decl = self.make_aligned_param_decl(
            'const ApiCallInfo&', 'call_info', self.INDENT_SIZE,
            self.genOpts.align_func_param
        )
        param_decls.append(param_decl)

        if dx12_method:
            param_decl = self.make_aligned_param_decl(
                'format::HandleId', 'object_id', self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            param_decls.append(param_decl)

        if return_type != 'void':
            param_decl = self.make_aligned_param_decl(
                return_type, 'returnValue', self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            param_decls.append(param_decl)

        for value in values:
            param_type = self.make_decoded_param_type(value)

            if 'Decoder' in param_type:
                param_type = '{}*'.format(param_type)

            param_decl = self.make_aligned_param_decl(
                param_type, value.name, self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            param_decls.append(param_decl)

        if param_decls:
            return 'void {}(\n{})'.format(name, ',\n'.join(param_decls))

        return 'void {}()'.format(name)

    def make_dump_resources_func_decl(
        self, return_type, name, values, is_override
    ):
        """make_consumer_decl - return VulkanConsumer class member function declaration.
        Generate VulkanConsumer class member function declaration.
        """
        param_decls = []
        param_decl = self.make_aligned_param_decl(
            'const ApiCallInfo&', 'call_info', self.INDENT_SIZE,
            self.genOpts.align_func_param
        )
        param_decls.append(param_decl)

        param_decl = self.make_aligned_param_decl(
            'PFN_' + name.rsplit('_', 1)[1], 'func', self.INDENT_SIZE,
            self.genOpts.align_func_param
        )
        param_decls.append(param_decl)

        if return_type != 'void':
            param_decl = self.make_aligned_param_decl(
                return_type, 'returnValue', self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            param_decls.append(param_decl)

        for value in values:
            type_name = value.base_type

            if is_override:
                prefix_from_type = self.get_prefix_from_type(value.base_type)
                info_type = prefix_from_type + value.base_type[2:] + 'Info'
                if value.is_pointer or value.is_array:
                    count = value.pointer_count

                    if self.is_struct(type_name):
                        param_type = 'StructPointerDecoder<Decoded_{}>*'.format(
                            type_name
                        )
                    elif self.is_handle(type_name) and type_name != 'VkCommandBuffer':
                        param_type = 'HandlePointerDecoder<{}>*'.format(type_name)
                    else:
                        param_type = 'const ' + type_name + '*'
                else:
                    if self.is_handle(type_name) and type_name != 'VkCommandBuffer':
                        param_type = 'const ' + info_type + '*'
                    else:
                        param_type = type_name
            else:
                if value.is_pointer or value.is_array:
                    count = value.pointer_count
                    param_type = 'const ' + type_name + '*'
                    if count > 1:
                        param_type += ' const *' * (count - 1)
                else:
                    param_type = type_name

            param_decl = self.make_aligned_param_decl(
                param_type, value.name, self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            param_decls.append(param_decl)

        if param_decls:
            return 'void {}(\n{})'.format(name, ',\n'.join(param_decls))

        return 'void {}()'.format(name)

    def make_structure_type_enum(self, typeinfo, typename):
        """Generate the VkStructureType enumeration value for the specified structure type."""
        members = typeinfo.elem.findall('.//member')

        for member in members:
            membername = noneStr(member.find('name').text)

            # We only care about structures with an sType, which can be included in a pNext chain.
            if membername == 'sType':
                # Check for value in the XML element.
                values = member.attrib.get('values')

                if values:
                    return values
                else:
                    # If the value was not specified by the XML element, process the struct type to create it.
                    stype = re.sub('([a-z0-9])([A-Z])', r'\1_\2', typename)
                    stype = stype.replace('D3_D12', 'D3D12')
                    stype = stype.replace('Device_IDProp', 'Device_ID_Prop')
                    stype = stype.upper()
                    return re.sub('VK_', 'VK_STRUCTURE_TYPE_', stype)
        return None

    def make_array_length_expression(self, value, prefix=''):
        """Generate an expression for the length of a given array value."""
        length_expr = value.array_length
        length_value = value.array_length_value

        if length_value:
            if length_value.is_pointer:
                # Add implicit dereference when length expr == pointer name
                if length_value.name == length_expr:
                    length_expr = '*' + length_expr
                # Add null check to length value behind pointer
                length_expr = '({length_value.name} != nullptr) ? ({length_expr}) : 0'.format(
                    length_value=length_value, length_expr=length_expr
                )
            elif length_value.base_type == 'VkDeviceSize':
                # Static cast 64-bit length expression to eliminate warning in 32-bit builds
                length_expr = 'static_cast<size_t>({})'.format(length_expr)
            # Add prefix to parameter in the length expression
            length_expr = length_expr.replace(
                length_value.name, prefix + length_value.name
            )
        return length_expr

    def make_array2d_length_expression(self, value, values, prefix=''):
        length_exprs = value.array_length.split(',')
        if len(length_exprs) == value.pointer_count:
            # All dimensions are provided in the xml
            lengths = []
            for length_expr in length_exprs:
                # Prefix members
                for v in values:
                    length_expr = re.sub(
                        r'\b({})\b'.format(v.name), r'{}\1'.format(prefix),
                        length_expr
                    )
                lengths.append(length_expr)
            return lengths
        else:
            # XML does not provide lengths for all dimensions, instantiate a specialization of ArraySize2D to fetch the sizes
            type_list = ', '.join([self.clean_type_define(v.full_type) for v in values])
            arg_list = ', '.join([v.name for v in values])
            return ['ArraySize2D<{}>({})'.format(type_list, arg_list)]

    def get_api_prefix(self):
        """Method override. Start processing in superclass."""
        return 'Vulkan'

    def get_prefix_from_type(self, type):
        """Method override. Start processing in superclass."""
        return self.get_api_prefix()

    def get_wrapper_prefix_from_type(self):
        """Method override. Start processing in superclass."""
        return 'vulkan_wrappers'

    def make_encoder_method_call(
        self, name, value, values, prefix, omit_output_param=None
    ):
        """Generate a parameter encoder method call invocation."""
        arg_name = prefix + value.name
        if self.is_generic_struct_handle_value(
            name, value.name
        ) or self.is_generic_cmd_handle_value(name, value.name):
            handle_type_name = prefix
            if self.is_generic_struct_handle_value(name, value.name):
                handle_type_name += self.get_generic_struct_handle_type_value(
                    name, value.name
                )
            else:
                handle_type_name += self.get_generic_cmd_handle_type_value(
                    name, value.name
                )
            wrapper = self.get_wrapper_prefix_from_type()
            arg_name = '{}::GetWrappedId({}, {})'.format(
                wrapper, arg_name, handle_type_name
            )

        args = [arg_name]

        is_struct = False
        is_string = False
        is_funcp = False

        type_name = self.make_invocation_type_name(value.base_type)
        is_handle = self.is_handle(value.base_type)

        if self.is_struct(type_name):
            args = ['encoder'] + args
            is_struct = True
            method_call = 'EncodeStruct'
        else:
            method_call = 'encoder->Encode'
            if type_name in ['String', 'WString']:
                is_string = True
            elif type_name == 'FunctionPtr':
                is_funcp = True
            elif self.has_basetype(type_name):
                type_base_type = self.get_basetype(type_name)
                if type_base_type in self.encode_types:
                    type_name = self.encode_types[type_base_type]

            method_call += type_name

        if is_string:
            if value.is_array and value.is_dynamic:
                method_call += 'Array'
                args.append(self.make_array_length_expression(value, prefix))
        elif value.is_array:
            if value.pointer_count > 1:
                method_call += 'Array{}D'.format(value.pointer_count)
                args.extend(
                    self.make_array2d_length_expression(value, values, prefix)
                )
            elif ',' in value.array_length:
                method_call += '{}DMatrix'.format(
                    value.array_length.count(',') + 1
                )
                args.append(self.make_array_length_expression(value, prefix))
            else:
                method_call += 'Array'
                args.append(self.make_array_length_expression(value, prefix))
        elif is_struct:
            if value.is_pointer:
                method_call += 'Ptr'
        elif not (is_string or is_funcp):
            # Ignore string and function names, which do not use the Ptr/Value suffix
            if value.is_pointer:
                method_call += 'Ptr' * value.pointer_count
            else:
                method_call += 'Value'

        if is_handle:
            wrapper_prefix = self.get_wrapper_prefix_from_type()
            method_call += '<{}>'.format(wrapper_prefix + '::' + value.base_type[2:] + 'Wrapper')

        if self.is_output_parameter(value) and omit_output_param:
            args.append(omit_output_param)

        return '{}({})'.format(method_call, ', '.join(args))

    def is_dump_resources_api_call(self, call_name):
        """Method override."""
        if (call_name[:5] == 'vkCmd' or call_name == 'vkEndCommandBuffer'):
            return True
        else:
            return False

    def get_feature_protect(self, interface):
        """Return appropriate feature protect string from 'platform' tag on feature.
        From Vulkan-ValidationLayers common_codegen.py.
        """
        # TODO: This should probably be in a JSON file.
        platform_dict = {
            'android': 'VK_USE_PLATFORM_ANDROID_KHR',
            'fuchsia': 'VK_USE_PLATFORM_FUCHSIA',
            'ios': 'VK_USE_PLATFORM_IOS_MVK',
            'macos': 'VK_USE_PLATFORM_MACOS_MVK',
            'mir': 'VK_USE_PLATFORM_MIR_KHR',
            'vi': 'VK_USE_PLATFORM_VI_NN',
            'wayland': 'VK_USE_PLATFORM_WAYLAND_KHR',
            'win32': 'VK_USE_PLATFORM_WIN32_KHR',
            'xcb': 'VK_USE_PLATFORM_XCB_KHR',
            'xlib': 'VK_USE_PLATFORM_XLIB_KHR',
            'xlib_xrandr': 'VK_USE_PLATFORM_XLIB_XRANDR_EXT',
            'ggp': 'VK_USE_PLATFORM_GGP',
            'directfb': 'VK_USE_PLATFORM_DIRECTFB_EXT',
            'headless': 'VK_USE_PLATFORM_HEADLESS'
        }

        platform = interface.get('platform')
        if platform and platform in platform_dict:
            return platform_dict[platform]
        return None

    def get_base_input_structure_name(self):
        """Method override"""
        return 'VkBaseInStructure'

    def get_base_output_structure_name(self):
        """Method override"""
        return 'VkBaseOutStructure'

    def get_struct_type_var_name(self):
        """Method override"""
        return 'sType'

    def get_struct_type_func_prefix(self):
        """Method override"""
        return 'SType'

    def get_extended_struct_var_name(self):
        """Method override"""
        return 'pNext'

    def get_extended_struct_func_prefix(self):
        """Method override"""
        return 'PNext'
