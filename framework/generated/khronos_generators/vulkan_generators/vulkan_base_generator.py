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
from khronos_base_generator import (KhronosBaseGeneratorOptions, KhronosBaseGenerator, make_re_string, ValueInfo, write)
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
    "VK_ARM_tensors",
    "VK_ARM_data_graph",
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
    "VK_NV_cluster_acceleration_structure",
    "VK_NV_external_compute_queue",
    "VK_OHOS_surface",
    "VK_OHOS_external_memory",
    "VK_OHOS_native_buffer",
    "VK_AMDX_dense_geometry_format",
    "VK_KHR_video_decode_h265",
    "VK_KHR_video_encode_h265",
    "VK_KHR_video_maintenance2",
]

# Exclude *video* extensions from code generation.  This excludes all
# generation of struct and enums under these video extensions
# TODO: This should probably behave like _remove_extensions
_remove_video_extensions = [
    "vulkan_video_codec_h265std",
    "vulkan_video_codec_h265std_decode",
    "vulkan_video_codec_h265std_encode",
]

# Turn lists of names/patterns into matching regular expressions.
# From Khronos genvk.py
_add_extensions_pat = make_re_string(_extensions)
_remove_extensions_pat = make_re_string(_remove_extensions)
_emit_extensions_pat = make_re_string(_emit_extensions, '.*')
_features_pat = make_re_string(_features, '.*')


class VulkanBaseGeneratorOptions(KhronosBaseGeneratorOptions):
    """VulkanBaseGeneratorOptions - subclass of KhronosGeneratorOptions.
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
      replay_overrides - Path to JSON file listing Vulkan API calls to
        override on replay.
      dump_resources_overrides - Path to JSON file listing Vulkan API
        calls to override on replay.
      replay_async_overrides - Path to JSON file listing Vulkan API calls
        to override on replay.
      extra_headers - headers to include in addition to the standard Khronos API
    """

    def __init__(
        self,
        blacklists=None,
        platform_types=None,
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
        replay_overrides=None,
        dump_resources_overrides=None,
        replay_async_overrides=None,
        extra_headers=[]
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
            replay_overrides=replay_overrides,
            dump_resources_overrides=dump_resources_overrides,
            replay_async_overrides=replay_async_overrides,
            extra_headers=extra_headers
        )

        self.begin_end_file_data.common_api_headers = [
            'vulkan/vulkan.h',
            'vk_video/vulkan_video_codec_h264std.h',
            'vk_video/vulkan_video_codec_h264std_decode.h',
            'vk_video/vulkan_video_codec_h264std_encode.h',
            'vk_video/vulkan_video_codec_h265std.h',
            'vk_video/vulkan_video_codec_h265std_decode.h',
            'vk_video/vulkan_video_codec_h265std_encode.h',
            'vk_video/vulkan_video_codecs_common.h',
        ]


class VulkanBaseGenerator(KhronosBaseGenerator):
    """VulkanBaseGenerator - subclass of KhronosBaseGenerator.
    Base class providing common operations used to generate C++-language code for framework
      components that encode and decode Vulkan API parameters.
    Base class for Vulkan API parameter encoding and decoding generators.
    """

    def __init__(
        self,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout
    ):
        KhronosBaseGenerator.__init__(
            self,
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

        self.VIDEO_TREE = None

        self.generate_video = False

    def beginFeature(self, interface, emit):
        """Method override. Start processing in superclass."""
        KhronosBaseGenerator.beginFeature(self, interface, emit)

        if not self.generate_video:
            self.gen_video_type()
            self.generate_video = True

    def endFeature(self):
        """Method override. Generate code for the feature."""
        KhronosBaseGenerator.endFeature(self)

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        return True

    def gen_video_type(self):
        if not self.VIDEO_TREE:
            return

        # Which video types should be omitted
        omit_video_types = set()

        # for all extensions in _remove_video_extensions, collect types
        # that should not be omitted.
        extensions = self.VIDEO_TREE.find('extensions')
        for element in extensions.iter('extension'):
            name = element.get('name')
            if name in _remove_video_extensions:
                for type_element in element.iter('type'):
                    omit_video_types.add(type_element.get('name'))

        types = self.VIDEO_TREE.find('types')
        for element in types.iter('type'):
            name = element.get('name')

            # if this type (struct) was in a removed video extension,
            # don't process it
            if name in omit_video_types:
                continue

            category = element.get('category')
            if name and category and (category == 'struct' or category == 'union'):
                self.struct_names.add(name)
                if category == 'struct':
                    self.process_struct(element, name, None)

        for element in self.VIDEO_TREE.iter('enums'):
            group_name = element.get('name')

            # if this enum group was in a removed video extension,
            # don't process it
            if group_name in omit_video_types:
                continue

            self.enum_names.add(group_name)
            enumerants = dict()
            for elem in element.findall('enum'):
                name = elem.get('name')
                value = elem.get('value')
                if value:
                    enumerants[name] = value
            self.enumEnumerants[group_name] = enumerants

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
                prefix_from_type = self.get_api_prefix_from_type(value.base_type)
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
