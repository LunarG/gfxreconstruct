#!/usr/bin/python3 -i
#
# Copyright (c) 2018-2021 Valve Corporation
# Copyright (c) 2018-2023 LunarG, Inc.
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

import os, re, sys, json
from base_generator_defines import BaseGeneratorDefines, ValueInfo, bits_enum_to_flags_typedef, make_re_string, write
from khronos_base_generator import KhronosBaseGeneratorOptions, KhronosBaseGenerator
from generator import noneStr, regSortFeatures
from collections import OrderedDict
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
    "VK_HUAWEI_subpass_shading",  # Limited tile shader
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
    """BaseGeneratorOptions - subclass of GeneratorOptions.
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
        emitversions=_features_pat,
        default_extensions=_default_extensions,
        add_extensions=_add_extensions_pat,
        remove_extensions=_remove_extensions_pat,
        emit_extensions=_emit_extensions_pat,
        extraHeaders=[]
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
            indent_func_proto=indent_func_proto,
            align_func_param=align_func_param,
            sort_procedure=sort_procedure,
            apiname=apiname,
            profile=profile,
            versions=versions,
            emitversions=emitversions,
            default_extensions=default_extensions,
            add_extensions=add_extensions,
            remove_extensions=remove_extensions,
            emit_extensions=emit_extensions,
            extraHeaders=extraHeaders
        )


class BaseGenerator(KhronosBaseGenerator):
    """BaseGenerator - subclass of OutputGenerator.
    Base class providing common operations used to generate C++-language code for framework
      components that encode and decode Vulkan API parameters.
    Base class for Vulkan API parameter encoding and decoding generators.
    """

    def __init__(
        self,
        process_cmds,
        process_structs,
        feature_break=True,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout
    ):
        super().__init__(
            process_cmds, process_structs, feature_break, err_file, warn_file,
            diag_file
        )

        # These structures should be ignored for handle mapping/unwrapping. They require special implementations.
        self.STRUCT_MAPPERS_BLACKLIST = [
            'VkAccelerationStructureBuildGeometryInfoKHR'
        ]

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

        self.DUPLICATE_HANDLE_TYPES = [
            'VkDescriptorUpdateTemplateKHR', 'VkSamplerYcbcrConversionKHR',
            'VkPrivateDataSlotEXT'
        ]

        self.VIDEO_TREE = None

        self.generate_video = False

    def includeExtraHeaders(self, gen_opts):
        """Write Vulkan header include statements
        """
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        write(
            '#include "vk_video/vulkan_video_codec_h264std.h"',
            file=self.outFile
        )
        write(
            '#include "vk_video/vulkan_video_codec_h264std_decode.h"',
            file=self.outFile
        )
        write(
            '#include "vk_video/vulkan_video_codec_h264std_encode.h"',
            file=self.outFile
        )
        write(
            '#include "vk_video/vulkan_video_codec_h265std.h"',
            file=self.outFile
        )
        write(
            '#include "vk_video/vulkan_video_codec_h265std_decode.h"',
            file=self.outFile
        )
        write(
            '#include "vk_video/vulkan_video_codec_h265std_encode.h"',
            file=self.outFile
        )
        write(
            '#include "vk_video/vulkan_video_codecs_common.h"',
            file=self.outFile
        )
        super().includeExtraHeaders(gen_opts)

    def beginFeature(self, interface, emit):
        """Method override. Start processing in superclass."""
        super().beginFeature(interface, emit)

        if not self.generate_video:
            self.genVideoType()
            self.generate_video = True

    def genVideoType(self):
        if not self.VIDEO_TREE:
            return

        if self.process_structs:
            types = self.VIDEO_TREE.find('types')
            for element in types.iter('type'):
                name = element.get('name')
                category = element.get('category')
                if name and category and (
                    category == 'struct' or category == 'union'
                ):
                    self.all_structs.append(name)
                    if category == 'struct':
                        self.set_struct_members(
                            name,
                            self.makeValueInfo(element.findall('member'))
                        )
                    else:
                        self.set_union_members(
                            name,
                            self.makeValueInfo(element.findall('member'))
                        )
                elif (category == 'bitmask'):
                    self.flags_types[name] = element.find('type').text

                    bittype = element.elem.get('requires')
                    if bittype is None:
                        bittype = element.elem.get('bitvalues')
                    if bittype is not None:
                        self.flag_enum_bits_type[name] = bittype
                        if bittype not in self.bitfields_names:
                            self.bitfields_names.append(bittype)
                        if bittype not in self.flag_bits_types:
                            self.flag_bits_types[bittype] = element.find(
                                'type'
                            ).text

        for element in self.VIDEO_TREE.iter('enums'):
            group_name = element.get('name')
            self.enum_names.add(group_name)
            enumerants = dict()
            for elem in element.findall('enum'):
                name = elem.get('name')
                enumerants[name] = elem.get('value')
            self.enum_enumerants[group_name] = enumerants

    def createCmdProtoDecl(self, proto_decl, text, tail):
        new_text = text
        if text.startswith('vk'):
            new_text = new_text[2:]
        return self.makeProtoName(new_text, tail)

    def checkExtendedStructForHandles(self, typename):
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
                                if found and self.is_valid_handle(
                                    member_info.text
                                ):
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

    def getBaseInStructureName(self):
        return 'VkBaseInStructure'

    def getBaseOutStructureName(self):
        return 'VkBaseOutStructure'

    def getStructTypeMemberName(self):
        return 'sType'

    def getExtendedTypeMemberName(self):
        return 'pNext'

    def getExtendedNodeType(self):
        return 'PNextNode'

    def updateStructureTypePrefix(self, type):
        return re.sub('VK_', 'VK_STRUCTURE_TYPE_', type)

    def make_array_length_expression(self, value, prefix=''):
        """Generate an expression for the length of a given array value."""
        length_expr = value.array_length
        length_value = value.array_length_value

        if length_value and not length_value.is_pointer and length_value.base_type == 'VkDeviceSize':
            # Static cast 64-bit length expression to eliminate warning in 32-bit builds
            length_expr = 'static_cast<size_t>({})'.format(length_expr)
            # Add prefix to parameter in the length expression
            length_expr = length_expr.replace(
                length_value.name, prefix + length_value.name
            )
        else:
            length_expr = super().make_array_length_expression(value, prefix)
        return length_expr

    def get_api_prefix(self):
        return 'Vulkan'

    def get_prefix_from_type(self, type):
        return self.get_api_prefix()

    def get_wrapper_prefix_from_type(self):
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
            method_call += '<{}>'.format(
                wrapper_prefix + '::' + value.base_type[2:] + 'Wrapper'
            )

        if self.is_output_parameter(value) and omit_output_param:
            args.append(omit_output_param)

        return '{}({})'.format(method_call, ', '.join(args))

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
