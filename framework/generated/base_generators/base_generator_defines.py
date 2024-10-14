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

import json, re, sys
from collections import OrderedDict


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


def remove_suffix(self: str, suffix: str, /) -> str:
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
def bits_enum_to_flags_typedef(enum):
    # if enum.endswith
    flags = remove_suffix(enum, 'Bits')
    if flags != enum:
        flags = flags + 's'
        return flags
    flags = remove_suffix(enum, 'Bits2')
    if flags != enum:
        flags = flags + 's2'
        return flags
    # Gods preserve us from Bits 3, 4, 5, etc.
    # It might have more extension suffix.
    flags = remove_suffix(enum, 'Bits2KHR')
    if flags != enum:
        flags = flags + 's2KHR'
        return flags
    return flags


class ValueInfo():
    """ValueInfo - Class to store parameter/struct member information.
    Contains information descripting Vulkan API call parameters and struct members.

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
      is_com_outptr - 
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


class BaseGeneratorDefines():

    def __init__(self):
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

        # Platform specific basic types that have been defined extarnally to the OpenXR header.
        self.PLATFORM_TYPES = {}
        self.PLATFORM_STRUCTS = []

        self.GENERIC_HANDLE_APICALLS = {}
        self.GENERIC_HANDLE_STRUCTS = {}

        self.REPLACE_TYPE = {}

        # These types represent pointers to non-OpenXR objects that were written as 64-bit address IDs.
        self.EXTERNAL_OBJECT_TYPES = ['void', 'Void']
        self.DISPATCHABLE_HANDLE_TYPES = []
        self.DUPLICATE_HANDLE_TYPES = []
        self.MANUALLY_GENERATED_COMMANDS = []
        self.SKIP_COMMANDS = []

        self.DUPLICATE_HANDLE_TYPES = []

        # Default C++ code indentation size.
        self.INDENT_SIZE = 4

        # Typenames
        self.base_types = dict()  # Set of basetypes
        self.cmd_names = list()  # Set of command names
        self.handle_names = set()  # Set of handle typenames
        self.dispatchable_handle_names = set(
        )  # Set of dispatchable handle typenames
        self.atom_names = set()  # Set of Atom typenames
        self.opaque_names = set()  # Set of Opaque typenames
        self.flags_types = dict()  # Map of flags types to base flag type
        self.flags_type_aliases = dict(
        )  # Map of flags type aliases to base flag type
        self.flag_enum_bits_type = dict()
        self.flag_bits_types = dict()
        self.bitfields_names = list()
        self.enum_names = set()  # Set of enumeration typenames
        self.enum_aliases = dict()  # Map of enum names to aliases
        self.enum_enumerants = dict()  # Map of enum names to enumerants
        self.extended_structs = dict()

        # List of structs containing handles that are also used as output parameters for a command
        self.output_structs_with_handles = []
        self.structs_with_handle_ptrs = []

        self.restrict_handles = True  # Determines if the 'is_handle' override limits the handle test to only the values conained by RESOURCE_HANDLE_TYPES.

        self.base_header_structs = dict(
        )  # Map of base header struct names to lists of child struct names

        # Map of typename to structure type for each struct that is not an alias
        self.struct_type_enums = dict()

        # Type processing options
        self.process_cmds = True  # Populate the feature_cmd_params map
        self.process_structs = True  # Populate the feature_struct_members map
        self.feature_break = False  # Insert a line break between features

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
        if self.process_structs:
            self.all_structs = list()  # List of all struct names
            self.all_struct_members = OrderedDict(
            )  # Map of all struct names to lists of per-member ValueInfo
            self.all_struct_aliases = OrderedDict(
            )  # Map of struct names to aliases
            self.all_unions = list()  # List of all union names
            self.all_union_members = OrderedDict(
            )  # Map of all union names to lists of per-member ValueInfo
            self.all_union_aliases = OrderedDict(
            )  # Map of union names to aliases
            self.feature_struct_members = OrderedDict(
            )  # Map of struct names to lists of per-member ValueInfo
            self.feature_struct_aliases = OrderedDict(
            )  # Map of struct names to aliases
            self.feature_union_members = OrderedDict(
            )  # Map of union names to lists of per-member ValueInfo
            self.feature_union_aliases = OrderedDict(
            )  # Map of union names to aliases
            self.output_structs = [
            ]  # Output structures that retrieve handles, which need to be wrapped.

        if self.process_cmds:
            self.all_cmd_params = OrderedDict(
            )  # Map of cmd names to lists of per-parameter ValueInfo
            self.feature_cmd_params = OrderedDict(
            )  # Map of cmd names to lists of per-parameter ValueInfo

        self.structs_with_map_data = None

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
        if gen_opts.blacklists:
            self.__load_blacklists(gen_opts.blacklists)
        if gen_opts.platform_types:
            self.__load_platform_types(gen_opts.platform_types)

            # Platform defined struct processing must be implemented manually,
            # so these structs will be added to the blacklist.
            self.STRUCT_BLACKLIST += self.PLATFORM_STRUCTS

    def beginFeature(self, interface, emit):
        # Reset feature specific data sets
        if self.process_structs:
            self.feature_struct_members = OrderedDict()
            self.feature_struct_aliases = OrderedDict()
            self.feature_union_members = OrderedDict()
            self.feature_union_aliases = OrderedDict()
        if self.process_cmds:
            self.feature_cmd_params = OrderedDict()

    #
    # Indicates that the current feature has C++ code to generate.
    # The subclass should override this method.
    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate.
        The subclass should override this method."""
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature.
        The subclass should override this method."""

    def is_dx12_class(self):
        return True if ('Dx12' in self.__class__.__name__) else False

    def is_openxr_class(self):
        return True if ('OpenXr' in self.__class__.__name__) else False

    def is_resource_dump_class(self):
        return True if (
            'ReplayDumpResources' in self.__class__.__name__
        ) else False

    def is_struct(self, base_type):
        """Check for struct type.  The subclass may override this method."""
        if (
            (base_type in self.all_structs)
            or (base_type in self.PLATFORM_STRUCTS)
        ):
            return True
        return False

    def is_platform_struct(self, base_type):
        """Check for struct type.  The subclass may override this method."""
        if (base_type in self.PLATFORM_STRUCTS):
            return True
        return False

    def is_parent_struct_type(self, base_type):
        return base_type in self.base_header_structs.keys()

    def is_enum(self, base_type):
        """Check for enum type.  The subclass may override this method."""
        if base_type in self.enum_names:
            return True
        return False

    def is_union(self, value):
        """Check for union type.  The subclass may override this method."""
        if value in self.all_unions:
            return True
        return False

    def is_class(self, value):
        """Check for class type.  The subclass may override this method."""
        return False

    def is_handle(self, base_type):
        """Check for handle type.  The subclass may override this method."""
        return False

    def is_dispatchable_handle(self, base_type):
        """Check for dispatchable type.  The subclass may override this method."""
        return False

    def is_valid_handle(self, base_type):
        """Check if this handle is valid for the current scenario.  The subclass may override this method."""
        return True

    def is_atom(self, base_type):
        """Check for atom type.  The subclass may override this method."""
        return False

    def is_opaque(self, base_type):
        """Check for opaque type.  The subclass may override this method."""
        return False

    def is_handle_like(self, base_type):
        """Check for handle type."""
        if self.is_handle(base_type) or self.is_atom(
            base_type
        ) or self.is_opaque(base_type):
            return True
        return False

    def has_basetype(self, base_type):
        """Determine if this type has a base type.  The subclass may override this method."""
        if base_type in self.base_types and self.base_types[base_type
                                                            ] is not None:
            return True
        return False

    def get_basetype(self, base_type):
        """Check for base type.  The subclass may override this method."""
        return self.base_types[base_type]

    def get_union_members(self, type):
        """Get union members.  The subclass may override this method."""
        if type in self.all_unions:
            return self.all_union_members[type]
        return None

    def is_flags(self, base_type):
        """Check for flags (bitmask) type."""
        if base_type in self.flags_types:
            return True
        return False

    def is_bittype(self, base_type):
        """Check for bittype (for flags) type."""
        if base_type in self.bitfields_names:
            return True
        return False

    def is_map_struct(self, base_type):
        if (
            (self.structs_with_map_data is not None)
            and (base_type is not None)
            and base_type in self.structs_with_map_data
            and base_type not in self.STRUCT_MAPPERS_BLACKLIST
        ):
            return True
        return False

    def is_function_ptr(self, base_type):
        """Check for function pointer type.  The subclass may override this method."""
        if (base_type[:4] == 'PFN_') or (base_type[-4:] == 'Func'):
            return True
        return False

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
        """Retrieves a filtered list of keys from self.feature_struct_memebers with blacklisted items removed."""
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

    def set_struct_members(self, typename, values):
        self.feature_struct_members[typename] = values
        self.all_struct_members[typename] = values

    def set_struct_aliases(self, typename, alias):
        self.feature_struct_aliases[typename] = alias
        self.all_struct_aliases[typename] = alias

    def set_union_members(self, typename, values):
        self.feature_union_members[typename] = values
        self.all_union_members[typename] = values

    def set_union_aliases(self, typename, alias):
        self.feature_union_aliases[typename] = alias
        self.all_union_aliases[typename] = alias

    def save_command_and_params(self, command, params):
        self.cmd_names.append(command)
        self.all_cmd_params[command] = params
        self.feature_cmd_params[command] = params

    def get_all_filtered_cmd_names(self):
        """Retrieves a filtered list of keys from self.feature_cmd_params with blacklisted items removed."""
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

    def generate_structure_type(self, type_name):
        upper_type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', type_name).upper()
        if upper_type.startswith('VK_'):
            type_with_prefix = re.sub('VK_', 'VK_STRUCTURE_TYPE_', upper_type)
        elif upper_type.startswith('XR_'):
            type_with_prefix = re.sub('XR_', 'XR_TYPE_', upper_type)
        if 'OPEN_GLES' in type_with_prefix:
            type_with_prefix = re.sub(
                'OPEN_GLES', 'OPENGL_ES_', type_with_prefix
            )
        elif 'OPEN_GL' in type_with_prefix:
            type_with_prefix = re.sub('OPEN_GL', 'OPENGL_', type_with_prefix)
        elif 'D3_D' in type_with_prefix:
            type_with_prefix = re.sub('D3_D', 'D3D', type_with_prefix)
        return type_with_prefix

    def make_simple_var_name(self, type_name):
        lower_type = re.sub('([a-z0-9])([A-Z])', r'\1_\2', type_name).lower()
        if lower_type.startswith('vk_'):
            lower_type = re.sub('vk_', '', lower_type)
        elif lower_type.startswith('xr_'):
            lower_type = re.sub('xr_', '', lower_type)
        return lower_type

    def clean_type_define(self, full_type):
        """Default to identity function, base classes may override."""
        return full_type

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
        elif self.is_parent_struct_type(value.base_type):
            return [f'{prefix}{length_exprs[0]}', '1']
        else:
            # XML does not provide lengths for all dimensions, instantiate a specialization of ArraySize2D to fetch the sizes
            type_list = ', '.join(
                [self.clean_type_define(v.full_type) for v in values]
            )
            arg_list = ', '.join([v.name for v in values])
            return ['ArraySize2D<{}>({})'.format(type_list, arg_list)]

    def make_decoded_param_type(
        self, value, allow_multi_dimen_struct_ptr=True
    ):
        """Create a type to use for a decoded parameter, using the decoder wrapper types for pointers."""
        type_name = value.base_type

        if self.process_structs and (
            self.is_struct(type_name) and type_name in self.all_struct_aliases
        ):
            type_name = self.all_struct_aliases[type_name]

        # For base header va
        # is_pointer will be False for static arrays.
        if value.is_pointer or value.is_array:
            count = value.pointer_count

            if self.is_struct(type_name):
                if count > 1 and allow_multi_dimen_struct_ptr:
                    type_name = 'StructPointerDecoder<Decoded_{}*>'.format(
                        type_name
                    )
                else:
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
                    # So, we specify uint64_t as the decode type and void* as the type to be used for Vulkan API call output parameters.
                    type_name = 'PointerDecoder<uint64_t, void*>'
                else:
                    # If this was a pointer to an unknown object (void*), it was encoded as a 64-bit address value.
                    type_name = 'uint64_t'
            elif self.is_handle_like(type_name):
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
        elif self.is_handle_like(type_name):
            type_name = 'format::HandleId'
        else:
            type_name = f'{type_name}'

        return type_name

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
        elif self.is_handle_like(base_type):
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
            if self.process_structs and (
                self.is_struct(type_name)
                and type_name in self.all_struct_aliases
            ):
                type_name = self.all_struct_aliases[type_name]

            if is_override:
                prefix_from_type = self.get_prefix_from_type(value.base_type)
                info_type = prefix_from_type + value.base_type[2:] + 'Info'
                if value.is_pointer or value.is_array:
                    count = value.pointer_count

                    if self.is_struct(type_name):
                        param_type = 'StructPointerDecoder<Decoded_{}>*'.format(
                            type_name
                        )
                    elif self.is_class(value):
                        if count == 1:
                            param_type = info_type + '*'
                        else:
                            param_type = 'HandlePointerDecoder<{}*>'.format(
                                type_name
                            )
                    elif self.is_handle(
                        type_name
                    ) and type_name != 'VkCommandBuffer':
                        param_type = 'HandlePointerDecoder<{}>*'.format(
                            type_name
                        )
                    else:
                        param_type = 'const ' + type_name + '*'
                else:
                    if self.is_handle(
                        type_name
                    ) and type_name != 'VkCommandBuffer':
                        param_type = "const " + info_type + '*'
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

    def hasExtendedTypeMemberName(self):
        return False

    def getExtendedTypeMemberName(self):
        return ''

    def getExtendedNodeType(self):
        return ''

    def getMapperObjectInfo(self, needs_ref=False):
        # Return object_table_prefix, map_type, base_type, and map_table
        return '', '', '', ''

    def needsObjectInfoTableOnArrayMap(self):
        return True

    def mapperNeedsValuePointerOnType(self, type):
        return (
            (
                self.is_handle(type.base_type) or self.is_atom(type.base_type)
                or self.is_opaque(type.base_type) or self.is_class(type)
            ) and not (type.is_array and not type.is_dynamic)
        )

    def decodeApiCallNonVoidReturnType(self, return_type, value_name):
        return '    {} return_value;\n'.format(return_type)

    def decodeInvokeNonVoidReturnApiCall(
        self, base_decoder_call, return_type, preamble, main_body, epilogue
    ):
        return base_decoder_call(
            self, ValueInfo('return_value', return_type, return_type),
            preamble, main_body, epilogue
        )

    def decodeAddApiSpecificArguments(self, name, return_type, arglist):
        if return_type and return_type != 'void':
            return ', '.join(['return_value', arglist])
        return arglist
