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
"""Generate the Vulkan field schema described by the generic field schema and action model.

One generator emits every part of the schema from one field-order model, so no output owns a separate field order.
The parts are separate files so that each includer pays for what it names and no more. The schema itself is three
files in a strict include order: types (API elements and command API elements) is what anything naming an API
element needs; fields (Fields) is what an Action's member traits need; schema (the Schema
specializations) is what the field walk needs. The member traits are partitioned further by storage population, and
only the target that owns an operation includes the population it reads.

This is the initial version. It emits:

    one API element for each registry type that a Field names or a Schema keys on
    one command API element for each command
    one Field for each command parameter and structure member
    one Return Field for each command, including a VoidReturn Return Field for a void command
    one Schema specialization for each command and each structure the registry gives members, and one of
    Alternatives for each union
    one decoded representation trait for each structure and each command; the inverse is the api_element member
    the wrapper and args generators emit
    one member trait for each valid storage and Field pair, in three storage populations

One rule governs what the elements state: the schema states the type the API header declares and the facts the
registry and the curated tables give, and invents no abstraction over them that would be more brittle than they
are. So a platform typedef the base generator substitutes, DWORD for uint32_t, keeps an element of its own, named
and typed as the header spells it, with the substitution recorded as the element's category.

It does not yet emit:

    semantic metadata, on either the API element or the Field
    capture_wrapper_type on a handle API element, which needs an authoritative handle to wrapper mapping
    formal API-signature storage and its member traits, and the decoded metadata storage population
    runtime dispatch tables, custom hooks, command lifecycle traits, or the args compatibility bindings

Two Field properties differ from the design text, because the registry forces the difference:

    The name property is emitted as field_name. Vulkan declares members called 'name', and a class member cannot
    share the name of its enclosing class.
    A field's declaration is its API element, or Const, Pointer, Array or FixedArray over a declaration, as the C
    declarator nests; the generator reads the header's spelling from the registry's full type, so each level's const
    lands where the header wrote it. The shape concepts read the declaration; no shape tag is emitted.
"""

import json
import sys
from generator import noneStr
from khronos_base_generator import write
from khronos_struct_decoders_header_generator import KhronosStructDecodersHeaderGenerator
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions

class VulkanSchemaBaseGeneratorOptions(VulkanBaseGeneratorOptions):
    """Shared options for every part of the Vulkan field schema. One subclass for each generated file, which is
    what add_part_headers exists to let each one state.
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

        # A command API element is named for the command with its API prefix removed, and the Windows headers define
        # macros for two of the resulting names. Every part shares this treatment, so an API element spells the same in
        # all of them.
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

        # The generated content opens its own inner namespaces, because one file spans gfxrecon::schema and
        # gfxrecon::decode.
        begin_end.namespaces.append('gfxrecon')

    def add_part_headers(self, begin_end):
        """Name the headers this part's generated file needs. One override for each generated file."""
        raise NotImplementedError


class VulkanSchemaTypesGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the API elements and command API elements. This is the public face of the schema: an API element is
    the key every trait and Schema is looked up by, and a wrapper can name its own. It needs the API headers and the
    categories in format/format.h, and nothing else.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'format/format.h',
            'format/platform_types.h',
            'schema/api_element.h',
            'util/defines.h',
            'util/type_list.h',
        ))
        begin_end.system_headers.append('string_view')


class VulkanSchemaFieldsGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the Fields. A Field names its API element and a shape, so this needs the types
    file and schema/field.h. Nothing outside an Action's member traits has a reason to name a Field.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_types.h',
            'schema/field.h',
            'util/defines.h',
        ))
        begin_end.system_headers.extend(('array', 'cstddef', 'string_view'))


class VulkanSchemaGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the Schema specializations that order the Fields. Only the field walk names a Schema, so only
    the translation unit that compiles the walk includes this.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_fields.h',
            'schema/schema.h',
            'util/defines.h',
            'util/type_list.h',
        ))


class VulkanInventoryGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for the inventory: a header with no include guard, no headers and no namespace, so that a consumer
    can include it inside its own namespace with its own visit macros defined, once per thing it builds.
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
    """Shared options for a member-trait partition: one file for each storage population. A subclass adds the
    declarations of the storage type it is keyed on.
    """

    def storage_headers(self):
        """The headers declaring this partition's storage types, empty when the API headers already supply them."""
        return ()

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_fields.h',
            'util/defines.h',
            'schema/field.h',
        ))

        begin_end.specific_headers.extend(self.storage_headers())

        begin_end.specific_headers.sort()

        # A member-trait partition is target-private. Say so in the generated file, since that is what a reader
        # reaching for the include will open.
        begin_end.pre_namespace_code.extend((
            '// TARGET-PRIVATE. Include this only from the one implementation header that owns an operation',
            '// family, and include the whole set of partitions that operation reads. Do not include it from a',
            '// header other targets pull in.',
            '//',
            '// An operation constrains its Apply overloads on these specializations. A translation unit that',
            '// sees some of them and not others still compiles: the constraints simply answer no, and the same',
            '// call resolves to a different overload than it does next door. Nothing diagnoses that. Keeping',
            '// the include in one place is what makes the partial state unreachable -- and the partitions exist',
            '// to keep this weight out of translation units that do not read it, which spreading the include',
            '// around also defeats.',
            '',
        ))


class VulkanSchemaNativeStructMembersGeneratorOptions(
    VulkanSchemaMemberPartitionGeneratorOptions
):
    """Options for the member traits keyed on the native API structure. The API headers declare it."""


class VulkanSchemaDecodedStructMembersGeneratorOptions(
    VulkanSchemaMemberPartitionGeneratorOptions
):
    """Options for the member traits keyed on the decoded structure wrapper."""

    def storage_headers(self):
        return ('generated/generated_vulkan_struct_decoders.h', )


class VulkanSchemaDecodedCommandMembersGeneratorOptions(
    VulkanSchemaMemberPartitionGeneratorOptions
):
    """Options for the member traits keyed on a command's decoded argument storage. The args namespace is split
    across a generated header and a hand-written one, and the command whose decoder is hand-written has its args
    structure in the second.
    """

    def storage_headers(self):
        return ('decode/vulkan_decoder_args.h', 'generated/generated_vulkan_decoder_args.h')


class VulkanSchemaEnumerantsGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the enumerant tables: one per enumerated type, value and name in registry order. The index and the
    name lookup over them are hand-written in binding/enumerants.h.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'binding/enumerants.h',
            'format/platform_types.h',
            'generated/generated_vulkan_schema_types.h',
            'util/defines.h',
        ))


class VulkanEnumToStringBodyGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the enum ToString definitions, one line each over the enumerant tables, and the explicit
    instantiations of the API element-keyed forms for the 64-bit flag-bits types. The bodies they forward to are in
    util/vulkan_enum_to_string_impl.h, which only this file includes."""

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_enumerants.h',
            'generated/generated_vulkan_schema_types.h',
            'util/defines.h',
            'util/vulkan_enum_to_string_impl.h',
        ))


class VulkanSchemaChecksGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the cross-generator agreement checks. Compiled only by the framework test target, so it costs a
    product build nothing and can include whatever it needs to check. Compiling it is the test; there is nothing to
    run.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'binding/enumerants.h',
            'binding/vulkan_call_id.h',
            'binding/vulkan_decoded_type.h',
            'binding/vulkan_api_element_of.h',
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
    """Shared model for every part of the Vulkan field schema. One subclass for each generated file: the model is
    built here and write_part decides which of it that file carries.
    """

    # Registry type to logical category, for the primitive spellings the base generator does not already classify. The
    # fixed-width integers come from KhronosBaseGenerator.encode_types; these five are the ones it lacks.
    PRIMITIVE_CATEGORIES = {
        'int': 'Int32',
        'float': 'Float',
        'double': 'Double',
        'char': 'Char',
        'wchar_t': 'WChar',
    }

    # The refinements. This is curated data about the API rather than generator logic: the registry does not say
    # which types carry a category of their own, so it comes from GFXReconstruct's hand-written encoder, and it is the
    # content a data file beside blacklists.json would hold.
    #
    # The three Vulkan entries stop the resolution the procedural decoders perform: those follow the registry's
    # basetype chain to a primitive, so VkDeviceSize decodes as DecodeUInt64. That is not a bug and not a width
    # difference -- VkDeviceSize is uint64_t and its wire type is uint64_t. The schema declines to resolve them so
    # the category survives into the field model, where a consumer can tell a device size from an arbitrary 64-bit
    # integer. size_t is here for the other reason: it really does vary, 4 or 8 bytes in memory against 8 on the
    # wire.
    #
    # No width is stated here. A category's wire type lives on the category, in format/format.h, and the generated checks
    # file asserts against it: every scalar API element's element is as wide as its category's wire type, and every
    # refinement here records the same bytes as the primitive the encoder resolves it to.
    CURATED_CATEGORIES = {
        'size_t': 'SizeT',
        'VkDeviceSize': 'DeviceSize',
        'VkDeviceAddress': 'DeviceAddress',
        'VkSampleMask': 'SampleMask',
    }

    # Categories whose element is not a scalar, so the width check does not apply to them. Char and WChar have wire
    # types, but text is reached through a string decoder and wchar_t is 2 or 4 bytes against 2 on the wire.
    NON_SCALAR_CATEGORIES = ('Char', 'WChar', 'Opaque', 'Callback', 'Handle', 'Struct', 'Void')

    # Types the API headers do not declare with a distinct name of their own, so an API element cannot be named for
    # them and their element type needs no qualification.
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

    # Element names for the types whose registry spelling is not a usable identifier. An API element is a type of
    # its own, so it cannot be named for a keyword, and it must not shadow the element type it names.
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
        'size_t': 'Size',
        'float': 'Float',
        'double': 'Double',
        'void': 'Void',
    }

    # A field the API declares as a plain integer but GFXReconstruct treats as a handle, with the handle type carried
    # by a sibling field at run time. The type alone cannot express that, so those fields name one shared API element.
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
        # The registry's selector and selection attributes, which ValueInfo does not carry. (owner, member) to the
        # sibling whose value chooses a union member's alternative, and (union, member) to the selector values that
        # choose it.
        self.member_selectors = dict()
        self.member_selections = dict()
        self.may_reach_cache = dict()
        self.api_type_categories = dict()  # Element name to format::category expression.
        self.platform_api_types = set()  # Platform typedefs with an element of their own, for the header's note.
        self.api_type_elements = dict()  # Element name to element type expression.
        self.defaulted_types = set()  # Registry types that reached the Scalar fallback without being classified.
        # Enum groups the registry declares type="bitmask", to the mask type their values compose into: the API's
        # 32-bit flags type unless the group states bitwidth="64".
        self.bitmask_types = dict()

    def genStruct(self, typeinfo, typename, alias):
        """Method override: also record the registry's selector attributes."""
        VulkanBaseGenerator.genStruct(self, typeinfo, typename, alias)
        if not alias:
            self.record_member_attributes(typeinfo, typename)

    def genUnion(self, typeinfo, typename, alias):
        """Method override: also record the registry's selection attributes."""
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
        """Method override: also record the mask type of a group the registry declares a bitmask."""
        VulkanBaseGenerator.genGroup(self, groupinfo, group_name, alias)
        if groupinfo.elem.get('type') == 'bitmask':
            api_data = self.get_api_data()
            wide = groupinfo.elem.get('bitwidth') == '64'
            self.bitmask_types[group_name] = api_data.flags_64_type if wide else api_data.flags_type

    #
    # Utilities for the model
    #
    def get_base_structs(self):
        api_data = self.get_api_data()
        if (api_data) :
            return (api_data.base_in_struct, api_data.base_out_struct)
        return ()

    def get_decodable_struct_names(self):
        """All decodable structures: excludes base structures as they are never instantiated."""
        base_structs = self.get_base_structs()
        return [key for key in self.all_struct_members if key not in base_structs]

    #
    # Model
    #

    def build_model(self):
        """Resolve every API type that a Field names, and select the elements that get a Schema."""
        # Every structure the registry gives members gets a Schema, and every union a Schema of Alternatives. That
        # a structure's encoder, decoder or handle mapping is hand-written is a back-end fact: the inventory carries
        # it as a row property and the catalog reads it back, and the schema's presence never does. The one structure without a Schema is
        # the platform-defined one, which the registry gives no members.
        self.schema_structs = list(self.all_struct_members)
        self.schema_unions = list(self.all_union_members)

        # The structures with a generated Decoded_ wrapper: the blacklist's complement. A generated wrapper names
        # its element and declares the members the decoded partition maps; a hand-written one is not relied on for
        # either.
        self.wrapper_structs = list(self.get_all_filtered_struct_names())

        # Every decodable structure gets a traits row, hand-written decoder or not, so schema-driven code can
        # reach its Decoded_ type.
        self.schema_decodable_structs = list(self.get_decodable_struct_names())

        self.schema_commands = list(self.get_all_filtered_cmd_names())

        # The catalog's selected lists, each from a generator input. A structure in the structures blacklist has a
        # hand-written encoder and decoder; the structures-encoder and structures-decoder lists, when present, name
        # one side only. The platform list names the structures the registry references but does not define.
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

        # One shared API element for the runtime-typed handle fields.
        self.api_type_categories[self.GENERIC_HANDLE_DESCRIPTOR] = 'Handle'
        self.api_type_elements[self.GENERIC_HANDLE_DESCRIPTOR] = 'uint64_t'

        for struct in self.schema_structs:
            # Every element that gets a Schema also gets an API element, because the decoded representation traits key
            # on the API element even when no Field names the type.
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

        # Every structure the registry gives a type gets an API element, described or not, so a sieve over
        # structure_type reaches the hand-written encoders of the structures the schema excludes.
        for struct in self.struct_type_names:
            if struct not in self.all_struct_aliases:
                self.add_api_type(struct)

        # Every enumerated type gets an API element, named or not, so its enumerant table has a key.
        for enum in self.enum_names:
            if self.is_enumerated(enum):
                self.add_api_type(enum)

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
        """Whether a handle is reachable from a value of this type: a handle member, a generic handle, an extension
        chain, or a member structure or union that reaches one. khronos_base_generator's struct_might_have_handles
        answers the same question for the handle-mapping generators by a narrower rule, see its comment; this one
        counts a chain wherever it sits, because a missed handle is the worse failure. A cycle through members other
        than pNext is reported, since the recursion would not end."""
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
        """Follow registry aliases to the canonical type. Aliases use the schema of their canonical registry type."""
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
        """The extension chain member. The base generator's test asks for a void pointer, which every structure but
        the two base structures declares; theirs is typed as the base structure itself, and is the chain all the
        same. A Pointer to the owner's own type would otherwise make the base structure's schema a cycle."""
        if self.is_extended_struct_definition(value):
            return True
        return (
            value.name == self.get_extended_struct_var_name() and value.is_pointer
            and self.resolve_type_alias(value.base_type) in self.get_base_structs()
        )

    def get_api_element_name(self, base_type):
        """The identifier of the API element for a registry type."""
        resolved = self.resolve_type_alias(base_type)
        return self.DESCRIPTOR_NAME_FOR_TYPE.get(resolved, resolved)

    def get_api_element_path(self, base_type):
        """The API element's path from the schema namespace, for a line emitted at schema scope."""
        return 'vulkan::api_elements::{}'.format(self.get_api_element_name(base_type))

    def get_api_element_reference(self, name):
        """The API element's spelling from inside the API's own namespace, where a Field is emitted: lookup
        reaches schema::vulkan from schema::vulkan::fields::<owner>, so the API component is not written."""
        return 'api_elements::{}'.format(name)

    def get_generic_handles(self, owner, is_command, members):
        """Map member name to selector name for the fields GFXReconstruct treats as runtime-typed handles.

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
        """The API's own C++ type for one element of a field that names this API element.

        This is the element type, not the declared type of any field. The shape supplies the packaging, so a
        pointer-array field naming this API element is declared as a pointer to this type.
        """
        resolved = self.resolve_type_alias(base_type)

        if resolved == 'void':
            return 'void'

        if resolved in self.PRIMITIVE_TYPES:
            return resolved

        # Everything else is a name the API headers declare at global scope. The qualification matters, because a
        # API element carries the name of the type it describes.
        return '::{}'.format(resolved)

    def get_underlying_primitive(self, base_type):
        """Follow basetype and bitmask declarations down to the primitive a named type resolves to."""
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
        """The logical category a registry type name carries of its own, or None when nothing names one."""
        category = self.CURATED_CATEGORIES.get(name)

        if category is None:
            category = self.PRIMITIVE_CATEGORIES.get(name)

        if category is None:
            category = self.encode_types.get(name)

        return category

    def get_logical_category(self, base_type):
        """Select the logical category that names the Encode and Decode operation for a registry type."""
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

        # The registry's funcpointer category.
        if self.is_function_ptr(resolved):
            return 'Callback'

        curated = self.category_for_type(resolved)

        if curated is not None:
            return curated

        if self.has_basetype(resolved):
            underlying = self.get_basetype(resolved)

            # A basetype over void*, VkRemoteAddressNV: a value the API declares and never describes.
            if underlying == 'void':
                return 'Opaque'

            curated = self.category_for_type(underlying)

            if curated is not None:
                return curated

        # Nothing classified this type. format::category::Scalar has no wire type, so it satisfies the
        # scalar concepts but cannot be encoded, and the generator reports it.
        self.defaulted_types.add(resolved)
        return 'Scalar'

    def get_field_element_name(self, value):
        """The element a field names: the registry type's, or the platform typedef's own when the base generator
        substituted one. The schema states the type the header declares and invents no abstraction over it; the
        substitution is dev's representation choice and lives on the element's category. One question decides it:
        did the header spell a platform typedef."""
        platform = value.platform_base_type

        if platform:
            self.add_platform_api_type(platform, value)
            return platform

        return self.get_api_element_name(value.base_type)

    def add_field_api_type(self, value):
        """Register the element a member or parameter names, the platform typedef's own where it has one."""
        if self.get_field_element_name(value) == self.get_api_element_name(value.base_type):
            self.add_api_type(value.base_type)

    def add_platform_api_type(self, platform_type, value):
        """An element for a platform typedef, named and typed as the header spells it. Its category is Opaque when the
        platform table says baseType void: an opaque structure the header reaches through a pointer, or a handle
        typedef held by value. Otherwise it is the category of the type the table substitutes, the text category for
        LPCWSTR, the scalar's own for DWORD."""
        if platform_type in self.api_type_categories:
            return

        if self.PLATFORM_TYPES[platform_type]['baseType'] == 'void':
            category = 'Opaque'
        else:
            category = self.get_logical_category(value.base_type)

        # Qualified from the global namespace: inside the element, the unqualified name is the element itself.
        self.api_type_categories[platform_type] = category
        self.api_type_elements[platform_type] = '::' + platform_type
        self.platform_api_types.add(platform_type)

    def add_api_type(self, base_type):
        name = self.get_api_element_name(base_type)

        if name in self.api_type_categories:
            return

        # A category that format::category does not declare fails the build at the symbol, and a category narrower than its
        # element fails the width assertion the checks file carries. Neither is restated here.
        category = self.get_logical_category(base_type)

        self.api_type_categories[name] = category
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
        """The shape defines how one field use packages its API type at this use site."""
        if self.is_extension_chain(value):
            return 'ExtensionChain'

        # A platform typedef is its own element, so the shape follows the header's declarator around the typedef:
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
        """An array of pointers, each to one element: two stars, and either a text element, whose registry length
        'count,null-terminated' the base generator has already reduced to the count, or a length of the form 'count,1'.
        A two-star run whose second length is anything else, or absent, is not one. The registry states only the outer
        count for the two variable-row command parameters, and they stay Array."""
        if value.pointer_count != 2:
            return False

        if value.base_type in ('char', 'wchar_t'):
            return True

        parts = [part.strip() for part in (value.array_length or '').split(',')]
        return len(parts) == 2 and parts[1] == '1'

    def get_count_field(self, value, members):
        """The sibling Field that carries the element count, when the length is exactly one sibling name."""
        length = value.array_length

        if not length or value.array_length_value is None:
            return None

        if self.get_field_shape(value) == 'PointerArray':
            # The row length is the shape's, not a count; only the sibling remains.
            length = length.split(',')[0].strip()

        if length != value.array_length_value.name:
            return None

        if not any(member.name == length for member in members):
            return None

        return length

    def get_count_member(self, value, members):
        """The (sibling, member) pair when the length is read through a pointer sibling, `sibling->member`."""
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
        """The registry's arithmetic length as a tree, or None when it is not one the schema states.

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
        """The sibling names a count expression reads."""
        if tree[0] == 'sibling':
            return [tree[1]]
        if tree[0] in ('number', 'constant'):
            return []
        return self.count_expression_siblings(tree[1]) + self.count_expression_siblings(tree[2])

    def make_count_expression(self, tree, members):
        """The StoreValue type for a count expression tree.

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
        """The length expression, or None when no Action can evaluate the registry length."""
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
        """The NOTE line written above a API element whose count is arithmetic, carrying the registry's text."""
        if self.parse_count_expression(value, members) is None:
            return None

        return '// NOTE: length evaluates {}'.format(value.array_length)

    def get_static_array_extents(self, value):
        """The declared extents of a fixed-extent array member, in declaration order, as the registry spells them."""
        return [part.strip() for part in value.array_capacity.split(',')]

    def make_field_definition(self, value, members, generic_handles, owner):
        """One Field api_element. It names its API element and its shape, and restates no type fact."""
        shape = self.get_field_shape(value)
        generic_selector = generic_handles.get(value.name)

        # The sibling whose value chooses what this field holds: the object type of a runtime-typed handle, from the
        # generic-handle tables, or the registry's selector on a union-typed member.
        selector = generic_selector if generic_selector is not None else self.member_selectors.get((owner, value.name))

        if generic_selector is not None:
            api_element = self.get_api_element_reference(self.GENERIC_HANDLE_DESCRIPTOR)
        elif value.platform_base_type:
            # A platform typedef names its own element, before the substituted void* can make it an external object.
            api_element = self.get_api_element_reference(self.get_field_element_name(value))
        else:
            api_element = self.get_api_element_reference(self.get_api_element_name(value.base_type))

        length = self.get_field_length(value, members)
        declaration = self.make_declaration(value, api_element, shape, length)

        # Facts the declarator does not spell stay as members of the derived struct.
        parts = []

        if selector is not None:
            parts.append('using selector_field = {};'.format(selector))

        # A union alternative the registry marks: the selector values that choose it, as the registry lists them.
        selections = self.member_selections.get((owner, value.name))

        if selections:
            parts.append('static constexpr auto selections = std::array{{ {} }};'.format(', '.join(selections)))

        if shape == 'ExtensionChain':
            # Whether the registry declares the owner on either side of structextends. The base generator names the
            # complement after the spec's usual consequence, "pNext must be NULL"; the schema records the registry
            # fact, which the spec's text does not always match (VkPipelineCreateInfoKHR requires a node).
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
        """The declaration of one field use: the element, or forms over it as the C declarator nests, read from
        the registry's full type so each level's const lands where the header wrote it."""
        if shape == 'ExtensionChain':
            # schema::ExtensionChain, reached from the fields namespace by enclosing-namespace lookup.
            element = 'ExtensionChain'
        else:
            element = api_element

        # The header's spelling: for a platform typedef the declarator around the typedef, not around what the base
        # generator substituted for it.
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
            # Nest from the innermost extent outward; a bounded array's sibling length sits on the outermost level.
            extents = self.get_static_array_extents(value)

            for index, extent in enumerate(reversed(extents)):
                outermost = index == len(extents) - 1
                declaration = 'FixedArray<{}, {}, {}>'.format(
                    declaration, length if (outermost and length) else 'UseCapacity', extent
                )

        return declaration

    def make_return_field_definition(self, return_type):
        """Every command has one Return Field; a void command's names the Void element."""
        return 'struct {} : Field<"{}", {}> {{ static constexpr bool is_return = true; }};'.format(
            self.RETURN_FIELD_NAME,
            self.RETURN_FIELD_NAME,
            self.get_api_element_reference(self.get_api_element_name(self.clean_return_type(return_type))),
        )

    def write_field_namespace(self, element, members, owner, is_command, return_type=None):
        """One namespace of Fields for one API element."""
        write(
            'GFXRECON_BEGIN_NAMESPACE({})'.format(element), file=self.outFile
        )

        generic_handles = self.get_generic_handles(owner, is_command, members)

        # A length or a selector_field names a sibling, and the Vulkan registry always declares that sibling
        # before the member that names it, so the API elements are written in declaration order with no forward
        # declarations. That is a Vulkan-derived rule: a sibling named before its declaration fails to compile at
        # that line, and an API that breaks the rule needs a "references" fact in the IR and a backend that emits
        # the declaration.
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
        """One Schema specialization. Its Fields list is the canonical field order for the API element; a union's
        Alternatives list is its members, of which a value holds one."""
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
        """Method override."""
        self.build_model()
        self.write_part()

        VulkanBaseGenerator.endFile(self)

    def write_part(self):
        """Write the content of this part's generated file. One override for each generated file."""
        raise NotImplementedError

    def write_schema_part(self, *writers):
        """Emit one part of the schema inside gfxrecon::schema, which every part opens the same way."""
        write('GFXRECON_BEGIN_NAMESPACE(schema)', file=self.outFile)
        self.newline()

        for writer in writers:
            writer()

        write('GFXRECON_END_NAMESPACE(schema)', file=self.outFile)

    def write_api_elements(self):
        write(
            '// API type api_elements. A API element carries the API\'s own type for one element and the logical category',
            file=self.outFile
        )
        write(
            '// that names its Encode and Decode operation. It carries no wire representation type and no decoded',
            file=self.outFile
        )
        write(
            '// representation; each category in format/format.h carries the wire type it is recorded as.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()
        write('// The enumerant tables, defined in generated_vulkan_schema_enumerants.h. A API element names its own.', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(enumerants)', file=self.outFile)
        for enum in self.get_enumerated_types():
            write('struct {};'.format(enum), file=self.outFile)
        write('GFXRECON_END_NAMESPACE(enumerants)', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(api_elements)', file=self.outFile)

        if self.platform_api_types:
            write('// Platform typedefs with an element of their own, typed as the platform header spells them; the', file=self.outFile)
            write('// category is that of the type format/platform_types.h substitutes for each: {}.'.format(
                ', '.join(sorted(self.platform_api_types))), file=self.outFile)

        # An element derives from the base that fixes its category and fills the member that category carries:
        # ApiElementTypedStruct for a structure with an sType value, ApiElementEnum for an enumeration,
        # ApiElementFlagBits for a bits enumeration, ApiElementBitmask for a flags typedef, ApiElementBase for the
        # rest. The table and bits-element arguments are qualified from the global namespace: the inherited
        # enumerants member would change the meaning of an unqualified enumerants:: in the completed class.
        bitvalues = self.get_bitvalues_of_bitmasks()
        for name in sorted(self.api_type_categories):
            element = self.api_type_elements[name]
            args = '"{}", {}'.format(element.lstrip(':'), element)
            category = 'format::category::{}'.format(self.api_type_categories[name])
            structure_type = self.get_structure_type(name)
            if structure_type is not None:
                assert self.api_type_categories[name] == 'Struct', name
                base = 'ApiElementTypedStruct<{}, {}>'.format(args, structure_type)
            elif self.is_enumerated(name):
                table = '::gfxrecon::schema::vulkan::enumerants::{}'.format(name)
                if name in self.bitmask_types:
                    base = 'ApiElementFlagBits<{}, {}, {}, ::{}>'.format(args, category, table, self.bitmask_types[name])
                else:
                    assert self.api_type_categories[name] == 'Enum', name
                    base = 'ApiElementEnum<{}, {}>'.format(args, table)
            elif name in bitvalues:
                base = 'ApiElementBitmask<{}, {}, ::gfxrecon::schema::vulkan::api_elements::{}>'.format(
                    args, category, bitvalues[name]
                )
            else:
                base = 'ApiElementBase<{}, {}>'.format(args, category)
            write('struct {} : {} {{}};'.format(name, base), file=self.outFile)

        write('GFXRECON_END_NAMESPACE(api_elements)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()

    def get_deep_copy_excluded_api_elements(self):
        """The deep-copy exclusions that are structure api_elements, by name; an alias in the list names no api_element."""
        return [name for name in self.get_structure_api_elements() if name in self.deep_copy_exclusions]

    def get_enumerated_types(self):
        """Every enumerated type, by name; its API element and its table carry the same name."""
        return sorted(enum for enum in self.enum_names if self.is_enumerated(enum))

    def get_native_enumerated_types(self):
        """The enumerated types that are C enums, by name: every enumerated type but the 64-bit flag-bits typedefs."""
        return [enum for enum in self.get_enumerated_types() if self.api_type_categories[self.get_api_element_name(enum)] == 'Enum']

    def get_wide_bitmask_pairs(self):
        """(bits api_element, typedef api_element) for each 64-bit flag-bits type whose typedef has a api_element."""
        return sorted(
            (enum, flags) for flags, enum in self.get_bitvalues_of_bitmasks().items()
            if flags in self.api_type_categories and self.api_type_categories[self.get_api_element_name(enum)] == 'Flags64'
        )

    def get_bitvalues_of_bitmasks(self):
        """Mask typedef API element name to the API element name of the bits enum whose values compose it, from the
        registry's requires or bitvalues attribute on the typedef, for the typedefs that have an API element."""
        result = dict()
        for enum in self.get_enumerated_types():
            if enum not in self.bitmask_types:
                continue
            flags = self.get_flags_type_from_enum(enum)
            if flags is not None:
                result[self.get_api_element_name(flags)] = enum
        return result

    def get_structure_api_elements(self):
        """Every API element of category Struct that is not a union, by name."""
        return [
            name for name in sorted(self.api_type_categories)
            if self.api_type_categories[name] == 'Struct' and name not in self.all_union_members
        ]

    def get_union_api_elements(self):
        """Every union API element, by name. A union's category is Struct: the encode and decode operations treat it as
        one, and its Schema of Alternatives is what tells it apart."""
        return [name for name in sorted(self.api_type_categories) if name in self.all_union_members]

    # The catalog's selected lists, binding/vulkan_catalog.h, each read back from an inventory property: the list
    # name and the attribute holding the generator's input, for the size checks.
    BINDING_CATALOG_LISTS = (
        ('external_structures', 'external_structs'),
        ('custom_encode_structures', 'custom_encode_structs'),
        ('custom_decode_structures', 'custom_decode_structs'),
        ('custom_handle_mapping_structures', 'custom_handle_mapping_structs'),
        ('generic_handle_structures', 'generic_handle_structs'),
        ('deep_copy_exclusions', 'deep_copy_exclusions'),
    )

    def get_binding_catalog_members(self, attribute):
        """The members of one binding list that are structure or union api_elements, by name."""
        names = set(getattr(self, attribute))
        return [name for name in self.get_structure_api_elements() + self.get_union_api_elements() if name in names]

    def get_structure_type(self, name):
        """The registry's structure type enumerant for a structure api_element, or None: an alias or a type without one."""
        if name in self.all_struct_aliases or name not in self.struct_type_names:
            return None
        return self.struct_type_names[name]

    def write_command_api_elements(self):
        write(
            '// Command api_elements. A command API element is a schema key and a binding key. It carries no members of its own\n'
            '// until command piloting, or an operation over commands, needs one.',
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
            '// Field api_elements. A Field names its API type and its shape at this use site.',
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
            '// Schemas. A structure keys on its API element and a command on its command api_element, which is the',
            file=self.outFile
        )
        write(
            '// same key the decoded-type binding uses, so one spelling reaches both.',
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
        """Every handle API element but the generic handle, by name: the handles that have a capture wrapper."""
        return [
            name for name in sorted(self.api_type_categories)
            if self.api_type_categories[name] == 'Handle' and name != self.GENERIC_HANDLE_DESCRIPTOR
        ]

    def get_inventory_enums(self):
        """(name, is_flag_bits) for every native enumerated type, by name."""
        return [(enum, enum in self.bitmask_types) for enum in self.get_native_enumerated_types()]

    INVENTORY_ROW_MACROS = (
        'GFXRECON_INVENTORY_VISIT_STRUCT(Name)',
        'GFXRECON_INVENTORY_VISIT_UNION(Name)',
        'GFXRECON_INVENTORY_VISIT_HANDLE(Name, Stem)',
        'GFXRECON_INVENTORY_VISIT_ENUM(Name)',
        'GFXRECON_INVENTORY_VISIT_FLAG_BITS(Name)',
        'GFXRECON_INVENTORY_VISIT_COMMAND(Name)',
    )

    # The row properties, in bit order: the macro suffix, the C++ name a visit reads the property back as, and the
    # banner's one-line meaning. A property is a fact the preprocessor cannot derive. Its name follows what reads
    # it: HAS_ a concept, MAY_ and a bare adjective a catalog list. What each is read from:
    #
    #   CUSTOM_ENCODE          blacklists.json 'structures', plus 'structures-encoder'
    #   CUSTOM_DECODE          blacklists.json 'structures', plus 'structures-decoder'
    #   CUSTOM_HANDLE_MAPPING  blacklists.json 'structures', plus STRUCT_MAPPERS_BLACKLIST in the Vulkan base generator
    #   DEEP_COPY_EXCLUDED     blacklists.json 'structures-deep-copy'
    #   EXTERNAL               platform_types.json 'structs'
    #   GENERIC_HANDLE         GENERIC_HANDLE_STRUCTS in the Vulkan base generator
    #   HAS_DECODED_TYPE       the decodable set, every structure but the two base structures
    #   MAY_REACH_HANDLES      the registry: a handle member, a pNext, or a member that reaches one
    #   HAS_STRUCTURE_TYPE     the registry: a structure type
    #
    # The first six are back-end inputs and the last three registry facts; the inventory carries both categories, which
    # is why reading it is a binding act.
    INVENTORY_PROPERTIES = (
        ('HAS_DECODED_TYPE', 'binding::HasDecodedType',
         'a Decoded_ wrapper exists and the decoded-type rows reach it'),
        ('MAY_REACH_HANDLES', 'binding::vulkan::MayReachHandles',
         'a handle is reachable through its fields, pNext included'),
        ('EXTERNAL', 'binding::vulkan::IsExternal',
         'a platform header defines it, not the registry, so it has a API element and no Schema'),
        ('CUSTOM_ENCODE', 'binding::vulkan::IsCustomEncode', 'its encoder is hand-written'),
        ('CUSTOM_DECODE', 'binding::vulkan::IsCustomDecode', 'its decoder is hand-written'),
        ('CUSTOM_HANDLE_MAPPING', 'binding::vulkan::IsCustomHandleMapping',
         'its unwrap and map bodies are hand-written, or absent'),
        ('GENERIC_HANDLE', 'binding::vulkan::HasGenericHandle',
         'a member is a runtime-typed handle, an integer its sibling object type names the type of'),
        ('DEEP_COPY_EXCLUDED', 'binding::vulkan::IsDeepCopyExcluded', 'vulkan_struct_deep_copy does not handle it'),
        ('HAS_STRUCTURE_TYPE', 'schema::HasStructureType',
         'the registry gives it a structure type, which its API element carries, so a pNext chain can hold it'),
    )

    def inventory_property_macro(self, suffix):
        return 'GFXRECON_INVENTORY_{}'.format(suffix)

    def get_inventory_properties(self, name):
        """The property suffixes of one structure or union row."""
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
        """The rows grouped by property set: (property suffixes, row names), in bit order of the set."""
        order = [suffix for suffix, _, _ in self.INVENTORY_PROPERTIES]
        groups = dict()
        for name in names:
            properties = tuple(self.get_inventory_properties(name))
            groups.setdefault(properties, []).append(name)
        return sorted(groups.items(), key=lambda item: sum(1 << order.index(suffix) for suffix in item[0]))

    def write_inventory(self):
        """The inventory: one row per API type and per command, for a consumer to expand into its own rows."""
        banner = [
            '// THIS FILE IS A LIST, NOT A HEADER. IT HAS NO INCLUDE GUARD, AND IT DECLARES NOTHING.',
            '//',
            '// It holds one macro call per Vulkan API type and per command, and nothing else: no declarations, no namespace,',
            '// no includes. It does not define the macros it calls. You define them, include this file, and each row expands',
            '// into whatever you defined. Include it once for each thing you want built from the list, inside the namespace',
            '// the result belongs in. The idiom is the X macro: Meyers, "The X Macro", Dr. Dobb\'s Journal, 2001.',
            '//',
            '// To use it:',
            '//   1. Define the visit macros for the categories you want:',
            '//        GFXRECON_INVENTORY_VISIT_STRUCT(Name)      GFXRECON_INVENTORY_VISIT_UNION(Name)',
            '//        GFXRECON_INVENTORY_VISIT_HANDLE(Name, Stem)',
            '//        GFXRECON_INVENTORY_VISIT_ENUM(Name)        GFXRECON_INVENTORY_VISIT_FLAG_BITS(Name)',
            '//        GFXRECON_INVENTORY_VISIT_COMMAND(Name)',
            '//      A category you leave undefined expands to nothing. Defining none is an error.',
            '//   2. Optionally define GFXRECON_INVENTORY_REQUIRE and GFXRECON_INVENTORY_FORBID as masks of the row properties',
            '//      below. A structure or union row expands only if it has every REQUIRE property and no FORBID property.',
            '//      Both default to 0. Handles, enumerated types and commands carry no properties and are not filtered.',
            '//   3. #include "generated/generated_vulkan_inventory.h"',
            '// Every visit, REQUIRE and FORBID definition is #undef\'d at the end, so the next include starts clean. The',
            '// property macros stay defined.',
            '//',
            '// Organization: the structure rows and the union rows are each grouped by property set, one #if per group and',
            '// none per row, and the groups are only the property sets that occur. A row\'s group is its complete property',
            '// set, so a property a row does not have is as readable as one it has.',
            '//',
            '// Where a stanza lives follows what its visitor yields. A visitor that yields a type, a specialization, an alias',
            '// or a declaration, lives in a header, because the compiler needs it wherever the type is asked for and nothing',
            '// links a type. A visitor that yields a definition with linkage, an explicit instantiation or a function body,',
            '// lives in one .cpp and is linked from everywhere else.',
            '//',
            '// Row properties. Each is a fact the preprocessor cannot derive, and each is read back into C++ by a visit,',
            '// as the trait or the catalog list named beside it, so the property and its C++ form cannot disagree. The',
            '// name follows what reads it: HAS_ a concept, MAY_ and a bare adjective a catalog list.',
        ]
        width = max(len(self.inventory_property_macro(suffix)) for suffix, _, _ in self.INVENTORY_PROPERTIES)
        reader_width = max(len(reader) for _, reader, _ in self.INVENTORY_PROPERTIES)
        for suffix, reader, meaning in self.INVENTORY_PROPERTIES:
            banner.append('//   {:<{}}  {:<{}}  {}'.format(self.inventory_property_macro(suffix), width, reader, reader_width, meaning))
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
        for bit, (suffix, _, _) in enumerate(self.INVENTORY_PROPERTIES):
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

        body.append('// Handles, with the stem the capture wrapper is named by: the handle name without its Vk prefix.')
        for handle in self.get_inventory_handles():
            body.append('GFXRECON_INVENTORY_VISIT_HANDLE({}, {})'.format(handle, handle[2:]))
        body.append('')

        body.append('// Enumerated types: a flag-bits enum, whose values compose into a mask, and every other enum.')
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
        """Static checks over the whole generated schema, compiled by the framework test target.

        Three of these compare one generator's output against another's. A decoded wrapper's struct_type comes from
        the struct-decoders generator, which knows nothing about the schema, so agreeing with the API element's
        element type is a real cross-check rather than this generator confirming itself.
        """
        # The file already opens gfxrecon, from the options, so only the inner namespace belongs here.
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
            write('static_assert(schema::HasSchemaAlternatives<{}>);'.format(element), file=self.outFile)
            write('static_assert(!schema::HasSchemaFields<{}>);'.format(element), file=self.outFile)

        self.newline()
        write(
            '// Every command schema has exactly one return Field, which is what HasCommandSchema tests through',
            file=self.outFile
        )
        write('// TypeListSole.', file=self.outFile)

        for command in self.schema_commands:
            api_element = 'schema::vulkan::api_elements::{}'.format(self.get_command_api_element_name(command))
            write('static_assert(schema::HasCommandSchema<{}>);'.format(api_element), file=self.outFile)

        self.newline()
        write('// Each wrapper names its element, and the trait keyed on that element names the wrapper. The two', file=self.outFile)
        write('// come from different generators, so a mis-paired line in either cannot pass.', file=self.outFile)

        for struct in self.wrapper_structs:
            write(
                'static_assert(std::is_same_v<binding::DecodedTypeOf<typename Decoded_{name}::api_element>, '
                'Decoded_{name}>);'.format(name=struct),
                file=self.outFile
            )

        self.newline()

        for command in self.schema_commands:
            api_element = self.get_command_api_element_name(command)
            write(
                'static_assert(std::is_same_v<binding::DecodedTypeOf<typename args::{api_element}::api_element>, '
                'args::{api_element}>);'.format(api_element=api_element),
                file=self.outFile
            )

        self.newline()
        write(
            '// Cross-generator: the element type on the API element against struct_type on the decoded wrapper,',
            file=self.outFile
        )
        write('// which the struct-decoders generator emits without any knowledge of the schema.', file=self.outFile)

        for struct in self.wrapper_structs:
            write(
                'static_assert(std::is_same_v<schema::ElementType<schema::{path}>, '
                'typename Decoded_{name}::struct_type>);'.format(
                    path=self.get_api_element_path(struct), name=struct
                ),
                file=self.outFile
            )

        self.newline()
        write('// Cross-source: the declaration a Field spells against the member the API declares. ApiTypeOf rebuilds', file=self.outFile)
        write('// the declared C type from the element and the declarator, const at each level, a star per Pointer or', file=self.outFile)
        write('// Array, an extent per FixedArray, and it must equal the member type the compiler laid out. A header', file=self.outFile)
        write('// revision that changed a member fails here. Structures only: a command parameter has no member to', file=self.outFile)
        write('// compare against. One kind of member is not comparable and is skipped: the base structures\' pNext,', file=self.outFile)
        write('// which the header types as the base structure and the schema as the chain.', file=self.outFile)

        for struct in self.schema_structs + self.schema_unions:
            for value in self.all_struct_members.get(struct, self.all_union_members.get(struct)):
                if self.is_extension_chain(value) and self.resolve_type_alias(value.base_type) in self.get_base_structs():
                    continue

                write(
                    'static_assert(std::is_same_v<decltype({struct}::{name}), schema::ApiTypeOf<{field}::declaration>>);'.format(
                        struct=struct, name=value.name, field='schema::' + self.get_field_path(struct, value.name)
                    ),
                    file=self.outFile
                )

        self.newline()
        write('// A API element states a category and the category states the wire type, in format/format.h. A API element', file=self.outFile)
        write('// whose element is narrower than its category would compile and desynchronize the stream, so every', file=self.outFile)
        write('// scalar element is as wide as its wire type. size_t is the one exception, 4 or 8 bytes in memory', file=self.outFile)
        write('// against 8 on the wire, which ValueDecoder converts.', file=self.outFile)

        for name in sorted(self.api_type_categories):
            category = self.api_type_categories[name]

            if category in self.NON_SCALAR_CATEGORIES or category == 'SizeT':
                continue

            write(
                'static_assert(sizeof(schema::ElementType<schema::vulkan::api_elements::{name}>) == '
                'sizeof(format::EncodeTypeFor<schema::vulkan::api_elements::{name}::category>));'.format(name=name),
                file=self.outFile
            )

        self.newline()
        write('// The encoder captures a refined type by its basetype, so a refinement must record the same bytes', file=self.outFile)
        write('// as the primitive category it refines.', file=self.outFile)

        for type_name in sorted(self.CURATED_CATEGORIES):
            primitive_category = self.encode_types.get(self.get_underlying_primitive(type_name))

            if primitive_category is None:
                continue

            write(
                'static_assert(std::is_same_v<format::EncodeTypeFor<format::category::{refined}>, '
                'format::EncodeTypeFor<format::category::{primitive}>>);'.format(
                    refined=self.CURATED_CATEGORIES[type_name], primitive=primitive_category
                ),
                file=self.outFile
            )

        self.newline()
        self.newline()
        write('// A API element carries structure_type exactly when the registry gives the structure one: the row property and', file=self.outFile)
        write('// the API element member are two emissions of that one fact, checked against each other on every row.', file=self.outFile)
        write('#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_HAS_STRUCTURE_TYPE', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) static_assert(schema::HasStructureType<schema::vulkan::api_elements::Name>);', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)', file=self.outFile)
        write('#include "generated/generated_vulkan_inventory.h"', file=self.outFile)
        write('#define GFXRECON_INVENTORY_FORBID GFXRECON_INVENTORY_HAS_STRUCTURE_TYPE', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) static_assert(!schema::HasStructureType<schema::vulkan::api_elements::Name>);', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)', file=self.outFile)
        write('#include "generated/generated_vulkan_inventory.h"', file=self.outFile)

        typed = sum(1 for struct in self.get_structure_api_elements() if self.get_structure_type(struct) is not None)

        self.newline()
        write('// The sizes the generator counted, then the relation checked arithmetically.', file=self.outFile)
        write(
            'constexpr size_t kStructuresCount = util::TypeListSizeV<binding::vulkan::catalog::structures>;\n' +
            'static_assert(kStructuresCount == {});'.format(len(self.get_structure_api_elements())),
            file=self.outFile
        )
        write(
            'constexpr size_t kUnionsCount = util::TypeListSizeV<binding::vulkan::catalog::unions>;\n' +
            'static_assert(kUnionsCount == {});'.format(len(self.get_union_api_elements())),
            file=self.outFile
        )
        write(
            'static_assert(util::TypeListSizeV<binding::vulkan::catalog::extensible_structures> == {});'.format(typed),
            file=self.outFile
        )

        excluded = self.get_deep_copy_excluded_api_elements()
        excluded_typed = [name for name in excluded if self.get_structure_type(name) is not None]
        write(
            'static_assert(util::TypeListSizeV<binding::vulkan::catalog::deep_copyable_structures> == {});'.format(typed - len(excluded_typed)),
            file=self.outFile
        )

        self.newline()
        write('// Every enumerated type\'s API element names its table, and every one but a 64-bit flag-bits type is bound to', file=self.outFile)
        write('// its native enum. Nothing is bound to the bare integer types that the 64-bit flag-bits and the Flags', file=self.outFile)
        write('// typedefs are spelled as, which would draw their ToString calls into the enumerant overloads.', file=self.outFile)

        for enum in self.get_enumerated_types():
            element = 'schema::{}'.format(self.get_api_element_path(enum))
            write('static_assert(schema::HasEnumerants<{}>);'.format(element), file=self.outFile)
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
                'static_assert({}schema::HasBitmask<{}>);'.format('' if 'FlagBits' in enum else '!', element),
                file=self.outFile
            )
        self.newline()
        write('// A mask typedef\'s own type is the type its bits compose into: the typedef\'s base type against the bits', file=self.outFile)
        write('// group\'s bitwidth, two places the registry states one width.', file=self.outFile)
        for flags, enum in sorted(self.get_bitvalues_of_bitmasks().items()):
            if flags not in self.api_type_categories:
                continue
            element = 'schema::{}'.format(self.get_api_element_path(flags))
            write(
                'static_assert(std::is_same_v<{0}::element_type, {0}::bitvalues::bitmask>);'.format(element),
                file=self.outFile
            )
        self.newline()
        write('static_assert(!binding::HasApiElement<uint32_t>);', file=self.outFile)
        write('static_assert(!binding::HasApiElement<uint64_t>);', file=self.outFile)

        self.newline()
        write('// The catalog: each list, read back from an inventory property, is the size of the input the', file=self.outFile)
        write('// generator carried into that property.', file=self.outFile)
        for name, attribute in self.BINDING_CATALOG_LISTS:
            write(
                'static_assert(util::TypeListSizeV<binding::vulkan::catalog::{}> == {});'.format(
                    name, len(self.get_binding_catalog_members(attribute))
                ),
                file=self.outFile
            )

        self.newline()
        write('// The inventory against the catalog and the model: one count per row category. A row the generator dropped or', file=self.outFile)
        write('// doubled fails here by count.', file=self.outFile)
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
        write('// The one property with a second source: EXTERNAL comes from the platform list, and a Schema from the members', file=self.outFile)
        write('// the registry gives, so an external structure has a API element and no Schema of either category, and every other', file=self.outFile)
        write('// structure and union row has one. Every other property is read back into C++ by a visit and cannot disagree.', file=self.outFile)
        write('#define GFXRECON_INVENTORY_REQUIRE GFXRECON_INVENTORY_EXTERNAL', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) static_assert(!schema::HasSchemaFields<schema::vulkan::api_elements::Name> && !schema::HasSchemaAlternatives<schema::vulkan::api_elements::Name>);', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_UNION(Name) GFXRECON_INVENTORY_VISIT_STRUCT(Name)', file=self.outFile)
        write('#include "generated/generated_vulkan_inventory.h"', file=self.outFile)
        write('#define GFXRECON_INVENTORY_FORBID GFXRECON_INVENTORY_EXTERNAL', file=self.outFile)
        write('#define GFXRECON_INVENTORY_VISIT_STRUCT(Name) static_assert(schema::HasSchemaFields<schema::vulkan::api_elements::Name> || schema::HasSchemaAlternatives<schema::vulkan::api_elements::Name>);', file=self.outFile)
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
        """A bitfield has no pointer to member, so the mapping supplies accessors and a sentinel value."""
        return (
            'template <> struct MemberPointer<{storage}, {field}> : NonAddressableMember '
            '{{ static {type} Get(const {storage}& storage) {{ return storage.{member}; }} '
            'static void Set({storage}& storage, {type} value) {{ storage.{member} = value; }} }};'.format(
                storage=storage, field=field, member=member_name, type=value_type
            )
        )

    def write_native_struct_members(self):
        self.write_member_partition_prologue(
            'Member traits for native structure storage.'
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
                # the wrapped native structure, so it has no mapping in this population.
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
    """Generates the API elements and command api_elements."""

    def write_part(self):
        self.write_schema_part(self.write_api_elements, self.write_command_api_elements)


class VulkanSchemaEnumerantsGenerator(VulkanSchemaBaseGenerator):
    """Generates the enumerant table of every enumerated type."""

    def write_part(self):
        write('// Enumerants: one table per enumerated type, in registry order, with the name the API spells. For a flag-bits', file=self.outFile)
        write('// type the table holds single bits, combined masks and zero alike: lookups go from value to name, so they', file=self.outFile)
        write('// are not told apart. An alias adds no entry. The type\'s API element names its table, and each entry', file=self.outFile)
        write('// names the api_element.', file=self.outFile)
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

        write('GFXRECON_END_NAMESPACE(enumerants)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(schema)', file=self.outFile)


class VulkanEnumToStringBodyGenerator(VulkanSchemaBaseGenerator):
    """Generates the ToString specialization definitions and the 64-bit explicit instantiations."""

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
        write('// The 64-bit flag-bits types, by api_element: the bits API element names one enumerant, the typedef\'s expands a mask.', file=self.outFile)
        for bits, flags in self.get_wide_bitmask_pairs():
            for api_element in (bits, flags):
                write(
                    'template std::string ToString<schema::vulkan::api_elements::{0}>({1}, ToStringFlags, uint32_t, uint32_t);'.format(api_element, api_data.flags_64_type),
                    file=self.outFile
                )
        self.newline()
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)


class VulkanSchemaFieldsGenerator(VulkanSchemaBaseGenerator):
    """Generates the Field api_elements."""

    def write_part(self):
        self.write_schema_part(self.write_fields)


class VulkanSchemaGenerator(VulkanSchemaBaseGenerator):
    """Generates the Schema specializations that order the Fields."""

    def write_part(self):
        self.write_schema_part(self.write_schemas)


class VulkanInventoryGenerator(VulkanSchemaBaseGenerator):
    """Generates the inventory, the one list every visitor is invoked across."""

    def write_part(self):
        self.write_inventory()


class VulkanSchemaNativeStructMembersGenerator(VulkanSchemaBaseGenerator):
    """Generates the member traits keyed on the native API structure."""

    def write_part(self):
        self.write_native_struct_members()


class VulkanSchemaDecodedStructMembersGenerator(VulkanSchemaBaseGenerator):
    """Generates the member traits keyed on the decoded structure wrapper."""

    def write_part(self):
        self.write_decoded_struct_members()


class VulkanSchemaDecodedCommandMembersGenerator(VulkanSchemaBaseGenerator):
    """Generates the member traits keyed on a command's decoded argument storage."""

    def write_part(self):
        self.write_decoded_command_members()


class VulkanSchemaChecksGenerator(VulkanSchemaBaseGenerator):
    """Generates the cross-generator agreement checks. Compiling the result is the test."""

    def write_part(self):
        self.write_checks()


