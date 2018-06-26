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
class StructEncodersGeneratorOptions(GeneratorOptions):
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
class StructEncodersOutputGenerator(OutputGenerator):
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
        write('#include <cmath>', file=self.outFile)
        self.newline()
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "format/parameter_encoder.h"', file=self.outFile)
        self.newline()
        write('BRIMSTONE_BEGIN_NAMESPACE(brimstone)', file=self.outFile)
        self.newline()
        write('size_t encode_pnext_struct(format::ParameterEncoder* encoder, const void* value);', file=self.outFile)
    def endFile(self):
        # C-specific
        # Finish C++ wrapper and multiple inclusion protection
        self.newline()
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
            body = 'size_t encode_struct(format::ParameterEncoder* encoder, const {}& value)\n'.format(typeName)
            body += '{\n'
            body += '    size_t result = 0;\n'
            body += ''.join(self.genStructBody(typeinfo, typeName, 'value.'))
            body += '    return result;\n'
            body += '}\n'
            self.appendSection('struct', body)
            body = 'size_t encode_struct_ptr(format::ParameterEncoder* encoder, const {}* value)\n'.format(typeName)
            body += '{\n'
            body += '    size_t result = encoder->EncodeStructPtrPreamble(value);\n'
            body += '    if (value != nullptr)\n'
            body += '    {\n'
            body += '        result += encode_struct(encoder, *value);\n'
            body += '    }\n'
            body += '    return result;\n'
            body += '}\n'
            self.appendSection('struct', body)
            body = 'size_t encode_struct_array(format::ParameterEncoder* encoder, const {}* value, size_t len)\n'.format(typeName)
            body += '{\n'
            body += '    size_t result = encoder->EncodeStructArrayPreamble(value, len);\n'
            body += '    if ((value != nullptr) && (len > 0))\n'
            body += '    {\n'
            body += '        for(size_t i = 0; i < len; ++i)\n'
            body += '        {\n'
            body += '            result = encode_struct(encoder, value[i]);\n'
            body += '        }\n'
            body += '    }\n'
            body += '    return result;\n'
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
    def genStructBody(self, typeinfo, name, prefix):
        # Build array of lines for function body
        body = []
        members = typeinfo.elem.findall('.//member')
        for member in members:
            methodcall = self.genEncoderMethodCall(member, members, prefix)
            body.append('    result += {};\n'.format(methodcall))

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
    # Extract length values from latexmath.  Currently an inflexible solution that looks for specific
    # patterns that are found in vk.xml.  Will need to be updated when new patterns are introduced.
    def parseLateXMath(self, source):
        name = 'ERROR'
        decoratedName = 'ERROR'
        if 'mathit' in source:
            # Matches expressions similar to 'latexmath:[\lceil{\mathit{rasterizationSamples} \over 32}\rceil]'
            match = re.match(r'latexmath\s*\:\s*\[\s*\\l(\w+)\s*\{\s*\\mathit\s*\{\s*(\w+)\s*\}\s*\\over\s*(\d+)\s*\}\s*\\r(\w+)\s*\]', source)
            if not match or match.group(1) != match.group(4):
                raise 'Unrecognized latexmath expression'
            name = match.group(2)
            # TODO: More flexible typecasting support
            decoratedName = 'static_cast<size_t>({}({}/{}))'.format(*match.group(1, 2, 3))
        else:
            # Matches expressions similar to 'latexmath : [dataSize \over 4]'
            match = re.match(r'latexmath\s*\:\s*\[\s*(\w+)\s*\\over\s*(\d+)\s*\]', source)
            name = match.group(1)
            decoratedName = '{}/{}'.format(*match.group(1, 2))
        return name, decoratedName
    #
    # Generate the parameter encoder method call invocation
    def genEncoderMethodCall(self, param, params, prefix):
        paramname = prefix + noneStr(param.find('name').text)

        # pNext fields require special treatment and are not processed by typename
        if 'pNext' in paramname:
            return 'encode_pnext_struct(encoder, {})'.format(paramname)

        methodcall = ''
        args = [paramname]
        typename = noneStr(param.find('type').text)
        paramnames = [noneStr(p.find('name').text) for p in params]

        isstruct = False
        isstring = False
        isfuncp = False

        if typename in self.structNames:
            isstruct = True
            args = ['encoder'] + args
            methodcall = 'encode_struct'
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
            methodcall = 'encoder->Encode' + typename

        pointercount = self.getPointerCount(param)
        arraylen = self.getArrayLen(param)

        if arraylen and not (isstring and self.isStaticArray(param)):  # Make sure strings delcared as 'char s[N]' are not treated as string arrays
            lenparam = arraylen         # The parameter name that appears in the length expression
            lenexpr = arraylen          # The expression that produces the array length (needed for the latexmath case where param name != param expr)
            if 'latexmath' in arraylen:
                lenparam, lenexpr = self.parseLateXMath(arraylen)

            if isstruct:
                methodcall += '_array'
            else:
                methodcall += 'Array'
            if self.isPointer(lenparam, params):
                args.append('({name} != nullptr) ? (*{name}) : 0'.format(name=lenexpr.replace(lenparam, prefix + lenparam)))
            elif lenparam in paramnames:
                # Length is provided by one of the other parameters and needs the prefix
                args.append(lenexpr.replace(lenparam, prefix + lenparam))
            else:
                # Length is a constant value
                args.append(lenexpr)
        elif isstruct:
            if pointercount:
                methodcall += '_ptr'
        # String function names do not have the Ptr/Value suffix
        elif not (isstring or isfuncp):
            if pointercount:
                methodcall += 'Ptr' * pointercount
            else:
                methodcall += 'Value'

        return '{}({})'.format(methodcall, ', '.join(args))

