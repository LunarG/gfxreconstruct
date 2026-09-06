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
The parts are separate files because member traits are partitioned by storage population, and only the target that
owns an operation includes the population it needs.

This is the initial version. It emits:

    one API type descriptor for each registry type that a Field names or a Schema keys on
    one command tag for each command
    one Field descriptor for each command parameter and structure member
    one Return Field for each command, including a Absent Return Field for a void command
    one Schema specialization for each command and structure
    one decoded representation trait for each structure and each generated command decoder
    one member trait for each valid storage and Field pair, in three storage populations

It does not yet emit:

    semantic metadata, on either the API type descriptor or the Field descriptor
    capture_wrapper_type on a handle descriptor, which needs an authoritative handle to wrapper mapping
    formal API-signature storage and its member traits, and the decoded metadata storage population
    runtime dispatch tables, custom hooks, command lifecycle traits, or the args compatibility bindings

Two Field descriptor properties differ from the design text, because the registry forces the difference:

    The name property is emitted as field_name. Vulkan declares members called 'name', and a class member cannot
    share the name of its enclosing class.
    The shape vocabulary adds Pointer, StaticArray, and ExtensionChain to Value, PointerArray, and Absent. The
    design names field_shape::Value, field_shape::PointerArray, and field_shape::Absent, and it names an
    ExtensionChainField concept, but it does not define the complete set.
"""

import sys
from khronos_base_generator import write
from khronos_struct_decoders_header_generator import KhronosStructDecodersHeaderGenerator
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions

# The parts of the generated schema.
# Structures whose DecodeStruct comes from the schema field walk. The struct-decoders generators read this and skip
# both the procedural body and the prototype; the hand-written constrained template in decode/vulkan_decode_struct.h
# supplies the definition. Their decoded wrapper is still generated as usual.
#
# A structure may only appear here when the decode Action has an Apply overload for every one of its fields.
# WalkFields fails to compile and names the field when it does not, so a wrong entry is a build error, not a silent
# gap.
SCHEMA_OWNED_STRUCT_DECODERS = (
    'VkBufferMemoryBarrier',
    'VkImageSubresourceRange',
    'VkImageMemoryBarrier',
    'VkShaderModuleCreateInfo',
    'VkSparseBufferMemoryBindInfo',
    'VkTransformMatrixKHR',
    'VkDeviceBufferMemoryRequirements',
    'StdVideoAV1TileInfoFlags',
    'VkCheckpointData2NV',
    'VkAllocationCallbacks',
    'VkRenderPassAttachmentBeginInfo',
    'VkDebugUtilsLabelEXT',
    'VkLayerProperties',
    'VkPipelineCacheCreateInfo',
    'VkRenderingInputAttachmentIndexInfo',
    'VkImageBlit2',
)


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


class VulkanSchemaIdentityGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the schema itself: logical kinds, API type descriptors, command tags, Field descriptors, and the
    Schema specializations that order them. It needs the API headers and nothing else.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'format/platform_types.h',
            'util/defines.h',
            'schema/schema.h',
            'util/type_list.h',
        ))
        begin_end.system_headers.extend(('cstddef', 'string_view'))


class VulkanSchemaApiElementTraitsGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the correspondence between an API element and its decoded representation, in both directions. It
    needs the generated decoded declarations.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'decode/api_element_traits.h',
            'format/api_call_id.h',
            'generated/generated_vulkan_decoder_args.h',
            'generated/generated_vulkan_schema.h',
            'generated/generated_vulkan_struct_decoders.h',
            'util/defines.h',
        ))


class VulkanSchemaMemberPartitionGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Shared options for a member-trait partition: one file for each storage population. A subclass adds the
    declarations of the storage type it is keyed on.
    """

    def storage_header(self):
        """The header declaring this partition's storage type, or None when the API headers already supply it."""
        return None

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema.h',
            'util/defines.h',
            'schema/field.h',
        ))

        storage_header = self.storage_header()
        if storage_header:
            begin_end.specific_headers.append(storage_header)

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

    def storage_header(self):
        return 'generated/generated_vulkan_struct_decoders.h'


class VulkanSchemaDecodedCommandMembersGeneratorOptions(
    VulkanSchemaMemberPartitionGeneratorOptions
):
    """Options for the member traits keyed on a command's decoded argument storage."""

    def storage_header(self):
        return 'generated/generated_vulkan_decoder_args.h'


class VulkanSchemaChecksGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Options for the cross-generator agreement checks. Compiled only by the framework test target, so it costs a
    product build nothing and can include whatever it needs to check. Compiling it is the test; there is nothing to
    run.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'decode/api_element_traits.h',
            'generated/generated_vulkan_decoder_args.h',
            'generated/generated_vulkan_schema.h',
            'generated/generated_vulkan_decode_api_element_traits.h',
            'generated/generated_vulkan_struct_decoders.h',
            'schema/schema.h',
            'util/defines.h',
        ))
        begin_end.system_headers.append('type_traits')


class VulkanSchemaBaseGenerator(VulkanBaseGenerator):
    """Shared model for every part of the Vulkan field schema. One subclass for each generated file: the model is
    built here and write_part decides which of it that file carries.
    """

    # The logical kinds the field model declares. A kind other than Identity, Handle, Struct or Void corresponds to
    # exactly one gfxrecon::format wire typedef, which the kind tag itself carries. The generator validates every
    # The logical kinds the field model declares. The generator validates every kind it emits against this set, so
    # it cannot invent one, and a kind with no wire type fails at the point of use.
    #
    # TO DO -- delete this. It is a copy of the C++ tag list in another language, and it fails in the wrong
    # direction: a kind added in C++ and not here is silently never emitted, while a kind here and not in C++ was
    # already going to fail the build at the symbol. Now that the kinds live in format::kind
    # the build is the check, and this list only adds a second place to update.
    KNOWN_KINDS = (
        'UInt8',
        'UInt16',
        'UInt32',
        'UInt64',
        'Int8',
        'Int16',
        'Int32',
        'Int64',
        'Float',
        'Double',
        'Char',
        'WChar',
        'SizeT',
        'Enum',
        'Flags',
        'Flags64',
        'SampleMask',
        'DeviceSize',
        'DeviceAddress',
        'Address',
        'Handle',
        'Struct',
        'Void',
        'Scalar',
    )

    # Registry type to logical kind. This is curated data about the API rather than generator logic: the registry
    # does not say which types use which encoding, so it comes from GFXReconstruct's hand-written encoder. It belongs
    # in a JSON configuration beside blacklists.json, and is inline for now so the content is reviewable in one place
    # with the rules that consume it.
    # Registry type to logical kind. The three Vulkan entries are here to stop the resolution the procedural
    # decoders perform: those follow the registry's basetype chain to a primitive, so VkDeviceSize decodes as
    # DecodeUInt64. That is not a bug and not a width difference -- VkDeviceSize is uint64_t and its wire type is
    # uint64_t. The schema declines to resolve them so the kind survives into the field model, where a consumer can
    # tell a device size from an arbitrary 64-bit integer. size_t is in this list for the other reason: it really
    # does vary, 4 or 8 bytes in memory against 8 on the wire.
    #
    # TO DO -- the eight primitive rows duplicate KhronosBaseGenerator.encode_types, which this generator inherits.
    # Seed from self.encode_types and keep here only what differs, so the list reads as the deliberate divergences
    # rather than hiding them among copies. Left alone for now to keep the procedural generators untouched.
    KIND_FOR_TYPE = {
        'int8_t': 'Int8',
        'int16_t': 'Int16',
        'int32_t': 'Int32',
        'int64_t': 'Int64',
        'uint8_t': 'UInt8',
        'uint16_t': 'UInt16',
        'uint32_t': 'UInt32',
        'uint64_t': 'UInt64',
        'int': 'Int32',
        'float': 'Float',
        'double': 'Double',
        'char': 'Char',
        'wchar_t': 'WChar',
        'size_t': 'SizeT',
        'VkDeviceSize': 'DeviceSize',
        'VkDeviceAddress': 'DeviceAddress',
        'VkSampleMask': 'SampleMask',
    }

    # The primitive each kind's element type must ultimately resolve to. A kind duplicates part of what element_type
    # says, and this is where that duplication is checked: the generator assigns both from one type resolution, so a
    # disagreement is a bug in that resolution and is caught here rather than reaching the wire.
    #
    # Enum, Address, Handle, Struct and Void are absent because their element types are not primitives.
    KIND_ELEMENT_BASETYPE = {
        'Int8': ('int8_t', ),
        'Int16': ('int16_t', ),
        'Int32': ('int32_t', 'int'),
        'Int64': ('int64_t', ),
        'UInt8': ('uint8_t', ),
        'UInt16': ('uint16_t', ),
        'UInt32': ('uint32_t', ),
        'UInt64': ('uint64_t', ),
        'Float': ('float', ),
        'Double': ('double', ),
        'Char': ('char', ),
        'WChar': ('wchar_t', ),
        'SizeT': ('size_t', ),
        'SampleMask': ('uint32_t', ),
        'DeviceSize': ('uint64_t', ),
        'DeviceAddress': ('uint64_t', ),
        'Flags': ('uint32_t', ),
        'Flags64': ('uint64_t', ),
    }

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
        self.defaulted_types = set()  # Registry types that reached Identity without being classified.

    #
    # Model
    #

    def build_model(self):
        """Resolve every API type that a Field names, and select the elements that get a Schema."""
        self.schema_structs = [
            struct for struct in self.get_all_filtered_struct_names()
            if struct not in self.all_struct_aliases
            and struct not in self.all_union_aliases
            and struct not in self.union_names
        ]

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

        for struct in self.schema_structs:
            # Every element that gets a Schema also gets a descriptor, because the decoded representation traits key
            # on the descriptor even when no Field names the type.
            self.add_api_type(struct)

            for value in self.all_struct_members[struct]:
                self.add_api_type(value.base_type)

        for command in self.schema_commands:
            return_type, _, params = self.all_cmd_params[command]
            self.add_api_type(self.clean_return_type(return_type))
            for value in params:
                self.add_api_type(value.base_type)

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
        decoder reads uint8_t elements. void names no element, so the descriptor names the element the capture
        actually keeps. That is the sibling of is_external_object, which takes the uncounted case -- the same
        is_array test those generators make, read the other way.

        FOR REVIEW -- naming these uint8_t cooks the schema, and the reviewer is not sold on it.

        What it buys: the existing scalar-run overload takes them unchanged, so the Action needs no specialisation
        at all for the fifteen fields this covers.

        What it costs, measured: nineteen UInt8 pointer-array fields on structures, fifteen from void* and four
        declared uint8_t*, and the schema can no longer tell them apart. A consumer that wants to know a field was
        an opaque blob rather than a declared byte array has nowhere to read it.

        Two ways out, if the cost is judged too high. A distinct kind -- Bytes, say -- restores the distinction but
        buys an Action overload whose body would be identical to the scalar-run one, which is the specialisation
        this was avoiding. Better is probably a distinct descriptor keeping kind UInt8:

            struct OpaqueBytes { using element_type = uint8_t; using kind = format::kind::UInt8; };

        The overloads constrain on kind, not descriptor, so one overload still covers both, and the name carries
        the distinction for anything reading the schema. That looks like both properties at once and is the option
        to weigh first.
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
        return 'api_type::vulkan::{}'.format(self.get_descriptor_name(base_type))

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

    def get_logical_kind(self, base_type):
        """Select the logical kind that names the Encode and Decode operation for a registry type."""
        api_data = self.get_api_data()
        resolved = self.resolve_type_alias(base_type)

        if resolved == 'void':
            return 'Void'

        if self.is_handle_like(resolved):
            return 'Handle'

        if self.is_struct(resolved) or resolved in self.union_names:
            return 'Struct'

        if resolved == api_data.flags_type:
            return 'Flags'

        if resolved == api_data.flags_64_type:
            return 'Flags64'

        if self.is_flags(resolved):
            return 'Flags64' if self.is_64bit_flags(resolved) else 'Flags'

        if self.is_enum(resolved):
            return 'Enum'

        # A function pointer and a pointer to a non-API object are both recorded as a 64-bit address.
        if self.is_function_ptr(resolved):
            return 'Address'

        curated = self.KIND_FOR_TYPE.get(resolved)

        if curated is not None:
            return curated

        if self.has_basetype(resolved):
            underlying = self.get_basetype(resolved)

            if underlying == 'void':
                return 'Address'

            curated = self.KIND_FOR_TYPE.get(underlying)

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

        kind = self.get_logical_kind(base_type)

        if kind not in self.KNOWN_KINDS:
            raise RuntimeError(
                'Vulkan schema: kind {} for {} is not declared by the field model'.format(kind, base_type)
            )

        # A kind restates part of what the element type says. Check the agreement here, in the one loop that assigns
        # both, rather than carrying machinery in the schema to make the restatement impossible.
        expected = self.KIND_ELEMENT_BASETYPE.get(kind)

        if expected is not None:
            underlying = self.get_underlying_primitive(base_type)

            if underlying is not None and underlying not in expected:
                raise RuntimeError(
                    'Vulkan schema: {} has kind {}, which requires an element type resolving to {}, but it '
                    'resolves to {}'.format(base_type, kind, ' or '.join(expected), underlying)
                )

        self.api_type_kinds[name] = kind
        self.api_type_elements[name] = self.get_element_type(base_type)

    #
    # Field model
    #

    def has_decoded_command_storage(self, command):
        """A decoded command wrapper exists only for a command whose decoder is generated."""
        return (
            not self.is_manually_generated_cmd_name(command)
            and command not in self.APICALL_DECODER_BLACKLIST
        )

    def get_command_tag(self, command):
        return VulkanBaseGenerator.make_args_struct_name(command)

    def get_field_namespace(self, element):
        return 'field::vulkan::{}'.format(element)

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
            return 'PointerArray' if value.is_array else 'Pointer'

        return 'Value'

    def get_count_field(self, value, members):
        """The sibling Field that carries the element count, when the length is exactly one sibling name."""
        length = value.array_length

        if not length or value.array_length_value is None:
            return None

        if length != value.array_length_value.name:
            return None

        if not any(member.name == length for member in members):
            return None

        return length

    def make_field_definition(self, value, members, generic_handles):
        """One Field descriptor. It names its API type descriptor and its shape, and restates no type fact."""
        shape = self.get_field_shape(value)
        selector = generic_handles.get(value.name)

        if selector is not None:
            descriptor = 'api_type::vulkan::{}'.format(self.GENERIC_HANDLE_DESCRIPTOR)
        elif self.is_external_object(value):
            descriptor = 'api_type::vulkan::{}'.format(self.EXTERNAL_OBJECT_DESCRIPTOR)
        elif self.is_opaque_bytes(value):
            descriptor = self.get_descriptor_path('uint8_t')
        else:
            descriptor = self.get_descriptor_path(value.base_type)

        parts = [
            'using api_type = {};'.format(descriptor),
            'using shape = field_shape::{};'.format(shape),
        ]

        if selector is not None:
            parts.append('using selector_field = {};'.format(selector))

        count_field = self.get_count_field(value, members)

        if count_field:
            parts.append('using count_field = {};'.format(count_field))
        elif value.array_length and shape in ('PointerArray', 'StaticArray'):
            parts.append(
                'static constexpr std::string_view length_expression = "{}";'.
                format(value.array_length)
            )

        if shape in ('Pointer', 'PointerArray'):
            parts.append(
                'static constexpr size_t pointer_count = {};'.format(
                    value.pointer_count
                )
            )

        if shape == 'StaticArray':
            if value.array_dimension and value.array_dimension > 1:
                parts.append(
                    'static constexpr size_t array_dimension = {};'.format(
                        value.array_dimension
                    )
                )
            else:
                parts.append(
                    'static constexpr size_t extent = {};'.format(
                        value.array_capacity
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
        """Every command has one Return Field, including a Absent Return Field for a void command."""
        is_void = self.clean_return_type(return_type) == 'void'

        parts = [
            'using api_type = {};'.format(
                self.get_descriptor_path(self.clean_return_type(return_type))
            ),
            'using shape = field_shape::{};'.format(
                'Absent' if is_void else 'Value'
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

        # A count_field or a selector_field can name a sibling that the registry declares later, so forward declare
        # every Field that a sibling names.
        referenced = [
            count for count in (
                self.get_count_field(value, members) for value in members
            ) if count
        ]
        referenced.extend(generic_handles.values())

        for member in members:
            if member.name in referenced:
                write('struct {};'.format(member.name), file=self.outFile)

        for value in members:
            write(
                self.make_field_definition(value, members, generic_handles),
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

    def write_identity(self):
        write('GFXRECON_BEGIN_NAMESPACE(schema)', file=self.outFile)
        self.newline()

        self.write_api_type_descriptors()
        self.write_command_tags()
        self.write_field_descriptors()
        self.write_schemas()

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
        write('GFXRECON_BEGIN_NAMESPACE(api_type)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)

        for name in sorted(self.api_type_kinds):
            write(
                'struct {} {{ using element_type = {}; using kind = format::kind::{}; }};'.format(
                    name, self.api_type_elements[name], self.api_type_kinds[name]
                ),
                file=self.outFile
            )

        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(api_type)', file=self.outFile)
        self.newline()

    def write_command_tags(self):
        write(
            '// Command tags. A command tag is a schema key and a traits key. It carries no members of its own.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(command)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)

        for command in self.schema_commands:
            write(
                'struct {} {{}};'.format(self.get_command_tag(command)),
                file=self.outFile
            )

        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(command)', file=self.outFile)
        self.newline()

    def write_field_descriptors(self):
        write(
            '// Field descriptors. A Field names its API type and its shape at this use site.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(field)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)
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

        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(field)', file=self.outFile)
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
                    'command::vulkan::{}'.format(tag), tag, names
                ),
                file=self.outFile
            )
            self.newline()

    def write_api_element_traits(self):
        """The correspondence between an API element and its decoded representation, in both directions."""
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()

        write(
            '// A structure needs no decoded_value_type: that is its element type, which its API type descriptor',
            file=self.outFile
        )
        write('// already carries.', file=self.outFile)

        for struct in self.schema_structs:
            write(
                'template <> struct ApiElementTraits<schema::api_type::vulkan::{name}> '
                '{{ using decoded_type = Decoded_{name}; }};'.format(name=struct),
                file=self.outFile
            )

        self.newline()

        # A command's decoded wrapper is today's generated args structure. The formal API-signature storage the
        # design also names does not exist yet, so no decoded_value_type is emitted for a command either.
        for command in self.schema_commands:
            if not self.has_decoded_command_storage(command):
                continue

            tag = self.get_command_tag(command)
            write(
                'template <> struct ApiElementTraits<schema::command::vulkan::{tag}> '
                '{{ using decoded_type = args::{tag}; '
                'static constexpr format::ApiCallId call_id = format::ApiCallId::ApiCall_{command}; }};'.format(
                    tag=tag, command=command
                ),
                file=self.outFile
            )

        self.newline()
        write(
            '// The inverse. An operation handed a decoded wrapper reaches the schema through this, and decode is',
            file=self.outFile
        )
        write('// not the only operation family that needs to.', file=self.outFile)

        for struct in self.schema_structs:
            write(
                'template <> struct ApiElementFor<Decoded_{name}> '
                '{{ using type = schema::api_type::vulkan::{name}; }};'.format(name=struct),
                file=self.outFile
            )

        self.newline()

        for command in self.schema_commands:
            if not self.has_decoded_command_storage(command):
                continue

            tag = self.get_command_tag(command)
            write(
                'template <> struct ApiElementFor<args::{tag}> '
                '{{ using type = schema::command::vulkan::{tag}; }};'.format(tag=tag),
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
            tag = 'schema::command::vulkan::{}'.format(self.get_command_tag(command))
            write('static_assert(schema::HasCommandSchema<{}>);'.format(tag), file=self.outFile)

        self.newline()
        write('// The two trait directions agree, so a mis-paired line in either cannot pass.', file=self.outFile)

        for struct in self.schema_structs:
            write(
                'static_assert(std::is_same_v<Decoded<typename ApiElementFor<Decoded_{name}>::type>, '
                'Decoded_{name}>);'.format(name=struct),
                file=self.outFile
            )

        self.newline()

        for command in self.schema_commands:
            if not self.has_decoded_command_storage(command):
                continue

            tag = self.get_command_tag(command)
            write(
                'static_assert(std::is_same_v<Decoded<typename ApiElementFor<args::{tag}>::type>, '
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
            if not self.has_decoded_command_storage(command):
                continue

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


class VulkanSchemaIdentityGenerator(VulkanSchemaBaseGenerator):
    """Generates the schema itself: API type descriptors, command tags, Field descriptors, and Schema
    specializations.
    """

    def write_part(self):
        self.write_identity()


class VulkanSchemaApiElementTraitsGenerator(VulkanSchemaBaseGenerator):
    """Generates ApiElementTraits and ApiElementFor: an API element to its decoded representation, and back."""

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
