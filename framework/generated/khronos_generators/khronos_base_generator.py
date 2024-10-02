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
from collections import OrderedDict
from generator import GeneratorOptions, OutputGenerator, noneStr, regSortFeatures


class KhronosBaseGeneratorOptions(GeneratorOptions):
    """KhronosBaseGeneratorOptions - subclass of GeneratorOptions.
    Options for Khronos API parameter encoding and decoding C++ code generation.

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
        conventions=None,
        apicall='',
        apientry='',
        apientryp='',
        indent_func_proto=True,
        align_func_param=48,
        sort_procedure=None,
        apiname='',
        profile=None,
        versions=None,
        emitversions=None,
        default_extensions=None,
        add_extensions=None,
        remove_extensions=None,
        emit_extensions=None,
        extraHeaders=[]
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
        self.apientry = apientry
        self.apientryp = apientryp
        self.indent_func_proto = indent_func_proto
        self.align_func_param = align_func_param
        self.code_generator = True
        self.extraHeaders = extraHeaders


class KhronosBaseGenerator(BaseGeneratorDefines, OutputGenerator):
    """KhronosBaseGenerator - subclass of OutputGenerator.
    Base class providing common operations used to generate C++-language code for framework
      components that encode and decode Khronos API parameters.
    Base class for Khronos API parameter encoding and decoding generators.
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

        self.PLATFORM_STRUCTS = []
        self.DUPLICATE_HANDLE_TYPES = []

        # Map of structs containing handles to a list values for handle members or struct members
        # that contain handles.
        self.structs_with_handles = dict()
        self.struct_enum_value = dict()

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

    def includeExtraHeaders(self, gen_opts):
        """Write extra header include statements
        """
        for extra_header in gen_opts.extraHeaders:
            header_include_path = re.sub(r'\\', '/', extra_header)
            write(f'#include "{header_include_path}"', file=self.outFile)

    def endFile(self):
        """Method override."""

        # Finish C++ wrapper and multiple inclusion protection
        if (self.genOpts.protect_file and self.genOpts.filename):
            self.newline()
            write('#endif // ', self.header_sym, file=self.outFile)

        # Finish processing in superclass
        OutputGenerator.endFile(self)

    def get_feature_protect(self, interface):
        return None

    def beginFeature(self, interface, emit):
        """Method override. Start processing in superclass."""
        OutputGenerator.beginFeature(self, interface, emit)
        BaseGeneratorDefines.beginFeature(self, interface, emit)

        # Some generation cases require that extra feature protection be suppressed
        if self.genOpts.protect_feature:
            self.featureExtraProtect = self.get_feature_protect(interface)
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

    def checkRemainingBaseTypes(self, name, type_info):
        self.base_types[name] = type_info

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
                self.genUnion(typeinfo, name, alias)
        elif (category == 'handle'):
            self.handle_names.add(name)
            if (
                type_elem is not None and type_elem.find('type') is not None
                and '_DEFINE_HANDLE' == type_elem.find('type').text[2:]
            ):
                self.dispatchable_handle_names.add(name)
        elif (category == 'bitmask'):
            # Flags can have either Flags or Flags64 base type
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

        elif (
            (category == "basetype") and (
                type_elem.find('type') is not None
                and type_elem.find('type').text is not None
            )
        ):
            self.checkRemainingBaseTypes(name, type_elem.find('type').text)

    def generateStructureType(self, typeinfo, typename):
        return

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

        if supress_local_processing or not self.process_structs:
            return

        self.generateStructureType(typeinfo, typename)

        # For structs, we ignore the alias because it is a typedef.  Not ignoring the alias
        # would produce multiple definition errors for functions with struct parameters.
        if self.process_structs:
            if not alias:
                self.set_struct_members(
                    typename,
                    self.makeValueInfo(typeinfo.elem.findall('.//member'))
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
                        self.makeValueInfo(typeinfo.elem.findall('.//member'))
                    )
            else:
                if typename not in self.feature_union_aliases:
                    self.set_union_aliases(typename, alias)

    def genGroup(self, groupinfo, group_name, alias):
        """Method override.
        Group (e.g. C "enum" type) generation.
        These are concatenated together with other types.
        """
        super().genGroup(groupinfo, group_name, alias)
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
                        if e in self.genOpts.apiname:
                            is_supported = True
                            break
                if is_supported:
                    name = elem.get('name')
                    if name and not elem.get('alias'):
                        enumerants[name] = elem.get('value')
            self.enum_enumerants[group_name] = enumerants
        else:
            self.enum_aliases[group_name] = alias

    def createCmdProtoDecl(self, proto_decl, text, tail):
        return self.makeProtoName(text, tail)

    def genCmd(
        self,
        cmdinfo,
        name,
        alias,
        supress_base_call=False,
        supress_local_processing=False,
        supress_blacklisted_cmds=False
    ):
        """Method override. Command generation."""
        if not supress_base_call:
            super().genCmd(cmdinfo, name, alias)

        if self.process_cmds and not supress_local_processing:
            if supress_blacklisted_cmds and self.is_cmd_black_listed(name):
                return

            # Create the declaration for the function prototype
            proto = cmdinfo.elem.find('proto')
            proto_decl = self.genOpts.apicall + noneStr(proto.text)
            for elem in proto:
                text = noneStr(elem.text)
                tail = noneStr(elem.tail)
                if (elem.tag == 'name'):
                    proto_decl += self.createCmdProtoDecl(
                        proto_decl, text, tail
                    )
                else:
                    proto_decl += text + tail

            return_type = noneStr(proto.text
                                  ) + noneStr(proto.find('type').text)

            self.save_command_and_params(
                name, (
                    return_type, proto_decl,
                    self.makeValueInfo(cmdinfo.elem.findall('param'))
                )
            )

            # Look for output structs that contain handles and add to list
            if not self.is_cmd_black_listed(name) and alias is None:
                for value_info in self.feature_cmd_params[name][2]:
                    if self.is_output_parameter(value_info) and (
                        value_info.base_type
                        in self.get_filtered_struct_names()
                    ) and (value_info.base_type
                           in self.structs_with_handles) and (
                               value_info.base_type
                               not in self.output_structs_with_handles
                           ):
                        self.output_structs_with_handles.append(
                            value_info.base_type
                        )

                        for member in self.structs_with_handles[
                            value_info.base_type]:
                            if self.is_struct(member.base_type):
                                found_handles, found_handle_ptrs, temp_handles = self.structHasHandles(
                                    member.base_type
                                )
                                if (
                                    (found_handles or found_handle_ptrs) and (
                                        member.base_type
                                        not in self.output_structs_with_handles
                                    )
                                ):
                                    self.output_structs_with_handles.append(
                                        member.base_type
                                    )

    def makeValueInfo(self, params):
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

    def get_default_handle_atom_value(self, base_type):
        if self.is_handle(base_type):
            all_caps_prefix = base_type[0:2].upper()
            return all_caps_prefix + '_NULL_HANDLE'
        else:
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
                if len == 'null-terminated':
                    paramname = param.find('name')
                    if (paramname.tail
                        is not None) and ('[' in paramname.tail):
                        paramenumsizes = param.findall('enum')
                        for paramenumsize in paramenumsizes:
                            # If there is more than one we'll pick the last one. But current vk.xml file doesn't have an instance with more than one.
                            result = paramenumsize.text
                else:
                    # For string arrays, 'len' can look like 'count,null-terminated', indicating that we have an array of null terminated
                    # strings.  We strip the null-terminated substring from the 'len' field and only return the parameter specifying the string count.
                    result = len.split(',')[0]
            else:
                paramname = param.find('name')
                # If there is an enum inside "[...]", return the enum
                if (paramname.tail is not None) and ('[' in paramname.tail):
                    result = None
                    paramenumsizes = param.findall('enum')
                    for paramenumsize in paramenumsizes:
                        # If there is more than one we'll pick the last one. But current vk.xml file doesn't have an instance with more than one.
                        result = paramenumsize.text
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

    def treat2dArrayAs1dArray(self):
        return False

    def hasExtendedTypeMemberName(self):
        return True

    def checkExtendedStructForHandles(self, typename):
        """Determines if the specified struct type can reference next extension structs that contain handles."""
        has_handles = False
        has_handle_ptrs = False
        return has_handles, has_handle_ptrs

    def checkStructMemberStructForHandles(self, value, structs_with_handles):
        """Determines if a struct member which is also a structure contains handles"""
        has_handles = value.base_type in structs_with_handles
        has_handle_pointer = False
        handles_list = []
        if has_handles:
            handles_list = structs_with_handles[value.base_type]
        return has_handles, has_handle_pointer, handles_list

    def isApiBaseType(self, typename):
        if (
            (self.getBaseInStructureName() == typename)
            or (self.getBaseOutStructureName() == typename)
        ):
            return True
        return False

    def check_struct_member_handles(
        self,
        typename,
        structs_with_handles,
        structs_with_handle_ptrs=None,
        ignore_output=False,
        extra_types=None,
        struct_members=None,
        print_this=False
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
                if (
                    not self.is_platform_struct(value.base_type)
                    and not (self.isApiBaseType(value.base_type))
                ):
                    self.check_struct_member_handles(
                        value.base_type, structs_with_handles,
                        structs_with_handle_ptrs, ignore_output, extra_types,
                        None, True
                    )
                has_handles, has_handle_ptrs, handle_list = self.checkStructMemberStructForHandles(
                    value, structs_with_handles
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
            elif (self.getExtendedTypeMemberName() == value.name):
                # The next chain may include a struct with handles.
                has_next_handles, has_next_handle_ptrs = self.checkExtendedStructForHandles(
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

    def getStructTypeMemberName(self):
        return ''

    def updateStructureTypePrefix(self, type):
        return type

    def generateStructureTypeFromStructName(self, name):
        if name in self.struct_enum_value:
            return self.struct_enum_value[name]

        type_name = name
        type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', type_name)
        type = type.upper()
        type = type.replace('D3_D12', 'D3D12')
        type = type.replace('_OPEN_GLES', '_OPENGL_ES_')
        type = type.replace('_OPEN_GL', '_OPENGL_')
        type = type.replace('_D3_D11', '_D3D11')
        type = type.replace('_D3_D12', '_D3D12')
        type = type.replace('_EGL', '_EGL_')
        type = type.replace('Device_IDProp', 'Device_ID_Prop')
        return self.updateStructureTypePrefix(type)

    def makeStructureTypeEnum(self, typeinfo, typename):
        """Generate the StructureType enumeration value for the specified structure type."""
        members = typeinfo.elem.findall('.//member')

        for member in members:
            membername = noneStr(member.find('name').text)

            # We only care about structures with a type, which can be included in a next chain.
            if membername == self.getStructTypeMemberName():
                # Check for value in the XML element.
                values = member.attrib.get('values')

                if values:
                    self.struct_enum_value[typename] = values
                    return values
                else:
                    name = self.generateStructureTypeFromStructName(typename)
                    self.struct_enum_value[typename] = name
                    return name
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
        return 'Khronos'

    def get_prefix_from_type(self, handle_name):
        return 'Khronos'

    def get_wrapper_prefix_from_type(self):
        return 'khronos_wrappers'

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

    def structHasHandles(self, struct_name):
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
                    found_handles, found_handle_ptrs, temp_handles = self.structHasHandles(
                        member_type
                    )
                    handles.extend(temp_handles)
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
                        if base_type_type.text[2:] == '_DEFINE_ATOM':
                            found_atom = True
                        if base_type_type.text[2:] == '_DEFINE_OPAQUE_64':
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

    # Return true if the enum or 64 bit pseudo enum passed-in represents a set
    # of bitwise flags.
    # Note, all 64 bit pseudo-enums represent flags since the only reason to go to
    # 64 bits is to allow more than 32 flags to be represented.
    def is64BitFlags(self, flag_type):
        if (
            (
                flag_type in self.flags_types
                and self.flags_types[flag_type][2:] == 'Flags64'
            ) or (
                flag_type in self.flag_bits_types
                and self.flag_bits_types[flag_type][2:] == 'Flags64'
            )
        ):
            return True
        return False

    def isHasSpecificKeywordInType(self, value, key_word):
        if key_word in value.base_type:
            return True

        values = self.all_struct_members.get(value.base_type)
        if values:
            for value in values:
                return self.isHasSpecificKeywordInType(value, key_word)
        return False

    def getMapperObjectInfo(self, needs_ref=False):
        # Return object_table_prefix, map_type, base_type, and map_table
        return 'Common', 'Handle', 'handle', ''
