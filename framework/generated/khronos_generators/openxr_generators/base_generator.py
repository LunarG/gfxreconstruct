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

import os
import re
import sys
import json
from base_generator_defines import BaseGeneratorDefines, ValueInfo, bits_enum_to_flags_typedef, make_re_string, write
from khronos_base_generator import KhronosBaseGeneratorOptions, KhronosBaseGenerator
from collections import OrderedDict
from generator import GeneratorOptions, OutputGenerator, noneStr, regSortFeatures
from xrconventions import OpenXRConventions

# Descriptive names for various regexp patterns used to select versions and extensions.
_default_extensions = 'openxr'
_extensions = _features = []
_emit_extensions = []

# Exclude extensions from code generation.
# Note this doesn't totally eliminate them. ToString and ToJson functions for enums
# will always be generated but functions and structs can be screened out by editing
# the blocklists files such as the openxr default "openxr_generators/blacklists.json".
# Note, this doesn't hide them from the  application, but lets them bypass our
# layer during capture, meaning we will not call any of their functions at
# replay.
# To screen an extension out from the list reported to the application it should
# be added to the list kUnsupportedDeviceExtensions in trace_layer.cpp.
_remove_extensions = []

# Turn lists of names/patterns into matching regular expressions.
# From Khronos genvk.py
_add_extensions_pat = make_re_string(_extensions)
_remove_extensions_pat = make_re_string(_remove_extensions)
_emit_extensions_pat = make_re_string(_emit_extensions, '.*')
_features_pat = make_re_string(_features, '.*')


class BaseGeneratorOptions(KhronosBaseGeneratorOptions):
    """BaseGeneratorOptions - subclass of GeneratorOptions.
    Options for OpenXR API parameter encoding and decoding C++ code generation.

    Adds options used by FrameworkGenerator objects during C++ language
    code generation.

    Additional members
      blacklists - Path to JSON file listing apicalls and structs to ignore.
      platform_types - Path to JSON file listing platform (WIN32, X11, etc.)
        specific types that are defined outside of the OpenXR header.

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
        conventions=OpenXRConventions(),
        apicall='XRAPI_ATTR ',
        apientry='XRAPI_CALL ',
        apientryp='XRAPI_PTR *',
        indent_func_proto=True,
        align_func_param=48,
        sort_procedure=regSortFeatures,
        apiname='openxr',
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
      components that encode and decode OpenXR API parameters.
    Base class for OpenXR API parameter encoding and decoding generators.
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

        # Platform specific structure types that have been defined extarnally to the OpenXR header.
        self.PLATFORM_STRUCTS = ['timespec']

        # Basetypes and their corresponding encode command type
        self.encode_types['XR_DEFINE_ATOM'] = 'UInt64'
        self.encode_types['XR_DEFINE_OPAQUE_64'] = 'UInt64'

        # Add Vulkan handle types to handle list since they aren't
        # easily detected from just the OpenXR registry file
        self.handle_names.add('VkInstance')
        self.handle_names.add('VkPhysicalDevice')
        self.handle_names.add('VkDevice')
        self.handle_names.add('VkImage')
        self.handle_names.add('VkCommandBuffer')
        self.handle_names.add('VkQueue')
        self.handle_names.add('VkSurfaceKHR')
        self.handle_names.add('VkSwapchainKHR')

        # Add Vulkan enums
        self.enum_names.add('VkResult')
        self.enum_names.add('VkFormat')
        self.enum_names.add('VkFilter')
        self.enum_names.add('VkSamplerMipmapMode')
        self.enum_names.add('VkSamplerAddressMode')
        self.enum_names.add('VkComponentSwizzle')

    def beginFile(self, gen_opts):
        """Method override."""
        super().beginFile(gen_opts)

        write('#ifdef ENABLE_OPENXR_SUPPORT', file=self.outFile)
        self.newline()

    def includeExtraHeaders(self, gen_opts):
        """Write OpenXR header include statements
        """
        write('#include "format/platform_types.h"', file=self.outFile)
        self.newline()
        write('#include "openxr/openxr.h"', file=self.outFile)
        write(
            '#include "openxr/openxr_loader_negotiation.h"', file=self.outFile
        )
        write('#include "openxr/openxr_platform.h"', file=self.outFile)

        super().includeExtraHeaders(gen_opts)

    def endFile(self):
        """Method override."""
        self.newline()
        write('#endif // ENABLE_OPENXR_SUPPORT', file=self.outFile)

        super().endFile()

    def checkRemainingBaseTypes(self, name, type_info):
        if type_info == 'XR_DEFINE_ATOM':
            self.atom_names.add(name)
        elif type_info == 'XR_DEFINE_OPAQUE_64':
            self.opaque_names.add(name)
        elif not name == 'XrTime':
            self.base_types[name] = type_info

    def generateStructureType(self, typeinfo, typename):
        struct_type_enum = self.makeStructureTypeEnum(typeinfo, typename)
        if struct_type_enum is not None and struct_type_enum in self.enum_enumerants[
            'XrStructureType']:
            self.struct_type_enums[typename] = struct_type_enum

    def is_atom(self, base_type):
        if base_type in self.atom_names:
            return True
        return False

    def is_opaque(self, base_type):
        if base_type in self.opaque_names:
            return True
        return False

    def get_default_handle_atom_value(self, base_type):
        if self.is_atom(base_type):
            # If the value was not specified by the XML element, process the struct type to create it.
            type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', base_type)
            type = type.upper()
            default_type = re.sub('XR_', 'XR_NULL_', type)

            # Special case remove any of the NULL atom types not defined
            no_null_defined = [
                'XR_NULL_ASYNC_REQUEST_ID_FB', 'XR_NULL_MARKER_ML'
            ]
            if default_type in no_null_defined:
                default_type = '0'
            return default_type
        else:
            return super().get_default_handle_atom_value(base_type)

    def getBaseInStructureName(self):
        return 'XrBaseInStructure'

    def getBaseOutStructureName(self):
        return 'XrBaseOutStructure'

    def getStructTypeMemberName(self):
        return 'type'

    def getExtendedTypeMemberName(self):
        return 'next'

    def getExtendedNodeType(self):
        return 'OpenXrNextNode'

    def updateStructureTypePrefix(self, type):
        temp = re.sub('VK_', 'VK_STRUCTURE_TYPE_', type)
        temp = re.sub('XR_', 'XR_TYPE_', temp)
        return temp

    def get_api_prefix(self):
        platform_type = 'Vulkan'
        if self.is_dx12_class():
            platform_type = 'Dx12'
        elif self.is_openxr_class():
            platform_type = 'OpenXr'
        return platform_type

    def get_prefix_from_type(self, handle_name):
        if handle_name.startswith('Vk'):
            return 'Vulkan'
        elif handle_name.startswith('Xr'):
            return 'OpenXr'
        else:
            return 'UNKNOWN'

    def get_handle_wrapper(self, base_type):
        handle_wrapper = ''
        if base_type.startswith('Vk'):
            handle_wrapper = 'vulkan_wrappers::'
        else:
            handle_wrapper = 'openxr_wrappers::'
        handle_wrapper += base_type[2:] + 'Wrapper'
        return handle_wrapper

    def get_wrapper_prefix_from_type(self, handle_name):
        if handle_name.startswith('Vk'):
            return 'vulkan_wrappers'
        elif handle_name.startswith('Xr'):
            return 'openxr_wrappers'
        else:
            return 'UNKNOWN_WRAPPERS'

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
            wrapper = self.get_wrapper_prefix_from_type(value.name)
            arg_name = '{}::GetWrappedId({}, {})'.format(
                wrapper, arg_name, handle_type_name
            )

        args = [arg_name]

        is_struct = False
        is_string = False
        is_funcp = False

        type_name = self.make_invocation_type_name(value.base_type)
        is_handle = self.is_handle(value.base_type)
        is_atom = self.is_atom(value.base_type)
        is_opaque = self.is_opaque(value.base_type)

        if self.is_struct(type_name):
            args = ['encoder'] + args
            is_struct = True
            method_call = 'Encode'
            method_call += 'Struct'
        else:
            method_call = 'encoder->Encode'
            if type_name in ['String', 'WString']:
                is_string = True
            elif type_name == 'FunctionPtr':
                is_funcp = True

            if type_name.startswith("Vk") and "Flags" in type_name:
                method_call += 'Flags'
            elif is_atom:
                method_call += 'OpenXrAtom'
            elif is_opaque:
                method_call += 'OpenXrOpaque'
            elif self.has_basetype(type_name):
                method_call += self.encode_types[self.get_basetype(type_name)]
            else:
                method_call += type_name

        if is_string:
            if value.is_array and value.is_dynamic and value.pointer_count > 1:
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

        if is_handle or is_atom or is_opaque:
            wrapper_prefix = self.get_wrapper_prefix_from_type(value.base_type)
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
            'android': 'XR_USE_PLATFORM_ANDROID',
            'wayland': 'XR_USE_PLATFORM_WAYLAND',
            'win32': 'XR_USE_PLATFORM_WIN32',
            'xcb': 'XR_USE_PLATFORM_XCB',
            'xlib': 'XR_USE_PLATFORM_XLIB',
        }

        platform = interface.get('platform')
        if platform and platform in platform_dict:
            return platform_dict[platform]
        return None

    def make_child_struct_switch(
        self, base_struct, value, initial_indent, switch_expression,
        fn_emit_default, fn_emit_case
    ):
        """ Base structs are abstract, need to case to specific child struct based on type """
        indent = '    '
        indent1 = initial_indent
        indent2 = indent1 + indent
        indent3 = indent2 + indent
        body = ''
        body += f'{indent1}// Cast and call the appropriate encoder based on the structure type\n'
        body += f'{indent1}switch({switch_expression})\n'

        body += f'{indent1}{{\n'
        body += f'{indent2}default:\n'
        body += f'{indent2}{{\n'
        body += '\n'.join(
            [indent3 + line for line in fn_emit_default(base_struct, value)]
        )
        body += f'\n{indent2}}}\n'

        for child_struct in self.base_header_structs[base_struct]:
            struct_type_name = self.struct_type_enums[child_struct]
            body += f'{indent2}case {struct_type_name}:\n'
            body += f'{indent2}{{\n'
            body += '\n'.join(
                [
                    indent3 + line for line in fn_emit_case(
                        base_struct, child_struct, struct_type_name, value
                    )
                ]
            )
            body += f'\n{indent2}}}\n'

        body += f'{indent1}}}\n'
        return body

    def checkExtendedStructForHandles(self, typename):
        """Determines if the specified struct type can reference next extension structs that contain handles."""
        has_handles = False
        has_handle_ptrs = False
        valid_extension_structs = self.registry.validextensionstructs.get(
            typename
        )
        if valid_extension_structs:
            # Need to search the XML tree for next structures that have not been processed yet.
            for struct_name in valid_extension_structs:
                found_handles, found_handle_ptrs, handle_list = self.structHasHandles(
                    struct_name
                )
                has_handles = has_handles or found_handles
                has_handle_ptrs = has_handle_ptrs or found_handle_ptrs
                if has_handles and has_handle_ptrs:
                    break

        if typename in self.extended_structs:
            # If struct has a extends another, then its "next" has the same has_* as the parent
            has_handles, has_handle_ptrs = self.checkExtendedStructForHandles(
                self.extended_structs[typename]
            )

        return has_handles, has_handle_ptrs

    def checkStructMemberStructForHandles(self, value, structs_with_handles):
        """Determines if a struct member which is also a structure contains handles"""
        has_handles, has_handle_ptrs, handle_list = self.structHasHandles(
            value.base_type
        )
        return has_handles, has_handle_ptrs, handle_list

    def isApiBaseType(self, typename):
        LOADER_NEGOTIATION_STRUCTS = [
            'XrApiLayerNextInfo', 'XrApiLayerCreateInfo',
            'XrNegotiateLoaderInfo', 'XrNegotiateRuntimeRequest',
            'XrNegotiateApiLayerRequest'
        ]
        if (
            (self.getBaseInStructureName() == typename)
            or (self.getBaseOutStructureName() == typename)
            or (typename in LOADER_NEGOTIATION_STRUCTS)
        ):
            return True
        return False
