#!/usr/bin/python3 -i
#
# Copyright (c) 2026 LunarG, Inc.
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
"""vulkan_schema_generator.py generates the Vulkan schema, and the generated inputs of its bindings, from vk.xml.

Every generator class below shares build_model, so every generated file is written from the same model and no file
owns a separate field order. One generator class writes each file:

    generated_vulkan_schema_types.h: the API elements and command API elements
    generated_vulkan_schema_fields.h: the Fields
    generated_vulkan_schema.h: the Schema specializations
    generated_vulkan_inventory.h: the inventory
    generated_vulkan_schema_api_struct_members.h, generated_vulkan_schema_decoded_struct_members.h and
    generated_vulkan_schema_decoded_command_members.h: the MemberPointer partitions, one per storage type
    generated_vulkan_schema_enumerants.h: the enumerant tables
    generated_vulkan_wire_types.h: the WireTypeOf specializations
    generated_vulkan_enum_to_string.cpp: the enum ToString definitions
    generated_vulkan_schema_checks.cpp: the static checks

Separate files, not one: each includer compiles only the part it needs. The schema proper is three files, each
including the one before: generated_vulkan_schema_types.h is what code that refers to an API element includes;
generated_vulkan_schema_fields.h is what the MemberPointer partitions include; generated_vulkan_schema.h is what the
field walk includes. Only the header that implements an operation includes the partitions it reads.

A platform typedef that platform_types.json substitutes, e.g. DWORD for uint32_t, keeps an API element of its own,
named and typed as the header spells it. The substituted type selects its category and its WireTypeOf
specialization; see add_platform_api_type.

A Field's declaration is its API element, or Const, Pointer, Array or FixedArray over a declaration, nested as the C
declarator nests. It is read from the registry's full type, so each level's const lands where the header wrote it.
"""

import json
import sys
from generator import noneStr
from khronos_base_generator import write
from khronos_struct_decoders_header_generator import KhronosStructDecodersHeaderGenerator
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions

class VulkanSchemaBaseGeneratorOptions(VulkanBaseGeneratorOptions):
    """Holds the options shared by every generated schema file but the inventory, whose options derive from
    VulkanBaseGeneratorOptions directly. Each subclass lists its file's headers in add_part_headers.
    """

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=False,
        extra_headers=[]
    ):
        VulkanBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
        )

        begin_end = self.begin_end_file_data

        self.add_part_headers(begin_end)

        # The Windows headers define CreateEvent and CreateSemaphore as macros, and both are command API element names
        # (the command name without its vk prefix). Every file these options generate undefines them, so an API
        # element spells the same in all of them on WIN32.
        begin_end.pre_namespace_code.extend((
            '#ifdef WIN32',
            '#ifdef CreateEvent',
            '#undef CreateEvent',
            '#endif',
            '#ifdef CreateSemaphore',
            '#undef CreateSemaphore',
            '#endif',
            '#endif',
            ''
        ))

        # Opens only gfxrecon: each generated file opens its own inner namespace, schema, binding, decode or util.
        begin_end.namespaces.append('gfxrecon')

    def add_part_headers(self, begin_end):
        """Adds the headers this generated file includes; every subclass overrides it."""
        raise NotImplementedError


class VulkanSchemaTypesGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options for generated_vulkan_schema_types.h: the API elements and command API elements. Every binding
    and Schema is keyed on an API element, and a Decoded_ wrapper declares its API element as api_element.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'format/platform_types.h',
            'schema/api_element.h',
            'util/defines.h',
            'util/type_list.h',
        ))
        begin_end.system_headers.append('string_view')


class VulkanSchemaFieldsGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options for generated_vulkan_schema_fields.h: the Fields. The MemberPointer partitions and
    generated_vulkan_schema.h include it.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_types.h',
            'schema/field.h',
            'util/defines.h',
        ))
        begin_end.system_headers.extend(('array', 'cstddef', 'string_view'))


class VulkanSchemaGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options for generated_vulkan_schema.h: the Schema specializations. Only the field walk reads a
    Schema, so product code includes it only from the headers that instantiate the walk,
    decode/vulkan_decode_struct_impl.h and encode/vulkan_encode_struct_impl.h.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_fields.h',
            'schema/schema.h',
            'util/defines.h',
            'util/type_list.h',
        ))


class VulkanInventoryGeneratorOptions(VulkanBaseGeneratorOptions):
    """Holds the options for generated_vulkan_inventory.h, which has no include guard, no includes and no namespace,
    so that a consumer can include it inside its own namespace, with its own visit macros defined, once per thing it
    builds.
    """

    def __init__(
        self,
        blacklists=None,
        platform_types=None,
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=False,
        extra_headers=[]
    ):
        VulkanBaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            False,
            False,
            extra_headers=extra_headers
        )
        self.begin_end_file_data.common_api_headers = []


class VulkanSchemaMemberPartitionGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options shared by the MemberPointer partitions, one file per storage type. A subclass adds the
    headers that declare its storage type in storage_headers.
    """

    def storage_headers(self):
        """Returns the headers that declare this partition's storage types; empty when the Vulkan headers declare
        them.
        """
        return ()

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_fields.h',
            'util/defines.h',
            'schema/field.h',
        ))

        begin_end.specific_headers.extend(self.storage_headers())

        begin_end.specific_headers.sort()

        begin_end.pre_namespace_code.extend((
            '// The MemberPointer specializations for this storage kind: schema::Get and Set for every member, and GetRef for',
            '// every addressable one. These headers are large; include them only from code that reads members through a',
            '// Field, the Actions and the schema tests, never from a header other targets include.',
            '',
        ))


class VulkanSchemaApiStructMembersGeneratorOptions(
    VulkanSchemaMemberPartitionGeneratorOptions
):
    """Holds the options for generated_vulkan_schema_api_struct_members.h, keyed on the API structures."""


class VulkanSchemaDecodedStructMembersGeneratorOptions(
    VulkanSchemaMemberPartitionGeneratorOptions
):
    """Holds the options for generated_vulkan_schema_decoded_struct_members.h, keyed on the Decoded_ wrappers."""

    def storage_headers(self):
        return ('generated/generated_vulkan_struct_decoders.h', )


class VulkanSchemaDecodedCommandMembersGeneratorOptions(
    VulkanSchemaMemberPartitionGeneratorOptions
):
    """Holds the options for generated_vulkan_schema_decoded_command_members.h: the MemberPointer specializations
    keyed on the decode::args structures. The args namespace is split across two headers: decode/vulkan_decoder_args.h
    declares the six hand-written args structures (blacklists.json functions-all and functions-decoder),
    generated_vulkan_decoder_args.h the rest.
    """

    def storage_headers(self):
        return ('decode/vulkan_decoder_args.h', 'generated/generated_vulkan_decoder_args.h')


class VulkanSchemaEnumerantsGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options for generated_vulkan_schema_enumerants.h: one enumerant table per enumerated type, value and
    name in registry order. The index and the name lookup over the tables are hand-written in binding/enumerants.h.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'binding/enumerants.h',
            'format/platform_types.h',
            'generated/generated_vulkan_schema_types.h',
            'util/defines.h',
        ))


class VulkanWireTypesGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options for generated_vulkan_wire_types.h: one binding::WireTypeOf specialization per scalar, enum
    and text API element, each holding the format typedef the encoder records it as. binding/vulkan_wire_type.h and
    the schema test include it.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'binding/wire_type_of.h',
            'format/format.h',
            'generated/generated_vulkan_schema_types.h',
            'util/defines.h',
        ))


class VulkanEnumToStringBodyGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options for generated_vulkan_enum_to_string.cpp: one ToString definition per C enum over its enumerant
    table, and the explicit instantiations of the API element-keyed ToString for the 64-bit flag-bits types. The bodies
    they forward to are in util/vulkan_enum_to_string_impl.h, which only this file includes.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_enumerants.h',
            'generated/generated_vulkan_schema_types.h',
            'util/defines.h',
            'util/vulkan_enum_to_string_impl.h',
        ))


class VulkanSchemaChecksGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options for generated_vulkan_schema_checks.cpp. Compiling it is the test: it holds static_asserts
    and the constexpr counts they compare, and only gfxrecon_framework_test compiles it (framework/CMakeLists.txt), so
    it costs a product build nothing and may include any header it checks.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'binding/enumerants.h',
            'binding/vulkan_call_id.h',
            'binding/vulkan_decoded_type.h',
            'binding/vulkan_api_element_of.h',
            'binding/vulkan_wire_type.h',
            'decode/vulkan_decoder_args.h',
            'binding/vulkan_catalog.h',
            'generated/generated_vulkan_decoder_args.h',
            'generated/generated_vulkan_schema.h',
            'generated/generated_vulkan_schema_enumerants.h',
            'generated/generated_vulkan_struct_decoders.h',
            'schema/schema.h',
            'util/defines.h',
        ))
        begin_end.system_headers.append('type_traits')


class VulkanSchemaBaseGenerator(VulkanBaseGenerator):
    """Builds the model every generated schema file is written from. One subclass per generated file: build_model
    builds the model, and the subclass's write_part writes that file's part of it.
    """

    # Maps the primitive spellings the base generator does not classify to their wire kind. The fixed-width integers
    # come from KhronosBaseGenerator.encode_types; these five are the ones it lacks.
    PRIMITIVE_CATEGORIES = {
        'int': 'Int32',
        'float': 'Float',
        'double': 'Double',
        'char': 'Char',
        'wchar_t': 'WChar',
    }

    # Maps the types that keep a wire kind of their own instead of resolving through their basetype. vk.xml does not
    # say which types these are; they are curated from the hand-written encoder. VkDeviceSize stays DeviceSize, not
    # UInt64, so a consumer of the field model can tell a device size from any 64-bit integer. The bytes are the same,
    # and the generated command decoders resolve the basetype (DecodeUInt64Value). size_t is here because
    # its width varies: 4 or 8 bytes in memory, 8 on the wire. No width is stated here: WIRE_TYPES gives each kind's
    # format typedef, and the checks file asserts that each refinement records the same bytes as its basetype.
    CURATED_CATEGORIES = {
        'size_t': 'SizeT',
        'VkDeviceSize': 'DeviceSize',
        'VkDeviceAddress': 'DeviceAddress',
        'VkSampleMask': 'SampleMask',
    }

    # WireTypeOf defines the encoded representation for a given arithmetic API element.
    WIRE_TYPES = {
        'Int8': 'Int8EncodeType',
        'Int16': 'Int16EncodeType',
        'Int32': 'Int32EncodeType',
        'Int64': 'Int64EncodeType',
        'UInt8': 'UInt8EncodeType',
        'UInt16': 'UInt16EncodeType',
        'UInt32': 'UInt32EncodeType',
        'UInt64': 'UInt64EncodeType',
        'Float': 'FloatEncodeType',
        'Double': 'DoubleEncodeType',
        'Char': 'CharEncodeType',
        'WChar': 'WCharEncodeType',
        'SizeT': 'SizeTEncodeType',
        'Enum': 'EnumEncodeType',
        'Flags': 'FlagsEncodeType',
        'Flags64': 'Flags64EncodeType',
        'SampleMask': 'SampleMaskEncodeType',
        'DeviceSize': 'DeviceSizeEncodeType',
        'DeviceAddress': 'DeviceAddressEncodeType',
    }

    # Lists the C and <cstdint> types the API uses. The Vulkan headers do not declare them under a name of their
    # own, so their element_type is written unqualified and their API element name comes from DESCRIPTOR_NAME_FOR_TYPE.
    PRIMITIVE_TYPES = (
        'int8_t',
        'int16_t',
        'int32_t',
        'int64_t',
        'uint8_t',
        'uint16_t',
        'uint32_t',
        'uint64_t',
        'int',
        'char',
        'wchar_t',
        'size_t',
        'float',
        'double',
    )

    # Maps each type whose registry spelling is not a usable API element name to the name used instead. An API
    # element is a type of its own, so it cannot be named for a keyword, e.g. int, and it must not shadow the
    # element_type it describes, e.g. uint32_t.
    DESCRIPTOR_NAME_FOR_TYPE = {
        'int8_t': 'Int8',
        'int16_t': 'Int16',
        'int32_t': 'Int32',
        'int64_t': 'Int64',
        'uint8_t': 'UInt8',
        'uint16_t': 'UInt16',
        'uint32_t': 'UInt32',
        'uint64_t': 'UInt64',
        'int': 'Int',
        'char': 'Char',
        'wchar_t': 'WChar',
        'size_t': 'SizeT',
        'float': 'Float',
        'double': 'Double',
        'void': 'Void',
    }

    # The API element of every runtime-typed handle field. The API declares the field as an integer; a sibling field
    # holds the handle type at run time.
    GENERIC_HANDLE_DESCRIPTOR = 'GenericHandle'

    RETURN_FIELD_NAME = 'result'

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        VulkanBaseGenerator.__init__(
            self,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Model built once in endFile and shared by every part.
        self.schema_structs = []  # Structure names that get a Schema specialization: every structure with members.
        self.schema_unions = []  # Union names that get a Schema of Alternatives: every union.
        self.wrapper_structs = []  # Structure names with a generated Decoded_ wrapper.
        self.schema_commands = []  # Command names that get a Schema specialization.
        # The registry's selector and selection attributes, which ValueInfo does not carry: (owner, member) to
        # the sibling whose value chooses a union member's alternative, and (union, member) to the selector values
        # that choose it.
        self.member_selectors = dict()
        self.member_selections = dict()
        self.may_reach_cache = dict()
        self.api_type_categories = dict()  # API element name to its schema::category word.
        self.api_type_wire_kinds = dict()  # API element name to the wire kind that selects its WireTypeOf.
        self.platform_api_types = set()  # Platform typedefs with an API element of their own, for the types header.
        self.api_type_elements = dict()  # API element name to its element_type expression.
        self.defaulted_types = set()  # Registry types that reached the Scalar fallback without being classified.
        self.bitmask_types = set()  # Enum groups vk.xml declares type="bitmask".

    def genStruct(self, typeinfo, typename, alias):
        """Method override: also records the registry's selector attributes."""
        VulkanBaseGenerator.genStruct(self, typeinfo, typename, alias)
        if not alias:
            self.record_member_attributes(typeinfo, typename)

    def genUnion(self, typeinfo, typename, alias):
        """Method override: also records the registry's selection attributes."""
        VulkanBaseGenerator.genUnion(self, typeinfo, typename, alias)
        if not alias:
            self.record_member_attributes(typeinfo, typename)

    def record_member_attributes(self, typeinfo, typename):
        for member in typeinfo.elem.findall('.//member'):
            name = noneStr(member.find('name').text)
            selector = member.get('selector')
            if selector:
                self.member_selectors[(typename, name)] = selector
            selection = member.get('selection')
            if selection:
                self.member_selections[(typename, name)] = [part.strip() for part in selection.split(',')]

    def genGroup(self, groupinfo, group_name, alias):
        """Method override: also records each group vk.xml declares type="bitmask" in bitmask_types."""
        VulkanBaseGenerator.genGroup(self, groupinfo, group_name, alias)
        if groupinfo.elem.get('type') == 'bitmask':
            self.bitmask_types.add(group_name)

    #
    # Utilities for the model
    #
    def get_base_structs(self):
        api_data = self.get_api_data()
        if (api_data) :
            return (api_data.base_in_struct, api_data.base_out_struct)
        return ()

    def get_decodable_struct_names(self):
        """Returns every structure vk.xml gives members except the two base structures, which have no Decoded_
        wrapper.
        """
        base_structs = self.get_base_structs()
        return [key for key in self.all_struct_members if key not in base_structs]

    #
    # Model
    #

    def build_model(self):
        """Selects the structures, unions and commands that get a Schema, and registers an API element for every type
        a generated file refers to."""
        # Every structure vk.xml gives members gets a Schema, and every union a Schema of Alternatives. A hand-written
        # encoder, decoder or handle mapping is an inventory property, never the absence of a Schema. Platform
        # structures (platform_types.json structs) have no members and no Schema.
        self.schema_structs = list(self.all_struct_members)
        self.schema_unions = list(self.all_union_members)

        # The structures with a generated Decoded_ wrapper: all but blacklists.json structures and platform structures.
        # Only a generated wrapper is relied on to hold its API element and to declare the members the decoded-struct
        # partition maps; a hand-written one is not.
        self.wrapper_structs = list(self.get_all_filtered_struct_names())

        # Every decodable structure gets the HAS_DECODED_TYPE inventory property, hand-written decoder or not, so
        # schema-driven code can reach its Decoded_ wrapper through binding::DecodedTypeOf.
        self.schema_decodable_structs = list(self.get_decodable_struct_names())

        self.schema_commands = list(self.get_all_filtered_cmd_names())

        # The inputs of the inventory properties, which binding/vulkan_catalog.h reads back. A blacklists.json
        # structures entry has a hand-written encoder and decoder; structures-encoder and structures-decoder, when
        # present, list one side only. Platform structures count as hand-written for encode, decode and, through
        # STRUCT_BLACKLIST, handle mapping.
        with open(self.genOpts.blacklists, 'r') as blacklists:
            lists = json.load(blacklists)
        self.custom_encode_structs = set(lists['structures']) | set(lists.get('structures-encoder', ())) | set(self.PLATFORM_STRUCTS)
        self.custom_decode_structs = set(lists['structures']) | set(lists.get('structures-decoder', ())) | set(self.PLATFORM_STRUCTS)
        self.custom_handle_mapping_structs = set(self.STRUCT_BLACKLIST) | set(self.STRUCT_MAPPERS_BLACKLIST)
        self.external_structs = set(self.PLATFORM_STRUCTS)
        self.generic_handle_structs = set(self.GENERIC_HANDLE_STRUCTS)
        self.deep_copy_exclusions = lists['structures-deep-copy']

        # 'void' always has an API element, because a void command still has one Return Field.
        self.add_api_type('void')

        # Registers GENERIC_HANDLE_DESCRIPTOR, the one API element every runtime-typed handle field refers to.
        self.api_type_categories[self.GENERIC_HANDLE_DESCRIPTOR] = 'Handle'
        self.api_type_wire_kinds[self.GENERIC_HANDLE_DESCRIPTOR] = 'Handle'
        self.api_type_elements[self.GENERIC_HANDLE_DESCRIPTOR] = 'uint64_t'

        for struct in self.schema_structs:
            # Every structure that gets a Schema also gets an API element: the Schema and binding::DecodedTypeOf are
            # keyed on it even when no Field refers to the type.
            self.add_api_type(struct)

            for value in self.all_struct_members[struct]:
                self.add_field_api_type(value)

        for union in self.schema_unions:
            self.add_api_type(union)

            for value in self.all_union_members[union]:
                self.add_field_api_type(value)

        for command in self.schema_commands:
            return_type, _, params = self.all_cmd_params[command]
            self.add_api_type(self.clean_return_type(return_type))
            for value in params:
                self.add_field_api_type(value)

        # Every structure with a structure type gets an API element, whether or not it has a Schema.
        for struct in self.struct_type_names:
            if struct not in self.all_struct_aliases:
                self.add_api_type(struct)

        # Every enumerated type gets an API element, whether or not a Field refers to it, so its enumerant table has a
        # key.
        for enum in self.enum_names:
            if self.is_enumerated(enum):
                self.add_api_type(enum)

        # VkFlags and VkFlags64 get API elements of their own; binding/wire_type_of.h reads a bitmask's width through
        # its flags_type. EmptyBitvalues and EmptyBitvalues64 are the bits API elements of the bitmasks vk.xml gives no
        # bits enum.
        api_data = self.get_api_data()
        self.add_api_type(api_data.flags_type)
        self.add_api_type(api_data.flags_64_type)
        self.empty_bitvalues = {api_data.flags_type: 'EmptyBitvalues', api_data.flags_64_type: 'EmptyBitvalues64'}
        for flags, name in self.empty_bitvalues.items():
            self.api_type_wire_kinds[name] = self.get_logical_category(flags)
            self.api_type_categories[name] = 'Enum'
            self.api_type_elements[name] = '::' + flags

        if self.defaulted_types:
            write(
                '* Vulkan schema: unclassified, treated as a plain scalar: {}'.format(
                    ', '.join(sorted(self.defaulted_types))
                ),
                file=sys.stderr
            )

    def clean_return_type(self, return_type):
        return return_type.strip() if return_type else 'void'

    def may_reach_handles(self, name):
        """Returns True if a value of this type can hold a handle: through a handle member, a generic handle, a
        pNext, or a member structure or union that can. Broader than struct_might_have_handles in
        khronos_base_generator.py, which the handle-mapping generators use: this one counts a pNext at any depth,
        because a missed handle is the worse failure. Raises ValueError on a cycle through members other than pNext,
        where the recursion would not end."""
        if name in self.may_reach_cache:
            if self.may_reach_cache[name] is None:
                raise ValueError('may_reach_handles: {} reaches itself through a member'.format(name))
            return self.may_reach_cache[name]

        members = self.all_struct_members.get(name, self.all_union_members.get(name))
        if members is None:
            self.may_reach_cache[name] = False
            return False

        self.may_reach_cache[name] = None
        generic_handles = self.get_generic_handles(name, False, members)
        result = any(
            value.name in generic_handles or self.get_logical_category(value.base_type) == 'Handle'
            or self.is_extension_chain(value)
            for value in members
        )
        if not result:
            result = any(
                self.get_logical_category(value.base_type) == 'Struct'
                and self.may_reach_handles(self.resolve_type_alias(value.base_type))
                for value in members
            )
        self.may_reach_cache[name] = result
        return result

    def resolve_type_alias(self, base_type):
        """Follows registry aliases to the canonical type. An alias uses the schema of its canonical type."""
        resolved = base_type

        for _ in range(8):
            if resolved in self.all_struct_aliases:
                resolved = self.all_struct_aliases[resolved]
            elif resolved in self.all_union_aliases:
                resolved = self.all_union_aliases[resolved]
            elif resolved in self.handle_aliases:
                resolved = self.handle_aliases[resolved]
            elif resolved in self.flags_type_aliases:
                resolved = self.flags_type_aliases[resolved]
            elif resolved in self.enumAliases:
                resolved = self.enumAliases[resolved]
            else:
                break

        return resolved

    def is_extension_chain(self, value):
        """Returns True for the extension chain member. The base generator's is_extended_struct_definition asks for a
        void pointer, which every structure but the two base structures declares; theirs is typed as the base
        structure itself and is the chain all the same. Without this, a Pointer to the owner's own type would make the
        base structure's schema a cycle."""
        if self.is_extended_struct_definition(value):
            return True
        return (
            value.name == self.get_extended_struct_var_name() and value.is_pointer
            and self.resolve_type_alias(value.base_type) in self.get_base_structs()
        )

    def get_api_element_name(self, base_type):
        """Returns the identifier of the API element for a registry type."""
        resolved = self.resolve_type_alias(base_type)
        return self.DESCRIPTOR_NAME_FOR_TYPE.get(resolved, resolved)

    def get_api_element_path(self, base_type):
        """Returns the API element's path from the schema namespace, for a line emitted at schema scope."""
        return 'vulkan::api_elements::{}'.format(self.get_api_element_name(base_type))

    def get_api_element_reference(self, name):
        """Returns the API element's spelling from inside schema::vulkan::fields::<owner>, where a Field is emitted.
        Lookup reaches schema::vulkan from there, so the vulkan component is not written."""
        return 'api_elements::{}'.format(name)

    def get_generic_handles(self, owner, is_command, members):
        """Maps member name to selector name for the fields GFXReconstruct treats as runtime-typed handles.

        The API declares these as plain integers, so no type-level fact can express them. The knowledge is curated in
        the base generator's generic-handle tables.
        """
        generic = dict()

        for value in members:
            if is_command:
                if not self.is_generic_cmd_handle_value(owner, value.name):
                    continue
                selector = self.get_generic_cmd_handle_type_value(owner, value.name)
            else:
                if not self.is_generic_struct_handle_value(owner, value.name):
                    continue
                selector = self.get_generic_struct_handle_type_value(owner, value.name)

            if selector and any(member.name == selector for member in members):
                generic[value.name] = selector

        return generic

    def get_element_type(self, base_type):
        """Returns the API element's element_type, e.g. ::VkExtent2D. This is not the declared type of any field: a
        field's declaration adds the const, pointer and array levels around it, so a `const char* const*` member's
        API element is Char, whose element_type is char."""
        resolved = self.resolve_type_alias(base_type)

        if resolved == 'void':
            return 'void'

        if resolved in self.PRIMITIVE_TYPES:
            return resolved

        # Everything else is a name the Vulkan headers declare at global scope. The :: matters: an API element carries
        # the name of the type it describes, so inside the API element the unqualified name is the API element.
        return '::{}'.format(resolved)

    def get_underlying_primitive(self, base_type):
        """Follows basetype and bitmask declarations down to the primitive a named type resolves to. Returns None
        if it resolves to none."""
        resolved = self.resolve_type_alias(base_type)

        for _ in range(8):
            if resolved in self.PRIMITIVE_TYPES:
                return resolved

            if self.is_flags(resolved):
                resolved = self.flags_types[resolved]
            elif self.has_basetype(resolved):
                resolved = self.get_basetype(resolved)
            else:
                return None

        return None

    def category_for_type(self, name):
        """Returns the wire kind a registry type name carries of its own (curated, primitive or encode_types), or
        None when no source gives one."""
        category = self.CURATED_CATEGORIES.get(name)

        if category is None:
            category = self.PRIMITIVE_CATEGORIES.get(name)

        if category is None:
            category = self.encode_types.get(name)

        return category

    def get_logical_category(self, base_type):
        """Returns the wire kind of a registry type: the input to category_for, and for an arithmetic kind the key
        into WIRE_TYPES."""
        api_data = self.get_api_data()
        resolved = self.resolve_type_alias(base_type)

        if resolved == 'void':
            return 'Void'

        if self.is_handle_like(resolved):
            return 'Handle'

        # struct_names holds unions too, so this is the union case as well.
        if self.is_struct(resolved):
            return 'Struct'

        if resolved == api_data.flags_type:
            return 'Flags'

        if resolved == api_data.flags_64_type:
            return 'Flags64'

        if self.is_flags(resolved):
            return 'Flags64' if self.is_64bit_flags(resolved) else 'Flags'

        # A 64-bit flag-bits type is declared as an enum in the registry and is a typedef of the 64-bit flags type in C.
        if self.is_enum(resolved) and self.is_flags_enum_64bit(resolved):
            return 'Flags64'

        if self.is_enum(resolved):
            return 'Enum'

        # Callback is the registry's funcpointer category; category_for maps it to Funcpointer.
        if self.is_function_ptr(resolved):
            return 'Callback'

        curated = self.category_for_type(resolved)

        if curated is not None:
            return curated

        if self.has_basetype(resolved):
            curated = self.category_for_type(self.get_basetype(resolved))

            if curated is not None:
                return curated

        # Nothing classified this type. Wire kind Scalar is not in WIRE_TYPES, so the API element satisfies the scalar
        # concepts but has no WireTypeOf specialization: encoding it fails to compile. build_model reports it.
        self.defaulted_types.add(resolved)
        return 'Scalar'

    def category_for(self, name, wire_kind):
        """Returns the API element's category, the registry's word, from its wire kind and the registry facts the wire
        kind collapses. Struct splits into Struct and Union. Flags and Flags64 split into Bitmask (a mask typedef),
        Enum (a 64-bit bits enum) and Scalar (VkFlags, VkFlags64). Callback becomes Funcpointer."""
        if wire_kind == 'Struct':
            return 'Union' if name in self.all_union_members else 'Struct'
        if wire_kind == 'Callback':
            return 'Funcpointer'
        if wire_kind in ('Flags', 'Flags64'):
            if self.is_flags(name):
                return 'Bitmask'
            if self.is_enum(name):
                return 'Enum'
            return 'Scalar'
        if wire_kind in ('Handle', 'Enum', 'Void', 'Opaque', 'Char', 'WChar'):
            return wire_kind
        return 'Scalar'

    def get_field_element_name(self, value):
        """Returns the name of a field's API element: the platform typedef's own when the header spells one
        that PLATFORM_TYPES substitutes, else the registry type's. The API element keeps the header's name; the
        substituted type selects its category."""
        platform = value.platform_base_type

        if platform:
            self.add_platform_api_type(platform, value)
            return platform

        return self.get_api_element_name(value.base_type)

    def add_field_api_type(self, value):
        """Registers a member's or parameter's API element, the platform typedef's own where it has one."""
        if self.get_field_element_name(value) == self.get_api_element_name(value.base_type):
            self.add_api_type(value.base_type)

    def add_platform_api_type(self, platform_type, value):
        """Registers an API element for a platform typedef, named and typed as the header spells it. Its category is
        Opaque when PLATFORM_TYPES gives baseType void: an opaque structure the header reaches through a pointer, or a
        handle typedef held by value. Otherwise it is the category of the substituted type: WChar for LPCWSTR,
        Scalar for DWORD."""
        if platform_type in self.api_type_categories:
            return

        if self.PLATFORM_TYPES[platform_type]['baseType'] == 'void':
            wire_kind = 'Opaque'
        else:
            wire_kind = self.get_logical_category(value.base_type)

        # element_type is qualified from the global namespace: inside the API element, the unqualified name is
        # the API element itself.
        self.api_type_wire_kinds[platform_type] = wire_kind
        self.api_type_categories[platform_type] = self.category_for(platform_type, wire_kind)
        self.api_type_elements[platform_type] = '::' + platform_type
        self.platform_api_types.add(platform_type)

    def add_api_type(self, base_type):
        name = self.get_api_element_name(base_type)

        if name in self.api_type_categories:
            return

        # Not validated here: a category schema::category does not declare fails to compile at the symbol, and an API
        # element narrower than its wire type fails the width static_assert in generated_vulkan_schema_checks.cpp.
        wire_kind = self.get_logical_category(base_type)

        self.api_type_wire_kinds[name] = wire_kind
        self.api_type_categories[name] = self.category_for(name, wire_kind)
        self.api_type_elements[name] = self.get_element_type(base_type)

    #
    # Field model
    #

    def get_command_api_element_name(self, command):
        return VulkanBaseGenerator.make_args_struct_name(command)

    def get_field_namespace(self, element):
        return 'vulkan::fields::{}'.format(element)

    def get_field_path(self, element, field_name):
        return '{}::{}'.format(self.get_field_namespace(element), field_name)

    def get_field_shape(self, value):
        """Returns the field's shape, how it packages its API element at this use: Value, Pointer, Array,
        PointerArray, StaticArray or ExtensionChain. The length and declaration logic read it; it is not emitted."""
        if self.is_extension_chain(value):
            return 'ExtensionChain'

        # A platform typedef has its own API element, so the shape follows the header's declarator around the typedef:
        # LPCWSTR name and HANDLE handle are values, HANDLE* pHandle is a pointer.
        if value.platform_base_type and '*' not in value.platform_full_type and not value.is_array:
            return 'Value'

        if value.is_array and not value.is_dynamic:
            return 'StaticArray'

        if value.is_pointer:
            if value.is_array and self.is_pointer_array(value):
                return 'PointerArray'
            return 'Array' if value.is_array else 'Pointer'

        return 'Value'

    def is_pointer_array(self, value):
        """Returns True for an array of pointers, each to one element: two stars, and either char or wchar_t text, or
        a length of the form 'count,1'. For text, the base generator has already reduced 'count,null-terminated' to
        the count. A two-star member whose second length is anything else, or absent, is not one. vk.xml gives only
        the outer count for ppBuildRangeInfos and ppMaxPrimitiveCounts, so they stay Array."""
        if value.pointer_count != 2:
            return False

        if value.base_type in ('char', 'wchar_t'):
            return True

        parts = [part.strip() for part in (value.array_length or '').split(',')]
        return len(parts) == 2 and parts[1] == '1'

    def get_count_field(self, value, members):
        """Returns the sibling Field that holds the count when the length is exactly one sibling name, else None."""
        length = value.array_length

        if not length or value.array_length_value is None:
            return None

        if self.get_field_shape(value) == 'PointerArray':
            # 'count,1': the 1 is the length of each pointed-at array; only the count refers to a sibling.
            length = length.split(',')[0].strip()

        if length != value.array_length_value.name:
            return None

        if not any(member.name == length for member in members):
            return None

        return length

    def get_count_member(self, value, members):
        """Returns the (sibling, member Field path) pair when the length is read through a pointer sibling,
        `sibling->member`, else None."""
        length = value.array_length
        sibling = value.array_length_value

        if not length or sibling is None or '->' not in length:
            return None

        sibling_name, _, member_name = (part.strip() for part in length.partition('->'))

        if sibling_name != sibling.name or not any(member.name == sibling_name for member in members):
            return None

        if sibling.base_type not in self.schema_structs:
            return None

        if not any(member.name == member_name for member in self.all_struct_members[sibling.base_type]):
            return None

        return sibling_name, self.get_field_path(sibling.base_type, member_name)

    def parse_count_expression(self, value, members):
        """Returns the registry's arithmetic length as a tree, or None when it is not one the schema states.

        The registry writes a computed length as C text in altlen: `codeSize / 4`, `(rasterizationSamples + 31) / 32`,
        `2*VK_UUID_SIZE`. The grammar is integers, sibling names, API constants, +, *, / and parentheses, and nothing
        else; a length outside it stays as length_expression text. Each node is ('number', text), ('sibling', name),
        ('constant', name) or (op, left, right) with op one of '+', '*', '/'.
        """
        import re

        length = value.array_length

        if not length or self.get_field_shape(value) not in ('Array', 'PointerArray'):
            return None

        if not any(op in length for op in '+*/'):
            return None

        tokens = re.findall(r'\d+|[A-Za-z_]\w*|[()+*/]|\S', length)
        sibling_names = {member.name for member in members}
        position = 0

        def peek():
            return tokens[position] if position < len(tokens) else None

        def take():
            nonlocal position
            token = tokens[position]
            position += 1
            return token

        def factor():
            token = take()
            if token == '(':
                node = expression()
                if take() != ')':
                    raise ValueError(length)
                return node
            if token.isdigit():
                return ('number', token)
            if token in sibling_names:
                return ('sibling', token)
            if token in self.registry.enumdict:
                return ('constant', token)
            raise ValueError(length)

        def term():
            node = factor()
            while peek() in ('*', '/'):
                node = (take(), node, factor())
            return node

        def expression():
            node = term()
            while peek() == '+':
                node = (take(), node, term())
            return node

        try:
            tree = expression()
        except (ValueError, IndexError):
            return None

        if position != len(tokens):
            return None

        return tree

    def count_expression_siblings(self, tree):
        """Returns the sibling names a count expression reads."""
        if tree[0] == 'sibling':
            return [tree[1]]
        if tree[0] in ('number', 'constant'):
            return []
        return self.count_expression_siblings(tree[1]) + self.count_expression_siblings(tree[2])

    def make_count_expression(self, tree, members):
        """Returns the StoreValue type for a count expression tree.

        A literal is written unsigned unless an enum sibling takes part, so that it meets an unsigned sibling or an
        unsigned API constant without a sign conversion, and an enum's promotion to int stays an int.
        """
        siblings = self.count_expression_siblings(tree)
        has_enum = any(
            self.is_enum(member.base_type) for member in members if member.name in siblings
        )
        suffix = '' if has_enum else 'u'
        operators = {'+': 'Sum', '*': 'Product', '/': 'Quotient'}

        def emit(node):
            if node[0] == 'number':
                return 'Literal<{}{}>'.format(node[1], suffix)
            if node[0] == 'sibling':
                return 'FieldValue<{}>'.format(node[1])
            if node[0] == 'constant':
                return 'Literal<{}>'.format(node[1])
            return '{}<{}, {}>'.format(operators[node[0]], emit(node[1]), emit(node[2]))

        return emit(tree)

    def get_field_length(self, value, members):
        """Returns the length expression, or None when no Action can evaluate the registry length."""
        count_field = self.get_count_field(value, members)

        if count_field:
            return 'FieldValue<{}>'.format(count_field)

        count_member = self.get_count_member(value, members)

        if count_member:
            return 'FieldValue<{}, {}>'.format(*count_member)

        tree = self.parse_count_expression(value, members)

        if tree:
            return self.make_count_expression(tree, members)

        return None

    def get_count_note(self, value, members):
        """Returns the NOTE comment written above a Field whose length is arithmetic, quoting the registry's altlen
        text, or None."""
        if self.parse_count_expression(value, members) is None:
            return None

        return '// NOTE: length evaluates {}'.format(value.array_length)

    def get_static_array_extents(self, value):
        """Returns the declared extents of a fixed-extent array member: the registry's spellings, in declaration
        order, outermost first."""
        return [part.strip() for part in value.array_capacity.split(',')]

    def make_field_definition(self, value, members, generic_handles, owner):
        """Returns one Field definition: its name and its declaration, plus selector_field, selections,
        has_extensions and length_expression where they apply. It restates no type fact the declaration carries."""
        shape = self.get_field_shape(value)
        generic_selector = generic_handles.get(value.name)

        # selector_field is the sibling whose value chooses what this field holds: the object type of a
        # runtime-typed handle, from the generic-handle tables, or the registry's selector on a union-typed member.
        selector = generic_selector if generic_selector is not None else self.member_selectors.get((owner, value.name))

        if generic_selector is not None:
            api_element = self.get_api_element_reference(self.GENERIC_HANDLE_DESCRIPTOR)
        elif value.platform_base_type:
            # A platform typedef has its own API element. This branch precedes the base_type branch because
            # value.base_type holds the substituted type, e.g. void for HANDLE.
            api_element = self.get_api_element_reference(self.get_field_element_name(value))
        else:
            api_element = self.get_api_element_reference(self.get_api_element_name(value.base_type))

        length = self.get_field_length(value, members)
        declaration = self.make_declaration(value, api_element, shape, length)

        # Facts the declarator does not spell stay as members of the derived struct.
        parts = []

        if selector is not None:
            parts.append('using selector_field = {};'.format(selector))

        # A union alternative lists the selector values that choose it, in the registry's selection order.
        selections = self.member_selections.get((owner, value.name))

        if selections:
            parts.append('static constexpr auto selections = std::array{{ {} }};'.format(', '.join(selections)))

        if shape == 'ExtensionChain':
            # has_extensions is true when vk.xml lists the owner on either side of a structextends. The base generator
            # calls the complement after the spec's usual consequence, "pNext must be NULL"; the schema records the
            # vk.xml fact, which the spec text does not always match: no structextends lists VkPipelineCreateInfoKHR,
            # so it gets false, but the spec requires a pNext node.
            parts.append(
                'static constexpr bool has_extensions = {};'.format(
                    'false' if self.must_extended_struct_be_null(owner) else 'true'
                )
            )

        if not length and value.array_length and shape == 'Array':
            parts.append(
                'static constexpr std::string_view length_expression = "{}";'.
                format(value.array_length)
            )

        return 'struct {} : Field<"{}", {}> {{{}}};'.format(
            value.name, value.name, declaration, ' ' + ' '.join(parts) + ' ' if parts else ''
        )

    def make_declaration(self, value, api_element, shape, length):
        """Returns the declaration of one field use: the API element, or Const, Pointer, Array or FixedArray over
        it as the C declarator nests. It is read from the registry's full type, so each level's const lands where
        the header wrote it."""
        if shape == 'ExtensionChain':
            # ExtensionChain resolves unqualified here: the Field is emitted inside the schema namespace.
            element = 'ExtensionChain'
        else:
            element = api_element

        # Reads the header's spelling: for a platform typedef, the declarator around the typedef, not around what the
        # base generator substituted for it.
        segments = (value.platform_full_type or value.full_type).split('*')
        levels = segments[1:]

        declaration = element

        if 'const' in segments[0]:
            declaration = 'Const<{}>'.format(declaration)

        for index, segment in enumerate(levels):
            if index == len(levels) - 1 and shape in ('Array', 'PointerArray'):
                declaration = 'Array<{}, {}>'.format(declaration, length if length else 'UnknownLength')
            else:
                declaration = 'Pointer<{}>'.format(declaration)

            if 'const' in segment:
                declaration = 'Const<{}>'.format(declaration)

        if shape == 'StaticArray':
            # Nests from the innermost extent outward; a bounded array's sibling length sits on the outermost level.
            extents = self.get_static_array_extents(value)

            for index, extent in enumerate(reversed(extents)):
                outermost = index == len(extents) - 1
                declaration = 'FixedArray<{}, {}, {}>'.format(
                    declaration, length if (outermost and length) else 'UseCapacity', extent
                )

        return declaration

    def make_return_field_definition(self, return_type):
        """Returns the command's Return Field definition. Every command has one; a void command's Return Field
        holds the Void API element."""
        return 'struct {} : Field<"{}", {}> {{ static constexpr bool is_return = true; }};'.format(
            self.RETURN_FIELD_NAME,
            self.RETURN_FIELD_NAME,
            self.get_api_element_reference(self.get_api_element_name(self.clean_return_type(return_type))),
        )

    def write_field_namespace(self, element, members, owner, is_command, return_type=None):
        """Writes the namespace of Fields for one structure, union or command."""
        write(
            'GFXRECON_BEGIN_NAMESPACE({})'.format(element), file=self.outFile
        )

        generic_handles = self.get_generic_handles(owner, is_command, members)

        # A length or selector_field refers to a sibling Field, and vk.xml always declares that sibling before the
        # member that refers to it, so Fields are written in member order with no forward declarations. A sibling
        # referred to before its declaration fails to compile at that line.
        for value in members:
            note = self.get_count_note(value, members)
            if note:
                write(note, file=self.outFile)
            write(
                self.make_field_definition(value, members, generic_handles, owner),
                file=self.outFile
            )

        if return_type is not None:
            write(
                self.make_return_field_definition(return_type),
                file=self.outFile
            )

        write('GFXRECON_END_NAMESPACE({})'.format(element), file=self.outFile)
        self.newline()

    def make_schema_specialization(self, key, element, field_names, list_name='Fields'):
        """Returns one Schema specialization. Its Fields list is the canonical field order for the API element; a
        union's Alternatives list is its members, of which a value holds one."""
        namespace = self.get_field_namespace(element)
        entries = ['{}::{}'.format(namespace, name) for name in field_names]

        lines = ['template <>', 'struct Schema<{}>'.format(key), '{']
        prefix = '    using {} = util::TypeList<'.format(list_name)
        indent = ' ' * len(prefix)
        line = prefix

        for index, entry in enumerate(entries):
            separator = ',' if index + 1 < len(entries) else '>;'
            fragment = entry + separator

            if line not in (prefix, indent) and (len(line) + len(fragment)) > 120:
                lines.append(line.rstrip())
                line = indent

            line += fragment

            if separator == ',':
                line += ' '

        lines.append(line.rstrip())
        lines.append('};')

        return '\n'.join(lines)

    #
    # Output
    #

    def endFile(self):
        """Method override: builds the model, then writes this file's part of it."""
        self.build_model()
        self.write_part()

        VulkanBaseGenerator.endFile(self)

    def write_part(self):
        """Writes this generated file's part of the model; every subclass overrides it."""
        raise NotImplementedError

    def write_schema_part(self, *writers):
        """Writes the given parts inside gfxrecon::schema, which every schema file opens the same way."""
        write('GFXRECON_BEGIN_NAMESPACE(schema)', file=self.outFile)
        self.newline()

        for writer in writers:
            writer()

        write('GFXRECON_END_NAMESPACE(schema)', file=self.outFile)

    def write_api_elements(self):
        write(
            '// API elements: one per type referenced by the schema. An API element carries its name, the\n'
            '// type the Vulkan headers declare (element_type) and the registry\'s category word for it. It\n'
            '// carries no wire type and no decoded type: those are bindings, binding::WireTypeOf and\n'
            '// binding::DecodedTypeOf.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()
        write('// The enumerant tables, defined in generated_vulkan_schema_enumerants.h. Each enumerated API element refers to its own.', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(enumerants)', file=self.outFile)
        for enum in self.get_enumerated_types() + sorted(self.empty_bitvalues.values()):
            write('struct {};'.format(enum), file=self.outFile)
        write('GFXRECON_END_NAMESPACE(enumerants)', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(api_elements)', file=self.outFile)

        if self.platform_api_types:
            write(
                '// Platform typedefs (platform_types.json and REPLACE_TYPE): each has an API element named and\n'
                '// typed as the platform header spells it. Its category is Opaque when the substituted base type\n'
                '// is void, else the substituted type\'s category, e.g. Scalar for DWORD.',
                file=self.outFile
            )

        # Every API element is declared before any is defined: a bitmask refers to its flags and bits API elements in
        # its base, and the names sort in no useful order.
        for name in sorted(self.api_type_categories):
            write('struct {};'.format(name), file=self.outFile)
        self.newline()

        # Each API element derives from its category's base in schema/api_element.h, which supplies the members the
        # category carries. Interim until stage 3: Opaque, Char and WChar derive from ApiElementBase. The table and API
        # element template arguments are qualified from the global namespace: inside an ApiElementEnum, an
        # unqualified enumerants:: resolves to the inherited enumerants member.
        bitvalues = self.get_bitvalues_of_bitmasks()
        elements = '::gfxrecon::schema::vulkan::api_elements::'
        for name in sorted(self.api_type_categories):
            element = self.api_type_elements[name]
            # An API element is named for the type it describes; EmptyBitvalues and EmptyBitvalues64 describe none and
            # are named for themselves.
            spelled = name if name in self.empty_bitvalues.values() else element.lstrip(':')
            args = '"{}", {}'.format(spelled, element)
            category = self.api_type_categories[name]
            body = ''
            if category == 'Struct':
                structure_type = self.get_structure_type(name)
                if structure_type is not None:
                    base = 'ApiElementTypedStruct<{}, {}>'.format(args, structure_type)
                else:
                    base = 'ApiElementStruct<{}>'.format(args)
            elif category == 'Enum':
                base = 'ApiElementEnum<{}, ::gfxrecon::schema::vulkan::enumerants::{}>'.format(args, name)
                if name in self.bitmask_types or name in self.empty_bitvalues.values():
                    body = ' static constexpr bool kBitvalues = true; '
            elif category == 'Bitmask':
                flags = self.flags_types[name]
                bits = bitvalues.get(name, self.empty_bitvalues[flags])
                base = 'ApiElementBitmask<{}, {}{}, {}{}>'.format(args, elements, flags, elements, bits)
            elif category in ('Union', 'Handle', 'Funcpointer', 'Scalar', 'Void'):
                base = 'ApiElement{}<{}>'.format(category, args)
            else:
                base = 'ApiElementBase<{}, category::{}>'.format(args, category)
            write('struct {} : {} {{{}}};'.format(name, base, body), file=self.outFile)

        write('GFXRECON_END_NAMESPACE(api_elements)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()

    def get_deep_copy_excluded_api_elements(self):
        """Returns the deep-copy exclusions that are structure API elements, by name. An alias in the list has no
        API element and is dropped."""
        return [name for name in self.get_structure_api_elements() if name in self.deep_copy_exclusions]

    def get_enumerated_types(self):
        """Returns every enumerated type, by name. Its API element and its table have the same name."""
        return sorted(enum for enum in self.enum_names if self.is_enumerated(enum))

    def get_native_enumerated_types(self):
        """Returns the enumerated types that are C enums, by name: every enumerated type but the 64-bit flag-bits
        types, which C declares as typedefs of VkFlags64."""
        return [enum for enum in self.get_enumerated_types() if self.api_type_wire_kinds[self.get_api_element_name(enum)] == 'Enum']

    def get_wide_bitmask_pairs(self):
        """Returns (bits API element, typedef API element) for each 64-bit flag-bits type
        whose typedef has an API element."""
        return sorted(
            (enum, flags) for flags, enum in self.get_bitvalues_of_bitmasks().items()
            if flags in self.api_type_categories and self.api_type_wire_kinds[self.get_api_element_name(enum)] == 'Flags64'
        )

    def get_bitvalues_of_bitmasks(self):
        """Returns mask typedef API element name to the API element name of the bits enum whose values compose it.
        Source: the typedef's requires or bitvalues attribute in vk.xml, else the FlagBits-to-Flags name rule in
        get_flags_type_from_enum. Callers drop the typedefs that have no API element."""
        result = dict()
        for enum in self.get_enumerated_types():
            if enum not in self.bitmask_types:
                continue
            flags = self.get_flags_type_from_enum(enum)
            if flags is not None:
                result[self.get_api_element_name(flags)] = enum
        return result

    def get_structure_api_elements(self):
        """Returns every API element of category Struct that is not a union, by name."""
        return [
            name for name in sorted(self.api_type_categories)
            if self.api_type_categories[name] == 'Struct' and name not in self.all_union_members
        ]

    def get_union_api_elements(self):
        """Returns every union API element, by name."""
        return [name for name in sorted(self.api_type_categories) if self.api_type_categories[name] == 'Union']

    # Pairs each binding/vulkan_catalog.h list, read back from an inventory property, with the attribute holding the
    # generator's input, for the size checks.
    BINDING_CATALOG_LISTS = (
        ('external_structures', 'external_structs'),
        ('custom_encode_structures', 'custom_encode_structs'),
        ('custom_decode_structures', 'custom_decode_structs'),
        ('custom_handle_mapping_structures', 'custom_handle_mapping_structs'),
        ('generic_handle_structures', 'generic_handle_structs'),
        ('deep_copy_exclusions', 'deep_copy_exclusions'),
    )

    def get_binding_catalog_members(self, attribute):
        """Returns the members of one catalog input that are structure or union API elements, by name."""
        names = set(getattr(self, attribute))
        return [name for name in self.get_structure_api_elements() + self.get_union_api_elements() if name in names]

    def get_structure_type(self, name):
        """Returns the registry's structure type enumerant for a structure API element, or None for an alias or a
        structure without one."""
        if name in self.all_struct_aliases or name not in self.struct_type_names:
            return None
        return self.struct_type_names[name]

    def write_command_api_elements(self):
        write(
            '// Command API elements: one per command, named for the command without its vk prefix. Each is\n'
            '// the key for the command\'s Schema, binding::DecodedTypeOf and binding::CallId, and has no members.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(api_elements)', file=self.outFile)

        for command in self.schema_commands:
            write(
                'struct {} {{}};'.format(self.get_command_api_element_name(command)),
                file=self.outFile
            )

        write('GFXRECON_END_NAMESPACE(api_elements)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()

    def write_fields(self):
        write(
            '// Fields: one namespace per structure, union and command, holding one Field per member or\n'
            '// parameter, and a command\'s Return Field. A Field holds its declaration: its API element and the\n'
            '// declarators over it.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(fields)', file=self.outFile)
        self.newline()

        for struct in self.schema_structs:
            self.write_field_namespace(
                struct, self.all_struct_members[struct], struct, False
            )

        for union in self.schema_unions:
            self.write_field_namespace(
                union, self.all_union_members[union], union, False
            )

        for command in self.schema_commands:
            return_type, _, params = self.all_cmd_params[command]
            self.write_field_namespace(
                self.get_command_api_element_name(command),
                params,
                command,
                True,
                return_type=return_type
            )

        write('GFXRECON_END_NAMESPACE(fields)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()

    def write_schemas(self):
        write(
            "// A structure's Fields are the TypeList in the Schema specialization for its API element, in API order. A command's\n"
            "// are the same, ending with its Return Field. A union's Schema lists Alternatives instead.",
            file=self.outFile
        )
        self.newline()

        for struct in self.schema_structs:
            names = [value.name for value in self.all_struct_members[struct]]
            write(
                self.make_schema_specialization(
                    self.get_api_element_path(struct), struct, names
                ),
                file=self.outFile
            )
            self.newline()

        write('// A union\'s Schema lists Alternatives, not Fields: a value holds one of them, and which one is the', file=self.outFile)
        write('// selector\'s to say, so no field walk applies.', file=self.outFile)
        self.newline()

        for union in self.schema_unions:
            names = [value.name for value in self.all_union_members[union]]
            write(
                self.make_schema_specialization(
                    self.get_api_element_path(union), union, names, 'Alternatives'
                ),
                file=self.outFile
            )
            self.newline()

        for command in self.schema_commands:
            _, _, params = self.all_cmd_params[command]
            api_element = self.get_command_api_element_name(command)
            names = [value.name for value in params]
            names.append(self.RETURN_FIELD_NAME)
            write(
                self.make_schema_specialization(
                    'vulkan::api_elements::{}'.format(api_element), api_element, names
                ),
                file=self.outFile
            )
            self.newline()

    def get_inventory_handles(self):
        """Returns every handle API element but GenericHandle, by name. Each gets an encode::CaptureWrapperOf
        specialization from the inventory."""
        return [
            name for name in sorted(self.api_type_categories)
            if self.api_type_categories[name] == 'Handle' and name != self.GENERIC_HANDLE_DESCRIPTOR
        ]

    def get_inventory_enums(self):
        """Returns (name, is_flag_bits) for every C enum, by name."""
        return [(enum, enum in self.bitmask_types) for enum in self.get_native_enumerated_types()]

    INVENTORY_ROW_MACROS = (
        'GFXRECON_INVENTORY_VISIT_STRUCT(Name)',
        'GFXRECON_INVENTORY_VISIT_UNION(Name)',
        'GFXRECON_INVENTORY_VISIT_HANDLE(Name, Stem)',
        'GFXRECON_INVENTORY_VISIT_ENUM(Name)',
        'GFXRECON_INVENTORY_VISIT_FLAG_BITS(Name)',
        'GFXRECON_INVENTORY_VISIT_COMMAND(Name)',
    )

    # Lists the inventory properties: the macro suffix, the C++ name a visit reads the property back as, the banner's
    # one-line meaning, and the input the property is read from. A property is a fact the preprocessor cannot derive.
    # Its bit is its index here, so append a new property to keep every existing mask value.
    INVENTORY_PROPERTIES = (
        ('HAS_DECODED_TYPE', 'binding::ApiElementWithDecodedType',
         'binding::DecodedTypeOf maps it to its Decoded_ wrapper',
         'vk.xml: every structure with members but the two base structures'),
        ('MAY_REACH_HANDLES', 'no C++ reader',
         'a handle is reachable through its fields, pNext included',
         'vk.xml: a handle member, a generic handle, a pNext, or a member that can hold one'),
        ('EXTERNAL', 'binding::vulkan::catalog::external_structures',
         'a platform header defines it: an API element, no Schema',
         'platform_types.json "structs"'),
        ('CUSTOM_ENCODE', 'binding::vulkan::catalog::custom_encode_structures', 'its encoder is hand-written',
         'blacklists.json "structures" and "structures-encoder", plus platform_types.json "structs"'),
        ('CUSTOM_DECODE', 'binding::vulkan::catalog::custom_decode_structures', 'its decoder is hand-written',
         'blacklists.json "structures" and "structures-decoder", plus platform_types.json "structs"'),
        ('CUSTOM_HANDLE_MAPPING', 'binding::vulkan::catalog::custom_handle_mapping_structures',
         'its unwrap and map bodies are hand-written, or absent',
         'blacklists.json "structures" plus platform_types.json "structs" (STRUCT_BLACKLIST), and STRUCT_MAPPERS_BLACKLIST in vulkan_base_generator.py'),
        ('GENERIC_HANDLE', 'binding::vulkan::catalog::generic_handle_structures',
         'an integer member holds a handle; a sibling object-type member gives its type',
         'GENERIC_HANDLE_STRUCTS in vulkan_base_generator.py'),
        ('DEEP_COPY_EXCLUDED', 'binding::vulkan::catalog::deep_copy_exclusions', 'vulkan_struct_deep_copy does not handle it',
         'blacklists.json "structures-deep-copy"'),
        ('HAS_STRUCTURE_TYPE', 'schema::TypedStructApiElement',
         'it has a structure type, so a pNext chain can hold it',
         'vk.xml: a structure type'),
    )

    def inventory_property_macro(self, suffix):
        return 'GFXRECON_INVENTORY_{}'.format(suffix)

    def get_inventory_properties(self, name):
        """Returns the property suffixes of one structure or union inventory entry."""
        properties = []
        if name in self.schema_decodable_structs:
            properties.append('HAS_DECODED_TYPE')
        if self.may_reach_handles(name):
            properties.append('MAY_REACH_HANDLES')
        if name in self.external_structs:
            properties.append('EXTERNAL')
        if name in self.custom_encode_structs:
            properties.append('CUSTOM_ENCODE')
        if name in self.custom_decode_structs:
            properties.append('CUSTOM_DECODE')
        if name in self.custom_handle_mapping_structs:
            properties.append('CUSTOM_HANDLE_MAPPING')
        if name in self.generic_handle_structs:
            properties.append('GENERIC_HANDLE')
        if name in self.deep_copy_exclusions:
            properties.append('DEEP_COPY_EXCLUDED')
        if self.get_structure_type(name) is not None:
            properties.append('HAS_STRUCTURE_TYPE')
        return properties

    def get_inventory_groups(self, names):
        """Returns the inventory entries grouped by property set, as (property suffixes, names), in the bit order
        of each set."""
        order = [suffix for suffix, _, _, _ in self.INVENTORY_PROPERTIES]
        groups = dict()
        for name in names:
            properties = tuple(self.get_inventory_properties(name))
            groups.setdefault(properties, []).append(name)
        return sorted(groups.items(), key=lambda item: sum(1 << order.index(suffix) for suffix in item[0]))

    def write_inventory(self):
        """Writes the inventory: one macro call per structure, union, handle, C enum and command, for a consumer to
        expand into its own declarations."""
        banner = [
            '// THIS FILE IS A LIST, NOT A HEADER. IT HAS NO INCLUDE GUARD, AND IT DECLARES NOTHING.',
            '//',
            '// It holds one macro call per Vulkan structure, union, handle, C enum and command, and nothing else: no',
            '// declarations, no namespace, no includes. It does not define the macros it calls: define them, include',
            '// this file, and each macro call expands into what you defined. Include it once per thing you build from',
            '// the list, inside the namespace the result belongs in.',
            '//',
            '// To use it:',
            '//   1. Define the visit macros for the categories you want:',
            '//        GFXRECON_INVENTORY_VISIT_STRUCT(Name)      GFXRECON_INVENTORY_VISIT_UNION(Name)',
            '//        GFXRECON_INVENTORY_VISIT_HANDLE(Name, Stem)',
            '//        GFXRECON_INVENTORY_VISIT_ENUM(Name)        GFXRECON_INVENTORY_VISIT_FLAG_BITS(Name)',
            '//        GFXRECON_INVENTORY_VISIT_COMMAND(Name)',
            '//      A category you leave undefined expands to nothing. Defining none is an error.',
            '//   2. Optionally define GFXRECON_INVENTORY_REQUIRE and GFXRECON_INVENTORY_FORBID as masks of the',
            '//      inventory properties below. A structure or union inventory entry expands only if it has every',
            '//      REQUIRE property and no FORBID property. Both default to 0. Handles, enumerated types and',
            '//      commands carry no properties and are not filtered.',
            '//   3. #include "generated/generated_vulkan_inventory.h"',
            '// Every visit, REQUIRE and FORBID definition is #undef\'d at the end, so the next include starts clean. The',
            '// property macros stay defined.',
            '//',
            '// Where to put a new expansion: one that yields types, specializations, aliases or declarations',
            '// goes in a header, since the compiler needs them wherever the type is asked for. One that yields',
            '// definitions with linkage, explicit instantiations or function bodies goes in one .cpp -- in a',
            '// header, every includer would define them again.',
            '//',
            '// Inventory properties: the mask macro, the C++ name a visit reads it back as, its meaning, and the input it',
            '// is read from. The json files and vulkan_base_generator.py are in',
            '// framework/generated/khronos_generators/vulkan_generators/.',
        ]
        width = max(len(self.inventory_property_macro(suffix)) for suffix, _, _, _ in self.INVENTORY_PROPERTIES)
        reader_width = max(len(reader) for _, reader, _, _ in self.INVENTORY_PROPERTIES)
        for suffix, reader, meaning, source in self.INVENTORY_PROPERTIES:
            banner.append('//   {:<{}}  {:<{}}  {} -- {}'.format(self.inventory_property_macro(suffix), width, reader, reader_width, meaning, source))
        banner.extend((
            '//',
            '// To read the list as C++, use the catalog, binding/vulkan_catalog.h, not this file.',
            '',
        ))

        prologue = ['#if {}'.format(' && '.join('!defined({})'.format(macro.split('(')[0]) for macro in self.INVENTORY_ROW_MACROS))]
        prologue.append('#error "generated_vulkan_inventory.h expands visit macros the includer defines; define at least one before including it"')
        prologue.append('#endif')
        for macro in self.INVENTORY_ROW_MACROS:
            name = macro.split('(')[0]
            prologue.extend(('#ifndef {}'.format(name), '#define {}'.format(macro), '#endif'))
        prologue.append('#ifndef {}'.format(self.inventory_property_macro(self.INVENTORY_PROPERTIES[0][0])))
        for bit, (suffix, _, _, _) in enumerate(self.INVENTORY_PROPERTIES):
            prologue.append('#define {} 0x{:x}'.format(self.inventory_property_macro(suffix), 1 << bit))
        prologue.append('#endif')
        prologue.extend((
            '#ifndef GFXRECON_INVENTORY_REQUIRE',
            '#define GFXRECON_INVENTORY_REQUIRE 0',
            '#endif',
            '#ifndef GFXRECON_INVENTORY_FORBID',
            '#define GFXRECON_INVENTORY_FORBID 0',
            '#endif',
            '#define GFXRECON_INVENTORY_SELECT(props) \\',
            '    ((((props) & GFXRECON_INVENTORY_REQUIRE) == GFXRECON_INVENTORY_REQUIRE) && !((props) & GFXRECON_INVENTORY_FORBID))',
            '',
        ))

        body = banner + prologue

        for category, macro, names in (
            ('Structures', 'GFXRECON_INVENTORY_VISIT_STRUCT', self.get_structure_api_elements()),
            ('Unions', 'GFXRECON_INVENTORY_VISIT_UNION', self.get_union_api_elements()),
        ):
            body.append('// {}, by API element name, grouped by property set.'.format(category))
            for properties, rows in self.get_inventory_groups(names):
                mask = ' | '.join(self.inventory_property_macro(suffix) for suffix in properties) or '0'
                body.append('')
                body.append('// {}: {}'.format(len(rows), ', '.join(properties) if properties else 'no properties'))
                body.append('#if GFXRECON_INVENTORY_SELECT({})'.format(mask))
                body.extend('{}({})'.format(macro, row) for row in rows)
                body.append('#endif')
            body.append('')

        body.append('// Handles. Stem is the handle name without its Vk prefix; vulkan_encode_capture_wrappers.h pastes Stem##Wrapper.')
        for handle in self.get_inventory_handles():
            body.append('GFXRECON_INVENTORY_VISIT_HANDLE({}, {})'.format(handle, handle[2:]))
        body.append('')

        body.append('// C enums: FLAG_BITS for a flag-bits enum, whose values compose into a mask, ENUM for every other enum.')
        for enum, is_flag_bits in self.get_inventory_enums():
            body.append('GFXRECON_INVENTORY_VISIT_{}({})'.format('FLAG_BITS' if is_flag_bits else 'ENUM', enum))
        body.append('')

        body.append('// Commands, by API element name: the command name without its vk prefix.')
        for command in self.schema_commands:
            body.append('GFXRECON_INVENTORY_VISIT_COMMAND({})'.format(self.get_command_api_element_name(command)))
        body.append('')

        for macro in self.INVENTORY_ROW_MACROS:
            body.append('#undef {}'.format(macro.split('(')[0]))
        body.extend(('#undef GFXRECON_INVENTORY_REQUIRE', '#undef GFXRECON_INVENTORY_FORBID', '#undef GFXRECON_INVENTORY_SELECT'))

        write('\n'.join(body), file=self.outFile)

    def write_checks(self):
        """Writes the static checks over the generated schema, compiled into gfxrecon_framework_test."""
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()

        write('// Every structure has a well formed schema, and no structure has a return Field.', file=self.outFile)

        for struct in self.schema_structs:
            element = 'schema::{}'.format(self.get_api_element_path(struct))
            write('static_assert(schema::HasSchemaFields<{}>);'.format(element), file=self.outFile)
            write('static_assert(!schema::HasCommandSchema<{}>);'.format(element), file=self.outFile)

        self.newline()
        write('// Every union has a Schema of Alternatives and no Fields.', file=self.outFile)

        for union in self.schema_unions:
            element = 'schema::{}'.format(self.get_api_element_path(union))
            write('static_assert(schema::UnionApiElement<{}>);'.format(element), file=self.outFile)
            write('static_assert(util::IsTypeList_v<schema::Schema<{}>::Alternatives>);'.format(element), file=self.outFile)
            write('static_assert(!schema::HasSchemaFields<{}>);'.format(element), file=self.outFile)

        self.newline()
        write(
            '// Every command schema has exactly one return Field, which is what HasCommandSchema tests through',
            file=self.outFile
        )
        write('// TypeListSole_t.', file=self.outFile)

        for command in self.schema_commands:
            api_element = 'schema::vulkan::api_elements::{}'.format(self.get_command_api_element_name(command))
            write('static_assert(schema::HasCommandSchema<{}>);'.format(api_element), file=self.outFile)

        self.newline()
        write(
            '// Decoded_X::api_element and args::X::api_element, from the struct-decoders and args generators,\n'
            '// against binding::DecodedTypeOf, which binding/vulkan_decoded_type.h builds from the inventory. A\n'
            '// mis-paired line in either fails here.',
            file=self.outFile
        )

        for struct in self.wrapper_structs:
            write(
                'static_assert(std::is_same_v<binding::DecodedTypeOf_t<typename Decoded_{name}::api_element>, '
                'Decoded_{name}>);'.format(name=struct),
                file=self.outFile
            )

        self.newline()

        for command in self.schema_commands:
            api_element = self.get_command_api_element_name(command)
            write(
                'static_assert(std::is_same_v<binding::DecodedTypeOf_t<typename args::{api_element}::api_element>, '
                'args::{api_element}>);'.format(api_element=api_element),
                file=self.outFile
            )

        self.newline()
        write(
            '// The API element\'s element_type against Decoded_X::struct_type, which the struct-decoders generator\n'
            '// writes from the registry name, not from the schema.',
            file=self.outFile
        )

        for struct in self.wrapper_structs:
            write(
                'static_assert(std::is_same_v<schema::ApiTypeOf_t<schema::{path}>, '
                'typename Decoded_{name}::struct_type>);'.format(
                    path=self.get_api_element_path(struct), name=struct
                ),
                file=self.outFile
            )

        self.newline()
        write('// Each structure and union member\'s C++ type against ApiTypeOf_t of its Field\'s declaration. ApiTypeOf_t', file=self.outFile)
        write('// rebuilds the C type from the API element and the declarators -- const at each level, a star per Pointer', file=self.outFile)
        write('// or Array, an extent per FixedArray -- so a header revision that changes a member fails here. Commands', file=self.outFile)
        write('// are not checked: a parameter has no member to compare against. Skipped: the base structures\' pNext,', file=self.outFile)
        write('// which the header types as the base structure and the schema as the chain.', file=self.outFile)

        for struct in self.schema_structs + self.schema_unions:
            for value in self.all_struct_members.get(struct, self.all_union_members.get(struct)):
                if self.is_extension_chain(value) and self.resolve_type_alias(value.base_type) in self.get_base_structs():
                    continue

                write(
                    'static_assert(std::is_same_v<decltype({struct}::{name}), schema::ApiTypeOf_t<{field}::declaration>>);'.format(
                        struct=struct, name=value.name, field='schema::' + self.get_field_path(struct, value.name)
                    ),
                    file=self.outFile
                )

        self.newline()
        write('// sizeof each API element == sizeof its WireTypeOf: an API element narrower than its wire type would', file=self.outFile)
        write('// compile and desynchronize the stream. Skipped: size_t (4 or 8 bytes in memory, 8 on the wire, which', file=self.outFile)
        write('// ValueDecoder converts), text, and the kinds with no generated WireTypeOf (handle, funcpointer and', file=self.outFile)
        write('// opaque are recorded as 64-bit identifiers or addresses; struct and void have no width).', file=self.outFile)

        for name in sorted(self.api_type_wire_kinds):
            kind = self.api_type_wire_kinds[name]

            if kind not in self.WIRE_TYPES or kind in ('SizeT', 'Char', 'WChar'):
                continue

            write(
                'static_assert(sizeof(schema::ApiTypeOf_t<schema::vulkan::api_elements::{name}>) == '
                'sizeof(binding::WireTypeOf_t<schema::vulkan::api_elements::{name}>));'.format(name=name),
                file=self.outFile
            )

        self.newline()
        write('// The encoder captures a refined typedef by its basetype, so a refined API element records the same bytes', file=self.outFile)
        write('// as the primitive it refines.', file=self.outFile)

        for type_name in sorted(self.CURATED_CATEGORIES):
            primitive = self.get_underlying_primitive(type_name)

            if primitive is None or primitive == type_name:
                continue

            write(
                'static_assert(std::is_same_v<binding::WireTypeOf_t<schema::vulkan::api_elements::{}>, '
                'binding::WireTypeOf_t<schema::vulkan::api_elements::{}>>);'.format(
                    self.get_api_element_name(type_name), self.get_api_element_name(primitive)
                ),
                file=self.outFile
            )

        self.newline()
        self.newline()
        write('// The HAS_STRUCTURE_TYPE inventory property against the API element\'s structure_type member: two emissions', file=self.outFile)
        write('// of one vk.xml fact, checked against each other on every structure and union inventory entry.', file=self.outFile)
        write('#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_HAS_STRUCTURE_TYPE', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) static_assert(schema::TypedStructApiElement<schema::vulkan::api_elements::Name>);', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)', file=self.outFile)
        write('#include "generated/generated_vulkan_inventory.h"', file=self.outFile)
        write('#define GFXRECON_INVENTORY_FORBID GFXRECON_INVENTORY_HAS_STRUCTURE_TYPE', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) static_assert(!schema::TypedStructApiElement<schema::vulkan::api_elements::Name>);', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)', file=self.outFile)
        write('#include "generated/generated_vulkan_inventory.h"', file=self.outFile)

        typed = sum(1 for struct in self.get_structure_api_elements() if self.get_structure_type(struct) is not None)

        self.newline()
        write('// Catalog list sizes against the counts this generator computed.', file=self.outFile)
        write(
            'constexpr size_t kStructuresCount = util::TypeListSize_v<binding::vulkan::catalog::structures>;\n' +
            'static_assert(kStructuresCount == {});'.format(len(self.get_structure_api_elements())),
            file=self.outFile
        )
        write(
            'constexpr size_t kUnionsCount = util::TypeListSize_v<binding::vulkan::catalog::unions>;\n' +
            'static_assert(kUnionsCount == {});'.format(len(self.get_union_api_elements())),
            file=self.outFile
        )
        write(
            'static_assert(util::TypeListSize_v<binding::vulkan::catalog::extensible_structures> == {});'.format(typed),
            file=self.outFile
        )

        excluded = self.get_deep_copy_excluded_api_elements()
        excluded_typed = [name for name in excluded if self.get_structure_type(name) is not None]
        write(
            'static_assert(util::TypeListSize_v<binding::vulkan::catalog::deep_copyable_structures> == {});'.format(typed - len(excluded_typed)),
            file=self.outFile
        )

        self.newline()
        write('// Each enumerated type\'s API element refers to its table, and each but a 64-bit flag-bits type is the', file=self.outFile)
        write('// binding::ApiElementOf of its C enum.', file=self.outFile)

        for enum in self.get_enumerated_types():
            element = 'schema::{}'.format(self.get_api_element_path(enum))
            write('static_assert(schema::EnumApiElement<{}>);'.format(element), file=self.outFile)
            if not self.is_flags_enum_64bit(enum):
                write(
                    'static_assert(std::is_same_v<binding::ApiElementOf<::{}>::type, {}>);'.format(enum, element),
                    file=self.outFile
                )
        self.newline()
        write('// The registry declares a group a bitmask exactly when its name says FlagBits. The two are separate sources,', file=self.outFile)
        write('// so a group that breaks the convention fails here by name.', file=self.outFile)
        for enum in self.get_enumerated_types():
            element = 'schema::{}'.format(self.get_api_element_path(enum))
            write(
                'static_assert({}schema::BitvaluesApiElement<{}>);'.format('' if 'FlagBits' in enum else '!', element),
                file=self.outFile
            )
        self.newline()
        write('// Each mask typedef\'s element_type is its flags_type\'s, and is as wide as its bits enum: vk.xml states the', file=self.outFile)
        write('// width twice, in the typedef\'s base type and in the bits group\'s bitwidth.', file=self.outFile)
        for flags, enum in sorted(self.get_bitvalues_of_bitmasks().items()):
            if flags not in self.api_type_categories:
                continue
            element = 'schema::{}'.format(self.get_api_element_path(flags))
            write(
                'static_assert(std::is_same_v<{0}::element_type, {0}::flags_type::element_type>);'.format(element),
                file=self.outFile
            )
            write(
                'static_assert(sizeof({0}::element_type) == sizeof({0}::bitvalues::element_type));'.format(element),
                file=self.outFile
            )
        self.newline()
        write('// No binding::ApiElementOf for uint32_t or uint64_t: every 32-bit mask typedef is uint32_t, and every 64-bit', file=self.outFile)
        write('// mask and flag-bits typedef is uint64_t, so one C type cannot select one API element.', file=self.outFile)
        write('static_assert(!binding::ApiTypeWithApiElement<uint32_t>);', file=self.outFile)
        write('static_assert(!binding::ApiTypeWithApiElement<uint64_t>);', file=self.outFile)

        self.newline()
        write('// The catalog: each list, read back from an inventory property, is the size of the input the', file=self.outFile)
        write('// generator carried into that property.', file=self.outFile)
        for name, attribute in self.BINDING_CATALOG_LISTS:
            write(
                'static_assert(util::TypeListSize_v<binding::vulkan::catalog::{}> == {});'.format(
                    name, len(self.get_binding_catalog_members(attribute))
                ),
                file=self.outFile
            )

        self.newline()
        write('// Inventory entry counts per category against the catalog and this generator\'s model. An entry the', file=self.outFile)
        write('// generator dropped or doubled fails here by count.', file=self.outFile)
        enums = self.get_inventory_enums()
        for name, macro, expected in (
            ('kInventoryStructs', 'GFXRECON_INVENTORY_VISIT_STRUCT', 'kStructuresCount'),
            ('kInventoryUnions', 'GFXRECON_INVENTORY_VISIT_UNION', 'kUnionsCount'),
            ('kInventoryHandles', 'GFXRECON_INVENTORY_VISIT_HANDLE', len(self.get_inventory_handles())),
            ('kInventoryEnums', 'GFXRECON_INVENTORY_VISIT_ENUM', sum(1 for _, bits in enums if not bits)),
            ('kInventoryFlagBits', 'GFXRECON_INVENTORY_VISIT_FLAG_BITS', sum(1 for _, bits in enums if bits)),
            ('kInventoryCommands', 'GFXRECON_INVENTORY_VISIT_COMMAND', len(self.schema_commands)),
        ):
            write('#define {}(...) +1'.format(macro), file=self.outFile)
            write('constexpr size_t {} = 0'.format(name), file=self.outFile)
            write('#include "generated/generated_vulkan_inventory.h"', file=self.outFile)
            write(';', file=self.outFile)
            write('static_assert({} == {});'.format(name, expected), file=self.outFile)

        self.newline()
        write('// EXTERNAL against the Schemas: EXTERNAL comes from platform_types.json and a Schema from the members', file=self.outFile)
        write('// vk.xml gives, so an external structure has no Schema and every other structure and union has one.', file=self.outFile)
        write('#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_EXTERNAL', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) static_assert(!schema::HasSchemaFields<schema::vulkan::api_elements::Name> && !schema::UnionApiElement<schema::vulkan::api_elements::Name>);', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)', file=self.outFile)
        write('#include "generated/generated_vulkan_inventory.h"', file=self.outFile)
        write('#define GFXRECON_INVENTORY_FORBID GFXRECON_INVENTORY_EXTERNAL', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) static_assert(schema::HasSchemaFields<schema::vulkan::api_elements::Name> || schema::UnionApiElement<schema::vulkan::api_elements::Name>);', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)', file=self.outFile)
        write('#include "generated/generated_vulkan_inventory.h"', file=self.outFile)

        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)

    def write_member_partition_prologue(self, description):
        write('// {}'.format(description), file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(schema)', file=self.outFile)
        self.newline()

    def write_member_partition_epilogue(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(schema)', file=self.outFile)

    def make_member_pointer(self, storage, field, member_expression):
        return (
            'template <> struct MemberPointer<{storage}, {field}> '
            '{{ static constexpr auto value = &{member}; }};'.format(
                storage=storage, field=field, member=member_expression
            )
        )

    def make_bitfield_member_pointer(self, storage, field, member_name, value_type):
        """Returns the MemberPointer specialization for a bitfield member, which has no pointer to member: it derives
        from NonAddressableMember, whose value marks it, and supplies static Get and Set."""
        return (
            'template <> struct MemberPointer<{storage}, {field}> : NonAddressableMember '
            '{{ static {type} Get(const {storage}& storage) {{ return storage.{member}; }} '
            'static void Set({storage}& storage, {type} value) {{ storage.{member} = value; }} }};'.format(
                storage=storage, field=field, member=member_name, type=value_type
            )
        )

    def write_api_struct_members(self):
        self.write_member_partition_prologue(
            'Member traits for API structure storage.'
        )

        for struct in self.schema_structs + self.schema_unions:
            storage = '::{}'.format(struct)

            for value in self.all_struct_members.get(struct, self.all_union_members.get(struct)):
                field = self.get_field_path(struct, value.name)

                if value.bitfield_width:
                    write(
                        self.make_bitfield_member_pointer(
                            storage, field, value.name, value.base_type
                        ),
                        file=self.outFile
                    )
                else:
                    write(
                        self.make_member_pointer(
                            storage, field,
                            '{}::{}'.format(storage, value.name)
                        ),
                        file=self.outFile
                    )

        self.write_member_partition_epilogue()

    def write_decoded_struct_members(self):
        self.write_member_partition_prologue(
            'Member traits for decoded structure storage.'
        )

        for struct in self.wrapper_structs:
            storage = 'decode::Decoded_{}'.format(struct)

            for value in self.all_struct_members[struct]:
                # A decoded wrapper holds a member only for a field that decode has to expand. A plain scalar stays in
                # the wrapped API structure, so it has no mapping in this population.
                if not self.is_extended_struct_definition(
                    value
                ) and not KhronosStructDecodersHeaderGenerator.needs_member_declaration(
                    self, struct, value
                ):
                    continue

                write(
                    self.make_member_pointer(
                        storage, self.get_field_path(struct, value.name),
                        '{}::{}'.format(storage, value.name)
                    ),
                    file=self.outFile
                )

        self.write_member_partition_epilogue()

    def write_decoded_command_members(self):
        self.write_member_partition_prologue(
            'Member traits for decoded command-wrapper storage.'
        )

        for command in self.schema_commands:
            return_type, _, params = self.all_cmd_params[command]
            api_element = self.get_command_api_element_name(command)
            storage = 'decode::args::{}'.format(api_element)

            for value in params:
                write(
                    self.make_member_pointer(
                        storage, self.get_field_path(api_element, value.name),
                        '{}::{}'.format(storage, value.name)
                    ),
                    file=self.outFile
                )

            # A void Return Field has no storage member, so it has no mapping.
            if self.clean_return_type(return_type) != 'void':
                write(
                    self.make_member_pointer(
                        storage,
                        self.get_field_path(api_element, self.RETURN_FIELD_NAME),
                        '{}::{}'.format(storage, self.RETURN_FIELD_NAME)
                    ),
                    file=self.outFile
                )

        self.write_member_partition_epilogue()


class VulkanSchemaTypesGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema_types.h: the API elements and command API elements."""

    def write_part(self):
        self.write_schema_part(self.write_api_elements, self.write_command_api_elements)


class VulkanSchemaEnumerantsGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema_enumerants.h: the enumerant table of every enumerated type."""

    def write_part(self):
        write('// Enumerant tables: one per enumerated type, in vk.xml order, with the name the API spells. A flag-bits', file=self.outFile)
        write('// table holds single bits, combined masks and zero alike: lookups go from value to name, so they are not', file=self.outFile)
        write('// told apart. An alias adds no entry. Each table is a struct named for its type, holding Enumerant<API element>', file=self.outFile)
        write('// entries.', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(schema)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(enumerants)', file=self.outFile)
        self.newline()

        for enum in self.get_enumerated_types():
            enumerants = self.enumEnumerants[enum]
            entry = 'binding::Enumerant<{}>'.format(self.get_api_element_reference(self.get_api_element_name(enum)))
            write('struct {}'.format(enum), file=self.outFile)
            write('{', file=self.outFile)
            if enumerants:
                write(
                    '    static constexpr std::array<{}, {}> entries = {{ {{'.format(entry, len(enumerants)),
                    file=self.outFile
                )
                for enumerant in enumerants:
                    write('        {{ {0}, "{0}" }},'.format(enumerant), file=self.outFile)
                write('    } };', file=self.outFile)
            else:
                write('    static constexpr std::array<{}, 0> entries{{}};'.format(entry), file=self.outFile)
            write('};', file=self.outFile)
            self.newline()

        write('// EmptyBitvalues and EmptyBitvalues64 are the empty tables for a mask the registry gives no bits enum.', file=self.outFile)
        for name in sorted(self.empty_bitvalues.values()):
            entry = 'binding::Enumerant<{}>'.format(self.get_api_element_reference(name))
            write('struct {}'.format(name), file=self.outFile)
            write('{', file=self.outFile)
            write('    static constexpr std::array<{}, 0> entries{{}};'.format(entry), file=self.outFile)
            write('};', file=self.outFile)
            self.newline()

        write('GFXRECON_END_NAMESPACE(enumerants)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(schema)', file=self.outFile)


class VulkanWireTypesGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_wire_types.h: the WireTypeOf specializations
    of the scalar, enum and text API elements."""

    def write_part(self):
        write('// WireTypeOf for the scalar, enum and text API elements: the format typedef each is recorded as. Bitmask,', file=self.outFile)
        write('// handle, funcpointer and opaque are partial specializations in binding/wire_type_of.h; struct and void', file=self.outFile)
        write('// have no width of their own.', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(binding)', file=self.outFile)
        self.newline()

        for name in sorted(self.api_type_wire_kinds):
            kind = self.api_type_wire_kinds[name]

            if kind not in self.WIRE_TYPES or self.api_type_categories[name] == 'Bitmask':
                continue

            write(
                'template <> struct WireTypeOf<schema::vulkan::api_elements::{}> {{ using type = format::{}; }};'.format(
                    name, self.WIRE_TYPES[kind]
                ),
                file=self.outFile
            )

        self.newline()
        write('GFXRECON_END_NAMESPACE(binding)', file=self.outFile)


class VulkanEnumToStringBodyGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_enum_to_string.cpp: the ToString specializations
    and the 64-bit explicit instantiations."""

    def write_part(self):
        api_data = self.get_api_data()
        write('GFXRECON_BEGIN_NAMESPACE(util)', file=self.outFile)
        self.newline()
        write('// One line per enum: the lookup over its table. A mask enum also expands a {}.'.format(api_data.flags_type), file=self.outFile)
        for enum in self.get_native_enumerated_types():
            table = 'schema::vulkan::enumerants::{}'.format(enum)
            write(
                'template <> std::string ToString<{0}>(const {0}& value, ToStringFlags, uint32_t, uint32_t) {{ return detail::EnumerantToString<{1}>(value); }}'.format(enum, table),
                file=self.outFile
            )
            if enum in self.bitmask_types:
                write(
                    'template <> std::string ToString<{0}>({1} vkFlags, ToStringFlags, uint32_t, uint32_t) {{ return detail::EnumerantMaskToString<{2}>(vkFlags); }}'.format(enum, api_data.flags_type, table),
                    file=self.outFile
                )
        self.newline()
        write('// ToString<bits API element>(VkFlags64) returns the name of one bit. ToString<mask API element>(VkFlags64) returns the',
              file=self.outFile)
        write("// names of all set bits joined with '|', or the zero value's name when none is set.", file=self.outFile)
        for bits, flags in self.get_wide_bitmask_pairs():
            for api_element in (bits, flags):
                write(
                    'template std::string ToString<schema::vulkan::api_elements::{0}>({1}, ToStringFlags, uint32_t, uint32_t);'.format(api_element, api_data.flags_64_type),
                    file=self.outFile
                )
        self.newline()
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)


class VulkanSchemaFieldsGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema_fields.h: the Fields."""

    def write_part(self):
        self.write_schema_part(self.write_fields)


class VulkanSchemaGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema.h: the Schema specializations that order the Fields."""

    def write_part(self):
        self.write_schema_part(self.write_schemas)


class VulkanInventoryGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_inventory.h, the one list every visitor expands."""

    def write_part(self):
        self.write_inventory()


class VulkanSchemaApiStructMembersGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema_api_struct_members.h: the MemberPointer
    specializations keyed on the API structures."""

    def write_part(self):
        self.write_api_struct_members()


class VulkanSchemaDecodedStructMembersGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema_decoded_struct_members.h: the MemberPointer specializations keyed on
    the Decoded_ wrappers."""

    def write_part(self):
        self.write_decoded_struct_members()


class VulkanSchemaDecodedCommandMembersGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema_decoded_command_members.h: the MemberPointer specializations keyed on
    the decode::args structures."""

    def write_part(self):
        self.write_decoded_command_members()


class VulkanSchemaChecksGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema_checks.cpp, the cross-generator agreement checks. Compiling the
    result is the test."""

    def write_part(self):
        self.write_checks()


