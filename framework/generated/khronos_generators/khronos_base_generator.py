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
from collections import OrderedDict
from copy import deepcopy
from generator import GeneratorOptions, OutputGenerator, noneStr, regSortFeatures

def write(*args, **kwargs):
    file = kwargs.pop('file', sys.stdout)
    end = kwargs.pop('end', '\n')
    file.write(' '.join(str(arg) for arg in args))
    file.write(end)

def make_re_string(list, default=None):
    """Turn a list of strings into a regexp string matching exactly those strings.
    From Khronos genvk.py
    """
    if (len(list) > 0) or (default is None):
        return '^(' + '|'.join(list) + ')$'
    else:
        return default


class ApiData():
    """ApiData - Class to store various Khronos API data.

    Members:
        api_name                    - The name of the API
        api_class_prefix            - The prefix to use for classes in this API
        wrapper_prefix              - The prefix used to wrap namespaces
        command_prefix              - The prefix used to identify commands belonging to this Khronos API
        type_prefix                 - The prefix used to identify types belonging to this Khronos API
        struct_type_enum            - The enum type used to define structure types for this Khronos API
        struct_type_prefix          - The prefix used in the enum to identify the structure type enum value
        struct_type_variable        - The variable name used to identify structure types for this Khronos API
        struct_type_func_prefix     - The function prefix to use for structure type related functoins for this Khronos API
        base_in_struct              - The base input structure defined in this Khronos API
        base_out_struct             - The base output structure defined in this Khronos API
        extended_struct_variable    - The extended struct varible name used in this Khronos API
        extended_struct_func_prefix - The function prefix to use for extended struct functions for this Khronos API.
        boolean_type                - The type used by the API for booleans
        flags_type                  - The type used for general flags in the API
        flags_64_type               - The type used for 64-bit flags in the API
        return_const_ptr_on_extended- Return a constant on extended pointer types
        supports_handles            - This API supports Handles
        handle_func_name_mod        - The name used to indicate a function is processing handles
        supports_atoms              - This API supports Atoms as a type
        atom_func_name_mod          - The name used to indicate a function is processing atoms
        supports_opaques            - This API supports Opaques as a type
        opaque_func_name_mod        - The name used to indicate a function is processing opaque
    """
    def __init__(
            self,
            api_name,
            api_class_prefix,
            wrapper_prefix,
            command_prefix,
            type_prefix,
            struct_type_enum,
            struct_type_prefix,
            struct_type_variable,
            struct_type_func_prefix,
            base_in_struct,
            base_out_struct,
            extended_struct_variable,
            extended_struct_func_prefix,
            boolean_type,
            flags_type,
            flags_64_type,
            return_const_ptr_on_extended,
            supports_handles,
            handle_func_name_mod,
            supports_atoms,
            atom_func_name_mod,
            supports_opaques,
            opaque_func_name_mod,
    ):
        self.api_name = api_name
        self.api_class_prefix = api_class_prefix
        self.wrapper_prefix = wrapper_prefix
        self.command_prefix = command_prefix
        self.struct_type_enum = struct_type_enum
        self.type_prefix = type_prefix
        self.struct_type_prefix = struct_type_prefix
        self.struct_type_variable = struct_type_variable
        self.struct_type_func_prefix = struct_type_func_prefix
        self.base_in_struct = base_in_struct
        self.base_out_struct = base_out_struct
        self.extended_struct_variable = extended_struct_variable
        self.extended_struct_func_prefix = extended_struct_func_prefix
        self.boolean_type = boolean_type
        self.flags_type = flags_type
        self.flags_64_type = flags_64_type
        self.return_const_ptr_on_extended = return_const_ptr_on_extended
        self.supports_handles = supports_handles
        self.handle_func_name_mod = handle_func_name_mod
        self.supports_atoms = supports_atoms
        self.atom_func_name_mod = atom_func_name_mod
        self.supports_opaques = supports_opaques
        self.opaque_func_name_mod  = opaque_func_name_mod

class ValueInfo():
    """ValueInfo - Class to store parameter/struct member information.
    Contains information descripting Khronos API call parameters and struct members.

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
      bitfield_width -
      is_pointer - True if the value is a pointer.
      is_optional - True if the value is optional
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
        is_optional=False,
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
        self.is_optional = is_optional
        self.is_array = True if array_length else False
        self.is_dynamic = True if not array_capacity else False
        self.is_const = is_const
        self.is_com_outptr = is_com_outptr



class KhronosBaseGeneratorOptions(GeneratorOptions):
    """KhronosBaseGeneratorOptions - subclass of GeneratorOptions.
    Options for Khronos API parameter encoding and decoding C++ code generation.

    Adds options used by FrameworkGenerator objects during C++ language
    code generation.

    Additional members
      blacklists - Path to JSON file listing apicalls and structs to ignore.
      platform_types - Path to JSON file listing platform (WIN32, X11, etc.)
        specific types that are defined outside of the Khronos API header.

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
        emit_versions=None,
        default_extensions=None,
        add_extensions=None,
        remove_extensions=None,
        emit_extensions=None,
        extra_headers=[]
    ):
        GeneratorOptions.__init__(
            self,
            conventions=conventions,
            filename=filename,
            directory=directory,
            apiname=apiname,
            profile=profile,
            versions=versions,
            emitversions=emit_versions,
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
        self.extra_headers = extra_headers


class KhronosBaseGenerator(OutputGenerator):
    """KhronosBaseGenerator - subclass of OutputGenerator.
    Base class providing common operations used to generate C++-language code for framework
      components that encode and decode Khronos API parameters.
    Base class for Khronos API parameter encoding and decoding generators.
    """

    def __init__(
        self,
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

        # These structures should be ignored for handle mapping/unwrapping. They require special implementations.
        self.STRUCT_MAPPERS_BLACKLIST = []

        # Platform specific basic types that have been defined externally from the current API's headers
        self.PLATFORM_TYPES = {}

        # Platform specific structure types that have been defined extarnally to the current API's headers
        self.PLATFORM_STRUCTS = []

        self.GENERIC_HANDLE_APICALLS = {}

        self.MAP_STRUCT_TYPE = {}
        self.GENERIC_HANDLE_APICALLS = {}
        self.GENERIC_HANDLE_STRUCTS = {}

        self.REPLACE_TYPE = {}

        # These types represent pointers to non-Khronos objects that were written as 64-bit address IDs.
        self.EXTERNAL_OBJECT_TYPES = ['void', 'Void']
        self.MANUALLY_GENERATED_COMMANDS = []
        self.SKIP_COMMANDS = []

        # The list of supported subsets
        self.SUPPORTED_SUBSETS = []

        # Default C++ code indentation size.
        self.INDENT_SIZE = 4

        # Typenames
        self.base_types = dict()  # Set of current API's basetypes
        self.union_names = set()  # Set of current API's union typenames
        self.handle_names = set()  # Set of current API's handle typenames
        self.handle_aliases = dict() # Map of hanlde aliases
        self.dispatchable_handle_names = set()  # Set of current API's dispatchable handle typenames
        self.flags_types = dict()  # Map of flags types
        self.flags_type_aliases = dict()  # Map of flags type aliases
        self.flags_to_enum_bits = dict() # Map of flags to enum bits
        self.enum_bits_to_flag = dict() # Map of enum bits to flag type
        self.enum_names = set()  # Set of current API's  enumeration typenames
        self.enumAliases = dict()  # Map of enum names to aliases
        self.enumEnumerants = dict()  # Map of enum names to enumerants

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

        # Command parameter and struct member data for the current feature
        self.struct_names = set()                              # Set of current API's struct typenames
        self.struct_type_names = OrderedDict()                 # Map of current API's struct type enums
        self.all_extended_structs = dict()                     # Map of all extended struct names
        self.feature_extended_structs = dict()                 # Map of per-feature extended struct names
        self.children_structs = dict()                         # Map of children struct names to lists of child struct names
        self.all_struct_members = OrderedDict()                # Map of struct names to lists of per-member ValueInfo
        self.feature_struct_members = OrderedDict()            # Map of per-feature struct names to lists of per-member ValueInfo
        self.all_struct_aliases = OrderedDict()                # Map of struct names to aliases
        self.feature_struct_aliases = OrderedDict()            # Map of per-feature struct names to aliases
        self.all_union_members = OrderedDict()                 # Map of union names to lists of per-member ValueInfo
        self.feature_union_members = OrderedDict()             # Map of per-feature union names to lists of per-member ValueInfo
        self.all_union_aliases = OrderedDict()                 # Map of union names to aliases
        self.feature_union_aliases = OrderedDict()             # Map of per-feature union names to aliases
        self.extension_structs_with_handles = OrderedDict()     # Map of extension struct names to a Boolean value indicating that a struct member has a handle type
        self.extension_structs_with_handle_ptrs = OrderedDict()  # Map of extension struct names to a Boolean value indicating that a struct member with a handle type is a pointer

        self.all_cmd_params = OrderedDict()                    # Map of cmd names to lists of per-parameter ValueInfo
        self.feature_cmd_params = OrderedDict()                # Map of cmd names to lists of per-parameter ValueInfo

        self.structs_with_handles = OrderedDict(
        )  # Map of structures with handles
        self.structs_with_handle_ptrs = set(
        )  # Set of structures with handles

        self.atom_names = set()  # Set of current API's Atom typenames
        self.opaque_names = set()  # Set of current API's Opaque typenames

        # Data for every supported Khronos API
        # TODO: Eventually, we should move this info into a data file that we read (JSON?)
        self.valid_khronos_supported_api_data = []
        self.valid_khronos_supported_api_data.append(
            ApiData(
                api_name='Vulkan',
                api_class_prefix='Vulkan',
                wrapper_prefix='vulkan_wrappers',
                command_prefix='vk',
                struct_type_enum='VkStructureType',
                type_prefix='Vk',
                struct_type_prefix='VK_STRUCTURE_TYPE_',
                struct_type_variable='sType',
                struct_type_func_prefix='SType',
                base_in_struct='VkBaseInStructure',
                base_out_struct='VkBaseOutStructure',
                extended_struct_variable='pNext',
                extended_struct_func_prefix='PNext',
                boolean_type='VkBool32',
                flags_type='VkFlags',
                flags_64_type='VkFlags64',
                return_const_ptr_on_extended=True,
                supports_handles=True,
                handle_func_name_mod='Handle',
                supports_atoms=False,
                atom_func_name_mod='',
                supports_opaques=False,
                opaque_func_name_mod=''
            )
        )
        self.valid_khronos_supported_api_data.append(
            ApiData(
                api_name='OpenXR',
                api_class_prefix='OpenXr',
                wrapper_prefix='openxr_wrappers',
                command_prefix='xr',
                struct_type_enum='XrStructureType',
                type_prefix='Xr',
                struct_type_prefix='XR_TYPE_',
                struct_type_variable='type',
                struct_type_func_prefix='Type',
                base_in_struct='XrBaseInStructure',
                base_out_struct='XrBaseOutStructure',
                extended_struct_variable='next',
                extended_struct_func_prefix='Next',
                boolean_type='XrBool32',
                flags_type='',
                flags_64_type='XrFlags64',
                return_const_ptr_on_extended=False,
                supports_handles=True,
                handle_func_name_mod='Handle',
                supports_atoms=True,
                atom_func_name_mod='Atom',
                supports_opaques=True,
                opaque_func_name_mod='Opaque'
            )
        )

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
            platform_types.update(self.REPLACE_TYPE)

            for type in platform_types:
                self.PLATFORM_TYPES[type] = platform_types[type]

            platform_structs = platform['structs']
            if platform_structs:
                self.PLATFORM_STRUCTS += platform_structs

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

    def include_extra_headers(self, gen_opts):
        """Write extra header include statements
        """
        for extra_header in gen_opts.extra_headers:
            header_include_path = re.sub(r'\\', '/', extra_header)
            write(f'#include "{header_include_path}"', file=self.outFile)

    def endFile(self):
        """Method override."""

        # Finish C++ wrapper and multiple inclusion protection
        if (self.genOpts.protect_file and self.genOpts.filename):
            self.newline()
            write('#endif', file=self.outFile)

        # Finish processing in superclass
        OutputGenerator.endFile(self)

    def get_feature_protect(self, interface):
        """Intended to be overridden."""
        return None

    #
    # Indicates that the current feature has C++ code to generate.
    # The subclass should override this method.
    def need_feature_generation(self):
        """Intended to be overridden.  Indicates that the current feature has C++ code to generate.
        The subclass should override this method."""
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature.
        The subclass should override this method."""

    def beginFeature(self, interface, emit):
        """Method override. Start processing in superclass."""
        OutputGenerator.beginFeature(self, interface, emit)

        # Reset feature specific data sets
        self.feature_struct_members = OrderedDict()
        self.feature_struct_aliases = OrderedDict()
        self.feature_cmd_params = OrderedDict()
        self.feature_extended_structs = dict()

        # Some generation cases require that extra feature protection be suppressed
        if self.genOpts.protect_feature:
            self.featureExtraProtect = self.get_feature_protect(interface)

    def endFeature(self):
        """Method override. Generate code for the feature."""
        if self.emit and self.need_feature_generation():
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

    def is_resource_dump_class(self):
        return True if ('ReplayDumpResources' in self.__class__.__name__) else False

    def is_dump_resources_api_call(self, call_name):
        return False

    def is_struct(self, base_type):
        """Check for struct type."""
        if (
            (base_type in self.struct_names)
            or (base_type in self.PLATFORM_STRUCTS)
        ):
            return True

    def is_handle(self, base_type):
        """Check if handle.  The subclass may override this method."""
        if base_type in self.handle_names:
            return True
        return False

    def is_atom(self, base_type):
        for api_data in self.valid_khronos_supported_api_data:
            if (api_data.supports_atoms and
                base_type.startswith(api_data.type_prefix) and
                base_type == self.atom_names):
                return True
        return False

    def is_opaque(self, base_type):
        for api_data in self.valid_khronos_supported_api_data:
            if (api_data.supports_opaques and
                base_type == api_data.type_prefix and
                base_type == self.opaque_names):
                return True
        return False

    def is_handle_like(self, base_type):
        if (self.is_handle(base_type) or
            self.is_atom(base_type) or
            self.is_opaque(base_type)):
            return True
        return False

    def get_handle_func_name_modifier(self, base_type):
        for api_data in self.valid_khronos_supported_api_data:
            if (api_data.supports_handles and
                base_type.startswith(api_data.type_prefix) and
                (base_type in self.handle_names or base_type in self.structs_with_handles)):
                return api_data.handle_func_name_mod
        return ''

    def get_atom_func_name_modifier(self, base_type):
        for api_data in self.valid_khronos_supported_api_data:
            if (api_data.supports_atoms and
                base_type.startswith(api_data.type_prefix) and
                base_type in self.atom_names):
                return api_data.atom_func_name_mod
        return ''

    def get_opaque_func_name_modifier(self, base_type):
        for api_data in self.valid_khronos_supported_api_data:
            if (api_data.supports_opaques and
                base_type.startswith(api_data.type_prefix) and
                base_type in self.opaque_names):
                return api_data.opaque_func_name_mod
        return ''

    def get_handle_like_func_name_modifier(self, base_type):
        if (self.is_handle(base_type) or base_type in self.structs_with_handles):
            return self.get_handle_func_name_modifier(base_type)
        if (self.is_atom(base_type)):
            return self.get_atom_func_name_modifier(base_type)
        if (self.is_opaque(base_type)):
            return self.get_opaque_func_name_modifier(base_type)
        return ''

    def get_default_handle_atom_value(self, base_type):
        return '0'

    def has_basetype(self, base_type):
        if base_type in self.base_types and self.base_types[base_type] is not None:
            return True
        return False

    def get_basetype(self, base_type):
        return self.base_types[base_type]

    def is_dispatchable_handle(self, base_type):
        """Check for dispatchable handle type."""
        if base_type in self.dispatchable_handle_names:
            return True
        return False

    def is_enum(self, base_type):
        """Check for enum type."""
        if base_type in self.enum_names:
            return True
        return False

    def is_union(self, value):
        """Check for union type.  The subclass may override this method."""
        return False

    def is_flags(self, base_type):
        """Check for flags (bitmask) type."""
        if base_type in self.flags_types:
            return True
        return False

    # Return true if the type passed in is used to hold a set of bitwise flags
    # that is 64 bits wide.
    def is_64bit_flags(self, flag_type):
        if flag_type in self.flags_types:
            for api_data in self.valid_khronos_supported_api_data:
                if (flag_type.startswith(api_data.type_prefix) and
                    self.flags_types[flag_type] == api_data.flags_64_type):
                    return True
        return False

    # Return true if the enum or 64 bit pseudo enum passed-in represents a set
    # of bitwise flags.
    # Note, all 64 bit pseudo-enums represent flags since the only reason to go to
    # 64 bits is to allow more than 32 flags to be represented.
    def is_flags_enum_64bit(self, enum):
        flag_type = self.get_flags_type_from_enum(enum)
        return self.is_64bit_flags(flag_type)

    def get_flags_type_from_enum(self, enum):
        if enum in self.enum_bits_to_flag:
            return self.enum_bits_to_flag[enum]

        # If we don't already have one picked out, determine it
        result = enum.find('FlagBits')

        # If we have a FlagBits type, strip off that, and save the extension
        if result > 0:
            trimmed_enum = enum[:result + 4]
            extension = enum[result + 8:]

            # Add an s toe the type plus add back any extension
            flag_type = trimmed_enum + 's' + extension

            if flag_type in self.flags_types:
                if flag_type not in self.enum_bits_to_flag:
                    self.enum_bits_to_flag[enum] = flag_type
                if flag_type not in self.flags_to_enum_bits:
                    self.flags_to_enum_bits[flag_type] = enum

            return flag_type
        else:
            return None

    def get_enum_from_flags_type(self, flag):
        if flag in self.flags_to_enum_bits:
            return self.flags_to_enum_bits[flag]

        enum = re.sub('FlagBit', '', flag)
        if enum in self.enum_names:
            return enum
        else:
            return None

    def is_has_specific_key_word_in_type(self, value, key_word):
        if key_word in value.base_type:
            return True

        values = self.feature_struct_members.get(value.base_type)
        if values:
            for value in values:
                return self.is_has_specific_key_word_in_type(value, key_word)
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
            # Khronos APIs seems to follow a pattern where input pointers will be const and output pointers will not be const.
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
                    if (paramname.tail is not None) and ('[' in paramname.tail):
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
                            result +=', '
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

    def get_all_filtered_struct_names(self):
        """Retrieves a filtered list of keys from self.all_struct_memebers with blacklisted items removed."""
        return [
            key for key in self.all_struct_members
            if not self.is_struct_black_listed(key)
        ]

    def get_filtered_struct_names(self):
        """Retrieves a filtered list of keys from self.feature_struct_memebers with blacklisted items removed."""
        return [
            key for key in self.feature_struct_members
            if not self.is_struct_black_listed(key)
        ]

    def get_all_filtered_cmd_names(self):
        """Retrieves a filtered list of keys from self.all_cmd_params with blacklisted items removed."""
        return [
            key for key in self.all_cmd_params
            if not self.is_cmd_black_listed(key)
        ]

    def get_filtered_cmd_names(self):
        """Retrieves a filtered list of keys from self.feature_cmd_params with blacklisted items removed."""
        return [
            key for key in self.feature_cmd_params
            if not self.is_cmd_black_listed(key)
        ]

    def is_manually_generated_cmd_name(self, command):
        """Determines if a command is in the list of manually generated command names."""
        if self.MANUALLY_GENERATED_COMMANDS is not None and command in self.MANUALLY_GENERATED_COMMANDS:
           return True
        return False

    def clean_type_define(self, full_type):
        """Default to identity function, base classes may override."""
        return full_type

    def get_generic_struct_handle_type_value(self, struct_name, member_name):
        """For a struct member that contains a generic handle value, retrieve the struct member
        containing an enum value defining the specific handle type.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type.
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
        type.
        """
        if cmd_name in self.GENERIC_HANDLE_APICALLS:
            cmd_entry = self.GENERIC_HANDLE_APICALLS[cmd_name]
            if param_name in cmd_entry:
                return cmd_entry[param_name]
        return None

    def is_generic_struct_handle_value(self, struct_name, member_name):
        """Determine if a struct member contains a generic handle value.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type.
        """
        if self.get_generic_struct_handle_type_value(struct_name, member_name):
            return True
        return False

    def is_generic_cmd_handle_value(self, cmd_name, param_name):
        """Determine if an API call parameter contains a generic handle value.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type.
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
            return self.get_api_prefix() + 'Handle'
        elif self.is_flags(base_type):
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

    def check_remaining_base_types(self, name, type_info):
        self.base_types[name] = type_info

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
            else:
                self.union_names.add(name)
                self.genUnion(typeinfo, name, alias)
        elif (category == 'handle'):
            self.handle_names.add(name)
            if (
                type_elem is not None and type_elem.find('type') is not None
                and '_DEFINE_HANDLE' == type_elem.find('type').text[2:]
            ):
                self.dispatchable_handle_names.add(name)

            # Flags can have either VkFlags or VkFlags64 base type
            alias = type_elem.get('alias')
            if alias:
                self.handle_aliases[name] = alias
        elif (category == 'bitmask'):
            # Flags can have either VkFlags or VkFlags64 base type
            alias = type_elem.get('alias')
            if alias:
                # Use same base type as the alias if one exists
                self.flags_types[name] = self.flags_types[alias]
                self.flags_type_aliases[name] = alias
            else:
                # Otherwise, look for base type inside type declaration
                self.flags_types[name] = type_elem.find('type').text

                bittype = type_elem.get('requires')
                if bittype is None:
                    bittype = type_elem.get('bitvalues')
                if bittype is not None:
                    if bittype in self.enumAliases:
                        bittype = self.enumAliases[bittype]
                    self.flags_to_enum_bits[name] = bittype
                    self.enum_bits_to_flag[bittype] = name

        elif (
            (category == "basetype") and (
                type_elem.find('type') is not None
                and type_elem.find('type').text is not None
            )
        ):
            self.check_remaining_base_types(name, type_elem.find('type').text)

    def genStruct(self, typeinfo, typename, alias):
        """Method override.
        Struct (e.g. C "struct" type) generation.
        This is a special case of the <type> tag where the contents are
        interpreted as a set of <member> tags instead of freeform C
        C type declarations. The <member> tags are just like <param>
        tags - they are a declaration of a struct or union member.
        """
        OutputGenerator.genStruct(self, typeinfo, typename, alias)
        self.process_struct(typeinfo.elem, typename, alias)

    def bubble_up_struct_has_handles(self, typename):
        """Bubble up the struct_has_handles information to
        every structure that may contain this structure.
        This is needed because sometimes we read a containing
        structure before we read the structure itself, or
        we read a structure before we read the set of
        extending structures which may include handles.
        So we need to go back and update the previously
        read structures which may have contained references
        to the containing structure."""
        # Only continue if we're supposed to process this struct
        if (
            self.is_struct_black_listed(typename)
            or self.is_base_input_structure_type(typename)
            or self.is_base_output_structure_type(typename)
        ):
            return

        for struct in self.all_struct_members:
            # If it's already listed as having a handle, just skip
            if struct in self.structs_with_handles:
                continue
            for member in self.all_struct_members[struct]:
                if member.base_type == typename:
                    self.structs_with_handles[struct] = [member]
                    if (
                        struct not in self.structs_with_handle_ptrs
                        and (member.is_pointer or member.is_array)
                    ):
                        self.structs_with_handle_ptrs.add(struct)

                    self.bubble_up_struct_has_handles(struct)

                    # Check to see if this is a child and update
                    # the parent's handle status if so.
                    for parent in self.children_structs.keys():
                        if member.base_type in self.children_structs[parent]:
                            self.gen_set_parent_has_handles(parent)

    def gen_set_parent_has_handles(self, parent):
        """If a child structure has a handle, we need to update
        the parent to indicate that it to now has a handle."""
        # If it's already listed as having a handle, just skip
        if (
            parent in self.structs_with_handles
            or self.is_struct_black_listed(parent)
            or self.is_base_input_structure_type(parent)
            or self.is_base_output_structure_type(parent)
        ):
            return

        if (parent in self.children_structs.keys()):
            # See if any of the children structures have handles
            for child in self.children_structs[parent]:
                if child in self.structs_with_handles:
                    self.structs_with_handles[parent] = [child]
                    self.bubble_up_struct_has_handles(parent)
                    if parent not in self.structs_with_handle_ptrs:
                        self.structs_with_handle_ptrs.add(parent)

    def process_struct(self, element, typename, alias):
        # For structs, we ignore the alias because it is a typedef.  Not ignoring the alias
        # would produce multiple definition errors for functions with struct parameters.
        if not alias:
            members = element.findall('.//member')
            self.add_struct_members(typename, self.make_value_info(members))

            handles = []
            has_handle_pointers = False
            for count in range(0, len(self.all_struct_members[typename])):
                current_xml_member = members[count]
                current_struct_member = self.all_struct_members[typename][count
                                                                          ]

                # If this structure has a type field, add it to the list
                # of structure types
                if (
                    current_struct_member.base_type
                    == self.get_struct_type_enum_name() and
                    current_struct_member.name == self.get_struct_type_var_name()
                ):

                    # Check for value in the XML element.
                    values = current_xml_member.attrib.get('values')
                    if values:
                        self.struct_type_names[typename] = values
                    elif (
                        not self.is_base_input_structure_type(typename)
                        and not self.is_base_output_structure_type(typename)
                    ):
                        self.struct_type_names[
                            typename] = self.generate_structure_type(typename)

                # If this is the extnded struct member, and we already have this structure
                # in the list of handled structs, it means one of the structs that extends
                # this one has a handle.  So add it to the handle list
                if (
                    current_struct_member.name
                    == self.get_extended_struct_var_name()
                    and typename in self.all_extended_structs
                ):

                    for extended_struct in self.all_extended_structs[typename]:
                        if extended_struct in self.structs_with_handles:
                            handles.append(deepcopy(current_struct_member))
                            break

                # If this member is a handle, of course we have handles in this struct
                elif self.is_handle(current_struct_member.base_type):
                    handles.append(deepcopy(current_struct_member))
                    if current_struct_member.is_pointer or current_struct_member.is_array:
                        has_handle_pointers = True

                # If the struct is one we already know about and it has handles, record that
                elif self.is_struct(current_struct_member.base_type):
                    if current_struct_member.base_type in self.structs_with_handles:
                        handles.append(deepcopy(current_struct_member))
                        if current_struct_member.base_type in self.structs_with_handle_ptrs:
                            has_handle_pointers = True

                elif (
                    current_struct_member.base_type
                    in self.children_structs.keys()
                ):
                    # See if any of the children structures have handles
                    for child in self.children_structs[
                        current_struct_member.base_type]:
                        if child in self.structs_with_handles:
                            handles.append(deepcopy(current_struct_member))
                            break

            if len(handles) > 0:
                if typename in self.structs_with_handles:
                    for handle in handles:
                        # Only add the handles if it is not already listed in the
                        # list of structure handles
                        if typename not in self.structs_with_handles[
                            typename]:
                            self.structs_with_handles[typename].append(
                                handle
                            )
                else:
                    self.structs_with_handles[typename] = handles
                self.bubble_up_struct_has_handles(typename)

            # If this struct has a parent name, keep track of all
            # the parents and their children
            parent_name = element.get('parentstruct')
            if parent_name:
                # If it doesn't already appear in the list of parents,
                # add an entry for it.
                if parent_name not in self.children_structs.keys():
                    self.children_structs[parent_name] = []
                self.children_structs[parent_name].append(typename)

                # If this has handles, but the parent is already present
                # and not listed as having handles, update the parent
                if len(handles) > 0:
                    self.gen_set_parent_has_handles(parent_name)

            # If this struct extends another struct, save that info
            extended_struct = element.get('structextends')
            if extended_struct:
                extended_struct_list = []
                if ',' in extended_struct:
                    extended_struct_list = extended_struct.split(",")
                else:
                    extended_struct_list.append(extended_struct)
                for ext_struct in extended_struct_list:
                    self.add_extended_structs(ext_struct, typename)

                # If this struct has handles, check the extended struct (or structs) and set
                # their extended struct field to having handles.
                if len(handles) > 0:
                    for ext_struct in extended_struct_list:
                        if ext_struct in self.all_struct_members:
                            for member in self.all_struct_members[ext_struct]:
                                if member.name == self.get_extended_struct_var_name(
                                ):
                                    # If the extended struct already has handles, then just
                                    # append the extended struct field name to the
                                    # existing list if it's not already there
                                    found = False
                                    if ext_struct in self.structs_with_handles:
                                        for check_handle in self.structs_with_handles[
                                            ext_struct]:
                                            if check_handle.name == member.name:
                                                found = True
                                                break
                                    if not found:
                                        if ext_struct in self.structs_with_handles:
                                            # If this member is not in the list of struct handles,
                                            # add it to the list and put it at the beginning
                                            if member not in self.structs_with_handles[
                                                ext_struct]:
                                                self.structs_with_handles[
                                                    ext_struct].extend(
                                                        [member]
                                                    )
                                                self.structs_with_handles[
                                                    ext_struct
                                                ].insert(
                                                    0, self.structs_with_handles[
                                                        ext_struct].
                                                    pop(
                                                        self.structs_with_handles[
                                                            ext_struct].
                                                        index(member)
                                                    )
                                                )
                                        else:
                                            self.structs_with_handles[
                                                ext_struct] = [member]
                                        has_handle_pointers = True
                                        self.bubble_up_struct_has_handles(
                                            ext_struct
                                        )
                                    break

            if has_handle_pointers and typename not in self.structs_with_handle_ptrs:
                self.structs_with_handle_ptrs.add(typename)

        else:
            self.add_struct_alias(typename, alias)

    def add_extended_structs(self, name, extended):
        if name in self.all_extended_structs:
            self.all_extended_structs[name].append(extended)
        else:
            new_list = [extended]
            self.all_extended_structs[name] = new_list

        if name in self.feature_extended_structs:
            self.feature_extended_structs[name].append(extended)
        else:
            new_list = [extended]
            self.feature_extended_structs[name] = new_list

    def add_struct_alias(self, name, alias):
        self.all_struct_aliases[name] = alias
        self.feature_struct_aliases[name] = alias

    def add_struct_members(self, name, value_info):
        self.all_struct_members[name] = value_info
        self.feature_struct_members[name] = value_info

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
        if not alias:
            if typename not in self.feature_union_members:
                self.add_union_members(typename, self.make_value_info(
                    typeinfo.elem.findall('.//member')
                ))
        else:
            if typename not in self.all_union_aliases:
                self.add_union_alias(typename, alias)

    def add_union_alias(self, name, alias):
        self.all_union_aliases[name] = alias
        self.feature_union_aliases[name] = alias

    def add_union_members(self, name, value_info):
        self.all_union_members[name] = value_info
        self.feature_union_members[name] = value_info

    def genGroup(self, groupinfo, group_name, alias):
        """Method override.
        Group (e.g. C "enum" type) generation.
        These are concatenated together with other types.
        """
        OutputGenerator.genGroup(self, groupinfo, group_name, alias)
        if group_name not in self.enum_names:
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
                            if e in self.SUPPORTED_SUBSETS:
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

        # Create the declaration for the function prototype
        proto = cmdinfo.elem.find('proto')
        proto_decl = self.genOpts.apicall + noneStr(proto.text)
        for elem in proto:
            text = noneStr(elem.text)
            tail = noneStr(elem.tail)
            if (elem.tag == 'name'):
                if text.startswith('vk'):
                    text = text[2:]
                proto_decl += self.makeProtoName(text, tail)
            else:
                proto_decl += text + tail

        return_type = noneStr(proto.text
                                ) + noneStr(proto.find('type').text)

        self.add_command_params(name, return_type, proto_decl,
            self.make_value_info(cmdinfo.elem.findall('param')))

    def add_command_params(self, name, return_type, proto_decl, value_info):
        # TODO: Define a class or namedtuple for the dictionary entry
        self.all_cmd_params[name] = (return_type, proto_decl, value_info)
        self.feature_cmd_params[name] = (return_type, proto_decl, value_info)

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

            # Get array length for HandlesInfo structs e.g. VkPipelineBinaryHandlesInfoKHR
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

    def get_api_data(self):
        for api_data in self.valid_khronos_supported_api_data:
            if api_data.api_name.lower() == self.genOpts.apiname.lower():
                return api_data
        return None

    def is_base_input_structure_type(self, type):
        for api_data in self.valid_khronos_supported_api_data:
            if (type.startswith(api_data.type_prefix) and
                type == api_data.base_in_struct):
                return True
        return False

    def is_base_output_structure_type(self, type):
        for api_data in self.valid_khronos_supported_api_data:
            if (type.startswith(api_data.type_prefix) and
                type == api_data.base_out_struct):
                return True
        return False

    def is_boolean_type(self, type):
        for api_data in self.valid_khronos_supported_api_data:
            if (type == api_data.boolean_type):
                return True
        return False

    def get_base_input_structure_name(self):
        api_data = self.get_api_data()
        if api_data is not None:
            return api_data.base_in_struct
        return ''

    def get_base_output_structure_name(self):
        api_data = self.get_api_data()
        if api_data is not None:
            return api_data.base_out_struct
        return ''

    def get_struct_type_enum_name(self):
        api_data = self.get_api_data()
        if api_data is not None:
            return api_data.struct_type_enum
        return ''

    def get_struct_type_var_name(self):
        api_data = self.get_api_data()
        if api_data is not None:
            return api_data.struct_type_variable
        return ''

    def get_struct_type_func_prefix(self):
        api_data = self.get_api_data()
        if api_data is not None:
            return api_data.struct_type_func_prefix
        return ''

    def get_extended_struct_var_name(self):
        api_data = self.get_api_data()
        if api_data is not None:
            return api_data.extended_struct_variable
        return ''

    def get_extended_struct_func_prefix(self):
        api_data = self.get_api_data()
        if api_data is not None:
            return api_data.extended_struct_func_prefix
        return ''

    def get_wrapper_prefix(self):
        api_data = self.get_api_data()
        if api_data is not None:
            return api_data.wrapper_prefix
        return ''

    def get_wrapper_prefix_from_type(self, type):
        for api_data in self.valid_khronos_supported_api_data:
            if type.startswith(api_data.type_prefix):
                return api_data.wrapper_prefix
        return self.get_wrapper_prefix()

    def get_wrapper_prefix_from_command(self, cmd):
        for api_data in self.valid_khronos_supported_api_data:
            if cmd.startswith(api_data.command_prefix):
                return api_data.wrapper_prefix
        return self.get_wrapper_prefix()

    def get_api_prefix(self):
        api_data = self.get_api_data()
        if api_data is not None:
            return api_data.api_class_prefix
        return 'Khronos'

    def get_api_prefix_from_type(self, type):
        for api_data in self.valid_khronos_supported_api_data:
            if type.startswith(api_data.type_prefix):
                return api_data.api_class_prefix
        return self.get_api_prefix()

    def get_api_prefix_from_command(self, cmd):
        for api_data in self.valid_khronos_supported_api_data:
            if cmd.startswith(api_data.command_prefix):
                return api_data.api_class_prefix
        return self.get_api_prefix()

    def is_extended_struct_definition(self, value):
        if (value.name == self.get_extended_struct_var_name() and
            value.base_type == 'void' and
            value.is_pointer):
            return True
        return False

    def generate_structure_type(self, type_name):
        # Make the type all upper case
        upper_type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', type_name).upper()
        type_with_prefix = upper_type

        # Apply any structure type prefix first
        for api_data in self.valid_khronos_supported_api_data:
            upper_prefix = api_data.type_prefix.upper()
            if upper_type.startswith(upper_prefix):
                type_with_prefix = api_data.struct_type_prefix + upper_type

        type_with_prefix = type_with_prefix.replace('_OPEN_GLES', '_OPENGL_ES_')
        type_with_prefix = type_with_prefix.replace('_OPEN_GL', '_OPENGL_')
        type_with_prefix = type_with_prefix.replace('_D3_D11', '_D3D11')
        type_with_prefix = type_with_prefix.replace('_D3_D12', '_D3D12')
        type_with_prefix = type_with_prefix.replace('_EGL', '_EGL_')
        type_with_prefix = type_with_prefix.replace('Device_IDProp', 'Device_ID_Prop')
        return type_with_prefix

    def make_simple_var_name(self, type_name):
        lower_type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', type_name).lower()

        for api_data in self.valid_khronos_supported_api_data:
            lower_prefix = api_data.type_prefix.lower()
            if lower_type.startswith(lower_prefix):
                lower_prefix_len = len(lower_prefix)
                new_lower_type = lower_type[:lower_prefix_len - 1] + '_' + lower_type[lower_prefix_len - 1:]
                lower_type = new_lower_type

        return lower_type

    def write_includes_of_common_api_headers(self, gen_opts):
        """ Method intended to be overridden. """
        raise NotImplementedError

    def generate_child_struct_switch_statement(
        self, parent_struct, value, initial_indent, switch_expression,
        fn_emit_default, fn_emit_case
    ):
        """ Parent structs are abstract, need to case to specific child struct based on type """
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
            [indent3 + line for line in fn_emit_default(parent_struct, value)]
        )
        body += f'\n{indent2}}}\n'

        for child_struct in self.children_structs[parent_struct]:
            struct_type_name = self.struct_type_names[child_struct]
            body += f'{indent2}case {struct_type_name}:\n'
            body += f'{indent2}{{\n'
            body += '\n'.join(
                [
                    indent3 + line for line in fn_emit_case(
                        parent_struct, child_struct, struct_type_name, value
                    )
                ]
            )
            body += f'\n{indent2}}}\n'

        body += f'{indent1}}}\n'
        return body
