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
from base_generator_defines import BaseGeneratorDefines, ValueInfo, bits_enum_to_flags_typedef, make_re_string
from collections import OrderedDict
from generator import GeneratorOptions, OutputGenerator, noneStr, regSortFeatures, write
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

_supported_subsets = ["openxr"]

# Turn lists of names/patterns into matching regular expressions.
# From Khronos genvk.py
_add_extensions_pat = make_re_string(_extensions)
_remove_extensions_pat = make_re_string(_remove_extensions)
_emit_extensions_pat = make_re_string(_emit_extensions, '.*')
_features_pat = make_re_string(_features, '.*')


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


class BaseGenerator(BaseGeneratorDefines, OutputGenerator):
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
        BaseGeneratorDefines.__init__(self)

        # Platform specific structure types that have been defined extarnally to the OpenXR header.
        self.PLATFORM_STRUCTS = ['timespec']

        self.DUPLICATE_HANDLE_TYPES = []

        # Basetypes and their corresponding encode command type
        self.encode_types['XR_DEFINE_ATOM'] = 'UInt64'
        self.encode_types['XR_DEFINE_OPAQUE_64'] = 'UInt64'

        # Add Vulkan handle types to handle list
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

        if self.process_structs:
            self.extension_structs_with_handles = OrderedDict(
            )  # Map of extension struct names to a Boolean value indicating that a struct member has a handle type
            self.extension_structs_with_handle_ptrs = OrderedDict(
            )  # Map of extension struct names to a Boolean value indicating that a struct member with a handle type is a pointer]

    def beginFile(self, gen_opts):
        """Method override."""
        OutputGenerator.beginFile(self, gen_opts)
        BaseGeneratorDefines.beginFile(self, gen_opts)

        # User-supplied prefix text, if any (list of strings)
        if (gen_opts.prefix_text):
            for s in gen_opts.prefix_text:
                write(s, file=self.outFile)

        # Multiple inclusion protection & C++ wrappers.
        if (gen_opts.protect_file and self.genOpts.filename):
            self.header_sym = 'GFXRECON_' + os.path.basename(
                self.genOpts.filename
            ).replace('.h', '_H').upper()
            write('#ifndef ', self.header_sym, file=self.outFile)
            write('#define ', self.header_sym, file=self.outFile)
            self.newline()

        write('#ifdef ENABLE_OPENXR_SUPPORT', file=self.outFile)
        self.newline()

    def includeOpenXrHeaders(self, gen_opts):
        """Write OpenXR header include statements
        """
        write('#include "format/platform_types.h"', file=self.outFile)
        self.newline()
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
        BaseGeneratorDefines.beginFeature(self, interface, emit)

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
            self.all_structs.append(name)
            # Skip code generation for union encode/decode functions.
            if category == 'struct':
                self.genStruct(typeinfo, name, alias)
            else:
                self.all_unions.append(name)
        elif (category == 'handle'):
            self.handle_names.add(name)
            if (
                type_elem is not None and type_elem.find('type') is not None
                and type_elem.find('type').text == 'XR_DEFINE_HANDLE'
            ):
                self.dispatchable_handle_names.add(name)
        elif (category == 'bitmask'):
            # Flags can have either XrFlags or XrFlags64 base type
            alias = type_elem.get('alias')
            if alias:
                if name not in self.flags_types:
                    self.flags_types[name] = self.flags_types[alias]

                # Use same base type as the alias if one exists
                self.flags_type_aliases[name] = alias
                if alias in self.flag_enum_bits_type:
                    self.flag_enum_bits_type[name] = self.flag_enum_bits_type[
                        alias]
            else:
                if name not in self.flags_types:
                    # Otherwise, look for base type inside type declaration
                    self.flags_types[name] = type_elem.find('type').text

                    bittype = typeinfo.elem.get('requires')
                    if bittype is None:
                        bittype = typeinfo.elem.get('bitvalues')
                    if bittype is not None:
                        self.flag_enum_bits_type[name] = bittype
                        if bittype not in self.bitfields_names:
                            self.bitfields_names.append(bittype)
                        if bittype not in self.flag_bits_types:
                            self.flag_bits_types[bittype] = type_elem.find(
                                'type'
                            ).text

        elif (category == "basetype") and type_elem.find('type') is not None:
            type_info = type_elem.find('type').text
            if type_info == 'XR_DEFINE_ATOM':
                self.atom_names.add(name)
            elif type_info == 'XR_DEFINE_OPAQUE_64':
                self.opaque_names.add(name)
            elif not name == 'XrTime':
                self.base_types[name] = type_info

    def genStruct(
        self,
        typeinfo,
        typename,
        alias,
        supress_base_call=False,
        supress_local_processing=False
    ):
        """Method override.
        Struct (e.g. C "struct" type) generation.
        This is a special case of the <type> tag where the contents are
        interpreted as a set of <member> tags instead of freeform C
        C type declarations. The <member> tags are just like <param>
        tags - they are a declaration of a struct or union member.
        """
        if not supress_base_call:
            OutputGenerator.genStruct(self, typeinfo, typename, alias)

        if supress_local_processing:
            return

        struct_type_enum = self.make_structure_type_enum(typeinfo, typename)
        if struct_type_enum is not None and struct_type_enum in self.enum_enumerants[
            'XrStructureType']:
            self.struct_type_enums[typename] = struct_type_enum

        # For structs, we ignore the alias because it is a typedef.  Not ignoring the alias
        # would produce multiple definition errors for functions with struct parameters.
        if self.process_structs:
            if not alias:
                self.set_struct_members(
                    typename,
                    self.make_value_info(typeinfo.elem.findall('.//member'))
                )

                # If this struct has a parent name, keep track of all
                # the parents and their children
                parent_name = typeinfo.elem.get('parentstruct')
                if parent_name:
                    # If it doesn't already appear in the list of parents,
                    # add an entry for it.
                    if parent_name not in self.base_header_structs.keys():
                        self.base_header_structs[parent_name] = []

                    self.base_header_structs[parent_name].append(typename)

                extended_struct = typeinfo.elem.get('structextends')
                if extended_struct:
                    self.extended_structs[typename] = extended_struct
            else:
                self.set_struct_aliases(typename, alias)

    def genUnion(self, typeinfo, typename, alias):
        """Method override.
        Union (e.g. C "union" type) generation.
        This is a special case of the <type> tag where the contents are
        interpreted as a set of <member> tags instead of freeform C
        C type declarations. The <member> tags are just like <param>
        tags - they are a declaration of a struct or union member.
        """
        # For structs, we ignore the alias because it is a typedef.  Not ignoring the alias
        # would produce multiple definition errors for functions with struct parameters.
        if self.process_structs:
            self.all_unions.append(typename)
            if not alias:
                if typename not in self.feature_union_members:
                    self.set_union_members(
                        typename,
                        self.make_value_info(
                            typeinfo.elem.findall('.//member')
                        )
                    )
            else:
                if typename not in self.feature_union_aliases:
                    self.set_union_aliases(typename, alias)

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
            self.enum_enumerants[group_name] = enumerants
        else:
            self.enum_aliases[group_name] = alias

    def genCmd(
        self,
        cmdinfo,
        name,
        alias,
        supress_base_call=False,
        supress_local_processing=False
    ):
        """Method override. Command generation."""
        if not supress_base_call:
            OutputGenerator.genCmd(self, cmdinfo, name, alias)

        if self.process_cmds and not supress_local_processing:
            if self.is_cmd_black_listed(name):
                return

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

            self.save_command_and_params(
                name, (
                    return_type, proto_decl,
                    self.make_value_info(cmdinfo.elem.findall('param'))
                )
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

            is_optional = False
            if 'optional' in param.attrib:
                is_optional = param.attrib.get('optional').lower() == 'true'

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
                    bitfield_width=bitfield_width,
                    is_optional=is_optional
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

    def is_handle(self, base_type):
        """Check for handle type.  The subclass may override this method."""
        if base_type in self.handle_names and self.is_valid_handle(base_type):
            return True
        return False

    def is_dispatchable_handle(self, base_type):
        """Check for dispatchable type.  The subclass may override this method."""
        if base_type in self.dispatchable_handle_names:
            return True
        return False

    def is_atom(self, base_type):
        if base_type in self.atom_names:
            return True
        return False

    def is_opaque(self, base_type):
        if base_type in self.opaque_names:
            return True
        return False

    def get_default_handle_atom_value(self, base_type):
        if self.is_handle(base_type):
            if base_type.startswith('Vk'):
                return 'VK_NULL_HANDLE'
            elif base_type.startswith('Xr'):
                return 'XR_NULL_HANDLE'
            else:
                return 'UNKNOWN_NULL_HANDLE'
        elif self.is_atom(base_type):
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
        elif self.is_opaque(base_type):
            return '0'

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

    def check_struct_next_handles(self, typename):
        """Determines if the specified struct type can reference next extension structs that contain handles."""
        has_handles = False
        has_handle_ptrs = False
        valid_extension_structs = self.registry.validextensionstructs.get(
            typename
        )
        if valid_extension_structs:
            # Need to search the XML tree for next structures that have not been processed yet.
            for struct_name in valid_extension_structs:
                found_handles, found_handle_ptrs, handle_list = self.struct_has_handles(
                    struct_name
                )
                has_handles = has_handles or found_handles
                has_handle_ptrs = has_handle_ptrs or found_handle_ptrs
                if has_handles and has_handle_ptrs:
                    break

        if typename in self.extended_structs:
            # If struct has a extends another, then its "next" has the same has_* as the parent
            has_handles, has_handle_ptrs = self.check_struct_next_handles(
                self.extended_structs[typename]
            )

        return has_handles, has_handle_ptrs

    def check_struct_member_handles(
        self,
        typename,
        structs_with_handles,
        structs_with_handle_ptrs=None,
        ignore_output=False,
        extra_types=None,
        struct_members=None
    ):
        """Determines if the specified struct type contains members that have a handle type or are structs that contain handles.
        Structs with member handles are added to a dictionary, where the key is the structure type and the value is a list of the handle members.
        An optional list of structure types that contain handle members with pointer types may also be generated.
        """
        handles = []
        has_handles = False
        has_handle_pointer = False

        # Allow the caller to use a different member list
        if not struct_members:
            if typename not in self.all_struct_members:
                return has_handles, has_handle_pointer, handles
            struct_members = self.all_struct_members[typename]

        map_data = []
        for value in struct_members:
            if (
                self.is_handle_like(value.base_type) or self.is_class(value)
                or (extra_types and value.base_type in extra_types)
            ):
                # The member is a handle.
                handles.append(value)
                if (
                    (structs_with_handle_ptrs is not None)
                    and (value.is_pointer or value.is_array)
                ):
                    has_handle_pointer = True
            elif self.is_struct(value.base_type):
                has_handles, has_handle_ptrs, handle_list = self.struct_has_handles(
                    value.base_type
                )
                if has_handles and (
                    (not ignore_output) or (not '_Out_' in value.full_type)
                ):
                    # The member is a struct that contains a handle.
                    handles.append(value)
                    if (
                        structs_with_handle_ptrs is not None
                    ) and has_handle_ptrs:
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
            elif ('next' == value.name):
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

        if handles:
            # Process the list of struct members a second time to check for
            # members with the same type as the struct.  The current struct
            # type has not been added to the table of structs with handles
            # yet, so we must check the struct members a second time, looking
            # for members with the struct type, now that we know the current
            # struct type contains members that are handles/objects.  Any
            # struct members that have the same type as the struct must be
            # added to the handle member list.
            for value in struct_members:
                if (value.base_type == typename) and (
                    (not ignore_output) or (not '_Out_' in value.full_type)
                ):
                    handles.append(value)

            structs_with_handles[typename] = handles
            if (structs_with_handle_ptrs is not None) and has_handle_pointer:
                structs_with_handle_ptrs.append(typename)
            return True
        return False

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
                    replace_1 = re.sub('XR_', 'XR_TYPE_', type)
                    return re.sub('VK_', 'VK_STRUCTURE_TYPE_', replace_1)
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

    def make_consumer_func_decl(self, return_type, name, values):
        """make_consumer_decl - return VulkanConsumer class member function declaration.
        Generate VulkanConsumer class member function declaration.
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
    def is_64bit_flags(self, flag_type):
        if (
            (
                flag_type in self.flags_types
                and self.flags_types[flag_type] == 'XrFlags64'
            ) or (
                flag_type in self.flag_bits_types
                and self.flag_bits_types[flag_type] == 'XrFlags64'
            )
        ):
            return True
        return False

    def is_has_specific_key_word_in_type(self, value, key_word):
        if key_word in value.base_type:
            return True

        values = self.struct_members.get(value.base_type)
        if values:
            for value in values:
                return self.is_has_specific_key_word_in_type(value, key_word)
        return False

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

    def struct_has_handles(self, struct_name):
        """Determines if the struct has handles and handle_ptrs, and caches check"""
        # Check for cached results from a previous check for this struct
        has_handles = False
        has_handle_ptrs = False
        handles = []

        if struct_name in self.structs_with_handles:
            has_handles = True
            handles.extend(self.structs_with_handles[struct_name])
            if struct_name in self.structs_with_handle_ptrs:
                has_handle_ptrs = True

            return has_handles, has_handle_ptrs, handles

        type_info = self.registry.lookupElementInfo(
            struct_name, self.registry.typedict
        )
        if not type_info:
            return has_handles, has_handle_ptrs, handles

        member_infos = [
            member for member in type_info.elem.findall('.//member/type')
        ]
        if not member_infos:
            return has_handles, has_handle_ptrs, handles

        member_type_infos = [
            self.registry.lookupElementInfo(
                member_info.text, self.registry.typedict
            ) for member_info in member_infos
        ]

        for member_type_info in member_type_infos:
            # Note: member_info.text is the type name
            member_elem = member_type_info.elem
            member_type = member_elem.attrib['name']
            #member_category = member_elem.attrib.get('category', '')
            member_category = member_elem.get('category')

            # Check to see if this is a struct and recur
            if member_category == 'struct':
                if not self.is_struct_black_listed(
                    member_type
                ) and not 'XrApiLayerNextInfo' == member_type:
                    # For compound types we recur
                    found_handles, found_handle_ptrs, handles = self.struct_has_handles(
                        member_type
                    )
                    has_handles = has_handles or found_handles
                    has_handle_ptrs = has_handle_ptrs or found_handle_ptrs
            else:
                # Check to see if this is a handle
                found_handle = member_category == 'handle'

                # Check for Vulkan handles as well.
                if member_type in self.handle_names:
                    found_handle = True

                # Also check to see if this is an atom or an opaque type
                found_atom = False
                found_opaque = False

                if member_category == 'basetype':
                    base_type = self.registry.tree.find(
                        "types/type/[name='" + member_type
                        + "'][@category='basetype']"
                    )
                    base_type_type = base_type.find('type')
                    if base_type_type is not None and base_type_type.text is not None:
                        if base_type_type.text == 'XR_DEFINE_ATOM':
                            found_atom = True
                        if base_type_type.text == 'XR_DEFINE_OPAQUE_64':
                            found_opaque = True

                if found_handle or found_atom or found_opaque:
                    has_handles = True
                    if member_elem.tail and ('*' in member_elem.tail):
                        has_handle_ptrs = True

            if has_handles and has_handle_ptrs:
                # Nothing more to be learned
                break

        if has_handles:
            self.structs_with_handles[struct_name] = handles
        if has_handle_ptrs:
            self.structs_with_handle_ptrs.append(struct_name)
        return has_handles, has_handle_ptrs, handles
