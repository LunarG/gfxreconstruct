#!/usr/bin/env python3
#
# Copyright (c) 2013-2024 The Khronos Group Inc.
# Copyright (c) 2021-2024 LunarG, Inc.
# Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

import json,os,re,shutil,sys,tempfile

from collections import OrderedDict

try:
    from pathlib import Path
except ImportError:
    # For limited python 2 compat as used by some Vulkan consumers
    from pathlib2 import Path  # type: ignore

def write(*args, **kwargs):
    file = kwargs.pop('file', sys.stdout)
    end = kwargs.pop('end', '\n')
    file.write(' '.join(str(arg) for arg in args))
    file.write(end)

def make_re_string(list, default=None):
    """Turn a list of strings into a regexp string matching exactly those strings.
    Pulled from Khronos genvk.py
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

def noneStr(s):
    """Return string argument, or "" if argument is None.

    Used in converting etree Elements into text.
    s - string to convert"""
    if s:
        return s
    return ""


def enquote(s):
    """Return string argument with surrounding quotes,
    for serialization into Python code."""
    if s:
        if isinstance(s, str):
            return f"'{s}'"
        else:
            return s
    return None


class MissingGeneratorOptionsError(RuntimeError):
    """Error raised when a Generator tries to do something that requires GeneratorOptions but it is None."""

    def __init__(self, msg=None):
        full_msg = 'Missing generator options object self.genOpts'
        if msg:
            full_msg += f": {msg}"
        super().__init__(full_msg)


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

        sizeof_key = 'sizeof'
        if (self.array_length != None) and isinstance(self.array_length, str) and (sizeof_key in self.array_length) and ('(' not in self.array_length):
            sizeof_index = self.array_length.find(sizeof_key)
            sizeof_len = len(sizeof_key)
            self.array_length = self.array_length[:sizeof_index + sizeof_len] + '(' +  self.array_length[sizeof_index + sizeof_len + 1:] + ')'

class Dx12GeneratorOptions():
    """Options for generating C++ function declarations for Dx12 API.

    Adds options used by FrameworkGenerator objects during C++ language
    code generation.

    Additional members
      blacklists - Path to JSON file listing apicalls and structs to ignore.
      platform_types - Path to JSON file listing platform (WIN32, X11, etc.)
        specific types that are defined outside of the Vulkan header.

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
        blacklists=None,
        platform_types=None,
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True
    ):
        self.blacklists = blacklists
        self.platform_types = platform_types
        self.filename = filename
        self.directory = directory
        self.prefix_text = prefix_text
        self.protect_file = protect_file
        self.protect_feature = protect_feature
        self.apicall = ''
        self.apientry = ''
        self.apientryp = ''
        self.indent_func_proto = ''
        self.align_func_param = 48
        self.code_generator = True
        self.apiname = 'Dx12',
        self.conventions = None
        self.genpath = None
        self.profile = None,
        self.versions = None,
        self.emitversions = None,
        self.default_extensions = None,
        self.add_extensions = None,
        self.remove_extensions = None,
        self.emit_extensions = None


class Dx12BaseGenerator():

    NO_STRUCT_BREAKDOWN = [
        'LARGE_INTEGER',
        'D3D12_AUTO_BREADCRUMB_NODE',
        'D3D12_AUTO_BREADCRUMB_NODE1',
        'D3D12_DRED_ALLOCATION_NODE',
        'D3D12_DRED_ALLOCATION_NODE1',
    ]

    ARRAY_SIZE_LIST = [
        ['D3D12_AUTO_BREADCRUMB_NODE', 'pCommandHistory', 'BreadcrumbCount'],
        ['D3D12_AUTO_BREADCRUMB_NODE1', 'pCommandHistory', 'BreadcrumbCount'],
        [
            'D3D12_AUTO_BREADCRUMB_NODE1', 'pBreadcrumbContexts',
            'BreadcrumbContextsCount'
        ],
        [
            'D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES', 'pTypes',
            'Count'
        ],
        [
            'ID3D12GraphicsCommandList_OMSetRenderTargets',
            'pRenderTargetDescriptors',
            '(NumRenderTargetDescriptors ? (RTsSingleHandleToDescriptorRange ? 1 : NumRenderTargetDescriptors) : 0)'
        ]
    ]

    RETURN_ARRAY_SIZE_LIST = [
        [
            'ID3D12StateObjectProperties_GetShaderIdentifier',
            'D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES'
        ]
    ]

    NOT_ARRAY_DICT = {'D3D12_MESSAGE': ['pDescription']}

    # convert base type into the encode function name
    CONVERT_FUNCTION_LIST = [
        [['BYTE', 'byte', 'UINT8', 'unsigned char'], 'UInt8'],
        [['INT8'], 'Int8'],
        [['UINT16', 'unsigned short'], 'UInt16'],
        [['SHORT'], 'Int16'],
        [
            [
                'unsigned long', 'ULONG', 'DWORD', 'UINT', 'UINT32',
                'unsigned int', 'DXGI_USAGE'
            ], 'UInt32'
        ],
        [['HRESULT', 'LONG', 'BOOL', 'INT', 'int'], 'Int32'],
        [['UINT64', 'D3D12_GPU_VIRTUAL_ADDRESS'], 'UInt64'],
        [['LONG_PTR', 'SIZE_T'], 'SizeT'],
        [['FLOAT', 'float'], 'Float'],
        [['void'], 'Void'],
        [['char'], 'String'],
        [['wchar_t'], 'WString'],
        [['PFN_DESTRUCTION_CALLBACK'], 'Function'],
        [['D3D12MessageFunc'], 'Function'],
    ]

    BIT_FIELD_LIST = [
        ['D3D12_RAYTRACING_INSTANCE_DESC', 'InstanceID', ':24'],
        ['D3D12_RAYTRACING_INSTANCE_DESC', 'InstanceMask', ':8'],
        [
            'D3D12_RAYTRACING_INSTANCE_DESC',
            'InstanceContributionToHitGroupIndex', ':24'
        ],
        ['D3D12_RAYTRACING_INSTANCE_DESC', 'Flags', ':8'],
    ]

    # Dictionary for structs with members that contain objects that must be
    # unwrapped or mapped on replay, for cases such as
    # D3D12_PIPELINE_STATE_STREAM_DESC that contain an array of bytes with
    # embedded objects.
    CUSTOM_STRUCT_HANDLE_MAP = {
        'D3D12_PIPELINE_STATE_STREAM_DESC': ['pPipelineStateSubobjectStream'],
        'D3D12_STATE_SUBOBJECT': ['pDesc']
    }

    # Some functions annotate COM pointer parameters that have a void**
    # with the '_Out_' token instead of '_COM_Outptr_'.  This table
    # contains the COM pointer parameters that are not annotated as
    # COM pointers.
    COM_POINTER_PARAMS = {
        'D3D12CreateRootSignatureDeserializer':
        ['ppRootSignatureDeserializer'],
        'D3D12CreateVersionedRootSignatureDeserializer':
        ['ppRootSignatureDeserializer']
    }

    # Those classes inherit from IUnknow
    NOT_FAMILY_CLASSES = [
        'ID3D12Debug1', 'ID3D12Debug2', 'ID3D12DebugDevice1',
        'ID3D12DebugCommandList1'
    ]

    # ID3D23CommandList is top parent class for all ID3D12GraphicsCommandList[n]
    FAMILY_CLASSES_EXECPTION = {
        'ID3D12GraphicsCommandList':
        'ID3D12CommandList'
    }

    ADD_RV_ANNOTATION_METHODS = [
        'GetGPUVirtualAddress',
        'GetGPUDescriptorHandleForHeapStart',
        'GetShaderIdentifier',
    ]

    REMOVE_RV_ANNOTATION_TYPES = {
        'D3D12_GPU_VIRTUAL_ADDRESS':'',
        'D3D12_GPU_DESCRIPTOR_HANDLE':'',
        'D3D12_INDEX_BUFFER_VIEW':'',
        'D3D12_VERTEX_BUFFER_VIEW':'',
        'D3D12_STREAM_OUTPUT_BUFFER_VIEW':'',
        'D3D12_CONSTANT_BUFFER_VIEW_DESC':'',
        'D3D12_SHADER_RESOURCE_VIEW_DESC':'',
        'D3D12_WRITEBUFFERIMMEDIATE_PARAMETER':'',
        'D3D12_DISPATCH_RAYS_DESC':'',
        'D3D12_RAYTRACING_GEOMETRY_DESC':'',
        'D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC':'D3D12_RAYTRACING_GEOMETRY_DESC[]',
        'D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS':'D3D12_RAYTRACING_GEOMETRY_DESC[]',
        'D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC':'',
    }

    def __init__(
        self,
        source_dict,
        dx12_prefix_strings,
        err_file=sys.stderr,
        warn_file=sys.stderr,
        diag_file=sys.stdout
    ):
        self.outFile = None
        self.errFile = err_file
        self.warnFile = warn_file
        self.diagFile = diag_file
        # Internal state
        self.featureName = None
        """The current feature name being generated."""

        self.genOpts = None
        """The GeneratorOptions subclass instance."""

        self.registry = None
        """The specification registry object."""

        self.featureDictionary = {}
        """The dictionary of dictionaries of API features."""

        # Used for extension enum value generation
        self.extBase = 1000000000
        self.extBlockSize = 1000
        self.madeDirs = {}

        # API dictionary, which may be loaded by the beginFile method of
        # derived generators.
        self.apidict = None

        self.source_dict = source_dict
        self.dx12_prefix_strings = dx12_prefix_strings
        self.feature_method_params = dict()
        self.check_blacklist = False

        self.structs_with_map_data = dict()

        self.MAP_STRUCT_TYPE = {
            'D3D12_GPU_DESCRIPTOR_HANDLE': [
                'MapGpuDescriptorHandle', 'MapGpuDescriptorHandles',
                'descriptor_map'
            ],
            'D3D12_GPU_VIRTUAL_ADDRESS':
            ['MapGpuVirtualAddress', 'MapGpuVirtualAddresses', 'gpu_va_map']
        }
        self.dx12_return_value = None
        self.dx12_return_decode_type = None

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

        # Platform specific basic types that have been defined extarnally to the Vulkan header.
        self.PLATFORM_TYPES = {}

        # Platform specific structure types that have been defined extarnally to the Vulkan header.
        self.PLATFORM_STRUCTS = []

        self.GENERIC_HANDLE_APICALLS = {}

        self.GENERIC_HANDLE_STRUCTS = {}

        # These types represent pointers to non-Vulkan or non-Dx12 objects that were written as 64-bit address IDs.
        self.EXTERNAL_OBJECT_TYPES = ['void', 'Void']

        self.MAP_STRUCT_TYPE = {
            'D3D12_GPU_DESCRIPTOR_HANDLE': [
                'MapGpuDescriptorHandle', 'MapGpuDescriptorHandles',
                'descriptor_map'
            ],
            'D3D12_GPU_VIRTUAL_ADDRESS':
            ['MapGpuVirtualAddress', 'MapGpuVirtualAddresses', 'gpu_va_map']
        }

        # Default C++ code indentation size.
        self.INDENT_SIZE = 4

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

            for type in platform_types:
                self.PLATFORM_TYPES[type] = platform_types[type]

            platform_structs = platform['structs']
            if platform_structs:
                self.PLATFORM_STRUCTS += platform_structs

    def beginFile(self, gen_opts):

        self.genOpts = gen_opts
        if self.genOpts is None:
            raise MissingGeneratorOptionsError()
        self.file_suffix = ''

        # Try to import the API dictionary, apimap.py, if it exists. Nothing
        # in apimap.py cannot be extracted directly from the XML, and in the
        # future we should do that.
        if self.genOpts.genpath is not None:
            try:
                sys.path.insert(0, self.genOpts.genpath)
                import apimap
                self.apidict = apimap
            except ImportError:
                self.apidict = None

        # Open a temporary file for accumulating output.
        if self.genOpts.filename is not None:
            self.outFile = tempfile.NamedTemporaryFile(mode='w', encoding='utf-8', newline='\n', delete=False)
        else:
            self.outFile = sys.stdout

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
            header_sym = 'GFXRECON_' + os.path.basename(self.genOpts.filename).replace('.h', '_H').upper()
            write('#ifndef ', header_sym, file=self.outFile)
            write('#define ', header_sym, file=self.outFile)
            self.newline()

    def endFile(self):
        """Method override."""
        # Finish C++ wrapper and multiple inclusion protection
        if (self.genOpts.protect_file and self.genOpts.filename):
            self.newline()
            write('#endif', file=self.outFile)
        if self.errFile:
            self.errFile.flush()
        if self.warnFile:
            self.warnFile.flush()
        if self.diagFile:
            self.diagFile.flush()
        if self.outFile:
            self.outFile.flush()
            if self.outFile != sys.stdout and self.outFile != sys.stderr:
                self.outFile.close()

            if self.genOpts is None:
                raise MissingGeneratorOptionsError()

            # On successfully generating output, move the temporary file to the
            # target file.
            if self.genOpts.filename is not None:
                directory = Path(self.genOpts.directory)
                if sys.platform == 'win32':
                    if not Path.exists(directory):
                        os.makedirs(directory)
                shutil.copy(self.outFile.name, directory / self.genOpts.filename)
                os.remove(self.outFile.name)
        self.genOpts = None

    def beginFeature(self, interface, emit):
        """Write interface for a feature and tag generated features as having been done.

        - interface - element for the `<version>` / `<extension>` to generate
        - emit - actually write to the header only when True"""

        # Reset feature specific data sets
        self.feature_struct_members = OrderedDict()
        self.feature_struct_aliases = OrderedDict()
        self.feature_cmd_params = OrderedDict()

        self.emit = emit
        if interface is not None:
            self.featureName = interface.get('name')
            # If there is an additional 'protect' attribute in the feature, save it
            self.featureExtraProtect = interface.get('protect')
        else:
            self.featureName = None
            self.featureExtraProtect = None

    def endFeature(self):
        """Finish an interface file, closing it when done.

        Derived classes responsible for emitting feature"""
        self.featureName = None
        self.featureExtraProtect = None

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

    def newline(self):
        """Print a newline to the output file (utility function)"""
        write('', file=self.outFile)

    def indent(self, value, spaces):
        """Indent all lines in a string.
        value - String to indent.
        spaces - Number of spaces to indent.
        """
        prefix = ' ' * spaces
        return '\n'.join([prefix + v if v else v for v in value.split('\n')])

    def clean_type_define(self, type):
        rtn = ''
        types = type.split(" ")
        skip = 0

        for t in types:
            if t[0] == '(':
                skip += 1
                continue
            elif t[0] == ')':
                skip -= 1
                continue
            elif skip:
                continue
            elif t == '_SECURITY_ATTRIBUTES' or (
                t[0] != '_' and t != 'STDMETHODCALLTYPE' and t != 'WINAPI'
                and t != 'IN' and t != 'OUT'
            ):
                if rtn:
                    rtn += ' '
                rtn += t
        return rtn

    def get_return_value_info(self, param_type, function_name):
        base_type = ''
        full_type = param_type
        const = False
        pointer = 0  # 1: *, 2: ** ...
        types1 = self.clean_type_define(param_type)
        types = types1.split(" ")

        for t in types:
            if t == 'const':
                const = True
            elif t == '*':
                pointer += 1
            elif t != 'struct':
                if base_type:
                    base_type += ' '
                base_type += t

        array_length = None
        array_capacity = 0
        array_dimension = 0
        for e in self.RETURN_ARRAY_SIZE_LIST:
            if e[0] == function_name:
                array_length = e[1]

        platform_base_type = None
        platform_full_type = None
        if base_type in self.PLATFORM_TYPES:
            type_info = self.PLATFORM_TYPES[base_type]
            platform_base_type = base_type
            platform_full_type = full_type
            base_type = type_info['baseType']
            full_type = full_type.replace(base_type, type_info['replaceWith'])
            replace_with = type_info['replaceWith']
            if 'const ' in replace_with:
                const = True
            pointer += replace_with.count('*')

        return ValueInfo(
            name='return_value',
            base_type=base_type,
            full_type=full_type,
            pointer_count=pointer,
            array_length=array_length,
            array_capacity=array_capacity,
            array_dimension=array_dimension,
            platform_base_type=platform_base_type,
            platform_full_type=platform_full_type,
            is_const=const
        )

    def get_value_info(self, param):
        struct_name = ''
        if ('parent' in param) and ('name' in param['parent']):
            struct_name = param['parent']['name']
            if (param['parent']['parent']
                ) and ('name' in param['parent']['parent']):
                struct_name = param['parent']['parent']['name'
                                                        ] + '_' + struct_name

        name = param['name']
        full_type = param['type']
        const = False
        pointer = 0  # 1: *, 2: ** ...
        types1 = self.clean_type_define(full_type)
        types = types1.split(" ")
        base_type = ''

        for t in types:
            if t == 'const':
                const = True
            elif t == '*':
                pointer += 1
            elif t != 'struct':
                if base_type:
                    base_type += ' '
                base_type += t

        platform_base_type = None
        platform_full_type = None
        if base_type in self.PLATFORM_TYPES:
            type_info = self.PLATFORM_TYPES[base_type]
            platform_base_type = base_type
            platform_full_type = full_type
            base_type = type_info['baseType']
            full_type = full_type.replace(base_type, type_info['replaceWith'])
            replace_with = type_info['replaceWith']
            if 'const ' in replace_with:
                const = True
            pointer += replace_with.count('*')

        array_length = None
        array_capacity = 0
        array_dimension = 0
        if 'array_size' in param:
            array_capacity = int(param['array_size'])
            array_length = array_capacity
            if 'multi_dimensional_array' in param:
                array_dimension = int(param['multi_dimensional_array'])

        # Check if it is an array pointer, and get the size of parameter's name.
        if pointer > 0:
            for e in self.ARRAY_SIZE_LIST:
                if e[0] == struct_name and name == e[1]:
                    array_length = e[2]

            if not array_length:
                index_parentheses1 = full_type.find('(')
                if index_parentheses1 != -1:
                    index_parentheses2 = full_type[
                        index_parentheses1
                        + 1:].find(')') + index_parentheses1
                    index_parentheses11 = index_parentheses1
                    parentheses = 0

                    while True:
                        index_parentheses111 = full_type[index_parentheses11
                                                         + 1:index_parentheses2
                                                         ].find('(')
                        if index_parentheses111 == -1:
                            break
                        index_parentheses11 += index_parentheses111 + 1
                        parentheses += 1

                    while parentheses > -1:
                        index_parentheses22 = full_type[index_parentheses2
                                                        + 1:].find(')')
                        if index_parentheses22 == -1:
                            break
                        index_parentheses2 += index_parentheses22 + 1
                        parentheses -= 1

                    param = full_type[index_parentheses1
                                      + 2:index_parentheses2]
                    if param[0] != '_':
                        param_list = param.split(', ')
                        array_length = param_list[0]
                        if (
                            array_length.find('Size') != -1
                            and base_type.find('void') == -1
                        ):
                            array_length += ('/sizeof ' + base_type)
                        elif array_length[-1] == ' ':
                            array_length = array_length[:-1]

        if struct_name in self.NOT_ARRAY_DICT:
            not_array_list = self.NOT_ARRAY_DICT[struct_name]
            if name in not_array_list:
                array_length = None
                array_capacity = 0
                array_dimension = 0

        return ValueInfo(
            name=name,
            base_type=base_type,
            full_type=full_type,
            pointer_count=pointer,
            array_length=array_length,
            array_capacity=array_capacity,
            array_dimension=array_dimension,
            platform_base_type=platform_base_type,
            platform_full_type=platform_full_type,
            bitfield_width=self.get_bit_field(struct_name, name),
            is_const=const,
            is_com_outptr=self.is_com_outptr(struct_name, name, full_type)
        )

    def make_decoded_param_type(self, value):
        """Create a type to use for a decoded parameter, using the decoder wrapper types for pointers."""
        type_name = value.base_type

        # is_pointer will be False for static arrays.
        if value.is_pointer or value.is_array:
            count = value.pointer_count

            if self.is_struct(type_name):
                if (value.array_dimension and value.array_dimension == 1):
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
                    if (count > 1):
                        # If this was a pointer to memory (void**) allocated internally by the implementation, it was encoded as
                        # an array of bytes but must be retrieved as a pointer to a memory allocation. For this case, the array
                        # length value defines the size of the memory referenced by the single retrieved pointer.
                        type_name = 'PointerDecoder<uint8_t, void*>'
                    else:
                        # If this was an array (void*) it was encoded as an array of bytes.
                        type_name = 'PointerDecoder<uint8_t>'
                elif count > 1:
                    # If this was a pointer to a pointer to an unknown object (void**), it was encoded as a pointer to a 64-bit address value.
                    # So, we specify uint64_t as the decode type and void* as the type to be used for Vulkan API call output parameters.
                    type_name = 'PointerDecoder<uint64_t, void*>'
                else:
                    # If this was a pointer to an unknown object (void*), it was encoded as a 64-bit address value.
                    type_name = 'uint64_t'
            elif self.is_handle(type_name):
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
        elif self.is_handle(type_name):
            type_name = 'format::HandleId'
        else:
            type_name = '{}'.format(type_name)

        return type_name

    def check_struct_member_handles(
        self,
        typename,
        structs_with_handles,
        structs_with_handle_ptrs=None,
        ignore_output=False,
        structs_with_map_data=None,
        extra_types=None
    ):
        """Determines if the specified struct type contains members that have a handle type or are structs that contain handles.
        Structs with member handles are added to a dictionary, where the key is the structure type and the value is a list of the handle members.
        An optional list of structure types that contain handle members with pointer types may also be generated.
        """
        handles = []
        has_handle_pointer = False
        map_data = []
        for value in self.feature_struct_members[typename]:
            if self.is_handle(value.base_type) or self.is_class(value) or (
                extra_types and value.base_type in extra_types
            ):
                # The member is a handle.
                handles.append(value)
                if (
                    (structs_with_handle_ptrs is not None)
                    and (value.is_pointer or value.is_array)
                ):
                    has_handle_pointer = True
            elif self.is_struct(value.base_type) and (
                (value.base_type in structs_with_handles) and
                ((not ignore_output) or (not '_Out_' in value.full_type))
            ):
                # The member is a struct that contains a handle.
                handles.append(value)
                if (
                    (structs_with_handle_ptrs is not None)
                    and (value.name in structs_with_handle_ptrs)
                ):
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
                    elif union_info.base_type in self.source_dict['class_dict'
                                                                  ]:
                        handles.append(value)
                        has_handle_pointer = True
                    elif union_info.base_type in self.MAP_STRUCT_TYPE:
                        if (structs_with_map_data is not None):
                            map_data.append(value)

            if (structs_with_map_data is not None) and (
                (value.base_type in self.MAP_STRUCT_TYPE) or
                (value.base_type in structs_with_map_data)
            ):
                map_data.append(value)

        if map_data:
            structs_with_map_data[typename] = map_data

        if handles:
            # Process the list of struct members a second time to check for
            # members with the same type as the struct.  The current struct
            # type has not been added to the table of structs with handles
            # yet, so we must check the struct members a second time, looking
            # for members with the struct type, now that we know the current
            # struct type contains members that are handles/objects.  Any
            # struct members that have the same type as the struct must be
            # added to the handle member list.
            for value in self.feature_struct_members[typename]:
                if (value.base_type == typename) and (
                    (not ignore_output) or (not '_Out_' in value.full_type)
                ):
                    handles.append(value)

            structs_with_handles[typename] = handles
            if (structs_with_handle_ptrs is not None) and has_handle_pointer:
                structs_with_handle_ptrs.append(typename)
            return True
        return False

    def make_consumer_func_decl(
        self, return_type, name, values, dx12_method=False
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

        if dx12_method:
            param_decl = self.make_aligned_param_decl(
                'format::HandleId', 'object_id', self.INDENT_SIZE,
                self.genOpts.align_func_param
            )
            param_decls.append(param_decl)

        if return_type != 'void':
            method_name = name[name.find('::Process_') + 10:]
            return_value = self.get_return_value_info(
                return_type, method_name
            )
            rtn_type1 = self.make_decoded_param_type(return_value)
            if rtn_type1.find('Decoder') != -1:
                rtn_type1 += '*'
            param_decl = self.make_aligned_param_decl(
                rtn_type1, 'return_value', self.INDENT_SIZE,
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

            if is_override:
                if value.is_pointer or value.is_array:
                    count = value.pointer_count
                    if self.is_struct(type_name):
                        param_type = 'StructPointerDecoder<Decoded_{}>*'.format(
                            type_name
                        )
                    elif self.is_class(value):
                        if count == 1:
                            param_type = type_name[2:] + 'Info*'
                        else:
                            param_type = 'HandlePointerDecoder<{}*>'.format(type_name)
                    else:
                        param_type = 'const ' + type_name + '*'
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

    def get_api_prefix(self):
        return 'Dx12'

    def get_wrapper_prefix_from_type(self):
        return 'object_wrappers'

    def is_resource_dump_class(self):
        return True if ('ReplayDumpResources' in self.__class__.__name__) else False

    def is_dump_resources_api_call(self, call_name):
        return False

    def get_generic_struct_handle_type_value(self, struct_name, member_name):
        """For a struct member that contains a generic handle value, retrieve the struct member
        containing an enum value defining the specific handle type.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as VkObjectType.
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
        type such as VkObjectType.
        """
        if cmd_name in self.GENERIC_HANDLE_APICALLS:
            cmd_entry = self.GENERIC_HANDLE_APICALLS[cmd_name]
            if param_name in cmd_entry:
                return cmd_entry[param_name]
        return None

    def is_generic_struct_handle_value(self, struct_name, member_name):
        """Determine if a struct member contains a generic handle value.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as VkObjectType.
        """
        if self.get_generic_struct_handle_type_value(struct_name, member_name):
            return True
        return False

    def is_generic_cmd_handle_value(self, cmd_name, param_name):
        """Determine if an API call parameter contains a generic handle value.  Generic handles have an
        integer type such as uint64_t, with an associated enum value defining the specific
        type such as VkObjectType.
        """
        if self.get_generic_cmd_handle_type_value(cmd_name, param_name):
            return True
        return False

    def genType(self, typeinfo, name, alias):
        """Method override."""
        self.genStruct(None, None, None)
        self.genCmd(None, None, None)
        self.gen_method()

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for class_name, class_value in v.classes.items():
                if self.is_required_struct_data(class_name, class_value):
                    self.feature_struct_members[
                        class_name] = self.make_value_info(
                            class_value['properties']['public']
                        )

    def genCmd(self, cmdinfo, name, alias):
        """Method override."""
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for m in v.functions:
                if self.is_required_function_data(m):
                    name = m['name']
                    self.feature_cmd_params[name] = (
                        self.clean_type_define(m['rtnType']), '',
                        self.make_value_info(m['parameters'])
                    )

    def gen_method(self):
        header_dict = self.source_dict['header_dict']
        for k, v in header_dict.items():
            for k, v in v.classes.items():
                if self.is_required_class_data(v):
                    for m in v['methods']['public']:
                        name = k + '_' + m['name']
                        self.feature_method_params[name] = (
                            self.clean_type_define(m['rtnType']), '',
                            self.make_value_info(m['parameters'])
                        )

    def is_struct(self, base_type):
        """Check for struct type."""
        if (
            (base_type in self.struct_names)
            or (base_type in self.PLATFORM_STRUCTS)
        ):
            return True
        return False

    def is_handle(self, base_type):
        return False

    def has_basetype(self, base_type):
        return False

    def get_basetype(self, base_type):
        return self.base_types[base_type]

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
            # Vulkan seems to follow a pattern where input pointers will be const and output pointers will not be const.
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

    def is_manually_generated_cmd_name(self, command):
        """Determines if a command is in the list of manually generated command names."""
        if self.MANUALLY_GENERATED_COMMANDS is not None and command in self.MANUALLY_GENERATED_COMMANDS:
           return True
        return False

    def get_filtered_cmd_names(self):
        """Retrieves a filtered list of keys from self.feature_cmd_params with blacklisted items removed."""
        return [
            key for key in self.feature_cmd_params
            if not self.is_cmd_black_listed(key)
        ]

    def get_filtered_method_names(self):
        return [
            key for key in self.feature_method_params
            if not self.is_method_black_listed(key)
        ]

    def make_value_info(self, params):
        """Method override."""
        values = []
        for p in params:
            values.append(self.get_value_info(p))
        return values

    def get_filtered_struct_names(self):
        """Method override."""
        if self.check_blacklist:
            return [
                key for key in self.source_dict['struct_dict']
                if not self.is_struct_black_listed(key)
            ]
        else:
            return self.source_dict['struct_dict'].keys()

    def get_category_type(self, type):
        if self.is_struct(type):
            return 'struct'
        elif self.is_class_type(type):
            return 'class'
        elif self.is_enum(type):
            return 'enum'
        elif self.is_union(type):
            return 'union'
        return 'base'

    def is_track_command_list(self, value):
        if self.has_class(value) or self.has_cpu_descriptor_handle(
            value
        ) or self.has_gpu_descriptor_handle(
            value
        ) or self.has_gpu_virtual_address(value):
            return True
        return False

    def has_cpu_descriptor_handle(self, value):
        if 'D3D12_CPU_DESCRIPTOR_HANDLE' in value.base_type:
            return True

        members = self.get_members(value.base_type, False)
        if members:
            for v in members:
                if self.has_cpu_descriptor_handle(v):
                    return True
        return False

    def has_gpu_descriptor_handle(self, value):
        if 'D3D12_GPU_DESCRIPTOR_HANDLE' in value.base_type:
            return True

        members = self.get_members(value.base_type, False)
        if members:
            for v in members:
                if self.has_gpu_descriptor_handle(v):
                    return True
        return False

    def has_gpu_virtual_address(self, value):
        if 'D3D12_GPU_VIRTUAL_ADDRESS' in value.base_type:
            return True

        members = self.get_members(value.base_type, False)
        if members:
            for v in members:
                if self.has_gpu_virtual_address(v):
                    return True
        return False

    def has_class(self, value):
        if self.is_class(value) or self.has_class_in_struct(
            value.base_type
        ) or (self.has_class_in_union(value)):
            return True
        return False

    def has_class_in_struct(self, type):
        struct_members = self.get_struct_members(type)
        if struct_members:
            for v in struct_members:
                if self.has_class(v):
                    return True
        return False

    def has_class_in_union(self, value):
        union_members = self.get_union_members(value.base_type)
        if union_members:
            for m in union_members:
                if self.has_class(m):
                    return True
        return False

    def get_function_arguments(self, info):
        values = list()
        for p in info['parameters']:
            values.append(self.get_value_info(p))
        return values

    def get_members(self, type, is_enum=True, is_union=True, is_struct=True):
        # D3D12's class has no members.
        if is_struct:
            members = self.get_struct_members(type)
            if members:
                return members
        if is_enum:
            members = self.get_enum_members(type)
            if members:
                return members
        if is_union:
            members = self.get_union_members(type)
            if members:
                return members
        return None

    def is_struct(self, type):
        """Method override."""
        # This type is from winnt.h. It isn't parsed. It's in custom classes.
        if type == 'LARGE_INTEGER':
            return True
        struct_dict = self.source_dict['struct_dict']
        return type in struct_dict

    def get_struct_members(self, type):
        struct_dict = self.source_dict['struct_dict']
        struct_info = struct_dict.get(type)
        if struct_info:
            members = list()
            for k, v in struct_info['properties'].items():
                for p in v:
                    members.append(self.get_value_info(p))
            return members
        return None

    def is_class_type(self, type):
        class_dict = self.source_dict['class_dict']
        return type in class_dict

    def is_class(self, value):
        """Method override. Use value, not type because it needs to check void** case."""
        if value.base_type == 'void' and value.pointer_count == 2 and value.is_com_outptr:
            return True

        class_dict = self.source_dict['class_dict']
        return value.base_type in class_dict

    def get_bit_field(self, struct_name, param_name):
        for m in self.BIT_FIELD_LIST:
            if m[0] == struct_name and m[1] == param_name:
                return m[2]
        return ''

    def is_enum(self, type):
        """Method override."""
        enum_dict = self.source_dict['enum_dict']
        return type in enum_dict

    def get_enum_members(self, type):
        enum_dict = self.source_dict['enum_dict']
        enum_info = enum_dict.get(type)
        if enum_info:
            members = list()
            for v in enum_info['values']:
                members.append([v['name'], v['value']])
            return members
        return None

    def is_union(self, type):
        if type[:12] == '<anon-union-':
            union_dict = self.source_dict['union_dict']
            return type in union_dict
        return False

    def get_union_members(self, type):
        if type[:12] == '<anon-union-':
            union_dict = self.source_dict['union_dict']
            union_info = union_dict.get(type)
            if union_info:
                members = list()
                for m in union_info['members']:
                    members.append(self.get_value_info(m))
                return members
        return None

    def convert_function(self, type):
        for e in self.CONVERT_FUNCTION_LIST:
            for k in e[0]:
                if type == k:
                    return e[1]
        return type

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
        type = self.convert_function(base_type)
        if self.is_struct(type):
            return type
        elif self.is_union(type):
            return 'Union'
        elif self.is_enum(type):
            return 'Enum'
        elif type == 'wchar_t':
            return 'WString'
        elif type == 'char':
            return 'String'
        elif type == 'Function' or self.is_function_ptr(type):
            return 'FunctionPtr'
        elif type == 'size_t':
            return 'SizeT'
        elif type == 'int':
            # Extensions use the int type when dealing with file descriptors
            return 'Int32'
        elif type.endswith('_t'):
            if type[0] == 'u':
                # For unsigned types, capitalize the first two characters.
                return type[0].upper() + type[1].upper(
                ) + type[2:-2]
            else:
                return type[:-2].title()
        elif type[0].islower():
            return type.title()

        return type

    def is_required_function_data(self, function_source_data):
        name = function_source_data['name']
        if (
            function_source_data['parent'] is None and name[:7] != 'DEFINE_'
            and name[:8] != 'DECLARE_' and name != 'InlineIsEqualGUID'
            and name != 'IsEqualGUID' and name[:8] != 'operator'
        ):
            return True
        return False

    def is_required_class_data(self, class_source_data):
        if class_source_data['declaration_method'] == 'class':
            return True
        return False

    def is_required_struct_data(self, struct_type, struct_source_data):
        if struct_source_data['declaration_method'] == 'struct' and (
            not self.check_blacklist
            or not struct_source_data['name'] in self.STRUCT_BLACKLIST
        ) and struct_type[-4:] != 'Vtbl' and struct_type.find(
            "::<anon-union-"
        ) == -1:
            return True
        return False

    def is_com_outptr(self, func_name, param_name, param_full_type):
        if 'COM_Outptr' in param_full_type:
            return True
        elif (
            func_name in self.COM_POINTER_PARAMS
            and param_name in self.COM_POINTER_PARAMS[func_name]
        ):
            return True
        return False

    def collect_struct_with_objects(self, header_dict):
        structs_with_objects = dict()

        for k, v in header_dict.items():
            for class_name, class_value in v.classes.items():
                if self.is_required_struct_data(class_name, class_value):
                    values = []
                    for prop_type, props in class_value['properties'].items():
                        for p in props:
                            value = self.get_value_info(p)

                            if (
                                self.is_struct(value.base_type) and
                                (value.full_type.find('_Out_') != -1) and
                                (value.base_type in structs_with_objects)
                            ) or (self.is_class(value)):
                                values.append(value)
                    if values:
                        structs_with_objects[class_name] = values

        return structs_with_objects

    def is_output(self, value):
        if (value.full_type.find('_Out') !=
            -1) or (value.full_type.find('_Inout') != -1):
            return True
        return False

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
        else:
            # XML does not provide lengths for all dimensions, instantiate a specialization of ArraySize2D to fetch the sizes
            type_list = ', '.join([self.clean_type_define(v.full_type) for v in values])
            arg_list = ', '.join([v.name for v in values])
            return ['ArraySize2D<{}>({})'.format(type_list, arg_list)]
