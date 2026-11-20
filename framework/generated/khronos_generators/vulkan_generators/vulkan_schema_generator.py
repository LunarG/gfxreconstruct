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
    the LIST_FILES files: one line per API element, each file described by its LIST_FILES entry
    generated_vulkan_wire_types.h: the WireTypeOf specializations
    generated_vulkan_schema_checks.cpp: the static checks

Separate files, not one: each includer compiles only the part it needs. The schema proper is three files, each
including the one before: generated_vulkan_schema_types.h is what code that refers to an API element includes;
generated_vulkan_schema_fields.h holds the Fields, each with its own accessor, and includes no storage type's header;
generated_vulkan_schema.h is what the field walk includes.

A platform typedef has no definition in vk.xml; platform_types.json supplies its C definition. The schema does not let
an element hide a pointer: every pointer is declared on the Field, so that a Field's shape is read from its
declaration alone. So a typedef whose definition is a pointer, HWND, LPCWSTR, becomes the element deref_<typedef>,
standing for the type pointed at, with the pointer on the Field and the typedef kept as source_type for the checks
that compare the element to the header. A typedef whose definition is not a pointer, DWORD, ANativeWindow, is an
element under its own name, categorized by its definition. See add_platform_api_type.

A Field's declaration is its API element, or Const, Pointer, Array or FixedArray over a declaration, nested as the C
declarator nests. It is read from the registry's full type, so each level's const lands where the header wrote it.
"""

import sys
from collections import namedtuple
from generator import noneStr
from khronos_base_generator import write
from vulkan_base_generator import VulkanBaseGenerator, VulkanBaseGeneratorOptions

class VulkanSchemaBaseGeneratorOptions(VulkanBaseGeneratorOptions):
    """Holds the options shared by every generated schema file. Each subclass lists its file's headers in
    add_part_headers.
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
        begin_end.system_headers.extend(('string_view', 'type_traits'))


class VulkanSchemaFieldsGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options for generated_vulkan_schema_fields.h: the Fields. generated_vulkan_schema.h includes it."""

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'generated/generated_vulkan_schema_types.h',
            'schema/field.h',
            'util/defines.h',
            'util/type_list.h',
        ))
        begin_end.system_headers.extend(('array', 'cstddef', 'string_view', 'type_traits'))


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


# ListFile describes one generated file that holds one line per API element:
#   headers, system_headers  The files it includes.
#   namespace                The namespace it opens inside gfxrecon.
#   preamble                 Fixed lines written before the lists.
#   lists                    (comment, selection, line) per list. selection is the VulkanSchemaBaseGenerator method
#                            that returns the API element names. line is written once per name: {name} is the API
#                            element name and {stem} is the name without its two-letter API prefix.
ListFile = namedtuple('ListFile', ('headers', 'system_headers', 'namespace', 'preamble', 'lists'))

API_ELEMENT_OF_LINE = 'template <> struct ApiElementOf<::{name}> {{ using type = schema::vulkan::api_elements::{name}; }};'

# LIST_FILES maps each such file to its description. VulkanListFileGenerator writes every one of them, and gencode.py
# registers it once per file, so each file is its own target. To add a file, add an entry here and list the file in
# generate_vulkan.py.
LIST_FILES = {
    'generated_vulkan_api_element_of.h': ListFile(
        headers=('binding/api_element_of.h', 'generated/generated_vulkan_schema_types.h', 'util/defines.h'),
        system_headers=(),
        namespace='binding',
        preamble=(),
        lists=(
            ('// binding::ApiElementOf for every structure, union and C enum: the API element of the C type. A 64-bit\n'
             '// flag-bits type is a VkFlags64 typedef, so it has no specialization: one would key on uint64_t.',
             'get_structure_api_elements', API_ELEMENT_OF_LINE),
            ('', 'get_union_api_elements', API_ELEMENT_OF_LINE),
            ('', 'get_native_enumerated_types', API_ELEMENT_OF_LINE),
        )
    ),
    'generated_vulkan_call_id.h': ListFile(
        headers=(
            'binding/call_id_of.h', 'format/api_call_id.h', 'generated/generated_vulkan_schema_types.h',
            'util/defines.h'
        ),
        system_headers=(),
        namespace='binding',
        preamble=(),
        lists=(
            ('// binding::CallId for every command: its format::ApiCallId enumerator.',
             'get_command_api_elements',
             'template <> struct CallId<schema::vulkan::api_elements::{name}> {{ static constexpr format::ApiCallId value = format::ApiCallId::ApiCall_vk{name}; }};'),
        )
    ),
}


class VulkanListFileGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options for one LIST_FILES file, selected by filename."""

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
        self.list_file = LIST_FILES[filename]
        VulkanSchemaBaseGeneratorOptions.__init__(
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

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend(self.list_file.headers)
        begin_end.system_headers.extend(self.list_file.system_headers)


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


class VulkanSchemaChecksGeneratorOptions(VulkanSchemaBaseGeneratorOptions):
    """Holds the options for generated_vulkan_schema_checks.cpp. Compiling it is the test: it holds static_asserts
    and the constexpr counts they compare, and only gfxrecon_framework_test compiles it (framework/CMakeLists.txt), so
    it costs a product build nothing and may include any header it checks.
    """

    def add_part_headers(self, begin_end):
        begin_end.specific_headers.extend((
            'binding/vulkan_wire_type.h',
            'decode/vulkan_decoder_args.h',
            'generated/generated_vulkan_api_element_of.h',
            'generated/generated_vulkan_call_id.h',
            'generated/generated_vulkan_decoder_args.h',
            'generated/generated_vulkan_schema.h',
            'generated/generated_vulkan_struct_decoders.h',
            'schema/schema.h',
            'util/defines.h',
        ))
        begin_end.system_headers.append('type_traits')


class VulkanSchemaBaseGenerator(VulkanBaseGenerator):
    """Builds the model every generated schema file is written from. build_model builds the model, and a subclass's
    write_part writes its part of it: one generated file per subclass, except VulkanListFileGenerator, which writes
    every LIST_FILES file.
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
    # own, so their element_type is written unqualified and their API element name comes from API_ELEMENT_NAME_FOR_TYPE.
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
    API_ELEMENT_NAME_FOR_TYPE = {
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
        self.api_type_categories = dict()  # API element name to its schema::category word.
        self.api_type_wire_kinds = dict()  # API element name to the wire kind that selects its WireTypeOf.
        self.platform_api_types = set()  # Platform typedefs with an API element of their own, for the types header.
        self.api_type_elements = dict()  # API element name to its element_type expression.
        self.api_type_sources = dict()  # deref_ API element name to the platform typedef it points through: source_type.
        self.defaulted_types = set()  # Registry types that reached the Scalar fallback without being classified.
        self.bitmask_types = set()  # Enum groups vk.xml declares type="bitmask".

    def genStruct(self, typeinfo, typename, alias, protect=None):
        """Method override: also records the registry's selector attributes."""
        VulkanBaseGenerator.genStruct(self, typeinfo, typename, alias, protect)
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

    def genGroup(self, groupinfo, group_name, alias, protect=None):
        """Method override: also records each group vk.xml declares type="bitmask" in bitmask_types."""
        VulkanBaseGenerator.genGroup(self, groupinfo, group_name, alias, protect)
        if groupinfo.elem.get('type') == 'bitmask':
            self.bitmask_types.add(group_name)

    def make_value_info(self, params):
        """Method override: keeps two registry attributes the base generator drops. registry_len is the len text as
        written, with its null-terminated term; objecttype is the sibling that holds a handle member's object type."""
        params = list(params)
        values = VulkanBaseGenerator.make_value_info(self, params)
        for value, param in zip(values, params):
            value.registry_len = param.attrib.get('len')
            value.objecttype = param.attrib.get('objecttype')
        return values

    #
    # Utilities for the model
    #
    def get_base_structs(self):
        api_data = self.get_api_data()
        if (api_data) :
            return (api_data.base_in_struct, api_data.base_out_struct)
        return ()

    #
    # Model
    #

    def build_model(self):
        """Selects the structures, unions and commands that get a Schema, and registers an API element for every type
        a generated file refers to."""
        # Every structure vk.xml gives members gets a Schema, and every union a Schema of Alternatives. A hand-written
        # encoder or decoder is a binding fact, read below, never the absence of a Schema. Platform
        # structures (platform_types.json structs) have no members and no Schema.
        self.schema_structs = list(self.all_struct_members)
        self.schema_unions = list(self.all_union_members)

        # The structures with a generated Decoded_ wrapper: all but blacklists.json structures and platform structures.
        # Only a generated wrapper is relied on to hold its API element and to declare each member under its Field's
        # name; a hand-written one is not.
        self.wrapper_structs = list(self.get_all_filtered_struct_names())

        self.schema_commands = list(self.get_all_filtered_cmd_names())

        self.external_structs = set(self.PLATFORM_STRUCTS)

                # 'void' always has an API element, because a void command still has one Return Field.
        self.add_api_type('void')

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
        return self.API_ELEMENT_NAME_FOR_TYPE.get(resolved, resolved)

    def get_api_element_path(self, base_type):
        """Returns the API element's path from the schema namespace, for a line emitted at schema scope."""
        return 'vulkan::api_elements::{}'.format(self.get_api_element_name(base_type))

    def get_api_element_reference(self, name):
        """Returns the API element's spelling from inside schema::vulkan::fields::<owner>, where a Field is emitted.
        Lookup reaches schema::vulkan from there, so the vulkan component is not written."""
        return 'api_elements::{}'.format(name)

    def get_generic_handles(self, members):
        """Maps member name to object type member name for the integer members vk.xml marks objecttype: the attribute
        holds the sibling whose value gives the handle's type. The registry states it for every such member, so no
        table is read."""
        generic = dict()

        for value in members:
            objecttype = getattr(value, 'objecttype', None)

            if objecttype and any(member.name == objecttype for member in members):
                generic[value.name] = objecttype

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
        Enum (a 64-bit bits enum) and Scalar (VkFlags, VkFlags64). Callback becomes Funcpointer; Char and WChar are
        Scalar."""
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
        if wire_kind in ('Handle', 'Enum', 'Void'):
            return wire_kind
        return 'Scalar'

    def get_field_element_name(self, value):
        """Returns the name of a field's API element: the platform typedef's own when the header spells one that
        PLATFORM_TYPES substitutes, deref_<typedef> when its replaceWith adds a star, else the registry type's."""
        platform = value.platform_base_type

        if platform:
            self.add_platform_api_type(platform, value)
            return self.get_platform_element_name(platform)

        return self.get_api_element_name(value.base_type)

    def get_platform_element_name(self, platform_type):
        """Returns deref_<typedef> for a platform typedef whose replaceWith adds a star, else the typedef's name."""
        if '*' in self.PLATFORM_TYPES[platform_type]['replaceWith']:
            return 'deref_' + platform_type
        return platform_type

    def is_null_terminated(self, value):
        """Returns True for a string: a char or wchar_t member or parameter whose registry len carries the
        null-terminated term, or a platform text typedef (LPCWSTR)."""
        if value.base_type not in ('char', 'wchar_t'):
            return False
        if 'null-terminated' in (getattr(value, 'registry_len', None) or ''):
            return True
        return bool(value.platform_base_type)

    def add_field_api_type(self, value):
        """Registers a member's or parameter's API element, the platform typedef's own where it has one."""
        if self.get_field_element_name(value) == self.get_api_element_name(value.base_type):
            self.add_api_type(value.base_type)

    def add_platform_api_type(self, platform_type, value):
        """Registers the API element of a platform typedef (platform_types.json, REPLACE_TYPE). A typedef whose
        replaceWith adds a star, HWND for void*, LPCWSTR for const wchar_t*, is a deref_ element for the type it points
        at, with the star on the Field and the typedef kept as source_type. Any other keeps the header's name. The
        category is Void when baseType is void (ANativeWindow, deref_HWND), else the substituted type's: Scalar for
        DWORD and deref_LPCWSTR."""
        name = self.get_platform_element_name(platform_type)

        if name in self.api_type_categories:
            return

        if self.PLATFORM_TYPES[platform_type]['baseType'] == 'void':
            wire_kind = 'Void'
        else:
            wire_kind = self.get_logical_category(value.base_type)

        # element_type is qualified from the global namespace: inside the API element, the unqualified name is
        # the API element itself.
        self.api_type_wire_kinds[name] = wire_kind
        self.api_type_categories[name] = self.category_for(name, wire_kind)
        self.platform_api_types.add(name)

        if name != platform_type:
            self.api_type_elements[name] = 'std::remove_cv_t<std::remove_pointer_t<::{}>>'.format(platform_type)
            self.api_type_sources[name] = '::' + platform_type
        else:
            self.api_type_elements[name] = '::' + platform_type

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
        else; a length outside it stays as source_length_expression text. Each node is ('number', text), ('sibling', name),
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
        """Returns the ExpressionValue type for a count expression tree.

        An enum sibling is read through AsInteger as its underlying integer, whose signedness is the compiler's
        choice for a C enum. A literal is written unsigned unless an enum sibling takes part, so that it meets an
        unsigned sibling or an unsigned API constant without a sign conversion.
        """
        siblings = self.count_expression_siblings(tree)
        enum_siblings = {
            member.name for member in members if member.name in siblings and self.is_enum(member.base_type)
        }
        suffix = '' if enum_siblings else 'u'
        operators = {'+': 'Sum', '*': 'Product', '/': 'Quotient'}

        def emit(node):
            if node[0] == 'number':
                return 'Literal<{}{}>'.format(node[1], suffix)
            if node[0] == 'sibling':
                if node[1] in enum_siblings:
                    return 'AsInteger<FieldValue<{}>>'.format(node[1])
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
            return 'StorageValue<Deref<FieldValue<{}>>, {}>'.format(*count_member)

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
        """Returns one Field definition: its name and its declaration, plus selector_field, objecttype_field,
        selections, semantics, source_length_expression and bit_width where they apply, and its accessor. It restates
        no type fact the declaration carries."""
        shape = self.get_field_shape(value)

        # selector_field is the registry's selector on a union-typed member: the sibling whose value chooses the
        # union alternative. objecttype_field is the registry's objecttype on an integer member that holds a handle:
        # the sibling that holds the handle's object type.
        selector = self.member_selectors.get((owner, value.name))
        objecttype = generic_handles.get(value.name)

        # get_field_element_name reads the platform typedef first: value.base_type holds the substituted type, e.g.
        # void for HANDLE.
        api_element = self.get_api_element_reference(self.get_field_element_name(value))

        length = self.get_field_length(value, members)
        declaration = self.make_declaration(value, api_element, shape, length, self.is_null_terminated(value))

        # Facts the declarator does not spell are members of the derived struct.
        parts = []

        if selector is not None:
            parts.append('using selector_field = {};'.format(selector))

        if objecttype is not None:
            parts.append('using objecttype_field = {};'.format(objecttype))

        # A union alternative lists the selector values that choose it, in the registry's selection order.
        selections = self.member_selections.get((owner, value.name))

        if selections:
            parts.append('static constexpr auto selections = std::array{{ {} }};'.format(', '.join(selections)))

        if shape == 'ExtensionChain':
            # ValidExtensions: vk.xml connects the owner to another structure with structextends. Another structure's
            # structextends lists the owner (VkBufferMemoryBarrier), or the owner's own lists another
            # (VkMemoryBarrier2). The source is registry.validextensionstructs, read by must_extended_struct_be_null.
            # It is the registry's fact, not the spec's: no structextends lists VkPipelineCreateInfoKHR, so it gets no
            # token, but the spec requires a structure in its pNext.
            tokens = ['semantic::ExtensionChain']
            if not self.must_extended_struct_be_null(owner):
                tokens.append('semantic::ValidExtensions')
            parts.append('using semantics = util::TypeList<{}>;'.format(', '.join(tokens)))

        # The registry's len text is kept only where the schema's length does not carry its meaning.
        if not length and value.array_length and shape == 'Array':
            parts.append(
                'static constexpr std::string_view source_length_expression = "{}";'.
                format(value.array_length)
            )

        parts.extend(self.make_field_accessor(value.name, value.bitfield_width))

        return self.make_field_struct(value.name, declaration, parts)

    def make_field_accessor(self, name, bitfield_width=None):
        """Returns the member lines that read the Field's member from any storage type that spells it by the Field's
        name: GetRef, or bit_width with Get and Set for a bitfield, whose width is the registry's `: N`. The trailing
        return type makes a storage type without the member a substitution failure, which StorageFor reads."""
        if bitfield_width:
            return [
                'using bit_width = std::integral_constant<size_t, {}>;'.format(bitfield_width.replace(':', '').strip()),
                'template <typename Storage> static auto Get(const Storage& storage) -> decltype(storage.{0}) '
                '{{ return storage.{0}; }}'.format(name),
                'template <typename Storage> static void Set(Storage& storage, decltype(storage.{0}) value) '
                '{{ storage.{0} = value; }}'.format(name),
            ]

        return [
            'template <typename Storage> static auto GetRef(Storage& storage) -> decltype((storage.{0})) '
            '{{ return (storage.{0}); }}'.format(name)
        ]

    def make_field_struct(self, name, declaration, parts):
        """Returns the Field struct, one member per line."""
        lines = ['struct {} : Field<"{}", {}>'.format(name, name, declaration), '{']
        lines.extend('    ' + part for part in parts)
        lines.append('};')
        return '\n'.join(lines)

    def make_declaration(self, value, api_element, shape, length, null_terminated):
        """Returns the declaration of one field use: the API element, or Const, Pointer, Array or FixedArray over
        it as the C declarator nests. It is read from the registry's full type, with a platform typedef replaced by
        its replaceWith, so each level's const lands where the header wrote it and a typedef's hidden star is a level.
        A string's innermost level takes the NullTerminated length."""
        if shape == 'ExtensionChain':
            # C declares the chain pointer void*, or the base structure's own type in the two base structures; the
            # schema declares Void for both, and the ExtensionChain token states what the pointer holds.
            element = self.get_api_element_reference('Void')
        else:
            element = api_element

        segments = value.full_type.split('*')
        levels = segments[1:]

        declaration = element

        if 'const' in segments[0]:
            declaration = 'Const<{}>'.format(declaration)

        for index, segment in enumerate(levels):
            if null_terminated and index == 0:
                declaration = 'Array<{}, NullTerminated>'.format(declaration)
            elif index == len(levels) - 1 and shape in ('Array', 'PointerArray'):
                declaration = 'Array<{}, {}>'.format(declaration, length if length else 'UnknownLength')
            else:
                declaration = 'Pointer<{}>'.format(declaration)

            if 'const' in segment:
                declaration = 'Const<{}>'.format(declaration)

        if shape == 'StaticArray':
            # Nests from the innermost extent outward; a bounded array's sibling length sits on the outermost level,
            # and a string's terminator on the innermost.
            extents = self.get_static_array_extents(value)

            for index, extent in enumerate(reversed(extents)):
                outermost = index == len(extents) - 1
                if null_terminated and index == 0:
                    extent_length = 'NullTerminated'
                elif outermost and length:
                    extent_length = length
                else:
                    extent_length = 'UseCapacity'
                declaration = 'FixedArray<{}, {}, {}>'.format(declaration, extent_length, extent)

        return declaration

    def make_return_field_definition(self, return_type):
        """Returns the command's Return Field definition. Every command has one; a void command's Return Field
        holds the Void API element and has no accessor, since no storage type has a member for it."""
        cleaned = self.clean_return_type(return_type)
        parts = ['static constexpr bool is_return = true;']

        if cleaned != 'void':
            parts.extend(self.make_field_accessor(self.RETURN_FIELD_NAME))

        return self.make_field_struct(
            self.RETURN_FIELD_NAME,
            self.get_api_element_reference(self.get_api_element_name(cleaned)),
            parts,
        )

    def write_field_namespace(self, element, members, owner, is_command, return_type=None):
        """Writes the namespace of Fields for one structure, union or command."""
        write(
            'GFXRECON_BEGIN_NAMESPACE({})'.format(element), file=self.outFile
        )

        generic_handles = self.get_generic_handles(members)

        # A length, selector_field or objecttype_field refers to a sibling Field, and vk.xml always declares that
        # sibling before the member that refers to it, so Fields are written in member order with no forward
        # declarations. A sibling referred to before its declaration fails to compile at that line.
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
                '// Platform typedefs (platform_types.json and REPLACE_TYPE in vulkan_base_generator.py): a typedef\n'
                '// whose replaceWith adds a star is a deref_ element for the type it points at, with the typedef as\n'
                '// source_type; any other keeps the platform header\'s name and type. The category is Void\n'
                '// when the substituted base type is void, else the substituted type\'s, e.g. Scalar for DWORD.',
                file=self.outFile
            )

        # Every API element is declared before any is defined: a bitmask refers to its flags and bits API elements in
        # its base, and the names sort in no useful order.
        for name in sorted(self.api_type_categories):
            write('struct {};'.format(name), file=self.outFile)
        self.newline()

        # Each API element derives from its category's base in schema/api_element.h, which supplies the members the
        # category carries. A registry basetype adds source_category and a deref_ element source_type, the facts the
        # schema replaced. A C type is spelled from the global namespace, ::VkFormat: inside namespace api_elements
        # the bare name is the API element.
        bitvalues = self.get_bitvalues_of_bitmasks()
        for name in sorted(self.api_type_categories):
            element = self.api_type_elements[name]
            # An API element carries the name of the type it describes; EmptyBitvalues and EmptyBitvalues64 describe none,
            # and a deref_ element describes a type with no name of its own, so each carries its own.
            spelled = name if (name in self.empty_bitvalues.values() or name in self.api_type_sources) else element.lstrip(':')
            args = '"{}", {}'.format(spelled, element)
            category = self.api_type_categories[name]
            body = self.get_source_members(name)
            if category == 'Struct':
                structure_type = self.get_structure_type(name)
                if structure_type is not None:
                    base = 'ApiElementTypedStruct<{}, {}>'.format(args, structure_type)
                else:
                    base = 'ApiElementStruct<{}>'.format(args)
            elif category == 'Enum':
                base = 'ApiElementEnum<{}, enumerants::{}>'.format(args, name)
                if name in self.bitmask_types or name in self.empty_bitvalues.values():
                    body += ' using semantics = util::TypeList<semantic::Bitvalues>; '
            elif category == 'Bitmask':
                flags = self.flags_types[name]
                bits = bitvalues.get(name, self.empty_bitvalues[flags])
                base = 'ApiElementBitmask<{}, {}, {}>'.format(args, flags, bits)
            else:
                assert category in ('Union', 'Handle', 'Funcpointer', 'Scalar', 'Void'), (name, category)
                base = 'ApiElement{}<{}>'.format(category, args)
            write('struct {} : {} {{{}}};'.format(name, base, body), file=self.outFile)

        write('GFXRECON_END_NAMESPACE(api_elements)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(vulkan)', file=self.outFile)
        self.newline()

    def get_source_members(self, name):
        """Returns the body members that keep what the schema replaced: source_category, "basetype", for an API
        element whose registry declaration is category basetype, and source_type for a deref_ element. Empty
        otherwise; EmptyBitvalues and EmptyBitvalues64 describe no registry type."""
        if name in self.empty_bitvalues.values():
            return ''
        source = self.api_type_sources.get(name)
        registry_name = (source or self.api_type_elements[name]).lstrip(':')
        parts = []
        if self.get_registry_category(registry_name) == 'basetype':
            parts.append('static constexpr std::string_view source_category = "basetype";')
        if source:
            parts.append('using source_type = {};'.format(source))
        return ' ' + ' '.join(parts) + ' ' if parts else ''

    def get_registry_category(self, name):
        """Returns the registry's category attribute of a type, or None for a type vk.xml does not declare or marks
        with none."""
        info = self.registry.typedict.get(name)
        if info is None:
            return None
        return info.elem.get('category')

    def get_enumerated_types(self):
        """Returns every enumerated type, by name. Its API element and its table have the same name."""
        return sorted(enum for enum in self.enum_names if self.is_enumerated(enum))

    def get_native_enumerated_types(self):
        """Returns the enumerated types that are C enums, by name: every enumerated type but the 64-bit flag-bits
        types, which C declares as typedefs of VkFlags64."""
        return [enum for enum in self.get_enumerated_types() if self.api_type_wire_kinds[self.get_api_element_name(enum)] == 'Enum']

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
            '// declarators over it, and the accessor that reads its member from a storage type.',
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

    def get_command_api_elements(self):
        """Returns every command API element, in command order: the command name without its vk prefix."""
        return [self.get_command_api_element_name(command) for command in self.schema_commands]

    def get_external_structure_api_elements(self):
        """Returns the structure API elements a platform header defines, by name."""
        return [name for name in self.get_structure_api_elements() if name in self.external_structs]

    def write_list_file(self):
        """Writes one LIST_FILES file: its preamble, then one line per selected API element for each of its lists."""
        list_file = self.genOpts.list_file
        body = ['GFXRECON_BEGIN_NAMESPACE({})'.format(list_file.namespace), '']
        body.extend(list_file.preamble)

        for comment, selection, line in list_file.lists:
            if comment:
                body.append(comment)
            body.extend(line.format(name=name, stem=name[2:]) for name in getattr(self, selection)())
            body.append('')

        body.append('GFXRECON_END_NAMESPACE({})'.format(list_file.namespace))
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
        write(
            '// Each structure and union C type against the element_type of its binding::ApiElementOf, which\n'
            '// generated/generated_vulkan_api_element_of.h specializes.',
            file=self.outFile
        )

        for name in self.get_structure_api_elements() + self.get_union_api_elements():
            write(
                'static_assert(std::is_same_v<schema::ApiTypeOf_t<binding::ApiElementOf<::{name}>::type>, '
                '::{name}>);'.format(name=name),
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
        write('// ValueDecoder converts), text, and the kinds with no generated WireTypeOf (handle and funcpointer are', file=self.outFile)
        write('// recorded as 64-bit identifiers or addresses; struct and void have no width).', file=self.outFile)

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
        write('// No API element hides a pointer: a platform typedef over a pointer is a deref_ element for the type pointed', file=self.outFile)
        write('// at, with the star on the Field. Handles and function pointers are the pointer types the API declares.', file=self.outFile)

        for name in sorted(self.api_type_categories):
            if self.api_type_categories[name] in ('Handle', 'Funcpointer'):
                continue
            write(
                'static_assert(!std::is_pointer_v<schema::ApiTypeOf_t<schema::vulkan::api_elements::{}>>);'.format(name),
                file=self.outFile
            )

        self.newline()
        write('// A deref_ element is the type its source typedef points at, and a registry basetype is a scalar or void.', file=self.outFile)

        for name in sorted(self.api_type_sources):
            write(
                'static_assert(std::is_same_v<std::remove_cv_t<std::remove_pointer_t<'
                'schema::vulkan::api_elements::{0}::source_type>>, '
                'schema::ApiTypeOf_t<schema::vulkan::api_elements::{0}>>);'.format(name),
                file=self.outFile
            )

        for name in sorted(self.api_type_categories):
            if 'source_category' in self.get_source_members(name):
                write(
                    'static_assert(schema::SimpleApiElement<schema::vulkan::api_elements::{0}> || '
                    'schema::VoidApiElement<schema::vulkan::api_elements::{0}>);'.format(name),
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
        write('// A structure a platform header defines (platform_types.json "structs") has no Schema, and every other', file=self.outFile)
        write('// structure has one.', file=self.outFile)
        external = self.get_external_structure_api_elements()
        for name in external:
            write(
                'static_assert(!schema::HasSchemaFields<schema::vulkan::api_elements::{}>);'.format(name),
                file=self.outFile
            )

        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)


class VulkanSchemaTypesGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema_types.h: the API elements and command API elements."""

    def write_part(self):
        self.write_schema_part(self.write_api_elements, self.write_command_api_elements)


class VulkanWireTypesGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_wire_types.h: the WireTypeOf specializations
    of the scalar and enum API elements."""

    def write_part(self):
        write('// WireTypeOf for the scalar and enum API elements: the format typedef each is recorded as. Bitmask,', file=self.outFile)
        write('// handle and funcpointer are partial specializations in binding/wire_type_of.h; struct and void have no', file=self.outFile)
        write('// width of their own.', file=self.outFile)
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


class VulkanSchemaFieldsGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema_fields.h: the Fields."""

    def write_part(self):
        self.write_schema_part(self.write_fields)


class VulkanSchemaGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema.h: the Schema specializations that order the Fields."""

    def write_part(self):
        self.write_schema_part(self.write_schemas)


class VulkanListFileGenerator(VulkanSchemaBaseGenerator):
    """Generates one LIST_FILES file, the one its options select."""

    def write_part(self):
        self.write_list_file()


class VulkanSchemaChecksGenerator(VulkanSchemaBaseGenerator):
    """Generates generated_vulkan_schema_checks.cpp, the cross-generator agreement checks. Compiling the
    result is the test."""

    def write_part(self):
        self.write_checks()


