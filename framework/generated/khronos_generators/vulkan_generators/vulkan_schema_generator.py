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
    one Return Field for each command, including a NoValue Return Field for a void command
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
    The shape vocabulary adds Pointer, StaticArray, and ExtensionChain to Value, PointerArray, and NoValue. The
    design names field_shape::Value, field_shape::PointerArray, and field_shape::NoValue, and it names an
    ExtensionChainField concept, but it does not define the complete set.
"""

import sys
from khronos_base_generator import write
from khronos_struct_decoders_header_generator import KhronosStructDecodersHeaderGenerator
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions

# The parts of the generated schema.
#
# 'identity' is the shared part. It carries logical kinds, API type descriptors, command tags, Field descriptors, and
# the Schema specializations that order them. It needs the API headers and nothing else.
#
# 'decoded_traits' resolves an API element to its decoded representation. It needs the generated decoded declarations.
#
# The remaining parts are member traits, one file for each storage population. They are target-private.
SCHEMA_PART_IDENTITY = 'identity'
SCHEMA_PART_DECODED_TRAITS = 'decoded_traits'
SCHEMA_PART_NATIVE_STRUCT_TRAITS = 'native_struct_traits'
SCHEMA_PART_DECODED_STRUCT_TRAITS = 'decoded_struct_traits'
SCHEMA_PART_DECODED_COMMAND_TRAITS = 'decoded_command_traits'


class VulkanSchemaGeneratorOptions(VulkanBaseGeneratorOptions):
    """Options for generating one part of the Vulkan field schema."""

    def __init__(
        self,
        schema_part=SCHEMA_PART_IDENTITY,
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

        self.schema_part = schema_part

        begin_end = self.begin_end_file_data

        if schema_part == SCHEMA_PART_IDENTITY:
            begin_end.specific_headers.extend((
                'format/platform_types.h',
                'util/defines.h',
                'util/schema_util.h',
                'util/type_list.h',
            ))
            begin_end.system_headers.extend(('cstddef', 'string_view'))
        elif schema_part == SCHEMA_PART_DECODED_TRAITS:
            begin_end.specific_headers.extend((
                'decode/decoded_representation_traits.h',
                'format/api_call_id.h',
                'generated/generated_vulkan_decoder_args.h',
                'generated/generated_vulkan_schema.h',
                'generated/generated_vulkan_struct_decoders.h',
                'util/defines.h',
            ))
        else:
            # A member-trait partition is target-private, and is included by one implementation file. It carries its
            # own include guard so that a target which includes two partitions still compiles.
            guard = 'GFXRECON_{}_INC'.format(
                filename.replace('.', '_').upper()
            ) if filename else 'GFXRECON_VULKAN_SCHEMA_TRAITS_INC'

            begin_end.guards.append(('ifndef', guard))
            begin_end.specific_headers.extend((
                'generated/generated_vulkan_schema.h',
                'util/defines.h',
                'util/schema_field_model.h',
            ))

            if schema_part == SCHEMA_PART_DECODED_STRUCT_TRAITS:
                begin_end.specific_headers.append(
                    'generated/generated_vulkan_struct_decoders.h'
                )
            elif schema_part == SCHEMA_PART_DECODED_COMMAND_TRAITS:
                begin_end.specific_headers.append(
                    'generated/generated_vulkan_decoder_args.h'
                )

            begin_end.specific_headers.sort()
            begin_end.pre_namespace_code.extend(
                ('#define {}'.format(guard), '')
            )

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


class VulkanSchemaGenerator(VulkanBaseGenerator):
    """Generates the Vulkan field schema: API type descriptors, command tags, Field descriptors, Schema
    specializations, decoded representation traits, and partitioned member traits.
    """

    # Logical scalar kinds, keyed by the C++ representation that the registry resolves a named type to. The generated
    # header emits one field_kind leaf for each kind that the API actually uses, because that set follows the registry
    # rather than the hand-written field model.
    SCALAR_KIND_FOR_TYPE = {
        'int8_t': 'Int8',
        'int16_t': 'Int16',
        'int32_t': 'Int32',
        'int64_t': 'Int64',
        'uint8_t': 'UInt8',
        'uint16_t': 'UInt16',
        'uint32_t': 'UInt32',
        'uint64_t': 'UInt64',
        'int': 'Int32',
        'char': 'Char',
        'wchar_t': 'WChar',
        'size_t': 'Size',
        'float': 'Float',
        'double': 'Double',
    }

    # Descriptor names for the types whose registry spelling is not a usable identifier. A descriptor is a type of
    # its own, so it cannot be named for a keyword, and it must not shadow the native type it names.
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

    # Kinds that the hand-written field model owns. The generator must not redefine these.
    FIXED_KINDS = ('Scalar', 'Handle', 'Struct', 'Void')

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
        self.api_type_kinds = dict()  # Descriptor name to field_kind expression.
        self.api_type_natives = dict()  # Descriptor name to native type expression.
        self.scalar_kinds = set()  # Scalar field_kind leaves that the generated descriptors name.
        self.unresolved_types = set()  # Registry types with no logical kind.

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

        if self.unresolved_types:
            write(
                '* Vulkan schema: no logical kind for {}'.format(
                    ', '.join(sorted(self.unresolved_types))
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

    def get_descriptor_name(self, base_type):
        """The identifier of the API type descriptor for a registry type."""
        resolved = self.resolve_type_alias(base_type)
        return self.DESCRIPTOR_NAME_FOR_TYPE.get(resolved, resolved)

    def get_descriptor_path(self, base_type):
        return 'api_type::vulkan::{}'.format(self.get_descriptor_name(base_type))

    def get_native_type(self, base_type):
        """The C++ type expression that a descriptor's native_type names."""
        resolved = self.resolve_type_alias(base_type)

        if resolved == 'void':
            return 'void'

        if resolved in self.SCALAR_KIND_FOR_TYPE:
            return resolved

        # Everything else is a name the API headers declare at global scope. The qualification matters, because a
        # descriptor carries the name of the type it describes.
        return '::{}'.format(resolved)

    def get_logical_kind(self, base_type):
        """Select the logical kind that identifies the Encode and Decode operation for a registry type."""
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

        if self.is_function_ptr(resolved):
            return 'FunctionPointer'

        scalar = self.SCALAR_KIND_FOR_TYPE.get(resolved)

        if scalar is None and self.has_basetype(resolved):
            underlying = self.get_basetype(resolved)
            if underlying == 'void':
                return 'Void'
            scalar = self.SCALAR_KIND_FOR_TYPE.get(underlying)

        if scalar is not None:
            return scalar

        self.unresolved_types.add(resolved)
        return 'Unresolved'

    def add_api_type(self, base_type):
        name = self.get_descriptor_name(base_type)

        if name in self.api_type_kinds:
            return

        kind = self.get_logical_kind(base_type)

        if kind not in self.FIXED_KINDS:
            self.scalar_kinds.add(kind)

        self.api_type_kinds[name] = kind
        self.api_type_natives[name] = self.get_native_type(base_type)

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

    def make_field_definition(self, value, members):
        """One Field descriptor. It names its API type descriptor and its shape, and restates no type fact."""
        shape = self.get_field_shape(value)

        parts = [
            'using api_type = {};'.format(
                self.get_descriptor_path(value.base_type)
            ),
            'using shape = field_shape::{};'.format(shape),
        ]

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
        """Every command has one Return Field, including a NoValue Return Field for a void command."""
        is_void = self.clean_return_type(return_type) == 'void'

        parts = [
            'using api_type = {};'.format(
                self.get_descriptor_path(self.clean_return_type(return_type))
            ),
            'using shape = field_shape::{};'.format(
                'NoValue' if is_void else 'Value'
            ),
            'static constexpr bool is_return = true;',
            'static constexpr std::string_view field_name = "{}";'.format(
                self.RETURN_FIELD_NAME
            ),
        ]

        return 'struct {} {{ {} }};'.format(
            self.RETURN_FIELD_NAME, ' '.join(parts)
        )

    def write_field_namespace(self, element, members, return_type=None):
        """One namespace of Field descriptors for one API element."""
        write(
            'GFXRECON_BEGIN_NAMESPACE({})'.format(element), file=self.outFile
        )

        # A count_field can name a sibling that the registry declares later, so forward declare every Field that a
        # sibling names.
        referenced = [
            count for count in (
                self.get_count_field(value, members) for value in members
            ) if count
        ]

        for member in members:
            if member.name in referenced:
                write('struct {};'.format(member.name), file=self.outFile)

        for value in members:
            write(
                self.make_field_definition(value, members),
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

        lines = ['template <> struct Schema<{}>'.format(key), '{']
        line = '    using Fields = util::TypeList<'
        indent = ' ' * len(line)

        for index, entry in enumerate(entries):
            separator = ',' if index + 1 < len(entries) else '>;'
            if len(line) + len(entry) + len(separator) > 120 and line.strip(
            ) != 'using Fields = util::TypeList<':
                lines.append(line)
                line = indent
            line += entry + separator
            if separator == ',':
                line += ' '

        lines.append(line)
        lines.append('};')

        return '\n'.join(lines)

    #
    # Output
    #

    def endFile(self):
        """Method override."""
        self.build_model()

        part = self.genOpts.schema_part

        if part == SCHEMA_PART_IDENTITY:
            self.write_identity()
        elif part == SCHEMA_PART_DECODED_TRAITS:
            self.write_decoded_traits()
        elif part == SCHEMA_PART_NATIVE_STRUCT_TRAITS:
            self.write_native_struct_traits()
        elif part == SCHEMA_PART_DECODED_STRUCT_TRAITS:
            self.write_decoded_struct_traits()
        elif part == SCHEMA_PART_DECODED_COMMAND_TRAITS:
            self.write_decoded_command_traits()
        else:
            raise RuntimeError('Unknown schema part: ' + str(part))

        VulkanBaseGenerator.endFile(self)

    def write_identity(self):
        write('GFXRECON_BEGIN_NAMESPACE(schema)', file=self.outFile)
        self.newline()

        self.write_scalar_kinds()
        self.write_api_type_descriptors()
        self.write_command_tags()
        self.write_field_descriptors()
        self.write_schemas()

        write('GFXRECON_END_NAMESPACE(schema)', file=self.outFile)

    def write_scalar_kinds(self):
        write(
            '// Logical scalar kinds used by this API. A scalar kind derives from field_kind::Scalar, so one concept',
            file=self.outFile
        )
        write(
            '// selects the shared scalar access pattern while the exact kind still selects the named operation.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(field_kind)', file=self.outFile)

        for kind in sorted(self.scalar_kinds):
            write('struct {} : Scalar {{}};'.format(kind), file=self.outFile)

        write('GFXRECON_END_NAMESPACE(field_kind)', file=self.outFile)
        self.newline()

    def write_api_type_descriptors(self):
        write(
            '// API type descriptors. A descriptor carries the native type and the logical kind. It never carries a',
            file=self.outFile
        )
        write(
            '// wire type, and it never carries decoded representation.',
            file=self.outFile
        )
        write('GFXRECON_BEGIN_NAMESPACE(api_type)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(vulkan)', file=self.outFile)

        for name in sorted(self.api_type_kinds):
            write(
                'struct {} {{ using native_type = {}; using kind = field_kind::{}; }};'.format(
                    name, self.api_type_natives[name], self.api_type_kinds[name]
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
            self.write_field_namespace(struct, self.all_struct_members[struct])

        for command in self.schema_commands:
            return_type, _, params = self.all_cmd_params[command]
            self.write_field_namespace(
                self.get_command_tag(command), params, return_type=return_type
            )

        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(field)', file=self.outFile)
        self.newline()

    def write_schemas(self):
        write(
            '// Schemas. A structure keys on its native type, and a command keys on its command tag.',
            file=self.outFile
        )
        self.newline()

        for struct in self.schema_structs:
            names = [value.name for value in self.all_struct_members[struct]]
            write(
                self.make_schema_specialization(
                    '::{}'.format(struct), struct, names
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

    def write_decoded_traits(self):
        """Decoded representation traits. The key is the API type descriptor or the command tag."""
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()

        for struct in self.schema_structs:
            write(
                'template <> struct TraitsFor<schema::api_type::vulkan::{name}> '
                '{{ using decoded_type = Decoded_{name}; using decoded_value_type = ::{name}; }};'.format(
                    name=struct
                ),
                file=self.outFile
            )

        self.newline()

        # The decoded command wrapper is today's generated args structure. The formal API-signature storage that the
        # design also names does not exist yet, so no decoded_value_type is emitted for a command.
        for command in self.schema_commands:
            if not self.has_decoded_command_storage(command):
                continue

            tag = self.get_command_tag(command)
            write(
                'template <> struct TraitsFor<schema::command::vulkan::{tag}> '
                '{{ using decoded_type = args::{tag}; '
                'static constexpr format::ApiCallId call_id = format::ApiCallId::ApiCall_{command}; }};'.format(
                    tag=tag, command=command
                ),
                file=self.outFile
            )

        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)

    def write_trait_partition_prologue(self, description):
        write('// {}'.format(description), file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(schema)', file=self.outFile)
        self.newline()

    def write_trait_partition_epilogue(self):
        self.newline()
        write('GFXRECON_END_NAMESPACE(schema)', file=self.outFile)

    def make_member_trait(self, storage, field, member_expression):
        return (
            'template <> struct MemberPointer<{storage}, {field}> '
            '{{ static constexpr auto value = &{member}; }};'.format(
                storage=storage, field=field, member=member_expression
            )
        )

    def make_bitfield_member_trait(self, storage, field, member_name, value_type):
        """A bitfield has no pointer to member, so the mapping supplies accessors and a sentinel value."""
        return (
            'template <> struct MemberPointer<{storage}, {field}> : NonAddressableMember '
            '{{ static {type} Get(const {storage}& storage) {{ return storage.{member}; }} '
            'static void Set({storage}& storage, {type} value) {{ storage.{member} = value; }} }};'.format(
                storage=storage, field=field, member=member_name, type=value_type
            )
        )

    def write_native_struct_traits(self):
        self.write_trait_partition_prologue(
            'Member traits for native structure storage.'
        )

        for struct in self.schema_structs:
            storage = '::{}'.format(struct)

            for value in self.all_struct_members[struct]:
                field = self.get_field_path(struct, value.name)

                if value.bitfield_width:
                    write(
                        self.make_bitfield_member_trait(
                            storage, field, value.name, value.base_type
                        ),
                        file=self.outFile
                    )
                else:
                    write(
                        self.make_member_trait(
                            storage, field,
                            '{}::{}'.format(storage, value.name)
                        ),
                        file=self.outFile
                    )

        self.write_trait_partition_epilogue()

    def write_decoded_struct_traits(self):
        self.write_trait_partition_prologue(
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
                    self.make_member_trait(
                        storage, self.get_field_path(struct, value.name),
                        '{}::{}'.format(storage, value.name)
                    ),
                    file=self.outFile
                )

        self.write_trait_partition_epilogue()

    def write_decoded_command_traits(self):
        self.write_trait_partition_prologue(
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
                    self.make_member_trait(
                        storage, self.get_field_path(tag, value.name),
                        '{}::{}'.format(storage, value.name)
                    ),
                    file=self.outFile
                )

            # A void Return Field has no storage member, so it has no mapping.
            if self.clean_return_type(return_type) != 'void':
                write(
                    self.make_member_trait(
                        storage,
                        self.get_field_path(tag, self.RETURN_FIELD_NAME),
                        '{}::{}'.format(storage, self.RETURN_FIELD_NAME)
                    ),
                    file=self.outFile
                )

        self.write_trait_partition_epilogue()
