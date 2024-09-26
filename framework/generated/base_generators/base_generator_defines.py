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

from collections import OrderedDict
import json
import re


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

        self.structs_with_map_data = dict()

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

    def make_consumer_func_decl(self, return_type, name, values):
        """Default function that should be overwritten by actual implementation"""
        return

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
