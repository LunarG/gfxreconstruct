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
from generator import GeneratorOptions, OutputGenerator, noneStr, regSortFeatures, write
from xrconventions import OpenXRConventions


def _make_re_string(list, default=None):
    """Turn a list of strings into a regexp string matching exactly those strings.
    From Khronos genvk.py
    """
    if (len(list) > 0) or (default is None):
        return '^(' + '|'.join(list) + ')$'
    else:
        return default


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

_supported_subsets = ["openxr"]

# Turn lists of names/patterns into matching regular expressions.
# From Khronos genvk.py
_add_extensions_pat = _make_re_string(_extensions)
_remove_extensions_pat = _make_re_string(_remove_extensions)
_emit_extensions_pat = _make_re_string(_emit_extensions, '.*')
_features_pat = _make_re_string(_features, '.*')


def removesuffix(self: str, suffix: str, /) -> str:
    # suffix='' should not call self[:-0].
    if suffix and self.endswith(suffix):
        return self[:-len(suffix)]
    else:
        return self[:]


# Strip the "Bit" ending or near-ending from an enum representing a group of
# flag bits to give the name of the type (typedef of Flags or Flags64) used to
# hold a disjoint set of them.
# It works for true enums and the 64 bit collections of static const variables
# which are tied together only with a naming convention in the C header.
def BitsEnumToFlagsTypedef(enum):
    # if enum.endswith
    flags = removesuffix(enum, 'Bits')
    if flags != enum:
        flags = flags + 's'
        return flags
    flags = removesuffix(enum, 'Bits2')
    if flags != enum:
        flags = flags + 's2'
        return flags
    # Gods preserve us from Bits 3, 4, 5, etc.
    # It might have more extension suffix.
    flags = removesuffix(enum, 'Bits2KHR')
    if flags != enum:
        flags = flags + 's2KHR'
        return flags
    return flags


class ValueInfo():
    """ValueInfo - Class to store parameter/struct member information.
    Contains information descripting OpenXR API call parameters and struct members.

    Members:
      name - Parameter/struct member name of the value.
      base_type - Undecorated typename of the value.
      full_type - Fully qualified typename of the value.
      pointer_count - Number of '*' characters in the type declaration.
      array_length - The parameter that specifies the number of elements in an array, or None if the value is not an array.
      array_capacity - The max size of a statically allocated array, or None for a dynamically allocated array.
      array_dimension - Number of the array dimension
      platform_base_type - For platform specific type definitions, stores the original base_type declaration before platform to trace type substitution.
      platform_full_type - For platform specific type definitions, stores the original full_type declaration before platform to trace type substitution.
      is_pointer - True if the value is a pointer.
      is_array - True if the member is an array.
      is_dynamic - True if the memory for the member is an array and it is dynamically allocated.
      is_const - True if the member is a const.
    """

    def __init__(
        self,
        name,
        base_type,
        full_type,
        pointer_count=0,
        array_length=None,
        array_length_value=None,
        array_capacity=None,
        array_dimension=None,
        platform_base_type=None,
        platform_full_type=None,
        bitfield_width=None,
        is_const=False,
        is_com_outptr=False
    ):
        self.name = name
        self.base_type = base_type
        self.full_type = full_type
        self.pointer_count = pointer_count
        self.array_length = array_length
        self.array_length_value = array_length_value
        self.array_capacity = array_capacity
        self.array_dimension = array_dimension
        self.platform_base_type = platform_base_type
        self.platform_full_type = platform_full_type
        self.bitfield_width = bitfield_width

        self.is_pointer = True if pointer_count > 0 else False
        self.is_array = True if array_length else False
        self.is_dynamic = True if not array_capacity else False
        self.is_const = is_const
        self.is_com_outptr = is_com_outptr


class BaseGeneratorOptions(GeneratorOptions):
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
        extraOpenXrHeaders=[]
    ):
        GeneratorOptions.__init__(
            self,
            conventions=conventions,
            filename=filename,
            directory=directory,
            apiname=apiname,
            profile=profile,
            versions=versions,
            emitversions=emitversions,
            defaultExtensions=default_extensions,
            addExtensions=add_extensions,
            removeExtensions=remove_extensions,
            emitExtensions=emit_extensions,
            sortProcedure=sort_procedure
        )
        self.blacklists = blacklists
        self.platform_types = platform_types
        # Khronos CGeneratorOptions
        self.prefix_text = prefix_text
        self.protect_file = protect_file
        self.protect_feature = protect_feature
        self.apicall = apicall
        self.apientry = apientry  # NOTE: While not used in this file, apientry is expected to be defined here by the OutputGenerator base class.
        self.apientryp = apientryp  # NOTE: While not used in this file, apientry is expected to be defined here by the OutputGenerator base class.
        self.indent_func_proto = indent_func_proto
        self.align_func_param = align_func_param
        self.code_generator = True
        self.extraOpenXrHeaders = extraOpenXrHeaders


class BaseGenerator(OutputGenerator):
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
        OutputGenerator.__init__(self, err_file, warn_file, diag_file)

        # These API calls should not be processed by the code generator.  They require special implementations.
        self.APICALL_BLACKLIST = []

        self.APICALL_ENCODER_BLACKLIST = []

        self.APICALL_DECODER_BLACKLIST = []

        # These method calls should not be processed by the code generator.  They require special implementations.
        self.METHODCALL_BLACKLIST = []

        # These structures should not be processed by the code generator.  They require special implementations.
        self.STRUCT_BLACKLIST = []

        # Platform specific basic types that have been defined extarnally to the OpenXR header.
        self.PLATFORM_TYPES = {}

        # Platform specific structure types that have been defined extarnally to the OpenXR header.
        self.PLATFORM_STRUCTS = ['timespec']

        self.GENERIC_HANDLE_APICALLS = {}

        self.GENERIC_HANDLE_STRUCTS = {}

        self.OPENXR_REPLACE_TYPE = {}

        # These types represent pointers to non-OpenXR objects that were written as 64-bit address IDs.
        self.EXTERNAL_OBJECT_TYPES = ['void', 'Void']

        self.MAP_STRUCT_TYPE = {}

        # Dispatchable handle types.
        self.DISPATCHABLE_HANDLE_TYPES = [
            'XrInstance', 'XrSession', 'XrSpace', 'XrAction', 'XrSwapchain',
            'XrActionSet'
        ]

        self.DUPLICATE_HANDLE_TYPES = []

        # Default C++ code indentation size.
        self.INDENT_SIZE = 4

        # Typenames
        self.base_types = dict()  # Set of OpenXR basetypes
        self.struct_names = set()  # Set of OpenXR struct typenames
        self.handle_names = set()  # Set of OpenXR handle typenames
        self.flags_types = dict(
        )  # Map of flags types to base flag type (VkFlags or VkFlags64)
        self.enum_names = set()  # Set of OpenXR enumeration typenames
        self.enumAliases = dict()  # Map of enum names to aliases
        self.enumEnumerants = dict()  # Map of enum names to enumerants

        # Type processing options
        self.process_cmds = process_cmds  # Populate the feature_cmd_params map
        self.process_structs = process_structs  # Populate the feature_struct_members map
        self.feature_break = feature_break  # Insert a line break between features

        # Command parameter and struct member data for the current feature
        if self.process_structs:
            self.feature_struct_members = dict(
            )  # Map of struct names to lists of per-member ValueInfo
            self.feature_struct_aliases = dict(
            )  # Map of struct names to aliases
            self.extension_structs_with_handles = dict(
            )  # Map of extension struct names to a Boolean value indicating that a struct member has a handle type
            self.extension_structs_with_handle_ptrs = dict(
            )  # Map of extension struct names to a Boolean value indicating that a struct member with a handle type is a pointer
        if self.process_cmds:
            self.feature_cmd_params = dict(
            )  # Map of cmd names to lists of per-parameter ValueInfo

        # Basetypes and their corresponding encode command type
        self.encode_types = dict()
        self.encode_types['int8_t'] = 'Int8'
        self.encode_types['int16_t'] = 'Int16'
        self.encode_types['int32_t'] = 'Int32'
        self.encode_types['int64_t'] = 'Int64'
        self.encode_types['uint8_t'] = 'UInt8'
        self.encode_types['uint16_t'] = 'UInt16'
        self.encode_types['uint32_t'] = 'UInt32'
        self.encode_types['uint64_t'] = 'UInt64'
        self.encode_types['XR_DEFINE_ATOM'] = 'UInt64'

        # Add Vulkan handle types to handle list
        self.handle_names.add('VkInstance')
        self.handle_names.add('VkPhysicalDevice')
        self.handle_names.add('VkDevice')
        self.handle_names.add('VkImage')
        self.handle_names.add('VkSwapchainKHR')

        # Add Vulkan enums
        self.enum_names.add('VkResult')
        self.enum_names.add('VkFormat')
        self.enum_names.add('VkFilter')
        self.enum_names.add('VkSamplerMipmapMode')
        self.enum_names.add('VkSamplerAddressMode')
        self.enum_names.add('VkComponentSwizzle')

        self.atom_names = [
            'XrSystemId',
            'XrPath',
            'XrAsyncRequestIdFB',
            'XrRenderModelKeyFB',
            'XrMarkerML',
            'XrControllerModelKeyMSFT',
        ]

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate.
        The subclass should override this method."""
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature.
        The subclass should override this method."""

    def beginFile(self, gen_opts):
        """Method override."""
        OutputGenerator.beginFile(self, gen_opts)

        if gen_opts.blacklists:
            self.__load_blacklists(gen_opts.blacklists)
        if gen_opts.platform_types:
            self.__load_platform_types(gen_opts.platform_types)

            # Platform defined struct processing must be implemented manually,
            # so these structs will be added to the blacklist.
            self.STRUCT_BLACKLIST += self.PLATFORM_STRUCTS

        self.header_sym = 'GFXRECON_' + re.sub(
            '\.h', '_H', os.path.basename(self.genOpts.filename)
        ).upper()

        # User-supplied prefix text, if any (list of strings)
        if (gen_opts.prefix_text):
            for s in gen_opts.prefix_text:
                write(s, file=self.outFile)

        # Multiple inclusion protection & C++ wrappers.
        if (gen_opts.protect_file and self.genOpts.filename):
            write('#ifndef ', self.header_sym, file=self.outFile)
            write('#define ', self.header_sym, file=self.outFile)
            self.newline()

        write('#ifdef ENABLE_OPENXR_SUPPORT', file=self.outFile)
        self.newline()

    def forceCommonXrDefines(self, gen_opts):
        """Write OpenXR defines to enable all entrypoint/struct visibility
        """
        write(
            '// Define the platform defines so that we can have entrypoints for each',
            file=self.outFile
        )
        write(
            '// possible entrypoint in our dispatch table.', file=self.outFile
        )
        write('#ifndef XR_USE_PLATFORM_WIN32', file=self.outFile)
        write('#define XR_USE_PLATFORM_WIN32', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_PLATFORM_WAYLAND', file=self.outFile)
        write('#define XR_USE_PLATFORM_WAYLAND', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_PLATFORM_XCB', file=self.outFile)
        write('#define XR_USE_PLATFORM_XCB', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_PLATFORM_XLIB', file=self.outFile)
        write('#define XR_USE_PLATFORM_XLIB', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_PLATFORM_ANDROID', file=self.outFile)
        write('#define XR_USE_PLATFORM_ANDROID', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_PLATFORM_ML', file=self.outFile)
        write('#define XR_USE_PLATFORM_ML', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_PLATFORM_EGL', file=self.outFile)
        write('#define XR_USE_PLATFORM_EGL', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_GRAPHICS_API_VULKAN', file=self.outFile)
        write('#define XR_USE_GRAPHICS_API_VULKAN', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_GRAPHICS_API_OPENGL', file=self.outFile)
        write('#define XR_USE_GRAPHICS_API_OPENGL', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_GRAPHICS_API_OPENGL_ES', file=self.outFile)
        write('#define XR_USE_GRAPHICS_API_OPENGL_ES', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_GRAPHICS_API_D3D11', file=self.outFile)
        write('#define XR_USE_GRAPHICS_API_D3D11', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_GRAPHICS_API_D3D12', file=self.outFile)
        write('#define XR_USE_GRAPHICS_API_D3D12', file=self.outFile)
        write('#endif', file=self.outFile)

        write('#ifndef XR_USE_TIMESPEC', file=self.outFile)
        write('#define XR_USE_TIMESPEC', file=self.outFile)
        write('#endif', file=self.outFile)

    def includeOpenXrHeaders(self, gen_opts):
        """Write OpenXR header include statements
        """
        write('#include "openxr/openxr.h"', file=self.outFile)
        write(
            '#include "openxr/openxr_loader_negotiation.h"', file=self.outFile
        )
        write('#include "openxr/openxr_platform.h"', file=self.outFile)
        for extra_openxr_header in gen_opts.extraOpenXrHeaders:
            header_include_path = re.sub(r'\\', '/', extra_openxr_header)
            write(f'#include "{header_include_path}"', file=self.outFile)

    def endFile(self):
        """Method override."""

        self.newline()
        write('#endif // ENABLE_OPENXR_SUPPORT', file=self.outFile)

        # Finish C++ wrapper and multiple inclusion protection
        if (self.genOpts.protect_file and self.genOpts.filename):
            self.newline()
            write('#endif // ', self.header_sym, file=self.outFile)

        # Finish processing in superclass
        OutputGenerator.endFile(self)

    def beginFeature(self, interface, emit):
        """Method override. Start processing in superclass."""
        OutputGenerator.beginFeature(self, interface, emit)

        # Reset feature specific data sets
        if self.process_structs:
            self.feature_struct_members = dict()
            self.feature_struct_aliases = dict()
        if self.process_cmds:
            self.feature_cmd_params = dict()

        # Some generation cases require that extra feature protection be suppressed
        if self.genOpts.protect_feature:
            self.featureExtraProtect = self.__get_feature_protect(interface)
        else:
            self.featureExtraProtect = None

    def endFeature(self):
        """Method override. Generate code for the feature."""
        if self.emit and self.need_feature_generation():
            if self.feature_break:
                self.newline()

            if (self.featureExtraProtect is not None):
                write('#ifdef', self.featureExtraProtect, file=self.outFile)

            self.generate_feature()

            if (self.featureExtraProtect is not None):
                write(
                    '#endif /*',
                    self.featureExtraProtect,
                    '*/',
                    file=self.outFile
                )

        # Finish processing in superclass
        OutputGenerator.endFeature(self)

    def genType(self, typeinfo, name, alias):
        """Method override. Type generation."""
        OutputGenerator.genType(self, typeinfo, name, alias)
        type_elem = typeinfo.elem
        # If the type is a struct type, traverse the imbedded <member> tags
        # generating a structure. Otherwise, emit the tag text.
        category = type_elem.get('category')
        if (category == 'struct' or category == 'union'):
            self.struct_names.add(name)
            # Skip code generation for union encode/decode functions.
            if category == 'struct':
                self.genStruct(typeinfo, name, alias)
        elif (category == 'handle'):
            self.handle_names.add(name)
        elif (category == 'bitmask'):
            # Flags can have either VkFlags or VkFlags64 base type
            alias = type_elem.get('alias')
            if alias:
                # Use same base type as the alias if one exists
                self.flags_types[name] = self.flags_types[alias]
            else:
                # Otherwise, look for base type inside type declaration
                self.flags_types[name] = type_elem.find('type').text
        elif (category == "basetype"):
            self.base_types[name] = type_elem.find('type').text

    def genStruct(self, typeinfo, typename, alias):
        """Method override.
        Struct (e.g. C "struct" type) generation.
        This is a special case of the <type> tag where the contents are
        interpreted as a set of <member> tags instead of freeform C
        C type declarations. The <member> tags are just like <param>
        tags - they are a declaration of a struct or union member.
        """
        OutputGenerator.genStruct(self, typeinfo, typename, alias)
        # For structs, we ignore the alias because it is a typedef.  Not ignoring the alias
        # would produce multiple definition errors for functions with struct parameters.
        if self.process_structs:
            if not alias:
                self.feature_struct_members[typename] = self.make_value_info(
                    typeinfo.elem.findall('.//member')
                )
            else:
                self.feature_struct_aliases[typename] = alias

    def genGroup(self, groupinfo, group_name, alias):
        """Method override.
        Group (e.g. C "enum" type) generation.
        These are concatenated together with other types.
        """
        OutputGenerator.genGroup(self, groupinfo, group_name, alias)
        self.enum_names.add(group_name)
        if not alias:
            enumerants = dict()
            for elem in groupinfo.elem:
                supported = elem.get('supported')
                is_supported = False
                if not supported:
                    is_supported = True
                else:
                    supported_list = supported.split(",")
                    for e in supported_list:
                        if e in _supported_subsets:
                            is_supported = True
                            break
                if is_supported:
                    name = elem.get('name')
                    if name and not elem.get('alias'):
                        enumerants[name] = elem.get('value')
            self.enumEnumerants[group_name] = enumerants
        else:
            self.enumAliases[group_name] = alias

    def genEnum(self, enuminfo, name, alias):
        """Method override.
        Enumerant generation
        <enum> tags may specify their values in several ways, but are usually
        just integers.
        """
        OutputGenerator.genEnum(self, enuminfo, name, alias)

    def genCmd(self, cmdinfo, name, alias):
        """Method override. Command generation."""
        OutputGenerator.genCmd(self, cmdinfo, name, alias)
        if self.process_cmds:
            # Create the declaration for the function prototype
            proto = cmdinfo.elem.find('proto')
            proto_decl = self.genOpts.apicall + noneStr(proto.text)
            for elem in proto:
                text = noneStr(elem.text)
                tail = noneStr(elem.tail)
                if (elem.tag == 'name'):
                    proto_decl += self.makeProtoName(text, tail)
                else:
                    proto_decl += text + tail

            return_type = noneStr(proto.text
                                  ) + noneStr(proto.find('type').text)

            # TODO: Define a class or namedtuple for the dictionary entry
            self.feature_cmd_params[name] = (
                return_type, proto_decl,
                self.make_value_info(cmdinfo.elem.findall('param'))
            )

    def make_value_info(self, params):
        """Generate a list of ValueInfo objects from a list of <param> or <member> tags
         params - list of <param> or <member> tags to process
        """
        values = []
        for param in params:
            # Get name
            elem = param.find('name')
            name = noneStr(elem.text)
            name_tail = noneStr(elem.tail)

            # Get type info
            elem = param.find('type')
            base_type = noneStr(elem.text)
            full_type = (noneStr(param.text) + base_type
                         + noneStr(elem.tail)).strip()

            # Check for platform specific type definitions that need to be converted to a recognized trace format type.
            platform_base_type = None
            platform_full_type = None
            if base_type in self.PLATFORM_TYPES:
                type_info = self.PLATFORM_TYPES[base_type]
                platform_base_type = base_type
                platform_full_type = full_type
                full_type = full_type.replace(
                    base_type, type_info['replaceWith']
                )
                base_type = type_info['baseType']

            # Get array length, always use altlen when available to avoid parsing latexmath
            if 'altlen' in param.attrib:
                array_length = param.attrib.get('altlen')
            else:
                array_length = self.get_array_len(param)

            array_capacity = None
            if self.is_static_array(param):
                array_capacity = array_length
                array_length = self.get_static_array_len(
                    name, params, array_capacity
                )

            array_dimension = 0
            if array_length:
                array_length_list = array_length.split(',')
                if array_length_list:
                    array_dimension = len(array_length_list)

            # Get bitfield width
            bitfield_width = None
            if ':' in name_tail:
                bitfield_width = name_tail

            values.append(
                ValueInfo(
                    name=name,
                    base_type=base_type,
                    full_type=full_type,
                    pointer_count=self.get_pointer_count(full_type),
                    array_length=array_length,
                    array_capacity=array_capacity,
                    array_dimension=array_dimension,
                    platform_base_type=platform_base_type,
                    platform_full_type=platform_full_type,
                    bitfield_width=bitfield_width
                )
            )

        # Link array values to their corresponding length values
        for array_value in [v for v in values if v.array_length]:
            for v in values:
                if re.search(
                    r'\b{}\b'.format(v.name), array_value.array_length
                ):
                    array_value.array_length_value = v
                    break

        return values

    def is_struct(self, base_type):
        """Check for struct type."""
        if (
            (base_type in self.struct_names)
            or (base_type in self.PLATFORM_STRUCTS)
        ):
            return True
        return False

    def is_class(self, value):
        return False

    def is_handle(self, base_type):
        """Check for handle type."""
        if base_type in self.handle_names:
            return True
        return False

    def is_dispatchable_handle(self, base_type):
        """Check for dispatchable handle type."""
        if base_type in self.DISPATCHABLE_HANDLE_TYPES:
            return True
        return False

    def is_enum(self, base_type):
        """Check for enum type."""
        if base_type in self.enum_names:
            return True
        return False

    def is_union(self, value):
        return False

    def is_flags(self, base_type):
        """Check for flags (bitmask) type."""
        if base_type in self.flags_types:
            return True
        return False

    def is_function_ptr(self, base_type):
        """Check for function pointer type."""
        if (base_type[:4] == 'PFN_') or (base_type[-4:] == 'Func'):
            return True
        return False

    def is_array_len(self, name, values):
        """Determine if the value name specifies an array length."""
        for value in values:
            if name == value.array_length:
                return True
        return False

    def get_pointer_count(self, full_type):
        """Return the number of '*' in a type declaration."""
        return full_type.count('*')

    def is_input_pointer(self, value):
        """Determine if a pointer parameter is an input parameter."""
        if 'const' in value.full_type:
            # Khrons APIs seems to follow a pattern where input pointers will be const and output pointers will not be const.
            return True
        elif value.platform_base_type and value.base_type == 'void' and value.pointer_count == 1:
            # For some extensions, platform specific handles are mapped to the 'void*' type without a const qualifier,
            # but need to be treated as an input (eg. if HANDLE is mapped to void*, it should not be treated as an output).
            return True
        return False

    def is_output_parameter(self, value):
        """Determine if a parameter is an output parameter."""
        # Check for an output pointer/array or an in-out pointer.
        if (
            (value.is_pointer or value.is_array)
            and not self.is_input_pointer(value)
        ):
            return True
        return False

    def get_array_len(self, param):
        """Retrieve the length of an array defined by a <param> or <member> element."""
        result = None
        len = param.attrib.get('len')
        if len:
            # Check for a string or array of strings
            if 'null-terminated' in len:
                # Strings are ignored, but string arrays are checked for a length value.
                # For string arrays, 'len' can look like 'count,null-terminated', indicating that we have an array of null terminated
                # strings.  We strip the null-terminated substring from the 'len' field and only return the parameter specifying the string count.
                if len != 'null-terminated':
                    result = len.split(',')[0]
            else:
                result = len
            if result:
                result = str(result).replace('::', '->')
        else:
            # Check for a static array
            paramname = param.find('name')
            if (paramname.tail is not None) and ('[' in paramname.tail):
                paramenumsizes = param.findall('enum')
                if paramenumsizes:
                    first = True
                    for paramenumsize in paramenumsizes:
                        if first:
                            first = False
                            result = paramenumsize.text
                        else:
                            result += ', '
                            result += paramenumsize.text
                else:
                    paramsizes = paramname.tail[1:-1].split('][')
                    sizetokens = []
                    for paramsize in paramsizes:
                        sizetokens.append(paramsize)
                    result = ', '.join(sizetokens)
        return result

    def is_static_array(self, param):
        """Check for a static array."""
        name = param.find('name')
        if (name.tail is not None) and ('[' in name.tail):
            return True
        return False

    def get_static_array_len(self, name, params, capacity):
        """Determine the length value of a static array (get_array_len() returns the total capacity, not the actual length)."""
        # The XML registry does not provide a direct method for determining if a parameter provides the length
        # of a static array, but the parameter naming follows a pattern of array name = 'values' and length
        # name = 'value_count'.  We will search the parameter list for a length parameter using this pattern.
        length_name = name[:-1] + 'Count'
        for param in params:
            if length_name == noneStr(param.find('name').text):
                return length_name

        # Not all static arrays have an associated length parameter. These will use capacity as length.
        return capacity

    def is_struct_black_listed(self, typename):
        """Determines if a struct with the specified typename is blacklisted."""
        if typename in self.STRUCT_BLACKLIST:
            return True
        return False

    def is_cmd_black_listed(self, name):
        """Determines if a function with the specified typename is blacklisted."""
        if name in self.APICALL_BLACKLIST:
            return True
        if 'Decoder' in self.__class__.__name__ and name in self.APICALL_DECODER_BLACKLIST:
            return True
        if 'Encoder' in self.__class__.__name__ and name in self.APICALL_ENCODER_BLACKLIST:
            return True
        return False

    def is_method_black_listed(self, class_name, method_name=None):
        """Determines if a method call with the specified typename is blacklisted."""
        combined_name = class_name
        if method_name:
            combined_name += '_' + method_name
        if combined_name in self.METHODCALL_BLACKLIST:
            return True
        return False

    def get_filtered_struct_names(self):
        """Retrieves a filtered list of keys from self.feature_struct_memebers with blacklisted items removed."""
        return [
            key for key in self.feature_struct_members
            if not self.is_struct_black_listed(key)
        ]

    def get_filtered_cmd_names(self):
        """Retrieves a filtered list of keys from self.feature_cmd_params with blacklisted items removed."""
        return [
            key for key in self.feature_cmd_params
            if not self.is_cmd_black_listed(key)
        ]

    def clean_type_define(self, full_type):
        """Default to identity function, base classes may override."""
        return full_type

    def check_struct_next_handles(self, typename):
        """Determines if the specified struct type can reference next extension structs that contain handles."""
        found_handles = False
        found_handle_ptrs = False
        valid_extension_structs = self.registry.validextensionstructs.get(
            typename
        )
        if valid_extension_structs:
            # Need to search the XML tree for next structures that have not been processed yet.
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
            if self.is_handle(value.base_type) or self.is_class(value) or (
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
            elif ('next' in value.name):
                # The next chain may include a struct with handles.
                has_next_handles, has_next_handle_ptrs = self.check_struct_next_handles(
                    typename
                )
                if has_next_handles:
                    handles.append(value)
                    if (
                        structs_with_handle_ptrs is not None
                    ) and has_next_handle_ptrs:
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

    def get_generic_struct_handle_type_value(self, struct_name, member_name):
        """For a struct member that contains a generic handle value, retrieve the struct member
        containing an enum value defining the specific handle type.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as XrObjectType.
        """
        if struct_name in self.GENERIC_HANDLE_STRUCTS:
            struct_entry = self.GENERIC_HANDLE_STRUCTS[struct_name]
            if member_name in struct_entry:
                return struct_entry[member_name]
        return None

    def get_generic_cmd_handle_type_value(self, cmd_name, param_name):
        """For an API call parameter that contains a generic handle value, retrieve the parameter
        containing an enum value defining the specific handle type.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as XrObjectType.
        """
        if cmd_name in self.GENERIC_HANDLE_APICALLS:
            cmd_entry = self.GENERIC_HANDLE_APICALLS[cmd_name]
            if param_name in cmd_entry:
                return cmd_entry[param_name]
        return None

    def is_generic_struct_handle_value(self, struct_name, member_name):
        """Determine if a struct member contains a generic handle value.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as XrObjectType.
        """
        if self.get_generic_struct_handle_type_value(struct_name, member_name):
            return True
        return False

    def is_generic_cmd_handle_value(self, cmd_name, param_name):
        """Determine if an API call parameter contains a generic handle value.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as XrObjectType.
        """
        if self.get_generic_cmd_handle_type_value(cmd_name, param_name):
            return True
        return False

    def indent(self, value, spaces):
        """Indent all lines in a string.
        value - String to indent.
        spaces - Number of spaces to indent.
        """
        prefix = ' ' * spaces
        return '\n'.join([prefix + v if v else v for v in value.split('\n')])

    def make_unique_list(self, in_list):
        """Return a copy of in_list with duplicates removed, preserving order."""
        out_list = []
        for value in in_list:
            if value not in out_list:
                out_list.append(value)
        return out_list

    def make_arg_list(self, values):
        """Create a string containing a comma separated argument list from a list of ValueInfo values.
        values - List of ValueInfo objects providing the parameter names for the argument list.
        """
        return ', '.join([value.name for value in values])

    def make_aligned_param_decl(
        self, param_type, param_name, indent_column, align_column
    ):
        """make_aligned_param_decl - return an indented parameter declaration string with the parameter
        name aligned to the specified column.
        """
        param_decl = ' ' * indent_column
        param_decl += param_type

        if align_column:
            param_decl = param_decl.ljust(align_column - 1)

        param_decl += ' '
        param_decl += param_name

        return param_decl

    def make_invocation_type_name(self, base_type):
        """Convert a type name to a string to be used as part of an encoder/decoder function/method name."""
        if self.is_struct(base_type):
            return base_type
        elif self.is_handle(base_type):
            type_name = self.get_prefix_from_type(base_type)
            type_name += 'Handle'
            return type_name
        elif self.is_flags(base_type):
            # Strip 'Xr' from base flag type
            return self.flags_types[base_type][2:]
        elif self.is_enum(base_type):
            return 'Enum'
        elif base_type == 'wchar_t':
            return 'WString'
        elif base_type == 'char':
            return 'String'
        elif self.is_function_ptr(base_type):
            return 'FunctionPtr'
        elif base_type == 'size_t':
            return 'SizeT'
        elif base_type == 'int':
            # Extensions use the int type when dealing with file descriptors
            return 'Int32'
        elif base_type.endswith('_t'):
            if base_type[0] == 'u':
                # For unsigned types, capitalize the first two characters.
                return base_type[0].upper() + base_type[1].upper(
                ) + base_type[2:-2]
            else:
                return base_type[:-2].title()
        elif base_type[0].islower():
            return base_type.title()

        return base_type

    def make_decoded_param_type(self, value):
        """Create a type to use for a decoded parameter, using the decoder wrapper types for pointers."""
        type_name = value.base_type

        # is_pointer will be False for static arrays.
        if value.is_pointer or value.is_array:
            count = value.pointer_count

            if self.is_struct(type_name):
                type_name = 'StructPointerDecoder<Decoded_{}>'.format(
                    type_name
                )
            elif self.is_class(value):
                if count == 1:
                    type_name = 'format::HandleId'
                else:
                    type_name = 'HandlePointerDecoder<{}*>'.format(type_name)
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
                    # So, we specify uint64_t as the decode type and void* as the type to be used for OpenXR API call output parameters.
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

    def make_consumer_func_decl(self, return_type, name, values):
        """make_consumer_decl - return OpenXrConsumer class member function declaration.
        Generate OpenXrConsumer class member function declaration.
        """
        param_decls = []
        param_decl = self.make_aligned_param_decl(
            'const ApiCallInfo&', 'call_info', self.INDENT_SIZE,
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

    def make_structure_type_enum(self, typeinfo, typename):
        """Generate the XrStructureType enumeration value for the specified structure type."""
        members = typeinfo.elem.findall('.//member')

        for member in members:
            membername = noneStr(member.find('name').text)

            # We only care about structures with a type, which can be included in a next chain.
            if membername == 'type':
                # Check for value in the XML element.
                values = member.attrib.get('values')

                if values:
                    return values
                else:
                    # If the value was not specified by the XML element, process the struct type to create it.
                    type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', typename)
                    type = type.upper()
                    return re.sub('XR_', 'XR_TYPE_', type)
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
            type_list = ', '.join(
                [self.clean_type_define(v.full_type) for v in values]
            )
            arg_list = ', '.join([v.name for v in values])
            return ['ArraySize2D<{}>({})'.format(type_list, arg_list)]

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
        is_handle = 'Handle' in type_name
        is_atom = type_name in self.atom_names

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

            if type_name.startswith("Vk") and "Flags" in type_name:
                method_call += 'Flags'
            elif is_atom:
                method_call += 'OpenXrAtom'
            elif type_name in self.base_types and self.base_types[
                type_name] is not None:
                method_call += self.encode_types[self.base_types[type_name]]
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

        if is_handle or is_atom:
            wrapper_prefix = self.get_wrapper_prefix_from_type(value.base_type)
            method_call += '<{}>'.format(
                wrapper_prefix + '::' + value.base_type[2:] + 'Wrapper'
            )

        if self.is_output_parameter(value) and omit_output_param:
            args.append(omit_output_param)

        return '{}({})'.format(method_call, ', '.join(args))

    def __get_feature_protect(self, interface):
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

    def __load_blacklists(self, filename):
        lists = json.loads(open(filename, 'r').read())
        self.APICALL_BLACKLIST += lists['functions-all']
        self.APICALL_ENCODER_BLACKLIST += lists['functions-encoder']
        self.APICALL_DECODER_BLACKLIST += lists['functions-decoder']
        self.STRUCT_BLACKLIST += lists['structures']
        if 'classmethods' in lists:
            for class_name, method_list in lists['classmethods'].items():
                for method_name in method_list:
                    self.METHODCALL_BLACKLIST.append(
                        class_name + '_' + method_name
                    )

    def __load_platform_types(self, filename):
        platforms = json.loads(open(filename, 'r').read())
        for platform_name in platforms:
            platform = platforms[platform_name]
            platform_types = platform['types']
            platform_types.update(self.OPENXR_REPLACE_TYPE)

            for type in platform_types:
                self.PLATFORM_TYPES[type] = platform_types[type]

            platform_structs = platform['structs']
            if platform_structs:
                self.PLATFORM_STRUCTS += platform_structs

    # Return true if the type passed in is used to hold a set of bitwise flags
    # that is 64 bits wide.
    def is_64bit_flags(self, flag_type):
        if flag_type in self.flags_types:
            if self.flags_types[flag_type] == 'XrFlags64':
                return True
        return False

    # Return true if the enum or 64 bit pseudo enum passed-in represents a set
    # of bitwise flags.
    # Note, all 64 bit pseudo-enums represent flags since the only reason to go to
    # 64 bits is to allow more than 32 flags to be represented.
    def is_flags_enum_64bit(self, enum):
        flag_type = BitsEnumToFlagsTypedef(enum)
        return self.is_64bit_flags(flag_type)

    def is_has_specific_key_word_in_type(self, value, key_word):
        if key_word in value.base_type:
            return True

        values = self.feature_struct_members.get(value.base_type)
        if values:
            for value in values:
                return self.is_has_specific_key_word_in_type(value, key_word)
        return False
