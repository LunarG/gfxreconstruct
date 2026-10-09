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
files in a strict include order: types (API type descriptors and command tags) is what anything naming an API
element needs; fields (Field descriptors) is what an Action's member traits need; schema (the Schema
specializations) is what the field walk needs. The member traits are partitioned further by storage population, and
only the target that owns an operation includes the population it reads.

This is the initial version. It emits:

    one API type descriptor for each registry type that a Field names or a Schema keys on
    one command tag for each command
    one Field descriptor for each command parameter and structure member
    one Return Field for each command, including a VoidReturn Return Field for a void command
    one Schema specialization for each command and structure
    one decoded representation trait for each structure and each command; the inverse is the api_element member
    the wrapper and args generators emit
    one member trait for each valid storage and Field pair, in three storage populations

It does not yet emit:

    semantic metadata, on either the API type descriptor or the Field descriptor
    capture_wrapper_type on a handle descriptor, which needs an authoritative handle to wrapper mapping
    formal API-signature storage and its member traits, and the decoded metadata storage population
    runtime dispatch tables, custom hooks, command lifecycle traits, or the args compatibility bindings

Two Field descriptor properties differ from the design text, because the registry forces the difference:

    The name property is emitted as field_name. Vulkan declares members called 'name', and a class member cannot
    share the name of its enclosing class.
    The shape vocabulary adds Pointer, StaticArray, PointerArray, and ExtensionChain to Value, Array, and VoidReturn. The
    design names field_shape::Value, field_shape::Array, and field_shape::VoidReturn, and it names an
    ExtensionChainShapeField concept, but it does not define the complete set.
"""

import json
import sys
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

        # A command tag carries the command name with its API prefix removed, and the Windows headers define macros
        # for two of the resulting names. Every part shares this treatment, so a tag spells the same in all of them.
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
    """Options for the API type descriptors and command tags. This is the public face of the schema: a descriptor is
    the key every trait and Schema is looked up by, and a wrapper can name its own. It needs the API headers and the
    kinds in format/format.h, and nothing else.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'format/format.h',
            'format/platform_types.h',
            'util/defines.h',
            'util/type_list.h',
        ))
        begin_end.system_headers.append('string_view')


class VulkanSchemaCatalogGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the catalog: the master list of descriptors per genre, the curated lists, and the derived lists as
    relations the C++ evaluates. Only the sieves read it."""

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_types.h',
            'schema/schema.h',
            'util/defines.h',
            'util/type_list.h',
        ))


class VulkanSchemaFieldsGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the Field descriptors. A Field names its API type descriptor and a shape, so this needs the types
    file and schema/field.h. Nothing outside an Action's member traits has a reason to name a Field.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_types.h',
            'schema/field.h',
            'util/defines.h',
        ))
        begin_end.system_headers.extend(('cstddef', 'string_view'))


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


class VulkanSchemaApiElementTraitsGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the correspondence between an API element and its decoded representation, in both directions. It
    needs the descriptors and the decoded declarations, generated and hand-written: the args namespace is split
    across two headers, and the command whose decoder is hand-written has its args structure in the hand-written
    one. It needs no Field and no Schema.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'decode/api_element_traits.h',
            'decode/vulkan_decoder_args.h',
            'format/api_call_id.h',
            'generated/generated_vulkan_decoder_args.h',
            'generated/generated_vulkan_schema_types.h',
            'generated/generated_vulkan_struct_decoders.h',
            'util/defines.h',
        ))


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


class VulkanEncodeCaptureWrappersGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the capture wrapper rows: one CaptureWrapperFor specialization per handle descriptor."""

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'encode/vulkan_encode_capture_wrappers.h',
            'util/defines.h',
        ))


class VulkanSchemaBindingDescriptorForGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the descriptor binding rows: one DescriptorFor specialization per structure descriptor."""

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_types.h',
            'binding/descriptor_for.h',
            'util/defines.h',
        ))


class VulkanSchemaEnumerantsGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the enumerant tables: one per enumerated type, value and name in registry order. The index and the
    name lookup over them are hand-written in util/enumerants.h.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'format/platform_types.h',
            'generated/generated_vulkan_schema_types.h',
            'util/defines.h',
            'util/enumerants.h',
        ))


class VulkanEnumToStringHeaderGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the enum ToString declarations: explicit specializations of util/to_string.h's primaries, one per
    native enum and one more per 32-bit mask enum. A specialization is found wherever the primary is, by the generic
    formatters too, which an overload would not be. Callers include only this; the tables stay in the .cpp.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'format/platform_types.h',
            'schema/schema.h',
            'util/defines.h',
            'util/to_string.h',
        ))


class VulkanEnumToStringBodyGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the enum ToString definitions, one line each over the enumerant tables, and the explicit
    instantiations of the descriptor-keyed forms for the 64-bit flag-bits types. The bodies they forward to are in
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
            'decode/api_element_traits.h',
            'decode/vulkan_decoder_args.h',
            'generated/generated_vulkan_decoder_args.h',
            'generated/generated_vulkan_schema.h',
            'generated/generated_vulkan_decode_api_element_traits.h',
            'generated/generated_vulkan_binding_descriptor_for.h',
            'generated/generated_vulkan_schema_catalog.h',
            'generated/generated_vulkan_schema_enumerants.h',
            'generated/generated_vulkan_struct_decoders.h',
            'binding/descriptor_for.h',
            'schema/schema.h',
            'util/defines.h',
            'util/enumerants.h',
        ))
        begin_end.system_headers.append('type_traits')


class VulkanSchemaBaseGenerator(VulkanBaseGenerator):
    """Shared model for every part of the Vulkan field schema. One subclass for each generated file: the model is
    built here and write_part decides which of it that file carries.
    """

    # Registry type to logical kind, for the primitive spellings the base generator does not already classify. The
    # fixed-width integers come from KhronosBaseGenerator.encode_types; these five are the ones it lacks.
    PRIMITIVE_KINDS = {
        'int': 'Int32',
        'float': 'Float',
        'double': 'Double',
        'char': 'Char',
        'wchar_t': 'WChar',
    }

    # The refinements. This is curated data about the API rather than generator logic: the registry does not say
    # which types carry a kind of their own, so it comes from GFXReconstruct's hand-written encoder, and it is the
    # content a data file beside blacklists.json would hold.
    #
    # The three Vulkan entries stop the resolution the procedural decoders perform: those follow the registry's
    # basetype chain to a primitive, so VkDeviceSize decodes as DecodeUInt64. That is not a bug and not a width
    # difference -- VkDeviceSize is uint64_t and its wire type is uint64_t. The schema declines to resolve them so
    # the kind survives into the field model, where a consumer can tell a device size from an arbitrary 64-bit
    # integer. size_t is here for the other reason: it really does vary, 4 or 8 bytes in memory against 8 on the
    # wire.
    #
    # No width is stated here. A kind's wire type lives on the kind, in format/format.h, and the generated checks
    # file asserts against it: every scalar descriptor's element is as wide as its kind's wire type, and every
    # refinement here records the same bytes as the primitive the encoder resolves it to.
    CURATED_KINDS = {
        'size_t': 'SizeT',
        'VkDeviceSize': 'DeviceSize',
        'VkDeviceAddress': 'DeviceAddress',
        'VkSampleMask': 'SampleMask',
    }

    # Kinds whose element is not a scalar, so the width check does not apply to them. Char and WChar have wire
    # types, but text is reached through a string decoder and wchar_t is 2 or 4 bytes against 2 on the wire.
    NON_SCALAR_KINDS = ('Char', 'WChar', 'Address', 'Handle', 'Struct', 'Void')

    # Types the API headers do not declare with a distinct name of their own, so a descriptor cannot be named for
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

    # Descriptor names for the types whose registry spelling is not a usable identifier. A descriptor is a type of
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
    # by a sibling field at run time. The type alone cannot express that, so those fields name one shared descriptor.
    GENERIC_HANDLE_DESCRIPTOR = 'GenericHandle'

    # An opaque pointer: a handle to something outside the API, or a pointer to memory this process does not own.
    # It is recorded as the 64-bit value the capture saw, and replay resolves it through
    # PreProcessExternalObject. The type alone cannot express that -- the declared type is void, and a void
    # pointer with a count is a run of bytes, not an address -- so the fields that mean it name one shared
    # descriptor, selected by the base generator's EXTERNAL_OBJECT_TYPES the same way four other generators
    # select it.
    EXTERNAL_OBJECT_DESCRIPTOR = 'ExternalObject'

    # A counted run of bytes the API declares as a void pointer. The capture stores the bytes and nothing else, so
    # the element is uint8_t and the kind is UInt8, the same as a declared byte array; the descriptor's name is what
    # keeps the two apart for anything that reads the schema. The Action constrains on kind, so one overload serves
    # both.
    OPAQUE_BYTES_DESCRIPTOR = 'OpaqueBytes'

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
        self.schema_structs = []  # Structure names that get a Schema specialization.
        self.schema_commands = []  # Command names that get a Schema specialization.
        self.api_type_kinds = dict()  # Descriptor name to format::kind expression.
        self.api_type_elements = dict()  # Descriptor name to element type expression.
        self.defaulted_types = set()  # Registry types that reached the Scalar fallback without being classified.
        # Enum groups the registry declares type="bitmask", to the mask type their values compose into: the API's
        # 32-bit flags type unless the group states bitwidth="64".
        self.bitmask_types = dict()

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
        # Every filtered structure gets a Schema: that set already holds no alias, no union and none of the
        # structures whose decoders or encoders are hand-written.
        self.schema_structs = list(self.get_all_filtered_struct_names())

        # Every decodable structure gets a traits row, hand-written decoder or not, so schema-driven code can
        # reach its Decoded_ type.
        self.schema_decodable_structs = list(self.get_decodable_struct_names())

        self.schema_commands = list(self.get_all_filtered_cmd_names())

        # 'void' always has a descriptor, because a void command still has one Return Field.
        self.add_api_type('void')

        # One shared descriptor for the runtime-typed handle fields.
        self.api_type_kinds[self.GENERIC_HANDLE_DESCRIPTOR] = 'Handle'
        self.api_type_elements[self.GENERIC_HANDLE_DESCRIPTOR] = 'uint64_t'

        # One element is the address itself, not what it points at, the same way GenericHandle's element is the
        # uint64_t it stores rather than the object it names. So a Value-shaped field of this descriptor is a
        # void*, and a Pointer-shaped one is a void** -- which is what the declarations say.
        self.api_type_kinds[self.EXTERNAL_OBJECT_DESCRIPTOR] = 'Address'
        self.api_type_elements[self.EXTERNAL_OBJECT_DESCRIPTOR] = 'void*'

        # The bytes a counted void pointer names. Registered here rather than through the member's declared type,
        # which is void.
        self.api_type_kinds[self.OPAQUE_BYTES_DESCRIPTOR] = 'UInt8'
        self.api_type_elements[self.OPAQUE_BYTES_DESCRIPTOR] = 'uint8_t'

        for struct in self.schema_decodable_structs:
            # Every element that gets a Schema also gets a descriptor, because the decoded representation traits key
            # on the descriptor even when no Field names the type.
            self.add_api_type(struct)

            for value in self.all_struct_members[struct]:
                self.add_api_type(value.base_type)

        # The base structures get a descriptor so the catalog can name them in non_decodable_structures.
        for base_struct in self.get_base_structs():
            self.add_api_type(base_struct)

        for command in self.schema_commands:
            return_type, _, params = self.all_cmd_params[command]
            self.add_api_type(self.clean_return_type(return_type))
            for value in params:
                self.add_api_type(value.base_type)

        # Every structure the registry gives a type gets a descriptor, described or not, so a sieve over
        # structure_type reaches the hand-written encoders of the structures the schema excludes.
        for struct in self.struct_type_names:
            if struct not in self.all_struct_aliases:
                self.add_api_type(struct)

        # The structures deep copy does not handle, from the blacklists file; the deep-copy generator reads the same
        # list. Emitted as catalog data for the names that are structure descriptors.
        with open(self.genOpts.blacklists, 'r') as blacklists:
            self.deep_copy_exclusions = json.load(blacklists)['structures-deep-copy']

        # Every enumerated type gets a descriptor, named or not, so its enumerant table has a key.
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

    def is_opaque_bytes(self, value):
        """A counted run of bytes the API declares as a void pointer.

        The capture stores it as bytes and nothing else: the wrapper declares PointerDecoder<uint8_t> and the
        decoder reads uint8_t elements. void names no element, so the field names OPAQUE_BYTES_DESCRIPTOR, whose
        element is the one the capture keeps and whose name records that the API said void. That is the sibling of
        is_external_object, which takes the uncounted case -- the same is_array test those generators make, read
        the other way.
        """
        return value.base_type in self.EXTERNAL_OBJECT_TYPES and value.is_pointer and value.is_array

    def is_external_object(self, value):
        """A pointer to something outside the API, recorded as the 64-bit value the capture saw.

        The same test the struct decoders, the decoder bodies, the JSON consumer, the replay consumers and deep
        copy already make, reading the same inherited list. Two void pointers are not this. A counted one is a run
        of bytes, which decodes into storage rather than being recorded as an address; those generators exclude it
        with the same is_array test. The extension chain is also declared void*, and they exclude it by handling
        pNext before they reach this test at all, which is what the first test here does.
        """
        if self.is_extended_struct_definition(value):
            return False

        return (
            value.base_type in self.EXTERNAL_OBJECT_TYPES and value.is_pointer
            and not value.is_array
        )

    def get_descriptor_name(self, base_type):
        """The identifier of the API type descriptor for a registry type."""
        resolved = self.resolve_type_alias(base_type)
        return self.DESCRIPTOR_NAME_FOR_TYPE.get(resolved, resolved)

    def get_descriptor_path(self, base_type):
        """The descriptor's path from the schema namespace, for a line emitted at schema scope."""
        return 'vulkan::api_types::{}'.format(self.get_descriptor_name(base_type))

    def get_descriptor_reference(self, name):
        """The descriptor's spelling from inside the API's own namespace, where a field descriptor is emitted: lookup
        reaches schema::vulkan from schema::vulkan::fields::<owner>, so the API component is not written."""
        return 'api_types::{}'.format(name)

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
        """The API's own C++ type for one element of a field that names this descriptor.

        This is the element type, not the declared type of any field. The shape supplies the packaging, so a
        pointer-array field naming this descriptor is declared as a pointer to this type.
        """
        resolved = self.resolve_type_alias(base_type)

        if resolved == 'void':
            return 'void'

        if resolved in self.PRIMITIVE_TYPES:
            return resolved

        # Everything else is a name the API headers declare at global scope. The qualification matters, because a
        # descriptor carries the name of the type it describes.
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

    def kind_for_type(self, name):
        """The logical kind a registry type name carries of its own, or None when nothing names one."""
        kind = self.CURATED_KINDS.get(name)

        if kind is None:
            kind = self.PRIMITIVE_KINDS.get(name)

        if kind is None:
            kind = self.encode_types.get(name)

        return kind

    def get_logical_kind(self, base_type):
        """Select the logical kind that names the Encode and Decode operation for a registry type."""
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

        # A function pointer and a pointer to a non-API object are both recorded as a 64-bit address.
        if self.is_function_ptr(resolved):
            return 'Address'

        curated = self.kind_for_type(resolved)

        if curated is not None:
            return curated

        if self.has_basetype(resolved):
            underlying = self.get_basetype(resolved)

            if underlying == 'void':
                return 'Address'

            curated = self.kind_for_type(underlying)

            if curated is not None:
                return curated

        # Nothing classified this type. format::kind::Scalar has no wire type, so it satisfies the
        # scalar concepts but cannot be encoded, and the generator reports it.
        self.defaulted_types.add(resolved)
        return 'Scalar'

    def add_api_type(self, base_type):
        name = self.get_descriptor_name(base_type)

        if name in self.api_type_kinds:
            return

        # A kind that format::kind does not declare fails the build at the symbol, and a kind narrower than its
        # element fails the width assertion the checks file carries. Neither is restated here.
        kind = self.get_logical_kind(base_type)

        self.api_type_kinds[name] = kind
        self.api_type_elements[name] = self.get_element_type(base_type)

    #
    # Field model
    #

    def get_command_tag(self, command):
        return VulkanBaseGenerator.make_args_struct_name(command)

    def get_field_namespace(self, element):
        return 'vulkan::fields::{}'.format(element)

    def get_field_path(self, element, field_name):
        return '{}::{}'.format(self.get_field_namespace(element), field_name)

    def get_field_shape(self, value):
        """The shape defines how one field use packages its API type at this use site."""
        if self.is_extended_struct_definition(value):
            return 'ExtensionChain'

        # A direct opaque address is a value. The declaration writes a star, but nothing is at the other end to
        # decode: the capture recorded the pointer itself, which is what a handle does with a star-free
        # declaration. Shape says what the use site does, so it says Value.
        #
        # One more star is a different field. void** is an output slot: the capture records a pointer to an
        # address, the decoder reads it into a PointerDecoder, and replay writes the resolved pointer back through
        # it. That is pointer-shaped, and the depth test below is the one the decoder bodies already make.
        if self.is_external_object(value) and value.pointer_count == 1:
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
                return 'Constant<{}{}>'.format(node[1], suffix)
            if node[0] == 'sibling':
                return 'FieldValue<{}>'.format(node[1])
            if node[0] == 'constant':
                return 'Constant<{}>'.format(node[1])
            return '{}<{}, {}>'.format(operators[node[0]], emit(node[1]), emit(node[2]))

        return emit(tree)

    def get_field_count(self, value, members):
        """The field_count expression, or None when no Action can evaluate the registry length."""
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
        """The NOTE line written above a descriptor whose count is arithmetic, carrying the registry's text."""
        if self.parse_count_expression(value, members) is None:
            return None

        return '// NOTE: field_count evaluates {}'.format(value.array_length)

    def get_static_array_extents(self, value):
        """The declared extents of a fixed-extent array member, in declaration order, as the registry spells them."""
        return [part.strip() for part in value.array_capacity.split(',')]

    def make_field_definition(self, value, members, generic_handles, owner):
        """One Field descriptor. It names its API type descriptor and its shape, and restates no type fact."""
        shape = self.get_field_shape(value)
        selector = generic_handles.get(value.name)

        if selector is not None:
            descriptor = self.get_descriptor_reference(self.GENERIC_HANDLE_DESCRIPTOR)
        elif self.is_external_object(value):
            descriptor = self.get_descriptor_reference(self.EXTERNAL_OBJECT_DESCRIPTOR)
        elif self.is_opaque_bytes(value):
            descriptor = self.get_descriptor_reference(self.OPAQUE_BYTES_DESCRIPTOR)
        else:
            descriptor = self.get_descriptor_reference(self.get_descriptor_name(value.base_type))

        parts = [
            'using api_type = {};'.format(descriptor),
            'using shape = field_shape::{};'.format(shape),
        ]

        if selector is not None:
            parts.append('using selector_field = {};'.format(selector))

        if shape == 'ExtensionChain':
            # Whether the registry declares the owner on either side of structextends. The base generator names the
            # complement after the spec's usual consequence, "pNext must be NULL"; the schema records the registry
            # fact, which the spec's text does not always match (VkPipelineCreateInfoKHR requires a node).
            parts.append(
                'static constexpr bool has_extensions = {};'.format(
                    'false' if self.must_extended_struct_be_null(owner) else 'true'
                )
            )

        field_count = self.get_field_count(value, members)

        if field_count:
            parts.append('using field_count = {};'.format(field_count))
        elif value.array_length and shape in ('Array', 'StaticArray'):
            parts.append(
                'static constexpr std::string_view length_expression = "{}";'.
                format(value.array_length)
            )

        if shape in ('Pointer', 'Array', 'PointerArray'):
            parts.append(
                'static constexpr size_t pointer_count = {};'.format(
                    value.pointer_count
                )
            )

        if shape == 'StaticArray':
            # The declared extents in declaration order, so extents[i] is std::extent_v<Member, i>. The registry
            # spells them as it spells the declaration, constant names included, and the checks file asserts
            # each against the declared member type.
            parts.append(
                'static constexpr size_t extents[] = {{{}}};'.format(
                    ', '.join(self.get_static_array_extents(value))
                )
            )

        # The descriptor member is field_name rather than name, because Vulkan declares members called 'name' and a
        # member cannot share the name of its enclosing class.
        parts.append(
            'static constexpr std::string_view field_name = "{}";'.format(
                value.name
            )
        )

        return 'struct {} {{ {} }};'.format(value.name, ' '.join(parts))

    def make_return_field_definition(self, return_type):
        """Every command has one Return Field, including a VoidReturn Return Field for a void command."""
        is_void = self.clean_return_type(return_type) == 'void'

        parts = [
            'using api_type = {};'.format(
                self.get_descriptor_reference(self.get_descriptor_name(self.clean_return_type(return_type)))
            ),
            'using shape = field_shape::{};'.format(
                'VoidReturn' if is_void else 'Value'
            ),
            'static constexpr bool is_return = true;',
            'static constexpr std::string_view field_name = "{}";'.format(
                self.RETURN_FIELD_NAME
            ),
        ]

        return 'struct {} {{ {} }};'.format(
            self.RETURN_FIELD_NAME, ' '.join(parts)
        )

    def write_field_namespace(self, element, members, owner, is_command, return_type=None):
        """One namespace of Field descriptors for one API element."""
        write(
            'GFXRECON_BEGIN_NAMESPACE({})'.format(element), file=self.outFile
        )

        generic_handles = self.get_generic_handles(owner, is_command, members)

        # A field_count or a selector_field names a sibling, and the Vulkan registry always declares that sibling
        # before the member that names it, so the descriptors are written in declaration order with no forward
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

    def make_schema_specialization(self, key, element, field_names):
        """One Schema specialization. Its Fields list is the canonical field order for the API element."""
        namespace = self.get_field_namespace(element)
        entries = ['{}::{}'.format(namespace, name) for name in field_names]

        lines = ['template <>', 'struct Schema<{}>'.format(key), '{']
        prefix = '    using Fields = util::TypeList<'
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

    def write_api_type_descriptors(self):
        write(
            '// API type descriptors. A descriptor carries the API\'s own type for one element and the logical kind',
            file=self.outFile
        )
        write(
            '// that names its Encode and Decode operation. It carries no wire representation type and no decoded',
            file=self.outFile
        )
        write(
            '// representation; each kind in format/format.h carries the wire type it is recorded as.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()
        write('// The enumerant tables, defined in generated_vulkan_schema_enumerants.h. A descriptor names its own.', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(enumerants)', file=self.outFile)
        for enum in self.get_enumerated_types():
            write('struct {};'.format(enum), file=self.outFile)
        write('GFXRECON_END_NAMESPACE(enumerants)', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(api_types)', file=self.outFile)

        bitvalues = self.get_bitvalues_of_bitmasks()
        for name in sorted(self.api_type_kinds):
            members = 'using element_type = {0}; using kind = format::kind::{1}; static constexpr std::string_view name = "{2}";'.format(
                self.api_type_elements[name], self.api_type_kinds[name], self.api_type_elements[name].lstrip(':')
            )
            structure_type = self.get_structure_type(name)
            if structure_type is not None:
                members += ' static constexpr {} structure_type = {};'.format(
                    '::' + self.get_struct_type_enum_name(), structure_type
                )
            # Qualified from the global namespace: within the descriptor an unqualified enumerants would change
            # meaning once the member of that name is declared.
            if self.is_enumerated(name):
                members += ' using enumerants = ::gfxrecon::schema::vulkan::enumerants::{};'.format(name)
                if name in self.bitmask_types:
                    members += ' using bitmask = ::{};'.format(self.bitmask_types[name])
            elif name in bitvalues:
                members += ' using bitvalues = ::gfxrecon::schema::vulkan::api_types::{};'.format(bitvalues[name])
            write('struct {} {{ {} }};'.format(name, members), file=self.outFile)

        write('GFXRECON_END_NAMESPACE(api_types)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()

    def write_catalog(self):
        write('// The catalog: what exists, per genre. The master list and the curated lists are generated; every other', file=self.outFile)
        write('// entry is a relation, base plus predicate or base plus exclude list, evaluated here. The checks file', file=self.outFile)
        write('// asserts each derived size against the generator\'s count.', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(catalog)', file=self.outFile)
        self.newline()
        self.write_catalog_list('structures', 'Every structure descriptor.', self.get_structure_descriptors())
        write('// The structures a pNext chain can hold: every descriptor with a structure_type.', file=self.outFile)
        write('using extensible_structures = decltype(util::TypeListKeep(structures{}, kHasStructureType));', file=self.outFile)
        self.newline()

        # In Vulkan, currently only the base structures are non-decodable.
        self.write_catalog_list('non_decodable_structures', 'The list of non-decodable structures, that cannot be present in an encode, nor instantiated.', list(self.get_base_structs()))
        write('// The decodable structures by exclusion.', file=self.outFile)
        write('using decodable_structures = decltype(util::TypeListExclude(structures{}, non_decodable_structures{}));', file=self.outFile)
        self.newline()

        self.write_catalog_list(
            'deep_copy_exclusions',
            'The structures vulkan_struct_deep_copy does not handle: structures-deep-copy in the blacklists file.',
            self.get_deep_copy_excluded_descriptors()
        )
        write('// What vulkan_struct_deep_copy_stype dispatches over.', file=self.outFile)
        write('using deep_copyable_structures = decltype(util::TypeListExclude(extensible_structures{}, deep_copy_exclusions{}));', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(catalog)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()

    def get_deep_copy_excluded_descriptors(self):
        """The deep-copy exclusions that are structure descriptors, by name; an alias in the list names no descriptor."""
        return [name for name in self.get_structure_descriptors() if name in self.deep_copy_exclusions]

    def get_enumerated_types(self):
        """Every enumerated type, by name; its descriptor and its table carry the same name."""
        return sorted(enum for enum in self.enum_names if self.is_enumerated(enum))

    def get_native_enumerated_types(self):
        """The enumerated types that are C enums, by name: every enumerated type but the 64-bit flag-bits typedefs."""
        return [enum for enum in self.get_enumerated_types() if self.api_type_kinds[self.get_descriptor_name(enum)] == 'Enum']

    def get_wide_bitmask_pairs(self):
        """(bits descriptor, typedef descriptor) for each 64-bit flag-bits type whose typedef has a descriptor."""
        return sorted(
            (enum, flags) for flags, enum in self.get_bitvalues_of_bitmasks().items()
            if flags in self.api_type_kinds and self.api_type_kinds[self.get_descriptor_name(enum)] == 'Flags64'
        )

    def get_bitvalues_of_bitmasks(self):
        """Mask typedef descriptor name to the descriptor name of the bits enum whose values compose it, from the
        registry's requires or bitvalues attribute on the typedef, for the typedefs that have a descriptor."""
        result = dict()
        for enum in self.get_enumerated_types():
            if enum not in self.bitmask_types:
                continue
            flags = self.get_flags_type_from_enum(enum)
            if flags is not None:
                result[self.get_descriptor_name(flags)] = enum
        return result

    def write_catalog_list(self, name, comment, structs):
        write('// {}'.format(comment), file=self.outFile)
        write('using {} = util::TypeList<'.format(name), file=self.outFile)
        for i, struct in enumerate(structs):
            write('    api_types::{}{}'.format(struct, ',' if i + 1 < len(structs) else '>;'), file=self.outFile)
        self.newline()

    def get_structure_descriptors(self):
        """Every descriptor of kind Struct, by name."""
        return [name for name in sorted(self.api_type_kinds) if self.api_type_kinds[name] == 'Struct']

    def get_structure_type(self, name):
        """The registry's structure type enumerant for a structure descriptor, or None: an alias or a type without one."""
        if name in self.all_struct_aliases or name not in self.struct_type_names:
            return None
        return self.struct_type_names[name]

    def write_command_tags(self):
        write(
            '// Command tags. A command tag is a schema key and a traits key. It carries no members of its own.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(commands)', file=self.outFile)

        for command in self.schema_commands:
            write(
                'struct {} {{}};'.format(self.get_command_tag(command)),
                file=self.outFile
            )

        write('GFXRECON_END_NAMESPACE(commands)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()

    def write_field_descriptors(self):
        write(
            '// Field descriptors. A Field names its API type and its shape at this use site.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(fields)', file=self.outFile)
        self.newline()

        for struct in self.schema_structs:
            self.write_field_namespace(
                struct, self.all_struct_members[struct], struct, False
            )

        for command in self.schema_commands:
            return_type, _, params = self.all_cmd_params[command]
            self.write_field_namespace(
                self.get_command_tag(command),
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
            '// Schemas. A structure keys on its API type descriptor and a command on its command tag, which is the',
            file=self.outFile
        )
        write(
            '// same key ApiElementTraits uses, so one spelling reaches both.',
            file=self.outFile
        )
        self.newline()

        for struct in self.schema_structs:
            names = [value.name for value in self.all_struct_members[struct]]
            write(
                self.make_schema_specialization(
                    self.get_descriptor_path(struct), struct, names
                ),
                file=self.outFile
            )
            self.newline()

        for command in self.schema_commands:
            _, _, params = self.all_cmd_params[command]
            tag = self.get_command_tag(command)
            names = [value.name for value in params]
            names.append(self.RETURN_FIELD_NAME)
            write(
                self.make_schema_specialization(
                    'vulkan::commands::{}'.format(tag), tag, names
                ),
                file=self.outFile
            )
            self.newline()

    def write_api_element_traits(self):
        """The correspondence between an API element and its decoded representation, in both directions."""
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()

        for struct in self.schema_decodable_structs:
            write(
                'template <> struct ApiElementTraits<schema::vulkan::api_types::{name}> '
                '{{ using decoded_type = Decoded_{name}; }};'.format(name=struct),
                file=self.outFile
            )

        self.newline()

        # A command's decoded wrapper is today's args structure. The formal API-signature storage the design also
        # names does not exist yet, so no decoded_value_type is emitted for a command either.
        #
        # Every command gets traits, including the one whose args structure is hand-written because its decoder is.
        # That structure is a derivation of the same schema and must have the canonical shape; the member-trait
        # partition names its members and the checks file names its type, so a departure fails the build.
        for command in self.schema_commands:
            tag = self.get_command_tag(command)
            write(
                'template <> struct ApiElementTraits<schema::vulkan::commands::{tag}> '
                '{{ using decoded_type = args::{tag}; '
                'static constexpr format::ApiCallId call_id = format::ApiCallId::ApiCall_{command}; }};'.format(
                    tag=tag, command=command
                ),
                file=self.outFile
            )

        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)

    def write_checks(self):
        """Static checks over the whole generated schema, compiled by the framework test target.

        Three of these compare one generator's output against another's. A decoded wrapper's struct_type comes from
        the struct-decoders generator, which knows nothing about the schema, so agreeing with the descriptor's
        element type is a real cross-check rather than this generator confirming itself.
        """
        # The file already opens gfxrecon, from the options, so only the inner namespace belongs here.
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()

        write('// Every structure has a well formed schema, and no structure has a return Field.', file=self.outFile)

        for struct in self.schema_structs:
            element = 'schema::{}'.format(self.get_descriptor_path(struct))
            write('static_assert(schema::HasSchema<{}>);'.format(element), file=self.outFile)
            write('static_assert(!schema::HasCommandSchema<{}>);'.format(element), file=self.outFile)

        self.newline()
        write(
            '// Every command schema has exactly one return Field, which is what HasCommandSchema tests through',
            file=self.outFile
        )
        write('// TypeListSole.', file=self.outFile)

        for command in self.schema_commands:
            tag = 'schema::vulkan::commands::{}'.format(self.get_command_tag(command))
            write('static_assert(schema::HasCommandSchema<{}>);'.format(tag), file=self.outFile)

        self.newline()
        write('// Each wrapper names its element, and the trait keyed on that element names the wrapper. The two', file=self.outFile)
        write('// come from different generators, so a mis-paired line in either cannot pass.', file=self.outFile)

        for struct in self.schema_structs:
            write(
                'static_assert(std::is_same_v<Decoded<typename Decoded_{name}::api_element>, '
                'Decoded_{name}>);'.format(name=struct),
                file=self.outFile
            )

        self.newline()

        for command in self.schema_commands:
            tag = self.get_command_tag(command)
            write(
                'static_assert(std::is_same_v<Decoded<typename args::{tag}::api_element>, '
                'args::{tag}>);'.format(tag=tag),
                file=self.outFile
            )

        self.newline()
        write(
            '// Cross-generator: the element type on the descriptor against struct_type on the decoded wrapper,',
            file=self.outFile
        )
        write('// which the struct-decoders generator emits without any knowledge of the schema.', file=self.outFile)

        for struct in self.schema_structs:
            write(
                'static_assert(std::is_same_v<schema::ElementType<schema::{path}>, '
                'typename Decoded_{name}::struct_type>);'.format(
                    path=self.get_descriptor_path(struct), name=struct
                ),
                file=self.outFile
            )

        self.newline()
        write('// Cross-source: the extents a StaticArray Field records against the extents of the member the API', file=self.outFile)
        write('// declares. The schema states them so a field is fully described without a storage type; the', file=self.outFile)
        write('// declaration is what the compiler lays out. A header revision that changed one fails here. Structures', file=self.outFile)
        write('// only: a command parameter declared as an array decays to a pointer in the signature, so the three', file=self.outFile)
        write('// such parameters have no declared extents to check against.', file=self.outFile)

        for struct in self.schema_structs:
            for value in self.all_struct_members[struct]:
                if self.get_field_shape(value) != 'StaticArray':
                    continue

                member = 'decltype({}::{})'.format(struct, value.name)
                field = 'schema::{}'.format(self.get_field_path(struct, value.name))

                write(
                    'static_assert(std::rank_v<{member}> == std::extent_v<decltype({field}::extents)>);'.format(
                        member=member, field=field
                    ),
                    file=self.outFile
                )

                for index in range(len(self.get_static_array_extents(value))):
                    write(
                        'static_assert(std::extent_v<{member}, {index}> == {field}::extents[{index}]);'.format(
                            member=member, index=index, field=field
                        ),
                        file=self.outFile
                    )

        self.newline()
        write('// A descriptor states a kind and the kind states the wire type, in format/format.h. A descriptor', file=self.outFile)
        write('// whose element is narrower than its kind would compile and desynchronize the stream, so every', file=self.outFile)
        write('// scalar element is as wide as its wire type. size_t is the one exception, 4 or 8 bytes in memory', file=self.outFile)
        write('// against 8 on the wire, which ValueDecoder converts.', file=self.outFile)

        for name in sorted(self.api_type_kinds):
            kind = self.api_type_kinds[name]

            if kind in self.NON_SCALAR_KINDS or kind == 'SizeT':
                continue

            write(
                'static_assert(sizeof(schema::ElementType<schema::vulkan::api_types::{name}>) == '
                'sizeof(format::EncodeTypeFor<schema::vulkan::api_types::{name}::kind>));'.format(name=name),
                file=self.outFile
            )

        self.newline()
        write('// The encoder captures a refined type by its basetype, so a refinement must record the same bytes', file=self.outFile)
        write('// as the primitive kind it refines.', file=self.outFile)

        for type_name in sorted(self.CURATED_KINDS):
            primitive_kind = self.encode_types.get(self.get_underlying_primitive(type_name))

            if primitive_kind is None:
                continue

            write(
                'static_assert(std::is_same_v<format::EncodeTypeFor<format::kind::{refined}>, '
                'format::EncodeTypeFor<format::kind::{primitive}>>);'.format(
                    refined=self.CURATED_KINDS[type_name], primitive=primitive_kind
                ),
                file=self.outFile
            )

        self.newline()
        self.newline()
        write('// A descriptor carries structure_type exactly when the registry gives the structure one.', file=self.outFile)

        typed = 0
        for struct in self.get_structure_descriptors():
            element = 'schema::vulkan::api_types::{}'.format(struct)
            if self.get_structure_type(struct) is None:
                write('static_assert(!schema::HasStructureType<{}>);'.format(element), file=self.outFile)
            else:
                typed += 1
                write('static_assert(schema::HasStructureType<{}>);'.format(element), file=self.outFile)

        self.newline()
        write('// The sizes the generator counted, then the relation checked arithmetically.', file=self.outFile)
        write(
            'constexpr size_t kStructuresCount = util::TypeListSizeV<schema::vulkan::catalog::structures>;\n' +
            'static_assert(kStructuresCount == {});'.format(len(self.get_structure_descriptors())),
            file=self.outFile
        )
        write(
            'static_assert(util::TypeListSizeV<schema::vulkan::catalog::extensible_structures> == {});'.format(typed),
            file=self.outFile
        )
        write(
            'constexpr size_t kNonDecodableCount = util::TypeListSizeV<schema::vulkan::catalog::non_decodable_structures>;\n' +
            'static_assert(kNonDecodableCount == {});'.format(len(self.get_base_structs())),
            file=self.outFile
        )
        write(
            'constexpr size_t kDecodableCount = util::TypeListSizeV<schema::vulkan::catalog::decodable_structures>;\n' +
            'static_assert(kDecodableCount == (kStructuresCount - kNonDecodableCount));',
            file=self.outFile
        )

        excluded = self.get_deep_copy_excluded_descriptors()
        excluded_typed = [name for name in excluded if self.get_structure_type(name) is not None]
        write(
            'static_assert(util::TypeListSizeV<schema::vulkan::catalog::deep_copy_exclusions> == {});'.format(len(excluded)),
            file=self.outFile
        )
        write(
            'static_assert(util::TypeListSizeV<schema::vulkan::catalog::deep_copyable_structures> == {});'.format(typed - len(excluded_typed)),
            file=self.outFile
        )

        self.newline()
        write('// Every enumerated type\'s descriptor names its table, and every one but a 64-bit flag-bits type is bound to', file=self.outFile)
        write('// its native enum. Nothing is bound to the bare integer types that the 64-bit flag-bits and the Flags', file=self.outFile)
        write('// typedefs are spelled as, which would draw their ToString calls into the enumerant overloads.', file=self.outFile)

        for enum in self.get_enumerated_types():
            element = 'schema::{}'.format(self.get_descriptor_path(enum))
            write('static_assert(schema::HasEnumerants<{}>);'.format(element), file=self.outFile)
            if not self.is_flags_enum_64bit(enum):
                write(
                    'static_assert(std::is_same_v<binding::DescriptorFor<::{}>::type, {}>);'.format(enum, element),
                    file=self.outFile
                )
        self.newline()
        write('// The registry declares a group a bitmask exactly when its name says FlagBits. The two are separate sources,', file=self.outFile)
        write('// so a group that breaks the convention fails here by name.', file=self.outFile)
        for enum in self.get_enumerated_types():
            element = 'schema::{}'.format(self.get_descriptor_path(enum))
            write(
                'static_assert({}schema::HasBitmask<{}>);'.format('' if 'FlagBits' in enum else '!', element),
                file=self.outFile
            )
        self.newline()
        write('// A mask typedef\'s own type is the type its bits compose into: the typedef\'s base type against the bits', file=self.outFile)
        write('// group\'s bitwidth, two places the registry states one width.', file=self.outFile)
        for flags, enum in sorted(self.get_bitvalues_of_bitmasks().items()):
            if flags not in self.api_type_kinds:
                continue
            element = 'schema::{}'.format(self.get_descriptor_path(flags))
            write(
                'static_assert(std::is_same_v<{0}::element_type, {0}::bitvalues::bitmask>);'.format(element),
                file=self.outFile
            )
        self.newline()
        write('static_assert(!binding::HasDescriptor<uint32_t>);', file=self.outFile)
        write('static_assert(!binding::HasDescriptor<uint64_t>);', file=self.outFile)

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

        for struct in self.schema_structs:
            storage = '::{}'.format(struct)

            for value in self.all_struct_members[struct]:
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

        for struct in self.schema_structs:
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
            tag = self.get_command_tag(command)
            storage = 'decode::args::{}'.format(tag)

            for value in params:
                write(
                    self.make_member_pointer(
                        storage, self.get_field_path(tag, value.name),
                        '{}::{}'.format(storage, value.name)
                    ),
                    file=self.outFile
                )

            # A void Return Field has no storage member, so it has no mapping.
            if self.clean_return_type(return_type) != 'void':
                write(
                    self.make_member_pointer(
                        storage,
                        self.get_field_path(tag, self.RETURN_FIELD_NAME),
                        '{}::{}'.format(storage, self.RETURN_FIELD_NAME)
                    ),
                    file=self.outFile
                )

        self.write_member_partition_epilogue()


class VulkanSchemaTypesGenerator(VulkanSchemaBaseGenerator):
    """Generates the API type descriptors and command tags."""

    def write_part(self):
        self.write_schema_part(self.write_api_type_descriptors, self.write_command_tags)


class VulkanSchemaCatalogGenerator(VulkanSchemaBaseGenerator):
    """Generates the catalog lists."""

    def write_part(self):
        self.write_schema_part(self.write_catalog)


class VulkanSchemaEnumerantsGenerator(VulkanSchemaBaseGenerator):
    """Generates the enumerant table of every enumerated type."""

    def write_part(self):
        write('// Enumerants: one table per enumerated type, in registry order, with the name the API spells. For a flag-bits', file=self.outFile)
        write('// type the table holds single bits, combined masks and zero alike: lookups go from value to name, so they', file=self.outFile)
        write('// are not told apart. An alias adds no entry. The type\'s API type descriptor names its table, and each entry', file=self.outFile)
        write('// names the descriptor.', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(schema)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(enumerants)', file=self.outFile)
        self.newline()

        for enum in self.get_enumerated_types():
            enumerants = self.enumEnumerants[enum]
            entry = 'util::Enumerant<{}>'.format(self.get_descriptor_reference(self.get_descriptor_name(enum)))
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


class VulkanEnumToStringHeaderGenerator(VulkanSchemaBaseGenerator):
    """Generates the ToString specialization declarations for every native enum."""

    def write_part(self):
        flags_type = self.get_api_data().flags_type
        flags_64_type = self.get_api_data().flags_64_type
        write('// Explicit specializations of util/to_string.h\'s primaries, one per enum and one more per 32-bit mask enum,', file=self.outFile)
        write('// defined in generated_vulkan_enum_to_string.cpp over the enumerant tables.', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(util)', file=self.outFile)
        self.newline()
        write('// Keyed on the API type descriptor, for the types spelled as a bare integer in C: the 64-bit flag-bits types,', file=self.outFile)
        write('// instantiated in generated_vulkan_enum_to_string.cpp.', file=self.outFile)
        self.newline()
        write('// Requires a descriptor with an enumerant table: one enumerant to its name.', file=self.outFile)
        write('template <schema::HasEnumerants Descriptor>', file=self.outFile)
        write('std::string ToString(typename Descriptor::element_type value, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);', file=self.outFile)
        self.newline()
        write('// Requires a mask typedef\'s descriptor: the set bits of a mask, by name.', file=self.outFile)
        write('template <schema::HasBitvalues Descriptor>', file=self.outFile)
        write('std::string ToString({} flags, ToStringFlags toStringFlags = kToString_Default, uint32_t tabCount = kToStringDefaultTabCount, uint32_t tabSize = kToStringDefaultTabSize);'.format(flags_64_type), file=self.outFile)
        self.newline()
        for enum in self.get_native_enumerated_types():
            write(
                'template <> std::string ToString<{0}>(const {0}& value, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);'.format(enum),
                file=self.outFile
            )
            if enum in self.bitmask_types:
                write(
                    'template <> std::string ToString<{0}>({1} vkFlags, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize);'.format(enum, flags_type),
                    file=self.outFile
                )
        self.newline()
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)


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
        write('// The 64-bit flag-bits types, by descriptor: the bits descriptor names one enumerant, the typedef\'s expands a mask.', file=self.outFile)
        for bits, flags in self.get_wide_bitmask_pairs():
            for descriptor in (bits, flags):
                write(
                    'template std::string ToString<schema::vulkan::api_types::{0}>({1}, ToStringFlags, uint32_t, uint32_t);'.format(descriptor, api_data.flags_64_type),
                    file=self.outFile
                )
        self.newline()
        write('GFXRECON_END_NAMESPACE(util)', file=self.outFile)


class VulkanSchemaFieldsGenerator(VulkanSchemaBaseGenerator):
    """Generates the Field descriptors."""

    def write_part(self):
        self.write_schema_part(self.write_field_descriptors)


class VulkanSchemaGenerator(VulkanSchemaBaseGenerator):
    """Generates the Schema specializations that order the Fields."""

    def write_part(self):
        self.write_schema_part(self.write_schemas)


class VulkanSchemaApiElementTraitsGenerator(VulkanSchemaBaseGenerator):
    """Generates ApiElementTraits: an API element to its decoded representation. The other direction is the
    api_element member each wrapper carries, emitted by the wrapper's own generator.
    """

    def write_part(self):
        self.write_api_element_traits()


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


class VulkanEncodeCaptureWrappersGenerator(VulkanSchemaBaseGenerator):
    """One CaptureWrapperFor row per handle descriptor, by the naming rule the base generator applies to every
    procedural handle call: the handle name without its Vk prefix, plus Wrapper. The source is the schema's handle
    descriptors, not the registry's handles, so a handle the generator filters out gets no row; a handle without a
    wrapper struct fails at its row.
    """

    def write_part(self):
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        self.newline()
        for name in sorted(self.api_type_kinds):
            if self.api_type_kinds[name] != 'Handle' or name == self.GENERIC_HANDLE_DESCRIPTOR:
                continue
            write('GFXRECON_VULKAN_CAPTURE_WRAPPER_FOR({}, {}Wrapper);'.format(name, name[2:]), file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)


class VulkanSchemaBindingDescriptorForGenerator(VulkanSchemaBaseGenerator):
    """One DescriptorFor row per structure descriptor: the native structure to its API type descriptor."""

    def write_part(self):
        write('GFXRECON_BEGIN_NAMESPACE(binding)', file=self.outFile)
        self.newline()
        for struct in sorted(self.get_structure_descriptors()):
            write('GFXRECON_BINDING_DESCRIPTOR_FOR(::{0}, schema::vulkan::api_types::{0});'.format(struct), file=self.outFile)
        self.newline()
        # A 64-bit flag-bits type is spelled VkFlags64, so a row for it would bind the bare integer type.
        for enum in self.get_enumerated_types():
            if not self.is_flags_enum_64bit(enum):
                write('GFXRECON_BINDING_DESCRIPTOR_FOR(::{0}, schema::vulkan::api_types::{0});'.format(enum), file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(binding)', file=self.outFile)
