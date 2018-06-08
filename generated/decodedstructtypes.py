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
class DecodedStructTypesGeneratorOptions(GeneratorOptions):
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
class DecodedStructTypesOutputGenerator(OutputGenerator):
    """Generate specified API interfaces in a specific style, such as a C header"""
    ALL_SECTIONS = ['struct']
    # These API calls should not be processed by the code generator.  They require special layer specific implementations.
    STRUCT_BLACKLIST = []
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        OutputGenerator.__init__(self, errFile, warnFile, diagFile)
        # Typenames
        self.structNames = []                             # List of Vulkan struct typenames
    #
    def beginFile(self, genOpts):
        OutputGenerator.beginFile(self, genOpts)
        # C-specific
        #
        # Multiple inclusion protection & C++ wrappers.
        if (genOpts.protectFile and self.genOpts.filename):
            headerSym = re.sub('\.h', '_h',
                               os.path.basename(self.genOpts.filename)).upper()
            write('#ifndef', headerSym, file=self.outFile)
            write('#define', headerSym, file=self.outFile)
            self.newline()
        #
        # User-supplied prefix text, if any (list of strings)
        if (genOpts.prefixText):
            for s in genOpts.prefixText:
                write(s, file=self.outFile)
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
        self.newline()
        write('BRIMSTONE_BEGIN_NAMESPACE(brimstone)', file=self.outFile)
        write('BRIMSTONE_BEGIN_NAMESPACE(format)', file=self.outFile)
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
            write('\n'.join(self.sections['struct']), end='', file=self.outFile)
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
            if not alias:
                self.structNames.append(name)
                self.genStruct(typeinfo, name, alias)
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
            decls = self.genPointerDecode(typeinfo, typeName)
            body = 'struct Decoded_{}\n'.format(typeName)
            body += '{\n'
            body += '    using struct_type = {};\n'.format(typeName)
            body += '\n'
            body += '    {}* value{{ nullptr }};\n'.format(typeName)
            if decls:
                body += '\n'
                body += ''.join(decls)
            body += '};\n'
            self.appendSection('struct', body)
    #
    # Group (e.g. C "enum" type) generation.
    # These are concatenated together with other types.
    def genGroup(self, groupinfo, groupName, alias):
        OutputGenerator.genGroup(self, groupinfo, groupName, alias)
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
    # Check if the parameter is a pointer
    def getPointerCount(self, param):
        result = 0
        paramtype = param.find('type')
        if (paramtype.tail is not None) and ('*' in paramtype.tail):
            result = paramtype.tail.count('*')
        return result
    #
    # Check if the parameter is a function pointer
    def isFunctionPtr(self, typename):
        result = False
        if typename[:4] == 'PFN_':
            result = True
        return result
    #
    # Command definition
    def genPointerDecode(self, typeinfo, name):
        # Build array of lines for function body
        decls = []
        members = typeinfo.elem.findall('.//member')
        for member in members:
            paramname = noneStr(member.find('name').text)

            if paramname == 'pNext':
                # We have a special type to store the pNext chain
                decls.append('    std::unique_ptr<PNextNode> pNext;\n')
            else:
                typename = noneStr(member.find('type').text)
                count = self.getPointerCount(member)

                if count > 0:
                    # We currently only expect the '*' count to be greater than one for the char** case
                    if count > 1 and typename != 'char':
                        print("WARNING: Processing a multi-dimensional array that is not an array of strings ({})".format(typename + ('*' * count)))
                    if typename in self.structNames:
                        decls.append('    StructPointerDecoder<Decoded_{}> {};\n'.format(typename, paramname))
                    elif typename == 'char':
                        if count == 2:
                            decls.append('    StringArrayDecoder {};\n'.format(paramname))
                        else:
                            decls.append('    StringDecoder {};\n'.format(paramname))
                    elif typename == 'void':
                        if self.getArrayLen(member):
                            # If this was an array it was encoded as an array of bytes.
                            decls.append('    PointerDecoder<uint8_t> {};\n'.format(paramname))
                        else:
                            # If this was a pointer to an unknown object, it was encoded as a 64-bit address value.
                            decls.append('    uint64_t {};\n'.format(paramname))
                    else:
                        decls.append('    PointerDecoder<{}> {};\n'.format(typename, paramname))
                elif self.isStaticArray(member):
                    if typename in self.structNames:
                        decls.append('    StructPointerDecoder<Decoded_{}> {};\n'.format(typename, paramname))
                    elif typename == 'char':
                        decls.append('    StringDecoder {};\n'.format(paramname))
                    else:
                        decls.append('    PointerDecoder<{}> {};\n'.format(typename, paramname))
                elif self.isFunctionPtr(typename):
                    # Function pointers are encoded as a 64-bit address value.
                    decls.append('    uint64_t {};\n'.format(paramname))
                elif typename in self.structNames:
                    decls.append('    Decoded_{} {};\n'.format(typename, paramname))

        return decls
