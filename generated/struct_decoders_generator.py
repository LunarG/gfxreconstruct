#!/usr/bin/python3 -i
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

import os,re,sys
from generator import *
from common_codegen import GetFeatureProtect

# CGeneratorOptions - subclass of GeneratorOptions.
#
# Adds options used by COutputGenerator objects during C language header
# generation.
#
# Additional members
#   prefixText - list of strings to prefix generated header with
#     (usually a copyright statement + calling convention macros).
#   protectFile - True if multiple inclusion protection should be
#     generated (based on the filename) around the entire header.
#   protectFeature - True if #ifndef..#endif protection should be
#     generated around a feature interface in the header file.
#   genFuncPointers - True if function pointer typedefs should be
#     generated
#   protectProto - If conditional protection should be generated
#     around prototype declarations, set to either '#ifdef'
#     to require opt-in (#ifdef protectProtoStr) or '#ifndef'
#     to require opt-out (#ifndef protectProtoStr). Otherwise
#     set to None.
#   protectProtoStr - #ifdef/#ifndef symbol to use around prototype
#     declarations, if protectProto is set
#   apicall - string to use for the function declaration prefix,
#     such as APICALL on Windows.
#   apientry - string to use for the calling convention macro,
#     in typedefs, such as APIENTRY.
#   apientryp - string to use for the calling convention macro
#     in function pointer typedefs, such as APIENTRYP.
#   indentFuncProto - True if prototype declarations should put each
#     parameter on a separate line
#   indentFuncPointer - True if typedefed function pointers should put each
#     parameter on a separate line
#   alignFuncParam - if nonzero and parameters are being put on a
#     separate line, align parameter names at the specified column
class StructDecodersGeneratorOptions(GeneratorOptions):
    """Represents options during C interface generation for headers"""
    def __init__(self,
                 filename = None,
                 directory = '.',
                 apiname = None,
                 profile = None,
                 versions = '.*',
                 emitversions = '.*',
                 defaultExtensions = None,
                 addExtensions = None,
                 removeExtensions = None,
                 emitExtensions = None,
                 sortProcedure = regSortFeatures,
                 prefixText = "",
                 genFuncPointers = True,
                 protectFile = True,
                 protectFeature = True,
                 protectProto = None,
                 protectProtoStr = None,
                 apicall = '',
                 apientry = '',
                 apientryp = '',
                 indentFuncProto = True,
                 indentFuncPointer = False,
                 alignFuncParam = 0):
        GeneratorOptions.__init__(self, filename, directory, apiname, profile,
                                  versions, emitversions, defaultExtensions,
                                  addExtensions, removeExtensions,
                                  emitExtensions, sortProcedure)
        self.prefixText      = prefixText
        self.genFuncPointers = genFuncPointers
        self.protectFile     = protectFile
        self.protectFeature  = protectFeature
        self.protectProto    = protectProto
        self.protectProtoStr = protectProtoStr
        self.apicall         = apicall
        self.apientry        = apientry
        self.apientryp       = apientryp
        self.indentFuncProto = indentFuncProto
        self.indentFuncPointer = indentFuncPointer
        self.alignFuncParam  = alignFuncParam

# COutputGenerator - subclass of OutputGenerator.
# Generates C-language API interfaces.
#
# ---- methods ----
# COutputGenerator(errFile, warnFile, diagFile) - args as for
#   OutputGenerator. Defines additional internal state.
# ---- methods overriding base class ----
# beginFile(genOpts)
# endFile()
# beginFeature(interface, emit)
# endFeature()
# genType(typeinfo,name)
# genStruct(typeinfo,name)
# genGroup(groupinfo,name)
# genEnum(enuminfo, name)
# genCmd(cmdinfo)
class StructDecodersOutputGenerator(OutputGenerator):
    """Generate specified API interfaces in a specific style, such as a C header"""
    ALL_SECTIONS = ['struct']
    # These API calls should not be processed by the code generator.  They require special layer specific implementations.
    STRUCT_BLACKLIST = ['VkBaseInStructure', 'VkBaseOutStructure']
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        OutputGenerator.__init__(self, errFile, warnFile, diagFile)
        # Internal state - accumulators for different inner block text
        self.sections = dict([(section, []) for section in self.ALL_SECTIONS])
        # Typenames
        self.structNames = []                             # List of Vulkan struct typenames
        self.handleTypes = set()                          # Set of handle type names
        self.flagsTypes = set()                           # Set of bitmask (flags) type names
        self.enumTypes = set()                            # Set of enum type names
    #
    def beginFile(self, genOpts):
        OutputGenerator.beginFile(self, genOpts)
        # C-specific
        #
        # Multiple inclusion protection & C++ wrappers.
        if (genOpts.protectFile and self.genOpts.filename):
            headerSym = re.sub('\.h', '_h',
                               os.path.basename(self.genOpts.filename)).upper()
            headerSym = re.sub('\.INC', '_INC', headerSym)
            write('#ifndef', headerSym, file=self.outFile)
            write('#define', headerSym, file=self.outFile)
            self.newline()
        #
        # User-supplied prefix text, if any (list of strings)
        if (genOpts.prefixText):
            for s in genOpts.prefixText:
                write(s, file=self.outFile)
        write('#include <cassert>', file=self.outFile)
        write('#include <memory>', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "format/pnext_node.h"', file=self.outFile)
        write('#include "format/pointer_decoder.h"', file=self.outFile)
        write('#include "format/string_array_decoder.h"', file=self.outFile)
        write('#include "format/string_decoder.h"', file=self.outFile)
        write('#include "format/struct_pointer_decoder.h"', file=self.outFile)
        write('#include "format/value_decoder.h"', file=self.outFile)
        self.newline()
        write('BRIMSTONE_BEGIN_NAMESPACE(brimstone)', file=self.outFile)
        write('BRIMSTONE_BEGIN_NAMESPACE(format)', file=self.outFile)
        self.newline()
        write('size_t decode_pnext_struct(const uint8_t* buffer, size_t buffer_size, std::unique_ptr<PNextNode>* pNext);', file=self.outFile)
    def endFile(self):
        # C-specific
        # Finish C++ wrapper and multiple inclusion protection
        self.newline()
        write('BRIMSTONE_END_NAMESPACE(format)', file=self.outFile)
        write('BRIMSTONE_END_NAMESPACE(brimstone)', file=self.outFile)
        if (self.genOpts.protectFile and self.genOpts.filename):
            self.newline()
            write('#endif', file=self.outFile)
        # Finish processing in superclass
        OutputGenerator.endFile(self)
    def beginFeature(self, interface, emit):
        # Start processing in superclass
        OutputGenerator.beginFeature(self, interface, emit)
        # C-specific
        # Accumulate includes, defines, types, enums, function pointer typedefs,
        # end function prototypes separately for this feature. They're only
        # printed in endFeature().
        self.sections = dict([(section, []) for section in self.ALL_SECTIONS])
        self.featureExtraProtect = GetFeatureProtect(interface)
    def endFeature(self):
        # C-specific
        # Actually write the interface to the output file.
        if (self.emit and self.sections['struct']):
            self.newline()
            if (self.genOpts.protectFeature):
                write('#ifndef', self.featureName, file=self.outFile)
            # If type declarations are needed by other features based on
            # this one, it may be necessary to suppress the ExtraProtect,
            # or move it below the 'for section...' loop.
            if (self.featureExtraProtect != None):
                write('#ifdef', self.featureExtraProtect, file=self.outFile)
            if (self.genOpts.protectProto):
                write(self.genOpts.protectProto,
                        self.genOpts.protectProtoStr, file=self.outFile)
            write('\n'.join(self.sections['struct']), end='', file=self.outFile)
            if (self.genOpts.protectProto):
                write('#endif', file=self.outFile)
            if (self.featureExtraProtect != None):
                write('#endif /*', self.featureExtraProtect, '*/', file=self.outFile)
            if (self.genOpts.protectFeature):
                write('#endif /*', self.featureName, '*/', file=self.outFile)
        # Finish processing in superclass
        OutputGenerator.endFeature(self)
    #
    # Append a definition to the specified section
    def appendSection(self, section, text):
        # self.sections[section].append('SECTION: ' + section + '\n')
        self.sections[section].append(text)
    #
    # Type generation
    def genType(self, typeinfo, name, alias):
        OutputGenerator.genType(self, typeinfo, name, alias)
        typeElem = typeinfo.elem
        # If the type is a struct type, traverse the imbedded <member> tags
        # generating a structure. Otherwise, emit the tag text.
        category = typeElem.get('category')
        if (category == 'struct' or category == 'union'):
            # Ignore structures that are a typedef of an alias
            if not alias:
                self.structNames.append(name)
                self.genStruct(typeinfo, name, alias)
        elif (category == 'handle'):
            self.handleTypes.add(name)
        elif (category == 'bitmask'):
            self.flagsTypes.add(name)
    #
    # Struct (e.g. C "struct" type) generation.
    # This is a special case of the <type> tag where the contents are
    # interpreted as a set of <member> tags instead of freeform C
    # C type declarations. The <member> tags are just like <param>
    # tags - they are a declaration of a struct or union member.
    # Only simple member declarations are supported (no nested
    # structs etc.)
    def genStruct(self, typeinfo, typeName, alias):
        OutputGenerator.genStruct(self, typeinfo, typeName, alias)
        if not typeName in self.STRUCT_BLACKLIST:
            body = 'size_t decode_struct(const uint8_t* buffer, size_t buffer_size, Decoded_{}* wrapper)\n'.format(typeName)
            body += '{\n'
            body += '    assert((wrapper != nullptr) && (wrapper->value != nullptr));\n'
            body += '\n'
            body += '    size_t bytes_read = 0;\n'
            body += '    {}* value = wrapper->value;\n'.format(typeName)
            body += '\n'
            body += self.genStructBody(typeinfo, typeName)
            body += '\n'
            body += '    return bytes_read;\n'
            body += '}\n'
            self.appendSection('struct', body)
    #
    # Group (e.g. C "enum" type) generation.
    # These are concatenated together with other types.
    def genGroup(self, groupinfo, groupName, alias):
        OutputGenerator.genGroup(self, groupinfo, groupName, alias)
        self.enumTypes.add(groupName)
    # Enumerant generation
    # <enum> tags may specify their values in several ways, but are usually
    # just integers.
    def genEnum(self, enuminfo, name, alias):
        OutputGenerator.genEnum(self, enuminfo, name, alias)
    #
    # Command generation
    def genCmd(self, cmdinfo, name, alias):
        OutputGenerator.genCmd(self, cmdinfo, name, alias)
    #
    # Command definition
    def genStructBody(self, typeinfo, name):
        # Build array of lines for function body
        body = ''
        members = typeinfo.elem.findall('.//member')
        for member in members:
            body += self.genDecoderFunctionCall(member)

        return body
    #
    # Check if the parameter is a function pointer
    def isFunctionPtr(self, typename):
        result = False
        if typename[:4] == 'PFN_':
            result = True
        return result
    #
    # Check if the parameter is a pointer
    def getPointerCount(self, param):
        result = 0
        paramtype = param.find('type')
        if (paramtype.tail is not None) and ('*' in paramtype.tail):
            result = paramtype.tail.count('*')
        return result
    #
    # Retrieve the value of the len tag
    def getArrayLen(self, param):
        result = None
        len = param.attrib.get('len')
        if len:
            # Check for a string or array of strings
            if 'null-terminated' in len:
                # Strings are ignored, but string arrays are checked for a length value.
                # For string arrays, 'len' can look like 'count,null-terminated', indicating that we have an array of null terminated
                # strings.  We strip the null-terminated substring from the 'len' field and only return the parameter specifying the string count.
                if len != 'null-terminated':
                    result = len.split(',')[0]
            else:
                result = len
            if result:
                result = str(result).replace('::', '->')
        else:
            # Check for a static array
            paramname = param.find('name')
            if (paramname.tail is not None) and ('[' in paramname.tail):
                paramenumsize = param.find('enum')
                if paramenumsize is not None:
                    result = paramenumsize.text
                else:
                    result = paramname.tail[1:-1]
        return result
    #
    # Check if the parameter is a static array
    def isStaticArray(self, param):
        result = False
        paramname = param.find('name')
        if (paramname.tail is not None) and ('[' in paramname.tail):
            result = True
        return result
    #
    # Find the the parameter with the specified name in the parameter list and determine if it is a pointer
    def isPointer(self, name, params):
        result = False
        for param in params:
            if name == noneStr(param.find('name').text):
                if self.getPointerCount(param) > 0:
                    result = True
                break
        return result
    #
    # Generate the parameter decoder function call invocation
    def genDecoderFunctionCall(self, param):
        bufferargs = '(buffer + bytes_read), (buffer_size - bytes_read)'
        paramname = noneStr(param.find('name').text)

        body = ''

        # pNext fields require special treatment and are not processed by typename
        if 'pNext' in paramname:
            body += '    bytes_read += decode_pnext_struct({}, &(wrapper->{}));\n'.format(bufferargs, paramname)
            body += '    value->pNext = wrapper->pNext->GetPointer();\n'
            return body

        typename = noneStr(param.find('type').text)

        isstruct = False
        isstring = False
        isfuncp = False

        if typename in self.structNames:
            isstruct = True
        else:
            if typename in self.handleTypes:
                typename = 'Handle'
            elif typename in self.flagsTypes:
                typename = 'Flags'
            elif typename in self.enumTypes:
                typename = 'Enum'
            elif typename == 'char':
                isstring = True
                typename = 'String'
            elif self.isFunctionPtr(typename):
                isfuncp = True
                typename = 'FunctionPtr'
            elif typename == 'size_t':
                typename = 'SizeT'
            elif typename[-2:] == '_t':
                typename = typename[:-2].title()
                if typename[0] == 'U':
                    typename = typename[0] + typename[1].upper() + typename[2:]
            elif typename == 'int':
                # Extensions use the int type when dealing with file descriptors
                typename = 'Int32'
            elif typename[0].islower():
                typename = typename.title()

        pointercount = self.getPointerCount(param)
        arraylen = self.getArrayLen(param)

        if pointercount or arraylen:
            if typename == 'Void' and not arraylen:
                # Pointer to an unknown object type, encoded as a 64-bit integer ID.
                body += '    bytes_read += ValueDecoder::DecodeAddress({}, &(wrapper->{}));\n'.format(bufferargs, paramname)
                body += '    value->{} = nullptr;\n'.format(paramname)
            else:
                if self.isStaticArray(param):
                    # The pointer decoder will write directly to the struct member's memory.
                    body += '    wrapper->{paramname}.SetExternalMemory(value->{paramname}, {arraylen});\n'.format(paramname=paramname, arraylen=arraylen)

                if isstruct:
                    body += '    bytes_read += wrapper->{}.Decode({});\n'.format(paramname, bufferargs)
                elif isstring:
                    body += '    bytes_read += wrapper->{}.Decode({});\n'.format(paramname, bufferargs)
                else:
                    body += '    bytes_read += wrapper->{}.Decode{}({});\n'.format(paramname, typename, bufferargs)

                if not self.isStaticArray(param):
                    # Point the real struct's member pointer to the pointer decoder's memory.
                    body += '    value->{paramname} = wrapper->{paramname}.GetPointer();\n'.format(paramname=paramname)
        else:
            if isstruct:
                body += '    wrapper->{paramname}.value = &(value->{paramname});\n'.format(paramname=paramname)
                body += '    bytes_read += decode_struct({}, &(wrapper->{}));\n'.format(bufferargs, paramname)
            elif isfuncp:
                body += '    bytes_read += ValueDecoder::DecodeAddress({}, &(wrapper->{}));\n'.format(bufferargs, paramname)
                body += '    value->{} = nullptr;\n'.format(paramname)
            else:
                body += '    bytes_read += ValueDecoder::Decode{}Value({}, &(value->{}));\n'.format(typename, bufferargs, paramname)

        return body

