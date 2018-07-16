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
class APICallEncodersGeneratorOptions(GeneratorOptions):
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
class APICallEncodersOutputGenerator(OutputGenerator):
    """Generate specified API interfaces in a specific style, such as a C header"""
    # This is an ordered list of sections in the header file.
    ALL_SECTIONS = ['command']
    # These API calls should not be processed by the code generator.  They require special layer specific implementations.
    APICALL_BLACKLIST = ['vkGetInstanceProcAddr',
                         'vkGetDeviceProcAddr',
                         'vkEnumerateInstanceLayerProperties',
                         'vkEnumerateDeviceLayerProperties',
                         'vkEnumerateInstanceExtensionProperties',
                         'vkEnumerateDeviceExtensionProperties',
                         'vkEnumerateInstanceVersion']
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
        self.flagsTypes = set()                            # Set of bitmask (flags) type names
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
            write('#ifndef', headerSym, file=self.outFile)
            write('#define', headerSym, file=self.outFile)
            self.newline()
        #
        # User-supplied prefix text, if any (list of strings)
        if (genOpts.prefixText):
            for s in genOpts.prefixText:
                write(s, file=self.outFile)
        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "format/api_call_id.h"', file=self.outFile)
        write('#include "format/trace_manager.h"', file=self.outFile)
        write('#include "format/parameter_encoder.h"', file=self.outFile)
        self.newline()
        write('BRIMSTONE_BEGIN_NAMESPACE(brimstone)', file=self.outFile)
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
        if (self.emit and self.sections['command']):
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
            write('\n'.join(self.sections['command']), end='', file=self.outFile)
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
        if not name in self.APICALL_BLACKLIST:
            cmddef = self.makeCDefs(cmdinfo.elem) + '\n'
            cmddef += '{\n'
            cmddef += ''.join(self.genCmdBody(cmdinfo, name))
            cmddef += '}\n'
            self.appendSection('command', cmddef)
    #
    # makeCDefs - return C function definition for a command
    # cmd - Element containing a <command> tag
    def makeCDefs(self, cmd):
        """Generate C function definition for <command> Element"""
        proto = cmd.find('proto')
        params = cmd.findall('param')
        # Begin accumulating prototype and typedef strings
        pdecl = self.genOpts.apicall
        #
        # Insert the function return type/name.
        # For prototypes, add APIENTRY macro before the name.
        # Done by walking the tree for <proto> element by element.
        # etree has elem.text followed by (elem[i], elem[i].tail)
        #   for each child element and any following text
        # Leading text
        pdecl += noneStr(proto.text)
        # For each child element, if it's a <name> wrap in appropriate
        # declaration. Otherwise append its contents and tail contents.
        for elem in proto:
            text = noneStr(elem.text)
            tail = noneStr(elem.tail)
            if (elem.tag == 'name'):
                pdecl += self.makeProtoName(text, tail)
            else:
                pdecl += text + tail
        # Now add the parameter declaration list. Concatenate all
        # the text from a <param> node without the tags. No tree
        # walking required since all tags are ignored.
        # Uses: self.indentFuncProto
        # self.indentFuncPointer
        # self.alignFuncParam
        # Might be able to doubly-nest the joins, e.g.
        #   ','.join(('_'.join([l[i] for i in range(0,len(l))])
        n = len(params)
        # Indented parameters
        if n > 0:
            indentdecl = '(\n'
            for i in range(0,n):
                paramdecl = self.makeCParamDecl(params[i], self.genOpts.alignFuncParam)
                if (i < n - 1):
                    paramdecl += ',\n'
                else:
                    paramdecl += ')'
                indentdecl += paramdecl
        else:
            indentdecl = '()'
        # Non-indented parameters
        paramdecl = '('
        if n > 0:
            for i in range(0,n):
                paramdecl += ''.join([t for t in params[i].itertext()])
                if (i < n - 1):
                    paramdecl += ', '
        paramdecl += ")";
        return pdecl + indentdecl
    #
    # Command definition
    def genCmdBody(self, cmdinfo, name):
        cmdelem = cmdinfo.elem

        # Get return type
        proto = cmdelem.find('proto')
        returntype = noneStr(proto.text) + noneStr(proto.find('type').text)

        # Get parameters and construct the function call to dispatch to the next layer.
        params = cmdelem.findall('param')
        callexpr = self.genLayerDispatchCall(name, params)

        # Build array of lines for function body
        body = []
        if returntype and returntype != 'void':
            body.append('    {} result = {};\n'.format(returntype, callexpr))
        else:
            body.append('    {};\n'.format(callexpr))
        body.append('\n')
        body.append('    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_{});\n'.format(name))
        body.append('    if (encoder)\n')
        body.append('    {\n')
        for param in params:
            methodcall = self.genEncoderMethodCall(param, params)
            body.append('        {};\n'.format(methodcall))
        if returntype and returntype != 'void':
            body.append('        encoder->EncodeEnumValue(result);\n')
        body.append('        get_trace_manager()->EndApiCallTrace(encoder);\n')
        body.append('    }\n')
        if returntype and returntype != 'void':
            body.append('\n')
            body.append('    return result;\n')

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
                start = paramname.tail.find('[') + 1
                end = paramname.tail.find(']')
                result = paramname.tail[start:end]
        return result
    #
    # Check for dispatchable handle types associated with the instance dispatch table.
    def useInstanceTable(self, typename):
        if typename in ['VkInstance', 'VkPhysicalDevice']:
            return True
        return False
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
    # Generate the layer dispatch call invocation
    def genLayerDispatchCall(self, name, params):
        callexpr = ''
        paramnames = [noneStr(param.find('name').text) for param in params]
        paramlist =  ', '.join(paramnames)
        if name == 'vkCreateInstance':
            # CreateInstance requires special processing for VkLayerInstanceCreateInfo.
            callexpr = 'dispatch_CreateInstance({})'.format(paramlist)
        elif name == 'vkCreateDevice':
            # CreateDevice requires special processing for VkLayerDeviceCreateInfo.
            callexpr = 'dispatch_CreateDevice({})'.format(paramlist)
        else:
            dispatchfunc = 'get_instance_table' if self.useInstanceTable(noneStr(params[0].find('type').text)) else 'get_device_table'
            callexpr = '{}({})->{}({})'.format(dispatchfunc, paramnames[0], name[2:], paramlist)
        return callexpr
    #
    # Generate the parameter encoder method call invocation
    def genEncoderMethodCall(self, param, params):
        methodcall = ''
        args = [noneStr(param.find('name').text)]
        typename = noneStr(param.find('type').text)

        isstruct = False
        isstring = False

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

        arraylen = self.getArrayLen(param)
        pointercount = self.getPointerCount(param)

        if arraylen:
            if isstruct:
                methodcall += '_array'
            else:
                methodcall += 'Array'
            if self.isPointer(arraylen, params):
                args.append('({name} != nullptr) ? (*{name}) : 0'.format(name=arraylen))
            else:
                args.append(arraylen)
        elif isstruct:
            methodcall += '_ptr'
        # String function names do not have the Ptr/Value suffix
        elif not isstring:
            if pointercount:
                methodcall += 'Ptr' * pointercount
            else:
                methodcall += 'Value'

        return '{}({})'.format(methodcall, ', '.join(args))

